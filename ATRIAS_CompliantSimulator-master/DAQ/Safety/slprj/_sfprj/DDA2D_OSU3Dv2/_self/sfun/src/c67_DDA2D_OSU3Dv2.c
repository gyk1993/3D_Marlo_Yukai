/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DDA2D_OSU3Dv2_sfun.h"
#include "c67_DDA2D_OSU3Dv2.h"
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
static const char * c67_debug_family_names[19] = { "weight", "u_LA_R", "u_LS_R",
  "u_LA_L", "u_LS_L", "uR", "uL", "T0", "u0", "deltaS", "KASaturationLim",
  "nargin", "nargout", "u", "s", "sat", "ControlState", "ControlParams", "u_sat"
};

static const char * c67_b_debug_family_names[7] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u_opt", "L_opt" };

static const char * c67_c_debug_family_names[8] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_min", "u_opt", "L_opt" };

static const char * c67_d_debug_family_names[8] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_max", "u_opt", "L_opt" };

static const char * c67_e_debug_family_names[8] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u2_min", "u_opt", "L_opt" };

static const char * c67_f_debug_family_names[8] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u2_max", "u_opt", "L_opt" };

static const char * c67_g_debug_family_names[9] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_min", "u2_min", "u_opt", "L_opt" };

static const char * c67_h_debug_family_names[9] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_min", "u2_max", "u_opt", "L_opt" };

static const char * c67_i_debug_family_names[9] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_max", "u2_min", "u_opt", "L_opt" };

static const char * c67_j_debug_family_names[9] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_max", "u2_max", "u_opt", "L_opt" };

static const char * c67_k_debug_family_names[32] = { "u_opt_1", "L_opt_1",
  "u_opt_2", "L_opt_2", "u_opt_3", "L_opt_3", "u_opt_4", "L_opt_4", "u_opt_5",
  "L_opt_5", "u_opt_6", "L_opt_6", "u_opt_7", "L_opt_7", "u_opt_8", "L_opt_8",
  "u_opt_9", "L_opt_9", "LB", "UB", "L_opt", "case_n", "nargin", "nargout",
  "u_LS", "u_LA", "w", "u1_min", "u1_max", "u2_min", "u2_max", "u_opt" };

/* Function Declarations */
static void initialize_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initialize_params_c67_DDA2D_OSU3Dv2
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void enable_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void disable_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c67_update_debugger_state_c67_DDA2D_OSU3Dv2
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c67_DDA2D_OSU3Dv2
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void set_sim_state_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_st);
static void finalize_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void sf_gateway_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void mdl_start_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c67_chartstep_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initSimStructsc67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c67_LA_LS_Revised_Saturation(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c67_u_LS, real_T c67_u_LA, real_T c67_w, real_T
  c67_u1_min, real_T c67_u1_max, real_T c67_u2_min, real_T c67_u2_max, real_T
  c67_u_opt[2]);
static void c67_LA_LS_Revised_Saturation_Case_1
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u_opt[2], real_T c67_L_opt[4]);
static void c67_LA_LS_Revised_Saturation_Case_2
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u1_min, real_T c67_u_opt[2], real_T
   c67_L_opt[4]);
static void c67_LA_LS_Revised_Saturation_Case_3
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u1_max, real_T c67_u_opt[2], real_T
   c67_L_opt[4]);
static void c67_LA_LS_Revised_Saturation_Case_4
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u2_min, real_T c67_u_opt[2], real_T
   c67_L_opt[4]);
static void c67_LA_LS_Revised_Saturation_Case_5
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u2_max, real_T c67_u_opt[2], real_T
   c67_L_opt[4]);
static void c67_LA_LS_Revised_Saturation_Case_6
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u1_min, real_T c67_u2_min, real_T
   c67_u_opt[2], real_T c67_L_opt[4]);
static void c67_LA_LS_Revised_Saturation_Case_7
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u1_min, real_T c67_u2_max, real_T
   c67_u_opt[2], real_T c67_L_opt[4]);
static void c67_LA_LS_Revised_Saturation_Case_8
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u1_max, real_T c67_u2_min, real_T
   c67_u_opt[2], real_T c67_L_opt[4]);
static void c67_LA_LS_Revised_Saturation_Case_9
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u1_max, real_T c67_u2_max, real_T
   c67_u_opt[2], real_T c67_L_opt[4]);
static void init_script_number_translation(uint32_T c67_machineNumber, uint32_T
  c67_chartNumber, uint32_T c67_instanceNumber);
static const mxArray *c67_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData);
static void c67_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u_sat, const char_T *c67_identifier,
  real_T c67_y[6]);
static void c67_b_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[6]);
static void c67_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData);
static const mxArray *c67_b_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData);
static const mxArray *c67_c_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData);
static const mxArray *c67_d_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData);
static const mxArray *c67_e_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData);
static real_T c67_c_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId);
static void c67_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData);
static const mxArray *c67_f_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData);
static void c67_d_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[36]);
static void c67_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData);
static void c67_e_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[2]);
static void c67_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData);
static const mxArray *c67_g_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData);
static void c67_f_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[4]);
static void c67_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData);
static void c67_info_helper(const mxArray **c67_info);
static const mxArray *c67_emlrt_marshallOut(const char * c67_b_u);
static const mxArray *c67_b_emlrt_marshallOut(const uint32_T c67_b_u);
static void c67_b_info_helper(const mxArray **c67_info);
static void c67_c_info_helper(const mxArray **c67_info);
static void c67_eml_scalar_eg(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c67_threshold(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static real_T c67_rdivide(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c67_x, real_T c67_y);
static void c67_eml_switch_helper(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c67_check_forloop_overflow_error(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, boolean_T c67_overflow);
static void c67_b_eml_scalar_eg(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c67_c_eml_scalar_eg(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static real_T c67_eml_xdotu(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c67_x[2], real_T c67_y[2]);
static void c67_realmin(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c67_eps(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c67_eml_matlab_zgetrf(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c67_A[36], real_T c67_b_A[36], int32_T c67_ipiv[6],
  int32_T *c67_info);
static int32_T c67_eml_ixamax(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c67_n, real_T c67_x[36], int32_T c67_ix0);
static void c67_b_eml_switch_helper(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c67_eml_xgeru(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c67_m, int32_T c67_n, real_T c67_alpha1, int32_T c67_ix0, int32_T
  c67_iy0, real_T c67_A[36], int32_T c67_ia0, real_T c67_b_A[36]);
static void c67_eml_warning(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c67_eml_xtrsm(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c67_A[36], real_T c67_B[6], real_T c67_b_B[6]);
static void c67_below_threshold(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c67_c_eml_switch_helper(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c67_scalarEg(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c67_b_eml_xtrsm(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c67_A[36], real_T c67_B[6], real_T c67_b_B[6]);
static const mxArray *c67_h_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData);
static int32_T c67_g_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId);
static void c67_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData);
static const mxArray *c67_ControlState_bus_io(void *chartInstanceVoid, void
  *c67_pData);
static const mxArray *c67_ControlParams_bus_io(void *chartInstanceVoid, void
  *c67_pData);
static uint8_T c67_h_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_is_active_c67_DDA2D_OSU3Dv2, const char_T
  *c67_identifier);
static uint8_T c67_i_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId);
static void c67_b_eml_matlab_zgetrf(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c67_A[36], int32_T c67_ipiv[6], int32_T *c67_info);
static void c67_b_eml_xgeru(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c67_m, int32_T c67_n, real_T c67_alpha1, int32_T c67_ix0, int32_T
  c67_iy0, real_T c67_A[36], int32_T c67_ia0);
static void c67_c_eml_xtrsm(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c67_A[36], real_T c67_B[6]);
static void c67_d_eml_xtrsm(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c67_A[36], real_T c67_B[6]);
static void init_dsm_address_info(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c67_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c67_is_active_c67_DDA2D_OSU3Dv2 = 0U;
}

static void initialize_params_c67_DDA2D_OSU3Dv2
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c67_update_debugger_state_c67_DDA2D_OSU3Dv2
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c67_DDA2D_OSU3Dv2
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  const mxArray *c67_st;
  const mxArray *c67_y = NULL;
  int32_T c67_i0;
  real_T c67_b_u[6];
  const mxArray *c67_b_y = NULL;
  uint8_T c67_hoistedGlobal;
  uint8_T c67_c_u;
  const mxArray *c67_c_y = NULL;
  c67_st = NULL;
  c67_st = NULL;
  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_createcellmatrix(2, 1), false);
  for (c67_i0 = 0; c67_i0 < 6; c67_i0++) {
    c67_b_u[c67_i0] = (*chartInstance->c67_u_sat)[c67_i0];
  }

  c67_b_y = NULL;
  sf_mex_assign(&c67_b_y, sf_mex_create("y", c67_b_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_setcell(c67_y, 0, c67_b_y);
  c67_hoistedGlobal = chartInstance->c67_is_active_c67_DDA2D_OSU3Dv2;
  c67_c_u = c67_hoistedGlobal;
  c67_c_y = NULL;
  sf_mex_assign(&c67_c_y, sf_mex_create("y", &c67_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c67_y, 1, c67_c_y);
  sf_mex_assign(&c67_st, c67_y, false);
  return c67_st;
}

static void set_sim_state_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_st)
{
  const mxArray *c67_b_u;
  real_T c67_dv0[6];
  int32_T c67_i1;
  chartInstance->c67_doneDoubleBufferReInit = true;
  c67_b_u = sf_mex_dup(c67_st);
  c67_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c67_b_u, 0)),
                       "u_sat", c67_dv0);
  for (c67_i1 = 0; c67_i1 < 6; c67_i1++) {
    (*chartInstance->c67_u_sat)[c67_i1] = c67_dv0[c67_i1];
  }

  chartInstance->c67_is_active_c67_DDA2D_OSU3Dv2 = c67_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c67_b_u, 1)),
     "is_active_c67_DDA2D_OSU3Dv2");
  sf_mex_destroy(&c67_b_u);
  c67_update_debugger_state_c67_DDA2D_OSU3Dv2(chartInstance);
  sf_mex_destroy(&c67_st);
}

static void finalize_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  int32_T c67_i2;
  int32_T c67_i3;
  int32_T c67_i4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 9U, chartInstance->c67_sfEvent);
  for (c67_i2 = 0; c67_i2 < 6; c67_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c67_u)[c67_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c67_s, 1U);
  chartInstance->c67_sfEvent = CALL_EVENT;
  c67_chartstep_c67_DDA2D_OSU3Dv2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DDA2D_OSU3Dv2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c67_i3 = 0; c67_i3 < 6; c67_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c67_u_sat)[c67_i3], 2U);
  }

  for (c67_i4 = 0; c67_i4 < 2; c67_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c67_sat)[c67_i4], 3U);
  }
}

static void mdl_start_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c67_chartstep_c67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  real_T c67_hoistedGlobal;
  int32_T c67_i5;
  real_T c67_b_u[6];
  real_T c67_b_s;
  int32_T c67_i6;
  real_T c67_b_sat[2];
  c67_ControlStateBus c67_b_ControlState;
  c67_ControlParamsBus c67_b_ControlParams;
  int32_T c67_i7;
  int32_T c67_i8;
  int32_T c67_i9;
  int32_T c67_i10;
  int32_T c67_i11;
  int32_T c67_i12;
  int32_T c67_i13;
  int32_T c67_i14;
  int32_T c67_i15;
  int32_T c67_i16;
  int32_T c67_i17;
  int32_T c67_i18;
  int32_T c67_i19;
  int32_T c67_i20;
  int32_T c67_i21;
  int32_T c67_i22;
  int32_T c67_i23;
  int32_T c67_i24;
  int32_T c67_i25;
  int32_T c67_i26;
  int32_T c67_i27;
  int32_T c67_i28;
  int32_T c67_i29;
  int32_T c67_i30;
  int32_T c67_i31;
  int32_T c67_i32;
  int32_T c67_i33;
  int32_T c67_i34;
  int32_T c67_i35;
  int32_T c67_i36;
  int32_T c67_i37;
  int32_T c67_i38;
  int32_T c67_i39;
  int32_T c67_i40;
  int32_T c67_i41;
  int32_T c67_i42;
  int32_T c67_i43;
  int32_T c67_i44;
  int32_T c67_i45;
  int32_T c67_i46;
  int32_T c67_i47;
  int32_T c67_i48;
  int32_T c67_i49;
  int32_T c67_i50;
  int32_T c67_i51;
  int32_T c67_i52;
  int32_T c67_i53;
  int32_T c67_i54;
  uint32_T c67_debug_family_var_map[19];
  real_T c67_weight[2];
  real_T c67_u_LA_R;
  real_T c67_u_LS_R;
  real_T c67_u_LA_L;
  real_T c67_u_LS_L;
  real_T c67_uR[2];
  real_T c67_uL[2];
  real_T c67_T0[36];
  real_T c67_u0[6];
  real_T c67_deltaS;
  real_T c67_KASaturationLim;
  real_T c67_nargin = 5.0;
  real_T c67_nargout = 1.0;
  real_T c67_b_u_sat[6];
  int32_T c67_i55;
  int32_T c67_i56;
  int32_T c67_i57;
  real_T c67_b[2];
  int32_T c67_i58;
  int32_T c67_i59;
  int32_T c67_i60;
  real_T c67_C[2];
  int32_T c67_i61;
  int32_T c67_i62;
  int32_T c67_i63;
  int32_T c67_i64;
  int32_T c67_i65;
  int32_T c67_i66;
  static real_T c67_a[4] = { 0.0, 1.0, 1.0, 0.0 };

  real_T c67_A;
  real_T c67_b_A;
  real_T c67_dv1[2];
  int32_T c67_i67;
  real_T c67_dv2[2];
  int32_T c67_i68;
  int32_T c67_i69;
  int32_T c67_i70;
  int32_T c67_i71;
  static real_T c67_dv3[36] = { 0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.5, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0,
    0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c67_i72;
  int32_T c67_i73;
  static int32_T c67_iv0[6] = { 1, 0, 3, 2, 5, 4 };

  real_T c67_b_T0[36];
  int32_T c67_i74;
  int32_T c67_i75;
  int32_T c67_i76;
  int32_T c67_i77;
  real_T c67_b_a[36];
  int32_T c67_i78;
  real_T c67_b_b[6];
  int32_T c67_i79;
  int32_T c67_i80;
  int32_T c67_i81;
  real_T c67_b_C[6];
  int32_T c67_i82;
  int32_T c67_i83;
  int32_T c67_i84;
  int32_T c67_i85;
  int32_T c67_i86;
  int32_T c67_i87;
  real_T c67_varargin_1;
  real_T c67_varargin_2;
  real_T c67_x;
  real_T c67_b_x;
  real_T c67_xk;
  real_T c67_c_x;
  real_T c67_c_a[2];
  int32_T c67_i88;
  real_T c67_d_a[2];
  int32_T c67_i89;
  real_T c67_c_b[2];
  real_T c67_y;
  real_T c67_c_A;
  real_T c67_B;
  real_T c67_b_varargin_1;
  real_T c67_b_varargin_2;
  real_T c67_c_varargin_2;
  real_T c67_varargin_3;
  real_T c67_d_x;
  real_T c67_b_y;
  real_T c67_e_x;
  real_T c67_c_y;
  real_T c67_b_xk;
  real_T c67_yk;
  real_T c67_f_x;
  real_T c67_d_y;
  real_T c67_minval;
  real_T c67_c_varargin_1;
  real_T c67_d_varargin_2;
  real_T c67_e_varargin_2;
  real_T c67_b_varargin_3;
  real_T c67_g_x;
  real_T c67_e_y;
  real_T c67_h_x;
  real_T c67_f_y;
  real_T c67_c_xk;
  real_T c67_b_yk;
  real_T c67_i_x;
  real_T c67_g_y;
  real_T c67_maxval;
  int32_T c67_i90;
  int32_T c67_i91;
  int32_T c67_info;
  int32_T c67_ipiv[6];
  int32_T c67_b_info;
  int32_T c67_c_info;
  int32_T c67_d_info;
  int32_T c67_i92;
  int32_T c67_xi;
  int32_T c67_b_xi;
  int32_T c67_ip;
  real_T c67_temp;
  int32_T c67_i93;
  int32_T c67_i94;
  real_T c67_e_a[36];
  int32_T c67_i95;
  int32_T c67_i96;
  int32_T c67_i97;
  real_T c67_f_a[36];
  int32_T c67_i98;
  int32_T c67_i99;
  boolean_T guard1 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 9U, chartInstance->c67_sfEvent);
  c67_hoistedGlobal = *chartInstance->c67_s;
  for (c67_i5 = 0; c67_i5 < 6; c67_i5++) {
    c67_b_u[c67_i5] = (*chartInstance->c67_u)[c67_i5];
  }

  c67_b_s = c67_hoistedGlobal;
  for (c67_i6 = 0; c67_i6 < 2; c67_i6++) {
    c67_b_sat[c67_i6] = (*chartInstance->c67_sat)[c67_i6];
  }

  c67_b_ControlState.ControllerMode = *(real_T *)&((char_T *)
    chartInstance->c67_ControlState)[0];
  c67_b_ControlState.SupportState = *(real_T *)&((char_T *)
    chartInstance->c67_ControlState)[8];
  c67_b_ControlState.StanceLeg = *(real_T *)&((char_T *)
    chartInstance->c67_ControlState)[16];
  c67_b_ControlState.InDoubleSupport = *(real_T *)&((char_T *)
    chartInstance->c67_ControlState)[24];
  c67_b_ControlState.RollPhase = *(real_T *)&((char_T *)
    chartInstance->c67_ControlState)[32];
  c67_b_ControlState.StepCount = *(real_T *)&((char_T *)
    chartInstance->c67_ControlState)[40];
  c67_b_ControlState.Error = *(real_T *)&((char_T *)
    chartInstance->c67_ControlState)[48];
  c67_b_ControlParams.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [0];
  c67_b_ControlParams.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [8];
  c67_b_ControlParams.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [16];
  c67_b_ControlParams.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [24];
  c67_b_ControlParams.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)
    &((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c67_ControlParams)[0])[32];
  c67_b_ControlParams.Supervisory.ImpactThresholdKASpringRel = *(real_T *)
    &((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c67_ControlParams)[0])[40];
  c67_b_ControlParams.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [48];
  c67_b_ControlParams.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [56];
  c67_b_ControlParams.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [64];
  c67_b_ControlParams.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [72];
  c67_b_ControlParams.Supervisory.TransitionThresholdTorsoVel = *(real_T *)
    &((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c67_ControlParams)[0])[80];
  for (c67_i7 = 0; c67_i7 < 2; c67_i7++) {
    c67_b_ControlParams.Supervisory.KAInjection[c67_i7] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [0])[88])[c67_i7];
  }

  c67_b_ControlParams.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T
    *)(c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
    [0])[104];
  c67_b_ControlParams.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [112];
  for (c67_i8 = 0; c67_i8 < 6; c67_i8++) {
    c67_b_ControlParams.Supervisory.VBLAParams[c67_i8] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [0])[120])[c67_i8];
  }

  for (c67_i9 = 0; c67_i9 < 13; c67_i9++) {
    c67_b_ControlParams.Supervisory.BalanceParams[c67_i9] = ((real_T *)&((char_T
      *)(c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [0])[168])[c67_i9];
  }

  for (c67_i10 = 0; c67_i10 < 5; c67_i10++) {
    c67_b_ControlParams.Supervisory.GaitTweaks[c67_i10] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [0])[272])[c67_i10];
  }

  c67_b_ControlParams.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [312];
  c67_b_ControlParams.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [320];
  c67_b_ControlParams.Supervisory.RunMode = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [328];
  c67_b_ControlParams.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [336];
  for (c67_i11 = 0; c67_i11 < 6; c67_i11++) {
    c67_b_ControlParams.Supervisory.ErrorZeroFactor[c67_i11] = ((real_T *)
      &((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c67_ControlParams)[0])[344])[c67_i11];
  }

  for (c67_i12 = 0; c67_i12 < 6; c67_i12++) {
    c67_b_ControlParams.Supervisory.ErrorVelZeroFactor[c67_i12] = ((real_T *)
      &((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c67_ControlParams)[0])[392])[c67_i12];
  }

  c67_b_ControlParams.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [440];
  c67_b_ControlParams.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [448];
  c67_b_ControlParams.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [456];
  c67_b_ControlParams.Supervisory.TPosing = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [464];
  c67_b_ControlParams.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [472];
  c67_b_ControlParams.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [480];
  c67_b_ControlParams.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [488];
  c67_b_ControlParams.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [496];
  c67_b_ControlParams.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T
    *)(c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
    [0])[504];
  c67_b_ControlParams.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T
    *)(c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
    [0])[512];
  c67_b_ControlParams.Supervisory.VelocityControlTorsoGain = *(real_T *)
    &((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c67_ControlParams)[0])[520];
  c67_b_ControlParams.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [528];
  c67_b_ControlParams.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [536];
  c67_b_ControlParams.Supervisory.Theta0 = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [544];
  c67_b_ControlParams.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [552];
  c67_b_ControlParams.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [560];
  c67_b_ControlParams.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T
    *)(c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
    [0])[568];
  c67_b_ControlParams.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [576];
  c67_b_ControlParams.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [584];
  c67_b_ControlParams.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [592];
  c67_b_ControlParams.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [600];
  for (c67_i13 = 0; c67_i13 < 6; c67_i13++) {
    c67_b_ControlParams.Supervisory.K1MidStanceUpdate[c67_i13] = ((real_T *)
      &((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c67_ControlParams)[0])[608])[c67_i13];
  }

  for (c67_i14 = 0; c67_i14 < 6; c67_i14++) {
    c67_b_ControlParams.Supervisory.K2MidStanceUpdate[c67_i14] = ((real_T *)
      &((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c67_ControlParams)[0])[656])[c67_i14];
  }

  c67_b_ControlParams.Supervisory.EnableVelocityBasedUpdate = *(real_T *)
    &((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c67_ControlParams)[0])[704];
  for (c67_i15 = 0; c67_i15 < 6; c67_i15++) {
    c67_b_ControlParams.Supervisory.VelocityBasedUpdateK1[c67_i15] = ((real_T *)
      &((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c67_ControlParams)[0])[712])[c67_i15];
  }

  for (c67_i16 = 0; c67_i16 < 6; c67_i16++) {
    c67_b_ControlParams.Supervisory.VelocityBasedUpdateK2[c67_i16] = ((real_T *)
      &((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c67_ControlParams)[0])[760])[c67_i16];
  }

  c67_b_ControlParams.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)
    &((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c67_ControlParams)[0])[808];
  c67_i17 = 0;
  for (c67_i18 = 0; c67_i18 < 2; c67_i18++) {
    for (c67_i19 = 0; c67_i19 < 6; c67_i19++) {
      c67_b_ControlParams.Supervisory.VelocityBasedUpdateLimits[c67_i19 +
        c67_i17] = ((real_T *)&((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
        chartInstance->c67_ControlParams)[0])[816])[c67_i19 + c67_i17];
    }

    c67_i17 += 6;
  }

  c67_b_ControlParams.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [912];
  c67_b_ControlParams.Supervisory.dx_cmd = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [920];
  c67_b_ControlParams.Supervisory.ForBackward = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [928];
  c67_b_ControlParams.Supervisory.EnableFrictionID = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [936];
  c67_b_ControlParams.Supervisory.ResetFrictionPosing = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [944];
  c67_b_ControlParams.Supervisory.MoveLegIndex = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [952];
  c67_b_ControlParams.Supervisory.dy_cmd = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [960];
  c67_b_ControlParams.Supervisory.TauDelay = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [968];
  c67_b_ControlParams.Supervisory.TrackFrequency = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [976];
  c67_b_ControlParams.Supervisory.EnablePDControl = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [984];
  c67_b_ControlParams.Supervisory.TorqueAmp = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[0])
    [992];
  for (c67_i20 = 0; c67_i20 < 6; c67_i20++) {
    c67_b_ControlParams.Supervisory.hdPosing[c67_i20] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [0])[1000])[c67_i20];
  }

  c67_b_ControlParams.Discrete.TLastUpdate = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1048])
    [0];
  c67_b_ControlParams.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1048])
    [8];
  c67_b_ControlParams.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1048])
    [16];
  c67_b_ControlParams.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1048])
    [24];
  c67_b_ControlParams.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T
    *)(c67_DiscreteParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
    [1048])[32];
  c67_b_ControlParams.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1048])
    [40];
  c67_b_ControlParams.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1048])
    [48];
  c67_b_ControlParams.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1048])
    [56];
  c67_b_ControlParams.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1048])
    [64];
  c67_b_ControlParams.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1048])
    [72];
  c67_b_ControlParams.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1048])
    [80];
  c67_i21 = 0;
  for (c67_i22 = 0; c67_i22 < 13; c67_i22++) {
    for (c67_i23 = 0; c67_i23 < 6; c67_i23++) {
      c67_b_ControlParams.Output.H0[c67_i23 + c67_i21] = ((real_T *)&((char_T *)
        (c67_OutputParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
        [1136])[0])[c67_i23 + c67_i21];
    }

    c67_i21 += 6;
  }

  c67_i24 = 0;
  for (c67_i25 = 0; c67_i25 < 6; c67_i25++) {
    for (c67_i26 = 0; c67_i26 < 6; c67_i26++) {
      c67_b_ControlParams.Output.HAlpha[c67_i26 + c67_i24] = ((real_T *)
        &((char_T *)(c67_OutputParamsBus *)&((char_T *)
        chartInstance->c67_ControlParams)[1136])[624])[c67_i26 + c67_i24];
    }

    c67_i24 += 6;
  }

  for (c67_i27 = 0; c67_i27 < 2; c67_i27++) {
    c67_b_ControlParams.Output.ThetaLimits[c67_i27] = ((real_T *)&((char_T *)
      (c67_OutputParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1136])
      [912])[c67_i27];
  }

  c67_b_ControlParams.Output.Theta.c0 = *(real_T *)&((char_T *)
    (c67_ThetaParamsBus *)&((char_T *)(c67_OutputParamsBus *)&((char_T *)
    chartInstance->c67_ControlParams)[1136])[928])[0];
  c67_b_ControlParams.Output.Theta.ct = *(real_T *)&((char_T *)
    (c67_ThetaParamsBus *)&((char_T *)(c67_OutputParamsBus *)&((char_T *)
    chartInstance->c67_ControlParams)[1136])[928])[8];
  for (c67_i28 = 0; c67_i28 < 13; c67_i28++) {
    c67_b_ControlParams.Output.Theta.cq[c67_i28] = ((real_T *)&((char_T *)
      (c67_ThetaParamsBus *)&((char_T *)(c67_OutputParamsBus *)&((char_T *)
      chartInstance->c67_ControlParams)[1136])[928])[16])[c67_i28];
  }

  c67_b_ControlParams.Output.Theta.t0 = *(real_T *)&((char_T *)
    (c67_ThetaParamsBus *)&((char_T *)(c67_OutputParamsBus *)&((char_T *)
    chartInstance->c67_ControlParams)[1136])[928])[120];
  for (c67_i29 = 0; c67_i29 < 7; c67_i29++) {
    c67_b_ControlParams.Output.Theta.cz[c67_i29] = ((real_T *)&((char_T *)
      (c67_ThetaParamsBus *)&((char_T *)(c67_OutputParamsBus *)&((char_T *)
      chartInstance->c67_ControlParams)[1136])[928])[128])[c67_i29];
  }

  c67_b_ControlParams.Output.SaturateS = *(real_T *)&((char_T *)
    (c67_OutputParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1136])
    [1112];
  for (c67_i30 = 0; c67_i30 < 2; c67_i30++) {
    c67_b_ControlParams.Output.SLimits[c67_i30] = ((real_T *)&((char_T *)
      (c67_OutputParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1136])
      [1120])[c67_i30];
  }

  c67_b_ControlParams.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c67_OutputParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1136])
    [1136];
  c67_b_ControlParams.Output.UseCorrection = *(real_T *)&((char_T *)
    (c67_OutputParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1136])
    [1144];
  c67_b_ControlParams.Output.SMaxCorrection = *(real_T *)&((char_T *)
    (c67_OutputParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1136])
    [1152];
  c67_i31 = 0;
  for (c67_i32 = 0; c67_i32 < 5; c67_i32++) {
    for (c67_i33 = 0; c67_i33 < 6; c67_i33++) {
      c67_b_ControlParams.Output.HAlphaCorrection[c67_i33 + c67_i31] = ((real_T *)
        &((char_T *)(c67_OutputParamsBus *)&((char_T *)
        chartInstance->c67_ControlParams)[1136])[1160])[c67_i33 + c67_i31];
    }

    c67_i31 += 6;
  }

  c67_b_ControlParams.Output.Phi.c0 = *(real_T *)&((char_T *)(c67_PhiParamsBus *)
    &((char_T *)(c67_OutputParamsBus *)&((char_T *)
    chartInstance->c67_ControlParams)[1136])[1400])[0];
  for (c67_i34 = 0; c67_i34 < 13; c67_i34++) {
    c67_b_ControlParams.Output.Phi.cq[c67_i34] = ((real_T *)&((char_T *)
      (c67_PhiParamsBus *)&((char_T *)(c67_OutputParamsBus *)&((char_T *)
      chartInstance->c67_ControlParams)[1136])[1400])[8])[c67_i34];
  }

  for (c67_i35 = 0; c67_i35 < 20; c67_i35++) {
    c67_b_ControlParams.Output.PhiAlpha[c67_i35] = ((real_T *)&((char_T *)
      (c67_OutputParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1136])
      [1512])[c67_i35];
  }

  c67_b_ControlParams.Output.SaturateR = *(real_T *)&((char_T *)
    (c67_OutputParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1136])
    [1672];
  for (c67_i36 = 0; c67_i36 < 2; c67_i36++) {
    c67_b_ControlParams.Output.RLimits[c67_i36] = ((real_T *)&((char_T *)
      (c67_OutputParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1136])
      [1680])[c67_i36];
  }

  c67_i37 = 0;
  for (c67_i38 = 0; c67_i38 < 5; c67_i38++) {
    for (c67_i39 = 0; c67_i39 < 6; c67_i39++) {
      c67_b_ControlParams.Output.HBarAlpha[c67_i39 + c67_i37] = ((real_T *)
        &((char_T *)(c67_OutputParamsBus *)&((char_T *)
        chartInstance->c67_ControlParams)[1136])[1696])[c67_i39 + c67_i37];
    }

    c67_i37 += 6;
  }

  c67_i40 = 0;
  for (c67_i41 = 0; c67_i41 < 2; c67_i41++) {
    for (c67_i42 = 0; c67_i42 < 6; c67_i42++) {
      c67_b_ControlParams.Output.HBarLimits[c67_i42 + c67_i40] = ((real_T *)
        &((char_T *)(c67_OutputParamsBus *)&((char_T *)
        chartInstance->c67_ControlParams)[1136])[1936])[c67_i42 + c67_i40];
    }

    c67_i40 += 6;
  }

  c67_i43 = 0;
  for (c67_i44 = 0; c67_i44 < 6; c67_i44++) {
    for (c67_i45 = 0; c67_i45 < 6; c67_i45++) {
      c67_b_ControlParams.Output.HAlphaStar[c67_i45 + c67_i43] = ((real_T *)
        &((char_T *)(c67_OutputParamsBus *)&((char_T *)
        chartInstance->c67_ControlParams)[1136])[2032])[c67_i45 + c67_i43];
    }

    c67_i43 += 6;
  }

  c67_b_ControlParams.Output.YawLimit = *(real_T *)&((char_T *)
    (c67_OutputParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[1136])
    [2320];
  c67_b_ControlParams.Output.test = *(real_T *)&((char_T *)(c67_OutputParamsBus *)
    &((char_T *)chartInstance->c67_ControlParams)[1136])[2328];
  for (c67_i46 = 0; c67_i46 < 6; c67_i46++) {
    c67_b_ControlParams.Feedback.kp[c67_i46] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [3472])[0])[c67_i46];
  }

  for (c67_i47 = 0; c67_i47 < 6; c67_i47++) {
    c67_b_ControlParams.Feedback.kd[c67_i47] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [3472])[48])[c67_i47];
  }

  for (c67_i48 = 0; c67_i48 < 2; c67_i48++) {
    c67_b_ControlParams.Feedback.epsilon[c67_i48] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [3472])[96])[c67_i48];
  }

  for (c67_i49 = 0; c67_i49 < 2; c67_i49++) {
    c67_b_ControlParams.Feedback.kff_grav[c67_i49] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [3472])[112])[c67_i49];
  }

  c67_b_ControlParams.Feedback.delta_grav = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [128];
  for (c67_i50 = 0; c67_i50 < 2; c67_i50++) {
    c67_b_ControlParams.Feedback.kff_decoup[c67_i50] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [3472])[136])[c67_i50];
  }

  for (c67_i51 = 0; c67_i51 < 2; c67_i51++) {
    c67_b_ControlParams.Feedback.kd_torso[c67_i51] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [3472])[152])[c67_i51];
  }

  c67_b_ControlParams.Feedback.kp_2dof = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [168];
  c67_b_ControlParams.Feedback.kd_2dof = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [176];
  c67_b_ControlParams.Feedback.kpre_2dof = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [184];
  c67_b_ControlParams.Feedback.kp_lat = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [192];
  c67_b_ControlParams.Feedback.kd_lat = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [200];
  c67_b_ControlParams.Feedback.q3d_min_lat = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [208];
  c67_b_ControlParams.Feedback.q3d_max_lat = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [216];
  c67_b_ControlParams.Feedback.w_torso_lat = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [224];
  for (c67_i52 = 0; c67_i52 < 6; c67_i52++) {
    c67_b_ControlParams.Feedback.u_ff[c67_i52] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [3472])[232])[c67_i52];
  }

  c67_b_ControlParams.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [280];
  c67_b_ControlParams.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [288];
  c67_b_ControlParams.Feedback.Use2DOF = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [296];
  c67_b_ControlParams.Feedback.UseDSGravComp = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [304];
  c67_b_ControlParams.Feedback.lat_bias = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [312];
  c67_b_ControlParams.Feedback.lat_bias2 = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [320];
  c67_b_ControlParams.Feedback.linkFeedback = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [328];
  c67_b_ControlParams.Feedback.RIO = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [336];
  c67_b_ControlParams.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [344];
  for (c67_i53 = 0; c67_i53 < 6; c67_i53++) {
    c67_b_ControlParams.Feedback.FeedforwardGain[c67_i53] = ((real_T *)&((char_T
      *)(c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [3472])[352])[c67_i53];
  }

  c67_b_ControlParams.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)chartInstance->c67_ControlParams)[3472])
    [400];
  c67_b_ControlParams.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c67_SaturationParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
    [3880])[0];
  for (c67_i54 = 0; c67_i54 < 2; c67_i54++) {
    c67_b_ControlParams.Saturation.QPWeight[c67_i54] = ((real_T *)&((char_T *)
      (c67_SaturationParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
      [3880])[8])[c67_i54];
  }

  c67_b_ControlParams.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c67_SaturationParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
    [3880])[24];
  c67_b_ControlParams.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c67_SaturationParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
    [3880])[32];
  c67_b_ControlParams.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c67_SaturationParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
    [3880])[40];
  c67_b_ControlParams.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c67_SaturationParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
    [3880])[48];
  c67_b_ControlParams.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c67_SaturationParamsBus *)&((char_T *)chartInstance->c67_ControlParams)
    [3880])[56];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c67_debug_family_names,
    c67_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_weight, 0U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LA_R, 1U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LS_R, 2U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LA_L, 3U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LS_L, 4U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_uR, 5U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_uL, 6U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_T0, 7U, c67_f_sf_marshallOut,
    c67_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u0, 8U, c67_sf_marshallOut,
    c67_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_deltaS, 9U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_KASaturationLim, 10U,
    c67_e_sf_marshallOut, c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargin, 11U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargout, 12U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c67_b_u, 13U, c67_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c67_b_s, 14U, c67_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c67_b_sat, 15U, c67_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c67_b_ControlState, 16U, c67_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c67_b_ControlParams, 17U, c67_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_b_u_sat, 18U, c67_sf_marshallOut,
    c67_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 4);
  for (c67_i55 = 0; c67_i55 < 6; c67_i55++) {
    c67_b_u_sat[c67_i55] = c67_b_u[c67_i55];
  }

  _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, c67_b_ControlParams.Saturation.UseQPSaturation != 0.0))
  {
    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 7);
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 0,
          c67_b_ControlState.StanceLeg, 0.0, -1, 0U,
          c67_b_ControlState.StanceLeg == 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 8);
      for (c67_i56 = 0; c67_i56 < 2; c67_i56++) {
        c67_weight[c67_i56] = c67_b_ControlParams.Saturation.QPWeight[c67_i56];
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 10);
      for (c67_i57 = 0; c67_i57 < 2; c67_i57++) {
        c67_b[c67_i57] = c67_b_ControlParams.Saturation.QPWeight[c67_i57];
      }

      c67_eml_scalar_eg(chartInstance);
      c67_eml_scalar_eg(chartInstance);
      for (c67_i58 = 0; c67_i58 < 2; c67_i58++) {
        c67_weight[c67_i58] = 0.0;
      }

      for (c67_i59 = 0; c67_i59 < 2; c67_i59++) {
        c67_weight[c67_i59] = 0.0;
      }

      for (c67_i60 = 0; c67_i60 < 2; c67_i60++) {
        c67_C[c67_i60] = c67_weight[c67_i60];
      }

      for (c67_i61 = 0; c67_i61 < 2; c67_i61++) {
        c67_weight[c67_i61] = c67_C[c67_i61];
      }

      c67_threshold(chartInstance);
      for (c67_i62 = 0; c67_i62 < 2; c67_i62++) {
        c67_C[c67_i62] = c67_weight[c67_i62];
      }

      for (c67_i63 = 0; c67_i63 < 2; c67_i63++) {
        c67_weight[c67_i63] = c67_C[c67_i63];
      }

      for (c67_i64 = 0; c67_i64 < 2; c67_i64++) {
        c67_weight[c67_i64] = 0.0;
        c67_i65 = 0;
        for (c67_i66 = 0; c67_i66 < 2; c67_i66++) {
          c67_weight[c67_i64] += c67_a[c67_i65 + c67_i64] * c67_b[c67_i66];
          c67_i65 += 2;
        }
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 13);
    c67_A = c67_b_u[0] + c67_b_u[1];
    c67_u_LA_R = c67_rdivide(chartInstance, c67_A, 2.0);
    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 14);
    c67_u_LS_R = c67_b_u[1] - c67_b_u[0];
    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 15);
    c67_b_A = c67_b_u[3] + c67_b_u[4];
    c67_u_LA_L = c67_rdivide(chartInstance, c67_b_A, 2.0);
    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 16);
    c67_u_LS_L = c67_b_u[4] - c67_b_u[3];
    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 18);
    c67_LA_LS_Revised_Saturation(chartInstance, c67_u_LS_R, c67_u_LA_R,
      c67_weight[0], -c67_b_sat[0], c67_b_sat[0], -c67_b_sat[1], c67_b_sat[1],
      c67_dv1);
    for (c67_i67 = 0; c67_i67 < 2; c67_i67++) {
      c67_uR[c67_i67] = c67_dv1[c67_i67];
    }

    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 19);
    c67_LA_LS_Revised_Saturation(chartInstance, c67_u_LS_L, c67_u_LA_L,
      c67_weight[1], -c67_b_sat[0], c67_b_sat[0], -c67_b_sat[1], c67_b_sat[1],
      c67_dv2);
    for (c67_i68 = 0; c67_i68 < 2; c67_i68++) {
      c67_uL[c67_i68] = c67_dv2[c67_i68];
    }

    _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 20);
    for (c67_i69 = 0; c67_i69 < 2; c67_i69++) {
      c67_b_u_sat[c67_i69] = c67_uR[c67_i69];
    }

    c67_b_u_sat[2] = c67_b_u[2];
    for (c67_i70 = 0; c67_i70 < 2; c67_i70++) {
      c67_b_u_sat[c67_i70 + 3] = c67_uL[c67_i70];
    }

    c67_b_u_sat[5] = c67_b_u[5];
  }

  _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 23);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 1,
        c67_b_ControlState.ControllerMode, 3.0, -1, 5U,
        c67_b_ControlState.ControllerMode >= 3.0))) {
    if (CV_EML_COND(0, 1, 1, c67_b_ControlParams.Saturation.UseKASaturation !=
                    0.0)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 2, true);
      _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 26);
      for (c67_i71 = 0; c67_i71 < 36; c67_i71++) {
        c67_T0[c67_i71] = c67_dv3[c67_i71];
      }

      _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 27);
      if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 2,
            c67_b_ControlState.StanceLeg, 1.0, -1, 0U,
            c67_b_ControlState.StanceLeg == 1.0))) {
        _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 28);
        for (c67_i72 = 0; c67_i72 < 6; c67_i72++) {
          for (c67_i73 = 0; c67_i73 < 6; c67_i73++) {
            c67_b_T0[c67_i73 + 6 * c67_i72] = c67_T0[c67_iv0[c67_i73] + 6 *
              c67_i72];
          }
        }

        c67_i74 = 0;
        for (c67_i75 = 0; c67_i75 < 6; c67_i75++) {
          for (c67_i76 = 0; c67_i76 < 6; c67_i76++) {
            c67_T0[c67_i76 + c67_i74] = c67_b_T0[c67_i76 + c67_i74];
          }

          c67_i74 += 6;
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 31);
      for (c67_i77 = 0; c67_i77 < 36; c67_i77++) {
        c67_b_a[c67_i77] = c67_T0[c67_i77];
      }

      for (c67_i78 = 0; c67_i78 < 6; c67_i78++) {
        c67_b_b[c67_i78] = c67_b_u_sat[c67_i78];
      }

      c67_b_eml_scalar_eg(chartInstance);
      c67_b_eml_scalar_eg(chartInstance);
      for (c67_i79 = 0; c67_i79 < 6; c67_i79++) {
        c67_u0[c67_i79] = 0.0;
      }

      for (c67_i80 = 0; c67_i80 < 6; c67_i80++) {
        c67_u0[c67_i80] = 0.0;
      }

      for (c67_i81 = 0; c67_i81 < 6; c67_i81++) {
        c67_b_C[c67_i81] = c67_u0[c67_i81];
      }

      for (c67_i82 = 0; c67_i82 < 6; c67_i82++) {
        c67_u0[c67_i82] = c67_b_C[c67_i82];
      }

      c67_threshold(chartInstance);
      for (c67_i83 = 0; c67_i83 < 6; c67_i83++) {
        c67_b_C[c67_i83] = c67_u0[c67_i83];
      }

      for (c67_i84 = 0; c67_i84 < 6; c67_i84++) {
        c67_u0[c67_i84] = c67_b_C[c67_i84];
      }

      for (c67_i85 = 0; c67_i85 < 6; c67_i85++) {
        c67_u0[c67_i85] = 0.0;
        c67_i86 = 0;
        for (c67_i87 = 0; c67_i87 < 6; c67_i87++) {
          c67_u0[c67_i85] += c67_b_a[c67_i86 + c67_i85] * c67_b_b[c67_i87];
          c67_i86 += 6;
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 32);
      c67_deltaS = c67_b_ControlParams.Saturation.KASaturationS2 -
        c67_b_ControlParams.Saturation.KASaturationS1;
      _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 33);
      c67_varargin_1 = c67_deltaS;
      c67_varargin_2 = c67_varargin_1;
      c67_x = c67_varargin_2;
      c67_b_x = c67_x;
      c67_c_eml_scalar_eg(chartInstance);
      c67_xk = c67_b_x;
      c67_c_x = c67_xk;
      c67_c_eml_scalar_eg(chartInstance);
      c67_deltaS = muDoubleScalarMin(c67_c_x, 1.0);
      _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 34);
      if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 3, c67_b_s,
            c67_b_ControlParams.Saturation.KASaturationS1, -1, 2U, c67_b_s <
            c67_b_ControlParams.Saturation.KASaturationS1))) {
        _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 35);
        c67_KASaturationLim = c67_b_ControlParams.Saturation.KASaturationEarly;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 36);
        if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 4, c67_b_s,
              c67_b_ControlParams.Saturation.KASaturationS2, -1, 2U, c67_b_s <
              c67_b_ControlParams.Saturation.KASaturationS2))) {
          _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 37);
          c67_c_a[0] = c67_b_ControlParams.Saturation.KASaturationS2 - c67_b_s;
          c67_c_a[1] = c67_b_s - c67_b_ControlParams.Saturation.KASaturationS1;
          c67_b[0] = c67_b_ControlParams.Saturation.KASaturationEarly;
          c67_b[1] = c67_b_ControlParams.Saturation.KASaturationMax;
          for (c67_i88 = 0; c67_i88 < 2; c67_i88++) {
            c67_d_a[c67_i88] = c67_c_a[c67_i88];
          }

          for (c67_i89 = 0; c67_i89 < 2; c67_i89++) {
            c67_c_b[c67_i89] = c67_b[c67_i89];
          }

          c67_y = c67_eml_xdotu(chartInstance, c67_d_a, c67_c_b);
          c67_c_A = c67_y;
          c67_B = c67_deltaS;
          c67_KASaturationLim = c67_rdivide(chartInstance, c67_c_A, c67_B);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 40);
          c67_KASaturationLim = c67_b_ControlParams.Saturation.KASaturationMax;
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 42);
      c67_b_varargin_1 = c67_u0[2];
      c67_b_varargin_2 = c67_KASaturationLim;
      c67_c_varargin_2 = c67_b_varargin_1;
      c67_varargin_3 = c67_b_varargin_2;
      c67_d_x = c67_c_varargin_2;
      c67_b_y = c67_varargin_3;
      c67_e_x = c67_d_x;
      c67_c_y = c67_b_y;
      c67_c_eml_scalar_eg(chartInstance);
      c67_b_xk = c67_e_x;
      c67_yk = c67_c_y;
      c67_f_x = c67_b_xk;
      c67_d_y = c67_yk;
      c67_c_eml_scalar_eg(chartInstance);
      c67_minval = muDoubleScalarMin(c67_f_x, c67_d_y);
      c67_c_varargin_1 = -c67_KASaturationLim;
      c67_d_varargin_2 = c67_minval;
      c67_e_varargin_2 = c67_c_varargin_1;
      c67_b_varargin_3 = c67_d_varargin_2;
      c67_g_x = c67_e_varargin_2;
      c67_e_y = c67_b_varargin_3;
      c67_h_x = c67_g_x;
      c67_f_y = c67_e_y;
      c67_c_eml_scalar_eg(chartInstance);
      c67_c_xk = c67_h_x;
      c67_b_yk = c67_f_y;
      c67_i_x = c67_c_xk;
      c67_g_y = c67_b_yk;
      c67_c_eml_scalar_eg(chartInstance);
      c67_maxval = muDoubleScalarMax(c67_i_x, c67_g_y);
      c67_u0[2] = c67_maxval;
      _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, 43);
      for (c67_i90 = 0; c67_i90 < 36; c67_i90++) {
        c67_b_a[c67_i90] = c67_T0[c67_i90];
      }

      for (c67_i91 = 0; c67_i91 < 6; c67_i91++) {
        c67_b_b[c67_i91] = c67_u0[c67_i91];
      }

      c67_b_eml_matlab_zgetrf(chartInstance, c67_b_a, c67_ipiv, &c67_info);
      c67_b_info = c67_info;
      c67_c_info = c67_b_info;
      c67_d_info = c67_c_info;
      if (c67_d_info > 0) {
        c67_eml_warning(chartInstance);
      }

      c67_b_eml_scalar_eg(chartInstance);
      for (c67_i92 = 0; c67_i92 < 6; c67_i92++) {
        c67_b_u_sat[c67_i92] = c67_b_b[c67_i92];
      }

      c67_eml_switch_helper(chartInstance);
      for (c67_xi = 1; c67_xi < 6; c67_xi++) {
        c67_b_xi = c67_xi;
        if (c67_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
             ("", (real_T)c67_b_xi), 1, 6, 1, 0) - 1] != c67_b_xi) {
          c67_ip = c67_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_b_xi), 1, 6, 1, 0) - 1];
          c67_temp = c67_b_u_sat[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_b_xi), 1, 6, 1, 0) - 1];
          c67_b_u_sat[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_b_xi), 1, 6, 1, 0) - 1] =
            c67_b_u_sat[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_ip), 1, 6, 1, 0) - 1];
          c67_b_u_sat[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_ip), 1, 6, 1, 0) - 1] = c67_temp;
        }
      }

      for (c67_i93 = 0; c67_i93 < 6; c67_i93++) {
        c67_b_b[c67_i93] = c67_b_u_sat[c67_i93];
      }

      for (c67_i94 = 0; c67_i94 < 36; c67_i94++) {
        c67_e_a[c67_i94] = c67_b_a[c67_i94];
      }

      c67_c_eml_xtrsm(chartInstance, c67_e_a, c67_b_b);
      for (c67_i95 = 0; c67_i95 < 6; c67_i95++) {
        c67_b_u_sat[c67_i95] = c67_b_b[c67_i95];
      }

      for (c67_i96 = 0; c67_i96 < 6; c67_i96++) {
        c67_b_b[c67_i96] = c67_b_u_sat[c67_i96];
      }

      for (c67_i97 = 0; c67_i97 < 36; c67_i97++) {
        c67_f_a[c67_i97] = c67_b_a[c67_i97];
      }

      c67_d_eml_xtrsm(chartInstance, c67_f_a, c67_b_b);
      for (c67_i98 = 0; c67_i98 < 6; c67_i98++) {
        c67_b_u_sat[c67_i98] = c67_b_b[c67_i98];
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 2, false);
  }

  _SFD_EML_CALL(0U, chartInstance->c67_sfEvent, -43);
  _SFD_SYMBOL_SCOPE_POP();
  for (c67_i99 = 0; c67_i99 < 6; c67_i99++) {
    (*chartInstance->c67_u_sat)[c67_i99] = c67_b_u_sat[c67_i99];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 9U, chartInstance->c67_sfEvent);
}

static void initSimStructsc67_DDA2D_OSU3Dv2(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c67_LA_LS_Revised_Saturation(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c67_u_LS, real_T c67_u_LA, real_T c67_w, real_T
  c67_u1_min, real_T c67_u1_max, real_T c67_u2_min, real_T c67_u2_max, real_T
  c67_u_opt[2])
{
  uint32_T c67_debug_family_var_map[32];
  real_T c67_u_opt_1[2];
  real_T c67_L_opt_1[4];
  real_T c67_u_opt_2[2];
  real_T c67_L_opt_2[4];
  real_T c67_u_opt_3[2];
  real_T c67_L_opt_3[4];
  real_T c67_u_opt_4[2];
  real_T c67_L_opt_4[4];
  real_T c67_u_opt_5[2];
  real_T c67_L_opt_5[4];
  real_T c67_u_opt_6[2];
  real_T c67_L_opt_6[4];
  real_T c67_u_opt_7[2];
  real_T c67_L_opt_7[4];
  real_T c67_u_opt_8[2];
  real_T c67_L_opt_8[4];
  real_T c67_u_opt_9[2];
  real_T c67_L_opt_9[4];
  real_T c67_LB[2];
  real_T c67_UB[2];
  real_T c67_L_opt[4];
  real_T c67_case_n;
  real_T c67_nargin = 7.0;
  real_T c67_nargout = 1.0;
  real_T c67_b_L_opt_1[4];
  real_T c67_b_u_opt_1[2];
  int32_T c67_i100;
  int32_T c67_i101;
  int32_T c67_i102;
  int32_T c67_i103;
  int32_T c67_i104;
  int32_T c67_i105;
  int32_T c67_i106;
  int32_T c67_i107;
  int32_T c67_i108;
  int32_T c67_i109;
  int32_T c67_i110;
  int32_T c67_i111;
  int32_T c67_i112;
  int32_T c67_i113;
  int32_T c67_i114;
  int32_T c67_i115;
  int32_T c67_i116;
  int32_T c67_i117;
  int32_T c67_i118;
  int32_T c67_i119;
  int32_T c67_i120;
  int32_T c67_ixstart;
  real_T c67_mtmp;
  real_T c67_x;
  boolean_T c67_b;
  int32_T c67_ix;
  int32_T c67_b_ix;
  real_T c67_b_x;
  boolean_T c67_b_b;
  int32_T c67_a;
  int32_T c67_b_a;
  int32_T c67_i121;
  int32_T c67_c_a;
  int32_T c67_d_a;
  boolean_T c67_overflow;
  int32_T c67_c_ix;
  real_T c67_e_a;
  real_T c67_c_b;
  boolean_T c67_p;
  real_T c67_b_mtmp;
  real_T c67_d0;
  int32_T c67_i122;
  int32_T c67_b_ixstart;
  real_T c67_c_mtmp;
  real_T c67_c_x;
  boolean_T c67_d_b;
  int32_T c67_d_ix;
  int32_T c67_e_ix;
  real_T c67_d_x;
  boolean_T c67_e_b;
  int32_T c67_f_a;
  int32_T c67_g_a;
  int32_T c67_i123;
  int32_T c67_h_a;
  int32_T c67_i_a;
  boolean_T c67_b_overflow;
  int32_T c67_f_ix;
  real_T c67_j_a;
  real_T c67_f_b;
  boolean_T c67_b_p;
  real_T c67_d_mtmp;
  real_T c67_d1;
  int32_T c67_i124;
  int32_T c67_c_ixstart;
  real_T c67_e_mtmp;
  real_T c67_e_x;
  boolean_T c67_g_b;
  int32_T c67_g_ix;
  int32_T c67_h_ix;
  real_T c67_f_x;
  boolean_T c67_h_b;
  int32_T c67_k_a;
  int32_T c67_l_a;
  int32_T c67_i125;
  int32_T c67_m_a;
  int32_T c67_n_a;
  boolean_T c67_c_overflow;
  int32_T c67_i_ix;
  real_T c67_o_a;
  real_T c67_i_b;
  boolean_T c67_c_p;
  real_T c67_f_mtmp;
  real_T c67_d2;
  int32_T c67_i126;
  int32_T c67_i127;
  int32_T c67_i128;
  int32_T c67_d_ixstart;
  real_T c67_g_mtmp;
  real_T c67_g_x;
  boolean_T c67_j_b;
  int32_T c67_j_ix;
  int32_T c67_k_ix;
  real_T c67_h_x;
  boolean_T c67_k_b;
  int32_T c67_p_a;
  int32_T c67_q_a;
  int32_T c67_i129;
  int32_T c67_r_a;
  int32_T c67_s_a;
  boolean_T c67_d_overflow;
  int32_T c67_l_ix;
  real_T c67_t_a;
  real_T c67_l_b;
  boolean_T c67_d_p;
  real_T c67_h_mtmp;
  real_T c67_d3;
  int32_T c67_i130;
  int32_T c67_e_ixstart;
  real_T c67_i_mtmp;
  real_T c67_i_x;
  boolean_T c67_m_b;
  int32_T c67_m_ix;
  int32_T c67_n_ix;
  real_T c67_j_x;
  boolean_T c67_n_b;
  int32_T c67_u_a;
  int32_T c67_v_a;
  int32_T c67_i131;
  int32_T c67_w_a;
  int32_T c67_x_a;
  boolean_T c67_e_overflow;
  int32_T c67_o_ix;
  real_T c67_y_a;
  real_T c67_o_b;
  boolean_T c67_e_p;
  real_T c67_j_mtmp;
  real_T c67_d4;
  int32_T c67_i132;
  int32_T c67_f_ixstart;
  real_T c67_k_mtmp;
  real_T c67_k_x;
  boolean_T c67_p_b;
  int32_T c67_p_ix;
  int32_T c67_q_ix;
  real_T c67_l_x;
  boolean_T c67_q_b;
  int32_T c67_ab_a;
  int32_T c67_bb_a;
  int32_T c67_i133;
  int32_T c67_cb_a;
  int32_T c67_db_a;
  boolean_T c67_f_overflow;
  int32_T c67_r_ix;
  real_T c67_eb_a;
  real_T c67_r_b;
  boolean_T c67_f_p;
  real_T c67_l_mtmp;
  real_T c67_d5;
  int32_T c67_i134;
  int32_T c67_i135;
  int32_T c67_i136;
  int32_T c67_g_ixstart;
  real_T c67_m_mtmp;
  real_T c67_m_x;
  boolean_T c67_s_b;
  int32_T c67_s_ix;
  int32_T c67_t_ix;
  real_T c67_n_x;
  boolean_T c67_t_b;
  int32_T c67_fb_a;
  int32_T c67_gb_a;
  int32_T c67_i137;
  int32_T c67_hb_a;
  int32_T c67_ib_a;
  boolean_T c67_g_overflow;
  int32_T c67_u_ix;
  real_T c67_jb_a;
  real_T c67_u_b;
  boolean_T c67_g_p;
  real_T c67_n_mtmp;
  real_T c67_d6;
  int32_T c67_i138;
  int32_T c67_h_ixstart;
  real_T c67_o_mtmp;
  real_T c67_o_x;
  boolean_T c67_v_b;
  int32_T c67_v_ix;
  int32_T c67_w_ix;
  real_T c67_p_x;
  boolean_T c67_w_b;
  int32_T c67_kb_a;
  int32_T c67_lb_a;
  int32_T c67_i139;
  int32_T c67_mb_a;
  int32_T c67_nb_a;
  boolean_T c67_h_overflow;
  int32_T c67_x_ix;
  real_T c67_ob_a;
  real_T c67_x_b;
  boolean_T c67_h_p;
  real_T c67_p_mtmp;
  real_T c67_d7;
  int32_T c67_i140;
  int32_T c67_i_ixstart;
  real_T c67_q_mtmp;
  real_T c67_q_x;
  boolean_T c67_y_b;
  int32_T c67_y_ix;
  int32_T c67_ab_ix;
  real_T c67_r_x;
  boolean_T c67_ab_b;
  int32_T c67_pb_a;
  int32_T c67_qb_a;
  int32_T c67_i141;
  int32_T c67_rb_a;
  int32_T c67_sb_a;
  boolean_T c67_i_overflow;
  int32_T c67_bb_ix;
  real_T c67_tb_a;
  real_T c67_bb_b;
  boolean_T c67_i_p;
  real_T c67_r_mtmp;
  real_T c67_d8;
  int32_T c67_i142;
  int32_T c67_i143;
  int32_T c67_i144;
  int32_T c67_j_ixstart;
  real_T c67_s_mtmp;
  real_T c67_s_x;
  boolean_T c67_cb_b;
  int32_T c67_cb_ix;
  int32_T c67_db_ix;
  real_T c67_t_x;
  boolean_T c67_db_b;
  int32_T c67_ub_a;
  int32_T c67_vb_a;
  int32_T c67_i145;
  int32_T c67_wb_a;
  int32_T c67_xb_a;
  boolean_T c67_j_overflow;
  int32_T c67_eb_ix;
  real_T c67_yb_a;
  real_T c67_eb_b;
  boolean_T c67_j_p;
  real_T c67_t_mtmp;
  real_T c67_d9;
  int32_T c67_i146;
  int32_T c67_k_ixstart;
  real_T c67_u_mtmp;
  real_T c67_u_x;
  boolean_T c67_fb_b;
  int32_T c67_fb_ix;
  int32_T c67_gb_ix;
  real_T c67_v_x;
  boolean_T c67_gb_b;
  int32_T c67_ac_a;
  int32_T c67_bc_a;
  int32_T c67_i147;
  int32_T c67_cc_a;
  int32_T c67_dc_a;
  boolean_T c67_k_overflow;
  int32_T c67_hb_ix;
  real_T c67_ec_a;
  real_T c67_hb_b;
  boolean_T c67_k_p;
  real_T c67_v_mtmp;
  real_T c67_d10;
  int32_T c67_i148;
  int32_T c67_l_ixstart;
  real_T c67_w_mtmp;
  real_T c67_w_x;
  boolean_T c67_ib_b;
  int32_T c67_ib_ix;
  int32_T c67_jb_ix;
  real_T c67_x_x;
  boolean_T c67_jb_b;
  int32_T c67_fc_a;
  int32_T c67_gc_a;
  int32_T c67_i149;
  int32_T c67_hc_a;
  int32_T c67_ic_a;
  boolean_T c67_l_overflow;
  int32_T c67_kb_ix;
  real_T c67_jc_a;
  real_T c67_kb_b;
  boolean_T c67_l_p;
  real_T c67_x_mtmp;
  real_T c67_d11;
  int32_T c67_i150;
  int32_T c67_i151;
  int32_T c67_i152;
  int32_T c67_m_ixstart;
  real_T c67_y_mtmp;
  real_T c67_y_x;
  boolean_T c67_lb_b;
  int32_T c67_lb_ix;
  int32_T c67_mb_ix;
  real_T c67_ab_x;
  boolean_T c67_mb_b;
  int32_T c67_kc_a;
  int32_T c67_lc_a;
  int32_T c67_i153;
  int32_T c67_mc_a;
  int32_T c67_nc_a;
  boolean_T c67_m_overflow;
  int32_T c67_nb_ix;
  real_T c67_oc_a;
  real_T c67_nb_b;
  boolean_T c67_m_p;
  real_T c67_ab_mtmp;
  real_T c67_d12;
  int32_T c67_i154;
  int32_T c67_n_ixstart;
  real_T c67_bb_mtmp;
  real_T c67_bb_x;
  boolean_T c67_ob_b;
  int32_T c67_ob_ix;
  int32_T c67_pb_ix;
  real_T c67_cb_x;
  boolean_T c67_pb_b;
  int32_T c67_pc_a;
  int32_T c67_qc_a;
  int32_T c67_i155;
  int32_T c67_rc_a;
  int32_T c67_sc_a;
  boolean_T c67_n_overflow;
  int32_T c67_qb_ix;
  real_T c67_tc_a;
  real_T c67_qb_b;
  boolean_T c67_n_p;
  real_T c67_cb_mtmp;
  real_T c67_d13;
  int32_T c67_i156;
  int32_T c67_o_ixstart;
  real_T c67_db_mtmp;
  real_T c67_db_x;
  boolean_T c67_rb_b;
  int32_T c67_rb_ix;
  int32_T c67_sb_ix;
  real_T c67_eb_x;
  boolean_T c67_sb_b;
  int32_T c67_uc_a;
  int32_T c67_vc_a;
  int32_T c67_i157;
  int32_T c67_wc_a;
  int32_T c67_xc_a;
  boolean_T c67_o_overflow;
  int32_T c67_tb_ix;
  real_T c67_yc_a;
  real_T c67_tb_b;
  boolean_T c67_o_p;
  real_T c67_eb_mtmp;
  real_T c67_d14;
  int32_T c67_i158;
  int32_T c67_i159;
  int32_T c67_i160;
  int32_T c67_p_ixstart;
  real_T c67_fb_mtmp;
  real_T c67_fb_x;
  boolean_T c67_ub_b;
  int32_T c67_ub_ix;
  int32_T c67_vb_ix;
  real_T c67_gb_x;
  boolean_T c67_vb_b;
  int32_T c67_ad_a;
  int32_T c67_bd_a;
  int32_T c67_i161;
  int32_T c67_cd_a;
  int32_T c67_dd_a;
  boolean_T c67_p_overflow;
  int32_T c67_wb_ix;
  real_T c67_ed_a;
  real_T c67_wb_b;
  boolean_T c67_p_p;
  real_T c67_gb_mtmp;
  real_T c67_d15;
  int32_T c67_i162;
  int32_T c67_q_ixstart;
  real_T c67_hb_mtmp;
  real_T c67_hb_x;
  boolean_T c67_xb_b;
  int32_T c67_xb_ix;
  int32_T c67_yb_ix;
  real_T c67_ib_x;
  boolean_T c67_yb_b;
  int32_T c67_fd_a;
  int32_T c67_gd_a;
  int32_T c67_i163;
  int32_T c67_hd_a;
  int32_T c67_id_a;
  boolean_T c67_q_overflow;
  int32_T c67_ac_ix;
  real_T c67_jd_a;
  real_T c67_ac_b;
  boolean_T c67_q_p;
  real_T c67_ib_mtmp;
  real_T c67_d16;
  int32_T c67_i164;
  int32_T c67_r_ixstart;
  real_T c67_jb_mtmp;
  real_T c67_jb_x;
  boolean_T c67_bc_b;
  int32_T c67_bc_ix;
  int32_T c67_cc_ix;
  real_T c67_kb_x;
  boolean_T c67_cc_b;
  int32_T c67_kd_a;
  int32_T c67_ld_a;
  int32_T c67_i165;
  int32_T c67_md_a;
  int32_T c67_nd_a;
  boolean_T c67_r_overflow;
  int32_T c67_dc_ix;
  real_T c67_od_a;
  real_T c67_dc_b;
  boolean_T c67_r_p;
  real_T c67_kb_mtmp;
  real_T c67_d17;
  int32_T c67_i166;
  int32_T c67_i167;
  int32_T c67_i168;
  int32_T c67_s_ixstart;
  real_T c67_lb_mtmp;
  real_T c67_lb_x;
  boolean_T c67_ec_b;
  int32_T c67_ec_ix;
  int32_T c67_fc_ix;
  real_T c67_mb_x;
  boolean_T c67_fc_b;
  int32_T c67_pd_a;
  int32_T c67_qd_a;
  int32_T c67_i169;
  int32_T c67_rd_a;
  int32_T c67_sd_a;
  boolean_T c67_s_overflow;
  int32_T c67_gc_ix;
  real_T c67_td_a;
  real_T c67_gc_b;
  boolean_T c67_s_p;
  real_T c67_mb_mtmp;
  real_T c67_d18;
  int32_T c67_i170;
  int32_T c67_t_ixstart;
  real_T c67_nb_mtmp;
  real_T c67_nb_x;
  boolean_T c67_hc_b;
  int32_T c67_hc_ix;
  int32_T c67_ic_ix;
  real_T c67_ob_x;
  boolean_T c67_ic_b;
  int32_T c67_ud_a;
  int32_T c67_vd_a;
  int32_T c67_i171;
  int32_T c67_wd_a;
  int32_T c67_xd_a;
  boolean_T c67_t_overflow;
  int32_T c67_jc_ix;
  real_T c67_yd_a;
  real_T c67_jc_b;
  boolean_T c67_t_p;
  real_T c67_ob_mtmp;
  real_T c67_d19;
  int32_T c67_i172;
  int32_T c67_u_ixstart;
  real_T c67_pb_mtmp;
  real_T c67_pb_x;
  boolean_T c67_kc_b;
  int32_T c67_kc_ix;
  int32_T c67_lc_ix;
  real_T c67_qb_x;
  boolean_T c67_lc_b;
  int32_T c67_ae_a;
  int32_T c67_be_a;
  int32_T c67_i173;
  int32_T c67_ce_a;
  int32_T c67_de_a;
  boolean_T c67_u_overflow;
  int32_T c67_mc_ix;
  real_T c67_ee_a;
  real_T c67_mc_b;
  boolean_T c67_u_p;
  real_T c67_qb_mtmp;
  real_T c67_d20;
  int32_T c67_i174;
  int32_T c67_i175;
  int32_T c67_i176;
  int32_T c67_v_ixstart;
  real_T c67_rb_mtmp;
  real_T c67_rb_x;
  boolean_T c67_nc_b;
  int32_T c67_nc_ix;
  int32_T c67_oc_ix;
  real_T c67_sb_x;
  boolean_T c67_oc_b;
  int32_T c67_fe_a;
  int32_T c67_ge_a;
  int32_T c67_i177;
  int32_T c67_he_a;
  int32_T c67_ie_a;
  boolean_T c67_v_overflow;
  int32_T c67_pc_ix;
  real_T c67_je_a;
  real_T c67_pc_b;
  boolean_T c67_v_p;
  real_T c67_sb_mtmp;
  real_T c67_d21;
  int32_T c67_i178;
  int32_T c67_w_ixstart;
  real_T c67_tb_mtmp;
  real_T c67_tb_x;
  boolean_T c67_qc_b;
  int32_T c67_qc_ix;
  int32_T c67_rc_ix;
  real_T c67_ub_x;
  boolean_T c67_rc_b;
  int32_T c67_ke_a;
  int32_T c67_le_a;
  int32_T c67_i179;
  int32_T c67_me_a;
  int32_T c67_ne_a;
  boolean_T c67_w_overflow;
  int32_T c67_sc_ix;
  real_T c67_oe_a;
  real_T c67_sc_b;
  boolean_T c67_w_p;
  real_T c67_ub_mtmp;
  real_T c67_d22;
  int32_T c67_i180;
  int32_T c67_x_ixstart;
  real_T c67_vb_mtmp;
  real_T c67_vb_x;
  boolean_T c67_tc_b;
  int32_T c67_tc_ix;
  int32_T c67_uc_ix;
  real_T c67_wb_x;
  boolean_T c67_uc_b;
  int32_T c67_pe_a;
  int32_T c67_qe_a;
  int32_T c67_i181;
  int32_T c67_re_a;
  int32_T c67_se_a;
  boolean_T c67_x_overflow;
  int32_T c67_vc_ix;
  real_T c67_te_a;
  real_T c67_vc_b;
  boolean_T c67_x_p;
  real_T c67_wb_mtmp;
  real_T c67_d23;
  int32_T c67_i182;
  int32_T c67_i183;
  int32_T c67_i184;
  int32_T c67_y_ixstart;
  real_T c67_xb_mtmp;
  real_T c67_xb_x;
  boolean_T c67_wc_b;
  int32_T c67_wc_ix;
  int32_T c67_xc_ix;
  real_T c67_yb_x;
  boolean_T c67_xc_b;
  int32_T c67_ue_a;
  int32_T c67_ve_a;
  int32_T c67_i185;
  int32_T c67_we_a;
  int32_T c67_xe_a;
  boolean_T c67_y_overflow;
  int32_T c67_yc_ix;
  real_T c67_ye_a;
  real_T c67_yc_b;
  boolean_T c67_y_p;
  real_T c67_yb_mtmp;
  real_T c67_d24;
  int32_T c67_i186;
  int32_T c67_ab_ixstart;
  real_T c67_ac_mtmp;
  real_T c67_ac_x;
  boolean_T c67_ad_b;
  int32_T c67_ad_ix;
  int32_T c67_bd_ix;
  real_T c67_bc_x;
  boolean_T c67_bd_b;
  int32_T c67_af_a;
  int32_T c67_bf_a;
  int32_T c67_i187;
  int32_T c67_cf_a;
  int32_T c67_df_a;
  boolean_T c67_ab_overflow;
  int32_T c67_cd_ix;
  real_T c67_ef_a;
  real_T c67_cd_b;
  boolean_T c67_ab_p;
  real_T c67_bc_mtmp;
  real_T c67_d25;
  int32_T c67_i188;
  int32_T c67_bb_ixstart;
  real_T c67_cc_mtmp;
  real_T c67_cc_x;
  boolean_T c67_dd_b;
  int32_T c67_dd_ix;
  int32_T c67_ed_ix;
  real_T c67_dc_x;
  boolean_T c67_ed_b;
  int32_T c67_ff_a;
  int32_T c67_gf_a;
  int32_T c67_i189;
  int32_T c67_hf_a;
  int32_T c67_if_a;
  boolean_T c67_bb_overflow;
  int32_T c67_fd_ix;
  real_T c67_jf_a;
  real_T c67_fd_b;
  boolean_T c67_bb_p;
  real_T c67_dc_mtmp;
  real_T c67_d26;
  int32_T c67_i190;
  int32_T c67_i191;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;
  boolean_T guard6 = false;
  boolean_T guard7 = false;
  boolean_T guard8 = false;
  boolean_T guard9 = false;
  boolean_T guard10 = false;
  boolean_T guard11 = false;
  boolean_T guard12 = false;
  boolean_T guard13 = false;
  boolean_T guard14 = false;
  boolean_T guard15 = false;
  boolean_T guard16 = false;
  boolean_T guard17 = false;
  boolean_T guard18 = false;
  boolean_T exitg1;
  boolean_T exitg2;
  boolean_T exitg3;
  boolean_T exitg4;
  boolean_T exitg5;
  boolean_T exitg6;
  boolean_T exitg7;
  boolean_T exitg8;
  boolean_T exitg9;
  boolean_T exitg10;
  boolean_T exitg11;
  boolean_T exitg12;
  boolean_T exitg13;
  boolean_T exitg14;
  boolean_T exitg15;
  boolean_T exitg16;
  boolean_T exitg17;
  boolean_T exitg18;
  boolean_T exitg19;
  boolean_T exitg20;
  boolean_T exitg21;
  boolean_T exitg22;
  boolean_T exitg23;
  boolean_T exitg24;
  boolean_T exitg25;
  boolean_T exitg26;
  boolean_T exitg27;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 32U, 32U, c67_k_debug_family_names,
    c67_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt_1, 0U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt_1, 1U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt_2, 2U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt_2, 3U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt_3, 4U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt_3, 5U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt_4, 6U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt_4, 7U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt_5, 8U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt_5, 9U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt_6, 10U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt_6, 11U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt_7, 12U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt_7, 13U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt_8, 14U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt_8, 15U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt_9, 16U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt_9, 17U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_LB, 18U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_UB, 19U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt, 20U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_case_n, 21U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargin, 22U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargout, 23U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LS, 24U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LA, 25U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_w, 26U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u1_min, 27U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u1_max, 28U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u2_min, 29U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u2_max, 30U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt, 31U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 30);
  c67_LA_LS_Revised_Saturation_Case_1(chartInstance, c67_u_LS, c67_u_LA, c67_w,
    c67_b_u_opt_1, c67_b_L_opt_1);
  for (c67_i100 = 0; c67_i100 < 2; c67_i100++) {
    c67_u_opt_1[c67_i100] = c67_b_u_opt_1[c67_i100];
  }

  for (c67_i101 = 0; c67_i101 < 4; c67_i101++) {
    c67_L_opt_1[c67_i101] = c67_b_L_opt_1[c67_i101];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 31);
  c67_LA_LS_Revised_Saturation_Case_2(chartInstance, c67_u_LS, c67_u_LA, c67_w,
    c67_u1_min, c67_b_u_opt_1, c67_b_L_opt_1);
  for (c67_i102 = 0; c67_i102 < 2; c67_i102++) {
    c67_u_opt_2[c67_i102] = c67_b_u_opt_1[c67_i102];
  }

  for (c67_i103 = 0; c67_i103 < 4; c67_i103++) {
    c67_L_opt_2[c67_i103] = c67_b_L_opt_1[c67_i103];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 32);
  c67_LA_LS_Revised_Saturation_Case_3(chartInstance, c67_u_LS, c67_u_LA, c67_w,
    c67_u1_max, c67_b_u_opt_1, c67_b_L_opt_1);
  for (c67_i104 = 0; c67_i104 < 2; c67_i104++) {
    c67_u_opt_3[c67_i104] = c67_b_u_opt_1[c67_i104];
  }

  for (c67_i105 = 0; c67_i105 < 4; c67_i105++) {
    c67_L_opt_3[c67_i105] = c67_b_L_opt_1[c67_i105];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 33);
  c67_LA_LS_Revised_Saturation_Case_4(chartInstance, c67_u_LS, c67_u_LA, c67_w,
    c67_u2_min, c67_b_u_opt_1, c67_b_L_opt_1);
  for (c67_i106 = 0; c67_i106 < 2; c67_i106++) {
    c67_u_opt_4[c67_i106] = c67_b_u_opt_1[c67_i106];
  }

  for (c67_i107 = 0; c67_i107 < 4; c67_i107++) {
    c67_L_opt_4[c67_i107] = c67_b_L_opt_1[c67_i107];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 34);
  c67_LA_LS_Revised_Saturation_Case_5(chartInstance, c67_u_LS, c67_u_LA, c67_w,
    c67_u2_max, c67_b_u_opt_1, c67_b_L_opt_1);
  for (c67_i108 = 0; c67_i108 < 2; c67_i108++) {
    c67_u_opt_5[c67_i108] = c67_b_u_opt_1[c67_i108];
  }

  for (c67_i109 = 0; c67_i109 < 4; c67_i109++) {
    c67_L_opt_5[c67_i109] = c67_b_L_opt_1[c67_i109];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 35);
  c67_LA_LS_Revised_Saturation_Case_6(chartInstance, c67_u_LS, c67_u_LA, c67_w,
    c67_u1_min, c67_u2_min, c67_b_u_opt_1, c67_b_L_opt_1);
  for (c67_i110 = 0; c67_i110 < 2; c67_i110++) {
    c67_u_opt_6[c67_i110] = c67_b_u_opt_1[c67_i110];
  }

  for (c67_i111 = 0; c67_i111 < 4; c67_i111++) {
    c67_L_opt_6[c67_i111] = c67_b_L_opt_1[c67_i111];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 36);
  c67_LA_LS_Revised_Saturation_Case_7(chartInstance, c67_u_LS, c67_u_LA, c67_w,
    c67_u1_min, c67_u2_max, c67_b_u_opt_1, c67_b_L_opt_1);
  for (c67_i112 = 0; c67_i112 < 2; c67_i112++) {
    c67_u_opt_7[c67_i112] = c67_b_u_opt_1[c67_i112];
  }

  for (c67_i113 = 0; c67_i113 < 4; c67_i113++) {
    c67_L_opt_7[c67_i113] = c67_b_L_opt_1[c67_i113];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 37);
  c67_LA_LS_Revised_Saturation_Case_8(chartInstance, c67_u_LS, c67_u_LA, c67_w,
    c67_u1_max, c67_u2_min, c67_b_u_opt_1, c67_b_L_opt_1);
  for (c67_i114 = 0; c67_i114 < 2; c67_i114++) {
    c67_u_opt_8[c67_i114] = c67_b_u_opt_1[c67_i114];
  }

  for (c67_i115 = 0; c67_i115 < 4; c67_i115++) {
    c67_L_opt_8[c67_i115] = c67_b_L_opt_1[c67_i115];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 38);
  c67_LA_LS_Revised_Saturation_Case_9(chartInstance, c67_u_LS, c67_u_LA, c67_w,
    c67_u1_max, c67_u2_max, c67_b_u_opt_1, c67_b_L_opt_1);
  for (c67_i116 = 0; c67_i116 < 2; c67_i116++) {
    c67_u_opt_9[c67_i116] = c67_b_u_opt_1[c67_i116];
  }

  for (c67_i117 = 0; c67_i117 < 4; c67_i117++) {
    c67_L_opt_9[c67_i117] = c67_b_L_opt_1[c67_i117];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 41);
  c67_LB[0] = c67_u1_min;
  c67_LB[1] = c67_u2_min;
  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 42);
  c67_UB[0] = c67_u1_max;
  c67_UB[1] = c67_u2_max;
  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 45);
  for (c67_i118 = 0; c67_i118 < 2; c67_i118++) {
    c67_u_opt[c67_i118] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 46);
  for (c67_i119 = 0; c67_i119 < 4; c67_i119++) {
    c67_L_opt[c67_i119] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 47);
  c67_case_n = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 49);
  for (c67_i120 = 0; c67_i120 < 2; c67_i120++) {
    c67_b_u_opt_1[c67_i120] = c67_u_opt_1[c67_i120] - c67_UB[c67_i120];
  }

  c67_ixstart = 1;
  c67_mtmp = c67_b_u_opt_1[0];
  c67_x = c67_mtmp;
  c67_b = muDoubleScalarIsNaN(c67_x);
  if (c67_b) {
    c67_eml_switch_helper(chartInstance);
    c67_eml_switch_helper(chartInstance);
    c67_ix = 2;
    exitg27 = false;
    while ((exitg27 == false) && (c67_ix < 3)) {
      c67_b_ix = c67_ix;
      c67_ixstart = c67_b_ix;
      c67_b_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_b_ix), 1, 2, 1, 0) - 1];
      c67_b_b = muDoubleScalarIsNaN(c67_b_x);
      if (!c67_b_b) {
        c67_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_b_ix), 1, 2, 1, 0) - 1];
        exitg27 = true;
      } else {
        c67_ix++;
      }
    }
  }

  if (c67_ixstart < 2) {
    c67_a = c67_ixstart;
    c67_b_a = c67_a + 1;
    c67_i121 = c67_b_a;
    c67_c_a = c67_i121;
    c67_d_a = c67_c_a;
    if (c67_d_a > 2) {
      c67_overflow = false;
    } else {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_overflow = false;
    }

    if (c67_overflow) {
      c67_check_forloop_overflow_error(chartInstance, c67_overflow);
    }

    for (c67_c_ix = c67_i121; c67_c_ix < 3; c67_c_ix++) {
      c67_b_ix = c67_c_ix;
      c67_e_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_b_ix), 1, 2, 1, 0) - 1];
      c67_c_b = c67_mtmp;
      c67_p = (c67_e_a > c67_c_b);
      if (c67_p) {
        c67_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_b_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c67_b_mtmp = c67_mtmp;
  c67_d0 = c67_b_mtmp;
  guard17 = false;
  guard18 = false;
  if (CV_SCRIPT_COND(0, 0, CV_RELATIONAL_EVAL(14U, 0U, 0, c67_d0, 0.0, -1, 3U,
        c67_d0 <= 0.0))) {
    for (c67_i122 = 0; c67_i122 < 2; c67_i122++) {
      c67_b_u_opt_1[c67_i122] = c67_u_opt_1[c67_i122] - c67_LB[c67_i122];
    }

    c67_b_ixstart = 1;
    c67_c_mtmp = c67_b_u_opt_1[0];
    c67_c_x = c67_c_mtmp;
    c67_d_b = muDoubleScalarIsNaN(c67_c_x);
    if (c67_d_b) {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_d_ix = 2;
      exitg26 = false;
      while ((exitg26 == false) && (c67_d_ix < 3)) {
        c67_e_ix = c67_d_ix;
        c67_b_ixstart = c67_e_ix;
        c67_d_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_e_ix), 1, 2, 1, 0) - 1];
        c67_e_b = muDoubleScalarIsNaN(c67_d_x);
        if (!c67_e_b) {
          c67_c_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_e_ix), 1, 2, 1, 0) - 1];
          exitg26 = true;
        } else {
          c67_d_ix++;
        }
      }
    }

    if (c67_b_ixstart < 2) {
      c67_f_a = c67_b_ixstart;
      c67_g_a = c67_f_a + 1;
      c67_i123 = c67_g_a;
      c67_h_a = c67_i123;
      c67_i_a = c67_h_a;
      if (c67_i_a > 2) {
        c67_b_overflow = false;
      } else {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_b_overflow = false;
      }

      if (c67_b_overflow) {
        c67_check_forloop_overflow_error(chartInstance, c67_b_overflow);
      }

      for (c67_f_ix = c67_i123; c67_f_ix < 3; c67_f_ix++) {
        c67_e_ix = c67_f_ix;
        c67_j_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_e_ix), 1, 2, 1, 0) - 1];
        c67_f_b = c67_c_mtmp;
        c67_b_p = (c67_j_a < c67_f_b);
        if (c67_b_p) {
          c67_c_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_e_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c67_d_mtmp = c67_c_mtmp;
    c67_d1 = c67_d_mtmp;
    if (CV_SCRIPT_COND(0, 1, CV_RELATIONAL_EVAL(14U, 0U, 1, c67_d1, 0.0, -1, 5U,
          c67_d1 >= 0.0))) {
      for (c67_i124 = 0; c67_i124 < 4; c67_i124++) {
        c67_b_L_opt_1[c67_i124] = c67_L_opt_1[c67_i124];
      }

      c67_c_ixstart = 1;
      c67_e_mtmp = c67_b_L_opt_1[0];
      c67_e_x = c67_e_mtmp;
      c67_g_b = muDoubleScalarIsNaN(c67_e_x);
      if (c67_g_b) {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_g_ix = 2;
        exitg25 = false;
        while ((exitg25 == false) && (c67_g_ix < 5)) {
          c67_h_ix = c67_g_ix;
          c67_c_ixstart = c67_h_ix;
          c67_f_x = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_h_ix), 1, 4, 1, 0) - 1];
          c67_h_b = muDoubleScalarIsNaN(c67_f_x);
          if (!c67_h_b) {
            c67_e_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_h_ix), 1, 4, 1, 0) - 1];
            exitg25 = true;
          } else {
            c67_g_ix++;
          }
        }
      }

      if (c67_c_ixstart < 4) {
        c67_k_a = c67_c_ixstart;
        c67_l_a = c67_k_a + 1;
        c67_i125 = c67_l_a;
        c67_m_a = c67_i125;
        c67_n_a = c67_m_a;
        if (c67_n_a > 4) {
          c67_c_overflow = false;
        } else {
          c67_eml_switch_helper(chartInstance);
          c67_eml_switch_helper(chartInstance);
          c67_c_overflow = false;
        }

        if (c67_c_overflow) {
          c67_check_forloop_overflow_error(chartInstance, c67_c_overflow);
        }

        for (c67_i_ix = c67_i125; c67_i_ix < 5; c67_i_ix++) {
          c67_h_ix = c67_i_ix;
          c67_o_a = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_h_ix), 1, 4, 1, 0) - 1];
          c67_i_b = c67_e_mtmp;
          c67_c_p = (c67_o_a < c67_i_b);
          if (c67_c_p) {
            c67_e_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_h_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c67_f_mtmp = c67_e_mtmp;
      c67_d2 = c67_f_mtmp;
      if (CV_SCRIPT_COND(0, 2, CV_RELATIONAL_EVAL(14U, 0U, 2, c67_d2, 0.0, -1,
            5U, c67_d2 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 0, true);
        CV_SCRIPT_IF(0, 0, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 50);
        for (c67_i126 = 0; c67_i126 < 2; c67_i126++) {
          c67_u_opt[c67_i126] = c67_u_opt_1[c67_i126];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 51);
        for (c67_i127 = 0; c67_i127 < 4; c67_i127++) {
          c67_L_opt[c67_i127] = c67_L_opt_1[c67_i127];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 52);
        c67_case_n = 1.0;
      } else {
        guard17 = true;
      }
    } else {
      guard18 = true;
    }
  } else {
    guard18 = true;
  }

  if (guard18 == true) {
    guard17 = true;
  }

  if (guard17 == true) {
    CV_SCRIPT_MCDC(0, 0, false);
    CV_SCRIPT_IF(0, 0, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 56);
  for (c67_i128 = 0; c67_i128 < 2; c67_i128++) {
    c67_b_u_opt_1[c67_i128] = c67_u_opt_2[c67_i128] - c67_UB[c67_i128];
  }

  c67_d_ixstart = 1;
  c67_g_mtmp = c67_b_u_opt_1[0];
  c67_g_x = c67_g_mtmp;
  c67_j_b = muDoubleScalarIsNaN(c67_g_x);
  if (c67_j_b) {
    c67_eml_switch_helper(chartInstance);
    c67_eml_switch_helper(chartInstance);
    c67_j_ix = 2;
    exitg24 = false;
    while ((exitg24 == false) && (c67_j_ix < 3)) {
      c67_k_ix = c67_j_ix;
      c67_d_ixstart = c67_k_ix;
      c67_h_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_k_ix), 1, 2, 1, 0) - 1];
      c67_k_b = muDoubleScalarIsNaN(c67_h_x);
      if (!c67_k_b) {
        c67_g_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_k_ix), 1, 2, 1, 0) - 1];
        exitg24 = true;
      } else {
        c67_j_ix++;
      }
    }
  }

  if (c67_d_ixstart < 2) {
    c67_p_a = c67_d_ixstart;
    c67_q_a = c67_p_a + 1;
    c67_i129 = c67_q_a;
    c67_r_a = c67_i129;
    c67_s_a = c67_r_a;
    if (c67_s_a > 2) {
      c67_d_overflow = false;
    } else {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_d_overflow = false;
    }

    if (c67_d_overflow) {
      c67_check_forloop_overflow_error(chartInstance, c67_d_overflow);
    }

    for (c67_l_ix = c67_i129; c67_l_ix < 3; c67_l_ix++) {
      c67_k_ix = c67_l_ix;
      c67_t_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_k_ix), 1, 2, 1, 0) - 1];
      c67_l_b = c67_g_mtmp;
      c67_d_p = (c67_t_a > c67_l_b);
      if (c67_d_p) {
        c67_g_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_k_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c67_h_mtmp = c67_g_mtmp;
  c67_d3 = c67_h_mtmp;
  guard15 = false;
  guard16 = false;
  if (CV_SCRIPT_COND(0, 3, CV_RELATIONAL_EVAL(14U, 0U, 3, c67_d3, 0.0, -1, 3U,
        c67_d3 <= 0.0))) {
    for (c67_i130 = 0; c67_i130 < 2; c67_i130++) {
      c67_b_u_opt_1[c67_i130] = c67_u_opt_2[c67_i130] - c67_LB[c67_i130];
    }

    c67_e_ixstart = 1;
    c67_i_mtmp = c67_b_u_opt_1[0];
    c67_i_x = c67_i_mtmp;
    c67_m_b = muDoubleScalarIsNaN(c67_i_x);
    if (c67_m_b) {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_m_ix = 2;
      exitg23 = false;
      while ((exitg23 == false) && (c67_m_ix < 3)) {
        c67_n_ix = c67_m_ix;
        c67_e_ixstart = c67_n_ix;
        c67_j_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_n_ix), 1, 2, 1, 0) - 1];
        c67_n_b = muDoubleScalarIsNaN(c67_j_x);
        if (!c67_n_b) {
          c67_i_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_n_ix), 1, 2, 1, 0) - 1];
          exitg23 = true;
        } else {
          c67_m_ix++;
        }
      }
    }

    if (c67_e_ixstart < 2) {
      c67_u_a = c67_e_ixstart;
      c67_v_a = c67_u_a + 1;
      c67_i131 = c67_v_a;
      c67_w_a = c67_i131;
      c67_x_a = c67_w_a;
      if (c67_x_a > 2) {
        c67_e_overflow = false;
      } else {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_e_overflow = false;
      }

      if (c67_e_overflow) {
        c67_check_forloop_overflow_error(chartInstance, c67_e_overflow);
      }

      for (c67_o_ix = c67_i131; c67_o_ix < 3; c67_o_ix++) {
        c67_n_ix = c67_o_ix;
        c67_y_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_n_ix), 1, 2, 1, 0) - 1];
        c67_o_b = c67_i_mtmp;
        c67_e_p = (c67_y_a < c67_o_b);
        if (c67_e_p) {
          c67_i_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_n_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c67_j_mtmp = c67_i_mtmp;
    c67_d4 = c67_j_mtmp;
    if (CV_SCRIPT_COND(0, 4, CV_RELATIONAL_EVAL(14U, 0U, 4, c67_d4, 0.0, -1, 5U,
          c67_d4 >= 0.0))) {
      for (c67_i132 = 0; c67_i132 < 4; c67_i132++) {
        c67_b_L_opt_1[c67_i132] = c67_L_opt_2[c67_i132];
      }

      c67_f_ixstart = 1;
      c67_k_mtmp = c67_b_L_opt_1[0];
      c67_k_x = c67_k_mtmp;
      c67_p_b = muDoubleScalarIsNaN(c67_k_x);
      if (c67_p_b) {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_p_ix = 2;
        exitg22 = false;
        while ((exitg22 == false) && (c67_p_ix < 5)) {
          c67_q_ix = c67_p_ix;
          c67_f_ixstart = c67_q_ix;
          c67_l_x = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_q_ix), 1, 4, 1, 0) - 1];
          c67_q_b = muDoubleScalarIsNaN(c67_l_x);
          if (!c67_q_b) {
            c67_k_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_q_ix), 1, 4, 1, 0) - 1];
            exitg22 = true;
          } else {
            c67_p_ix++;
          }
        }
      }

      if (c67_f_ixstart < 4) {
        c67_ab_a = c67_f_ixstart;
        c67_bb_a = c67_ab_a + 1;
        c67_i133 = c67_bb_a;
        c67_cb_a = c67_i133;
        c67_db_a = c67_cb_a;
        if (c67_db_a > 4) {
          c67_f_overflow = false;
        } else {
          c67_eml_switch_helper(chartInstance);
          c67_eml_switch_helper(chartInstance);
          c67_f_overflow = false;
        }

        if (c67_f_overflow) {
          c67_check_forloop_overflow_error(chartInstance, c67_f_overflow);
        }

        for (c67_r_ix = c67_i133; c67_r_ix < 5; c67_r_ix++) {
          c67_q_ix = c67_r_ix;
          c67_eb_a = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_q_ix), 1, 4, 1, 0) - 1];
          c67_r_b = c67_k_mtmp;
          c67_f_p = (c67_eb_a < c67_r_b);
          if (c67_f_p) {
            c67_k_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_q_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c67_l_mtmp = c67_k_mtmp;
      c67_d5 = c67_l_mtmp;
      if (CV_SCRIPT_COND(0, 5, CV_RELATIONAL_EVAL(14U, 0U, 5, c67_d5, 0.0, -1,
            5U, c67_d5 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 1, true);
        CV_SCRIPT_IF(0, 1, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 57);
        for (c67_i134 = 0; c67_i134 < 2; c67_i134++) {
          c67_u_opt[c67_i134] = c67_u_opt_2[c67_i134];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 58);
        for (c67_i135 = 0; c67_i135 < 4; c67_i135++) {
          c67_L_opt[c67_i135] = c67_L_opt_2[c67_i135];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 59);
        c67_case_n = 2.0;
      } else {
        guard15 = true;
      }
    } else {
      guard16 = true;
    }
  } else {
    guard16 = true;
  }

  if (guard16 == true) {
    guard15 = true;
  }

  if (guard15 == true) {
    CV_SCRIPT_MCDC(0, 1, false);
    CV_SCRIPT_IF(0, 1, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 63);
  for (c67_i136 = 0; c67_i136 < 2; c67_i136++) {
    c67_b_u_opt_1[c67_i136] = c67_u_opt_3[c67_i136] - c67_UB[c67_i136];
  }

  c67_g_ixstart = 1;
  c67_m_mtmp = c67_b_u_opt_1[0];
  c67_m_x = c67_m_mtmp;
  c67_s_b = muDoubleScalarIsNaN(c67_m_x);
  if (c67_s_b) {
    c67_eml_switch_helper(chartInstance);
    c67_eml_switch_helper(chartInstance);
    c67_s_ix = 2;
    exitg21 = false;
    while ((exitg21 == false) && (c67_s_ix < 3)) {
      c67_t_ix = c67_s_ix;
      c67_g_ixstart = c67_t_ix;
      c67_n_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_t_ix), 1, 2, 1, 0) - 1];
      c67_t_b = muDoubleScalarIsNaN(c67_n_x);
      if (!c67_t_b) {
        c67_m_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_t_ix), 1, 2, 1, 0) - 1];
        exitg21 = true;
      } else {
        c67_s_ix++;
      }
    }
  }

  if (c67_g_ixstart < 2) {
    c67_fb_a = c67_g_ixstart;
    c67_gb_a = c67_fb_a + 1;
    c67_i137 = c67_gb_a;
    c67_hb_a = c67_i137;
    c67_ib_a = c67_hb_a;
    if (c67_ib_a > 2) {
      c67_g_overflow = false;
    } else {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_g_overflow = false;
    }

    if (c67_g_overflow) {
      c67_check_forloop_overflow_error(chartInstance, c67_g_overflow);
    }

    for (c67_u_ix = c67_i137; c67_u_ix < 3; c67_u_ix++) {
      c67_t_ix = c67_u_ix;
      c67_jb_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_t_ix), 1, 2, 1, 0) - 1];
      c67_u_b = c67_m_mtmp;
      c67_g_p = (c67_jb_a > c67_u_b);
      if (c67_g_p) {
        c67_m_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_t_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c67_n_mtmp = c67_m_mtmp;
  c67_d6 = c67_n_mtmp;
  guard13 = false;
  guard14 = false;
  if (CV_SCRIPT_COND(0, 6, CV_RELATIONAL_EVAL(14U, 0U, 6, c67_d6, 0.0, -1, 3U,
        c67_d6 <= 0.0))) {
    for (c67_i138 = 0; c67_i138 < 2; c67_i138++) {
      c67_b_u_opt_1[c67_i138] = c67_u_opt_3[c67_i138] - c67_LB[c67_i138];
    }

    c67_h_ixstart = 1;
    c67_o_mtmp = c67_b_u_opt_1[0];
    c67_o_x = c67_o_mtmp;
    c67_v_b = muDoubleScalarIsNaN(c67_o_x);
    if (c67_v_b) {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_v_ix = 2;
      exitg20 = false;
      while ((exitg20 == false) && (c67_v_ix < 3)) {
        c67_w_ix = c67_v_ix;
        c67_h_ixstart = c67_w_ix;
        c67_p_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_w_ix), 1, 2, 1, 0) - 1];
        c67_w_b = muDoubleScalarIsNaN(c67_p_x);
        if (!c67_w_b) {
          c67_o_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_w_ix), 1, 2, 1, 0) - 1];
          exitg20 = true;
        } else {
          c67_v_ix++;
        }
      }
    }

    if (c67_h_ixstart < 2) {
      c67_kb_a = c67_h_ixstart;
      c67_lb_a = c67_kb_a + 1;
      c67_i139 = c67_lb_a;
      c67_mb_a = c67_i139;
      c67_nb_a = c67_mb_a;
      if (c67_nb_a > 2) {
        c67_h_overflow = false;
      } else {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_h_overflow = false;
      }

      if (c67_h_overflow) {
        c67_check_forloop_overflow_error(chartInstance, c67_h_overflow);
      }

      for (c67_x_ix = c67_i139; c67_x_ix < 3; c67_x_ix++) {
        c67_w_ix = c67_x_ix;
        c67_ob_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_w_ix), 1, 2, 1, 0) - 1];
        c67_x_b = c67_o_mtmp;
        c67_h_p = (c67_ob_a < c67_x_b);
        if (c67_h_p) {
          c67_o_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_w_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c67_p_mtmp = c67_o_mtmp;
    c67_d7 = c67_p_mtmp;
    if (CV_SCRIPT_COND(0, 7, CV_RELATIONAL_EVAL(14U, 0U, 7, c67_d7, 0.0, -1, 5U,
          c67_d7 >= 0.0))) {
      for (c67_i140 = 0; c67_i140 < 4; c67_i140++) {
        c67_b_L_opt_1[c67_i140] = c67_L_opt_3[c67_i140];
      }

      c67_i_ixstart = 1;
      c67_q_mtmp = c67_b_L_opt_1[0];
      c67_q_x = c67_q_mtmp;
      c67_y_b = muDoubleScalarIsNaN(c67_q_x);
      if (c67_y_b) {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_y_ix = 2;
        exitg19 = false;
        while ((exitg19 == false) && (c67_y_ix < 5)) {
          c67_ab_ix = c67_y_ix;
          c67_i_ixstart = c67_ab_ix;
          c67_r_x = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_ab_ix), 1, 4, 1, 0) - 1];
          c67_ab_b = muDoubleScalarIsNaN(c67_r_x);
          if (!c67_ab_b) {
            c67_q_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_ab_ix), 1, 4, 1, 0) - 1];
            exitg19 = true;
          } else {
            c67_y_ix++;
          }
        }
      }

      if (c67_i_ixstart < 4) {
        c67_pb_a = c67_i_ixstart;
        c67_qb_a = c67_pb_a + 1;
        c67_i141 = c67_qb_a;
        c67_rb_a = c67_i141;
        c67_sb_a = c67_rb_a;
        if (c67_sb_a > 4) {
          c67_i_overflow = false;
        } else {
          c67_eml_switch_helper(chartInstance);
          c67_eml_switch_helper(chartInstance);
          c67_i_overflow = false;
        }

        if (c67_i_overflow) {
          c67_check_forloop_overflow_error(chartInstance, c67_i_overflow);
        }

        for (c67_bb_ix = c67_i141; c67_bb_ix < 5; c67_bb_ix++) {
          c67_ab_ix = c67_bb_ix;
          c67_tb_a = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_ab_ix), 1, 4, 1, 0) - 1];
          c67_bb_b = c67_q_mtmp;
          c67_i_p = (c67_tb_a < c67_bb_b);
          if (c67_i_p) {
            c67_q_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_ab_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c67_r_mtmp = c67_q_mtmp;
      c67_d8 = c67_r_mtmp;
      if (CV_SCRIPT_COND(0, 8, CV_RELATIONAL_EVAL(14U, 0U, 8, c67_d8, 0.0, -1,
            5U, c67_d8 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 2, true);
        CV_SCRIPT_IF(0, 2, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 64);
        for (c67_i142 = 0; c67_i142 < 2; c67_i142++) {
          c67_u_opt[c67_i142] = c67_u_opt_3[c67_i142];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 65);
        for (c67_i143 = 0; c67_i143 < 4; c67_i143++) {
          c67_L_opt[c67_i143] = c67_L_opt_3[c67_i143];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 66);
        c67_case_n = 3.0;
      } else {
        guard13 = true;
      }
    } else {
      guard14 = true;
    }
  } else {
    guard14 = true;
  }

  if (guard14 == true) {
    guard13 = true;
  }

  if (guard13 == true) {
    CV_SCRIPT_MCDC(0, 2, false);
    CV_SCRIPT_IF(0, 2, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 70);
  for (c67_i144 = 0; c67_i144 < 2; c67_i144++) {
    c67_b_u_opt_1[c67_i144] = c67_u_opt_4[c67_i144] - c67_UB[c67_i144];
  }

  c67_j_ixstart = 1;
  c67_s_mtmp = c67_b_u_opt_1[0];
  c67_s_x = c67_s_mtmp;
  c67_cb_b = muDoubleScalarIsNaN(c67_s_x);
  if (c67_cb_b) {
    c67_eml_switch_helper(chartInstance);
    c67_eml_switch_helper(chartInstance);
    c67_cb_ix = 2;
    exitg18 = false;
    while ((exitg18 == false) && (c67_cb_ix < 3)) {
      c67_db_ix = c67_cb_ix;
      c67_j_ixstart = c67_db_ix;
      c67_t_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_db_ix), 1, 2, 1, 0) - 1];
      c67_db_b = muDoubleScalarIsNaN(c67_t_x);
      if (!c67_db_b) {
        c67_s_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_db_ix), 1, 2, 1, 0) - 1];
        exitg18 = true;
      } else {
        c67_cb_ix++;
      }
    }
  }

  if (c67_j_ixstart < 2) {
    c67_ub_a = c67_j_ixstart;
    c67_vb_a = c67_ub_a + 1;
    c67_i145 = c67_vb_a;
    c67_wb_a = c67_i145;
    c67_xb_a = c67_wb_a;
    if (c67_xb_a > 2) {
      c67_j_overflow = false;
    } else {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_j_overflow = false;
    }

    if (c67_j_overflow) {
      c67_check_forloop_overflow_error(chartInstance, c67_j_overflow);
    }

    for (c67_eb_ix = c67_i145; c67_eb_ix < 3; c67_eb_ix++) {
      c67_db_ix = c67_eb_ix;
      c67_yb_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_db_ix), 1, 2, 1, 0) - 1];
      c67_eb_b = c67_s_mtmp;
      c67_j_p = (c67_yb_a > c67_eb_b);
      if (c67_j_p) {
        c67_s_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_db_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c67_t_mtmp = c67_s_mtmp;
  c67_d9 = c67_t_mtmp;
  guard11 = false;
  guard12 = false;
  if (CV_SCRIPT_COND(0, 9, CV_RELATIONAL_EVAL(14U, 0U, 9, c67_d9, 0.0, -1, 3U,
        c67_d9 <= 0.0))) {
    for (c67_i146 = 0; c67_i146 < 2; c67_i146++) {
      c67_b_u_opt_1[c67_i146] = c67_u_opt_4[c67_i146] - c67_LB[c67_i146];
    }

    c67_k_ixstart = 1;
    c67_u_mtmp = c67_b_u_opt_1[0];
    c67_u_x = c67_u_mtmp;
    c67_fb_b = muDoubleScalarIsNaN(c67_u_x);
    if (c67_fb_b) {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_fb_ix = 2;
      exitg17 = false;
      while ((exitg17 == false) && (c67_fb_ix < 3)) {
        c67_gb_ix = c67_fb_ix;
        c67_k_ixstart = c67_gb_ix;
        c67_v_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_gb_ix), 1, 2, 1, 0) - 1];
        c67_gb_b = muDoubleScalarIsNaN(c67_v_x);
        if (!c67_gb_b) {
          c67_u_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_gb_ix), 1, 2, 1, 0) - 1];
          exitg17 = true;
        } else {
          c67_fb_ix++;
        }
      }
    }

    if (c67_k_ixstart < 2) {
      c67_ac_a = c67_k_ixstart;
      c67_bc_a = c67_ac_a + 1;
      c67_i147 = c67_bc_a;
      c67_cc_a = c67_i147;
      c67_dc_a = c67_cc_a;
      if (c67_dc_a > 2) {
        c67_k_overflow = false;
      } else {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_k_overflow = false;
      }

      if (c67_k_overflow) {
        c67_check_forloop_overflow_error(chartInstance, c67_k_overflow);
      }

      for (c67_hb_ix = c67_i147; c67_hb_ix < 3; c67_hb_ix++) {
        c67_gb_ix = c67_hb_ix;
        c67_ec_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_gb_ix), 1, 2, 1, 0) - 1];
        c67_hb_b = c67_u_mtmp;
        c67_k_p = (c67_ec_a < c67_hb_b);
        if (c67_k_p) {
          c67_u_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_gb_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c67_v_mtmp = c67_u_mtmp;
    c67_d10 = c67_v_mtmp;
    if (CV_SCRIPT_COND(0, 10, CV_RELATIONAL_EVAL(14U, 0U, 10, c67_d10, 0.0, -1,
          5U, c67_d10 >= 0.0))) {
      for (c67_i148 = 0; c67_i148 < 4; c67_i148++) {
        c67_b_L_opt_1[c67_i148] = c67_L_opt_4[c67_i148];
      }

      c67_l_ixstart = 1;
      c67_w_mtmp = c67_b_L_opt_1[0];
      c67_w_x = c67_w_mtmp;
      c67_ib_b = muDoubleScalarIsNaN(c67_w_x);
      if (c67_ib_b) {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_ib_ix = 2;
        exitg16 = false;
        while ((exitg16 == false) && (c67_ib_ix < 5)) {
          c67_jb_ix = c67_ib_ix;
          c67_l_ixstart = c67_jb_ix;
          c67_x_x = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_jb_ix), 1, 4, 1, 0) - 1];
          c67_jb_b = muDoubleScalarIsNaN(c67_x_x);
          if (!c67_jb_b) {
            c67_w_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_jb_ix), 1, 4, 1, 0) - 1];
            exitg16 = true;
          } else {
            c67_ib_ix++;
          }
        }
      }

      if (c67_l_ixstart < 4) {
        c67_fc_a = c67_l_ixstart;
        c67_gc_a = c67_fc_a + 1;
        c67_i149 = c67_gc_a;
        c67_hc_a = c67_i149;
        c67_ic_a = c67_hc_a;
        if (c67_ic_a > 4) {
          c67_l_overflow = false;
        } else {
          c67_eml_switch_helper(chartInstance);
          c67_eml_switch_helper(chartInstance);
          c67_l_overflow = false;
        }

        if (c67_l_overflow) {
          c67_check_forloop_overflow_error(chartInstance, c67_l_overflow);
        }

        for (c67_kb_ix = c67_i149; c67_kb_ix < 5; c67_kb_ix++) {
          c67_jb_ix = c67_kb_ix;
          c67_jc_a = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_jb_ix), 1, 4, 1, 0) - 1];
          c67_kb_b = c67_w_mtmp;
          c67_l_p = (c67_jc_a < c67_kb_b);
          if (c67_l_p) {
            c67_w_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_jb_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c67_x_mtmp = c67_w_mtmp;
      c67_d11 = c67_x_mtmp;
      if (CV_SCRIPT_COND(0, 11, CV_RELATIONAL_EVAL(14U, 0U, 11, c67_d11, 0.0, -1,
            5U, c67_d11 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 3, true);
        CV_SCRIPT_IF(0, 3, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 71);
        for (c67_i150 = 0; c67_i150 < 2; c67_i150++) {
          c67_u_opt[c67_i150] = c67_u_opt_4[c67_i150];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 72);
        for (c67_i151 = 0; c67_i151 < 4; c67_i151++) {
          c67_L_opt[c67_i151] = c67_L_opt_4[c67_i151];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 73);
        c67_case_n = 4.0;
      } else {
        guard11 = true;
      }
    } else {
      guard12 = true;
    }
  } else {
    guard12 = true;
  }

  if (guard12 == true) {
    guard11 = true;
  }

  if (guard11 == true) {
    CV_SCRIPT_MCDC(0, 3, false);
    CV_SCRIPT_IF(0, 3, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 77);
  for (c67_i152 = 0; c67_i152 < 2; c67_i152++) {
    c67_b_u_opt_1[c67_i152] = c67_u_opt_5[c67_i152] - c67_UB[c67_i152];
  }

  c67_m_ixstart = 1;
  c67_y_mtmp = c67_b_u_opt_1[0];
  c67_y_x = c67_y_mtmp;
  c67_lb_b = muDoubleScalarIsNaN(c67_y_x);
  if (c67_lb_b) {
    c67_eml_switch_helper(chartInstance);
    c67_eml_switch_helper(chartInstance);
    c67_lb_ix = 2;
    exitg15 = false;
    while ((exitg15 == false) && (c67_lb_ix < 3)) {
      c67_mb_ix = c67_lb_ix;
      c67_m_ixstart = c67_mb_ix;
      c67_ab_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_mb_ix), 1, 2, 1, 0) - 1];
      c67_mb_b = muDoubleScalarIsNaN(c67_ab_x);
      if (!c67_mb_b) {
        c67_y_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_mb_ix), 1, 2, 1, 0) - 1];
        exitg15 = true;
      } else {
        c67_lb_ix++;
      }
    }
  }

  if (c67_m_ixstart < 2) {
    c67_kc_a = c67_m_ixstart;
    c67_lc_a = c67_kc_a + 1;
    c67_i153 = c67_lc_a;
    c67_mc_a = c67_i153;
    c67_nc_a = c67_mc_a;
    if (c67_nc_a > 2) {
      c67_m_overflow = false;
    } else {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_m_overflow = false;
    }

    if (c67_m_overflow) {
      c67_check_forloop_overflow_error(chartInstance, c67_m_overflow);
    }

    for (c67_nb_ix = c67_i153; c67_nb_ix < 3; c67_nb_ix++) {
      c67_mb_ix = c67_nb_ix;
      c67_oc_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_mb_ix), 1, 2, 1, 0) - 1];
      c67_nb_b = c67_y_mtmp;
      c67_m_p = (c67_oc_a > c67_nb_b);
      if (c67_m_p) {
        c67_y_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_mb_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c67_ab_mtmp = c67_y_mtmp;
  c67_d12 = c67_ab_mtmp;
  guard9 = false;
  guard10 = false;
  if (CV_SCRIPT_COND(0, 12, CV_RELATIONAL_EVAL(14U, 0U, 12, c67_d12, 0.0, -1, 3U,
        c67_d12 <= 0.0))) {
    for (c67_i154 = 0; c67_i154 < 2; c67_i154++) {
      c67_b_u_opt_1[c67_i154] = c67_u_opt_5[c67_i154] - c67_LB[c67_i154];
    }

    c67_n_ixstart = 1;
    c67_bb_mtmp = c67_b_u_opt_1[0];
    c67_bb_x = c67_bb_mtmp;
    c67_ob_b = muDoubleScalarIsNaN(c67_bb_x);
    if (c67_ob_b) {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_ob_ix = 2;
      exitg14 = false;
      while ((exitg14 == false) && (c67_ob_ix < 3)) {
        c67_pb_ix = c67_ob_ix;
        c67_n_ixstart = c67_pb_ix;
        c67_cb_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_pb_ix), 1, 2, 1, 0) - 1];
        c67_pb_b = muDoubleScalarIsNaN(c67_cb_x);
        if (!c67_pb_b) {
          c67_bb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_pb_ix), 1, 2, 1, 0) - 1];
          exitg14 = true;
        } else {
          c67_ob_ix++;
        }
      }
    }

    if (c67_n_ixstart < 2) {
      c67_pc_a = c67_n_ixstart;
      c67_qc_a = c67_pc_a + 1;
      c67_i155 = c67_qc_a;
      c67_rc_a = c67_i155;
      c67_sc_a = c67_rc_a;
      if (c67_sc_a > 2) {
        c67_n_overflow = false;
      } else {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_n_overflow = false;
      }

      if (c67_n_overflow) {
        c67_check_forloop_overflow_error(chartInstance, c67_n_overflow);
      }

      for (c67_qb_ix = c67_i155; c67_qb_ix < 3; c67_qb_ix++) {
        c67_pb_ix = c67_qb_ix;
        c67_tc_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_pb_ix), 1, 2, 1, 0) - 1];
        c67_qb_b = c67_bb_mtmp;
        c67_n_p = (c67_tc_a < c67_qb_b);
        if (c67_n_p) {
          c67_bb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_pb_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c67_cb_mtmp = c67_bb_mtmp;
    c67_d13 = c67_cb_mtmp;
    if (CV_SCRIPT_COND(0, 13, CV_RELATIONAL_EVAL(14U, 0U, 13, c67_d13, 0.0, -1,
          5U, c67_d13 >= 0.0))) {
      for (c67_i156 = 0; c67_i156 < 4; c67_i156++) {
        c67_b_L_opt_1[c67_i156] = c67_L_opt_5[c67_i156];
      }

      c67_o_ixstart = 1;
      c67_db_mtmp = c67_b_L_opt_1[0];
      c67_db_x = c67_db_mtmp;
      c67_rb_b = muDoubleScalarIsNaN(c67_db_x);
      if (c67_rb_b) {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_rb_ix = 2;
        exitg13 = false;
        while ((exitg13 == false) && (c67_rb_ix < 5)) {
          c67_sb_ix = c67_rb_ix;
          c67_o_ixstart = c67_sb_ix;
          c67_eb_x = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_sb_ix), 1, 4, 1, 0) - 1];
          c67_sb_b = muDoubleScalarIsNaN(c67_eb_x);
          if (!c67_sb_b) {
            c67_db_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_sb_ix), 1, 4, 1, 0) - 1];
            exitg13 = true;
          } else {
            c67_rb_ix++;
          }
        }
      }

      if (c67_o_ixstart < 4) {
        c67_uc_a = c67_o_ixstart;
        c67_vc_a = c67_uc_a + 1;
        c67_i157 = c67_vc_a;
        c67_wc_a = c67_i157;
        c67_xc_a = c67_wc_a;
        if (c67_xc_a > 4) {
          c67_o_overflow = false;
        } else {
          c67_eml_switch_helper(chartInstance);
          c67_eml_switch_helper(chartInstance);
          c67_o_overflow = false;
        }

        if (c67_o_overflow) {
          c67_check_forloop_overflow_error(chartInstance, c67_o_overflow);
        }

        for (c67_tb_ix = c67_i157; c67_tb_ix < 5; c67_tb_ix++) {
          c67_sb_ix = c67_tb_ix;
          c67_yc_a = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_sb_ix), 1, 4, 1, 0) - 1];
          c67_tb_b = c67_db_mtmp;
          c67_o_p = (c67_yc_a < c67_tb_b);
          if (c67_o_p) {
            c67_db_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_sb_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c67_eb_mtmp = c67_db_mtmp;
      c67_d14 = c67_eb_mtmp;
      if (CV_SCRIPT_COND(0, 14, CV_RELATIONAL_EVAL(14U, 0U, 14, c67_d14, 0.0, -1,
            5U, c67_d14 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 4, true);
        CV_SCRIPT_IF(0, 4, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 78);
        for (c67_i158 = 0; c67_i158 < 2; c67_i158++) {
          c67_u_opt[c67_i158] = c67_u_opt_5[c67_i158];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 79);
        for (c67_i159 = 0; c67_i159 < 4; c67_i159++) {
          c67_L_opt[c67_i159] = c67_L_opt_5[c67_i159];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 80);
        c67_case_n = 5.0;
      } else {
        guard9 = true;
      }
    } else {
      guard10 = true;
    }
  } else {
    guard10 = true;
  }

  if (guard10 == true) {
    guard9 = true;
  }

  if (guard9 == true) {
    CV_SCRIPT_MCDC(0, 4, false);
    CV_SCRIPT_IF(0, 4, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 84);
  for (c67_i160 = 0; c67_i160 < 2; c67_i160++) {
    c67_b_u_opt_1[c67_i160] = c67_u_opt_6[c67_i160] - c67_UB[c67_i160];
  }

  c67_p_ixstart = 1;
  c67_fb_mtmp = c67_b_u_opt_1[0];
  c67_fb_x = c67_fb_mtmp;
  c67_ub_b = muDoubleScalarIsNaN(c67_fb_x);
  if (c67_ub_b) {
    c67_eml_switch_helper(chartInstance);
    c67_eml_switch_helper(chartInstance);
    c67_ub_ix = 2;
    exitg12 = false;
    while ((exitg12 == false) && (c67_ub_ix < 3)) {
      c67_vb_ix = c67_ub_ix;
      c67_p_ixstart = c67_vb_ix;
      c67_gb_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_vb_ix), 1, 2, 1, 0) - 1];
      c67_vb_b = muDoubleScalarIsNaN(c67_gb_x);
      if (!c67_vb_b) {
        c67_fb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_vb_ix), 1, 2, 1, 0) - 1];
        exitg12 = true;
      } else {
        c67_ub_ix++;
      }
    }
  }

  if (c67_p_ixstart < 2) {
    c67_ad_a = c67_p_ixstart;
    c67_bd_a = c67_ad_a + 1;
    c67_i161 = c67_bd_a;
    c67_cd_a = c67_i161;
    c67_dd_a = c67_cd_a;
    if (c67_dd_a > 2) {
      c67_p_overflow = false;
    } else {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_p_overflow = false;
    }

    if (c67_p_overflow) {
      c67_check_forloop_overflow_error(chartInstance, c67_p_overflow);
    }

    for (c67_wb_ix = c67_i161; c67_wb_ix < 3; c67_wb_ix++) {
      c67_vb_ix = c67_wb_ix;
      c67_ed_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_vb_ix), 1, 2, 1, 0) - 1];
      c67_wb_b = c67_fb_mtmp;
      c67_p_p = (c67_ed_a > c67_wb_b);
      if (c67_p_p) {
        c67_fb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_vb_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c67_gb_mtmp = c67_fb_mtmp;
  c67_d15 = c67_gb_mtmp;
  guard7 = false;
  guard8 = false;
  if (CV_SCRIPT_COND(0, 15, CV_RELATIONAL_EVAL(14U, 0U, 15, c67_d15, 0.0, -1, 3U,
        c67_d15 <= 0.0))) {
    for (c67_i162 = 0; c67_i162 < 2; c67_i162++) {
      c67_b_u_opt_1[c67_i162] = c67_u_opt_6[c67_i162] - c67_LB[c67_i162];
    }

    c67_q_ixstart = 1;
    c67_hb_mtmp = c67_b_u_opt_1[0];
    c67_hb_x = c67_hb_mtmp;
    c67_xb_b = muDoubleScalarIsNaN(c67_hb_x);
    if (c67_xb_b) {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_xb_ix = 2;
      exitg11 = false;
      while ((exitg11 == false) && (c67_xb_ix < 3)) {
        c67_yb_ix = c67_xb_ix;
        c67_q_ixstart = c67_yb_ix;
        c67_ib_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_yb_ix), 1, 2, 1, 0) - 1];
        c67_yb_b = muDoubleScalarIsNaN(c67_ib_x);
        if (!c67_yb_b) {
          c67_hb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_yb_ix), 1, 2, 1, 0) - 1];
          exitg11 = true;
        } else {
          c67_xb_ix++;
        }
      }
    }

    if (c67_q_ixstart < 2) {
      c67_fd_a = c67_q_ixstart;
      c67_gd_a = c67_fd_a + 1;
      c67_i163 = c67_gd_a;
      c67_hd_a = c67_i163;
      c67_id_a = c67_hd_a;
      if (c67_id_a > 2) {
        c67_q_overflow = false;
      } else {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_q_overflow = false;
      }

      if (c67_q_overflow) {
        c67_check_forloop_overflow_error(chartInstance, c67_q_overflow);
      }

      for (c67_ac_ix = c67_i163; c67_ac_ix < 3; c67_ac_ix++) {
        c67_yb_ix = c67_ac_ix;
        c67_jd_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_yb_ix), 1, 2, 1, 0) - 1];
        c67_ac_b = c67_hb_mtmp;
        c67_q_p = (c67_jd_a < c67_ac_b);
        if (c67_q_p) {
          c67_hb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_yb_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c67_ib_mtmp = c67_hb_mtmp;
    c67_d16 = c67_ib_mtmp;
    if (CV_SCRIPT_COND(0, 16, CV_RELATIONAL_EVAL(14U, 0U, 16, c67_d16, 0.0, -1,
          5U, c67_d16 >= 0.0))) {
      for (c67_i164 = 0; c67_i164 < 4; c67_i164++) {
        c67_b_L_opt_1[c67_i164] = c67_L_opt_6[c67_i164];
      }

      c67_r_ixstart = 1;
      c67_jb_mtmp = c67_b_L_opt_1[0];
      c67_jb_x = c67_jb_mtmp;
      c67_bc_b = muDoubleScalarIsNaN(c67_jb_x);
      if (c67_bc_b) {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_bc_ix = 2;
        exitg10 = false;
        while ((exitg10 == false) && (c67_bc_ix < 5)) {
          c67_cc_ix = c67_bc_ix;
          c67_r_ixstart = c67_cc_ix;
          c67_kb_x = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_cc_ix), 1, 4, 1, 0) - 1];
          c67_cc_b = muDoubleScalarIsNaN(c67_kb_x);
          if (!c67_cc_b) {
            c67_jb_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_cc_ix), 1, 4, 1, 0) - 1];
            exitg10 = true;
          } else {
            c67_bc_ix++;
          }
        }
      }

      if (c67_r_ixstart < 4) {
        c67_kd_a = c67_r_ixstart;
        c67_ld_a = c67_kd_a + 1;
        c67_i165 = c67_ld_a;
        c67_md_a = c67_i165;
        c67_nd_a = c67_md_a;
        if (c67_nd_a > 4) {
          c67_r_overflow = false;
        } else {
          c67_eml_switch_helper(chartInstance);
          c67_eml_switch_helper(chartInstance);
          c67_r_overflow = false;
        }

        if (c67_r_overflow) {
          c67_check_forloop_overflow_error(chartInstance, c67_r_overflow);
        }

        for (c67_dc_ix = c67_i165; c67_dc_ix < 5; c67_dc_ix++) {
          c67_cc_ix = c67_dc_ix;
          c67_od_a = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_cc_ix), 1, 4, 1, 0) - 1];
          c67_dc_b = c67_jb_mtmp;
          c67_r_p = (c67_od_a < c67_dc_b);
          if (c67_r_p) {
            c67_jb_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_cc_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c67_kb_mtmp = c67_jb_mtmp;
      c67_d17 = c67_kb_mtmp;
      if (CV_SCRIPT_COND(0, 17, CV_RELATIONAL_EVAL(14U, 0U, 17, c67_d17, 0.0, -1,
            5U, c67_d17 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 5, true);
        CV_SCRIPT_IF(0, 5, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 85);
        for (c67_i166 = 0; c67_i166 < 2; c67_i166++) {
          c67_u_opt[c67_i166] = c67_u_opt_6[c67_i166];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 86);
        for (c67_i167 = 0; c67_i167 < 4; c67_i167++) {
          c67_L_opt[c67_i167] = c67_L_opt_6[c67_i167];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 87);
        c67_case_n = 6.0;
      } else {
        guard7 = true;
      }
    } else {
      guard8 = true;
    }
  } else {
    guard8 = true;
  }

  if (guard8 == true) {
    guard7 = true;
  }

  if (guard7 == true) {
    CV_SCRIPT_MCDC(0, 5, false);
    CV_SCRIPT_IF(0, 5, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 91);
  for (c67_i168 = 0; c67_i168 < 2; c67_i168++) {
    c67_b_u_opt_1[c67_i168] = c67_u_opt_7[c67_i168] - c67_UB[c67_i168];
  }

  c67_s_ixstart = 1;
  c67_lb_mtmp = c67_b_u_opt_1[0];
  c67_lb_x = c67_lb_mtmp;
  c67_ec_b = muDoubleScalarIsNaN(c67_lb_x);
  if (c67_ec_b) {
    c67_eml_switch_helper(chartInstance);
    c67_eml_switch_helper(chartInstance);
    c67_ec_ix = 2;
    exitg9 = false;
    while ((exitg9 == false) && (c67_ec_ix < 3)) {
      c67_fc_ix = c67_ec_ix;
      c67_s_ixstart = c67_fc_ix;
      c67_mb_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_fc_ix), 1, 2, 1, 0) - 1];
      c67_fc_b = muDoubleScalarIsNaN(c67_mb_x);
      if (!c67_fc_b) {
        c67_lb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_fc_ix), 1, 2, 1, 0) - 1];
        exitg9 = true;
      } else {
        c67_ec_ix++;
      }
    }
  }

  if (c67_s_ixstart < 2) {
    c67_pd_a = c67_s_ixstart;
    c67_qd_a = c67_pd_a + 1;
    c67_i169 = c67_qd_a;
    c67_rd_a = c67_i169;
    c67_sd_a = c67_rd_a;
    if (c67_sd_a > 2) {
      c67_s_overflow = false;
    } else {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_s_overflow = false;
    }

    if (c67_s_overflow) {
      c67_check_forloop_overflow_error(chartInstance, c67_s_overflow);
    }

    for (c67_gc_ix = c67_i169; c67_gc_ix < 3; c67_gc_ix++) {
      c67_fc_ix = c67_gc_ix;
      c67_td_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_fc_ix), 1, 2, 1, 0) - 1];
      c67_gc_b = c67_lb_mtmp;
      c67_s_p = (c67_td_a > c67_gc_b);
      if (c67_s_p) {
        c67_lb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_fc_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c67_mb_mtmp = c67_lb_mtmp;
  c67_d18 = c67_mb_mtmp;
  guard5 = false;
  guard6 = false;
  if (CV_SCRIPT_COND(0, 18, CV_RELATIONAL_EVAL(14U, 0U, 18, c67_d18, 0.0, -1, 3U,
        c67_d18 <= 0.0))) {
    for (c67_i170 = 0; c67_i170 < 2; c67_i170++) {
      c67_b_u_opt_1[c67_i170] = c67_u_opt_7[c67_i170] - c67_LB[c67_i170];
    }

    c67_t_ixstart = 1;
    c67_nb_mtmp = c67_b_u_opt_1[0];
    c67_nb_x = c67_nb_mtmp;
    c67_hc_b = muDoubleScalarIsNaN(c67_nb_x);
    if (c67_hc_b) {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_hc_ix = 2;
      exitg8 = false;
      while ((exitg8 == false) && (c67_hc_ix < 3)) {
        c67_ic_ix = c67_hc_ix;
        c67_t_ixstart = c67_ic_ix;
        c67_ob_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_ic_ix), 1, 2, 1, 0) - 1];
        c67_ic_b = muDoubleScalarIsNaN(c67_ob_x);
        if (!c67_ic_b) {
          c67_nb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_ic_ix), 1, 2, 1, 0) - 1];
          exitg8 = true;
        } else {
          c67_hc_ix++;
        }
      }
    }

    if (c67_t_ixstart < 2) {
      c67_ud_a = c67_t_ixstart;
      c67_vd_a = c67_ud_a + 1;
      c67_i171 = c67_vd_a;
      c67_wd_a = c67_i171;
      c67_xd_a = c67_wd_a;
      if (c67_xd_a > 2) {
        c67_t_overflow = false;
      } else {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_t_overflow = false;
      }

      if (c67_t_overflow) {
        c67_check_forloop_overflow_error(chartInstance, c67_t_overflow);
      }

      for (c67_jc_ix = c67_i171; c67_jc_ix < 3; c67_jc_ix++) {
        c67_ic_ix = c67_jc_ix;
        c67_yd_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_ic_ix), 1, 2, 1, 0) - 1];
        c67_jc_b = c67_nb_mtmp;
        c67_t_p = (c67_yd_a < c67_jc_b);
        if (c67_t_p) {
          c67_nb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_ic_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c67_ob_mtmp = c67_nb_mtmp;
    c67_d19 = c67_ob_mtmp;
    if (CV_SCRIPT_COND(0, 19, CV_RELATIONAL_EVAL(14U, 0U, 19, c67_d19, 0.0, -1,
          5U, c67_d19 >= 0.0))) {
      for (c67_i172 = 0; c67_i172 < 4; c67_i172++) {
        c67_b_L_opt_1[c67_i172] = c67_L_opt_7[c67_i172];
      }

      c67_u_ixstart = 1;
      c67_pb_mtmp = c67_b_L_opt_1[0];
      c67_pb_x = c67_pb_mtmp;
      c67_kc_b = muDoubleScalarIsNaN(c67_pb_x);
      if (c67_kc_b) {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_kc_ix = 2;
        exitg7 = false;
        while ((exitg7 == false) && (c67_kc_ix < 5)) {
          c67_lc_ix = c67_kc_ix;
          c67_u_ixstart = c67_lc_ix;
          c67_qb_x = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_lc_ix), 1, 4, 1, 0) - 1];
          c67_lc_b = muDoubleScalarIsNaN(c67_qb_x);
          if (!c67_lc_b) {
            c67_pb_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_lc_ix), 1, 4, 1, 0) - 1];
            exitg7 = true;
          } else {
            c67_kc_ix++;
          }
        }
      }

      if (c67_u_ixstart < 4) {
        c67_ae_a = c67_u_ixstart;
        c67_be_a = c67_ae_a + 1;
        c67_i173 = c67_be_a;
        c67_ce_a = c67_i173;
        c67_de_a = c67_ce_a;
        if (c67_de_a > 4) {
          c67_u_overflow = false;
        } else {
          c67_eml_switch_helper(chartInstance);
          c67_eml_switch_helper(chartInstance);
          c67_u_overflow = false;
        }

        if (c67_u_overflow) {
          c67_check_forloop_overflow_error(chartInstance, c67_u_overflow);
        }

        for (c67_mc_ix = c67_i173; c67_mc_ix < 5; c67_mc_ix++) {
          c67_lc_ix = c67_mc_ix;
          c67_ee_a = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_lc_ix), 1, 4, 1, 0) - 1];
          c67_mc_b = c67_pb_mtmp;
          c67_u_p = (c67_ee_a < c67_mc_b);
          if (c67_u_p) {
            c67_pb_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_lc_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c67_qb_mtmp = c67_pb_mtmp;
      c67_d20 = c67_qb_mtmp;
      if (CV_SCRIPT_COND(0, 20, CV_RELATIONAL_EVAL(14U, 0U, 20, c67_d20, 0.0, -1,
            5U, c67_d20 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 6, true);
        CV_SCRIPT_IF(0, 6, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 92);
        for (c67_i174 = 0; c67_i174 < 2; c67_i174++) {
          c67_u_opt[c67_i174] = c67_u_opt_7[c67_i174];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 93);
        for (c67_i175 = 0; c67_i175 < 4; c67_i175++) {
          c67_L_opt[c67_i175] = c67_L_opt_7[c67_i175];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 94);
        c67_case_n = 7.0;
      } else {
        guard5 = true;
      }
    } else {
      guard6 = true;
    }
  } else {
    guard6 = true;
  }

  if (guard6 == true) {
    guard5 = true;
  }

  if (guard5 == true) {
    CV_SCRIPT_MCDC(0, 6, false);
    CV_SCRIPT_IF(0, 6, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 98);
  for (c67_i176 = 0; c67_i176 < 2; c67_i176++) {
    c67_b_u_opt_1[c67_i176] = c67_u_opt_8[c67_i176] - c67_UB[c67_i176];
  }

  c67_v_ixstart = 1;
  c67_rb_mtmp = c67_b_u_opt_1[0];
  c67_rb_x = c67_rb_mtmp;
  c67_nc_b = muDoubleScalarIsNaN(c67_rb_x);
  if (c67_nc_b) {
    c67_eml_switch_helper(chartInstance);
    c67_eml_switch_helper(chartInstance);
    c67_nc_ix = 2;
    exitg6 = false;
    while ((exitg6 == false) && (c67_nc_ix < 3)) {
      c67_oc_ix = c67_nc_ix;
      c67_v_ixstart = c67_oc_ix;
      c67_sb_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_oc_ix), 1, 2, 1, 0) - 1];
      c67_oc_b = muDoubleScalarIsNaN(c67_sb_x);
      if (!c67_oc_b) {
        c67_rb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_oc_ix), 1, 2, 1, 0) - 1];
        exitg6 = true;
      } else {
        c67_nc_ix++;
      }
    }
  }

  if (c67_v_ixstart < 2) {
    c67_fe_a = c67_v_ixstart;
    c67_ge_a = c67_fe_a + 1;
    c67_i177 = c67_ge_a;
    c67_he_a = c67_i177;
    c67_ie_a = c67_he_a;
    if (c67_ie_a > 2) {
      c67_v_overflow = false;
    } else {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_v_overflow = false;
    }

    if (c67_v_overflow) {
      c67_check_forloop_overflow_error(chartInstance, c67_v_overflow);
    }

    for (c67_pc_ix = c67_i177; c67_pc_ix < 3; c67_pc_ix++) {
      c67_oc_ix = c67_pc_ix;
      c67_je_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_oc_ix), 1, 2, 1, 0) - 1];
      c67_pc_b = c67_rb_mtmp;
      c67_v_p = (c67_je_a > c67_pc_b);
      if (c67_v_p) {
        c67_rb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_oc_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c67_sb_mtmp = c67_rb_mtmp;
  c67_d21 = c67_sb_mtmp;
  guard3 = false;
  guard4 = false;
  if (CV_SCRIPT_COND(0, 21, CV_RELATIONAL_EVAL(14U, 0U, 21, c67_d21, 0.0, -1, 3U,
        c67_d21 <= 0.0))) {
    for (c67_i178 = 0; c67_i178 < 2; c67_i178++) {
      c67_b_u_opt_1[c67_i178] = c67_u_opt_8[c67_i178] - c67_LB[c67_i178];
    }

    c67_w_ixstart = 1;
    c67_tb_mtmp = c67_b_u_opt_1[0];
    c67_tb_x = c67_tb_mtmp;
    c67_qc_b = muDoubleScalarIsNaN(c67_tb_x);
    if (c67_qc_b) {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_qc_ix = 2;
      exitg5 = false;
      while ((exitg5 == false) && (c67_qc_ix < 3)) {
        c67_rc_ix = c67_qc_ix;
        c67_w_ixstart = c67_rc_ix;
        c67_ub_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_rc_ix), 1, 2, 1, 0) - 1];
        c67_rc_b = muDoubleScalarIsNaN(c67_ub_x);
        if (!c67_rc_b) {
          c67_tb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_rc_ix), 1, 2, 1, 0) - 1];
          exitg5 = true;
        } else {
          c67_qc_ix++;
        }
      }
    }

    if (c67_w_ixstart < 2) {
      c67_ke_a = c67_w_ixstart;
      c67_le_a = c67_ke_a + 1;
      c67_i179 = c67_le_a;
      c67_me_a = c67_i179;
      c67_ne_a = c67_me_a;
      if (c67_ne_a > 2) {
        c67_w_overflow = false;
      } else {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_w_overflow = false;
      }

      if (c67_w_overflow) {
        c67_check_forloop_overflow_error(chartInstance, c67_w_overflow);
      }

      for (c67_sc_ix = c67_i179; c67_sc_ix < 3; c67_sc_ix++) {
        c67_rc_ix = c67_sc_ix;
        c67_oe_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_rc_ix), 1, 2, 1, 0) - 1];
        c67_sc_b = c67_tb_mtmp;
        c67_w_p = (c67_oe_a < c67_sc_b);
        if (c67_w_p) {
          c67_tb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_rc_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c67_ub_mtmp = c67_tb_mtmp;
    c67_d22 = c67_ub_mtmp;
    if (CV_SCRIPT_COND(0, 22, CV_RELATIONAL_EVAL(14U, 0U, 22, c67_d22, 0.0, -1,
          5U, c67_d22 >= 0.0))) {
      for (c67_i180 = 0; c67_i180 < 4; c67_i180++) {
        c67_b_L_opt_1[c67_i180] = c67_L_opt_8[c67_i180];
      }

      c67_x_ixstart = 1;
      c67_vb_mtmp = c67_b_L_opt_1[0];
      c67_vb_x = c67_vb_mtmp;
      c67_tc_b = muDoubleScalarIsNaN(c67_vb_x);
      if (c67_tc_b) {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_tc_ix = 2;
        exitg4 = false;
        while ((exitg4 == false) && (c67_tc_ix < 5)) {
          c67_uc_ix = c67_tc_ix;
          c67_x_ixstart = c67_uc_ix;
          c67_wb_x = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_uc_ix), 1, 4, 1, 0) - 1];
          c67_uc_b = muDoubleScalarIsNaN(c67_wb_x);
          if (!c67_uc_b) {
            c67_vb_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_uc_ix), 1, 4, 1, 0) - 1];
            exitg4 = true;
          } else {
            c67_tc_ix++;
          }
        }
      }

      if (c67_x_ixstart < 4) {
        c67_pe_a = c67_x_ixstart;
        c67_qe_a = c67_pe_a + 1;
        c67_i181 = c67_qe_a;
        c67_re_a = c67_i181;
        c67_se_a = c67_re_a;
        if (c67_se_a > 4) {
          c67_x_overflow = false;
        } else {
          c67_eml_switch_helper(chartInstance);
          c67_eml_switch_helper(chartInstance);
          c67_x_overflow = false;
        }

        if (c67_x_overflow) {
          c67_check_forloop_overflow_error(chartInstance, c67_x_overflow);
        }

        for (c67_vc_ix = c67_i181; c67_vc_ix < 5; c67_vc_ix++) {
          c67_uc_ix = c67_vc_ix;
          c67_te_a = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_uc_ix), 1, 4, 1, 0) - 1];
          c67_vc_b = c67_vb_mtmp;
          c67_x_p = (c67_te_a < c67_vc_b);
          if (c67_x_p) {
            c67_vb_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_uc_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c67_wb_mtmp = c67_vb_mtmp;
      c67_d23 = c67_wb_mtmp;
      if (CV_SCRIPT_COND(0, 23, CV_RELATIONAL_EVAL(14U, 0U, 23, c67_d23, 0.0, -1,
            5U, c67_d23 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 7, true);
        CV_SCRIPT_IF(0, 7, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 99);
        for (c67_i182 = 0; c67_i182 < 2; c67_i182++) {
          c67_u_opt[c67_i182] = c67_u_opt_8[c67_i182];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 100);
        for (c67_i183 = 0; c67_i183 < 4; c67_i183++) {
          c67_L_opt[c67_i183] = c67_L_opt_8[c67_i183];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 101);
        c67_case_n = 8.0;
      } else {
        guard3 = true;
      }
    } else {
      guard4 = true;
    }
  } else {
    guard4 = true;
  }

  if (guard4 == true) {
    guard3 = true;
  }

  if (guard3 == true) {
    CV_SCRIPT_MCDC(0, 7, false);
    CV_SCRIPT_IF(0, 7, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 105);
  for (c67_i184 = 0; c67_i184 < 2; c67_i184++) {
    c67_b_u_opt_1[c67_i184] = c67_u_opt_9[c67_i184] - c67_UB[c67_i184];
  }

  c67_y_ixstart = 1;
  c67_xb_mtmp = c67_b_u_opt_1[0];
  c67_xb_x = c67_xb_mtmp;
  c67_wc_b = muDoubleScalarIsNaN(c67_xb_x);
  if (c67_wc_b) {
    c67_eml_switch_helper(chartInstance);
    c67_eml_switch_helper(chartInstance);
    c67_wc_ix = 2;
    exitg3 = false;
    while ((exitg3 == false) && (c67_wc_ix < 3)) {
      c67_xc_ix = c67_wc_ix;
      c67_y_ixstart = c67_xc_ix;
      c67_yb_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_xc_ix), 1, 2, 1, 0) - 1];
      c67_xc_b = muDoubleScalarIsNaN(c67_yb_x);
      if (!c67_xc_b) {
        c67_xb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_xc_ix), 1, 2, 1, 0) - 1];
        exitg3 = true;
      } else {
        c67_wc_ix++;
      }
    }
  }

  if (c67_y_ixstart < 2) {
    c67_ue_a = c67_y_ixstart;
    c67_ve_a = c67_ue_a + 1;
    c67_i185 = c67_ve_a;
    c67_we_a = c67_i185;
    c67_xe_a = c67_we_a;
    if (c67_xe_a > 2) {
      c67_y_overflow = false;
    } else {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_y_overflow = false;
    }

    if (c67_y_overflow) {
      c67_check_forloop_overflow_error(chartInstance, c67_y_overflow);
    }

    for (c67_yc_ix = c67_i185; c67_yc_ix < 3; c67_yc_ix++) {
      c67_xc_ix = c67_yc_ix;
      c67_ye_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_xc_ix), 1, 2, 1, 0) - 1];
      c67_yc_b = c67_xb_mtmp;
      c67_y_p = (c67_ye_a > c67_yc_b);
      if (c67_y_p) {
        c67_xb_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_xc_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c67_yb_mtmp = c67_xb_mtmp;
  c67_d24 = c67_yb_mtmp;
  guard1 = false;
  guard2 = false;
  if (CV_SCRIPT_COND(0, 24, CV_RELATIONAL_EVAL(14U, 0U, 24, c67_d24, 0.0, -1, 3U,
        c67_d24 <= 0.0))) {
    for (c67_i186 = 0; c67_i186 < 2; c67_i186++) {
      c67_b_u_opt_1[c67_i186] = c67_u_opt_9[c67_i186] - c67_LB[c67_i186];
    }

    c67_ab_ixstart = 1;
    c67_ac_mtmp = c67_b_u_opt_1[0];
    c67_ac_x = c67_ac_mtmp;
    c67_ad_b = muDoubleScalarIsNaN(c67_ac_x);
    if (c67_ad_b) {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_ad_ix = 2;
      exitg2 = false;
      while ((exitg2 == false) && (c67_ad_ix < 3)) {
        c67_bd_ix = c67_ad_ix;
        c67_ab_ixstart = c67_bd_ix;
        c67_bc_x = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_bd_ix), 1, 2, 1, 0) - 1];
        c67_bd_b = muDoubleScalarIsNaN(c67_bc_x);
        if (!c67_bd_b) {
          c67_ac_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_bd_ix), 1, 2, 1, 0) - 1];
          exitg2 = true;
        } else {
          c67_ad_ix++;
        }
      }
    }

    if (c67_ab_ixstart < 2) {
      c67_af_a = c67_ab_ixstart;
      c67_bf_a = c67_af_a + 1;
      c67_i187 = c67_bf_a;
      c67_cf_a = c67_i187;
      c67_df_a = c67_cf_a;
      if (c67_df_a > 2) {
        c67_ab_overflow = false;
      } else {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_ab_overflow = false;
      }

      if (c67_ab_overflow) {
        c67_check_forloop_overflow_error(chartInstance, c67_ab_overflow);
      }

      for (c67_cd_ix = c67_i187; c67_cd_ix < 3; c67_cd_ix++) {
        c67_bd_ix = c67_cd_ix;
        c67_ef_a = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_bd_ix), 1, 2, 1, 0) - 1];
        c67_cd_b = c67_ac_mtmp;
        c67_ab_p = (c67_ef_a < c67_cd_b);
        if (c67_ab_p) {
          c67_ac_mtmp = c67_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_bd_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c67_bc_mtmp = c67_ac_mtmp;
    c67_d25 = c67_bc_mtmp;
    if (CV_SCRIPT_COND(0, 25, CV_RELATIONAL_EVAL(14U, 0U, 25, c67_d25, 0.0, -1,
          5U, c67_d25 >= 0.0))) {
      for (c67_i188 = 0; c67_i188 < 4; c67_i188++) {
        c67_b_L_opt_1[c67_i188] = c67_L_opt_9[c67_i188];
      }

      c67_bb_ixstart = 1;
      c67_cc_mtmp = c67_b_L_opt_1[0];
      c67_cc_x = c67_cc_mtmp;
      c67_dd_b = muDoubleScalarIsNaN(c67_cc_x);
      if (c67_dd_b) {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_dd_ix = 2;
        exitg1 = false;
        while ((exitg1 == false) && (c67_dd_ix < 5)) {
          c67_ed_ix = c67_dd_ix;
          c67_bb_ixstart = c67_ed_ix;
          c67_dc_x = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_ed_ix), 1, 4, 1, 0) - 1];
          c67_ed_b = muDoubleScalarIsNaN(c67_dc_x);
          if (!c67_ed_b) {
            c67_cc_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_ed_ix), 1, 4, 1, 0) - 1];
            exitg1 = true;
          } else {
            c67_dd_ix++;
          }
        }
      }

      if (c67_bb_ixstart < 4) {
        c67_ff_a = c67_bb_ixstart;
        c67_gf_a = c67_ff_a + 1;
        c67_i189 = c67_gf_a;
        c67_hf_a = c67_i189;
        c67_if_a = c67_hf_a;
        if (c67_if_a > 4) {
          c67_bb_overflow = false;
        } else {
          c67_eml_switch_helper(chartInstance);
          c67_eml_switch_helper(chartInstance);
          c67_bb_overflow = false;
        }

        if (c67_bb_overflow) {
          c67_check_forloop_overflow_error(chartInstance, c67_bb_overflow);
        }

        for (c67_fd_ix = c67_i189; c67_fd_ix < 5; c67_fd_ix++) {
          c67_ed_ix = c67_fd_ix;
          c67_jf_a = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_ed_ix), 1, 4, 1, 0) - 1];
          c67_fd_b = c67_cc_mtmp;
          c67_bb_p = (c67_jf_a < c67_fd_b);
          if (c67_bb_p) {
            c67_cc_mtmp = c67_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c67_ed_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c67_dc_mtmp = c67_cc_mtmp;
      c67_d26 = c67_dc_mtmp;
      if (CV_SCRIPT_COND(0, 26, CV_RELATIONAL_EVAL(14U, 0U, 26, c67_d26, 0.0, -1,
            5U, c67_d26 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 8, true);
        CV_SCRIPT_IF(0, 8, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 106);
        for (c67_i190 = 0; c67_i190 < 2; c67_i190++) {
          c67_u_opt[c67_i190] = c67_u_opt_9[c67_i190];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 107);
        for (c67_i191 = 0; c67_i191 < 4; c67_i191++) {
          c67_L_opt[c67_i191] = c67_L_opt_9[c67_i191];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 108);
        c67_case_n = 9.0;
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
    CV_SCRIPT_MCDC(0, 8, false);
    CV_SCRIPT_IF(0, 8, false);
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, 111);
  _SFD_SCRIPT_CALL(0U, chartInstance->c67_sfEvent, -111);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c67_LA_LS_Revised_Saturation_Case_1
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u_opt[2], real_T c67_L_opt[4])
{
  uint32_T c67_debug_family_var_map[7];
  real_T c67_nargin = 7.0;
  real_T c67_nargout = 2.0;
  int32_T c67_i192;
  real_T c67_A;
  real_T c67_B;
  real_T c67_y;
  real_T c67_b_A;
  real_T c67_b_B;
  real_T c67_b_y;
  real_T c67_c_A;
  real_T c67_c_B;
  real_T c67_c_y;
  real_T c67_d_A;
  real_T c67_d_B;
  real_T c67_d_y;
  int32_T c67_i193;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c67_b_debug_family_names,
    c67_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargin, 0U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargout, 1U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LS, 2U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LA, 3U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_w, 4U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt, 5U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt, 6U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c67_sfEvent, 9);
  for (c67_i192 = 0; c67_i192 < 2; c67_i192++) {
    c67_u_opt[c67_i192] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c67_sfEvent, 10);
  c67_A = -((2.0 * c67_u_LS + c67_u_LA * c67_w) * (c67_w - 4.0));
  c67_B = 8.0 * c67_w;
  c67_y = c67_rdivide(chartInstance, c67_A, c67_B);
  c67_b_A = (2.0 * c67_u_LS - c67_u_LA * c67_w) * (c67_w + 4.0);
  c67_b_B = 8.0 * c67_w;
  c67_b_y = c67_rdivide(chartInstance, c67_b_A, c67_b_B);
  c67_u_opt[0] = c67_y - c67_b_y;
  _SFD_SCRIPT_CALL(1U, chartInstance->c67_sfEvent, 11);
  c67_c_A = (2.0 * c67_u_LS + c67_u_LA * c67_w) * (c67_w + 4.0);
  c67_c_B = 8.0 * c67_w;
  c67_c_y = c67_rdivide(chartInstance, c67_c_A, c67_c_B);
  c67_d_A = (2.0 * c67_u_LS - c67_u_LA * c67_w) * (c67_w - 4.0);
  c67_d_B = 8.0 * c67_w;
  c67_d_y = c67_rdivide(chartInstance, c67_d_A, c67_d_B);
  c67_u_opt[1] = c67_c_y + c67_d_y;
  _SFD_SCRIPT_CALL(1U, chartInstance->c67_sfEvent, 14);
  for (c67_i193 = 0; c67_i193 < 4; c67_i193++) {
    c67_L_opt[c67_i193] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c67_sfEvent, 15);
  c67_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c67_sfEvent, 16);
  c67_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c67_sfEvent, 17);
  c67_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c67_sfEvent, 18);
  c67_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c67_sfEvent, 19);
  _SFD_SCRIPT_CALL(1U, chartInstance->c67_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c67_LA_LS_Revised_Saturation_Case_2
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u1_min, real_T c67_u_opt[2], real_T
   c67_L_opt[4])
{
  uint32_T c67_debug_family_var_map[8];
  real_T c67_nargin = 7.0;
  real_T c67_nargout = 2.0;
  int32_T c67_i194;
  real_T c67_A;
  real_T c67_B;
  real_T c67_y;
  int32_T c67_i195;
  real_T c67_b_A;
  real_T c67_b_B;
  real_T c67_b_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c67_c_debug_family_names,
    c67_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargin, 0U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargout, 1U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LS, 2U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LA, 3U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_w, 4U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u1_min, 5U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt, 6U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt, 7U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c67_sfEvent, 9);
  for (c67_i194 = 0; c67_i194 < 2; c67_i194++) {
    c67_u_opt[c67_i194] = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c67_sfEvent, 10);
  c67_u_opt[0] = c67_u1_min;
  _SFD_SCRIPT_CALL(2U, chartInstance->c67_sfEvent, 11);
  c67_A = ((4.0 * c67_u1_min + 4.0 * c67_u_LS) - c67_u1_min * c67_w) + 2.0 *
    c67_u_LA * c67_w;
  c67_B = c67_w + 4.0;
  c67_y = c67_rdivide(chartInstance, c67_A, c67_B);
  c67_u_opt[1] = c67_y;
  _SFD_SCRIPT_CALL(2U, chartInstance->c67_sfEvent, 14);
  for (c67_i195 = 0; c67_i195 < 4; c67_i195++) {
    c67_L_opt[c67_i195] = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c67_sfEvent, 15);
  c67_b_A = (8.0 * c67_u1_min * c67_w - 8.0 * c67_u_LA * c67_w) + 4.0 * c67_u_LS
    * c67_w;
  c67_b_B = c67_w + 4.0;
  c67_b_y = c67_rdivide(chartInstance, c67_b_A, c67_b_B);
  c67_L_opt[0] = c67_b_y;
  _SFD_SCRIPT_CALL(2U, chartInstance->c67_sfEvent, 16);
  c67_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c67_sfEvent, 17);
  c67_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c67_sfEvent, 18);
  c67_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c67_sfEvent, 19);
  _SFD_SCRIPT_CALL(2U, chartInstance->c67_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c67_LA_LS_Revised_Saturation_Case_3
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u1_max, real_T c67_u_opt[2], real_T
   c67_L_opt[4])
{
  uint32_T c67_debug_family_var_map[8];
  real_T c67_nargin = 7.0;
  real_T c67_nargout = 2.0;
  int32_T c67_i196;
  real_T c67_A;
  real_T c67_B;
  real_T c67_y;
  int32_T c67_i197;
  real_T c67_b_A;
  real_T c67_b_B;
  real_T c67_b_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c67_d_debug_family_names,
    c67_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargin, 0U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargout, 1U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LS, 2U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LA, 3U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_w, 4U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u1_max, 5U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt, 6U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt, 7U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c67_sfEvent, 9);
  for (c67_i196 = 0; c67_i196 < 2; c67_i196++) {
    c67_u_opt[c67_i196] = 0.0;
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c67_sfEvent, 10);
  c67_u_opt[0] = c67_u1_max;
  _SFD_SCRIPT_CALL(3U, chartInstance->c67_sfEvent, 11);
  c67_A = ((4.0 * c67_u1_max + 4.0 * c67_u_LS) - c67_u1_max * c67_w) + 2.0 *
    c67_u_LA * c67_w;
  c67_B = c67_w + 4.0;
  c67_y = c67_rdivide(chartInstance, c67_A, c67_B);
  c67_u_opt[1] = c67_y;
  _SFD_SCRIPT_CALL(3U, chartInstance->c67_sfEvent, 14);
  for (c67_i197 = 0; c67_i197 < 4; c67_i197++) {
    c67_L_opt[c67_i197] = 0.0;
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c67_sfEvent, 15);
  c67_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(3U, chartInstance->c67_sfEvent, 16);
  c67_b_A = -((8.0 * c67_u1_max * c67_w - 8.0 * c67_u_LA * c67_w) + 4.0 *
              c67_u_LS * c67_w);
  c67_b_B = c67_w + 4.0;
  c67_b_y = c67_rdivide(chartInstance, c67_b_A, c67_b_B);
  c67_L_opt[1] = c67_b_y;
  _SFD_SCRIPT_CALL(3U, chartInstance->c67_sfEvent, 17);
  c67_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(3U, chartInstance->c67_sfEvent, 18);
  c67_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(3U, chartInstance->c67_sfEvent, 19);
  _SFD_SCRIPT_CALL(3U, chartInstance->c67_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c67_LA_LS_Revised_Saturation_Case_4
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u2_min, real_T c67_u_opt[2], real_T
   c67_L_opt[4])
{
  uint32_T c67_debug_family_var_map[8];
  real_T c67_nargin = 7.0;
  real_T c67_nargout = 2.0;
  int32_T c67_i198;
  real_T c67_A;
  real_T c67_B;
  real_T c67_y;
  int32_T c67_i199;
  real_T c67_b_A;
  real_T c67_b_B;
  real_T c67_b_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c67_e_debug_family_names,
    c67_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargin, 0U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargout, 1U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LS, 2U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LA, 3U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_w, 4U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u2_min, 5U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt, 6U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt, 7U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  CV_SCRIPT_FCN(4, 0);
  _SFD_SCRIPT_CALL(4U, chartInstance->c67_sfEvent, 9);
  for (c67_i198 = 0; c67_i198 < 2; c67_i198++) {
    c67_u_opt[c67_i198] = 0.0;
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c67_sfEvent, 10);
  c67_A = ((4.0 * c67_u2_min - 4.0 * c67_u_LS) - c67_u2_min * c67_w) + 2.0 *
    c67_u_LA * c67_w;
  c67_B = c67_w + 4.0;
  c67_y = c67_rdivide(chartInstance, c67_A, c67_B);
  c67_u_opt[0] = c67_y;
  _SFD_SCRIPT_CALL(4U, chartInstance->c67_sfEvent, 11);
  c67_u_opt[1] = c67_u2_min;
  _SFD_SCRIPT_CALL(4U, chartInstance->c67_sfEvent, 14);
  for (c67_i199 = 0; c67_i199 < 4; c67_i199++) {
    c67_L_opt[c67_i199] = 0.0;
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c67_sfEvent, 15);
  c67_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c67_sfEvent, 16);
  c67_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c67_sfEvent, 17);
  c67_b_A = -((8.0 * c67_u_LA * c67_w - 8.0 * c67_u2_min * c67_w) + 4.0 *
              c67_u_LS * c67_w);
  c67_b_B = c67_w + 4.0;
  c67_b_y = c67_rdivide(chartInstance, c67_b_A, c67_b_B);
  c67_L_opt[2] = c67_b_y;
  _SFD_SCRIPT_CALL(4U, chartInstance->c67_sfEvent, 18);
  c67_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c67_sfEvent, 19);
  _SFD_SCRIPT_CALL(4U, chartInstance->c67_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c67_LA_LS_Revised_Saturation_Case_5
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u2_max, real_T c67_u_opt[2], real_T
   c67_L_opt[4])
{
  uint32_T c67_debug_family_var_map[8];
  real_T c67_nargin = 7.0;
  real_T c67_nargout = 2.0;
  int32_T c67_i200;
  real_T c67_A;
  real_T c67_B;
  real_T c67_y;
  int32_T c67_i201;
  real_T c67_b_A;
  real_T c67_b_B;
  real_T c67_b_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c67_f_debug_family_names,
    c67_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargin, 0U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargout, 1U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LS, 2U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LA, 3U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_w, 4U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u2_max, 5U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt, 6U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt, 7U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5U, chartInstance->c67_sfEvent, 9);
  for (c67_i200 = 0; c67_i200 < 2; c67_i200++) {
    c67_u_opt[c67_i200] = 0.0;
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c67_sfEvent, 10);
  c67_A = ((4.0 * c67_u2_max - 4.0 * c67_u_LS) - c67_u2_max * c67_w) + 2.0 *
    c67_u_LA * c67_w;
  c67_B = c67_w + 4.0;
  c67_y = c67_rdivide(chartInstance, c67_A, c67_B);
  c67_u_opt[0] = c67_y;
  _SFD_SCRIPT_CALL(5U, chartInstance->c67_sfEvent, 11);
  c67_u_opt[1] = c67_u2_max;
  _SFD_SCRIPT_CALL(5U, chartInstance->c67_sfEvent, 14);
  for (c67_i201 = 0; c67_i201 < 4; c67_i201++) {
    c67_L_opt[c67_i201] = 0.0;
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c67_sfEvent, 15);
  c67_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(5U, chartInstance->c67_sfEvent, 16);
  c67_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(5U, chartInstance->c67_sfEvent, 17);
  c67_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(5U, chartInstance->c67_sfEvent, 18);
  c67_b_A = (8.0 * c67_u_LA * c67_w - 8.0 * c67_u2_max * c67_w) + 4.0 * c67_u_LS
    * c67_w;
  c67_b_B = c67_w + 4.0;
  c67_b_y = c67_rdivide(chartInstance, c67_b_A, c67_b_B);
  c67_L_opt[3] = c67_b_y;
  _SFD_SCRIPT_CALL(5U, chartInstance->c67_sfEvent, 19);
  _SFD_SCRIPT_CALL(5U, chartInstance->c67_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c67_LA_LS_Revised_Saturation_Case_6
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u1_min, real_T c67_u2_min, real_T
   c67_u_opt[2], real_T c67_L_opt[4])
{
  uint32_T c67_debug_family_var_map[9];
  real_T c67_nargin = 7.0;
  real_T c67_nargout = 2.0;
  int32_T c67_i202;
  int32_T c67_i203;
  real_T c67_A;
  real_T c67_y;
  real_T c67_b_A;
  real_T c67_b_y;
  real_T c67_c_A;
  real_T c67_c_y;
  real_T c67_d_A;
  real_T c67_d_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c67_g_debug_family_names,
    c67_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargin, 0U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargout, 1U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LS, 2U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LA, 3U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_w, 4U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u1_min, 5U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u2_min, 6U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt, 7U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt, 8U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  CV_SCRIPT_FCN(6, 0);
  _SFD_SCRIPT_CALL(6U, chartInstance->c67_sfEvent, 9);
  for (c67_i202 = 0; c67_i202 < 2; c67_i202++) {
    c67_u_opt[c67_i202] = 0.0;
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c67_sfEvent, 10);
  c67_u_opt[0] = c67_u1_min;
  _SFD_SCRIPT_CALL(6U, chartInstance->c67_sfEvent, 11);
  c67_u_opt[1] = c67_u2_min;
  _SFD_SCRIPT_CALL(6U, chartInstance->c67_sfEvent, 14);
  for (c67_i203 = 0; c67_i203 < 4; c67_i203++) {
    c67_L_opt[c67_i203] = 0.0;
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c67_sfEvent, 15);
  c67_A = c67_u1_min;
  c67_y = c67_rdivide(chartInstance, c67_A, 2.0);
  c67_b_A = c67_u2_min;
  c67_b_y = c67_rdivide(chartInstance, c67_b_A, 2.0);
  c67_L_opt[0] = ((2.0 * c67_u1_min - 2.0 * c67_u2_min) + 2.0 * c67_u_LS) +
    c67_w * ((c67_y + c67_b_y) - c67_u_LA);
  _SFD_SCRIPT_CALL(6U, chartInstance->c67_sfEvent, 16);
  c67_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(6U, chartInstance->c67_sfEvent, 17);
  c67_c_A = c67_u1_min;
  c67_c_y = c67_rdivide(chartInstance, c67_c_A, 2.0);
  c67_d_A = c67_u2_min;
  c67_d_y = c67_rdivide(chartInstance, c67_d_A, 2.0);
  c67_L_opt[2] = ((2.0 * c67_u2_min - 2.0 * c67_u1_min) - 2.0 * c67_u_LS) +
    c67_w * ((c67_c_y + c67_d_y) - c67_u_LA);
  _SFD_SCRIPT_CALL(6U, chartInstance->c67_sfEvent, 18);
  c67_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(6U, chartInstance->c67_sfEvent, 19);
  _SFD_SCRIPT_CALL(6U, chartInstance->c67_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c67_LA_LS_Revised_Saturation_Case_7
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u1_min, real_T c67_u2_max, real_T
   c67_u_opt[2], real_T c67_L_opt[4])
{
  uint32_T c67_debug_family_var_map[9];
  real_T c67_nargin = 7.0;
  real_T c67_nargout = 2.0;
  int32_T c67_i204;
  int32_T c67_i205;
  real_T c67_A;
  real_T c67_y;
  real_T c67_b_A;
  real_T c67_b_y;
  real_T c67_c_A;
  real_T c67_c_y;
  real_T c67_d_A;
  real_T c67_d_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c67_h_debug_family_names,
    c67_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargin, 0U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargout, 1U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LS, 2U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LA, 3U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_w, 4U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u1_min, 5U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u2_max, 6U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt, 7U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt, 8U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  CV_SCRIPT_FCN(7, 0);
  _SFD_SCRIPT_CALL(7U, chartInstance->c67_sfEvent, 9);
  for (c67_i204 = 0; c67_i204 < 2; c67_i204++) {
    c67_u_opt[c67_i204] = 0.0;
  }

  _SFD_SCRIPT_CALL(7U, chartInstance->c67_sfEvent, 10);
  c67_u_opt[0] = c67_u1_min;
  _SFD_SCRIPT_CALL(7U, chartInstance->c67_sfEvent, 11);
  c67_u_opt[1] = c67_u2_max;
  _SFD_SCRIPT_CALL(7U, chartInstance->c67_sfEvent, 14);
  for (c67_i205 = 0; c67_i205 < 4; c67_i205++) {
    c67_L_opt[c67_i205] = 0.0;
  }

  _SFD_SCRIPT_CALL(7U, chartInstance->c67_sfEvent, 15);
  c67_A = c67_u1_min;
  c67_y = c67_rdivide(chartInstance, c67_A, 2.0);
  c67_b_A = c67_u2_max;
  c67_b_y = c67_rdivide(chartInstance, c67_b_A, 2.0);
  c67_L_opt[0] = ((2.0 * c67_u1_min - 2.0 * c67_u2_max) + 2.0 * c67_u_LS) +
    c67_w * ((c67_y + c67_b_y) - c67_u_LA);
  _SFD_SCRIPT_CALL(7U, chartInstance->c67_sfEvent, 16);
  c67_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(7U, chartInstance->c67_sfEvent, 17);
  c67_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(7U, chartInstance->c67_sfEvent, 18);
  c67_c_A = c67_u1_min * c67_w;
  c67_c_y = c67_rdivide(chartInstance, c67_c_A, 2.0);
  c67_d_A = c67_u2_max * c67_w;
  c67_d_y = c67_rdivide(chartInstance, c67_d_A, 2.0);
  c67_L_opt[3] = ((((2.0 * c67_u1_min - 2.0 * c67_u2_max) + 2.0 * c67_u_LS) -
                   c67_c_y) - c67_d_y) + c67_u_LA * c67_w;
  _SFD_SCRIPT_CALL(7U, chartInstance->c67_sfEvent, 19);
  _SFD_SCRIPT_CALL(7U, chartInstance->c67_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c67_LA_LS_Revised_Saturation_Case_8
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u1_max, real_T c67_u2_min, real_T
   c67_u_opt[2], real_T c67_L_opt[4])
{
  uint32_T c67_debug_family_var_map[9];
  real_T c67_nargin = 7.0;
  real_T c67_nargout = 2.0;
  int32_T c67_i206;
  int32_T c67_i207;
  real_T c67_A;
  real_T c67_y;
  real_T c67_b_A;
  real_T c67_b_y;
  real_T c67_c_A;
  real_T c67_c_y;
  real_T c67_d_A;
  real_T c67_d_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c67_i_debug_family_names,
    c67_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargin, 0U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargout, 1U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LS, 2U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LA, 3U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_w, 4U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u1_max, 5U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u2_min, 6U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt, 7U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt, 8U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  CV_SCRIPT_FCN(8, 0);
  _SFD_SCRIPT_CALL(8U, chartInstance->c67_sfEvent, 9);
  for (c67_i206 = 0; c67_i206 < 2; c67_i206++) {
    c67_u_opt[c67_i206] = 0.0;
  }

  _SFD_SCRIPT_CALL(8U, chartInstance->c67_sfEvent, 10);
  c67_u_opt[0] = c67_u1_max;
  _SFD_SCRIPT_CALL(8U, chartInstance->c67_sfEvent, 11);
  c67_u_opt[1] = c67_u2_min;
  _SFD_SCRIPT_CALL(8U, chartInstance->c67_sfEvent, 14);
  for (c67_i207 = 0; c67_i207 < 4; c67_i207++) {
    c67_L_opt[c67_i207] = 0.0;
  }

  _SFD_SCRIPT_CALL(8U, chartInstance->c67_sfEvent, 15);
  c67_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(8U, chartInstance->c67_sfEvent, 16);
  c67_A = c67_u2_min * c67_w;
  c67_y = c67_rdivide(chartInstance, c67_A, 2.0);
  c67_b_A = c67_u1_max * c67_w;
  c67_b_y = c67_rdivide(chartInstance, c67_b_A, 2.0);
  c67_L_opt[1] = ((((2.0 * c67_u2_min - 2.0 * c67_u1_max) - 2.0 * c67_u_LS) -
                   c67_y) - c67_b_y) + c67_u_LA * c67_w;
  _SFD_SCRIPT_CALL(8U, chartInstance->c67_sfEvent, 17);
  c67_c_A = c67_u2_min;
  c67_c_y = c67_rdivide(chartInstance, c67_c_A, 2.0);
  c67_d_A = c67_u1_max;
  c67_d_y = c67_rdivide(chartInstance, c67_d_A, 2.0);
  c67_L_opt[2] = ((2.0 * c67_u2_min - 2.0 * c67_u1_max) - 2.0 * c67_u_LS) +
    c67_w * ((c67_c_y + c67_d_y) - c67_u_LA);
  _SFD_SCRIPT_CALL(8U, chartInstance->c67_sfEvent, 18);
  c67_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(8U, chartInstance->c67_sfEvent, 19);
  _SFD_SCRIPT_CALL(8U, chartInstance->c67_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c67_LA_LS_Revised_Saturation_Case_9
  (SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c67_u_LS, real_T
   c67_u_LA, real_T c67_w, real_T c67_u1_max, real_T c67_u2_max, real_T
   c67_u_opt[2], real_T c67_L_opt[4])
{
  uint32_T c67_debug_family_var_map[9];
  real_T c67_nargin = 7.0;
  real_T c67_nargout = 2.0;
  int32_T c67_i208;
  int32_T c67_i209;
  real_T c67_A;
  real_T c67_y;
  real_T c67_b_A;
  real_T c67_b_y;
  real_T c67_c_A;
  real_T c67_c_y;
  real_T c67_d_A;
  real_T c67_d_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c67_j_debug_family_names,
    c67_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargin, 0U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_nargout, 1U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LS, 2U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u_LA, 3U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_w, 4U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u1_max, 5U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c67_u2_max, 6U, c67_e_sf_marshallOut,
    c67_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_u_opt, 7U, c67_d_sf_marshallOut,
    c67_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c67_L_opt, 8U, c67_g_sf_marshallOut,
    c67_e_sf_marshallIn);
  CV_SCRIPT_FCN(9, 0);
  _SFD_SCRIPT_CALL(9U, chartInstance->c67_sfEvent, 9);
  for (c67_i208 = 0; c67_i208 < 2; c67_i208++) {
    c67_u_opt[c67_i208] = 0.0;
  }

  _SFD_SCRIPT_CALL(9U, chartInstance->c67_sfEvent, 10);
  c67_u_opt[0] = c67_u1_max;
  _SFD_SCRIPT_CALL(9U, chartInstance->c67_sfEvent, 11);
  c67_u_opt[1] = c67_u2_max;
  _SFD_SCRIPT_CALL(9U, chartInstance->c67_sfEvent, 14);
  for (c67_i209 = 0; c67_i209 < 4; c67_i209++) {
    c67_L_opt[c67_i209] = 0.0;
  }

  _SFD_SCRIPT_CALL(9U, chartInstance->c67_sfEvent, 15);
  c67_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(9U, chartInstance->c67_sfEvent, 16);
  c67_A = c67_u1_max * c67_w;
  c67_y = c67_rdivide(chartInstance, c67_A, 2.0);
  c67_b_A = c67_u2_max * c67_w;
  c67_b_y = c67_rdivide(chartInstance, c67_b_A, 2.0);
  c67_L_opt[1] = ((((2.0 * c67_u2_max - 2.0 * c67_u1_max) - 2.0 * c67_u_LS) -
                   c67_y) - c67_b_y) + c67_u_LA * c67_w;
  _SFD_SCRIPT_CALL(9U, chartInstance->c67_sfEvent, 17);
  c67_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(9U, chartInstance->c67_sfEvent, 18);
  c67_c_A = c67_u1_max * c67_w;
  c67_c_y = c67_rdivide(chartInstance, c67_c_A, 2.0);
  c67_d_A = c67_u2_max * c67_w;
  c67_d_y = c67_rdivide(chartInstance, c67_d_A, 2.0);
  c67_L_opt[3] = ((((2.0 * c67_u1_max - 2.0 * c67_u2_max) + 2.0 * c67_u_LS) -
                   c67_c_y) - c67_d_y) + c67_u_LA * c67_w;
  _SFD_SCRIPT_CALL(9U, chartInstance->c67_sfEvent, 19);
  _SFD_SCRIPT_CALL(9U, chartInstance->c67_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c67_machineNumber, uint32_T
  c67_chartNumber, uint32_T c67_instanceNumber)
{
  (void)c67_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c67_chartNumber, c67_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation.m"));
  _SFD_SCRIPT_TRANSLATION(c67_chartNumber, c67_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_1.m"));
  _SFD_SCRIPT_TRANSLATION(c67_chartNumber, c67_instanceNumber, 2U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_2.m"));
  _SFD_SCRIPT_TRANSLATION(c67_chartNumber, c67_instanceNumber, 3U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_3.m"));
  _SFD_SCRIPT_TRANSLATION(c67_chartNumber, c67_instanceNumber, 4U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_4.m"));
  _SFD_SCRIPT_TRANSLATION(c67_chartNumber, c67_instanceNumber, 5U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_5.m"));
  _SFD_SCRIPT_TRANSLATION(c67_chartNumber, c67_instanceNumber, 6U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_6.m"));
  _SFD_SCRIPT_TRANSLATION(c67_chartNumber, c67_instanceNumber, 7U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_7.m"));
  _SFD_SCRIPT_TRANSLATION(c67_chartNumber, c67_instanceNumber, 8U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_8.m"));
  _SFD_SCRIPT_TRANSLATION(c67_chartNumber, c67_instanceNumber, 9U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_9.m"));
}

static const mxArray *c67_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData)
{
  const mxArray *c67_mxArrayOutData = NULL;
  int32_T c67_i210;
  real_T c67_b_inData[6];
  int32_T c67_i211;
  real_T c67_b_u[6];
  const mxArray *c67_y = NULL;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_mxArrayOutData = NULL;
  for (c67_i210 = 0; c67_i210 < 6; c67_i210++) {
    c67_b_inData[c67_i210] = (*(real_T (*)[6])c67_inData)[c67_i210];
  }

  for (c67_i211 = 0; c67_i211 < 6; c67_i211++) {
    c67_b_u[c67_i211] = c67_b_inData[c67_i211];
  }

  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", c67_b_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c67_mxArrayOutData, c67_y, false);
  return c67_mxArrayOutData;
}

static void c67_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u_sat, const char_T *c67_identifier,
  real_T c67_y[6])
{
  emlrtMsgIdentifier c67_thisId;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c67_b_u_sat), &c67_thisId,
    c67_y);
  sf_mex_destroy(&c67_b_u_sat);
}

static void c67_b_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[6])
{
  real_T c67_dv4[6];
  int32_T c67_i212;
  (void)chartInstance;
  sf_mex_import(c67_parentId, sf_mex_dup(c67_b_u), c67_dv4, 1, 0, 0U, 1, 0U, 1,
                6);
  for (c67_i212 = 0; c67_i212 < 6; c67_i212++) {
    c67_y[c67_i212] = c67_dv4[c67_i212];
  }

  sf_mex_destroy(&c67_b_u);
}

static void c67_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData)
{
  const mxArray *c67_b_u_sat;
  const char_T *c67_identifier;
  emlrtMsgIdentifier c67_thisId;
  real_T c67_y[6];
  int32_T c67_i213;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_b_u_sat = sf_mex_dup(c67_mxArrayInData);
  c67_identifier = c67_varName;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c67_b_u_sat), &c67_thisId,
    c67_y);
  sf_mex_destroy(&c67_b_u_sat);
  for (c67_i213 = 0; c67_i213 < 6; c67_i213++) {
    (*(real_T (*)[6])c67_outData)[c67_i213] = c67_y[c67_i213];
  }

  sf_mex_destroy(&c67_mxArrayInData);
}

static const mxArray *c67_b_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData)
{
  const mxArray *c67_mxArrayOutData;
  c67_ControlParamsBus c67_b_u;
  const mxArray *c67_y = NULL;
  c67_SupervisoryParamsBus c67_c_u;
  const mxArray *c67_b_y = NULL;
  real_T c67_d_u;
  const mxArray *c67_c_y = NULL;
  real_T c67_e_u;
  const mxArray *c67_d_y = NULL;
  real_T c67_f_u;
  const mxArray *c67_e_y = NULL;
  real_T c67_g_u;
  const mxArray *c67_f_y = NULL;
  real_T c67_h_u;
  const mxArray *c67_g_y = NULL;
  real_T c67_i_u;
  const mxArray *c67_h_y = NULL;
  real_T c67_j_u;
  const mxArray *c67_i_y = NULL;
  real_T c67_k_u;
  const mxArray *c67_j_y = NULL;
  real_T c67_l_u;
  const mxArray *c67_k_y = NULL;
  real_T c67_m_u;
  const mxArray *c67_l_y = NULL;
  real_T c67_n_u;
  const mxArray *c67_m_y = NULL;
  int32_T c67_i214;
  real_T c67_o_u[2];
  const mxArray *c67_n_y = NULL;
  real_T c67_p_u;
  const mxArray *c67_o_y = NULL;
  real_T c67_q_u;
  const mxArray *c67_p_y = NULL;
  int32_T c67_i215;
  real_T c67_r_u[6];
  const mxArray *c67_q_y = NULL;
  int32_T c67_i216;
  real_T c67_s_u[13];
  const mxArray *c67_r_y = NULL;
  int32_T c67_i217;
  real_T c67_t_u[5];
  const mxArray *c67_s_y = NULL;
  real_T c67_u_u;
  const mxArray *c67_t_y = NULL;
  real_T c67_v_u;
  const mxArray *c67_u_y = NULL;
  real_T c67_w_u;
  const mxArray *c67_v_y = NULL;
  real_T c67_x_u;
  const mxArray *c67_w_y = NULL;
  int32_T c67_i218;
  real_T c67_y_u[6];
  const mxArray *c67_x_y = NULL;
  int32_T c67_i219;
  real_T c67_ab_u[6];
  const mxArray *c67_y_y = NULL;
  real_T c67_bb_u;
  const mxArray *c67_ab_y = NULL;
  real_T c67_cb_u;
  const mxArray *c67_bb_y = NULL;
  real_T c67_db_u;
  const mxArray *c67_cb_y = NULL;
  real_T c67_eb_u;
  const mxArray *c67_db_y = NULL;
  real_T c67_fb_u;
  const mxArray *c67_eb_y = NULL;
  real_T c67_gb_u;
  const mxArray *c67_fb_y = NULL;
  real_T c67_hb_u;
  const mxArray *c67_gb_y = NULL;
  real_T c67_ib_u;
  const mxArray *c67_hb_y = NULL;
  real_T c67_jb_u;
  const mxArray *c67_ib_y = NULL;
  real_T c67_kb_u;
  const mxArray *c67_jb_y = NULL;
  real_T c67_lb_u;
  const mxArray *c67_kb_y = NULL;
  real_T c67_mb_u;
  const mxArray *c67_lb_y = NULL;
  real_T c67_nb_u;
  const mxArray *c67_mb_y = NULL;
  real_T c67_ob_u;
  const mxArray *c67_nb_y = NULL;
  real_T c67_pb_u;
  const mxArray *c67_ob_y = NULL;
  real_T c67_qb_u;
  const mxArray *c67_pb_y = NULL;
  real_T c67_rb_u;
  const mxArray *c67_qb_y = NULL;
  real_T c67_sb_u;
  const mxArray *c67_rb_y = NULL;
  real_T c67_tb_u;
  const mxArray *c67_sb_y = NULL;
  real_T c67_ub_u;
  const mxArray *c67_tb_y = NULL;
  real_T c67_vb_u;
  const mxArray *c67_ub_y = NULL;
  int32_T c67_i220;
  real_T c67_wb_u[6];
  const mxArray *c67_vb_y = NULL;
  int32_T c67_i221;
  real_T c67_xb_u[6];
  const mxArray *c67_wb_y = NULL;
  real_T c67_yb_u;
  const mxArray *c67_xb_y = NULL;
  int32_T c67_i222;
  real_T c67_ac_u[6];
  const mxArray *c67_yb_y = NULL;
  int32_T c67_i223;
  real_T c67_bc_u[6];
  const mxArray *c67_ac_y = NULL;
  real_T c67_cc_u;
  const mxArray *c67_bc_y = NULL;
  int32_T c67_i224;
  real_T c67_dc_u[12];
  const mxArray *c67_cc_y = NULL;
  real_T c67_ec_u;
  const mxArray *c67_dc_y = NULL;
  real_T c67_fc_u;
  const mxArray *c67_ec_y = NULL;
  real_T c67_gc_u;
  const mxArray *c67_fc_y = NULL;
  real_T c67_hc_u;
  const mxArray *c67_gc_y = NULL;
  real_T c67_ic_u;
  const mxArray *c67_hc_y = NULL;
  real_T c67_jc_u;
  const mxArray *c67_ic_y = NULL;
  real_T c67_kc_u;
  const mxArray *c67_jc_y = NULL;
  real_T c67_lc_u;
  const mxArray *c67_kc_y = NULL;
  real_T c67_mc_u;
  const mxArray *c67_lc_y = NULL;
  real_T c67_nc_u;
  const mxArray *c67_mc_y = NULL;
  real_T c67_oc_u;
  const mxArray *c67_nc_y = NULL;
  int32_T c67_i225;
  real_T c67_pc_u[6];
  const mxArray *c67_oc_y = NULL;
  c67_DiscreteParamsBus c67_qc_u;
  const mxArray *c67_pc_y = NULL;
  real_T c67_rc_u;
  const mxArray *c67_qc_y = NULL;
  real_T c67_sc_u;
  const mxArray *c67_rc_y = NULL;
  real_T c67_tc_u;
  const mxArray *c67_sc_y = NULL;
  real_T c67_uc_u;
  const mxArray *c67_tc_y = NULL;
  real_T c67_vc_u;
  const mxArray *c67_uc_y = NULL;
  real_T c67_wc_u;
  const mxArray *c67_vc_y = NULL;
  real_T c67_xc_u;
  const mxArray *c67_wc_y = NULL;
  real_T c67_yc_u;
  const mxArray *c67_xc_y = NULL;
  real_T c67_ad_u;
  const mxArray *c67_yc_y = NULL;
  real_T c67_bd_u;
  const mxArray *c67_ad_y = NULL;
  real_T c67_cd_u;
  const mxArray *c67_bd_y = NULL;
  c67_OutputParamsBus c67_dd_u;
  const mxArray *c67_cd_y = NULL;
  int32_T c67_i226;
  real_T c67_ed_u[78];
  const mxArray *c67_dd_y = NULL;
  int32_T c67_i227;
  real_T c67_fd_u[36];
  const mxArray *c67_ed_y = NULL;
  int32_T c67_i228;
  real_T c67_gd_u[2];
  const mxArray *c67_fd_y = NULL;
  c67_ThetaParamsBus c67_hd_u;
  const mxArray *c67_gd_y = NULL;
  real_T c67_id_u;
  const mxArray *c67_hd_y = NULL;
  real_T c67_jd_u;
  const mxArray *c67_id_y = NULL;
  int32_T c67_i229;
  real_T c67_kd_u[13];
  const mxArray *c67_jd_y = NULL;
  real_T c67_ld_u;
  const mxArray *c67_kd_y = NULL;
  int32_T c67_i230;
  real_T c67_md_u[7];
  const mxArray *c67_ld_y = NULL;
  real_T c67_nd_u;
  const mxArray *c67_md_y = NULL;
  int32_T c67_i231;
  real_T c67_od_u[2];
  const mxArray *c67_nd_y = NULL;
  real_T c67_pd_u;
  const mxArray *c67_od_y = NULL;
  real_T c67_qd_u;
  const mxArray *c67_pd_y = NULL;
  real_T c67_rd_u;
  const mxArray *c67_qd_y = NULL;
  int32_T c67_i232;
  real_T c67_sd_u[30];
  const mxArray *c67_rd_y = NULL;
  c67_PhiParamsBus c67_td_u;
  const mxArray *c67_sd_y = NULL;
  real_T c67_ud_u;
  const mxArray *c67_td_y = NULL;
  int32_T c67_i233;
  real_T c67_vd_u[13];
  const mxArray *c67_ud_y = NULL;
  int32_T c67_i234;
  real_T c67_wd_u[20];
  const mxArray *c67_vd_y = NULL;
  real_T c67_xd_u;
  const mxArray *c67_wd_y = NULL;
  int32_T c67_i235;
  real_T c67_yd_u[2];
  const mxArray *c67_xd_y = NULL;
  int32_T c67_i236;
  real_T c67_ae_u[30];
  const mxArray *c67_yd_y = NULL;
  int32_T c67_i237;
  real_T c67_be_u[12];
  const mxArray *c67_ae_y = NULL;
  int32_T c67_i238;
  real_T c67_ce_u[36];
  const mxArray *c67_be_y = NULL;
  real_T c67_de_u;
  const mxArray *c67_ce_y = NULL;
  real_T c67_ee_u;
  const mxArray *c67_de_y = NULL;
  c67_FeedbackParamsBus c67_fe_u;
  const mxArray *c67_ee_y = NULL;
  int32_T c67_i239;
  real_T c67_ge_u[6];
  const mxArray *c67_fe_y = NULL;
  int32_T c67_i240;
  real_T c67_he_u[6];
  const mxArray *c67_ge_y = NULL;
  int32_T c67_i241;
  real_T c67_ie_u[2];
  const mxArray *c67_he_y = NULL;
  int32_T c67_i242;
  real_T c67_je_u[2];
  const mxArray *c67_ie_y = NULL;
  real_T c67_ke_u;
  const mxArray *c67_je_y = NULL;
  int32_T c67_i243;
  real_T c67_le_u[2];
  const mxArray *c67_ke_y = NULL;
  int32_T c67_i244;
  real_T c67_me_u[2];
  const mxArray *c67_le_y = NULL;
  real_T c67_ne_u;
  const mxArray *c67_me_y = NULL;
  real_T c67_oe_u;
  const mxArray *c67_ne_y = NULL;
  real_T c67_pe_u;
  const mxArray *c67_oe_y = NULL;
  real_T c67_qe_u;
  const mxArray *c67_pe_y = NULL;
  real_T c67_re_u;
  const mxArray *c67_qe_y = NULL;
  real_T c67_se_u;
  const mxArray *c67_re_y = NULL;
  real_T c67_te_u;
  const mxArray *c67_se_y = NULL;
  real_T c67_ue_u;
  const mxArray *c67_te_y = NULL;
  int32_T c67_i245;
  real_T c67_ve_u[6];
  const mxArray *c67_ue_y = NULL;
  real_T c67_we_u;
  const mxArray *c67_ve_y = NULL;
  real_T c67_xe_u;
  const mxArray *c67_we_y = NULL;
  real_T c67_ye_u;
  const mxArray *c67_xe_y = NULL;
  real_T c67_af_u;
  const mxArray *c67_ye_y = NULL;
  real_T c67_bf_u;
  const mxArray *c67_af_y = NULL;
  real_T c67_cf_u;
  const mxArray *c67_bf_y = NULL;
  real_T c67_df_u;
  const mxArray *c67_cf_y = NULL;
  real_T c67_ef_u;
  const mxArray *c67_df_y = NULL;
  real_T c67_ff_u;
  const mxArray *c67_ef_y = NULL;
  int32_T c67_i246;
  real_T c67_gf_u[6];
  const mxArray *c67_ff_y = NULL;
  real_T c67_hf_u;
  const mxArray *c67_gf_y = NULL;
  c67_SaturationParamsBus c67_if_u;
  const mxArray *c67_hf_y = NULL;
  real_T c67_jf_u;
  const mxArray *c67_if_y = NULL;
  int32_T c67_i247;
  real_T c67_kf_u[2];
  const mxArray *c67_jf_y = NULL;
  real_T c67_lf_u;
  const mxArray *c67_kf_y = NULL;
  real_T c67_mf_u;
  const mxArray *c67_lf_y = NULL;
  real_T c67_nf_u;
  const mxArray *c67_mf_y = NULL;
  real_T c67_of_u;
  const mxArray *c67_nf_y = NULL;
  real_T c67_pf_u;
  const mxArray *c67_of_y = NULL;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_mxArrayOutData = NULL;
  c67_mxArrayOutData = NULL;
  c67_b_u = *(c67_ControlParamsBus *)c67_inData;
  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c67_c_u = c67_b_u.Supervisory;
  c67_b_y = NULL;
  sf_mex_assign(&c67_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c67_d_u = c67_c_u.EnableSwapOnKAAccel;
  c67_c_y = NULL;
  sf_mex_assign(&c67_c_y, sf_mex_create("y", &c67_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_c_y, "EnableSwapOnKAAccel", "EnableSwapOnKAAccel",
                  0);
  c67_e_u = c67_c_u.EnableSwapOnKASpring;
  c67_d_y = NULL;
  sf_mex_assign(&c67_d_y, sf_mex_create("y", &c67_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_d_y, "EnableSwapOnKASpring",
                  "EnableSwapOnKASpring", 0);
  c67_f_u = c67_c_u.EnableBackwardSwap;
  c67_e_y = NULL;
  sf_mex_assign(&c67_e_y, sf_mex_create("y", &c67_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_e_y, "EnableBackwardSwap", "EnableBackwardSwap",
                  0);
  c67_g_u = c67_c_u.ImpactThresholdKAAccel;
  c67_f_y = NULL;
  sf_mex_assign(&c67_f_y, sf_mex_create("y", &c67_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_f_y, "ImpactThresholdKAAccel",
                  "ImpactThresholdKAAccel", 0);
  c67_h_u = c67_c_u.ImpactThresholdKASpringAbs;
  c67_g_y = NULL;
  sf_mex_assign(&c67_g_y, sf_mex_create("y", &c67_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_g_y, "ImpactThresholdKASpringAbs",
                  "ImpactThresholdKASpringAbs", 0);
  c67_i_u = c67_c_u.ImpactThresholdKASpringRel;
  c67_h_y = NULL;
  sf_mex_assign(&c67_h_y, sf_mex_create("y", &c67_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_h_y, "ImpactThresholdKASpringRel",
                  "ImpactThresholdKASpringRel", 0);
  c67_j_u = c67_c_u.SwapThresholdS;
  c67_i_y = NULL;
  sf_mex_assign(&c67_i_y, sf_mex_create("y", &c67_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_i_y, "SwapThresholdS", "SwapThresholdS", 0);
  c67_k_u = c67_c_u.AllowDoubleSupport;
  c67_j_y = NULL;
  sf_mex_assign(&c67_j_y, sf_mex_create("y", &c67_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_j_y, "AllowDoubleSupport", "AllowDoubleSupport",
                  0);
  c67_l_u = c67_c_u.UseGaitTransition;
  c67_k_y = NULL;
  sf_mex_assign(&c67_k_y, sf_mex_create("y", &c67_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_k_y, "UseGaitTransition", "UseGaitTransition", 0);
  c67_m_u = c67_c_u.NumTransitionSteps;
  c67_l_y = NULL;
  sf_mex_assign(&c67_l_y, sf_mex_create("y", &c67_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_l_y, "NumTransitionSteps", "NumTransitionSteps",
                  0);
  c67_n_u = c67_c_u.TransitionThresholdTorsoVel;
  c67_m_y = NULL;
  sf_mex_assign(&c67_m_y, sf_mex_create("y", &c67_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_m_y, "TransitionThresholdTorsoVel",
                  "TransitionThresholdTorsoVel", 0);
  for (c67_i214 = 0; c67_i214 < 2; c67_i214++) {
    c67_o_u[c67_i214] = c67_c_u.KAInjection[c67_i214];
  }

  c67_n_y = NULL;
  sf_mex_assign(&c67_n_y, sf_mex_create("y", c67_o_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c67_b_y, c67_n_y, "KAInjection", "KAInjection", 0);
  c67_p_u = c67_c_u.MinDeltaThetaTransition;
  c67_o_y = NULL;
  sf_mex_assign(&c67_o_y, sf_mex_create("y", &c67_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_o_y, "MinDeltaThetaTransition",
                  "MinDeltaThetaTransition", 0);
  c67_q_u = c67_c_u.StartSecondGaitOnStep;
  c67_p_y = NULL;
  sf_mex_assign(&c67_p_y, sf_mex_create("y", &c67_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_p_y, "StartSecondGaitOnStep",
                  "StartSecondGaitOnStep", 0);
  for (c67_i215 = 0; c67_i215 < 6; c67_i215++) {
    c67_r_u[c67_i215] = c67_c_u.VBLAParams[c67_i215];
  }

  c67_q_y = NULL;
  sf_mex_assign(&c67_q_y, sf_mex_create("y", c67_r_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c67_b_y, c67_q_y, "VBLAParams", "VBLAParams", 0);
  for (c67_i216 = 0; c67_i216 < 13; c67_i216++) {
    c67_s_u[c67_i216] = c67_c_u.BalanceParams[c67_i216];
  }

  c67_r_y = NULL;
  sf_mex_assign(&c67_r_y, sf_mex_create("y", c67_s_u, 0, 0U, 1U, 0U, 1, 13),
                false);
  sf_mex_addfield(c67_b_y, c67_r_y, "BalanceParams", "BalanceParams", 0);
  for (c67_i217 = 0; c67_i217 < 5; c67_i217++) {
    c67_t_u[c67_i217] = c67_c_u.GaitTweaks[c67_i217];
  }

  c67_s_y = NULL;
  sf_mex_assign(&c67_s_y, sf_mex_create("y", c67_t_u, 0, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_addfield(c67_b_y, c67_s_y, "GaitTweaks", "GaitTweaks", 0);
  c67_u_u = c67_c_u.TStepInitial;
  c67_t_y = NULL;
  sf_mex_assign(&c67_t_y, sf_mex_create("y", &c67_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_t_y, "TStepInitial", "TStepInitial", 0);
  c67_v_u = c67_c_u.TMaxUpdate;
  c67_u_y = NULL;
  sf_mex_assign(&c67_u_y, sf_mex_create("y", &c67_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_u_y, "TMaxUpdate", "TMaxUpdate", 0);
  c67_w_u = c67_c_u.RunMode;
  c67_v_y = NULL;
  sf_mex_assign(&c67_v_y, sf_mex_create("y", &c67_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_v_y, "RunMode", "RunMode", 0);
  c67_x_u = c67_c_u.UseAbsoluteSwingLA;
  c67_w_y = NULL;
  sf_mex_assign(&c67_w_y, sf_mex_create("y", &c67_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_b_y, c67_w_y, "UseAbsoluteSwingLA", "UseAbsoluteSwingLA",
                  0);
  for (c67_i218 = 0; c67_i218 < 6; c67_i218++) {
    c67_y_u[c67_i218] = c67_c_u.ErrorZeroFactor[c67_i218];
  }

  c67_x_y = NULL;
  sf_mex_assign(&c67_x_y, sf_mex_create("y", c67_y_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c67_b_y, c67_x_y, "ErrorZeroFactor", "ErrorZeroFactor", 0);
  for (c67_i219 = 0; c67_i219 < 6; c67_i219++) {
    c67_ab_u[c67_i219] = c67_c_u.ErrorVelZeroFactor[c67_i219];
  }

  c67_y_y = NULL;
  sf_mex_assign(&c67_y_y, sf_mex_create("y", c67_ab_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c67_b_y, c67_y_y, "ErrorVelZeroFactor", "ErrorVelZeroFactor",
                  0);
  c67_bb_u = c67_c_u.StanceLegInit;
  c67_ab_y = NULL;
  sf_mex_assign(&c67_ab_y, sf_mex_create("y", &c67_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_ab_y, "StanceLegInit", "StanceLegInit", 0);
  c67_cb_u = c67_c_u.ControllerModeInit;
  c67_bb_y = NULL;
  sf_mex_assign(&c67_bb_y, sf_mex_create("y", &c67_cb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_bb_y, "ControllerModeInit", "ControllerModeInit",
                  0);
  c67_db_u = c67_c_u.UsePosingControl;
  c67_cb_y = NULL;
  sf_mex_assign(&c67_cb_y, sf_mex_create("y", &c67_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_cb_y, "UsePosingControl", "UsePosingControl", 0);
  c67_eb_u = c67_c_u.TPosing;
  c67_db_y = NULL;
  sf_mex_assign(&c67_db_y, sf_mex_create("y", &c67_eb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_db_y, "TPosing", "TPosing", 0);
  c67_fb_u = c67_c_u.TorsoBackAngle;
  c67_eb_y = NULL;
  sf_mex_assign(&c67_eb_y, sf_mex_create("y", &c67_fb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_eb_y, "TorsoBackAngle", "TorsoBackAngle", 0);
  c67_gb_u = c67_c_u.TorsoBackOnStep;
  c67_fb_y = NULL;
  sf_mex_assign(&c67_fb_y, sf_mex_create("y", &c67_gb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_fb_y, "TorsoBackOnStep", "TorsoBackOnStep", 0);
  c67_hb_u = c67_c_u.EnergyControlGain;
  c67_gb_y = NULL;
  sf_mex_assign(&c67_gb_y, sf_mex_create("y", &c67_hb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_gb_y, "EnergyControlGain", "EnergyControlGain", 0);
  c67_ib_u = c67_c_u.EnergyControlPhi0;
  c67_hb_y = NULL;
  sf_mex_assign(&c67_hb_y, sf_mex_create("y", &c67_ib_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_hb_y, "EnergyControlPhi0", "EnergyControlPhi0", 0);
  c67_jb_u = c67_c_u.VelocityControlTorsoMax;
  c67_ib_y = NULL;
  sf_mex_assign(&c67_ib_y, sf_mex_create("y", &c67_jb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_ib_y, "VelocityControlTorsoMax",
                  "VelocityControlTorsoMax", 0);
  c67_kb_u = c67_c_u.VelocityControlTorsoMin;
  c67_jb_y = NULL;
  sf_mex_assign(&c67_jb_y, sf_mex_create("y", &c67_kb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_jb_y, "VelocityControlTorsoMin",
                  "VelocityControlTorsoMin", 0);
  c67_lb_u = c67_c_u.VelocityControlTorsoGain;
  c67_kb_y = NULL;
  sf_mex_assign(&c67_kb_y, sf_mex_create("y", &c67_lb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_kb_y, "VelocityControlTorsoGain",
                  "VelocityControlTorsoGain", 0);
  c67_mb_u = c67_c_u.VelocityControlTorsoV0;
  c67_lb_y = NULL;
  sf_mex_assign(&c67_lb_y, sf_mex_create("y", &c67_mb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_lb_y, "VelocityControlTorsoV0",
                  "VelocityControlTorsoV0", 0);
  c67_nb_u = c67_c_u.MinDeltaTheta;
  c67_mb_y = NULL;
  sf_mex_assign(&c67_mb_y, sf_mex_create("y", &c67_nb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_mb_y, "MinDeltaTheta", "MinDeltaTheta", 0);
  c67_ob_u = c67_c_u.Theta0;
  c67_nb_y = NULL;
  sf_mex_assign(&c67_nb_y, sf_mex_create("y", &c67_ob_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_nb_y, "Theta0", "Theta0", 0);
  c67_pb_u = c67_c_u.KThetaPlus;
  c67_ob_y = NULL;
  sf_mex_assign(&c67_ob_y, sf_mex_create("y", &c67_pb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_ob_y, "KThetaPlus", "KThetaPlus", 0);
  c67_qb_u = c67_c_u.KThetaMinus;
  c67_pb_y = NULL;
  sf_mex_assign(&c67_pb_y, sf_mex_create("y", &c67_qb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_pb_y, "KThetaMinus", "KThetaMinus", 0);
  c67_rb_u = c67_c_u.RollPhaseVelocityThresh;
  c67_qb_y = NULL;
  sf_mex_assign(&c67_qb_y, sf_mex_create("y", &c67_rb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_qb_y, "RollPhaseVelocityThresh",
                  "RollPhaseVelocityThresh", 0);
  c67_sb_u = c67_c_u.RollPhaseSThresh;
  c67_rb_y = NULL;
  sf_mex_assign(&c67_rb_y, sf_mex_create("y", &c67_sb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_rb_y, "RollPhaseSThresh", "RollPhaseSThresh", 0);
  c67_tb_u = c67_c_u.MaxError;
  c67_sb_y = NULL;
  sf_mex_assign(&c67_sb_y, sf_mex_create("y", &c67_tb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_sb_y, "MaxError", "MaxError", 0);
  c67_ub_u = c67_c_u.MaxErrorVel;
  c67_tb_y = NULL;
  sf_mex_assign(&c67_tb_y, sf_mex_create("y", &c67_ub_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_tb_y, "MaxErrorVel", "MaxErrorVel", 0);
  c67_vb_u = c67_c_u.MaxErrorCount;
  c67_ub_y = NULL;
  sf_mex_assign(&c67_ub_y, sf_mex_create("y", &c67_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_ub_y, "MaxErrorCount", "MaxErrorCount", 0);
  for (c67_i220 = 0; c67_i220 < 6; c67_i220++) {
    c67_wb_u[c67_i220] = c67_c_u.K1MidStanceUpdate[c67_i220];
  }

  c67_vb_y = NULL;
  sf_mex_assign(&c67_vb_y, sf_mex_create("y", c67_wb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c67_b_y, c67_vb_y, "K1MidStanceUpdate", "K1MidStanceUpdate", 0);
  for (c67_i221 = 0; c67_i221 < 6; c67_i221++) {
    c67_xb_u[c67_i221] = c67_c_u.K2MidStanceUpdate[c67_i221];
  }

  c67_wb_y = NULL;
  sf_mex_assign(&c67_wb_y, sf_mex_create("y", c67_xb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c67_b_y, c67_wb_y, "K2MidStanceUpdate", "K2MidStanceUpdate", 0);
  c67_yb_u = c67_c_u.EnableVelocityBasedUpdate;
  c67_xb_y = NULL;
  sf_mex_assign(&c67_xb_y, sf_mex_create("y", &c67_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_xb_y, "EnableVelocityBasedUpdate",
                  "EnableVelocityBasedUpdate", 0);
  for (c67_i222 = 0; c67_i222 < 6; c67_i222++) {
    c67_ac_u[c67_i222] = c67_c_u.VelocityBasedUpdateK1[c67_i222];
  }

  c67_yb_y = NULL;
  sf_mex_assign(&c67_yb_y, sf_mex_create("y", c67_ac_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c67_b_y, c67_yb_y, "VelocityBasedUpdateK1",
                  "VelocityBasedUpdateK1", 0);
  for (c67_i223 = 0; c67_i223 < 6; c67_i223++) {
    c67_bc_u[c67_i223] = c67_c_u.VelocityBasedUpdateK2[c67_i223];
  }

  c67_ac_y = NULL;
  sf_mex_assign(&c67_ac_y, sf_mex_create("y", c67_bc_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c67_b_y, c67_ac_y, "VelocityBasedUpdateK2",
                  "VelocityBasedUpdateK2", 0);
  c67_cc_u = c67_c_u.VelocityBasedUpdateDTheta0;
  c67_bc_y = NULL;
  sf_mex_assign(&c67_bc_y, sf_mex_create("y", &c67_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_bc_y, "VelocityBasedUpdateDTheta0",
                  "VelocityBasedUpdateDTheta0", 0);
  for (c67_i224 = 0; c67_i224 < 12; c67_i224++) {
    c67_dc_u[c67_i224] = c67_c_u.VelocityBasedUpdateLimits[c67_i224];
  }

  c67_cc_y = NULL;
  sf_mex_assign(&c67_cc_y, sf_mex_create("y", c67_dc_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c67_b_y, c67_cc_y, "VelocityBasedUpdateLimits",
                  "VelocityBasedUpdateLimits", 0);
  c67_ec_u = c67_c_u.DesiredYawOffset;
  c67_dc_y = NULL;
  sf_mex_assign(&c67_dc_y, sf_mex_create("y", &c67_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_dc_y, "DesiredYawOffset", "DesiredYawOffset", 0);
  c67_fc_u = c67_c_u.dx_cmd;
  c67_ec_y = NULL;
  sf_mex_assign(&c67_ec_y, sf_mex_create("y", &c67_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_ec_y, "dx_cmd", "dx_cmd", 0);
  c67_gc_u = c67_c_u.ForBackward;
  c67_fc_y = NULL;
  sf_mex_assign(&c67_fc_y, sf_mex_create("y", &c67_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_fc_y, "ForBackward", "ForBackward", 0);
  c67_hc_u = c67_c_u.EnableFrictionID;
  c67_gc_y = NULL;
  sf_mex_assign(&c67_gc_y, sf_mex_create("y", &c67_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_gc_y, "EnableFrictionID", "EnableFrictionID", 0);
  c67_ic_u = c67_c_u.ResetFrictionPosing;
  c67_hc_y = NULL;
  sf_mex_assign(&c67_hc_y, sf_mex_create("y", &c67_ic_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_hc_y, "ResetFrictionPosing",
                  "ResetFrictionPosing", 0);
  c67_jc_u = c67_c_u.MoveLegIndex;
  c67_ic_y = NULL;
  sf_mex_assign(&c67_ic_y, sf_mex_create("y", &c67_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_ic_y, "MoveLegIndex", "MoveLegIndex", 0);
  c67_kc_u = c67_c_u.dy_cmd;
  c67_jc_y = NULL;
  sf_mex_assign(&c67_jc_y, sf_mex_create("y", &c67_kc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_jc_y, "dy_cmd", "dy_cmd", 0);
  c67_lc_u = c67_c_u.TauDelay;
  c67_kc_y = NULL;
  sf_mex_assign(&c67_kc_y, sf_mex_create("y", &c67_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_kc_y, "TauDelay", "TauDelay", 0);
  c67_mc_u = c67_c_u.TrackFrequency;
  c67_lc_y = NULL;
  sf_mex_assign(&c67_lc_y, sf_mex_create("y", &c67_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_lc_y, "TrackFrequency", "TrackFrequency", 0);
  c67_nc_u = c67_c_u.EnablePDControl;
  c67_mc_y = NULL;
  sf_mex_assign(&c67_mc_y, sf_mex_create("y", &c67_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_mc_y, "EnablePDControl", "EnablePDControl", 0);
  c67_oc_u = c67_c_u.TorqueAmp;
  c67_nc_y = NULL;
  sf_mex_assign(&c67_nc_y, sf_mex_create("y", &c67_oc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_b_y, c67_nc_y, "TorqueAmp", "TorqueAmp", 0);
  for (c67_i225 = 0; c67_i225 < 6; c67_i225++) {
    c67_pc_u[c67_i225] = c67_c_u.hdPosing[c67_i225];
  }

  c67_oc_y = NULL;
  sf_mex_assign(&c67_oc_y, sf_mex_create("y", c67_pc_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c67_b_y, c67_oc_y, "hdPosing", "hdPosing", 0);
  sf_mex_addfield(c67_y, c67_b_y, "Supervisory", "Supervisory", 0);
  c67_qc_u = c67_b_u.Discrete;
  c67_pc_y = NULL;
  sf_mex_assign(&c67_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c67_rc_u = c67_qc_u.TLastUpdate;
  c67_qc_y = NULL;
  sf_mex_assign(&c67_qc_y, sf_mex_create("y", &c67_rc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_pc_y, c67_qc_y, "TLastUpdate", "TLastUpdate", 0);
  c67_sc_u = c67_qc_u.VelocityControlLADelta;
  c67_rc_y = NULL;
  sf_mex_assign(&c67_rc_y, sf_mex_create("y", &c67_sc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_pc_y, c67_rc_y, "VelocityControlLADelta",
                  "VelocityControlLADelta", 0);
  c67_tc_u = c67_qc_u.VelocityControlTorsoDelta;
  c67_sc_y = NULL;
  sf_mex_assign(&c67_sc_y, sf_mex_create("y", &c67_tc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_pc_y, c67_sc_y, "VelocityControlTorsoDelta",
                  "VelocityControlTorsoDelta", 0);
  c67_uc_u = c67_qc_u.VelocityControlHipDistCur;
  c67_tc_y = NULL;
  sf_mex_assign(&c67_tc_y, sf_mex_create("y", &c67_uc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_pc_y, c67_tc_y, "VelocityControlHipDistCur",
                  "VelocityControlHipDistCur", 0);
  c67_vc_u = c67_qc_u.VelocityControlHipDistPrev;
  c67_uc_y = NULL;
  sf_mex_assign(&c67_uc_y, sf_mex_create("y", &c67_vc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_pc_y, c67_uc_y, "VelocityControlHipDistPrev",
                  "VelocityControlHipDistPrev", 0);
  c67_wc_u = c67_qc_u.VirtualSpringMode;
  c67_vc_y = NULL;
  sf_mex_assign(&c67_vc_y, sf_mex_create("y", &c67_wc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_pc_y, c67_vc_y, "VirtualSpringMode", "VirtualSpringMode",
                  0);
  c67_xc_u = c67_qc_u.VirtualSpringStiffness;
  c67_wc_y = NULL;
  sf_mex_assign(&c67_wc_y, sf_mex_create("y", &c67_xc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_pc_y, c67_wc_y, "VirtualSpringStiffness",
                  "VirtualSpringStiffness", 0);
  c67_yc_u = c67_qc_u.VirtualSpringDamping;
  c67_xc_y = NULL;
  sf_mex_assign(&c67_xc_y, sf_mex_create("y", &c67_yc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_pc_y, c67_xc_y, "VirtualSpringDamping",
                  "VirtualSpringDamping", 0);
  c67_ad_u = c67_qc_u.VirtualSpringModAmplitude;
  c67_yc_y = NULL;
  sf_mex_assign(&c67_yc_y, sf_mex_create("y", &c67_ad_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_pc_y, c67_yc_y, "VirtualSpringModAmplitude",
                  "VirtualSpringModAmplitude", 0);
  c67_bd_u = c67_qc_u.VirtualSpringModRate;
  c67_ad_y = NULL;
  sf_mex_assign(&c67_ad_y, sf_mex_create("y", &c67_bd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_pc_y, c67_ad_y, "VirtualSpringModRate",
                  "VirtualSpringModRate", 0);
  c67_cd_u = c67_qc_u.VirtualSpringRestPos;
  c67_bd_y = NULL;
  sf_mex_assign(&c67_bd_y, sf_mex_create("y", &c67_cd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_pc_y, c67_bd_y, "VirtualSpringRestPos",
                  "VirtualSpringRestPos", 0);
  sf_mex_addfield(c67_y, c67_pc_y, "Discrete", "Discrete", 0);
  c67_dd_u = c67_b_u.Output;
  c67_cd_y = NULL;
  sf_mex_assign(&c67_cd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c67_i226 = 0; c67_i226 < 78; c67_i226++) {
    c67_ed_u[c67_i226] = c67_dd_u.H0[c67_i226];
  }

  c67_dd_y = NULL;
  sf_mex_assign(&c67_dd_y, sf_mex_create("y", c67_ed_u, 0, 0U, 1U, 0U, 2, 6, 13),
                false);
  sf_mex_addfield(c67_cd_y, c67_dd_y, "H0", "H0", 0);
  for (c67_i227 = 0; c67_i227 < 36; c67_i227++) {
    c67_fd_u[c67_i227] = c67_dd_u.HAlpha[c67_i227];
  }

  c67_ed_y = NULL;
  sf_mex_assign(&c67_ed_y, sf_mex_create("y", c67_fd_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c67_cd_y, c67_ed_y, "HAlpha", "HAlpha", 0);
  for (c67_i228 = 0; c67_i228 < 2; c67_i228++) {
    c67_gd_u[c67_i228] = c67_dd_u.ThetaLimits[c67_i228];
  }

  c67_fd_y = NULL;
  sf_mex_assign(&c67_fd_y, sf_mex_create("y", c67_gd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c67_cd_y, c67_fd_y, "ThetaLimits", "ThetaLimits", 0);
  c67_hd_u = c67_dd_u.Theta;
  c67_gd_y = NULL;
  sf_mex_assign(&c67_gd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c67_id_u = c67_hd_u.c0;
  c67_hd_y = NULL;
  sf_mex_assign(&c67_hd_y, sf_mex_create("y", &c67_id_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_gd_y, c67_hd_y, "c0", "c0", 0);
  c67_jd_u = c67_hd_u.ct;
  c67_id_y = NULL;
  sf_mex_assign(&c67_id_y, sf_mex_create("y", &c67_jd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_gd_y, c67_id_y, "ct", "ct", 0);
  for (c67_i229 = 0; c67_i229 < 13; c67_i229++) {
    c67_kd_u[c67_i229] = c67_hd_u.cq[c67_i229];
  }

  c67_jd_y = NULL;
  sf_mex_assign(&c67_jd_y, sf_mex_create("y", c67_kd_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c67_gd_y, c67_jd_y, "cq", "cq", 0);
  c67_ld_u = c67_hd_u.t0;
  c67_kd_y = NULL;
  sf_mex_assign(&c67_kd_y, sf_mex_create("y", &c67_ld_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_gd_y, c67_kd_y, "t0", "t0", 0);
  for (c67_i230 = 0; c67_i230 < 7; c67_i230++) {
    c67_md_u[c67_i230] = c67_hd_u.cz[c67_i230];
  }

  c67_ld_y = NULL;
  sf_mex_assign(&c67_ld_y, sf_mex_create("y", c67_md_u, 0, 0U, 1U, 0U, 2, 1, 7),
                false);
  sf_mex_addfield(c67_gd_y, c67_ld_y, "cz", "cz", 0);
  sf_mex_addfield(c67_cd_y, c67_gd_y, "Theta", "Theta", 0);
  c67_nd_u = c67_dd_u.SaturateS;
  c67_md_y = NULL;
  sf_mex_assign(&c67_md_y, sf_mex_create("y", &c67_nd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_cd_y, c67_md_y, "SaturateS", "SaturateS", 0);
  for (c67_i231 = 0; c67_i231 < 2; c67_i231++) {
    c67_od_u[c67_i231] = c67_dd_u.SLimits[c67_i231];
  }

  c67_nd_y = NULL;
  sf_mex_assign(&c67_nd_y, sf_mex_create("y", c67_od_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c67_cd_y, c67_nd_y, "SLimits", "SLimits", 0);
  c67_pd_u = c67_dd_u.EnforceIncreasingS;
  c67_od_y = NULL;
  sf_mex_assign(&c67_od_y, sf_mex_create("y", &c67_pd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_cd_y, c67_od_y, "EnforceIncreasingS", "EnforceIncreasingS",
                  0);
  c67_qd_u = c67_dd_u.UseCorrection;
  c67_pd_y = NULL;
  sf_mex_assign(&c67_pd_y, sf_mex_create("y", &c67_qd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_cd_y, c67_pd_y, "UseCorrection", "UseCorrection", 0);
  c67_rd_u = c67_dd_u.SMaxCorrection;
  c67_qd_y = NULL;
  sf_mex_assign(&c67_qd_y, sf_mex_create("y", &c67_rd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_cd_y, c67_qd_y, "SMaxCorrection", "SMaxCorrection", 0);
  for (c67_i232 = 0; c67_i232 < 30; c67_i232++) {
    c67_sd_u[c67_i232] = c67_dd_u.HAlphaCorrection[c67_i232];
  }

  c67_rd_y = NULL;
  sf_mex_assign(&c67_rd_y, sf_mex_create("y", c67_sd_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c67_cd_y, c67_rd_y, "HAlphaCorrection", "HAlphaCorrection", 0);
  c67_td_u = c67_dd_u.Phi;
  c67_sd_y = NULL;
  sf_mex_assign(&c67_sd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c67_ud_u = c67_td_u.c0;
  c67_td_y = NULL;
  sf_mex_assign(&c67_td_y, sf_mex_create("y", &c67_ud_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_sd_y, c67_td_y, "c0", "c0", 0);
  for (c67_i233 = 0; c67_i233 < 13; c67_i233++) {
    c67_vd_u[c67_i233] = c67_td_u.cq[c67_i233];
  }

  c67_ud_y = NULL;
  sf_mex_assign(&c67_ud_y, sf_mex_create("y", c67_vd_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c67_sd_y, c67_ud_y, "cq", "cq", 0);
  sf_mex_addfield(c67_cd_y, c67_sd_y, "Phi", "Phi", 0);
  for (c67_i234 = 0; c67_i234 < 20; c67_i234++) {
    c67_wd_u[c67_i234] = c67_dd_u.PhiAlpha[c67_i234];
  }

  c67_vd_y = NULL;
  sf_mex_assign(&c67_vd_y, sf_mex_create("y", c67_wd_u, 0, 0U, 1U, 0U, 2, 1, 20),
                false);
  sf_mex_addfield(c67_cd_y, c67_vd_y, "PhiAlpha", "PhiAlpha", 0);
  c67_xd_u = c67_dd_u.SaturateR;
  c67_wd_y = NULL;
  sf_mex_assign(&c67_wd_y, sf_mex_create("y", &c67_xd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_cd_y, c67_wd_y, "SaturateR", "SaturateR", 0);
  for (c67_i235 = 0; c67_i235 < 2; c67_i235++) {
    c67_yd_u[c67_i235] = c67_dd_u.RLimits[c67_i235];
  }

  c67_xd_y = NULL;
  sf_mex_assign(&c67_xd_y, sf_mex_create("y", c67_yd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c67_cd_y, c67_xd_y, "RLimits", "RLimits", 0);
  for (c67_i236 = 0; c67_i236 < 30; c67_i236++) {
    c67_ae_u[c67_i236] = c67_dd_u.HBarAlpha[c67_i236];
  }

  c67_yd_y = NULL;
  sf_mex_assign(&c67_yd_y, sf_mex_create("y", c67_ae_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c67_cd_y, c67_yd_y, "HBarAlpha", "HBarAlpha", 0);
  for (c67_i237 = 0; c67_i237 < 12; c67_i237++) {
    c67_be_u[c67_i237] = c67_dd_u.HBarLimits[c67_i237];
  }

  c67_ae_y = NULL;
  sf_mex_assign(&c67_ae_y, sf_mex_create("y", c67_be_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c67_cd_y, c67_ae_y, "HBarLimits", "HBarLimits", 0);
  for (c67_i238 = 0; c67_i238 < 36; c67_i238++) {
    c67_ce_u[c67_i238] = c67_dd_u.HAlphaStar[c67_i238];
  }

  c67_be_y = NULL;
  sf_mex_assign(&c67_be_y, sf_mex_create("y", c67_ce_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c67_cd_y, c67_be_y, "HAlphaStar", "HAlphaStar", 0);
  c67_de_u = c67_dd_u.YawLimit;
  c67_ce_y = NULL;
  sf_mex_assign(&c67_ce_y, sf_mex_create("y", &c67_de_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_cd_y, c67_ce_y, "YawLimit", "YawLimit", 0);
  c67_ee_u = c67_dd_u.test;
  c67_de_y = NULL;
  sf_mex_assign(&c67_de_y, sf_mex_create("y", &c67_ee_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_cd_y, c67_de_y, "test", "test", 0);
  sf_mex_addfield(c67_y, c67_cd_y, "Output", "Output", 0);
  c67_fe_u = c67_b_u.Feedback;
  c67_ee_y = NULL;
  sf_mex_assign(&c67_ee_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c67_i239 = 0; c67_i239 < 6; c67_i239++) {
    c67_ge_u[c67_i239] = c67_fe_u.kp[c67_i239];
  }

  c67_fe_y = NULL;
  sf_mex_assign(&c67_fe_y, sf_mex_create("y", c67_ge_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c67_ee_y, c67_fe_y, "kp", "kp", 0);
  for (c67_i240 = 0; c67_i240 < 6; c67_i240++) {
    c67_he_u[c67_i240] = c67_fe_u.kd[c67_i240];
  }

  c67_ge_y = NULL;
  sf_mex_assign(&c67_ge_y, sf_mex_create("y", c67_he_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c67_ee_y, c67_ge_y, "kd", "kd", 0);
  for (c67_i241 = 0; c67_i241 < 2; c67_i241++) {
    c67_ie_u[c67_i241] = c67_fe_u.epsilon[c67_i241];
  }

  c67_he_y = NULL;
  sf_mex_assign(&c67_he_y, sf_mex_create("y", c67_ie_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c67_ee_y, c67_he_y, "epsilon", "epsilon", 0);
  for (c67_i242 = 0; c67_i242 < 2; c67_i242++) {
    c67_je_u[c67_i242] = c67_fe_u.kff_grav[c67_i242];
  }

  c67_ie_y = NULL;
  sf_mex_assign(&c67_ie_y, sf_mex_create("y", c67_je_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c67_ee_y, c67_ie_y, "kff_grav", "kff_grav", 0);
  c67_ke_u = c67_fe_u.delta_grav;
  c67_je_y = NULL;
  sf_mex_assign(&c67_je_y, sf_mex_create("y", &c67_ke_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_je_y, "delta_grav", "delta_grav", 0);
  for (c67_i243 = 0; c67_i243 < 2; c67_i243++) {
    c67_le_u[c67_i243] = c67_fe_u.kff_decoup[c67_i243];
  }

  c67_ke_y = NULL;
  sf_mex_assign(&c67_ke_y, sf_mex_create("y", c67_le_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c67_ee_y, c67_ke_y, "kff_decoup", "kff_decoup", 0);
  for (c67_i244 = 0; c67_i244 < 2; c67_i244++) {
    c67_me_u[c67_i244] = c67_fe_u.kd_torso[c67_i244];
  }

  c67_le_y = NULL;
  sf_mex_assign(&c67_le_y, sf_mex_create("y", c67_me_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c67_ee_y, c67_le_y, "kd_torso", "kd_torso", 0);
  c67_ne_u = c67_fe_u.kp_2dof;
  c67_me_y = NULL;
  sf_mex_assign(&c67_me_y, sf_mex_create("y", &c67_ne_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_me_y, "kp_2dof", "kp_2dof", 0);
  c67_oe_u = c67_fe_u.kd_2dof;
  c67_ne_y = NULL;
  sf_mex_assign(&c67_ne_y, sf_mex_create("y", &c67_oe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_ne_y, "kd_2dof", "kd_2dof", 0);
  c67_pe_u = c67_fe_u.kpre_2dof;
  c67_oe_y = NULL;
  sf_mex_assign(&c67_oe_y, sf_mex_create("y", &c67_pe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_oe_y, "kpre_2dof", "kpre_2dof", 0);
  c67_qe_u = c67_fe_u.kp_lat;
  c67_pe_y = NULL;
  sf_mex_assign(&c67_pe_y, sf_mex_create("y", &c67_qe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_pe_y, "kp_lat", "kp_lat", 0);
  c67_re_u = c67_fe_u.kd_lat;
  c67_qe_y = NULL;
  sf_mex_assign(&c67_qe_y, sf_mex_create("y", &c67_re_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_qe_y, "kd_lat", "kd_lat", 0);
  c67_se_u = c67_fe_u.q3d_min_lat;
  c67_re_y = NULL;
  sf_mex_assign(&c67_re_y, sf_mex_create("y", &c67_se_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_re_y, "q3d_min_lat", "q3d_min_lat", 0);
  c67_te_u = c67_fe_u.q3d_max_lat;
  c67_se_y = NULL;
  sf_mex_assign(&c67_se_y, sf_mex_create("y", &c67_te_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_se_y, "q3d_max_lat", "q3d_max_lat", 0);
  c67_ue_u = c67_fe_u.w_torso_lat;
  c67_te_y = NULL;
  sf_mex_assign(&c67_te_y, sf_mex_create("y", &c67_ue_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_te_y, "w_torso_lat", "w_torso_lat", 0);
  for (c67_i245 = 0; c67_i245 < 6; c67_i245++) {
    c67_ve_u[c67_i245] = c67_fe_u.u_ff[c67_i245];
  }

  c67_ue_y = NULL;
  sf_mex_assign(&c67_ue_y, sf_mex_create("y", c67_ve_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c67_ee_y, c67_ue_y, "u_ff", "u_ff", 0);
  c67_we_u = c67_fe_u.LateralControlMode;
  c67_ve_y = NULL;
  sf_mex_assign(&c67_ve_y, sf_mex_create("y", &c67_we_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_ve_y, "LateralControlMode", "LateralControlMode",
                  0);
  c67_xe_u = c67_fe_u.DecouplingMode;
  c67_we_y = NULL;
  sf_mex_assign(&c67_we_y, sf_mex_create("y", &c67_xe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_we_y, "DecouplingMode", "DecouplingMode", 0);
  c67_ye_u = c67_fe_u.Use2DOF;
  c67_xe_y = NULL;
  sf_mex_assign(&c67_xe_y, sf_mex_create("y", &c67_ye_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_xe_y, "Use2DOF", "Use2DOF", 0);
  c67_af_u = c67_fe_u.UseDSGravComp;
  c67_ye_y = NULL;
  sf_mex_assign(&c67_ye_y, sf_mex_create("y", &c67_af_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_ye_y, "UseDSGravComp", "UseDSGravComp", 0);
  c67_bf_u = c67_fe_u.lat_bias;
  c67_af_y = NULL;
  sf_mex_assign(&c67_af_y, sf_mex_create("y", &c67_bf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_af_y, "lat_bias", "lat_bias", 0);
  c67_cf_u = c67_fe_u.lat_bias2;
  c67_bf_y = NULL;
  sf_mex_assign(&c67_bf_y, sf_mex_create("y", &c67_cf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_bf_y, "lat_bias2", "lat_bias2", 0);
  c67_df_u = c67_fe_u.linkFeedback;
  c67_cf_y = NULL;
  sf_mex_assign(&c67_cf_y, sf_mex_create("y", &c67_df_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_cf_y, "linkFeedback", "linkFeedback", 0);
  c67_ef_u = c67_fe_u.RIO;
  c67_df_y = NULL;
  sf_mex_assign(&c67_df_y, sf_mex_create("y", &c67_ef_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_df_y, "RIO", "RIO", 0);
  c67_ff_u = c67_fe_u.SelectFeedforward;
  c67_ef_y = NULL;
  sf_mex_assign(&c67_ef_y, sf_mex_create("y", &c67_ff_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_ef_y, "SelectFeedforward", "SelectFeedforward",
                  0);
  for (c67_i246 = 0; c67_i246 < 6; c67_i246++) {
    c67_gf_u[c67_i246] = c67_fe_u.FeedforwardGain[c67_i246];
  }

  c67_ff_y = NULL;
  sf_mex_assign(&c67_ff_y, sf_mex_create("y", c67_gf_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c67_ee_y, c67_ff_y, "FeedforwardGain", "FeedforwardGain", 0);
  c67_hf_u = c67_fe_u.EnableFeedforwardOnStep;
  c67_gf_y = NULL;
  sf_mex_assign(&c67_gf_y, sf_mex_create("y", &c67_hf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_ee_y, c67_gf_y, "EnableFeedforwardOnStep",
                  "EnableFeedforwardOnStep", 0);
  sf_mex_addfield(c67_y, c67_ee_y, "Feedback", "Feedback", 0);
  c67_if_u = c67_b_u.Saturation;
  c67_hf_y = NULL;
  sf_mex_assign(&c67_hf_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c67_jf_u = c67_if_u.UseQPSaturation;
  c67_if_y = NULL;
  sf_mex_assign(&c67_if_y, sf_mex_create("y", &c67_jf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_hf_y, c67_if_y, "UseQPSaturation", "UseQPSaturation", 0);
  for (c67_i247 = 0; c67_i247 < 2; c67_i247++) {
    c67_kf_u[c67_i247] = c67_if_u.QPWeight[c67_i247];
  }

  c67_jf_y = NULL;
  sf_mex_assign(&c67_jf_y, sf_mex_create("y", c67_kf_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c67_hf_y, c67_jf_y, "QPWeight", "QPWeight", 0);
  c67_lf_u = c67_if_u.UseKASaturation;
  c67_kf_y = NULL;
  sf_mex_assign(&c67_kf_y, sf_mex_create("y", &c67_lf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_hf_y, c67_kf_y, "UseKASaturation", "UseKASaturation", 0);
  c67_mf_u = c67_if_u.KASaturationS1;
  c67_lf_y = NULL;
  sf_mex_assign(&c67_lf_y, sf_mex_create("y", &c67_mf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_hf_y, c67_lf_y, "KASaturationS1", "KASaturationS1", 0);
  c67_nf_u = c67_if_u.KASaturationS2;
  c67_mf_y = NULL;
  sf_mex_assign(&c67_mf_y, sf_mex_create("y", &c67_nf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_hf_y, c67_mf_y, "KASaturationS2", "KASaturationS2", 0);
  c67_of_u = c67_if_u.KASaturationEarly;
  c67_nf_y = NULL;
  sf_mex_assign(&c67_nf_y, sf_mex_create("y", &c67_of_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_hf_y, c67_nf_y, "KASaturationEarly", "KASaturationEarly",
                  0);
  c67_pf_u = c67_if_u.KASaturationMax;
  c67_of_y = NULL;
  sf_mex_assign(&c67_of_y, sf_mex_create("y", &c67_pf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c67_hf_y, c67_of_y, "KASaturationMax", "KASaturationMax", 0);
  sf_mex_addfield(c67_y, c67_hf_y, "Saturation", "Saturation", 0);
  sf_mex_assign(&c67_mxArrayOutData, c67_y, false);
  return c67_mxArrayOutData;
}

static const mxArray *c67_c_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData)
{
  const mxArray *c67_mxArrayOutData = NULL;
  c67_ControlStateBus c67_b_u;
  const mxArray *c67_y = NULL;
  real_T c67_c_u;
  const mxArray *c67_b_y = NULL;
  real_T c67_d_u;
  const mxArray *c67_c_y = NULL;
  real_T c67_e_u;
  const mxArray *c67_d_y = NULL;
  real_T c67_f_u;
  const mxArray *c67_e_y = NULL;
  real_T c67_g_u;
  const mxArray *c67_f_y = NULL;
  real_T c67_h_u;
  const mxArray *c67_g_y = NULL;
  real_T c67_i_u;
  const mxArray *c67_h_y = NULL;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_mxArrayOutData = NULL;
  c67_b_u = *(c67_ControlStateBus *)c67_inData;
  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c67_c_u = c67_b_u.ControllerMode;
  c67_b_y = NULL;
  sf_mex_assign(&c67_b_y, sf_mex_create("y", &c67_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_y, c67_b_y, "ControllerMode", "ControllerMode", 0);
  c67_d_u = c67_b_u.SupportState;
  c67_c_y = NULL;
  sf_mex_assign(&c67_c_y, sf_mex_create("y", &c67_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_y, c67_c_y, "SupportState", "SupportState", 0);
  c67_e_u = c67_b_u.StanceLeg;
  c67_d_y = NULL;
  sf_mex_assign(&c67_d_y, sf_mex_create("y", &c67_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_y, c67_d_y, "StanceLeg", "StanceLeg", 0);
  c67_f_u = c67_b_u.InDoubleSupport;
  c67_e_y = NULL;
  sf_mex_assign(&c67_e_y, sf_mex_create("y", &c67_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_y, c67_e_y, "InDoubleSupport", "InDoubleSupport", 0);
  c67_g_u = c67_b_u.RollPhase;
  c67_f_y = NULL;
  sf_mex_assign(&c67_f_y, sf_mex_create("y", &c67_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_y, c67_f_y, "RollPhase", "RollPhase", 0);
  c67_h_u = c67_b_u.StepCount;
  c67_g_y = NULL;
  sf_mex_assign(&c67_g_y, sf_mex_create("y", &c67_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_y, c67_g_y, "StepCount", "StepCount", 0);
  c67_i_u = c67_b_u.Error;
  c67_h_y = NULL;
  sf_mex_assign(&c67_h_y, sf_mex_create("y", &c67_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c67_y, c67_h_y, "Error", "Error", 0);
  sf_mex_assign(&c67_mxArrayOutData, c67_y, false);
  return c67_mxArrayOutData;
}

static const mxArray *c67_d_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData)
{
  const mxArray *c67_mxArrayOutData = NULL;
  int32_T c67_i248;
  real_T c67_b_inData[2];
  int32_T c67_i249;
  real_T c67_b_u[2];
  const mxArray *c67_y = NULL;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_mxArrayOutData = NULL;
  for (c67_i248 = 0; c67_i248 < 2; c67_i248++) {
    c67_b_inData[c67_i248] = (*(real_T (*)[2])c67_inData)[c67_i248];
  }

  for (c67_i249 = 0; c67_i249 < 2; c67_i249++) {
    c67_b_u[c67_i249] = c67_b_inData[c67_i249];
  }

  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", c67_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c67_mxArrayOutData, c67_y, false);
  return c67_mxArrayOutData;
}

static const mxArray *c67_e_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData)
{
  const mxArray *c67_mxArrayOutData = NULL;
  real_T c67_b_u;
  const mxArray *c67_y = NULL;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_mxArrayOutData = NULL;
  c67_b_u = *(real_T *)c67_inData;
  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", &c67_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c67_mxArrayOutData, c67_y, false);
  return c67_mxArrayOutData;
}

static real_T c67_c_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId)
{
  real_T c67_y;
  real_T c67_d27;
  (void)chartInstance;
  sf_mex_import(c67_parentId, sf_mex_dup(c67_b_u), &c67_d27, 1, 0, 0U, 0, 0U, 0);
  c67_y = c67_d27;
  sf_mex_destroy(&c67_b_u);
  return c67_y;
}

static void c67_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData)
{
  const mxArray *c67_nargout;
  const char_T *c67_identifier;
  emlrtMsgIdentifier c67_thisId;
  real_T c67_y;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_nargout = sf_mex_dup(c67_mxArrayInData);
  c67_identifier = c67_varName;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_y = c67_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c67_nargout),
    &c67_thisId);
  sf_mex_destroy(&c67_nargout);
  *(real_T *)c67_outData = c67_y;
  sf_mex_destroy(&c67_mxArrayInData);
}

static const mxArray *c67_f_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData)
{
  const mxArray *c67_mxArrayOutData = NULL;
  int32_T c67_i250;
  int32_T c67_i251;
  int32_T c67_i252;
  real_T c67_b_inData[36];
  int32_T c67_i253;
  int32_T c67_i254;
  int32_T c67_i255;
  real_T c67_b_u[36];
  const mxArray *c67_y = NULL;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_mxArrayOutData = NULL;
  c67_i250 = 0;
  for (c67_i251 = 0; c67_i251 < 6; c67_i251++) {
    for (c67_i252 = 0; c67_i252 < 6; c67_i252++) {
      c67_b_inData[c67_i252 + c67_i250] = (*(real_T (*)[36])c67_inData)[c67_i252
        + c67_i250];
    }

    c67_i250 += 6;
  }

  c67_i253 = 0;
  for (c67_i254 = 0; c67_i254 < 6; c67_i254++) {
    for (c67_i255 = 0; c67_i255 < 6; c67_i255++) {
      c67_b_u[c67_i255 + c67_i253] = c67_b_inData[c67_i255 + c67_i253];
    }

    c67_i253 += 6;
  }

  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", c67_b_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_assign(&c67_mxArrayOutData, c67_y, false);
  return c67_mxArrayOutData;
}

static void c67_d_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[36])
{
  real_T c67_dv5[36];
  int32_T c67_i256;
  (void)chartInstance;
  sf_mex_import(c67_parentId, sf_mex_dup(c67_b_u), c67_dv5, 1, 0, 0U, 1, 0U, 2,
                6, 6);
  for (c67_i256 = 0; c67_i256 < 36; c67_i256++) {
    c67_y[c67_i256] = c67_dv5[c67_i256];
  }

  sf_mex_destroy(&c67_b_u);
}

static void c67_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData)
{
  const mxArray *c67_T0;
  const char_T *c67_identifier;
  emlrtMsgIdentifier c67_thisId;
  real_T c67_y[36];
  int32_T c67_i257;
  int32_T c67_i258;
  int32_T c67_i259;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_T0 = sf_mex_dup(c67_mxArrayInData);
  c67_identifier = c67_varName;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c67_T0), &c67_thisId, c67_y);
  sf_mex_destroy(&c67_T0);
  c67_i257 = 0;
  for (c67_i258 = 0; c67_i258 < 6; c67_i258++) {
    for (c67_i259 = 0; c67_i259 < 6; c67_i259++) {
      (*(real_T (*)[36])c67_outData)[c67_i259 + c67_i257] = c67_y[c67_i259 +
        c67_i257];
    }

    c67_i257 += 6;
  }

  sf_mex_destroy(&c67_mxArrayInData);
}

static void c67_e_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[2])
{
  real_T c67_dv6[2];
  int32_T c67_i260;
  (void)chartInstance;
  sf_mex_import(c67_parentId, sf_mex_dup(c67_b_u), c67_dv6, 1, 0, 0U, 1, 0U, 1,
                2);
  for (c67_i260 = 0; c67_i260 < 2; c67_i260++) {
    c67_y[c67_i260] = c67_dv6[c67_i260];
  }

  sf_mex_destroy(&c67_b_u);
}

static void c67_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData)
{
  const mxArray *c67_uL;
  const char_T *c67_identifier;
  emlrtMsgIdentifier c67_thisId;
  real_T c67_y[2];
  int32_T c67_i261;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_uL = sf_mex_dup(c67_mxArrayInData);
  c67_identifier = c67_varName;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c67_uL), &c67_thisId, c67_y);
  sf_mex_destroy(&c67_uL);
  for (c67_i261 = 0; c67_i261 < 2; c67_i261++) {
    (*(real_T (*)[2])c67_outData)[c67_i261] = c67_y[c67_i261];
  }

  sf_mex_destroy(&c67_mxArrayInData);
}

static const mxArray *c67_g_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData)
{
  const mxArray *c67_mxArrayOutData = NULL;
  int32_T c67_i262;
  real_T c67_b_inData[4];
  int32_T c67_i263;
  real_T c67_b_u[4];
  const mxArray *c67_y = NULL;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_mxArrayOutData = NULL;
  for (c67_i262 = 0; c67_i262 < 4; c67_i262++) {
    c67_b_inData[c67_i262] = (*(real_T (*)[4])c67_inData)[c67_i262];
  }

  for (c67_i263 = 0; c67_i263 < 4; c67_i263++) {
    c67_b_u[c67_i263] = c67_b_inData[c67_i263];
  }

  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", c67_b_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c67_mxArrayOutData, c67_y, false);
  return c67_mxArrayOutData;
}

static void c67_f_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId,
  real_T c67_y[4])
{
  real_T c67_dv7[4];
  int32_T c67_i264;
  (void)chartInstance;
  sf_mex_import(c67_parentId, sf_mex_dup(c67_b_u), c67_dv7, 1, 0, 0U, 1, 0U, 1,
                4);
  for (c67_i264 = 0; c67_i264 < 4; c67_i264++) {
    c67_y[c67_i264] = c67_dv7[c67_i264];
  }

  sf_mex_destroy(&c67_b_u);
}

static void c67_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData)
{
  const mxArray *c67_L_opt;
  const char_T *c67_identifier;
  emlrtMsgIdentifier c67_thisId;
  real_T c67_y[4];
  int32_T c67_i265;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_L_opt = sf_mex_dup(c67_mxArrayInData);
  c67_identifier = c67_varName;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c67_L_opt), &c67_thisId,
    c67_y);
  sf_mex_destroy(&c67_L_opt);
  for (c67_i265 = 0; c67_i265 < 4; c67_i265++) {
    (*(real_T (*)[4])c67_outData)[c67_i265] = c67_y[c67_i265];
  }

  sf_mex_destroy(&c67_mxArrayInData);
}

const mxArray *sf_c67_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void)
{
  const mxArray *c67_nameCaptureInfo = NULL;
  c67_nameCaptureInfo = NULL;
  sf_mex_assign(&c67_nameCaptureInfo, sf_mex_createstruct("structure", 2, 190, 1),
                false);
  c67_info_helper(&c67_nameCaptureInfo);
  c67_b_info_helper(&c67_nameCaptureInfo);
  c67_c_info_helper(&c67_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c67_nameCaptureInfo);
  return c67_nameCaptureInfo;
}

static void c67_info_helper(const mxArray **c67_info)
{
  const mxArray *c67_rhs0 = NULL;
  const mxArray *c67_lhs0 = NULL;
  const mxArray *c67_rhs1 = NULL;
  const mxArray *c67_lhs1 = NULL;
  const mxArray *c67_rhs2 = NULL;
  const mxArray *c67_lhs2 = NULL;
  const mxArray *c67_rhs3 = NULL;
  const mxArray *c67_lhs3 = NULL;
  const mxArray *c67_rhs4 = NULL;
  const mxArray *c67_lhs4 = NULL;
  const mxArray *c67_rhs5 = NULL;
  const mxArray *c67_lhs5 = NULL;
  const mxArray *c67_rhs6 = NULL;
  const mxArray *c67_lhs6 = NULL;
  const mxArray *c67_rhs7 = NULL;
  const mxArray *c67_lhs7 = NULL;
  const mxArray *c67_rhs8 = NULL;
  const mxArray *c67_lhs8 = NULL;
  const mxArray *c67_rhs9 = NULL;
  const mxArray *c67_lhs9 = NULL;
  const mxArray *c67_rhs10 = NULL;
  const mxArray *c67_lhs10 = NULL;
  const mxArray *c67_rhs11 = NULL;
  const mxArray *c67_lhs11 = NULL;
  const mxArray *c67_rhs12 = NULL;
  const mxArray *c67_lhs12 = NULL;
  const mxArray *c67_rhs13 = NULL;
  const mxArray *c67_lhs13 = NULL;
  const mxArray *c67_rhs14 = NULL;
  const mxArray *c67_lhs14 = NULL;
  const mxArray *c67_rhs15 = NULL;
  const mxArray *c67_lhs15 = NULL;
  const mxArray *c67_rhs16 = NULL;
  const mxArray *c67_lhs16 = NULL;
  const mxArray *c67_rhs17 = NULL;
  const mxArray *c67_lhs17 = NULL;
  const mxArray *c67_rhs18 = NULL;
  const mxArray *c67_lhs18 = NULL;
  const mxArray *c67_rhs19 = NULL;
  const mxArray *c67_lhs19 = NULL;
  const mxArray *c67_rhs20 = NULL;
  const mxArray *c67_lhs20 = NULL;
  const mxArray *c67_rhs21 = NULL;
  const mxArray *c67_lhs21 = NULL;
  const mxArray *c67_rhs22 = NULL;
  const mxArray *c67_lhs22 = NULL;
  const mxArray *c67_rhs23 = NULL;
  const mxArray *c67_lhs23 = NULL;
  const mxArray *c67_rhs24 = NULL;
  const mxArray *c67_lhs24 = NULL;
  const mxArray *c67_rhs25 = NULL;
  const mxArray *c67_lhs25 = NULL;
  const mxArray *c67_rhs26 = NULL;
  const mxArray *c67_lhs26 = NULL;
  const mxArray *c67_rhs27 = NULL;
  const mxArray *c67_lhs27 = NULL;
  const mxArray *c67_rhs28 = NULL;
  const mxArray *c67_lhs28 = NULL;
  const mxArray *c67_rhs29 = NULL;
  const mxArray *c67_lhs29 = NULL;
  const mxArray *c67_rhs30 = NULL;
  const mxArray *c67_lhs30 = NULL;
  const mxArray *c67_rhs31 = NULL;
  const mxArray *c67_lhs31 = NULL;
  const mxArray *c67_rhs32 = NULL;
  const mxArray *c67_lhs32 = NULL;
  const mxArray *c67_rhs33 = NULL;
  const mxArray *c67_lhs33 = NULL;
  const mxArray *c67_rhs34 = NULL;
  const mxArray *c67_lhs34 = NULL;
  const mxArray *c67_rhs35 = NULL;
  const mxArray *c67_lhs35 = NULL;
  const mxArray *c67_rhs36 = NULL;
  const mxArray *c67_lhs36 = NULL;
  const mxArray *c67_rhs37 = NULL;
  const mxArray *c67_lhs37 = NULL;
  const mxArray *c67_rhs38 = NULL;
  const mxArray *c67_lhs38 = NULL;
  const mxArray *c67_rhs39 = NULL;
  const mxArray *c67_lhs39 = NULL;
  const mxArray *c67_rhs40 = NULL;
  const mxArray *c67_lhs40 = NULL;
  const mxArray *c67_rhs41 = NULL;
  const mxArray *c67_lhs41 = NULL;
  const mxArray *c67_rhs42 = NULL;
  const mxArray *c67_lhs42 = NULL;
  const mxArray *c67_rhs43 = NULL;
  const mxArray *c67_lhs43 = NULL;
  const mxArray *c67_rhs44 = NULL;
  const mxArray *c67_lhs44 = NULL;
  const mxArray *c67_rhs45 = NULL;
  const mxArray *c67_lhs45 = NULL;
  const mxArray *c67_rhs46 = NULL;
  const mxArray *c67_lhs46 = NULL;
  const mxArray *c67_rhs47 = NULL;
  const mxArray *c67_lhs47 = NULL;
  const mxArray *c67_rhs48 = NULL;
  const mxArray *c67_lhs48 = NULL;
  const mxArray *c67_rhs49 = NULL;
  const mxArray *c67_lhs49 = NULL;
  const mxArray *c67_rhs50 = NULL;
  const mxArray *c67_lhs50 = NULL;
  const mxArray *c67_rhs51 = NULL;
  const mxArray *c67_lhs51 = NULL;
  const mxArray *c67_rhs52 = NULL;
  const mxArray *c67_lhs52 = NULL;
  const mxArray *c67_rhs53 = NULL;
  const mxArray *c67_lhs53 = NULL;
  const mxArray *c67_rhs54 = NULL;
  const mxArray *c67_lhs54 = NULL;
  const mxArray *c67_rhs55 = NULL;
  const mxArray *c67_lhs55 = NULL;
  const mxArray *c67_rhs56 = NULL;
  const mxArray *c67_lhs56 = NULL;
  const mxArray *c67_rhs57 = NULL;
  const mxArray *c67_lhs57 = NULL;
  const mxArray *c67_rhs58 = NULL;
  const mxArray *c67_lhs58 = NULL;
  const mxArray *c67_rhs59 = NULL;
  const mxArray *c67_lhs59 = NULL;
  const mxArray *c67_rhs60 = NULL;
  const mxArray *c67_lhs60 = NULL;
  const mxArray *c67_rhs61 = NULL;
  const mxArray *c67_lhs61 = NULL;
  const mxArray *c67_rhs62 = NULL;
  const mxArray *c67_lhs62 = NULL;
  const mxArray *c67_rhs63 = NULL;
  const mxArray *c67_lhs63 = NULL;
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c67_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c67_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c67_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c67_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c67_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  5);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c67_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 6);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c67_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 7);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c67_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 8);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 8);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c67_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 9);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 9);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c67_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 10);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 10);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c67_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c67_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 12);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c67_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("mrdivide"), "name", "name",
                  13);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c67_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 14);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 14);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c67_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 15);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("rdivide"), "name", "name",
                  15);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c67_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c67_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 17);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c67_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_div"), "name", "name",
                  18);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c67_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 19);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c67_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "context", "context", 20);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("LA_LS_Revised_Saturation"),
                  "name", "name", 20);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1444270528U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c67_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_1"), "name", "name", 21);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_1.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1444270528U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c67_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_1.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("mrdivide"), "name", "name",
                  22);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c67_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_2"), "name", "name", 23);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_2.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1444270528U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c67_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_2.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("mrdivide"), "name", "name",
                  24);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c67_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_3"), "name", "name", 25);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_3.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1444270528U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c67_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_3.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("mrdivide"), "name", "name",
                  26);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c67_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 27);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_4"), "name", "name", 27);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_4.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1444270528U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c67_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_4.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("mrdivide"), "name", "name",
                  28);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c67_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_5"), "name", "name", 29);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_5.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1444270528U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c67_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_5.m"),
                  "context", "context", 30);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("mrdivide"), "name", "name",
                  30);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c67_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_6"), "name", "name", 31);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_6.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1444270528U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c67_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_6.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("mrdivide"), "name", "name",
                  32);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c67_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_7"), "name", "name", 33);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_7.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1444270528U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c67_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_7.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("mrdivide"), "name", "name",
                  34);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c67_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 35);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_8"), "name", "name", 35);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_8.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1444270528U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c67_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_8.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("mrdivide"), "name", "name",
                  36);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c67_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_9"), "name", "name", 37);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_9.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1444270528U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c67_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_9.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("mrdivide"), "name", "name",
                  38);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c67_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("max"), "name", "name", 39);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c67_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 40);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c67_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 41);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 41);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c67_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 42);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c67_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 43);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 43);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c67_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 44);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 44);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c67_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 45);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 45);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c67_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 46);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("isnan"), "name", "name", 46);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c67_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 47);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c67_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 48);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 48);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 48);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c67_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 49);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 49);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c67_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 50);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 50);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c67_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 51);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("isfi"), "name", "name", 51);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 51);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c67_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 52);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c67_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 53);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("intmax"), "name", "name", 53);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c67_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 54);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c67_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 55);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("intmin"), "name", "name", 55);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c67_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 56);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c67_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 57);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_relop"), "name", "name",
                  57);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 57);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1342472782U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c67_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 58);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("min"), "name", "name", 58);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c67_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 59);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c67_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "context", "context", 60);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("min"), "name", "name", 60);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 60);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c67_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 61);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 61);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 61);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c67_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 62);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 62);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c67_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 63);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 63);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c67_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c67_rhs0);
  sf_mex_destroy(&c67_lhs0);
  sf_mex_destroy(&c67_rhs1);
  sf_mex_destroy(&c67_lhs1);
  sf_mex_destroy(&c67_rhs2);
  sf_mex_destroy(&c67_lhs2);
  sf_mex_destroy(&c67_rhs3);
  sf_mex_destroy(&c67_lhs3);
  sf_mex_destroy(&c67_rhs4);
  sf_mex_destroy(&c67_lhs4);
  sf_mex_destroy(&c67_rhs5);
  sf_mex_destroy(&c67_lhs5);
  sf_mex_destroy(&c67_rhs6);
  sf_mex_destroy(&c67_lhs6);
  sf_mex_destroy(&c67_rhs7);
  sf_mex_destroy(&c67_lhs7);
  sf_mex_destroy(&c67_rhs8);
  sf_mex_destroy(&c67_lhs8);
  sf_mex_destroy(&c67_rhs9);
  sf_mex_destroy(&c67_lhs9);
  sf_mex_destroy(&c67_rhs10);
  sf_mex_destroy(&c67_lhs10);
  sf_mex_destroy(&c67_rhs11);
  sf_mex_destroy(&c67_lhs11);
  sf_mex_destroy(&c67_rhs12);
  sf_mex_destroy(&c67_lhs12);
  sf_mex_destroy(&c67_rhs13);
  sf_mex_destroy(&c67_lhs13);
  sf_mex_destroy(&c67_rhs14);
  sf_mex_destroy(&c67_lhs14);
  sf_mex_destroy(&c67_rhs15);
  sf_mex_destroy(&c67_lhs15);
  sf_mex_destroy(&c67_rhs16);
  sf_mex_destroy(&c67_lhs16);
  sf_mex_destroy(&c67_rhs17);
  sf_mex_destroy(&c67_lhs17);
  sf_mex_destroy(&c67_rhs18);
  sf_mex_destroy(&c67_lhs18);
  sf_mex_destroy(&c67_rhs19);
  sf_mex_destroy(&c67_lhs19);
  sf_mex_destroy(&c67_rhs20);
  sf_mex_destroy(&c67_lhs20);
  sf_mex_destroy(&c67_rhs21);
  sf_mex_destroy(&c67_lhs21);
  sf_mex_destroy(&c67_rhs22);
  sf_mex_destroy(&c67_lhs22);
  sf_mex_destroy(&c67_rhs23);
  sf_mex_destroy(&c67_lhs23);
  sf_mex_destroy(&c67_rhs24);
  sf_mex_destroy(&c67_lhs24);
  sf_mex_destroy(&c67_rhs25);
  sf_mex_destroy(&c67_lhs25);
  sf_mex_destroy(&c67_rhs26);
  sf_mex_destroy(&c67_lhs26);
  sf_mex_destroy(&c67_rhs27);
  sf_mex_destroy(&c67_lhs27);
  sf_mex_destroy(&c67_rhs28);
  sf_mex_destroy(&c67_lhs28);
  sf_mex_destroy(&c67_rhs29);
  sf_mex_destroy(&c67_lhs29);
  sf_mex_destroy(&c67_rhs30);
  sf_mex_destroy(&c67_lhs30);
  sf_mex_destroy(&c67_rhs31);
  sf_mex_destroy(&c67_lhs31);
  sf_mex_destroy(&c67_rhs32);
  sf_mex_destroy(&c67_lhs32);
  sf_mex_destroy(&c67_rhs33);
  sf_mex_destroy(&c67_lhs33);
  sf_mex_destroy(&c67_rhs34);
  sf_mex_destroy(&c67_lhs34);
  sf_mex_destroy(&c67_rhs35);
  sf_mex_destroy(&c67_lhs35);
  sf_mex_destroy(&c67_rhs36);
  sf_mex_destroy(&c67_lhs36);
  sf_mex_destroy(&c67_rhs37);
  sf_mex_destroy(&c67_lhs37);
  sf_mex_destroy(&c67_rhs38);
  sf_mex_destroy(&c67_lhs38);
  sf_mex_destroy(&c67_rhs39);
  sf_mex_destroy(&c67_lhs39);
  sf_mex_destroy(&c67_rhs40);
  sf_mex_destroy(&c67_lhs40);
  sf_mex_destroy(&c67_rhs41);
  sf_mex_destroy(&c67_lhs41);
  sf_mex_destroy(&c67_rhs42);
  sf_mex_destroy(&c67_lhs42);
  sf_mex_destroy(&c67_rhs43);
  sf_mex_destroy(&c67_lhs43);
  sf_mex_destroy(&c67_rhs44);
  sf_mex_destroy(&c67_lhs44);
  sf_mex_destroy(&c67_rhs45);
  sf_mex_destroy(&c67_lhs45);
  sf_mex_destroy(&c67_rhs46);
  sf_mex_destroy(&c67_lhs46);
  sf_mex_destroy(&c67_rhs47);
  sf_mex_destroy(&c67_lhs47);
  sf_mex_destroy(&c67_rhs48);
  sf_mex_destroy(&c67_lhs48);
  sf_mex_destroy(&c67_rhs49);
  sf_mex_destroy(&c67_lhs49);
  sf_mex_destroy(&c67_rhs50);
  sf_mex_destroy(&c67_lhs50);
  sf_mex_destroy(&c67_rhs51);
  sf_mex_destroy(&c67_lhs51);
  sf_mex_destroy(&c67_rhs52);
  sf_mex_destroy(&c67_lhs52);
  sf_mex_destroy(&c67_rhs53);
  sf_mex_destroy(&c67_lhs53);
  sf_mex_destroy(&c67_rhs54);
  sf_mex_destroy(&c67_lhs54);
  sf_mex_destroy(&c67_rhs55);
  sf_mex_destroy(&c67_lhs55);
  sf_mex_destroy(&c67_rhs56);
  sf_mex_destroy(&c67_lhs56);
  sf_mex_destroy(&c67_rhs57);
  sf_mex_destroy(&c67_lhs57);
  sf_mex_destroy(&c67_rhs58);
  sf_mex_destroy(&c67_lhs58);
  sf_mex_destroy(&c67_rhs59);
  sf_mex_destroy(&c67_lhs59);
  sf_mex_destroy(&c67_rhs60);
  sf_mex_destroy(&c67_lhs60);
  sf_mex_destroy(&c67_rhs61);
  sf_mex_destroy(&c67_lhs61);
  sf_mex_destroy(&c67_rhs62);
  sf_mex_destroy(&c67_lhs62);
  sf_mex_destroy(&c67_rhs63);
  sf_mex_destroy(&c67_lhs63);
}

static const mxArray *c67_emlrt_marshallOut(const char * c67_b_u)
{
  const mxArray *c67_y = NULL;
  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", c67_b_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c67_b_u)), false);
  return c67_y;
}

static const mxArray *c67_b_emlrt_marshallOut(const uint32_T c67_b_u)
{
  const mxArray *c67_y = NULL;
  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", &c67_b_u, 7, 0U, 0U, 0U, 0), false);
  return c67_y;
}

static void c67_b_info_helper(const mxArray **c67_info)
{
  const mxArray *c67_rhs64 = NULL;
  const mxArray *c67_lhs64 = NULL;
  const mxArray *c67_rhs65 = NULL;
  const mxArray *c67_lhs65 = NULL;
  const mxArray *c67_rhs66 = NULL;
  const mxArray *c67_lhs66 = NULL;
  const mxArray *c67_rhs67 = NULL;
  const mxArray *c67_lhs67 = NULL;
  const mxArray *c67_rhs68 = NULL;
  const mxArray *c67_lhs68 = NULL;
  const mxArray *c67_rhs69 = NULL;
  const mxArray *c67_lhs69 = NULL;
  const mxArray *c67_rhs70 = NULL;
  const mxArray *c67_lhs70 = NULL;
  const mxArray *c67_rhs71 = NULL;
  const mxArray *c67_lhs71 = NULL;
  const mxArray *c67_rhs72 = NULL;
  const mxArray *c67_lhs72 = NULL;
  const mxArray *c67_rhs73 = NULL;
  const mxArray *c67_lhs73 = NULL;
  const mxArray *c67_rhs74 = NULL;
  const mxArray *c67_lhs74 = NULL;
  const mxArray *c67_rhs75 = NULL;
  const mxArray *c67_lhs75 = NULL;
  const mxArray *c67_rhs76 = NULL;
  const mxArray *c67_lhs76 = NULL;
  const mxArray *c67_rhs77 = NULL;
  const mxArray *c67_lhs77 = NULL;
  const mxArray *c67_rhs78 = NULL;
  const mxArray *c67_lhs78 = NULL;
  const mxArray *c67_rhs79 = NULL;
  const mxArray *c67_lhs79 = NULL;
  const mxArray *c67_rhs80 = NULL;
  const mxArray *c67_lhs80 = NULL;
  const mxArray *c67_rhs81 = NULL;
  const mxArray *c67_lhs81 = NULL;
  const mxArray *c67_rhs82 = NULL;
  const mxArray *c67_lhs82 = NULL;
  const mxArray *c67_rhs83 = NULL;
  const mxArray *c67_lhs83 = NULL;
  const mxArray *c67_rhs84 = NULL;
  const mxArray *c67_lhs84 = NULL;
  const mxArray *c67_rhs85 = NULL;
  const mxArray *c67_lhs85 = NULL;
  const mxArray *c67_rhs86 = NULL;
  const mxArray *c67_lhs86 = NULL;
  const mxArray *c67_rhs87 = NULL;
  const mxArray *c67_lhs87 = NULL;
  const mxArray *c67_rhs88 = NULL;
  const mxArray *c67_lhs88 = NULL;
  const mxArray *c67_rhs89 = NULL;
  const mxArray *c67_lhs89 = NULL;
  const mxArray *c67_rhs90 = NULL;
  const mxArray *c67_lhs90 = NULL;
  const mxArray *c67_rhs91 = NULL;
  const mxArray *c67_lhs91 = NULL;
  const mxArray *c67_rhs92 = NULL;
  const mxArray *c67_lhs92 = NULL;
  const mxArray *c67_rhs93 = NULL;
  const mxArray *c67_lhs93 = NULL;
  const mxArray *c67_rhs94 = NULL;
  const mxArray *c67_lhs94 = NULL;
  const mxArray *c67_rhs95 = NULL;
  const mxArray *c67_lhs95 = NULL;
  const mxArray *c67_rhs96 = NULL;
  const mxArray *c67_lhs96 = NULL;
  const mxArray *c67_rhs97 = NULL;
  const mxArray *c67_lhs97 = NULL;
  const mxArray *c67_rhs98 = NULL;
  const mxArray *c67_lhs98 = NULL;
  const mxArray *c67_rhs99 = NULL;
  const mxArray *c67_lhs99 = NULL;
  const mxArray *c67_rhs100 = NULL;
  const mxArray *c67_lhs100 = NULL;
  const mxArray *c67_rhs101 = NULL;
  const mxArray *c67_lhs101 = NULL;
  const mxArray *c67_rhs102 = NULL;
  const mxArray *c67_lhs102 = NULL;
  const mxArray *c67_rhs103 = NULL;
  const mxArray *c67_lhs103 = NULL;
  const mxArray *c67_rhs104 = NULL;
  const mxArray *c67_lhs104 = NULL;
  const mxArray *c67_rhs105 = NULL;
  const mxArray *c67_lhs105 = NULL;
  const mxArray *c67_rhs106 = NULL;
  const mxArray *c67_lhs106 = NULL;
  const mxArray *c67_rhs107 = NULL;
  const mxArray *c67_lhs107 = NULL;
  const mxArray *c67_rhs108 = NULL;
  const mxArray *c67_lhs108 = NULL;
  const mxArray *c67_rhs109 = NULL;
  const mxArray *c67_lhs109 = NULL;
  const mxArray *c67_rhs110 = NULL;
  const mxArray *c67_lhs110 = NULL;
  const mxArray *c67_rhs111 = NULL;
  const mxArray *c67_lhs111 = NULL;
  const mxArray *c67_rhs112 = NULL;
  const mxArray *c67_lhs112 = NULL;
  const mxArray *c67_rhs113 = NULL;
  const mxArray *c67_lhs113 = NULL;
  const mxArray *c67_rhs114 = NULL;
  const mxArray *c67_lhs114 = NULL;
  const mxArray *c67_rhs115 = NULL;
  const mxArray *c67_lhs115 = NULL;
  const mxArray *c67_rhs116 = NULL;
  const mxArray *c67_lhs116 = NULL;
  const mxArray *c67_rhs117 = NULL;
  const mxArray *c67_lhs117 = NULL;
  const mxArray *c67_rhs118 = NULL;
  const mxArray *c67_lhs118 = NULL;
  const mxArray *c67_rhs119 = NULL;
  const mxArray *c67_lhs119 = NULL;
  const mxArray *c67_rhs120 = NULL;
  const mxArray *c67_lhs120 = NULL;
  const mxArray *c67_rhs121 = NULL;
  const mxArray *c67_lhs121 = NULL;
  const mxArray *c67_rhs122 = NULL;
  const mxArray *c67_lhs122 = NULL;
  const mxArray *c67_rhs123 = NULL;
  const mxArray *c67_lhs123 = NULL;
  const mxArray *c67_rhs124 = NULL;
  const mxArray *c67_lhs124 = NULL;
  const mxArray *c67_rhs125 = NULL;
  const mxArray *c67_lhs125 = NULL;
  const mxArray *c67_rhs126 = NULL;
  const mxArray *c67_lhs126 = NULL;
  const mxArray *c67_rhs127 = NULL;
  const mxArray *c67_lhs127 = NULL;
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 64);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 64);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c67_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 65);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 65);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 65);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c67_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 66);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 66);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c67_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 67);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 67);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c67_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 68);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  68);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c67_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 69);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 69);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c67_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 70);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.xdotu"),
                  "name", "name", 70);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c67_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "context", "context", 71);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 71);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c67_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 72);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 72);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c67_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 73);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 73);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 73);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c67_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 74);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 74);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c67_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 75);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 75);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c67_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 76);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 76);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c67_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 77);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 77);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c67_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 78);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 78);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 78);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c67_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 79);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 79);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 79);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c67_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 80);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 80);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c67_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "context", "context", 81);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("max"), "name", "name", 81);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 81);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c67_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "context", "context", 82);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("mldivide"), "name", "name",
                  82);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "resolved",
                  "resolved", 82);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1319751566U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c67_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "context",
                  "context", 83);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_lusolve"), "name",
                  "name", 83);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m"), "resolved",
                  "resolved", 83);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1370031486U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c67_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 84);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_xgetrf"), "name", "name",
                  84);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840406U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c67_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "context", "context", 85);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_lapack_xgetrf"), "name",
                  "name", 85);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "resolved", "resolved", 85);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840410U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c67_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "context", "context", 86);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_matlab_zgetrf"), "name",
                  "name", 86);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1302710594U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c67_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 87);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("realmin"), "name", "name",
                  87);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 87);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c67_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 88);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 88);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 88);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1307672844U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c67_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 89);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 89);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c67_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 90);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eps"), "name", "name", 90);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 90);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c67_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 91);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 91);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 91);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c67_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 92);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_eps"), "name", "name",
                  92);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 92);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c67_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 93);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 93);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c67_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 94);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("min"), "name", "name", 94);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 94);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 94);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c67_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 95);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 95);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 95);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 95);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c67_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 96);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 96);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 96);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 96);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c67_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 97);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 97);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 97);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 97);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c67_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 98);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 98);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 98);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c67_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 99);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 99);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 99);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 99);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c67_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 100);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 100);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 100);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 100);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c67_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs100), "rhs",
                  "rhs", 100);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs100), "lhs",
                  "lhs", 100);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 101);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("colon"), "name", "name", 101);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 101);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c67_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs101), "rhs",
                  "rhs", 101);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs101), "lhs",
                  "lhs", 101);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 102);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("colon"), "name", "name", 102);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 102);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c67_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs102), "rhs",
                  "rhs", 102);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs102), "lhs",
                  "lhs", 102);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 103);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 103);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 103);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c67_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs103), "rhs",
                  "rhs", 103);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs103), "lhs",
                  "lhs", 103);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 104);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 104);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 104);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 104);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c67_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs104), "rhs",
                  "rhs", 104);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs104), "lhs",
                  "lhs", 104);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 105);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("floor"), "name", "name", 105);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 105);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c67_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs105), "rhs",
                  "rhs", 105);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs105), "lhs",
                  "lhs", 105);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 106);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 106);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c67_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs106), "rhs",
                  "rhs", 106);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs106), "lhs",
                  "lhs", 106);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 107);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 107);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c67_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs107), "rhs",
                  "rhs", 107);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs107), "lhs",
                  "lhs", 107);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 108);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("intmin"), "name", "name",
                  108);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 108);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c67_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs108), "rhs",
                  "rhs", 108);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs108), "lhs",
                  "lhs", 108);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 109);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("intmax"), "name", "name",
                  109);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 109);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c67_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs109), "rhs",
                  "rhs", 109);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs109), "lhs",
                  "lhs", 109);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 110);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("intmin"), "name", "name",
                  110);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 110);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c67_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs110), "rhs",
                  "rhs", 110);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs110), "lhs",
                  "lhs", 110);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 111);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("intmax"), "name", "name",
                  111);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 111);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c67_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs111), "rhs",
                  "rhs", 111);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs111), "lhs",
                  "lhs", 111);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 112);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 112);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 112);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 112);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c67_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs112), "rhs",
                  "rhs", 112);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs112), "lhs",
                  "lhs", 112);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 113);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 113);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 113);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 113);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c67_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs113), "rhs",
                  "rhs", 113);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs113), "lhs",
                  "lhs", 113);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 114);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 114);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 114);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c67_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs114), "rhs",
                  "rhs", 114);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs114), "lhs",
                  "lhs", 114);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 115);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 115);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 115);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 115);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c67_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs115), "rhs",
                  "rhs", 115);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs115), "lhs",
                  "lhs", 115);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 116);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 116);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 116);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c67_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs116), "rhs",
                  "rhs", 116);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs116), "lhs",
                  "lhs", 116);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 117);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 117);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 117);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c67_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs117), "rhs",
                  "rhs", 117);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs117), "lhs",
                  "lhs", 117);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 118);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 118);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 118);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 118);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c67_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs118), "rhs",
                  "rhs", 118);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs118), "lhs",
                  "lhs", 118);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 119);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("intmax"), "name", "name",
                  119);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 119);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 119);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c67_rhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs119), "rhs",
                  "rhs", 119);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs119), "lhs",
                  "lhs", 119);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 120);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 120);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 120);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 120);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c67_rhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs120), "rhs",
                  "rhs", 120);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs120), "lhs",
                  "lhs", 120);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 121);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 121);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 121);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c67_rhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs121), "rhs",
                  "rhs", 121);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs121), "lhs",
                  "lhs", 121);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 122);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 122);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 122);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 122);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c67_rhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs122), "rhs",
                  "rhs", 122);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs122), "lhs",
                  "lhs", 122);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 123);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 123);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 123);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c67_rhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs123), "rhs",
                  "rhs", 123);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs123), "lhs",
                  "lhs", 123);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 124);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 124);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 124);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 124);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c67_rhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs124), "rhs",
                  "rhs", 124);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs124), "lhs",
                  "lhs", 124);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 125);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 125);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 125);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c67_rhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs125), "rhs",
                  "rhs", 125);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs125), "lhs",
                  "lhs", 125);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 126);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 126);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 126);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c67_rhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs126), "rhs",
                  "rhs", 126);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs126), "lhs",
                  "lhs", 126);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 127);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 127);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 127);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 127);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c67_rhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs127), "rhs",
                  "rhs", 127);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs127), "lhs",
                  "lhs", 127);
  sf_mex_destroy(&c67_rhs64);
  sf_mex_destroy(&c67_lhs64);
  sf_mex_destroy(&c67_rhs65);
  sf_mex_destroy(&c67_lhs65);
  sf_mex_destroy(&c67_rhs66);
  sf_mex_destroy(&c67_lhs66);
  sf_mex_destroy(&c67_rhs67);
  sf_mex_destroy(&c67_lhs67);
  sf_mex_destroy(&c67_rhs68);
  sf_mex_destroy(&c67_lhs68);
  sf_mex_destroy(&c67_rhs69);
  sf_mex_destroy(&c67_lhs69);
  sf_mex_destroy(&c67_rhs70);
  sf_mex_destroy(&c67_lhs70);
  sf_mex_destroy(&c67_rhs71);
  sf_mex_destroy(&c67_lhs71);
  sf_mex_destroy(&c67_rhs72);
  sf_mex_destroy(&c67_lhs72);
  sf_mex_destroy(&c67_rhs73);
  sf_mex_destroy(&c67_lhs73);
  sf_mex_destroy(&c67_rhs74);
  sf_mex_destroy(&c67_lhs74);
  sf_mex_destroy(&c67_rhs75);
  sf_mex_destroy(&c67_lhs75);
  sf_mex_destroy(&c67_rhs76);
  sf_mex_destroy(&c67_lhs76);
  sf_mex_destroy(&c67_rhs77);
  sf_mex_destroy(&c67_lhs77);
  sf_mex_destroy(&c67_rhs78);
  sf_mex_destroy(&c67_lhs78);
  sf_mex_destroy(&c67_rhs79);
  sf_mex_destroy(&c67_lhs79);
  sf_mex_destroy(&c67_rhs80);
  sf_mex_destroy(&c67_lhs80);
  sf_mex_destroy(&c67_rhs81);
  sf_mex_destroy(&c67_lhs81);
  sf_mex_destroy(&c67_rhs82);
  sf_mex_destroy(&c67_lhs82);
  sf_mex_destroy(&c67_rhs83);
  sf_mex_destroy(&c67_lhs83);
  sf_mex_destroy(&c67_rhs84);
  sf_mex_destroy(&c67_lhs84);
  sf_mex_destroy(&c67_rhs85);
  sf_mex_destroy(&c67_lhs85);
  sf_mex_destroy(&c67_rhs86);
  sf_mex_destroy(&c67_lhs86);
  sf_mex_destroy(&c67_rhs87);
  sf_mex_destroy(&c67_lhs87);
  sf_mex_destroy(&c67_rhs88);
  sf_mex_destroy(&c67_lhs88);
  sf_mex_destroy(&c67_rhs89);
  sf_mex_destroy(&c67_lhs89);
  sf_mex_destroy(&c67_rhs90);
  sf_mex_destroy(&c67_lhs90);
  sf_mex_destroy(&c67_rhs91);
  sf_mex_destroy(&c67_lhs91);
  sf_mex_destroy(&c67_rhs92);
  sf_mex_destroy(&c67_lhs92);
  sf_mex_destroy(&c67_rhs93);
  sf_mex_destroy(&c67_lhs93);
  sf_mex_destroy(&c67_rhs94);
  sf_mex_destroy(&c67_lhs94);
  sf_mex_destroy(&c67_rhs95);
  sf_mex_destroy(&c67_lhs95);
  sf_mex_destroy(&c67_rhs96);
  sf_mex_destroy(&c67_lhs96);
  sf_mex_destroy(&c67_rhs97);
  sf_mex_destroy(&c67_lhs97);
  sf_mex_destroy(&c67_rhs98);
  sf_mex_destroy(&c67_lhs98);
  sf_mex_destroy(&c67_rhs99);
  sf_mex_destroy(&c67_lhs99);
  sf_mex_destroy(&c67_rhs100);
  sf_mex_destroy(&c67_lhs100);
  sf_mex_destroy(&c67_rhs101);
  sf_mex_destroy(&c67_lhs101);
  sf_mex_destroy(&c67_rhs102);
  sf_mex_destroy(&c67_lhs102);
  sf_mex_destroy(&c67_rhs103);
  sf_mex_destroy(&c67_lhs103);
  sf_mex_destroy(&c67_rhs104);
  sf_mex_destroy(&c67_lhs104);
  sf_mex_destroy(&c67_rhs105);
  sf_mex_destroy(&c67_lhs105);
  sf_mex_destroy(&c67_rhs106);
  sf_mex_destroy(&c67_lhs106);
  sf_mex_destroy(&c67_rhs107);
  sf_mex_destroy(&c67_lhs107);
  sf_mex_destroy(&c67_rhs108);
  sf_mex_destroy(&c67_lhs108);
  sf_mex_destroy(&c67_rhs109);
  sf_mex_destroy(&c67_lhs109);
  sf_mex_destroy(&c67_rhs110);
  sf_mex_destroy(&c67_lhs110);
  sf_mex_destroy(&c67_rhs111);
  sf_mex_destroy(&c67_lhs111);
  sf_mex_destroy(&c67_rhs112);
  sf_mex_destroy(&c67_lhs112);
  sf_mex_destroy(&c67_rhs113);
  sf_mex_destroy(&c67_lhs113);
  sf_mex_destroy(&c67_rhs114);
  sf_mex_destroy(&c67_lhs114);
  sf_mex_destroy(&c67_rhs115);
  sf_mex_destroy(&c67_lhs115);
  sf_mex_destroy(&c67_rhs116);
  sf_mex_destroy(&c67_lhs116);
  sf_mex_destroy(&c67_rhs117);
  sf_mex_destroy(&c67_lhs117);
  sf_mex_destroy(&c67_rhs118);
  sf_mex_destroy(&c67_lhs118);
  sf_mex_destroy(&c67_rhs119);
  sf_mex_destroy(&c67_lhs119);
  sf_mex_destroy(&c67_rhs120);
  sf_mex_destroy(&c67_lhs120);
  sf_mex_destroy(&c67_rhs121);
  sf_mex_destroy(&c67_lhs121);
  sf_mex_destroy(&c67_rhs122);
  sf_mex_destroy(&c67_lhs122);
  sf_mex_destroy(&c67_rhs123);
  sf_mex_destroy(&c67_lhs123);
  sf_mex_destroy(&c67_rhs124);
  sf_mex_destroy(&c67_lhs124);
  sf_mex_destroy(&c67_rhs125);
  sf_mex_destroy(&c67_lhs125);
  sf_mex_destroy(&c67_rhs126);
  sf_mex_destroy(&c67_lhs126);
  sf_mex_destroy(&c67_rhs127);
  sf_mex_destroy(&c67_lhs127);
}

static void c67_c_info_helper(const mxArray **c67_info)
{
  const mxArray *c67_rhs128 = NULL;
  const mxArray *c67_lhs128 = NULL;
  const mxArray *c67_rhs129 = NULL;
  const mxArray *c67_lhs129 = NULL;
  const mxArray *c67_rhs130 = NULL;
  const mxArray *c67_lhs130 = NULL;
  const mxArray *c67_rhs131 = NULL;
  const mxArray *c67_lhs131 = NULL;
  const mxArray *c67_rhs132 = NULL;
  const mxArray *c67_lhs132 = NULL;
  const mxArray *c67_rhs133 = NULL;
  const mxArray *c67_lhs133 = NULL;
  const mxArray *c67_rhs134 = NULL;
  const mxArray *c67_lhs134 = NULL;
  const mxArray *c67_rhs135 = NULL;
  const mxArray *c67_lhs135 = NULL;
  const mxArray *c67_rhs136 = NULL;
  const mxArray *c67_lhs136 = NULL;
  const mxArray *c67_rhs137 = NULL;
  const mxArray *c67_lhs137 = NULL;
  const mxArray *c67_rhs138 = NULL;
  const mxArray *c67_lhs138 = NULL;
  const mxArray *c67_rhs139 = NULL;
  const mxArray *c67_lhs139 = NULL;
  const mxArray *c67_rhs140 = NULL;
  const mxArray *c67_lhs140 = NULL;
  const mxArray *c67_rhs141 = NULL;
  const mxArray *c67_lhs141 = NULL;
  const mxArray *c67_rhs142 = NULL;
  const mxArray *c67_lhs142 = NULL;
  const mxArray *c67_rhs143 = NULL;
  const mxArray *c67_lhs143 = NULL;
  const mxArray *c67_rhs144 = NULL;
  const mxArray *c67_lhs144 = NULL;
  const mxArray *c67_rhs145 = NULL;
  const mxArray *c67_lhs145 = NULL;
  const mxArray *c67_rhs146 = NULL;
  const mxArray *c67_lhs146 = NULL;
  const mxArray *c67_rhs147 = NULL;
  const mxArray *c67_lhs147 = NULL;
  const mxArray *c67_rhs148 = NULL;
  const mxArray *c67_lhs148 = NULL;
  const mxArray *c67_rhs149 = NULL;
  const mxArray *c67_lhs149 = NULL;
  const mxArray *c67_rhs150 = NULL;
  const mxArray *c67_lhs150 = NULL;
  const mxArray *c67_rhs151 = NULL;
  const mxArray *c67_lhs151 = NULL;
  const mxArray *c67_rhs152 = NULL;
  const mxArray *c67_lhs152 = NULL;
  const mxArray *c67_rhs153 = NULL;
  const mxArray *c67_lhs153 = NULL;
  const mxArray *c67_rhs154 = NULL;
  const mxArray *c67_lhs154 = NULL;
  const mxArray *c67_rhs155 = NULL;
  const mxArray *c67_lhs155 = NULL;
  const mxArray *c67_rhs156 = NULL;
  const mxArray *c67_lhs156 = NULL;
  const mxArray *c67_rhs157 = NULL;
  const mxArray *c67_lhs157 = NULL;
  const mxArray *c67_rhs158 = NULL;
  const mxArray *c67_lhs158 = NULL;
  const mxArray *c67_rhs159 = NULL;
  const mxArray *c67_lhs159 = NULL;
  const mxArray *c67_rhs160 = NULL;
  const mxArray *c67_lhs160 = NULL;
  const mxArray *c67_rhs161 = NULL;
  const mxArray *c67_lhs161 = NULL;
  const mxArray *c67_rhs162 = NULL;
  const mxArray *c67_lhs162 = NULL;
  const mxArray *c67_rhs163 = NULL;
  const mxArray *c67_lhs163 = NULL;
  const mxArray *c67_rhs164 = NULL;
  const mxArray *c67_lhs164 = NULL;
  const mxArray *c67_rhs165 = NULL;
  const mxArray *c67_lhs165 = NULL;
  const mxArray *c67_rhs166 = NULL;
  const mxArray *c67_lhs166 = NULL;
  const mxArray *c67_rhs167 = NULL;
  const mxArray *c67_lhs167 = NULL;
  const mxArray *c67_rhs168 = NULL;
  const mxArray *c67_lhs168 = NULL;
  const mxArray *c67_rhs169 = NULL;
  const mxArray *c67_lhs169 = NULL;
  const mxArray *c67_rhs170 = NULL;
  const mxArray *c67_lhs170 = NULL;
  const mxArray *c67_rhs171 = NULL;
  const mxArray *c67_lhs171 = NULL;
  const mxArray *c67_rhs172 = NULL;
  const mxArray *c67_lhs172 = NULL;
  const mxArray *c67_rhs173 = NULL;
  const mxArray *c67_lhs173 = NULL;
  const mxArray *c67_rhs174 = NULL;
  const mxArray *c67_lhs174 = NULL;
  const mxArray *c67_rhs175 = NULL;
  const mxArray *c67_lhs175 = NULL;
  const mxArray *c67_rhs176 = NULL;
  const mxArray *c67_lhs176 = NULL;
  const mxArray *c67_rhs177 = NULL;
  const mxArray *c67_lhs177 = NULL;
  const mxArray *c67_rhs178 = NULL;
  const mxArray *c67_lhs178 = NULL;
  const mxArray *c67_rhs179 = NULL;
  const mxArray *c67_lhs179 = NULL;
  const mxArray *c67_rhs180 = NULL;
  const mxArray *c67_lhs180 = NULL;
  const mxArray *c67_rhs181 = NULL;
  const mxArray *c67_lhs181 = NULL;
  const mxArray *c67_rhs182 = NULL;
  const mxArray *c67_lhs182 = NULL;
  const mxArray *c67_rhs183 = NULL;
  const mxArray *c67_lhs183 = NULL;
  const mxArray *c67_rhs184 = NULL;
  const mxArray *c67_lhs184 = NULL;
  const mxArray *c67_rhs185 = NULL;
  const mxArray *c67_lhs185 = NULL;
  const mxArray *c67_rhs186 = NULL;
  const mxArray *c67_lhs186 = NULL;
  const mxArray *c67_rhs187 = NULL;
  const mxArray *c67_lhs187 = NULL;
  const mxArray *c67_rhs188 = NULL;
  const mxArray *c67_lhs188 = NULL;
  const mxArray *c67_rhs189 = NULL;
  const mxArray *c67_lhs189 = NULL;
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 128);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 128);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 128);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 128);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c67_rhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs128), "rhs",
                  "rhs", 128);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs128), "lhs",
                  "lhs", 128);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 129);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 129);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 129);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 129);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 129);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 129);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 129);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 129);
  sf_mex_assign(&c67_rhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs129), "rhs",
                  "rhs", 129);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs129), "lhs",
                  "lhs", 129);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 130);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 130);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 130);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 130);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 130);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 130);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 130);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 130);
  sf_mex_assign(&c67_rhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs130), "rhs",
                  "rhs", 130);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs130), "lhs",
                  "lhs", 130);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 131);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 131);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 131);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 131);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 131);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 131);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 131);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 131);
  sf_mex_assign(&c67_rhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs131), "rhs",
                  "rhs", 131);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs131), "lhs",
                  "lhs", 131);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 132);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 132);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 132);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 132);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 132);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 132);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 132);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 132);
  sf_mex_assign(&c67_rhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs132), "rhs",
                  "rhs", 132);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs132), "lhs",
                  "lhs", 132);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 133);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 133);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 133);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 133);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 133);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 133);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 133);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 133);
  sf_mex_assign(&c67_rhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs133), "rhs",
                  "rhs", 133);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs133), "lhs",
                  "lhs", 133);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 134);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_ixamax"), "name", "name",
                  134);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 134);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "resolved", "resolved", 134);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 134);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 134);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 134);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 134);
  sf_mex_assign(&c67_rhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs134), "rhs",
                  "rhs", 134);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs134), "lhs",
                  "lhs", 134);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "context", "context", 135);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 135);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 135);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 135);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 135);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 135);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 135);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 135);
  sf_mex_assign(&c67_rhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs135), "rhs",
                  "rhs", 135);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs135), "lhs",
                  "lhs", 135);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "context", "context", 136);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.ixamax"),
                  "name", "name", 136);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 136);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "resolved", "resolved", 136);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 136);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 136);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 136);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 136);
  sf_mex_assign(&c67_rhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs136), "rhs",
                  "rhs", 136);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs136), "lhs",
                  "lhs", 136);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "context", "context", 137);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 137);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 137);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 137);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 137);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 137);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 137);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 137);
  sf_mex_assign(&c67_rhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs137), "rhs",
                  "rhs", 137);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs137), "lhs",
                  "lhs", 137);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                  "context", "context", 138);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 138);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 138);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 138);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 138);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 138);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 138);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 138);
  sf_mex_assign(&c67_rhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs138), "rhs",
                  "rhs", 138);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs138), "lhs",
                  "lhs", 138);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                  "context", "context", 139);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("length"), "name", "name",
                  139);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 139);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 139);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 139);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 139);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 139);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 139);
  sf_mex_assign(&c67_rhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs139), "rhs",
                  "rhs", 139);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs139), "lhs",
                  "lhs", 139);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 140);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 140);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 140);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 140);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 140);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 140);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 140);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 140);
  sf_mex_assign(&c67_rhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs140), "rhs",
                  "rhs", 140);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs140), "lhs",
                  "lhs", 140);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "context", "context", 141);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.refblas.ixamax"), "name", "name", 141);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 141);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "resolved", "resolved", 141);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 141);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 141);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 141);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 141);
  sf_mex_assign(&c67_rhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs141), "rhs",
                  "rhs", 141);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs141), "lhs",
                  "lhs", 141);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 142);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.refblas.xcabs1"), "name", "name", 142);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 142);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 142);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 142);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 142);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 142);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 142);
  sf_mex_assign(&c67_rhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs142), "rhs",
                  "rhs", 142);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs142), "lhs",
                  "lhs", 142);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "context", "context", 143);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("abs"), "name", "name", 143);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 143);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 143);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 143);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 143);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 143);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 143);
  sf_mex_assign(&c67_rhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs143), "rhs",
                  "rhs", 143);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs143), "lhs",
                  "lhs", 143);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 144);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 144);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 144);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 144);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 144);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 144);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 144);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 144);
  sf_mex_assign(&c67_rhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs144), "rhs",
                  "rhs", 144);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs144), "lhs",
                  "lhs", 144);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 145);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 145);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 145);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 145);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 145);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 145);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 145);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 145);
  sf_mex_assign(&c67_rhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs145), "rhs",
                  "rhs", 145);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs145), "lhs",
                  "lhs", 145);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 146);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 146);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 146);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 146);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 146);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 146);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 146);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 146);
  sf_mex_assign(&c67_rhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs146), "rhs",
                  "rhs", 146);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs146), "lhs",
                  "lhs", 146);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 147);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 147);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 147);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 147);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 147);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 147);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 147);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 147);
  sf_mex_assign(&c67_rhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs147), "rhs",
                  "rhs", 147);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs147), "lhs",
                  "lhs", 147);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 148);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_xswap"), "name", "name",
                  148);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 148);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"),
                  "resolved", "resolved", 148);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 148);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 148);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 148);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 148);
  sf_mex_assign(&c67_rhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs148), "rhs",
                  "rhs", 148);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs148), "lhs",
                  "lhs", 148);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 149);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 149);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 149);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 149);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 149);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 149);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 149);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 149);
  sf_mex_assign(&c67_rhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs149), "rhs",
                  "rhs", 149);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs149), "lhs",
                  "lhs", 149);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 150);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.xswap"),
                  "name", "name", 150);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 150);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "resolved", "resolved", 150);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 150);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 150);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 150);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 150);
  sf_mex_assign(&c67_rhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs150), "rhs",
                  "rhs", 150);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs150), "lhs",
                  "lhs", 150);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 151);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 151);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 151);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 151);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 151);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 151);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 151);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 151);
  sf_mex_assign(&c67_rhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs151), "rhs",
                  "rhs", 151);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs151), "lhs",
                  "lhs", 151);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p!below_threshold"),
                  "context", "context", 152);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 152);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 152);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 152);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 152);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 152);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 152);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 152);
  sf_mex_assign(&c67_rhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs152), "rhs",
                  "rhs", 152);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs152), "lhs",
                  "lhs", 152);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 153);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.refblas.xswap"), "name", "name", 153);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 153);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "resolved", "resolved", 153);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 153);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 153);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 153);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 153);
  sf_mex_assign(&c67_rhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs153), "rhs",
                  "rhs", 153);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs153), "lhs",
                  "lhs", 153);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 154);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("abs"), "name", "name", 154);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 154);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 154);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 154);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 154);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 154);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 154);
  sf_mex_assign(&c67_rhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs154), "rhs",
                  "rhs", 154);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs154), "lhs",
                  "lhs", 154);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 155);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 155);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 155);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 155);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 155);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 155);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 155);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 155);
  sf_mex_assign(&c67_rhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs155), "rhs",
                  "rhs", 155);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs155), "lhs",
                  "lhs", 155);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 156);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 156);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 156);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 156);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 156);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 156);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 156);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 156);
  sf_mex_assign(&c67_rhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs156), "rhs",
                  "rhs", 156);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs156), "lhs",
                  "lhs", 156);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 157);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 157);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 157);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 157);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 157);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 157);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 157);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 157);
  sf_mex_assign(&c67_rhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs157), "rhs",
                  "rhs", 157);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs157), "lhs",
                  "lhs", 157);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 158);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 158);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 158);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 158);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 158);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 158);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 158);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 158);
  sf_mex_assign(&c67_rhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs158), "rhs",
                  "rhs", 158);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs158), "lhs",
                  "lhs", 158);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 159);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_div"), "name", "name",
                  159);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 159);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 159);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 159);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 159);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 159);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 159);
  sf_mex_assign(&c67_rhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs159), "rhs",
                  "rhs", 159);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs159), "lhs",
                  "lhs", 159);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 160);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_xgeru"), "name", "name",
                  160);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 160);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"),
                  "resolved", "resolved", 160);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 160);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 160);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 160);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 160);
  sf_mex_assign(&c67_rhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs160), "rhs",
                  "rhs", 160);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs160), "lhs",
                  "lhs", 160);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 161);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 161);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 161);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 161);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 161);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 161);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 161);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 161);
  sf_mex_assign(&c67_rhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs161), "rhs",
                  "rhs", 161);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs161), "lhs",
                  "lhs", 161);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 162);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.xgeru"),
                  "name", "name", 162);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 162);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                  "resolved", "resolved", 162);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 162);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 162);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 162);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 162);
  sf_mex_assign(&c67_rhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs162), "rhs",
                  "rhs", 162);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs162), "lhs",
                  "lhs", 162);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                  "context", "context", 163);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.xger"),
                  "name", "name", 163);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 163);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "resolved", "resolved", 163);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 163);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 163);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 163);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 163);
  sf_mex_assign(&c67_rhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs163), "rhs",
                  "rhs", 163);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs163), "lhs",
                  "lhs", 163);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "context", "context", 164);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 164);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 164);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 164);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 164);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 164);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 164);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 164);
  sf_mex_assign(&c67_rhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs164), "rhs",
                  "rhs", 164);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs164), "lhs",
                  "lhs", 164);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 165);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 165);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 165);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 165);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 165);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 165);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 165);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 165);
  sf_mex_assign(&c67_rhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs165), "rhs",
                  "rhs", 165);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs165), "lhs",
                  "lhs", 165);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 166);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.int"),
                  "name", "name", 166);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 166);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/int.p"),
                  "resolved", "resolved", 166);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 166);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 166);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 166);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 166);
  sf_mex_assign(&c67_rhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs166), "rhs",
                  "rhs", 166);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs166), "lhs",
                  "lhs", 166);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 167);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("intmax"), "name", "name",
                  167);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 167);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 167);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 167);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 167);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 167);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 167);
  sf_mex_assign(&c67_rhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs167), "rhs",
                  "rhs", 167);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs167), "lhs",
                  "lhs", 167);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 168);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("min"), "name", "name", 168);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 168);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 168);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 168);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 168);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 168);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 168);
  sf_mex_assign(&c67_rhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs168), "rhs",
                  "rhs", 168);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs168), "lhs",
                  "lhs", 168);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "context", "context", 169);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.refblas.xger"),
                  "name", "name", 169);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 169);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                  "resolved", "resolved", 169);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 169);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 169);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 169);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 169);
  sf_mex_assign(&c67_rhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs169), "rhs",
                  "rhs", 169);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs169), "lhs",
                  "lhs", 169);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                  "context", "context", 170);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.refblas.xgerx"), "name", "name", 170);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 170);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "resolved", "resolved", 170);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 170);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 170);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 170);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 170);
  sf_mex_assign(&c67_rhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs170), "rhs",
                  "rhs", 170);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs170), "lhs",
                  "lhs", 170);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 171);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("abs"), "name", "name", 171);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 171);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 171);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 171);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 171);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 171);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 171);
  sf_mex_assign(&c67_rhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs171), "rhs",
                  "rhs", 171);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs171), "lhs",
                  "lhs", 171);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 172);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 172);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 172);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 172);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 172);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 172);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 172);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 172);
  sf_mex_assign(&c67_rhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs172), "rhs",
                  "rhs", 172);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs172), "lhs",
                  "lhs", 172);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 173);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 173);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 173);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 173);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 173);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 173);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 173);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 173);
  sf_mex_assign(&c67_rhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs173), "rhs",
                  "rhs", 173);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs173), "lhs",
                  "lhs", 173);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 174);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 174);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 174);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 174);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 174);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 174);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 174);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 174);
  sf_mex_assign(&c67_rhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs174), "rhs",
                  "rhs", 174);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs174), "lhs",
                  "lhs", 174);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 175);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 175);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 175);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 175);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 175);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 175);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 175);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 175);
  sf_mex_assign(&c67_rhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs175), "rhs",
                  "rhs", 175);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs175), "lhs",
                  "lhs", 175);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular"),
                  "context", "context", 176);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_warning"), "name",
                  "name", 176);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 176);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 176);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1286840402U), "fileTimeLo",
                  "fileTimeLo", 176);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 176);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 176);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 176);
  sf_mex_assign(&c67_rhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs176), "rhs",
                  "rhs", 176);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs176), "lhs",
                  "lhs", 176);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 177);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 177);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 177);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 177);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 177);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 177);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 177);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 177);
  sf_mex_assign(&c67_rhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs177), "rhs",
                  "rhs", 177);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs177), "lhs",
                  "lhs", 177);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 178);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 178);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 178);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 178);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 178);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 178);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 178);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 178);
  sf_mex_assign(&c67_rhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs178), "rhs",
                  "rhs", 178);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs178), "lhs",
                  "lhs", 178);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 179);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("eml_xtrsm"), "name", "name",
                  179);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 179);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"),
                  "resolved", "resolved", 179);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 179);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 179);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 179);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 179);
  sf_mex_assign(&c67_rhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs179), "rhs",
                  "rhs", 179);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs179), "lhs",
                  "lhs", 179);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                  "context", 180);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 180);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 180);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 180);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 180);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 180);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 180);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 180);
  sf_mex_assign(&c67_rhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs180), "rhs",
                  "rhs", 180);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs180), "lhs",
                  "lhs", 180);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                  "context", 181);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.blas.xtrsm"),
                  "name", "name", 181);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 181);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "resolved", "resolved", 181);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 181);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 181);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 181);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 181);
  sf_mex_assign(&c67_rhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs181), "rhs",
                  "rhs", 181);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs181), "lhs",
                  "lhs", 181);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 182);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 182);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 182);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 182);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 182);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 182);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 182);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 182);
  sf_mex_assign(&c67_rhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs182), "rhs",
                  "rhs", 182);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs182), "lhs",
                  "lhs", 182);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p!below_threshold"),
                  "context", "context", 183);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 183);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 183);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 183);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 183);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 183);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 183);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 183);
  sf_mex_assign(&c67_rhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs183), "rhs",
                  "rhs", 183);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs183), "lhs",
                  "lhs", 183);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 184);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 184);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 184);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 184);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 184);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 184);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 184);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 184);
  sf_mex_assign(&c67_rhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs184), "rhs",
                  "rhs", 184);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs184), "lhs",
                  "lhs", 184);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 185);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "coder.internal.refblas.xtrsm"), "name", "name", 185);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 185);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "resolved", "resolved", 185);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 185);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 185);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 185);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 185);
  sf_mex_assign(&c67_rhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs185), "rhs",
                  "rhs", 185);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs185), "lhs",
                  "lhs", 185);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 186);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 186);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 186);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 186);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 186);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 186);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 186);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 186);
  sf_mex_assign(&c67_rhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs186), "rhs",
                  "rhs", 186);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs186), "lhs",
                  "lhs", 186);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 187);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 187);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 187);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 187);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 187);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 187);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 187);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 187);
  sf_mex_assign(&c67_rhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs187), "rhs",
                  "rhs", 187);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs187), "lhs",
                  "lhs", 187);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 188);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 188);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 188);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 188);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 188);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 188);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 188);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 188);
  sf_mex_assign(&c67_rhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs188), "rhs",
                  "rhs", 188);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs188), "lhs",
                  "lhs", 188);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 189);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("rdivide"), "name", "name",
                  189);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 189);
  sf_mex_addfield(*c67_info, c67_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 189);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 189);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 189);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 189);
  sf_mex_addfield(*c67_info, c67_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 189);
  sf_mex_assign(&c67_rhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c67_lhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_rhs189), "rhs",
                  "rhs", 189);
  sf_mex_addfield(*c67_info, sf_mex_duplicatearraysafe(&c67_lhs189), "lhs",
                  "lhs", 189);
  sf_mex_destroy(&c67_rhs128);
  sf_mex_destroy(&c67_lhs128);
  sf_mex_destroy(&c67_rhs129);
  sf_mex_destroy(&c67_lhs129);
  sf_mex_destroy(&c67_rhs130);
  sf_mex_destroy(&c67_lhs130);
  sf_mex_destroy(&c67_rhs131);
  sf_mex_destroy(&c67_lhs131);
  sf_mex_destroy(&c67_rhs132);
  sf_mex_destroy(&c67_lhs132);
  sf_mex_destroy(&c67_rhs133);
  sf_mex_destroy(&c67_lhs133);
  sf_mex_destroy(&c67_rhs134);
  sf_mex_destroy(&c67_lhs134);
  sf_mex_destroy(&c67_rhs135);
  sf_mex_destroy(&c67_lhs135);
  sf_mex_destroy(&c67_rhs136);
  sf_mex_destroy(&c67_lhs136);
  sf_mex_destroy(&c67_rhs137);
  sf_mex_destroy(&c67_lhs137);
  sf_mex_destroy(&c67_rhs138);
  sf_mex_destroy(&c67_lhs138);
  sf_mex_destroy(&c67_rhs139);
  sf_mex_destroy(&c67_lhs139);
  sf_mex_destroy(&c67_rhs140);
  sf_mex_destroy(&c67_lhs140);
  sf_mex_destroy(&c67_rhs141);
  sf_mex_destroy(&c67_lhs141);
  sf_mex_destroy(&c67_rhs142);
  sf_mex_destroy(&c67_lhs142);
  sf_mex_destroy(&c67_rhs143);
  sf_mex_destroy(&c67_lhs143);
  sf_mex_destroy(&c67_rhs144);
  sf_mex_destroy(&c67_lhs144);
  sf_mex_destroy(&c67_rhs145);
  sf_mex_destroy(&c67_lhs145);
  sf_mex_destroy(&c67_rhs146);
  sf_mex_destroy(&c67_lhs146);
  sf_mex_destroy(&c67_rhs147);
  sf_mex_destroy(&c67_lhs147);
  sf_mex_destroy(&c67_rhs148);
  sf_mex_destroy(&c67_lhs148);
  sf_mex_destroy(&c67_rhs149);
  sf_mex_destroy(&c67_lhs149);
  sf_mex_destroy(&c67_rhs150);
  sf_mex_destroy(&c67_lhs150);
  sf_mex_destroy(&c67_rhs151);
  sf_mex_destroy(&c67_lhs151);
  sf_mex_destroy(&c67_rhs152);
  sf_mex_destroy(&c67_lhs152);
  sf_mex_destroy(&c67_rhs153);
  sf_mex_destroy(&c67_lhs153);
  sf_mex_destroy(&c67_rhs154);
  sf_mex_destroy(&c67_lhs154);
  sf_mex_destroy(&c67_rhs155);
  sf_mex_destroy(&c67_lhs155);
  sf_mex_destroy(&c67_rhs156);
  sf_mex_destroy(&c67_lhs156);
  sf_mex_destroy(&c67_rhs157);
  sf_mex_destroy(&c67_lhs157);
  sf_mex_destroy(&c67_rhs158);
  sf_mex_destroy(&c67_lhs158);
  sf_mex_destroy(&c67_rhs159);
  sf_mex_destroy(&c67_lhs159);
  sf_mex_destroy(&c67_rhs160);
  sf_mex_destroy(&c67_lhs160);
  sf_mex_destroy(&c67_rhs161);
  sf_mex_destroy(&c67_lhs161);
  sf_mex_destroy(&c67_rhs162);
  sf_mex_destroy(&c67_lhs162);
  sf_mex_destroy(&c67_rhs163);
  sf_mex_destroy(&c67_lhs163);
  sf_mex_destroy(&c67_rhs164);
  sf_mex_destroy(&c67_lhs164);
  sf_mex_destroy(&c67_rhs165);
  sf_mex_destroy(&c67_lhs165);
  sf_mex_destroy(&c67_rhs166);
  sf_mex_destroy(&c67_lhs166);
  sf_mex_destroy(&c67_rhs167);
  sf_mex_destroy(&c67_lhs167);
  sf_mex_destroy(&c67_rhs168);
  sf_mex_destroy(&c67_lhs168);
  sf_mex_destroy(&c67_rhs169);
  sf_mex_destroy(&c67_lhs169);
  sf_mex_destroy(&c67_rhs170);
  sf_mex_destroy(&c67_lhs170);
  sf_mex_destroy(&c67_rhs171);
  sf_mex_destroy(&c67_lhs171);
  sf_mex_destroy(&c67_rhs172);
  sf_mex_destroy(&c67_lhs172);
  sf_mex_destroy(&c67_rhs173);
  sf_mex_destroy(&c67_lhs173);
  sf_mex_destroy(&c67_rhs174);
  sf_mex_destroy(&c67_lhs174);
  sf_mex_destroy(&c67_rhs175);
  sf_mex_destroy(&c67_lhs175);
  sf_mex_destroy(&c67_rhs176);
  sf_mex_destroy(&c67_lhs176);
  sf_mex_destroy(&c67_rhs177);
  sf_mex_destroy(&c67_lhs177);
  sf_mex_destroy(&c67_rhs178);
  sf_mex_destroy(&c67_lhs178);
  sf_mex_destroy(&c67_rhs179);
  sf_mex_destroy(&c67_lhs179);
  sf_mex_destroy(&c67_rhs180);
  sf_mex_destroy(&c67_lhs180);
  sf_mex_destroy(&c67_rhs181);
  sf_mex_destroy(&c67_lhs181);
  sf_mex_destroy(&c67_rhs182);
  sf_mex_destroy(&c67_lhs182);
  sf_mex_destroy(&c67_rhs183);
  sf_mex_destroy(&c67_lhs183);
  sf_mex_destroy(&c67_rhs184);
  sf_mex_destroy(&c67_lhs184);
  sf_mex_destroy(&c67_rhs185);
  sf_mex_destroy(&c67_lhs185);
  sf_mex_destroy(&c67_rhs186);
  sf_mex_destroy(&c67_lhs186);
  sf_mex_destroy(&c67_rhs187);
  sf_mex_destroy(&c67_lhs187);
  sf_mex_destroy(&c67_rhs188);
  sf_mex_destroy(&c67_lhs188);
  sf_mex_destroy(&c67_rhs189);
  sf_mex_destroy(&c67_lhs189);
}

static void c67_eml_scalar_eg(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c67_threshold(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c67_rdivide(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c67_x, real_T c67_y)
{
  real_T c67_b_x;
  real_T c67_b_y;
  real_T c67_c_x;
  real_T c67_c_y;
  (void)chartInstance;
  c67_b_x = c67_x;
  c67_b_y = c67_y;
  c67_c_x = c67_b_x;
  c67_c_y = c67_b_y;
  return c67_c_x / c67_c_y;
}

static void c67_eml_switch_helper(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c67_check_forloop_overflow_error(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, boolean_T c67_overflow)
{
  int32_T c67_i266;
  static char_T c67_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c67_b_u[34];
  const mxArray *c67_y = NULL;
  int32_T c67_i267;
  static char_T c67_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c67_c_u[5];
  const mxArray *c67_b_y = NULL;
  (void)chartInstance;
  if (!c67_overflow) {
  } else {
    for (c67_i266 = 0; c67_i266 < 34; c67_i266++) {
      c67_b_u[c67_i266] = c67_cv0[c67_i266];
    }

    c67_y = NULL;
    sf_mex_assign(&c67_y, sf_mex_create("y", c67_b_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c67_i267 = 0; c67_i267 < 5; c67_i267++) {
      c67_c_u[c67_i267] = c67_cv1[c67_i267];
    }

    c67_b_y = NULL;
    sf_mex_assign(&c67_b_y, sf_mex_create("y", c67_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c67_y, 14, c67_b_y));
  }
}

static void c67_b_eml_scalar_eg(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c67_c_eml_scalar_eg(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c67_eml_xdotu(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c67_x[2], real_T c67_y[2])
{
  real_T c67_d;
  int32_T c67_k;
  int32_T c67_b_k;
  c67_d = 0.0;
  c67_eml_switch_helper(chartInstance);
  for (c67_k = 1; c67_k < 3; c67_k++) {
    c67_b_k = c67_k;
    c67_d += c67_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c67_b_k), 1, 2, 1, 0) - 1] * c67_y[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c67_b_k), 1, 2, 1, 0) - 1];
  }

  return c67_d;
}

static void c67_realmin(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c67_eps(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c67_eml_matlab_zgetrf(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c67_A[36], real_T c67_b_A[36], int32_T c67_ipiv[6],
  int32_T *c67_info)
{
  int32_T c67_i268;
  for (c67_i268 = 0; c67_i268 < 36; c67_i268++) {
    c67_b_A[c67_i268] = c67_A[c67_i268];
  }

  c67_b_eml_matlab_zgetrf(chartInstance, c67_b_A, c67_ipiv, c67_info);
}

static int32_T c67_eml_ixamax(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c67_n, real_T c67_x[36], int32_T c67_ix0)
{
  int32_T c67_idxmax;
  int32_T c67_b_n;
  int32_T c67_b_ix0;
  int32_T c67_c_n;
  int32_T c67_c_ix0;
  int32_T c67_ix;
  real_T c67_b_x;
  real_T c67_c_x;
  real_T c67_d_x;
  real_T c67_y;
  real_T c67_e_x;
  real_T c67_f_x;
  real_T c67_b_y;
  real_T c67_smax;
  int32_T c67_d_n;
  int32_T c67_b;
  int32_T c67_b_b;
  boolean_T c67_overflow;
  int32_T c67_k;
  int32_T c67_b_k;
  int32_T c67_a;
  real_T c67_g_x;
  real_T c67_h_x;
  real_T c67_i_x;
  real_T c67_c_y;
  real_T c67_j_x;
  real_T c67_k_x;
  real_T c67_d_y;
  real_T c67_b_s;
  c67_b_n = c67_n;
  c67_b_ix0 = c67_ix0;
  c67_c_n = c67_b_n;
  c67_c_ix0 = c67_b_ix0;
  if (c67_c_n < 1) {
    c67_idxmax = 0;
  } else {
    c67_idxmax = 1;
    if (c67_c_n > 1) {
      c67_ix = c67_c_ix0;
      c67_b_x = c67_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_ix), 1, 36, 1, 0) - 1];
      c67_c_x = c67_b_x;
      c67_d_x = c67_c_x;
      c67_y = muDoubleScalarAbs(c67_d_x);
      c67_e_x = 0.0;
      c67_f_x = c67_e_x;
      c67_b_y = muDoubleScalarAbs(c67_f_x);
      c67_smax = c67_y + c67_b_y;
      c67_d_n = c67_c_n;
      c67_b = c67_d_n;
      c67_b_b = c67_b;
      if (2 > c67_b_b) {
        c67_overflow = false;
      } else {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_overflow = (c67_b_b > 2147483646);
      }

      if (c67_overflow) {
        c67_check_forloop_overflow_error(chartInstance, c67_overflow);
      }

      for (c67_k = 2; c67_k <= c67_d_n; c67_k++) {
        c67_b_k = c67_k;
        c67_a = c67_ix + 1;
        c67_ix = c67_a;
        c67_g_x = c67_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_ix), 1, 36, 1, 0) - 1];
        c67_h_x = c67_g_x;
        c67_i_x = c67_h_x;
        c67_c_y = muDoubleScalarAbs(c67_i_x);
        c67_j_x = 0.0;
        c67_k_x = c67_j_x;
        c67_d_y = muDoubleScalarAbs(c67_k_x);
        c67_b_s = c67_c_y + c67_d_y;
        if (c67_b_s > c67_smax) {
          c67_idxmax = c67_b_k;
          c67_smax = c67_b_s;
        }
      }
    }
  }

  return c67_idxmax;
}

static void c67_b_eml_switch_helper(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c67_eml_xgeru(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c67_m, int32_T c67_n, real_T c67_alpha1, int32_T c67_ix0, int32_T
  c67_iy0, real_T c67_A[36], int32_T c67_ia0, real_T c67_b_A[36])
{
  int32_T c67_i269;
  for (c67_i269 = 0; c67_i269 < 36; c67_i269++) {
    c67_b_A[c67_i269] = c67_A[c67_i269];
  }

  c67_b_eml_xgeru(chartInstance, c67_m, c67_n, c67_alpha1, c67_ix0, c67_iy0,
                  c67_b_A, c67_ia0);
}

static void c67_eml_warning(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  int32_T c67_i270;
  static char_T c67_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c67_b_u[27];
  const mxArray *c67_y = NULL;
  (void)chartInstance;
  for (c67_i270 = 0; c67_i270 < 27; c67_i270++) {
    c67_b_u[c67_i270] = c67_varargin_1[c67_i270];
  }

  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", c67_b_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c67_y));
}

static void c67_eml_xtrsm(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c67_A[36], real_T c67_B[6], real_T c67_b_B[6])
{
  int32_T c67_i271;
  int32_T c67_i272;
  real_T c67_b_A[36];
  for (c67_i271 = 0; c67_i271 < 6; c67_i271++) {
    c67_b_B[c67_i271] = c67_B[c67_i271];
  }

  for (c67_i272 = 0; c67_i272 < 36; c67_i272++) {
    c67_b_A[c67_i272] = c67_A[c67_i272];
  }

  c67_c_eml_xtrsm(chartInstance, c67_b_A, c67_b_B);
}

static void c67_below_threshold(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  c67_c_eml_switch_helper(chartInstance);
}

static void c67_c_eml_switch_helper(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c67_scalarEg(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c67_b_eml_xtrsm(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c67_A[36], real_T c67_B[6], real_T c67_b_B[6])
{
  int32_T c67_i273;
  int32_T c67_i274;
  real_T c67_b_A[36];
  for (c67_i273 = 0; c67_i273 < 6; c67_i273++) {
    c67_b_B[c67_i273] = c67_B[c67_i273];
  }

  for (c67_i274 = 0; c67_i274 < 36; c67_i274++) {
    c67_b_A[c67_i274] = c67_A[c67_i274];
  }

  c67_d_eml_xtrsm(chartInstance, c67_b_A, c67_b_B);
}

static const mxArray *c67_h_sf_marshallOut(void *chartInstanceVoid, void
  *c67_inData)
{
  const mxArray *c67_mxArrayOutData = NULL;
  int32_T c67_b_u;
  const mxArray *c67_y = NULL;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_mxArrayOutData = NULL;
  c67_b_u = *(int32_T *)c67_inData;
  c67_y = NULL;
  sf_mex_assign(&c67_y, sf_mex_create("y", &c67_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c67_mxArrayOutData, c67_y, false);
  return c67_mxArrayOutData;
}

static int32_T c67_g_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId)
{
  int32_T c67_y;
  int32_T c67_i275;
  (void)chartInstance;
  sf_mex_import(c67_parentId, sf_mex_dup(c67_b_u), &c67_i275, 1, 6, 0U, 0, 0U, 0);
  c67_y = c67_i275;
  sf_mex_destroy(&c67_b_u);
  return c67_y;
}

static void c67_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c67_mxArrayInData, const char_T *c67_varName, void *c67_outData)
{
  const mxArray *c67_b_sfEvent;
  const char_T *c67_identifier;
  emlrtMsgIdentifier c67_thisId;
  int32_T c67_y;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_b_sfEvent = sf_mex_dup(c67_mxArrayInData);
  c67_identifier = c67_varName;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_y = c67_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c67_b_sfEvent),
    &c67_thisId);
  sf_mex_destroy(&c67_b_sfEvent);
  *(int32_T *)c67_outData = c67_y;
  sf_mex_destroy(&c67_mxArrayInData);
}

static const mxArray *c67_ControlState_bus_io(void *chartInstanceVoid, void
  *c67_pData)
{
  const mxArray *c67_mxVal = NULL;
  c67_ControlStateBus c67_tmp;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_mxVal = NULL;
  c67_tmp.ControllerMode = *(real_T *)&((char_T *)(c67_ControlStateBus *)
    c67_pData)[0];
  c67_tmp.SupportState = *(real_T *)&((char_T *)(c67_ControlStateBus *)c67_pData)
    [8];
  c67_tmp.StanceLeg = *(real_T *)&((char_T *)(c67_ControlStateBus *)c67_pData)
    [16];
  c67_tmp.InDoubleSupport = *(real_T *)&((char_T *)(c67_ControlStateBus *)
    c67_pData)[24];
  c67_tmp.RollPhase = *(real_T *)&((char_T *)(c67_ControlStateBus *)c67_pData)
    [32];
  c67_tmp.StepCount = *(real_T *)&((char_T *)(c67_ControlStateBus *)c67_pData)
    [40];
  c67_tmp.Error = *(real_T *)&((char_T *)(c67_ControlStateBus *)c67_pData)[48];
  sf_mex_assign(&c67_mxVal, c67_c_sf_marshallOut(chartInstance, &c67_tmp), false);
  return c67_mxVal;
}

static const mxArray *c67_ControlParams_bus_io(void *chartInstanceVoid, void
  *c67_pData)
{
  const mxArray *c67_mxVal = NULL;
  c67_ControlParamsBus c67_tmp;
  int32_T c67_i276;
  int32_T c67_i277;
  int32_T c67_i278;
  int32_T c67_i279;
  int32_T c67_i280;
  int32_T c67_i281;
  int32_T c67_i282;
  int32_T c67_i283;
  int32_T c67_i284;
  int32_T c67_i285;
  int32_T c67_i286;
  int32_T c67_i287;
  int32_T c67_i288;
  int32_T c67_i289;
  int32_T c67_i290;
  int32_T c67_i291;
  int32_T c67_i292;
  int32_T c67_i293;
  int32_T c67_i294;
  int32_T c67_i295;
  int32_T c67_i296;
  int32_T c67_i297;
  int32_T c67_i298;
  int32_T c67_i299;
  int32_T c67_i300;
  int32_T c67_i301;
  int32_T c67_i302;
  int32_T c67_i303;
  int32_T c67_i304;
  int32_T c67_i305;
  int32_T c67_i306;
  int32_T c67_i307;
  int32_T c67_i308;
  int32_T c67_i309;
  int32_T c67_i310;
  int32_T c67_i311;
  int32_T c67_i312;
  int32_T c67_i313;
  int32_T c67_i314;
  int32_T c67_i315;
  int32_T c67_i316;
  int32_T c67_i317;
  int32_T c67_i318;
  int32_T c67_i319;
  int32_T c67_i320;
  int32_T c67_i321;
  int32_T c67_i322;
  int32_T c67_i323;
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c67_mxVal = NULL;
  c67_tmp.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [0];
  c67_tmp.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [8];
  c67_tmp.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [16];
  c67_tmp.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [24];
  c67_tmp.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [32];
  c67_tmp.Supervisory.ImpactThresholdKASpringRel = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [40];
  c67_tmp.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [48];
  c67_tmp.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [56];
  c67_tmp.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [64];
  c67_tmp.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [72];
  c67_tmp.Supervisory.TransitionThresholdTorsoVel = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [80];
  for (c67_i276 = 0; c67_i276 < 2; c67_i276++) {
    c67_tmp.Supervisory.KAInjection[c67_i276] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [0])[88])[c67_i276];
  }

  c67_tmp.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [104];
  c67_tmp.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [112];
  for (c67_i277 = 0; c67_i277 < 6; c67_i277++) {
    c67_tmp.Supervisory.VBLAParams[c67_i277] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [0])[120])[c67_i277];
  }

  for (c67_i278 = 0; c67_i278 < 13; c67_i278++) {
    c67_tmp.Supervisory.BalanceParams[c67_i278] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [0])[168])[c67_i278];
  }

  for (c67_i279 = 0; c67_i279 < 5; c67_i279++) {
    c67_tmp.Supervisory.GaitTweaks[c67_i279] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [0])[272])[c67_i279];
  }

  c67_tmp.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [312];
  c67_tmp.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [320];
  c67_tmp.Supervisory.RunMode = *(real_T *)&((char_T *)(c67_SupervisoryParamsBus
    *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])[328];
  c67_tmp.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [336];
  for (c67_i280 = 0; c67_i280 < 6; c67_i280++) {
    c67_tmp.Supervisory.ErrorZeroFactor[c67_i280] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [0])[344])[c67_i280];
  }

  for (c67_i281 = 0; c67_i281 < 6; c67_i281++) {
    c67_tmp.Supervisory.ErrorVelZeroFactor[c67_i281] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [0])[392])[c67_i281];
  }

  c67_tmp.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [440];
  c67_tmp.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [448];
  c67_tmp.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [456];
  c67_tmp.Supervisory.TPosing = *(real_T *)&((char_T *)(c67_SupervisoryParamsBus
    *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])[464];
  c67_tmp.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [472];
  c67_tmp.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [480];
  c67_tmp.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [488];
  c67_tmp.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [496];
  c67_tmp.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [504];
  c67_tmp.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [512];
  c67_tmp.Supervisory.VelocityControlTorsoGain = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [520];
  c67_tmp.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [528];
  c67_tmp.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [536];
  c67_tmp.Supervisory.Theta0 = *(real_T *)&((char_T *)(c67_SupervisoryParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[0])[544];
  c67_tmp.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [552];
  c67_tmp.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [560];
  c67_tmp.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [568];
  c67_tmp.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [576];
  c67_tmp.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [584];
  c67_tmp.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [592];
  c67_tmp.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [600];
  for (c67_i282 = 0; c67_i282 < 6; c67_i282++) {
    c67_tmp.Supervisory.K1MidStanceUpdate[c67_i282] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [0])[608])[c67_i282];
  }

  for (c67_i283 = 0; c67_i283 < 6; c67_i283++) {
    c67_tmp.Supervisory.K2MidStanceUpdate[c67_i283] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [0])[656])[c67_i283];
  }

  c67_tmp.Supervisory.EnableVelocityBasedUpdate = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [704];
  for (c67_i284 = 0; c67_i284 < 6; c67_i284++) {
    c67_tmp.Supervisory.VelocityBasedUpdateK1[c67_i284] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [0])[712])[c67_i284];
  }

  for (c67_i285 = 0; c67_i285 < 6; c67_i285++) {
    c67_tmp.Supervisory.VelocityBasedUpdateK2[c67_i285] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [0])[760])[c67_i285];
  }

  c67_tmp.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [808];
  c67_i286 = 0;
  for (c67_i287 = 0; c67_i287 < 2; c67_i287++) {
    for (c67_i288 = 0; c67_i288 < 6; c67_i288++) {
      c67_tmp.Supervisory.VelocityBasedUpdateLimits[c67_i288 + c67_i286] =
        ((real_T *)&((char_T *)(c67_SupervisoryParamsBus *)&((char_T *)
           (c67_ControlParamsBus *)c67_pData)[0])[816])[c67_i288 + c67_i286];
    }

    c67_i286 += 6;
  }

  c67_tmp.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [912];
  c67_tmp.Supervisory.dx_cmd = *(real_T *)&((char_T *)(c67_SupervisoryParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[0])[920];
  c67_tmp.Supervisory.ForBackward = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [928];
  c67_tmp.Supervisory.EnableFrictionID = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [936];
  c67_tmp.Supervisory.ResetFrictionPosing = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [944];
  c67_tmp.Supervisory.MoveLegIndex = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [952];
  c67_tmp.Supervisory.dy_cmd = *(real_T *)&((char_T *)(c67_SupervisoryParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[0])[960];
  c67_tmp.Supervisory.TauDelay = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [968];
  c67_tmp.Supervisory.TrackFrequency = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [976];
  c67_tmp.Supervisory.EnablePDControl = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [984];
  c67_tmp.Supervisory.TorqueAmp = *(real_T *)&((char_T *)
    (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[0])
    [992];
  for (c67_i289 = 0; c67_i289 < 6; c67_i289++) {
    c67_tmp.Supervisory.hdPosing[c67_i289] = ((real_T *)&((char_T *)
      (c67_SupervisoryParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [0])[1000])[c67_i289];
  }

  c67_tmp.Discrete.TLastUpdate = *(real_T *)&((char_T *)(c67_DiscreteParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[1048])[0];
  c67_tmp.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1048])
    [8];
  c67_tmp.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1048])
    [16];
  c67_tmp.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1048])
    [24];
  c67_tmp.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1048])
    [32];
  c67_tmp.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1048])
    [40];
  c67_tmp.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1048])
    [48];
  c67_tmp.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1048])
    [56];
  c67_tmp.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1048])
    [64];
  c67_tmp.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1048])
    [72];
  c67_tmp.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c67_DiscreteParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1048])
    [80];
  c67_i290 = 0;
  for (c67_i291 = 0; c67_i291 < 13; c67_i291++) {
    for (c67_i292 = 0; c67_i292 < 6; c67_i292++) {
      c67_tmp.Output.H0[c67_i292 + c67_i290] = ((real_T *)&((char_T *)
        (c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
        [1136])[0])[c67_i292 + c67_i290];
    }

    c67_i290 += 6;
  }

  c67_i293 = 0;
  for (c67_i294 = 0; c67_i294 < 6; c67_i294++) {
    for (c67_i295 = 0; c67_i295 < 6; c67_i295++) {
      c67_tmp.Output.HAlpha[c67_i295 + c67_i293] = ((real_T *)&((char_T *)
        (c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
        [1136])[624])[c67_i295 + c67_i293];
    }

    c67_i293 += 6;
  }

  for (c67_i296 = 0; c67_i296 < 2; c67_i296++) {
    c67_tmp.Output.ThetaLimits[c67_i296] = ((real_T *)&((char_T *)
      (c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1136])
      [912])[c67_i296];
  }

  c67_tmp.Output.Theta.c0 = *(real_T *)&((char_T *)(c67_ThetaParamsBus *)
    &((char_T *)(c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)
    c67_pData)[1136])[928])[0];
  c67_tmp.Output.Theta.ct = *(real_T *)&((char_T *)(c67_ThetaParamsBus *)
    &((char_T *)(c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)
    c67_pData)[1136])[928])[8];
  for (c67_i297 = 0; c67_i297 < 13; c67_i297++) {
    c67_tmp.Output.Theta.cq[c67_i297] = ((real_T *)&((char_T *)
      (c67_ThetaParamsBus *)&((char_T *)(c67_OutputParamsBus *)&((char_T *)
      (c67_ControlParamsBus *)c67_pData)[1136])[928])[16])[c67_i297];
  }

  c67_tmp.Output.Theta.t0 = *(real_T *)&((char_T *)(c67_ThetaParamsBus *)
    &((char_T *)(c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)
    c67_pData)[1136])[928])[120];
  for (c67_i298 = 0; c67_i298 < 7; c67_i298++) {
    c67_tmp.Output.Theta.cz[c67_i298] = ((real_T *)&((char_T *)
      (c67_ThetaParamsBus *)&((char_T *)(c67_OutputParamsBus *)&((char_T *)
      (c67_ControlParamsBus *)c67_pData)[1136])[928])[128])[c67_i298];
  }

  c67_tmp.Output.SaturateS = *(real_T *)&((char_T *)(c67_OutputParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[1136])[1112];
  for (c67_i299 = 0; c67_i299 < 2; c67_i299++) {
    c67_tmp.Output.SLimits[c67_i299] = ((real_T *)&((char_T *)
      (c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1136])
      [1120])[c67_i299];
  }

  c67_tmp.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1136])
    [1136];
  c67_tmp.Output.UseCorrection = *(real_T *)&((char_T *)(c67_OutputParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[1136])[1144];
  c67_tmp.Output.SMaxCorrection = *(real_T *)&((char_T *)(c67_OutputParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[1136])[1152];
  c67_i300 = 0;
  for (c67_i301 = 0; c67_i301 < 5; c67_i301++) {
    for (c67_i302 = 0; c67_i302 < 6; c67_i302++) {
      c67_tmp.Output.HAlphaCorrection[c67_i302 + c67_i300] = ((real_T *)
        &((char_T *)(c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)
        c67_pData)[1136])[1160])[c67_i302 + c67_i300];
    }

    c67_i300 += 6;
  }

  c67_tmp.Output.Phi.c0 = *(real_T *)&((char_T *)(c67_PhiParamsBus *)&((char_T *)
                                        (c67_OutputParamsBus *)&((char_T *)
    (c67_ControlParamsBus *)c67_pData)[1136])[1400])[0];
  for (c67_i303 = 0; c67_i303 < 13; c67_i303++) {
    c67_tmp.Output.Phi.cq[c67_i303] = ((real_T *)&((char_T *)(c67_PhiParamsBus *)
      &((char_T *)(c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)
      c67_pData)[1136])[1400])[8])[c67_i303];
  }

  for (c67_i304 = 0; c67_i304 < 20; c67_i304++) {
    c67_tmp.Output.PhiAlpha[c67_i304] = ((real_T *)&((char_T *)
      (c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1136])
      [1512])[c67_i304];
  }

  c67_tmp.Output.SaturateR = *(real_T *)&((char_T *)(c67_OutputParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[1136])[1672];
  for (c67_i305 = 0; c67_i305 < 2; c67_i305++) {
    c67_tmp.Output.RLimits[c67_i305] = ((real_T *)&((char_T *)
      (c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[1136])
      [1680])[c67_i305];
  }

  c67_i306 = 0;
  for (c67_i307 = 0; c67_i307 < 5; c67_i307++) {
    for (c67_i308 = 0; c67_i308 < 6; c67_i308++) {
      c67_tmp.Output.HBarAlpha[c67_i308 + c67_i306] = ((real_T *)&((char_T *)
        (c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
        [1136])[1696])[c67_i308 + c67_i306];
    }

    c67_i306 += 6;
  }

  c67_i309 = 0;
  for (c67_i310 = 0; c67_i310 < 2; c67_i310++) {
    for (c67_i311 = 0; c67_i311 < 6; c67_i311++) {
      c67_tmp.Output.HBarLimits[c67_i311 + c67_i309] = ((real_T *)&((char_T *)
        (c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
        [1136])[1936])[c67_i311 + c67_i309];
    }

    c67_i309 += 6;
  }

  c67_i312 = 0;
  for (c67_i313 = 0; c67_i313 < 6; c67_i313++) {
    for (c67_i314 = 0; c67_i314 < 6; c67_i314++) {
      c67_tmp.Output.HAlphaStar[c67_i314 + c67_i312] = ((real_T *)&((char_T *)
        (c67_OutputParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
        [1136])[2032])[c67_i314 + c67_i312];
    }

    c67_i312 += 6;
  }

  c67_tmp.Output.YawLimit = *(real_T *)&((char_T *)(c67_OutputParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[1136])[2320];
  c67_tmp.Output.test = *(real_T *)&((char_T *)(c67_OutputParamsBus *)&((char_T *)
                                      (c67_ControlParamsBus *)c67_pData)[1136])
    [2328];
  for (c67_i315 = 0; c67_i315 < 6; c67_i315++) {
    c67_tmp.Feedback.kp[c67_i315] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [3472])[0])[c67_i315];
  }

  for (c67_i316 = 0; c67_i316 < 6; c67_i316++) {
    c67_tmp.Feedback.kd[c67_i316] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [3472])[48])[c67_i316];
  }

  for (c67_i317 = 0; c67_i317 < 2; c67_i317++) {
    c67_tmp.Feedback.epsilon[c67_i317] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [3472])[96])[c67_i317];
  }

  for (c67_i318 = 0; c67_i318 < 2; c67_i318++) {
    c67_tmp.Feedback.kff_grav[c67_i318] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [3472])[112])[c67_i318];
  }

  c67_tmp.Feedback.delta_grav = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[128];
  for (c67_i319 = 0; c67_i319 < 2; c67_i319++) {
    c67_tmp.Feedback.kff_decoup[c67_i319] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [3472])[136])[c67_i319];
  }

  for (c67_i320 = 0; c67_i320 < 2; c67_i320++) {
    c67_tmp.Feedback.kd_torso[c67_i320] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [3472])[152])[c67_i320];
  }

  c67_tmp.Feedback.kp_2dof = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[168];
  c67_tmp.Feedback.kd_2dof = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[176];
  c67_tmp.Feedback.kpre_2dof = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[184];
  c67_tmp.Feedback.kp_lat = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[192];
  c67_tmp.Feedback.kd_lat = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[200];
  c67_tmp.Feedback.q3d_min_lat = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[208];
  c67_tmp.Feedback.q3d_max_lat = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[216];
  c67_tmp.Feedback.w_torso_lat = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[224];
  for (c67_i321 = 0; c67_i321 < 6; c67_i321++) {
    c67_tmp.Feedback.u_ff[c67_i321] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [3472])[232])[c67_i321];
  }

  c67_tmp.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])
    [280];
  c67_tmp.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])
    [288];
  c67_tmp.Feedback.Use2DOF = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[296];
  c67_tmp.Feedback.UseDSGravComp = *(real_T *)&((char_T *)(c67_FeedbackParamsBus
    *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[304];
  c67_tmp.Feedback.lat_bias = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[312];
  c67_tmp.Feedback.lat_bias2 = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[320];
  c67_tmp.Feedback.linkFeedback = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[328];
  c67_tmp.Feedback.RIO = *(real_T *)&((char_T *)(c67_FeedbackParamsBus *)
    &((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])[336];
  c67_tmp.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])
    [344];
  for (c67_i322 = 0; c67_i322 < 6; c67_i322++) {
    c67_tmp.Feedback.FeedforwardGain[c67_i322] = ((real_T *)&((char_T *)
      (c67_FeedbackParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [3472])[352])[c67_i322];
  }

  c67_tmp.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c67_FeedbackParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)[3472])
    [400];
  c67_tmp.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c67_SaturationParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
    [3880])[0];
  for (c67_i323 = 0; c67_i323 < 2; c67_i323++) {
    c67_tmp.Saturation.QPWeight[c67_i323] = ((real_T *)&((char_T *)
      (c67_SaturationParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
      [3880])[8])[c67_i323];
  }

  c67_tmp.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c67_SaturationParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
    [3880])[24];
  c67_tmp.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c67_SaturationParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
    [3880])[32];
  c67_tmp.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c67_SaturationParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
    [3880])[40];
  c67_tmp.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c67_SaturationParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
    [3880])[48];
  c67_tmp.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c67_SaturationParamsBus *)&((char_T *)(c67_ControlParamsBus *)c67_pData)
    [3880])[56];
  sf_mex_assign(&c67_mxVal, c67_b_sf_marshallOut(chartInstance, &c67_tmp), false);
  return c67_mxVal;
}

static uint8_T c67_h_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_is_active_c67_DDA2D_OSU3Dv2, const char_T
  *c67_identifier)
{
  uint8_T c67_y;
  emlrtMsgIdentifier c67_thisId;
  c67_thisId.fIdentifier = c67_identifier;
  c67_thisId.fParent = NULL;
  c67_y = c67_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c67_b_is_active_c67_DDA2D_OSU3Dv2), &c67_thisId);
  sf_mex_destroy(&c67_b_is_active_c67_DDA2D_OSU3Dv2);
  return c67_y;
}

static uint8_T c67_i_emlrt_marshallIn(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c67_b_u, const emlrtMsgIdentifier *c67_parentId)
{
  uint8_T c67_y;
  uint8_T c67_u0;
  (void)chartInstance;
  sf_mex_import(c67_parentId, sf_mex_dup(c67_b_u), &c67_u0, 1, 3, 0U, 0, 0U, 0);
  c67_y = c67_u0;
  sf_mex_destroy(&c67_b_u);
  return c67_y;
}

static void c67_b_eml_matlab_zgetrf(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c67_A[36], int32_T c67_ipiv[6], int32_T *c67_info)
{
  int32_T c67_i324;
  int32_T c67_j;
  int32_T c67_b_j;
  int32_T c67_a;
  int32_T c67_b_a;
  int32_T c67_jm1;
  int32_T c67_b;
  int32_T c67_b_b;
  int32_T c67_mmj;
  int32_T c67_c_a;
  int32_T c67_d_a;
  int32_T c67_c;
  int32_T c67_c_b;
  int32_T c67_d_b;
  int32_T c67_jj;
  int32_T c67_e_a;
  int32_T c67_f_a;
  int32_T c67_jp1j;
  int32_T c67_g_a;
  int32_T c67_h_a;
  int32_T c67_b_c;
  int32_T c67_i325;
  real_T c67_b_A[36];
  int32_T c67_i_a;
  int32_T c67_j_a;
  int32_T c67_jpiv_offset;
  int32_T c67_k_a;
  int32_T c67_e_b;
  int32_T c67_l_a;
  int32_T c67_f_b;
  int32_T c67_jpiv;
  int32_T c67_m_a;
  int32_T c67_g_b;
  int32_T c67_n_a;
  int32_T c67_h_b;
  int32_T c67_c_c;
  int32_T c67_i_b;
  int32_T c67_j_b;
  int32_T c67_jrow;
  int32_T c67_o_a;
  int32_T c67_k_b;
  int32_T c67_p_a;
  int32_T c67_l_b;
  int32_T c67_jprow;
  int32_T c67_ix0;
  int32_T c67_iy0;
  int32_T c67_b_ix0;
  int32_T c67_b_iy0;
  int32_T c67_c_ix0;
  int32_T c67_c_iy0;
  int32_T c67_ix;
  int32_T c67_iy;
  int32_T c67_k;
  real_T c67_temp;
  int32_T c67_q_a;
  int32_T c67_r_a;
  int32_T c67_b_jp1j;
  int32_T c67_s_a;
  int32_T c67_t_a;
  int32_T c67_d_c;
  int32_T c67_u_a;
  int32_T c67_m_b;
  int32_T c67_v_a;
  int32_T c67_n_b;
  int32_T c67_i326;
  int32_T c67_w_a;
  int32_T c67_o_b;
  int32_T c67_x_a;
  int32_T c67_p_b;
  boolean_T c67_overflow;
  int32_T c67_i;
  int32_T c67_b_i;
  real_T c67_x;
  real_T c67_y;
  real_T c67_b_x;
  real_T c67_b_y;
  real_T c67_z;
  int32_T c67_q_b;
  int32_T c67_r_b;
  int32_T c67_e_c;
  int32_T c67_y_a;
  int32_T c67_ab_a;
  int32_T c67_f_c;
  int32_T c67_bb_a;
  int32_T c67_cb_a;
  int32_T c67_g_c;
  c67_realmin(chartInstance);
  c67_eps(chartInstance);
  for (c67_i324 = 0; c67_i324 < 6; c67_i324++) {
    c67_ipiv[c67_i324] = 1 + c67_i324;
  }

  *c67_info = 0;
  c67_eml_switch_helper(chartInstance);
  for (c67_j = 1; c67_j < 6; c67_j++) {
    c67_b_j = c67_j;
    c67_a = c67_b_j;
    c67_b_a = c67_a - 1;
    c67_jm1 = c67_b_a;
    c67_b = c67_b_j;
    c67_b_b = c67_b;
    c67_mmj = 6 - c67_b_b;
    c67_c_a = c67_jm1;
    c67_d_a = c67_c_a;
    c67_c = c67_d_a * 7;
    c67_c_b = c67_c;
    c67_d_b = c67_c_b + 1;
    c67_jj = c67_d_b;
    c67_e_a = c67_jj;
    c67_f_a = c67_e_a + 1;
    c67_jp1j = c67_f_a;
    c67_g_a = c67_mmj;
    c67_h_a = c67_g_a;
    c67_b_c = c67_h_a;
    for (c67_i325 = 0; c67_i325 < 36; c67_i325++) {
      c67_b_A[c67_i325] = c67_A[c67_i325];
    }

    c67_i_a = c67_eml_ixamax(chartInstance, c67_b_c + 1, c67_b_A, c67_jj);
    c67_j_a = c67_i_a - 1;
    c67_jpiv_offset = c67_j_a;
    c67_k_a = c67_jj;
    c67_e_b = c67_jpiv_offset;
    c67_l_a = c67_k_a;
    c67_f_b = c67_e_b;
    c67_jpiv = c67_l_a + c67_f_b;
    if (c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c67_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if (c67_jpiv_offset != 0) {
        c67_m_a = c67_b_j;
        c67_g_b = c67_jpiv_offset;
        c67_n_a = c67_m_a;
        c67_h_b = c67_g_b;
        c67_c_c = c67_n_a + c67_h_b;
        c67_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c67_b_j), 1, 6, 1, 0) - 1] = c67_c_c;
        c67_i_b = c67_jm1;
        c67_j_b = c67_i_b + 1;
        c67_jrow = c67_j_b;
        c67_o_a = c67_jrow;
        c67_k_b = c67_jpiv_offset;
        c67_p_a = c67_o_a;
        c67_l_b = c67_k_b;
        c67_jprow = c67_p_a + c67_l_b;
        c67_ix0 = c67_jrow;
        c67_iy0 = c67_jprow;
        c67_b_ix0 = c67_ix0;
        c67_b_iy0 = c67_iy0;
        c67_b_eml_switch_helper(chartInstance);
        c67_c_ix0 = c67_b_ix0;
        c67_c_iy0 = c67_b_iy0;
        c67_ix = c67_c_ix0;
        c67_iy = c67_c_iy0;
        c67_eml_switch_helper(chartInstance);
        for (c67_k = 1; c67_k < 7; c67_k++) {
          c67_temp = c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c67_ix), 1, 36, 1, 0) - 1];
          c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c67_ix), 1, 36, 1, 0) - 1] =
            c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c67_iy), 1, 36, 1, 0) - 1];
          c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c67_iy), 1, 36, 1, 0) - 1] = c67_temp;
          c67_q_a = c67_ix + 6;
          c67_ix = c67_q_a;
          c67_r_a = c67_iy + 6;
          c67_iy = c67_r_a;
        }
      }

      c67_b_jp1j = c67_jp1j;
      c67_s_a = c67_mmj;
      c67_t_a = c67_s_a;
      c67_d_c = c67_t_a;
      c67_u_a = c67_jp1j;
      c67_m_b = c67_d_c - 1;
      c67_v_a = c67_u_a;
      c67_n_b = c67_m_b;
      c67_i326 = c67_v_a + c67_n_b;
      c67_w_a = c67_b_jp1j;
      c67_o_b = c67_i326;
      c67_x_a = c67_w_a;
      c67_p_b = c67_o_b;
      if (c67_x_a > c67_p_b) {
        c67_overflow = false;
      } else {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_overflow = (c67_p_b > 2147483646);
      }

      if (c67_overflow) {
        c67_check_forloop_overflow_error(chartInstance, c67_overflow);
      }

      for (c67_i = c67_b_jp1j; c67_i <= c67_i326; c67_i++) {
        c67_b_i = c67_i;
        c67_x = c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_b_i), 1, 36, 1, 0) - 1];
        c67_y = c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c67_jj), 1, 36, 1, 0) - 1];
        c67_b_x = c67_x;
        c67_b_y = c67_y;
        c67_z = c67_b_x / c67_b_y;
        c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c67_b_i), 1, 36, 1, 0) - 1] = c67_z;
      }
    } else {
      *c67_info = c67_b_j;
    }

    c67_q_b = c67_b_j;
    c67_r_b = c67_q_b;
    c67_e_c = 6 - c67_r_b;
    c67_y_a = c67_jj;
    c67_ab_a = c67_y_a;
    c67_f_c = c67_ab_a;
    c67_bb_a = c67_jj;
    c67_cb_a = c67_bb_a;
    c67_g_c = c67_cb_a;
    c67_b_eml_xgeru(chartInstance, c67_mmj, c67_e_c, -1.0, c67_jp1j, c67_f_c + 6,
                    c67_A, c67_g_c + 7);
  }

  if (*c67_info == 0) {
    if (!(c67_A[35] != 0.0)) {
      *c67_info = 6;
    }
  }
}

static void c67_b_eml_xgeru(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c67_m, int32_T c67_n, real_T c67_alpha1, int32_T c67_ix0, int32_T
  c67_iy0, real_T c67_A[36], int32_T c67_ia0)
{
  int32_T c67_b_m;
  int32_T c67_b_n;
  real_T c67_b_alpha1;
  int32_T c67_b_ix0;
  int32_T c67_b_iy0;
  int32_T c67_b_ia0;
  int32_T c67_c_m;
  int32_T c67_c_n;
  real_T c67_c_alpha1;
  int32_T c67_c_ix0;
  int32_T c67_c_iy0;
  int32_T c67_c_ia0;
  int32_T c67_d_m;
  int32_T c67_d_n;
  real_T c67_d_alpha1;
  int32_T c67_d_ix0;
  int32_T c67_d_iy0;
  int32_T c67_d_ia0;
  int32_T c67_e_m;
  int32_T c67_e_n;
  real_T c67_e_alpha1;
  int32_T c67_e_ix0;
  int32_T c67_e_iy0;
  int32_T c67_e_ia0;
  int32_T c67_ixstart;
  int32_T c67_a;
  int32_T c67_jA;
  int32_T c67_jy;
  int32_T c67_f_n;
  int32_T c67_b;
  int32_T c67_b_b;
  boolean_T c67_overflow;
  int32_T c67_j;
  real_T c67_yjy;
  real_T c67_temp;
  int32_T c67_ix;
  int32_T c67_c_b;
  int32_T c67_i327;
  int32_T c67_b_a;
  int32_T c67_d_b;
  int32_T c67_i328;
  int32_T c67_c_a;
  int32_T c67_e_b;
  int32_T c67_d_a;
  int32_T c67_f_b;
  boolean_T c67_b_overflow;
  int32_T c67_ijA;
  int32_T c67_b_ijA;
  int32_T c67_e_a;
  int32_T c67_f_a;
  int32_T c67_g_a;
  c67_b_m = c67_m;
  c67_b_n = c67_n;
  c67_b_alpha1 = c67_alpha1;
  c67_b_ix0 = c67_ix0;
  c67_b_iy0 = c67_iy0;
  c67_b_ia0 = c67_ia0;
  c67_c_m = c67_b_m;
  c67_c_n = c67_b_n;
  c67_c_alpha1 = c67_b_alpha1;
  c67_c_ix0 = c67_b_ix0;
  c67_c_iy0 = c67_b_iy0;
  c67_c_ia0 = c67_b_ia0;
  c67_d_m = c67_c_m;
  c67_d_n = c67_c_n;
  c67_d_alpha1 = c67_c_alpha1;
  c67_d_ix0 = c67_c_ix0;
  c67_d_iy0 = c67_c_iy0;
  c67_d_ia0 = c67_c_ia0;
  c67_e_m = c67_d_m;
  c67_e_n = c67_d_n;
  c67_e_alpha1 = c67_d_alpha1;
  c67_e_ix0 = c67_d_ix0;
  c67_e_iy0 = c67_d_iy0;
  c67_e_ia0 = c67_d_ia0;
  if (c67_e_alpha1 == 0.0) {
  } else {
    c67_ixstart = c67_e_ix0;
    c67_a = c67_e_ia0 - 1;
    c67_jA = c67_a;
    c67_jy = c67_e_iy0;
    c67_f_n = c67_e_n;
    c67_b = c67_f_n;
    c67_b_b = c67_b;
    if (1 > c67_b_b) {
      c67_overflow = false;
    } else {
      c67_eml_switch_helper(chartInstance);
      c67_eml_switch_helper(chartInstance);
      c67_overflow = (c67_b_b > 2147483646);
    }

    if (c67_overflow) {
      c67_check_forloop_overflow_error(chartInstance, c67_overflow);
    }

    for (c67_j = 1; c67_j <= c67_f_n; c67_j++) {
      c67_yjy = c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c67_jy), 1, 36, 1, 0) - 1];
      if (c67_yjy != 0.0) {
        c67_temp = c67_yjy * c67_e_alpha1;
        c67_ix = c67_ixstart;
        c67_c_b = c67_jA + 1;
        c67_i327 = c67_c_b;
        c67_b_a = c67_e_m;
        c67_d_b = c67_jA;
        c67_i328 = c67_b_a + c67_d_b;
        c67_c_a = c67_i327;
        c67_e_b = c67_i328;
        c67_d_a = c67_c_a;
        c67_f_b = c67_e_b;
        if (c67_d_a > c67_f_b) {
          c67_b_overflow = false;
        } else {
          c67_eml_switch_helper(chartInstance);
          c67_eml_switch_helper(chartInstance);
          c67_b_overflow = (c67_f_b > 2147483646);
        }

        if (c67_b_overflow) {
          c67_check_forloop_overflow_error(chartInstance, c67_b_overflow);
        }

        for (c67_ijA = c67_i327; c67_ijA <= c67_i328; c67_ijA++) {
          c67_b_ijA = c67_ijA;
          c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c67_b_ijA), 1, 36, 1, 0) - 1] =
            c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c67_b_ijA), 1, 36, 1, 0) - 1] +
            c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c67_ix), 1, 36, 1, 0) - 1] * c67_temp;
          c67_e_a = c67_ix + 1;
          c67_ix = c67_e_a;
        }
      }

      c67_f_a = c67_jy + 6;
      c67_jy = c67_f_a;
      c67_g_a = c67_jA + 6;
      c67_jA = c67_g_a;
    }
  }
}

static void c67_c_eml_xtrsm(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c67_A[36], real_T c67_B[6])
{
  int32_T c67_k;
  int32_T c67_b_k;
  int32_T c67_kAcol;
  int32_T c67_i329;
  int32_T c67_a;
  int32_T c67_b_a;
  boolean_T c67_overflow;
  int32_T c67_i;
  int32_T c67_b_i;
  c67_below_threshold(chartInstance);
  c67_scalarEg(chartInstance);
  c67_eml_switch_helper(chartInstance);
  for (c67_k = 1; c67_k < 7; c67_k++) {
    c67_b_k = c67_k;
    c67_kAcol = 6 * (c67_b_k - 1);
    if (c67_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c67_b_k), 1, 6, 1, 0) - 1] != 0.0) {
      c67_i329 = c67_b_k + 1;
      c67_a = c67_i329;
      c67_b_a = c67_a;
      if (c67_b_a > 6) {
        c67_overflow = false;
      } else {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_overflow = false;
      }

      if (c67_overflow) {
        c67_check_forloop_overflow_error(chartInstance, c67_overflow);
      }

      for (c67_i = c67_i329; c67_i < 7; c67_i++) {
        c67_b_i = c67_i;
        c67_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c67_b_i), 1, 6, 1, 0) - 1] = c67_B[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c67_b_i), 1, 6, 1, 0) - 1]
          - c67_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c67_b_k), 1, 6, 1, 0) - 1] * c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c67_b_i + c67_kAcol)), 1,
           36, 1, 0) - 1];
      }
    }
  }
}

static void c67_d_eml_xtrsm(SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c67_A[36], real_T c67_B[6])
{
  int32_T c67_k;
  int32_T c67_b_k;
  int32_T c67_kAcol;
  int32_T c67_i330;
  int32_T c67_b;
  int32_T c67_b_b;
  boolean_T c67_overflow;
  int32_T c67_i;
  int32_T c67_b_i;
  c67_below_threshold(chartInstance);
  c67_scalarEg(chartInstance);
  c67_eml_switch_helper(chartInstance);
  for (c67_k = 6; c67_k > 0; c67_k--) {
    c67_b_k = c67_k;
    c67_kAcol = 6 * (c67_b_k - 1);
    if (c67_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c67_b_k), 1, 6, 1, 0) - 1] != 0.0) {
      c67_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c67_b_k), 1, 6, 1, 0) - 1] = c67_rdivide(chartInstance,
        c67_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c67_b_k), 1, 6, 1, 0) - 1], c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c67_b_k + c67_kAcol)), 1, 36, 1,
        0) - 1]);
      c67_i330 = c67_b_k - 1;
      c67_b = c67_i330;
      c67_b_b = c67_b;
      if (1 > c67_b_b) {
        c67_overflow = false;
      } else {
        c67_eml_switch_helper(chartInstance);
        c67_eml_switch_helper(chartInstance);
        c67_overflow = (c67_b_b > 2147483646);
      }

      if (c67_overflow) {
        c67_check_forloop_overflow_error(chartInstance, c67_overflow);
      }

      for (c67_i = 1; c67_i <= c67_i330; c67_i++) {
        c67_b_i = c67_i;
        c67_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c67_b_i), 1, 6, 1, 0) - 1] = c67_B[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c67_b_i), 1, 6, 1, 0) - 1]
          - c67_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c67_b_k), 1, 6, 1, 0) - 1] * c67_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c67_b_i + c67_kAcol)), 1,
           36, 1, 0) - 1];
      }
    }
  }
}

static void init_dsm_address_info(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc67_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c67_u = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c67_s = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c67_u_sat = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c67_sat = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c67_ControlState = (c67_ControlStateBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c67_ControlParams = (c67_ControlParamsBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 4);
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

void sf_c67_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1647421758U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(369279835U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(17822709U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2129408503U);
}

mxArray* sf_c67_DDA2D_OSU3Dv2_get_post_codegen_info(void);
mxArray *sf_c67_DDA2D_OSU3Dv2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("o1hm4vkhKUV3wzhDDCFrxF");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(13));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,4,"type",mxType);
    }

    mxSetField(mxData,4,"complexity",mxCreateDoubleScalar(0));
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
    mxArray* mxPostCodegenInfo = sf_c67_DDA2D_OSU3Dv2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c67_DDA2D_OSU3Dv2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c67_DDA2D_OSU3Dv2_jit_fallback_info(void)
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

mxArray *sf_c67_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c67_DDA2D_OSU3Dv2_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c67_DDA2D_OSU3Dv2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"u_sat\",},{M[8],M[0],T\"is_active_c67_DDA2D_OSU3Dv2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c67_DDA2D_OSU3Dv2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DDA2D_OSU3Dv2MachineNumber_,
           67,
           1,
           1,
           0,
           6,
           0,
           0,
           0,
           0,
           10,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,1,1,0,"s");
          _SFD_SET_DATA_PROPS(2,2,0,1,"u_sat");
          _SFD_SET_DATA_PROPS(3,1,1,0,"sat");
          _SFD_SET_DATA_PROPS(4,1,1,0,"ControlState");
          _SFD_SET_DATA_PROPS(5,1,1,0,"ControlParams");
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
        _SFD_CV_INIT_EML(0,1,1,6,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,1951);
        _SFD_CV_INIT_EML_IF(0,1,0,104,149,-1,707);
        _SFD_CV_INIT_EML_IF(0,1,1,158,188,253,336);
        _SFD_CV_INIT_EML_IF(0,1,2,717,797,-1,1947);
        _SFD_CV_INIT_EML_IF(0,1,3,1079,1109,-1,1159);
        _SFD_CV_INIT_EML_IF(0,1,4,1335,1383,1466,1848);
        _SFD_CV_INIT_EML_IF(0,1,5,1466,1518,1760,1848);

        {
          static int condStart[] = { 721, 756 };

          static int condEnd[] = { 751, 796 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,721,796,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,162,187,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,721,751,-1,5);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,1083,1108,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,3,1339,1382,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,4,1474,1517,-1,2);
        _SFD_CV_INIT_SCRIPT(0,1,9,0,0,0,0,0,27,9);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"LA_LS_Revised_Saturation",0,-1,3133);
        _SFD_CV_INIT_SCRIPT_IF(0,0,1867,1935,-1,1997);
        _SFD_CV_INIT_SCRIPT_IF(0,1,2008,2076,-1,2138);
        _SFD_CV_INIT_SCRIPT_IF(0,2,2149,2217,-1,2279);
        _SFD_CV_INIT_SCRIPT_IF(0,3,2290,2358,-1,2420);
        _SFD_CV_INIT_SCRIPT_IF(0,4,2431,2499,-1,2561);
        _SFD_CV_INIT_SCRIPT_IF(0,5,2572,2640,-1,2702);
        _SFD_CV_INIT_SCRIPT_IF(0,6,2713,2781,-1,2843);
        _SFD_CV_INIT_SCRIPT_IF(0,7,2854,2922,-1,2984);
        _SFD_CV_INIT_SCRIPT_IF(0,8,2995,3063,-1,3125);

        {
          static int condStart[] = { 1871, 1895, 1919 };

          static int condEnd[] = { 1889, 1913, 1934 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,0,1870,1935,3,0,&(condStart[0]),&(condEnd[0]),
            5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2012, 2036, 2060 };

          static int condEnd[] = { 2030, 2054, 2075 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,1,2011,2076,3,3,&(condStart[0]),&(condEnd[0]),
            5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2153, 2177, 2201 };

          static int condEnd[] = { 2171, 2195, 2216 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,2,2152,2217,3,6,&(condStart[0]),&(condEnd[0]),
            5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2294, 2318, 2342 };

          static int condEnd[] = { 2312, 2336, 2357 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,3,2293,2358,3,9,&(condStart[0]),&(condEnd[0]),
            5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2435, 2459, 2483 };

          static int condEnd[] = { 2453, 2477, 2498 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,4,2434,2499,3,12,&(condStart[0]),&(condEnd
            [0]),5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2576, 2600, 2624 };

          static int condEnd[] = { 2594, 2618, 2639 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,5,2575,2640,3,15,&(condStart[0]),&(condEnd
            [0]),5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2717, 2741, 2765 };

          static int condEnd[] = { 2735, 2759, 2780 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,6,2716,2781,3,18,&(condStart[0]),&(condEnd
            [0]),5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2858, 2882, 2906 };

          static int condEnd[] = { 2876, 2900, 2921 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,7,2857,2922,3,21,&(condStart[0]),&(condEnd
            [0]),5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 2999, 3023, 3047 };

          static int condEnd[] = { 3017, 3041, 3062 };

          static int pfixExpr[] = { 0, 1, -3, 2, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,8,2998,3063,3,24,&(condStart[0]),&(condEnd
            [0]),5,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,0,1871,1889,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,1,1895,1913,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,2,1919,1934,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,3,2012,2030,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,4,2036,2054,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,5,2060,2075,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,6,2153,2171,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,7,2177,2195,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,8,2201,2216,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,9,2294,2312,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,10,2318,2336,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,11,2342,2357,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,12,2435,2453,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,13,2459,2477,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,14,2483,2498,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,15,2576,2594,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,16,2600,2618,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,17,2624,2639,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,18,2717,2735,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,19,2741,2759,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,20,2765,2780,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,21,2858,2876,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,22,2882,2900,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,23,2906,2921,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,24,2999,3017,-1,3);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,25,3023,3041,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,26,3047,3062,-1,5);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"LA_LS_Revised_Saturation_Case_1",0,-1,543);
        _SFD_CV_INIT_SCRIPT(2,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"LA_LS_Revised_Saturation_Case_2",0,-1,499);
        _SFD_CV_INIT_SCRIPT(3,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"LA_LS_Revised_Saturation_Case_3",0,-1,500);
        _SFD_CV_INIT_SCRIPT(4,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(4,0,"LA_LS_Revised_Saturation_Case_4",0,-1,500);
        _SFD_CV_INIT_SCRIPT(5,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(5,0,"LA_LS_Revised_Saturation_Case_5",0,-1,499);
        _SFD_CV_INIT_SCRIPT(6,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(6,0,"LA_LS_Revised_Saturation_Case_6",0,-1,535);
        _SFD_CV_INIT_SCRIPT(7,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(7,0,"LA_LS_Revised_Saturation_Case_7",0,-1,541);
        _SFD_CV_INIT_SCRIPT(8,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(8,0,"LA_LS_Revised_Saturation_Case_8",0,-1,541);
        _SFD_CV_INIT_SCRIPT(9,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(9,0,"LA_LS_Revised_Saturation_Case_9",0,-1,547);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c67_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c67_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c67_sf_marshallOut,(MexInFcnForType)
            c67_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c67_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c67_ControlState_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c67_ControlParams_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c67_u);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c67_s);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c67_u_sat);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c67_sat);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c67_ControlState);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c67_ControlParams);
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
  return "jMXLkjmTKbjAEJqPdBIEM";
}

static void sf_opaque_initialize_c67_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc67_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c67_DDA2D_OSU3Dv2((SFc67_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
  initialize_c67_DDA2D_OSU3Dv2((SFc67_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c67_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  enable_c67_DDA2D_OSU3Dv2((SFc67_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c67_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  disable_c67_DDA2D_OSU3Dv2((SFc67_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c67_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  sf_gateway_c67_DDA2D_OSU3Dv2((SFc67_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c67_DDA2D_OSU3Dv2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c67_DDA2D_OSU3Dv2((SFc67_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c67_DDA2D_OSU3Dv2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c67_DDA2D_OSU3Dv2((SFc67_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c67_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc67_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DDA2D_OSU3Dv2_optimization_info();
    }

    finalize_c67_DDA2D_OSU3Dv2((SFc67_DDA2D_OSU3Dv2InstanceStruct*)
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
  initSimStructsc67_DDA2D_OSU3Dv2((SFc67_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c67_DDA2D_OSU3Dv2(SimStruct *S)
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
    initialize_params_c67_DDA2D_OSU3Dv2((SFc67_DDA2D_OSU3Dv2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c67_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DDA2D_OSU3Dv2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      67);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,67,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,67,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,67);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,67,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,67,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,67);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3866757823U));
  ssSetChecksum1(S,(3408203161U));
  ssSetChecksum2(S,(2411914802U));
  ssSetChecksum3(S,(940190104U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c67_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c67_DDA2D_OSU3Dv2(SimStruct *S)
{
  SFc67_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc67_DDA2D_OSU3Dv2InstanceStruct *)utMalloc(sizeof
    (SFc67_DDA2D_OSU3Dv2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc67_DDA2D_OSU3Dv2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c67_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c67_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c67_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c67_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c67_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c67_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c67_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c67_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c67_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlStart = mdlStart_c67_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c67_DDA2D_OSU3Dv2;
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

void c67_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c67_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c67_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c67_DDA2D_OSU3Dv2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c67_DDA2D_OSU3Dv2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
