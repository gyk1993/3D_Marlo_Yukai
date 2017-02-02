#ifndef __DDA2D_OSU3Dv2_cgxe_h__
#define __DDA2D_OSU3Dv2_cgxe_h__

/* Include files */
#include "simstruc.h"
#include "rtwtypes.h"
#include "multiword_types.h"
#include "emlrt.h"
#include "covrt.h"
#include "cgxert.h"

/* Custom Code from Simulation Target dialog*/
#include "ATRIAS3D_D_Hip.h"
#include "ATRIAS3D_Cdq_Hip.h"
#include "ATRIAS3D_G_Hip.h"
#include "ATRIAS3D_B_Hip.h"
#define rtInf                          (mxGetInf())
#define rtMinusInf                     (-(mxGetInf()))
#define rtNaN                          (mxGetNaN())
#define rtIsNaN(X)                     ((int)mxIsNaN(X))
#define rtIsInf(X)                     ((int)mxIsInf(X))

extern void *emlrtRootTLSGlobal;
extern char cgxeRtErrBuf[4096];

#define CGXERT_ENTER_CHECK() \
{ \
 jmp_buf emlrtJBEnviron; \
 emlrtSetJmpBuf(emlrtRootTLSGlobal, &emlrtJBEnviron); \
 switch (setjmp(emlrtJBEnviron)) { \
 case 0:
#define CGXERT_LEAVE_CHECK() \
 break; \
 case 1: \
 emlrtRetrieveRunTimeError(emlrtRootTLSGlobal, cgxeRtErrBuf, sizeof(cgxeRtErrBuf)); \
 S->errorStatus.str = cgxeRtErrBuf; \
 case 2: \
 break; \
 default: \
 break; \
 } \
}

extern unsigned int cgxe_DDA2D_OSU3Dv2_method_dispatcher(SimStruct* S, int_T
  method, void* data);
extern int cgxe_DDA2D_OSU3Dv2_autoInfer_dispatcher(const mxArray* prhs, mxArray*
  lhs[], const char* commandName);
extern void cgxe_DDA2D_OSU3Dv2_initializer(void);
extern void cgxe_DDA2D_OSU3Dv2_terminator(void);

#endif
