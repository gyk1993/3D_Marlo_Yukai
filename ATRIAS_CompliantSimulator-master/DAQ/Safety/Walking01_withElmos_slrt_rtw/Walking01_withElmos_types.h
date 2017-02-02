/*
 * Walking01_withElmos_types.h
 *
 * Code generation for model "Walking01_withElmos".
 *
 * Model version              : 1.1128
 * Simulink Coder version : 8.7 (R2014b) 08-Sep-2014
 * C source code generated on : Mon Jun 08 18:00:32 2015
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Walking01_withElmos_types_h_
#define RTW_HEADER_Walking01_withElmos_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef _DEFINED_TYPEDEF_FOR_struct_ejS3XxP2cpNSLBrHRQpJ6B_
#define _DEFINED_TYPEDEF_FOR_struct_ejS3XxP2cpNSLBrHRQpJ6B_

typedef struct {
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
} struct_ejS3XxP2cpNSLBrHRQpJ6B;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_03rYgQwetGUfYPNCqYfA8C_
#define _DEFINED_TYPEDEF_FOR_struct_03rYgQwetGUfYPNCqYfA8C_

typedef struct {
  real_T TLastUpdate;
  real_T VelocityControlLADelta;
  real_T VelocityControlTorsoDelta;
  real_T VelocityControlHipDistCur;
  real_T VelocityControlHipDistPrev;
  real_T VirtualSpringMode;
  real_T VirtualSpringStiffness;
  real_T VirtualSpringDamping;
  real_T VirtualSpringModAmplitude;
  real_T VirtualSpringModRate;
  real_T VirtualSpringRestPos;
} struct_03rYgQwetGUfYPNCqYfA8C;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_sfpKF6f8kAqNBcgNOT1TeH_
#define _DEFINED_TYPEDEF_FOR_struct_sfpKF6f8kAqNBcgNOT1TeH_

typedef struct {
  real_T kp[6];
  real_T kd[6];
  real_T epsilon[2];
  real_T kff_grav[2];
  real_T delta_grav;
  real_T kff_decoup[2];
  real_T kd_torso[2];
  real_T kp_2dof;
  real_T kd_2dof;
  real_T kpre_2dof;
  real_T kp_lat;
  real_T kd_lat;
  real_T q3d_min_lat;
  real_T q3d_max_lat;
  real_T w_torso_lat;
  real_T u_ff[6];
  real_T LateralControlMode;
  real_T DecouplingMode;
  real_T Use2DOF;
  real_T UseDSGravComp;
  real_T lat_bias;
  real_T lat_bias2;
  real_T linkFeedback;
  real_T RIO;
  real_T SelectFeedforward;
  real_T FeedforwardGain[6];
  real_T EnableFeedforwardOnStep;
} struct_sfpKF6f8kAqNBcgNOT1TeH;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_5fMnUe5Pdll1SHu9ujL08D_
#define _DEFINED_TYPEDEF_FOR_struct_5fMnUe5Pdll1SHu9ujL08D_

typedef struct {
  real_T UseQPSaturation;
  real_T QPWeight[2];
  real_T UseKASaturation;
  real_T KASaturationS1;
  real_T KASaturationS2;
  real_T KASaturationEarly;
  real_T KASaturationMax;
} struct_5fMnUe5Pdll1SHu9ujL08D;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_lKX5rZxiodED0xonMqNE4E_
#define _DEFINED_TYPEDEF_FOR_struct_lKX5rZxiodED0xonMqNE4E_

typedef struct {
  real_T EnableSwapOnKAAccel;
  real_T EnableSwapOnKASpring;
  real_T EnableBackwardSwap;
  real_T ImpactThresholdKAAccel;
  real_T ImpactThresholdKASpringAbs;
  real_T ImpactThresholdKASpringRel;
  real_T SwapThresholdS;
  real_T AllowDoubleSupport;
  real_T UseGaitTransition;
  real_T NumTransitionSteps;
  real_T TransitionThresholdTorsoVel;
  real_T KAInjection[2];
  real_T MinDeltaThetaTransition;
  real_T StartSecondGaitOnStep;
  real_T VBLAParams[6];
  real_T BalanceParams[13];
  real_T GaitTweaks[5];
  real_T TStepInitial;
  real_T TMaxUpdate;
  real_T RunMode;
  real_T UseAbsoluteSwingLA;
  real_T ErrorZeroFactor[6];
  real_T ErrorVelZeroFactor[6];
  real_T StanceLegInit;
  real_T ControllerModeInit;
  real_T UsePosingControl;
  real_T TPosing;
  real_T TorsoBackAngle;
  real_T TorsoBackOnStep;
  real_T EnergyControlGain;
  real_T EnergyControlPhi0;
  real_T VelocityControlTorsoMax;
  real_T VelocityControlTorsoMin;
  real_T VelocityControlTorsoGain;
  real_T VelocityControlTorsoV0;
  real_T MinDeltaTheta;
  real_T Theta0;
  real_T KThetaPlus;
  real_T KThetaMinus;
  real_T RollPhaseVelocityThresh;
  real_T RollPhaseSThresh;
  real_T MaxError;
  real_T MaxErrorVel;
  real_T MaxErrorCount;
  real_T K1MidStanceUpdate[6];
  real_T K2MidStanceUpdate[6];
  real_T EnableVelocityBasedUpdate;
  real_T VelocityBasedUpdateK1[6];
  real_T VelocityBasedUpdateK2[6];
  real_T VelocityBasedUpdateDTheta0;
  real_T VelocityBasedUpdateLimits[12];
  real_T DesiredYawOffset;
} struct_lKX5rZxiodED0xonMqNE4E;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_vVbQQSvlu4te0AbLB0kVdB_
#define _DEFINED_TYPEDEF_FOR_struct_vVbQQSvlu4te0AbLB0kVdB_

typedef struct {
  real_T c0;
  real_T ct;
  real_T cq[13];
  real_T t0;
  real_T cz[7];
} struct_vVbQQSvlu4te0AbLB0kVdB;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_oI6LMO2QxWYqjYfxzs0Dp_
#define _DEFINED_TYPEDEF_FOR_struct_oI6LMO2QxWYqjYfxzs0Dp_

typedef struct {
  real_T c0;
  real_T cq[13];
} struct_oI6LMO2QxWYqjYfxzs0Dp;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_struct_UNZvwuE1nYalf4RiZWSyfE_
#define _DEFINED_TYPEDEF_FOR_struct_UNZvwuE1nYalf4RiZWSyfE_

typedef struct {
  real_T H0[78];
  real_T HAlpha[36];
  real_T ThetaLimits[2];
  struct_vVbQQSvlu4te0AbLB0kVdB Theta;
  real_T SaturateS;
  real_T SLimits[2];
  real_T EnforceIncreasingS;
  real_T UseCorrection;
  real_T SMaxCorrection;
  real_T HAlphaCorrection[30];
  struct_oI6LMO2QxWYqjYfxzs0Dp Phi;
  real_T PhiAlpha[20];
  real_T SaturateR;
  real_T RLimits[2];
  real_T HBarAlpha[30];
  real_T HBarLimits[12];
  real_T HAlphaStar[36];
  real_T YawLimit;
} struct_UNZvwuE1nYalf4RiZWSyfE;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_RobotCalibrationBus_
#define _DEFINED_TYPEDEF_FOR_RobotCalibrationBus_

typedef struct {
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
} RobotCalibrationBus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_ControlStateBus_
#define _DEFINED_TYPEDEF_FOR_ControlStateBus_

typedef struct {
  real_T ControllerMode;
  real_T SupportState;
  real_T StanceLeg;
  real_T InDoubleSupport;
  real_T RollPhase;
  real_T StepCount;
  real_T Error;
} ControlStateBus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SupervisoryParamsBus_
#define _DEFINED_TYPEDEF_FOR_SupervisoryParamsBus_

typedef struct {
  real_T EnableSwapOnKAAccel;
  real_T EnableSwapOnKASpring;
  real_T EnableBackwardSwap;
  real_T ImpactThresholdKAAccel;
  real_T ImpactThresholdKASpringAbs;
  real_T ImpactThresholdKASpringRel;
  real_T SwapThresholdS;
  real_T AllowDoubleSupport;
  real_T UseGaitTransition;
  real_T NumTransitionSteps;
  real_T TransitionThresholdTorsoVel;
  real_T KAInjection[2];
  real_T MinDeltaThetaTransition;
  real_T StartSecondGaitOnStep;
  real_T VBLAParams[6];
  real_T BalanceParams[13];
  real_T GaitTweaks[5];
  real_T TStepInitial;
  real_T TMaxUpdate;
  real_T RunMode;
  real_T UseAbsoluteSwingLA;
  real_T ErrorZeroFactor[6];
  real_T ErrorVelZeroFactor[6];
  real_T StanceLegInit;
  real_T ControllerModeInit;
  real_T UsePosingControl;
  real_T TPosing;
  real_T TorsoBackAngle;
  real_T TorsoBackOnStep;
  real_T EnergyControlGain;
  real_T EnergyControlPhi0;
  real_T VelocityControlTorsoMax;
  real_T VelocityControlTorsoMin;
  real_T VelocityControlTorsoGain;
  real_T VelocityControlTorsoV0;
  real_T MinDeltaTheta;
  real_T Theta0;
  real_T KThetaPlus;
  real_T KThetaMinus;
  real_T RollPhaseVelocityThresh;
  real_T RollPhaseSThresh;
  real_T MaxError;
  real_T MaxErrorVel;
  real_T MaxErrorCount;
  real_T K1MidStanceUpdate[6];
  real_T K2MidStanceUpdate[6];
  real_T EnableVelocityBasedUpdate;
  real_T VelocityBasedUpdateK1[6];
  real_T VelocityBasedUpdateK2[6];
  real_T VelocityBasedUpdateDTheta0;
  real_T VelocityBasedUpdateLimits[12];
  real_T DesiredYawOffset;
} SupervisoryParamsBus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_DiscreteParamsBus_
#define _DEFINED_TYPEDEF_FOR_DiscreteParamsBus_

typedef struct {
  real_T TLastUpdate;
  real_T VelocityControlLADelta;
  real_T VelocityControlTorsoDelta;
  real_T VelocityControlHipDistCur;
  real_T VelocityControlHipDistPrev;
  real_T VirtualSpringMode;
  real_T VirtualSpringStiffness;
  real_T VirtualSpringDamping;
  real_T VirtualSpringModAmplitude;
  real_T VirtualSpringModRate;
  real_T VirtualSpringRestPos;
} DiscreteParamsBus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_ThetaParamsBus_
#define _DEFINED_TYPEDEF_FOR_ThetaParamsBus_

typedef struct {
  real_T c0;
  real_T ct;
  real_T cq[13];
  real_T t0;
  real_T cz[7];
} ThetaParamsBus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_PhiParamsBus_
#define _DEFINED_TYPEDEF_FOR_PhiParamsBus_

typedef struct {
  real_T c0;
  real_T cq[13];
} PhiParamsBus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_OutputParamsBus_
#define _DEFINED_TYPEDEF_FOR_OutputParamsBus_

typedef struct {
  real_T H0[78];
  real_T HAlpha[36];
  real_T ThetaLimits[2];
  ThetaParamsBus Theta;
  real_T SaturateS;
  real_T SLimits[2];
  real_T EnforceIncreasingS;
  real_T UseCorrection;
  real_T SMaxCorrection;
  real_T HAlphaCorrection[30];
  PhiParamsBus Phi;
  real_T PhiAlpha[20];
  real_T SaturateR;
  real_T RLimits[2];
  real_T HBarAlpha[30];
  real_T HBarLimits[12];
  real_T HAlphaStar[36];
  real_T YawLimit;
} OutputParamsBus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_FeedbackParamsBus_
#define _DEFINED_TYPEDEF_FOR_FeedbackParamsBus_

typedef struct {
  real_T kp[6];
  real_T kd[6];
  real_T epsilon[2];
  real_T kff_grav[2];
  real_T delta_grav;
  real_T kff_decoup[2];
  real_T kd_torso[2];
  real_T kp_2dof;
  real_T kd_2dof;
  real_T kpre_2dof;
  real_T kp_lat;
  real_T kd_lat;
  real_T q3d_min_lat;
  real_T q3d_max_lat;
  real_T w_torso_lat;
  real_T u_ff[6];
  real_T LateralControlMode;
  real_T DecouplingMode;
  real_T Use2DOF;
  real_T UseDSGravComp;
  real_T lat_bias;
  real_T lat_bias2;
  real_T linkFeedback;
  real_T RIO;
  real_T SelectFeedforward;
  real_T FeedforwardGain[6];
  real_T EnableFeedforwardOnStep;
} FeedbackParamsBus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_SaturationParamsBus_
#define _DEFINED_TYPEDEF_FOR_SaturationParamsBus_

typedef struct {
  real_T UseQPSaturation;
  real_T QPWeight[2];
  real_T UseKASaturation;
  real_T KASaturationS1;
  real_T KASaturationS2;
  real_T KASaturationEarly;
  real_T KASaturationMax;
} SaturationParamsBus;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_ControlParamsBus_
#define _DEFINED_TYPEDEF_FOR_ControlParamsBus_

typedef struct {
  SupervisoryParamsBus Supervisory;
  DiscreteParamsBus Discrete;
  OutputParamsBus Output;
  FeedbackParamsBus Feedback;
  SaturationParamsBus Saturation;
} ControlParamsBus;

#endif

/* Custom Type definition for MATLAB Function: '<S33>/TypecastAndCast1' */
#include <stddef.h>

/* Custom Type definition for Chart: '<S202>/StateLogic' */
#ifndef struct_sHmAB4PxSQg3wmqo1saFKWH
#define struct_sHmAB4PxSQg3wmqo1saFKWH

struct sHmAB4PxSQg3wmqo1saFKWH
{
  real_T halpha[24];
  real_T spPlus;
};

#endif                                 /*struct_sHmAB4PxSQg3wmqo1saFKWH*/

#ifndef typedef_sHmAB4PxSQg3wmqo1saFKWH_Walki_T
#define typedef_sHmAB4PxSQg3wmqo1saFKWH_Walki_T

typedef struct sHmAB4PxSQg3wmqo1saFKWH sHmAB4PxSQg3wmqo1saFKWH_Walki_T;

#endif                                 /*typedef_sHmAB4PxSQg3wmqo1saFKWH_Walki_T*/

/* Parameters (auto storage) */
typedef struct P_Walking01_withElmos_T_ P_Walking01_withElmos_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Walking01_withElmos_T RT_MODEL_Walking01_withElmos_T;

#endif                                 /* RTW_HEADER_Walking01_withElmos_types_h_ */
