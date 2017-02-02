/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_DDA3D_sfun.h"
#include "c39_Walking01_DDA3D.h"
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
static const char * c39_debug_family_names[5] = { "LimitSwitchesVec", "nargin",
  "nargout", "Switches", "LimitSwitchesEncoded" };

static const char * c39_b_debug_family_names[4] = { "nargin", "nargout",
  "LimitSwitchesVec", "LimitSwitchesEncoded" };

/* Function Declarations */
static void initialize_c39_Walking01_DDA3D(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initialize_params_c39_Walking01_DDA3D
  (SFc39_Walking01_DDA3DInstanceStruct *chartInstance);
static void enable_c39_Walking01_DDA3D(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void disable_c39_Walking01_DDA3D(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c39_update_debugger_state_c39_Walking01_DDA3D
  (SFc39_Walking01_DDA3DInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c39_Walking01_DDA3D
  (SFc39_Walking01_DDA3DInstanceStruct *chartInstance);
static void set_sim_state_c39_Walking01_DDA3D
  (SFc39_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c39_st);
static void finalize_c39_Walking01_DDA3D(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void sf_gateway_c39_Walking01_DDA3D(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void mdl_start_c39_Walking01_DDA3D(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initSimStructsc39_Walking01_DDA3D
  (SFc39_Walking01_DDA3DInstanceStruct *chartInstance);
static uint32_T c39_EncodeSwitches(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, uint32_T c39_LimitSwitchesVec[6]);
static void init_script_number_translation(uint32_T c39_machineNumber, uint32_T
  c39_chartNumber, uint32_T c39_instanceNumber);
static const mxArray *c39_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData);
static real_T c39_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_b_LimitSwitchesEncoded, const char_T
  *c39_identifier);
static real_T c39_b_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId);
static void c39_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData);
static const mxArray *c39_b_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData);
static const mxArray *c39_c_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData);
static void c39_c_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId,
  uint32_T c39_y[6]);
static void c39_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData);
static const mxArray *c39_d_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData);
static uint32_T c39_d_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId);
static void c39_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData);
static void c39_info_helper(const mxArray **c39_info);
static const mxArray *c39_emlrt_marshallOut(const char * c39_u);
static const mxArray *c39_b_emlrt_marshallOut(const uint32_T c39_u);
static const mxArray *c39_e_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData);
static int32_T c39_e_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId);
static void c39_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData);
static uint8_T c39_f_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_b_is_active_c39_Walking01_DDA3D, const
  char_T *c39_identifier);
static uint8_T c39_g_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId);
static void init_dsm_address_info(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c39_Walking01_DDA3D(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c39_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c39_is_active_c39_Walking01_DDA3D = 0U;
}

static void initialize_params_c39_Walking01_DDA3D
  (SFc39_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c39_Walking01_DDA3D(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c39_Walking01_DDA3D(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c39_update_debugger_state_c39_Walking01_DDA3D
  (SFc39_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c39_Walking01_DDA3D
  (SFc39_Walking01_DDA3DInstanceStruct *chartInstance)
{
  const mxArray *c39_st;
  const mxArray *c39_y = NULL;
  real_T c39_hoistedGlobal;
  real_T c39_u;
  const mxArray *c39_b_y = NULL;
  uint8_T c39_b_hoistedGlobal;
  uint8_T c39_b_u;
  const mxArray *c39_c_y = NULL;
  c39_st = NULL;
  c39_st = NULL;
  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_createcellmatrix(2, 1), false);
  c39_hoistedGlobal = *chartInstance->c39_LimitSwitchesEncoded;
  c39_u = c39_hoistedGlobal;
  c39_b_y = NULL;
  sf_mex_assign(&c39_b_y, sf_mex_create("y", &c39_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c39_y, 0, c39_b_y);
  c39_b_hoistedGlobal = chartInstance->c39_is_active_c39_Walking01_DDA3D;
  c39_b_u = c39_b_hoistedGlobal;
  c39_c_y = NULL;
  sf_mex_assign(&c39_c_y, sf_mex_create("y", &c39_b_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c39_y, 1, c39_c_y);
  sf_mex_assign(&c39_st, c39_y, false);
  return c39_st;
}

static void set_sim_state_c39_Walking01_DDA3D
  (SFc39_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c39_st)
{
  const mxArray *c39_u;
  chartInstance->c39_doneDoubleBufferReInit = true;
  c39_u = sf_mex_dup(c39_st);
  *chartInstance->c39_LimitSwitchesEncoded = c39_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c39_u, 0)), "LimitSwitchesEncoded");
  chartInstance->c39_is_active_c39_Walking01_DDA3D = c39_f_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c39_u, 1)),
     "is_active_c39_Walking01_DDA3D");
  sf_mex_destroy(&c39_u);
  c39_update_debugger_state_c39_Walking01_DDA3D(chartInstance);
  sf_mex_destroy(&c39_st);
}

static void finalize_c39_Walking01_DDA3D(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c39_Walking01_DDA3D(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  int32_T c39_i0;
  int32_T c39_i1;
  real_T c39_b_Switches[6];
  uint32_T c39_debug_family_var_map[5];
  uint32_T c39_LimitSwitchesVec[6];
  real_T c39_nargin = 1.0;
  real_T c39_nargout = 1.0;
  real_T c39_b_LimitSwitchesEncoded;
  int32_T c39_i2;
  real_T c39_d0;
  uint32_T c39_u0;
  int32_T c39_i3;
  uint32_T c39_b_LimitSwitchesVec[6];
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c39_sfEvent);
  for (c39_i0 = 0; c39_i0 < 6; c39_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c39_Switches)[c39_i0], 0U);
  }

  chartInstance->c39_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c39_sfEvent);
  for (c39_i1 = 0; c39_i1 < 6; c39_i1++) {
    c39_b_Switches[c39_i1] = (*chartInstance->c39_Switches)[c39_i1];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 5U, 5U, c39_debug_family_names,
    c39_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c39_LimitSwitchesVec, 0U,
    c39_c_sf_marshallOut, c39_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c39_nargin, 1U, c39_sf_marshallOut,
    c39_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c39_nargout, 2U, c39_sf_marshallOut,
    c39_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c39_b_Switches, 3U, c39_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c39_b_LimitSwitchesEncoded, 4U,
    c39_sf_marshallOut, c39_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c39_sfEvent, 2);
  for (c39_i2 = 0; c39_i2 < 6; c39_i2++) {
    c39_d0 = muDoubleScalarRound(c39_b_Switches[c39_i2]);
    if (c39_d0 < 4.294967296E+9) {
      if (CV_SATURATION_EVAL(4, 0, 0, 1, c39_d0 >= 0.0)) {
        c39_u0 = (uint32_T)c39_d0;
      } else {
        c39_u0 = 0U;
      }
    } else if (CV_SATURATION_EVAL(4, 0, 0, 0, c39_d0 >= 4.294967296E+9)) {
      c39_u0 = MAX_uint32_T;
    } else {
      c39_u0 = 0U;
    }

    c39_LimitSwitchesVec[c39_i2] = c39_u0;
  }

  _SFD_EML_CALL(0U, chartInstance->c39_sfEvent, 3);
  for (c39_i3 = 0; c39_i3 < 6; c39_i3++) {
    c39_b_LimitSwitchesVec[c39_i3] = c39_LimitSwitchesVec[c39_i3];
  }

  c39_b_LimitSwitchesEncoded = (real_T)c39_EncodeSwitches(chartInstance,
    c39_b_LimitSwitchesVec);
  _SFD_EML_CALL(0U, chartInstance->c39_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c39_LimitSwitchesEncoded = c39_b_LimitSwitchesEncoded;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c39_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_DDA3DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c39_LimitSwitchesEncoded, 1U);
}

static void mdl_start_c39_Walking01_DDA3D(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc39_Walking01_DDA3D
  (SFc39_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static uint32_T c39_EncodeSwitches(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, uint32_T c39_LimitSwitchesVec[6])
{
  uint32_T c39_b_LimitSwitchesEncoded;
  uint32_T c39_debug_family_var_map[4];
  real_T c39_nargin = 1.0;
  real_T c39_nargout = 1.0;
  uint32_T c39_a;
  uint32_T c39_a1;
  uint32_T c39_b_a;
  uint32_T c39_c;
  uint32_T c39_varargin_2;
  uint32_T c39_b;
  uint32_T c39_c_a;
  uint32_T c39_b_a1;
  uint32_T c39_d_a;
  uint32_T c39_b_c;
  uint32_T c39_varargin_1;
  uint32_T c39_b_varargin_2;
  uint32_T c39_e_a;
  uint32_T c39_b_b;
  uint32_T c39_f_a;
  uint32_T c39_c_a1;
  uint32_T c39_g_a;
  uint32_T c39_c_c;
  uint32_T c39_b_varargin_1;
  uint32_T c39_c_varargin_2;
  uint32_T c39_h_a;
  uint32_T c39_c_b;
  uint32_T c39_i_a;
  uint32_T c39_d_a1;
  uint32_T c39_j_a;
  uint32_T c39_d_c;
  uint32_T c39_c_varargin_1;
  uint32_T c39_d_varargin_2;
  uint32_T c39_k_a;
  uint32_T c39_d_b;
  uint32_T c39_l_a;
  uint32_T c39_e_a1;
  uint32_T c39_m_a;
  uint32_T c39_e_c;
  uint32_T c39_d_varargin_1;
  uint32_T c39_e_varargin_2;
  uint32_T c39_n_a;
  uint32_T c39_e_b;
  uint32_T c39_o_a;
  uint32_T c39_f_a1;
  uint32_T c39_p_a;
  uint32_T c39_f_c;
  uint32_T c39_e_varargin_1;
  uint32_T c39_f_varargin_2;
  uint32_T c39_q_a;
  uint32_T c39_f_b;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c39_b_debug_family_names,
    c39_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c39_nargin, 0U, c39_sf_marshallOut,
    c39_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c39_nargout, 1U, c39_sf_marshallOut,
    c39_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c39_LimitSwitchesVec, 2U,
    c39_c_sf_marshallOut, c39_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c39_b_LimitSwitchesEncoded, 3U,
    c39_d_sf_marshallOut, c39_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c39_sfEvent, 61);
  c39_b_LimitSwitchesEncoded = 0U;
  _SFD_SCRIPT_CALL(0U, chartInstance->c39_sfEvent, 62);
  c39_a = c39_LimitSwitchesVec[0];
  c39_a1 = c39_a;
  c39_b_a = c39_a1;
  c39_c = c39_b_a;
  c39_varargin_2 = c39_c;
  c39_b = c39_varargin_2;
  c39_b_LimitSwitchesEncoded = c39_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c39_sfEvent, 63);
  c39_c_a = c39_LimitSwitchesVec[1];
  c39_b_a1 = c39_c_a;
  c39_d_a = c39_b_a1;
  c39_b_c = c39_d_a << 6U;
  c39_varargin_1 = c39_b_LimitSwitchesEncoded;
  c39_b_varargin_2 = c39_b_c;
  c39_e_a = c39_varargin_1;
  c39_b_b = c39_b_varargin_2;
  c39_b_LimitSwitchesEncoded = c39_e_a | c39_b_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c39_sfEvent, 64);
  c39_f_a = c39_LimitSwitchesVec[2];
  c39_c_a1 = c39_f_a;
  c39_g_a = c39_c_a1;
  c39_c_c = c39_g_a << 11U;
  c39_b_varargin_1 = c39_b_LimitSwitchesEncoded;
  c39_c_varargin_2 = c39_c_c;
  c39_h_a = c39_b_varargin_1;
  c39_c_b = c39_c_varargin_2;
  c39_b_LimitSwitchesEncoded = c39_h_a | c39_c_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c39_sfEvent, 65);
  c39_i_a = c39_LimitSwitchesVec[3];
  c39_d_a1 = c39_i_a;
  c39_j_a = c39_d_a1;
  c39_d_c = c39_j_a << 16U;
  c39_c_varargin_1 = c39_b_LimitSwitchesEncoded;
  c39_d_varargin_2 = c39_d_c;
  c39_k_a = c39_c_varargin_1;
  c39_d_b = c39_d_varargin_2;
  c39_b_LimitSwitchesEncoded = c39_k_a | c39_d_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c39_sfEvent, 66);
  c39_l_a = c39_LimitSwitchesVec[4];
  c39_e_a1 = c39_l_a;
  c39_m_a = c39_e_a1;
  c39_e_c = c39_m_a << 22U;
  c39_d_varargin_1 = c39_b_LimitSwitchesEncoded;
  c39_e_varargin_2 = c39_e_c;
  c39_n_a = c39_d_varargin_1;
  c39_e_b = c39_e_varargin_2;
  c39_b_LimitSwitchesEncoded = c39_n_a | c39_e_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c39_sfEvent, 67);
  c39_o_a = c39_LimitSwitchesVec[5];
  c39_f_a1 = c39_o_a;
  c39_p_a = c39_f_a1;
  c39_f_c = c39_p_a << 27U;
  c39_e_varargin_1 = c39_b_LimitSwitchesEncoded;
  c39_f_varargin_2 = c39_f_c;
  c39_q_a = c39_e_varargin_1;
  c39_f_b = c39_f_varargin_2;
  c39_b_LimitSwitchesEncoded = c39_q_a | c39_f_b;
  _SFD_SCRIPT_CALL(0U, chartInstance->c39_sfEvent, -67);
  _SFD_SYMBOL_SCOPE_POP();
  return c39_b_LimitSwitchesEncoded;
}

static void init_script_number_translation(uint32_T c39_machineNumber, uint32_T
  c39_chartNumber, uint32_T c39_instanceNumber)
{
  (void)c39_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c39_chartNumber, c39_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\DAQ\\EncodeSwitches.m"));
}

static const mxArray *c39_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData)
{
  const mxArray *c39_mxArrayOutData = NULL;
  real_T c39_u;
  const mxArray *c39_y = NULL;
  SFc39_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc39_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c39_mxArrayOutData = NULL;
  c39_u = *(real_T *)c39_inData;
  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_create("y", &c39_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c39_mxArrayOutData, c39_y, false);
  return c39_mxArrayOutData;
}

static real_T c39_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_b_LimitSwitchesEncoded, const char_T
  *c39_identifier)
{
  real_T c39_y;
  emlrtMsgIdentifier c39_thisId;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_y = c39_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c39_b_LimitSwitchesEncoded), &c39_thisId);
  sf_mex_destroy(&c39_b_LimitSwitchesEncoded);
  return c39_y;
}

static real_T c39_b_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId)
{
  real_T c39_y;
  real_T c39_d1;
  (void)chartInstance;
  sf_mex_import(c39_parentId, sf_mex_dup(c39_u), &c39_d1, 1, 0, 0U, 0, 0U, 0);
  c39_y = c39_d1;
  sf_mex_destroy(&c39_u);
  return c39_y;
}

static void c39_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData)
{
  const mxArray *c39_b_LimitSwitchesEncoded;
  const char_T *c39_identifier;
  emlrtMsgIdentifier c39_thisId;
  real_T c39_y;
  SFc39_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc39_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c39_b_LimitSwitchesEncoded = sf_mex_dup(c39_mxArrayInData);
  c39_identifier = c39_varName;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_y = c39_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c39_b_LimitSwitchesEncoded), &c39_thisId);
  sf_mex_destroy(&c39_b_LimitSwitchesEncoded);
  *(real_T *)c39_outData = c39_y;
  sf_mex_destroy(&c39_mxArrayInData);
}

static const mxArray *c39_b_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData)
{
  const mxArray *c39_mxArrayOutData = NULL;
  int32_T c39_i4;
  real_T c39_b_inData[6];
  int32_T c39_i5;
  real_T c39_u[6];
  const mxArray *c39_y = NULL;
  SFc39_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc39_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c39_mxArrayOutData = NULL;
  for (c39_i4 = 0; c39_i4 < 6; c39_i4++) {
    c39_b_inData[c39_i4] = (*(real_T (*)[6])c39_inData)[c39_i4];
  }

  for (c39_i5 = 0; c39_i5 < 6; c39_i5++) {
    c39_u[c39_i5] = c39_b_inData[c39_i5];
  }

  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_create("y", c39_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c39_mxArrayOutData, c39_y, false);
  return c39_mxArrayOutData;
}

static const mxArray *c39_c_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData)
{
  const mxArray *c39_mxArrayOutData = NULL;
  int32_T c39_i6;
  uint32_T c39_b_inData[6];
  int32_T c39_i7;
  uint32_T c39_u[6];
  const mxArray *c39_y = NULL;
  SFc39_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc39_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c39_mxArrayOutData = NULL;
  for (c39_i6 = 0; c39_i6 < 6; c39_i6++) {
    c39_b_inData[c39_i6] = (*(uint32_T (*)[6])c39_inData)[c39_i6];
  }

  for (c39_i7 = 0; c39_i7 < 6; c39_i7++) {
    c39_u[c39_i7] = c39_b_inData[c39_i7];
  }

  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_create("y", c39_u, 7, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c39_mxArrayOutData, c39_y, false);
  return c39_mxArrayOutData;
}

static void c39_c_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId,
  uint32_T c39_y[6])
{
  uint32_T c39_uv0[6];
  int32_T c39_i8;
  (void)chartInstance;
  sf_mex_import(c39_parentId, sf_mex_dup(c39_u), c39_uv0, 1, 7, 0U, 1, 0U, 1, 6);
  for (c39_i8 = 0; c39_i8 < 6; c39_i8++) {
    c39_y[c39_i8] = c39_uv0[c39_i8];
  }

  sf_mex_destroy(&c39_u);
}

static void c39_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData)
{
  const mxArray *c39_LimitSwitchesVec;
  const char_T *c39_identifier;
  emlrtMsgIdentifier c39_thisId;
  uint32_T c39_y[6];
  int32_T c39_i9;
  SFc39_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc39_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c39_LimitSwitchesVec = sf_mex_dup(c39_mxArrayInData);
  c39_identifier = c39_varName;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c39_LimitSwitchesVec),
    &c39_thisId, c39_y);
  sf_mex_destroy(&c39_LimitSwitchesVec);
  for (c39_i9 = 0; c39_i9 < 6; c39_i9++) {
    (*(uint32_T (*)[6])c39_outData)[c39_i9] = c39_y[c39_i9];
  }

  sf_mex_destroy(&c39_mxArrayInData);
}

static const mxArray *c39_d_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData)
{
  const mxArray *c39_mxArrayOutData = NULL;
  uint32_T c39_u;
  const mxArray *c39_y = NULL;
  SFc39_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc39_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c39_mxArrayOutData = NULL;
  c39_u = *(uint32_T *)c39_inData;
  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_create("y", &c39_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c39_mxArrayOutData, c39_y, false);
  return c39_mxArrayOutData;
}

static uint32_T c39_d_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId)
{
  uint32_T c39_y;
  uint32_T c39_u1;
  (void)chartInstance;
  sf_mex_import(c39_parentId, sf_mex_dup(c39_u), &c39_u1, 1, 7, 0U, 0, 0U, 0);
  c39_y = c39_u1;
  sf_mex_destroy(&c39_u);
  return c39_y;
}

static void c39_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData)
{
  const mxArray *c39_b_LimitSwitchesEncoded;
  const char_T *c39_identifier;
  emlrtMsgIdentifier c39_thisId;
  uint32_T c39_y;
  SFc39_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc39_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c39_b_LimitSwitchesEncoded = sf_mex_dup(c39_mxArrayInData);
  c39_identifier = c39_varName;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_y = c39_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c39_b_LimitSwitchesEncoded), &c39_thisId);
  sf_mex_destroy(&c39_b_LimitSwitchesEncoded);
  *(uint32_T *)c39_outData = c39_y;
  sf_mex_destroy(&c39_mxArrayInData);
}

const mxArray *sf_c39_Walking01_DDA3D_get_eml_resolved_functions_info(void)
{
  const mxArray *c39_nameCaptureInfo = NULL;
  c39_nameCaptureInfo = NULL;
  sf_mex_assign(&c39_nameCaptureInfo, sf_mex_createstruct("structure", 2, 17, 1),
                false);
  c39_info_helper(&c39_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c39_nameCaptureInfo);
  return c39_nameCaptureInfo;
}

static void c39_info_helper(const mxArray **c39_info)
{
  const mxArray *c39_rhs0 = NULL;
  const mxArray *c39_lhs0 = NULL;
  const mxArray *c39_rhs1 = NULL;
  const mxArray *c39_lhs1 = NULL;
  const mxArray *c39_rhs2 = NULL;
  const mxArray *c39_lhs2 = NULL;
  const mxArray *c39_rhs3 = NULL;
  const mxArray *c39_lhs3 = NULL;
  const mxArray *c39_rhs4 = NULL;
  const mxArray *c39_lhs4 = NULL;
  const mxArray *c39_rhs5 = NULL;
  const mxArray *c39_lhs5 = NULL;
  const mxArray *c39_rhs6 = NULL;
  const mxArray *c39_lhs6 = NULL;
  const mxArray *c39_rhs7 = NULL;
  const mxArray *c39_lhs7 = NULL;
  const mxArray *c39_rhs8 = NULL;
  const mxArray *c39_lhs8 = NULL;
  const mxArray *c39_rhs9 = NULL;
  const mxArray *c39_lhs9 = NULL;
  const mxArray *c39_rhs10 = NULL;
  const mxArray *c39_lhs10 = NULL;
  const mxArray *c39_rhs11 = NULL;
  const mxArray *c39_lhs11 = NULL;
  const mxArray *c39_rhs12 = NULL;
  const mxArray *c39_lhs12 = NULL;
  const mxArray *c39_rhs13 = NULL;
  const mxArray *c39_lhs13 = NULL;
  const mxArray *c39_rhs14 = NULL;
  const mxArray *c39_lhs14 = NULL;
  const mxArray *c39_rhs15 = NULL;
  const mxArray *c39_lhs15 = NULL;
  const mxArray *c39_rhs16 = NULL;
  const mxArray *c39_lhs16 = NULL;
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("EncodeSwitches"), "name",
                  "name", 0);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/EncodeSwitches.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1444247667U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c39_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/EncodeSwitches.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("bitshift"), "name", "name",
                  1);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1388216346U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c39_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 2);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c39_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c39_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c39_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 5);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c39_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 6);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c39_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!allinteger"),
                  "context", "context", 7);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("floor"), "name", "name", 7);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c39_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c39_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 9);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c39_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitshift.m!lshift"),
                  "context", "context", 10);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("eml_int_nbits"), "name",
                  "name", 10);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c39_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_nbits.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 11);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c39_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/DAQ/EncodeSwitches.m"),
                  "context", "context", 12);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("bitor"), "name", "name", 12);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitor.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1383898892U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c39_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitor.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 13);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c39_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/bitor.m"), "context",
                  "context", 14);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("bitbinop"), "name", "name",
                  14);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 14);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/ops/private/bitbinop.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1383898890U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c39_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/ops/private/bitbinop.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 15);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c39_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/ops/private/bitbinop.m"),
                  "context", "context", 16);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 16);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut("uint32"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c39_info, c39_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c39_info, c39_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c39_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c39_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c39_info, sf_mex_duplicatearraysafe(&c39_lhs16), "lhs", "lhs",
                  16);
  sf_mex_destroy(&c39_rhs0);
  sf_mex_destroy(&c39_lhs0);
  sf_mex_destroy(&c39_rhs1);
  sf_mex_destroy(&c39_lhs1);
  sf_mex_destroy(&c39_rhs2);
  sf_mex_destroy(&c39_lhs2);
  sf_mex_destroy(&c39_rhs3);
  sf_mex_destroy(&c39_lhs3);
  sf_mex_destroy(&c39_rhs4);
  sf_mex_destroy(&c39_lhs4);
  sf_mex_destroy(&c39_rhs5);
  sf_mex_destroy(&c39_lhs5);
  sf_mex_destroy(&c39_rhs6);
  sf_mex_destroy(&c39_lhs6);
  sf_mex_destroy(&c39_rhs7);
  sf_mex_destroy(&c39_lhs7);
  sf_mex_destroy(&c39_rhs8);
  sf_mex_destroy(&c39_lhs8);
  sf_mex_destroy(&c39_rhs9);
  sf_mex_destroy(&c39_lhs9);
  sf_mex_destroy(&c39_rhs10);
  sf_mex_destroy(&c39_lhs10);
  sf_mex_destroy(&c39_rhs11);
  sf_mex_destroy(&c39_lhs11);
  sf_mex_destroy(&c39_rhs12);
  sf_mex_destroy(&c39_lhs12);
  sf_mex_destroy(&c39_rhs13);
  sf_mex_destroy(&c39_lhs13);
  sf_mex_destroy(&c39_rhs14);
  sf_mex_destroy(&c39_lhs14);
  sf_mex_destroy(&c39_rhs15);
  sf_mex_destroy(&c39_lhs15);
  sf_mex_destroy(&c39_rhs16);
  sf_mex_destroy(&c39_lhs16);
}

static const mxArray *c39_emlrt_marshallOut(const char * c39_u)
{
  const mxArray *c39_y = NULL;
  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_create("y", c39_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c39_u)), false);
  return c39_y;
}

static const mxArray *c39_b_emlrt_marshallOut(const uint32_T c39_u)
{
  const mxArray *c39_y = NULL;
  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_create("y", &c39_u, 7, 0U, 0U, 0U, 0), false);
  return c39_y;
}

static const mxArray *c39_e_sf_marshallOut(void *chartInstanceVoid, void
  *c39_inData)
{
  const mxArray *c39_mxArrayOutData = NULL;
  int32_T c39_u;
  const mxArray *c39_y = NULL;
  SFc39_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc39_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c39_mxArrayOutData = NULL;
  c39_u = *(int32_T *)c39_inData;
  c39_y = NULL;
  sf_mex_assign(&c39_y, sf_mex_create("y", &c39_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c39_mxArrayOutData, c39_y, false);
  return c39_mxArrayOutData;
}

static int32_T c39_e_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId)
{
  int32_T c39_y;
  int32_T c39_i10;
  (void)chartInstance;
  sf_mex_import(c39_parentId, sf_mex_dup(c39_u), &c39_i10, 1, 6, 0U, 0, 0U, 0);
  c39_y = c39_i10;
  sf_mex_destroy(&c39_u);
  return c39_y;
}

static void c39_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c39_mxArrayInData, const char_T *c39_varName, void *c39_outData)
{
  const mxArray *c39_b_sfEvent;
  const char_T *c39_identifier;
  emlrtMsgIdentifier c39_thisId;
  int32_T c39_y;
  SFc39_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc39_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c39_b_sfEvent = sf_mex_dup(c39_mxArrayInData);
  c39_identifier = c39_varName;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_y = c39_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c39_b_sfEvent),
    &c39_thisId);
  sf_mex_destroy(&c39_b_sfEvent);
  *(int32_T *)c39_outData = c39_y;
  sf_mex_destroy(&c39_mxArrayInData);
}

static uint8_T c39_f_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_b_is_active_c39_Walking01_DDA3D, const
  char_T *c39_identifier)
{
  uint8_T c39_y;
  emlrtMsgIdentifier c39_thisId;
  c39_thisId.fIdentifier = c39_identifier;
  c39_thisId.fParent = NULL;
  c39_y = c39_g_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c39_b_is_active_c39_Walking01_DDA3D), &c39_thisId);
  sf_mex_destroy(&c39_b_is_active_c39_Walking01_DDA3D);
  return c39_y;
}

static uint8_T c39_g_emlrt_marshallIn(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c39_u, const emlrtMsgIdentifier *c39_parentId)
{
  uint8_T c39_y;
  uint8_T c39_u2;
  (void)chartInstance;
  sf_mex_import(c39_parentId, sf_mex_dup(c39_u), &c39_u2, 1, 3, 0U, 0, 0U, 0);
  c39_y = c39_u2;
  sf_mex_destroy(&c39_u);
  return c39_y;
}

static void init_dsm_address_info(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc39_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c39_Switches = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c39_LimitSwitchesEncoded = (real_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
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

void sf_c39_Walking01_DDA3D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2024268115U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2792480351U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3519490547U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(80772322U);
}

mxArray* sf_c39_Walking01_DDA3D_get_post_codegen_info(void);
mxArray *sf_c39_Walking01_DDA3D_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("xmhS1ASqFy18QLEWKqnyWD");
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
      pr[0] = (double)(1);
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
    mxArray* mxPostCodegenInfo = sf_c39_Walking01_DDA3D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c39_Walking01_DDA3D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c39_Walking01_DDA3D_jit_fallback_info(void)
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

mxArray *sf_c39_Walking01_DDA3D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c39_Walking01_DDA3D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c39_Walking01_DDA3D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"LimitSwitchesEncoded\",},{M[8],M[0],T\"is_active_c39_Walking01_DDA3D\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c39_Walking01_DDA3D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc39_Walking01_DDA3DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc39_Walking01_DDA3DInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_DDA3DMachineNumber_,
           39,
           1,
           1,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"Switches");
          _SFD_SET_DATA_PROPS(1,2,0,1,"LimitSwitchesEncoded");
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
        _SFD_CV_INIT_EML(0,1,1,0,0,1,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,174);
        _SFD_CV_INIT_EML_SATURATION(0,1,0,84,-1,100);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"EncodeSwitches",0,-1,2825);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c39_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c39_sf_marshallOut,(MexInFcnForType)c39_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c39_Switches);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c39_LimitSwitchesEncoded);
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
  return "71WIr8ml2bwzQstRISnWiE";
}

static void sf_opaque_initialize_c39_Walking01_DDA3D(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc39_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c39_Walking01_DDA3D((SFc39_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
  initialize_c39_Walking01_DDA3D((SFc39_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c39_Walking01_DDA3D(void *chartInstanceVar)
{
  enable_c39_Walking01_DDA3D((SFc39_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c39_Walking01_DDA3D(void *chartInstanceVar)
{
  disable_c39_Walking01_DDA3D((SFc39_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c39_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_gateway_c39_Walking01_DDA3D((SFc39_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c39_Walking01_DDA3D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c39_Walking01_DDA3D((SFc39_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c39_Walking01_DDA3D(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c39_Walking01_DDA3D((SFc39_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c39_Walking01_DDA3D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc39_Walking01_DDA3DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_DDA3D_optimization_info();
    }

    finalize_c39_Walking01_DDA3D((SFc39_Walking01_DDA3DInstanceStruct*)
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
  initSimStructsc39_Walking01_DDA3D((SFc39_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c39_Walking01_DDA3D(SimStruct *S)
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
    initialize_params_c39_Walking01_DDA3D((SFc39_Walking01_DDA3DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c39_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      39);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,39,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,39,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,39);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,39,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,39,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,39);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(224359417U));
  ssSetChecksum1(S,(412232805U));
  ssSetChecksum2(S,(3822738740U));
  ssSetChecksum3(S,(2474092848U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c39_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c39_Walking01_DDA3D(SimStruct *S)
{
  SFc39_Walking01_DDA3DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc39_Walking01_DDA3DInstanceStruct *)utMalloc(sizeof
    (SFc39_Walking01_DDA3DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc39_Walking01_DDA3DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c39_Walking01_DDA3D;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c39_Walking01_DDA3D;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c39_Walking01_DDA3D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c39_Walking01_DDA3D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c39_Walking01_DDA3D;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c39_Walking01_DDA3D;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c39_Walking01_DDA3D;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c39_Walking01_DDA3D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c39_Walking01_DDA3D;
  chartInstance->chartInfo.mdlStart = mdlStart_c39_Walking01_DDA3D;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c39_Walking01_DDA3D;
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

void c39_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c39_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c39_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c39_Walking01_DDA3D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c39_Walking01_DDA3D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
