#ifndef __c59_Walking_ATRIAS_h__
#define __c59_Walking_ATRIAS_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc59_Walking_ATRIASInstanceStruct
#define typedef_SFc59_Walking_ATRIASInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c59_sfEvent;
  boolean_T c59_isStable;
  boolean_T c59_doneDoubleBufferReInit;
  uint8_T c59_is_active_c59_Walking_ATRIAS;
  real_T (*c59_EncoderAngles)[19];
  real_T (*c59_EncoderVelocities)[19];
  real_T (*c59_q_clean)[13];
  real_T (*c59_IMUAngles)[3];
  real_T (*c59_IMUVelocities)[3];
  real_T *c59_UseMotorIncEncoders;
  real_T *c59_UseIMU;
  real_T (*c59_dq_clean)[13];
  real_T (*c59_IMUTorsoOffset)[2];
  real_T (*c59_GearOffset)[4];
  boolean_T *c59_Reset;
} SFc59_Walking_ATRIASInstanceStruct;

#endif                                 /*typedef_SFc59_Walking_ATRIASInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c59_Walking_ATRIAS_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c59_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
extern void c59_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
