#ifndef __c44_ATRIAS_test_h__
#define __c44_ATRIAS_test_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc44_ATRIAS_testInstanceStruct
#define typedef_SFc44_ATRIAS_testInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c44_dataWrittenToVector[4];
  uint8_T c44_doSetSimStateSideEffects;
  const mxArray *c44_setSimStateSideEffectsInfo;
  int32_T *c44_sfEvent;
  boolean_T *c44_isStable;
  uint8_T *c44_is_active_c44_ATRIAS_test;
  uint8_T *c44_is_c44_ATRIAS_test;
  uint8_T *c44_is_Initialization;
  boolean_T *c44_SwitchOnDisabledMode;
  boolean_T *c44_EnabledMode;
  boolean_T *c44_ReadyToSwitchOnMode;
  real_T *c44_ControlWordIndex;
  real_T *c44_EnableTargetTorque;
  real_T *c44_Timeout;
  boolean_T *c44_FaultMode;
  real_T *c44_FaultDetected;
  real_T *c44_MedullaCommand;
} SFc44_ATRIAS_testInstanceStruct;

#endif                                 /*typedef_SFc44_ATRIAS_testInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c44_ATRIAS_test_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c44_ATRIAS_test_get_check_sum(mxArray *plhs[]);
extern void c44_ATRIAS_test_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
