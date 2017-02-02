/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_DDA3D_sfun.h"
#include "c21_Walking01_DDA3D.h"
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
static const char * c21_debug_family_names[19] = { "qT0", "YawRolloverCount",
  "PreviousYaw", "CurrentYaw", "qzT", "qyT", "nargin", "nargout", "RkIn", "wk",
  "RCal", "Reset", "R0In", "YawRolloverIn", "ZYX", "dZYX", "Rk", "R0",
  "YawRollover" };

static const char * c21_b_debug_family_names[7] = { "qY", "qX", "qZ", "nargin",
  "nargout", "M", "EulerAngles" };

static const char * c21_c_debug_family_names[4] = { "nargin", "nargout", "t",
  "R" };

static const char * c21_d_debug_family_names[5] = { "nargin", "nargout",
  "CurrentYaw", "PreviousYaw", "Rollover" };

/* Function Declarations */
static void initialize_c21_Walking01_DDA3D(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initialize_params_c21_Walking01_DDA3D
  (SFc21_Walking01_DDA3DInstanceStruct *chartInstance);
static void enable_c21_Walking01_DDA3D(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void disable_c21_Walking01_DDA3D(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c21_update_debugger_state_c21_Walking01_DDA3D
  (SFc21_Walking01_DDA3DInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c21_Walking01_DDA3D
  (SFc21_Walking01_DDA3DInstanceStruct *chartInstance);
static void set_sim_state_c21_Walking01_DDA3D
  (SFc21_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c21_st);
static void finalize_c21_Walking01_DDA3D(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void sf_gateway_c21_Walking01_DDA3D(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void mdl_start_c21_Walking01_DDA3D(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c21_chartstep_c21_Walking01_DDA3D
  (SFc21_Walking01_DDA3DInstanceStruct *chartInstance);
static void initSimStructsc21_Walking01_DDA3D
  (SFc21_Walking01_DDA3DInstanceStruct *chartInstance);
static void c21_M_to_ZYX(SFc21_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c21_M[9], real_T c21_EulerAngles[3]);
static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber, uint32_T c21_instanceNumber);
static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static void c21_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_b_YawRollover, const char_T *c21_identifier,
  real_T c21_y[2]);
static void c21_b_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[2]);
static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static void c21_c_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_b_R0, const char_T *c21_identifier, real_T
  c21_y[9]);
static void c21_d_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[9]);
static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static void c21_e_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_b_dZYX, const char_T *c21_identifier,
  real_T c21_y[3]);
static void c21_f_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[3]);
static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static const mxArray *c21_d_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static const mxArray *c21_e_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static real_T c21_g_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static void c21_info_helper(const mxArray **c21_info);
static const mxArray *c21_emlrt_marshallOut(const char * c21_u);
static const mxArray *c21_b_emlrt_marshallOut(const uint32_T c21_u);
static void c21_eml_scalar_eg(SFc21_Walking01_DDA3DInstanceStruct *chartInstance);
static void c21_threshold(SFc21_Walking01_DDA3DInstanceStruct *chartInstance);
static void c21_eml_error(SFc21_Walking01_DDA3DInstanceStruct *chartInstance);
static real_T c21_atan2(SFc21_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c21_y, real_T c21_x);
static real_T c21_squeeze(SFc21_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c21_a);
static void c21_Rz(SFc21_Walking01_DDA3DInstanceStruct *chartInstance, real_T
                   c21_t, real_T c21_R[9]);
static real_T c21_getYawRollover(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, real_T c21_CurrentYaw, real_T c21_PreviousYaw);
static void c21_b_eml_scalar_eg(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c21_mldivide(SFc21_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c21_A[9], real_T c21_B[3], real_T c21_Y[3]);
static real_T c21_rdivide(SFc21_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c21_x, real_T c21_y);
static void c21_eml_warning(SFc21_Walking01_DDA3DInstanceStruct *chartInstance);
static const mxArray *c21_f_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData);
static int32_T c21_h_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void c21_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData);
static uint8_T c21_i_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_Walking01_DDA3D, const
  char_T *c21_identifier);
static uint8_T c21_j_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId);
static void init_dsm_address_info(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c21_Walking01_DDA3D(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c21_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c21_is_active_c21_Walking01_DDA3D = 0U;
}

static void initialize_params_c21_Walking01_DDA3D
  (SFc21_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c21_Walking01_DDA3D(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c21_Walking01_DDA3D(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c21_update_debugger_state_c21_Walking01_DDA3D
  (SFc21_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c21_Walking01_DDA3D
  (SFc21_Walking01_DDA3DInstanceStruct *chartInstance)
{
  const mxArray *c21_st;
  const mxArray *c21_y = NULL;
  int32_T c21_i0;
  real_T c21_u[9];
  const mxArray *c21_b_y = NULL;
  int32_T c21_i1;
  real_T c21_b_u[9];
  const mxArray *c21_c_y = NULL;
  int32_T c21_i2;
  real_T c21_c_u[2];
  const mxArray *c21_d_y = NULL;
  int32_T c21_i3;
  real_T c21_d_u[3];
  const mxArray *c21_e_y = NULL;
  int32_T c21_i4;
  real_T c21_e_u[3];
  const mxArray *c21_f_y = NULL;
  uint8_T c21_hoistedGlobal;
  uint8_T c21_f_u;
  const mxArray *c21_g_y = NULL;
  c21_st = NULL;
  c21_st = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_createcellmatrix(6, 1), false);
  for (c21_i0 = 0; c21_i0 < 9; c21_i0++) {
    c21_u[c21_i0] = (*chartInstance->c21_R0)[c21_i0];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 2, 3, 3),
                false);
  sf_mex_setcell(c21_y, 0, c21_b_y);
  for (c21_i1 = 0; c21_i1 < 9; c21_i1++) {
    c21_b_u[c21_i1] = (*chartInstance->c21_Rk)[c21_i1];
  }

  c21_c_y = NULL;
  sf_mex_assign(&c21_c_y, sf_mex_create("y", c21_b_u, 0, 0U, 1U, 0U, 2, 3, 3),
                false);
  sf_mex_setcell(c21_y, 1, c21_c_y);
  for (c21_i2 = 0; c21_i2 < 2; c21_i2++) {
    c21_c_u[c21_i2] = (*chartInstance->c21_YawRollover)[c21_i2];
  }

  c21_d_y = NULL;
  sf_mex_assign(&c21_d_y, sf_mex_create("y", c21_c_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_setcell(c21_y, 2, c21_d_y);
  for (c21_i3 = 0; c21_i3 < 3; c21_i3++) {
    c21_d_u[c21_i3] = (*chartInstance->c21_ZYX)[c21_i3];
  }

  c21_e_y = NULL;
  sf_mex_assign(&c21_e_y, sf_mex_create("y", c21_d_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c21_y, 3, c21_e_y);
  for (c21_i4 = 0; c21_i4 < 3; c21_i4++) {
    c21_e_u[c21_i4] = (*chartInstance->c21_dZYX)[c21_i4];
  }

  c21_f_y = NULL;
  sf_mex_assign(&c21_f_y, sf_mex_create("y", c21_e_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c21_y, 4, c21_f_y);
  c21_hoistedGlobal = chartInstance->c21_is_active_c21_Walking01_DDA3D;
  c21_f_u = c21_hoistedGlobal;
  c21_g_y = NULL;
  sf_mex_assign(&c21_g_y, sf_mex_create("y", &c21_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c21_y, 5, c21_g_y);
  sf_mex_assign(&c21_st, c21_y, false);
  return c21_st;
}

static void set_sim_state_c21_Walking01_DDA3D
  (SFc21_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c21_st)
{
  const mxArray *c21_u;
  real_T c21_dv0[9];
  int32_T c21_i5;
  real_T c21_dv1[9];
  int32_T c21_i6;
  real_T c21_dv2[2];
  int32_T c21_i7;
  real_T c21_dv3[3];
  int32_T c21_i8;
  real_T c21_dv4[3];
  int32_T c21_i9;
  chartInstance->c21_doneDoubleBufferReInit = true;
  c21_u = sf_mex_dup(c21_st);
  c21_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 0)),
    "R0", c21_dv0);
  for (c21_i5 = 0; c21_i5 < 9; c21_i5++) {
    (*chartInstance->c21_R0)[c21_i5] = c21_dv0[c21_i5];
  }

  c21_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 1)),
    "Rk", c21_dv1);
  for (c21_i6 = 0; c21_i6 < 9; c21_i6++) {
    (*chartInstance->c21_Rk)[c21_i6] = c21_dv1[c21_i6];
  }

  c21_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 2)),
                       "YawRollover", c21_dv2);
  for (c21_i7 = 0; c21_i7 < 2; c21_i7++) {
    (*chartInstance->c21_YawRollover)[c21_i7] = c21_dv2[c21_i7];
  }

  c21_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 3)),
    "ZYX", c21_dv3);
  for (c21_i8 = 0; c21_i8 < 3; c21_i8++) {
    (*chartInstance->c21_ZYX)[c21_i8] = c21_dv3[c21_i8];
  }

  c21_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 4)),
    "dZYX", c21_dv4);
  for (c21_i9 = 0; c21_i9 < 3; c21_i9++) {
    (*chartInstance->c21_dZYX)[c21_i9] = c21_dv4[c21_i9];
  }

  chartInstance->c21_is_active_c21_Walking01_DDA3D = c21_i_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c21_u, 5)),
     "is_active_c21_Walking01_DDA3D");
  sf_mex_destroy(&c21_u);
  c21_update_debugger_state_c21_Walking01_DDA3D(chartInstance);
  sf_mex_destroy(&c21_st);
}

static void finalize_c21_Walking01_DDA3D(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c21_Walking01_DDA3D(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  int32_T c21_i10;
  int32_T c21_i11;
  int32_T c21_i12;
  int32_T c21_i13;
  int32_T c21_i14;
  int32_T c21_i15;
  int32_T c21_i16;
  int32_T c21_i17;
  int32_T c21_i18;
  int32_T c21_i19;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 15U, chartInstance->c21_sfEvent);
  for (c21_i10 = 0; c21_i10 < 9; c21_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_RkIn)[c21_i10], 0U);
  }

  for (c21_i11 = 0; c21_i11 < 3; c21_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_wk)[c21_i11], 1U);
  }

  for (c21_i12 = 0; c21_i12 < 9; c21_i12++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_RCal)[c21_i12], 2U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c21_Reset, 3U);
  for (c21_i13 = 0; c21_i13 < 9; c21_i13++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_R0In)[c21_i13], 4U);
  }

  chartInstance->c21_sfEvent = CALL_EVENT;
  c21_chartstep_c21_Walking01_DDA3D(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_DDA3DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c21_i14 = 0; c21_i14 < 3; c21_i14++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_ZYX)[c21_i14], 5U);
  }

  for (c21_i15 = 0; c21_i15 < 3; c21_i15++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_dZYX)[c21_i15], 6U);
  }

  for (c21_i16 = 0; c21_i16 < 9; c21_i16++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_Rk)[c21_i16], 7U);
  }

  for (c21_i17 = 0; c21_i17 < 9; c21_i17++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_R0)[c21_i17], 8U);
  }

  for (c21_i18 = 0; c21_i18 < 2; c21_i18++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_YawRolloverIn)[c21_i18], 9U);
  }

  for (c21_i19 = 0; c21_i19 < 2; c21_i19++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c21_YawRollover)[c21_i19], 10U);
  }
}

static void mdl_start_c21_Walking01_DDA3D(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c21_chartstep_c21_Walking01_DDA3D
  (SFc21_Walking01_DDA3DInstanceStruct *chartInstance)
{
  boolean_T c21_hoistedGlobal;
  int32_T c21_i20;
  real_T c21_b_RkIn[9];
  int32_T c21_i21;
  real_T c21_b_wk[3];
  int32_T c21_i22;
  real_T c21_b_RCal[9];
  boolean_T c21_b_Reset;
  int32_T c21_i23;
  real_T c21_b_R0In[9];
  int32_T c21_i24;
  real_T c21_b_YawRolloverIn[2];
  uint32_T c21_debug_family_var_map[19];
  real_T c21_qT0[3];
  real_T c21_YawRolloverCount;
  real_T c21_PreviousYaw;
  real_T c21_CurrentYaw;
  real_T c21_qzT;
  real_T c21_qyT;
  real_T c21_nargin = 6.0;
  real_T c21_nargout = 5.0;
  real_T c21_b_ZYX[3];
  real_T c21_b_dZYX[3];
  real_T c21_b_Rk[9];
  real_T c21_b_R0[9];
  real_T c21_b_YawRollover[2];
  int32_T c21_i25;
  real_T c21_a[9];
  int32_T c21_i26;
  real_T c21_b[9];
  int32_T c21_i27;
  int32_T c21_i28;
  int32_T c21_i29;
  real_T c21_y[9];
  int32_T c21_i30;
  int32_T c21_i31;
  int32_T c21_i32;
  real_T c21_b_y[9];
  real_T c21_dv5[3];
  int32_T c21_i33;
  real_T c21_dv6[9];
  int32_T c21_i34;
  int32_T c21_i35;
  int32_T c21_i36;
  int32_T c21_i37;
  int32_T c21_i38;
  int32_T c21_i39;
  int32_T c21_i40;
  int32_T c21_i41;
  int32_T c21_i42;
  int32_T c21_i43;
  int32_T c21_i44;
  int32_T c21_i45;
  int32_T c21_i46;
  int32_T c21_i47;
  int32_T c21_i48;
  int32_T c21_i49;
  int32_T c21_i50;
  int32_T c21_i51;
  int32_T c21_i52;
  int32_T c21_i53;
  int32_T c21_i54;
  int32_T c21_i55;
  real_T c21_c_Rk[9];
  real_T c21_dv7[3];
  int32_T c21_i56;
  real_T c21_x;
  real_T c21_d0;
  real_T c21_b_x;
  real_T c21_c_x;
  real_T c21_d_x;
  real_T c21_e_x;
  real_T c21_f_x;
  real_T c21_g_x;
  real_T c21_h_x;
  real_T c21_i_x;
  real_T c21_j_x;
  real_T c21_k_x;
  real_T c21_l_x;
  real_T c21_m_x;
  real_T c21_n_x;
  real_T c21_o_x;
  int32_T c21_i57;
  int32_T c21_i58;
  int32_T c21_i59;
  int32_T c21_i60;
  int32_T c21_i61;
  int32_T c21_i62;
  int32_T c21_i63;
  int32_T c21_i64;
  real_T c21_b_b[3];
  int32_T c21_i65;
  real_T c21_c_y[3];
  int32_T c21_i66;
  int32_T c21_i67;
  real_T c21_dv8[9];
  int32_T c21_i68;
  real_T c21_d_y[3];
  real_T c21_dv9[3];
  int32_T c21_i69;
  int32_T c21_i70;
  int32_T c21_i71;
  int32_T c21_i72;
  int32_T c21_i73;
  int32_T c21_i74;
  int32_T c21_i75;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 15U, chartInstance->c21_sfEvent);
  c21_hoistedGlobal = *chartInstance->c21_Reset;
  for (c21_i20 = 0; c21_i20 < 9; c21_i20++) {
    c21_b_RkIn[c21_i20] = (*chartInstance->c21_RkIn)[c21_i20];
  }

  for (c21_i21 = 0; c21_i21 < 3; c21_i21++) {
    c21_b_wk[c21_i21] = (*chartInstance->c21_wk)[c21_i21];
  }

  for (c21_i22 = 0; c21_i22 < 9; c21_i22++) {
    c21_b_RCal[c21_i22] = (*chartInstance->c21_RCal)[c21_i22];
  }

  c21_b_Reset = c21_hoistedGlobal;
  for (c21_i23 = 0; c21_i23 < 9; c21_i23++) {
    c21_b_R0In[c21_i23] = (*chartInstance->c21_R0In)[c21_i23];
  }

  for (c21_i24 = 0; c21_i24 < 2; c21_i24++) {
    c21_b_YawRolloverIn[c21_i24] = (*chartInstance->c21_YawRolloverIn)[c21_i24];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c21_debug_family_names,
    c21_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_qT0, 0U, c21_c_sf_marshallOut,
    c21_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_YawRolloverCount, 1U,
    c21_e_sf_marshallOut, c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_PreviousYaw, 2U,
    c21_e_sf_marshallOut, c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_CurrentYaw, 3U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_qzT, 4U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_qyT, 5U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargin, 6U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargout, 7U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_RkIn, 8U, c21_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_wk, 9U, c21_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_RCal, 10U, c21_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c21_b_Reset, 11U, c21_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_R0In, 12U, c21_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c21_b_YawRolloverIn, 13U, c21_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_b_ZYX, 14U, c21_c_sf_marshallOut,
    c21_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_b_dZYX, 15U, c21_c_sf_marshallOut,
    c21_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_b_Rk, 16U, c21_b_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_b_R0, 17U, c21_b_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_b_YawRollover, 18U,
    c21_sf_marshallOut, c21_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 5);
  if (CV_EML_IF(0, 1, 0, c21_b_Reset)) {
    _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 7);
    for (c21_i25 = 0; c21_i25 < 9; c21_i25++) {
      c21_a[c21_i25] = c21_b_RkIn[c21_i25];
    }

    for (c21_i26 = 0; c21_i26 < 9; c21_i26++) {
      c21_b[c21_i26] = c21_b_RCal[c21_i26];
    }

    c21_eml_scalar_eg(chartInstance);
    c21_eml_scalar_eg(chartInstance);
    c21_threshold(chartInstance);
    for (c21_i27 = 0; c21_i27 < 3; c21_i27++) {
      c21_i28 = 0;
      for (c21_i29 = 0; c21_i29 < 3; c21_i29++) {
        c21_y[c21_i28 + c21_i27] = 0.0;
        c21_i30 = 0;
        for (c21_i31 = 0; c21_i31 < 3; c21_i31++) {
          c21_y[c21_i28 + c21_i27] += c21_a[c21_i30 + c21_i27] * c21_b[c21_i31 +
            c21_i28];
          c21_i30 += 3;
        }

        c21_i28 += 3;
      }
    }

    for (c21_i32 = 0; c21_i32 < 9; c21_i32++) {
      c21_b_y[c21_i32] = c21_y[c21_i32];
    }

    c21_M_to_ZYX(chartInstance, c21_b_y, c21_dv5);
    for (c21_i33 = 0; c21_i33 < 3; c21_i33++) {
      c21_qT0[c21_i33] = c21_dv5[c21_i33];
    }

    _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 8);
    c21_Rz(chartInstance, -c21_qT0[0], c21_dv6);
    for (c21_i34 = 0; c21_i34 < 9; c21_i34++) {
      c21_b_R0[c21_i34] = c21_dv6[c21_i34];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 10);
    for (c21_i35 = 0; c21_i35 < 9; c21_i35++) {
      c21_b_R0[c21_i35] = c21_b_R0In[c21_i35];
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 14);
  for (c21_i36 = 0; c21_i36 < 9; c21_i36++) {
    c21_a[c21_i36] = c21_b_R0[c21_i36];
  }

  for (c21_i37 = 0; c21_i37 < 9; c21_i37++) {
    c21_b[c21_i37] = c21_b_RkIn[c21_i37];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  c21_threshold(chartInstance);
  for (c21_i38 = 0; c21_i38 < 3; c21_i38++) {
    c21_i39 = 0;
    for (c21_i40 = 0; c21_i40 < 3; c21_i40++) {
      c21_y[c21_i39 + c21_i38] = 0.0;
      c21_i41 = 0;
      for (c21_i42 = 0; c21_i42 < 3; c21_i42++) {
        c21_y[c21_i39 + c21_i38] += c21_a[c21_i41 + c21_i38] * c21_b[c21_i42 +
          c21_i39];
        c21_i41 += 3;
      }

      c21_i39 += 3;
    }
  }

  for (c21_i43 = 0; c21_i43 < 9; c21_i43++) {
    c21_b[c21_i43] = c21_b_RCal[c21_i43];
  }

  c21_eml_scalar_eg(chartInstance);
  c21_eml_scalar_eg(chartInstance);
  for (c21_i44 = 0; c21_i44 < 9; c21_i44++) {
    c21_b_Rk[c21_i44] = 0.0;
  }

  for (c21_i45 = 0; c21_i45 < 9; c21_i45++) {
    c21_b_Rk[c21_i45] = 0.0;
  }

  for (c21_i46 = 0; c21_i46 < 9; c21_i46++) {
    c21_a[c21_i46] = c21_b_Rk[c21_i46];
  }

  for (c21_i47 = 0; c21_i47 < 9; c21_i47++) {
    c21_b_Rk[c21_i47] = c21_a[c21_i47];
  }

  c21_threshold(chartInstance);
  for (c21_i48 = 0; c21_i48 < 9; c21_i48++) {
    c21_a[c21_i48] = c21_b_Rk[c21_i48];
  }

  for (c21_i49 = 0; c21_i49 < 9; c21_i49++) {
    c21_b_Rk[c21_i49] = c21_a[c21_i49];
  }

  for (c21_i50 = 0; c21_i50 < 3; c21_i50++) {
    c21_i51 = 0;
    for (c21_i52 = 0; c21_i52 < 3; c21_i52++) {
      c21_b_Rk[c21_i51 + c21_i50] = 0.0;
      c21_i53 = 0;
      for (c21_i54 = 0; c21_i54 < 3; c21_i54++) {
        c21_b_Rk[c21_i51 + c21_i50] += c21_y[c21_i53 + c21_i50] * c21_b[c21_i54
          + c21_i51];
        c21_i53 += 3;
      }

      c21_i51 += 3;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 17);
  for (c21_i55 = 0; c21_i55 < 9; c21_i55++) {
    c21_c_Rk[c21_i55] = c21_b_Rk[c21_i55];
  }

  c21_M_to_ZYX(chartInstance, c21_c_Rk, c21_dv7);
  for (c21_i56 = 0; c21_i56 < 3; c21_i56++) {
    c21_b_ZYX[c21_i56] = c21_dv7[c21_i56];
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 20);
  c21_YawRolloverCount = c21_b_YawRolloverIn[0];
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 21);
  c21_PreviousYaw = c21_b_YawRolloverIn[1];
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 22);
  c21_CurrentYaw = c21_b_ZYX[0];
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 23);
  c21_YawRolloverCount += c21_getYawRollover(chartInstance, c21_CurrentYaw,
    c21_PreviousYaw);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 24);
  c21_b_YawRollover[0] = c21_YawRolloverCount;
  c21_b_YawRollover[1] = c21_CurrentYaw;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 25);
  c21_b_ZYX[0] += 6.2831853071795862 * c21_YawRolloverCount;
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 28);
  c21_qzT = c21_b_ZYX[0];
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 29);
  c21_qyT = c21_b_ZYX[1];
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 31);
  c21_x = c21_qyT;
  c21_d0 = c21_x;
  c21_d0 = muDoubleScalarCos(c21_d0);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 0, c21_d0, 0.001, -1, 4U,
        c21_d0 > 0.001))) {
    _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 32);
    c21_b_x = c21_qzT;
    c21_c_x = c21_b_x;
    c21_c_x = muDoubleScalarSin(c21_c_x);
    c21_d_x = c21_qzT;
    c21_e_x = c21_d_x;
    c21_e_x = muDoubleScalarCos(c21_e_x);
    c21_f_x = c21_qyT;
    c21_g_x = c21_f_x;
    c21_g_x = muDoubleScalarCos(c21_g_x);
    c21_h_x = c21_qzT;
    c21_i_x = c21_h_x;
    c21_i_x = muDoubleScalarCos(c21_i_x);
    c21_j_x = c21_qzT;
    c21_k_x = c21_j_x;
    c21_k_x = muDoubleScalarSin(c21_k_x);
    c21_l_x = c21_qyT;
    c21_m_x = c21_l_x;
    c21_m_x = muDoubleScalarCos(c21_m_x);
    c21_n_x = c21_qyT;
    c21_o_x = c21_n_x;
    c21_o_x = muDoubleScalarSin(c21_o_x);
    for (c21_i57 = 0; c21_i57 < 9; c21_i57++) {
      c21_a[c21_i57] = c21_b_R0[c21_i57];
    }

    for (c21_i58 = 0; c21_i58 < 9; c21_i58++) {
      c21_b[c21_i58] = c21_b_RkIn[c21_i58];
    }

    c21_eml_scalar_eg(chartInstance);
    c21_eml_scalar_eg(chartInstance);
    c21_threshold(chartInstance);
    for (c21_i59 = 0; c21_i59 < 3; c21_i59++) {
      c21_i60 = 0;
      for (c21_i61 = 0; c21_i61 < 3; c21_i61++) {
        c21_y[c21_i60 + c21_i59] = 0.0;
        c21_i62 = 0;
        for (c21_i63 = 0; c21_i63 < 3; c21_i63++) {
          c21_y[c21_i60 + c21_i59] += c21_a[c21_i62 + c21_i59] * c21_b[c21_i63 +
            c21_i60];
          c21_i62 += 3;
        }

        c21_i60 += 3;
      }
    }

    for (c21_i64 = 0; c21_i64 < 3; c21_i64++) {
      c21_b_b[c21_i64] = c21_b_wk[c21_i64];
    }

    c21_b_eml_scalar_eg(chartInstance);
    c21_b_eml_scalar_eg(chartInstance);
    c21_threshold(chartInstance);
    for (c21_i65 = 0; c21_i65 < 3; c21_i65++) {
      c21_c_y[c21_i65] = 0.0;
      c21_i66 = 0;
      for (c21_i67 = 0; c21_i67 < 3; c21_i67++) {
        c21_c_y[c21_i65] += c21_y[c21_i66 + c21_i65] * c21_b_b[c21_i67];
        c21_i66 += 3;
      }
    }

    c21_dv8[0] = 0.0;
    c21_dv8[3] = -c21_c_x;
    c21_dv8[6] = c21_e_x * c21_g_x;
    c21_dv8[1] = 0.0;
    c21_dv8[4] = c21_i_x;
    c21_dv8[7] = c21_k_x * c21_m_x;
    c21_dv8[2] = 1.0;
    c21_dv8[5] = 0.0;
    c21_dv8[8] = -c21_o_x;
    for (c21_i68 = 0; c21_i68 < 3; c21_i68++) {
      c21_d_y[c21_i68] = c21_c_y[c21_i68];
    }

    c21_mldivide(chartInstance, c21_dv8, c21_d_y, c21_dv9);
    for (c21_i69 = 0; c21_i69 < 3; c21_i69++) {
      c21_b_dZYX[c21_i69] = c21_dv9[c21_i69];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 34);
    for (c21_i70 = 0; c21_i70 < 3; c21_i70++) {
      c21_b_dZYX[c21_i70] = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
  for (c21_i71 = 0; c21_i71 < 3; c21_i71++) {
    (*chartInstance->c21_ZYX)[c21_i71] = c21_b_ZYX[c21_i71];
  }

  for (c21_i72 = 0; c21_i72 < 3; c21_i72++) {
    (*chartInstance->c21_dZYX)[c21_i72] = c21_b_dZYX[c21_i72];
  }

  for (c21_i73 = 0; c21_i73 < 9; c21_i73++) {
    (*chartInstance->c21_Rk)[c21_i73] = c21_b_Rk[c21_i73];
  }

  for (c21_i74 = 0; c21_i74 < 9; c21_i74++) {
    (*chartInstance->c21_R0)[c21_i74] = c21_b_R0[c21_i74];
  }

  for (c21_i75 = 0; c21_i75 < 2; c21_i75++) {
    (*chartInstance->c21_YawRollover)[c21_i75] = c21_b_YawRollover[c21_i75];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 15U, chartInstance->c21_sfEvent);
}

static void initSimStructsc21_Walking01_DDA3D
  (SFc21_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c21_M_to_ZYX(SFc21_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c21_M[9], real_T c21_EulerAngles[3])
{
  uint32_T c21_debug_family_var_map[7];
  real_T c21_qY;
  real_T c21_qX;
  real_T c21_qZ;
  real_T c21_nargin = 1.0;
  real_T c21_nargout = 1.0;
  real_T c21_x;
  real_T c21_b_x;
  real_T c21_d1;
  real_T c21_d2;
  real_T c21_d3;
  boolean_T guard1 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c21_b_debug_family_names,
    c21_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_qY, 0U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_qX, 1U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_qZ, 2U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargin, 3U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargout, 4U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_M, 5U, c21_b_sf_marshallOut,
    c21_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_EulerAngles, 6U, c21_c_sf_marshallOut,
    c21_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c21_sfEvent, 13);
  c21_x = -c21_M[2];
  c21_qY = c21_x;
  guard1 = false;
  if (c21_qY < -1.0) {
    guard1 = true;
  } else {
    if (1.0 < c21_qY) {
      guard1 = true;
    }
  }

  if (guard1 == true) {
    c21_eml_error(chartInstance);
  }

  c21_b_x = c21_qY;
  c21_qY = c21_b_x;
  c21_qY = muDoubleScalarAsin(c21_qY);
  _SFD_SCRIPT_CALL(0U, chartInstance->c21_sfEvent, 14);
  c21_qX = c21_atan2(chartInstance, c21_M[5], c21_M[8]);
  _SFD_SCRIPT_CALL(0U, chartInstance->c21_sfEvent, 15);
  c21_qZ = c21_atan2(chartInstance, c21_M[1], c21_M[0]);
  _SFD_SCRIPT_CALL(0U, chartInstance->c21_sfEvent, 16);
  c21_d1 = c21_squeeze(chartInstance, c21_qZ);
  c21_d2 = c21_squeeze(chartInstance, c21_qY);
  c21_d3 = c21_squeeze(chartInstance, c21_qX);
  c21_EulerAngles[0] = c21_d1;
  c21_EulerAngles[1] = c21_d2;
  c21_EulerAngles[2] = c21_d3;
  _SFD_SCRIPT_CALL(0U, chartInstance->c21_sfEvent, -16);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c21_machineNumber, uint32_T
  c21_chartNumber, uint32_T c21_instanceNumber)
{
  (void)c21_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c21_chartNumber, c21_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_3D_Controllers\\DAQ_withElmos\\utils\\M_to_ZYX.m"));
}

static const mxArray *c21_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i76;
  real_T c21_b_inData[2];
  int32_T c21_i77;
  real_T c21_u[2];
  const mxArray *c21_y = NULL;
  SFc21_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc21_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  for (c21_i76 = 0; c21_i76 < 2; c21_i76++) {
    c21_b_inData[c21_i76] = (*(real_T (*)[2])c21_inData)[c21_i76];
  }

  for (c21_i77 = 0; c21_i77 < 2; c21_i77++) {
    c21_u[c21_i77] = c21_b_inData[c21_i77];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static void c21_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_b_YawRollover, const char_T *c21_identifier,
  real_T c21_y[2])
{
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_YawRollover),
    &c21_thisId, c21_y);
  sf_mex_destroy(&c21_b_YawRollover);
}

static void c21_b_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[2])
{
  real_T c21_dv10[2];
  int32_T c21_i78;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_dv10, 1, 0, 0U, 1, 0U, 1, 2);
  for (c21_i78 = 0; c21_i78 < 2; c21_i78++) {
    c21_y[c21_i78] = c21_dv10[c21_i78];
  }

  sf_mex_destroy(&c21_u);
}

static void c21_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_YawRollover;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y[2];
  int32_T c21_i79;
  SFc21_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc21_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c21_b_YawRollover = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_YawRollover),
    &c21_thisId, c21_y);
  sf_mex_destroy(&c21_b_YawRollover);
  for (c21_i79 = 0; c21_i79 < 2; c21_i79++) {
    (*(real_T (*)[2])c21_outData)[c21_i79] = c21_y[c21_i79];
  }

  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_b_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i80;
  int32_T c21_i81;
  int32_T c21_i82;
  real_T c21_b_inData[9];
  int32_T c21_i83;
  int32_T c21_i84;
  int32_T c21_i85;
  real_T c21_u[9];
  const mxArray *c21_y = NULL;
  SFc21_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc21_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_i80 = 0;
  for (c21_i81 = 0; c21_i81 < 3; c21_i81++) {
    for (c21_i82 = 0; c21_i82 < 3; c21_i82++) {
      c21_b_inData[c21_i82 + c21_i80] = (*(real_T (*)[9])c21_inData)[c21_i82 +
        c21_i80];
    }

    c21_i80 += 3;
  }

  c21_i83 = 0;
  for (c21_i84 = 0; c21_i84 < 3; c21_i84++) {
    for (c21_i85 = 0; c21_i85 < 3; c21_i85++) {
      c21_u[c21_i85 + c21_i83] = c21_b_inData[c21_i85 + c21_i83];
    }

    c21_i83 += 3;
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static void c21_c_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_b_R0, const char_T *c21_identifier, real_T
  c21_y[9])
{
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_R0), &c21_thisId, c21_y);
  sf_mex_destroy(&c21_b_R0);
}

static void c21_d_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[9])
{
  real_T c21_dv11[9];
  int32_T c21_i86;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_dv11, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c21_i86 = 0; c21_i86 < 9; c21_i86++) {
    c21_y[c21_i86] = c21_dv11[c21_i86];
  }

  sf_mex_destroy(&c21_u);
}

static void c21_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_R0;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y[9];
  int32_T c21_i87;
  int32_T c21_i88;
  int32_T c21_i89;
  SFc21_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc21_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c21_b_R0 = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_R0), &c21_thisId, c21_y);
  sf_mex_destroy(&c21_b_R0);
  c21_i87 = 0;
  for (c21_i88 = 0; c21_i88 < 3; c21_i88++) {
    for (c21_i89 = 0; c21_i89 < 3; c21_i89++) {
      (*(real_T (*)[9])c21_outData)[c21_i89 + c21_i87] = c21_y[c21_i89 + c21_i87];
    }

    c21_i87 += 3;
  }

  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_c_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_i90;
  real_T c21_b_inData[3];
  int32_T c21_i91;
  real_T c21_u[3];
  const mxArray *c21_y = NULL;
  SFc21_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc21_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  for (c21_i90 = 0; c21_i90 < 3; c21_i90++) {
    c21_b_inData[c21_i90] = (*(real_T (*)[3])c21_inData)[c21_i90];
  }

  for (c21_i91 = 0; c21_i91 < 3; c21_i91++) {
    c21_u[c21_i91] = c21_b_inData[c21_i91];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static void c21_e_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_b_dZYX, const char_T *c21_identifier,
  real_T c21_y[3])
{
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_dZYX), &c21_thisId,
    c21_y);
  sf_mex_destroy(&c21_b_dZYX);
}

static void c21_f_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId,
  real_T c21_y[3])
{
  real_T c21_dv12[3];
  int32_T c21_i92;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), c21_dv12, 1, 0, 0U, 1, 0U, 1, 3);
  for (c21_i92 = 0; c21_i92 < 3; c21_i92++) {
    c21_y[c21_i92] = c21_dv12[c21_i92];
  }

  sf_mex_destroy(&c21_u);
}

static void c21_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_dZYX;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y[3];
  int32_T c21_i93;
  SFc21_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc21_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c21_b_dZYX = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_dZYX), &c21_thisId,
    c21_y);
  sf_mex_destroy(&c21_b_dZYX);
  for (c21_i93 = 0; c21_i93 < 3; c21_i93++) {
    (*(real_T (*)[3])c21_outData)[c21_i93] = c21_y[c21_i93];
  }

  sf_mex_destroy(&c21_mxArrayInData);
}

static const mxArray *c21_d_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  boolean_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc21_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(boolean_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static const mxArray *c21_e_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  real_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc21_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(real_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static real_T c21_g_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  real_T c21_y;
  real_T c21_d4;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_d4, 1, 0, 0U, 0, 0U, 0);
  c21_y = c21_d4;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_nargout;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  real_T c21_y;
  SFc21_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc21_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c21_nargout = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_nargout),
    &c21_thisId);
  sf_mex_destroy(&c21_nargout);
  *(real_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

const mxArray *sf_c21_Walking01_DDA3D_get_eml_resolved_functions_info(void)
{
  const mxArray *c21_nameCaptureInfo = NULL;
  c21_nameCaptureInfo = NULL;
  sf_mex_assign(&c21_nameCaptureInfo, sf_mex_createstruct("structure", 2, 43, 1),
                false);
  c21_info_helper(&c21_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c21_nameCaptureInfo);
  return c21_nameCaptureInfo;
}

static void c21_info_helper(const mxArray **c21_info)
{
  const mxArray *c21_rhs0 = NULL;
  const mxArray *c21_lhs0 = NULL;
  const mxArray *c21_rhs1 = NULL;
  const mxArray *c21_lhs1 = NULL;
  const mxArray *c21_rhs2 = NULL;
  const mxArray *c21_lhs2 = NULL;
  const mxArray *c21_rhs3 = NULL;
  const mxArray *c21_lhs3 = NULL;
  const mxArray *c21_rhs4 = NULL;
  const mxArray *c21_lhs4 = NULL;
  const mxArray *c21_rhs5 = NULL;
  const mxArray *c21_lhs5 = NULL;
  const mxArray *c21_rhs6 = NULL;
  const mxArray *c21_lhs6 = NULL;
  const mxArray *c21_rhs7 = NULL;
  const mxArray *c21_lhs7 = NULL;
  const mxArray *c21_rhs8 = NULL;
  const mxArray *c21_lhs8 = NULL;
  const mxArray *c21_rhs9 = NULL;
  const mxArray *c21_lhs9 = NULL;
  const mxArray *c21_rhs10 = NULL;
  const mxArray *c21_lhs10 = NULL;
  const mxArray *c21_rhs11 = NULL;
  const mxArray *c21_lhs11 = NULL;
  const mxArray *c21_rhs12 = NULL;
  const mxArray *c21_lhs12 = NULL;
  const mxArray *c21_rhs13 = NULL;
  const mxArray *c21_lhs13 = NULL;
  const mxArray *c21_rhs14 = NULL;
  const mxArray *c21_lhs14 = NULL;
  const mxArray *c21_rhs15 = NULL;
  const mxArray *c21_lhs15 = NULL;
  const mxArray *c21_rhs16 = NULL;
  const mxArray *c21_lhs16 = NULL;
  const mxArray *c21_rhs17 = NULL;
  const mxArray *c21_lhs17 = NULL;
  const mxArray *c21_rhs18 = NULL;
  const mxArray *c21_lhs18 = NULL;
  const mxArray *c21_rhs19 = NULL;
  const mxArray *c21_lhs19 = NULL;
  const mxArray *c21_rhs20 = NULL;
  const mxArray *c21_lhs20 = NULL;
  const mxArray *c21_rhs21 = NULL;
  const mxArray *c21_lhs21 = NULL;
  const mxArray *c21_rhs22 = NULL;
  const mxArray *c21_lhs22 = NULL;
  const mxArray *c21_rhs23 = NULL;
  const mxArray *c21_lhs23 = NULL;
  const mxArray *c21_rhs24 = NULL;
  const mxArray *c21_lhs24 = NULL;
  const mxArray *c21_rhs25 = NULL;
  const mxArray *c21_lhs25 = NULL;
  const mxArray *c21_rhs26 = NULL;
  const mxArray *c21_lhs26 = NULL;
  const mxArray *c21_rhs27 = NULL;
  const mxArray *c21_lhs27 = NULL;
  const mxArray *c21_rhs28 = NULL;
  const mxArray *c21_lhs28 = NULL;
  const mxArray *c21_rhs29 = NULL;
  const mxArray *c21_lhs29 = NULL;
  const mxArray *c21_rhs30 = NULL;
  const mxArray *c21_lhs30 = NULL;
  const mxArray *c21_rhs31 = NULL;
  const mxArray *c21_lhs31 = NULL;
  const mxArray *c21_rhs32 = NULL;
  const mxArray *c21_lhs32 = NULL;
  const mxArray *c21_rhs33 = NULL;
  const mxArray *c21_lhs33 = NULL;
  const mxArray *c21_rhs34 = NULL;
  const mxArray *c21_lhs34 = NULL;
  const mxArray *c21_rhs35 = NULL;
  const mxArray *c21_lhs35 = NULL;
  const mxArray *c21_rhs36 = NULL;
  const mxArray *c21_lhs36 = NULL;
  const mxArray *c21_rhs37 = NULL;
  const mxArray *c21_lhs37 = NULL;
  const mxArray *c21_rhs38 = NULL;
  const mxArray *c21_lhs38 = NULL;
  const mxArray *c21_rhs39 = NULL;
  const mxArray *c21_lhs39 = NULL;
  const mxArray *c21_rhs40 = NULL;
  const mxArray *c21_lhs40 = NULL;
  const mxArray *c21_rhs41 = NULL;
  const mxArray *c21_lhs41 = NULL;
  const mxArray *c21_rhs42 = NULL;
  const mxArray *c21_lhs42 = NULL;
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c21_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c21_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c21_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c21_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c21_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c21_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c21_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 7);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c21_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 8);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 8);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c21_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 9);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 9);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c21_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 10);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 10);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c21_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c21_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 12);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c21_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("M_to_ZYX"), "name", "name",
                  13);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/DAQ_withElmos/utils/M_to_ZYX.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1433971706U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c21_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/DAQ_withElmos/utils/M_to_ZYX.m"),
                  "context", "context", 14);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("asin"), "name", "name", 14);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395346494U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c21_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_error"), "name", "name",
                  15);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1343851958U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c21_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_asin"), "name",
                  "name", 16);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asin.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1343851976U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c21_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/DAQ_withElmos/utils/M_to_ZYX.m"),
                  "context", "context", 17);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("atan2"), "name", "name", 17);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c21_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 18);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c21_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 19);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c21_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 20);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 20);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c21_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan2.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_atan2"), "name",
                  "name", 21);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286840320U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c21_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/DAQ_withElmos/utils/M_to_ZYX.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("squeeze"), "name", "name",
                  22);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/squeeze.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286840370U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c21_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/squeeze.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 23);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c21_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/squeeze.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 24);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c21_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 25);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("cos"), "name", "name", 25);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c21_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 26);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286840322U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c21_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 27);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("sin"), "name", "name", 27);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c21_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 28);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286840336U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c21_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(""), "context", "context", 29);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("mldivide"), "name", "name",
                  29);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1319751566U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c21_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "context",
                  "context", 30);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_lusolve"), "name",
                  "name", 30);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1370031486U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c21_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve3x3"),
                  "context", "context", 31);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_xcabs1"), "name", "name",
                  31);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c21_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.refblas.xcabs1"), "name", "name", 32);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c21_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "context", "context", 33);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("abs"), "name", "name", 33);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c21_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c21_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 35);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 35);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c21_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve3x3"),
                  "context", "context", 36);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("rdivide"), "name", "name",
                  36);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c21_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 37);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c21_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 38);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c21_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_div"), "name", "name",
                  39);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c21_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 40);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c21_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular"),
                  "context", "context", 41);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_warning"), "name",
                  "name", 41);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1286840402U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c21_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve3x3"),
                  "context", "context", 42);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 42);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c21_info, c21_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c21_info, c21_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c21_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c21_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c21_info, sf_mex_duplicatearraysafe(&c21_lhs42), "lhs", "lhs",
                  42);
  sf_mex_destroy(&c21_rhs0);
  sf_mex_destroy(&c21_lhs0);
  sf_mex_destroy(&c21_rhs1);
  sf_mex_destroy(&c21_lhs1);
  sf_mex_destroy(&c21_rhs2);
  sf_mex_destroy(&c21_lhs2);
  sf_mex_destroy(&c21_rhs3);
  sf_mex_destroy(&c21_lhs3);
  sf_mex_destroy(&c21_rhs4);
  sf_mex_destroy(&c21_lhs4);
  sf_mex_destroy(&c21_rhs5);
  sf_mex_destroy(&c21_lhs5);
  sf_mex_destroy(&c21_rhs6);
  sf_mex_destroy(&c21_lhs6);
  sf_mex_destroy(&c21_rhs7);
  sf_mex_destroy(&c21_lhs7);
  sf_mex_destroy(&c21_rhs8);
  sf_mex_destroy(&c21_lhs8);
  sf_mex_destroy(&c21_rhs9);
  sf_mex_destroy(&c21_lhs9);
  sf_mex_destroy(&c21_rhs10);
  sf_mex_destroy(&c21_lhs10);
  sf_mex_destroy(&c21_rhs11);
  sf_mex_destroy(&c21_lhs11);
  sf_mex_destroy(&c21_rhs12);
  sf_mex_destroy(&c21_lhs12);
  sf_mex_destroy(&c21_rhs13);
  sf_mex_destroy(&c21_lhs13);
  sf_mex_destroy(&c21_rhs14);
  sf_mex_destroy(&c21_lhs14);
  sf_mex_destroy(&c21_rhs15);
  sf_mex_destroy(&c21_lhs15);
  sf_mex_destroy(&c21_rhs16);
  sf_mex_destroy(&c21_lhs16);
  sf_mex_destroy(&c21_rhs17);
  sf_mex_destroy(&c21_lhs17);
  sf_mex_destroy(&c21_rhs18);
  sf_mex_destroy(&c21_lhs18);
  sf_mex_destroy(&c21_rhs19);
  sf_mex_destroy(&c21_lhs19);
  sf_mex_destroy(&c21_rhs20);
  sf_mex_destroy(&c21_lhs20);
  sf_mex_destroy(&c21_rhs21);
  sf_mex_destroy(&c21_lhs21);
  sf_mex_destroy(&c21_rhs22);
  sf_mex_destroy(&c21_lhs22);
  sf_mex_destroy(&c21_rhs23);
  sf_mex_destroy(&c21_lhs23);
  sf_mex_destroy(&c21_rhs24);
  sf_mex_destroy(&c21_lhs24);
  sf_mex_destroy(&c21_rhs25);
  sf_mex_destroy(&c21_lhs25);
  sf_mex_destroy(&c21_rhs26);
  sf_mex_destroy(&c21_lhs26);
  sf_mex_destroy(&c21_rhs27);
  sf_mex_destroy(&c21_lhs27);
  sf_mex_destroy(&c21_rhs28);
  sf_mex_destroy(&c21_lhs28);
  sf_mex_destroy(&c21_rhs29);
  sf_mex_destroy(&c21_lhs29);
  sf_mex_destroy(&c21_rhs30);
  sf_mex_destroy(&c21_lhs30);
  sf_mex_destroy(&c21_rhs31);
  sf_mex_destroy(&c21_lhs31);
  sf_mex_destroy(&c21_rhs32);
  sf_mex_destroy(&c21_lhs32);
  sf_mex_destroy(&c21_rhs33);
  sf_mex_destroy(&c21_lhs33);
  sf_mex_destroy(&c21_rhs34);
  sf_mex_destroy(&c21_lhs34);
  sf_mex_destroy(&c21_rhs35);
  sf_mex_destroy(&c21_lhs35);
  sf_mex_destroy(&c21_rhs36);
  sf_mex_destroy(&c21_lhs36);
  sf_mex_destroy(&c21_rhs37);
  sf_mex_destroy(&c21_lhs37);
  sf_mex_destroy(&c21_rhs38);
  sf_mex_destroy(&c21_lhs38);
  sf_mex_destroy(&c21_rhs39);
  sf_mex_destroy(&c21_lhs39);
  sf_mex_destroy(&c21_rhs40);
  sf_mex_destroy(&c21_lhs40);
  sf_mex_destroy(&c21_rhs41);
  sf_mex_destroy(&c21_lhs41);
  sf_mex_destroy(&c21_rhs42);
  sf_mex_destroy(&c21_lhs42);
}

static const mxArray *c21_emlrt_marshallOut(const char * c21_u)
{
  const mxArray *c21_y = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c21_u)), false);
  return c21_y;
}

static const mxArray *c21_b_emlrt_marshallOut(const uint32_T c21_u)
{
  const mxArray *c21_y = NULL;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 7, 0U, 0U, 0U, 0), false);
  return c21_y;
}

static void c21_eml_scalar_eg(SFc21_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c21_threshold(SFc21_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c21_eml_error(SFc21_Walking01_DDA3DInstanceStruct *chartInstance)
{
  int32_T c21_i94;
  static char_T c21_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c21_u[30];
  const mxArray *c21_y = NULL;
  int32_T c21_i95;
  static char_T c21_cv1[4] = { 'a', 's', 'i', 'n' };

  char_T c21_b_u[4];
  const mxArray *c21_b_y = NULL;
  (void)chartInstance;
  for (c21_i94 = 0; c21_i94 < 30; c21_i94++) {
    c21_u[c21_i94] = c21_cv0[c21_i94];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c21_i95 = 0; c21_i95 < 4; c21_i95++) {
    c21_b_u[c21_i95] = c21_cv1[c21_i95];
  }

  c21_b_y = NULL;
  sf_mex_assign(&c21_b_y, sf_mex_create("y", c21_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c21_y, 14, c21_b_y));
}

static real_T c21_atan2(SFc21_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c21_y, real_T c21_x)
{
  real_T c21_b_y;
  real_T c21_b_x;
  (void)chartInstance;
  c21_b_y = c21_y;
  c21_b_x = c21_x;
  return muDoubleScalarAtan2(c21_b_y, c21_b_x);
}

static real_T c21_squeeze(SFc21_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c21_a)
{
  (void)chartInstance;
  return c21_a;
}

static void c21_Rz(SFc21_Walking01_DDA3DInstanceStruct *chartInstance, real_T
                   c21_t, real_T c21_R[9])
{
  uint32_T c21_debug_family_var_map[4];
  real_T c21_nargin = 1.0;
  real_T c21_nargout = 1.0;
  real_T c21_x;
  real_T c21_b_x;
  real_T c21_c_x;
  real_T c21_d_x;
  real_T c21_e_x;
  real_T c21_f_x;
  real_T c21_g_x;
  real_T c21_h_x;
  int32_T c21_i96;
  int32_T c21_i97;
  static real_T c21_dv13[3] = { 0.0, 0.0, 1.0 };

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c21_c_debug_family_names,
    c21_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargin, 0U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargout, 1U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_t, 2U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c21_R, 3U, c21_b_sf_marshallOut,
    c21_b_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 39);
  c21_x = c21_t;
  c21_b_x = c21_x;
  c21_b_x = muDoubleScalarCos(c21_b_x);
  c21_c_x = c21_t;
  c21_d_x = c21_c_x;
  c21_d_x = muDoubleScalarSin(c21_d_x);
  c21_e_x = c21_t;
  c21_f_x = c21_e_x;
  c21_f_x = muDoubleScalarSin(c21_f_x);
  c21_g_x = c21_t;
  c21_h_x = c21_g_x;
  c21_h_x = muDoubleScalarCos(c21_h_x);
  c21_R[0] = c21_b_x;
  c21_R[3] = -c21_d_x;
  c21_R[6] = 0.0;
  c21_R[1] = c21_f_x;
  c21_R[4] = c21_h_x;
  c21_R[7] = 0.0;
  c21_i96 = 0;
  for (c21_i97 = 0; c21_i97 < 3; c21_i97++) {
    c21_R[c21_i96 + 2] = c21_dv13[c21_i97];
    c21_i96 += 3;
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, -39);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c21_getYawRollover(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, real_T c21_CurrentYaw, real_T c21_PreviousYaw)
{
  real_T c21_Rollover;
  uint32_T c21_debug_family_var_map[5];
  real_T c21_nargin = 2.0;
  real_T c21_nargout = 1.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c21_d_debug_family_names,
    c21_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargin, 0U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_nargout, 1U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_CurrentYaw, 2U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_PreviousYaw, 3U,
    c21_e_sf_marshallOut, c21_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c21_Rollover, 4U, c21_e_sf_marshallOut,
    c21_d_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 47);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 1, c21_PreviousYaw, 0.0,
        -1, 4U, c21_PreviousYaw > 0.0))) {
    if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 2, c21_CurrentYaw,
          c21_PreviousYaw - 3.1415926535897931, -1, 2U, c21_CurrentYaw <
          c21_PreviousYaw - 3.1415926535897931))) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 2, true);
      _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 48);
      c21_Rollover = 1.0;
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 2, false);
    _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 49);
    guard2 = false;
    if (CV_EML_COND(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 3, c21_PreviousYaw, 0.0,
          -1, 2U, c21_PreviousYaw < 0.0))) {
      if (CV_EML_COND(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 4, c21_CurrentYaw,
            c21_PreviousYaw + 3.1415926535897931, -1, 4U, c21_CurrentYaw >
            c21_PreviousYaw + 3.1415926535897931))) {
        CV_EML_MCDC(0, 1, 1, true);
        CV_EML_IF(0, 1, 3, true);
        _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 50);
        c21_Rollover = -1.0;
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(0, 1, 1, false);
      CV_EML_IF(0, 1, 3, false);
      _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, 52);
      c21_Rollover = 0.0;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c21_sfEvent, -52);
  _SFD_SYMBOL_SCOPE_POP();
  return c21_Rollover;
}

static void c21_b_eml_scalar_eg(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c21_mldivide(SFc21_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c21_A[9], real_T c21_B[3], real_T c21_Y[3])
{
  int32_T c21_i98;
  real_T c21_b_A[9];
  int32_T c21_r1;
  int32_T c21_r2;
  int32_T c21_r3;
  real_T c21_x;
  real_T c21_b_x;
  real_T c21_c_x;
  real_T c21_d_x;
  real_T c21_y;
  real_T c21_e_x;
  real_T c21_f_x;
  real_T c21_b_y;
  real_T c21_maxval;
  real_T c21_g_x;
  real_T c21_h_x;
  real_T c21_i_x;
  real_T c21_j_x;
  real_T c21_c_y;
  real_T c21_k_x;
  real_T c21_l_x;
  real_T c21_d_y;
  real_T c21_a21;
  real_T c21_m_x;
  real_T c21_n_x;
  real_T c21_o_x;
  real_T c21_p_x;
  real_T c21_e_y;
  real_T c21_q_x;
  real_T c21_r_x;
  real_T c21_f_y;
  real_T c21_d;
  real_T c21_s_x;
  real_T c21_t_x;
  real_T c21_u_x;
  real_T c21_v_x;
  real_T c21_g_y;
  real_T c21_w_x;
  real_T c21_x_x;
  real_T c21_h_y;
  real_T c21_b_d;
  real_T c21_y_x;
  real_T c21_ab_x;
  real_T c21_bb_x;
  real_T c21_cb_x;
  real_T c21_i_y;
  real_T c21_db_x;
  real_T c21_eb_x;
  real_T c21_j_y;
  real_T c21_c_d;
  int32_T c21_rtemp;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  for (c21_i98 = 0; c21_i98 < 9; c21_i98++) {
    c21_b_A[c21_i98] = c21_A[c21_i98];
  }

  c21_r1 = 1;
  c21_r2 = 2;
  c21_r3 = 3;
  c21_x = c21_b_A[0];
  c21_b_x = c21_x;
  c21_c_x = c21_b_x;
  c21_d_x = c21_c_x;
  c21_y = muDoubleScalarAbs(c21_d_x);
  c21_e_x = 0.0;
  c21_f_x = c21_e_x;
  c21_b_y = muDoubleScalarAbs(c21_f_x);
  c21_maxval = c21_y + c21_b_y;
  c21_g_x = c21_b_A[1];
  c21_h_x = c21_g_x;
  c21_i_x = c21_h_x;
  c21_j_x = c21_i_x;
  c21_c_y = muDoubleScalarAbs(c21_j_x);
  c21_k_x = 0.0;
  c21_l_x = c21_k_x;
  c21_d_y = muDoubleScalarAbs(c21_l_x);
  c21_a21 = c21_c_y + c21_d_y;
  if (c21_a21 > c21_maxval) {
    c21_maxval = c21_a21;
    c21_r1 = 2;
    c21_r2 = 1;
  }

  c21_m_x = c21_b_A[2];
  c21_n_x = c21_m_x;
  c21_o_x = c21_n_x;
  c21_p_x = c21_o_x;
  c21_e_y = muDoubleScalarAbs(c21_p_x);
  c21_q_x = 0.0;
  c21_r_x = c21_q_x;
  c21_f_y = muDoubleScalarAbs(c21_r_x);
  c21_d = c21_e_y + c21_f_y;
  if (c21_d > c21_maxval) {
    c21_r1 = 3;
    c21_r2 = 2;
    c21_r3 = 1;
  }

  c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r2), 1, 3, 1, 0) - 1] = c21_rdivide(chartInstance,
    c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r2), 1, 3, 1, 0) - 1], c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_r1), 1, 3, 1, 0) - 1]);
  c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r3), 1, 3, 1, 0) - 1] = c21_rdivide(chartInstance,
    c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r3), 1, 3, 1, 0) - 1], c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_r1), 1, 3, 1, 0) - 1]);
  c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r2), 1, 3, 1, 0) + 2] = c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_r2), 1, 3, 1, 0) + 2] -
    c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r2), 1, 3, 1, 0) - 1] * c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_r1), 1, 3, 1, 0) + 2];
  c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r3), 1, 3, 1, 0) + 2] = c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_r3), 1, 3, 1, 0) + 2] -
    c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r3), 1, 3, 1, 0) - 1] * c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_r1), 1, 3, 1, 0) + 2];
  c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r2), 1, 3, 1, 0) + 5] = c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_r2), 1, 3, 1, 0) + 5] -
    c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r2), 1, 3, 1, 0) - 1] * c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_r1), 1, 3, 1, 0) + 5];
  c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r3), 1, 3, 1, 0) + 5] = c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_r3), 1, 3, 1, 0) + 5] -
    c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r3), 1, 3, 1, 0) - 1] * c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_r1), 1, 3, 1, 0) + 5];
  c21_s_x = c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c21_r3), 1, 3, 1, 0) + 2];
  c21_t_x = c21_s_x;
  c21_u_x = c21_t_x;
  c21_v_x = c21_u_x;
  c21_g_y = muDoubleScalarAbs(c21_v_x);
  c21_w_x = 0.0;
  c21_x_x = c21_w_x;
  c21_h_y = muDoubleScalarAbs(c21_x_x);
  c21_b_d = c21_g_y + c21_h_y;
  c21_y_x = c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c21_r2), 1, 3, 1, 0) + 2];
  c21_ab_x = c21_y_x;
  c21_bb_x = c21_ab_x;
  c21_cb_x = c21_bb_x;
  c21_i_y = muDoubleScalarAbs(c21_cb_x);
  c21_db_x = 0.0;
  c21_eb_x = c21_db_x;
  c21_j_y = muDoubleScalarAbs(c21_eb_x);
  c21_c_d = c21_i_y + c21_j_y;
  if (c21_b_d > c21_c_d) {
    c21_rtemp = c21_r2;
    c21_r2 = c21_r3;
    c21_r3 = c21_rtemp;
  }

  c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r3), 1, 3, 1, 0) + 2] = c21_rdivide(chartInstance,
    c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r3), 1, 3, 1, 0) + 2], c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_r2), 1, 3, 1, 0) + 2]);
  c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r3), 1, 3, 1, 0) + 5] = c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_r3), 1, 3, 1, 0) + 5] -
    c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r3), 1, 3, 1, 0) + 2] * c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c21_r2), 1, 3, 1, 0) + 5];
  guard1 = false;
  guard2 = false;
  if (c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c21_r1), 1, 3, 1, 0) - 1] == 0.0) {
    guard2 = true;
  } else if (c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
              ("", (real_T)c21_r2), 1, 3, 1, 0) + 2] == 0.0) {
    guard2 = true;
  } else {
    if (c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c21_r3), 1, 3, 1, 0) + 5] == 0.0) {
      guard1 = true;
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c21_eml_warning(chartInstance);
  }

  c21_b_eml_scalar_eg(chartInstance);
  c21_Y[0] = c21_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c21_r1), 1, 3, 1, 0) - 1];
  c21_Y[1] = c21_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c21_r2), 1, 3, 1, 0) - 1] - c21_Y[0] *
    c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r2), 1, 3, 1, 0) - 1];
  c21_Y[2] = (c21_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c21_r3), 1, 3, 1, 0) - 1] - c21_Y[0] *
              c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c21_r3), 1, 3, 1, 0) - 1]) - c21_Y[1] *
    c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r3), 1, 3, 1, 0) + 2];
  c21_Y[2] = c21_rdivide(chartInstance, c21_Y[2],
    c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r3), 1, 3, 1, 0) + 5]);
  c21_Y[0] -= c21_Y[2] * c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c21_r1), 1, 3, 1, 0) + 5];
  c21_Y[1] -= c21_Y[2] * c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c21_r2), 1, 3, 1, 0) + 5];
  c21_Y[1] = c21_rdivide(chartInstance, c21_Y[1],
    c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r2), 1, 3, 1, 0) + 2]);
  c21_Y[0] -= c21_Y[1] * c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c21_r1), 1, 3, 1, 0) + 2];
  c21_Y[0] = c21_rdivide(chartInstance, c21_Y[0],
    c21_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c21_r1), 1, 3, 1, 0) - 1]);
}

static real_T c21_rdivide(SFc21_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c21_x, real_T c21_y)
{
  real_T c21_b_x;
  real_T c21_b_y;
  real_T c21_c_x;
  real_T c21_c_y;
  (void)chartInstance;
  c21_b_x = c21_x;
  c21_b_y = c21_y;
  c21_c_x = c21_b_x;
  c21_c_y = c21_b_y;
  return c21_c_x / c21_c_y;
}

static void c21_eml_warning(SFc21_Walking01_DDA3DInstanceStruct *chartInstance)
{
  int32_T c21_i99;
  static char_T c21_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c21_u[27];
  const mxArray *c21_y = NULL;
  (void)chartInstance;
  for (c21_i99 = 0; c21_i99 < 27; c21_i99++) {
    c21_u[c21_i99] = c21_varargin_1[c21_i99];
  }

  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", c21_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c21_y));
}

static const mxArray *c21_f_sf_marshallOut(void *chartInstanceVoid, void
  *c21_inData)
{
  const mxArray *c21_mxArrayOutData = NULL;
  int32_T c21_u;
  const mxArray *c21_y = NULL;
  SFc21_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc21_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c21_mxArrayOutData = NULL;
  c21_u = *(int32_T *)c21_inData;
  c21_y = NULL;
  sf_mex_assign(&c21_y, sf_mex_create("y", &c21_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c21_mxArrayOutData, c21_y, false);
  return c21_mxArrayOutData;
}

static int32_T c21_h_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  int32_T c21_y;
  int32_T c21_i100;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_i100, 1, 6, 0U, 0, 0U, 0);
  c21_y = c21_i100;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void c21_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c21_mxArrayInData, const char_T *c21_varName, void *c21_outData)
{
  const mxArray *c21_b_sfEvent;
  const char_T *c21_identifier;
  emlrtMsgIdentifier c21_thisId;
  int32_T c21_y;
  SFc21_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc21_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c21_b_sfEvent = sf_mex_dup(c21_mxArrayInData);
  c21_identifier = c21_varName;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c21_b_sfEvent),
    &c21_thisId);
  sf_mex_destroy(&c21_b_sfEvent);
  *(int32_T *)c21_outData = c21_y;
  sf_mex_destroy(&c21_mxArrayInData);
}

static uint8_T c21_i_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_b_is_active_c21_Walking01_DDA3D, const
  char_T *c21_identifier)
{
  uint8_T c21_y;
  emlrtMsgIdentifier c21_thisId;
  c21_thisId.fIdentifier = c21_identifier;
  c21_thisId.fParent = NULL;
  c21_y = c21_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c21_b_is_active_c21_Walking01_DDA3D), &c21_thisId);
  sf_mex_destroy(&c21_b_is_active_c21_Walking01_DDA3D);
  return c21_y;
}

static uint8_T c21_j_emlrt_marshallIn(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c21_u, const emlrtMsgIdentifier *c21_parentId)
{
  uint8_T c21_y;
  uint8_T c21_u0;
  (void)chartInstance;
  sf_mex_import(c21_parentId, sf_mex_dup(c21_u), &c21_u0, 1, 3, 0U, 0, 0U, 0);
  c21_y = c21_u0;
  sf_mex_destroy(&c21_u);
  return c21_y;
}

static void init_dsm_address_info(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc21_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c21_RkIn = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c21_wk = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c21_RCal = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c21_Reset = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c21_R0In = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c21_ZYX = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c21_dZYX = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c21_Rk = (real_T (*)[9])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c21_R0 = (real_T (*)[9])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c21_YawRolloverIn = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c21_YawRollover = (real_T (*)[2])ssGetOutputPortSignal_wrapper
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

void sf_c21_Walking01_DDA3D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4053636876U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3430932392U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2993011273U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1923766444U);
}

mxArray* sf_c21_Walking01_DDA3D_get_post_codegen_info(void);
mxArray *sf_c21_Walking01_DDA3D_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("V699iiUYGcKUYsuOEAQYIE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(2);
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

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(3);
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
      pr[0] = (double)(2);
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
    mxArray* mxPostCodegenInfo = sf_c21_Walking01_DDA3D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c21_Walking01_DDA3D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c21_Walking01_DDA3D_jit_fallback_info(void)
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

mxArray *sf_c21_Walking01_DDA3D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c21_Walking01_DDA3D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c21_Walking01_DDA3D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x6'type','srcId','name','auxInfo'{{M[1],M[13],T\"R0\",},{M[1],M[5],T\"Rk\",},{M[1],M[18],T\"YawRollover\",},{M[1],M[10],T\"ZYX\",},{M[1],M[16],T\"dZYX\",},{M[8],M[0],T\"is_active_c21_Walking01_DDA3D\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 6, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c21_Walking01_DDA3D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc21_Walking01_DDA3DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc21_Walking01_DDA3DInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_DDA3DMachineNumber_,
           21,
           1,
           1,
           0,
           11,
           0,
           0,
           0,
           0,
           1,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"RkIn");
          _SFD_SET_DATA_PROPS(1,1,1,0,"wk");
          _SFD_SET_DATA_PROPS(2,1,1,0,"RCal");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Reset");
          _SFD_SET_DATA_PROPS(4,1,1,0,"R0In");
          _SFD_SET_DATA_PROPS(5,2,0,1,"ZYX");
          _SFD_SET_DATA_PROPS(6,2,0,1,"dZYX");
          _SFD_SET_DATA_PROPS(7,2,0,1,"Rk");
          _SFD_SET_DATA_PROPS(8,2,0,1,"R0");
          _SFD_SET_DATA_PROPS(9,1,1,0,"YawRolloverIn");
          _SFD_SET_DATA_PROPS(10,2,0,1,"YawRollover");
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
        _SFD_CV_INIT_EML(0,1,3,4,0,0,0,0,0,4,2);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1157);
        _SFD_CV_INIT_EML_FCN(0,1,"Rz",1159,-1,1233);
        _SFD_CV_INIT_EML_FCN(0,2,"getYawRollover",1235,-1,1680);
        _SFD_CV_INIT_EML_IF(0,1,0,241,251,385,416);
        _SFD_CV_INIT_EML_IF(0,1,1,988,1004,1115,1153);
        _SFD_CV_INIT_EML_IF(0,1,2,1481,1532,1559,1676);
        _SFD_CV_INIT_EML_IF(0,1,3,1559,1614,1642,1676);

        {
          static int condStart[] = { 1485, 1502 };

          static int condEnd[] = { 1498, 1531 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,1485,1531,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 1567, 1584 };

          static int condEnd[] = { 1580, 1613 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,1567,1613,2,2,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,991,1004,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,1485,1498,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,1502,1531,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,1567,1580,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,1584,1613,-1,4);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"M_to_ZYX",0,-1,688);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c21_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_c_sf_marshallOut,(MexInFcnForType)
            c21_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_c_sf_marshallOut,(MexInFcnForType)
            c21_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_b_sf_marshallOut,(MexInFcnForType)
            c21_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_b_sf_marshallOut,(MexInFcnForType)
            c21_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c21_sf_marshallOut,(MexInFcnForType)
            c21_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c21_RkIn);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c21_wk);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c21_RCal);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c21_Reset);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c21_R0In);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c21_ZYX);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c21_dZYX);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c21_Rk);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c21_R0);
        _SFD_SET_DATA_VALUE_PTR(9U, *chartInstance->c21_YawRolloverIn);
        _SFD_SET_DATA_VALUE_PTR(10U, *chartInstance->c21_YawRollover);
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
  return "ufxMySglYksJ0YipIiDyrD";
}

static void sf_opaque_initialize_c21_Walking01_DDA3D(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc21_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c21_Walking01_DDA3D((SFc21_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
  initialize_c21_Walking01_DDA3D((SFc21_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c21_Walking01_DDA3D(void *chartInstanceVar)
{
  enable_c21_Walking01_DDA3D((SFc21_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c21_Walking01_DDA3D(void *chartInstanceVar)
{
  disable_c21_Walking01_DDA3D((SFc21_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c21_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_gateway_c21_Walking01_DDA3D((SFc21_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c21_Walking01_DDA3D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c21_Walking01_DDA3D((SFc21_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c21_Walking01_DDA3D(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c21_Walking01_DDA3D((SFc21_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c21_Walking01_DDA3D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc21_Walking01_DDA3DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_DDA3D_optimization_info();
    }

    finalize_c21_Walking01_DDA3D((SFc21_Walking01_DDA3DInstanceStruct*)
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
  initSimStructsc21_Walking01_DDA3D((SFc21_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c21_Walking01_DDA3D(SimStruct *S)
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
    initialize_params_c21_Walking01_DDA3D((SFc21_Walking01_DDA3DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c21_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      21);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,21,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,21,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,21);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,21,6);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,21,5);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=5; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 6; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,21);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(763001665U));
  ssSetChecksum1(S,(3798485957U));
  ssSetChecksum2(S,(64144748U));
  ssSetChecksum3(S,(750558914U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c21_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c21_Walking01_DDA3D(SimStruct *S)
{
  SFc21_Walking01_DDA3DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc21_Walking01_DDA3DInstanceStruct *)utMalloc(sizeof
    (SFc21_Walking01_DDA3DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc21_Walking01_DDA3DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c21_Walking01_DDA3D;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c21_Walking01_DDA3D;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c21_Walking01_DDA3D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c21_Walking01_DDA3D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c21_Walking01_DDA3D;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c21_Walking01_DDA3D;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c21_Walking01_DDA3D;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c21_Walking01_DDA3D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c21_Walking01_DDA3D;
  chartInstance->chartInfo.mdlStart = mdlStart_c21_Walking01_DDA3D;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c21_Walking01_DDA3D;
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

void c21_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c21_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c21_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c21_Walking01_DDA3D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c21_Walking01_DDA3D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
