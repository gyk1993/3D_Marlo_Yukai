  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 2;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Walking01_withElmos_P)
    ;%
      section.nData     = 98;
      section.data(98)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_P.AllowDoubleSupport
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_P.CommandSerialize
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_P.ControllerModeInit
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking01_withElmos_P.DecouplingMode
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking01_withElmos_P.DesiredYawOffset
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking01_withElmos_P.EnableFeedforwardOnStep
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking01_withElmos_P.EnableTransition
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking01_withElmos_P.EnableVelocityBasedUpdate
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Walking01_withElmos_P.ErrorVelZeroFactor
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Walking01_withElmos_P.ErrorZeroFactor
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 14;
	
	  ;% Walking01_withElmos_P.FeedforwardGain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 20;
	
	  ;% Walking01_withElmos_P.GearOffsets
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 26;
	
	  ;% Walking01_withElmos_P.H0Transition
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 30;
	
	  ;% Walking01_withElmos_P.H0WalkingDouble
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 108;
	
	  ;% Walking01_withElmos_P.H0WalkingSingle
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 186;
	
	  ;% Walking01_withElmos_P.HAlphaStarInjection
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 264;
	
	  ;% Walking01_withElmos_P.HAlphaStarPosing
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 300;
	
	  ;% Walking01_withElmos_P.HAlphaStarTransition
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 336;
	
	  ;% Walking01_withElmos_P.HAlphaStarWalkingDouble
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 372;
	
	  ;% Walking01_withElmos_P.HAlphaStarWalkingSingle
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 408;
	
	  ;% Walking01_withElmos_P.HAlphaTransition
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 444;
	
	  ;% Walking01_withElmos_P.HAlphaWalkingDouble
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 480;
	
	  ;% Walking01_withElmos_P.HAlphaWalkingSingle
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 516;
	
	  ;% Walking01_withElmos_P.HBarAlphaTransition
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 552;
	
	  ;% Walking01_withElmos_P.HBarAlphaWalkingDouble
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 582;
	
	  ;% Walking01_withElmos_P.HBarAlphaWalkingSingle
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 612;
	
	  ;% Walking01_withElmos_P.HBarLimitsTransition
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 642;
	
	  ;% Walking01_withElmos_P.HBarLimitsWalkingDouble
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 654;
	
	  ;% Walking01_withElmos_P.HBarLimitsWalkingSingle
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 666;
	
	  ;% Walking01_withElmos_P.IMUCommand
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 678;
	
	  ;% Walking01_withElmos_P.IMUThreshold
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 679;
	
	  ;% Walking01_withElmos_P.IMUTorsoOffsets
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 680;
	
	  ;% Walking01_withElmos_P.K1MidStanceUpdate
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 682;
	
	  ;% Walking01_withElmos_P.K2MidStanceUpdate
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 688;
	
	  ;% Walking01_withElmos_P.KASaturationEarly
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 694;
	
	  ;% Walking01_withElmos_P.KASaturationMax
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 695;
	
	  ;% Walking01_withElmos_P.KASaturationS1
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 696;
	
	  ;% Walking01_withElmos_P.KASaturationS2
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 697;
	
	  ;% Walking01_withElmos_P.KASpringOffsets
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 698;
	
	  ;% Walking01_withElmos_P.KThetaMinus
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 700;
	
	  ;% Walking01_withElmos_P.KThetaPlus
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 701;
	
	  ;% Walking01_withElmos_P.LegHipTorqueLimit
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 702;
	
	  ;% Walking01_withElmos_P.ManualSwap
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 704;
	
	  ;% Walking01_withElmos_P.MaxError
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 705;
	
	  ;% Walking01_withElmos_P.MaxErrorVel
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 706;
	
	  ;% Walking01_withElmos_P.MedullaCommand
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 707;
	
	  ;% Walking01_withElmos_P.MinDeltaTheta
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 708;
	
	  ;% Walking01_withElmos_P.MinDeltaThetaTransition
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 709;
	
	  ;% Walking01_withElmos_P.PhiOffset
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 710;
	
	  ;% Walking01_withElmos_P.RLimits
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 711;
	
	  ;% Walking01_withElmos_P.ResetControl
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 713;
	
	  ;% Walking01_withElmos_P.RollPhaseVelocityThresh
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 714;
	
	  ;% Walking01_withElmos_P.RunMode
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 715;
	
	  ;% Walking01_withElmos_P.SelectFeedforward
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 716;
	
	  ;% Walking01_withElmos_P.StanceLegInit
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 717;
	
	  ;% Walking01_withElmos_P.StartSecondGaitOnStep
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 718;
	
	  ;% Walking01_withElmos_P.TMaxUpdate
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 719;
	
	  ;% Walking01_withElmos_P.TPosing
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 720;
	
	  ;% Walking01_withElmos_P.Theta0
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 721;
	
	  ;% Walking01_withElmos_P.ThetaLimitsTransition
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 722;
	
	  ;% Walking01_withElmos_P.ThetaLimitsWalkingDouble
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 724;
	
	  ;% Walking01_withElmos_P.ThetaLimitsWalkingSingle
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 726;
	
	  ;% Walking01_withElmos_P.TorsoBackAngle
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 728;
	
	  ;% Walking01_withElmos_P.TorsoBackOnStep
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 729;
	
	  ;% Walking01_withElmos_P.TorsoCOMOffsets
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 730;
	
	  ;% Walking01_withElmos_P.UseKASaturation
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 732;
	
	  ;% Walking01_withElmos_P.UsePosingControl
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 733;
	
	  ;% Walking01_withElmos_P.VelocityBasedUpdateDTheta0
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 734;
	
	  ;% Walking01_withElmos_P.VelocityBasedUpdateK1
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 735;
	
	  ;% Walking01_withElmos_P.VelocityBasedUpdateK2
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 741;
	
	  ;% Walking01_withElmos_P.VelocityBasedUpdateLimits
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 747;
	
	  ;% Walking01_withElmos_P.VelocityControlTorsoGain
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 759;
	
	  ;% Walking01_withElmos_P.VelocityControlTorsoMax
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 760;
	
	  ;% Walking01_withElmos_P.VelocityControlTorsoMin
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 761;
	
	  ;% Walking01_withElmos_P.VelocityControlTorsoV0
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 762;
	
	  ;% Walking01_withElmos_P.YawLimit
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 763;
	
	  ;% Walking01_withElmos_P.epsilon
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 764;
	
	  ;% Walking01_withElmos_P.ff_params
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 766;
	
	  ;% Walking01_withElmos_P.hd_posing
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 771;
	
	  ;% Walking01_withElmos_P.k_precomp
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 777;
	
	  ;% Walking01_withElmos_P.kd
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 778;
	
	  ;% Walking01_withElmos_P.kd_2dof
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 784;
	
	  ;% Walking01_withElmos_P.kd_torso
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 785;
	
	  ;% Walking01_withElmos_P.kp
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 787;
	
	  ;% Walking01_withElmos_P.kp_2dof
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 793;
	
	  ;% Walking01_withElmos_P.lat_bias
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 794;
	
	  ;% Walking01_withElmos_P.lat_bias2
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 795;
	
	  ;% Walking01_withElmos_P.lateralParams
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 796;
	
	  ;% Walking01_withElmos_P.linkFeedback
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 801;
	
	  ;% Walking01_withElmos_P.optimal_sat_weights
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 802;
	
	  ;% Walking01_withElmos_P.step_params
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 804;
	
	  ;% Walking01_withElmos_P.swap_params
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 809;
	
	  ;% Walking01_withElmos_P.tStepInitial
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 816;
	
	  ;% Walking01_withElmos_P.transitionParams
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 817;
	
	  ;% Walking01_withElmos_P.u_ff
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 822;
	
	  ;% Walking01_withElmos_P.use2DOFHipControl
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 828;
	
	  ;% Walking01_withElmos_P.useOptimalSaturation
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 829;
	
	  ;% Walking01_withElmos_P.w_torso_lat
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 830;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_P.EnableFT
	  section.data(1).logicalSrcIdx = 98;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_P.ResetDAQ
	  section.data(2).logicalSrcIdx = 99;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_P.ResetYaw
	  section.data(3).logicalSrcIdx = 100;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 23;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Walking01_withElmos_B)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.BusConversion_InsertedFor_State
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.ControlParams
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.VectorConcatenate
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.ControlState
	  section.data(1).logicalSrcIdx = 3;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.FIFOwrite1
	  section.data(1).logicalSrcIdx = 4;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.DataTypeConversion57
	  section.data(1).logicalSrcIdx = 5;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.DataTypeConversion81
	  section.data(2).logicalSrcIdx = 6;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_B.DataTypeConversion9
	  section.data(3).logicalSrcIdx = 7;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking01_withElmos_B.DataTypeConversion33
	  section.data(4).logicalSrcIdx = 8;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking01_withElmos_B.DataTypeConversion104
	  section.data(5).logicalSrcIdx = 9;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking01_withElmos_B.DataTypeConversion119
	  section.data(6).logicalSrcIdx = 10;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking01_withElmos_B.VectorConcatenate_m
	  section.data(7).logicalSrcIdx = 11;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking01_withElmos_B.TmpSignalConversionAtEncoderFil
	  section.data(8).logicalSrcIdx = 12;
	  section.data(8).dtTransOffset = 25;
	
	  ;% Walking01_withElmos_B.RateTransition2
	  section.data(9).logicalSrcIdx = 13;
	  section.data(9).dtTransOffset = 44;
	
	  ;% Walking01_withElmos_B.RateTransition1
	  section.data(10).logicalSrcIdx = 14;
	  section.data(10).dtTransOffset = 47;
	
	  ;% Walking01_withElmos_B.TKA
	  section.data(11).logicalSrcIdx = 15;
	  section.data(11).dtTransOffset = 50;
	
	  ;% Walking01_withElmos_B.VectorConcatenate_a
	  section.data(12).logicalSrcIdx = 16;
	  section.data(12).dtTransOffset = 52;
	
	  ;% Walking01_withElmos_B.EnableTransition
	  section.data(13).logicalSrcIdx = 17;
	  section.data(13).dtTransOffset = 54;
	
	  ;% Walking01_withElmos_B.DataTypeConversion1
	  section.data(14).logicalSrcIdx = 18;
	  section.data(14).dtTransOffset = 55;
	
	  ;% Walking01_withElmos_B.ResetControl
	  section.data(15).logicalSrcIdx = 19;
	  section.data(15).dtTransOffset = 56;
	
	  ;% Walking01_withElmos_B.DataTypeConversion97
	  section.data(16).logicalSrcIdx = 20;
	  section.data(16).dtTransOffset = 57;
	
	  ;% Walking01_withElmos_B.TaskExecutionTime
	  section.data(17).logicalSrcIdx = 21;
	  section.data(17).dtTransOffset = 63;
	
	  ;% Walking01_withElmos_B.Bias
	  section.data(18).logicalSrcIdx = 22;
	  section.data(18).dtTransOffset = 64;
	
	  ;% Walking01_withElmos_B.SerialOut
	  section.data(19).logicalSrcIdx = 23;
	  section.data(19).dtTransOffset = 65;
	
	  ;% Walking01_withElmos_B.s
	  section.data(20).logicalSrcIdx = 24;
	  section.data(20).dtTransOffset = 70;
	
	  ;% Walking01_withElmos_B.ErrorCount
	  section.data(21).logicalSrcIdx = 25;
	  section.data(21).dtTransOffset = 71;
	
	  ;% Walking01_withElmos_B.MedullaCommandSafe
	  section.data(22).logicalSrcIdx = 26;
	  section.data(22).dtTransOffset = 72;
	
	  ;% Walking01_withElmos_B.SafetyCountOut
	  section.data(23).logicalSrcIdx = 27;
	  section.data(23).dtTransOffset = 73;
	
	  ;% Walking01_withElmos_B.dq_clean
	  section.data(24).logicalSrcIdx = 28;
	  section.data(24).dtTransOffset = 74;
	
	  ;% Walking01_withElmos_B.Rollover
	  section.data(25).logicalSrcIdx = 33;
	  section.data(25).dtTransOffset = 87;
	
	  ;% Walking01_withElmos_B.IncCalTick
	  section.data(26).logicalSrcIdx = 34;
	  section.data(26).dtTransOffset = 96;
	
	  ;% Walking01_withElmos_B.ControlWordIndex
	  section.data(27).logicalSrcIdx = 35;
	  section.data(27).dtTransOffset = 102;
	
	  ;% Walking01_withElmos_B.EnableTargetTorque
	  section.data(28).logicalSrcIdx = 36;
	  section.data(28).dtTransOffset = 103;
	
	  ;% Walking01_withElmos_B.FaultDetected
	  section.data(29).logicalSrcIdx = 37;
	  section.data(29).dtTransOffset = 104;
	
	  ;% Walking01_withElmos_B.ControlWordIndex_j
	  section.data(30).logicalSrcIdx = 38;
	  section.data(30).dtTransOffset = 105;
	
	  ;% Walking01_withElmos_B.EnableTargetTorque_f
	  section.data(31).logicalSrcIdx = 39;
	  section.data(31).dtTransOffset = 106;
	
	  ;% Walking01_withElmos_B.FaultDetected_n
	  section.data(32).logicalSrcIdx = 40;
	  section.data(32).dtTransOffset = 107;
	
	  ;% Walking01_withElmos_B.q
	  section.data(33).logicalSrcIdx = 42;
	  section.data(33).dtTransOffset = 108;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.EtherCATInit
	  section.data(1).logicalSrcIdx = 43;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive1
	  section.data(2).logicalSrcIdx = 44;
	  section.data(2).dtTransOffset = 6;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive1_f
	  section.data(3).logicalSrcIdx = 45;
	  section.data(3).dtTransOffset = 7;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive1_n
	  section.data(4).logicalSrcIdx = 46;
	  section.data(4).dtTransOffset = 8;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive1_i
	  section.data(5).logicalSrcIdx = 47;
	  section.data(5).dtTransOffset = 9;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive4
	  section.data(6).logicalSrcIdx = 48;
	  section.data(6).dtTransOffset = 10;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive4_d
	  section.data(7).logicalSrcIdx = 49;
	  section.data(7).dtTransOffset = 11;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive4_b
	  section.data(8).logicalSrcIdx = 50;
	  section.data(8).dtTransOffset = 12;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive4_p
	  section.data(9).logicalSrcIdx = 51;
	  section.data(9).dtTransOffset = 13;
	
	  ;% Walking01_withElmos_B.DataTypeConversion5
	  section.data(10).logicalSrcIdx = 52;
	  section.data(10).dtTransOffset = 14;
	
	  ;% Walking01_withElmos_B.DataTypeConversion5_e
	  section.data(11).logicalSrcIdx = 53;
	  section.data(11).dtTransOffset = 15;
	
	  ;% Walking01_withElmos_B.DataTypeConversion5_n
	  section.data(12).logicalSrcIdx = 54;
	  section.data(12).dtTransOffset = 16;
	
	  ;% Walking01_withElmos_B.DataTypeConversion5_b
	  section.data(13).logicalSrcIdx = 55;
	  section.data(13).dtTransOffset = 17;
	
	  ;% Walking01_withElmos_B.DataTypeConversion5_by
	  section.data(14).logicalSrcIdx = 56;
	  section.data(14).dtTransOffset = 18;
	
	  ;% Walking01_withElmos_B.DataTypeConversion5_a
	  section.data(15).logicalSrcIdx = 57;
	  section.data(15).dtTransOffset = 19;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 32;
      section.data(32)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.EtherCATRxVar4
	  section.data(1).logicalSrcIdx = 58;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar4_p
	  section.data(2).logicalSrcIdx = 59;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar4_n
	  section.data(3).logicalSrcIdx = 60;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar4_e
	  section.data(4).logicalSrcIdx = 61;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar8
	  section.data(5).logicalSrcIdx = 62;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar8_h
	  section.data(6).logicalSrcIdx = 63;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar8_b
	  section.data(7).logicalSrcIdx = 64;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar8_bs
	  section.data(8).logicalSrcIdx = 65;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar4_m
	  section.data(9).logicalSrcIdx = 66;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar4_nd
	  section.data(10).logicalSrcIdx = 67;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar6
	  section.data(11).logicalSrcIdx = 68;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar1
	  section.data(12).logicalSrcIdx = 69;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar2
	  section.data(13).logicalSrcIdx = 70;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar5
	  section.data(14).logicalSrcIdx = 71;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar3
	  section.data(15).logicalSrcIdx = 72;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar4_ph
	  section.data(16).logicalSrcIdx = 73;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar19
	  section.data(17).logicalSrcIdx = 74;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar7
	  section.data(18).logicalSrcIdx = 75;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar8_m
	  section.data(19).logicalSrcIdx = 76;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar10
	  section.data(20).logicalSrcIdx = 77;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar14
	  section.data(21).logicalSrcIdx = 78;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar13
	  section.data(22).logicalSrcIdx = 79;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Walking01_withElmos_B.GetOverloadCounter
	  section.data(23).logicalSrcIdx = 80;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Walking01_withElmos_B.RateTransition1_p
	  section.data(24).logicalSrcIdx = 81;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Walking01_withElmos_B.RateTransition
	  section.data(25).logicalSrcIdx = 82;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar11
	  section.data(26).logicalSrcIdx = 83;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar12
	  section.data(27).logicalSrcIdx = 84;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar9
	  section.data(28).logicalSrcIdx = 85;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Walking01_withElmos_B.GetOverloadCounter1
	  section.data(29).logicalSrcIdx = 86;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Walking01_withElmos_B.GetOverloadCounter2
	  section.data(30).logicalSrcIdx = 87;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Walking01_withElmos_B.ReadHWFIFO
	  section.data(31).logicalSrcIdx = 88;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Walking01_withElmos_B.FIFObinread
	  section.data(32).logicalSrcIdx = 89;
	  section.data(32).dtTransOffset = 95;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 22;
      section.data(22)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.EtherCATPDOReceive
	  section.data(1).logicalSrcIdx = 90;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive_b
	  section.data(2).logicalSrcIdx = 91;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive_n
	  section.data(3).logicalSrcIdx = 92;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive_nq
	  section.data(4).logicalSrcIdx = 93;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive3
	  section.data(5).logicalSrcIdx = 94;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive3_b
	  section.data(6).logicalSrcIdx = 95;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive3_j
	  section.data(7).logicalSrcIdx = 96;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive3_n
	  section.data(8).logicalSrcIdx = 97;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar6_n
	  section.data(9).logicalSrcIdx = 98;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar7_g
	  section.data(10).logicalSrcIdx = 99;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar6_o
	  section.data(11).logicalSrcIdx = 100;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar7_d
	  section.data(12).logicalSrcIdx = 101;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar
	  section.data(13).logicalSrcIdx = 102;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar6_b
	  section.data(14).logicalSrcIdx = 103;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar7_b
	  section.data(15).logicalSrcIdx = 104;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar6_m
	  section.data(16).logicalSrcIdx = 105;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar7_gy
	  section.data(17).logicalSrcIdx = 106;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar_i
	  section.data(18).logicalSrcIdx = 107;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Walking01_withElmos_B.Switch
	  section.data(19).logicalSrcIdx = 108;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Walking01_withElmos_B.Switch_a
	  section.data(20).logicalSrcIdx = 109;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Walking01_withElmos_B.Switch_d
	  section.data(21).logicalSrcIdx = 110;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Walking01_withElmos_B.Switch_i
	  section.data(22).logicalSrcIdx = 111;
	  section.data(22).dtTransOffset = 21;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 92;
      section.data(92)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.EtherCATRxVar_h
	  section.data(1).logicalSrcIdx = 112;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar_k
	  section.data(2).logicalSrcIdx = 113;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar_o
	  section.data(3).logicalSrcIdx = 114;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar_p
	  section.data(4).logicalSrcIdx = 115;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar2_g
	  section.data(5).logicalSrcIdx = 116;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar2_i
	  section.data(6).logicalSrcIdx = 117;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar12_p
	  section.data(7).logicalSrcIdx = 118;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar13_h
	  section.data(8).logicalSrcIdx = 119;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar14_h
	  section.data(9).logicalSrcIdx = 120;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar15
	  section.data(10).logicalSrcIdx = 121;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar16
	  section.data(11).logicalSrcIdx = 122;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar17
	  section.data(12).logicalSrcIdx = 123;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar12_c
	  section.data(13).logicalSrcIdx = 124;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar13_o
	  section.data(14).logicalSrcIdx = 125;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar14_g
	  section.data(15).logicalSrcIdx = 126;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar15_m
	  section.data(16).logicalSrcIdx = 127;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar16_b
	  section.data(17).logicalSrcIdx = 128;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar17_k
	  section.data(18).logicalSrcIdx = 129;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar12_h
	  section.data(19).logicalSrcIdx = 130;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar13_e
	  section.data(20).logicalSrcIdx = 131;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar14_f
	  section.data(21).logicalSrcIdx = 132;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar12_b
	  section.data(22).logicalSrcIdx = 133;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar13_j
	  section.data(23).logicalSrcIdx = 134;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar14_fm
	  section.data(24).logicalSrcIdx = 135;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar15_n
	  section.data(25).logicalSrcIdx = 136;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar16_j
	  section.data(26).logicalSrcIdx = 137;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar17_l
	  section.data(27).logicalSrcIdx = 138;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar12_i
	  section.data(28).logicalSrcIdx = 139;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar13_c
	  section.data(29).logicalSrcIdx = 140;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar14_n
	  section.data(30).logicalSrcIdx = 141;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar15_a
	  section.data(31).logicalSrcIdx = 142;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar16_a
	  section.data(32).logicalSrcIdx = 143;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar17_kd
	  section.data(33).logicalSrcIdx = 144;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar12_pv
	  section.data(34).logicalSrcIdx = 145;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar13_e0
	  section.data(35).logicalSrcIdx = 146;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar14_b
	  section.data(36).logicalSrcIdx = 147;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive5
	  section.data(37).logicalSrcIdx = 148;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive5_d
	  section.data(38).logicalSrcIdx = 149;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive5_h
	  section.data(39).logicalSrcIdx = 150;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive5_p
	  section.data(40).logicalSrcIdx = 151;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar10_c
	  section.data(41).logicalSrcIdx = 152;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar10_f
	  section.data(42).logicalSrcIdx = 153;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar6_a
	  section.data(43).logicalSrcIdx = 154;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar10_b
	  section.data(44).logicalSrcIdx = 155;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar10_g
	  section.data(45).logicalSrcIdx = 156;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar6_f
	  section.data(46).logicalSrcIdx = 157;
	  section.data(46).dtTransOffset = 45;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar11_b
	  section.data(47).logicalSrcIdx = 158;
	  section.data(47).dtTransOffset = 46;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar11_a
	  section.data(48).logicalSrcIdx = 159;
	  section.data(48).dtTransOffset = 47;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar1_p
	  section.data(49).logicalSrcIdx = 160;
	  section.data(49).dtTransOffset = 48;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar11_h
	  section.data(50).logicalSrcIdx = 161;
	  section.data(50).dtTransOffset = 49;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar11_l
	  section.data(51).logicalSrcIdx = 162;
	  section.data(51).dtTransOffset = 50;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar1_m
	  section.data(52).logicalSrcIdx = 163;
	  section.data(52).dtTransOffset = 51;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar5_n
	  section.data(53).logicalSrcIdx = 164;
	  section.data(53).dtTransOffset = 52;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar5_o
	  section.data(54).logicalSrcIdx = 165;
	  section.data(54).dtTransOffset = 53;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar3_h
	  section.data(55).logicalSrcIdx = 166;
	  section.data(55).dtTransOffset = 54;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar9_p
	  section.data(56).logicalSrcIdx = 167;
	  section.data(56).dtTransOffset = 55;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar1_h
	  section.data(57).logicalSrcIdx = 168;
	  section.data(57).dtTransOffset = 56;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar5_d
	  section.data(58).logicalSrcIdx = 169;
	  section.data(58).dtTransOffset = 57;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar3_c
	  section.data(59).logicalSrcIdx = 170;
	  section.data(59).dtTransOffset = 58;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar23
	  section.data(60).logicalSrcIdx = 171;
	  section.data(60).dtTransOffset = 59;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar2_o
	  section.data(61).logicalSrcIdx = 172;
	  section.data(61).dtTransOffset = 60;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar3_j
	  section.data(62).logicalSrcIdx = 173;
	  section.data(62).dtTransOffset = 61;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar23_c
	  section.data(63).logicalSrcIdx = 174;
	  section.data(63).dtTransOffset = 62;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar5_l
	  section.data(64).logicalSrcIdx = 175;
	  section.data(64).dtTransOffset = 63;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar9_a
	  section.data(65).logicalSrcIdx = 176;
	  section.data(65).dtTransOffset = 64;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar1_b
	  section.data(66).logicalSrcIdx = 177;
	  section.data(66).dtTransOffset = 65;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar2_m
	  section.data(67).logicalSrcIdx = 178;
	  section.data(67).dtTransOffset = 66;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar3_o
	  section.data(68).logicalSrcIdx = 179;
	  section.data(68).dtTransOffset = 67;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar23_e
	  section.data(69).logicalSrcIdx = 180;
	  section.data(69).dtTransOffset = 68;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar5_k
	  section.data(70).logicalSrcIdx = 181;
	  section.data(70).dtTransOffset = 69;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar9_i
	  section.data(71).logicalSrcIdx = 182;
	  section.data(71).dtTransOffset = 70;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar1_f
	  section.data(72).logicalSrcIdx = 183;
	  section.data(72).dtTransOffset = 71;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar2_n
	  section.data(73).logicalSrcIdx = 184;
	  section.data(73).dtTransOffset = 72;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar3_c4
	  section.data(74).logicalSrcIdx = 185;
	  section.data(74).dtTransOffset = 73;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar23_p
	  section.data(75).logicalSrcIdx = 186;
	  section.data(75).dtTransOffset = 74;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar5_p
	  section.data(76).logicalSrcIdx = 187;
	  section.data(76).dtTransOffset = 75;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar9_j
	  section.data(77).logicalSrcIdx = 188;
	  section.data(77).dtTransOffset = 76;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar1_pm
	  section.data(78).logicalSrcIdx = 189;
	  section.data(78).dtTransOffset = 77;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar2_p
	  section.data(79).logicalSrcIdx = 190;
	  section.data(79).dtTransOffset = 78;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar3_k
	  section.data(80).logicalSrcIdx = 191;
	  section.data(80).dtTransOffset = 79;
	
	  ;% Walking01_withElmos_B.DataTypeConversion4
	  section.data(81).logicalSrcIdx = 192;
	  section.data(81).dtTransOffset = 80;
	
	  ;% Walking01_withElmos_B.DataTypeConversion4_h
	  section.data(82).logicalSrcIdx = 193;
	  section.data(82).dtTransOffset = 81;
	
	  ;% Walking01_withElmos_B.DataTypeConversion4_a
	  section.data(83).logicalSrcIdx = 194;
	  section.data(83).dtTransOffset = 82;
	
	  ;% Walking01_withElmos_B.DataTypeConversion1_l
	  section.data(84).logicalSrcIdx = 195;
	  section.data(84).dtTransOffset = 83;
	
	  ;% Walking01_withElmos_B.Merge
	  section.data(85).logicalSrcIdx = 196;
	  section.data(85).dtTransOffset = 84;
	
	  ;% Walking01_withElmos_B.Merge_l
	  section.data(86).logicalSrcIdx = 197;
	  section.data(86).dtTransOffset = 85;
	
	  ;% Walking01_withElmos_B.Merge_h
	  section.data(87).logicalSrcIdx = 198;
	  section.data(87).dtTransOffset = 86;
	
	  ;% Walking01_withElmos_B.Merge_e
	  section.data(88).logicalSrcIdx = 199;
	  section.data(88).dtTransOffset = 87;
	
	  ;% Walking01_withElmos_B.DataTypeConversion4_k
	  section.data(89).logicalSrcIdx = 200;
	  section.data(89).dtTransOffset = 88;
	
	  ;% Walking01_withElmos_B.DataTypeConversion4_i
	  section.data(90).logicalSrcIdx = 201;
	  section.data(90).dtTransOffset = 89;
	
	  ;% Walking01_withElmos_B.DataTypeConversion4_n
	  section.data(91).logicalSrcIdx = 202;
	  section.data(91).dtTransOffset = 90;
	
	  ;% Walking01_withElmos_B.DataTypeConversion4_o
	  section.data(92).logicalSrcIdx = 203;
	  section.data(92).dtTransOffset = 91;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.EtherCATPDOReceive2
	  section.data(1).logicalSrcIdx = 204;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive2_k
	  section.data(2).logicalSrcIdx = 205;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive2_l
	  section.data(3).logicalSrcIdx = 206;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking01_withElmos_B.EtherCATPDOReceive2_h
	  section.data(4).logicalSrcIdx = 207;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 42;
      section.data(42)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.EtherCATRxVar18
	  section.data(1).logicalSrcIdx = 208;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar18_c
	  section.data(2).logicalSrcIdx = 209;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar18_i
	  section.data(3).logicalSrcIdx = 210;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar18_f
	  section.data(4).logicalSrcIdx = 211;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar15_b
	  section.data(5).logicalSrcIdx = 212;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar15_g
	  section.data(6).logicalSrcIdx = 213;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar17_c
	  section.data(7).logicalSrcIdx = 214;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking01_withElmos_B.Compare
	  section.data(8).logicalSrcIdx = 215;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar21
	  section.data(9).logicalSrcIdx = 216;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar21_b
	  section.data(10).logicalSrcIdx = 217;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar18_j
	  section.data(11).logicalSrcIdx = 218;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar21_o
	  section.data(12).logicalSrcIdx = 219;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar21_m
	  section.data(13).logicalSrcIdx = 220;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar18_h
	  section.data(14).logicalSrcIdx = 221;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar22
	  section.data(15).logicalSrcIdx = 222;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar22_o
	  section.data(16).logicalSrcIdx = 223;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar19_o
	  section.data(17).logicalSrcIdx = 224;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar22_g
	  section.data(18).logicalSrcIdx = 225;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar22_a
	  section.data(19).logicalSrcIdx = 226;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar19_i
	  section.data(20).logicalSrcIdx = 227;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar18_k
	  section.data(21).logicalSrcIdx = 228;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar19_c
	  section.data(22).logicalSrcIdx = 229;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar19_m
	  section.data(23).logicalSrcIdx = 230;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar16_bt
	  section.data(24).logicalSrcIdx = 231;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar19_e
	  section.data(25).logicalSrcIdx = 232;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar19_d
	  section.data(26).logicalSrcIdx = 233;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar16_d
	  section.data(27).logicalSrcIdx = 234;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar15_d
	  section.data(28).logicalSrcIdx = 235;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar17_j
	  section.data(29).logicalSrcIdx = 236;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar17_p
	  section.data(30).logicalSrcIdx = 237;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar16_k
	  section.data(31).logicalSrcIdx = 238;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar20
	  section.data(32).logicalSrcIdx = 239;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar20_c
	  section.data(33).logicalSrcIdx = 240;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar20_p
	  section.data(34).logicalSrcIdx = 241;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Walking01_withElmos_B.EtherCATRxVar20_l
	  section.data(35).logicalSrcIdx = 242;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Walking01_withElmos_B.DataTypeConversion3
	  section.data(36).logicalSrcIdx = 243;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Walking01_withElmos_B.DataTypeConversion3_i
	  section.data(37).logicalSrcIdx = 244;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Walking01_withElmos_B.DataTypeConversion3_j
	  section.data(38).logicalSrcIdx = 245;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Walking01_withElmos_B.DataTypeConversion3_f
	  section.data(39).logicalSrcIdx = 246;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Walking01_withElmos_B.DataTypeConversion3_g
	  section.data(40).logicalSrcIdx = 247;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Walking01_withElmos_B.DataTypeConversion3_o
	  section.data(41).logicalSrcIdx = 248;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Walking01_withElmos_B.DataTypeConversion3_f2
	  section.data(42).logicalSrcIdx = 249;
	  section.data(42).dtTransOffset = 41;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.LogicalOperator1
	  section.data(1).logicalSrcIdx = 250;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.Compare_l
	  section.data(2).logicalSrcIdx = 251;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_B.FixPtRelationalOperator
	  section.data(3).logicalSrcIdx = 252;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking01_withElmos_B.RateTransition3
	  section.data(4).logicalSrcIdx = 253;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking01_withElmos_B.Compare_n
	  section.data(5).logicalSrcIdx = 254;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking01_withElmos_B.Compare_lw
	  section.data(6).logicalSrcIdx = 255;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking01_withElmos_B.Compare_a
	  section.data(7).logicalSrcIdx = 256;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking01_withElmos_B.Compare_e
	  section.data(8).logicalSrcIdx = 257;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Walking01_withElmos_B.Compare_p
	  section.data(9).logicalSrcIdx = 258;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Walking01_withElmos_B.Compare_i
	  section.data(10).logicalSrcIdx = 259;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Walking01_withElmos_B.Compare_j
	  section.data(11).logicalSrcIdx = 260;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Walking01_withElmos_B.Compare_c
	  section.data(12).logicalSrcIdx = 261;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Walking01_withElmos_B.Compare_pz
	  section.data(13).logicalSrcIdx = 262;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Walking01_withElmos_B.Compare_h
	  section.data(14).logicalSrcIdx = 263;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Walking01_withElmos_B.Compare_e5
	  section.data(15).logicalSrcIdx = 264;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Walking01_withElmos_B.Compare_g
	  section.data(16).logicalSrcIdx = 265;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Walking01_withElmos_B.Compare_n4
	  section.data(17).logicalSrcIdx = 266;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Walking01_withElmos_B.Compare_f
	  section.data(18).logicalSrcIdx = 267;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Walking01_withElmos_B.Compare_co
	  section.data(19).logicalSrcIdx = 268;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Walking01_withElmos_B.Compare_ju
	  section.data(20).logicalSrcIdx = 269;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Walking01_withElmos_B.LogicalOperator2
	  section.data(21).logicalSrcIdx = 272;
	  section.data(21).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.sf_ComputeEulerAngles_i.ZYX
	  section.data(1).logicalSrcIdx = 273;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.sf_ComputeEulerAngles_i.dZYX
	  section.data(2).logicalSrcIdx = 274;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Walking01_withElmos_B.sf_ComputeEulerAngles_i.Rk
	  section.data(3).logicalSrcIdx = 275;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Walking01_withElmos_B.sf_ComputeEulerAngles_i.R0
	  section.data(4).logicalSrcIdx = 276;
	  section.data(4).dtTransOffset = 15;
	
	  ;% Walking01_withElmos_B.sf_ComputeEulerAngles_i.YawRollover
	  section.data(5).logicalSrcIdx = 277;
	  section.data(5).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(13) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.CoreSubsys_p[2].RateTransition
	  section.data(1).logicalSrcIdx = 278;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.CoreSubsys_p[2].UnitDelay
	  section.data(2).logicalSrcIdx = 279;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_B.CoreSubsys_p[2].RateTransition6
	  section.data(3).logicalSrcIdx = 280;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking01_withElmos_B.CoreSubsys_p[2].RateTransition5
	  section.data(4).logicalSrcIdx = 281;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Walking01_withElmos_B.CoreSubsys_p[2].RateTransition3
	  section.data(5).logicalSrcIdx = 282;
	  section.data(5).dtTransOffset = 5;
	
	  ;% Walking01_withElmos_B.CoreSubsys_p[2].RateTransition4
	  section.data(6).logicalSrcIdx = 283;
	  section.data(6).dtTransOffset = 6;
	
	  ;% Walking01_withElmos_B.CoreSubsys_p[2].Switch
	  section.data(7).logicalSrcIdx = 284;
	  section.data(7).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.CoreSubsys_p[2].RateTransition7
	  section.data(1).logicalSrcIdx = 285;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(15) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.CoreSubsys_p[2].sf_AnomalyDetection.q_clean
	  section.data(1).logicalSrcIdx = 286;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.CoreSubsys_p[2].sf_AnomalyDetection.ErrorCount
	  section.data(2).logicalSrcIdx = 287;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(16) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.sf_Chart_b.ControlWordIndex
	  section.data(1).logicalSrcIdx = 288;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.sf_Chart_b.EnableTargetTorque
	  section.data(2).logicalSrcIdx = 289;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_B.sf_Chart_b.FaultDetected
	  section.data(3).logicalSrcIdx = 290;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(17) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.sf_Chart.ControlWordIndex
	  section.data(1).logicalSrcIdx = 291;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.sf_Chart.EnableTargetTorque
	  section.data(2).logicalSrcIdx = 292;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_B.sf_Chart.FaultDetected
	  section.data(3).logicalSrcIdx = 293;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.sf_TypecastAndCast2.y
	  section.data(1).logicalSrcIdx = 294;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.sf_TypecastAndCast1.y
	  section.data(1).logicalSrcIdx = 295;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(20) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.CoreSubsys[18].UnitDelay
	  section.data(1).logicalSrcIdx = 296;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.CoreSubsys[18].DiscreteStateSpace
	  section.data(2).logicalSrcIdx = 297;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(21) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.CoreSubsys[18].sf_AnomalyDetection.q_clean
	  section.data(1).logicalSrcIdx = 298;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.CoreSubsys[18].sf_AnomalyDetection.ErrorCount
	  section.data(2).logicalSrcIdx = 299;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(22) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_B.sf_ComputeEulerAngles.ZYX
	  section.data(1).logicalSrcIdx = 300;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_B.sf_ComputeEulerAngles.dZYX
	  section.data(2).logicalSrcIdx = 301;
	  section.data(2).dtTransOffset = 3;
	
	  ;% Walking01_withElmos_B.sf_ComputeEulerAngles.Rk
	  section.data(3).logicalSrcIdx = 302;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Walking01_withElmos_B.sf_ComputeEulerAngles.R0
	  section.data(4).logicalSrcIdx = 303;
	  section.data(4).dtTransOffset = 15;
	
	  ;% Walking01_withElmos_B.sf_ComputeEulerAngles.YawRollover
	  section.data(5).logicalSrcIdx = 304;
	  section.data(5).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(23) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 50;
    sectIdxOffset = 23;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (Walking01_withElmos_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.ControlParamsPrev
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.ControlStatePrev
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 33;
      section.data(33)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.UnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.UnitDelay_DSTATE
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 9;
	
	  ;% Walking01_withElmos_DW.UnitDelay2_DSTATE
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 18;
	
	  ;% Walking01_withElmos_DW.UnitDelay4_DSTATE
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 24;
	
	  ;% Walking01_withElmos_DW.UnitDelay3_DSTATE
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 33;
	
	  ;% Walking01_withElmos_DW.DiscreteStateSpace_DSTATE
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 35;
	
	  ;% Walking01_withElmos_DW.DiscreteStateSpace1_DSTATE
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 39;
	
	  ;% Walking01_withElmos_DW.UnitDelay_DSTATE_d
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 43;
	
	  ;% Walking01_withElmos_DW.UnitDelay1_DSTATE_g
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 44;
	
	  ;% Walking01_withElmos_DW.DiscreteFilter_states
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 45;
	
	  ;% Walking01_withElmos_DW.UnitDelay_DSTATE_k
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 75;
	
	  ;% Walking01_withElmos_DW.UnitDelay1_DSTATE_h
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 76;
	
	  ;% Walking01_withElmos_DW.ResettableDelay_DSTATE
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 80;
	
	  ;% Walking01_withElmos_DW.UnitDelay2_DSTATE_o
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 81;
	
	  ;% Walking01_withElmos_DW.UnitDelay1_DSTATE_c
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 90;
	
	  ;% Walking01_withElmos_DW.UnitDelay1_DSTATE_l
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 92;
	
	  ;% Walking01_withElmos_DW.UnitDelay2_DSTATE_p
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 101;
	
	  ;% Walking01_withElmos_DW.UnitDelay_DSTATE_p
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 104;
	
	  ;% Walking01_withElmos_DW.UnitDelay3_DSTATE_j
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 107;
	
	  ;% Walking01_withElmos_DW.RateTransition2_Buffer0
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 108;
	
	  ;% Walking01_withElmos_DW.RateTransition1_Buffer0
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 111;
	
	  ;% Walking01_withElmos_DW.DiscreteFilter_tmp
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 114;
	
	  ;% Walking01_withElmos_DW.SerialBuffer
	  section.data(23).logicalSrcIdx = 24;
	  section.data(23).dtTransOffset = 144;
	
	  ;% Walking01_withElmos_DW.SerialIdx
	  section.data(24).logicalSrcIdx = 25;
	  section.data(24).dtTransOffset = 2120;
	
	  ;% Walking01_withElmos_DW.TransitionStepCount
	  section.data(25).logicalSrcIdx = 26;
	  section.data(25).dtTransOffset = 2121;
	
	  ;% Walking01_withElmos_DW.WalkingStepCount
	  section.data(26).logicalSrcIdx = 27;
	  section.data(26).dtTransOffset = 2122;
	
	  ;% Walking01_withElmos_DW.s
	  section.data(27).logicalSrcIdx = 28;
	  section.data(27).dtTransOffset = 2123;
	
	  ;% Walking01_withElmos_DW.SerialBufferBegin
	  section.data(28).logicalSrcIdx = 29;
	  section.data(28).dtTransOffset = 2124;
	
	  ;% Walking01_withElmos_DW.SerialBufferEnd
	  section.data(29).logicalSrcIdx = 30;
	  section.data(29).dtTransOffset = 2125;
	
	  ;% Walking01_withElmos_DW.theta
	  section.data(30).logicalSrcIdx = 31;
	  section.data(30).dtTransOffset = 2126;
	
	  ;% Walking01_withElmos_DW.tLastSend
	  section.data(31).logicalSrcIdx = 32;
	  section.data(31).dtTransOffset = 2127;
	
	  ;% Walking01_withElmos_DW.Timeout
	  section.data(32).logicalSrcIdx = 33;
	  section.data(32).dtTransOffset = 2128;
	
	  ;% Walking01_withElmos_DW.Timeout_i
	  section.data(33).logicalSrcIdx = 34;
	  section.data(33).dtTransOffset = 2129;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.FIFOwrite1_PWORK
	  section.data(1).logicalSrcIdx = 35;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.FIFObinread_PWORK
	  section.data(2).logicalSrcIdx = 36;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.sfEvent
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.sfEvent_p
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_DW.sfEvent_a
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.RateTransition1_Buffer0_i
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.RateTransition_Buffer0
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_DW.temporalCounter_i1
	  section.data(3).logicalSrcIdx = 42;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking01_withElmos_DW.temporalCounter_i2
	  section.data(4).logicalSrcIdx = 43;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 206;
      section.data(206)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.EtherCATRxVar4_IWORK
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar4_IWORK_p
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar4_IWORK_n
	  section.data(3).logicalSrcIdx = 46;
	  section.data(3).dtTransOffset = 14;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar4_IWORK_k
	  section.data(4).logicalSrcIdx = 47;
	  section.data(4).dtTransOffset = 21;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar8_IWORK
	  section.data(5).logicalSrcIdx = 48;
	  section.data(5).dtTransOffset = 28;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar8_IWORK_m
	  section.data(6).logicalSrcIdx = 49;
	  section.data(6).dtTransOffset = 35;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar8_IWORK_c
	  section.data(7).logicalSrcIdx = 50;
	  section.data(7).dtTransOffset = 42;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar8_IWORK_l
	  section.data(8).logicalSrcIdx = 51;
	  section.data(8).dtTransOffset = 49;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar4_IWORK_nb
	  section.data(9).logicalSrcIdx = 52;
	  section.data(9).dtTransOffset = 56;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar4_IWORK_l
	  section.data(10).logicalSrcIdx = 53;
	  section.data(10).dtTransOffset = 63;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar_IWORK
	  section.data(11).logicalSrcIdx = 54;
	  section.data(11).dtTransOffset = 70;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar_IWORK_b
	  section.data(12).logicalSrcIdx = 55;
	  section.data(12).dtTransOffset = 77;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar_IWORK_f
	  section.data(13).logicalSrcIdx = 56;
	  section.data(13).dtTransOffset = 84;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar_IWORK_c
	  section.data(14).logicalSrcIdx = 57;
	  section.data(14).dtTransOffset = 91;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar2_IWORK
	  section.data(15).logicalSrcIdx = 58;
	  section.data(15).dtTransOffset = 98;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar2_IWORK_g
	  section.data(16).logicalSrcIdx = 59;
	  section.data(16).dtTransOffset = 105;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar18_IWORK
	  section.data(17).logicalSrcIdx = 60;
	  section.data(17).dtTransOffset = 112;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar18_IWORK_b
	  section.data(18).logicalSrcIdx = 61;
	  section.data(18).dtTransOffset = 119;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar18_IWORK_c
	  section.data(19).logicalSrcIdx = 62;
	  section.data(19).dtTransOffset = 126;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar18_IWORK_m
	  section.data(20).logicalSrcIdx = 63;
	  section.data(20).dtTransOffset = 133;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar15_IWORK
	  section.data(21).logicalSrcIdx = 64;
	  section.data(21).dtTransOffset = 140;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar15_IWORK_m
	  section.data(22).logicalSrcIdx = 65;
	  section.data(22).dtTransOffset = 147;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar17_IWORK
	  section.data(23).logicalSrcIdx = 66;
	  section.data(23).dtTransOffset = 154;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar6_IWORK
	  section.data(24).logicalSrcIdx = 67;
	  section.data(24).dtTransOffset = 161;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar1_IWORK
	  section.data(25).logicalSrcIdx = 68;
	  section.data(25).dtTransOffset = 168;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar2_IWORK_g0
	  section.data(26).logicalSrcIdx = 69;
	  section.data(26).dtTransOffset = 175;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar5_IWORK
	  section.data(27).logicalSrcIdx = 70;
	  section.data(27).dtTransOffset = 182;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar3_IWORK
	  section.data(28).logicalSrcIdx = 71;
	  section.data(28).dtTransOffset = 189;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar4_IWORK_c
	  section.data(29).logicalSrcIdx = 72;
	  section.data(29).dtTransOffset = 196;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar19_IWORK
	  section.data(30).logicalSrcIdx = 73;
	  section.data(30).dtTransOffset = 203;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar7_IWORK
	  section.data(31).logicalSrcIdx = 74;
	  section.data(31).dtTransOffset = 210;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar8_IWORK_d
	  section.data(32).logicalSrcIdx = 75;
	  section.data(32).dtTransOffset = 217;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar10_IWORK
	  section.data(33).logicalSrcIdx = 76;
	  section.data(33).dtTransOffset = 224;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar14_IWORK
	  section.data(34).logicalSrcIdx = 77;
	  section.data(34).dtTransOffset = 231;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar13_IWORK
	  section.data(35).logicalSrcIdx = 78;
	  section.data(35).dtTransOffset = 238;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar21_IWORK
	  section.data(36).logicalSrcIdx = 79;
	  section.data(36).dtTransOffset = 245;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar21_IWORK_o
	  section.data(37).logicalSrcIdx = 80;
	  section.data(37).dtTransOffset = 252;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar18_IWORK_i
	  section.data(38).logicalSrcIdx = 81;
	  section.data(38).dtTransOffset = 259;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar21_IWORK_i
	  section.data(39).logicalSrcIdx = 82;
	  section.data(39).dtTransOffset = 266;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar21_IWORK_g
	  section.data(40).logicalSrcIdx = 83;
	  section.data(40).dtTransOffset = 273;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar18_IWORK_j
	  section.data(41).logicalSrcIdx = 84;
	  section.data(41).dtTransOffset = 280;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar22_IWORK
	  section.data(42).logicalSrcIdx = 85;
	  section.data(42).dtTransOffset = 287;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar22_IWORK_h
	  section.data(43).logicalSrcIdx = 86;
	  section.data(43).dtTransOffset = 294;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar19_IWORK_i
	  section.data(44).logicalSrcIdx = 87;
	  section.data(44).dtTransOffset = 301;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar22_IWORK_d
	  section.data(45).logicalSrcIdx = 88;
	  section.data(45).dtTransOffset = 308;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar22_IWORK_o
	  section.data(46).logicalSrcIdx = 89;
	  section.data(46).dtTransOffset = 315;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar19_IWORK_m
	  section.data(47).logicalSrcIdx = 90;
	  section.data(47).dtTransOffset = 322;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar18_IWORK_e
	  section.data(48).logicalSrcIdx = 91;
	  section.data(48).dtTransOffset = 329;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar19_IWORK_k
	  section.data(49).logicalSrcIdx = 92;
	  section.data(49).dtTransOffset = 336;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar19_IWORK_h
	  section.data(50).logicalSrcIdx = 93;
	  section.data(50).dtTransOffset = 343;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar16_IWORK
	  section.data(51).logicalSrcIdx = 94;
	  section.data(51).dtTransOffset = 350;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar19_IWORK_n
	  section.data(52).logicalSrcIdx = 95;
	  section.data(52).dtTransOffset = 357;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar19_IWORK_j
	  section.data(53).logicalSrcIdx = 96;
	  section.data(53).dtTransOffset = 364;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar16_IWORK_e
	  section.data(54).logicalSrcIdx = 97;
	  section.data(54).dtTransOffset = 371;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar15_IWORK_k
	  section.data(55).logicalSrcIdx = 98;
	  section.data(55).dtTransOffset = 378;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar12_IWORK
	  section.data(56).logicalSrcIdx = 99;
	  section.data(56).dtTransOffset = 385;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar13_IWORK_e
	  section.data(57).logicalSrcIdx = 100;
	  section.data(57).dtTransOffset = 392;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar14_IWORK_i
	  section.data(58).logicalSrcIdx = 101;
	  section.data(58).dtTransOffset = 399;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar15_IWORK_e
	  section.data(59).logicalSrcIdx = 102;
	  section.data(59).dtTransOffset = 406;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar16_IWORK_d
	  section.data(60).logicalSrcIdx = 103;
	  section.data(60).dtTransOffset = 413;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar17_IWORK_j
	  section.data(61).logicalSrcIdx = 104;
	  section.data(61).dtTransOffset = 420;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar12_IWORK_p
	  section.data(62).logicalSrcIdx = 105;
	  section.data(62).dtTransOffset = 427;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar13_IWORK_d
	  section.data(63).logicalSrcIdx = 106;
	  section.data(63).dtTransOffset = 434;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar14_IWORK_n
	  section.data(64).logicalSrcIdx = 107;
	  section.data(64).dtTransOffset = 441;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar15_IWORK_l
	  section.data(65).logicalSrcIdx = 108;
	  section.data(65).dtTransOffset = 448;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar16_IWORK_a
	  section.data(66).logicalSrcIdx = 109;
	  section.data(66).dtTransOffset = 455;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar17_IWORK_m
	  section.data(67).logicalSrcIdx = 110;
	  section.data(67).dtTransOffset = 462;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar12_IWORK_c
	  section.data(68).logicalSrcIdx = 111;
	  section.data(68).dtTransOffset = 469;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar13_IWORK_k
	  section.data(69).logicalSrcIdx = 112;
	  section.data(69).dtTransOffset = 476;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar14_IWORK_b
	  section.data(70).logicalSrcIdx = 113;
	  section.data(70).dtTransOffset = 483;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar12_IWORK_a
	  section.data(71).logicalSrcIdx = 114;
	  section.data(71).dtTransOffset = 490;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar13_IWORK_eu
	  section.data(72).logicalSrcIdx = 115;
	  section.data(72).dtTransOffset = 497;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar14_IWORK_p
	  section.data(73).logicalSrcIdx = 116;
	  section.data(73).dtTransOffset = 504;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar15_IWORK_p
	  section.data(74).logicalSrcIdx = 117;
	  section.data(74).dtTransOffset = 511;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar16_IWORK_n
	  section.data(75).logicalSrcIdx = 118;
	  section.data(75).dtTransOffset = 518;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar17_IWORK_b
	  section.data(76).logicalSrcIdx = 119;
	  section.data(76).dtTransOffset = 525;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar12_IWORK_l
	  section.data(77).logicalSrcIdx = 120;
	  section.data(77).dtTransOffset = 532;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar13_IWORK_i
	  section.data(78).logicalSrcIdx = 121;
	  section.data(78).dtTransOffset = 539;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar14_IWORK_f
	  section.data(79).logicalSrcIdx = 122;
	  section.data(79).dtTransOffset = 546;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar15_IWORK_i
	  section.data(80).logicalSrcIdx = 123;
	  section.data(80).dtTransOffset = 553;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar16_IWORK_nl
	  section.data(81).logicalSrcIdx = 124;
	  section.data(81).dtTransOffset = 560;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar17_IWORK_p
	  section.data(82).logicalSrcIdx = 125;
	  section.data(82).dtTransOffset = 567;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar12_IWORK_n
	  section.data(83).logicalSrcIdx = 126;
	  section.data(83).dtTransOffset = 574;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar13_IWORK_g
	  section.data(84).logicalSrcIdx = 127;
	  section.data(84).dtTransOffset = 581;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar14_IWORK_d
	  section.data(85).logicalSrcIdx = 128;
	  section.data(85).dtTransOffset = 588;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive_IWORK
	  section.data(86).logicalSrcIdx = 129;
	  section.data(86).dtTransOffset = 595;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive_IWORK_f
	  section.data(87).logicalSrcIdx = 130;
	  section.data(87).dtTransOffset = 602;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive_IWORK_d
	  section.data(88).logicalSrcIdx = 131;
	  section.data(88).dtTransOffset = 609;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive_IWORK_o
	  section.data(89).logicalSrcIdx = 132;
	  section.data(89).dtTransOffset = 616;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive3_IWORK
	  section.data(90).logicalSrcIdx = 133;
	  section.data(90).dtTransOffset = 623;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive3_IWORK_n
	  section.data(91).logicalSrcIdx = 134;
	  section.data(91).dtTransOffset = 630;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive3_IWORK_b
	  section.data(92).logicalSrcIdx = 135;
	  section.data(92).dtTransOffset = 637;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive3_IWORK_l
	  section.data(93).logicalSrcIdx = 136;
	  section.data(93).dtTransOffset = 644;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive1_IWORK
	  section.data(94).logicalSrcIdx = 137;
	  section.data(94).dtTransOffset = 651;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive1_IWORK_f
	  section.data(95).logicalSrcIdx = 138;
	  section.data(95).dtTransOffset = 658;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive1_IWORK_m
	  section.data(96).logicalSrcIdx = 139;
	  section.data(96).dtTransOffset = 665;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive1_IWORK_l
	  section.data(97).logicalSrcIdx = 140;
	  section.data(97).dtTransOffset = 672;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive4_IWORK
	  section.data(98).logicalSrcIdx = 141;
	  section.data(98).dtTransOffset = 679;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive4_IWORK_m
	  section.data(99).logicalSrcIdx = 142;
	  section.data(99).dtTransOffset = 686;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive4_IWORK_b
	  section.data(100).logicalSrcIdx = 143;
	  section.data(100).dtTransOffset = 693;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive4_IWORK_n
	  section.data(101).logicalSrcIdx = 144;
	  section.data(101).dtTransOffset = 700;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive5_IWORK
	  section.data(102).logicalSrcIdx = 145;
	  section.data(102).dtTransOffset = 707;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive5_IWORK_b
	  section.data(103).logicalSrcIdx = 146;
	  section.data(103).dtTransOffset = 714;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive5_IWORK_c
	  section.data(104).logicalSrcIdx = 147;
	  section.data(104).dtTransOffset = 721;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive5_IWORK_j
	  section.data(105).logicalSrcIdx = 148;
	  section.data(105).dtTransOffset = 728;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar6_IWORK_l
	  section.data(106).logicalSrcIdx = 149;
	  section.data(106).dtTransOffset = 735;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar7_IWORK_m
	  section.data(107).logicalSrcIdx = 150;
	  section.data(107).dtTransOffset = 742;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar6_IWORK_p
	  section.data(108).logicalSrcIdx = 151;
	  section.data(108).dtTransOffset = 749;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar7_IWORK_n
	  section.data(109).logicalSrcIdx = 152;
	  section.data(109).dtTransOffset = 756;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar_IWORK_o
	  section.data(110).logicalSrcIdx = 153;
	  section.data(110).dtTransOffset = 763;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar6_IWORK_e
	  section.data(111).logicalSrcIdx = 154;
	  section.data(111).dtTransOffset = 770;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar7_IWORK_mw
	  section.data(112).logicalSrcIdx = 155;
	  section.data(112).dtTransOffset = 777;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar6_IWORK_j
	  section.data(113).logicalSrcIdx = 156;
	  section.data(113).dtTransOffset = 784;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar7_IWORK_a
	  section.data(114).logicalSrcIdx = 157;
	  section.data(114).dtTransOffset = 791;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar_IWORK_h
	  section.data(115).logicalSrcIdx = 158;
	  section.data(115).dtTransOffset = 798;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar10_IWORK_a
	  section.data(116).logicalSrcIdx = 159;
	  section.data(116).dtTransOffset = 805;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar10_IWORK_h
	  section.data(117).logicalSrcIdx = 160;
	  section.data(117).dtTransOffset = 812;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar6_IWORK_pu
	  section.data(118).logicalSrcIdx = 161;
	  section.data(118).dtTransOffset = 819;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar10_IWORK_c
	  section.data(119).logicalSrcIdx = 162;
	  section.data(119).dtTransOffset = 826;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar10_IWORK_n
	  section.data(120).logicalSrcIdx = 163;
	  section.data(120).dtTransOffset = 833;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar6_IWORK_n
	  section.data(121).logicalSrcIdx = 164;
	  section.data(121).dtTransOffset = 840;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar11_IWORK
	  section.data(122).logicalSrcIdx = 165;
	  section.data(122).dtTransOffset = 847;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar11_IWORK_m
	  section.data(123).logicalSrcIdx = 166;
	  section.data(123).dtTransOffset = 854;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar1_IWORK_m
	  section.data(124).logicalSrcIdx = 167;
	  section.data(124).dtTransOffset = 861;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar11_IWORK_g
	  section.data(125).logicalSrcIdx = 168;
	  section.data(125).dtTransOffset = 868;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar11_IWORK_d
	  section.data(126).logicalSrcIdx = 169;
	  section.data(126).dtTransOffset = 875;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar1_IWORK_f
	  section.data(127).logicalSrcIdx = 170;
	  section.data(127).dtTransOffset = 882;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar5_IWORK_d
	  section.data(128).logicalSrcIdx = 171;
	  section.data(128).dtTransOffset = 889;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar5_IWORK_i
	  section.data(129).logicalSrcIdx = 172;
	  section.data(129).dtTransOffset = 896;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar3_IWORK_h
	  section.data(130).logicalSrcIdx = 173;
	  section.data(130).dtTransOffset = 903;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar9_IWORK
	  section.data(131).logicalSrcIdx = 174;
	  section.data(131).dtTransOffset = 910;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar17_IWORK_i
	  section.data(132).logicalSrcIdx = 175;
	  section.data(132).dtTransOffset = 917;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar1_IWORK_n
	  section.data(133).logicalSrcIdx = 176;
	  section.data(133).dtTransOffset = 924;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar5_IWORK_p
	  section.data(134).logicalSrcIdx = 177;
	  section.data(134).dtTransOffset = 931;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar3_IWORK_hk
	  section.data(135).logicalSrcIdx = 178;
	  section.data(135).dtTransOffset = 938;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar17_IWORK_a
	  section.data(136).logicalSrcIdx = 179;
	  section.data(136).dtTransOffset = 945;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar16_IWORK_m
	  section.data(137).logicalSrcIdx = 180;
	  section.data(137).dtTransOffset = 952;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar23_IWORK
	  section.data(138).logicalSrcIdx = 181;
	  section.data(138).dtTransOffset = 959;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar2_IWORK_o
	  section.data(139).logicalSrcIdx = 182;
	  section.data(139).dtTransOffset = 966;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar3_IWORK_a
	  section.data(140).logicalSrcIdx = 183;
	  section.data(140).dtTransOffset = 973;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar23_IWORK_k
	  section.data(141).logicalSrcIdx = 184;
	  section.data(141).dtTransOffset = 980;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar20_IWORK
	  section.data(142).logicalSrcIdx = 185;
	  section.data(142).dtTransOffset = 987;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar5_IWORK_ds
	  section.data(143).logicalSrcIdx = 186;
	  section.data(143).dtTransOffset = 994;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar9_IWORK_d
	  section.data(144).logicalSrcIdx = 187;
	  section.data(144).dtTransOffset = 1001;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar1_IWORK_a
	  section.data(145).logicalSrcIdx = 188;
	  section.data(145).dtTransOffset = 1008;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar2_IWORK_a
	  section.data(146).logicalSrcIdx = 189;
	  section.data(146).dtTransOffset = 1015;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar3_IWORK_e
	  section.data(147).logicalSrcIdx = 190;
	  section.data(147).dtTransOffset = 1022;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar20_IWORK_e
	  section.data(148).logicalSrcIdx = 191;
	  section.data(148).dtTransOffset = 1029;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar23_IWORK_l
	  section.data(149).logicalSrcIdx = 192;
	  section.data(149).dtTransOffset = 1036;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar20_IWORK_c
	  section.data(150).logicalSrcIdx = 193;
	  section.data(150).dtTransOffset = 1043;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar5_IWORK_o
	  section.data(151).logicalSrcIdx = 194;
	  section.data(151).dtTransOffset = 1050;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar9_IWORK_j
	  section.data(152).logicalSrcIdx = 195;
	  section.data(152).dtTransOffset = 1057;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar1_IWORK_mc
	  section.data(153).logicalSrcIdx = 196;
	  section.data(153).dtTransOffset = 1064;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar2_IWORK_p
	  section.data(154).logicalSrcIdx = 197;
	  section.data(154).dtTransOffset = 1071;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar3_IWORK_j
	  section.data(155).logicalSrcIdx = 198;
	  section.data(155).dtTransOffset = 1078;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar23_IWORK_l4
	  section.data(156).logicalSrcIdx = 199;
	  section.data(156).dtTransOffset = 1085;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar20_IWORK_i
	  section.data(157).logicalSrcIdx = 200;
	  section.data(157).dtTransOffset = 1092;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar5_IWORK_h
	  section.data(158).logicalSrcIdx = 201;
	  section.data(158).dtTransOffset = 1099;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar9_IWORK_f
	  section.data(159).logicalSrcIdx = 202;
	  section.data(159).dtTransOffset = 1106;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar1_IWORK_ff
	  section.data(160).logicalSrcIdx = 203;
	  section.data(160).dtTransOffset = 1113;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar2_IWORK_h
	  section.data(161).logicalSrcIdx = 204;
	  section.data(161).dtTransOffset = 1120;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar3_IWORK_b
	  section.data(162).logicalSrcIdx = 205;
	  section.data(162).dtTransOffset = 1127;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar3_IWORK
	  section.data(163).logicalSrcIdx = 206;
	  section.data(163).dtTransOffset = 1134;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar4_IWORK
	  section.data(164).logicalSrcIdx = 207;
	  section.data(164).dtTransOffset = 1141;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar5_IWORK
	  section.data(165).logicalSrcIdx = 208;
	  section.data(165).dtTransOffset = 1148;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar3_IWORK_i
	  section.data(166).logicalSrcIdx = 209;
	  section.data(166).dtTransOffset = 1155;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar4_IWORK_l
	  section.data(167).logicalSrcIdx = 210;
	  section.data(167).dtTransOffset = 1162;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar5_IWORK_g
	  section.data(168).logicalSrcIdx = 211;
	  section.data(168).dtTransOffset = 1169;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar11_IWORK_c
	  section.data(169).logicalSrcIdx = 212;
	  section.data(169).dtTransOffset = 1176;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar12_IWORK_m
	  section.data(170).logicalSrcIdx = 213;
	  section.data(170).dtTransOffset = 1183;
	
	  ;% Walking01_withElmos_DW.EtherCATRxVar9_IWORK_o
	  section.data(171).logicalSrcIdx = 214;
	  section.data(171).dtTransOffset = 1190;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar_IWORK
	  section.data(172).logicalSrcIdx = 215;
	  section.data(172).dtTransOffset = 1197;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar1_IWORK
	  section.data(173).logicalSrcIdx = 216;
	  section.data(173).dtTransOffset = 1204;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar2_IWORK
	  section.data(174).logicalSrcIdx = 217;
	  section.data(174).dtTransOffset = 1211;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive2_IWORK
	  section.data(175).logicalSrcIdx = 218;
	  section.data(175).dtTransOffset = 1218;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOTransmit_IWORK
	  section.data(176).logicalSrcIdx = 219;
	  section.data(176).dtTransOffset = 1225;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOTransmit1_IWORK
	  section.data(177).logicalSrcIdx = 220;
	  section.data(177).dtTransOffset = 1232;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOTransmit2_IWORK
	  section.data(178).logicalSrcIdx = 221;
	  section.data(178).dtTransOffset = 1239;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive2_IWORK_p
	  section.data(179).logicalSrcIdx = 222;
	  section.data(179).dtTransOffset = 1246;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOTransmit_IWORK_i
	  section.data(180).logicalSrcIdx = 223;
	  section.data(180).dtTransOffset = 1253;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOTransmit1_IWORK_m
	  section.data(181).logicalSrcIdx = 224;
	  section.data(181).dtTransOffset = 1260;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOTransmit2_IWORK_l
	  section.data(182).logicalSrcIdx = 225;
	  section.data(182).dtTransOffset = 1267;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive2_IWORK_k
	  section.data(183).logicalSrcIdx = 226;
	  section.data(183).dtTransOffset = 1274;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOTransmit_IWORK_o
	  section.data(184).logicalSrcIdx = 227;
	  section.data(184).dtTransOffset = 1281;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOTransmit1_IWORK_p
	  section.data(185).logicalSrcIdx = 228;
	  section.data(185).dtTransOffset = 1288;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOTransmit2_IWORK_lo
	  section.data(186).logicalSrcIdx = 229;
	  section.data(186).dtTransOffset = 1295;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOReceive2_IWORK_f
	  section.data(187).logicalSrcIdx = 230;
	  section.data(187).dtTransOffset = 1302;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOTransmit_IWORK_l
	  section.data(188).logicalSrcIdx = 231;
	  section.data(188).dtTransOffset = 1309;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOTransmit1_IWORK_pr
	  section.data(189).logicalSrcIdx = 232;
	  section.data(189).dtTransOffset = 1316;
	
	  ;% Walking01_withElmos_DW.EtherCATPDOTransmit2_IWORK_m
	  section.data(190).logicalSrcIdx = 233;
	  section.data(190).dtTransOffset = 1323;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar3_IWORK_ix
	  section.data(191).logicalSrcIdx = 234;
	  section.data(191).dtTransOffset = 1330;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar4_IWORK_h
	  section.data(192).logicalSrcIdx = 235;
	  section.data(192).dtTransOffset = 1337;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar5_IWORK_m
	  section.data(193).logicalSrcIdx = 236;
	  section.data(193).dtTransOffset = 1344;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar3_IWORK_k
	  section.data(194).logicalSrcIdx = 237;
	  section.data(194).dtTransOffset = 1351;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar4_IWORK_d
	  section.data(195).logicalSrcIdx = 238;
	  section.data(195).dtTransOffset = 1358;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar5_IWORK_e
	  section.data(196).logicalSrcIdx = 239;
	  section.data(196).dtTransOffset = 1365;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar3_IWORK_j
	  section.data(197).logicalSrcIdx = 240;
	  section.data(197).dtTransOffset = 1372;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar4_IWORK_e
	  section.data(198).logicalSrcIdx = 241;
	  section.data(198).dtTransOffset = 1379;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar5_IWORK_er
	  section.data(199).logicalSrcIdx = 242;
	  section.data(199).dtTransOffset = 1386;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar3_IWORK_f
	  section.data(200).logicalSrcIdx = 243;
	  section.data(200).dtTransOffset = 1393;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar4_IWORK_a
	  section.data(201).logicalSrcIdx = 244;
	  section.data(201).dtTransOffset = 1400;
	
	  ;% Walking01_withElmos_DW.EtherCATTxVar5_IWORK_n
	  section.data(202).logicalSrcIdx = 245;
	  section.data(202).dtTransOffset = 1407;
	
	  ;% Walking01_withElmos_DW.BoardSetup_IWORK
	  section.data(203).logicalSrcIdx = 246;
	  section.data(203).dtTransOffset = 1414;
	
	  ;% Walking01_withElmos_DW.Setup3_IWORK
	  section.data(204).logicalSrcIdx = 247;
	  section.data(204).dtTransOffset = 1415;
	
	  ;% Walking01_withElmos_DW.ReadHWFIFO_IWORK
	  section.data(205).logicalSrcIdx = 248;
	  section.data(205).dtTransOffset = 1418;
	
	  ;% Walking01_withElmos_DW.FIFOwrite1_IWORK
	  section.data(206).logicalSrcIdx = 249;
	  section.data(206).dtTransOffset = 1419;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.Counter_Count
	  section.data(1).logicalSrcIdx = 250;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.DelayInput1_DSTATE
	  section.data(1).logicalSrcIdx = 251;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.UnitDelay_DSTATE_n
	  section.data(1).logicalSrcIdx = 252;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.DelayInput1_DSTATE_c
	  section.data(2).logicalSrcIdx = 253;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.ResetCPUOverloadCount_SubsysRan
	  section.data(1).logicalSrcIdx = 254;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.Counter_Count_o
	  section.data(1).logicalSrcIdx = 255;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.icLoad
	  section.data(2).logicalSrcIdx = 256;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_DW.is_active_c22_LibWalking
	  section.data(3).logicalSrcIdx = 257;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking01_withElmos_DW.is_Main
	  section.data(4).logicalSrcIdx = 258;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking01_withElmos_DW.is_active_Main
	  section.data(5).logicalSrcIdx = 259;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking01_withElmos_DW.is_Support
	  section.data(6).logicalSrcIdx = 260;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking01_withElmos_DW.is_active_Support
	  section.data(7).logicalSrcIdx = 261;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking01_withElmos_DW.is_Stage
	  section.data(8).logicalSrcIdx = 262;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Walking01_withElmos_DW.is_active_Stage
	  section.data(9).logicalSrcIdx = 263;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Walking01_withElmos_DW.is_ControllerMode
	  section.data(10).logicalSrcIdx = 264;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Walking01_withElmos_DW.is_active_ControllerMode
	  section.data(11).logicalSrcIdx = 265;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Walking01_withElmos_DW.is_Transition
	  section.data(12).logicalSrcIdx = 266;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Walking01_withElmos_DW.is_active_Serialize
	  section.data(13).logicalSrcIdx = 267;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Walking01_withElmos_DW.is_ControlStatus
	  section.data(14).logicalSrcIdx = 268;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Walking01_withElmos_DW.is_active_ControlStatus
	  section.data(15).logicalSrcIdx = 269;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Walking01_withElmos_DW.is_SerialState
	  section.data(16).logicalSrcIdx = 270;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Walking01_withElmos_DW.is_active_SerialState
	  section.data(17).logicalSrcIdx = 271;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Walking01_withElmos_DW.is_active_c23_Walking01_withElm
	  section.data(18).logicalSrcIdx = 272;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Walking01_withElmos_DW.is_c23_Walking01_withElmos
	  section.data(19).logicalSrcIdx = 273;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Walking01_withElmos_DW.is_Initialization
	  section.data(20).logicalSrcIdx = 274;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Walking01_withElmos_DW.is_active_c20_Walking01_withElm
	  section.data(21).logicalSrcIdx = 275;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Walking01_withElmos_DW.is_c20_Walking01_withElmos
	  section.data(22).logicalSrcIdx = 276;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Walking01_withElmos_DW.is_Initialization_h
	  section.data(23).logicalSrcIdx = 277;
	  section.data(23).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.isStable
	  section.data(1).logicalSrcIdx = 278;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.isStable_d
	  section.data(2).logicalSrcIdx = 279;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_DW.isStable_m
	  section.data(3).logicalSrcIdx = 280;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 281;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].DiscreteStateSpace_DSTATE
	  section.data(2).logicalSrcIdx = 282;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].RateTransition1_Buffer
	  section.data(3).logicalSrcIdx = 283;
	  section.data(3).dtTransOffset = 5;
	
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].RateTransition2_Buffer
	  section.data(4).logicalSrcIdx = 284;
	  section.data(4).dtTransOffset = 7;
	
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].RateTransition8_Buffer
	  section.data(5).logicalSrcIdx = 285;
	  section.data(5).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].RateTransition1_ActiveBufIdx
	  section.data(1).logicalSrcIdx = 286;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].RateTransition2_ActiveBufIdx
	  section.data(2).logicalSrcIdx = 287;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].RateTransition8_ActiveBufIdx
	  section.data(3).logicalSrcIdx = 288;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].sf_AnomalyDetection.q_last
	  section.data(1).logicalSrcIdx = 289;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].sf_AnomalyDetection.dq_last
	  section.data(2).logicalSrcIdx = 290;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].sf_AnomalyDetection.sfEvent
	  section.data(1).logicalSrcIdx = 291;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].sf_AnomalyDetection.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 292;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].sf_AnomalyDetection.is_active_c3_Walking01_withElmo
	  section.data(1).logicalSrcIdx = 293;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].sf_AnomalyDetection.is_c3_Walking01_withElmos
	  section.data(2).logicalSrcIdx = 294;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].sf_AnomalyDetection.is_Run
	  section.data(3).logicalSrcIdx = 295;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.CoreSubsys_p[2].sf_AnomalyDetection.isStable
	  section.data(1).logicalSrcIdx = 296;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.NothingControlWord_m.NothingControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 297;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.FaultReset_i.FaultReset_SubsysRanBC
	  section.data(1).logicalSrcIdx = 298;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.EnableControlWord_m.EnableControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 299;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.ShutdownControlWord_ju.ShutdownControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 300;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.sf_Chart_b.Timeout
	  section.data(1).logicalSrcIdx = 301;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.sf_Chart_b.sfEvent
	  section.data(1).logicalSrcIdx = 302;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.sf_Chart_b.is_active_c22_Walking01_withElm
	  section.data(1).logicalSrcIdx = 303;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.sf_Chart_b.is_c22_Walking01_withElmos
	  section.data(2).logicalSrcIdx = 304;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_DW.sf_Chart_b.is_Initialization
	  section.data(3).logicalSrcIdx = 305;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.sf_Chart_b.isStable
	  section.data(1).logicalSrcIdx = 306;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(28) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.NothingControlWord_k.NothingControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 307;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.FaultReset_n.FaultReset_SubsysRanBC
	  section.data(1).logicalSrcIdx = 308;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.EnableControlWord_l.EnableControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 309;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(31) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.ShutdownControlWord_j.ShutdownControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 310;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.NothingControlWord_d.NothingControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 311;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(33) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.FaultReset_c.FaultReset_SubsysRanBC
	  section.data(1).logicalSrcIdx = 312;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(34) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.EnableControlWord_c.EnableControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 313;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(35) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.ShutdownControlWord_h.ShutdownControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 314;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(36) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.sf_Chart.Timeout
	  section.data(1).logicalSrcIdx = 315;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(37) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.sf_Chart.sfEvent
	  section.data(1).logicalSrcIdx = 316;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(38) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.sf_Chart.is_active_c22_Walking01_withElm
	  section.data(1).logicalSrcIdx = 317;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.sf_Chart.is_c22_Walking01_withElmos
	  section.data(2).logicalSrcIdx = 318;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_DW.sf_Chart.is_Initialization
	  section.data(3).logicalSrcIdx = 319;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(39) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.sf_Chart.isStable
	  section.data(1).logicalSrcIdx = 320;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(40) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.NothingControlWord.NothingControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 321;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(41) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.FaultReset.FaultReset_SubsysRanBC
	  section.data(1).logicalSrcIdx = 322;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(42) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.EnableControlWord.EnableControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 323;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(43) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.ShutdownControlWord.ShutdownControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 324;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(44) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.CoreSubsys[18].UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 325;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.CoreSubsys[18].DiscreteStateSpace_DSTATE
	  section.data(2).logicalSrcIdx = 326;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(45) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.CoreSubsys[18].sf_AnomalyDetection.q_last
	  section.data(1).logicalSrcIdx = 327;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.CoreSubsys[18].sf_AnomalyDetection.dq_last
	  section.data(2).logicalSrcIdx = 328;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_DW.CoreSubsys[18].sf_AnomalyDetection.Counter_last
	  section.data(3).logicalSrcIdx = 329;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(46) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.CoreSubsys[18].sf_AnomalyDetection.sfEvent
	  section.data(1).logicalSrcIdx = 330;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(47) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.CoreSubsys[18].sf_AnomalyDetection.temporalCounter_i1
	  section.data(1).logicalSrcIdx = 331;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(48) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.CoreSubsys[18].sf_AnomalyDetection.is_active_c9_Walking01_withElmo
	  section.data(1).logicalSrcIdx = 332;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking01_withElmos_DW.CoreSubsys[18].sf_AnomalyDetection.is_c9_Walking01_withElmos
	  section.data(2).logicalSrcIdx = 333;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking01_withElmos_DW.CoreSubsys[18].sf_AnomalyDetection.is_Run
	  section.data(3).logicalSrcIdx = 334;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(49) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking01_withElmos_DW.CoreSubsys[18].sf_AnomalyDetection.isStable
	  section.data(1).logicalSrcIdx = 335;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(50) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 654870487;
  targMap.checksum1 = 1233570073;
  targMap.checksum2 = 4040884438;
  targMap.checksum3 = 4144415613;

