#ifndef __c6_Walking01_withElmos_h__
#define __c6_Walking01_withElmos_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stddef.h>
#ifndef typedef_SFc6_Walking01_withElmosInstanceStruct
#define typedef_SFc6_Walking01_withElmosInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c6_sfEvent;
  boolean_T c6_isStable;
  boolean_T c6_doneDoubleBufferReInit;
  uint8_T c6_is_active_c6_Walking01_withElmos;
  uint32_T (*c6_u)[3];
  real_T (*c6_y)[3];
} SFc6_Walking01_withElmosInstanceStruct;

#endif                                 /*typedef_SFc6_Walking01_withElmosInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c6_Walking01_withElmos_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c6_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
extern void c6_Walking01_withElmos_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
