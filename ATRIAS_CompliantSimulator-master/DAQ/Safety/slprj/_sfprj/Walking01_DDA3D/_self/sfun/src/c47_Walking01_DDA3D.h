#ifndef __c47_Walking01_DDA3D_h__
#define __c47_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc47_Walking01_DDA3DInstanceStruct
#define typedef_SFc47_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  real_T c47_MAX_ANOMALY;
  real_T c47_ANOMALY_INIT;
  uint8_T c47_doSetSimStateSideEffects;
  const mxArray *c47_setSimStateSideEffectsInfo;
  int32_T *c47_sfEvent;
  boolean_T *c47_isStable;
  uint8_T *c47_is_active_c47_Walking01_DDA3D;
  uint8_T *c47_is_c47_Walking01_DDA3D;
  uint8_T *c47_is_Run;
  real_T *c47_q;
  real_T *c47_dq;
  real_T *c47_q_clean;
  real_T *c47_ErrorCount;
  real_T *c47_q_last;
  real_T *c47_dq_last;
  real_T (*c47_q_limits)[2];
  real_T *c47_Threshold;
  boolean_T *c47_Reset;
  real_T *c47_ANOMALY_DT;
  uint32_T *c47_temporalCounter_i1;
} SFc47_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc47_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c47_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c47_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c47_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
