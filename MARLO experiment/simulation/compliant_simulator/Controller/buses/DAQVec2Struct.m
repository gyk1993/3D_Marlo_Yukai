function [log] = DAQVec2Struct(log, DAQ_template, datalogfilename, overwrite)
%% Script to convert experiment DAQ output vector into a structure

% Load log file
if nargin > 2
    mat = load(datalogfilename);
    log = mat.log;
    status = mat.status;
end

assert(isfield(log,'DAQVec'),'log file does not contain DataVec')

% Convert DAQ output vector into a struct based on the fieldnames in Data
fieldNames = fields(DAQ_template);
log.DAQ = struct;
index = 1;

for i = 1:length(fieldNames)
    len = size(DAQ_template.(fieldNames{i}),2);
    log.DAQ.(fieldNames{i}) = log.DAQVec(:,index:(index+len-1));
    index = index+len;
end

if nargin > 3 && overwrite
    save(datalogfilename,'log','status')
end