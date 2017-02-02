/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DDA2D_OSU3Dv2_sfun.h"
#include "c4_DDA2D_OSU3Dv2.h"
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
static const char * c4_debug_family_names[5] = { "nargin", "nargout", "xe", "q",
  "dq" };

/* Function Declarations */
static void initialize_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initialize_params_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct *
  chartInstance);
static void enable_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void disable_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c4_update_debugger_state_c4_DDA2D_OSU3Dv2
  (SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c4_DDA2D_OSU3Dv2
  (SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void set_sim_state_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c4_st);
static void finalize_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void sf_gateway_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void mdl_start_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initSimStructsc4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber);
static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData);
static void c4_emlrt_marshallIn(SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  const mxArray *c4_b_dq, const char_T *c4_identifier, real_T c4_y[13]);
static void c4_b_emlrt_marshallIn(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[13]);
static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static real_T c4_c_emlrt_marshallIn(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData);
static int32_T c4_d_emlrt_marshallIn(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData);
static uint8_T c4_e_emlrt_marshallIn(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_DDA2D_OSU3Dv2, const char_T
  *c4_identifier);
static uint8_T c4_f_emlrt_marshallIn(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId);
static void init_dsm_address_info(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c4_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c4_is_active_c4_DDA2D_OSU3Dv2 = 0U;
}

static void initialize_params_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c4_update_debugger_state_c4_DDA2D_OSU3Dv2
  (SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c4_DDA2D_OSU3Dv2
  (SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  const mxArray *c4_st;
  const mxArray *c4_y = NULL;
  int32_T c4_i0;
  real_T c4_u[13];
  const mxArray *c4_b_y = NULL;
  int32_T c4_i1;
  real_T c4_b_u[13];
  const mxArray *c4_c_y = NULL;
  uint8_T c4_hoistedGlobal;
  uint8_T c4_c_u;
  const mxArray *c4_d_y = NULL;
  c4_st = NULL;
  c4_st = NULL;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_createcellmatrix(3, 1), false);
  for (c4_i0 = 0; c4_i0 < 13; c4_i0++) {
    c4_u[c4_i0] = (*chartInstance->c4_dq)[c4_i0];
  }

  c4_b_y = NULL;
  sf_mex_assign(&c4_b_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_setcell(c4_y, 0, c4_b_y);
  for (c4_i1 = 0; c4_i1 < 13; c4_i1++) {
    c4_b_u[c4_i1] = (*chartInstance->c4_q)[c4_i1];
  }

  c4_c_y = NULL;
  sf_mex_assign(&c4_c_y, sf_mex_create("y", c4_b_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_setcell(c4_y, 1, c4_c_y);
  c4_hoistedGlobal = chartInstance->c4_is_active_c4_DDA2D_OSU3Dv2;
  c4_c_u = c4_hoistedGlobal;
  c4_d_y = NULL;
  sf_mex_assign(&c4_d_y, sf_mex_create("y", &c4_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c4_y, 2, c4_d_y);
  sf_mex_assign(&c4_st, c4_y, false);
  return c4_st;
}

static void set_sim_state_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c4_st)
{
  const mxArray *c4_u;
  real_T c4_dv0[13];
  int32_T c4_i2;
  real_T c4_dv1[13];
  int32_T c4_i3;
  chartInstance->c4_doneDoubleBufferReInit = true;
  c4_u = sf_mex_dup(c4_st);
  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 0)), "dq",
                      c4_dv0);
  for (c4_i2 = 0; c4_i2 < 13; c4_i2++) {
    (*chartInstance->c4_dq)[c4_i2] = c4_dv0[c4_i2];
  }

  c4_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 1)), "q",
                      c4_dv1);
  for (c4_i3 = 0; c4_i3 < 13; c4_i3++) {
    (*chartInstance->c4_q)[c4_i3] = c4_dv1[c4_i3];
  }

  chartInstance->c4_is_active_c4_DDA2D_OSU3Dv2 = c4_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c4_u, 2)),
     "is_active_c4_DDA2D_OSU3Dv2");
  sf_mex_destroy(&c4_u);
  c4_update_debugger_state_c4_DDA2D_OSU3Dv2(chartInstance);
  sf_mex_destroy(&c4_st);
}

static void finalize_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  int32_T c4_i4;
  int32_T c4_i5;
  real_T c4_b_xe[32];
  uint32_T c4_debug_family_var_map[5];
  real_T c4_nargin = 1.0;
  real_T c4_nargout = 2.0;
  real_T c4_b_q[13];
  real_T c4_b_dq[13];
  int32_T c4_i6;
  int32_T c4_i7;
  int32_T c4_i8;
  int32_T c4_i9;
  int32_T c4_i10;
  int32_T c4_i11;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  for (c4_i4 = 0; c4_i4 < 32; c4_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_xe)[c4_i4], 0U);
  }

  chartInstance->c4_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  for (c4_i5 = 0; c4_i5 < 32; c4_i5++) {
    c4_b_xe[c4_i5] = (*chartInstance->c4_xe)[c4_i5];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c4_debug_family_names,
    c4_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargin, 0U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c4_nargout, 1U, c4_c_sf_marshallOut,
    c4_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c4_b_xe, 2U, c4_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_q, 3U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c4_b_dq, 4U, c4_sf_marshallOut,
    c4_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 3);
  for (c4_i6 = 0; c4_i6 < 13; c4_i6++) {
    c4_b_q[c4_i6] = c4_b_xe[c4_i6 + 3];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, 4);
  for (c4_i7 = 0; c4_i7 < 13; c4_i7++) {
    c4_b_dq[c4_i7] = c4_b_xe[c4_i7 + 19];
  }

  _SFD_EML_CALL(0U, chartInstance->c4_sfEvent, -4);
  _SFD_SYMBOL_SCOPE_POP();
  for (c4_i8 = 0; c4_i8 < 13; c4_i8++) {
    (*chartInstance->c4_q)[c4_i8] = c4_b_q[c4_i8];
  }

  for (c4_i9 = 0; c4_i9 < 13; c4_i9++) {
    (*chartInstance->c4_dq)[c4_i9] = c4_b_dq[c4_i9];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c4_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DDA2D_OSU3Dv2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c4_i10 = 0; c4_i10 < 13; c4_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_q)[c4_i10], 1U);
  }

  for (c4_i11 = 0; c4_i11 < 13; c4_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c4_dq)[c4_i11], 2U);
  }
}

static void mdl_start_c4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc4_DDA2D_OSU3Dv2(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c4_machineNumber, uint32_T
  c4_chartNumber, uint32_T c4_instanceNumber)
{
  (void)c4_machineNumber;
  (void)c4_chartNumber;
  (void)c4_instanceNumber;
}

static const mxArray *c4_sf_marshallOut(void *chartInstanceVoid, void *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i12;
  real_T c4_b_inData[13];
  int32_T c4_i13;
  real_T c4_u[13];
  const mxArray *c4_y = NULL;
  SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc4_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i12 = 0; c4_i12 < 13; c4_i12++) {
    c4_b_inData[c4_i12] = (*(real_T (*)[13])c4_inData)[c4_i12];
  }

  for (c4_i13 = 0; c4_i13 < 13; c4_i13++) {
    c4_u[c4_i13] = c4_b_inData[c4_i13];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static void c4_emlrt_marshallIn(SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  const mxArray *c4_b_dq, const char_T *c4_identifier, real_T c4_y[13])
{
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_dq), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_dq);
}

static void c4_b_emlrt_marshallIn(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId,
  real_T c4_y[13])
{
  real_T c4_dv2[13];
  int32_T c4_i14;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), c4_dv2, 1, 0, 0U, 1, 0U, 1, 13);
  for (c4_i14 = 0; c4_i14 < 13; c4_i14++) {
    c4_y[c4_i14] = c4_dv2[c4_i14];
  }

  sf_mex_destroy(&c4_u);
}

static void c4_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_dq;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y[13];
  int32_T c4_i15;
  SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc4_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c4_b_dq = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_dq), &c4_thisId, c4_y);
  sf_mex_destroy(&c4_b_dq);
  for (c4_i15 = 0; c4_i15 < 13; c4_i15++) {
    (*(real_T (*)[13])c4_outData)[c4_i15] = c4_y[c4_i15];
  }

  sf_mex_destroy(&c4_mxArrayInData);
}

static const mxArray *c4_b_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_i16;
  real_T c4_b_inData[32];
  int32_T c4_i17;
  real_T c4_u[32];
  const mxArray *c4_y = NULL;
  SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc4_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  for (c4_i16 = 0; c4_i16 < 32; c4_i16++) {
    c4_b_inData[c4_i16] = (*(real_T (*)[32])c4_inData)[c4_i16];
  }

  for (c4_i17 = 0; c4_i17 < 32; c4_i17++) {
    c4_u[c4_i17] = c4_b_inData[c4_i17];
  }

  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", c4_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static const mxArray *c4_c_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  real_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc4_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(real_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static real_T c4_c_emlrt_marshallIn(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  real_T c4_y;
  real_T c4_d0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_d0, 1, 0, 0U, 0, 0U, 0);
  c4_y = c4_d0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_nargout;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  real_T c4_y;
  SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc4_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c4_nargout = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_nargout), &c4_thisId);
  sf_mex_destroy(&c4_nargout);
  *(real_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

const mxArray *sf_c4_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void)
{
  const mxArray *c4_nameCaptureInfo = NULL;
  c4_nameCaptureInfo = NULL;
  sf_mex_assign(&c4_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c4_nameCaptureInfo;
}

static const mxArray *c4_d_sf_marshallOut(void *chartInstanceVoid, void
  *c4_inData)
{
  const mxArray *c4_mxArrayOutData = NULL;
  int32_T c4_u;
  const mxArray *c4_y = NULL;
  SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc4_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c4_mxArrayOutData = NULL;
  c4_u = *(int32_T *)c4_inData;
  c4_y = NULL;
  sf_mex_assign(&c4_y, sf_mex_create("y", &c4_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c4_mxArrayOutData, c4_y, false);
  return c4_mxArrayOutData;
}

static int32_T c4_d_emlrt_marshallIn(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  int32_T c4_y;
  int32_T c4_i18;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_i18, 1, 6, 0U, 0, 0U, 0);
  c4_y = c4_i18;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void c4_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c4_mxArrayInData, const char_T *c4_varName, void *c4_outData)
{
  const mxArray *c4_b_sfEvent;
  const char_T *c4_identifier;
  emlrtMsgIdentifier c4_thisId;
  int32_T c4_y;
  SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc4_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c4_b_sfEvent = sf_mex_dup(c4_mxArrayInData);
  c4_identifier = c4_varName;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c4_b_sfEvent),
    &c4_thisId);
  sf_mex_destroy(&c4_b_sfEvent);
  *(int32_T *)c4_outData = c4_y;
  sf_mex_destroy(&c4_mxArrayInData);
}

static uint8_T c4_e_emlrt_marshallIn(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c4_b_is_active_c4_DDA2D_OSU3Dv2, const char_T
  *c4_identifier)
{
  uint8_T c4_y;
  emlrtMsgIdentifier c4_thisId;
  c4_thisId.fIdentifier = c4_identifier;
  c4_thisId.fParent = NULL;
  c4_y = c4_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c4_b_is_active_c4_DDA2D_OSU3Dv2), &c4_thisId);
  sf_mex_destroy(&c4_b_is_active_c4_DDA2D_OSU3Dv2);
  return c4_y;
}

static uint8_T c4_f_emlrt_marshallIn(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c4_u, const emlrtMsgIdentifier *c4_parentId)
{
  uint8_T c4_y;
  uint8_T c4_u0;
  (void)chartInstance;
  sf_mex_import(c4_parentId, sf_mex_dup(c4_u), &c4_u0, 1, 3, 0U, 0, 0U, 0);
  c4_y = c4_u0;
  sf_mex_destroy(&c4_u);
  return c4_y;
}

static void init_dsm_address_info(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc4_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c4_xe = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c4_q = (real_T (*)[13])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c4_dq = (real_T (*)[13])ssGetOutputPortSignal_wrapper
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

void sf_c4_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3287576717U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3313631517U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(4050890828U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(356560001U);
}

mxArray* sf_c4_DDA2D_OSU3Dv2_get_post_codegen_info(void);
mxArray *sf_c4_DDA2D_OSU3Dv2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("tzhUsPcxCAlzxo8JLTsA8B");
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c4_DDA2D_OSU3Dv2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c4_DDA2D_OSU3Dv2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c4_DDA2D_OSU3Dv2_jit_fallback_info(void)
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

mxArray *sf_c4_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c4_DDA2D_OSU3Dv2_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c4_DDA2D_OSU3Dv2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[6],T\"dq\",},{M[1],M[5],T\"q\",},{M[8],M[0],T\"is_active_c4_DDA2D_OSU3Dv2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c4_DDA2D_OSU3Dv2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc4_DDA2D_OSU3Dv2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DDA2D_OSU3Dv2MachineNumber_,
           4,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"xe");
          _SFD_SET_DATA_PROPS(1,2,0,1,"q");
          _SFD_SET_DATA_PROPS(2,2,0,1,"dq");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,74);

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c4_sf_marshallOut,(MexInFcnForType)
            c4_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c4_xe);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c4_q);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c4_dq);
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
  return "xVky7YK8spNffnrxsYZf9E";
}

static void sf_opaque_initialize_c4_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc4_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c4_DDA2D_OSU3Dv2((SFc4_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
  initialize_c4_DDA2D_OSU3Dv2((SFc4_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c4_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  enable_c4_DDA2D_OSU3Dv2((SFc4_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c4_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  disable_c4_DDA2D_OSU3Dv2((SFc4_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c4_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  sf_gateway_c4_DDA2D_OSU3Dv2((SFc4_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c4_DDA2D_OSU3Dv2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c4_DDA2D_OSU3Dv2((SFc4_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c4_DDA2D_OSU3Dv2(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c4_DDA2D_OSU3Dv2((SFc4_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c4_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc4_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DDA2D_OSU3Dv2_optimization_info();
    }

    finalize_c4_DDA2D_OSU3Dv2((SFc4_DDA2D_OSU3Dv2InstanceStruct*)
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
  initSimStructsc4_DDA2D_OSU3Dv2((SFc4_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c4_DDA2D_OSU3Dv2(SimStruct *S)
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
    initialize_params_c4_DDA2D_OSU3Dv2((SFc4_DDA2D_OSU3Dv2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c4_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DDA2D_OSU3Dv2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,4);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,4,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,4,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,4);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,4,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,4,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,4);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(177186185U));
  ssSetChecksum1(S,(3686353369U));
  ssSetChecksum2(S,(3352201843U));
  ssSetChecksum3(S,(2632123031U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c4_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c4_DDA2D_OSU3Dv2(SimStruct *S)
{
  SFc4_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc4_DDA2D_OSU3Dv2InstanceStruct *)utMalloc(sizeof
    (SFc4_DDA2D_OSU3Dv2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc4_DDA2D_OSU3Dv2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c4_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c4_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c4_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c4_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c4_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c4_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c4_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c4_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c4_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlStart = mdlStart_c4_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c4_DDA2D_OSU3Dv2;
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

void c4_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c4_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c4_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c4_DDA2D_OSU3Dv2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c4_DDA2D_OSU3Dv2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
