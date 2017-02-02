#ifndef __c35_Walking01_DDA3D_h__
#define __c35_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc35_Walking01_DDA3DInstanceStruct
#define typedef_SFc35_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c35_sfEvent;
  boolean_T c35_isStable;
  boolean_T c35_doneDoubleBufferReInit;
  uint8_T c35_is_active_c35_Walking01_DDA3D;
  real_T (*c35_adc_value)[10];
  real_T (*c35_measuredCurrent)[10];
} SFc35_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc35_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c35_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c35_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c35_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif