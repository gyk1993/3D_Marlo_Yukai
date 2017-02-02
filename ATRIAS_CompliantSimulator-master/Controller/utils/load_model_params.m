%% Initialize the DAQ
DAQParams3_1ms_DDA;
EnableTransition = 0; MedullaCommand = 0; ManualSwap = 0; Reset = 0; 
CommandSerialize = 0;

if isSim
    Ts = 5e-4;
end

%% Get defaults for all controller parameters
KAFiltSys = getDerivFilter(2, 5, 5, Ts);

LegHipTorqueLimit = [5; 3]; 

%Initializes parameters for ground reaction force, etc.
GroundModelParams
FootPoints = FootModel('Point');

% Harmonic drive stiction model
EnableStictionModel = 0;
% == LuGre Model Parameters ==
p = {3.7632,    0.0011,    0.3549,    0.0154,    0.0053};   %p_exp11_5
[sigma_0,J,alpha_0,sigma_1,alpha_2] = deal(p{:});

% Spring parameters
spring_k = 2.6908e+03;
% spring_k = 2.6908e+03*(3/2)^3;  % 12 mm spring
% spring_zeta = 0.2; %Nominal value around 0.1?
spring_zeta = 0.8; %Nominal value around 0.1?
% spring_zeta = 6.9762e-02; % % DDA 2015-10-1 8 mm spring

% -- OSU derivative filter --
% Sensors
sample_time = Ts;
lpf_damping = sqrt(2)/2; % Butterworth filter damping
fcut_velocity = 100*(2*pi); % Cutoff frequency for velocities
B1_lpf_velocity = -2*exp(-lpf_damping*fcut_velocity*sample_time)*cos(fcut_velocity*sample_time*sqrt(1-lpf_damping^2));
B2_lpf_velocity = exp(-2*lpf_damping*fcut_velocity*sample_time);
A_lpf_velocity = 1 + B1_lpf_velocity + B2_lpf_velocity;

% -- DDA derivative filter --
std_w = 1/Ts^2;
R = std_w^2/10;    % state noise (default)
Q = Ts/100;        % output noise (default)
% Q = 1.5e3;    % filter out more frequency
EncoderFiltSys = getDerivFilter_DDA(R, Q, Ts);

TorsoCOMOffsets = [0,0]; %deg

% -- Friction Param --
% addpath('C:\Users\xingye\Dropbox (Personal)\UMich\Research\Harmonic Drivev2\SystemID2015')
load Experiment_2015-09-30v2

% -- Ground Setup --
xLine = -3:1:10;
yLine = -3:1:10;
[X,Y] = meshgrid(xLine, yLine);
% Z = Y*tan(-8*pi/180).*(Y>0);
% Z = X*tan(8*pi/180)+0.2*sin(Y*4);   % wave field
% Z = -0.05.*(Y>0);
% Z = X*tan(8*pi/180);
Z = 0.*Y;
ground_terrain_data{1} = X;
ground_terrain_data{2} = Y;
ground_terrain_data{3} = Z;

q_offset = zeros(13,1);

% Set Variable model parameters
leg_length = 0.6; 
torso_com_offset = [0.0;0.0;0.0];

% Terrain
[X,Y] = meshgrid(-100:1:100, -100:1:100);
Z = zeros(size(X));

xLine = X(1,:);
yLine = Y(:,1)';

terrain.Tx = X;
terrain.Ty = Y;
terrain.Tz = Z;

% Enable perturbations
EnablePerturb = 1;
