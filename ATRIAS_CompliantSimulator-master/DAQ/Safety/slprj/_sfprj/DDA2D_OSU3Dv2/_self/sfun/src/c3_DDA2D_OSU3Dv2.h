#ifndef __c3_DDA2D_OSU3Dv2_h__
#define __c3_DDA2D_OSU3Dv2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_GroundModelParamsBus_tag
#define struct_GroundModelParamsBus_tag

struct GroundModelParamsBus_tag
{
  real_T n;
  real_T k;
  real_T sigma0;
  real_T sigma1;
  real_T alpha0;
  real_T alpha2;
  real_T alpha3;
  real_T lambda_a;
  real_T lambda_b;
  real_T mu_s;
  real_T GRF_UpperLimit;
  real_T GRF_LowerLimit;
};

#endif                                 /*struct_GroundModelParamsBus_tag*/

#ifndef typedef_c3_GroundModelParamsBus
#define typedef_c3_GroundModelParamsBus

typedef struct GroundModelParamsBus_tag c3_GroundModelParamsBus;

#endif                                 /*typedef_c3_GroundModelParamsBus*/

#ifndef typedef_SFc3_DDA2D_OSU3Dv2InstanceStruct
#define typedef_SFc3_DDA2D_OSU3Dv2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c3_sfEvent;
  boolean_T c3_isStable;
  boolean_T c3_doneDoubleBufferReInit;
  uint8_T c3_is_active_c3_DDA2D_OSU3Dv2;
  real_T (*c3_pF)[3];
  real_T (*c3_GRF)[3];
  real_T (*c3_tau)[16];
  real_T (*c3_vF)[3];
  real_T (*c3_J4)[48];
  real_T (*c3_JRCol)[144];
  real_T (*c3_FootPoints)[3];
  c3_GroundModelParamsBus *c3_GroundModel;
  real_T (*c3_d)[2];
  real_T (*c3_dd)[2];
} SFc3_DDA2D_OSU3Dv2InstanceStruct;

#endif                                 /*typedef_SFc3_DDA2D_OSU3Dv2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c3_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c3_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
extern void c3_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
