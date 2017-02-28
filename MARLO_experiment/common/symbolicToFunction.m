function symbolicToFunction(fname, inputs, outputs, path)
% SYMBOLICTOFUNCTION creates a matlab and mex function for evaluating a symbolic expression.

if isempty(path)
    path = '';
end
if ~exist([path,'/m'],'dir')
    mkdir([path,'/m'])
end
if ~exist([path,'/mex'],'dir')
    mkdir([path,'/mex'])
end
if ~exist([path,'/codegen'],'dir')
    mkdir([path,'/codegen'])
end

% Write matlab function
disp(['Generating ', fname, ' .m code.'])
matlabFunction(outputs{:},'File',[path, '/m/',fname],'Vars',inputs,'Optimize',true);

% Create template arguments
args = cell(size(inputs));
for i = 1:length(inputs)
   args{i} = zeros(size(inputs{i})); 
end

% Create MEX file
disp(['Compiling ', fname, ' to MEX file.'])
cfg = coder.config('mex');
codegen([path, '/m/',fname,'.m'],'-args',args,'-o', [path,'/mex/'], '-d', [path,'codegen/'], '-config',cfg)

end