%% IO601 Read multiple CAN messages from receive queue
% A simple for-loop is used to receive and process the complete message 
% queue in a single time step.
% Using multiple CAN read blocks isn't recommended because of possible
% loss of data. 

%% Requirements
% * Simulink Real-Time(TM)
% * Speedgoat Real-time target machine with IO601 installed
% * Terminal board with demo wiring connected to the IO601

%% External wiring
% To perform the loopback test, connect the two CAN ports with
% provided loopback cable.


%% Open, Build and Download the Simulink model to the Speedgoat Real-time target machine
% Click here to open the Simulink model
% <matlab:open_system('IO601queueloopback') IO601queueloopback>.

% Open the model
open_system('IO601queueloopback');

% Build the model and download to the target computer
set_param('IO601queueloopback','RTWVerbose','off'); % Configure for non-verbose build
rtwbuild('IO601queueloopback');                     % Build and download application

%% Start and run the model

% Using the Simulink Real-Time object variable tg, start the model execution
start(tg);  % Start the application
pause(5);   % Wait for 1 second

%% Display the target screenshot

try
    tg.viewTargetScreen;    % This command replaces xpctargetspy from R2014a
catch
    xpctargetspy;           % Legacy command for xPC Target
end