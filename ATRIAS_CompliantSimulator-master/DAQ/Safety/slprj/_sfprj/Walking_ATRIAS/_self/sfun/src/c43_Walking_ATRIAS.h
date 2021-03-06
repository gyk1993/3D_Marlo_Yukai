#ifndef __c43_Walking_ATRIAS_h__
#define __c43_Walking_ATRIAS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc43_Walking_ATRIASInstanceStruct
#define typedef_SFc43_Walking_ATRIASInstanceStruct

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
  uint8_T *c43_is_active_c43_Walking_ATRIAS;
  uint8_T *c43_is_c43_Walking_ATRIAS;
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
} SFc43_Walking_ATRIASInstanceStruct;

#endif                                 /*typedef_SFc43_Walking_ATRIASInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c43_Walking_ATRIAS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c43_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
extern void c43_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
