#ifndef __c17_Walking01_DDA3D_h__
#define __c17_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc17_Walking01_DDA3DInstanceStruct
#define typedef_SFc17_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c17_sfEvent;
  boolean_T c17_isStable;
  boolean_T c17_doneDoubleBufferReInit;
  uint8_T c17_is_active_c17_Walking01_DDA3D;
  real_T (*c17_Temperatures)[30];
  real_T (*c17_adc_value)[30];
} SFc17_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc17_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c17_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c17_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c17_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif