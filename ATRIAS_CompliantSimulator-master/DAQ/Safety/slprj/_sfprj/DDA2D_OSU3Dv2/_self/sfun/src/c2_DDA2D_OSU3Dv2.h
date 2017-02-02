#ifndef __c2_DDA2D_OSU3Dv2_h__
#define __c2_DDA2D_OSU3Dv2_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_DDA2D_OSU3Dv2InstanceStruct
#define typedef_SFc2_DDA2D_OSU3Dv2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_DDA2D_OSU3Dv2;
  real_T c2_spring_k;
  real_T c2_spring_zeta;
  real_T c2_ProjectTo2D;
  real_T c2_BoomParams[3];
  real_T c2_pBInitial[3];
  real_T (*c2_x)[32];
  real_T (*c2_u)[6];
  real_T (*c2_D)[256];
  real_T (*c2_Cdq)[16];
  real_T (*c2_G)[16];
  real_T (*c2_B)[96];
  real_T (*c2_FGround)[16];
  real_T (*c2_Fstiction)[6];
  real_T (*c2_x_dot)[32];
  real_T *c2_ExternalHipForce;
  real_T *c2_Ttime;
} SFc2_DDA2D_OSU3Dv2InstanceStruct;

#endif                                 /*typedef_SFc2_DDA2D_OSU3Dv2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c2_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
extern void c2_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void *
  data);

#endif
