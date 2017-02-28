function str = struct2str(S,name)
    if nargin<2
        name = inputname(1);
    end
    if isempty(name)
        name = 'S';
    end
    
    str = '';
    if length(S)==1
        str = toString(S(1), str, name);
    else
        for k=1:length(S)
            str = toString(S(k), str, sprintf('%s(%d)', name, k));
        end
        str = [str sprintf('%s = reshape(%s, %s);\n', name, name, mat2str(size(S)))];
    end
end

function str = toString(S, str, name)
    f = fieldnames(S);
    for k=1:length(f)
        fname = [name '.' f{k}];
        
        if isstruct(S.(f{k}))
            stmp = struct2str(S.(f{k}), fname);
        elseif (isnumeric(S.(f{k})) || islogical(S.(f{k}))) && ismatrix(S.(f{k}))
            stmp = [fname ' = ' mat2str(S.(f{k})) ';' sprintf('\n')];
        else
            warning('Cannot convert %s to string!', fname);
            stmp = [name '.' f{k} ' = [];' sprintf('\n')]; 
        end
        str = [str stmp]; 
    end
end

