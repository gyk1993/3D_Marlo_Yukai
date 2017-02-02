#ifndef __c23_Walking01_withElmos_h__
#define __c23_Walking01_withElmos_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc23_Walking01_withElmosInstanceStruct
#define typedef_SFc23_Walking01_withElmosInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c23_dataWrittenToVector[4];
  uint8_T c23_doSetSimStateSideEffects;
  const mxArray *c23_setSimStateSideEffectsInfo;
  int32_T *c23_sfEvent;
  boolean_T *c23_isStable;
  uint8_T *c23_is_active_c23_Walking01_withElmos;
  uint8_T *c23_is_c23_Walking01_withElmos;
  uint8_T *c23_is_Initialization;
  boolean_T *c23_SwitchOnDisabledMode;
  boolean_T *c23_EnabledMode;
  boolean_T *c23_ReadyToSwitchOnMode;
  real_T *c23_ControlWordIndex;
  real_T *c23_EnableTargetTorque;
  real_T *c23_Timeout;
  boolean_T *c23_FaultMode;
  real_T *c23_FaultDetected;
  real_T *c23_MedullaCommand;
} SFc23_Walking01_withElmosInstanceStruct;

#endif                                 /*typedef_SFc23_Walking01_withElmosInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c23_Walking01_withElmos_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c23_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
extern void c23_Walking01_withElmos_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
