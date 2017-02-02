/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_withElmos_sfun.h"
#include "c24_Walking01_withElmos.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Walking01_withElmos_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c24_debug_family_names[13] = { "nargin", "nargout",
  "Calibration", "AbsEncoders", "IncEncoders", "IncEncodersPrev", "Reset",
  "RolloverIn", "IncCalTickIn", "AbsAngle", "IncAngle", "Rollover", "IncCalTick"
};

static const char * c24_b_debug_family_names[10] = { "HalfMaxTicks", "CalOffset",
  "iHigh", "iLow", "nargin", "nargout", "AbsMaxTick", "AbsCalTick", "AbsEncoder",
  "AbsUnrolled" };

static const char * c24_c_debug_family_names[8] = { "nargin", "nargout",
  "IncCalConst", "IncMaxTick", "AbsAngle", "IncTick", "IncCalTick", "Rollover" };

static const char * c24_d_debug_family_names[8] = { "NormalizedCountPrev",
  "NormalizedCount", "nargin", "nargout", "MaxTick", "IncEncoders",
  "IncEncodersPrev", "Rollover" };

static const char * c24_e_debug_family_names[17] = { "RefAngle", "IncCalTickB",
  "IncCalAngle", "IncTick", "nargin", "nargout", "Calibration", "AbsEncoders",
  "IncEncoders", "IncEncodersPrev", "Reset", "RolloverIn", "IncCalTickIn",
  "AbsAngle", "IncAngle", "Rollover", "IncCalTick" };

/* Function Declarations */
static void initialize_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance);
static void initialize_params_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance);
static void enable_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance);
static void disable_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance);
static void c24_update_debugger_state_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance);
static void set_sim_state_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance, const mxArray *c24_st);
static void finalize_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance);
static void sf_gateway_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance);
static void mdl_start_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance);
static void initSimStructsc24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance);
static void c24_calibrateEncoders2(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, c24_RobotCalibrationBus *c24_b_Calibration, real_T
  c24_b_AbsEncoders[10], real_T c24_b_IncEncoders[9], real_T
  c24_b_IncEncodersPrev[9], boolean_T c24_b_Reset, real_T c24_b_RolloverIn[9],
  real_T c24_b_IncCalTickIn[6], real_T c24_b_AbsAngle[10], real_T
  c24_b_IncAngle[9], real_T c24_b_Rollover[9], real_T c24_b_IncCalTick[6]);
static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber, uint32_T c24_instanceNumber);
static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_b_IncCalTick, const char_T *c24_identifier,
  real_T c24_y[6]);
static void c24_b_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[6]);
static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_c_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_b_Rollover, const char_T *c24_identifier,
  real_T c24_y[9]);
static void c24_d_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[9]);
static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_e_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_b_AbsAngle, const char_T *c24_identifier,
  real_T c24_y[10]);
static void c24_f_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[10]);
static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static const mxArray *c24_e_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static const mxArray *c24_f_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static real_T c24_g_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_g_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_h_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[2]);
static void c24_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_h_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static void c24_i_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  boolean_T c24_y[2]);
static void c24_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static boolean_T c24_j_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct *
  chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static void c24_k_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  c24_RobotCalibrationBus *c24_y);
static void c24_l_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[3]);
static void c24_m_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[9]);
static void c24_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static void c24_info_helper(const mxArray **c24_info);
static const mxArray *c24_emlrt_marshallOut(const char * c24_u);
static const mxArray *c24_b_emlrt_marshallOut(const uint32_T c24_u);
static void c24_eml_li_find(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, boolean_T c24_x[2], int32_T c24_y_data[], int32_T *c24_y_sizes);
static int32_T c24_intmin(SFc24_Walking01_withElmosInstanceStruct *chartInstance);
static void c24_rdivide(SFc24_Walking01_withElmosInstanceStruct *chartInstance,
  real_T c24_x[6], real_T c24_y[6], real_T c24_z[6]);
static void c24_b_rdivide(SFc24_Walking01_withElmosInstanceStruct *chartInstance,
  real_T c24_x[9], real_T c24_y[9], real_T c24_z[9]);
static void c24_b_eml_li_find(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, boolean_T c24_x[9], int32_T c24_y_data[], int32_T *c24_y_sizes);
static const mxArray *c24_i_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData);
static int32_T c24_n_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void c24_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData);
static const mxArray *c24_Calibration_bus_io(void *chartInstanceVoid, void
  *c24_pData);
static uint8_T c24_o_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_b_is_active_c24_Walking01_withElmos, const
  char_T *c24_identifier);
static uint8_T c24_p_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId);
static void init_dsm_address_info(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance)
{
  chartInstance->c24_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c24_is_active_c24_Walking01_withElmos = 0U;
}

static void initialize_params_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c24_update_debugger_state_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance)
{
  const mxArray *c24_st;
  const mxArray *c24_y = NULL;
  int32_T c24_i0;
  real_T c24_u[10];
  const mxArray *c24_b_y = NULL;
  int32_T c24_i1;
  real_T c24_b_u[9];
  const mxArray *c24_c_y = NULL;
  int32_T c24_i2;
  real_T c24_c_u[6];
  const mxArray *c24_d_y = NULL;
  int32_T c24_i3;
  real_T c24_d_u[9];
  const mxArray *c24_e_y = NULL;
  uint8_T c24_hoistedGlobal;
  uint8_T c24_e_u;
  const mxArray *c24_f_y = NULL;
  c24_st = NULL;
  c24_st = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createcellmatrix(5, 1), false);
  for (c24_i0 = 0; c24_i0 < 10; c24_i0++) {
    c24_u[c24_i0] = (*chartInstance->c24_AbsAngle)[c24_i0];
  }

  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 10), false);
  sf_mex_setcell(c24_y, 0, c24_b_y);
  for (c24_i1 = 0; c24_i1 < 9; c24_i1++) {
    c24_b_u[c24_i1] = (*chartInstance->c24_IncAngle)[c24_i1];
  }

  c24_c_y = NULL;
  sf_mex_assign(&c24_c_y, sf_mex_create("y", c24_b_u, 0, 0U, 1U, 0U, 1, 9),
                false);
  sf_mex_setcell(c24_y, 1, c24_c_y);
  for (c24_i2 = 0; c24_i2 < 6; c24_i2++) {
    c24_c_u[c24_i2] = (*chartInstance->c24_IncCalTick)[c24_i2];
  }

  c24_d_y = NULL;
  sf_mex_assign(&c24_d_y, sf_mex_create("y", c24_c_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_setcell(c24_y, 2, c24_d_y);
  for (c24_i3 = 0; c24_i3 < 9; c24_i3++) {
    c24_d_u[c24_i3] = (*chartInstance->c24_Rollover)[c24_i3];
  }

  c24_e_y = NULL;
  sf_mex_assign(&c24_e_y, sf_mex_create("y", c24_d_u, 0, 0U, 1U, 0U, 1, 9),
                false);
  sf_mex_setcell(c24_y, 3, c24_e_y);
  c24_hoistedGlobal = chartInstance->c24_is_active_c24_Walking01_withElmos;
  c24_e_u = c24_hoistedGlobal;
  c24_f_y = NULL;
  sf_mex_assign(&c24_f_y, sf_mex_create("y", &c24_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c24_y, 4, c24_f_y);
  sf_mex_assign(&c24_st, c24_y, false);
  return c24_st;
}

static void set_sim_state_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance, const mxArray *c24_st)
{
  const mxArray *c24_u;
  real_T c24_dv0[10];
  int32_T c24_i4;
  real_T c24_dv1[9];
  int32_T c24_i5;
  real_T c24_dv2[6];
  int32_T c24_i6;
  real_T c24_dv3[9];
  int32_T c24_i7;
  chartInstance->c24_doneDoubleBufferReInit = true;
  c24_u = sf_mex_dup(c24_st);
  c24_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 0)),
    "AbsAngle", c24_dv0);
  for (c24_i4 = 0; c24_i4 < 10; c24_i4++) {
    (*chartInstance->c24_AbsAngle)[c24_i4] = c24_dv0[c24_i4];
  }

  c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 1)),
    "IncAngle", c24_dv1);
  for (c24_i5 = 0; c24_i5 < 9; c24_i5++) {
    (*chartInstance->c24_IncAngle)[c24_i5] = c24_dv1[c24_i5];
  }

  c24_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 2)),
                       "IncCalTick", c24_dv2);
  for (c24_i6 = 0; c24_i6 < 6; c24_i6++) {
    (*chartInstance->c24_IncCalTick)[c24_i6] = c24_dv2[c24_i6];
  }

  c24_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 3)),
    "Rollover", c24_dv3);
  for (c24_i7 = 0; c24_i7 < 9; c24_i7++) {
    (*chartInstance->c24_Rollover)[c24_i7] = c24_dv3[c24_i7];
  }

  chartInstance->c24_is_active_c24_Walking01_withElmos = c24_o_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c24_u, 4)),
     "is_active_c24_Walking01_withElmos");
  sf_mex_destroy(&c24_u);
  c24_update_debugger_state_c24_Walking01_withElmos(chartInstance);
  sf_mex_destroy(&c24_st);
}

static void finalize_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance)
{
  int32_T c24_i8;
  int32_T c24_i9;
  int32_T c24_i10;
  boolean_T c24_hoistedGlobal;
  int32_T c24_i11;
  c24_RobotCalibrationBus c24_b_Calibration;
  int32_T c24_i12;
  int32_T c24_i13;
  int32_T c24_i14;
  int32_T c24_i15;
  int32_T c24_i16;
  int32_T c24_i17;
  int32_T c24_i18;
  int32_T c24_i19;
  int32_T c24_i20;
  int32_T c24_i21;
  int32_T c24_i22;
  int32_T c24_i23;
  int32_T c24_i24;
  int32_T c24_i25;
  int32_T c24_i26;
  int32_T c24_i27;
  int32_T c24_i28;
  int32_T c24_i29;
  real_T c24_b_AbsEncoders[10];
  int32_T c24_i30;
  real_T c24_b_IncEncoders[9];
  int32_T c24_i31;
  real_T c24_b_IncEncodersPrev[9];
  boolean_T c24_b_Reset;
  int32_T c24_i32;
  real_T c24_b_RolloverIn[9];
  int32_T c24_i33;
  real_T c24_b_IncCalTickIn[6];
  uint32_T c24_debug_family_var_map[13];
  real_T c24_nargin = 7.0;
  real_T c24_nargout = 4.0;
  real_T c24_b_AbsAngle[10];
  real_T c24_b_IncAngle[9];
  real_T c24_b_Rollover[9];
  real_T c24_b_IncCalTick[6];
  c24_RobotCalibrationBus c24_c_Calibration;
  int32_T c24_i34;
  real_T c24_c_AbsEncoders[10];
  int32_T c24_i35;
  real_T c24_c_IncEncoders[9];
  int32_T c24_i36;
  real_T c24_c_IncEncodersPrev[9];
  int32_T c24_i37;
  real_T c24_c_RolloverIn[9];
  int32_T c24_i38;
  real_T c24_c_IncCalTickIn[6];
  real_T c24_c_IncCalTick[6];
  real_T c24_c_Rollover[9];
  real_T c24_c_IncAngle[9];
  real_T c24_c_AbsAngle[10];
  int32_T c24_i39;
  int32_T c24_i40;
  int32_T c24_i41;
  int32_T c24_i42;
  int32_T c24_i43;
  int32_T c24_i44;
  int32_T c24_i45;
  int32_T c24_i46;
  int32_T c24_i47;
  int32_T c24_i48;
  int32_T c24_i49;
  int32_T c24_i50;
  int32_T c24_i51;
  int32_T c24_i52;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 18U, chartInstance->c24_sfEvent);
  for (c24_i8 = 0; c24_i8 < 10; c24_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c24_AbsEncoders)[c24_i8], 1U);
  }

  for (c24_i9 = 0; c24_i9 < 9; c24_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c24_IncEncoders)[c24_i9], 2U);
  }

  for (c24_i10 = 0; c24_i10 < 9; c24_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c24_IncEncodersPrev)[c24_i10], 3U);
  }

  chartInstance->c24_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 18U, chartInstance->c24_sfEvent);
  c24_hoistedGlobal = *chartInstance->c24_Reset;
  for (c24_i11 = 0; c24_i11 < 10; c24_i11++) {
    c24_b_Calibration.AbsCalTick[c24_i11] = ((real_T *)&((char_T *)
      chartInstance->c24_Calibration)[0])[c24_i11];
  }

  for (c24_i12 = 0; c24_i12 < 3; c24_i12++) {
    c24_b_Calibration.BoomCalTick[c24_i12] = ((real_T *)&((char_T *)
      chartInstance->c24_Calibration)[80])[c24_i12];
  }

  for (c24_i13 = 0; c24_i13 < 10; c24_i13++) {
    c24_b_Calibration.AbsCalConst[c24_i13] = ((real_T *)&((char_T *)
      chartInstance->c24_Calibration)[104])[c24_i13];
  }

  for (c24_i14 = 0; c24_i14 < 10; c24_i14++) {
    c24_b_Calibration.AbsCalAngle[c24_i14] = ((real_T *)&((char_T *)
      chartInstance->c24_Calibration)[184])[c24_i14];
  }

  for (c24_i15 = 0; c24_i15 < 10; c24_i15++) {
    c24_b_Calibration.AbsMaxTick[c24_i15] = ((real_T *)&((char_T *)
      chartInstance->c24_Calibration)[264])[c24_i15];
  }

  for (c24_i16 = 0; c24_i16 < 6; c24_i16++) {
    c24_b_Calibration.IncCalConst[c24_i16] = ((real_T *)&((char_T *)
      chartInstance->c24_Calibration)[344])[c24_i16];
  }

  for (c24_i17 = 0; c24_i17 < 6; c24_i17++) {
    c24_b_Calibration.IncMaxTick[c24_i17] = ((real_T *)&((char_T *)
      chartInstance->c24_Calibration)[392])[c24_i17];
  }

  for (c24_i18 = 0; c24_i18 < 3; c24_i18++) {
    c24_b_Calibration.BoomCalConst[c24_i18] = ((real_T *)&((char_T *)
      chartInstance->c24_Calibration)[440])[c24_i18];
  }

  for (c24_i19 = 0; c24_i19 < 3; c24_i19++) {
    c24_b_Calibration.BoomCalAngle[c24_i19] = ((real_T *)&((char_T *)
      chartInstance->c24_Calibration)[464])[c24_i19];
  }

  for (c24_i20 = 0; c24_i20 < 3; c24_i20++) {
    c24_b_Calibration.BoomMaxTick[c24_i20] = ((real_T *)&((char_T *)
      chartInstance->c24_Calibration)[488])[c24_i20];
  }

  for (c24_i21 = 0; c24_i21 < 9; c24_i21++) {
    c24_b_Calibration.MaxTick[c24_i21] = ((real_T *)&((char_T *)
      chartInstance->c24_Calibration)[512])[c24_i21];
  }

  for (c24_i22 = 0; c24_i22 < 9; c24_i22++) {
    c24_b_Calibration.Motors[c24_i22] = ((real_T *)&((char_T *)
      chartInstance->c24_Calibration)[584])[c24_i22];
  }

  c24_i23 = 0;
  for (c24_i24 = 0; c24_i24 < 3; c24_i24++) {
    for (c24_i25 = 0; c24_i25 < 3; c24_i25++) {
      c24_b_Calibration.KVHOrientation[c24_i25 + c24_i23] = ((real_T *)&((char_T
        *)chartInstance->c24_Calibration)[656])[c24_i25 + c24_i23];
    }

    c24_i23 += 3;
  }

  c24_i26 = 0;
  for (c24_i27 = 0; c24_i27 < 3; c24_i27++) {
    for (c24_i28 = 0; c24_i28 < 3; c24_i28++) {
      c24_b_Calibration.MicrostrainOrientation[c24_i28 + c24_i26] = ((real_T *)
        &((char_T *)chartInstance->c24_Calibration)[728])[c24_i28 + c24_i26];
    }

    c24_i26 += 3;
  }

  for (c24_i29 = 0; c24_i29 < 10; c24_i29++) {
    c24_b_AbsEncoders[c24_i29] = (*chartInstance->c24_AbsEncoders)[c24_i29];
  }

  for (c24_i30 = 0; c24_i30 < 9; c24_i30++) {
    c24_b_IncEncoders[c24_i30] = (*chartInstance->c24_IncEncoders)[c24_i30];
  }

  for (c24_i31 = 0; c24_i31 < 9; c24_i31++) {
    c24_b_IncEncodersPrev[c24_i31] = (*chartInstance->c24_IncEncodersPrev)
      [c24_i31];
  }

  c24_b_Reset = c24_hoistedGlobal;
  for (c24_i32 = 0; c24_i32 < 9; c24_i32++) {
    c24_b_RolloverIn[c24_i32] = (*chartInstance->c24_RolloverIn)[c24_i32];
  }

  for (c24_i33 = 0; c24_i33 < 6; c24_i33++) {
    c24_b_IncCalTickIn[c24_i33] = (*chartInstance->c24_IncCalTickIn)[c24_i33];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c24_debug_family_names,
    c24_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargin, 0U, c24_f_sf_marshallOut,
    c24_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargout, 1U, c24_f_sf_marshallOut,
    c24_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c24_b_Calibration, 2U, c24_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c24_b_AbsEncoders, 3U, c24_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c24_b_IncEncoders, 4U, c24_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c24_b_IncEncodersPrev, 5U, c24_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c24_b_Reset, 6U, c24_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c24_b_RolloverIn, 7U, c24_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c24_b_IncCalTickIn, 8U, c24_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_AbsAngle, 9U, c24_c_sf_marshallOut,
    c24_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_IncAngle, 10U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_Rollover, 11U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_IncCalTick, 12U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, 3);
  c24_c_Calibration = c24_b_Calibration;
  for (c24_i34 = 0; c24_i34 < 10; c24_i34++) {
    c24_c_AbsEncoders[c24_i34] = c24_b_AbsEncoders[c24_i34];
  }

  for (c24_i35 = 0; c24_i35 < 9; c24_i35++) {
    c24_c_IncEncoders[c24_i35] = c24_b_IncEncoders[c24_i35];
  }

  for (c24_i36 = 0; c24_i36 < 9; c24_i36++) {
    c24_c_IncEncodersPrev[c24_i36] = c24_b_IncEncodersPrev[c24_i36];
  }

  for (c24_i37 = 0; c24_i37 < 9; c24_i37++) {
    c24_c_RolloverIn[c24_i37] = c24_b_RolloverIn[c24_i37];
  }

  for (c24_i38 = 0; c24_i38 < 6; c24_i38++) {
    c24_c_IncCalTickIn[c24_i38] = c24_b_IncCalTickIn[c24_i38];
  }

  c24_calibrateEncoders2(chartInstance, &c24_c_Calibration, c24_c_AbsEncoders,
    c24_c_IncEncoders, c24_c_IncEncodersPrev, c24_b_Reset, c24_c_RolloverIn,
    c24_c_IncCalTickIn, c24_c_AbsAngle, c24_c_IncAngle, c24_c_Rollover,
    c24_c_IncCalTick);
  for (c24_i39 = 0; c24_i39 < 10; c24_i39++) {
    c24_b_AbsAngle[c24_i39] = c24_c_AbsAngle[c24_i39];
  }

  for (c24_i40 = 0; c24_i40 < 9; c24_i40++) {
    c24_b_IncAngle[c24_i40] = c24_c_IncAngle[c24_i40];
  }

  for (c24_i41 = 0; c24_i41 < 9; c24_i41++) {
    c24_b_Rollover[c24_i41] = c24_c_Rollover[c24_i41];
  }

  for (c24_i42 = 0; c24_i42 < 6; c24_i42++) {
    c24_b_IncCalTick[c24_i42] = c24_c_IncCalTick[c24_i42];
  }

  _SFD_EML_CALL(0U, chartInstance->c24_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c24_i43 = 0; c24_i43 < 10; c24_i43++) {
    (*chartInstance->c24_AbsAngle)[c24_i43] = c24_b_AbsAngle[c24_i43];
  }

  for (c24_i44 = 0; c24_i44 < 9; c24_i44++) {
    (*chartInstance->c24_IncAngle)[c24_i44] = c24_b_IncAngle[c24_i44];
  }

  for (c24_i45 = 0; c24_i45 < 9; c24_i45++) {
    (*chartInstance->c24_Rollover)[c24_i45] = c24_b_Rollover[c24_i45];
  }

  for (c24_i46 = 0; c24_i46 < 6; c24_i46++) {
    (*chartInstance->c24_IncCalTick)[c24_i46] = c24_b_IncCalTick[c24_i46];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 18U, chartInstance->c24_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_withElmosMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c24_i47 = 0; c24_i47 < 10; c24_i47++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c24_AbsAngle)[c24_i47], 4U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c24_Reset, 5U);
  for (c24_i48 = 0; c24_i48 < 9; c24_i48++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c24_IncAngle)[c24_i48], 6U);
  }

  for (c24_i49 = 0; c24_i49 < 9; c24_i49++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c24_RolloverIn)[c24_i49], 7U);
  }

  for (c24_i50 = 0; c24_i50 < 9; c24_i50++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c24_Rollover)[c24_i50], 8U);
  }

  for (c24_i51 = 0; c24_i51 < 6; c24_i51++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c24_IncCalTickIn)[c24_i51], 9U);
  }

  for (c24_i52 = 0; c24_i52 < 6; c24_i52++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c24_IncCalTick)[c24_i52], 10U);
  }
}

static void mdl_start_c24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc24_Walking01_withElmos
  (SFc24_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c24_calibrateEncoders2(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, c24_RobotCalibrationBus *c24_b_Calibration, real_T
  c24_b_AbsEncoders[10], real_T c24_b_IncEncoders[9], real_T
  c24_b_IncEncodersPrev[9], boolean_T c24_b_Reset, real_T c24_b_RolloverIn[9],
  real_T c24_b_IncCalTickIn[6], real_T c24_b_AbsAngle[10], real_T
  c24_b_IncAngle[9], real_T c24_b_Rollover[9], real_T c24_b_IncCalTick[6])
{
  uint32_T c24_debug_family_var_map[17];
  real_T c24_RefAngle[6];
  real_T c24_IncCalTickB[9];
  real_T c24_IncCalAngle[9];
  real_T c24_IncTick[9];
  real_T c24_nargin = 7.0;
  real_T c24_nargout = 4.0;
  int32_T c24_i53;
  real_T c24_AbsMaxTick[2];
  int32_T c24_i54;
  real_T c24_AbsCalTick[2];
  int32_T c24_i55;
  real_T c24_AbsEncoder[2];
  uint32_T c24_b_debug_family_var_map[10];
  real_T c24_HalfMaxTicks[2];
  real_T c24_CalOffset[2];
  boolean_T c24_iHigh[2];
  boolean_T c24_iLow[2];
  real_T c24_b_nargin = 3.0;
  real_T c24_b_nargout = 1.0;
  real_T c24_AbsUnrolled[2];
  int32_T c24_i56;
  int32_T c24_i57;
  real_T c24_A[2];
  int32_T c24_i58;
  int32_T c24_i59;
  int32_T c24_i60;
  boolean_T c24_bv0[2];
  int32_T c24_i61;
  boolean_T c24_bv1[2];
  int32_T c24_i62;
  int32_T c24_i63;
  boolean_T c24_b_iHigh[2];
  int32_T c24_tmp_sizes;
  int32_T c24_tmp_data[2];
  int32_T c24_b_tmp_sizes;
  int32_T c24_loop_ub;
  int32_T c24_i64;
  real_T c24_b_tmp_data[2];
  int32_T c24_i65;
  boolean_T c24_c_iHigh[2];
  int32_T c24_c_tmp_sizes;
  int32_T c24_b_loop_ub;
  int32_T c24_i66;
  real_T c24_c_tmp_data[2];
  int32_T c24_i67;
  boolean_T c24_d_iHigh[2];
  int32_T c24_c_loop_ub;
  int32_T c24_i68;
  int32_T c24_i69;
  int32_T c24_i70;
  int32_T c24_i71;
  int32_T c24_i72;
  boolean_T c24_b_iLow[2];
  int32_T c24_d_loop_ub;
  int32_T c24_i73;
  int32_T c24_i74;
  boolean_T c24_c_iLow[2];
  int32_T c24_e_loop_ub;
  int32_T c24_i75;
  int32_T c24_i76;
  boolean_T c24_d_iLow[2];
  int32_T c24_f_loop_ub;
  int32_T c24_i77;
  int32_T c24_i78;
  int32_T c24_i79;
  int32_T c24_i80;
  real_T c24_b[9];
  int32_T c24_i81;
  int32_T c24_i82;
  real_T c24_a[4];
  int32_T c24_i83;
  int32_T c24_i84;
  int32_T c24_i85;
  int32_T c24_i86;
  real_T c24_IncCalConst[6];
  int32_T c24_i87;
  real_T c24_IncMaxTick[6];
  int32_T c24_i88;
  real_T c24_c_AbsAngle[6];
  int32_T c24_i89;
  real_T c24_b_IncTick[6];
  uint32_T c24_c_debug_family_var_map[8];
  real_T c24_c_nargin = 4.0;
  real_T c24_c_nargout = 2.0;
  real_T c24_c_IncCalTick[6];
  real_T c24_dv4[6];
  int32_T c24_i90;
  real_T c24_d_AbsAngle[6];
  int32_T c24_i91;
  real_T c24_b_IncCalConst[6];
  real_T c24_x[6];
  int32_T c24_i92;
  int32_T c24_i93;
  real_T c24_y[6];
  int32_T c24_i94;
  int32_T c24_k;
  real_T c24_b_k;
  real_T c24_xk;
  real_T c24_yk;
  real_T c24_b_x;
  real_T c24_b_y;
  real_T c24_r;
  real_T c24_c_x;
  real_T c24_d_x;
  real_T c24_e_x;
  real_T c24_f_x;
  real_T c24_g_x;
  real_T c24_h_x;
  real_T c24_i_x;
  real_T c24_c_y;
  real_T c24_j_x;
  real_T c24_d_y;
  real_T c24_k_x;
  real_T c24_l_x;
  int32_T c24_i95;
  real_T c24_e_AbsAngle[6];
  int32_T c24_i96;
  real_T c24_c_IncCalConst[6];
  int32_T c24_i97;
  real_T c24_m_x[6];
  int32_T c24_i98;
  real_T c24_b_IncMaxTick[6];
  int32_T c24_i99;
  int32_T c24_c_k;
  real_T c24_d_k;
  real_T c24_n_x;
  real_T c24_o_x;
  int32_T c24_i100;
  int32_T c24_i101;
  int32_T c24_i102;
  real_T c24_MaxTick[9];
  int32_T c24_i103;
  real_T c24_c_IncEncoders[9];
  int32_T c24_i104;
  real_T c24_c_IncEncodersPrev[9];
  real_T c24_NormalizedCountPrev[9];
  real_T c24_NormalizedCount[9];
  real_T c24_d_nargin = 3.0;
  real_T c24_d_nargout = 1.0;
  real_T c24_c_Rollover[9];
  int32_T c24_i105;
  real_T c24_d_IncEncodersPrev[9];
  int32_T c24_i106;
  real_T c24_b_MaxTick[9];
  real_T c24_dv5[9];
  int32_T c24_i107;
  int32_T c24_i108;
  real_T c24_d_IncEncoders[9];
  int32_T c24_i109;
  real_T c24_c_MaxTick[9];
  real_T c24_dv6[9];
  int32_T c24_i110;
  int32_T c24_i111;
  int32_T c24_i112;
  boolean_T c24_bv2[9];
  int32_T c24_i113;
  boolean_T c24_bv3[9];
  int32_T c24_i114;
  boolean_T c24_bv4[9];
  int32_T c24_d_tmp_sizes;
  int32_T c24_d_tmp_data[9];
  int32_T c24_g_loop_ub;
  int32_T c24_i115;
  int32_T c24_i116;
  int32_T c24_i117;
  int32_T c24_i118;
  boolean_T c24_bv5[9];
  int32_T c24_h_loop_ub;
  int32_T c24_i119;
  int32_T c24_i120;
  int32_T c24_i121;
  int32_T c24_i122;
  int32_T c24_i123;
  int32_T c24_i124;
  int32_T c24_i125;
  int32_T c24_i126;
  int32_T c24_i127;
  real_T c24_c_Calibration[9];
  int32_T c24_i128;
  int32_T c24_i129;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 17U, 17U, c24_e_debug_family_names,
    c24_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_RefAngle, 0U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_IncCalTickB, 1U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_IncCalAngle, 2U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_IncTick, 3U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargin, 4U, c24_f_sf_marshallOut,
    c24_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_nargout, 5U, c24_f_sf_marshallOut,
    c24_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_Calibration, 6U,
    c24_e_sf_marshallOut, c24_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_AbsEncoders, 7U,
    c24_c_sf_marshallOut, c24_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_IncEncoders, 8U,
    c24_b_sf_marshallOut, c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_IncEncodersPrev, 9U,
    c24_b_sf_marshallOut, c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_Reset, 10U, c24_d_sf_marshallOut,
    c24_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_RolloverIn, 11U,
    c24_b_sf_marshallOut, c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_IncCalTickIn, 12U,
    c24_sf_marshallOut, c24_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_AbsAngle, 13U, c24_c_sf_marshallOut,
    c24_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_IncAngle, 14U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_Rollover, 15U, c24_b_sf_marshallOut,
    c24_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_IncCalTick, 16U, c24_sf_marshallOut,
    c24_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 11);
  for (c24_i53 = 0; c24_i53 < 2; c24_i53++) {
    c24_AbsMaxTick[c24_i53] = c24_b_Calibration->AbsMaxTick[c24_i53 + 8];
  }

  for (c24_i54 = 0; c24_i54 < 2; c24_i54++) {
    c24_AbsCalTick[c24_i54] = c24_b_Calibration->AbsCalTick[c24_i54 + 8];
  }

  for (c24_i55 = 0; c24_i55 < 2; c24_i55++) {
    c24_AbsEncoder[c24_i55] = c24_b_AbsEncoders[c24_i55 + 8];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c24_b_debug_family_names,
    c24_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_HalfMaxTicks, 0U,
    c24_g_sf_marshallOut, c24_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_CalOffset, 1U, c24_g_sf_marshallOut,
    c24_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_iHigh, 2U, c24_h_sf_marshallOut,
    c24_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_iLow, 3U, c24_h_sf_marshallOut,
    c24_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_nargin, 4U, c24_f_sf_marshallOut,
    c24_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_b_nargout, 5U, c24_f_sf_marshallOut,
    c24_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_AbsMaxTick, 6U, c24_g_sf_marshallOut,
    c24_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_AbsCalTick, 7U, c24_g_sf_marshallOut,
    c24_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_AbsEncoder, 8U, c24_g_sf_marshallOut,
    c24_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_AbsUnrolled, 9U, c24_g_sf_marshallOut,
    c24_e_sf_marshallIn);
  CV_SCRIPT_FCN(0, 3);
  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 68);
  for (c24_i56 = 0; c24_i56 < 2; c24_i56++) {
    c24_AbsUnrolled[c24_i56] = c24_AbsEncoder[c24_i56];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 71);
  for (c24_i57 = 0; c24_i57 < 2; c24_i57++) {
    c24_A[c24_i57] = c24_AbsMaxTick[c24_i57];
  }

  for (c24_i58 = 0; c24_i58 < 2; c24_i58++) {
    c24_HalfMaxTicks[c24_i58] = c24_A[c24_i58] / 2.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 72);
  for (c24_i59 = 0; c24_i59 < 2; c24_i59++) {
    c24_CalOffset[c24_i59] = c24_AbsCalTick[c24_i59] - c24_HalfMaxTicks[c24_i59];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 77);
  for (c24_i60 = 0; c24_i60 < 2; c24_i60++) {
    c24_bv0[c24_i60] = (c24_CalOffset[c24_i60] < 0.0);
  }

  for (c24_i61 = 0; c24_i61 < 2; c24_i61++) {
    c24_bv1[c24_i61] = (c24_AbsEncoder[c24_i61] > c24_AbsCalTick[c24_i61] +
                        c24_HalfMaxTicks[c24_i61]);
  }

  for (c24_i62 = 0; c24_i62 < 2; c24_i62++) {
    c24_iHigh[c24_i62] = (c24_bv0[c24_i62] && c24_bv1[c24_i62]);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 78);
  for (c24_i63 = 0; c24_i63 < 2; c24_i63++) {
    c24_b_iHigh[c24_i63] = c24_iHigh[c24_i63];
  }

  c24_eml_li_find(chartInstance, c24_b_iHigh, c24_tmp_data, &c24_tmp_sizes);
  c24_b_tmp_sizes = c24_tmp_sizes;
  c24_loop_ub = c24_tmp_sizes - 1;
  for (c24_i64 = 0; c24_i64 <= c24_loop_ub; c24_i64++) {
    c24_b_tmp_data[c24_i64] = c24_AbsUnrolled[c24_tmp_data[c24_i64] - 1];
  }

  for (c24_i65 = 0; c24_i65 < 2; c24_i65++) {
    c24_c_iHigh[c24_i65] = c24_iHigh[c24_i65];
  }

  c24_eml_li_find(chartInstance, c24_c_iHigh, c24_tmp_data, &c24_tmp_sizes);
  c24_c_tmp_sizes = c24_tmp_sizes;
  c24_b_loop_ub = c24_tmp_sizes - 1;
  for (c24_i66 = 0; c24_i66 <= c24_b_loop_ub; c24_i66++) {
    c24_c_tmp_data[c24_i66] = c24_AbsMaxTick[c24_tmp_data[c24_i66] - 1];
  }

  _SFD_SIZE_EQ_CHECK_1D(c24_b_tmp_sizes, c24_c_tmp_sizes);
  for (c24_i67 = 0; c24_i67 < 2; c24_i67++) {
    c24_d_iHigh[c24_i67] = c24_iHigh[c24_i67];
  }

  c24_eml_li_find(chartInstance, c24_d_iHigh, c24_tmp_data, &c24_tmp_sizes);
  _SFD_SIZE_EQ_CHECK_1D(c24_tmp_sizes, c24_b_tmp_sizes);
  c24_c_loop_ub = c24_b_tmp_sizes - 1;
  for (c24_i68 = 0; c24_i68 <= c24_c_loop_ub; c24_i68++) {
    c24_AbsUnrolled[c24_tmp_data[c24_i68] - 1] = c24_b_tmp_data[c24_i68] -
      c24_c_tmp_data[c24_i68];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 83);
  for (c24_i69 = 0; c24_i69 < 2; c24_i69++) {
    c24_bv0[c24_i69] = (c24_CalOffset[c24_i69] > 0.0);
  }

  for (c24_i70 = 0; c24_i70 < 2; c24_i70++) {
    c24_bv1[c24_i70] = (c24_AbsEncoder[c24_i70] < c24_AbsCalTick[c24_i70] -
                        c24_HalfMaxTicks[c24_i70]);
  }

  for (c24_i71 = 0; c24_i71 < 2; c24_i71++) {
    c24_iLow[c24_i71] = (c24_bv0[c24_i71] && c24_bv1[c24_i71]);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 84);
  for (c24_i72 = 0; c24_i72 < 2; c24_i72++) {
    c24_b_iLow[c24_i72] = c24_iLow[c24_i72];
  }

  c24_eml_li_find(chartInstance, c24_b_iLow, c24_tmp_data, &c24_tmp_sizes);
  c24_b_tmp_sizes = c24_tmp_sizes;
  c24_d_loop_ub = c24_tmp_sizes - 1;
  for (c24_i73 = 0; c24_i73 <= c24_d_loop_ub; c24_i73++) {
    c24_b_tmp_data[c24_i73] = c24_AbsUnrolled[c24_tmp_data[c24_i73] - 1];
  }

  for (c24_i74 = 0; c24_i74 < 2; c24_i74++) {
    c24_c_iLow[c24_i74] = c24_iLow[c24_i74];
  }

  c24_eml_li_find(chartInstance, c24_c_iLow, c24_tmp_data, &c24_tmp_sizes);
  c24_c_tmp_sizes = c24_tmp_sizes;
  c24_e_loop_ub = c24_tmp_sizes - 1;
  for (c24_i75 = 0; c24_i75 <= c24_e_loop_ub; c24_i75++) {
    c24_c_tmp_data[c24_i75] = c24_AbsMaxTick[c24_tmp_data[c24_i75] - 1];
  }

  _SFD_SIZE_EQ_CHECK_1D(c24_b_tmp_sizes, c24_c_tmp_sizes);
  for (c24_i76 = 0; c24_i76 < 2; c24_i76++) {
    c24_d_iLow[c24_i76] = c24_iLow[c24_i76];
  }

  c24_eml_li_find(chartInstance, c24_d_iLow, c24_tmp_data, &c24_tmp_sizes);
  _SFD_SIZE_EQ_CHECK_1D(c24_tmp_sizes, c24_b_tmp_sizes);
  c24_f_loop_ub = c24_b_tmp_sizes - 1;
  for (c24_i77 = 0; c24_i77 <= c24_f_loop_ub; c24_i77++) {
    c24_AbsUnrolled[c24_tmp_data[c24_i77] - 1] = c24_b_tmp_data[c24_i77] +
      c24_c_tmp_data[c24_i77];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, -84);
  _SFD_SYMBOL_SCOPE_POP();
  for (c24_i78 = 0; c24_i78 < 2; c24_i78++) {
    c24_b_AbsEncoders[c24_i78 + 8] = c24_AbsUnrolled[c24_i78];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 14);
  for (c24_i79 = 0; c24_i79 < 10; c24_i79++) {
    c24_b_AbsAngle[c24_i79] = c24_b_Calibration->AbsCalAngle[c24_i79] +
      c24_b_Calibration->AbsCalConst[c24_i79] * (c24_b_AbsEncoders[c24_i79] -
      c24_b_Calibration->AbsCalTick[c24_i79]);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 17);
  if (CV_SCRIPT_IF(0, 0, c24_b_Reset)) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 18);
    for (c24_i80 = 0; c24_i80 < 9; c24_i80++) {
      c24_b[c24_i80] = c24_b_RolloverIn[c24_i80];
    }

    for (c24_i81 = 0; c24_i81 < 9; c24_i81++) {
      c24_b_Rollover[c24_i81] = 0.0 * c24_b[c24_i81];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 19);
    for (c24_i82 = 0; c24_i82 < 4; c24_i82++) {
      c24_a[c24_i82] = c24_b_AbsAngle[c24_i82 + 4];
    }

    for (c24_i83 = 0; c24_i83 < 4; c24_i83++) {
      c24_a[c24_i83] *= 50.0;
    }

    for (c24_i84 = 0; c24_i84 < 4; c24_i84++) {
      c24_RefAngle[c24_i84] = c24_a[c24_i84];
    }

    for (c24_i85 = 0; c24_i85 < 2; c24_i85++) {
      c24_RefAngle[c24_i85 + 4] = c24_b_AbsAngle[c24_i85 + 8];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 20);
    for (c24_i86 = 0; c24_i86 < 6; c24_i86++) {
      c24_IncCalConst[c24_i86] = c24_b_Calibration->IncCalConst[c24_i86];
    }

    for (c24_i87 = 0; c24_i87 < 6; c24_i87++) {
      c24_IncMaxTick[c24_i87] = c24_b_Calibration->IncMaxTick[c24_i87];
    }

    for (c24_i88 = 0; c24_i88 < 6; c24_i88++) {
      c24_c_AbsAngle[c24_i88] = c24_RefAngle[c24_i88];
    }

    for (c24_i89 = 0; c24_i89 < 6; c24_i89++) {
      c24_b_IncTick[c24_i89] = c24_b_IncEncoders[c24_i89];
    }

    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c24_c_debug_family_names,
      c24_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_c_nargin, 0U, c24_f_sf_marshallOut,
      c24_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_c_nargout, 1U,
      c24_f_sf_marshallOut, c24_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_IncCalConst, 2U, c24_sf_marshallOut,
      c24_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_IncMaxTick, 3U, c24_sf_marshallOut,
      c24_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_c_AbsAngle, 4U, c24_sf_marshallOut,
      c24_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_b_IncTick, 5U, c24_sf_marshallOut,
      c24_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_c_IncCalTick, 6U,
      c24_sf_marshallOut, c24_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_dv4, 7U, c24_sf_marshallOut,
      c24_sf_marshallIn);
    CV_SCRIPT_FCN(0, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 36);
    for (c24_i90 = 0; c24_i90 < 6; c24_i90++) {
      c24_d_AbsAngle[c24_i90] = c24_c_AbsAngle[c24_i90];
    }

    for (c24_i91 = 0; c24_i91 < 6; c24_i91++) {
      c24_b_IncCalConst[c24_i91] = c24_IncCalConst[c24_i91];
    }

    c24_rdivide(chartInstance, c24_d_AbsAngle, c24_b_IncCalConst, c24_x);
    for (c24_i92 = 0; c24_i92 < 6; c24_i92++) {
      c24_x[c24_i92] = c24_b_IncTick[c24_i92] - c24_x[c24_i92];
    }

    for (c24_i93 = 0; c24_i93 < 6; c24_i93++) {
      c24_y[c24_i93] = c24_IncMaxTick[c24_i93];
    }

    for (c24_i94 = 0; c24_i94 < 6; c24_i94++) {
      c24_c_IncCalTick[c24_i94] = 0.0;
    }

    for (c24_k = 0; c24_k < 6; c24_k++) {
      c24_b_k = 1.0 + (real_T)c24_k;
      c24_xk = c24_x[(int32_T)c24_b_k - 1];
      c24_yk = c24_y[(int32_T)c24_b_k - 1];
      c24_b_x = c24_xk;
      c24_b_y = c24_yk;
      if (c24_b_y == 0.0) {
        c24_r = c24_b_x;
      } else {
        c24_c_x = c24_b_y;
        c24_d_x = c24_c_x;
        c24_d_x = muDoubleScalarFloor(c24_d_x);
        if (c24_b_y == c24_d_x) {
          c24_e_x = c24_b_x / c24_b_y;
          c24_f_x = c24_e_x;
          c24_f_x = muDoubleScalarFloor(c24_f_x);
          c24_r = c24_b_x - c24_f_x * c24_b_y;
        } else {
          c24_r = c24_b_x / c24_b_y;
          c24_g_x = c24_r;
          c24_h_x = c24_g_x;
          c24_h_x = muDoubleScalarRound(c24_h_x);
          c24_i_x = c24_r - c24_h_x;
          c24_c_y = muDoubleScalarAbs(c24_i_x);
          c24_j_x = c24_r;
          c24_d_y = muDoubleScalarAbs(c24_j_x);
          if (c24_c_y <= 2.2204460492503131E-16 * c24_d_y) {
            c24_r = 0.0;
          } else {
            c24_k_x = c24_r;
            c24_l_x = c24_k_x;
            c24_l_x = muDoubleScalarFloor(c24_l_x);
            c24_r = (c24_r - c24_l_x) * c24_b_y;
          }
        }
      }

      c24_c_IncCalTick[(int32_T)c24_b_k - 1] = c24_r;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 38);
    for (c24_i95 = 0; c24_i95 < 6; c24_i95++) {
      c24_e_AbsAngle[c24_i95] = c24_c_AbsAngle[c24_i95];
    }

    for (c24_i96 = 0; c24_i96 < 6; c24_i96++) {
      c24_c_IncCalConst[c24_i96] = c24_IncCalConst[c24_i96];
    }

    c24_rdivide(chartInstance, c24_e_AbsAngle, c24_c_IncCalConst, c24_x);
    for (c24_i97 = 0; c24_i97 < 6; c24_i97++) {
      c24_m_x[c24_i97] = (c24_x[c24_i97] - c24_b_IncTick[c24_i97]) +
        c24_c_IncCalTick[c24_i97];
    }

    for (c24_i98 = 0; c24_i98 < 6; c24_i98++) {
      c24_b_IncMaxTick[c24_i98] = c24_IncMaxTick[c24_i98];
    }

    c24_rdivide(chartInstance, c24_m_x, c24_b_IncMaxTick, c24_x);
    for (c24_i99 = 0; c24_i99 < 6; c24_i99++) {
      c24_dv4[c24_i99] = c24_x[c24_i99];
    }

    for (c24_c_k = 0; c24_c_k < 6; c24_c_k++) {
      c24_d_k = 1.0 + (real_T)c24_c_k;
      c24_n_x = c24_dv4[(int32_T)c24_d_k - 1];
      c24_o_x = c24_n_x;
      c24_o_x = muDoubleScalarFloor(c24_o_x);
      c24_dv4[(int32_T)c24_d_k - 1] = c24_o_x;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, -38);
    _SFD_SYMBOL_SCOPE_POP();
    for (c24_i100 = 0; c24_i100 < 6; c24_i100++) {
      c24_b_IncCalTick[c24_i100] = c24_c_IncCalTick[c24_i100];
    }

    for (c24_i101 = 0; c24_i101 < 6; c24_i101++) {
      c24_b_Rollover[c24_i101] = c24_dv4[c24_i101];
    }
  } else {
    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 23);
    for (c24_i102 = 0; c24_i102 < 9; c24_i102++) {
      c24_MaxTick[c24_i102] = c24_b_Calibration->MaxTick[c24_i102];
    }

    for (c24_i103 = 0; c24_i103 < 9; c24_i103++) {
      c24_c_IncEncoders[c24_i103] = c24_b_IncEncoders[c24_i103];
    }

    for (c24_i104 = 0; c24_i104 < 9; c24_i104++) {
      c24_c_IncEncodersPrev[c24_i104] = c24_b_IncEncodersPrev[c24_i104];
    }

    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c24_d_debug_family_names,
      c24_c_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_NormalizedCountPrev, 0U,
      c24_b_sf_marshallOut, c24_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_NormalizedCount, 1U,
      c24_b_sf_marshallOut, c24_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_d_nargin, 2U, c24_f_sf_marshallOut,
      c24_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c24_d_nargout, 3U,
      c24_f_sf_marshallOut, c24_d_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_MaxTick, 4U, c24_b_sf_marshallOut,
      c24_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_c_IncEncoders, 5U,
      c24_b_sf_marshallOut, c24_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_c_IncEncodersPrev, 6U,
      c24_b_sf_marshallOut, c24_b_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c24_c_Rollover, 7U,
      c24_b_sf_marshallOut, c24_b_sf_marshallIn);
    CV_SCRIPT_FCN(0, 2);
    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 55);
    for (c24_i105 = 0; c24_i105 < 9; c24_i105++) {
      c24_d_IncEncodersPrev[c24_i105] = c24_c_IncEncodersPrev[c24_i105];
    }

    for (c24_i106 = 0; c24_i106 < 9; c24_i106++) {
      c24_b_MaxTick[c24_i106] = c24_MaxTick[c24_i106];
    }

    c24_b_rdivide(chartInstance, c24_d_IncEncodersPrev, c24_b_MaxTick, c24_dv5);
    for (c24_i107 = 0; c24_i107 < 9; c24_i107++) {
      c24_NormalizedCountPrev[c24_i107] = c24_dv5[c24_i107];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 56);
    for (c24_i108 = 0; c24_i108 < 9; c24_i108++) {
      c24_d_IncEncoders[c24_i108] = c24_c_IncEncoders[c24_i108];
    }

    for (c24_i109 = 0; c24_i109 < 9; c24_i109++) {
      c24_c_MaxTick[c24_i109] = c24_MaxTick[c24_i109];
    }

    c24_b_rdivide(chartInstance, c24_d_IncEncoders, c24_c_MaxTick, c24_dv6);
    for (c24_i110 = 0; c24_i110 < 9; c24_i110++) {
      c24_NormalizedCount[c24_i110] = c24_dv6[c24_i110];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 58);
    for (c24_i111 = 0; c24_i111 < 9; c24_i111++) {
      c24_c_Rollover[c24_i111] = 0.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 59);
    for (c24_i112 = 0; c24_i112 < 9; c24_i112++) {
      c24_bv2[c24_i112] = (c24_NormalizedCountPrev[c24_i112] < 0.5);
    }

    for (c24_i113 = 0; c24_i113 < 9; c24_i113++) {
      c24_bv3[c24_i113] = (c24_NormalizedCount[c24_i113] >
                           c24_NormalizedCountPrev[c24_i113] + 0.5);
    }

    for (c24_i114 = 0; c24_i114 < 9; c24_i114++) {
      c24_bv4[c24_i114] = (c24_bv2[c24_i114] && c24_bv3[c24_i114]);
    }

    c24_b_eml_li_find(chartInstance, c24_bv4, c24_d_tmp_data, &c24_d_tmp_sizes);
    c24_g_loop_ub = c24_d_tmp_sizes - 1;
    for (c24_i115 = 0; c24_i115 <= c24_g_loop_ub; c24_i115++) {
      c24_c_Rollover[c24_d_tmp_data[c24_i115] - 1] = -1.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 60);
    for (c24_i116 = 0; c24_i116 < 9; c24_i116++) {
      c24_bv2[c24_i116] = (c24_NormalizedCountPrev[c24_i116] > 0.5);
    }

    for (c24_i117 = 0; c24_i117 < 9; c24_i117++) {
      c24_bv3[c24_i117] = (c24_NormalizedCount[c24_i117] <
                           c24_NormalizedCountPrev[c24_i117] - 0.5);
    }

    for (c24_i118 = 0; c24_i118 < 9; c24_i118++) {
      c24_bv5[c24_i118] = (c24_bv2[c24_i118] && c24_bv3[c24_i118]);
    }

    c24_b_eml_li_find(chartInstance, c24_bv5, c24_d_tmp_data, &c24_d_tmp_sizes);
    c24_h_loop_ub = c24_d_tmp_sizes - 1;
    for (c24_i119 = 0; c24_i119 <= c24_h_loop_ub; c24_i119++) {
      c24_c_Rollover[c24_d_tmp_data[c24_i119] - 1] = 1.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, -60);
    _SFD_SYMBOL_SCOPE_POP();
    for (c24_i120 = 0; c24_i120 < 9; c24_i120++) {
      c24_b_Rollover[c24_i120] = c24_b_RolloverIn[c24_i120] +
        c24_c_Rollover[c24_i120];
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 24);
    for (c24_i121 = 0; c24_i121 < 6; c24_i121++) {
      c24_b_IncCalTick[c24_i121] = c24_b_IncCalTickIn[c24_i121];
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 28);
  for (c24_i122 = 0; c24_i122 < 6; c24_i122++) {
    c24_IncCalTickB[c24_i122] = c24_b_IncCalTick[c24_i122];
  }

  for (c24_i123 = 0; c24_i123 < 3; c24_i123++) {
    c24_IncCalTickB[c24_i123 + 6] = c24_b_Calibration->BoomCalTick[c24_i123];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 29);
  for (c24_i124 = 0; c24_i124 < 6; c24_i124++) {
    c24_IncCalAngle[c24_i124] = 0.0;
  }

  for (c24_i125 = 0; c24_i125 < 3; c24_i125++) {
    c24_IncCalAngle[c24_i125 + 6] = c24_b_Calibration->BoomCalAngle[c24_i125];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 30);
  for (c24_i126 = 0; c24_i126 < 9; c24_i126++) {
    c24_IncTick[c24_i126] = c24_b_IncEncoders[c24_i126] +
      c24_b_Calibration->MaxTick[c24_i126] * c24_b_Rollover[c24_i126];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, 31);
  for (c24_i127 = 0; c24_i127 < 6; c24_i127++) {
    c24_c_Calibration[c24_i127] = c24_b_Calibration->IncCalConst[c24_i127];
  }

  for (c24_i128 = 0; c24_i128 < 3; c24_i128++) {
    c24_c_Calibration[c24_i128 + 6] = c24_b_Calibration->BoomCalConst[c24_i128];
  }

  for (c24_i129 = 0; c24_i129 < 9; c24_i129++) {
    c24_b_IncAngle[c24_i129] = c24_IncCalAngle[c24_i129] +
      c24_c_Calibration[c24_i129] * (c24_IncTick[c24_i129] -
      c24_IncCalTickB[c24_i129]);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c24_sfEvent, -31);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c24_machineNumber, uint32_T
  c24_chartNumber, uint32_T c24_instanceNumber)
{
  (void)c24_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c24_chartNumber, c24_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\DAQ_withElmos\\calibrateEncoders2.m"));
}

static const mxArray *c24_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i130;
  real_T c24_b_inData[6];
  int32_T c24_i131;
  real_T c24_u[6];
  const mxArray *c24_y = NULL;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i130 = 0; c24_i130 < 6; c24_i130++) {
    c24_b_inData[c24_i130] = (*(real_T (*)[6])c24_inData)[c24_i130];
  }

  for (c24_i131 = 0; c24_i131 < 6; c24_i131++) {
    c24_u[c24_i131] = c24_b_inData[c24_i131];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static void c24_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_b_IncCalTick, const char_T *c24_identifier,
  real_T c24_y[6])
{
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_IncCalTick),
    &c24_thisId, c24_y);
  sf_mex_destroy(&c24_b_IncCalTick);
}

static void c24_b_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[6])
{
  real_T c24_dv7[6];
  int32_T c24_i132;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv7, 1, 0, 0U, 1, 0U, 1, 6);
  for (c24_i132 = 0; c24_i132 < 6; c24_i132++) {
    c24_y[c24_i132] = c24_dv7[c24_i132];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_IncCalTick;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[6];
  int32_T c24_i133;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_b_IncCalTick = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_IncCalTick),
    &c24_thisId, c24_y);
  sf_mex_destroy(&c24_b_IncCalTick);
  for (c24_i133 = 0; c24_i133 < 6; c24_i133++) {
    (*(real_T (*)[6])c24_outData)[c24_i133] = c24_y[c24_i133];
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_b_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i134;
  real_T c24_b_inData[9];
  int32_T c24_i135;
  real_T c24_u[9];
  const mxArray *c24_y = NULL;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i134 = 0; c24_i134 < 9; c24_i134++) {
    c24_b_inData[c24_i134] = (*(real_T (*)[9])c24_inData)[c24_i134];
  }

  for (c24_i135 = 0; c24_i135 < 9; c24_i135++) {
    c24_u[c24_i135] = c24_b_inData[c24_i135];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 9), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static void c24_c_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_b_Rollover, const char_T *c24_identifier,
  real_T c24_y[9])
{
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_Rollover), &c24_thisId,
    c24_y);
  sf_mex_destroy(&c24_b_Rollover);
}

static void c24_d_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[9])
{
  real_T c24_dv8[9];
  int32_T c24_i136;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv8, 1, 0, 0U, 1, 0U, 1, 9);
  for (c24_i136 = 0; c24_i136 < 9; c24_i136++) {
    c24_y[c24_i136] = c24_dv8[c24_i136];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_Rollover;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[9];
  int32_T c24_i137;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_b_Rollover = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_Rollover), &c24_thisId,
    c24_y);
  sf_mex_destroy(&c24_b_Rollover);
  for (c24_i137 = 0; c24_i137 < 9; c24_i137++) {
    (*(real_T (*)[9])c24_outData)[c24_i137] = c24_y[c24_i137];
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_c_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i138;
  real_T c24_b_inData[10];
  int32_T c24_i139;
  real_T c24_u[10];
  const mxArray *c24_y = NULL;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i138 = 0; c24_i138 < 10; c24_i138++) {
    c24_b_inData[c24_i138] = (*(real_T (*)[10])c24_inData)[c24_i138];
  }

  for (c24_i139 = 0; c24_i139 < 10; c24_i139++) {
    c24_u[c24_i139] = c24_b_inData[c24_i139];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 10), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static void c24_e_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_b_AbsAngle, const char_T *c24_identifier,
  real_T c24_y[10])
{
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_AbsAngle), &c24_thisId,
    c24_y);
  sf_mex_destroy(&c24_b_AbsAngle);
}

static void c24_f_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[10])
{
  real_T c24_dv9[10];
  int32_T c24_i140;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv9, 1, 0, 0U, 1, 0U, 1, 10);
  for (c24_i140 = 0; c24_i140 < 10; c24_i140++) {
    c24_y[c24_i140] = c24_dv9[c24_i140];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_AbsAngle;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[10];
  int32_T c24_i141;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_b_AbsAngle = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_AbsAngle), &c24_thisId,
    c24_y);
  sf_mex_destroy(&c24_b_AbsAngle);
  for (c24_i141 = 0; c24_i141 < 10; c24_i141++) {
    (*(real_T (*)[10])c24_outData)[c24_i141] = c24_y[c24_i141];
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_d_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  boolean_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(boolean_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static const mxArray *c24_e_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  c24_RobotCalibrationBus c24_u;
  const mxArray *c24_y = NULL;
  int32_T c24_i142;
  real_T c24_b_u[10];
  const mxArray *c24_b_y = NULL;
  int32_T c24_i143;
  real_T c24_c_u[3];
  const mxArray *c24_c_y = NULL;
  int32_T c24_i144;
  real_T c24_d_u[10];
  const mxArray *c24_d_y = NULL;
  int32_T c24_i145;
  real_T c24_e_u[10];
  const mxArray *c24_e_y = NULL;
  int32_T c24_i146;
  real_T c24_f_u[10];
  const mxArray *c24_f_y = NULL;
  int32_T c24_i147;
  real_T c24_g_u[6];
  const mxArray *c24_g_y = NULL;
  int32_T c24_i148;
  real_T c24_h_u[6];
  const mxArray *c24_h_y = NULL;
  int32_T c24_i149;
  real_T c24_i_u[3];
  const mxArray *c24_i_y = NULL;
  int32_T c24_i150;
  real_T c24_j_u[3];
  const mxArray *c24_j_y = NULL;
  int32_T c24_i151;
  real_T c24_k_u[3];
  const mxArray *c24_k_y = NULL;
  int32_T c24_i152;
  real_T c24_l_u[9];
  const mxArray *c24_l_y = NULL;
  int32_T c24_i153;
  real_T c24_m_u[9];
  const mxArray *c24_m_y = NULL;
  int32_T c24_i154;
  real_T c24_n_u[9];
  const mxArray *c24_n_y = NULL;
  int32_T c24_i155;
  real_T c24_o_u[9];
  const mxArray *c24_o_y = NULL;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(c24_RobotCalibrationBus *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c24_i142 = 0; c24_i142 < 10; c24_i142++) {
    c24_b_u[c24_i142] = c24_u.AbsCalTick[c24_i142];
  }

  c24_b_y = NULL;
  sf_mex_assign(&c24_b_y, sf_mex_create("y", c24_b_u, 0, 0U, 1U, 0U, 1, 10),
                false);
  sf_mex_addfield(c24_y, c24_b_y, "AbsCalTick", "AbsCalTick", 0);
  for (c24_i143 = 0; c24_i143 < 3; c24_i143++) {
    c24_c_u[c24_i143] = c24_u.BoomCalTick[c24_i143];
  }

  c24_c_y = NULL;
  sf_mex_assign(&c24_c_y, sf_mex_create("y", c24_c_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_addfield(c24_y, c24_c_y, "BoomCalTick", "BoomCalTick", 0);
  for (c24_i144 = 0; c24_i144 < 10; c24_i144++) {
    c24_d_u[c24_i144] = c24_u.AbsCalConst[c24_i144];
  }

  c24_d_y = NULL;
  sf_mex_assign(&c24_d_y, sf_mex_create("y", c24_d_u, 0, 0U, 1U, 0U, 1, 10),
                false);
  sf_mex_addfield(c24_y, c24_d_y, "AbsCalConst", "AbsCalConst", 0);
  for (c24_i145 = 0; c24_i145 < 10; c24_i145++) {
    c24_e_u[c24_i145] = c24_u.AbsCalAngle[c24_i145];
  }

  c24_e_y = NULL;
  sf_mex_assign(&c24_e_y, sf_mex_create("y", c24_e_u, 0, 0U, 1U, 0U, 1, 10),
                false);
  sf_mex_addfield(c24_y, c24_e_y, "AbsCalAngle", "AbsCalAngle", 0);
  for (c24_i146 = 0; c24_i146 < 10; c24_i146++) {
    c24_f_u[c24_i146] = c24_u.AbsMaxTick[c24_i146];
  }

  c24_f_y = NULL;
  sf_mex_assign(&c24_f_y, sf_mex_create("y", c24_f_u, 0, 0U, 1U, 0U, 1, 10),
                false);
  sf_mex_addfield(c24_y, c24_f_y, "AbsMaxTick", "AbsMaxTick", 0);
  for (c24_i147 = 0; c24_i147 < 6; c24_i147++) {
    c24_g_u[c24_i147] = c24_u.IncCalConst[c24_i147];
  }

  c24_g_y = NULL;
  sf_mex_assign(&c24_g_y, sf_mex_create("y", c24_g_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c24_y, c24_g_y, "IncCalConst", "IncCalConst", 0);
  for (c24_i148 = 0; c24_i148 < 6; c24_i148++) {
    c24_h_u[c24_i148] = c24_u.IncMaxTick[c24_i148];
  }

  c24_h_y = NULL;
  sf_mex_assign(&c24_h_y, sf_mex_create("y", c24_h_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c24_y, c24_h_y, "IncMaxTick", "IncMaxTick", 0);
  for (c24_i149 = 0; c24_i149 < 3; c24_i149++) {
    c24_i_u[c24_i149] = c24_u.BoomCalConst[c24_i149];
  }

  c24_i_y = NULL;
  sf_mex_assign(&c24_i_y, sf_mex_create("y", c24_i_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_addfield(c24_y, c24_i_y, "BoomCalConst", "BoomCalConst", 0);
  for (c24_i150 = 0; c24_i150 < 3; c24_i150++) {
    c24_j_u[c24_i150] = c24_u.BoomCalAngle[c24_i150];
  }

  c24_j_y = NULL;
  sf_mex_assign(&c24_j_y, sf_mex_create("y", c24_j_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_addfield(c24_y, c24_j_y, "BoomCalAngle", "BoomCalAngle", 0);
  for (c24_i151 = 0; c24_i151 < 3; c24_i151++) {
    c24_k_u[c24_i151] = c24_u.BoomMaxTick[c24_i151];
  }

  c24_k_y = NULL;
  sf_mex_assign(&c24_k_y, sf_mex_create("y", c24_k_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_addfield(c24_y, c24_k_y, "BoomMaxTick", "BoomMaxTick", 0);
  for (c24_i152 = 0; c24_i152 < 9; c24_i152++) {
    c24_l_u[c24_i152] = c24_u.MaxTick[c24_i152];
  }

  c24_l_y = NULL;
  sf_mex_assign(&c24_l_y, sf_mex_create("y", c24_l_u, 0, 0U, 1U, 0U, 1, 9),
                false);
  sf_mex_addfield(c24_y, c24_l_y, "MaxTick", "MaxTick", 0);
  for (c24_i153 = 0; c24_i153 < 9; c24_i153++) {
    c24_m_u[c24_i153] = c24_u.Motors[c24_i153];
  }

  c24_m_y = NULL;
  sf_mex_assign(&c24_m_y, sf_mex_create("y", c24_m_u, 0, 0U, 1U, 0U, 1, 9),
                false);
  sf_mex_addfield(c24_y, c24_m_y, "Motors", "Motors", 0);
  for (c24_i154 = 0; c24_i154 < 9; c24_i154++) {
    c24_n_u[c24_i154] = c24_u.KVHOrientation[c24_i154];
  }

  c24_n_y = NULL;
  sf_mex_assign(&c24_n_y, sf_mex_create("y", c24_n_u, 0, 0U, 1U, 0U, 2, 3, 3),
                false);
  sf_mex_addfield(c24_y, c24_n_y, "KVHOrientation", "KVHOrientation", 0);
  for (c24_i155 = 0; c24_i155 < 9; c24_i155++) {
    c24_o_u[c24_i155] = c24_u.MicrostrainOrientation[c24_i155];
  }

  c24_o_y = NULL;
  sf_mex_assign(&c24_o_y, sf_mex_create("y", c24_o_u, 0, 0U, 1U, 0U, 2, 3, 3),
                false);
  sf_mex_addfield(c24_y, c24_o_y, "MicrostrainOrientation",
                  "MicrostrainOrientation", 0);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static const mxArray *c24_f_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  real_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(real_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static real_T c24_g_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  real_T c24_y;
  real_T c24_d0;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_d0, 1, 0, 0U, 0, 0U, 0);
  c24_y = c24_d0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_nargout;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_nargout = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_nargout),
    &c24_thisId);
  sf_mex_destroy(&c24_nargout);
  *(real_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_g_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i156;
  real_T c24_b_inData[2];
  int32_T c24_i157;
  real_T c24_u[2];
  const mxArray *c24_y = NULL;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i156 = 0; c24_i156 < 2; c24_i156++) {
    c24_b_inData[c24_i156] = (*(real_T (*)[2])c24_inData)[c24_i156];
  }

  for (c24_i157 = 0; c24_i157 < 2; c24_i157++) {
    c24_u[c24_i157] = c24_b_inData[c24_i157];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static void c24_h_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[2])
{
  real_T c24_dv10[2];
  int32_T c24_i158;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv10, 1, 0, 0U, 1, 0U, 1, 2);
  for (c24_i158 = 0; c24_i158 < 2; c24_i158++) {
    c24_y[c24_i158] = c24_dv10[c24_i158];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_AbsUnrolled;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  real_T c24_y[2];
  int32_T c24_i159;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_AbsUnrolled = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_AbsUnrolled), &c24_thisId,
    c24_y);
  sf_mex_destroy(&c24_AbsUnrolled);
  for (c24_i159 = 0; c24_i159 < 2; c24_i159++) {
    (*(real_T (*)[2])c24_outData)[c24_i159] = c24_y[c24_i159];
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_h_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_i160;
  boolean_T c24_b_inData[2];
  int32_T c24_i161;
  boolean_T c24_u[2];
  const mxArray *c24_y = NULL;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  for (c24_i160 = 0; c24_i160 < 2; c24_i160++) {
    c24_b_inData[c24_i160] = (*(boolean_T (*)[2])c24_inData)[c24_i160];
  }

  for (c24_i161 = 0; c24_i161 < 2; c24_i161++) {
    c24_u[c24_i161] = c24_b_inData[c24_i161];
  }

  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 11, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static void c24_i_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  boolean_T c24_y[2])
{
  boolean_T c24_bv6[2];
  int32_T c24_i162;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_bv6, 1, 11, 0U, 1, 0U, 1, 2);
  for (c24_i162 = 0; c24_i162 < 2; c24_i162++) {
    c24_y[c24_i162] = c24_bv6[c24_i162];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_iLow;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  boolean_T c24_y[2];
  int32_T c24_i163;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_iLow = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_iLow), &c24_thisId, c24_y);
  sf_mex_destroy(&c24_iLow);
  for (c24_i163 = 0; c24_i163 < 2; c24_i163++) {
    (*(boolean_T (*)[2])c24_outData)[c24_i163] = c24_y[c24_i163];
  }

  sf_mex_destroy(&c24_mxArrayInData);
}

static boolean_T c24_j_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct *
  chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  boolean_T c24_y;
  boolean_T c24_b0;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_b0, 1, 11, 0U, 0, 0U, 0);
  c24_y = c24_b0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_Reset;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  boolean_T c24_y;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_b_Reset = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_Reset),
    &c24_thisId);
  sf_mex_destroy(&c24_b_Reset);
  *(boolean_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static void c24_k_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  c24_RobotCalibrationBus *c24_y)
{
  emlrtMsgIdentifier c24_thisId;
  static const char * c24_fieldNames[14] = { "AbsCalTick", "BoomCalTick",
    "AbsCalConst", "AbsCalAngle", "AbsMaxTick", "IncCalConst", "IncMaxTick",
    "BoomCalConst", "BoomCalAngle", "BoomMaxTick", "MaxTick", "Motors",
    "KVHOrientation", "MicrostrainOrientation" };

  c24_thisId.fParent = c24_parentId;
  sf_mex_check_struct(c24_parentId, c24_u, 14, c24_fieldNames, 0U, NULL);
  c24_thisId.fIdentifier = "AbsCalTick";
  c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "AbsCalTick", "AbsCalTick", 0)), &c24_thisId, c24_y->AbsCalTick);
  c24_thisId.fIdentifier = "BoomCalTick";
  c24_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "BoomCalTick", "BoomCalTick", 0)), &c24_thisId, c24_y->BoomCalTick);
  c24_thisId.fIdentifier = "AbsCalConst";
  c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "AbsCalConst", "AbsCalConst", 0)), &c24_thisId, c24_y->AbsCalConst);
  c24_thisId.fIdentifier = "AbsCalAngle";
  c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "AbsCalAngle", "AbsCalAngle", 0)), &c24_thisId, c24_y->AbsCalAngle);
  c24_thisId.fIdentifier = "AbsMaxTick";
  c24_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "AbsMaxTick", "AbsMaxTick", 0)), &c24_thisId, c24_y->AbsMaxTick);
  c24_thisId.fIdentifier = "IncCalConst";
  c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "IncCalConst", "IncCalConst", 0)), &c24_thisId, c24_y->IncCalConst);
  c24_thisId.fIdentifier = "IncMaxTick";
  c24_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "IncMaxTick", "IncMaxTick", 0)), &c24_thisId, c24_y->IncMaxTick);
  c24_thisId.fIdentifier = "BoomCalConst";
  c24_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "BoomCalConst", "BoomCalConst", 0)), &c24_thisId, c24_y->BoomCalConst);
  c24_thisId.fIdentifier = "BoomCalAngle";
  c24_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "BoomCalAngle", "BoomCalAngle", 0)), &c24_thisId, c24_y->BoomCalAngle);
  c24_thisId.fIdentifier = "BoomMaxTick";
  c24_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "BoomMaxTick", "BoomMaxTick", 0)), &c24_thisId, c24_y->BoomMaxTick);
  c24_thisId.fIdentifier = "MaxTick";
  c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "MaxTick", "MaxTick", 0)), &c24_thisId, c24_y->MaxTick);
  c24_thisId.fIdentifier = "Motors";
  c24_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "Motors", "Motors", 0)), &c24_thisId, c24_y->Motors);
  c24_thisId.fIdentifier = "KVHOrientation";
  c24_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "KVHOrientation", "KVHOrientation", 0)), &c24_thisId, c24_y->KVHOrientation);
  c24_thisId.fIdentifier = "MicrostrainOrientation";
  c24_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c24_u,
    "MicrostrainOrientation", "MicrostrainOrientation", 0)), &c24_thisId,
    c24_y->MicrostrainOrientation);
  sf_mex_destroy(&c24_u);
}

static void c24_l_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[3])
{
  real_T c24_dv11[3];
  int32_T c24_i164;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv11, 1, 0, 0U, 1, 0U, 1, 3);
  for (c24_i164 = 0; c24_i164 < 3; c24_i164++) {
    c24_y[c24_i164] = c24_dv11[c24_i164];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_m_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId,
  real_T c24_y[9])
{
  real_T c24_dv12[9];
  int32_T c24_i165;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), c24_dv12, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c24_i165 = 0; c24_i165 < 9; c24_i165++) {
    c24_y[c24_i165] = c24_dv12[c24_i165];
  }

  sf_mex_destroy(&c24_u);
}

static void c24_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_Calibration;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  c24_RobotCalibrationBus c24_y;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_b_Calibration = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_Calibration),
    &c24_thisId, &c24_y);
  sf_mex_destroy(&c24_b_Calibration);
  *(c24_RobotCalibrationBus *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

const mxArray *sf_c24_Walking01_withElmos_get_eml_resolved_functions_info(void)
{
  const mxArray *c24_nameCaptureInfo = NULL;
  c24_nameCaptureInfo = NULL;
  sf_mex_assign(&c24_nameCaptureInfo, sf_mex_createstruct("structure", 2, 55, 1),
                false);
  c24_info_helper(&c24_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c24_nameCaptureInfo);
  return c24_nameCaptureInfo;
}

static void c24_info_helper(const mxArray **c24_info)
{
  const mxArray *c24_rhs0 = NULL;
  const mxArray *c24_lhs0 = NULL;
  const mxArray *c24_rhs1 = NULL;
  const mxArray *c24_lhs1 = NULL;
  const mxArray *c24_rhs2 = NULL;
  const mxArray *c24_lhs2 = NULL;
  const mxArray *c24_rhs3 = NULL;
  const mxArray *c24_lhs3 = NULL;
  const mxArray *c24_rhs4 = NULL;
  const mxArray *c24_lhs4 = NULL;
  const mxArray *c24_rhs5 = NULL;
  const mxArray *c24_lhs5 = NULL;
  const mxArray *c24_rhs6 = NULL;
  const mxArray *c24_lhs6 = NULL;
  const mxArray *c24_rhs7 = NULL;
  const mxArray *c24_lhs7 = NULL;
  const mxArray *c24_rhs8 = NULL;
  const mxArray *c24_lhs8 = NULL;
  const mxArray *c24_rhs9 = NULL;
  const mxArray *c24_lhs9 = NULL;
  const mxArray *c24_rhs10 = NULL;
  const mxArray *c24_lhs10 = NULL;
  const mxArray *c24_rhs11 = NULL;
  const mxArray *c24_lhs11 = NULL;
  const mxArray *c24_rhs12 = NULL;
  const mxArray *c24_lhs12 = NULL;
  const mxArray *c24_rhs13 = NULL;
  const mxArray *c24_lhs13 = NULL;
  const mxArray *c24_rhs14 = NULL;
  const mxArray *c24_lhs14 = NULL;
  const mxArray *c24_rhs15 = NULL;
  const mxArray *c24_lhs15 = NULL;
  const mxArray *c24_rhs16 = NULL;
  const mxArray *c24_lhs16 = NULL;
  const mxArray *c24_rhs17 = NULL;
  const mxArray *c24_lhs17 = NULL;
  const mxArray *c24_rhs18 = NULL;
  const mxArray *c24_lhs18 = NULL;
  const mxArray *c24_rhs19 = NULL;
  const mxArray *c24_lhs19 = NULL;
  const mxArray *c24_rhs20 = NULL;
  const mxArray *c24_lhs20 = NULL;
  const mxArray *c24_rhs21 = NULL;
  const mxArray *c24_lhs21 = NULL;
  const mxArray *c24_rhs22 = NULL;
  const mxArray *c24_lhs22 = NULL;
  const mxArray *c24_rhs23 = NULL;
  const mxArray *c24_lhs23 = NULL;
  const mxArray *c24_rhs24 = NULL;
  const mxArray *c24_lhs24 = NULL;
  const mxArray *c24_rhs25 = NULL;
  const mxArray *c24_lhs25 = NULL;
  const mxArray *c24_rhs26 = NULL;
  const mxArray *c24_lhs26 = NULL;
  const mxArray *c24_rhs27 = NULL;
  const mxArray *c24_lhs27 = NULL;
  const mxArray *c24_rhs28 = NULL;
  const mxArray *c24_lhs28 = NULL;
  const mxArray *c24_rhs29 = NULL;
  const mxArray *c24_lhs29 = NULL;
  const mxArray *c24_rhs30 = NULL;
  const mxArray *c24_lhs30 = NULL;
  const mxArray *c24_rhs31 = NULL;
  const mxArray *c24_lhs31 = NULL;
  const mxArray *c24_rhs32 = NULL;
  const mxArray *c24_lhs32 = NULL;
  const mxArray *c24_rhs33 = NULL;
  const mxArray *c24_lhs33 = NULL;
  const mxArray *c24_rhs34 = NULL;
  const mxArray *c24_lhs34 = NULL;
  const mxArray *c24_rhs35 = NULL;
  const mxArray *c24_lhs35 = NULL;
  const mxArray *c24_rhs36 = NULL;
  const mxArray *c24_lhs36 = NULL;
  const mxArray *c24_rhs37 = NULL;
  const mxArray *c24_lhs37 = NULL;
  const mxArray *c24_rhs38 = NULL;
  const mxArray *c24_lhs38 = NULL;
  const mxArray *c24_rhs39 = NULL;
  const mxArray *c24_lhs39 = NULL;
  const mxArray *c24_rhs40 = NULL;
  const mxArray *c24_lhs40 = NULL;
  const mxArray *c24_rhs41 = NULL;
  const mxArray *c24_lhs41 = NULL;
  const mxArray *c24_rhs42 = NULL;
  const mxArray *c24_lhs42 = NULL;
  const mxArray *c24_rhs43 = NULL;
  const mxArray *c24_lhs43 = NULL;
  const mxArray *c24_rhs44 = NULL;
  const mxArray *c24_lhs44 = NULL;
  const mxArray *c24_rhs45 = NULL;
  const mxArray *c24_lhs45 = NULL;
  const mxArray *c24_rhs46 = NULL;
  const mxArray *c24_lhs46 = NULL;
  const mxArray *c24_rhs47 = NULL;
  const mxArray *c24_lhs47 = NULL;
  const mxArray *c24_rhs48 = NULL;
  const mxArray *c24_lhs48 = NULL;
  const mxArray *c24_rhs49 = NULL;
  const mxArray *c24_lhs49 = NULL;
  const mxArray *c24_rhs50 = NULL;
  const mxArray *c24_lhs50 = NULL;
  const mxArray *c24_rhs51 = NULL;
  const mxArray *c24_lhs51 = NULL;
  const mxArray *c24_rhs52 = NULL;
  const mxArray *c24_lhs52 = NULL;
  const mxArray *c24_rhs53 = NULL;
  const mxArray *c24_lhs53 = NULL;
  const mxArray *c24_rhs54 = NULL;
  const mxArray *c24_lhs54 = NULL;
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("calibrateEncoders2"), "name",
                  "name", 0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/calibrateEncoders2.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1432837202U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c24_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/calibrateEncoders2.m!unrollAbsEncoders"),
                  "context", "context", 1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("mrdivide"), "name", "name",
                  1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c24_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c24_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("rdivide"), "name", "name", 3);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c24_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c24_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 5);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c24_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_div"), "name", "name", 6);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c24_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 7);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c24_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/calibrateEncoders2.m!unrollAbsEncoders"),
                  "context", "context", 8);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_li_find"), "name",
                  "name", 8);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c24_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 9);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c24_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 10);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 10);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c24_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 11);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 11);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c24_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 12);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("isfi"), "name", "name", 12);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 12);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c24_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 13);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c24_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 14);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("intmax"), "name", "name", 14);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c24_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 15);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c24_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 16);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("intmin"), "name", "name", 16);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c24_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 17);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c24_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 18);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 18);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c24_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 19);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c24_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 20);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c24_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 21);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c24_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/calibrateEncoders2.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 22);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c24_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 23);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 23);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c24_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/calibrateEncoders2.m!getIncCalTick"),
                  "context", "context", 24);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("rdivide"), "name", "name",
                  24);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c24_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("isequal"), "name", "name",
                  25);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1286840358U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c24_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 26);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c24_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 27);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("isnan"), "name", "name", 27);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c24_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 28);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c24_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/calibrateEncoders2.m!getIncCalTick"),
                  "context", "context", 29);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("mod"), "name", "name", 29);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c24_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 30);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 30);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c24_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 31);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 31);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 31);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c24_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 32);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 32);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c24_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m"), "context",
                  "context", 33);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 33);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c24_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 34);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c24_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p!equalsize"),
                  "context", "context", 35);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("max"), "name", "name", 35);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c24_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 36);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c24_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 37);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 37);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c24_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 38);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 38);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c24_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 39);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 39);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c24_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 40);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 40);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c24_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 41);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 41);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c24_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 42);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 42);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c24_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 43);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 43);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c24_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 44);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalar_round"), "name",
                  "name", 44);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1307672838U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c24_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 45);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 45);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c24_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/mod.m!floatmod"), "context",
                  "context", 46);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eps"), "name", "name", 46);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c24_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 47);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c24_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_eps"), "name", "name",
                  48);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 48);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c24_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 49);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c24_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/calibrateEncoders2.m!getIncCalTick"),
                  "context", "context", 50);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("floor"), "name", "name", 50);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 50);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c24_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 51);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 51);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c24_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 52);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c24_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/calibrateEncoders2.m!getRollover"),
                  "context", "context", 53);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("rdivide"), "name", "name",
                  53);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c24_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/calibrateEncoders2.m!getRollover"),
                  "context", "context", 54);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut("eml_li_find"), "name",
                  "name", 54);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c24_info, c24_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c24_info, c24_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c24_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c24_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c24_info, sf_mex_duplicatearraysafe(&c24_lhs54), "lhs", "lhs",
                  54);
  sf_mex_destroy(&c24_rhs0);
  sf_mex_destroy(&c24_lhs0);
  sf_mex_destroy(&c24_rhs1);
  sf_mex_destroy(&c24_lhs1);
  sf_mex_destroy(&c24_rhs2);
  sf_mex_destroy(&c24_lhs2);
  sf_mex_destroy(&c24_rhs3);
  sf_mex_destroy(&c24_lhs3);
  sf_mex_destroy(&c24_rhs4);
  sf_mex_destroy(&c24_lhs4);
  sf_mex_destroy(&c24_rhs5);
  sf_mex_destroy(&c24_lhs5);
  sf_mex_destroy(&c24_rhs6);
  sf_mex_destroy(&c24_lhs6);
  sf_mex_destroy(&c24_rhs7);
  sf_mex_destroy(&c24_lhs7);
  sf_mex_destroy(&c24_rhs8);
  sf_mex_destroy(&c24_lhs8);
  sf_mex_destroy(&c24_rhs9);
  sf_mex_destroy(&c24_lhs9);
  sf_mex_destroy(&c24_rhs10);
  sf_mex_destroy(&c24_lhs10);
  sf_mex_destroy(&c24_rhs11);
  sf_mex_destroy(&c24_lhs11);
  sf_mex_destroy(&c24_rhs12);
  sf_mex_destroy(&c24_lhs12);
  sf_mex_destroy(&c24_rhs13);
  sf_mex_destroy(&c24_lhs13);
  sf_mex_destroy(&c24_rhs14);
  sf_mex_destroy(&c24_lhs14);
  sf_mex_destroy(&c24_rhs15);
  sf_mex_destroy(&c24_lhs15);
  sf_mex_destroy(&c24_rhs16);
  sf_mex_destroy(&c24_lhs16);
  sf_mex_destroy(&c24_rhs17);
  sf_mex_destroy(&c24_lhs17);
  sf_mex_destroy(&c24_rhs18);
  sf_mex_destroy(&c24_lhs18);
  sf_mex_destroy(&c24_rhs19);
  sf_mex_destroy(&c24_lhs19);
  sf_mex_destroy(&c24_rhs20);
  sf_mex_destroy(&c24_lhs20);
  sf_mex_destroy(&c24_rhs21);
  sf_mex_destroy(&c24_lhs21);
  sf_mex_destroy(&c24_rhs22);
  sf_mex_destroy(&c24_lhs22);
  sf_mex_destroy(&c24_rhs23);
  sf_mex_destroy(&c24_lhs23);
  sf_mex_destroy(&c24_rhs24);
  sf_mex_destroy(&c24_lhs24);
  sf_mex_destroy(&c24_rhs25);
  sf_mex_destroy(&c24_lhs25);
  sf_mex_destroy(&c24_rhs26);
  sf_mex_destroy(&c24_lhs26);
  sf_mex_destroy(&c24_rhs27);
  sf_mex_destroy(&c24_lhs27);
  sf_mex_destroy(&c24_rhs28);
  sf_mex_destroy(&c24_lhs28);
  sf_mex_destroy(&c24_rhs29);
  sf_mex_destroy(&c24_lhs29);
  sf_mex_destroy(&c24_rhs30);
  sf_mex_destroy(&c24_lhs30);
  sf_mex_destroy(&c24_rhs31);
  sf_mex_destroy(&c24_lhs31);
  sf_mex_destroy(&c24_rhs32);
  sf_mex_destroy(&c24_lhs32);
  sf_mex_destroy(&c24_rhs33);
  sf_mex_destroy(&c24_lhs33);
  sf_mex_destroy(&c24_rhs34);
  sf_mex_destroy(&c24_lhs34);
  sf_mex_destroy(&c24_rhs35);
  sf_mex_destroy(&c24_lhs35);
  sf_mex_destroy(&c24_rhs36);
  sf_mex_destroy(&c24_lhs36);
  sf_mex_destroy(&c24_rhs37);
  sf_mex_destroy(&c24_lhs37);
  sf_mex_destroy(&c24_rhs38);
  sf_mex_destroy(&c24_lhs38);
  sf_mex_destroy(&c24_rhs39);
  sf_mex_destroy(&c24_lhs39);
  sf_mex_destroy(&c24_rhs40);
  sf_mex_destroy(&c24_lhs40);
  sf_mex_destroy(&c24_rhs41);
  sf_mex_destroy(&c24_lhs41);
  sf_mex_destroy(&c24_rhs42);
  sf_mex_destroy(&c24_lhs42);
  sf_mex_destroy(&c24_rhs43);
  sf_mex_destroy(&c24_lhs43);
  sf_mex_destroy(&c24_rhs44);
  sf_mex_destroy(&c24_lhs44);
  sf_mex_destroy(&c24_rhs45);
  sf_mex_destroy(&c24_lhs45);
  sf_mex_destroy(&c24_rhs46);
  sf_mex_destroy(&c24_lhs46);
  sf_mex_destroy(&c24_rhs47);
  sf_mex_destroy(&c24_lhs47);
  sf_mex_destroy(&c24_rhs48);
  sf_mex_destroy(&c24_lhs48);
  sf_mex_destroy(&c24_rhs49);
  sf_mex_destroy(&c24_lhs49);
  sf_mex_destroy(&c24_rhs50);
  sf_mex_destroy(&c24_lhs50);
  sf_mex_destroy(&c24_rhs51);
  sf_mex_destroy(&c24_lhs51);
  sf_mex_destroy(&c24_rhs52);
  sf_mex_destroy(&c24_lhs52);
  sf_mex_destroy(&c24_rhs53);
  sf_mex_destroy(&c24_lhs53);
  sf_mex_destroy(&c24_rhs54);
  sf_mex_destroy(&c24_lhs54);
}

static const mxArray *c24_emlrt_marshallOut(const char * c24_u)
{
  const mxArray *c24_y = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", c24_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c24_u)), false);
  return c24_y;
}

static const mxArray *c24_b_emlrt_marshallOut(const uint32_T c24_u)
{
  const mxArray *c24_y = NULL;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 7, 0U, 0U, 0U, 0), false);
  return c24_y;
}

static void c24_eml_li_find(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, boolean_T c24_x[2], int32_T c24_y_data[], int32_T *c24_y_sizes)
{
  int32_T c24_k;
  int32_T c24_i;
  int32_T c24_b_i;
  int32_T c24_a;
  int32_T c24_b_a;
  const mxArray *c24_y = NULL;
  int32_T c24_tmp_sizes;
  int32_T c24_loop_ub;
  int32_T c24_i166;
  int32_T c24_tmp_data[2];
  int32_T c24_j;
  int32_T c24_c_i;
  int32_T c24_d_i;
  int32_T c24_c_a;
  int32_T c24_d_a;
  c24_k = 0;
  c24_intmin(chartInstance);
  for (c24_i = 1; c24_i < 3; c24_i++) {
    c24_b_i = c24_i - 1;
    if (c24_x[c24_b_i]) {
      c24_a = c24_k;
      c24_b_a = c24_a + 1;
      c24_k = c24_b_a;
    }
  }

  if (c24_k <= 2) {
  } else {
    c24_y = NULL;
    sf_mex_assign(&c24_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U, 0U,
      2, 1, strlen("Assertion failed.")), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c24_y);
  }

  c24_tmp_sizes = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c24_k);
  c24_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c24_k) - 1;
  for (c24_i166 = 0; c24_i166 <= c24_loop_ub; c24_i166++) {
    c24_tmp_data[c24_i166] = 0;
  }

  *c24_y_sizes = c24_tmp_sizes;
  c24_j = 1;
  c24_intmin(chartInstance);
  for (c24_c_i = 1; c24_c_i < 3; c24_c_i++) {
    c24_d_i = c24_c_i;
    if (c24_x[c24_d_i - 1]) {
      c24_y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c24_j, 1, *c24_y_sizes, 1, 0) -
        1] = c24_d_i;
      c24_c_a = c24_j;
      c24_d_a = c24_c_a + 1;
      c24_j = c24_d_a;
    }
  }
}

static int32_T c24_intmin(SFc24_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
  return MIN_int32_T;
}

static void c24_rdivide(SFc24_Walking01_withElmosInstanceStruct *chartInstance,
  real_T c24_x[6], real_T c24_y[6], real_T c24_z[6])
{
  int32_T c24_i167;
  (void)chartInstance;
  for (c24_i167 = 0; c24_i167 < 6; c24_i167++) {
    c24_z[c24_i167] = c24_x[c24_i167] / c24_y[c24_i167];
  }
}

static void c24_b_rdivide(SFc24_Walking01_withElmosInstanceStruct *chartInstance,
  real_T c24_x[9], real_T c24_y[9], real_T c24_z[9])
{
  int32_T c24_i168;
  (void)chartInstance;
  for (c24_i168 = 0; c24_i168 < 9; c24_i168++) {
    c24_z[c24_i168] = c24_x[c24_i168] / c24_y[c24_i168];
  }
}

static void c24_b_eml_li_find(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, boolean_T c24_x[9], int32_T c24_y_data[], int32_T *c24_y_sizes)
{
  int32_T c24_k;
  int32_T c24_i;
  int32_T c24_b_i;
  int32_T c24_a;
  int32_T c24_b_a;
  const mxArray *c24_y = NULL;
  int32_T c24_tmp_sizes;
  int32_T c24_loop_ub;
  int32_T c24_i169;
  int32_T c24_tmp_data[9];
  int32_T c24_j;
  int32_T c24_c_i;
  int32_T c24_d_i;
  int32_T c24_c_a;
  int32_T c24_d_a;
  c24_k = 0;
  c24_intmin(chartInstance);
  for (c24_i = 1; c24_i < 10; c24_i++) {
    c24_b_i = c24_i - 1;
    if (c24_x[c24_b_i]) {
      c24_a = c24_k;
      c24_b_a = c24_a + 1;
      c24_k = c24_b_a;
    }
  }

  if (c24_k <= 9) {
  } else {
    c24_y = NULL;
    sf_mex_assign(&c24_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U, 0U,
      2, 1, strlen("Assertion failed.")), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c24_y);
  }

  c24_tmp_sizes = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c24_k);
  c24_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c24_k) - 1;
  for (c24_i169 = 0; c24_i169 <= c24_loop_ub; c24_i169++) {
    c24_tmp_data[c24_i169] = 0;
  }

  *c24_y_sizes = c24_tmp_sizes;
  c24_j = 1;
  c24_intmin(chartInstance);
  for (c24_c_i = 1; c24_c_i < 10; c24_c_i++) {
    c24_d_i = c24_c_i;
    if (c24_x[c24_d_i - 1]) {
      c24_y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c24_j, 1, *c24_y_sizes, 1, 0) -
        1] = c24_d_i;
      c24_c_a = c24_j;
      c24_d_a = c24_c_a + 1;
      c24_j = c24_d_a;
    }
  }
}

static const mxArray *c24_i_sf_marshallOut(void *chartInstanceVoid, void
  *c24_inData)
{
  const mxArray *c24_mxArrayOutData = NULL;
  int32_T c24_u;
  const mxArray *c24_y = NULL;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_mxArrayOutData = NULL;
  c24_u = *(int32_T *)c24_inData;
  c24_y = NULL;
  sf_mex_assign(&c24_y, sf_mex_create("y", &c24_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c24_mxArrayOutData, c24_y, false);
  return c24_mxArrayOutData;
}

static int32_T c24_n_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  int32_T c24_y;
  int32_T c24_i170;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_i170, 1, 6, 0U, 0, 0U, 0);
  c24_y = c24_i170;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void c24_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c24_mxArrayInData, const char_T *c24_varName, void *c24_outData)
{
  const mxArray *c24_b_sfEvent;
  const char_T *c24_identifier;
  emlrtMsgIdentifier c24_thisId;
  int32_T c24_y;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_b_sfEvent = sf_mex_dup(c24_mxArrayInData);
  c24_identifier = c24_varName;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c24_b_sfEvent),
    &c24_thisId);
  sf_mex_destroy(&c24_b_sfEvent);
  *(int32_T *)c24_outData = c24_y;
  sf_mex_destroy(&c24_mxArrayInData);
}

static const mxArray *c24_Calibration_bus_io(void *chartInstanceVoid, void
  *c24_pData)
{
  const mxArray *c24_mxVal = NULL;
  int32_T c24_i171;
  c24_RobotCalibrationBus c24_tmp;
  int32_T c24_i172;
  int32_T c24_i173;
  int32_T c24_i174;
  int32_T c24_i175;
  int32_T c24_i176;
  int32_T c24_i177;
  int32_T c24_i178;
  int32_T c24_i179;
  int32_T c24_i180;
  int32_T c24_i181;
  int32_T c24_i182;
  int32_T c24_i183;
  int32_T c24_i184;
  int32_T c24_i185;
  int32_T c24_i186;
  int32_T c24_i187;
  int32_T c24_i188;
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c24_mxVal = NULL;
  for (c24_i171 = 0; c24_i171 < 10; c24_i171++) {
    c24_tmp.AbsCalTick[c24_i171] = ((real_T *)&((char_T *)
      (c24_RobotCalibrationBus *)c24_pData)[0])[c24_i171];
  }

  for (c24_i172 = 0; c24_i172 < 3; c24_i172++) {
    c24_tmp.BoomCalTick[c24_i172] = ((real_T *)&((char_T *)
      (c24_RobotCalibrationBus *)c24_pData)[80])[c24_i172];
  }

  for (c24_i173 = 0; c24_i173 < 10; c24_i173++) {
    c24_tmp.AbsCalConst[c24_i173] = ((real_T *)&((char_T *)
      (c24_RobotCalibrationBus *)c24_pData)[104])[c24_i173];
  }

  for (c24_i174 = 0; c24_i174 < 10; c24_i174++) {
    c24_tmp.AbsCalAngle[c24_i174] = ((real_T *)&((char_T *)
      (c24_RobotCalibrationBus *)c24_pData)[184])[c24_i174];
  }

  for (c24_i175 = 0; c24_i175 < 10; c24_i175++) {
    c24_tmp.AbsMaxTick[c24_i175] = ((real_T *)&((char_T *)
      (c24_RobotCalibrationBus *)c24_pData)[264])[c24_i175];
  }

  for (c24_i176 = 0; c24_i176 < 6; c24_i176++) {
    c24_tmp.IncCalConst[c24_i176] = ((real_T *)&((char_T *)
      (c24_RobotCalibrationBus *)c24_pData)[344])[c24_i176];
  }

  for (c24_i177 = 0; c24_i177 < 6; c24_i177++) {
    c24_tmp.IncMaxTick[c24_i177] = ((real_T *)&((char_T *)
      (c24_RobotCalibrationBus *)c24_pData)[392])[c24_i177];
  }

  for (c24_i178 = 0; c24_i178 < 3; c24_i178++) {
    c24_tmp.BoomCalConst[c24_i178] = ((real_T *)&((char_T *)
      (c24_RobotCalibrationBus *)c24_pData)[440])[c24_i178];
  }

  for (c24_i179 = 0; c24_i179 < 3; c24_i179++) {
    c24_tmp.BoomCalAngle[c24_i179] = ((real_T *)&((char_T *)
      (c24_RobotCalibrationBus *)c24_pData)[464])[c24_i179];
  }

  for (c24_i180 = 0; c24_i180 < 3; c24_i180++) {
    c24_tmp.BoomMaxTick[c24_i180] = ((real_T *)&((char_T *)
      (c24_RobotCalibrationBus *)c24_pData)[488])[c24_i180];
  }

  for (c24_i181 = 0; c24_i181 < 9; c24_i181++) {
    c24_tmp.MaxTick[c24_i181] = ((real_T *)&((char_T *)(c24_RobotCalibrationBus *)
      c24_pData)[512])[c24_i181];
  }

  for (c24_i182 = 0; c24_i182 < 9; c24_i182++) {
    c24_tmp.Motors[c24_i182] = ((real_T *)&((char_T *)(c24_RobotCalibrationBus *)
      c24_pData)[584])[c24_i182];
  }

  c24_i183 = 0;
  for (c24_i184 = 0; c24_i184 < 3; c24_i184++) {
    for (c24_i185 = 0; c24_i185 < 3; c24_i185++) {
      c24_tmp.KVHOrientation[c24_i185 + c24_i183] = ((real_T *)&((char_T *)
        (c24_RobotCalibrationBus *)c24_pData)[656])[c24_i185 + c24_i183];
    }

    c24_i183 += 3;
  }

  c24_i186 = 0;
  for (c24_i187 = 0; c24_i187 < 3; c24_i187++) {
    for (c24_i188 = 0; c24_i188 < 3; c24_i188++) {
      c24_tmp.MicrostrainOrientation[c24_i188 + c24_i186] = ((real_T *)&((char_T
        *)(c24_RobotCalibrationBus *)c24_pData)[728])[c24_i188 + c24_i186];
    }

    c24_i186 += 3;
  }

  sf_mex_assign(&c24_mxVal, c24_e_sf_marshallOut(chartInstance, &c24_tmp), false);
  return c24_mxVal;
}

static uint8_T c24_o_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_b_is_active_c24_Walking01_withElmos, const
  char_T *c24_identifier)
{
  uint8_T c24_y;
  emlrtMsgIdentifier c24_thisId;
  c24_thisId.fIdentifier = c24_identifier;
  c24_thisId.fParent = NULL;
  c24_y = c24_p_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c24_b_is_active_c24_Walking01_withElmos), &c24_thisId);
  sf_mex_destroy(&c24_b_is_active_c24_Walking01_withElmos);
  return c24_y;
}

static uint8_T c24_p_emlrt_marshallIn(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c24_u, const emlrtMsgIdentifier *c24_parentId)
{
  uint8_T c24_y;
  uint8_T c24_u0;
  (void)chartInstance;
  sf_mex_import(c24_parentId, sf_mex_dup(c24_u), &c24_u0, 1, 3, 0U, 0, 0U, 0);
  c24_y = c24_u0;
  sf_mex_destroy(&c24_u);
  return c24_y;
}

static void init_dsm_address_info(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc24_Walking01_withElmosInstanceStruct
  *chartInstance)
{
  chartInstance->c24_Calibration = (c24_RobotCalibrationBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c24_AbsEncoders = (real_T (*)[10])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c24_IncEncoders = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c24_IncEncodersPrev = (real_T (*)[9])
    ssGetInputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c24_AbsAngle = (real_T (*)[10])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c24_Reset = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c24_IncAngle = (real_T (*)[9])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c24_RolloverIn = (real_T (*)[9])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c24_Rollover = (real_T (*)[9])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c24_IncCalTickIn = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c24_IncCalTick = (real_T (*)[6])ssGetOutputPortSignal_wrapper
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

void sf_c24_Walking01_withElmos_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1468370945U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3162978877U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2002880066U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(202312746U);
}

mxArray* sf_c24_Walking01_withElmos_get_post_codegen_info(void);
mxArray *sf_c24_Walking01_withElmos_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("a4BLA4EmTVlKbO9yUahgOH");
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
    mxArray* mxPostCodegenInfo =
      sf_c24_Walking01_withElmos_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c24_Walking01_withElmos_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c24_Walking01_withElmos_jit_fallback_info(void)
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

mxArray *sf_c24_Walking01_withElmos_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c24_Walking01_withElmos_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c24_Walking01_withElmos(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"AbsAngle\",},{M[1],M[11],T\"IncAngle\",},{M[1],M[22],T\"IncCalTick\",},{M[1],M[17],T\"Rollover\",},{M[8],M[0],T\"is_active_c24_Walking01_withElmos\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c24_Walking01_withElmos_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc24_Walking01_withElmosInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_withElmosMachineNumber_,
           24,
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
        init_script_number_translation(_Walking01_withElmosMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Walking01_withElmosMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Walking01_withElmosMachineNumber_,
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,316);
        _SFD_CV_INIT_SCRIPT(0,4,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"calibrateEncoders2",0,-1,1708);
        _SFD_CV_INIT_SCRIPT_FCN(0,1,"getIncCalTick",1710,-1,2075);
        _SFD_CV_INIT_SCRIPT_FCN(0,2,"getRollover",2077,-1,3186);
        _SFD_CV_INIT_SCRIPT_FCN(0,3,"unrollAbsEncoders",3188,-1,4418);
        _SFD_CV_INIT_SCRIPT_IF(0,0,989,997,1220,1374);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_Calibration_bus_io,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 10;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_c_sf_marshallOut,(MexInFcnForType)
            c24_c_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(5,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c24_d_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)
            c24_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 9;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_b_sf_marshallOut,(MexInFcnForType)
            c24_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c24_sf_marshallOut,(MexInFcnForType)
            c24_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c24_Calibration);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c24_AbsEncoders);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c24_IncEncoders);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c24_IncEncodersPrev);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c24_AbsAngle);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c24_Reset);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c24_IncAngle);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c24_RolloverIn);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c24_Rollover);
        _SFD_SET_DATA_VALUE_PTR(9U, *chartInstance->c24_IncCalTickIn);
        _SFD_SET_DATA_VALUE_PTR(10U, *chartInstance->c24_IncCalTick);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Walking01_withElmosMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "mfov7pLG2vXuk5uP140IbE";
}

static void sf_opaque_initialize_c24_Walking01_withElmos(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc24_Walking01_withElmosInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c24_Walking01_withElmos
    ((SFc24_Walking01_withElmosInstanceStruct*) chartInstanceVar);
  initialize_c24_Walking01_withElmos((SFc24_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c24_Walking01_withElmos(void *chartInstanceVar)
{
  enable_c24_Walking01_withElmos((SFc24_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c24_Walking01_withElmos(void *chartInstanceVar)
{
  disable_c24_Walking01_withElmos((SFc24_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c24_Walking01_withElmos(void *chartInstanceVar)
{
  sf_gateway_c24_Walking01_withElmos((SFc24_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c24_Walking01_withElmos(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c24_Walking01_withElmos
    ((SFc24_Walking01_withElmosInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c24_Walking01_withElmos(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c24_Walking01_withElmos((SFc24_Walking01_withElmosInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c24_Walking01_withElmos(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc24_Walking01_withElmosInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_withElmos_optimization_info();
    }

    finalize_c24_Walking01_withElmos((SFc24_Walking01_withElmosInstanceStruct*)
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
  initSimStructsc24_Walking01_withElmos((SFc24_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c24_Walking01_withElmos(SimStruct *S)
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
    initialize_params_c24_Walking01_withElmos
      ((SFc24_Walking01_withElmosInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c24_Walking01_withElmos(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_withElmos_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      24);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,24,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,24,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,24);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,24,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,24,4);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,24);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2865149839U));
  ssSetChecksum1(S,(3570799319U));
  ssSetChecksum2(S,(177528196U));
  ssSetChecksum3(S,(3120163423U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c24_Walking01_withElmos(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c24_Walking01_withElmos(SimStruct *S)
{
  SFc24_Walking01_withElmosInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc24_Walking01_withElmosInstanceStruct *)utMalloc(sizeof
    (SFc24_Walking01_withElmosInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc24_Walking01_withElmosInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c24_Walking01_withElmos;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c24_Walking01_withElmos;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c24_Walking01_withElmos;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c24_Walking01_withElmos;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c24_Walking01_withElmos;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c24_Walking01_withElmos;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c24_Walking01_withElmos;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c24_Walking01_withElmos;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c24_Walking01_withElmos;
  chartInstance->chartInfo.mdlStart = mdlStart_c24_Walking01_withElmos;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c24_Walking01_withElmos;
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

void c24_Walking01_withElmos_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c24_Walking01_withElmos(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c24_Walking01_withElmos(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c24_Walking01_withElmos(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c24_Walking01_withElmos_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
