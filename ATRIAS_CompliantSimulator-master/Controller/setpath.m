addpath(fileparts(mfilename('fullpath')));
addpath(fileparts(fileparts(mfilename('fullpath'))));

controller_path = fileparts(fileparts(mfilename('fullpath')));

addpath([controller_path, '\Models'])

addpath(genpath([controller_path, '\DAQ']))
addpath(genpath([controller_path, '\shared_utils']))
% Remove old gui and use joystick one
rmpath(genpath(fullfile(controller_path, '\shared_utils','\GUI')));

addpath('Friction')
addpath('buses')
addpath('plotting')
addpath('mat')
addpath('utils')
addpath('Controller')


