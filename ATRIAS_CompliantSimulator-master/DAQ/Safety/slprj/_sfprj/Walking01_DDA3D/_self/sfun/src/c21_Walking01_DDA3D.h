#ifndef __c21_Walking01_DDA3D_h__
#define __c21_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc21_Walking01_DDA3DInstanceStruct
#define typedef_SFc21_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c21_sfEvent;
  boolean_T c21_isStable;
  boolean_T c21_doneDoubleBufferReInit;
  uint8_T c21_is_active_c21_Walking01_DDA3D;
  real_T (*c21_RkIn)[9];
  real_T (*c21_wk)[3];
  real_T (*c21_RCal)[9];
  boolean_T *c21_Reset;
  real_T (*c21_R0In)[9];
  real_T (*c21_ZYX)[3];
  real_T (*c21_dZYX)[3];
  real_T (*c21_Rk)[9];
  real_T (*c21_R0)[9];
  real_T (*c21_YawRolloverIn)[2];
  real_T (*c21_YawRollover)[2];
} SFc21_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc21_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c21_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c21_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c21_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
