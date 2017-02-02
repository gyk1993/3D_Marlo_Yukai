  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
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
    ;% Auto data (Walking_ATRIAS_P)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_P.Calibration
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_P.GearOffsets
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_P.IMUTorsoOffsets
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 4;
	
	  ;% Walking_ATRIAS_P.LegHipTorqueLimit
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 6;
	
	  ;% Walking_ATRIAS_P.MedullaCommand
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 8;
	
	  ;% Walking_ATRIAS_P.TorsoCOMOffsets
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 9;
	
	  ;% Walking_ATRIAS_P.dx_err_d_gain
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 11;
	
	  ;% Walking_ATRIAS_P.dx_err_p_gain
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 12;
	
	  ;% Walking_ATRIAS_P.dx_gain
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 13;
	
	  ;% Walking_ATRIAS_P.dy_err_d_gain
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 14;
	
	  ;% Walking_ATRIAS_P.dy_err_p_gain
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 15;
	
	  ;% Walking_ATRIAS_P.dy_gain
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 16;
	
	  ;% Walking_ATRIAS_P.hAlphaSet
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 17;
	
	  ;% Walking_ATRIAS_P.hip_gain
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 377;
	
	  ;% Walking_ATRIAS_P.hip_offset
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 378;
	
	  ;% Walking_ATRIAS_P.isTrackHold
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 379;
	
	  ;% Walking_ATRIAS_P.kd_hip
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 380;
	
	  ;% Walking_ATRIAS_P.kd_st_leg
	  section.data(17).logicalSrcIdx = 17;
	  section.data(17).dtTransOffset = 381;
	
	  ;% Walking_ATRIAS_P.kd_sw_leg
	  section.data(18).logicalSrcIdx = 18;
	  section.data(18).dtTransOffset = 382;
	
	  ;% Walking_ATRIAS_P.kd_vs
	  section.data(19).logicalSrcIdx = 19;
	  section.data(19).dtTransOffset = 383;
	
	  ;% Walking_ATRIAS_P.kd_yaw
	  section.data(20).logicalSrcIdx = 20;
	  section.data(20).dtTransOffset = 384;
	
	  ;% Walking_ATRIAS_P.kp_hip
	  section.data(21).logicalSrcIdx = 21;
	  section.data(21).dtTransOffset = 385;
	
	  ;% Walking_ATRIAS_P.kp_st_leg
	  section.data(22).logicalSrcIdx = 22;
	  section.data(22).dtTransOffset = 386;
	
	  ;% Walking_ATRIAS_P.kp_sw_leg
	  section.data(23).logicalSrcIdx = 23;
	  section.data(23).dtTransOffset = 387;
	
	  ;% Walking_ATRIAS_P.kp_vs
	  section.data(24).logicalSrcIdx = 24;
	  section.data(24).dtTransOffset = 388;
	
	  ;% Walking_ATRIAS_P.kp_yaw
	  section.data(25).logicalSrcIdx = 25;
	  section.data(25).dtTransOffset = 389;
	
	  ;% Walking_ATRIAS_P.lbForce
	  section.data(26).logicalSrcIdx = 26;
	  section.data(26).dtTransOffset = 390;
	
	  ;% Walking_ATRIAS_P.ps3Axes
	  section.data(27).logicalSrcIdx = 27;
	  section.data(27).dtTransOffset = 391;
	
	  ;% Walking_ATRIAS_P.ps3Buttons
	  section.data(28).logicalSrcIdx = 28;
	  section.data(28).dtTransOffset = 397;
	
	  ;% Walking_ATRIAS_P.ps3Pov
	  section.data(29).logicalSrcIdx = 29;
	  section.data(29).dtTransOffset = 408;
	
	  ;% Walking_ATRIAS_P.step_gain
	  section.data(30).logicalSrcIdx = 30;
	  section.data(30).dtTransOffset = 409;
	
	  ;% Walking_ATRIAS_P.t0_step
	  section.data(31).logicalSrcIdx = 31;
	  section.data(31).dtTransOffset = 410;
	
	  ;% Walking_ATRIAS_P.theta_limits_norm
	  section.data(32).logicalSrcIdx = 32;
	  section.data(32).dtTransOffset = 411;
	
	  ;% Walking_ATRIAS_P.uHipGravity
	  section.data(33).logicalSrcIdx = 33;
	  section.data(33).dtTransOffset = 429;
	
	  ;% Walking_ATRIAS_P.ubForce
	  section.data(34).logicalSrcIdx = 34;
	  section.data(34).dtTransOffset = 430;
	
	  ;% Walking_ATRIAS_P.velFilConst
	  section.data(35).logicalSrcIdx = 35;
	  section.data(35).dtTransOffset = 431;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_P.isSetHipConst
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_P.isSim
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_P.isTestGravity
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking_ATRIAS_P.isTestHipTrack
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking_ATRIAS_P.isVCtracking
	  section.data(5).logicalSrcIdx = 40;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking_ATRIAS_P.isVirtualConstraint
	  section.data(6).logicalSrcIdx = 41;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
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
    nTotSects     = 12;
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
    ;% Auto data (Walking_ATRIAS_B)
    ;%
      section.nData     = 218;
      section.data(218)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_B.DataTypeConversion49
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion73
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion3
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion25
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion50
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion74
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion26
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion98
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion114
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion57
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion81
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion9
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion33
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion104
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion119
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Walking_ATRIAS_B.UnitDelay1
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Walking_ATRIAS_B.UnitDelay
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 25;
	
	  ;% Walking_ATRIAS_B.UnitDelay2
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 34;
	
	  ;% Walking_ATRIAS_B.VectorConcatenate
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 40;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion20
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 59;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion22
	  section.data(22).logicalSrcIdx = 21;
	  section.data(22).dtTransOffset = 62;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion17
	  section.data(23).logicalSrcIdx = 22;
	  section.data(23).dtTransOffset = 65;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion24
	  section.data(24).logicalSrcIdx = 23;
	  section.data(24).dtTransOffset = 66;
	
	  ;% Walking_ATRIAS_B.UnitDelay6
	  section.data(25).logicalSrcIdx = 24;
	  section.data(25).dtTransOffset = 67;
	
	  ;% Walking_ATRIAS_B.UnitDelay7
	  section.data(26).logicalSrcIdx = 25;
	  section.data(26).dtTransOffset = 76;
	
	  ;% Walking_ATRIAS_B.UnitDelay5
	  section.data(27).logicalSrcIdx = 26;
	  section.data(27).dtTransOffset = 79;
	
	  ;% Walking_ATRIAS_B.UnitDelay8
	  section.data(28).logicalSrcIdx = 27;
	  section.data(28).dtTransOffset = 82;
	
	  ;% Walking_ATRIAS_B.UnitDelay10
	  section.data(29).logicalSrcIdx = 28;
	  section.data(29).dtTransOffset = 83;
	
	  ;% Walking_ATRIAS_B.UnitDelay9
	  section.data(30).logicalSrcIdx = 29;
	  section.data(30).dtTransOffset = 92;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion7
	  section.data(31).logicalSrcIdx = 30;
	  section.data(31).dtTransOffset = 94;
	
	  ;% Walking_ATRIAS_B.Reshape3
	  section.data(32).logicalSrcIdx = 31;
	  section.data(32).dtTransOffset = 97;
	
	  ;% Walking_ATRIAS_B.Gain1
	  section.data(33).logicalSrcIdx = 32;
	  section.data(33).dtTransOffset = 106;
	
	  ;% Walking_ATRIAS_B.Gain
	  section.data(34).logicalSrcIdx = 33;
	  section.data(34).dtTransOffset = 112;
	
	  ;% Walking_ATRIAS_B.Add
	  section.data(35).logicalSrcIdx = 34;
	  section.data(35).dtTransOffset = 125;
	
	  ;% Walking_ATRIAS_B.Gain_a
	  section.data(36).logicalSrcIdx = 35;
	  section.data(36).dtTransOffset = 138;
	
	  ;% Walking_ATRIAS_B.UnitDelay_m
	  section.data(37).logicalSrcIdx = 36;
	  section.data(37).dtTransOffset = 151;
	
	  ;% Walking_ATRIAS_B.DiscreteTimeIntegrator1
	  section.data(38).logicalSrcIdx = 37;
	  section.data(38).dtTransOffset = 152;
	
	  ;% Walking_ATRIAS_B.Divide
	  section.data(39).logicalSrcIdx = 38;
	  section.data(39).dtTransOffset = 153;
	
	  ;% Walking_ATRIAS_B.Constant3
	  section.data(40).logicalSrcIdx = 39;
	  section.data(40).dtTransOffset = 154;
	
	  ;% Walking_ATRIAS_B.Constant4
	  section.data(41).logicalSrcIdx = 40;
	  section.data(41).dtTransOffset = 160;
	
	  ;% Walking_ATRIAS_B.Reshape
	  section.data(42).logicalSrcIdx = 41;
	  section.data(42).dtTransOffset = 171;
	
	  ;% Walking_ATRIAS_B.Gain2
	  section.data(43).logicalSrcIdx = 42;
	  section.data(43).dtTransOffset = 177;
	
	  ;% Walking_ATRIAS_B.Gain_e
	  section.data(44).logicalSrcIdx = 43;
	  section.data(44).dtTransOffset = 183;
	
	  ;% Walking_ATRIAS_B.Switch
	  section.data(45).logicalSrcIdx = 44;
	  section.data(45).dtTransOffset = 189;
	
	  ;% Walking_ATRIAS_B.Switch2
	  section.data(46).logicalSrcIdx = 45;
	  section.data(46).dtTransOffset = 195;
	
	  ;% Walking_ATRIAS_B.torque_sat
	  section.data(47).logicalSrcIdx = 46;
	  section.data(47).dtTransOffset = 201;
	
	  ;% Walking_ATRIAS_B.current_unsat
	  section.data(48).logicalSrcIdx = 47;
	  section.data(48).dtTransOffset = 207;
	
	  ;% Walking_ATRIAS_B.Switch_b
	  section.data(49).logicalSrcIdx = 48;
	  section.data(49).dtTransOffset = 213;
	
	  ;% Walking_ATRIAS_B.Switch2_d
	  section.data(50).logicalSrcIdx = 49;
	  section.data(50).dtTransOffset = 219;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion
	  section.data(51).logicalSrcIdx = 50;
	  section.data(51).dtTransOffset = 225;
	
	  ;% Walking_ATRIAS_B.UnitDelay2_o
	  section.data(52).logicalSrcIdx = 51;
	  section.data(52).dtTransOffset = 226;
	
	  ;% Walking_ATRIAS_B.UnitDelay1_h
	  section.data(53).logicalSrcIdx = 52;
	  section.data(53).dtTransOffset = 239;
	
	  ;% Walking_ATRIAS_B.UnitDelay_a
	  section.data(54).logicalSrcIdx = 53;
	  section.data(54).dtTransOffset = 252;
	
	  ;% Walking_ATRIAS_B.Reshape3_i
	  section.data(55).logicalSrcIdx = 54;
	  section.data(55).dtTransOffset = 253;
	
	  ;% Walking_ATRIAS_B.Reshape4
	  section.data(56).logicalSrcIdx = 55;
	  section.data(56).dtTransOffset = 259;
	
	  ;% Walking_ATRIAS_B.Reshape1
	  section.data(57).logicalSrcIdx = 56;
	  section.data(57).dtTransOffset = 265;
	
	  ;% Walking_ATRIAS_B.rad2deg
	  section.data(58).logicalSrcIdx = 57;
	  section.data(58).dtTransOffset = 281;
	
	  ;% Walking_ATRIAS_B.Add_j
	  section.data(59).logicalSrcIdx = 58;
	  section.data(59).dtTransOffset = 294;
	
	  ;% Walking_ATRIAS_B.DigitalClock
	  section.data(60).logicalSrcIdx = 59;
	  section.data(60).dtTransOffset = 298;
	
	  ;% Walking_ATRIAS_B.Gain1_o
	  section.data(61).logicalSrcIdx = 60;
	  section.data(61).dtTransOffset = 299;
	
	  ;% Walking_ATRIAS_B.Gain_d
	  section.data(62).logicalSrcIdx = 61;
	  section.data(62).dtTransOffset = 303;
	
	  ;% Walking_ATRIAS_B.Gain1_i
	  section.data(63).logicalSrcIdx = 62;
	  section.data(63).dtTransOffset = 309;
	
	  ;% Walking_ATRIAS_B.Switch_f
	  section.data(64).logicalSrcIdx = 63;
	  section.data(64).dtTransOffset = 315;
	
	  ;% Walking_ATRIAS_B.DigitalClock_e
	  section.data(65).logicalSrcIdx = 64;
	  section.data(65).dtTransOffset = 316;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion97
	  section.data(66).logicalSrcIdx = 65;
	  section.data(66).dtTransOffset = 317;
	
	  ;% Walking_ATRIAS_B.CurrentSaturation
	  section.data(67).logicalSrcIdx = 66;
	  section.data(67).dtTransOffset = 323;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion69
	  section.data(68).logicalSrcIdx = 67;
	  section.data(68).dtTransOffset = 329;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion93
	  section.data(69).logicalSrcIdx = 68;
	  section.data(69).dtTransOffset = 331;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion111
	  section.data(70).logicalSrcIdx = 69;
	  section.data(70).dtTransOffset = 333;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion21
	  section.data(71).logicalSrcIdx = 70;
	  section.data(71).dtTransOffset = 334;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion45
	  section.data(72).logicalSrcIdx = 71;
	  section.data(72).dtTransOffset = 336;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion126
	  section.data(73).logicalSrcIdx = 72;
	  section.data(73).dtTransOffset = 338;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion62
	  section.data(74).logicalSrcIdx = 73;
	  section.data(74).dtTransOffset = 339;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion86
	  section.data(75).logicalSrcIdx = 74;
	  section.data(75).dtTransOffset = 340;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion103
	  section.data(76).logicalSrcIdx = 75;
	  section.data(76).dtTransOffset = 341;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion14
	  section.data(77).logicalSrcIdx = 76;
	  section.data(77).dtTransOffset = 342;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion38
	  section.data(78).logicalSrcIdx = 77;
	  section.data(78).dtTransOffset = 343;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion118
	  section.data(79).logicalSrcIdx = 78;
	  section.data(79).dtTransOffset = 344;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion61
	  section.data(80).logicalSrcIdx = 79;
	  section.data(80).dtTransOffset = 345;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion85
	  section.data(81).logicalSrcIdx = 80;
	  section.data(81).dtTransOffset = 346;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion101
	  section.data(82).logicalSrcIdx = 81;
	  section.data(82).dtTransOffset = 347;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion13
	  section.data(83).logicalSrcIdx = 82;
	  section.data(83).dtTransOffset = 348;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion37
	  section.data(84).logicalSrcIdx = 83;
	  section.data(84).dtTransOffset = 349;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion116
	  section.data(85).logicalSrcIdx = 84;
	  section.data(85).dtTransOffset = 350;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion63
	  section.data(86).logicalSrcIdx = 85;
	  section.data(86).dtTransOffset = 351;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion87
	  section.data(87).logicalSrcIdx = 86;
	  section.data(87).dtTransOffset = 357;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion102
	  section.data(88).logicalSrcIdx = 87;
	  section.data(88).dtTransOffset = 363;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion15
	  section.data(89).logicalSrcIdx = 88;
	  section.data(89).dtTransOffset = 366;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion39
	  section.data(90).logicalSrcIdx = 89;
	  section.data(90).dtTransOffset = 372;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion117
	  section.data(91).logicalSrcIdx = 90;
	  section.data(91).dtTransOffset = 378;
	
	  ;% Walking_ATRIAS_B.Counter_o1
	  section.data(92).logicalSrcIdx = 91;
	  section.data(92).dtTransOffset = 381;
	
	  ;% Walking_ATRIAS_B.Counter_o2
	  section.data(93).logicalSrcIdx = 92;
	  section.data(93).dtTransOffset = 382;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion10
	  section.data(94).logicalSrcIdx = 93;
	  section.data(94).dtTransOffset = 383;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion105
	  section.data(95).logicalSrcIdx = 94;
	  section.data(95).dtTransOffset = 384;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion106
	  section.data(96).logicalSrcIdx = 95;
	  section.data(96).dtTransOffset = 385;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion107
	  section.data(97).logicalSrcIdx = 96;
	  section.data(97).dtTransOffset = 386;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion108
	  section.data(98).logicalSrcIdx = 97;
	  section.data(98).dtTransOffset = 387;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion109
	  section.data(99).logicalSrcIdx = 98;
	  section.data(99).dtTransOffset = 388;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion11
	  section.data(100).logicalSrcIdx = 99;
	  section.data(100).dtTransOffset = 389;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion110
	  section.data(101).logicalSrcIdx = 100;
	  section.data(101).dtTransOffset = 390;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion112
	  section.data(102).logicalSrcIdx = 101;
	  section.data(102).dtTransOffset = 391;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion12
	  section.data(103).logicalSrcIdx = 102;
	  section.data(103).dtTransOffset = 392;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion120
	  section.data(104).logicalSrcIdx = 103;
	  section.data(104).dtTransOffset = 393;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion121
	  section.data(105).logicalSrcIdx = 104;
	  section.data(105).dtTransOffset = 394;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion122
	  section.data(106).logicalSrcIdx = 105;
	  section.data(106).dtTransOffset = 395;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion123
	  section.data(107).logicalSrcIdx = 106;
	  section.data(107).dtTransOffset = 396;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion124
	  section.data(108).logicalSrcIdx = 107;
	  section.data(108).dtTransOffset = 397;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion125
	  section.data(109).logicalSrcIdx = 108;
	  section.data(109).dtTransOffset = 398;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion157
	  section.data(110).logicalSrcIdx = 109;
	  section.data(110).dtTransOffset = 399;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion16
	  section.data(111).logicalSrcIdx = 110;
	  section.data(111).dtTransOffset = 400;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion18
	  section.data(112).logicalSrcIdx = 111;
	  section.data(112).dtTransOffset = 401;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion19
	  section.data(113).logicalSrcIdx = 112;
	  section.data(113).dtTransOffset = 402;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion2
	  section.data(114).logicalSrcIdx = 113;
	  section.data(114).dtTransOffset = 403;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion23
	  section.data(115).logicalSrcIdx = 114;
	  section.data(115).dtTransOffset = 404;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion27
	  section.data(116).logicalSrcIdx = 115;
	  section.data(116).dtTransOffset = 406;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion28
	  section.data(117).logicalSrcIdx = 116;
	  section.data(117).dtTransOffset = 407;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion29
	  section.data(118).logicalSrcIdx = 117;
	  section.data(118).dtTransOffset = 408;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion30
	  section.data(119).logicalSrcIdx = 118;
	  section.data(119).dtTransOffset = 409;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion31
	  section.data(120).logicalSrcIdx = 119;
	  section.data(120).dtTransOffset = 410;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion32
	  section.data(121).logicalSrcIdx = 120;
	  section.data(121).dtTransOffset = 411;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion34
	  section.data(122).logicalSrcIdx = 121;
	  section.data(122).dtTransOffset = 412;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion35
	  section.data(123).logicalSrcIdx = 122;
	  section.data(123).dtTransOffset = 413;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion36
	  section.data(124).logicalSrcIdx = 123;
	  section.data(124).dtTransOffset = 414;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion4
	  section.data(125).logicalSrcIdx = 124;
	  section.data(125).dtTransOffset = 415;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion47
	  section.data(126).logicalSrcIdx = 125;
	  section.data(126).dtTransOffset = 416;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion5
	  section.data(127).logicalSrcIdx = 126;
	  section.data(127).dtTransOffset = 418;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion51
	  section.data(128).logicalSrcIdx = 127;
	  section.data(128).dtTransOffset = 419;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion52
	  section.data(129).logicalSrcIdx = 128;
	  section.data(129).dtTransOffset = 420;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion53
	  section.data(130).logicalSrcIdx = 129;
	  section.data(130).dtTransOffset = 421;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion54
	  section.data(131).logicalSrcIdx = 130;
	  section.data(131).dtTransOffset = 422;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion55
	  section.data(132).logicalSrcIdx = 131;
	  section.data(132).dtTransOffset = 423;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion56
	  section.data(133).logicalSrcIdx = 132;
	  section.data(133).dtTransOffset = 424;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion58
	  section.data(134).logicalSrcIdx = 133;
	  section.data(134).dtTransOffset = 425;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion59
	  section.data(135).logicalSrcIdx = 134;
	  section.data(135).dtTransOffset = 426;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion6
	  section.data(136).logicalSrcIdx = 135;
	  section.data(136).dtTransOffset = 427;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion60
	  section.data(137).logicalSrcIdx = 136;
	  section.data(137).dtTransOffset = 428;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion7_l
	  section.data(138).logicalSrcIdx = 137;
	  section.data(138).dtTransOffset = 429;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion71
	  section.data(139).logicalSrcIdx = 138;
	  section.data(139).dtTransOffset = 430;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion75
	  section.data(140).logicalSrcIdx = 139;
	  section.data(140).dtTransOffset = 432;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion76
	  section.data(141).logicalSrcIdx = 140;
	  section.data(141).dtTransOffset = 433;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion77
	  section.data(142).logicalSrcIdx = 141;
	  section.data(142).dtTransOffset = 434;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion78
	  section.data(143).logicalSrcIdx = 142;
	  section.data(143).dtTransOffset = 435;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion79
	  section.data(144).logicalSrcIdx = 143;
	  section.data(144).dtTransOffset = 436;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion8
	  section.data(145).logicalSrcIdx = 144;
	  section.data(145).dtTransOffset = 437;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion80
	  section.data(146).logicalSrcIdx = 145;
	  section.data(146).dtTransOffset = 438;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion82
	  section.data(147).logicalSrcIdx = 146;
	  section.data(147).dtTransOffset = 439;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion83
	  section.data(148).logicalSrcIdx = 147;
	  section.data(148).dtTransOffset = 440;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion84
	  section.data(149).logicalSrcIdx = 148;
	  section.data(149).dtTransOffset = 441;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion95
	  section.data(150).logicalSrcIdx = 149;
	  section.data(150).dtTransOffset = 442;
	
	  ;% Walking_ATRIAS_B.VectorConcatenate_g
	  section.data(151).logicalSrcIdx = 150;
	  section.data(151).dtTransOffset = 444;
	
	  ;% Walking_ATRIAS_B.Fcn
	  section.data(152).logicalSrcIdx = 151;
	  section.data(152).dtTransOffset = 446;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion20_f
	  section.data(153).logicalSrcIdx = 152;
	  section.data(153).dtTransOffset = 447;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion42
	  section.data(154).logicalSrcIdx = 153;
	  section.data(154).dtTransOffset = 448;
	
	  ;% Walking_ATRIAS_B.VectorConcatenate_f
	  section.data(155).logicalSrcIdx = 154;
	  section.data(155).dtTransOffset = 449;
	
	  ;% Walking_ATRIAS_B.Fcn_m
	  section.data(156).logicalSrcIdx = 155;
	  section.data(156).dtTransOffset = 451;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion20_o
	  section.data(157).logicalSrcIdx = 156;
	  section.data(157).dtTransOffset = 452;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion42_e
	  section.data(158).logicalSrcIdx = 157;
	  section.data(158).dtTransOffset = 453;
	
	  ;% Walking_ATRIAS_B.VectorConcatenate_d
	  section.data(159).logicalSrcIdx = 158;
	  section.data(159).dtTransOffset = 454;
	
	  ;% Walking_ATRIAS_B.Fcn_k
	  section.data(160).logicalSrcIdx = 159;
	  section.data(160).dtTransOffset = 456;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion20_n
	  section.data(161).logicalSrcIdx = 160;
	  section.data(161).dtTransOffset = 457;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion42_h
	  section.data(162).logicalSrcIdx = 161;
	  section.data(162).dtTransOffset = 458;
	
	  ;% Walking_ATRIAS_B.VectorConcatenate_p
	  section.data(163).logicalSrcIdx = 162;
	  section.data(163).dtTransOffset = 459;
	
	  ;% Walking_ATRIAS_B.Fcn_mq
	  section.data(164).logicalSrcIdx = 163;
	  section.data(164).dtTransOffset = 461;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion20_h
	  section.data(165).logicalSrcIdx = 164;
	  section.data(165).dtTransOffset = 462;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion42_i
	  section.data(166).logicalSrcIdx = 165;
	  section.data(166).dtTransOffset = 463;
	
	  ;% Walking_ATRIAS_B.y
	  section.data(167).logicalSrcIdx = 166;
	  section.data(167).dtTransOffset = 464;
	
	  ;% Walking_ATRIAS_B.TmpSignalConversionAtSFunctionI
	  section.data(168).logicalSrcIdx = 167;
	  section.data(168).dtTransOffset = 470;
	
	  ;% Walking_ATRIAS_B.TmpSignalConversionAtSFunctio_d
	  section.data(169).logicalSrcIdx = 168;
	  section.data(169).dtTransOffset = 480;
	
	  ;% Walking_ATRIAS_B.Rollover
	  section.data(170).logicalSrcIdx = 169;
	  section.data(170).dtTransOffset = 489;
	
	  ;% Walking_ATRIAS_B.IncCalTick
	  section.data(171).logicalSrcIdx = 170;
	  section.data(171).dtTransOffset = 498;
	
	  ;% Walking_ATRIAS_B.u_zeroed
	  section.data(172).logicalSrcIdx = 171;
	  section.data(172).dtTransOffset = 504;
	
	  ;% Walking_ATRIAS_B.VectorConcatenate_dr
	  section.data(173).logicalSrcIdx = 172;
	  section.data(173).dtTransOffset = 510;
	
	  ;% Walking_ATRIAS_B.Fcn_i
	  section.data(174).logicalSrcIdx = 173;
	  section.data(174).dtTransOffset = 512;
	
	  ;% Walking_ATRIAS_B.ControlWordIndex
	  section.data(175).logicalSrcIdx = 174;
	  section.data(175).dtTransOffset = 513;
	
	  ;% Walking_ATRIAS_B.EnableTargetTorque
	  section.data(176).logicalSrcIdx = 175;
	  section.data(176).dtTransOffset = 514;
	
	  ;% Walking_ATRIAS_B.FaultDetected
	  section.data(177).logicalSrcIdx = 176;
	  section.data(177).dtTransOffset = 515;
	
	  ;% Walking_ATRIAS_B.VectorConcatenate_n
	  section.data(178).logicalSrcIdx = 177;
	  section.data(178).dtTransOffset = 516;
	
	  ;% Walking_ATRIAS_B.Fcn_f
	  section.data(179).logicalSrcIdx = 178;
	  section.data(179).dtTransOffset = 518;
	
	  ;% Walking_ATRIAS_B.VectorConcatenate_c
	  section.data(180).logicalSrcIdx = 179;
	  section.data(180).dtTransOffset = 519;
	
	  ;% Walking_ATRIAS_B.Fcn_h
	  section.data(181).logicalSrcIdx = 180;
	  section.data(181).dtTransOffset = 521;
	
	  ;% Walking_ATRIAS_B.ControlWordIndex_m
	  section.data(182).logicalSrcIdx = 181;
	  section.data(182).dtTransOffset = 522;
	
	  ;% Walking_ATRIAS_B.EnableTargetTorque_h
	  section.data(183).logicalSrcIdx = 182;
	  section.data(183).dtTransOffset = 523;
	
	  ;% Walking_ATRIAS_B.FaultDetected_g
	  section.data(184).logicalSrcIdx = 183;
	  section.data(184).dtTransOffset = 524;
	
	  ;% Walking_ATRIAS_B.VectorConcatenate_f0
	  section.data(185).logicalSrcIdx = 184;
	  section.data(185).dtTransOffset = 525;
	
	  ;% Walking_ATRIAS_B.Fcn_c
	  section.data(186).logicalSrcIdx = 185;
	  section.data(186).dtTransOffset = 527;
	
	  ;% Walking_ATRIAS_B.TmpSignalConversionAtSFunctio_e
	  section.data(187).logicalSrcIdx = 186;
	  section.data(187).dtTransOffset = 528;
	
	  ;% Walking_ATRIAS_B.LimitSwitchesEncoded
	  section.data(188).logicalSrcIdx = 187;
	  section.data(188).dtTransOffset = 534;
	
	  ;% Walking_ATRIAS_B.TmpSignalConversionAtSFunctio_a
	  section.data(189).logicalSrcIdx = 188;
	  section.data(189).dtTransOffset = 535;
	
	  ;% Walking_ATRIAS_B.Temperatures
	  section.data(190).logicalSrcIdx = 189;
	  section.data(190).dtTransOffset = 565;
	
	  ;% Walking_ATRIAS_B.TmpSignalConversionAtSFunctio_l
	  section.data(191).logicalSrcIdx = 190;
	  section.data(191).dtTransOffset = 595;
	
	  ;% Walking_ATRIAS_B.motorVoltage
	  section.data(192).logicalSrcIdx = 191;
	  section.data(192).dtTransOffset = 601;
	
	  ;% Walking_ATRIAS_B.TmpSignalConversionAtSFunctio_o
	  section.data(193).logicalSrcIdx = 192;
	  section.data(193).dtTransOffset = 607;
	
	  ;% Walking_ATRIAS_B.logicVoltage
	  section.data(194).logicalSrcIdx = 193;
	  section.data(194).dtTransOffset = 613;
	
	  ;% Walking_ATRIAS_B.TmpSignalConversionAtSFunctio_c
	  section.data(195).logicalSrcIdx = 194;
	  section.data(195).dtTransOffset = 619;
	
	  ;% Walking_ATRIAS_B.measuredCurrent
	  section.data(196).logicalSrcIdx = 195;
	  section.data(196).dtTransOffset = 629;
	
	  ;% Walking_ATRIAS_B.Rk
	  section.data(197).logicalSrcIdx = 196;
	  section.data(197).dtTransOffset = 639;
	
	  ;% Walking_ATRIAS_B.wk
	  section.data(198).logicalSrcIdx = 197;
	  section.data(198).dtTransOffset = 648;
	
	  ;% Walking_ATRIAS_B.Ak
	  section.data(199).logicalSrcIdx = 198;
	  section.data(199).dtTransOffset = 651;
	
	  ;% Walking_ATRIAS_B.Seqk
	  section.data(200).logicalSrcIdx = 199;
	  section.data(200).dtTransOffset = 654;
	
	  ;% Walking_ATRIAS_B.ImpAsg_InsertedFor_q_clean_at_i
	  section.data(201).logicalSrcIdx = 200;
	  section.data(201).dtTransOffset = 655;
	
	  ;% Walking_ATRIAS_B.ImpAsg_InsertedFor_dq_clean_at_
	  section.data(202).logicalSrcIdx = 201;
	  section.data(202).dtTransOffset = 674;
	
	  ;% Walking_ATRIAS_B.ZYX
	  section.data(203).logicalSrcIdx = 202;
	  section.data(203).dtTransOffset = 693;
	
	  ;% Walking_ATRIAS_B.dZYX
	  section.data(204).logicalSrcIdx = 203;
	  section.data(204).dtTransOffset = 696;
	
	  ;% Walking_ATRIAS_B.Rk_g
	  section.data(205).logicalSrcIdx = 204;
	  section.data(205).dtTransOffset = 699;
	
	  ;% Walking_ATRIAS_B.R0
	  section.data(206).logicalSrcIdx = 205;
	  section.data(206).dtTransOffset = 708;
	
	  ;% Walking_ATRIAS_B.YawRollover
	  section.data(207).logicalSrcIdx = 206;
	  section.data(207).dtTransOffset = 717;
	
	  ;% Walking_ATRIAS_B.q_clean
	  section.data(208).logicalSrcIdx = 207;
	  section.data(208).dtTransOffset = 719;
	
	  ;% Walking_ATRIAS_B.dq_clean
	  section.data(209).logicalSrcIdx = 208;
	  section.data(209).dtTransOffset = 732;
	
	  ;% Walking_ATRIAS_B.MotorCurrentCommandSafe
	  section.data(210).logicalSrcIdx = 209;
	  section.data(210).dtTransOffset = 745;
	
	  ;% Walking_ATRIAS_B.MedullaCommandSafe
	  section.data(211).logicalSrcIdx = 210;
	  section.data(211).dtTransOffset = 751;
	
	  ;% Walking_ATRIAS_B.SafetyState
	  section.data(212).logicalSrcIdx = 211;
	  section.data(212).dtTransOffset = 752;
	
	  ;% Walking_ATRIAS_B.SafetyCountOut
	  section.data(213).logicalSrcIdx = 212;
	  section.data(213).dtTransOffset = 753;
	
	  ;% Walking_ATRIAS_B.q
	  section.data(214).logicalSrcIdx = 213;
	  section.data(214).dtTransOffset = 754;
	
	  ;% Walking_ATRIAS_B.Controller3_o2
	  section.data(215).logicalSrcIdx = 214;
	  section.data(215).dtTransOffset = 767;
	
	  ;% Walking_ATRIAS_B.Controller3_o3
	  section.data(216).logicalSrcIdx = 215;
	  section.data(216).dtTransOffset = 773;
	
	  ;% Walking_ATRIAS_B.Controller3_o4
	  section.data(217).logicalSrcIdx = 216;
	  section.data(217).dtTransOffset = 789;
	
	  ;% Walking_ATRIAS_B.Controller3_o5
	  section.data(218).logicalSrcIdx = 217;
	  section.data(218).dtTransOffset = 795;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_B.EtherCATRxVar6
	  section.data(1).logicalSrcIdx = 218;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar1
	  section.data(2).logicalSrcIdx = 219;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar2
	  section.data(3).logicalSrcIdx = 220;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar9
	  section.data(4).logicalSrcIdx = 221;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar11
	  section.data(5).logicalSrcIdx = 222;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar12
	  section.data(6).logicalSrcIdx = 223;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_B.EtherCATInit
	  section.data(1).logicalSrcIdx = 224;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion5_a
	  section.data(2).logicalSrcIdx = 225;
	  section.data(2).dtTransOffset = 6;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion5_d
	  section.data(3).logicalSrcIdx = 226;
	  section.data(3).dtTransOffset = 7;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive1
	  section.data(4).logicalSrcIdx = 227;
	  section.data(4).dtTransOffset = 8;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive1_d
	  section.data(5).logicalSrcIdx = 228;
	  section.data(5).dtTransOffset = 9;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive1_n
	  section.data(6).logicalSrcIdx = 229;
	  section.data(6).dtTransOffset = 10;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive1_f
	  section.data(7).logicalSrcIdx = 230;
	  section.data(7).dtTransOffset = 11;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion5_i
	  section.data(8).logicalSrcIdx = 231;
	  section.data(8).dtTransOffset = 12;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion5_p
	  section.data(9).logicalSrcIdx = 232;
	  section.data(9).dtTransOffset = 13;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion5_h
	  section.data(10).logicalSrcIdx = 233;
	  section.data(10).dtTransOffset = 14;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion5_b
	  section.data(11).logicalSrcIdx = 234;
	  section.data(11).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 10;
      section.data(10)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_B.EtherCATRxVar4
	  section.data(1).logicalSrcIdx = 235;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar4_l
	  section.data(2).logicalSrcIdx = 236;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar4_o
	  section.data(3).logicalSrcIdx = 237;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar4_h
	  section.data(4).logicalSrcIdx = 238;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar8
	  section.data(5).logicalSrcIdx = 239;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar8_b
	  section.data(6).logicalSrcIdx = 240;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar8_h
	  section.data(7).logicalSrcIdx = 241;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar8_bx
	  section.data(8).logicalSrcIdx = 242;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar4_e
	  section.data(9).logicalSrcIdx = 243;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar4_j
	  section.data(10).logicalSrcIdx = 244;
	  section.data(10).dtTransOffset = 9;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_B.EtherCATRxVar6_b
	  section.data(1).logicalSrcIdx = 245;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar7
	  section.data(2).logicalSrcIdx = 246;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar6_j
	  section.data(3).logicalSrcIdx = 247;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar7_p
	  section.data(4).logicalSrcIdx = 248;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar
	  section.data(5).logicalSrcIdx = 249;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar6_h
	  section.data(6).logicalSrcIdx = 250;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar7_g
	  section.data(7).logicalSrcIdx = 251;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar6_bg
	  section.data(8).logicalSrcIdx = 252;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar7_h
	  section.data(9).logicalSrcIdx = 253;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar_h
	  section.data(10).logicalSrcIdx = 254;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar4_d
	  section.data(11).logicalSrcIdx = 255;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive
	  section.data(12).logicalSrcIdx = 256;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Walking_ATRIAS_B.Switch_fb
	  section.data(13).logicalSrcIdx = 257;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive_d
	  section.data(14).logicalSrcIdx = 258;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Walking_ATRIAS_B.Switch_fg
	  section.data(15).logicalSrcIdx = 259;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive_p
	  section.data(16).logicalSrcIdx = 260;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Walking_ATRIAS_B.Switch_d
	  section.data(17).logicalSrcIdx = 261;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive_o
	  section.data(18).logicalSrcIdx = 262;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Walking_ATRIAS_B.Switch_i
	  section.data(19).logicalSrcIdx = 263;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion6_h
	  section.data(20).logicalSrcIdx = 264;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion6_e
	  section.data(21).logicalSrcIdx = 265;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion6_eq
	  section.data(22).logicalSrcIdx = 266;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion6_f
	  section.data(23).logicalSrcIdx = 267;
	  section.data(23).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 107;
      section.data(107)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_B.EtherCATRxVar_n
	  section.data(1).logicalSrcIdx = 268;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar_k
	  section.data(2).logicalSrcIdx = 269;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar_nk
	  section.data(3).logicalSrcIdx = 270;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar_o
	  section.data(4).logicalSrcIdx = 271;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar2_i
	  section.data(5).logicalSrcIdx = 272;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar2_p
	  section.data(6).logicalSrcIdx = 273;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar10
	  section.data(7).logicalSrcIdx = 274;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar10_i
	  section.data(8).logicalSrcIdx = 275;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar6_p
	  section.data(9).logicalSrcIdx = 276;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar10_h
	  section.data(10).logicalSrcIdx = 277;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar10_l
	  section.data(11).logicalSrcIdx = 278;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar6_n
	  section.data(12).logicalSrcIdx = 279;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar11_b
	  section.data(13).logicalSrcIdx = 280;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar11_e
	  section.data(14).logicalSrcIdx = 281;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar1_n
	  section.data(15).logicalSrcIdx = 282;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar11_k
	  section.data(16).logicalSrcIdx = 283;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar11_l
	  section.data(17).logicalSrcIdx = 284;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar1_b
	  section.data(18).logicalSrcIdx = 285;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar12_f
	  section.data(19).logicalSrcIdx = 286;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar13
	  section.data(20).logicalSrcIdx = 287;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar14
	  section.data(21).logicalSrcIdx = 288;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar15
	  section.data(22).logicalSrcIdx = 289;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar16
	  section.data(23).logicalSrcIdx = 290;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar17
	  section.data(24).logicalSrcIdx = 291;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar12_o
	  section.data(25).logicalSrcIdx = 292;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar13_b
	  section.data(26).logicalSrcIdx = 293;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar14_j
	  section.data(27).logicalSrcIdx = 294;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar15_m
	  section.data(28).logicalSrcIdx = 295;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar16_h
	  section.data(29).logicalSrcIdx = 296;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar17_b
	  section.data(30).logicalSrcIdx = 297;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar12_l
	  section.data(31).logicalSrcIdx = 298;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar13_f
	  section.data(32).logicalSrcIdx = 299;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar14_f
	  section.data(33).logicalSrcIdx = 300;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar12_og
	  section.data(34).logicalSrcIdx = 301;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar13_h
	  section.data(35).logicalSrcIdx = 302;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar14_l
	  section.data(36).logicalSrcIdx = 303;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar15_k
	  section.data(37).logicalSrcIdx = 304;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar16_b
	  section.data(38).logicalSrcIdx = 305;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar17_g
	  section.data(39).logicalSrcIdx = 306;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar12_m
	  section.data(40).logicalSrcIdx = 307;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar13_n
	  section.data(41).logicalSrcIdx = 308;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar14_b
	  section.data(42).logicalSrcIdx = 309;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar15_mh
	  section.data(43).logicalSrcIdx = 310;
	  section.data(43).dtTransOffset = 42;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar16_hz
	  section.data(44).logicalSrcIdx = 311;
	  section.data(44).dtTransOffset = 43;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar17_bq
	  section.data(45).logicalSrcIdx = 312;
	  section.data(45).dtTransOffset = 44;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar12_k
	  section.data(46).logicalSrcIdx = 313;
	  section.data(46).dtTransOffset = 45;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar13_g
	  section.data(47).logicalSrcIdx = 314;
	  section.data(47).dtTransOffset = 46;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar14_d
	  section.data(48).logicalSrcIdx = 315;
	  section.data(48).dtTransOffset = 47;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar5
	  section.data(49).logicalSrcIdx = 316;
	  section.data(49).dtTransOffset = 48;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar5_h
	  section.data(50).logicalSrcIdx = 317;
	  section.data(50).dtTransOffset = 49;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar3
	  section.data(51).logicalSrcIdx = 318;
	  section.data(51).dtTransOffset = 50;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar9_p
	  section.data(52).logicalSrcIdx = 319;
	  section.data(52).dtTransOffset = 51;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar1_c
	  section.data(53).logicalSrcIdx = 320;
	  section.data(53).dtTransOffset = 52;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar5_f
	  section.data(54).logicalSrcIdx = 321;
	  section.data(54).dtTransOffset = 53;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar3_f
	  section.data(55).logicalSrcIdx = 322;
	  section.data(55).dtTransOffset = 54;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar23
	  section.data(56).logicalSrcIdx = 323;
	  section.data(56).dtTransOffset = 55;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar2_g
	  section.data(57).logicalSrcIdx = 324;
	  section.data(57).dtTransOffset = 56;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar3_e
	  section.data(58).logicalSrcIdx = 325;
	  section.data(58).dtTransOffset = 57;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar23_d
	  section.data(59).logicalSrcIdx = 326;
	  section.data(59).dtTransOffset = 58;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar5_g
	  section.data(60).logicalSrcIdx = 327;
	  section.data(60).dtTransOffset = 59;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar9_n
	  section.data(61).logicalSrcIdx = 328;
	  section.data(61).dtTransOffset = 60;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar1_g
	  section.data(62).logicalSrcIdx = 329;
	  section.data(62).dtTransOffset = 61;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar2_iw
	  section.data(63).logicalSrcIdx = 330;
	  section.data(63).dtTransOffset = 62;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar3_k
	  section.data(64).logicalSrcIdx = 331;
	  section.data(64).dtTransOffset = 63;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar23_n
	  section.data(65).logicalSrcIdx = 332;
	  section.data(65).dtTransOffset = 64;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar5_e
	  section.data(66).logicalSrcIdx = 333;
	  section.data(66).dtTransOffset = 65;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar9_nz
	  section.data(67).logicalSrcIdx = 334;
	  section.data(67).dtTransOffset = 66;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar1_m
	  section.data(68).logicalSrcIdx = 335;
	  section.data(68).dtTransOffset = 67;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar2_f
	  section.data(69).logicalSrcIdx = 336;
	  section.data(69).dtTransOffset = 68;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar3_b
	  section.data(70).logicalSrcIdx = 337;
	  section.data(70).dtTransOffset = 69;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar23_b
	  section.data(71).logicalSrcIdx = 338;
	  section.data(71).dtTransOffset = 70;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar5_gi
	  section.data(72).logicalSrcIdx = 339;
	  section.data(72).dtTransOffset = 71;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar9_e
	  section.data(73).logicalSrcIdx = 340;
	  section.data(73).dtTransOffset = 72;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar1_o
	  section.data(74).logicalSrcIdx = 341;
	  section.data(74).dtTransOffset = 73;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar2_d
	  section.data(75).logicalSrcIdx = 342;
	  section.data(75).dtTransOffset = 74;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar3_c
	  section.data(76).logicalSrcIdx = 343;
	  section.data(76).dtTransOffset = 75;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion4_d
	  section.data(77).logicalSrcIdx = 344;
	  section.data(77).dtTransOffset = 76;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion4_l
	  section.data(78).logicalSrcIdx = 345;
	  section.data(78).dtTransOffset = 77;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion4_li
	  section.data(79).logicalSrcIdx = 346;
	  section.data(79).dtTransOffset = 78;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive5
	  section.data(80).logicalSrcIdx = 347;
	  section.data(80).dtTransOffset = 79;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator
	  section.data(81).logicalSrcIdx = 348;
	  section.data(81).dtTransOffset = 80;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_c
	  section.data(82).logicalSrcIdx = 349;
	  section.data(82).dtTransOffset = 81;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_j
	  section.data(83).logicalSrcIdx = 350;
	  section.data(83).dtTransOffset = 82;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_m
	  section.data(84).logicalSrcIdx = 351;
	  section.data(84).dtTransOffset = 83;
	
	  ;% Walking_ATRIAS_B.Merge
	  section.data(85).logicalSrcIdx = 352;
	  section.data(85).dtTransOffset = 84;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive5_d
	  section.data(86).logicalSrcIdx = 353;
	  section.data(86).dtTransOffset = 85;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_h
	  section.data(87).logicalSrcIdx = 354;
	  section.data(87).dtTransOffset = 86;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_d
	  section.data(88).logicalSrcIdx = 355;
	  section.data(88).dtTransOffset = 87;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_k
	  section.data(89).logicalSrcIdx = 356;
	  section.data(89).dtTransOffset = 88;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_he
	  section.data(90).logicalSrcIdx = 357;
	  section.data(90).dtTransOffset = 89;
	
	  ;% Walking_ATRIAS_B.Merge_b
	  section.data(91).logicalSrcIdx = 358;
	  section.data(91).dtTransOffset = 90;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive5_dm
	  section.data(92).logicalSrcIdx = 359;
	  section.data(92).dtTransOffset = 91;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_hh
	  section.data(93).logicalSrcIdx = 360;
	  section.data(93).dtTransOffset = 92;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_f
	  section.data(94).logicalSrcIdx = 361;
	  section.data(94).dtTransOffset = 93;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_cf
	  section.data(95).logicalSrcIdx = 362;
	  section.data(95).dtTransOffset = 94;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_e
	  section.data(96).logicalSrcIdx = 363;
	  section.data(96).dtTransOffset = 95;
	
	  ;% Walking_ATRIAS_B.Merge_e
	  section.data(97).logicalSrcIdx = 364;
	  section.data(97).dtTransOffset = 96;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive5_m
	  section.data(98).logicalSrcIdx = 365;
	  section.data(98).dtTransOffset = 97;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_d5
	  section.data(99).logicalSrcIdx = 366;
	  section.data(99).dtTransOffset = 98;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_g
	  section.data(100).logicalSrcIdx = 367;
	  section.data(100).dtTransOffset = 99;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_o
	  section.data(101).logicalSrcIdx = 368;
	  section.data(101).dtTransOffset = 100;
	
	  ;% Walking_ATRIAS_B.BitwiseOperator_hb
	  section.data(102).logicalSrcIdx = 369;
	  section.data(102).dtTransOffset = 101;
	
	  ;% Walking_ATRIAS_B.Merge_k
	  section.data(103).logicalSrcIdx = 370;
	  section.data(103).dtTransOffset = 102;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion4_g
	  section.data(104).logicalSrcIdx = 371;
	  section.data(104).dtTransOffset = 103;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion4_a
	  section.data(105).logicalSrcIdx = 372;
	  section.data(105).dtTransOffset = 104;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion4_di
	  section.data(106).logicalSrcIdx = 373;
	  section.data(106).dtTransOffset = 105;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion4_f
	  section.data(107).logicalSrcIdx = 374;
	  section.data(107).dtTransOffset = 106;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive2
	  section.data(1).logicalSrcIdx = 375;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive2_n
	  section.data(2).logicalSrcIdx = 376;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive2_f
	  section.data(3).logicalSrcIdx = 377;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking_ATRIAS_B.EtherCATPDOReceive3
	  section.data(4).logicalSrcIdx = 378;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(7) = section;
      clear section
      
      section.nData     = 43;
      section.data(43)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_B.EtherCATRxVar18
	  section.data(1).logicalSrcIdx = 379;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar5_hj
	  section.data(2).logicalSrcIdx = 380;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar19
	  section.data(3).logicalSrcIdx = 381;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar16_e
	  section.data(4).logicalSrcIdx = 382;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar15_d
	  section.data(5).logicalSrcIdx = 383;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar17_f
	  section.data(6).logicalSrcIdx = 384;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar18_a
	  section.data(7).logicalSrcIdx = 385;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar19_p
	  section.data(8).logicalSrcIdx = 386;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar16_l
	  section.data(9).logicalSrcIdx = 387;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar15_j
	  section.data(10).logicalSrcIdx = 388;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar17_i
	  section.data(11).logicalSrcIdx = 389;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar18_n
	  section.data(12).logicalSrcIdx = 390;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar16_e3
	  section.data(13).logicalSrcIdx = 391;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar17_n
	  section.data(14).logicalSrcIdx = 392;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar15_e
	  section.data(15).logicalSrcIdx = 393;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar21
	  section.data(16).logicalSrcIdx = 394;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar20
	  section.data(17).logicalSrcIdx = 395;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar22
	  section.data(18).logicalSrcIdx = 396;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar18_d
	  section.data(19).logicalSrcIdx = 397;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar19_p0
	  section.data(20).logicalSrcIdx = 398;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar21_f
	  section.data(21).logicalSrcIdx = 399;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar20_n
	  section.data(22).logicalSrcIdx = 400;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar21_p
	  section.data(23).logicalSrcIdx = 401;
	  section.data(23).dtTransOffset = 22;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar20_h
	  section.data(24).logicalSrcIdx = 402;
	  section.data(24).dtTransOffset = 23;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar22_l
	  section.data(25).logicalSrcIdx = 403;
	  section.data(25).dtTransOffset = 24;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar18_e
	  section.data(26).logicalSrcIdx = 404;
	  section.data(26).dtTransOffset = 25;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar19_m
	  section.data(27).logicalSrcIdx = 405;
	  section.data(27).dtTransOffset = 26;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar22_i
	  section.data(28).logicalSrcIdx = 406;
	  section.data(28).dtTransOffset = 27;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar18_b
	  section.data(29).logicalSrcIdx = 407;
	  section.data(29).dtTransOffset = 28;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar21_l
	  section.data(30).logicalSrcIdx = 408;
	  section.data(30).dtTransOffset = 29;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar20_e
	  section.data(31).logicalSrcIdx = 409;
	  section.data(31).dtTransOffset = 30;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar22_a
	  section.data(32).logicalSrcIdx = 410;
	  section.data(32).dtTransOffset = 31;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar18_o
	  section.data(33).logicalSrcIdx = 411;
	  section.data(33).dtTransOffset = 32;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar19_ma
	  section.data(34).logicalSrcIdx = 412;
	  section.data(34).dtTransOffset = 33;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar19_c
	  section.data(35).logicalSrcIdx = 413;
	  section.data(35).dtTransOffset = 34;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion3_o
	  section.data(36).logicalSrcIdx = 414;
	  section.data(36).dtTransOffset = 35;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion3_m
	  section.data(37).logicalSrcIdx = 415;
	  section.data(37).dtTransOffset = 36;
	
	  ;% Walking_ATRIAS_B.EtherCATRxVar3_g
	  section.data(38).logicalSrcIdx = 416;
	  section.data(38).dtTransOffset = 37;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion3_m4
	  section.data(39).logicalSrcIdx = 417;
	  section.data(39).dtTransOffset = 38;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion3_h
	  section.data(40).logicalSrcIdx = 418;
	  section.data(40).dtTransOffset = 39;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion3_m4p
	  section.data(41).logicalSrcIdx = 419;
	  section.data(41).dtTransOffset = 40;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion3_f
	  section.data(42).logicalSrcIdx = 420;
	  section.data(42).dtTransOffset = 41;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion3_l
	  section.data(43).logicalSrcIdx = 421;
	  section.data(43).dtTransOffset = 42;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(8) = section;
      clear section
      
      section.nData     = 30;
      section.data(30)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_B.UnitDelay_l
	  section.data(1).logicalSrcIdx = 422;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_B.LogicalOperator1
	  section.data(2).logicalSrcIdx = 423;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_B.Compare
	  section.data(3).logicalSrcIdx = 424;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking_ATRIAS_B.LowerRelop1
	  section.data(4).logicalSrcIdx = 425;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking_ATRIAS_B.UpperRelop
	  section.data(5).logicalSrcIdx = 426;
	  section.data(5).dtTransOffset = 9;
	
	  ;% Walking_ATRIAS_B.LowerRelop1_k
	  section.data(6).logicalSrcIdx = 427;
	  section.data(6).dtTransOffset = 15;
	
	  ;% Walking_ATRIAS_B.UpperRelop_j
	  section.data(7).logicalSrcIdx = 428;
	  section.data(7).dtTransOffset = 21;
	
	  ;% Walking_ATRIAS_B.DataTypeConversion_h
	  section.data(8).logicalSrcIdx = 429;
	  section.data(8).dtTransOffset = 27;
	
	  ;% Walking_ATRIAS_B.Compare_k
	  section.data(9).logicalSrcIdx = 430;
	  section.data(9).dtTransOffset = 28;
	
	  ;% Walking_ATRIAS_B.Compare_m
	  section.data(10).logicalSrcIdx = 431;
	  section.data(10).dtTransOffset = 29;
	
	  ;% Walking_ATRIAS_B.LogicalOperator
	  section.data(11).logicalSrcIdx = 432;
	  section.data(11).dtTransOffset = 30;
	
	  ;% Walking_ATRIAS_B.LogicalOperator2
	  section.data(12).logicalSrcIdx = 433;
	  section.data(12).dtTransOffset = 31;
	
	  ;% Walking_ATRIAS_B.Compare_o
	  section.data(13).logicalSrcIdx = 434;
	  section.data(13).dtTransOffset = 32;
	
	  ;% Walking_ATRIAS_B.Compare_l
	  section.data(14).logicalSrcIdx = 435;
	  section.data(14).dtTransOffset = 33;
	
	  ;% Walking_ATRIAS_B.Compare_ly
	  section.data(15).logicalSrcIdx = 436;
	  section.data(15).dtTransOffset = 34;
	
	  ;% Walking_ATRIAS_B.Compare_d
	  section.data(16).logicalSrcIdx = 437;
	  section.data(16).dtTransOffset = 35;
	
	  ;% Walking_ATRIAS_B.Compare_d0
	  section.data(17).logicalSrcIdx = 438;
	  section.data(17).dtTransOffset = 36;
	
	  ;% Walking_ATRIAS_B.Compare_p
	  section.data(18).logicalSrcIdx = 439;
	  section.data(18).dtTransOffset = 37;
	
	  ;% Walking_ATRIAS_B.Compare_om
	  section.data(19).logicalSrcIdx = 440;
	  section.data(19).dtTransOffset = 38;
	
	  ;% Walking_ATRIAS_B.Compare_n
	  section.data(20).logicalSrcIdx = 441;
	  section.data(20).dtTransOffset = 39;
	
	  ;% Walking_ATRIAS_B.Compare_e
	  section.data(21).logicalSrcIdx = 442;
	  section.data(21).dtTransOffset = 40;
	
	  ;% Walking_ATRIAS_B.Compare_lx
	  section.data(22).logicalSrcIdx = 443;
	  section.data(22).dtTransOffset = 41;
	
	  ;% Walking_ATRIAS_B.Compare_k0
	  section.data(23).logicalSrcIdx = 444;
	  section.data(23).dtTransOffset = 42;
	
	  ;% Walking_ATRIAS_B.Compare_la
	  section.data(24).logicalSrcIdx = 445;
	  section.data(24).dtTransOffset = 43;
	
	  ;% Walking_ATRIAS_B.Compare_i
	  section.data(25).logicalSrcIdx = 446;
	  section.data(25).dtTransOffset = 44;
	
	  ;% Walking_ATRIAS_B.Compare_ls
	  section.data(26).logicalSrcIdx = 447;
	  section.data(26).dtTransOffset = 45;
	
	  ;% Walking_ATRIAS_B.Compare_da
	  section.data(27).logicalSrcIdx = 448;
	  section.data(27).dtTransOffset = 46;
	
	  ;% Walking_ATRIAS_B.Compare_dh
	  section.data(28).logicalSrcIdx = 449;
	  section.data(28).dtTransOffset = 47;
	
	  ;% Walking_ATRIAS_B.ValidStates
	  section.data(29).logicalSrcIdx = 450;
	  section.data(29).dtTransOffset = 48;
	
	  ;% Walking_ATRIAS_B.Controller3_o1
	  section.data(30).logicalSrcIdx = 451;
	  section.data(30).dtTransOffset = 51;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(9) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_B.sf_Chart_mz.ControlWordIndex
	  section.data(1).logicalSrcIdx = 452;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_B.sf_Chart_mz.EnableTargetTorque
	  section.data(2).logicalSrcIdx = 453;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_B.sf_Chart_mz.FaultDetected
	  section.data(3).logicalSrcIdx = 454;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(10) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_B.sf_Chart_m.ControlWordIndex
	  section.data(1).logicalSrcIdx = 455;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_B.sf_Chart_m.EnableTargetTorque
	  section.data(2).logicalSrcIdx = 456;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_B.sf_Chart_m.FaultDetected
	  section.data(3).logicalSrcIdx = 457;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(11) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_B.CoreSubsys[18].Uk1
	  section.data(1).logicalSrcIdx = 458;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_B.CoreSubsys[18].Diff
	  section.data(2).logicalSrcIdx = 459;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_B.CoreSubsys[18].Gain1
	  section.data(3).logicalSrcIdx = 460;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking_ATRIAS_B.CoreSubsys[18].two_pole_filter
	  section.data(4).logicalSrcIdx = 461;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking_ATRIAS_B.CoreSubsys[18].UnitDelay2
	  section.data(5).logicalSrcIdx = 462;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking_ATRIAS_B.CoreSubsys[18].UnitDelay1
	  section.data(6).logicalSrcIdx = 463;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking_ATRIAS_B.CoreSubsys[18].dq_out
	  section.data(7).logicalSrcIdx = 464;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking_ATRIAS_B.CoreSubsys[18].dq_good
	  section.data(8).logicalSrcIdx = 465;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(12) = section;
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
    nTotSects     = 35;
    sectIdxOffset = 12;
    
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
    ;% Auto data (Walking_ATRIAS_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.obj
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.UnitDelay1_DSTATE
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_DW.UnitDelay_DSTATE
	  section.data(2).logicalSrcIdx = 2;
	  section.data(2).dtTransOffset = 9;
	
	  ;% Walking_ATRIAS_DW.UnitDelay2_DSTATE
	  section.data(3).logicalSrcIdx = 3;
	  section.data(3).dtTransOffset = 18;
	
	  ;% Walking_ATRIAS_DW.UnitDelay6_DSTATE
	  section.data(4).logicalSrcIdx = 4;
	  section.data(4).dtTransOffset = 24;
	
	  ;% Walking_ATRIAS_DW.UnitDelay7_DSTATE
	  section.data(5).logicalSrcIdx = 5;
	  section.data(5).dtTransOffset = 33;
	
	  ;% Walking_ATRIAS_DW.UnitDelay5_DSTATE
	  section.data(6).logicalSrcIdx = 6;
	  section.data(6).dtTransOffset = 36;
	
	  ;% Walking_ATRIAS_DW.UnitDelay8_DSTATE
	  section.data(7).logicalSrcIdx = 7;
	  section.data(7).dtTransOffset = 39;
	
	  ;% Walking_ATRIAS_DW.UnitDelay10_DSTATE
	  section.data(8).logicalSrcIdx = 8;
	  section.data(8).dtTransOffset = 40;
	
	  ;% Walking_ATRIAS_DW.UnitDelay9_DSTATE
	  section.data(9).logicalSrcIdx = 9;
	  section.data(9).dtTransOffset = 49;
	
	  ;% Walking_ATRIAS_DW.UnitDelay_DSTATE_l
	  section.data(10).logicalSrcIdx = 10;
	  section.data(10).dtTransOffset = 51;
	
	  ;% Walking_ATRIAS_DW.DiscreteTimeIntegrator1_DSTATE
	  section.data(11).logicalSrcIdx = 11;
	  section.data(11).dtTransOffset = 52;
	
	  ;% Walking_ATRIAS_DW.UnitDelay2_DSTATE_h
	  section.data(12).logicalSrcIdx = 12;
	  section.data(12).dtTransOffset = 53;
	
	  ;% Walking_ATRIAS_DW.UnitDelay1_DSTATE_j
	  section.data(13).logicalSrcIdx = 13;
	  section.data(13).dtTransOffset = 66;
	
	  ;% Walking_ATRIAS_DW.UnitDelay_DSTATE_k
	  section.data(14).logicalSrcIdx = 14;
	  section.data(14).dtTransOffset = 79;
	
	  ;% Walking_ATRIAS_DW.Timeout
	  section.data(15).logicalSrcIdx = 15;
	  section.data(15).dtTransOffset = 80;
	
	  ;% Walking_ATRIAS_DW.Timeout_b
	  section.data(16).logicalSrcIdx = 16;
	  section.data(16).dtTransOffset = 81;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 23;
      section.data(23)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.Scope1_PWORK.LoggedData
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_DW.Scope10_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_DW.Scope11_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 19;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking_ATRIAS_DW.Scope12_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 20;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking_ATRIAS_DW.Scope14_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 21;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking_ATRIAS_DW.Scope15_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 22;
	  section.data(6).dtTransOffset = 5;
	
	  ;% Walking_ATRIAS_DW.Scope16_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 23;
	  section.data(7).dtTransOffset = 6;
	
	  ;% Walking_ATRIAS_DW.Scope17_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 24;
	  section.data(8).dtTransOffset = 7;
	
	  ;% Walking_ATRIAS_DW.Scope18_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 25;
	  section.data(9).dtTransOffset = 8;
	
	  ;% Walking_ATRIAS_DW.Scope19_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 26;
	  section.data(10).dtTransOffset = 9;
	
	  ;% Walking_ATRIAS_DW.Scope2_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 27;
	  section.data(11).dtTransOffset = 10;
	
	  ;% Walking_ATRIAS_DW.Scope20_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 28;
	  section.data(12).dtTransOffset = 11;
	
	  ;% Walking_ATRIAS_DW.Scope3_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 29;
	  section.data(13).dtTransOffset = 12;
	
	  ;% Walking_ATRIAS_DW.Scope4_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 30;
	  section.data(14).dtTransOffset = 13;
	
	  ;% Walking_ATRIAS_DW.Scope5_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 31;
	  section.data(15).dtTransOffset = 14;
	
	  ;% Walking_ATRIAS_DW.Scope6_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 32;
	  section.data(16).dtTransOffset = 15;
	
	  ;% Walking_ATRIAS_DW.Scope7_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 33;
	  section.data(17).dtTransOffset = 16;
	
	  ;% Walking_ATRIAS_DW.Scope8_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 34;
	  section.data(18).dtTransOffset = 17;
	
	  ;% Walking_ATRIAS_DW.Scope9_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 35;
	  section.data(19).dtTransOffset = 18;
	
	  ;% Walking_ATRIAS_DW.ToWorkspace1_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 36;
	  section.data(20).dtTransOffset = 19;
	
	  ;% Walking_ATRIAS_DW.ToWorkspace12_PWORK.LoggedData
	  section.data(21).logicalSrcIdx = 37;
	  section.data(21).dtTransOffset = 20;
	
	  ;% Walking_ATRIAS_DW.ToWorkspace2_PWORK.LoggedData
	  section.data(22).logicalSrcIdx = 38;
	  section.data(22).dtTransOffset = 21;
	
	  ;% Walking_ATRIAS_DW.Controller3_PWORK
	  section.data(23).logicalSrcIdx = 39;
	  section.data(23).dtTransOffset = 22;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.sfEvent
	  section.data(1).logicalSrcIdx = 40;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_DW.sfEvent_l
	  section.data(2).logicalSrcIdx = 41;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 199;
      section.data(199)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.EtherCATRxVar4_IWORK
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar4_IWORK_j
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 7;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar4_IWORK_g
	  section.data(3).logicalSrcIdx = 44;
	  section.data(3).dtTransOffset = 14;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar4_IWORK_k
	  section.data(4).logicalSrcIdx = 45;
	  section.data(4).dtTransOffset = 21;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar8_IWORK
	  section.data(5).logicalSrcIdx = 46;
	  section.data(5).dtTransOffset = 28;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar8_IWORK_g
	  section.data(6).logicalSrcIdx = 47;
	  section.data(6).dtTransOffset = 35;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar8_IWORK_a
	  section.data(7).logicalSrcIdx = 48;
	  section.data(7).dtTransOffset = 42;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar8_IWORK_k
	  section.data(8).logicalSrcIdx = 49;
	  section.data(8).dtTransOffset = 49;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar4_IWORK_d
	  section.data(9).logicalSrcIdx = 50;
	  section.data(9).dtTransOffset = 56;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar4_IWORK_dc
	  section.data(10).logicalSrcIdx = 51;
	  section.data(10).dtTransOffset = 63;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar_IWORK
	  section.data(11).logicalSrcIdx = 52;
	  section.data(11).dtTransOffset = 70;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar_IWORK_o
	  section.data(12).logicalSrcIdx = 53;
	  section.data(12).dtTransOffset = 77;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar_IWORK_d
	  section.data(13).logicalSrcIdx = 54;
	  section.data(13).dtTransOffset = 84;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar_IWORK_g
	  section.data(14).logicalSrcIdx = 55;
	  section.data(14).dtTransOffset = 91;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar2_IWORK
	  section.data(15).logicalSrcIdx = 56;
	  section.data(15).dtTransOffset = 98;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar2_IWORK_g
	  section.data(16).logicalSrcIdx = 57;
	  section.data(16).dtTransOffset = 105;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar6_IWORK
	  section.data(17).logicalSrcIdx = 58;
	  section.data(17).dtTransOffset = 112;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar1_IWORK
	  section.data(18).logicalSrcIdx = 59;
	  section.data(18).dtTransOffset = 119;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar2_IWORK_a
	  section.data(19).logicalSrcIdx = 60;
	  section.data(19).dtTransOffset = 126;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar9_IWORK
	  section.data(20).logicalSrcIdx = 61;
	  section.data(20).dtTransOffset = 133;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar11_IWORK
	  section.data(21).logicalSrcIdx = 62;
	  section.data(21).dtTransOffset = 140;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar12_IWORK
	  section.data(22).logicalSrcIdx = 63;
	  section.data(22).dtTransOffset = 147;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar18_IWORK
	  section.data(23).logicalSrcIdx = 64;
	  section.data(23).dtTransOffset = 154;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar5_IWORK
	  section.data(24).logicalSrcIdx = 65;
	  section.data(24).dtTransOffset = 161;
	
	  ;% Walking_ATRIAS_DW.SFunction_IWORK.AcquireOK
	  section.data(25).logicalSrcIdx = 66;
	  section.data(25).dtTransOffset = 168;
	
	  ;% Walking_ATRIAS_DW.SFunction_IWORK_m.AcquireOK
	  section.data(26).logicalSrcIdx = 67;
	  section.data(26).dtTransOffset = 169;
	
	  ;% Walking_ATRIAS_DW.SFunction_IWORK_m1.AcquireOK
	  section.data(27).logicalSrcIdx = 68;
	  section.data(27).dtTransOffset = 170;
	
	  ;% Walking_ATRIAS_DW.SFunction_IWORK_l.AcquireOK
	  section.data(28).logicalSrcIdx = 69;
	  section.data(28).dtTransOffset = 171;
	
	  ;% Walking_ATRIAS_DW.SFunction_IWORK_k.AcquireOK
	  section.data(29).logicalSrcIdx = 70;
	  section.data(29).dtTransOffset = 172;
	
	  ;% Walking_ATRIAS_DW.SFunction_IWORK_o.AcquireOK
	  section.data(30).logicalSrcIdx = 71;
	  section.data(30).dtTransOffset = 173;
	
	  ;% Walking_ATRIAS_DW.SFunction_IWORK_b.AcquireOK
	  section.data(31).logicalSrcIdx = 72;
	  section.data(31).dtTransOffset = 174;
	
	  ;% Walking_ATRIAS_DW.SFunction_IWORK_j.AcquireOK
	  section.data(32).logicalSrcIdx = 73;
	  section.data(32).dtTransOffset = 175;
	
	  ;% Walking_ATRIAS_DW.SFunction_IWORK_n.AcquireOK
	  section.data(33).logicalSrcIdx = 74;
	  section.data(33).dtTransOffset = 176;
	
	  ;% Walking_ATRIAS_DW.SFunction_IWORK_h.AcquireOK
	  section.data(34).logicalSrcIdx = 75;
	  section.data(34).dtTransOffset = 177;
	
	  ;% Walking_ATRIAS_DW.SFunction_IWORK_c.AcquireOK
	  section.data(35).logicalSrcIdx = 76;
	  section.data(35).dtTransOffset = 178;
	
	  ;% Walking_ATRIAS_DW.SFunction_IWORK_i.AcquireOK
	  section.data(36).logicalSrcIdx = 77;
	  section.data(36).dtTransOffset = 179;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar6_IWORK_a
	  section.data(37).logicalSrcIdx = 78;
	  section.data(37).dtTransOffset = 180;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar7_IWORK
	  section.data(38).logicalSrcIdx = 79;
	  section.data(38).dtTransOffset = 187;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar6_IWORK_b
	  section.data(39).logicalSrcIdx = 80;
	  section.data(39).dtTransOffset = 194;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar7_IWORK_d
	  section.data(40).logicalSrcIdx = 81;
	  section.data(40).dtTransOffset = 201;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar_IWORK_p
	  section.data(41).logicalSrcIdx = 82;
	  section.data(41).dtTransOffset = 208;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar6_IWORK_l
	  section.data(42).logicalSrcIdx = 83;
	  section.data(42).dtTransOffset = 215;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar7_IWORK_h
	  section.data(43).logicalSrcIdx = 84;
	  section.data(43).dtTransOffset = 222;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar6_IWORK_g
	  section.data(44).logicalSrcIdx = 85;
	  section.data(44).dtTransOffset = 229;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar7_IWORK_b
	  section.data(45).logicalSrcIdx = 86;
	  section.data(45).dtTransOffset = 236;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar_IWORK_dh
	  section.data(46).logicalSrcIdx = 87;
	  section.data(46).dtTransOffset = 243;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar10_IWORK
	  section.data(47).logicalSrcIdx = 88;
	  section.data(47).dtTransOffset = 250;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar10_IWORK_f
	  section.data(48).logicalSrcIdx = 89;
	  section.data(48).dtTransOffset = 257;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar6_IWORK_bw
	  section.data(49).logicalSrcIdx = 90;
	  section.data(49).dtTransOffset = 264;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar10_IWORK_g
	  section.data(50).logicalSrcIdx = 91;
	  section.data(50).dtTransOffset = 271;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar10_IWORK_h
	  section.data(51).logicalSrcIdx = 92;
	  section.data(51).dtTransOffset = 278;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar6_IWORK_l0
	  section.data(52).logicalSrcIdx = 93;
	  section.data(52).dtTransOffset = 285;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar11_IWORK_n
	  section.data(53).logicalSrcIdx = 94;
	  section.data(53).dtTransOffset = 292;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar11_IWORK_p
	  section.data(54).logicalSrcIdx = 95;
	  section.data(54).dtTransOffset = 299;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar1_IWORK_p
	  section.data(55).logicalSrcIdx = 96;
	  section.data(55).dtTransOffset = 306;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar11_IWORK_i
	  section.data(56).logicalSrcIdx = 97;
	  section.data(56).dtTransOffset = 313;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar11_IWORK_f
	  section.data(57).logicalSrcIdx = 98;
	  section.data(57).dtTransOffset = 320;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar1_IWORK_i
	  section.data(58).logicalSrcIdx = 99;
	  section.data(58).dtTransOffset = 327;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar12_IWORK_m
	  section.data(59).logicalSrcIdx = 100;
	  section.data(59).dtTransOffset = 334;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar13_IWORK
	  section.data(60).logicalSrcIdx = 101;
	  section.data(60).dtTransOffset = 341;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar14_IWORK
	  section.data(61).logicalSrcIdx = 102;
	  section.data(61).dtTransOffset = 348;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar15_IWORK
	  section.data(62).logicalSrcIdx = 103;
	  section.data(62).dtTransOffset = 355;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar16_IWORK
	  section.data(63).logicalSrcIdx = 104;
	  section.data(63).dtTransOffset = 362;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar17_IWORK
	  section.data(64).logicalSrcIdx = 105;
	  section.data(64).dtTransOffset = 369;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar12_IWORK_f
	  section.data(65).logicalSrcIdx = 106;
	  section.data(65).dtTransOffset = 376;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar13_IWORK_e
	  section.data(66).logicalSrcIdx = 107;
	  section.data(66).dtTransOffset = 383;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar14_IWORK_c
	  section.data(67).logicalSrcIdx = 108;
	  section.data(67).dtTransOffset = 390;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar15_IWORK_i
	  section.data(68).logicalSrcIdx = 109;
	  section.data(68).dtTransOffset = 397;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar16_IWORK_e
	  section.data(69).logicalSrcIdx = 110;
	  section.data(69).dtTransOffset = 404;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar17_IWORK_e
	  section.data(70).logicalSrcIdx = 111;
	  section.data(70).dtTransOffset = 411;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar12_IWORK_j
	  section.data(71).logicalSrcIdx = 112;
	  section.data(71).dtTransOffset = 418;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar13_IWORK_h
	  section.data(72).logicalSrcIdx = 113;
	  section.data(72).dtTransOffset = 425;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar14_IWORK_cr
	  section.data(73).logicalSrcIdx = 114;
	  section.data(73).dtTransOffset = 432;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar12_IWORK_o
	  section.data(74).logicalSrcIdx = 115;
	  section.data(74).dtTransOffset = 439;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar13_IWORK_j
	  section.data(75).logicalSrcIdx = 116;
	  section.data(75).dtTransOffset = 446;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar14_IWORK_p
	  section.data(76).logicalSrcIdx = 117;
	  section.data(76).dtTransOffset = 453;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar15_IWORK_g
	  section.data(77).logicalSrcIdx = 118;
	  section.data(77).dtTransOffset = 460;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar16_IWORK_l
	  section.data(78).logicalSrcIdx = 119;
	  section.data(78).dtTransOffset = 467;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar17_IWORK_j
	  section.data(79).logicalSrcIdx = 120;
	  section.data(79).dtTransOffset = 474;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar12_IWORK_b
	  section.data(80).logicalSrcIdx = 121;
	  section.data(80).dtTransOffset = 481;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar13_IWORK_g
	  section.data(81).logicalSrcIdx = 122;
	  section.data(81).dtTransOffset = 488;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar14_IWORK_k
	  section.data(82).logicalSrcIdx = 123;
	  section.data(82).dtTransOffset = 495;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar15_IWORK_b
	  section.data(83).logicalSrcIdx = 124;
	  section.data(83).dtTransOffset = 502;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar16_IWORK_h
	  section.data(84).logicalSrcIdx = 125;
	  section.data(84).dtTransOffset = 509;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar17_IWORK_p
	  section.data(85).logicalSrcIdx = 126;
	  section.data(85).dtTransOffset = 516;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar12_IWORK_c
	  section.data(86).logicalSrcIdx = 127;
	  section.data(86).dtTransOffset = 523;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar13_IWORK_b
	  section.data(87).logicalSrcIdx = 128;
	  section.data(87).dtTransOffset = 530;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar14_IWORK_g
	  section.data(88).logicalSrcIdx = 129;
	  section.data(88).dtTransOffset = 537;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar5_IWORK_c
	  section.data(89).logicalSrcIdx = 130;
	  section.data(89).dtTransOffset = 544;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar19_IWORK
	  section.data(90).logicalSrcIdx = 131;
	  section.data(90).dtTransOffset = 551;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar16_IWORK_j
	  section.data(91).logicalSrcIdx = 132;
	  section.data(91).dtTransOffset = 558;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar15_IWORK_bk
	  section.data(92).logicalSrcIdx = 133;
	  section.data(92).dtTransOffset = 565;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar5_IWORK_p
	  section.data(93).logicalSrcIdx = 134;
	  section.data(93).dtTransOffset = 572;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar3_IWORK
	  section.data(94).logicalSrcIdx = 135;
	  section.data(94).dtTransOffset = 579;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar9_IWORK_a
	  section.data(95).logicalSrcIdx = 136;
	  section.data(95).dtTransOffset = 586;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar17_IWORK_i
	  section.data(96).logicalSrcIdx = 137;
	  section.data(96).dtTransOffset = 593;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar18_IWORK_o
	  section.data(97).logicalSrcIdx = 138;
	  section.data(97).dtTransOffset = 600;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar1_IWORK_h
	  section.data(98).logicalSrcIdx = 139;
	  section.data(98).dtTransOffset = 607;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar19_IWORK_o
	  section.data(99).logicalSrcIdx = 140;
	  section.data(99).dtTransOffset = 614;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar16_IWORK_p
	  section.data(100).logicalSrcIdx = 141;
	  section.data(100).dtTransOffset = 621;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar15_IWORK_o
	  section.data(101).logicalSrcIdx = 142;
	  section.data(101).dtTransOffset = 628;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar5_IWORK_g
	  section.data(102).logicalSrcIdx = 143;
	  section.data(102).dtTransOffset = 635;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar3_IWORK_p
	  section.data(103).logicalSrcIdx = 144;
	  section.data(103).dtTransOffset = 642;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar17_IWORK_m
	  section.data(104).logicalSrcIdx = 145;
	  section.data(104).dtTransOffset = 649;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar18_IWORK_c
	  section.data(105).logicalSrcIdx = 146;
	  section.data(105).dtTransOffset = 656;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar16_IWORK_d
	  section.data(106).logicalSrcIdx = 147;
	  section.data(106).dtTransOffset = 663;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar17_IWORK_l
	  section.data(107).logicalSrcIdx = 148;
	  section.data(107).dtTransOffset = 670;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar15_IWORK_c
	  section.data(108).logicalSrcIdx = 149;
	  section.data(108).dtTransOffset = 677;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar23_IWORK
	  section.data(109).logicalSrcIdx = 150;
	  section.data(109).dtTransOffset = 684;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar2_IWORK_k
	  section.data(110).logicalSrcIdx = 151;
	  section.data(110).dtTransOffset = 691;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar3_IWORK_i
	  section.data(111).logicalSrcIdx = 152;
	  section.data(111).dtTransOffset = 698;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar23_IWORK_f
	  section.data(112).logicalSrcIdx = 153;
	  section.data(112).dtTransOffset = 705;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar21_IWORK
	  section.data(113).logicalSrcIdx = 154;
	  section.data(113).dtTransOffset = 712;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar20_IWORK
	  section.data(114).logicalSrcIdx = 155;
	  section.data(114).dtTransOffset = 719;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar22_IWORK
	  section.data(115).logicalSrcIdx = 156;
	  section.data(115).dtTransOffset = 726;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar18_IWORK_k
	  section.data(116).logicalSrcIdx = 157;
	  section.data(116).dtTransOffset = 733;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar19_IWORK_i
	  section.data(117).logicalSrcIdx = 158;
	  section.data(117).dtTransOffset = 740;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar5_IWORK_i
	  section.data(118).logicalSrcIdx = 159;
	  section.data(118).dtTransOffset = 747;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar9_IWORK_f
	  section.data(119).logicalSrcIdx = 160;
	  section.data(119).dtTransOffset = 754;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar1_IWORK_d
	  section.data(120).logicalSrcIdx = 161;
	  section.data(120).dtTransOffset = 761;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar21_IWORK_n
	  section.data(121).logicalSrcIdx = 162;
	  section.data(121).dtTransOffset = 768;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar2_IWORK_f
	  section.data(122).logicalSrcIdx = 163;
	  section.data(122).dtTransOffset = 775;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar3_IWORK_j
	  section.data(123).logicalSrcIdx = 164;
	  section.data(123).dtTransOffset = 782;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar20_IWORK_d
	  section.data(124).logicalSrcIdx = 165;
	  section.data(124).dtTransOffset = 789;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar23_IWORK_b
	  section.data(125).logicalSrcIdx = 166;
	  section.data(125).dtTransOffset = 796;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar21_IWORK_i
	  section.data(126).logicalSrcIdx = 167;
	  section.data(126).dtTransOffset = 803;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar20_IWORK_o
	  section.data(127).logicalSrcIdx = 168;
	  section.data(127).dtTransOffset = 810;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar22_IWORK_i
	  section.data(128).logicalSrcIdx = 169;
	  section.data(128).dtTransOffset = 817;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar18_IWORK_j
	  section.data(129).logicalSrcIdx = 170;
	  section.data(129).dtTransOffset = 824;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar19_IWORK_p
	  section.data(130).logicalSrcIdx = 171;
	  section.data(130).dtTransOffset = 831;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar5_IWORK_j
	  section.data(131).logicalSrcIdx = 172;
	  section.data(131).dtTransOffset = 838;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar9_IWORK_n
	  section.data(132).logicalSrcIdx = 173;
	  section.data(132).dtTransOffset = 845;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar22_IWORK_m
	  section.data(133).logicalSrcIdx = 174;
	  section.data(133).dtTransOffset = 852;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar1_IWORK_pv
	  section.data(134).logicalSrcIdx = 175;
	  section.data(134).dtTransOffset = 859;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar18_IWORK_b
	  section.data(135).logicalSrcIdx = 176;
	  section.data(135).dtTransOffset = 866;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar2_IWORK_h
	  section.data(136).logicalSrcIdx = 177;
	  section.data(136).dtTransOffset = 873;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar3_IWORK_o
	  section.data(137).logicalSrcIdx = 178;
	  section.data(137).dtTransOffset = 880;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar23_IWORK_n
	  section.data(138).logicalSrcIdx = 179;
	  section.data(138).dtTransOffset = 887;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar21_IWORK_h
	  section.data(139).logicalSrcIdx = 180;
	  section.data(139).dtTransOffset = 894;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar20_IWORK_c
	  section.data(140).logicalSrcIdx = 181;
	  section.data(140).dtTransOffset = 901;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar22_IWORK_j
	  section.data(141).logicalSrcIdx = 182;
	  section.data(141).dtTransOffset = 908;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar18_IWORK_l
	  section.data(142).logicalSrcIdx = 183;
	  section.data(142).dtTransOffset = 915;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar19_IWORK_a
	  section.data(143).logicalSrcIdx = 184;
	  section.data(143).dtTransOffset = 922;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar19_IWORK_c
	  section.data(144).logicalSrcIdx = 185;
	  section.data(144).dtTransOffset = 929;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar5_IWORK_a
	  section.data(145).logicalSrcIdx = 186;
	  section.data(145).dtTransOffset = 936;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar9_IWORK_c
	  section.data(146).logicalSrcIdx = 187;
	  section.data(146).dtTransOffset = 943;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar1_IWORK_k
	  section.data(147).logicalSrcIdx = 188;
	  section.data(147).dtTransOffset = 950;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar2_IWORK_m
	  section.data(148).logicalSrcIdx = 189;
	  section.data(148).dtTransOffset = 957;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar3_IWORK_k
	  section.data(149).logicalSrcIdx = 190;
	  section.data(149).dtTransOffset = 964;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar3_IWORK
	  section.data(150).logicalSrcIdx = 191;
	  section.data(150).dtTransOffset = 971;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar4_IWORK
	  section.data(151).logicalSrcIdx = 192;
	  section.data(151).dtTransOffset = 978;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar5_IWORK
	  section.data(152).logicalSrcIdx = 193;
	  section.data(152).dtTransOffset = 985;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar3_IWORK_g
	  section.data(153).logicalSrcIdx = 194;
	  section.data(153).dtTransOffset = 992;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar4_IWORK_e
	  section.data(154).logicalSrcIdx = 195;
	  section.data(154).dtTransOffset = 999;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar5_IWORK_p
	  section.data(155).logicalSrcIdx = 196;
	  section.data(155).dtTransOffset = 1006;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar3_IWORK_f
	  section.data(156).logicalSrcIdx = 197;
	  section.data(156).dtTransOffset = 1013;
	
	  ;% Walking_ATRIAS_DW.EtherCATRxVar4_IWORK_l
	  section.data(157).logicalSrcIdx = 198;
	  section.data(157).dtTransOffset = 1020;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar_IWORK
	  section.data(158).logicalSrcIdx = 199;
	  section.data(158).dtTransOffset = 1027;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar1_IWORK
	  section.data(159).logicalSrcIdx = 200;
	  section.data(159).dtTransOffset = 1034;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive5_IWORK
	  section.data(160).logicalSrcIdx = 201;
	  section.data(160).dtTransOffset = 1041;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive_IWORK
	  section.data(161).logicalSrcIdx = 202;
	  section.data(161).dtTransOffset = 1048;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive1_IWORK
	  section.data(162).logicalSrcIdx = 203;
	  section.data(162).dtTransOffset = 1055;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive2_IWORK
	  section.data(163).logicalSrcIdx = 204;
	  section.data(163).dtTransOffset = 1062;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOTransmit_IWORK
	  section.data(164).logicalSrcIdx = 205;
	  section.data(164).dtTransOffset = 1069;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOTransmit1_IWORK
	  section.data(165).logicalSrcIdx = 206;
	  section.data(165).dtTransOffset = 1076;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOTransmit2_IWORK
	  section.data(166).logicalSrcIdx = 207;
	  section.data(166).dtTransOffset = 1083;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive5_IWORK_o
	  section.data(167).logicalSrcIdx = 208;
	  section.data(167).dtTransOffset = 1090;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive_IWORK_d
	  section.data(168).logicalSrcIdx = 209;
	  section.data(168).dtTransOffset = 1097;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive1_IWORK_k
	  section.data(169).logicalSrcIdx = 210;
	  section.data(169).dtTransOffset = 1104;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive2_IWORK_j
	  section.data(170).logicalSrcIdx = 211;
	  section.data(170).dtTransOffset = 1111;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOTransmit_IWORK_b
	  section.data(171).logicalSrcIdx = 212;
	  section.data(171).dtTransOffset = 1118;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOTransmit1_IWORK_c
	  section.data(172).logicalSrcIdx = 213;
	  section.data(172).dtTransOffset = 1125;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOTransmit2_IWORK_h
	  section.data(173).logicalSrcIdx = 214;
	  section.data(173).dtTransOffset = 1132;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive5_IWORK_p
	  section.data(174).logicalSrcIdx = 215;
	  section.data(174).dtTransOffset = 1139;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive_IWORK_i
	  section.data(175).logicalSrcIdx = 216;
	  section.data(175).dtTransOffset = 1146;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive1_IWORK_d
	  section.data(176).logicalSrcIdx = 217;
	  section.data(176).dtTransOffset = 1153;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive2_IWORK_h
	  section.data(177).logicalSrcIdx = 218;
	  section.data(177).dtTransOffset = 1160;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOTransmit_IWORK_g
	  section.data(178).logicalSrcIdx = 219;
	  section.data(178).dtTransOffset = 1167;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOTransmit1_IWORK_g
	  section.data(179).logicalSrcIdx = 220;
	  section.data(179).dtTransOffset = 1174;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOTransmit2_IWORK_hi
	  section.data(180).logicalSrcIdx = 221;
	  section.data(180).dtTransOffset = 1181;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive5_IWORK_m
	  section.data(181).logicalSrcIdx = 222;
	  section.data(181).dtTransOffset = 1188;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive_IWORK_m
	  section.data(182).logicalSrcIdx = 223;
	  section.data(182).dtTransOffset = 1195;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive1_IWORK_p
	  section.data(183).logicalSrcIdx = 224;
	  section.data(183).dtTransOffset = 1202;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOReceive3_IWORK
	  section.data(184).logicalSrcIdx = 225;
	  section.data(184).dtTransOffset = 1209;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOTransmit_IWORK_l
	  section.data(185).logicalSrcIdx = 226;
	  section.data(185).dtTransOffset = 1216;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOTransmit1_IWORK_ci
	  section.data(186).logicalSrcIdx = 227;
	  section.data(186).dtTransOffset = 1223;
	
	  ;% Walking_ATRIAS_DW.EtherCATPDOTransmit2_IWORK_o
	  section.data(187).logicalSrcIdx = 228;
	  section.data(187).dtTransOffset = 1230;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar3_IWORK_o
	  section.data(188).logicalSrcIdx = 229;
	  section.data(188).dtTransOffset = 1237;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar4_IWORK_a
	  section.data(189).logicalSrcIdx = 230;
	  section.data(189).dtTransOffset = 1244;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar5_IWORK_k
	  section.data(190).logicalSrcIdx = 231;
	  section.data(190).dtTransOffset = 1251;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar3_IWORK_i
	  section.data(191).logicalSrcIdx = 232;
	  section.data(191).dtTransOffset = 1258;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar4_IWORK_p
	  section.data(192).logicalSrcIdx = 233;
	  section.data(192).dtTransOffset = 1265;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar5_IWORK_a
	  section.data(193).logicalSrcIdx = 234;
	  section.data(193).dtTransOffset = 1272;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar3_IWORK_a
	  section.data(194).logicalSrcIdx = 235;
	  section.data(194).dtTransOffset = 1279;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar4_IWORK_f
	  section.data(195).logicalSrcIdx = 236;
	  section.data(195).dtTransOffset = 1286;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar5_IWORK_kq
	  section.data(196).logicalSrcIdx = 237;
	  section.data(196).dtTransOffset = 1293;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar3_IWORK_e
	  section.data(197).logicalSrcIdx = 238;
	  section.data(197).dtTransOffset = 1300;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar4_IWORK_d
	  section.data(198).logicalSrcIdx = 239;
	  section.data(198).dtTransOffset = 1307;
	
	  ;% Walking_ATRIAS_DW.EtherCATTxVar5_IWORK_a3
	  section.data(199).logicalSrcIdx = 240;
	  section.data(199).dtTransOffset = 1314;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.Counter_Count
	  section.data(1).logicalSrcIdx = 241;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.UnitDelay_DSTATE_b
	  section.data(1).logicalSrcIdx = 242;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.DiscreteTimeIntegrator1_PrevRes
	  section.data(1).logicalSrcIdx = 243;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.is_active_c45_Walking_ATRIAS
	  section.data(1).logicalSrcIdx = 244;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_DW.is_c45_Walking_ATRIAS
	  section.data(2).logicalSrcIdx = 245;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_DW.is_Initialization
	  section.data(3).logicalSrcIdx = 246;
	  section.data(3).dtTransOffset = 2;
	
	  ;% Walking_ATRIAS_DW.is_active_c43_Walking_ATRIAS
	  section.data(4).logicalSrcIdx = 247;
	  section.data(4).dtTransOffset = 3;
	
	  ;% Walking_ATRIAS_DW.is_c43_Walking_ATRIAS
	  section.data(5).logicalSrcIdx = 248;
	  section.data(5).dtTransOffset = 4;
	
	  ;% Walking_ATRIAS_DW.is_Initialization_a
	  section.data(6).logicalSrcIdx = 249;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.isStable
	  section.data(1).logicalSrcIdx = 250;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_DW.isStable_i
	  section.data(2).logicalSrcIdx = 251;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_DW.objisempty
	  section.data(3).logicalSrcIdx = 252;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.NothingControlWord_jg.NothingControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 253;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.FaultReset_l.FaultReset_SubsysRanBC
	  section.data(1).logicalSrcIdx = 254;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.EnableControlWord_n.EnableControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 255;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.ShutdownControlWord_l.ShutdownControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 256;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.sf_Chart_mz.Timeout
	  section.data(1).logicalSrcIdx = 257;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.sf_Chart_mz.sfEvent
	  section.data(1).logicalSrcIdx = 258;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(16) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.sf_Chart_mz.is_active_c44_Walking_ATRIAS
	  section.data(1).logicalSrcIdx = 259;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_DW.sf_Chart_mz.is_c44_Walking_ATRIAS
	  section.data(2).logicalSrcIdx = 260;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_DW.sf_Chart_mz.is_Initialization
	  section.data(3).logicalSrcIdx = 261;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(17) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.sf_Chart_mz.isStable
	  section.data(1).logicalSrcIdx = 262;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(18) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.NothingControlWord_j.NothingControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 263;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(19) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.FaultReset_k.FaultReset_SubsysRanBC
	  section.data(1).logicalSrcIdx = 264;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(20) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.EnableControlWord_k.EnableControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 265;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(21) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.ShutdownControlWord_b.ShutdownControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 266;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(22) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.NothingControlWord_n.NothingControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 267;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(23) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.FaultReset_a.FaultReset_SubsysRanBC
	  section.data(1).logicalSrcIdx = 268;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(24) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.EnableControlWord_h.EnableControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 269;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(25) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.ShutdownControlWord_p.ShutdownControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 270;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(26) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.sf_Chart_m.Timeout
	  section.data(1).logicalSrcIdx = 271;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(27) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.sf_Chart_m.sfEvent
	  section.data(1).logicalSrcIdx = 272;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(28) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.sf_Chart_m.is_active_c44_Walking_ATRIAS
	  section.data(1).logicalSrcIdx = 273;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_DW.sf_Chart_m.is_c44_Walking_ATRIAS
	  section.data(2).logicalSrcIdx = 274;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_DW.sf_Chart_m.is_Initialization
	  section.data(3).logicalSrcIdx = 275;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(29) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.sf_Chart_m.isStable
	  section.data(1).logicalSrcIdx = 276;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(30) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.NothingControlWord.NothingControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 277;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(31) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.FaultReset.FaultReset_SubsysRanBC
	  section.data(1).logicalSrcIdx = 278;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(32) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.EnableControlWord.EnableControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 279;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(33) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.ShutdownControlWord.ShutdownControlWord_SubsysRanBC
	  section.data(1).logicalSrcIdx = 280;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(34) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% Walking_ATRIAS_DW.CoreSubsys[18].UD_DSTATE
	  section.data(1).logicalSrcIdx = 281;
	  section.data(1).dtTransOffset = 0;
	
	  ;% Walking_ATRIAS_DW.CoreSubsys[18].two_pole_filter_states
	  section.data(2).logicalSrcIdx = 282;
	  section.data(2).dtTransOffset = 1;
	
	  ;% Walking_ATRIAS_DW.CoreSubsys[18].UnitDelay2_DSTATE
	  section.data(3).logicalSrcIdx = 283;
	  section.data(3).dtTransOffset = 3;
	
	  ;% Walking_ATRIAS_DW.CoreSubsys[18].UnitDelay1_DSTATE
	  section.data(4).logicalSrcIdx = 284;
	  section.data(4).dtTransOffset = 4;
	
	  ;% Walking_ATRIAS_DW.CoreSubsys[18].two_pole_filter_tmp
	  section.data(5).logicalSrcIdx = 285;
	  section.data(5).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(35) = section;
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


  targMap.checksum0 = 2385601952;
  targMap.checksum1 = 804019991;
  targMap.checksum2 = 783034396;
  targMap.checksum3 = 4003235734;

