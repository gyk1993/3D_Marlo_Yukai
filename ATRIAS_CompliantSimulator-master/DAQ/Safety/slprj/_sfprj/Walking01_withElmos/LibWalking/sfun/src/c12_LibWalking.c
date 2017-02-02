/* Include files */

#include <stddef.h>
#include "blas.h"
#include "LibWalking_sfun.h"
#include "c12_LibWalking.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "LibWalking_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c12_debug_family_names[11] = { "nargin", "nargout",
  "TorqueSaturationLimits", "y", "dy", "s", "ControlState", "ControlParams",
  "ErrorCountIn", "Error", "ErrorCount" };

/* Function Declarations */
static void initialize_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance);
static void initialize_params_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance);
static void enable_c12_LibWalking(SFc12_LibWalkingInstanceStruct *chartInstance);
static void disable_c12_LibWalking(SFc12_LibWalkingInstanceStruct *chartInstance);
static void c12_update_debugger_state_c12_LibWalking
  (SFc12_LibWalkingInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c12_LibWalking
  (SFc12_LibWalkingInstanceStruct *chartInstance);
static void set_sim_state_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_st);
static void finalize_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance);
static void sf_gateway_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance);
static void mdl_start_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance);
static void c12_chartstep_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance);
static void initSimStructsc12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber);
static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static real_T c12_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c12_b_ErrorCount, const char_T *c12_identifier);
static real_T c12_b_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static boolean_T c12_c_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_b_Error, const char_T *c12_identifier);
static boolean_T c12_d_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static void c12_info_helper(const mxArray **c12_info);
static const mxArray *c12_emlrt_marshallOut(const char * c12_u);
static const mxArray *c12_b_emlrt_marshallOut(const uint32_T c12_u);
static real_T c12_norm(SFc12_LibWalkingInstanceStruct *chartInstance, real_T
  c12_x[6]);
static const mxArray *c12_g_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData);
static int32_T c12_e_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData);
static const mxArray *c12_ControlState_bus_io(void *chartInstanceVoid, void
  *c12_pData);
static const mxArray *c12_ControlParams_bus_io(void *chartInstanceVoid, void
  *c12_pData);
static uint8_T c12_f_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_LibWalking, const char_T
  *c12_identifier);
static uint8_T c12_g_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId);
static void init_dsm_address_info(SFc12_LibWalkingInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc12_LibWalkingInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance)
{
  chartInstance->c12_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c12_is_active_c12_LibWalking = 0U;
}

static void initialize_params_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c12_LibWalking(SFc12_LibWalkingInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c12_LibWalking(SFc12_LibWalkingInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c12_update_debugger_state_c12_LibWalking
  (SFc12_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c12_LibWalking
  (SFc12_LibWalkingInstanceStruct *chartInstance)
{
  const mxArray *c12_st;
  const mxArray *c12_b_y = NULL;
  boolean_T c12_hoistedGlobal;
  boolean_T c12_u;
  const mxArray *c12_c_y = NULL;
  real_T c12_b_hoistedGlobal;
  real_T c12_b_u;
  const mxArray *c12_d_y = NULL;
  uint8_T c12_c_hoistedGlobal;
  uint8_T c12_c_u;
  const mxArray *c12_e_y = NULL;
  c12_st = NULL;
  c12_st = NULL;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_createcellmatrix(3, 1), false);
  c12_hoistedGlobal = *chartInstance->c12_Error;
  c12_u = c12_hoistedGlobal;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_b_y, 0, c12_c_y);
  c12_b_hoistedGlobal = *chartInstance->c12_ErrorCount;
  c12_b_u = c12_b_hoistedGlobal;
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_b_y, 1, c12_d_y);
  c12_c_hoistedGlobal = chartInstance->c12_is_active_c12_LibWalking;
  c12_c_u = c12_c_hoistedGlobal;
  c12_e_y = NULL;
  sf_mex_assign(&c12_e_y, sf_mex_create("y", &c12_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c12_b_y, 2, c12_e_y);
  sf_mex_assign(&c12_st, c12_b_y, false);
  return c12_st;
}

static void set_sim_state_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_st)
{
  const mxArray *c12_u;
  chartInstance->c12_doneDoubleBufferReInit = true;
  c12_u = sf_mex_dup(c12_st);
  *chartInstance->c12_Error = c12_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c12_u, 0)), "Error");
  *chartInstance->c12_ErrorCount = c12_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c12_u, 1)), "ErrorCount");
  chartInstance->c12_is_active_c12_LibWalking = c12_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c12_u, 2)),
     "is_active_c12_LibWalking");
  sf_mex_destroy(&c12_u);
  c12_update_debugger_state_c12_LibWalking(chartInstance);
  sf_mex_destroy(&c12_st);
}

static void finalize_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance)
{
  int32_T c12_i0;
  int32_T c12_i1;
  int32_T c12_i2;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c12_sfEvent);
  for (c12_i0 = 0; c12_i0 < 2; c12_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c12_TorqueSaturationLimits)[c12_i0],
                          0U);
  }

  for (c12_i1 = 0; c12_i1 < 6; c12_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c12_y)[c12_i1], 1U);
  }

  for (c12_i2 = 0; c12_i2 < 6; c12_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c12_dy)[c12_i2], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_s, 3U);
  chartInstance->c12_sfEvent = CALL_EVENT;
  c12_chartstep_c12_LibWalking(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_LibWalkingMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c12_Error, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_ErrorCount, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c12_ErrorCountIn, 8U);
}

static void mdl_start_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c12_chartstep_c12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance)
{
  real_T c12_hoistedGlobal;
  real_T c12_b_hoistedGlobal;
  int32_T c12_i3;
  real_T c12_b_TorqueSaturationLimits[2];
  int32_T c12_i4;
  real_T c12_b_y[6];
  int32_T c12_i5;
  real_T c12_b_dy[6];
  real_T c12_b_s;
  c12_ControlStateBus c12_b_ControlState;
  c12_ControlParamsBus c12_b_ControlParams;
  int32_T c12_i6;
  int32_T c12_i7;
  int32_T c12_i8;
  int32_T c12_i9;
  int32_T c12_i10;
  int32_T c12_i11;
  int32_T c12_i12;
  int32_T c12_i13;
  int32_T c12_i14;
  int32_T c12_i15;
  int32_T c12_i16;
  int32_T c12_i17;
  int32_T c12_i18;
  int32_T c12_i19;
  int32_T c12_i20;
  int32_T c12_i21;
  int32_T c12_i22;
  int32_T c12_i23;
  int32_T c12_i24;
  int32_T c12_i25;
  int32_T c12_i26;
  int32_T c12_i27;
  int32_T c12_i28;
  int32_T c12_i29;
  int32_T c12_i30;
  int32_T c12_i31;
  int32_T c12_i32;
  int32_T c12_i33;
  int32_T c12_i34;
  int32_T c12_i35;
  int32_T c12_i36;
  int32_T c12_i37;
  int32_T c12_i38;
  int32_T c12_i39;
  int32_T c12_i40;
  int32_T c12_i41;
  int32_T c12_i42;
  int32_T c12_i43;
  int32_T c12_i44;
  int32_T c12_i45;
  int32_T c12_i46;
  int32_T c12_i47;
  int32_T c12_i48;
  int32_T c12_i49;
  int32_T c12_i50;
  int32_T c12_i51;
  int32_T c12_i52;
  real_T c12_b_ErrorCountIn;
  uint32_T c12_debug_family_var_map[11];
  real_T c12_nargin = 7.0;
  real_T c12_nargout = 2.0;
  boolean_T c12_b_Error;
  real_T c12_b_ErrorCount;
  int32_T c12_i53;
  boolean_T c12_x[2];
  boolean_T c12_c_y;
  int32_T c12_k;
  real_T c12_b_k;
  int32_T c12_i54;
  real_T c12_d_y[6];
  real_T c12_d0;
  real_T c12_A;
  real_T c12_b_x;
  real_T c12_c_x;
  real_T c12_d_x;
  real_T c12_d1;
  int32_T c12_i55;
  real_T c12_c_dy[6];
  real_T c12_d2;
  real_T c12_b_A;
  real_T c12_e_x;
  real_T c12_f_x;
  real_T c12_g_x;
  real_T c12_d3;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T exitg1;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c12_sfEvent);
  c12_hoistedGlobal = *chartInstance->c12_s;
  c12_b_hoistedGlobal = *chartInstance->c12_ErrorCountIn;
  for (c12_i3 = 0; c12_i3 < 2; c12_i3++) {
    c12_b_TorqueSaturationLimits[c12_i3] =
      (*chartInstance->c12_TorqueSaturationLimits)[c12_i3];
  }

  for (c12_i4 = 0; c12_i4 < 6; c12_i4++) {
    c12_b_y[c12_i4] = (*chartInstance->c12_y)[c12_i4];
  }

  for (c12_i5 = 0; c12_i5 < 6; c12_i5++) {
    c12_b_dy[c12_i5] = (*chartInstance->c12_dy)[c12_i5];
  }

  c12_b_s = c12_hoistedGlobal;
  c12_b_ControlState.ControllerMode = *(real_T *)&((char_T *)
    chartInstance->c12_ControlState)[0];
  c12_b_ControlState.SupportState = *(real_T *)&((char_T *)
    chartInstance->c12_ControlState)[8];
  c12_b_ControlState.StanceLeg = *(real_T *)&((char_T *)
    chartInstance->c12_ControlState)[16];
  c12_b_ControlState.InDoubleSupport = *(real_T *)&((char_T *)
    chartInstance->c12_ControlState)[24];
  c12_b_ControlState.RollPhase = *(real_T *)&((char_T *)
    chartInstance->c12_ControlState)[32];
  c12_b_ControlState.StepCount = *(real_T *)&((char_T *)
    chartInstance->c12_ControlState)[40];
  c12_b_ControlState.Error = *(real_T *)&((char_T *)
    chartInstance->c12_ControlState)[48];
  c12_b_ControlParams.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [0];
  c12_b_ControlParams.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [8];
  c12_b_ControlParams.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [16];
  c12_b_ControlParams.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [24];
  c12_b_ControlParams.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)
    &((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c12_ControlParams)[0])[32];
  c12_b_ControlParams.Supervisory.ImpactThresholdKASpringRel = *(real_T *)
    &((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c12_ControlParams)[0])[40];
  c12_b_ControlParams.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [48];
  c12_b_ControlParams.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [56];
  c12_b_ControlParams.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [64];
  c12_b_ControlParams.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [72];
  c12_b_ControlParams.Supervisory.TransitionThresholdTorsoVel = *(real_T *)
    &((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c12_ControlParams)[0])[80];
  for (c12_i6 = 0; c12_i6 < 2; c12_i6++) {
    c12_b_ControlParams.Supervisory.KAInjection[c12_i6] = ((real_T *)&((char_T *)
      (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
      [0])[88])[c12_i6];
  }

  c12_b_ControlParams.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T
    *)(c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
    [0])[104];
  c12_b_ControlParams.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [112];
  for (c12_i7 = 0; c12_i7 < 6; c12_i7++) {
    c12_b_ControlParams.Supervisory.VBLAParams[c12_i7] = ((real_T *)&((char_T *)
      (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
      [0])[120])[c12_i7];
  }

  for (c12_i8 = 0; c12_i8 < 13; c12_i8++) {
    c12_b_ControlParams.Supervisory.BalanceParams[c12_i8] = ((real_T *)&((char_T
      *)(c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
      [0])[168])[c12_i8];
  }

  for (c12_i9 = 0; c12_i9 < 5; c12_i9++) {
    c12_b_ControlParams.Supervisory.GaitTweaks[c12_i9] = ((real_T *)&((char_T *)
      (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
      [0])[272])[c12_i9];
  }

  c12_b_ControlParams.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [312];
  c12_b_ControlParams.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [320];
  c12_b_ControlParams.Supervisory.RunMode = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [328];
  c12_b_ControlParams.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [336];
  for (c12_i10 = 0; c12_i10 < 6; c12_i10++) {
    c12_b_ControlParams.Supervisory.ErrorZeroFactor[c12_i10] = ((real_T *)
      &((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c12_ControlParams)[0])[344])[c12_i10];
  }

  for (c12_i11 = 0; c12_i11 < 6; c12_i11++) {
    c12_b_ControlParams.Supervisory.ErrorVelZeroFactor[c12_i11] = ((real_T *)
      &((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c12_ControlParams)[0])[392])[c12_i11];
  }

  c12_b_ControlParams.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [440];
  c12_b_ControlParams.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [448];
  c12_b_ControlParams.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [456];
  c12_b_ControlParams.Supervisory.TPosing = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [464];
  c12_b_ControlParams.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [472];
  c12_b_ControlParams.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [480];
  c12_b_ControlParams.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [488];
  c12_b_ControlParams.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [496];
  c12_b_ControlParams.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T
    *)(c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
    [0])[504];
  c12_b_ControlParams.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T
    *)(c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
    [0])[512];
  c12_b_ControlParams.Supervisory.VelocityControlTorsoGain = *(real_T *)
    &((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c12_ControlParams)[0])[520];
  c12_b_ControlParams.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [528];
  c12_b_ControlParams.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [536];
  c12_b_ControlParams.Supervisory.Theta0 = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [544];
  c12_b_ControlParams.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [552];
  c12_b_ControlParams.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [560];
  c12_b_ControlParams.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T
    *)(c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
    [0])[568];
  c12_b_ControlParams.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [576];
  c12_b_ControlParams.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [584];
  c12_b_ControlParams.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [592];
  c12_b_ControlParams.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [600];
  for (c12_i12 = 0; c12_i12 < 6; c12_i12++) {
    c12_b_ControlParams.Supervisory.K1MidStanceUpdate[c12_i12] = ((real_T *)
      &((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c12_ControlParams)[0])[608])[c12_i12];
  }

  for (c12_i13 = 0; c12_i13 < 6; c12_i13++) {
    c12_b_ControlParams.Supervisory.K2MidStanceUpdate[c12_i13] = ((real_T *)
      &((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c12_ControlParams)[0])[656])[c12_i13];
  }

  c12_b_ControlParams.Supervisory.EnableVelocityBasedUpdate = *(real_T *)
    &((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c12_ControlParams)[0])[704];
  for (c12_i14 = 0; c12_i14 < 6; c12_i14++) {
    c12_b_ControlParams.Supervisory.VelocityBasedUpdateK1[c12_i14] = ((real_T *)
      &((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c12_ControlParams)[0])[712])[c12_i14];
  }

  for (c12_i15 = 0; c12_i15 < 6; c12_i15++) {
    c12_b_ControlParams.Supervisory.VelocityBasedUpdateK2[c12_i15] = ((real_T *)
      &((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c12_ControlParams)[0])[760])[c12_i15];
  }

  c12_b_ControlParams.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)
    &((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c12_ControlParams)[0])[808];
  c12_i16 = 0;
  for (c12_i17 = 0; c12_i17 < 2; c12_i17++) {
    for (c12_i18 = 0; c12_i18 < 6; c12_i18++) {
      c12_b_ControlParams.Supervisory.VelocityBasedUpdateLimits[c12_i18 +
        c12_i16] = ((real_T *)&((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
        chartInstance->c12_ControlParams)[0])[816])[c12_i18 + c12_i16];
    }

    c12_i16 += 6;
  }

  c12_b_ControlParams.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[0])
    [912];
  c12_b_ControlParams.Discrete.TLastUpdate = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[920])
    [0];
  c12_b_ControlParams.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[920])
    [8];
  c12_b_ControlParams.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[920])
    [16];
  c12_b_ControlParams.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[920])
    [24];
  c12_b_ControlParams.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T
    *)(c12_DiscreteParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[920])
    [32];
  c12_b_ControlParams.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[920])
    [40];
  c12_b_ControlParams.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[920])
    [48];
  c12_b_ControlParams.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[920])
    [56];
  c12_b_ControlParams.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[920])
    [64];
  c12_b_ControlParams.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[920])
    [72];
  c12_b_ControlParams.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[920])
    [80];
  c12_i19 = 0;
  for (c12_i20 = 0; c12_i20 < 13; c12_i20++) {
    for (c12_i21 = 0; c12_i21 < 6; c12_i21++) {
      c12_b_ControlParams.Output.H0[c12_i21 + c12_i19] = ((real_T *)&((char_T *)
        (c12_OutputParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
        [1008])[0])[c12_i21 + c12_i19];
    }

    c12_i19 += 6;
  }

  c12_i22 = 0;
  for (c12_i23 = 0; c12_i23 < 6; c12_i23++) {
    for (c12_i24 = 0; c12_i24 < 6; c12_i24++) {
      c12_b_ControlParams.Output.HAlpha[c12_i24 + c12_i22] = ((real_T *)
        &((char_T *)(c12_OutputParamsBus *)&((char_T *)
        chartInstance->c12_ControlParams)[1008])[624])[c12_i24 + c12_i22];
    }

    c12_i22 += 6;
  }

  for (c12_i25 = 0; c12_i25 < 2; c12_i25++) {
    c12_b_ControlParams.Output.ThetaLimits[c12_i25] = ((real_T *)&((char_T *)
      (c12_OutputParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[1008])
      [912])[c12_i25];
  }

  c12_b_ControlParams.Output.Theta.c0 = *(real_T *)&((char_T *)
    (c12_ThetaParamsBus *)&((char_T *)(c12_OutputParamsBus *)&((char_T *)
    chartInstance->c12_ControlParams)[1008])[928])[0];
  c12_b_ControlParams.Output.Theta.ct = *(real_T *)&((char_T *)
    (c12_ThetaParamsBus *)&((char_T *)(c12_OutputParamsBus *)&((char_T *)
    chartInstance->c12_ControlParams)[1008])[928])[8];
  for (c12_i26 = 0; c12_i26 < 13; c12_i26++) {
    c12_b_ControlParams.Output.Theta.cq[c12_i26] = ((real_T *)&((char_T *)
      (c12_ThetaParamsBus *)&((char_T *)(c12_OutputParamsBus *)&((char_T *)
      chartInstance->c12_ControlParams)[1008])[928])[16])[c12_i26];
  }

  c12_b_ControlParams.Output.Theta.t0 = *(real_T *)&((char_T *)
    (c12_ThetaParamsBus *)&((char_T *)(c12_OutputParamsBus *)&((char_T *)
    chartInstance->c12_ControlParams)[1008])[928])[120];
  for (c12_i27 = 0; c12_i27 < 7; c12_i27++) {
    c12_b_ControlParams.Output.Theta.cz[c12_i27] = ((real_T *)&((char_T *)
      (c12_ThetaParamsBus *)&((char_T *)(c12_OutputParamsBus *)&((char_T *)
      chartInstance->c12_ControlParams)[1008])[928])[128])[c12_i27];
  }

  c12_b_ControlParams.Output.SaturateS = *(real_T *)&((char_T *)
    (c12_OutputParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[1008])
    [1112];
  for (c12_i28 = 0; c12_i28 < 2; c12_i28++) {
    c12_b_ControlParams.Output.SLimits[c12_i28] = ((real_T *)&((char_T *)
      (c12_OutputParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[1008])
      [1120])[c12_i28];
  }

  c12_b_ControlParams.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c12_OutputParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[1008])
    [1136];
  c12_b_ControlParams.Output.UseCorrection = *(real_T *)&((char_T *)
    (c12_OutputParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[1008])
    [1144];
  c12_b_ControlParams.Output.SMaxCorrection = *(real_T *)&((char_T *)
    (c12_OutputParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[1008])
    [1152];
  c12_i29 = 0;
  for (c12_i30 = 0; c12_i30 < 5; c12_i30++) {
    for (c12_i31 = 0; c12_i31 < 6; c12_i31++) {
      c12_b_ControlParams.Output.HAlphaCorrection[c12_i31 + c12_i29] = ((real_T *)
        &((char_T *)(c12_OutputParamsBus *)&((char_T *)
        chartInstance->c12_ControlParams)[1008])[1160])[c12_i31 + c12_i29];
    }

    c12_i29 += 6;
  }

  c12_b_ControlParams.Output.Phi.c0 = *(real_T *)&((char_T *)(c12_PhiParamsBus *)
    &((char_T *)(c12_OutputParamsBus *)&((char_T *)
    chartInstance->c12_ControlParams)[1008])[1400])[0];
  for (c12_i32 = 0; c12_i32 < 13; c12_i32++) {
    c12_b_ControlParams.Output.Phi.cq[c12_i32] = ((real_T *)&((char_T *)
      (c12_PhiParamsBus *)&((char_T *)(c12_OutputParamsBus *)&((char_T *)
      chartInstance->c12_ControlParams)[1008])[1400])[8])[c12_i32];
  }

  for (c12_i33 = 0; c12_i33 < 20; c12_i33++) {
    c12_b_ControlParams.Output.PhiAlpha[c12_i33] = ((real_T *)&((char_T *)
      (c12_OutputParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[1008])
      [1512])[c12_i33];
  }

  c12_b_ControlParams.Output.SaturateR = *(real_T *)&((char_T *)
    (c12_OutputParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[1008])
    [1672];
  for (c12_i34 = 0; c12_i34 < 2; c12_i34++) {
    c12_b_ControlParams.Output.RLimits[c12_i34] = ((real_T *)&((char_T *)
      (c12_OutputParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[1008])
      [1680])[c12_i34];
  }

  c12_i35 = 0;
  for (c12_i36 = 0; c12_i36 < 5; c12_i36++) {
    for (c12_i37 = 0; c12_i37 < 6; c12_i37++) {
      c12_b_ControlParams.Output.HBarAlpha[c12_i37 + c12_i35] = ((real_T *)
        &((char_T *)(c12_OutputParamsBus *)&((char_T *)
        chartInstance->c12_ControlParams)[1008])[1696])[c12_i37 + c12_i35];
    }

    c12_i35 += 6;
  }

  c12_i38 = 0;
  for (c12_i39 = 0; c12_i39 < 2; c12_i39++) {
    for (c12_i40 = 0; c12_i40 < 6; c12_i40++) {
      c12_b_ControlParams.Output.HBarLimits[c12_i40 + c12_i38] = ((real_T *)
        &((char_T *)(c12_OutputParamsBus *)&((char_T *)
        chartInstance->c12_ControlParams)[1008])[1936])[c12_i40 + c12_i38];
    }

    c12_i38 += 6;
  }

  c12_i41 = 0;
  for (c12_i42 = 0; c12_i42 < 6; c12_i42++) {
    for (c12_i43 = 0; c12_i43 < 6; c12_i43++) {
      c12_b_ControlParams.Output.HAlphaStar[c12_i43 + c12_i41] = ((real_T *)
        &((char_T *)(c12_OutputParamsBus *)&((char_T *)
        chartInstance->c12_ControlParams)[1008])[2032])[c12_i43 + c12_i41];
    }

    c12_i41 += 6;
  }

  c12_b_ControlParams.Output.YawLimit = *(real_T *)&((char_T *)
    (c12_OutputParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[1008])
    [2320];
  for (c12_i44 = 0; c12_i44 < 6; c12_i44++) {
    c12_b_ControlParams.Feedback.kp[c12_i44] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
      [3336])[0])[c12_i44];
  }

  for (c12_i45 = 0; c12_i45 < 6; c12_i45++) {
    c12_b_ControlParams.Feedback.kd[c12_i45] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
      [3336])[48])[c12_i45];
  }

  for (c12_i46 = 0; c12_i46 < 2; c12_i46++) {
    c12_b_ControlParams.Feedback.epsilon[c12_i46] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
      [3336])[96])[c12_i46];
  }

  for (c12_i47 = 0; c12_i47 < 2; c12_i47++) {
    c12_b_ControlParams.Feedback.kff_grav[c12_i47] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
      [3336])[112])[c12_i47];
  }

  c12_b_ControlParams.Feedback.delta_grav = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [128];
  for (c12_i48 = 0; c12_i48 < 2; c12_i48++) {
    c12_b_ControlParams.Feedback.kff_decoup[c12_i48] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
      [3336])[136])[c12_i48];
  }

  for (c12_i49 = 0; c12_i49 < 2; c12_i49++) {
    c12_b_ControlParams.Feedback.kd_torso[c12_i49] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
      [3336])[152])[c12_i49];
  }

  c12_b_ControlParams.Feedback.kp_2dof = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [168];
  c12_b_ControlParams.Feedback.kd_2dof = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [176];
  c12_b_ControlParams.Feedback.kpre_2dof = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [184];
  c12_b_ControlParams.Feedback.kp_lat = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [192];
  c12_b_ControlParams.Feedback.kd_lat = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [200];
  c12_b_ControlParams.Feedback.q3d_min_lat = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [208];
  c12_b_ControlParams.Feedback.q3d_max_lat = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [216];
  c12_b_ControlParams.Feedback.w_torso_lat = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [224];
  for (c12_i50 = 0; c12_i50 < 6; c12_i50++) {
    c12_b_ControlParams.Feedback.u_ff[c12_i50] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
      [3336])[232])[c12_i50];
  }

  c12_b_ControlParams.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [280];
  c12_b_ControlParams.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [288];
  c12_b_ControlParams.Feedback.Use2DOF = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [296];
  c12_b_ControlParams.Feedback.UseDSGravComp = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [304];
  c12_b_ControlParams.Feedback.lat_bias = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [312];
  c12_b_ControlParams.Feedback.lat_bias2 = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [320];
  c12_b_ControlParams.Feedback.linkFeedback = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [328];
  c12_b_ControlParams.Feedback.RIO = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [336];
  c12_b_ControlParams.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [344];
  for (c12_i51 = 0; c12_i51 < 6; c12_i51++) {
    c12_b_ControlParams.Feedback.FeedforwardGain[c12_i51] = ((real_T *)&((char_T
      *)(c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
      [3336])[352])[c12_i51];
  }

  c12_b_ControlParams.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)chartInstance->c12_ControlParams)[3336])
    [400];
  c12_b_ControlParams.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c12_SaturationParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
    [3744])[0];
  for (c12_i52 = 0; c12_i52 < 2; c12_i52++) {
    c12_b_ControlParams.Saturation.QPWeight[c12_i52] = ((real_T *)&((char_T *)
      (c12_SaturationParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
      [3744])[8])[c12_i52];
  }

  c12_b_ControlParams.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c12_SaturationParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
    [3744])[24];
  c12_b_ControlParams.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c12_SaturationParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
    [3744])[32];
  c12_b_ControlParams.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c12_SaturationParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
    [3744])[40];
  c12_b_ControlParams.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c12_SaturationParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
    [3744])[48];
  c12_b_ControlParams.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c12_SaturationParamsBus *)&((char_T *)chartInstance->c12_ControlParams)
    [3744])[56];
  c12_b_ErrorCountIn = c12_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c12_debug_family_names,
    c12_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargin, 0U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_nargout, 1U, c12_sf_marshallOut,
    c12_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c12_b_TorqueSaturationLimits, 2U,
    c12_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c12_b_y, 3U, c12_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c12_b_dy, 4U, c12_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_s, 5U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_ControlState, 6U, c12_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_ControlParams, 7U, c12_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c12_b_ErrorCountIn, 8U, c12_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_Error, 9U, c12_b_sf_marshallOut,
    c12_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c12_b_ErrorCount, 10U,
    c12_sf_marshallOut, c12_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 4);
  c12_b_ErrorCount = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 6);
  for (c12_i53 = 0; c12_i53 < 2; c12_i53++) {
    c12_x[c12_i53] = (c12_b_TorqueSaturationLimits[c12_i53] > 1.0);
  }

  c12_c_y = true;
  c12_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c12_k < 2)) {
    c12_b_k = 1.0 + (real_T)c12_k;
    if ((real_T)c12_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
         _SFD_INTEGER_CHECK("", c12_b_k), 1, 2, 1, 0) - 1] == 0.0) {
      c12_c_y = false;
      exitg1 = true;
    } else {
      c12_k++;
    }
  }

  guard1 = false;
  guard2 = false;
  if (CV_EML_COND(0, 1, 0, c12_c_y)) {
    for (c12_i54 = 0; c12_i54 < 6; c12_i54++) {
      c12_d_y[c12_i54] = c12_b_y[c12_i54];
    }

    c12_d0 = c12_norm(chartInstance, c12_d_y);
    c12_A = c12_b_ControlParams.Supervisory.MaxError * 3.1415926535897931;
    c12_b_x = c12_A;
    c12_c_x = c12_b_x;
    c12_d_x = c12_c_x;
    c12_d1 = c12_d_x / 180.0;
    if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 0, c12_d0, c12_d1, -1,
          4U, c12_d0 > c12_d1))) {
      guard2 = true;
    } else {
      for (c12_i55 = 0; c12_i55 < 6; c12_i55++) {
        c12_c_dy[c12_i55] = c12_b_dy[c12_i55];
      }

      c12_d2 = c12_norm(chartInstance, c12_c_dy);
      c12_b_A = c12_b_ControlParams.Supervisory.MaxErrorVel * 3.1415926535897931;
      c12_e_x = c12_b_A;
      c12_f_x = c12_e_x;
      c12_g_x = c12_f_x;
      c12_d3 = c12_g_x / 180.0;
      if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 1, c12_d2, c12_d3, -1,
            4U, c12_d2 > c12_d3))) {
        guard2 = true;
      } else {
        guard1 = true;
      }
    }
  } else {
    guard1 = true;
  }

  if (guard2 == true) {
    CV_EML_MCDC(0, 1, 0, true);
    CV_EML_IF(0, 1, 0, true);
    _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 10);
    c12_b_ErrorCount = c12_b_ErrorCountIn + 1.0;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, 12);
  c12_b_Error = (c12_b_ErrorCount >
                 c12_b_ControlParams.Supervisory.MaxErrorCount);
  _SFD_EML_CALL(0U, chartInstance->c12_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c12_Error = c12_b_Error;
  *chartInstance->c12_ErrorCount = c12_b_ErrorCount;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c12_sfEvent);
}

static void initSimStructsc12_LibWalking(SFc12_LibWalkingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c12_machineNumber, uint32_T
  c12_chartNumber, uint32_T c12_instanceNumber)
{
  (void)c12_machineNumber;
  (void)c12_chartNumber;
  (void)c12_instanceNumber;
}

static const mxArray *c12_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  real_T c12_u;
  const mxArray *c12_b_y = NULL;
  SFc12_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc12_LibWalkingInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(real_T *)c12_inData;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_b_y, false);
  return c12_mxArrayOutData;
}

static real_T c12_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c12_b_ErrorCount, const char_T *c12_identifier)
{
  real_T c12_b_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_ErrorCount),
    &c12_thisId);
  sf_mex_destroy(&c12_b_ErrorCount);
  return c12_b_y;
}

static real_T c12_b_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  real_T c12_b_y;
  real_T c12_d4;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_d4, 1, 0, 0U, 0, 0U, 0);
  c12_b_y = c12_d4;
  sf_mex_destroy(&c12_u);
  return c12_b_y;
}

static void c12_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_ErrorCount;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  real_T c12_b_y;
  SFc12_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc12_LibWalkingInstanceStruct *)chartInstanceVoid;
  c12_b_ErrorCount = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_y = c12_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_ErrorCount),
    &c12_thisId);
  sf_mex_destroy(&c12_b_ErrorCount);
  *(real_T *)c12_outData = c12_b_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_b_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  boolean_T c12_u;
  const mxArray *c12_b_y = NULL;
  SFc12_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc12_LibWalkingInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(boolean_T *)c12_inData;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_b_y, false);
  return c12_mxArrayOutData;
}

static boolean_T c12_c_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_b_Error, const char_T *c12_identifier)
{
  boolean_T c12_b_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_y = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_Error),
    &c12_thisId);
  sf_mex_destroy(&c12_b_Error);
  return c12_b_y;
}

static boolean_T c12_d_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  boolean_T c12_b_y;
  boolean_T c12_b0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_b0, 1, 11, 0U, 0, 0U, 0);
  c12_b_y = c12_b0;
  sf_mex_destroy(&c12_u);
  return c12_b_y;
}

static void c12_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_Error;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  boolean_T c12_b_y;
  SFc12_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc12_LibWalkingInstanceStruct *)chartInstanceVoid;
  c12_b_Error = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_y = c12_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_Error),
    &c12_thisId);
  sf_mex_destroy(&c12_b_Error);
  *(boolean_T *)c12_outData = c12_b_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_c_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData;
  c12_ControlParamsBus c12_u;
  const mxArray *c12_b_y = NULL;
  c12_SupervisoryParamsBus c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T c12_c_u;
  const mxArray *c12_d_y = NULL;
  real_T c12_d_u;
  const mxArray *c12_e_y = NULL;
  real_T c12_e_u;
  const mxArray *c12_f_y = NULL;
  real_T c12_f_u;
  const mxArray *c12_g_y = NULL;
  real_T c12_g_u;
  const mxArray *c12_h_y = NULL;
  real_T c12_h_u;
  const mxArray *c12_i_y = NULL;
  real_T c12_i_u;
  const mxArray *c12_j_y = NULL;
  real_T c12_j_u;
  const mxArray *c12_k_y = NULL;
  real_T c12_k_u;
  const mxArray *c12_l_y = NULL;
  real_T c12_l_u;
  const mxArray *c12_m_y = NULL;
  real_T c12_m_u;
  const mxArray *c12_n_y = NULL;
  int32_T c12_i56;
  real_T c12_n_u[2];
  const mxArray *c12_o_y = NULL;
  real_T c12_o_u;
  const mxArray *c12_p_y = NULL;
  real_T c12_p_u;
  const mxArray *c12_q_y = NULL;
  int32_T c12_i57;
  real_T c12_q_u[6];
  const mxArray *c12_r_y = NULL;
  int32_T c12_i58;
  real_T c12_r_u[13];
  const mxArray *c12_s_y = NULL;
  int32_T c12_i59;
  real_T c12_s_u[5];
  const mxArray *c12_t_y = NULL;
  real_T c12_t_u;
  const mxArray *c12_u_y = NULL;
  real_T c12_u_u;
  const mxArray *c12_v_y = NULL;
  real_T c12_v_u;
  const mxArray *c12_w_y = NULL;
  real_T c12_w_u;
  const mxArray *c12_x_y = NULL;
  int32_T c12_i60;
  real_T c12_x_u[6];
  const mxArray *c12_y_y = NULL;
  int32_T c12_i61;
  real_T c12_y_u[6];
  const mxArray *c12_ab_y = NULL;
  real_T c12_ab_u;
  const mxArray *c12_bb_y = NULL;
  real_T c12_bb_u;
  const mxArray *c12_cb_y = NULL;
  real_T c12_cb_u;
  const mxArray *c12_db_y = NULL;
  real_T c12_db_u;
  const mxArray *c12_eb_y = NULL;
  real_T c12_eb_u;
  const mxArray *c12_fb_y = NULL;
  real_T c12_fb_u;
  const mxArray *c12_gb_y = NULL;
  real_T c12_gb_u;
  const mxArray *c12_hb_y = NULL;
  real_T c12_hb_u;
  const mxArray *c12_ib_y = NULL;
  real_T c12_ib_u;
  const mxArray *c12_jb_y = NULL;
  real_T c12_jb_u;
  const mxArray *c12_kb_y = NULL;
  real_T c12_kb_u;
  const mxArray *c12_lb_y = NULL;
  real_T c12_lb_u;
  const mxArray *c12_mb_y = NULL;
  real_T c12_mb_u;
  const mxArray *c12_nb_y = NULL;
  real_T c12_nb_u;
  const mxArray *c12_ob_y = NULL;
  real_T c12_ob_u;
  const mxArray *c12_pb_y = NULL;
  real_T c12_pb_u;
  const mxArray *c12_qb_y = NULL;
  real_T c12_qb_u;
  const mxArray *c12_rb_y = NULL;
  real_T c12_rb_u;
  const mxArray *c12_sb_y = NULL;
  real_T c12_sb_u;
  const mxArray *c12_tb_y = NULL;
  real_T c12_tb_u;
  const mxArray *c12_ub_y = NULL;
  real_T c12_ub_u;
  const mxArray *c12_vb_y = NULL;
  int32_T c12_i62;
  real_T c12_vb_u[6];
  const mxArray *c12_wb_y = NULL;
  int32_T c12_i63;
  real_T c12_wb_u[6];
  const mxArray *c12_xb_y = NULL;
  real_T c12_xb_u;
  const mxArray *c12_yb_y = NULL;
  int32_T c12_i64;
  real_T c12_yb_u[6];
  const mxArray *c12_ac_y = NULL;
  int32_T c12_i65;
  real_T c12_ac_u[6];
  const mxArray *c12_bc_y = NULL;
  real_T c12_bc_u;
  const mxArray *c12_cc_y = NULL;
  int32_T c12_i66;
  real_T c12_cc_u[12];
  const mxArray *c12_dc_y = NULL;
  real_T c12_dc_u;
  const mxArray *c12_ec_y = NULL;
  c12_DiscreteParamsBus c12_ec_u;
  const mxArray *c12_fc_y = NULL;
  real_T c12_fc_u;
  const mxArray *c12_gc_y = NULL;
  real_T c12_gc_u;
  const mxArray *c12_hc_y = NULL;
  real_T c12_hc_u;
  const mxArray *c12_ic_y = NULL;
  real_T c12_ic_u;
  const mxArray *c12_jc_y = NULL;
  real_T c12_jc_u;
  const mxArray *c12_kc_y = NULL;
  real_T c12_kc_u;
  const mxArray *c12_lc_y = NULL;
  real_T c12_lc_u;
  const mxArray *c12_mc_y = NULL;
  real_T c12_mc_u;
  const mxArray *c12_nc_y = NULL;
  real_T c12_nc_u;
  const mxArray *c12_oc_y = NULL;
  real_T c12_oc_u;
  const mxArray *c12_pc_y = NULL;
  real_T c12_pc_u;
  const mxArray *c12_qc_y = NULL;
  c12_OutputParamsBus c12_qc_u;
  const mxArray *c12_rc_y = NULL;
  int32_T c12_i67;
  real_T c12_rc_u[78];
  const mxArray *c12_sc_y = NULL;
  int32_T c12_i68;
  real_T c12_sc_u[36];
  const mxArray *c12_tc_y = NULL;
  int32_T c12_i69;
  real_T c12_tc_u[2];
  const mxArray *c12_uc_y = NULL;
  c12_ThetaParamsBus c12_uc_u;
  const mxArray *c12_vc_y = NULL;
  real_T c12_vc_u;
  const mxArray *c12_wc_y = NULL;
  real_T c12_wc_u;
  const mxArray *c12_xc_y = NULL;
  int32_T c12_i70;
  real_T c12_xc_u[13];
  const mxArray *c12_yc_y = NULL;
  real_T c12_yc_u;
  const mxArray *c12_ad_y = NULL;
  int32_T c12_i71;
  real_T c12_ad_u[7];
  const mxArray *c12_bd_y = NULL;
  real_T c12_bd_u;
  const mxArray *c12_cd_y = NULL;
  int32_T c12_i72;
  real_T c12_cd_u[2];
  const mxArray *c12_dd_y = NULL;
  real_T c12_dd_u;
  const mxArray *c12_ed_y = NULL;
  real_T c12_ed_u;
  const mxArray *c12_fd_y = NULL;
  real_T c12_fd_u;
  const mxArray *c12_gd_y = NULL;
  int32_T c12_i73;
  real_T c12_gd_u[30];
  const mxArray *c12_hd_y = NULL;
  c12_PhiParamsBus c12_hd_u;
  const mxArray *c12_id_y = NULL;
  real_T c12_id_u;
  const mxArray *c12_jd_y = NULL;
  int32_T c12_i74;
  real_T c12_jd_u[13];
  const mxArray *c12_kd_y = NULL;
  int32_T c12_i75;
  real_T c12_kd_u[20];
  const mxArray *c12_ld_y = NULL;
  real_T c12_ld_u;
  const mxArray *c12_md_y = NULL;
  int32_T c12_i76;
  real_T c12_md_u[2];
  const mxArray *c12_nd_y = NULL;
  int32_T c12_i77;
  real_T c12_nd_u[30];
  const mxArray *c12_od_y = NULL;
  int32_T c12_i78;
  real_T c12_od_u[12];
  const mxArray *c12_pd_y = NULL;
  int32_T c12_i79;
  real_T c12_pd_u[36];
  const mxArray *c12_qd_y = NULL;
  real_T c12_qd_u;
  const mxArray *c12_rd_y = NULL;
  c12_FeedbackParamsBus c12_rd_u;
  const mxArray *c12_sd_y = NULL;
  int32_T c12_i80;
  real_T c12_sd_u[6];
  const mxArray *c12_td_y = NULL;
  int32_T c12_i81;
  real_T c12_td_u[6];
  const mxArray *c12_ud_y = NULL;
  int32_T c12_i82;
  real_T c12_ud_u[2];
  const mxArray *c12_vd_y = NULL;
  int32_T c12_i83;
  real_T c12_vd_u[2];
  const mxArray *c12_wd_y = NULL;
  real_T c12_wd_u;
  const mxArray *c12_xd_y = NULL;
  int32_T c12_i84;
  real_T c12_xd_u[2];
  const mxArray *c12_yd_y = NULL;
  int32_T c12_i85;
  real_T c12_yd_u[2];
  const mxArray *c12_ae_y = NULL;
  real_T c12_ae_u;
  const mxArray *c12_be_y = NULL;
  real_T c12_be_u;
  const mxArray *c12_ce_y = NULL;
  real_T c12_ce_u;
  const mxArray *c12_de_y = NULL;
  real_T c12_de_u;
  const mxArray *c12_ee_y = NULL;
  real_T c12_ee_u;
  const mxArray *c12_fe_y = NULL;
  real_T c12_fe_u;
  const mxArray *c12_ge_y = NULL;
  real_T c12_ge_u;
  const mxArray *c12_he_y = NULL;
  real_T c12_he_u;
  const mxArray *c12_ie_y = NULL;
  int32_T c12_i86;
  real_T c12_ie_u[6];
  const mxArray *c12_je_y = NULL;
  real_T c12_je_u;
  const mxArray *c12_ke_y = NULL;
  real_T c12_ke_u;
  const mxArray *c12_le_y = NULL;
  real_T c12_le_u;
  const mxArray *c12_me_y = NULL;
  real_T c12_me_u;
  const mxArray *c12_ne_y = NULL;
  real_T c12_ne_u;
  const mxArray *c12_oe_y = NULL;
  real_T c12_oe_u;
  const mxArray *c12_pe_y = NULL;
  real_T c12_pe_u;
  const mxArray *c12_qe_y = NULL;
  real_T c12_qe_u;
  const mxArray *c12_re_y = NULL;
  real_T c12_re_u;
  const mxArray *c12_se_y = NULL;
  int32_T c12_i87;
  real_T c12_se_u[6];
  const mxArray *c12_te_y = NULL;
  real_T c12_te_u;
  const mxArray *c12_ue_y = NULL;
  c12_SaturationParamsBus c12_ue_u;
  const mxArray *c12_ve_y = NULL;
  real_T c12_ve_u;
  const mxArray *c12_we_y = NULL;
  int32_T c12_i88;
  real_T c12_we_u[2];
  const mxArray *c12_xe_y = NULL;
  real_T c12_xe_u;
  const mxArray *c12_ye_y = NULL;
  real_T c12_ye_u;
  const mxArray *c12_af_y = NULL;
  real_T c12_af_u;
  const mxArray *c12_bf_y = NULL;
  real_T c12_bf_u;
  const mxArray *c12_cf_y = NULL;
  real_T c12_cf_u;
  const mxArray *c12_df_y = NULL;
  SFc12_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc12_LibWalkingInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_mxArrayOutData = NULL;
  c12_u = *(c12_ControlParamsBus *)c12_inData;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_b_u = c12_u.Supervisory;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_c_u = c12_b_u.EnableSwapOnKAAccel;
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_d_y, "EnableSwapOnKAAccel", "EnableSwapOnKAAccel",
                  0);
  c12_d_u = c12_b_u.EnableSwapOnKASpring;
  c12_e_y = NULL;
  sf_mex_assign(&c12_e_y, sf_mex_create("y", &c12_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_e_y, "EnableSwapOnKASpring",
                  "EnableSwapOnKASpring", 0);
  c12_e_u = c12_b_u.EnableBackwardSwap;
  c12_f_y = NULL;
  sf_mex_assign(&c12_f_y, sf_mex_create("y", &c12_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_f_y, "EnableBackwardSwap", "EnableBackwardSwap",
                  0);
  c12_f_u = c12_b_u.ImpactThresholdKAAccel;
  c12_g_y = NULL;
  sf_mex_assign(&c12_g_y, sf_mex_create("y", &c12_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_g_y, "ImpactThresholdKAAccel",
                  "ImpactThresholdKAAccel", 0);
  c12_g_u = c12_b_u.ImpactThresholdKASpringAbs;
  c12_h_y = NULL;
  sf_mex_assign(&c12_h_y, sf_mex_create("y", &c12_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_h_y, "ImpactThresholdKASpringAbs",
                  "ImpactThresholdKASpringAbs", 0);
  c12_h_u = c12_b_u.ImpactThresholdKASpringRel;
  c12_i_y = NULL;
  sf_mex_assign(&c12_i_y, sf_mex_create("y", &c12_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_i_y, "ImpactThresholdKASpringRel",
                  "ImpactThresholdKASpringRel", 0);
  c12_i_u = c12_b_u.SwapThresholdS;
  c12_j_y = NULL;
  sf_mex_assign(&c12_j_y, sf_mex_create("y", &c12_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_j_y, "SwapThresholdS", "SwapThresholdS", 0);
  c12_j_u = c12_b_u.AllowDoubleSupport;
  c12_k_y = NULL;
  sf_mex_assign(&c12_k_y, sf_mex_create("y", &c12_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_k_y, "AllowDoubleSupport", "AllowDoubleSupport",
                  0);
  c12_k_u = c12_b_u.UseGaitTransition;
  c12_l_y = NULL;
  sf_mex_assign(&c12_l_y, sf_mex_create("y", &c12_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_l_y, "UseGaitTransition", "UseGaitTransition", 0);
  c12_l_u = c12_b_u.NumTransitionSteps;
  c12_m_y = NULL;
  sf_mex_assign(&c12_m_y, sf_mex_create("y", &c12_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_m_y, "NumTransitionSteps", "NumTransitionSteps",
                  0);
  c12_m_u = c12_b_u.TransitionThresholdTorsoVel;
  c12_n_y = NULL;
  sf_mex_assign(&c12_n_y, sf_mex_create("y", &c12_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_n_y, "TransitionThresholdTorsoVel",
                  "TransitionThresholdTorsoVel", 0);
  for (c12_i56 = 0; c12_i56 < 2; c12_i56++) {
    c12_n_u[c12_i56] = c12_b_u.KAInjection[c12_i56];
  }

  c12_o_y = NULL;
  sf_mex_assign(&c12_o_y, sf_mex_create("y", c12_n_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c12_c_y, c12_o_y, "KAInjection", "KAInjection", 0);
  c12_o_u = c12_b_u.MinDeltaThetaTransition;
  c12_p_y = NULL;
  sf_mex_assign(&c12_p_y, sf_mex_create("y", &c12_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_p_y, "MinDeltaThetaTransition",
                  "MinDeltaThetaTransition", 0);
  c12_p_u = c12_b_u.StartSecondGaitOnStep;
  c12_q_y = NULL;
  sf_mex_assign(&c12_q_y, sf_mex_create("y", &c12_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_q_y, "StartSecondGaitOnStep",
                  "StartSecondGaitOnStep", 0);
  for (c12_i57 = 0; c12_i57 < 6; c12_i57++) {
    c12_q_u[c12_i57] = c12_b_u.VBLAParams[c12_i57];
  }

  c12_r_y = NULL;
  sf_mex_assign(&c12_r_y, sf_mex_create("y", c12_q_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c12_c_y, c12_r_y, "VBLAParams", "VBLAParams", 0);
  for (c12_i58 = 0; c12_i58 < 13; c12_i58++) {
    c12_r_u[c12_i58] = c12_b_u.BalanceParams[c12_i58];
  }

  c12_s_y = NULL;
  sf_mex_assign(&c12_s_y, sf_mex_create("y", c12_r_u, 0, 0U, 1U, 0U, 1, 13),
                false);
  sf_mex_addfield(c12_c_y, c12_s_y, "BalanceParams", "BalanceParams", 0);
  for (c12_i59 = 0; c12_i59 < 5; c12_i59++) {
    c12_s_u[c12_i59] = c12_b_u.GaitTweaks[c12_i59];
  }

  c12_t_y = NULL;
  sf_mex_assign(&c12_t_y, sf_mex_create("y", c12_s_u, 0, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_addfield(c12_c_y, c12_t_y, "GaitTweaks", "GaitTweaks", 0);
  c12_t_u = c12_b_u.TStepInitial;
  c12_u_y = NULL;
  sf_mex_assign(&c12_u_y, sf_mex_create("y", &c12_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_u_y, "TStepInitial", "TStepInitial", 0);
  c12_u_u = c12_b_u.TMaxUpdate;
  c12_v_y = NULL;
  sf_mex_assign(&c12_v_y, sf_mex_create("y", &c12_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_v_y, "TMaxUpdate", "TMaxUpdate", 0);
  c12_v_u = c12_b_u.RunMode;
  c12_w_y = NULL;
  sf_mex_assign(&c12_w_y, sf_mex_create("y", &c12_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_w_y, "RunMode", "RunMode", 0);
  c12_w_u = c12_b_u.UseAbsoluteSwingLA;
  c12_x_y = NULL;
  sf_mex_assign(&c12_x_y, sf_mex_create("y", &c12_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_c_y, c12_x_y, "UseAbsoluteSwingLA", "UseAbsoluteSwingLA",
                  0);
  for (c12_i60 = 0; c12_i60 < 6; c12_i60++) {
    c12_x_u[c12_i60] = c12_b_u.ErrorZeroFactor[c12_i60];
  }

  c12_y_y = NULL;
  sf_mex_assign(&c12_y_y, sf_mex_create("y", c12_x_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c12_c_y, c12_y_y, "ErrorZeroFactor", "ErrorZeroFactor", 0);
  for (c12_i61 = 0; c12_i61 < 6; c12_i61++) {
    c12_y_u[c12_i61] = c12_b_u.ErrorVelZeroFactor[c12_i61];
  }

  c12_ab_y = NULL;
  sf_mex_assign(&c12_ab_y, sf_mex_create("y", c12_y_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c12_c_y, c12_ab_y, "ErrorVelZeroFactor", "ErrorVelZeroFactor",
                  0);
  c12_ab_u = c12_b_u.StanceLegInit;
  c12_bb_y = NULL;
  sf_mex_assign(&c12_bb_y, sf_mex_create("y", &c12_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_bb_y, "StanceLegInit", "StanceLegInit", 0);
  c12_bb_u = c12_b_u.ControllerModeInit;
  c12_cb_y = NULL;
  sf_mex_assign(&c12_cb_y, sf_mex_create("y", &c12_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_cb_y, "ControllerModeInit", "ControllerModeInit",
                  0);
  c12_cb_u = c12_b_u.UsePosingControl;
  c12_db_y = NULL;
  sf_mex_assign(&c12_db_y, sf_mex_create("y", &c12_cb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_db_y, "UsePosingControl", "UsePosingControl", 0);
  c12_db_u = c12_b_u.TPosing;
  c12_eb_y = NULL;
  sf_mex_assign(&c12_eb_y, sf_mex_create("y", &c12_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_eb_y, "TPosing", "TPosing", 0);
  c12_eb_u = c12_b_u.TorsoBackAngle;
  c12_fb_y = NULL;
  sf_mex_assign(&c12_fb_y, sf_mex_create("y", &c12_eb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_fb_y, "TorsoBackAngle", "TorsoBackAngle", 0);
  c12_fb_u = c12_b_u.TorsoBackOnStep;
  c12_gb_y = NULL;
  sf_mex_assign(&c12_gb_y, sf_mex_create("y", &c12_fb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_gb_y, "TorsoBackOnStep", "TorsoBackOnStep", 0);
  c12_gb_u = c12_b_u.EnergyControlGain;
  c12_hb_y = NULL;
  sf_mex_assign(&c12_hb_y, sf_mex_create("y", &c12_gb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_hb_y, "EnergyControlGain", "EnergyControlGain", 0);
  c12_hb_u = c12_b_u.EnergyControlPhi0;
  c12_ib_y = NULL;
  sf_mex_assign(&c12_ib_y, sf_mex_create("y", &c12_hb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_ib_y, "EnergyControlPhi0", "EnergyControlPhi0", 0);
  c12_ib_u = c12_b_u.VelocityControlTorsoMax;
  c12_jb_y = NULL;
  sf_mex_assign(&c12_jb_y, sf_mex_create("y", &c12_ib_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_jb_y, "VelocityControlTorsoMax",
                  "VelocityControlTorsoMax", 0);
  c12_jb_u = c12_b_u.VelocityControlTorsoMin;
  c12_kb_y = NULL;
  sf_mex_assign(&c12_kb_y, sf_mex_create("y", &c12_jb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_kb_y, "VelocityControlTorsoMin",
                  "VelocityControlTorsoMin", 0);
  c12_kb_u = c12_b_u.VelocityControlTorsoGain;
  c12_lb_y = NULL;
  sf_mex_assign(&c12_lb_y, sf_mex_create("y", &c12_kb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_lb_y, "VelocityControlTorsoGain",
                  "VelocityControlTorsoGain", 0);
  c12_lb_u = c12_b_u.VelocityControlTorsoV0;
  c12_mb_y = NULL;
  sf_mex_assign(&c12_mb_y, sf_mex_create("y", &c12_lb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_mb_y, "VelocityControlTorsoV0",
                  "VelocityControlTorsoV0", 0);
  c12_mb_u = c12_b_u.MinDeltaTheta;
  c12_nb_y = NULL;
  sf_mex_assign(&c12_nb_y, sf_mex_create("y", &c12_mb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_nb_y, "MinDeltaTheta", "MinDeltaTheta", 0);
  c12_nb_u = c12_b_u.Theta0;
  c12_ob_y = NULL;
  sf_mex_assign(&c12_ob_y, sf_mex_create("y", &c12_nb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_ob_y, "Theta0", "Theta0", 0);
  c12_ob_u = c12_b_u.KThetaPlus;
  c12_pb_y = NULL;
  sf_mex_assign(&c12_pb_y, sf_mex_create("y", &c12_ob_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_pb_y, "KThetaPlus", "KThetaPlus", 0);
  c12_pb_u = c12_b_u.KThetaMinus;
  c12_qb_y = NULL;
  sf_mex_assign(&c12_qb_y, sf_mex_create("y", &c12_pb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_qb_y, "KThetaMinus", "KThetaMinus", 0);
  c12_qb_u = c12_b_u.RollPhaseVelocityThresh;
  c12_rb_y = NULL;
  sf_mex_assign(&c12_rb_y, sf_mex_create("y", &c12_qb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_rb_y, "RollPhaseVelocityThresh",
                  "RollPhaseVelocityThresh", 0);
  c12_rb_u = c12_b_u.RollPhaseSThresh;
  c12_sb_y = NULL;
  sf_mex_assign(&c12_sb_y, sf_mex_create("y", &c12_rb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_sb_y, "RollPhaseSThresh", "RollPhaseSThresh", 0);
  c12_sb_u = c12_b_u.MaxError;
  c12_tb_y = NULL;
  sf_mex_assign(&c12_tb_y, sf_mex_create("y", &c12_sb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_tb_y, "MaxError", "MaxError", 0);
  c12_tb_u = c12_b_u.MaxErrorVel;
  c12_ub_y = NULL;
  sf_mex_assign(&c12_ub_y, sf_mex_create("y", &c12_tb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_ub_y, "MaxErrorVel", "MaxErrorVel", 0);
  c12_ub_u = c12_b_u.MaxErrorCount;
  c12_vb_y = NULL;
  sf_mex_assign(&c12_vb_y, sf_mex_create("y", &c12_ub_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_vb_y, "MaxErrorCount", "MaxErrorCount", 0);
  for (c12_i62 = 0; c12_i62 < 6; c12_i62++) {
    c12_vb_u[c12_i62] = c12_b_u.K1MidStanceUpdate[c12_i62];
  }

  c12_wb_y = NULL;
  sf_mex_assign(&c12_wb_y, sf_mex_create("y", c12_vb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c12_c_y, c12_wb_y, "K1MidStanceUpdate", "K1MidStanceUpdate", 0);
  for (c12_i63 = 0; c12_i63 < 6; c12_i63++) {
    c12_wb_u[c12_i63] = c12_b_u.K2MidStanceUpdate[c12_i63];
  }

  c12_xb_y = NULL;
  sf_mex_assign(&c12_xb_y, sf_mex_create("y", c12_wb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c12_c_y, c12_xb_y, "K2MidStanceUpdate", "K2MidStanceUpdate", 0);
  c12_xb_u = c12_b_u.EnableVelocityBasedUpdate;
  c12_yb_y = NULL;
  sf_mex_assign(&c12_yb_y, sf_mex_create("y", &c12_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_yb_y, "EnableVelocityBasedUpdate",
                  "EnableVelocityBasedUpdate", 0);
  for (c12_i64 = 0; c12_i64 < 6; c12_i64++) {
    c12_yb_u[c12_i64] = c12_b_u.VelocityBasedUpdateK1[c12_i64];
  }

  c12_ac_y = NULL;
  sf_mex_assign(&c12_ac_y, sf_mex_create("y", c12_yb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c12_c_y, c12_ac_y, "VelocityBasedUpdateK1",
                  "VelocityBasedUpdateK1", 0);
  for (c12_i65 = 0; c12_i65 < 6; c12_i65++) {
    c12_ac_u[c12_i65] = c12_b_u.VelocityBasedUpdateK2[c12_i65];
  }

  c12_bc_y = NULL;
  sf_mex_assign(&c12_bc_y, sf_mex_create("y", c12_ac_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c12_c_y, c12_bc_y, "VelocityBasedUpdateK2",
                  "VelocityBasedUpdateK2", 0);
  c12_bc_u = c12_b_u.VelocityBasedUpdateDTheta0;
  c12_cc_y = NULL;
  sf_mex_assign(&c12_cc_y, sf_mex_create("y", &c12_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_cc_y, "VelocityBasedUpdateDTheta0",
                  "VelocityBasedUpdateDTheta0", 0);
  for (c12_i66 = 0; c12_i66 < 12; c12_i66++) {
    c12_cc_u[c12_i66] = c12_b_u.VelocityBasedUpdateLimits[c12_i66];
  }

  c12_dc_y = NULL;
  sf_mex_assign(&c12_dc_y, sf_mex_create("y", c12_cc_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c12_c_y, c12_dc_y, "VelocityBasedUpdateLimits",
                  "VelocityBasedUpdateLimits", 0);
  c12_dc_u = c12_b_u.DesiredYawOffset;
  c12_ec_y = NULL;
  sf_mex_assign(&c12_ec_y, sf_mex_create("y", &c12_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_c_y, c12_ec_y, "DesiredYawOffset", "DesiredYawOffset", 0);
  sf_mex_addfield(c12_b_y, c12_c_y, "Supervisory", "Supervisory", 0);
  c12_ec_u = c12_u.Discrete;
  c12_fc_y = NULL;
  sf_mex_assign(&c12_fc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_fc_u = c12_ec_u.TLastUpdate;
  c12_gc_y = NULL;
  sf_mex_assign(&c12_gc_y, sf_mex_create("y", &c12_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_fc_y, c12_gc_y, "TLastUpdate", "TLastUpdate", 0);
  c12_gc_u = c12_ec_u.VelocityControlLADelta;
  c12_hc_y = NULL;
  sf_mex_assign(&c12_hc_y, sf_mex_create("y", &c12_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_fc_y, c12_hc_y, "VelocityControlLADelta",
                  "VelocityControlLADelta", 0);
  c12_hc_u = c12_ec_u.VelocityControlTorsoDelta;
  c12_ic_y = NULL;
  sf_mex_assign(&c12_ic_y, sf_mex_create("y", &c12_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_fc_y, c12_ic_y, "VelocityControlTorsoDelta",
                  "VelocityControlTorsoDelta", 0);
  c12_ic_u = c12_ec_u.VelocityControlHipDistCur;
  c12_jc_y = NULL;
  sf_mex_assign(&c12_jc_y, sf_mex_create("y", &c12_ic_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_fc_y, c12_jc_y, "VelocityControlHipDistCur",
                  "VelocityControlHipDistCur", 0);
  c12_jc_u = c12_ec_u.VelocityControlHipDistPrev;
  c12_kc_y = NULL;
  sf_mex_assign(&c12_kc_y, sf_mex_create("y", &c12_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_fc_y, c12_kc_y, "VelocityControlHipDistPrev",
                  "VelocityControlHipDistPrev", 0);
  c12_kc_u = c12_ec_u.VirtualSpringMode;
  c12_lc_y = NULL;
  sf_mex_assign(&c12_lc_y, sf_mex_create("y", &c12_kc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_fc_y, c12_lc_y, "VirtualSpringMode", "VirtualSpringMode",
                  0);
  c12_lc_u = c12_ec_u.VirtualSpringStiffness;
  c12_mc_y = NULL;
  sf_mex_assign(&c12_mc_y, sf_mex_create("y", &c12_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_fc_y, c12_mc_y, "VirtualSpringStiffness",
                  "VirtualSpringStiffness", 0);
  c12_mc_u = c12_ec_u.VirtualSpringDamping;
  c12_nc_y = NULL;
  sf_mex_assign(&c12_nc_y, sf_mex_create("y", &c12_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_fc_y, c12_nc_y, "VirtualSpringDamping",
                  "VirtualSpringDamping", 0);
  c12_nc_u = c12_ec_u.VirtualSpringModAmplitude;
  c12_oc_y = NULL;
  sf_mex_assign(&c12_oc_y, sf_mex_create("y", &c12_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_fc_y, c12_oc_y, "VirtualSpringModAmplitude",
                  "VirtualSpringModAmplitude", 0);
  c12_oc_u = c12_ec_u.VirtualSpringModRate;
  c12_pc_y = NULL;
  sf_mex_assign(&c12_pc_y, sf_mex_create("y", &c12_oc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_fc_y, c12_pc_y, "VirtualSpringModRate",
                  "VirtualSpringModRate", 0);
  c12_pc_u = c12_ec_u.VirtualSpringRestPos;
  c12_qc_y = NULL;
  sf_mex_assign(&c12_qc_y, sf_mex_create("y", &c12_pc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_fc_y, c12_qc_y, "VirtualSpringRestPos",
                  "VirtualSpringRestPos", 0);
  sf_mex_addfield(c12_b_y, c12_fc_y, "Discrete", "Discrete", 0);
  c12_qc_u = c12_u.Output;
  c12_rc_y = NULL;
  sf_mex_assign(&c12_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c12_i67 = 0; c12_i67 < 78; c12_i67++) {
    c12_rc_u[c12_i67] = c12_qc_u.H0[c12_i67];
  }

  c12_sc_y = NULL;
  sf_mex_assign(&c12_sc_y, sf_mex_create("y", c12_rc_u, 0, 0U, 1U, 0U, 2, 6, 13),
                false);
  sf_mex_addfield(c12_rc_y, c12_sc_y, "H0", "H0", 0);
  for (c12_i68 = 0; c12_i68 < 36; c12_i68++) {
    c12_sc_u[c12_i68] = c12_qc_u.HAlpha[c12_i68];
  }

  c12_tc_y = NULL;
  sf_mex_assign(&c12_tc_y, sf_mex_create("y", c12_sc_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c12_rc_y, c12_tc_y, "HAlpha", "HAlpha", 0);
  for (c12_i69 = 0; c12_i69 < 2; c12_i69++) {
    c12_tc_u[c12_i69] = c12_qc_u.ThetaLimits[c12_i69];
  }

  c12_uc_y = NULL;
  sf_mex_assign(&c12_uc_y, sf_mex_create("y", c12_tc_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c12_rc_y, c12_uc_y, "ThetaLimits", "ThetaLimits", 0);
  c12_uc_u = c12_qc_u.Theta;
  c12_vc_y = NULL;
  sf_mex_assign(&c12_vc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_vc_u = c12_uc_u.c0;
  c12_wc_y = NULL;
  sf_mex_assign(&c12_wc_y, sf_mex_create("y", &c12_vc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_vc_y, c12_wc_y, "c0", "c0", 0);
  c12_wc_u = c12_uc_u.ct;
  c12_xc_y = NULL;
  sf_mex_assign(&c12_xc_y, sf_mex_create("y", &c12_wc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_vc_y, c12_xc_y, "ct", "ct", 0);
  for (c12_i70 = 0; c12_i70 < 13; c12_i70++) {
    c12_xc_u[c12_i70] = c12_uc_u.cq[c12_i70];
  }

  c12_yc_y = NULL;
  sf_mex_assign(&c12_yc_y, sf_mex_create("y", c12_xc_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c12_vc_y, c12_yc_y, "cq", "cq", 0);
  c12_yc_u = c12_uc_u.t0;
  c12_ad_y = NULL;
  sf_mex_assign(&c12_ad_y, sf_mex_create("y", &c12_yc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_vc_y, c12_ad_y, "t0", "t0", 0);
  for (c12_i71 = 0; c12_i71 < 7; c12_i71++) {
    c12_ad_u[c12_i71] = c12_uc_u.cz[c12_i71];
  }

  c12_bd_y = NULL;
  sf_mex_assign(&c12_bd_y, sf_mex_create("y", c12_ad_u, 0, 0U, 1U, 0U, 2, 1, 7),
                false);
  sf_mex_addfield(c12_vc_y, c12_bd_y, "cz", "cz", 0);
  sf_mex_addfield(c12_rc_y, c12_vc_y, "Theta", "Theta", 0);
  c12_bd_u = c12_qc_u.SaturateS;
  c12_cd_y = NULL;
  sf_mex_assign(&c12_cd_y, sf_mex_create("y", &c12_bd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_rc_y, c12_cd_y, "SaturateS", "SaturateS", 0);
  for (c12_i72 = 0; c12_i72 < 2; c12_i72++) {
    c12_cd_u[c12_i72] = c12_qc_u.SLimits[c12_i72];
  }

  c12_dd_y = NULL;
  sf_mex_assign(&c12_dd_y, sf_mex_create("y", c12_cd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c12_rc_y, c12_dd_y, "SLimits", "SLimits", 0);
  c12_dd_u = c12_qc_u.EnforceIncreasingS;
  c12_ed_y = NULL;
  sf_mex_assign(&c12_ed_y, sf_mex_create("y", &c12_dd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_rc_y, c12_ed_y, "EnforceIncreasingS", "EnforceIncreasingS",
                  0);
  c12_ed_u = c12_qc_u.UseCorrection;
  c12_fd_y = NULL;
  sf_mex_assign(&c12_fd_y, sf_mex_create("y", &c12_ed_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_rc_y, c12_fd_y, "UseCorrection", "UseCorrection", 0);
  c12_fd_u = c12_qc_u.SMaxCorrection;
  c12_gd_y = NULL;
  sf_mex_assign(&c12_gd_y, sf_mex_create("y", &c12_fd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_rc_y, c12_gd_y, "SMaxCorrection", "SMaxCorrection", 0);
  for (c12_i73 = 0; c12_i73 < 30; c12_i73++) {
    c12_gd_u[c12_i73] = c12_qc_u.HAlphaCorrection[c12_i73];
  }

  c12_hd_y = NULL;
  sf_mex_assign(&c12_hd_y, sf_mex_create("y", c12_gd_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c12_rc_y, c12_hd_y, "HAlphaCorrection", "HAlphaCorrection", 0);
  c12_hd_u = c12_qc_u.Phi;
  c12_id_y = NULL;
  sf_mex_assign(&c12_id_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_id_u = c12_hd_u.c0;
  c12_jd_y = NULL;
  sf_mex_assign(&c12_jd_y, sf_mex_create("y", &c12_id_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_id_y, c12_jd_y, "c0", "c0", 0);
  for (c12_i74 = 0; c12_i74 < 13; c12_i74++) {
    c12_jd_u[c12_i74] = c12_hd_u.cq[c12_i74];
  }

  c12_kd_y = NULL;
  sf_mex_assign(&c12_kd_y, sf_mex_create("y", c12_jd_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c12_id_y, c12_kd_y, "cq", "cq", 0);
  sf_mex_addfield(c12_rc_y, c12_id_y, "Phi", "Phi", 0);
  for (c12_i75 = 0; c12_i75 < 20; c12_i75++) {
    c12_kd_u[c12_i75] = c12_qc_u.PhiAlpha[c12_i75];
  }

  c12_ld_y = NULL;
  sf_mex_assign(&c12_ld_y, sf_mex_create("y", c12_kd_u, 0, 0U, 1U, 0U, 2, 1, 20),
                false);
  sf_mex_addfield(c12_rc_y, c12_ld_y, "PhiAlpha", "PhiAlpha", 0);
  c12_ld_u = c12_qc_u.SaturateR;
  c12_md_y = NULL;
  sf_mex_assign(&c12_md_y, sf_mex_create("y", &c12_ld_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_rc_y, c12_md_y, "SaturateR", "SaturateR", 0);
  for (c12_i76 = 0; c12_i76 < 2; c12_i76++) {
    c12_md_u[c12_i76] = c12_qc_u.RLimits[c12_i76];
  }

  c12_nd_y = NULL;
  sf_mex_assign(&c12_nd_y, sf_mex_create("y", c12_md_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c12_rc_y, c12_nd_y, "RLimits", "RLimits", 0);
  for (c12_i77 = 0; c12_i77 < 30; c12_i77++) {
    c12_nd_u[c12_i77] = c12_qc_u.HBarAlpha[c12_i77];
  }

  c12_od_y = NULL;
  sf_mex_assign(&c12_od_y, sf_mex_create("y", c12_nd_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c12_rc_y, c12_od_y, "HBarAlpha", "HBarAlpha", 0);
  for (c12_i78 = 0; c12_i78 < 12; c12_i78++) {
    c12_od_u[c12_i78] = c12_qc_u.HBarLimits[c12_i78];
  }

  c12_pd_y = NULL;
  sf_mex_assign(&c12_pd_y, sf_mex_create("y", c12_od_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c12_rc_y, c12_pd_y, "HBarLimits", "HBarLimits", 0);
  for (c12_i79 = 0; c12_i79 < 36; c12_i79++) {
    c12_pd_u[c12_i79] = c12_qc_u.HAlphaStar[c12_i79];
  }

  c12_qd_y = NULL;
  sf_mex_assign(&c12_qd_y, sf_mex_create("y", c12_pd_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c12_rc_y, c12_qd_y, "HAlphaStar", "HAlphaStar", 0);
  c12_qd_u = c12_qc_u.YawLimit;
  c12_rd_y = NULL;
  sf_mex_assign(&c12_rd_y, sf_mex_create("y", &c12_qd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_rc_y, c12_rd_y, "YawLimit", "YawLimit", 0);
  sf_mex_addfield(c12_b_y, c12_rc_y, "Output", "Output", 0);
  c12_rd_u = c12_u.Feedback;
  c12_sd_y = NULL;
  sf_mex_assign(&c12_sd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c12_i80 = 0; c12_i80 < 6; c12_i80++) {
    c12_sd_u[c12_i80] = c12_rd_u.kp[c12_i80];
  }

  c12_td_y = NULL;
  sf_mex_assign(&c12_td_y, sf_mex_create("y", c12_sd_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c12_sd_y, c12_td_y, "kp", "kp", 0);
  for (c12_i81 = 0; c12_i81 < 6; c12_i81++) {
    c12_td_u[c12_i81] = c12_rd_u.kd[c12_i81];
  }

  c12_ud_y = NULL;
  sf_mex_assign(&c12_ud_y, sf_mex_create("y", c12_td_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c12_sd_y, c12_ud_y, "kd", "kd", 0);
  for (c12_i82 = 0; c12_i82 < 2; c12_i82++) {
    c12_ud_u[c12_i82] = c12_rd_u.epsilon[c12_i82];
  }

  c12_vd_y = NULL;
  sf_mex_assign(&c12_vd_y, sf_mex_create("y", c12_ud_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c12_sd_y, c12_vd_y, "epsilon", "epsilon", 0);
  for (c12_i83 = 0; c12_i83 < 2; c12_i83++) {
    c12_vd_u[c12_i83] = c12_rd_u.kff_grav[c12_i83];
  }

  c12_wd_y = NULL;
  sf_mex_assign(&c12_wd_y, sf_mex_create("y", c12_vd_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c12_sd_y, c12_wd_y, "kff_grav", "kff_grav", 0);
  c12_wd_u = c12_rd_u.delta_grav;
  c12_xd_y = NULL;
  sf_mex_assign(&c12_xd_y, sf_mex_create("y", &c12_wd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_xd_y, "delta_grav", "delta_grav", 0);
  for (c12_i84 = 0; c12_i84 < 2; c12_i84++) {
    c12_xd_u[c12_i84] = c12_rd_u.kff_decoup[c12_i84];
  }

  c12_yd_y = NULL;
  sf_mex_assign(&c12_yd_y, sf_mex_create("y", c12_xd_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c12_sd_y, c12_yd_y, "kff_decoup", "kff_decoup", 0);
  for (c12_i85 = 0; c12_i85 < 2; c12_i85++) {
    c12_yd_u[c12_i85] = c12_rd_u.kd_torso[c12_i85];
  }

  c12_ae_y = NULL;
  sf_mex_assign(&c12_ae_y, sf_mex_create("y", c12_yd_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c12_sd_y, c12_ae_y, "kd_torso", "kd_torso", 0);
  c12_ae_u = c12_rd_u.kp_2dof;
  c12_be_y = NULL;
  sf_mex_assign(&c12_be_y, sf_mex_create("y", &c12_ae_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_be_y, "kp_2dof", "kp_2dof", 0);
  c12_be_u = c12_rd_u.kd_2dof;
  c12_ce_y = NULL;
  sf_mex_assign(&c12_ce_y, sf_mex_create("y", &c12_be_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_ce_y, "kd_2dof", "kd_2dof", 0);
  c12_ce_u = c12_rd_u.kpre_2dof;
  c12_de_y = NULL;
  sf_mex_assign(&c12_de_y, sf_mex_create("y", &c12_ce_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_de_y, "kpre_2dof", "kpre_2dof", 0);
  c12_de_u = c12_rd_u.kp_lat;
  c12_ee_y = NULL;
  sf_mex_assign(&c12_ee_y, sf_mex_create("y", &c12_de_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_ee_y, "kp_lat", "kp_lat", 0);
  c12_ee_u = c12_rd_u.kd_lat;
  c12_fe_y = NULL;
  sf_mex_assign(&c12_fe_y, sf_mex_create("y", &c12_ee_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_fe_y, "kd_lat", "kd_lat", 0);
  c12_fe_u = c12_rd_u.q3d_min_lat;
  c12_ge_y = NULL;
  sf_mex_assign(&c12_ge_y, sf_mex_create("y", &c12_fe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_ge_y, "q3d_min_lat", "q3d_min_lat", 0);
  c12_ge_u = c12_rd_u.q3d_max_lat;
  c12_he_y = NULL;
  sf_mex_assign(&c12_he_y, sf_mex_create("y", &c12_ge_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_he_y, "q3d_max_lat", "q3d_max_lat", 0);
  c12_he_u = c12_rd_u.w_torso_lat;
  c12_ie_y = NULL;
  sf_mex_assign(&c12_ie_y, sf_mex_create("y", &c12_he_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_ie_y, "w_torso_lat", "w_torso_lat", 0);
  for (c12_i86 = 0; c12_i86 < 6; c12_i86++) {
    c12_ie_u[c12_i86] = c12_rd_u.u_ff[c12_i86];
  }

  c12_je_y = NULL;
  sf_mex_assign(&c12_je_y, sf_mex_create("y", c12_ie_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c12_sd_y, c12_je_y, "u_ff", "u_ff", 0);
  c12_je_u = c12_rd_u.LateralControlMode;
  c12_ke_y = NULL;
  sf_mex_assign(&c12_ke_y, sf_mex_create("y", &c12_je_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_ke_y, "LateralControlMode", "LateralControlMode",
                  0);
  c12_ke_u = c12_rd_u.DecouplingMode;
  c12_le_y = NULL;
  sf_mex_assign(&c12_le_y, sf_mex_create("y", &c12_ke_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_le_y, "DecouplingMode", "DecouplingMode", 0);
  c12_le_u = c12_rd_u.Use2DOF;
  c12_me_y = NULL;
  sf_mex_assign(&c12_me_y, sf_mex_create("y", &c12_le_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_me_y, "Use2DOF", "Use2DOF", 0);
  c12_me_u = c12_rd_u.UseDSGravComp;
  c12_ne_y = NULL;
  sf_mex_assign(&c12_ne_y, sf_mex_create("y", &c12_me_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_ne_y, "UseDSGravComp", "UseDSGravComp", 0);
  c12_ne_u = c12_rd_u.lat_bias;
  c12_oe_y = NULL;
  sf_mex_assign(&c12_oe_y, sf_mex_create("y", &c12_ne_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_oe_y, "lat_bias", "lat_bias", 0);
  c12_oe_u = c12_rd_u.lat_bias2;
  c12_pe_y = NULL;
  sf_mex_assign(&c12_pe_y, sf_mex_create("y", &c12_oe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_pe_y, "lat_bias2", "lat_bias2", 0);
  c12_pe_u = c12_rd_u.linkFeedback;
  c12_qe_y = NULL;
  sf_mex_assign(&c12_qe_y, sf_mex_create("y", &c12_pe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_qe_y, "linkFeedback", "linkFeedback", 0);
  c12_qe_u = c12_rd_u.RIO;
  c12_re_y = NULL;
  sf_mex_assign(&c12_re_y, sf_mex_create("y", &c12_qe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_re_y, "RIO", "RIO", 0);
  c12_re_u = c12_rd_u.SelectFeedforward;
  c12_se_y = NULL;
  sf_mex_assign(&c12_se_y, sf_mex_create("y", &c12_re_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_se_y, "SelectFeedforward", "SelectFeedforward",
                  0);
  for (c12_i87 = 0; c12_i87 < 6; c12_i87++) {
    c12_se_u[c12_i87] = c12_rd_u.FeedforwardGain[c12_i87];
  }

  c12_te_y = NULL;
  sf_mex_assign(&c12_te_y, sf_mex_create("y", c12_se_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c12_sd_y, c12_te_y, "FeedforwardGain", "FeedforwardGain", 0);
  c12_te_u = c12_rd_u.EnableFeedforwardOnStep;
  c12_ue_y = NULL;
  sf_mex_assign(&c12_ue_y, sf_mex_create("y", &c12_te_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_sd_y, c12_ue_y, "EnableFeedforwardOnStep",
                  "EnableFeedforwardOnStep", 0);
  sf_mex_addfield(c12_b_y, c12_sd_y, "Feedback", "Feedback", 0);
  c12_ue_u = c12_u.Saturation;
  c12_ve_y = NULL;
  sf_mex_assign(&c12_ve_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_ve_u = c12_ue_u.UseQPSaturation;
  c12_we_y = NULL;
  sf_mex_assign(&c12_we_y, sf_mex_create("y", &c12_ve_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_ve_y, c12_we_y, "UseQPSaturation", "UseQPSaturation", 0);
  for (c12_i88 = 0; c12_i88 < 2; c12_i88++) {
    c12_we_u[c12_i88] = c12_ue_u.QPWeight[c12_i88];
  }

  c12_xe_y = NULL;
  sf_mex_assign(&c12_xe_y, sf_mex_create("y", c12_we_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c12_ve_y, c12_xe_y, "QPWeight", "QPWeight", 0);
  c12_xe_u = c12_ue_u.UseKASaturation;
  c12_ye_y = NULL;
  sf_mex_assign(&c12_ye_y, sf_mex_create("y", &c12_xe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_ve_y, c12_ye_y, "UseKASaturation", "UseKASaturation", 0);
  c12_ye_u = c12_ue_u.KASaturationS1;
  c12_af_y = NULL;
  sf_mex_assign(&c12_af_y, sf_mex_create("y", &c12_ye_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_ve_y, c12_af_y, "KASaturationS1", "KASaturationS1", 0);
  c12_af_u = c12_ue_u.KASaturationS2;
  c12_bf_y = NULL;
  sf_mex_assign(&c12_bf_y, sf_mex_create("y", &c12_af_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_ve_y, c12_bf_y, "KASaturationS2", "KASaturationS2", 0);
  c12_bf_u = c12_ue_u.KASaturationEarly;
  c12_cf_y = NULL;
  sf_mex_assign(&c12_cf_y, sf_mex_create("y", &c12_bf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_ve_y, c12_cf_y, "KASaturationEarly", "KASaturationEarly",
                  0);
  c12_cf_u = c12_ue_u.KASaturationMax;
  c12_df_y = NULL;
  sf_mex_assign(&c12_df_y, sf_mex_create("y", &c12_cf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c12_ve_y, c12_df_y, "KASaturationMax", "KASaturationMax", 0);
  sf_mex_addfield(c12_b_y, c12_ve_y, "Saturation", "Saturation", 0);
  sf_mex_assign(&c12_mxArrayOutData, c12_b_y, false);
  return c12_mxArrayOutData;
}

static const mxArray *c12_d_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  c12_ControlStateBus c12_u;
  const mxArray *c12_b_y = NULL;
  real_T c12_b_u;
  const mxArray *c12_c_y = NULL;
  real_T c12_c_u;
  const mxArray *c12_d_y = NULL;
  real_T c12_d_u;
  const mxArray *c12_e_y = NULL;
  real_T c12_e_u;
  const mxArray *c12_f_y = NULL;
  real_T c12_f_u;
  const mxArray *c12_g_y = NULL;
  real_T c12_g_u;
  const mxArray *c12_h_y = NULL;
  real_T c12_h_u;
  const mxArray *c12_i_y = NULL;
  SFc12_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc12_LibWalkingInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(c12_ControlStateBus *)c12_inData;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c12_b_u = c12_u.ControllerMode;
  c12_c_y = NULL;
  sf_mex_assign(&c12_c_y, sf_mex_create("y", &c12_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_b_y, c12_c_y, "ControllerMode", "ControllerMode", 0);
  c12_c_u = c12_u.SupportState;
  c12_d_y = NULL;
  sf_mex_assign(&c12_d_y, sf_mex_create("y", &c12_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_b_y, c12_d_y, "SupportState", "SupportState", 0);
  c12_d_u = c12_u.StanceLeg;
  c12_e_y = NULL;
  sf_mex_assign(&c12_e_y, sf_mex_create("y", &c12_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_b_y, c12_e_y, "StanceLeg", "StanceLeg", 0);
  c12_e_u = c12_u.InDoubleSupport;
  c12_f_y = NULL;
  sf_mex_assign(&c12_f_y, sf_mex_create("y", &c12_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_b_y, c12_f_y, "InDoubleSupport", "InDoubleSupport", 0);
  c12_f_u = c12_u.RollPhase;
  c12_g_y = NULL;
  sf_mex_assign(&c12_g_y, sf_mex_create("y", &c12_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_b_y, c12_g_y, "RollPhase", "RollPhase", 0);
  c12_g_u = c12_u.StepCount;
  c12_h_y = NULL;
  sf_mex_assign(&c12_h_y, sf_mex_create("y", &c12_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_b_y, c12_h_y, "StepCount", "StepCount", 0);
  c12_h_u = c12_u.Error;
  c12_i_y = NULL;
  sf_mex_assign(&c12_i_y, sf_mex_create("y", &c12_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c12_b_y, c12_i_y, "Error", "Error", 0);
  sf_mex_assign(&c12_mxArrayOutData, c12_b_y, false);
  return c12_mxArrayOutData;
}

static const mxArray *c12_e_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i89;
  real_T c12_b_inData[6];
  int32_T c12_i90;
  real_T c12_u[6];
  const mxArray *c12_b_y = NULL;
  SFc12_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc12_LibWalkingInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i89 = 0; c12_i89 < 6; c12_i89++) {
    c12_b_inData[c12_i89] = (*(real_T (*)[6])c12_inData)[c12_i89];
  }

  for (c12_i90 = 0; c12_i90 < 6; c12_i90++) {
    c12_u[c12_i90] = c12_b_inData[c12_i90];
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_b_y, false);
  return c12_mxArrayOutData;
}

static const mxArray *c12_f_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_i91;
  real_T c12_b_inData[2];
  int32_T c12_i92;
  real_T c12_u[2];
  const mxArray *c12_b_y = NULL;
  SFc12_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc12_LibWalkingInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  for (c12_i91 = 0; c12_i91 < 2; c12_i91++) {
    c12_b_inData[c12_i91] = (*(real_T (*)[2])c12_inData)[c12_i91];
  }

  for (c12_i92 = 0; c12_i92 < 2; c12_i92++) {
    c12_u[c12_i92] = c12_b_inData[c12_i92];
  }

  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_b_y, false);
  return c12_mxArrayOutData;
}

const mxArray *sf_c12_LibWalking_get_eml_resolved_functions_info(void)
{
  const mxArray *c12_nameCaptureInfo = NULL;
  c12_nameCaptureInfo = NULL;
  sf_mex_assign(&c12_nameCaptureInfo, sf_mex_createstruct("structure", 2, 26, 1),
                false);
  c12_info_helper(&c12_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c12_nameCaptureInfo);
  return c12_nameCaptureInfo;
}

static void c12_info_helper(const mxArray **c12_info)
{
  const mxArray *c12_rhs0 = NULL;
  const mxArray *c12_lhs0 = NULL;
  const mxArray *c12_rhs1 = NULL;
  const mxArray *c12_lhs1 = NULL;
  const mxArray *c12_rhs2 = NULL;
  const mxArray *c12_lhs2 = NULL;
  const mxArray *c12_rhs3 = NULL;
  const mxArray *c12_lhs3 = NULL;
  const mxArray *c12_rhs4 = NULL;
  const mxArray *c12_lhs4 = NULL;
  const mxArray *c12_rhs5 = NULL;
  const mxArray *c12_lhs5 = NULL;
  const mxArray *c12_rhs6 = NULL;
  const mxArray *c12_lhs6 = NULL;
  const mxArray *c12_rhs7 = NULL;
  const mxArray *c12_lhs7 = NULL;
  const mxArray *c12_rhs8 = NULL;
  const mxArray *c12_lhs8 = NULL;
  const mxArray *c12_rhs9 = NULL;
  const mxArray *c12_lhs9 = NULL;
  const mxArray *c12_rhs10 = NULL;
  const mxArray *c12_lhs10 = NULL;
  const mxArray *c12_rhs11 = NULL;
  const mxArray *c12_lhs11 = NULL;
  const mxArray *c12_rhs12 = NULL;
  const mxArray *c12_lhs12 = NULL;
  const mxArray *c12_rhs13 = NULL;
  const mxArray *c12_lhs13 = NULL;
  const mxArray *c12_rhs14 = NULL;
  const mxArray *c12_lhs14 = NULL;
  const mxArray *c12_rhs15 = NULL;
  const mxArray *c12_lhs15 = NULL;
  const mxArray *c12_rhs16 = NULL;
  const mxArray *c12_lhs16 = NULL;
  const mxArray *c12_rhs17 = NULL;
  const mxArray *c12_lhs17 = NULL;
  const mxArray *c12_rhs18 = NULL;
  const mxArray *c12_lhs18 = NULL;
  const mxArray *c12_rhs19 = NULL;
  const mxArray *c12_lhs19 = NULL;
  const mxArray *c12_rhs20 = NULL;
  const mxArray *c12_lhs20 = NULL;
  const mxArray *c12_rhs21 = NULL;
  const mxArray *c12_lhs21 = NULL;
  const mxArray *c12_rhs22 = NULL;
  const mxArray *c12_lhs22 = NULL;
  const mxArray *c12_rhs23 = NULL;
  const mxArray *c12_lhs23 = NULL;
  const mxArray *c12_rhs24 = NULL;
  const mxArray *c12_lhs24 = NULL;
  const mxArray *c12_rhs25 = NULL;
  const mxArray *c12_lhs25 = NULL;
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("all"), "name", "name", 0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1372604014U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c12_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c12_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c12_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  3);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("coder.internal.allOrAny"),
                  "name", "name", 3);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1372604758U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c12_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c12_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("isequal"), "name", "name", 5);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1286840358U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c12_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 6);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c12_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 7);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c12_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("norm"), "name", "name", 8);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1363731868U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c12_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c12_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 10);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 10);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c12_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 11);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c12_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 12);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("abs"), "name", "name", 12);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c12_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c12_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 14);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c12_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 15);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("isnan"), "name", "name", 15);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c12_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c12_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 17);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 17);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1286840376U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c12_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 18);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c12_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(""), "context", "context", 19);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("mrdivide"), "name", "name",
                  19);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c12_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 20);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 20);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c12_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 21);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("rdivide"), "name", "name",
                  21);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c12_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 22);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c12_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 23);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c12_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("eml_div"), "name", "name",
                  24);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c12_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 25);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c12_info, c12_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c12_info, c12_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c12_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c12_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c12_info, sf_mex_duplicatearraysafe(&c12_lhs25), "lhs", "lhs",
                  25);
  sf_mex_destroy(&c12_rhs0);
  sf_mex_destroy(&c12_lhs0);
  sf_mex_destroy(&c12_rhs1);
  sf_mex_destroy(&c12_lhs1);
  sf_mex_destroy(&c12_rhs2);
  sf_mex_destroy(&c12_lhs2);
  sf_mex_destroy(&c12_rhs3);
  sf_mex_destroy(&c12_lhs3);
  sf_mex_destroy(&c12_rhs4);
  sf_mex_destroy(&c12_lhs4);
  sf_mex_destroy(&c12_rhs5);
  sf_mex_destroy(&c12_lhs5);
  sf_mex_destroy(&c12_rhs6);
  sf_mex_destroy(&c12_lhs6);
  sf_mex_destroy(&c12_rhs7);
  sf_mex_destroy(&c12_lhs7);
  sf_mex_destroy(&c12_rhs8);
  sf_mex_destroy(&c12_lhs8);
  sf_mex_destroy(&c12_rhs9);
  sf_mex_destroy(&c12_lhs9);
  sf_mex_destroy(&c12_rhs10);
  sf_mex_destroy(&c12_lhs10);
  sf_mex_destroy(&c12_rhs11);
  sf_mex_destroy(&c12_lhs11);
  sf_mex_destroy(&c12_rhs12);
  sf_mex_destroy(&c12_lhs12);
  sf_mex_destroy(&c12_rhs13);
  sf_mex_destroy(&c12_lhs13);
  sf_mex_destroy(&c12_rhs14);
  sf_mex_destroy(&c12_lhs14);
  sf_mex_destroy(&c12_rhs15);
  sf_mex_destroy(&c12_lhs15);
  sf_mex_destroy(&c12_rhs16);
  sf_mex_destroy(&c12_lhs16);
  sf_mex_destroy(&c12_rhs17);
  sf_mex_destroy(&c12_lhs17);
  sf_mex_destroy(&c12_rhs18);
  sf_mex_destroy(&c12_lhs18);
  sf_mex_destroy(&c12_rhs19);
  sf_mex_destroy(&c12_lhs19);
  sf_mex_destroy(&c12_rhs20);
  sf_mex_destroy(&c12_lhs20);
  sf_mex_destroy(&c12_rhs21);
  sf_mex_destroy(&c12_lhs21);
  sf_mex_destroy(&c12_rhs22);
  sf_mex_destroy(&c12_lhs22);
  sf_mex_destroy(&c12_rhs23);
  sf_mex_destroy(&c12_lhs23);
  sf_mex_destroy(&c12_rhs24);
  sf_mex_destroy(&c12_lhs24);
  sf_mex_destroy(&c12_rhs25);
  sf_mex_destroy(&c12_lhs25);
}

static const mxArray *c12_emlrt_marshallOut(const char * c12_u)
{
  const mxArray *c12_b_y = NULL;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", c12_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c12_u)), false);
  return c12_b_y;
}

static const mxArray *c12_b_emlrt_marshallOut(const uint32_T c12_u)
{
  const mxArray *c12_b_y = NULL;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 7, 0U, 0U, 0U, 0), false);
  return c12_b_y;
}

static real_T c12_norm(SFc12_LibWalkingInstanceStruct *chartInstance, real_T
  c12_x[6])
{
  real_T c12_b_y;
  int32_T c12_k;
  real_T c12_b_k;
  real_T c12_b_x;
  real_T c12_c_x;
  real_T c12_absx;
  real_T c12_d_x;
  boolean_T c12_b;
  boolean_T exitg1;
  (void)chartInstance;
  c12_b_y = 0.0;
  c12_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c12_k < 6)) {
    c12_b_k = 1.0 + (real_T)c12_k;
    c12_b_x = c12_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", c12_b_k), 1, 6, 1, 0) - 1];
    c12_c_x = c12_b_x;
    c12_absx = muDoubleScalarAbs(c12_c_x);
    c12_d_x = c12_absx;
    c12_b = muDoubleScalarIsNaN(c12_d_x);
    if (c12_b) {
      c12_b_y = rtNaN;
      exitg1 = true;
    } else {
      if (c12_absx > c12_b_y) {
        c12_b_y = c12_absx;
      }

      c12_k++;
    }
  }

  return c12_b_y;
}

static const mxArray *c12_g_sf_marshallOut(void *chartInstanceVoid, void
  *c12_inData)
{
  const mxArray *c12_mxArrayOutData = NULL;
  int32_T c12_u;
  const mxArray *c12_b_y = NULL;
  SFc12_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc12_LibWalkingInstanceStruct *)chartInstanceVoid;
  c12_mxArrayOutData = NULL;
  c12_u = *(int32_T *)c12_inData;
  c12_b_y = NULL;
  sf_mex_assign(&c12_b_y, sf_mex_create("y", &c12_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c12_mxArrayOutData, c12_b_y, false);
  return c12_mxArrayOutData;
}

static int32_T c12_e_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  int32_T c12_b_y;
  int32_T c12_i93;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_i93, 1, 6, 0U, 0, 0U, 0);
  c12_b_y = c12_i93;
  sf_mex_destroy(&c12_u);
  return c12_b_y;
}

static void c12_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c12_mxArrayInData, const char_T *c12_varName, void *c12_outData)
{
  const mxArray *c12_b_sfEvent;
  const char_T *c12_identifier;
  emlrtMsgIdentifier c12_thisId;
  int32_T c12_b_y;
  SFc12_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc12_LibWalkingInstanceStruct *)chartInstanceVoid;
  c12_b_sfEvent = sf_mex_dup(c12_mxArrayInData);
  c12_identifier = c12_varName;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_y = c12_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c12_b_sfEvent),
    &c12_thisId);
  sf_mex_destroy(&c12_b_sfEvent);
  *(int32_T *)c12_outData = c12_b_y;
  sf_mex_destroy(&c12_mxArrayInData);
}

static const mxArray *c12_ControlState_bus_io(void *chartInstanceVoid, void
  *c12_pData)
{
  const mxArray *c12_mxVal = NULL;
  c12_ControlStateBus c12_tmp;
  SFc12_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc12_LibWalkingInstanceStruct *)chartInstanceVoid;
  c12_mxVal = NULL;
  c12_tmp.ControllerMode = *(real_T *)&((char_T *)(c12_ControlStateBus *)
    c12_pData)[0];
  c12_tmp.SupportState = *(real_T *)&((char_T *)(c12_ControlStateBus *)c12_pData)
    [8];
  c12_tmp.StanceLeg = *(real_T *)&((char_T *)(c12_ControlStateBus *)c12_pData)
    [16];
  c12_tmp.InDoubleSupport = *(real_T *)&((char_T *)(c12_ControlStateBus *)
    c12_pData)[24];
  c12_tmp.RollPhase = *(real_T *)&((char_T *)(c12_ControlStateBus *)c12_pData)
    [32];
  c12_tmp.StepCount = *(real_T *)&((char_T *)(c12_ControlStateBus *)c12_pData)
    [40];
  c12_tmp.Error = *(real_T *)&((char_T *)(c12_ControlStateBus *)c12_pData)[48];
  sf_mex_assign(&c12_mxVal, c12_d_sf_marshallOut(chartInstance, &c12_tmp), false);
  return c12_mxVal;
}

static const mxArray *c12_ControlParams_bus_io(void *chartInstanceVoid, void
  *c12_pData)
{
  const mxArray *c12_mxVal = NULL;
  c12_ControlParamsBus c12_tmp;
  int32_T c12_i94;
  int32_T c12_i95;
  int32_T c12_i96;
  int32_T c12_i97;
  int32_T c12_i98;
  int32_T c12_i99;
  int32_T c12_i100;
  int32_T c12_i101;
  int32_T c12_i102;
  int32_T c12_i103;
  int32_T c12_i104;
  int32_T c12_i105;
  int32_T c12_i106;
  int32_T c12_i107;
  int32_T c12_i108;
  int32_T c12_i109;
  int32_T c12_i110;
  int32_T c12_i111;
  int32_T c12_i112;
  int32_T c12_i113;
  int32_T c12_i114;
  int32_T c12_i115;
  int32_T c12_i116;
  int32_T c12_i117;
  int32_T c12_i118;
  int32_T c12_i119;
  int32_T c12_i120;
  int32_T c12_i121;
  int32_T c12_i122;
  int32_T c12_i123;
  int32_T c12_i124;
  int32_T c12_i125;
  int32_T c12_i126;
  int32_T c12_i127;
  int32_T c12_i128;
  int32_T c12_i129;
  int32_T c12_i130;
  int32_T c12_i131;
  int32_T c12_i132;
  int32_T c12_i133;
  int32_T c12_i134;
  int32_T c12_i135;
  int32_T c12_i136;
  int32_T c12_i137;
  int32_T c12_i138;
  int32_T c12_i139;
  int32_T c12_i140;
  SFc12_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc12_LibWalkingInstanceStruct *)chartInstanceVoid;
  c12_mxVal = NULL;
  c12_tmp.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [0];
  c12_tmp.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [8];
  c12_tmp.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [16];
  c12_tmp.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [24];
  c12_tmp.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [32];
  c12_tmp.Supervisory.ImpactThresholdKASpringRel = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [40];
  c12_tmp.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [48];
  c12_tmp.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [56];
  c12_tmp.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [64];
  c12_tmp.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [72];
  c12_tmp.Supervisory.TransitionThresholdTorsoVel = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [80];
  for (c12_i94 = 0; c12_i94 < 2; c12_i94++) {
    c12_tmp.Supervisory.KAInjection[c12_i94] = ((real_T *)&((char_T *)
      (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [0])[88])[c12_i94];
  }

  c12_tmp.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [104];
  c12_tmp.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [112];
  for (c12_i95 = 0; c12_i95 < 6; c12_i95++) {
    c12_tmp.Supervisory.VBLAParams[c12_i95] = ((real_T *)&((char_T *)
      (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [0])[120])[c12_i95];
  }

  for (c12_i96 = 0; c12_i96 < 13; c12_i96++) {
    c12_tmp.Supervisory.BalanceParams[c12_i96] = ((real_T *)&((char_T *)
      (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [0])[168])[c12_i96];
  }

  for (c12_i97 = 0; c12_i97 < 5; c12_i97++) {
    c12_tmp.Supervisory.GaitTweaks[c12_i97] = ((real_T *)&((char_T *)
      (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [0])[272])[c12_i97];
  }

  c12_tmp.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [312];
  c12_tmp.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [320];
  c12_tmp.Supervisory.RunMode = *(real_T *)&((char_T *)(c12_SupervisoryParamsBus
    *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])[328];
  c12_tmp.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [336];
  for (c12_i98 = 0; c12_i98 < 6; c12_i98++) {
    c12_tmp.Supervisory.ErrorZeroFactor[c12_i98] = ((real_T *)&((char_T *)
      (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [0])[344])[c12_i98];
  }

  for (c12_i99 = 0; c12_i99 < 6; c12_i99++) {
    c12_tmp.Supervisory.ErrorVelZeroFactor[c12_i99] = ((real_T *)&((char_T *)
      (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [0])[392])[c12_i99];
  }

  c12_tmp.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [440];
  c12_tmp.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [448];
  c12_tmp.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [456];
  c12_tmp.Supervisory.TPosing = *(real_T *)&((char_T *)(c12_SupervisoryParamsBus
    *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])[464];
  c12_tmp.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [472];
  c12_tmp.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [480];
  c12_tmp.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [488];
  c12_tmp.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [496];
  c12_tmp.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [504];
  c12_tmp.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [512];
  c12_tmp.Supervisory.VelocityControlTorsoGain = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [520];
  c12_tmp.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [528];
  c12_tmp.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [536];
  c12_tmp.Supervisory.Theta0 = *(real_T *)&((char_T *)(c12_SupervisoryParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[0])[544];
  c12_tmp.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [552];
  c12_tmp.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [560];
  c12_tmp.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [568];
  c12_tmp.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [576];
  c12_tmp.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [584];
  c12_tmp.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [592];
  c12_tmp.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [600];
  for (c12_i100 = 0; c12_i100 < 6; c12_i100++) {
    c12_tmp.Supervisory.K1MidStanceUpdate[c12_i100] = ((real_T *)&((char_T *)
      (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [0])[608])[c12_i100];
  }

  for (c12_i101 = 0; c12_i101 < 6; c12_i101++) {
    c12_tmp.Supervisory.K2MidStanceUpdate[c12_i101] = ((real_T *)&((char_T *)
      (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [0])[656])[c12_i101];
  }

  c12_tmp.Supervisory.EnableVelocityBasedUpdate = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [704];
  for (c12_i102 = 0; c12_i102 < 6; c12_i102++) {
    c12_tmp.Supervisory.VelocityBasedUpdateK1[c12_i102] = ((real_T *)&((char_T *)
      (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [0])[712])[c12_i102];
  }

  for (c12_i103 = 0; c12_i103 < 6; c12_i103++) {
    c12_tmp.Supervisory.VelocityBasedUpdateK2[c12_i103] = ((real_T *)&((char_T *)
      (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [0])[760])[c12_i103];
  }

  c12_tmp.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [808];
  c12_i104 = 0;
  for (c12_i105 = 0; c12_i105 < 2; c12_i105++) {
    for (c12_i106 = 0; c12_i106 < 6; c12_i106++) {
      c12_tmp.Supervisory.VelocityBasedUpdateLimits[c12_i106 + c12_i104] =
        ((real_T *)&((char_T *)(c12_SupervisoryParamsBus *)&((char_T *)
           (c12_ControlParamsBus *)c12_pData)[0])[816])[c12_i106 + c12_i104];
    }

    c12_i104 += 6;
  }

  c12_tmp.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c12_SupervisoryParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[0])
    [912];
  c12_tmp.Discrete.TLastUpdate = *(real_T *)&((char_T *)(c12_DiscreteParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[920])[0];
  c12_tmp.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[920])
    [8];
  c12_tmp.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[920])
    [16];
  c12_tmp.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[920])
    [24];
  c12_tmp.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[920])
    [32];
  c12_tmp.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[920])
    [40];
  c12_tmp.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[920])
    [48];
  c12_tmp.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[920])
    [56];
  c12_tmp.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[920])
    [64];
  c12_tmp.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[920])
    [72];
  c12_tmp.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c12_DiscreteParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[920])
    [80];
  c12_i107 = 0;
  for (c12_i108 = 0; c12_i108 < 13; c12_i108++) {
    for (c12_i109 = 0; c12_i109 < 6; c12_i109++) {
      c12_tmp.Output.H0[c12_i109 + c12_i107] = ((real_T *)&((char_T *)
        (c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
        [1008])[0])[c12_i109 + c12_i107];
    }

    c12_i107 += 6;
  }

  c12_i110 = 0;
  for (c12_i111 = 0; c12_i111 < 6; c12_i111++) {
    for (c12_i112 = 0; c12_i112 < 6; c12_i112++) {
      c12_tmp.Output.HAlpha[c12_i112 + c12_i110] = ((real_T *)&((char_T *)
        (c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
        [1008])[624])[c12_i112 + c12_i110];
    }

    c12_i110 += 6;
  }

  for (c12_i113 = 0; c12_i113 < 2; c12_i113++) {
    c12_tmp.Output.ThetaLimits[c12_i113] = ((real_T *)&((char_T *)
      (c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[1008])
      [912])[c12_i113];
  }

  c12_tmp.Output.Theta.c0 = *(real_T *)&((char_T *)(c12_ThetaParamsBus *)
    &((char_T *)(c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)
    c12_pData)[1008])[928])[0];
  c12_tmp.Output.Theta.ct = *(real_T *)&((char_T *)(c12_ThetaParamsBus *)
    &((char_T *)(c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)
    c12_pData)[1008])[928])[8];
  for (c12_i114 = 0; c12_i114 < 13; c12_i114++) {
    c12_tmp.Output.Theta.cq[c12_i114] = ((real_T *)&((char_T *)
      (c12_ThetaParamsBus *)&((char_T *)(c12_OutputParamsBus *)&((char_T *)
      (c12_ControlParamsBus *)c12_pData)[1008])[928])[16])[c12_i114];
  }

  c12_tmp.Output.Theta.t0 = *(real_T *)&((char_T *)(c12_ThetaParamsBus *)
    &((char_T *)(c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)
    c12_pData)[1008])[928])[120];
  for (c12_i115 = 0; c12_i115 < 7; c12_i115++) {
    c12_tmp.Output.Theta.cz[c12_i115] = ((real_T *)&((char_T *)
      (c12_ThetaParamsBus *)&((char_T *)(c12_OutputParamsBus *)&((char_T *)
      (c12_ControlParamsBus *)c12_pData)[1008])[928])[128])[c12_i115];
  }

  c12_tmp.Output.SaturateS = *(real_T *)&((char_T *)(c12_OutputParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[1008])[1112];
  for (c12_i116 = 0; c12_i116 < 2; c12_i116++) {
    c12_tmp.Output.SLimits[c12_i116] = ((real_T *)&((char_T *)
      (c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[1008])
      [1120])[c12_i116];
  }

  c12_tmp.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[1008])
    [1136];
  c12_tmp.Output.UseCorrection = *(real_T *)&((char_T *)(c12_OutputParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[1008])[1144];
  c12_tmp.Output.SMaxCorrection = *(real_T *)&((char_T *)(c12_OutputParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[1008])[1152];
  c12_i117 = 0;
  for (c12_i118 = 0; c12_i118 < 5; c12_i118++) {
    for (c12_i119 = 0; c12_i119 < 6; c12_i119++) {
      c12_tmp.Output.HAlphaCorrection[c12_i119 + c12_i117] = ((real_T *)
        &((char_T *)(c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)
        c12_pData)[1008])[1160])[c12_i119 + c12_i117];
    }

    c12_i117 += 6;
  }

  c12_tmp.Output.Phi.c0 = *(real_T *)&((char_T *)(c12_PhiParamsBus *)&((char_T *)
                                        (c12_OutputParamsBus *)&((char_T *)
    (c12_ControlParamsBus *)c12_pData)[1008])[1400])[0];
  for (c12_i120 = 0; c12_i120 < 13; c12_i120++) {
    c12_tmp.Output.Phi.cq[c12_i120] = ((real_T *)&((char_T *)(c12_PhiParamsBus *)
      &((char_T *)(c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)
      c12_pData)[1008])[1400])[8])[c12_i120];
  }

  for (c12_i121 = 0; c12_i121 < 20; c12_i121++) {
    c12_tmp.Output.PhiAlpha[c12_i121] = ((real_T *)&((char_T *)
      (c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[1008])
      [1512])[c12_i121];
  }

  c12_tmp.Output.SaturateR = *(real_T *)&((char_T *)(c12_OutputParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[1008])[1672];
  for (c12_i122 = 0; c12_i122 < 2; c12_i122++) {
    c12_tmp.Output.RLimits[c12_i122] = ((real_T *)&((char_T *)
      (c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[1008])
      [1680])[c12_i122];
  }

  c12_i123 = 0;
  for (c12_i124 = 0; c12_i124 < 5; c12_i124++) {
    for (c12_i125 = 0; c12_i125 < 6; c12_i125++) {
      c12_tmp.Output.HBarAlpha[c12_i125 + c12_i123] = ((real_T *)&((char_T *)
        (c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
        [1008])[1696])[c12_i125 + c12_i123];
    }

    c12_i123 += 6;
  }

  c12_i126 = 0;
  for (c12_i127 = 0; c12_i127 < 2; c12_i127++) {
    for (c12_i128 = 0; c12_i128 < 6; c12_i128++) {
      c12_tmp.Output.HBarLimits[c12_i128 + c12_i126] = ((real_T *)&((char_T *)
        (c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
        [1008])[1936])[c12_i128 + c12_i126];
    }

    c12_i126 += 6;
  }

  c12_i129 = 0;
  for (c12_i130 = 0; c12_i130 < 6; c12_i130++) {
    for (c12_i131 = 0; c12_i131 < 6; c12_i131++) {
      c12_tmp.Output.HAlphaStar[c12_i131 + c12_i129] = ((real_T *)&((char_T *)
        (c12_OutputParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
        [1008])[2032])[c12_i131 + c12_i129];
    }

    c12_i129 += 6;
  }

  c12_tmp.Output.YawLimit = *(real_T *)&((char_T *)(c12_OutputParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[1008])[2320];
  for (c12_i132 = 0; c12_i132 < 6; c12_i132++) {
    c12_tmp.Feedback.kp[c12_i132] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [3336])[0])[c12_i132];
  }

  for (c12_i133 = 0; c12_i133 < 6; c12_i133++) {
    c12_tmp.Feedback.kd[c12_i133] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [3336])[48])[c12_i133];
  }

  for (c12_i134 = 0; c12_i134 < 2; c12_i134++) {
    c12_tmp.Feedback.epsilon[c12_i134] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [3336])[96])[c12_i134];
  }

  for (c12_i135 = 0; c12_i135 < 2; c12_i135++) {
    c12_tmp.Feedback.kff_grav[c12_i135] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [3336])[112])[c12_i135];
  }

  c12_tmp.Feedback.delta_grav = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[128];
  for (c12_i136 = 0; c12_i136 < 2; c12_i136++) {
    c12_tmp.Feedback.kff_decoup[c12_i136] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [3336])[136])[c12_i136];
  }

  for (c12_i137 = 0; c12_i137 < 2; c12_i137++) {
    c12_tmp.Feedback.kd_torso[c12_i137] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [3336])[152])[c12_i137];
  }

  c12_tmp.Feedback.kp_2dof = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[168];
  c12_tmp.Feedback.kd_2dof = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[176];
  c12_tmp.Feedback.kpre_2dof = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[184];
  c12_tmp.Feedback.kp_lat = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[192];
  c12_tmp.Feedback.kd_lat = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[200];
  c12_tmp.Feedback.q3d_min_lat = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[208];
  c12_tmp.Feedback.q3d_max_lat = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[216];
  c12_tmp.Feedback.w_torso_lat = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[224];
  for (c12_i138 = 0; c12_i138 < 6; c12_i138++) {
    c12_tmp.Feedback.u_ff[c12_i138] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [3336])[232])[c12_i138];
  }

  c12_tmp.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])
    [280];
  c12_tmp.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])
    [288];
  c12_tmp.Feedback.Use2DOF = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[296];
  c12_tmp.Feedback.UseDSGravComp = *(real_T *)&((char_T *)(c12_FeedbackParamsBus
    *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[304];
  c12_tmp.Feedback.lat_bias = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[312];
  c12_tmp.Feedback.lat_bias2 = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[320];
  c12_tmp.Feedback.linkFeedback = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[328];
  c12_tmp.Feedback.RIO = *(real_T *)&((char_T *)(c12_FeedbackParamsBus *)
    &((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])[336];
  c12_tmp.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])
    [344];
  for (c12_i139 = 0; c12_i139 < 6; c12_i139++) {
    c12_tmp.Feedback.FeedforwardGain[c12_i139] = ((real_T *)&((char_T *)
      (c12_FeedbackParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [3336])[352])[c12_i139];
  }

  c12_tmp.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c12_FeedbackParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)[3336])
    [400];
  c12_tmp.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c12_SaturationParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
    [3744])[0];
  for (c12_i140 = 0; c12_i140 < 2; c12_i140++) {
    c12_tmp.Saturation.QPWeight[c12_i140] = ((real_T *)&((char_T *)
      (c12_SaturationParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
      [3744])[8])[c12_i140];
  }

  c12_tmp.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c12_SaturationParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
    [3744])[24];
  c12_tmp.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c12_SaturationParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
    [3744])[32];
  c12_tmp.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c12_SaturationParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
    [3744])[40];
  c12_tmp.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c12_SaturationParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
    [3744])[48];
  c12_tmp.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c12_SaturationParamsBus *)&((char_T *)(c12_ControlParamsBus *)c12_pData)
    [3744])[56];
  sf_mex_assign(&c12_mxVal, c12_c_sf_marshallOut(chartInstance, &c12_tmp), false);
  return c12_mxVal;
}

static uint8_T c12_f_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_b_is_active_c12_LibWalking, const char_T
  *c12_identifier)
{
  uint8_T c12_b_y;
  emlrtMsgIdentifier c12_thisId;
  c12_thisId.fIdentifier = c12_identifier;
  c12_thisId.fParent = NULL;
  c12_b_y = c12_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c12_b_is_active_c12_LibWalking), &c12_thisId);
  sf_mex_destroy(&c12_b_is_active_c12_LibWalking);
  return c12_b_y;
}

static uint8_T c12_g_emlrt_marshallIn(SFc12_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c12_u, const emlrtMsgIdentifier *c12_parentId)
{
  uint8_T c12_b_y;
  uint8_T c12_u0;
  (void)chartInstance;
  sf_mex_import(c12_parentId, sf_mex_dup(c12_u), &c12_u0, 1, 3, 0U, 0, 0U, 0);
  c12_b_y = c12_u0;
  sf_mex_destroy(&c12_u);
  return c12_b_y;
}

static void init_dsm_address_info(SFc12_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc12_LibWalkingInstanceStruct
  *chartInstance)
{
  chartInstance->c12_TorqueSaturationLimits = (real_T (*)[2])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c12_y = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c12_dy = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c12_s = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    3);
  chartInstance->c12_Error = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c12_ControlState = (c12_ControlStateBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 4);
  chartInstance->c12_ControlParams = (c12_ControlParamsBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 5);
  chartInstance->c12_ErrorCount = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c12_ErrorCountIn = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c12_LibWalking_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1907693792U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(834690131U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3335344306U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2718622999U);
}

mxArray* sf_c12_LibWalking_get_post_codegen_info(void);
mxArray *sf_c12_LibWalking_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("GUkVMi26Ya3YetSku7IwIC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,5,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,6,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,6,"type",mxType);
    }

    mxSetField(mxData,6,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c12_LibWalking_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c12_LibWalking_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c12_LibWalking_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c12_LibWalking_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c12_LibWalking_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray *sf_get_sim_state_info_c12_LibWalking(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"Error\",},{M[1],M[13],T\"ErrorCount\",},{M[8],M[0],T\"is_active_c12_LibWalking\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c12_LibWalking_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc12_LibWalkingInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc12_LibWalkingInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _LibWalkingMachineNumber_,
           12,
           1,
           1,
           0,
           9,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_LibWalkingMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_LibWalkingMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _LibWalkingMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"TorqueSaturationLimits");
          _SFD_SET_DATA_PROPS(1,1,1,0,"y");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dy");
          _SFD_SET_DATA_PROPS(3,1,1,0,"s");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Error");
          _SFD_SET_DATA_PROPS(5,1,1,0,"ControlState");
          _SFD_SET_DATA_PROPS(6,1,1,0,"ControlParams");
          _SFD_SET_DATA_PROPS(7,2,0,1,"ErrorCount");
          _SFD_SET_DATA_PROPS(8,1,1,0,"ErrorCountIn");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,3,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,492);
        _SFD_CV_INIT_EML_IF(0,1,0,167,364,-1,420);

        {
          static int condStart[] = { 170, 222, 300 };

          static int condEnd[] = { 201, 280, 363 };

          static int pfixExpr[] = { 0, 1, 2, -2, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,170,364,3,0,&(condStart[0]),&(condEnd[0]),
                                5,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,222,280,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,300,363,-1,4);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c12_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_b_sf_marshallOut,(MexInFcnForType)
          c12_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_ControlState_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_ControlParams_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)c12_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c12_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c12_TorqueSaturationLimits);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c12_y);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c12_dy);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c12_s);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c12_Error);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c12_ControlState);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c12_ControlParams);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c12_ErrorCount);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c12_ErrorCountIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _LibWalkingMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "3fvRgRfmQpwavI4cWFNMpH";
}

static void sf_opaque_initialize_c12_LibWalking(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc12_LibWalkingInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c12_LibWalking((SFc12_LibWalkingInstanceStruct*)
    chartInstanceVar);
  initialize_c12_LibWalking((SFc12_LibWalkingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c12_LibWalking(void *chartInstanceVar)
{
  enable_c12_LibWalking((SFc12_LibWalkingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c12_LibWalking(void *chartInstanceVar)
{
  disable_c12_LibWalking((SFc12_LibWalkingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c12_LibWalking(void *chartInstanceVar)
{
  sf_gateway_c12_LibWalking((SFc12_LibWalkingInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c12_LibWalking(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c12_LibWalking((SFc12_LibWalkingInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c12_LibWalking(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c12_LibWalking((SFc12_LibWalkingInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c12_LibWalking(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc12_LibWalkingInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_LibWalking_optimization_info();
    }

    finalize_c12_LibWalking((SFc12_LibWalkingInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc12_LibWalking((SFc12_LibWalkingInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c12_LibWalking(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c12_LibWalking((SFc12_LibWalkingInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c12_LibWalking(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_LibWalking_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      12);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,12,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,12,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,12);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,12,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,12,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,12);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1013126576U));
  ssSetChecksum1(S,(3098303855U));
  ssSetChecksum2(S,(3668921621U));
  ssSetChecksum3(S,(3204729663U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c12_LibWalking(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c12_LibWalking(SimStruct *S)
{
  SFc12_LibWalkingInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc12_LibWalkingInstanceStruct *)utMalloc(sizeof
    (SFc12_LibWalkingInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc12_LibWalkingInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c12_LibWalking;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c12_LibWalking;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c12_LibWalking;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c12_LibWalking;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c12_LibWalking;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c12_LibWalking;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c12_LibWalking;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c12_LibWalking;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c12_LibWalking;
  chartInstance->chartInfo.mdlStart = mdlStart_c12_LibWalking;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c12_LibWalking;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c12_LibWalking_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c12_LibWalking(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c12_LibWalking(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c12_LibWalking(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c12_LibWalking_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
