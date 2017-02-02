/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking_ATRIAS_sfun.h"
#include "c59_Walking_ATRIAS.h"
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
static const char * c59_debug_family_names[13] = { "nargin", "nargout",
  "EncoderAngles", "EncoderVelocities", "IMUAngles", "IMUVelocities",
  "UseMotorIncEncoders", "UseIMU", "IMUTorsoOffset", "GearOffset", "Reset",
  "q_clean", "dq_clean" };

/* Function Declarations */
static void initialize_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance);
static void initialize_params_c59_Walking_ATRIAS
  (SFc59_Walking_ATRIASInstanceStruct *chartInstance);
static void enable_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance);
static void disable_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance);
static void c59_update_debugger_state_c59_Walking_ATRIAS
  (SFc59_Walking_ATRIASInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c59_Walking_ATRIAS
  (SFc59_Walking_ATRIASInstanceStruct *chartInstance);
static void set_sim_state_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c59_st);
static void finalize_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance);
static void sf_gateway_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance);
static void mdl_start_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance);
static void c59_chartstep_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct *
  chartInstance);
static void initSimStructsc59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c59_machineNumber, uint32_T
  c59_chartNumber, uint32_T c59_instanceNumber);
static const mxArray *c59_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData);
static void c59_emlrt_marshallIn(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c59_b_dq_clean, const char_T *c59_identifier,
  real_T c59_y[13]);
static void c59_b_emlrt_marshallIn(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId,
  real_T c59_y[13]);
static void c59_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData);
static const mxArray *c59_b_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData);
static const mxArray *c59_c_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData);
static const mxArray *c59_d_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData);
static const mxArray *c59_e_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData);
static const mxArray *c59_f_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData);
static const mxArray *c59_g_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData);
static real_T c59_c_emlrt_marshallIn(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId);
static void c59_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData);
static void c59_info_helper(const mxArray **c59_info);
static const mxArray *c59_emlrt_marshallOut(const char * c59_u);
static const mxArray *c59_b_emlrt_marshallOut(const uint32_T c59_u);
static void c59_realmax(SFc59_Walking_ATRIASInstanceStruct *chartInstance);
static const mxArray *c59_h_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData);
static int32_T c59_d_emlrt_marshallIn(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId);
static void c59_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData);
static uint8_T c59_e_emlrt_marshallIn(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c59_b_is_active_c59_Walking_ATRIAS, const
  char_T *c59_identifier);
static uint8_T c59_f_emlrt_marshallIn(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId);
static void init_dsm_address_info(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  chartInstance->c59_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c59_is_active_c59_Walking_ATRIAS = 0U;
}

static void initialize_params_c59_Walking_ATRIAS
  (SFc59_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c59_update_debugger_state_c59_Walking_ATRIAS
  (SFc59_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c59_Walking_ATRIAS
  (SFc59_Walking_ATRIASInstanceStruct *chartInstance)
{
  const mxArray *c59_st;
  const mxArray *c59_y = NULL;
  int32_T c59_i0;
  real_T c59_u[13];
  const mxArray *c59_b_y = NULL;
  int32_T c59_i1;
  real_T c59_b_u[13];
  const mxArray *c59_c_y = NULL;
  uint8_T c59_hoistedGlobal;
  uint8_T c59_c_u;
  const mxArray *c59_d_y = NULL;
  c59_st = NULL;
  c59_st = NULL;
  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_createcellmatrix(3, 1), false);
  for (c59_i0 = 0; c59_i0 < 13; c59_i0++) {
    c59_u[c59_i0] = (*chartInstance->c59_dq_clean)[c59_i0];
  }

  c59_b_y = NULL;
  sf_mex_assign(&c59_b_y, sf_mex_create("y", c59_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_setcell(c59_y, 0, c59_b_y);
  for (c59_i1 = 0; c59_i1 < 13; c59_i1++) {
    c59_b_u[c59_i1] = (*chartInstance->c59_q_clean)[c59_i1];
  }

  c59_c_y = NULL;
  sf_mex_assign(&c59_c_y, sf_mex_create("y", c59_b_u, 0, 0U, 1U, 0U, 1, 13),
                false);
  sf_mex_setcell(c59_y, 1, c59_c_y);
  c59_hoistedGlobal = chartInstance->c59_is_active_c59_Walking_ATRIAS;
  c59_c_u = c59_hoistedGlobal;
  c59_d_y = NULL;
  sf_mex_assign(&c59_d_y, sf_mex_create("y", &c59_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c59_y, 2, c59_d_y);
  sf_mex_assign(&c59_st, c59_y, false);
  return c59_st;
}

static void set_sim_state_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c59_st)
{
  const mxArray *c59_u;
  real_T c59_dv0[13];
  int32_T c59_i2;
  real_T c59_dv1[13];
  int32_T c59_i3;
  chartInstance->c59_doneDoubleBufferReInit = true;
  c59_u = sf_mex_dup(c59_st);
  c59_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c59_u, 0)),
                       "dq_clean", c59_dv0);
  for (c59_i2 = 0; c59_i2 < 13; c59_i2++) {
    (*chartInstance->c59_dq_clean)[c59_i2] = c59_dv0[c59_i2];
  }

  c59_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c59_u, 1)),
                       "q_clean", c59_dv1);
  for (c59_i3 = 0; c59_i3 < 13; c59_i3++) {
    (*chartInstance->c59_q_clean)[c59_i3] = c59_dv1[c59_i3];
  }

  chartInstance->c59_is_active_c59_Walking_ATRIAS = c59_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c59_u, 2)),
     "is_active_c59_Walking_ATRIAS");
  sf_mex_destroy(&c59_u);
  c59_update_debugger_state_c59_Walking_ATRIAS(chartInstance);
  sf_mex_destroy(&c59_st);
}

static void finalize_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  int32_T c59_i4;
  int32_T c59_i5;
  int32_T c59_i6;
  int32_T c59_i7;
  int32_T c59_i8;
  int32_T c59_i9;
  int32_T c59_i10;
  int32_T c59_i11;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c59_sfEvent);
  for (c59_i4 = 0; c59_i4 < 19; c59_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c59_EncoderAngles)[c59_i4], 0U);
  }

  for (c59_i5 = 0; c59_i5 < 19; c59_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c59_EncoderVelocities)[c59_i5], 1U);
  }

  chartInstance->c59_sfEvent = CALL_EVENT;
  c59_chartstep_c59_Walking_ATRIAS(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking_ATRIASMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c59_i6 = 0; c59_i6 < 13; c59_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c59_q_clean)[c59_i6], 2U);
  }

  for (c59_i7 = 0; c59_i7 < 3; c59_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c59_IMUAngles)[c59_i7], 3U);
  }

  for (c59_i8 = 0; c59_i8 < 3; c59_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c59_IMUVelocities)[c59_i8], 4U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c59_UseMotorIncEncoders, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c59_UseIMU, 6U);
  for (c59_i9 = 0; c59_i9 < 13; c59_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c59_dq_clean)[c59_i9], 7U);
  }

  for (c59_i10 = 0; c59_i10 < 2; c59_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c59_IMUTorsoOffset)[c59_i10], 8U);
  }

  for (c59_i11 = 0; c59_i11 < 4; c59_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c59_GearOffset)[c59_i11], 9U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c59_Reset, 10U);
}

static void mdl_start_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c59_chartstep_c59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct *
  chartInstance)
{
  real_T c59_hoistedGlobal;
  real_T c59_b_hoistedGlobal;
  boolean_T c59_c_hoistedGlobal;
  int32_T c59_i12;
  real_T c59_b_EncoderAngles[19];
  int32_T c59_i13;
  real_T c59_b_EncoderVelocities[19];
  int32_T c59_i14;
  real_T c59_b_IMUAngles[3];
  int32_T c59_i15;
  real_T c59_b_IMUVelocities[3];
  real_T c59_b_UseMotorIncEncoders;
  real_T c59_b_UseIMU;
  int32_T c59_i16;
  real_T c59_b_IMUTorsoOffset[2];
  int32_T c59_i17;
  real_T c59_b_GearOffset[4];
  boolean_T c59_b_Reset;
  uint32_T c59_debug_family_var_map[13];
  real_T c59_nargin = 9.0;
  real_T c59_nargout = 2.0;
  real_T c59_b_q_clean[13];
  real_T c59_b_dq_clean[13];
  int32_T c59_i18;
  int32_T c59_i19;
  int32_T c59_i20;
  static int32_T c59_iv0[13] = { 16, 17, 18, 0, 1, 2, 3, 4, 5, 14, 6, 7, 15 };

  int32_T c59_i21;
  int32_T c59_i22;
  int32_T c59_i23;
  int32_T c59_i24;
  real_T c59_a[4];
  int32_T c59_i25;
  int32_T c59_i26;
  int32_T c59_i27;
  static int32_T c59_iv1[4] = { 7, 8, 10, 11 };

  real_T c59_c_q_clean[4];
  int32_T c59_i28;
  real_T c59_b_a[3];
  int32_T c59_i29;
  int32_T c59_i30;
  int32_T c59_i31;
  int32_T c59_i32;
  int32_T c59_i33;
  int32_T c59_i34;
  int32_T c59_i35;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c59_sfEvent);
  c59_hoistedGlobal = *chartInstance->c59_UseMotorIncEncoders;
  c59_b_hoistedGlobal = *chartInstance->c59_UseIMU;
  c59_c_hoistedGlobal = *chartInstance->c59_Reset;
  for (c59_i12 = 0; c59_i12 < 19; c59_i12++) {
    c59_b_EncoderAngles[c59_i12] = (*chartInstance->c59_EncoderAngles)[c59_i12];
  }

  for (c59_i13 = 0; c59_i13 < 19; c59_i13++) {
    c59_b_EncoderVelocities[c59_i13] = (*chartInstance->c59_EncoderVelocities)
      [c59_i13];
  }

  for (c59_i14 = 0; c59_i14 < 3; c59_i14++) {
    c59_b_IMUAngles[c59_i14] = (*chartInstance->c59_IMUAngles)[c59_i14];
  }

  for (c59_i15 = 0; c59_i15 < 3; c59_i15++) {
    c59_b_IMUVelocities[c59_i15] = (*chartInstance->c59_IMUVelocities)[c59_i15];
  }

  c59_b_UseMotorIncEncoders = c59_hoistedGlobal;
  c59_b_UseIMU = c59_b_hoistedGlobal;
  for (c59_i16 = 0; c59_i16 < 2; c59_i16++) {
    c59_b_IMUTorsoOffset[c59_i16] = (*chartInstance->c59_IMUTorsoOffset)[c59_i16];
  }

  for (c59_i17 = 0; c59_i17 < 4; c59_i17++) {
    c59_b_GearOffset[c59_i17] = (*chartInstance->c59_GearOffset)[c59_i17];
  }

  c59_b_Reset = c59_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c59_debug_family_names,
    c59_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_nargin, 0U, c59_e_sf_marshallOut,
    c59_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c59_nargout, 1U, c59_e_sf_marshallOut,
    c59_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c59_b_EncoderAngles, 2U, c59_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c59_b_EncoderVelocities, 3U, c59_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c59_b_IMUAngles, 4U, c59_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c59_b_IMUVelocities, 5U, c59_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c59_b_UseMotorIncEncoders, 6U, c59_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c59_b_UseIMU, 7U, c59_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c59_b_IMUTorsoOffset, 8U, c59_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c59_b_GearOffset, 9U, c59_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c59_b_Reset, 10U, c59_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_b_q_clean, 11U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c59_b_dq_clean, 12U, c59_sf_marshallOut,
    c59_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 11);
  if (CV_EML_IF(0, 1, 0, c59_b_Reset)) {
    _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 12);
    for (c59_i18 = 0; c59_i18 < 13; c59_i18++) {
      c59_b_q_clean[c59_i18] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 13);
    for (c59_i19 = 0; c59_i19 < 13; c59_i19++) {
      c59_b_dq_clean[c59_i19] = 0.0;
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 15);
    c59_realmax(chartInstance);
    c59_realmax(chartInstance);
    c59_realmax(chartInstance);
    for (c59_i20 = 0; c59_i20 < 13; c59_i20++) {
      c59_b_q_clean[c59_i20] = c59_b_EncoderAngles[c59_iv0[c59_i20]];
    }

    _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 16);
    c59_realmax(chartInstance);
    c59_realmax(chartInstance);
    c59_realmax(chartInstance);
    for (c59_i21 = 0; c59_i21 < 13; c59_i21++) {
      c59_b_dq_clean[c59_i21] = c59_b_EncoderVelocities[c59_iv0[c59_i21]];
    }

    _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 22);
    c59_i22 = 0;
    for (c59_i23 = 0; c59_i23 < 2; c59_i23++) {
      c59_b_q_clean[c59_i22 + 9] = c59_b_EncoderAngles[c59_i23 + 8];
      c59_i22 += 3;
    }

    _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 25);
    if (CV_EML_IF(0, 1, 1, c59_b_UseMotorIncEncoders != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 26);
      CV_EML_IF(0, 1, 2, false);
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 30);
      CV_EML_IF(0, 1, 3, false);
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 38);
      CV_EML_IF(0, 1, 4, false);
    }

    _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 53);
    c59_realmax(chartInstance);
    c59_realmax(chartInstance);
    c59_realmax(chartInstance);
    c59_realmax(chartInstance);
    for (c59_i24 = 0; c59_i24 < 4; c59_i24++) {
      c59_a[c59_i24] = c59_b_GearOffset[c59_i24];
    }

    for (c59_i25 = 0; c59_i25 < 4; c59_i25++) {
      c59_a[c59_i25] *= 3.1415926535897931;
    }

    for (c59_i26 = 0; c59_i26 < 4; c59_i26++) {
      c59_a[c59_i26] /= 180.0;
    }

    for (c59_i27 = 0; c59_i27 < 4; c59_i27++) {
      c59_c_q_clean[c59_i27] = c59_b_q_clean[c59_iv1[c59_i27]] + c59_a[c59_i27];
    }

    for (c59_i28 = 0; c59_i28 < 4; c59_i28++) {
      c59_b_q_clean[c59_iv1[c59_i28]] = c59_c_q_clean[c59_i28];
    }

    _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 55);
    if (CV_EML_IF(0, 1, 5, c59_b_UseIMU != 0.0)) {
      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 56);
      c59_b_a[0] = 0.0;
      for (c59_i29 = 0; c59_i29 < 2; c59_i29++) {
        c59_b_a[c59_i29 + 1] = c59_b_IMUTorsoOffset[c59_i29];
      }

      for (c59_i30 = 0; c59_i30 < 3; c59_i30++) {
        c59_b_a[c59_i30] *= 3.1415926535897931;
      }

      for (c59_i31 = 0; c59_i31 < 3; c59_i31++) {
        c59_b_a[c59_i31] /= 180.0;
      }

      for (c59_i32 = 0; c59_i32 < 3; c59_i32++) {
        c59_b_q_clean[c59_i32] = c59_b_IMUAngles[c59_i32] + c59_b_a[c59_i32];
      }

      _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, 57);
      for (c59_i33 = 0; c59_i33 < 3; c59_i33++) {
        c59_b_dq_clean[c59_i33] = c59_b_IMUVelocities[c59_i33];
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c59_sfEvent, -57);
  _SFD_SYMBOL_SCOPE_POP();
  for (c59_i34 = 0; c59_i34 < 13; c59_i34++) {
    (*chartInstance->c59_q_clean)[c59_i34] = c59_b_q_clean[c59_i34];
  }

  for (c59_i35 = 0; c59_i35 < 13; c59_i35++) {
    (*chartInstance->c59_dq_clean)[c59_i35] = c59_b_dq_clean[c59_i35];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c59_sfEvent);
}

static void initSimStructsc59_Walking_ATRIAS(SFc59_Walking_ATRIASInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c59_machineNumber, uint32_T
  c59_chartNumber, uint32_T c59_instanceNumber)
{
  (void)c59_machineNumber;
  (void)c59_chartNumber;
  (void)c59_instanceNumber;
}

static const mxArray *c59_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData)
{
  const mxArray *c59_mxArrayOutData = NULL;
  int32_T c59_i36;
  real_T c59_b_inData[13];
  int32_T c59_i37;
  real_T c59_u[13];
  const mxArray *c59_y = NULL;
  SFc59_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc59_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c59_mxArrayOutData = NULL;
  for (c59_i36 = 0; c59_i36 < 13; c59_i36++) {
    c59_b_inData[c59_i36] = (*(real_T (*)[13])c59_inData)[c59_i36];
  }

  for (c59_i37 = 0; c59_i37 < 13; c59_i37++) {
    c59_u[c59_i37] = c59_b_inData[c59_i37];
  }

  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", c59_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_assign(&c59_mxArrayOutData, c59_y, false);
  return c59_mxArrayOutData;
}

static void c59_emlrt_marshallIn(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c59_b_dq_clean, const char_T *c59_identifier,
  real_T c59_y[13])
{
  emlrtMsgIdentifier c59_thisId;
  c59_thisId.fIdentifier = c59_identifier;
  c59_thisId.fParent = NULL;
  c59_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c59_b_dq_clean), &c59_thisId,
    c59_y);
  sf_mex_destroy(&c59_b_dq_clean);
}

static void c59_b_emlrt_marshallIn(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId,
  real_T c59_y[13])
{
  real_T c59_dv2[13];
  int32_T c59_i38;
  (void)chartInstance;
  sf_mex_import(c59_parentId, sf_mex_dup(c59_u), c59_dv2, 1, 0, 0U, 1, 0U, 1, 13);
  for (c59_i38 = 0; c59_i38 < 13; c59_i38++) {
    c59_y[c59_i38] = c59_dv2[c59_i38];
  }

  sf_mex_destroy(&c59_u);
}

static void c59_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData)
{
  const mxArray *c59_b_dq_clean;
  const char_T *c59_identifier;
  emlrtMsgIdentifier c59_thisId;
  real_T c59_y[13];
  int32_T c59_i39;
  SFc59_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc59_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c59_b_dq_clean = sf_mex_dup(c59_mxArrayInData);
  c59_identifier = c59_varName;
  c59_thisId.fIdentifier = c59_identifier;
  c59_thisId.fParent = NULL;
  c59_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c59_b_dq_clean), &c59_thisId,
    c59_y);
  sf_mex_destroy(&c59_b_dq_clean);
  for (c59_i39 = 0; c59_i39 < 13; c59_i39++) {
    (*(real_T (*)[13])c59_outData)[c59_i39] = c59_y[c59_i39];
  }

  sf_mex_destroy(&c59_mxArrayInData);
}

static const mxArray *c59_b_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData)
{
  const mxArray *c59_mxArrayOutData = NULL;
  boolean_T c59_u;
  const mxArray *c59_y = NULL;
  SFc59_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc59_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c59_mxArrayOutData = NULL;
  c59_u = *(boolean_T *)c59_inData;
  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", &c59_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c59_mxArrayOutData, c59_y, false);
  return c59_mxArrayOutData;
}

static const mxArray *c59_c_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData)
{
  const mxArray *c59_mxArrayOutData = NULL;
  int32_T c59_i40;
  real_T c59_b_inData[4];
  int32_T c59_i41;
  real_T c59_u[4];
  const mxArray *c59_y = NULL;
  SFc59_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc59_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c59_mxArrayOutData = NULL;
  for (c59_i40 = 0; c59_i40 < 4; c59_i40++) {
    c59_b_inData[c59_i40] = (*(real_T (*)[4])c59_inData)[c59_i40];
  }

  for (c59_i41 = 0; c59_i41 < 4; c59_i41++) {
    c59_u[c59_i41] = c59_b_inData[c59_i41];
  }

  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", c59_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c59_mxArrayOutData, c59_y, false);
  return c59_mxArrayOutData;
}

static const mxArray *c59_d_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData)
{
  const mxArray *c59_mxArrayOutData = NULL;
  int32_T c59_i42;
  real_T c59_b_inData[2];
  int32_T c59_i43;
  real_T c59_u[2];
  const mxArray *c59_y = NULL;
  SFc59_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc59_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c59_mxArrayOutData = NULL;
  for (c59_i42 = 0; c59_i42 < 2; c59_i42++) {
    c59_b_inData[c59_i42] = (*(real_T (*)[2])c59_inData)[c59_i42];
  }

  for (c59_i43 = 0; c59_i43 < 2; c59_i43++) {
    c59_u[c59_i43] = c59_b_inData[c59_i43];
  }

  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", c59_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c59_mxArrayOutData, c59_y, false);
  return c59_mxArrayOutData;
}

static const mxArray *c59_e_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData)
{
  const mxArray *c59_mxArrayOutData = NULL;
  real_T c59_u;
  const mxArray *c59_y = NULL;
  SFc59_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc59_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c59_mxArrayOutData = NULL;
  c59_u = *(real_T *)c59_inData;
  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", &c59_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c59_mxArrayOutData, c59_y, false);
  return c59_mxArrayOutData;
}

static const mxArray *c59_f_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData)
{
  const mxArray *c59_mxArrayOutData = NULL;
  int32_T c59_i44;
  real_T c59_b_inData[3];
  int32_T c59_i45;
  real_T c59_u[3];
  const mxArray *c59_y = NULL;
  SFc59_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc59_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c59_mxArrayOutData = NULL;
  for (c59_i44 = 0; c59_i44 < 3; c59_i44++) {
    c59_b_inData[c59_i44] = (*(real_T (*)[3])c59_inData)[c59_i44];
  }

  for (c59_i45 = 0; c59_i45 < 3; c59_i45++) {
    c59_u[c59_i45] = c59_b_inData[c59_i45];
  }

  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", c59_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c59_mxArrayOutData, c59_y, false);
  return c59_mxArrayOutData;
}

static const mxArray *c59_g_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData)
{
  const mxArray *c59_mxArrayOutData = NULL;
  int32_T c59_i46;
  real_T c59_b_inData[19];
  int32_T c59_i47;
  real_T c59_u[19];
  const mxArray *c59_y = NULL;
  SFc59_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc59_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c59_mxArrayOutData = NULL;
  for (c59_i46 = 0; c59_i46 < 19; c59_i46++) {
    c59_b_inData[c59_i46] = (*(real_T (*)[19])c59_inData)[c59_i46];
  }

  for (c59_i47 = 0; c59_i47 < 19; c59_i47++) {
    c59_u[c59_i47] = c59_b_inData[c59_i47];
  }

  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", c59_u, 0, 0U, 1U, 0U, 1, 19), false);
  sf_mex_assign(&c59_mxArrayOutData, c59_y, false);
  return c59_mxArrayOutData;
}

static real_T c59_c_emlrt_marshallIn(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId)
{
  real_T c59_y;
  real_T c59_d0;
  (void)chartInstance;
  sf_mex_import(c59_parentId, sf_mex_dup(c59_u), &c59_d0, 1, 0, 0U, 0, 0U, 0);
  c59_y = c59_d0;
  sf_mex_destroy(&c59_u);
  return c59_y;
}

static void c59_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData)
{
  const mxArray *c59_nargout;
  const char_T *c59_identifier;
  emlrtMsgIdentifier c59_thisId;
  real_T c59_y;
  SFc59_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc59_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c59_nargout = sf_mex_dup(c59_mxArrayInData);
  c59_identifier = c59_varName;
  c59_thisId.fIdentifier = c59_identifier;
  c59_thisId.fParent = NULL;
  c59_y = c59_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c59_nargout),
    &c59_thisId);
  sf_mex_destroy(&c59_nargout);
  *(real_T *)c59_outData = c59_y;
  sf_mex_destroy(&c59_mxArrayInData);
}

const mxArray *sf_c59_Walking_ATRIAS_get_eml_resolved_functions_info(void)
{
  const mxArray *c59_nameCaptureInfo = NULL;
  c59_nameCaptureInfo = NULL;
  sf_mex_assign(&c59_nameCaptureInfo, sf_mex_createstruct("structure", 2, 36, 1),
                false);
  c59_info_helper(&c59_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c59_nameCaptureInfo);
  return c59_nameCaptureInfo;
}

static void c59_info_helper(const mxArray **c59_info)
{
  const mxArray *c59_rhs0 = NULL;
  const mxArray *c59_lhs0 = NULL;
  const mxArray *c59_rhs1 = NULL;
  const mxArray *c59_lhs1 = NULL;
  const mxArray *c59_rhs2 = NULL;
  const mxArray *c59_lhs2 = NULL;
  const mxArray *c59_rhs3 = NULL;
  const mxArray *c59_lhs3 = NULL;
  const mxArray *c59_rhs4 = NULL;
  const mxArray *c59_lhs4 = NULL;
  const mxArray *c59_rhs5 = NULL;
  const mxArray *c59_lhs5 = NULL;
  const mxArray *c59_rhs6 = NULL;
  const mxArray *c59_lhs6 = NULL;
  const mxArray *c59_rhs7 = NULL;
  const mxArray *c59_lhs7 = NULL;
  const mxArray *c59_rhs8 = NULL;
  const mxArray *c59_lhs8 = NULL;
  const mxArray *c59_rhs9 = NULL;
  const mxArray *c59_lhs9 = NULL;
  const mxArray *c59_rhs10 = NULL;
  const mxArray *c59_lhs10 = NULL;
  const mxArray *c59_rhs11 = NULL;
  const mxArray *c59_lhs11 = NULL;
  const mxArray *c59_rhs12 = NULL;
  const mxArray *c59_lhs12 = NULL;
  const mxArray *c59_rhs13 = NULL;
  const mxArray *c59_lhs13 = NULL;
  const mxArray *c59_rhs14 = NULL;
  const mxArray *c59_lhs14 = NULL;
  const mxArray *c59_rhs15 = NULL;
  const mxArray *c59_lhs15 = NULL;
  const mxArray *c59_rhs16 = NULL;
  const mxArray *c59_lhs16 = NULL;
  const mxArray *c59_rhs17 = NULL;
  const mxArray *c59_lhs17 = NULL;
  const mxArray *c59_rhs18 = NULL;
  const mxArray *c59_lhs18 = NULL;
  const mxArray *c59_rhs19 = NULL;
  const mxArray *c59_lhs19 = NULL;
  const mxArray *c59_rhs20 = NULL;
  const mxArray *c59_lhs20 = NULL;
  const mxArray *c59_rhs21 = NULL;
  const mxArray *c59_lhs21 = NULL;
  const mxArray *c59_rhs22 = NULL;
  const mxArray *c59_lhs22 = NULL;
  const mxArray *c59_rhs23 = NULL;
  const mxArray *c59_lhs23 = NULL;
  const mxArray *c59_rhs24 = NULL;
  const mxArray *c59_lhs24 = NULL;
  const mxArray *c59_rhs25 = NULL;
  const mxArray *c59_lhs25 = NULL;
  const mxArray *c59_rhs26 = NULL;
  const mxArray *c59_lhs26 = NULL;
  const mxArray *c59_rhs27 = NULL;
  const mxArray *c59_lhs27 = NULL;
  const mxArray *c59_rhs28 = NULL;
  const mxArray *c59_lhs28 = NULL;
  const mxArray *c59_rhs29 = NULL;
  const mxArray *c59_lhs29 = NULL;
  const mxArray *c59_rhs30 = NULL;
  const mxArray *c59_lhs30 = NULL;
  const mxArray *c59_rhs31 = NULL;
  const mxArray *c59_lhs31 = NULL;
  const mxArray *c59_rhs32 = NULL;
  const mxArray *c59_lhs32 = NULL;
  const mxArray *c59_rhs33 = NULL;
  const mxArray *c59_lhs33 = NULL;
  const mxArray *c59_rhs34 = NULL;
  const mxArray *c59_lhs34 = NULL;
  const mxArray *c59_rhs35 = NULL;
  const mxArray *c59_lhs35 = NULL;
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("colon"), "name", "name", 0);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c59_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("colon"), "name", "name", 1);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c59_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c59_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                  "context", "context", 3);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("isfinite"), "name", "name",
                  3);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c59_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c59_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("isinf"), "name", "name", 5);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c59_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 6);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c59_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("isnan"), "name", "name", 7);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c59_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c59_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                  "context", "context", 9);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("floor"), "name", "name", 9);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c59_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 10);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c59_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 11);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c59_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                  "context", "context", 12);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c59_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 13);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c59_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                  "context", "context", 14);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("flintmax"), "name", "name",
                  14);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1348213516U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c59_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 15);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c59_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkFlintRange"),
                  "context", "context", 16);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("abs"), "name", "name", 16);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c59_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c59_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 18);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c59_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 19);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("realmax"), "name", "name",
                  19);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c59_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_realmax"), "name",
                  "name", 20);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c59_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 21);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c59_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 22);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("mrdivide"), "name", "name",
                  22);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c59_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 23);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 23);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c59_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 24);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("rdivide"), "name", "name",
                  24);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c59_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c59_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 26);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c59_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_div"), "name", "name",
                  27);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c59_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 28);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c59_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 29);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("floor"), "name", "name", 29);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c59_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 30);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 30);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c59_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_flint_colon"),
                  "context", "context", 31);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("intmax"), "name", "name", 31);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c59_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 32);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c59_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "context", "context", 33);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 33);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c59_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 34);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 34);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c59_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(""), "context", "context", 35);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("mrdivide"), "name", "name",
                  35);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c59_info, c59_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c59_info, c59_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c59_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c59_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c59_info, sf_mex_duplicatearraysafe(&c59_lhs35), "lhs", "lhs",
                  35);
  sf_mex_destroy(&c59_rhs0);
  sf_mex_destroy(&c59_lhs0);
  sf_mex_destroy(&c59_rhs1);
  sf_mex_destroy(&c59_lhs1);
  sf_mex_destroy(&c59_rhs2);
  sf_mex_destroy(&c59_lhs2);
  sf_mex_destroy(&c59_rhs3);
  sf_mex_destroy(&c59_lhs3);
  sf_mex_destroy(&c59_rhs4);
  sf_mex_destroy(&c59_lhs4);
  sf_mex_destroy(&c59_rhs5);
  sf_mex_destroy(&c59_lhs5);
  sf_mex_destroy(&c59_rhs6);
  sf_mex_destroy(&c59_lhs6);
  sf_mex_destroy(&c59_rhs7);
  sf_mex_destroy(&c59_lhs7);
  sf_mex_destroy(&c59_rhs8);
  sf_mex_destroy(&c59_lhs8);
  sf_mex_destroy(&c59_rhs9);
  sf_mex_destroy(&c59_lhs9);
  sf_mex_destroy(&c59_rhs10);
  sf_mex_destroy(&c59_lhs10);
  sf_mex_destroy(&c59_rhs11);
  sf_mex_destroy(&c59_lhs11);
  sf_mex_destroy(&c59_rhs12);
  sf_mex_destroy(&c59_lhs12);
  sf_mex_destroy(&c59_rhs13);
  sf_mex_destroy(&c59_lhs13);
  sf_mex_destroy(&c59_rhs14);
  sf_mex_destroy(&c59_lhs14);
  sf_mex_destroy(&c59_rhs15);
  sf_mex_destroy(&c59_lhs15);
  sf_mex_destroy(&c59_rhs16);
  sf_mex_destroy(&c59_lhs16);
  sf_mex_destroy(&c59_rhs17);
  sf_mex_destroy(&c59_lhs17);
  sf_mex_destroy(&c59_rhs18);
  sf_mex_destroy(&c59_lhs18);
  sf_mex_destroy(&c59_rhs19);
  sf_mex_destroy(&c59_lhs19);
  sf_mex_destroy(&c59_rhs20);
  sf_mex_destroy(&c59_lhs20);
  sf_mex_destroy(&c59_rhs21);
  sf_mex_destroy(&c59_lhs21);
  sf_mex_destroy(&c59_rhs22);
  sf_mex_destroy(&c59_lhs22);
  sf_mex_destroy(&c59_rhs23);
  sf_mex_destroy(&c59_lhs23);
  sf_mex_destroy(&c59_rhs24);
  sf_mex_destroy(&c59_lhs24);
  sf_mex_destroy(&c59_rhs25);
  sf_mex_destroy(&c59_lhs25);
  sf_mex_destroy(&c59_rhs26);
  sf_mex_destroy(&c59_lhs26);
  sf_mex_destroy(&c59_rhs27);
  sf_mex_destroy(&c59_lhs27);
  sf_mex_destroy(&c59_rhs28);
  sf_mex_destroy(&c59_lhs28);
  sf_mex_destroy(&c59_rhs29);
  sf_mex_destroy(&c59_lhs29);
  sf_mex_destroy(&c59_rhs30);
  sf_mex_destroy(&c59_lhs30);
  sf_mex_destroy(&c59_rhs31);
  sf_mex_destroy(&c59_lhs31);
  sf_mex_destroy(&c59_rhs32);
  sf_mex_destroy(&c59_lhs32);
  sf_mex_destroy(&c59_rhs33);
  sf_mex_destroy(&c59_lhs33);
  sf_mex_destroy(&c59_rhs34);
  sf_mex_destroy(&c59_lhs34);
  sf_mex_destroy(&c59_rhs35);
  sf_mex_destroy(&c59_lhs35);
}

static const mxArray *c59_emlrt_marshallOut(const char * c59_u)
{
  const mxArray *c59_y = NULL;
  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", c59_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c59_u)), false);
  return c59_y;
}

static const mxArray *c59_b_emlrt_marshallOut(const uint32_T c59_u)
{
  const mxArray *c59_y = NULL;
  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", &c59_u, 7, 0U, 0U, 0U, 0), false);
  return c59_y;
}

static void c59_realmax(SFc59_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *c59_h_sf_marshallOut(void *chartInstanceVoid, void
  *c59_inData)
{
  const mxArray *c59_mxArrayOutData = NULL;
  int32_T c59_u;
  const mxArray *c59_y = NULL;
  SFc59_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc59_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c59_mxArrayOutData = NULL;
  c59_u = *(int32_T *)c59_inData;
  c59_y = NULL;
  sf_mex_assign(&c59_y, sf_mex_create("y", &c59_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c59_mxArrayOutData, c59_y, false);
  return c59_mxArrayOutData;
}

static int32_T c59_d_emlrt_marshallIn(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId)
{
  int32_T c59_y;
  int32_T c59_i48;
  (void)chartInstance;
  sf_mex_import(c59_parentId, sf_mex_dup(c59_u), &c59_i48, 1, 6, 0U, 0, 0U, 0);
  c59_y = c59_i48;
  sf_mex_destroy(&c59_u);
  return c59_y;
}

static void c59_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c59_mxArrayInData, const char_T *c59_varName, void *c59_outData)
{
  const mxArray *c59_b_sfEvent;
  const char_T *c59_identifier;
  emlrtMsgIdentifier c59_thisId;
  int32_T c59_y;
  SFc59_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc59_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c59_b_sfEvent = sf_mex_dup(c59_mxArrayInData);
  c59_identifier = c59_varName;
  c59_thisId.fIdentifier = c59_identifier;
  c59_thisId.fParent = NULL;
  c59_y = c59_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c59_b_sfEvent),
    &c59_thisId);
  sf_mex_destroy(&c59_b_sfEvent);
  *(int32_T *)c59_outData = c59_y;
  sf_mex_destroy(&c59_mxArrayInData);
}

static uint8_T c59_e_emlrt_marshallIn(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c59_b_is_active_c59_Walking_ATRIAS, const
  char_T *c59_identifier)
{
  uint8_T c59_y;
  emlrtMsgIdentifier c59_thisId;
  c59_thisId.fIdentifier = c59_identifier;
  c59_thisId.fParent = NULL;
  c59_y = c59_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c59_b_is_active_c59_Walking_ATRIAS), &c59_thisId);
  sf_mex_destroy(&c59_b_is_active_c59_Walking_ATRIAS);
  return c59_y;
}

static uint8_T c59_f_emlrt_marshallIn(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c59_u, const emlrtMsgIdentifier *c59_parentId)
{
  uint8_T c59_y;
  uint8_T c59_u0;
  (void)chartInstance;
  sf_mex_import(c59_parentId, sf_mex_dup(c59_u), &c59_u0, 1, 3, 0U, 0, 0U, 0);
  c59_y = c59_u0;
  sf_mex_destroy(&c59_u);
  return c59_y;
}

static void init_dsm_address_info(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc59_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  chartInstance->c59_EncoderAngles = (real_T (*)[19])
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c59_EncoderVelocities = (real_T (*)[19])
    ssGetInputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c59_q_clean = (real_T (*)[13])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c59_IMUAngles = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c59_IMUVelocities = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c59_UseMotorIncEncoders = (real_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 4);
  chartInstance->c59_UseIMU = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c59_dq_clean = (real_T (*)[13])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c59_IMUTorsoOffset = (real_T (*)[2])
    ssGetInputPortSignal_wrapper(chartInstance->S, 6);
  chartInstance->c59_GearOffset = (real_T (*)[4])ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c59_Reset = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
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

void sf_c59_Walking_ATRIAS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1391484139U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1601295526U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(392332202U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1163025461U);
}

mxArray* sf_c59_Walking_ATRIAS_get_post_codegen_info(void);
mxArray *sf_c59_Walking_ATRIAS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("hSRA6mI8M2hg2rpL5QdxuD");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,9,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(19);
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
      pr[0] = (double)(19);
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
      pr[0] = (double)(3);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(4);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
    mxArray* mxPostCodegenInfo = sf_c59_Walking_ATRIAS_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c59_Walking_ATRIAS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c59_Walking_ATRIAS_jit_fallback_info(void)
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

mxArray *sf_c59_Walking_ATRIAS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c59_Walking_ATRIAS_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c59_Walking_ATRIAS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x3'type','srcId','name','auxInfo'{{M[1],M[10],T\"dq_clean\",},{M[1],M[5],T\"q_clean\",},{M[8],M[0],T\"is_active_c59_Walking_ATRIAS\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 3, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c59_Walking_ATRIAS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc59_Walking_ATRIASInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc59_Walking_ATRIASInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking_ATRIASMachineNumber_,
           59,
           1,
           1,
           0,
           11,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"EncoderAngles");
          _SFD_SET_DATA_PROPS(1,1,1,0,"EncoderVelocities");
          _SFD_SET_DATA_PROPS(2,2,0,1,"q_clean");
          _SFD_SET_DATA_PROPS(3,1,1,0,"IMUAngles");
          _SFD_SET_DATA_PROPS(4,1,1,0,"IMUVelocities");
          _SFD_SET_DATA_PROPS(5,1,1,0,"UseMotorIncEncoders");
          _SFD_SET_DATA_PROPS(6,1,1,0,"UseIMU");
          _SFD_SET_DATA_PROPS(7,2,0,1,"dq_clean");
          _SFD_SET_DATA_PROPS(8,1,1,0,"IMUTorsoOffset");
          _SFD_SET_DATA_PROPS(9,1,1,0,"GearOffset");
          _SFD_SET_DATA_PROPS(10,1,1,0,"Reset");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2480);
        _SFD_CV_INIT_EML_IF(0,1,0,544,554,623,2476);
        _SFD_CV_INIT_EML_IF(0,1,1,1098,1122,-1,2158);
        _SFD_CV_INIT_EML_IF(0,1,2,1135,1139,1303,2146);
        _SFD_CV_INIT_EML_IF(0,1,3,1303,1311,1668,2146);
        _SFD_CV_INIT_EML_IF(0,1,4,1668,1676,1985,2146);
        _SFD_CV_INIT_EML_IF(0,1,5,2334,2345,-1,2468);

        {
          unsigned int dimVector[1];
          dimVector[0]= 19;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c59_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 19;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c59_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)
            c59_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c59_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c59_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_e_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c59_sf_marshallOut,(MexInFcnForType)
            c59_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c59_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 4;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c59_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c59_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c59_EncoderAngles);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c59_EncoderVelocities);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c59_q_clean);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c59_IMUAngles);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c59_IMUVelocities);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c59_UseMotorIncEncoders);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c59_UseIMU);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c59_dq_clean);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c59_IMUTorsoOffset);
        _SFD_SET_DATA_VALUE_PTR(9U, *chartInstance->c59_GearOffset);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c59_Reset);
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
  return "2qz1POYjbxzHMbF40o6G3";
}

static void sf_opaque_initialize_c59_Walking_ATRIAS(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc59_Walking_ATRIASInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c59_Walking_ATRIAS((SFc59_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
  initialize_c59_Walking_ATRIAS((SFc59_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c59_Walking_ATRIAS(void *chartInstanceVar)
{
  enable_c59_Walking_ATRIAS((SFc59_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c59_Walking_ATRIAS(void *chartInstanceVar)
{
  disable_c59_Walking_ATRIAS((SFc59_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c59_Walking_ATRIAS(void *chartInstanceVar)
{
  sf_gateway_c59_Walking_ATRIAS((SFc59_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c59_Walking_ATRIAS(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c59_Walking_ATRIAS((SFc59_Walking_ATRIASInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c59_Walking_ATRIAS(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c59_Walking_ATRIAS((SFc59_Walking_ATRIASInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c59_Walking_ATRIAS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc59_Walking_ATRIASInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking_ATRIAS_optimization_info();
    }

    finalize_c59_Walking_ATRIAS((SFc59_Walking_ATRIASInstanceStruct*)
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
  initSimStructsc59_Walking_ATRIAS((SFc59_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c59_Walking_ATRIAS(SimStruct *S)
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
    initialize_params_c59_Walking_ATRIAS((SFc59_Walking_ATRIASInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c59_Walking_ATRIAS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking_ATRIAS_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      59);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,59,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,59,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,59);
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
        infoStruct,59,9);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,59,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 9; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,59);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2625062919U));
  ssSetChecksum1(S,(1085555940U));
  ssSetChecksum2(S,(569833413U));
  ssSetChecksum3(S,(2381345706U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c59_Walking_ATRIAS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c59_Walking_ATRIAS(SimStruct *S)
{
  SFc59_Walking_ATRIASInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc59_Walking_ATRIASInstanceStruct *)utMalloc(sizeof
    (SFc59_Walking_ATRIASInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc59_Walking_ATRIASInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c59_Walking_ATRIAS;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c59_Walking_ATRIAS;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c59_Walking_ATRIAS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c59_Walking_ATRIAS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c59_Walking_ATRIAS;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c59_Walking_ATRIAS;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c59_Walking_ATRIAS;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c59_Walking_ATRIAS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c59_Walking_ATRIAS;
  chartInstance->chartInfo.mdlStart = mdlStart_c59_Walking_ATRIAS;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c59_Walking_ATRIAS;
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

void c59_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c59_Walking_ATRIAS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c59_Walking_ATRIAS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c59_Walking_ATRIAS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c59_Walking_ATRIAS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
