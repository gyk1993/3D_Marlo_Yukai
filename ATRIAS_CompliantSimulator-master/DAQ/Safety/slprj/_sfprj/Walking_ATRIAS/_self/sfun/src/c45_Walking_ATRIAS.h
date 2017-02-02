#ifndef __c45_Walking_ATRIAS_h__
#define __c45_Walking_ATRIAS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc45_Walking_ATRIASInstanceStruct
#define typedef_SFc45_Walking_ATRIASInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  boolean_T c45_dataWrittenToVector[4];
  uint8_T c45_doSetSimStateSideEffects;
  const mxArray *c45_setSimStateSideEffectsInfo;
  int32_T *c45_sfEvent;
  boolean_T *c45_isStable;
  uint8_T *c45_is_active_c45_Walking_ATRIAS;
  uint8_T *c45_is_c45_Walking_ATRIAS;
  uint8_T *c45_is_Initialization;
  boolean_T *c45_SwitchOnDisabledMode;
  boolean_T *c45_EnabledMode;
  boolean_T *c45_ReadyToSwitchOnMode;
  real_T *c45_ControlWordIndex;
  real_T *c45_EnableTargetTorque;
  real_T *c45_Timeout;
  boolean_T *c45_FaultMode;
  real_T *c45_FaultDetected;
  real_T *c45_MedullaCommand;
} SFc45_Walking_ATRIASInstanceStruct;

#endif                                 /*typedef_SFc45_Walking_ATRIASInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c45_Walking_ATRIAS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c45_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
extern void c45_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
