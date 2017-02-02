#ifndef __c13_LibWalking_h__
#define __c13_LibWalking_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef struct_ControlStateBus_tag
#define struct_ControlStateBus_tag

struct ControlStateBus_tag
{
  real_T ControllerMode;
  real_T SupportState;
  real_T StanceLeg;
  real_T InDoubleSupport;
  real_T RollPhase;
  real_T StepCount;
  real_T Error;
};

#endif                                 /*struct_ControlStateBus_tag*/

#ifndef typedef_c13_ControlStateBus
#define typedef_c13_ControlStateBus

typedef struct ControlStateBus_tag c13_ControlStateBus;

#endif                                 /*typedef_c13_ControlStateBus*/

#ifndef struct_DiscreteParamsBus_tag
#define struct_DiscreteParamsBus_tag

struct DiscreteParamsBus_tag
{
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
};

#endif                                 /*struct_DiscreteParamsBus_tag*/

#ifndef typedef_c13_DiscreteParamsBus
#define typedef_c13_DiscreteParamsBus

typedef struct DiscreteParamsBus_tag c13_DiscreteParamsBus;

#endif                                 /*typedef_c13_DiscreteParamsBus*/

#ifndef struct_FeedbackParamsBus_tag
#define struct_FeedbackParamsBus_tag

struct FeedbackParamsBus_tag
{
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
};

#endif                                 /*struct_FeedbackParamsBus_tag*/

#ifndef typedef_c13_FeedbackParamsBus
#define typedef_c13_FeedbackParamsBus

typedef struct FeedbackParamsBus_tag c13_FeedbackParamsBus;

#endif                                 /*typedef_c13_FeedbackParamsBus*/

#ifndef struct_SaturationParamsBus_tag
#define struct_SaturationParamsBus_tag

struct SaturationParamsBus_tag
{
  real_T UseQPSaturation;
  real_T QPWeight[2];
  real_T UseKASaturation;
  real_T KASaturationS1;
  real_T KASaturationS2;
  real_T KASaturationEarly;
  real_T KASaturationMax;
};

#endif                                 /*struct_SaturationParamsBus_tag*/

#ifndef typedef_c13_SaturationParamsBus
#define typedef_c13_SaturationParamsBus

typedef struct SaturationParamsBus_tag c13_SaturationParamsBus;

#endif                                 /*typedef_c13_SaturationParamsBus*/

#ifndef struct_SupervisoryParamsBus_tag
#define struct_SupervisoryParamsBus_tag

struct SupervisoryParamsBus_tag
{
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
};

#endif                                 /*struct_SupervisoryParamsBus_tag*/

#ifndef typedef_c13_SupervisoryParamsBus
#define typedef_c13_SupervisoryParamsBus

typedef struct SupervisoryParamsBus_tag c13_SupervisoryParamsBus;

#endif                                 /*typedef_c13_SupervisoryParamsBus*/

#ifndef struct_ThetaParamsBus_tag
#define struct_ThetaParamsBus_tag

struct ThetaParamsBus_tag
{
  real_T c0;
  real_T ct;
  real_T cq[13];
  real_T t0;
  real_T cz[7];
};

#endif                                 /*struct_ThetaParamsBus_tag*/

#ifndef typedef_c13_ThetaParamsBus
#define typedef_c13_ThetaParamsBus

typedef struct ThetaParamsBus_tag c13_ThetaParamsBus;

#endif                                 /*typedef_c13_ThetaParamsBus*/

#ifndef struct_PhiParamsBus_tag
#define struct_PhiParamsBus_tag

struct PhiParamsBus_tag
{
  real_T c0;
  real_T cq[13];
};

#endif                                 /*struct_PhiParamsBus_tag*/

#ifndef typedef_c13_PhiParamsBus
#define typedef_c13_PhiParamsBus

typedef struct PhiParamsBus_tag c13_PhiParamsBus;

#endif                                 /*typedef_c13_PhiParamsBus*/

#ifndef struct_OutputParamsBus_tag
#define struct_OutputParamsBus_tag

struct OutputParamsBus_tag
{
  real_T H0[78];
  real_T HAlpha[36];
  real_T ThetaLimits[2];
  c13_ThetaParamsBus Theta;
  real_T SaturateS;
  real_T SLimits[2];
  real_T EnforceIncreasingS;
  real_T UseCorrection;
  real_T SMaxCorrection;
  real_T HAlphaCorrection[30];
  c13_PhiParamsBus Phi;
  real_T PhiAlpha[20];
  real_T SaturateR;
  real_T RLimits[2];
  real_T HBarAlpha[30];
  real_T HBarLimits[12];
  real_T HAlphaStar[36];
  real_T YawLimit;
};

#endif                                 /*struct_OutputParamsBus_tag*/

#ifndef typedef_c13_OutputParamsBus
#define typedef_c13_OutputParamsBus

typedef struct OutputParamsBus_tag c13_OutputParamsBus;

#endif                                 /*typedef_c13_OutputParamsBus*/

#ifndef struct_ControlParamsBus_tag
#define struct_ControlParamsBus_tag

struct ControlParamsBus_tag
{
  c13_SupervisoryParamsBus Supervisory;
  c13_DiscreteParamsBus Discrete;
  c13_OutputParamsBus Output;
  c13_FeedbackParamsBus Feedback;
  c13_SaturationParamsBus Saturation;
};

#endif                                 /*struct_ControlParamsBus_tag*/

#ifndef typedef_c13_ControlParamsBus
#define typedef_c13_ControlParamsBus

typedef struct ControlParamsBus_tag c13_ControlParamsBus;

#endif                                 /*typedef_c13_ControlParamsBus*/

#ifndef typedef_SFc13_LibWalkingInstanceStruct
#define typedef_SFc13_LibWalkingInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c13_sfEvent;
  boolean_T c13_isStable;
  boolean_T c13_doneDoubleBufferReInit;
  uint8_T c13_is_active_c13_LibWalking;
  real_T (*c13_u)[6];
  real_T *c13_s;
  real_T (*c13_u_sat)[6];
  real_T (*c13_sat)[2];
  c13_ControlStateBus *c13_ControlState;
  c13_ControlParamsBus *c13_ControlParams;
} SFc13_LibWalkingInstanceStruct;

#endif                                 /*typedef_SFc13_LibWalkingInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c13_LibWalking_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c13_LibWalking_get_check_sum(mxArray *plhs[]);
extern void c13_LibWalking_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
