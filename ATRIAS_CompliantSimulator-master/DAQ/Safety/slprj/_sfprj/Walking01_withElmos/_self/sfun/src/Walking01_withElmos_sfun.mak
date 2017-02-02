# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64
!include <ntwin32.mak>

MACHINE     = Walking01_withElmos
TARGET      = sfun
CHART_SRCS   = c1_Walking01_withElmos.c c2_Walking01_withElmos.c c3_Walking01_withElmos.c c5_Walking01_withElmos.c c6_Walking01_withElmos.c c7_Walking01_withElmos.c c9_Walking01_withElmos.c c10_Walking01_withElmos.c c11_Walking01_withElmos.c c15_Walking01_withElmos.c c16_Walking01_withElmos.c c17_Walking01_withElmos.c c18_Walking01_withElmos.c c19_Walking01_withElmos.c c20_Walking01_withElmos.c c21_Walking01_withElmos.c c22_Walking01_withElmos.c c23_Walking01_withElmos.c c24_Walking01_withElmos.c c25_Walking01_withElmos.c c26_Walking01_withElmos.c c27_Walking01_withElmos.c c32_Walking01_withElmos.c
MACHINE_SRC  = Walking01_withElmos_sfun.c
MACHINE_REG = Walking01_withElmos_sfun_registry.c
MAKEFILE    = Walking01_withElmos_sfun.mak
MATLAB_ROOT  = C:\Program Files\MATLAB\R2014b
BUILDARGS   =

#--------------------------- Tool Specifications ------------------------------
#
#
MSVC_ROOT1 = $(MSDEVDIR:SharedIDE=vc)
MSVC_ROOT2 = $(MSVC_ROOT1:SHAREDIDE=vc)
MSVC_ROOT  = $(MSVC_ROOT2:sharedide=vc)

# Compiler tool locations, CC, LD, LIBCMD:
CC     = cl.exe
LD     = link.exe
LIBCMD = lib.exe
#------------------------------ Include/Lib Path ------------------------------

USER_INCLUDES   =  /I "c:\Users\rosshart\Desktop\SVN\marlo_3d_controllers\daq_withelmos\Safety\slprj\_sfprj\walking01_withelmos\_self\sfun\src" /I "c:\Users\rosshart\Desktop\SVN\marlo_3d_controllers\daq_withelmos\Safety" /I "c:\Users\rosshart\Desktop\SVN\marlo_3d_controllers\Walking\InPlace\Rocking" /I "c:\Users\rosshart\Desktop\SVN\marlo_3d_controllers\Walking\InPlace\Rocking\dynamicmodel\c"
AUX_INCLUDES   = 
MLSLSF_INCLUDES = \
    /I "C:\Program Files\MATLAB\R2014b\extern\include" \
    /I "C:\Program Files\MATLAB\R2014b\simulink\include" \
    /I "C:\Program Files\MATLAB\R2014b\stateflow\c\mex\include" \
    /I "C:\Program Files\MATLAB\R2014b\rtw\c\src" \
    /I "C:\Users\rosshart\Desktop\SVN\MARLO_3D_Controllers\DAQ_withElmos\Safety\slprj\_sfprj\Walking01_withElmos\_self\sfun\src" 

COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   = 
INCLUDE_PATH = $(USER_INCLUDES) $(AUX_INCLUDES) $(MLSLSF_INCLUDES)\
 $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"

CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMATLAB_MEX_FILE /nologo /MD 
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction  
#----------------------------- Source Files -----------------------------------

REQ_SRCS  =  $(MACHINE_SRC) $(MACHINE_REG) $(CHART_SRCS)

USER_ABS_OBJS =

AUX_ABS_OBJS =

THIRD_PARTY_OBJS =

REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS) $(AUX_ABS_OBJS) $(THIRD_PARTY_OBJS)
OBJLIST_FILE = Walking01_withElmos_sfun.mol
SFCLIB = 
AUX_LNK_OBJS =     
USER_LIBS = 
LINK_MACHINE_LIBS = "C:\Users\rosshart\Desktop\SVN\MARLO_3D_Controllers\DAQ_withElmos\Safety\slprj\_sfprj\Walking01_withElmos\LibWalking\sfun\src\LibWalking_sfun.lib" 
BLAS_LIBS = "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libmwblas.lib" 
THIRD_PARTY_LIBS = 

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MACHINE)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
MEX_FILE_CSF =
all : $(MEX_FILE_NAME) $(MEX_FILE_CSF)

TMWLIB = "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\sf_runtime.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libmx.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libmex.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libmat.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libfixedpoint.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libut.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libmwmathutil.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libemlrt.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libmwsl_log_load_blocks.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libmwsimulink.lib" "C:\Program Files\MATLAB\R2014b\lib\win64\libmwipp.lib" 

$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS) $(SFCLIB) $(AUX_LNK_OBJS) $(USER_LIBS) $(THIRD_PARTY_LIBS)
 @echo ### Linking ...
 $(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map"\
  $(USER_LIBS) $(SFCLIB) $(AUX_LNK_OBJS)\
  $(TMWLIB) $(LINK_MACHINE_LIBS) $(DSP_LIBS) $(BLAS_LIBS) $(THIRD_PARTY_LIBS)\
  @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"


