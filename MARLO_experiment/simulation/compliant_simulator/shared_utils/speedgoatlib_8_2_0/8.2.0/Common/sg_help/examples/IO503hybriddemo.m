%% IO503 hybrid 
% This example shows how to construct a simple model with the IO503, using
% only the specific internal hardware blocks. Interrupts are used only
% for the receiver side.

%% Requirements
% * Simulink Real-Time(TM)
% * Speedgoat Real-time target machine with IO503 installed
% * Terminal board with demo wiring connected to the IO503
% * Configure the IRQ line number in the IRQ Source block

%% Terminal board demo wiring
% Connect the provided terminal board to the Speedgoat IO503 as
% follows.
%
% <html>
% <table border=1>
% <tr><td>From pin</td><td>Description</td><td>To pin</td><td>Description</td></tr>
% <tr><td>2</td><td>Channel 1 TX</td><td>13</td><td>Channel 2 RX</td></tr>
% <tr><td>12</td><td>Channel 2 TX</td><td>3</td><td>Channel 1 RX</td></tr>
% </table>
% </html>

%% Open, Build and Download the Simulink model to the Speedgoat Real-time target machine
% Click here to open the Simulink model
% <matlab:open_system('IO503hybrid') IO503hybrid>.

% Open the model
open_system('IO503hybrid');

% Build the model and download to the target computer
set_param('IO503hybrid','RTWVerbose','off'); % Configure for non-verbose build
rtwbuild('IO503hybrid');                     % Build and download application

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



