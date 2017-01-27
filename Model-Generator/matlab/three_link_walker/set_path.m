function [CURRENT_PATH, ROOT_PATH, UTILS_PATH, GEN_PATH, OPT_PATH, SIM_PATH, MODEL_PATH] = set_path(model_name, subdirectory)
%% Setup paths and names
CURRENT_PATH = pwd;
ROOT_PATH = fileparts(fileparts(CURRENT_PATH));
UTILS_PATH = [ROOT_PATH, '\utils'];
MODEL_PATH = [ROOT_PATH,'\models\',model_name];
GEN_PATH = [MODEL_PATH,'\gen\',subdirectory];
OPT_PATH = [GEN_PATH,'\opt'];
SIM_PATH = [GEN_PATH,'\sim'];

if ~exist(GEN_PATH,'dir')
    mkdir(GEN_PATH)
end
if ~exist(OPT_PATH,'dir')
    mkdir(OPT_PATH)
end

addpath(genpath(UTILS_PATH))
addpath(genpath(OPT_PATH))
addpath(genpath(SIM_PATH))

end