addpath(fileparts(mfilename('fullpath')));
addpath(fileparts(fileparts(mfilename('fullpath'))));

controller_path = fileparts(fileparts(mfilename('fullpath')));

addpath([controller_path, '\Models'])

addpath(genpath([controller_path, '\DAQ']))
addpath(genpath([controller_path, '\shared_utils']))
addpath(genpath('D:\Graduate\robots\GitHub\3D_Marlo_Yukai\MARLO_experiment\common'))
% Remove old gui and use joystick one
rmpath(genpath(fullfile(controller_path, '\shared_utils','\GUI')));

addpath('Friction')
addpath('buses')
addpath('plotting')
addpath('mat')
addpath('utils')
addpath('Controller')
addpath('D:\Graduate\robots\GitHub\3D_Marlo_Yukai\MARLO_experiment\common')


