%% IO102 simple loopback demo 
% This example shows how to input and output analog and digital signals 
% with the Speedgoat IO102 module.

%% Requirements
% * Simulink Real-Time(TM)
% * Speedgoat Real-time target machine with IO102 installed
% * Terminal board with demo wiring connected to IO102

%% Terminal board demo wiring
% Connect the provided terminal board to the Speedgoat IO102 as follows:
%
% <html>
% <table border=1>
% <tr><td>From pin</td><td>Description</td><td>To pin</td><td>Description</td></tr>
% <tr><td>68</td><td>Analog output channel 1</td><td>34</td><td>Analog input channel 1</td></tr>
% <tr><td>47</td><td>Digital output channel 1</td><td>55</td><td>Digital input channel 1</td></tr>
% </table>
% </html>

%% Open, Build and Download the Simulink model to the Speedgoat real-time target machine
% Click here to open the Simulink model
% <matlab:open_system('IO102simpleloopback') IO102simpleloopback>.

% Open the model
open_system('IO102simpleloopback');

% Build the model and download to the target computer
set_param('IO102simpleloopback','RTWVerbose','off'); % Configure for non-Verbose build
rtwbuild('IO102simpleloopback');                     % Build and download application

%% Start and run the model

% Using the Simulink Real-Time object variables tg, start the model execution
start(tg);  % Start the application
pause(1);   % Wait for 1 second

%% Display the target screenshot

try
    tg.viewTargetScreen;    % This command replace xpctargetspy from R2014a
catch
    xpctargetspy;           % Legacy command for xPC Target
end



