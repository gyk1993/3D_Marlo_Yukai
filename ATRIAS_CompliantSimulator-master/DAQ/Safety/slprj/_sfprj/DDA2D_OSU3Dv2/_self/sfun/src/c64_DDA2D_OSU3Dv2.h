#ifndef __c64_DDA2D_OSU3Dv2_h__
#define __c64_DDA2D_OSU3Dv2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc64_DDA2D_OSU3Dv2InstanceStruct
#define typedef_SFc64_DDA2D_OSU3Dv2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c64_sfEvent;
  boolean_T c64_isStable;
  boolean_T c64_doneDoubleBufferReInit;
  uint8_T c64_is_active_c64_DDA2D_OSU3Dv2;
  real_T (*c64_q_in)[13];
  real_T (*c64_q)[13];
  real_T (*c64_TorsoCOMOffsets)[2];
} SFc64_DDA2D_OSU3Dv2InstanceStruct;

#endif                                 /*typedef_SFc64_DDA2D_OSU3Dv2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c64_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c64_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
extern void c64_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
