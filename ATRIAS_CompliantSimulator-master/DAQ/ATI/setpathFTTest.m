%% Adds to the path the folders needed for CharacterizationControl

if (isempty(which('genpathnosvn'))), genpathnosvn = @genpath; end

addpath(userpath);

% Get the directory where this script lives
base_path = fileparts(mfilename('fullpath'));


% Add paths
addpath(base_path);
addpath(genpathnosvn(fullfile(base_path, 'autogen')));

% Get the directory ONE ABOVE where this script lives.
base_path = fileparts(fileparts(mfilename('fullpath')));

% Add paths
addpath(genpathnosvn(fullfile(base_path, 'utils')));

% Get the directory ONE ABOVE where this script lives.
base_path = fileparts(fileparts(fileparts(mfilename('fullpath'))));
addpath(genpathnosvn(fullfile(base_path, 'shared_utils')));
