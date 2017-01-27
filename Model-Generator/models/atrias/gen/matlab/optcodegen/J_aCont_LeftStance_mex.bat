@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=J_aCont_LeftStance_mex
set MEX_NAME=J_aCont_LeftStance_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for J_aCont_LeftStance > J_aCont_LeftStance_mex.mki
echo COMPILER=%COMPILER%>> J_aCont_LeftStance_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> J_aCont_LeftStance_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> J_aCont_LeftStance_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> J_aCont_LeftStance_mex.mki
echo LINKER=%LINKER%>> J_aCont_LeftStance_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> J_aCont_LeftStance_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> J_aCont_LeftStance_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> J_aCont_LeftStance_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> J_aCont_LeftStance_mex.mki
echo BORLAND=%BORLAND%>> J_aCont_LeftStance_mex.mki
echo OMPFLAGS= >> J_aCont_LeftStance_mex.mki
echo OMPLINKFLAGS= >> J_aCont_LeftStance_mex.mki
echo EMC_COMPILER=msvcsdk>> J_aCont_LeftStance_mex.mki
echo EMC_CONFIG=optim>> J_aCont_LeftStance_mex.mki
"C:\Program Files\MATLAB\R2016a\bin\win64\gmake" -B -f J_aCont_LeftStance_mex.mk
