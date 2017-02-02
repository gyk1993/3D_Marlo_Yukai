#ifndef __c33_Walking01_DDA3D_h__
#define __c33_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc33_Walking01_DDA3DInstanceStruct
#define typedef_SFc33_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c33_sfEvent;
  boolean_T c33_isStable;
  boolean_T c33_doneDoubleBufferReInit;
  uint8_T c33_is_active_c33_Walking01_DDA3D;
  real_T (*c33_RkIn)[9];
  real_T (*c33_wk)[3];
  real_T (*c33_RCal)[9];
  boolean_T *c33_Reset;
  real_T (*c33_R0In)[9];
  real_T (*c33_ZYX)[3];
  real_T (*c33_dZYX)[3];
  real_T (*c33_Rk)[9];
  real_T (*c33_R0)[9];
  real_T (*c33_YawRolloverIn)[2];
  real_T (*c33_YawRollover)[2];
} SFc33_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc33_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c33_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c33_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c33_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
