function writeOptimizedFunctions(fcn_name,inputs,outputs,use_cpp)

    %--------------------------------------------------------------------------
    % Writes functions in C or C++ and MATLAB to compute values from
    % symbolic expressions
    %
    %   writeOptimizedFunctions(fcn_name, inputs, replace_list, outputs)
    %   fcn_name    A character string denoting the name of the function we are writing
    %   inputs      A two column list of the input parameters with the fist
    %       column being the data type and the second the variable name.
    %   replace_list    A two column matrix of strings with the first column
    %       containing the string to replace with the string in the second
    %       column.
    %   outputs     A three column list of the output parameters with the first
    %       column containing the variable, the second its c variable type, and
    %       the third its name.
    %--------------------------------------------------------------------------

    % Modified from write_fcn_c.m by Koushil Sreenath and others.
    % 
    % Modfication History:
    %   2014-08-09 BGB
    %       Added option to create C code instead of CPP
    
    if nargin<5
        [dmy1,dmy2,ext] = fileparts(fcn_name);
        use_cpp = strcmpi(ext, '.cpp');
    end

    % validate output variable names - Has to be valid in maple
    outputs = validate_output_names(outputs) ;

    % Get Input var declarations
    Inputs = getVarInfo(inputs, false, use_cpp);

    % Get Output var declarations
    Outputs = getVarInfo(outputs, true, use_cpp);

    % Open relevant files for writing
    [path, name, fid, fid_h, fid_mex, fid_m] = open_files(fcn_name, use_cpp) ;

    % write header file
    write_header_file(fid_h, name, Inputs, Outputs, use_cpp) ;
    fclose(fid_h) ;

    % write c/cpp file
    write_c_file(fid, name, Inputs, Outputs, use_cpp);
    fclose(fid);
    
    % write mex file
    write_mex_file(fid_mex, name, Inputs, Outputs, use_cpp) ;
    fclose(fid_mex) ;

    % write m file
    write_m_file(fid_m, name, Inputs, Outputs);
    fclose(fid_m);
end


% Function to check if output variable name is protected in maple and
% modifiy name if so.
function outputs = validate_output_names(outputs)
    for item = 1:size(outputs,1)
        currentname = outputs{item,2};
        if (eval(maple(['type(' currentname ', protected)']))) % append text to variable name if name protected in maple
            currentname = [currentname '_retval'] ;
            outputs{item,2} = currentname ;
        end
    end
end


% Deduce Input dimensions
% c_vector, c_matrix are from the boost::numeric::ublas - Refer boost lib
function VarInfo = getVarInfo(var, isOutput, use_cpp)
    if isempty(var)
        var = cell(0,2);
    end
    
    VarInfo = struct(...
        'Name', var(:,2), ...
        'Symbolic', var(:,1), ...
        'Dimensionality', [], ...
        'Dimensions', [], ...
        'NumElements', [], ...
        'CDeclaration', [] ...
        );

    for j = 1:length(VarInfo)
        VarInfo(j).Dimensions = size(VarInfo(j).Symbolic);
        VarInfo(j).NumElements = numel(VarInfo(j).Symbolic);

        if isscalar(VarInfo(j).Symbolic) % SCALAR
            VarInfo(j).Dimensionality = 0;
            if use_cpp || ~isOutput
                VarInfo(j).CDeclaration = sprintf('double %s', VarInfo(j).Name) ; %BGB
            else
                VarInfo(j).CDeclaration = sprintf('double* %s ', VarInfo(j).Name) ;
            end
        elseif isvector(VarInfo(j).Symbolic) % VECTOR
            VarInfo(j).Dimensionality = 1;
            if use_cpp
                VarInfo(j).CDeclaration = sprintf('c_vector<double,%d>& %s', VarInfo(j).NumElements, VarInfo(j).Name) ;
            else
                VarInfo(j).CDeclaration = sprintf('double %s[%d]', VarInfo(j).Name, VarInfo(j).NumElements) ;
            end
        elseif length(VarInfo(j).Dimensions)==2 % MATRIX
            % When using BOOST in conjunction with MEX, matrices easily can
            % be converted from row major form (C/C++) to column major form
            % (MATLAB) at the time the BOOST c_matrix<> is created or read
            % from. In C, there is no need to copy data to or from the
            % c_matrix<>; thus if we pass to the C function and return from
            % it the *TRANSPOSE* of any matrix arguments, then the
            % conversion between row major and column major is taken care
            % of implicitly.
            VarInfo(j).Dimensionality = 2;
            if use_cpp
                VarInfo(j).CDeclaration = sprintf('c_matrix<double,%d,%d>& %s', VarInfo(j).Dimensions, VarInfo(j).Name) ;
            else
                VarInfo(j).CDeclaration = sprintf('double %s[%d][%d]', VarInfo(j).Name, VarInfo(j).Dimensions([2 1])) ; % REVERSE THE DIMENSIONS!
            end
        else
            error('Multidimensional inputs are not supported.') ;
        end
    end
end

% Function to open relevant files for writing
function [path,name,fid,fid_h,fid_mex,fid_m] = open_files(fcn_name, use_cpp)
    [path, name, ext] = fileparts(fcn_name) ;
    if(~isempty(path))
        path = [path '/'] ;
    end
    mpath = regexprep(path, 'cpp[/\\]?$', 'm');
    
    disp(['- writing ' name ext]);

    % Open files
    fid = fopen(fcn_name,'w');
    fid_h = fopen([path name '.h'], 'w') ;
    if use_cpp
        fid_mex = fopen([path 'C' name '.cxx'], 'w') ;
    else
        % Use .c extension so that gcc will compile this as as C, not C++
        fid_mex = fopen([path 'C' name '.c'], 'w') ;
    end
    fid_m = fopen(fullfile(mpath, [name '.m']), 'w');
end

function [declare_list] = ccode(fid,var,name,use_cpp)

    if (~use_cpp && ~isvector(var))
        % To avoid copying/transposing data in the mex function, the
        % generated C function actually computes the transpose of the
        % desired output. The conversion from a c-style (row major) array
        % to a MATLAB-style (column major) array will undo this reordering,
        % giving the correct result.
        var = var.';
    end

    c = optimized_ccode(var,name);
    
    % string replacements necessary for correct syntax

    if (use_cpp)
        if(size(var,1)==1 && size(var,2)==1) % scalar
            c = regexprep(c, [name '\[\d+\]\[\d+\]'], name) ;
        elseif(size(var,1)==1) % vector transpose
            c = regexprep(c, [name '\[\d+\](\[\d+\])'], [name '$1']) ;
        elseif(size(var,2)==1) % vector
            c = regexprep(c, [name '(\[\d+\])\[\d+\]'], [name '$1']) ;
        else % matrix
            ; % do nothing
        end

        c = strrep(c,' ','');
        c = strrep(c,'~','');
        c = strrep(c,'][',',');
        c = strrep(c,'[','(');c = strrep(c,']',')');
        %c = strrep(c,name,['(*',name,')']);
    else
        if(size(var,1)==1 && size(var,2)==1) % scalar
            c = regexprep(c, [name '\[\d+\]\[\d+\]'], ['*(' name ')']) ;
            c = regexprep(c, name, ['*', name]);
        elseif(size(var,1)==1) % vector transpose
            c = regexprep(c, [name '\[\d+\](\[\d+\])'], [name '$1']) ;
        elseif(size(var,2)==1) % vector
            c = regexprep(c, [name '(\[\d+\])\[\d+\]'], [name '$1']) ;
        else % matrix
        end
        c = strrep(c,' ','');
        c = strrep(c,'\n','');
        c = strrep(c,'''','');
    end

    I = findstr(c,';');
    I = [0 I];

    declare_list = {};
    for i=1:1:length(I)-1
        if (isempty(findstr(c(I(i)+1:I(i+1)),name)))
            fprintf(fid,'  %s\n',c(I(i)+1:I(i+1)));
            tem=findstr(c(I(i)+1:I(i+1)),'=');
            declare_list=[declare_list;{c(I(i)+1:I(i)+tem-1)}];
        else
            fprintf(fid,'  %s\n',c(I(i)+1:I(i+1)));
        end
    end

    fprintf(fid,'\n\n');
end

function c = optimized_ccode(var,name)
    
%     if(isnumeric(var))
%         if isscalar(var)
%             str = ['matrix([[' num2str(var) ']])'] ;
%         else
%             str = regexprep(mat2str(var), {';', ' '}, {'],[', ','});
%             str = ['matrix([' str '])'];
%         end
%     else
%         str = char(var);
%     end
% 
%     if (isempty(findstr(str,'matrix')) && isempty(findstr(str,'Vector')))
%         str = ['matrix([[', str, ']])'];
%     end
    
    % Sometimes the variable is stored as a 1x1 matrix instead of just a
    % symbolic expression. This fixes that.
    if and(size(var,1)==1, size(var,2)==1)
        var = var(1);
    end
        
    str = char(var);
    
    maple([name ':=' str]);
    maple('with(CodeGeneration):');
    c = maple(['C(' name ',optimize,precision=double,output=string);']);
    c = sym2str(c);

    c = strrep(c,' ',''); % remove spaces
    c = strrep(c,'(int)',''); % remove any interger type casting
    % For some reason, maple code generation will have the returned
    % variable named cg, cg1, cg2, etc. if the output is a matrix or vector
    % If the output is a scalar, then the output will just be the last
    % line. This next block of code will correct the output to represent
    % the actual output name.
    if (isempty(regexp(c,'cg(\d+)','ONCE')) && isempty(regexp(c,'cg','ONCE')))
        ind = regexp(c,'\\nt(\d+)');
        if isempty(ind)
            ind = regexp(c,'t(\d+)');
            x = regexprep(c(ind(end):end),'t(\d+)=',[name,'=']);
        else
            x = regexprep(c(ind(end):end),'\\nt(\d+)=',[name,'=']);
        end
        c = strrep(c, c(ind(end):end), x);
    else
        c = regexprep(c,'cg(\d+)',name);
        c = regexprep(c,'cg',name);
    end

    maple([name ':=''' name '''']);
end

% Function to write header file
function write_header_file(fid_h, name, Inputs, Outputs, use_cpp)

    % Get fcn prototype
    fcn_prototype = get_fcn_prototype(name, Inputs, Outputs) ;

    % Write
    fprintf(fid_h, '%s\n', ['#ifndef _' name '_h_']) ; % Include directive
    fprintf(fid_h, '%s\n\n', ['#define _' name '_h_']) ;

    if (use_cpp)
        % Include appropriate header files
        %  fprintf(fid_h, '%s\n\n', '#include "params.h"') ; % // For params
        fprintf(fid_h, '%s\n', '#include <boost/numeric/ublas/vector.hpp>') ; % // For c_vector
        fprintf(fid_h, '%s\n', '#include <boost/numeric/ublas/matrix.hpp>') ; % // For c_matrix

        % namespace
        fprintf(fid_h, '\n%s\n', 'using namespace boost::numeric::ublas ;') ;
    else
        fprintf(fid_h, '%s\n', '#include <math.h>') ;
    end

    % fcn prototype
    fprintf(fid_h, '\n%s ;\n', fcn_prototype) ;

    % include directive
    fprintf(fid_h, '\n\n%s\n', ['#endif /* _' name '_h_ */']) ;
end

% Function to get function prototype
function fcn_prototype = get_fcn_prototype(name, Inputs, Outputs)
    inputList = list({Inputs.CDeclaration}, 'const ');
    outputList = list({Outputs.CDeclaration}, '');
    fcn_prototype = sprintf('void %s(%s)', name, list({inputList, outputList}, '')) ;
end

% Function to get function call
function fcn_call = get_fcn_call(name, Inputs, Outputs)
    inputList = list({Inputs.Name}, '');
    outputList = list({Outputs.Name}, '');
    fcn_call = sprintf('%s(%s)', name, list({inputList, outputList}, '')) ;
end

% Helper function to generate comma-separated list from cell array
function L = list(C, prefix)
    C = C(~cellfun(@isempty, C)); % remove any empty cells
    C = regexprep(C, '\s$', ''); % remove trailing whitespace
    if length(C)>1
        L = [sprintf([prefix '%s, '], C{1:end-1}) prefix C{end}];
    elseif length(C)==1
        L = [prefix C{1}];
    else
        L = '';
    end
end

% Function to write out the mex file
function write_mex_file(fid_mex, name, Inputs, Outputs, use_cpp)
    fprintf(fid_mex, '/* %s \n', upper(name));
    fprintf(fid_mex, ' * Generated by %s (%s)\n', mfilename, datestr(now, 'dd mmm yyyy HH:MM:SS'));
    fprintf(fid_mex, ' */\n\n');
    fprintf(fid_mex, '#include <mex.h>\n') ;
    fprintf(fid_mex, '#include "%s.h"\n\n', name) ;
    fprintf(fid_mex, '%s\n{\n', 'void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])') ;

    % Declare all variables before other commands for C-compatibility
    for j=1:length(Inputs)
        if use_cpp
            fprintf(fid_mex, '\t%s ;\n', regexprep(Inputs(j).CDeclaration, '&', '')) ;
        elseif (Inputs(j).NumElements==1) % SCALAR
            fprintf(fid_mex, '\tdouble %s ;\n', Inputs(j).Name) ;
        else % VECTOR OR MATRIX
            fprintf(fid_mex, '\tdouble * %s ;\n', Inputs(j).Name) ;
        end
    end
    for j=1:length(Outputs)
        if use_cpp
            fprintf(fid_mex, '\t%s ;\n', regexprep(Outputs(j).CDeclaration, '&', '')) ;
        elseif isvector(Outputs(j).Symbolic) % SCALAR OR VECTOR
            fprintf(fid_mex, '\tdouble *%s ;\n', Outputs(j).Name) ;
        else % MATRIX
            fprintf(fid_mex, '\tdouble (*%s)[][%d] ;\n', Outputs(j).Name, Outputs(j).Dimensions(1)) ;
        end
    end
    fprintf(fid_mex, '\n');

    fprintf(fid_mex, '\t/* Check for proper number of arguments. */\n') ;
    fprintf(fid_mex, '\tif(nlhs!=%d) mexErrMsgTxt("MEX function %s expects %d output arguments.");\n', length(Outputs), name, length(Outputs)) ;
    fprintf(fid_mex, '\tif(nrhs!=%d) mexErrMsgTxt("MEX function %s expects %d input arguments.");\n', length(Inputs), name, length(Inputs)) ;

    % Process inputs
    fprintf(fid_mex, '\n\t/* Process Inputs */') ;
    for j=1:length(Inputs)
        fprintf(fid_mex, '\n') ;
        if (Inputs(j).NumElements==1) % SCALAR
            fprintf(fid_mex, '\tif(mxGetM(prhs[%d])!=%d || mxGetN(prhs[%d])!=%d)\n',j-1,1,j-1,1) ;
            fprintf(fid_mex, '\t\tmexErrMsgTxt("Incorrect dimensions for input #%d - Should be scalar") ;\n',j) ;
            fprintf(fid_mex, '\t%s = *(mxGetPr(prhs[%d]));\n', Inputs(j).Name, j-1) ;
        elseif isvector(Inputs(j)) % VECTOR
            M = Inputs(j).NumElements;
            fprintf(fid_mex, '\tif(!(mxGetM(prhs[%d])==%d && mxGetN(prhs[%d])==%d) && !(mxGetM(prhs[%d])==%d && mxGetN(prhs[%d])==%d) )\n', j-1,M,j-1,1,  j-1,1,j-1,M) ;
            fprintf(fid_mex, '\t\tmexErrMsgTxt("Incorrect dimensions for input #%d - Should be a vector of length %d") ;\n',j,M) ;
            if use_cpp
                fprintf(fid_mex, '\tfor(unsigned int i=0 ; i<%d ; ++i)\n', M) ;
                fprintf(fid_mex, '\t\t%s(i) = (mxGetPr(prhs[%d]))[i] ;\n', Inputs(j).Name,j-1) ;
            else
                fprintf(fid_mex, '\t%s = mxGetPr(prhs[%d]) ;\n', Inputs(j).Name, j-1) ;
            end
        else % matrix
            M = Inputs(j).Dimensions(1);
            N = Inputs(j).Dimensions(2);
            fprintf(fid_mex, '\tif(mxGetM(prhs[%d])!=%d || mxGetN(prhs[%d])!=%d)\n',j-1,M,j-1,N) ;
            fprintf(fid_mex, '\t\tmexErrMsgTxt("Incorrect dimensions for input #%d - Should be %d x %d") ;\n',j,M,N) ;
            if use_cpp
                fprintf(fid_mex, '\tc_matrix<double, %d, %d> %s ;\n', M, N, Inputs(j).Name) ;
                fprintf(fid_mex, '\tfor(unsigned int i=0 ; i<%d ; ++i)\n', M) ;
                fprintf(fid_mex, '\t\tfor(unsigned int j=0 ; j<%d ; ++j)\n', N) ;
                fprintf(fid_mex, '\t\t\t%s(i,j) = (mxGetPr(prhs[%d]))[j*%d+i] ;\n', Inputs(j).Name, j-1, M) ;
            else
                fprintf(fid_mex, '\t%s = mxGetPr(prhs[%d]) ;\n', Inputs(j).Name, j-1) ;
            end
        end
    end

    % Define output variables
    fprintf(fid_mex, '\n\n\t/* Define Output variables */\n') ;
    for j=1:length(Outputs)
        M = Outputs(j).Dimensions(1);
        N = Outputs(j).Dimensions(2);
        fprintf(fid_mex, '\tplhs[%d] = mxCreateDoubleMatrix(%d,%d, mxREAL);\n', j-1,M,N) ;
        if (~use_cpp)
            if (M==1 || N==1)
                fprintf(fid_mex, '\t%s = mxGetPr(plhs[%d]) ;\n', Outputs(j).Name, j-1) ;
            else
                fprintf(fid_mex, '\t%s = (double (*)[][%d]) mxGetPr(plhs[%d]) ;\n', Outputs(j).Name, M, j-1) ;
            end
        end
    end

    % Invoke function
    fprintf(fid_mex, '\n\t/* Invoke function */\n') ;
    fcn_call = get_fcn_call(name, Inputs, Outputs);
    if (~use_cpp)
        % Pass matrix parameters as pointers to arrays
        MatrixInputs  = Inputs([Inputs.Dimensionality]==2);
        MatrixOutputs = Outputs([Outputs.Dimensionality]==2);
        MatrixArgs    = {MatrixInputs.Name MatrixOutputs.Name};
        MatrixArgsDeref = cellfun(@(s) ['*' s], MatrixArgs, 'Unif', 0);
        MatrixArgs      = cellfun(@(s) ['\<' s '\>'], MatrixArgs, 'Unif', 0); % Protect
        fcn_call = regexprep(fcn_call, MatrixArgs, MatrixArgsDeref);
    end
    fprintf(fid_mex, '\t%s ;\n', fcn_call) ;

    if (use_cpp)
        % Process outputs
        fprintf(fid_mex, '\n\n\t/* Process Outputs */\n') ;
        for j=1:length(Outputs)
            if (Outputs(j).Dimensionality==0) % SCALAR
                fprintf(fid_mex, '\t*(mxGetPr(plhs[%d])) = %s ;\n', j-1,Outputs(j).Name) ;
            elseif (Outputs(j).Dimensionality==1) % VECTOR
                fprintf(fid_mex, '\tfor(unsigned int i=0 ; i<%d ; ++i)\n', Outputs(j).NumElements) ;
                fprintf(fid_mex, '\t\t(mxGetPr(plhs[%d]))[i] = %s(i) ;\n', j-1,Outputs(j).Name) ;
            else
                M = Outputs(j).Dimensions(1) ; N = Outputs(j).Dimensions(2) ;
                fprintf(fid_mex, '\tfor(unsigned int i=0 ; i<%d ; ++i)\n',M) ;
                fprintf(fid_mex, '\t\tfor(unsigned int j=0 ; j<%d ; ++j)\n', N) ;
                fprintf(fid_mex, '\t\t\t(mxGetPr(plhs[%d]))[j*%d+i] = %s(i,j) ;\n', j-1,M,Outputs(j).Name) ;
            end
        end
    end

    fprintf(fid_mex, '}\n') ;
end


function write_c_file(fid, name, Inputs, Outputs, use_cpp)

    fcn_prototype = get_fcn_prototype(name, Inputs, Outputs) ;
    fprintf(fid, '/* %s \n', upper(name));
    fprintf(fid, ' * Generated by %s (%s)\n', mfilename, datestr(now, 'dd mmm yyyy HH:MM:SS'));
    fprintf(fid, ' */\n\n');
    fprintf(fid, '%s\n\n', ['#include "' name '.h"']) ;
    fprintf(fid,fcn_prototype) ;
    fprintf(fid,'\n{\n') ;

    % Generate replacments
    for k=1:length(Inputs)
%         if Inputs(k).Dimensionality==0
%             continue
%         end
        replace_list = gen_c_m_lists(Inputs(k).Symbolic, Inputs(k).Name);
        if (~use_cpp)
            replace_list(:,2) = regexprep(replace_list(:,2), {'\(' '\)'} , {'[' ']'});
        end
        for i=1:size(replace_list,1) % write temporaries
            fprintf(fid,'  double %s = %s;\n',char(replace_list(i,1)),char(replace_list(i,2)));
        end
    end

    fprintf(fid,'\n');
    %    fprintf(fid_m,'\n');

    declare_list = {}; % list of temporaries declared.
    % write variables computations to temporary file
    fid_tem = fopen('temp.tmp','w');
    for item = 1:length(Outputs)
        currentvar = Outputs(item).Symbolic;
        currentname = Outputs(item).Name;
        list_tem = ccode(fid_tem,currentvar,currentname,use_cpp);
        declare_list = [declare_list;list_tem];
    end
    fclose(fid_tem);

    % remove duplicates in list of temporaries declared, and write
    % temporary variable definitions
    declare_list=sort(declare_list);
    unique=ones(size(declare_list,1),1);
    for i=1:1:size(declare_list,1)-1
        if (strcmp(char(declare_list(i)),char(declare_list(i+1))))
            unique(i) = 0;
        end
    end
    declare_list = declare_list(unique == 1);
    for i=1:1:size(declare_list,1)
        fprintf(fid,'  double %s;\n',char(declare_list(i)));
    end
    fprintf(fid,'\n');

    % copy code from temporary file to cpp file
    fid_tem = fopen('temp.tmp','r');
    while(1)
        line = fgetl(fid_tem);
        if ~ischar(line), break, end
        fprintf(fid,'%s\n',line);
    end
    fprintf(fid, '  return;\n}\n\n');
    fclose(fid_tem); delete('temp.tmp');
end

% Fun
function write_m_file(fid_m, name, Inputs, Outputs)

    % Create function prototype
    inputList = list({Inputs.Name}, '');
    outputList = regexprep(list({Outputs.Name}, ''), '_retval', '');
    fcn_prototype = sprintf('function [%s] = %s(%s) %%#codegen', outputList, name, inputList) ;

    fprintf(fid_m, '%s\n', fcn_prototype) ;
    fprintf(fid_m, '\t%% Generated by %s (%s)\n', mfilename, datestr(now, 'dd mmm yyyy HH:MM:SS'));
    fprintf(fid_m, '\n');

    % Generate replacments
    for k=1:length(Inputs)
        [dmy,replace_list] = gen_c_m_lists(Inputs(k).Symbolic, Inputs(k).Name);
        for i=1:size(replace_list,1) % write temporaries
            fprintf(fid_m,'\t%s = %s;\n',char(replace_list(i,1)),char(replace_list(i,2)));
        end
    end
    fprintf(fid_m,'\n');

    % Print output code
    for item = 1:length(Outputs)
        mcode(fid_m, Outputs(item).Symbolic, Outputs(item).Name);
    end
    fprintf(fid_m,'end\n');
end

% Write optimized MATLAB code corresponding to a symbolic variable
function mcode(fid,var,name)

    % Sometimes the variable is stored as a 1x1 matrix instead of just a
    % symbolic expression. This fixes that.
    if and(size(var,1)==1, size(var,2)==1)
        var = var(1);
    end
    
    c = optimized_mcode(var,name);
    
    % string replacements necessary for correct syntax and line breaks
    c = regexprep(c, [name '\[(\d+)\]\[(\d+)\]\[(\d+)\]'], [name '(${num2str(str2double($1)+1)},${num2str(str2double($2)+1)},${num2str(str2double($3)+1)})']);
    c = regexprep(c, [name '\[(\d+)\]\[(\d+)\]'], [name '(${num2str(str2double($1)+1)},${num2str(str2double($2)+1)})']);
    c = regexprep(c, [name '\[(\d+)\]'], [name '(${num2str(str2double($1)+1)})']);
    c = regexprep(c, {';', ' ', '~', '_retval', '='}, {sprintf(';\n\t') , '', '', '', ' = '});
    c = strrep(c,'\n','');
    c = strrep(c,'''','');
    c = strrep(c,'(double)','');
    c = strrep(c,'(int)','');
    name = regexprep(name, '_retval', '');
    
    % Print to file
    if ~isscalar(var)
        fprintf(fid, '\t%s = zeros(%d,%d);\n', name, size(var));
    end
    fprintf(fid, '\t%s\n', c);
end


function c = optimized_mcode(var,name)
    
    str = char(var);
    
    maple([name ':=' str]);
    maple('with(CodeGeneration):');
    c = maple(['Matlab(' name ',optimize,precision=double,output=string);']);
    c = sym2str(c);
    
    c = strrep(c,' ',''); % remove spaces
    c = strrep(c,'(int)',''); % remove any interger type casting
    % For some reason, maple code generation will have the returned
    % variable named cg, cg1, cg2, etc. if the output is a matrix or vector
    % If the output is a scalar, then the output will just be the last
    % line. This next block of code will correct the output to represent
    % the actual output name.
    if (isempty(regexp(c,'cg(\d+)','ONCE')) && isempty(regexp(c,'cg','ONCE')))
        ind = regexp(c,'\\nt(\d+)');
        if isempty(ind)
            ind = regexp(c,'t(\d+)');
            x = regexprep(c(ind(end):end),'t(\d+)=',[name,'=']);
        else
            x = regexprep(c(ind(end):end),'\\nt(\d+)=',[name,'=']);
        end
        c = strrep(c, c(ind(end):end), x);
    else
        c = regexprep(c,'cg(\d+)',name);
        c = regexprep(c,'cg',name);
    end

    maple([name ':=''' name '''']);
end

% Function to generate the C and Matlab lists given the vector
% Inputs:
%     vec: vector of symbolic variables
%     str_prefix: This string prefix is appended to each element of the list.
% Outputs:
%     c_list: This is the c list
%     m_list: This is the m list
%
% Example:
% dq=[dqLA_L;dqLS_L;dqT];
% [c_list m_list] = gen_c_m_lists(q, 'dq') ;
% Produces:
% c_list = {'dqLA_L','dq(0)'; 'dqLS_L','dq(1)'; 'dqT','dq(2)';}
% m_list = {{'dqLA_L','dq(1)'; 'dqLS_L','dq(2)'; 'dqT','dq(3)';}
function [c_list, m_list] = gen_c_m_lists(vec, str_prefix)
    c_list = {} ; m_list = {} ;
    if length(vec) == 1
        c_list{1,1} = char(vec);
        c_list{1,2} = str_prefix;
        m_list = c_list;
    else
        for j=1:length(vec)
            c_list{j,1} = char(vec(j)) ;
            c_list{j,2} = [str_prefix '(' num2str(j-1) ')'] ;
            m_list{j,1} = char(vec(j)) ;
            m_list{j,2} = [str_prefix '(' num2str(j) ')'] ;
        end
    end
end

