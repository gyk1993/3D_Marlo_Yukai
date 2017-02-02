#ifndef __c48_Walking_ATRIAS_h__
#define __c48_Walking_ATRIAS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc48_Walking_ATRIASInstanceStruct
#define typedef_SFc48_Walking_ATRIASInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c48_sfEvent;
  boolean_T c48_isStable;
  boolean_T c48_doneDoubleBufferReInit;
  uint8_T c48_is_active_c48_Walking_ATRIAS;
  real_T (*c48_u)[6];
  real_T (*c48_u_zeroed)[6];
} SFc48_Walking_ATRIASInstanceStruct;

#endif                                 /*typedef_SFc48_Walking_ATRIASInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c48_Walking_ATRIAS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c48_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
extern void c48_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
