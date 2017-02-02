#ifndef __c11_Walking01_withElmos_h__
#define __c11_Walking01_withElmos_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#include <stddef.h>
#ifndef typedef_SFc11_Walking01_withElmosInstanceStruct
#define typedef_SFc11_Walking01_withElmosInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c11_sfEvent;
  boolean_T c11_isStable;
  boolean_T c11_doneDoubleBufferReInit;
  uint8_T c11_is_active_c11_Walking01_withElmos;
  uint32_T (*c11_P)[36];
  real_T (*c11_Rotation)[3];
  real_T (*c11_Acceleration)[3];
  uint32_T *c11_Status;
  real_T *c11_Sequence;
  real_T *c11_Temperature;
  boolean_T *c11_Valid;
} SFc11_Walking01_withElmosInstanceStruct;

#endif                                 /*typedef_SFc11_Walking01_withElmosInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c11_Walking01_withElmos_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c11_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
extern void c11_Walking01_withElmos_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
