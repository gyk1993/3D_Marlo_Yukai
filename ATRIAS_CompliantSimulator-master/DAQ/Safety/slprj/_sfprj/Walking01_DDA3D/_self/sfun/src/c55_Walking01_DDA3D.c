/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_DDA3D_sfun.h"
#include "c55_Walking01_DDA3D.h"
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
static const char * c55_debug_family_names[7] = { "TorsoCOMRollOffset",
  "TorsoCOMPitchOffset", "nargin", "nargout", "q_in", "TorsoCOMOffsets", "q" };

/* Function Declarations */
static void initialize_c55_Walking01_DDA3D(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initialize_params_c55_Walking01_DDA3D
  (SFc55_Walking01_DDA3DInstanceStruct *chartInstance);
static void enable_c55_Walking01_DDA3D(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void disable_c55_Walking01_DDA3D(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c55_update_debugger_state_c55_Walking01_DDA3D
  (SFc55_Walking01_DDA3DInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c55_Walking01_DDA3D
  (SFc55_Walking01_DDA3DInstanceStruct *chartInstance);
static void set_sim_state_c55_Walking01_DDA3D
  (SFc55_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c55_st);
static void finalize_c55_Walking01_DDA3D(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void sf_gateway_c55_Walking01_DDA3D(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void mdl_start_c55_Walking01_DDA3D(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c55_chartstep_c55_Walking01_DDA3D
  (SFc55_Walking01_DDA3DInstanceStruct *chartInstance);
static void initSimStructsc55_Walking01_DDA3D
  (SFc55_Walking01_DDA3DInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c55_machineNumber, uint32_T
  c55_chartNumber, uint32_T c55_instanceNumber);
static const mxArray *c55_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static void c55_emlrt_marshallIn(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c55_b_q, const char_T *c55_identifier, real_T
  c55_y[13]);
static void c55_b_emlrt_marshallIn(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId,
  real_T c55_y[13]);
static void c55_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData);
static const mxArray *c55_b_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static const mxArray *c55_c_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static real_T c55_c_emlrt_marshallIn(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void c55_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData);
static void c55_info_helper(const mxArray **c55_info);
static const mxArray *c55_emlrt_marshallOut(const char * c55_u);
static const mxArray *c55_b_emlrt_marshallOut(const uint32_T c55_u);
static void c55_realmax(SFc55_Walking01_DDA3DInstanceStruct *chartInstance);
static const mxArray *c55_d_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData);
static int32_T c55_d_emlrt_marshallIn(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void c55_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData);
static uint8_T c55_e_emlrt_marshallIn(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c55_b_is_active_c55_Walking01_DDA3D, const
  char_T *c55_identifier);
static uint8_T c55_f_emlrt_marshallIn(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId);
static void init_dsm_address_info(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c55_Walking01_DDA3D(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c55_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c55_is_active_c55_Walking01_DDA3D = 0U;
}

static void initialize_params_c55_Walking01_DDA3D
  (SFc55_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c55_Walking01_DDA3D(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c55_Walking01_DDA3D(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c55_update_debugger_state_c55_Walking01_DDA3D
  (SFc55_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c55_Walking01_DDA3D
  (SFc55_Walking01_DDA3DInstanceStruct *chartInstance)
{
  const mxArray *c55_st;
  const mxArray *c55_y = NULL;
  int32_T c55_i0;
  real_T c55_u[13];
  const mxArray *c55_b_y = NULL;
  uint8_T c55_hoistedGlobal;
  uint8_T c55_b_u;
  const mxArray *c55_c_y = NULL;
  c55_st = NULL;
  c55_st = NULL;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_createcellmatrix(2, 1), false);
  for (c55_i0 = 0; c55_i0 < 13; c55_i0++) {
    c55_u[c55_i0] = (*chartInstance->c55_q)[c55_i0];
  }

  c55_b_y = NULL;
  sf_mex_assign(&c55_b_y, sf_mex_create("y", c55_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_setcell(c55_y, 0, c55_b_y);
  c55_hoistedGlobal = chartInstance->c55_is_active_c55_Walking01_DDA3D;
  c55_b_u = c55_hoistedGlobal;
  c55_c_y = NULL;
  sf_mex_assign(&c55_c_y, sf_mex_create("y", &c55_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c55_y, 1, c55_c_y);
  sf_mex_assign(&c55_st, c55_y, false);
  return c55_st;
}

static void set_sim_state_c55_Walking01_DDA3D
  (SFc55_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c55_st)
{
  const mxArray *c55_u;
  real_T c55_dv0[13];
  int32_T c55_i1;
  chartInstance->c55_doneDoubleBufferReInit = true;
  c55_u = sf_mex_dup(c55_st);
  c55_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c55_u, 0)), "q",
                       c55_dv0);
  for (c55_i1 = 0; c55_i1 < 13; c55_i1++) {
    (*chartInstance->c55_q)[c55_i1] = c55_dv0[c55_i1];
  }

  chartInstance->c55_is_active_c55_Walking01_DDA3D = c55_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c55_u, 1)),
     "is_active_c55_Walking01_DDA3D");
  sf_mex_destroy(&c55_u);
  c55_update_debugger_state_c55_Walking01_DDA3D(chartInstance);
  sf_mex_destroy(&c55_st);
}

static void finalize_c55_Walking01_DDA3D(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c55_Walking01_DDA3D(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  int32_T c55_i2;
  int32_T c55_i3;
  int32_T c55_i4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 24U, chartInstance->c55_sfEvent);
  for (c55_i2 = 0; c55_i2 < 13; c55_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c55_q_in)[c55_i2], 0U);
  }

  chartInstance->c55_sfEvent = CALL_EVENT;
  c55_chartstep_c55_Walking01_DDA3D(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_DDA3DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c55_i3 = 0; c55_i3 < 13; c55_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c55_q)[c55_i3], 1U);
  }

  for (c55_i4 = 0; c55_i4 < 2; c55_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c55_TorsoCOMOffsets)[c55_i4], 2U);
  }
}

static void mdl_start_c55_Walking01_DDA3D(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c55_chartstep_c55_Walking01_DDA3D
  (SFc55_Walking01_DDA3DInstanceStruct *chartInstance)
{
  int32_T c55_i5;
  real_T c55_b_q_in[13];
  int32_T c55_i6;
  real_T c55_b_TorsoCOMOffsets[2];
  uint32_T c55_debug_family_var_map[7];
  real_T c55_TorsoCOMRollOffset;
  real_T c55_TorsoCOMPitchOffset;
  real_T c55_nargin = 2.0;
  real_T c55_nargout = 1.0;
  real_T c55_b_q[13];
  real_T c55_A;
  real_T c55_x;
  real_T c55_b_x;
  real_T c55_c_x;
  real_T c55_b_A;
  real_T c55_d_x;
  real_T c55_e_x;
  real_T c55_f_x;
  int32_T c55_i7;
  int32_T c55_i8;
  static int32_T c55_iv0[8] = { 3, 4, 5, 6, 7, 8, 10, 11 };

  real_T c55_c_q[8];
  int32_T c55_i9;
  int32_T c55_i10;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 24U, chartInstance->c55_sfEvent);
  for (c55_i5 = 0; c55_i5 < 13; c55_i5++) {
    c55_b_q_in[c55_i5] = (*chartInstance->c55_q_in)[c55_i5];
  }

  for (c55_i6 = 0; c55_i6 < 2; c55_i6++) {
    c55_b_TorsoCOMOffsets[c55_i6] = (*chartInstance->c55_TorsoCOMOffsets)[c55_i6];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c55_debug_family_names,
    c55_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_TorsoCOMRollOffset, 0U,
    c55_c_sf_marshallOut, c55_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_TorsoCOMPitchOffset, 1U,
    c55_c_sf_marshallOut, c55_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_nargin, 2U, c55_c_sf_marshallOut,
    c55_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c55_nargout, 3U, c55_c_sf_marshallOut,
    c55_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c55_b_q_in, 4U, c55_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c55_b_TorsoCOMOffsets, 5U, c55_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c55_b_q, 6U, c55_sf_marshallOut,
    c55_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 4);
  c55_A = c55_b_TorsoCOMOffsets[0] * 3.1415926535897931;
  c55_x = c55_A;
  c55_b_x = c55_x;
  c55_c_x = c55_b_x;
  c55_TorsoCOMRollOffset = c55_c_x / 180.0;
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 5);
  c55_b_A = c55_b_TorsoCOMOffsets[1] * 3.1415926535897931;
  c55_d_x = c55_b_A;
  c55_e_x = c55_d_x;
  c55_f_x = c55_e_x;
  c55_TorsoCOMPitchOffset = c55_f_x / 180.0;
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 7);
  for (c55_i7 = 0; c55_i7 < 13; c55_i7++) {
    c55_b_q[c55_i7] = c55_b_q_in[c55_i7];
  }

  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 8);
  c55_b_q[1] += c55_TorsoCOMRollOffset;
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 9);
  c55_b_q[9] -= c55_TorsoCOMRollOffset;
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 10);
  c55_b_q[12] += c55_TorsoCOMRollOffset;
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 12);
  c55_b_q[2] += c55_TorsoCOMPitchOffset;
  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, 13);
  c55_realmax(chartInstance);
  c55_realmax(chartInstance);
  c55_realmax(chartInstance);
  c55_realmax(chartInstance);
  for (c55_i8 = 0; c55_i8 < 8; c55_i8++) {
    c55_c_q[c55_i8] = c55_b_q[c55_iv0[c55_i8]] - c55_TorsoCOMPitchOffset;
  }

  for (c55_i9 = 0; c55_i9 < 8; c55_i9++) {
    c55_b_q[c55_iv0[c55_i9]] = c55_c_q[c55_i9];
  }

  _SFD_EML_CALL(0U, chartInstance->c55_sfEvent, -13);
  _SFD_SYMBOL_SCOPE_POP();
  for (c55_i10 = 0; c55_i10 < 13; c55_i10++) {
    (*chartInstance->c55_q)[c55_i10] = c55_b_q[c55_i10];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 24U, chartInstance->c55_sfEvent);
}

static void initSimStructsc55_Walking01_DDA3D
  (SFc55_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c55_machineNumber, uint32_T
  c55_chartNumber, uint32_T c55_instanceNumber)
{
  (void)c55_machineNumber;
  (void)c55_chartNumber;
  (void)c55_instanceNumber;
}

static const mxArray *c55_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  int32_T c55_i11;
  real_T c55_b_inData[13];
  int32_T c55_i12;
  real_T c55_u[13];
  const mxArray *c55_y = NULL;
  SFc55_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc55_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  for (c55_i11 = 0; c55_i11 < 13; c55_i11++) {
    c55_b_inData[c55_i11] = (*(real_T (*)[13])c55_inData)[c55_i11];
  }

  for (c55_i12 = 0; c55_i12 < 13; c55_i12++) {
    c55_u[c55_i12] = c55_b_inData[c55_i12];
  }

  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", c55_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static void c55_emlrt_marshallIn(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c55_b_q, const char_T *c55_identifier, real_T
  c55_y[13])
{
  emlrtMsgIdentifier c55_thisId;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_b_q), &c55_thisId, c55_y);
  sf_mex_destroy(&c55_b_q);
}

static void c55_b_emlrt_marshallIn(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId,
  real_T c55_y[13])
{
  real_T c55_dv1[13];
  int32_T c55_i13;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), c55_dv1, 1, 0, 0U, 1, 0U, 1, 13);
  for (c55_i13 = 0; c55_i13 < 13; c55_i13++) {
    c55_y[c55_i13] = c55_dv1[c55_i13];
  }

  sf_mex_destroy(&c55_u);
}

static void c55_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData)
{
  const mxArray *c55_b_q;
  const char_T *c55_identifier;
  emlrtMsgIdentifier c55_thisId;
  real_T c55_y[13];
  int32_T c55_i14;
  SFc55_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc55_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c55_b_q = sf_mex_dup(c55_mxArrayInData);
  c55_identifier = c55_varName;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_b_q), &c55_thisId, c55_y);
  sf_mex_destroy(&c55_b_q);
  for (c55_i14 = 0; c55_i14 < 13; c55_i14++) {
    (*(real_T (*)[13])c55_outData)[c55_i14] = c55_y[c55_i14];
  }

  sf_mex_destroy(&c55_mxArrayInData);
}

static const mxArray *c55_b_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  int32_T c55_i15;
  real_T c55_b_inData[2];
  int32_T c55_i16;
  real_T c55_u[2];
  const mxArray *c55_y = NULL;
  SFc55_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc55_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  for (c55_i15 = 0; c55_i15 < 2; c55_i15++) {
    c55_b_inData[c55_i15] = (*(real_T (*)[2])c55_inData)[c55_i15];
  }

  for (c55_i16 = 0; c55_i16 < 2; c55_i16++) {
    c55_u[c55_i16] = c55_b_inData[c55_i16];
  }

  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", c55_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static const mxArray *c55_c_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  real_T c55_u;
  const mxArray *c55_y = NULL;
  SFc55_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc55_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  c55_u = *(real_T *)c55_inData;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", &c55_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static real_T c55_c_emlrt_marshallIn(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  real_T c55_y;
  real_T c55_d0;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_d0, 1, 0, 0U, 0, 0U, 0);
  c55_y = c55_d0;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void c55_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData)
{
  const mxArray *c55_nargout;
  const char_T *c55_identifier;
  emlrtMsgIdentifier c55_thisId;
  real_T c55_y;
  SFc55_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc55_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c55_nargout = sf_mex_dup(c55_mxArrayInData);
  c55_identifier = c55_varName;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_nargout),
    &c55_thisId);
  sf_mex_destroy(&c55_nargout);
  *(real_T *)c55_outData = c55_y;
  sf_mex_destroy(&c55_mxArrayInData);
}

const mxArray *sf_c55_Walking01_DDA3D_get_eml_resolved_functions_info(void)
{
  const mxArray *c55_nameCaptureInfo = NULL;
  c55_nameCaptureInfo = NULL;
  sf_mex_assign(&c55_nameCaptureInfo, sf_mex_createstruct("structure", 2, 34, 1),
                false);
  c55_info_helper(&c55_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c55_nameCaptureInfo);
  return c55_nameCaptureInfo;
}

static void c55_info_helper(const mxArray **c55_info)
{
  const mxArray *c55_rhs0 = NULL;
  const mxArray *c55_lhs0 = NULL;
  const mxArray *c55_rhs1 = NULL;
  const mxArray *c55_lhs1 = NULL;
  const mxArray *c55_rhs2 = NULL;
  const mxArray *c55_lhs2 = NULL;
  const mxArray *c55_rhs3 = NULL;
  const mxArray *c55_lhs3 = NULL;
  const mxArray *c55_rhs4 = NULL;
  const mxArray *c55_lhs4 = NULL;
  const mxArray *c55_rhs5 = NULL;
  const mxArray *c55_lhs5 = NULL;
  const mxArray *c55_rhs6 = NULL;
  const mxArray *c55_lhs6 = NULL;
  const mxArray *c55_rhs7 = NULL;
  const mxArray *c55_lhs7 = NULL;
  const mxArray *c55_rhs8 = NULL;
  const mxArray *c55_lhs8 = NULL;
  const mxArray *c55_rhs9 = NULL;
  const mxArray *c55_lhs9 = NULL;
  const mxArray *c55_rhs10 = NULL;
  const mxArray *c55_lhs10 = NULL;
  const mxArray *c55_rhs11 = NULL;
  const mxArray *c55_lhs11 = NULL;
  const mxArray *c55_rhs12 = NULL;
  const mxArray *c55_lhs12 = NULL;
  const mxArray *c55_rhs13 = NULL;
  const mxArray *c55_lhs13 = NULL;
  const mxArray *c55_rhs14 = NULL;
  const mxArray *c55_lhs14 = NULL;
  const mxArray *c55_rhs15 = NULL;
  const mxArray *c55_lhs15 = NULL;
  const mxArray *c55_rhs16 = NULL;
  const mxArray *c55_lhs16 = NULL;
  const mxArray *c55_rhs17 = NULL;
  const mxArray *c55_lhs17 = NULL;
  const mxArray *c55_rhs18 = NULL;
  const mxArray *c55_lhs18 = NULL;
  const mxArray *c55_rhs19 = NULL;
  const mxArray *c55_lhs19 = NULL;
  const mxArray *c55_rhs20 = NULL;
  const mxArray *c55_lhs20 = NULL;
  const mxArray *c55_rhs21 = NULL;
  const mxArray *c55_lhs21 = NULL;
  const mxArray *c55_rhs22 = NULL;
  const mxArray *c55_lhs22 = NULL;
  const mxArray *c55_rhs23 = NULL;
  const mxArray *c55_lhs23 = NULL;
  const mxArray *c55_rhs24 = NULL;
  const mxArray *c55_lhs24 = NULL;
  const mxArray *c55_rhs25 = NULL;
  const mxArray *c55_lhs25 = NULL;
  const mxArray *c55_rhs26 = NULL;
  const mxArray *c55_lhs26 = NULL;
  const mxArray *c55_rhs27 = NULL;
  const mxArray *c55_lhs27 = NULL;
  const mxArray *c55_rhs28 = NULL;
  const mxArray *c55_lhs28 = NULL;
  const mxArray *c55_rhs29 = NULL;
  const mxArray *c55_lhs29 = NULL;
  const mxArray *c55_rhs30 = NULL;
  const mxArray *c55_lhs30 = NULL;
  const mxArray *c55_rhs31 = NULL;
  const mxArray *c55_lhs31 = NULL;
  const mxArray *c55_rhs32 = NULL;
  const mxArray *c55_lhs32 = NULL;
  const mxArray *c55_rhs33 = NULL;
  const mxArray *c55_lhs33 = NULL;
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c55_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c55_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c55_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c55_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c55_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c55_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c55_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("colon"), "name", "name", 7);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c55_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("colon"), "name", "name", 8);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c55_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 9);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c55_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                  "context", "context", 10);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("isfinite"), "name", "name",
                  10);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c55_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c55_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("isinf"), "name", "name", 12);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c55_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c55_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("isnan"), "name", "name", 14);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c55_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 15);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c55_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                  "context", "context", 16);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("floor"), "name", "name", 16);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c55_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c55_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 18);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c55_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                  "context", "context", 19);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 19);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c55_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 20);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c55_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                  "context", "context", 21);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("flintmax"), "name", "name",
                  21);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1348213516U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c55_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 22);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c55_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                  "context", "context", 23);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("abs"), "name", "name", 23);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c55_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 24);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c55_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 25);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c55_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 26);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("realmax"), "name", "name",
                  26);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c55_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("eml_realmax"), "name",
                  "name", 27);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c55_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 28);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c55_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 29);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("mrdivide"), "name", "name",
                  29);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c55_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 30);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("floor"), "name", "name", 30);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c55_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 31);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 31);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c55_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 32);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("intmax"), "name", "name", 32);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c55_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 33);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c55_info, c55_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c55_info, c55_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c55_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c55_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c55_info, sf_mex_duplicatearraysafe(&c55_lhs33), "lhs", "lhs",
                  33);
  sf_mex_destroy(&c55_rhs0);
  sf_mex_destroy(&c55_lhs0);
  sf_mex_destroy(&c55_rhs1);
  sf_mex_destroy(&c55_lhs1);
  sf_mex_destroy(&c55_rhs2);
  sf_mex_destroy(&c55_lhs2);
  sf_mex_destroy(&c55_rhs3);
  sf_mex_destroy(&c55_lhs3);
  sf_mex_destroy(&c55_rhs4);
  sf_mex_destroy(&c55_lhs4);
  sf_mex_destroy(&c55_rhs5);
  sf_mex_destroy(&c55_lhs5);
  sf_mex_destroy(&c55_rhs6);
  sf_mex_destroy(&c55_lhs6);
  sf_mex_destroy(&c55_rhs7);
  sf_mex_destroy(&c55_lhs7);
  sf_mex_destroy(&c55_rhs8);
  sf_mex_destroy(&c55_lhs8);
  sf_mex_destroy(&c55_rhs9);
  sf_mex_destroy(&c55_lhs9);
  sf_mex_destroy(&c55_rhs10);
  sf_mex_destroy(&c55_lhs10);
  sf_mex_destroy(&c55_rhs11);
  sf_mex_destroy(&c55_lhs11);
  sf_mex_destroy(&c55_rhs12);
  sf_mex_destroy(&c55_lhs12);
  sf_mex_destroy(&c55_rhs13);
  sf_mex_destroy(&c55_lhs13);
  sf_mex_destroy(&c55_rhs14);
  sf_mex_destroy(&c55_lhs14);
  sf_mex_destroy(&c55_rhs15);
  sf_mex_destroy(&c55_lhs15);
  sf_mex_destroy(&c55_rhs16);
  sf_mex_destroy(&c55_lhs16);
  sf_mex_destroy(&c55_rhs17);
  sf_mex_destroy(&c55_lhs17);
  sf_mex_destroy(&c55_rhs18);
  sf_mex_destroy(&c55_lhs18);
  sf_mex_destroy(&c55_rhs19);
  sf_mex_destroy(&c55_lhs19);
  sf_mex_destroy(&c55_rhs20);
  sf_mex_destroy(&c55_lhs20);
  sf_mex_destroy(&c55_rhs21);
  sf_mex_destroy(&c55_lhs21);
  sf_mex_destroy(&c55_rhs22);
  sf_mex_destroy(&c55_lhs22);
  sf_mex_destroy(&c55_rhs23);
  sf_mex_destroy(&c55_lhs23);
  sf_mex_destroy(&c55_rhs24);
  sf_mex_destroy(&c55_lhs24);
  sf_mex_destroy(&c55_rhs25);
  sf_mex_destroy(&c55_lhs25);
  sf_mex_destroy(&c55_rhs26);
  sf_mex_destroy(&c55_lhs26);
  sf_mex_destroy(&c55_rhs27);
  sf_mex_destroy(&c55_lhs27);
  sf_mex_destroy(&c55_rhs28);
  sf_mex_destroy(&c55_lhs28);
  sf_mex_destroy(&c55_rhs29);
  sf_mex_destroy(&c55_lhs29);
  sf_mex_destroy(&c55_rhs30);
  sf_mex_destroy(&c55_lhs30);
  sf_mex_destroy(&c55_rhs31);
  sf_mex_destroy(&c55_lhs31);
  sf_mex_destroy(&c55_rhs32);
  sf_mex_destroy(&c55_lhs32);
  sf_mex_destroy(&c55_rhs33);
  sf_mex_destroy(&c55_lhs33);
}

static const mxArray *c55_emlrt_marshallOut(const char * c55_u)
{
  const mxArray *c55_y = NULL;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", c55_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c55_u)), false);
  return c55_y;
}

static const mxArray *c55_b_emlrt_marshallOut(const uint32_T c55_u)
{
  const mxArray *c55_y = NULL;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", &c55_u, 7, 0U, 0U, 0U, 0), false);
  return c55_y;
}

static void c55_realmax(SFc55_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c55_d_sf_marshallOut(void *chartInstanceVoid, void
  *c55_inData)
{
  const mxArray *c55_mxArrayOutData = NULL;
  int32_T c55_u;
  const mxArray *c55_y = NULL;
  SFc55_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc55_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c55_mxArrayOutData = NULL;
  c55_u = *(int32_T *)c55_inData;
  c55_y = NULL;
  sf_mex_assign(&c55_y, sf_mex_create("y", &c55_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c55_mxArrayOutData, c55_y, false);
  return c55_mxArrayOutData;
}

static int32_T c55_d_emlrt_marshallIn(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  int32_T c55_y;
  int32_T c55_i17;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_i17, 1, 6, 0U, 0, 0U, 0);
  c55_y = c55_i17;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void c55_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c55_mxArrayInData, const char_T *c55_varName, void *c55_outData)
{
  const mxArray *c55_b_sfEvent;
  const char_T *c55_identifier;
  emlrtMsgIdentifier c55_thisId;
  int32_T c55_y;
  SFc55_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc55_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c55_b_sfEvent = sf_mex_dup(c55_mxArrayInData);
  c55_identifier = c55_varName;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c55_b_sfEvent),
    &c55_thisId);
  sf_mex_destroy(&c55_b_sfEvent);
  *(int32_T *)c55_outData = c55_y;
  sf_mex_destroy(&c55_mxArrayInData);
}

static uint8_T c55_e_emlrt_marshallIn(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c55_b_is_active_c55_Walking01_DDA3D, const
  char_T *c55_identifier)
{
  uint8_T c55_y;
  emlrtMsgIdentifier c55_thisId;
  c55_thisId.fIdentifier = c55_identifier;
  c55_thisId.fParent = NULL;
  c55_y = c55_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c55_b_is_active_c55_Walking01_DDA3D), &c55_thisId);
  sf_mex_destroy(&c55_b_is_active_c55_Walking01_DDA3D);
  return c55_y;
}

static uint8_T c55_f_emlrt_marshallIn(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c55_u, const emlrtMsgIdentifier *c55_parentId)
{
  uint8_T c55_y;
  uint8_T c55_u0;
  (void)chartInstance;
  sf_mex_import(c55_parentId, sf_mex_dup(c55_u), &c55_u0, 1, 3, 0U, 0, 0U, 0);
  c55_y = c55_u0;
  sf_mex_destroy(&c55_u);
  return c55_y;
}

static void init_dsm_address_info(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc55_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c55_q_in = (real_T (*)[13])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c55_q = (real_T (*)[13])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c55_TorsoCOMOffsets = (real_T (*)[2])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
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

void sf_c55_Walking01_DDA3D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4174573390U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1068460647U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2142800626U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4034158958U);
}

mxArray* sf_c55_Walking01_DDA3D_get_post_codegen_info(void);
mxArray *sf_c55_Walking01_DDA3D_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("BiioFsR1miNQT6nxbkj4XH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(13);
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
      pr[0] = (double)(2);
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
      pr[0] = (double)(13);
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
    mxArray* mxPostCodegenInfo = sf_c55_Walking01_DDA3D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c55_Walking01_DDA3D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c55_Walking01_DDA3D_jit_fallback_info(void)
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

mxArray *sf_c55_Walking01_DDA3D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c55_Walking01_DDA3D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c55_Walking01_DDA3D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"q\",},{M[8],M[0],T\"is_active_c55_Walking01_DDA3D\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c55_Walking01_DDA3D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc55_Walking01_DDA3DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc55_Walking01_DDA3DInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_DDA3DMachineNumber_,
           55,
           1,
           1,
           0,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"q_in");
          _SFD_SET_DATA_PROPS(1,2,0,1,"q");
          _SFD_SET_DATA_PROPS(2,1,1,0,"TorsoCOMOffsets");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,407);

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c55_sf_marshallOut,(MexInFcnForType)
            c55_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c55_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c55_q_in);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c55_q);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c55_TorsoCOMOffsets);
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
  return "4rHvCGgzaPltmg9pfSHdYB";
}

static void sf_opaque_initialize_c55_Walking01_DDA3D(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc55_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c55_Walking01_DDA3D((SFc55_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
  initialize_c55_Walking01_DDA3D((SFc55_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c55_Walking01_DDA3D(void *chartInstanceVar)
{
  enable_c55_Walking01_DDA3D((SFc55_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c55_Walking01_DDA3D(void *chartInstanceVar)
{
  disable_c55_Walking01_DDA3D((SFc55_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c55_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_gateway_c55_Walking01_DDA3D((SFc55_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c55_Walking01_DDA3D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c55_Walking01_DDA3D((SFc55_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c55_Walking01_DDA3D(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c55_Walking01_DDA3D((SFc55_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c55_Walking01_DDA3D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc55_Walking01_DDA3DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_DDA3D_optimization_info();
    }

    finalize_c55_Walking01_DDA3D((SFc55_Walking01_DDA3DInstanceStruct*)
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
  initSimStructsc55_Walking01_DDA3D((SFc55_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c55_Walking01_DDA3D(SimStruct *S)
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
    initialize_params_c55_Walking01_DDA3D((SFc55_Walking01_DDA3DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c55_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      55);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,55,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,55,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,55);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,55,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,55,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,55);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(112397827U));
  ssSetChecksum1(S,(791483911U));
  ssSetChecksum2(S,(2933810466U));
  ssSetChecksum3(S,(4198409021U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c55_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c55_Walking01_DDA3D(SimStruct *S)
{
  SFc55_Walking01_DDA3DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc55_Walking01_DDA3DInstanceStruct *)utMalloc(sizeof
    (SFc55_Walking01_DDA3DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc55_Walking01_DDA3DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c55_Walking01_DDA3D;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c55_Walking01_DDA3D;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c55_Walking01_DDA3D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c55_Walking01_DDA3D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c55_Walking01_DDA3D;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c55_Walking01_DDA3D;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c55_Walking01_DDA3D;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c55_Walking01_DDA3D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c55_Walking01_DDA3D;
  chartInstance->chartInfo.mdlStart = mdlStart_c55_Walking01_DDA3D;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c55_Walking01_DDA3D;
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

void c55_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c55_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c55_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c55_Walking01_DDA3D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c55_Walking01_DDA3D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
