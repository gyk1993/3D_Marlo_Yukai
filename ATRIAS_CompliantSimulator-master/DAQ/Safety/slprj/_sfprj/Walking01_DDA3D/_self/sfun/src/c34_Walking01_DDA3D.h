#ifndef __c34_Walking01_DDA3D_h__
#define __c34_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc34_Walking01_DDA3DInstanceStruct
#define typedef_SFc34_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  real_T c34_MAX_ANOMALY;
  real_T c34_ANOMALY_INIT;
  uint8_T c34_doSetSimStateSideEffects;
  const mxArray *c34_setSimStateSideEffectsInfo;
  int32_T *c34_sfEvent;
  boolean_T *c34_isStable;
  uint8_T *c34_is_active_c34_Walking01_DDA3D;
  uint8_T *c34_is_c34_Walking01_DDA3D;
  uint8_T *c34_is_Run;
  real_T *c34_q;
  real_T *c34_dq;
  real_T *c34_Counter;
  real_T *c34_q_clean;
  real_T *c34_ErrorCount;
  real_T *c34_q_last;
  real_T *c34_dq_last;
  real_T (*c34_q_limits)[2];
  real_T *c34_Threshold;
  boolean_T *c34_Reset;
  real_T *c34_ANOMALY_DT;
  real_T *c34_Counter_last;
  uint32_T *c34_temporalCounter_i1;
} SFc34_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc34_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c34_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c34_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c34_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
