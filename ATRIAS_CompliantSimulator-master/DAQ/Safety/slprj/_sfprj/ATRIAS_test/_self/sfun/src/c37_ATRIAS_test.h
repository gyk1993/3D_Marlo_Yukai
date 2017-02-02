#ifndef __c37_ATRIAS_test_h__
#define __c37_ATRIAS_test_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc37_ATRIAS_testInstanceStruct
#define typedef_SFc37_ATRIAS_testInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c37_sfEvent;
  boolean_T c37_isStable;
  boolean_T c37_doneDoubleBufferReInit;
  uint8_T c37_is_active_c37_ATRIAS_test;
  real_T (*c37_adc_value)[6];
  real_T (*c37_motorVoltage)[6];
} SFc37_ATRIAS_testInstanceStruct;

#endif                                 /*typedef_SFc37_ATRIAS_testInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c37_ATRIAS_test_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c37_ATRIAS_test_get_check_sum(mxArray *plhs[]);
extern void c37_ATRIAS_test_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
