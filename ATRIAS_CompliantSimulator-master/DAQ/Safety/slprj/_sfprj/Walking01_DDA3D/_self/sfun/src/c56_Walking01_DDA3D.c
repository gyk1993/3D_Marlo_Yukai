/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_DDA3D_sfun.h"
#include "c56_Walking01_DDA3D.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Walking01_DDA3D_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c56_debug_family_names[11] = { "nargin", "nargout",
  "TorqueSaturationLimits", "y", "dy", "s", "ControlState", "ControlParams",
  "ErrorCountIn", "Error", "ErrorCount" };

/* Function Declarations */
static void initialize_c56_Walking01_DDA3D(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initialize_params_c56_Walking01_DDA3D
  (SFc56_Walking01_DDA3DInstanceStruct *chartInstance);
static void enable_c56_Walking01_DDA3D(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void disable_c56_Walking01_DDA3D(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c56_update_debugger_state_c56_Walking01_DDA3D
  (SFc56_Walking01_DDA3DInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c56_Walking01_DDA3D
  (SFc56_Walking01_DDA3DInstanceStruct *chartInstance);
static void set_sim_state_c56_Walking01_DDA3D
  (SFc56_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c56_st);
static void finalize_c56_Walking01_DDA3D(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void sf_gateway_c56_Walking01_DDA3D(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void mdl_start_c56_Walking01_DDA3D(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c56_chartstep_c56_Walking01_DDA3D
  (SFc56_Walking01_DDA3DInstanceStruct *chartInstance);
static void initSimStructsc56_Walking01_DDA3D
  (SFc56_Walking01_DDA3DInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c56_machineNumber, uint32_T
  c56_chartNumber, uint32_T c56_instanceNumber);
static const mxArray *c56_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static real_T c56_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_b_ErrorCount, const char_T *c56_identifier);
static real_T c56_b_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId);
static void c56_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData);
static const mxArray *c56_b_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static boolean_T c56_c_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_b_Error, const char_T *c56_identifier);
static boolean_T c56_d_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId);
static void c56_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData);
static const mxArray *c56_c_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static const mxArray *c56_d_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static const mxArray *c56_e_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static const mxArray *c56_f_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static void c56_info_helper(const mxArray **c56_info);
static const mxArray *c56_emlrt_marshallOut(const char * c56_u);
static const mxArray *c56_b_emlrt_marshallOut(const uint32_T c56_u);
static real_T c56_norm(SFc56_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c56_x[6]);
static const mxArray *c56_g_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData);
static int32_T c56_e_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId);
static void c56_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData);
static const mxArray *c56_ControlState_bus_io(void *chartInstanceVoid, void
  *c56_pData);
static const mxArray *c56_ControlParams_bus_io(void *chartInstanceVoid, void
  *c56_pData);
static uint8_T c56_f_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_b_is_active_c56_Walking01_DDA3D, const
  char_T *c56_identifier);
static uint8_T c56_g_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId);
static void init_dsm_address_info(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c56_Walking01_DDA3D(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c56_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c56_is_active_c56_Walking01_DDA3D = 0U;
}

static void initialize_params_c56_Walking01_DDA3D
  (SFc56_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c56_Walking01_DDA3D(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c56_Walking01_DDA3D(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c56_update_debugger_state_c56_Walking01_DDA3D
  (SFc56_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c56_Walking01_DDA3D
  (SFc56_Walking01_DDA3DInstanceStruct *chartInstance)
{
  const mxArray *c56_st;
  const mxArray *c56_b_y = NULL;
  boolean_T c56_hoistedGlobal;
  boolean_T c56_u;
  const mxArray *c56_c_y = NULL;
  real_T c56_b_hoistedGlobal;
  real_T c56_b_u;
  const mxArray *c56_d_y = NULL;
  uint8_T c56_c_hoistedGlobal;
  uint8_T c56_c_u;
  const mxArray *c56_e_y = NULL;
  c56_st = NULL;
  c56_st = NULL;
  c56_b_y = NULL;
  sf_mex_assign(&c56_b_y, sf_mex_createcellmatrix(3, 1), false);
  c56_hoistedGlobal = *chartInstance->c56_Error;
  c56_u = c56_hoistedGlobal;
  c56_c_y = NULL;
  sf_mex_assign(&c56_c_y, sf_mex_create("y", &c56_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c56_b_y, 0, c56_c_y);
  c56_b_hoistedGlobal = *chartInstance->c56_ErrorCount;
  c56_b_u = c56_b_hoistedGlobal;
  c56_d_y = NULL;
  sf_mex_assign(&c56_d_y, sf_mex_create("y", &c56_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c56_b_y, 1, c56_d_y);
  c56_c_hoistedGlobal = chartInstance->c56_is_active_c56_Walking01_DDA3D;
  c56_c_u = c56_c_hoistedGlobal;
  c56_e_y = NULL;
  sf_mex_assign(&c56_e_y, sf_mex_create("y", &c56_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c56_b_y, 2, c56_e_y);
  sf_mex_assign(&c56_st, c56_b_y, false);
  return c56_st;
}

static void set_sim_state_c56_Walking01_DDA3D
  (SFc56_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c56_st)
{
  const mxArray *c56_u;
  chartInstance->c56_doneDoubleBufferReInit = true;
  c56_u = sf_mex_dup(c56_st);
  *chartInstance->c56_Error = c56_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c56_u, 0)), "Error");
  *chartInstance->c56_ErrorCount = c56_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c56_u, 1)), "ErrorCount");
  chartInstance->c56_is_active_c56_Walking01_DDA3D = c56_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c56_u, 2)),
     "is_active_c56_Walking01_DDA3D");
  sf_mex_destroy(&c56_u);
  c56_update_debugger_state_c56_Walking01_DDA3D(chartInstance);
  sf_mex_destroy(&c56_st);
}

static void finalize_c56_Walking01_DDA3D(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c56_Walking01_DDA3D(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  int32_T c56_i0;
  int32_T c56_i1;
  int32_T c56_i2;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 25U, chartInstance->c56_sfEvent);
  for (c56_i0 = 0; c56_i0 < 2; c56_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c56_TorqueSaturationLimits)[c56_i0],
                          0U);
  }

  for (c56_i1 = 0; c56_i1 < 6; c56_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c56_y)[c56_i1], 1U);
  }

  for (c56_i2 = 0; c56_i2 < 6; c56_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c56_dy)[c56_i2], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c56_s, 3U);
  chartInstance->c56_sfEvent = CALL_EVENT;
  c56_chartstep_c56_Walking01_DDA3D(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_DDA3DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c56_Error, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c56_ErrorCount, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c56_ErrorCountIn, 8U);
}

static void mdl_start_c56_Walking01_DDA3D(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c56_chartstep_c56_Walking01_DDA3D
  (SFc56_Walking01_DDA3DInstanceStruct *chartInstance)
{
  real_T c56_hoistedGlobal;
  real_T c56_b_hoistedGlobal;
  int32_T c56_i3;
  real_T c56_b_TorqueSaturationLimits[2];
  int32_T c56_i4;
  real_T c56_b_y[6];
  int32_T c56_i5;
  real_T c56_b_dy[6];
  real_T c56_b_s;
  c56_ControlStateBus c56_b_ControlState;
  c56_ControlParamsBus c56_b_ControlParams;
  int32_T c56_i6;
  int32_T c56_i7;
  int32_T c56_i8;
  int32_T c56_i9;
  int32_T c56_i10;
  int32_T c56_i11;
  int32_T c56_i12;
  int32_T c56_i13;
  int32_T c56_i14;
  int32_T c56_i15;
  int32_T c56_i16;
  int32_T c56_i17;
  int32_T c56_i18;
  int32_T c56_i19;
  int32_T c56_i20;
  int32_T c56_i21;
  int32_T c56_i22;
  int32_T c56_i23;
  int32_T c56_i24;
  int32_T c56_i25;
  int32_T c56_i26;
  int32_T c56_i27;
  int32_T c56_i28;
  int32_T c56_i29;
  int32_T c56_i30;
  int32_T c56_i31;
  int32_T c56_i32;
  int32_T c56_i33;
  int32_T c56_i34;
  int32_T c56_i35;
  int32_T c56_i36;
  int32_T c56_i37;
  int32_T c56_i38;
  int32_T c56_i39;
  int32_T c56_i40;
  int32_T c56_i41;
  int32_T c56_i42;
  int32_T c56_i43;
  int32_T c56_i44;
  int32_T c56_i45;
  int32_T c56_i46;
  int32_T c56_i47;
  int32_T c56_i48;
  int32_T c56_i49;
  int32_T c56_i50;
  int32_T c56_i51;
  int32_T c56_i52;
  real_T c56_b_ErrorCountIn;
  uint32_T c56_debug_family_var_map[11];
  real_T c56_nargin = 7.0;
  real_T c56_nargout = 2.0;
  boolean_T c56_b_Error;
  real_T c56_b_ErrorCount;
  int32_T c56_i53;
  boolean_T c56_x[2];
  boolean_T c56_c_y;
  int32_T c56_k;
  real_T c56_b_k;
  int32_T c56_i54;
  real_T c56_d_y[6];
  real_T c56_d0;
  real_T c56_A;
  real_T c56_b_x;
  real_T c56_c_x;
  real_T c56_d_x;
  real_T c56_d1;
  int32_T c56_i55;
  real_T c56_c_dy[6];
  real_T c56_d2;
  real_T c56_b_A;
  real_T c56_e_x;
  real_T c56_f_x;
  real_T c56_g_x;
  real_T c56_d3;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T exitg1;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 25U, chartInstance->c56_sfEvent);
  c56_hoistedGlobal = *chartInstance->c56_s;
  c56_b_hoistedGlobal = *chartInstance->c56_ErrorCountIn;
  for (c56_i3 = 0; c56_i3 < 2; c56_i3++) {
    c56_b_TorqueSaturationLimits[c56_i3] =
      (*chartInstance->c56_TorqueSaturationLimits)[c56_i3];
  }

  for (c56_i4 = 0; c56_i4 < 6; c56_i4++) {
    c56_b_y[c56_i4] = (*chartInstance->c56_y)[c56_i4];
  }

  for (c56_i5 = 0; c56_i5 < 6; c56_i5++) {
    c56_b_dy[c56_i5] = (*chartInstance->c56_dy)[c56_i5];
  }

  c56_b_s = c56_hoistedGlobal;
  c56_b_ControlState.ControllerMode = *(real_T *)&((char_T *)
    chartInstance->c56_ControlState)[0];
  c56_b_ControlState.SupportState = *(real_T *)&((char_T *)
    chartInstance->c56_ControlState)[8];
  c56_b_ControlState.StanceLeg = *(real_T *)&((char_T *)
    chartInstance->c56_ControlState)[16];
  c56_b_ControlState.InDoubleSupport = *(real_T *)&((char_T *)
    chartInstance->c56_ControlState)[24];
  c56_b_ControlState.RollPhase = *(real_T *)&((char_T *)
    chartInstance->c56_ControlState)[32];
  c56_b_ControlState.StepCount = *(real_T *)&((char_T *)
    chartInstance->c56_ControlState)[40];
  c56_b_ControlState.Error = *(real_T *)&((char_T *)
    chartInstance->c56_ControlState)[48];
  c56_b_ControlParams.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [0];
  c56_b_ControlParams.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [8];
  c56_b_ControlParams.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [16];
  c56_b_ControlParams.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [24];
  c56_b_ControlParams.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)
    &((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c56_ControlParams)[0])[32];
  c56_b_ControlParams.Supervisory.ImpactThresholdKASpringRel = *(real_T *)
    &((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c56_ControlParams)[0])[40];
  c56_b_ControlParams.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [48];
  c56_b_ControlParams.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [56];
  c56_b_ControlParams.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [64];
  c56_b_ControlParams.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [72];
  c56_b_ControlParams.Supervisory.TransitionThresholdTorsoVel = *(real_T *)
    &((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c56_ControlParams)[0])[80];
  for (c56_i6 = 0; c56_i6 < 2; c56_i6++) {
    c56_b_ControlParams.Supervisory.KAInjection[c56_i6] = ((real_T *)&((char_T *)
      (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
      [0])[88])[c56_i6];
  }

  c56_b_ControlParams.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T
    *)(c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
    [0])[104];
  c56_b_ControlParams.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [112];
  for (c56_i7 = 0; c56_i7 < 6; c56_i7++) {
    c56_b_ControlParams.Supervisory.VBLAParams[c56_i7] = ((real_T *)&((char_T *)
      (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
      [0])[120])[c56_i7];
  }

  for (c56_i8 = 0; c56_i8 < 13; c56_i8++) {
    c56_b_ControlParams.Supervisory.BalanceParams[c56_i8] = ((real_T *)&((char_T
      *)(c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
      [0])[168])[c56_i8];
  }

  for (c56_i9 = 0; c56_i9 < 5; c56_i9++) {
    c56_b_ControlParams.Supervisory.GaitTweaks[c56_i9] = ((real_T *)&((char_T *)
      (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
      [0])[272])[c56_i9];
  }

  c56_b_ControlParams.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [312];
  c56_b_ControlParams.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [320];
  c56_b_ControlParams.Supervisory.RunMode = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [328];
  c56_b_ControlParams.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [336];
  for (c56_i10 = 0; c56_i10 < 6; c56_i10++) {
    c56_b_ControlParams.Supervisory.ErrorZeroFactor[c56_i10] = ((real_T *)
      &((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c56_ControlParams)[0])[344])[c56_i10];
  }

  for (c56_i11 = 0; c56_i11 < 6; c56_i11++) {
    c56_b_ControlParams.Supervisory.ErrorVelZeroFactor[c56_i11] = ((real_T *)
      &((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c56_ControlParams)[0])[392])[c56_i11];
  }

  c56_b_ControlParams.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [440];
  c56_b_ControlParams.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [448];
  c56_b_ControlParams.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [456];
  c56_b_ControlParams.Supervisory.TPosing = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [464];
  c56_b_ControlParams.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [472];
  c56_b_ControlParams.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [480];
  c56_b_ControlParams.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [488];
  c56_b_ControlParams.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [496];
  c56_b_ControlParams.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T
    *)(c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
    [0])[504];
  c56_b_ControlParams.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T
    *)(c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
    [0])[512];
  c56_b_ControlParams.Supervisory.VelocityControlTorsoGain = *(real_T *)
    &((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c56_ControlParams)[0])[520];
  c56_b_ControlParams.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [528];
  c56_b_ControlParams.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [536];
  c56_b_ControlParams.Supervisory.Theta0 = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [544];
  c56_b_ControlParams.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [552];
  c56_b_ControlParams.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [560];
  c56_b_ControlParams.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T
    *)(c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
    [0])[568];
  c56_b_ControlParams.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [576];
  c56_b_ControlParams.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [584];
  c56_b_ControlParams.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [592];
  c56_b_ControlParams.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [600];
  for (c56_i12 = 0; c56_i12 < 6; c56_i12++) {
    c56_b_ControlParams.Supervisory.K1MidStanceUpdate[c56_i12] = ((real_T *)
      &((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c56_ControlParams)[0])[608])[c56_i12];
  }

  for (c56_i13 = 0; c56_i13 < 6; c56_i13++) {
    c56_b_ControlParams.Supervisory.K2MidStanceUpdate[c56_i13] = ((real_T *)
      &((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c56_ControlParams)[0])[656])[c56_i13];
  }

  c56_b_ControlParams.Supervisory.EnableVelocityBasedUpdate = *(real_T *)
    &((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c56_ControlParams)[0])[704];
  for (c56_i14 = 0; c56_i14 < 6; c56_i14++) {
    c56_b_ControlParams.Supervisory.VelocityBasedUpdateK1[c56_i14] = ((real_T *)
      &((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c56_ControlParams)[0])[712])[c56_i14];
  }

  for (c56_i15 = 0; c56_i15 < 6; c56_i15++) {
    c56_b_ControlParams.Supervisory.VelocityBasedUpdateK2[c56_i15] = ((real_T *)
      &((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c56_ControlParams)[0])[760])[c56_i15];
  }

  c56_b_ControlParams.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)
    &((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c56_ControlParams)[0])[808];
  c56_i16 = 0;
  for (c56_i17 = 0; c56_i17 < 2; c56_i17++) {
    for (c56_i18 = 0; c56_i18 < 6; c56_i18++) {
      c56_b_ControlParams.Supervisory.VelocityBasedUpdateLimits[c56_i18 +
        c56_i16] = ((real_T *)&((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
        chartInstance->c56_ControlParams)[0])[816])[c56_i18 + c56_i16];
    }

    c56_i16 += 6;
  }

  c56_b_ControlParams.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [912];
  c56_b_ControlParams.Supervisory.dx_cmd = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [920];
  c56_b_ControlParams.Supervisory.ForBackward = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [928];
  c56_b_ControlParams.Supervisory.EnableFrictionID = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [936];
  c56_b_ControlParams.Supervisory.ResetFrictionPosing = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [944];
  c56_b_ControlParams.Supervisory.MoveLegIndex = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [952];
  c56_b_ControlParams.Supervisory.dy_cmd = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[0])
    [960];
  c56_b_ControlParams.Discrete.TLastUpdate = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[968])
    [0];
  c56_b_ControlParams.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[968])
    [8];
  c56_b_ControlParams.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[968])
    [16];
  c56_b_ControlParams.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[968])
    [24];
  c56_b_ControlParams.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T
    *)(c56_DiscreteParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[968])
    [32];
  c56_b_ControlParams.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[968])
    [40];
  c56_b_ControlParams.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[968])
    [48];
  c56_b_ControlParams.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[968])
    [56];
  c56_b_ControlParams.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[968])
    [64];
  c56_b_ControlParams.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[968])
    [72];
  c56_b_ControlParams.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[968])
    [80];
  c56_i19 = 0;
  for (c56_i20 = 0; c56_i20 < 13; c56_i20++) {
    for (c56_i21 = 0; c56_i21 < 6; c56_i21++) {
      c56_b_ControlParams.Output.H0[c56_i21 + c56_i19] = ((real_T *)&((char_T *)
        (c56_OutputParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
        [1056])[0])[c56_i21 + c56_i19];
    }

    c56_i19 += 6;
  }

  c56_i22 = 0;
  for (c56_i23 = 0; c56_i23 < 6; c56_i23++) {
    for (c56_i24 = 0; c56_i24 < 6; c56_i24++) {
      c56_b_ControlParams.Output.HAlpha[c56_i24 + c56_i22] = ((real_T *)
        &((char_T *)(c56_OutputParamsBus *)&((char_T *)
        chartInstance->c56_ControlParams)[1056])[624])[c56_i24 + c56_i22];
    }

    c56_i22 += 6;
  }

  for (c56_i25 = 0; c56_i25 < 2; c56_i25++) {
    c56_b_ControlParams.Output.ThetaLimits[c56_i25] = ((real_T *)&((char_T *)
      (c56_OutputParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[1056])
      [912])[c56_i25];
  }

  c56_b_ControlParams.Output.Theta.c0 = *(real_T *)&((char_T *)
    (c56_ThetaParamsBus *)&((char_T *)(c56_OutputParamsBus *)&((char_T *)
    chartInstance->c56_ControlParams)[1056])[928])[0];
  c56_b_ControlParams.Output.Theta.ct = *(real_T *)&((char_T *)
    (c56_ThetaParamsBus *)&((char_T *)(c56_OutputParamsBus *)&((char_T *)
    chartInstance->c56_ControlParams)[1056])[928])[8];
  for (c56_i26 = 0; c56_i26 < 13; c56_i26++) {
    c56_b_ControlParams.Output.Theta.cq[c56_i26] = ((real_T *)&((char_T *)
      (c56_ThetaParamsBus *)&((char_T *)(c56_OutputParamsBus *)&((char_T *)
      chartInstance->c56_ControlParams)[1056])[928])[16])[c56_i26];
  }

  c56_b_ControlParams.Output.Theta.t0 = *(real_T *)&((char_T *)
    (c56_ThetaParamsBus *)&((char_T *)(c56_OutputParamsBus *)&((char_T *)
    chartInstance->c56_ControlParams)[1056])[928])[120];
  for (c56_i27 = 0; c56_i27 < 7; c56_i27++) {
    c56_b_ControlParams.Output.Theta.cz[c56_i27] = ((real_T *)&((char_T *)
      (c56_ThetaParamsBus *)&((char_T *)(c56_OutputParamsBus *)&((char_T *)
      chartInstance->c56_ControlParams)[1056])[928])[128])[c56_i27];
  }

  c56_b_ControlParams.Output.SaturateS = *(real_T *)&((char_T *)
    (c56_OutputParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[1056])
    [1112];
  for (c56_i28 = 0; c56_i28 < 2; c56_i28++) {
    c56_b_ControlParams.Output.SLimits[c56_i28] = ((real_T *)&((char_T *)
      (c56_OutputParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[1056])
      [1120])[c56_i28];
  }

  c56_b_ControlParams.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c56_OutputParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[1056])
    [1136];
  c56_b_ControlParams.Output.UseCorrection = *(real_T *)&((char_T *)
    (c56_OutputParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[1056])
    [1144];
  c56_b_ControlParams.Output.SMaxCorrection = *(real_T *)&((char_T *)
    (c56_OutputParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[1056])
    [1152];
  c56_i29 = 0;
  for (c56_i30 = 0; c56_i30 < 5; c56_i30++) {
    for (c56_i31 = 0; c56_i31 < 6; c56_i31++) {
      c56_b_ControlParams.Output.HAlphaCorrection[c56_i31 + c56_i29] = ((real_T *)
        &((char_T *)(c56_OutputParamsBus *)&((char_T *)
        chartInstance->c56_ControlParams)[1056])[1160])[c56_i31 + c56_i29];
    }

    c56_i29 += 6;
  }

  c56_b_ControlParams.Output.Phi.c0 = *(real_T *)&((char_T *)(c56_PhiParamsBus *)
    &((char_T *)(c56_OutputParamsBus *)&((char_T *)
    chartInstance->c56_ControlParams)[1056])[1400])[0];
  for (c56_i32 = 0; c56_i32 < 13; c56_i32++) {
    c56_b_ControlParams.Output.Phi.cq[c56_i32] = ((real_T *)&((char_T *)
      (c56_PhiParamsBus *)&((char_T *)(c56_OutputParamsBus *)&((char_T *)
      chartInstance->c56_ControlParams)[1056])[1400])[8])[c56_i32];
  }

  for (c56_i33 = 0; c56_i33 < 20; c56_i33++) {
    c56_b_ControlParams.Output.PhiAlpha[c56_i33] = ((real_T *)&((char_T *)
      (c56_OutputParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[1056])
      [1512])[c56_i33];
  }

  c56_b_ControlParams.Output.SaturateR = *(real_T *)&((char_T *)
    (c56_OutputParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[1056])
    [1672];
  for (c56_i34 = 0; c56_i34 < 2; c56_i34++) {
    c56_b_ControlParams.Output.RLimits[c56_i34] = ((real_T *)&((char_T *)
      (c56_OutputParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[1056])
      [1680])[c56_i34];
  }

  c56_i35 = 0;
  for (c56_i36 = 0; c56_i36 < 5; c56_i36++) {
    for (c56_i37 = 0; c56_i37 < 6; c56_i37++) {
      c56_b_ControlParams.Output.HBarAlpha[c56_i37 + c56_i35] = ((real_T *)
        &((char_T *)(c56_OutputParamsBus *)&((char_T *)
        chartInstance->c56_ControlParams)[1056])[1696])[c56_i37 + c56_i35];
    }

    c56_i35 += 6;
  }

  c56_i38 = 0;
  for (c56_i39 = 0; c56_i39 < 2; c56_i39++) {
    for (c56_i40 = 0; c56_i40 < 6; c56_i40++) {
      c56_b_ControlParams.Output.HBarLimits[c56_i40 + c56_i38] = ((real_T *)
        &((char_T *)(c56_OutputParamsBus *)&((char_T *)
        chartInstance->c56_ControlParams)[1056])[1936])[c56_i40 + c56_i38];
    }

    c56_i38 += 6;
  }

  c56_i41 = 0;
  for (c56_i42 = 0; c56_i42 < 6; c56_i42++) {
    for (c56_i43 = 0; c56_i43 < 6; c56_i43++) {
      c56_b_ControlParams.Output.HAlphaStar[c56_i43 + c56_i41] = ((real_T *)
        &((char_T *)(c56_OutputParamsBus *)&((char_T *)
        chartInstance->c56_ControlParams)[1056])[2032])[c56_i43 + c56_i41];
    }

    c56_i41 += 6;
  }

  c56_b_ControlParams.Output.YawLimit = *(real_T *)&((char_T *)
    (c56_OutputParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[1056])
    [2320];
  c56_b_ControlParams.Output.test = *(real_T *)&((char_T *)(c56_OutputParamsBus *)
    &((char_T *)chartInstance->c56_ControlParams)[1056])[2328];
  for (c56_i44 = 0; c56_i44 < 6; c56_i44++) {
    c56_b_ControlParams.Feedback.kp[c56_i44] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
      [3392])[0])[c56_i44];
  }

  for (c56_i45 = 0; c56_i45 < 6; c56_i45++) {
    c56_b_ControlParams.Feedback.kd[c56_i45] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
      [3392])[48])[c56_i45];
  }

  for (c56_i46 = 0; c56_i46 < 2; c56_i46++) {
    c56_b_ControlParams.Feedback.epsilon[c56_i46] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
      [3392])[96])[c56_i46];
  }

  for (c56_i47 = 0; c56_i47 < 2; c56_i47++) {
    c56_b_ControlParams.Feedback.kff_grav[c56_i47] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
      [3392])[112])[c56_i47];
  }

  c56_b_ControlParams.Feedback.delta_grav = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [128];
  for (c56_i48 = 0; c56_i48 < 2; c56_i48++) {
    c56_b_ControlParams.Feedback.kff_decoup[c56_i48] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
      [3392])[136])[c56_i48];
  }

  for (c56_i49 = 0; c56_i49 < 2; c56_i49++) {
    c56_b_ControlParams.Feedback.kd_torso[c56_i49] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
      [3392])[152])[c56_i49];
  }

  c56_b_ControlParams.Feedback.kp_2dof = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [168];
  c56_b_ControlParams.Feedback.kd_2dof = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [176];
  c56_b_ControlParams.Feedback.kpre_2dof = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [184];
  c56_b_ControlParams.Feedback.kp_lat = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [192];
  c56_b_ControlParams.Feedback.kd_lat = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [200];
  c56_b_ControlParams.Feedback.q3d_min_lat = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [208];
  c56_b_ControlParams.Feedback.q3d_max_lat = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [216];
  c56_b_ControlParams.Feedback.w_torso_lat = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [224];
  for (c56_i50 = 0; c56_i50 < 6; c56_i50++) {
    c56_b_ControlParams.Feedback.u_ff[c56_i50] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
      [3392])[232])[c56_i50];
  }

  c56_b_ControlParams.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [280];
  c56_b_ControlParams.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [288];
  c56_b_ControlParams.Feedback.Use2DOF = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [296];
  c56_b_ControlParams.Feedback.UseDSGravComp = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [304];
  c56_b_ControlParams.Feedback.lat_bias = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [312];
  c56_b_ControlParams.Feedback.lat_bias2 = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [320];
  c56_b_ControlParams.Feedback.linkFeedback = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [328];
  c56_b_ControlParams.Feedback.RIO = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [336];
  c56_b_ControlParams.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [344];
  for (c56_i51 = 0; c56_i51 < 6; c56_i51++) {
    c56_b_ControlParams.Feedback.FeedforwardGain[c56_i51] = ((real_T *)&((char_T
      *)(c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
      [3392])[352])[c56_i51];
  }

  c56_b_ControlParams.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)chartInstance->c56_ControlParams)[3392])
    [400];
  c56_b_ControlParams.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c56_SaturationParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
    [3800])[0];
  for (c56_i52 = 0; c56_i52 < 2; c56_i52++) {
    c56_b_ControlParams.Saturation.QPWeight[c56_i52] = ((real_T *)&((char_T *)
      (c56_SaturationParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
      [3800])[8])[c56_i52];
  }

  c56_b_ControlParams.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c56_SaturationParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
    [3800])[24];
  c56_b_ControlParams.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c56_SaturationParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
    [3800])[32];
  c56_b_ControlParams.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c56_SaturationParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
    [3800])[40];
  c56_b_ControlParams.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c56_SaturationParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
    [3800])[48];
  c56_b_ControlParams.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c56_SaturationParamsBus *)&((char_T *)chartInstance->c56_ControlParams)
    [3800])[56];
  c56_b_ErrorCountIn = c56_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c56_debug_family_names,
    c56_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_nargin, 0U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_nargout, 1U, c56_sf_marshallOut,
    c56_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c56_b_TorqueSaturationLimits, 2U,
    c56_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c56_b_y, 3U, c56_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c56_b_dy, 4U, c56_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c56_b_s, 5U, c56_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c56_b_ControlState, 6U, c56_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c56_b_ControlParams, 7U, c56_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c56_b_ErrorCountIn, 8U, c56_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_b_Error, 9U, c56_b_sf_marshallOut,
    c56_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c56_b_ErrorCount, 10U,
    c56_sf_marshallOut, c56_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 4);
  c56_b_ErrorCount = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 6);
  for (c56_i53 = 0; c56_i53 < 2; c56_i53++) {
    c56_x[c56_i53] = (c56_b_TorqueSaturationLimits[c56_i53] > 1.0);
  }

  c56_c_y = true;
  c56_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c56_k < 2)) {
    c56_b_k = 1.0 + (real_T)c56_k;
    if ((real_T)c56_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
         _SFD_INTEGER_CHECK("", c56_b_k), 1, 2, 1, 0) - 1] == 0.0) {
      c56_c_y = false;
      exitg1 = true;
    } else {
      c56_k++;
    }
  }

  guard1 = false;
  guard2 = false;
  if (CV_EML_COND(0, 1, 0, c56_c_y)) {
    for (c56_i54 = 0; c56_i54 < 6; c56_i54++) {
      c56_d_y[c56_i54] = c56_b_y[c56_i54];
    }

    c56_d0 = c56_norm(chartInstance, c56_d_y);
    c56_A = c56_b_ControlParams.Supervisory.MaxError * 3.1415926535897931;
    c56_b_x = c56_A;
    c56_c_x = c56_b_x;
    c56_d_x = c56_c_x;
    c56_d1 = c56_d_x / 180.0;
    if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 0, c56_d0, c56_d1, -1,
          4U, c56_d0 > c56_d1))) {
      guard2 = true;
    } else {
      for (c56_i55 = 0; c56_i55 < 6; c56_i55++) {
        c56_c_dy[c56_i55] = c56_b_dy[c56_i55];
      }

      c56_d2 = c56_norm(chartInstance, c56_c_dy);
      c56_b_A = c56_b_ControlParams.Supervisory.MaxErrorVel * 3.1415926535897931;
      c56_e_x = c56_b_A;
      c56_f_x = c56_e_x;
      c56_g_x = c56_f_x;
      c56_d3 = c56_g_x / 180.0;
      if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 1, c56_d2, c56_d3, -1,
            4U, c56_d2 > c56_d3))) {
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
    _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 10);
    c56_b_ErrorCount = c56_b_ErrorCountIn + 1.0;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, 12);
  c56_b_Error = (c56_b_ErrorCount >
                 c56_b_ControlParams.Supervisory.MaxErrorCount);
  _SFD_EML_CALL(0U, chartInstance->c56_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c56_Error = c56_b_Error;
  *chartInstance->c56_ErrorCount = c56_b_ErrorCount;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c56_sfEvent);
}

static void initSimStructsc56_Walking01_DDA3D
  (SFc56_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c56_machineNumber, uint32_T
  c56_chartNumber, uint32_T c56_instanceNumber)
{
  (void)c56_machineNumber;
  (void)c56_chartNumber;
  (void)c56_instanceNumber;
}

static const mxArray *c56_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  real_T c56_u;
  const mxArray *c56_b_y = NULL;
  SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  c56_u = *(real_T *)c56_inData;
  c56_b_y = NULL;
  sf_mex_assign(&c56_b_y, sf_mex_create("y", &c56_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c56_mxArrayOutData, c56_b_y, false);
  return c56_mxArrayOutData;
}

static real_T c56_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_b_ErrorCount, const char_T *c56_identifier)
{
  real_T c56_b_y;
  emlrtMsgIdentifier c56_thisId;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_b_y = c56_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_b_ErrorCount),
    &c56_thisId);
  sf_mex_destroy(&c56_b_ErrorCount);
  return c56_b_y;
}

static real_T c56_b_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId)
{
  real_T c56_b_y;
  real_T c56_d4;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), &c56_d4, 1, 0, 0U, 0, 0U, 0);
  c56_b_y = c56_d4;
  sf_mex_destroy(&c56_u);
  return c56_b_y;
}

static void c56_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData)
{
  const mxArray *c56_b_ErrorCount;
  const char_T *c56_identifier;
  emlrtMsgIdentifier c56_thisId;
  real_T c56_b_y;
  SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c56_b_ErrorCount = sf_mex_dup(c56_mxArrayInData);
  c56_identifier = c56_varName;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_b_y = c56_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_b_ErrorCount),
    &c56_thisId);
  sf_mex_destroy(&c56_b_ErrorCount);
  *(real_T *)c56_outData = c56_b_y;
  sf_mex_destroy(&c56_mxArrayInData);
}

static const mxArray *c56_b_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  boolean_T c56_u;
  const mxArray *c56_b_y = NULL;
  SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  c56_u = *(boolean_T *)c56_inData;
  c56_b_y = NULL;
  sf_mex_assign(&c56_b_y, sf_mex_create("y", &c56_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c56_mxArrayOutData, c56_b_y, false);
  return c56_mxArrayOutData;
}

static boolean_T c56_c_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_b_Error, const char_T *c56_identifier)
{
  boolean_T c56_b_y;
  emlrtMsgIdentifier c56_thisId;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_b_y = c56_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_b_Error),
    &c56_thisId);
  sf_mex_destroy(&c56_b_Error);
  return c56_b_y;
}

static boolean_T c56_d_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId)
{
  boolean_T c56_b_y;
  boolean_T c56_b0;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), &c56_b0, 1, 11, 0U, 0, 0U, 0);
  c56_b_y = c56_b0;
  sf_mex_destroy(&c56_u);
  return c56_b_y;
}

static void c56_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData)
{
  const mxArray *c56_b_Error;
  const char_T *c56_identifier;
  emlrtMsgIdentifier c56_thisId;
  boolean_T c56_b_y;
  SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c56_b_Error = sf_mex_dup(c56_mxArrayInData);
  c56_identifier = c56_varName;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_b_y = c56_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_b_Error),
    &c56_thisId);
  sf_mex_destroy(&c56_b_Error);
  *(boolean_T *)c56_outData = c56_b_y;
  sf_mex_destroy(&c56_mxArrayInData);
}

static const mxArray *c56_c_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData;
  c56_ControlParamsBus c56_u;
  const mxArray *c56_b_y = NULL;
  c56_SupervisoryParamsBus c56_b_u;
  const mxArray *c56_c_y = NULL;
  real_T c56_c_u;
  const mxArray *c56_d_y = NULL;
  real_T c56_d_u;
  const mxArray *c56_e_y = NULL;
  real_T c56_e_u;
  const mxArray *c56_f_y = NULL;
  real_T c56_f_u;
  const mxArray *c56_g_y = NULL;
  real_T c56_g_u;
  const mxArray *c56_h_y = NULL;
  real_T c56_h_u;
  const mxArray *c56_i_y = NULL;
  real_T c56_i_u;
  const mxArray *c56_j_y = NULL;
  real_T c56_j_u;
  const mxArray *c56_k_y = NULL;
  real_T c56_k_u;
  const mxArray *c56_l_y = NULL;
  real_T c56_l_u;
  const mxArray *c56_m_y = NULL;
  real_T c56_m_u;
  const mxArray *c56_n_y = NULL;
  int32_T c56_i56;
  real_T c56_n_u[2];
  const mxArray *c56_o_y = NULL;
  real_T c56_o_u;
  const mxArray *c56_p_y = NULL;
  real_T c56_p_u;
  const mxArray *c56_q_y = NULL;
  int32_T c56_i57;
  real_T c56_q_u[6];
  const mxArray *c56_r_y = NULL;
  int32_T c56_i58;
  real_T c56_r_u[13];
  const mxArray *c56_s_y = NULL;
  int32_T c56_i59;
  real_T c56_s_u[5];
  const mxArray *c56_t_y = NULL;
  real_T c56_t_u;
  const mxArray *c56_u_y = NULL;
  real_T c56_u_u;
  const mxArray *c56_v_y = NULL;
  real_T c56_v_u;
  const mxArray *c56_w_y = NULL;
  real_T c56_w_u;
  const mxArray *c56_x_y = NULL;
  int32_T c56_i60;
  real_T c56_x_u[6];
  const mxArray *c56_y_y = NULL;
  int32_T c56_i61;
  real_T c56_y_u[6];
  const mxArray *c56_ab_y = NULL;
  real_T c56_ab_u;
  const mxArray *c56_bb_y = NULL;
  real_T c56_bb_u;
  const mxArray *c56_cb_y = NULL;
  real_T c56_cb_u;
  const mxArray *c56_db_y = NULL;
  real_T c56_db_u;
  const mxArray *c56_eb_y = NULL;
  real_T c56_eb_u;
  const mxArray *c56_fb_y = NULL;
  real_T c56_fb_u;
  const mxArray *c56_gb_y = NULL;
  real_T c56_gb_u;
  const mxArray *c56_hb_y = NULL;
  real_T c56_hb_u;
  const mxArray *c56_ib_y = NULL;
  real_T c56_ib_u;
  const mxArray *c56_jb_y = NULL;
  real_T c56_jb_u;
  const mxArray *c56_kb_y = NULL;
  real_T c56_kb_u;
  const mxArray *c56_lb_y = NULL;
  real_T c56_lb_u;
  const mxArray *c56_mb_y = NULL;
  real_T c56_mb_u;
  const mxArray *c56_nb_y = NULL;
  real_T c56_nb_u;
  const mxArray *c56_ob_y = NULL;
  real_T c56_ob_u;
  const mxArray *c56_pb_y = NULL;
  real_T c56_pb_u;
  const mxArray *c56_qb_y = NULL;
  real_T c56_qb_u;
  const mxArray *c56_rb_y = NULL;
  real_T c56_rb_u;
  const mxArray *c56_sb_y = NULL;
  real_T c56_sb_u;
  const mxArray *c56_tb_y = NULL;
  real_T c56_tb_u;
  const mxArray *c56_ub_y = NULL;
  real_T c56_ub_u;
  const mxArray *c56_vb_y = NULL;
  int32_T c56_i62;
  real_T c56_vb_u[6];
  const mxArray *c56_wb_y = NULL;
  int32_T c56_i63;
  real_T c56_wb_u[6];
  const mxArray *c56_xb_y = NULL;
  real_T c56_xb_u;
  const mxArray *c56_yb_y = NULL;
  int32_T c56_i64;
  real_T c56_yb_u[6];
  const mxArray *c56_ac_y = NULL;
  int32_T c56_i65;
  real_T c56_ac_u[6];
  const mxArray *c56_bc_y = NULL;
  real_T c56_bc_u;
  const mxArray *c56_cc_y = NULL;
  int32_T c56_i66;
  real_T c56_cc_u[12];
  const mxArray *c56_dc_y = NULL;
  real_T c56_dc_u;
  const mxArray *c56_ec_y = NULL;
  real_T c56_ec_u;
  const mxArray *c56_fc_y = NULL;
  real_T c56_fc_u;
  const mxArray *c56_gc_y = NULL;
  real_T c56_gc_u;
  const mxArray *c56_hc_y = NULL;
  real_T c56_hc_u;
  const mxArray *c56_ic_y = NULL;
  real_T c56_ic_u;
  const mxArray *c56_jc_y = NULL;
  real_T c56_jc_u;
  const mxArray *c56_kc_y = NULL;
  c56_DiscreteParamsBus c56_kc_u;
  const mxArray *c56_lc_y = NULL;
  real_T c56_lc_u;
  const mxArray *c56_mc_y = NULL;
  real_T c56_mc_u;
  const mxArray *c56_nc_y = NULL;
  real_T c56_nc_u;
  const mxArray *c56_oc_y = NULL;
  real_T c56_oc_u;
  const mxArray *c56_pc_y = NULL;
  real_T c56_pc_u;
  const mxArray *c56_qc_y = NULL;
  real_T c56_qc_u;
  const mxArray *c56_rc_y = NULL;
  real_T c56_rc_u;
  const mxArray *c56_sc_y = NULL;
  real_T c56_sc_u;
  const mxArray *c56_tc_y = NULL;
  real_T c56_tc_u;
  const mxArray *c56_uc_y = NULL;
  real_T c56_uc_u;
  const mxArray *c56_vc_y = NULL;
  real_T c56_vc_u;
  const mxArray *c56_wc_y = NULL;
  c56_OutputParamsBus c56_wc_u;
  const mxArray *c56_xc_y = NULL;
  int32_T c56_i67;
  real_T c56_xc_u[78];
  const mxArray *c56_yc_y = NULL;
  int32_T c56_i68;
  real_T c56_yc_u[36];
  const mxArray *c56_ad_y = NULL;
  int32_T c56_i69;
  real_T c56_ad_u[2];
  const mxArray *c56_bd_y = NULL;
  c56_ThetaParamsBus c56_bd_u;
  const mxArray *c56_cd_y = NULL;
  real_T c56_cd_u;
  const mxArray *c56_dd_y = NULL;
  real_T c56_dd_u;
  const mxArray *c56_ed_y = NULL;
  int32_T c56_i70;
  real_T c56_ed_u[13];
  const mxArray *c56_fd_y = NULL;
  real_T c56_fd_u;
  const mxArray *c56_gd_y = NULL;
  int32_T c56_i71;
  real_T c56_gd_u[7];
  const mxArray *c56_hd_y = NULL;
  real_T c56_hd_u;
  const mxArray *c56_id_y = NULL;
  int32_T c56_i72;
  real_T c56_id_u[2];
  const mxArray *c56_jd_y = NULL;
  real_T c56_jd_u;
  const mxArray *c56_kd_y = NULL;
  real_T c56_kd_u;
  const mxArray *c56_ld_y = NULL;
  real_T c56_ld_u;
  const mxArray *c56_md_y = NULL;
  int32_T c56_i73;
  real_T c56_md_u[30];
  const mxArray *c56_nd_y = NULL;
  c56_PhiParamsBus c56_nd_u;
  const mxArray *c56_od_y = NULL;
  real_T c56_od_u;
  const mxArray *c56_pd_y = NULL;
  int32_T c56_i74;
  real_T c56_pd_u[13];
  const mxArray *c56_qd_y = NULL;
  int32_T c56_i75;
  real_T c56_qd_u[20];
  const mxArray *c56_rd_y = NULL;
  real_T c56_rd_u;
  const mxArray *c56_sd_y = NULL;
  int32_T c56_i76;
  real_T c56_sd_u[2];
  const mxArray *c56_td_y = NULL;
  int32_T c56_i77;
  real_T c56_td_u[30];
  const mxArray *c56_ud_y = NULL;
  int32_T c56_i78;
  real_T c56_ud_u[12];
  const mxArray *c56_vd_y = NULL;
  int32_T c56_i79;
  real_T c56_vd_u[36];
  const mxArray *c56_wd_y = NULL;
  real_T c56_wd_u;
  const mxArray *c56_xd_y = NULL;
  real_T c56_xd_u;
  const mxArray *c56_yd_y = NULL;
  c56_FeedbackParamsBus c56_yd_u;
  const mxArray *c56_ae_y = NULL;
  int32_T c56_i80;
  real_T c56_ae_u[6];
  const mxArray *c56_be_y = NULL;
  int32_T c56_i81;
  real_T c56_be_u[6];
  const mxArray *c56_ce_y = NULL;
  int32_T c56_i82;
  real_T c56_ce_u[2];
  const mxArray *c56_de_y = NULL;
  int32_T c56_i83;
  real_T c56_de_u[2];
  const mxArray *c56_ee_y = NULL;
  real_T c56_ee_u;
  const mxArray *c56_fe_y = NULL;
  int32_T c56_i84;
  real_T c56_fe_u[2];
  const mxArray *c56_ge_y = NULL;
  int32_T c56_i85;
  real_T c56_ge_u[2];
  const mxArray *c56_he_y = NULL;
  real_T c56_he_u;
  const mxArray *c56_ie_y = NULL;
  real_T c56_ie_u;
  const mxArray *c56_je_y = NULL;
  real_T c56_je_u;
  const mxArray *c56_ke_y = NULL;
  real_T c56_ke_u;
  const mxArray *c56_le_y = NULL;
  real_T c56_le_u;
  const mxArray *c56_me_y = NULL;
  real_T c56_me_u;
  const mxArray *c56_ne_y = NULL;
  real_T c56_ne_u;
  const mxArray *c56_oe_y = NULL;
  real_T c56_oe_u;
  const mxArray *c56_pe_y = NULL;
  int32_T c56_i86;
  real_T c56_pe_u[6];
  const mxArray *c56_qe_y = NULL;
  real_T c56_qe_u;
  const mxArray *c56_re_y = NULL;
  real_T c56_re_u;
  const mxArray *c56_se_y = NULL;
  real_T c56_se_u;
  const mxArray *c56_te_y = NULL;
  real_T c56_te_u;
  const mxArray *c56_ue_y = NULL;
  real_T c56_ue_u;
  const mxArray *c56_ve_y = NULL;
  real_T c56_ve_u;
  const mxArray *c56_we_y = NULL;
  real_T c56_we_u;
  const mxArray *c56_xe_y = NULL;
  real_T c56_xe_u;
  const mxArray *c56_ye_y = NULL;
  real_T c56_ye_u;
  const mxArray *c56_af_y = NULL;
  int32_T c56_i87;
  real_T c56_af_u[6];
  const mxArray *c56_bf_y = NULL;
  real_T c56_bf_u;
  const mxArray *c56_cf_y = NULL;
  c56_SaturationParamsBus c56_cf_u;
  const mxArray *c56_df_y = NULL;
  real_T c56_df_u;
  const mxArray *c56_ef_y = NULL;
  int32_T c56_i88;
  real_T c56_ef_u[2];
  const mxArray *c56_ff_y = NULL;
  real_T c56_ff_u;
  const mxArray *c56_gf_y = NULL;
  real_T c56_gf_u;
  const mxArray *c56_hf_y = NULL;
  real_T c56_hf_u;
  const mxArray *c56_if_y = NULL;
  real_T c56_if_u;
  const mxArray *c56_jf_y = NULL;
  real_T c56_jf_u;
  const mxArray *c56_kf_y = NULL;
  SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  c56_mxArrayOutData = NULL;
  c56_u = *(c56_ControlParamsBus *)c56_inData;
  c56_b_y = NULL;
  sf_mex_assign(&c56_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c56_b_u = c56_u.Supervisory;
  c56_c_y = NULL;
  sf_mex_assign(&c56_c_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c56_c_u = c56_b_u.EnableSwapOnKAAccel;
  c56_d_y = NULL;
  sf_mex_assign(&c56_d_y, sf_mex_create("y", &c56_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_d_y, "EnableSwapOnKAAccel", "EnableSwapOnKAAccel",
                  0);
  c56_d_u = c56_b_u.EnableSwapOnKASpring;
  c56_e_y = NULL;
  sf_mex_assign(&c56_e_y, sf_mex_create("y", &c56_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_e_y, "EnableSwapOnKASpring",
                  "EnableSwapOnKASpring", 0);
  c56_e_u = c56_b_u.EnableBackwardSwap;
  c56_f_y = NULL;
  sf_mex_assign(&c56_f_y, sf_mex_create("y", &c56_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_f_y, "EnableBackwardSwap", "EnableBackwardSwap",
                  0);
  c56_f_u = c56_b_u.ImpactThresholdKAAccel;
  c56_g_y = NULL;
  sf_mex_assign(&c56_g_y, sf_mex_create("y", &c56_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_g_y, "ImpactThresholdKAAccel",
                  "ImpactThresholdKAAccel", 0);
  c56_g_u = c56_b_u.ImpactThresholdKASpringAbs;
  c56_h_y = NULL;
  sf_mex_assign(&c56_h_y, sf_mex_create("y", &c56_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_h_y, "ImpactThresholdKASpringAbs",
                  "ImpactThresholdKASpringAbs", 0);
  c56_h_u = c56_b_u.ImpactThresholdKASpringRel;
  c56_i_y = NULL;
  sf_mex_assign(&c56_i_y, sf_mex_create("y", &c56_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_i_y, "ImpactThresholdKASpringRel",
                  "ImpactThresholdKASpringRel", 0);
  c56_i_u = c56_b_u.SwapThresholdS;
  c56_j_y = NULL;
  sf_mex_assign(&c56_j_y, sf_mex_create("y", &c56_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_j_y, "SwapThresholdS", "SwapThresholdS", 0);
  c56_j_u = c56_b_u.AllowDoubleSupport;
  c56_k_y = NULL;
  sf_mex_assign(&c56_k_y, sf_mex_create("y", &c56_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_k_y, "AllowDoubleSupport", "AllowDoubleSupport",
                  0);
  c56_k_u = c56_b_u.UseGaitTransition;
  c56_l_y = NULL;
  sf_mex_assign(&c56_l_y, sf_mex_create("y", &c56_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_l_y, "UseGaitTransition", "UseGaitTransition", 0);
  c56_l_u = c56_b_u.NumTransitionSteps;
  c56_m_y = NULL;
  sf_mex_assign(&c56_m_y, sf_mex_create("y", &c56_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_m_y, "NumTransitionSteps", "NumTransitionSteps",
                  0);
  c56_m_u = c56_b_u.TransitionThresholdTorsoVel;
  c56_n_y = NULL;
  sf_mex_assign(&c56_n_y, sf_mex_create("y", &c56_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_n_y, "TransitionThresholdTorsoVel",
                  "TransitionThresholdTorsoVel", 0);
  for (c56_i56 = 0; c56_i56 < 2; c56_i56++) {
    c56_n_u[c56_i56] = c56_b_u.KAInjection[c56_i56];
  }

  c56_o_y = NULL;
  sf_mex_assign(&c56_o_y, sf_mex_create("y", c56_n_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c56_c_y, c56_o_y, "KAInjection", "KAInjection", 0);
  c56_o_u = c56_b_u.MinDeltaThetaTransition;
  c56_p_y = NULL;
  sf_mex_assign(&c56_p_y, sf_mex_create("y", &c56_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_p_y, "MinDeltaThetaTransition",
                  "MinDeltaThetaTransition", 0);
  c56_p_u = c56_b_u.StartSecondGaitOnStep;
  c56_q_y = NULL;
  sf_mex_assign(&c56_q_y, sf_mex_create("y", &c56_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_q_y, "StartSecondGaitOnStep",
                  "StartSecondGaitOnStep", 0);
  for (c56_i57 = 0; c56_i57 < 6; c56_i57++) {
    c56_q_u[c56_i57] = c56_b_u.VBLAParams[c56_i57];
  }

  c56_r_y = NULL;
  sf_mex_assign(&c56_r_y, sf_mex_create("y", c56_q_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c56_c_y, c56_r_y, "VBLAParams", "VBLAParams", 0);
  for (c56_i58 = 0; c56_i58 < 13; c56_i58++) {
    c56_r_u[c56_i58] = c56_b_u.BalanceParams[c56_i58];
  }

  c56_s_y = NULL;
  sf_mex_assign(&c56_s_y, sf_mex_create("y", c56_r_u, 0, 0U, 1U, 0U, 1, 13),
                false);
  sf_mex_addfield(c56_c_y, c56_s_y, "BalanceParams", "BalanceParams", 0);
  for (c56_i59 = 0; c56_i59 < 5; c56_i59++) {
    c56_s_u[c56_i59] = c56_b_u.GaitTweaks[c56_i59];
  }

  c56_t_y = NULL;
  sf_mex_assign(&c56_t_y, sf_mex_create("y", c56_s_u, 0, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_addfield(c56_c_y, c56_t_y, "GaitTweaks", "GaitTweaks", 0);
  c56_t_u = c56_b_u.TStepInitial;
  c56_u_y = NULL;
  sf_mex_assign(&c56_u_y, sf_mex_create("y", &c56_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_u_y, "TStepInitial", "TStepInitial", 0);
  c56_u_u = c56_b_u.TMaxUpdate;
  c56_v_y = NULL;
  sf_mex_assign(&c56_v_y, sf_mex_create("y", &c56_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_v_y, "TMaxUpdate", "TMaxUpdate", 0);
  c56_v_u = c56_b_u.RunMode;
  c56_w_y = NULL;
  sf_mex_assign(&c56_w_y, sf_mex_create("y", &c56_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_w_y, "RunMode", "RunMode", 0);
  c56_w_u = c56_b_u.UseAbsoluteSwingLA;
  c56_x_y = NULL;
  sf_mex_assign(&c56_x_y, sf_mex_create("y", &c56_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_c_y, c56_x_y, "UseAbsoluteSwingLA", "UseAbsoluteSwingLA",
                  0);
  for (c56_i60 = 0; c56_i60 < 6; c56_i60++) {
    c56_x_u[c56_i60] = c56_b_u.ErrorZeroFactor[c56_i60];
  }

  c56_y_y = NULL;
  sf_mex_assign(&c56_y_y, sf_mex_create("y", c56_x_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c56_c_y, c56_y_y, "ErrorZeroFactor", "ErrorZeroFactor", 0);
  for (c56_i61 = 0; c56_i61 < 6; c56_i61++) {
    c56_y_u[c56_i61] = c56_b_u.ErrorVelZeroFactor[c56_i61];
  }

  c56_ab_y = NULL;
  sf_mex_assign(&c56_ab_y, sf_mex_create("y", c56_y_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c56_c_y, c56_ab_y, "ErrorVelZeroFactor", "ErrorVelZeroFactor",
                  0);
  c56_ab_u = c56_b_u.StanceLegInit;
  c56_bb_y = NULL;
  sf_mex_assign(&c56_bb_y, sf_mex_create("y", &c56_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_bb_y, "StanceLegInit", "StanceLegInit", 0);
  c56_bb_u = c56_b_u.ControllerModeInit;
  c56_cb_y = NULL;
  sf_mex_assign(&c56_cb_y, sf_mex_create("y", &c56_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_cb_y, "ControllerModeInit", "ControllerModeInit",
                  0);
  c56_cb_u = c56_b_u.UsePosingControl;
  c56_db_y = NULL;
  sf_mex_assign(&c56_db_y, sf_mex_create("y", &c56_cb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_db_y, "UsePosingControl", "UsePosingControl", 0);
  c56_db_u = c56_b_u.TPosing;
  c56_eb_y = NULL;
  sf_mex_assign(&c56_eb_y, sf_mex_create("y", &c56_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_eb_y, "TPosing", "TPosing", 0);
  c56_eb_u = c56_b_u.TorsoBackAngle;
  c56_fb_y = NULL;
  sf_mex_assign(&c56_fb_y, sf_mex_create("y", &c56_eb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_fb_y, "TorsoBackAngle", "TorsoBackAngle", 0);
  c56_fb_u = c56_b_u.TorsoBackOnStep;
  c56_gb_y = NULL;
  sf_mex_assign(&c56_gb_y, sf_mex_create("y", &c56_fb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_gb_y, "TorsoBackOnStep", "TorsoBackOnStep", 0);
  c56_gb_u = c56_b_u.EnergyControlGain;
  c56_hb_y = NULL;
  sf_mex_assign(&c56_hb_y, sf_mex_create("y", &c56_gb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_hb_y, "EnergyControlGain", "EnergyControlGain", 0);
  c56_hb_u = c56_b_u.EnergyControlPhi0;
  c56_ib_y = NULL;
  sf_mex_assign(&c56_ib_y, sf_mex_create("y", &c56_hb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_ib_y, "EnergyControlPhi0", "EnergyControlPhi0", 0);
  c56_ib_u = c56_b_u.VelocityControlTorsoMax;
  c56_jb_y = NULL;
  sf_mex_assign(&c56_jb_y, sf_mex_create("y", &c56_ib_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_jb_y, "VelocityControlTorsoMax",
                  "VelocityControlTorsoMax", 0);
  c56_jb_u = c56_b_u.VelocityControlTorsoMin;
  c56_kb_y = NULL;
  sf_mex_assign(&c56_kb_y, sf_mex_create("y", &c56_jb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_kb_y, "VelocityControlTorsoMin",
                  "VelocityControlTorsoMin", 0);
  c56_kb_u = c56_b_u.VelocityControlTorsoGain;
  c56_lb_y = NULL;
  sf_mex_assign(&c56_lb_y, sf_mex_create("y", &c56_kb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_lb_y, "VelocityControlTorsoGain",
                  "VelocityControlTorsoGain", 0);
  c56_lb_u = c56_b_u.VelocityControlTorsoV0;
  c56_mb_y = NULL;
  sf_mex_assign(&c56_mb_y, sf_mex_create("y", &c56_lb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_mb_y, "VelocityControlTorsoV0",
                  "VelocityControlTorsoV0", 0);
  c56_mb_u = c56_b_u.MinDeltaTheta;
  c56_nb_y = NULL;
  sf_mex_assign(&c56_nb_y, sf_mex_create("y", &c56_mb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_nb_y, "MinDeltaTheta", "MinDeltaTheta", 0);
  c56_nb_u = c56_b_u.Theta0;
  c56_ob_y = NULL;
  sf_mex_assign(&c56_ob_y, sf_mex_create("y", &c56_nb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_ob_y, "Theta0", "Theta0", 0);
  c56_ob_u = c56_b_u.KThetaPlus;
  c56_pb_y = NULL;
  sf_mex_assign(&c56_pb_y, sf_mex_create("y", &c56_ob_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_pb_y, "KThetaPlus", "KThetaPlus", 0);
  c56_pb_u = c56_b_u.KThetaMinus;
  c56_qb_y = NULL;
  sf_mex_assign(&c56_qb_y, sf_mex_create("y", &c56_pb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_qb_y, "KThetaMinus", "KThetaMinus", 0);
  c56_qb_u = c56_b_u.RollPhaseVelocityThresh;
  c56_rb_y = NULL;
  sf_mex_assign(&c56_rb_y, sf_mex_create("y", &c56_qb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_rb_y, "RollPhaseVelocityThresh",
                  "RollPhaseVelocityThresh", 0);
  c56_rb_u = c56_b_u.RollPhaseSThresh;
  c56_sb_y = NULL;
  sf_mex_assign(&c56_sb_y, sf_mex_create("y", &c56_rb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_sb_y, "RollPhaseSThresh", "RollPhaseSThresh", 0);
  c56_sb_u = c56_b_u.MaxError;
  c56_tb_y = NULL;
  sf_mex_assign(&c56_tb_y, sf_mex_create("y", &c56_sb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_tb_y, "MaxError", "MaxError", 0);
  c56_tb_u = c56_b_u.MaxErrorVel;
  c56_ub_y = NULL;
  sf_mex_assign(&c56_ub_y, sf_mex_create("y", &c56_tb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_ub_y, "MaxErrorVel", "MaxErrorVel", 0);
  c56_ub_u = c56_b_u.MaxErrorCount;
  c56_vb_y = NULL;
  sf_mex_assign(&c56_vb_y, sf_mex_create("y", &c56_ub_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_vb_y, "MaxErrorCount", "MaxErrorCount", 0);
  for (c56_i62 = 0; c56_i62 < 6; c56_i62++) {
    c56_vb_u[c56_i62] = c56_b_u.K1MidStanceUpdate[c56_i62];
  }

  c56_wb_y = NULL;
  sf_mex_assign(&c56_wb_y, sf_mex_create("y", c56_vb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c56_c_y, c56_wb_y, "K1MidStanceUpdate", "K1MidStanceUpdate", 0);
  for (c56_i63 = 0; c56_i63 < 6; c56_i63++) {
    c56_wb_u[c56_i63] = c56_b_u.K2MidStanceUpdate[c56_i63];
  }

  c56_xb_y = NULL;
  sf_mex_assign(&c56_xb_y, sf_mex_create("y", c56_wb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c56_c_y, c56_xb_y, "K2MidStanceUpdate", "K2MidStanceUpdate", 0);
  c56_xb_u = c56_b_u.EnableVelocityBasedUpdate;
  c56_yb_y = NULL;
  sf_mex_assign(&c56_yb_y, sf_mex_create("y", &c56_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_yb_y, "EnableVelocityBasedUpdate",
                  "EnableVelocityBasedUpdate", 0);
  for (c56_i64 = 0; c56_i64 < 6; c56_i64++) {
    c56_yb_u[c56_i64] = c56_b_u.VelocityBasedUpdateK1[c56_i64];
  }

  c56_ac_y = NULL;
  sf_mex_assign(&c56_ac_y, sf_mex_create("y", c56_yb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c56_c_y, c56_ac_y, "VelocityBasedUpdateK1",
                  "VelocityBasedUpdateK1", 0);
  for (c56_i65 = 0; c56_i65 < 6; c56_i65++) {
    c56_ac_u[c56_i65] = c56_b_u.VelocityBasedUpdateK2[c56_i65];
  }

  c56_bc_y = NULL;
  sf_mex_assign(&c56_bc_y, sf_mex_create("y", c56_ac_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c56_c_y, c56_bc_y, "VelocityBasedUpdateK2",
                  "VelocityBasedUpdateK2", 0);
  c56_bc_u = c56_b_u.VelocityBasedUpdateDTheta0;
  c56_cc_y = NULL;
  sf_mex_assign(&c56_cc_y, sf_mex_create("y", &c56_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_cc_y, "VelocityBasedUpdateDTheta0",
                  "VelocityBasedUpdateDTheta0", 0);
  for (c56_i66 = 0; c56_i66 < 12; c56_i66++) {
    c56_cc_u[c56_i66] = c56_b_u.VelocityBasedUpdateLimits[c56_i66];
  }

  c56_dc_y = NULL;
  sf_mex_assign(&c56_dc_y, sf_mex_create("y", c56_cc_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c56_c_y, c56_dc_y, "VelocityBasedUpdateLimits",
                  "VelocityBasedUpdateLimits", 0);
  c56_dc_u = c56_b_u.DesiredYawOffset;
  c56_ec_y = NULL;
  sf_mex_assign(&c56_ec_y, sf_mex_create("y", &c56_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_ec_y, "DesiredYawOffset", "DesiredYawOffset", 0);
  c56_ec_u = c56_b_u.dx_cmd;
  c56_fc_y = NULL;
  sf_mex_assign(&c56_fc_y, sf_mex_create("y", &c56_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_fc_y, "dx_cmd", "dx_cmd", 0);
  c56_fc_u = c56_b_u.ForBackward;
  c56_gc_y = NULL;
  sf_mex_assign(&c56_gc_y, sf_mex_create("y", &c56_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_gc_y, "ForBackward", "ForBackward", 0);
  c56_gc_u = c56_b_u.EnableFrictionID;
  c56_hc_y = NULL;
  sf_mex_assign(&c56_hc_y, sf_mex_create("y", &c56_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_hc_y, "EnableFrictionID", "EnableFrictionID", 0);
  c56_hc_u = c56_b_u.ResetFrictionPosing;
  c56_ic_y = NULL;
  sf_mex_assign(&c56_ic_y, sf_mex_create("y", &c56_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_ic_y, "ResetFrictionPosing",
                  "ResetFrictionPosing", 0);
  c56_ic_u = c56_b_u.MoveLegIndex;
  c56_jc_y = NULL;
  sf_mex_assign(&c56_jc_y, sf_mex_create("y", &c56_ic_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_jc_y, "MoveLegIndex", "MoveLegIndex", 0);
  c56_jc_u = c56_b_u.dy_cmd;
  c56_kc_y = NULL;
  sf_mex_assign(&c56_kc_y, sf_mex_create("y", &c56_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_c_y, c56_kc_y, "dy_cmd", "dy_cmd", 0);
  sf_mex_addfield(c56_b_y, c56_c_y, "Supervisory", "Supervisory", 0);
  c56_kc_u = c56_u.Discrete;
  c56_lc_y = NULL;
  sf_mex_assign(&c56_lc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c56_lc_u = c56_kc_u.TLastUpdate;
  c56_mc_y = NULL;
  sf_mex_assign(&c56_mc_y, sf_mex_create("y", &c56_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_lc_y, c56_mc_y, "TLastUpdate", "TLastUpdate", 0);
  c56_mc_u = c56_kc_u.VelocityControlLADelta;
  c56_nc_y = NULL;
  sf_mex_assign(&c56_nc_y, sf_mex_create("y", &c56_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_lc_y, c56_nc_y, "VelocityControlLADelta",
                  "VelocityControlLADelta", 0);
  c56_nc_u = c56_kc_u.VelocityControlTorsoDelta;
  c56_oc_y = NULL;
  sf_mex_assign(&c56_oc_y, sf_mex_create("y", &c56_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_lc_y, c56_oc_y, "VelocityControlTorsoDelta",
                  "VelocityControlTorsoDelta", 0);
  c56_oc_u = c56_kc_u.VelocityControlHipDistCur;
  c56_pc_y = NULL;
  sf_mex_assign(&c56_pc_y, sf_mex_create("y", &c56_oc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_lc_y, c56_pc_y, "VelocityControlHipDistCur",
                  "VelocityControlHipDistCur", 0);
  c56_pc_u = c56_kc_u.VelocityControlHipDistPrev;
  c56_qc_y = NULL;
  sf_mex_assign(&c56_qc_y, sf_mex_create("y", &c56_pc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_lc_y, c56_qc_y, "VelocityControlHipDistPrev",
                  "VelocityControlHipDistPrev", 0);
  c56_qc_u = c56_kc_u.VirtualSpringMode;
  c56_rc_y = NULL;
  sf_mex_assign(&c56_rc_y, sf_mex_create("y", &c56_qc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_lc_y, c56_rc_y, "VirtualSpringMode", "VirtualSpringMode",
                  0);
  c56_rc_u = c56_kc_u.VirtualSpringStiffness;
  c56_sc_y = NULL;
  sf_mex_assign(&c56_sc_y, sf_mex_create("y", &c56_rc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_lc_y, c56_sc_y, "VirtualSpringStiffness",
                  "VirtualSpringStiffness", 0);
  c56_sc_u = c56_kc_u.VirtualSpringDamping;
  c56_tc_y = NULL;
  sf_mex_assign(&c56_tc_y, sf_mex_create("y", &c56_sc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_lc_y, c56_tc_y, "VirtualSpringDamping",
                  "VirtualSpringDamping", 0);
  c56_tc_u = c56_kc_u.VirtualSpringModAmplitude;
  c56_uc_y = NULL;
  sf_mex_assign(&c56_uc_y, sf_mex_create("y", &c56_tc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_lc_y, c56_uc_y, "VirtualSpringModAmplitude",
                  "VirtualSpringModAmplitude", 0);
  c56_uc_u = c56_kc_u.VirtualSpringModRate;
  c56_vc_y = NULL;
  sf_mex_assign(&c56_vc_y, sf_mex_create("y", &c56_uc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_lc_y, c56_vc_y, "VirtualSpringModRate",
                  "VirtualSpringModRate", 0);
  c56_vc_u = c56_kc_u.VirtualSpringRestPos;
  c56_wc_y = NULL;
  sf_mex_assign(&c56_wc_y, sf_mex_create("y", &c56_vc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_lc_y, c56_wc_y, "VirtualSpringRestPos",
                  "VirtualSpringRestPos", 0);
  sf_mex_addfield(c56_b_y, c56_lc_y, "Discrete", "Discrete", 0);
  c56_wc_u = c56_u.Output;
  c56_xc_y = NULL;
  sf_mex_assign(&c56_xc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c56_i67 = 0; c56_i67 < 78; c56_i67++) {
    c56_xc_u[c56_i67] = c56_wc_u.H0[c56_i67];
  }

  c56_yc_y = NULL;
  sf_mex_assign(&c56_yc_y, sf_mex_create("y", c56_xc_u, 0, 0U, 1U, 0U, 2, 6, 13),
                false);
  sf_mex_addfield(c56_xc_y, c56_yc_y, "H0", "H0", 0);
  for (c56_i68 = 0; c56_i68 < 36; c56_i68++) {
    c56_yc_u[c56_i68] = c56_wc_u.HAlpha[c56_i68];
  }

  c56_ad_y = NULL;
  sf_mex_assign(&c56_ad_y, sf_mex_create("y", c56_yc_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c56_xc_y, c56_ad_y, "HAlpha", "HAlpha", 0);
  for (c56_i69 = 0; c56_i69 < 2; c56_i69++) {
    c56_ad_u[c56_i69] = c56_wc_u.ThetaLimits[c56_i69];
  }

  c56_bd_y = NULL;
  sf_mex_assign(&c56_bd_y, sf_mex_create("y", c56_ad_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c56_xc_y, c56_bd_y, "ThetaLimits", "ThetaLimits", 0);
  c56_bd_u = c56_wc_u.Theta;
  c56_cd_y = NULL;
  sf_mex_assign(&c56_cd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c56_cd_u = c56_bd_u.c0;
  c56_dd_y = NULL;
  sf_mex_assign(&c56_dd_y, sf_mex_create("y", &c56_cd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_cd_y, c56_dd_y, "c0", "c0", 0);
  c56_dd_u = c56_bd_u.ct;
  c56_ed_y = NULL;
  sf_mex_assign(&c56_ed_y, sf_mex_create("y", &c56_dd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_cd_y, c56_ed_y, "ct", "ct", 0);
  for (c56_i70 = 0; c56_i70 < 13; c56_i70++) {
    c56_ed_u[c56_i70] = c56_bd_u.cq[c56_i70];
  }

  c56_fd_y = NULL;
  sf_mex_assign(&c56_fd_y, sf_mex_create("y", c56_ed_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c56_cd_y, c56_fd_y, "cq", "cq", 0);
  c56_fd_u = c56_bd_u.t0;
  c56_gd_y = NULL;
  sf_mex_assign(&c56_gd_y, sf_mex_create("y", &c56_fd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_cd_y, c56_gd_y, "t0", "t0", 0);
  for (c56_i71 = 0; c56_i71 < 7; c56_i71++) {
    c56_gd_u[c56_i71] = c56_bd_u.cz[c56_i71];
  }

  c56_hd_y = NULL;
  sf_mex_assign(&c56_hd_y, sf_mex_create("y", c56_gd_u, 0, 0U, 1U, 0U, 2, 1, 7),
                false);
  sf_mex_addfield(c56_cd_y, c56_hd_y, "cz", "cz", 0);
  sf_mex_addfield(c56_xc_y, c56_cd_y, "Theta", "Theta", 0);
  c56_hd_u = c56_wc_u.SaturateS;
  c56_id_y = NULL;
  sf_mex_assign(&c56_id_y, sf_mex_create("y", &c56_hd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_xc_y, c56_id_y, "SaturateS", "SaturateS", 0);
  for (c56_i72 = 0; c56_i72 < 2; c56_i72++) {
    c56_id_u[c56_i72] = c56_wc_u.SLimits[c56_i72];
  }

  c56_jd_y = NULL;
  sf_mex_assign(&c56_jd_y, sf_mex_create("y", c56_id_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c56_xc_y, c56_jd_y, "SLimits", "SLimits", 0);
  c56_jd_u = c56_wc_u.EnforceIncreasingS;
  c56_kd_y = NULL;
  sf_mex_assign(&c56_kd_y, sf_mex_create("y", &c56_jd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_xc_y, c56_kd_y, "EnforceIncreasingS", "EnforceIncreasingS",
                  0);
  c56_kd_u = c56_wc_u.UseCorrection;
  c56_ld_y = NULL;
  sf_mex_assign(&c56_ld_y, sf_mex_create("y", &c56_kd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_xc_y, c56_ld_y, "UseCorrection", "UseCorrection", 0);
  c56_ld_u = c56_wc_u.SMaxCorrection;
  c56_md_y = NULL;
  sf_mex_assign(&c56_md_y, sf_mex_create("y", &c56_ld_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_xc_y, c56_md_y, "SMaxCorrection", "SMaxCorrection", 0);
  for (c56_i73 = 0; c56_i73 < 30; c56_i73++) {
    c56_md_u[c56_i73] = c56_wc_u.HAlphaCorrection[c56_i73];
  }

  c56_nd_y = NULL;
  sf_mex_assign(&c56_nd_y, sf_mex_create("y", c56_md_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c56_xc_y, c56_nd_y, "HAlphaCorrection", "HAlphaCorrection", 0);
  c56_nd_u = c56_wc_u.Phi;
  c56_od_y = NULL;
  sf_mex_assign(&c56_od_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c56_od_u = c56_nd_u.c0;
  c56_pd_y = NULL;
  sf_mex_assign(&c56_pd_y, sf_mex_create("y", &c56_od_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_od_y, c56_pd_y, "c0", "c0", 0);
  for (c56_i74 = 0; c56_i74 < 13; c56_i74++) {
    c56_pd_u[c56_i74] = c56_nd_u.cq[c56_i74];
  }

  c56_qd_y = NULL;
  sf_mex_assign(&c56_qd_y, sf_mex_create("y", c56_pd_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c56_od_y, c56_qd_y, "cq", "cq", 0);
  sf_mex_addfield(c56_xc_y, c56_od_y, "Phi", "Phi", 0);
  for (c56_i75 = 0; c56_i75 < 20; c56_i75++) {
    c56_qd_u[c56_i75] = c56_wc_u.PhiAlpha[c56_i75];
  }

  c56_rd_y = NULL;
  sf_mex_assign(&c56_rd_y, sf_mex_create("y", c56_qd_u, 0, 0U, 1U, 0U, 2, 1, 20),
                false);
  sf_mex_addfield(c56_xc_y, c56_rd_y, "PhiAlpha", "PhiAlpha", 0);
  c56_rd_u = c56_wc_u.SaturateR;
  c56_sd_y = NULL;
  sf_mex_assign(&c56_sd_y, sf_mex_create("y", &c56_rd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_xc_y, c56_sd_y, "SaturateR", "SaturateR", 0);
  for (c56_i76 = 0; c56_i76 < 2; c56_i76++) {
    c56_sd_u[c56_i76] = c56_wc_u.RLimits[c56_i76];
  }

  c56_td_y = NULL;
  sf_mex_assign(&c56_td_y, sf_mex_create("y", c56_sd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c56_xc_y, c56_td_y, "RLimits", "RLimits", 0);
  for (c56_i77 = 0; c56_i77 < 30; c56_i77++) {
    c56_td_u[c56_i77] = c56_wc_u.HBarAlpha[c56_i77];
  }

  c56_ud_y = NULL;
  sf_mex_assign(&c56_ud_y, sf_mex_create("y", c56_td_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c56_xc_y, c56_ud_y, "HBarAlpha", "HBarAlpha", 0);
  for (c56_i78 = 0; c56_i78 < 12; c56_i78++) {
    c56_ud_u[c56_i78] = c56_wc_u.HBarLimits[c56_i78];
  }

  c56_vd_y = NULL;
  sf_mex_assign(&c56_vd_y, sf_mex_create("y", c56_ud_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c56_xc_y, c56_vd_y, "HBarLimits", "HBarLimits", 0);
  for (c56_i79 = 0; c56_i79 < 36; c56_i79++) {
    c56_vd_u[c56_i79] = c56_wc_u.HAlphaStar[c56_i79];
  }

  c56_wd_y = NULL;
  sf_mex_assign(&c56_wd_y, sf_mex_create("y", c56_vd_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c56_xc_y, c56_wd_y, "HAlphaStar", "HAlphaStar", 0);
  c56_wd_u = c56_wc_u.YawLimit;
  c56_xd_y = NULL;
  sf_mex_assign(&c56_xd_y, sf_mex_create("y", &c56_wd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_xc_y, c56_xd_y, "YawLimit", "YawLimit", 0);
  c56_xd_u = c56_wc_u.test;
  c56_yd_y = NULL;
  sf_mex_assign(&c56_yd_y, sf_mex_create("y", &c56_xd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_xc_y, c56_yd_y, "test", "test", 0);
  sf_mex_addfield(c56_b_y, c56_xc_y, "Output", "Output", 0);
  c56_yd_u = c56_u.Feedback;
  c56_ae_y = NULL;
  sf_mex_assign(&c56_ae_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c56_i80 = 0; c56_i80 < 6; c56_i80++) {
    c56_ae_u[c56_i80] = c56_yd_u.kp[c56_i80];
  }

  c56_be_y = NULL;
  sf_mex_assign(&c56_be_y, sf_mex_create("y", c56_ae_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c56_ae_y, c56_be_y, "kp", "kp", 0);
  for (c56_i81 = 0; c56_i81 < 6; c56_i81++) {
    c56_be_u[c56_i81] = c56_yd_u.kd[c56_i81];
  }

  c56_ce_y = NULL;
  sf_mex_assign(&c56_ce_y, sf_mex_create("y", c56_be_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c56_ae_y, c56_ce_y, "kd", "kd", 0);
  for (c56_i82 = 0; c56_i82 < 2; c56_i82++) {
    c56_ce_u[c56_i82] = c56_yd_u.epsilon[c56_i82];
  }

  c56_de_y = NULL;
  sf_mex_assign(&c56_de_y, sf_mex_create("y", c56_ce_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c56_ae_y, c56_de_y, "epsilon", "epsilon", 0);
  for (c56_i83 = 0; c56_i83 < 2; c56_i83++) {
    c56_de_u[c56_i83] = c56_yd_u.kff_grav[c56_i83];
  }

  c56_ee_y = NULL;
  sf_mex_assign(&c56_ee_y, sf_mex_create("y", c56_de_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c56_ae_y, c56_ee_y, "kff_grav", "kff_grav", 0);
  c56_ee_u = c56_yd_u.delta_grav;
  c56_fe_y = NULL;
  sf_mex_assign(&c56_fe_y, sf_mex_create("y", &c56_ee_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_fe_y, "delta_grav", "delta_grav", 0);
  for (c56_i84 = 0; c56_i84 < 2; c56_i84++) {
    c56_fe_u[c56_i84] = c56_yd_u.kff_decoup[c56_i84];
  }

  c56_ge_y = NULL;
  sf_mex_assign(&c56_ge_y, sf_mex_create("y", c56_fe_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c56_ae_y, c56_ge_y, "kff_decoup", "kff_decoup", 0);
  for (c56_i85 = 0; c56_i85 < 2; c56_i85++) {
    c56_ge_u[c56_i85] = c56_yd_u.kd_torso[c56_i85];
  }

  c56_he_y = NULL;
  sf_mex_assign(&c56_he_y, sf_mex_create("y", c56_ge_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c56_ae_y, c56_he_y, "kd_torso", "kd_torso", 0);
  c56_he_u = c56_yd_u.kp_2dof;
  c56_ie_y = NULL;
  sf_mex_assign(&c56_ie_y, sf_mex_create("y", &c56_he_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_ie_y, "kp_2dof", "kp_2dof", 0);
  c56_ie_u = c56_yd_u.kd_2dof;
  c56_je_y = NULL;
  sf_mex_assign(&c56_je_y, sf_mex_create("y", &c56_ie_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_je_y, "kd_2dof", "kd_2dof", 0);
  c56_je_u = c56_yd_u.kpre_2dof;
  c56_ke_y = NULL;
  sf_mex_assign(&c56_ke_y, sf_mex_create("y", &c56_je_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_ke_y, "kpre_2dof", "kpre_2dof", 0);
  c56_ke_u = c56_yd_u.kp_lat;
  c56_le_y = NULL;
  sf_mex_assign(&c56_le_y, sf_mex_create("y", &c56_ke_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_le_y, "kp_lat", "kp_lat", 0);
  c56_le_u = c56_yd_u.kd_lat;
  c56_me_y = NULL;
  sf_mex_assign(&c56_me_y, sf_mex_create("y", &c56_le_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_me_y, "kd_lat", "kd_lat", 0);
  c56_me_u = c56_yd_u.q3d_min_lat;
  c56_ne_y = NULL;
  sf_mex_assign(&c56_ne_y, sf_mex_create("y", &c56_me_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_ne_y, "q3d_min_lat", "q3d_min_lat", 0);
  c56_ne_u = c56_yd_u.q3d_max_lat;
  c56_oe_y = NULL;
  sf_mex_assign(&c56_oe_y, sf_mex_create("y", &c56_ne_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_oe_y, "q3d_max_lat", "q3d_max_lat", 0);
  c56_oe_u = c56_yd_u.w_torso_lat;
  c56_pe_y = NULL;
  sf_mex_assign(&c56_pe_y, sf_mex_create("y", &c56_oe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_pe_y, "w_torso_lat", "w_torso_lat", 0);
  for (c56_i86 = 0; c56_i86 < 6; c56_i86++) {
    c56_pe_u[c56_i86] = c56_yd_u.u_ff[c56_i86];
  }

  c56_qe_y = NULL;
  sf_mex_assign(&c56_qe_y, sf_mex_create("y", c56_pe_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c56_ae_y, c56_qe_y, "u_ff", "u_ff", 0);
  c56_qe_u = c56_yd_u.LateralControlMode;
  c56_re_y = NULL;
  sf_mex_assign(&c56_re_y, sf_mex_create("y", &c56_qe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_re_y, "LateralControlMode", "LateralControlMode",
                  0);
  c56_re_u = c56_yd_u.DecouplingMode;
  c56_se_y = NULL;
  sf_mex_assign(&c56_se_y, sf_mex_create("y", &c56_re_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_se_y, "DecouplingMode", "DecouplingMode", 0);
  c56_se_u = c56_yd_u.Use2DOF;
  c56_te_y = NULL;
  sf_mex_assign(&c56_te_y, sf_mex_create("y", &c56_se_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_te_y, "Use2DOF", "Use2DOF", 0);
  c56_te_u = c56_yd_u.UseDSGravComp;
  c56_ue_y = NULL;
  sf_mex_assign(&c56_ue_y, sf_mex_create("y", &c56_te_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_ue_y, "UseDSGravComp", "UseDSGravComp", 0);
  c56_ue_u = c56_yd_u.lat_bias;
  c56_ve_y = NULL;
  sf_mex_assign(&c56_ve_y, sf_mex_create("y", &c56_ue_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_ve_y, "lat_bias", "lat_bias", 0);
  c56_ve_u = c56_yd_u.lat_bias2;
  c56_we_y = NULL;
  sf_mex_assign(&c56_we_y, sf_mex_create("y", &c56_ve_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_we_y, "lat_bias2", "lat_bias2", 0);
  c56_we_u = c56_yd_u.linkFeedback;
  c56_xe_y = NULL;
  sf_mex_assign(&c56_xe_y, sf_mex_create("y", &c56_we_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_xe_y, "linkFeedback", "linkFeedback", 0);
  c56_xe_u = c56_yd_u.RIO;
  c56_ye_y = NULL;
  sf_mex_assign(&c56_ye_y, sf_mex_create("y", &c56_xe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_ye_y, "RIO", "RIO", 0);
  c56_ye_u = c56_yd_u.SelectFeedforward;
  c56_af_y = NULL;
  sf_mex_assign(&c56_af_y, sf_mex_create("y", &c56_ye_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_af_y, "SelectFeedforward", "SelectFeedforward",
                  0);
  for (c56_i87 = 0; c56_i87 < 6; c56_i87++) {
    c56_af_u[c56_i87] = c56_yd_u.FeedforwardGain[c56_i87];
  }

  c56_bf_y = NULL;
  sf_mex_assign(&c56_bf_y, sf_mex_create("y", c56_af_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c56_ae_y, c56_bf_y, "FeedforwardGain", "FeedforwardGain", 0);
  c56_bf_u = c56_yd_u.EnableFeedforwardOnStep;
  c56_cf_y = NULL;
  sf_mex_assign(&c56_cf_y, sf_mex_create("y", &c56_bf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_ae_y, c56_cf_y, "EnableFeedforwardOnStep",
                  "EnableFeedforwardOnStep", 0);
  sf_mex_addfield(c56_b_y, c56_ae_y, "Feedback", "Feedback", 0);
  c56_cf_u = c56_u.Saturation;
  c56_df_y = NULL;
  sf_mex_assign(&c56_df_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c56_df_u = c56_cf_u.UseQPSaturation;
  c56_ef_y = NULL;
  sf_mex_assign(&c56_ef_y, sf_mex_create("y", &c56_df_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_df_y, c56_ef_y, "UseQPSaturation", "UseQPSaturation", 0);
  for (c56_i88 = 0; c56_i88 < 2; c56_i88++) {
    c56_ef_u[c56_i88] = c56_cf_u.QPWeight[c56_i88];
  }

  c56_ff_y = NULL;
  sf_mex_assign(&c56_ff_y, sf_mex_create("y", c56_ef_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c56_df_y, c56_ff_y, "QPWeight", "QPWeight", 0);
  c56_ff_u = c56_cf_u.UseKASaturation;
  c56_gf_y = NULL;
  sf_mex_assign(&c56_gf_y, sf_mex_create("y", &c56_ff_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_df_y, c56_gf_y, "UseKASaturation", "UseKASaturation", 0);
  c56_gf_u = c56_cf_u.KASaturationS1;
  c56_hf_y = NULL;
  sf_mex_assign(&c56_hf_y, sf_mex_create("y", &c56_gf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_df_y, c56_hf_y, "KASaturationS1", "KASaturationS1", 0);
  c56_hf_u = c56_cf_u.KASaturationS2;
  c56_if_y = NULL;
  sf_mex_assign(&c56_if_y, sf_mex_create("y", &c56_hf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_df_y, c56_if_y, "KASaturationS2", "KASaturationS2", 0);
  c56_if_u = c56_cf_u.KASaturationEarly;
  c56_jf_y = NULL;
  sf_mex_assign(&c56_jf_y, sf_mex_create("y", &c56_if_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_df_y, c56_jf_y, "KASaturationEarly", "KASaturationEarly",
                  0);
  c56_jf_u = c56_cf_u.KASaturationMax;
  c56_kf_y = NULL;
  sf_mex_assign(&c56_kf_y, sf_mex_create("y", &c56_jf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c56_df_y, c56_kf_y, "KASaturationMax", "KASaturationMax", 0);
  sf_mex_addfield(c56_b_y, c56_df_y, "Saturation", "Saturation", 0);
  sf_mex_assign(&c56_mxArrayOutData, c56_b_y, false);
  return c56_mxArrayOutData;
}

static const mxArray *c56_d_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  c56_ControlStateBus c56_u;
  const mxArray *c56_b_y = NULL;
  real_T c56_b_u;
  const mxArray *c56_c_y = NULL;
  real_T c56_c_u;
  const mxArray *c56_d_y = NULL;
  real_T c56_d_u;
  const mxArray *c56_e_y = NULL;
  real_T c56_e_u;
  const mxArray *c56_f_y = NULL;
  real_T c56_f_u;
  const mxArray *c56_g_y = NULL;
  real_T c56_g_u;
  const mxArray *c56_h_y = NULL;
  real_T c56_h_u;
  const mxArray *c56_i_y = NULL;
  SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  c56_u = *(c56_ControlStateBus *)c56_inData;
  c56_b_y = NULL;
  sf_mex_assign(&c56_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c56_b_u = c56_u.ControllerMode;
  c56_c_y = NULL;
  sf_mex_assign(&c56_c_y, sf_mex_create("y", &c56_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_b_y, c56_c_y, "ControllerMode", "ControllerMode", 0);
  c56_c_u = c56_u.SupportState;
  c56_d_y = NULL;
  sf_mex_assign(&c56_d_y, sf_mex_create("y", &c56_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_b_y, c56_d_y, "SupportState", "SupportState", 0);
  c56_d_u = c56_u.StanceLeg;
  c56_e_y = NULL;
  sf_mex_assign(&c56_e_y, sf_mex_create("y", &c56_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_b_y, c56_e_y, "StanceLeg", "StanceLeg", 0);
  c56_e_u = c56_u.InDoubleSupport;
  c56_f_y = NULL;
  sf_mex_assign(&c56_f_y, sf_mex_create("y", &c56_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_b_y, c56_f_y, "InDoubleSupport", "InDoubleSupport", 0);
  c56_f_u = c56_u.RollPhase;
  c56_g_y = NULL;
  sf_mex_assign(&c56_g_y, sf_mex_create("y", &c56_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_b_y, c56_g_y, "RollPhase", "RollPhase", 0);
  c56_g_u = c56_u.StepCount;
  c56_h_y = NULL;
  sf_mex_assign(&c56_h_y, sf_mex_create("y", &c56_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_b_y, c56_h_y, "StepCount", "StepCount", 0);
  c56_h_u = c56_u.Error;
  c56_i_y = NULL;
  sf_mex_assign(&c56_i_y, sf_mex_create("y", &c56_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c56_b_y, c56_i_y, "Error", "Error", 0);
  sf_mex_assign(&c56_mxArrayOutData, c56_b_y, false);
  return c56_mxArrayOutData;
}

static const mxArray *c56_e_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  int32_T c56_i89;
  real_T c56_b_inData[6];
  int32_T c56_i90;
  real_T c56_u[6];
  const mxArray *c56_b_y = NULL;
  SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  for (c56_i89 = 0; c56_i89 < 6; c56_i89++) {
    c56_b_inData[c56_i89] = (*(real_T (*)[6])c56_inData)[c56_i89];
  }

  for (c56_i90 = 0; c56_i90 < 6; c56_i90++) {
    c56_u[c56_i90] = c56_b_inData[c56_i90];
  }

  c56_b_y = NULL;
  sf_mex_assign(&c56_b_y, sf_mex_create("y", c56_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c56_mxArrayOutData, c56_b_y, false);
  return c56_mxArrayOutData;
}

static const mxArray *c56_f_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  int32_T c56_i91;
  real_T c56_b_inData[2];
  int32_T c56_i92;
  real_T c56_u[2];
  const mxArray *c56_b_y = NULL;
  SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  for (c56_i91 = 0; c56_i91 < 2; c56_i91++) {
    c56_b_inData[c56_i91] = (*(real_T (*)[2])c56_inData)[c56_i91];
  }

  for (c56_i92 = 0; c56_i92 < 2; c56_i92++) {
    c56_u[c56_i92] = c56_b_inData[c56_i92];
  }

  c56_b_y = NULL;
  sf_mex_assign(&c56_b_y, sf_mex_create("y", c56_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c56_mxArrayOutData, c56_b_y, false);
  return c56_mxArrayOutData;
}

const mxArray *sf_c56_Walking01_DDA3D_get_eml_resolved_functions_info(void)
{
  const mxArray *c56_nameCaptureInfo = NULL;
  c56_nameCaptureInfo = NULL;
  sf_mex_assign(&c56_nameCaptureInfo, sf_mex_createstruct("structure", 2, 26, 1),
                false);
  c56_info_helper(&c56_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c56_nameCaptureInfo);
  return c56_nameCaptureInfo;
}

static void c56_info_helper(const mxArray **c56_info)
{
  const mxArray *c56_rhs0 = NULL;
  const mxArray *c56_lhs0 = NULL;
  const mxArray *c56_rhs1 = NULL;
  const mxArray *c56_lhs1 = NULL;
  const mxArray *c56_rhs2 = NULL;
  const mxArray *c56_lhs2 = NULL;
  const mxArray *c56_rhs3 = NULL;
  const mxArray *c56_lhs3 = NULL;
  const mxArray *c56_rhs4 = NULL;
  const mxArray *c56_lhs4 = NULL;
  const mxArray *c56_rhs5 = NULL;
  const mxArray *c56_lhs5 = NULL;
  const mxArray *c56_rhs6 = NULL;
  const mxArray *c56_lhs6 = NULL;
  const mxArray *c56_rhs7 = NULL;
  const mxArray *c56_lhs7 = NULL;
  const mxArray *c56_rhs8 = NULL;
  const mxArray *c56_lhs8 = NULL;
  const mxArray *c56_rhs9 = NULL;
  const mxArray *c56_lhs9 = NULL;
  const mxArray *c56_rhs10 = NULL;
  const mxArray *c56_lhs10 = NULL;
  const mxArray *c56_rhs11 = NULL;
  const mxArray *c56_lhs11 = NULL;
  const mxArray *c56_rhs12 = NULL;
  const mxArray *c56_lhs12 = NULL;
  const mxArray *c56_rhs13 = NULL;
  const mxArray *c56_lhs13 = NULL;
  const mxArray *c56_rhs14 = NULL;
  const mxArray *c56_lhs14 = NULL;
  const mxArray *c56_rhs15 = NULL;
  const mxArray *c56_lhs15 = NULL;
  const mxArray *c56_rhs16 = NULL;
  const mxArray *c56_lhs16 = NULL;
  const mxArray *c56_rhs17 = NULL;
  const mxArray *c56_lhs17 = NULL;
  const mxArray *c56_rhs18 = NULL;
  const mxArray *c56_lhs18 = NULL;
  const mxArray *c56_rhs19 = NULL;
  const mxArray *c56_lhs19 = NULL;
  const mxArray *c56_rhs20 = NULL;
  const mxArray *c56_lhs20 = NULL;
  const mxArray *c56_rhs21 = NULL;
  const mxArray *c56_lhs21 = NULL;
  const mxArray *c56_rhs22 = NULL;
  const mxArray *c56_lhs22 = NULL;
  const mxArray *c56_rhs23 = NULL;
  const mxArray *c56_lhs23 = NULL;
  const mxArray *c56_rhs24 = NULL;
  const mxArray *c56_lhs24 = NULL;
  const mxArray *c56_rhs25 = NULL;
  const mxArray *c56_lhs25 = NULL;
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("all"), "name", "name", 0);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1372604014U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c56_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  1);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c56_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  2);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c56_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  3);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("coder.internal.allOrAny"),
                  "name", "name", 3);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1372604758U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c56_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c56_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("isequal"), "name", "name", 5);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1286840358U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c56_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 6);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c56_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 7);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c56_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("norm"), "name", "name", 8);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1363731868U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c56_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c56_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 10);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 10);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c56_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 11);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c56_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 12);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("abs"), "name", "name", 12);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c56_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c56_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 14);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c56_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 15);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("isnan"), "name", "name", 15);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c56_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c56_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 17);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 17);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1286840376U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c56_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 18);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c56_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(""), "context", "context", 19);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("mrdivide"), "name", "name",
                  19);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c56_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 20);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 20);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c56_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 21);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("rdivide"), "name", "name",
                  21);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c56_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 22);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c56_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 23);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c56_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("eml_div"), "name", "name",
                  24);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c56_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 25);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c56_info, c56_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c56_info, c56_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c56_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c56_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c56_info, sf_mex_duplicatearraysafe(&c56_lhs25), "lhs", "lhs",
                  25);
  sf_mex_destroy(&c56_rhs0);
  sf_mex_destroy(&c56_lhs0);
  sf_mex_destroy(&c56_rhs1);
  sf_mex_destroy(&c56_lhs1);
  sf_mex_destroy(&c56_rhs2);
  sf_mex_destroy(&c56_lhs2);
  sf_mex_destroy(&c56_rhs3);
  sf_mex_destroy(&c56_lhs3);
  sf_mex_destroy(&c56_rhs4);
  sf_mex_destroy(&c56_lhs4);
  sf_mex_destroy(&c56_rhs5);
  sf_mex_destroy(&c56_lhs5);
  sf_mex_destroy(&c56_rhs6);
  sf_mex_destroy(&c56_lhs6);
  sf_mex_destroy(&c56_rhs7);
  sf_mex_destroy(&c56_lhs7);
  sf_mex_destroy(&c56_rhs8);
  sf_mex_destroy(&c56_lhs8);
  sf_mex_destroy(&c56_rhs9);
  sf_mex_destroy(&c56_lhs9);
  sf_mex_destroy(&c56_rhs10);
  sf_mex_destroy(&c56_lhs10);
  sf_mex_destroy(&c56_rhs11);
  sf_mex_destroy(&c56_lhs11);
  sf_mex_destroy(&c56_rhs12);
  sf_mex_destroy(&c56_lhs12);
  sf_mex_destroy(&c56_rhs13);
  sf_mex_destroy(&c56_lhs13);
  sf_mex_destroy(&c56_rhs14);
  sf_mex_destroy(&c56_lhs14);
  sf_mex_destroy(&c56_rhs15);
  sf_mex_destroy(&c56_lhs15);
  sf_mex_destroy(&c56_rhs16);
  sf_mex_destroy(&c56_lhs16);
  sf_mex_destroy(&c56_rhs17);
  sf_mex_destroy(&c56_lhs17);
  sf_mex_destroy(&c56_rhs18);
  sf_mex_destroy(&c56_lhs18);
  sf_mex_destroy(&c56_rhs19);
  sf_mex_destroy(&c56_lhs19);
  sf_mex_destroy(&c56_rhs20);
  sf_mex_destroy(&c56_lhs20);
  sf_mex_destroy(&c56_rhs21);
  sf_mex_destroy(&c56_lhs21);
  sf_mex_destroy(&c56_rhs22);
  sf_mex_destroy(&c56_lhs22);
  sf_mex_destroy(&c56_rhs23);
  sf_mex_destroy(&c56_lhs23);
  sf_mex_destroy(&c56_rhs24);
  sf_mex_destroy(&c56_lhs24);
  sf_mex_destroy(&c56_rhs25);
  sf_mex_destroy(&c56_lhs25);
}

static const mxArray *c56_emlrt_marshallOut(const char * c56_u)
{
  const mxArray *c56_b_y = NULL;
  c56_b_y = NULL;
  sf_mex_assign(&c56_b_y, sf_mex_create("y", c56_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c56_u)), false);
  return c56_b_y;
}

static const mxArray *c56_b_emlrt_marshallOut(const uint32_T c56_u)
{
  const mxArray *c56_b_y = NULL;
  c56_b_y = NULL;
  sf_mex_assign(&c56_b_y, sf_mex_create("y", &c56_u, 7, 0U, 0U, 0U, 0), false);
  return c56_b_y;
}

static real_T c56_norm(SFc56_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c56_x[6])
{
  real_T c56_b_y;
  int32_T c56_k;
  real_T c56_b_k;
  real_T c56_b_x;
  real_T c56_c_x;
  real_T c56_absx;
  real_T c56_d_x;
  boolean_T c56_b;
  boolean_T exitg1;
  (void)chartInstance;
  c56_b_y = 0.0;
  c56_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c56_k < 6)) {
    c56_b_k = 1.0 + (real_T)c56_k;
    c56_b_x = c56_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", c56_b_k), 1, 6, 1, 0) - 1];
    c56_c_x = c56_b_x;
    c56_absx = muDoubleScalarAbs(c56_c_x);
    c56_d_x = c56_absx;
    c56_b = muDoubleScalarIsNaN(c56_d_x);
    if (c56_b) {
      c56_b_y = rtNaN;
      exitg1 = true;
    } else {
      if (c56_absx > c56_b_y) {
        c56_b_y = c56_absx;
      }

      c56_k++;
    }
  }

  return c56_b_y;
}

static const mxArray *c56_g_sf_marshallOut(void *chartInstanceVoid, void
  *c56_inData)
{
  const mxArray *c56_mxArrayOutData = NULL;
  int32_T c56_u;
  const mxArray *c56_b_y = NULL;
  SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c56_mxArrayOutData = NULL;
  c56_u = *(int32_T *)c56_inData;
  c56_b_y = NULL;
  sf_mex_assign(&c56_b_y, sf_mex_create("y", &c56_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c56_mxArrayOutData, c56_b_y, false);
  return c56_mxArrayOutData;
}

static int32_T c56_e_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId)
{
  int32_T c56_b_y;
  int32_T c56_i93;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), &c56_i93, 1, 6, 0U, 0, 0U, 0);
  c56_b_y = c56_i93;
  sf_mex_destroy(&c56_u);
  return c56_b_y;
}

static void c56_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c56_mxArrayInData, const char_T *c56_varName, void *c56_outData)
{
  const mxArray *c56_b_sfEvent;
  const char_T *c56_identifier;
  emlrtMsgIdentifier c56_thisId;
  int32_T c56_b_y;
  SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c56_b_sfEvent = sf_mex_dup(c56_mxArrayInData);
  c56_identifier = c56_varName;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_b_y = c56_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c56_b_sfEvent),
    &c56_thisId);
  sf_mex_destroy(&c56_b_sfEvent);
  *(int32_T *)c56_outData = c56_b_y;
  sf_mex_destroy(&c56_mxArrayInData);
}

static const mxArray *c56_ControlState_bus_io(void *chartInstanceVoid, void
  *c56_pData)
{
  const mxArray *c56_mxVal = NULL;
  c56_ControlStateBus c56_tmp;
  SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c56_mxVal = NULL;
  c56_tmp.ControllerMode = *(real_T *)&((char_T *)(c56_ControlStateBus *)
    c56_pData)[0];
  c56_tmp.SupportState = *(real_T *)&((char_T *)(c56_ControlStateBus *)c56_pData)
    [8];
  c56_tmp.StanceLeg = *(real_T *)&((char_T *)(c56_ControlStateBus *)c56_pData)
    [16];
  c56_tmp.InDoubleSupport = *(real_T *)&((char_T *)(c56_ControlStateBus *)
    c56_pData)[24];
  c56_tmp.RollPhase = *(real_T *)&((char_T *)(c56_ControlStateBus *)c56_pData)
    [32];
  c56_tmp.StepCount = *(real_T *)&((char_T *)(c56_ControlStateBus *)c56_pData)
    [40];
  c56_tmp.Error = *(real_T *)&((char_T *)(c56_ControlStateBus *)c56_pData)[48];
  sf_mex_assign(&c56_mxVal, c56_d_sf_marshallOut(chartInstance, &c56_tmp), false);
  return c56_mxVal;
}

static const mxArray *c56_ControlParams_bus_io(void *chartInstanceVoid, void
  *c56_pData)
{
  const mxArray *c56_mxVal = NULL;
  c56_ControlParamsBus c56_tmp;
  int32_T c56_i94;
  int32_T c56_i95;
  int32_T c56_i96;
  int32_T c56_i97;
  int32_T c56_i98;
  int32_T c56_i99;
  int32_T c56_i100;
  int32_T c56_i101;
  int32_T c56_i102;
  int32_T c56_i103;
  int32_T c56_i104;
  int32_T c56_i105;
  int32_T c56_i106;
  int32_T c56_i107;
  int32_T c56_i108;
  int32_T c56_i109;
  int32_T c56_i110;
  int32_T c56_i111;
  int32_T c56_i112;
  int32_T c56_i113;
  int32_T c56_i114;
  int32_T c56_i115;
  int32_T c56_i116;
  int32_T c56_i117;
  int32_T c56_i118;
  int32_T c56_i119;
  int32_T c56_i120;
  int32_T c56_i121;
  int32_T c56_i122;
  int32_T c56_i123;
  int32_T c56_i124;
  int32_T c56_i125;
  int32_T c56_i126;
  int32_T c56_i127;
  int32_T c56_i128;
  int32_T c56_i129;
  int32_T c56_i130;
  int32_T c56_i131;
  int32_T c56_i132;
  int32_T c56_i133;
  int32_T c56_i134;
  int32_T c56_i135;
  int32_T c56_i136;
  int32_T c56_i137;
  int32_T c56_i138;
  int32_T c56_i139;
  int32_T c56_i140;
  SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c56_mxVal = NULL;
  c56_tmp.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [0];
  c56_tmp.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [8];
  c56_tmp.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [16];
  c56_tmp.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [24];
  c56_tmp.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [32];
  c56_tmp.Supervisory.ImpactThresholdKASpringRel = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [40];
  c56_tmp.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [48];
  c56_tmp.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [56];
  c56_tmp.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [64];
  c56_tmp.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [72];
  c56_tmp.Supervisory.TransitionThresholdTorsoVel = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [80];
  for (c56_i94 = 0; c56_i94 < 2; c56_i94++) {
    c56_tmp.Supervisory.KAInjection[c56_i94] = ((real_T *)&((char_T *)
      (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [0])[88])[c56_i94];
  }

  c56_tmp.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [104];
  c56_tmp.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [112];
  for (c56_i95 = 0; c56_i95 < 6; c56_i95++) {
    c56_tmp.Supervisory.VBLAParams[c56_i95] = ((real_T *)&((char_T *)
      (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [0])[120])[c56_i95];
  }

  for (c56_i96 = 0; c56_i96 < 13; c56_i96++) {
    c56_tmp.Supervisory.BalanceParams[c56_i96] = ((real_T *)&((char_T *)
      (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [0])[168])[c56_i96];
  }

  for (c56_i97 = 0; c56_i97 < 5; c56_i97++) {
    c56_tmp.Supervisory.GaitTweaks[c56_i97] = ((real_T *)&((char_T *)
      (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [0])[272])[c56_i97];
  }

  c56_tmp.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [312];
  c56_tmp.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [320];
  c56_tmp.Supervisory.RunMode = *(real_T *)&((char_T *)(c56_SupervisoryParamsBus
    *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])[328];
  c56_tmp.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [336];
  for (c56_i98 = 0; c56_i98 < 6; c56_i98++) {
    c56_tmp.Supervisory.ErrorZeroFactor[c56_i98] = ((real_T *)&((char_T *)
      (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [0])[344])[c56_i98];
  }

  for (c56_i99 = 0; c56_i99 < 6; c56_i99++) {
    c56_tmp.Supervisory.ErrorVelZeroFactor[c56_i99] = ((real_T *)&((char_T *)
      (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [0])[392])[c56_i99];
  }

  c56_tmp.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [440];
  c56_tmp.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [448];
  c56_tmp.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [456];
  c56_tmp.Supervisory.TPosing = *(real_T *)&((char_T *)(c56_SupervisoryParamsBus
    *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])[464];
  c56_tmp.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [472];
  c56_tmp.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [480];
  c56_tmp.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [488];
  c56_tmp.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [496];
  c56_tmp.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [504];
  c56_tmp.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [512];
  c56_tmp.Supervisory.VelocityControlTorsoGain = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [520];
  c56_tmp.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [528];
  c56_tmp.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [536];
  c56_tmp.Supervisory.Theta0 = *(real_T *)&((char_T *)(c56_SupervisoryParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[0])[544];
  c56_tmp.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [552];
  c56_tmp.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [560];
  c56_tmp.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [568];
  c56_tmp.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [576];
  c56_tmp.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [584];
  c56_tmp.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [592];
  c56_tmp.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [600];
  for (c56_i100 = 0; c56_i100 < 6; c56_i100++) {
    c56_tmp.Supervisory.K1MidStanceUpdate[c56_i100] = ((real_T *)&((char_T *)
      (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [0])[608])[c56_i100];
  }

  for (c56_i101 = 0; c56_i101 < 6; c56_i101++) {
    c56_tmp.Supervisory.K2MidStanceUpdate[c56_i101] = ((real_T *)&((char_T *)
      (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [0])[656])[c56_i101];
  }

  c56_tmp.Supervisory.EnableVelocityBasedUpdate = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [704];
  for (c56_i102 = 0; c56_i102 < 6; c56_i102++) {
    c56_tmp.Supervisory.VelocityBasedUpdateK1[c56_i102] = ((real_T *)&((char_T *)
      (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [0])[712])[c56_i102];
  }

  for (c56_i103 = 0; c56_i103 < 6; c56_i103++) {
    c56_tmp.Supervisory.VelocityBasedUpdateK2[c56_i103] = ((real_T *)&((char_T *)
      (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [0])[760])[c56_i103];
  }

  c56_tmp.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [808];
  c56_i104 = 0;
  for (c56_i105 = 0; c56_i105 < 2; c56_i105++) {
    for (c56_i106 = 0; c56_i106 < 6; c56_i106++) {
      c56_tmp.Supervisory.VelocityBasedUpdateLimits[c56_i106 + c56_i104] =
        ((real_T *)&((char_T *)(c56_SupervisoryParamsBus *)&((char_T *)
           (c56_ControlParamsBus *)c56_pData)[0])[816])[c56_i106 + c56_i104];
    }

    c56_i104 += 6;
  }

  c56_tmp.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [912];
  c56_tmp.Supervisory.dx_cmd = *(real_T *)&((char_T *)(c56_SupervisoryParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[0])[920];
  c56_tmp.Supervisory.ForBackward = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [928];
  c56_tmp.Supervisory.EnableFrictionID = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [936];
  c56_tmp.Supervisory.ResetFrictionPosing = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [944];
  c56_tmp.Supervisory.MoveLegIndex = *(real_T *)&((char_T *)
    (c56_SupervisoryParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[0])
    [952];
  c56_tmp.Supervisory.dy_cmd = *(real_T *)&((char_T *)(c56_SupervisoryParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[0])[960];
  c56_tmp.Discrete.TLastUpdate = *(real_T *)&((char_T *)(c56_DiscreteParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[968])[0];
  c56_tmp.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[968])
    [8];
  c56_tmp.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[968])
    [16];
  c56_tmp.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[968])
    [24];
  c56_tmp.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[968])
    [32];
  c56_tmp.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[968])
    [40];
  c56_tmp.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[968])
    [48];
  c56_tmp.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[968])
    [56];
  c56_tmp.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[968])
    [64];
  c56_tmp.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[968])
    [72];
  c56_tmp.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c56_DiscreteParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[968])
    [80];
  c56_i107 = 0;
  for (c56_i108 = 0; c56_i108 < 13; c56_i108++) {
    for (c56_i109 = 0; c56_i109 < 6; c56_i109++) {
      c56_tmp.Output.H0[c56_i109 + c56_i107] = ((real_T *)&((char_T *)
        (c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
        [1056])[0])[c56_i109 + c56_i107];
    }

    c56_i107 += 6;
  }

  c56_i110 = 0;
  for (c56_i111 = 0; c56_i111 < 6; c56_i111++) {
    for (c56_i112 = 0; c56_i112 < 6; c56_i112++) {
      c56_tmp.Output.HAlpha[c56_i112 + c56_i110] = ((real_T *)&((char_T *)
        (c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
        [1056])[624])[c56_i112 + c56_i110];
    }

    c56_i110 += 6;
  }

  for (c56_i113 = 0; c56_i113 < 2; c56_i113++) {
    c56_tmp.Output.ThetaLimits[c56_i113] = ((real_T *)&((char_T *)
      (c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[1056])
      [912])[c56_i113];
  }

  c56_tmp.Output.Theta.c0 = *(real_T *)&((char_T *)(c56_ThetaParamsBus *)
    &((char_T *)(c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)
    c56_pData)[1056])[928])[0];
  c56_tmp.Output.Theta.ct = *(real_T *)&((char_T *)(c56_ThetaParamsBus *)
    &((char_T *)(c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)
    c56_pData)[1056])[928])[8];
  for (c56_i114 = 0; c56_i114 < 13; c56_i114++) {
    c56_tmp.Output.Theta.cq[c56_i114] = ((real_T *)&((char_T *)
      (c56_ThetaParamsBus *)&((char_T *)(c56_OutputParamsBus *)&((char_T *)
      (c56_ControlParamsBus *)c56_pData)[1056])[928])[16])[c56_i114];
  }

  c56_tmp.Output.Theta.t0 = *(real_T *)&((char_T *)(c56_ThetaParamsBus *)
    &((char_T *)(c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)
    c56_pData)[1056])[928])[120];
  for (c56_i115 = 0; c56_i115 < 7; c56_i115++) {
    c56_tmp.Output.Theta.cz[c56_i115] = ((real_T *)&((char_T *)
      (c56_ThetaParamsBus *)&((char_T *)(c56_OutputParamsBus *)&((char_T *)
      (c56_ControlParamsBus *)c56_pData)[1056])[928])[128])[c56_i115];
  }

  c56_tmp.Output.SaturateS = *(real_T *)&((char_T *)(c56_OutputParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[1056])[1112];
  for (c56_i116 = 0; c56_i116 < 2; c56_i116++) {
    c56_tmp.Output.SLimits[c56_i116] = ((real_T *)&((char_T *)
      (c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[1056])
      [1120])[c56_i116];
  }

  c56_tmp.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[1056])
    [1136];
  c56_tmp.Output.UseCorrection = *(real_T *)&((char_T *)(c56_OutputParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[1056])[1144];
  c56_tmp.Output.SMaxCorrection = *(real_T *)&((char_T *)(c56_OutputParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[1056])[1152];
  c56_i117 = 0;
  for (c56_i118 = 0; c56_i118 < 5; c56_i118++) {
    for (c56_i119 = 0; c56_i119 < 6; c56_i119++) {
      c56_tmp.Output.HAlphaCorrection[c56_i119 + c56_i117] = ((real_T *)
        &((char_T *)(c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)
        c56_pData)[1056])[1160])[c56_i119 + c56_i117];
    }

    c56_i117 += 6;
  }

  c56_tmp.Output.Phi.c0 = *(real_T *)&((char_T *)(c56_PhiParamsBus *)&((char_T *)
                                        (c56_OutputParamsBus *)&((char_T *)
    (c56_ControlParamsBus *)c56_pData)[1056])[1400])[0];
  for (c56_i120 = 0; c56_i120 < 13; c56_i120++) {
    c56_tmp.Output.Phi.cq[c56_i120] = ((real_T *)&((char_T *)(c56_PhiParamsBus *)
      &((char_T *)(c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)
      c56_pData)[1056])[1400])[8])[c56_i120];
  }

  for (c56_i121 = 0; c56_i121 < 20; c56_i121++) {
    c56_tmp.Output.PhiAlpha[c56_i121] = ((real_T *)&((char_T *)
      (c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[1056])
      [1512])[c56_i121];
  }

  c56_tmp.Output.SaturateR = *(real_T *)&((char_T *)(c56_OutputParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[1056])[1672];
  for (c56_i122 = 0; c56_i122 < 2; c56_i122++) {
    c56_tmp.Output.RLimits[c56_i122] = ((real_T *)&((char_T *)
      (c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[1056])
      [1680])[c56_i122];
  }

  c56_i123 = 0;
  for (c56_i124 = 0; c56_i124 < 5; c56_i124++) {
    for (c56_i125 = 0; c56_i125 < 6; c56_i125++) {
      c56_tmp.Output.HBarAlpha[c56_i125 + c56_i123] = ((real_T *)&((char_T *)
        (c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
        [1056])[1696])[c56_i125 + c56_i123];
    }

    c56_i123 += 6;
  }

  c56_i126 = 0;
  for (c56_i127 = 0; c56_i127 < 2; c56_i127++) {
    for (c56_i128 = 0; c56_i128 < 6; c56_i128++) {
      c56_tmp.Output.HBarLimits[c56_i128 + c56_i126] = ((real_T *)&((char_T *)
        (c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
        [1056])[1936])[c56_i128 + c56_i126];
    }

    c56_i126 += 6;
  }

  c56_i129 = 0;
  for (c56_i130 = 0; c56_i130 < 6; c56_i130++) {
    for (c56_i131 = 0; c56_i131 < 6; c56_i131++) {
      c56_tmp.Output.HAlphaStar[c56_i131 + c56_i129] = ((real_T *)&((char_T *)
        (c56_OutputParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
        [1056])[2032])[c56_i131 + c56_i129];
    }

    c56_i129 += 6;
  }

  c56_tmp.Output.YawLimit = *(real_T *)&((char_T *)(c56_OutputParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[1056])[2320];
  c56_tmp.Output.test = *(real_T *)&((char_T *)(c56_OutputParamsBus *)&((char_T *)
                                      (c56_ControlParamsBus *)c56_pData)[1056])
    [2328];
  for (c56_i132 = 0; c56_i132 < 6; c56_i132++) {
    c56_tmp.Feedback.kp[c56_i132] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [3392])[0])[c56_i132];
  }

  for (c56_i133 = 0; c56_i133 < 6; c56_i133++) {
    c56_tmp.Feedback.kd[c56_i133] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [3392])[48])[c56_i133];
  }

  for (c56_i134 = 0; c56_i134 < 2; c56_i134++) {
    c56_tmp.Feedback.epsilon[c56_i134] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [3392])[96])[c56_i134];
  }

  for (c56_i135 = 0; c56_i135 < 2; c56_i135++) {
    c56_tmp.Feedback.kff_grav[c56_i135] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [3392])[112])[c56_i135];
  }

  c56_tmp.Feedback.delta_grav = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[128];
  for (c56_i136 = 0; c56_i136 < 2; c56_i136++) {
    c56_tmp.Feedback.kff_decoup[c56_i136] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [3392])[136])[c56_i136];
  }

  for (c56_i137 = 0; c56_i137 < 2; c56_i137++) {
    c56_tmp.Feedback.kd_torso[c56_i137] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [3392])[152])[c56_i137];
  }

  c56_tmp.Feedback.kp_2dof = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[168];
  c56_tmp.Feedback.kd_2dof = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[176];
  c56_tmp.Feedback.kpre_2dof = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[184];
  c56_tmp.Feedback.kp_lat = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[192];
  c56_tmp.Feedback.kd_lat = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[200];
  c56_tmp.Feedback.q3d_min_lat = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[208];
  c56_tmp.Feedback.q3d_max_lat = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[216];
  c56_tmp.Feedback.w_torso_lat = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[224];
  for (c56_i138 = 0; c56_i138 < 6; c56_i138++) {
    c56_tmp.Feedback.u_ff[c56_i138] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [3392])[232])[c56_i138];
  }

  c56_tmp.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])
    [280];
  c56_tmp.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])
    [288];
  c56_tmp.Feedback.Use2DOF = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[296];
  c56_tmp.Feedback.UseDSGravComp = *(real_T *)&((char_T *)(c56_FeedbackParamsBus
    *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[304];
  c56_tmp.Feedback.lat_bias = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[312];
  c56_tmp.Feedback.lat_bias2 = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[320];
  c56_tmp.Feedback.linkFeedback = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[328];
  c56_tmp.Feedback.RIO = *(real_T *)&((char_T *)(c56_FeedbackParamsBus *)
    &((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])[336];
  c56_tmp.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])
    [344];
  for (c56_i139 = 0; c56_i139 < 6; c56_i139++) {
    c56_tmp.Feedback.FeedforwardGain[c56_i139] = ((real_T *)&((char_T *)
      (c56_FeedbackParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [3392])[352])[c56_i139];
  }

  c56_tmp.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c56_FeedbackParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)[3392])
    [400];
  c56_tmp.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c56_SaturationParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
    [3800])[0];
  for (c56_i140 = 0; c56_i140 < 2; c56_i140++) {
    c56_tmp.Saturation.QPWeight[c56_i140] = ((real_T *)&((char_T *)
      (c56_SaturationParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
      [3800])[8])[c56_i140];
  }

  c56_tmp.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c56_SaturationParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
    [3800])[24];
  c56_tmp.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c56_SaturationParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
    [3800])[32];
  c56_tmp.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c56_SaturationParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
    [3800])[40];
  c56_tmp.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c56_SaturationParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
    [3800])[48];
  c56_tmp.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c56_SaturationParamsBus *)&((char_T *)(c56_ControlParamsBus *)c56_pData)
    [3800])[56];
  sf_mex_assign(&c56_mxVal, c56_c_sf_marshallOut(chartInstance, &c56_tmp), false);
  return c56_mxVal;
}

static uint8_T c56_f_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_b_is_active_c56_Walking01_DDA3D, const
  char_T *c56_identifier)
{
  uint8_T c56_b_y;
  emlrtMsgIdentifier c56_thisId;
  c56_thisId.fIdentifier = c56_identifier;
  c56_thisId.fParent = NULL;
  c56_b_y = c56_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c56_b_is_active_c56_Walking01_DDA3D), &c56_thisId);
  sf_mex_destroy(&c56_b_is_active_c56_Walking01_DDA3D);
  return c56_b_y;
}

static uint8_T c56_g_emlrt_marshallIn(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c56_u, const emlrtMsgIdentifier *c56_parentId)
{
  uint8_T c56_b_y;
  uint8_T c56_u0;
  (void)chartInstance;
  sf_mex_import(c56_parentId, sf_mex_dup(c56_u), &c56_u0, 1, 3, 0U, 0, 0U, 0);
  c56_b_y = c56_u0;
  sf_mex_destroy(&c56_u);
  return c56_b_y;
}

static void init_dsm_address_info(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc56_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c56_TorqueSaturationLimits = (real_T (*)[2])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c56_y = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c56_dy = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c56_s = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    3);
  chartInstance->c56_Error = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c56_ControlState = (c56_ControlStateBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 4);
  chartInstance->c56_ControlParams = (c56_ControlParamsBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 5);
  chartInstance->c56_ErrorCount = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c56_ErrorCountIn = (real_T *)ssGetInputPortSignal_wrapper
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

void sf_c56_Walking01_DDA3D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(789174020U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4125196079U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2244467016U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2378237715U);
}

mxArray* sf_c56_Walking01_DDA3D_get_post_codegen_info(void);
mxArray *sf_c56_Walking01_DDA3D_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c56_Walking01_DDA3D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c56_Walking01_DDA3D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c56_Walking01_DDA3D_jit_fallback_info(void)
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

mxArray *sf_c56_Walking01_DDA3D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c56_Walking01_DDA3D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c56_Walking01_DDA3D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"Error\",},{M[1],M[13],T\"ErrorCount\",},{M[8],M[0],T\"is_active_c56_Walking01_DDA3D\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c56_Walking01_DDA3D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_DDA3DMachineNumber_,
           56,
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
        init_script_number_translation(_Walking01_DDA3DMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Walking01_DDA3DMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Walking01_DDA3DMachineNumber_,
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
            1.0,0,0,(MexFcnForType)c56_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c56_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c56_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_b_sf_marshallOut,(MexInFcnForType)
          c56_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_ControlState_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_ControlParams_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)c56_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c56_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c56_TorqueSaturationLimits);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c56_y);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c56_dy);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c56_s);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c56_Error);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c56_ControlState);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c56_ControlParams);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c56_ErrorCount);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c56_ErrorCountIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Walking01_DDA3DMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "3gryq4VJkSqKVfrcJZbzpG";
}

static void sf_opaque_initialize_c56_Walking01_DDA3D(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc56_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c56_Walking01_DDA3D((SFc56_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
  initialize_c56_Walking01_DDA3D((SFc56_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c56_Walking01_DDA3D(void *chartInstanceVar)
{
  enable_c56_Walking01_DDA3D((SFc56_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c56_Walking01_DDA3D(void *chartInstanceVar)
{
  disable_c56_Walking01_DDA3D((SFc56_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c56_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_gateway_c56_Walking01_DDA3D((SFc56_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c56_Walking01_DDA3D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c56_Walking01_DDA3D((SFc56_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c56_Walking01_DDA3D(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c56_Walking01_DDA3D((SFc56_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c56_Walking01_DDA3D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc56_Walking01_DDA3DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_DDA3D_optimization_info();
    }

    finalize_c56_Walking01_DDA3D((SFc56_Walking01_DDA3DInstanceStruct*)
      chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc56_Walking01_DDA3D((SFc56_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c56_Walking01_DDA3D(SimStruct *S)
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
    initialize_params_c56_Walking01_DDA3D((SFc56_Walking01_DDA3DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c56_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      56);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,56,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,56,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,56);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,56,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,56,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,56);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3350623131U));
  ssSetChecksum1(S,(1337190740U));
  ssSetChecksum2(S,(1718092626U));
  ssSetChecksum3(S,(235483657U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c56_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c56_Walking01_DDA3D(SimStruct *S)
{
  SFc56_Walking01_DDA3DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc56_Walking01_DDA3DInstanceStruct *)utMalloc(sizeof
    (SFc56_Walking01_DDA3DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc56_Walking01_DDA3DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c56_Walking01_DDA3D;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c56_Walking01_DDA3D;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c56_Walking01_DDA3D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c56_Walking01_DDA3D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c56_Walking01_DDA3D;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c56_Walking01_DDA3D;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c56_Walking01_DDA3D;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c56_Walking01_DDA3D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c56_Walking01_DDA3D;
  chartInstance->chartInfo.mdlStart = mdlStart_c56_Walking01_DDA3D;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c56_Walking01_DDA3D;
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

void c56_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c56_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c56_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c56_Walking01_DDA3D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c56_Walking01_DDA3D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
