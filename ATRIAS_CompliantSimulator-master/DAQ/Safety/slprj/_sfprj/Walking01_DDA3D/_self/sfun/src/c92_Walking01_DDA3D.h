#ifndef __c92_Walking01_DDA3D_h__
#define __c92_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc92_Walking01_DDA3DInstanceStruct
#define typedef_SFc92_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c92_sfEvent;
  boolean_T c92_isStable;
  boolean_T c92_doneDoubleBufferReInit;
  uint8_T c92_is_active_c92_Walking01_DDA3D;
  real_T *c92_dy;
  real_T (*c92_HAlphaStruct)[30];
  real_T (*c92_HAlpha_NN)[24];
  real_T (*c92_HAlpha_Offset)[24];
} SFc92_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc92_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c92_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c92_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c92_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
