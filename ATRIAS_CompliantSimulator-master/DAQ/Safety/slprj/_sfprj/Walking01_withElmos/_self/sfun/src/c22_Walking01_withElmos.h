#ifndef __c22_Walking01_withElmos_h__
#define __c22_Walking01_withElmos_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc22_Walking01_withElmosInstanceStruct
#define typedef_SFc22_Walking01_withElmosInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c22_dataWrittenToVector[4];
  uint8_T c22_doSetSimStateSideEffects;
  const mxArray *c22_setSimStateSideEffectsInfo;
  int32_T *c22_sfEvent;
  boolean_T *c22_isStable;
  uint8_T *c22_is_active_c22_Walking01_withElmos;
  uint8_T *c22_is_c22_Walking01_withElmos;
  uint8_T *c22_is_Initialization;
  boolean_T *c22_SwitchOnDisabledMode;
  boolean_T *c22_EnabledMode;
  boolean_T *c22_ReadyToSwitchOnMode;
  real_T *c22_ControlWordIndex;
  real_T *c22_EnableTargetTorque;
  real_T *c22_Timeout;
  boolean_T *c22_FaultMode;
  real_T *c22_FaultDetected;
  real_T *c22_MedullaCommand;
} SFc22_Walking01_withElmosInstanceStruct;

#endif                                 /*typedef_SFc22_Walking01_withElmosInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c22_Walking01_withElmos_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c22_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
extern void c22_Walking01_withElmos_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
