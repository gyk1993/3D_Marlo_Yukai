#ifndef __c2_ATRIAS_test_h__
#define __c2_ATRIAS_test_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_ATRIAS_testInstanceStruct
#define typedef_SFc2_ATRIAS_testInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_ATRIAS_test;
  real_T (*c2_RkIn)[9];
  real_T (*c2_wk)[3];
  real_T (*c2_RCal)[9];
  boolean_T *c2_Reset;
  real_T (*c2_R0In)[9];
  real_T (*c2_ZYX)[3];
  real_T (*c2_dZYX)[3];
  real_T (*c2_Rk)[9];
  real_T (*c2_R0)[9];
  real_T (*c2_YawRolloverIn)[2];
  real_T (*c2_YawRollover)[2];
} SFc2_ATRIAS_testInstanceStruct;

#endif                                 /*typedef_SFc2_ATRIAS_testInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_ATRIAS_test_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_ATRIAS_test_get_check_sum(mxArray *plhs[]);
extern void c2_ATRIAS_test_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
