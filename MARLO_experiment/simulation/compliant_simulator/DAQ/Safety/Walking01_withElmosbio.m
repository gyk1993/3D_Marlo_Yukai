function bio=Walking01_withElmosbio
bio = [];
bio(1).blkName='DAQ_WITH_SAFETY_IMU/AdjustForCOMOffset';
bio(1).sigName='q';
bio(1).portIdx=0;
bio(1).dim=[13,1];
bio(1).sigWidth=13;
bio(1).sigAddress='&Walking01_withElmos_B.q[0]';
bio(1).ndims=2;
bio(1).size=[];

bio(getlenBIO) = bio(1);

bio(2).blkName='DAQ_WITH_SAFETY_IMU/SAFETY/p2';
bio(2).sigName='MedullaCommandSafe';
bio(2).portIdx=1;
bio(2).dim=[1,1];
bio(2).sigWidth=1;
bio(2).sigAddress='&Walking01_withElmos_B.MedullaCommandSafe';
bio(2).ndims=2;
bio(2).size=[];


bio(3).blkName='DAQ_WITH_SAFETY_IMU/SAFETY/p4';
bio(3).sigName='SafetyCountOut';
bio(3).portIdx=3;
bio(3).dim=[1,1];
bio(3).sigWidth=1;
bio(3).sigAddress='&Walking01_withElmos_B.SafetyCountOut';
bio(3).ndims=2;
bio(3).size=[];


bio(4).blkName='DAQ_WITH_SAFETY_IMU/Gain';
bio(4).sigName='';
bio(4).portIdx=0;
bio(4).dim=[1,1];
bio(4).sigWidth=1;
bio(4).sigAddress='&Walking01_withElmos_ConstB.Gain';
bio(4).ndims=2;
bio(4).size=[];


bio(5).blkName='DAQ_WITH_SAFETY_IMU/Rate Transition';
bio(5).sigName='';
bio(5).portIdx=0;
bio(5).dim=[1,1];
bio(5).sigWidth=1;
bio(5).sigAddress='&Walking01_withElmos_B.RateTransition';
bio(5).ndims=2;
bio(5).size=[];


bio(6).blkName='DAQ_WITH_SAFETY_IMU/Rate Transition1';
bio(6).sigName='';
bio(6).portIdx=0;
bio(6).dim=[1,1];
bio(6).sigWidth=1;
bio(6).sigAddress='&Walking01_withElmos_B.RateTransition1_p';
bio(6).ndims=2;
bio(6).size=[];


bio(7).blkName='DAQ_WITH_SAFETY_IMU/Get Overload Counter ';
bio(7).sigName='';
bio(7).portIdx=0;
bio(7).dim=[1,1];
bio(7).sigWidth=1;
bio(7).sigAddress='&Walking01_withElmos_B.GetOverloadCounter';
bio(7).ndims=2;
bio(7).size=[];


bio(8).blkName='DAQ_WITH_SAFETY_IMU/Get Overload Counter 1';
bio(8).sigName='';
bio(8).portIdx=0;
bio(8).dim=[1,1];
bio(8).sigWidth=1;
bio(8).sigAddress='&Walking01_withElmos_B.GetOverloadCounter1';
bio(8).ndims=2;
bio(8).size=[];


bio(9).blkName='DAQ_WITH_SAFETY_IMU/Get Overload Counter 2';
bio(9).sigName='';
bio(9).portIdx=0;
bio(9).dim=[1,1];
bio(9).sigWidth=1;
bio(9).sigAddress='&Walking01_withElmos_B.GetOverloadCounter2';
bio(9).ndims=2;
bio(9).size=[];


bio(10).blkName='DAQ_WITH_SAFETY_IMU/CPU Overload Regulator/Bias';
bio(10).sigName='';
bio(10).portIdx=0;
bio(10).dim=[1,1];
bio(10).sigWidth=1;
bio(10).sigAddress='&Walking01_withElmos_B.Bias';
bio(10).ndims=2;
bio(10).size=[];


bio(11).blkName='DAQ_WITH_SAFETY_IMU/CPU Overload Regulator/Task Execution Time ';
bio(11).sigName='';
bio(11).portIdx=0;
bio(11).dim=[1,1];
bio(11).sigWidth=1;
bio(11).sigAddress='&Walking01_withElmos_B.TaskExecutionTime';
bio(11).ndims=2;
bio(11).size=[];


bio(12).blkName='DAQ_WITH_SAFETY_IMU/DAQ/Rate Transition1';
bio(12).sigName='';
bio(12).portIdx=0;
bio(12).dim=[3,1];
bio(12).sigWidth=3;
bio(12).sigAddress='&Walking01_withElmos_B.RateTransition1[0]';
bio(12).ndims=2;
bio(12).size=[];


bio(13).blkName='DAQ_WITH_SAFETY_IMU/DAQ/Rate Transition2';
bio(13).sigName='';
bio(13).portIdx=0;
bio(13).dim=[3,1];
bio(13).sigWidth=3;
bio(13).sigAddress='&Walking01_withElmos_B.RateTransition2[0]';
bio(13).ndims=2;
bio(13).size=[];


bio(14).blkName='DAQ_WITH_SAFETY_IMU/DAQ/Rate Transition3';
bio(14).sigName='';
bio(14).portIdx=0;
bio(14).dim=[1,1];
bio(14).sigWidth=1;
bio(14).sigAddress='&Walking01_withElmos_B.RateTransition3';
bio(14).ndims=2;
bio(14).size=[];


bio(15).blkName='Walking/Continuous/CheckError/p2';
bio(15).sigName='ErrorCount';
bio(15).portIdx=1;
bio(15).dim=[1,1];
bio(15).sigWidth=1;
bio(15).sigAddress='&Walking01_withElmos_B.ErrorCount';
bio(15).ndims=2;
bio(15).size=[];


bio(16).blkName='Walking/Continuous/controller1/p5';
bio(16).sigName='s';
bio(16).portIdx=4;
bio(16).dim=[1,1];
bio(16).sigWidth=1;
bio(16).sigAddress='&Walking01_withElmos_B.s';
bio(16).ndims=2;
bio(16).size=[];


bio(17).blkName='Walking/Discrete/StateLogic/p3';
bio(17).sigName='SerialOut';
bio(17).portIdx=2;
bio(17).dim=[5,1];
bio(17).sigWidth=5;
bio(17).sigAddress='&Walking01_withElmos_B.SerialOut[0]';
bio(17).ndims=2;
bio(17).size=[];


bio(18).blkName='Walking/Discrete/EnableTransition';
bio(18).sigName='';
bio(18).portIdx=0;
bio(18).dim=[1,1];
bio(18).sigWidth=1;
bio(18).sigAddress='&Walking01_withElmos_B.EnableTransition';
bio(18).ndims=2;
bio(18).size=[];


bio(19).blkName='Walking/Discrete/ResetControl';
bio(19).sigName='';
bio(19).portIdx=0;
bio(19).dim=[1,1];
bio(19).sigWidth=1;
bio(19).sigAddress='&Walking01_withElmos_B.ResetControl';
bio(19).ndims=2;
bio(19).size=[];


bio(20).blkName='Walking/Discrete/Data Type Conversion1';
bio(20).sigName='';
bio(20).portIdx=0;
bio(20).dim=[1,1];
bio(20).sigWidth=1;
bio(20).sigAddress='&Walking01_withElmos_B.DataTypeConversion1';
bio(20).ndims=2;
bio(20).size=[];


bio(21).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/ComputeEulerAngles/p1';
bio(21).sigName='ZYX';
bio(21).portIdx=0;
bio(21).dim=[3,1];
bio(21).sigWidth=3;
bio(21).sigAddress='&Walking01_withElmos_B.sf_ComputeEulerAngles.ZYX[0]';
bio(21).ndims=2;
bio(21).size=[];


bio(22).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/ComputeEulerAngles/p2';
bio(22).sigName='dZYX';
bio(22).portIdx=1;
bio(22).dim=[3,1];
bio(22).sigWidth=3;
bio(22).sigAddress='&Walking01_withElmos_B.sf_ComputeEulerAngles.dZYX[0]';
bio(22).ndims=2;
bio(22).size=[];


bio(23).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/ComputeEulerAngles/p3';
bio(23).sigName='Rk';
bio(23).portIdx=2;
bio(23).dim=[3,3];
bio(23).sigWidth=9;
bio(23).sigAddress='&Walking01_withElmos_B.sf_ComputeEulerAngles.Rk[0]';
bio(23).ndims=2;
bio(23).size=[];


bio(24).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/ComputeEulerAngles/p4';
bio(24).sigName='R0';
bio(24).portIdx=3;
bio(24).dim=[3,3];
bio(24).sigWidth=9;
bio(24).sigAddress='&Walking01_withElmos_B.sf_ComputeEulerAngles.R0[0]';
bio(24).ndims=2;
bio(24).size=[];


bio(25).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/ComputeEulerAngles/p5';
bio(25).sigName='YawRollover';
bio(25).portIdx=4;
bio(25).dim=[2,1];
bio(25).sigWidth=2;
bio(25).sigAddress='&Walking01_withElmos_B.sf_ComputeEulerAngles.YawRollover[0]';
bio(25).ndims=2;
bio(25).size=[];


bio(26).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/calibrate/p1';
bio(26).sigName='';
bio(26).portIdx=0;
bio(26).dim=[19,1];
bio(26).sigWidth=19;
bio(26).sigAddress='&Walking01_withElmos_B.VectorConcatenate_m[0]';
bio(26).ndims=2;
bio(26).size=[];


bio(27).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/calibrate/p2';
bio(27).sigName='';
bio(27).portIdx=1;
bio(27).dim=[19,1];
bio(27).sigWidth=19;
bio(27).sigAddress='&Walking01_withElmos_B.VectorConcatenate_m[0]';
bio(27).ndims=2;
bio(27).size=[];


bio(28).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/calibrate/p3';
bio(28).sigName='Rollover';
bio(28).portIdx=2;
bio(28).dim=[9,1];
bio(28).sigWidth=9;
bio(28).sigAddress='&Walking01_withElmos_B.Rollover[0]';
bio(28).ndims=2;
bio(28).size=[];


bio(29).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/calibrate/p4';
bio(29).sigName='IncCalTick';
bio(29).portIdx=3;
bio(29).dim=[6,1];
bio(29).sigWidth=6;
bio(29).sigAddress='&Walking01_withElmos_B.IncCalTick[0]';
bio(29).ndims=2;
bio(29).size=[];


bio(30).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/Vector Concatenate';
bio(30).sigName='';
bio(30).portIdx=0;
bio(30).dim=[19,1];
bio(30).sigWidth=19;
bio(30).sigAddress='&Walking01_withElmos_B.VectorConcatenate_m[0]';
bio(30).ndims=2;
bio(30).size=[];


bio(31).blkName='DAQ_WITH_SAFETY_IMU/DAQ/Reset/Logical Operator1';
bio(31).sigName='';
bio(31).portIdx=0;
bio(31).dim=[1,1];
bio(31).sigWidth=1;
bio(31).sigAddress='&Walking01_withElmos_B.LogicalOperator1';
bio(31).ndims=2;
bio(31).size=[];


bio(32).blkName='DAQ_WITH_SAFETY_IMU/DAQ/Reset/Logical Operator2';
bio(32).sigName='';
bio(32).portIdx=0;
bio(32).dim=[1,1];
bio(32).sigWidth=1;
bio(32).sigAddress='&Walking01_withElmos_B.LogicalOperator2';
bio(32).ndims=2;
bio(32).size=[];


bio(33).blkName='DAQ_WITH_SAFETY_IMU/DAQ/StateEstimator/GeneralizedCoordinates/p2';
bio(33).sigName='dq_clean';
bio(33).portIdx=1;
bio(33).dim=[13,1];
bio(33).sigWidth=13;
bio(33).sigAddress='&Walking01_withElmos_B.dq_clean[0]';
bio(33).ndims=2;
bio(33).size=[];


bio(34).blkName='Walking/Discrete/Detect Rise Positive2/FixPt Relational Operator';
bio(34).sigName='';
bio(34).portIdx=0;
bio(34).dim=[1,1];
bio(34).sigWidth=1;
bio(34).sigAddress='&Walking01_withElmos_B.FixPtRelationalOperator';
bio(34).ndims=2;
bio(34).size=[];


bio(35).blkName='Walking/Discrete/KA Acceleration/Vector Concatenate';
bio(35).sigName='';
bio(35).portIdx=0;
bio(35).dim=[2,1];
bio(35).sigWidth=2;
bio(35).sigAddress='&Walking01_withElmos_B.VectorConcatenate_a[0]';
bio(35).ndims=2;
bio(35).size=[];


bio(36).blkName='Walking/Discrete/KA Acceleration/Discrete State-Space';
bio(36).sigName='';
bio(36).portIdx=0;
bio(36).dim=[2,1];
bio(36).sigWidth=2;
bio(36).sigAddress='&Walking01_withElmos_B.VectorConcatenate_a[0]';
bio(36).ndims=2;
bio(36).size=[];


bio(37).blkName='Walking/Discrete/KA Acceleration/Discrete State-Space1';
bio(37).sigName='';
bio(37).portIdx=0;
bio(37).dim=[2,1];
bio(37).sigWidth=2;
bio(37).sigAddress='&Walking01_withElmos_B.VectorConcatenate_a[0]';
bio(37).ndims=2;
bio(37).size=[];


bio(38).blkName='Walking/Discrete/KA Acceleration/TKA';
bio(38).sigName='';
bio(38).portIdx=0;
bio(38).dim=[2,1];
bio(38).sigWidth=2;
bio(38).sigAddress='&Walking01_withElmos_B.TKA[0]';
bio(38).ndims=2;
bio(38).size=[];


bio(39).blkName='DAQ_WITH_SAFETY_IMU/CPU Overload Regulator/Reset CPU Overload Count/Set Overload Counter 1/Data Type  Conversion';
bio(39).sigName='';
bio(39).portIdx=0;
bio(39).dim=[1,1];
bio(39).sigWidth=1;
bio(39).sigAddress='&Walking01_withElmos_ConstB.DataTypeConversion';
bio(39).ndims=2;
bio(39).size=[];


bio(40).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion104';
bio(40).sigName='';
bio(40).portIdx=0;
bio(40).dim=[1,1];
bio(40).sigWidth=1;
bio(40).sigAddress='&Walking01_withElmos_B.DataTypeConversion104';
bio(40).ndims=2;
bio(40).size=[];


bio(41).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion119';
bio(41).sigName='';
bio(41).portIdx=0;
bio(41).dim=[1,1];
bio(41).sigWidth=1;
bio(41).sigAddress='&Walking01_withElmos_B.DataTypeConversion119';
bio(41).ndims=2;
bio(41).size=[];


bio(42).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion141';
bio(42).sigName='';
bio(42).portIdx=0;
bio(42).dim=[3,1];
bio(42).sigWidth=3;
bio(42).sigAddress='&Walking01_withElmos_ConstB.DataTypeConversion141[0]';
bio(42).ndims=2;
bio(42).size=[];


bio(43).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion33';
bio(43).sigName='';
bio(43).portIdx=0;
bio(43).dim=[1,1];
bio(43).sigWidth=1;
bio(43).sigAddress='&Walking01_withElmos_B.DataTypeConversion33';
bio(43).ndims=2;
bio(43).size=[];


bio(44).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion57';
bio(44).sigName='';
bio(44).portIdx=0;
bio(44).dim=[1,1];
bio(44).sigWidth=1;
bio(44).sigAddress='&Walking01_withElmos_B.DataTypeConversion57';
bio(44).ndims=2;
bio(44).size=[];


bio(45).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion81';
bio(45).sigName='';
bio(45).portIdx=0;
bio(45).dim=[1,1];
bio(45).sigWidth=1;
bio(45).sigAddress='&Walking01_withElmos_B.DataTypeConversion81';
bio(45).ndims=2;
bio(45).size=[];


bio(46).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion9';
bio(46).sigName='';
bio(46).portIdx=0;
bio(46).dim=[1,1];
bio(46).sigWidth=1;
bio(46).sigAddress='&Walking01_withElmos_B.DataTypeConversion9';
bio(46).ndims=2;
bio(46).size=[];


bio(47).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion97';
bio(47).sigName='';
bio(47).portIdx=0;
bio(47).dim=[6,1];
bio(47).sigWidth=6;
bio(47).sigAddress='&Walking01_withElmos_B.DataTypeConversion97[0]';
bio(47).ndims=2;
bio(47).size=[];


bio(48).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/EtherCAT Init ';
bio(48).sigName='';
bio(48).portIdx=0;
bio(48).dim=[6,1];
bio(48).sigWidth=6;
bio(48).sigAddress='&Walking01_withElmos_B.EtherCATInit[0]';
bio(48).ndims=2;
bio(48).size=[];


bio(49).blkName='DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/ComputeEulerAngles/p1';
bio(49).sigName='ZYX';
bio(49).portIdx=0;
bio(49).dim=[3,1];
bio(49).sigWidth=3;
bio(49).sigAddress='&Walking01_withElmos_B.sf_ComputeEulerAngles_i.ZYX[0]';
bio(49).ndims=2;
bio(49).size=[];


bio(50).blkName='DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/ComputeEulerAngles/p2';
bio(50).sigName='dZYX';
bio(50).portIdx=1;
bio(50).dim=[3,1];
bio(50).sigWidth=3;
bio(50).sigAddress='&Walking01_withElmos_B.sf_ComputeEulerAngles_i.dZYX[0]';
bio(50).ndims=2;
bio(50).size=[];


bio(51).blkName='DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/ComputeEulerAngles/p3';
bio(51).sigName='Rk';
bio(51).portIdx=2;
bio(51).dim=[3,3];
bio(51).sigWidth=9;
bio(51).sigAddress='&Walking01_withElmos_B.sf_ComputeEulerAngles_i.Rk[0]';
bio(51).ndims=2;
bio(51).size=[];


bio(52).blkName='DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/ComputeEulerAngles/p4';
bio(52).sigName='R0';
bio(52).portIdx=3;
bio(52).dim=[3,3];
bio(52).sigWidth=9;
bio(52).sigAddress='&Walking01_withElmos_B.sf_ComputeEulerAngles_i.R0[0]';
bio(52).ndims=2;
bio(52).size=[];


bio(53).blkName='DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/ComputeEulerAngles/p5';
bio(53).sigName='YawRollover';
bio(53).portIdx=4;
bio(53).dim=[2,1];
bio(53).sigWidth=2;
bio(53).sigAddress='&Walking01_withElmos_B.sf_ComputeEulerAngles_i.YawRollover[0]';
bio(53).ndims=2;
bio(53).size=[];


bio(54).blkName='Walking/Discrete/Detect Rise Positive1/Positive/Compare';
bio(54).sigName='';
bio(54).portIdx=0;
bio(54).dim=[1,1];
bio(54).sigWidth=1;
bio(54).sigAddress='&Walking01_withElmos_B.Compare';
bio(54).ndims=2;
bio(54).size=[];


bio(55).blkName='Walking/Discrete/Detect Rise Positive2/Positive/Compare';
bio(55).sigName='';
bio(55).portIdx=0;
bio(55).dim=[1,1];
bio(55).sigWidth=1;
bio(55).sigAddress='&Walking01_withElmos_B.Compare_l';
bio(55).ndims=2;
bio(55).size=[];


bio(56).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EncoderFilters/CheckAndFilterEncoder/AnomalyDetection/p1';
bio(56).sigName='q_clean';
bio(56).portIdx=0;
bio(56).dim=[1,1];
bio(56).sigWidth=1;
bio(56).sigAddress='&Walking01_withElmos_B.CoreSubsys[18].sf_AnomalyDetection.q_clean';
bio(56).ndims=2;
bio(56).size=[];


bio(57).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EncoderFilters/CheckAndFilterEncoder/AnomalyDetection/p2';
bio(57).sigName='ErrorCount';
bio(57).portIdx=1;
bio(57).dim=[1,1];
bio(57).sigWidth=1;
bio(57).sigAddress='&Walking01_withElmos_B.CoreSubsys[18].sf_AnomalyDetection.ErrorCount';
bio(57).ndims=2;
bio(57).size=[];


bio(58).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EncoderFilters/CheckAndFilterEncoder/Discrete State-Space';
bio(58).sigName='';
bio(58).portIdx=0;
bio(58).dim=[1,1];
bio(58).sigWidth=1;
bio(58).sigAddress='&Walking01_withElmos_B.CoreSubsys[18].DiscreteStateSpace';
bio(58).ndims=2;
bio(58).size=[];


bio(59).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EncoderFilters/CheckAndFilterEncoder/Unit Delay';
bio(59).sigName='';
bio(59).portIdx=0;
bio(59).dim=[1,1];
bio(59).sigWidth=1;
bio(59).sigAddress='&Walking01_withElmos_B.CoreSubsys[18].UnitDelay';
bio(59).ndims=2;
bio(59).size=[];


bio(60).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/Data Type Conversion3';
bio(60).sigName='';
bio(60).portIdx=0;
bio(60).dim=[1,1];
bio(60).sigWidth=1;
bio(60).sigAddress='&Walking01_withElmos_B.DataTypeConversion3';
bio(60).ndims=2;
bio(60).size=[];


bio(61).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/Data Type Conversion4';
bio(61).sigName='';
bio(61).portIdx=0;
bio(61).dim=[1,1];
bio(61).sigWidth=1;
bio(61).sigAddress='&Walking01_withElmos_B.DataTypeConversion4';
bio(61).ndims=2;
bio(61).size=[];


bio(62).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/Data Type Conversion5';
bio(62).sigName='';
bio(62).portIdx=0;
bio(62).dim=[1,1];
bio(62).sigWidth=1;
bio(62).sigAddress='&Walking01_withElmos_B.DataTypeConversion5';
bio(62).ndims=2;
bio(62).size=[];


bio(63).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var ';
bio(63).sigName='';
bio(63).portIdx=0;
bio(63).dim=[1,1];
bio(63).sigWidth=1;
bio(63).sigAddress='&Walking01_withElmos_B.EtherCATRxVar_i';
bio(63).ndims=2;
bio(63).size=[];


bio(64).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 1';
bio(64).sigName='';
bio(64).portIdx=0;
bio(64).dim=[1,1];
bio(64).sigWidth=1;
bio(64).sigAddress='&Walking01_withElmos_B.EtherCATRxVar1_m';
bio(64).ndims=2;
bio(64).size=[];


bio(65).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 12';
bio(65).sigName='';
bio(65).portIdx=0;
bio(65).dim=[1,1];
bio(65).sigWidth=1;
bio(65).sigAddress='&Walking01_withElmos_B.EtherCATRxVar12_pv';
bio(65).ndims=2;
bio(65).size=[];


bio(66).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 13';
bio(66).sigName='';
bio(66).portIdx=0;
bio(66).dim=[1,1];
bio(66).sigWidth=1;
bio(66).sigAddress='&Walking01_withElmos_B.EtherCATRxVar13_e0';
bio(66).ndims=2;
bio(66).size=[];


bio(67).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 14';
bio(67).sigName='';
bio(67).portIdx=0;
bio(67).dim=[1,1];
bio(67).sigWidth=1;
bio(67).sigAddress='&Walking01_withElmos_B.EtherCATRxVar14_b';
bio(67).ndims=2;
bio(67).size=[];


bio(68).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 15';
bio(68).sigName='';
bio(68).portIdx=0;
bio(68).dim=[1,1];
bio(68).sigWidth=1;
bio(68).sigAddress='&Walking01_withElmos_B.EtherCATRxVar15_g';
bio(68).ndims=2;
bio(68).size=[];


bio(69).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 16';
bio(69).sigName='';
bio(69).portIdx=0;
bio(69).dim=[1,1];
bio(69).sigWidth=1;
bio(69).sigAddress='&Walking01_withElmos_B.EtherCATRxVar16_d';
bio(69).ndims=2;
bio(69).size=[];


bio(70).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 17';
bio(70).sigName='';
bio(70).portIdx=0;
bio(70).dim=[1,1];
bio(70).sigWidth=1;
bio(70).sigAddress='&Walking01_withElmos_B.EtherCATRxVar17_p';
bio(70).ndims=2;
bio(70).size=[];


bio(71).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 18';
bio(71).sigName='';
bio(71).portIdx=0;
bio(71).dim=[1,1];
bio(71).sigWidth=1;
bio(71).sigAddress='&Walking01_withElmos_B.EtherCATRxVar18_h';
bio(71).ndims=2;
bio(71).size=[];


bio(72).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 19';
bio(72).sigName='';
bio(72).portIdx=0;
bio(72).dim=[1,1];
bio(72).sigWidth=1;
bio(72).sigAddress='&Walking01_withElmos_B.EtherCATRxVar19_i';
bio(72).ndims=2;
bio(72).size=[];


bio(73).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 2';
bio(73).sigName='';
bio(73).portIdx=0;
bio(73).dim=[1,1];
bio(73).sigWidth=1;
bio(73).sigAddress='&Walking01_withElmos_B.EtherCATRxVar2_i';
bio(73).ndims=2;
bio(73).size=[];


bio(74).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 3';
bio(74).sigName='';
bio(74).portIdx=0;
bio(74).dim=[1,1];
bio(74).sigWidth=1;
bio(74).sigAddress='&Walking01_withElmos_B.EtherCATRxVar3_c';
bio(74).ndims=2;
bio(74).size=[];


bio(75).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 4';
bio(75).sigName='';
bio(75).portIdx=0;
bio(75).dim=[1,1];
bio(75).sigWidth=1;
bio(75).sigAddress='&Walking01_withElmos_B.EtherCATRxVar4_nd';
bio(75).ndims=2;
bio(75).size=[];


bio(76).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 5';
bio(76).sigName='';
bio(76).portIdx=0;
bio(76).dim=[1,1];
bio(76).sigWidth=1;
bio(76).sigAddress='&Walking01_withElmos_B.EtherCATRxVar5_d';
bio(76).ndims=2;
bio(76).size=[];


bio(77).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 6';
bio(77).sigName='';
bio(77).portIdx=0;
bio(77).dim=[1,1];
bio(77).sigWidth=1;
bio(77).sigAddress='&Walking01_withElmos_B.EtherCATRxVar6_f';
bio(77).ndims=2;
bio(77).size=[];


bio(78).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/Data Type Conversion3';
bio(78).sigName='';
bio(78).portIdx=0;
bio(78).dim=[1,1];
bio(78).sigWidth=1;
bio(78).sigAddress='&Walking01_withElmos_B.DataTypeConversion3_i';
bio(78).ndims=2;
bio(78).size=[];


bio(79).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/Data Type Conversion4';
bio(79).sigName='';
bio(79).portIdx=0;
bio(79).dim=[1,1];
bio(79).sigWidth=1;
bio(79).sigAddress='&Walking01_withElmos_B.DataTypeConversion4_h';
bio(79).ndims=2;
bio(79).size=[];


bio(80).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/Data Type Conversion5';
bio(80).sigName='';
bio(80).portIdx=0;
bio(80).dim=[1,1];
bio(80).sigWidth=1;
bio(80).sigAddress='&Walking01_withElmos_B.DataTypeConversion5_e';
bio(80).ndims=2;
bio(80).size=[];


bio(81).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var ';
bio(81).sigName='';
bio(81).portIdx=0;
bio(81).dim=[1,1];
bio(81).sigWidth=1;
bio(81).sigAddress='&Walking01_withElmos_B.EtherCATRxVar';
bio(81).ndims=2;
bio(81).size=[];


bio(82).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 1';
bio(82).sigName='';
bio(82).portIdx=0;
bio(82).dim=[1,1];
bio(82).sigWidth=1;
bio(82).sigAddress='&Walking01_withElmos_B.EtherCATRxVar1_p';
bio(82).ndims=2;
bio(82).size=[];


bio(83).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 12';
bio(83).sigName='';
bio(83).portIdx=0;
bio(83).dim=[1,1];
bio(83).sigWidth=1;
bio(83).sigAddress='&Walking01_withElmos_B.EtherCATRxVar12_h';
bio(83).ndims=2;
bio(83).size=[];


bio(84).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 13';
bio(84).sigName='';
bio(84).portIdx=0;
bio(84).dim=[1,1];
bio(84).sigWidth=1;
bio(84).sigAddress='&Walking01_withElmos_B.EtherCATRxVar13_e';
bio(84).ndims=2;
bio(84).size=[];


bio(85).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 14';
bio(85).sigName='';
bio(85).portIdx=0;
bio(85).dim=[1,1];
bio(85).sigWidth=1;
bio(85).sigAddress='&Walking01_withElmos_B.EtherCATRxVar14_f';
bio(85).ndims=2;
bio(85).size=[];


bio(86).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 15';
bio(86).sigName='';
bio(86).portIdx=0;
bio(86).dim=[1,1];
bio(86).sigWidth=1;
bio(86).sigAddress='&Walking01_withElmos_B.EtherCATRxVar15_b';
bio(86).ndims=2;
bio(86).size=[];


bio(87).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 16';
bio(87).sigName='';
bio(87).portIdx=0;
bio(87).dim=[1,1];
bio(87).sigWidth=1;
bio(87).sigAddress='&Walking01_withElmos_B.EtherCATRxVar16_bt';
bio(87).ndims=2;
bio(87).size=[];


bio(88).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 17';
bio(88).sigName='';
bio(88).portIdx=0;
bio(88).dim=[1,1];
bio(88).sigWidth=1;
bio(88).sigAddress='&Walking01_withElmos_B.EtherCATRxVar17_j';
bio(88).ndims=2;
bio(88).size=[];


bio(89).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 18';
bio(89).sigName='';
bio(89).portIdx=0;
bio(89).dim=[1,1];
bio(89).sigWidth=1;
bio(89).sigAddress='&Walking01_withElmos_B.EtherCATRxVar18_j';
bio(89).ndims=2;
bio(89).size=[];


bio(90).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 19';
bio(90).sigName='';
bio(90).portIdx=0;
bio(90).dim=[1,1];
bio(90).sigWidth=1;
bio(90).sigAddress='&Walking01_withElmos_B.EtherCATRxVar19_o';
bio(90).ndims=2;
bio(90).size=[];


bio(91).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 2';
bio(91).sigName='';
bio(91).portIdx=0;
bio(91).dim=[1,1];
bio(91).sigWidth=1;
bio(91).sigAddress='&Walking01_withElmos_B.EtherCATRxVar2_g';
bio(91).ndims=2;
bio(91).size=[];


bio(92).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 3';
bio(92).sigName='';
bio(92).portIdx=0;
bio(92).dim=[1,1];
bio(92).sigWidth=1;
bio(92).sigAddress='&Walking01_withElmos_B.EtherCATRxVar3_h';
bio(92).ndims=2;
bio(92).size=[];


bio(93).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 4';
bio(93).sigName='';
bio(93).portIdx=0;
bio(93).dim=[1,1];
bio(93).sigWidth=1;
bio(93).sigAddress='&Walking01_withElmos_B.EtherCATRxVar4_m';
bio(93).ndims=2;
bio(93).size=[];


bio(94).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 5';
bio(94).sigName='';
bio(94).portIdx=0;
bio(94).dim=[1,1];
bio(94).sigWidth=1;
bio(94).sigAddress='&Walking01_withElmos_B.EtherCATRxVar5_o';
bio(94).ndims=2;
bio(94).size=[];


bio(95).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 6';
bio(95).sigName='';
bio(95).portIdx=0;
bio(95).dim=[1,1];
bio(95).sigWidth=1;
bio(95).sigAddress='&Walking01_withElmos_B.EtherCATRxVar6_a';
bio(95).ndims=2;
bio(95).size=[];


bio(96).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/TypecastAndCast1';
bio(96).sigName='y';
bio(96).portIdx=0;
bio(96).dim=[3,1];
bio(96).sigWidth=3;
bio(96).sigAddress='&Walking01_withElmos_B.sf_TypecastAndCast1.y[0]';
bio(96).ndims=2;
bio(96).size=[];


bio(97).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/TypecastAndCast2';
bio(97).sigName='y';
bio(97).portIdx=0;
bio(97).dim=[3,1];
bio(97).sigWidth=3;
bio(97).sigAddress='&Walking01_withElmos_B.sf_TypecastAndCast2.y[0]';
bio(97).ndims=2;
bio(97).size=[];


bio(98).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/Data Type Conversion1';
bio(98).sigName='';
bio(98).portIdx=0;
bio(98).dim=[1,1];
bio(98).sigWidth=1;
bio(98).sigAddress='&Walking01_withElmos_B.DataTypeConversion1_l';
bio(98).ndims=2;
bio(98).size=[];


bio(99).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/Data Type Conversion3';
bio(99).sigName='';
bio(99).portIdx=0;
bio(99).dim=[1,1];
bio(99).sigWidth=1;
bio(99).sigAddress='&Walking01_withElmos_B.DataTypeConversion3_j';
bio(99).ndims=2;
bio(99).size=[];


bio(100).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/Data Type Conversion4';
bio(100).sigName='';
bio(100).portIdx=0;
bio(100).dim=[1,1];
bio(100).sigWidth=1;
bio(100).sigAddress='&Walking01_withElmos_B.DataTypeConversion4_a';
bio(100).ndims=2;
bio(100).size=[];


bio(101).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 1';
bio(101).sigName='';
bio(101).portIdx=0;
bio(101).dim=[1,1];
bio(101).sigWidth=1;
bio(101).sigAddress='&Walking01_withElmos_B.EtherCATRxVar1';
bio(101).ndims=2;
bio(101).size=[];


bio(102).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 10';
bio(102).sigName='';
bio(102).portIdx=0;
bio(102).dim=[1,1];
bio(102).sigWidth=1;
bio(102).sigAddress='&Walking01_withElmos_B.EtherCATRxVar10';
bio(102).ndims=2;
bio(102).size=[];


bio(103).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 11';
bio(103).sigName='';
bio(103).portIdx=0;
bio(103).dim=[1,1];
bio(103).sigWidth=1;
bio(103).sigAddress='&Walking01_withElmos_B.EtherCATRxVar11';
bio(103).ndims=2;
bio(103).size=[];


bio(104).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 12';
bio(104).sigName='';
bio(104).portIdx=0;
bio(104).dim=[1,1];
bio(104).sigWidth=1;
bio(104).sigAddress='&Walking01_withElmos_B.EtherCATRxVar12';
bio(104).ndims=2;
bio(104).size=[];


bio(105).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 13';
bio(105).sigName='';
bio(105).portIdx=0;
bio(105).dim=[1,1];
bio(105).sigWidth=1;
bio(105).sigAddress='&Walking01_withElmos_B.EtherCATRxVar13';
bio(105).ndims=2;
bio(105).size=[];


bio(106).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 14';
bio(106).sigName='';
bio(106).portIdx=0;
bio(106).dim=[1,1];
bio(106).sigWidth=1;
bio(106).sigAddress='&Walking01_withElmos_B.EtherCATRxVar14';
bio(106).ndims=2;
bio(106).size=[];


bio(107).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 15';
bio(107).sigName='';
bio(107).portIdx=0;
bio(107).dim=[1,1];
bio(107).sigWidth=1;
bio(107).sigAddress='&Walking01_withElmos_B.EtherCATRxVar15_d';
bio(107).ndims=2;
bio(107).size=[];


bio(108).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 16';
bio(108).sigName='';
bio(108).portIdx=0;
bio(108).dim=[1,1];
bio(108).sigWidth=1;
bio(108).sigAddress='&Walking01_withElmos_B.EtherCATRxVar16_k';
bio(108).ndims=2;
bio(108).size=[];


bio(109).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 17';
bio(109).sigName='';
bio(109).portIdx=0;
bio(109).dim=[1,1];
bio(109).sigWidth=1;
bio(109).sigAddress='&Walking01_withElmos_B.EtherCATRxVar17_c';
bio(109).ndims=2;
bio(109).size=[];


bio(110).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 18';
bio(110).sigName='';
bio(110).portIdx=0;
bio(110).dim=[1,1];
bio(110).sigWidth=1;
bio(110).sigAddress='&Walking01_withElmos_B.EtherCATRxVar18_k';
bio(110).ndims=2;
bio(110).size=[];


bio(111).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 19';
bio(111).sigName='';
bio(111).portIdx=0;
bio(111).dim=[1,1];
bio(111).sigWidth=1;
bio(111).sigAddress='&Walking01_withElmos_B.EtherCATRxVar19';
bio(111).ndims=2;
bio(111).size=[];


bio(112).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 2';
bio(112).sigName='';
bio(112).portIdx=0;
bio(112).dim=[1,1];
bio(112).sigWidth=1;
bio(112).sigAddress='&Walking01_withElmos_B.EtherCATRxVar2';
bio(112).ndims=2;
bio(112).size=[];


bio(113).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 3';
bio(113).sigName='';
bio(113).portIdx=0;
bio(113).dim=[1,1];
bio(113).sigWidth=1;
bio(113).sigAddress='&Walking01_withElmos_B.EtherCATRxVar3';
bio(113).ndims=2;
bio(113).size=[];


bio(114).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 4';
bio(114).sigName='';
bio(114).portIdx=0;
bio(114).dim=[1,1];
bio(114).sigWidth=1;
bio(114).sigAddress='&Walking01_withElmos_B.EtherCATRxVar4_ph';
bio(114).ndims=2;
bio(114).size=[];


bio(115).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 5';
bio(115).sigName='';
bio(115).portIdx=0;
bio(115).dim=[1,1];
bio(115).sigWidth=1;
bio(115).sigAddress='&Walking01_withElmos_B.EtherCATRxVar5';
bio(115).ndims=2;
bio(115).size=[];


bio(116).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 6';
bio(116).sigName='';
bio(116).portIdx=0;
bio(116).dim=[1,1];
bio(116).sigWidth=1;
bio(116).sigAddress='&Walking01_withElmos_B.EtherCATRxVar6';
bio(116).ndims=2;
bio(116).size=[];


bio(117).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 7';
bio(117).sigName='';
bio(117).portIdx=0;
bio(117).dim=[1,1];
bio(117).sigWidth=1;
bio(117).sigAddress='&Walking01_withElmos_B.EtherCATRxVar7';
bio(117).ndims=2;
bio(117).size=[];


bio(118).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 8';
bio(118).sigName='';
bio(118).portIdx=0;
bio(118).dim=[1,1];
bio(118).sigWidth=1;
bio(118).sigAddress='&Walking01_withElmos_B.EtherCATRxVar8_m';
bio(118).ndims=2;
bio(118).size=[];


bio(119).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 9';
bio(119).sigName='';
bio(119).portIdx=0;
bio(119).dim=[1,1];
bio(119).sigWidth=1;
bio(119).sigAddress='&Walking01_withElmos_B.EtherCATRxVar9';
bio(119).ndims=2;
bio(119).size=[];


bio(120).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Chart/p1';
bio(120).sigName='ControlWordIndex';
bio(120).portIdx=0;
bio(120).dim=[1,1];
bio(120).sigWidth=1;
bio(120).sigAddress='&Walking01_withElmos_B.ControlWordIndex_j';
bio(120).ndims=2;
bio(120).size=[];


bio(121).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Chart/p2';
bio(121).sigName='EnableTargetTorque';
bio(121).portIdx=1;
bio(121).dim=[1,1];
bio(121).sigWidth=1;
bio(121).sigAddress='&Walking01_withElmos_B.EnableTargetTorque_f';
bio(121).ndims=2;
bio(121).size=[];


bio(122).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Chart/p3';
bio(122).sigName='FaultDetected';
bio(122).portIdx=2;
bio(122).dim=[1,1];
bio(122).sigWidth=1;
bio(122).sigAddress='&Walking01_withElmos_B.FaultDetected_n';
bio(122).ndims=2;
bio(122).size=[];


bio(123).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Switch';
bio(123).sigName='';
bio(123).portIdx=0;
bio(123).dim=[1,1];
bio(123).sigWidth=1;
bio(123).sigAddress='&Walking01_withElmos_B.Switch';
bio(123).ndims=2;
bio(123).size=[];


bio(124).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Chart/p1';
bio(124).sigName='ControlWordIndex';
bio(124).portIdx=0;
bio(124).dim=[1,1];
bio(124).sigWidth=1;
bio(124).sigAddress='&Walking01_withElmos_B.sf_Chart.ControlWordIndex';
bio(124).ndims=2;
bio(124).size=[];


bio(125).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Chart/p2';
bio(125).sigName='EnableTargetTorque';
bio(125).portIdx=1;
bio(125).dim=[1,1];
bio(125).sigWidth=1;
bio(125).sigAddress='&Walking01_withElmos_B.sf_Chart.EnableTargetTorque';
bio(125).ndims=2;
bio(125).size=[];


bio(126).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Chart/p3';
bio(126).sigName='FaultDetected';
bio(126).portIdx=2;
bio(126).dim=[1,1];
bio(126).sigWidth=1;
bio(126).sigAddress='&Walking01_withElmos_B.sf_Chart.FaultDetected';
bio(126).ndims=2;
bio(126).size=[];


bio(127).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Switch';
bio(127).sigName='';
bio(127).portIdx=0;
bio(127).dim=[1,1];
bio(127).sigWidth=1;
bio(127).sigAddress='&Walking01_withElmos_B.Switch_a';
bio(127).ndims=2;
bio(127).size=[];


bio(128).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Chart/p1';
bio(128).sigName='ControlWordIndex';
bio(128).portIdx=0;
bio(128).dim=[1,1];
bio(128).sigWidth=1;
bio(128).sigAddress='&Walking01_withElmos_B.ControlWordIndex';
bio(128).ndims=2;
bio(128).size=[];


bio(129).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Chart/p2';
bio(129).sigName='EnableTargetTorque';
bio(129).portIdx=1;
bio(129).dim=[1,1];
bio(129).sigWidth=1;
bio(129).sigAddress='&Walking01_withElmos_B.EnableTargetTorque';
bio(129).ndims=2;
bio(129).size=[];


bio(130).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Chart/p3';
bio(130).sigName='FaultDetected';
bio(130).portIdx=2;
bio(130).dim=[1,1];
bio(130).sigWidth=1;
bio(130).sigAddress='&Walking01_withElmos_B.FaultDetected';
bio(130).ndims=2;
bio(130).size=[];


bio(131).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Switch';
bio(131).sigName='';
bio(131).portIdx=0;
bio(131).dim=[1,1];
bio(131).sigWidth=1;
bio(131).sigAddress='&Walking01_withElmos_B.Switch_d';
bio(131).ndims=2;
bio(131).size=[];


bio(132).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Chart/p1';
bio(132).sigName='ControlWordIndex';
bio(132).portIdx=0;
bio(132).dim=[1,1];
bio(132).sigWidth=1;
bio(132).sigAddress='&Walking01_withElmos_B.sf_Chart_b.ControlWordIndex';
bio(132).ndims=2;
bio(132).size=[];


bio(133).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Chart/p2';
bio(133).sigName='EnableTargetTorque';
bio(133).portIdx=1;
bio(133).dim=[1,1];
bio(133).sigWidth=1;
bio(133).sigAddress='&Walking01_withElmos_B.sf_Chart_b.EnableTargetTorque';
bio(133).ndims=2;
bio(133).size=[];


bio(134).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Chart/p3';
bio(134).sigName='FaultDetected';
bio(134).portIdx=2;
bio(134).dim=[1,1];
bio(134).sigWidth=1;
bio(134).sigAddress='&Walking01_withElmos_B.sf_Chart_b.FaultDetected';
bio(134).ndims=2;
bio(134).size=[];


bio(135).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Switch';
bio(135).sigName='';
bio(135).portIdx=0;
bio(135).dim=[1,1];
bio(135).sigWidth=1;
bio(135).sigAddress='&Walking01_withElmos_B.Switch_i';
bio(135).ndims=2;
bio(135).size=[];


bio(136).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/Data Type Conversion3';
bio(136).sigName='';
bio(136).portIdx=0;
bio(136).dim=[1,1];
bio(136).sigWidth=1;
bio(136).sigAddress='&Walking01_withElmos_B.DataTypeConversion3_f';
bio(136).ndims=2;
bio(136).size=[];


bio(137).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/Data Type Conversion4';
bio(137).sigName='';
bio(137).portIdx=0;
bio(137).dim=[1,1];
bio(137).sigWidth=1;
bio(137).sigAddress='&Walking01_withElmos_B.DataTypeConversion4_k';
bio(137).ndims=2;
bio(137).size=[];


bio(138).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/Data Type Conversion5';
bio(138).sigName='';
bio(138).portIdx=0;
bio(138).dim=[1,1];
bio(138).sigWidth=1;
bio(138).sigAddress='&Walking01_withElmos_B.DataTypeConversion5_n';
bio(138).ndims=2;
bio(138).size=[];


bio(139).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var ';
bio(139).sigName='';
bio(139).portIdx=0;
bio(139).dim=[1,1];
bio(139).sigWidth=1;
bio(139).sigAddress='&Walking01_withElmos_B.EtherCATRxVar_o';
bio(139).ndims=2;
bio(139).size=[];


bio(140).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 1';
bio(140).sigName='';
bio(140).portIdx=0;
bio(140).dim=[1,1];
bio(140).sigWidth=1;
bio(140).sigAddress='&Walking01_withElmos_B.EtherCATRxVar1_h';
bio(140).ndims=2;
bio(140).size=[];


bio(141).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 10';
bio(141).sigName='';
bio(141).portIdx=0;
bio(141).dim=[1,1];
bio(141).sigWidth=1;
bio(141).sigAddress='&Walking01_withElmos_B.EtherCATRxVar10_b';
bio(141).ndims=2;
bio(141).size=[];


bio(142).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 11';
bio(142).sigName='';
bio(142).portIdx=0;
bio(142).dim=[1,1];
bio(142).sigWidth=1;
bio(142).sigAddress='&Walking01_withElmos_B.EtherCATRxVar11_h';
bio(142).ndims=2;
bio(142).size=[];


bio(143).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 12';
bio(143).sigName='';
bio(143).portIdx=0;
bio(143).dim=[1,1];
bio(143).sigWidth=1;
bio(143).sigAddress='&Walking01_withElmos_B.EtherCATRxVar12_b';
bio(143).ndims=2;
bio(143).size=[];


bio(144).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 13';
bio(144).sigName='';
bio(144).portIdx=0;
bio(144).dim=[1,1];
bio(144).sigWidth=1;
bio(144).sigAddress='&Walking01_withElmos_B.EtherCATRxVar13_j';
bio(144).ndims=2;
bio(144).size=[];


bio(145).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 14';
bio(145).sigName='';
bio(145).portIdx=0;
bio(145).dim=[1,1];
bio(145).sigWidth=1;
bio(145).sigAddress='&Walking01_withElmos_B.EtherCATRxVar14_fm';
bio(145).ndims=2;
bio(145).size=[];


bio(146).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 15';
bio(146).sigName='';
bio(146).portIdx=0;
bio(146).dim=[1,1];
bio(146).sigWidth=1;
bio(146).sigAddress='&Walking01_withElmos_B.EtherCATRxVar15_n';
bio(146).ndims=2;
bio(146).size=[];


bio(147).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 16';
bio(147).sigName='';
bio(147).portIdx=0;
bio(147).dim=[1,1];
bio(147).sigWidth=1;
bio(147).sigAddress='&Walking01_withElmos_B.EtherCATRxVar16_j';
bio(147).ndims=2;
bio(147).size=[];


bio(148).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 17';
bio(148).sigName='';
bio(148).portIdx=0;
bio(148).dim=[1,1];
bio(148).sigWidth=1;
bio(148).sigAddress='&Walking01_withElmos_B.EtherCATRxVar17_l';
bio(148).ndims=2;
bio(148).size=[];


bio(149).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 18';
bio(149).sigName='';
bio(149).portIdx=0;
bio(149).dim=[1,1];
bio(149).sigWidth=1;
bio(149).sigAddress='&Walking01_withElmos_B.EtherCATRxVar18_i';
bio(149).ndims=2;
bio(149).size=[];


bio(150).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 19';
bio(150).sigName='';
bio(150).portIdx=0;
bio(150).dim=[1,1];
bio(150).sigWidth=1;
bio(150).sigAddress='&Walking01_withElmos_B.EtherCATRxVar19_e';
bio(150).ndims=2;
bio(150).size=[];


bio(151).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 2';
bio(151).sigName='';
bio(151).portIdx=0;
bio(151).dim=[1,1];
bio(151).sigWidth=1;
bio(151).sigAddress='&Walking01_withElmos_B.EtherCATRxVar2_o';
bio(151).ndims=2;
bio(151).size=[];


bio(152).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 20';
bio(152).sigName='';
bio(152).portIdx=0;
bio(152).dim=[1,1];
bio(152).sigWidth=1;
bio(152).sigAddress='&Walking01_withElmos_B.EtherCATRxVar20_c';
bio(152).ndims=2;
bio(152).size=[];


bio(153).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 21';
bio(153).sigName='';
bio(153).portIdx=0;
bio(153).dim=[1,1];
bio(153).sigWidth=1;
bio(153).sigAddress='&Walking01_withElmos_B.EtherCATRxVar21_o';
bio(153).ndims=2;
bio(153).size=[];


bio(154).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 22';
bio(154).sigName='';
bio(154).portIdx=0;
bio(154).dim=[1,1];
bio(154).sigWidth=1;
bio(154).sigAddress='&Walking01_withElmos_B.EtherCATRxVar22_g';
bio(154).ndims=2;
bio(154).size=[];


bio(155).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 23';
bio(155).sigName='';
bio(155).portIdx=0;
bio(155).dim=[1,1];
bio(155).sigWidth=1;
bio(155).sigAddress='&Walking01_withElmos_B.EtherCATRxVar23';
bio(155).ndims=2;
bio(155).size=[];


bio(156).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 3';
bio(156).sigName='';
bio(156).portIdx=0;
bio(156).dim=[1,1];
bio(156).sigWidth=1;
bio(156).sigAddress='&Walking01_withElmos_B.EtherCATRxVar3_j';
bio(156).ndims=2;
bio(156).size=[];


bio(157).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 4';
bio(157).sigName='';
bio(157).portIdx=0;
bio(157).dim=[1,1];
bio(157).sigWidth=1;
bio(157).sigAddress='&Walking01_withElmos_B.EtherCATRxVar4_n';
bio(157).ndims=2;
bio(157).size=[];


bio(158).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 5';
bio(158).sigName='';
bio(158).portIdx=0;
bio(158).dim=[1,1];
bio(158).sigWidth=1;
bio(158).sigAddress='&Walking01_withElmos_B.EtherCATRxVar5_n';
bio(158).ndims=2;
bio(158).size=[];


bio(159).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 6';
bio(159).sigName='';
bio(159).portIdx=0;
bio(159).dim=[1,1];
bio(159).sigWidth=1;
bio(159).sigAddress='&Walking01_withElmos_B.EtherCATRxVar6_b';
bio(159).ndims=2;
bio(159).size=[];


bio(160).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 7';
bio(160).sigName='';
bio(160).portIdx=0;
bio(160).dim=[1,1];
bio(160).sigWidth=1;
bio(160).sigAddress='&Walking01_withElmos_B.EtherCATRxVar7_b';
bio(160).ndims=2;
bio(160).size=[];


bio(161).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 8';
bio(161).sigName='';
bio(161).portIdx=0;
bio(161).dim=[1,1];
bio(161).sigWidth=1;
bio(161).sigAddress='&Walking01_withElmos_B.EtherCATRxVar8_b';
bio(161).ndims=2;
bio(161).size=[];


bio(162).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 9';
bio(162).sigName='';
bio(162).portIdx=0;
bio(162).dim=[1,1];
bio(162).sigWidth=1;
bio(162).sigAddress='&Walking01_withElmos_B.EtherCATRxVar9_p';
bio(162).ndims=2;
bio(162).size=[];


bio(163).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/Data Type Conversion3';
bio(163).sigName='';
bio(163).portIdx=0;
bio(163).dim=[1,1];
bio(163).sigWidth=1;
bio(163).sigAddress='&Walking01_withElmos_B.DataTypeConversion3_g';
bio(163).ndims=2;
bio(163).size=[];


bio(164).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/Data Type Conversion4';
bio(164).sigName='';
bio(164).portIdx=0;
bio(164).dim=[1,1];
bio(164).sigWidth=1;
bio(164).sigAddress='&Walking01_withElmos_B.DataTypeConversion4_i';
bio(164).ndims=2;
bio(164).size=[];


bio(165).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/Data Type Conversion5';
bio(165).sigName='';
bio(165).portIdx=0;
bio(165).dim=[1,1];
bio(165).sigWidth=1;
bio(165).sigAddress='&Walking01_withElmos_B.DataTypeConversion5_b';
bio(165).ndims=2;
bio(165).size=[];


bio(166).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var ';
bio(166).sigName='';
bio(166).portIdx=0;
bio(166).dim=[1,1];
bio(166).sigWidth=1;
bio(166).sigAddress='&Walking01_withElmos_B.EtherCATRxVar_h';
bio(166).ndims=2;
bio(166).size=[];


bio(167).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 1';
bio(167).sigName='';
bio(167).portIdx=0;
bio(167).dim=[1,1];
bio(167).sigWidth=1;
bio(167).sigAddress='&Walking01_withElmos_B.EtherCATRxVar1_f';
bio(167).ndims=2;
bio(167).size=[];


bio(168).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 10';
bio(168).sigName='';
bio(168).portIdx=0;
bio(168).dim=[1,1];
bio(168).sigWidth=1;
bio(168).sigAddress='&Walking01_withElmos_B.EtherCATRxVar10_c';
bio(168).ndims=2;
bio(168).size=[];


bio(169).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 11';
bio(169).sigName='';
bio(169).portIdx=0;
bio(169).dim=[1,1];
bio(169).sigWidth=1;
bio(169).sigAddress='&Walking01_withElmos_B.EtherCATRxVar11_b';
bio(169).ndims=2;
bio(169).size=[];


bio(170).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 12';
bio(170).sigName='';
bio(170).portIdx=0;
bio(170).dim=[1,1];
bio(170).sigWidth=1;
bio(170).sigAddress='&Walking01_withElmos_B.EtherCATRxVar12_p';
bio(170).ndims=2;
bio(170).size=[];


bio(171).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 13';
bio(171).sigName='';
bio(171).portIdx=0;
bio(171).dim=[1,1];
bio(171).sigWidth=1;
bio(171).sigAddress='&Walking01_withElmos_B.EtherCATRxVar13_h';
bio(171).ndims=2;
bio(171).size=[];


bio(172).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 14';
bio(172).sigName='';
bio(172).portIdx=0;
bio(172).dim=[1,1];
bio(172).sigWidth=1;
bio(172).sigAddress='&Walking01_withElmos_B.EtherCATRxVar14_h';
bio(172).ndims=2;
bio(172).size=[];


bio(173).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 15';
bio(173).sigName='';
bio(173).portIdx=0;
bio(173).dim=[1,1];
bio(173).sigWidth=1;
bio(173).sigAddress='&Walking01_withElmos_B.EtherCATRxVar15';
bio(173).ndims=2;
bio(173).size=[];


bio(174).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 16';
bio(174).sigName='';
bio(174).portIdx=0;
bio(174).dim=[1,1];
bio(174).sigWidth=1;
bio(174).sigAddress='&Walking01_withElmos_B.EtherCATRxVar16';
bio(174).ndims=2;
bio(174).size=[];


bio(175).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 17';
bio(175).sigName='';
bio(175).portIdx=0;
bio(175).dim=[1,1];
bio(175).sigWidth=1;
bio(175).sigAddress='&Walking01_withElmos_B.EtherCATRxVar17';
bio(175).ndims=2;
bio(175).size=[];


bio(176).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 18';
bio(176).sigName='';
bio(176).portIdx=0;
bio(176).dim=[1,1];
bio(176).sigWidth=1;
bio(176).sigAddress='&Walking01_withElmos_B.EtherCATRxVar18';
bio(176).ndims=2;
bio(176).size=[];


bio(177).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 19';
bio(177).sigName='';
bio(177).portIdx=0;
bio(177).dim=[1,1];
bio(177).sigWidth=1;
bio(177).sigAddress='&Walking01_withElmos_B.EtherCATRxVar19_c';
bio(177).ndims=2;
bio(177).size=[];


bio(178).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 2';
bio(178).sigName='';
bio(178).portIdx=0;
bio(178).dim=[1,1];
bio(178).sigWidth=1;
bio(178).sigAddress='&Walking01_withElmos_B.EtherCATRxVar2_n';
bio(178).ndims=2;
bio(178).size=[];


bio(179).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 20';
bio(179).sigName='';
bio(179).portIdx=0;
bio(179).dim=[1,1];
bio(179).sigWidth=1;
bio(179).sigAddress='&Walking01_withElmos_B.EtherCATRxVar20_p';
bio(179).ndims=2;
bio(179).size=[];


bio(180).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 21';
bio(180).sigName='';
bio(180).portIdx=0;
bio(180).dim=[1,1];
bio(180).sigWidth=1;
bio(180).sigAddress='&Walking01_withElmos_B.EtherCATRxVar21';
bio(180).ndims=2;
bio(180).size=[];


bio(181).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 22';
bio(181).sigName='';
bio(181).portIdx=0;
bio(181).dim=[1,1];
bio(181).sigWidth=1;
bio(181).sigAddress='&Walking01_withElmos_B.EtherCATRxVar22';
bio(181).ndims=2;
bio(181).size=[];


bio(182).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 23';
bio(182).sigName='';
bio(182).portIdx=0;
bio(182).dim=[1,1];
bio(182).sigWidth=1;
bio(182).sigAddress='&Walking01_withElmos_B.EtherCATRxVar23_e';
bio(182).ndims=2;
bio(182).size=[];


bio(183).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 3';
bio(183).sigName='';
bio(183).portIdx=0;
bio(183).dim=[1,1];
bio(183).sigWidth=1;
bio(183).sigAddress='&Walking01_withElmos_B.EtherCATRxVar3_c4';
bio(183).ndims=2;
bio(183).size=[];


bio(184).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 4';
bio(184).sigName='';
bio(184).portIdx=0;
bio(184).dim=[1,1];
bio(184).sigWidth=1;
bio(184).sigAddress='&Walking01_withElmos_B.EtherCATRxVar4';
bio(184).ndims=2;
bio(184).size=[];


bio(185).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 5';
bio(185).sigName='';
bio(185).portIdx=0;
bio(185).dim=[1,1];
bio(185).sigWidth=1;
bio(185).sigAddress='&Walking01_withElmos_B.EtherCATRxVar5_k';
bio(185).ndims=2;
bio(185).size=[];


bio(186).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 6';
bio(186).sigName='';
bio(186).portIdx=0;
bio(186).dim=[1,1];
bio(186).sigWidth=1;
bio(186).sigAddress='&Walking01_withElmos_B.EtherCATRxVar6_n';
bio(186).ndims=2;
bio(186).size=[];


bio(187).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 7';
bio(187).sigName='';
bio(187).portIdx=0;
bio(187).dim=[1,1];
bio(187).sigWidth=1;
bio(187).sigAddress='&Walking01_withElmos_B.EtherCATRxVar7_g';
bio(187).ndims=2;
bio(187).size=[];


bio(188).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 8';
bio(188).sigName='';
bio(188).portIdx=0;
bio(188).dim=[1,1];
bio(188).sigWidth=1;
bio(188).sigAddress='&Walking01_withElmos_B.EtherCATRxVar8';
bio(188).ndims=2;
bio(188).size=[];


bio(189).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 9';
bio(189).sigName='';
bio(189).portIdx=0;
bio(189).dim=[1,1];
bio(189).sigWidth=1;
bio(189).sigAddress='&Walking01_withElmos_B.EtherCATRxVar9_i';
bio(189).ndims=2;
bio(189).size=[];


bio(190).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/Data Type Conversion3';
bio(190).sigName='';
bio(190).portIdx=0;
bio(190).dim=[1,1];
bio(190).sigWidth=1;
bio(190).sigAddress='&Walking01_withElmos_B.DataTypeConversion3_o';
bio(190).ndims=2;
bio(190).size=[];


bio(191).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/Data Type Conversion4';
bio(191).sigName='';
bio(191).portIdx=0;
bio(191).dim=[1,1];
bio(191).sigWidth=1;
bio(191).sigAddress='&Walking01_withElmos_B.DataTypeConversion4_n';
bio(191).ndims=2;
bio(191).size=[];


bio(192).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/Data Type Conversion5';
bio(192).sigName='';
bio(192).portIdx=0;
bio(192).dim=[1,1];
bio(192).sigWidth=1;
bio(192).sigAddress='&Walking01_withElmos_B.DataTypeConversion5_by';
bio(192).ndims=2;
bio(192).size=[];


bio(193).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var ';
bio(193).sigName='';
bio(193).portIdx=0;
bio(193).dim=[1,1];
bio(193).sigWidth=1;
bio(193).sigAddress='&Walking01_withElmos_B.EtherCATRxVar_p';
bio(193).ndims=2;
bio(193).size=[];


bio(194).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 1';
bio(194).sigName='';
bio(194).portIdx=0;
bio(194).dim=[1,1];
bio(194).sigWidth=1;
bio(194).sigAddress='&Walking01_withElmos_B.EtherCATRxVar1_b';
bio(194).ndims=2;
bio(194).size=[];


bio(195).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 10';
bio(195).sigName='';
bio(195).portIdx=0;
bio(195).dim=[1,1];
bio(195).sigWidth=1;
bio(195).sigAddress='&Walking01_withElmos_B.EtherCATRxVar10_g';
bio(195).ndims=2;
bio(195).size=[];


bio(196).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 11';
bio(196).sigName='';
bio(196).portIdx=0;
bio(196).dim=[1,1];
bio(196).sigWidth=1;
bio(196).sigAddress='&Walking01_withElmos_B.EtherCATRxVar11_l';
bio(196).ndims=2;
bio(196).size=[];


bio(197).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 12';
bio(197).sigName='';
bio(197).portIdx=0;
bio(197).dim=[1,1];
bio(197).sigWidth=1;
bio(197).sigAddress='&Walking01_withElmos_B.EtherCATRxVar12_i';
bio(197).ndims=2;
bio(197).size=[];


bio(198).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 13';
bio(198).sigName='';
bio(198).portIdx=0;
bio(198).dim=[1,1];
bio(198).sigWidth=1;
bio(198).sigAddress='&Walking01_withElmos_B.EtherCATRxVar13_c';
bio(198).ndims=2;
bio(198).size=[];


bio(199).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 14';
bio(199).sigName='';
bio(199).portIdx=0;
bio(199).dim=[1,1];
bio(199).sigWidth=1;
bio(199).sigAddress='&Walking01_withElmos_B.EtherCATRxVar14_n';
bio(199).ndims=2;
bio(199).size=[];


bio(200).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 15';
bio(200).sigName='';
bio(200).portIdx=0;
bio(200).dim=[1,1];
bio(200).sigWidth=1;
bio(200).sigAddress='&Walking01_withElmos_B.EtherCATRxVar15_a';
bio(200).ndims=2;
bio(200).size=[];


bio(201).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 16';
bio(201).sigName='';
bio(201).portIdx=0;
bio(201).dim=[1,1];
bio(201).sigWidth=1;
bio(201).sigAddress='&Walking01_withElmos_B.EtherCATRxVar16_a';
bio(201).ndims=2;
bio(201).size=[];


bio(202).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 17';
bio(202).sigName='';
bio(202).portIdx=0;
bio(202).dim=[1,1];
bio(202).sigWidth=1;
bio(202).sigAddress='&Walking01_withElmos_B.EtherCATRxVar17_kd';
bio(202).ndims=2;
bio(202).size=[];


bio(203).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 18';
bio(203).sigName='';
bio(203).portIdx=0;
bio(203).dim=[1,1];
bio(203).sigWidth=1;
bio(203).sigAddress='&Walking01_withElmos_B.EtherCATRxVar18_f';
bio(203).ndims=2;
bio(203).size=[];


bio(204).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 19';
bio(204).sigName='';
bio(204).portIdx=0;
bio(204).dim=[1,1];
bio(204).sigWidth=1;
bio(204).sigAddress='&Walking01_withElmos_B.EtherCATRxVar19_d';
bio(204).ndims=2;
bio(204).size=[];


bio(205).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 2';
bio(205).sigName='';
bio(205).portIdx=0;
bio(205).dim=[1,1];
bio(205).sigWidth=1;
bio(205).sigAddress='&Walking01_withElmos_B.EtherCATRxVar2_m';
bio(205).ndims=2;
bio(205).size=[];


bio(206).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 20';
bio(206).sigName='';
bio(206).portIdx=0;
bio(206).dim=[1,1];
bio(206).sigWidth=1;
bio(206).sigAddress='&Walking01_withElmos_B.EtherCATRxVar20';
bio(206).ndims=2;
bio(206).size=[];


bio(207).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 21';
bio(207).sigName='';
bio(207).portIdx=0;
bio(207).dim=[1,1];
bio(207).sigWidth=1;
bio(207).sigAddress='&Walking01_withElmos_B.EtherCATRxVar21_m';
bio(207).ndims=2;
bio(207).size=[];


bio(208).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 22';
bio(208).sigName='';
bio(208).portIdx=0;
bio(208).dim=[1,1];
bio(208).sigWidth=1;
bio(208).sigAddress='&Walking01_withElmos_B.EtherCATRxVar22_a';
bio(208).ndims=2;
bio(208).size=[];


bio(209).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 23';
bio(209).sigName='';
bio(209).portIdx=0;
bio(209).dim=[1,1];
bio(209).sigWidth=1;
bio(209).sigAddress='&Walking01_withElmos_B.EtherCATRxVar23_c';
bio(209).ndims=2;
bio(209).size=[];


bio(210).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 3';
bio(210).sigName='';
bio(210).portIdx=0;
bio(210).dim=[1,1];
bio(210).sigWidth=1;
bio(210).sigAddress='&Walking01_withElmos_B.EtherCATRxVar3_o';
bio(210).ndims=2;
bio(210).size=[];


bio(211).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 4';
bio(211).sigName='';
bio(211).portIdx=0;
bio(211).dim=[1,1];
bio(211).sigWidth=1;
bio(211).sigAddress='&Walking01_withElmos_B.EtherCATRxVar4_e';
bio(211).ndims=2;
bio(211).size=[];


bio(212).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 5';
bio(212).sigName='';
bio(212).portIdx=0;
bio(212).dim=[1,1];
bio(212).sigWidth=1;
bio(212).sigAddress='&Walking01_withElmos_B.EtherCATRxVar5_l';
bio(212).ndims=2;
bio(212).size=[];


bio(213).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 6';
bio(213).sigName='';
bio(213).portIdx=0;
bio(213).dim=[1,1];
bio(213).sigWidth=1;
bio(213).sigAddress='&Walking01_withElmos_B.EtherCATRxVar6_m';
bio(213).ndims=2;
bio(213).size=[];


bio(214).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 7';
bio(214).sigName='';
bio(214).portIdx=0;
bio(214).dim=[1,1];
bio(214).sigWidth=1;
bio(214).sigAddress='&Walking01_withElmos_B.EtherCATRxVar7_gy';
bio(214).ndims=2;
bio(214).size=[];


bio(215).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 8';
bio(215).sigName='';
bio(215).portIdx=0;
bio(215).dim=[1,1];
bio(215).sigWidth=1;
bio(215).sigAddress='&Walking01_withElmos_B.EtherCATRxVar8_bs';
bio(215).ndims=2;
bio(215).size=[];


bio(216).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 9';
bio(216).sigName='';
bio(216).portIdx=0;
bio(216).dim=[1,1];
bio(216).sigWidth=1;
bio(216).sigAddress='&Walking01_withElmos_B.EtherCATRxVar9_a';
bio(216).ndims=2;
bio(216).size=[];


bio(217).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/Data Type Conversion3';
bio(217).sigName='';
bio(217).portIdx=0;
bio(217).dim=[1,1];
bio(217).sigWidth=1;
bio(217).sigAddress='&Walking01_withElmos_B.DataTypeConversion3_f2';
bio(217).ndims=2;
bio(217).size=[];


bio(218).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/Data Type Conversion4';
bio(218).sigName='';
bio(218).portIdx=0;
bio(218).dim=[1,1];
bio(218).sigWidth=1;
bio(218).sigAddress='&Walking01_withElmos_B.DataTypeConversion4_o';
bio(218).ndims=2;
bio(218).size=[];


bio(219).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/Data Type Conversion5';
bio(219).sigName='';
bio(219).portIdx=0;
bio(219).dim=[1,1];
bio(219).sigWidth=1;
bio(219).sigAddress='&Walking01_withElmos_B.DataTypeConversion5_a';
bio(219).ndims=2;
bio(219).size=[];


bio(220).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var ';
bio(220).sigName='';
bio(220).portIdx=0;
bio(220).dim=[1,1];
bio(220).sigWidth=1;
bio(220).sigAddress='&Walking01_withElmos_B.EtherCATRxVar_k';
bio(220).ndims=2;
bio(220).size=[];


bio(221).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 1';
bio(221).sigName='';
bio(221).portIdx=0;
bio(221).dim=[1,1];
bio(221).sigWidth=1;
bio(221).sigAddress='&Walking01_withElmos_B.EtherCATRxVar1_pm';
bio(221).ndims=2;
bio(221).size=[];


bio(222).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 10';
bio(222).sigName='';
bio(222).portIdx=0;
bio(222).dim=[1,1];
bio(222).sigWidth=1;
bio(222).sigAddress='&Walking01_withElmos_B.EtherCATRxVar10_f';
bio(222).ndims=2;
bio(222).size=[];


bio(223).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 11';
bio(223).sigName='';
bio(223).portIdx=0;
bio(223).dim=[1,1];
bio(223).sigWidth=1;
bio(223).sigAddress='&Walking01_withElmos_B.EtherCATRxVar11_a';
bio(223).ndims=2;
bio(223).size=[];


bio(224).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 12';
bio(224).sigName='';
bio(224).portIdx=0;
bio(224).dim=[1,1];
bio(224).sigWidth=1;
bio(224).sigAddress='&Walking01_withElmos_B.EtherCATRxVar12_c';
bio(224).ndims=2;
bio(224).size=[];


bio(225).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 13';
bio(225).sigName='';
bio(225).portIdx=0;
bio(225).dim=[1,1];
bio(225).sigWidth=1;
bio(225).sigAddress='&Walking01_withElmos_B.EtherCATRxVar13_o';
bio(225).ndims=2;
bio(225).size=[];


bio(226).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 14';
bio(226).sigName='';
bio(226).portIdx=0;
bio(226).dim=[1,1];
bio(226).sigWidth=1;
bio(226).sigAddress='&Walking01_withElmos_B.EtherCATRxVar14_g';
bio(226).ndims=2;
bio(226).size=[];


bio(227).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 15';
bio(227).sigName='';
bio(227).portIdx=0;
bio(227).dim=[1,1];
bio(227).sigWidth=1;
bio(227).sigAddress='&Walking01_withElmos_B.EtherCATRxVar15_m';
bio(227).ndims=2;
bio(227).size=[];


bio(228).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 16';
bio(228).sigName='';
bio(228).portIdx=0;
bio(228).dim=[1,1];
bio(228).sigWidth=1;
bio(228).sigAddress='&Walking01_withElmos_B.EtherCATRxVar16_b';
bio(228).ndims=2;
bio(228).size=[];


bio(229).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 17';
bio(229).sigName='';
bio(229).portIdx=0;
bio(229).dim=[1,1];
bio(229).sigWidth=1;
bio(229).sigAddress='&Walking01_withElmos_B.EtherCATRxVar17_k';
bio(229).ndims=2;
bio(229).size=[];


bio(230).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 18';
bio(230).sigName='';
bio(230).portIdx=0;
bio(230).dim=[1,1];
bio(230).sigWidth=1;
bio(230).sigAddress='&Walking01_withElmos_B.EtherCATRxVar18_c';
bio(230).ndims=2;
bio(230).size=[];


bio(231).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 19';
bio(231).sigName='';
bio(231).portIdx=0;
bio(231).dim=[1,1];
bio(231).sigWidth=1;
bio(231).sigAddress='&Walking01_withElmos_B.EtherCATRxVar19_m';
bio(231).ndims=2;
bio(231).size=[];


bio(232).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 2';
bio(232).sigName='';
bio(232).portIdx=0;
bio(232).dim=[1,1];
bio(232).sigWidth=1;
bio(232).sigAddress='&Walking01_withElmos_B.EtherCATRxVar2_p';
bio(232).ndims=2;
bio(232).size=[];


bio(233).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 20';
bio(233).sigName='';
bio(233).portIdx=0;
bio(233).dim=[1,1];
bio(233).sigWidth=1;
bio(233).sigAddress='&Walking01_withElmos_B.EtherCATRxVar20_l';
bio(233).ndims=2;
bio(233).size=[];


bio(234).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 21';
bio(234).sigName='';
bio(234).portIdx=0;
bio(234).dim=[1,1];
bio(234).sigWidth=1;
bio(234).sigAddress='&Walking01_withElmos_B.EtherCATRxVar21_b';
bio(234).ndims=2;
bio(234).size=[];


bio(235).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 22';
bio(235).sigName='';
bio(235).portIdx=0;
bio(235).dim=[1,1];
bio(235).sigWidth=1;
bio(235).sigAddress='&Walking01_withElmos_B.EtherCATRxVar22_o';
bio(235).ndims=2;
bio(235).size=[];


bio(236).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 23';
bio(236).sigName='';
bio(236).portIdx=0;
bio(236).dim=[1,1];
bio(236).sigWidth=1;
bio(236).sigAddress='&Walking01_withElmos_B.EtherCATRxVar23_p';
bio(236).ndims=2;
bio(236).size=[];


bio(237).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 3';
bio(237).sigName='';
bio(237).portIdx=0;
bio(237).dim=[1,1];
bio(237).sigWidth=1;
bio(237).sigAddress='&Walking01_withElmos_B.EtherCATRxVar3_k';
bio(237).ndims=2;
bio(237).size=[];


bio(238).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 4';
bio(238).sigName='';
bio(238).portIdx=0;
bio(238).dim=[1,1];
bio(238).sigWidth=1;
bio(238).sigAddress='&Walking01_withElmos_B.EtherCATRxVar4_p';
bio(238).ndims=2;
bio(238).size=[];


bio(239).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 5';
bio(239).sigName='';
bio(239).portIdx=0;
bio(239).dim=[1,1];
bio(239).sigWidth=1;
bio(239).sigAddress='&Walking01_withElmos_B.EtherCATRxVar5_p';
bio(239).ndims=2;
bio(239).size=[];


bio(240).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 6';
bio(240).sigName='';
bio(240).portIdx=0;
bio(240).dim=[1,1];
bio(240).sigWidth=1;
bio(240).sigAddress='&Walking01_withElmos_B.EtherCATRxVar6_o';
bio(240).ndims=2;
bio(240).size=[];


bio(241).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 7';
bio(241).sigName='';
bio(241).portIdx=0;
bio(241).dim=[1,1];
bio(241).sigWidth=1;
bio(241).sigAddress='&Walking01_withElmos_B.EtherCATRxVar7_d';
bio(241).ndims=2;
bio(241).size=[];


bio(242).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 8';
bio(242).sigName='';
bio(242).portIdx=0;
bio(242).dim=[1,1];
bio(242).sigWidth=1;
bio(242).sigAddress='&Walking01_withElmos_B.EtherCATRxVar8_h';
bio(242).ndims=2;
bio(242).size=[];


bio(243).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 9';
bio(243).sigName='';
bio(243).portIdx=0;
bio(243).dim=[1,1];
bio(243).sigWidth=1;
bio(243).sigAddress='&Walking01_withElmos_B.EtherCATRxVar9_j';
bio(243).ndims=2;
bio(243).size=[];


bio(244).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/AnomalyDetection/p1';
bio(244).sigName='q_clean';
bio(244).portIdx=0;
bio(244).dim=[1,1];
bio(244).sigWidth=1;
bio(244).sigAddress='&Walking01_withElmos_B.CoreSubsys_p[2].sf_AnomalyDetection.q_clean';
bio(244).ndims=2;
bio(244).size=[];


bio(245).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/AnomalyDetection/p2';
bio(245).sigName='ErrorCount';
bio(245).portIdx=1;
bio(245).dim=[1,1];
bio(245).sigWidth=1;
bio(245).sigAddress='&Walking01_withElmos_B.CoreSubsys_p[2].sf_AnomalyDetection.ErrorCount';
bio(245).ndims=2;
bio(245).size=[];


bio(246).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Rate Transition';
bio(246).sigName='';
bio(246).portIdx=0;
bio(246).dim=[1,1];
bio(246).sigWidth=1;
bio(246).sigAddress='&Walking01_withElmos_B.CoreSubsys_p[2].RateTransition';
bio(246).ndims=2;
bio(246).size=[];


bio(247).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Rate Transition3';
bio(247).sigName='';
bio(247).portIdx=0;
bio(247).dim=[1,1];
bio(247).sigWidth=1;
bio(247).sigAddress='&Walking01_withElmos_B.CoreSubsys_p[2].RateTransition3';
bio(247).ndims=2;
bio(247).size=[];


bio(248).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Rate Transition4';
bio(248).sigName='';
bio(248).portIdx=0;
bio(248).dim=[1,1];
bio(248).sigWidth=1;
bio(248).sigAddress='&Walking01_withElmos_B.CoreSubsys_p[2].RateTransition4';
bio(248).ndims=2;
bio(248).size=[];


bio(249).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Rate Transition5';
bio(249).sigName='';
bio(249).portIdx=0;
bio(249).dim=[1,1];
bio(249).sigWidth=1;
bio(249).sigAddress='&Walking01_withElmos_B.CoreSubsys_p[2].RateTransition5';
bio(249).ndims=2;
bio(249).size=[];


bio(250).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Rate Transition6';
bio(250).sigName='';
bio(250).portIdx=0;
bio(250).dim=[1,2];
bio(250).sigWidth=2;
bio(250).sigAddress='&Walking01_withElmos_B.CoreSubsys_p[2].RateTransition6[0]';
bio(250).ndims=2;
bio(250).size=[];


bio(251).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Rate Transition7';
bio(251).sigName='';
bio(251).portIdx=0;
bio(251).dim=[1,1];
bio(251).sigWidth=1;
bio(251).sigAddress='&Walking01_withElmos_B.CoreSubsys_p[2].RateTransition7';
bio(251).ndims=2;
bio(251).size=[];


bio(252).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Switch';
bio(252).sigName='';
bio(252).portIdx=0;
bio(252).dim=[1,1];
bio(252).sigWidth=1;
bio(252).sigAddress='&Walking01_withElmos_B.CoreSubsys_p[2].Switch';
bio(252).ndims=2;
bio(252).size=[];


bio(253).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Unit Delay';
bio(253).sigName='';
bio(253).portIdx=0;
bio(253).dim=[1,1];
bio(253).sigWidth=1;
bio(253).sigAddress='&Walking01_withElmos_B.CoreSubsys_p[2].UnitDelay';
bio(253).ndims=2;
bio(253).size=[];


bio(254).blkName='DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/Subsystem/FIFO write 1';
bio(254).sigName='';
bio(254).portIdx=0;
bio(254).dim=[1,1];
bio(254).sigWidth=1;
bio(254).sigAddress='&Walking01_withElmos_B.FIFOwrite1';
bio(254).ndims=2;
bio(254).size=[];


bio(255).blkName='DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/Subsystem/Read HW FIFO';
bio(255).sigName='';
bio(255).portIdx=0;
bio(255).dim=[65,1];
bio(255).sigWidth=65;
bio(255).sigAddress='&Walking01_withElmos_B.ReadHWFIFO[0]';
bio(255).ndims=2;
bio(255).size=[];


bio(256).blkName='DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/UpdateOrientation/FIFO bin read ';
bio(256).sigName='';
bio(256).portIdx=0;
bio(256).dim=[37,1];
bio(256).sigWidth=37;
bio(256).sigAddress='&Walking01_withElmos_B.FIFObinread[0]';
bio(256).ndims=2;
bio(256).size=[];


bio(257).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive';
bio(257).sigName='';
bio(257).portIdx=0;
bio(257).dim=[1,1];
bio(257).sigWidth=1;
bio(257).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive_n';
bio(257).ndims=2;
bio(257).size=[];


bio(258).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive1';
bio(258).sigName='';
bio(258).portIdx=0;
bio(258).dim=[1,1];
bio(258).sigWidth=1;
bio(258).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive1_n';
bio(258).ndims=2;
bio(258).size=[];


bio(259).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive2';
bio(259).sigName='';
bio(259).portIdx=0;
bio(259).dim=[1,1];
bio(259).sigWidth=1;
bio(259).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive2';
bio(259).ndims=2;
bio(259).size=[];


bio(260).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive3';
bio(260).sigName='';
bio(260).portIdx=0;
bio(260).dim=[1,1];
bio(260).sigWidth=1;
bio(260).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive3_j';
bio(260).ndims=2;
bio(260).size=[];


bio(261).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive4';
bio(261).sigName='';
bio(261).portIdx=0;
bio(261).dim=[1,1];
bio(261).sigWidth=1;
bio(261).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive4_b';
bio(261).ndims=2;
bio(261).size=[];


bio(262).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive5';
bio(262).sigName='';
bio(262).portIdx=0;
bio(262).dim=[1,1];
bio(262).sigWidth=1;
bio(262).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive5_h';
bio(262).ndims=2;
bio(262).size=[];


bio(263).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem1/Merge';
bio(263).sigName='';
bio(263).portIdx=0;
bio(263).dim=[1,1];
bio(263).sigWidth=1;
bio(263).sigAddress='&Walking01_withElmos_B.Merge';
bio(263).ndims=2;
bio(263).size=[];


bio(264).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive';
bio(264).sigName='';
bio(264).portIdx=0;
bio(264).dim=[1,1];
bio(264).sigWidth=1;
bio(264).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive';
bio(264).ndims=2;
bio(264).size=[];


bio(265).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive1';
bio(265).sigName='';
bio(265).portIdx=0;
bio(265).dim=[1,1];
bio(265).sigWidth=1;
bio(265).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive1';
bio(265).ndims=2;
bio(265).size=[];


bio(266).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive2';
bio(266).sigName='';
bio(266).portIdx=0;
bio(266).dim=[1,1];
bio(266).sigWidth=1;
bio(266).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive2_k';
bio(266).ndims=2;
bio(266).size=[];


bio(267).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive3';
bio(267).sigName='';
bio(267).portIdx=0;
bio(267).dim=[1,1];
bio(267).sigWidth=1;
bio(267).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive3';
bio(267).ndims=2;
bio(267).size=[];


bio(268).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive4';
bio(268).sigName='';
bio(268).portIdx=0;
bio(268).dim=[1,1];
bio(268).sigWidth=1;
bio(268).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive4';
bio(268).ndims=2;
bio(268).size=[];


bio(269).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive5';
bio(269).sigName='';
bio(269).portIdx=0;
bio(269).dim=[1,1];
bio(269).sigWidth=1;
bio(269).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive5';
bio(269).ndims=2;
bio(269).size=[];


bio(270).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem1/Merge';
bio(270).sigName='';
bio(270).portIdx=0;
bio(270).dim=[1,1];
bio(270).sigWidth=1;
bio(270).sigAddress='&Walking01_withElmos_B.Merge_l';
bio(270).ndims=2;
bio(270).size=[];


bio(271).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive';
bio(271).sigName='';
bio(271).portIdx=0;
bio(271).dim=[1,1];
bio(271).sigWidth=1;
bio(271).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive_nq';
bio(271).ndims=2;
bio(271).size=[];


bio(272).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive1';
bio(272).sigName='';
bio(272).portIdx=0;
bio(272).dim=[1,1];
bio(272).sigWidth=1;
bio(272).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive1_i';
bio(272).ndims=2;
bio(272).size=[];


bio(273).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive2';
bio(273).sigName='';
bio(273).portIdx=0;
bio(273).dim=[1,1];
bio(273).sigWidth=1;
bio(273).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive2_l';
bio(273).ndims=2;
bio(273).size=[];


bio(274).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive3';
bio(274).sigName='';
bio(274).portIdx=0;
bio(274).dim=[1,1];
bio(274).sigWidth=1;
bio(274).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive3_n';
bio(274).ndims=2;
bio(274).size=[];


bio(275).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive4';
bio(275).sigName='';
bio(275).portIdx=0;
bio(275).dim=[1,1];
bio(275).sigWidth=1;
bio(275).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive4_p';
bio(275).ndims=2;
bio(275).size=[];


bio(276).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive5';
bio(276).sigName='';
bio(276).portIdx=0;
bio(276).dim=[1,1];
bio(276).sigWidth=1;
bio(276).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive5_p';
bio(276).ndims=2;
bio(276).size=[];


bio(277).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem1/Merge';
bio(277).sigName='';
bio(277).portIdx=0;
bio(277).dim=[1,1];
bio(277).sigWidth=1;
bio(277).sigAddress='&Walking01_withElmos_B.Merge_h';
bio(277).ndims=2;
bio(277).size=[];


bio(278).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive';
bio(278).sigName='';
bio(278).portIdx=0;
bio(278).dim=[1,1];
bio(278).sigWidth=1;
bio(278).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive_b';
bio(278).ndims=2;
bio(278).size=[];


bio(279).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive1';
bio(279).sigName='';
bio(279).portIdx=0;
bio(279).dim=[1,1];
bio(279).sigWidth=1;
bio(279).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive1_f';
bio(279).ndims=2;
bio(279).size=[];


bio(280).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive2';
bio(280).sigName='';
bio(280).portIdx=0;
bio(280).dim=[1,1];
bio(280).sigWidth=1;
bio(280).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive2_h';
bio(280).ndims=2;
bio(280).size=[];


bio(281).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive3';
bio(281).sigName='';
bio(281).portIdx=0;
bio(281).dim=[1,1];
bio(281).sigWidth=1;
bio(281).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive3_b';
bio(281).ndims=2;
bio(281).size=[];


bio(282).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive4';
bio(282).sigName='';
bio(282).portIdx=0;
bio(282).dim=[1,1];
bio(282).sigWidth=1;
bio(282).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive4_d';
bio(282).ndims=2;
bio(282).size=[];


bio(283).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive5';
bio(283).sigName='';
bio(283).portIdx=0;
bio(283).dim=[1,1];
bio(283).sigWidth=1;
bio(283).sigAddress='&Walking01_withElmos_B.EtherCATPDOReceive5_d';
bio(283).ndims=2;
bio(283).size=[];


bio(284).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem1/Merge';
bio(284).sigName='';
bio(284).portIdx=0;
bio(284).dim=[1,1];
bio(284).sigWidth=1;
bio(284).sigAddress='&Walking01_withElmos_B.Merge_e';
bio(284).ndims=2;
bio(284).size=[];


bio(285).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem2/Compare To Constant/Compare';
bio(285).sigName='';
bio(285).portIdx=0;
bio(285).dim=[1,1];
bio(285).sigWidth=1;
bio(285).sigAddress='&Walking01_withElmos_B.Compare_pz';
bio(285).ndims=2;
bio(285).size=[];


bio(286).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem3/Compare To Constant/Compare';
bio(286).sigName='';
bio(286).portIdx=0;
bio(286).dim=[1,1];
bio(286).sigWidth=1;
bio(286).sigAddress='&Walking01_withElmos_B.Compare_h';
bio(286).ndims=2;
bio(286).size=[];


bio(287).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem4/Compare To Constant/Compare';
bio(287).sigName='';
bio(287).portIdx=0;
bio(287).dim=[1,1];
bio(287).sigWidth=1;
bio(287).sigAddress='&Walking01_withElmos_B.Compare_e5';
bio(287).ndims=2;
bio(287).size=[];


bio(288).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem5/Compare To Constant/Compare';
bio(288).sigName='';
bio(288).portIdx=0;
bio(288).dim=[1,1];
bio(288).sigWidth=1;
bio(288).sigAddress='&Walking01_withElmos_B.Compare_g';
bio(288).ndims=2;
bio(288).size=[];


bio(289).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem2/Compare To Constant/Compare';
bio(289).sigName='';
bio(289).portIdx=0;
bio(289).dim=[1,1];
bio(289).sigWidth=1;
bio(289).sigAddress='&Walking01_withElmos_B.Compare_n';
bio(289).ndims=2;
bio(289).size=[];


bio(290).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem3/Compare To Constant/Compare';
bio(290).sigName='';
bio(290).portIdx=0;
bio(290).dim=[1,1];
bio(290).sigWidth=1;
bio(290).sigAddress='&Walking01_withElmos_B.Compare_lw';
bio(290).ndims=2;
bio(290).size=[];


bio(291).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem4/Compare To Constant/Compare';
bio(291).sigName='';
bio(291).portIdx=0;
bio(291).dim=[1,1];
bio(291).sigWidth=1;
bio(291).sigAddress='&Walking01_withElmos_B.Compare_a';
bio(291).ndims=2;
bio(291).size=[];


bio(292).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem5/Compare To Constant/Compare';
bio(292).sigName='';
bio(292).portIdx=0;
bio(292).dim=[1,1];
bio(292).sigWidth=1;
bio(292).sigAddress='&Walking01_withElmos_B.Compare_e';
bio(292).ndims=2;
bio(292).size=[];


bio(293).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem2/Compare To Constant/Compare';
bio(293).sigName='';
bio(293).portIdx=0;
bio(293).dim=[1,1];
bio(293).sigWidth=1;
bio(293).sigAddress='&Walking01_withElmos_B.Compare_n4';
bio(293).ndims=2;
bio(293).size=[];


bio(294).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem3/Compare To Constant/Compare';
bio(294).sigName='';
bio(294).portIdx=0;
bio(294).dim=[1,1];
bio(294).sigWidth=1;
bio(294).sigAddress='&Walking01_withElmos_B.Compare_f';
bio(294).ndims=2;
bio(294).size=[];


bio(295).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem4/Compare To Constant/Compare';
bio(295).sigName='';
bio(295).portIdx=0;
bio(295).dim=[1,1];
bio(295).sigWidth=1;
bio(295).sigAddress='&Walking01_withElmos_B.Compare_co';
bio(295).ndims=2;
bio(295).size=[];


bio(296).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem5/Compare To Constant/Compare';
bio(296).sigName='';
bio(296).portIdx=0;
bio(296).dim=[1,1];
bio(296).sigWidth=1;
bio(296).sigAddress='&Walking01_withElmos_B.Compare_ju';
bio(296).ndims=2;
bio(296).size=[];


bio(297).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem2/Compare To Constant/Compare';
bio(297).sigName='';
bio(297).portIdx=0;
bio(297).dim=[1,1];
bio(297).sigWidth=1;
bio(297).sigAddress='&Walking01_withElmos_B.Compare_p';
bio(297).ndims=2;
bio(297).size=[];


bio(298).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem3/Compare To Constant/Compare';
bio(298).sigName='';
bio(298).portIdx=0;
bio(298).dim=[1,1];
bio(298).sigWidth=1;
bio(298).sigAddress='&Walking01_withElmos_B.Compare_i';
bio(298).ndims=2;
bio(298).size=[];


bio(299).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem4/Compare To Constant/Compare';
bio(299).sigName='';
bio(299).portIdx=0;
bio(299).dim=[1,1];
bio(299).sigWidth=1;
bio(299).sigAddress='&Walking01_withElmos_B.Compare_j';
bio(299).ndims=2;
bio(299).size=[];


bio(300).blkName='DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem5/Compare To Constant/Compare';
bio(300).sigName='';
bio(300).portIdx=0;
bio(300).dim=[1,1];
bio(300).sigWidth=1;
bio(300).sigAddress='&Walking01_withElmos_B.Compare_c';
bio(300).ndims=2;
bio(300).size=[];


function len = getlenBIO
len = 300;
