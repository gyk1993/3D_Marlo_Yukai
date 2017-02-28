function [log] = StateEstimatorVec2Struct(log, StateEstimator_template, datalogfilename, overwrite)
%% Script to convert experiment StateEstimator vector into a structure

% Load log file
if nargin > 2
    mat = load(datalogfilename);
    log = mat.log;
    status = mat.status;
end

assert(isfield(log,'StateEstimatorVec'),'log file does not contain StateEstimatorVec')

% Convert StateEstimator vector into a struct based on the fieldnames in StateEstimator
fieldNames = fields(StateEstimator_template);
log.StateEstimator = struct;
index = 1;

for i = 1:length(fieldNames)
    len = size(StateEstimator_template.(fieldNames{i}),1);
    log.StateEstimator.(fieldNames{i}) = log.StateEstimatorVec(:,index:(index+len-1));
    index = index+len;
end

if nargin > 3 && overwrite
    save(datalogfilename,'log','status')
end

