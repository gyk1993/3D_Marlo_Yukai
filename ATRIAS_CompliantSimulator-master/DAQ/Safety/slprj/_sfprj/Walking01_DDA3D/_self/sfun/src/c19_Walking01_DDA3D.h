#ifndef __c19_Walking01_DDA3D_h__
#define __c19_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc19_Walking01_DDA3DInstanceStruct
#define typedef_SFc19_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c19_sfEvent;
  boolean_T c19_isStable;
  boolean_T c19_doneDoubleBufferReInit;
  uint8_T c19_is_active_c19_Walking01_DDA3D;
  real_T (*c19_EncoderAngles)[19];
  real_T (*c19_EncoderVelocities)[19];
  real_T (*c19_q_clean)[13];
  real_T (*c19_IMUAngles)[3];
  real_T (*c19_IMUVelocities)[3];
  real_T *c19_UseMotorIncEncoders;
  real_T *c19_UseIMU;
  real_T (*c19_dq_clean)[13];
  real_T (*c19_IMUTorsoOffset)[2];
  real_T (*c19_GearOffset)[4];
  boolean_T *c19_Reset;
} SFc19_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc19_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c19_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c19_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c19_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
