#ifndef __c32_Walking01_DDA3D_h__
#define __c32_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stddef.h>
#ifndef typedef_SFc32_Walking01_DDA3DInstanceStruct
#define typedef_SFc32_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c32_sfEvent;
  boolean_T c32_isStable;
  boolean_T c32_doneDoubleBufferReInit;
  uint8_T c32_is_active_c32_Walking01_DDA3D;
  uint32_T (*c32_u)[9];
  real_T (*c32_y)[9];
} SFc32_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc32_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c32_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c32_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c32_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
