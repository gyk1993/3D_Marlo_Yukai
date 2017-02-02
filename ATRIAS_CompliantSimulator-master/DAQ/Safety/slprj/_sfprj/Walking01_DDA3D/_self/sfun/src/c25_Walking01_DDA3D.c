/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_DDA3D_sfun.h"
#include "c25_Walking01_DDA3D.h"
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
static const char * c25_debug_family_names[29] = { "leg_motor_1R_torque_cmd",
  "leg_motor_2R_torque_cmd", "hip_motor_3R_torque_cmd",
  "leg_motor_1L_torque_cmd", "leg_motor_2L_torque_cmd",
  "hip_motor_3L_torque_cmd", "UMich_LEFT_MOTOR_HIP_DIRECTION",
  "UMich_RIGHT_MOTOR_HIP_DIRECTION", "MTR_MAX_COUNT", "MTR_MAX_TORQUE",
  "MTR_HIP_MAX_TORQUE", "LEG3_MOTOR_A_DIRECTION", "LEG3_MOTOR_B_DIRECTION",
  "LEG4_MOTOR_A_DIRECTION", "LEG4_MOTOR_B_DIRECTION", "leg_torque_to_pwm",
  "hip_torque_to_pwm", "leg_motor_1L_direction", "leg_motor_2L_direction",
  "leg_motor_1R_direction", "leg_motor_2R_direction", "hip_motor_3R_direction",
  "hip_motor_3L_direction", "nargin", "nargout", "params", "u", "Reset", "y" };

static const char * c25_b_debug_family_names[6] = { "nargin", "nargout",
  "motor_direction", "torque_to_pwm_const", "motor_torque_cmd", "motor_pwm" };

/* Function Declarations */
static void initialize_c25_Walking01_DDA3D(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initialize_params_c25_Walking01_DDA3D
  (SFc25_Walking01_DDA3DInstanceStruct *chartInstance);
static void enable_c25_Walking01_DDA3D(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void disable_c25_Walking01_DDA3D(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c25_update_debugger_state_c25_Walking01_DDA3D
  (SFc25_Walking01_DDA3DInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c25_Walking01_DDA3D
  (SFc25_Walking01_DDA3DInstanceStruct *chartInstance);
static void set_sim_state_c25_Walking01_DDA3D
  (SFc25_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c25_st);
static void finalize_c25_Walking01_DDA3D(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void sf_gateway_c25_Walking01_DDA3D(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void mdl_start_c25_Walking01_DDA3D(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c25_chartstep_c25_Walking01_DDA3D
  (SFc25_Walking01_DDA3DInstanceStruct *chartInstance);
static void initSimStructsc25_Walking01_DDA3D
  (SFc25_Walking01_DDA3DInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber, uint32_T c25_instanceNumber);
static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static void c25_emlrt_marshallIn(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c25_b_y, const char_T *c25_identifier, real_T
  c25_c_y[6]);
static void c25_b_emlrt_marshallIn(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c25_b_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_b_y[6]);
static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static const mxArray *c25_c_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static const mxArray *c25_d_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static real_T c25_c_emlrt_marshallIn(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c25_b_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static void c25_info_helper(const mxArray **c25_info);
static const mxArray *c25_emlrt_marshallOut(const char * c25_b_u);
static const mxArray *c25_b_emlrt_marshallOut(const uint32_T c25_b_u);
static const mxArray *c25_e_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData);
static int32_T c25_d_emlrt_marshallIn(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c25_b_u, const emlrtMsgIdentifier *c25_parentId);
static void c25_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData);
static uint8_T c25_e_emlrt_marshallIn(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c25_b_is_active_c25_Walking01_DDA3D, const
  char_T *c25_identifier);
static uint8_T c25_f_emlrt_marshallIn(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c25_b_u, const emlrtMsgIdentifier *c25_parentId);
static void init_dsm_address_info(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c25_Walking01_DDA3D(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c25_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c25_is_active_c25_Walking01_DDA3D = 0U;
}

static void initialize_params_c25_Walking01_DDA3D
  (SFc25_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c25_Walking01_DDA3D(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c25_Walking01_DDA3D(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c25_update_debugger_state_c25_Walking01_DDA3D
  (SFc25_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c25_Walking01_DDA3D
  (SFc25_Walking01_DDA3DInstanceStruct *chartInstance)
{
  const mxArray *c25_st;
  const mxArray *c25_b_y = NULL;
  int32_T c25_i0;
  real_T c25_b_u[6];
  const mxArray *c25_c_y = NULL;
  uint8_T c25_hoistedGlobal;
  uint8_T c25_c_u;
  const mxArray *c25_d_y = NULL;
  c25_st = NULL;
  c25_st = NULL;
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_createcellmatrix(2, 1), false);
  for (c25_i0 = 0; c25_i0 < 6; c25_i0++) {
    c25_b_u[c25_i0] = (*chartInstance->c25_y)[c25_i0];
  }

  c25_c_y = NULL;
  sf_mex_assign(&c25_c_y, sf_mex_create("y", c25_b_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_setcell(c25_b_y, 0, c25_c_y);
  c25_hoistedGlobal = chartInstance->c25_is_active_c25_Walking01_DDA3D;
  c25_c_u = c25_hoistedGlobal;
  c25_d_y = NULL;
  sf_mex_assign(&c25_d_y, sf_mex_create("y", &c25_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c25_b_y, 1, c25_d_y);
  sf_mex_assign(&c25_st, c25_b_y, false);
  return c25_st;
}

static void set_sim_state_c25_Walking01_DDA3D
  (SFc25_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c25_st)
{
  const mxArray *c25_b_u;
  real_T c25_dv0[6];
  int32_T c25_i1;
  chartInstance->c25_doneDoubleBufferReInit = true;
  c25_b_u = sf_mex_dup(c25_st);
  c25_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c25_b_u, 0)),
                       "y", c25_dv0);
  for (c25_i1 = 0; c25_i1 < 6; c25_i1++) {
    (*chartInstance->c25_y)[c25_i1] = c25_dv0[c25_i1];
  }

  chartInstance->c25_is_active_c25_Walking01_DDA3D = c25_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c25_b_u, 1)),
     "is_active_c25_Walking01_DDA3D");
  sf_mex_destroy(&c25_b_u);
  c25_update_debugger_state_c25_Walking01_DDA3D(chartInstance);
  sf_mex_destroy(&c25_st);
}

static void finalize_c25_Walking01_DDA3D(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c25_Walking01_DDA3D(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  int32_T c25_i2;
  int32_T c25_i3;
  int32_T c25_i4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 19U, chartInstance->c25_sfEvent);
  for (c25_i2 = 0; c25_i2 < 9; c25_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_params)[c25_i2], 0U);
  }

  for (c25_i3 = 0; c25_i3 < 6; c25_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_u)[c25_i3], 1U);
  }

  chartInstance->c25_sfEvent = CALL_EVENT;
  c25_chartstep_c25_Walking01_DDA3D(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_DDA3DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c25_i4 = 0; c25_i4 < 6; c25_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c25_y)[c25_i4], 2U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c25_Reset, 3U);
}

static void mdl_start_c25_Walking01_DDA3D(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c25_chartstep_c25_Walking01_DDA3D
  (SFc25_Walking01_DDA3DInstanceStruct *chartInstance)
{
  boolean_T c25_hoistedGlobal;
  int32_T c25_i5;
  real_T c25_b_params[9];
  int32_T c25_i6;
  real_T c25_b_u[6];
  boolean_T c25_b_Reset;
  uint32_T c25_debug_family_var_map[29];
  real_T c25_leg_motor_1R_torque_cmd;
  real_T c25_leg_motor_2R_torque_cmd;
  real_T c25_hip_motor_3R_torque_cmd;
  real_T c25_leg_motor_1L_torque_cmd;
  real_T c25_leg_motor_2L_torque_cmd;
  real_T c25_hip_motor_3L_torque_cmd;
  real_T c25_UMich_LEFT_MOTOR_HIP_DIRECTION;
  real_T c25_UMich_RIGHT_MOTOR_HIP_DIRECTION;
  real_T c25_MTR_MAX_COUNT;
  real_T c25_MTR_MAX_TORQUE;
  real_T c25_MTR_HIP_MAX_TORQUE;
  real_T c25_LEG3_MOTOR_A_DIRECTION;
  real_T c25_LEG3_MOTOR_B_DIRECTION;
  real_T c25_LEG4_MOTOR_A_DIRECTION;
  real_T c25_LEG4_MOTOR_B_DIRECTION;
  real_T c25_leg_torque_to_pwm;
  real_T c25_hip_torque_to_pwm;
  real_T c25_leg_motor_1L_direction;
  real_T c25_leg_motor_2L_direction;
  real_T c25_leg_motor_1R_direction;
  real_T c25_leg_motor_2R_direction;
  real_T c25_hip_motor_3R_direction;
  real_T c25_hip_motor_3L_direction;
  real_T c25_nargin = 3.0;
  real_T c25_nargout = 1.0;
  real_T c25_b_y[6];
  int32_T c25_i7;
  real_T c25_A;
  real_T c25_B;
  real_T c25_x;
  real_T c25_c_y;
  real_T c25_b_x;
  real_T c25_d_y;
  real_T c25_c_x;
  real_T c25_e_y;
  real_T c25_b_A;
  real_T c25_b_B;
  real_T c25_d_x;
  real_T c25_f_y;
  real_T c25_e_x;
  real_T c25_g_y;
  real_T c25_f_x;
  real_T c25_h_y;
  real_T c25_motor_direction;
  real_T c25_torque_to_pwm_const;
  real_T c25_motor_torque_cmd;
  uint32_T c25_b_debug_family_var_map[6];
  real_T c25_b_nargin = 3.0;
  real_T c25_b_nargout = 1.0;
  real_T c25_motor_pwm;
  real_T c25_b_motor_direction;
  real_T c25_b_torque_to_pwm_const;
  real_T c25_b_motor_torque_cmd;
  real_T c25_c_nargin = 3.0;
  real_T c25_c_nargout = 1.0;
  real_T c25_b_motor_pwm;
  real_T c25_c_motor_direction;
  real_T c25_c_torque_to_pwm_const;
  real_T c25_c_motor_torque_cmd;
  real_T c25_d_nargin = 3.0;
  real_T c25_d_nargout = 1.0;
  real_T c25_c_motor_pwm;
  real_T c25_d_motor_direction;
  real_T c25_d_torque_to_pwm_const;
  real_T c25_d_motor_torque_cmd;
  real_T c25_e_nargin = 3.0;
  real_T c25_e_nargout = 1.0;
  real_T c25_d_motor_pwm;
  real_T c25_e_motor_direction;
  real_T c25_e_torque_to_pwm_const;
  real_T c25_e_motor_torque_cmd;
  real_T c25_f_nargin = 3.0;
  real_T c25_f_nargout = 1.0;
  real_T c25_e_motor_pwm;
  real_T c25_f_motor_direction;
  real_T c25_f_torque_to_pwm_const;
  real_T c25_f_motor_torque_cmd;
  real_T c25_g_nargin = 3.0;
  real_T c25_g_nargout = 1.0;
  real_T c25_f_motor_pwm;
  int32_T c25_i8;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 19U, chartInstance->c25_sfEvent);
  c25_hoistedGlobal = *chartInstance->c25_Reset;
  for (c25_i5 = 0; c25_i5 < 9; c25_i5++) {
    c25_b_params[c25_i5] = (*chartInstance->c25_params)[c25_i5];
  }

  for (c25_i6 = 0; c25_i6 < 6; c25_i6++) {
    c25_b_u[c25_i6] = (*chartInstance->c25_u)[c25_i6];
  }

  c25_b_Reset = c25_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 29U, 29U, c25_debug_family_names,
    c25_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_leg_motor_1R_torque_cmd, 0U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_leg_motor_2R_torque_cmd, 1U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_hip_motor_3R_torque_cmd, 2U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_leg_motor_1L_torque_cmd, 3U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_leg_motor_2L_torque_cmd, 4U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_hip_motor_3L_torque_cmd, 5U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_UMich_LEFT_MOTOR_HIP_DIRECTION, 6U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_UMich_RIGHT_MOTOR_HIP_DIRECTION, 7U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_MTR_MAX_COUNT, 8U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_MTR_MAX_TORQUE, 9U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_MTR_HIP_MAX_TORQUE, 10U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_LEG3_MOTOR_A_DIRECTION, 11U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_LEG3_MOTOR_B_DIRECTION, 12U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_LEG4_MOTOR_A_DIRECTION, 13U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_LEG4_MOTOR_B_DIRECTION, 14U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_leg_torque_to_pwm, 15U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_hip_torque_to_pwm, 16U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_leg_motor_1L_direction, 17U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_leg_motor_2L_direction, 18U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_leg_motor_1R_direction, 19U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_leg_motor_2R_direction, 20U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_hip_motor_3R_direction, 21U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_hip_motor_3L_direction, 22U,
    c25_d_sf_marshallOut, c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_nargin, 23U, c25_d_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_nargout, 24U, c25_d_sf_marshallOut,
    c25_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_b_params, 25U, c25_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c25_b_u, 26U, c25_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c25_b_Reset, 27U, c25_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c25_b_y, 28U, c25_sf_marshallOut,
    c25_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 6);
  for (c25_i7 = 0; c25_i7 < 6; c25_i7++) {
    c25_b_y[c25_i7] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 8);
  if (CV_EML_IF(0, 1, 0, c25_b_Reset)) {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 9);
  } else {
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 13);
    c25_leg_motor_1R_torque_cmd = c25_b_u[0];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 14);
    c25_leg_motor_2R_torque_cmd = c25_b_u[1];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 15);
    c25_hip_motor_3R_torque_cmd = c25_b_u[2];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 16);
    c25_leg_motor_1L_torque_cmd = c25_b_u[3];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 17);
    c25_leg_motor_2L_torque_cmd = c25_b_u[4];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 18);
    c25_hip_motor_3L_torque_cmd = c25_b_u[5];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 21);
    c25_UMich_LEFT_MOTOR_HIP_DIRECTION = c25_b_params[0];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 22);
    c25_UMich_RIGHT_MOTOR_HIP_DIRECTION = c25_b_params[1];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 26);
    c25_MTR_MAX_COUNT = c25_b_params[2];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 28);
    c25_MTR_MAX_TORQUE = c25_b_params[3];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 29);
    c25_MTR_HIP_MAX_TORQUE = c25_b_params[4];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 32);
    c25_LEG3_MOTOR_A_DIRECTION = c25_b_params[5];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 33);
    c25_LEG3_MOTOR_B_DIRECTION = c25_b_params[6];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 36);
    c25_LEG4_MOTOR_A_DIRECTION = c25_b_params[7];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 37);
    c25_LEG4_MOTOR_B_DIRECTION = c25_b_params[8];
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 39);
    c25_A = c25_MTR_MAX_COUNT;
    c25_B = c25_MTR_MAX_TORQUE;
    c25_x = c25_A;
    c25_c_y = c25_B;
    c25_b_x = c25_x;
    c25_d_y = c25_c_y;
    c25_c_x = c25_b_x;
    c25_e_y = c25_d_y;
    c25_leg_torque_to_pwm = c25_c_x / c25_e_y;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 40);
    c25_b_A = c25_MTR_MAX_COUNT;
    c25_b_B = c25_MTR_HIP_MAX_TORQUE;
    c25_d_x = c25_b_A;
    c25_f_y = c25_b_B;
    c25_e_x = c25_d_x;
    c25_g_y = c25_f_y;
    c25_f_x = c25_e_x;
    c25_h_y = c25_g_y;
    c25_hip_torque_to_pwm = c25_f_x / c25_h_y;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 43);
    c25_leg_motor_1L_direction = c25_LEG3_MOTOR_A_DIRECTION;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 44);
    c25_motor_direction = c25_leg_motor_1L_direction;
    c25_torque_to_pwm_const = c25_leg_torque_to_pwm;
    c25_motor_torque_cmd = c25_leg_motor_1L_torque_cmd;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c25_b_debug_family_names,
      c25_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_b_nargin, 0U, c25_d_sf_marshallOut,
      c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_b_nargout, 1U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_motor_direction, 2U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_torque_to_pwm_const, 3U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_motor_torque_cmd, 4U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_motor_pwm, 5U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 69);
    c25_motor_pwm = c25_motor_direction * c25_torque_to_pwm_const
      * c25_motor_torque_cmd;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, -69);
    _SFD_SYMBOL_SCOPE_POP();
    c25_b_y[0] = c25_motor_pwm;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 47);
    c25_leg_motor_2L_direction = c25_LEG3_MOTOR_B_DIRECTION;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 48);
    c25_b_motor_direction = c25_leg_motor_2L_direction;
    c25_b_torque_to_pwm_const = c25_leg_torque_to_pwm;
    c25_b_motor_torque_cmd = c25_leg_motor_2L_torque_cmd;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c25_b_debug_family_names,
      c25_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_c_nargin, 0U, c25_d_sf_marshallOut,
      c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_c_nargout, 1U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_b_motor_direction, 2U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_b_torque_to_pwm_const, 3U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_b_motor_torque_cmd, 4U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_b_motor_pwm, 5U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 69);
    c25_b_motor_pwm = c25_b_motor_direction * c25_b_torque_to_pwm_const
      * c25_b_motor_torque_cmd;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, -69);
    _SFD_SYMBOL_SCOPE_POP();
    c25_b_y[1] = c25_b_motor_pwm;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 51);
    c25_leg_motor_1R_direction = c25_LEG4_MOTOR_A_DIRECTION;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 52);
    c25_c_motor_direction = c25_leg_motor_1R_direction;
    c25_c_torque_to_pwm_const = c25_leg_torque_to_pwm;
    c25_c_motor_torque_cmd = c25_leg_motor_1R_torque_cmd;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c25_b_debug_family_names,
      c25_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_d_nargin, 0U, c25_d_sf_marshallOut,
      c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_d_nargout, 1U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_c_motor_direction, 2U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_c_torque_to_pwm_const, 3U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_c_motor_torque_cmd, 4U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_c_motor_pwm, 5U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 69);
    c25_c_motor_pwm = c25_c_motor_direction * c25_c_torque_to_pwm_const
      * c25_c_motor_torque_cmd;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, -69);
    _SFD_SYMBOL_SCOPE_POP();
    c25_b_y[2] = c25_c_motor_pwm;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 55);
    c25_leg_motor_2R_direction = c25_LEG4_MOTOR_B_DIRECTION;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 56);
    c25_d_motor_direction = c25_leg_motor_2R_direction;
    c25_d_torque_to_pwm_const = c25_leg_torque_to_pwm;
    c25_d_motor_torque_cmd = c25_leg_motor_2R_torque_cmd;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c25_b_debug_family_names,
      c25_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_e_nargin, 0U, c25_d_sf_marshallOut,
      c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_e_nargout, 1U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_d_motor_direction, 2U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_d_torque_to_pwm_const, 3U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_d_motor_torque_cmd, 4U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_d_motor_pwm, 5U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 69);
    c25_d_motor_pwm = c25_d_motor_direction * c25_d_torque_to_pwm_const
      * c25_d_motor_torque_cmd;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, -69);
    _SFD_SYMBOL_SCOPE_POP();
    c25_b_y[3] = c25_d_motor_pwm;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 59);
    c25_hip_motor_3R_direction = c25_UMich_RIGHT_MOTOR_HIP_DIRECTION;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 60);
    c25_e_motor_direction = c25_hip_motor_3R_direction;
    c25_e_torque_to_pwm_const = c25_hip_torque_to_pwm;
    c25_e_motor_torque_cmd = c25_hip_motor_3R_torque_cmd;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c25_b_debug_family_names,
      c25_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_f_nargin, 0U, c25_d_sf_marshallOut,
      c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_f_nargout, 1U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_e_motor_direction, 2U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_e_torque_to_pwm_const, 3U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_e_motor_torque_cmd, 4U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_e_motor_pwm, 5U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 69);
    c25_e_motor_pwm = c25_e_motor_direction * c25_e_torque_to_pwm_const
      * c25_e_motor_torque_cmd;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, -69);
    _SFD_SYMBOL_SCOPE_POP();
    c25_b_y[4] = c25_e_motor_pwm;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 63);
    c25_hip_motor_3L_direction = c25_UMich_LEFT_MOTOR_HIP_DIRECTION;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 64);
    c25_f_motor_direction = c25_hip_motor_3L_direction;
    c25_f_torque_to_pwm_const = c25_hip_torque_to_pwm;
    c25_f_motor_torque_cmd = c25_hip_motor_3L_torque_cmd;
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c25_b_debug_family_names,
      c25_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_g_nargin, 0U, c25_d_sf_marshallOut,
      c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_g_nargout, 1U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_f_motor_direction, 2U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_f_torque_to_pwm_const, 3U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_f_motor_torque_cmd, 4U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c25_f_motor_pwm, 5U,
      c25_d_sf_marshallOut, c25_b_sf_marshallIn);
    CV_EML_FCN(0, 1);
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, 69);
    c25_f_motor_pwm = c25_f_motor_direction * c25_f_torque_to_pwm_const
      * c25_f_motor_torque_cmd;
    _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, -69);
    _SFD_SYMBOL_SCOPE_POP();
    c25_b_y[5] = c25_f_motor_pwm;
  }

  _SFD_EML_CALL(0U, chartInstance->c25_sfEvent, -64);
  _SFD_SYMBOL_SCOPE_POP();
  for (c25_i8 = 0; c25_i8 < 6; c25_i8++) {
    (*chartInstance->c25_y)[c25_i8] = c25_b_y[c25_i8];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 19U, chartInstance->c25_sfEvent);
}

static void initSimStructsc25_Walking01_DDA3D
  (SFc25_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c25_machineNumber, uint32_T
  c25_chartNumber, uint32_T c25_instanceNumber)
{
  (void)c25_machineNumber;
  (void)c25_chartNumber;
  (void)c25_instanceNumber;
}

static const mxArray *c25_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i9;
  real_T c25_b_inData[6];
  int32_T c25_i10;
  real_T c25_b_u[6];
  const mxArray *c25_b_y = NULL;
  SFc25_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc25_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  for (c25_i9 = 0; c25_i9 < 6; c25_i9++) {
    c25_b_inData[c25_i9] = (*(real_T (*)[6])c25_inData)[c25_i9];
  }

  for (c25_i10 = 0; c25_i10 < 6; c25_i10++) {
    c25_b_u[c25_i10] = c25_b_inData[c25_i10];
  }

  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", c25_b_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_assign(&c25_mxArrayOutData, c25_b_y, false);
  return c25_mxArrayOutData;
}

static void c25_emlrt_marshallIn(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c25_b_y, const char_T *c25_identifier, real_T
  c25_c_y[6])
{
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_y), &c25_thisId,
    c25_c_y);
  sf_mex_destroy(&c25_b_y);
}

static void c25_b_emlrt_marshallIn(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c25_b_u, const emlrtMsgIdentifier *c25_parentId,
  real_T c25_b_y[6])
{
  real_T c25_dv1[6];
  int32_T c25_i11;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_b_u), c25_dv1, 1, 0, 0U, 1, 0U, 1,
                6);
  for (c25_i11 = 0; c25_i11 < 6; c25_i11++) {
    c25_b_y[c25_i11] = c25_dv1[c25_i11];
  }

  sf_mex_destroy(&c25_b_u);
}

static void c25_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_y;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_c_y[6];
  int32_T c25_i12;
  SFc25_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc25_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c25_b_y = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_y), &c25_thisId,
    c25_c_y);
  sf_mex_destroy(&c25_b_y);
  for (c25_i12 = 0; c25_i12 < 6; c25_i12++) {
    (*(real_T (*)[6])c25_outData)[c25_i12] = c25_c_y[c25_i12];
  }

  sf_mex_destroy(&c25_mxArrayInData);
}

static const mxArray *c25_b_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  boolean_T c25_b_u;
  const mxArray *c25_b_y = NULL;
  SFc25_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc25_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_b_u = *(boolean_T *)c25_inData;
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_b_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_b_y, false);
  return c25_mxArrayOutData;
}

static const mxArray *c25_c_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_i13;
  real_T c25_b_inData[9];
  int32_T c25_i14;
  real_T c25_b_u[9];
  const mxArray *c25_b_y = NULL;
  SFc25_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc25_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  for (c25_i13 = 0; c25_i13 < 9; c25_i13++) {
    c25_b_inData[c25_i13] = (*(real_T (*)[9])c25_inData)[c25_i13];
  }

  for (c25_i14 = 0; c25_i14 < 9; c25_i14++) {
    c25_b_u[c25_i14] = c25_b_inData[c25_i14];
  }

  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", c25_b_u, 0, 0U, 1U, 0U, 1, 9),
                false);
  sf_mex_assign(&c25_mxArrayOutData, c25_b_y, false);
  return c25_mxArrayOutData;
}

static const mxArray *c25_d_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  real_T c25_b_u;
  const mxArray *c25_b_y = NULL;
  SFc25_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc25_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_b_u = *(real_T *)c25_inData;
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_b_y, false);
  return c25_mxArrayOutData;
}

static real_T c25_c_emlrt_marshallIn(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c25_b_u, const emlrtMsgIdentifier *c25_parentId)
{
  real_T c25_b_y;
  real_T c25_d0;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_b_u), &c25_d0, 1, 0, 0U, 0, 0U, 0);
  c25_b_y = c25_d0;
  sf_mex_destroy(&c25_b_u);
  return c25_b_y;
}

static void c25_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_nargout;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  real_T c25_b_y;
  SFc25_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc25_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c25_nargout = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_b_y = c25_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_nargout),
    &c25_thisId);
  sf_mex_destroy(&c25_nargout);
  *(real_T *)c25_outData = c25_b_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

const mxArray *sf_c25_Walking01_DDA3D_get_eml_resolved_functions_info(void)
{
  const mxArray *c25_nameCaptureInfo = NULL;
  c25_nameCaptureInfo = NULL;
  sf_mex_assign(&c25_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c25_info_helper(&c25_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c25_nameCaptureInfo);
  return c25_nameCaptureInfo;
}

static void c25_info_helper(const mxArray **c25_info)
{
  const mxArray *c25_rhs0 = NULL;
  const mxArray *c25_lhs0 = NULL;
  const mxArray *c25_rhs1 = NULL;
  const mxArray *c25_lhs1 = NULL;
  const mxArray *c25_rhs2 = NULL;
  const mxArray *c25_lhs2 = NULL;
  const mxArray *c25_rhs3 = NULL;
  const mxArray *c25_lhs3 = NULL;
  const mxArray *c25_rhs4 = NULL;
  const mxArray *c25_lhs4 = NULL;
  const mxArray *c25_rhs5 = NULL;
  const mxArray *c25_lhs5 = NULL;
  const mxArray *c25_rhs6 = NULL;
  const mxArray *c25_lhs6 = NULL;
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c25_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c25_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c25_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c25_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c25_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c25_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c25_info, c25_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c25_info, c25_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c25_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c25_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c25_info, sf_mex_duplicatearraysafe(&c25_lhs6), "lhs", "lhs",
                  6);
  sf_mex_destroy(&c25_rhs0);
  sf_mex_destroy(&c25_lhs0);
  sf_mex_destroy(&c25_rhs1);
  sf_mex_destroy(&c25_lhs1);
  sf_mex_destroy(&c25_rhs2);
  sf_mex_destroy(&c25_lhs2);
  sf_mex_destroy(&c25_rhs3);
  sf_mex_destroy(&c25_lhs3);
  sf_mex_destroy(&c25_rhs4);
  sf_mex_destroy(&c25_lhs4);
  sf_mex_destroy(&c25_rhs5);
  sf_mex_destroy(&c25_lhs5);
  sf_mex_destroy(&c25_rhs6);
  sf_mex_destroy(&c25_lhs6);
}

static const mxArray *c25_emlrt_marshallOut(const char * c25_b_u)
{
  const mxArray *c25_b_y = NULL;
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", c25_b_u, 15, 0U, 0U, 0U, 2, 1,
    strlen(c25_b_u)), false);
  return c25_b_y;
}

static const mxArray *c25_b_emlrt_marshallOut(const uint32_T c25_b_u)
{
  const mxArray *c25_b_y = NULL;
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_b_u, 7, 0U, 0U, 0U, 0), false);
  return c25_b_y;
}

static const mxArray *c25_e_sf_marshallOut(void *chartInstanceVoid, void
  *c25_inData)
{
  const mxArray *c25_mxArrayOutData = NULL;
  int32_T c25_b_u;
  const mxArray *c25_b_y = NULL;
  SFc25_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc25_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c25_mxArrayOutData = NULL;
  c25_b_u = *(int32_T *)c25_inData;
  c25_b_y = NULL;
  sf_mex_assign(&c25_b_y, sf_mex_create("y", &c25_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c25_mxArrayOutData, c25_b_y, false);
  return c25_mxArrayOutData;
}

static int32_T c25_d_emlrt_marshallIn(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c25_b_u, const emlrtMsgIdentifier *c25_parentId)
{
  int32_T c25_b_y;
  int32_T c25_i15;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_b_u), &c25_i15, 1, 6, 0U, 0, 0U, 0);
  c25_b_y = c25_i15;
  sf_mex_destroy(&c25_b_u);
  return c25_b_y;
}

static void c25_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c25_mxArrayInData, const char_T *c25_varName, void *c25_outData)
{
  const mxArray *c25_b_sfEvent;
  const char_T *c25_identifier;
  emlrtMsgIdentifier c25_thisId;
  int32_T c25_b_y;
  SFc25_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc25_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c25_b_sfEvent = sf_mex_dup(c25_mxArrayInData);
  c25_identifier = c25_varName;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_b_y = c25_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c25_b_sfEvent),
    &c25_thisId);
  sf_mex_destroy(&c25_b_sfEvent);
  *(int32_T *)c25_outData = c25_b_y;
  sf_mex_destroy(&c25_mxArrayInData);
}

static uint8_T c25_e_emlrt_marshallIn(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c25_b_is_active_c25_Walking01_DDA3D, const
  char_T *c25_identifier)
{
  uint8_T c25_b_y;
  emlrtMsgIdentifier c25_thisId;
  c25_thisId.fIdentifier = c25_identifier;
  c25_thisId.fParent = NULL;
  c25_b_y = c25_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c25_b_is_active_c25_Walking01_DDA3D), &c25_thisId);
  sf_mex_destroy(&c25_b_is_active_c25_Walking01_DDA3D);
  return c25_b_y;
}

static uint8_T c25_f_emlrt_marshallIn(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c25_b_u, const emlrtMsgIdentifier *c25_parentId)
{
  uint8_T c25_b_y;
  uint8_T c25_u0;
  (void)chartInstance;
  sf_mex_import(c25_parentId, sf_mex_dup(c25_b_u), &c25_u0, 1, 3, 0U, 0, 0U, 0);
  c25_b_y = c25_u0;
  sf_mex_destroy(&c25_b_u);
  return c25_b_y;
}

static void init_dsm_address_info(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc25_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c25_params = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c25_u = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c25_y = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c25_Reset = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
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

void sf_c25_Walking01_DDA3D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1180359361U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(708648295U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3754055957U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(304702287U);
}

mxArray* sf_c25_Walking01_DDA3D_get_post_codegen_info(void);
mxArray *sf_c25_Walking01_DDA3D_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ZRDEY1y09s8YDEVqmnEAKE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c25_Walking01_DDA3D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c25_Walking01_DDA3D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c25_Walking01_DDA3D_jit_fallback_info(void)
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

mxArray *sf_c25_Walking01_DDA3D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c25_Walking01_DDA3D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c25_Walking01_DDA3D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c25_Walking01_DDA3D\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c25_Walking01_DDA3D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc25_Walking01_DDA3DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc25_Walking01_DDA3DInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_DDA3DMachineNumber_,
           25,
           1,
           1,
           0,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"params");
          _SFD_SET_DATA_PROPS(1,1,1,0,"u");
          _SFD_SET_DATA_PROPS(2,2,0,1,"y");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Reset");
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
        _SFD_CV_INIT_EML(0,1,2,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2721);
        _SFD_CV_INIT_EML_FCN(0,1,"motor_torque_to_pwm",2723,-1,2890);
        _SFD_CV_INIT_EML_IF(0,1,0,185,195,-1,-2);

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c25_sf_marshallOut,(MexInFcnForType)
            c25_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c25_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c25_params);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c25_u);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c25_y);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c25_Reset);
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
  return "V8DcCJKGSDtSAUYceOllI";
}

static void sf_opaque_initialize_c25_Walking01_DDA3D(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc25_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c25_Walking01_DDA3D((SFc25_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
  initialize_c25_Walking01_DDA3D((SFc25_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c25_Walking01_DDA3D(void *chartInstanceVar)
{
  enable_c25_Walking01_DDA3D((SFc25_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c25_Walking01_DDA3D(void *chartInstanceVar)
{
  disable_c25_Walking01_DDA3D((SFc25_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c25_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_gateway_c25_Walking01_DDA3D((SFc25_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c25_Walking01_DDA3D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c25_Walking01_DDA3D((SFc25_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c25_Walking01_DDA3D(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c25_Walking01_DDA3D((SFc25_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c25_Walking01_DDA3D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc25_Walking01_DDA3DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_DDA3D_optimization_info();
    }

    finalize_c25_Walking01_DDA3D((SFc25_Walking01_DDA3DInstanceStruct*)
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
  initSimStructsc25_Walking01_DDA3D((SFc25_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c25_Walking01_DDA3D(SimStruct *S)
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
    initialize_params_c25_Walking01_DDA3D((SFc25_Walking01_DDA3DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c25_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      25);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,25,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,25,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,25);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,25,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,25,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,25);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2379296649U));
  ssSetChecksum1(S,(2268795054U));
  ssSetChecksum2(S,(3939647991U));
  ssSetChecksum3(S,(1384554165U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c25_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c25_Walking01_DDA3D(SimStruct *S)
{
  SFc25_Walking01_DDA3DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc25_Walking01_DDA3DInstanceStruct *)utMalloc(sizeof
    (SFc25_Walking01_DDA3DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc25_Walking01_DDA3DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c25_Walking01_DDA3D;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c25_Walking01_DDA3D;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c25_Walking01_DDA3D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c25_Walking01_DDA3D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c25_Walking01_DDA3D;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c25_Walking01_DDA3D;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c25_Walking01_DDA3D;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c25_Walking01_DDA3D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c25_Walking01_DDA3D;
  chartInstance->chartInfo.mdlStart = mdlStart_c25_Walking01_DDA3D;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c25_Walking01_DDA3D;
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

void c25_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c25_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c25_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c25_Walking01_DDA3D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c25_Walking01_DDA3D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
