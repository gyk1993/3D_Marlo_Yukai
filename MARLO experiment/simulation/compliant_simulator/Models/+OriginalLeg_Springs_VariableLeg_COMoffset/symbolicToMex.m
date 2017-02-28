function symbolicToMex(fname, inputs, outputs, varargin)
    % SYMBOLICTOMEX creates a mex function and/or an S-function for
    % evaluating a symbolic expression.
    
    if nargin<1
        fname = '';
    end
    Options = parseInputs(fname, varargin{:});
    if isempty(Options.FunctionName)
        return
    end
    
    % Write optimized C/C++ and MATLAB files for evaluating the symbolic expressions
    cfilename = fullfile(Options.CPath, [Options.FunctionName Options.CExtension]);
    cfullfilename = fullfile(Options.AutogenPath, cfilename);
    writeOptimizedFunctions(cfullfilename, inputs, outputs, varargin);
    
    % Compile the C code and generate mex function and/or S-function
    %if (Options.CreateMexFunction || Options.CreateSFunction)
    %    createLib();
    %end
    if (Options.CreateMexFunction)
        createMex(cfilename, Options);
    end
    if (Options.CreateSFunction)
        %createSFun();
    end
end

function createMex(cfilename, Options)
    [cpath, cfile, cext] = fileparts(cfilename);
    
    if isunix
        ofilename = regexprep(cfilename, '(\.c)|(.cpp)$', '.o');
    else
        ofilename = regexprep(cfilename, '(\.c)|(.cpp)$', '.obj');
    end
    
    % Include directory
    Include = ['''-I' cpath ''''];
    if strcmpi(cext, '.cpp')
        cext = '.cxx';
        Include = [Include ', ''-I' boost_path ''''];
    end
    mexfilename = fullfile(cpath, ['C' cfile cext]);
    
    % Output directory
    ObjOutdir = ['''-outdir'', ''' Options.CPath ''''];
    MexOutdir = ['''-outdir'', ''' Options.MexPath ''''];
    
    % Write script
    if Options.CreateScript
        fid = fopen(Options.ScriptName, 'a');
        if fid==-1
            error('Cannot open script file %s for writing.', Options.ScriptName);
        end
        fprintf(fid, '\tdisp(''[BUILDING <a href="matlab:edit(''''%s'''')">%s</a>]'')\n', cfile, cfile);
        str = sprintf('mex(''-c'', %s, %s, ''%s'')', Include, ObjOutdir, cfilename);
        fprintf(fid, '\tdisp(''%s'')\n', regexprep(str, '''', ''''''));
        fprintf(fid, '\t%s\n', str);
        str = sprintf('mex(%s, %s, ''%s'', obj(''%s''))', Include, MexOutdir, mexfilename, ofilename);
        fprintf(fid, '\tdisp(''%s'')\n', regexprep(str, '''', ''''''));
        fprintf(fid, '\t%s\n\n', str);
        
        fclose(fid);
    else
        mex(Include, fullfile(cpath, ['C' cfile cext]), cfilename);
    end
end

% function createSFun(Options)
%     %% Create S-function and TLC files
%
%     def = legacy_code('initialize');
%     def.SourceFiles    = {};
%     def.HeaderFiles    = {'fcnLagrangeModel3DStance.h'};
%     def.HostLibFiles   = {'libLagrangeModel3DStance.a'};
%     def.TargetLibFiles = {'libLagrangeModel3DStance.a'};
%     def.IncPaths       = {};
%     def.SrcPaths       = {};
%     def.LibPaths       = {'/z/bgbuss/biped/code/CompliantGround3dSimulator/ModelGeneration/SymbolicCode/ATRIAS-3D_SymbolicCode/c'};
%     def.SFunctionName  = Options.SFunctionName;
%     def.OutputFcnSpec  = 'void fcnLagrangeModel3DStance(double u1[13], double u2[13], double u3, double y1[13][13], double y2[13], double y3[3], double y4[3])';
%
%     def.Options.language  = 'C';
%
%
%     legacy_code('sfcn_cmex_generate', def);
%     legacy_code('compile', def);
%     legacy_code('sfcn_tlc_generate', def);
%     legacy_code('rtwmakecfg_generate', def);
%     legacy_code('slblock_generate', def, lib_name);
%     save_system(lib_name);
% end

function Options = parseInputs(fname, varargin)
    
    persistent StoredOptions
    
    if isempty(StoredOptions) || isempty(fname)
        StoredOptions.AutogenPath  = './autogen';
        StoredOptions.ScriptName   = 'compileMex.m';
        StoredOptions.BaseFileName = '<FNAME>';
    end
    
    
    % Make sure the function name does not include path or extension
    [pathstr, fname, ext] = fileparts(fname);
    if (~isempty(pathstr))
        warning('symbolicToMex will ignore paths passed as part of function names.');
    end
    
    % Expand function name (except on initialization)
    if (~isempty(fname))
        fname = regexprep(StoredOptions.BaseFileName, '<FNAME>', fname);
    end
    
    % Set extension (determines generated code will be C or C++)
    if isempty(ext)
        ext = '.c';
    end
    
    % Define input options
    istruefalse = @(v) isscalar(v) && (islogical(v) || isnumeric(v));
    p = inputParser();
    
    p.addParamValue('CPath', 'cpp', @ischar);
    p.addParamValue('MPath', 'm', @ischar);
    p.addParamValue('MexPath', 'mex', @ischar);
    p.addParamValue('CExtension', ext, @ischar);
    p.addParamValue('CreateSFunction', true,  istruefalse);
    p.addParamValue('CreateMexFunction', true,  istruefalse);
    p.addParamValue('FunctionName', fname, @(f) isempty(f) || isvarname(f));
    p.addParamValue('MexFunctionName', ['C' fname], @ischar);
    p.addParamValue('SFunctionName', ['S' fname], @ischar);
    p.addParamValue('LibraryName', '', @ischar);
    p.addParamValue('CreateScript', true, istruefalse);
    p.addParamValue('AppendToScript', false, istruefalse);
    p.addParamValue('AutogenPath', '', @ischar);
    p.addParamValue('ScriptName', '', @ischar);
    p.addParamValue('BaseFileName', '', @ischar);
    
    % Parse inputs
    p.parse(StoredOptions, varargin{:});
    Options = p.Results;
    
    if isempty(fname)
        % On the first call, create directories and initialize function file
        ScriptName = fullfile(Options.AutogenPath, Options.ScriptName);
        Options.ScriptName         = ScriptName;
        StoredOptions.AutogenPath  = Options.AutogenPath;
        StoredOptions.ScriptName   = Options.ScriptName;
        StoredOptions.BaseFileName = Options.BaseFileName;
        
        % Create directories if they do not exist
        CPathFull = fullfile(Options.AutogenPath, Options.CPath);
        MPathFull = fullfile(Options.AutogenPath, Options.MPath);
        MexPathFull = fullfile(Options.AutogenPath, Options.MexPath);
        
        if (~exist(Options.AutogenPath, 'dir'))
            mkdir(Options.AutogenPath);
        end
        if (~exist(CPathFull, 'dir'))
            mkdir(CPathFull);
        end
        if (~exist(MPathFull, 'dir'))
            mkdir(MPathFull);
        end
        if (~exist(MexPathFull, 'dir'))
            mkdir(MexPathFull);
        end
        
        if Options.AppendToScript
            return
        end
        
        % Open the file and overwrite contents
        fid = fopen(ScriptName, 'w');
        if fid==-1
            error('Cannot open script file %s for writing.', Options.ScriptName);
        end
        [spath, sname] = fileparts(Options.ScriptName);
        fprintf(fid, 'function %s()\n', sname);
        fprintf(fid, '\t%% Compile mex functions for symbolic calculations\n');
        fprintf(fid, '\t%% Autogenerated by %s on %s\n', mfilename, datestr(now, 'yyyy-mm-dd HH:MM'));
        fprintf(fid, '\t%% CWD during code generation: %s\n', pwd);
        fprintf(fid, '\tprevdir = cd;\n');
        fprintf(fid, '\tcd(fileparts(mfilename(''fullpath'')));\n');
        %fprintf(fid, '\tif ~exist(''%s'', ''dir'')\n', Options.MPath);
        %fprintf(fid, '\t\tmkdir(''%s'');\n', Options.MPath);
        %fprintf(fid, '\tend\n');
        fprintf(fid, '\tcompileAll();\n');
        fprintf(fid, '\tcd(prevdir);\n');
        fprintf(fid, '\n');
        fprintf(fid, '\n');
        fprintf(fid, 'function compileAll()\n');
        fprintf(fid, '\t%% Compile each mex-function\n');
        fprintf(fid, '\t%% In order to generate object files which could be linked in other code\n');
        fprintf(fid, '\t%% (such as in an s-function), the compilation is done in two steps:\n');
        fprintf(fid, '\t%% First, the primary code file is compiled without linking or creating\n');
        fprintf(fid, '\t%% a mex-function. Then the main mex file is compiled and linked against\n');
        fprintf(fid, '\t%% the object file.\n');
        fprintf(fid, '\n');
        fprintf(fid, '\t%% Create function to change object file extension on Windows\n');
        fprintf(fid, '\tif ispc()\n');
        fprintf(fid, '\t\t%s\n', 'obj = @(file) regexprep(file, ''\.o$'', ''.obj'');');
        fprintf(fid, '\telse\n');
        fprintf(fid, '\t\t%s\n', 'obj = @(file) file;');
        fprintf(fid, '\tend\n');
        fprintf(fid, '\n');
        fclose(fid);
        
        % Write a function to get the model name
        ModelFunName = regexprep(Options.BaseFileName, '<FNAME>', 'ModelName');
        ModelFunName = fullfile(Options.AutogenPath, ModelFunName);
        fid = fopen([ModelFunName '.m'], 'w');
        if fid==-1
            error('Cannot open file %s for writing.', ModelFunName);
        end
        [dmy, ModelFun] = fileparts(ModelFunName);
        [ModelPath, ModelName] = fileparts(Options.AutogenPath);
        if isempty(ModelName)
            [ModelPath, ModelName] = fileparts(ModelPath);
        end
        fprintf(fid, 'function ModelName = %s()\n', ModelFun);
        fprintf(fid, '\t%% Return the name of the selected model.\n');
        fprintf(fid, '\t%% Autogenerated by %s on %s\n', mfilename, datestr(now, 'yyyy-mm-dd HH:MM'));
        fprintf(fid, '\tModelName = ''%s'';\n', ModelName);
        fprintf(fid, 'end\n');
        fclose(fid);
    end
end

