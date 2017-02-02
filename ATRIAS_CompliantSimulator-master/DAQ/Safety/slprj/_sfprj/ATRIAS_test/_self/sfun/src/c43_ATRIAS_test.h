#ifndef __c43_ATRIAS_test_h__
#define __c43_ATRIAS_test_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc43_ATRIAS_testInstanceStruct
#define typedef_SFc43_ATRIAS_testInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c43_dataWrittenToVector[4];
  uint8_T c43_doSetSimStateSideEffects;
  const mxArray *c43_setSimStateSideEffectsInfo;
  int32_T *c43_sfEvent;
  boolean_T *c43_isStable;
  uint8_T *c43_is_active_c43_ATRIAS_test;
  uint8_T *c43_is_c43_ATRIAS_test;
  uint8_T *c43_is_Initialization;
  boolean_T *c43_SwitchOnDisabledMode;
  boolean_T *c43_EnabledMode;
  boolean_T *c43_ReadyToSwitchOnMode;
  real_T *c43_ControlWordIndex;
  real_T *c43_EnableTargetTorque;
  real_T *c43_Timeout;
  boolean_T *c43_FaultMode;
  real_T *c43_FaultDetected;
  real_T *c43_MedullaCommand;
} SFc43_ATRIAS_testInstanceStruct;

#endif                                 /*typedef_SFc43_ATRIAS_testInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c43_ATRIAS_test_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c43_ATRIAS_test_get_check_sum(mxArray *plhs[]);
extern void c43_ATRIAS_test_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
