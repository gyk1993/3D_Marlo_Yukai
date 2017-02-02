#ifndef __c24_Walking01_DDA3D_h__
#define __c24_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_RobotCalibrationBus_tag
#define struct_RobotCalibrationBus_tag

struct RobotCalibrationBus_tag
{
  real_T AbsCalTick[10];
  real_T BoomCalTick[3];
  real_T AbsCalConst[10];
  real_T AbsCalAngle[10];
  real_T AbsMaxTick[10];
  real_T IncCalConst[6];
  real_T IncMaxTick[6];
  real_T BoomCalConst[3];
  real_T BoomCalAngle[3];
  real_T BoomMaxTick[3];
  real_T MaxTick[9];
  real_T Motors[9];
  real_T KVHOrientation[9];
  real_T MicrostrainOrientation[9];
};

#endif                                 /*struct_RobotCalibrationBus_tag*/

#ifndef typedef_c24_RobotCalibrationBus
#define typedef_c24_RobotCalibrationBus

typedef struct RobotCalibrationBus_tag c24_RobotCalibrationBus;

#endif                                 /*typedef_c24_RobotCalibrationBus*/

#ifndef typedef_SFc24_Walking01_DDA3DInstanceStruct
#define typedef_SFc24_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c24_sfEvent;
  boolean_T c24_isStable;
  boolean_T c24_doneDoubleBufferReInit;
  uint8_T c24_is_active_c24_Walking01_DDA3D;
  c24_RobotCalibrationBus *c24_Calibration;
  real_T (*c24_AbsEncoders)[10];
  real_T (*c24_IncEncoders)[9];
  real_T (*c24_IncEncodersPrev)[9];
  real_T (*c24_AbsAngle)[10];
  boolean_T *c24_Reset;
  real_T (*c24_IncAngle)[9];
  real_T (*c24_RolloverIn)[9];
  real_T (*c24_Rollover)[9];
  real_T (*c24_IncCalTickIn)[6];
  real_T (*c24_IncCalTick)[6];
} SFc24_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc24_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c24_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c24_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c24_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
