%% IO301 Subsystem synchronization with external interrupt source
% This demo shows how to use an external interrupt source to synchronize a 
% subsystem (part of the model) of the real-time application with your 
% hardware. The external interrupt line of the IO301 I/O module is used to 
% trigger the subsystem execution. The required external synchronization 
% signal is generated from a PWM trigger output of the same IO301 I/O 
% module.

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
% <tr><td>3</td><td>PWM1 - Trigger signal</td><td>25</td><td>Interrupt input</td></tr>
% </table>
% </html>

%% Parameters
% The model runs at the defined sample time. A subsystem is driven by the
% interrupt input line.

fpga_freq = 33e6;     % FPGA frequency = 33MHz
Ts = 0.001;           % Sample time = 1 millisecond
Tpwm = 100e-6;        % PWM period = 100 microsecond


%% Open, Build and Download the Simulink model to the Speedgoat Real time target machine
% Click here to open the Simulink model
% <matlab:open_system('IO301interruptsynchsubsystem') IO301interruptsynchsubsystem>.

% Open the model
open_system('IO301interruptsynchsubsystem');

% Build the model and download to the target computer
set_param('IO301interruptsynchsubsystem','RTWVerbose','off'); % Configure for non-verbose build
rtwbuild('IO301interruptsynchsubsystem');                     % Build and download application

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



