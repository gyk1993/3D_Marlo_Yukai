#ifndef __c1_Walking_ATRIAS_h__
#define __c1_Walking_ATRIAS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc1_Walking_ATRIASInstanceStruct
#define typedef_SFc1_Walking_ATRIASInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c1_sfEvent;
  boolean_T c1_isStable;
  boolean_T c1_doneDoubleBufferReInit;
  uint8_T c1_is_active_c1_Walking_ATRIAS;
  real_T (*c1_DeltaAngle)[3];
  real_T (*c1_Acceleration)[3];
  real_T *c1_Status;
  real_T *c1_Sequence;
  boolean_T *c1_Reset;
  real_T (*c1_Rk)[9];
  real_T (*c1_wk)[3];
  real_T (*c1_Rkm1)[9];
  real_T (*c1_wkm1)[3];
  real_T (*c1_Akm1)[3];
  real_T (*c1_Ak)[3];
  real_T *c1_Seqkm1;
  real_T *c1_Seqk;
  boolean_T (*c1_ValidStates)[3];
} SFc1_Walking_ATRIASInstanceStruct;

#endif                                 /*typedef_SFc1_Walking_ATRIASInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c1_Walking_ATRIAS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c1_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
extern void c1_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
