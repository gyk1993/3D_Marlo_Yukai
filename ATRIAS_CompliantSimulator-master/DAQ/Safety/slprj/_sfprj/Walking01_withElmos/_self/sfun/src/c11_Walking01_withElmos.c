/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_withElmos_sfun.h"
#include "c11_Walking01_withElmos.h"
#include <string.h>
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
static const char * c11_debug_family_names[10] = { "CMD", "nargin", "nargout",
  "P", "Rotation", "Acceleration", "Status", "Sequence", "Temperature", "Valid"
};

static const char * c11_b_debug_family_names[6] = { "Utmp1", "Utmp2", "nargin",
  "nargout", "D", "U" };

static const char * c11_c_debug_family_names[12] = { "D32", "receivedCRC",
  "generatorPolynomial", "xorIn", "remainderPolynomial", "k", "l", "nextbit",
  "nargin", "nargout", "D0", "valid" };

static const char * c11_d_debug_family_names[7] = { "Stmp1", "Stmp2", "Stmp3",
  "nargin", "nargout", "D", "S" };

static const char * c11_e_debug_family_names[6] = { "Stmp1", "Stmp2", "nargin",
  "nargout", "D", "S" };

/* Function Declarations */
static void initialize_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance);
static void initialize_params_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance);
static void enable_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance);
static void disable_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance);
static void c11_update_debugger_state_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance);
static void set_sim_state_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance, const mxArray *c11_st);
static void finalize_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance);
static void sf_gateway_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance);
static void mdl_start_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance);
static void c11_chartstep_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance);
static void initSimStructsc11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance);
static boolean_T c11_kvhCheckCRC(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, uint32_T c11_D0[36]);
static void c11_parseUint32(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, uint32_T c11_D[36], uint32_T c11_U[9]);
static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber);
static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static boolean_T c11_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_b_Valid, const char_T *c11_identifier);
static boolean_T c11_b_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static real_T c11_c_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_b_Temperature, const char_T *c11_identifier);
static real_T c11_d_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static uint32_T c11_e_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_b_Status, const char_T *c11_identifier);
static uint32_T c11_f_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_g_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_b_Acceleration, const char_T
  *c11_identifier, real_T c11_y[3]);
static void c11_h_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[3]);
static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_i_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[4]);
static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_j_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[9]);
static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static void c11_k_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[36]);
static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_l_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[9]);
static void c11_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_m_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[36]);
static void c11_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_j_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_n_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[12]);
static void c11_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_k_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_o_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real32_T c11_y[3]);
static void c11_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_l_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_p_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[3]);
static void c11_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_m_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_q_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[12]);
static void c11_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_n_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_r_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[2]);
static void c11_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_o_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static uint16_T c11_s_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static const mxArray *c11_p_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static void c11_t_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint16_T c11_y[2]);
static void c11_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static void c11_info_helper(const mxArray **c11_info);
static const mxArray *c11_emlrt_marshallOut(const char * c11_u);
static const mxArray *c11_b_emlrt_marshallOut(const uint32_T c11_u);
static void c11_b_info_helper(const mxArray **c11_info);
static int32_T c11_intmin(SFc11_Walking01_withElmosInstanceStruct *chartInstance);
static boolean_T c11_all_in_integer_range
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance, real_T c11_x, int32_T
   c11_minval, uint8_T c11_maxval);
static void c11_parseSingle(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, uint32_T c11_D[12], real_T c11_S[3]);
static const mxArray *c11_q_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData);
static int32_T c11_u_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void c11_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData);
static uint8_T c11_v_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_Walking01_withElmos, const
  char_T *c11_identifier);
static uint8_T c11_w_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId);
static void init_dsm_address_info(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance)
{
  chartInstance->c11_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c11_is_active_c11_Walking01_withElmos = 0U;
}

static void initialize_params_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c11_update_debugger_state_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance)
{
  const mxArray *c11_st;
  const mxArray *c11_y = NULL;
  int32_T c11_i0;
  real_T c11_u[3];
  const mxArray *c11_b_y = NULL;
  int32_T c11_i1;
  real_T c11_b_u[3];
  const mxArray *c11_c_y = NULL;
  real_T c11_hoistedGlobal;
  real_T c11_c_u;
  const mxArray *c11_d_y = NULL;
  uint32_T c11_b_hoistedGlobal;
  uint32_T c11_d_u;
  const mxArray *c11_e_y = NULL;
  real_T c11_c_hoistedGlobal;
  real_T c11_e_u;
  const mxArray *c11_f_y = NULL;
  boolean_T c11_d_hoistedGlobal;
  boolean_T c11_f_u;
  const mxArray *c11_g_y = NULL;
  uint8_T c11_e_hoistedGlobal;
  uint8_T c11_g_u;
  const mxArray *c11_h_y = NULL;
  c11_st = NULL;
  c11_st = NULL;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_createcellmatrix(7, 1), false);
  for (c11_i0 = 0; c11_i0 < 3; c11_i0++) {
    c11_u[c11_i0] = (*chartInstance->c11_Acceleration)[c11_i0];
  }

  c11_b_y = NULL;
  sf_mex_assign(&c11_b_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c11_y, 0, c11_b_y);
  for (c11_i1 = 0; c11_i1 < 3; c11_i1++) {
    c11_b_u[c11_i1] = (*chartInstance->c11_Rotation)[c11_i1];
  }

  c11_c_y = NULL;
  sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_b_u, 0, 0U, 1U, 0U, 1, 3),
                false);
  sf_mex_setcell(c11_y, 1, c11_c_y);
  c11_hoistedGlobal = *chartInstance->c11_Sequence;
  c11_c_u = c11_hoistedGlobal;
  c11_d_y = NULL;
  sf_mex_assign(&c11_d_y, sf_mex_create("y", &c11_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 2, c11_d_y);
  c11_b_hoistedGlobal = *chartInstance->c11_Status;
  c11_d_u = c11_b_hoistedGlobal;
  c11_e_y = NULL;
  sf_mex_assign(&c11_e_y, sf_mex_create("y", &c11_d_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 3, c11_e_y);
  c11_c_hoistedGlobal = *chartInstance->c11_Temperature;
  c11_e_u = c11_c_hoistedGlobal;
  c11_f_y = NULL;
  sf_mex_assign(&c11_f_y, sf_mex_create("y", &c11_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 4, c11_f_y);
  c11_d_hoistedGlobal = *chartInstance->c11_Valid;
  c11_f_u = c11_d_hoistedGlobal;
  c11_g_y = NULL;
  sf_mex_assign(&c11_g_y, sf_mex_create("y", &c11_f_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 5, c11_g_y);
  c11_e_hoistedGlobal = chartInstance->c11_is_active_c11_Walking01_withElmos;
  c11_g_u = c11_e_hoistedGlobal;
  c11_h_y = NULL;
  sf_mex_assign(&c11_h_y, sf_mex_create("y", &c11_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c11_y, 6, c11_h_y);
  sf_mex_assign(&c11_st, c11_y, false);
  return c11_st;
}

static void set_sim_state_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance, const mxArray *c11_st)
{
  const mxArray *c11_u;
  real_T c11_dv0[3];
  int32_T c11_i2;
  real_T c11_dv1[3];
  int32_T c11_i3;
  chartInstance->c11_doneDoubleBufferReInit = true;
  c11_u = sf_mex_dup(c11_st);
  c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 0)),
    "Acceleration", c11_dv0);
  for (c11_i2 = 0; c11_i2 < 3; c11_i2++) {
    (*chartInstance->c11_Acceleration)[c11_i2] = c11_dv0[c11_i2];
  }

  c11_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 1)),
    "Rotation", c11_dv1);
  for (c11_i3 = 0; c11_i3 < 3; c11_i3++) {
    (*chartInstance->c11_Rotation)[c11_i3] = c11_dv1[c11_i3];
  }

  *chartInstance->c11_Sequence = c11_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 2)), "Sequence");
  *chartInstance->c11_Status = c11_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 3)), "Status");
  *chartInstance->c11_Temperature = c11_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c11_u, 4)), "Temperature");
  *chartInstance->c11_Valid = c11_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c11_u, 5)), "Valid");
  chartInstance->c11_is_active_c11_Walking01_withElmos = c11_v_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c11_u, 6)),
     "is_active_c11_Walking01_withElmos");
  sf_mex_destroy(&c11_u);
  c11_update_debugger_state_c11_Walking01_withElmos(chartInstance);
  sf_mex_destroy(&c11_st);
}

static void finalize_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance)
{
  int32_T c11_i4;
  int32_T c11_i5;
  int32_T c11_i6;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  for (c11_i4 = 0; c11_i4 < 36; c11_i4++) {
    _SFD_DATA_RANGE_CHECK((real_T)(*chartInstance->c11_P)[c11_i4], 0U);
  }

  chartInstance->c11_sfEvent = CALL_EVENT;
  c11_chartstep_c11_Walking01_withElmos(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_withElmosMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c11_i5 = 0; c11_i5 < 3; c11_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c11_Rotation)[c11_i5], 1U);
  }

  for (c11_i6 = 0; c11_i6 < 3; c11_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c11_Acceleration)[c11_i6], 2U);
  }

  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c11_Status, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c11_Sequence, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c11_Temperature, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c11_Valid, 6U);
}

static void mdl_start_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c11_chartstep_c11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance)
{
  int32_T c11_i7;
  uint32_T c11_b_P[36];
  uint32_T c11_debug_family_var_map[10];
  real_T c11_CMD[4];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 6.0;
  real_T c11_b_Rotation[3];
  real_T c11_b_Acceleration[3];
  uint32_T c11_b_Status;
  real_T c11_b_Sequence;
  real_T c11_b_Temperature;
  boolean_T c11_b_Valid;
  int32_T c11_i8;
  static real_T c11_dv2[4] = { 254.0, 129.0, 255.0, 85.0 };

  int32_T c11_i9;
  boolean_T c11_x[4];
  boolean_T c11_y;
  int32_T c11_k;
  real_T c11_b_k;
  int32_T c11_i10;
  uint32_T c11_c_P[36];
  int32_T c11_i11;
  uint32_T c11_d_P[12];
  real_T c11_dv3[3];
  int32_T c11_i12;
  int32_T c11_i13;
  uint32_T c11_e_P[12];
  real_T c11_dv4[3];
  int32_T c11_i14;
  int32_T c11_i15;
  uint32_T c11_D[2];
  uint32_T c11_b_debug_family_var_map[6];
  uint16_T c11_Stmp1[2];
  uint16_T c11_Stmp2;
  real_T c11_b_nargin = 1.0;
  real_T c11_b_nargout = 1.0;
  int32_T c11_i16;
  uint32_T c11_b_x[2];
  int32_T c11_c_k;
  int32_T c11_d_k;
  uint32_T c11_b_y[2];
  int32_T c11_i17;
  uint32_T c11_u0;
  uint16_T c11_b;
  uint16_T c11_u1;
  uint16_T c11_u2;
  uint16_T c11_c_y;
  uint32_T c11_u3;
  int32_T c11_i18;
  int32_T c11_i19;
  boolean_T exitg1;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
  for (c11_i7 = 0; c11_i7 < 36; c11_i7++) {
    c11_b_P[c11_i7] = (*chartInstance->c11_P)[c11_i7];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c11_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_CMD, 0U, c11_f_sf_marshallOut,
    c11_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 1U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 2U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c11_b_P, 3U, c11_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_b_Rotation, 4U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_b_Acceleration, 5U,
    c11_d_sf_marshallOut, c11_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_Status, 6U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_Sequence, 7U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_Temperature, 8U,
    c11_b_sf_marshallOut, c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_Valid, 9U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 3);
  for (c11_i8 = 0; c11_i8 < 4; c11_i8++) {
    c11_CMD[c11_i8] = c11_dv2[c11_i8];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 5);
  c11_b_Valid = false;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i9 = 0; c11_i9 < 4; c11_i9++) {
    c11_x[c11_i9] = ((real_T)c11_b_P[c11_i9] == c11_CMD[c11_i9]);
  }

  c11_y = true;
  c11_k = 0;
  exitg1 = false;
  while ((exitg1 == false) && (c11_k < 4)) {
    c11_b_k = 1.0 + (real_T)c11_k;
    if ((real_T)c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
         _SFD_INTEGER_CHECK("", c11_b_k), 1, 4, 1, 0) - 1] == 0.0) {
      c11_y = false;
      exitg1 = true;
    } else {
      c11_k++;
    }
  }

  if (CV_EML_IF(0, 1, 0, c11_y)) {
    _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 7);
    for (c11_i10 = 0; c11_i10 < 36; c11_i10++) {
      c11_c_P[c11_i10] = c11_b_P[c11_i10];
    }

    c11_b_Valid = c11_kvhCheckCRC(chartInstance, c11_c_P);
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 10);
  for (c11_i11 = 0; c11_i11 < 12; c11_i11++) {
    c11_d_P[c11_i11] = c11_b_P[c11_i11 + 4];
  }

  c11_parseSingle(chartInstance, c11_d_P, c11_dv3);
  for (c11_i12 = 0; c11_i12 < 3; c11_i12++) {
    c11_b_Rotation[c11_i12] = c11_dv3[c11_i12];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 11);
  for (c11_i13 = 0; c11_i13 < 12; c11_i13++) {
    c11_e_P[c11_i13] = c11_b_P[c11_i13 + 16];
  }

  c11_parseSingle(chartInstance, c11_e_P, c11_dv4);
  for (c11_i14 = 0; c11_i14 < 3; c11_i14++) {
    c11_b_Acceleration[c11_i14] = c11_dv4[c11_i14];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 12);
  c11_b_Status = c11_b_P[28];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 13);
  c11_b_Sequence = (real_T)c11_b_P[29];
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 14);
  for (c11_i15 = 0; c11_i15 < 2; c11_i15++) {
    c11_D[c11_i15] = c11_b_P[c11_i15 + 30];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c11_e_debug_family_names,
    c11_b_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_Stmp1, 0U, c11_p_sf_marshallOut,
    c11_p_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_Stmp2, 1U, c11_o_sf_marshallOut,
    c11_o_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargin, 2U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_nargout, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_D, 4U, c11_n_sf_marshallOut,
    c11_n_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_b_Temperature, 5U,
    c11_b_sf_marshallOut, c11_b_sf_marshallIn);
  CV_EML_FCN(0, 2);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 25);
  for (c11_i16 = 0; c11_i16 < 2; c11_i16++) {
    c11_b_x[c11_i16] = c11_D[c11_i16];
  }

  c11_intmin(chartInstance);
  for (c11_c_k = 1; c11_c_k < 3; c11_c_k++) {
    c11_d_k = c11_c_k;
    c11_b_y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c11_d_k), 1, 2, 1, 0) - 1] = c11_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c11_d_k), 1, 2, 1, 0) - 1];
  }

  for (c11_i17 = 0; c11_i17 < 2; c11_i17++) {
    c11_u0 = c11_b_y[c11_i17];
    if (CV_SATURATION_EVAL(4, 0, 6, 0, c11_u0 > 65535U)) {
      c11_u0 = 65535U;
    }

    c11_Stmp1[c11_i17] = (uint16_T)c11_u0;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 26);
  c11_b = c11_Stmp1[0];
  c11_u1 = c11_b;
  if (CV_SATURATION_EVAL(4, 0, 7, 0, c11_u1 > 255)) {
    c11_u2 = MAX_uint16_T;
  } else {
    c11_u2 = (uint16_T)(c11_u1 << 8);
  }

  c11_c_y = c11_u2;
  c11_u3 = (uint32_T)c11_c_y + (uint32_T)c11_Stmp1[1];
  if (CV_SATURATION_EVAL(4, 0, 8, 0, c11_u3 > 65535U)) {
    c11_u3 = 65535U;
  }

  c11_Stmp2 = (uint16_T)c11_u3;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 27);
  c11_b_Temperature = (real_T)c11_Stmp2;
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -27);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -14);
  _SFD_SYMBOL_SCOPE_POP();
  for (c11_i18 = 0; c11_i18 < 3; c11_i18++) {
    (*chartInstance->c11_Rotation)[c11_i18] = c11_b_Rotation[c11_i18];
  }

  for (c11_i19 = 0; c11_i19 < 3; c11_i19++) {
    (*chartInstance->c11_Acceleration)[c11_i19] = c11_b_Acceleration[c11_i19];
  }

  *chartInstance->c11_Status = c11_b_Status;
  *chartInstance->c11_Sequence = c11_b_Sequence;
  *chartInstance->c11_Temperature = c11_b_Temperature;
  *chartInstance->c11_Valid = c11_b_Valid;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c11_sfEvent);
}

static void initSimStructsc11_Walking01_withElmos
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static boolean_T c11_kvhCheckCRC(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, uint32_T c11_D0[36])
{
  boolean_T c11_valid;
  uint32_T c11_debug_family_var_map[12];
  uint32_T c11_D32[9];
  uint32_T c11_receivedCRC;
  uint32_T c11_generatorPolynomial;
  uint32_T c11_xorIn;
  uint32_T c11_remainderPolynomial;
  real_T c11_k;
  real_T c11_l;
  uint32_T c11_nextbit;
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i20;
  uint32_T c11_b_D0[36];
  uint32_T c11_uv0[9];
  int32_T c11_i21;
  uint32_T c11_varargin_1;
  uint32_T c11_a;
  int32_T c11_b_k;
  int32_T c11_b_l;
  uint32_T c11_b_a;
  real_T c11_bit;
  boolean_T c11_cond;
  int32_T c11_i22;
  static char_T c11_cv0[30] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 'b', 'i', 't',
    'S', 'e', 't', 'G', 'e', 't', ':', 'B', 'I', 'T', 'O', 'u', 't', 'O', 'f',
    'R', 'a', 'n', 'g', 'e' };

  char_T c11_u[30];
  const mxArray *c11_y = NULL;
  uint8_T c11_b_u;
  const mxArray *c11_b_y = NULL;
  int32_T c11_i23;
  static char_T c11_cv1[6] = { 'u', 'i', 'n', 't', '3', '2' };

  char_T c11_c_u[6];
  const mxArray *c11_c_y = NULL;
  uint32_T c11_ak;
  real_T c11_d0;
  uint8_T c11_u4;
  uint32_T c11_q0;
  uint32_T c11_qY;
  uint32_T c11_u5;
  uint8_T c11_bitkm1;
  uint32_T c11_c_a;
  uint32_T c11_b_ak;
  uint32_T c11_c;
  uint32_T c11_d_a;
  uint32_T c11_a1;
  uint32_T c11_e_a;
  uint32_T c11_b_c;
  uint64_T c11_u6;
  uint32_T c11_b_varargin_1;
  uint32_T c11_f_a;
  uint32_T c11_g_a;
  uint32_T c11_b_a1;
  uint32_T c11_h_a;
  uint32_T c11_c_c;
  uint64_T c11_u7;
  uint32_T c11_c_varargin_1;
  uint32_T c11_varargin_2;
  uint32_T c11_i_a;
  uint32_T c11_b;
  uint32_T c11_d_c;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c11_c_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_D32, 0U, c11_g_sf_marshallOut,
    c11_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_receivedCRC, 1U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_generatorPolynomial, 2U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c11_xorIn, 3U, c11_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_remainderPolynomial, 4U,
    c11_c_sf_marshallOut, c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_k, 5U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_l, 6U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nextbit, 7U, c11_c_sf_marshallOut,
    c11_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 8U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 9U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_D0, 10U, c11_e_sf_marshallOut,
    c11_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_valid, 11U, c11_sf_marshallOut,
    c11_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 6);
  for (c11_i20 = 0; c11_i20 < 36; c11_i20++) {
    c11_b_D0[c11_i20] = c11_D0[c11_i20];
  }

  c11_parseUint32(chartInstance, c11_b_D0, c11_uv0);
  for (c11_i21 = 0; c11_i21 < 9; c11_i21++) {
    c11_D32[c11_i21] = c11_uv0[c11_i21];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 7);
  c11_receivedCRC = c11_D32[8];
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 8);
  c11_D32[8] = 0U;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 10);
  c11_generatorPolynomial = 79764919U;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 11);
  c11_xorIn = MAX_uint32_T;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 14);
  c11_varargin_1 = c11_D32[0];
  c11_a = c11_varargin_1;
  c11_remainderPolynomial = c11_a ^ MAX_uint32_T;
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 16);
  c11_k = 2.0;
  c11_b_k = 0;
  while (c11_b_k < 8) {
    c11_k = 2.0 + (real_T)c11_b_k;
    CV_SCRIPT_FOR(0, 0, 1);
    _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 17);
    c11_l = 32.0;
    c11_b_l = 0;
    while (c11_b_l < 32) {
      c11_l = 32.0 + -(real_T)c11_b_l;
      CV_SCRIPT_FOR(0, 1, 1);
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 18);
      c11_b_a = c11_D32[_SFD_EML_ARRAY_BOUNDS_CHECK("D32", (int32_T)
        _SFD_INTEGER_CHECK("k", c11_k), 1, 9, 1, 0) - 1];
      c11_bit = c11_l;
      c11_nextbit = 0U;
      c11_cond = c11_all_in_integer_range(chartInstance, c11_bit, 1, 32U);
      if (c11_cond) {
      } else {
        for (c11_i22 = 0; c11_i22 < 30; c11_i22++) {
          c11_u[c11_i22] = c11_cv0[c11_i22];
        }

        c11_y = NULL;
        sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 10, 0U, 1U, 0U, 2, 1, 30),
                      false);
        c11_b_u = 32U;
        c11_b_y = NULL;
        sf_mex_assign(&c11_b_y, sf_mex_create("y", &c11_b_u, 3, 0U, 0U, 0U, 0),
                      false);
        for (c11_i23 = 0; c11_i23 < 6; c11_i23++) {
          c11_c_u[c11_i23] = c11_cv1[c11_i23];
        }

        c11_c_y = NULL;
        sf_mex_assign(&c11_c_y, sf_mex_create("y", c11_c_u, 10, 0U, 1U, 0U, 2, 1,
          6), false);
        sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                          sf_mex_call_debug(sfGlobalDebugInstanceStruct,
          "message", 1U, 3U, 14, c11_y, 14, c11_b_y, 14, c11_c_y));
      }

      c11_ak = c11_b_a;
      c11_d0 = muDoubleScalarRound(c11_bit);
      if (c11_d0 < 256.0) {
        if (CV_SATURATION_EVAL(14, 0, 6, 1, c11_d0 >= 0.0)) {
          c11_u4 = (uint8_T)c11_d0;
        } else {
          c11_u4 = 0U;
        }
      } else if (CV_SATURATION_EVAL(14, 0, 6, 0, c11_d0 >= 256.0)) {
        c11_u4 = MAX_uint8_T;
      } else {
        c11_u4 = 0U;
      }

      c11_q0 = c11_u4;
      c11_qY = c11_q0 - 1U;
      if (CV_SATURATION_EVAL(14, 0, 6, 0, c11_qY > c11_q0)) {
        c11_qY = 0U;
      }

      c11_u5 = c11_qY;
      if (CV_SATURATION_EVAL(14, 0, 6, 0, c11_u5 > 255U)) {
        c11_u5 = 255U;
      }

      c11_bitkm1 = (uint8_T)c11_u5;
      c11_nextbit = (uint32_T)((real_T)(c11_ak & 1U << (uint8_T)
        _SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)(uint8_T)_SFD_INTEGER_CHECK("",
                                  (real_T)c11_bitkm1), 0, 31, 1, 1)) != 0.0);
      _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 19);
      c11_c_a = c11_remainderPolynomial;
      c11_b_ak = c11_c_a;
      c11_c = (uint32_T)((real_T)(c11_b_ak & 2147483648U) != 0.0);
      if (CV_SCRIPT_IF(0, 0, c11_c != 0U)) {
        _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 20);
        c11_d_a = c11_remainderPolynomial;
        c11_a1 = c11_d_a;
        c11_e_a = c11_a1;
        c11_b_c = c11_e_a << 1U;
        c11_u6 = (uint64_T)c11_b_c + (uint64_T)c11_nextbit;
        if (CV_SATURATION_EVAL(14, 0, 7, 0, c11_u6 > 4294967295ULL)) {
          c11_u6 = 4294967295ULL;
        }

        c11_b_varargin_1 = (uint32_T)c11_u6;
        c11_f_a = c11_b_varargin_1;
        c11_remainderPolynomial = c11_f_a ^ 79764919U;
      } else {
        _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 22);
        c11_g_a = c11_remainderPolynomial;
        c11_b_a1 = c11_g_a;
        c11_h_a = c11_b_a1;
        c11_c_c = c11_h_a << 1U;
        c11_u7 = (uint64_T)c11_c_c + (uint64_T)c11_nextbit;
        if (CV_SATURATION_EVAL(14, 0, 8, 0, c11_u7 > 4294967295ULL)) {
          c11_u7 = 4294967295ULL;
        }

        c11_remainderPolynomial = (uint32_T)c11_u7;
      }

      c11_b_l++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_SCRIPT_FOR(0, 1, 0);
    c11_b_k++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(0, 0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 28);
  c11_c_varargin_1 = c11_remainderPolynomial;
  c11_varargin_2 = c11_receivedCRC;
  c11_i_a = c11_c_varargin_1;
  c11_b = c11_varargin_2;
  c11_d_c = c11_i_a ^ c11_b;
  c11_valid = !(c11_d_c != 0U);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -28);
  _SFD_SYMBOL_SCOPE_POP();
  return c11_valid;
}

static void c11_parseUint32(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, uint32_T c11_D[36], uint32_T c11_U[9])
{
  uint32_T c11_debug_family_var_map[6];
  uint32_T c11_Utmp1[36];
  uint32_T c11_Utmp2[9];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i24;
  uint32_T c11_x[36];
  int32_T c11_k;
  int32_T c11_b_k;
  int32_T c11_i25;
  int32_T c11_i26;
  uint32_T c11_b[9];
  int32_T c11_i27;
  uint32_T c11_u8;
  uint32_T c11_u9;
  int32_T c11_i28;
  int32_T c11_i29;
  uint32_T c11_b_b[9];
  int32_T c11_i30;
  uint32_T c11_u10;
  uint32_T c11_u11;
  int32_T c11_i31;
  int32_T c11_i32;
  uint32_T c11_c_b[9];
  int32_T c11_i33;
  uint32_T c11_u12;
  uint32_T c11_u13;
  int32_T c11_i34;
  int32_T c11_i35;
  uint64_T c11_u14;
  uint64_T c11_u15;
  uint64_T c11_u16;
  int32_T c11_i36;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c11_b_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_Utmp1, 0U, c11_i_sf_marshallOut,
    c11_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_Utmp2, 1U, c11_h_sf_marshallOut,
    c11_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 2U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_D, 4U, c11_e_sf_marshallOut,
    c11_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_U, 5U, c11_g_sf_marshallOut,
    c11_f_sf_marshallIn);
  CV_SCRIPT_FCN(0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 32);
  for (c11_i24 = 0; c11_i24 < 36; c11_i24++) {
    c11_x[c11_i24] = c11_D[c11_i24];
  }

  c11_intmin(chartInstance);
  for (c11_k = 1; c11_k < 37; c11_k++) {
    c11_b_k = c11_k;
    c11_Utmp1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c11_b_k), 1, 36, 1, 0) - 1] = c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c11_b_k), 1, 36, 1, 0) - 1];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 33);
  c11_i25 = 0;
  for (c11_i26 = 0; c11_i26 < 9; c11_i26++) {
    c11_b[c11_i26] = c11_Utmp1[c11_i25];
    c11_i25 += 4;
  }

  for (c11_i27 = 0; c11_i27 < 9; c11_i27++) {
    c11_u8 = c11_b[c11_i27];
    if (CV_SATURATION_EVAL(14, 0, 0, 0, c11_u8 > 255U)) {
      c11_u9 = MAX_uint32_T;
    } else {
      c11_u9 = c11_u8 << 24;
    }

    c11_b[c11_i27] = c11_u9;
  }

  c11_i28 = 0;
  for (c11_i29 = 0; c11_i29 < 9; c11_i29++) {
    c11_b_b[c11_i29] = c11_Utmp1[c11_i28 + 1];
    c11_i28 += 4;
  }

  for (c11_i30 = 0; c11_i30 < 9; c11_i30++) {
    c11_u10 = c11_b_b[c11_i30];
    if (CV_SATURATION_EVAL(14, 0, 4, 0, c11_u10 > 65535U)) {
      c11_u11 = MAX_uint32_T;
    } else {
      c11_u11 = c11_u10 << 16;
    }

    c11_b_b[c11_i30] = c11_u11;
  }

  c11_i31 = 0;
  for (c11_i32 = 0; c11_i32 < 9; c11_i32++) {
    c11_c_b[c11_i32] = c11_Utmp1[c11_i31 + 2];
    c11_i31 += 4;
  }

  for (c11_i33 = 0; c11_i33 < 9; c11_i33++) {
    c11_u12 = c11_c_b[c11_i33];
    if (CV_SATURATION_EVAL(14, 0, 5, 0, c11_u12 > 16777215U)) {
      c11_u13 = MAX_uint32_T;
    } else {
      c11_u13 = c11_u12 << 8;
    }

    c11_c_b[c11_i33] = c11_u13;
  }

  c11_i34 = 0;
  for (c11_i35 = 0; c11_i35 < 9; c11_i35++) {
    c11_u14 = (uint64_T)c11_b[c11_i35] + (uint64_T)c11_b_b[c11_i35];
    if (CV_SATURATION_EVAL(14, 0, 1, 0, c11_u14 > 4294967295ULL)) {
      c11_u14 = 4294967295ULL;
    }

    c11_u15 = (uint64_T)(uint32_T)c11_u14 + (uint64_T)c11_c_b[c11_i35];
    if (CV_SATURATION_EVAL(14, 0, 2, 0, c11_u15 > 4294967295ULL)) {
      c11_u15 = 4294967295ULL;
    }

    c11_u16 = (uint64_T)(uint32_T)c11_u15 + (uint64_T)c11_Utmp1[c11_i34 + 3];
    if (CV_SATURATION_EVAL(14, 0, 3, 0, c11_u16 > 4294967295ULL)) {
      c11_u16 = 4294967295ULL;
    }

    c11_Utmp2[c11_i35] = (uint32_T)c11_u16;
    c11_i34 += 4;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, 34);
  for (c11_i36 = 0; c11_i36 < 9; c11_i36++) {
    c11_U[c11_i36] = c11_Utmp2[c11_i36];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c11_sfEvent, -34);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c11_machineNumber, uint32_T
  c11_chartNumber, uint32_T c11_instanceNumber)
{
  (void)c11_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c11_chartNumber, c11_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\DAQ_withElmos\\utils\\kvhCheckCRC.m"));
}

static const mxArray *c11_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  boolean_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(boolean_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static boolean_T c11_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_b_Valid, const char_T *c11_identifier)
{
  boolean_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_Valid),
    &c11_thisId);
  sf_mex_destroy(&c11_b_Valid);
  return c11_y;
}

static boolean_T c11_b_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct *
  chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  boolean_T c11_y;
  boolean_T c11_b0;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_b0, 1, 11, 0U, 0, 0U, 0);
  c11_y = c11_b0;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_Valid;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  boolean_T c11_y;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_b_Valid = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_Valid),
    &c11_thisId);
  sf_mex_destroy(&c11_b_Valid);
  *(boolean_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_b_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  real_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(real_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static real_T c11_c_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_b_Temperature, const char_T *c11_identifier)
{
  real_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_Temperature),
    &c11_thisId);
  sf_mex_destroy(&c11_b_Temperature);
  return c11_y;
}

static real_T c11_d_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
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

static void c11_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_Temperature;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_b_Temperature = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_Temperature),
    &c11_thisId);
  sf_mex_destroy(&c11_b_Temperature);
  *(real_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_c_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  uint32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(uint32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static uint32_T c11_e_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_b_Status, const char_T *c11_identifier)
{
  uint32_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_Status),
    &c11_thisId);
  sf_mex_destroy(&c11_b_Status);
  return c11_y;
}

static uint32_T c11_f_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint32_T c11_y;
  uint32_T c11_u17;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u17, 1, 7, 0U, 0, 0U, 0);
  c11_y = c11_u17;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_Status;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint32_T c11_y;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_b_Status = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_Status),
    &c11_thisId);
  sf_mex_destroy(&c11_b_Status);
  *(uint32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_d_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i37;
  real_T c11_b_inData[3];
  int32_T c11_i38;
  real_T c11_u[3];
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i37 = 0; c11_i37 < 3; c11_i37++) {
    c11_b_inData[c11_i37] = (*(real_T (*)[3])c11_inData)[c11_i37];
  }

  for (c11_i38 = 0; c11_i38 < 3; c11_i38++) {
    c11_u[c11_i38] = c11_b_inData[c11_i38];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_g_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_b_Acceleration, const char_T
  *c11_identifier, real_T c11_y[3])
{
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_Acceleration),
    &c11_thisId, c11_y);
  sf_mex_destroy(&c11_b_Acceleration);
}

static void c11_h_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[3])
{
  real_T c11_dv5[3];
  int32_T c11_i39;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv5, 1, 0, 0U, 1, 0U, 1, 3);
  for (c11_i39 = 0; c11_i39 < 3; c11_i39++) {
    c11_y[c11_i39] = c11_dv5[c11_i39];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_Acceleration;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[3];
  int32_T c11_i40;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_b_Acceleration = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_Acceleration),
    &c11_thisId, c11_y);
  sf_mex_destroy(&c11_b_Acceleration);
  for (c11_i40 = 0; c11_i40 < 3; c11_i40++) {
    (*(real_T (*)[3])c11_outData)[c11_i40] = c11_y[c11_i40];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_e_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i41;
  uint32_T c11_b_inData[36];
  int32_T c11_i42;
  uint32_T c11_u[36];
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i41 = 0; c11_i41 < 36; c11_i41++) {
    c11_b_inData[c11_i41] = (*(uint32_T (*)[36])c11_inData)[c11_i41];
  }

  for (c11_i42 = 0; c11_i42 < 36; c11_i42++) {
    c11_u[c11_i42] = c11_b_inData[c11_i42];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 7, 0U, 1U, 0U, 1, 36), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static const mxArray *c11_f_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i43;
  real_T c11_b_inData[4];
  int32_T c11_i44;
  real_T c11_u[4];
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i43 = 0; c11_i43 < 4; c11_i43++) {
    c11_b_inData[c11_i43] = (*(real_T (*)[4])c11_inData)[c11_i43];
  }

  for (c11_i44 = 0; c11_i44 < 4; c11_i44++) {
    c11_u[c11_i44] = c11_b_inData[c11_i44];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_i_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real_T c11_y[4])
{
  real_T c11_dv6[4];
  int32_T c11_i45;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_dv6, 1, 0, 0U, 1, 0U, 1, 4);
  for (c11_i45 = 0; c11_i45 < 4; c11_i45++) {
    c11_y[c11_i45] = c11_dv6[c11_i45];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_CMD;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real_T c11_y[4];
  int32_T c11_i46;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_CMD = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_CMD), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_CMD);
  for (c11_i46 = 0; c11_i46 < 4; c11_i46++) {
    (*(real_T (*)[4])c11_outData)[c11_i46] = c11_y[c11_i46];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_g_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i47;
  uint32_T c11_b_inData[9];
  int32_T c11_i48;
  uint32_T c11_u[9];
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i47 = 0; c11_i47 < 9; c11_i47++) {
    c11_b_inData[c11_i47] = (*(uint32_T (*)[9])c11_inData)[c11_i47];
  }

  for (c11_i48 = 0; c11_i48 < 9; c11_i48++) {
    c11_u[c11_i48] = c11_b_inData[c11_i48];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 7, 0U, 1U, 0U, 1, 9), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_j_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[9])
{
  uint32_T c11_uv1[9];
  int32_T c11_i49;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_uv1, 1, 7, 0U, 1, 0U, 1, 9);
  for (c11_i49 = 0; c11_i49 < 9; c11_i49++) {
    c11_y[c11_i49] = c11_uv1[c11_i49];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_U;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint32_T c11_y[9];
  int32_T c11_i50;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_U = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_U), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_U);
  for (c11_i50 = 0; c11_i50 < 9; c11_i50++) {
    (*(uint32_T (*)[9])c11_outData)[c11_i50] = c11_y[c11_i50];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static void c11_k_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[36])
{
  uint32_T c11_uv2[36];
  int32_T c11_i51;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_uv2, 1, 7, 0U, 1, 0U, 1, 36);
  for (c11_i51 = 0; c11_i51 < 36; c11_i51++) {
    c11_y[c11_i51] = c11_uv2[c11_i51];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_D;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint32_T c11_y[36];
  int32_T c11_i52;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_D = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_D), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_D);
  for (c11_i52 = 0; c11_i52 < 36; c11_i52++) {
    (*(uint32_T (*)[36])c11_outData)[c11_i52] = c11_y[c11_i52];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_h_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i53;
  uint32_T c11_b_inData[9];
  int32_T c11_i54;
  uint32_T c11_u[9];
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i53 = 0; c11_i53 < 9; c11_i53++) {
    c11_b_inData[c11_i53] = (*(uint32_T (*)[9])c11_inData)[c11_i53];
  }

  for (c11_i54 = 0; c11_i54 < 9; c11_i54++) {
    c11_u[c11_i54] = c11_b_inData[c11_i54];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 7, 0U, 1U, 0U, 2, 1, 9), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_l_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[9])
{
  uint32_T c11_uv3[9];
  int32_T c11_i55;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_uv3, 1, 7, 0U, 1, 0U, 2, 1,
                9);
  for (c11_i55 = 0; c11_i55 < 9; c11_i55++) {
    c11_y[c11_i55] = c11_uv3[c11_i55];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_Utmp2;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint32_T c11_y[9];
  int32_T c11_i56;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_Utmp2 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_Utmp2), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_Utmp2);
  for (c11_i56 = 0; c11_i56 < 9; c11_i56++) {
    (*(uint32_T (*)[9])c11_outData)[c11_i56] = c11_y[c11_i56];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_i_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i57;
  int32_T c11_i58;
  int32_T c11_i59;
  uint32_T c11_b_inData[36];
  int32_T c11_i60;
  int32_T c11_i61;
  int32_T c11_i62;
  uint32_T c11_u[36];
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i57 = 0;
  for (c11_i58 = 0; c11_i58 < 9; c11_i58++) {
    for (c11_i59 = 0; c11_i59 < 4; c11_i59++) {
      c11_b_inData[c11_i59 + c11_i57] = (*(uint32_T (*)[36])c11_inData)[c11_i59
        + c11_i57];
    }

    c11_i57 += 4;
  }

  c11_i60 = 0;
  for (c11_i61 = 0; c11_i61 < 9; c11_i61++) {
    for (c11_i62 = 0; c11_i62 < 4; c11_i62++) {
      c11_u[c11_i62 + c11_i60] = c11_b_inData[c11_i62 + c11_i60];
    }

    c11_i60 += 4;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 7, 0U, 1U, 0U, 2, 4, 9), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_m_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[36])
{
  uint32_T c11_uv4[36];
  int32_T c11_i63;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_uv4, 1, 7, 0U, 1, 0U, 2, 4,
                9);
  for (c11_i63 = 0; c11_i63 < 36; c11_i63++) {
    c11_y[c11_i63] = c11_uv4[c11_i63];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_Utmp1;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint32_T c11_y[36];
  int32_T c11_i64;
  int32_T c11_i65;
  int32_T c11_i66;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_Utmp1 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_Utmp1), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_Utmp1);
  c11_i64 = 0;
  for (c11_i65 = 0; c11_i65 < 9; c11_i65++) {
    for (c11_i66 = 0; c11_i66 < 4; c11_i66++) {
      (*(uint32_T (*)[36])c11_outData)[c11_i66 + c11_i64] = c11_y[c11_i66 +
        c11_i64];
    }

    c11_i64 += 4;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_j_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i67;
  uint32_T c11_b_inData[12];
  int32_T c11_i68;
  uint32_T c11_u[12];
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i67 = 0; c11_i67 < 12; c11_i67++) {
    c11_b_inData[c11_i67] = (*(uint32_T (*)[12])c11_inData)[c11_i67];
  }

  for (c11_i68 = 0; c11_i68 < 12; c11_i68++) {
    c11_u[c11_i68] = c11_b_inData[c11_i68];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 7, 0U, 1U, 0U, 1, 12), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_n_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[12])
{
  uint32_T c11_uv5[12];
  int32_T c11_i69;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_uv5, 1, 7, 0U, 1, 0U, 1, 12);
  for (c11_i69 = 0; c11_i69 < 12; c11_i69++) {
    c11_y[c11_i69] = c11_uv5[c11_i69];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_D;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint32_T c11_y[12];
  int32_T c11_i70;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_D = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_D), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_D);
  for (c11_i70 = 0; c11_i70 < 12; c11_i70++) {
    (*(uint32_T (*)[12])c11_outData)[c11_i70] = c11_y[c11_i70];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_k_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i71;
  real32_T c11_b_inData[3];
  int32_T c11_i72;
  real32_T c11_u[3];
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i71 = 0; c11_i71 < 3; c11_i71++) {
    c11_b_inData[c11_i71] = (*(real32_T (*)[3])c11_inData)[c11_i71];
  }

  for (c11_i72 = 0; c11_i72 < 3; c11_i72++) {
    c11_u[c11_i72] = c11_b_inData[c11_i72];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 1, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_o_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  real32_T c11_y[3])
{
  real32_T c11_fv0[3];
  int32_T c11_i73;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_fv0, 1, 1, 0U, 1, 0U, 2, 1,
                3);
  for (c11_i73 = 0; c11_i73 < 3; c11_i73++) {
    c11_y[c11_i73] = c11_fv0[c11_i73];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_Stmp3;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  real32_T c11_y[3];
  int32_T c11_i74;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_Stmp3 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_Stmp3), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_Stmp3);
  for (c11_i74 = 0; c11_i74 < 3; c11_i74++) {
    (*(real32_T (*)[3])c11_outData)[c11_i74] = c11_y[c11_i74];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_l_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i75;
  uint32_T c11_b_inData[3];
  int32_T c11_i76;
  uint32_T c11_u[3];
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i75 = 0; c11_i75 < 3; c11_i75++) {
    c11_b_inData[c11_i75] = (*(uint32_T (*)[3])c11_inData)[c11_i75];
  }

  for (c11_i76 = 0; c11_i76 < 3; c11_i76++) {
    c11_u[c11_i76] = c11_b_inData[c11_i76];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 7, 0U, 1U, 0U, 2, 1, 3), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_p_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[3])
{
  uint32_T c11_uv6[3];
  int32_T c11_i77;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_uv6, 1, 7, 0U, 1, 0U, 2, 1,
                3);
  for (c11_i77 = 0; c11_i77 < 3; c11_i77++) {
    c11_y[c11_i77] = c11_uv6[c11_i77];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_Stmp2;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint32_T c11_y[3];
  int32_T c11_i78;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_Stmp2 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_p_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_Stmp2), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_Stmp2);
  for (c11_i78 = 0; c11_i78 < 3; c11_i78++) {
    (*(uint32_T (*)[3])c11_outData)[c11_i78] = c11_y[c11_i78];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_m_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i79;
  int32_T c11_i80;
  int32_T c11_i81;
  uint32_T c11_b_inData[12];
  int32_T c11_i82;
  int32_T c11_i83;
  int32_T c11_i84;
  uint32_T c11_u[12];
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_i79 = 0;
  for (c11_i80 = 0; c11_i80 < 3; c11_i80++) {
    for (c11_i81 = 0; c11_i81 < 4; c11_i81++) {
      c11_b_inData[c11_i81 + c11_i79] = (*(uint32_T (*)[12])c11_inData)[c11_i81
        + c11_i79];
    }

    c11_i79 += 4;
  }

  c11_i82 = 0;
  for (c11_i83 = 0; c11_i83 < 3; c11_i83++) {
    for (c11_i84 = 0; c11_i84 < 4; c11_i84++) {
      c11_u[c11_i84 + c11_i82] = c11_b_inData[c11_i84 + c11_i82];
    }

    c11_i82 += 4;
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 7, 0U, 1U, 0U, 2, 4, 3), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_q_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[12])
{
  uint32_T c11_uv7[12];
  int32_T c11_i85;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_uv7, 1, 7, 0U, 1, 0U, 2, 4,
                3);
  for (c11_i85 = 0; c11_i85 < 12; c11_i85++) {
    c11_y[c11_i85] = c11_uv7[c11_i85];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_Stmp1;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint32_T c11_y[12];
  int32_T c11_i86;
  int32_T c11_i87;
  int32_T c11_i88;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_Stmp1 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_Stmp1), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_Stmp1);
  c11_i86 = 0;
  for (c11_i87 = 0; c11_i87 < 3; c11_i87++) {
    for (c11_i88 = 0; c11_i88 < 4; c11_i88++) {
      (*(uint32_T (*)[12])c11_outData)[c11_i88 + c11_i86] = c11_y[c11_i88 +
        c11_i86];
    }

    c11_i86 += 4;
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_n_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i89;
  uint32_T c11_b_inData[2];
  int32_T c11_i90;
  uint32_T c11_u[2];
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i89 = 0; c11_i89 < 2; c11_i89++) {
    c11_b_inData[c11_i89] = (*(uint32_T (*)[2])c11_inData)[c11_i89];
  }

  for (c11_i90 = 0; c11_i90 < 2; c11_i90++) {
    c11_u[c11_i90] = c11_b_inData[c11_i90];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 7, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_r_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint32_T c11_y[2])
{
  uint32_T c11_uv8[2];
  int32_T c11_i91;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_uv8, 1, 7, 0U, 1, 0U, 1, 2);
  for (c11_i91 = 0; c11_i91 < 2; c11_i91++) {
    c11_y[c11_i91] = c11_uv8[c11_i91];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_D;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint32_T c11_y[2];
  int32_T c11_i92;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_D = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_r_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_D), &c11_thisId, c11_y);
  sf_mex_destroy(&c11_D);
  for (c11_i92 = 0; c11_i92 < 2; c11_i92++) {
    (*(uint32_T (*)[2])c11_outData)[c11_i92] = c11_y[c11_i92];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_o_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  uint16_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(uint16_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 5, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static uint16_T c11_s_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint16_T c11_y;
  uint16_T c11_u18;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u18, 1, 5, 0U, 0, 0U, 0);
  c11_y = c11_u18;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_Stmp2;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint16_T c11_y;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_Stmp2 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_Stmp2),
    &c11_thisId);
  sf_mex_destroy(&c11_Stmp2);
  *(uint16_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static const mxArray *c11_p_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_i93;
  uint16_T c11_b_inData[2];
  int32_T c11_i94;
  uint16_T c11_u[2];
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  for (c11_i93 = 0; c11_i93 < 2; c11_i93++) {
    c11_b_inData[c11_i93] = (*(uint16_T (*)[2])c11_inData)[c11_i93];
  }

  for (c11_i94 = 0; c11_i94 < 2; c11_i94++) {
    c11_u[c11_i94] = c11_b_inData[c11_i94];
  }

  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", c11_u, 5, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static void c11_t_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId,
  uint16_T c11_y[2])
{
  uint16_T c11_uv9[2];
  int32_T c11_i95;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), c11_uv9, 1, 5, 0U, 1, 0U, 1, 2);
  for (c11_i95 = 0; c11_i95 < 2; c11_i95++) {
    c11_y[c11_i95] = c11_uv9[c11_i95];
  }

  sf_mex_destroy(&c11_u);
}

static void c11_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_Stmp1;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  uint16_T c11_y[2];
  int32_T c11_i96;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_Stmp1 = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_t_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_Stmp1), &c11_thisId,
    c11_y);
  sf_mex_destroy(&c11_Stmp1);
  for (c11_i96 = 0; c11_i96 < 2; c11_i96++) {
    (*(uint16_T (*)[2])c11_outData)[c11_i96] = c11_y[c11_i96];
  }

  sf_mex_destroy(&c11_mxArrayInData);
}

const mxArray *sf_c11_Walking01_withElmos_get_eml_resolved_functions_info(void)
{
  const mxArray *c11_nameCaptureInfo = NULL;
  c11_nameCaptureInfo = NULL;
  sf_mex_assign(&c11_nameCaptureInfo, sf_mex_createstruct("structure", 2, 118, 1),
                false);
  c11_info_helper(&c11_nameCaptureInfo);
  c11_b_info_helper(&c11_nameCaptureInfo);
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
  const mxArray *c11_rhs25 = NULL;
  const mxArray *c11_lhs25 = NULL;
  const mxArray *c11_rhs26 = NULL;
  const mxArray *c11_lhs26 = NULL;
  const mxArray *c11_rhs27 = NULL;
  const mxArray *c11_lhs27 = NULL;
  const mxArray *c11_rhs28 = NULL;
  const mxArray *c11_lhs28 = NULL;
  const mxArray *c11_rhs29 = NULL;
  const mxArray *c11_lhs29 = NULL;
  const mxArray *c11_rhs30 = NULL;
  const mxArray *c11_lhs30 = NULL;
  const mxArray *c11_rhs31 = NULL;
  const mxArray *c11_lhs31 = NULL;
  const mxArray *c11_rhs32 = NULL;
  const mxArray *c11_lhs32 = NULL;
  const mxArray *c11_rhs33 = NULL;
  const mxArray *c11_lhs33 = NULL;
  const mxArray *c11_rhs34 = NULL;
  const mxArray *c11_lhs34 = NULL;
  const mxArray *c11_rhs35 = NULL;
  const mxArray *c11_lhs35 = NULL;
  const mxArray *c11_rhs36 = NULL;
  const mxArray *c11_lhs36 = NULL;
  const mxArray *c11_rhs37 = NULL;
  const mxArray *c11_lhs37 = NULL;
  const mxArray *c11_rhs38 = NULL;
  const mxArray *c11_lhs38 = NULL;
  const mxArray *c11_rhs39 = NULL;
  const mxArray *c11_lhs39 = NULL;
  const mxArray *c11_rhs40 = NULL;
  const mxArray *c11_lhs40 = NULL;
  const mxArray *c11_rhs41 = NULL;
  const mxArray *c11_lhs41 = NULL;
  const mxArray *c11_rhs42 = NULL;
  const mxArray *c11_lhs42 = NULL;
  const mxArray *c11_rhs43 = NULL;
  const mxArray *c11_lhs43 = NULL;
  const mxArray *c11_rhs44 = NULL;
  const mxArray *c11_lhs44 = NULL;
  const mxArray *c11_rhs45 = NULL;
  const mxArray *c11_lhs45 = NULL;
  const mxArray *c11_rhs46 = NULL;
  const mxArray *c11_lhs46 = NULL;
  const mxArray *c11_rhs47 = NULL;
  const mxArray *c11_lhs47 = NULL;
  const mxArray *c11_rhs48 = NULL;
  const mxArray *c11_lhs48 = NULL;
  const mxArray *c11_rhs49 = NULL;
  const mxArray *c11_lhs49 = NULL;
  const mxArray *c11_rhs50 = NULL;
  const mxArray *c11_lhs50 = NULL;
  const mxArray *c11_rhs51 = NULL;
  const mxArray *c11_lhs51 = NULL;
  const mxArray *c11_rhs52 = NULL;
  const mxArray *c11_lhs52 = NULL;
  const mxArray *c11_rhs53 = NULL;
  const mxArray *c11_lhs53 = NULL;
  const mxArray *c11_rhs54 = NULL;
  const mxArray *c11_lhs54 = NULL;
  const mxArray *c11_rhs55 = NULL;
  const mxArray *c11_lhs55 = NULL;
  const mxArray *c11_rhs56 = NULL;
  const mxArray *c11_lhs56 = NULL;
  const mxArray *c11_rhs57 = NULL;
  const mxArray *c11_lhs57 = NULL;
  const mxArray *c11_rhs58 = NULL;
  const mxArray *c11_lhs58 = NULL;
  const mxArray *c11_rhs59 = NULL;
  const mxArray *c11_lhs59 = NULL;
  const mxArray *c11_rhs60 = NULL;
  const mxArray *c11_lhs60 = NULL;
  const mxArray *c11_rhs61 = NULL;
  const mxArray *c11_lhs61 = NULL;
  const mxArray *c11_rhs62 = NULL;
  const mxArray *c11_lhs62 = NULL;
  const mxArray *c11_rhs63 = NULL;
  const mxArray *c11_lhs63 = NULL;
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("all"), "name", "name", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604014U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/all.m"), "context", "context",
                  3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.allOrAny"),
                  "name", "name", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604758U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
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
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isequal"), "name", "name", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286840358U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
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
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("kvhCheckCRC"), "name",
                  "name", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/utils/kvhCheckCRC.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1432837203U), "fileTimeLo",
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
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/utils/kvhCheckCRC.m!parseUint32"),
                  "context", "context", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("reshape"), "name", "name", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1378317582U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size"),
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!varargin_nempty"),
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!varargin_nempty"),
                  "context", "context", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isfi"), "name", "name", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 14);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 14);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
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
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmin"), "name", "name", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!varargin_nempty"),
                  "context", "context", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!computeDimsData"),
                  "context", "context", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!computeDimsData"),
                  "context", "context", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!computeDimsData"),
                  "context", "context", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1368204630U), "fileTimeLo",
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
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c11_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isinf"), "name", "name", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c11_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c11_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_is_integer_class"),
                  "name", "name", 28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c11_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c11_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmin"), "name", "name", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c11_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1326749922U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c11_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c11_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c11_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmin"), "name", "name", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c11_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c11_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c11_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!computeDimsData"),
                  "context", "context", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c11_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!computeDimsData"),
                  "context", "context", 38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_rdivide"), "name",
                  "name", 38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "resolved", "resolved", 38);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c11_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexDivide"),
                  "name", "name", 39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexDivide.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c11_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m!reshape_varargin_to_size"),
                  "context", "context", 40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c11_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 41);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c11_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c11_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c11_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/utils/kvhCheckCRC.m!parseUint32"),
                  "context", "context", 44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c11_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c11_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c11_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/utils/kvhCheckCRC.m"),
                  "context", "context", 47);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("bitxor"), "name", "name", 47);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitxor.m"), "resolved",
                  "resolved", 47);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c11_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitxor.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 48);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c11_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitxor.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("bitbinop"), "name", "name",
                  49);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 49);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/ops/private/bitbinop.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1383898890U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c11_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/ops/private/bitbinop.m"),
                  "context", "context", 50);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 50);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c11_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/ops/private/bitbinop.m"),
                  "context", "context", 51);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 51);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c11_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/utils/kvhCheckCRC.m"),
                  "context", "context", 52);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("bitget"), "name", "name", 52);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitget.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1383898890U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c11_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitget.m"), "context",
                  "context", 53);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 53);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c11_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitget.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 54);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c11_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitget.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 55);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c11_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 56);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 56);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c11_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitget.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_int_nbits"), "name",
                  "name", 57);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c11_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 58);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c11_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitget.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("all_in_integer_range"),
                  "name", "name", 59);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/ops/private/all_in_integer_range.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1383898888U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c11_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/ops/private/all_in_integer_range.m"),
                  "context", "context", 60);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.indexIntRelop"), "name", "name", 60);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1326749922U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c11_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/ops/private/all_in_integer_range.m"),
                  "context", "context", 61);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("floor"), "name", "name", 61);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 61);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c11_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 62);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 62);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c11_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 63);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 63);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c11_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs63), "lhs", "lhs",
                  63);
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
  sf_mex_destroy(&c11_rhs25);
  sf_mex_destroy(&c11_lhs25);
  sf_mex_destroy(&c11_rhs26);
  sf_mex_destroy(&c11_lhs26);
  sf_mex_destroy(&c11_rhs27);
  sf_mex_destroy(&c11_lhs27);
  sf_mex_destroy(&c11_rhs28);
  sf_mex_destroy(&c11_lhs28);
  sf_mex_destroy(&c11_rhs29);
  sf_mex_destroy(&c11_lhs29);
  sf_mex_destroy(&c11_rhs30);
  sf_mex_destroy(&c11_lhs30);
  sf_mex_destroy(&c11_rhs31);
  sf_mex_destroy(&c11_lhs31);
  sf_mex_destroy(&c11_rhs32);
  sf_mex_destroy(&c11_lhs32);
  sf_mex_destroy(&c11_rhs33);
  sf_mex_destroy(&c11_lhs33);
  sf_mex_destroy(&c11_rhs34);
  sf_mex_destroy(&c11_lhs34);
  sf_mex_destroy(&c11_rhs35);
  sf_mex_destroy(&c11_lhs35);
  sf_mex_destroy(&c11_rhs36);
  sf_mex_destroy(&c11_lhs36);
  sf_mex_destroy(&c11_rhs37);
  sf_mex_destroy(&c11_lhs37);
  sf_mex_destroy(&c11_rhs38);
  sf_mex_destroy(&c11_lhs38);
  sf_mex_destroy(&c11_rhs39);
  sf_mex_destroy(&c11_lhs39);
  sf_mex_destroy(&c11_rhs40);
  sf_mex_destroy(&c11_lhs40);
  sf_mex_destroy(&c11_rhs41);
  sf_mex_destroy(&c11_lhs41);
  sf_mex_destroy(&c11_rhs42);
  sf_mex_destroy(&c11_lhs42);
  sf_mex_destroy(&c11_rhs43);
  sf_mex_destroy(&c11_lhs43);
  sf_mex_destroy(&c11_rhs44);
  sf_mex_destroy(&c11_lhs44);
  sf_mex_destroy(&c11_rhs45);
  sf_mex_destroy(&c11_lhs45);
  sf_mex_destroy(&c11_rhs46);
  sf_mex_destroy(&c11_lhs46);
  sf_mex_destroy(&c11_rhs47);
  sf_mex_destroy(&c11_lhs47);
  sf_mex_destroy(&c11_rhs48);
  sf_mex_destroy(&c11_lhs48);
  sf_mex_destroy(&c11_rhs49);
  sf_mex_destroy(&c11_lhs49);
  sf_mex_destroy(&c11_rhs50);
  sf_mex_destroy(&c11_lhs50);
  sf_mex_destroy(&c11_rhs51);
  sf_mex_destroy(&c11_lhs51);
  sf_mex_destroy(&c11_rhs52);
  sf_mex_destroy(&c11_lhs52);
  sf_mex_destroy(&c11_rhs53);
  sf_mex_destroy(&c11_lhs53);
  sf_mex_destroy(&c11_rhs54);
  sf_mex_destroy(&c11_lhs54);
  sf_mex_destroy(&c11_rhs55);
  sf_mex_destroy(&c11_lhs55);
  sf_mex_destroy(&c11_rhs56);
  sf_mex_destroy(&c11_lhs56);
  sf_mex_destroy(&c11_rhs57);
  sf_mex_destroy(&c11_lhs57);
  sf_mex_destroy(&c11_rhs58);
  sf_mex_destroy(&c11_lhs58);
  sf_mex_destroy(&c11_rhs59);
  sf_mex_destroy(&c11_lhs59);
  sf_mex_destroy(&c11_rhs60);
  sf_mex_destroy(&c11_lhs60);
  sf_mex_destroy(&c11_rhs61);
  sf_mex_destroy(&c11_lhs61);
  sf_mex_destroy(&c11_rhs62);
  sf_mex_destroy(&c11_lhs62);
  sf_mex_destroy(&c11_rhs63);
  sf_mex_destroy(&c11_lhs63);
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

static void c11_b_info_helper(const mxArray **c11_info)
{
  const mxArray *c11_rhs64 = NULL;
  const mxArray *c11_lhs64 = NULL;
  const mxArray *c11_rhs65 = NULL;
  const mxArray *c11_lhs65 = NULL;
  const mxArray *c11_rhs66 = NULL;
  const mxArray *c11_lhs66 = NULL;
  const mxArray *c11_rhs67 = NULL;
  const mxArray *c11_lhs67 = NULL;
  const mxArray *c11_rhs68 = NULL;
  const mxArray *c11_lhs68 = NULL;
  const mxArray *c11_rhs69 = NULL;
  const mxArray *c11_lhs69 = NULL;
  const mxArray *c11_rhs70 = NULL;
  const mxArray *c11_lhs70 = NULL;
  const mxArray *c11_rhs71 = NULL;
  const mxArray *c11_lhs71 = NULL;
  const mxArray *c11_rhs72 = NULL;
  const mxArray *c11_lhs72 = NULL;
  const mxArray *c11_rhs73 = NULL;
  const mxArray *c11_lhs73 = NULL;
  const mxArray *c11_rhs74 = NULL;
  const mxArray *c11_lhs74 = NULL;
  const mxArray *c11_rhs75 = NULL;
  const mxArray *c11_lhs75 = NULL;
  const mxArray *c11_rhs76 = NULL;
  const mxArray *c11_lhs76 = NULL;
  const mxArray *c11_rhs77 = NULL;
  const mxArray *c11_lhs77 = NULL;
  const mxArray *c11_rhs78 = NULL;
  const mxArray *c11_lhs78 = NULL;
  const mxArray *c11_rhs79 = NULL;
  const mxArray *c11_lhs79 = NULL;
  const mxArray *c11_rhs80 = NULL;
  const mxArray *c11_lhs80 = NULL;
  const mxArray *c11_rhs81 = NULL;
  const mxArray *c11_lhs81 = NULL;
  const mxArray *c11_rhs82 = NULL;
  const mxArray *c11_lhs82 = NULL;
  const mxArray *c11_rhs83 = NULL;
  const mxArray *c11_lhs83 = NULL;
  const mxArray *c11_rhs84 = NULL;
  const mxArray *c11_lhs84 = NULL;
  const mxArray *c11_rhs85 = NULL;
  const mxArray *c11_lhs85 = NULL;
  const mxArray *c11_rhs86 = NULL;
  const mxArray *c11_lhs86 = NULL;
  const mxArray *c11_rhs87 = NULL;
  const mxArray *c11_lhs87 = NULL;
  const mxArray *c11_rhs88 = NULL;
  const mxArray *c11_lhs88 = NULL;
  const mxArray *c11_rhs89 = NULL;
  const mxArray *c11_lhs89 = NULL;
  const mxArray *c11_rhs90 = NULL;
  const mxArray *c11_lhs90 = NULL;
  const mxArray *c11_rhs91 = NULL;
  const mxArray *c11_lhs91 = NULL;
  const mxArray *c11_rhs92 = NULL;
  const mxArray *c11_lhs92 = NULL;
  const mxArray *c11_rhs93 = NULL;
  const mxArray *c11_lhs93 = NULL;
  const mxArray *c11_rhs94 = NULL;
  const mxArray *c11_lhs94 = NULL;
  const mxArray *c11_rhs95 = NULL;
  const mxArray *c11_lhs95 = NULL;
  const mxArray *c11_rhs96 = NULL;
  const mxArray *c11_lhs96 = NULL;
  const mxArray *c11_rhs97 = NULL;
  const mxArray *c11_lhs97 = NULL;
  const mxArray *c11_rhs98 = NULL;
  const mxArray *c11_lhs98 = NULL;
  const mxArray *c11_rhs99 = NULL;
  const mxArray *c11_lhs99 = NULL;
  const mxArray *c11_rhs100 = NULL;
  const mxArray *c11_lhs100 = NULL;
  const mxArray *c11_rhs101 = NULL;
  const mxArray *c11_lhs101 = NULL;
  const mxArray *c11_rhs102 = NULL;
  const mxArray *c11_lhs102 = NULL;
  const mxArray *c11_rhs103 = NULL;
  const mxArray *c11_lhs103 = NULL;
  const mxArray *c11_rhs104 = NULL;
  const mxArray *c11_lhs104 = NULL;
  const mxArray *c11_rhs105 = NULL;
  const mxArray *c11_lhs105 = NULL;
  const mxArray *c11_rhs106 = NULL;
  const mxArray *c11_lhs106 = NULL;
  const mxArray *c11_rhs107 = NULL;
  const mxArray *c11_lhs107 = NULL;
  const mxArray *c11_rhs108 = NULL;
  const mxArray *c11_lhs108 = NULL;
  const mxArray *c11_rhs109 = NULL;
  const mxArray *c11_lhs109 = NULL;
  const mxArray *c11_rhs110 = NULL;
  const mxArray *c11_lhs110 = NULL;
  const mxArray *c11_rhs111 = NULL;
  const mxArray *c11_lhs111 = NULL;
  const mxArray *c11_rhs112 = NULL;
  const mxArray *c11_lhs112 = NULL;
  const mxArray *c11_rhs113 = NULL;
  const mxArray *c11_lhs113 = NULL;
  const mxArray *c11_rhs114 = NULL;
  const mxArray *c11_lhs114 = NULL;
  const mxArray *c11_rhs115 = NULL;
  const mxArray *c11_lhs115 = NULL;
  const mxArray *c11_rhs116 = NULL;
  const mxArray *c11_lhs116 = NULL;
  const mxArray *c11_rhs117 = NULL;
  const mxArray *c11_lhs117 = NULL;
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitget.m"), "context",
                  "context", 64);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 64);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c11_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/DAQ_withElmos/utils/kvhCheckCRC.m"),
                  "context", "context", 65);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("bitshift"), "name", "name",
                  65);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "resolved",
                  "resolved", 65);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1388216346U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c11_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 66);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 66);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c11_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 67);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 67);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 67);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c11_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 68);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 68);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c11_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!allinteger"),
                  "context", "context", 69);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("floor"), "name", "name", 69);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 69);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c11_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!lshift"),
                  "context", "context", 70);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_int_nbits"), "name",
                  "name", 70);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "resolved",
                  "resolved", 70);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c11_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 71);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("reshape"), "name", "name",
                  71);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/reshape.m"), "resolved",
                  "resolved", 71);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1378317582U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c11_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 72);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 72);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c11_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "context", "context", 73);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("typecast"), "name", "name",
                  73);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m"),
                  "resolved", "resolved", 73);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1407186096U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c11_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m"), "context",
                  "context", 74);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 74);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c11_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m"), "context",
                  "context", 75);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("deblank"), "name", "name",
                  75);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/deblank.m"), "resolved",
                  "resolved", 75);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1331326488U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c11_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/deblank.m"), "context",
                  "context", 76);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("ismatrix"), "name", "name",
                  76);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 76);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1331326458U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c11_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/deblank.m!allwspace"),
                  "context", "context", 77);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("isstrprop"), "name", "name",
                  77);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/isstrprop.m"), "resolved",
                  "resolved", 77);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376002294U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c11_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/isstrprop.m!apply_property_predicate"),
                  "context", "context", 78);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_assert_supported_string"),
                  "name", "name", 78);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c11_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m!inrange"),
                  "context", "context", 79);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 79);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c11_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"), "context",
                  "context", 80);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 80);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 80);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c11_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_assert_supported_string.m"),
                  "context", "context", 81);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 81);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 81);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c11_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/isstrprop.m!apply_property_predicate"),
                  "context", "context", 82);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_charmax"), "name",
                  "name", 82);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/eml_charmax.m"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1327440710U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c11_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/isstrprop.m!apply_property_predicate"),
                  "context", "context", 83);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("colon"), "name", "name", 83);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 83);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c11_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 84);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("colon"), "name", "name", 84);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 84);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c11_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 85);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 85);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 85);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c11_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 86);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 86);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c11_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 87);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("floor"), "name", "name", 87);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 87);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c11_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 88);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmin"), "name", "name", 88);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 88);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c11_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 89);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 89);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 89);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c11_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 90);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmin"), "name", "name", 90);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 90);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c11_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 91);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 91);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 91);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c11_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 92);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 92);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 92);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c11_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 93);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 93);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c11_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 94);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 94);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 94);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c11_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 95);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 95);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 95);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 95);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c11_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 96);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 96);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 96);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 96);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c11_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 97);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 97);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 97);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 97);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c11_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 98);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("intmax"), "name", "name", 98);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 98);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 98);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c11_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 99);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 99);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 99);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 99);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c11_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 100);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 100);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 100);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 100);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c11_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs100), "rhs",
                  "rhs", 100);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs100), "lhs",
                  "lhs", 100);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 101);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 101);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 101);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c11_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs101), "rhs",
                  "rhs", 101);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs101), "lhs",
                  "lhs", 101);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/isstrprop.m!apply_property_predicate"),
                  "context", "context", 102);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "name", "name", 102);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int8"), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/strfun/char.m"), "resolved",
                  "resolved", 102);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1319751568U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c11_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs102), "rhs",
                  "rhs", 102);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs102), "lhs",
                  "lhs", 102);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element"),
                  "context", "context", 103);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 103);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 103);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c11_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs103), "rhs",
                  "rhs", 103);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs103), "lhs",
                  "lhs", 103);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element"),
                  "context", "context", 104);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_int_nbits"), "name",
                  "name", 104);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 104);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "resolved",
                  "resolved", 104);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c11_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs104), "rhs",
                  "rhs", 104);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs104), "lhs",
                  "lhs", 104);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element"),
                  "context", "context", 105);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_rdivide"), "name",
                  "name", 105);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "resolved", "resolved", 105);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c11_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs105), "rhs",
                  "rhs", 105);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs105), "lhs",
                  "lhs", 105);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "context", "context", 106);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexDivide"),
                  "name", "name", 106);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint8"), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexDivide.m"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c11_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs106), "rhs",
                  "rhs", 106);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs106), "lhs",
                  "lhs", 106);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element"),
                  "context", "context", 107);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_float_nbits"), "name",
                  "name", 107);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_nbits.m"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c11_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs107), "rhs",
                  "rhs", 107);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs107), "lhs",
                  "lhs", 107);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_nbits.m"),
                  "context", "context", 108);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 108);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 108);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c11_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs108), "rhs",
                  "rhs", 108);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs108), "lhs",
                  "lhs", 108);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m!bytes_per_element"),
                  "context", "context", 109);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_rdivide"), "name",
                  "name", 109);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "resolved", "resolved", 109);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c11_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs109), "rhs",
                  "rhs", 109);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs109), "lhs",
                  "lhs", 109);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "context", "context", 110);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexDivide"),
                  "name", "name", 110);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexDivide.m"),
                  "resolved", "resolved", 110);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c11_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs110), "rhs",
                  "rhs", 110);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs110), "lhs",
                  "lhs", 110);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m"), "context",
                  "context", 111);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 111);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 111);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c11_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs111), "rhs",
                  "rhs", 111);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs111), "lhs",
                  "lhs", 111);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 112);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 112);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 112);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 112);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c11_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs112), "rhs",
                  "rhs", 112);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs112), "lhs",
                  "lhs", 112);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m"), "context",
                  "context", 113);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_rdivide"), "name",
                  "name", 113);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 113);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "resolved", "resolved", 113);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c11_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs113), "rhs",
                  "rhs", 113);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs113), "lhs",
                  "lhs", 113);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m"), "context",
                  "context", 114);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 114);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 114);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 114);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c11_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs114), "rhs",
                  "rhs", 114);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs114), "lhs",
                  "lhs", 114);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 115);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 115);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 115);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 115);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c11_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs115), "rhs",
                  "rhs", 115);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs115), "lhs",
                  "lhs", 115);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datatypes/typecast.m"), "context",
                  "context", 116);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 116);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("single"), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 116);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c11_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs116), "rhs",
                  "rhs", 116);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs116), "lhs",
                  "lhs", 116);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 117);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 117);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut("uint16"), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c11_info, c11_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 117);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c11_info, c11_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c11_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c11_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_rhs117), "rhs",
                  "rhs", 117);
  sf_mex_addfield(*c11_info, sf_mex_duplicatearraysafe(&c11_lhs117), "lhs",
                  "lhs", 117);
  sf_mex_destroy(&c11_rhs64);
  sf_mex_destroy(&c11_lhs64);
  sf_mex_destroy(&c11_rhs65);
  sf_mex_destroy(&c11_lhs65);
  sf_mex_destroy(&c11_rhs66);
  sf_mex_destroy(&c11_lhs66);
  sf_mex_destroy(&c11_rhs67);
  sf_mex_destroy(&c11_lhs67);
  sf_mex_destroy(&c11_rhs68);
  sf_mex_destroy(&c11_lhs68);
  sf_mex_destroy(&c11_rhs69);
  sf_mex_destroy(&c11_lhs69);
  sf_mex_destroy(&c11_rhs70);
  sf_mex_destroy(&c11_lhs70);
  sf_mex_destroy(&c11_rhs71);
  sf_mex_destroy(&c11_lhs71);
  sf_mex_destroy(&c11_rhs72);
  sf_mex_destroy(&c11_lhs72);
  sf_mex_destroy(&c11_rhs73);
  sf_mex_destroy(&c11_lhs73);
  sf_mex_destroy(&c11_rhs74);
  sf_mex_destroy(&c11_lhs74);
  sf_mex_destroy(&c11_rhs75);
  sf_mex_destroy(&c11_lhs75);
  sf_mex_destroy(&c11_rhs76);
  sf_mex_destroy(&c11_lhs76);
  sf_mex_destroy(&c11_rhs77);
  sf_mex_destroy(&c11_lhs77);
  sf_mex_destroy(&c11_rhs78);
  sf_mex_destroy(&c11_lhs78);
  sf_mex_destroy(&c11_rhs79);
  sf_mex_destroy(&c11_lhs79);
  sf_mex_destroy(&c11_rhs80);
  sf_mex_destroy(&c11_lhs80);
  sf_mex_destroy(&c11_rhs81);
  sf_mex_destroy(&c11_lhs81);
  sf_mex_destroy(&c11_rhs82);
  sf_mex_destroy(&c11_lhs82);
  sf_mex_destroy(&c11_rhs83);
  sf_mex_destroy(&c11_lhs83);
  sf_mex_destroy(&c11_rhs84);
  sf_mex_destroy(&c11_lhs84);
  sf_mex_destroy(&c11_rhs85);
  sf_mex_destroy(&c11_lhs85);
  sf_mex_destroy(&c11_rhs86);
  sf_mex_destroy(&c11_lhs86);
  sf_mex_destroy(&c11_rhs87);
  sf_mex_destroy(&c11_lhs87);
  sf_mex_destroy(&c11_rhs88);
  sf_mex_destroy(&c11_lhs88);
  sf_mex_destroy(&c11_rhs89);
  sf_mex_destroy(&c11_lhs89);
  sf_mex_destroy(&c11_rhs90);
  sf_mex_destroy(&c11_lhs90);
  sf_mex_destroy(&c11_rhs91);
  sf_mex_destroy(&c11_lhs91);
  sf_mex_destroy(&c11_rhs92);
  sf_mex_destroy(&c11_lhs92);
  sf_mex_destroy(&c11_rhs93);
  sf_mex_destroy(&c11_lhs93);
  sf_mex_destroy(&c11_rhs94);
  sf_mex_destroy(&c11_lhs94);
  sf_mex_destroy(&c11_rhs95);
  sf_mex_destroy(&c11_lhs95);
  sf_mex_destroy(&c11_rhs96);
  sf_mex_destroy(&c11_lhs96);
  sf_mex_destroy(&c11_rhs97);
  sf_mex_destroy(&c11_lhs97);
  sf_mex_destroy(&c11_rhs98);
  sf_mex_destroy(&c11_lhs98);
  sf_mex_destroy(&c11_rhs99);
  sf_mex_destroy(&c11_lhs99);
  sf_mex_destroy(&c11_rhs100);
  sf_mex_destroy(&c11_lhs100);
  sf_mex_destroy(&c11_rhs101);
  sf_mex_destroy(&c11_lhs101);
  sf_mex_destroy(&c11_rhs102);
  sf_mex_destroy(&c11_lhs102);
  sf_mex_destroy(&c11_rhs103);
  sf_mex_destroy(&c11_lhs103);
  sf_mex_destroy(&c11_rhs104);
  sf_mex_destroy(&c11_lhs104);
  sf_mex_destroy(&c11_rhs105);
  sf_mex_destroy(&c11_lhs105);
  sf_mex_destroy(&c11_rhs106);
  sf_mex_destroy(&c11_lhs106);
  sf_mex_destroy(&c11_rhs107);
  sf_mex_destroy(&c11_lhs107);
  sf_mex_destroy(&c11_rhs108);
  sf_mex_destroy(&c11_lhs108);
  sf_mex_destroy(&c11_rhs109);
  sf_mex_destroy(&c11_lhs109);
  sf_mex_destroy(&c11_rhs110);
  sf_mex_destroy(&c11_lhs110);
  sf_mex_destroy(&c11_rhs111);
  sf_mex_destroy(&c11_lhs111);
  sf_mex_destroy(&c11_rhs112);
  sf_mex_destroy(&c11_lhs112);
  sf_mex_destroy(&c11_rhs113);
  sf_mex_destroy(&c11_lhs113);
  sf_mex_destroy(&c11_rhs114);
  sf_mex_destroy(&c11_lhs114);
  sf_mex_destroy(&c11_rhs115);
  sf_mex_destroy(&c11_lhs115);
  sf_mex_destroy(&c11_rhs116);
  sf_mex_destroy(&c11_lhs116);
  sf_mex_destroy(&c11_rhs117);
  sf_mex_destroy(&c11_lhs117);
}

static int32_T c11_intmin(SFc11_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
  return MIN_int32_T;
}

static boolean_T c11_all_in_integer_range
  (SFc11_Walking01_withElmosInstanceStruct *chartInstance, real_T c11_x, int32_T
   c11_minval, uint8_T c11_maxval)
{
  boolean_T c11_p;
  real_T c11_a;
  int32_T c11_b;
  real_T c11_b_a;
  int32_T c11_b_b;
  int32_T c11_idx;
  real_T c11_flt;
  boolean_T c11_b_p;
  real_T c11_b_x;
  real_T c11_c_x;
  boolean_T c11_b1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  (void)chartInstance;
  c11_p = true;
  c11_a = c11_x;
  c11_b = c11_minval;
  c11_b_a = c11_a;
  c11_b_b = c11_b;
  c11_idx = c11_b_b;
  c11_flt = c11_b_a;
  c11_b_p = ((real_T)c11_idx <= c11_flt);
  guard1 = false;
  guard2 = false;
  if (c11_b_p) {
    if (c11_x <= (real_T)c11_maxval) {
      c11_b_x = c11_x;
      c11_c_x = c11_b_x;
      c11_c_x = muDoubleScalarFloor(c11_c_x);
      if (c11_x == c11_c_x) {
        c11_b1 = true;
      } else {
        guard1 = true;
      }
    } else {
      guard2 = true;
    }
  } else {
    guard2 = true;
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c11_b1 = false;
  }

  if (!c11_b1) {
    c11_p = false;
  }

  return c11_p;
}

static void c11_parseSingle(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, uint32_T c11_D[12], real_T c11_S[3])
{
  uint32_T c11_debug_family_var_map[7];
  uint32_T c11_Stmp1[12];
  uint32_T c11_Stmp2[3];
  real32_T c11_Stmp3[3];
  real_T c11_nargin = 1.0;
  real_T c11_nargout = 1.0;
  int32_T c11_i97;
  uint32_T c11_x[12];
  int32_T c11_k;
  int32_T c11_b_k;
  int32_T c11_i98;
  int32_T c11_i99;
  uint32_T c11_b[3];
  int32_T c11_i100;
  uint32_T c11_u19;
  uint32_T c11_u20;
  int32_T c11_i101;
  int32_T c11_i102;
  uint32_T c11_b_b[3];
  int32_T c11_i103;
  uint32_T c11_u21;
  uint32_T c11_u22;
  int32_T c11_i104;
  int32_T c11_i105;
  uint32_T c11_c_b[3];
  int32_T c11_i106;
  uint32_T c11_u23;
  uint32_T c11_u24;
  int32_T c11_i107;
  int32_T c11_i108;
  uint64_T c11_u25;
  uint64_T c11_u26;
  uint64_T c11_u27;
  int32_T c11_i109;
  int32_T c11_i110;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c11_d_debug_family_names,
    c11_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_Stmp1, 0U, c11_m_sf_marshallOut,
    c11_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_Stmp2, 1U, c11_l_sf_marshallOut,
    c11_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_Stmp3, 2U, c11_k_sf_marshallOut,
    c11_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargin, 3U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c11_nargout, 4U, c11_b_sf_marshallOut,
    c11_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_D, 5U, c11_j_sf_marshallOut,
    c11_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c11_S, 6U, c11_d_sf_marshallOut,
    c11_d_sf_marshallIn);
  CV_EML_FCN(0, 1);
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 18);
  for (c11_i97 = 0; c11_i97 < 12; c11_i97++) {
    c11_x[c11_i97] = c11_D[c11_i97];
  }

  c11_intmin(chartInstance);
  for (c11_k = 1; c11_k < 13; c11_k++) {
    c11_b_k = c11_k;
    c11_Stmp1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c11_b_k), 1, 12, 1, 0) - 1] = c11_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c11_b_k), 1, 12, 1, 0) - 1];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 19);
  c11_i98 = 0;
  for (c11_i99 = 0; c11_i99 < 3; c11_i99++) {
    c11_b[c11_i99] = c11_Stmp1[c11_i98];
    c11_i98 += 4;
  }

  for (c11_i100 = 0; c11_i100 < 3; c11_i100++) {
    c11_u19 = c11_b[c11_i100];
    if (CV_SATURATION_EVAL(4, 0, 0, 0, c11_u19 > 255U)) {
      c11_u20 = MAX_uint32_T;
    } else {
      c11_u20 = c11_u19 << 24;
    }

    c11_b[c11_i100] = c11_u20;
  }

  c11_i101 = 0;
  for (c11_i102 = 0; c11_i102 < 3; c11_i102++) {
    c11_b_b[c11_i102] = c11_Stmp1[c11_i101 + 1];
    c11_i101 += 4;
  }

  for (c11_i103 = 0; c11_i103 < 3; c11_i103++) {
    c11_u21 = c11_b_b[c11_i103];
    if (CV_SATURATION_EVAL(4, 0, 4, 0, c11_u21 > 65535U)) {
      c11_u22 = MAX_uint32_T;
    } else {
      c11_u22 = c11_u21 << 16;
    }

    c11_b_b[c11_i103] = c11_u22;
  }

  c11_i104 = 0;
  for (c11_i105 = 0; c11_i105 < 3; c11_i105++) {
    c11_c_b[c11_i105] = c11_Stmp1[c11_i104 + 2];
    c11_i104 += 4;
  }

  for (c11_i106 = 0; c11_i106 < 3; c11_i106++) {
    c11_u23 = c11_c_b[c11_i106];
    if (CV_SATURATION_EVAL(4, 0, 5, 0, c11_u23 > 16777215U)) {
      c11_u24 = MAX_uint32_T;
    } else {
      c11_u24 = c11_u23 << 8;
    }

    c11_c_b[c11_i106] = c11_u24;
  }

  c11_i107 = 0;
  for (c11_i108 = 0; c11_i108 < 3; c11_i108++) {
    c11_u25 = (uint64_T)c11_b[c11_i108] + (uint64_T)c11_b_b[c11_i108];
    if (CV_SATURATION_EVAL(4, 0, 1, 0, c11_u25 > 4294967295ULL)) {
      c11_u25 = 4294967295ULL;
    }

    c11_u26 = (uint64_T)(uint32_T)c11_u25 + (uint64_T)c11_c_b[c11_i108];
    if (CV_SATURATION_EVAL(4, 0, 2, 0, c11_u26 > 4294967295ULL)) {
      c11_u26 = 4294967295ULL;
    }

    c11_u27 = (uint64_T)(uint32_T)c11_u26 + (uint64_T)c11_Stmp1[c11_i107 + 3];
    if (CV_SATURATION_EVAL(4, 0, 3, 0, c11_u27 > 4294967295ULL)) {
      c11_u27 = 4294967295ULL;
    }

    c11_Stmp2[c11_i108] = (uint32_T)c11_u27;
    c11_i107 += 4;
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 20);
  for (c11_i109 = 0; c11_i109 < 3; c11_i109++) {
    c11_b[c11_i109] = c11_Stmp2[c11_i109];
  }

  memcpy(&c11_Stmp3[0], &c11_b[0], (size_t)3 * sizeof(real32_T));
  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, 21);
  for (c11_i110 = 0; c11_i110 < 3; c11_i110++) {
    c11_S[c11_i110] = c11_Stmp3[c11_i110];
  }

  _SFD_EML_CALL(0U, chartInstance->c11_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
}

static const mxArray *c11_q_sf_marshallOut(void *chartInstanceVoid, void
  *c11_inData)
{
  const mxArray *c11_mxArrayOutData = NULL;
  int32_T c11_u;
  const mxArray *c11_y = NULL;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_mxArrayOutData = NULL;
  c11_u = *(int32_T *)c11_inData;
  c11_y = NULL;
  sf_mex_assign(&c11_y, sf_mex_create("y", &c11_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c11_mxArrayOutData, c11_y, false);
  return c11_mxArrayOutData;
}

static int32_T c11_u_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  int32_T c11_y;
  int32_T c11_i111;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_i111, 1, 6, 0U, 0, 0U, 0);
  c11_y = c11_i111;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void c11_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c11_mxArrayInData, const char_T *c11_varName, void *c11_outData)
{
  const mxArray *c11_b_sfEvent;
  const char_T *c11_identifier;
  emlrtMsgIdentifier c11_thisId;
  int32_T c11_y;
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c11_b_sfEvent = sf_mex_dup(c11_mxArrayInData);
  c11_identifier = c11_varName;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c11_b_sfEvent),
    &c11_thisId);
  sf_mex_destroy(&c11_b_sfEvent);
  *(int32_T *)c11_outData = c11_y;
  sf_mex_destroy(&c11_mxArrayInData);
}

static uint8_T c11_v_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_b_is_active_c11_Walking01_withElmos, const
  char_T *c11_identifier)
{
  uint8_T c11_y;
  emlrtMsgIdentifier c11_thisId;
  c11_thisId.fIdentifier = c11_identifier;
  c11_thisId.fParent = NULL;
  c11_y = c11_w_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c11_b_is_active_c11_Walking01_withElmos), &c11_thisId);
  sf_mex_destroy(&c11_b_is_active_c11_Walking01_withElmos);
  return c11_y;
}

static uint8_T c11_w_emlrt_marshallIn(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c11_u, const emlrtMsgIdentifier *c11_parentId)
{
  uint8_T c11_y;
  uint8_T c11_u28;
  (void)chartInstance;
  sf_mex_import(c11_parentId, sf_mex_dup(c11_u), &c11_u28, 1, 3, 0U, 0, 0U, 0);
  c11_y = c11_u28;
  sf_mex_destroy(&c11_u);
  return c11_y;
}

static void init_dsm_address_info(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc11_Walking01_withElmosInstanceStruct
  *chartInstance)
{
  chartInstance->c11_P = (uint32_T (*)[36])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c11_Rotation = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c11_Acceleration = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c11_Status = (uint32_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c11_Sequence = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c11_Temperature = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c11_Valid = (boolean_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
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

void sf_c11_Walking01_withElmos_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3077916593U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4020062045U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1834239007U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1259744110U);
}

mxArray* sf_c11_Walking01_withElmos_get_post_codegen_info(void);
mxArray *sf_c11_Walking01_withElmos_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("PjNphwNBnwuwvoE8moWXf");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(36);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(7));
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

    mxArray *mxData = mxCreateStructMatrix(1,6,3,dataFields);

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
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(7));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,5,"type",mxType);
    }

    mxSetField(mxData,5,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c11_Walking01_withElmos_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c11_Walking01_withElmos_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c11_Walking01_withElmos_jit_fallback_info(void)
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

mxArray *sf_c11_Walking01_withElmos_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c11_Walking01_withElmos_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c11_Walking01_withElmos(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[6],T\"Acceleration\",},{M[1],M[5],T\"Rotation\",},{M[1],M[9],T\"Sequence\",},{M[1],M[8],T\"Status\",},{M[1],M[10],T\"Temperature\",},{M[1],M[7],T\"Valid\",},{M[8],M[0],T\"is_active_c11_Walking01_withElmos\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c11_Walking01_withElmos_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc11_Walking01_withElmosInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_withElmosMachineNumber_,
           11,
           1,
           1,
           0,
           7,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"P");
          _SFD_SET_DATA_PROPS(1,2,0,1,"Rotation");
          _SFD_SET_DATA_PROPS(2,2,0,1,"Acceleration");
          _SFD_SET_DATA_PROPS(3,2,0,1,"Status");
          _SFD_SET_DATA_PROPS(4,2,0,1,"Sequence");
          _SFD_SET_DATA_PROPS(5,2,0,1,"Temperature");
          _SFD_SET_DATA_PROPS(6,2,0,1,"Valid");
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
        _SFD_CV_INIT_EML(0,1,3,1,0,9,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,442);
        _SFD_CV_INIT_EML_FCN(0,1,"parseSingle",444,-1,656);
        _SFD_CV_INIT_EML_FCN(0,2,"parseInt16",658,-1,790);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,521,-1,540);
        _SFD_CV_INIT_EML_SATURATION(0,1,1,521,-1,559);
        _SFD_CV_INIT_EML_SATURATION(0,1,2,521,-1,576);
        _SFD_CV_INIT_EML_SATURATION(0,1,3,521,-1,589);
        _SFD_CV_INIT_EML_SATURATION(0,1,4,543,-1,559);
        _SFD_CV_INIT_EML_SATURATION(0,1,5,562,-1,576);
        _SFD_CV_INIT_EML_SATURATION(0,1,6,697,-1,720);
        _SFD_CV_INIT_EML_SATURATION(0,1,7,734,-1,748);
        _SFD_CV_INIT_EML_SATURATION(0,1,8,734,-1,761);
        _SFD_CV_INIT_EML_IF(0,1,0,193,214,-1,260);
        _SFD_CV_INIT_SCRIPT(0,2,1,0,9,0,2,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"kvhCheckCRC",0,-1,940);
        _SFD_CV_INIT_SCRIPT_FCN(0,1,"parseUint32",942,-1,1108);
        _SFD_CV_INIT_SCRIPT_SATURATION(0,0,1019,-1,1038);
        _SFD_CV_INIT_SCRIPT_SATURATION(0,1,1019,-1,1057);
        _SFD_CV_INIT_SCRIPT_SATURATION(0,2,1019,-1,1074);
        _SFD_CV_INIT_SCRIPT_SATURATION(0,3,1019,-1,1087);
        _SFD_CV_INIT_SCRIPT_SATURATION(0,4,1041,-1,1057);
        _SFD_CV_INIT_SCRIPT_SATURATION(0,5,1060,-1,1074);
        _SFD_CV_INIT_SCRIPT_SATURATION(0,6,510,-1,526);
        _SFD_CV_INIT_SCRIPT_SATURATION(0,7,668,-1,707);
        _SFD_CV_INIT_SCRIPT_SATURATION(0,8,786,-1,825);
        _SFD_CV_INIT_SCRIPT_IF(0,0,540,573,743,842);
        _SFD_CV_INIT_SCRIPT_FOR(0,0,456,466,862);
        _SFD_CV_INIT_SCRIPT_FOR(0,1,474,488,854);

        {
          unsigned int dimVector[1];
          dimVector[0]= 36;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT32,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_d_sf_marshallOut,(MexInFcnForType)
            c11_d_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c11_d_sf_marshallOut,(MexInFcnForType)
            c11_d_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_UINT32,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_c_sf_marshallOut,(MexInFcnForType)
          c11_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_b_sf_marshallOut,(MexInFcnForType)
          c11_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c11_sf_marshallOut,(MexInFcnForType)c11_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c11_P);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c11_Rotation);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c11_Acceleration);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c11_Status);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c11_Sequence);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c11_Temperature);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c11_Valid);
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
  return "5ycb0rqNkFZszaDdsfMMHG";
}

static void sf_opaque_initialize_c11_Walking01_withElmos(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc11_Walking01_withElmosInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c11_Walking01_withElmos
    ((SFc11_Walking01_withElmosInstanceStruct*) chartInstanceVar);
  initialize_c11_Walking01_withElmos((SFc11_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c11_Walking01_withElmos(void *chartInstanceVar)
{
  enable_c11_Walking01_withElmos((SFc11_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c11_Walking01_withElmos(void *chartInstanceVar)
{
  disable_c11_Walking01_withElmos((SFc11_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c11_Walking01_withElmos(void *chartInstanceVar)
{
  sf_gateway_c11_Walking01_withElmos((SFc11_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c11_Walking01_withElmos(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c11_Walking01_withElmos
    ((SFc11_Walking01_withElmosInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c11_Walking01_withElmos(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c11_Walking01_withElmos((SFc11_Walking01_withElmosInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c11_Walking01_withElmos(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc11_Walking01_withElmosInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_withElmos_optimization_info();
    }

    finalize_c11_Walking01_withElmos((SFc11_Walking01_withElmosInstanceStruct*)
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
  initSimStructsc11_Walking01_withElmos((SFc11_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c11_Walking01_withElmos(SimStruct *S)
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
    initialize_params_c11_Walking01_withElmos
      ((SFc11_Walking01_withElmosInstanceStruct*)(chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c11_Walking01_withElmos(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_withElmos_optimization_info();
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
        infoStruct,11,6);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=6; ++outPortIdx) {
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
  ssSetChecksum0(S,(1708761630U));
  ssSetChecksum1(S,(4282688262U));
  ssSetChecksum2(S,(329743318U));
  ssSetChecksum3(S,(665305949U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c11_Walking01_withElmos(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c11_Walking01_withElmos(SimStruct *S)
{
  SFc11_Walking01_withElmosInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc11_Walking01_withElmosInstanceStruct *)utMalloc(sizeof
    (SFc11_Walking01_withElmosInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc11_Walking01_withElmosInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c11_Walking01_withElmos;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c11_Walking01_withElmos;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c11_Walking01_withElmos;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c11_Walking01_withElmos;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c11_Walking01_withElmos;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c11_Walking01_withElmos;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c11_Walking01_withElmos;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c11_Walking01_withElmos;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c11_Walking01_withElmos;
  chartInstance->chartInfo.mdlStart = mdlStart_c11_Walking01_withElmos;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c11_Walking01_withElmos;
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

void c11_Walking01_withElmos_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c11_Walking01_withElmos(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c11_Walking01_withElmos(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c11_Walking01_withElmos(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c11_Walking01_withElmos_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
