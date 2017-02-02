#ifndef __c39_Walking01_DDA3D_h__
#define __c39_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc39_Walking01_DDA3DInstanceStruct
#define typedef_SFc39_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c39_sfEvent;
  boolean_T c39_isStable;
  boolean_T c39_doneDoubleBufferReInit;
  uint8_T c39_is_active_c39_Walking01_DDA3D;
  real_T (*c39_Switches)[6];
  real_T *c39_LimitSwitchesEncoded;
} SFc39_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc39_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c39_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c39_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c39_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif