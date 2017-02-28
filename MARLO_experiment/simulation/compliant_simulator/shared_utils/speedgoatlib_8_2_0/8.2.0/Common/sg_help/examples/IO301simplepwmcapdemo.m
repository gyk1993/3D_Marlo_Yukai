%% IO301 simple PWM and Capture demo 
% This example shows how to output a simple PWM signal with a duty cycle
% of 0 to 100%, and read it back using the Capture line. The PWM signal is
% center-aligned (determined by the A-action vector).

%% Requirements
% * Simulink Real-Time(TM)
% * Speedgoat Real-time target machine with IO301 installed
% * Terminal board with demo wiring connected to the IO301

%% Terminal board demo wiring
% Connect the provided terminal board to the Speedgoat IO301 as
% follows.
%
% <html>
% <table border=1>
% <tr><td>From pin</td><td>Description</td><td>To pin</td><td>Description</td></tr>
% <tr><td>1</td><td>PWM1 - A signal</td><td>11</td><td>CAP1 input</td></tr>
% </table>
% </html>

%% Parameters
% It's important to explain the various frequencies/periods present
% in the model/application.
%
% The FPGA frequency depends on the module. IO30x and IO31x by default
% use a 33MHz oscillator.

fpga_freq = 33e6;   % FPGA frequency = 33MHz

%%
% The sample time is the closed-loop sample rate of the model. The minimum
% achievable sample time depends on the model complexity. In this demo we
% use a sample rate of 1kHz.

Ts = 0.001;         % Sample time = 1 millisecond

%%
% The PWM period is defined here.

Tpwm = 10e-6;        % PWM period = 10 microsecond


%% Open, Build and Download the Simulink model to the Speedgoat Real-time target machine
% Click here to open the Simulink model
% <matlab:open_system('IO301simplepwmcap') IO301simplepwmcap>.

% Open the model
open_system('IO301simplepwmcap');

% Build the model and download to the target computer
set_param('IO301simplepwmcap','RTWVerbose','off'); % Configure for non-verbose build
rtwbuild('IO301simplepwmcap');                     % Build and download application

%% Start and run the model

% Using the Simulink Real-Time object variables tg, start the model execution
start(tg);  % Start the application
pause(10);   % Wait for 1 second

%% Display the target screenshot

try
    tg.viewTargetScreen;    % This command replaces xpctargetspy from R2014a
catch
    xpctargetspy;           % Legacy command for xPC Target
end



