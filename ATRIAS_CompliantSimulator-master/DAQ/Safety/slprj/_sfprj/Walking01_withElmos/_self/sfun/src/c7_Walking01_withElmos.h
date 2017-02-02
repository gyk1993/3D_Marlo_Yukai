#ifndef __c7_Walking01_withElmos_h__
#define __c7_Walking01_withElmos_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc7_Walking01_withElmosInstanceStruct
#define typedef_SFc7_Walking01_withElmosInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c7_sfEvent;
  boolean_T c7_isStable;
  boolean_T c7_doneDoubleBufferReInit;
  uint8_T c7_is_active_c7_Walking01_withElmos;
  real_T (*c7_RkIn)[9];
  real_T (*c7_wk)[3];
  real_T (*c7_RCal)[9];
  boolean_T *c7_Reset;
  real_T (*c7_R0In)[9];
  real_T (*c7_ZYX)[3];
  real_T (*c7_dZYX)[3];
  real_T (*c7_Rk)[9];
  real_T (*c7_R0)[9];
  real_T (*c7_YawRolloverIn)[2];
  real_T (*c7_YawRollover)[2];
} SFc7_Walking01_withElmosInstanceStruct;

#endif                                 /*typedef_SFc7_Walking01_withElmosInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c7_Walking01_withElmos_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c7_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
extern void c7_Walking01_withElmos_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
