function pt=Walking01_withElmospt
pt = [];
pt(1).blockname = '';
pt(1).paramname = 'AllowDoubleSupport';
pt(1).class     = 'scalar';
pt(1).nrows     = 1;
pt(1).ncols     = 1;
pt(1).subsource = 'SS_DOUBLE';
pt(1).ndims     = '2';
pt(1).size      = '[]';
pt(getlenPT) = pt(1);

pt(2).blockname = '';
pt(2).paramname = 'CommandSerialize';
pt(2).class     = 'scalar';
pt(2).nrows     = 1;
pt(2).ncols     = 1;
pt(2).subsource = 'SS_DOUBLE';
pt(2).ndims     = '2';
pt(2).size      = '[]';

pt(3).blockname = '';
pt(3).paramname = 'ControllerModeInit';
pt(3).class     = 'scalar';
pt(3).nrows     = 1;
pt(3).ncols     = 1;
pt(3).subsource = 'SS_DOUBLE';
pt(3).ndims     = '2';
pt(3).size      = '[]';

pt(4).blockname = '';
pt(4).paramname = 'DecouplingMode';
pt(4).class     = 'scalar';
pt(4).nrows     = 1;
pt(4).ncols     = 1;
pt(4).subsource = 'SS_DOUBLE';
pt(4).ndims     = '2';
pt(4).size      = '[]';

pt(5).blockname = '';
pt(5).paramname = 'DesiredYawOffset';
pt(5).class     = 'scalar';
pt(5).nrows     = 1;
pt(5).ncols     = 1;
pt(5).subsource = 'SS_DOUBLE';
pt(5).ndims     = '2';
pt(5).size      = '[]';

pt(6).blockname = '';
pt(6).paramname = 'EnableFeedforwardOnStep';
pt(6).class     = 'scalar';
pt(6).nrows     = 1;
pt(6).ncols     = 1;
pt(6).subsource = 'SS_DOUBLE';
pt(6).ndims     = '2';
pt(6).size      = '[]';

pt(7).blockname = '';
pt(7).paramname = 'EnableTransition';
pt(7).class     = 'scalar';
pt(7).nrows     = 1;
pt(7).ncols     = 1;
pt(7).subsource = 'SS_DOUBLE';
pt(7).ndims     = '2';
pt(7).size      = '[]';

pt(8).blockname = '';
pt(8).paramname = 'EnableVelocityBasedUpdate';
pt(8).class     = 'scalar';
pt(8).nrows     = 1;
pt(8).ncols     = 1;
pt(8).subsource = 'SS_DOUBLE';
pt(8).ndims     = '2';
pt(8).size      = '[]';

pt(9).blockname = '';
pt(9).paramname = 'ErrorVelZeroFactor';
pt(9).class     = 'vector';
pt(9).nrows     = 6;
pt(9).ncols     = 1;
pt(9).subsource = 'SS_DOUBLE';
pt(9).ndims     = '2';
pt(9).size      = '[]';

pt(10).blockname = '';
pt(10).paramname = 'ErrorZeroFactor';
pt(10).class     = 'vector';
pt(10).nrows     = 6;
pt(10).ncols     = 1;
pt(10).subsource = 'SS_DOUBLE';
pt(10).ndims     = '2';
pt(10).size      = '[]';

pt(11).blockname = '';
pt(11).paramname = 'FeedforwardGain';
pt(11).class     = 'vector';
pt(11).nrows     = 6;
pt(11).ncols     = 1;
pt(11).subsource = 'SS_DOUBLE';
pt(11).ndims     = '2';
pt(11).size      = '[]';

pt(12).blockname = '';
pt(12).paramname = 'GearOffsets';
pt(12).class     = 'vector';
pt(12).nrows     = 4;
pt(12).ncols     = 1;
pt(12).subsource = 'SS_DOUBLE';
pt(12).ndims     = '2';
pt(12).size      = '[]';

pt(13).blockname = '';
pt(13).paramname = 'H0Transition';
pt(13).class     = 'col-mat';
pt(13).nrows     = 6;
pt(13).ncols     = 13;
pt(13).subsource = 'SS_DOUBLE';
pt(13).ndims     = '2';
pt(13).size      = '[]';

pt(14).blockname = '';
pt(14).paramname = 'H0WalkingDouble';
pt(14).class     = 'col-mat';
pt(14).nrows     = 6;
pt(14).ncols     = 13;
pt(14).subsource = 'SS_DOUBLE';
pt(14).ndims     = '2';
pt(14).size      = '[]';

pt(15).blockname = '';
pt(15).paramname = 'H0WalkingSingle';
pt(15).class     = 'col-mat';
pt(15).nrows     = 6;
pt(15).ncols     = 13;
pt(15).subsource = 'SS_DOUBLE';
pt(15).ndims     = '2';
pt(15).size      = '[]';

pt(16).blockname = '';
pt(16).paramname = 'HAlphaStarInjection';
pt(16).class     = 'col-mat';
pt(16).nrows     = 6;
pt(16).ncols     = 6;
pt(16).subsource = 'SS_DOUBLE';
pt(16).ndims     = '2';
pt(16).size      = '[]';

pt(17).blockname = '';
pt(17).paramname = 'HAlphaStarPosing';
pt(17).class     = 'col-mat';
pt(17).nrows     = 6;
pt(17).ncols     = 6;
pt(17).subsource = 'SS_DOUBLE';
pt(17).ndims     = '2';
pt(17).size      = '[]';

pt(18).blockname = '';
pt(18).paramname = 'HAlphaStarTransition';
pt(18).class     = 'col-mat';
pt(18).nrows     = 6;
pt(18).ncols     = 6;
pt(18).subsource = 'SS_DOUBLE';
pt(18).ndims     = '2';
pt(18).size      = '[]';

pt(19).blockname = '';
pt(19).paramname = 'HAlphaStarWalkingDouble';
pt(19).class     = 'col-mat';
pt(19).nrows     = 6;
pt(19).ncols     = 6;
pt(19).subsource = 'SS_DOUBLE';
pt(19).ndims     = '2';
pt(19).size      = '[]';

pt(20).blockname = '';
pt(20).paramname = 'HAlphaStarWalkingSingle';
pt(20).class     = 'col-mat';
pt(20).nrows     = 6;
pt(20).ncols     = 6;
pt(20).subsource = 'SS_DOUBLE';
pt(20).ndims     = '2';
pt(20).size      = '[]';

pt(21).blockname = '';
pt(21).paramname = 'HAlphaTransition';
pt(21).class     = 'col-mat';
pt(21).nrows     = 6;
pt(21).ncols     = 6;
pt(21).subsource = 'SS_DOUBLE';
pt(21).ndims     = '2';
pt(21).size      = '[]';

pt(22).blockname = '';
pt(22).paramname = 'HAlphaWalkingDouble';
pt(22).class     = 'col-mat';
pt(22).nrows     = 6;
pt(22).ncols     = 6;
pt(22).subsource = 'SS_DOUBLE';
pt(22).ndims     = '2';
pt(22).size      = '[]';

pt(23).blockname = '';
pt(23).paramname = 'HAlphaWalkingSingle';
pt(23).class     = 'col-mat';
pt(23).nrows     = 6;
pt(23).ncols     = 6;
pt(23).subsource = 'SS_DOUBLE';
pt(23).ndims     = '2';
pt(23).size      = '[]';

pt(24).blockname = '';
pt(24).paramname = 'HBarAlphaTransition';
pt(24).class     = 'col-mat';
pt(24).nrows     = 6;
pt(24).ncols     = 5;
pt(24).subsource = 'SS_DOUBLE';
pt(24).ndims     = '2';
pt(24).size      = '[]';

pt(25).blockname = '';
pt(25).paramname = 'HBarAlphaWalkingDouble';
pt(25).class     = 'col-mat';
pt(25).nrows     = 6;
pt(25).ncols     = 5;
pt(25).subsource = 'SS_DOUBLE';
pt(25).ndims     = '2';
pt(25).size      = '[]';

pt(26).blockname = '';
pt(26).paramname = 'HBarAlphaWalkingSingle';
pt(26).class     = 'col-mat';
pt(26).nrows     = 6;
pt(26).ncols     = 5;
pt(26).subsource = 'SS_DOUBLE';
pt(26).ndims     = '2';
pt(26).size      = '[]';

pt(27).blockname = '';
pt(27).paramname = 'HBarLimitsTransition';
pt(27).class     = 'col-mat';
pt(27).nrows     = 6;
pt(27).ncols     = 2;
pt(27).subsource = 'SS_DOUBLE';
pt(27).ndims     = '2';
pt(27).size      = '[]';

pt(28).blockname = '';
pt(28).paramname = 'HBarLimitsWalkingDouble';
pt(28).class     = 'col-mat';
pt(28).nrows     = 6;
pt(28).ncols     = 2;
pt(28).subsource = 'SS_DOUBLE';
pt(28).ndims     = '2';
pt(28).size      = '[]';

pt(29).blockname = '';
pt(29).paramname = 'HBarLimitsWalkingSingle';
pt(29).class     = 'col-mat';
pt(29).nrows     = 6;
pt(29).ncols     = 2;
pt(29).subsource = 'SS_DOUBLE';
pt(29).ndims     = '2';
pt(29).size      = '[]';

pt(30).blockname = '';
pt(30).paramname = 'IMUCommand';
pt(30).class     = 'scalar';
pt(30).nrows     = 1;
pt(30).ncols     = 1;
pt(30).subsource = 'SS_DOUBLE';
pt(30).ndims     = '2';
pt(30).size      = '[]';

pt(31).blockname = '';
pt(31).paramname = 'IMUThreshold';
pt(31).class     = 'scalar';
pt(31).nrows     = 1;
pt(31).ncols     = 1;
pt(31).subsource = 'SS_DOUBLE';
pt(31).ndims     = '2';
pt(31).size      = '[]';

pt(32).blockname = '';
pt(32).paramname = 'IMUTorsoOffsets';
pt(32).class     = 'vector';
pt(32).nrows     = 2;
pt(32).ncols     = 1;
pt(32).subsource = 'SS_DOUBLE';
pt(32).ndims     = '2';
pt(32).size      = '[]';

pt(33).blockname = '';
pt(33).paramname = 'K1MidStanceUpdate';
pt(33).class     = 'vector';
pt(33).nrows     = 6;
pt(33).ncols     = 1;
pt(33).subsource = 'SS_DOUBLE';
pt(33).ndims     = '2';
pt(33).size      = '[]';

pt(34).blockname = '';
pt(34).paramname = 'K2MidStanceUpdate';
pt(34).class     = 'vector';
pt(34).nrows     = 6;
pt(34).ncols     = 1;
pt(34).subsource = 'SS_DOUBLE';
pt(34).ndims     = '2';
pt(34).size      = '[]';

pt(35).blockname = '';
pt(35).paramname = 'KASaturationEarly';
pt(35).class     = 'scalar';
pt(35).nrows     = 1;
pt(35).ncols     = 1;
pt(35).subsource = 'SS_DOUBLE';
pt(35).ndims     = '2';
pt(35).size      = '[]';

pt(36).blockname = '';
pt(36).paramname = 'KASaturationMax';
pt(36).class     = 'scalar';
pt(36).nrows     = 1;
pt(36).ncols     = 1;
pt(36).subsource = 'SS_DOUBLE';
pt(36).ndims     = '2';
pt(36).size      = '[]';

pt(37).blockname = '';
pt(37).paramname = 'KASaturationS1';
pt(37).class     = 'scalar';
pt(37).nrows     = 1;
pt(37).ncols     = 1;
pt(37).subsource = 'SS_DOUBLE';
pt(37).ndims     = '2';
pt(37).size      = '[]';

pt(38).blockname = '';
pt(38).paramname = 'KASaturationS2';
pt(38).class     = 'scalar';
pt(38).nrows     = 1;
pt(38).ncols     = 1;
pt(38).subsource = 'SS_DOUBLE';
pt(38).ndims     = '2';
pt(38).size      = '[]';

pt(39).blockname = '';
pt(39).paramname = 'KASpringOffsets';
pt(39).class     = 'vector';
pt(39).nrows     = 2;
pt(39).ncols     = 1;
pt(39).subsource = 'SS_DOUBLE';
pt(39).ndims     = '2';
pt(39).size      = '[]';

pt(40).blockname = '';
pt(40).paramname = 'KThetaMinus';
pt(40).class     = 'scalar';
pt(40).nrows     = 1;
pt(40).ncols     = 1;
pt(40).subsource = 'SS_DOUBLE';
pt(40).ndims     = '2';
pt(40).size      = '[]';

pt(41).blockname = '';
pt(41).paramname = 'KThetaPlus';
pt(41).class     = 'scalar';
pt(41).nrows     = 1;
pt(41).ncols     = 1;
pt(41).subsource = 'SS_DOUBLE';
pt(41).ndims     = '2';
pt(41).size      = '[]';

pt(42).blockname = '';
pt(42).paramname = 'LegHipTorqueLimit';
pt(42).class     = 'vector';
pt(42).nrows     = 2;
pt(42).ncols     = 1;
pt(42).subsource = 'SS_DOUBLE';
pt(42).ndims     = '2';
pt(42).size      = '[]';

pt(43).blockname = '';
pt(43).paramname = 'ManualSwap';
pt(43).class     = 'scalar';
pt(43).nrows     = 1;
pt(43).ncols     = 1;
pt(43).subsource = 'SS_DOUBLE';
pt(43).ndims     = '2';
pt(43).size      = '[]';

pt(44).blockname = '';
pt(44).paramname = 'MaxError';
pt(44).class     = 'scalar';
pt(44).nrows     = 1;
pt(44).ncols     = 1;
pt(44).subsource = 'SS_DOUBLE';
pt(44).ndims     = '2';
pt(44).size      = '[]';

pt(45).blockname = '';
pt(45).paramname = 'MaxErrorVel';
pt(45).class     = 'scalar';
pt(45).nrows     = 1;
pt(45).ncols     = 1;
pt(45).subsource = 'SS_DOUBLE';
pt(45).ndims     = '2';
pt(45).size      = '[]';

pt(46).blockname = '';
pt(46).paramname = 'MedullaCommand';
pt(46).class     = 'scalar';
pt(46).nrows     = 1;
pt(46).ncols     = 1;
pt(46).subsource = 'SS_DOUBLE';
pt(46).ndims     = '2';
pt(46).size      = '[]';

pt(47).blockname = '';
pt(47).paramname = 'MinDeltaTheta';
pt(47).class     = 'scalar';
pt(47).nrows     = 1;
pt(47).ncols     = 1;
pt(47).subsource = 'SS_DOUBLE';
pt(47).ndims     = '2';
pt(47).size      = '[]';

pt(48).blockname = '';
pt(48).paramname = 'MinDeltaThetaTransition';
pt(48).class     = 'scalar';
pt(48).nrows     = 1;
pt(48).ncols     = 1;
pt(48).subsource = 'SS_DOUBLE';
pt(48).ndims     = '2';
pt(48).size      = '[]';

pt(49).blockname = '';
pt(49).paramname = 'PhiOffset';
pt(49).class     = 'scalar';
pt(49).nrows     = 1;
pt(49).ncols     = 1;
pt(49).subsource = 'SS_DOUBLE';
pt(49).ndims     = '2';
pt(49).size      = '[]';

pt(50).blockname = '';
pt(50).paramname = 'RLimits';
pt(50).class     = 'vector';
pt(50).nrows     = 1;
pt(50).ncols     = 2;
pt(50).subsource = 'SS_DOUBLE';
pt(50).ndims     = '2';
pt(50).size      = '[]';

pt(51).blockname = '';
pt(51).paramname = 'ResetControl';
pt(51).class     = 'scalar';
pt(51).nrows     = 1;
pt(51).ncols     = 1;
pt(51).subsource = 'SS_DOUBLE';
pt(51).ndims     = '2';
pt(51).size      = '[]';

pt(52).blockname = '';
pt(52).paramname = 'RollPhaseVelocityThresh';
pt(52).class     = 'scalar';
pt(52).nrows     = 1;
pt(52).ncols     = 1;
pt(52).subsource = 'SS_DOUBLE';
pt(52).ndims     = '2';
pt(52).size      = '[]';

pt(53).blockname = '';
pt(53).paramname = 'RunMode';
pt(53).class     = 'scalar';
pt(53).nrows     = 1;
pt(53).ncols     = 1;
pt(53).subsource = 'SS_DOUBLE';
pt(53).ndims     = '2';
pt(53).size      = '[]';

pt(54).blockname = '';
pt(54).paramname = 'SelectFeedforward';
pt(54).class     = 'scalar';
pt(54).nrows     = 1;
pt(54).ncols     = 1;
pt(54).subsource = 'SS_DOUBLE';
pt(54).ndims     = '2';
pt(54).size      = '[]';

pt(55).blockname = '';
pt(55).paramname = 'StanceLegInit';
pt(55).class     = 'scalar';
pt(55).nrows     = 1;
pt(55).ncols     = 1;
pt(55).subsource = 'SS_DOUBLE';
pt(55).ndims     = '2';
pt(55).size      = '[]';

pt(56).blockname = '';
pt(56).paramname = 'StartSecondGaitOnStep';
pt(56).class     = 'scalar';
pt(56).nrows     = 1;
pt(56).ncols     = 1;
pt(56).subsource = 'SS_DOUBLE';
pt(56).ndims     = '2';
pt(56).size      = '[]';

pt(57).blockname = '';
pt(57).paramname = 'TMaxUpdate';
pt(57).class     = 'scalar';
pt(57).nrows     = 1;
pt(57).ncols     = 1;
pt(57).subsource = 'SS_DOUBLE';
pt(57).ndims     = '2';
pt(57).size      = '[]';

pt(58).blockname = '';
pt(58).paramname = 'TPosing';
pt(58).class     = 'scalar';
pt(58).nrows     = 1;
pt(58).ncols     = 1;
pt(58).subsource = 'SS_DOUBLE';
pt(58).ndims     = '2';
pt(58).size      = '[]';

pt(59).blockname = '';
pt(59).paramname = 'Theta0';
pt(59).class     = 'scalar';
pt(59).nrows     = 1;
pt(59).ncols     = 1;
pt(59).subsource = 'SS_DOUBLE';
pt(59).ndims     = '2';
pt(59).size      = '[]';

pt(60).blockname = '';
pt(60).paramname = 'ThetaLimitsTransition';
pt(60).class     = 'vector';
pt(60).nrows     = 1;
pt(60).ncols     = 2;
pt(60).subsource = 'SS_DOUBLE';
pt(60).ndims     = '2';
pt(60).size      = '[]';

pt(61).blockname = '';
pt(61).paramname = 'ThetaLimitsWalkingDouble';
pt(61).class     = 'vector';
pt(61).nrows     = 1;
pt(61).ncols     = 2;
pt(61).subsource = 'SS_DOUBLE';
pt(61).ndims     = '2';
pt(61).size      = '[]';

pt(62).blockname = '';
pt(62).paramname = 'ThetaLimitsWalkingSingle';
pt(62).class     = 'vector';
pt(62).nrows     = 1;
pt(62).ncols     = 2;
pt(62).subsource = 'SS_DOUBLE';
pt(62).ndims     = '2';
pt(62).size      = '[]';

pt(63).blockname = '';
pt(63).paramname = 'TorsoBackAngle';
pt(63).class     = 'scalar';
pt(63).nrows     = 1;
pt(63).ncols     = 1;
pt(63).subsource = 'SS_DOUBLE';
pt(63).ndims     = '2';
pt(63).size      = '[]';

pt(64).blockname = '';
pt(64).paramname = 'TorsoBackOnStep';
pt(64).class     = 'scalar';
pt(64).nrows     = 1;
pt(64).ncols     = 1;
pt(64).subsource = 'SS_DOUBLE';
pt(64).ndims     = '2';
pt(64).size      = '[]';

pt(65).blockname = '';
pt(65).paramname = 'TorsoCOMOffsets';
pt(65).class     = 'vector';
pt(65).nrows     = 2;
pt(65).ncols     = 1;
pt(65).subsource = 'SS_DOUBLE';
pt(65).ndims     = '2';
pt(65).size      = '[]';

pt(66).blockname = '';
pt(66).paramname = 'UseKASaturation';
pt(66).class     = 'scalar';
pt(66).nrows     = 1;
pt(66).ncols     = 1;
pt(66).subsource = 'SS_DOUBLE';
pt(66).ndims     = '2';
pt(66).size      = '[]';

pt(67).blockname = '';
pt(67).paramname = 'UsePosingControl';
pt(67).class     = 'scalar';
pt(67).nrows     = 1;
pt(67).ncols     = 1;
pt(67).subsource = 'SS_DOUBLE';
pt(67).ndims     = '2';
pt(67).size      = '[]';

pt(68).blockname = '';
pt(68).paramname = 'VelocityBasedUpdateDTheta0';
pt(68).class     = 'scalar';
pt(68).nrows     = 1;
pt(68).ncols     = 1;
pt(68).subsource = 'SS_DOUBLE';
pt(68).ndims     = '2';
pt(68).size      = '[]';

pt(69).blockname = '';
pt(69).paramname = 'VelocityBasedUpdateK1';
pt(69).class     = 'vector';
pt(69).nrows     = 6;
pt(69).ncols     = 1;
pt(69).subsource = 'SS_DOUBLE';
pt(69).ndims     = '2';
pt(69).size      = '[]';

pt(70).blockname = '';
pt(70).paramname = 'VelocityBasedUpdateK2';
pt(70).class     = 'vector';
pt(70).nrows     = 6;
pt(70).ncols     = 1;
pt(70).subsource = 'SS_DOUBLE';
pt(70).ndims     = '2';
pt(70).size      = '[]';

pt(71).blockname = '';
pt(71).paramname = 'VelocityBasedUpdateLimits';
pt(71).class     = 'col-mat';
pt(71).nrows     = 6;
pt(71).ncols     = 2;
pt(71).subsource = 'SS_DOUBLE';
pt(71).ndims     = '2';
pt(71).size      = '[]';

pt(72).blockname = '';
pt(72).paramname = 'VelocityControlTorsoGain';
pt(72).class     = 'scalar';
pt(72).nrows     = 1;
pt(72).ncols     = 1;
pt(72).subsource = 'SS_DOUBLE';
pt(72).ndims     = '2';
pt(72).size      = '[]';

pt(73).blockname = '';
pt(73).paramname = 'VelocityControlTorsoMax';
pt(73).class     = 'scalar';
pt(73).nrows     = 1;
pt(73).ncols     = 1;
pt(73).subsource = 'SS_DOUBLE';
pt(73).ndims     = '2';
pt(73).size      = '[]';

pt(74).blockname = '';
pt(74).paramname = 'VelocityControlTorsoMin';
pt(74).class     = 'scalar';
pt(74).nrows     = 1;
pt(74).ncols     = 1;
pt(74).subsource = 'SS_DOUBLE';
pt(74).ndims     = '2';
pt(74).size      = '[]';

pt(75).blockname = '';
pt(75).paramname = 'VelocityControlTorsoV0';
pt(75).class     = 'scalar';
pt(75).nrows     = 1;
pt(75).ncols     = 1;
pt(75).subsource = 'SS_DOUBLE';
pt(75).ndims     = '2';
pt(75).size      = '[]';

pt(76).blockname = '';
pt(76).paramname = 'YawLimit';
pt(76).class     = 'scalar';
pt(76).nrows     = 1;
pt(76).ncols     = 1;
pt(76).subsource = 'SS_DOUBLE';
pt(76).ndims     = '2';
pt(76).size      = '[]';

pt(77).blockname = '';
pt(77).paramname = 'epsilon';
pt(77).class     = 'vector';
pt(77).nrows     = 2;
pt(77).ncols     = 1;
pt(77).subsource = 'SS_DOUBLE';
pt(77).ndims     = '2';
pt(77).size      = '[]';

pt(78).blockname = '';
pt(78).paramname = 'ff_params';
pt(78).class     = 'vector';
pt(78).nrows     = 5;
pt(78).ncols     = 1;
pt(78).subsource = 'SS_DOUBLE';
pt(78).ndims     = '2';
pt(78).size      = '[]';

pt(79).blockname = '';
pt(79).paramname = 'hd_posing';
pt(79).class     = 'vector';
pt(79).nrows     = 6;
pt(79).ncols     = 1;
pt(79).subsource = 'SS_DOUBLE';
pt(79).ndims     = '2';
pt(79).size      = '[]';

pt(80).blockname = '';
pt(80).paramname = 'k_precomp';
pt(80).class     = 'scalar';
pt(80).nrows     = 1;
pt(80).ncols     = 1;
pt(80).subsource = 'SS_DOUBLE';
pt(80).ndims     = '2';
pt(80).size      = '[]';

pt(81).blockname = '';
pt(81).paramname = 'kd';
pt(81).class     = 'vector';
pt(81).nrows     = 6;
pt(81).ncols     = 1;
pt(81).subsource = 'SS_DOUBLE';
pt(81).ndims     = '2';
pt(81).size      = '[]';

pt(82).blockname = '';
pt(82).paramname = 'kd_2dof';
pt(82).class     = 'scalar';
pt(82).nrows     = 1;
pt(82).ncols     = 1;
pt(82).subsource = 'SS_DOUBLE';
pt(82).ndims     = '2';
pt(82).size      = '[]';

pt(83).blockname = '';
pt(83).paramname = 'kd_torso';
pt(83).class     = 'vector';
pt(83).nrows     = 2;
pt(83).ncols     = 1;
pt(83).subsource = 'SS_DOUBLE';
pt(83).ndims     = '2';
pt(83).size      = '[]';

pt(84).blockname = '';
pt(84).paramname = 'kp';
pt(84).class     = 'vector';
pt(84).nrows     = 6;
pt(84).ncols     = 1;
pt(84).subsource = 'SS_DOUBLE';
pt(84).ndims     = '2';
pt(84).size      = '[]';

pt(85).blockname = '';
pt(85).paramname = 'kp_2dof';
pt(85).class     = 'scalar';
pt(85).nrows     = 1;
pt(85).ncols     = 1;
pt(85).subsource = 'SS_DOUBLE';
pt(85).ndims     = '2';
pt(85).size      = '[]';

pt(86).blockname = '';
pt(86).paramname = 'lat_bias';
pt(86).class     = 'scalar';
pt(86).nrows     = 1;
pt(86).ncols     = 1;
pt(86).subsource = 'SS_DOUBLE';
pt(86).ndims     = '2';
pt(86).size      = '[]';

pt(87).blockname = '';
pt(87).paramname = 'lat_bias2';
pt(87).class     = 'scalar';
pt(87).nrows     = 1;
pt(87).ncols     = 1;
pt(87).subsource = 'SS_DOUBLE';
pt(87).ndims     = '2';
pt(87).size      = '[]';

pt(88).blockname = '';
pt(88).paramname = 'lateralParams';
pt(88).class     = 'vector';
pt(88).nrows     = 5;
pt(88).ncols     = 1;
pt(88).subsource = 'SS_DOUBLE';
pt(88).ndims     = '2';
pt(88).size      = '[]';

pt(89).blockname = '';
pt(89).paramname = 'linkFeedback';
pt(89).class     = 'scalar';
pt(89).nrows     = 1;
pt(89).ncols     = 1;
pt(89).subsource = 'SS_DOUBLE';
pt(89).ndims     = '2';
pt(89).size      = '[]';

pt(90).blockname = '';
pt(90).paramname = 'optimal_sat_weights';
pt(90).class     = 'vector';
pt(90).nrows     = 2;
pt(90).ncols     = 1;
pt(90).subsource = 'SS_DOUBLE';
pt(90).ndims     = '2';
pt(90).size      = '[]';

pt(91).blockname = '';
pt(91).paramname = 'step_params';
pt(91).class     = 'vector';
pt(91).nrows     = 5;
pt(91).ncols     = 1;
pt(91).subsource = 'SS_DOUBLE';
pt(91).ndims     = '2';
pt(91).size      = '[]';

pt(92).blockname = '';
pt(92).paramname = 'swap_params';
pt(92).class     = 'vector';
pt(92).nrows     = 7;
pt(92).ncols     = 1;
pt(92).subsource = 'SS_DOUBLE';
pt(92).ndims     = '2';
pt(92).size      = '[]';

pt(93).blockname = '';
pt(93).paramname = 'tStepInitial';
pt(93).class     = 'scalar';
pt(93).nrows     = 1;
pt(93).ncols     = 1;
pt(93).subsource = 'SS_DOUBLE';
pt(93).ndims     = '2';
pt(93).size      = '[]';

pt(94).blockname = '';
pt(94).paramname = 'transitionParams';
pt(94).class     = 'vector';
pt(94).nrows     = 5;
pt(94).ncols     = 1;
pt(94).subsource = 'SS_DOUBLE';
pt(94).ndims     = '2';
pt(94).size      = '[]';

pt(95).blockname = '';
pt(95).paramname = 'u_ff';
pt(95).class     = 'vector';
pt(95).nrows     = 6;
pt(95).ncols     = 1;
pt(95).subsource = 'SS_DOUBLE';
pt(95).ndims     = '2';
pt(95).size      = '[]';

pt(96).blockname = '';
pt(96).paramname = 'use2DOFHipControl';
pt(96).class     = 'scalar';
pt(96).nrows     = 1;
pt(96).ncols     = 1;
pt(96).subsource = 'SS_DOUBLE';
pt(96).ndims     = '2';
pt(96).size      = '[]';

pt(97).blockname = '';
pt(97).paramname = 'useOptimalSaturation';
pt(97).class     = 'scalar';
pt(97).nrows     = 1;
pt(97).ncols     = 1;
pt(97).subsource = 'SS_DOUBLE';
pt(97).ndims     = '2';
pt(97).size      = '[]';

pt(98).blockname = '';
pt(98).paramname = 'w_torso_lat';
pt(98).class     = 'scalar';
pt(98).nrows     = 1;
pt(98).ncols     = 1;
pt(98).subsource = 'SS_DOUBLE';
pt(98).ndims     = '2';
pt(98).size      = '[]';

pt(99).blockname = '';
pt(99).paramname = 'EnableFT';
pt(99).class     = 'scalar';
pt(99).nrows     = 1;
pt(99).ncols     = 1;
pt(99).subsource = 'SS_BOOLEAN';
pt(99).ndims     = '2';
pt(99).size      = '[]';

pt(100).blockname = '';
pt(100).paramname = 'ResetDAQ';
pt(100).class     = 'scalar';
pt(100).nrows     = 1;
pt(100).ncols     = 1;
pt(100).subsource = 'SS_BOOLEAN';
pt(100).ndims     = '2';
pt(100).size      = '[]';

pt(101).blockname = '';
pt(101).paramname = 'ResetYaw';
pt(101).class     = 'scalar';
pt(101).nrows     = 1;
pt(101).ncols     = 1;
pt(101).subsource = 'SS_BOOLEAN';
pt(101).ndims     = '2';
pt(101).size      = '[]';

function len = getlenPT
len = 101;

