/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DDA2D_OSU3Dv2_sfun.h"
#include "c65_DDA2D_OSU3Dv2.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "DDA2D_OSU3Dv2_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c65_debug_family_names[11] = { "nargin", "nargout",
  "TorqueSaturationLimits", "y", "dy", "s", "ControlState", "ControlParams",
  "ErrorCountIn", "Error", "ErrorCount" };

/* Function Declarations */
static void initialize_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initialize_params_c65_DDA2D_OSU3Dv2
  (SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void enable_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void disable_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c65_update_debugger_state_c65_DDA2D_OSU3Dv2
  (SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c65_DDA2D_OSU3Dv2
  (SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void set_sim_state_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_st);
static void finalize_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void sf_gateway_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void mdl_start_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c65_chartstep_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initSimStructsc65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c65_machineNumber, uint32_T
  c65_chartNumber, uint32_T c65_instanceNumber);
static const mxArray *c65_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData);
static real_T c65_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_b_ErrorCount, const char_T *c65_identifier);
static real_T c65_b_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId);
static void c65_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData);
static const mxArray *c65_b_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData);
static boolean_T c65_c_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_b_Error, const char_T *c65_identifier);
static boolean_T c65_d_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId);
static void c65_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData);
static const mxArray *c65_c_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData);
static const mxArray *c65_d_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData);
static const mxArray *c65_e_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData);
static const mxArray *c65_f_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData);
static void c65_info_helper(const mxArray **c65_info);
static const mxArray *c65_emlrt_marshallOut(const char * c65_u);
static const mxArray *c65_b_emlrt_marshallOut(const uint32_T c65_u);
static real_T c65_norm(SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c65_x[6]);
static const mxArray *c65_g_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData);
static int32_T c65_e_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId);
static void c65_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData);
static const mxArray *c65_ControlState_bus_io(void *chartInstanceVoid, void
  *c65_pData);
static const mxArray *c65_ControlParams_bus_io(void *chartInstanceVoid, void
  *c65_pData);
static uint8_T c65_f_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_b_is_active_c65_DDA2D_OSU3Dv2, const char_T
  *c65_identifier);
static uint8_T c65_g_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId);
static void init_dsm_address_info(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c65_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c65_is_active_c65_DDA2D_OSU3Dv2 = 0U;
}

static void initialize_params_c65_DDA2D_OSU3Dv2
  (SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c65_update_debugger_state_c65_DDA2D_OSU3Dv2
  (SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c65_DDA2D_OSU3Dv2
  (SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  const mxArray *c65_st;
  const mxArray *c65_b_y = NULL;
  boolean_T c65_hoistedGlobal;
  boolean_T c65_u;
  const mxArray *c65_c_y = NULL;
  real_T c65_b_hoistedGlobal;
  real_T c65_b_u;
  const mxArray *c65_d_y = NULL;
  uint8_T c65_c_hoistedGlobal;
  uint8_T c65_c_u;
  const mxArray *c65_e_y = NULL;
  c65_st = NULL;
  c65_st = NULL;
  c65_b_y = NULL;
  sf_mex_assign(&c65_b_y, sf_mex_createcellmatrix(3, 1), false);
  c65_hoistedGlobal = *chartInstance->c65_Error;
  c65_u = c65_hoistedGlobal;
  c65_c_y = NULL;
  sf_mex_assign(&c65_c_y, sf_mex_create("y", &c65_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c65_b_y, 0, c65_c_y);
  c65_b_hoistedGlobal = *chartInstance->c65_ErrorCount;
  c65_b_u = c65_b_hoistedGlobal;
  c65_d_y = NULL;
  sf_mex_assign(&c65_d_y, sf_mex_create("y", &c65_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c65_b_y, 1, c65_d_y);
  c65_c_hoistedGlobal = chartInstance->c65_is_active_c65_DDA2D_OSU3Dv2;
  c65_c_u = c65_c_hoistedGlobal;
  c65_e_y = NULL;
  sf_mex_assign(&c65_e_y, sf_mex_create("y", &c65_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c65_b_y, 2, c65_e_y);
  sf_mex_assign(&c65_st, c65_b_y, false);
  return c65_st;
}

static void set_sim_state_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_st)
{
  const mxArray *c65_u;
  chartInstance->c65_doneDoubleBufferReInit = true;
  c65_u = sf_mex_dup(c65_st);
  *chartInstance->c65_Error = c65_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c65_u, 0)), "Error");
  *chartInstance->c65_ErrorCount = c65_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c65_u, 1)), "ErrorCount");
  chartInstance->c65_is_active_c65_DDA2D_OSU3Dv2 = c65_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c65_u, 2)),
     "is_active_c65_DDA2D_OSU3Dv2");
  sf_mex_destroy(&c65_u);
  c65_update_debugger_state_c65_DDA2D_OSU3Dv2(chartInstance);
  sf_mex_destroy(&c65_st);
}

static void finalize_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  int32_T c65_i0;
  int32_T c65_i1;
  int32_T c65_i2;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c65_sfEvent);
  for (c65_i0 = 0; c65_i0 < 2; c65_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c65_TorqueSaturationLimits)[c65_i0],
                          0U);
  }

  for (c65_i1 = 0; c65_i1 < 6; c65_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c65_y)[c65_i1], 1U);
  }

  for (c65_i2 = 0; c65_i2 < 6; c65_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c65_dy)[c65_i2], 2U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c65_s, 3U);
  chartInstance->c65_sfEvent = CALL_EVENT;
  c65_chartstep_c65_DDA2D_OSU3Dv2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DDA2D_OSU3Dv2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c65_Error, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c65_ErrorCount, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c65_ErrorCountIn, 8U);
}

static void mdl_start_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c65_chartstep_c65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  real_T c65_hoistedGlobal;
  real_T c65_b_hoistedGlobal;
  int32_T c65_i3;
  real_T c65_b_TorqueSaturationLimits[2];
  int32_T c65_i4;
  real_T c65_b_y[6];
  int32_T c65_i5;
  real_T c65_b_dy[6];
  real_T c65_b_s;
  c65_ControlStateBus c65_b_ControlState;
  c65_ControlParamsBus c65_b_ControlParams;
  int32_T c65_i6;
  int32_T c65_i7;
  int32_T c65_i8;
  int32_T c65_i9;
  int32_T c65_i10;
  int32_T c65_i11;
  int32_T c65_i12;
  int32_T c65_i13;
  int32_T c65_i14;
  int32_T c65_i15;
  int32_T c65_i16;
  int32_T c65_i17;
  int32_T c65_i18;
  int32_T c65_i19;
  int32_T c65_i20;
  int32_T c65_i21;
  int32_T c65_i22;
  int32_T c65_i23;
  int32_T c65_i24;
  int32_T c65_i25;
  int32_T c65_i26;
  int32_T c65_i27;
  int32_T c65_i28;
  int32_T c65_i29;
  int32_T c65_i30;
  int32_T c65_i31;
  int32_T c65_i32;
  int32_T c65_i33;
  int32_T c65_i34;
  int32_T c65_i35;
  int32_T c65_i36;
  int32_T c65_i37;
  int32_T c65_i38;
  int32_T c65_i39;
  int32_T c65_i40;
  int32_T c65_i41;
  int32_T c65_i42;
  int32_T c65_i43;
  int32_T c65_i44;
  int32_T c65_i45;
  int32_T c65_i46;
  int32_T c65_i47;
  int32_T c65_i48;
  int32_T c65_i49;
  int32_T c65_i50;
  int32_T c65_i51;
  int32_T c65_i52;
  int32_T c65_i53;
  real_T c65_b_ErrorCountIn;
  uint32_T c65_debug_family_var_map[11];
  real_T c65_nargin = 7.0;
  real_T c65_nargout = 2.0;
  boolean_T c65_b_Error;
  real_T c65_b_ErrorCount;
  int32_T c65_i54;
  boolean_T c65_x[2];
  boolean_T c65_c_y;
  int32_T c65_k;
  real_T c65_b_k;
  int32_T c65_i55;
  real_T c65_d_y[6];
  real_T c65_d0;
  real_T c65_A;
  real_T c65_b_x;
  real_T c65_c_x;
  real_T c65_d_x;
  real_T c65_d1;
  int32_T c65_i56;
  real_T c65_c_dy[6];
  real_T c65_d2;
  real_T c65_b_A;
  real_T c65_e_x;
  real_T c65_f_x;
  real_T c65_g_x;
  real_T c65_d3;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T exitg1;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c65_sfEvent);
  c65_hoistedGlobal = *chartInstance->c65_s;
  c65_b_hoistedGlobal = *chartInstance->c65_ErrorCountIn;
  for (c65_i3 = 0; c65_i3 < 2; c65_i3++) {
    c65_b_TorqueSaturationLimits[c65_i3] =
      (*chartInstance->c65_TorqueSaturationLimits)[c65_i3];
  }

  for (c65_i4 = 0; c65_i4 < 6; c65_i4++) {
    c65_b_y[c65_i4] = (*chartInstance->c65_y)[c65_i4];
  }

  for (c65_i5 = 0; c65_i5 < 6; c65_i5++) {
    c65_b_dy[c65_i5] = (*chartInstance->c65_dy)[c65_i5];
  }

  c65_b_s = c65_hoistedGlobal;
  c65_b_ControlState.ControllerMode = *(real_T *)&((char_T *)
    chartInstance->c65_ControlState)[0];
  c65_b_ControlState.SupportState = *(real_T *)&((char_T *)
    chartInstance->c65_ControlState)[8];
  c65_b_ControlState.StanceLeg = *(real_T *)&((char_T *)
    chartInstance->c65_ControlState)[16];
  c65_b_ControlState.InDoubleSupport = *(real_T *)&((char_T *)
    chartInstance->c65_ControlState)[24];
  c65_b_ControlState.RollPhase = *(real_T *)&((char_T *)
    chartInstance->c65_ControlState)[32];
  c65_b_ControlState.StepCount = *(real_T *)&((char_T *)
    chartInstance->c65_ControlState)[40];
  c65_b_ControlState.Error = *(real_T *)&((char_T *)
    chartInstance->c65_ControlState)[48];
  c65_b_ControlParams.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [0];
  c65_b_ControlParams.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [8];
  c65_b_ControlParams.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [16];
  c65_b_ControlParams.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [24];
  c65_b_ControlParams.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)
    &((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c65_ControlParams)[0])[32];
  c65_b_ControlParams.Supervisory.ImpactThresholdKASpringRel = *(real_T *)
    &((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c65_ControlParams)[0])[40];
  c65_b_ControlParams.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [48];
  c65_b_ControlParams.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [56];
  c65_b_ControlParams.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [64];
  c65_b_ControlParams.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [72];
  c65_b_ControlParams.Supervisory.TransitionThresholdTorsoVel = *(real_T *)
    &((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c65_ControlParams)[0])[80];
  for (c65_i6 = 0; c65_i6 < 2; c65_i6++) {
    c65_b_ControlParams.Supervisory.KAInjection[c65_i6] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [0])[88])[c65_i6];
  }

  c65_b_ControlParams.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T
    *)(c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
    [0])[104];
  c65_b_ControlParams.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [112];
  for (c65_i7 = 0; c65_i7 < 6; c65_i7++) {
    c65_b_ControlParams.Supervisory.VBLAParams[c65_i7] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [0])[120])[c65_i7];
  }

  for (c65_i8 = 0; c65_i8 < 13; c65_i8++) {
    c65_b_ControlParams.Supervisory.BalanceParams[c65_i8] = ((real_T *)&((char_T
      *)(c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [0])[168])[c65_i8];
  }

  for (c65_i9 = 0; c65_i9 < 5; c65_i9++) {
    c65_b_ControlParams.Supervisory.GaitTweaks[c65_i9] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [0])[272])[c65_i9];
  }

  c65_b_ControlParams.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [312];
  c65_b_ControlParams.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [320];
  c65_b_ControlParams.Supervisory.RunMode = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [328];
  c65_b_ControlParams.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [336];
  for (c65_i10 = 0; c65_i10 < 6; c65_i10++) {
    c65_b_ControlParams.Supervisory.ErrorZeroFactor[c65_i10] = ((real_T *)
      &((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c65_ControlParams)[0])[344])[c65_i10];
  }

  for (c65_i11 = 0; c65_i11 < 6; c65_i11++) {
    c65_b_ControlParams.Supervisory.ErrorVelZeroFactor[c65_i11] = ((real_T *)
      &((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c65_ControlParams)[0])[392])[c65_i11];
  }

  c65_b_ControlParams.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [440];
  c65_b_ControlParams.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [448];
  c65_b_ControlParams.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [456];
  c65_b_ControlParams.Supervisory.TPosing = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [464];
  c65_b_ControlParams.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [472];
  c65_b_ControlParams.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [480];
  c65_b_ControlParams.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [488];
  c65_b_ControlParams.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [496];
  c65_b_ControlParams.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T
    *)(c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
    [0])[504];
  c65_b_ControlParams.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T
    *)(c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
    [0])[512];
  c65_b_ControlParams.Supervisory.VelocityControlTorsoGain = *(real_T *)
    &((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c65_ControlParams)[0])[520];
  c65_b_ControlParams.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [528];
  c65_b_ControlParams.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [536];
  c65_b_ControlParams.Supervisory.Theta0 = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [544];
  c65_b_ControlParams.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [552];
  c65_b_ControlParams.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [560];
  c65_b_ControlParams.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T
    *)(c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
    [0])[568];
  c65_b_ControlParams.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [576];
  c65_b_ControlParams.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [584];
  c65_b_ControlParams.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [592];
  c65_b_ControlParams.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [600];
  for (c65_i12 = 0; c65_i12 < 6; c65_i12++) {
    c65_b_ControlParams.Supervisory.K1MidStanceUpdate[c65_i12] = ((real_T *)
      &((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c65_ControlParams)[0])[608])[c65_i12];
  }

  for (c65_i13 = 0; c65_i13 < 6; c65_i13++) {
    c65_b_ControlParams.Supervisory.K2MidStanceUpdate[c65_i13] = ((real_T *)
      &((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c65_ControlParams)[0])[656])[c65_i13];
  }

  c65_b_ControlParams.Supervisory.EnableVelocityBasedUpdate = *(real_T *)
    &((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c65_ControlParams)[0])[704];
  for (c65_i14 = 0; c65_i14 < 6; c65_i14++) {
    c65_b_ControlParams.Supervisory.VelocityBasedUpdateK1[c65_i14] = ((real_T *)
      &((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c65_ControlParams)[0])[712])[c65_i14];
  }

  for (c65_i15 = 0; c65_i15 < 6; c65_i15++) {
    c65_b_ControlParams.Supervisory.VelocityBasedUpdateK2[c65_i15] = ((real_T *)
      &((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c65_ControlParams)[0])[760])[c65_i15];
  }

  c65_b_ControlParams.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)
    &((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c65_ControlParams)[0])[808];
  c65_i16 = 0;
  for (c65_i17 = 0; c65_i17 < 2; c65_i17++) {
    for (c65_i18 = 0; c65_i18 < 6; c65_i18++) {
      c65_b_ControlParams.Supervisory.VelocityBasedUpdateLimits[c65_i18 +
        c65_i16] = ((real_T *)&((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
        chartInstance->c65_ControlParams)[0])[816])[c65_i18 + c65_i16];
    }

    c65_i16 += 6;
  }

  c65_b_ControlParams.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [912];
  c65_b_ControlParams.Supervisory.dx_cmd = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [920];
  c65_b_ControlParams.Supervisory.ForBackward = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [928];
  c65_b_ControlParams.Supervisory.EnableFrictionID = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [936];
  c65_b_ControlParams.Supervisory.ResetFrictionPosing = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [944];
  c65_b_ControlParams.Supervisory.MoveLegIndex = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [952];
  c65_b_ControlParams.Supervisory.dy_cmd = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [960];
  c65_b_ControlParams.Supervisory.TauDelay = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [968];
  c65_b_ControlParams.Supervisory.TrackFrequency = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [976];
  c65_b_ControlParams.Supervisory.EnablePDControl = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [984];
  c65_b_ControlParams.Supervisory.TorqueAmp = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[0])
    [992];
  for (c65_i19 = 0; c65_i19 < 6; c65_i19++) {
    c65_b_ControlParams.Supervisory.hdPosing[c65_i19] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [0])[1000])[c65_i19];
  }

  c65_b_ControlParams.Discrete.TLastUpdate = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1048])
    [0];
  c65_b_ControlParams.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1048])
    [8];
  c65_b_ControlParams.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1048])
    [16];
  c65_b_ControlParams.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1048])
    [24];
  c65_b_ControlParams.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T
    *)(c65_DiscreteParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
    [1048])[32];
  c65_b_ControlParams.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1048])
    [40];
  c65_b_ControlParams.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1048])
    [48];
  c65_b_ControlParams.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1048])
    [56];
  c65_b_ControlParams.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1048])
    [64];
  c65_b_ControlParams.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1048])
    [72];
  c65_b_ControlParams.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1048])
    [80];
  c65_i20 = 0;
  for (c65_i21 = 0; c65_i21 < 13; c65_i21++) {
    for (c65_i22 = 0; c65_i22 < 6; c65_i22++) {
      c65_b_ControlParams.Output.H0[c65_i22 + c65_i20] = ((real_T *)&((char_T *)
        (c65_OutputParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
        [1136])[0])[c65_i22 + c65_i20];
    }

    c65_i20 += 6;
  }

  c65_i23 = 0;
  for (c65_i24 = 0; c65_i24 < 6; c65_i24++) {
    for (c65_i25 = 0; c65_i25 < 6; c65_i25++) {
      c65_b_ControlParams.Output.HAlpha[c65_i25 + c65_i23] = ((real_T *)
        &((char_T *)(c65_OutputParamsBus *)&((char_T *)
        chartInstance->c65_ControlParams)[1136])[624])[c65_i25 + c65_i23];
    }

    c65_i23 += 6;
  }

  for (c65_i26 = 0; c65_i26 < 2; c65_i26++) {
    c65_b_ControlParams.Output.ThetaLimits[c65_i26] = ((real_T *)&((char_T *)
      (c65_OutputParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1136])
      [912])[c65_i26];
  }

  c65_b_ControlParams.Output.Theta.c0 = *(real_T *)&((char_T *)
    (c65_ThetaParamsBus *)&((char_T *)(c65_OutputParamsBus *)&((char_T *)
    chartInstance->c65_ControlParams)[1136])[928])[0];
  c65_b_ControlParams.Output.Theta.ct = *(real_T *)&((char_T *)
    (c65_ThetaParamsBus *)&((char_T *)(c65_OutputParamsBus *)&((char_T *)
    chartInstance->c65_ControlParams)[1136])[928])[8];
  for (c65_i27 = 0; c65_i27 < 13; c65_i27++) {
    c65_b_ControlParams.Output.Theta.cq[c65_i27] = ((real_T *)&((char_T *)
      (c65_ThetaParamsBus *)&((char_T *)(c65_OutputParamsBus *)&((char_T *)
      chartInstance->c65_ControlParams)[1136])[928])[16])[c65_i27];
  }

  c65_b_ControlParams.Output.Theta.t0 = *(real_T *)&((char_T *)
    (c65_ThetaParamsBus *)&((char_T *)(c65_OutputParamsBus *)&((char_T *)
    chartInstance->c65_ControlParams)[1136])[928])[120];
  for (c65_i28 = 0; c65_i28 < 7; c65_i28++) {
    c65_b_ControlParams.Output.Theta.cz[c65_i28] = ((real_T *)&((char_T *)
      (c65_ThetaParamsBus *)&((char_T *)(c65_OutputParamsBus *)&((char_T *)
      chartInstance->c65_ControlParams)[1136])[928])[128])[c65_i28];
  }

  c65_b_ControlParams.Output.SaturateS = *(real_T *)&((char_T *)
    (c65_OutputParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1136])
    [1112];
  for (c65_i29 = 0; c65_i29 < 2; c65_i29++) {
    c65_b_ControlParams.Output.SLimits[c65_i29] = ((real_T *)&((char_T *)
      (c65_OutputParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1136])
      [1120])[c65_i29];
  }

  c65_b_ControlParams.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c65_OutputParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1136])
    [1136];
  c65_b_ControlParams.Output.UseCorrection = *(real_T *)&((char_T *)
    (c65_OutputParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1136])
    [1144];
  c65_b_ControlParams.Output.SMaxCorrection = *(real_T *)&((char_T *)
    (c65_OutputParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1136])
    [1152];
  c65_i30 = 0;
  for (c65_i31 = 0; c65_i31 < 5; c65_i31++) {
    for (c65_i32 = 0; c65_i32 < 6; c65_i32++) {
      c65_b_ControlParams.Output.HAlphaCorrection[c65_i32 + c65_i30] = ((real_T *)
        &((char_T *)(c65_OutputParamsBus *)&((char_T *)
        chartInstance->c65_ControlParams)[1136])[1160])[c65_i32 + c65_i30];
    }

    c65_i30 += 6;
  }

  c65_b_ControlParams.Output.Phi.c0 = *(real_T *)&((char_T *)(c65_PhiParamsBus *)
    &((char_T *)(c65_OutputParamsBus *)&((char_T *)
    chartInstance->c65_ControlParams)[1136])[1400])[0];
  for (c65_i33 = 0; c65_i33 < 13; c65_i33++) {
    c65_b_ControlParams.Output.Phi.cq[c65_i33] = ((real_T *)&((char_T *)
      (c65_PhiParamsBus *)&((char_T *)(c65_OutputParamsBus *)&((char_T *)
      chartInstance->c65_ControlParams)[1136])[1400])[8])[c65_i33];
  }

  for (c65_i34 = 0; c65_i34 < 20; c65_i34++) {
    c65_b_ControlParams.Output.PhiAlpha[c65_i34] = ((real_T *)&((char_T *)
      (c65_OutputParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1136])
      [1512])[c65_i34];
  }

  c65_b_ControlParams.Output.SaturateR = *(real_T *)&((char_T *)
    (c65_OutputParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1136])
    [1672];
  for (c65_i35 = 0; c65_i35 < 2; c65_i35++) {
    c65_b_ControlParams.Output.RLimits[c65_i35] = ((real_T *)&((char_T *)
      (c65_OutputParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1136])
      [1680])[c65_i35];
  }

  c65_i36 = 0;
  for (c65_i37 = 0; c65_i37 < 5; c65_i37++) {
    for (c65_i38 = 0; c65_i38 < 6; c65_i38++) {
      c65_b_ControlParams.Output.HBarAlpha[c65_i38 + c65_i36] = ((real_T *)
        &((char_T *)(c65_OutputParamsBus *)&((char_T *)
        chartInstance->c65_ControlParams)[1136])[1696])[c65_i38 + c65_i36];
    }

    c65_i36 += 6;
  }

  c65_i39 = 0;
  for (c65_i40 = 0; c65_i40 < 2; c65_i40++) {
    for (c65_i41 = 0; c65_i41 < 6; c65_i41++) {
      c65_b_ControlParams.Output.HBarLimits[c65_i41 + c65_i39] = ((real_T *)
        &((char_T *)(c65_OutputParamsBus *)&((char_T *)
        chartInstance->c65_ControlParams)[1136])[1936])[c65_i41 + c65_i39];
    }

    c65_i39 += 6;
  }

  c65_i42 = 0;
  for (c65_i43 = 0; c65_i43 < 6; c65_i43++) {
    for (c65_i44 = 0; c65_i44 < 6; c65_i44++) {
      c65_b_ControlParams.Output.HAlphaStar[c65_i44 + c65_i42] = ((real_T *)
        &((char_T *)(c65_OutputParamsBus *)&((char_T *)
        chartInstance->c65_ControlParams)[1136])[2032])[c65_i44 + c65_i42];
    }

    c65_i42 += 6;
  }

  c65_b_ControlParams.Output.YawLimit = *(real_T *)&((char_T *)
    (c65_OutputParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[1136])
    [2320];
  c65_b_ControlParams.Output.test = *(real_T *)&((char_T *)(c65_OutputParamsBus *)
    &((char_T *)chartInstance->c65_ControlParams)[1136])[2328];
  for (c65_i45 = 0; c65_i45 < 6; c65_i45++) {
    c65_b_ControlParams.Feedback.kp[c65_i45] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [3472])[0])[c65_i45];
  }

  for (c65_i46 = 0; c65_i46 < 6; c65_i46++) {
    c65_b_ControlParams.Feedback.kd[c65_i46] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [3472])[48])[c65_i46];
  }

  for (c65_i47 = 0; c65_i47 < 2; c65_i47++) {
    c65_b_ControlParams.Feedback.epsilon[c65_i47] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [3472])[96])[c65_i47];
  }

  for (c65_i48 = 0; c65_i48 < 2; c65_i48++) {
    c65_b_ControlParams.Feedback.kff_grav[c65_i48] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [3472])[112])[c65_i48];
  }

  c65_b_ControlParams.Feedback.delta_grav = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [128];
  for (c65_i49 = 0; c65_i49 < 2; c65_i49++) {
    c65_b_ControlParams.Feedback.kff_decoup[c65_i49] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [3472])[136])[c65_i49];
  }

  for (c65_i50 = 0; c65_i50 < 2; c65_i50++) {
    c65_b_ControlParams.Feedback.kd_torso[c65_i50] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [3472])[152])[c65_i50];
  }

  c65_b_ControlParams.Feedback.kp_2dof = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [168];
  c65_b_ControlParams.Feedback.kd_2dof = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [176];
  c65_b_ControlParams.Feedback.kpre_2dof = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [184];
  c65_b_ControlParams.Feedback.kp_lat = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [192];
  c65_b_ControlParams.Feedback.kd_lat = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [200];
  c65_b_ControlParams.Feedback.q3d_min_lat = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [208];
  c65_b_ControlParams.Feedback.q3d_max_lat = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [216];
  c65_b_ControlParams.Feedback.w_torso_lat = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [224];
  for (c65_i51 = 0; c65_i51 < 6; c65_i51++) {
    c65_b_ControlParams.Feedback.u_ff[c65_i51] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [3472])[232])[c65_i51];
  }

  c65_b_ControlParams.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [280];
  c65_b_ControlParams.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [288];
  c65_b_ControlParams.Feedback.Use2DOF = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [296];
  c65_b_ControlParams.Feedback.UseDSGravComp = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [304];
  c65_b_ControlParams.Feedback.lat_bias = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [312];
  c65_b_ControlParams.Feedback.lat_bias2 = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [320];
  c65_b_ControlParams.Feedback.linkFeedback = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [328];
  c65_b_ControlParams.Feedback.RIO = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [336];
  c65_b_ControlParams.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [344];
  for (c65_i52 = 0; c65_i52 < 6; c65_i52++) {
    c65_b_ControlParams.Feedback.FeedforwardGain[c65_i52] = ((real_T *)&((char_T
      *)(c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [3472])[352])[c65_i52];
  }

  c65_b_ControlParams.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)chartInstance->c65_ControlParams)[3472])
    [400];
  c65_b_ControlParams.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c65_SaturationParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
    [3880])[0];
  for (c65_i53 = 0; c65_i53 < 2; c65_i53++) {
    c65_b_ControlParams.Saturation.QPWeight[c65_i53] = ((real_T *)&((char_T *)
      (c65_SaturationParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
      [3880])[8])[c65_i53];
  }

  c65_b_ControlParams.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c65_SaturationParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
    [3880])[24];
  c65_b_ControlParams.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c65_SaturationParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
    [3880])[32];
  c65_b_ControlParams.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c65_SaturationParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
    [3880])[40];
  c65_b_ControlParams.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c65_SaturationParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
    [3880])[48];
  c65_b_ControlParams.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c65_SaturationParamsBus *)&((char_T *)chartInstance->c65_ControlParams)
    [3880])[56];
  c65_b_ErrorCountIn = c65_b_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c65_debug_family_names,
    c65_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c65_nargin, 0U, c65_sf_marshallOut,
    c65_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c65_nargout, 1U, c65_sf_marshallOut,
    c65_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c65_b_TorqueSaturationLimits, 2U,
    c65_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c65_b_y, 3U, c65_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c65_b_dy, 4U, c65_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_s, 5U, c65_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_ControlState, 6U, c65_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_ControlParams, 7U, c65_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c65_b_ErrorCountIn, 8U, c65_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c65_b_Error, 9U, c65_b_sf_marshallOut,
    c65_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c65_b_ErrorCount, 10U,
    c65_sf_marshallOut, c65_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 4);
  c65_b_ErrorCount = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 6);
  for (c65_i54 = 0; c65_i54 < 2; c65_i54++) {
    c65_x[c65_i54] = (c65_b_TorqueSaturationLimits[c65_i54] > 1.0);
  }

  c65_c_y = true;
  c65_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c65_k < 2)) {
    c65_b_k = 1.0 + (real_T)c65_k;
    if ((real_T)c65_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
         _SFD_INTEGER_CHECK("", c65_b_k), 1, 2, 1, 0) - 1] == 0.0) {
      c65_c_y = false;
      exitg1 = true;
    } else {
      c65_k++;
    }
  }

  guard1 = false;
  guard2 = false;
  if (CV_EML_COND(0, 1, 0, c65_c_y)) {
    for (c65_i55 = 0; c65_i55 < 6; c65_i55++) {
      c65_d_y[c65_i55] = c65_b_y[c65_i55];
    }

    c65_d0 = c65_norm(chartInstance, c65_d_y);
    c65_A = c65_b_ControlParams.Supervisory.MaxError * 3.1415926535897931;
    c65_b_x = c65_A;
    c65_c_x = c65_b_x;
    c65_d_x = c65_c_x;
    c65_d1 = c65_d_x / 180.0;
    if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 0, c65_d0, c65_d1, -1,
          4U, c65_d0 > c65_d1))) {
      guard2 = true;
    } else {
      for (c65_i56 = 0; c65_i56 < 6; c65_i56++) {
        c65_c_dy[c65_i56] = c65_b_dy[c65_i56];
      }

      c65_d2 = c65_norm(chartInstance, c65_c_dy);
      c65_b_A = c65_b_ControlParams.Supervisory.MaxErrorVel * 3.1415926535897931;
      c65_e_x = c65_b_A;
      c65_f_x = c65_e_x;
      c65_g_x = c65_f_x;
      c65_d3 = c65_g_x / 180.0;
      if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 1, c65_d2, c65_d3, -1,
            4U, c65_d2 > c65_d3))) {
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
    _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 10);
    c65_b_ErrorCount = c65_b_ErrorCountIn + 1.0;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, 12);
  c65_b_Error = (c65_b_ErrorCount >
                 c65_b_ControlParams.Supervisory.MaxErrorCount);
  _SFD_EML_CALL(0U, chartInstance->c65_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c65_Error = c65_b_Error;
  *chartInstance->c65_ErrorCount = c65_b_ErrorCount;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c65_sfEvent);
}

static void initSimStructsc65_DDA2D_OSU3Dv2(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c65_machineNumber, uint32_T
  c65_chartNumber, uint32_T c65_instanceNumber)
{
  (void)c65_machineNumber;
  (void)c65_chartNumber;
  (void)c65_instanceNumber;
}

static const mxArray *c65_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData)
{
  const mxArray *c65_mxArrayOutData = NULL;
  real_T c65_u;
  const mxArray *c65_b_y = NULL;
  SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c65_mxArrayOutData = NULL;
  c65_u = *(real_T *)c65_inData;
  c65_b_y = NULL;
  sf_mex_assign(&c65_b_y, sf_mex_create("y", &c65_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c65_mxArrayOutData, c65_b_y, false);
  return c65_mxArrayOutData;
}

static real_T c65_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_b_ErrorCount, const char_T *c65_identifier)
{
  real_T c65_b_y;
  emlrtMsgIdentifier c65_thisId;
  c65_thisId.fIdentifier = c65_identifier;
  c65_thisId.fParent = NULL;
  c65_b_y = c65_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c65_b_ErrorCount),
    &c65_thisId);
  sf_mex_destroy(&c65_b_ErrorCount);
  return c65_b_y;
}

static real_T c65_b_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId)
{
  real_T c65_b_y;
  real_T c65_d4;
  (void)chartInstance;
  sf_mex_import(c65_parentId, sf_mex_dup(c65_u), &c65_d4, 1, 0, 0U, 0, 0U, 0);
  c65_b_y = c65_d4;
  sf_mex_destroy(&c65_u);
  return c65_b_y;
}

static void c65_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData)
{
  const mxArray *c65_b_ErrorCount;
  const char_T *c65_identifier;
  emlrtMsgIdentifier c65_thisId;
  real_T c65_b_y;
  SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c65_b_ErrorCount = sf_mex_dup(c65_mxArrayInData);
  c65_identifier = c65_varName;
  c65_thisId.fIdentifier = c65_identifier;
  c65_thisId.fParent = NULL;
  c65_b_y = c65_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c65_b_ErrorCount),
    &c65_thisId);
  sf_mex_destroy(&c65_b_ErrorCount);
  *(real_T *)c65_outData = c65_b_y;
  sf_mex_destroy(&c65_mxArrayInData);
}

static const mxArray *c65_b_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData)
{
  const mxArray *c65_mxArrayOutData = NULL;
  boolean_T c65_u;
  const mxArray *c65_b_y = NULL;
  SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c65_mxArrayOutData = NULL;
  c65_u = *(boolean_T *)c65_inData;
  c65_b_y = NULL;
  sf_mex_assign(&c65_b_y, sf_mex_create("y", &c65_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c65_mxArrayOutData, c65_b_y, false);
  return c65_mxArrayOutData;
}

static boolean_T c65_c_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_b_Error, const char_T *c65_identifier)
{
  boolean_T c65_b_y;
  emlrtMsgIdentifier c65_thisId;
  c65_thisId.fIdentifier = c65_identifier;
  c65_thisId.fParent = NULL;
  c65_b_y = c65_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c65_b_Error),
    &c65_thisId);
  sf_mex_destroy(&c65_b_Error);
  return c65_b_y;
}

static boolean_T c65_d_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId)
{
  boolean_T c65_b_y;
  boolean_T c65_b0;
  (void)chartInstance;
  sf_mex_import(c65_parentId, sf_mex_dup(c65_u), &c65_b0, 1, 11, 0U, 0, 0U, 0);
  c65_b_y = c65_b0;
  sf_mex_destroy(&c65_u);
  return c65_b_y;
}

static void c65_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData)
{
  const mxArray *c65_b_Error;
  const char_T *c65_identifier;
  emlrtMsgIdentifier c65_thisId;
  boolean_T c65_b_y;
  SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c65_b_Error = sf_mex_dup(c65_mxArrayInData);
  c65_identifier = c65_varName;
  c65_thisId.fIdentifier = c65_identifier;
  c65_thisId.fParent = NULL;
  c65_b_y = c65_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c65_b_Error),
    &c65_thisId);
  sf_mex_destroy(&c65_b_Error);
  *(boolean_T *)c65_outData = c65_b_y;
  sf_mex_destroy(&c65_mxArrayInData);
}

static const mxArray *c65_c_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData)
{
  const mxArray *c65_mxArrayOutData;
  c65_ControlParamsBus c65_u;
  const mxArray *c65_b_y = NULL;
  c65_SupervisoryParamsBus c65_b_u;
  const mxArray *c65_c_y = NULL;
  real_T c65_c_u;
  const mxArray *c65_d_y = NULL;
  real_T c65_d_u;
  const mxArray *c65_e_y = NULL;
  real_T c65_e_u;
  const mxArray *c65_f_y = NULL;
  real_T c65_f_u;
  const mxArray *c65_g_y = NULL;
  real_T c65_g_u;
  const mxArray *c65_h_y = NULL;
  real_T c65_h_u;
  const mxArray *c65_i_y = NULL;
  real_T c65_i_u;
  const mxArray *c65_j_y = NULL;
  real_T c65_j_u;
  const mxArray *c65_k_y = NULL;
  real_T c65_k_u;
  const mxArray *c65_l_y = NULL;
  real_T c65_l_u;
  const mxArray *c65_m_y = NULL;
  real_T c65_m_u;
  const mxArray *c65_n_y = NULL;
  int32_T c65_i57;
  real_T c65_n_u[2];
  const mxArray *c65_o_y = NULL;
  real_T c65_o_u;
  const mxArray *c65_p_y = NULL;
  real_T c65_p_u;
  const mxArray *c65_q_y = NULL;
  int32_T c65_i58;
  real_T c65_q_u[6];
  const mxArray *c65_r_y = NULL;
  int32_T c65_i59;
  real_T c65_r_u[13];
  const mxArray *c65_s_y = NULL;
  int32_T c65_i60;
  real_T c65_s_u[5];
  const mxArray *c65_t_y = NULL;
  real_T c65_t_u;
  const mxArray *c65_u_y = NULL;
  real_T c65_u_u;
  const mxArray *c65_v_y = NULL;
  real_T c65_v_u;
  const mxArray *c65_w_y = NULL;
  real_T c65_w_u;
  const mxArray *c65_x_y = NULL;
  int32_T c65_i61;
  real_T c65_x_u[6];
  const mxArray *c65_y_y = NULL;
  int32_T c65_i62;
  real_T c65_y_u[6];
  const mxArray *c65_ab_y = NULL;
  real_T c65_ab_u;
  const mxArray *c65_bb_y = NULL;
  real_T c65_bb_u;
  const mxArray *c65_cb_y = NULL;
  real_T c65_cb_u;
  const mxArray *c65_db_y = NULL;
  real_T c65_db_u;
  const mxArray *c65_eb_y = NULL;
  real_T c65_eb_u;
  const mxArray *c65_fb_y = NULL;
  real_T c65_fb_u;
  const mxArray *c65_gb_y = NULL;
  real_T c65_gb_u;
  const mxArray *c65_hb_y = NULL;
  real_T c65_hb_u;
  const mxArray *c65_ib_y = NULL;
  real_T c65_ib_u;
  const mxArray *c65_jb_y = NULL;
  real_T c65_jb_u;
  const mxArray *c65_kb_y = NULL;
  real_T c65_kb_u;
  const mxArray *c65_lb_y = NULL;
  real_T c65_lb_u;
  const mxArray *c65_mb_y = NULL;
  real_T c65_mb_u;
  const mxArray *c65_nb_y = NULL;
  real_T c65_nb_u;
  const mxArray *c65_ob_y = NULL;
  real_T c65_ob_u;
  const mxArray *c65_pb_y = NULL;
  real_T c65_pb_u;
  const mxArray *c65_qb_y = NULL;
  real_T c65_qb_u;
  const mxArray *c65_rb_y = NULL;
  real_T c65_rb_u;
  const mxArray *c65_sb_y = NULL;
  real_T c65_sb_u;
  const mxArray *c65_tb_y = NULL;
  real_T c65_tb_u;
  const mxArray *c65_ub_y = NULL;
  real_T c65_ub_u;
  const mxArray *c65_vb_y = NULL;
  int32_T c65_i63;
  real_T c65_vb_u[6];
  const mxArray *c65_wb_y = NULL;
  int32_T c65_i64;
  real_T c65_wb_u[6];
  const mxArray *c65_xb_y = NULL;
  real_T c65_xb_u;
  const mxArray *c65_yb_y = NULL;
  int32_T c65_i65;
  real_T c65_yb_u[6];
  const mxArray *c65_ac_y = NULL;
  int32_T c65_i66;
  real_T c65_ac_u[6];
  const mxArray *c65_bc_y = NULL;
  real_T c65_bc_u;
  const mxArray *c65_cc_y = NULL;
  int32_T c65_i67;
  real_T c65_cc_u[12];
  const mxArray *c65_dc_y = NULL;
  real_T c65_dc_u;
  const mxArray *c65_ec_y = NULL;
  real_T c65_ec_u;
  const mxArray *c65_fc_y = NULL;
  real_T c65_fc_u;
  const mxArray *c65_gc_y = NULL;
  real_T c65_gc_u;
  const mxArray *c65_hc_y = NULL;
  real_T c65_hc_u;
  const mxArray *c65_ic_y = NULL;
  real_T c65_ic_u;
  const mxArray *c65_jc_y = NULL;
  real_T c65_jc_u;
  const mxArray *c65_kc_y = NULL;
  real_T c65_kc_u;
  const mxArray *c65_lc_y = NULL;
  real_T c65_lc_u;
  const mxArray *c65_mc_y = NULL;
  real_T c65_mc_u;
  const mxArray *c65_nc_y = NULL;
  real_T c65_nc_u;
  const mxArray *c65_oc_y = NULL;
  int32_T c65_i68;
  real_T c65_oc_u[6];
  const mxArray *c65_pc_y = NULL;
  c65_DiscreteParamsBus c65_pc_u;
  const mxArray *c65_qc_y = NULL;
  real_T c65_qc_u;
  const mxArray *c65_rc_y = NULL;
  real_T c65_rc_u;
  const mxArray *c65_sc_y = NULL;
  real_T c65_sc_u;
  const mxArray *c65_tc_y = NULL;
  real_T c65_tc_u;
  const mxArray *c65_uc_y = NULL;
  real_T c65_uc_u;
  const mxArray *c65_vc_y = NULL;
  real_T c65_vc_u;
  const mxArray *c65_wc_y = NULL;
  real_T c65_wc_u;
  const mxArray *c65_xc_y = NULL;
  real_T c65_xc_u;
  const mxArray *c65_yc_y = NULL;
  real_T c65_yc_u;
  const mxArray *c65_ad_y = NULL;
  real_T c65_ad_u;
  const mxArray *c65_bd_y = NULL;
  real_T c65_bd_u;
  const mxArray *c65_cd_y = NULL;
  c65_OutputParamsBus c65_cd_u;
  const mxArray *c65_dd_y = NULL;
  int32_T c65_i69;
  real_T c65_dd_u[78];
  const mxArray *c65_ed_y = NULL;
  int32_T c65_i70;
  real_T c65_ed_u[36];
  const mxArray *c65_fd_y = NULL;
  int32_T c65_i71;
  real_T c65_fd_u[2];
  const mxArray *c65_gd_y = NULL;
  c65_ThetaParamsBus c65_gd_u;
  const mxArray *c65_hd_y = NULL;
  real_T c65_hd_u;
  const mxArray *c65_id_y = NULL;
  real_T c65_id_u;
  const mxArray *c65_jd_y = NULL;
  int32_T c65_i72;
  real_T c65_jd_u[13];
  const mxArray *c65_kd_y = NULL;
  real_T c65_kd_u;
  const mxArray *c65_ld_y = NULL;
  int32_T c65_i73;
  real_T c65_ld_u[7];
  const mxArray *c65_md_y = NULL;
  real_T c65_md_u;
  const mxArray *c65_nd_y = NULL;
  int32_T c65_i74;
  real_T c65_nd_u[2];
  const mxArray *c65_od_y = NULL;
  real_T c65_od_u;
  const mxArray *c65_pd_y = NULL;
  real_T c65_pd_u;
  const mxArray *c65_qd_y = NULL;
  real_T c65_qd_u;
  const mxArray *c65_rd_y = NULL;
  int32_T c65_i75;
  real_T c65_rd_u[30];
  const mxArray *c65_sd_y = NULL;
  c65_PhiParamsBus c65_sd_u;
  const mxArray *c65_td_y = NULL;
  real_T c65_td_u;
  const mxArray *c65_ud_y = NULL;
  int32_T c65_i76;
  real_T c65_ud_u[13];
  const mxArray *c65_vd_y = NULL;
  int32_T c65_i77;
  real_T c65_vd_u[20];
  const mxArray *c65_wd_y = NULL;
  real_T c65_wd_u;
  const mxArray *c65_xd_y = NULL;
  int32_T c65_i78;
  real_T c65_xd_u[2];
  const mxArray *c65_yd_y = NULL;
  int32_T c65_i79;
  real_T c65_yd_u[30];
  const mxArray *c65_ae_y = NULL;
  int32_T c65_i80;
  real_T c65_ae_u[12];
  const mxArray *c65_be_y = NULL;
  int32_T c65_i81;
  real_T c65_be_u[36];
  const mxArray *c65_ce_y = NULL;
  real_T c65_ce_u;
  const mxArray *c65_de_y = NULL;
  real_T c65_de_u;
  const mxArray *c65_ee_y = NULL;
  c65_FeedbackParamsBus c65_ee_u;
  const mxArray *c65_fe_y = NULL;
  int32_T c65_i82;
  real_T c65_fe_u[6];
  const mxArray *c65_ge_y = NULL;
  int32_T c65_i83;
  real_T c65_ge_u[6];
  const mxArray *c65_he_y = NULL;
  int32_T c65_i84;
  real_T c65_he_u[2];
  const mxArray *c65_ie_y = NULL;
  int32_T c65_i85;
  real_T c65_ie_u[2];
  const mxArray *c65_je_y = NULL;
  real_T c65_je_u;
  const mxArray *c65_ke_y = NULL;
  int32_T c65_i86;
  real_T c65_ke_u[2];
  const mxArray *c65_le_y = NULL;
  int32_T c65_i87;
  real_T c65_le_u[2];
  const mxArray *c65_me_y = NULL;
  real_T c65_me_u;
  const mxArray *c65_ne_y = NULL;
  real_T c65_ne_u;
  const mxArray *c65_oe_y = NULL;
  real_T c65_oe_u;
  const mxArray *c65_pe_y = NULL;
  real_T c65_pe_u;
  const mxArray *c65_qe_y = NULL;
  real_T c65_qe_u;
  const mxArray *c65_re_y = NULL;
  real_T c65_re_u;
  const mxArray *c65_se_y = NULL;
  real_T c65_se_u;
  const mxArray *c65_te_y = NULL;
  real_T c65_te_u;
  const mxArray *c65_ue_y = NULL;
  int32_T c65_i88;
  real_T c65_ue_u[6];
  const mxArray *c65_ve_y = NULL;
  real_T c65_ve_u;
  const mxArray *c65_we_y = NULL;
  real_T c65_we_u;
  const mxArray *c65_xe_y = NULL;
  real_T c65_xe_u;
  const mxArray *c65_ye_y = NULL;
  real_T c65_ye_u;
  const mxArray *c65_af_y = NULL;
  real_T c65_af_u;
  const mxArray *c65_bf_y = NULL;
  real_T c65_bf_u;
  const mxArray *c65_cf_y = NULL;
  real_T c65_cf_u;
  const mxArray *c65_df_y = NULL;
  real_T c65_df_u;
  const mxArray *c65_ef_y = NULL;
  real_T c65_ef_u;
  const mxArray *c65_ff_y = NULL;
  int32_T c65_i89;
  real_T c65_ff_u[6];
  const mxArray *c65_gf_y = NULL;
  real_T c65_gf_u;
  const mxArray *c65_hf_y = NULL;
  c65_SaturationParamsBus c65_hf_u;
  const mxArray *c65_if_y = NULL;
  real_T c65_if_u;
  const mxArray *c65_jf_y = NULL;
  int32_T c65_i90;
  real_T c65_jf_u[2];
  const mxArray *c65_kf_y = NULL;
  real_T c65_kf_u;
  const mxArray *c65_lf_y = NULL;
  real_T c65_lf_u;
  const mxArray *c65_mf_y = NULL;
  real_T c65_mf_u;
  const mxArray *c65_nf_y = NULL;
  real_T c65_nf_u;
  const mxArray *c65_of_y = NULL;
  real_T c65_of_u;
  const mxArray *c65_pf_y = NULL;
  SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c65_mxArrayOutData = NULL;
  c65_mxArrayOutData = NULL;
  c65_u = *(c65_ControlParamsBus *)c65_inData;
  c65_b_y = NULL;
  sf_mex_assign(&c65_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c65_b_u = c65_u.Supervisory;
  c65_c_y = NULL;
  sf_mex_assign(&c65_c_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c65_c_u = c65_b_u.EnableSwapOnKAAccel;
  c65_d_y = NULL;
  sf_mex_assign(&c65_d_y, sf_mex_create("y", &c65_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_d_y, "EnableSwapOnKAAccel", "EnableSwapOnKAAccel",
                  0);
  c65_d_u = c65_b_u.EnableSwapOnKASpring;
  c65_e_y = NULL;
  sf_mex_assign(&c65_e_y, sf_mex_create("y", &c65_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_e_y, "EnableSwapOnKASpring",
                  "EnableSwapOnKASpring", 0);
  c65_e_u = c65_b_u.EnableBackwardSwap;
  c65_f_y = NULL;
  sf_mex_assign(&c65_f_y, sf_mex_create("y", &c65_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_f_y, "EnableBackwardSwap", "EnableBackwardSwap",
                  0);
  c65_f_u = c65_b_u.ImpactThresholdKAAccel;
  c65_g_y = NULL;
  sf_mex_assign(&c65_g_y, sf_mex_create("y", &c65_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_g_y, "ImpactThresholdKAAccel",
                  "ImpactThresholdKAAccel", 0);
  c65_g_u = c65_b_u.ImpactThresholdKASpringAbs;
  c65_h_y = NULL;
  sf_mex_assign(&c65_h_y, sf_mex_create("y", &c65_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_h_y, "ImpactThresholdKASpringAbs",
                  "ImpactThresholdKASpringAbs", 0);
  c65_h_u = c65_b_u.ImpactThresholdKASpringRel;
  c65_i_y = NULL;
  sf_mex_assign(&c65_i_y, sf_mex_create("y", &c65_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_i_y, "ImpactThresholdKASpringRel",
                  "ImpactThresholdKASpringRel", 0);
  c65_i_u = c65_b_u.SwapThresholdS;
  c65_j_y = NULL;
  sf_mex_assign(&c65_j_y, sf_mex_create("y", &c65_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_j_y, "SwapThresholdS", "SwapThresholdS", 0);
  c65_j_u = c65_b_u.AllowDoubleSupport;
  c65_k_y = NULL;
  sf_mex_assign(&c65_k_y, sf_mex_create("y", &c65_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_k_y, "AllowDoubleSupport", "AllowDoubleSupport",
                  0);
  c65_k_u = c65_b_u.UseGaitTransition;
  c65_l_y = NULL;
  sf_mex_assign(&c65_l_y, sf_mex_create("y", &c65_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_l_y, "UseGaitTransition", "UseGaitTransition", 0);
  c65_l_u = c65_b_u.NumTransitionSteps;
  c65_m_y = NULL;
  sf_mex_assign(&c65_m_y, sf_mex_create("y", &c65_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_m_y, "NumTransitionSteps", "NumTransitionSteps",
                  0);
  c65_m_u = c65_b_u.TransitionThresholdTorsoVel;
  c65_n_y = NULL;
  sf_mex_assign(&c65_n_y, sf_mex_create("y", &c65_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_n_y, "TransitionThresholdTorsoVel",
                  "TransitionThresholdTorsoVel", 0);
  for (c65_i57 = 0; c65_i57 < 2; c65_i57++) {
    c65_n_u[c65_i57] = c65_b_u.KAInjection[c65_i57];
  }

  c65_o_y = NULL;
  sf_mex_assign(&c65_o_y, sf_mex_create("y", c65_n_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c65_c_y, c65_o_y, "KAInjection", "KAInjection", 0);
  c65_o_u = c65_b_u.MinDeltaThetaTransition;
  c65_p_y = NULL;
  sf_mex_assign(&c65_p_y, sf_mex_create("y", &c65_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_p_y, "MinDeltaThetaTransition",
                  "MinDeltaThetaTransition", 0);
  c65_p_u = c65_b_u.StartSecondGaitOnStep;
  c65_q_y = NULL;
  sf_mex_assign(&c65_q_y, sf_mex_create("y", &c65_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_q_y, "StartSecondGaitOnStep",
                  "StartSecondGaitOnStep", 0);
  for (c65_i58 = 0; c65_i58 < 6; c65_i58++) {
    c65_q_u[c65_i58] = c65_b_u.VBLAParams[c65_i58];
  }

  c65_r_y = NULL;
  sf_mex_assign(&c65_r_y, sf_mex_create("y", c65_q_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c65_c_y, c65_r_y, "VBLAParams", "VBLAParams", 0);
  for (c65_i59 = 0; c65_i59 < 13; c65_i59++) {
    c65_r_u[c65_i59] = c65_b_u.BalanceParams[c65_i59];
  }

  c65_s_y = NULL;
  sf_mex_assign(&c65_s_y, sf_mex_create("y", c65_r_u, 0, 0U, 1U, 0U, 1, 13),
                false);
  sf_mex_addfield(c65_c_y, c65_s_y, "BalanceParams", "BalanceParams", 0);
  for (c65_i60 = 0; c65_i60 < 5; c65_i60++) {
    c65_s_u[c65_i60] = c65_b_u.GaitTweaks[c65_i60];
  }

  c65_t_y = NULL;
  sf_mex_assign(&c65_t_y, sf_mex_create("y", c65_s_u, 0, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_addfield(c65_c_y, c65_t_y, "GaitTweaks", "GaitTweaks", 0);
  c65_t_u = c65_b_u.TStepInitial;
  c65_u_y = NULL;
  sf_mex_assign(&c65_u_y, sf_mex_create("y", &c65_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_u_y, "TStepInitial", "TStepInitial", 0);
  c65_u_u = c65_b_u.TMaxUpdate;
  c65_v_y = NULL;
  sf_mex_assign(&c65_v_y, sf_mex_create("y", &c65_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_v_y, "TMaxUpdate", "TMaxUpdate", 0);
  c65_v_u = c65_b_u.RunMode;
  c65_w_y = NULL;
  sf_mex_assign(&c65_w_y, sf_mex_create("y", &c65_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_w_y, "RunMode", "RunMode", 0);
  c65_w_u = c65_b_u.UseAbsoluteSwingLA;
  c65_x_y = NULL;
  sf_mex_assign(&c65_x_y, sf_mex_create("y", &c65_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_c_y, c65_x_y, "UseAbsoluteSwingLA", "UseAbsoluteSwingLA",
                  0);
  for (c65_i61 = 0; c65_i61 < 6; c65_i61++) {
    c65_x_u[c65_i61] = c65_b_u.ErrorZeroFactor[c65_i61];
  }

  c65_y_y = NULL;
  sf_mex_assign(&c65_y_y, sf_mex_create("y", c65_x_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c65_c_y, c65_y_y, "ErrorZeroFactor", "ErrorZeroFactor", 0);
  for (c65_i62 = 0; c65_i62 < 6; c65_i62++) {
    c65_y_u[c65_i62] = c65_b_u.ErrorVelZeroFactor[c65_i62];
  }

  c65_ab_y = NULL;
  sf_mex_assign(&c65_ab_y, sf_mex_create("y", c65_y_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c65_c_y, c65_ab_y, "ErrorVelZeroFactor", "ErrorVelZeroFactor",
                  0);
  c65_ab_u = c65_b_u.StanceLegInit;
  c65_bb_y = NULL;
  sf_mex_assign(&c65_bb_y, sf_mex_create("y", &c65_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_bb_y, "StanceLegInit", "StanceLegInit", 0);
  c65_bb_u = c65_b_u.ControllerModeInit;
  c65_cb_y = NULL;
  sf_mex_assign(&c65_cb_y, sf_mex_create("y", &c65_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_cb_y, "ControllerModeInit", "ControllerModeInit",
                  0);
  c65_cb_u = c65_b_u.UsePosingControl;
  c65_db_y = NULL;
  sf_mex_assign(&c65_db_y, sf_mex_create("y", &c65_cb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_db_y, "UsePosingControl", "UsePosingControl", 0);
  c65_db_u = c65_b_u.TPosing;
  c65_eb_y = NULL;
  sf_mex_assign(&c65_eb_y, sf_mex_create("y", &c65_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_eb_y, "TPosing", "TPosing", 0);
  c65_eb_u = c65_b_u.TorsoBackAngle;
  c65_fb_y = NULL;
  sf_mex_assign(&c65_fb_y, sf_mex_create("y", &c65_eb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_fb_y, "TorsoBackAngle", "TorsoBackAngle", 0);
  c65_fb_u = c65_b_u.TorsoBackOnStep;
  c65_gb_y = NULL;
  sf_mex_assign(&c65_gb_y, sf_mex_create("y", &c65_fb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_gb_y, "TorsoBackOnStep", "TorsoBackOnStep", 0);
  c65_gb_u = c65_b_u.EnergyControlGain;
  c65_hb_y = NULL;
  sf_mex_assign(&c65_hb_y, sf_mex_create("y", &c65_gb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_hb_y, "EnergyControlGain", "EnergyControlGain", 0);
  c65_hb_u = c65_b_u.EnergyControlPhi0;
  c65_ib_y = NULL;
  sf_mex_assign(&c65_ib_y, sf_mex_create("y", &c65_hb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_ib_y, "EnergyControlPhi0", "EnergyControlPhi0", 0);
  c65_ib_u = c65_b_u.VelocityControlTorsoMax;
  c65_jb_y = NULL;
  sf_mex_assign(&c65_jb_y, sf_mex_create("y", &c65_ib_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_jb_y, "VelocityControlTorsoMax",
                  "VelocityControlTorsoMax", 0);
  c65_jb_u = c65_b_u.VelocityControlTorsoMin;
  c65_kb_y = NULL;
  sf_mex_assign(&c65_kb_y, sf_mex_create("y", &c65_jb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_kb_y, "VelocityControlTorsoMin",
                  "VelocityControlTorsoMin", 0);
  c65_kb_u = c65_b_u.VelocityControlTorsoGain;
  c65_lb_y = NULL;
  sf_mex_assign(&c65_lb_y, sf_mex_create("y", &c65_kb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_lb_y, "VelocityControlTorsoGain",
                  "VelocityControlTorsoGain", 0);
  c65_lb_u = c65_b_u.VelocityControlTorsoV0;
  c65_mb_y = NULL;
  sf_mex_assign(&c65_mb_y, sf_mex_create("y", &c65_lb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_mb_y, "VelocityControlTorsoV0",
                  "VelocityControlTorsoV0", 0);
  c65_mb_u = c65_b_u.MinDeltaTheta;
  c65_nb_y = NULL;
  sf_mex_assign(&c65_nb_y, sf_mex_create("y", &c65_mb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_nb_y, "MinDeltaTheta", "MinDeltaTheta", 0);
  c65_nb_u = c65_b_u.Theta0;
  c65_ob_y = NULL;
  sf_mex_assign(&c65_ob_y, sf_mex_create("y", &c65_nb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_ob_y, "Theta0", "Theta0", 0);
  c65_ob_u = c65_b_u.KThetaPlus;
  c65_pb_y = NULL;
  sf_mex_assign(&c65_pb_y, sf_mex_create("y", &c65_ob_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_pb_y, "KThetaPlus", "KThetaPlus", 0);
  c65_pb_u = c65_b_u.KThetaMinus;
  c65_qb_y = NULL;
  sf_mex_assign(&c65_qb_y, sf_mex_create("y", &c65_pb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_qb_y, "KThetaMinus", "KThetaMinus", 0);
  c65_qb_u = c65_b_u.RollPhaseVelocityThresh;
  c65_rb_y = NULL;
  sf_mex_assign(&c65_rb_y, sf_mex_create("y", &c65_qb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_rb_y, "RollPhaseVelocityThresh",
                  "RollPhaseVelocityThresh", 0);
  c65_rb_u = c65_b_u.RollPhaseSThresh;
  c65_sb_y = NULL;
  sf_mex_assign(&c65_sb_y, sf_mex_create("y", &c65_rb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_sb_y, "RollPhaseSThresh", "RollPhaseSThresh", 0);
  c65_sb_u = c65_b_u.MaxError;
  c65_tb_y = NULL;
  sf_mex_assign(&c65_tb_y, sf_mex_create("y", &c65_sb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_tb_y, "MaxError", "MaxError", 0);
  c65_tb_u = c65_b_u.MaxErrorVel;
  c65_ub_y = NULL;
  sf_mex_assign(&c65_ub_y, sf_mex_create("y", &c65_tb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_ub_y, "MaxErrorVel", "MaxErrorVel", 0);
  c65_ub_u = c65_b_u.MaxErrorCount;
  c65_vb_y = NULL;
  sf_mex_assign(&c65_vb_y, sf_mex_create("y", &c65_ub_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_vb_y, "MaxErrorCount", "MaxErrorCount", 0);
  for (c65_i63 = 0; c65_i63 < 6; c65_i63++) {
    c65_vb_u[c65_i63] = c65_b_u.K1MidStanceUpdate[c65_i63];
  }

  c65_wb_y = NULL;
  sf_mex_assign(&c65_wb_y, sf_mex_create("y", c65_vb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c65_c_y, c65_wb_y, "K1MidStanceUpdate", "K1MidStanceUpdate", 0);
  for (c65_i64 = 0; c65_i64 < 6; c65_i64++) {
    c65_wb_u[c65_i64] = c65_b_u.K2MidStanceUpdate[c65_i64];
  }

  c65_xb_y = NULL;
  sf_mex_assign(&c65_xb_y, sf_mex_create("y", c65_wb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c65_c_y, c65_xb_y, "K2MidStanceUpdate", "K2MidStanceUpdate", 0);
  c65_xb_u = c65_b_u.EnableVelocityBasedUpdate;
  c65_yb_y = NULL;
  sf_mex_assign(&c65_yb_y, sf_mex_create("y", &c65_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_yb_y, "EnableVelocityBasedUpdate",
                  "EnableVelocityBasedUpdate", 0);
  for (c65_i65 = 0; c65_i65 < 6; c65_i65++) {
    c65_yb_u[c65_i65] = c65_b_u.VelocityBasedUpdateK1[c65_i65];
  }

  c65_ac_y = NULL;
  sf_mex_assign(&c65_ac_y, sf_mex_create("y", c65_yb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c65_c_y, c65_ac_y, "VelocityBasedUpdateK1",
                  "VelocityBasedUpdateK1", 0);
  for (c65_i66 = 0; c65_i66 < 6; c65_i66++) {
    c65_ac_u[c65_i66] = c65_b_u.VelocityBasedUpdateK2[c65_i66];
  }

  c65_bc_y = NULL;
  sf_mex_assign(&c65_bc_y, sf_mex_create("y", c65_ac_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c65_c_y, c65_bc_y, "VelocityBasedUpdateK2",
                  "VelocityBasedUpdateK2", 0);
  c65_bc_u = c65_b_u.VelocityBasedUpdateDTheta0;
  c65_cc_y = NULL;
  sf_mex_assign(&c65_cc_y, sf_mex_create("y", &c65_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_cc_y, "VelocityBasedUpdateDTheta0",
                  "VelocityBasedUpdateDTheta0", 0);
  for (c65_i67 = 0; c65_i67 < 12; c65_i67++) {
    c65_cc_u[c65_i67] = c65_b_u.VelocityBasedUpdateLimits[c65_i67];
  }

  c65_dc_y = NULL;
  sf_mex_assign(&c65_dc_y, sf_mex_create("y", c65_cc_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c65_c_y, c65_dc_y, "VelocityBasedUpdateLimits",
                  "VelocityBasedUpdateLimits", 0);
  c65_dc_u = c65_b_u.DesiredYawOffset;
  c65_ec_y = NULL;
  sf_mex_assign(&c65_ec_y, sf_mex_create("y", &c65_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_ec_y, "DesiredYawOffset", "DesiredYawOffset", 0);
  c65_ec_u = c65_b_u.dx_cmd;
  c65_fc_y = NULL;
  sf_mex_assign(&c65_fc_y, sf_mex_create("y", &c65_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_fc_y, "dx_cmd", "dx_cmd", 0);
  c65_fc_u = c65_b_u.ForBackward;
  c65_gc_y = NULL;
  sf_mex_assign(&c65_gc_y, sf_mex_create("y", &c65_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_gc_y, "ForBackward", "ForBackward", 0);
  c65_gc_u = c65_b_u.EnableFrictionID;
  c65_hc_y = NULL;
  sf_mex_assign(&c65_hc_y, sf_mex_create("y", &c65_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_hc_y, "EnableFrictionID", "EnableFrictionID", 0);
  c65_hc_u = c65_b_u.ResetFrictionPosing;
  c65_ic_y = NULL;
  sf_mex_assign(&c65_ic_y, sf_mex_create("y", &c65_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_ic_y, "ResetFrictionPosing",
                  "ResetFrictionPosing", 0);
  c65_ic_u = c65_b_u.MoveLegIndex;
  c65_jc_y = NULL;
  sf_mex_assign(&c65_jc_y, sf_mex_create("y", &c65_ic_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_jc_y, "MoveLegIndex", "MoveLegIndex", 0);
  c65_jc_u = c65_b_u.dy_cmd;
  c65_kc_y = NULL;
  sf_mex_assign(&c65_kc_y, sf_mex_create("y", &c65_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_kc_y, "dy_cmd", "dy_cmd", 0);
  c65_kc_u = c65_b_u.TauDelay;
  c65_lc_y = NULL;
  sf_mex_assign(&c65_lc_y, sf_mex_create("y", &c65_kc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_lc_y, "TauDelay", "TauDelay", 0);
  c65_lc_u = c65_b_u.TrackFrequency;
  c65_mc_y = NULL;
  sf_mex_assign(&c65_mc_y, sf_mex_create("y", &c65_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_mc_y, "TrackFrequency", "TrackFrequency", 0);
  c65_mc_u = c65_b_u.EnablePDControl;
  c65_nc_y = NULL;
  sf_mex_assign(&c65_nc_y, sf_mex_create("y", &c65_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_nc_y, "EnablePDControl", "EnablePDControl", 0);
  c65_nc_u = c65_b_u.TorqueAmp;
  c65_oc_y = NULL;
  sf_mex_assign(&c65_oc_y, sf_mex_create("y", &c65_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_c_y, c65_oc_y, "TorqueAmp", "TorqueAmp", 0);
  for (c65_i68 = 0; c65_i68 < 6; c65_i68++) {
    c65_oc_u[c65_i68] = c65_b_u.hdPosing[c65_i68];
  }

  c65_pc_y = NULL;
  sf_mex_assign(&c65_pc_y, sf_mex_create("y", c65_oc_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c65_c_y, c65_pc_y, "hdPosing", "hdPosing", 0);
  sf_mex_addfield(c65_b_y, c65_c_y, "Supervisory", "Supervisory", 0);
  c65_pc_u = c65_u.Discrete;
  c65_qc_y = NULL;
  sf_mex_assign(&c65_qc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c65_qc_u = c65_pc_u.TLastUpdate;
  c65_rc_y = NULL;
  sf_mex_assign(&c65_rc_y, sf_mex_create("y", &c65_qc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_qc_y, c65_rc_y, "TLastUpdate", "TLastUpdate", 0);
  c65_rc_u = c65_pc_u.VelocityControlLADelta;
  c65_sc_y = NULL;
  sf_mex_assign(&c65_sc_y, sf_mex_create("y", &c65_rc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_qc_y, c65_sc_y, "VelocityControlLADelta",
                  "VelocityControlLADelta", 0);
  c65_sc_u = c65_pc_u.VelocityControlTorsoDelta;
  c65_tc_y = NULL;
  sf_mex_assign(&c65_tc_y, sf_mex_create("y", &c65_sc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_qc_y, c65_tc_y, "VelocityControlTorsoDelta",
                  "VelocityControlTorsoDelta", 0);
  c65_tc_u = c65_pc_u.VelocityControlHipDistCur;
  c65_uc_y = NULL;
  sf_mex_assign(&c65_uc_y, sf_mex_create("y", &c65_tc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_qc_y, c65_uc_y, "VelocityControlHipDistCur",
                  "VelocityControlHipDistCur", 0);
  c65_uc_u = c65_pc_u.VelocityControlHipDistPrev;
  c65_vc_y = NULL;
  sf_mex_assign(&c65_vc_y, sf_mex_create("y", &c65_uc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_qc_y, c65_vc_y, "VelocityControlHipDistPrev",
                  "VelocityControlHipDistPrev", 0);
  c65_vc_u = c65_pc_u.VirtualSpringMode;
  c65_wc_y = NULL;
  sf_mex_assign(&c65_wc_y, sf_mex_create("y", &c65_vc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_qc_y, c65_wc_y, "VirtualSpringMode", "VirtualSpringMode",
                  0);
  c65_wc_u = c65_pc_u.VirtualSpringStiffness;
  c65_xc_y = NULL;
  sf_mex_assign(&c65_xc_y, sf_mex_create("y", &c65_wc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_qc_y, c65_xc_y, "VirtualSpringStiffness",
                  "VirtualSpringStiffness", 0);
  c65_xc_u = c65_pc_u.VirtualSpringDamping;
  c65_yc_y = NULL;
  sf_mex_assign(&c65_yc_y, sf_mex_create("y", &c65_xc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_qc_y, c65_yc_y, "VirtualSpringDamping",
                  "VirtualSpringDamping", 0);
  c65_yc_u = c65_pc_u.VirtualSpringModAmplitude;
  c65_ad_y = NULL;
  sf_mex_assign(&c65_ad_y, sf_mex_create("y", &c65_yc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_qc_y, c65_ad_y, "VirtualSpringModAmplitude",
                  "VirtualSpringModAmplitude", 0);
  c65_ad_u = c65_pc_u.VirtualSpringModRate;
  c65_bd_y = NULL;
  sf_mex_assign(&c65_bd_y, sf_mex_create("y", &c65_ad_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_qc_y, c65_bd_y, "VirtualSpringModRate",
                  "VirtualSpringModRate", 0);
  c65_bd_u = c65_pc_u.VirtualSpringRestPos;
  c65_cd_y = NULL;
  sf_mex_assign(&c65_cd_y, sf_mex_create("y", &c65_bd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_qc_y, c65_cd_y, "VirtualSpringRestPos",
                  "VirtualSpringRestPos", 0);
  sf_mex_addfield(c65_b_y, c65_qc_y, "Discrete", "Discrete", 0);
  c65_cd_u = c65_u.Output;
  c65_dd_y = NULL;
  sf_mex_assign(&c65_dd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c65_i69 = 0; c65_i69 < 78; c65_i69++) {
    c65_dd_u[c65_i69] = c65_cd_u.H0[c65_i69];
  }

  c65_ed_y = NULL;
  sf_mex_assign(&c65_ed_y, sf_mex_create("y", c65_dd_u, 0, 0U, 1U, 0U, 2, 6, 13),
                false);
  sf_mex_addfield(c65_dd_y, c65_ed_y, "H0", "H0", 0);
  for (c65_i70 = 0; c65_i70 < 36; c65_i70++) {
    c65_ed_u[c65_i70] = c65_cd_u.HAlpha[c65_i70];
  }

  c65_fd_y = NULL;
  sf_mex_assign(&c65_fd_y, sf_mex_create("y", c65_ed_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c65_dd_y, c65_fd_y, "HAlpha", "HAlpha", 0);
  for (c65_i71 = 0; c65_i71 < 2; c65_i71++) {
    c65_fd_u[c65_i71] = c65_cd_u.ThetaLimits[c65_i71];
  }

  c65_gd_y = NULL;
  sf_mex_assign(&c65_gd_y, sf_mex_create("y", c65_fd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c65_dd_y, c65_gd_y, "ThetaLimits", "ThetaLimits", 0);
  c65_gd_u = c65_cd_u.Theta;
  c65_hd_y = NULL;
  sf_mex_assign(&c65_hd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c65_hd_u = c65_gd_u.c0;
  c65_id_y = NULL;
  sf_mex_assign(&c65_id_y, sf_mex_create("y", &c65_hd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_hd_y, c65_id_y, "c0", "c0", 0);
  c65_id_u = c65_gd_u.ct;
  c65_jd_y = NULL;
  sf_mex_assign(&c65_jd_y, sf_mex_create("y", &c65_id_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_hd_y, c65_jd_y, "ct", "ct", 0);
  for (c65_i72 = 0; c65_i72 < 13; c65_i72++) {
    c65_jd_u[c65_i72] = c65_gd_u.cq[c65_i72];
  }

  c65_kd_y = NULL;
  sf_mex_assign(&c65_kd_y, sf_mex_create("y", c65_jd_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c65_hd_y, c65_kd_y, "cq", "cq", 0);
  c65_kd_u = c65_gd_u.t0;
  c65_ld_y = NULL;
  sf_mex_assign(&c65_ld_y, sf_mex_create("y", &c65_kd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_hd_y, c65_ld_y, "t0", "t0", 0);
  for (c65_i73 = 0; c65_i73 < 7; c65_i73++) {
    c65_ld_u[c65_i73] = c65_gd_u.cz[c65_i73];
  }

  c65_md_y = NULL;
  sf_mex_assign(&c65_md_y, sf_mex_create("y", c65_ld_u, 0, 0U, 1U, 0U, 2, 1, 7),
                false);
  sf_mex_addfield(c65_hd_y, c65_md_y, "cz", "cz", 0);
  sf_mex_addfield(c65_dd_y, c65_hd_y, "Theta", "Theta", 0);
  c65_md_u = c65_cd_u.SaturateS;
  c65_nd_y = NULL;
  sf_mex_assign(&c65_nd_y, sf_mex_create("y", &c65_md_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_dd_y, c65_nd_y, "SaturateS", "SaturateS", 0);
  for (c65_i74 = 0; c65_i74 < 2; c65_i74++) {
    c65_nd_u[c65_i74] = c65_cd_u.SLimits[c65_i74];
  }

  c65_od_y = NULL;
  sf_mex_assign(&c65_od_y, sf_mex_create("y", c65_nd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c65_dd_y, c65_od_y, "SLimits", "SLimits", 0);
  c65_od_u = c65_cd_u.EnforceIncreasingS;
  c65_pd_y = NULL;
  sf_mex_assign(&c65_pd_y, sf_mex_create("y", &c65_od_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_dd_y, c65_pd_y, "EnforceIncreasingS", "EnforceIncreasingS",
                  0);
  c65_pd_u = c65_cd_u.UseCorrection;
  c65_qd_y = NULL;
  sf_mex_assign(&c65_qd_y, sf_mex_create("y", &c65_pd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_dd_y, c65_qd_y, "UseCorrection", "UseCorrection", 0);
  c65_qd_u = c65_cd_u.SMaxCorrection;
  c65_rd_y = NULL;
  sf_mex_assign(&c65_rd_y, sf_mex_create("y", &c65_qd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_dd_y, c65_rd_y, "SMaxCorrection", "SMaxCorrection", 0);
  for (c65_i75 = 0; c65_i75 < 30; c65_i75++) {
    c65_rd_u[c65_i75] = c65_cd_u.HAlphaCorrection[c65_i75];
  }

  c65_sd_y = NULL;
  sf_mex_assign(&c65_sd_y, sf_mex_create("y", c65_rd_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c65_dd_y, c65_sd_y, "HAlphaCorrection", "HAlphaCorrection", 0);
  c65_sd_u = c65_cd_u.Phi;
  c65_td_y = NULL;
  sf_mex_assign(&c65_td_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c65_td_u = c65_sd_u.c0;
  c65_ud_y = NULL;
  sf_mex_assign(&c65_ud_y, sf_mex_create("y", &c65_td_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_td_y, c65_ud_y, "c0", "c0", 0);
  for (c65_i76 = 0; c65_i76 < 13; c65_i76++) {
    c65_ud_u[c65_i76] = c65_sd_u.cq[c65_i76];
  }

  c65_vd_y = NULL;
  sf_mex_assign(&c65_vd_y, sf_mex_create("y", c65_ud_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c65_td_y, c65_vd_y, "cq", "cq", 0);
  sf_mex_addfield(c65_dd_y, c65_td_y, "Phi", "Phi", 0);
  for (c65_i77 = 0; c65_i77 < 20; c65_i77++) {
    c65_vd_u[c65_i77] = c65_cd_u.PhiAlpha[c65_i77];
  }

  c65_wd_y = NULL;
  sf_mex_assign(&c65_wd_y, sf_mex_create("y", c65_vd_u, 0, 0U, 1U, 0U, 2, 1, 20),
                false);
  sf_mex_addfield(c65_dd_y, c65_wd_y, "PhiAlpha", "PhiAlpha", 0);
  c65_wd_u = c65_cd_u.SaturateR;
  c65_xd_y = NULL;
  sf_mex_assign(&c65_xd_y, sf_mex_create("y", &c65_wd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_dd_y, c65_xd_y, "SaturateR", "SaturateR", 0);
  for (c65_i78 = 0; c65_i78 < 2; c65_i78++) {
    c65_xd_u[c65_i78] = c65_cd_u.RLimits[c65_i78];
  }

  c65_yd_y = NULL;
  sf_mex_assign(&c65_yd_y, sf_mex_create("y", c65_xd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c65_dd_y, c65_yd_y, "RLimits", "RLimits", 0);
  for (c65_i79 = 0; c65_i79 < 30; c65_i79++) {
    c65_yd_u[c65_i79] = c65_cd_u.HBarAlpha[c65_i79];
  }

  c65_ae_y = NULL;
  sf_mex_assign(&c65_ae_y, sf_mex_create("y", c65_yd_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c65_dd_y, c65_ae_y, "HBarAlpha", "HBarAlpha", 0);
  for (c65_i80 = 0; c65_i80 < 12; c65_i80++) {
    c65_ae_u[c65_i80] = c65_cd_u.HBarLimits[c65_i80];
  }

  c65_be_y = NULL;
  sf_mex_assign(&c65_be_y, sf_mex_create("y", c65_ae_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c65_dd_y, c65_be_y, "HBarLimits", "HBarLimits", 0);
  for (c65_i81 = 0; c65_i81 < 36; c65_i81++) {
    c65_be_u[c65_i81] = c65_cd_u.HAlphaStar[c65_i81];
  }

  c65_ce_y = NULL;
  sf_mex_assign(&c65_ce_y, sf_mex_create("y", c65_be_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c65_dd_y, c65_ce_y, "HAlphaStar", "HAlphaStar", 0);
  c65_ce_u = c65_cd_u.YawLimit;
  c65_de_y = NULL;
  sf_mex_assign(&c65_de_y, sf_mex_create("y", &c65_ce_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_dd_y, c65_de_y, "YawLimit", "YawLimit", 0);
  c65_de_u = c65_cd_u.test;
  c65_ee_y = NULL;
  sf_mex_assign(&c65_ee_y, sf_mex_create("y", &c65_de_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_dd_y, c65_ee_y, "test", "test", 0);
  sf_mex_addfield(c65_b_y, c65_dd_y, "Output", "Output", 0);
  c65_ee_u = c65_u.Feedback;
  c65_fe_y = NULL;
  sf_mex_assign(&c65_fe_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c65_i82 = 0; c65_i82 < 6; c65_i82++) {
    c65_fe_u[c65_i82] = c65_ee_u.kp[c65_i82];
  }

  c65_ge_y = NULL;
  sf_mex_assign(&c65_ge_y, sf_mex_create("y", c65_fe_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c65_fe_y, c65_ge_y, "kp", "kp", 0);
  for (c65_i83 = 0; c65_i83 < 6; c65_i83++) {
    c65_ge_u[c65_i83] = c65_ee_u.kd[c65_i83];
  }

  c65_he_y = NULL;
  sf_mex_assign(&c65_he_y, sf_mex_create("y", c65_ge_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c65_fe_y, c65_he_y, "kd", "kd", 0);
  for (c65_i84 = 0; c65_i84 < 2; c65_i84++) {
    c65_he_u[c65_i84] = c65_ee_u.epsilon[c65_i84];
  }

  c65_ie_y = NULL;
  sf_mex_assign(&c65_ie_y, sf_mex_create("y", c65_he_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c65_fe_y, c65_ie_y, "epsilon", "epsilon", 0);
  for (c65_i85 = 0; c65_i85 < 2; c65_i85++) {
    c65_ie_u[c65_i85] = c65_ee_u.kff_grav[c65_i85];
  }

  c65_je_y = NULL;
  sf_mex_assign(&c65_je_y, sf_mex_create("y", c65_ie_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c65_fe_y, c65_je_y, "kff_grav", "kff_grav", 0);
  c65_je_u = c65_ee_u.delta_grav;
  c65_ke_y = NULL;
  sf_mex_assign(&c65_ke_y, sf_mex_create("y", &c65_je_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_ke_y, "delta_grav", "delta_grav", 0);
  for (c65_i86 = 0; c65_i86 < 2; c65_i86++) {
    c65_ke_u[c65_i86] = c65_ee_u.kff_decoup[c65_i86];
  }

  c65_le_y = NULL;
  sf_mex_assign(&c65_le_y, sf_mex_create("y", c65_ke_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c65_fe_y, c65_le_y, "kff_decoup", "kff_decoup", 0);
  for (c65_i87 = 0; c65_i87 < 2; c65_i87++) {
    c65_le_u[c65_i87] = c65_ee_u.kd_torso[c65_i87];
  }

  c65_me_y = NULL;
  sf_mex_assign(&c65_me_y, sf_mex_create("y", c65_le_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c65_fe_y, c65_me_y, "kd_torso", "kd_torso", 0);
  c65_me_u = c65_ee_u.kp_2dof;
  c65_ne_y = NULL;
  sf_mex_assign(&c65_ne_y, sf_mex_create("y", &c65_me_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_ne_y, "kp_2dof", "kp_2dof", 0);
  c65_ne_u = c65_ee_u.kd_2dof;
  c65_oe_y = NULL;
  sf_mex_assign(&c65_oe_y, sf_mex_create("y", &c65_ne_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_oe_y, "kd_2dof", "kd_2dof", 0);
  c65_oe_u = c65_ee_u.kpre_2dof;
  c65_pe_y = NULL;
  sf_mex_assign(&c65_pe_y, sf_mex_create("y", &c65_oe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_pe_y, "kpre_2dof", "kpre_2dof", 0);
  c65_pe_u = c65_ee_u.kp_lat;
  c65_qe_y = NULL;
  sf_mex_assign(&c65_qe_y, sf_mex_create("y", &c65_pe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_qe_y, "kp_lat", "kp_lat", 0);
  c65_qe_u = c65_ee_u.kd_lat;
  c65_re_y = NULL;
  sf_mex_assign(&c65_re_y, sf_mex_create("y", &c65_qe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_re_y, "kd_lat", "kd_lat", 0);
  c65_re_u = c65_ee_u.q3d_min_lat;
  c65_se_y = NULL;
  sf_mex_assign(&c65_se_y, sf_mex_create("y", &c65_re_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_se_y, "q3d_min_lat", "q3d_min_lat", 0);
  c65_se_u = c65_ee_u.q3d_max_lat;
  c65_te_y = NULL;
  sf_mex_assign(&c65_te_y, sf_mex_create("y", &c65_se_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_te_y, "q3d_max_lat", "q3d_max_lat", 0);
  c65_te_u = c65_ee_u.w_torso_lat;
  c65_ue_y = NULL;
  sf_mex_assign(&c65_ue_y, sf_mex_create("y", &c65_te_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_ue_y, "w_torso_lat", "w_torso_lat", 0);
  for (c65_i88 = 0; c65_i88 < 6; c65_i88++) {
    c65_ue_u[c65_i88] = c65_ee_u.u_ff[c65_i88];
  }

  c65_ve_y = NULL;
  sf_mex_assign(&c65_ve_y, sf_mex_create("y", c65_ue_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c65_fe_y, c65_ve_y, "u_ff", "u_ff", 0);
  c65_ve_u = c65_ee_u.LateralControlMode;
  c65_we_y = NULL;
  sf_mex_assign(&c65_we_y, sf_mex_create("y", &c65_ve_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_we_y, "LateralControlMode", "LateralControlMode",
                  0);
  c65_we_u = c65_ee_u.DecouplingMode;
  c65_xe_y = NULL;
  sf_mex_assign(&c65_xe_y, sf_mex_create("y", &c65_we_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_xe_y, "DecouplingMode", "DecouplingMode", 0);
  c65_xe_u = c65_ee_u.Use2DOF;
  c65_ye_y = NULL;
  sf_mex_assign(&c65_ye_y, sf_mex_create("y", &c65_xe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_ye_y, "Use2DOF", "Use2DOF", 0);
  c65_ye_u = c65_ee_u.UseDSGravComp;
  c65_af_y = NULL;
  sf_mex_assign(&c65_af_y, sf_mex_create("y", &c65_ye_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_af_y, "UseDSGravComp", "UseDSGravComp", 0);
  c65_af_u = c65_ee_u.lat_bias;
  c65_bf_y = NULL;
  sf_mex_assign(&c65_bf_y, sf_mex_create("y", &c65_af_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_bf_y, "lat_bias", "lat_bias", 0);
  c65_bf_u = c65_ee_u.lat_bias2;
  c65_cf_y = NULL;
  sf_mex_assign(&c65_cf_y, sf_mex_create("y", &c65_bf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_cf_y, "lat_bias2", "lat_bias2", 0);
  c65_cf_u = c65_ee_u.linkFeedback;
  c65_df_y = NULL;
  sf_mex_assign(&c65_df_y, sf_mex_create("y", &c65_cf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_df_y, "linkFeedback", "linkFeedback", 0);
  c65_df_u = c65_ee_u.RIO;
  c65_ef_y = NULL;
  sf_mex_assign(&c65_ef_y, sf_mex_create("y", &c65_df_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_ef_y, "RIO", "RIO", 0);
  c65_ef_u = c65_ee_u.SelectFeedforward;
  c65_ff_y = NULL;
  sf_mex_assign(&c65_ff_y, sf_mex_create("y", &c65_ef_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_ff_y, "SelectFeedforward", "SelectFeedforward",
                  0);
  for (c65_i89 = 0; c65_i89 < 6; c65_i89++) {
    c65_ff_u[c65_i89] = c65_ee_u.FeedforwardGain[c65_i89];
  }

  c65_gf_y = NULL;
  sf_mex_assign(&c65_gf_y, sf_mex_create("y", c65_ff_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c65_fe_y, c65_gf_y, "FeedforwardGain", "FeedforwardGain", 0);
  c65_gf_u = c65_ee_u.EnableFeedforwardOnStep;
  c65_hf_y = NULL;
  sf_mex_assign(&c65_hf_y, sf_mex_create("y", &c65_gf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_fe_y, c65_hf_y, "EnableFeedforwardOnStep",
                  "EnableFeedforwardOnStep", 0);
  sf_mex_addfield(c65_b_y, c65_fe_y, "Feedback", "Feedback", 0);
  c65_hf_u = c65_u.Saturation;
  c65_if_y = NULL;
  sf_mex_assign(&c65_if_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c65_if_u = c65_hf_u.UseQPSaturation;
  c65_jf_y = NULL;
  sf_mex_assign(&c65_jf_y, sf_mex_create("y", &c65_if_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_if_y, c65_jf_y, "UseQPSaturation", "UseQPSaturation", 0);
  for (c65_i90 = 0; c65_i90 < 2; c65_i90++) {
    c65_jf_u[c65_i90] = c65_hf_u.QPWeight[c65_i90];
  }

  c65_kf_y = NULL;
  sf_mex_assign(&c65_kf_y, sf_mex_create("y", c65_jf_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c65_if_y, c65_kf_y, "QPWeight", "QPWeight", 0);
  c65_kf_u = c65_hf_u.UseKASaturation;
  c65_lf_y = NULL;
  sf_mex_assign(&c65_lf_y, sf_mex_create("y", &c65_kf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_if_y, c65_lf_y, "UseKASaturation", "UseKASaturation", 0);
  c65_lf_u = c65_hf_u.KASaturationS1;
  c65_mf_y = NULL;
  sf_mex_assign(&c65_mf_y, sf_mex_create("y", &c65_lf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_if_y, c65_mf_y, "KASaturationS1", "KASaturationS1", 0);
  c65_mf_u = c65_hf_u.KASaturationS2;
  c65_nf_y = NULL;
  sf_mex_assign(&c65_nf_y, sf_mex_create("y", &c65_mf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_if_y, c65_nf_y, "KASaturationS2", "KASaturationS2", 0);
  c65_nf_u = c65_hf_u.KASaturationEarly;
  c65_of_y = NULL;
  sf_mex_assign(&c65_of_y, sf_mex_create("y", &c65_nf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_if_y, c65_of_y, "KASaturationEarly", "KASaturationEarly",
                  0);
  c65_of_u = c65_hf_u.KASaturationMax;
  c65_pf_y = NULL;
  sf_mex_assign(&c65_pf_y, sf_mex_create("y", &c65_of_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c65_if_y, c65_pf_y, "KASaturationMax", "KASaturationMax", 0);
  sf_mex_addfield(c65_b_y, c65_if_y, "Saturation", "Saturation", 0);
  sf_mex_assign(&c65_mxArrayOutData, c65_b_y, false);
  return c65_mxArrayOutData;
}

static const mxArray *c65_d_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData)
{
  const mxArray *c65_mxArrayOutData = NULL;
  c65_ControlStateBus c65_u;
  const mxArray *c65_b_y = NULL;
  real_T c65_b_u;
  const mxArray *c65_c_y = NULL;
  real_T c65_c_u;
  const mxArray *c65_d_y = NULL;
  real_T c65_d_u;
  const mxArray *c65_e_y = NULL;
  real_T c65_e_u;
  const mxArray *c65_f_y = NULL;
  real_T c65_f_u;
  const mxArray *c65_g_y = NULL;
  real_T c65_g_u;
  const mxArray *c65_h_y = NULL;
  real_T c65_h_u;
  const mxArray *c65_i_y = NULL;
  SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c65_mxArrayOutData = NULL;
  c65_u = *(c65_ControlStateBus *)c65_inData;
  c65_b_y = NULL;
  sf_mex_assign(&c65_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c65_b_u = c65_u.ControllerMode;
  c65_c_y = NULL;
  sf_mex_assign(&c65_c_y, sf_mex_create("y", &c65_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_b_y, c65_c_y, "ControllerMode", "ControllerMode", 0);
  c65_c_u = c65_u.SupportState;
  c65_d_y = NULL;
  sf_mex_assign(&c65_d_y, sf_mex_create("y", &c65_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_b_y, c65_d_y, "SupportState", "SupportState", 0);
  c65_d_u = c65_u.StanceLeg;
  c65_e_y = NULL;
  sf_mex_assign(&c65_e_y, sf_mex_create("y", &c65_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_b_y, c65_e_y, "StanceLeg", "StanceLeg", 0);
  c65_e_u = c65_u.InDoubleSupport;
  c65_f_y = NULL;
  sf_mex_assign(&c65_f_y, sf_mex_create("y", &c65_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_b_y, c65_f_y, "InDoubleSupport", "InDoubleSupport", 0);
  c65_f_u = c65_u.RollPhase;
  c65_g_y = NULL;
  sf_mex_assign(&c65_g_y, sf_mex_create("y", &c65_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_b_y, c65_g_y, "RollPhase", "RollPhase", 0);
  c65_g_u = c65_u.StepCount;
  c65_h_y = NULL;
  sf_mex_assign(&c65_h_y, sf_mex_create("y", &c65_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_b_y, c65_h_y, "StepCount", "StepCount", 0);
  c65_h_u = c65_u.Error;
  c65_i_y = NULL;
  sf_mex_assign(&c65_i_y, sf_mex_create("y", &c65_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c65_b_y, c65_i_y, "Error", "Error", 0);
  sf_mex_assign(&c65_mxArrayOutData, c65_b_y, false);
  return c65_mxArrayOutData;
}

static const mxArray *c65_e_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData)
{
  const mxArray *c65_mxArrayOutData = NULL;
  int32_T c65_i91;
  real_T c65_b_inData[6];
  int32_T c65_i92;
  real_T c65_u[6];
  const mxArray *c65_b_y = NULL;
  SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c65_mxArrayOutData = NULL;
  for (c65_i91 = 0; c65_i91 < 6; c65_i91++) {
    c65_b_inData[c65_i91] = (*(real_T (*)[6])c65_inData)[c65_i91];
  }

  for (c65_i92 = 0; c65_i92 < 6; c65_i92++) {
    c65_u[c65_i92] = c65_b_inData[c65_i92];
  }

  c65_b_y = NULL;
  sf_mex_assign(&c65_b_y, sf_mex_create("y", c65_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c65_mxArrayOutData, c65_b_y, false);
  return c65_mxArrayOutData;
}

static const mxArray *c65_f_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData)
{
  const mxArray *c65_mxArrayOutData = NULL;
  int32_T c65_i93;
  real_T c65_b_inData[2];
  int32_T c65_i94;
  real_T c65_u[2];
  const mxArray *c65_b_y = NULL;
  SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c65_mxArrayOutData = NULL;
  for (c65_i93 = 0; c65_i93 < 2; c65_i93++) {
    c65_b_inData[c65_i93] = (*(real_T (*)[2])c65_inData)[c65_i93];
  }

  for (c65_i94 = 0; c65_i94 < 2; c65_i94++) {
    c65_u[c65_i94] = c65_b_inData[c65_i94];
  }

  c65_b_y = NULL;
  sf_mex_assign(&c65_b_y, sf_mex_create("y", c65_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c65_mxArrayOutData, c65_b_y, false);
  return c65_mxArrayOutData;
}

const mxArray *sf_c65_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void)
{
  const mxArray *c65_nameCaptureInfo = NULL;
  c65_nameCaptureInfo = NULL;
  sf_mex_assign(&c65_nameCaptureInfo, sf_mex_createstruct("structure", 2, 26, 1),
                false);
  c65_info_helper(&c65_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c65_nameCaptureInfo);
  return c65_nameCaptureInfo;
}

static void c65_info_helper(const mxArray **c65_info)
{
  const mxArray *c65_rhs0 = NULL;
  const mxArray *c65_lhs0 = NULL;
  const mxArray *c65_rhs1 = NULL;
  const mxArray *c65_lhs1 = NULL;
  const mxArray *c65_rhs2 = NULL;
  const mxArray *c65_lhs2 = NULL;
  const mxArray *c65_rhs3 = NULL;
  const mxArray *c65_lhs3 = NULL;
  const mxArray *c65_rhs4 = NULL;
  const mxArray *c65_lhs4 = NULL;
  const mxArray *c65_rhs5 = NULL;
  const mxArray *c65_lhs5 = NULL;
  const mxArray *c65_rhs6 = NULL;
  const mxArray *c65_lhs6 = NULL;
  const mxArray *c65_rhs7 = NULL;
  const mxArray *c65_lhs7 = NULL;
  const mxArray *c65_rhs8 = NULL;
  const mxArray *c65_lhs8 = NULL;
  const mxArray *c65_rhs9 = NULL;
  const mxArray *c65_lhs9 = NULL;
  const mxArray *c65_rhs10 = NULL;
  const mxArray *c65_lhs10 = NULL;
  const mxArray *c65_rhs11 = NULL;
  const mxArray *c65_lhs11 = NULL;
  const mxArray *c65_rhs12 = NULL;
  const mxArray *c65_lhs12 = NULL;
  const mxArray *c65_rhs13 = NULL;
  const mxArray *c65_lhs13 = NULL;
  const mxArray *c65_rhs14 = NULL;
  const mxArray *c65_lhs14 = NULL;
  const mxArray *c65_rhs15 = NULL;
  const mxArray *c65_lhs15 = NULL;
  const mxArray *c65_rhs16 = NULL;
  const mxArray *c65_lhs16 = NULL;
  const mxArray *c65_rhs17 = NULL;
  const mxArray *c65_lhs17 = NULL;
  const mxArray *c65_rhs18 = NULL;
  const mxArray *c65_lhs18 = NULL;
  const mxArray *c65_rhs19 = NULL;
  const mxArray *c65_lhs19 = NULL;
  const mxArray *c65_rhs20 = NULL;
  const mxArray *c65_lhs20 = NULL;
  const mxArray *c65_rhs21 = NULL;
  const mxArray *c65_lhs21 = NULL;
  const mxArray *c65_rhs22 = NULL;
  const mxArray *c65_lhs22 = NULL;
  const mxArray *c65_rhs23 = NULL;
  const mxArray *c65_lhs23 = NULL;
  const mxArray *c65_rhs24 = NULL;
  const mxArray *c65_lhs24 = NULL;
  const mxArray *c65_rhs25 = NULL;
  const mxArray *c65_lhs25 = NULL;
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("all"), "name", "name", 0);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1372604014U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c65_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  1);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c65_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  2);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c65_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  3);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.allOrAny"),
                  "name", "name", 3);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1372604758U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c65_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c65_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("isequal"), "name", "name", 5);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1286840358U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c65_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 6);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c65_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 7);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c65_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("norm"), "name", "name", 8);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731868U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c65_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c65_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 10);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 10);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c65_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 11);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c65_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 12);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("abs"), "name", "name", 12);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c65_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c65_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 14);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c65_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 15);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("isnan"), "name", "name", 15);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c65_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c65_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/matfun/norm.m!genpnorm"),
                  "context", "context", 17);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 17);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1286840376U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c65_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 18);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c65_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(""), "context", "context", 19);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("mrdivide"), "name", "name",
                  19);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c65_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 20);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 20);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c65_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 21);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("rdivide"), "name", "name",
                  21);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c65_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 22);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c65_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 23);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c65_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("eml_div"), "name", "name",
                  24);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c65_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 25);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c65_info, c65_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c65_info, c65_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c65_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c65_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c65_info, sf_mex_duplicatearraysafe(&c65_lhs25), "lhs", "lhs",
                  25);
  sf_mex_destroy(&c65_rhs0);
  sf_mex_destroy(&c65_lhs0);
  sf_mex_destroy(&c65_rhs1);
  sf_mex_destroy(&c65_lhs1);
  sf_mex_destroy(&c65_rhs2);
  sf_mex_destroy(&c65_lhs2);
  sf_mex_destroy(&c65_rhs3);
  sf_mex_destroy(&c65_lhs3);
  sf_mex_destroy(&c65_rhs4);
  sf_mex_destroy(&c65_lhs4);
  sf_mex_destroy(&c65_rhs5);
  sf_mex_destroy(&c65_lhs5);
  sf_mex_destroy(&c65_rhs6);
  sf_mex_destroy(&c65_lhs6);
  sf_mex_destroy(&c65_rhs7);
  sf_mex_destroy(&c65_lhs7);
  sf_mex_destroy(&c65_rhs8);
  sf_mex_destroy(&c65_lhs8);
  sf_mex_destroy(&c65_rhs9);
  sf_mex_destroy(&c65_lhs9);
  sf_mex_destroy(&c65_rhs10);
  sf_mex_destroy(&c65_lhs10);
  sf_mex_destroy(&c65_rhs11);
  sf_mex_destroy(&c65_lhs11);
  sf_mex_destroy(&c65_rhs12);
  sf_mex_destroy(&c65_lhs12);
  sf_mex_destroy(&c65_rhs13);
  sf_mex_destroy(&c65_lhs13);
  sf_mex_destroy(&c65_rhs14);
  sf_mex_destroy(&c65_lhs14);
  sf_mex_destroy(&c65_rhs15);
  sf_mex_destroy(&c65_lhs15);
  sf_mex_destroy(&c65_rhs16);
  sf_mex_destroy(&c65_lhs16);
  sf_mex_destroy(&c65_rhs17);
  sf_mex_destroy(&c65_lhs17);
  sf_mex_destroy(&c65_rhs18);
  sf_mex_destroy(&c65_lhs18);
  sf_mex_destroy(&c65_rhs19);
  sf_mex_destroy(&c65_lhs19);
  sf_mex_destroy(&c65_rhs20);
  sf_mex_destroy(&c65_lhs20);
  sf_mex_destroy(&c65_rhs21);
  sf_mex_destroy(&c65_lhs21);
  sf_mex_destroy(&c65_rhs22);
  sf_mex_destroy(&c65_lhs22);
  sf_mex_destroy(&c65_rhs23);
  sf_mex_destroy(&c65_lhs23);
  sf_mex_destroy(&c65_rhs24);
  sf_mex_destroy(&c65_lhs24);
  sf_mex_destroy(&c65_rhs25);
  sf_mex_destroy(&c65_lhs25);
}

static const mxArray *c65_emlrt_marshallOut(const char * c65_u)
{
  const mxArray *c65_b_y = NULL;
  c65_b_y = NULL;
  sf_mex_assign(&c65_b_y, sf_mex_create("y", c65_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c65_u)), false);
  return c65_b_y;
}

static const mxArray *c65_b_emlrt_marshallOut(const uint32_T c65_u)
{
  const mxArray *c65_b_y = NULL;
  c65_b_y = NULL;
  sf_mex_assign(&c65_b_y, sf_mex_create("y", &c65_u, 7, 0U, 0U, 0U, 0), false);
  return c65_b_y;
}

static real_T c65_norm(SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c65_x[6])
{
  real_T c65_b_y;
  int32_T c65_k;
  real_T c65_b_k;
  real_T c65_b_x;
  real_T c65_c_x;
  real_T c65_absx;
  real_T c65_d_x;
  boolean_T c65_b;
  boolean_T exitg1;
  (void)chartInstance;
  c65_b_y = 0.0;
  c65_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c65_k < 6)) {
    c65_b_k = 1.0 + (real_T)c65_k;
    c65_b_x = c65_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", c65_b_k), 1, 6, 1, 0) - 1];
    c65_c_x = c65_b_x;
    c65_absx = muDoubleScalarAbs(c65_c_x);
    c65_d_x = c65_absx;
    c65_b = muDoubleScalarIsNaN(c65_d_x);
    if (c65_b) {
      c65_b_y = rtNaN;
      exitg1 = true;
    } else {
      if (c65_absx > c65_b_y) {
        c65_b_y = c65_absx;
      }

      c65_k++;
    }
  }

  return c65_b_y;
}

static const mxArray *c65_g_sf_marshallOut(void *chartInstanceVoid, void
  *c65_inData)
{
  const mxArray *c65_mxArrayOutData = NULL;
  int32_T c65_u;
  const mxArray *c65_b_y = NULL;
  SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c65_mxArrayOutData = NULL;
  c65_u = *(int32_T *)c65_inData;
  c65_b_y = NULL;
  sf_mex_assign(&c65_b_y, sf_mex_create("y", &c65_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c65_mxArrayOutData, c65_b_y, false);
  return c65_mxArrayOutData;
}

static int32_T c65_e_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId)
{
  int32_T c65_b_y;
  int32_T c65_i95;
  (void)chartInstance;
  sf_mex_import(c65_parentId, sf_mex_dup(c65_u), &c65_i95, 1, 6, 0U, 0, 0U, 0);
  c65_b_y = c65_i95;
  sf_mex_destroy(&c65_u);
  return c65_b_y;
}

static void c65_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c65_mxArrayInData, const char_T *c65_varName, void *c65_outData)
{
  const mxArray *c65_b_sfEvent;
  const char_T *c65_identifier;
  emlrtMsgIdentifier c65_thisId;
  int32_T c65_b_y;
  SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c65_b_sfEvent = sf_mex_dup(c65_mxArrayInData);
  c65_identifier = c65_varName;
  c65_thisId.fIdentifier = c65_identifier;
  c65_thisId.fParent = NULL;
  c65_b_y = c65_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c65_b_sfEvent),
    &c65_thisId);
  sf_mex_destroy(&c65_b_sfEvent);
  *(int32_T *)c65_outData = c65_b_y;
  sf_mex_destroy(&c65_mxArrayInData);
}

static const mxArray *c65_ControlState_bus_io(void *chartInstanceVoid, void
  *c65_pData)
{
  const mxArray *c65_mxVal = NULL;
  c65_ControlStateBus c65_tmp;
  SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c65_mxVal = NULL;
  c65_tmp.ControllerMode = *(real_T *)&((char_T *)(c65_ControlStateBus *)
    c65_pData)[0];
  c65_tmp.SupportState = *(real_T *)&((char_T *)(c65_ControlStateBus *)c65_pData)
    [8];
  c65_tmp.StanceLeg = *(real_T *)&((char_T *)(c65_ControlStateBus *)c65_pData)
    [16];
  c65_tmp.InDoubleSupport = *(real_T *)&((char_T *)(c65_ControlStateBus *)
    c65_pData)[24];
  c65_tmp.RollPhase = *(real_T *)&((char_T *)(c65_ControlStateBus *)c65_pData)
    [32];
  c65_tmp.StepCount = *(real_T *)&((char_T *)(c65_ControlStateBus *)c65_pData)
    [40];
  c65_tmp.Error = *(real_T *)&((char_T *)(c65_ControlStateBus *)c65_pData)[48];
  sf_mex_assign(&c65_mxVal, c65_d_sf_marshallOut(chartInstance, &c65_tmp), false);
  return c65_mxVal;
}

static const mxArray *c65_ControlParams_bus_io(void *chartInstanceVoid, void
  *c65_pData)
{
  const mxArray *c65_mxVal = NULL;
  c65_ControlParamsBus c65_tmp;
  int32_T c65_i96;
  int32_T c65_i97;
  int32_T c65_i98;
  int32_T c65_i99;
  int32_T c65_i100;
  int32_T c65_i101;
  int32_T c65_i102;
  int32_T c65_i103;
  int32_T c65_i104;
  int32_T c65_i105;
  int32_T c65_i106;
  int32_T c65_i107;
  int32_T c65_i108;
  int32_T c65_i109;
  int32_T c65_i110;
  int32_T c65_i111;
  int32_T c65_i112;
  int32_T c65_i113;
  int32_T c65_i114;
  int32_T c65_i115;
  int32_T c65_i116;
  int32_T c65_i117;
  int32_T c65_i118;
  int32_T c65_i119;
  int32_T c65_i120;
  int32_T c65_i121;
  int32_T c65_i122;
  int32_T c65_i123;
  int32_T c65_i124;
  int32_T c65_i125;
  int32_T c65_i126;
  int32_T c65_i127;
  int32_T c65_i128;
  int32_T c65_i129;
  int32_T c65_i130;
  int32_T c65_i131;
  int32_T c65_i132;
  int32_T c65_i133;
  int32_T c65_i134;
  int32_T c65_i135;
  int32_T c65_i136;
  int32_T c65_i137;
  int32_T c65_i138;
  int32_T c65_i139;
  int32_T c65_i140;
  int32_T c65_i141;
  int32_T c65_i142;
  int32_T c65_i143;
  SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c65_mxVal = NULL;
  c65_tmp.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [0];
  c65_tmp.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [8];
  c65_tmp.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [16];
  c65_tmp.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [24];
  c65_tmp.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [32];
  c65_tmp.Supervisory.ImpactThresholdKASpringRel = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [40];
  c65_tmp.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [48];
  c65_tmp.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [56];
  c65_tmp.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [64];
  c65_tmp.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [72];
  c65_tmp.Supervisory.TransitionThresholdTorsoVel = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [80];
  for (c65_i96 = 0; c65_i96 < 2; c65_i96++) {
    c65_tmp.Supervisory.KAInjection[c65_i96] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [0])[88])[c65_i96];
  }

  c65_tmp.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [104];
  c65_tmp.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [112];
  for (c65_i97 = 0; c65_i97 < 6; c65_i97++) {
    c65_tmp.Supervisory.VBLAParams[c65_i97] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [0])[120])[c65_i97];
  }

  for (c65_i98 = 0; c65_i98 < 13; c65_i98++) {
    c65_tmp.Supervisory.BalanceParams[c65_i98] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [0])[168])[c65_i98];
  }

  for (c65_i99 = 0; c65_i99 < 5; c65_i99++) {
    c65_tmp.Supervisory.GaitTweaks[c65_i99] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [0])[272])[c65_i99];
  }

  c65_tmp.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [312];
  c65_tmp.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [320];
  c65_tmp.Supervisory.RunMode = *(real_T *)&((char_T *)(c65_SupervisoryParamsBus
    *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])[328];
  c65_tmp.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [336];
  for (c65_i100 = 0; c65_i100 < 6; c65_i100++) {
    c65_tmp.Supervisory.ErrorZeroFactor[c65_i100] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [0])[344])[c65_i100];
  }

  for (c65_i101 = 0; c65_i101 < 6; c65_i101++) {
    c65_tmp.Supervisory.ErrorVelZeroFactor[c65_i101] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [0])[392])[c65_i101];
  }

  c65_tmp.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [440];
  c65_tmp.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [448];
  c65_tmp.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [456];
  c65_tmp.Supervisory.TPosing = *(real_T *)&((char_T *)(c65_SupervisoryParamsBus
    *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])[464];
  c65_tmp.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [472];
  c65_tmp.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [480];
  c65_tmp.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [488];
  c65_tmp.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [496];
  c65_tmp.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [504];
  c65_tmp.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [512];
  c65_tmp.Supervisory.VelocityControlTorsoGain = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [520];
  c65_tmp.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [528];
  c65_tmp.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [536];
  c65_tmp.Supervisory.Theta0 = *(real_T *)&((char_T *)(c65_SupervisoryParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[0])[544];
  c65_tmp.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [552];
  c65_tmp.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [560];
  c65_tmp.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [568];
  c65_tmp.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [576];
  c65_tmp.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [584];
  c65_tmp.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [592];
  c65_tmp.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [600];
  for (c65_i102 = 0; c65_i102 < 6; c65_i102++) {
    c65_tmp.Supervisory.K1MidStanceUpdate[c65_i102] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [0])[608])[c65_i102];
  }

  for (c65_i103 = 0; c65_i103 < 6; c65_i103++) {
    c65_tmp.Supervisory.K2MidStanceUpdate[c65_i103] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [0])[656])[c65_i103];
  }

  c65_tmp.Supervisory.EnableVelocityBasedUpdate = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [704];
  for (c65_i104 = 0; c65_i104 < 6; c65_i104++) {
    c65_tmp.Supervisory.VelocityBasedUpdateK1[c65_i104] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [0])[712])[c65_i104];
  }

  for (c65_i105 = 0; c65_i105 < 6; c65_i105++) {
    c65_tmp.Supervisory.VelocityBasedUpdateK2[c65_i105] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [0])[760])[c65_i105];
  }

  c65_tmp.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [808];
  c65_i106 = 0;
  for (c65_i107 = 0; c65_i107 < 2; c65_i107++) {
    for (c65_i108 = 0; c65_i108 < 6; c65_i108++) {
      c65_tmp.Supervisory.VelocityBasedUpdateLimits[c65_i108 + c65_i106] =
        ((real_T *)&((char_T *)(c65_SupervisoryParamsBus *)&((char_T *)
           (c65_ControlParamsBus *)c65_pData)[0])[816])[c65_i108 + c65_i106];
    }

    c65_i106 += 6;
  }

  c65_tmp.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [912];
  c65_tmp.Supervisory.dx_cmd = *(real_T *)&((char_T *)(c65_SupervisoryParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[0])[920];
  c65_tmp.Supervisory.ForBackward = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [928];
  c65_tmp.Supervisory.EnableFrictionID = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [936];
  c65_tmp.Supervisory.ResetFrictionPosing = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [944];
  c65_tmp.Supervisory.MoveLegIndex = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [952];
  c65_tmp.Supervisory.dy_cmd = *(real_T *)&((char_T *)(c65_SupervisoryParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[0])[960];
  c65_tmp.Supervisory.TauDelay = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [968];
  c65_tmp.Supervisory.TrackFrequency = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [976];
  c65_tmp.Supervisory.EnablePDControl = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [984];
  c65_tmp.Supervisory.TorqueAmp = *(real_T *)&((char_T *)
    (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[0])
    [992];
  for (c65_i109 = 0; c65_i109 < 6; c65_i109++) {
    c65_tmp.Supervisory.hdPosing[c65_i109] = ((real_T *)&((char_T *)
      (c65_SupervisoryParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [0])[1000])[c65_i109];
  }

  c65_tmp.Discrete.TLastUpdate = *(real_T *)&((char_T *)(c65_DiscreteParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[1048])[0];
  c65_tmp.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1048])
    [8];
  c65_tmp.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1048])
    [16];
  c65_tmp.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1048])
    [24];
  c65_tmp.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1048])
    [32];
  c65_tmp.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1048])
    [40];
  c65_tmp.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1048])
    [48];
  c65_tmp.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1048])
    [56];
  c65_tmp.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1048])
    [64];
  c65_tmp.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1048])
    [72];
  c65_tmp.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c65_DiscreteParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1048])
    [80];
  c65_i110 = 0;
  for (c65_i111 = 0; c65_i111 < 13; c65_i111++) {
    for (c65_i112 = 0; c65_i112 < 6; c65_i112++) {
      c65_tmp.Output.H0[c65_i112 + c65_i110] = ((real_T *)&((char_T *)
        (c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
        [1136])[0])[c65_i112 + c65_i110];
    }

    c65_i110 += 6;
  }

  c65_i113 = 0;
  for (c65_i114 = 0; c65_i114 < 6; c65_i114++) {
    for (c65_i115 = 0; c65_i115 < 6; c65_i115++) {
      c65_tmp.Output.HAlpha[c65_i115 + c65_i113] = ((real_T *)&((char_T *)
        (c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
        [1136])[624])[c65_i115 + c65_i113];
    }

    c65_i113 += 6;
  }

  for (c65_i116 = 0; c65_i116 < 2; c65_i116++) {
    c65_tmp.Output.ThetaLimits[c65_i116] = ((real_T *)&((char_T *)
      (c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1136])
      [912])[c65_i116];
  }

  c65_tmp.Output.Theta.c0 = *(real_T *)&((char_T *)(c65_ThetaParamsBus *)
    &((char_T *)(c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)
    c65_pData)[1136])[928])[0];
  c65_tmp.Output.Theta.ct = *(real_T *)&((char_T *)(c65_ThetaParamsBus *)
    &((char_T *)(c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)
    c65_pData)[1136])[928])[8];
  for (c65_i117 = 0; c65_i117 < 13; c65_i117++) {
    c65_tmp.Output.Theta.cq[c65_i117] = ((real_T *)&((char_T *)
      (c65_ThetaParamsBus *)&((char_T *)(c65_OutputParamsBus *)&((char_T *)
      (c65_ControlParamsBus *)c65_pData)[1136])[928])[16])[c65_i117];
  }

  c65_tmp.Output.Theta.t0 = *(real_T *)&((char_T *)(c65_ThetaParamsBus *)
    &((char_T *)(c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)
    c65_pData)[1136])[928])[120];
  for (c65_i118 = 0; c65_i118 < 7; c65_i118++) {
    c65_tmp.Output.Theta.cz[c65_i118] = ((real_T *)&((char_T *)
      (c65_ThetaParamsBus *)&((char_T *)(c65_OutputParamsBus *)&((char_T *)
      (c65_ControlParamsBus *)c65_pData)[1136])[928])[128])[c65_i118];
  }

  c65_tmp.Output.SaturateS = *(real_T *)&((char_T *)(c65_OutputParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[1136])[1112];
  for (c65_i119 = 0; c65_i119 < 2; c65_i119++) {
    c65_tmp.Output.SLimits[c65_i119] = ((real_T *)&((char_T *)
      (c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1136])
      [1120])[c65_i119];
  }

  c65_tmp.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1136])
    [1136];
  c65_tmp.Output.UseCorrection = *(real_T *)&((char_T *)(c65_OutputParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[1136])[1144];
  c65_tmp.Output.SMaxCorrection = *(real_T *)&((char_T *)(c65_OutputParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[1136])[1152];
  c65_i120 = 0;
  for (c65_i121 = 0; c65_i121 < 5; c65_i121++) {
    for (c65_i122 = 0; c65_i122 < 6; c65_i122++) {
      c65_tmp.Output.HAlphaCorrection[c65_i122 + c65_i120] = ((real_T *)
        &((char_T *)(c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)
        c65_pData)[1136])[1160])[c65_i122 + c65_i120];
    }

    c65_i120 += 6;
  }

  c65_tmp.Output.Phi.c0 = *(real_T *)&((char_T *)(c65_PhiParamsBus *)&((char_T *)
                                        (c65_OutputParamsBus *)&((char_T *)
    (c65_ControlParamsBus *)c65_pData)[1136])[1400])[0];
  for (c65_i123 = 0; c65_i123 < 13; c65_i123++) {
    c65_tmp.Output.Phi.cq[c65_i123] = ((real_T *)&((char_T *)(c65_PhiParamsBus *)
      &((char_T *)(c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)
      c65_pData)[1136])[1400])[8])[c65_i123];
  }

  for (c65_i124 = 0; c65_i124 < 20; c65_i124++) {
    c65_tmp.Output.PhiAlpha[c65_i124] = ((real_T *)&((char_T *)
      (c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1136])
      [1512])[c65_i124];
  }

  c65_tmp.Output.SaturateR = *(real_T *)&((char_T *)(c65_OutputParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[1136])[1672];
  for (c65_i125 = 0; c65_i125 < 2; c65_i125++) {
    c65_tmp.Output.RLimits[c65_i125] = ((real_T *)&((char_T *)
      (c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[1136])
      [1680])[c65_i125];
  }

  c65_i126 = 0;
  for (c65_i127 = 0; c65_i127 < 5; c65_i127++) {
    for (c65_i128 = 0; c65_i128 < 6; c65_i128++) {
      c65_tmp.Output.HBarAlpha[c65_i128 + c65_i126] = ((real_T *)&((char_T *)
        (c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
        [1136])[1696])[c65_i128 + c65_i126];
    }

    c65_i126 += 6;
  }

  c65_i129 = 0;
  for (c65_i130 = 0; c65_i130 < 2; c65_i130++) {
    for (c65_i131 = 0; c65_i131 < 6; c65_i131++) {
      c65_tmp.Output.HBarLimits[c65_i131 + c65_i129] = ((real_T *)&((char_T *)
        (c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
        [1136])[1936])[c65_i131 + c65_i129];
    }

    c65_i129 += 6;
  }

  c65_i132 = 0;
  for (c65_i133 = 0; c65_i133 < 6; c65_i133++) {
    for (c65_i134 = 0; c65_i134 < 6; c65_i134++) {
      c65_tmp.Output.HAlphaStar[c65_i134 + c65_i132] = ((real_T *)&((char_T *)
        (c65_OutputParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
        [1136])[2032])[c65_i134 + c65_i132];
    }

    c65_i132 += 6;
  }

  c65_tmp.Output.YawLimit = *(real_T *)&((char_T *)(c65_OutputParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[1136])[2320];
  c65_tmp.Output.test = *(real_T *)&((char_T *)(c65_OutputParamsBus *)&((char_T *)
                                      (c65_ControlParamsBus *)c65_pData)[1136])
    [2328];
  for (c65_i135 = 0; c65_i135 < 6; c65_i135++) {
    c65_tmp.Feedback.kp[c65_i135] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [3472])[0])[c65_i135];
  }

  for (c65_i136 = 0; c65_i136 < 6; c65_i136++) {
    c65_tmp.Feedback.kd[c65_i136] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [3472])[48])[c65_i136];
  }

  for (c65_i137 = 0; c65_i137 < 2; c65_i137++) {
    c65_tmp.Feedback.epsilon[c65_i137] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [3472])[96])[c65_i137];
  }

  for (c65_i138 = 0; c65_i138 < 2; c65_i138++) {
    c65_tmp.Feedback.kff_grav[c65_i138] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [3472])[112])[c65_i138];
  }

  c65_tmp.Feedback.delta_grav = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[128];
  for (c65_i139 = 0; c65_i139 < 2; c65_i139++) {
    c65_tmp.Feedback.kff_decoup[c65_i139] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [3472])[136])[c65_i139];
  }

  for (c65_i140 = 0; c65_i140 < 2; c65_i140++) {
    c65_tmp.Feedback.kd_torso[c65_i140] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [3472])[152])[c65_i140];
  }

  c65_tmp.Feedback.kp_2dof = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[168];
  c65_tmp.Feedback.kd_2dof = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[176];
  c65_tmp.Feedback.kpre_2dof = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[184];
  c65_tmp.Feedback.kp_lat = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[192];
  c65_tmp.Feedback.kd_lat = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[200];
  c65_tmp.Feedback.q3d_min_lat = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[208];
  c65_tmp.Feedback.q3d_max_lat = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[216];
  c65_tmp.Feedback.w_torso_lat = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[224];
  for (c65_i141 = 0; c65_i141 < 6; c65_i141++) {
    c65_tmp.Feedback.u_ff[c65_i141] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [3472])[232])[c65_i141];
  }

  c65_tmp.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])
    [280];
  c65_tmp.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])
    [288];
  c65_tmp.Feedback.Use2DOF = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[296];
  c65_tmp.Feedback.UseDSGravComp = *(real_T *)&((char_T *)(c65_FeedbackParamsBus
    *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[304];
  c65_tmp.Feedback.lat_bias = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[312];
  c65_tmp.Feedback.lat_bias2 = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[320];
  c65_tmp.Feedback.linkFeedback = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[328];
  c65_tmp.Feedback.RIO = *(real_T *)&((char_T *)(c65_FeedbackParamsBus *)
    &((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])[336];
  c65_tmp.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])
    [344];
  for (c65_i142 = 0; c65_i142 < 6; c65_i142++) {
    c65_tmp.Feedback.FeedforwardGain[c65_i142] = ((real_T *)&((char_T *)
      (c65_FeedbackParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [3472])[352])[c65_i142];
  }

  c65_tmp.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c65_FeedbackParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)[3472])
    [400];
  c65_tmp.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c65_SaturationParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
    [3880])[0];
  for (c65_i143 = 0; c65_i143 < 2; c65_i143++) {
    c65_tmp.Saturation.QPWeight[c65_i143] = ((real_T *)&((char_T *)
      (c65_SaturationParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
      [3880])[8])[c65_i143];
  }

  c65_tmp.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c65_SaturationParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
    [3880])[24];
  c65_tmp.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c65_SaturationParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
    [3880])[32];
  c65_tmp.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c65_SaturationParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
    [3880])[40];
  c65_tmp.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c65_SaturationParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
    [3880])[48];
  c65_tmp.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c65_SaturationParamsBus *)&((char_T *)(c65_ControlParamsBus *)c65_pData)
    [3880])[56];
  sf_mex_assign(&c65_mxVal, c65_c_sf_marshallOut(chartInstance, &c65_tmp), false);
  return c65_mxVal;
}

static uint8_T c65_f_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_b_is_active_c65_DDA2D_OSU3Dv2, const char_T
  *c65_identifier)
{
  uint8_T c65_b_y;
  emlrtMsgIdentifier c65_thisId;
  c65_thisId.fIdentifier = c65_identifier;
  c65_thisId.fParent = NULL;
  c65_b_y = c65_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c65_b_is_active_c65_DDA2D_OSU3Dv2), &c65_thisId);
  sf_mex_destroy(&c65_b_is_active_c65_DDA2D_OSU3Dv2);
  return c65_b_y;
}

static uint8_T c65_g_emlrt_marshallIn(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c65_u, const emlrtMsgIdentifier *c65_parentId)
{
  uint8_T c65_b_y;
  uint8_T c65_u0;
  (void)chartInstance;
  sf_mex_import(c65_parentId, sf_mex_dup(c65_u), &c65_u0, 1, 3, 0U, 0, 0U, 0);
  c65_b_y = c65_u0;
  sf_mex_destroy(&c65_u);
  return c65_b_y;
}

static void init_dsm_address_info(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc65_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c65_TorqueSaturationLimits = (real_T (*)[2])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c65_y = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c65_dy = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c65_s = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    3);
  chartInstance->c65_Error = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c65_ControlState = (c65_ControlStateBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 4);
  chartInstance->c65_ControlParams = (c65_ControlParamsBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 5);
  chartInstance->c65_ErrorCount = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c65_ErrorCountIn = (real_T *)ssGetInputPortSignal_wrapper
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

void sf_c65_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1750671132U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2494488784U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1444020959U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(662866265U);
}

mxArray* sf_c65_DDA2D_OSU3Dv2_get_post_codegen_info(void);
mxArray *sf_c65_DDA2D_OSU3Dv2_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c65_DDA2D_OSU3Dv2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c65_DDA2D_OSU3Dv2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c65_DDA2D_OSU3Dv2_jit_fallback_info(void)
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

mxArray *sf_c65_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c65_DDA2D_OSU3Dv2_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c65_DDA2D_OSU3Dv2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[5],T\"Error\",},{M[1],M[13],T\"ErrorCount\",},{M[8],M[0],T\"is_active_c65_DDA2D_OSU3Dv2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c65_DDA2D_OSU3Dv2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DDA2D_OSU3Dv2MachineNumber_,
           65,
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
        init_script_number_translation(_DDA2D_OSU3Dv2MachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_DDA2D_OSU3Dv2MachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _DDA2D_OSU3Dv2MachineNumber_,
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
            1.0,0,0,(MexFcnForType)c65_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c65_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c65_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_b_sf_marshallOut,(MexInFcnForType)
          c65_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_ControlState_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_ControlParams_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_sf_marshallOut,(MexInFcnForType)c65_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c65_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c65_TorqueSaturationLimits);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c65_y);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c65_dy);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c65_s);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c65_Error);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c65_ControlState);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c65_ControlParams);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c65_ErrorCount);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c65_ErrorCountIn);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _DDA2D_OSU3Dv2MachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "LpmaMG19KJccs1xh1NGlXH";
}

static void sf_opaque_initialize_c65_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc65_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c65_DDA2D_OSU3Dv2((SFc65_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
  initialize_c65_DDA2D_OSU3Dv2((SFc65_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c65_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  enable_c65_DDA2D_OSU3Dv2((SFc65_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c65_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  disable_c65_DDA2D_OSU3Dv2((SFc65_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c65_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  sf_gateway_c65_DDA2D_OSU3Dv2((SFc65_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c65_DDA2D_OSU3Dv2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c65_DDA2D_OSU3Dv2((SFc65_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c65_DDA2D_OSU3Dv2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c65_DDA2D_OSU3Dv2((SFc65_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c65_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc65_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DDA2D_OSU3Dv2_optimization_info();
    }

    finalize_c65_DDA2D_OSU3Dv2((SFc65_DDA2D_OSU3Dv2InstanceStruct*)
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
  initSimStructsc65_DDA2D_OSU3Dv2((SFc65_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c65_DDA2D_OSU3Dv2(SimStruct *S)
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
    initialize_params_c65_DDA2D_OSU3Dv2((SFc65_DDA2D_OSU3Dv2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c65_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DDA2D_OSU3Dv2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      65);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,65,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,65,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,65);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,65,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,65,2);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,65);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4181476121U));
  ssSetChecksum1(S,(2088264091U));
  ssSetChecksum2(S,(716497670U));
  ssSetChecksum3(S,(3099551960U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c65_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c65_DDA2D_OSU3Dv2(SimStruct *S)
{
  SFc65_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc65_DDA2D_OSU3Dv2InstanceStruct *)utMalloc(sizeof
    (SFc65_DDA2D_OSU3Dv2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc65_DDA2D_OSU3Dv2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c65_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c65_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c65_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c65_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c65_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c65_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c65_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c65_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c65_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlStart = mdlStart_c65_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c65_DDA2D_OSU3Dv2;
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

void c65_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c65_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c65_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c65_DDA2D_OSU3Dv2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c65_DDA2D_OSU3Dv2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
