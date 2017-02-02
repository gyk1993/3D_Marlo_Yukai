function runtlccmd
% RUNTLCCMD - run tlc command (regenerate C code from .rtw file) for model Walking01_withElmos
% This function will run the tlc command stored in the variable 
% "tlccmd" in tlccmd.mat, whose contents is as follows:
% 
% 	tlc
% 	-r
% 	C:\Users\rosshart\Desktop\SVN\MARLO_3D_Controllers\DAQ_withElmos\Safety\Walking01_withElmos_slrt_rtw\Walking01_withElmos.rtw
% 	C:\Program Files\MATLAB\R2014b\toolbox\slrt\rtw\slrt.tlc
% 	-OC:\Users\rosshart\Desktop\SVN\MARLO_3D_Controllers\DAQ_withElmos\Safety\Walking01_withElmos_slrt_rtw
% 	-IC:\Program Files\MATLAB\R2014b\toolbox\slrt\rtw
% 	-IC:\Program Files\MATLAB\R2014b\toolbox\rtw\targets\xpc\target\build\xpcblocks\tlc_c
% 	-IC:\Program Files\MATLAB\R2014b\toolbox\simulink\fixedandfloat\tlc_c
% 	-IC:\Users\rosshart\Desktop\SVN\MARLO_3D_Controllers\DAQ_withElmos\Safety\Walking01_withElmos_slrt_rtw\tlc
% 	-IC:\Program Files\MATLAB\R2014b\rtw\c\tlc\mw
% 	-IC:\Program Files\MATLAB\R2014b\rtw\c\tlc\lib
% 	-IC:\Program Files\MATLAB\R2014b\rtw\c\tlc\blocks
% 	-IC:\Program Files\MATLAB\R2014b\rtw\c\tlc\fixpt
% 	-IC:\Program Files\MATLAB\R2014b\stateflow\c\tlc
% 	-aFoldNonRolledExpr=1
% 	-aInlineInvariantSignals=1
% 	-aInlineParameters=1
% 	-aLocalBlockOutputs=1
% 	-aRollThreshold=5
% 	-aForceBlockIOInitOptimize=0
% 	-aGenerateReport=0
% 	-aGenCodeOnly=0
% 	-aRTWVerbose=1
% 	-aIncludeHyperlinkInReport=0
% 	-aLaunchReport=0
% 	-aGenerateTraceInfo=0
% 	-aForceParamTrailComments=0
% 	-aGenerateComments=1
% 	-aIgnoreCustomStorageClasses=1
% 	-aIncHierarchyInIds=0
% 	-aMaxRTWIdLen=31
% 	-aShowEliminatedStatements=0
% 	-aIncDataTypeInIds=0
% 	-aInsertBlockDesc=0
% 	-aIgnoreTestpoints=0
% 	-aSimulinkBlockComments=1
% 	-aInlinedPrmAccess="Literals"
% 	-aTargetFcnLib="ansi_tfl_table_tmw.mat"
% 	-aLogVarNameModifier="rt_"
% 	-aGenerateFullHeader=1
% 	-aRL32ModeModifier="Real-Time"
% 	-aExtMode=1
% 	-aExtModeMexArgs=""
% 	-aExtModeArmWhenConnect=0
% 	-aRL32LogTETModifier=1
% 	-aRL32LogBufSizeModifier="100000000"
% 	-aRL32IRQSourceModifier="Timer"
% 	-axPCIRQSourceBoard="None/Other"
% 	-axPCIOIRQSlot="-1"
% 	-axpcDblBuff=0
% 	-axpcObjCom=0
% 	-axPCGenerateASAP2=0
% 	-aRL32ObjectName="tg"
% 	-axPCisDownloadable=1
% 	-axPCisDefaultEnv=1
% 	-axPCTargetPCEnvName=""
% 	-axPCisModelTimeout=0
% 	-axPCModelTimeoutSecs="20"
% 	-axPCLoadParamSetFile=0
% 	-axPCOnTgtParamSetFileName=""
% 	-axPCRL32EventNumber="0"
% 	-aGenerateTraceInfo=0
% 	-aIgnoreTestpoints=0
% 	-axPCModelStackSizeKB=128
% 	-axPCMaxOverloads=1000
% 	-aProtectedModelReferenceTarget=0
% 	-p10000

   disp('This function will be obsoleted in a future release.') 
   mdl = 'Walking01_withElmos';

   sysopen = ~isempty(strmatch(mdl, find_system('type', 'block_diagram'), 'exact'));

   if ~sysopen

      disp([mfilename ': Error: model ' mdl ' is not open. Please open model ' mdl ' and then run ' mfilename ' again.']);

   else

      rtwprivate('rtwattic', 'setBuildDir', 'C:\Users\rosshart\Desktop\SVN\MARLO_3D_Controllers\DAQ_withElmos\Safety\Walking01_withElmos_slrt_rtw');
      rtwprivate('ec_set_replacement_flag', 'Walking01_withElmos');
      set_param('Walking01_withElmos', 'RTWGenSharedUtilitiesWithoutAssert', 0);
      load tlccmd.mat;
      savedpwd = pwd;
      cd ..;
      coder.internal.ModelCodegenMgr.setInstance(modelCodegenMgr);
      tlccmd{end+1} = '-aSLCGUseRTWContext=0';
      feval(tlccmd{:});
      coder.internal.ModelCodegenMgr.setInstance([]);
      
      rtwprivate rtwattic clean;
      set_param('Walking01_withElmos', 'RTWGenSharedUtilitiesWithoutAssert', -1);
      cd(savedpwd);

   end
