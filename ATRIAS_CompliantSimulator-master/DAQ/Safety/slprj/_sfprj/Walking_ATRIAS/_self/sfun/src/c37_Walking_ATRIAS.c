/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking_ATRIAS_sfun.h"
#include "c37_Walking_ATRIAS.h"
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
static const char * c37_debug_family_names[7] = { "MOTOR_VOLTAGE_C_OFFSET",
  "MOTOR_VOLTAGE_V_CAL", "MOTOR_VOLTAGE_C_CAL", "nargin", "nargout", "adc_value",
  "motorVoltage" };

/* Function Declarations */
static void initialize_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance);
static void initialize_params_c37_Walking_ATRIAS
  (SFc37_Walking_ATRIASInstanceStruct *chartInstance);
static void enable_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance);
static void disable_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance);
static void c37_update_debugger_state_c37_Walking_ATRIAS
  (SFc37_Walking_ATRIASInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c37_Walking_ATRIAS
  (SFc37_Walking_ATRIASInstanceStruct *chartInstance);
static void set_sim_state_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c37_st);
static void finalize_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance);
static void sf_gateway_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance);
static void mdl_start_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance);
static void initSimStructsc37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c37_machineNumber, uint32_T
  c37_chartNumber, uint32_T c37_instanceNumber);
static const mxArray *c37_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData);
static void c37_emlrt_marshallIn(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c37_b_motorVoltage, const char_T
  *c37_identifier, real_T c37_y[6]);
static void c37_b_emlrt_marshallIn(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId,
  real_T c37_y[6]);
static void c37_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData);
static const mxArray *c37_b_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData);
static real_T c37_c_emlrt_marshallIn(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId);
static void c37_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData);
static void c37_info_helper(const mxArray **c37_info);
static const mxArray *c37_emlrt_marshallOut(const char * c37_u);
static const mxArray *c37_b_emlrt_marshallOut(const uint32_T c37_u);
static const mxArray *c37_c_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData);
static int32_T c37_d_emlrt_marshallIn(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId);
static void c37_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData);
static uint8_T c37_e_emlrt_marshallIn(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c37_b_is_active_c37_Walking_ATRIAS, const
  char_T *c37_identifier);
static uint8_T c37_f_emlrt_marshallIn(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId);
static void init_dsm_address_info(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  chartInstance->c37_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c37_is_active_c37_Walking_ATRIAS = 0U;
}

static void initialize_params_c37_Walking_ATRIAS
  (SFc37_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c37_update_debugger_state_c37_Walking_ATRIAS
  (SFc37_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c37_Walking_ATRIAS
  (SFc37_Walking_ATRIASInstanceStruct *chartInstance)
{
  const mxArray *c37_st;
  const mxArray *c37_y = NULL;
  int32_T c37_i0;
  real_T c37_u[6];
  const mxArray *c37_b_y = NULL;
  uint8_T c37_hoistedGlobal;
  uint8_T c37_b_u;
  const mxArray *c37_c_y = NULL;
  c37_st = NULL;
  c37_st = NULL;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_createcellmatrix(2, 1), false);
  for (c37_i0 = 0; c37_i0 < 6; c37_i0++) {
    c37_u[c37_i0] = (*chartInstance->c37_motorVoltage)[c37_i0];
  }

  c37_b_y = NULL;
  sf_mex_assign(&c37_b_y, sf_mex_create("y", c37_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c37_y, 0, c37_b_y);
  c37_hoistedGlobal = chartInstance->c37_is_active_c37_Walking_ATRIAS;
  c37_b_u = c37_hoistedGlobal;
  c37_c_y = NULL;
  sf_mex_assign(&c37_c_y, sf_mex_create("y", &c37_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c37_y, 1, c37_c_y);
  sf_mex_assign(&c37_st, c37_y, false);
  return c37_st;
}

static void set_sim_state_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c37_st)
{
  const mxArray *c37_u;
  real_T c37_dv0[6];
  int32_T c37_i1;
  chartInstance->c37_doneDoubleBufferReInit = true;
  c37_u = sf_mex_dup(c37_st);
  c37_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c37_u, 0)),
                       "motorVoltage", c37_dv0);
  for (c37_i1 = 0; c37_i1 < 6; c37_i1++) {
    (*chartInstance->c37_motorVoltage)[c37_i1] = c37_dv0[c37_i1];
  }

  chartInstance->c37_is_active_c37_Walking_ATRIAS = c37_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c37_u, 1)),
     "is_active_c37_Walking_ATRIAS");
  sf_mex_destroy(&c37_u);
  c37_update_debugger_state_c37_Walking_ATRIAS(chartInstance);
  sf_mex_destroy(&c37_st);
}

static void finalize_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  int32_T c37_i2;
  int32_T c37_i3;
  real_T c37_b_adc_value[6];
  uint32_T c37_debug_family_var_map[7];
  real_T c37_MOTOR_VOLTAGE_C_OFFSET;
  real_T c37_MOTOR_VOLTAGE_V_CAL;
  real_T c37_MOTOR_VOLTAGE_C_CAL;
  real_T c37_nargin = 1.0;
  real_T c37_nargout = 1.0;
  real_T c37_b_motorVoltage[6];
  int32_T c37_i4;
  real_T c37_a[6];
  int32_T c37_i5;
  int32_T c37_i6;
  int32_T c37_i7;
  int32_T c37_i8;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, chartInstance->c37_sfEvent);
  for (c37_i2 = 0; c37_i2 < 6; c37_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c37_adc_value)[c37_i2], 0U);
  }

  chartInstance->c37_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, chartInstance->c37_sfEvent);
  for (c37_i3 = 0; c37_i3 < 6; c37_i3++) {
    c37_b_adc_value[c37_i3] = (*chartInstance->c37_adc_value)[c37_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c37_debug_family_names,
    c37_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_MOTOR_VOLTAGE_C_OFFSET, 0U,
    c37_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_MOTOR_VOLTAGE_V_CAL, 1U, c37_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c37_MOTOR_VOLTAGE_C_CAL, 2U, c37_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_nargin, 3U, c37_b_sf_marshallOut,
    c37_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c37_nargout, 4U, c37_b_sf_marshallOut,
    c37_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c37_b_adc_value, 5U, c37_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c37_b_motorVoltage, 6U,
    c37_sf_marshallOut, c37_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 4);
  c37_MOTOR_VOLTAGE_C_OFFSET = 1300.0;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 5);
  c37_MOTOR_VOLTAGE_V_CAL = 60.2;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 6);
  c37_MOTOR_VOLTAGE_C_CAL = 3600.0;
  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, 8);
  for (c37_i4 = 0; c37_i4 < 6; c37_i4++) {
    c37_a[c37_i4] = c37_b_adc_value[c37_i4] - c37_MOTOR_VOLTAGE_C_OFFSET;
  }

  for (c37_i5 = 0; c37_i5 < 6; c37_i5++) {
    c37_a[c37_i5] *= 60.2;
  }

  for (c37_i6 = 0; c37_i6 < 6; c37_i6++) {
    c37_b_motorVoltage[c37_i6] = c37_a[c37_i6] / 2300.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c37_sfEvent, -8);
  _SFD_SYMBOL_SCOPE_POP();
  for (c37_i7 = 0; c37_i7 < 6; c37_i7++) {
    (*chartInstance->c37_motorVoltage)[c37_i7] = c37_b_motorVoltage[c37_i7];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, chartInstance->c37_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking_ATRIASMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c37_i8 = 0; c37_i8 < 6; c37_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c37_motorVoltage)[c37_i8], 1U);
  }
}

static void mdl_start_c37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc37_Walking_ATRIAS(SFc37_Walking_ATRIASInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c37_machineNumber, uint32_T
  c37_chartNumber, uint32_T c37_instanceNumber)
{
  (void)c37_machineNumber;
  (void)c37_chartNumber;
  (void)c37_instanceNumber;
}

static const mxArray *c37_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData)
{
  const mxArray *c37_mxArrayOutData = NULL;
  int32_T c37_i9;
  real_T c37_b_inData[6];
  int32_T c37_i10;
  real_T c37_u[6];
  const mxArray *c37_y = NULL;
  SFc37_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc37_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c37_mxArrayOutData = NULL;
  for (c37_i9 = 0; c37_i9 < 6; c37_i9++) {
    c37_b_inData[c37_i9] = (*(real_T (*)[6])c37_inData)[c37_i9];
  }

  for (c37_i10 = 0; c37_i10 < 6; c37_i10++) {
    c37_u[c37_i10] = c37_b_inData[c37_i10];
  }

  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_create("y", c37_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c37_mxArrayOutData, c37_y, false);
  return c37_mxArrayOutData;
}

static void c37_emlrt_marshallIn(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c37_b_motorVoltage, const char_T
  *c37_identifier, real_T c37_y[6])
{
  emlrtMsgIdentifier c37_thisId;
  c37_thisId.fIdentifier = c37_identifier;
  c37_thisId.fParent = NULL;
  c37_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c37_b_motorVoltage),
    &c37_thisId, c37_y);
  sf_mex_destroy(&c37_b_motorVoltage);
}

static void c37_b_emlrt_marshallIn(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId,
  real_T c37_y[6])
{
  real_T c37_dv1[6];
  int32_T c37_i11;
  (void)chartInstance;
  sf_mex_import(c37_parentId, sf_mex_dup(c37_u), c37_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c37_i11 = 0; c37_i11 < 6; c37_i11++) {
    c37_y[c37_i11] = c37_dv1[c37_i11];
  }

  sf_mex_destroy(&c37_u);
}

static void c37_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData)
{
  const mxArray *c37_b_motorVoltage;
  const char_T *c37_identifier;
  emlrtMsgIdentifier c37_thisId;
  real_T c37_y[6];
  int32_T c37_i12;
  SFc37_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc37_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c37_b_motorVoltage = sf_mex_dup(c37_mxArrayInData);
  c37_identifier = c37_varName;
  c37_thisId.fIdentifier = c37_identifier;
  c37_thisId.fParent = NULL;
  c37_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c37_b_motorVoltage),
    &c37_thisId, c37_y);
  sf_mex_destroy(&c37_b_motorVoltage);
  for (c37_i12 = 0; c37_i12 < 6; c37_i12++) {
    (*(real_T (*)[6])c37_outData)[c37_i12] = c37_y[c37_i12];
  }

  sf_mex_destroy(&c37_mxArrayInData);
}

static const mxArray *c37_b_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData)
{
  const mxArray *c37_mxArrayOutData = NULL;
  real_T c37_u;
  const mxArray *c37_y = NULL;
  SFc37_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc37_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c37_mxArrayOutData = NULL;
  c37_u = *(real_T *)c37_inData;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_create("y", &c37_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c37_mxArrayOutData, c37_y, false);
  return c37_mxArrayOutData;
}

static real_T c37_c_emlrt_marshallIn(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId)
{
  real_T c37_y;
  real_T c37_d0;
  (void)chartInstance;
  sf_mex_import(c37_parentId, sf_mex_dup(c37_u), &c37_d0, 1, 0, 0U, 0, 0U, 0);
  c37_y = c37_d0;
  sf_mex_destroy(&c37_u);
  return c37_y;
}

static void c37_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData)
{
  const mxArray *c37_nargout;
  const char_T *c37_identifier;
  emlrtMsgIdentifier c37_thisId;
  real_T c37_y;
  SFc37_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc37_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c37_nargout = sf_mex_dup(c37_mxArrayInData);
  c37_identifier = c37_varName;
  c37_thisId.fIdentifier = c37_identifier;
  c37_thisId.fParent = NULL;
  c37_y = c37_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c37_nargout),
    &c37_thisId);
  sf_mex_destroy(&c37_nargout);
  *(real_T *)c37_outData = c37_y;
  sf_mex_destroy(&c37_mxArrayInData);
}

const mxArray *sf_c37_Walking_ATRIAS_get_eml_resolved_functions_info(void)
{
  const mxArray *c37_nameCaptureInfo = NULL;
  c37_nameCaptureInfo = NULL;
  sf_mex_assign(&c37_nameCaptureInfo, sf_mex_createstruct("structure", 2, 9, 1),
                false);
  c37_info_helper(&c37_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c37_nameCaptureInfo);
  return c37_nameCaptureInfo;
}

static void c37_info_helper(const mxArray **c37_info)
{
  const mxArray *c37_rhs0 = NULL;
  const mxArray *c37_lhs0 = NULL;
  const mxArray *c37_rhs1 = NULL;
  const mxArray *c37_lhs1 = NULL;
  const mxArray *c37_rhs2 = NULL;
  const mxArray *c37_lhs2 = NULL;
  const mxArray *c37_rhs3 = NULL;
  const mxArray *c37_lhs3 = NULL;
  const mxArray *c37_rhs4 = NULL;
  const mxArray *c37_lhs4 = NULL;
  const mxArray *c37_rhs5 = NULL;
  const mxArray *c37_lhs5 = NULL;
  const mxArray *c37_rhs6 = NULL;
  const mxArray *c37_lhs6 = NULL;
  const mxArray *c37_rhs7 = NULL;
  const mxArray *c37_lhs7 = NULL;
  const mxArray *c37_rhs8 = NULL;
  const mxArray *c37_lhs8 = NULL;
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c37_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c37_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c37_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c37_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(""), "context", "context", 2);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("mrdivide"), "name", "name",
                  2);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c37_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c37_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 3);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c37_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c37_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 4);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("rdivide"), "name", "name", 4);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c37_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c37_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c37_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c37_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 6);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c37_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c37_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("eml_div"), "name", "name", 7);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c37_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c37_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 8);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c37_info, c37_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c37_info, c37_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c37_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c37_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c37_info, sf_mex_duplicatearraysafe(&c37_lhs8), "lhs", "lhs",
                  8);
  sf_mex_destroy(&c37_rhs0);
  sf_mex_destroy(&c37_lhs0);
  sf_mex_destroy(&c37_rhs1);
  sf_mex_destroy(&c37_lhs1);
  sf_mex_destroy(&c37_rhs2);
  sf_mex_destroy(&c37_lhs2);
  sf_mex_destroy(&c37_rhs3);
  sf_mex_destroy(&c37_lhs3);
  sf_mex_destroy(&c37_rhs4);
  sf_mex_destroy(&c37_lhs4);
  sf_mex_destroy(&c37_rhs5);
  sf_mex_destroy(&c37_lhs5);
  sf_mex_destroy(&c37_rhs6);
  sf_mex_destroy(&c37_lhs6);
  sf_mex_destroy(&c37_rhs7);
  sf_mex_destroy(&c37_lhs7);
  sf_mex_destroy(&c37_rhs8);
  sf_mex_destroy(&c37_lhs8);
}

static const mxArray *c37_emlrt_marshallOut(const char * c37_u)
{
  const mxArray *c37_y = NULL;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_create("y", c37_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c37_u)), false);
  return c37_y;
}

static const mxArray *c37_b_emlrt_marshallOut(const uint32_T c37_u)
{
  const mxArray *c37_y = NULL;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_create("y", &c37_u, 7, 0U, 0U, 0U, 0), false);
  return c37_y;
}

static const mxArray *c37_c_sf_marshallOut(void *chartInstanceVoid, void
  *c37_inData)
{
  const mxArray *c37_mxArrayOutData = NULL;
  int32_T c37_u;
  const mxArray *c37_y = NULL;
  SFc37_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc37_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c37_mxArrayOutData = NULL;
  c37_u = *(int32_T *)c37_inData;
  c37_y = NULL;
  sf_mex_assign(&c37_y, sf_mex_create("y", &c37_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c37_mxArrayOutData, c37_y, false);
  return c37_mxArrayOutData;
}

static int32_T c37_d_emlrt_marshallIn(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId)
{
  int32_T c37_y;
  int32_T c37_i13;
  (void)chartInstance;
  sf_mex_import(c37_parentId, sf_mex_dup(c37_u), &c37_i13, 1, 6, 0U, 0, 0U, 0);
  c37_y = c37_i13;
  sf_mex_destroy(&c37_u);
  return c37_y;
}

static void c37_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c37_mxArrayInData, const char_T *c37_varName, void *c37_outData)
{
  const mxArray *c37_b_sfEvent;
  const char_T *c37_identifier;
  emlrtMsgIdentifier c37_thisId;
  int32_T c37_y;
  SFc37_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc37_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c37_b_sfEvent = sf_mex_dup(c37_mxArrayInData);
  c37_identifier = c37_varName;
  c37_thisId.fIdentifier = c37_identifier;
  c37_thisId.fParent = NULL;
  c37_y = c37_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c37_b_sfEvent),
    &c37_thisId);
  sf_mex_destroy(&c37_b_sfEvent);
  *(int32_T *)c37_outData = c37_y;
  sf_mex_destroy(&c37_mxArrayInData);
}

static uint8_T c37_e_emlrt_marshallIn(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c37_b_is_active_c37_Walking_ATRIAS, const
  char_T *c37_identifier)
{
  uint8_T c37_y;
  emlrtMsgIdentifier c37_thisId;
  c37_thisId.fIdentifier = c37_identifier;
  c37_thisId.fParent = NULL;
  c37_y = c37_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c37_b_is_active_c37_Walking_ATRIAS), &c37_thisId);
  sf_mex_destroy(&c37_b_is_active_c37_Walking_ATRIAS);
  return c37_y;
}

static uint8_T c37_f_emlrt_marshallIn(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c37_u, const emlrtMsgIdentifier *c37_parentId)
{
  uint8_T c37_y;
  uint8_T c37_u0;
  (void)chartInstance;
  sf_mex_import(c37_parentId, sf_mex_dup(c37_u), &c37_u0, 1, 3, 0U, 0, 0U, 0);
  c37_y = c37_u0;
  sf_mex_destroy(&c37_u);
  return c37_y;
}

static void init_dsm_address_info(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc37_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  chartInstance->c37_adc_value = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c37_motorVoltage = (real_T (*)[6])ssGetOutputPortSignal_wrapper
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

void sf_c37_Walking_ATRIAS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2148929927U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2723281463U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(653572107U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(789597746U);
}

mxArray* sf_c37_Walking_ATRIAS_get_post_codegen_info(void);
mxArray *sf_c37_Walking_ATRIAS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("kRjh6w16qR2ajJq3FHwusF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
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
    mxArray* mxPostCodegenInfo = sf_c37_Walking_ATRIAS_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c37_Walking_ATRIAS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c37_Walking_ATRIAS_jit_fallback_info(void)
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

mxArray *sf_c37_Walking_ATRIAS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c37_Walking_ATRIAS_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c37_Walking_ATRIAS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"motorVoltage\",},{M[8],M[0],T\"is_active_c37_Walking_ATRIAS\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c37_Walking_ATRIAS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc37_Walking_ATRIASInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc37_Walking_ATRIASInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking_ATRIASMachineNumber_,
           37,
           1,
           1,
           0,
           2,
           0,
           0,
           0,
           0,
           0,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"adc_value");
          _SFD_SET_DATA_PROPS(1,2,0,1,"motorVoltage");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,310);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c37_sf_marshallOut,(MexInFcnForType)
            c37_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c37_adc_value);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c37_motorVoltage);
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
  return "ctmA7vBYMeRwVpCT8K4e7C";
}

static void sf_opaque_initialize_c37_Walking_ATRIAS(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc37_Walking_ATRIASInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c37_Walking_ATRIAS((SFc37_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
  initialize_c37_Walking_ATRIAS((SFc37_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c37_Walking_ATRIAS(void *chartInstanceVar)
{
  enable_c37_Walking_ATRIAS((SFc37_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c37_Walking_ATRIAS(void *chartInstanceVar)
{
  disable_c37_Walking_ATRIAS((SFc37_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c37_Walking_ATRIAS(void *chartInstanceVar)
{
  sf_gateway_c37_Walking_ATRIAS((SFc37_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c37_Walking_ATRIAS(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c37_Walking_ATRIAS((SFc37_Walking_ATRIASInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c37_Walking_ATRIAS(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c37_Walking_ATRIAS((SFc37_Walking_ATRIASInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c37_Walking_ATRIAS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc37_Walking_ATRIASInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking_ATRIAS_optimization_info();
    }

    finalize_c37_Walking_ATRIAS((SFc37_Walking_ATRIASInstanceStruct*)
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
  initSimStructsc37_Walking_ATRIAS((SFc37_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c37_Walking_ATRIAS(SimStruct *S)
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
    initialize_params_c37_Walking_ATRIAS((SFc37_Walking_ATRIASInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c37_Walking_ATRIAS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking_ATRIAS_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      37);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,37,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,37,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,37);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,37,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,37,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,37);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3369709500U));
  ssSetChecksum1(S,(1863383741U));
  ssSetChecksum2(S,(1572324318U));
  ssSetChecksum3(S,(2723074052U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c37_Walking_ATRIAS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c37_Walking_ATRIAS(SimStruct *S)
{
  SFc37_Walking_ATRIASInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc37_Walking_ATRIASInstanceStruct *)utMalloc(sizeof
    (SFc37_Walking_ATRIASInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc37_Walking_ATRIASInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c37_Walking_ATRIAS;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c37_Walking_ATRIAS;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c37_Walking_ATRIAS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c37_Walking_ATRIAS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c37_Walking_ATRIAS;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c37_Walking_ATRIAS;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c37_Walking_ATRIAS;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c37_Walking_ATRIAS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c37_Walking_ATRIAS;
  chartInstance->chartInfo.mdlStart = mdlStart_c37_Walking_ATRIAS;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c37_Walking_ATRIAS;
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

void c37_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c37_Walking_ATRIAS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c37_Walking_ATRIAS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c37_Walking_ATRIAS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c37_Walking_ATRIAS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
