/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_DDA3D_sfun.h"
#include "c93_Walking01_DDA3D.h"
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
static const char * c93_debug_family_names[8] = { "dySet", "hSet", "h", "nargin",
  "nargout", "hAlphaSet", "dy", "HAlphaTwo" };

static const char * c93_b_debug_family_names[10] = { "minAbs", "AIdx",
  "HAlpha_hSet", "dxSet", "hSet", "nargin", "nargout", "hAlphaSet", "dx",
  "HAlpha" };

/* Function Declarations */
static void initialize_c93_Walking01_DDA3D(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initialize_params_c93_Walking01_DDA3D
  (SFc93_Walking01_DDA3DInstanceStruct *chartInstance);
static void enable_c93_Walking01_DDA3D(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void disable_c93_Walking01_DDA3D(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c93_update_debugger_state_c93_Walking01_DDA3D
  (SFc93_Walking01_DDA3DInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c93_Walking01_DDA3D
  (SFc93_Walking01_DDA3DInstanceStruct *chartInstance);
static void set_sim_state_c93_Walking01_DDA3D
  (SFc93_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c93_st);
static void finalize_c93_Walking01_DDA3D(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void sf_gateway_c93_Walking01_DDA3D(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void mdl_start_c93_Walking01_DDA3D(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initSimStructsc93_Walking01_DDA3D
  (SFc93_Walking01_DDA3DInstanceStruct *chartInstance);
static void c93_interpolateRoughGround(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, real_T c93_b_hAlphaSet[1080], real_T c93_dx, real_T
  c93_HAlpha[72]);
static void init_script_number_translation(uint32_T c93_machineNumber, uint32_T
  c93_chartNumber, uint32_T c93_instanceNumber);
static const mxArray *c93_sf_marshallOut(void *chartInstanceVoid, void
  *c93_inData);
static void c93_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_b_HAlphaTwo, const char_T *c93_identifier,
  real_T c93_y[72]);
static void c93_b_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId,
  real_T c93_y[72]);
static void c93_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c93_mxArrayInData, const char_T *c93_varName, void *c93_outData);
static const mxArray *c93_b_sf_marshallOut(void *chartInstanceVoid, void
  *c93_inData);
static const mxArray *c93_c_sf_marshallOut(void *chartInstanceVoid, void
  *c93_inData);
static real_T c93_c_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId);
static void c93_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c93_mxArrayInData, const char_T *c93_varName, void *c93_outData);
static const mxArray *c93_d_sf_marshallOut(void *chartInstanceVoid, void
  *c93_inData);
static void c93_d_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId,
  real_T c93_y[1080]);
static void c93_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c93_mxArrayInData, const char_T *c93_varName, void *c93_outData);
static const mxArray *c93_e_sf_marshallOut(void *chartInstanceVoid, void
  *c93_inData);
static void c93_e_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId,
  real_T c93_y[2]);
static void c93_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c93_mxArrayInData, const char_T *c93_varName, void *c93_outData);
static void c93_f_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId,
  real_T c93_y[15]);
static void c93_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c93_mxArrayInData, const char_T *c93_varName, void *c93_outData);
static void c93_info_helper(const mxArray **c93_info);
static const mxArray *c93_emlrt_marshallOut(const char * c93_u);
static const mxArray *c93_b_emlrt_marshallOut(const uint32_T c93_u);
static void c93_b_info_helper(const mxArray **c93_info);
static void c93_eml_switch_helper(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c93_eml_sort(SFc93_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c93_x[15], real_T c93_y[15], int32_T c93_idx[15]);
static void c93_eml_sort_idx(SFc93_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c93_x[15], int32_T c93_idx[15], real_T c93_y[15]);
static void c93_check_forloop_overflow_error(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, boolean_T c93_overflow);
static const mxArray *c93_f_sf_marshallOut(void *chartInstanceVoid, void
  *c93_inData);
static int32_T c93_g_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId);
static void c93_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c93_mxArrayInData, const char_T *c93_varName, void *c93_outData);
static uint8_T c93_h_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_b_is_active_c93_Walking01_DDA3D, const
  char_T *c93_identifier);
static uint8_T c93_i_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId);
static void init_dsm_address_info(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c93_Walking01_DDA3D(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c93_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c93_is_active_c93_Walking01_DDA3D = 0U;
}

static void initialize_params_c93_Walking01_DDA3D
  (SFc93_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c93_Walking01_DDA3D(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c93_Walking01_DDA3D(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c93_update_debugger_state_c93_Walking01_DDA3D
  (SFc93_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c93_Walking01_DDA3D
  (SFc93_Walking01_DDA3DInstanceStruct *chartInstance)
{
  const mxArray *c93_st;
  const mxArray *c93_y = NULL;
  int32_T c93_i0;
  real_T c93_u[72];
  const mxArray *c93_b_y = NULL;
  uint8_T c93_hoistedGlobal;
  uint8_T c93_b_u;
  const mxArray *c93_c_y = NULL;
  c93_st = NULL;
  c93_st = NULL;
  c93_y = NULL;
  sf_mex_assign(&c93_y, sf_mex_createcellmatrix(2, 1), false);
  for (c93_i0 = 0; c93_i0 < 72; c93_i0++) {
    c93_u[c93_i0] = (*chartInstance->c93_HAlphaTwo)[c93_i0];
  }

  c93_b_y = NULL;
  sf_mex_assign(&c93_b_y, sf_mex_create("y", c93_u, 0, 0U, 1U, 0U, 2, 12, 6),
                false);
  sf_mex_setcell(c93_y, 0, c93_b_y);
  c93_hoistedGlobal = chartInstance->c93_is_active_c93_Walking01_DDA3D;
  c93_b_u = c93_hoistedGlobal;
  c93_c_y = NULL;
  sf_mex_assign(&c93_c_y, sf_mex_create("y", &c93_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c93_y, 1, c93_c_y);
  sf_mex_assign(&c93_st, c93_y, false);
  return c93_st;
}

static void set_sim_state_c93_Walking01_DDA3D
  (SFc93_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c93_st)
{
  const mxArray *c93_u;
  real_T c93_dv0[72];
  int32_T c93_i1;
  chartInstance->c93_doneDoubleBufferReInit = true;
  c93_u = sf_mex_dup(c93_st);
  c93_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c93_u, 0)),
                       "HAlphaTwo", c93_dv0);
  for (c93_i1 = 0; c93_i1 < 72; c93_i1++) {
    (*chartInstance->c93_HAlphaTwo)[c93_i1] = c93_dv0[c93_i1];
  }

  chartInstance->c93_is_active_c93_Walking01_DDA3D = c93_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c93_u, 1)),
     "is_active_c93_Walking01_DDA3D");
  sf_mex_destroy(&c93_u);
  c93_update_debugger_state_c93_Walking01_DDA3D(chartInstance);
  sf_mex_destroy(&c93_st);
}

static void finalize_c93_Walking01_DDA3D(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c93_Walking01_DDA3D(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  int32_T c93_i2;
  real_T c93_hoistedGlobal;
  int32_T c93_i3;
  real_T c93_b_hAlphaSet[1080];
  real_T c93_b_dy;
  uint32_T c93_debug_family_var_map[8];
  real_T c93_dySet[15];
  real_T c93_hSet;
  real_T c93_h;
  real_T c93_nargin = 2.0;
  real_T c93_nargout = 1.0;
  real_T c93_b_HAlphaTwo[72];
  int32_T c93_i4;
  static real_T c93_dv1[15] = { -0.7, -0.6, -0.49999999999999994,
    -0.39999999999999991, -0.29999999999999993, -0.19999999999999996,
    -0.099999999999999867, 0.0, 0.099999999999999867, 0.19999999999999996,
    0.29999999999999993, 0.39999999999999991, 0.49999999999999994, 0.6, 0.7 };

  int32_T c93_i5;
  real_T c93_c_hAlphaSet[1080];
  real_T c93_dv2[72];
  int32_T c93_i6;
  int32_T c93_i7;
  real_T c93_d_hAlphaSet[1080];
  real_T c93_dv3[72];
  int32_T c93_i8;
  int32_T c93_i9;
  int32_T c93_i10;
  static int32_T c93_iv0[12] = { 7, 6, 9, 8, 11, 10, 1, 0, 3, 2, 5, 4 };

  real_T c93_c_HAlphaTwo[72];
  int32_T c93_i11;
  int32_T c93_i12;
  int32_T c93_i13;
  int32_T c93_i14;
  int32_T c93_i15;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 25U, chartInstance->c93_sfEvent);
  for (c93_i2 = 0; c93_i2 < 1080; c93_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c93_hAlphaSet)[c93_i2], 0U);
  }

  chartInstance->c93_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 25U, chartInstance->c93_sfEvent);
  c93_hoistedGlobal = *chartInstance->c93_dy;
  for (c93_i3 = 0; c93_i3 < 1080; c93_i3++) {
    c93_b_hAlphaSet[c93_i3] = (*chartInstance->c93_hAlphaSet)[c93_i3];
  }

  c93_b_dy = c93_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c93_debug_family_names,
    c93_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(c93_dySet, 0U, c93_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c93_hSet, 1U, c93_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c93_h, 2U, c93_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c93_nargin, 3U, c93_b_sf_marshallOut,
    c93_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c93_nargout, 4U, c93_b_sf_marshallOut,
    c93_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c93_b_hAlphaSet, 5U, c93_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c93_b_dy, 6U, c93_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c93_b_HAlphaTwo, 7U, c93_sf_marshallOut,
    c93_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c93_sfEvent, 4);
  for (c93_i4 = 0; c93_i4 < 15; c93_i4++) {
    c93_dySet[c93_i4] = c93_dv1[c93_i4];
  }

  _SFD_EML_CALL(0U, chartInstance->c93_sfEvent, 5);
  c93_hSet = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c93_sfEvent, 6);
  c93_h = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c93_sfEvent, 8);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c93_b_dy, 0.0, -1, 5U,
        c93_b_dy >= 0.0))) {
    _SFD_EML_CALL(0U, chartInstance->c93_sfEvent, 9);
    for (c93_i5 = 0; c93_i5 < 1080; c93_i5++) {
      c93_c_hAlphaSet[c93_i5] = c93_b_hAlphaSet[c93_i5];
    }

    c93_interpolateRoughGround(chartInstance, c93_c_hAlphaSet, c93_b_dy, c93_dv2);
    for (c93_i6 = 0; c93_i6 < 72; c93_i6++) {
      c93_b_HAlphaTwo[c93_i6] = c93_dv2[c93_i6];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c93_sfEvent, 12);
    c93_b_dy = -c93_b_dy;
    _SFD_EML_CALL(0U, chartInstance->c93_sfEvent, 13);
    for (c93_i7 = 0; c93_i7 < 1080; c93_i7++) {
      c93_d_hAlphaSet[c93_i7] = c93_b_hAlphaSet[c93_i7];
    }

    c93_interpolateRoughGround(chartInstance, c93_d_hAlphaSet, c93_b_dy, c93_dv3);
    for (c93_i8 = 0; c93_i8 < 72; c93_i8++) {
      c93_b_HAlphaTwo[c93_i8] = c93_dv3[c93_i8];
    }

    _SFD_EML_CALL(0U, chartInstance->c93_sfEvent, 14);
    for (c93_i9 = 0; c93_i9 < 6; c93_i9++) {
      for (c93_i10 = 0; c93_i10 < 12; c93_i10++) {
        c93_c_HAlphaTwo[c93_i10 + 12 * c93_i9] = c93_b_HAlphaTwo[c93_iv0[c93_i10]
          + 12 * c93_i9];
      }
    }

    c93_i11 = 0;
    for (c93_i12 = 0; c93_i12 < 6; c93_i12++) {
      for (c93_i13 = 0; c93_i13 < 12; c93_i13++) {
        c93_b_HAlphaTwo[c93_i13 + c93_i11] = c93_c_HAlphaTwo[c93_i13 + c93_i11];
      }

      c93_i11 += 12;
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c93_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  for (c93_i14 = 0; c93_i14 < 72; c93_i14++) {
    (*chartInstance->c93_HAlphaTwo)[c93_i14] = c93_b_HAlphaTwo[c93_i14];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 25U, chartInstance->c93_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_DDA3DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c93_i15 = 0; c93_i15 < 72; c93_i15++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c93_HAlphaTwo)[c93_i15], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c93_dy, 2U);
}

static void mdl_start_c93_Walking01_DDA3D(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc93_Walking01_DDA3D
  (SFc93_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c93_interpolateRoughGround(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, real_T c93_b_hAlphaSet[1080], real_T c93_dx, real_T
  c93_HAlpha[72])
{
  uint32_T c93_debug_family_var_map[10];
  real_T c93_minAbs[15];
  real_T c93_AIdx[15];
  real_T c93_HAlpha_hSet[72];
  real_T c93_b_AIdx[2];
  real_T c93_dxSet[15];
  real_T c93_hSet;
  real_T c93_nargin = 5.0;
  real_T c93_nargout = 1.0;
  int32_T c93_i16;
  static real_T c93_dv4[15] = { -0.7, -0.6, -0.49999999999999994,
    -0.39999999999999991, -0.29999999999999993, -0.19999999999999996,
    -0.099999999999999867, 0.0, 0.099999999999999867, 0.19999999999999996,
    0.29999999999999993, 0.39999999999999991, 0.49999999999999994, 0.6, 0.7 };

  int32_T c93_i17;
  real_T c93_x[15];
  int32_T c93_k;
  real_T c93_b_k;
  real_T c93_b_x;
  real_T c93_y;
  int32_T c93_i18;
  int32_T c93_i19;
  real_T c93_c_x[15];
  int32_T c93_iidx[15];
  real_T c93_b_y[15];
  int32_T c93_i20;
  int32_T c93_i21;
  int32_T c93_i22;
  int32_T c93_c_AIdx;
  int32_T c93_i23;
  int32_T c93_i24;
  real_T c93_a[72];
  real_T c93_b;
  int32_T c93_i25;
  int32_T c93_d_AIdx;
  int32_T c93_i26;
  int32_T c93_i27;
  real_T c93_b_a[72];
  real_T c93_b_b;
  int32_T c93_i28;
  int32_T c93_i29;
  real_T c93_B;
  real_T c93_c_y;
  real_T c93_d_y;
  real_T c93_e_y;
  int32_T c93_i30;
  int32_T c93_i31;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 11U, c93_b_debug_family_names,
    c93_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c93_minAbs, 0U, c93_d_sf_marshallOut,
    c93_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c93_AIdx, MAX_uint32_T,
    c93_d_sf_marshallOut, c93_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c93_HAlpha_hSet, 2U, c93_sf_marshallOut,
    c93_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c93_b_AIdx, MAX_uint32_T,
    c93_e_sf_marshallOut, c93_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c93_dxSet, 3U, c93_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c93_hSet, 4U, c93_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c93_nargin, 5U, c93_b_sf_marshallOut,
    c93_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c93_nargout, 6U, c93_b_sf_marshallOut,
    c93_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c93_b_hAlphaSet, 7U, c93_c_sf_marshallOut,
    c93_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c93_dx, 8U, c93_b_sf_marshallOut,
    c93_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c93_HAlpha, 9U, c93_sf_marshallOut,
    c93_sf_marshallIn);
  c93_hSet = 0.0;
  for (c93_i16 = 0; c93_i16 < 15; c93_i16++) {
    c93_dxSet[c93_i16] = c93_dv4[c93_i16];
  }

  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c93_sfEvent, 3);
  CV_SCRIPT_IF(0, 0, CV_RELATIONAL_EVAL(14U, 0U, 0, 15.0, 1.0, -1, 4U, 1));
  _SFD_SCRIPT_CALL(0U, chartInstance->c93_sfEvent, 4);
  for (c93_i17 = 0; c93_i17 < 15; c93_i17++) {
    c93_x[c93_i17] = c93_dxSet[c93_i17] - c93_dx;
  }

  for (c93_k = 0; c93_k < 15; c93_k++) {
    c93_b_k = 1.0 + (real_T)c93_k;
    c93_b_x = c93_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", c93_b_k), 1, 15, 1, 0) - 1];
    c93_y = muDoubleScalarAbs(c93_b_x);
    c93_minAbs[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      c93_b_k), 1, 15, 1, 0) - 1] = c93_y;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c93_sfEvent, 5);
  for (c93_i18 = 0; c93_i18 < 15; c93_i18++) {
    c93_x[c93_i18] = c93_minAbs[c93_i18];
  }

  for (c93_i19 = 0; c93_i19 < 15; c93_i19++) {
    c93_c_x[c93_i19] = c93_x[c93_i19];
  }

  c93_eml_sort(chartInstance, c93_c_x, c93_b_y, c93_iidx);
  for (c93_i20 = 0; c93_i20 < 15; c93_i20++) {
    c93_x[c93_i20] = (real_T)c93_iidx[c93_i20];
  }

  for (c93_i21 = 0; c93_i21 < 15; c93_i21++) {
    c93_AIdx[c93_i21] = c93_x[c93_i21];
  }

  _SFD_SYMBOL_SWITCH(1U, 1U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c93_sfEvent, 5);
  _SFD_SCRIPT_CALL(0U, chartInstance->c93_sfEvent, 6);
  for (c93_i22 = 0; c93_i22 < 2; c93_i22++) {
    c93_b_AIdx[c93_i22] = c93_AIdx[c93_i22];
  }

  _SFD_SYMBOL_SWITCH(1U, 3U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c93_sfEvent, 7);
  c93_c_AIdx = _SFD_EML_ARRAY_BOUNDS_CHECK("hAlphaSet", (int32_T)
    _SFD_INTEGER_CHECK("AIdx(1)", c93_b_AIdx[0]), 1, 15, 3, 0) - 1;
  for (c93_i23 = 0; c93_i23 < 6; c93_i23++) {
    for (c93_i24 = 0; c93_i24 < 12; c93_i24++) {
      c93_a[c93_i24 + 12 * c93_i23] = c93_b_hAlphaSet[(c93_i24 + 12 * c93_i23) +
        72 * c93_c_AIdx];
    }
  }

  c93_b = c93_dxSet[_SFD_EML_ARRAY_BOUNDS_CHECK("dxSet", (int32_T)
    _SFD_INTEGER_CHECK("AIdx(2)", c93_b_AIdx[1]), 1, 15, 1, 0) - 1] - c93_dx;
  for (c93_i25 = 0; c93_i25 < 72; c93_i25++) {
    c93_a[c93_i25] *= c93_b;
  }

  c93_d_AIdx = _SFD_EML_ARRAY_BOUNDS_CHECK("hAlphaSet", (int32_T)
    _SFD_INTEGER_CHECK("AIdx(2)", c93_b_AIdx[1]), 1, 15, 3, 0) - 1;
  for (c93_i26 = 0; c93_i26 < 6; c93_i26++) {
    for (c93_i27 = 0; c93_i27 < 12; c93_i27++) {
      c93_b_a[c93_i27 + 12 * c93_i26] = c93_b_hAlphaSet[(c93_i27 + 12 * c93_i26)
        + 72 * c93_d_AIdx];
    }
  }

  c93_b_b = c93_dx - c93_dxSet[_SFD_EML_ARRAY_BOUNDS_CHECK("dxSet", (int32_T)
    _SFD_INTEGER_CHECK("AIdx(1)", c93_b_AIdx[0]), 1, 15, 1, 0) - 1];
  for (c93_i28 = 0; c93_i28 < 72; c93_i28++) {
    c93_b_a[c93_i28] *= c93_b_b;
  }

  for (c93_i29 = 0; c93_i29 < 72; c93_i29++) {
    c93_a[c93_i29] += c93_b_a[c93_i29];
  }

  c93_B = c93_dxSet[_SFD_EML_ARRAY_BOUNDS_CHECK("dxSet", (int32_T)
    _SFD_INTEGER_CHECK("AIdx(2)", c93_b_AIdx[1]), 1, 15, 1, 0) - 1] -
    c93_dxSet[_SFD_EML_ARRAY_BOUNDS_CHECK("dxSet", (int32_T)_SFD_INTEGER_CHECK(
    "AIdx(1)", c93_b_AIdx[0]), 1, 15, 1, 0) - 1];
  c93_c_y = c93_B;
  c93_d_y = c93_c_y;
  c93_e_y = c93_d_y;
  for (c93_i30 = 0; c93_i30 < 72; c93_i30++) {
    c93_HAlpha_hSet[c93_i30] = c93_a[c93_i30] / c93_e_y;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c93_sfEvent, 13);
  CV_SCRIPT_IF(0, 1, CV_RELATIONAL_EVAL(14U, 0U, 1, 1.0, 1.0, -1, 4U, 0));
  _SFD_SCRIPT_CALL(0U, chartInstance->c93_sfEvent, 20);
  for (c93_i31 = 0; c93_i31 < 72; c93_i31++) {
    c93_HAlpha[c93_i31] = c93_HAlpha_hSet[c93_i31];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c93_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c93_machineNumber, uint32_T
  c93_chartNumber, uint32_T c93_instanceNumber)
{
  (void)c93_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c93_chartNumber, c93_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\TransitionExp\\DDAcontroller\\interpolateRoughGround.m"));
}

static const mxArray *c93_sf_marshallOut(void *chartInstanceVoid, void
  *c93_inData)
{
  const mxArray *c93_mxArrayOutData = NULL;
  int32_T c93_i32;
  int32_T c93_i33;
  int32_T c93_i34;
  real_T c93_b_inData[72];
  int32_T c93_i35;
  int32_T c93_i36;
  int32_T c93_i37;
  real_T c93_u[72];
  const mxArray *c93_y = NULL;
  SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c93_mxArrayOutData = NULL;
  c93_i32 = 0;
  for (c93_i33 = 0; c93_i33 < 6; c93_i33++) {
    for (c93_i34 = 0; c93_i34 < 12; c93_i34++) {
      c93_b_inData[c93_i34 + c93_i32] = (*(real_T (*)[72])c93_inData)[c93_i34 +
        c93_i32];
    }

    c93_i32 += 12;
  }

  c93_i35 = 0;
  for (c93_i36 = 0; c93_i36 < 6; c93_i36++) {
    for (c93_i37 = 0; c93_i37 < 12; c93_i37++) {
      c93_u[c93_i37 + c93_i35] = c93_b_inData[c93_i37 + c93_i35];
    }

    c93_i35 += 12;
  }

  c93_y = NULL;
  sf_mex_assign(&c93_y, sf_mex_create("y", c93_u, 0, 0U, 1U, 0U, 2, 12, 6),
                false);
  sf_mex_assign(&c93_mxArrayOutData, c93_y, false);
  return c93_mxArrayOutData;
}

static void c93_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_b_HAlphaTwo, const char_T *c93_identifier,
  real_T c93_y[72])
{
  emlrtMsgIdentifier c93_thisId;
  c93_thisId.fIdentifier = c93_identifier;
  c93_thisId.fParent = NULL;
  c93_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c93_b_HAlphaTwo), &c93_thisId,
    c93_y);
  sf_mex_destroy(&c93_b_HAlphaTwo);
}

static void c93_b_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId,
  real_T c93_y[72])
{
  real_T c93_dv5[72];
  int32_T c93_i38;
  (void)chartInstance;
  sf_mex_import(c93_parentId, sf_mex_dup(c93_u), c93_dv5, 1, 0, 0U, 1, 0U, 2, 12,
                6);
  for (c93_i38 = 0; c93_i38 < 72; c93_i38++) {
    c93_y[c93_i38] = c93_dv5[c93_i38];
  }

  sf_mex_destroy(&c93_u);
}

static void c93_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c93_mxArrayInData, const char_T *c93_varName, void *c93_outData)
{
  const mxArray *c93_b_HAlphaTwo;
  const char_T *c93_identifier;
  emlrtMsgIdentifier c93_thisId;
  real_T c93_y[72];
  int32_T c93_i39;
  int32_T c93_i40;
  int32_T c93_i41;
  SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c93_b_HAlphaTwo = sf_mex_dup(c93_mxArrayInData);
  c93_identifier = c93_varName;
  c93_thisId.fIdentifier = c93_identifier;
  c93_thisId.fParent = NULL;
  c93_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c93_b_HAlphaTwo), &c93_thisId,
    c93_y);
  sf_mex_destroy(&c93_b_HAlphaTwo);
  c93_i39 = 0;
  for (c93_i40 = 0; c93_i40 < 6; c93_i40++) {
    for (c93_i41 = 0; c93_i41 < 12; c93_i41++) {
      (*(real_T (*)[72])c93_outData)[c93_i41 + c93_i39] = c93_y[c93_i41 +
        c93_i39];
    }

    c93_i39 += 12;
  }

  sf_mex_destroy(&c93_mxArrayInData);
}

static const mxArray *c93_b_sf_marshallOut(void *chartInstanceVoid, void
  *c93_inData)
{
  const mxArray *c93_mxArrayOutData = NULL;
  real_T c93_u;
  const mxArray *c93_y = NULL;
  SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c93_mxArrayOutData = NULL;
  c93_u = *(real_T *)c93_inData;
  c93_y = NULL;
  sf_mex_assign(&c93_y, sf_mex_create("y", &c93_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c93_mxArrayOutData, c93_y, false);
  return c93_mxArrayOutData;
}

static const mxArray *c93_c_sf_marshallOut(void *chartInstanceVoid, void
  *c93_inData)
{
  const mxArray *c93_mxArrayOutData = NULL;
  int32_T c93_i42;
  int32_T c93_i43;
  int32_T c93_i44;
  int32_T c93_i45;
  int32_T c93_i46;
  real_T c93_b_inData[1080];
  int32_T c93_i47;
  int32_T c93_i48;
  int32_T c93_i49;
  int32_T c93_i50;
  int32_T c93_i51;
  real_T c93_u[1080];
  const mxArray *c93_y = NULL;
  SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c93_mxArrayOutData = NULL;
  c93_i42 = 0;
  for (c93_i43 = 0; c93_i43 < 15; c93_i43++) {
    c93_i44 = 0;
    for (c93_i45 = 0; c93_i45 < 6; c93_i45++) {
      for (c93_i46 = 0; c93_i46 < 12; c93_i46++) {
        c93_b_inData[(c93_i46 + c93_i44) + c93_i42] = (*(real_T (*)[1080])
          c93_inData)[(c93_i46 + c93_i44) + c93_i42];
      }

      c93_i44 += 12;
    }

    c93_i42 += 72;
  }

  c93_i47 = 0;
  for (c93_i48 = 0; c93_i48 < 15; c93_i48++) {
    c93_i49 = 0;
    for (c93_i50 = 0; c93_i50 < 6; c93_i50++) {
      for (c93_i51 = 0; c93_i51 < 12; c93_i51++) {
        c93_u[(c93_i51 + c93_i49) + c93_i47] = c93_b_inData[(c93_i51 + c93_i49)
          + c93_i47];
      }

      c93_i49 += 12;
    }

    c93_i47 += 72;
  }

  c93_y = NULL;
  sf_mex_assign(&c93_y, sf_mex_create("y", c93_u, 0, 0U, 1U, 0U, 3, 12, 6, 15),
                false);
  sf_mex_assign(&c93_mxArrayOutData, c93_y, false);
  return c93_mxArrayOutData;
}

static real_T c93_c_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId)
{
  real_T c93_y;
  real_T c93_d0;
  (void)chartInstance;
  sf_mex_import(c93_parentId, sf_mex_dup(c93_u), &c93_d0, 1, 0, 0U, 0, 0U, 0);
  c93_y = c93_d0;
  sf_mex_destroy(&c93_u);
  return c93_y;
}

static void c93_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c93_mxArrayInData, const char_T *c93_varName, void *c93_outData)
{
  const mxArray *c93_nargout;
  const char_T *c93_identifier;
  emlrtMsgIdentifier c93_thisId;
  real_T c93_y;
  SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c93_nargout = sf_mex_dup(c93_mxArrayInData);
  c93_identifier = c93_varName;
  c93_thisId.fIdentifier = c93_identifier;
  c93_thisId.fParent = NULL;
  c93_y = c93_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c93_nargout),
    &c93_thisId);
  sf_mex_destroy(&c93_nargout);
  *(real_T *)c93_outData = c93_y;
  sf_mex_destroy(&c93_mxArrayInData);
}

static const mxArray *c93_d_sf_marshallOut(void *chartInstanceVoid, void
  *c93_inData)
{
  const mxArray *c93_mxArrayOutData = NULL;
  int32_T c93_i52;
  real_T c93_b_inData[15];
  int32_T c93_i53;
  real_T c93_u[15];
  const mxArray *c93_y = NULL;
  SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c93_mxArrayOutData = NULL;
  for (c93_i52 = 0; c93_i52 < 15; c93_i52++) {
    c93_b_inData[c93_i52] = (*(real_T (*)[15])c93_inData)[c93_i52];
  }

  for (c93_i53 = 0; c93_i53 < 15; c93_i53++) {
    c93_u[c93_i53] = c93_b_inData[c93_i53];
  }

  c93_y = NULL;
  sf_mex_assign(&c93_y, sf_mex_create("y", c93_u, 0, 0U, 1U, 0U, 2, 1, 15),
                false);
  sf_mex_assign(&c93_mxArrayOutData, c93_y, false);
  return c93_mxArrayOutData;
}

static void c93_d_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId,
  real_T c93_y[1080])
{
  real_T c93_dv6[1080];
  int32_T c93_i54;
  (void)chartInstance;
  sf_mex_import(c93_parentId, sf_mex_dup(c93_u), c93_dv6, 1, 0, 0U, 1, 0U, 3, 12,
                6, 15);
  for (c93_i54 = 0; c93_i54 < 1080; c93_i54++) {
    c93_y[c93_i54] = c93_dv6[c93_i54];
  }

  sf_mex_destroy(&c93_u);
}

static void c93_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c93_mxArrayInData, const char_T *c93_varName, void *c93_outData)
{
  const mxArray *c93_b_hAlphaSet;
  const char_T *c93_identifier;
  emlrtMsgIdentifier c93_thisId;
  real_T c93_y[1080];
  int32_T c93_i55;
  int32_T c93_i56;
  int32_T c93_i57;
  int32_T c93_i58;
  int32_T c93_i59;
  SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c93_b_hAlphaSet = sf_mex_dup(c93_mxArrayInData);
  c93_identifier = c93_varName;
  c93_thisId.fIdentifier = c93_identifier;
  c93_thisId.fParent = NULL;
  c93_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c93_b_hAlphaSet), &c93_thisId,
    c93_y);
  sf_mex_destroy(&c93_b_hAlphaSet);
  c93_i55 = 0;
  for (c93_i56 = 0; c93_i56 < 15; c93_i56++) {
    c93_i57 = 0;
    for (c93_i58 = 0; c93_i58 < 6; c93_i58++) {
      for (c93_i59 = 0; c93_i59 < 12; c93_i59++) {
        (*(real_T (*)[1080])c93_outData)[(c93_i59 + c93_i57) + c93_i55] = c93_y
          [(c93_i59 + c93_i57) + c93_i55];
      }

      c93_i57 += 12;
    }

    c93_i55 += 72;
  }

  sf_mex_destroy(&c93_mxArrayInData);
}

static const mxArray *c93_e_sf_marshallOut(void *chartInstanceVoid, void
  *c93_inData)
{
  const mxArray *c93_mxArrayOutData = NULL;
  int32_T c93_i60;
  real_T c93_b_inData[2];
  int32_T c93_i61;
  real_T c93_u[2];
  const mxArray *c93_y = NULL;
  SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c93_mxArrayOutData = NULL;
  for (c93_i60 = 0; c93_i60 < 2; c93_i60++) {
    c93_b_inData[c93_i60] = (*(real_T (*)[2])c93_inData)[c93_i60];
  }

  for (c93_i61 = 0; c93_i61 < 2; c93_i61++) {
    c93_u[c93_i61] = c93_b_inData[c93_i61];
  }

  c93_y = NULL;
  sf_mex_assign(&c93_y, sf_mex_create("y", c93_u, 0, 0U, 1U, 0U, 2, 1, 2), false);
  sf_mex_assign(&c93_mxArrayOutData, c93_y, false);
  return c93_mxArrayOutData;
}

static void c93_e_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId,
  real_T c93_y[2])
{
  real_T c93_dv7[2];
  int32_T c93_i62;
  (void)chartInstance;
  sf_mex_import(c93_parentId, sf_mex_dup(c93_u), c93_dv7, 1, 0, 0U, 1, 0U, 2, 1,
                2);
  for (c93_i62 = 0; c93_i62 < 2; c93_i62++) {
    c93_y[c93_i62] = c93_dv7[c93_i62];
  }

  sf_mex_destroy(&c93_u);
}

static void c93_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c93_mxArrayInData, const char_T *c93_varName, void *c93_outData)
{
  const mxArray *c93_AIdx;
  const char_T *c93_identifier;
  emlrtMsgIdentifier c93_thisId;
  real_T c93_y[2];
  int32_T c93_i63;
  SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c93_AIdx = sf_mex_dup(c93_mxArrayInData);
  c93_identifier = c93_varName;
  c93_thisId.fIdentifier = c93_identifier;
  c93_thisId.fParent = NULL;
  c93_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c93_AIdx), &c93_thisId, c93_y);
  sf_mex_destroy(&c93_AIdx);
  for (c93_i63 = 0; c93_i63 < 2; c93_i63++) {
    (*(real_T (*)[2])c93_outData)[c93_i63] = c93_y[c93_i63];
  }

  sf_mex_destroy(&c93_mxArrayInData);
}

static void c93_f_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId,
  real_T c93_y[15])
{
  real_T c93_dv8[15];
  int32_T c93_i64;
  (void)chartInstance;
  sf_mex_import(c93_parentId, sf_mex_dup(c93_u), c93_dv8, 1, 0, 0U, 1, 0U, 2, 1,
                15);
  for (c93_i64 = 0; c93_i64 < 15; c93_i64++) {
    c93_y[c93_i64] = c93_dv8[c93_i64];
  }

  sf_mex_destroy(&c93_u);
}

static void c93_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c93_mxArrayInData, const char_T *c93_varName, void *c93_outData)
{
  const mxArray *c93_AIdx;
  const char_T *c93_identifier;
  emlrtMsgIdentifier c93_thisId;
  real_T c93_y[15];
  int32_T c93_i65;
  SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c93_AIdx = sf_mex_dup(c93_mxArrayInData);
  c93_identifier = c93_varName;
  c93_thisId.fIdentifier = c93_identifier;
  c93_thisId.fParent = NULL;
  c93_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c93_AIdx), &c93_thisId, c93_y);
  sf_mex_destroy(&c93_AIdx);
  for (c93_i65 = 0; c93_i65 < 15; c93_i65++) {
    (*(real_T (*)[15])c93_outData)[c93_i65] = c93_y[c93_i65];
  }

  sf_mex_destroy(&c93_mxArrayInData);
}

const mxArray *sf_c93_Walking01_DDA3D_get_eml_resolved_functions_info(void)
{
  const mxArray *c93_nameCaptureInfo = NULL;
  c93_nameCaptureInfo = NULL;
  sf_mex_assign(&c93_nameCaptureInfo, sf_mex_createstruct("structure", 2, 92, 1),
                false);
  c93_info_helper(&c93_nameCaptureInfo);
  c93_b_info_helper(&c93_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c93_nameCaptureInfo);
  return c93_nameCaptureInfo;
}

static void c93_info_helper(const mxArray **c93_info)
{
  const mxArray *c93_rhs0 = NULL;
  const mxArray *c93_lhs0 = NULL;
  const mxArray *c93_rhs1 = NULL;
  const mxArray *c93_lhs1 = NULL;
  const mxArray *c93_rhs2 = NULL;
  const mxArray *c93_lhs2 = NULL;
  const mxArray *c93_rhs3 = NULL;
  const mxArray *c93_lhs3 = NULL;
  const mxArray *c93_rhs4 = NULL;
  const mxArray *c93_lhs4 = NULL;
  const mxArray *c93_rhs5 = NULL;
  const mxArray *c93_lhs5 = NULL;
  const mxArray *c93_rhs6 = NULL;
  const mxArray *c93_lhs6 = NULL;
  const mxArray *c93_rhs7 = NULL;
  const mxArray *c93_lhs7 = NULL;
  const mxArray *c93_rhs8 = NULL;
  const mxArray *c93_lhs8 = NULL;
  const mxArray *c93_rhs9 = NULL;
  const mxArray *c93_lhs9 = NULL;
  const mxArray *c93_rhs10 = NULL;
  const mxArray *c93_lhs10 = NULL;
  const mxArray *c93_rhs11 = NULL;
  const mxArray *c93_lhs11 = NULL;
  const mxArray *c93_rhs12 = NULL;
  const mxArray *c93_lhs12 = NULL;
  const mxArray *c93_rhs13 = NULL;
  const mxArray *c93_lhs13 = NULL;
  const mxArray *c93_rhs14 = NULL;
  const mxArray *c93_lhs14 = NULL;
  const mxArray *c93_rhs15 = NULL;
  const mxArray *c93_lhs15 = NULL;
  const mxArray *c93_rhs16 = NULL;
  const mxArray *c93_lhs16 = NULL;
  const mxArray *c93_rhs17 = NULL;
  const mxArray *c93_lhs17 = NULL;
  const mxArray *c93_rhs18 = NULL;
  const mxArray *c93_lhs18 = NULL;
  const mxArray *c93_rhs19 = NULL;
  const mxArray *c93_lhs19 = NULL;
  const mxArray *c93_rhs20 = NULL;
  const mxArray *c93_lhs20 = NULL;
  const mxArray *c93_rhs21 = NULL;
  const mxArray *c93_lhs21 = NULL;
  const mxArray *c93_rhs22 = NULL;
  const mxArray *c93_lhs22 = NULL;
  const mxArray *c93_rhs23 = NULL;
  const mxArray *c93_lhs23 = NULL;
  const mxArray *c93_rhs24 = NULL;
  const mxArray *c93_lhs24 = NULL;
  const mxArray *c93_rhs25 = NULL;
  const mxArray *c93_lhs25 = NULL;
  const mxArray *c93_rhs26 = NULL;
  const mxArray *c93_lhs26 = NULL;
  const mxArray *c93_rhs27 = NULL;
  const mxArray *c93_lhs27 = NULL;
  const mxArray *c93_rhs28 = NULL;
  const mxArray *c93_lhs28 = NULL;
  const mxArray *c93_rhs29 = NULL;
  const mxArray *c93_lhs29 = NULL;
  const mxArray *c93_rhs30 = NULL;
  const mxArray *c93_lhs30 = NULL;
  const mxArray *c93_rhs31 = NULL;
  const mxArray *c93_lhs31 = NULL;
  const mxArray *c93_rhs32 = NULL;
  const mxArray *c93_lhs32 = NULL;
  const mxArray *c93_rhs33 = NULL;
  const mxArray *c93_lhs33 = NULL;
  const mxArray *c93_rhs34 = NULL;
  const mxArray *c93_lhs34 = NULL;
  const mxArray *c93_rhs35 = NULL;
  const mxArray *c93_lhs35 = NULL;
  const mxArray *c93_rhs36 = NULL;
  const mxArray *c93_lhs36 = NULL;
  const mxArray *c93_rhs37 = NULL;
  const mxArray *c93_lhs37 = NULL;
  const mxArray *c93_rhs38 = NULL;
  const mxArray *c93_lhs38 = NULL;
  const mxArray *c93_rhs39 = NULL;
  const mxArray *c93_lhs39 = NULL;
  const mxArray *c93_rhs40 = NULL;
  const mxArray *c93_lhs40 = NULL;
  const mxArray *c93_rhs41 = NULL;
  const mxArray *c93_lhs41 = NULL;
  const mxArray *c93_rhs42 = NULL;
  const mxArray *c93_lhs42 = NULL;
  const mxArray *c93_rhs43 = NULL;
  const mxArray *c93_lhs43 = NULL;
  const mxArray *c93_rhs44 = NULL;
  const mxArray *c93_lhs44 = NULL;
  const mxArray *c93_rhs45 = NULL;
  const mxArray *c93_lhs45 = NULL;
  const mxArray *c93_rhs46 = NULL;
  const mxArray *c93_lhs46 = NULL;
  const mxArray *c93_rhs47 = NULL;
  const mxArray *c93_lhs47 = NULL;
  const mxArray *c93_rhs48 = NULL;
  const mxArray *c93_lhs48 = NULL;
  const mxArray *c93_rhs49 = NULL;
  const mxArray *c93_lhs49 = NULL;
  const mxArray *c93_rhs50 = NULL;
  const mxArray *c93_lhs50 = NULL;
  const mxArray *c93_rhs51 = NULL;
  const mxArray *c93_lhs51 = NULL;
  const mxArray *c93_rhs52 = NULL;
  const mxArray *c93_lhs52 = NULL;
  const mxArray *c93_rhs53 = NULL;
  const mxArray *c93_lhs53 = NULL;
  const mxArray *c93_rhs54 = NULL;
  const mxArray *c93_lhs54 = NULL;
  const mxArray *c93_rhs55 = NULL;
  const mxArray *c93_lhs55 = NULL;
  const mxArray *c93_rhs56 = NULL;
  const mxArray *c93_lhs56 = NULL;
  const mxArray *c93_rhs57 = NULL;
  const mxArray *c93_lhs57 = NULL;
  const mxArray *c93_rhs58 = NULL;
  const mxArray *c93_lhs58 = NULL;
  const mxArray *c93_rhs59 = NULL;
  const mxArray *c93_lhs59 = NULL;
  const mxArray *c93_rhs60 = NULL;
  const mxArray *c93_lhs60 = NULL;
  const mxArray *c93_rhs61 = NULL;
  const mxArray *c93_lhs61 = NULL;
  const mxArray *c93_rhs62 = NULL;
  const mxArray *c93_lhs62 = NULL;
  const mxArray *c93_rhs63 = NULL;
  const mxArray *c93_lhs63 = NULL;
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("colon"), "name", "name", 0);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c93_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c93_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                  "context", "context", 2);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("isfinite"), "name", "name",
                  2);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c93_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c93_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("isinf"), "name", "name", 4);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c93_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c93_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("isnan"), "name", "name", 6);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c93_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c93_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                  "context", "context", 8);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("floor"), "name", "name", 8);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c93_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c93_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 10);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c93_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 11);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("realmax"), "name", "name",
                  11);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 11);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c93_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_realmax"), "name",
                  "name", 12);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c93_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 13);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c93_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 14);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("isnan"), "name", "name", 14);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c93_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 15);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("isinf"), "name", "name", 15);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c93_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 16);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("floor"), "name", "name", 16);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c93_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 17);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("abs"), "name", "name", 17);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c93_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 18);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c93_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 19);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c93_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 20);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eps"), "name", "name", 20);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c93_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 21);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c93_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_eps"), "name", "name",
                  22);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c93_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 23);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c93_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!maxabs"), "context",
                  "context", 24);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("abs"), "name", "name", 24);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c93_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 25);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 25);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c93_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 26);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("intmax"), "name", "name", 26);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c93_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 27);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c93_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 28);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 28);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1326749922U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c93_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 29);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 29);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c93_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 30);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 30);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c93_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 31);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("intmin"), "name", "name", 31);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c93_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 32);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c93_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon"),
                  "context", "context", 33);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 33);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c93_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 34);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c93_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon"),
                  "context", "context", 35);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_rdivide"), "name",
                  "name", 35);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c93_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexDivide"),
                  "name", "name", 36);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexDivide.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c93_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon"),
                  "context", "context", 37);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 37);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c93_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 38);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("isfi"), "name", "name", 38);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 38);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c93_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 39);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c93_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 40);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("intmax"), "name", "name", 40);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c93_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 41);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("intmin"), "name", "name", 41);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c93_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon"),
                  "context", "context", 42);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 42);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c93_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 43);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 43);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c93_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon"),
                  "context", "context", 44);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 44);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c93_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 45);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c93_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon"),
                  "context", "context", 46);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 46);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 46);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c93_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 47);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 47);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 47);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c93_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "context", "context", 48);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("interpolateRoughGround"),
                  "name", "name", 48);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/TransitionExp/DDAcontroller/interpolateRoughGround.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1460480082U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c93_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/TransitionExp/DDAcontroller/interpolateRoughGround.m"),
                  "context", "context", 49);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("length"), "name", "name", 49);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 49);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c93_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/TransitionExp/DDAcontroller/interpolateRoughGround.m"),
                  "context", "context", 50);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("abs"), "name", "name", 50);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c93_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/TransitionExp/DDAcontroller/interpolateRoughGround.m"),
                  "context", "context", 51);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("sort"), "name", "name", 51);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c93_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 52);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c93_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/sort.m"), "context",
                  "context", 53);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_sort"), "name", "name",
                  53);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1314758212U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c93_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_nonsingleton_dim"),
                  "name", "name", 54);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c93_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m"),
                  "context", "context", 55);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 55);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c93_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_nonsingleton_dim.m"),
                  "context", "context", 56);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 56);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c93_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_assert_valid_dim"),
                  "name", "name", 57);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 57);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m"),
                  "resolved", "resolved", 57);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c93_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_dim.m"),
                  "context", "context", 58);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.assertValidDim"), "name", "name", 58);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 58);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c93_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 59);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 59);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 59);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c93_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 60);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("floor"), "name", "name", 60);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 60);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 60);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c93_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 61);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 61);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 61);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c93_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 62);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 62);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 62);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c93_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assertValidDim.m"),
                  "context", "context", 63);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("intmax"), "name", "name", 63);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 63);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c93_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c93_rhs0);
  sf_mex_destroy(&c93_lhs0);
  sf_mex_destroy(&c93_rhs1);
  sf_mex_destroy(&c93_lhs1);
  sf_mex_destroy(&c93_rhs2);
  sf_mex_destroy(&c93_lhs2);
  sf_mex_destroy(&c93_rhs3);
  sf_mex_destroy(&c93_lhs3);
  sf_mex_destroy(&c93_rhs4);
  sf_mex_destroy(&c93_lhs4);
  sf_mex_destroy(&c93_rhs5);
  sf_mex_destroy(&c93_lhs5);
  sf_mex_destroy(&c93_rhs6);
  sf_mex_destroy(&c93_lhs6);
  sf_mex_destroy(&c93_rhs7);
  sf_mex_destroy(&c93_lhs7);
  sf_mex_destroy(&c93_rhs8);
  sf_mex_destroy(&c93_lhs8);
  sf_mex_destroy(&c93_rhs9);
  sf_mex_destroy(&c93_lhs9);
  sf_mex_destroy(&c93_rhs10);
  sf_mex_destroy(&c93_lhs10);
  sf_mex_destroy(&c93_rhs11);
  sf_mex_destroy(&c93_lhs11);
  sf_mex_destroy(&c93_rhs12);
  sf_mex_destroy(&c93_lhs12);
  sf_mex_destroy(&c93_rhs13);
  sf_mex_destroy(&c93_lhs13);
  sf_mex_destroy(&c93_rhs14);
  sf_mex_destroy(&c93_lhs14);
  sf_mex_destroy(&c93_rhs15);
  sf_mex_destroy(&c93_lhs15);
  sf_mex_destroy(&c93_rhs16);
  sf_mex_destroy(&c93_lhs16);
  sf_mex_destroy(&c93_rhs17);
  sf_mex_destroy(&c93_lhs17);
  sf_mex_destroy(&c93_rhs18);
  sf_mex_destroy(&c93_lhs18);
  sf_mex_destroy(&c93_rhs19);
  sf_mex_destroy(&c93_lhs19);
  sf_mex_destroy(&c93_rhs20);
  sf_mex_destroy(&c93_lhs20);
  sf_mex_destroy(&c93_rhs21);
  sf_mex_destroy(&c93_lhs21);
  sf_mex_destroy(&c93_rhs22);
  sf_mex_destroy(&c93_lhs22);
  sf_mex_destroy(&c93_rhs23);
  sf_mex_destroy(&c93_lhs23);
  sf_mex_destroy(&c93_rhs24);
  sf_mex_destroy(&c93_lhs24);
  sf_mex_destroy(&c93_rhs25);
  sf_mex_destroy(&c93_lhs25);
  sf_mex_destroy(&c93_rhs26);
  sf_mex_destroy(&c93_lhs26);
  sf_mex_destroy(&c93_rhs27);
  sf_mex_destroy(&c93_lhs27);
  sf_mex_destroy(&c93_rhs28);
  sf_mex_destroy(&c93_lhs28);
  sf_mex_destroy(&c93_rhs29);
  sf_mex_destroy(&c93_lhs29);
  sf_mex_destroy(&c93_rhs30);
  sf_mex_destroy(&c93_lhs30);
  sf_mex_destroy(&c93_rhs31);
  sf_mex_destroy(&c93_lhs31);
  sf_mex_destroy(&c93_rhs32);
  sf_mex_destroy(&c93_lhs32);
  sf_mex_destroy(&c93_rhs33);
  sf_mex_destroy(&c93_lhs33);
  sf_mex_destroy(&c93_rhs34);
  sf_mex_destroy(&c93_lhs34);
  sf_mex_destroy(&c93_rhs35);
  sf_mex_destroy(&c93_lhs35);
  sf_mex_destroy(&c93_rhs36);
  sf_mex_destroy(&c93_lhs36);
  sf_mex_destroy(&c93_rhs37);
  sf_mex_destroy(&c93_lhs37);
  sf_mex_destroy(&c93_rhs38);
  sf_mex_destroy(&c93_lhs38);
  sf_mex_destroy(&c93_rhs39);
  sf_mex_destroy(&c93_lhs39);
  sf_mex_destroy(&c93_rhs40);
  sf_mex_destroy(&c93_lhs40);
  sf_mex_destroy(&c93_rhs41);
  sf_mex_destroy(&c93_lhs41);
  sf_mex_destroy(&c93_rhs42);
  sf_mex_destroy(&c93_lhs42);
  sf_mex_destroy(&c93_rhs43);
  sf_mex_destroy(&c93_lhs43);
  sf_mex_destroy(&c93_rhs44);
  sf_mex_destroy(&c93_lhs44);
  sf_mex_destroy(&c93_rhs45);
  sf_mex_destroy(&c93_lhs45);
  sf_mex_destroy(&c93_rhs46);
  sf_mex_destroy(&c93_lhs46);
  sf_mex_destroy(&c93_rhs47);
  sf_mex_destroy(&c93_lhs47);
  sf_mex_destroy(&c93_rhs48);
  sf_mex_destroy(&c93_lhs48);
  sf_mex_destroy(&c93_rhs49);
  sf_mex_destroy(&c93_lhs49);
  sf_mex_destroy(&c93_rhs50);
  sf_mex_destroy(&c93_lhs50);
  sf_mex_destroy(&c93_rhs51);
  sf_mex_destroy(&c93_lhs51);
  sf_mex_destroy(&c93_rhs52);
  sf_mex_destroy(&c93_lhs52);
  sf_mex_destroy(&c93_rhs53);
  sf_mex_destroy(&c93_lhs53);
  sf_mex_destroy(&c93_rhs54);
  sf_mex_destroy(&c93_lhs54);
  sf_mex_destroy(&c93_rhs55);
  sf_mex_destroy(&c93_lhs55);
  sf_mex_destroy(&c93_rhs56);
  sf_mex_destroy(&c93_lhs56);
  sf_mex_destroy(&c93_rhs57);
  sf_mex_destroy(&c93_lhs57);
  sf_mex_destroy(&c93_rhs58);
  sf_mex_destroy(&c93_lhs58);
  sf_mex_destroy(&c93_rhs59);
  sf_mex_destroy(&c93_lhs59);
  sf_mex_destroy(&c93_rhs60);
  sf_mex_destroy(&c93_lhs60);
  sf_mex_destroy(&c93_rhs61);
  sf_mex_destroy(&c93_lhs61);
  sf_mex_destroy(&c93_rhs62);
  sf_mex_destroy(&c93_lhs62);
  sf_mex_destroy(&c93_rhs63);
  sf_mex_destroy(&c93_lhs63);
}

static const mxArray *c93_emlrt_marshallOut(const char * c93_u)
{
  const mxArray *c93_y = NULL;
  c93_y = NULL;
  sf_mex_assign(&c93_y, sf_mex_create("y", c93_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c93_u)), false);
  return c93_y;
}

static const mxArray *c93_b_emlrt_marshallOut(const uint32_T c93_u)
{
  const mxArray *c93_y = NULL;
  c93_y = NULL;
  sf_mex_assign(&c93_y, sf_mex_create("y", &c93_u, 7, 0U, 0U, 0U, 0), false);
  return c93_y;
}

static void c93_b_info_helper(const mxArray **c93_info)
{
  const mxArray *c93_rhs64 = NULL;
  const mxArray *c93_lhs64 = NULL;
  const mxArray *c93_rhs65 = NULL;
  const mxArray *c93_lhs65 = NULL;
  const mxArray *c93_rhs66 = NULL;
  const mxArray *c93_lhs66 = NULL;
  const mxArray *c93_rhs67 = NULL;
  const mxArray *c93_lhs67 = NULL;
  const mxArray *c93_rhs68 = NULL;
  const mxArray *c93_lhs68 = NULL;
  const mxArray *c93_rhs69 = NULL;
  const mxArray *c93_lhs69 = NULL;
  const mxArray *c93_rhs70 = NULL;
  const mxArray *c93_lhs70 = NULL;
  const mxArray *c93_rhs71 = NULL;
  const mxArray *c93_lhs71 = NULL;
  const mxArray *c93_rhs72 = NULL;
  const mxArray *c93_lhs72 = NULL;
  const mxArray *c93_rhs73 = NULL;
  const mxArray *c93_lhs73 = NULL;
  const mxArray *c93_rhs74 = NULL;
  const mxArray *c93_lhs74 = NULL;
  const mxArray *c93_rhs75 = NULL;
  const mxArray *c93_lhs75 = NULL;
  const mxArray *c93_rhs76 = NULL;
  const mxArray *c93_lhs76 = NULL;
  const mxArray *c93_rhs77 = NULL;
  const mxArray *c93_lhs77 = NULL;
  const mxArray *c93_rhs78 = NULL;
  const mxArray *c93_lhs78 = NULL;
  const mxArray *c93_rhs79 = NULL;
  const mxArray *c93_lhs79 = NULL;
  const mxArray *c93_rhs80 = NULL;
  const mxArray *c93_lhs80 = NULL;
  const mxArray *c93_rhs81 = NULL;
  const mxArray *c93_lhs81 = NULL;
  const mxArray *c93_rhs82 = NULL;
  const mxArray *c93_lhs82 = NULL;
  const mxArray *c93_rhs83 = NULL;
  const mxArray *c93_lhs83 = NULL;
  const mxArray *c93_rhs84 = NULL;
  const mxArray *c93_lhs84 = NULL;
  const mxArray *c93_rhs85 = NULL;
  const mxArray *c93_lhs85 = NULL;
  const mxArray *c93_rhs86 = NULL;
  const mxArray *c93_lhs86 = NULL;
  const mxArray *c93_rhs87 = NULL;
  const mxArray *c93_lhs87 = NULL;
  const mxArray *c93_rhs88 = NULL;
  const mxArray *c93_lhs88 = NULL;
  const mxArray *c93_rhs89 = NULL;
  const mxArray *c93_lhs89 = NULL;
  const mxArray *c93_rhs90 = NULL;
  const mxArray *c93_lhs90 = NULL;
  const mxArray *c93_rhs91 = NULL;
  const mxArray *c93_lhs91 = NULL;
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "context",
                  "context", 64);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 64);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 64);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c93_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 65);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 65);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c93_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort.m"), "context",
                  "context", 66);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_sort_idx"), "name",
                  "name", 66);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "resolved",
                  "resolved", 66);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1305339604U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c93_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 67);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 67);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c93_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 68);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_size_ispow2"), "name",
                  "name", 68);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 68);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731870U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c93_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_size_ispow2.m"),
                  "context", "context", 69);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 69);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c93_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 70);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 70);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c93_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 71);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 71);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c93_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 72);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 72);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c93_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 73);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 73);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 73);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 73);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c93_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 74);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 74);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 74);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c93_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 75);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 75);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c93_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 76);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 76);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c93_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 77);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 77);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c93_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 78);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_sort_le"), "name",
                  "name", 78);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m"), "resolved",
                  "resolved", 78);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1292212110U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c93_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m!eml_sort_ascending_le"),
                  "context", "context", 79);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_relop"), "name", "name",
                  79);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 79);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 79);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1342472782U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c93_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_le.m!eml_sort_ascending_le"),
                  "context", "context", 80);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("isnan"), "name", "name", 80);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 80);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c93_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 81);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 81);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 81);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c93_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_sort_idx.m"), "context",
                  "context", 82);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 82);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 82);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c93_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/TransitionExp/DDAcontroller/interpolateRoughGround.m"),
                  "context", "context", 83);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 83);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 83);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c93_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 84);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 84);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c93_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/TransitionExp/DDAcontroller/interpolateRoughGround.m"),
                  "context", "context", 85);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("mrdivide"), "name", "name",
                  85);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 85);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c93_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 86);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 86);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c93_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 87);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("rdivide"), "name", "name",
                  87);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 87);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c93_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 88);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 88);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 88);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c93_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 89);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 89);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c93_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 90);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("eml_div"), "name", "name",
                  90);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 90);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c93_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 91);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 91);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c93_info, c93_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 91);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c93_info, c93_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c93_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c93_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c93_info, sf_mex_duplicatearraysafe(&c93_lhs91), "lhs", "lhs",
                  91);
  sf_mex_destroy(&c93_rhs64);
  sf_mex_destroy(&c93_lhs64);
  sf_mex_destroy(&c93_rhs65);
  sf_mex_destroy(&c93_lhs65);
  sf_mex_destroy(&c93_rhs66);
  sf_mex_destroy(&c93_lhs66);
  sf_mex_destroy(&c93_rhs67);
  sf_mex_destroy(&c93_lhs67);
  sf_mex_destroy(&c93_rhs68);
  sf_mex_destroy(&c93_lhs68);
  sf_mex_destroy(&c93_rhs69);
  sf_mex_destroy(&c93_lhs69);
  sf_mex_destroy(&c93_rhs70);
  sf_mex_destroy(&c93_lhs70);
  sf_mex_destroy(&c93_rhs71);
  sf_mex_destroy(&c93_lhs71);
  sf_mex_destroy(&c93_rhs72);
  sf_mex_destroy(&c93_lhs72);
  sf_mex_destroy(&c93_rhs73);
  sf_mex_destroy(&c93_lhs73);
  sf_mex_destroy(&c93_rhs74);
  sf_mex_destroy(&c93_lhs74);
  sf_mex_destroy(&c93_rhs75);
  sf_mex_destroy(&c93_lhs75);
  sf_mex_destroy(&c93_rhs76);
  sf_mex_destroy(&c93_lhs76);
  sf_mex_destroy(&c93_rhs77);
  sf_mex_destroy(&c93_lhs77);
  sf_mex_destroy(&c93_rhs78);
  sf_mex_destroy(&c93_lhs78);
  sf_mex_destroy(&c93_rhs79);
  sf_mex_destroy(&c93_lhs79);
  sf_mex_destroy(&c93_rhs80);
  sf_mex_destroy(&c93_lhs80);
  sf_mex_destroy(&c93_rhs81);
  sf_mex_destroy(&c93_lhs81);
  sf_mex_destroy(&c93_rhs82);
  sf_mex_destroy(&c93_lhs82);
  sf_mex_destroy(&c93_rhs83);
  sf_mex_destroy(&c93_lhs83);
  sf_mex_destroy(&c93_rhs84);
  sf_mex_destroy(&c93_lhs84);
  sf_mex_destroy(&c93_rhs85);
  sf_mex_destroy(&c93_lhs85);
  sf_mex_destroy(&c93_rhs86);
  sf_mex_destroy(&c93_lhs86);
  sf_mex_destroy(&c93_rhs87);
  sf_mex_destroy(&c93_lhs87);
  sf_mex_destroy(&c93_rhs88);
  sf_mex_destroy(&c93_lhs88);
  sf_mex_destroy(&c93_rhs89);
  sf_mex_destroy(&c93_lhs89);
  sf_mex_destroy(&c93_rhs90);
  sf_mex_destroy(&c93_lhs90);
  sf_mex_destroy(&c93_rhs91);
  sf_mex_destroy(&c93_lhs91);
}

static void c93_eml_switch_helper(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c93_eml_sort(SFc93_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c93_x[15], real_T c93_y[15], int32_T c93_idx[15])
{
  int32_T c93_i66;
  real_T c93_b_x[15];
  for (c93_i66 = 0; c93_i66 < 15; c93_i66++) {
    c93_b_x[c93_i66] = c93_x[c93_i66];
  }

  c93_eml_sort_idx(chartInstance, c93_b_x, c93_idx, c93_y);
}

static void c93_eml_sort_idx(SFc93_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c93_x[15], int32_T c93_idx[15], real_T c93_y[15])
{
  int32_T c93_k;
  int32_T c93_b_k;
  int32_T c93_c_k;
  int32_T c93_a;
  int32_T c93_b_a;
  int32_T c93_c;
  int32_T c93_irow1;
  int32_T c93_irow2;
  real_T c93_c_a;
  real_T c93_b;
  real_T c93_d_a;
  real_T c93_b_b;
  boolean_T c93_p;
  real_T c93_b_x;
  boolean_T c93_c_b;
  boolean_T c93_b0;
  boolean_T c93_b_p;
  int32_T c93_e_a;
  int32_T c93_f_a;
  int32_T c93_b_c;
  int32_T c93_g_a;
  int32_T c93_h_a;
  int32_T c93_c_c;
  int32_T c93_i67;
  int32_T c93_idx0[15];
  int32_T c93_i;
  int32_T c93_i_a;
  int32_T c93_j_a;
  int32_T c93_i2;
  int32_T c93_j;
  int32_T c93_d_b;
  int32_T c93_e_b;
  int32_T c93_pEnd;
  int32_T c93_c_p;
  int32_T c93_q;
  int32_T c93_k_a;
  int32_T c93_f_b;
  int32_T c93_l_a;
  int32_T c93_g_b;
  int32_T c93_qEnd;
  int32_T c93_m_a;
  int32_T c93_h_b;
  int32_T c93_n_a;
  int32_T c93_i_b;
  int32_T c93_kEnd;
  int32_T c93_b_irow1;
  int32_T c93_b_irow2;
  real_T c93_o_a;
  real_T c93_j_b;
  real_T c93_p_a;
  real_T c93_k_b;
  boolean_T c93_d_p;
  real_T c93_c_x;
  boolean_T c93_l_b;
  boolean_T c93_b1;
  boolean_T c93_e_p;
  int32_T c93_q_a;
  int32_T c93_r_a;
  int32_T c93_s_a;
  int32_T c93_t_a;
  int32_T c93_u_a;
  int32_T c93_v_a;
  int32_T c93_w_a;
  int32_T c93_x_a;
  int32_T c93_y_a;
  int32_T c93_ab_a;
  int32_T c93_bb_a;
  int32_T c93_cb_a;
  int32_T c93_db_a;
  int32_T c93_eb_a;
  int32_T c93_fb_a;
  int32_T c93_gb_a;
  int32_T c93_b_kEnd;
  int32_T c93_m_b;
  int32_T c93_n_b;
  boolean_T c93_overflow;
  int32_T c93_d_k;
  int32_T c93_hb_a;
  int32_T c93_o_b;
  int32_T c93_ib_a;
  int32_T c93_p_b;
  int32_T c93_d_c;
  int32_T c93_jb_a;
  int32_T c93_q_b;
  int32_T c93_kb_a;
  int32_T c93_r_b;
  int32_T c93_e_k;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  c93_eml_switch_helper(chartInstance);
  for (c93_k = 1; c93_k < 16; c93_k++) {
    c93_b_k = c93_k;
    c93_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c93_b_k), 1, 15, 1, 0) - 1] = c93_b_k;
  }

  c93_eml_switch_helper(chartInstance);
  for (c93_c_k = 1; c93_c_k < 15; c93_c_k += 2) {
    c93_b_k = c93_c_k;
    c93_a = c93_b_k;
    c93_b_a = c93_a;
    c93_c = c93_b_a;
    c93_irow1 = c93_b_k;
    c93_irow2 = c93_c + 1;
    c93_c_a = c93_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c93_irow1), 1, 15, 1, 0) - 1];
    c93_b = c93_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c93_irow2), 1, 15, 1, 0) - 1];
    c93_d_a = c93_c_a;
    c93_b_b = c93_b;
    c93_p = (c93_d_a <= c93_b_b);
    guard2 = false;
    if (c93_p) {
      guard2 = true;
    } else {
      c93_b_x = c93_b;
      c93_c_b = muDoubleScalarIsNaN(c93_b_x);
      if (c93_c_b) {
        guard2 = true;
      } else {
        c93_b0 = false;
      }
    }

    if (guard2 == true) {
      c93_b0 = true;
    }

    c93_b_p = c93_b0;
    if (c93_b_p) {
    } else {
      c93_e_a = c93_b_k;
      c93_f_a = c93_e_a;
      c93_b_c = c93_f_a;
      c93_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c93_b_k), 1, 15, 1, 0) - 1] = c93_b_c + 1;
      c93_g_a = c93_b_k;
      c93_h_a = c93_g_a;
      c93_c_c = c93_h_a;
      c93_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c93_c_c + 1)), 1, 15, 1, 0) - 1] = c93_b_k;
    }
  }

  for (c93_i67 = 0; c93_i67 < 15; c93_i67++) {
    c93_idx0[c93_i67] = 1;
  }

  c93_i = 2;
  while (c93_i < 15) {
    c93_i_a = c93_i;
    c93_j_a = c93_i_a;
    c93_i2 = c93_j_a << 1;
    c93_j = 1;
    c93_d_b = c93_i;
    c93_e_b = c93_d_b + 1;
    for (c93_pEnd = c93_e_b; c93_pEnd < 16; c93_pEnd = c93_kb_a + c93_r_b) {
      c93_c_p = c93_j;
      c93_q = c93_pEnd;
      c93_k_a = c93_j;
      c93_f_b = c93_i2;
      c93_l_a = c93_k_a;
      c93_g_b = c93_f_b;
      c93_qEnd = c93_l_a + c93_g_b;
      if (c93_qEnd > 16) {
        c93_qEnd = 16;
      }

      c93_b_k = 1;
      c93_m_a = c93_qEnd;
      c93_h_b = c93_j;
      c93_n_a = c93_m_a;
      c93_i_b = c93_h_b;
      c93_kEnd = c93_n_a - c93_i_b;
      while (c93_b_k <= c93_kEnd) {
        c93_b_irow1 = c93_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c93_c_p), 1, 15, 1, 0) - 1];
        c93_b_irow2 = c93_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c93_q), 1, 15, 1, 0) - 1];
        c93_o_a = c93_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c93_b_irow1), 1, 15, 1, 0) - 1];
        c93_j_b = c93_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c93_b_irow2), 1, 15, 1, 0) - 1];
        c93_p_a = c93_o_a;
        c93_k_b = c93_j_b;
        c93_d_p = (c93_p_a <= c93_k_b);
        guard1 = false;
        if (c93_d_p) {
          guard1 = true;
        } else {
          c93_c_x = c93_j_b;
          c93_l_b = muDoubleScalarIsNaN(c93_c_x);
          if (c93_l_b) {
            guard1 = true;
          } else {
            c93_b1 = false;
          }
        }

        if (guard1 == true) {
          c93_b1 = true;
        }

        c93_e_p = c93_b1;
        if (c93_e_p) {
          c93_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c93_b_k), 1, 15, 1, 0) - 1] =
            c93_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c93_c_p), 1, 15, 1, 0) - 1];
          c93_q_a = c93_c_p;
          c93_r_a = c93_q_a + 1;
          c93_c_p = c93_r_a;
          if (c93_c_p == c93_pEnd) {
            while (c93_q < c93_qEnd) {
              c93_s_a = c93_b_k;
              c93_t_a = c93_s_a + 1;
              c93_b_k = c93_t_a;
              c93_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c93_b_k), 1, 15, 1, 0) - 1] =
                c93_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c93_q), 1, 15, 1, 0) - 1];
              c93_u_a = c93_q;
              c93_v_a = c93_u_a + 1;
              c93_q = c93_v_a;
            }
          }
        } else {
          c93_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c93_b_k), 1, 15, 1, 0) - 1] =
            c93_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)c93_q), 1, 15, 1, 0) - 1];
          c93_w_a = c93_q;
          c93_x_a = c93_w_a + 1;
          c93_q = c93_x_a;
          if (c93_q == c93_qEnd) {
            while (c93_c_p < c93_pEnd) {
              c93_y_a = c93_b_k;
              c93_ab_a = c93_y_a + 1;
              c93_b_k = c93_ab_a;
              c93_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c93_b_k), 1, 15, 1, 0) - 1] =
                c93_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
                _SFD_INTEGER_CHECK("", (real_T)c93_c_p), 1, 15, 1, 0) - 1];
              c93_bb_a = c93_c_p;
              c93_cb_a = c93_bb_a + 1;
              c93_c_p = c93_cb_a;
            }
          }
        }

        c93_db_a = c93_b_k;
        c93_eb_a = c93_db_a + 1;
        c93_b_k = c93_eb_a;
      }

      c93_fb_a = c93_j;
      c93_gb_a = c93_fb_a;
      c93_c_p = c93_gb_a;
      c93_b_kEnd = c93_kEnd;
      c93_m_b = c93_b_kEnd;
      c93_n_b = c93_m_b;
      if (1 > c93_n_b) {
        c93_overflow = false;
      } else {
        c93_eml_switch_helper(chartInstance);
        c93_eml_switch_helper(chartInstance);
        c93_overflow = (c93_n_b > 2147483646);
      }

      if (c93_overflow) {
        c93_check_forloop_overflow_error(chartInstance, c93_overflow);
      }

      for (c93_d_k = 1; c93_d_k <= c93_b_kEnd; c93_d_k++) {
        c93_b_k = c93_d_k;
        c93_hb_a = c93_c_p - 1;
        c93_o_b = c93_b_k;
        c93_ib_a = c93_hb_a;
        c93_p_b = c93_o_b;
        c93_d_c = c93_ib_a + c93_p_b;
        c93_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c93_d_c), 1, 15, 1, 0) - 1] =
          c93_idx0[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
          "", (real_T)c93_b_k), 1, 15, 1, 0) - 1];
      }

      c93_j = c93_qEnd;
      c93_jb_a = c93_j;
      c93_q_b = c93_i;
      c93_kb_a = c93_jb_a;
      c93_r_b = c93_q_b;
    }

    c93_i = c93_i2;
  }

  c93_eml_switch_helper(chartInstance);
  for (c93_e_k = 1; c93_e_k < 16; c93_e_k++) {
    c93_b_k = c93_e_k;
    c93_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c93_b_k), 1, 15, 1, 0) - 1] = c93_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c93_idx[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c93_b_k), 1, 15, 1, 0) - 1]), 1, 15, 1, 0) - 1];
  }
}

static void c93_check_forloop_overflow_error(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, boolean_T c93_overflow)
{
  int32_T c93_i68;
  static char_T c93_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c93_u[34];
  const mxArray *c93_y = NULL;
  int32_T c93_i69;
  static char_T c93_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c93_b_u[5];
  const mxArray *c93_b_y = NULL;
  (void)chartInstance;
  if (!c93_overflow) {
  } else {
    for (c93_i68 = 0; c93_i68 < 34; c93_i68++) {
      c93_u[c93_i68] = c93_cv0[c93_i68];
    }

    c93_y = NULL;
    sf_mex_assign(&c93_y, sf_mex_create("y", c93_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c93_i69 = 0; c93_i69 < 5; c93_i69++) {
      c93_b_u[c93_i69] = c93_cv1[c93_i69];
    }

    c93_b_y = NULL;
    sf_mex_assign(&c93_b_y, sf_mex_create("y", c93_b_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c93_y, 14, c93_b_y));
  }
}

static const mxArray *c93_f_sf_marshallOut(void *chartInstanceVoid, void
  *c93_inData)
{
  const mxArray *c93_mxArrayOutData = NULL;
  int32_T c93_u;
  const mxArray *c93_y = NULL;
  SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c93_mxArrayOutData = NULL;
  c93_u = *(int32_T *)c93_inData;
  c93_y = NULL;
  sf_mex_assign(&c93_y, sf_mex_create("y", &c93_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c93_mxArrayOutData, c93_y, false);
  return c93_mxArrayOutData;
}

static int32_T c93_g_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId)
{
  int32_T c93_y;
  int32_T c93_i70;
  (void)chartInstance;
  sf_mex_import(c93_parentId, sf_mex_dup(c93_u), &c93_i70, 1, 6, 0U, 0, 0U, 0);
  c93_y = c93_i70;
  sf_mex_destroy(&c93_u);
  return c93_y;
}

static void c93_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c93_mxArrayInData, const char_T *c93_varName, void *c93_outData)
{
  const mxArray *c93_b_sfEvent;
  const char_T *c93_identifier;
  emlrtMsgIdentifier c93_thisId;
  int32_T c93_y;
  SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c93_b_sfEvent = sf_mex_dup(c93_mxArrayInData);
  c93_identifier = c93_varName;
  c93_thisId.fIdentifier = c93_identifier;
  c93_thisId.fParent = NULL;
  c93_y = c93_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c93_b_sfEvent),
    &c93_thisId);
  sf_mex_destroy(&c93_b_sfEvent);
  *(int32_T *)c93_outData = c93_y;
  sf_mex_destroy(&c93_mxArrayInData);
}

static uint8_T c93_h_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_b_is_active_c93_Walking01_DDA3D, const
  char_T *c93_identifier)
{
  uint8_T c93_y;
  emlrtMsgIdentifier c93_thisId;
  c93_thisId.fIdentifier = c93_identifier;
  c93_thisId.fParent = NULL;
  c93_y = c93_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c93_b_is_active_c93_Walking01_DDA3D), &c93_thisId);
  sf_mex_destroy(&c93_b_is_active_c93_Walking01_DDA3D);
  return c93_y;
}

static uint8_T c93_i_emlrt_marshallIn(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c93_u, const emlrtMsgIdentifier *c93_parentId)
{
  uint8_T c93_y;
  uint8_T c93_u0;
  (void)chartInstance;
  sf_mex_import(c93_parentId, sf_mex_dup(c93_u), &c93_u0, 1, 3, 0U, 0, 0U, 0);
  c93_y = c93_u0;
  sf_mex_destroy(&c93_u);
  return c93_y;
}

static void init_dsm_address_info(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc93_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c93_hAlphaSet = (real_T (*)[1080])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c93_HAlphaTwo = (real_T (*)[72])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c93_dy = (real_T *)ssGetInputPortSignal_wrapper
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

void sf_c93_Walking01_DDA3D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3028096141U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2334548576U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3544943323U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3986450833U);
}

mxArray* sf_c93_Walking01_DDA3D_get_post_codegen_info(void);
mxArray *sf_c93_Walking01_DDA3D_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("1mU39Zfe7Wsa8QVzr7IfGC");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,3,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(12);
      pr[1] = (double)(6);
      pr[2] = (double)(15);
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
      pr[0] = (double)(12);
      pr[1] = (double)(6);
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
    mxArray* mxPostCodegenInfo = sf_c93_Walking01_DDA3D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c93_Walking01_DDA3D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c93_Walking01_DDA3D_jit_fallback_info(void)
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

mxArray *sf_c93_Walking01_DDA3D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c93_Walking01_DDA3D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c93_Walking01_DDA3D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"HAlphaTwo\",},{M[8],M[0],T\"is_active_c93_Walking01_DDA3D\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c93_Walking01_DDA3D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_DDA3DMachineNumber_,
           93,
           1,
           1,
           0,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"hAlphaSet");
          _SFD_SET_DATA_PROPS(1,2,0,1,"HAlphaTwo");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dy");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,323);
        _SFD_CV_INIT_EML_IF(0,1,0,101,111,179,320);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,104,111,-1,5);
        _SFD_CV_INIT_SCRIPT(0,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"interpolateRoughGround",0,-1,630);
        _SFD_CV_INIT_SCRIPT_IF(0,0,73,93,320,356);
        _SFD_CV_INIT_SCRIPT_IF(0,1,360,379,597,630);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,0,76,93,-1,4);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,1,363,379,-1,4);

        {
          unsigned int dimVector[3];
          dimVector[0]= 12;
          dimVector[1]= 6;
          dimVector[2]= 15;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,3,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c93_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 12;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c93_sf_marshallOut,(MexInFcnForType)
            c93_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c93_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c93_hAlphaSet);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c93_HAlphaTwo);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c93_dy);
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
  return "D6wsj60IMLHf4DjqsHgJW";
}

static void sf_opaque_initialize_c93_Walking01_DDA3D(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc93_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c93_Walking01_DDA3D((SFc93_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
  initialize_c93_Walking01_DDA3D((SFc93_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c93_Walking01_DDA3D(void *chartInstanceVar)
{
  enable_c93_Walking01_DDA3D((SFc93_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c93_Walking01_DDA3D(void *chartInstanceVar)
{
  disable_c93_Walking01_DDA3D((SFc93_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c93_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_gateway_c93_Walking01_DDA3D((SFc93_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c93_Walking01_DDA3D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c93_Walking01_DDA3D((SFc93_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c93_Walking01_DDA3D(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c93_Walking01_DDA3D((SFc93_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c93_Walking01_DDA3D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc93_Walking01_DDA3DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_DDA3D_optimization_info();
    }

    finalize_c93_Walking01_DDA3D((SFc93_Walking01_DDA3DInstanceStruct*)
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
  initSimStructsc93_Walking01_DDA3D((SFc93_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c93_Walking01_DDA3D(SimStruct *S)
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
    initialize_params_c93_Walking01_DDA3D((SFc93_Walking01_DDA3DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c93_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      93);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,93,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,93,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,93);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,93,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,93,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,93);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3050265693U));
  ssSetChecksum1(S,(1390347347U));
  ssSetChecksum2(S,(2898756180U));
  ssSetChecksum3(S,(152499479U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c93_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c93_Walking01_DDA3D(SimStruct *S)
{
  SFc93_Walking01_DDA3DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc93_Walking01_DDA3DInstanceStruct *)utMalloc(sizeof
    (SFc93_Walking01_DDA3DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc93_Walking01_DDA3DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c93_Walking01_DDA3D;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c93_Walking01_DDA3D;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c93_Walking01_DDA3D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c93_Walking01_DDA3D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c93_Walking01_DDA3D;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c93_Walking01_DDA3D;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c93_Walking01_DDA3D;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c93_Walking01_DDA3D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c93_Walking01_DDA3D;
  chartInstance->chartInfo.mdlStart = mdlStart_c93_Walking01_DDA3D;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c93_Walking01_DDA3D;
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

void c93_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c93_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c93_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c93_Walking01_DDA3D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c93_Walking01_DDA3D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
