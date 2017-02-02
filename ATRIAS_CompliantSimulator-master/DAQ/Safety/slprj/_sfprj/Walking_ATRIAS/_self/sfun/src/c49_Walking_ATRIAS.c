/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking_ATRIAS_sfun.h"
#include "c49_Walking_ATRIAS.h"
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
static const char * c49_debug_family_names[13] = { "nargin", "nargout",
  "Calibration", "AbsEncoders", "IncEncoders", "IncEncodersPrev", "Reset",
  "RolloverIn", "IncCalTickIn", "AbsAngle", "IncAngle", "Rollover", "IncCalTick"
};

static const char * c49_b_debug_family_names[10] = { "HalfMaxTicks", "CalOffset",
  "iHigh", "iLow", "nargin", "nargout", "AbsMaxTick", "AbsCalTick", "AbsEncoder",
  "AbsUnrolled" };

static const char * c49_c_debug_family_names[8] = { "nargin", "nargout",
  "IncCalConst", "IncMaxTick", "AbsAngle", "IncTick", "IncCalTick", "Rollover" };

static const char * c49_d_debug_family_names[8] = { "NormalizedCountPrev",
  "NormalizedCount", "nargin", "nargout", "MaxTick", "IncEncoders",
  "IncEncodersPrev", "Rollover" };

static const char * c49_e_debug_family_names[17] = { "RefAngle", "IncCalTickB",
  "IncCalAngle", "IncTick", "nargin", "nargout", "Calibration", "AbsEncoders",
  "IncEncoders", "IncEncodersPrev", "Reset", "RolloverIn", "IncCalTickIn",
  "AbsAngle", "IncAngle", "Rollover", "IncCalTick" };

/* Function Declarations */
static void initialize_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance);
static void initialize_params_c49_Walking_ATRIAS
  (SFc49_Walking_ATRIASInstanceStruct *chartInstance);
static void enable_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance);
static void disable_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance);
static void c49_update_debugger_state_c49_Walking_ATRIAS
  (SFc49_Walking_ATRIASInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c49_Walking_ATRIAS
  (SFc49_Walking_ATRIASInstanceStruct *chartInstance);
static void set_sim_state_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c49_st);
static void finalize_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance);
static void sf_gateway_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance);
static void mdl_start_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance);
static void initSimStructsc49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct *
  chartInstance);
static void c49_calibrateEncoders_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, c49_RobotCalibrationBus *c49_b_Calibration, real_T
  c49_b_AbsEncoders[10], real_T c49_b_IncEncoders[9], real_T
  c49_b_IncEncodersPrev[9], boolean_T c49_b_Reset, real_T c49_b_RolloverIn[9],
  real_T c49_b_IncCalTickIn[6], real_T c49_b_AbsAngle[10], real_T
  c49_b_IncAngle[9], real_T c49_b_Rollover[9], real_T c49_b_IncCalTick[6]);
static void init_script_number_translation(uint32_T c49_machineNumber, uint32_T
  c49_chartNumber, uint32_T c49_instanceNumber);
static const mxArray *c49_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData);
static void c49_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_b_IncCalTick, const char_T *c49_identifier,
  real_T c49_y[6]);
static void c49_b_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  real_T c49_y[6]);
static void c49_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData);
static const mxArray *c49_b_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData);
static void c49_c_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_b_Rollover, const char_T *c49_identifier,
  real_T c49_y[9]);
static void c49_d_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  real_T c49_y[9]);
static void c49_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData);
static const mxArray *c49_c_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData);
static void c49_e_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_b_AbsAngle, const char_T *c49_identifier,
  real_T c49_y[10]);
static void c49_f_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  real_T c49_y[10]);
static void c49_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData);
static const mxArray *c49_d_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData);
static const mxArray *c49_e_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData);
static const mxArray *c49_f_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData);
static real_T c49_g_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId);
static void c49_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData);
static const mxArray *c49_g_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData);
static void c49_h_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  real_T c49_y[2]);
static void c49_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData);
static const mxArray *c49_h_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData);
static void c49_i_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  boolean_T c49_y[2]);
static void c49_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData);
static boolean_T c49_j_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId);
static void c49_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData);
static void c49_k_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  c49_RobotCalibrationBus *c49_y);
static void c49_l_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  real_T c49_y[3]);
static void c49_m_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  real_T c49_y[9]);
static void c49_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData);
static void c49_info_helper(const mxArray **c49_info);
static const mxArray *c49_emlrt_marshallOut(const char * c49_u);
static const mxArray *c49_b_emlrt_marshallOut(const uint32_T c49_u);
static void c49_eml_li_find(SFc49_Walking_ATRIASInstanceStruct *chartInstance,
  boolean_T c49_x[2], int32_T c49_y_data[], int32_T *c49_y_sizes);
static int32_T c49_intmin(SFc49_Walking_ATRIASInstanceStruct *chartInstance);
static void c49_rdivide(SFc49_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c49_x[6], real_T c49_y[6], real_T c49_z[6]);
static void c49_b_rdivide(SFc49_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c49_x[9], real_T c49_y[9], real_T c49_z[9]);
static void c49_b_eml_li_find(SFc49_Walking_ATRIASInstanceStruct *chartInstance,
  boolean_T c49_x[9], int32_T c49_y_data[], int32_T *c49_y_sizes);
static const mxArray *c49_i_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData);
static int32_T c49_n_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId);
static void c49_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData);
static const mxArray *c49_Calibration_bus_io(void *chartInstanceVoid, void
  *c49_pData);
static uint8_T c49_o_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_b_is_active_c49_Walking_ATRIAS, const
  char_T *c49_identifier);
static uint8_T c49_p_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId);
static void init_dsm_address_info(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  chartInstance->c49_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c49_is_active_c49_Walking_ATRIAS = 0U;
}

static void initialize_params_c49_Walking_ATRIAS
  (SFc49_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c49_update_debugger_state_c49_Walking_ATRIAS
  (SFc49_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c49_Walking_ATRIAS
  (SFc49_Walking_ATRIASInstanceStruct *chartInstance)
{
  const mxArray *c49_st;
  const mxArray *c49_y = NULL;
  int32_T c49_i0;
  real_T c49_u[10];
  const mxArray *c49_b_y = NULL;
  int32_T c49_i1;
  real_T c49_b_u[9];
  const mxArray *c49_c_y = NULL;
  int32_T c49_i2;
  real_T c49_c_u[6];
  const mxArray *c49_d_y = NULL;
  int32_T c49_i3;
  real_T c49_d_u[9];
  const mxArray *c49_e_y = NULL;
  uint8_T c49_hoistedGlobal;
  uint8_T c49_e_u;
  const mxArray *c49_f_y = NULL;
  c49_st = NULL;
  c49_st = NULL;
  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_createcellmatrix(5, 1), false);
  for (c49_i0 = 0; c49_i0 < 10; c49_i0++) {
    c49_u[c49_i0] = (*chartInstance->c49_AbsAngle)[c49_i0];
  }

  c49_b_y = NULL;
  sf_mex_assign(&c49_b_y, sf_mex_create("y", c49_u, 0, 0U, 1U, 0U, 1, 10), false);
  sf_mex_setcell(c49_y, 0, c49_b_y);
  for (c49_i1 = 0; c49_i1 < 9; c49_i1++) {
    c49_b_u[c49_i1] = (*chartInstance->c49_IncAngle)[c49_i1];
  }

  c49_c_y = NULL;
  sf_mex_assign(&c49_c_y, sf_mex_create("y", c49_b_u, 0, 0U, 1U, 0U, 1, 9),
                false);
  sf_mex_setcell(c49_y, 1, c49_c_y);
  for (c49_i2 = 0; c49_i2 < 6; c49_i2++) {
    c49_c_u[c49_i2] = (*chartInstance->c49_IncCalTick)[c49_i2];
  }

  c49_d_y = NULL;
  sf_mex_assign(&c49_d_y, sf_mex_create("y", c49_c_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_setcell(c49_y, 2, c49_d_y);
  for (c49_i3 = 0; c49_i3 < 9; c49_i3++) {
    c49_d_u[c49_i3] = (*chartInstance->c49_Rollover)[c49_i3];
  }

  c49_e_y = NULL;
  sf_mex_assign(&c49_e_y, sf_mex_create("y", c49_d_u, 0, 0U, 1U, 0U, 1, 9),
                false);
  sf_mex_setcell(c49_y, 3, c49_e_y);
  c49_hoistedGlobal = chartInstance->c49_is_active_c49_Walking_ATRIAS;
  c49_e_u = c49_hoistedGlobal;
  c49_f_y = NULL;
  sf_mex_assign(&c49_f_y, sf_mex_create("y", &c49_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c49_y, 4, c49_f_y);
  sf_mex_assign(&c49_st, c49_y, false);
  return c49_st;
}

static void set_sim_state_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c49_st)
{
  const mxArray *c49_u;
  real_T c49_dv0[10];
  int32_T c49_i4;
  real_T c49_dv1[9];
  int32_T c49_i5;
  real_T c49_dv2[6];
  int32_T c49_i6;
  real_T c49_dv3[9];
  int32_T c49_i7;
  chartInstance->c49_doneDoubleBufferReInit = true;
  c49_u = sf_mex_dup(c49_st);
  c49_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c49_u, 0)),
    "AbsAngle", c49_dv0);
  for (c49_i4 = 0; c49_i4 < 10; c49_i4++) {
    (*chartInstance->c49_AbsAngle)[c49_i4] = c49_dv0[c49_i4];
  }

  c49_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c49_u, 1)),
    "IncAngle", c49_dv1);
  for (c49_i5 = 0; c49_i5 < 9; c49_i5++) {
    (*chartInstance->c49_IncAngle)[c49_i5] = c49_dv1[c49_i5];
  }

  c49_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c49_u, 2)),
                       "IncCalTick", c49_dv2);
  for (c49_i6 = 0; c49_i6 < 6; c49_i6++) {
    (*chartInstance->c49_IncCalTick)[c49_i6] = c49_dv2[c49_i6];
  }

  c49_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c49_u, 3)),
    "Rollover", c49_dv3);
  for (c49_i7 = 0; c49_i7 < 9; c49_i7++) {
    (*chartInstance->c49_Rollover)[c49_i7] = c49_dv3[c49_i7];
  }

  chartInstance->c49_is_active_c49_Walking_ATRIAS = c49_o_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c49_u, 4)),
     "is_active_c49_Walking_ATRIAS");
  sf_mex_destroy(&c49_u);
  c49_update_debugger_state_c49_Walking_ATRIAS(chartInstance);
  sf_mex_destroy(&c49_st);
}

static void finalize_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  int32_T c49_i8;
  int32_T c49_i9;
  int32_T c49_i10;
  boolean_T c49_hoistedGlobal;
  int32_T c49_i11;
  c49_RobotCalibrationBus c49_b_Calibration;
  int32_T c49_i12;
  int32_T c49_i13;
  int32_T c49_i14;
  int32_T c49_i15;
  int32_T c49_i16;
  int32_T c49_i17;
  int32_T c49_i18;
  int32_T c49_i19;
  int32_T c49_i20;
  int32_T c49_i21;
  int32_T c49_i22;
  int32_T c49_i23;
  int32_T c49_i24;
  int32_T c49_i25;
  int32_T c49_i26;
  int32_T c49_i27;
  int32_T c49_i28;
  int32_T c49_i29;
  real_T c49_b_AbsEncoders[10];
  int32_T c49_i30;
  real_T c49_b_IncEncoders[9];
  int32_T c49_i31;
  real_T c49_b_IncEncodersPrev[9];
  boolean_T c49_b_Reset;
  int32_T c49_i32;
  real_T c49_b_RolloverIn[9];
  int32_T c49_i33;
  real_T c49_b_IncCalTickIn[6];
  uint32_T c49_debug_family_var_map[13];
  real_T c49_nargin = 7.0;
  real_T c49_nargout = 4.0;
  real_T c49_b_AbsAngle[10];
  real_T c49_b_IncAngle[9];
  real_T c49_b_Rollover[9];
  real_T c49_b_IncCalTick[6];
  c49_RobotCalibrationBus c49_c_Calibration;
  int32_T c49_i34;
  real_T c49_c_AbsEncoders[10];
  int32_T c49_i35;
  real_T c49_c_IncEncoders[9];
  int32_T c49_i36;
  real_T c49_c_IncEncodersPrev[9];
  int32_T c49_i37;
  real_T c49_c_RolloverIn[9];
  int32_T c49_i38;
  real_T c49_c_IncCalTickIn[6];
  real_T c49_c_IncCalTick[6];
  real_T c49_c_Rollover[9];
  real_T c49_c_IncAngle[9];
  real_T c49_c_AbsAngle[10];
  int32_T c49_i39;
  int32_T c49_i40;
  int32_T c49_i41;
  int32_T c49_i42;
  int32_T c49_i43;
  int32_T c49_i44;
  int32_T c49_i45;
  int32_T c49_i46;
  int32_T c49_i47;
  int32_T c49_i48;
  int32_T c49_i49;
  int32_T c49_i50;
  int32_T c49_i51;
  int32_T c49_i52;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, chartInstance->c49_sfEvent);
  for (c49_i8 = 0; c49_i8 < 10; c49_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c49_AbsEncoders)[c49_i8], 1U);
  }

  for (c49_i9 = 0; c49_i9 < 9; c49_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c49_IncEncoders)[c49_i9], 2U);
  }

  for (c49_i10 = 0; c49_i10 < 9; c49_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c49_IncEncodersPrev)[c49_i10], 3U);
  }

  chartInstance->c49_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, chartInstance->c49_sfEvent);
  c49_hoistedGlobal = *chartInstance->c49_Reset;
  for (c49_i11 = 0; c49_i11 < 10; c49_i11++) {
    c49_b_Calibration.AbsCalTick[c49_i11] = ((real_T *)&((char_T *)
      chartInstance->c49_Calibration)[0])[c49_i11];
  }

  for (c49_i12 = 0; c49_i12 < 3; c49_i12++) {
    c49_b_Calibration.BoomCalTick[c49_i12] = ((real_T *)&((char_T *)
      chartInstance->c49_Calibration)[80])[c49_i12];
  }

  for (c49_i13 = 0; c49_i13 < 10; c49_i13++) {
    c49_b_Calibration.AbsCalConst[c49_i13] = ((real_T *)&((char_T *)
      chartInstance->c49_Calibration)[104])[c49_i13];
  }

  for (c49_i14 = 0; c49_i14 < 10; c49_i14++) {
    c49_b_Calibration.AbsCalAngle[c49_i14] = ((real_T *)&((char_T *)
      chartInstance->c49_Calibration)[184])[c49_i14];
  }

  for (c49_i15 = 0; c49_i15 < 10; c49_i15++) {
    c49_b_Calibration.AbsMaxTick[c49_i15] = ((real_T *)&((char_T *)
      chartInstance->c49_Calibration)[264])[c49_i15];
  }

  for (c49_i16 = 0; c49_i16 < 6; c49_i16++) {
    c49_b_Calibration.IncCalConst[c49_i16] = ((real_T *)&((char_T *)
      chartInstance->c49_Calibration)[344])[c49_i16];
  }

  for (c49_i17 = 0; c49_i17 < 6; c49_i17++) {
    c49_b_Calibration.IncMaxTick[c49_i17] = ((real_T *)&((char_T *)
      chartInstance->c49_Calibration)[392])[c49_i17];
  }

  for (c49_i18 = 0; c49_i18 < 3; c49_i18++) {
    c49_b_Calibration.BoomCalConst[c49_i18] = ((real_T *)&((char_T *)
      chartInstance->c49_Calibration)[440])[c49_i18];
  }

  for (c49_i19 = 0; c49_i19 < 3; c49_i19++) {
    c49_b_Calibration.BoomCalAngle[c49_i19] = ((real_T *)&((char_T *)
      chartInstance->c49_Calibration)[464])[c49_i19];
  }

  for (c49_i20 = 0; c49_i20 < 3; c49_i20++) {
    c49_b_Calibration.BoomMaxTick[c49_i20] = ((real_T *)&((char_T *)
      chartInstance->c49_Calibration)[488])[c49_i20];
  }

  for (c49_i21 = 0; c49_i21 < 9; c49_i21++) {
    c49_b_Calibration.MaxTick[c49_i21] = ((real_T *)&((char_T *)
      chartInstance->c49_Calibration)[512])[c49_i21];
  }

  for (c49_i22 = 0; c49_i22 < 9; c49_i22++) {
    c49_b_Calibration.Motors[c49_i22] = ((real_T *)&((char_T *)
      chartInstance->c49_Calibration)[584])[c49_i22];
  }

  c49_i23 = 0;
  for (c49_i24 = 0; c49_i24 < 3; c49_i24++) {
    for (c49_i25 = 0; c49_i25 < 3; c49_i25++) {
      c49_b_Calibration.KVHOrientation[c49_i25 + c49_i23] = ((real_T *)&((char_T
        *)chartInstance->c49_Calibration)[656])[c49_i25 + c49_i23];
    }

    c49_i23 += 3;
  }

  c49_i26 = 0;
  for (c49_i27 = 0; c49_i27 < 3; c49_i27++) {
    for (c49_i28 = 0; c49_i28 < 3; c49_i28++) {
      c49_b_Calibration.MicrostrainOrientation[c49_i28 + c49_i26] = ((real_T *)
        &((char_T *)chartInstance->c49_Calibration)[728])[c49_i28 + c49_i26];
    }

    c49_i26 += 3;
  }

  for (c49_i29 = 0; c49_i29 < 10; c49_i29++) {
    c49_b_AbsEncoders[c49_i29] = (*chartInstance->c49_AbsEncoders)[c49_i29];
  }

  for (c49_i30 = 0; c49_i30 < 9; c49_i30++) {
    c49_b_IncEncoders[c49_i30] = (*chartInstance->c49_IncEncoders)[c49_i30];
  }

  for (c49_i31 = 0; c49_i31 < 9; c49_i31++) {
    c49_b_IncEncodersPrev[c49_i31] = (*chartInstance->c49_IncEncodersPrev)
      [c49_i31];
  }

  c49_b_Reset = c49_hoistedGlobal;
  for (c49_i32 = 0; c49_i32 < 9; c49_i32++) {
    c49_b_RolloverIn[c49_i32] = (*chartInstance->c49_RolloverIn)[c49_i32];
  }

  for (c49_i33 = 0; c49_i33 < 6; c49_i33++) {
    c49_b_IncCalTickIn[c49_i33] = (*chartInstance->c49_IncCalTickIn)[c49_i33];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c49_debug_family_names,
    c49_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c49_nargin, 0U, c49_f_sf_marshallOut,
    c49_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c49_nargout, 1U, c49_f_sf_marshallOut,
    c49_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c49_b_Calibration, 2U, c49_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c49_b_AbsEncoders, 3U, c49_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c49_b_IncEncoders, 4U, c49_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c49_b_IncEncodersPrev, 5U, c49_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c49_b_Reset, 6U, c49_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c49_b_RolloverIn, 7U, c49_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c49_b_IncCalTickIn, 8U, c49_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_AbsAngle, 9U, c49_c_sf_marshallOut,
    c49_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_IncAngle, 10U, c49_b_sf_marshallOut,
    c49_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_Rollover, 11U, c49_b_sf_marshallOut,
    c49_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_IncCalTick, 12U, c49_sf_marshallOut,
    c49_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c49_sfEvent, 3);
  c49_c_Calibration = c49_b_Calibration;
  for (c49_i34 = 0; c49_i34 < 10; c49_i34++) {
    c49_c_AbsEncoders[c49_i34] = c49_b_AbsEncoders[c49_i34];
  }

  for (c49_i35 = 0; c49_i35 < 9; c49_i35++) {
    c49_c_IncEncoders[c49_i35] = c49_b_IncEncoders[c49_i35];
  }

  for (c49_i36 = 0; c49_i36 < 9; c49_i36++) {
    c49_c_IncEncodersPrev[c49_i36] = c49_b_IncEncodersPrev[c49_i36];
  }

  for (c49_i37 = 0; c49_i37 < 9; c49_i37++) {
    c49_c_RolloverIn[c49_i37] = c49_b_RolloverIn[c49_i37];
  }

  for (c49_i38 = 0; c49_i38 < 6; c49_i38++) {
    c49_c_IncCalTickIn[c49_i38] = c49_b_IncCalTickIn[c49_i38];
  }

  c49_calibrateEncoders_ATRIAS(chartInstance, &c49_c_Calibration,
    c49_c_AbsEncoders, c49_c_IncEncoders, c49_c_IncEncodersPrev, c49_b_Reset,
    c49_c_RolloverIn, c49_c_IncCalTickIn, c49_c_AbsAngle, c49_c_IncAngle,
    c49_c_Rollover, c49_c_IncCalTick);
  for (c49_i39 = 0; c49_i39 < 10; c49_i39++) {
    c49_b_AbsAngle[c49_i39] = c49_c_AbsAngle[c49_i39];
  }

  for (c49_i40 = 0; c49_i40 < 9; c49_i40++) {
    c49_b_IncAngle[c49_i40] = c49_c_IncAngle[c49_i40];
  }

  for (c49_i41 = 0; c49_i41 < 9; c49_i41++) {
    c49_b_Rollover[c49_i41] = c49_c_Rollover[c49_i41];
  }

  for (c49_i42 = 0; c49_i42 < 6; c49_i42++) {
    c49_b_IncCalTick[c49_i42] = c49_c_IncCalTick[c49_i42];
  }

  _SFD_EML_CALL(0U, chartInstance->c49_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c49_i43 = 0; c49_i43 < 10; c49_i43++) {
    (*chartInstance->c49_AbsAngle)[c49_i43] = c49_b_AbsAngle[c49_i43];
  }

  for (c49_i44 = 0; c49_i44 < 9; c49_i44++) {
    (*chartInstance->c49_IncAngle)[c49_i44] = c49_b_IncAngle[c49_i44];
  }

  for (c49_i45 = 0; c49_i45 < 9; c49_i45++) {
    (*chartInstance->c49_Rollover)[c49_i45] = c49_b_Rollover[c49_i45];
  }

  for (c49_i46 = 0; c49_i46 < 6; c49_i46++) {
    (*chartInstance->c49_IncCalTick)[c49_i46] = c49_b_IncCalTick[c49_i46];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, chartInstance->c49_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking_ATRIASMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c49_i47 = 0; c49_i47 < 10; c49_i47++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c49_AbsAngle)[c49_i47], 4U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c49_Reset, 5U);
  for (c49_i48 = 0; c49_i48 < 9; c49_i48++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c49_IncAngle)[c49_i48], 6U);
  }

  for (c49_i49 = 0; c49_i49 < 9; c49_i49++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c49_RolloverIn)[c49_i49], 7U);
  }

  for (c49_i50 = 0; c49_i50 < 9; c49_i50++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c49_Rollover)[c49_i50], 8U);
  }

  for (c49_i51 = 0; c49_i51 < 6; c49_i51++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c49_IncCalTickIn)[c49_i51], 9U);
  }

  for (c49_i52 = 0; c49_i52 < 6; c49_i52++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c49_IncCalTick)[c49_i52], 10U);
  }
}

static void mdl_start_c49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc49_Walking_ATRIAS(SFc49_Walking_ATRIASInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c49_calibrateEncoders_ATRIAS(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, c49_RobotCalibrationBus *c49_b_Calibration, real_T
  c49_b_AbsEncoders[10], real_T c49_b_IncEncoders[9], real_T
  c49_b_IncEncodersPrev[9], boolean_T c49_b_Reset, real_T c49_b_RolloverIn[9],
  real_T c49_b_IncCalTickIn[6], real_T c49_b_AbsAngle[10], real_T
  c49_b_IncAngle[9], real_T c49_b_Rollover[9], real_T c49_b_IncCalTick[6])
{
  uint32_T c49_debug_family_var_map[17];
  real_T c49_RefAngle[6];
  real_T c49_IncCalTickB[9];
  real_T c49_IncCalAngle[9];
  real_T c49_IncTick[9];
  real_T c49_nargin = 7.0;
  real_T c49_nargout = 4.0;
  int32_T c49_i53;
  real_T c49_AbsMaxTick[2];
  int32_T c49_i54;
  real_T c49_AbsCalTick[2];
  int32_T c49_i55;
  real_T c49_AbsEncoder[2];
  uint32_T c49_b_debug_family_var_map[10];
  real_T c49_HalfMaxTicks[2];
  real_T c49_CalOffset[2];
  boolean_T c49_iHigh[2];
  boolean_T c49_iLow[2];
  real_T c49_b_nargin = 3.0;
  real_T c49_b_nargout = 1.0;
  real_T c49_AbsUnrolled[2];
  int32_T c49_i56;
  int32_T c49_i57;
  real_T c49_A[2];
  int32_T c49_i58;
  int32_T c49_i59;
  int32_T c49_i60;
  boolean_T c49_bv0[2];
  int32_T c49_i61;
  boolean_T c49_bv1[2];
  int32_T c49_i62;
  int32_T c49_i63;
  boolean_T c49_b_iHigh[2];
  int32_T c49_tmp_sizes;
  int32_T c49_tmp_data[2];
  int32_T c49_b_tmp_sizes;
  int32_T c49_loop_ub;
  int32_T c49_i64;
  real_T c49_b_tmp_data[2];
  int32_T c49_i65;
  boolean_T c49_c_iHigh[2];
  int32_T c49_c_tmp_sizes;
  int32_T c49_b_loop_ub;
  int32_T c49_i66;
  real_T c49_c_tmp_data[2];
  int32_T c49_i67;
  boolean_T c49_d_iHigh[2];
  int32_T c49_c_loop_ub;
  int32_T c49_i68;
  int32_T c49_i69;
  int32_T c49_i70;
  int32_T c49_i71;
  int32_T c49_i72;
  boolean_T c49_b_iLow[2];
  int32_T c49_d_loop_ub;
  int32_T c49_i73;
  int32_T c49_i74;
  boolean_T c49_c_iLow[2];
  int32_T c49_e_loop_ub;
  int32_T c49_i75;
  int32_T c49_i76;
  boolean_T c49_d_iLow[2];
  int32_T c49_f_loop_ub;
  int32_T c49_i77;
  int32_T c49_i78;
  int32_T c49_i79;
  int32_T c49_i80;
  real_T c49_b[9];
  int32_T c49_i81;
  int32_T c49_i82;
  real_T c49_a[4];
  int32_T c49_i83;
  int32_T c49_i84;
  int32_T c49_i85;
  int32_T c49_i86;
  real_T c49_IncCalConst[6];
  int32_T c49_i87;
  real_T c49_IncMaxTick[6];
  int32_T c49_i88;
  real_T c49_c_AbsAngle[6];
  int32_T c49_i89;
  real_T c49_b_IncTick[6];
  uint32_T c49_c_debug_family_var_map[8];
  real_T c49_c_nargin = 4.0;
  real_T c49_c_nargout = 2.0;
  real_T c49_c_IncCalTick[6];
  real_T c49_dv4[6];
  int32_T c49_i90;
  real_T c49_d_AbsAngle[6];
  int32_T c49_i91;
  real_T c49_b_IncCalConst[6];
  real_T c49_x[6];
  int32_T c49_i92;
  int32_T c49_i93;
  real_T c49_y[6];
  int32_T c49_i94;
  int32_T c49_k;
  real_T c49_b_k;
  real_T c49_xk;
  real_T c49_yk;
  real_T c49_b_x;
  real_T c49_b_y;
  real_T c49_r;
  real_T c49_c_x;
  real_T c49_d_x;
  real_T c49_e_x;
  real_T c49_f_x;
  real_T c49_g_x;
  real_T c49_h_x;
  real_T c49_i_x;
  real_T c49_c_y;
  real_T c49_j_x;
  real_T c49_d_y;
  real_T c49_k_x;
  real_T c49_l_x;
  int32_T c49_i95;
  real_T c49_e_AbsAngle[6];
  int32_T c49_i96;
  real_T c49_c_IncCalConst[6];
  int32_T c49_i97;
  real_T c49_m_x[6];
  int32_T c49_i98;
  real_T c49_b_IncMaxTick[6];
  int32_T c49_i99;
  int32_T c49_c_k;
  real_T c49_d_k;
  real_T c49_n_x;
  real_T c49_o_x;
  int32_T c49_i100;
  int32_T c49_i101;
  int32_T c49_i102;
  real_T c49_MaxTick[9];
  int32_T c49_i103;
  real_T c49_c_IncEncoders[9];
  int32_T c49_i104;
  real_T c49_c_IncEncodersPrev[9];
  real_T c49_NormalizedCountPrev[9];
  real_T c49_NormalizedCount[9];
  real_T c49_d_nargin = 3.0;
  real_T c49_d_nargout = 1.0;
  real_T c49_c_Rollover[9];
  int32_T c49_i105;
  real_T c49_d_IncEncodersPrev[9];
  int32_T c49_i106;
  real_T c49_b_MaxTick[9];
  real_T c49_dv5[9];
  int32_T c49_i107;
  int32_T c49_i108;
  real_T c49_d_IncEncoders[9];
  int32_T c49_i109;
  real_T c49_c_MaxTick[9];
  real_T c49_dv6[9];
  int32_T c49_i110;
  int32_T c49_i111;
  int32_T c49_i112;
  boolean_T c49_bv2[9];
  int32_T c49_i113;
  boolean_T c49_bv3[9];
  int32_T c49_i114;
  boolean_T c49_bv4[9];
  int32_T c49_d_tmp_sizes;
  int32_T c49_d_tmp_data[9];
  int32_T c49_g_loop_ub;
  int32_T c49_i115;
  int32_T c49_i116;
  int32_T c49_i117;
  int32_T c49_i118;
  boolean_T c49_bv5[9];
  int32_T c49_h_loop_ub;
  int32_T c49_i119;
  int32_T c49_i120;
  int32_T c49_i121;
  int32_T c49_i122;
  int32_T c49_i123;
  int32_T c49_i124;
  int32_T c49_i125;
  int32_T c49_i126;
  int32_T c49_i127;
  real_T c49_c_Calibration[9];
  int32_T c49_i128;
  int32_T c49_i129;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c49_e_debug_family_names,
    c49_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_RefAngle, 0U, c49_sf_marshallOut,
    c49_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_IncCalTickB, 1U, c49_b_sf_marshallOut,
    c49_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_IncCalAngle, 2U, c49_b_sf_marshallOut,
    c49_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_IncTick, 3U, c49_b_sf_marshallOut,
    c49_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c49_nargin, 4U, c49_f_sf_marshallOut,
    c49_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c49_nargout, 5U, c49_f_sf_marshallOut,
    c49_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_Calibration, 6U,
    c49_e_sf_marshallOut, c49_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_AbsEncoders, 7U,
    c49_c_sf_marshallOut, c49_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_IncEncoders, 8U,
    c49_b_sf_marshallOut, c49_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_IncEncodersPrev, 9U,
    c49_b_sf_marshallOut, c49_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c49_b_Reset, 10U, c49_d_sf_marshallOut,
    c49_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_RolloverIn, 11U,
    c49_b_sf_marshallOut, c49_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_IncCalTickIn, 12U,
    c49_sf_marshallOut, c49_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_AbsAngle, 13U, c49_c_sf_marshallOut,
    c49_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_IncAngle, 14U, c49_b_sf_marshallOut,
    c49_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_Rollover, 15U, c49_b_sf_marshallOut,
    c49_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_IncCalTick, 16U, c49_sf_marshallOut,
    c49_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 11);
  for (c49_i53 = 0; c49_i53 < 2; c49_i53++) {
    c49_AbsMaxTick[c49_i53] = c49_b_Calibration->AbsMaxTick[c49_i53 + 8];
  }

  for (c49_i54 = 0; c49_i54 < 2; c49_i54++) {
    c49_AbsCalTick[c49_i54] = c49_b_Calibration->AbsCalTick[c49_i54 + 8];
  }

  for (c49_i55 = 0; c49_i55 < 2; c49_i55++) {
    c49_AbsEncoder[c49_i55] = c49_b_AbsEncoders[c49_i55 + 8];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c49_b_debug_family_names,
    c49_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_HalfMaxTicks, 0U,
    c49_g_sf_marshallOut, c49_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_CalOffset, 1U, c49_g_sf_marshallOut,
    c49_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_iHigh, 2U, c49_h_sf_marshallOut,
    c49_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_iLow, 3U, c49_h_sf_marshallOut,
    c49_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c49_b_nargin, 4U, c49_f_sf_marshallOut,
    c49_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c49_b_nargout, 5U, c49_f_sf_marshallOut,
    c49_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_AbsMaxTick, 6U, c49_g_sf_marshallOut,
    c49_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_AbsCalTick, 7U, c49_g_sf_marshallOut,
    c49_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_AbsEncoder, 8U, c49_g_sf_marshallOut,
    c49_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_AbsUnrolled, 9U, c49_g_sf_marshallOut,
    c49_e_sf_marshallIn);
  CV_SCRIPT_FCN(0, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 68);
  for (c49_i56 = 0; c49_i56 < 2; c49_i56++) {
    c49_AbsUnrolled[c49_i56] = c49_AbsEncoder[c49_i56];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 71);
  for (c49_i57 = 0; c49_i57 < 2; c49_i57++) {
    c49_A[c49_i57] = c49_AbsMaxTick[c49_i57];
  }

  for (c49_i58 = 0; c49_i58 < 2; c49_i58++) {
    c49_HalfMaxTicks[c49_i58] = c49_A[c49_i58] / 2.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 72);
  for (c49_i59 = 0; c49_i59 < 2; c49_i59++) {
    c49_CalOffset[c49_i59] = c49_AbsCalTick[c49_i59] - c49_HalfMaxTicks[c49_i59];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 77);
  for (c49_i60 = 0; c49_i60 < 2; c49_i60++) {
    c49_bv0[c49_i60] = (c49_CalOffset[c49_i60] < 0.0);
  }

  for (c49_i61 = 0; c49_i61 < 2; c49_i61++) {
    c49_bv1[c49_i61] = (c49_AbsEncoder[c49_i61] > c49_AbsCalTick[c49_i61] +
                        c49_HalfMaxTicks[c49_i61]);
  }

  for (c49_i62 = 0; c49_i62 < 2; c49_i62++) {
    c49_iHigh[c49_i62] = (c49_bv0[c49_i62] && c49_bv1[c49_i62]);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 78);
  for (c49_i63 = 0; c49_i63 < 2; c49_i63++) {
    c49_b_iHigh[c49_i63] = c49_iHigh[c49_i63];
  }

  c49_eml_li_find(chartInstance, c49_b_iHigh, c49_tmp_data, &c49_tmp_sizes);
  c49_b_tmp_sizes = c49_tmp_sizes;
  c49_loop_ub = c49_tmp_sizes - 1;
  for (c49_i64 = 0; c49_i64 <= c49_loop_ub; c49_i64++) {
    c49_b_tmp_data[c49_i64] = c49_AbsUnrolled[c49_tmp_data[c49_i64] - 1];
  }

  for (c49_i65 = 0; c49_i65 < 2; c49_i65++) {
    c49_c_iHigh[c49_i65] = c49_iHigh[c49_i65];
  }

  c49_eml_li_find(chartInstance, c49_c_iHigh, c49_tmp_data, &c49_tmp_sizes);
  c49_c_tmp_sizes = c49_tmp_sizes;
  c49_b_loop_ub = c49_tmp_sizes - 1;
  for (c49_i66 = 0; c49_i66 <= c49_b_loop_ub; c49_i66++) {
    c49_c_tmp_data[c49_i66] = c49_AbsMaxTick[c49_tmp_data[c49_i66] - 1];
  }

  _SFD_SIZE_EQ_CHECK_1D(c49_b_tmp_sizes, c49_c_tmp_sizes);
  for (c49_i67 = 0; c49_i67 < 2; c49_i67++) {
    c49_d_iHigh[c49_i67] = c49_iHigh[c49_i67];
  }

  c49_eml_li_find(chartInstance, c49_d_iHigh, c49_tmp_data, &c49_tmp_sizes);
  _SFD_SIZE_EQ_CHECK_1D(c49_tmp_sizes, c49_b_tmp_sizes);
  c49_c_loop_ub = c49_b_tmp_sizes - 1;
  for (c49_i68 = 0; c49_i68 <= c49_c_loop_ub; c49_i68++) {
    c49_AbsUnrolled[c49_tmp_data[c49_i68] - 1] = c49_b_tmp_data[c49_i68] -
      c49_c_tmp_data[c49_i68];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 83);
  for (c49_i69 = 0; c49_i69 < 2; c49_i69++) {
    c49_bv0[c49_i69] = (c49_CalOffset[c49_i69] > 0.0);
  }

  for (c49_i70 = 0; c49_i70 < 2; c49_i70++) {
    c49_bv1[c49_i70] = (c49_AbsEncoder[c49_i70] < c49_AbsCalTick[c49_i70] -
                        c49_HalfMaxTicks[c49_i70]);
  }

  for (c49_i71 = 0; c49_i71 < 2; c49_i71++) {
    c49_iLow[c49_i71] = (c49_bv0[c49_i71] && c49_bv1[c49_i71]);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 84);
  for (c49_i72 = 0; c49_i72 < 2; c49_i72++) {
    c49_b_iLow[c49_i72] = c49_iLow[c49_i72];
  }

  c49_eml_li_find(chartInstance, c49_b_iLow, c49_tmp_data, &c49_tmp_sizes);
  c49_b_tmp_sizes = c49_tmp_sizes;
  c49_d_loop_ub = c49_tmp_sizes - 1;
  for (c49_i73 = 0; c49_i73 <= c49_d_loop_ub; c49_i73++) {
    c49_b_tmp_data[c49_i73] = c49_AbsUnrolled[c49_tmp_data[c49_i73] - 1];
  }

  for (c49_i74 = 0; c49_i74 < 2; c49_i74++) {
    c49_c_iLow[c49_i74] = c49_iLow[c49_i74];
  }

  c49_eml_li_find(chartInstance, c49_c_iLow, c49_tmp_data, &c49_tmp_sizes);
  c49_c_tmp_sizes = c49_tmp_sizes;
  c49_e_loop_ub = c49_tmp_sizes - 1;
  for (c49_i75 = 0; c49_i75 <= c49_e_loop_ub; c49_i75++) {
    c49_c_tmp_data[c49_i75] = c49_AbsMaxTick[c49_tmp_data[c49_i75] - 1];
  }

  _SFD_SIZE_EQ_CHECK_1D(c49_b_tmp_sizes, c49_c_tmp_sizes);
  for (c49_i76 = 0; c49_i76 < 2; c49_i76++) {
    c49_d_iLow[c49_i76] = c49_iLow[c49_i76];
  }

  c49_eml_li_find(chartInstance, c49_d_iLow, c49_tmp_data, &c49_tmp_sizes);
  _SFD_SIZE_EQ_CHECK_1D(c49_tmp_sizes, c49_b_tmp_sizes);
  c49_f_loop_ub = c49_b_tmp_sizes - 1;
  for (c49_i77 = 0; c49_i77 <= c49_f_loop_ub; c49_i77++) {
    c49_AbsUnrolled[c49_tmp_data[c49_i77] - 1] = c49_b_tmp_data[c49_i77] +
      c49_c_tmp_data[c49_i77];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, -84);
  _SFD_SYMBOL_SCOPE_POP();
  for (c49_i78 = 0; c49_i78 < 2; c49_i78++) {
    c49_b_AbsEncoders[c49_i78 + 8] = c49_AbsUnrolled[c49_i78];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 14);
  for (c49_i79 = 0; c49_i79 < 10; c49_i79++) {
    c49_b_AbsAngle[c49_i79] = c49_b_Calibration->AbsCalAngle[c49_i79] +
      c49_b_Calibration->AbsCalConst[c49_i79] * (c49_b_AbsEncoders[c49_i79] -
      c49_b_Calibration->AbsCalTick[c49_i79]);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 17);
  if (CV_SCRIPT_IF(0, 0, c49_b_Reset)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 18);
    for (c49_i80 = 0; c49_i80 < 9; c49_i80++) {
      c49_b[c49_i80] = c49_b_RolloverIn[c49_i80];
    }

    for (c49_i81 = 0; c49_i81 < 9; c49_i81++) {
      c49_b_Rollover[c49_i81] = 0.0 * c49_b[c49_i81];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 19);
    for (c49_i82 = 0; c49_i82 < 4; c49_i82++) {
      c49_a[c49_i82] = c49_b_AbsAngle[c49_i82 + 4];
    }

    for (c49_i83 = 0; c49_i83 < 4; c49_i83++) {
      c49_a[c49_i83] *= 50.0;
    }

    for (c49_i84 = 0; c49_i84 < 4; c49_i84++) {
      c49_RefAngle[c49_i84] = c49_a[c49_i84];
    }

    for (c49_i85 = 0; c49_i85 < 2; c49_i85++) {
      c49_RefAngle[c49_i85 + 4] = c49_b_AbsAngle[c49_i85 + 8];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 20);
    for (c49_i86 = 0; c49_i86 < 6; c49_i86++) {
      c49_IncCalConst[c49_i86] = c49_b_Calibration->IncCalConst[c49_i86];
    }

    for (c49_i87 = 0; c49_i87 < 6; c49_i87++) {
      c49_IncMaxTick[c49_i87] = c49_b_Calibration->IncMaxTick[c49_i87];
    }

    for (c49_i88 = 0; c49_i88 < 6; c49_i88++) {
      c49_c_AbsAngle[c49_i88] = c49_RefAngle[c49_i88];
    }

    for (c49_i89 = 0; c49_i89 < 6; c49_i89++) {
      c49_b_IncTick[c49_i89] = c49_b_IncEncoders[c49_i89];
    }

    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c49_c_debug_family_names,
      c49_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c49_c_nargin, 0U, c49_f_sf_marshallOut,
      c49_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c49_c_nargout, 1U,
      c49_f_sf_marshallOut, c49_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_IncCalConst, 2U, c49_sf_marshallOut,
      c49_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_IncMaxTick, 3U, c49_sf_marshallOut,
      c49_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_c_AbsAngle, 4U, c49_sf_marshallOut,
      c49_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_b_IncTick, 5U, c49_sf_marshallOut,
      c49_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_c_IncCalTick, 6U,
      c49_sf_marshallOut, c49_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_dv4, 7U, c49_sf_marshallOut,
      c49_sf_marshallIn);
    CV_SCRIPT_FCN(0, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 36);
    for (c49_i90 = 0; c49_i90 < 6; c49_i90++) {
      c49_d_AbsAngle[c49_i90] = c49_c_AbsAngle[c49_i90];
    }

    for (c49_i91 = 0; c49_i91 < 6; c49_i91++) {
      c49_b_IncCalConst[c49_i91] = c49_IncCalConst[c49_i91];
    }

    c49_rdivide(chartInstance, c49_d_AbsAngle, c49_b_IncCalConst, c49_x);
    for (c49_i92 = 0; c49_i92 < 6; c49_i92++) {
      c49_x[c49_i92] = c49_b_IncTick[c49_i92] - c49_x[c49_i92];
    }

    for (c49_i93 = 0; c49_i93 < 6; c49_i93++) {
      c49_y[c49_i93] = c49_IncMaxTick[c49_i93];
    }

    for (c49_i94 = 0; c49_i94 < 6; c49_i94++) {
      c49_c_IncCalTick[c49_i94] = 0.0;
    }

    for (c49_k = 0; c49_k < 6; c49_k++) {
      c49_b_k = 1.0 + (real_T)c49_k;
      c49_xk = c49_x[(int32_T)c49_b_k - 1];
      c49_yk = c49_y[(int32_T)c49_b_k - 1];
      c49_b_x = c49_xk;
      c49_b_y = c49_yk;
      if (c49_b_y == 0.0) {
        c49_r = c49_b_x;
      } else {
        c49_c_x = c49_b_y;
        c49_d_x = c49_c_x;
        c49_d_x = muDoubleScalarFloor(c49_d_x);
        if (c49_b_y == c49_d_x) {
          c49_e_x = c49_b_x / c49_b_y;
          c49_f_x = c49_e_x;
          c49_f_x = muDoubleScalarFloor(c49_f_x);
          c49_r = c49_b_x - c49_f_x * c49_b_y;
        } else {
          c49_r = c49_b_x / c49_b_y;
          c49_g_x = c49_r;
          c49_h_x = c49_g_x;
          c49_h_x = muDoubleScalarRound(c49_h_x);
          c49_i_x = c49_r - c49_h_x;
          c49_c_y = muDoubleScalarAbs(c49_i_x);
          c49_j_x = c49_r;
          c49_d_y = muDoubleScalarAbs(c49_j_x);
          if (c49_c_y <= 2.2204460492503131E-16 * c49_d_y) {
            c49_r = 0.0;
          } else {
            c49_k_x = c49_r;
            c49_l_x = c49_k_x;
            c49_l_x = muDoubleScalarFloor(c49_l_x);
            c49_r = (c49_r - c49_l_x) * c49_b_y;
          }
        }
      }

      c49_c_IncCalTick[(int32_T)c49_b_k - 1] = c49_r;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 38);
    for (c49_i95 = 0; c49_i95 < 6; c49_i95++) {
      c49_e_AbsAngle[c49_i95] = c49_c_AbsAngle[c49_i95];
    }

    for (c49_i96 = 0; c49_i96 < 6; c49_i96++) {
      c49_c_IncCalConst[c49_i96] = c49_IncCalConst[c49_i96];
    }

    c49_rdivide(chartInstance, c49_e_AbsAngle, c49_c_IncCalConst, c49_x);
    for (c49_i97 = 0; c49_i97 < 6; c49_i97++) {
      c49_m_x[c49_i97] = (c49_x[c49_i97] - c49_b_IncTick[c49_i97]) +
        c49_c_IncCalTick[c49_i97];
    }

    for (c49_i98 = 0; c49_i98 < 6; c49_i98++) {
      c49_b_IncMaxTick[c49_i98] = c49_IncMaxTick[c49_i98];
    }

    c49_rdivide(chartInstance, c49_m_x, c49_b_IncMaxTick, c49_x);
    for (c49_i99 = 0; c49_i99 < 6; c49_i99++) {
      c49_dv4[c49_i99] = c49_x[c49_i99];
    }

    for (c49_c_k = 0; c49_c_k < 6; c49_c_k++) {
      c49_d_k = 1.0 + (real_T)c49_c_k;
      c49_n_x = c49_dv4[(int32_T)c49_d_k - 1];
      c49_o_x = c49_n_x;
      c49_o_x = muDoubleScalarFloor(c49_o_x);
      c49_dv4[(int32_T)c49_d_k - 1] = c49_o_x;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, -38);
    _SFD_SYMBOL_SCOPE_POP();
    for (c49_i100 = 0; c49_i100 < 6; c49_i100++) {
      c49_b_IncCalTick[c49_i100] = c49_c_IncCalTick[c49_i100];
    }

    for (c49_i101 = 0; c49_i101 < 6; c49_i101++) {
      c49_b_Rollover[c49_i101] = c49_dv4[c49_i101];
    }
  } else {
    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 23);
    for (c49_i102 = 0; c49_i102 < 9; c49_i102++) {
      c49_MaxTick[c49_i102] = c49_b_Calibration->MaxTick[c49_i102];
    }

    for (c49_i103 = 0; c49_i103 < 9; c49_i103++) {
      c49_c_IncEncoders[c49_i103] = c49_b_IncEncoders[c49_i103];
    }

    for (c49_i104 = 0; c49_i104 < 9; c49_i104++) {
      c49_c_IncEncodersPrev[c49_i104] = c49_b_IncEncodersPrev[c49_i104];
    }

    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c49_d_debug_family_names,
      c49_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_NormalizedCountPrev, 0U,
      c49_b_sf_marshallOut, c49_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_NormalizedCount, 1U,
      c49_b_sf_marshallOut, c49_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c49_d_nargin, 2U, c49_f_sf_marshallOut,
      c49_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c49_d_nargout, 3U,
      c49_f_sf_marshallOut, c49_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_MaxTick, 4U, c49_b_sf_marshallOut,
      c49_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_c_IncEncoders, 5U,
      c49_b_sf_marshallOut, c49_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_c_IncEncodersPrev, 6U,
      c49_b_sf_marshallOut, c49_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c49_c_Rollover, 7U,
      c49_b_sf_marshallOut, c49_b_sf_marshallIn);
    CV_SCRIPT_FCN(0, 2);
    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 55);
    for (c49_i105 = 0; c49_i105 < 9; c49_i105++) {
      c49_d_IncEncodersPrev[c49_i105] = c49_c_IncEncodersPrev[c49_i105];
    }

    for (c49_i106 = 0; c49_i106 < 9; c49_i106++) {
      c49_b_MaxTick[c49_i106] = c49_MaxTick[c49_i106];
    }

    c49_b_rdivide(chartInstance, c49_d_IncEncodersPrev, c49_b_MaxTick, c49_dv5);
    for (c49_i107 = 0; c49_i107 < 9; c49_i107++) {
      c49_NormalizedCountPrev[c49_i107] = c49_dv5[c49_i107];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 56);
    for (c49_i108 = 0; c49_i108 < 9; c49_i108++) {
      c49_d_IncEncoders[c49_i108] = c49_c_IncEncoders[c49_i108];
    }

    for (c49_i109 = 0; c49_i109 < 9; c49_i109++) {
      c49_c_MaxTick[c49_i109] = c49_MaxTick[c49_i109];
    }

    c49_b_rdivide(chartInstance, c49_d_IncEncoders, c49_c_MaxTick, c49_dv6);
    for (c49_i110 = 0; c49_i110 < 9; c49_i110++) {
      c49_NormalizedCount[c49_i110] = c49_dv6[c49_i110];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 58);
    for (c49_i111 = 0; c49_i111 < 9; c49_i111++) {
      c49_c_Rollover[c49_i111] = 0.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 59);
    for (c49_i112 = 0; c49_i112 < 9; c49_i112++) {
      c49_bv2[c49_i112] = (c49_NormalizedCountPrev[c49_i112] < 0.5);
    }

    for (c49_i113 = 0; c49_i113 < 9; c49_i113++) {
      c49_bv3[c49_i113] = (c49_NormalizedCount[c49_i113] >
                           c49_NormalizedCountPrev[c49_i113] + 0.5);
    }

    for (c49_i114 = 0; c49_i114 < 9; c49_i114++) {
      c49_bv4[c49_i114] = (c49_bv2[c49_i114] && c49_bv3[c49_i114]);
    }

    c49_b_eml_li_find(chartInstance, c49_bv4, c49_d_tmp_data, &c49_d_tmp_sizes);
    c49_g_loop_ub = c49_d_tmp_sizes - 1;
    for (c49_i115 = 0; c49_i115 <= c49_g_loop_ub; c49_i115++) {
      c49_c_Rollover[c49_d_tmp_data[c49_i115] - 1] = -1.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 60);
    for (c49_i116 = 0; c49_i116 < 9; c49_i116++) {
      c49_bv2[c49_i116] = (c49_NormalizedCountPrev[c49_i116] > 0.5);
    }

    for (c49_i117 = 0; c49_i117 < 9; c49_i117++) {
      c49_bv3[c49_i117] = (c49_NormalizedCount[c49_i117] <
                           c49_NormalizedCountPrev[c49_i117] - 0.5);
    }

    for (c49_i118 = 0; c49_i118 < 9; c49_i118++) {
      c49_bv5[c49_i118] = (c49_bv2[c49_i118] && c49_bv3[c49_i118]);
    }

    c49_b_eml_li_find(chartInstance, c49_bv5, c49_d_tmp_data, &c49_d_tmp_sizes);
    c49_h_loop_ub = c49_d_tmp_sizes - 1;
    for (c49_i119 = 0; c49_i119 <= c49_h_loop_ub; c49_i119++) {
      c49_c_Rollover[c49_d_tmp_data[c49_i119] - 1] = 1.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, -60);
    _SFD_SYMBOL_SCOPE_POP();
    for (c49_i120 = 0; c49_i120 < 9; c49_i120++) {
      c49_b_Rollover[c49_i120] = c49_b_RolloverIn[c49_i120] +
        c49_c_Rollover[c49_i120];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 24);
    for (c49_i121 = 0; c49_i121 < 6; c49_i121++) {
      c49_b_IncCalTick[c49_i121] = c49_b_IncCalTickIn[c49_i121];
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 28);
  for (c49_i122 = 0; c49_i122 < 6; c49_i122++) {
    c49_IncCalTickB[c49_i122] = c49_b_IncCalTick[c49_i122];
  }

  for (c49_i123 = 0; c49_i123 < 3; c49_i123++) {
    c49_IncCalTickB[c49_i123 + 6] = c49_b_Calibration->BoomCalTick[c49_i123];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 29);
  for (c49_i124 = 0; c49_i124 < 6; c49_i124++) {
    c49_IncCalAngle[c49_i124] = 0.0;
  }

  for (c49_i125 = 0; c49_i125 < 3; c49_i125++) {
    c49_IncCalAngle[c49_i125 + 6] = c49_b_Calibration->BoomCalAngle[c49_i125];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 30);
  for (c49_i126 = 0; c49_i126 < 9; c49_i126++) {
    c49_IncTick[c49_i126] = c49_b_IncEncoders[c49_i126] +
      c49_b_Calibration->MaxTick[c49_i126] * c49_b_Rollover[c49_i126];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, 31);
  for (c49_i127 = 0; c49_i127 < 6; c49_i127++) {
    c49_c_Calibration[c49_i127] = c49_b_Calibration->IncCalConst[c49_i127];
  }

  for (c49_i128 = 0; c49_i128 < 3; c49_i128++) {
    c49_c_Calibration[c49_i128 + 6] = c49_b_Calibration->BoomCalConst[c49_i128];
  }

  for (c49_i129 = 0; c49_i129 < 9; c49_i129++) {
    c49_b_IncAngle[c49_i129] = c49_IncCalAngle[c49_i129] +
      c49_c_Calibration[c49_i129] * (c49_IncTick[c49_i129] -
      c49_IncCalTickB[c49_i129]);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c49_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c49_machineNumber, uint32_T
  c49_chartNumber, uint32_T c49_instanceNumber)
{
  (void)c49_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c49_chartNumber, c49_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\DAQ\\calibrateEncoders_ATRIAS.m"));
}

static const mxArray *c49_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData)
{
  const mxArray *c49_mxArrayOutData = NULL;
  int32_T c49_i130;
  real_T c49_b_inData[6];
  int32_T c49_i131;
  real_T c49_u[6];
  const mxArray *c49_y = NULL;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_mxArrayOutData = NULL;
  for (c49_i130 = 0; c49_i130 < 6; c49_i130++) {
    c49_b_inData[c49_i130] = (*(real_T (*)[6])c49_inData)[c49_i130];
  }

  for (c49_i131 = 0; c49_i131 < 6; c49_i131++) {
    c49_u[c49_i131] = c49_b_inData[c49_i131];
  }

  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", c49_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c49_mxArrayOutData, c49_y, false);
  return c49_mxArrayOutData;
}

static void c49_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_b_IncCalTick, const char_T *c49_identifier,
  real_T c49_y[6])
{
  emlrtMsgIdentifier c49_thisId;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_b_IncCalTick),
    &c49_thisId, c49_y);
  sf_mex_destroy(&c49_b_IncCalTick);
}

static void c49_b_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  real_T c49_y[6])
{
  real_T c49_dv7[6];
  int32_T c49_i132;
  (void)chartInstance;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), c49_dv7, 1, 0, 0U, 1, 0U, 1, 6);
  for (c49_i132 = 0; c49_i132 < 6; c49_i132++) {
    c49_y[c49_i132] = c49_dv7[c49_i132];
  }

  sf_mex_destroy(&c49_u);
}

static void c49_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData)
{
  const mxArray *c49_b_IncCalTick;
  const char_T *c49_identifier;
  emlrtMsgIdentifier c49_thisId;
  real_T c49_y[6];
  int32_T c49_i133;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_b_IncCalTick = sf_mex_dup(c49_mxArrayInData);
  c49_identifier = c49_varName;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_b_IncCalTick),
    &c49_thisId, c49_y);
  sf_mex_destroy(&c49_b_IncCalTick);
  for (c49_i133 = 0; c49_i133 < 6; c49_i133++) {
    (*(real_T (*)[6])c49_outData)[c49_i133] = c49_y[c49_i133];
  }

  sf_mex_destroy(&c49_mxArrayInData);
}

static const mxArray *c49_b_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData)
{
  const mxArray *c49_mxArrayOutData = NULL;
  int32_T c49_i134;
  real_T c49_b_inData[9];
  int32_T c49_i135;
  real_T c49_u[9];
  const mxArray *c49_y = NULL;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_mxArrayOutData = NULL;
  for (c49_i134 = 0; c49_i134 < 9; c49_i134++) {
    c49_b_inData[c49_i134] = (*(real_T (*)[9])c49_inData)[c49_i134];
  }

  for (c49_i135 = 0; c49_i135 < 9; c49_i135++) {
    c49_u[c49_i135] = c49_b_inData[c49_i135];
  }

  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", c49_u, 0, 0U, 1U, 0U, 1, 9), false);
  sf_mex_assign(&c49_mxArrayOutData, c49_y, false);
  return c49_mxArrayOutData;
}

static void c49_c_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_b_Rollover, const char_T *c49_identifier,
  real_T c49_y[9])
{
  emlrtMsgIdentifier c49_thisId;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_b_Rollover), &c49_thisId,
    c49_y);
  sf_mex_destroy(&c49_b_Rollover);
}

static void c49_d_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  real_T c49_y[9])
{
  real_T c49_dv8[9];
  int32_T c49_i136;
  (void)chartInstance;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), c49_dv8, 1, 0, 0U, 1, 0U, 1, 9);
  for (c49_i136 = 0; c49_i136 < 9; c49_i136++) {
    c49_y[c49_i136] = c49_dv8[c49_i136];
  }

  sf_mex_destroy(&c49_u);
}

static void c49_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData)
{
  const mxArray *c49_b_Rollover;
  const char_T *c49_identifier;
  emlrtMsgIdentifier c49_thisId;
  real_T c49_y[9];
  int32_T c49_i137;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_b_Rollover = sf_mex_dup(c49_mxArrayInData);
  c49_identifier = c49_varName;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_b_Rollover), &c49_thisId,
    c49_y);
  sf_mex_destroy(&c49_b_Rollover);
  for (c49_i137 = 0; c49_i137 < 9; c49_i137++) {
    (*(real_T (*)[9])c49_outData)[c49_i137] = c49_y[c49_i137];
  }

  sf_mex_destroy(&c49_mxArrayInData);
}

static const mxArray *c49_c_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData)
{
  const mxArray *c49_mxArrayOutData = NULL;
  int32_T c49_i138;
  real_T c49_b_inData[10];
  int32_T c49_i139;
  real_T c49_u[10];
  const mxArray *c49_y = NULL;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_mxArrayOutData = NULL;
  for (c49_i138 = 0; c49_i138 < 10; c49_i138++) {
    c49_b_inData[c49_i138] = (*(real_T (*)[10])c49_inData)[c49_i138];
  }

  for (c49_i139 = 0; c49_i139 < 10; c49_i139++) {
    c49_u[c49_i139] = c49_b_inData[c49_i139];
  }

  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", c49_u, 0, 0U, 1U, 0U, 1, 10), false);
  sf_mex_assign(&c49_mxArrayOutData, c49_y, false);
  return c49_mxArrayOutData;
}

static void c49_e_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_b_AbsAngle, const char_T *c49_identifier,
  real_T c49_y[10])
{
  emlrtMsgIdentifier c49_thisId;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_b_AbsAngle), &c49_thisId,
    c49_y);
  sf_mex_destroy(&c49_b_AbsAngle);
}

static void c49_f_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  real_T c49_y[10])
{
  real_T c49_dv9[10];
  int32_T c49_i140;
  (void)chartInstance;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), c49_dv9, 1, 0, 0U, 1, 0U, 1, 10);
  for (c49_i140 = 0; c49_i140 < 10; c49_i140++) {
    c49_y[c49_i140] = c49_dv9[c49_i140];
  }

  sf_mex_destroy(&c49_u);
}

static void c49_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData)
{
  const mxArray *c49_b_AbsAngle;
  const char_T *c49_identifier;
  emlrtMsgIdentifier c49_thisId;
  real_T c49_y[10];
  int32_T c49_i141;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_b_AbsAngle = sf_mex_dup(c49_mxArrayInData);
  c49_identifier = c49_varName;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_b_AbsAngle), &c49_thisId,
    c49_y);
  sf_mex_destroy(&c49_b_AbsAngle);
  for (c49_i141 = 0; c49_i141 < 10; c49_i141++) {
    (*(real_T (*)[10])c49_outData)[c49_i141] = c49_y[c49_i141];
  }

  sf_mex_destroy(&c49_mxArrayInData);
}

static const mxArray *c49_d_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData)
{
  const mxArray *c49_mxArrayOutData = NULL;
  boolean_T c49_u;
  const mxArray *c49_y = NULL;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_mxArrayOutData = NULL;
  c49_u = *(boolean_T *)c49_inData;
  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", &c49_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c49_mxArrayOutData, c49_y, false);
  return c49_mxArrayOutData;
}

static const mxArray *c49_e_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData)
{
  const mxArray *c49_mxArrayOutData = NULL;
  c49_RobotCalibrationBus c49_u;
  const mxArray *c49_y = NULL;
  int32_T c49_i142;
  real_T c49_b_u[10];
  const mxArray *c49_b_y = NULL;
  int32_T c49_i143;
  real_T c49_c_u[3];
  const mxArray *c49_c_y = NULL;
  int32_T c49_i144;
  real_T c49_d_u[10];
  const mxArray *c49_d_y = NULL;
  int32_T c49_i145;
  real_T c49_e_u[10];
  const mxArray *c49_e_y = NULL;
  int32_T c49_i146;
  real_T c49_f_u[10];
  const mxArray *c49_f_y = NULL;
  int32_T c49_i147;
  real_T c49_g_u[6];
  const mxArray *c49_g_y = NULL;
  int32_T c49_i148;
  real_T c49_h_u[6];
  const mxArray *c49_h_y = NULL;
  int32_T c49_i149;
  real_T c49_i_u[3];
  const mxArray *c49_i_y = NULL;
  int32_T c49_i150;
  real_T c49_j_u[3];
  const mxArray *c49_j_y = NULL;
  int32_T c49_i151;
  real_T c49_k_u[3];
  const mxArray *c49_k_y = NULL;
  int32_T c49_i152;
  real_T c49_l_u[9];
  const mxArray *c49_l_y = NULL;
  int32_T c49_i153;
  real_T c49_m_u[9];
  const mxArray *c49_m_y = NULL;
  int32_T c49_i154;
  real_T c49_n_u[9];
  const mxArray *c49_n_y = NULL;
  int32_T c49_i155;
  real_T c49_o_u[9];
  const mxArray *c49_o_y = NULL;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_mxArrayOutData = NULL;
  c49_u = *(c49_RobotCalibrationBus *)c49_inData;
  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c49_i142 = 0; c49_i142 < 10; c49_i142++) {
    c49_b_u[c49_i142] = c49_u.AbsCalTick[c49_i142];
  }

  c49_b_y = NULL;
  sf_mex_assign(&c49_b_y, sf_mex_create("y", c49_b_u, 0, 0U, 1U, 0U, 1, 10),
                false);
  sf_mex_addfield(c49_y, c49_b_y, "AbsCalTick", "AbsCalTick", 0);
  for (c49_i143 = 0; c49_i143 < 3; c49_i143++) {
    c49_c_u[c49_i143] = c49_u.BoomCalTick[c49_i143];
  }

  c49_c_y = NULL;
  sf_mex_assign(&c49_c_y, sf_mex_create("y", c49_c_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_addfield(c49_y, c49_c_y, "BoomCalTick", "BoomCalTick", 0);
  for (c49_i144 = 0; c49_i144 < 10; c49_i144++) {
    c49_d_u[c49_i144] = c49_u.AbsCalConst[c49_i144];
  }

  c49_d_y = NULL;
  sf_mex_assign(&c49_d_y, sf_mex_create("y", c49_d_u, 0, 0U, 1U, 0U, 1, 10),
                false);
  sf_mex_addfield(c49_y, c49_d_y, "AbsCalConst", "AbsCalConst", 0);
  for (c49_i145 = 0; c49_i145 < 10; c49_i145++) {
    c49_e_u[c49_i145] = c49_u.AbsCalAngle[c49_i145];
  }

  c49_e_y = NULL;
  sf_mex_assign(&c49_e_y, sf_mex_create("y", c49_e_u, 0, 0U, 1U, 0U, 1, 10),
                false);
  sf_mex_addfield(c49_y, c49_e_y, "AbsCalAngle", "AbsCalAngle", 0);
  for (c49_i146 = 0; c49_i146 < 10; c49_i146++) {
    c49_f_u[c49_i146] = c49_u.AbsMaxTick[c49_i146];
  }

  c49_f_y = NULL;
  sf_mex_assign(&c49_f_y, sf_mex_create("y", c49_f_u, 0, 0U, 1U, 0U, 1, 10),
                false);
  sf_mex_addfield(c49_y, c49_f_y, "AbsMaxTick", "AbsMaxTick", 0);
  for (c49_i147 = 0; c49_i147 < 6; c49_i147++) {
    c49_g_u[c49_i147] = c49_u.IncCalConst[c49_i147];
  }

  c49_g_y = NULL;
  sf_mex_assign(&c49_g_y, sf_mex_create("y", c49_g_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c49_y, c49_g_y, "IncCalConst", "IncCalConst", 0);
  for (c49_i148 = 0; c49_i148 < 6; c49_i148++) {
    c49_h_u[c49_i148] = c49_u.IncMaxTick[c49_i148];
  }

  c49_h_y = NULL;
  sf_mex_assign(&c49_h_y, sf_mex_create("y", c49_h_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c49_y, c49_h_y, "IncMaxTick", "IncMaxTick", 0);
  for (c49_i149 = 0; c49_i149 < 3; c49_i149++) {
    c49_i_u[c49_i149] = c49_u.BoomCalConst[c49_i149];
  }

  c49_i_y = NULL;
  sf_mex_assign(&c49_i_y, sf_mex_create("y", c49_i_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_addfield(c49_y, c49_i_y, "BoomCalConst", "BoomCalConst", 0);
  for (c49_i150 = 0; c49_i150 < 3; c49_i150++) {
    c49_j_u[c49_i150] = c49_u.BoomCalAngle[c49_i150];
  }

  c49_j_y = NULL;
  sf_mex_assign(&c49_j_y, sf_mex_create("y", c49_j_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_addfield(c49_y, c49_j_y, "BoomCalAngle", "BoomCalAngle", 0);
  for (c49_i151 = 0; c49_i151 < 3; c49_i151++) {
    c49_k_u[c49_i151] = c49_u.BoomMaxTick[c49_i151];
  }

  c49_k_y = NULL;
  sf_mex_assign(&c49_k_y, sf_mex_create("y", c49_k_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_addfield(c49_y, c49_k_y, "BoomMaxTick", "BoomMaxTick", 0);
  for (c49_i152 = 0; c49_i152 < 9; c49_i152++) {
    c49_l_u[c49_i152] = c49_u.MaxTick[c49_i152];
  }

  c49_l_y = NULL;
  sf_mex_assign(&c49_l_y, sf_mex_create("y", c49_l_u, 0, 0U, 1U, 0U, 1, 9),
                false);
  sf_mex_addfield(c49_y, c49_l_y, "MaxTick", "MaxTick", 0);
  for (c49_i153 = 0; c49_i153 < 9; c49_i153++) {
    c49_m_u[c49_i153] = c49_u.Motors[c49_i153];
  }

  c49_m_y = NULL;
  sf_mex_assign(&c49_m_y, sf_mex_create("y", c49_m_u, 0, 0U, 1U, 0U, 1, 9),
                false);
  sf_mex_addfield(c49_y, c49_m_y, "Motors", "Motors", 0);
  for (c49_i154 = 0; c49_i154 < 9; c49_i154++) {
    c49_n_u[c49_i154] = c49_u.KVHOrientation[c49_i154];
  }

  c49_n_y = NULL;
  sf_mex_assign(&c49_n_y, sf_mex_create("y", c49_n_u, 0, 0U, 1U, 0U, 2, 3, 3),
                false);
  sf_mex_addfield(c49_y, c49_n_y, "KVHOrientation", "KVHOrientation", 0);
  for (c49_i155 = 0; c49_i155 < 9; c49_i155++) {
    c49_o_u[c49_i155] = c49_u.MicrostrainOrientation[c49_i155];
  }

  c49_o_y = NULL;
  sf_mex_assign(&c49_o_y, sf_mex_create("y", c49_o_u, 0, 0U, 1U, 0U, 2, 3, 3),
                false);
  sf_mex_addfield(c49_y, c49_o_y, "MicrostrainOrientation",
                  "MicrostrainOrientation", 0);
  sf_mex_assign(&c49_mxArrayOutData, c49_y, false);
  return c49_mxArrayOutData;
}

static const mxArray *c49_f_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData)
{
  const mxArray *c49_mxArrayOutData = NULL;
  real_T c49_u;
  const mxArray *c49_y = NULL;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_mxArrayOutData = NULL;
  c49_u = *(real_T *)c49_inData;
  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", &c49_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c49_mxArrayOutData, c49_y, false);
  return c49_mxArrayOutData;
}

static real_T c49_g_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId)
{
  real_T c49_y;
  real_T c49_d0;
  (void)chartInstance;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), &c49_d0, 1, 0, 0U, 0, 0U, 0);
  c49_y = c49_d0;
  sf_mex_destroy(&c49_u);
  return c49_y;
}

static void c49_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData)
{
  const mxArray *c49_nargout;
  const char_T *c49_identifier;
  emlrtMsgIdentifier c49_thisId;
  real_T c49_y;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_nargout = sf_mex_dup(c49_mxArrayInData);
  c49_identifier = c49_varName;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_y = c49_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_nargout),
    &c49_thisId);
  sf_mex_destroy(&c49_nargout);
  *(real_T *)c49_outData = c49_y;
  sf_mex_destroy(&c49_mxArrayInData);
}

static const mxArray *c49_g_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData)
{
  const mxArray *c49_mxArrayOutData = NULL;
  int32_T c49_i156;
  real_T c49_b_inData[2];
  int32_T c49_i157;
  real_T c49_u[2];
  const mxArray *c49_y = NULL;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_mxArrayOutData = NULL;
  for (c49_i156 = 0; c49_i156 < 2; c49_i156++) {
    c49_b_inData[c49_i156] = (*(real_T (*)[2])c49_inData)[c49_i156];
  }

  for (c49_i157 = 0; c49_i157 < 2; c49_i157++) {
    c49_u[c49_i157] = c49_b_inData[c49_i157];
  }

  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", c49_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c49_mxArrayOutData, c49_y, false);
  return c49_mxArrayOutData;
}

static void c49_h_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  real_T c49_y[2])
{
  real_T c49_dv10[2];
  int32_T c49_i158;
  (void)chartInstance;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), c49_dv10, 1, 0, 0U, 1, 0U, 1, 2);
  for (c49_i158 = 0; c49_i158 < 2; c49_i158++) {
    c49_y[c49_i158] = c49_dv10[c49_i158];
  }

  sf_mex_destroy(&c49_u);
}

static void c49_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData)
{
  const mxArray *c49_AbsUnrolled;
  const char_T *c49_identifier;
  emlrtMsgIdentifier c49_thisId;
  real_T c49_y[2];
  int32_T c49_i159;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_AbsUnrolled = sf_mex_dup(c49_mxArrayInData);
  c49_identifier = c49_varName;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_AbsUnrolled), &c49_thisId,
    c49_y);
  sf_mex_destroy(&c49_AbsUnrolled);
  for (c49_i159 = 0; c49_i159 < 2; c49_i159++) {
    (*(real_T (*)[2])c49_outData)[c49_i159] = c49_y[c49_i159];
  }

  sf_mex_destroy(&c49_mxArrayInData);
}

static const mxArray *c49_h_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData)
{
  const mxArray *c49_mxArrayOutData = NULL;
  int32_T c49_i160;
  boolean_T c49_b_inData[2];
  int32_T c49_i161;
  boolean_T c49_u[2];
  const mxArray *c49_y = NULL;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_mxArrayOutData = NULL;
  for (c49_i160 = 0; c49_i160 < 2; c49_i160++) {
    c49_b_inData[c49_i160] = (*(boolean_T (*)[2])c49_inData)[c49_i160];
  }

  for (c49_i161 = 0; c49_i161 < 2; c49_i161++) {
    c49_u[c49_i161] = c49_b_inData[c49_i161];
  }

  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", c49_u, 11, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c49_mxArrayOutData, c49_y, false);
  return c49_mxArrayOutData;
}

static void c49_i_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  boolean_T c49_y[2])
{
  boolean_T c49_bv6[2];
  int32_T c49_i162;
  (void)chartInstance;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), c49_bv6, 1, 11, 0U, 1, 0U, 1, 2);
  for (c49_i162 = 0; c49_i162 < 2; c49_i162++) {
    c49_y[c49_i162] = c49_bv6[c49_i162];
  }

  sf_mex_destroy(&c49_u);
}

static void c49_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData)
{
  const mxArray *c49_iLow;
  const char_T *c49_identifier;
  emlrtMsgIdentifier c49_thisId;
  boolean_T c49_y[2];
  int32_T c49_i163;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_iLow = sf_mex_dup(c49_mxArrayInData);
  c49_identifier = c49_varName;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_iLow), &c49_thisId, c49_y);
  sf_mex_destroy(&c49_iLow);
  for (c49_i163 = 0; c49_i163 < 2; c49_i163++) {
    (*(boolean_T (*)[2])c49_outData)[c49_i163] = c49_y[c49_i163];
  }

  sf_mex_destroy(&c49_mxArrayInData);
}

static boolean_T c49_j_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId)
{
  boolean_T c49_y;
  boolean_T c49_b0;
  (void)chartInstance;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), &c49_b0, 1, 11, 0U, 0, 0U, 0);
  c49_y = c49_b0;
  sf_mex_destroy(&c49_u);
  return c49_y;
}

static void c49_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData)
{
  const mxArray *c49_b_Reset;
  const char_T *c49_identifier;
  emlrtMsgIdentifier c49_thisId;
  boolean_T c49_y;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_b_Reset = sf_mex_dup(c49_mxArrayInData);
  c49_identifier = c49_varName;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_y = c49_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_b_Reset),
    &c49_thisId);
  sf_mex_destroy(&c49_b_Reset);
  *(boolean_T *)c49_outData = c49_y;
  sf_mex_destroy(&c49_mxArrayInData);
}

static void c49_k_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  c49_RobotCalibrationBus *c49_y)
{
  emlrtMsgIdentifier c49_thisId;
  static const char * c49_fieldNames[14] = { "AbsCalTick", "BoomCalTick",
    "AbsCalConst", "AbsCalAngle", "AbsMaxTick", "IncCalConst", "IncMaxTick",
    "BoomCalConst", "BoomCalAngle", "BoomMaxTick", "MaxTick", "Motors",
    "KVHOrientation", "MicrostrainOrientation" };

  c49_thisId.fParent = c49_parentId;
  sf_mex_check_struct(c49_parentId, c49_u, 14, c49_fieldNames, 0U, NULL);
  c49_thisId.fIdentifier = "AbsCalTick";
  c49_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "AbsCalTick", "AbsCalTick", 0)), &c49_thisId, c49_y->AbsCalTick);
  c49_thisId.fIdentifier = "BoomCalTick";
  c49_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "BoomCalTick", "BoomCalTick", 0)), &c49_thisId, c49_y->BoomCalTick);
  c49_thisId.fIdentifier = "AbsCalConst";
  c49_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "AbsCalConst", "AbsCalConst", 0)), &c49_thisId, c49_y->AbsCalConst);
  c49_thisId.fIdentifier = "AbsCalAngle";
  c49_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "AbsCalAngle", "AbsCalAngle", 0)), &c49_thisId, c49_y->AbsCalAngle);
  c49_thisId.fIdentifier = "AbsMaxTick";
  c49_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "AbsMaxTick", "AbsMaxTick", 0)), &c49_thisId, c49_y->AbsMaxTick);
  c49_thisId.fIdentifier = "IncCalConst";
  c49_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "IncCalConst", "IncCalConst", 0)), &c49_thisId, c49_y->IncCalConst);
  c49_thisId.fIdentifier = "IncMaxTick";
  c49_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "IncMaxTick", "IncMaxTick", 0)), &c49_thisId, c49_y->IncMaxTick);
  c49_thisId.fIdentifier = "BoomCalConst";
  c49_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "BoomCalConst", "BoomCalConst", 0)), &c49_thisId, c49_y->BoomCalConst);
  c49_thisId.fIdentifier = "BoomCalAngle";
  c49_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "BoomCalAngle", "BoomCalAngle", 0)), &c49_thisId, c49_y->BoomCalAngle);
  c49_thisId.fIdentifier = "BoomMaxTick";
  c49_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "BoomMaxTick", "BoomMaxTick", 0)), &c49_thisId, c49_y->BoomMaxTick);
  c49_thisId.fIdentifier = "MaxTick";
  c49_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "MaxTick", "MaxTick", 0)), &c49_thisId, c49_y->MaxTick);
  c49_thisId.fIdentifier = "Motors";
  c49_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "Motors", "Motors", 0)), &c49_thisId, c49_y->Motors);
  c49_thisId.fIdentifier = "KVHOrientation";
  c49_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "KVHOrientation", "KVHOrientation", 0)), &c49_thisId, c49_y->KVHOrientation);
  c49_thisId.fIdentifier = "MicrostrainOrientation";
  c49_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c49_u,
    "MicrostrainOrientation", "MicrostrainOrientation", 0)), &c49_thisId,
    c49_y->MicrostrainOrientation);
  sf_mex_destroy(&c49_u);
}

static void c49_l_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  real_T c49_y[3])
{
  real_T c49_dv11[3];
  int32_T c49_i164;
  (void)chartInstance;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), c49_dv11, 1, 0, 0U, 1, 0U, 1, 3);
  for (c49_i164 = 0; c49_i164 < 3; c49_i164++) {
    c49_y[c49_i164] = c49_dv11[c49_i164];
  }

  sf_mex_destroy(&c49_u);
}

static void c49_m_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId,
  real_T c49_y[9])
{
  real_T c49_dv12[9];
  int32_T c49_i165;
  (void)chartInstance;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), c49_dv12, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c49_i165 = 0; c49_i165 < 9; c49_i165++) {
    c49_y[c49_i165] = c49_dv12[c49_i165];
  }

  sf_mex_destroy(&c49_u);
}

static void c49_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData)
{
  const mxArray *c49_b_Calibration;
  const char_T *c49_identifier;
  emlrtMsgIdentifier c49_thisId;
  c49_RobotCalibrationBus c49_y;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_b_Calibration = sf_mex_dup(c49_mxArrayInData);
  c49_identifier = c49_varName;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_b_Calibration),
    &c49_thisId, &c49_y);
  sf_mex_destroy(&c49_b_Calibration);
  *(c49_RobotCalibrationBus *)c49_outData = c49_y;
  sf_mex_destroy(&c49_mxArrayInData);
}

const mxArray *sf_c49_Walking_ATRIAS_get_eml_resolved_functions_info(void)
{
  const mxArray *c49_nameCaptureInfo = NULL;
  c49_nameCaptureInfo = NULL;
  sf_mex_assign(&c49_nameCaptureInfo, sf_mex_createstruct("structure", 2, 55, 1),
                false);
  c49_info_helper(&c49_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c49_nameCaptureInfo);
  return c49_nameCaptureInfo;
}

static void c49_info_helper(const mxArray **c49_info)
{
  const mxArray *c49_rhs0 = NULL;
  const mxArray *c49_lhs0 = NULL;
  const mxArray *c49_rhs1 = NULL;
  const mxArray *c49_lhs1 = NULL;
  const mxArray *c49_rhs2 = NULL;
  const mxArray *c49_lhs2 = NULL;
  const mxArray *c49_rhs3 = NULL;
  const mxArray *c49_lhs3 = NULL;
  const mxArray *c49_rhs4 = NULL;
  const mxArray *c49_lhs4 = NULL;
  const mxArray *c49_rhs5 = NULL;
  const mxArray *c49_lhs5 = NULL;
  const mxArray *c49_rhs6 = NULL;
  const mxArray *c49_lhs6 = NULL;
  const mxArray *c49_rhs7 = NULL;
  const mxArray *c49_lhs7 = NULL;
  const mxArray *c49_rhs8 = NULL;
  const mxArray *c49_lhs8 = NULL;
  const mxArray *c49_rhs9 = NULL;
  const mxArray *c49_lhs9 = NULL;
  const mxArray *c49_rhs10 = NULL;
  const mxArray *c49_lhs10 = NULL;
  const mxArray *c49_rhs11 = NULL;
  const mxArray *c49_lhs11 = NULL;
  const mxArray *c49_rhs12 = NULL;
  const mxArray *c49_lhs12 = NULL;
  const mxArray *c49_rhs13 = NULL;
  const mxArray *c49_lhs13 = NULL;
  const mxArray *c49_rhs14 = NULL;
  const mxArray *c49_lhs14 = NULL;
  const mxArray *c49_rhs15 = NULL;
  const mxArray *c49_lhs15 = NULL;
  const mxArray *c49_rhs16 = NULL;
  const mxArray *c49_lhs16 = NULL;
  const mxArray *c49_rhs17 = NULL;
  const mxArray *c49_lhs17 = NULL;
  const mxArray *c49_rhs18 = NULL;
  const mxArray *c49_lhs18 = NULL;
  const mxArray *c49_rhs19 = NULL;
  const mxArray *c49_lhs19 = NULL;
  const mxArray *c49_rhs20 = NULL;
  const mxArray *c49_lhs20 = NULL;
  const mxArray *c49_rhs21 = NULL;
  const mxArray *c49_lhs21 = NULL;
  const mxArray *c49_rhs22 = NULL;
  const mxArray *c49_lhs22 = NULL;
  const mxArray *c49_rhs23 = NULL;
  const mxArray *c49_lhs23 = NULL;
  const mxArray *c49_rhs24 = NULL;
  const mxArray *c49_lhs24 = NULL;
  const mxArray *c49_rhs25 = NULL;
  const mxArray *c49_lhs25 = NULL;
  const mxArray *c49_rhs26 = NULL;
  const mxArray *c49_lhs26 = NULL;
  const mxArray *c49_rhs27 = NULL;
  const mxArray *c49_lhs27 = NULL;
  const mxArray *c49_rhs28 = NULL;
  const mxArray *c49_lhs28 = NULL;
  const mxArray *c49_rhs29 = NULL;
  const mxArray *c49_lhs29 = NULL;
  const mxArray *c49_rhs30 = NULL;
  const mxArray *c49_lhs30 = NULL;
  const mxArray *c49_rhs31 = NULL;
  const mxArray *c49_lhs31 = NULL;
  const mxArray *c49_rhs32 = NULL;
  const mxArray *c49_lhs32 = NULL;
  const mxArray *c49_rhs33 = NULL;
  const mxArray *c49_lhs33 = NULL;
  const mxArray *c49_rhs34 = NULL;
  const mxArray *c49_lhs34 = NULL;
  const mxArray *c49_rhs35 = NULL;
  const mxArray *c49_lhs35 = NULL;
  const mxArray *c49_rhs36 = NULL;
  const mxArray *c49_lhs36 = NULL;
  const mxArray *c49_rhs37 = NULL;
  const mxArray *c49_lhs37 = NULL;
  const mxArray *c49_rhs38 = NULL;
  const mxArray *c49_lhs38 = NULL;
  const mxArray *c49_rhs39 = NULL;
  const mxArray *c49_lhs39 = NULL;
  const mxArray *c49_rhs40 = NULL;
  const mxArray *c49_lhs40 = NULL;
  const mxArray *c49_rhs41 = NULL;
  const mxArray *c49_lhs41 = NULL;
  const mxArray *c49_rhs42 = NULL;
  const mxArray *c49_lhs42 = NULL;
  const mxArray *c49_rhs43 = NULL;
  const mxArray *c49_lhs43 = NULL;
  const mxArray *c49_rhs44 = NULL;
  const mxArray *c49_lhs44 = NULL;
  const mxArray *c49_rhs45 = NULL;
  const mxArray *c49_lhs45 = NULL;
  const mxArray *c49_rhs46 = NULL;
  const mxArray *c49_lhs46 = NULL;
  const mxArray *c49_rhs47 = NULL;
  const mxArray *c49_lhs47 = NULL;
  const mxArray *c49_rhs48 = NULL;
  const mxArray *c49_lhs48 = NULL;
  const mxArray *c49_rhs49 = NULL;
  const mxArray *c49_lhs49 = NULL;
  const mxArray *c49_rhs50 = NULL;
  const mxArray *c49_lhs50 = NULL;
  const mxArray *c49_rhs51 = NULL;
  const mxArray *c49_lhs51 = NULL;
  const mxArray *c49_rhs52 = NULL;
  const mxArray *c49_lhs52 = NULL;
  const mxArray *c49_rhs53 = NULL;
  const mxArray *c49_lhs53 = NULL;
  const mxArray *c49_rhs54 = NULL;
  const mxArray *c49_lhs54 = NULL;
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("calibrateEncoders_ATRIAS"),
                  "name", "name", 0);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/calibrateEncoders_ATRIAS.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1468009398U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c49_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/calibrateEncoders_ATRIAS.m!unrollAbsEncoders"),
                  "context", "context", 1);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("mrdivide"), "name", "name",
                  1);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c49_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 2);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c49_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("rdivide"), "name", "name", 3);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c49_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c49_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 5);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c49_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_div"), "name", "name", 6);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c49_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 7);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c49_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/calibrateEncoders_ATRIAS.m!unrollAbsEncoders"),
                  "context", "context", 8);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_li_find"), "name",
                  "name", 8);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c49_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c49_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 10);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 10);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c49_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 11);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 11);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c49_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 12);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("isfi"), "name", "name", 12);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 12);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c49_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 13);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c49_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 14);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("intmax"), "name", "name", 14);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c49_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 15);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c49_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 16);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("intmin"), "name", "name", 16);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c49_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 17);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c49_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 18);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 18);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c49_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 19);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c49_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 20);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c49_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 21);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c49_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/calibrateEncoders_ATRIAS.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 22);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c49_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 23);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c49_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/calibrateEncoders_ATRIAS.m!getIncCalTick"),
                  "context", "context", 24);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("rdivide"), "name", "name",
                  24);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c49_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("isequal"), "name", "name",
                  25);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1286840358U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c49_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 26);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c49_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 27);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("isnan"), "name", "name", 27);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c49_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c49_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/calibrateEncoders_ATRIAS.m!getIncCalTick"),
                  "context", "context", 29);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("mod"), "name", "name", 29);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c49_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c49_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 31);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c49_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 32);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c49_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 33);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c49_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 34);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c49_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p!equalsize"),
                  "context", "context", 35);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("max"), "name", "name", 35);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c49_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 36);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c49_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 37);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 37);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c49_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 38);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 38);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c49_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 39);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 39);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c49_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 40);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 40);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c49_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 41);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 41);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c49_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 42);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 42);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c49_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 43);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 43);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c49_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 44);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 44);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1307672838U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c49_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 45);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 45);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c49_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 46);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eps"), "name", "name", 46);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c49_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 47);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c49_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_eps"), "name", "name",
                  48);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c49_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 49);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c49_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/calibrateEncoders_ATRIAS.m!getIncCalTick"),
                  "context", "context", 50);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("floor"), "name", "name", 50);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c49_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 51);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c49_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 52);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c49_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/calibrateEncoders_ATRIAS.m!getRollover"),
                  "context", "context", 53);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("rdivide"), "name", "name",
                  53);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c49_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/calibrateEncoders_ATRIAS.m!getRollover"),
                  "context", "context", 54);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut("eml_li_find"), "name",
                  "name", 54);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c49_info, c49_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c49_info, c49_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c49_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c49_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c49_info, sf_mex_duplicatearraysafe(&c49_lhs54), "lhs", "lhs",
                  54);
  sf_mex_destroy(&c49_rhs0);
  sf_mex_destroy(&c49_lhs0);
  sf_mex_destroy(&c49_rhs1);
  sf_mex_destroy(&c49_lhs1);
  sf_mex_destroy(&c49_rhs2);
  sf_mex_destroy(&c49_lhs2);
  sf_mex_destroy(&c49_rhs3);
  sf_mex_destroy(&c49_lhs3);
  sf_mex_destroy(&c49_rhs4);
  sf_mex_destroy(&c49_lhs4);
  sf_mex_destroy(&c49_rhs5);
  sf_mex_destroy(&c49_lhs5);
  sf_mex_destroy(&c49_rhs6);
  sf_mex_destroy(&c49_lhs6);
  sf_mex_destroy(&c49_rhs7);
  sf_mex_destroy(&c49_lhs7);
  sf_mex_destroy(&c49_rhs8);
  sf_mex_destroy(&c49_lhs8);
  sf_mex_destroy(&c49_rhs9);
  sf_mex_destroy(&c49_lhs9);
  sf_mex_destroy(&c49_rhs10);
  sf_mex_destroy(&c49_lhs10);
  sf_mex_destroy(&c49_rhs11);
  sf_mex_destroy(&c49_lhs11);
  sf_mex_destroy(&c49_rhs12);
  sf_mex_destroy(&c49_lhs12);
  sf_mex_destroy(&c49_rhs13);
  sf_mex_destroy(&c49_lhs13);
  sf_mex_destroy(&c49_rhs14);
  sf_mex_destroy(&c49_lhs14);
  sf_mex_destroy(&c49_rhs15);
  sf_mex_destroy(&c49_lhs15);
  sf_mex_destroy(&c49_rhs16);
  sf_mex_destroy(&c49_lhs16);
  sf_mex_destroy(&c49_rhs17);
  sf_mex_destroy(&c49_lhs17);
  sf_mex_destroy(&c49_rhs18);
  sf_mex_destroy(&c49_lhs18);
  sf_mex_destroy(&c49_rhs19);
  sf_mex_destroy(&c49_lhs19);
  sf_mex_destroy(&c49_rhs20);
  sf_mex_destroy(&c49_lhs20);
  sf_mex_destroy(&c49_rhs21);
  sf_mex_destroy(&c49_lhs21);
  sf_mex_destroy(&c49_rhs22);
  sf_mex_destroy(&c49_lhs22);
  sf_mex_destroy(&c49_rhs23);
  sf_mex_destroy(&c49_lhs23);
  sf_mex_destroy(&c49_rhs24);
  sf_mex_destroy(&c49_lhs24);
  sf_mex_destroy(&c49_rhs25);
  sf_mex_destroy(&c49_lhs25);
  sf_mex_destroy(&c49_rhs26);
  sf_mex_destroy(&c49_lhs26);
  sf_mex_destroy(&c49_rhs27);
  sf_mex_destroy(&c49_lhs27);
  sf_mex_destroy(&c49_rhs28);
  sf_mex_destroy(&c49_lhs28);
  sf_mex_destroy(&c49_rhs29);
  sf_mex_destroy(&c49_lhs29);
  sf_mex_destroy(&c49_rhs30);
  sf_mex_destroy(&c49_lhs30);
  sf_mex_destroy(&c49_rhs31);
  sf_mex_destroy(&c49_lhs31);
  sf_mex_destroy(&c49_rhs32);
  sf_mex_destroy(&c49_lhs32);
  sf_mex_destroy(&c49_rhs33);
  sf_mex_destroy(&c49_lhs33);
  sf_mex_destroy(&c49_rhs34);
  sf_mex_destroy(&c49_lhs34);
  sf_mex_destroy(&c49_rhs35);
  sf_mex_destroy(&c49_lhs35);
  sf_mex_destroy(&c49_rhs36);
  sf_mex_destroy(&c49_lhs36);
  sf_mex_destroy(&c49_rhs37);
  sf_mex_destroy(&c49_lhs37);
  sf_mex_destroy(&c49_rhs38);
  sf_mex_destroy(&c49_lhs38);
  sf_mex_destroy(&c49_rhs39);
  sf_mex_destroy(&c49_lhs39);
  sf_mex_destroy(&c49_rhs40);
  sf_mex_destroy(&c49_lhs40);
  sf_mex_destroy(&c49_rhs41);
  sf_mex_destroy(&c49_lhs41);
  sf_mex_destroy(&c49_rhs42);
  sf_mex_destroy(&c49_lhs42);
  sf_mex_destroy(&c49_rhs43);
  sf_mex_destroy(&c49_lhs43);
  sf_mex_destroy(&c49_rhs44);
  sf_mex_destroy(&c49_lhs44);
  sf_mex_destroy(&c49_rhs45);
  sf_mex_destroy(&c49_lhs45);
  sf_mex_destroy(&c49_rhs46);
  sf_mex_destroy(&c49_lhs46);
  sf_mex_destroy(&c49_rhs47);
  sf_mex_destroy(&c49_lhs47);
  sf_mex_destroy(&c49_rhs48);
  sf_mex_destroy(&c49_lhs48);
  sf_mex_destroy(&c49_rhs49);
  sf_mex_destroy(&c49_lhs49);
  sf_mex_destroy(&c49_rhs50);
  sf_mex_destroy(&c49_lhs50);
  sf_mex_destroy(&c49_rhs51);
  sf_mex_destroy(&c49_lhs51);
  sf_mex_destroy(&c49_rhs52);
  sf_mex_destroy(&c49_lhs52);
  sf_mex_destroy(&c49_rhs53);
  sf_mex_destroy(&c49_lhs53);
  sf_mex_destroy(&c49_rhs54);
  sf_mex_destroy(&c49_lhs54);
}

static const mxArray *c49_emlrt_marshallOut(const char * c49_u)
{
  const mxArray *c49_y = NULL;
  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", c49_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c49_u)), false);
  return c49_y;
}

static const mxArray *c49_b_emlrt_marshallOut(const uint32_T c49_u)
{
  const mxArray *c49_y = NULL;
  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", &c49_u, 7, 0U, 0U, 0U, 0), false);
  return c49_y;
}

static void c49_eml_li_find(SFc49_Walking_ATRIASInstanceStruct *chartInstance,
  boolean_T c49_x[2], int32_T c49_y_data[], int32_T *c49_y_sizes)
{
  int32_T c49_k;
  int32_T c49_i;
  int32_T c49_b_i;
  int32_T c49_a;
  int32_T c49_b_a;
  const mxArray *c49_y = NULL;
  int32_T c49_tmp_sizes;
  int32_T c49_loop_ub;
  int32_T c49_i166;
  int32_T c49_tmp_data[2];
  int32_T c49_j;
  int32_T c49_c_i;
  int32_T c49_d_i;
  int32_T c49_c_a;
  int32_T c49_d_a;
  c49_k = 0;
  c49_intmin(chartInstance);
  for (c49_i = 1; c49_i < 3; c49_i++) {
    c49_b_i = c49_i - 1;
    if (c49_x[c49_b_i]) {
      c49_a = c49_k;
      c49_b_a = c49_a + 1;
      c49_k = c49_b_a;
    }
  }

  if (c49_k <= 2) {
  } else {
    c49_y = NULL;
    sf_mex_assign(&c49_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U, 0U,
      2, 1, strlen("Assertion failed.")), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c49_y);
  }

  c49_tmp_sizes = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c49_k);
  c49_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c49_k) - 1;
  for (c49_i166 = 0; c49_i166 <= c49_loop_ub; c49_i166++) {
    c49_tmp_data[c49_i166] = 0;
  }

  *c49_y_sizes = c49_tmp_sizes;
  c49_j = 1;
  c49_intmin(chartInstance);
  for (c49_c_i = 1; c49_c_i < 3; c49_c_i++) {
    c49_d_i = c49_c_i;
    if (c49_x[c49_d_i - 1]) {
      c49_y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c49_j, 1, *c49_y_sizes, 1, 0) -
        1] = c49_d_i;
      c49_c_a = c49_j;
      c49_d_a = c49_c_a + 1;
      c49_j = c49_d_a;
    }
  }
}

static int32_T c49_intmin(SFc49_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
  return MIN_int32_T;
}

static void c49_rdivide(SFc49_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c49_x[6], real_T c49_y[6], real_T c49_z[6])
{
  int32_T c49_i167;
  (void)chartInstance;
  for (c49_i167 = 0; c49_i167 < 6; c49_i167++) {
    c49_z[c49_i167] = c49_x[c49_i167] / c49_y[c49_i167];
  }
}

static void c49_b_rdivide(SFc49_Walking_ATRIASInstanceStruct *chartInstance,
  real_T c49_x[9], real_T c49_y[9], real_T c49_z[9])
{
  int32_T c49_i168;
  (void)chartInstance;
  for (c49_i168 = 0; c49_i168 < 9; c49_i168++) {
    c49_z[c49_i168] = c49_x[c49_i168] / c49_y[c49_i168];
  }
}

static void c49_b_eml_li_find(SFc49_Walking_ATRIASInstanceStruct *chartInstance,
  boolean_T c49_x[9], int32_T c49_y_data[], int32_T *c49_y_sizes)
{
  int32_T c49_k;
  int32_T c49_i;
  int32_T c49_b_i;
  int32_T c49_a;
  int32_T c49_b_a;
  const mxArray *c49_y = NULL;
  int32_T c49_tmp_sizes;
  int32_T c49_loop_ub;
  int32_T c49_i169;
  int32_T c49_tmp_data[9];
  int32_T c49_j;
  int32_T c49_c_i;
  int32_T c49_d_i;
  int32_T c49_c_a;
  int32_T c49_d_a;
  c49_k = 0;
  c49_intmin(chartInstance);
  for (c49_i = 1; c49_i < 10; c49_i++) {
    c49_b_i = c49_i - 1;
    if (c49_x[c49_b_i]) {
      c49_a = c49_k;
      c49_b_a = c49_a + 1;
      c49_k = c49_b_a;
    }
  }

  if (c49_k <= 9) {
  } else {
    c49_y = NULL;
    sf_mex_assign(&c49_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U, 0U,
      2, 1, strlen("Assertion failed.")), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c49_y);
  }

  c49_tmp_sizes = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c49_k);
  c49_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c49_k) - 1;
  for (c49_i169 = 0; c49_i169 <= c49_loop_ub; c49_i169++) {
    c49_tmp_data[c49_i169] = 0;
  }

  *c49_y_sizes = c49_tmp_sizes;
  c49_j = 1;
  c49_intmin(chartInstance);
  for (c49_c_i = 1; c49_c_i < 10; c49_c_i++) {
    c49_d_i = c49_c_i;
    if (c49_x[c49_d_i - 1]) {
      c49_y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c49_j, 1, *c49_y_sizes, 1, 0) -
        1] = c49_d_i;
      c49_c_a = c49_j;
      c49_d_a = c49_c_a + 1;
      c49_j = c49_d_a;
    }
  }
}

static const mxArray *c49_i_sf_marshallOut(void *chartInstanceVoid, void
  *c49_inData)
{
  const mxArray *c49_mxArrayOutData = NULL;
  int32_T c49_u;
  const mxArray *c49_y = NULL;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_mxArrayOutData = NULL;
  c49_u = *(int32_T *)c49_inData;
  c49_y = NULL;
  sf_mex_assign(&c49_y, sf_mex_create("y", &c49_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c49_mxArrayOutData, c49_y, false);
  return c49_mxArrayOutData;
}

static int32_T c49_n_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId)
{
  int32_T c49_y;
  int32_T c49_i170;
  (void)chartInstance;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), &c49_i170, 1, 6, 0U, 0, 0U, 0);
  c49_y = c49_i170;
  sf_mex_destroy(&c49_u);
  return c49_y;
}

static void c49_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c49_mxArrayInData, const char_T *c49_varName, void *c49_outData)
{
  const mxArray *c49_b_sfEvent;
  const char_T *c49_identifier;
  emlrtMsgIdentifier c49_thisId;
  int32_T c49_y;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_b_sfEvent = sf_mex_dup(c49_mxArrayInData);
  c49_identifier = c49_varName;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_y = c49_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c49_b_sfEvent),
    &c49_thisId);
  sf_mex_destroy(&c49_b_sfEvent);
  *(int32_T *)c49_outData = c49_y;
  sf_mex_destroy(&c49_mxArrayInData);
}

static const mxArray *c49_Calibration_bus_io(void *chartInstanceVoid, void
  *c49_pData)
{
  const mxArray *c49_mxVal = NULL;
  int32_T c49_i171;
  c49_RobotCalibrationBus c49_tmp;
  int32_T c49_i172;
  int32_T c49_i173;
  int32_T c49_i174;
  int32_T c49_i175;
  int32_T c49_i176;
  int32_T c49_i177;
  int32_T c49_i178;
  int32_T c49_i179;
  int32_T c49_i180;
  int32_T c49_i181;
  int32_T c49_i182;
  int32_T c49_i183;
  int32_T c49_i184;
  int32_T c49_i185;
  int32_T c49_i186;
  int32_T c49_i187;
  int32_T c49_i188;
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c49_mxVal = NULL;
  for (c49_i171 = 0; c49_i171 < 10; c49_i171++) {
    c49_tmp.AbsCalTick[c49_i171] = ((real_T *)&((char_T *)
      (c49_RobotCalibrationBus *)c49_pData)[0])[c49_i171];
  }

  for (c49_i172 = 0; c49_i172 < 3; c49_i172++) {
    c49_tmp.BoomCalTick[c49_i172] = ((real_T *)&((char_T *)
      (c49_RobotCalibrationBus *)c49_pData)[80])[c49_i172];
  }

  for (c49_i173 = 0; c49_i173 < 10; c49_i173++) {
    c49_tmp.AbsCalConst[c49_i173] = ((real_T *)&((char_T *)
      (c49_RobotCalibrationBus *)c49_pData)[104])[c49_i173];
  }

  for (c49_i174 = 0; c49_i174 < 10; c49_i174++) {
    c49_tmp.AbsCalAngle[c49_i174] = ((real_T *)&((char_T *)
      (c49_RobotCalibrationBus *)c49_pData)[184])[c49_i174];
  }

  for (c49_i175 = 0; c49_i175 < 10; c49_i175++) {
    c49_tmp.AbsMaxTick[c49_i175] = ((real_T *)&((char_T *)
      (c49_RobotCalibrationBus *)c49_pData)[264])[c49_i175];
  }

  for (c49_i176 = 0; c49_i176 < 6; c49_i176++) {
    c49_tmp.IncCalConst[c49_i176] = ((real_T *)&((char_T *)
      (c49_RobotCalibrationBus *)c49_pData)[344])[c49_i176];
  }

  for (c49_i177 = 0; c49_i177 < 6; c49_i177++) {
    c49_tmp.IncMaxTick[c49_i177] = ((real_T *)&((char_T *)
      (c49_RobotCalibrationBus *)c49_pData)[392])[c49_i177];
  }

  for (c49_i178 = 0; c49_i178 < 3; c49_i178++) {
    c49_tmp.BoomCalConst[c49_i178] = ((real_T *)&((char_T *)
      (c49_RobotCalibrationBus *)c49_pData)[440])[c49_i178];
  }

  for (c49_i179 = 0; c49_i179 < 3; c49_i179++) {
    c49_tmp.BoomCalAngle[c49_i179] = ((real_T *)&((char_T *)
      (c49_RobotCalibrationBus *)c49_pData)[464])[c49_i179];
  }

  for (c49_i180 = 0; c49_i180 < 3; c49_i180++) {
    c49_tmp.BoomMaxTick[c49_i180] = ((real_T *)&((char_T *)
      (c49_RobotCalibrationBus *)c49_pData)[488])[c49_i180];
  }

  for (c49_i181 = 0; c49_i181 < 9; c49_i181++) {
    c49_tmp.MaxTick[c49_i181] = ((real_T *)&((char_T *)(c49_RobotCalibrationBus *)
      c49_pData)[512])[c49_i181];
  }

  for (c49_i182 = 0; c49_i182 < 9; c49_i182++) {
    c49_tmp.Motors[c49_i182] = ((real_T *)&((char_T *)(c49_RobotCalibrationBus *)
      c49_pData)[584])[c49_i182];
  }

  c49_i183 = 0;
  for (c49_i184 = 0; c49_i184 < 3; c49_i184++) {
    for (c49_i185 = 0; c49_i185 < 3; c49_i185++) {
      c49_tmp.KVHOrientation[c49_i185 + c49_i183] = ((real_T *)&((char_T *)
        (c49_RobotCalibrationBus *)c49_pData)[656])[c49_i185 + c49_i183];
    }

    c49_i183 += 3;
  }

  c49_i186 = 0;
  for (c49_i187 = 0; c49_i187 < 3; c49_i187++) {
    for (c49_i188 = 0; c49_i188 < 3; c49_i188++) {
      c49_tmp.MicrostrainOrientation[c49_i188 + c49_i186] = ((real_T *)&((char_T
        *)(c49_RobotCalibrationBus *)c49_pData)[728])[c49_i188 + c49_i186];
    }

    c49_i186 += 3;
  }

  sf_mex_assign(&c49_mxVal, c49_e_sf_marshallOut(chartInstance, &c49_tmp), false);
  return c49_mxVal;
}

static uint8_T c49_o_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_b_is_active_c49_Walking_ATRIAS, const
  char_T *c49_identifier)
{
  uint8_T c49_y;
  emlrtMsgIdentifier c49_thisId;
  c49_thisId.fIdentifier = c49_identifier;
  c49_thisId.fParent = NULL;
  c49_y = c49_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c49_b_is_active_c49_Walking_ATRIAS), &c49_thisId);
  sf_mex_destroy(&c49_b_is_active_c49_Walking_ATRIAS);
  return c49_y;
}

static uint8_T c49_p_emlrt_marshallIn(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c49_u, const emlrtMsgIdentifier *c49_parentId)
{
  uint8_T c49_y;
  uint8_T c49_u0;
  (void)chartInstance;
  sf_mex_import(c49_parentId, sf_mex_dup(c49_u), &c49_u0, 1, 3, 0U, 0, 0U, 0);
  c49_y = c49_u0;
  sf_mex_destroy(&c49_u);
  return c49_y;
}

static void init_dsm_address_info(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc49_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  chartInstance->c49_Calibration = (c49_RobotCalibrationBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c49_AbsEncoders = (real_T (*)[10])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c49_IncEncoders = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c49_IncEncodersPrev = (real_T (*)[9])
    ssGetInputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c49_AbsAngle = (real_T (*)[10])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c49_Reset = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c49_IncAngle = (real_T (*)[9])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c49_RolloverIn = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c49_Rollover = (real_T (*)[9])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c49_IncCalTickIn = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c49_IncCalTick = (real_T (*)[6])ssGetOutputPortSignal_wrapper
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

void sf_c49_Walking_ATRIAS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(830750938U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(456296498U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(870373313U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(588133930U);
}

mxArray* sf_c49_Walking_ATRIAS_get_post_codegen_info(void);
mxArray *sf_c49_Walking_ATRIAS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("gamjViGitfhU5dptTnMx1B");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
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
      pr[0] = (double)(9);
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
      pr[0] = (double)(9);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(9);
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
      pr[0] = (double)(6);
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

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(10);
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
      pr[0] = (double)(9);
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
      pr[0] = (double)(9);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c49_Walking_ATRIAS_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c49_Walking_ATRIAS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c49_Walking_ATRIAS_jit_fallback_info(void)
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

mxArray *sf_c49_Walking_ATRIAS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c49_Walking_ATRIAS_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c49_Walking_ATRIAS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"AbsAngle\",},{M[1],M[11],T\"IncAngle\",},{M[1],M[22],T\"IncCalTick\",},{M[1],M[17],T\"Rollover\",},{M[8],M[0],T\"is_active_c49_Walking_ATRIAS\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c49_Walking_ATRIAS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc49_Walking_ATRIASInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking_ATRIASMachineNumber_,
           49,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Calibration");
          _SFD_SET_DATA_PROPS(1,1,1,0,"AbsEncoders");
          _SFD_SET_DATA_PROPS(2,1,1,0,"IncEncoders");
          _SFD_SET_DATA_PROPS(3,1,1,0,"IncEncodersPrev");
          _SFD_SET_DATA_PROPS(4,2,0,1,"AbsAngle");
          _SFD_SET_DATA_PROPS(5,1,1,0,"Reset");
          _SFD_SET_DATA_PROPS(6,2,0,1,"IncAngle");
          _SFD_SET_DATA_PROPS(7,1,1,0,"RolloverIn");
          _SFD_SET_DATA_PROPS(8,2,0,1,"Rollover");
          _SFD_SET_DATA_PROPS(9,1,1,0,"IncCalTickIn");
          _SFD_SET_DATA_PROPS(10,2,0,1,"IncCalTick");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,322);
        _SFD_CV_INIT_SCRIPT(0,4,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"calibrateEncoders_ATRIAS",0,-1,1714);
        _SFD_CV_INIT_SCRIPT_FCN(0,1,"getIncCalTick",1716,-1,2081);
        _SFD_CV_INIT_SCRIPT_FCN(0,2,"getRollover",2083,-1,3192);
        _SFD_CV_INIT_SCRIPT_FCN(0,3,"unrollAbsEncoders",3194,-1,4424);
        _SFD_CV_INIT_SCRIPT_IF(0,0,995,1003,1226,1380);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c49_Calibration_bus_io,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c49_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c49_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c49_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c49_c_sf_marshallOut,(MexInFcnForType)
            c49_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c49_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c49_b_sf_marshallOut,(MexInFcnForType)
            c49_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c49_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c49_b_sf_marshallOut,(MexInFcnForType)
            c49_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c49_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c49_sf_marshallOut,(MexInFcnForType)
            c49_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c49_Calibration);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c49_AbsEncoders);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c49_IncEncoders);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c49_IncEncodersPrev);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c49_AbsAngle);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c49_Reset);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c49_IncAngle);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c49_RolloverIn);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c49_Rollover);
        _SFD_SET_DATA_VALUE_PTR(9U, *chartInstance->c49_IncCalTickIn);
        _SFD_SET_DATA_VALUE_PTR(10U, *chartInstance->c49_IncCalTick);
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
  return "QSTMJemHZNYcPsVACP6BGG";
}

static void sf_opaque_initialize_c49_Walking_ATRIAS(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc49_Walking_ATRIASInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c49_Walking_ATRIAS((SFc49_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
  initialize_c49_Walking_ATRIAS((SFc49_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c49_Walking_ATRIAS(void *chartInstanceVar)
{
  enable_c49_Walking_ATRIAS((SFc49_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c49_Walking_ATRIAS(void *chartInstanceVar)
{
  disable_c49_Walking_ATRIAS((SFc49_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c49_Walking_ATRIAS(void *chartInstanceVar)
{
  sf_gateway_c49_Walking_ATRIAS((SFc49_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c49_Walking_ATRIAS(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c49_Walking_ATRIAS((SFc49_Walking_ATRIASInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c49_Walking_ATRIAS(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c49_Walking_ATRIAS((SFc49_Walking_ATRIASInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c49_Walking_ATRIAS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc49_Walking_ATRIASInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking_ATRIAS_optimization_info();
    }

    finalize_c49_Walking_ATRIAS((SFc49_Walking_ATRIASInstanceStruct*)
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
  initSimStructsc49_Walking_ATRIAS((SFc49_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c49_Walking_ATRIAS(SimStruct *S)
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
    initialize_params_c49_Walking_ATRIAS((SFc49_Walking_ATRIASInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c49_Walking_ATRIAS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking_ATRIAS_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      49);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,49,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,49,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,49);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,49,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,49,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,49);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3873091036U));
  ssSetChecksum1(S,(2083971268U));
  ssSetChecksum2(S,(689872338U));
  ssSetChecksum3(S,(2713215806U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c49_Walking_ATRIAS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c49_Walking_ATRIAS(SimStruct *S)
{
  SFc49_Walking_ATRIASInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc49_Walking_ATRIASInstanceStruct *)utMalloc(sizeof
    (SFc49_Walking_ATRIASInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc49_Walking_ATRIASInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c49_Walking_ATRIAS;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c49_Walking_ATRIAS;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c49_Walking_ATRIAS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c49_Walking_ATRIAS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c49_Walking_ATRIAS;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c49_Walking_ATRIAS;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c49_Walking_ATRIAS;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c49_Walking_ATRIAS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c49_Walking_ATRIAS;
  chartInstance->chartInfo.mdlStart = mdlStart_c49_Walking_ATRIAS;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c49_Walking_ATRIAS;
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

void c49_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c49_Walking_ATRIAS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c49_Walking_ATRIAS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c49_Walking_ATRIAS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c49_Walking_ATRIAS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
