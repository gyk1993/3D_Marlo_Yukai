%% Script to initialize the xbox controller bus

%ps3Axes = zeros(1,6);
ps3Axes = zeros(1,5);
ps3Buttons = zeros(1,11);
ps3Pov = -1;

% axis 
xbox.leftStickX = 0;
xbox.leftStickY = 0;
xbox.leftTrigger = 0;
xbox.rightStickX = 0;
xbox.rightStickY = 0;
xbox.rightTrigger = 0;

% button 
xbox.A = 0;
xbox.B = 0;
xbox.X = 0;
xbox.Y = 0;
xbox.leftBumper = 0;
xbox.rightBumper = 0;
xbox.back = 0;
xbox.start = 0;
xbox.leftStickButton = 0;
xbox.rightStickButton = 0;

% D-pad 
xbox.dUp = 0;
xbox.dRight = 0;
xbox.dDown = 0;
xbox.dLeft = 0;

createBusObject(xbox, 'xbox_bus');
