#ifndef __c66_DDA2D_OSU3Dv2_h__
#define __c66_DDA2D_OSU3Dv2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc66_DDA2D_OSU3Dv2InstanceStruct
#define typedef_SFc66_DDA2D_OSU3Dv2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c66_sfEvent;
  boolean_T c66_isStable;
  boolean_T c66_doneDoubleBufferReInit;
  uint8_T c66_is_active_c66_DDA2D_OSU3Dv2;
  real_T (*c66_q)[13];
  real_T (*c66_dq)[13];
  real_T *c66_stanceLeg;
  real_T *c66_dy;
  real_T *c66_dy_prev;
  real_T *c66_ddy_prev;
  real_T *c66_dx;
  real_T *c66_dx_prev;
  real_T *c66_ddx_prev;
} SFc66_DDA2D_OSU3Dv2InstanceStruct;

#endif                                 /*typedef_SFc66_DDA2D_OSU3Dv2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c66_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c66_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
extern void c66_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
