/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DDA2D_OSU3Dv2_sfun.h"
#include "c11_DDA2D_OSU3Dv2.h"
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
static const char * c11_debug_family_names[20] = { "q", "dq", "pcm", "p0", "p0T",
  "pHR", "p1R", "p2R", "p3R", "p4R", "pHL", "p1L", "p2L", "p3L", "p4L", "p_Z",
  "nargin", "nargout", "x_e", "terminate_signal" };

static const char * c11_b_debug_family_names[118] = { "xT", "yT", "zT", "qzT",
  "qyT", "qxT", "q1R", "q2R", "q1L", "q2L", "qgr1R", "qgr2R", "q3R", "qgr1L",
  "qgr2L", "q3L", "t1", "t2", "t3", "t5", "t6", "t7", "t8", "t9", "t10", "t11",
  "t14", "t15", "t16", "t17", "t18", "t21", "t22", "t23", "t24", "t25", "t26",
  "t33", "t36", "t37", "t39", "t40", "t41", "t42", "t47", "t54", "t57", "t64",
  "t67", "t74", "t76", "t79", "t86", "t89", "t96", "t99", "t104", "t107", "t110",
  "t126", "t129", "t131", "t132", "t133", "t137", "t138", "t142", "t144", "t151",
  "t152", "t155", "t160", "t161", "t170", "t171", "t182", "t206", "t228", "t231",
  "t234", "t235", "t237", "t275", "t277", "t279", "t284", "t286", "t301", "t322",
  "t4", "t12", "t27", "t31", "t35", "t53", "t20", "t30", "t43", "t48", "t63",
  "t66", "t71", "nargin", "nargout", "q", "pcm", "p0", "p0T", "pHR", "p1R",
  "p2R", "p3R", "p4R", "pHL", "p1L", "p2L", "p3L", "p4L" };

/* Function Declarations */
static void initialize_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initialize_params_c11_DDA2D_OSU3Dv2
  (SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void enable_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void disable_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c11_update_debugger_state_c11_DDA2D_OSU3Dv2
  (SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_DDA2D_OSU3Dv2
  (SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void set_sim_state_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_st);
static void finalize_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void sf_gateway_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void mdl_start_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c11_chartstep_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initSimStructsc11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c11_ATRIAS3D_Positions_Hip(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c11_q[16], real_T c11_pcm[3], real_T c11_p0[3], real_T
  c11_p0T[3], real_T c11_pHR[3], real_T c11_p1R[3], real_T c11_p2R[3], real_T
  c11_p3R[3], real_T c11_p4R[3], real_T c11_pHL[3], real_T c11_p1L[3], real_T
  c11_p2L[3], real_T c11_p3L[3], real_T c11_p4L[3]);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_b_terminate_signal, const char_T
  *c11_identifier);
static real_T c11_b_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_c_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[2]);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_d_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[3]);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_e_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[16]);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static void c11_info_helper(const mxArray **c11_info);
static const mxArray *c11_emlrt_marshallOut(const char * c11_u);
static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u);
static void c11_eml_switch_helper(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c11_check_forloop_overflow_error(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, boolean_T c11_overflow);
static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_f_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_g_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_DDA2D_OSU3Dv2, const char_T
  *c11_identifier);
static uint8_T c11_h_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_is_active_c11_DDA2D_OSU3Dv2 = 0U;
}

static void initialize_params_c11_DDA2D_OSU3Dv2
  (SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c11_update_debugger_state_c11_DDA2D_OSU3Dv2
  (SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c11_DDA2D_OSU3Dv2
  (SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  real_T c11_hoistedGlobal;
  real_T c11_u;
  const mxArray *c11_b_y = NULL;
  uint8_T c11_b_hoistedGlobal;
  uint8_T c11_b_u;
  const mxArray *c11_c_y = NULL;
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(2, 1), false);
  c11_hoistedGlobal = *chartInstance->c11_terminate_signal;
  c11_u = c11_hoistedGlobal;
  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  c11_b_hoistedGlobal = chartInstance->c11_is_active_c11_DDA2D_OSU3Dv2;
  c11_b_u = c11_b_hoistedGlobal;
  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  chartInstance->c11_doneDoubleBufferReInit = true;
  c11_u = sf_mex_dup(c11_st);
  *chartInstance->c11_terminate_signal = c11_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 0)), "terminate_signal");
  chartInstance->c11_is_active_c11_DDA2D_OSU3Dv2 = c11_g_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
     "is_active_c11_DDA2D_OSU3Dv2");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_DDA2D_OSU3Dv2(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  int32_T c11_i0;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
  for (c11_i0 = 0; c11_i0 < 32; c11_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c11_x_e)[c11_i0], 0U);
  }

  chartInstance->c11_sfEvent = CALL_EVENT;
  c11_chartstep_c11_DDA2D_OSU3Dv2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DDA2D_OSU3Dv2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c11_terminate_signal, 1U);
}

static void mdl_start_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c11_chartstep_c11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  int32_T c11_i1;
  real_T c11_b_x_e[32];
  uint32_T c11_debug_family_var_map[20];
  real_T c11_q[16];
  real_T c11_dq[16];
  real_T c11_pcm[3];
  real_T c11_p0[3];
  real_T c11_p0T[3];
  real_T c11_pHR[3];
  real_T c11_p1R[3];
  real_T c11_p2R[3];
  real_T c11_p3R[3];
  real_T c11_p4R[3];
  real_T c11_pHL[3];
  real_T c11_p1L[3];
  real_T c11_p2L[3];
  real_T c11_p3L[3];
  real_T c11_p4L[3];
  real_T c11_p_Z[2];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  real_T c11_b_terminate_signal;
  int32_T c11_i2;
  int32_T c11_i3;
  int32_T c11_i4;
  real_T c11_b_q[16];
  real_T c11_b_p4L[3];
  real_T c11_b_p3L[3];
  real_T c11_b_p2L[3];
  real_T c11_b_p1L[3];
  real_T c11_b_pHL[3];
  real_T c11_b_p4R[3];
  real_T c11_b_p3R[3];
  real_T c11_b_p2R[3];
  real_T c11_b_p1R[3];
  real_T c11_b_pHR[3];
  real_T c11_b_p0T[3];
  real_T c11_b_p0[3];
  real_T c11_b_pcm[3];
  int32_T c11_i5;
  int32_T c11_i6;
  int32_T c11_i7;
  int32_T c11_i8;
  int32_T c11_i9;
  int32_T c11_i10;
  int32_T c11_i11;
  int32_T c11_i12;
  int32_T c11_i13;
  int32_T c11_i14;
  int32_T c11_i15;
  int32_T c11_i16;
  int32_T c11_i17;
  int32_T c11_i18;
  real_T c11_varargin_1[2];
  int32_T c11_ixstart;
  real_T c11_mtmp;
  real_T c11_x;
  boolean_T c11_b;
  int32_T c11_ix;
  int32_T c11_b_ix;
  real_T c11_b_x;
  boolean_T c11_b_b;
  int32_T c11_a;
  int32_T c11_b_a;
  int32_T c11_i19;
  int32_T c11_c_a;
  int32_T c11_d_a;
  boolean_T c11_overflow;
  int32_T c11_c_ix;
  real_T c11_e_a;
  real_T c11_c_b;
  boolean_T c11_p;
  real_T c11_b_mtmp;
  real_T c11_d0;
  boolean_T guard1 = false;
  boolean_T exitg1;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
  for (c11_i1 = 0; c11_i1 < 32; c11_i1++) {
    c11_b_x_e[c11_i1] = (*chartInstance->c11_x_e)[c11_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 20U, 20U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_q, 0U, c11_e_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_dq, 1U, c11_e_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_pcm, 2U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p0, 3U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p0T, 4U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_pHR, 5U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p1R, 6U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p2R, 7U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p3R, 8U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p4R, 9U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_pHL, 10U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p1L, 11U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p2L, 12U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p3L, 13U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p4L, 14U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p_Z, 15U, c11_c_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 16U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 17U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_b_x_e, 18U, c11_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_terminate_signal, 19U,
    c11_sf_marshallOut, c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 4);
  for (c11_i2 = 0; c11_i2 < 16; c11_i2++) {
    c11_q[c11_i2] = c11_b_x_e[c11_i2];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 5);
  for (c11_i3 = 0; c11_i3 < 16; c11_i3++) {
    c11_dq[c11_i3] = c11_b_x_e[c11_i3 + 16];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 8);
  for (c11_i4 = 0; c11_i4 < 16; c11_i4++) {
    c11_b_q[c11_i4] = c11_q[c11_i4];
  }

  c11_ATRIAS3D_Positions_Hip(chartInstance, c11_b_q, c11_b_pcm, c11_b_p0,
    c11_b_p0T, c11_b_pHR, c11_b_p1R, c11_b_p2R, c11_b_p3R, c11_b_p4R, c11_b_pHL,
    c11_b_p1L, c11_b_p2L, c11_b_p3L, c11_b_p4L);
  for (c11_i5 = 0; c11_i5 < 3; c11_i5++) {
    c11_pcm[c11_i5] = c11_b_pcm[c11_i5];
  }

  for (c11_i6 = 0; c11_i6 < 3; c11_i6++) {
    c11_p0[c11_i6] = c11_b_p0[c11_i6];
  }

  for (c11_i7 = 0; c11_i7 < 3; c11_i7++) {
    c11_p0T[c11_i7] = c11_b_p0T[c11_i7];
  }

  for (c11_i8 = 0; c11_i8 < 3; c11_i8++) {
    c11_pHR[c11_i8] = c11_b_pHR[c11_i8];
  }

  for (c11_i9 = 0; c11_i9 < 3; c11_i9++) {
    c11_p1R[c11_i9] = c11_b_p1R[c11_i9];
  }

  for (c11_i10 = 0; c11_i10 < 3; c11_i10++) {
    c11_p2R[c11_i10] = c11_b_p2R[c11_i10];
  }

  for (c11_i11 = 0; c11_i11 < 3; c11_i11++) {
    c11_p3R[c11_i11] = c11_b_p3R[c11_i11];
  }

  for (c11_i12 = 0; c11_i12 < 3; c11_i12++) {
    c11_p4R[c11_i12] = c11_b_p4R[c11_i12];
  }

  for (c11_i13 = 0; c11_i13 < 3; c11_i13++) {
    c11_pHL[c11_i13] = c11_b_pHL[c11_i13];
  }

  for (c11_i14 = 0; c11_i14 < 3; c11_i14++) {
    c11_p1L[c11_i14] = c11_b_p1L[c11_i14];
  }

  for (c11_i15 = 0; c11_i15 < 3; c11_i15++) {
    c11_p2L[c11_i15] = c11_b_p2L[c11_i15];
  }

  for (c11_i16 = 0; c11_i16 < 3; c11_i16++) {
    c11_p3L[c11_i16] = c11_b_p3L[c11_i16];
  }

  for (c11_i17 = 0; c11_i17 < 3; c11_i17++) {
    c11_p4L[c11_i17] = c11_b_p4L[c11_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_p_Z[0] = c11_p4L[2];
  c11_p_Z[1] = c11_p4R[2];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 13);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c11_p0T[2], 0.5, -1, 2U,
        c11_p0T[2] < 0.5))) {
    guard1 = true;
  } else {
    for (c11_i18 = 0; c11_i18 < 2; c11_i18++) {
      c11_varargin_1[c11_i18] = c11_p_Z[c11_i18];
    }

    c11_ixstart = 1;
    c11_mtmp = c11_varargin_1[0];
    c11_x = c11_mtmp;
    c11_b = muDoubleScalarIsNaN(c11_x);
    if (c11_b) {
      c11_eml_switch_helper(chartInstance);
      c11_eml_switch_helper(chartInstance);
      c11_ix = 2;
      exitg1 = false;
      while ((exitg1 == false) && (c11_ix < 3)) {
        c11_b_ix = c11_ix;
        c11_ixstart = c11_b_ix;
        c11_b_x = c11_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c11_b_ix), 1, 2, 1, 0) - 1];
        c11_b_b = muDoubleScalarIsNaN(c11_b_x);
        if (!c11_b_b) {
          c11_mtmp = c11_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c11_b_ix), 1, 2, 1, 0) - 1];
          exitg1 = true;
        } else {
          c11_ix++;
        }
      }
    }

    if (c11_ixstart < 2) {
      c11_a = c11_ixstart;
      c11_b_a = c11_a + 1;
      c11_i19 = c11_b_a;
      c11_c_a = c11_i19;
      c11_d_a = c11_c_a;
      if (c11_d_a > 2) {
        c11_overflow = false;
      } else {
        c11_eml_switch_helper(chartInstance);
        c11_eml_switch_helper(chartInstance);
        c11_overflow = false;
      }

      if (c11_overflow) {
        c11_check_forloop_overflow_error(chartInstance, c11_overflow);
      }

      for (c11_c_ix = c11_i19; c11_c_ix < 3; c11_c_ix++) {
        c11_b_ix = c11_c_ix;
        c11_e_a = c11_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c11_b_ix), 1, 2, 1, 0) - 1];
        c11_c_b = c11_mtmp;
        c11_p = (c11_e_a > c11_c_b);
        if (c11_p) {
          c11_mtmp = c11_varargin_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c11_b_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c11_b_mtmp = c11_mtmp;
    c11_d0 = c11_b_mtmp;
    if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c11_d0, 1.0, -1, 4U,
          c11_d0 > 1.0))) {
      guard1 = true;
    } else {
      CV_EML_MCDC(0, 1, 0, false);
      CV_EML_IF(0, 1, 0, false);
      _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 16);
      c11_b_terminate_signal = 0.0;
    }
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, true);
    CV_EML_IF(0, 1, 0, true);
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 14);
    c11_b_terminate_signal = 1.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c11_terminate_signal = c11_b_terminate_signal;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, chartInstance->c11_sfEvent);
}

static void initSimStructsc11_DDA2D_OSU3Dv2(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c11_ATRIAS3D_Positions_Hip(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c11_q[16], real_T c11_pcm[3], real_T c11_p0[3], real_T
  c11_p0T[3], real_T c11_pHR[3], real_T c11_p1R[3], real_T c11_p2R[3], real_T
  c11_p3R[3], real_T c11_p4R[3], real_T c11_pHL[3], real_T c11_p1L[3], real_T
  c11_p2L[3], real_T c11_p3L[3], real_T c11_p4L[3])
{
  uint32_T c11_debug_family_var_map[118];
  real_T c11_xT;
  real_T c11_yT;
  real_T c11_zT;
  real_T c11_qzT;
  real_T c11_qyT;
  real_T c11_qxT;
  real_T c11_q1R;
  real_T c11_q2R;
  real_T c11_q1L;
  real_T c11_q2L;
  real_T c11_qgr1R;
  real_T c11_qgr2R;
  real_T c11_q3R;
  real_T c11_qgr1L;
  real_T c11_qgr2L;
  real_T c11_q3L;
  real_T c11_t1;
  real_T c11_t2;
  real_T c11_t3;
  real_T c11_t5;
  real_T c11_t6;
  real_T c11_t7;
  real_T c11_t8;
  real_T c11_t9;
  real_T c11_t10;
  real_T c11_t11;
  real_T c11_t14;
  real_T c11_t15;
  real_T c11_t16;
  real_T c11_t17;
  real_T c11_t18;
  real_T c11_t21;
  real_T c11_t22;
  real_T c11_t23;
  real_T c11_t24;
  real_T c11_t25;
  real_T c11_t26;
  real_T c11_t33;
  real_T c11_t36;
  real_T c11_t37;
  real_T c11_t39;
  real_T c11_t40;
  real_T c11_t41;
  real_T c11_t42;
  real_T c11_t47;
  real_T c11_t54;
  real_T c11_t57;
  real_T c11_t64;
  real_T c11_t67;
  real_T c11_t74;
  real_T c11_t76;
  real_T c11_t79;
  real_T c11_t86;
  real_T c11_t89;
  real_T c11_t96;
  real_T c11_t99;
  real_T c11_t104;
  real_T c11_t107;
  real_T c11_t110;
  real_T c11_t126;
  real_T c11_t129;
  real_T c11_t131;
  real_T c11_t132;
  real_T c11_t133;
  real_T c11_t137;
  real_T c11_t138;
  real_T c11_t142;
  real_T c11_t144;
  real_T c11_t151;
  real_T c11_t152;
  real_T c11_t155;
  real_T c11_t160;
  real_T c11_t161;
  real_T c11_t170;
  real_T c11_t171;
  real_T c11_t182;
  real_T c11_t206;
  real_T c11_t228;
  real_T c11_t231;
  real_T c11_t234;
  real_T c11_t235;
  real_T c11_t237;
  real_T c11_t275;
  real_T c11_t277;
  real_T c11_t279;
  real_T c11_t284;
  real_T c11_t286;
  real_T c11_t301;
  real_T c11_t322;
  real_T c11_t4;
  real_T c11_t12;
  real_T c11_t27;
  real_T c11_t31;
  real_T c11_t35;
  real_T c11_t53;
  real_T c11_t20;
  real_T c11_t30;
  real_T c11_t43;
  real_T c11_t48;
  real_T c11_t63;
  real_T c11_t66;
  real_T c11_t71;
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 13.0;
  int32_T c11_i20;
  real_T c11_x;
  real_T c11_b_x;
  real_T c11_c_x;
  real_T c11_d_x;
  real_T c11_e_x;
  real_T c11_f_x;
  real_T c11_g_x;
  real_T c11_h_x;
  real_T c11_i_x;
  real_T c11_j_x;
  real_T c11_k_x;
  real_T c11_l_x;
  real_T c11_m_x;
  real_T c11_n_x;
  real_T c11_o_x;
  real_T c11_p_x;
  real_T c11_q_x;
  real_T c11_r_x;
  real_T c11_s_x;
  real_T c11_t_x;
  real_T c11_u_x;
  real_T c11_v_x;
  real_T c11_w_x;
  real_T c11_x_x;
  real_T c11_y_x;
  real_T c11_ab_x;
  real_T c11_bb_x;
  real_T c11_cb_x;
  real_T c11_db_x;
  real_T c11_eb_x;
  real_T c11_fb_x;
  real_T c11_gb_x;
  real_T c11_hb_x;
  real_T c11_ib_x;
  real_T c11_jb_x;
  real_T c11_kb_x;
  real_T c11_lb_x;
  real_T c11_mb_x;
  real_T c11_nb_x;
  real_T c11_ob_x;
  real_T c11_pb_x;
  real_T c11_qb_x;
  real_T c11_rb_x;
  real_T c11_sb_x;
  real_T c11_tb_x;
  real_T c11_ub_x;
  real_T c11_vb_x;
  real_T c11_wb_x;
  real_T c11_xb_x;
  real_T c11_yb_x;
  real_T c11_ac_x;
  real_T c11_bc_x;
  int32_T c11_i21;
  int32_T c11_i22;
  real_T c11_cc_x;
  real_T c11_dc_x;
  real_T c11_ec_x;
  real_T c11_fc_x;
  real_T c11_gc_x;
  real_T c11_hc_x;
  real_T c11_ic_x;
  real_T c11_jc_x;
  real_T c11_kc_x;
  real_T c11_lc_x;
  real_T c11_mc_x;
  real_T c11_nc_x;
  int32_T c11_i23;
  real_T c11_oc_x;
  real_T c11_pc_x;
  real_T c11_qc_x;
  real_T c11_rc_x;
  real_T c11_sc_x;
  real_T c11_tc_x;
  real_T c11_uc_x;
  real_T c11_vc_x;
  real_T c11_wc_x;
  real_T c11_xc_x;
  real_T c11_yc_x;
  real_T c11_ad_x;
  real_T c11_bd_x;
  real_T c11_cd_x;
  real_T c11_dd_x;
  real_T c11_ed_x;
  int32_T c11_i24;
  real_T c11_fd_x;
  real_T c11_gd_x;
  real_T c11_hd_x;
  real_T c11_id_x;
  real_T c11_jd_x;
  real_T c11_kd_x;
  real_T c11_ld_x;
  real_T c11_md_x;
  real_T c11_nd_x;
  real_T c11_od_x;
  real_T c11_pd_x;
  real_T c11_qd_x;
  real_T c11_rd_x;
  real_T c11_sd_x;
  real_T c11_td_x;
  real_T c11_ud_x;
  real_T c11_vd_x;
  real_T c11_wd_x;
  real_T c11_xd_x;
  real_T c11_yd_x;
  int32_T c11_i25;
  real_T c11_ae_x;
  real_T c11_be_x;
  real_T c11_ce_x;
  real_T c11_de_x;
  real_T c11_ee_x;
  real_T c11_fe_x;
  real_T c11_ge_x;
  real_T c11_he_x;
  real_T c11_ie_x;
  real_T c11_je_x;
  real_T c11_ke_x;
  real_T c11_le_x;
  real_T c11_me_x;
  real_T c11_ne_x;
  real_T c11_oe_x;
  real_T c11_pe_x;
  real_T c11_qe_x;
  real_T c11_re_x;
  real_T c11_se_x;
  real_T c11_te_x;
  int32_T c11_i26;
  real_T c11_ue_x;
  real_T c11_ve_x;
  real_T c11_we_x;
  real_T c11_xe_x;
  real_T c11_ye_x;
  real_T c11_af_x;
  real_T c11_bf_x;
  real_T c11_cf_x;
  real_T c11_df_x;
  real_T c11_ef_x;
  real_T c11_ff_x;
  real_T c11_gf_x;
  real_T c11_hf_x;
  real_T c11_if_x;
  real_T c11_jf_x;
  real_T c11_kf_x;
  real_T c11_lf_x;
  real_T c11_mf_x;
  real_T c11_nf_x;
  real_T c11_of_x;
  real_T c11_pf_x;
  real_T c11_qf_x;
  real_T c11_rf_x;
  real_T c11_sf_x;
  int32_T c11_i27;
  real_T c11_tf_x;
  real_T c11_uf_x;
  real_T c11_vf_x;
  real_T c11_wf_x;
  real_T c11_xf_x;
  real_T c11_yf_x;
  real_T c11_ag_x;
  real_T c11_bg_x;
  real_T c11_cg_x;
  real_T c11_dg_x;
  real_T c11_eg_x;
  real_T c11_fg_x;
  real_T c11_gg_x;
  real_T c11_hg_x;
  real_T c11_ig_x;
  real_T c11_jg_x;
  real_T c11_kg_x;
  real_T c11_lg_x;
  real_T c11_mg_x;
  real_T c11_ng_x;
  real_T c11_og_x;
  real_T c11_pg_x;
  real_T c11_qg_x;
  real_T c11_rg_x;
  int32_T c11_i28;
  real_T c11_sg_x;
  real_T c11_tg_x;
  real_T c11_ug_x;
  real_T c11_vg_x;
  real_T c11_wg_x;
  real_T c11_xg_x;
  real_T c11_yg_x;
  real_T c11_ah_x;
  real_T c11_bh_x;
  real_T c11_ch_x;
  real_T c11_dh_x;
  real_T c11_eh_x;
  real_T c11_fh_x;
  real_T c11_gh_x;
  real_T c11_hh_x;
  real_T c11_ih_x;
  int32_T c11_i29;
  real_T c11_jh_x;
  real_T c11_kh_x;
  real_T c11_lh_x;
  real_T c11_mh_x;
  real_T c11_nh_x;
  real_T c11_oh_x;
  real_T c11_ph_x;
  real_T c11_qh_x;
  real_T c11_rh_x;
  real_T c11_sh_x;
  real_T c11_th_x;
  real_T c11_uh_x;
  real_T c11_vh_x;
  real_T c11_wh_x;
  real_T c11_xh_x;
  real_T c11_yh_x;
  real_T c11_ai_x;
  real_T c11_bi_x;
  real_T c11_ci_x;
  real_T c11_di_x;
  int32_T c11_i30;
  real_T c11_ei_x;
  real_T c11_fi_x;
  real_T c11_gi_x;
  real_T c11_hi_x;
  real_T c11_ii_x;
  real_T c11_ji_x;
  real_T c11_ki_x;
  real_T c11_li_x;
  real_T c11_mi_x;
  real_T c11_ni_x;
  real_T c11_oi_x;
  real_T c11_pi_x;
  real_T c11_qi_x;
  real_T c11_ri_x;
  real_T c11_si_x;
  real_T c11_ti_x;
  real_T c11_ui_x;
  real_T c11_vi_x;
  real_T c11_wi_x;
  real_T c11_xi_x;
  int32_T c11_i31;
  real_T c11_yi_x;
  real_T c11_aj_x;
  real_T c11_bj_x;
  real_T c11_cj_x;
  real_T c11_dj_x;
  real_T c11_ej_x;
  real_T c11_fj_x;
  real_T c11_gj_x;
  real_T c11_hj_x;
  real_T c11_ij_x;
  real_T c11_jj_x;
  real_T c11_kj_x;
  real_T c11_lj_x;
  real_T c11_mj_x;
  real_T c11_nj_x;
  real_T c11_oj_x;
  real_T c11_pj_x;
  real_T c11_qj_x;
  real_T c11_rj_x;
  real_T c11_sj_x;
  real_T c11_tj_x;
  real_T c11_uj_x;
  real_T c11_vj_x;
  real_T c11_wj_x;
  int32_T c11_i32;
  real_T c11_xj_x;
  real_T c11_yj_x;
  real_T c11_ak_x;
  real_T c11_bk_x;
  real_T c11_ck_x;
  real_T c11_dk_x;
  real_T c11_ek_x;
  real_T c11_fk_x;
  real_T c11_gk_x;
  real_T c11_hk_x;
  real_T c11_ik_x;
  real_T c11_jk_x;
  real_T c11_kk_x;
  real_T c11_lk_x;
  real_T c11_mk_x;
  real_T c11_nk_x;
  real_T c11_ok_x;
  real_T c11_pk_x;
  real_T c11_qk_x;
  real_T c11_rk_x;
  real_T c11_sk_x;
  real_T c11_tk_x;
  real_T c11_uk_x;
  real_T c11_vk_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 118U, 118U, c11_b_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_xT, 0U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_yT, 1U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_zT, 2U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_qzT, 3U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_qyT, 4U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_qxT, 5U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_q1R, 6U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_q2R, 7U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_q1L, 8U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_q2L, 9U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_qgr1R, 10U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_qgr2R, 11U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_q3R, 12U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_qgr1L, 13U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_qgr2L, 14U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_q3L, 15U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t1, 16U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t2, 17U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t3, 18U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t5, 19U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t6, 20U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t7, 21U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t8, 22U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t9, 23U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t10, 24U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t11, 25U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t14, 26U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t15, 27U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t16, 28U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t17, 29U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t18, 30U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t21, 31U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t22, 32U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t23, 33U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t24, 34U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t25, 35U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t26, 36U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t33, 37U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t36, 38U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t37, 39U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t39, 40U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t40, 41U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t41, 42U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t42, 43U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t47, 44U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t54, 45U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t57, 46U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t64, 47U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t67, 48U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t74, 49U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t76, 50U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t79, 51U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t86, 52U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t89, 53U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t96, 54U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t99, 55U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t104, 56U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t107, 57U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t110, 58U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t126, 59U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t129, 60U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t131, 61U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t132, 62U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t133, 63U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t137, 64U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t138, 65U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t142, 66U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t144, 67U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t151, 68U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t152, 69U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t155, 70U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t160, 71U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t161, 72U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t170, 73U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t171, 74U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t182, 75U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t206, 76U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t228, 77U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t231, 78U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t234, 79U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t235, 80U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t237, 81U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t275, 82U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t277, 83U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t279, 84U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t284, 85U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t286, 86U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t301, 87U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t322, 88U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t4, 89U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t12, 90U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t27, 91U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t31, 92U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t35, 93U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t53, 94U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t20, 95U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t30, 96U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t43, 97U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t48, 98U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t63, 99U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t66, 100U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_t71, 101U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 102U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 103U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_q, 104U, c11_e_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_pcm, 105U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p0, 106U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p0T, 107U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_pHR, 108U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p1R, 109U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p2R, 110U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p3R, 111U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p4R, 112U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_pHL, 113U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p1L, 114U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p2L, 115U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p3L, 116U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_p4L, 117U, c11_d_sf_marshallOut,
    c11_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 4);
  c11_xT = c11_q[0];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 5);
  c11_yT = c11_q[1];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  c11_zT = c11_q[2];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_qzT = c11_q[3];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_qyT = c11_q[4];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 9);
  c11_qxT = c11_q[5];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_q1R = c11_q[6];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  c11_q2R = c11_q[7];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 12);
  c11_q1L = c11_q[8];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 13);
  c11_q2L = c11_q[9];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 14);
  c11_qgr1R = c11_q[10];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 15);
  c11_qgr2R = c11_q[11];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 16);
  c11_q3R = c11_q[12];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 17);
  c11_qgr1L = c11_q[13];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 18);
  c11_qgr2L = c11_q[14];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 19);
  c11_q3L = c11_q[15];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 21);
  for (c11_i20 = 0; c11_i20 < 3; c11_i20++) {
    c11_pcm[c11_i20] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 22);
  c11_x = c11_qzT;
  c11_t1 = c11_x;
  c11_b_x = c11_t1;
  c11_t1 = c11_b_x;
  c11_t1 = muDoubleScalarSin(c11_t1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 23);
  c11_c_x = c11_qxT;
  c11_t2 = c11_c_x;
  c11_d_x = c11_t2;
  c11_t2 = c11_d_x;
  c11_t2 = muDoubleScalarCos(c11_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 24);
  c11_t3 = c11_t1 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 25);
  c11_e_x = c11_qzT;
  c11_t5 = c11_e_x;
  c11_f_x = c11_t5;
  c11_t5 = c11_f_x;
  c11_t5 = muDoubleScalarCos(c11_t5);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 26);
  c11_g_x = c11_qyT;
  c11_t6 = c11_g_x;
  c11_h_x = c11_t6;
  c11_t6 = c11_h_x;
  c11_t6 = muDoubleScalarSin(c11_t6);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 27);
  c11_t7 = c11_t5 * c11_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 28);
  c11_i_x = c11_qxT;
  c11_t8 = c11_i_x;
  c11_j_x = c11_t8;
  c11_t8 = c11_j_x;
  c11_t8 = muDoubleScalarSin(c11_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 29);
  c11_t9 = c11_t7 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 30);
  c11_t10 = -c11_t3 + c11_t9;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 31);
  c11_k_x = c11_q2R;
  c11_t11 = c11_k_x;
  c11_l_x = c11_t11;
  c11_t11 = c11_l_x;
  c11_t11 = muDoubleScalarCos(c11_t11);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 32);
  c11_t14 = c11_t1 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 33);
  c11_t15 = c11_t7 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 34);
  c11_t16 = c11_t14 + c11_t15;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 35);
  c11_m_x = c11_q3R;
  c11_t17 = c11_m_x;
  c11_n_x = c11_t17;
  c11_t17 = c11_n_x;
  c11_t17 = muDoubleScalarCos(c11_t17);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 36);
  c11_t18 = c11_t16 * c11_t17;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 37);
  c11_o_x = c11_qyT;
  c11_t21 = c11_o_x;
  c11_p_x = c11_t21;
  c11_t21 = c11_p_x;
  c11_t21 = muDoubleScalarCos(c11_t21);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 38);
  c11_t22 = c11_t5 * c11_t21;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 39);
  c11_q_x = c11_q3R;
  c11_t23 = c11_q_x;
  c11_r_x = c11_t23;
  c11_t23 = c11_r_x;
  c11_t23 = muDoubleScalarSin(c11_t23);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 40);
  c11_t24 = c11_t22 * c11_t23;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 41);
  c11_t25 = c11_t24 + c11_t18;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 42);
  c11_s_x = c11_q2R;
  c11_t26 = c11_s_x;
  c11_t_x = c11_t26;
  c11_t26 = c11_t_x;
  c11_t26 = muDoubleScalarSin(c11_t26);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 43);
  c11_u_x = c11_q1L;
  c11_t33 = c11_u_x;
  c11_v_x = c11_t33;
  c11_t33 = c11_v_x;
  c11_t33 = muDoubleScalarCos(c11_t33);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 44);
  c11_w_x = c11_q3L;
  c11_t36 = c11_w_x;
  c11_x_x = c11_t36;
  c11_t36 = c11_x_x;
  c11_t36 = muDoubleScalarCos(c11_t36);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 45);
  c11_t37 = c11_t16 * c11_t36;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 46);
  c11_y_x = c11_q3L;
  c11_t39 = c11_y_x;
  c11_ab_x = c11_t39;
  c11_t39 = c11_ab_x;
  c11_t39 = muDoubleScalarSin(c11_t39);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 47);
  c11_t40 = c11_t22 * c11_t39;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 48);
  c11_t41 = -c11_t40 + c11_t37;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 49);
  c11_bb_x = c11_q1L;
  c11_t42 = c11_bb_x;
  c11_cb_x = c11_t42;
  c11_t42 = c11_cb_x;
  c11_t42 = muDoubleScalarSin(c11_t42);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 50);
  c11_t47 = (((((((((0.000563253 * c11_t3 - 0.000191189 * c11_t10 * c11_t11) +
                    0.0015191382403008 * c11_t18) + 0.15096349872 * c11_t14) -
                  0.000191189 * c11_t25 * c11_t26) + 0.00712672 * c11_t25 *
                 c11_t11) - 0.00712672 * c11_t10 * c11_t26) + 0.000339818 *
               c11_t10 * c11_t33) + 0.0015191382403008 * c11_t37) + 0.000339818 *
             c11_t41 * c11_t42) + 0.0074766 * c11_t41 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 51);
  c11_db_x = c11_qgr2R;
  c11_t54 = c11_db_x;
  c11_eb_x = c11_t54;
  c11_t54 = c11_eb_x;
  c11_t54 = muDoubleScalarCos(c11_t54);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 52);
  c11_fb_x = c11_qgr2R;
  c11_t57 = c11_fb_x;
  c11_gb_x = c11_t57;
  c11_t57 = c11_gb_x;
  c11_t57 = muDoubleScalarSin(c11_t57);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 53);
  c11_hb_x = c11_qgr2L;
  c11_t64 = c11_hb_x;
  c11_ib_x = c11_t64;
  c11_t64 = c11_ib_x;
  c11_t64 = muDoubleScalarCos(c11_t64);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 54);
  c11_jb_x = c11_qgr2L;
  c11_t67 = c11_jb_x;
  c11_kb_x = c11_t67;
  c11_t67 = c11_kb_x;
  c11_t67 = muDoubleScalarSin(c11_t67);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 55);
  c11_t74 = (((((((((-0.0074766 * c11_t10 * c11_t42 - 0.0573115 * c11_t16 *
                     c11_t23) - 0.0573115 * c11_t16 * c11_t39) - 0.00192121 *
                   c11_t10 * c11_t54) - 0.00192121 * c11_t25 * c11_t57) +
                 0.001929878553636 * c11_t25 * c11_t54) - 0.00192988 * c11_t10 *
                c11_t57) - 0.00192121 * c11_t10 * c11_t64) - 0.00192121 *
              c11_t41 * c11_t67) + 0.001929878553636 * c11_t41 * c11_t64) -
    0.00192988 * c11_t10 * c11_t67;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 56);
  c11_lb_x = c11_qgr1L;
  c11_t76 = c11_lb_x;
  c11_mb_x = c11_t76;
  c11_t76 = c11_mb_x;
  c11_t76 = muDoubleScalarCos(c11_t76);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 57);
  c11_nb_x = c11_qgr1L;
  c11_t79 = c11_nb_x;
  c11_ob_x = c11_t79;
  c11_t79 = c11_ob_x;
  c11_t79 = muDoubleScalarSin(c11_t79);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 58);
  c11_pb_x = c11_q2L;
  c11_t86 = c11_pb_x;
  c11_qb_x = c11_t86;
  c11_t86 = c11_qb_x;
  c11_t86 = muDoubleScalarCos(c11_t86);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 59);
  c11_rb_x = c11_q2L;
  c11_t89 = c11_rb_x;
  c11_sb_x = c11_t89;
  c11_t89 = c11_sb_x;
  c11_t89 = muDoubleScalarSin(c11_t89);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 60);
  c11_tb_x = c11_q1R;
  c11_t96 = c11_tb_x;
  c11_ub_x = c11_t96;
  c11_t96 = c11_ub_x;
  c11_t96 = muDoubleScalarCos(c11_t96);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 61);
  c11_vb_x = c11_q1R;
  c11_t99 = c11_vb_x;
  c11_wb_x = c11_t99;
  c11_t99 = c11_wb_x;
  c11_t99 = muDoubleScalarSin(c11_t99);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 62);
  c11_t104 = (((((((((0.001953468825084 * c11_t10 * c11_t76 + 0.001953468825084 *
                      c11_t41 * c11_t79) + 0.001942481936304 * c11_t41 * c11_t76)
                    - 0.00194248 * c11_t10 * c11_t79) - 0.000191189 * c11_t10 *
                   c11_t86) - 0.000191189 * c11_t41 * c11_t89) + 0.00712672 *
                 c11_t41 * c11_t86) - 0.00712672 * c11_t10 * c11_t89) +
               0.000339818 * c11_t10 * c11_t96) + 0.000339818 * c11_t25 *
              c11_t99) + 0.0074766 * c11_t25 * c11_t96;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 63);
  c11_xb_x = c11_qgr1R;
  c11_t107 = c11_xb_x;
  c11_yb_x = c11_t107;
  c11_t107 = c11_yb_x;
  c11_t107 = muDoubleScalarCos(c11_t107);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 64);
  c11_ac_x = c11_qgr1R;
  c11_t110 = c11_ac_x;
  c11_bc_x = c11_t110;
  c11_t110 = c11_bc_x;
  c11_t110 = muDoubleScalarSin(c11_t110);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 65);
  c11_t126 = ((((((((((-0.0074766 * c11_t10 * c11_t99 + 0.001953468825084 *
                       c11_t10 * c11_t107) + 0.001953468825084 * c11_t25 *
                      c11_t110) + 0.001942481936304 * c11_t25 * c11_t107) -
                    0.00194248 * c11_t10 * c11_t110) + c11_xT) - 0.000563253 *
                  c11_t9) + 0.0015191382403008 * c11_t24) + 0.15096349872 *
                c11_t15) - 0.00151914 * c11_t40) - 0.0573115 * c11_t22 * c11_t36)
    + 0.0573115 * c11_t22 * c11_t17;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 66);
  c11_t129 = c11_t5 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 67);
  c11_t131 = c11_t1 * c11_t6;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 68);
  c11_t132 = c11_t131 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 69);
  c11_t133 = c11_t129 + c11_t132;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 70);
  c11_t137 = c11_t1 * c11_t21;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 71);
  c11_t138 = c11_t137 * c11_t23;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 72);
  c11_t142 = c11_t131 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 73);
  c11_t144 = c11_t137 * c11_t39;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 74);
  c11_t151 = c11_t5 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 75);
  c11_t152 = -c11_t151 + c11_t142;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 76);
  c11_t155 = (((((((((-0.000563253 * c11_t129 - 0.000191189 * c11_t133 * c11_t11)
                     - 0.000563253 * c11_t132) + 0.0015191382403008 * c11_t138)
                   + 0.0573115 * c11_t137 * c11_t17) + 0.15096349872 * c11_t142)
                 - 0.00151914 * c11_t144) - 0.0573115 * c11_t137 * c11_t36) +
               c11_yT) - 0.0074766 * c11_t133 * c11_t42) - 0.0573115 * c11_t152 *
    c11_t23;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 77);
  c11_t160 = c11_t152 * c11_t17;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 78);
  c11_t161 = c11_t138 + c11_t160;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 79);
  c11_t170 = c11_t152 * c11_t36;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 80);
  c11_t171 = -c11_t144 + c11_t170;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 81);
  c11_t182 = (((((((((-0.0573115 * c11_t152 * c11_t39 - 0.00192121 * c11_t133 *
                      c11_t54) - 0.00192121 * c11_t161 * c11_t57) +
                    0.001929878553636 * c11_t161 * c11_t54) - 0.00192988 *
                   c11_t133 * c11_t57) - 0.00192121 * c11_t133 * c11_t64) -
                 0.00192121 * c11_t171 * c11_t67) + 0.001929878553636 * c11_t171
                * c11_t64) - 0.00192988 * c11_t133 * c11_t67) +
              0.001953468825084 * c11_t133 * c11_t76) + 0.001953468825084 *
    c11_t171 * c11_t79;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 82);
  c11_t206 = (((((((((0.001942481936304 * c11_t171 * c11_t76 - 0.00194248 *
                      c11_t133 * c11_t79) - 0.000191189 * c11_t133 * c11_t86) -
                    0.000191189 * c11_t171 * c11_t89) + 0.00712672 * c11_t171 *
                   c11_t86) - 0.00712672 * c11_t133 * c11_t89) + 0.000339818 *
                 c11_t133 * c11_t96) + 0.000339818 * c11_t161 * c11_t99) +
               0.0074766 * c11_t161 * c11_t96) - 0.0074766 * c11_t133 * c11_t99)
    + 0.001953468825084 * c11_t133 * c11_t107;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 83);
  c11_t228 = ((((((((((0.001953468825084 * c11_t161 * c11_t110 +
                       0.001942481936304 * c11_t161 * c11_t107) - 0.00194248 *
                      c11_t133 * c11_t110) + 0.0015191382403008 * c11_t160) -
                    0.150963 * c11_t151) - 0.000191189 * c11_t161 * c11_t26) +
                  0.00712672 * c11_t161 * c11_t11) - 0.00712672 * c11_t133 *
                 c11_t26) + 0.000339818 * c11_t133 * c11_t33) +
               0.0015191382403008 * c11_t170) + 0.000339818 * c11_t171 * c11_t42)
    + 0.0074766 * c11_t171 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 84);
  c11_t231 = c11_t21 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 85);
  c11_t234 = c11_t21 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 86);
  c11_t235 = c11_t234 * c11_t17;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 87);
  c11_t237 = c11_t234 * c11_t36;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 88);
  c11_t275 = (((((((((-0.000191189 * c11_t231 * c11_t11 - 0.00712672 * c11_t231 *
                      c11_t26) + 0.000339818 * c11_t231 * c11_t33) - 0.0074766 *
                    c11_t231 * c11_t42) + 0.001953468825084 * c11_t231 * c11_t76)
                  - 0.00194248 * c11_t231 * c11_t79) - 0.00712672 * c11_t231 *
                 c11_t89) - 0.00192988 * c11_t231 * c11_t67) - 0.00192121 *
               c11_t231 * c11_t54) - 0.00192988 * c11_t231 * c11_t57) + c11_zT;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 89);
  c11_t277 = c11_t6 * c11_t23;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 90);
  c11_t279 = -c11_t277 + c11_t235;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 91);
  c11_t284 = c11_t6 * c11_t39;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 92);
  c11_t286 = c11_t284 + c11_t237;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 93);
  c11_t301 = (((((((((-0.00151914 * c11_t277 - 0.000191189 * c11_t279 * c11_t26)
                     + 0.00712672 * c11_t279 * c11_t11) + 0.0015191382403008 *
                    c11_t284) + 0.000339818 * c11_t286 * c11_t42) + 0.0074766 *
                  c11_t286 * c11_t33) - 0.0573115 * c11_t6 * c11_t17) +
                0.0573115 * c11_t6 * c11_t36) - 0.00192121 * c11_t279 * c11_t57)
              + 0.001929878553636 * c11_t279 * c11_t54) - 0.00192121 * c11_t286 *
    c11_t67;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 94);
  c11_t322 = (((((((((0.001929878553636 * c11_t286 * c11_t64 + 0.001953468825084
                      * c11_t286 * c11_t79) + 0.001942481936304 * c11_t286 *
                     c11_t76) - 0.000191189 * c11_t286 * c11_t89) + 0.00712672 *
                   c11_t286 * c11_t86) - 0.000563253 * c11_t231) + 0.15096349872
                 * c11_t234) + 0.000339818 * c11_t279 * c11_t99) + 0.0074766 *
               c11_t279 * c11_t96) + 0.001953468825084 * c11_t279 * c11_t110) +
    0.001942481936304 * c11_t279 * c11_t107;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 95);
  c11_pcm[0] = ((c11_t47 + c11_t74) + c11_t104) + c11_t126;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 96);
  c11_pcm[1] = ((c11_t155 + c11_t182) + c11_t206) + c11_t228;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 97);
  c11_pcm[2] = (((((((((((-0.00192121 * c11_t231 * c11_t64 + 0.0015191382403008 *
    c11_t235) + 0.0015191382403008 * c11_t237) - 0.0573115 * c11_t234 * c11_t39)
                       - 0.000191189 * c11_t231 * c11_t86) - 0.0573115 *
                      c11_t234 * c11_t23) + 0.000339818 * c11_t231 * c11_t96) -
                    0.0074766 * c11_t231 * c11_t99) + 0.001953468825084 *
                   c11_t231 * c11_t107) - 0.00194248 * c11_t231 * c11_t110) +
                 c11_t275) + c11_t301) + c11_t322;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 99);
  for (c11_i21 = 0; c11_i21 < 3; c11_i21++) {
    c11_p0[c11_i21] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 100);
  c11_p0[0] = c11_xT;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 101);
  c11_p0[1] = c11_yT;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 102);
  c11_p0[2] = c11_zT;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 104);
  for (c11_i22 = 0; c11_i22 < 3; c11_i22++) {
    c11_p0T[c11_i22] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 105);
  c11_cc_x = c11_qzT;
  c11_t1 = c11_cc_x;
  c11_dc_x = c11_t1;
  c11_t1 = c11_dc_x;
  c11_t1 = muDoubleScalarSin(c11_t1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 106);
  c11_ec_x = c11_qxT;
  c11_t2 = c11_ec_x;
  c11_fc_x = c11_t2;
  c11_t2 = c11_fc_x;
  c11_t2 = muDoubleScalarSin(c11_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 107);
  c11_gc_x = c11_qzT;
  c11_t5 = c11_gc_x;
  c11_hc_x = c11_t5;
  c11_t5 = c11_hc_x;
  c11_t5 = muDoubleScalarCos(c11_t5);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 108);
  c11_ic_x = c11_qyT;
  c11_t6 = c11_ic_x;
  c11_jc_x = c11_t6;
  c11_t6 = c11_jc_x;
  c11_t6 = muDoubleScalarSin(c11_t6);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 109);
  c11_kc_x = c11_qxT;
  c11_t8 = c11_kc_x;
  c11_lc_x = c11_t8;
  c11_t8 = c11_lc_x;
  c11_t8 = muDoubleScalarCos(c11_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 110);
  c11_mc_x = c11_qyT;
  c11_t18 = c11_mc_x;
  c11_nc_x = c11_t18;
  c11_t18 = c11_nc_x;
  c11_t18 = muDoubleScalarCos(c11_t18);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 111);
  c11_p0T[0] = (c11_xT + 0.58 * c11_t1 * c11_t2) + 0.58 * c11_t5 * c11_t6 *
    c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 112);
  c11_p0T[1] = (c11_yT - 0.58 * c11_t5 * c11_t2) + 0.58 * c11_t1 * c11_t6 *
    c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 113);
  c11_p0T[2] = c11_zT + 0.58 * c11_t18 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 115);
  for (c11_i23 = 0; c11_i23 < 3; c11_i23++) {
    c11_pHR[c11_i23] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 116);
  c11_oc_x = c11_qzT;
  c11_t1 = c11_oc_x;
  c11_pc_x = c11_t1;
  c11_t1 = c11_pc_x;
  c11_t1 = muDoubleScalarCos(c11_t1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 117);
  c11_qc_x = c11_qyT;
  c11_t2 = c11_qc_x;
  c11_rc_x = c11_t2;
  c11_t2 = c11_rc_x;
  c11_t2 = muDoubleScalarCos(c11_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 118);
  c11_sc_x = c11_q3R;
  c11_t4 = c11_sc_x;
  c11_tc_x = c11_t4;
  c11_t4 = c11_tc_x;
  c11_t4 = muDoubleScalarCos(c11_t4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 119);
  c11_uc_x = c11_qzT;
  c11_t7 = c11_uc_x;
  c11_vc_x = c11_t7;
  c11_t7 = c11_vc_x;
  c11_t7 = muDoubleScalarSin(c11_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 120);
  c11_wc_x = c11_qxT;
  c11_t8 = c11_wc_x;
  c11_xc_x = c11_t8;
  c11_t8 = c11_xc_x;
  c11_t8 = muDoubleScalarSin(c11_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 121);
  c11_yc_x = c11_qyT;
  c11_t10 = c11_yc_x;
  c11_ad_x = c11_t10;
  c11_t10 = c11_ad_x;
  c11_t10 = muDoubleScalarSin(c11_t10);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 122);
  c11_bd_x = c11_qxT;
  c11_t12 = c11_bd_x;
  c11_cd_x = c11_t12;
  c11_t12 = c11_cd_x;
  c11_t12 = muDoubleScalarCos(c11_t12);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 123);
  c11_dd_x = c11_q3R;
  c11_t15 = c11_dd_x;
  c11_ed_x = c11_t15;
  c11_t15 = c11_ed_x;
  c11_t15 = muDoubleScalarSin(c11_t15);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 124);
  c11_pHR[0] = (c11_xT + 0.1834 * c11_t1 * c11_t2 * c11_t4) - 0.1834 * (c11_t7 *
    c11_t8 + c11_t1 * c11_t10 * c11_t12) * c11_t15;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 125);
  c11_pHR[1] = (c11_yT + 0.1834 * c11_t7 * c11_t2 * c11_t4) - 0.1834 * (-c11_t1 *
    c11_t8 + c11_t7 * c11_t10 * c11_t12) * c11_t15;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 126);
  c11_pHR[2] = (c11_zT - 0.1834 * c11_t10 * c11_t4) - 0.1834 * c11_t2 * c11_t12 *
    c11_t15;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 128U);
  for (c11_i24 = 0; c11_i24 < 3; c11_i24++) {
    c11_p1R[c11_i24] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 129U);
  c11_fd_x = c11_qzT;
  c11_t1 = c11_fd_x;
  c11_gd_x = c11_t1;
  c11_t1 = c11_gd_x;
  c11_t1 = muDoubleScalarCos(c11_t1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 130U);
  c11_hd_x = c11_qyT;
  c11_t2 = c11_hd_x;
  c11_id_x = c11_t2;
  c11_t2 = c11_id_x;
  c11_t2 = muDoubleScalarCos(c11_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 131U);
  c11_t3 = c11_t1 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 132U);
  c11_jd_x = c11_q3R;
  c11_t4 = c11_jd_x;
  c11_kd_x = c11_t4;
  c11_t4 = c11_kd_x;
  c11_t4 = muDoubleScalarCos(c11_t4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 133U);
  c11_ld_x = c11_qzT;
  c11_t7 = c11_ld_x;
  c11_md_x = c11_t7;
  c11_t7 = c11_md_x;
  c11_t7 = muDoubleScalarSin(c11_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 134U);
  c11_nd_x = c11_qxT;
  c11_t8 = c11_nd_x;
  c11_od_x = c11_t8;
  c11_t8 = c11_od_x;
  c11_t8 = muDoubleScalarSin(c11_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 135U);
  c11_pd_x = c11_qyT;
  c11_t10 = c11_pd_x;
  c11_qd_x = c11_t10;
  c11_t10 = c11_qd_x;
  c11_t10 = muDoubleScalarSin(c11_t10);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 136U);
  c11_t11 = c11_t1 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 137U);
  c11_rd_x = c11_qxT;
  c11_t12 = c11_rd_x;
  c11_sd_x = c11_t12;
  c11_t12 = c11_sd_x;
  c11_t12 = muDoubleScalarCos(c11_t12);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 138U);
  c11_t14 = c11_t7 * c11_t8 + c11_t11 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 139U);
  c11_td_x = c11_q3R;
  c11_t15 = c11_td_x;
  c11_ud_x = c11_t15;
  c11_t15 = c11_ud_x;
  c11_t15 = muDoubleScalarSin(c11_t15);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 140U);
  c11_vd_x = c11_q1R;
  c11_t21 = c11_vd_x;
  c11_wd_x = c11_t21;
  c11_t21 = c11_wd_x;
  c11_t21 = muDoubleScalarSin(c11_t21);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 141U);
  c11_xd_x = c11_q1R;
  c11_t27 = c11_xd_x;
  c11_yd_x = c11_t27;
  c11_t27 = c11_yd_x;
  c11_t27 = muDoubleScalarCos(c11_t27);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 142U);
  c11_t31 = c11_t7 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 143U);
  c11_t35 = c11_t7 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 144U);
  c11_t37 = -c11_t1 * c11_t8 + c11_t35 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 145U);
  c11_t53 = c11_t2 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 146U);
  c11_p1R[0] = (((c11_xT + 0.1834 * c11_t3 * c11_t4) - 0.1834 * c11_t14 *
                 c11_t15) - 0.4 * (-c11_t7 * c11_t12 + c11_t11 * c11_t8) *
                c11_t21) + 0.4 * (c11_t3 * c11_t15 + c11_t14 * c11_t4) * c11_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 147U);
  c11_p1R[1] = (((c11_yT + 0.1834 * c11_t31 * c11_t4) - 0.1834 * c11_t37 *
                 c11_t15) - 0.4 * (c11_t1 * c11_t12 + c11_t35 * c11_t8) *
                c11_t21) + 0.4 * (c11_t31 * c11_t15 + c11_t37 * c11_t4) *
    c11_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 148U);
  c11_p1R[2] = (((c11_zT - 0.1834 * c11_t10 * c11_t4) - 0.1834 * c11_t53 *
                 c11_t15) - 0.4 * c11_t2 * c11_t8 * c11_t21) + 0.4 * (-c11_t10 *
    c11_t15 + c11_t53 * c11_t4) * c11_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 150U);
  for (c11_i25 = 0; c11_i25 < 3; c11_i25++) {
    c11_p2R[c11_i25] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 151U);
  c11_ae_x = c11_qzT;
  c11_t1 = c11_ae_x;
  c11_be_x = c11_t1;
  c11_t1 = c11_be_x;
  c11_t1 = muDoubleScalarCos(c11_t1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 152U);
  c11_ce_x = c11_qyT;
  c11_t2 = c11_ce_x;
  c11_de_x = c11_t2;
  c11_t2 = c11_de_x;
  c11_t2 = muDoubleScalarCos(c11_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 153U);
  c11_t3 = c11_t1 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 154U);
  c11_ee_x = c11_q3R;
  c11_t4 = c11_ee_x;
  c11_fe_x = c11_t4;
  c11_t4 = c11_fe_x;
  c11_t4 = muDoubleScalarCos(c11_t4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 155U);
  c11_ge_x = c11_qzT;
  c11_t7 = c11_ge_x;
  c11_he_x = c11_t7;
  c11_t7 = c11_he_x;
  c11_t7 = muDoubleScalarSin(c11_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 156U);
  c11_ie_x = c11_qxT;
  c11_t8 = c11_ie_x;
  c11_je_x = c11_t8;
  c11_t8 = c11_je_x;
  c11_t8 = muDoubleScalarSin(c11_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 157U);
  c11_ke_x = c11_qyT;
  c11_t10 = c11_ke_x;
  c11_le_x = c11_t10;
  c11_t10 = c11_le_x;
  c11_t10 = muDoubleScalarSin(c11_t10);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 158U);
  c11_t11 = c11_t1 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 159U);
  c11_me_x = c11_qxT;
  c11_t12 = c11_me_x;
  c11_ne_x = c11_t12;
  c11_t12 = c11_ne_x;
  c11_t12 = muDoubleScalarCos(c11_t12);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 160U);
  c11_t14 = c11_t7 * c11_t8 + c11_t11 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 161U);
  c11_oe_x = c11_q3R;
  c11_t15 = c11_oe_x;
  c11_pe_x = c11_t15;
  c11_t15 = c11_pe_x;
  c11_t15 = muDoubleScalarSin(c11_t15);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 162U);
  c11_qe_x = c11_q2R;
  c11_t21 = c11_qe_x;
  c11_re_x = c11_t21;
  c11_t21 = c11_re_x;
  c11_t21 = muDoubleScalarSin(c11_t21);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 163U);
  c11_se_x = c11_q2R;
  c11_t27 = c11_se_x;
  c11_te_x = c11_t27;
  c11_t27 = c11_te_x;
  c11_t27 = muDoubleScalarCos(c11_t27);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 164U);
  c11_t31 = c11_t7 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 165U);
  c11_t35 = c11_t7 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 166U);
  c11_t37 = -c11_t1 * c11_t8 + c11_t35 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 167U);
  c11_t53 = c11_t2 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 168U);
  c11_p2R[0] = (((c11_xT + 0.1834 * c11_t3 * c11_t4) - 0.1834 * c11_t14 *
                 c11_t15) - 0.5 * (-c11_t7 * c11_t12 + c11_t11 * c11_t8) *
                c11_t21) + 0.5 * (c11_t3 * c11_t15 + c11_t14 * c11_t4) * c11_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 169U);
  c11_p2R[1] = (((c11_yT + 0.1834 * c11_t31 * c11_t4) - 0.1834 * c11_t37 *
                 c11_t15) - 0.5 * (c11_t1 * c11_t12 + c11_t35 * c11_t8) *
                c11_t21) + 0.5 * (c11_t31 * c11_t15 + c11_t37 * c11_t4) *
    c11_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 170U);
  c11_p2R[2] = (((c11_zT - 0.1834 * c11_t10 * c11_t4) - 0.1834 * c11_t53 *
                 c11_t15) - 0.5 * c11_t2 * c11_t8 * c11_t21) + 0.5 * (-c11_t10 *
    c11_t15 + c11_t53 * c11_t4) * c11_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 172U);
  for (c11_i26 = 0; c11_i26 < 3; c11_i26++) {
    c11_p3R[c11_i26] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 173U);
  c11_ue_x = c11_qzT;
  c11_t1 = c11_ue_x;
  c11_ve_x = c11_t1;
  c11_t1 = c11_ve_x;
  c11_t1 = muDoubleScalarCos(c11_t1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 174U);
  c11_we_x = c11_qyT;
  c11_t2 = c11_we_x;
  c11_xe_x = c11_t2;
  c11_t2 = c11_xe_x;
  c11_t2 = muDoubleScalarCos(c11_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 175U);
  c11_t3 = c11_t1 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 176U);
  c11_ye_x = c11_q3R;
  c11_t4 = c11_ye_x;
  c11_af_x = c11_t4;
  c11_t4 = c11_af_x;
  c11_t4 = muDoubleScalarCos(c11_t4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 177U);
  c11_bf_x = c11_qzT;
  c11_t7 = c11_bf_x;
  c11_cf_x = c11_t7;
  c11_t7 = c11_cf_x;
  c11_t7 = muDoubleScalarSin(c11_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 178U);
  c11_df_x = c11_qxT;
  c11_t8 = c11_df_x;
  c11_ef_x = c11_t8;
  c11_t8 = c11_ef_x;
  c11_t8 = muDoubleScalarSin(c11_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 179U);
  c11_ff_x = c11_qyT;
  c11_t10 = c11_ff_x;
  c11_gf_x = c11_t10;
  c11_t10 = c11_gf_x;
  c11_t10 = muDoubleScalarSin(c11_t10);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 180U);
  c11_t11 = c11_t1 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 181U);
  c11_hf_x = c11_qxT;
  c11_t12 = c11_hf_x;
  c11_if_x = c11_t12;
  c11_t12 = c11_if_x;
  c11_t12 = muDoubleScalarCos(c11_t12);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 182U);
  c11_t14 = c11_t7 * c11_t8 + c11_t11 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 183U);
  c11_jf_x = c11_q3R;
  c11_t15 = c11_jf_x;
  c11_kf_x = c11_t15;
  c11_t15 = c11_kf_x;
  c11_t15 = muDoubleScalarSin(c11_t15);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 184U);
  c11_t20 = -c11_t7 * c11_t12 + c11_t11 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 185U);
  c11_lf_x = c11_q1R;
  c11_t21 = c11_lf_x;
  c11_mf_x = c11_t21;
  c11_t21 = c11_mf_x;
  c11_t21 = muDoubleScalarSin(c11_t21);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 186U);
  c11_t26 = c11_t3 * c11_t15 + c11_t14 * c11_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 187U);
  c11_nf_x = c11_q1R;
  c11_t27 = c11_nf_x;
  c11_of_x = c11_t27;
  c11_t27 = c11_of_x;
  c11_t27 = muDoubleScalarCos(c11_t27);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 188U);
  c11_pf_x = c11_q2R;
  c11_t30 = c11_pf_x;
  c11_qf_x = c11_t30;
  c11_t30 = c11_qf_x;
  c11_t30 = muDoubleScalarSin(c11_t30);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 189U);
  c11_rf_x = c11_q2R;
  c11_t33 = c11_rf_x;
  c11_sf_x = c11_t33;
  c11_t33 = c11_sf_x;
  c11_t33 = muDoubleScalarCos(c11_t33);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 190U);
  c11_t37 = c11_t7 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 191U);
  c11_t41 = c11_t7 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 192U);
  c11_t43 = -c11_t1 * c11_t8 + c11_t41 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 193U);
  c11_t48 = c11_t1 * c11_t12 + c11_t41 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 194U);
  c11_t53 = c11_t37 * c11_t15 + c11_t43 * c11_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 195U);
  c11_t63 = c11_t2 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 196U);
  c11_t66 = c11_t2 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 197U);
  c11_t71 = -c11_t10 * c11_t15 + c11_t63 * c11_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 198U);
  c11_p3R[0] = (((((c11_xT + 0.1834 * c11_t3 * c11_t4) - 0.1834 * c11_t14 *
                   c11_t15) - 0.4 * c11_t20 * c11_t21) + 0.4 * c11_t26 * c11_t27)
                - 0.5 * c11_t20 * c11_t30) + 0.5 * c11_t26 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 199U);
  c11_p3R[1] = (((((c11_yT + 0.1834 * c11_t37 * c11_t4) - 0.1834 * c11_t43 *
                   c11_t15) - 0.4 * c11_t48 * c11_t21) + 0.4 * c11_t53 * c11_t27)
                - 0.5 * c11_t48 * c11_t30) + 0.5 * c11_t53 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 200U);
  c11_p3R[2] = (((((c11_zT - 0.1834 * c11_t10 * c11_t4) - 0.1834 * c11_t63 *
                   c11_t15) - 0.4 * c11_t66 * c11_t21) + 0.4 * c11_t71 * c11_t27)
                - 0.5 * c11_t66 * c11_t30) + 0.5 * c11_t71 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 202U);
  for (c11_i27 = 0; c11_i27 < 3; c11_i27++) {
    c11_p4R[c11_i27] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 203U);
  c11_tf_x = c11_qzT;
  c11_t1 = c11_tf_x;
  c11_uf_x = c11_t1;
  c11_t1 = c11_uf_x;
  c11_t1 = muDoubleScalarCos(c11_t1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 204U);
  c11_vf_x = c11_qyT;
  c11_t2 = c11_vf_x;
  c11_wf_x = c11_t2;
  c11_t2 = c11_wf_x;
  c11_t2 = muDoubleScalarCos(c11_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 205U);
  c11_t3 = c11_t1 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 206U);
  c11_xf_x = c11_q3R;
  c11_t4 = c11_xf_x;
  c11_yf_x = c11_t4;
  c11_t4 = c11_yf_x;
  c11_t4 = muDoubleScalarCos(c11_t4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 207U);
  c11_ag_x = c11_qzT;
  c11_t7 = c11_ag_x;
  c11_bg_x = c11_t7;
  c11_t7 = c11_bg_x;
  c11_t7 = muDoubleScalarSin(c11_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 208U);
  c11_cg_x = c11_qxT;
  c11_t8 = c11_cg_x;
  c11_dg_x = c11_t8;
  c11_t8 = c11_dg_x;
  c11_t8 = muDoubleScalarSin(c11_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 209U);
  c11_eg_x = c11_qyT;
  c11_t10 = c11_eg_x;
  c11_fg_x = c11_t10;
  c11_t10 = c11_fg_x;
  c11_t10 = muDoubleScalarSin(c11_t10);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 210U);
  c11_t11 = c11_t1 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 211U);
  c11_gg_x = c11_qxT;
  c11_t12 = c11_gg_x;
  c11_hg_x = c11_t12;
  c11_t12 = c11_hg_x;
  c11_t12 = muDoubleScalarCos(c11_t12);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 212U);
  c11_t14 = c11_t7 * c11_t8 + c11_t11 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 213U);
  c11_ig_x = c11_q3R;
  c11_t15 = c11_ig_x;
  c11_jg_x = c11_t15;
  c11_t15 = c11_jg_x;
  c11_t15 = muDoubleScalarSin(c11_t15);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 214U);
  c11_t20 = -c11_t7 * c11_t12 + c11_t11 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 215U);
  c11_kg_x = c11_q2R;
  c11_t21 = c11_kg_x;
  c11_lg_x = c11_t21;
  c11_t21 = c11_lg_x;
  c11_t21 = muDoubleScalarSin(c11_t21);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 216U);
  c11_t26 = c11_t3 * c11_t15 + c11_t14 * c11_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 217U);
  c11_mg_x = c11_q2R;
  c11_t27 = c11_mg_x;
  c11_ng_x = c11_t27;
  c11_t27 = c11_ng_x;
  c11_t27 = muDoubleScalarCos(c11_t27);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 218U);
  c11_og_x = c11_q1R;
  c11_t30 = c11_og_x;
  c11_pg_x = c11_t30;
  c11_t30 = c11_pg_x;
  c11_t30 = muDoubleScalarSin(c11_t30);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 219U);
  c11_qg_x = c11_q1R;
  c11_t33 = c11_qg_x;
  c11_rg_x = c11_t33;
  c11_t33 = c11_rg_x;
  c11_t33 = muDoubleScalarCos(c11_t33);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 220U);
  c11_t37 = c11_t7 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 221U);
  c11_t41 = c11_t7 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 222U);
  c11_t43 = -c11_t1 * c11_t8 + c11_t41 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 223U);
  c11_t48 = c11_t1 * c11_t12 + c11_t41 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 224U);
  c11_t53 = c11_t37 * c11_t15 + c11_t43 * c11_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 225U);
  c11_t63 = c11_t2 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 226U);
  c11_t66 = c11_t2 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 227U);
  c11_t71 = -c11_t10 * c11_t15 + c11_t63 * c11_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 228U);
  c11_p4R[0] = (((((c11_xT + 0.1834 * c11_t3 * c11_t4) - 0.1834 * c11_t14 *
                   c11_t15) - 0.5 * c11_t20 * c11_t21) + 0.5 * c11_t26 * c11_t27)
                - 0.5 * c11_t20 * c11_t30) + 0.5 * c11_t26 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 229U);
  c11_p4R[1] = (((((c11_yT + 0.1834 * c11_t37 * c11_t4) - 0.1834 * c11_t43 *
                   c11_t15) - 0.5 * c11_t48 * c11_t21) + 0.5 * c11_t53 * c11_t27)
                - 0.5 * c11_t48 * c11_t30) + 0.5 * c11_t53 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 230U);
  c11_p4R[2] = (((((c11_zT - 0.1834 * c11_t10 * c11_t4) - 0.1834 * c11_t63 *
                   c11_t15) - 0.5 * c11_t66 * c11_t21) + 0.5 * c11_t71 * c11_t27)
                - 0.5 * c11_t66 * c11_t30) + 0.5 * c11_t71 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 232U);
  for (c11_i28 = 0; c11_i28 < 3; c11_i28++) {
    c11_pHL[c11_i28] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 233U);
  c11_sg_x = c11_qzT;
  c11_t1 = c11_sg_x;
  c11_tg_x = c11_t1;
  c11_t1 = c11_tg_x;
  c11_t1 = muDoubleScalarCos(c11_t1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 234U);
  c11_ug_x = c11_qyT;
  c11_t2 = c11_ug_x;
  c11_vg_x = c11_t2;
  c11_t2 = c11_vg_x;
  c11_t2 = muDoubleScalarCos(c11_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 235U);
  c11_wg_x = c11_q3L;
  c11_t4 = c11_wg_x;
  c11_xg_x = c11_t4;
  c11_t4 = c11_xg_x;
  c11_t4 = muDoubleScalarCos(c11_t4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 236U);
  c11_yg_x = c11_qzT;
  c11_t7 = c11_yg_x;
  c11_ah_x = c11_t7;
  c11_t7 = c11_ah_x;
  c11_t7 = muDoubleScalarSin(c11_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 237U);
  c11_bh_x = c11_qxT;
  c11_t8 = c11_bh_x;
  c11_ch_x = c11_t8;
  c11_t8 = c11_ch_x;
  c11_t8 = muDoubleScalarSin(c11_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 238U);
  c11_dh_x = c11_qyT;
  c11_t10 = c11_dh_x;
  c11_eh_x = c11_t10;
  c11_t10 = c11_eh_x;
  c11_t10 = muDoubleScalarSin(c11_t10);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 239U);
  c11_fh_x = c11_qxT;
  c11_t12 = c11_fh_x;
  c11_gh_x = c11_t12;
  c11_t12 = c11_gh_x;
  c11_t12 = muDoubleScalarCos(c11_t12);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 240U);
  c11_hh_x = c11_q3L;
  c11_t15 = c11_hh_x;
  c11_ih_x = c11_t15;
  c11_t15 = c11_ih_x;
  c11_t15 = muDoubleScalarSin(c11_t15);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 241U);
  c11_pHL[0] = (c11_xT - 0.1834 * c11_t1 * c11_t2 * c11_t4) - 0.1834 * (c11_t7 *
    c11_t8 + c11_t1 * c11_t10 * c11_t12) * c11_t15;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 242U);
  c11_pHL[1] = (c11_yT - 0.1834 * c11_t7 * c11_t2 * c11_t4) - 0.1834 * (-c11_t1 *
    c11_t8 + c11_t7 * c11_t10 * c11_t12) * c11_t15;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 243U);
  c11_pHL[2] = (c11_zT + 0.1834 * c11_t10 * c11_t4) - 0.1834 * c11_t2 * c11_t12 *
    c11_t15;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 245U);
  for (c11_i29 = 0; c11_i29 < 3; c11_i29++) {
    c11_p1L[c11_i29] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 246U);
  c11_jh_x = c11_qzT;
  c11_t1 = c11_jh_x;
  c11_kh_x = c11_t1;
  c11_t1 = c11_kh_x;
  c11_t1 = muDoubleScalarCos(c11_t1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 247U);
  c11_lh_x = c11_qyT;
  c11_t2 = c11_lh_x;
  c11_mh_x = c11_t2;
  c11_t2 = c11_mh_x;
  c11_t2 = muDoubleScalarCos(c11_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 248U);
  c11_t3 = c11_t1 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 249U);
  c11_nh_x = c11_q3L;
  c11_t4 = c11_nh_x;
  c11_oh_x = c11_t4;
  c11_t4 = c11_oh_x;
  c11_t4 = muDoubleScalarCos(c11_t4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 250U);
  c11_ph_x = c11_qzT;
  c11_t7 = c11_ph_x;
  c11_qh_x = c11_t7;
  c11_t7 = c11_qh_x;
  c11_t7 = muDoubleScalarSin(c11_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 251U);
  c11_rh_x = c11_qxT;
  c11_t8 = c11_rh_x;
  c11_sh_x = c11_t8;
  c11_t8 = c11_sh_x;
  c11_t8 = muDoubleScalarSin(c11_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 252U);
  c11_th_x = c11_qyT;
  c11_t10 = c11_th_x;
  c11_uh_x = c11_t10;
  c11_t10 = c11_uh_x;
  c11_t10 = muDoubleScalarSin(c11_t10);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 253U);
  c11_t11 = c11_t1 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 254U);
  c11_vh_x = c11_qxT;
  c11_t12 = c11_vh_x;
  c11_wh_x = c11_t12;
  c11_t12 = c11_wh_x;
  c11_t12 = muDoubleScalarCos(c11_t12);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, MAX_uint8_T);
  c11_t14 = c11_t7 * c11_t8 + c11_t11 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 256);
  c11_xh_x = c11_q3L;
  c11_t15 = c11_xh_x;
  c11_yh_x = c11_t15;
  c11_t15 = c11_yh_x;
  c11_t15 = muDoubleScalarSin(c11_t15);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 257);
  c11_ai_x = c11_q1L;
  c11_t21 = c11_ai_x;
  c11_bi_x = c11_t21;
  c11_t21 = c11_bi_x;
  c11_t21 = muDoubleScalarSin(c11_t21);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 258);
  c11_ci_x = c11_q1L;
  c11_t27 = c11_ci_x;
  c11_di_x = c11_t27;
  c11_t27 = c11_di_x;
  c11_t27 = muDoubleScalarCos(c11_t27);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 259);
  c11_t31 = c11_t7 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 260);
  c11_t35 = c11_t7 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 261);
  c11_t37 = -c11_t1 * c11_t8 + c11_t35 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 262);
  c11_t53 = c11_t2 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 263);
  c11_p1L[0] = (((c11_xT - 0.1834 * c11_t3 * c11_t4) - 0.1834 * c11_t14 *
                 c11_t15) - 0.4 * (-c11_t7 * c11_t12 + c11_t11 * c11_t8) *
                c11_t21) + 0.4 * (-c11_t3 * c11_t15 + c11_t14 * c11_t4) *
    c11_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 264);
  c11_p1L[1] = (((c11_yT - 0.1834 * c11_t31 * c11_t4) - 0.1834 * c11_t37 *
                 c11_t15) - 0.4 * (c11_t1 * c11_t12 + c11_t35 * c11_t8) *
                c11_t21) + 0.4 * (-c11_t31 * c11_t15 + c11_t37 * c11_t4) *
    c11_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 265);
  c11_p1L[2] = (((c11_zT + 0.1834 * c11_t10 * c11_t4) - 0.1834 * c11_t53 *
                 c11_t15) - 0.4 * c11_t2 * c11_t8 * c11_t21) + 0.4 * (c11_t10 *
    c11_t15 + c11_t53 * c11_t4) * c11_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 267);
  for (c11_i30 = 0; c11_i30 < 3; c11_i30++) {
    c11_p2L[c11_i30] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 268);
  c11_ei_x = c11_qzT;
  c11_t1 = c11_ei_x;
  c11_fi_x = c11_t1;
  c11_t1 = c11_fi_x;
  c11_t1 = muDoubleScalarCos(c11_t1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 269);
  c11_gi_x = c11_qyT;
  c11_t2 = c11_gi_x;
  c11_hi_x = c11_t2;
  c11_t2 = c11_hi_x;
  c11_t2 = muDoubleScalarCos(c11_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 270);
  c11_t3 = c11_t1 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 271);
  c11_ii_x = c11_q3L;
  c11_t4 = c11_ii_x;
  c11_ji_x = c11_t4;
  c11_t4 = c11_ji_x;
  c11_t4 = muDoubleScalarCos(c11_t4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 272);
  c11_ki_x = c11_qzT;
  c11_t7 = c11_ki_x;
  c11_li_x = c11_t7;
  c11_t7 = c11_li_x;
  c11_t7 = muDoubleScalarSin(c11_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 273);
  c11_mi_x = c11_qxT;
  c11_t8 = c11_mi_x;
  c11_ni_x = c11_t8;
  c11_t8 = c11_ni_x;
  c11_t8 = muDoubleScalarSin(c11_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 274);
  c11_oi_x = c11_qyT;
  c11_t10 = c11_oi_x;
  c11_pi_x = c11_t10;
  c11_t10 = c11_pi_x;
  c11_t10 = muDoubleScalarSin(c11_t10);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 275);
  c11_t11 = c11_t1 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 276);
  c11_qi_x = c11_qxT;
  c11_t12 = c11_qi_x;
  c11_ri_x = c11_t12;
  c11_t12 = c11_ri_x;
  c11_t12 = muDoubleScalarCos(c11_t12);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 277);
  c11_t14 = c11_t7 * c11_t8 + c11_t11 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 278);
  c11_si_x = c11_q3L;
  c11_t15 = c11_si_x;
  c11_ti_x = c11_t15;
  c11_t15 = c11_ti_x;
  c11_t15 = muDoubleScalarSin(c11_t15);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 279);
  c11_ui_x = c11_q2L;
  c11_t21 = c11_ui_x;
  c11_vi_x = c11_t21;
  c11_t21 = c11_vi_x;
  c11_t21 = muDoubleScalarSin(c11_t21);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 280);
  c11_wi_x = c11_q2L;
  c11_t27 = c11_wi_x;
  c11_xi_x = c11_t27;
  c11_t27 = c11_xi_x;
  c11_t27 = muDoubleScalarCos(c11_t27);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 281);
  c11_t31 = c11_t7 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 282);
  c11_t35 = c11_t7 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 283);
  c11_t37 = -c11_t1 * c11_t8 + c11_t35 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 284);
  c11_t53 = c11_t2 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 285);
  c11_p2L[0] = (((c11_xT - 0.1834 * c11_t3 * c11_t4) - 0.1834 * c11_t14 *
                 c11_t15) - 0.5 * (-c11_t7 * c11_t12 + c11_t11 * c11_t8) *
                c11_t21) + 0.5 * (-c11_t3 * c11_t15 + c11_t14 * c11_t4) *
    c11_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 286);
  c11_p2L[1] = (((c11_yT - 0.1834 * c11_t31 * c11_t4) - 0.1834 * c11_t37 *
                 c11_t15) - 0.5 * (c11_t1 * c11_t12 + c11_t35 * c11_t8) *
                c11_t21) + 0.5 * (-c11_t31 * c11_t15 + c11_t37 * c11_t4) *
    c11_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 287);
  c11_p2L[2] = (((c11_zT + 0.1834 * c11_t10 * c11_t4) - 0.1834 * c11_t53 *
                 c11_t15) - 0.5 * c11_t2 * c11_t8 * c11_t21) + 0.5 * (c11_t10 *
    c11_t15 + c11_t53 * c11_t4) * c11_t27;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 289);
  for (c11_i31 = 0; c11_i31 < 3; c11_i31++) {
    c11_p3L[c11_i31] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 290);
  c11_yi_x = c11_qzT;
  c11_t1 = c11_yi_x;
  c11_aj_x = c11_t1;
  c11_t1 = c11_aj_x;
  c11_t1 = muDoubleScalarCos(c11_t1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 291);
  c11_bj_x = c11_qyT;
  c11_t2 = c11_bj_x;
  c11_cj_x = c11_t2;
  c11_t2 = c11_cj_x;
  c11_t2 = muDoubleScalarCos(c11_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 292);
  c11_t3 = c11_t1 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 293);
  c11_dj_x = c11_q3L;
  c11_t4 = c11_dj_x;
  c11_ej_x = c11_t4;
  c11_t4 = c11_ej_x;
  c11_t4 = muDoubleScalarCos(c11_t4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 294);
  c11_fj_x = c11_qzT;
  c11_t7 = c11_fj_x;
  c11_gj_x = c11_t7;
  c11_t7 = c11_gj_x;
  c11_t7 = muDoubleScalarSin(c11_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 295);
  c11_hj_x = c11_qxT;
  c11_t8 = c11_hj_x;
  c11_ij_x = c11_t8;
  c11_t8 = c11_ij_x;
  c11_t8 = muDoubleScalarSin(c11_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 296);
  c11_jj_x = c11_qyT;
  c11_t10 = c11_jj_x;
  c11_kj_x = c11_t10;
  c11_t10 = c11_kj_x;
  c11_t10 = muDoubleScalarSin(c11_t10);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 297);
  c11_t11 = c11_t1 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 298);
  c11_lj_x = c11_qxT;
  c11_t12 = c11_lj_x;
  c11_mj_x = c11_t12;
  c11_t12 = c11_mj_x;
  c11_t12 = muDoubleScalarCos(c11_t12);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 299);
  c11_t14 = c11_t7 * c11_t8 + c11_t11 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 300);
  c11_nj_x = c11_q3L;
  c11_t15 = c11_nj_x;
  c11_oj_x = c11_t15;
  c11_t15 = c11_oj_x;
  c11_t15 = muDoubleScalarSin(c11_t15);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 301);
  c11_t20 = -c11_t7 * c11_t12 + c11_t11 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 302);
  c11_pj_x = c11_q1L;
  c11_t21 = c11_pj_x;
  c11_qj_x = c11_t21;
  c11_t21 = c11_qj_x;
  c11_t21 = muDoubleScalarSin(c11_t21);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 303);
  c11_t26 = -c11_t3 * c11_t15 + c11_t14 * c11_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 304);
  c11_rj_x = c11_q1L;
  c11_t27 = c11_rj_x;
  c11_sj_x = c11_t27;
  c11_t27 = c11_sj_x;
  c11_t27 = muDoubleScalarCos(c11_t27);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 305);
  c11_tj_x = c11_q2L;
  c11_t30 = c11_tj_x;
  c11_uj_x = c11_t30;
  c11_t30 = c11_uj_x;
  c11_t30 = muDoubleScalarSin(c11_t30);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 306);
  c11_vj_x = c11_q2L;
  c11_t33 = c11_vj_x;
  c11_wj_x = c11_t33;
  c11_t33 = c11_wj_x;
  c11_t33 = muDoubleScalarCos(c11_t33);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 307);
  c11_t37 = c11_t7 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 308);
  c11_t41 = c11_t7 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 309);
  c11_t43 = -c11_t1 * c11_t8 + c11_t41 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 310);
  c11_t48 = c11_t1 * c11_t12 + c11_t41 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 311);
  c11_t53 = -c11_t37 * c11_t15 + c11_t43 * c11_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 312);
  c11_t63 = c11_t2 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 313);
  c11_t66 = c11_t2 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 314);
  c11_t71 = c11_t10 * c11_t15 + c11_t63 * c11_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 315);
  c11_p3L[0] = (((((c11_xT - 0.1834 * c11_t3 * c11_t4) - 0.1834 * c11_t14 *
                   c11_t15) - 0.4 * c11_t20 * c11_t21) + 0.4 * c11_t26 * c11_t27)
                - 0.5 * c11_t20 * c11_t30) + 0.5 * c11_t26 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 316);
  c11_p3L[1] = (((((c11_yT - 0.1834 * c11_t37 * c11_t4) - 0.1834 * c11_t43 *
                   c11_t15) - 0.4 * c11_t48 * c11_t21) + 0.4 * c11_t53 * c11_t27)
                - 0.5 * c11_t48 * c11_t30) + 0.5 * c11_t53 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 317);
  c11_p3L[2] = (((((c11_zT + 0.1834 * c11_t10 * c11_t4) - 0.1834 * c11_t63 *
                   c11_t15) - 0.4 * c11_t66 * c11_t21) + 0.4 * c11_t71 * c11_t27)
                - 0.5 * c11_t66 * c11_t30) + 0.5 * c11_t71 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 319);
  for (c11_i32 = 0; c11_i32 < 3; c11_i32++) {
    c11_p4L[c11_i32] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 320);
  c11_xj_x = c11_qzT;
  c11_t1 = c11_xj_x;
  c11_yj_x = c11_t1;
  c11_t1 = c11_yj_x;
  c11_t1 = muDoubleScalarCos(c11_t1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 321);
  c11_ak_x = c11_qyT;
  c11_t2 = c11_ak_x;
  c11_bk_x = c11_t2;
  c11_t2 = c11_bk_x;
  c11_t2 = muDoubleScalarCos(c11_t2);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 322);
  c11_t3 = c11_t1 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 323);
  c11_ck_x = c11_q3L;
  c11_t4 = c11_ck_x;
  c11_dk_x = c11_t4;
  c11_t4 = c11_dk_x;
  c11_t4 = muDoubleScalarCos(c11_t4);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 324);
  c11_ek_x = c11_qzT;
  c11_t7 = c11_ek_x;
  c11_fk_x = c11_t7;
  c11_t7 = c11_fk_x;
  c11_t7 = muDoubleScalarSin(c11_t7);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 325);
  c11_gk_x = c11_qxT;
  c11_t8 = c11_gk_x;
  c11_hk_x = c11_t8;
  c11_t8 = c11_hk_x;
  c11_t8 = muDoubleScalarSin(c11_t8);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 326);
  c11_ik_x = c11_qyT;
  c11_t10 = c11_ik_x;
  c11_jk_x = c11_t10;
  c11_t10 = c11_jk_x;
  c11_t10 = muDoubleScalarSin(c11_t10);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 327);
  c11_t11 = c11_t1 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 328);
  c11_kk_x = c11_qxT;
  c11_t12 = c11_kk_x;
  c11_lk_x = c11_t12;
  c11_t12 = c11_lk_x;
  c11_t12 = muDoubleScalarCos(c11_t12);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 329);
  c11_t14 = c11_t7 * c11_t8 + c11_t11 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 330);
  c11_mk_x = c11_q3L;
  c11_t15 = c11_mk_x;
  c11_nk_x = c11_t15;
  c11_t15 = c11_nk_x;
  c11_t15 = muDoubleScalarSin(c11_t15);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 331);
  c11_t20 = -c11_t7 * c11_t12 + c11_t11 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 332);
  c11_ok_x = c11_q2L;
  c11_t21 = c11_ok_x;
  c11_pk_x = c11_t21;
  c11_t21 = c11_pk_x;
  c11_t21 = muDoubleScalarSin(c11_t21);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 333);
  c11_t26 = -c11_t3 * c11_t15 + c11_t14 * c11_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 334);
  c11_qk_x = c11_q2L;
  c11_t27 = c11_qk_x;
  c11_rk_x = c11_t27;
  c11_t27 = c11_rk_x;
  c11_t27 = muDoubleScalarCos(c11_t27);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 335);
  c11_sk_x = c11_q1L;
  c11_t30 = c11_sk_x;
  c11_tk_x = c11_t30;
  c11_t30 = c11_tk_x;
  c11_t30 = muDoubleScalarSin(c11_t30);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 336);
  c11_uk_x = c11_q1L;
  c11_t33 = c11_uk_x;
  c11_vk_x = c11_t33;
  c11_t33 = c11_vk_x;
  c11_t33 = muDoubleScalarCos(c11_t33);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 337);
  c11_t37 = c11_t7 * c11_t2;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 338);
  c11_t41 = c11_t7 * c11_t10;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 339);
  c11_t43 = -c11_t1 * c11_t8 + c11_t41 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 340);
  c11_t48 = c11_t1 * c11_t12 + c11_t41 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 341);
  c11_t53 = -c11_t37 * c11_t15 + c11_t43 * c11_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 342);
  c11_t63 = c11_t2 * c11_t12;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 343);
  c11_t66 = c11_t2 * c11_t8;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 344);
  c11_t71 = c11_t10 * c11_t15 + c11_t63 * c11_t4;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 345);
  c11_p4L[0] = (((((c11_xT - 0.1834 * c11_t3 * c11_t4) - 0.1834 * c11_t14 *
                   c11_t15) - 0.5 * c11_t20 * c11_t21) + 0.5 * c11_t26 * c11_t27)
                - 0.5 * c11_t20 * c11_t30) + 0.5 * c11_t26 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 346);
  c11_p4L[1] = (((((c11_yT - 0.1834 * c11_t37 * c11_t4) - 0.1834 * c11_t43 *
                   c11_t15) - 0.5 * c11_t48 * c11_t21) + 0.5 * c11_t53 * c11_t27)
                - 0.5 * c11_t48 * c11_t30) + 0.5 * c11_t53 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 347);
  c11_p4L[2] = (((((c11_zT + 0.1834 * c11_t10 * c11_t4) - 0.1834 * c11_t63 *
                   c11_t15) - 0.5 * c11_t66 * c11_t21) + 0.5 * c11_t71 * c11_t27)
                - 0.5 * c11_t66 * c11_t30) + 0.5 * c11_t71 * c11_t33;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -347);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)c11_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, c11_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Models\\OriginalLeg_Updated\\m\\ATRIAS3D_Positions_Hip.m"));
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc11_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_b_terminate_signal, const char_T
  *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_terminate_signal), &c11_thisId);
  sf_mex_destroy(&c11_b_terminate_signal);
  return c11_y;
}

static real_T c11_b_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  real_T c11_y;
  real_T c11_d1;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_d1, 1, 0, 0U, 0, 0U, 0);
  c11_y = c11_d1;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_terminate_signal;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc11_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c11_b_terminate_signal = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_terminate_signal), &c11_thisId);
  sf_mex_destroy(&c11_b_terminate_signal);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i33;
  real_T c11_b_inData[32];
  int32_T c11_i34;
  real_T c11_u[32];
  const mxArray *c11_y = NULL;
  SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc11_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i33 = 0; c11_i33 < 32; c11_i33++) {
    c11_b_inData[c11_i33] = (*(real_T (*)[32])c11_inData)[c11_i33];
  }

  for (c11_i34 = 0; c11_i34 < 32; c11_i34++) {
    c11_u[c11_i34] = c11_b_inData[c11_i34];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i35;
  real_T c11_b_inData[2];
  int32_T c11_i36;
  real_T c11_u[2];
  const mxArray *c11_y = NULL;
  SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc11_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i35 = 0; c11_i35 < 2; c11_i35++) {
    c11_b_inData[c11_i35] = (*(real_T (*)[2])c11_inData)[c11_i35];
  }

  for (c11_i36 = 0; c11_i36 < 2; c11_i36++) {
    c11_u[c11_i36] = c11_b_inData[c11_i36];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_c_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[2])
{
  real_T c11_dv0[2];
  int32_T c11_i37;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv0, 1, 0, 0U, 1, 0U, 2, 1,
                2);
  for (c11_i37 = 0; c11_i37 < 2; c11_i37++) {
    c11_y[c11_i37] = c11_dv0[c11_i37];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_p_Z;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[2];
  int32_T c11_i38;
  SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc11_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c11_p_Z = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_p_Z), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_p_Z);
  for (c11_i38 = 0; c11_i38 < 2; c11_i38++) {
    (*(real_T (*)[2])c11_outData)[c11_i38] = c11_y[c11_i38];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i39;
  real_T c11_b_inData[3];
  int32_T c11_i40;
  real_T c11_u[3];
  const mxArray *c11_y = NULL;
  SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc11_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i39 = 0; c11_i39 < 3; c11_i39++) {
    c11_b_inData[c11_i39] = (*(real_T (*)[3])c11_inData)[c11_i39];
  }

  for (c11_i40 = 0; c11_i40 < 3; c11_i40++) {
    c11_u[c11_i40] = c11_b_inData[c11_i40];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_d_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[3])
{
  real_T c11_dv1[3];
  int32_T c11_i41;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv1, 1, 0, 0U, 1, 0U, 1, 3);
  for (c11_i41 = 0; c11_i41 < 3; c11_i41++) {
    c11_y[c11_i41] = c11_dv1[c11_i41];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_p4L;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[3];
  int32_T c11_i42;
  SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc11_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c11_p4L = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_p4L), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_p4L);
  for (c11_i42 = 0; c11_i42 < 3; c11_i42++) {
    (*(real_T (*)[3])c11_outData)[c11_i42] = c11_y[c11_i42];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i43;
  real_T c11_b_inData[16];
  int32_T c11_i44;
  real_T c11_u[16];
  const mxArray *c11_y = NULL;
  SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc11_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i43 = 0; c11_i43 < 16; c11_i43++) {
    c11_b_inData[c11_i43] = (*(real_T (*)[16])c11_inData)[c11_i43];
  }

  for (c11_i44 = 0; c11_i44 < 16; c11_i44++) {
    c11_u[c11_i44] = c11_b_inData[c11_i44];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 16), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_e_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[16])
{
  real_T c11_dv2[16];
  int32_T c11_i45;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv2, 1, 0, 0U, 1, 0U, 1, 16);
  for (c11_i45 = 0; c11_i45 < 16; c11_i45++) {
    c11_y[c11_i45] = c11_dv2[c11_i45];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_dq;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[16];
  int32_T c11_i46;
  SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc11_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c11_dq = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_dq), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_dq);
  for (c11_i46 = 0; c11_i46 < 16; c11_i46++) {
    (*(real_T (*)[16])c11_outData)[c11_i46] = c11_y[c11_i46];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_createstruct("structure", 2, 25, 1),
                false);
  c11_info_helper(&c11_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c11_nameCaptureInfo);
  return c11_nameCaptureInfo;
}

static void c11_info_helper(const mxArray **c11_info)
{
  const mxArray *c11_rhs0 = NULL;
  const mxArray *c11_lhs0 = NULL;
  const mxArray *c11_rhs1 = NULL;
  const mxArray *c11_lhs1 = NULL;
  const mxArray *c11_rhs2 = NULL;
  const mxArray *c11_lhs2 = NULL;
  const mxArray *c11_rhs3 = NULL;
  const mxArray *c11_lhs3 = NULL;
  const mxArray *c11_rhs4 = NULL;
  const mxArray *c11_lhs4 = NULL;
  const mxArray *c11_rhs5 = NULL;
  const mxArray *c11_lhs5 = NULL;
  const mxArray *c11_rhs6 = NULL;
  const mxArray *c11_lhs6 = NULL;
  const mxArray *c11_rhs7 = NULL;
  const mxArray *c11_lhs7 = NULL;
  const mxArray *c11_rhs8 = NULL;
  const mxArray *c11_lhs8 = NULL;
  const mxArray *c11_rhs9 = NULL;
  const mxArray *c11_lhs9 = NULL;
  const mxArray *c11_rhs10 = NULL;
  const mxArray *c11_lhs10 = NULL;
  const mxArray *c11_rhs11 = NULL;
  const mxArray *c11_lhs11 = NULL;
  const mxArray *c11_rhs12 = NULL;
  const mxArray *c11_lhs12 = NULL;
  const mxArray *c11_rhs13 = NULL;
  const mxArray *c11_lhs13 = NULL;
  const mxArray *c11_rhs14 = NULL;
  const mxArray *c11_lhs14 = NULL;
  const mxArray *c11_rhs15 = NULL;
  const mxArray *c11_lhs15 = NULL;
  const mxArray *c11_rhs16 = NULL;
  const mxArray *c11_lhs16 = NULL;
  const mxArray *c11_rhs17 = NULL;
  const mxArray *c11_lhs17 = NULL;
  const mxArray *c11_rhs18 = NULL;
  const mxArray *c11_lhs18 = NULL;
  const mxArray *c11_rhs19 = NULL;
  const mxArray *c11_lhs19 = NULL;
  const mxArray *c11_rhs20 = NULL;
  const mxArray *c11_lhs20 = NULL;
  const mxArray *c11_rhs21 = NULL;
  const mxArray *c11_lhs21 = NULL;
  const mxArray *c11_rhs22 = NULL;
  const mxArray *c11_lhs22 = NULL;
  const mxArray *c11_rhs23 = NULL;
  const mxArray *c11_lhs23 = NULL;
  const mxArray *c11_rhs24 = NULL;
  const mxArray *c11_lhs24 = NULL;
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("ATRIAS3D_Positions_Hip"),
                  "name", "name", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Models/OriginalLeg_Updated/m/ATRIAS3D_Positions_Hip.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1444616514U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c11_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Models/OriginalLeg_Updated/m/ATRIAS3D_Positions_Hip.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("sin"), "name", "name", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c11_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286840336U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c11_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Models/OriginalLeg_Updated/m/ATRIAS3D_Positions_Hip.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("cos"), "name", "name", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c11_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286840322U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c11_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("max"), "name", "name", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c11_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c11_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c11_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c11_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c11_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c11_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c11_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c11_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isnan"), "name", "name", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c11_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c11_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c11_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c11_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c11_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isfi"), "name", "name", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c11_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c11_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c11_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c11_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmin"), "name", "name", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c11_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c11_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_relop"), "name", "name",
                  24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1342472782U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c11_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs24), "lhs", "lhs",
                  24);
  sf_mex_destroy(&c11_rhs0);
  sf_mex_destroy(&c11_lhs0);
  sf_mex_destroy(&c11_rhs1);
  sf_mex_destroy(&c11_lhs1);
  sf_mex_destroy(&c11_rhs2);
  sf_mex_destroy(&c11_lhs2);
  sf_mex_destroy(&c11_rhs3);
  sf_mex_destroy(&c11_lhs3);
  sf_mex_destroy(&c11_rhs4);
  sf_mex_destroy(&c11_lhs4);
  sf_mex_destroy(&c11_rhs5);
  sf_mex_destroy(&c11_lhs5);
  sf_mex_destroy(&c11_rhs6);
  sf_mex_destroy(&c11_lhs6);
  sf_mex_destroy(&c11_rhs7);
  sf_mex_destroy(&c11_lhs7);
  sf_mex_destroy(&c11_rhs8);
  sf_mex_destroy(&c11_lhs8);
  sf_mex_destroy(&c11_rhs9);
  sf_mex_destroy(&c11_lhs9);
  sf_mex_destroy(&c11_rhs10);
  sf_mex_destroy(&c11_lhs10);
  sf_mex_destroy(&c11_rhs11);
  sf_mex_destroy(&c11_lhs11);
  sf_mex_destroy(&c11_rhs12);
  sf_mex_destroy(&c11_lhs12);
  sf_mex_destroy(&c11_rhs13);
  sf_mex_destroy(&c11_lhs13);
  sf_mex_destroy(&c11_rhs14);
  sf_mex_destroy(&c11_lhs14);
  sf_mex_destroy(&c11_rhs15);
  sf_mex_destroy(&c11_lhs15);
  sf_mex_destroy(&c11_rhs16);
  sf_mex_destroy(&c11_lhs16);
  sf_mex_destroy(&c11_rhs17);
  sf_mex_destroy(&c11_lhs17);
  sf_mex_destroy(&c11_rhs18);
  sf_mex_destroy(&c11_lhs18);
  sf_mex_destroy(&c11_rhs19);
  sf_mex_destroy(&c11_lhs19);
  sf_mex_destroy(&c11_rhs20);
  sf_mex_destroy(&c11_lhs20);
  sf_mex_destroy(&c11_rhs21);
  sf_mex_destroy(&c11_lhs21);
  sf_mex_destroy(&c11_rhs22);
  sf_mex_destroy(&c11_lhs22);
  sf_mex_destroy(&c11_rhs23);
  sf_mex_destroy(&c11_lhs23);
  sf_mex_destroy(&c11_rhs24);
  sf_mex_destroy(&c11_lhs24);
}

static const mxArray *c11_emlrt_marshallOut(const char * c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c11_u)), false);
  return c11_y;
}

static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u)
{
  const mxArray *c11_y = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 7, 0U, 0U, 0U, 0), false);
  return c11_y;
}

static void c11_eml_switch_helper(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c11_check_forloop_overflow_error(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, boolean_T c11_overflow)
{
  int32_T c11_i47;
  static char_T c11_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c11_u[34];
  const mxArray *c11_y = NULL;
  int32_T c11_i48;
  static char_T c11_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c11_b_u[5];
  const mxArray *c11_b_y = NULL;
  (void)chartInstance;
  if (!c11_overflow) {
  } else {
    for (c11_i47 = 0; c11_i47 < 34; c11_i47++) {
      c11_u[c11_i47] = c11_cv0[c11_i47];
    }

    c11_y = NULL;
    sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c11_i48 = 0; c11_i48 < 5; c11_i48++) {
      c11_b_u[c11_i48] = c11_cv1[c11_i48];
    }

    c11_b_y = NULL;
    sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c11_y, 14, c11_b_y));
  }
}

static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc11_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_f_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i49;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i49, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i49;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc11_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_g_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_DDA2D_OSU3Dv2, const char_T
  *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_DDA2D_OSU3Dv2), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_DDA2D_OSU3Dv2);
  return c11_y;
}

static uint8_T c11_h_emlrt_marshallIn(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u0, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void init_dsm_address_info(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc11_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c11_x_e = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c11_terminate_signal = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
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

void sf_c11_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4136792865U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3774574968U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(500768132U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(324890570U);
}

mxArray* sf_c11_DDA2D_OSU3Dv2_get_post_codegen_info(void);
mxArray *sf_c11_DDA2D_OSU3Dv2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("E2HAxAMZspJ0Ofd1RozEVB");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(32);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c11_DDA2D_OSU3Dv2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c11_DDA2D_OSU3Dv2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_DDA2D_OSU3Dv2_jit_fallback_info(void)
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

mxArray *sf_c11_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c11_DDA2D_OSU3Dv2_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c11_DDA2D_OSU3Dv2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"terminate_signal\",},{M[8],M[0],T\"is_active_c11_DDA2D_OSU3Dv2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_DDA2D_OSU3Dv2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc11_DDA2D_OSU3Dv2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DDA2D_OSU3Dv2MachineNumber_,
           11,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           1,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"x_e");
          _SFD_SET_DATA_PROPS(1,2,0,1,"terminate_signal");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,480);
        _SFD_CV_INIT_EML_IF(0,1,0,386,415,442,480);

        {
          static int condStart[] = { 389, 403 };

          static int condEnd[] = { 399, 415 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,389,415,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,389,399,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,403,415,-1,4);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"ATRIAS3D_Positions_Hip",0,-1,11482);

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c11_x_e);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c11_terminate_signal);
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
  return "bjXFo3OIYVQJL2hv0nek2B";
}

static void sf_opaque_initialize_c11_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_DDA2D_OSU3Dv2((SFc11_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
  initialize_c11_DDA2D_OSU3Dv2((SFc11_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  enable_c11_DDA2D_OSU3Dv2((SFc11_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c11_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  disable_c11_DDA2D_OSU3Dv2((SFc11_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  sf_gateway_c11_DDA2D_OSU3Dv2((SFc11_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c11_DDA2D_OSU3Dv2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c11_DDA2D_OSU3Dv2((SFc11_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c11_DDA2D_OSU3Dv2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c11_DDA2D_OSU3Dv2((SFc11_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c11_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DDA2D_OSU3Dv2_optimization_info();
    }

    finalize_c11_DDA2D_OSU3Dv2((SFc11_DDA2D_OSU3Dv2InstanceStruct*)
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
  initSimStructsc11_DDA2D_OSU3Dv2((SFc11_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_DDA2D_OSU3Dv2(SimStruct *S)
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
    initialize_params_c11_DDA2D_OSU3Dv2((SFc11_DDA2D_OSU3Dv2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DDA2D_OSU3Dv2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      11);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,11,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,11,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,11);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,11,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,11);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2916247162U));
  ssSetChecksum1(S,(1451393282U));
  ssSetChecksum2(S,(2949665975U));
  ssSetChecksum3(S,(2921829438U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_DDA2D_OSU3Dv2(SimStruct *S)
{
  SFc11_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc11_DDA2D_OSU3Dv2InstanceStruct *)utMalloc(sizeof
    (SFc11_DDA2D_OSU3Dv2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_DDA2D_OSU3Dv2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c11_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c11_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c11_DDA2D_OSU3Dv2;
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

void c11_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_DDA2D_OSU3Dv2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_DDA2D_OSU3Dv2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
