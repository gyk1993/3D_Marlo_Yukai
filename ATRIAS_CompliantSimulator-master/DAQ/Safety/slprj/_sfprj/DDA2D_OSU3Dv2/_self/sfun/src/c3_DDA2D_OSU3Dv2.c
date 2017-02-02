/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DDA2D_OSU3Dv2_sfun.h"
#include "c3_DDA2D_OSU3Dv2.h"
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
static const char * c3_debug_family_names[14] = { "F", "J", "nargin", "nargout",
  "pF", "vF", "J4", "JRCol", "FootPoints", "GroundModel", "d", "GRF", "tau",
  "dd" };

static const char * c3_b_debug_family_names[7] = { "nargin", "nargout", "d", "v",
  "GroundModel", "dd", "mu" };

static const char * c3_c_debug_family_names[11] = { "Fn", "mu", "nargin",
  "nargout", "zG", "dzG", "d", "v", "GroundModel", "F", "dd" };

/* Function Declarations */
static void initialize_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initialize_params_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct *
  chartInstance);
static void enable_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void disable_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c3_update_debugger_state_c3_DDA2D_OSU3Dv2
  (SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_DDA2D_OSU3Dv2
  (SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void set_sim_state_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_st);
static void finalize_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void sf_gateway_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void mdl_start_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initSimStructsc3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c3_LuGreHertzian(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c3_zG, real_T c3_dzG, real_T c3_b_d[2], real_T c3_v[2],
  c3_GroundModelParamsBus *c3_b_GroundModel, real_T c3_F[3], real_T c3_b_dd[2]);
static void c3_LuGre(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
                     c3_b_d[2], real_T c3_v[2], c3_GroundModelParamsBus
                     *c3_b_GroundModel, real_T c3_b_dd[2], real_T c3_mu[2]);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static void c3_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  const mxArray *c3_b_dd, const char_T *c3_identifier, real_T c3_y[2]);
static void c3_b_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2]);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_c_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_b_tau, const char_T *c3_identifier, real_T
  c3_y[16]);
static void c3_d_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[16]);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static void c3_e_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_b_GRF, const char_T *c3_identifier, real_T
  c3_y[3]);
static void c3_f_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[3]);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static real_T c3_g_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_h_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[48]);
static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_i_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  c3_GroundModelParamsBus *c3_y);
static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static void c3_eml_scalar_eg(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c3_eml_error(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c3_b_eml_error(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c3_abs(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c3_x
                   [2], real_T c3_y[2]);
static void c3_eml_bin_extremum(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c3_x[2], real_T c3_y, real_T c3_extremum[2]);
static void c3_b_eml_bin_extremum(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c3_x, real_T c3_y[2], real_T c3_extremum[2]);
static void c3_b_eml_scalar_eg(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c3_eml_xgemm(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c3_A[48], real_T c3_B[3], real_T c3_C[16], real_T c3_b_C[16]);
static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_j_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_GroundModel_bus_io(void *chartInstanceVoid, void
  *c3_pData);
static uint8_T c3_k_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_DDA2D_OSU3Dv2, const char_T
  *c3_identifier);
static uint8_T c3_l_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_eml_xgemm(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c3_A[48], real_T c3_B[3], real_T c3_C[16]);
static void init_dsm_address_info(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_DDA2D_OSU3Dv2 = 0U;
}

static void initialize_params_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_DDA2D_OSU3Dv2
  (SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_DDA2D_OSU3Dv2
  (SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  int32_T c3_i0;
  real_T c3_u[3];
  const mxArray *c3_b_y = NULL;
  int32_T c3_i1;
  real_T c3_b_u[2];
  const mxArray *c3_c_y = NULL;
  int32_T c3_i2;
  real_T c3_c_u[16];
  const mxArray *c3_d_y = NULL;
  uint8_T c3_hoistedGlobal;
  uint8_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(4, 1), false);
  for (c3_i0 = 0; c3_i0 < 3; c3_i0++) {
    c3_u[c3_i0] = (*chartInstance->c3_GRF)[c3_i0];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  for (c3_i1 = 0; c3_i1 < 2; c3_i1++) {
    c3_b_u[c3_i1] = (*chartInstance->c3_dd)[c3_i1];
  }

  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", c3_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  for (c3_i2 = 0; c3_i2 < 16; c3_i2++) {
    c3_c_u[c3_i2] = (*chartInstance->c3_tau)[c3_i2];
  }

  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", c3_c_u, 0, 0U, 1U, 0U, 1, 16), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_hoistedGlobal = chartInstance->c3_is_active_c3_DDA2D_OSU3Dv2;
  c3_d_u = c3_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_st)
{
  const mxArray *c3_u;
  real_T c3_dv0[3];
  int32_T c3_i3;
  real_T c3_dv1[2];
  int32_T c3_i4;
  real_T c3_dv2[16];
  int32_T c3_i5;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 0)),
                        "GRF", c3_dv0);
  for (c3_i3 = 0; c3_i3 < 3; c3_i3++) {
    (*chartInstance->c3_GRF)[c3_i3] = c3_dv0[c3_i3];
  }

  c3_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 1)), "dd",
                      c3_dv1);
  for (c3_i4 = 0; c3_i4 < 2; c3_i4++) {
    (*chartInstance->c3_dd)[c3_i4] = c3_dv1[c3_i4];
  }

  c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 2)),
                        "tau", c3_dv2);
  for (c3_i5 = 0; c3_i5 < 16; c3_i5++) {
    (*chartInstance->c3_tau)[c3_i5] = c3_dv2[c3_i5];
  }

  chartInstance->c3_is_active_c3_DDA2D_OSU3Dv2 = c3_k_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
     "is_active_c3_DDA2D_OSU3Dv2");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_DDA2D_OSU3Dv2(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  int32_T c3_i6;
  int32_T c3_i7;
  real_T c3_b_pF[3];
  int32_T c3_i8;
  real_T c3_b_vF[3];
  int32_T c3_i9;
  real_T c3_b_J4[48];
  int32_T c3_i10;
  real_T c3_b_JRCol[144];
  int32_T c3_i11;
  real_T c3_b_FootPoints[3];
  c3_GroundModelParamsBus c3_b_GroundModel;
  int32_T c3_i12;
  real_T c3_b_d[2];
  uint32_T c3_debug_family_var_map[14];
  real_T c3_F[3];
  real_T c3_J[48];
  real_T c3_nargin = 7.0;
  real_T c3_nargout = 3.0;
  real_T c3_b_GRF[3];
  real_T c3_b_tau[16];
  real_T c3_b_dd[2];
  int32_T c3_i13;
  real_T c3_c_d[2];
  int32_T c3_i14;
  real_T c3_c_vF[2];
  c3_GroundModelParamsBus c3_c_GroundModel;
  real_T c3_c_dd[2];
  real_T c3_b_F[3];
  int32_T c3_i15;
  int32_T c3_i16;
  int32_T c3_i17;
  real_T c3_a;
  int32_T c3_i18;
  int32_T c3_i19;
  int32_T c3_i20;
  int32_T c3_i21;
  real_T c3_b[48];
  int32_T c3_i22;
  real_T c3_b_a;
  int32_T c3_i23;
  int32_T c3_i24;
  int32_T c3_i25;
  int32_T c3_i26;
  real_T c3_b_b[48];
  int32_T c3_i27;
  real_T c3_c_a;
  int32_T c3_i28;
  int32_T c3_i29;
  int32_T c3_i30;
  int32_T c3_i31;
  real_T c3_c_b[48];
  int32_T c3_i32;
  int32_T c3_i33;
  int32_T c3_i34;
  int32_T c3_i35;
  int32_T c3_i36;
  int32_T c3_i37;
  real_T c3_d_a[48];
  int32_T c3_i38;
  int32_T c3_i39;
  int32_T c3_i40;
  real_T c3_dv3[16];
  int32_T c3_i41;
  real_T c3_e_a[48];
  int32_T c3_i42;
  real_T c3_c_F[3];
  int32_T c3_i43;
  int32_T c3_i44;
  int32_T c3_i45;
  int32_T c3_i46;
  int32_T c3_i47;
  int32_T c3_i48;
  int32_T c3_i49;
  int32_T c3_i50;
  int32_T c3_i51;
  int32_T c3_i52;
  int32_T c3_i53;
  int32_T c3_i54;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  for (c3_i6 = 0; c3_i6 < 3; c3_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_pF)[c3_i6], 0U);
  }

  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  for (c3_i7 = 0; c3_i7 < 3; c3_i7++) {
    c3_b_pF[c3_i7] = (*chartInstance->c3_pF)[c3_i7];
  }

  for (c3_i8 = 0; c3_i8 < 3; c3_i8++) {
    c3_b_vF[c3_i8] = (*chartInstance->c3_vF)[c3_i8];
  }

  for (c3_i9 = 0; c3_i9 < 48; c3_i9++) {
    c3_b_J4[c3_i9] = (*chartInstance->c3_J4)[c3_i9];
  }

  for (c3_i10 = 0; c3_i10 < 144; c3_i10++) {
    c3_b_JRCol[c3_i10] = (*chartInstance->c3_JRCol)[c3_i10];
  }

  for (c3_i11 = 0; c3_i11 < 3; c3_i11++) {
    c3_b_FootPoints[c3_i11] = (*chartInstance->c3_FootPoints)[c3_i11];
  }

  c3_b_GroundModel.n = *(real_T *)&((char_T *)chartInstance->c3_GroundModel)[0];
  c3_b_GroundModel.k = *(real_T *)&((char_T *)chartInstance->c3_GroundModel)[8];
  c3_b_GroundModel.sigma0 = *(real_T *)&((char_T *)chartInstance->c3_GroundModel)
    [16];
  c3_b_GroundModel.sigma1 = *(real_T *)&((char_T *)chartInstance->c3_GroundModel)
    [24];
  c3_b_GroundModel.alpha0 = *(real_T *)&((char_T *)chartInstance->c3_GroundModel)
    [32];
  c3_b_GroundModel.alpha2 = *(real_T *)&((char_T *)chartInstance->c3_GroundModel)
    [40];
  c3_b_GroundModel.alpha3 = *(real_T *)&((char_T *)chartInstance->c3_GroundModel)
    [48];
  c3_b_GroundModel.lambda_a = *(real_T *)&((char_T *)
    chartInstance->c3_GroundModel)[56];
  c3_b_GroundModel.lambda_b = *(real_T *)&((char_T *)
    chartInstance->c3_GroundModel)[64];
  c3_b_GroundModel.mu_s = *(real_T *)&((char_T *)chartInstance->c3_GroundModel)
    [72];
  c3_b_GroundModel.GRF_UpperLimit = *(real_T *)&((char_T *)
    chartInstance->c3_GroundModel)[80];
  c3_b_GroundModel.GRF_LowerLimit = *(real_T *)&((char_T *)
    chartInstance->c3_GroundModel)[88];
  for (c3_i12 = 0; c3_i12 < 2; c3_i12++) {
    c3_b_d[c3_i12] = (*chartInstance->c3_d)[c3_i12];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_F, 0U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_J, 1U, c3_g_sf_marshallOut,
    c3_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 2U, c3_h_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 3U, c3_h_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_b_pF, 4U, c3_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_b_vF, 5U, c3_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_b_J4, 6U, c3_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_b_JRCol, 7U, c3_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_b_FootPoints, 8U, c3_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_GroundModel, 9U, c3_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c3_b_d, 10U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_GRF, 11U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_tau, 12U, c3_b_sf_marshallOut,
    c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_dd, 13U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  for (c3_i13 = 0; c3_i13 < 2; c3_i13++) {
    c3_c_d[c3_i13] = c3_b_d[c3_i13];
  }

  for (c3_i14 = 0; c3_i14 < 2; c3_i14++) {
    c3_c_vF[c3_i14] = c3_b_vF[c3_i14];
  }

  c3_c_GroundModel = c3_b_GroundModel;
  c3_LuGreHertzian(chartInstance, c3_b_pF[2], c3_b_vF[2], c3_c_d, c3_c_vF,
                   &c3_c_GroundModel, c3_b_F, c3_c_dd);
  for (c3_i15 = 0; c3_i15 < 3; c3_i15++) {
    c3_F[c3_i15] = c3_b_F[c3_i15];
  }

  for (c3_i16 = 0; c3_i16 < 2; c3_i16++) {
    c3_b_dd[c3_i16] = c3_c_dd[c3_i16];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  for (c3_i17 = 0; c3_i17 < 3; c3_i17++) {
    c3_b_GRF[c3_i17] = c3_F[c3_i17];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_a = c3_b_FootPoints[0];
  c3_i18 = 0;
  c3_i19 = 0;
  for (c3_i20 = 0; c3_i20 < 16; c3_i20++) {
    for (c3_i21 = 0; c3_i21 < 3; c3_i21++) {
      c3_b[c3_i21 + c3_i18] = c3_b_JRCol[c3_i21 + c3_i19];
    }

    c3_i18 += 3;
    c3_i19 += 9;
  }

  for (c3_i22 = 0; c3_i22 < 48; c3_i22++) {
    c3_b[c3_i22] *= c3_a;
  }

  c3_b_a = c3_b_FootPoints[1];
  c3_i23 = 0;
  c3_i24 = 0;
  for (c3_i25 = 0; c3_i25 < 16; c3_i25++) {
    for (c3_i26 = 0; c3_i26 < 3; c3_i26++) {
      c3_b_b[c3_i26 + c3_i23] = c3_b_JRCol[(c3_i26 + c3_i24) + 3];
    }

    c3_i23 += 3;
    c3_i24 += 9;
  }

  for (c3_i27 = 0; c3_i27 < 48; c3_i27++) {
    c3_b_b[c3_i27] *= c3_b_a;
  }

  c3_c_a = c3_b_FootPoints[2];
  c3_i28 = 0;
  c3_i29 = 0;
  for (c3_i30 = 0; c3_i30 < 16; c3_i30++) {
    for (c3_i31 = 0; c3_i31 < 3; c3_i31++) {
      c3_c_b[c3_i31 + c3_i28] = c3_b_JRCol[(c3_i31 + c3_i29) + 6];
    }

    c3_i28 += 3;
    c3_i29 += 9;
  }

  for (c3_i32 = 0; c3_i32 < 48; c3_i32++) {
    c3_c_b[c3_i32] *= c3_c_a;
  }

  for (c3_i33 = 0; c3_i33 < 48; c3_i33++) {
    c3_J[c3_i33] = ((c3_b_J4[c3_i33] + c3_b[c3_i33]) + c3_b_b[c3_i33]) +
      c3_c_b[c3_i33];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_i34 = 0;
  for (c3_i35 = 0; c3_i35 < 3; c3_i35++) {
    c3_i36 = 0;
    for (c3_i37 = 0; c3_i37 < 16; c3_i37++) {
      c3_d_a[c3_i37 + c3_i34] = c3_J[c3_i36 + c3_i35];
      c3_i36 += 3;
    }

    c3_i34 += 16;
  }

  for (c3_i38 = 0; c3_i38 < 3; c3_i38++) {
    c3_b_F[c3_i38] = c3_b_GRF[c3_i38];
  }

  c3_b_eml_scalar_eg(chartInstance);
  c3_b_eml_scalar_eg(chartInstance);
  for (c3_i39 = 0; c3_i39 < 16; c3_i39++) {
    c3_b_tau[c3_i39] = 0.0;
  }

  for (c3_i40 = 0; c3_i40 < 16; c3_i40++) {
    c3_dv3[c3_i40] = 0.0;
  }

  for (c3_i41 = 0; c3_i41 < 48; c3_i41++) {
    c3_e_a[c3_i41] = c3_d_a[c3_i41];
  }

  for (c3_i42 = 0; c3_i42 < 3; c3_i42++) {
    c3_c_F[c3_i42] = c3_b_F[c3_i42];
  }

  c3_b_eml_xgemm(chartInstance, c3_e_a, c3_c_F, c3_dv3);
  for (c3_i43 = 0; c3_i43 < 16; c3_i43++) {
    c3_b_tau[c3_i43] = c3_dv3[c3_i43];
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -7);
  _SFD_SYMBOL_SCOPE_POP();
  for (c3_i44 = 0; c3_i44 < 3; c3_i44++) {
    (*chartInstance->c3_GRF)[c3_i44] = c3_b_GRF[c3_i44];
  }

  for (c3_i45 = 0; c3_i45 < 16; c3_i45++) {
    (*chartInstance->c3_tau)[c3_i45] = c3_b_tau[c3_i45];
  }

  for (c3_i46 = 0; c3_i46 < 2; c3_i46++) {
    (*chartInstance->c3_dd)[c3_i46] = c3_b_dd[c3_i46];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DDA2D_OSU3Dv2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c3_i47 = 0; c3_i47 < 3; c3_i47++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_GRF)[c3_i47], 1U);
  }

  for (c3_i48 = 0; c3_i48 < 16; c3_i48++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_tau)[c3_i48], 2U);
  }

  for (c3_i49 = 0; c3_i49 < 3; c3_i49++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_vF)[c3_i49], 3U);
  }

  for (c3_i50 = 0; c3_i50 < 48; c3_i50++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_J4)[c3_i50], 4U);
  }

  for (c3_i51 = 0; c3_i51 < 144; c3_i51++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_JRCol)[c3_i51], 5U);
  }

  for (c3_i52 = 0; c3_i52 < 3; c3_i52++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_FootPoints)[c3_i52], 6U);
  }

  for (c3_i53 = 0; c3_i53 < 2; c3_i53++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_d)[c3_i53], 8U);
  }

  for (c3_i54 = 0; c3_i54 < 2; c3_i54++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c3_dd)[c3_i54], 9U);
  }
}

static void mdl_start_c3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc3_DDA2D_OSU3Dv2(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c3_LuGreHertzian(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c3_zG, real_T c3_dzG, real_T c3_b_d[2], real_T c3_v[2],
  c3_GroundModelParamsBus *c3_b_GroundModel, real_T c3_F[3], real_T c3_b_dd[2])
{
  uint32_T c3_debug_family_var_map[11];
  real_T c3_Fn;
  real_T c3_mu[2];
  real_T c3_nargin = 5.0;
  real_T c3_nargout = 2.0;
  real_T c3_x;
  real_T c3_b_x;
  real_T c3_y;
  real_T c3_a;
  real_T c3_b;
  real_T c3_b_a;
  real_T c3_b_b;
  real_T c3_ak;
  real_T c3_bk;
  real_T c3_c_x;
  real_T c3_d_x;
  real_T c3_c_a;
  real_T c3_c_b;
  real_T c3_ar;
  real_T c3_br;
  real_T c3_b_y;
  real_T c3_e_x;
  real_T c3_f_x;
  real_T c3_c_y;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_j_x;
  real_T c3_d_y;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_varargin_1;
  real_T c3_varargin_2;
  real_T c3_b_varargin_2;
  real_T c3_varargin_3;
  real_T c3_m_x;
  real_T c3_e_y;
  real_T c3_n_x;
  real_T c3_f_y;
  real_T c3_xk;
  real_T c3_yk;
  real_T c3_o_x;
  real_T c3_g_y;
  real_T c3_minval;
  real_T c3_b_varargin_1;
  real_T c3_c_varargin_2;
  real_T c3_d_varargin_2;
  real_T c3_b_varargin_3;
  real_T c3_p_x;
  real_T c3_h_y;
  real_T c3_q_x;
  real_T c3_i_y;
  real_T c3_b_xk;
  real_T c3_b_yk;
  real_T c3_r_x;
  real_T c3_j_y;
  int32_T c3_i55;
  real_T c3_c_d[2];
  int32_T c3_i56;
  real_T c3_b_v[2];
  c3_GroundModelParamsBus c3_c_GroundModel;
  real_T c3_b_mu[2];
  real_T c3_c_dd[2];
  int32_T c3_i57;
  int32_T c3_i58;
  boolean_T c3_d_b;
  int32_T c3_i59;
  int32_T c3_i60;
  real_T c3_s_x;
  real_T c3_t_x;
  real_T c3_k_y;
  real_T c3_u_x;
  real_T c3_v_x;
  real_T c3_l_y;
  real_T c3_m_y[2];
  int32_T c3_i61;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c3_c_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_Fn, 0U, c3_h_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_mu, 1U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 2U, c3_h_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 3U, c3_h_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_zG, 4U, c3_h_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_dzG, 5U, c3_h_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_d, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_v, 7U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_GroundModel, 8U, c3_d_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_F, 9U, c3_c_sf_marshallOut,
    c3_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_dd, 10U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 5);
  c3_x = c3_zG;
  c3_b_x = c3_x;
  c3_y = muDoubleScalarAbs(c3_b_x);
  c3_a = c3_y;
  c3_b = c3_b_GroundModel->n;
  c3_b_a = c3_a;
  c3_b_b = c3_b;
  c3_eml_scalar_eg(chartInstance);
  c3_ak = c3_b_a;
  c3_bk = c3_b_b;
  if (c3_ak < 0.0) {
    c3_c_x = c3_bk;
    c3_d_x = c3_c_x;
    c3_d_x = muDoubleScalarFloor(c3_d_x);
    if (c3_d_x != c3_bk) {
      c3_eml_error(chartInstance);
    }
  }

  c3_c_a = c3_ak;
  c3_c_b = c3_bk;
  c3_eml_scalar_eg(chartInstance);
  c3_ar = c3_c_a;
  c3_br = c3_c_b;
  c3_b_y = muDoubleScalarPower(c3_ar, c3_br);
  c3_e_x = c3_zG;
  c3_f_x = c3_e_x;
  c3_c_y = muDoubleScalarAbs(c3_f_x);
  c3_g_x = c3_dzG;
  c3_h_x = c3_g_x;
  c3_h_x = muDoubleScalarSign(c3_h_x);
  c3_i_x = c3_dzG;
  c3_j_x = c3_i_x;
  c3_d_y = muDoubleScalarAbs(c3_j_x);
  c3_k_x = c3_d_y;
  c3_l_x = c3_k_x;
  if (c3_l_x < 0.0) {
    c3_b_eml_error(chartInstance);
  }

  c3_l_x = muDoubleScalarSqrt(c3_l_x);
  c3_Fn = c3_b_y * (c3_b_GroundModel->k - c3_b_GroundModel->lambda_a * c3_dzG) -
    c3_b_GroundModel->lambda_b * c3_c_y * c3_h_x * c3_l_x;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 6);
  c3_varargin_1 = c3_Fn;
  c3_varargin_2 = c3_b_GroundModel->GRF_UpperLimit;
  c3_b_varargin_2 = c3_varargin_1;
  c3_varargin_3 = c3_varargin_2;
  c3_m_x = c3_b_varargin_2;
  c3_e_y = c3_varargin_3;
  c3_n_x = c3_m_x;
  c3_f_y = c3_e_y;
  c3_eml_scalar_eg(chartInstance);
  c3_xk = c3_n_x;
  c3_yk = c3_f_y;
  c3_o_x = c3_xk;
  c3_g_y = c3_yk;
  c3_eml_scalar_eg(chartInstance);
  c3_minval = muDoubleScalarMin(c3_o_x, c3_g_y);
  c3_b_varargin_1 = c3_b_GroundModel->GRF_LowerLimit;
  c3_c_varargin_2 = c3_minval;
  c3_d_varargin_2 = c3_b_varargin_1;
  c3_b_varargin_3 = c3_c_varargin_2;
  c3_p_x = c3_d_varargin_2;
  c3_h_y = c3_b_varargin_3;
  c3_q_x = c3_p_x;
  c3_i_y = c3_h_y;
  c3_eml_scalar_eg(chartInstance);
  c3_b_xk = c3_q_x;
  c3_b_yk = c3_i_y;
  c3_r_x = c3_b_xk;
  c3_j_y = c3_b_yk;
  c3_eml_scalar_eg(chartInstance);
  c3_Fn = muDoubleScalarMax(c3_r_x, c3_j_y);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 7);
  c3_Fn *= (real_T)(c3_zG < 0.0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 10);
  for (c3_i55 = 0; c3_i55 < 2; c3_i55++) {
    c3_c_d[c3_i55] = c3_b_d[c3_i55];
  }

  for (c3_i56 = 0; c3_i56 < 2; c3_i56++) {
    c3_b_v[c3_i56] = c3_v[c3_i56];
  }

  c3_c_GroundModel = *c3_b_GroundModel;
  c3_LuGre(chartInstance, c3_c_d, c3_b_v, &c3_c_GroundModel, c3_c_dd, c3_b_mu);
  for (c3_i57 = 0; c3_i57 < 2; c3_i57++) {
    c3_b_dd[c3_i57] = c3_c_dd[c3_i57];
  }

  for (c3_i58 = 0; c3_i58 < 2; c3_i58++) {
    c3_mu[c3_i58] = c3_b_mu[c3_i58];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 11);
  c3_d_b = (c3_zG < 0.0);
  for (c3_i59 = 0; c3_i59 < 2; c3_i59++) {
    c3_c_dd[c3_i59] = (real_T)c3_d_b;
  }

  for (c3_i60 = 0; c3_i60 < 2; c3_i60++) {
    c3_b_dd[c3_i60] *= c3_c_dd[c3_i60];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 12);
  c3_s_x = c3_Fn;
  c3_t_x = c3_s_x;
  c3_k_y = muDoubleScalarAbs(c3_t_x);
  c3_u_x = c3_Fn;
  c3_v_x = c3_u_x;
  c3_l_y = muDoubleScalarAbs(c3_v_x);
  c3_m_y[0] = c3_k_y;
  c3_m_y[1] = c3_l_y;
  for (c3_i61 = 0; c3_i61 < 2; c3_i61++) {
    c3_F[c3_i61] = c3_mu[c3_i61] * c3_m_y[c3_i61];
  }

  c3_F[2] = c3_Fn;
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -12);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c3_LuGre(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
                     c3_b_d[2], real_T c3_v[2], c3_GroundModelParamsBus
                     *c3_b_GroundModel, real_T c3_b_dd[2], real_T c3_mu[2])
{
  uint32_T c3_debug_family_var_map[7];
  real_T c3_nargin = 3.0;
  real_T c3_nargout = 2.0;
  int32_T c3_i62;
  real_T c3_b_v[2];
  real_T c3_a[2];
  real_T c3_b;
  int32_T c3_i63;
  real_T c3_B;
  real_T c3_y;
  real_T c3_b_y;
  real_T c3_c_y;
  int32_T c3_i64;
  int32_T c3_i65;
  real_T c3_b_a;
  int32_T c3_i66;
  int32_T c3_i67;
  real_T c3_c_a;
  int32_T c3_i68;
  real_T c3_b_b[2];
  int32_T c3_i69;
  real_T c3_d_a;
  int32_T c3_i70;
  real_T c3_c_b[2];
  int32_T c3_i71;
  int32_T c3_i72;
  real_T c3_x[2];
  int32_T c3_k;
  real_T c3_b_k;
  real_T c3_b_x;
  real_T c3_c_x;
  real_T c3_e_a;
  int32_T c3_i73;
  int32_T c3_i74;
  real_T c3_c_v[2];
  real_T c3_d_x[2];
  int32_T c3_c_k;
  real_T c3_d_k;
  int32_T c3_e_k;
  real_T c3_e_x;
  real_T c3_f_x;
  int32_T c3_i75;
  real_T c3_A;
  real_T c3_g_x;
  real_T c3_h_x;
  real_T c3_i_x;
  real_T c3_d_y;
  real_T c3_b_A;
  real_T c3_j_x;
  real_T c3_k_x;
  real_T c3_l_x;
  real_T c3_e_y;
  int32_T c3_i76;
  real_T c3_varargin_2;
  real_T c3_varargin_3;
  real_T c3_f_y;
  int32_T c3_i77;
  real_T c3_f_a[2];
  real_T c3_varargin_1;
  real_T c3_b_varargin_2;
  real_T c3_m_x;
  int32_T c3_i78;
  real_T c3_d_b[2];
  real_T c3_dv4[2];
  int32_T c3_i79;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c3_b_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 0U, c3_h_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 1U, c3_h_sf_marshallOut,
    c3_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_d, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_v, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_GroundModel, 4U, c3_d_sf_marshallOut,
    c3_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_b_dd, 5U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c3_mu, 6U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 20);
  for (c3_i62 = 0; c3_i62 < 2; c3_i62++) {
    c3_b_v[c3_i62] = c3_v[c3_i62];
  }

  c3_abs(chartInstance, c3_b_v, c3_a);
  c3_b = c3_b_GroundModel->sigma0;
  for (c3_i63 = 0; c3_i63 < 2; c3_i63++) {
    c3_a[c3_i63] *= c3_b;
  }

  c3_B = c3_b_GroundModel->alpha0;
  c3_y = c3_B;
  c3_b_y = c3_y;
  c3_c_y = c3_b_y;
  for (c3_i64 = 0; c3_i64 < 2; c3_i64++) {
    c3_a[c3_i64] /= c3_c_y;
  }

  for (c3_i65 = 0; c3_i65 < 2; c3_i65++) {
    c3_b_dd[c3_i65] = c3_v[c3_i65] - c3_a[c3_i65] * c3_b_d[c3_i65];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 21);
  c3_b_a = c3_b_GroundModel->sigma0;
  for (c3_i66 = 0; c3_i66 < 2; c3_i66++) {
    c3_a[c3_i66] = c3_b_d[c3_i66];
  }

  for (c3_i67 = 0; c3_i67 < 2; c3_i67++) {
    c3_a[c3_i67] *= c3_b_a;
  }

  c3_c_a = c3_b_GroundModel->sigma1;
  for (c3_i68 = 0; c3_i68 < 2; c3_i68++) {
    c3_b_b[c3_i68] = c3_b_dd[c3_i68];
  }

  for (c3_i69 = 0; c3_i69 < 2; c3_i69++) {
    c3_b_b[c3_i69] *= c3_c_a;
  }

  c3_d_a = c3_b_GroundModel->alpha2;
  for (c3_i70 = 0; c3_i70 < 2; c3_i70++) {
    c3_c_b[c3_i70] = c3_v[c3_i70];
  }

  for (c3_i71 = 0; c3_i71 < 2; c3_i71++) {
    c3_c_b[c3_i71] *= c3_d_a;
  }

  for (c3_i72 = 0; c3_i72 < 2; c3_i72++) {
    c3_x[c3_i72] = c3_v[c3_i72];
  }

  for (c3_k = 0; c3_k < 2; c3_k++) {
    c3_b_k = 1.0 + (real_T)c3_k;
    c3_b_x = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c3_b_k), 1, 2, 1, 0) - 1];
    c3_c_x = c3_b_x;
    c3_c_x = muDoubleScalarSign(c3_c_x);
    c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c3_b_k),
      1, 2, 1, 0) - 1] = c3_c_x;
  }

  c3_e_a = c3_b_GroundModel->alpha3;
  for (c3_i73 = 0; c3_i73 < 2; c3_i73++) {
    c3_x[c3_i73] *= c3_e_a;
  }

  for (c3_i74 = 0; c3_i74 < 2; c3_i74++) {
    c3_c_v[c3_i74] = c3_v[c3_i74];
  }

  c3_abs(chartInstance, c3_c_v, c3_d_x);
  for (c3_c_k = 0; c3_c_k < 2; c3_c_k++) {
    c3_d_k = 1.0 + (real_T)c3_c_k;
    if (c3_d_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          c3_d_k), 1, 2, 1, 0) - 1] < 0.0) {
      c3_b_eml_error(chartInstance);
    }
  }

  for (c3_e_k = 0; c3_e_k < 2; c3_e_k++) {
    c3_d_k = 1.0 + (real_T)c3_e_k;
    c3_e_x = c3_d_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", c3_d_k), 1, 2, 1, 0) - 1];
    c3_f_x = c3_e_x;
    c3_f_x = muDoubleScalarSqrt(c3_f_x);
    c3_d_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c3_d_k), 1, 2, 1, 0) - 1] = c3_f_x;
  }

  for (c3_i75 = 0; c3_i75 < 2; c3_i75++) {
    c3_mu[c3_i75] = -(((c3_a[c3_i75] + c3_b_b[c3_i75]) + c3_c_b[c3_i75]) +
                      c3_x[c3_i75] * c3_d_x[c3_i75]);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, 22);
  c3_A = -c3_b_GroundModel->mu_s;
  c3_g_x = c3_A;
  c3_h_x = c3_g_x;
  c3_i_x = c3_h_x;
  c3_d_y = c3_i_x / 1.4142135623730951;
  c3_b_A = c3_b_GroundModel->mu_s;
  c3_j_x = c3_b_A;
  c3_k_x = c3_j_x;
  c3_l_x = c3_k_x;
  c3_e_y = c3_l_x / 1.4142135623730951;
  for (c3_i76 = 0; c3_i76 < 2; c3_i76++) {
    c3_a[c3_i76] = c3_mu[c3_i76];
  }

  c3_varargin_2 = c3_e_y;
  c3_varargin_3 = c3_varargin_2;
  c3_f_y = c3_varargin_3;
  for (c3_i77 = 0; c3_i77 < 2; c3_i77++) {
    c3_f_a[c3_i77] = c3_a[c3_i77];
  }

  c3_eml_bin_extremum(chartInstance, c3_f_a, c3_f_y, c3_b_b);
  c3_varargin_1 = c3_d_y;
  c3_b_varargin_2 = c3_varargin_1;
  c3_m_x = c3_b_varargin_2;
  for (c3_i78 = 0; c3_i78 < 2; c3_i78++) {
    c3_d_b[c3_i78] = c3_b_b[c3_i78];
  }

  c3_b_eml_bin_extremum(chartInstance, c3_m_x, c3_d_b, c3_dv4);
  for (c3_i79 = 0; c3_i79 < 2; c3_i79++) {
    c3_mu[c3_i79] = c3_dv4[c3_i79];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c3_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c3_chartNumber, c3_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Sims\\Model\\LuGreHertzian.m"));
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i80;
  real_T c3_b_inData[2];
  int32_T c3_i81;
  real_T c3_u[2];
  const mxArray *c3_y = NULL;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i80 = 0; c3_i80 < 2; c3_i80++) {
    c3_b_inData[c3_i80] = (*(real_T (*)[2])c3_inData)[c3_i80];
  }

  for (c3_i81 = 0; c3_i81 < 2; c3_i81++) {
    c3_u[c3_i81] = c3_b_inData[c3_i81];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  const mxArray *c3_b_dd, const char_T *c3_identifier, real_T c3_y[2])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dd), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dd);
}

static void c3_b_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[2])
{
  real_T c3_dv5[2];
  int32_T c3_i82;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv5, 1, 0, 0U, 1, 0U, 1, 2);
  for (c3_i82 = 0; c3_i82 < 2; c3_i82++) {
    c3_y[c3_i82] = c3_dv5[c3_i82];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_dd;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[2];
  int32_T c3_i83;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_b_dd = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_dd), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_dd);
  for (c3_i83 = 0; c3_i83 < 2; c3_i83++) {
    (*(real_T (*)[2])c3_outData)[c3_i83] = c3_y[c3_i83];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i84;
  real_T c3_b_inData[16];
  int32_T c3_i85;
  real_T c3_u[16];
  const mxArray *c3_y = NULL;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i84 = 0; c3_i84 < 16; c3_i84++) {
    c3_b_inData[c3_i84] = (*(real_T (*)[16])c3_inData)[c3_i84];
  }

  for (c3_i85 = 0; c3_i85 < 16; c3_i85++) {
    c3_u[c3_i85] = c3_b_inData[c3_i85];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 16), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_c_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_b_tau, const char_T *c3_identifier, real_T
  c3_y[16])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tau), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_tau);
}

static void c3_d_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[16])
{
  real_T c3_dv6[16];
  int32_T c3_i86;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv6, 1, 0, 0U, 1, 0U, 1, 16);
  for (c3_i86 = 0; c3_i86 < 16; c3_i86++) {
    c3_y[c3_i86] = c3_dv6[c3_i86];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_tau;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[16];
  int32_T c3_i87;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_b_tau = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_tau), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_tau);
  for (c3_i87 = 0; c3_i87 < 16; c3_i87++) {
    (*(real_T (*)[16])c3_outData)[c3_i87] = c3_y[c3_i87];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i88;
  real_T c3_b_inData[3];
  int32_T c3_i89;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i88 = 0; c3_i88 < 3; c3_i88++) {
    c3_b_inData[c3_i88] = (*(real_T (*)[3])c3_inData)[c3_i88];
  }

  for (c3_i89 = 0; c3_i89 < 3; c3_i89++) {
    c3_u[c3_i89] = c3_b_inData[c3_i89];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static void c3_e_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_b_GRF, const char_T *c3_identifier, real_T
  c3_y[3])
{
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_GRF), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_GRF);
}

static void c3_f_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[3])
{
  real_T c3_dv7[3];
  int32_T c3_i90;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv7, 1, 0, 0U, 1, 0U, 1, 3);
  for (c3_i90 = 0; c3_i90 < 3; c3_i90++) {
    c3_y[c3_i90] = c3_dv7[c3_i90];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_GRF;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[3];
  int32_T c3_i91;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_b_GRF = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_GRF), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_b_GRF);
  for (c3_i91 = 0; c3_i91 < 3; c3_i91++) {
    (*(real_T (*)[3])c3_outData)[c3_i91] = c3_y[c3_i91];
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_d_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  c3_GroundModelParamsBus c3_u;
  const mxArray *c3_y = NULL;
  real_T c3_b_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_c_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_d_u;
  const mxArray *c3_d_y = NULL;
  real_T c3_e_u;
  const mxArray *c3_e_y = NULL;
  real_T c3_f_u;
  const mxArray *c3_f_y = NULL;
  real_T c3_g_u;
  const mxArray *c3_g_y = NULL;
  real_T c3_h_u;
  const mxArray *c3_h_y = NULL;
  real_T c3_i_u;
  const mxArray *c3_i_y = NULL;
  real_T c3_j_u;
  const mxArray *c3_j_y = NULL;
  real_T c3_k_u;
  const mxArray *c3_k_y = NULL;
  real_T c3_l_u;
  const mxArray *c3_l_y = NULL;
  real_T c3_m_u;
  const mxArray *c3_m_y = NULL;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(c3_GroundModelParamsBus *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c3_b_u = c3_u.n;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_b_y, "n", "n", 0);
  c3_c_u = c3_u.k;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_c_y, "k", "k", 0);
  c3_d_u = c3_u.sigma0;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_d_y, "sigma0", "sigma0", 0);
  c3_e_u = c3_u.sigma1;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_e_y, "sigma1", "sigma1", 0);
  c3_f_u = c3_u.alpha0;
  c3_f_y = NULL;
  sf_mex_assign(&c3_f_y, sf_mex_create("y", &c3_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_f_y, "alpha0", "alpha0", 0);
  c3_g_u = c3_u.alpha2;
  c3_g_y = NULL;
  sf_mex_assign(&c3_g_y, sf_mex_create("y", &c3_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_g_y, "alpha2", "alpha2", 0);
  c3_h_u = c3_u.alpha3;
  c3_h_y = NULL;
  sf_mex_assign(&c3_h_y, sf_mex_create("y", &c3_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_h_y, "alpha3", "alpha3", 0);
  c3_i_u = c3_u.lambda_a;
  c3_i_y = NULL;
  sf_mex_assign(&c3_i_y, sf_mex_create("y", &c3_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_i_y, "lambda_a", "lambda_a", 0);
  c3_j_u = c3_u.lambda_b;
  c3_j_y = NULL;
  sf_mex_assign(&c3_j_y, sf_mex_create("y", &c3_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_j_y, "lambda_b", "lambda_b", 0);
  c3_k_u = c3_u.mu_s;
  c3_k_y = NULL;
  sf_mex_assign(&c3_k_y, sf_mex_create("y", &c3_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_k_y, "mu_s", "mu_s", 0);
  c3_l_u = c3_u.GRF_UpperLimit;
  c3_l_y = NULL;
  sf_mex_assign(&c3_l_y, sf_mex_create("y", &c3_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_l_y, "GRF_UpperLimit", "GRF_UpperLimit", 0);
  c3_m_u = c3_u.GRF_LowerLimit;
  c3_m_y = NULL;
  sf_mex_assign(&c3_m_y, sf_mex_create("y", &c3_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c3_y, c3_m_y, "GRF_LowerLimit", "GRF_LowerLimit", 0);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_e_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i92;
  real_T c3_b_inData[3];
  int32_T c3_i93;
  real_T c3_u[3];
  const mxArray *c3_y = NULL;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  for (c3_i92 = 0; c3_i92 < 3; c3_i92++) {
    c3_b_inData[c3_i92] = (*(real_T (*)[3])c3_inData)[c3_i92];
  }

  for (c3_i93 = 0; c3_i93 < 3; c3_i93++) {
    c3_u[c3_i93] = c3_b_inData[c3_i93];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 1), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_f_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i94;
  int32_T c3_i95;
  int32_T c3_i96;
  real_T c3_b_inData[144];
  int32_T c3_i97;
  int32_T c3_i98;
  int32_T c3_i99;
  real_T c3_u[144];
  const mxArray *c3_y = NULL;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i94 = 0;
  for (c3_i95 = 0; c3_i95 < 16; c3_i95++) {
    for (c3_i96 = 0; c3_i96 < 9; c3_i96++) {
      c3_b_inData[c3_i96 + c3_i94] = (*(real_T (*)[144])c3_inData)[c3_i96 +
        c3_i94];
    }

    c3_i94 += 9;
  }

  c3_i97 = 0;
  for (c3_i98 = 0; c3_i98 < 16; c3_i98++) {
    for (c3_i99 = 0; c3_i99 < 9; c3_i99++) {
      c3_u[c3_i99 + c3_i97] = c3_b_inData[c3_i99 + c3_i97];
    }

    c3_i97 += 9;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 9, 16), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_g_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_i100;
  int32_T c3_i101;
  int32_T c3_i102;
  real_T c3_b_inData[48];
  int32_T c3_i103;
  int32_T c3_i104;
  int32_T c3_i105;
  real_T c3_u[48];
  const mxArray *c3_y = NULL;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_i100 = 0;
  for (c3_i101 = 0; c3_i101 < 16; c3_i101++) {
    for (c3_i102 = 0; c3_i102 < 3; c3_i102++) {
      c3_b_inData[c3_i102 + c3_i100] = (*(real_T (*)[48])c3_inData)[c3_i102 +
        c3_i100];
    }

    c3_i100 += 3;
  }

  c3_i103 = 0;
  for (c3_i104 = 0; c3_i104 < 16; c3_i104++) {
    for (c3_i105 = 0; c3_i105 < 3; c3_i105++) {
      c3_u[c3_i105 + c3_i103] = c3_b_inData[c3_i105 + c3_i103];
    }

    c3_i103 += 3;
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 0, 0U, 1U, 0U, 2, 3, 16), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static const mxArray *c3_h_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_g_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d0, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_nargout;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_nargout = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_nargout), &c3_thisId);
  sf_mex_destroy(&c3_nargout);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_h_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  real_T c3_y[48])
{
  real_T c3_dv8[48];
  int32_T c3_i106;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), c3_dv8, 1, 0, 0U, 1, 0U, 2, 3, 16);
  for (c3_i106 = 0; c3_i106 < 48; c3_i106++) {
    c3_y[c3_i106] = c3_dv8[c3_i106];
  }

  sf_mex_destroy(&c3_u);
}

static void c3_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_J;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y[48];
  int32_T c3_i107;
  int32_T c3_i108;
  int32_T c3_i109;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_J = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_J), &c3_thisId, c3_y);
  sf_mex_destroy(&c3_J);
  c3_i107 = 0;
  for (c3_i108 = 0; c3_i108 < 16; c3_i108++) {
    for (c3_i109 = 0; c3_i109 < 3; c3_i109++) {
      (*(real_T (*)[48])c3_outData)[c3_i109 + c3_i107] = c3_y[c3_i109 + c3_i107];
    }

    c3_i107 += 3;
  }

  sf_mex_destroy(&c3_mxArrayInData);
}

static void c3_i_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId,
  c3_GroundModelParamsBus *c3_y)
{
  emlrtMsgIdentifier c3_thisId;
  static const char * c3_fieldNames[12] = { "n", "k", "sigma0", "sigma1",
    "alpha0", "alpha2", "alpha3", "lambda_a", "lambda_b", "mu_s",
    "GRF_UpperLimit", "GRF_LowerLimit" };

  c3_thisId.fParent = c3_parentId;
  sf_mex_check_struct(c3_parentId, c3_u, 12, c3_fieldNames, 0U, NULL);
  c3_thisId.fIdentifier = "n";
  c3_y->n = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u,
    "n", "n", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "k";
  c3_y->k = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c3_u,
    "k", "k", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "sigma0";
  c3_y->sigma0 = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c3_u, "sigma0", "sigma0", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "sigma1";
  c3_y->sigma1 = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c3_u, "sigma1", "sigma1", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "alpha0";
  c3_y->alpha0 = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c3_u, "alpha0", "alpha0", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "alpha2";
  c3_y->alpha2 = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c3_u, "alpha2", "alpha2", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "alpha3";
  c3_y->alpha3 = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c3_u, "alpha3", "alpha3", 0)),
    &c3_thisId);
  c3_thisId.fIdentifier = "lambda_a";
  c3_y->lambda_a = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_u, "lambda_a", "lambda_a", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "lambda_b";
  c3_y->lambda_b = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_u, "lambda_b", "lambda_b", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "mu_s";
  c3_y->mu_s = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c3_u, "mu_s", "mu_s", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "GRF_UpperLimit";
  c3_y->GRF_UpperLimit = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_u, "GRF_UpperLimit", "GRF_UpperLimit", 0)), &c3_thisId);
  c3_thisId.fIdentifier = "GRF_LowerLimit";
  c3_y->GRF_LowerLimit = c3_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c3_u, "GRF_LowerLimit", "GRF_LowerLimit", 0)), &c3_thisId);
  sf_mex_destroy(&c3_u);
}

static void c3_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_GroundModel;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  c3_GroundModelParamsBus c3_y;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_b_GroundModel = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_GroundModel), &c3_thisId,
                        &c3_y);
  sf_mex_destroy(&c3_b_GroundModel);
  *(c3_GroundModelParamsBus *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray *sf_c3_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 64, 1),
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
  const mxArray *c3_rhs11 = NULL;
  const mxArray *c3_lhs11 = NULL;
  const mxArray *c3_rhs12 = NULL;
  const mxArray *c3_lhs12 = NULL;
  const mxArray *c3_rhs13 = NULL;
  const mxArray *c3_lhs13 = NULL;
  const mxArray *c3_rhs14 = NULL;
  const mxArray *c3_lhs14 = NULL;
  const mxArray *c3_rhs15 = NULL;
  const mxArray *c3_lhs15 = NULL;
  const mxArray *c3_rhs16 = NULL;
  const mxArray *c3_lhs16 = NULL;
  const mxArray *c3_rhs17 = NULL;
  const mxArray *c3_lhs17 = NULL;
  const mxArray *c3_rhs18 = NULL;
  const mxArray *c3_lhs18 = NULL;
  const mxArray *c3_rhs19 = NULL;
  const mxArray *c3_lhs19 = NULL;
  const mxArray *c3_rhs20 = NULL;
  const mxArray *c3_lhs20 = NULL;
  const mxArray *c3_rhs21 = NULL;
  const mxArray *c3_lhs21 = NULL;
  const mxArray *c3_rhs22 = NULL;
  const mxArray *c3_lhs22 = NULL;
  const mxArray *c3_rhs23 = NULL;
  const mxArray *c3_lhs23 = NULL;
  const mxArray *c3_rhs24 = NULL;
  const mxArray *c3_lhs24 = NULL;
  const mxArray *c3_rhs25 = NULL;
  const mxArray *c3_lhs25 = NULL;
  const mxArray *c3_rhs26 = NULL;
  const mxArray *c3_lhs26 = NULL;
  const mxArray *c3_rhs27 = NULL;
  const mxArray *c3_lhs27 = NULL;
  const mxArray *c3_rhs28 = NULL;
  const mxArray *c3_lhs28 = NULL;
  const mxArray *c3_rhs29 = NULL;
  const mxArray *c3_lhs29 = NULL;
  const mxArray *c3_rhs30 = NULL;
  const mxArray *c3_lhs30 = NULL;
  const mxArray *c3_rhs31 = NULL;
  const mxArray *c3_lhs31 = NULL;
  const mxArray *c3_rhs32 = NULL;
  const mxArray *c3_lhs32 = NULL;
  const mxArray *c3_rhs33 = NULL;
  const mxArray *c3_lhs33 = NULL;
  const mxArray *c3_rhs34 = NULL;
  const mxArray *c3_lhs34 = NULL;
  const mxArray *c3_rhs35 = NULL;
  const mxArray *c3_lhs35 = NULL;
  const mxArray *c3_rhs36 = NULL;
  const mxArray *c3_lhs36 = NULL;
  const mxArray *c3_rhs37 = NULL;
  const mxArray *c3_lhs37 = NULL;
  const mxArray *c3_rhs38 = NULL;
  const mxArray *c3_lhs38 = NULL;
  const mxArray *c3_rhs39 = NULL;
  const mxArray *c3_lhs39 = NULL;
  const mxArray *c3_rhs40 = NULL;
  const mxArray *c3_lhs40 = NULL;
  const mxArray *c3_rhs41 = NULL;
  const mxArray *c3_lhs41 = NULL;
  const mxArray *c3_rhs42 = NULL;
  const mxArray *c3_lhs42 = NULL;
  const mxArray *c3_rhs43 = NULL;
  const mxArray *c3_lhs43 = NULL;
  const mxArray *c3_rhs44 = NULL;
  const mxArray *c3_lhs44 = NULL;
  const mxArray *c3_rhs45 = NULL;
  const mxArray *c3_lhs45 = NULL;
  const mxArray *c3_rhs46 = NULL;
  const mxArray *c3_lhs46 = NULL;
  const mxArray *c3_rhs47 = NULL;
  const mxArray *c3_lhs47 = NULL;
  const mxArray *c3_rhs48 = NULL;
  const mxArray *c3_lhs48 = NULL;
  const mxArray *c3_rhs49 = NULL;
  const mxArray *c3_lhs49 = NULL;
  const mxArray *c3_rhs50 = NULL;
  const mxArray *c3_lhs50 = NULL;
  const mxArray *c3_rhs51 = NULL;
  const mxArray *c3_lhs51 = NULL;
  const mxArray *c3_rhs52 = NULL;
  const mxArray *c3_lhs52 = NULL;
  const mxArray *c3_rhs53 = NULL;
  const mxArray *c3_lhs53 = NULL;
  const mxArray *c3_rhs54 = NULL;
  const mxArray *c3_lhs54 = NULL;
  const mxArray *c3_rhs55 = NULL;
  const mxArray *c3_lhs55 = NULL;
  const mxArray *c3_rhs56 = NULL;
  const mxArray *c3_lhs56 = NULL;
  const mxArray *c3_rhs57 = NULL;
  const mxArray *c3_lhs57 = NULL;
  const mxArray *c3_rhs58 = NULL;
  const mxArray *c3_lhs58 = NULL;
  const mxArray *c3_rhs59 = NULL;
  const mxArray *c3_lhs59 = NULL;
  const mxArray *c3_rhs60 = NULL;
  const mxArray *c3_lhs60 = NULL;
  const mxArray *c3_rhs61 = NULL;
  const mxArray *c3_lhs61 = NULL;
  const mxArray *c3_rhs62 = NULL;
  const mxArray *c3_lhs62 = NULL;
  const mxArray *c3_rhs63 = NULL;
  const mxArray *c3_lhs63 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("LuGreHertzian"), "name",
                  "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1444269963U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("abs"), "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
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
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("power"), "name", "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395346506U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
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
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
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
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("floor"), "name", "name", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
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
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c3_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c3_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_error"), "name", "name",
                  13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343851958U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c3_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c3_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("sign"), "name", "name", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c3_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c3_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_sign"), "name",
                  "name", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1356563094U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c3_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m"),
                  "context", "context", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("sqrt"), "name", "name", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343851986U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c3_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_error"), "name", "name",
                  19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343851958U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c3_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286840338U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c3_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("min"), "name", "name", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c3_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c3_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c3_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c3_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c3_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c3_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c3_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("max"), "name", "name", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c3_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c3_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m!LuGre"),
                  "context", "context", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("abs"), "name", "name", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c3_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m!LuGre"),
                  "context", "context", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c3_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c3_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m!LuGre"),
                  "context", "context", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mrdivide"), "name", "name", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c3_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c3_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rdivide"), "name", "name", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c3_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c3_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c3_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_div"), "name", "name", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c3_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c3_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m!LuGre"),
                  "context", "context", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("sign"), "name", "name", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c3_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m!LuGre"),
                  "context", "context", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("sqrt"), "name", "name", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1343851986U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c3_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m!LuGre"),
                  "context", "context", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("min"), "name", "name", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c3_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c3_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isfi"), "name", "name", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c3_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c3_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("intmax"), "name", "name", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c3_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c3_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("intmin"), "name", "name", 48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c3_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c3_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m!LuGre"),
                  "context", "context", 50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("max"), "name", "name", 50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c3_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/LuGreHertzian.m"),
                  "context", "context", 51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c3_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c3_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c3_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c3_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 55);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 55);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c3_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 56);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  56);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c3_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 57);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c3_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 58);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c3_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 59);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 59);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c3_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 60);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 60);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c3_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 61);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 61);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c3_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 62);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 62);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c3_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 63);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.refblas.xgemm"),
                  "name", "name", 63);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c3_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs63), "lhs", "lhs",
                  63);
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
  sf_mex_destroy(&c3_rhs11);
  sf_mex_destroy(&c3_lhs11);
  sf_mex_destroy(&c3_rhs12);
  sf_mex_destroy(&c3_lhs12);
  sf_mex_destroy(&c3_rhs13);
  sf_mex_destroy(&c3_lhs13);
  sf_mex_destroy(&c3_rhs14);
  sf_mex_destroy(&c3_lhs14);
  sf_mex_destroy(&c3_rhs15);
  sf_mex_destroy(&c3_lhs15);
  sf_mex_destroy(&c3_rhs16);
  sf_mex_destroy(&c3_lhs16);
  sf_mex_destroy(&c3_rhs17);
  sf_mex_destroy(&c3_lhs17);
  sf_mex_destroy(&c3_rhs18);
  sf_mex_destroy(&c3_lhs18);
  sf_mex_destroy(&c3_rhs19);
  sf_mex_destroy(&c3_lhs19);
  sf_mex_destroy(&c3_rhs20);
  sf_mex_destroy(&c3_lhs20);
  sf_mex_destroy(&c3_rhs21);
  sf_mex_destroy(&c3_lhs21);
  sf_mex_destroy(&c3_rhs22);
  sf_mex_destroy(&c3_lhs22);
  sf_mex_destroy(&c3_rhs23);
  sf_mex_destroy(&c3_lhs23);
  sf_mex_destroy(&c3_rhs24);
  sf_mex_destroy(&c3_lhs24);
  sf_mex_destroy(&c3_rhs25);
  sf_mex_destroy(&c3_lhs25);
  sf_mex_destroy(&c3_rhs26);
  sf_mex_destroy(&c3_lhs26);
  sf_mex_destroy(&c3_rhs27);
  sf_mex_destroy(&c3_lhs27);
  sf_mex_destroy(&c3_rhs28);
  sf_mex_destroy(&c3_lhs28);
  sf_mex_destroy(&c3_rhs29);
  sf_mex_destroy(&c3_lhs29);
  sf_mex_destroy(&c3_rhs30);
  sf_mex_destroy(&c3_lhs30);
  sf_mex_destroy(&c3_rhs31);
  sf_mex_destroy(&c3_lhs31);
  sf_mex_destroy(&c3_rhs32);
  sf_mex_destroy(&c3_lhs32);
  sf_mex_destroy(&c3_rhs33);
  sf_mex_destroy(&c3_lhs33);
  sf_mex_destroy(&c3_rhs34);
  sf_mex_destroy(&c3_lhs34);
  sf_mex_destroy(&c3_rhs35);
  sf_mex_destroy(&c3_lhs35);
  sf_mex_destroy(&c3_rhs36);
  sf_mex_destroy(&c3_lhs36);
  sf_mex_destroy(&c3_rhs37);
  sf_mex_destroy(&c3_lhs37);
  sf_mex_destroy(&c3_rhs38);
  sf_mex_destroy(&c3_lhs38);
  sf_mex_destroy(&c3_rhs39);
  sf_mex_destroy(&c3_lhs39);
  sf_mex_destroy(&c3_rhs40);
  sf_mex_destroy(&c3_lhs40);
  sf_mex_destroy(&c3_rhs41);
  sf_mex_destroy(&c3_lhs41);
  sf_mex_destroy(&c3_rhs42);
  sf_mex_destroy(&c3_lhs42);
  sf_mex_destroy(&c3_rhs43);
  sf_mex_destroy(&c3_lhs43);
  sf_mex_destroy(&c3_rhs44);
  sf_mex_destroy(&c3_lhs44);
  sf_mex_destroy(&c3_rhs45);
  sf_mex_destroy(&c3_lhs45);
  sf_mex_destroy(&c3_rhs46);
  sf_mex_destroy(&c3_lhs46);
  sf_mex_destroy(&c3_rhs47);
  sf_mex_destroy(&c3_lhs47);
  sf_mex_destroy(&c3_rhs48);
  sf_mex_destroy(&c3_lhs48);
  sf_mex_destroy(&c3_rhs49);
  sf_mex_destroy(&c3_lhs49);
  sf_mex_destroy(&c3_rhs50);
  sf_mex_destroy(&c3_lhs50);
  sf_mex_destroy(&c3_rhs51);
  sf_mex_destroy(&c3_lhs51);
  sf_mex_destroy(&c3_rhs52);
  sf_mex_destroy(&c3_lhs52);
  sf_mex_destroy(&c3_rhs53);
  sf_mex_destroy(&c3_lhs53);
  sf_mex_destroy(&c3_rhs54);
  sf_mex_destroy(&c3_lhs54);
  sf_mex_destroy(&c3_rhs55);
  sf_mex_destroy(&c3_lhs55);
  sf_mex_destroy(&c3_rhs56);
  sf_mex_destroy(&c3_lhs56);
  sf_mex_destroy(&c3_rhs57);
  sf_mex_destroy(&c3_lhs57);
  sf_mex_destroy(&c3_rhs58);
  sf_mex_destroy(&c3_lhs58);
  sf_mex_destroy(&c3_rhs59);
  sf_mex_destroy(&c3_lhs59);
  sf_mex_destroy(&c3_rhs60);
  sf_mex_destroy(&c3_lhs60);
  sf_mex_destroy(&c3_rhs61);
  sf_mex_destroy(&c3_lhs61);
  sf_mex_destroy(&c3_rhs62);
  sf_mex_destroy(&c3_lhs62);
  sf_mex_destroy(&c3_rhs63);
  sf_mex_destroy(&c3_lhs63);
}

static const mxArray *c3_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static void c3_eml_scalar_eg(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_error(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  int32_T c3_i110;
  static char_T c3_cv0[31] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'p', 'o', 'w', 'e', 'r', '_', 'd', 'o', 'm', 'a', 'i',
    'n', 'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[31];
  const mxArray *c3_y = NULL;
  (void)chartInstance;
  for (c3_i110 = 0; c3_i110 < 31; c3_i110++) {
    c3_u[c3_i110] = c3_cv0[c3_i110];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 31), false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c3_y));
}

static void c3_b_eml_error(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  int32_T c3_i111;
  static char_T c3_cv1[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c3_u[30];
  const mxArray *c3_y = NULL;
  int32_T c3_i112;
  static char_T c3_cv2[4] = { 's', 'q', 'r', 't' };

  char_T c3_b_u[4];
  const mxArray *c3_b_y = NULL;
  (void)chartInstance;
  for (c3_i111 = 0; c3_i111 < 30; c3_i111++) {
    c3_u[c3_i111] = c3_cv1[c3_i111];
  }

  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 10, 0U, 1U, 0U, 2, 1, 30), false);
  for (c3_i112 = 0; c3_i112 < 4; c3_i112++) {
    c3_b_u[c3_i112] = c3_cv2[c3_i112];
  }

  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", c3_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c3_y, 14, c3_b_y));
}

static void c3_abs(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c3_x
                   [2], real_T c3_y[2])
{
  int32_T c3_k;
  real_T c3_b_k;
  real_T c3_b_x;
  real_T c3_b_y;
  (void)chartInstance;
  for (c3_k = 0; c3_k < 2; c3_k++) {
    c3_b_k = 1.0 + (real_T)c3_k;
    c3_b_x = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c3_b_k), 1, 2, 1, 0) - 1];
    c3_b_y = muDoubleScalarAbs(c3_b_x);
    c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", c3_b_k),
      1, 2, 1, 0) - 1] = c3_b_y;
  }
}

static void c3_eml_bin_extremum(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c3_x[2], real_T c3_y, real_T c3_extremum[2])
{
  int32_T c3_k;
  int32_T c3_b_k;
  real_T c3_xk;
  real_T c3_yk;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_b_extremum;
  for (c3_k = 1; c3_k < 3; c3_k++) {
    c3_b_k = c3_k;
    c3_xk = c3_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c3_b_k), 1, 2, 1, 0) - 1];
    c3_yk = c3_y;
    c3_b_x = c3_xk;
    c3_b_y = c3_yk;
    c3_eml_scalar_eg(chartInstance);
    c3_b_extremum = muDoubleScalarMin(c3_b_x, c3_b_y);
    c3_extremum[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c3_b_k), 1, 2, 1, 0) - 1] = c3_b_extremum;
  }
}

static void c3_b_eml_bin_extremum(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c3_x, real_T c3_y[2], real_T c3_extremum[2])
{
  int32_T c3_k;
  int32_T c3_b_k;
  real_T c3_xk;
  real_T c3_yk;
  real_T c3_b_x;
  real_T c3_b_y;
  real_T c3_b_extremum;
  for (c3_k = 1; c3_k < 3; c3_k++) {
    c3_b_k = c3_k;
    c3_xk = c3_x;
    c3_yk = c3_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c3_b_k), 1, 2, 1, 0) - 1];
    c3_b_x = c3_xk;
    c3_b_y = c3_yk;
    c3_eml_scalar_eg(chartInstance);
    c3_b_extremum = muDoubleScalarMax(c3_b_x, c3_b_y);
    c3_extremum[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c3_b_k), 1, 2, 1, 0) - 1] = c3_b_extremum;
  }
}

static void c3_b_eml_scalar_eg(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c3_eml_xgemm(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c3_A[48], real_T c3_B[3], real_T c3_C[16], real_T c3_b_C[16])
{
  int32_T c3_i113;
  int32_T c3_i114;
  real_T c3_b_A[48];
  int32_T c3_i115;
  real_T c3_b_B[3];
  for (c3_i113 = 0; c3_i113 < 16; c3_i113++) {
    c3_b_C[c3_i113] = c3_C[c3_i113];
  }

  for (c3_i114 = 0; c3_i114 < 48; c3_i114++) {
    c3_b_A[c3_i114] = c3_A[c3_i114];
  }

  for (c3_i115 = 0; c3_i115 < 3; c3_i115++) {
    c3_b_B[c3_i115] = c3_B[c3_i115];
  }

  c3_b_eml_xgemm(chartInstance, c3_b_A, c3_b_B, c3_b_C);
}

static const mxArray *c3_i_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_j_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i116;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i116, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i116;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_GroundModel_bus_io(void *chartInstanceVoid, void
  *c3_pData)
{
  const mxArray *c3_mxVal = NULL;
  c3_GroundModelParamsBus c3_tmp;
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c3_mxVal = NULL;
  c3_tmp.n = *(real_T *)&((char_T *)(c3_GroundModelParamsBus *)c3_pData)[0];
  c3_tmp.k = *(real_T *)&((char_T *)(c3_GroundModelParamsBus *)c3_pData)[8];
  c3_tmp.sigma0 = *(real_T *)&((char_T *)(c3_GroundModelParamsBus *)c3_pData)[16];
  c3_tmp.sigma1 = *(real_T *)&((char_T *)(c3_GroundModelParamsBus *)c3_pData)[24];
  c3_tmp.alpha0 = *(real_T *)&((char_T *)(c3_GroundModelParamsBus *)c3_pData)[32];
  c3_tmp.alpha2 = *(real_T *)&((char_T *)(c3_GroundModelParamsBus *)c3_pData)[40];
  c3_tmp.alpha3 = *(real_T *)&((char_T *)(c3_GroundModelParamsBus *)c3_pData)[48];
  c3_tmp.lambda_a = *(real_T *)&((char_T *)(c3_GroundModelParamsBus *)c3_pData)
    [56];
  c3_tmp.lambda_b = *(real_T *)&((char_T *)(c3_GroundModelParamsBus *)c3_pData)
    [64];
  c3_tmp.mu_s = *(real_T *)&((char_T *)(c3_GroundModelParamsBus *)c3_pData)[72];
  c3_tmp.GRF_UpperLimit = *(real_T *)&((char_T *)(c3_GroundModelParamsBus *)
    c3_pData)[80];
  c3_tmp.GRF_LowerLimit = *(real_T *)&((char_T *)(c3_GroundModelParamsBus *)
    c3_pData)[88];
  sf_mex_assign(&c3_mxVal, c3_d_sf_marshallOut(chartInstance, &c3_tmp), false);
  return c3_mxVal;
}

static uint8_T c3_k_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_b_is_active_c3_DDA2D_OSU3Dv2, const char_T
  *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_l_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_DDA2D_OSU3Dv2), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_DDA2D_OSU3Dv2);
  return c3_y;
}

static uint8_T c3_l_emlrt_marshallIn(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_eml_xgemm(SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c3_A[48], real_T c3_B[3], real_T c3_C[16])
{
  int32_T c3_i117;
  int32_T c3_i118;
  int32_T c3_i119;
  (void)chartInstance;
  for (c3_i117 = 0; c3_i117 < 16; c3_i117++) {
    c3_C[c3_i117] = 0.0;
    c3_i118 = 0;
    for (c3_i119 = 0; c3_i119 < 3; c3_i119++) {
      c3_C[c3_i117] += c3_A[c3_i118 + c3_i117] * c3_B[c3_i119];
      c3_i118 += 16;
    }
  }
}

static void init_dsm_address_info(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc3_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c3_pF = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_GRF = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_tau = (real_T (*)[16])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_vF = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_J4 = (real_T (*)[48])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_JRCol = (real_T (*)[144])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_FootPoints = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c3_GroundModel = (c3_GroundModelParamsBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 5);
  chartInstance->c3_d = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c3_dd = (real_T (*)[2])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
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

void sf_c3_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2226207812U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3016060192U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(53683565U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(932351072U);
}

mxArray* sf_c3_DDA2D_OSU3Dv2_get_post_codegen_info(void);
mxArray *sf_c3_DDA2D_OSU3Dv2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("1CnjG2H1VJ51evOfceguAH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
      pr[1] = (double)(16);
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
      pr[0] = (double)(9);
      pr[1] = (double)(16);
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
      pr[0] = (double)(3);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(2);
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

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      pr[0] = (double)(16);
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
      pr[0] = (double)(2);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c3_DDA2D_OSU3Dv2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_DDA2D_OSU3Dv2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_DDA2D_OSU3Dv2_jit_fallback_info(void)
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

mxArray *sf_c3_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_DDA2D_OSU3Dv2_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c3_DDA2D_OSU3Dv2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[5],T\"GRF\",},{M[1],M[9],T\"dd\",},{M[1],M[10],T\"tau\",},{M[8],M[0],T\"is_active_c3_DDA2D_OSU3Dv2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_DDA2D_OSU3Dv2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DDA2D_OSU3Dv2MachineNumber_,
           3,
           1,
           1,
           0,
           10,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"pF");
          _SFD_SET_DATA_PROPS(1,2,0,1,"GRF");
          _SFD_SET_DATA_PROPS(2,2,0,1,"tau");
          _SFD_SET_DATA_PROPS(3,1,1,0,"vF");
          _SFD_SET_DATA_PROPS(4,1,1,0,"J4");
          _SFD_SET_DATA_PROPS(5,1,1,0,"JRCol");
          _SFD_SET_DATA_PROPS(6,1,1,0,"FootPoints");
          _SFD_SET_DATA_PROPS(7,1,1,0,"GroundModel");
          _SFD_SET_DATA_PROPS(8,1,1,0,"d");
          _SFD_SET_DATA_PROPS(9,2,0,1,"dd");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,324);
        _SFD_CV_INIT_SCRIPT(0,2,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"LuGreHertzian",0,-1,611);
        _SFD_CV_INIT_SCRIPT_FCN(0,1,"LuGre",613,-1,1209);

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_c_sf_marshallOut,(MexInFcnForType)
            c3_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 16;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_b_sf_marshallOut,(MexInFcnForType)
            c3_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 16;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 9;
          dimVector[1]= 16;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(7,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_GroundModel_bus_io,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)
            c3_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c3_pF);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c3_GRF);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c3_tau);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c3_vF);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c3_J4);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c3_JRCol);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c3_FootPoints);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c3_GroundModel);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c3_d);
        _SFD_SET_DATA_VALUE_PTR(9U, *chartInstance->c3_dd);
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
  return "jozVARIf7424X7eC4xzmRG";
}

static void sf_opaque_initialize_c3_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc3_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c3_DDA2D_OSU3Dv2((SFc3_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
  initialize_c3_DDA2D_OSU3Dv2((SFc3_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c3_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  enable_c3_DDA2D_OSU3Dv2((SFc3_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c3_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  disable_c3_DDA2D_OSU3Dv2((SFc3_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c3_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  sf_gateway_c3_DDA2D_OSU3Dv2((SFc3_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c3_DDA2D_OSU3Dv2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c3_DDA2D_OSU3Dv2((SFc3_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_DDA2D_OSU3Dv2(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c3_DDA2D_OSU3Dv2((SFc3_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c3_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DDA2D_OSU3Dv2_optimization_info();
    }

    finalize_c3_DDA2D_OSU3Dv2((SFc3_DDA2D_OSU3Dv2InstanceStruct*)
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
  initSimStructsc3_DDA2D_OSU3Dv2((SFc3_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_DDA2D_OSU3Dv2(SimStruct *S)
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
    initialize_params_c3_DDA2D_OSU3Dv2((SFc3_DDA2D_OSU3Dv2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DDA2D_OSU3Dv2_optimization_info();
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
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2081191329U));
  ssSetChecksum1(S,(1402938208U));
  ssSetChecksum2(S,(2153440824U));
  ssSetChecksum3(S,(1474970977U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c3_DDA2D_OSU3Dv2(SimStruct *S)
{
  SFc3_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_DDA2D_OSU3Dv2InstanceStruct *)utMalloc(sizeof
    (SFc3_DDA2D_OSU3Dv2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc3_DDA2D_OSU3Dv2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c3_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c3_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c3_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c3_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c3_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlStart = mdlStart_c3_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c3_DDA2D_OSU3Dv2;
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

void c3_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_DDA2D_OSU3Dv2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_DDA2D_OSU3Dv2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
