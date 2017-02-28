%setpath_DAQ
genpathnosvn = @(p) regexprep(genpath(p),['[^' pathsep ']*\.svn[^' pathsep ']*' pathsep '?'], '');

% Get the directory where this script lives
base_path = fileparts(mfilename('fullpath'));
addpath(base_path);

% Add subfolders (All versions)
addpath(genpathnosvn(fullfile(base_path, '500us')));
addpath(genpathnosvn(fullfile(base_path, 'IMU')));
addpath(genpathnosvn(fullfile(base_path, 'ATI')));
addpath(genpathnosvn(fullfile(base_path, 'Safety')));
addpath(genpathnosvn(fullfile(base_path, 'utils')));

% Add subfolders (Version-specific)
release = version('-release');
addpath(genpathnosvn(fullfile(base_path, ['R' release])));

% % Add shared_utils folder
% utils_path = fullfile(fileparts(base_path), 'shared_utils');
% addpath(genpathnosvn(utils_path));
% 
% % remove path and use local gui instead
% rmpath(genpathnosvn(fullfile(base_path, 'shared_utils','GUI')));
