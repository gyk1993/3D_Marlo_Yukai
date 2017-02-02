# ------------------- Required for MSVC nmake ---------------------------------
# This file should be included at the top of a MAKEFILE as follows:


CPU = AMD64
!include <ntwin32.mak>

MODEL  = DDA2D_OSU3Dv2
TARGET = cgxe
MODULE_SRCS 	= m_KVvGQhP9zVmL5NQhzh0cxF.c
MODEL_SRC	= DDA2D_OSU3Dv2_cgxe.c
MODEL_REG = DDA2D_OSU3Dv2_cgxe_registry.c
MAKEFILE    = DDA2D_OSU3Dv2_cgxe.mak
MATLAB_ROOT	= C:\Program Files\MATLAB\R2014b
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


USER_INCLUDES   =  /I "c:\Users\xingye\documents\SVN\marlo_controllers\DAQ\Safety\slprj\_cgxe\dda2d_osu3dv2\src" /I "c:\Users\xingye\documents\SVN\marlo_controllers\DAQ\Safety" /I "c:\Users\xingye\documents\SVN\marlo_sims\dda2d_osu3d" /I "c:\users\xingye\documents\svn\marlo_sims\marlo_model\originalleg_updated\cpp" /I "c:\Users\xingye\documents\SVN\marlo_models\originalleg_updated\cpp"

MLSL_INCLUDES     = \
    /I "C:\Program Files\MATLAB\R2014b\extern\include" \
    /I "C:\Program Files\MATLAB\R2014b\simulink\include" \
    /I "C:\Program Files\MATLAB\R2014b\rtw\c\src"
COMPILER_INCLUDES = /I "$(MSVC_ROOT)\include"

THIRD_PARTY_INCLUDES   = 
INCLUDE_PATH = $(MLSL_INCLUDES) $(USER_INCLUDES) $(THIRD_PARTY_INCLUDES)
LIB_PATH     = "$(MSVC_ROOT)\lib"
CFLAGS = /c /Zp8 /GR /W3 /EHs /D_CRT_SECURE_NO_DEPRECATE /D_SCL_SECURE_NO_DEPRECATE /D_SECURE_SCL=0 /DMATLAB_MEX_FILE /DMX_COMPAT_32 /nologo /MD 
LDFLAGS = /nologo /dll /MANIFEST /OPT:NOREF /export:mexFunction  
#----------------------------- Source Files -----------------------------------

USER_ABS_OBJS =

AUX_SRCS =   

REQ_SRCS  = $(MODEL_SRC) $(MODEL_REG) $(MODULE_SRCS) $(AUX_SRCS)
REQ_OBJS = $(REQ_SRCS:.cpp=.obj)
REQ_OBJS2 = $(REQ_OBJS:.c=.obj)
OBJS = $(REQ_OBJS2) $(USER_ABS_OBJS) $(AUX_ABS_OBJS)
OBJLIST_FILE = DDA2D_OSU3Dv2_cgxe.mol
BLAS_LIBS = "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libmwblas.lib" 
TMWLIB = "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libmx.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libmex.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libmat.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libfixedpoint.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libut.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libmwmathutil.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libemlrt.lib" "C:\Program Files\MATLAB\R2014b\extern\lib\win64\microsoft\libcgxert.lib" "C:\Program Files\MATLAB\R2014b\lib\win64\libmwipp.lib" 
THIRD_PARTY_LIBS = 

#--------------------------------- Rules --------------------------------------

MEX_FILE_NAME_WO_EXT = $(MODEL)_$(TARGET)
MEX_FILE_NAME = $(MEX_FILE_NAME_WO_EXT).mexw64
all : $(MEX_FILE_NAME) 


$(MEX_FILE_NAME) : $(MAKEFILE) $(OBJS)
	@echo ### Linking ...
	$(LD) $(LDFLAGS) /OUT:$(MEX_FILE_NAME) /map:"$(MEX_FILE_NAME_WO_EXT).map" $(TMWLIB) $(THIRD_PARTY_LIBS) $(BLAS_LIBS) @$(OBJLIST_FILE)
     mt -outputresource:"$(MEX_FILE_NAME);2" -manifest "$(MEX_FILE_NAME).manifest"
	@echo ### Created $@

.c.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

.cpp.obj :
	@echo ### Compiling "$<"
	$(CC) $(CFLAGS) $(INCLUDE_PATH) "$<"

