#ifndef __c3_Walking01_DDA3D_h__
#define __c3_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc3_Walking01_DDA3DInstanceStruct
#define typedef_SFc3_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  real_T c3_MAX_ANOMALY;
  real_T c3_ANOMALY_INIT;
  uint8_T c3_doSetSimStateSideEffects;
  const mxArray *c3_setSimStateSideEffectsInfo;
  int32_T *c3_sfEvent;
  boolean_T *c3_isStable;
  uint8_T *c3_is_active_c3_Walking01_DDA3D;
  uint8_T *c3_is_c3_Walking01_DDA3D;
  uint8_T *c3_is_Run;
  real_T *c3_q;
  real_T *c3_dq;
  real_T *c3_q_clean;
  real_T *c3_ErrorCount;
  real_T *c3_q_last;
  real_T *c3_dq_last;
  real_T (*c3_q_limits)[2];
  real_T *c3_Threshold;
  boolean_T *c3_Reset;
  real_T *c3_ANOMALY_DT;
  uint32_T *c3_temporalCounter_i1;
} SFc3_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc3_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_Walking01_DDA3D_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c3_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
