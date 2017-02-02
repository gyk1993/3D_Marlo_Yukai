#ifndef __c46_Walking_ATRIAS_h__
#define __c46_Walking_ATRIAS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc46_Walking_ATRIASInstanceStruct
#define typedef_SFc46_Walking_ATRIASInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c46_dataWrittenToVector[4];
  uint8_T c46_doSetSimStateSideEffects;
  const mxArray *c46_setSimStateSideEffectsInfo;
  int32_T *c46_sfEvent;
  boolean_T *c46_isStable;
  uint8_T *c46_is_active_c46_Walking_ATRIAS;
  uint8_T *c46_is_c46_Walking_ATRIAS;
  uint8_T *c46_is_Initialization;
  boolean_T *c46_SwitchOnDisabledMode;
  boolean_T *c46_EnabledMode;
  boolean_T *c46_ReadyToSwitchOnMode;
  real_T *c46_ControlWordIndex;
  real_T *c46_EnableTargetTorque;
  real_T *c46_Timeout;
  boolean_T *c46_FaultMode;
  real_T *c46_FaultDetected;
  real_T *c46_MedullaCommand;
} SFc46_Walking_ATRIASInstanceStruct;

#endif                                 /*typedef_SFc46_Walking_ATRIASInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c46_Walking_ATRIAS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c46_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
extern void c46_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
