function set_paths()

MODEL_PATH = 'C:\Users\oharib\Documents\GitHub\Model-Generator\models\atrias\gen';
IPOPT_PATH = 'C:\Users\oharib\Documents\Ipopt';

addpath(genpath(MODEL_PATH))
addpath(IPOPT_PATH)
addpath(genpath('../common'))
addpath(genpath('./opt_func/gen/mex'))
addpath(genpath([pwd,'/config']))
addpath(genpath([pwd,'/function_wrappers']))
addpath('utils')
addpath_matlab_utilities('general', 'strings', 'yaml', 'ros', 'sim', 'plot', 'validation');

end
