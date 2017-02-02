/* Include files */

#include <stddef.h>
#include "blas.h"
#include "ATRIAS_test_sfun.h"
#include "c3_ATRIAS_test.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "ATRIAS_test_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[22] = { "q0", "dq0", "hd", "dhd", "Kp",
  "Kd", "nargin", "nargout", "t", "q", "dq", "q_d", "kp", "kd", "kp_hip",
  "kd_hip", "mode", "u", "y", "dy", "hd_h0", "dhd_dh0" };

/* Function Declarations */
static void initialize_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance);
static void initialize_params_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance);
static void enable_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct *chartInstance);
static void disable_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_ATRIAS_test
  (SFc3_ATRIAS_testInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_ATRIAS_test
  (SFc3_ATRIAS_testInstanceStruct *chartInstance);
static void set_sim_state_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance);
static void sf_gateway_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance);
static void mdl_start_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance);
static void initSimStructsc3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct *chartInstance,
  const mxArray *c3_b_dhd_dh0, const char_T *c3_identifier, real_T c3_b_y[12]);
static void c3_b_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct *chartInstance,
  const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_b_y[12]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct *chartInstance,
  const mxArray *c3_b_dy, const char_T *c3_identifier, real_T c3_b_y[6]);
static void c3_d_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct *chartInstance,
  const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_b_y[6]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_e_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_b_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_b_u);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_f_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_g_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_ATRIAS_test, const char_T
  *c3_identifier);
static uint8_T c3_h_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info(SFc3_ATRIAS_testInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc3_ATRIAS_testInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_ATRIAS_test = 0U;
}

static void initialize_params_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_ATRIAS_test
  (SFc3_ATRIAS_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_ATRIAS_test
  (SFc3_ATRIAS_testInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_b_y = NULL;
  int32_T c3_i0;
  real_T c3_b_u[12];
  const mxArray *c3_c_y = NULL;
  int32_T c3_i1;
  real_T c3_c_u[6];
  const mxArray *c3_d_y = NULL;
  int32_T c3_i2;
  real_T c3_d_u[12];
  const mxArray *c3_e_y = NULL;
  int32_T c3_i3;
  real_T c3_e_u[6];
  const mxArray *c3_f_y = NULL;
  int32_T c3_i4;
  real_T c3_f_u[6];
  const mxArray *c3_g_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_g_u;
  const mxArray *c3_h_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_createcellmatrix(6, 1), false);
  for (c3_i0 = 0; c3_i0 < 12; c3_i0++) {
    c3_b_u[c3_i0] = (*chartInstance->c3_dhd_dh0)[c3_i0];
  }

  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_setcell(c3_b_y, 0, c3_c_y);
  for (c3_i1 = 0; c3_i1 < 6; c3_i1++) {
    c3_c_u[c3_i1] = (*chartInstance->c3_dy)[c3_i1];
  }

  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_c_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c3_b_y, 1, c3_d_y);
  for (c3_i2 = 0; c3_i2 < 12; c3_i2++) {
    c3_d_u[c3_i2] = (*chartInstance->c3_hd_h0)[c3_i2];
  }

  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", c3_d_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_setcell(c3_b_y, 2, c3_e_y);
  for (c3_i3 = 0; c3_i3 < 6; c3_i3++) {
    c3_e_u[c3_i3] = (*chartInstance->c3_u)[c3_i3];
  }

  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", c3_e_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c3_b_y, 3, c3_f_y);
  for (c3_i4 = 0; c3_i4 < 6; c3_i4++) {
    c3_f_u[c3_i4] = (*chartInstance->c3_y)[c3_i4];
  }

  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", c3_f_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c3_b_y, 4, c3_g_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_ATRIAS_test;
  c3_g_u = c3_hoistedGlobal;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_b_y, 5, c3_h_y);
  sf_mex_assign(&c3_st, c3_b_y, false);
  return c3_st;
}

static void set_sim_state_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_b_u;
  real_T c3_dv0[12];
  int32_T c3_i5;
  real_T c3_dv1[6];
  int32_T c3_i6;
  real_T c3_dv2[12];
  int32_T c3_i7;
  real_T c3_dv3[6];
  int32_T c3_i8;
  real_T c3_dv4[6];
  int32_T c3_i9;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_b_u = sf_mex_dup(c3_st);
  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 0)),
                      "dhd_dh0", c3_dv0);
  for (c3_i5 = 0; c3_i5 < 12; c3_i5++) {
    (*chartInstance->c3_dhd_dh0)[c3_i5] = c3_dv0[c3_i5];
  }

  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 1)),
                        "dy", c3_dv1);
  for (c3_i6 = 0; c3_i6 < 6; c3_i6++) {
    (*chartInstance->c3_dy)[c3_i6] = c3_dv1[c3_i6];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 2)),
                      "hd_h0", c3_dv2);
  for (c3_i7 = 0; c3_i7 < 12; c3_i7++) {
    (*chartInstance->c3_hd_h0)[c3_i7] = c3_dv2[c3_i7];
  }

  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 3)),
                        "u", c3_dv3);
  for (c3_i8 = 0; c3_i8 < 6; c3_i8++) {
    (*chartInstance->c3_u)[c3_i8] = c3_dv3[c3_i8];
  }

  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 4)),
                        "y", c3_dv4);
  for (c3_i9 = 0; c3_i9 < 6; c3_i9++) {
    (*chartInstance->c3_y)[c3_i9] = c3_dv4[c3_i9];
  }

  chartInstance->c3_is_active_c3_ATRIAS_test = c3_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_b_u, 5)),
     "is_active_c3_ATRIAS_test");
  sf_mex_destroy(&c3_b_u);
  c3_update_debugger_state_c3_ATRIAS_test(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_f_hoistedGlobal;
  real_T c3_b_t;
  int32_T c3_i10;
  real_T c3_b_q[13];
  int32_T c3_i11;
  real_T c3_b_dq[13];
  int32_T c3_i12;
  real_T c3_b_q_d[6];
  real_T c3_b_kp;
  real_T c3_b_kd;
  real_T c3_b_kp_hip;
  real_T c3_b_kd_hip;
  real_T c3_b_mode;
  uint32_T c3_debug_family_var_map[22];
  real_T c3_q0[6];
  real_T c3_dq0[6];
  real_T c3_hd[6];
  real_T c3_dhd[6];
  real_T c3_Kp[6];
  real_T c3_Kd[6];
  real_T c3_nargin = 9.0;
  real_T c3_nargout = 5.0;
  real_T c3_b_u[6];
  real_T c3_b_y[6];
  real_T c3_b_dy[6];
  real_T c3_b_hd_h0[12];
  real_T c3_b_dhd_dh0[12];
  int32_T c3_i13;
  int32_T c3_i14;
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_m_x;
  real_T c3_n_x;
  real_T c3_o_x;
  real_T c3_p_x;
  real_T c3_q_x;
  real_T c3_r_x;
  real_T c3_s_x;
  real_T c3_t_x;
  real_T c3_u_x;
  real_T c3_v_x;
  real_T c3_w_x;
  real_T c3_x_x;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  int32_T c3_i22;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  int32_T c3_i27;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  int32_T c3_i31;
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_t, 0U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *chartInstance->c3_t;
  c3_b_hoistedGlobal = *chartInstance->c3_kp;
  c3_c_hoistedGlobal = *chartInstance->c3_kd;
  c3_d_hoistedGlobal = *chartInstance->c3_kp_hip;
  c3_e_hoistedGlobal = *chartInstance->c3_kd_hip;
  c3_f_hoistedGlobal = *chartInstance->c3_mode;
  c3_b_t = c3_hoistedGlobal;
  for (c3_i10 = 0; c3_i10 < 13; c3_i10++) {
    c3_b_q[c3_i10] = (*chartInstance->c3_q)[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 13; c3_i11++) {
    c3_b_dq[c3_i11] = (*chartInstance->c3_dq)[c3_i11];
  }

  for (c3_i12 = 0; c3_i12 < 6; c3_i12++) {
    c3_b_q_d[c3_i12] = (*chartInstance->c3_q_d)[c3_i12];
  }

  c3_b_kp = c3_b_hoistedGlobal;
  c3_b_kd = c3_c_hoistedGlobal;
  c3_b_kp_hip = c3_d_hoistedGlobal;
  c3_b_kd_hip = c3_e_hoistedGlobal;
  c3_b_mode = c3_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 22U, 22U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_q0, 0U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_dq0, 1U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_hd, 2U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_dhd, 3U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_Kp, 4U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_Kd, 5U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 6U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 7U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_t, 8U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_b_q, 9U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_b_dq, 10U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_b_q_d, 11U, c3_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_kp, 12U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_kd, 13U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_kp_hip, 14U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_kd_hip, 15U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_mode, 16U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_u, 17U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_y, 18U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_dy, 19U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_hd_h0, 20U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_dhd_dh0, 21U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  for (c3_i13 = 0; c3_i13 < 6; c3_i13++) {
    c3_q0[c3_i13] = c3_b_q[c3_i13 + 7];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 5);
  for (c3_i14 = 0; c3_i14 < 6; c3_i14++) {
    c3_dq0[c3_i14] = c3_b_dq[c3_i14 + 7];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  for (c3_i15 = 0; c3_i15 < 6; c3_i15++) {
    c3_b_u[c3_i15] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 8);
  for (c3_i16 = 0; c3_i16 < 6; c3_i16++) {
    c3_hd[c3_i16] = c3_b_q_d[c3_i16];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  for (c3_i17 = 0; c3_i17 < 6; c3_i17++) {
    c3_dhd[c3_i17] = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 11);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c3_b_mode, 1.0, -1, 0U,
        c3_b_mode == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 12);
    c3_x = 6.2831853071795862 * c3_b_t;
    c3_b_x = c3_x;
    c3_b_x = muDoubleScalarSin(c3_b_x);
    c3_hd[0] += 0.17453292519943295 * c3_b_x;
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
    c3_c_x = 6.2831853071795862 * c3_b_t;
    c3_d_x = c3_c_x;
    c3_d_x = muDoubleScalarCos(c3_d_x);
    c3_dhd[0] += 1.0966227112321509 * c3_d_x;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 14);
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c3_b_mode, 2.0, -1, 0U,
          c3_b_mode == 2.0))) {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
      c3_e_x = 6.2831853071795862 * c3_b_t;
      c3_f_x = c3_e_x;
      c3_f_x = muDoubleScalarSin(c3_f_x);
      c3_hd[1] += 0.17453292519943295 * c3_f_x;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
      c3_g_x = 6.2831853071795862 * c3_b_t;
      c3_h_x = c3_g_x;
      c3_h_x = muDoubleScalarCos(c3_h_x);
      c3_dhd[1] += 1.0966227112321509 * c3_h_x;
    } else {
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
      if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2, c3_b_mode, 3.0, -1,
            0U, c3_b_mode == 3.0))) {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
        c3_i_x = 6.2831853071795862 * c3_b_t;
        c3_j_x = c3_i_x;
        c3_j_x = muDoubleScalarSin(c3_j_x);
        c3_hd[2] += 0.087266462599716474 * c3_j_x;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
        c3_k_x = 6.2831853071795862 * c3_b_t;
        c3_l_x = c3_k_x;
        c3_l_x = muDoubleScalarCos(c3_l_x);
        c3_dhd[2] += 0.54831135561607547 * c3_l_x;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
        if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 3, c3_b_mode, 4.0, -1,
              0U, c3_b_mode == 4.0))) {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 21);
          c3_m_x = 6.2831853071795862 * c3_b_t;
          c3_n_x = c3_m_x;
          c3_n_x = muDoubleScalarSin(c3_n_x);
          c3_hd[3] += 0.17453292519943295 * c3_n_x;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
          c3_o_x = 6.2831853071795862 * c3_b_t;
          c3_p_x = c3_o_x;
          c3_p_x = muDoubleScalarCos(c3_p_x);
          c3_dhd[3] += 1.0966227112321509 * c3_p_x;
        } else {
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 23);
          if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 4, c3_b_mode, 5.0,
                -1, 0U, c3_b_mode == 5.0))) {
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 24);
            c3_q_x = 6.2831853071795862 * c3_b_t;
            c3_r_x = c3_q_x;
            c3_r_x = muDoubleScalarSin(c3_r_x);
            c3_hd[4] += 0.17453292519943295 * c3_r_x;
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 25);
            c3_s_x = 6.2831853071795862 * c3_b_t;
            c3_t_x = c3_s_x;
            c3_t_x = muDoubleScalarCos(c3_t_x);
            c3_dhd[4] += 1.0966227112321509 * c3_t_x;
          } else {
            _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 26);
            if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 5, c3_b_mode, 6.0,
                  -1, 0U, c3_b_mode == 6.0))) {
              _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 27);
              c3_u_x = 6.2831853071795862 * c3_b_t;
              c3_v_x = c3_u_x;
              c3_v_x = muDoubleScalarSin(c3_v_x);
              c3_hd[5] += 0.087266462599716474 * c3_v_x;
              _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 28);
              c3_w_x = 6.2831853071795862 * c3_b_t;
              c3_x_x = c3_w_x;
              c3_x_x = muDoubleScalarCos(c3_x_x);
              c3_dhd[5] += 0.54831135561607547 * c3_x_x;
            }
          }
        }
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 31);
  for (c3_i18 = 0; c3_i18 < 6; c3_i18++) {
    c3_b_y[c3_i18] = c3_hd[c3_i18] - c3_q0[c3_i18];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 32);
  for (c3_i19 = 0; c3_i19 < 6; c3_i19++) {
    c3_b_dy[c3_i19] = c3_dhd[c3_i19] - c3_dq0[c3_i19];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 34);
  c3_Kp[0] = c3_b_kp;
  c3_Kp[1] = c3_b_kp;
  c3_Kp[2] = c3_b_kp_hip;
  c3_Kp[3] = c3_b_kp;
  c3_Kp[4] = c3_b_kp;
  c3_Kp[5] = c3_b_kp_hip;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 35);
  c3_Kd[0] = c3_b_kd;
  c3_Kd[1] = c3_b_kd;
  c3_Kd[2] = c3_b_kd_hip;
  c3_Kd[3] = c3_b_kd;
  c3_Kd[4] = c3_b_kd;
  c3_Kd[5] = c3_b_kd_hip;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
  for (c3_i20 = 0; c3_i20 < 6; c3_i20++) {
    c3_b_u[c3_i20] = c3_Kp[c3_i20] * c3_b_y[c3_i20] + c3_Kd[c3_i20] *
      c3_b_dy[c3_i20];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 38);
  for (c3_i21 = 0; c3_i21 < 6; c3_i21++) {
    c3_b_hd_h0[c3_i21] = c3_hd[c3_i21];
  }

  for (c3_i22 = 0; c3_i22 < 6; c3_i22++) {
    c3_b_hd_h0[c3_i22 + 6] = c3_q0[c3_i22];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 39);
  for (c3_i23 = 0; c3_i23 < 6; c3_i23++) {
    c3_b_dhd_dh0[c3_i23] = c3_dhd[c3_i23];
  }

  for (c3_i24 = 0; c3_i24 < 6; c3_i24++) {
    c3_b_dhd_dh0[c3_i24 + 6] = c3_dq0[c3_i24];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -39);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i25 = 0; c3_i25 < 6; c3_i25++) {
    (*chartInstance->c3_u)[c3_i25] = c3_b_u[c3_i25];
  }

  for (c3_i26 = 0; c3_i26 < 6; c3_i26++) {
    (*chartInstance->c3_y)[c3_i26] = c3_b_y[c3_i26];
  }

  for (c3_i27 = 0; c3_i27 < 6; c3_i27++) {
    (*chartInstance->c3_dy)[c3_i27] = c3_b_dy[c3_i27];
  }

  for (c3_i28 = 0; c3_i28 < 12; c3_i28++) {
    (*chartInstance->c3_hd_h0)[c3_i28] = c3_b_hd_h0[c3_i28];
  }

  for (c3_i29 = 0; c3_i29 < 12; c3_i29++) {
    (*chartInstance->c3_dhd_dh0)[c3_i29] = c3_b_dhd_dh0[c3_i29];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_ATRIAS_testMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c3_i30 = 0; c3_i30 < 6; c3_i30++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_u)[c3_i30], 1U);
  }

  for (c3_i31 = 0; c3_i31 < 13; c3_i31++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_q)[c3_i31], 2U);
  }

  for (c3_i32 = 0; c3_i32 < 13; c3_i32++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_dq)[c3_i32], 3U);
  }

  for (c3_i33 = 0; c3_i33 < 6; c3_i33++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_q_d)[c3_i33], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_kp, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_kd, 6U);
  for (c3_i34 = 0; c3_i34 < 6; c3_i34++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_y)[c3_i34], 7U);
  }

  for (c3_i35 = 0; c3_i35 < 6; c3_i35++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_dy)[c3_i35], 8U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_kp_hip, 9U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_kd_hip, 10U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_mode, 11U);
  for (c3_i36 = 0; c3_i36 < 12; c3_i36++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_hd_h0)[c3_i36], 12U);
  }

  for (c3_i37 = 0; c3_i37 < 12; c3_i37++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_dhd_dh0)[c3_i37], 13U);
  }
}

static void mdl_start_c3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc3_ATRIAS_test(SFc3_ATRIAS_testInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i38;
  real_T c3_b_inData[12];
  int32_T c3_i39;
  real_T c3_b_u[12];
  const mxArray *c3_b_y = NULL;
  SFc3_ATRIAS_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_ATRIAS_testInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i38 = 0; c3_i38 < 12; c3_i38++) {
    c3_b_inData[c3_i38] = (*(real_T (*)[12])c3_inData)[c3_i38];
  }

  for (c3_i39 = 0; c3_i39 < 12; c3_i39++) {
    c3_b_u[c3_i39] = c3_b_inData[c3_i39];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct *chartInstance,
  const mxArray *c3_b_dhd_dh0, const char_T *c3_identifier, real_T c3_b_y[12])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dhd_dh0), &c3_thisId,
                        c3_b_y);
  sf_mex_destroy(&c3_b_dhd_dh0);
}

static void c3_b_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct *chartInstance,
  const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_b_y[12])
{
  real_T c3_dv5[12];
  int32_T c3_i40;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_dv5, 1, 0, 0U, 1, 0U, 1, 12);
  for (c3_i40 = 0; c3_i40 < 12; c3_i40++) {
    c3_b_y[c3_i40] = c3_dv5[c3_i40];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_dhd_dh0;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y[12];
  int32_T c3_i41;
  SFc3_ATRIAS_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_ATRIAS_testInstanceStruct *)chartInstanceVoid;
  c3_b_dhd_dh0 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dhd_dh0), &c3_thisId,
                        c3_b_y);
  sf_mex_destroy(&c3_b_dhd_dh0);
  for (c3_i41 = 0; c3_i41 < 12; c3_i41++) {
    (*(real_T (*)[12])c3_outData)[c3_i41] = c3_b_y[c3_i41];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i42;
  real_T c3_b_inData[6];
  int32_T c3_i43;
  real_T c3_b_u[6];
  const mxArray *c3_b_y = NULL;
  SFc3_ATRIAS_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_ATRIAS_testInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i42 = 0; c3_i42 < 6; c3_i42++) {
    c3_b_inData[c3_i42] = (*(real_T (*)[6])c3_inData)[c3_i42];
  }

  for (c3_i43 = 0; c3_i43 < 6; c3_i43++) {
    c3_b_u[c3_i43] = c3_b_inData[c3_i43];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct *chartInstance,
  const mxArray *c3_b_dy, const char_T *c3_identifier, real_T c3_b_y[6])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dy), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_b_dy);
}

static void c3_d_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct *chartInstance,
  const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId, real_T c3_b_y[6])
{
  real_T c3_dv6[6];
  int32_T c3_i44;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), c3_dv6, 1, 0, 0U, 1, 0U, 1, 6);
  for (c3_i44 = 0; c3_i44 < 6; c3_i44++) {
    c3_b_y[c3_i44] = c3_dv6[c3_i44];
  }

  sf_mex_destroy(&c3_b_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_dy;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y[6];
  int32_T c3_i45;
  SFc3_ATRIAS_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_ATRIAS_testInstanceStruct *)chartInstanceVoid;
  c3_b_dy = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dy), &c3_thisId, c3_b_y);
  sf_mex_destroy(&c3_b_dy);
  for (c3_i45 = 0; c3_i45 < 6; c3_i45++) {
    (*(real_T (*)[6])c3_outData)[c3_i45] = c3_b_y[c3_i45];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_ATRIAS_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_ATRIAS_testInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_b_u = *(real_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i46;
  real_T c3_b_inData[13];
  int32_T c3_i47;
  real_T c3_b_u[13];
  const mxArray *c3_b_y = NULL;
  SFc3_ATRIAS_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_ATRIAS_testInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i46 = 0; c3_i46 < 13; c3_i46++) {
    c3_b_inData[c3_i46] = (*(real_T (*)[13])c3_inData)[c3_i46];
  }

  for (c3_i47 = 0; c3_i47 < 13; c3_i47++) {
    c3_b_u[c3_i47] = c3_b_inData[c3_i47];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_e_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_b_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_b_y = c3_d0;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_b_y;
  SFc3_ATRIAS_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_ATRIAS_testInstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_y = c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout),
    &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_ATRIAS_test_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 11, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  const mxArray *c3_rhs3 = NULL;
  const mxArray *c3_lhs3 = NULL;
  const mxArray *c3_rhs4 = NULL;
  const mxArray *c3_lhs4 = NULL;
  const mxArray *c3_rhs5 = NULL;
  const mxArray *c3_lhs5 = NULL;
  const mxArray *c3_rhs6 = NULL;
  const mxArray *c3_lhs6 = NULL;
  const mxArray *c3_rhs7 = NULL;
  const mxArray *c3_lhs7 = NULL;
  const mxArray *c3_rhs8 = NULL;
  const mxArray *c3_lhs8 = NULL;
  const mxArray *c3_rhs9 = NULL;
  const mxArray *c3_lhs9 = NULL;
  const mxArray *c3_rhs10 = NULL;
  const mxArray *c3_lhs10 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c3_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c3_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c3_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c3_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("sin"), "name", "name", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c3_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286840336U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c3_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("cos"), "name", "name", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c3_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286840322U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c3_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs10), "lhs", "lhs",
                  10);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
  sf_mex_destroy(&c3_rhs3);
  sf_mex_destroy(&c3_lhs3);
  sf_mex_destroy(&c3_rhs4);
  sf_mex_destroy(&c3_lhs4);
  sf_mex_destroy(&c3_rhs5);
  sf_mex_destroy(&c3_lhs5);
  sf_mex_destroy(&c3_rhs6);
  sf_mex_destroy(&c3_lhs6);
  sf_mex_destroy(&c3_rhs7);
  sf_mex_destroy(&c3_lhs7);
  sf_mex_destroy(&c3_rhs8);
  sf_mex_destroy(&c3_lhs8);
  sf_mex_destroy(&c3_rhs9);
  sf_mex_destroy(&c3_lhs9);
  sf_mex_destroy(&c3_rhs10);
  sf_mex_destroy(&c3_lhs10);
}

static const mxArray *c3_emlrt_marshallOut(const char * c3_b_u)
{
  const mxArray *c3_b_y = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c3_b_u)), false);
  return c3_b_y;
}

static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_b_u)
{
  const mxArray *c3_b_y = NULL;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 7, 0U, 0U, 0U, 0), false);
  return c3_b_y;
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  SFc3_ATRIAS_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_ATRIAS_testInstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_b_u = *(int32_T *)c3_inData;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_b_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_f_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_b_y;
  int32_T c3_i48;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_i48, 1, 6, 0U, 0, 0U, 0);
  c3_b_y = c3_i48;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_b_y;
  SFc3_ATRIAS_testInstanceStruct *chartInstance;
  chartInstance = (SFc3_ATRIAS_testInstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_b_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_g_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_ATRIAS_test, const char_T
  *c3_identifier)
{
  uint8_T c3_b_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_y = c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_ATRIAS_test), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_ATRIAS_test);
  return c3_b_y;
}

static uint8_T c3_h_emlrt_marshallIn(SFc3_ATRIAS_testInstanceStruct
  *chartInstance, const mxArray *c3_b_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_b_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_b_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_b_y = c3_u0;
  sf_mex_destroy(&c3_b_u);
  return c3_b_y;
}

static void init_dsm_address_info(SFc3_ATRIAS_testInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_ATRIAS_testInstanceStruct
  *chartInstance)
{
  chartInstance->c3_t = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c3_u = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_q = (real_T (*)[13])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_dq = (real_T (*)[13])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_q_d = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_kp = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    4);
  chartInstance->c3_kd = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    5);
  chartInstance->c3_y = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_dy = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_kp_hip = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_kd_hip = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c3_mode = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c3_hd_h0 = (real_T (*)[12])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_dhd_dh0 = (real_T (*)[12])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
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

void sf_c3_ATRIAS_test_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(779071493U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3164130983U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3845343007U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3186844885U);
}

mxArray* sf_c3_ATRIAS_test_get_post_codegen_info(void);
mxArray *sf_c3_ATRIAS_test_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("EyzaiMD5KrqjC7jCkJ74O");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(13);
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
      pr[0] = (double)(13);
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
      pr[0] = (double)(6);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,7,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,7,"type",mxType);
    }

    mxSetField(mxData,7,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,8,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      pr[0] = (double)(12);
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
      pr[0] = (double)(12);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_ATRIAS_test_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_ATRIAS_test_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_ATRIAS_test_jit_fallback_info(void)
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

mxArray *sf_c3_ATRIAS_test_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_ATRIAS_test_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_ATRIAS_test(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[21],T\"dhd_dh0\",},{M[1],M[12],T\"dy\",},{M[1],M[20],T\"hd_h0\",},{M[1],M[4],T\"u\",},{M[1],M[11],T\"y\",},{M[8],M[0],T\"is_active_c3_ATRIAS_test\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_ATRIAS_test_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_ATRIAS_testInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_ATRIAS_testInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _ATRIAS_testMachineNumber_,
           3,
           1,
           1,
           0,
           14,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_ATRIAS_testMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_ATRIAS_testMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _ATRIAS_testMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"t");
          _SFD_SET_DATA_PROPS(1,2,0,1,"u");
          _SFD_SET_DATA_PROPS(2,1,1,0,"q");
          _SFD_SET_DATA_PROPS(3,1,1,0,"dq");
          _SFD_SET_DATA_PROPS(4,1,1,0,"q_d");
          _SFD_SET_DATA_PROPS(5,1,1,0,"kp");
          _SFD_SET_DATA_PROPS(6,1,1,0,"kd");
          _SFD_SET_DATA_PROPS(7,2,0,1,"y");
          _SFD_SET_DATA_PROPS(8,2,0,1,"dy");
          _SFD_SET_DATA_PROPS(9,1,1,0,"kp_hip");
          _SFD_SET_DATA_PROPS(10,1,1,0,"kd_hip");
          _SFD_SET_DATA_PROPS(11,1,1,0,"mode");
          _SFD_SET_DATA_PROPS(12,2,0,1,"hd_h0");
          _SFD_SET_DATA_PROPS(13,2,0,1,"dhd_dh0");
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
        _SFD_CV_INIT_EML(0,1,1,6,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,986);
        _SFD_CV_INIT_EML_IF(0,1,0,199,211,299,315);
        _SFD_CV_INIT_EML_IF(0,1,1,299,315,403,818);
        _SFD_CV_INIT_EML_IF(0,1,2,403,419,505,818);
        _SFD_CV_INIT_EML_IF(0,1,3,505,521,609,818);
        _SFD_CV_INIT_EML_IF(0,1,4,609,625,713,818);
        _SFD_CV_INIT_EML_IF(0,1,5,713,729,-1,729);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,202,211,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,306,315,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,410,419,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,512,521,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,616,625,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,5,720,729,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 12;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_t);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c3_u);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c3_q);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c3_dq);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c3_q_d);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c3_kp);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c3_kd);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c3_y);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c3_dy);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c3_kp_hip);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c3_kd_hip);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c3_mode);
        _SFD_SET_DATA_VALUE_PTR(12U, *chartInstance->c3_hd_h0);
        _SFD_SET_DATA_VALUE_PTR(13U, *chartInstance->c3_dhd_dh0);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _ATRIAS_testMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "gHUgSMNKiyULj42KbNNRa";
}

static void sf_opaque_initialize_c3_ATRIAS_test(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_ATRIAS_testInstanceStruct*) chartInstanceVar)
    ->S,0);
  initialize_params_c3_ATRIAS_test((SFc3_ATRIAS_testInstanceStruct*)
    chartInstanceVar);
  initialize_c3_ATRIAS_test((SFc3_ATRIAS_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c3_ATRIAS_test(void *chartInstanceVar)
{
  enable_c3_ATRIAS_test((SFc3_ATRIAS_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_ATRIAS_test(void *chartInstanceVar)
{
  disable_c3_ATRIAS_test((SFc3_ATRIAS_testInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_ATRIAS_test(void *chartInstanceVar)
{
  sf_gateway_c3_ATRIAS_test((SFc3_ATRIAS_testInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_ATRIAS_test(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c3_ATRIAS_test((SFc3_ATRIAS_testInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_ATRIAS_test(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c3_ATRIAS_test((SFc3_ATRIAS_testInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c3_ATRIAS_test(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_ATRIAS_testInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_ATRIAS_test_optimization_info();
    }

    finalize_c3_ATRIAS_test((SFc3_ATRIAS_testInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_ATRIAS_test((SFc3_ATRIAS_testInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_ATRIAS_test(SimStruct *S)
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
    initialize_params_c3_ATRIAS_test((SFc3_ATRIAS_testInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_ATRIAS_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_ATRIAS_test_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 7, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 8, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,9);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 9; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2410517376U));
  ssSetChecksum1(S,(273198793U));
  ssSetChecksum2(S,(4077449118U));
  ssSetChecksum3(S,(2405816583U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_ATRIAS_test(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_ATRIAS_test(SimStruct *S)
{
  SFc3_ATRIAS_testInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_ATRIAS_testInstanceStruct *)utMalloc(sizeof
    (SFc3_ATRIAS_testInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_ATRIAS_testInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_ATRIAS_test;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c3_ATRIAS_test;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_ATRIAS_test;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_ATRIAS_test;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_ATRIAS_test;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c3_ATRIAS_test;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c3_ATRIAS_test;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_ATRIAS_test;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_ATRIAS_test;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_ATRIAS_test;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_ATRIAS_test;
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

void c3_ATRIAS_test_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_ATRIAS_test(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_ATRIAS_test(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_ATRIAS_test(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_ATRIAS_test_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
