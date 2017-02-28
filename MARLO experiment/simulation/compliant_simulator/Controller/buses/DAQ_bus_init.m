%% Script to initialize the DAQ Output bus

DAQ.EncoderAngles = zeros(1,19);
DAQ.EncoderDerivs = zeros(1,19);
DAQ.MotorCurrentSafe = zeros(1,6);
DAQ.IMU_EulerAngles = zeros(1,3);
DAQ.IMU_EulerAnglesDerivs = zeros(1,3);
DAQ.MedullaCommandSafe = zeros(1,1);
DAQ.RotationMatrix = zeros(1,9);
DAQ.AbsTick = zeros(1,10);
DAQ.IncTick = zeros(1,9);
DAQ.ValidStates = zeros(1,3);
DAQ.SafetyState = zeros(1,1);
DAQ.IMU_Accel = zeros(1,3);
DAQ.IMU_AngularRate = zeros(1,3);
DAQ.EtherCATStatus = zeros(1,6);
DAQ.EncoderAnglesDirty = zeros(1,19);
DAQ.CurrentActual = zeros(1,4);
DAQ.FaultDetected = zeros(1,4);
DAQ.MedullaState = zeros(1,7);
DAQ.ErrorFlags = zeros(1,7);
DAQ.ElmoPosition = zeros(1,4);

createBusObject(DAQ, 'DAQ_bus');