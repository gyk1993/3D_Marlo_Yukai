#ifndef __c38_Walking_ATRIAS_h__
#define __c38_Walking_ATRIAS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc38_Walking_ATRIASInstanceStruct
#define typedef_SFc38_Walking_ATRIASInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c38_sfEvent;
  boolean_T c38_isStable;
  boolean_T c38_doneDoubleBufferReInit;
  uint8_T c38_is_active_c38_Walking_ATRIAS;
  real_T (*c38_Temperatures)[30];
  real_T (*c38_adc_value)[30];
} SFc38_Walking_ATRIASInstanceStruct;

#endif                                 /*typedef_SFc38_Walking_ATRIASInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c38_Walking_ATRIAS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c38_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
extern void c38_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
