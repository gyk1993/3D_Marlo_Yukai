% Set paths
restoredefaultpath;
model_name = 'atrias';
[CURRENT_PATH, ROOT_PATH, UTILS_PATH, GEN_PATH, OPT_PATH, SIM_PATH, MODEL_PATH] = set_path(model_name,'mathematica');

INCLUDE_PATH = [ROOT_PATH,'\include'];
EIGEN_PATH = 'C:\Users\Ross\Documents\GIT\lib\eigen_3.3.1';

%% Compile

compile(OPT_PATH,INCLUDE_PATH,EIGEN_PATH)
% compile(SIM_PATH,INCLUDE_PATH,EIGEN_PATH)


