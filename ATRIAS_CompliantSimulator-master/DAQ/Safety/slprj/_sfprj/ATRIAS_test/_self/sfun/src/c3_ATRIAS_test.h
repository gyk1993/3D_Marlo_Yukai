#ifndef __c3_ATRIAS_test_h__
#define __c3_ATRIAS_test_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_ATRIAS_testInstanceStruct
#define typedef_SFc3_ATRIAS_testInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_ATRIAS_test;
  real_T *c3_t;
  real_T (*c3_u)[6];
  real_T (*c3_q)[13];
  real_T (*c3_dq)[13];
  real_T (*c3_q_d)[6];
  real_T *c3_kp;
  real_T *c3_kd;
  real_T (*c3_y)[6];
  real_T (*c3_dy)[6];
  real_T *c3_kp_hip;
  real_T *c3_kd_hip;
  real_T *c3_mode;
  real_T (*c3_hd_h0)[12];
  real_T (*c3_dhd_dh0)[12];
} SFc3_ATRIAS_testInstanceStruct;

#endif                                 /*typedef_SFc3_ATRIAS_testInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_ATRIAS_test_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_ATRIAS_test_get_check_sum(mxArray *plhs[]);
extern void c3_ATRIAS_test_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
