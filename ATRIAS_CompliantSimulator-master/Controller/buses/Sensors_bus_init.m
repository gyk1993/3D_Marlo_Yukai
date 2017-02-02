% Initialize bus to hold sensor data
Sensors.Encoder_Angles = zeros(10,1);
Sensors.Encoder_AnglesDerivs = zeros(10,1);
Sensors.IMU_AngularRate = zeros(3,1);
Sensors.IMU_Accel = [0;0;9.81];
Sensors.IMU_EulerAngles = zeros(3,1);
Sensors.IMU_EulerAnglesDerivs = zeros(3,1);
createBusObject(Sensors, 'Sensors_bus');