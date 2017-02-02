#ifndef __c20_Walking01_withElmos_h__
#define __c20_Walking01_withElmos_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc20_Walking01_withElmosInstanceStruct
#define typedef_SFc20_Walking01_withElmosInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c20_dataWrittenToVector[4];
  uint8_T c20_doSetSimStateSideEffects;
  const mxArray *c20_setSimStateSideEffectsInfo;
  int32_T *c20_sfEvent;
  boolean_T *c20_isStable;
  uint8_T *c20_is_active_c20_Walking01_withElmos;
  uint8_T *c20_is_c20_Walking01_withElmos;
  uint8_T *c20_is_Initialization;
  boolean_T *c20_SwitchOnDisabledMode;
  boolean_T *c20_EnabledMode;
  boolean_T *c20_ReadyToSwitchOnMode;
  real_T *c20_ControlWordIndex;
  real_T *c20_EnableTargetTorque;
  real_T *c20_Timeout;
  boolean_T *c20_FaultMode;
  real_T *c20_FaultDetected;
  real_T *c20_MedullaCommand;
} SFc20_Walking01_withElmosInstanceStruct;

#endif                                 /*typedef_SFc20_Walking01_withElmosInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c20_Walking01_withElmos_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c20_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
extern void c20_Walking01_withElmos_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
