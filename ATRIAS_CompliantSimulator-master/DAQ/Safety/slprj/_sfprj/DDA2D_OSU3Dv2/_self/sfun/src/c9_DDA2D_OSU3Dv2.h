#ifndef __c9_DDA2D_OSU3Dv2_h__
#define __c9_DDA2D_OSU3Dv2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc9_DDA2D_OSU3Dv2InstanceStruct
#define typedef_SFc9_DDA2D_OSU3Dv2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c9_sfEvent;
  boolean_T c9_isStable;
  boolean_T c9_doneDoubleBufferReInit;
  uint8_T c9_is_active_c9_DDA2D_OSU3Dv2;
  real_T (*c9_x)[32];
  real_T (*c9_pR)[3];
  real_T (*c9_vR)[3];
  real_T (*c9_J4R)[48];
  real_T (*c9_JR1Col)[144];
  real_T (*c9_pL)[3];
  real_T (*c9_vL)[3];
  real_T (*c9_J4L)[48];
  real_T (*c9_JR5Col)[144];
  real_T (*c9_FootPoints)[3];
} SFc9_DDA2D_OSU3Dv2InstanceStruct;

#endif                                 /*typedef_SFc9_DDA2D_OSU3Dv2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c9_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c9_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
extern void c9_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
