#ifndef __c55_Walking01_DDA3D_h__
#define __c55_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc55_Walking01_DDA3DInstanceStruct
#define typedef_SFc55_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c55_sfEvent;
  boolean_T c55_isStable;
  boolean_T c55_doneDoubleBufferReInit;
  uint8_T c55_is_active_c55_Walking01_DDA3D;
  real_T (*c55_q_in)[13];
  real_T (*c55_q)[13];
  real_T (*c55_TorsoCOMOffsets)[2];
} SFc55_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc55_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c55_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c55_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c55_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
