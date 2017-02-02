/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking_ATRIAS_sfun.h"
#include "c60_Walking_ATRIAS.h"
#include <math.h>
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Walking_ATRIAS_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c60_debug_family_names[13] = { "SelectBasicLimits", "nargin",
  "nargout", "MotorCurrentCommand", "MedullaCommand", "RequestSoftStop", "q",
  "dq", "SafetyCountIn", "MotorCurrentCommandSafe", "MedullaCommandSafe",
  "SafetyState", "SafetyCountOut" };

static const char * c60_b_debug_family_names[14] = { "qbar", "dqbar", "qmin",
  "qmax", "dqmin", "dqmax", "qminv", "qmaxv", "T", "nargin", "nargout", "q",
  "dq", "violation" };

static const char * c60_c_debug_family_names[14] = { "qbar", "dqbar", "qmin",
  "qmax", "dqmin", "dqmax", "qminv", "qmaxv", "T", "nargin", "nargout", "q",
  "dq", "violation" };

static const char * c60_d_debug_family_names[14] = { "qbar", "dqbar", "qmin",
  "qmax", "dqmin", "dqmax", "qminv", "qmaxv", "T", "nargin", "nargout", "q",
  "dq", "violation" };

static const char * c60_e_debug_family_names[19] = { "MAX_MOTOR_CURRENT",
  "VALID_MEDULLA_COMMANDS", "SS_DYNAMIC_STATE_LIMIT", "SS_INVALID_MOTOR_COMMAND",
  "SS_INVALID_MEDULLA_COMMAND", "violation", "nargin", "nargout",
  "MotorCurrentCommand", "MedullaCommand", "RequestSoftStop", "q", "dq",
  "SafetyCountIn", "SelectBasicLimits", "MotorCurrentCommandSafe",
  "MedullaCommandSafe", "SafetyState", "SafetyCountOut" };

/* Function Declarations */
static void initialize_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance);
static void initialize_params_c60_Walking_ATRIAS
  (SFc60_Walking_ATRIASInstanceStruct *chartInstance);
static void enable_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance);
static void disable_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance);
static void c60_update_debugger_state_c60_Walking_ATRIAS
  (SFc60_Walking_ATRIASInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c60_Walking_ATRIAS
  (SFc60_Walking_ATRIASInstanceStruct *chartInstance);
static void set_sim_state_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c60_st);
static void finalize_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance);
static void sf_gateway_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance);
static void mdl_start_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance);
static void initSimStructsc60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct *
  chartInstance);
static void c60_MARLOSafety_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, real_T c60_b_MotorCurrentCommand[6], real_T
  c60_b_MedullaCommand, boolean_T c60_b_RequestSoftStop, real_T c60_b_q[13],
  real_T c60_b_dq[13], real_T c60_b_SafetyCountIn, real_T c60_SelectBasicLimits,
  real_T c60_b_MotorCurrentCommandSafe[6], real_T *c60_b_MedullaCommandSafe,
  real_T *c60_b_SafetyState, real_T *c60_b_SafetyCountOut);
static void c60_MARLOBasicSafetyLimits2(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, real_T c60_b_q[13], real_T c60_b_dq[13], boolean_T
  c60_violation[34]);
static void c60_MARLOBasicSafetyLimits3(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, real_T c60_b_q[13], real_T c60_b_dq[13], boolean_T
  c60_violation[34]);
static void c60_MARLOBasicSafetyLimits(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, real_T c60_b_q[13], real_T c60_b_dq[13], boolean_T
  c60_violation[34]);
static void init_script_number_translation(uint32_T c60_machineNumber, uint32_T
  c60_chartNumber, uint32_T c60_instanceNumber);
static const mxArray *c60_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData);
static real_T c60_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_b_SafetyCountOut, const char_T
  *c60_identifier);
static real_T c60_b_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId);
static void c60_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData);
static const mxArray *c60_b_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData);
static void c60_c_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_b_MotorCurrentCommandSafe, const char_T
  *c60_identifier, real_T c60_y[6]);
static void c60_d_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId,
  real_T c60_y[6]);
static void c60_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData);
static const mxArray *c60_c_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData);
static const mxArray *c60_d_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData);
static const mxArray *c60_e_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData);
static void c60_e_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId,
  boolean_T c60_y[34]);
static void c60_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData);
static void c60_f_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId,
  real_T c60_y[13]);
static void c60_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData);
static const mxArray *c60_f_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData);
static const mxArray *c60_g_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData);
static void c60_g_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId,
  real_T c60_y[34]);
static void c60_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData);
static boolean_T c60_h_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId);
static void c60_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData);
static const mxArray *c60_h_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData);
static void c60_info_helper(const mxArray **c60_info);
static const mxArray *c60_emlrt_marshallOut(const char * c60_u);
static const mxArray *c60_b_emlrt_marshallOut(const uint32_T c60_u);
static void c60_b_info_helper(const mxArray **c60_info);
static void c60_c_info_helper(const mxArray **c60_info);
static void c60_eml_scalar_eg(SFc60_Walking_ATRIASInstanceStruct *chartInstance);
static real_T c60_mpower(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c60_a);
static real_T c60_b_mpower(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c60_a);
static void c60_b_eml_scalar_eg(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance);
static void c60_eml_xgemm(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c60_A[442], real_T c60_B[13], real_T c60_C[34], real_T c60_b_C[34]);
static real_T c60_sum(SFc60_Walking_ATRIASInstanceStruct *chartInstance, real_T
                      c60_x[34]);
static int32_T c60_intmin(SFc60_Walking_ATRIASInstanceStruct *chartInstance);
static void c60_isfinite(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c60_x[6], boolean_T c60_b[6]);
static boolean_T c60_any(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  boolean_T c60_x[6]);
static void c60_abs(SFc60_Walking_ATRIASInstanceStruct *chartInstance, real_T
                    c60_x[6], real_T c60_y[6]);
static void c60_eml_error(SFc60_Walking_ATRIASInstanceStruct *chartInstance);
static int32_T c60_bsearch(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c60_x, real_T c60_s[8]);
static const mxArray *c60_i_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData);
static int32_T c60_i_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId);
static void c60_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData);
static uint8_T c60_j_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_b_is_active_c60_Walking_ATRIAS, const
  char_T *c60_identifier);
static uint8_T c60_k_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId);
static void c60_b_eml_xgemm(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c60_A[442], real_T c60_B[13], real_T c60_C[34]);
static void init_dsm_address_info(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  chartInstance->c60_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c60_is_active_c60_Walking_ATRIAS = 0U;
}

static void initialize_params_c60_Walking_ATRIAS
  (SFc60_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c60_update_debugger_state_c60_Walking_ATRIAS
  (SFc60_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c60_Walking_ATRIAS
  (SFc60_Walking_ATRIASInstanceStruct *chartInstance)
{
  const mxArray *c60_st;
  const mxArray *c60_y = NULL;
  real_T c60_hoistedGlobal;
  real_T c60_u;
  const mxArray *c60_b_y = NULL;
  int32_T c60_i0;
  real_T c60_b_u[6];
  const mxArray *c60_c_y = NULL;
  real_T c60_b_hoistedGlobal;
  real_T c60_c_u;
  const mxArray *c60_d_y = NULL;
  real_T c60_c_hoistedGlobal;
  real_T c60_d_u;
  const mxArray *c60_e_y = NULL;
  uint8_T c60_d_hoistedGlobal;
  uint8_T c60_e_u;
  const mxArray *c60_f_y = NULL;
  c60_st = NULL;
  c60_st = NULL;
  c60_y = NULL;
  sf_mex_assign(&c60_y, sf_mex_createcellmatrix(5, 1), false);
  c60_hoistedGlobal = *chartInstance->c60_MedullaCommandSafe;
  c60_u = c60_hoistedGlobal;
  c60_b_y = NULL;
  sf_mex_assign(&c60_b_y, sf_mex_create("y", &c60_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c60_y, 0, c60_b_y);
  for (c60_i0 = 0; c60_i0 < 6; c60_i0++) {
    c60_b_u[c60_i0] = (*chartInstance->c60_MotorCurrentCommandSafe)[c60_i0];
  }

  c60_c_y = NULL;
  sf_mex_assign(&c60_c_y, sf_mex_create("y", c60_b_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_setcell(c60_y, 1, c60_c_y);
  c60_b_hoistedGlobal = *chartInstance->c60_SafetyCountOut;
  c60_c_u = c60_b_hoistedGlobal;
  c60_d_y = NULL;
  sf_mex_assign(&c60_d_y, sf_mex_create("y", &c60_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c60_y, 2, c60_d_y);
  c60_c_hoistedGlobal = *chartInstance->c60_SafetyState;
  c60_d_u = c60_c_hoistedGlobal;
  c60_e_y = NULL;
  sf_mex_assign(&c60_e_y, sf_mex_create("y", &c60_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c60_y, 3, c60_e_y);
  c60_d_hoistedGlobal = chartInstance->c60_is_active_c60_Walking_ATRIAS;
  c60_e_u = c60_d_hoistedGlobal;
  c60_f_y = NULL;
  sf_mex_assign(&c60_f_y, sf_mex_create("y", &c60_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c60_y, 4, c60_f_y);
  sf_mex_assign(&c60_st, c60_y, false);
  return c60_st;
}

static void set_sim_state_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c60_st)
{
  const mxArray *c60_u;
  real_T c60_dv0[6];
  int32_T c60_i1;
  chartInstance->c60_doneDoubleBufferReInit = true;
  c60_u = sf_mex_dup(c60_st);
  *chartInstance->c60_MedullaCommandSafe = c60_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c60_u, 0)), "MedullaCommandSafe");
  c60_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c60_u, 1)),
    "MotorCurrentCommandSafe", c60_dv0);
  for (c60_i1 = 0; c60_i1 < 6; c60_i1++) {
    (*chartInstance->c60_MotorCurrentCommandSafe)[c60_i1] = c60_dv0[c60_i1];
  }

  *chartInstance->c60_SafetyCountOut = c60_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c60_u, 2)), "SafetyCountOut");
  *chartInstance->c60_SafetyState = c60_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c60_u, 3)), "SafetyState");
  chartInstance->c60_is_active_c60_Walking_ATRIAS = c60_j_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c60_u, 4)),
     "is_active_c60_Walking_ATRIAS");
  sf_mex_destroy(&c60_u);
  c60_update_debugger_state_c60_Walking_ATRIAS(chartInstance);
  sf_mex_destroy(&c60_st);
}

static void finalize_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  int32_T c60_i2;
  real_T c60_hoistedGlobal;
  boolean_T c60_b_hoistedGlobal;
  real_T c60_c_hoistedGlobal;
  int32_T c60_i3;
  real_T c60_b_MotorCurrentCommand[6];
  real_T c60_b_MedullaCommand;
  boolean_T c60_b_RequestSoftStop;
  int32_T c60_i4;
  real_T c60_b_q[13];
  int32_T c60_i5;
  real_T c60_b_dq[13];
  real_T c60_b_SafetyCountIn;
  uint32_T c60_debug_family_var_map[13];
  real_T c60_SelectBasicLimits;
  real_T c60_nargin = 6.0;
  real_T c60_nargout = 4.0;
  real_T c60_b_MotorCurrentCommandSafe[6];
  real_T c60_b_MedullaCommandSafe;
  real_T c60_b_SafetyState;
  real_T c60_b_SafetyCountOut;
  int32_T c60_i6;
  real_T c60_c_MotorCurrentCommand[6];
  int32_T c60_i7;
  real_T c60_c_q[13];
  int32_T c60_i8;
  real_T c60_c_dq[13];
  real_T c60_c_SafetyCountOut;
  real_T c60_c_SafetyState;
  real_T c60_c_MedullaCommandSafe;
  real_T c60_c_MotorCurrentCommandSafe[6];
  int32_T c60_i9;
  int32_T c60_i10;
  int32_T c60_i11;
  int32_T c60_i12;
  int32_T c60_i13;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 17U, chartInstance->c60_sfEvent);
  for (c60_i2 = 0; c60_i2 < 6; c60_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c60_MotorCurrentCommand)[c60_i2], 0U);
  }

  chartInstance->c60_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 17U, chartInstance->c60_sfEvent);
  c60_hoistedGlobal = *chartInstance->c60_MedullaCommand;
  c60_b_hoistedGlobal = *chartInstance->c60_RequestSoftStop;
  c60_c_hoistedGlobal = *chartInstance->c60_SafetyCountIn;
  for (c60_i3 = 0; c60_i3 < 6; c60_i3++) {
    c60_b_MotorCurrentCommand[c60_i3] = (*chartInstance->c60_MotorCurrentCommand)
      [c60_i3];
  }

  c60_b_MedullaCommand = c60_hoistedGlobal;
  c60_b_RequestSoftStop = c60_b_hoistedGlobal;
  for (c60_i4 = 0; c60_i4 < 13; c60_i4++) {
    c60_b_q[c60_i4] = (*chartInstance->c60_q)[c60_i4];
  }

  for (c60_i5 = 0; c60_i5 < 13; c60_i5++) {
    c60_b_dq[c60_i5] = (*chartInstance->c60_dq)[c60_i5];
  }

  c60_b_SafetyCountIn = c60_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c60_debug_family_names,
    c60_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c60_SelectBasicLimits, 0U, c60_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_nargin, 1U, c60_sf_marshallOut,
    c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_nargout, 2U, c60_sf_marshallOut,
    c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c60_b_MotorCurrentCommand, 3U, c60_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c60_b_MedullaCommand, 4U, c60_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c60_b_RequestSoftStop, 5U, c60_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c60_b_q, 6U, c60_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c60_b_dq, 7U, c60_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c60_b_SafetyCountIn, 8U, c60_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_MotorCurrentCommandSafe, 9U,
    c60_b_sf_marshallOut, c60_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_b_MedullaCommandSafe, 10U,
    c60_sf_marshallOut, c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_b_SafetyState, 11U,
    c60_sf_marshallOut, c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_b_SafetyCountOut, 12U,
    c60_sf_marshallOut, c60_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c60_sfEvent, 2);
  c60_SelectBasicLimits = 3.0;
  _SFD_EML_CALL(0U, chartInstance->c60_sfEvent, 3);
  for (c60_i6 = 0; c60_i6 < 6; c60_i6++) {
    c60_c_MotorCurrentCommand[c60_i6] = c60_b_MotorCurrentCommand[c60_i6];
  }

  for (c60_i7 = 0; c60_i7 < 13; c60_i7++) {
    c60_c_q[c60_i7] = c60_b_q[c60_i7];
  }

  for (c60_i8 = 0; c60_i8 < 13; c60_i8++) {
    c60_c_dq[c60_i8] = c60_b_dq[c60_i8];
  }

  c60_MARLOSafety_ATRIAS(chartInstance, c60_c_MotorCurrentCommand,
    c60_b_MedullaCommand, c60_b_RequestSoftStop, c60_c_q, c60_c_dq,
    c60_b_SafetyCountIn, 3.0, c60_c_MotorCurrentCommandSafe,
    &c60_c_MedullaCommandSafe, &c60_c_SafetyState, &c60_c_SafetyCountOut);
  for (c60_i9 = 0; c60_i9 < 6; c60_i9++) {
    c60_b_MotorCurrentCommandSafe[c60_i9] = c60_c_MotorCurrentCommandSafe[c60_i9];
  }

  c60_b_MedullaCommandSafe = c60_c_MedullaCommandSafe;
  c60_b_SafetyState = c60_c_SafetyState;
  c60_b_SafetyCountOut = c60_c_SafetyCountOut;
  _SFD_EML_CALL(0U, chartInstance->c60_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c60_i10 = 0; c60_i10 < 6; c60_i10++) {
    (*chartInstance->c60_MotorCurrentCommandSafe)[c60_i10] =
      c60_b_MotorCurrentCommandSafe[c60_i10];
  }

  *chartInstance->c60_MedullaCommandSafe = c60_b_MedullaCommandSafe;
  *chartInstance->c60_SafetyState = c60_b_SafetyState;
  *chartInstance->c60_SafetyCountOut = c60_b_SafetyCountOut;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 17U, chartInstance->c60_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking_ATRIASMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c60_i11 = 0; c60_i11 < 6; c60_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c60_MotorCurrentCommandSafe)[c60_i11],
                          1U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c60_MedullaCommand, 2U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c60_RequestSoftStop, 3U);
  for (c60_i12 = 0; c60_i12 < 13; c60_i12++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c60_q)[c60_i12], 4U);
  }

  for (c60_i13 = 0; c60_i13 < 13; c60_i13++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c60_dq)[c60_i13], 5U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c60_SafetyCountIn, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c60_MedullaCommandSafe, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c60_SafetyState, 8U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c60_SafetyCountOut, 9U);
}

static void mdl_start_c60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc60_Walking_ATRIAS(SFc60_Walking_ATRIASInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c60_MARLOSafety_ATRIAS(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, real_T c60_b_MotorCurrentCommand[6], real_T
  c60_b_MedullaCommand, boolean_T c60_b_RequestSoftStop, real_T c60_b_q[13],
  real_T c60_b_dq[13], real_T c60_b_SafetyCountIn, real_T c60_SelectBasicLimits,
  real_T c60_b_MotorCurrentCommandSafe[6], real_T *c60_b_MedullaCommandSafe,
  real_T *c60_b_SafetyState, real_T *c60_b_SafetyCountOut)
{
  uint32_T c60_debug_family_var_map[19];
  real_T c60_MAX_MOTOR_CURRENT;
  real_T c60_VALID_MEDULLA_COMMANDS[8];
  real_T c60_SS_DYNAMIC_STATE_LIMIT[34];
  real_T c60_SS_INVALID_MOTOR_COMMAND;
  real_T c60_SS_INVALID_MEDULLA_COMMAND;
  boolean_T c60_violation[34];
  real_T c60_nargin = 7.0;
  real_T c60_nargout = 4.0;
  int32_T c60_i14;
  int32_T c60_i15;
  int32_T c60_i16;
  static real_T c60_dv1[34] = { 1.0, 2.0, 4.0, 8.0, 16.0, 32.0, 64.0, 128.0,
    256.0, 512.0, 1024.0, 2048.0, 4096.0, 8192.0, 16384.0, 32768.0, 65536.0,
    131072.0, 262144.0, 524288.0, 1.048576E+6, 2.097152E+6, 4.194304E+6,
    8.388608E+6, 1.6777216E+7, 3.3554432E+7, 6.7108864E+7, 1.34217728E+8,
    2.68435456E+8, 5.36870912E+8, 1.073741824E+9, 2.147483648E+9, 4.294967296E+9,
    8.589934592E+9 };

  int32_T c60_i17;
  real_T c60_c_q[13];
  int32_T c60_i18;
  real_T c60_c_dq[13];
  boolean_T c60_bv0[34];
  int32_T c60_i19;
  int32_T c60_i20;
  real_T c60_d_q[13];
  int32_T c60_i21;
  real_T c60_d_dq[13];
  boolean_T c60_bv1[34];
  int32_T c60_i22;
  int32_T c60_i23;
  real_T c60_b_SS_DYNAMIC_STATE_LIMIT[34];
  int32_T c60_i24;
  real_T c60_c_MotorCurrentCommand[6];
  boolean_T c60_bv2[6];
  int32_T c60_i25;
  boolean_T c60_bv3[6];
  int32_T c60_i26;
  real_T c60_d_MotorCurrentCommand[6];
  real_T c60_dv2[6];
  int32_T c60_i27;
  boolean_T c60_bv4[6];
  real_T c60_a;
  real_T c60_b_a;
  boolean_T c60_y;
  int32_T c60_k;
  int32_T c60_b_k;
  int32_T c60_c_a;
  int32_T c60_d_a;
  int32_T c60_c;
  int32_T c60_irow1;
  int32_T c60_irow2;
  real_T c60_e_a;
  real_T c60_b;
  real_T c60_f_a;
  real_T c60_b_b;
  boolean_T c60_p;
  real_T c60_x;
  boolean_T c60_c_b;
  boolean_T c60_b0;
  boolean_T c60_b_p;
  boolean_T c60_tf;
  int32_T c60_i28;
  real_T c60_dv3[8];
  int32_T c60_n;
  boolean_T c60_b_x;
  boolean_T c60_c_x;
  boolean_T c60_b1;
  boolean_T c60_b_y;
  real_T c60_varargin_2;
  real_T c60_varargin_3;
  real_T c60_c_y;
  real_T c60_d_y;
  real_T c60_yk;
  real_T c60_e_y;
  real_T c60_varargin_1;
  real_T c60_b_varargin_2;
  real_T c60_d_x;
  real_T c60_e_x;
  real_T c60_xk;
  real_T c60_f_x;
  int32_T c60_i29;
  real_T c60_e_q[13];
  real_T c60_e_dq[13];
  boolean_T c60_bv5[34];
  int32_T c60_i30;
  int32_T c60_i31;
  int32_T c60_i32;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T exitg1;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c60_e_debug_family_names,
    c60_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_MAX_MOTOR_CURRENT, 0U,
    c60_sf_marshallOut, c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c60_VALID_MEDULLA_COMMANDS, 1U, c60_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_SS_DYNAMIC_STATE_LIMIT, 2U,
    c60_g_sf_marshallOut, c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_SS_INVALID_MOTOR_COMMAND, 3U,
    c60_sf_marshallOut, c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_SS_INVALID_MEDULLA_COMMAND, 4U,
    c60_sf_marshallOut, c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_violation, 5U, c60_e_sf_marshallOut,
    c60_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_nargin, 6U, c60_sf_marshallOut,
    c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_nargout, 7U, c60_sf_marshallOut,
    c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_MotorCurrentCommand, 8U,
    c60_b_sf_marshallOut, c60_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_b_MedullaCommand, 9U,
    c60_sf_marshallOut, c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_b_RequestSoftStop, 10U,
    c60_d_sf_marshallOut, c60_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_q, 11U, c60_c_sf_marshallOut,
    c60_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_dq, 12U, c60_c_sf_marshallOut,
    c60_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_b_SafetyCountIn, 13U,
    c60_sf_marshallOut, c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_SelectBasicLimits, 14U,
    c60_sf_marshallOut, c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_MotorCurrentCommandSafe, 15U,
    c60_b_sf_marshallOut, c60_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_MedullaCommandSafe, 16U,
    c60_sf_marshallOut, c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_SafetyState, 17U,
    c60_sf_marshallOut, c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_SafetyCountOut, 18U,
    c60_sf_marshallOut, c60_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 27);
  for (c60_i14 = 0; c60_i14 < 6; c60_i14++) {
    c60_b_MotorCurrentCommandSafe[c60_i14] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 28);
  *c60_b_MedullaCommandSafe = 4.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 35);
  c60_MAX_MOTOR_CURRENT = 120.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 36);
  for (c60_i15 = 0; c60_i15 < 8; c60_i15++) {
    c60_VALID_MEDULLA_COMMANDS[c60_i15] = (real_T)c60_i15;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 56);
  for (c60_i16 = 0; c60_i16 < 34; c60_i16++) {
    c60_SS_DYNAMIC_STATE_LIMIT[c60_i16] = c60_dv1[c60_i16];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 57);
  c60_SS_INVALID_MOTOR_COMMAND = c60_mpower(chartInstance, 2.0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 58);
  c60_SS_INVALID_MEDULLA_COMMAND = c60_b_mpower(chartInstance, 2.0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 64);
  switch ((int32_T)_SFD_INTEGER_CHECK("SelectBasicLimits", c60_SelectBasicLimits))
  {
   case 3:
    CV_SCRIPT_SWITCH(0, 0, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 66);
    for (c60_i17 = 0; c60_i17 < 13; c60_i17++) {
      c60_c_q[c60_i17] = c60_b_q[c60_i17];
    }

    for (c60_i18 = 0; c60_i18 < 13; c60_i18++) {
      c60_c_dq[c60_i18] = c60_b_dq[c60_i18];
    }

    c60_MARLOBasicSafetyLimits3(chartInstance, c60_c_q, c60_c_dq, c60_bv0);
    for (c60_i19 = 0; c60_i19 < 34; c60_i19++) {
      c60_violation[c60_i19] = c60_bv0[c60_i19];
    }
    break;

   case 2:
    CV_SCRIPT_SWITCH(0, 0, 2);
    _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 68);
    for (c60_i20 = 0; c60_i20 < 13; c60_i20++) {
      c60_d_q[c60_i20] = c60_b_q[c60_i20];
    }

    for (c60_i21 = 0; c60_i21 < 13; c60_i21++) {
      c60_d_dq[c60_i21] = c60_b_dq[c60_i21];
    }

    c60_MARLOBasicSafetyLimits2(chartInstance, c60_d_q, c60_d_dq, c60_bv1);
    for (c60_i22 = 0; c60_i22 < 34; c60_i22++) {
      c60_violation[c60_i22] = c60_bv1[c60_i22];
    }
    break;

   default:
    CV_SCRIPT_SWITCH(0, 0, 0);
    _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 70);
    for (c60_i30 = 0; c60_i30 < 13; c60_i30++) {
      c60_e_q[c60_i30] = c60_b_q[c60_i30];
    }

    for (c60_i31 = 0; c60_i31 < 13; c60_i31++) {
      c60_e_dq[c60_i31] = c60_b_dq[c60_i31];
    }

    c60_MARLOBasicSafetyLimits(chartInstance, c60_e_q, c60_e_dq, c60_bv5);
    for (c60_i32 = 0; c60_i32 < 34; c60_i32++) {
      c60_violation[c60_i32] = c60_bv5[c60_i32];
    }
    break;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 72);
  for (c60_i23 = 0; c60_i23 < 34; c60_i23++) {
    c60_b_SS_DYNAMIC_STATE_LIMIT[c60_i23] = c60_SS_DYNAMIC_STATE_LIMIT[c60_i23] *
      (real_T)c60_violation[c60_i23];
  }

  *c60_b_SafetyState = c60_sum(chartInstance, c60_b_SS_DYNAMIC_STATE_LIMIT);
  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 75);
  for (c60_i24 = 0; c60_i24 < 6; c60_i24++) {
    c60_c_MotorCurrentCommand[c60_i24] = c60_b_MotorCurrentCommand[c60_i24];
  }

  c60_isfinite(chartInstance, c60_c_MotorCurrentCommand, c60_bv2);
  for (c60_i25 = 0; c60_i25 < 6; c60_i25++) {
    c60_bv3[c60_i25] = !c60_bv2[c60_i25];
  }

  guard3 = false;
  if (CV_SCRIPT_COND(0, 0, c60_any(chartInstance, c60_bv3))) {
    guard3 = true;
  } else {
    for (c60_i26 = 0; c60_i26 < 6; c60_i26++) {
      c60_d_MotorCurrentCommand[c60_i26] = c60_b_MotorCurrentCommand[c60_i26];
    }

    c60_abs(chartInstance, c60_d_MotorCurrentCommand, c60_dv2);
    for (c60_i27 = 0; c60_i27 < 6; c60_i27++) {
      c60_bv4[c60_i27] = (c60_dv2[c60_i27] > c60_MAX_MOTOR_CURRENT);
    }

    if (CV_SCRIPT_COND(0, 1, c60_any(chartInstance, c60_bv4))) {
      guard3 = true;
    } else {
      CV_SCRIPT_MCDC(0, 0, false);
      CV_SCRIPT_IF(0, 0, false);
    }
  }

  if (guard3 == true) {
    CV_SCRIPT_MCDC(0, 0, true);
    CV_SCRIPT_IF(0, 0, true);
    _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 77);
    *c60_b_SafetyState += c60_SS_INVALID_MOTOR_COMMAND;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 81);
  c60_a = c60_b_MedullaCommand;
  c60_b_a = c60_a;
  c60_y = true;
  c60_intmin(chartInstance);
  c60_k = 1;
  exitg1 = false;
  while ((exitg1 == false) && (c60_k < 8)) {
    c60_b_k = c60_k;
    c60_c_a = c60_b_k;
    c60_d_a = c60_c_a;
    c60_c = c60_d_a;
    c60_irow1 = c60_b_k;
    c60_irow2 = c60_c + 1;
    c60_e_a = (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c60_irow1), 1, 8, 1, 0) - 1);
    c60_b = (real_T)(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
                      ("", (real_T)c60_irow2), 1, 8, 1, 0) - 1);
    c60_f_a = c60_e_a;
    c60_b_b = c60_b;
    c60_p = (c60_f_a <= c60_b_b);
    guard2 = false;
    if (c60_p) {
      guard2 = true;
    } else {
      c60_x = c60_b;
      c60_c_b = muDoubleScalarIsNaN(c60_x);
      if (c60_c_b) {
        guard2 = true;
      } else {
        c60_b0 = false;
      }
    }

    if (guard2 == true) {
      c60_b0 = true;
    }

    c60_b_p = c60_b0;
    if (!c60_b_p) {
      c60_y = false;
      exitg1 = true;
    } else {
      c60_k++;
    }
  }

  if (!c60_y) {
    c60_eml_error(chartInstance);
  }

  c60_tf = false;
  for (c60_i28 = 0; c60_i28 < 8; c60_i28++) {
    c60_dv3[c60_i28] = (real_T)c60_i28;
  }

  c60_n = c60_bsearch(chartInstance, c60_b_a, c60_dv3);
  if (c60_n > 0) {
    c60_tf = true;
  }

  c60_b_x = !c60_tf;
  c60_c_x = c60_b_x;
  c60_b1 = ((real_T)c60_c_x == 0.0);
  c60_b_y = !c60_b1;
  if (CV_SCRIPT_IF(0, 1, c60_b_y)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 82);
    *c60_b_SafetyState += c60_SS_INVALID_MEDULLA_COMMAND;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 112);
  if (CV_SCRIPT_IF(0, 2, CV_RELATIONAL_EVAL(14U, 0U, 0, *c60_b_SafetyState, 0.0,
        -1, 0U, *c60_b_SafetyState == 0.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 113);
    c60_varargin_2 = c60_b_SafetyCountIn - 1.0;
    c60_varargin_3 = c60_varargin_2;
    c60_c_y = c60_varargin_3;
    c60_d_y = c60_c_y;
    c60_eml_scalar_eg(chartInstance);
    c60_yk = c60_d_y;
    c60_e_y = c60_yk;
    c60_eml_scalar_eg(chartInstance);
    *c60_b_SafetyCountOut = muDoubleScalarMax(0.0, c60_e_y);
  } else {
    _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 115);
    c60_varargin_1 = c60_b_SafetyCountIn + 1.0;
    c60_b_varargin_2 = c60_varargin_1;
    c60_d_x = c60_b_varargin_2;
    c60_e_x = c60_d_x;
    c60_eml_scalar_eg(chartInstance);
    c60_xk = c60_e_x;
    c60_f_x = c60_xk;
    c60_eml_scalar_eg(chartInstance);
    *c60_b_SafetyCountOut = muDoubleScalarMin(c60_f_x, 10.0);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 118);
  guard1 = false;
  if (CV_SCRIPT_COND(0, 2, CV_RELATIONAL_EVAL(14U, 0U, 1, *c60_b_SafetyCountOut,
        4.0, -1, 2U, *c60_b_SafetyCountOut < 4.0))) {
    if (CV_SCRIPT_COND(0, 3, CV_RELATIONAL_EVAL(14U, 0U, 2, (real_T)
          c60_b_RequestSoftStop, 0.0, -1, 0U, (real_T)c60_b_RequestSoftStop ==
          0.0))) {
      CV_SCRIPT_MCDC(0, 1, true);
      CV_SCRIPT_IF(0, 3, true);
      _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 119);
      for (c60_i29 = 0; c60_i29 < 6; c60_i29++) {
        c60_b_MotorCurrentCommandSafe[c60_i29] =
          c60_b_MotorCurrentCommand[c60_i29];
      }

      _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, 120);
      *c60_b_MedullaCommandSafe = c60_b_MedullaCommand;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_SCRIPT_MCDC(0, 1, false);
    CV_SCRIPT_IF(0, 3, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c60_sfEvent, -120);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c60_MARLOBasicSafetyLimits2(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, real_T c60_b_q[13], real_T c60_b_dq[13], boolean_T
  c60_violation[34])
{
  uint32_T c60_debug_family_var_map[14];
  real_T c60_qbar[34];
  real_T c60_dqbar[34];
  real_T c60_qmin[34];
  real_T c60_qmax[34];
  real_T c60_dqmin[34];
  real_T c60_dqmax[34];
  real_T c60_qminv[34];
  real_T c60_qmaxv[34];
  real_T c60_T[442];
  real_T c60_nargin = 2.0;
  real_T c60_nargout = 1.0;
  int32_T c60_i33;
  static real_T c60_a[442] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, -0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 0.5, 0.0,
    0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, -0.5, 0.0, -1.0, 0.0,
    0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0,
    0.0, -0.5, 0.0, 1.0, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -1.0, 0.0, -0.5, 0.0, -1.0, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0,
    0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.5, 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.5,
    0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c60_i34;
  static real_T c60_dv4[34] = { 100.0, 100.0, 160.0, 160.0, 130.0, 130.0, 15.0,
    15.0, 100.0, 100.0, 160.0, 160.0, 130.0, 130.0, 15.0, 15.0, -2.0, -2.0, -6.0,
    -6.0, -3.0, -3.0, -8.0, -8.0, -20.0, -20.0, -45.0, -25.0, -30.0, -20.0,
    140.0, 140.0, 140.0, 140.0 };

  int32_T c60_i35;
  static real_T c60_dv5[34] = { 200.0, 200.0, 260.0, 260.0, 230.0, 230.0, 90.0,
    90.0, 200.0, 200.0, 260.0, 260.0, 230.0, 230.0, 90.0, 90.0, 6.0, 6.0, 3.0,
    3.0, 3.0, 3.0, 3.0, 3.0, 15.0, 15.0, 45.0, 30.0, 15.0, 20.0, 220.0, 220.0,
    220.0, 220.0 };

  int32_T c60_i36;
  static real_T c60_dv6[34] = { -400.0, -400.0, -400.0, -400.0, -400.0, -400.0,
    -500.0, -500.0, -400.0, -400.0, -400.0, -400.0, -400.0, -400.0, -500.0,
    -500.0, -200.0, -200.0, -400.0, -400.0, -300.0, -300.0, -600.0, -600.0,
    -250.0, -250.0, -400.0, -300.0, -150.0, -150.0, -300.0, -300.0, -300.0,
    -300.0 };

  int32_T c60_i37;
  static real_T c60_dv7[34] = { 600.0, 600.0, 500.0, 500.0, 500.0, 500.0, 500.0,
    500.0, 600.0, 600.0, 500.0, 500.0, 500.0, 500.0, 500.0, 500.0, 300.0, 300.0,
    200.0, 200.0, 300.0, 300.0, 500.0, 500.0, 250.0, 250.0, 400.0, 300.0, 150.0,
    150.0, 300.0, 300.0, 300.0, 300.0 };

  int32_T c60_i38;
  static real_T c60_dv8[34] = { 160.0, 160.0, 200.0, 200.0, 180.0, 180.0, 30.0,
    30.0, 160.0, 160.0, 200.0, 200.0, 180.0, 180.0, 30.0, 30.0, -1.0, -1.0, -2.0,
    -2.0, -1.0, -1.0, -2.0, -2.0, -20.0, -20.0, -25.0, -25.0, -20.0, -10.0,
    160.0, 160.0, 160.0, 160.0 };

  int32_T c60_i39;
  static real_T c60_dv9[34] = { 180.0, 180.0, 220.0, 220.0, 180.0, 180.0, 60.0,
    60.0, 180.0, 180.0, 220.0, 220.0, 180.0, 180.0, 60.0, 60.0, 3.0, 3.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 15.0, 15.0, 25.0, 30.0, 0.0, 10.0, 200.0, 200.0,
    200.0, 200.0 };

  int32_T c60_i40;
  real_T c60_b[13];
  int32_T c60_i41;
  real_T c60_y[34];
  int32_T c60_i42;
  real_T c60_b_a[442];
  int32_T c60_i43;
  real_T c60_b_b[13];
  int32_T c60_i44;
  int32_T c60_i45;
  int32_T c60_i46;
  int32_T c60_i47;
  int32_T c60_i48;
  real_T c60_c_a[442];
  int32_T c60_i49;
  real_T c60_c_b[13];
  int32_T c60_i50;
  int32_T c60_i51;
  int32_T c60_i52;
  boolean_T c60_bv6[34];
  int32_T c60_i53;
  boolean_T c60_bv7[34];
  int32_T c60_i54;
  int32_T c60_i55;
  int32_T c60_i56;
  int32_T c60_i57;
  int32_T c60_i58;
  int32_T c60_i59;
  int32_T c60_i60;
  int32_T c60_i61;
  int32_T c60_i62;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c60_b_debug_family_names,
    c60_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qbar, 0U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_dqbar, 1U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qmin, 2U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qmax, 3U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_dqmin, 4U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_dqmax, 5U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qminv, 6U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qmaxv, 7U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c60_T, 8U, c60_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_nargin, 9U, c60_sf_marshallOut,
    c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_nargout, 10U, c60_sf_marshallOut,
    c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_q, 11U, c60_c_sf_marshallOut,
    c60_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_dq, 12U, c60_c_sf_marshallOut,
    c60_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_violation, 13U, c60_e_sf_marshallOut,
    c60_c_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c60_sfEvent, 4);
  for (c60_i33 = 0; c60_i33 < 442; c60_i33++) {
    c60_T[c60_i33] = c60_a[c60_i33];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c60_sfEvent, 60);
  for (c60_i34 = 0; c60_i34 < 34; c60_i34++) {
    c60_qmin[c60_i34] = c60_dv4[c60_i34];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c60_sfEvent, 115);
  for (c60_i35 = 0; c60_i35 < 34; c60_i35++) {
    c60_qmax[c60_i35] = c60_dv5[c60_i35];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c60_sfEvent, 170U);
  for (c60_i36 = 0; c60_i36 < 34; c60_i36++) {
    c60_dqmin[c60_i36] = c60_dv6[c60_i36];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c60_sfEvent, 225U);
  for (c60_i37 = 0; c60_i37 < 34; c60_i37++) {
    c60_dqmax[c60_i37] = c60_dv7[c60_i37];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c60_sfEvent, 280);
  for (c60_i38 = 0; c60_i38 < 34; c60_i38++) {
    c60_qminv[c60_i38] = c60_dv8[c60_i38];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c60_sfEvent, 335);
  for (c60_i39 = 0; c60_i39 < 34; c60_i39++) {
    c60_qmaxv[c60_i39] = c60_dv9[c60_i39];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c60_sfEvent, 392);
  for (c60_i40 = 0; c60_i40 < 13; c60_i40++) {
    c60_b[c60_i40] = c60_b_q[c60_i40];
  }

  c60_b_eml_scalar_eg(chartInstance);
  c60_b_eml_scalar_eg(chartInstance);
  for (c60_i41 = 0; c60_i41 < 34; c60_i41++) {
    c60_y[c60_i41] = 0.0;
  }

  for (c60_i42 = 0; c60_i42 < 442; c60_i42++) {
    c60_b_a[c60_i42] = c60_a[c60_i42];
  }

  for (c60_i43 = 0; c60_i43 < 13; c60_i43++) {
    c60_b_b[c60_i43] = c60_b[c60_i43];
  }

  c60_b_eml_xgemm(chartInstance, c60_b_a, c60_b_b, c60_y);
  for (c60_i44 = 0; c60_i44 < 34; c60_i44++) {
    c60_y[c60_i44] *= 180.0;
  }

  for (c60_i45 = 0; c60_i45 < 34; c60_i45++) {
    c60_qbar[c60_i45] = c60_y[c60_i45] / 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c60_sfEvent, 393);
  for (c60_i46 = 0; c60_i46 < 13; c60_i46++) {
    c60_b[c60_i46] = c60_b_dq[c60_i46];
  }

  c60_b_eml_scalar_eg(chartInstance);
  c60_b_eml_scalar_eg(chartInstance);
  for (c60_i47 = 0; c60_i47 < 34; c60_i47++) {
    c60_y[c60_i47] = 0.0;
  }

  for (c60_i48 = 0; c60_i48 < 442; c60_i48++) {
    c60_c_a[c60_i48] = c60_a[c60_i48];
  }

  for (c60_i49 = 0; c60_i49 < 13; c60_i49++) {
    c60_c_b[c60_i49] = c60_b[c60_i49];
  }

  c60_b_eml_xgemm(chartInstance, c60_c_a, c60_c_b, c60_y);
  for (c60_i50 = 0; c60_i50 < 34; c60_i50++) {
    c60_y[c60_i50] *= 180.0;
  }

  for (c60_i51 = 0; c60_i51 < 34; c60_i51++) {
    c60_dqbar[c60_i51] = c60_y[c60_i51] / 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c60_sfEvent, 394);
  for (c60_i52 = 0; c60_i52 < 34; c60_i52++) {
    c60_bv6[c60_i52] = (c60_qbar[c60_i52] < c60_qmin[c60_i52]);
  }

  for (c60_i53 = 0; c60_i53 < 34; c60_i53++) {
    c60_bv7[c60_i53] = (c60_qbar[c60_i53] > c60_qmax[c60_i53]);
  }

  for (c60_i54 = 0; c60_i54 < 34; c60_i54++) {
    c60_bv6[c60_i54] = (c60_bv6[c60_i54] || c60_bv7[c60_i54]);
  }

  for (c60_i55 = 0; c60_i55 < 34; c60_i55++) {
    c60_bv7[c60_i55] = (c60_dqbar[c60_i55] < c60_dqmin[c60_i55]);
  }

  for (c60_i56 = 0; c60_i56 < 34; c60_i56++) {
    c60_bv6[c60_i56] = (c60_bv6[c60_i56] || c60_bv7[c60_i56]);
  }

  for (c60_i57 = 0; c60_i57 < 34; c60_i57++) {
    c60_bv7[c60_i57] = (c60_dqbar[c60_i57] > c60_dqmax[c60_i57]);
  }

  for (c60_i58 = 0; c60_i58 < 34; c60_i58++) {
    c60_bv6[c60_i58] = (c60_bv6[c60_i58] || c60_bv7[c60_i58]);
  }

  for (c60_i59 = 0; c60_i59 < 34; c60_i59++) {
    c60_bv7[c60_i59] = (c60_dqbar[c60_i59] * (c60_qminv[c60_i59] -
      c60_qmin[c60_i59]) < c60_dqmin[c60_i59] * (c60_qbar[c60_i59] -
      c60_qmin[c60_i59]));
  }

  for (c60_i60 = 0; c60_i60 < 34; c60_i60++) {
    c60_bv6[c60_i60] = (c60_bv6[c60_i60] || c60_bv7[c60_i60]);
  }

  for (c60_i61 = 0; c60_i61 < 34; c60_i61++) {
    c60_bv7[c60_i61] = (c60_dqbar[c60_i61] * (c60_qmax[c60_i61] -
      c60_qmaxv[c60_i61]) > c60_dqmax[c60_i61] * (c60_qmax[c60_i61] -
      c60_qbar[c60_i61]));
  }

  for (c60_i62 = 0; c60_i62 < 34; c60_i62++) {
    c60_violation[c60_i62] = (c60_bv6[c60_i62] || c60_bv7[c60_i62]);
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c60_sfEvent, -394);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c60_MARLOBasicSafetyLimits3(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, real_T c60_b_q[13], real_T c60_b_dq[13], boolean_T
  c60_violation[34])
{
  uint32_T c60_debug_family_var_map[14];
  real_T c60_qbar[34];
  real_T c60_dqbar[34];
  real_T c60_qmin[34];
  real_T c60_qmax[34];
  real_T c60_dqmin[34];
  real_T c60_dqmax[34];
  real_T c60_qminv[34];
  real_T c60_qmaxv[34];
  real_T c60_T[442];
  real_T c60_nargin = 2.0;
  real_T c60_nargout = 1.0;
  int32_T c60_i63;
  static real_T c60_a[442] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, -0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 0.5, 0.0,
    0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, -0.5, 0.0, -1.0, 0.0,
    0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0,
    0.0, -0.5, 0.0, 1.0, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -1.0, 0.0, -0.5, 0.0, -1.0, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0,
    0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.5, 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.5,
    0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c60_i64;
  static real_T c60_dv10[34] = { 100.0, 100.0, 140.0, 140.0, 130.0, 130.0, 30.0,
    30.0, 100.0, 100.0, 140.0, 140.0, 130.0, 130.0, 30.0, 30.0, -4.0, -4.0,
    -10.0, -10.0, -8.0, -8.0, -20.0, -20.0, -20.0, -20.0, -70.0, -40.0, -25.0,
    -20.0, 120.0, 120.0, 120.0, 120.0 };

  int32_T c60_i65;
  static real_T c60_dv11[34] = { 240.0, 240.0, 250.0, 250.0, 230.0, 230.0, 180.0,
    180.0, 240.0, 240.0, 250.0, 250.0, 230.0, 230.0, 180.0, 180.0, 10.0, 10.0,
    5.0, 5.0, 5.0, 5.0, 8.0, 8.0, 12.0, 12.0, 70.0, 25.0, 25.0, 20.0, 240.0,
    240.0, 240.0, 240.0 };

  int32_T c60_i66;
  static real_T c60_dv12[34] = { -600.0, -600.0, -600.0, -600.0, -600.0, -600.0,
    -800.0, -800.0, -600.0, -600.0, -600.0, -600.0, -600.0, -600.0, -800.0,
    -800.0, -600.0, -600.0, -600.0, -600.0, -1000.0, -1000.0, -1000.0, -1000.0,
    -400.0, -400.0, -600.0, -600.0, -250.0, -250.0, -600.0, -600.0, -600.0,
    -600.0 };

  int32_T c60_i67;
  static real_T c60_dv13[34] = { 600.0, 600.0, 600.0, 600.0, 600.0, 600.0, 800.0,
    800.0, 600.0, 600.0, 600.0, 600.0, 600.0, 600.0, 800.0, 800.0, 600.0, 600.0,
    600.0, 600.0, 1000.0, 1000.0, 1000.0, 1000.0, 400.0, 400.0, 600.0, 600.0,
    250.0, 250.0, 600.0, 600.0, 600.0, 600.0 };

  int32_T c60_i68;
  static real_T c60_dv14[34] = { 140.0, 140.0, 180.0, 180.0, 150.0, 150.0, 35.0,
    35.0, 140.0, 140.0, 180.0, 180.0, 150.0, 150.0, 35.0, 35.0, -1.0, -1.0, -5.0,
    -5.0, -4.0, -4.0, -10.0, -10.0, -20.0, -20.0, -50.0, -40.0, -20.0, -10.0,
    140.0, 140.0, 140.0, 140.0 };

  int32_T c60_i69;
  static real_T c60_dv15[34] = { 200.0, 200.0, 240.0, 240.0, 200.0, 200.0, 140.0,
    140.0, 200.0, 200.0, 240.0, 240.0, 200.0, 200.0, 140.0, 140.0, 5.0, 5.0, 1.0,
    1.0, 1.0, 1.0, 3.0, 3.0, 8.0, 8.0, 50.0, 20.0, 20.0, 10.0, 220.0, 220.0,
    220.0, 220.0 };

  int32_T c60_i70;
  real_T c60_b[13];
  int32_T c60_i71;
  real_T c60_y[34];
  int32_T c60_i72;
  real_T c60_b_a[442];
  int32_T c60_i73;
  real_T c60_b_b[13];
  int32_T c60_i74;
  int32_T c60_i75;
  int32_T c60_i76;
  int32_T c60_i77;
  int32_T c60_i78;
  real_T c60_c_a[442];
  int32_T c60_i79;
  real_T c60_c_b[13];
  int32_T c60_i80;
  int32_T c60_i81;
  int32_T c60_i82;
  boolean_T c60_bv8[34];
  int32_T c60_i83;
  boolean_T c60_bv9[34];
  int32_T c60_i84;
  int32_T c60_i85;
  int32_T c60_i86;
  int32_T c60_i87;
  int32_T c60_i88;
  int32_T c60_i89;
  int32_T c60_i90;
  int32_T c60_i91;
  int32_T c60_i92;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c60_c_debug_family_names,
    c60_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qbar, 0U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_dqbar, 1U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qmin, 2U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qmax, 3U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_dqmin, 4U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_dqmax, 5U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qminv, 6U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qmaxv, 7U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c60_T, 8U, c60_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_nargin, 9U, c60_sf_marshallOut,
    c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_nargout, 10U, c60_sf_marshallOut,
    c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_q, 11U, c60_c_sf_marshallOut,
    c60_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_dq, 12U, c60_c_sf_marshallOut,
    c60_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_violation, 13U, c60_e_sf_marshallOut,
    c60_c_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c60_sfEvent, 4);
  for (c60_i63 = 0; c60_i63 < 442; c60_i63++) {
    c60_T[c60_i63] = c60_a[c60_i63];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c60_sfEvent, 60);
  for (c60_i64 = 0; c60_i64 < 34; c60_i64++) {
    c60_qmin[c60_i64] = c60_dv10[c60_i64];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c60_sfEvent, 115);
  for (c60_i65 = 0; c60_i65 < 34; c60_i65++) {
    c60_qmax[c60_i65] = c60_dv11[c60_i65];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c60_sfEvent, 170U);
  for (c60_i66 = 0; c60_i66 < 34; c60_i66++) {
    c60_dqmin[c60_i66] = c60_dv12[c60_i66];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c60_sfEvent, 225U);
  for (c60_i67 = 0; c60_i67 < 34; c60_i67++) {
    c60_dqmax[c60_i67] = c60_dv13[c60_i67];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c60_sfEvent, 280);
  for (c60_i68 = 0; c60_i68 < 34; c60_i68++) {
    c60_qminv[c60_i68] = c60_dv14[c60_i68];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c60_sfEvent, 335);
  for (c60_i69 = 0; c60_i69 < 34; c60_i69++) {
    c60_qmaxv[c60_i69] = c60_dv15[c60_i69];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c60_sfEvent, 392);
  for (c60_i70 = 0; c60_i70 < 13; c60_i70++) {
    c60_b[c60_i70] = c60_b_q[c60_i70];
  }

  c60_b_eml_scalar_eg(chartInstance);
  c60_b_eml_scalar_eg(chartInstance);
  for (c60_i71 = 0; c60_i71 < 34; c60_i71++) {
    c60_y[c60_i71] = 0.0;
  }

  for (c60_i72 = 0; c60_i72 < 442; c60_i72++) {
    c60_b_a[c60_i72] = c60_a[c60_i72];
  }

  for (c60_i73 = 0; c60_i73 < 13; c60_i73++) {
    c60_b_b[c60_i73] = c60_b[c60_i73];
  }

  c60_b_eml_xgemm(chartInstance, c60_b_a, c60_b_b, c60_y);
  for (c60_i74 = 0; c60_i74 < 34; c60_i74++) {
    c60_y[c60_i74] *= 180.0;
  }

  for (c60_i75 = 0; c60_i75 < 34; c60_i75++) {
    c60_qbar[c60_i75] = c60_y[c60_i75] / 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c60_sfEvent, 393);
  for (c60_i76 = 0; c60_i76 < 13; c60_i76++) {
    c60_b[c60_i76] = c60_b_dq[c60_i76];
  }

  c60_b_eml_scalar_eg(chartInstance);
  c60_b_eml_scalar_eg(chartInstance);
  for (c60_i77 = 0; c60_i77 < 34; c60_i77++) {
    c60_y[c60_i77] = 0.0;
  }

  for (c60_i78 = 0; c60_i78 < 442; c60_i78++) {
    c60_c_a[c60_i78] = c60_a[c60_i78];
  }

  for (c60_i79 = 0; c60_i79 < 13; c60_i79++) {
    c60_c_b[c60_i79] = c60_b[c60_i79];
  }

  c60_b_eml_xgemm(chartInstance, c60_c_a, c60_c_b, c60_y);
  for (c60_i80 = 0; c60_i80 < 34; c60_i80++) {
    c60_y[c60_i80] *= 180.0;
  }

  for (c60_i81 = 0; c60_i81 < 34; c60_i81++) {
    c60_dqbar[c60_i81] = c60_y[c60_i81] / 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c60_sfEvent, 394);
  for (c60_i82 = 0; c60_i82 < 34; c60_i82++) {
    c60_bv8[c60_i82] = (c60_qbar[c60_i82] < c60_qmin[c60_i82]);
  }

  for (c60_i83 = 0; c60_i83 < 34; c60_i83++) {
    c60_bv9[c60_i83] = (c60_qbar[c60_i83] > c60_qmax[c60_i83]);
  }

  for (c60_i84 = 0; c60_i84 < 34; c60_i84++) {
    c60_bv8[c60_i84] = (c60_bv8[c60_i84] || c60_bv9[c60_i84]);
  }

  for (c60_i85 = 0; c60_i85 < 34; c60_i85++) {
    c60_bv9[c60_i85] = (c60_dqbar[c60_i85] < c60_dqmin[c60_i85]);
  }

  for (c60_i86 = 0; c60_i86 < 34; c60_i86++) {
    c60_bv8[c60_i86] = (c60_bv8[c60_i86] || c60_bv9[c60_i86]);
  }

  for (c60_i87 = 0; c60_i87 < 34; c60_i87++) {
    c60_bv9[c60_i87] = (c60_dqbar[c60_i87] > c60_dqmax[c60_i87]);
  }

  for (c60_i88 = 0; c60_i88 < 34; c60_i88++) {
    c60_bv8[c60_i88] = (c60_bv8[c60_i88] || c60_bv9[c60_i88]);
  }

  for (c60_i89 = 0; c60_i89 < 34; c60_i89++) {
    c60_bv9[c60_i89] = (c60_dqbar[c60_i89] * (c60_qminv[c60_i89] -
      c60_qmin[c60_i89]) < c60_dqmin[c60_i89] * (c60_qbar[c60_i89] -
      c60_qmin[c60_i89]));
  }

  for (c60_i90 = 0; c60_i90 < 34; c60_i90++) {
    c60_bv8[c60_i90] = (c60_bv8[c60_i90] || c60_bv9[c60_i90]);
  }

  for (c60_i91 = 0; c60_i91 < 34; c60_i91++) {
    c60_bv9[c60_i91] = (c60_dqbar[c60_i91] * (c60_qmax[c60_i91] -
      c60_qmaxv[c60_i91]) > c60_dqmax[c60_i91] * (c60_qmax[c60_i91] -
      c60_qbar[c60_i91]));
  }

  for (c60_i92 = 0; c60_i92 < 34; c60_i92++) {
    c60_violation[c60_i92] = (c60_bv8[c60_i92] || c60_bv9[c60_i92]);
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c60_sfEvent, -394);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c60_MARLOBasicSafetyLimits(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, real_T c60_b_q[13], real_T c60_b_dq[13], boolean_T
  c60_violation[34])
{
  uint32_T c60_debug_family_var_map[14];
  real_T c60_qbar[34];
  real_T c60_dqbar[34];
  real_T c60_qmin[34];
  real_T c60_qmax[34];
  real_T c60_dqmin[34];
  real_T c60_dqmax[34];
  real_T c60_qminv[34];
  real_T c60_qmaxv[34];
  real_T c60_T[442];
  real_T c60_nargin = 2.0;
  real_T c60_nargout = 1.0;
  int32_T c60_i93;
  static real_T c60_a[442] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 1.0,
    1.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -1.0, 0.0, 0.0, 0.0, -0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 0.5, 0.0,
    0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, -0.5, 0.0, -1.0, 0.0,
    0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0,
    0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0, 0.0, 0.0,
    0.0, -0.5, 0.0, 1.0, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0,
    0.0, 0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, -1.0, 0.0, -0.5, 0.0, -1.0, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0,
    0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0,
    0.0, 0.5, 0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0,
    1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.5,
    0.0, -1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0, 1.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.5, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 };

  int32_T c60_i94;
  static real_T c60_dv16[34] = { 100.0, 100.0, 160.0, 160.0, 130.0, 130.0, 15.0,
    15.0, 100.0, 100.0, 160.0, 160.0, 130.0, 130.0, 15.0, 15.0, -2.0, -2.0, -6.0,
    -6.0, -3.0, -3.0, -8.0, -8.0, -20.0, -20.0, -45.0, -25.0, -30.0, -20.0,
    140.0, 140.0, 140.0, 140.0 };

  int32_T c60_i95;
  static real_T c60_dv17[34] = { 200.0, 200.0, 260.0, 260.0, 230.0, 230.0, 90.0,
    90.0, 200.0, 200.0, 260.0, 260.0, 230.0, 230.0, 90.0, 90.0, 5.0, 5.0, 3.0,
    3.0, 3.0, 3.0, 3.0, 3.0, 15.0, 15.0, 45.0, 18.0, 15.0, 20.0, 220.0, 220.0,
    220.0, 220.0 };

  int32_T c60_i96;
  static real_T c60_dv18[34] = { -400.0, -400.0, -400.0, -400.0, -400.0, -400.0,
    -500.0, -500.0, -400.0, -400.0, -400.0, -400.0, -400.0, -400.0, -500.0,
    -500.0, -200.0, -200.0, -400.0, -400.0, -300.0, -300.0, -600.0, -600.0,
    -250.0, -250.0, -400.0, -300.0, -150.0, -150.0, -300.0, -300.0, -300.0,
    -300.0 };

  int32_T c60_i97;
  static real_T c60_dv19[34] = { 600.0, 600.0, 500.0, 500.0, 500.0, 500.0, 500.0,
    500.0, 600.0, 600.0, 500.0, 500.0, 500.0, 500.0, 500.0, 500.0, 300.0, 300.0,
    200.0, 200.0, 300.0, 300.0, 500.0, 500.0, 250.0, 250.0, 400.0, 300.0, 150.0,
    150.0, 300.0, 300.0, 300.0, 300.0 };

  int32_T c60_i98;
  static real_T c60_dv20[34] = { 160.0, 160.0, 200.0, 200.0, 180.0, 180.0, 30.0,
    30.0, 160.0, 160.0, 200.0, 200.0, 180.0, 180.0, 30.0, 30.0, -1.0, -1.0, -2.0,
    -2.0, -1.0, -1.0, -2.0, -2.0, -20.0, -20.0, -25.0, -25.0, -20.0, -10.0,
    160.0, 160.0, 160.0, 160.0 };

  int32_T c60_i99;
  static real_T c60_dv21[34] = { 180.0, 180.0, 220.0, 220.0, 180.0, 180.0, 60.0,
    60.0, 180.0, 180.0, 220.0, 220.0, 180.0, 180.0, 60.0, 60.0, 3.0, 3.0, 1.0,
    1.0, 1.0, 1.0, 1.0, 1.0, 15.0, 15.0, 25.0, 18.0, 0.0, 10.0, 200.0, 200.0,
    200.0, 200.0 };

  int32_T c60_i100;
  real_T c60_b[13];
  int32_T c60_i101;
  real_T c60_y[34];
  int32_T c60_i102;
  real_T c60_b_a[442];
  int32_T c60_i103;
  real_T c60_b_b[13];
  int32_T c60_i104;
  int32_T c60_i105;
  int32_T c60_i106;
  int32_T c60_i107;
  int32_T c60_i108;
  real_T c60_c_a[442];
  int32_T c60_i109;
  real_T c60_c_b[13];
  int32_T c60_i110;
  int32_T c60_i111;
  int32_T c60_i112;
  boolean_T c60_bv10[34];
  int32_T c60_i113;
  boolean_T c60_bv11[34];
  int32_T c60_i114;
  int32_T c60_i115;
  int32_T c60_i116;
  int32_T c60_i117;
  int32_T c60_i118;
  int32_T c60_i119;
  int32_T c60_i120;
  int32_T c60_i121;
  int32_T c60_i122;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c60_d_debug_family_names,
    c60_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qbar, 0U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_dqbar, 1U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qmin, 2U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qmax, 3U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_dqmin, 4U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_dqmax, 5U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qminv, 6U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_qmaxv, 7U, c60_g_sf_marshallOut,
    c60_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c60_T, 8U, c60_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_nargin, 9U, c60_sf_marshallOut,
    c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c60_nargout, 10U, c60_sf_marshallOut,
    c60_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_q, 11U, c60_c_sf_marshallOut,
    c60_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_b_dq, 12U, c60_c_sf_marshallOut,
    c60_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c60_violation, 13U, c60_e_sf_marshallOut,
    c60_c_sf_marshallIn);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c60_sfEvent, 4);
  for (c60_i93 = 0; c60_i93 < 442; c60_i93++) {
    c60_T[c60_i93] = c60_a[c60_i93];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c60_sfEvent, 60);
  for (c60_i94 = 0; c60_i94 < 34; c60_i94++) {
    c60_qmin[c60_i94] = c60_dv16[c60_i94];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c60_sfEvent, 115);
  for (c60_i95 = 0; c60_i95 < 34; c60_i95++) {
    c60_qmax[c60_i95] = c60_dv17[c60_i95];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c60_sfEvent, 170U);
  for (c60_i96 = 0; c60_i96 < 34; c60_i96++) {
    c60_dqmin[c60_i96] = c60_dv18[c60_i96];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c60_sfEvent, 225U);
  for (c60_i97 = 0; c60_i97 < 34; c60_i97++) {
    c60_dqmax[c60_i97] = c60_dv19[c60_i97];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c60_sfEvent, 280);
  for (c60_i98 = 0; c60_i98 < 34; c60_i98++) {
    c60_qminv[c60_i98] = c60_dv20[c60_i98];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c60_sfEvent, 335);
  for (c60_i99 = 0; c60_i99 < 34; c60_i99++) {
    c60_qmaxv[c60_i99] = c60_dv21[c60_i99];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c60_sfEvent, 392);
  for (c60_i100 = 0; c60_i100 < 13; c60_i100++) {
    c60_b[c60_i100] = c60_b_q[c60_i100];
  }

  c60_b_eml_scalar_eg(chartInstance);
  c60_b_eml_scalar_eg(chartInstance);
  for (c60_i101 = 0; c60_i101 < 34; c60_i101++) {
    c60_y[c60_i101] = 0.0;
  }

  for (c60_i102 = 0; c60_i102 < 442; c60_i102++) {
    c60_b_a[c60_i102] = c60_a[c60_i102];
  }

  for (c60_i103 = 0; c60_i103 < 13; c60_i103++) {
    c60_b_b[c60_i103] = c60_b[c60_i103];
  }

  c60_b_eml_xgemm(chartInstance, c60_b_a, c60_b_b, c60_y);
  for (c60_i104 = 0; c60_i104 < 34; c60_i104++) {
    c60_y[c60_i104] *= 180.0;
  }

  for (c60_i105 = 0; c60_i105 < 34; c60_i105++) {
    c60_qbar[c60_i105] = c60_y[c60_i105] / 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c60_sfEvent, 393);
  for (c60_i106 = 0; c60_i106 < 13; c60_i106++) {
    c60_b[c60_i106] = c60_b_dq[c60_i106];
  }

  c60_b_eml_scalar_eg(chartInstance);
  c60_b_eml_scalar_eg(chartInstance);
  for (c60_i107 = 0; c60_i107 < 34; c60_i107++) {
    c60_y[c60_i107] = 0.0;
  }

  for (c60_i108 = 0; c60_i108 < 442; c60_i108++) {
    c60_c_a[c60_i108] = c60_a[c60_i108];
  }

  for (c60_i109 = 0; c60_i109 < 13; c60_i109++) {
    c60_c_b[c60_i109] = c60_b[c60_i109];
  }

  c60_b_eml_xgemm(chartInstance, c60_c_a, c60_c_b, c60_y);
  for (c60_i110 = 0; c60_i110 < 34; c60_i110++) {
    c60_y[c60_i110] *= 180.0;
  }

  for (c60_i111 = 0; c60_i111 < 34; c60_i111++) {
    c60_dqbar[c60_i111] = c60_y[c60_i111] / 3.1415926535897931;
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c60_sfEvent, 394);
  for (c60_i112 = 0; c60_i112 < 34; c60_i112++) {
    c60_bv10[c60_i112] = (c60_qbar[c60_i112] < c60_qmin[c60_i112]);
  }

  for (c60_i113 = 0; c60_i113 < 34; c60_i113++) {
    c60_bv11[c60_i113] = (c60_qbar[c60_i113] > c60_qmax[c60_i113]);
  }

  for (c60_i114 = 0; c60_i114 < 34; c60_i114++) {
    c60_bv10[c60_i114] = (c60_bv10[c60_i114] || c60_bv11[c60_i114]);
  }

  for (c60_i115 = 0; c60_i115 < 34; c60_i115++) {
    c60_bv11[c60_i115] = (c60_dqbar[c60_i115] < c60_dqmin[c60_i115]);
  }

  for (c60_i116 = 0; c60_i116 < 34; c60_i116++) {
    c60_bv10[c60_i116] = (c60_bv10[c60_i116] || c60_bv11[c60_i116]);
  }

  for (c60_i117 = 0; c60_i117 < 34; c60_i117++) {
    c60_bv11[c60_i117] = (c60_dqbar[c60_i117] > c60_dqmax[c60_i117]);
  }

  for (c60_i118 = 0; c60_i118 < 34; c60_i118++) {
    c60_bv10[c60_i118] = (c60_bv10[c60_i118] || c60_bv11[c60_i118]);
  }

  for (c60_i119 = 0; c60_i119 < 34; c60_i119++) {
    c60_bv11[c60_i119] = (c60_dqbar[c60_i119] * (c60_qminv[c60_i119] -
      c60_qmin[c60_i119]) < c60_dqmin[c60_i119] * (c60_qbar[c60_i119] -
      c60_qmin[c60_i119]));
  }

  for (c60_i120 = 0; c60_i120 < 34; c60_i120++) {
    c60_bv10[c60_i120] = (c60_bv10[c60_i120] || c60_bv11[c60_i120]);
  }

  for (c60_i121 = 0; c60_i121 < 34; c60_i121++) {
    c60_bv11[c60_i121] = (c60_dqbar[c60_i121] * (c60_qmax[c60_i121] -
      c60_qmaxv[c60_i121]) > c60_dqmax[c60_i121] * (c60_qmax[c60_i121] -
      c60_qbar[c60_i121]));
  }

  for (c60_i122 = 0; c60_i122 < 34; c60_i122++) {
    c60_violation[c60_i122] = (c60_bv10[c60_i122] || c60_bv11[c60_i122]);
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c60_sfEvent, -394);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c60_machineNumber, uint32_T
  c60_chartNumber, uint32_T c60_instanceNumber)
{
  (void)c60_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c60_chartNumber, c60_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\DAQ\\Safety\\MARLOSafety_ATRIAS.m"));
  _SFD_SCRIPT_TRANSLATION(c60_chartNumber, c60_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\DAQ\\Safety\\MARLOBasicSafetyLimits2.m"));
  _SFD_SCRIPT_TRANSLATION(c60_chartNumber, c60_instanceNumber, 2U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\DAQ\\Safety\\MARLOBasicSafetyLimits3.m"));
  _SFD_SCRIPT_TRANSLATION(c60_chartNumber, c60_instanceNumber, 3U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\DAQ\\Safety\\MARLOBasicSafetyLimits.m"));
}

static const mxArray *c60_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData)
{
  const mxArray *c60_mxArrayOutData = NULL;
  real_T c60_u;
  const mxArray *c60_y = NULL;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_mxArrayOutData = NULL;
  c60_u = *(real_T *)c60_inData;
  c60_y = NULL;
  sf_mex_assign(&c60_y, sf_mex_create("y", &c60_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c60_mxArrayOutData, c60_y, false);
  return c60_mxArrayOutData;
}

static real_T c60_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_b_SafetyCountOut, const char_T
  *c60_identifier)
{
  real_T c60_y;
  emlrtMsgIdentifier c60_thisId;
  c60_thisId.fIdentifier = c60_identifier;
  c60_thisId.fParent = NULL;
  c60_y = c60_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c60_b_SafetyCountOut),
    &c60_thisId);
  sf_mex_destroy(&c60_b_SafetyCountOut);
  return c60_y;
}

static real_T c60_b_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId)
{
  real_T c60_y;
  real_T c60_d0;
  (void)chartInstance;
  sf_mex_import(c60_parentId, sf_mex_dup(c60_u), &c60_d0, 1, 0, 0U, 0, 0U, 0);
  c60_y = c60_d0;
  sf_mex_destroy(&c60_u);
  return c60_y;
}

static void c60_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData)
{
  const mxArray *c60_b_SafetyCountOut;
  const char_T *c60_identifier;
  emlrtMsgIdentifier c60_thisId;
  real_T c60_y;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_b_SafetyCountOut = sf_mex_dup(c60_mxArrayInData);
  c60_identifier = c60_varName;
  c60_thisId.fIdentifier = c60_identifier;
  c60_thisId.fParent = NULL;
  c60_y = c60_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c60_b_SafetyCountOut),
    &c60_thisId);
  sf_mex_destroy(&c60_b_SafetyCountOut);
  *(real_T *)c60_outData = c60_y;
  sf_mex_destroy(&c60_mxArrayInData);
}

static const mxArray *c60_b_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData)
{
  const mxArray *c60_mxArrayOutData = NULL;
  int32_T c60_i123;
  real_T c60_b_inData[6];
  int32_T c60_i124;
  real_T c60_u[6];
  const mxArray *c60_y = NULL;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_mxArrayOutData = NULL;
  for (c60_i123 = 0; c60_i123 < 6; c60_i123++) {
    c60_b_inData[c60_i123] = (*(real_T (*)[6])c60_inData)[c60_i123];
  }

  for (c60_i124 = 0; c60_i124 < 6; c60_i124++) {
    c60_u[c60_i124] = c60_b_inData[c60_i124];
  }

  c60_y = NULL;
  sf_mex_assign(&c60_y, sf_mex_create("y", c60_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c60_mxArrayOutData, c60_y, false);
  return c60_mxArrayOutData;
}

static void c60_c_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_b_MotorCurrentCommandSafe, const char_T
  *c60_identifier, real_T c60_y[6])
{
  emlrtMsgIdentifier c60_thisId;
  c60_thisId.fIdentifier = c60_identifier;
  c60_thisId.fParent = NULL;
  c60_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c60_b_MotorCurrentCommandSafe),
    &c60_thisId, c60_y);
  sf_mex_destroy(&c60_b_MotorCurrentCommandSafe);
}

static void c60_d_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId,
  real_T c60_y[6])
{
  real_T c60_dv22[6];
  int32_T c60_i125;
  (void)chartInstance;
  sf_mex_import(c60_parentId, sf_mex_dup(c60_u), c60_dv22, 1, 0, 0U, 1, 0U, 1, 6);
  for (c60_i125 = 0; c60_i125 < 6; c60_i125++) {
    c60_y[c60_i125] = c60_dv22[c60_i125];
  }

  sf_mex_destroy(&c60_u);
}

static void c60_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData)
{
  const mxArray *c60_b_MotorCurrentCommandSafe;
  const char_T *c60_identifier;
  emlrtMsgIdentifier c60_thisId;
  real_T c60_y[6];
  int32_T c60_i126;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_b_MotorCurrentCommandSafe = sf_mex_dup(c60_mxArrayInData);
  c60_identifier = c60_varName;
  c60_thisId.fIdentifier = c60_identifier;
  c60_thisId.fParent = NULL;
  c60_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c60_b_MotorCurrentCommandSafe),
    &c60_thisId, c60_y);
  sf_mex_destroy(&c60_b_MotorCurrentCommandSafe);
  for (c60_i126 = 0; c60_i126 < 6; c60_i126++) {
    (*(real_T (*)[6])c60_outData)[c60_i126] = c60_y[c60_i126];
  }

  sf_mex_destroy(&c60_mxArrayInData);
}

static const mxArray *c60_c_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData)
{
  const mxArray *c60_mxArrayOutData = NULL;
  int32_T c60_i127;
  real_T c60_b_inData[13];
  int32_T c60_i128;
  real_T c60_u[13];
  const mxArray *c60_y = NULL;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_mxArrayOutData = NULL;
  for (c60_i127 = 0; c60_i127 < 13; c60_i127++) {
    c60_b_inData[c60_i127] = (*(real_T (*)[13])c60_inData)[c60_i127];
  }

  for (c60_i128 = 0; c60_i128 < 13; c60_i128++) {
    c60_u[c60_i128] = c60_b_inData[c60_i128];
  }

  c60_y = NULL;
  sf_mex_assign(&c60_y, sf_mex_create("y", c60_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_assign(&c60_mxArrayOutData, c60_y, false);
  return c60_mxArrayOutData;
}

static const mxArray *c60_d_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData)
{
  const mxArray *c60_mxArrayOutData = NULL;
  boolean_T c60_u;
  const mxArray *c60_y = NULL;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_mxArrayOutData = NULL;
  c60_u = *(boolean_T *)c60_inData;
  c60_y = NULL;
  sf_mex_assign(&c60_y, sf_mex_create("y", &c60_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c60_mxArrayOutData, c60_y, false);
  return c60_mxArrayOutData;
}

static const mxArray *c60_e_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData)
{
  const mxArray *c60_mxArrayOutData = NULL;
  int32_T c60_i129;
  boolean_T c60_b_inData[34];
  int32_T c60_i130;
  boolean_T c60_u[34];
  const mxArray *c60_y = NULL;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_mxArrayOutData = NULL;
  for (c60_i129 = 0; c60_i129 < 34; c60_i129++) {
    c60_b_inData[c60_i129] = (*(boolean_T (*)[34])c60_inData)[c60_i129];
  }

  for (c60_i130 = 0; c60_i130 < 34; c60_i130++) {
    c60_u[c60_i130] = c60_b_inData[c60_i130];
  }

  c60_y = NULL;
  sf_mex_assign(&c60_y, sf_mex_create("y", c60_u, 11, 0U, 1U, 0U, 1, 34), false);
  sf_mex_assign(&c60_mxArrayOutData, c60_y, false);
  return c60_mxArrayOutData;
}

static void c60_e_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId,
  boolean_T c60_y[34])
{
  boolean_T c60_bv12[34];
  int32_T c60_i131;
  (void)chartInstance;
  sf_mex_import(c60_parentId, sf_mex_dup(c60_u), c60_bv12, 1, 11, 0U, 1, 0U, 1,
                34);
  for (c60_i131 = 0; c60_i131 < 34; c60_i131++) {
    c60_y[c60_i131] = c60_bv12[c60_i131];
  }

  sf_mex_destroy(&c60_u);
}

static void c60_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData)
{
  const mxArray *c60_violation;
  const char_T *c60_identifier;
  emlrtMsgIdentifier c60_thisId;
  boolean_T c60_y[34];
  int32_T c60_i132;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_violation = sf_mex_dup(c60_mxArrayInData);
  c60_identifier = c60_varName;
  c60_thisId.fIdentifier = c60_identifier;
  c60_thisId.fParent = NULL;
  c60_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c60_violation), &c60_thisId,
    c60_y);
  sf_mex_destroy(&c60_violation);
  for (c60_i132 = 0; c60_i132 < 34; c60_i132++) {
    (*(boolean_T (*)[34])c60_outData)[c60_i132] = c60_y[c60_i132];
  }

  sf_mex_destroy(&c60_mxArrayInData);
}

static void c60_f_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId,
  real_T c60_y[13])
{
  real_T c60_dv23[13];
  int32_T c60_i133;
  (void)chartInstance;
  sf_mex_import(c60_parentId, sf_mex_dup(c60_u), c60_dv23, 1, 0, 0U, 1, 0U, 1,
                13);
  for (c60_i133 = 0; c60_i133 < 13; c60_i133++) {
    c60_y[c60_i133] = c60_dv23[c60_i133];
  }

  sf_mex_destroy(&c60_u);
}

static void c60_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData)
{
  const mxArray *c60_b_dq;
  const char_T *c60_identifier;
  emlrtMsgIdentifier c60_thisId;
  real_T c60_y[13];
  int32_T c60_i134;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_b_dq = sf_mex_dup(c60_mxArrayInData);
  c60_identifier = c60_varName;
  c60_thisId.fIdentifier = c60_identifier;
  c60_thisId.fParent = NULL;
  c60_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c60_b_dq), &c60_thisId, c60_y);
  sf_mex_destroy(&c60_b_dq);
  for (c60_i134 = 0; c60_i134 < 13; c60_i134++) {
    (*(real_T (*)[13])c60_outData)[c60_i134] = c60_y[c60_i134];
  }

  sf_mex_destroy(&c60_mxArrayInData);
}

static const mxArray *c60_f_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData)
{
  const mxArray *c60_mxArrayOutData = NULL;
  int32_T c60_i135;
  int32_T c60_i136;
  int32_T c60_i137;
  real_T c60_b_inData[442];
  int32_T c60_i138;
  int32_T c60_i139;
  int32_T c60_i140;
  real_T c60_u[442];
  const mxArray *c60_y = NULL;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_mxArrayOutData = NULL;
  c60_i135 = 0;
  for (c60_i136 = 0; c60_i136 < 13; c60_i136++) {
    for (c60_i137 = 0; c60_i137 < 34; c60_i137++) {
      c60_b_inData[c60_i137 + c60_i135] = (*(real_T (*)[442])c60_inData)
        [c60_i137 + c60_i135];
    }

    c60_i135 += 34;
  }

  c60_i138 = 0;
  for (c60_i139 = 0; c60_i139 < 13; c60_i139++) {
    for (c60_i140 = 0; c60_i140 < 34; c60_i140++) {
      c60_u[c60_i140 + c60_i138] = c60_b_inData[c60_i140 + c60_i138];
    }

    c60_i138 += 34;
  }

  c60_y = NULL;
  sf_mex_assign(&c60_y, sf_mex_create("y", c60_u, 0, 0U, 1U, 0U, 2, 34, 13),
                false);
  sf_mex_assign(&c60_mxArrayOutData, c60_y, false);
  return c60_mxArrayOutData;
}

static const mxArray *c60_g_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData)
{
  const mxArray *c60_mxArrayOutData = NULL;
  int32_T c60_i141;
  real_T c60_b_inData[34];
  int32_T c60_i142;
  real_T c60_u[34];
  const mxArray *c60_y = NULL;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_mxArrayOutData = NULL;
  for (c60_i141 = 0; c60_i141 < 34; c60_i141++) {
    c60_b_inData[c60_i141] = (*(real_T (*)[34])c60_inData)[c60_i141];
  }

  for (c60_i142 = 0; c60_i142 < 34; c60_i142++) {
    c60_u[c60_i142] = c60_b_inData[c60_i142];
  }

  c60_y = NULL;
  sf_mex_assign(&c60_y, sf_mex_create("y", c60_u, 0, 0U, 1U, 0U, 1, 34), false);
  sf_mex_assign(&c60_mxArrayOutData, c60_y, false);
  return c60_mxArrayOutData;
}

static void c60_g_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId,
  real_T c60_y[34])
{
  real_T c60_dv24[34];
  int32_T c60_i143;
  (void)chartInstance;
  sf_mex_import(c60_parentId, sf_mex_dup(c60_u), c60_dv24, 1, 0, 0U, 1, 0U, 1,
                34);
  for (c60_i143 = 0; c60_i143 < 34; c60_i143++) {
    c60_y[c60_i143] = c60_dv24[c60_i143];
  }

  sf_mex_destroy(&c60_u);
}

static void c60_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData)
{
  const mxArray *c60_qmaxv;
  const char_T *c60_identifier;
  emlrtMsgIdentifier c60_thisId;
  real_T c60_y[34];
  int32_T c60_i144;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_qmaxv = sf_mex_dup(c60_mxArrayInData);
  c60_identifier = c60_varName;
  c60_thisId.fIdentifier = c60_identifier;
  c60_thisId.fParent = NULL;
  c60_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c60_qmaxv), &c60_thisId,
    c60_y);
  sf_mex_destroy(&c60_qmaxv);
  for (c60_i144 = 0; c60_i144 < 34; c60_i144++) {
    (*(real_T (*)[34])c60_outData)[c60_i144] = c60_y[c60_i144];
  }

  sf_mex_destroy(&c60_mxArrayInData);
}

static boolean_T c60_h_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId)
{
  boolean_T c60_y;
  boolean_T c60_b2;
  (void)chartInstance;
  sf_mex_import(c60_parentId, sf_mex_dup(c60_u), &c60_b2, 1, 11, 0U, 0, 0U, 0);
  c60_y = c60_b2;
  sf_mex_destroy(&c60_u);
  return c60_y;
}

static void c60_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData)
{
  const mxArray *c60_b_RequestSoftStop;
  const char_T *c60_identifier;
  emlrtMsgIdentifier c60_thisId;
  boolean_T c60_y;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_b_RequestSoftStop = sf_mex_dup(c60_mxArrayInData);
  c60_identifier = c60_varName;
  c60_thisId.fIdentifier = c60_identifier;
  c60_thisId.fParent = NULL;
  c60_y = c60_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c60_b_RequestSoftStop),
    &c60_thisId);
  sf_mex_destroy(&c60_b_RequestSoftStop);
  *(boolean_T *)c60_outData = c60_y;
  sf_mex_destroy(&c60_mxArrayInData);
}

static const mxArray *c60_h_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData)
{
  const mxArray *c60_mxArrayOutData = NULL;
  int32_T c60_i145;
  real_T c60_b_inData[8];
  int32_T c60_i146;
  real_T c60_u[8];
  const mxArray *c60_y = NULL;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_mxArrayOutData = NULL;
  for (c60_i145 = 0; c60_i145 < 8; c60_i145++) {
    c60_b_inData[c60_i145] = (*(real_T (*)[8])c60_inData)[c60_i145];
  }

  for (c60_i146 = 0; c60_i146 < 8; c60_i146++) {
    c60_u[c60_i146] = c60_b_inData[c60_i146];
  }

  c60_y = NULL;
  sf_mex_assign(&c60_y, sf_mex_create("y", c60_u, 0, 0U, 1U, 0U, 2, 1, 8), false);
  sf_mex_assign(&c60_mxArrayOutData, c60_y, false);
  return c60_mxArrayOutData;
}

const mxArray *sf_c60_Walking_ATRIAS_get_eml_resolved_functions_info(void)
{
  const mxArray *c60_nameCaptureInfo = NULL;
  c60_nameCaptureInfo = NULL;
  sf_mex_assign(&c60_nameCaptureInfo, sf_mex_createstruct("structure", 2, 144, 1),
                false);
  c60_info_helper(&c60_nameCaptureInfo);
  c60_b_info_helper(&c60_nameCaptureInfo);
  c60_c_info_helper(&c60_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c60_nameCaptureInfo);
  return c60_nameCaptureInfo;
}

static void c60_info_helper(const mxArray **c60_info)
{
  const mxArray *c60_rhs0 = NULL;
  const mxArray *c60_lhs0 = NULL;
  const mxArray *c60_rhs1 = NULL;
  const mxArray *c60_lhs1 = NULL;
  const mxArray *c60_rhs2 = NULL;
  const mxArray *c60_lhs2 = NULL;
  const mxArray *c60_rhs3 = NULL;
  const mxArray *c60_lhs3 = NULL;
  const mxArray *c60_rhs4 = NULL;
  const mxArray *c60_lhs4 = NULL;
  const mxArray *c60_rhs5 = NULL;
  const mxArray *c60_lhs5 = NULL;
  const mxArray *c60_rhs6 = NULL;
  const mxArray *c60_lhs6 = NULL;
  const mxArray *c60_rhs7 = NULL;
  const mxArray *c60_lhs7 = NULL;
  const mxArray *c60_rhs8 = NULL;
  const mxArray *c60_lhs8 = NULL;
  const mxArray *c60_rhs9 = NULL;
  const mxArray *c60_lhs9 = NULL;
  const mxArray *c60_rhs10 = NULL;
  const mxArray *c60_lhs10 = NULL;
  const mxArray *c60_rhs11 = NULL;
  const mxArray *c60_lhs11 = NULL;
  const mxArray *c60_rhs12 = NULL;
  const mxArray *c60_lhs12 = NULL;
  const mxArray *c60_rhs13 = NULL;
  const mxArray *c60_lhs13 = NULL;
  const mxArray *c60_rhs14 = NULL;
  const mxArray *c60_lhs14 = NULL;
  const mxArray *c60_rhs15 = NULL;
  const mxArray *c60_lhs15 = NULL;
  const mxArray *c60_rhs16 = NULL;
  const mxArray *c60_lhs16 = NULL;
  const mxArray *c60_rhs17 = NULL;
  const mxArray *c60_lhs17 = NULL;
  const mxArray *c60_rhs18 = NULL;
  const mxArray *c60_lhs18 = NULL;
  const mxArray *c60_rhs19 = NULL;
  const mxArray *c60_lhs19 = NULL;
  const mxArray *c60_rhs20 = NULL;
  const mxArray *c60_lhs20 = NULL;
  const mxArray *c60_rhs21 = NULL;
  const mxArray *c60_lhs21 = NULL;
  const mxArray *c60_rhs22 = NULL;
  const mxArray *c60_lhs22 = NULL;
  const mxArray *c60_rhs23 = NULL;
  const mxArray *c60_lhs23 = NULL;
  const mxArray *c60_rhs24 = NULL;
  const mxArray *c60_lhs24 = NULL;
  const mxArray *c60_rhs25 = NULL;
  const mxArray *c60_lhs25 = NULL;
  const mxArray *c60_rhs26 = NULL;
  const mxArray *c60_lhs26 = NULL;
  const mxArray *c60_rhs27 = NULL;
  const mxArray *c60_lhs27 = NULL;
  const mxArray *c60_rhs28 = NULL;
  const mxArray *c60_lhs28 = NULL;
  const mxArray *c60_rhs29 = NULL;
  const mxArray *c60_lhs29 = NULL;
  const mxArray *c60_rhs30 = NULL;
  const mxArray *c60_lhs30 = NULL;
  const mxArray *c60_rhs31 = NULL;
  const mxArray *c60_lhs31 = NULL;
  const mxArray *c60_rhs32 = NULL;
  const mxArray *c60_lhs32 = NULL;
  const mxArray *c60_rhs33 = NULL;
  const mxArray *c60_lhs33 = NULL;
  const mxArray *c60_rhs34 = NULL;
  const mxArray *c60_lhs34 = NULL;
  const mxArray *c60_rhs35 = NULL;
  const mxArray *c60_lhs35 = NULL;
  const mxArray *c60_rhs36 = NULL;
  const mxArray *c60_lhs36 = NULL;
  const mxArray *c60_rhs37 = NULL;
  const mxArray *c60_lhs37 = NULL;
  const mxArray *c60_rhs38 = NULL;
  const mxArray *c60_lhs38 = NULL;
  const mxArray *c60_rhs39 = NULL;
  const mxArray *c60_lhs39 = NULL;
  const mxArray *c60_rhs40 = NULL;
  const mxArray *c60_lhs40 = NULL;
  const mxArray *c60_rhs41 = NULL;
  const mxArray *c60_lhs41 = NULL;
  const mxArray *c60_rhs42 = NULL;
  const mxArray *c60_lhs42 = NULL;
  const mxArray *c60_rhs43 = NULL;
  const mxArray *c60_lhs43 = NULL;
  const mxArray *c60_rhs44 = NULL;
  const mxArray *c60_lhs44 = NULL;
  const mxArray *c60_rhs45 = NULL;
  const mxArray *c60_lhs45 = NULL;
  const mxArray *c60_rhs46 = NULL;
  const mxArray *c60_lhs46 = NULL;
  const mxArray *c60_rhs47 = NULL;
  const mxArray *c60_lhs47 = NULL;
  const mxArray *c60_rhs48 = NULL;
  const mxArray *c60_lhs48 = NULL;
  const mxArray *c60_rhs49 = NULL;
  const mxArray *c60_lhs49 = NULL;
  const mxArray *c60_rhs50 = NULL;
  const mxArray *c60_lhs50 = NULL;
  const mxArray *c60_rhs51 = NULL;
  const mxArray *c60_lhs51 = NULL;
  const mxArray *c60_rhs52 = NULL;
  const mxArray *c60_lhs52 = NULL;
  const mxArray *c60_rhs53 = NULL;
  const mxArray *c60_lhs53 = NULL;
  const mxArray *c60_rhs54 = NULL;
  const mxArray *c60_lhs54 = NULL;
  const mxArray *c60_rhs55 = NULL;
  const mxArray *c60_lhs55 = NULL;
  const mxArray *c60_rhs56 = NULL;
  const mxArray *c60_lhs56 = NULL;
  const mxArray *c60_rhs57 = NULL;
  const mxArray *c60_lhs57 = NULL;
  const mxArray *c60_rhs58 = NULL;
  const mxArray *c60_lhs58 = NULL;
  const mxArray *c60_rhs59 = NULL;
  const mxArray *c60_lhs59 = NULL;
  const mxArray *c60_rhs60 = NULL;
  const mxArray *c60_lhs60 = NULL;
  const mxArray *c60_rhs61 = NULL;
  const mxArray *c60_lhs61 = NULL;
  const mxArray *c60_rhs62 = NULL;
  const mxArray *c60_lhs62 = NULL;
  const mxArray *c60_rhs63 = NULL;
  const mxArray *c60_lhs63 = NULL;
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("MARLOSafety_ATRIAS"), "name",
                  "name", 0);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1469047905U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c60_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("colon"), "name", "name", 1);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c60_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("colon"), "name", "name", 2);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c60_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c60_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                  "context", "context", 4);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("isfinite"), "name", "name",
                  4);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c60_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c60_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("isinf"), "name", "name", 6);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c60_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c60_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("isnan"), "name", "name", 8);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c60_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c60_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                  "context", "context", 10);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("floor"), "name", "name", 10);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c60_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c60_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 12);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c60_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                  "context", "context", 13);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 13);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c60_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 14);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c60_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                  "context", "context", 15);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("flintmax"), "name", "name",
                  15);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1348213516U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c60_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 16);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c60_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                  "context", "context", 17);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("abs"), "name", "name", 17);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c60_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 18);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c60_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 19);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c60_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 20);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("realmax"), "name", "name",
                  20);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c60_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_realmax"), "name",
                  "name", 21);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c60_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 22);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c60_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 23);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("mrdivide"), "name", "name",
                  23);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c60_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 24);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 24);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c60_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 25);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("rdivide"), "name", "name",
                  25);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c60_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 26);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c60_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 27);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c60_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_div"), "name", "name",
                  28);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c60_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 29);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c60_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 30);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("floor"), "name", "name", 30);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c60_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 31);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 31);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c60_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 32);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("intmax"), "name", "name", 32);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c60_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 33);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c60_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("power"), "name", "name", 34);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395346506U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c60_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 35);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c60_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 36);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 36);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c60_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 37);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 37);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c60_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 38);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c60_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 39);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("floor"), "name", "name", 39);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c60_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 40);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_error"), "name", "name",
                  40);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1343851958U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c60_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 41);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 41);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c60_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("mpower"), "name", "name", 42);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731878U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c60_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 43);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c60_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 44);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("ismatrix"), "name", "name",
                  44);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1331326458U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c60_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("power"), "name", "name", 45);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395346506U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c60_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("MARLOBasicSafetyLimits2"),
                  "name", "name", 46);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOBasicSafetyLimits2.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1444271055U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c60_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOBasicSafetyLimits2.m"),
                  "context", "context", 47);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 47);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c60_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 48);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 48);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c60_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 49);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 49);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c60_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 50);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 50);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c60_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 51);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  51);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c60_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 52);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c60_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 53);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 53);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c60_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 54);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 54);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c60_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 55);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 55);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c60_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 56);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 56);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c60_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 57);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 57);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c60_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 58);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 58);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c60_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOBasicSafetyLimits2.m"),
                  "context", "context", 59);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("mrdivide"), "name", "name",
                  59);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 59);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c60_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "context", "context", 60);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("MARLOBasicSafetyLimits3"),
                  "name", "name", 60);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOBasicSafetyLimits3.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1469054443U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c60_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOBasicSafetyLimits3.m"),
                  "context", "context", 61);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 61);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c60_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOBasicSafetyLimits3.m"),
                  "context", "context", 62);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("mrdivide"), "name", "name",
                  62);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c60_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "context", "context", 63);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("MARLOBasicSafetyLimits"),
                  "name", "name", 63);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOBasicSafetyLimits.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1444271055U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c60_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c60_rhs0);
  sf_mex_destroy(&c60_lhs0);
  sf_mex_destroy(&c60_rhs1);
  sf_mex_destroy(&c60_lhs1);
  sf_mex_destroy(&c60_rhs2);
  sf_mex_destroy(&c60_lhs2);
  sf_mex_destroy(&c60_rhs3);
  sf_mex_destroy(&c60_lhs3);
  sf_mex_destroy(&c60_rhs4);
  sf_mex_destroy(&c60_lhs4);
  sf_mex_destroy(&c60_rhs5);
  sf_mex_destroy(&c60_lhs5);
  sf_mex_destroy(&c60_rhs6);
  sf_mex_destroy(&c60_lhs6);
  sf_mex_destroy(&c60_rhs7);
  sf_mex_destroy(&c60_lhs7);
  sf_mex_destroy(&c60_rhs8);
  sf_mex_destroy(&c60_lhs8);
  sf_mex_destroy(&c60_rhs9);
  sf_mex_destroy(&c60_lhs9);
  sf_mex_destroy(&c60_rhs10);
  sf_mex_destroy(&c60_lhs10);
  sf_mex_destroy(&c60_rhs11);
  sf_mex_destroy(&c60_lhs11);
  sf_mex_destroy(&c60_rhs12);
  sf_mex_destroy(&c60_lhs12);
  sf_mex_destroy(&c60_rhs13);
  sf_mex_destroy(&c60_lhs13);
  sf_mex_destroy(&c60_rhs14);
  sf_mex_destroy(&c60_lhs14);
  sf_mex_destroy(&c60_rhs15);
  sf_mex_destroy(&c60_lhs15);
  sf_mex_destroy(&c60_rhs16);
  sf_mex_destroy(&c60_lhs16);
  sf_mex_destroy(&c60_rhs17);
  sf_mex_destroy(&c60_lhs17);
  sf_mex_destroy(&c60_rhs18);
  sf_mex_destroy(&c60_lhs18);
  sf_mex_destroy(&c60_rhs19);
  sf_mex_destroy(&c60_lhs19);
  sf_mex_destroy(&c60_rhs20);
  sf_mex_destroy(&c60_lhs20);
  sf_mex_destroy(&c60_rhs21);
  sf_mex_destroy(&c60_lhs21);
  sf_mex_destroy(&c60_rhs22);
  sf_mex_destroy(&c60_lhs22);
  sf_mex_destroy(&c60_rhs23);
  sf_mex_destroy(&c60_lhs23);
  sf_mex_destroy(&c60_rhs24);
  sf_mex_destroy(&c60_lhs24);
  sf_mex_destroy(&c60_rhs25);
  sf_mex_destroy(&c60_lhs25);
  sf_mex_destroy(&c60_rhs26);
  sf_mex_destroy(&c60_lhs26);
  sf_mex_destroy(&c60_rhs27);
  sf_mex_destroy(&c60_lhs27);
  sf_mex_destroy(&c60_rhs28);
  sf_mex_destroy(&c60_lhs28);
  sf_mex_destroy(&c60_rhs29);
  sf_mex_destroy(&c60_lhs29);
  sf_mex_destroy(&c60_rhs30);
  sf_mex_destroy(&c60_lhs30);
  sf_mex_destroy(&c60_rhs31);
  sf_mex_destroy(&c60_lhs31);
  sf_mex_destroy(&c60_rhs32);
  sf_mex_destroy(&c60_lhs32);
  sf_mex_destroy(&c60_rhs33);
  sf_mex_destroy(&c60_lhs33);
  sf_mex_destroy(&c60_rhs34);
  sf_mex_destroy(&c60_lhs34);
  sf_mex_destroy(&c60_rhs35);
  sf_mex_destroy(&c60_lhs35);
  sf_mex_destroy(&c60_rhs36);
  sf_mex_destroy(&c60_lhs36);
  sf_mex_destroy(&c60_rhs37);
  sf_mex_destroy(&c60_lhs37);
  sf_mex_destroy(&c60_rhs38);
  sf_mex_destroy(&c60_lhs38);
  sf_mex_destroy(&c60_rhs39);
  sf_mex_destroy(&c60_lhs39);
  sf_mex_destroy(&c60_rhs40);
  sf_mex_destroy(&c60_lhs40);
  sf_mex_destroy(&c60_rhs41);
  sf_mex_destroy(&c60_lhs41);
  sf_mex_destroy(&c60_rhs42);
  sf_mex_destroy(&c60_lhs42);
  sf_mex_destroy(&c60_rhs43);
  sf_mex_destroy(&c60_lhs43);
  sf_mex_destroy(&c60_rhs44);
  sf_mex_destroy(&c60_lhs44);
  sf_mex_destroy(&c60_rhs45);
  sf_mex_destroy(&c60_lhs45);
  sf_mex_destroy(&c60_rhs46);
  sf_mex_destroy(&c60_lhs46);
  sf_mex_destroy(&c60_rhs47);
  sf_mex_destroy(&c60_lhs47);
  sf_mex_destroy(&c60_rhs48);
  sf_mex_destroy(&c60_lhs48);
  sf_mex_destroy(&c60_rhs49);
  sf_mex_destroy(&c60_lhs49);
  sf_mex_destroy(&c60_rhs50);
  sf_mex_destroy(&c60_lhs50);
  sf_mex_destroy(&c60_rhs51);
  sf_mex_destroy(&c60_lhs51);
  sf_mex_destroy(&c60_rhs52);
  sf_mex_destroy(&c60_lhs52);
  sf_mex_destroy(&c60_rhs53);
  sf_mex_destroy(&c60_lhs53);
  sf_mex_destroy(&c60_rhs54);
  sf_mex_destroy(&c60_lhs54);
  sf_mex_destroy(&c60_rhs55);
  sf_mex_destroy(&c60_lhs55);
  sf_mex_destroy(&c60_rhs56);
  sf_mex_destroy(&c60_lhs56);
  sf_mex_destroy(&c60_rhs57);
  sf_mex_destroy(&c60_lhs57);
  sf_mex_destroy(&c60_rhs58);
  sf_mex_destroy(&c60_lhs58);
  sf_mex_destroy(&c60_rhs59);
  sf_mex_destroy(&c60_lhs59);
  sf_mex_destroy(&c60_rhs60);
  sf_mex_destroy(&c60_lhs60);
  sf_mex_destroy(&c60_rhs61);
  sf_mex_destroy(&c60_lhs61);
  sf_mex_destroy(&c60_rhs62);
  sf_mex_destroy(&c60_lhs62);
  sf_mex_destroy(&c60_rhs63);
  sf_mex_destroy(&c60_lhs63);
}

static const mxArray *c60_emlrt_marshallOut(const char * c60_u)
{
  const mxArray *c60_y = NULL;
  c60_y = NULL;
  sf_mex_assign(&c60_y, sf_mex_create("y", c60_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c60_u)), false);
  return c60_y;
}

static const mxArray *c60_b_emlrt_marshallOut(const uint32_T c60_u)
{
  const mxArray *c60_y = NULL;
  c60_y = NULL;
  sf_mex_assign(&c60_y, sf_mex_create("y", &c60_u, 7, 0U, 0U, 0U, 0), false);
  return c60_y;
}

static void c60_b_info_helper(const mxArray **c60_info)
{
  const mxArray *c60_rhs64 = NULL;
  const mxArray *c60_lhs64 = NULL;
  const mxArray *c60_rhs65 = NULL;
  const mxArray *c60_lhs65 = NULL;
  const mxArray *c60_rhs66 = NULL;
  const mxArray *c60_lhs66 = NULL;
  const mxArray *c60_rhs67 = NULL;
  const mxArray *c60_lhs67 = NULL;
  const mxArray *c60_rhs68 = NULL;
  const mxArray *c60_lhs68 = NULL;
  const mxArray *c60_rhs69 = NULL;
  const mxArray *c60_lhs69 = NULL;
  const mxArray *c60_rhs70 = NULL;
  const mxArray *c60_lhs70 = NULL;
  const mxArray *c60_rhs71 = NULL;
  const mxArray *c60_lhs71 = NULL;
  const mxArray *c60_rhs72 = NULL;
  const mxArray *c60_lhs72 = NULL;
  const mxArray *c60_rhs73 = NULL;
  const mxArray *c60_lhs73 = NULL;
  const mxArray *c60_rhs74 = NULL;
  const mxArray *c60_lhs74 = NULL;
  const mxArray *c60_rhs75 = NULL;
  const mxArray *c60_lhs75 = NULL;
  const mxArray *c60_rhs76 = NULL;
  const mxArray *c60_lhs76 = NULL;
  const mxArray *c60_rhs77 = NULL;
  const mxArray *c60_lhs77 = NULL;
  const mxArray *c60_rhs78 = NULL;
  const mxArray *c60_lhs78 = NULL;
  const mxArray *c60_rhs79 = NULL;
  const mxArray *c60_lhs79 = NULL;
  const mxArray *c60_rhs80 = NULL;
  const mxArray *c60_lhs80 = NULL;
  const mxArray *c60_rhs81 = NULL;
  const mxArray *c60_lhs81 = NULL;
  const mxArray *c60_rhs82 = NULL;
  const mxArray *c60_lhs82 = NULL;
  const mxArray *c60_rhs83 = NULL;
  const mxArray *c60_lhs83 = NULL;
  const mxArray *c60_rhs84 = NULL;
  const mxArray *c60_lhs84 = NULL;
  const mxArray *c60_rhs85 = NULL;
  const mxArray *c60_lhs85 = NULL;
  const mxArray *c60_rhs86 = NULL;
  const mxArray *c60_lhs86 = NULL;
  const mxArray *c60_rhs87 = NULL;
  const mxArray *c60_lhs87 = NULL;
  const mxArray *c60_rhs88 = NULL;
  const mxArray *c60_lhs88 = NULL;
  const mxArray *c60_rhs89 = NULL;
  const mxArray *c60_lhs89 = NULL;
  const mxArray *c60_rhs90 = NULL;
  const mxArray *c60_lhs90 = NULL;
  const mxArray *c60_rhs91 = NULL;
  const mxArray *c60_lhs91 = NULL;
  const mxArray *c60_rhs92 = NULL;
  const mxArray *c60_lhs92 = NULL;
  const mxArray *c60_rhs93 = NULL;
  const mxArray *c60_lhs93 = NULL;
  const mxArray *c60_rhs94 = NULL;
  const mxArray *c60_lhs94 = NULL;
  const mxArray *c60_rhs95 = NULL;
  const mxArray *c60_lhs95 = NULL;
  const mxArray *c60_rhs96 = NULL;
  const mxArray *c60_lhs96 = NULL;
  const mxArray *c60_rhs97 = NULL;
  const mxArray *c60_lhs97 = NULL;
  const mxArray *c60_rhs98 = NULL;
  const mxArray *c60_lhs98 = NULL;
  const mxArray *c60_rhs99 = NULL;
  const mxArray *c60_lhs99 = NULL;
  const mxArray *c60_rhs100 = NULL;
  const mxArray *c60_lhs100 = NULL;
  const mxArray *c60_rhs101 = NULL;
  const mxArray *c60_lhs101 = NULL;
  const mxArray *c60_rhs102 = NULL;
  const mxArray *c60_lhs102 = NULL;
  const mxArray *c60_rhs103 = NULL;
  const mxArray *c60_lhs103 = NULL;
  const mxArray *c60_rhs104 = NULL;
  const mxArray *c60_lhs104 = NULL;
  const mxArray *c60_rhs105 = NULL;
  const mxArray *c60_lhs105 = NULL;
  const mxArray *c60_rhs106 = NULL;
  const mxArray *c60_lhs106 = NULL;
  const mxArray *c60_rhs107 = NULL;
  const mxArray *c60_lhs107 = NULL;
  const mxArray *c60_rhs108 = NULL;
  const mxArray *c60_lhs108 = NULL;
  const mxArray *c60_rhs109 = NULL;
  const mxArray *c60_lhs109 = NULL;
  const mxArray *c60_rhs110 = NULL;
  const mxArray *c60_lhs110 = NULL;
  const mxArray *c60_rhs111 = NULL;
  const mxArray *c60_lhs111 = NULL;
  const mxArray *c60_rhs112 = NULL;
  const mxArray *c60_lhs112 = NULL;
  const mxArray *c60_rhs113 = NULL;
  const mxArray *c60_lhs113 = NULL;
  const mxArray *c60_rhs114 = NULL;
  const mxArray *c60_lhs114 = NULL;
  const mxArray *c60_rhs115 = NULL;
  const mxArray *c60_lhs115 = NULL;
  const mxArray *c60_rhs116 = NULL;
  const mxArray *c60_lhs116 = NULL;
  const mxArray *c60_rhs117 = NULL;
  const mxArray *c60_lhs117 = NULL;
  const mxArray *c60_rhs118 = NULL;
  const mxArray *c60_lhs118 = NULL;
  const mxArray *c60_rhs119 = NULL;
  const mxArray *c60_lhs119 = NULL;
  const mxArray *c60_rhs120 = NULL;
  const mxArray *c60_lhs120 = NULL;
  const mxArray *c60_rhs121 = NULL;
  const mxArray *c60_lhs121 = NULL;
  const mxArray *c60_rhs122 = NULL;
  const mxArray *c60_lhs122 = NULL;
  const mxArray *c60_rhs123 = NULL;
  const mxArray *c60_lhs123 = NULL;
  const mxArray *c60_rhs124 = NULL;
  const mxArray *c60_lhs124 = NULL;
  const mxArray *c60_rhs125 = NULL;
  const mxArray *c60_lhs125 = NULL;
  const mxArray *c60_rhs126 = NULL;
  const mxArray *c60_lhs126 = NULL;
  const mxArray *c60_rhs127 = NULL;
  const mxArray *c60_lhs127 = NULL;
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOBasicSafetyLimits.m"),
                  "context", "context", 64);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 64);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c60_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOBasicSafetyLimits.m"),
                  "context", "context", 65);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("mrdivide"), "name", "name",
                  65);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 65);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c60_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "context", "context", 66);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("sum"), "name", "name", 66);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "resolved",
                  "resolved", 66);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395948306U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c60_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 67);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 67);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c60_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sum.m"), "context",
                  "context", 68);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("sumprod"), "name", "name",
                  68);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395948302U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c60_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 69);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 69);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c60_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 70);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 70);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c60_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 71);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("process_sumprod_inputs"),
                  "name", "name", 71);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395948302U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c60_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "context", "context", 72);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.narginchk"),
                  "name", "name", 72);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363732558U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c60_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "context", "context", 73);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("floor"), "name", "name", 73);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 73);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c60_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                  "context", "context", 74);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 74);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c60_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "context", "context", 75);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 75);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c60_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "context", "context", 76);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 76);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c60_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                  "context", "context", 77);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 77);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 77);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c60_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 78);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("isequal"), "name", "name",
                  78);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 78);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1286840358U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c60_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 79);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 79);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c60_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/sumprod.m"),
                  "context", "context", 80);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("combine_vector_elements"),
                  "name", "name", 80);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 80);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395948302U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c60_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"),
                  "context", "context", 81);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 81);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 81);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c60_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 82);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("isfi"), "name", "name", 82);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 82);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 82);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c60_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 83);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 83);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 83);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c60_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 84);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("intmax"), "name", "name", 84);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 84);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c60_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 85);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("intmin"), "name", "name", 85);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 85);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c60_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 86);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 86);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c60_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "context", "context", 87);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("isfinite"), "name", "name",
                  87);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 87);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c60_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "context", "context", 88);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("any"), "name", "name", 88);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m"), "resolved",
                  "resolved", 88);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c60_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m"), "context", "context",
                  89);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 89);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c60_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m"), "context", "context",
                  90);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 90);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 90);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c60_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m"), "context", "context",
                  91);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.allOrAny"),
                  "name", "name", 91);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "resolved", "resolved", 91);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1372604758U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c60_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 92);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 92);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 92);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c60_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 93);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("isequal"), "name", "name",
                  93);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 93);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1286840358U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c60_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 94);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 94);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 94);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c60_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 95);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("isnan"), "name", "name", 95);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 95);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 95);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c60_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 96);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 96);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 96);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 96);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c60_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "context", "context", 97);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("abs"), "name", "name", 97);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 97);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 97);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c60_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "context", "context", 98);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("ismember"), "name", "name",
                  98);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 98);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/ismember.m"), "resolved",
                  "resolved", 98);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731876U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c60_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/ismember.m"), "context",
                  "context", 99);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 99);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 99);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 99);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c60_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/ismember.m!local_ismember"),
                  "context", "context", 100);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("issorted"), "name", "name",
                  100);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 100);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/issorted.m"), "resolved",
                  "resolved", 100);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1286840294U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c60_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs100), "rhs",
                  "rhs", 100);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs100), "lhs",
                  "lhs", 100);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/issorted.m"), "context",
                  "context", 101);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 101);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 101);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c60_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs101), "rhs",
                  "rhs", 101);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs101), "lhs",
                  "lhs", 101);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 102);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 102);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 102);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c60_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs102), "rhs",
                  "rhs", 102);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs102), "lhs",
                  "lhs", 102);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/issorted.m"), "context",
                  "context", 103);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 103);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 103);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c60_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs103), "rhs",
                  "rhs", 103);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs103), "lhs",
                  "lhs", 103);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/issorted.m"), "context",
                  "context", 104);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 104);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 104);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 104);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c60_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs104), "rhs",
                  "rhs", 104);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs104), "lhs",
                  "lhs", 104);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 105);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 105);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 105);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c60_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs105), "rhs",
                  "rhs", 105);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs105), "lhs",
                  "lhs", 105);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/issorted.m"), "context",
                  "context", 106);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_sort_le"), "name",
                  "name", 106);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m"), "resolved",
                  "resolved", 106);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1292212110U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c60_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs106), "rhs",
                  "rhs", 106);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs106), "lhs",
                  "lhs", 106);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m!eml_sort_ascending_le"),
                  "context", "context", 107);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_relop"), "name", "name",
                  107);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 107);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 107);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1342472782U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c60_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs107), "rhs",
                  "rhs", 107);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs107), "lhs",
                  "lhs", 107);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m!eml_sort_ascending_le"),
                  "context", "context", 108);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("isnan"), "name", "name", 108);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 108);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c60_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs108), "rhs",
                  "rhs", 108);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs108), "lhs",
                  "lhs", 108);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/ismember.m!local_ismember"),
                  "context", "context", 109);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_error"), "name", "name",
                  109);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 109);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1343851958U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c60_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs109), "rhs",
                  "rhs", 109);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs109), "lhs",
                  "lhs", 109);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/ismember.m!local_ismember"),
                  "context", "context", 110);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 110);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 110);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c60_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs110), "rhs",
                  "rhs", 110);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs110), "lhs",
                  "lhs", 110);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/ismember.m!bsearch"),
                  "context", "context", 111);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 111);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 111);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c60_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs111), "rhs",
                  "rhs", 111);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs111), "lhs",
                  "lhs", 111);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/ismember.m!bsearch"),
                  "context", "context", 112);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 112);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 112);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 112);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c60_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs112), "rhs",
                  "rhs", 112);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs112), "lhs",
                  "lhs", 112);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 113);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 113);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 113);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 113);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c60_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs113), "rhs",
                  "rhs", 113);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs113), "lhs",
                  "lhs", 113);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 114);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 114);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 114);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c60_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs114), "rhs",
                  "rhs", 114);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs114), "lhs",
                  "lhs", 114);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 115);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 115);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 115);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 115);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c60_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs115), "rhs",
                  "rhs", 115);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs115), "lhs",
                  "lhs", 115);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/ismember.m!bsearch"),
                  "context", "context", 116);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_safe_eq"), "name",
                  "name", 116);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "resolved",
                  "resolved", 116);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1383898886U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c60_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs116), "rhs",
                  "rhs", 116);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs116), "lhs",
                  "lhs", 116);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "context",
                  "context", 117);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("abs"), "name", "name", 117);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 117);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c60_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs117), "rhs",
                  "rhs", 117);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs117), "lhs",
                  "lhs", 117);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "context",
                  "context", 118);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("mrdivide"), "name", "name",
                  118);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 118);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 118);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c60_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs118), "rhs",
                  "rhs", 118);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs118), "lhs",
                  "lhs", 118);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "context",
                  "context", 119);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eps"), "name", "name", 119);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 119);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 119);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c60_rhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs119), "rhs",
                  "rhs", 119);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs119), "lhs",
                  "lhs", 119);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 120);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_mantissa_nbits"), "name",
                  "name", 120);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 120);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m"),
                  "resolved", "resolved", 120);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c60_rhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs120), "rhs",
                  "rhs", 120);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs120), "lhs",
                  "lhs", 120);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_mantissa_nbits.m"),
                  "context", "context", 121);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 121);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 121);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c60_rhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs121), "rhs",
                  "rhs", 121);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs121), "lhs",
                  "lhs", 121);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 122);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 122);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 122);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 122);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1307672844U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c60_rhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs122), "rhs",
                  "rhs", 122);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs122), "lhs",
                  "lhs", 122);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 123);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 123);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 123);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c60_rhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs123), "rhs",
                  "rhs", 123);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs123), "lhs",
                  "lhs", 123);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 124);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_realmin_denormal"),
                  "name", "name", 124);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 124);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m"),
                  "resolved", "resolved", 124);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1326749598U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c60_rhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs124), "rhs",
                  "rhs", 124);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs124), "lhs",
                  "lhs", 124);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin_denormal.m"),
                  "context", "context", 125);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 125);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 125);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c60_rhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs125), "rhs",
                  "rhs", 125);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs125), "lhs",
                  "lhs", 125);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 126);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("abs"), "name", "name", 126);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 126);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c60_rhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs126), "rhs",
                  "rhs", 126);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs126), "lhs",
                  "lhs", 126);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 127);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("isfinite"), "name", "name",
                  127);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 127);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 127);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c60_rhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs127), "rhs",
                  "rhs", 127);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs127), "lhs",
                  "lhs", 127);
  sf_mex_destroy(&c60_rhs64);
  sf_mex_destroy(&c60_lhs64);
  sf_mex_destroy(&c60_rhs65);
  sf_mex_destroy(&c60_lhs65);
  sf_mex_destroy(&c60_rhs66);
  sf_mex_destroy(&c60_lhs66);
  sf_mex_destroy(&c60_rhs67);
  sf_mex_destroy(&c60_lhs67);
  sf_mex_destroy(&c60_rhs68);
  sf_mex_destroy(&c60_lhs68);
  sf_mex_destroy(&c60_rhs69);
  sf_mex_destroy(&c60_lhs69);
  sf_mex_destroy(&c60_rhs70);
  sf_mex_destroy(&c60_lhs70);
  sf_mex_destroy(&c60_rhs71);
  sf_mex_destroy(&c60_lhs71);
  sf_mex_destroy(&c60_rhs72);
  sf_mex_destroy(&c60_lhs72);
  sf_mex_destroy(&c60_rhs73);
  sf_mex_destroy(&c60_lhs73);
  sf_mex_destroy(&c60_rhs74);
  sf_mex_destroy(&c60_lhs74);
  sf_mex_destroy(&c60_rhs75);
  sf_mex_destroy(&c60_lhs75);
  sf_mex_destroy(&c60_rhs76);
  sf_mex_destroy(&c60_lhs76);
  sf_mex_destroy(&c60_rhs77);
  sf_mex_destroy(&c60_lhs77);
  sf_mex_destroy(&c60_rhs78);
  sf_mex_destroy(&c60_lhs78);
  sf_mex_destroy(&c60_rhs79);
  sf_mex_destroy(&c60_lhs79);
  sf_mex_destroy(&c60_rhs80);
  sf_mex_destroy(&c60_lhs80);
  sf_mex_destroy(&c60_rhs81);
  sf_mex_destroy(&c60_lhs81);
  sf_mex_destroy(&c60_rhs82);
  sf_mex_destroy(&c60_lhs82);
  sf_mex_destroy(&c60_rhs83);
  sf_mex_destroy(&c60_lhs83);
  sf_mex_destroy(&c60_rhs84);
  sf_mex_destroy(&c60_lhs84);
  sf_mex_destroy(&c60_rhs85);
  sf_mex_destroy(&c60_lhs85);
  sf_mex_destroy(&c60_rhs86);
  sf_mex_destroy(&c60_lhs86);
  sf_mex_destroy(&c60_rhs87);
  sf_mex_destroy(&c60_lhs87);
  sf_mex_destroy(&c60_rhs88);
  sf_mex_destroy(&c60_lhs88);
  sf_mex_destroy(&c60_rhs89);
  sf_mex_destroy(&c60_lhs89);
  sf_mex_destroy(&c60_rhs90);
  sf_mex_destroy(&c60_lhs90);
  sf_mex_destroy(&c60_rhs91);
  sf_mex_destroy(&c60_lhs91);
  sf_mex_destroy(&c60_rhs92);
  sf_mex_destroy(&c60_lhs92);
  sf_mex_destroy(&c60_rhs93);
  sf_mex_destroy(&c60_lhs93);
  sf_mex_destroy(&c60_rhs94);
  sf_mex_destroy(&c60_lhs94);
  sf_mex_destroy(&c60_rhs95);
  sf_mex_destroy(&c60_lhs95);
  sf_mex_destroy(&c60_rhs96);
  sf_mex_destroy(&c60_lhs96);
  sf_mex_destroy(&c60_rhs97);
  sf_mex_destroy(&c60_lhs97);
  sf_mex_destroy(&c60_rhs98);
  sf_mex_destroy(&c60_lhs98);
  sf_mex_destroy(&c60_rhs99);
  sf_mex_destroy(&c60_lhs99);
  sf_mex_destroy(&c60_rhs100);
  sf_mex_destroy(&c60_lhs100);
  sf_mex_destroy(&c60_rhs101);
  sf_mex_destroy(&c60_lhs101);
  sf_mex_destroy(&c60_rhs102);
  sf_mex_destroy(&c60_lhs102);
  sf_mex_destroy(&c60_rhs103);
  sf_mex_destroy(&c60_lhs103);
  sf_mex_destroy(&c60_rhs104);
  sf_mex_destroy(&c60_lhs104);
  sf_mex_destroy(&c60_rhs105);
  sf_mex_destroy(&c60_lhs105);
  sf_mex_destroy(&c60_rhs106);
  sf_mex_destroy(&c60_lhs106);
  sf_mex_destroy(&c60_rhs107);
  sf_mex_destroy(&c60_lhs107);
  sf_mex_destroy(&c60_rhs108);
  sf_mex_destroy(&c60_lhs108);
  sf_mex_destroy(&c60_rhs109);
  sf_mex_destroy(&c60_lhs109);
  sf_mex_destroy(&c60_rhs110);
  sf_mex_destroy(&c60_lhs110);
  sf_mex_destroy(&c60_rhs111);
  sf_mex_destroy(&c60_lhs111);
  sf_mex_destroy(&c60_rhs112);
  sf_mex_destroy(&c60_lhs112);
  sf_mex_destroy(&c60_rhs113);
  sf_mex_destroy(&c60_lhs113);
  sf_mex_destroy(&c60_rhs114);
  sf_mex_destroy(&c60_lhs114);
  sf_mex_destroy(&c60_rhs115);
  sf_mex_destroy(&c60_lhs115);
  sf_mex_destroy(&c60_rhs116);
  sf_mex_destroy(&c60_lhs116);
  sf_mex_destroy(&c60_rhs117);
  sf_mex_destroy(&c60_lhs117);
  sf_mex_destroy(&c60_rhs118);
  sf_mex_destroy(&c60_lhs118);
  sf_mex_destroy(&c60_rhs119);
  sf_mex_destroy(&c60_lhs119);
  sf_mex_destroy(&c60_rhs120);
  sf_mex_destroy(&c60_lhs120);
  sf_mex_destroy(&c60_rhs121);
  sf_mex_destroy(&c60_lhs121);
  sf_mex_destroy(&c60_rhs122);
  sf_mex_destroy(&c60_lhs122);
  sf_mex_destroy(&c60_rhs123);
  sf_mex_destroy(&c60_lhs123);
  sf_mex_destroy(&c60_rhs124);
  sf_mex_destroy(&c60_lhs124);
  sf_mex_destroy(&c60_rhs125);
  sf_mex_destroy(&c60_lhs125);
  sf_mex_destroy(&c60_rhs126);
  sf_mex_destroy(&c60_lhs126);
  sf_mex_destroy(&c60_rhs127);
  sf_mex_destroy(&c60_lhs127);
}

static void c60_c_info_helper(const mxArray **c60_info)
{
  const mxArray *c60_rhs128 = NULL;
  const mxArray *c60_lhs128 = NULL;
  const mxArray *c60_rhs129 = NULL;
  const mxArray *c60_lhs129 = NULL;
  const mxArray *c60_rhs130 = NULL;
  const mxArray *c60_lhs130 = NULL;
  const mxArray *c60_rhs131 = NULL;
  const mxArray *c60_lhs131 = NULL;
  const mxArray *c60_rhs132 = NULL;
  const mxArray *c60_lhs132 = NULL;
  const mxArray *c60_rhs133 = NULL;
  const mxArray *c60_lhs133 = NULL;
  const mxArray *c60_rhs134 = NULL;
  const mxArray *c60_lhs134 = NULL;
  const mxArray *c60_rhs135 = NULL;
  const mxArray *c60_lhs135 = NULL;
  const mxArray *c60_rhs136 = NULL;
  const mxArray *c60_lhs136 = NULL;
  const mxArray *c60_rhs137 = NULL;
  const mxArray *c60_lhs137 = NULL;
  const mxArray *c60_rhs138 = NULL;
  const mxArray *c60_lhs138 = NULL;
  const mxArray *c60_rhs139 = NULL;
  const mxArray *c60_lhs139 = NULL;
  const mxArray *c60_rhs140 = NULL;
  const mxArray *c60_lhs140 = NULL;
  const mxArray *c60_rhs141 = NULL;
  const mxArray *c60_lhs141 = NULL;
  const mxArray *c60_rhs142 = NULL;
  const mxArray *c60_lhs142 = NULL;
  const mxArray *c60_rhs143 = NULL;
  const mxArray *c60_lhs143 = NULL;
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 128);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_guarded_nan"), "name",
                  "name", 128);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 128);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                  "resolved", "resolved", 128);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1286840376U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c60_rhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs128), "rhs",
                  "rhs", 128);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs128), "lhs",
                  "lhs", 128);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_safe_eq.m"), "context",
                  "context", 129);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("isinf"), "name", "name", 129);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 129);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 129);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 129);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 129);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 129);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 129);
  sf_mex_assign(&c60_rhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs129), "rhs",
                  "rhs", 129);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs129), "lhs",
                  "lhs", 129);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/ismember.m!bsearch"),
                  "context", "context", 130);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_sort_lt"), "name",
                  "name", 130);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 130);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_lt.m"), "resolved",
                  "resolved", 130);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1292212110U), "fileTimeLo",
                  "fileTimeLo", 130);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 130);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 130);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 130);
  sf_mex_assign(&c60_rhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs130), "rhs",
                  "rhs", 130);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs130), "lhs",
                  "lhs", 130);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_lt.m"), "context",
                  "context", 131);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_relop"), "name", "name",
                  131);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 131);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 131);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1342472782U), "fileTimeLo",
                  "fileTimeLo", 131);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 131);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 131);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 131);
  sf_mex_assign(&c60_rhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs131), "rhs",
                  "rhs", 131);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs131), "lhs",
                  "lhs", 131);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_lt.m"), "context",
                  "context", 132);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("isnan"), "name", "name", 132);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 132);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 132);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 132);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 132);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 132);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 132);
  sf_mex_assign(&c60_rhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs132), "rhs",
                  "rhs", 132);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs132), "lhs",
                  "lhs", 132);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/ismember.m!bsearch"),
                  "context", "context", 133);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 133);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 133);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 133);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 133);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 133);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 133);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 133);
  sf_mex_assign(&c60_rhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs133), "rhs",
                  "rhs", 133);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs133), "lhs",
                  "lhs", 133);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/ismember.m!bsearch"),
                  "context", "context", 134);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 134);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 134);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 134);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 134);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 134);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 134);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 134);
  sf_mex_assign(&c60_rhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs134), "rhs",
                  "rhs", 134);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs134), "lhs",
                  "lhs", 134);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "context", "context", 135);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("max"), "name", "name", 135);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 135);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 135);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 135);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 135);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 135);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 135);
  sf_mex_assign(&c60_rhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs135), "rhs",
                  "rhs", 135);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs135), "lhs",
                  "lhs", 135);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 136);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 136);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 136);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 136);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 136);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 136);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 136);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 136);
  sf_mex_assign(&c60_rhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs136), "rhs",
                  "rhs", 136);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs136), "lhs",
                  "lhs", 136);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 137);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 137);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 137);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 137);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 137);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 137);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 137);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 137);
  sf_mex_assign(&c60_rhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs137), "rhs",
                  "rhs", 137);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs137), "lhs",
                  "lhs", 137);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 138);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 138);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 138);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 138);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 138);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 138);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 138);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 138);
  sf_mex_assign(&c60_rhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs138), "rhs",
                  "rhs", 138);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs138), "lhs",
                  "lhs", 138);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 139);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 139);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 139);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 139);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 139);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 139);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 139);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 139);
  sf_mex_assign(&c60_rhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs139), "rhs",
                  "rhs", 139);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs139), "lhs",
                  "lhs", 139);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 140);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 140);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 140);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 140);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 140);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 140);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 140);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 140);
  sf_mex_assign(&c60_rhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs140), "rhs",
                  "rhs", 140);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs140), "lhs",
                  "lhs", 140);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 141);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 141);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 141);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 141);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 141);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 141);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 141);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 141);
  sf_mex_assign(&c60_rhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs141), "rhs",
                  "rhs", 141);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs141), "lhs",
                  "lhs", 141);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/Safety/MARLOSafety_ATRIAS.m"),
                  "context", "context", 142);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("min"), "name", "name", 142);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 142);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 142);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 142);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 142);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 142);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 142);
  sf_mex_assign(&c60_rhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs142), "rhs",
                  "rhs", 142);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs142), "lhs",
                  "lhs", 142);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 143);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 143);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 143);
  sf_mex_addfield(*c60_info, c60_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 143);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 143);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 143);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 143);
  sf_mex_addfield(*c60_info, c60_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 143);
  sf_mex_assign(&c60_rhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c60_lhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_rhs143), "rhs",
                  "rhs", 143);
  sf_mex_addfield(*c60_info, sf_mex_duplicatearraysafe(&c60_lhs143), "lhs",
                  "lhs", 143);
  sf_mex_destroy(&c60_rhs128);
  sf_mex_destroy(&c60_lhs128);
  sf_mex_destroy(&c60_rhs129);
  sf_mex_destroy(&c60_lhs129);
  sf_mex_destroy(&c60_rhs130);
  sf_mex_destroy(&c60_lhs130);
  sf_mex_destroy(&c60_rhs131);
  sf_mex_destroy(&c60_lhs131);
  sf_mex_destroy(&c60_rhs132);
  sf_mex_destroy(&c60_lhs132);
  sf_mex_destroy(&c60_rhs133);
  sf_mex_destroy(&c60_lhs133);
  sf_mex_destroy(&c60_rhs134);
  sf_mex_destroy(&c60_lhs134);
  sf_mex_destroy(&c60_rhs135);
  sf_mex_destroy(&c60_lhs135);
  sf_mex_destroy(&c60_rhs136);
  sf_mex_destroy(&c60_lhs136);
  sf_mex_destroy(&c60_rhs137);
  sf_mex_destroy(&c60_lhs137);
  sf_mex_destroy(&c60_rhs138);
  sf_mex_destroy(&c60_lhs138);
  sf_mex_destroy(&c60_rhs139);
  sf_mex_destroy(&c60_lhs139);
  sf_mex_destroy(&c60_rhs140);
  sf_mex_destroy(&c60_lhs140);
  sf_mex_destroy(&c60_rhs141);
  sf_mex_destroy(&c60_lhs141);
  sf_mex_destroy(&c60_rhs142);
  sf_mex_destroy(&c60_lhs142);
  sf_mex_destroy(&c60_rhs143);
  sf_mex_destroy(&c60_lhs143);
}

static void c60_eml_scalar_eg(SFc60_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c60_mpower(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c60_a)
{
  real_T c60_b_a;
  real_T c60_c_a;
  real_T c60_ak;
  real_T c60_d_a;
  real_T c60_ar;
  c60_b_a = c60_a;
  c60_c_a = c60_b_a;
  c60_eml_scalar_eg(chartInstance);
  c60_ak = c60_c_a;
  c60_d_a = c60_ak;
  c60_eml_scalar_eg(chartInstance);
  c60_ar = c60_d_a;
  return muDoubleScalarPower(c60_ar, 40.0);
}

static real_T c60_b_mpower(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c60_a)
{
  real_T c60_b_a;
  real_T c60_c_a;
  real_T c60_ak;
  real_T c60_d_a;
  real_T c60_ar;
  c60_b_a = c60_a;
  c60_c_a = c60_b_a;
  c60_eml_scalar_eg(chartInstance);
  c60_ak = c60_c_a;
  c60_d_a = c60_ak;
  c60_eml_scalar_eg(chartInstance);
  c60_ar = c60_d_a;
  return muDoubleScalarPower(c60_ar, 41.0);
}

static void c60_b_eml_scalar_eg(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c60_eml_xgemm(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c60_A[442], real_T c60_B[13], real_T c60_C[34], real_T c60_b_C[34])
{
  int32_T c60_i147;
  int32_T c60_i148;
  real_T c60_b_A[442];
  int32_T c60_i149;
  real_T c60_b_B[13];
  for (c60_i147 = 0; c60_i147 < 34; c60_i147++) {
    c60_b_C[c60_i147] = c60_C[c60_i147];
  }

  for (c60_i148 = 0; c60_i148 < 442; c60_i148++) {
    c60_b_A[c60_i148] = c60_A[c60_i148];
  }

  for (c60_i149 = 0; c60_i149 < 13; c60_i149++) {
    c60_b_B[c60_i149] = c60_B[c60_i149];
  }

  c60_b_eml_xgemm(chartInstance, c60_b_A, c60_b_B, c60_b_C);
}

static real_T c60_sum(SFc60_Walking_ATRIASInstanceStruct *chartInstance, real_T
                      c60_x[34])
{
  real_T c60_y;
  int32_T c60_k;
  int32_T c60_b_k;
  c60_y = c60_x[0];
  c60_intmin(chartInstance);
  for (c60_k = 2; c60_k < 35; c60_k++) {
    c60_b_k = c60_k;
    c60_y += c60_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c60_b_k), 1, 34, 1, 0) - 1];
  }

  return c60_y;
}

static int32_T c60_intmin(SFc60_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
  return MIN_int32_T;
}

static void c60_isfinite(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c60_x[6], boolean_T c60_b[6])
{
  int32_T c60_i150;
  int32_T c60_i151;
  int32_T c60_i152;
  boolean_T c60_b_b[6];
  int32_T c60_i153;
  int32_T c60_i154;
  (void)chartInstance;
  for (c60_i150 = 0; c60_i150 < 6; c60_i150++) {
    c60_b[c60_i150] = muDoubleScalarIsInf(c60_x[c60_i150]);
  }

  for (c60_i151 = 0; c60_i151 < 6; c60_i151++) {
    c60_b[c60_i151] = !c60_b[c60_i151];
  }

  for (c60_i152 = 0; c60_i152 < 6; c60_i152++) {
    c60_b_b[c60_i152] = muDoubleScalarIsNaN(c60_x[c60_i152]);
  }

  for (c60_i153 = 0; c60_i153 < 6; c60_i153++) {
    c60_b_b[c60_i153] = !c60_b_b[c60_i153];
  }

  for (c60_i154 = 0; c60_i154 < 6; c60_i154++) {
    c60_b[c60_i154] = (c60_b[c60_i154] && c60_b_b[c60_i154]);
  }
}

static boolean_T c60_any(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  boolean_T c60_x[6])
{
  boolean_T c60_y;
  int32_T c60_k;
  real_T c60_b_k;
  boolean_T c60_b3;
  boolean_T exitg1;
  (void)chartInstance;
  c60_y = false;
  c60_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c60_k < 6)) {
    c60_b_k = 1.0 + (real_T)c60_k;
    if ((real_T)c60_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
         _SFD_INTEGER_CHECK("", c60_b_k), 1, 6, 1, 0) - 1] == 0.0) {
      c60_b3 = true;
    } else {
      (real_T)_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        c60_b_k), 1, 6, 1, 0);
      c60_b3 = false;
    }

    if (!c60_b3) {
      c60_y = true;
      exitg1 = true;
    } else {
      c60_k++;
    }
  }

  return c60_y;
}

static void c60_abs(SFc60_Walking_ATRIASInstanceStruct *chartInstance, real_T
                    c60_x[6], real_T c60_y[6])
{
  int32_T c60_k;
  real_T c60_b_k;
  real_T c60_b_x;
  real_T c60_b_y;
  (void)chartInstance;
  for (c60_k = 0; c60_k < 6; c60_k++) {
    c60_b_k = 1.0 + (real_T)c60_k;
    c60_b_x = c60_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", c60_b_k), 1, 6, 1, 0) - 1];
    c60_b_y = muDoubleScalarAbs(c60_b_x);
    c60_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c60_b_k), 1, 6, 1, 0) - 1] = c60_b_y;
  }
}

static void c60_eml_error(SFc60_Walking_ATRIASInstanceStruct *chartInstance)
{
  int32_T c60_i155;
  static char_T c60_cv0[32] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 's', 'm', 'e', 'm', 'b', 'e', 'r', '_', 'u', 'n',
    's', 'o', 'r', 't', 'e', 'd', 'S' };

  char_T c60_u[32];
  const mxArray *c60_y = NULL;
  (void)chartInstance;
  for (c60_i155 = 0; c60_i155 < 32; c60_i155++) {
    c60_u[c60_i155] = c60_cv0[c60_i155];
  }

  c60_y = NULL;
  sf_mex_assign(&c60_y, sf_mex_create("y", c60_u, 10, 0U, 1U, 0U, 2, 1, 32),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c60_y));
}

static int32_T c60_bsearch(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c60_x, real_T c60_s[8])
{
  int32_T c60_idx;
  int32_T c60_ilo;
  int32_T c60_ihi;
  int32_T c60_imid;
  real_T c60_a;
  real_T c60_b;
  real_T c60_b_x;
  real_T c60_c_x;
  real_T c60_y;
  real_T c60_A;
  real_T c60_d_x;
  real_T c60_e_x;
  real_T c60_f_x;
  real_T c60_b_y;
  real_T c60_g_x;
  real_T c60_h_x;
  real_T c60_i_x;
  real_T c60_absxk;
  real_T c60_j_x;
  real_T c60_k_x;
  boolean_T c60_b_b;
  boolean_T c60_b4;
  real_T c60_l_x;
  boolean_T c60_c_b;
  boolean_T c60_b5;
  boolean_T c60_d_b;
  real_T c60_r;
  int32_T c60_exponent;
  int32_T c60_b_exponent;
  int32_T c60_c_exponent;
  real_T c60_m_x;
  boolean_T c60_e_b;
  real_T c60_n_x;
  boolean_T c60_f_b;
  boolean_T c60_b6;
  boolean_T c60_p;
  real_T c60_b_a;
  real_T c60_g_b;
  real_T c60_c_a;
  real_T c60_h_b;
  boolean_T c60_b_p;
  real_T c60_o_x;
  boolean_T c60_i_b;
  boolean_T c60_b7;
  boolean_T c60_c_p;
  int32_T c60_d_a;
  int32_T c60_e_a;
  real_T c60_f_a;
  real_T c60_j_b;
  real_T c60_p_x;
  real_T c60_q_x;
  real_T c60_c_y;
  real_T c60_b_A;
  real_T c60_r_x;
  real_T c60_s_x;
  real_T c60_t_x;
  real_T c60_d_y;
  real_T c60_u_x;
  real_T c60_v_x;
  real_T c60_w_x;
  real_T c60_b_absxk;
  real_T c60_x_x;
  real_T c60_y_x;
  boolean_T c60_k_b;
  boolean_T c60_b8;
  real_T c60_ab_x;
  boolean_T c60_l_b;
  boolean_T c60_b9;
  boolean_T c60_m_b;
  real_T c60_b_r;
  int32_T c60_d_exponent;
  int32_T c60_e_exponent;
  int32_T c60_f_exponent;
  real_T c60_bb_x;
  boolean_T c60_n_b;
  real_T c60_cb_x;
  boolean_T c60_o_b;
  boolean_T c60_b10;
  boolean_T c60_d_p;
  int32_T c60_g_a;
  int32_T c60_h_a;
  int32_T c60_i_a;
  int32_T c60_j_a;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T exitg1;
  boolean_T exitg2;
  (void)chartInstance;
  c60_idx = 0;
  c60_ilo = 1;
  c60_ihi = 8;
  exitg2 = false;
  while ((exitg2 == false) && (c60_ihi >= c60_ilo)) {
    c60_imid = (c60_ilo >> 1) + (c60_ihi >> 1);
    if ((c60_ilo & 1) == 1) {
      if ((c60_ihi & 1) == 1) {
        c60_imid++;
      }
    }

    c60_a = c60_x;
    c60_b = c60_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c60_imid), 1, 8, 1, 0) - 1];
    c60_b_x = c60_b - c60_a;
    c60_c_x = c60_b_x;
    c60_y = muDoubleScalarAbs(c60_c_x);
    c60_A = c60_b;
    c60_d_x = c60_A;
    c60_e_x = c60_d_x;
    c60_f_x = c60_e_x;
    c60_b_y = c60_f_x / 2.0;
    c60_g_x = c60_b_y;
    c60_h_x = c60_g_x;
    c60_i_x = c60_h_x;
    c60_absxk = muDoubleScalarAbs(c60_i_x);
    c60_j_x = c60_absxk;
    c60_k_x = c60_j_x;
    c60_b_b = muDoubleScalarIsInf(c60_k_x);
    c60_b4 = !c60_b_b;
    c60_l_x = c60_j_x;
    c60_c_b = muDoubleScalarIsNaN(c60_l_x);
    c60_b5 = !c60_c_b;
    c60_d_b = (c60_b4 && c60_b5);
    if (c60_d_b) {
      if (c60_absxk <= 2.2250738585072014E-308) {
        c60_r = 4.94065645841247E-324;
      } else {
        frexp(c60_absxk, &c60_exponent);
        c60_b_exponent = c60_exponent;
        c60_c_exponent = c60_b_exponent - 53;
        c60_c_exponent;
        c60_r = ldexp(1.0, c60_c_exponent);
      }
    } else {
      c60_r = rtNaN;
    }

    guard5 = false;
    guard6 = false;
    guard7 = false;
    if (c60_y < c60_r) {
      guard6 = true;
    } else {
      c60_m_x = c60_a;
      c60_e_b = muDoubleScalarIsInf(c60_m_x);
      if (c60_e_b) {
        c60_n_x = c60_b;
        c60_f_b = muDoubleScalarIsInf(c60_n_x);
        if (c60_f_b) {
          if (c60_a > 0.0 == c60_b > 0.0) {
            guard6 = true;
          } else {
            guard5 = true;
          }
        } else {
          guard7 = true;
        }
      } else {
        guard7 = true;
      }
    }

    if (guard7 == true) {
      guard5 = true;
    }

    if (guard6 == true) {
      c60_b6 = true;
    }

    if (guard5 == true) {
      c60_b6 = false;
    }

    c60_p = c60_b6;
    if (c60_p) {
      c60_idx = c60_imid;
      exitg2 = true;
    } else {
      c60_b_a = c60_x;
      c60_g_b = c60_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c60_imid), 1, 8, 1, 0) - 1];
      c60_c_a = c60_b_a;
      c60_h_b = c60_g_b;
      c60_b_p = (c60_c_a < c60_h_b);
      guard4 = false;
      if (c60_b_p) {
        guard4 = true;
      } else {
        c60_o_x = c60_g_b;
        c60_i_b = muDoubleScalarIsNaN(c60_o_x);
        if (c60_i_b) {
          guard4 = true;
        } else {
          c60_b7 = false;
        }
      }

      if (guard4 == true) {
        c60_b7 = true;
      }

      c60_c_p = c60_b7;
      if (c60_c_p) {
        c60_ihi = c60_imid - 1;
      } else {
        c60_ilo = c60_imid + 1;
      }
    }
  }

  if (c60_idx > 0) {
    c60_d_a = c60_idx;
    c60_e_a = c60_d_a - 1;
    c60_idx = c60_e_a;
    exitg1 = false;
    while ((exitg1 == false) && (c60_idx > 0)) {
      c60_f_a = c60_x;
      c60_j_b = c60_s[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c60_idx), 1, 8, 1, 0) - 1];
      c60_p_x = c60_j_b - c60_f_a;
      c60_q_x = c60_p_x;
      c60_c_y = muDoubleScalarAbs(c60_q_x);
      c60_b_A = c60_j_b;
      c60_r_x = c60_b_A;
      c60_s_x = c60_r_x;
      c60_t_x = c60_s_x;
      c60_d_y = c60_t_x / 2.0;
      c60_u_x = c60_d_y;
      c60_v_x = c60_u_x;
      c60_w_x = c60_v_x;
      c60_b_absxk = muDoubleScalarAbs(c60_w_x);
      c60_x_x = c60_b_absxk;
      c60_y_x = c60_x_x;
      c60_k_b = muDoubleScalarIsInf(c60_y_x);
      c60_b8 = !c60_k_b;
      c60_ab_x = c60_x_x;
      c60_l_b = muDoubleScalarIsNaN(c60_ab_x);
      c60_b9 = !c60_l_b;
      c60_m_b = (c60_b8 && c60_b9);
      if (c60_m_b) {
        if (c60_b_absxk <= 2.2250738585072014E-308) {
          c60_b_r = 4.94065645841247E-324;
        } else {
          frexp(c60_b_absxk, &c60_d_exponent);
          c60_e_exponent = c60_d_exponent;
          c60_f_exponent = c60_e_exponent - 53;
          c60_f_exponent;
          c60_b_r = ldexp(1.0, c60_f_exponent);
        }
      } else {
        c60_b_r = rtNaN;
      }

      guard1 = false;
      guard2 = false;
      guard3 = false;
      if (c60_c_y < c60_b_r) {
        guard2 = true;
      } else {
        c60_bb_x = c60_f_a;
        c60_n_b = muDoubleScalarIsInf(c60_bb_x);
        if (c60_n_b) {
          c60_cb_x = c60_j_b;
          c60_o_b = muDoubleScalarIsInf(c60_cb_x);
          if (c60_o_b) {
            if (c60_f_a > 0.0 == c60_j_b > 0.0) {
              guard2 = true;
            } else {
              guard1 = true;
            }
          } else {
            guard3 = true;
          }
        } else {
          guard3 = true;
        }
      }

      if (guard3 == true) {
        guard1 = true;
      }

      if (guard2 == true) {
        c60_b10 = true;
      }

      if (guard1 == true) {
        c60_b10 = false;
      }

      c60_d_p = c60_b10;
      if (c60_d_p) {
        c60_g_a = c60_idx;
        c60_h_a = c60_g_a - 1;
        c60_idx = c60_h_a;
      } else {
        exitg1 = true;
      }
    }

    c60_i_a = c60_idx;
    c60_j_a = c60_i_a + 1;
    c60_idx = c60_j_a;
  }

  return c60_idx;
}

static const mxArray *c60_i_sf_marshallOut(void *chartInstanceVoid, void
  *c60_inData)
{
  const mxArray *c60_mxArrayOutData = NULL;
  int32_T c60_u;
  const mxArray *c60_y = NULL;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_mxArrayOutData = NULL;
  c60_u = *(int32_T *)c60_inData;
  c60_y = NULL;
  sf_mex_assign(&c60_y, sf_mex_create("y", &c60_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c60_mxArrayOutData, c60_y, false);
  return c60_mxArrayOutData;
}

static int32_T c60_i_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId)
{
  int32_T c60_y;
  int32_T c60_i156;
  (void)chartInstance;
  sf_mex_import(c60_parentId, sf_mex_dup(c60_u), &c60_i156, 1, 6, 0U, 0, 0U, 0);
  c60_y = c60_i156;
  sf_mex_destroy(&c60_u);
  return c60_y;
}

static void c60_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c60_mxArrayInData, const char_T *c60_varName, void *c60_outData)
{
  const mxArray *c60_b_sfEvent;
  const char_T *c60_identifier;
  emlrtMsgIdentifier c60_thisId;
  int32_T c60_y;
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c60_b_sfEvent = sf_mex_dup(c60_mxArrayInData);
  c60_identifier = c60_varName;
  c60_thisId.fIdentifier = c60_identifier;
  c60_thisId.fParent = NULL;
  c60_y = c60_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c60_b_sfEvent),
    &c60_thisId);
  sf_mex_destroy(&c60_b_sfEvent);
  *(int32_T *)c60_outData = c60_y;
  sf_mex_destroy(&c60_mxArrayInData);
}

static uint8_T c60_j_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_b_is_active_c60_Walking_ATRIAS, const
  char_T *c60_identifier)
{
  uint8_T c60_y;
  emlrtMsgIdentifier c60_thisId;
  c60_thisId.fIdentifier = c60_identifier;
  c60_thisId.fParent = NULL;
  c60_y = c60_k_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c60_b_is_active_c60_Walking_ATRIAS), &c60_thisId);
  sf_mex_destroy(&c60_b_is_active_c60_Walking_ATRIAS);
  return c60_y;
}

static uint8_T c60_k_emlrt_marshallIn(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c60_u, const emlrtMsgIdentifier *c60_parentId)
{
  uint8_T c60_y;
  uint8_T c60_u0;
  (void)chartInstance;
  sf_mex_import(c60_parentId, sf_mex_dup(c60_u), &c60_u0, 1, 3, 0U, 0, 0U, 0);
  c60_y = c60_u0;
  sf_mex_destroy(&c60_u);
  return c60_y;
}

static void c60_b_eml_xgemm(SFc60_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c60_A[442], real_T c60_B[13], real_T c60_C[34])
{
  int32_T c60_i157;
  int32_T c60_i158;
  int32_T c60_i159;
  (void)chartInstance;
  for (c60_i157 = 0; c60_i157 < 34; c60_i157++) {
    c60_C[c60_i157] = 0.0;
    c60_i158 = 0;
    for (c60_i159 = 0; c60_i159 < 13; c60_i159++) {
      c60_C[c60_i157] += c60_A[c60_i158 + c60_i157] * c60_B[c60_i159];
      c60_i158 += 34;
    }
  }
}

static void init_dsm_address_info(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc60_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  chartInstance->c60_MotorCurrentCommand = (real_T (*)[6])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c60_MotorCurrentCommandSafe = (real_T (*)[6])
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c60_MedullaCommand = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c60_RequestSoftStop = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c60_q = (real_T (*)[13])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c60_dq = (real_T (*)[13])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c60_SafetyCountIn = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c60_MedullaCommandSafe = (real_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c60_SafetyState = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c60_SafetyCountOut = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
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

void sf_c60_Walking_ATRIAS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(704970710U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1204470638U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1284381235U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1495514304U);
}

mxArray* sf_c60_Walking_ATRIAS_get_post_codegen_info(void);
mxArray *sf_c60_Walking_ATRIAS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("tzKTAgW4FxXcIy2ZoPNODG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(13);
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
      pr[0] = (double)(13);
      pr[1] = (double)(1);
      mxSetField(mxData,4,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c60_Walking_ATRIAS_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c60_Walking_ATRIAS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c60_Walking_ATRIAS_jit_fallback_info(void)
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

mxArray *sf_c60_Walking_ATRIAS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c60_Walking_ATRIAS_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c60_Walking_ATRIAS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[12],T\"MedullaCommandSafe\",},{M[1],M[5],T\"MotorCurrentCommandSafe\",},{M[1],M[17],T\"SafetyCountOut\",},{M[1],M[14],T\"SafetyState\",},{M[8],M[0],T\"is_active_c60_Walking_ATRIAS\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c60_Walking_ATRIAS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc60_Walking_ATRIASInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking_ATRIASMachineNumber_,
           60,
           1,
           1,
           0,
           10,
           0,
           0,
           0,
           0,
           4,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_Walking_ATRIASMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Walking_ATRIASMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Walking_ATRIASMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"MotorCurrentCommand");
          _SFD_SET_DATA_PROPS(1,2,0,1,"MotorCurrentCommandSafe");
          _SFD_SET_DATA_PROPS(2,1,1,0,"MedullaCommand");
          _SFD_SET_DATA_PROPS(3,1,1,0,"RequestSoftStop");
          _SFD_SET_DATA_PROPS(4,1,1,0,"q");
          _SFD_SET_DATA_PROPS(5,1,1,0,"dq");
          _SFD_SET_DATA_PROPS(6,1,1,0,"SafetyCountIn");
          _SFD_SET_DATA_PROPS(7,2,0,1,"MedullaCommandSafe");
          _SFD_SET_DATA_PROPS(8,2,0,1,"SafetyState");
          _SFD_SET_DATA_PROPS(9,2,0,1,"SafetyCountOut");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,402);
        _SFD_CV_INIT_SCRIPT(0,1,4,0,0,1,0,0,4,2);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"MARLOSafety_ATRIAS",0,-1,5003);
        _SFD_CV_INIT_SCRIPT_IF(0,0,3209,3369,-1,3477);
        _SFD_CV_INIT_SCRIPT_IF(0,1,3518,3575,-1,3647);
        _SFD_CV_INIT_SCRIPT_IF(0,2,4689,4708,4763,4826);
        _SFD_CV_INIT_SCRIPT_IF(0,3,4836,4885,-1,4993);

        {
          static int caseStart[] = { 3038, 2896, 2967 };

          static int caseExprEnd[] = { 3047, 2902, 2973 };

          _SFD_CV_INIT_SCRIPT_SWITCH(0,0,2863,2888,3110,3,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        {
          static int condStart[] = { 3212, 3320 };

          static int condEnd[] = { 3247, 3369 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,0,3212,3369,2,0,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 4840, 4864 };

          static int condEnd[] = { 4858, 4884 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,1,4839,4885,2,2,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,0,4693,4707,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,1,4840,4858,-1,2);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,2,4864,4884,-1,0);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"MARLOBasicSafetyLimits2",0,-1,6559);
        _SFD_CV_INIT_SCRIPT(2,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"MARLOBasicSafetyLimits3",0,-1,6582);
        _SFD_CV_INIT_SCRIPT(3,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"MARLOBasicSafetyLimits",0,-1,6557);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c60_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c60_b_sf_marshallOut,(MexInFcnForType)
            c60_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c60_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c60_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c60_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c60_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c60_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c60_sf_marshallOut,(MexInFcnForType)c60_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c60_sf_marshallOut,(MexInFcnForType)c60_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c60_sf_marshallOut,(MexInFcnForType)c60_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c60_MotorCurrentCommand);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c60_MotorCurrentCommandSafe);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c60_MedullaCommand);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c60_RequestSoftStop);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c60_q);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c60_dq);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c60_SafetyCountIn);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c60_MedullaCommandSafe);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c60_SafetyState);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c60_SafetyCountOut);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Walking_ATRIASMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "3s1XSvO3KC37wfj7igJu8D";
}

static void sf_opaque_initialize_c60_Walking_ATRIAS(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc60_Walking_ATRIASInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c60_Walking_ATRIAS((SFc60_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
  initialize_c60_Walking_ATRIAS((SFc60_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c60_Walking_ATRIAS(void *chartInstanceVar)
{
  enable_c60_Walking_ATRIAS((SFc60_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c60_Walking_ATRIAS(void *chartInstanceVar)
{
  disable_c60_Walking_ATRIAS((SFc60_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c60_Walking_ATRIAS(void *chartInstanceVar)
{
  sf_gateway_c60_Walking_ATRIAS((SFc60_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c60_Walking_ATRIAS(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c60_Walking_ATRIAS((SFc60_Walking_ATRIASInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c60_Walking_ATRIAS(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c60_Walking_ATRIAS((SFc60_Walking_ATRIASInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c60_Walking_ATRIAS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc60_Walking_ATRIASInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking_ATRIAS_optimization_info();
    }

    finalize_c60_Walking_ATRIAS((SFc60_Walking_ATRIASInstanceStruct*)
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
  initSimStructsc60_Walking_ATRIAS((SFc60_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c60_Walking_ATRIAS(SimStruct *S)
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
    initialize_params_c60_Walking_ATRIAS((SFc60_Walking_ATRIASInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c60_Walking_ATRIAS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking_ATRIAS_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      60);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,60,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,60,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,60);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,60,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,60,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,60);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3103481710U));
  ssSetChecksum1(S,(2102401534U));
  ssSetChecksum2(S,(4129276090U));
  ssSetChecksum3(S,(2357848618U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c60_Walking_ATRIAS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c60_Walking_ATRIAS(SimStruct *S)
{
  SFc60_Walking_ATRIASInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc60_Walking_ATRIASInstanceStruct *)utMalloc(sizeof
    (SFc60_Walking_ATRIASInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc60_Walking_ATRIASInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c60_Walking_ATRIAS;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c60_Walking_ATRIAS;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c60_Walking_ATRIAS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c60_Walking_ATRIAS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c60_Walking_ATRIAS;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c60_Walking_ATRIAS;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c60_Walking_ATRIAS;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c60_Walking_ATRIAS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c60_Walking_ATRIAS;
  chartInstance->chartInfo.mdlStart = mdlStart_c60_Walking_ATRIAS;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c60_Walking_ATRIAS;
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

void c60_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c60_Walking_ATRIAS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c60_Walking_ATRIAS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c60_Walking_ATRIAS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c60_Walking_ATRIAS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
