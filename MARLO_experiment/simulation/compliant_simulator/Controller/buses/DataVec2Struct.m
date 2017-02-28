function [log] = DataVec2Struct(log, Data_template, datalogfilename, overwrite)
%% Script to convert experiment Data vector into a structure

% Load log file
if nargin > 2
    mat = load(datalogfilename);
    log = mat.log;
    status = mat.status;
end

assert(isfield(log,'DataVec'),'log file does not contain DataVec')

% Convert Data vector into a struct based on the fieldnames in Data
fieldNames = fields(Data_template);
log.Data = struct;
index = 1;

for i = 1:length(fieldNames)
    len = size(Data_template.(fieldNames{i}),1);
    log.Data.(fieldNames{i}) = log.DataVec(:,index:(index+len-1));
    index = index+len;
end

if nargin > 3 && overwrite
    save(datalogfilename,'log','status')
end

