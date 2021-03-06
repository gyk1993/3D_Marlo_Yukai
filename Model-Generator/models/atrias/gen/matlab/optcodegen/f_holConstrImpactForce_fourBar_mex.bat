@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2016a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2016a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=f_holConstrImpactForce_fourBar_mex
set MEX_NAME=f_holConstrImpactForce_fourBar_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for f_holConstrImpactForce_fourBar > f_holConstrImpactForce_fourBar_mex.mki
echo COMPILER=%COMPILER%>> f_holConstrImpactForce_fourBar_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> f_holConstrImpactForce_fourBar_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> f_holConstrImpactForce_fourBar_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> f_holConstrImpactForce_fourBar_mex.mki
echo LINKER=%LINKER%>> f_holConstrImpactForce_fourBar_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> f_holConstrImpactForce_fourBar_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> f_holConstrImpactForce_fourBar_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> f_holConstrImpactForce_fourBar_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> f_holConstrImpactForce_fourBar_mex.mki
echo BORLAND=%BORLAND%>> f_holConstrImpactForce_fourBar_mex.mki
echo OMPFLAGS= >> f_holConstrImpactForce_fourBar_mex.mki
echo OMPLINKFLAGS= >> f_holConstrImpactForce_fourBar_mex.mki
echo EMC_COMPILER=msvcsdk>> f_holConstrImpactForce_fourBar_mex.mki
echo EMC_CONFIG=optim>> f_holConstrImpactForce_fourBar_mex.mki
"C:\Program Files\MATLAB\R2016a\bin\win64\gmake" -B -f f_holConstrImpactForce_fourBar_mex.mk
