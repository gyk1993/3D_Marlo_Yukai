%% IO301 Model synchronization with external interrupt source
% This demo shows how to use an external interrupt source to synchronize 
% the entire real-time application with your hardware. The external 
% interrupt line of the IO301 I/O module is used to trigger the model 
% execution. The required external synchronization signal is generated 
% through a PWM trigger output of the same IO301 I/O module.

%% Requirements
% * Simulink Real-Time(TM)
% * Speedgoat Real-time target machine with IO301 installed
% * Terminal board with demo wiring connected to the IO301

%% Terminal board demo wiring
% Connect the provided terminal board to the Speedgoat IO301 as
% follows:
%
% <html>
% <table border=1>
% <tr><td>From pin</td><td>Description</td><td>To pin</td><td>Description</td></tr>
% <tr><td>3</td><td>PWM1 - Trigger signal</td><td>25</td><td>Interrupt input</td></tr>
% </table>
% </html>

%% Parameters
% As the model will run synchronized with the PWM, the PWM period
% will also define the sample time of the model.

fpga_freq = 33e6;     % FPGA frequency = 33MHz
Tpwm = 100e-6;        % PWM period = 100 microsecond


%% Open, Build and Download the Simulink model to the Speedgoat Real time target machine
% Click here to open the Simulink model
% <matlab:open_system('IO301interruptsynch') IO301interruptsynch>.

% Open the model
open_system('IO301interruptsynch');

% Build the model and download to the target computer
set_param('IO301interruptsynch','RTWVerbose','off'); % Configure for non-verbose build
rtwbuild('IO301interruptsynch');                     % Build and download application

%% Start and run the model

% Using the Simulink Real-Time object variables tg, start the model execution
start(tg);  % Start the application
pause(5);   % Wait for 1 second

%% Display the target screenshot

try
    tg.viewTargetScreen;    % This command replaces xpctargetspy from R2014a
catch
    xpctargetspy;           % Legacy command for xPC Target
end



