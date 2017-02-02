#ifndef __c5_Walking01_DDA3D_h__
#define __c5_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc5_Walking01_DDA3DInstanceStruct
#define typedef_SFc5_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c5_sfEvent;
  boolean_T c5_isStable;
  boolean_T c5_doneDoubleBufferReInit;
  uint8_T c5_is_active_c5_Walking01_DDA3D;
  real_T (*c5_DeltaAngle)[3];
  real_T (*c5_Acceleration)[3];
  uint8_T *c5_Status;
  real_T *c5_Sequence;
  boolean_T *c5_Reset;
  real_T (*c5_Rk)[9];
  real_T (*c5_wk)[3];
  real_T (*c5_Rkm1)[9];
  real_T (*c5_wkm1)[3];
  real_T (*c5_Akm1)[3];
  real_T (*c5_Ak)[3];
  real_T *c5_Seqkm1;
  real_T *c5_Seqk;
} SFc5_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc5_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c5_Walking01_DDA3D_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c5_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c5_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
