%% IO601 CAN multiple messages loopback demo
% Multiple messages CAN loopback demo with the IO601 I/O module.

%% Requirements
% * Simulink Real-Time(TM)
% * Speedgoat Real-time target machine with IO601 installed
% * Terminal board with demo wiring connected to the IO601

%% External wiring
% To perform the loopback test, connect the two CAN ports with the provided loopback cable.


%% Open, Build and Download the Simulink model to the Speedgoat Real-time target machine
% Click here to open the Simulink model
% <matlab:open_system('IO601canmultiplemessageloopback') IO601canmultiplemessageloopback>.

% Open the model
open_system('IO601canmultiplemessageloopback');

% Build the model and download to the target computer
set_param('IO601canmultiplemessageloopback','RTWVerbose','off'); % Configure for non-verbose build
rtwbuild('IO601canmultiplemessageloopback');                     % Build and download application

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