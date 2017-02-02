#ifndef __c49_Walking01_DDA3D_h__
#define __c49_Walking01_DDA3D_h__

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

#ifndef typedef_c49_RobotCalibrationBus
#define typedef_c49_RobotCalibrationBus

typedef struct RobotCalibrationBus_tag c49_RobotCalibrationBus;

#endif                                 /*typedef_c49_RobotCalibrationBus*/

#ifndef typedef_SFc49_Walking01_DDA3DInstanceStruct
#define typedef_SFc49_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c49_sfEvent;
  boolean_T c49_isStable;
  boolean_T c49_doneDoubleBufferReInit;
  uint8_T c49_is_active_c49_Walking01_DDA3D;
  c49_RobotCalibrationBus *c49_Calibration;
  real_T (*c49_AbsEncoders)[10];
  real_T (*c49_IncEncoders)[9];
  real_T (*c49_IncEncodersPrev)[9];
  real_T (*c49_AbsAngle)[10];
  boolean_T *c49_Reset;
  real_T (*c49_IncAngle)[9];
  real_T (*c49_RolloverIn)[9];
  real_T (*c49_Rollover)[9];
  real_T (*c49_IncCalTickIn)[6];
  real_T (*c49_IncCalTick)[6];
} SFc49_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc49_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c49_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c49_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c49_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
