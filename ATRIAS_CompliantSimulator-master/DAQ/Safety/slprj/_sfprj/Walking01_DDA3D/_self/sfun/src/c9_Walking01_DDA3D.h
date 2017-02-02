#ifndef __c9_Walking01_DDA3D_h__
#define __c9_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_Walking01_DDA3DInstanceStruct
#define typedef_SFc9_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  real_T c9_MAX_ANOMALY;
  real_T c9_ANOMALY_INIT;
  uint8_T c9_doSetSimStateSideEffects;
  const mxArray *c9_setSimStateSideEffectsInfo;
  int32_T *c9_sfEvent;
  boolean_T *c9_isStable;
  uint8_T *c9_is_active_c9_Walking01_DDA3D;
  uint8_T *c9_is_c9_Walking01_DDA3D;
  uint8_T *c9_is_Run;
  real_T *c9_q;
  real_T *c9_dq;
  real_T *c9_Counter;
  real_T *c9_q_clean;
  real_T *c9_ErrorCount;
  real_T *c9_q_last;
  real_T *c9_dq_last;
  real_T (*c9_q_limits)[2];
  real_T *c9_Threshold;
  boolean_T *c9_Reset;
  real_T *c9_ANOMALY_DT;
  real_T *c9_Counter_last;
  uint32_T *c9_temporalCounter_i1;
} SFc9_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc9_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_Walking01_DDA3D_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c9_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
