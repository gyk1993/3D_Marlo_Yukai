function writeBusSerializationFunctions(BusName, folder)
    % WRITEBUSSERIALIZATIONFUNCTIONS generates functions to convert between
    % a Simulink.Bus object (structure) and a monolithic array. All of
    % the elements of the bus must be convertible to datatype double or be
    % structures for which the same is true.

    if nargin<2
        folder = 'autogen';
    end
    if (exist(folder, 'dir')~=7)
        status = mkdir(folder);
        if ~status
            folder = pwd;
        end
    end
    
    %% SERIALIZATION
    serializeFcn = ['serialize' BusName];
    fser = fopen(fullfile(folder,[serializeFcn '.m']), 'w');
    if (fser==-1)
        error('Could not open file %s for writing.', serializeFcn);
    end
    
    % Write headers
    fprintf(fser, 'function A = serialize%s(S)\n', BusName);
    fprintf(fser, '\t%%#codegen\n');
    fprintf(fser, '\tif coder.target(''MATLAB'')\n');
    fprintf(fser, '\t\tA = zeros(%d, 1);\n', getSize(BusName));
    fprintf(fser, '\telse\n');
    fprintf(fser, '\t\tA = coder.nullcopy(zeros(%d, 1));\n', getSize(BusName));
    fprintf(fser, '\tend\n');
    
    % Write serialization 
    writeBusSerialization(fser, BusName, 'S');
    
    % Write footer
    fprintf(fser, 'end\n\n');
    fclose(fser);
    %edit(serializeFcn);
    
    %% DESERIALIZATION
    deserializeFcn = ['deserialize' BusName];
    fdes = fopen(fullfile(folder,[deserializeFcn '.m']), 'w');
    if (fdes==-1)
        error('Could not open file %s for writing.', deserializeFcn);
    end
    
    DefinedBuses = {};
    NeededBuses = {BusName};
    while ~isempty(NeededBuses)
        NewNeededBuses = writeBusDeserialization(fdes, NeededBuses{1}, DefinedBuses);
        DefinedBuses = [DefinedBuses; NeededBuses(1)];
        NeededBuses = [NeededBuses(2:end); NewNeededBuses];
    end
    
    fclose(fdes);
    %edit(deserializeFcn);
end

function idx0 = writeBusSerialization(fser, BusName, prefix, idx0)
    Bus = evalin('base', BusName);
    builtinClasses = {'double', 'single', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64'};
    
    if nargin<4
        idx0 = 0;
    end
    
    % Elements
    for k=1:length(Bus.Elements)
        if ~ismember(Bus.Elements(k).DataType, builtinClasses)
            for l=1:prod(Bus.Elements(k).Dimensions)
                %idx = idx0 + [1 getSize(Bus.Elements(k).DataType)];
                %m2v = mat2vec(Bus.Elements(k).Dimensions, l);
                prefixsub = sprintf('%s.%s', prefix, Bus.Elements(k).Name);
                idx0 = writeBusSerialization(fser, Bus.Elements(k).DataType, prefixsub, idx0);
            end
        elseif ~strcmp(Bus.Elements(k).DataType, 'double')
            idx = idx0 + [1 prod(Bus.Elements(k).Dimensions)];
            m2v = mat2vec(Bus.Elements(k).Dimensions);
            if prod(Bus.Elements(k).Dimensions)==1
                idxstr = sprintf('%d', idx(1));
            else
                idxstr = sprintf('%d:%d', idx);
            end
            fprintf(fser, '\tA(%s) = double(%s.%s%s);\n', idxstr, prefix, Bus.Elements(k).Name, m2v);
            idx0 = idx(2);
        else
            idx = idx0 + [1 prod(Bus.Elements(k).Dimensions)];
            m2v = mat2vec(Bus.Elements(k).Dimensions);
            if prod(Bus.Elements(k).Dimensions)==1
                idxstr = sprintf('%d', idx(1));
            else
                idxstr = sprintf('%d:%d', idx);
            end
            fprintf(fser, '\tA(%s) = %s.%s%s;\n', idxstr, prefix, Bus.Elements(k).Name, m2v);
            idx0 = idx(2);
        end
    end
    
    
end


function NeededBuses = writeBusDeserialization(fdes, BusName, DefinedBuses)
    Bus = evalin('base', BusName);
    builtinClasses = {'double', 'single', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64'};
    NeededBuses = {};
    
    % Write headers
    fprintf(fdes, 'function S = deserialize%s(A)\n', BusName);
    fprintf(fdes, '\t%%#codegen\n');
    fprintf(fdes, '\tS = struct();\n');
    
    % Elements
    idx0 = 0;
    for k=1:length(Bus.Elements)
        if ~ismember(Bus.Elements(k).DataType, builtinClasses)
            for l=1:prod(Bus.Elements(k).Dimensions)
                idx = idx0 + [1 getSize(Bus.Elements(k).DataType)];
                m2v = mat2vec(Bus.Elements(k).Dimensions, l);
                fprintf(fdes, '\tS.%s%s = deserialize%s(A(%d:%d));\n', Bus.Elements(k).Name, m2v, Bus.Elements(k).DataType, idx);
                idx0 = idx(2);
                if ~ismember(Bus.Elements(k).DataType, DefinedBuses)
                    NeededBuses = [NeededBuses; Bus.Elements(k).DataType];
                end
            end
        else
            idx = idx0 + [1 prod(Bus.Elements(k).Dimensions)];
            str = sprintf('A(%d:%d)',idx);
            if ~strcmp(Bus.Elements(k).DataType, 'double')
                str = sprintf('double(%s)',str);
            end
            if (length(Bus.Elements(k).Dimensions)>1) && any(Bus.Elements(k).Dimensions~=1)
                str = sprintf('reshape(%s, %s)', str, mat2str(Bus.Elements(k).Dimensions));
            end
            fprintf(fdes, '\tS.%s = %s;\n', Bus.Elements(k).Name, str);
            idx0 = idx(2);
        end
    end
    
    fprintf(fdes, 'end\n\n');
end

function N = getSize(BusName)
    Bus = evalin('base', BusName);
    builtinClasses = {'double', 'single', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64'};
    
    N = 0;
    for k=1:length(Bus.Elements)
        if ~ismember(Bus.Elements(k).DataType, builtinClasses)
            N = N + getSize(Bus.Elements(k).DataType)*prod(Bus.Elements(k).Dimensions);
        else
            N = N + prod(Bus.Elements(k).Dimensions);
        end
    end
end

function m2v = mat2vec(dim,l)
    if sum(dim>1)>1
        if nargin<2
            m2v = '(:)';
        else
            m2v = sprintf('(%d)',l);
        end
    else
        m2v = '';
    end
end

