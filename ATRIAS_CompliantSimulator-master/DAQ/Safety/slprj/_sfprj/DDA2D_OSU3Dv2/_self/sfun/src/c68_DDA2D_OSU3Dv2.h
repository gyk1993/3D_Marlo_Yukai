#ifndef __c68_DDA2D_OSU3Dv2_h__
#define __c68_DDA2D_OSU3Dv2_h__

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

#ifndef typedef_c68_ControlStateBus
#define typedef_c68_ControlStateBus

typedef struct ControlStateBus_tag c68_ControlStateBus;

#endif                                 /*typedef_c68_ControlStateBus*/

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

#ifndef typedef_c68_DiscreteParamsBus
#define typedef_c68_DiscreteParamsBus

typedef struct DiscreteParamsBus_tag c68_DiscreteParamsBus;

#endif                                 /*typedef_c68_DiscreteParamsBus*/

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

#ifndef typedef_c68_FeedbackParamsBus
#define typedef_c68_FeedbackParamsBus

typedef struct FeedbackParamsBus_tag c68_FeedbackParamsBus;

#endif                                 /*typedef_c68_FeedbackParamsBus*/

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

#ifndef typedef_c68_SaturationParamsBus
#define typedef_c68_SaturationParamsBus

typedef struct SaturationParamsBus_tag c68_SaturationParamsBus;

#endif                                 /*typedef_c68_SaturationParamsBus*/

#ifndef struct_sdkYTpticp9PS7Nwke9DxK
#define struct_sdkYTpticp9PS7Nwke9DxK

struct sdkYTpticp9PS7Nwke9DxK
{
  real_T feedforward;
  real_T feedbackOnly;
  real_T saturationTorque;
  real_T saturateTorque;
};

#endif                                 /*struct_sdkYTpticp9PS7Nwke9DxK*/

#ifndef typedef_c68_sdkYTpticp9PS7Nwke9DxK
#define typedef_c68_sdkYTpticp9PS7Nwke9DxK

typedef struct sdkYTpticp9PS7Nwke9DxK c68_sdkYTpticp9PS7Nwke9DxK;

#endif                                 /*typedef_c68_sdkYTpticp9PS7Nwke9DxK*/

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
  real_T dx_cmd;
  real_T ForBackward;
  real_T EnableFrictionID;
  real_T ResetFrictionPosing;
  real_T MoveLegIndex;
  real_T dy_cmd;
  real_T TauDelay;
  real_T TrackFrequency;
  real_T EnablePDControl;
  real_T TorqueAmp;
  real_T hdPosing[6];
};

#endif                                 /*struct_SupervisoryParamsBus_tag*/

#ifndef typedef_c68_SupervisoryParamsBus
#define typedef_c68_SupervisoryParamsBus

typedef struct SupervisoryParamsBus_tag c68_SupervisoryParamsBus;

#endif                                 /*typedef_c68_SupervisoryParamsBus*/

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

#ifndef typedef_c68_ThetaParamsBus
#define typedef_c68_ThetaParamsBus

typedef struct ThetaParamsBus_tag c68_ThetaParamsBus;

#endif                                 /*typedef_c68_ThetaParamsBus*/

#ifndef struct_PhiParamsBus_tag
#define struct_PhiParamsBus_tag

struct PhiParamsBus_tag
{
  real_T c0;
  real_T cq[13];
};

#endif                                 /*struct_PhiParamsBus_tag*/

#ifndef typedef_c68_PhiParamsBus
#define typedef_c68_PhiParamsBus

typedef struct PhiParamsBus_tag c68_PhiParamsBus;

#endif                                 /*typedef_c68_PhiParamsBus*/

#ifndef struct_OutputParamsBus_tag
#define struct_OutputParamsBus_tag

struct OutputParamsBus_tag
{
  real_T H0[78];
  real_T HAlpha[36];
  real_T ThetaLimits[2];
  c68_ThetaParamsBus Theta;
  real_T SaturateS;
  real_T SLimits[2];
  real_T EnforceIncreasingS;
  real_T UseCorrection;
  real_T SMaxCorrection;
  real_T HAlphaCorrection[30];
  c68_PhiParamsBus Phi;
  real_T PhiAlpha[20];
  real_T SaturateR;
  real_T RLimits[2];
  real_T HBarAlpha[30];
  real_T HBarLimits[12];
  real_T HAlphaStar[36];
  real_T YawLimit;
  real_T test;
};

#endif                                 /*struct_OutputParamsBus_tag*/

#ifndef typedef_c68_OutputParamsBus
#define typedef_c68_OutputParamsBus

typedef struct OutputParamsBus_tag c68_OutputParamsBus;

#endif                                 /*typedef_c68_OutputParamsBus*/

#ifndef struct_ControlParamsBus_tag
#define struct_ControlParamsBus_tag

struct ControlParamsBus_tag
{
  c68_SupervisoryParamsBus Supervisory;
  c68_DiscreteParamsBus Discrete;
  c68_OutputParamsBus Output;
  c68_FeedbackParamsBus Feedback;
  c68_SaturationParamsBus Saturation;
};

#endif                                 /*struct_ControlParamsBus_tag*/

#ifndef typedef_c68_ControlParamsBus
#define typedef_c68_ControlParamsBus

typedef struct ControlParamsBus_tag c68_ControlParamsBus;

#endif                                 /*typedef_c68_ControlParamsBus*/

#ifndef typedef_SFc68_DDA2D_OSU3Dv2InstanceStruct
#define typedef_SFc68_DDA2D_OSU3Dv2InstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c68_sfEvent;
  boolean_T c68_isStable;
  boolean_T c68_doneDoubleBufferReInit;
  uint8_T c68_is_active_c68_DDA2D_OSU3Dv2;
  real_T *c68_t;
  real_T (*c68_q)[13];
  real_T (*c68_dq)[13];
  c68_ControlStateBus *c68_ControlState;
  c68_ControlParamsBus *c68_ControlParams;
  real_T (*c68_u)[6];
  real_T (*c68_y)[6];
  real_T (*c68_dy)[6];
  real_T (*c68_hd)[6];
  real_T *c68_s;
  real_T *c68_s_unsaturated;
  real_T *c68_ds;
  real_T *c68_theta;
  real_T *c68_phi;
  real_T *c68_r;
  real_T (*c68_hdbar)[6];
  real_T *c68_D;
  real_T *c68_G;
  real_T *c68_pcm;
  real_T *c68_vcm;
  real_T *c68_sprev;
  real_T (*c68_u_star)[6];
  real_T (*c68_u_pd)[6];
  real_T (*c68_HAlphaDDA)[36];
  real_T (*c68_uDDA)[4];
  real_T (*c68_yDDA)[4];
  real_T (*c68_dyDDA)[4];
  real_T *c68_Tau;
  real_T *c68_dTau;
  boolean_T *c68_isSim;
} SFc68_DDA2D_OSU3Dv2InstanceStruct;

#endif                                 /*typedef_SFc68_DDA2D_OSU3Dv2InstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c68_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);

/* Function Definitions */
extern void sf_c68_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
extern void c68_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void
  *data);

#endif
