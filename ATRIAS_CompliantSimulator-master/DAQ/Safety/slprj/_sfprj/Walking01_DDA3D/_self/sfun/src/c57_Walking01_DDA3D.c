/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_DDA3D_sfun.h"
#include "c57_Walking01_DDA3D.h"
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
static const char * c57_debug_family_names[19] = { "weight", "u_LA_R", "u_LS_R",
  "u_LA_L", "u_LS_L", "uR", "uL", "T0", "u0", "deltaS", "KASaturationLim",
  "nargin", "nargout", "u", "s", "sat", "ControlState", "ControlParams", "u_sat"
};

static const char * c57_b_debug_family_names[7] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u_opt", "L_opt" };

static const char * c57_c_debug_family_names[8] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_min", "u_opt", "L_opt" };

static const char * c57_d_debug_family_names[8] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_max", "u_opt", "L_opt" };

static const char * c57_e_debug_family_names[8] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u2_min", "u_opt", "L_opt" };

static const char * c57_f_debug_family_names[8] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u2_max", "u_opt", "L_opt" };

static const char * c57_g_debug_family_names[9] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_min", "u2_min", "u_opt", "L_opt" };

static const char * c57_h_debug_family_names[9] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_min", "u2_max", "u_opt", "L_opt" };

static const char * c57_i_debug_family_names[9] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_max", "u2_min", "u_opt", "L_opt" };

static const char * c57_j_debug_family_names[9] = { "nargin", "nargout", "u_LS",
  "u_LA", "w", "u1_max", "u2_max", "u_opt", "L_opt" };

static const char * c57_k_debug_family_names[32] = { "u_opt_1", "L_opt_1",
  "u_opt_2", "L_opt_2", "u_opt_3", "L_opt_3", "u_opt_4", "L_opt_4", "u_opt_5",
  "L_opt_5", "u_opt_6", "L_opt_6", "u_opt_7", "L_opt_7", "u_opt_8", "L_opt_8",
  "u_opt_9", "L_opt_9", "LB", "UB", "L_opt", "case_n", "nargin", "nargout",
  "u_LS", "u_LA", "w", "u1_min", "u1_max", "u2_min", "u2_max", "u_opt" };

/* Function Declarations */
static void initialize_c57_Walking01_DDA3D(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initialize_params_c57_Walking01_DDA3D
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance);
static void enable_c57_Walking01_DDA3D(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void disable_c57_Walking01_DDA3D(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c57_update_debugger_state_c57_Walking01_DDA3D
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c57_Walking01_DDA3D
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance);
static void set_sim_state_c57_Walking01_DDA3D
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c57_st);
static void finalize_c57_Walking01_DDA3D(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void sf_gateway_c57_Walking01_DDA3D(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void mdl_start_c57_Walking01_DDA3D(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c57_chartstep_c57_Walking01_DDA3D
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance);
static void initSimStructsc57_Walking01_DDA3D
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance);
static void c57_LA_LS_Revised_Saturation(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, real_T c57_u_LS, real_T c57_u_LA, real_T c57_w, real_T
  c57_u1_min, real_T c57_u1_max, real_T c57_u2_min, real_T c57_u2_max, real_T
  c57_u_opt[2]);
static void c57_LA_LS_Revised_Saturation_Case_1
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u_opt[2], real_T c57_L_opt[4]);
static void c57_LA_LS_Revised_Saturation_Case_2
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u1_min, real_T c57_u_opt[2], real_T
   c57_L_opt[4]);
static void c57_LA_LS_Revised_Saturation_Case_3
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u1_max, real_T c57_u_opt[2], real_T
   c57_L_opt[4]);
static void c57_LA_LS_Revised_Saturation_Case_4
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u2_min, real_T c57_u_opt[2], real_T
   c57_L_opt[4]);
static void c57_LA_LS_Revised_Saturation_Case_5
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u2_max, real_T c57_u_opt[2], real_T
   c57_L_opt[4]);
static void c57_LA_LS_Revised_Saturation_Case_6
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u1_min, real_T c57_u2_min, real_T
   c57_u_opt[2], real_T c57_L_opt[4]);
static void c57_LA_LS_Revised_Saturation_Case_7
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u1_min, real_T c57_u2_max, real_T
   c57_u_opt[2], real_T c57_L_opt[4]);
static void c57_LA_LS_Revised_Saturation_Case_8
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u1_max, real_T c57_u2_min, real_T
   c57_u_opt[2], real_T c57_L_opt[4]);
static void c57_LA_LS_Revised_Saturation_Case_9
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u1_max, real_T c57_u2_max, real_T
   c57_u_opt[2], real_T c57_L_opt[4]);
static void init_script_number_translation(uint32_T c57_machineNumber, uint32_T
  c57_chartNumber, uint32_T c57_instanceNumber);
static const mxArray *c57_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData);
static void c57_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u_sat, const char_T *c57_identifier,
  real_T c57_y[6]);
static void c57_b_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId,
  real_T c57_y[6]);
static void c57_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData);
static const mxArray *c57_b_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData);
static const mxArray *c57_c_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData);
static const mxArray *c57_d_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData);
static const mxArray *c57_e_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData);
static real_T c57_c_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId);
static void c57_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData);
static const mxArray *c57_f_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData);
static void c57_d_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId,
  real_T c57_y[36]);
static void c57_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData);
static void c57_e_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId,
  real_T c57_y[2]);
static void c57_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData);
static const mxArray *c57_g_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData);
static void c57_f_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId,
  real_T c57_y[4]);
static void c57_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData);
static void c57_info_helper(const mxArray **c57_info);
static const mxArray *c57_emlrt_marshallOut(const char * c57_b_u);
static const mxArray *c57_b_emlrt_marshallOut(const uint32_T c57_b_u);
static void c57_b_info_helper(const mxArray **c57_info);
static void c57_c_info_helper(const mxArray **c57_info);
static void c57_eml_scalar_eg(SFc57_Walking01_DDA3DInstanceStruct *chartInstance);
static void c57_threshold(SFc57_Walking01_DDA3DInstanceStruct *chartInstance);
static real_T c57_rdivide(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c57_x, real_T c57_y);
static void c57_eml_switch_helper(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c57_check_forloop_overflow_error(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, boolean_T c57_overflow);
static void c57_b_eml_scalar_eg(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c57_c_eml_scalar_eg(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);
static real_T c57_eml_xdotu(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c57_x[2], real_T c57_y[2]);
static void c57_realmin(SFc57_Walking01_DDA3DInstanceStruct *chartInstance);
static void c57_eps(SFc57_Walking01_DDA3DInstanceStruct *chartInstance);
static void c57_eml_matlab_zgetrf(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, real_T c57_A[36], real_T c57_b_A[36], int32_T c57_ipiv[6],
  int32_T *c57_info);
static int32_T c57_eml_ixamax(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  int32_T c57_n, real_T c57_x[36], int32_T c57_ix0);
static void c57_b_eml_switch_helper(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c57_eml_xgeru(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  int32_T c57_m, int32_T c57_n, real_T c57_alpha1, int32_T c57_ix0, int32_T
  c57_iy0, real_T c57_A[36], int32_T c57_ia0, real_T c57_b_A[36]);
static void c57_eml_warning(SFc57_Walking01_DDA3DInstanceStruct *chartInstance);
static void c57_eml_xtrsm(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c57_A[36], real_T c57_B[6], real_T c57_b_B[6]);
static void c57_below_threshold(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c57_c_eml_switch_helper(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c57_scalarEg(SFc57_Walking01_DDA3DInstanceStruct *chartInstance);
static void c57_b_eml_xtrsm(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c57_A[36], real_T c57_B[6], real_T c57_b_B[6]);
static const mxArray *c57_h_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData);
static int32_T c57_g_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId);
static void c57_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData);
static const mxArray *c57_ControlState_bus_io(void *chartInstanceVoid, void
  *c57_pData);
static const mxArray *c57_ControlParams_bus_io(void *chartInstanceVoid, void
  *c57_pData);
static uint8_T c57_h_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_is_active_c57_Walking01_DDA3D, const
  char_T *c57_identifier);
static uint8_T c57_i_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId);
static void c57_b_eml_matlab_zgetrf(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, real_T c57_A[36], int32_T c57_ipiv[6], int32_T *c57_info);
static void c57_b_eml_xgeru(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  int32_T c57_m, int32_T c57_n, real_T c57_alpha1, int32_T c57_ix0, int32_T
  c57_iy0, real_T c57_A[36], int32_T c57_ia0);
static void c57_c_eml_xtrsm(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c57_A[36], real_T c57_B[6]);
static void c57_d_eml_xtrsm(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c57_A[36], real_T c57_B[6]);
static void init_dsm_address_info(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c57_Walking01_DDA3D(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c57_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c57_is_active_c57_Walking01_DDA3D = 0U;
}

static void initialize_params_c57_Walking01_DDA3D
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c57_Walking01_DDA3D(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c57_Walking01_DDA3D(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c57_update_debugger_state_c57_Walking01_DDA3D
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c57_Walking01_DDA3D
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance)
{
  const mxArray *c57_st;
  const mxArray *c57_y = NULL;
  int32_T c57_i0;
  real_T c57_b_u[6];
  const mxArray *c57_b_y = NULL;
  uint8_T c57_hoistedGlobal;
  uint8_T c57_c_u;
  const mxArray *c57_c_y = NULL;
  c57_st = NULL;
  c57_st = NULL;
  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_createcellmatrix(2, 1), false);
  for (c57_i0 = 0; c57_i0 < 6; c57_i0++) {
    c57_b_u[c57_i0] = (*chartInstance->c57_u_sat)[c57_i0];
  }

  c57_b_y = NULL;
  sf_mex_assign(&c57_b_y, sf_mex_create("y", c57_b_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_setcell(c57_y, 0, c57_b_y);
  c57_hoistedGlobal = chartInstance->c57_is_active_c57_Walking01_DDA3D;
  c57_c_u = c57_hoistedGlobal;
  c57_c_y = NULL;
  sf_mex_assign(&c57_c_y, sf_mex_create("y", &c57_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c57_y, 1, c57_c_y);
  sf_mex_assign(&c57_st, c57_y, false);
  return c57_st;
}

static void set_sim_state_c57_Walking01_DDA3D
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c57_st)
{
  const mxArray *c57_b_u;
  real_T c57_dv0[6];
  int32_T c57_i1;
  chartInstance->c57_doneDoubleBufferReInit = true;
  c57_b_u = sf_mex_dup(c57_st);
  c57_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c57_b_u, 0)),
                       "u_sat", c57_dv0);
  for (c57_i1 = 0; c57_i1 < 6; c57_i1++) {
    (*chartInstance->c57_u_sat)[c57_i1] = c57_dv0[c57_i1];
  }

  chartInstance->c57_is_active_c57_Walking01_DDA3D = c57_h_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c57_b_u, 1)),
     "is_active_c57_Walking01_DDA3D");
  sf_mex_destroy(&c57_b_u);
  c57_update_debugger_state_c57_Walking01_DDA3D(chartInstance);
  sf_mex_destroy(&c57_st);
}

static void finalize_c57_Walking01_DDA3D(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c57_Walking01_DDA3D(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  int32_T c57_i2;
  int32_T c57_i3;
  int32_T c57_i4;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 26U, chartInstance->c57_sfEvent);
  for (c57_i2 = 0; c57_i2 < 6; c57_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c57_u)[c57_i2], 0U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c57_s, 1U);
  chartInstance->c57_sfEvent = CALL_EVENT;
  c57_chartstep_c57_Walking01_DDA3D(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_DDA3DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c57_i3 = 0; c57_i3 < 6; c57_i3++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c57_u_sat)[c57_i3], 2U);
  }

  for (c57_i4 = 0; c57_i4 < 2; c57_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c57_sat)[c57_i4], 3U);
  }
}

static void mdl_start_c57_Walking01_DDA3D(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c57_chartstep_c57_Walking01_DDA3D
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance)
{
  real_T c57_hoistedGlobal;
  int32_T c57_i5;
  real_T c57_b_u[6];
  real_T c57_b_s;
  int32_T c57_i6;
  real_T c57_b_sat[2];
  c57_ControlStateBus c57_b_ControlState;
  c57_ControlParamsBus c57_b_ControlParams;
  int32_T c57_i7;
  int32_T c57_i8;
  int32_T c57_i9;
  int32_T c57_i10;
  int32_T c57_i11;
  int32_T c57_i12;
  int32_T c57_i13;
  int32_T c57_i14;
  int32_T c57_i15;
  int32_T c57_i16;
  int32_T c57_i17;
  int32_T c57_i18;
  int32_T c57_i19;
  int32_T c57_i20;
  int32_T c57_i21;
  int32_T c57_i22;
  int32_T c57_i23;
  int32_T c57_i24;
  int32_T c57_i25;
  int32_T c57_i26;
  int32_T c57_i27;
  int32_T c57_i28;
  int32_T c57_i29;
  int32_T c57_i30;
  int32_T c57_i31;
  int32_T c57_i32;
  int32_T c57_i33;
  int32_T c57_i34;
  int32_T c57_i35;
  int32_T c57_i36;
  int32_T c57_i37;
  int32_T c57_i38;
  int32_T c57_i39;
  int32_T c57_i40;
  int32_T c57_i41;
  int32_T c57_i42;
  int32_T c57_i43;
  int32_T c57_i44;
  int32_T c57_i45;
  int32_T c57_i46;
  int32_T c57_i47;
  int32_T c57_i48;
  int32_T c57_i49;
  int32_T c57_i50;
  int32_T c57_i51;
  int32_T c57_i52;
  int32_T c57_i53;
  uint32_T c57_debug_family_var_map[19];
  real_T c57_weight[2];
  real_T c57_u_LA_R;
  real_T c57_u_LS_R;
  real_T c57_u_LA_L;
  real_T c57_u_LS_L;
  real_T c57_uR[2];
  real_T c57_uL[2];
  real_T c57_T0[36];
  real_T c57_u0[6];
  real_T c57_deltaS;
  real_T c57_KASaturationLim;
  real_T c57_nargin = 5.0;
  real_T c57_nargout = 1.0;
  real_T c57_b_u_sat[6];
  int32_T c57_i54;
  int32_T c57_i55;
  int32_T c57_i56;
  real_T c57_b[2];
  int32_T c57_i57;
  int32_T c57_i58;
  int32_T c57_i59;
  real_T c57_C[2];
  int32_T c57_i60;
  int32_T c57_i61;
  int32_T c57_i62;
  int32_T c57_i63;
  int32_T c57_i64;
  int32_T c57_i65;
  static real_T c57_a[4] = { 0.0, 1.0, 1.0, 0.0 };

  real_T c57_A;
  real_T c57_b_A;
  real_T c57_dv1[2];
  int32_T c57_i66;
  real_T c57_dv2[2];
  int32_T c57_i67;
  int32_T c57_i68;
  int32_T c57_i69;
  int32_T c57_i70;
  static real_T c57_dv3[36] = { 0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.5, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0,
    0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c57_i71;
  int32_T c57_i72;
  static int32_T c57_iv0[6] = { 1, 0, 3, 2, 5, 4 };

  real_T c57_b_T0[36];
  int32_T c57_i73;
  int32_T c57_i74;
  int32_T c57_i75;
  int32_T c57_i76;
  real_T c57_b_a[36];
  int32_T c57_i77;
  real_T c57_b_b[6];
  int32_T c57_i78;
  int32_T c57_i79;
  int32_T c57_i80;
  real_T c57_b_C[6];
  int32_T c57_i81;
  int32_T c57_i82;
  int32_T c57_i83;
  int32_T c57_i84;
  int32_T c57_i85;
  int32_T c57_i86;
  real_T c57_varargin_1;
  real_T c57_varargin_2;
  real_T c57_x;
  real_T c57_b_x;
  real_T c57_xk;
  real_T c57_c_x;
  real_T c57_c_a[2];
  int32_T c57_i87;
  real_T c57_d_a[2];
  int32_T c57_i88;
  real_T c57_c_b[2];
  real_T c57_y;
  real_T c57_c_A;
  real_T c57_B;
  real_T c57_b_varargin_1;
  real_T c57_b_varargin_2;
  real_T c57_c_varargin_2;
  real_T c57_varargin_3;
  real_T c57_d_x;
  real_T c57_b_y;
  real_T c57_e_x;
  real_T c57_c_y;
  real_T c57_b_xk;
  real_T c57_yk;
  real_T c57_f_x;
  real_T c57_d_y;
  real_T c57_minval;
  real_T c57_c_varargin_1;
  real_T c57_d_varargin_2;
  real_T c57_e_varargin_2;
  real_T c57_b_varargin_3;
  real_T c57_g_x;
  real_T c57_e_y;
  real_T c57_h_x;
  real_T c57_f_y;
  real_T c57_c_xk;
  real_T c57_b_yk;
  real_T c57_i_x;
  real_T c57_g_y;
  real_T c57_maxval;
  int32_T c57_i89;
  int32_T c57_i90;
  int32_T c57_info;
  int32_T c57_ipiv[6];
  int32_T c57_b_info;
  int32_T c57_c_info;
  int32_T c57_d_info;
  int32_T c57_i91;
  int32_T c57_xi;
  int32_T c57_b_xi;
  int32_T c57_ip;
  real_T c57_temp;
  int32_T c57_i92;
  int32_T c57_i93;
  real_T c57_e_a[36];
  int32_T c57_i94;
  int32_T c57_i95;
  int32_T c57_i96;
  real_T c57_f_a[36];
  int32_T c57_i97;
  int32_T c57_i98;
  boolean_T guard1 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 26U, chartInstance->c57_sfEvent);
  c57_hoistedGlobal = *chartInstance->c57_s;
  for (c57_i5 = 0; c57_i5 < 6; c57_i5++) {
    c57_b_u[c57_i5] = (*chartInstance->c57_u)[c57_i5];
  }

  c57_b_s = c57_hoistedGlobal;
  for (c57_i6 = 0; c57_i6 < 2; c57_i6++) {
    c57_b_sat[c57_i6] = (*chartInstance->c57_sat)[c57_i6];
  }

  c57_b_ControlState.ControllerMode = *(real_T *)&((char_T *)
    chartInstance->c57_ControlState)[0];
  c57_b_ControlState.SupportState = *(real_T *)&((char_T *)
    chartInstance->c57_ControlState)[8];
  c57_b_ControlState.StanceLeg = *(real_T *)&((char_T *)
    chartInstance->c57_ControlState)[16];
  c57_b_ControlState.InDoubleSupport = *(real_T *)&((char_T *)
    chartInstance->c57_ControlState)[24];
  c57_b_ControlState.RollPhase = *(real_T *)&((char_T *)
    chartInstance->c57_ControlState)[32];
  c57_b_ControlState.StepCount = *(real_T *)&((char_T *)
    chartInstance->c57_ControlState)[40];
  c57_b_ControlState.Error = *(real_T *)&((char_T *)
    chartInstance->c57_ControlState)[48];
  c57_b_ControlParams.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [0];
  c57_b_ControlParams.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [8];
  c57_b_ControlParams.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [16];
  c57_b_ControlParams.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [24];
  c57_b_ControlParams.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)
    &((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c57_ControlParams)[0])[32];
  c57_b_ControlParams.Supervisory.ImpactThresholdKASpringRel = *(real_T *)
    &((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c57_ControlParams)[0])[40];
  c57_b_ControlParams.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [48];
  c57_b_ControlParams.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [56];
  c57_b_ControlParams.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [64];
  c57_b_ControlParams.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [72];
  c57_b_ControlParams.Supervisory.TransitionThresholdTorsoVel = *(real_T *)
    &((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c57_ControlParams)[0])[80];
  for (c57_i7 = 0; c57_i7 < 2; c57_i7++) {
    c57_b_ControlParams.Supervisory.KAInjection[c57_i7] = ((real_T *)&((char_T *)
      (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
      [0])[88])[c57_i7];
  }

  c57_b_ControlParams.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T
    *)(c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
    [0])[104];
  c57_b_ControlParams.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [112];
  for (c57_i8 = 0; c57_i8 < 6; c57_i8++) {
    c57_b_ControlParams.Supervisory.VBLAParams[c57_i8] = ((real_T *)&((char_T *)
      (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
      [0])[120])[c57_i8];
  }

  for (c57_i9 = 0; c57_i9 < 13; c57_i9++) {
    c57_b_ControlParams.Supervisory.BalanceParams[c57_i9] = ((real_T *)&((char_T
      *)(c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
      [0])[168])[c57_i9];
  }

  for (c57_i10 = 0; c57_i10 < 5; c57_i10++) {
    c57_b_ControlParams.Supervisory.GaitTweaks[c57_i10] = ((real_T *)&((char_T *)
      (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
      [0])[272])[c57_i10];
  }

  c57_b_ControlParams.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [312];
  c57_b_ControlParams.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [320];
  c57_b_ControlParams.Supervisory.RunMode = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [328];
  c57_b_ControlParams.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [336];
  for (c57_i11 = 0; c57_i11 < 6; c57_i11++) {
    c57_b_ControlParams.Supervisory.ErrorZeroFactor[c57_i11] = ((real_T *)
      &((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c57_ControlParams)[0])[344])[c57_i11];
  }

  for (c57_i12 = 0; c57_i12 < 6; c57_i12++) {
    c57_b_ControlParams.Supervisory.ErrorVelZeroFactor[c57_i12] = ((real_T *)
      &((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c57_ControlParams)[0])[392])[c57_i12];
  }

  c57_b_ControlParams.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [440];
  c57_b_ControlParams.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [448];
  c57_b_ControlParams.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [456];
  c57_b_ControlParams.Supervisory.TPosing = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [464];
  c57_b_ControlParams.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [472];
  c57_b_ControlParams.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [480];
  c57_b_ControlParams.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [488];
  c57_b_ControlParams.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [496];
  c57_b_ControlParams.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T
    *)(c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
    [0])[504];
  c57_b_ControlParams.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T
    *)(c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
    [0])[512];
  c57_b_ControlParams.Supervisory.VelocityControlTorsoGain = *(real_T *)
    &((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c57_ControlParams)[0])[520];
  c57_b_ControlParams.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [528];
  c57_b_ControlParams.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [536];
  c57_b_ControlParams.Supervisory.Theta0 = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [544];
  c57_b_ControlParams.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [552];
  c57_b_ControlParams.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [560];
  c57_b_ControlParams.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T
    *)(c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
    [0])[568];
  c57_b_ControlParams.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [576];
  c57_b_ControlParams.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [584];
  c57_b_ControlParams.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [592];
  c57_b_ControlParams.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [600];
  for (c57_i13 = 0; c57_i13 < 6; c57_i13++) {
    c57_b_ControlParams.Supervisory.K1MidStanceUpdate[c57_i13] = ((real_T *)
      &((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c57_ControlParams)[0])[608])[c57_i13];
  }

  for (c57_i14 = 0; c57_i14 < 6; c57_i14++) {
    c57_b_ControlParams.Supervisory.K2MidStanceUpdate[c57_i14] = ((real_T *)
      &((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c57_ControlParams)[0])[656])[c57_i14];
  }

  c57_b_ControlParams.Supervisory.EnableVelocityBasedUpdate = *(real_T *)
    &((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c57_ControlParams)[0])[704];
  for (c57_i15 = 0; c57_i15 < 6; c57_i15++) {
    c57_b_ControlParams.Supervisory.VelocityBasedUpdateK1[c57_i15] = ((real_T *)
      &((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c57_ControlParams)[0])[712])[c57_i15];
  }

  for (c57_i16 = 0; c57_i16 < 6; c57_i16++) {
    c57_b_ControlParams.Supervisory.VelocityBasedUpdateK2[c57_i16] = ((real_T *)
      &((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c57_ControlParams)[0])[760])[c57_i16];
  }

  c57_b_ControlParams.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)
    &((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c57_ControlParams)[0])[808];
  c57_i17 = 0;
  for (c57_i18 = 0; c57_i18 < 2; c57_i18++) {
    for (c57_i19 = 0; c57_i19 < 6; c57_i19++) {
      c57_b_ControlParams.Supervisory.VelocityBasedUpdateLimits[c57_i19 +
        c57_i17] = ((real_T *)&((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
        chartInstance->c57_ControlParams)[0])[816])[c57_i19 + c57_i17];
    }

    c57_i17 += 6;
  }

  c57_b_ControlParams.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [912];
  c57_b_ControlParams.Supervisory.dx_cmd = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [920];
  c57_b_ControlParams.Supervisory.ForBackward = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [928];
  c57_b_ControlParams.Supervisory.EnableFrictionID = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [936];
  c57_b_ControlParams.Supervisory.ResetFrictionPosing = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [944];
  c57_b_ControlParams.Supervisory.MoveLegIndex = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [952];
  c57_b_ControlParams.Supervisory.dy_cmd = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[0])
    [960];
  c57_b_ControlParams.Discrete.TLastUpdate = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[968])
    [0];
  c57_b_ControlParams.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[968])
    [8];
  c57_b_ControlParams.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[968])
    [16];
  c57_b_ControlParams.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[968])
    [24];
  c57_b_ControlParams.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T
    *)(c57_DiscreteParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[968])
    [32];
  c57_b_ControlParams.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[968])
    [40];
  c57_b_ControlParams.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[968])
    [48];
  c57_b_ControlParams.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[968])
    [56];
  c57_b_ControlParams.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[968])
    [64];
  c57_b_ControlParams.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[968])
    [72];
  c57_b_ControlParams.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[968])
    [80];
  c57_i20 = 0;
  for (c57_i21 = 0; c57_i21 < 13; c57_i21++) {
    for (c57_i22 = 0; c57_i22 < 6; c57_i22++) {
      c57_b_ControlParams.Output.H0[c57_i22 + c57_i20] = ((real_T *)&((char_T *)
        (c57_OutputParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
        [1056])[0])[c57_i22 + c57_i20];
    }

    c57_i20 += 6;
  }

  c57_i23 = 0;
  for (c57_i24 = 0; c57_i24 < 6; c57_i24++) {
    for (c57_i25 = 0; c57_i25 < 6; c57_i25++) {
      c57_b_ControlParams.Output.HAlpha[c57_i25 + c57_i23] = ((real_T *)
        &((char_T *)(c57_OutputParamsBus *)&((char_T *)
        chartInstance->c57_ControlParams)[1056])[624])[c57_i25 + c57_i23];
    }

    c57_i23 += 6;
  }

  for (c57_i26 = 0; c57_i26 < 2; c57_i26++) {
    c57_b_ControlParams.Output.ThetaLimits[c57_i26] = ((real_T *)&((char_T *)
      (c57_OutputParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[1056])
      [912])[c57_i26];
  }

  c57_b_ControlParams.Output.Theta.c0 = *(real_T *)&((char_T *)
    (c57_ThetaParamsBus *)&((char_T *)(c57_OutputParamsBus *)&((char_T *)
    chartInstance->c57_ControlParams)[1056])[928])[0];
  c57_b_ControlParams.Output.Theta.ct = *(real_T *)&((char_T *)
    (c57_ThetaParamsBus *)&((char_T *)(c57_OutputParamsBus *)&((char_T *)
    chartInstance->c57_ControlParams)[1056])[928])[8];
  for (c57_i27 = 0; c57_i27 < 13; c57_i27++) {
    c57_b_ControlParams.Output.Theta.cq[c57_i27] = ((real_T *)&((char_T *)
      (c57_ThetaParamsBus *)&((char_T *)(c57_OutputParamsBus *)&((char_T *)
      chartInstance->c57_ControlParams)[1056])[928])[16])[c57_i27];
  }

  c57_b_ControlParams.Output.Theta.t0 = *(real_T *)&((char_T *)
    (c57_ThetaParamsBus *)&((char_T *)(c57_OutputParamsBus *)&((char_T *)
    chartInstance->c57_ControlParams)[1056])[928])[120];
  for (c57_i28 = 0; c57_i28 < 7; c57_i28++) {
    c57_b_ControlParams.Output.Theta.cz[c57_i28] = ((real_T *)&((char_T *)
      (c57_ThetaParamsBus *)&((char_T *)(c57_OutputParamsBus *)&((char_T *)
      chartInstance->c57_ControlParams)[1056])[928])[128])[c57_i28];
  }

  c57_b_ControlParams.Output.SaturateS = *(real_T *)&((char_T *)
    (c57_OutputParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[1056])
    [1112];
  for (c57_i29 = 0; c57_i29 < 2; c57_i29++) {
    c57_b_ControlParams.Output.SLimits[c57_i29] = ((real_T *)&((char_T *)
      (c57_OutputParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[1056])
      [1120])[c57_i29];
  }

  c57_b_ControlParams.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c57_OutputParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[1056])
    [1136];
  c57_b_ControlParams.Output.UseCorrection = *(real_T *)&((char_T *)
    (c57_OutputParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[1056])
    [1144];
  c57_b_ControlParams.Output.SMaxCorrection = *(real_T *)&((char_T *)
    (c57_OutputParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[1056])
    [1152];
  c57_i30 = 0;
  for (c57_i31 = 0; c57_i31 < 5; c57_i31++) {
    for (c57_i32 = 0; c57_i32 < 6; c57_i32++) {
      c57_b_ControlParams.Output.HAlphaCorrection[c57_i32 + c57_i30] = ((real_T *)
        &((char_T *)(c57_OutputParamsBus *)&((char_T *)
        chartInstance->c57_ControlParams)[1056])[1160])[c57_i32 + c57_i30];
    }

    c57_i30 += 6;
  }

  c57_b_ControlParams.Output.Phi.c0 = *(real_T *)&((char_T *)(c57_PhiParamsBus *)
    &((char_T *)(c57_OutputParamsBus *)&((char_T *)
    chartInstance->c57_ControlParams)[1056])[1400])[0];
  for (c57_i33 = 0; c57_i33 < 13; c57_i33++) {
    c57_b_ControlParams.Output.Phi.cq[c57_i33] = ((real_T *)&((char_T *)
      (c57_PhiParamsBus *)&((char_T *)(c57_OutputParamsBus *)&((char_T *)
      chartInstance->c57_ControlParams)[1056])[1400])[8])[c57_i33];
  }

  for (c57_i34 = 0; c57_i34 < 20; c57_i34++) {
    c57_b_ControlParams.Output.PhiAlpha[c57_i34] = ((real_T *)&((char_T *)
      (c57_OutputParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[1056])
      [1512])[c57_i34];
  }

  c57_b_ControlParams.Output.SaturateR = *(real_T *)&((char_T *)
    (c57_OutputParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[1056])
    [1672];
  for (c57_i35 = 0; c57_i35 < 2; c57_i35++) {
    c57_b_ControlParams.Output.RLimits[c57_i35] = ((real_T *)&((char_T *)
      (c57_OutputParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[1056])
      [1680])[c57_i35];
  }

  c57_i36 = 0;
  for (c57_i37 = 0; c57_i37 < 5; c57_i37++) {
    for (c57_i38 = 0; c57_i38 < 6; c57_i38++) {
      c57_b_ControlParams.Output.HBarAlpha[c57_i38 + c57_i36] = ((real_T *)
        &((char_T *)(c57_OutputParamsBus *)&((char_T *)
        chartInstance->c57_ControlParams)[1056])[1696])[c57_i38 + c57_i36];
    }

    c57_i36 += 6;
  }

  c57_i39 = 0;
  for (c57_i40 = 0; c57_i40 < 2; c57_i40++) {
    for (c57_i41 = 0; c57_i41 < 6; c57_i41++) {
      c57_b_ControlParams.Output.HBarLimits[c57_i41 + c57_i39] = ((real_T *)
        &((char_T *)(c57_OutputParamsBus *)&((char_T *)
        chartInstance->c57_ControlParams)[1056])[1936])[c57_i41 + c57_i39];
    }

    c57_i39 += 6;
  }

  c57_i42 = 0;
  for (c57_i43 = 0; c57_i43 < 6; c57_i43++) {
    for (c57_i44 = 0; c57_i44 < 6; c57_i44++) {
      c57_b_ControlParams.Output.HAlphaStar[c57_i44 + c57_i42] = ((real_T *)
        &((char_T *)(c57_OutputParamsBus *)&((char_T *)
        chartInstance->c57_ControlParams)[1056])[2032])[c57_i44 + c57_i42];
    }

    c57_i42 += 6;
  }

  c57_b_ControlParams.Output.YawLimit = *(real_T *)&((char_T *)
    (c57_OutputParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[1056])
    [2320];
  c57_b_ControlParams.Output.test = *(real_T *)&((char_T *)(c57_OutputParamsBus *)
    &((char_T *)chartInstance->c57_ControlParams)[1056])[2328];
  for (c57_i45 = 0; c57_i45 < 6; c57_i45++) {
    c57_b_ControlParams.Feedback.kp[c57_i45] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
      [3392])[0])[c57_i45];
  }

  for (c57_i46 = 0; c57_i46 < 6; c57_i46++) {
    c57_b_ControlParams.Feedback.kd[c57_i46] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
      [3392])[48])[c57_i46];
  }

  for (c57_i47 = 0; c57_i47 < 2; c57_i47++) {
    c57_b_ControlParams.Feedback.epsilon[c57_i47] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
      [3392])[96])[c57_i47];
  }

  for (c57_i48 = 0; c57_i48 < 2; c57_i48++) {
    c57_b_ControlParams.Feedback.kff_grav[c57_i48] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
      [3392])[112])[c57_i48];
  }

  c57_b_ControlParams.Feedback.delta_grav = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [128];
  for (c57_i49 = 0; c57_i49 < 2; c57_i49++) {
    c57_b_ControlParams.Feedback.kff_decoup[c57_i49] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
      [3392])[136])[c57_i49];
  }

  for (c57_i50 = 0; c57_i50 < 2; c57_i50++) {
    c57_b_ControlParams.Feedback.kd_torso[c57_i50] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
      [3392])[152])[c57_i50];
  }

  c57_b_ControlParams.Feedback.kp_2dof = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [168];
  c57_b_ControlParams.Feedback.kd_2dof = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [176];
  c57_b_ControlParams.Feedback.kpre_2dof = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [184];
  c57_b_ControlParams.Feedback.kp_lat = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [192];
  c57_b_ControlParams.Feedback.kd_lat = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [200];
  c57_b_ControlParams.Feedback.q3d_min_lat = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [208];
  c57_b_ControlParams.Feedback.q3d_max_lat = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [216];
  c57_b_ControlParams.Feedback.w_torso_lat = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [224];
  for (c57_i51 = 0; c57_i51 < 6; c57_i51++) {
    c57_b_ControlParams.Feedback.u_ff[c57_i51] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
      [3392])[232])[c57_i51];
  }

  c57_b_ControlParams.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [280];
  c57_b_ControlParams.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [288];
  c57_b_ControlParams.Feedback.Use2DOF = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [296];
  c57_b_ControlParams.Feedback.UseDSGravComp = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [304];
  c57_b_ControlParams.Feedback.lat_bias = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [312];
  c57_b_ControlParams.Feedback.lat_bias2 = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [320];
  c57_b_ControlParams.Feedback.linkFeedback = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [328];
  c57_b_ControlParams.Feedback.RIO = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [336];
  c57_b_ControlParams.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [344];
  for (c57_i52 = 0; c57_i52 < 6; c57_i52++) {
    c57_b_ControlParams.Feedback.FeedforwardGain[c57_i52] = ((real_T *)&((char_T
      *)(c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
      [3392])[352])[c57_i52];
  }

  c57_b_ControlParams.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)chartInstance->c57_ControlParams)[3392])
    [400];
  c57_b_ControlParams.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c57_SaturationParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
    [3800])[0];
  for (c57_i53 = 0; c57_i53 < 2; c57_i53++) {
    c57_b_ControlParams.Saturation.QPWeight[c57_i53] = ((real_T *)&((char_T *)
      (c57_SaturationParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
      [3800])[8])[c57_i53];
  }

  c57_b_ControlParams.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c57_SaturationParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
    [3800])[24];
  c57_b_ControlParams.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c57_SaturationParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
    [3800])[32];
  c57_b_ControlParams.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c57_SaturationParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
    [3800])[40];
  c57_b_ControlParams.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c57_SaturationParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
    [3800])[48];
  c57_b_ControlParams.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c57_SaturationParamsBus *)&((char_T *)chartInstance->c57_ControlParams)
    [3800])[56];
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 19U, 19U, c57_debug_family_names,
    c57_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_weight, 0U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LA_R, 1U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LS_R, 2U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LA_L, 3U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LS_L, 4U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_uR, 5U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_uL, 6U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_T0, 7U, c57_f_sf_marshallOut,
    c57_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u0, 8U, c57_sf_marshallOut,
    c57_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_deltaS, 9U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_KASaturationLim, 10U,
    c57_e_sf_marshallOut, c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargin, 11U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargout, 12U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c57_b_u, 13U, c57_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c57_b_s, 14U, c57_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c57_b_sat, 15U, c57_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c57_b_ControlState, 16U, c57_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c57_b_ControlParams, 17U, c57_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_b_u_sat, 18U, c57_sf_marshallOut,
    c57_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 4);
  for (c57_i54 = 0; c57_i54 < 6; c57_i54++) {
    c57_b_u_sat[c57_i54] = c57_b_u[c57_i54];
  }

  _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 6);
  if (CV_EML_IF(0, 1, 0, c57_b_ControlParams.Saturation.UseQPSaturation != 0.0))
  {
    _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 7);
    if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 0,
          c57_b_ControlState.StanceLeg, 0.0, -1, 0U,
          c57_b_ControlState.StanceLeg == 0.0))) {
      _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 8);
      for (c57_i55 = 0; c57_i55 < 2; c57_i55++) {
        c57_weight[c57_i55] = c57_b_ControlParams.Saturation.QPWeight[c57_i55];
      }
    } else {
      _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 10);
      for (c57_i56 = 0; c57_i56 < 2; c57_i56++) {
        c57_b[c57_i56] = c57_b_ControlParams.Saturation.QPWeight[c57_i56];
      }

      c57_eml_scalar_eg(chartInstance);
      c57_eml_scalar_eg(chartInstance);
      for (c57_i57 = 0; c57_i57 < 2; c57_i57++) {
        c57_weight[c57_i57] = 0.0;
      }

      for (c57_i58 = 0; c57_i58 < 2; c57_i58++) {
        c57_weight[c57_i58] = 0.0;
      }

      for (c57_i59 = 0; c57_i59 < 2; c57_i59++) {
        c57_C[c57_i59] = c57_weight[c57_i59];
      }

      for (c57_i60 = 0; c57_i60 < 2; c57_i60++) {
        c57_weight[c57_i60] = c57_C[c57_i60];
      }

      c57_threshold(chartInstance);
      for (c57_i61 = 0; c57_i61 < 2; c57_i61++) {
        c57_C[c57_i61] = c57_weight[c57_i61];
      }

      for (c57_i62 = 0; c57_i62 < 2; c57_i62++) {
        c57_weight[c57_i62] = c57_C[c57_i62];
      }

      for (c57_i63 = 0; c57_i63 < 2; c57_i63++) {
        c57_weight[c57_i63] = 0.0;
        c57_i64 = 0;
        for (c57_i65 = 0; c57_i65 < 2; c57_i65++) {
          c57_weight[c57_i63] += c57_a[c57_i64 + c57_i63] * c57_b[c57_i65];
          c57_i64 += 2;
        }
      }
    }

    _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 13);
    c57_A = c57_b_u[0] + c57_b_u[1];
    c57_u_LA_R = c57_rdivide(chartInstance, c57_A, 2.0);
    _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 14);
    c57_u_LS_R = c57_b_u[1] - c57_b_u[0];
    _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 15);
    c57_b_A = c57_b_u[3] + c57_b_u[4];
    c57_u_LA_L = c57_rdivide(chartInstance, c57_b_A, 2.0);
    _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 16);
    c57_u_LS_L = c57_b_u[4] - c57_b_u[3];
    _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 18);
    c57_LA_LS_Revised_Saturation(chartInstance, c57_u_LS_R, c57_u_LA_R,
      c57_weight[0], -c57_b_sat[0], c57_b_sat[0], -c57_b_sat[1], c57_b_sat[1],
      c57_dv1);
    for (c57_i66 = 0; c57_i66 < 2; c57_i66++) {
      c57_uR[c57_i66] = c57_dv1[c57_i66];
    }

    _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 19);
    c57_LA_LS_Revised_Saturation(chartInstance, c57_u_LS_L, c57_u_LA_L,
      c57_weight[1], -c57_b_sat[0], c57_b_sat[0], -c57_b_sat[1], c57_b_sat[1],
      c57_dv2);
    for (c57_i67 = 0; c57_i67 < 2; c57_i67++) {
      c57_uL[c57_i67] = c57_dv2[c57_i67];
    }

    _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 20);
    for (c57_i68 = 0; c57_i68 < 2; c57_i68++) {
      c57_b_u_sat[c57_i68] = c57_uR[c57_i68];
    }

    c57_b_u_sat[2] = c57_b_u[2];
    for (c57_i69 = 0; c57_i69 < 2; c57_i69++) {
      c57_b_u_sat[c57_i69 + 3] = c57_uL[c57_i69];
    }

    c57_b_u_sat[5] = c57_b_u[5];
  }

  _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 23);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 1,
        c57_b_ControlState.ControllerMode, 3.0, -1, 5U,
        c57_b_ControlState.ControllerMode >= 3.0))) {
    if (CV_EML_COND(0, 1, 1, c57_b_ControlParams.Saturation.UseKASaturation !=
                    0.0)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 2, true);
      _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 26);
      for (c57_i70 = 0; c57_i70 < 36; c57_i70++) {
        c57_T0[c57_i70] = c57_dv3[c57_i70];
      }

      _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 27);
      if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 2,
            c57_b_ControlState.StanceLeg, 1.0, -1, 0U,
            c57_b_ControlState.StanceLeg == 1.0))) {
        _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 28);
        for (c57_i71 = 0; c57_i71 < 6; c57_i71++) {
          for (c57_i72 = 0; c57_i72 < 6; c57_i72++) {
            c57_b_T0[c57_i72 + 6 * c57_i71] = c57_T0[c57_iv0[c57_i72] + 6 *
              c57_i71];
          }
        }

        c57_i73 = 0;
        for (c57_i74 = 0; c57_i74 < 6; c57_i74++) {
          for (c57_i75 = 0; c57_i75 < 6; c57_i75++) {
            c57_T0[c57_i75 + c57_i73] = c57_b_T0[c57_i75 + c57_i73];
          }

          c57_i73 += 6;
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 31);
      for (c57_i76 = 0; c57_i76 < 36; c57_i76++) {
        c57_b_a[c57_i76] = c57_T0[c57_i76];
      }

      for (c57_i77 = 0; c57_i77 < 6; c57_i77++) {
        c57_b_b[c57_i77] = c57_b_u_sat[c57_i77];
      }

      c57_b_eml_scalar_eg(chartInstance);
      c57_b_eml_scalar_eg(chartInstance);
      for (c57_i78 = 0; c57_i78 < 6; c57_i78++) {
        c57_u0[c57_i78] = 0.0;
      }

      for (c57_i79 = 0; c57_i79 < 6; c57_i79++) {
        c57_u0[c57_i79] = 0.0;
      }

      for (c57_i80 = 0; c57_i80 < 6; c57_i80++) {
        c57_b_C[c57_i80] = c57_u0[c57_i80];
      }

      for (c57_i81 = 0; c57_i81 < 6; c57_i81++) {
        c57_u0[c57_i81] = c57_b_C[c57_i81];
      }

      c57_threshold(chartInstance);
      for (c57_i82 = 0; c57_i82 < 6; c57_i82++) {
        c57_b_C[c57_i82] = c57_u0[c57_i82];
      }

      for (c57_i83 = 0; c57_i83 < 6; c57_i83++) {
        c57_u0[c57_i83] = c57_b_C[c57_i83];
      }

      for (c57_i84 = 0; c57_i84 < 6; c57_i84++) {
        c57_u0[c57_i84] = 0.0;
        c57_i85 = 0;
        for (c57_i86 = 0; c57_i86 < 6; c57_i86++) {
          c57_u0[c57_i84] += c57_b_a[c57_i85 + c57_i84] * c57_b_b[c57_i86];
          c57_i85 += 6;
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 32);
      c57_deltaS = c57_b_ControlParams.Saturation.KASaturationS2 -
        c57_b_ControlParams.Saturation.KASaturationS1;
      _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 33);
      c57_varargin_1 = c57_deltaS;
      c57_varargin_2 = c57_varargin_1;
      c57_x = c57_varargin_2;
      c57_b_x = c57_x;
      c57_c_eml_scalar_eg(chartInstance);
      c57_xk = c57_b_x;
      c57_c_x = c57_xk;
      c57_c_eml_scalar_eg(chartInstance);
      c57_deltaS = muDoubleScalarMin(c57_c_x, 1.0);
      _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 34);
      if (CV_EML_IF(0, 1, 4, CV_RELATIONAL_EVAL(4U, 0U, 3, c57_b_s,
            c57_b_ControlParams.Saturation.KASaturationS1, -1, 2U, c57_b_s <
            c57_b_ControlParams.Saturation.KASaturationS1))) {
        _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 35);
        c57_KASaturationLim = c57_b_ControlParams.Saturation.KASaturationEarly;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 36);
        if (CV_EML_IF(0, 1, 5, CV_RELATIONAL_EVAL(4U, 0U, 4, c57_b_s,
              c57_b_ControlParams.Saturation.KASaturationS2, -1, 2U, c57_b_s <
              c57_b_ControlParams.Saturation.KASaturationS2))) {
          _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 37);
          c57_c_a[0] = c57_b_ControlParams.Saturation.KASaturationS2 - c57_b_s;
          c57_c_a[1] = c57_b_s - c57_b_ControlParams.Saturation.KASaturationS1;
          c57_b[0] = c57_b_ControlParams.Saturation.KASaturationEarly;
          c57_b[1] = c57_b_ControlParams.Saturation.KASaturationMax;
          for (c57_i87 = 0; c57_i87 < 2; c57_i87++) {
            c57_d_a[c57_i87] = c57_c_a[c57_i87];
          }

          for (c57_i88 = 0; c57_i88 < 2; c57_i88++) {
            c57_c_b[c57_i88] = c57_b[c57_i88];
          }

          c57_y = c57_eml_xdotu(chartInstance, c57_d_a, c57_c_b);
          c57_c_A = c57_y;
          c57_B = c57_deltaS;
          c57_KASaturationLim = c57_rdivide(chartInstance, c57_c_A, c57_B);
        } else {
          _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 40);
          c57_KASaturationLim = c57_b_ControlParams.Saturation.KASaturationMax;
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 42);
      c57_b_varargin_1 = c57_u0[2];
      c57_b_varargin_2 = c57_KASaturationLim;
      c57_c_varargin_2 = c57_b_varargin_1;
      c57_varargin_3 = c57_b_varargin_2;
      c57_d_x = c57_c_varargin_2;
      c57_b_y = c57_varargin_3;
      c57_e_x = c57_d_x;
      c57_c_y = c57_b_y;
      c57_c_eml_scalar_eg(chartInstance);
      c57_b_xk = c57_e_x;
      c57_yk = c57_c_y;
      c57_f_x = c57_b_xk;
      c57_d_y = c57_yk;
      c57_c_eml_scalar_eg(chartInstance);
      c57_minval = muDoubleScalarMin(c57_f_x, c57_d_y);
      c57_c_varargin_1 = -c57_KASaturationLim;
      c57_d_varargin_2 = c57_minval;
      c57_e_varargin_2 = c57_c_varargin_1;
      c57_b_varargin_3 = c57_d_varargin_2;
      c57_g_x = c57_e_varargin_2;
      c57_e_y = c57_b_varargin_3;
      c57_h_x = c57_g_x;
      c57_f_y = c57_e_y;
      c57_c_eml_scalar_eg(chartInstance);
      c57_c_xk = c57_h_x;
      c57_b_yk = c57_f_y;
      c57_i_x = c57_c_xk;
      c57_g_y = c57_b_yk;
      c57_c_eml_scalar_eg(chartInstance);
      c57_maxval = muDoubleScalarMax(c57_i_x, c57_g_y);
      c57_u0[2] = c57_maxval;
      _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, 43);
      for (c57_i89 = 0; c57_i89 < 36; c57_i89++) {
        c57_b_a[c57_i89] = c57_T0[c57_i89];
      }

      for (c57_i90 = 0; c57_i90 < 6; c57_i90++) {
        c57_b_b[c57_i90] = c57_u0[c57_i90];
      }

      c57_b_eml_matlab_zgetrf(chartInstance, c57_b_a, c57_ipiv, &c57_info);
      c57_b_info = c57_info;
      c57_c_info = c57_b_info;
      c57_d_info = c57_c_info;
      if (c57_d_info > 0) {
        c57_eml_warning(chartInstance);
      }

      c57_b_eml_scalar_eg(chartInstance);
      for (c57_i91 = 0; c57_i91 < 6; c57_i91++) {
        c57_b_u_sat[c57_i91] = c57_b_b[c57_i91];
      }

      c57_eml_switch_helper(chartInstance);
      for (c57_xi = 1; c57_xi < 6; c57_xi++) {
        c57_b_xi = c57_xi;
        if (c57_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
             ("", (real_T)c57_b_xi), 1, 6, 1, 0) - 1] != c57_b_xi) {
          c57_ip = c57_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_b_xi), 1, 6, 1, 0) - 1];
          c57_temp = c57_b_u_sat[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_b_xi), 1, 6, 1, 0) - 1];
          c57_b_u_sat[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_b_xi), 1, 6, 1, 0) - 1] =
            c57_b_u_sat[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_ip), 1, 6, 1, 0) - 1];
          c57_b_u_sat[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_ip), 1, 6, 1, 0) - 1] = c57_temp;
        }
      }

      for (c57_i92 = 0; c57_i92 < 6; c57_i92++) {
        c57_b_b[c57_i92] = c57_b_u_sat[c57_i92];
      }

      for (c57_i93 = 0; c57_i93 < 36; c57_i93++) {
        c57_e_a[c57_i93] = c57_b_a[c57_i93];
      }

      c57_c_eml_xtrsm(chartInstance, c57_e_a, c57_b_b);
      for (c57_i94 = 0; c57_i94 < 6; c57_i94++) {
        c57_b_u_sat[c57_i94] = c57_b_b[c57_i94];
      }

      for (c57_i95 = 0; c57_i95 < 6; c57_i95++) {
        c57_b_b[c57_i95] = c57_b_u_sat[c57_i95];
      }

      for (c57_i96 = 0; c57_i96 < 36; c57_i96++) {
        c57_f_a[c57_i96] = c57_b_a[c57_i96];
      }

      c57_d_eml_xtrsm(chartInstance, c57_f_a, c57_b_b);
      for (c57_i97 = 0; c57_i97 < 6; c57_i97++) {
        c57_b_u_sat[c57_i97] = c57_b_b[c57_i97];
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

  _SFD_EML_CALL(0U, chartInstance->c57_sfEvent, -43);
  _SFD_SYMBOL_SCOPE_POP();
  for (c57_i98 = 0; c57_i98 < 6; c57_i98++) {
    (*chartInstance->c57_u_sat)[c57_i98] = c57_b_u_sat[c57_i98];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 26U, chartInstance->c57_sfEvent);
}

static void initSimStructsc57_Walking01_DDA3D
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c57_LA_LS_Revised_Saturation(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, real_T c57_u_LS, real_T c57_u_LA, real_T c57_w, real_T
  c57_u1_min, real_T c57_u1_max, real_T c57_u2_min, real_T c57_u2_max, real_T
  c57_u_opt[2])
{
  uint32_T c57_debug_family_var_map[32];
  real_T c57_u_opt_1[2];
  real_T c57_L_opt_1[4];
  real_T c57_u_opt_2[2];
  real_T c57_L_opt_2[4];
  real_T c57_u_opt_3[2];
  real_T c57_L_opt_3[4];
  real_T c57_u_opt_4[2];
  real_T c57_L_opt_4[4];
  real_T c57_u_opt_5[2];
  real_T c57_L_opt_5[4];
  real_T c57_u_opt_6[2];
  real_T c57_L_opt_6[4];
  real_T c57_u_opt_7[2];
  real_T c57_L_opt_7[4];
  real_T c57_u_opt_8[2];
  real_T c57_L_opt_8[4];
  real_T c57_u_opt_9[2];
  real_T c57_L_opt_9[4];
  real_T c57_LB[2];
  real_T c57_UB[2];
  real_T c57_L_opt[4];
  real_T c57_case_n;
  real_T c57_nargin = 7.0;
  real_T c57_nargout = 1.0;
  real_T c57_b_L_opt_1[4];
  real_T c57_b_u_opt_1[2];
  int32_T c57_i99;
  int32_T c57_i100;
  int32_T c57_i101;
  int32_T c57_i102;
  int32_T c57_i103;
  int32_T c57_i104;
  int32_T c57_i105;
  int32_T c57_i106;
  int32_T c57_i107;
  int32_T c57_i108;
  int32_T c57_i109;
  int32_T c57_i110;
  int32_T c57_i111;
  int32_T c57_i112;
  int32_T c57_i113;
  int32_T c57_i114;
  int32_T c57_i115;
  int32_T c57_i116;
  int32_T c57_i117;
  int32_T c57_i118;
  int32_T c57_i119;
  int32_T c57_ixstart;
  real_T c57_mtmp;
  real_T c57_x;
  boolean_T c57_b;
  int32_T c57_ix;
  int32_T c57_b_ix;
  real_T c57_b_x;
  boolean_T c57_b_b;
  int32_T c57_a;
  int32_T c57_b_a;
  int32_T c57_i120;
  int32_T c57_c_a;
  int32_T c57_d_a;
  boolean_T c57_overflow;
  int32_T c57_c_ix;
  real_T c57_e_a;
  real_T c57_c_b;
  boolean_T c57_p;
  real_T c57_b_mtmp;
  real_T c57_d0;
  int32_T c57_i121;
  int32_T c57_b_ixstart;
  real_T c57_c_mtmp;
  real_T c57_c_x;
  boolean_T c57_d_b;
  int32_T c57_d_ix;
  int32_T c57_e_ix;
  real_T c57_d_x;
  boolean_T c57_e_b;
  int32_T c57_f_a;
  int32_T c57_g_a;
  int32_T c57_i122;
  int32_T c57_h_a;
  int32_T c57_i_a;
  boolean_T c57_b_overflow;
  int32_T c57_f_ix;
  real_T c57_j_a;
  real_T c57_f_b;
  boolean_T c57_b_p;
  real_T c57_d_mtmp;
  real_T c57_d1;
  int32_T c57_i123;
  int32_T c57_c_ixstart;
  real_T c57_e_mtmp;
  real_T c57_e_x;
  boolean_T c57_g_b;
  int32_T c57_g_ix;
  int32_T c57_h_ix;
  real_T c57_f_x;
  boolean_T c57_h_b;
  int32_T c57_k_a;
  int32_T c57_l_a;
  int32_T c57_i124;
  int32_T c57_m_a;
  int32_T c57_n_a;
  boolean_T c57_c_overflow;
  int32_T c57_i_ix;
  real_T c57_o_a;
  real_T c57_i_b;
  boolean_T c57_c_p;
  real_T c57_f_mtmp;
  real_T c57_d2;
  int32_T c57_i125;
  int32_T c57_i126;
  int32_T c57_i127;
  int32_T c57_d_ixstart;
  real_T c57_g_mtmp;
  real_T c57_g_x;
  boolean_T c57_j_b;
  int32_T c57_j_ix;
  int32_T c57_k_ix;
  real_T c57_h_x;
  boolean_T c57_k_b;
  int32_T c57_p_a;
  int32_T c57_q_a;
  int32_T c57_i128;
  int32_T c57_r_a;
  int32_T c57_s_a;
  boolean_T c57_d_overflow;
  int32_T c57_l_ix;
  real_T c57_t_a;
  real_T c57_l_b;
  boolean_T c57_d_p;
  real_T c57_h_mtmp;
  real_T c57_d3;
  int32_T c57_i129;
  int32_T c57_e_ixstart;
  real_T c57_i_mtmp;
  real_T c57_i_x;
  boolean_T c57_m_b;
  int32_T c57_m_ix;
  int32_T c57_n_ix;
  real_T c57_j_x;
  boolean_T c57_n_b;
  int32_T c57_u_a;
  int32_T c57_v_a;
  int32_T c57_i130;
  int32_T c57_w_a;
  int32_T c57_x_a;
  boolean_T c57_e_overflow;
  int32_T c57_o_ix;
  real_T c57_y_a;
  real_T c57_o_b;
  boolean_T c57_e_p;
  real_T c57_j_mtmp;
  real_T c57_d4;
  int32_T c57_i131;
  int32_T c57_f_ixstart;
  real_T c57_k_mtmp;
  real_T c57_k_x;
  boolean_T c57_p_b;
  int32_T c57_p_ix;
  int32_T c57_q_ix;
  real_T c57_l_x;
  boolean_T c57_q_b;
  int32_T c57_ab_a;
  int32_T c57_bb_a;
  int32_T c57_i132;
  int32_T c57_cb_a;
  int32_T c57_db_a;
  boolean_T c57_f_overflow;
  int32_T c57_r_ix;
  real_T c57_eb_a;
  real_T c57_r_b;
  boolean_T c57_f_p;
  real_T c57_l_mtmp;
  real_T c57_d5;
  int32_T c57_i133;
  int32_T c57_i134;
  int32_T c57_i135;
  int32_T c57_g_ixstart;
  real_T c57_m_mtmp;
  real_T c57_m_x;
  boolean_T c57_s_b;
  int32_T c57_s_ix;
  int32_T c57_t_ix;
  real_T c57_n_x;
  boolean_T c57_t_b;
  int32_T c57_fb_a;
  int32_T c57_gb_a;
  int32_T c57_i136;
  int32_T c57_hb_a;
  int32_T c57_ib_a;
  boolean_T c57_g_overflow;
  int32_T c57_u_ix;
  real_T c57_jb_a;
  real_T c57_u_b;
  boolean_T c57_g_p;
  real_T c57_n_mtmp;
  real_T c57_d6;
  int32_T c57_i137;
  int32_T c57_h_ixstart;
  real_T c57_o_mtmp;
  real_T c57_o_x;
  boolean_T c57_v_b;
  int32_T c57_v_ix;
  int32_T c57_w_ix;
  real_T c57_p_x;
  boolean_T c57_w_b;
  int32_T c57_kb_a;
  int32_T c57_lb_a;
  int32_T c57_i138;
  int32_T c57_mb_a;
  int32_T c57_nb_a;
  boolean_T c57_h_overflow;
  int32_T c57_x_ix;
  real_T c57_ob_a;
  real_T c57_x_b;
  boolean_T c57_h_p;
  real_T c57_p_mtmp;
  real_T c57_d7;
  int32_T c57_i139;
  int32_T c57_i_ixstart;
  real_T c57_q_mtmp;
  real_T c57_q_x;
  boolean_T c57_y_b;
  int32_T c57_y_ix;
  int32_T c57_ab_ix;
  real_T c57_r_x;
  boolean_T c57_ab_b;
  int32_T c57_pb_a;
  int32_T c57_qb_a;
  int32_T c57_i140;
  int32_T c57_rb_a;
  int32_T c57_sb_a;
  boolean_T c57_i_overflow;
  int32_T c57_bb_ix;
  real_T c57_tb_a;
  real_T c57_bb_b;
  boolean_T c57_i_p;
  real_T c57_r_mtmp;
  real_T c57_d8;
  int32_T c57_i141;
  int32_T c57_i142;
  int32_T c57_i143;
  int32_T c57_j_ixstart;
  real_T c57_s_mtmp;
  real_T c57_s_x;
  boolean_T c57_cb_b;
  int32_T c57_cb_ix;
  int32_T c57_db_ix;
  real_T c57_t_x;
  boolean_T c57_db_b;
  int32_T c57_ub_a;
  int32_T c57_vb_a;
  int32_T c57_i144;
  int32_T c57_wb_a;
  int32_T c57_xb_a;
  boolean_T c57_j_overflow;
  int32_T c57_eb_ix;
  real_T c57_yb_a;
  real_T c57_eb_b;
  boolean_T c57_j_p;
  real_T c57_t_mtmp;
  real_T c57_d9;
  int32_T c57_i145;
  int32_T c57_k_ixstart;
  real_T c57_u_mtmp;
  real_T c57_u_x;
  boolean_T c57_fb_b;
  int32_T c57_fb_ix;
  int32_T c57_gb_ix;
  real_T c57_v_x;
  boolean_T c57_gb_b;
  int32_T c57_ac_a;
  int32_T c57_bc_a;
  int32_T c57_i146;
  int32_T c57_cc_a;
  int32_T c57_dc_a;
  boolean_T c57_k_overflow;
  int32_T c57_hb_ix;
  real_T c57_ec_a;
  real_T c57_hb_b;
  boolean_T c57_k_p;
  real_T c57_v_mtmp;
  real_T c57_d10;
  int32_T c57_i147;
  int32_T c57_l_ixstart;
  real_T c57_w_mtmp;
  real_T c57_w_x;
  boolean_T c57_ib_b;
  int32_T c57_ib_ix;
  int32_T c57_jb_ix;
  real_T c57_x_x;
  boolean_T c57_jb_b;
  int32_T c57_fc_a;
  int32_T c57_gc_a;
  int32_T c57_i148;
  int32_T c57_hc_a;
  int32_T c57_ic_a;
  boolean_T c57_l_overflow;
  int32_T c57_kb_ix;
  real_T c57_jc_a;
  real_T c57_kb_b;
  boolean_T c57_l_p;
  real_T c57_x_mtmp;
  real_T c57_d11;
  int32_T c57_i149;
  int32_T c57_i150;
  int32_T c57_i151;
  int32_T c57_m_ixstart;
  real_T c57_y_mtmp;
  real_T c57_y_x;
  boolean_T c57_lb_b;
  int32_T c57_lb_ix;
  int32_T c57_mb_ix;
  real_T c57_ab_x;
  boolean_T c57_mb_b;
  int32_T c57_kc_a;
  int32_T c57_lc_a;
  int32_T c57_i152;
  int32_T c57_mc_a;
  int32_T c57_nc_a;
  boolean_T c57_m_overflow;
  int32_T c57_nb_ix;
  real_T c57_oc_a;
  real_T c57_nb_b;
  boolean_T c57_m_p;
  real_T c57_ab_mtmp;
  real_T c57_d12;
  int32_T c57_i153;
  int32_T c57_n_ixstart;
  real_T c57_bb_mtmp;
  real_T c57_bb_x;
  boolean_T c57_ob_b;
  int32_T c57_ob_ix;
  int32_T c57_pb_ix;
  real_T c57_cb_x;
  boolean_T c57_pb_b;
  int32_T c57_pc_a;
  int32_T c57_qc_a;
  int32_T c57_i154;
  int32_T c57_rc_a;
  int32_T c57_sc_a;
  boolean_T c57_n_overflow;
  int32_T c57_qb_ix;
  real_T c57_tc_a;
  real_T c57_qb_b;
  boolean_T c57_n_p;
  real_T c57_cb_mtmp;
  real_T c57_d13;
  int32_T c57_i155;
  int32_T c57_o_ixstart;
  real_T c57_db_mtmp;
  real_T c57_db_x;
  boolean_T c57_rb_b;
  int32_T c57_rb_ix;
  int32_T c57_sb_ix;
  real_T c57_eb_x;
  boolean_T c57_sb_b;
  int32_T c57_uc_a;
  int32_T c57_vc_a;
  int32_T c57_i156;
  int32_T c57_wc_a;
  int32_T c57_xc_a;
  boolean_T c57_o_overflow;
  int32_T c57_tb_ix;
  real_T c57_yc_a;
  real_T c57_tb_b;
  boolean_T c57_o_p;
  real_T c57_eb_mtmp;
  real_T c57_d14;
  int32_T c57_i157;
  int32_T c57_i158;
  int32_T c57_i159;
  int32_T c57_p_ixstart;
  real_T c57_fb_mtmp;
  real_T c57_fb_x;
  boolean_T c57_ub_b;
  int32_T c57_ub_ix;
  int32_T c57_vb_ix;
  real_T c57_gb_x;
  boolean_T c57_vb_b;
  int32_T c57_ad_a;
  int32_T c57_bd_a;
  int32_T c57_i160;
  int32_T c57_cd_a;
  int32_T c57_dd_a;
  boolean_T c57_p_overflow;
  int32_T c57_wb_ix;
  real_T c57_ed_a;
  real_T c57_wb_b;
  boolean_T c57_p_p;
  real_T c57_gb_mtmp;
  real_T c57_d15;
  int32_T c57_i161;
  int32_T c57_q_ixstart;
  real_T c57_hb_mtmp;
  real_T c57_hb_x;
  boolean_T c57_xb_b;
  int32_T c57_xb_ix;
  int32_T c57_yb_ix;
  real_T c57_ib_x;
  boolean_T c57_yb_b;
  int32_T c57_fd_a;
  int32_T c57_gd_a;
  int32_T c57_i162;
  int32_T c57_hd_a;
  int32_T c57_id_a;
  boolean_T c57_q_overflow;
  int32_T c57_ac_ix;
  real_T c57_jd_a;
  real_T c57_ac_b;
  boolean_T c57_q_p;
  real_T c57_ib_mtmp;
  real_T c57_d16;
  int32_T c57_i163;
  int32_T c57_r_ixstart;
  real_T c57_jb_mtmp;
  real_T c57_jb_x;
  boolean_T c57_bc_b;
  int32_T c57_bc_ix;
  int32_T c57_cc_ix;
  real_T c57_kb_x;
  boolean_T c57_cc_b;
  int32_T c57_kd_a;
  int32_T c57_ld_a;
  int32_T c57_i164;
  int32_T c57_md_a;
  int32_T c57_nd_a;
  boolean_T c57_r_overflow;
  int32_T c57_dc_ix;
  real_T c57_od_a;
  real_T c57_dc_b;
  boolean_T c57_r_p;
  real_T c57_kb_mtmp;
  real_T c57_d17;
  int32_T c57_i165;
  int32_T c57_i166;
  int32_T c57_i167;
  int32_T c57_s_ixstart;
  real_T c57_lb_mtmp;
  real_T c57_lb_x;
  boolean_T c57_ec_b;
  int32_T c57_ec_ix;
  int32_T c57_fc_ix;
  real_T c57_mb_x;
  boolean_T c57_fc_b;
  int32_T c57_pd_a;
  int32_T c57_qd_a;
  int32_T c57_i168;
  int32_T c57_rd_a;
  int32_T c57_sd_a;
  boolean_T c57_s_overflow;
  int32_T c57_gc_ix;
  real_T c57_td_a;
  real_T c57_gc_b;
  boolean_T c57_s_p;
  real_T c57_mb_mtmp;
  real_T c57_d18;
  int32_T c57_i169;
  int32_T c57_t_ixstart;
  real_T c57_nb_mtmp;
  real_T c57_nb_x;
  boolean_T c57_hc_b;
  int32_T c57_hc_ix;
  int32_T c57_ic_ix;
  real_T c57_ob_x;
  boolean_T c57_ic_b;
  int32_T c57_ud_a;
  int32_T c57_vd_a;
  int32_T c57_i170;
  int32_T c57_wd_a;
  int32_T c57_xd_a;
  boolean_T c57_t_overflow;
  int32_T c57_jc_ix;
  real_T c57_yd_a;
  real_T c57_jc_b;
  boolean_T c57_t_p;
  real_T c57_ob_mtmp;
  real_T c57_d19;
  int32_T c57_i171;
  int32_T c57_u_ixstart;
  real_T c57_pb_mtmp;
  real_T c57_pb_x;
  boolean_T c57_kc_b;
  int32_T c57_kc_ix;
  int32_T c57_lc_ix;
  real_T c57_qb_x;
  boolean_T c57_lc_b;
  int32_T c57_ae_a;
  int32_T c57_be_a;
  int32_T c57_i172;
  int32_T c57_ce_a;
  int32_T c57_de_a;
  boolean_T c57_u_overflow;
  int32_T c57_mc_ix;
  real_T c57_ee_a;
  real_T c57_mc_b;
  boolean_T c57_u_p;
  real_T c57_qb_mtmp;
  real_T c57_d20;
  int32_T c57_i173;
  int32_T c57_i174;
  int32_T c57_i175;
  int32_T c57_v_ixstart;
  real_T c57_rb_mtmp;
  real_T c57_rb_x;
  boolean_T c57_nc_b;
  int32_T c57_nc_ix;
  int32_T c57_oc_ix;
  real_T c57_sb_x;
  boolean_T c57_oc_b;
  int32_T c57_fe_a;
  int32_T c57_ge_a;
  int32_T c57_i176;
  int32_T c57_he_a;
  int32_T c57_ie_a;
  boolean_T c57_v_overflow;
  int32_T c57_pc_ix;
  real_T c57_je_a;
  real_T c57_pc_b;
  boolean_T c57_v_p;
  real_T c57_sb_mtmp;
  real_T c57_d21;
  int32_T c57_i177;
  int32_T c57_w_ixstart;
  real_T c57_tb_mtmp;
  real_T c57_tb_x;
  boolean_T c57_qc_b;
  int32_T c57_qc_ix;
  int32_T c57_rc_ix;
  real_T c57_ub_x;
  boolean_T c57_rc_b;
  int32_T c57_ke_a;
  int32_T c57_le_a;
  int32_T c57_i178;
  int32_T c57_me_a;
  int32_T c57_ne_a;
  boolean_T c57_w_overflow;
  int32_T c57_sc_ix;
  real_T c57_oe_a;
  real_T c57_sc_b;
  boolean_T c57_w_p;
  real_T c57_ub_mtmp;
  real_T c57_d22;
  int32_T c57_i179;
  int32_T c57_x_ixstart;
  real_T c57_vb_mtmp;
  real_T c57_vb_x;
  boolean_T c57_tc_b;
  int32_T c57_tc_ix;
  int32_T c57_uc_ix;
  real_T c57_wb_x;
  boolean_T c57_uc_b;
  int32_T c57_pe_a;
  int32_T c57_qe_a;
  int32_T c57_i180;
  int32_T c57_re_a;
  int32_T c57_se_a;
  boolean_T c57_x_overflow;
  int32_T c57_vc_ix;
  real_T c57_te_a;
  real_T c57_vc_b;
  boolean_T c57_x_p;
  real_T c57_wb_mtmp;
  real_T c57_d23;
  int32_T c57_i181;
  int32_T c57_i182;
  int32_T c57_i183;
  int32_T c57_y_ixstart;
  real_T c57_xb_mtmp;
  real_T c57_xb_x;
  boolean_T c57_wc_b;
  int32_T c57_wc_ix;
  int32_T c57_xc_ix;
  real_T c57_yb_x;
  boolean_T c57_xc_b;
  int32_T c57_ue_a;
  int32_T c57_ve_a;
  int32_T c57_i184;
  int32_T c57_we_a;
  int32_T c57_xe_a;
  boolean_T c57_y_overflow;
  int32_T c57_yc_ix;
  real_T c57_ye_a;
  real_T c57_yc_b;
  boolean_T c57_y_p;
  real_T c57_yb_mtmp;
  real_T c57_d24;
  int32_T c57_i185;
  int32_T c57_ab_ixstart;
  real_T c57_ac_mtmp;
  real_T c57_ac_x;
  boolean_T c57_ad_b;
  int32_T c57_ad_ix;
  int32_T c57_bd_ix;
  real_T c57_bc_x;
  boolean_T c57_bd_b;
  int32_T c57_af_a;
  int32_T c57_bf_a;
  int32_T c57_i186;
  int32_T c57_cf_a;
  int32_T c57_df_a;
  boolean_T c57_ab_overflow;
  int32_T c57_cd_ix;
  real_T c57_ef_a;
  real_T c57_cd_b;
  boolean_T c57_ab_p;
  real_T c57_bc_mtmp;
  real_T c57_d25;
  int32_T c57_i187;
  int32_T c57_bb_ixstart;
  real_T c57_cc_mtmp;
  real_T c57_cc_x;
  boolean_T c57_dd_b;
  int32_T c57_dd_ix;
  int32_T c57_ed_ix;
  real_T c57_dc_x;
  boolean_T c57_ed_b;
  int32_T c57_ff_a;
  int32_T c57_gf_a;
  int32_T c57_i188;
  int32_T c57_hf_a;
  int32_T c57_if_a;
  boolean_T c57_bb_overflow;
  int32_T c57_fd_ix;
  real_T c57_jf_a;
  real_T c57_fd_b;
  boolean_T c57_bb_p;
  real_T c57_dc_mtmp;
  real_T c57_d26;
  int32_T c57_i189;
  int32_T c57_i190;
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
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 32U, 32U, c57_k_debug_family_names,
    c57_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt_1, 0U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt_1, 1U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt_2, 2U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt_2, 3U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt_3, 4U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt_3, 5U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt_4, 6U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt_4, 7U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt_5, 8U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt_5, 9U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt_6, 10U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt_6, 11U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt_7, 12U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt_7, 13U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt_8, 14U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt_8, 15U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt_9, 16U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt_9, 17U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_LB, 18U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_UB, 19U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt, 20U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_case_n, 21U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargin, 22U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargout, 23U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LS, 24U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LA, 25U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_w, 26U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u1_min, 27U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u1_max, 28U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u2_min, 29U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u2_max, 30U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt, 31U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 30);
  c57_LA_LS_Revised_Saturation_Case_1(chartInstance, c57_u_LS, c57_u_LA, c57_w,
    c57_b_u_opt_1, c57_b_L_opt_1);
  for (c57_i99 = 0; c57_i99 < 2; c57_i99++) {
    c57_u_opt_1[c57_i99] = c57_b_u_opt_1[c57_i99];
  }

  for (c57_i100 = 0; c57_i100 < 4; c57_i100++) {
    c57_L_opt_1[c57_i100] = c57_b_L_opt_1[c57_i100];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 31);
  c57_LA_LS_Revised_Saturation_Case_2(chartInstance, c57_u_LS, c57_u_LA, c57_w,
    c57_u1_min, c57_b_u_opt_1, c57_b_L_opt_1);
  for (c57_i101 = 0; c57_i101 < 2; c57_i101++) {
    c57_u_opt_2[c57_i101] = c57_b_u_opt_1[c57_i101];
  }

  for (c57_i102 = 0; c57_i102 < 4; c57_i102++) {
    c57_L_opt_2[c57_i102] = c57_b_L_opt_1[c57_i102];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 32);
  c57_LA_LS_Revised_Saturation_Case_3(chartInstance, c57_u_LS, c57_u_LA, c57_w,
    c57_u1_max, c57_b_u_opt_1, c57_b_L_opt_1);
  for (c57_i103 = 0; c57_i103 < 2; c57_i103++) {
    c57_u_opt_3[c57_i103] = c57_b_u_opt_1[c57_i103];
  }

  for (c57_i104 = 0; c57_i104 < 4; c57_i104++) {
    c57_L_opt_3[c57_i104] = c57_b_L_opt_1[c57_i104];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 33);
  c57_LA_LS_Revised_Saturation_Case_4(chartInstance, c57_u_LS, c57_u_LA, c57_w,
    c57_u2_min, c57_b_u_opt_1, c57_b_L_opt_1);
  for (c57_i105 = 0; c57_i105 < 2; c57_i105++) {
    c57_u_opt_4[c57_i105] = c57_b_u_opt_1[c57_i105];
  }

  for (c57_i106 = 0; c57_i106 < 4; c57_i106++) {
    c57_L_opt_4[c57_i106] = c57_b_L_opt_1[c57_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 34);
  c57_LA_LS_Revised_Saturation_Case_5(chartInstance, c57_u_LS, c57_u_LA, c57_w,
    c57_u2_max, c57_b_u_opt_1, c57_b_L_opt_1);
  for (c57_i107 = 0; c57_i107 < 2; c57_i107++) {
    c57_u_opt_5[c57_i107] = c57_b_u_opt_1[c57_i107];
  }

  for (c57_i108 = 0; c57_i108 < 4; c57_i108++) {
    c57_L_opt_5[c57_i108] = c57_b_L_opt_1[c57_i108];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 35);
  c57_LA_LS_Revised_Saturation_Case_6(chartInstance, c57_u_LS, c57_u_LA, c57_w,
    c57_u1_min, c57_u2_min, c57_b_u_opt_1, c57_b_L_opt_1);
  for (c57_i109 = 0; c57_i109 < 2; c57_i109++) {
    c57_u_opt_6[c57_i109] = c57_b_u_opt_1[c57_i109];
  }

  for (c57_i110 = 0; c57_i110 < 4; c57_i110++) {
    c57_L_opt_6[c57_i110] = c57_b_L_opt_1[c57_i110];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 36);
  c57_LA_LS_Revised_Saturation_Case_7(chartInstance, c57_u_LS, c57_u_LA, c57_w,
    c57_u1_min, c57_u2_max, c57_b_u_opt_1, c57_b_L_opt_1);
  for (c57_i111 = 0; c57_i111 < 2; c57_i111++) {
    c57_u_opt_7[c57_i111] = c57_b_u_opt_1[c57_i111];
  }

  for (c57_i112 = 0; c57_i112 < 4; c57_i112++) {
    c57_L_opt_7[c57_i112] = c57_b_L_opt_1[c57_i112];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 37);
  c57_LA_LS_Revised_Saturation_Case_8(chartInstance, c57_u_LS, c57_u_LA, c57_w,
    c57_u1_max, c57_u2_min, c57_b_u_opt_1, c57_b_L_opt_1);
  for (c57_i113 = 0; c57_i113 < 2; c57_i113++) {
    c57_u_opt_8[c57_i113] = c57_b_u_opt_1[c57_i113];
  }

  for (c57_i114 = 0; c57_i114 < 4; c57_i114++) {
    c57_L_opt_8[c57_i114] = c57_b_L_opt_1[c57_i114];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 38);
  c57_LA_LS_Revised_Saturation_Case_9(chartInstance, c57_u_LS, c57_u_LA, c57_w,
    c57_u1_max, c57_u2_max, c57_b_u_opt_1, c57_b_L_opt_1);
  for (c57_i115 = 0; c57_i115 < 2; c57_i115++) {
    c57_u_opt_9[c57_i115] = c57_b_u_opt_1[c57_i115];
  }

  for (c57_i116 = 0; c57_i116 < 4; c57_i116++) {
    c57_L_opt_9[c57_i116] = c57_b_L_opt_1[c57_i116];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 41);
  c57_LB[0] = c57_u1_min;
  c57_LB[1] = c57_u2_min;
  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 42);
  c57_UB[0] = c57_u1_max;
  c57_UB[1] = c57_u2_max;
  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 45);
  for (c57_i117 = 0; c57_i117 < 2; c57_i117++) {
    c57_u_opt[c57_i117] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 46);
  for (c57_i118 = 0; c57_i118 < 4; c57_i118++) {
    c57_L_opt[c57_i118] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 47);
  c57_case_n = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 49);
  for (c57_i119 = 0; c57_i119 < 2; c57_i119++) {
    c57_b_u_opt_1[c57_i119] = c57_u_opt_1[c57_i119] - c57_UB[c57_i119];
  }

  c57_ixstart = 1;
  c57_mtmp = c57_b_u_opt_1[0];
  c57_x = c57_mtmp;
  c57_b = muDoubleScalarIsNaN(c57_x);
  if (c57_b) {
    c57_eml_switch_helper(chartInstance);
    c57_eml_switch_helper(chartInstance);
    c57_ix = 2;
    exitg27 = false;
    while ((exitg27 == false) && (c57_ix < 3)) {
      c57_b_ix = c57_ix;
      c57_ixstart = c57_b_ix;
      c57_b_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_b_ix), 1, 2, 1, 0) - 1];
      c57_b_b = muDoubleScalarIsNaN(c57_b_x);
      if (!c57_b_b) {
        c57_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_b_ix), 1, 2, 1, 0) - 1];
        exitg27 = true;
      } else {
        c57_ix++;
      }
    }
  }

  if (c57_ixstart < 2) {
    c57_a = c57_ixstart;
    c57_b_a = c57_a + 1;
    c57_i120 = c57_b_a;
    c57_c_a = c57_i120;
    c57_d_a = c57_c_a;
    if (c57_d_a > 2) {
      c57_overflow = false;
    } else {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_overflow = false;
    }

    if (c57_overflow) {
      c57_check_forloop_overflow_error(chartInstance, c57_overflow);
    }

    for (c57_c_ix = c57_i120; c57_c_ix < 3; c57_c_ix++) {
      c57_b_ix = c57_c_ix;
      c57_e_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_b_ix), 1, 2, 1, 0) - 1];
      c57_c_b = c57_mtmp;
      c57_p = (c57_e_a > c57_c_b);
      if (c57_p) {
        c57_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_b_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c57_b_mtmp = c57_mtmp;
  c57_d0 = c57_b_mtmp;
  guard17 = false;
  guard18 = false;
  if (CV_SCRIPT_COND(0, 0, CV_RELATIONAL_EVAL(14U, 0U, 0, c57_d0, 0.0, -1, 3U,
        c57_d0 <= 0.0))) {
    for (c57_i121 = 0; c57_i121 < 2; c57_i121++) {
      c57_b_u_opt_1[c57_i121] = c57_u_opt_1[c57_i121] - c57_LB[c57_i121];
    }

    c57_b_ixstart = 1;
    c57_c_mtmp = c57_b_u_opt_1[0];
    c57_c_x = c57_c_mtmp;
    c57_d_b = muDoubleScalarIsNaN(c57_c_x);
    if (c57_d_b) {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_d_ix = 2;
      exitg26 = false;
      while ((exitg26 == false) && (c57_d_ix < 3)) {
        c57_e_ix = c57_d_ix;
        c57_b_ixstart = c57_e_ix;
        c57_d_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_e_ix), 1, 2, 1, 0) - 1];
        c57_e_b = muDoubleScalarIsNaN(c57_d_x);
        if (!c57_e_b) {
          c57_c_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_e_ix), 1, 2, 1, 0) - 1];
          exitg26 = true;
        } else {
          c57_d_ix++;
        }
      }
    }

    if (c57_b_ixstart < 2) {
      c57_f_a = c57_b_ixstart;
      c57_g_a = c57_f_a + 1;
      c57_i122 = c57_g_a;
      c57_h_a = c57_i122;
      c57_i_a = c57_h_a;
      if (c57_i_a > 2) {
        c57_b_overflow = false;
      } else {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_b_overflow = false;
      }

      if (c57_b_overflow) {
        c57_check_forloop_overflow_error(chartInstance, c57_b_overflow);
      }

      for (c57_f_ix = c57_i122; c57_f_ix < 3; c57_f_ix++) {
        c57_e_ix = c57_f_ix;
        c57_j_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_e_ix), 1, 2, 1, 0) - 1];
        c57_f_b = c57_c_mtmp;
        c57_b_p = (c57_j_a < c57_f_b);
        if (c57_b_p) {
          c57_c_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_e_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c57_d_mtmp = c57_c_mtmp;
    c57_d1 = c57_d_mtmp;
    if (CV_SCRIPT_COND(0, 1, CV_RELATIONAL_EVAL(14U, 0U, 1, c57_d1, 0.0, -1, 5U,
          c57_d1 >= 0.0))) {
      for (c57_i123 = 0; c57_i123 < 4; c57_i123++) {
        c57_b_L_opt_1[c57_i123] = c57_L_opt_1[c57_i123];
      }

      c57_c_ixstart = 1;
      c57_e_mtmp = c57_b_L_opt_1[0];
      c57_e_x = c57_e_mtmp;
      c57_g_b = muDoubleScalarIsNaN(c57_e_x);
      if (c57_g_b) {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_g_ix = 2;
        exitg25 = false;
        while ((exitg25 == false) && (c57_g_ix < 5)) {
          c57_h_ix = c57_g_ix;
          c57_c_ixstart = c57_h_ix;
          c57_f_x = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_h_ix), 1, 4, 1, 0) - 1];
          c57_h_b = muDoubleScalarIsNaN(c57_f_x);
          if (!c57_h_b) {
            c57_e_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_h_ix), 1, 4, 1, 0) - 1];
            exitg25 = true;
          } else {
            c57_g_ix++;
          }
        }
      }

      if (c57_c_ixstart < 4) {
        c57_k_a = c57_c_ixstart;
        c57_l_a = c57_k_a + 1;
        c57_i124 = c57_l_a;
        c57_m_a = c57_i124;
        c57_n_a = c57_m_a;
        if (c57_n_a > 4) {
          c57_c_overflow = false;
        } else {
          c57_eml_switch_helper(chartInstance);
          c57_eml_switch_helper(chartInstance);
          c57_c_overflow = false;
        }

        if (c57_c_overflow) {
          c57_check_forloop_overflow_error(chartInstance, c57_c_overflow);
        }

        for (c57_i_ix = c57_i124; c57_i_ix < 5; c57_i_ix++) {
          c57_h_ix = c57_i_ix;
          c57_o_a = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_h_ix), 1, 4, 1, 0) - 1];
          c57_i_b = c57_e_mtmp;
          c57_c_p = (c57_o_a < c57_i_b);
          if (c57_c_p) {
            c57_e_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_h_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c57_f_mtmp = c57_e_mtmp;
      c57_d2 = c57_f_mtmp;
      if (CV_SCRIPT_COND(0, 2, CV_RELATIONAL_EVAL(14U, 0U, 2, c57_d2, 0.0, -1,
            5U, c57_d2 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 0, true);
        CV_SCRIPT_IF(0, 0, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 50);
        for (c57_i125 = 0; c57_i125 < 2; c57_i125++) {
          c57_u_opt[c57_i125] = c57_u_opt_1[c57_i125];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 51);
        for (c57_i126 = 0; c57_i126 < 4; c57_i126++) {
          c57_L_opt[c57_i126] = c57_L_opt_1[c57_i126];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 52);
        c57_case_n = 1.0;
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

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 56);
  for (c57_i127 = 0; c57_i127 < 2; c57_i127++) {
    c57_b_u_opt_1[c57_i127] = c57_u_opt_2[c57_i127] - c57_UB[c57_i127];
  }

  c57_d_ixstart = 1;
  c57_g_mtmp = c57_b_u_opt_1[0];
  c57_g_x = c57_g_mtmp;
  c57_j_b = muDoubleScalarIsNaN(c57_g_x);
  if (c57_j_b) {
    c57_eml_switch_helper(chartInstance);
    c57_eml_switch_helper(chartInstance);
    c57_j_ix = 2;
    exitg24 = false;
    while ((exitg24 == false) && (c57_j_ix < 3)) {
      c57_k_ix = c57_j_ix;
      c57_d_ixstart = c57_k_ix;
      c57_h_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_k_ix), 1, 2, 1, 0) - 1];
      c57_k_b = muDoubleScalarIsNaN(c57_h_x);
      if (!c57_k_b) {
        c57_g_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_k_ix), 1, 2, 1, 0) - 1];
        exitg24 = true;
      } else {
        c57_j_ix++;
      }
    }
  }

  if (c57_d_ixstart < 2) {
    c57_p_a = c57_d_ixstart;
    c57_q_a = c57_p_a + 1;
    c57_i128 = c57_q_a;
    c57_r_a = c57_i128;
    c57_s_a = c57_r_a;
    if (c57_s_a > 2) {
      c57_d_overflow = false;
    } else {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_d_overflow = false;
    }

    if (c57_d_overflow) {
      c57_check_forloop_overflow_error(chartInstance, c57_d_overflow);
    }

    for (c57_l_ix = c57_i128; c57_l_ix < 3; c57_l_ix++) {
      c57_k_ix = c57_l_ix;
      c57_t_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_k_ix), 1, 2, 1, 0) - 1];
      c57_l_b = c57_g_mtmp;
      c57_d_p = (c57_t_a > c57_l_b);
      if (c57_d_p) {
        c57_g_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_k_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c57_h_mtmp = c57_g_mtmp;
  c57_d3 = c57_h_mtmp;
  guard15 = false;
  guard16 = false;
  if (CV_SCRIPT_COND(0, 3, CV_RELATIONAL_EVAL(14U, 0U, 3, c57_d3, 0.0, -1, 3U,
        c57_d3 <= 0.0))) {
    for (c57_i129 = 0; c57_i129 < 2; c57_i129++) {
      c57_b_u_opt_1[c57_i129] = c57_u_opt_2[c57_i129] - c57_LB[c57_i129];
    }

    c57_e_ixstart = 1;
    c57_i_mtmp = c57_b_u_opt_1[0];
    c57_i_x = c57_i_mtmp;
    c57_m_b = muDoubleScalarIsNaN(c57_i_x);
    if (c57_m_b) {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_m_ix = 2;
      exitg23 = false;
      while ((exitg23 == false) && (c57_m_ix < 3)) {
        c57_n_ix = c57_m_ix;
        c57_e_ixstart = c57_n_ix;
        c57_j_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_n_ix), 1, 2, 1, 0) - 1];
        c57_n_b = muDoubleScalarIsNaN(c57_j_x);
        if (!c57_n_b) {
          c57_i_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_n_ix), 1, 2, 1, 0) - 1];
          exitg23 = true;
        } else {
          c57_m_ix++;
        }
      }
    }

    if (c57_e_ixstart < 2) {
      c57_u_a = c57_e_ixstart;
      c57_v_a = c57_u_a + 1;
      c57_i130 = c57_v_a;
      c57_w_a = c57_i130;
      c57_x_a = c57_w_a;
      if (c57_x_a > 2) {
        c57_e_overflow = false;
      } else {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_e_overflow = false;
      }

      if (c57_e_overflow) {
        c57_check_forloop_overflow_error(chartInstance, c57_e_overflow);
      }

      for (c57_o_ix = c57_i130; c57_o_ix < 3; c57_o_ix++) {
        c57_n_ix = c57_o_ix;
        c57_y_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_n_ix), 1, 2, 1, 0) - 1];
        c57_o_b = c57_i_mtmp;
        c57_e_p = (c57_y_a < c57_o_b);
        if (c57_e_p) {
          c57_i_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_n_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c57_j_mtmp = c57_i_mtmp;
    c57_d4 = c57_j_mtmp;
    if (CV_SCRIPT_COND(0, 4, CV_RELATIONAL_EVAL(14U, 0U, 4, c57_d4, 0.0, -1, 5U,
          c57_d4 >= 0.0))) {
      for (c57_i131 = 0; c57_i131 < 4; c57_i131++) {
        c57_b_L_opt_1[c57_i131] = c57_L_opt_2[c57_i131];
      }

      c57_f_ixstart = 1;
      c57_k_mtmp = c57_b_L_opt_1[0];
      c57_k_x = c57_k_mtmp;
      c57_p_b = muDoubleScalarIsNaN(c57_k_x);
      if (c57_p_b) {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_p_ix = 2;
        exitg22 = false;
        while ((exitg22 == false) && (c57_p_ix < 5)) {
          c57_q_ix = c57_p_ix;
          c57_f_ixstart = c57_q_ix;
          c57_l_x = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_q_ix), 1, 4, 1, 0) - 1];
          c57_q_b = muDoubleScalarIsNaN(c57_l_x);
          if (!c57_q_b) {
            c57_k_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_q_ix), 1, 4, 1, 0) - 1];
            exitg22 = true;
          } else {
            c57_p_ix++;
          }
        }
      }

      if (c57_f_ixstart < 4) {
        c57_ab_a = c57_f_ixstart;
        c57_bb_a = c57_ab_a + 1;
        c57_i132 = c57_bb_a;
        c57_cb_a = c57_i132;
        c57_db_a = c57_cb_a;
        if (c57_db_a > 4) {
          c57_f_overflow = false;
        } else {
          c57_eml_switch_helper(chartInstance);
          c57_eml_switch_helper(chartInstance);
          c57_f_overflow = false;
        }

        if (c57_f_overflow) {
          c57_check_forloop_overflow_error(chartInstance, c57_f_overflow);
        }

        for (c57_r_ix = c57_i132; c57_r_ix < 5; c57_r_ix++) {
          c57_q_ix = c57_r_ix;
          c57_eb_a = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_q_ix), 1, 4, 1, 0) - 1];
          c57_r_b = c57_k_mtmp;
          c57_f_p = (c57_eb_a < c57_r_b);
          if (c57_f_p) {
            c57_k_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_q_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c57_l_mtmp = c57_k_mtmp;
      c57_d5 = c57_l_mtmp;
      if (CV_SCRIPT_COND(0, 5, CV_RELATIONAL_EVAL(14U, 0U, 5, c57_d5, 0.0, -1,
            5U, c57_d5 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 1, true);
        CV_SCRIPT_IF(0, 1, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 57);
        for (c57_i133 = 0; c57_i133 < 2; c57_i133++) {
          c57_u_opt[c57_i133] = c57_u_opt_2[c57_i133];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 58);
        for (c57_i134 = 0; c57_i134 < 4; c57_i134++) {
          c57_L_opt[c57_i134] = c57_L_opt_2[c57_i134];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 59);
        c57_case_n = 2.0;
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

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 63);
  for (c57_i135 = 0; c57_i135 < 2; c57_i135++) {
    c57_b_u_opt_1[c57_i135] = c57_u_opt_3[c57_i135] - c57_UB[c57_i135];
  }

  c57_g_ixstart = 1;
  c57_m_mtmp = c57_b_u_opt_1[0];
  c57_m_x = c57_m_mtmp;
  c57_s_b = muDoubleScalarIsNaN(c57_m_x);
  if (c57_s_b) {
    c57_eml_switch_helper(chartInstance);
    c57_eml_switch_helper(chartInstance);
    c57_s_ix = 2;
    exitg21 = false;
    while ((exitg21 == false) && (c57_s_ix < 3)) {
      c57_t_ix = c57_s_ix;
      c57_g_ixstart = c57_t_ix;
      c57_n_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_t_ix), 1, 2, 1, 0) - 1];
      c57_t_b = muDoubleScalarIsNaN(c57_n_x);
      if (!c57_t_b) {
        c57_m_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_t_ix), 1, 2, 1, 0) - 1];
        exitg21 = true;
      } else {
        c57_s_ix++;
      }
    }
  }

  if (c57_g_ixstart < 2) {
    c57_fb_a = c57_g_ixstart;
    c57_gb_a = c57_fb_a + 1;
    c57_i136 = c57_gb_a;
    c57_hb_a = c57_i136;
    c57_ib_a = c57_hb_a;
    if (c57_ib_a > 2) {
      c57_g_overflow = false;
    } else {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_g_overflow = false;
    }

    if (c57_g_overflow) {
      c57_check_forloop_overflow_error(chartInstance, c57_g_overflow);
    }

    for (c57_u_ix = c57_i136; c57_u_ix < 3; c57_u_ix++) {
      c57_t_ix = c57_u_ix;
      c57_jb_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_t_ix), 1, 2, 1, 0) - 1];
      c57_u_b = c57_m_mtmp;
      c57_g_p = (c57_jb_a > c57_u_b);
      if (c57_g_p) {
        c57_m_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_t_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c57_n_mtmp = c57_m_mtmp;
  c57_d6 = c57_n_mtmp;
  guard13 = false;
  guard14 = false;
  if (CV_SCRIPT_COND(0, 6, CV_RELATIONAL_EVAL(14U, 0U, 6, c57_d6, 0.0, -1, 3U,
        c57_d6 <= 0.0))) {
    for (c57_i137 = 0; c57_i137 < 2; c57_i137++) {
      c57_b_u_opt_1[c57_i137] = c57_u_opt_3[c57_i137] - c57_LB[c57_i137];
    }

    c57_h_ixstart = 1;
    c57_o_mtmp = c57_b_u_opt_1[0];
    c57_o_x = c57_o_mtmp;
    c57_v_b = muDoubleScalarIsNaN(c57_o_x);
    if (c57_v_b) {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_v_ix = 2;
      exitg20 = false;
      while ((exitg20 == false) && (c57_v_ix < 3)) {
        c57_w_ix = c57_v_ix;
        c57_h_ixstart = c57_w_ix;
        c57_p_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_w_ix), 1, 2, 1, 0) - 1];
        c57_w_b = muDoubleScalarIsNaN(c57_p_x);
        if (!c57_w_b) {
          c57_o_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_w_ix), 1, 2, 1, 0) - 1];
          exitg20 = true;
        } else {
          c57_v_ix++;
        }
      }
    }

    if (c57_h_ixstart < 2) {
      c57_kb_a = c57_h_ixstart;
      c57_lb_a = c57_kb_a + 1;
      c57_i138 = c57_lb_a;
      c57_mb_a = c57_i138;
      c57_nb_a = c57_mb_a;
      if (c57_nb_a > 2) {
        c57_h_overflow = false;
      } else {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_h_overflow = false;
      }

      if (c57_h_overflow) {
        c57_check_forloop_overflow_error(chartInstance, c57_h_overflow);
      }

      for (c57_x_ix = c57_i138; c57_x_ix < 3; c57_x_ix++) {
        c57_w_ix = c57_x_ix;
        c57_ob_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_w_ix), 1, 2, 1, 0) - 1];
        c57_x_b = c57_o_mtmp;
        c57_h_p = (c57_ob_a < c57_x_b);
        if (c57_h_p) {
          c57_o_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_w_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c57_p_mtmp = c57_o_mtmp;
    c57_d7 = c57_p_mtmp;
    if (CV_SCRIPT_COND(0, 7, CV_RELATIONAL_EVAL(14U, 0U, 7, c57_d7, 0.0, -1, 5U,
          c57_d7 >= 0.0))) {
      for (c57_i139 = 0; c57_i139 < 4; c57_i139++) {
        c57_b_L_opt_1[c57_i139] = c57_L_opt_3[c57_i139];
      }

      c57_i_ixstart = 1;
      c57_q_mtmp = c57_b_L_opt_1[0];
      c57_q_x = c57_q_mtmp;
      c57_y_b = muDoubleScalarIsNaN(c57_q_x);
      if (c57_y_b) {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_y_ix = 2;
        exitg19 = false;
        while ((exitg19 == false) && (c57_y_ix < 5)) {
          c57_ab_ix = c57_y_ix;
          c57_i_ixstart = c57_ab_ix;
          c57_r_x = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_ab_ix), 1, 4, 1, 0) - 1];
          c57_ab_b = muDoubleScalarIsNaN(c57_r_x);
          if (!c57_ab_b) {
            c57_q_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_ab_ix), 1, 4, 1, 0) - 1];
            exitg19 = true;
          } else {
            c57_y_ix++;
          }
        }
      }

      if (c57_i_ixstart < 4) {
        c57_pb_a = c57_i_ixstart;
        c57_qb_a = c57_pb_a + 1;
        c57_i140 = c57_qb_a;
        c57_rb_a = c57_i140;
        c57_sb_a = c57_rb_a;
        if (c57_sb_a > 4) {
          c57_i_overflow = false;
        } else {
          c57_eml_switch_helper(chartInstance);
          c57_eml_switch_helper(chartInstance);
          c57_i_overflow = false;
        }

        if (c57_i_overflow) {
          c57_check_forloop_overflow_error(chartInstance, c57_i_overflow);
        }

        for (c57_bb_ix = c57_i140; c57_bb_ix < 5; c57_bb_ix++) {
          c57_ab_ix = c57_bb_ix;
          c57_tb_a = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_ab_ix), 1, 4, 1, 0) - 1];
          c57_bb_b = c57_q_mtmp;
          c57_i_p = (c57_tb_a < c57_bb_b);
          if (c57_i_p) {
            c57_q_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_ab_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c57_r_mtmp = c57_q_mtmp;
      c57_d8 = c57_r_mtmp;
      if (CV_SCRIPT_COND(0, 8, CV_RELATIONAL_EVAL(14U, 0U, 8, c57_d8, 0.0, -1,
            5U, c57_d8 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 2, true);
        CV_SCRIPT_IF(0, 2, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 64);
        for (c57_i141 = 0; c57_i141 < 2; c57_i141++) {
          c57_u_opt[c57_i141] = c57_u_opt_3[c57_i141];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 65);
        for (c57_i142 = 0; c57_i142 < 4; c57_i142++) {
          c57_L_opt[c57_i142] = c57_L_opt_3[c57_i142];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 66);
        c57_case_n = 3.0;
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

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 70);
  for (c57_i143 = 0; c57_i143 < 2; c57_i143++) {
    c57_b_u_opt_1[c57_i143] = c57_u_opt_4[c57_i143] - c57_UB[c57_i143];
  }

  c57_j_ixstart = 1;
  c57_s_mtmp = c57_b_u_opt_1[0];
  c57_s_x = c57_s_mtmp;
  c57_cb_b = muDoubleScalarIsNaN(c57_s_x);
  if (c57_cb_b) {
    c57_eml_switch_helper(chartInstance);
    c57_eml_switch_helper(chartInstance);
    c57_cb_ix = 2;
    exitg18 = false;
    while ((exitg18 == false) && (c57_cb_ix < 3)) {
      c57_db_ix = c57_cb_ix;
      c57_j_ixstart = c57_db_ix;
      c57_t_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_db_ix), 1, 2, 1, 0) - 1];
      c57_db_b = muDoubleScalarIsNaN(c57_t_x);
      if (!c57_db_b) {
        c57_s_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_db_ix), 1, 2, 1, 0) - 1];
        exitg18 = true;
      } else {
        c57_cb_ix++;
      }
    }
  }

  if (c57_j_ixstart < 2) {
    c57_ub_a = c57_j_ixstart;
    c57_vb_a = c57_ub_a + 1;
    c57_i144 = c57_vb_a;
    c57_wb_a = c57_i144;
    c57_xb_a = c57_wb_a;
    if (c57_xb_a > 2) {
      c57_j_overflow = false;
    } else {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_j_overflow = false;
    }

    if (c57_j_overflow) {
      c57_check_forloop_overflow_error(chartInstance, c57_j_overflow);
    }

    for (c57_eb_ix = c57_i144; c57_eb_ix < 3; c57_eb_ix++) {
      c57_db_ix = c57_eb_ix;
      c57_yb_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_db_ix), 1, 2, 1, 0) - 1];
      c57_eb_b = c57_s_mtmp;
      c57_j_p = (c57_yb_a > c57_eb_b);
      if (c57_j_p) {
        c57_s_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_db_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c57_t_mtmp = c57_s_mtmp;
  c57_d9 = c57_t_mtmp;
  guard11 = false;
  guard12 = false;
  if (CV_SCRIPT_COND(0, 9, CV_RELATIONAL_EVAL(14U, 0U, 9, c57_d9, 0.0, -1, 3U,
        c57_d9 <= 0.0))) {
    for (c57_i145 = 0; c57_i145 < 2; c57_i145++) {
      c57_b_u_opt_1[c57_i145] = c57_u_opt_4[c57_i145] - c57_LB[c57_i145];
    }

    c57_k_ixstart = 1;
    c57_u_mtmp = c57_b_u_opt_1[0];
    c57_u_x = c57_u_mtmp;
    c57_fb_b = muDoubleScalarIsNaN(c57_u_x);
    if (c57_fb_b) {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_fb_ix = 2;
      exitg17 = false;
      while ((exitg17 == false) && (c57_fb_ix < 3)) {
        c57_gb_ix = c57_fb_ix;
        c57_k_ixstart = c57_gb_ix;
        c57_v_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_gb_ix), 1, 2, 1, 0) - 1];
        c57_gb_b = muDoubleScalarIsNaN(c57_v_x);
        if (!c57_gb_b) {
          c57_u_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_gb_ix), 1, 2, 1, 0) - 1];
          exitg17 = true;
        } else {
          c57_fb_ix++;
        }
      }
    }

    if (c57_k_ixstart < 2) {
      c57_ac_a = c57_k_ixstart;
      c57_bc_a = c57_ac_a + 1;
      c57_i146 = c57_bc_a;
      c57_cc_a = c57_i146;
      c57_dc_a = c57_cc_a;
      if (c57_dc_a > 2) {
        c57_k_overflow = false;
      } else {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_k_overflow = false;
      }

      if (c57_k_overflow) {
        c57_check_forloop_overflow_error(chartInstance, c57_k_overflow);
      }

      for (c57_hb_ix = c57_i146; c57_hb_ix < 3; c57_hb_ix++) {
        c57_gb_ix = c57_hb_ix;
        c57_ec_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_gb_ix), 1, 2, 1, 0) - 1];
        c57_hb_b = c57_u_mtmp;
        c57_k_p = (c57_ec_a < c57_hb_b);
        if (c57_k_p) {
          c57_u_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_gb_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c57_v_mtmp = c57_u_mtmp;
    c57_d10 = c57_v_mtmp;
    if (CV_SCRIPT_COND(0, 10, CV_RELATIONAL_EVAL(14U, 0U, 10, c57_d10, 0.0, -1,
          5U, c57_d10 >= 0.0))) {
      for (c57_i147 = 0; c57_i147 < 4; c57_i147++) {
        c57_b_L_opt_1[c57_i147] = c57_L_opt_4[c57_i147];
      }

      c57_l_ixstart = 1;
      c57_w_mtmp = c57_b_L_opt_1[0];
      c57_w_x = c57_w_mtmp;
      c57_ib_b = muDoubleScalarIsNaN(c57_w_x);
      if (c57_ib_b) {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_ib_ix = 2;
        exitg16 = false;
        while ((exitg16 == false) && (c57_ib_ix < 5)) {
          c57_jb_ix = c57_ib_ix;
          c57_l_ixstart = c57_jb_ix;
          c57_x_x = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_jb_ix), 1, 4, 1, 0) - 1];
          c57_jb_b = muDoubleScalarIsNaN(c57_x_x);
          if (!c57_jb_b) {
            c57_w_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_jb_ix), 1, 4, 1, 0) - 1];
            exitg16 = true;
          } else {
            c57_ib_ix++;
          }
        }
      }

      if (c57_l_ixstart < 4) {
        c57_fc_a = c57_l_ixstart;
        c57_gc_a = c57_fc_a + 1;
        c57_i148 = c57_gc_a;
        c57_hc_a = c57_i148;
        c57_ic_a = c57_hc_a;
        if (c57_ic_a > 4) {
          c57_l_overflow = false;
        } else {
          c57_eml_switch_helper(chartInstance);
          c57_eml_switch_helper(chartInstance);
          c57_l_overflow = false;
        }

        if (c57_l_overflow) {
          c57_check_forloop_overflow_error(chartInstance, c57_l_overflow);
        }

        for (c57_kb_ix = c57_i148; c57_kb_ix < 5; c57_kb_ix++) {
          c57_jb_ix = c57_kb_ix;
          c57_jc_a = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_jb_ix), 1, 4, 1, 0) - 1];
          c57_kb_b = c57_w_mtmp;
          c57_l_p = (c57_jc_a < c57_kb_b);
          if (c57_l_p) {
            c57_w_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_jb_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c57_x_mtmp = c57_w_mtmp;
      c57_d11 = c57_x_mtmp;
      if (CV_SCRIPT_COND(0, 11, CV_RELATIONAL_EVAL(14U, 0U, 11, c57_d11, 0.0, -1,
            5U, c57_d11 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 3, true);
        CV_SCRIPT_IF(0, 3, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 71);
        for (c57_i149 = 0; c57_i149 < 2; c57_i149++) {
          c57_u_opt[c57_i149] = c57_u_opt_4[c57_i149];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 72);
        for (c57_i150 = 0; c57_i150 < 4; c57_i150++) {
          c57_L_opt[c57_i150] = c57_L_opt_4[c57_i150];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 73);
        c57_case_n = 4.0;
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

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 77);
  for (c57_i151 = 0; c57_i151 < 2; c57_i151++) {
    c57_b_u_opt_1[c57_i151] = c57_u_opt_5[c57_i151] - c57_UB[c57_i151];
  }

  c57_m_ixstart = 1;
  c57_y_mtmp = c57_b_u_opt_1[0];
  c57_y_x = c57_y_mtmp;
  c57_lb_b = muDoubleScalarIsNaN(c57_y_x);
  if (c57_lb_b) {
    c57_eml_switch_helper(chartInstance);
    c57_eml_switch_helper(chartInstance);
    c57_lb_ix = 2;
    exitg15 = false;
    while ((exitg15 == false) && (c57_lb_ix < 3)) {
      c57_mb_ix = c57_lb_ix;
      c57_m_ixstart = c57_mb_ix;
      c57_ab_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_mb_ix), 1, 2, 1, 0) - 1];
      c57_mb_b = muDoubleScalarIsNaN(c57_ab_x);
      if (!c57_mb_b) {
        c57_y_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_mb_ix), 1, 2, 1, 0) - 1];
        exitg15 = true;
      } else {
        c57_lb_ix++;
      }
    }
  }

  if (c57_m_ixstart < 2) {
    c57_kc_a = c57_m_ixstart;
    c57_lc_a = c57_kc_a + 1;
    c57_i152 = c57_lc_a;
    c57_mc_a = c57_i152;
    c57_nc_a = c57_mc_a;
    if (c57_nc_a > 2) {
      c57_m_overflow = false;
    } else {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_m_overflow = false;
    }

    if (c57_m_overflow) {
      c57_check_forloop_overflow_error(chartInstance, c57_m_overflow);
    }

    for (c57_nb_ix = c57_i152; c57_nb_ix < 3; c57_nb_ix++) {
      c57_mb_ix = c57_nb_ix;
      c57_oc_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_mb_ix), 1, 2, 1, 0) - 1];
      c57_nb_b = c57_y_mtmp;
      c57_m_p = (c57_oc_a > c57_nb_b);
      if (c57_m_p) {
        c57_y_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_mb_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c57_ab_mtmp = c57_y_mtmp;
  c57_d12 = c57_ab_mtmp;
  guard9 = false;
  guard10 = false;
  if (CV_SCRIPT_COND(0, 12, CV_RELATIONAL_EVAL(14U, 0U, 12, c57_d12, 0.0, -1, 3U,
        c57_d12 <= 0.0))) {
    for (c57_i153 = 0; c57_i153 < 2; c57_i153++) {
      c57_b_u_opt_1[c57_i153] = c57_u_opt_5[c57_i153] - c57_LB[c57_i153];
    }

    c57_n_ixstart = 1;
    c57_bb_mtmp = c57_b_u_opt_1[0];
    c57_bb_x = c57_bb_mtmp;
    c57_ob_b = muDoubleScalarIsNaN(c57_bb_x);
    if (c57_ob_b) {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_ob_ix = 2;
      exitg14 = false;
      while ((exitg14 == false) && (c57_ob_ix < 3)) {
        c57_pb_ix = c57_ob_ix;
        c57_n_ixstart = c57_pb_ix;
        c57_cb_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_pb_ix), 1, 2, 1, 0) - 1];
        c57_pb_b = muDoubleScalarIsNaN(c57_cb_x);
        if (!c57_pb_b) {
          c57_bb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_pb_ix), 1, 2, 1, 0) - 1];
          exitg14 = true;
        } else {
          c57_ob_ix++;
        }
      }
    }

    if (c57_n_ixstart < 2) {
      c57_pc_a = c57_n_ixstart;
      c57_qc_a = c57_pc_a + 1;
      c57_i154 = c57_qc_a;
      c57_rc_a = c57_i154;
      c57_sc_a = c57_rc_a;
      if (c57_sc_a > 2) {
        c57_n_overflow = false;
      } else {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_n_overflow = false;
      }

      if (c57_n_overflow) {
        c57_check_forloop_overflow_error(chartInstance, c57_n_overflow);
      }

      for (c57_qb_ix = c57_i154; c57_qb_ix < 3; c57_qb_ix++) {
        c57_pb_ix = c57_qb_ix;
        c57_tc_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_pb_ix), 1, 2, 1, 0) - 1];
        c57_qb_b = c57_bb_mtmp;
        c57_n_p = (c57_tc_a < c57_qb_b);
        if (c57_n_p) {
          c57_bb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_pb_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c57_cb_mtmp = c57_bb_mtmp;
    c57_d13 = c57_cb_mtmp;
    if (CV_SCRIPT_COND(0, 13, CV_RELATIONAL_EVAL(14U, 0U, 13, c57_d13, 0.0, -1,
          5U, c57_d13 >= 0.0))) {
      for (c57_i155 = 0; c57_i155 < 4; c57_i155++) {
        c57_b_L_opt_1[c57_i155] = c57_L_opt_5[c57_i155];
      }

      c57_o_ixstart = 1;
      c57_db_mtmp = c57_b_L_opt_1[0];
      c57_db_x = c57_db_mtmp;
      c57_rb_b = muDoubleScalarIsNaN(c57_db_x);
      if (c57_rb_b) {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_rb_ix = 2;
        exitg13 = false;
        while ((exitg13 == false) && (c57_rb_ix < 5)) {
          c57_sb_ix = c57_rb_ix;
          c57_o_ixstart = c57_sb_ix;
          c57_eb_x = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_sb_ix), 1, 4, 1, 0) - 1];
          c57_sb_b = muDoubleScalarIsNaN(c57_eb_x);
          if (!c57_sb_b) {
            c57_db_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_sb_ix), 1, 4, 1, 0) - 1];
            exitg13 = true;
          } else {
            c57_rb_ix++;
          }
        }
      }

      if (c57_o_ixstart < 4) {
        c57_uc_a = c57_o_ixstart;
        c57_vc_a = c57_uc_a + 1;
        c57_i156 = c57_vc_a;
        c57_wc_a = c57_i156;
        c57_xc_a = c57_wc_a;
        if (c57_xc_a > 4) {
          c57_o_overflow = false;
        } else {
          c57_eml_switch_helper(chartInstance);
          c57_eml_switch_helper(chartInstance);
          c57_o_overflow = false;
        }

        if (c57_o_overflow) {
          c57_check_forloop_overflow_error(chartInstance, c57_o_overflow);
        }

        for (c57_tb_ix = c57_i156; c57_tb_ix < 5; c57_tb_ix++) {
          c57_sb_ix = c57_tb_ix;
          c57_yc_a = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_sb_ix), 1, 4, 1, 0) - 1];
          c57_tb_b = c57_db_mtmp;
          c57_o_p = (c57_yc_a < c57_tb_b);
          if (c57_o_p) {
            c57_db_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_sb_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c57_eb_mtmp = c57_db_mtmp;
      c57_d14 = c57_eb_mtmp;
      if (CV_SCRIPT_COND(0, 14, CV_RELATIONAL_EVAL(14U, 0U, 14, c57_d14, 0.0, -1,
            5U, c57_d14 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 4, true);
        CV_SCRIPT_IF(0, 4, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 78);
        for (c57_i157 = 0; c57_i157 < 2; c57_i157++) {
          c57_u_opt[c57_i157] = c57_u_opt_5[c57_i157];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 79);
        for (c57_i158 = 0; c57_i158 < 4; c57_i158++) {
          c57_L_opt[c57_i158] = c57_L_opt_5[c57_i158];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 80);
        c57_case_n = 5.0;
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

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 84);
  for (c57_i159 = 0; c57_i159 < 2; c57_i159++) {
    c57_b_u_opt_1[c57_i159] = c57_u_opt_6[c57_i159] - c57_UB[c57_i159];
  }

  c57_p_ixstart = 1;
  c57_fb_mtmp = c57_b_u_opt_1[0];
  c57_fb_x = c57_fb_mtmp;
  c57_ub_b = muDoubleScalarIsNaN(c57_fb_x);
  if (c57_ub_b) {
    c57_eml_switch_helper(chartInstance);
    c57_eml_switch_helper(chartInstance);
    c57_ub_ix = 2;
    exitg12 = false;
    while ((exitg12 == false) && (c57_ub_ix < 3)) {
      c57_vb_ix = c57_ub_ix;
      c57_p_ixstart = c57_vb_ix;
      c57_gb_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_vb_ix), 1, 2, 1, 0) - 1];
      c57_vb_b = muDoubleScalarIsNaN(c57_gb_x);
      if (!c57_vb_b) {
        c57_fb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_vb_ix), 1, 2, 1, 0) - 1];
        exitg12 = true;
      } else {
        c57_ub_ix++;
      }
    }
  }

  if (c57_p_ixstart < 2) {
    c57_ad_a = c57_p_ixstart;
    c57_bd_a = c57_ad_a + 1;
    c57_i160 = c57_bd_a;
    c57_cd_a = c57_i160;
    c57_dd_a = c57_cd_a;
    if (c57_dd_a > 2) {
      c57_p_overflow = false;
    } else {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_p_overflow = false;
    }

    if (c57_p_overflow) {
      c57_check_forloop_overflow_error(chartInstance, c57_p_overflow);
    }

    for (c57_wb_ix = c57_i160; c57_wb_ix < 3; c57_wb_ix++) {
      c57_vb_ix = c57_wb_ix;
      c57_ed_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_vb_ix), 1, 2, 1, 0) - 1];
      c57_wb_b = c57_fb_mtmp;
      c57_p_p = (c57_ed_a > c57_wb_b);
      if (c57_p_p) {
        c57_fb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_vb_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c57_gb_mtmp = c57_fb_mtmp;
  c57_d15 = c57_gb_mtmp;
  guard7 = false;
  guard8 = false;
  if (CV_SCRIPT_COND(0, 15, CV_RELATIONAL_EVAL(14U, 0U, 15, c57_d15, 0.0, -1, 3U,
        c57_d15 <= 0.0))) {
    for (c57_i161 = 0; c57_i161 < 2; c57_i161++) {
      c57_b_u_opt_1[c57_i161] = c57_u_opt_6[c57_i161] - c57_LB[c57_i161];
    }

    c57_q_ixstart = 1;
    c57_hb_mtmp = c57_b_u_opt_1[0];
    c57_hb_x = c57_hb_mtmp;
    c57_xb_b = muDoubleScalarIsNaN(c57_hb_x);
    if (c57_xb_b) {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_xb_ix = 2;
      exitg11 = false;
      while ((exitg11 == false) && (c57_xb_ix < 3)) {
        c57_yb_ix = c57_xb_ix;
        c57_q_ixstart = c57_yb_ix;
        c57_ib_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_yb_ix), 1, 2, 1, 0) - 1];
        c57_yb_b = muDoubleScalarIsNaN(c57_ib_x);
        if (!c57_yb_b) {
          c57_hb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_yb_ix), 1, 2, 1, 0) - 1];
          exitg11 = true;
        } else {
          c57_xb_ix++;
        }
      }
    }

    if (c57_q_ixstart < 2) {
      c57_fd_a = c57_q_ixstart;
      c57_gd_a = c57_fd_a + 1;
      c57_i162 = c57_gd_a;
      c57_hd_a = c57_i162;
      c57_id_a = c57_hd_a;
      if (c57_id_a > 2) {
        c57_q_overflow = false;
      } else {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_q_overflow = false;
      }

      if (c57_q_overflow) {
        c57_check_forloop_overflow_error(chartInstance, c57_q_overflow);
      }

      for (c57_ac_ix = c57_i162; c57_ac_ix < 3; c57_ac_ix++) {
        c57_yb_ix = c57_ac_ix;
        c57_jd_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_yb_ix), 1, 2, 1, 0) - 1];
        c57_ac_b = c57_hb_mtmp;
        c57_q_p = (c57_jd_a < c57_ac_b);
        if (c57_q_p) {
          c57_hb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_yb_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c57_ib_mtmp = c57_hb_mtmp;
    c57_d16 = c57_ib_mtmp;
    if (CV_SCRIPT_COND(0, 16, CV_RELATIONAL_EVAL(14U, 0U, 16, c57_d16, 0.0, -1,
          5U, c57_d16 >= 0.0))) {
      for (c57_i163 = 0; c57_i163 < 4; c57_i163++) {
        c57_b_L_opt_1[c57_i163] = c57_L_opt_6[c57_i163];
      }

      c57_r_ixstart = 1;
      c57_jb_mtmp = c57_b_L_opt_1[0];
      c57_jb_x = c57_jb_mtmp;
      c57_bc_b = muDoubleScalarIsNaN(c57_jb_x);
      if (c57_bc_b) {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_bc_ix = 2;
        exitg10 = false;
        while ((exitg10 == false) && (c57_bc_ix < 5)) {
          c57_cc_ix = c57_bc_ix;
          c57_r_ixstart = c57_cc_ix;
          c57_kb_x = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_cc_ix), 1, 4, 1, 0) - 1];
          c57_cc_b = muDoubleScalarIsNaN(c57_kb_x);
          if (!c57_cc_b) {
            c57_jb_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_cc_ix), 1, 4, 1, 0) - 1];
            exitg10 = true;
          } else {
            c57_bc_ix++;
          }
        }
      }

      if (c57_r_ixstart < 4) {
        c57_kd_a = c57_r_ixstart;
        c57_ld_a = c57_kd_a + 1;
        c57_i164 = c57_ld_a;
        c57_md_a = c57_i164;
        c57_nd_a = c57_md_a;
        if (c57_nd_a > 4) {
          c57_r_overflow = false;
        } else {
          c57_eml_switch_helper(chartInstance);
          c57_eml_switch_helper(chartInstance);
          c57_r_overflow = false;
        }

        if (c57_r_overflow) {
          c57_check_forloop_overflow_error(chartInstance, c57_r_overflow);
        }

        for (c57_dc_ix = c57_i164; c57_dc_ix < 5; c57_dc_ix++) {
          c57_cc_ix = c57_dc_ix;
          c57_od_a = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_cc_ix), 1, 4, 1, 0) - 1];
          c57_dc_b = c57_jb_mtmp;
          c57_r_p = (c57_od_a < c57_dc_b);
          if (c57_r_p) {
            c57_jb_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_cc_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c57_kb_mtmp = c57_jb_mtmp;
      c57_d17 = c57_kb_mtmp;
      if (CV_SCRIPT_COND(0, 17, CV_RELATIONAL_EVAL(14U, 0U, 17, c57_d17, 0.0, -1,
            5U, c57_d17 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 5, true);
        CV_SCRIPT_IF(0, 5, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 85);
        for (c57_i165 = 0; c57_i165 < 2; c57_i165++) {
          c57_u_opt[c57_i165] = c57_u_opt_6[c57_i165];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 86);
        for (c57_i166 = 0; c57_i166 < 4; c57_i166++) {
          c57_L_opt[c57_i166] = c57_L_opt_6[c57_i166];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 87);
        c57_case_n = 6.0;
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

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 91);
  for (c57_i167 = 0; c57_i167 < 2; c57_i167++) {
    c57_b_u_opt_1[c57_i167] = c57_u_opt_7[c57_i167] - c57_UB[c57_i167];
  }

  c57_s_ixstart = 1;
  c57_lb_mtmp = c57_b_u_opt_1[0];
  c57_lb_x = c57_lb_mtmp;
  c57_ec_b = muDoubleScalarIsNaN(c57_lb_x);
  if (c57_ec_b) {
    c57_eml_switch_helper(chartInstance);
    c57_eml_switch_helper(chartInstance);
    c57_ec_ix = 2;
    exitg9 = false;
    while ((exitg9 == false) && (c57_ec_ix < 3)) {
      c57_fc_ix = c57_ec_ix;
      c57_s_ixstart = c57_fc_ix;
      c57_mb_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_fc_ix), 1, 2, 1, 0) - 1];
      c57_fc_b = muDoubleScalarIsNaN(c57_mb_x);
      if (!c57_fc_b) {
        c57_lb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_fc_ix), 1, 2, 1, 0) - 1];
        exitg9 = true;
      } else {
        c57_ec_ix++;
      }
    }
  }

  if (c57_s_ixstart < 2) {
    c57_pd_a = c57_s_ixstart;
    c57_qd_a = c57_pd_a + 1;
    c57_i168 = c57_qd_a;
    c57_rd_a = c57_i168;
    c57_sd_a = c57_rd_a;
    if (c57_sd_a > 2) {
      c57_s_overflow = false;
    } else {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_s_overflow = false;
    }

    if (c57_s_overflow) {
      c57_check_forloop_overflow_error(chartInstance, c57_s_overflow);
    }

    for (c57_gc_ix = c57_i168; c57_gc_ix < 3; c57_gc_ix++) {
      c57_fc_ix = c57_gc_ix;
      c57_td_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_fc_ix), 1, 2, 1, 0) - 1];
      c57_gc_b = c57_lb_mtmp;
      c57_s_p = (c57_td_a > c57_gc_b);
      if (c57_s_p) {
        c57_lb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_fc_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c57_mb_mtmp = c57_lb_mtmp;
  c57_d18 = c57_mb_mtmp;
  guard5 = false;
  guard6 = false;
  if (CV_SCRIPT_COND(0, 18, CV_RELATIONAL_EVAL(14U, 0U, 18, c57_d18, 0.0, -1, 3U,
        c57_d18 <= 0.0))) {
    for (c57_i169 = 0; c57_i169 < 2; c57_i169++) {
      c57_b_u_opt_1[c57_i169] = c57_u_opt_7[c57_i169] - c57_LB[c57_i169];
    }

    c57_t_ixstart = 1;
    c57_nb_mtmp = c57_b_u_opt_1[0];
    c57_nb_x = c57_nb_mtmp;
    c57_hc_b = muDoubleScalarIsNaN(c57_nb_x);
    if (c57_hc_b) {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_hc_ix = 2;
      exitg8 = false;
      while ((exitg8 == false) && (c57_hc_ix < 3)) {
        c57_ic_ix = c57_hc_ix;
        c57_t_ixstart = c57_ic_ix;
        c57_ob_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_ic_ix), 1, 2, 1, 0) - 1];
        c57_ic_b = muDoubleScalarIsNaN(c57_ob_x);
        if (!c57_ic_b) {
          c57_nb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_ic_ix), 1, 2, 1, 0) - 1];
          exitg8 = true;
        } else {
          c57_hc_ix++;
        }
      }
    }

    if (c57_t_ixstart < 2) {
      c57_ud_a = c57_t_ixstart;
      c57_vd_a = c57_ud_a + 1;
      c57_i170 = c57_vd_a;
      c57_wd_a = c57_i170;
      c57_xd_a = c57_wd_a;
      if (c57_xd_a > 2) {
        c57_t_overflow = false;
      } else {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_t_overflow = false;
      }

      if (c57_t_overflow) {
        c57_check_forloop_overflow_error(chartInstance, c57_t_overflow);
      }

      for (c57_jc_ix = c57_i170; c57_jc_ix < 3; c57_jc_ix++) {
        c57_ic_ix = c57_jc_ix;
        c57_yd_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_ic_ix), 1, 2, 1, 0) - 1];
        c57_jc_b = c57_nb_mtmp;
        c57_t_p = (c57_yd_a < c57_jc_b);
        if (c57_t_p) {
          c57_nb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_ic_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c57_ob_mtmp = c57_nb_mtmp;
    c57_d19 = c57_ob_mtmp;
    if (CV_SCRIPT_COND(0, 19, CV_RELATIONAL_EVAL(14U, 0U, 19, c57_d19, 0.0, -1,
          5U, c57_d19 >= 0.0))) {
      for (c57_i171 = 0; c57_i171 < 4; c57_i171++) {
        c57_b_L_opt_1[c57_i171] = c57_L_opt_7[c57_i171];
      }

      c57_u_ixstart = 1;
      c57_pb_mtmp = c57_b_L_opt_1[0];
      c57_pb_x = c57_pb_mtmp;
      c57_kc_b = muDoubleScalarIsNaN(c57_pb_x);
      if (c57_kc_b) {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_kc_ix = 2;
        exitg7 = false;
        while ((exitg7 == false) && (c57_kc_ix < 5)) {
          c57_lc_ix = c57_kc_ix;
          c57_u_ixstart = c57_lc_ix;
          c57_qb_x = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_lc_ix), 1, 4, 1, 0) - 1];
          c57_lc_b = muDoubleScalarIsNaN(c57_qb_x);
          if (!c57_lc_b) {
            c57_pb_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_lc_ix), 1, 4, 1, 0) - 1];
            exitg7 = true;
          } else {
            c57_kc_ix++;
          }
        }
      }

      if (c57_u_ixstart < 4) {
        c57_ae_a = c57_u_ixstart;
        c57_be_a = c57_ae_a + 1;
        c57_i172 = c57_be_a;
        c57_ce_a = c57_i172;
        c57_de_a = c57_ce_a;
        if (c57_de_a > 4) {
          c57_u_overflow = false;
        } else {
          c57_eml_switch_helper(chartInstance);
          c57_eml_switch_helper(chartInstance);
          c57_u_overflow = false;
        }

        if (c57_u_overflow) {
          c57_check_forloop_overflow_error(chartInstance, c57_u_overflow);
        }

        for (c57_mc_ix = c57_i172; c57_mc_ix < 5; c57_mc_ix++) {
          c57_lc_ix = c57_mc_ix;
          c57_ee_a = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_lc_ix), 1, 4, 1, 0) - 1];
          c57_mc_b = c57_pb_mtmp;
          c57_u_p = (c57_ee_a < c57_mc_b);
          if (c57_u_p) {
            c57_pb_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_lc_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c57_qb_mtmp = c57_pb_mtmp;
      c57_d20 = c57_qb_mtmp;
      if (CV_SCRIPT_COND(0, 20, CV_RELATIONAL_EVAL(14U, 0U, 20, c57_d20, 0.0, -1,
            5U, c57_d20 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 6, true);
        CV_SCRIPT_IF(0, 6, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 92);
        for (c57_i173 = 0; c57_i173 < 2; c57_i173++) {
          c57_u_opt[c57_i173] = c57_u_opt_7[c57_i173];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 93);
        for (c57_i174 = 0; c57_i174 < 4; c57_i174++) {
          c57_L_opt[c57_i174] = c57_L_opt_7[c57_i174];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 94);
        c57_case_n = 7.0;
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

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 98);
  for (c57_i175 = 0; c57_i175 < 2; c57_i175++) {
    c57_b_u_opt_1[c57_i175] = c57_u_opt_8[c57_i175] - c57_UB[c57_i175];
  }

  c57_v_ixstart = 1;
  c57_rb_mtmp = c57_b_u_opt_1[0];
  c57_rb_x = c57_rb_mtmp;
  c57_nc_b = muDoubleScalarIsNaN(c57_rb_x);
  if (c57_nc_b) {
    c57_eml_switch_helper(chartInstance);
    c57_eml_switch_helper(chartInstance);
    c57_nc_ix = 2;
    exitg6 = false;
    while ((exitg6 == false) && (c57_nc_ix < 3)) {
      c57_oc_ix = c57_nc_ix;
      c57_v_ixstart = c57_oc_ix;
      c57_sb_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_oc_ix), 1, 2, 1, 0) - 1];
      c57_oc_b = muDoubleScalarIsNaN(c57_sb_x);
      if (!c57_oc_b) {
        c57_rb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_oc_ix), 1, 2, 1, 0) - 1];
        exitg6 = true;
      } else {
        c57_nc_ix++;
      }
    }
  }

  if (c57_v_ixstart < 2) {
    c57_fe_a = c57_v_ixstart;
    c57_ge_a = c57_fe_a + 1;
    c57_i176 = c57_ge_a;
    c57_he_a = c57_i176;
    c57_ie_a = c57_he_a;
    if (c57_ie_a > 2) {
      c57_v_overflow = false;
    } else {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_v_overflow = false;
    }

    if (c57_v_overflow) {
      c57_check_forloop_overflow_error(chartInstance, c57_v_overflow);
    }

    for (c57_pc_ix = c57_i176; c57_pc_ix < 3; c57_pc_ix++) {
      c57_oc_ix = c57_pc_ix;
      c57_je_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_oc_ix), 1, 2, 1, 0) - 1];
      c57_pc_b = c57_rb_mtmp;
      c57_v_p = (c57_je_a > c57_pc_b);
      if (c57_v_p) {
        c57_rb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_oc_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c57_sb_mtmp = c57_rb_mtmp;
  c57_d21 = c57_sb_mtmp;
  guard3 = false;
  guard4 = false;
  if (CV_SCRIPT_COND(0, 21, CV_RELATIONAL_EVAL(14U, 0U, 21, c57_d21, 0.0, -1, 3U,
        c57_d21 <= 0.0))) {
    for (c57_i177 = 0; c57_i177 < 2; c57_i177++) {
      c57_b_u_opt_1[c57_i177] = c57_u_opt_8[c57_i177] - c57_LB[c57_i177];
    }

    c57_w_ixstart = 1;
    c57_tb_mtmp = c57_b_u_opt_1[0];
    c57_tb_x = c57_tb_mtmp;
    c57_qc_b = muDoubleScalarIsNaN(c57_tb_x);
    if (c57_qc_b) {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_qc_ix = 2;
      exitg5 = false;
      while ((exitg5 == false) && (c57_qc_ix < 3)) {
        c57_rc_ix = c57_qc_ix;
        c57_w_ixstart = c57_rc_ix;
        c57_ub_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_rc_ix), 1, 2, 1, 0) - 1];
        c57_rc_b = muDoubleScalarIsNaN(c57_ub_x);
        if (!c57_rc_b) {
          c57_tb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_rc_ix), 1, 2, 1, 0) - 1];
          exitg5 = true;
        } else {
          c57_qc_ix++;
        }
      }
    }

    if (c57_w_ixstart < 2) {
      c57_ke_a = c57_w_ixstart;
      c57_le_a = c57_ke_a + 1;
      c57_i178 = c57_le_a;
      c57_me_a = c57_i178;
      c57_ne_a = c57_me_a;
      if (c57_ne_a > 2) {
        c57_w_overflow = false;
      } else {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_w_overflow = false;
      }

      if (c57_w_overflow) {
        c57_check_forloop_overflow_error(chartInstance, c57_w_overflow);
      }

      for (c57_sc_ix = c57_i178; c57_sc_ix < 3; c57_sc_ix++) {
        c57_rc_ix = c57_sc_ix;
        c57_oe_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_rc_ix), 1, 2, 1, 0) - 1];
        c57_sc_b = c57_tb_mtmp;
        c57_w_p = (c57_oe_a < c57_sc_b);
        if (c57_w_p) {
          c57_tb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_rc_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c57_ub_mtmp = c57_tb_mtmp;
    c57_d22 = c57_ub_mtmp;
    if (CV_SCRIPT_COND(0, 22, CV_RELATIONAL_EVAL(14U, 0U, 22, c57_d22, 0.0, -1,
          5U, c57_d22 >= 0.0))) {
      for (c57_i179 = 0; c57_i179 < 4; c57_i179++) {
        c57_b_L_opt_1[c57_i179] = c57_L_opt_8[c57_i179];
      }

      c57_x_ixstart = 1;
      c57_vb_mtmp = c57_b_L_opt_1[0];
      c57_vb_x = c57_vb_mtmp;
      c57_tc_b = muDoubleScalarIsNaN(c57_vb_x);
      if (c57_tc_b) {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_tc_ix = 2;
        exitg4 = false;
        while ((exitg4 == false) && (c57_tc_ix < 5)) {
          c57_uc_ix = c57_tc_ix;
          c57_x_ixstart = c57_uc_ix;
          c57_wb_x = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_uc_ix), 1, 4, 1, 0) - 1];
          c57_uc_b = muDoubleScalarIsNaN(c57_wb_x);
          if (!c57_uc_b) {
            c57_vb_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_uc_ix), 1, 4, 1, 0) - 1];
            exitg4 = true;
          } else {
            c57_tc_ix++;
          }
        }
      }

      if (c57_x_ixstart < 4) {
        c57_pe_a = c57_x_ixstart;
        c57_qe_a = c57_pe_a + 1;
        c57_i180 = c57_qe_a;
        c57_re_a = c57_i180;
        c57_se_a = c57_re_a;
        if (c57_se_a > 4) {
          c57_x_overflow = false;
        } else {
          c57_eml_switch_helper(chartInstance);
          c57_eml_switch_helper(chartInstance);
          c57_x_overflow = false;
        }

        if (c57_x_overflow) {
          c57_check_forloop_overflow_error(chartInstance, c57_x_overflow);
        }

        for (c57_vc_ix = c57_i180; c57_vc_ix < 5; c57_vc_ix++) {
          c57_uc_ix = c57_vc_ix;
          c57_te_a = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_uc_ix), 1, 4, 1, 0) - 1];
          c57_vc_b = c57_vb_mtmp;
          c57_x_p = (c57_te_a < c57_vc_b);
          if (c57_x_p) {
            c57_vb_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_uc_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c57_wb_mtmp = c57_vb_mtmp;
      c57_d23 = c57_wb_mtmp;
      if (CV_SCRIPT_COND(0, 23, CV_RELATIONAL_EVAL(14U, 0U, 23, c57_d23, 0.0, -1,
            5U, c57_d23 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 7, true);
        CV_SCRIPT_IF(0, 7, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 99);
        for (c57_i181 = 0; c57_i181 < 2; c57_i181++) {
          c57_u_opt[c57_i181] = c57_u_opt_8[c57_i181];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 100);
        for (c57_i182 = 0; c57_i182 < 4; c57_i182++) {
          c57_L_opt[c57_i182] = c57_L_opt_8[c57_i182];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 101);
        c57_case_n = 8.0;
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

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 105);
  for (c57_i183 = 0; c57_i183 < 2; c57_i183++) {
    c57_b_u_opt_1[c57_i183] = c57_u_opt_9[c57_i183] - c57_UB[c57_i183];
  }

  c57_y_ixstart = 1;
  c57_xb_mtmp = c57_b_u_opt_1[0];
  c57_xb_x = c57_xb_mtmp;
  c57_wc_b = muDoubleScalarIsNaN(c57_xb_x);
  if (c57_wc_b) {
    c57_eml_switch_helper(chartInstance);
    c57_eml_switch_helper(chartInstance);
    c57_wc_ix = 2;
    exitg3 = false;
    while ((exitg3 == false) && (c57_wc_ix < 3)) {
      c57_xc_ix = c57_wc_ix;
      c57_y_ixstart = c57_xc_ix;
      c57_yb_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_xc_ix), 1, 2, 1, 0) - 1];
      c57_xc_b = muDoubleScalarIsNaN(c57_yb_x);
      if (!c57_xc_b) {
        c57_xb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_xc_ix), 1, 2, 1, 0) - 1];
        exitg3 = true;
      } else {
        c57_wc_ix++;
      }
    }
  }

  if (c57_y_ixstart < 2) {
    c57_ue_a = c57_y_ixstart;
    c57_ve_a = c57_ue_a + 1;
    c57_i184 = c57_ve_a;
    c57_we_a = c57_i184;
    c57_xe_a = c57_we_a;
    if (c57_xe_a > 2) {
      c57_y_overflow = false;
    } else {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_y_overflow = false;
    }

    if (c57_y_overflow) {
      c57_check_forloop_overflow_error(chartInstance, c57_y_overflow);
    }

    for (c57_yc_ix = c57_i184; c57_yc_ix < 3; c57_yc_ix++) {
      c57_xc_ix = c57_yc_ix;
      c57_ye_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_xc_ix), 1, 2, 1, 0) - 1];
      c57_yc_b = c57_xb_mtmp;
      c57_y_p = (c57_ye_a > c57_yc_b);
      if (c57_y_p) {
        c57_xb_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_xc_ix), 1, 2, 1, 0) - 1];
      }
    }
  }

  c57_yb_mtmp = c57_xb_mtmp;
  c57_d24 = c57_yb_mtmp;
  guard1 = false;
  guard2 = false;
  if (CV_SCRIPT_COND(0, 24, CV_RELATIONAL_EVAL(14U, 0U, 24, c57_d24, 0.0, -1, 3U,
        c57_d24 <= 0.0))) {
    for (c57_i185 = 0; c57_i185 < 2; c57_i185++) {
      c57_b_u_opt_1[c57_i185] = c57_u_opt_9[c57_i185] - c57_LB[c57_i185];
    }

    c57_ab_ixstart = 1;
    c57_ac_mtmp = c57_b_u_opt_1[0];
    c57_ac_x = c57_ac_mtmp;
    c57_ad_b = muDoubleScalarIsNaN(c57_ac_x);
    if (c57_ad_b) {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_ad_ix = 2;
      exitg2 = false;
      while ((exitg2 == false) && (c57_ad_ix < 3)) {
        c57_bd_ix = c57_ad_ix;
        c57_ab_ixstart = c57_bd_ix;
        c57_bc_x = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_bd_ix), 1, 2, 1, 0) - 1];
        c57_bd_b = muDoubleScalarIsNaN(c57_bc_x);
        if (!c57_bd_b) {
          c57_ac_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_bd_ix), 1, 2, 1, 0) - 1];
          exitg2 = true;
        } else {
          c57_ad_ix++;
        }
      }
    }

    if (c57_ab_ixstart < 2) {
      c57_af_a = c57_ab_ixstart;
      c57_bf_a = c57_af_a + 1;
      c57_i186 = c57_bf_a;
      c57_cf_a = c57_i186;
      c57_df_a = c57_cf_a;
      if (c57_df_a > 2) {
        c57_ab_overflow = false;
      } else {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_ab_overflow = false;
      }

      if (c57_ab_overflow) {
        c57_check_forloop_overflow_error(chartInstance, c57_ab_overflow);
      }

      for (c57_cd_ix = c57_i186; c57_cd_ix < 3; c57_cd_ix++) {
        c57_bd_ix = c57_cd_ix;
        c57_ef_a = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_bd_ix), 1, 2, 1, 0) - 1];
        c57_cd_b = c57_ac_mtmp;
        c57_ab_p = (c57_ef_a < c57_cd_b);
        if (c57_ab_p) {
          c57_ac_mtmp = c57_b_u_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_bd_ix), 1, 2, 1, 0) - 1];
        }
      }
    }

    c57_bc_mtmp = c57_ac_mtmp;
    c57_d25 = c57_bc_mtmp;
    if (CV_SCRIPT_COND(0, 25, CV_RELATIONAL_EVAL(14U, 0U, 25, c57_d25, 0.0, -1,
          5U, c57_d25 >= 0.0))) {
      for (c57_i187 = 0; c57_i187 < 4; c57_i187++) {
        c57_b_L_opt_1[c57_i187] = c57_L_opt_9[c57_i187];
      }

      c57_bb_ixstart = 1;
      c57_cc_mtmp = c57_b_L_opt_1[0];
      c57_cc_x = c57_cc_mtmp;
      c57_dd_b = muDoubleScalarIsNaN(c57_cc_x);
      if (c57_dd_b) {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_dd_ix = 2;
        exitg1 = false;
        while ((exitg1 == false) && (c57_dd_ix < 5)) {
          c57_ed_ix = c57_dd_ix;
          c57_bb_ixstart = c57_ed_ix;
          c57_dc_x = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_ed_ix), 1, 4, 1, 0) - 1];
          c57_ed_b = muDoubleScalarIsNaN(c57_dc_x);
          if (!c57_ed_b) {
            c57_cc_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_ed_ix), 1, 4, 1, 0) - 1];
            exitg1 = true;
          } else {
            c57_dd_ix++;
          }
        }
      }

      if (c57_bb_ixstart < 4) {
        c57_ff_a = c57_bb_ixstart;
        c57_gf_a = c57_ff_a + 1;
        c57_i188 = c57_gf_a;
        c57_hf_a = c57_i188;
        c57_if_a = c57_hf_a;
        if (c57_if_a > 4) {
          c57_bb_overflow = false;
        } else {
          c57_eml_switch_helper(chartInstance);
          c57_eml_switch_helper(chartInstance);
          c57_bb_overflow = false;
        }

        if (c57_bb_overflow) {
          c57_check_forloop_overflow_error(chartInstance, c57_bb_overflow);
        }

        for (c57_fd_ix = c57_i188; c57_fd_ix < 5; c57_fd_ix++) {
          c57_ed_ix = c57_fd_ix;
          c57_jf_a = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_ed_ix), 1, 4, 1, 0) - 1];
          c57_fd_b = c57_cc_mtmp;
          c57_bb_p = (c57_jf_a < c57_fd_b);
          if (c57_bb_p) {
            c57_cc_mtmp = c57_b_L_opt_1[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
              _SFD_INTEGER_CHECK("", (real_T)c57_ed_ix), 1, 4, 1, 0) - 1];
          }
        }
      }

      c57_dc_mtmp = c57_cc_mtmp;
      c57_d26 = c57_dc_mtmp;
      if (CV_SCRIPT_COND(0, 26, CV_RELATIONAL_EVAL(14U, 0U, 26, c57_d26, 0.0, -1,
            5U, c57_d26 >= 0.0))) {
        CV_SCRIPT_MCDC(0, 8, true);
        CV_SCRIPT_IF(0, 8, true);
        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 106);
        for (c57_i189 = 0; c57_i189 < 2; c57_i189++) {
          c57_u_opt[c57_i189] = c57_u_opt_9[c57_i189];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 107);
        for (c57_i190 = 0; c57_i190 < 4; c57_i190++) {
          c57_L_opt[c57_i190] = c57_L_opt_9[c57_i190];
        }

        _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 108);
        c57_case_n = 9.0;
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

  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, 111);
  _SFD_SCRIPT_CALL(0U, chartInstance->c57_sfEvent, -111);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c57_LA_LS_Revised_Saturation_Case_1
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u_opt[2], real_T c57_L_opt[4])
{
  uint32_T c57_debug_family_var_map[7];
  real_T c57_nargin = 7.0;
  real_T c57_nargout = 2.0;
  int32_T c57_i191;
  real_T c57_A;
  real_T c57_B;
  real_T c57_y;
  real_T c57_b_A;
  real_T c57_b_B;
  real_T c57_b_y;
  real_T c57_c_A;
  real_T c57_c_B;
  real_T c57_c_y;
  real_T c57_d_A;
  real_T c57_d_B;
  real_T c57_d_y;
  int32_T c57_i192;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 7U, 7U, c57_b_debug_family_names,
    c57_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargin, 0U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargout, 1U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LS, 2U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LA, 3U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_w, 4U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt, 5U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt, 6U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c57_sfEvent, 9);
  for (c57_i191 = 0; c57_i191 < 2; c57_i191++) {
    c57_u_opt[c57_i191] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c57_sfEvent, 10);
  c57_A = -((2.0 * c57_u_LS + c57_u_LA * c57_w) * (c57_w - 4.0));
  c57_B = 8.0 * c57_w;
  c57_y = c57_rdivide(chartInstance, c57_A, c57_B);
  c57_b_A = (2.0 * c57_u_LS - c57_u_LA * c57_w) * (c57_w + 4.0);
  c57_b_B = 8.0 * c57_w;
  c57_b_y = c57_rdivide(chartInstance, c57_b_A, c57_b_B);
  c57_u_opt[0] = c57_y - c57_b_y;
  _SFD_SCRIPT_CALL(1U, chartInstance->c57_sfEvent, 11);
  c57_c_A = (2.0 * c57_u_LS + c57_u_LA * c57_w) * (c57_w + 4.0);
  c57_c_B = 8.0 * c57_w;
  c57_c_y = c57_rdivide(chartInstance, c57_c_A, c57_c_B);
  c57_d_A = (2.0 * c57_u_LS - c57_u_LA * c57_w) * (c57_w - 4.0);
  c57_d_B = 8.0 * c57_w;
  c57_d_y = c57_rdivide(chartInstance, c57_d_A, c57_d_B);
  c57_u_opt[1] = c57_c_y + c57_d_y;
  _SFD_SCRIPT_CALL(1U, chartInstance->c57_sfEvent, 14);
  for (c57_i192 = 0; c57_i192 < 4; c57_i192++) {
    c57_L_opt[c57_i192] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c57_sfEvent, 15);
  c57_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c57_sfEvent, 16);
  c57_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c57_sfEvent, 17);
  c57_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c57_sfEvent, 18);
  c57_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c57_sfEvent, 19);
  _SFD_SCRIPT_CALL(1U, chartInstance->c57_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c57_LA_LS_Revised_Saturation_Case_2
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u1_min, real_T c57_u_opt[2], real_T
   c57_L_opt[4])
{
  uint32_T c57_debug_family_var_map[8];
  real_T c57_nargin = 7.0;
  real_T c57_nargout = 2.0;
  int32_T c57_i193;
  real_T c57_A;
  real_T c57_B;
  real_T c57_y;
  int32_T c57_i194;
  real_T c57_b_A;
  real_T c57_b_B;
  real_T c57_b_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c57_c_debug_family_names,
    c57_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargin, 0U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargout, 1U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LS, 2U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LA, 3U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_w, 4U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u1_min, 5U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt, 6U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt, 7U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c57_sfEvent, 9);
  for (c57_i193 = 0; c57_i193 < 2; c57_i193++) {
    c57_u_opt[c57_i193] = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c57_sfEvent, 10);
  c57_u_opt[0] = c57_u1_min;
  _SFD_SCRIPT_CALL(2U, chartInstance->c57_sfEvent, 11);
  c57_A = ((4.0 * c57_u1_min + 4.0 * c57_u_LS) - c57_u1_min * c57_w) + 2.0 *
    c57_u_LA * c57_w;
  c57_B = c57_w + 4.0;
  c57_y = c57_rdivide(chartInstance, c57_A, c57_B);
  c57_u_opt[1] = c57_y;
  _SFD_SCRIPT_CALL(2U, chartInstance->c57_sfEvent, 14);
  for (c57_i194 = 0; c57_i194 < 4; c57_i194++) {
    c57_L_opt[c57_i194] = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c57_sfEvent, 15);
  c57_b_A = (8.0 * c57_u1_min * c57_w - 8.0 * c57_u_LA * c57_w) + 4.0 * c57_u_LS
    * c57_w;
  c57_b_B = c57_w + 4.0;
  c57_b_y = c57_rdivide(chartInstance, c57_b_A, c57_b_B);
  c57_L_opt[0] = c57_b_y;
  _SFD_SCRIPT_CALL(2U, chartInstance->c57_sfEvent, 16);
  c57_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c57_sfEvent, 17);
  c57_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c57_sfEvent, 18);
  c57_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c57_sfEvent, 19);
  _SFD_SCRIPT_CALL(2U, chartInstance->c57_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c57_LA_LS_Revised_Saturation_Case_3
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u1_max, real_T c57_u_opt[2], real_T
   c57_L_opt[4])
{
  uint32_T c57_debug_family_var_map[8];
  real_T c57_nargin = 7.0;
  real_T c57_nargout = 2.0;
  int32_T c57_i195;
  real_T c57_A;
  real_T c57_B;
  real_T c57_y;
  int32_T c57_i196;
  real_T c57_b_A;
  real_T c57_b_B;
  real_T c57_b_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c57_d_debug_family_names,
    c57_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargin, 0U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargout, 1U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LS, 2U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LA, 3U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_w, 4U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u1_max, 5U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt, 6U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt, 7U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c57_sfEvent, 9);
  for (c57_i195 = 0; c57_i195 < 2; c57_i195++) {
    c57_u_opt[c57_i195] = 0.0;
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c57_sfEvent, 10);
  c57_u_opt[0] = c57_u1_max;
  _SFD_SCRIPT_CALL(3U, chartInstance->c57_sfEvent, 11);
  c57_A = ((4.0 * c57_u1_max + 4.0 * c57_u_LS) - c57_u1_max * c57_w) + 2.0 *
    c57_u_LA * c57_w;
  c57_B = c57_w + 4.0;
  c57_y = c57_rdivide(chartInstance, c57_A, c57_B);
  c57_u_opt[1] = c57_y;
  _SFD_SCRIPT_CALL(3U, chartInstance->c57_sfEvent, 14);
  for (c57_i196 = 0; c57_i196 < 4; c57_i196++) {
    c57_L_opt[c57_i196] = 0.0;
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c57_sfEvent, 15);
  c57_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(3U, chartInstance->c57_sfEvent, 16);
  c57_b_A = -((8.0 * c57_u1_max * c57_w - 8.0 * c57_u_LA * c57_w) + 4.0 *
              c57_u_LS * c57_w);
  c57_b_B = c57_w + 4.0;
  c57_b_y = c57_rdivide(chartInstance, c57_b_A, c57_b_B);
  c57_L_opt[1] = c57_b_y;
  _SFD_SCRIPT_CALL(3U, chartInstance->c57_sfEvent, 17);
  c57_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(3U, chartInstance->c57_sfEvent, 18);
  c57_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(3U, chartInstance->c57_sfEvent, 19);
  _SFD_SCRIPT_CALL(3U, chartInstance->c57_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c57_LA_LS_Revised_Saturation_Case_4
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u2_min, real_T c57_u_opt[2], real_T
   c57_L_opt[4])
{
  uint32_T c57_debug_family_var_map[8];
  real_T c57_nargin = 7.0;
  real_T c57_nargout = 2.0;
  int32_T c57_i197;
  real_T c57_A;
  real_T c57_B;
  real_T c57_y;
  int32_T c57_i198;
  real_T c57_b_A;
  real_T c57_b_B;
  real_T c57_b_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c57_e_debug_family_names,
    c57_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargin, 0U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargout, 1U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LS, 2U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LA, 3U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_w, 4U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u2_min, 5U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt, 6U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt, 7U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  CV_SCRIPT_FCN(4, 0);
  _SFD_SCRIPT_CALL(4U, chartInstance->c57_sfEvent, 9);
  for (c57_i197 = 0; c57_i197 < 2; c57_i197++) {
    c57_u_opt[c57_i197] = 0.0;
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c57_sfEvent, 10);
  c57_A = ((4.0 * c57_u2_min - 4.0 * c57_u_LS) - c57_u2_min * c57_w) + 2.0 *
    c57_u_LA * c57_w;
  c57_B = c57_w + 4.0;
  c57_y = c57_rdivide(chartInstance, c57_A, c57_B);
  c57_u_opt[0] = c57_y;
  _SFD_SCRIPT_CALL(4U, chartInstance->c57_sfEvent, 11);
  c57_u_opt[1] = c57_u2_min;
  _SFD_SCRIPT_CALL(4U, chartInstance->c57_sfEvent, 14);
  for (c57_i198 = 0; c57_i198 < 4; c57_i198++) {
    c57_L_opt[c57_i198] = 0.0;
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c57_sfEvent, 15);
  c57_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c57_sfEvent, 16);
  c57_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c57_sfEvent, 17);
  c57_b_A = -((8.0 * c57_u_LA * c57_w - 8.0 * c57_u2_min * c57_w) + 4.0 *
              c57_u_LS * c57_w);
  c57_b_B = c57_w + 4.0;
  c57_b_y = c57_rdivide(chartInstance, c57_b_A, c57_b_B);
  c57_L_opt[2] = c57_b_y;
  _SFD_SCRIPT_CALL(4U, chartInstance->c57_sfEvent, 18);
  c57_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c57_sfEvent, 19);
  _SFD_SCRIPT_CALL(4U, chartInstance->c57_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c57_LA_LS_Revised_Saturation_Case_5
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u2_max, real_T c57_u_opt[2], real_T
   c57_L_opt[4])
{
  uint32_T c57_debug_family_var_map[8];
  real_T c57_nargin = 7.0;
  real_T c57_nargout = 2.0;
  int32_T c57_i199;
  real_T c57_A;
  real_T c57_B;
  real_T c57_y;
  int32_T c57_i200;
  real_T c57_b_A;
  real_T c57_b_B;
  real_T c57_b_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c57_f_debug_family_names,
    c57_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargin, 0U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargout, 1U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LS, 2U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LA, 3U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_w, 4U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u2_max, 5U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt, 6U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt, 7U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5U, chartInstance->c57_sfEvent, 9);
  for (c57_i199 = 0; c57_i199 < 2; c57_i199++) {
    c57_u_opt[c57_i199] = 0.0;
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c57_sfEvent, 10);
  c57_A = ((4.0 * c57_u2_max - 4.0 * c57_u_LS) - c57_u2_max * c57_w) + 2.0 *
    c57_u_LA * c57_w;
  c57_B = c57_w + 4.0;
  c57_y = c57_rdivide(chartInstance, c57_A, c57_B);
  c57_u_opt[0] = c57_y;
  _SFD_SCRIPT_CALL(5U, chartInstance->c57_sfEvent, 11);
  c57_u_opt[1] = c57_u2_max;
  _SFD_SCRIPT_CALL(5U, chartInstance->c57_sfEvent, 14);
  for (c57_i200 = 0; c57_i200 < 4; c57_i200++) {
    c57_L_opt[c57_i200] = 0.0;
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c57_sfEvent, 15);
  c57_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(5U, chartInstance->c57_sfEvent, 16);
  c57_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(5U, chartInstance->c57_sfEvent, 17);
  c57_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(5U, chartInstance->c57_sfEvent, 18);
  c57_b_A = (8.0 * c57_u_LA * c57_w - 8.0 * c57_u2_max * c57_w) + 4.0 * c57_u_LS
    * c57_w;
  c57_b_B = c57_w + 4.0;
  c57_b_y = c57_rdivide(chartInstance, c57_b_A, c57_b_B);
  c57_L_opt[3] = c57_b_y;
  _SFD_SCRIPT_CALL(5U, chartInstance->c57_sfEvent, 19);
  _SFD_SCRIPT_CALL(5U, chartInstance->c57_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c57_LA_LS_Revised_Saturation_Case_6
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u1_min, real_T c57_u2_min, real_T
   c57_u_opt[2], real_T c57_L_opt[4])
{
  uint32_T c57_debug_family_var_map[9];
  real_T c57_nargin = 7.0;
  real_T c57_nargout = 2.0;
  int32_T c57_i201;
  int32_T c57_i202;
  real_T c57_A;
  real_T c57_y;
  real_T c57_b_A;
  real_T c57_b_y;
  real_T c57_c_A;
  real_T c57_c_y;
  real_T c57_d_A;
  real_T c57_d_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c57_g_debug_family_names,
    c57_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargin, 0U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargout, 1U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LS, 2U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LA, 3U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_w, 4U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u1_min, 5U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u2_min, 6U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt, 7U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt, 8U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  CV_SCRIPT_FCN(6, 0);
  _SFD_SCRIPT_CALL(6U, chartInstance->c57_sfEvent, 9);
  for (c57_i201 = 0; c57_i201 < 2; c57_i201++) {
    c57_u_opt[c57_i201] = 0.0;
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c57_sfEvent, 10);
  c57_u_opt[0] = c57_u1_min;
  _SFD_SCRIPT_CALL(6U, chartInstance->c57_sfEvent, 11);
  c57_u_opt[1] = c57_u2_min;
  _SFD_SCRIPT_CALL(6U, chartInstance->c57_sfEvent, 14);
  for (c57_i202 = 0; c57_i202 < 4; c57_i202++) {
    c57_L_opt[c57_i202] = 0.0;
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c57_sfEvent, 15);
  c57_A = c57_u1_min;
  c57_y = c57_rdivide(chartInstance, c57_A, 2.0);
  c57_b_A = c57_u2_min;
  c57_b_y = c57_rdivide(chartInstance, c57_b_A, 2.0);
  c57_L_opt[0] = ((2.0 * c57_u1_min - 2.0 * c57_u2_min) + 2.0 * c57_u_LS) +
    c57_w * ((c57_y + c57_b_y) - c57_u_LA);
  _SFD_SCRIPT_CALL(6U, chartInstance->c57_sfEvent, 16);
  c57_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(6U, chartInstance->c57_sfEvent, 17);
  c57_c_A = c57_u1_min;
  c57_c_y = c57_rdivide(chartInstance, c57_c_A, 2.0);
  c57_d_A = c57_u2_min;
  c57_d_y = c57_rdivide(chartInstance, c57_d_A, 2.0);
  c57_L_opt[2] = ((2.0 * c57_u2_min - 2.0 * c57_u1_min) - 2.0 * c57_u_LS) +
    c57_w * ((c57_c_y + c57_d_y) - c57_u_LA);
  _SFD_SCRIPT_CALL(6U, chartInstance->c57_sfEvent, 18);
  c57_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(6U, chartInstance->c57_sfEvent, 19);
  _SFD_SCRIPT_CALL(6U, chartInstance->c57_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c57_LA_LS_Revised_Saturation_Case_7
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u1_min, real_T c57_u2_max, real_T
   c57_u_opt[2], real_T c57_L_opt[4])
{
  uint32_T c57_debug_family_var_map[9];
  real_T c57_nargin = 7.0;
  real_T c57_nargout = 2.0;
  int32_T c57_i203;
  int32_T c57_i204;
  real_T c57_A;
  real_T c57_y;
  real_T c57_b_A;
  real_T c57_b_y;
  real_T c57_c_A;
  real_T c57_c_y;
  real_T c57_d_A;
  real_T c57_d_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c57_h_debug_family_names,
    c57_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargin, 0U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargout, 1U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LS, 2U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LA, 3U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_w, 4U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u1_min, 5U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u2_max, 6U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt, 7U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt, 8U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  CV_SCRIPT_FCN(7, 0);
  _SFD_SCRIPT_CALL(7U, chartInstance->c57_sfEvent, 9);
  for (c57_i203 = 0; c57_i203 < 2; c57_i203++) {
    c57_u_opt[c57_i203] = 0.0;
  }

  _SFD_SCRIPT_CALL(7U, chartInstance->c57_sfEvent, 10);
  c57_u_opt[0] = c57_u1_min;
  _SFD_SCRIPT_CALL(7U, chartInstance->c57_sfEvent, 11);
  c57_u_opt[1] = c57_u2_max;
  _SFD_SCRIPT_CALL(7U, chartInstance->c57_sfEvent, 14);
  for (c57_i204 = 0; c57_i204 < 4; c57_i204++) {
    c57_L_opt[c57_i204] = 0.0;
  }

  _SFD_SCRIPT_CALL(7U, chartInstance->c57_sfEvent, 15);
  c57_A = c57_u1_min;
  c57_y = c57_rdivide(chartInstance, c57_A, 2.0);
  c57_b_A = c57_u2_max;
  c57_b_y = c57_rdivide(chartInstance, c57_b_A, 2.0);
  c57_L_opt[0] = ((2.0 * c57_u1_min - 2.0 * c57_u2_max) + 2.0 * c57_u_LS) +
    c57_w * ((c57_y + c57_b_y) - c57_u_LA);
  _SFD_SCRIPT_CALL(7U, chartInstance->c57_sfEvent, 16);
  c57_L_opt[1] = 0.0;
  _SFD_SCRIPT_CALL(7U, chartInstance->c57_sfEvent, 17);
  c57_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(7U, chartInstance->c57_sfEvent, 18);
  c57_c_A = c57_u1_min * c57_w;
  c57_c_y = c57_rdivide(chartInstance, c57_c_A, 2.0);
  c57_d_A = c57_u2_max * c57_w;
  c57_d_y = c57_rdivide(chartInstance, c57_d_A, 2.0);
  c57_L_opt[3] = ((((2.0 * c57_u1_min - 2.0 * c57_u2_max) + 2.0 * c57_u_LS) -
                   c57_c_y) - c57_d_y) + c57_u_LA * c57_w;
  _SFD_SCRIPT_CALL(7U, chartInstance->c57_sfEvent, 19);
  _SFD_SCRIPT_CALL(7U, chartInstance->c57_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c57_LA_LS_Revised_Saturation_Case_8
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u1_max, real_T c57_u2_min, real_T
   c57_u_opt[2], real_T c57_L_opt[4])
{
  uint32_T c57_debug_family_var_map[9];
  real_T c57_nargin = 7.0;
  real_T c57_nargout = 2.0;
  int32_T c57_i205;
  int32_T c57_i206;
  real_T c57_A;
  real_T c57_y;
  real_T c57_b_A;
  real_T c57_b_y;
  real_T c57_c_A;
  real_T c57_c_y;
  real_T c57_d_A;
  real_T c57_d_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c57_i_debug_family_names,
    c57_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargin, 0U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargout, 1U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LS, 2U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LA, 3U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_w, 4U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u1_max, 5U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u2_min, 6U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt, 7U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt, 8U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  CV_SCRIPT_FCN(8, 0);
  _SFD_SCRIPT_CALL(8U, chartInstance->c57_sfEvent, 9);
  for (c57_i205 = 0; c57_i205 < 2; c57_i205++) {
    c57_u_opt[c57_i205] = 0.0;
  }

  _SFD_SCRIPT_CALL(8U, chartInstance->c57_sfEvent, 10);
  c57_u_opt[0] = c57_u1_max;
  _SFD_SCRIPT_CALL(8U, chartInstance->c57_sfEvent, 11);
  c57_u_opt[1] = c57_u2_min;
  _SFD_SCRIPT_CALL(8U, chartInstance->c57_sfEvent, 14);
  for (c57_i206 = 0; c57_i206 < 4; c57_i206++) {
    c57_L_opt[c57_i206] = 0.0;
  }

  _SFD_SCRIPT_CALL(8U, chartInstance->c57_sfEvent, 15);
  c57_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(8U, chartInstance->c57_sfEvent, 16);
  c57_A = c57_u2_min * c57_w;
  c57_y = c57_rdivide(chartInstance, c57_A, 2.0);
  c57_b_A = c57_u1_max * c57_w;
  c57_b_y = c57_rdivide(chartInstance, c57_b_A, 2.0);
  c57_L_opt[1] = ((((2.0 * c57_u2_min - 2.0 * c57_u1_max) - 2.0 * c57_u_LS) -
                   c57_y) - c57_b_y) + c57_u_LA * c57_w;
  _SFD_SCRIPT_CALL(8U, chartInstance->c57_sfEvent, 17);
  c57_c_A = c57_u2_min;
  c57_c_y = c57_rdivide(chartInstance, c57_c_A, 2.0);
  c57_d_A = c57_u1_max;
  c57_d_y = c57_rdivide(chartInstance, c57_d_A, 2.0);
  c57_L_opt[2] = ((2.0 * c57_u2_min - 2.0 * c57_u1_max) - 2.0 * c57_u_LS) +
    c57_w * ((c57_c_y + c57_d_y) - c57_u_LA);
  _SFD_SCRIPT_CALL(8U, chartInstance->c57_sfEvent, 18);
  c57_L_opt[3] = 0.0;
  _SFD_SCRIPT_CALL(8U, chartInstance->c57_sfEvent, 19);
  _SFD_SCRIPT_CALL(8U, chartInstance->c57_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c57_LA_LS_Revised_Saturation_Case_9
  (SFc57_Walking01_DDA3DInstanceStruct *chartInstance, real_T c57_u_LS, real_T
   c57_u_LA, real_T c57_w, real_T c57_u1_max, real_T c57_u2_max, real_T
   c57_u_opt[2], real_T c57_L_opt[4])
{
  uint32_T c57_debug_family_var_map[9];
  real_T c57_nargin = 7.0;
  real_T c57_nargout = 2.0;
  int32_T c57_i207;
  int32_T c57_i208;
  real_T c57_A;
  real_T c57_y;
  real_T c57_b_A;
  real_T c57_b_y;
  real_T c57_c_A;
  real_T c57_c_y;
  real_T c57_d_A;
  real_T c57_d_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c57_j_debug_family_names,
    c57_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargin, 0U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_nargout, 1U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LS, 2U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u_LA, 3U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_w, 4U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u1_max, 5U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c57_u2_max, 6U, c57_e_sf_marshallOut,
    c57_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_u_opt, 7U, c57_d_sf_marshallOut,
    c57_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c57_L_opt, 8U, c57_g_sf_marshallOut,
    c57_e_sf_marshallIn);
  CV_SCRIPT_FCN(9, 0);
  _SFD_SCRIPT_CALL(9U, chartInstance->c57_sfEvent, 9);
  for (c57_i207 = 0; c57_i207 < 2; c57_i207++) {
    c57_u_opt[c57_i207] = 0.0;
  }

  _SFD_SCRIPT_CALL(9U, chartInstance->c57_sfEvent, 10);
  c57_u_opt[0] = c57_u1_max;
  _SFD_SCRIPT_CALL(9U, chartInstance->c57_sfEvent, 11);
  c57_u_opt[1] = c57_u2_max;
  _SFD_SCRIPT_CALL(9U, chartInstance->c57_sfEvent, 14);
  for (c57_i208 = 0; c57_i208 < 4; c57_i208++) {
    c57_L_opt[c57_i208] = 0.0;
  }

  _SFD_SCRIPT_CALL(9U, chartInstance->c57_sfEvent, 15);
  c57_L_opt[0] = 0.0;
  _SFD_SCRIPT_CALL(9U, chartInstance->c57_sfEvent, 16);
  c57_A = c57_u1_max * c57_w;
  c57_y = c57_rdivide(chartInstance, c57_A, 2.0);
  c57_b_A = c57_u2_max * c57_w;
  c57_b_y = c57_rdivide(chartInstance, c57_b_A, 2.0);
  c57_L_opt[1] = ((((2.0 * c57_u2_max - 2.0 * c57_u1_max) - 2.0 * c57_u_LS) -
                   c57_y) - c57_b_y) + c57_u_LA * c57_w;
  _SFD_SCRIPT_CALL(9U, chartInstance->c57_sfEvent, 17);
  c57_L_opt[2] = 0.0;
  _SFD_SCRIPT_CALL(9U, chartInstance->c57_sfEvent, 18);
  c57_c_A = c57_u1_max * c57_w;
  c57_c_y = c57_rdivide(chartInstance, c57_c_A, 2.0);
  c57_d_A = c57_u2_max * c57_w;
  c57_d_y = c57_rdivide(chartInstance, c57_d_A, 2.0);
  c57_L_opt[3] = ((((2.0 * c57_u1_max - 2.0 * c57_u2_max) + 2.0 * c57_u_LS) -
                   c57_c_y) - c57_d_y) + c57_u_LA * c57_w;
  _SFD_SCRIPT_CALL(9U, chartInstance->c57_sfEvent, 19);
  _SFD_SCRIPT_CALL(9U, chartInstance->c57_sfEvent, -19);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c57_machineNumber, uint32_T
  c57_chartNumber, uint32_T c57_instanceNumber)
{
  (void)c57_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c57_chartNumber, c57_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation.m"));
  _SFD_SCRIPT_TRANSLATION(c57_chartNumber, c57_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_1.m"));
  _SFD_SCRIPT_TRANSLATION(c57_chartNumber, c57_instanceNumber, 2U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_2.m"));
  _SFD_SCRIPT_TRANSLATION(c57_chartNumber, c57_instanceNumber, 3U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_3.m"));
  _SFD_SCRIPT_TRANSLATION(c57_chartNumber, c57_instanceNumber, 4U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_4.m"));
  _SFD_SCRIPT_TRANSLATION(c57_chartNumber, c57_instanceNumber, 5U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_5.m"));
  _SFD_SCRIPT_TRANSLATION(c57_chartNumber, c57_instanceNumber, 6U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_6.m"));
  _SFD_SCRIPT_TRANSLATION(c57_chartNumber, c57_instanceNumber, 7U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_7.m"));
  _SFD_SCRIPT_TRANSLATION(c57_chartNumber, c57_instanceNumber, 8U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_8.m"));
  _SFD_SCRIPT_TRANSLATION(c57_chartNumber, c57_instanceNumber, 9U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\QP\\LA_LS_Revised_Saturation_Case_9.m"));
}

static const mxArray *c57_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData)
{
  const mxArray *c57_mxArrayOutData = NULL;
  int32_T c57_i209;
  real_T c57_b_inData[6];
  int32_T c57_i210;
  real_T c57_b_u[6];
  const mxArray *c57_y = NULL;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_mxArrayOutData = NULL;
  for (c57_i209 = 0; c57_i209 < 6; c57_i209++) {
    c57_b_inData[c57_i209] = (*(real_T (*)[6])c57_inData)[c57_i209];
  }

  for (c57_i210 = 0; c57_i210 < 6; c57_i210++) {
    c57_b_u[c57_i210] = c57_b_inData[c57_i210];
  }

  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", c57_b_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c57_mxArrayOutData, c57_y, false);
  return c57_mxArrayOutData;
}

static void c57_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u_sat, const char_T *c57_identifier,
  real_T c57_y[6])
{
  emlrtMsgIdentifier c57_thisId;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c57_b_u_sat), &c57_thisId,
    c57_y);
  sf_mex_destroy(&c57_b_u_sat);
}

static void c57_b_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId,
  real_T c57_y[6])
{
  real_T c57_dv4[6];
  int32_T c57_i211;
  (void)chartInstance;
  sf_mex_import(c57_parentId, sf_mex_dup(c57_b_u), c57_dv4, 1, 0, 0U, 1, 0U, 1,
                6);
  for (c57_i211 = 0; c57_i211 < 6; c57_i211++) {
    c57_y[c57_i211] = c57_dv4[c57_i211];
  }

  sf_mex_destroy(&c57_b_u);
}

static void c57_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData)
{
  const mxArray *c57_b_u_sat;
  const char_T *c57_identifier;
  emlrtMsgIdentifier c57_thisId;
  real_T c57_y[6];
  int32_T c57_i212;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_b_u_sat = sf_mex_dup(c57_mxArrayInData);
  c57_identifier = c57_varName;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c57_b_u_sat), &c57_thisId,
    c57_y);
  sf_mex_destroy(&c57_b_u_sat);
  for (c57_i212 = 0; c57_i212 < 6; c57_i212++) {
    (*(real_T (*)[6])c57_outData)[c57_i212] = c57_y[c57_i212];
  }

  sf_mex_destroy(&c57_mxArrayInData);
}

static const mxArray *c57_b_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData)
{
  const mxArray *c57_mxArrayOutData;
  c57_ControlParamsBus c57_b_u;
  const mxArray *c57_y = NULL;
  c57_SupervisoryParamsBus c57_c_u;
  const mxArray *c57_b_y = NULL;
  real_T c57_d_u;
  const mxArray *c57_c_y = NULL;
  real_T c57_e_u;
  const mxArray *c57_d_y = NULL;
  real_T c57_f_u;
  const mxArray *c57_e_y = NULL;
  real_T c57_g_u;
  const mxArray *c57_f_y = NULL;
  real_T c57_h_u;
  const mxArray *c57_g_y = NULL;
  real_T c57_i_u;
  const mxArray *c57_h_y = NULL;
  real_T c57_j_u;
  const mxArray *c57_i_y = NULL;
  real_T c57_k_u;
  const mxArray *c57_j_y = NULL;
  real_T c57_l_u;
  const mxArray *c57_k_y = NULL;
  real_T c57_m_u;
  const mxArray *c57_l_y = NULL;
  real_T c57_n_u;
  const mxArray *c57_m_y = NULL;
  int32_T c57_i213;
  real_T c57_o_u[2];
  const mxArray *c57_n_y = NULL;
  real_T c57_p_u;
  const mxArray *c57_o_y = NULL;
  real_T c57_q_u;
  const mxArray *c57_p_y = NULL;
  int32_T c57_i214;
  real_T c57_r_u[6];
  const mxArray *c57_q_y = NULL;
  int32_T c57_i215;
  real_T c57_s_u[13];
  const mxArray *c57_r_y = NULL;
  int32_T c57_i216;
  real_T c57_t_u[5];
  const mxArray *c57_s_y = NULL;
  real_T c57_u_u;
  const mxArray *c57_t_y = NULL;
  real_T c57_v_u;
  const mxArray *c57_u_y = NULL;
  real_T c57_w_u;
  const mxArray *c57_v_y = NULL;
  real_T c57_x_u;
  const mxArray *c57_w_y = NULL;
  int32_T c57_i217;
  real_T c57_y_u[6];
  const mxArray *c57_x_y = NULL;
  int32_T c57_i218;
  real_T c57_ab_u[6];
  const mxArray *c57_y_y = NULL;
  real_T c57_bb_u;
  const mxArray *c57_ab_y = NULL;
  real_T c57_cb_u;
  const mxArray *c57_bb_y = NULL;
  real_T c57_db_u;
  const mxArray *c57_cb_y = NULL;
  real_T c57_eb_u;
  const mxArray *c57_db_y = NULL;
  real_T c57_fb_u;
  const mxArray *c57_eb_y = NULL;
  real_T c57_gb_u;
  const mxArray *c57_fb_y = NULL;
  real_T c57_hb_u;
  const mxArray *c57_gb_y = NULL;
  real_T c57_ib_u;
  const mxArray *c57_hb_y = NULL;
  real_T c57_jb_u;
  const mxArray *c57_ib_y = NULL;
  real_T c57_kb_u;
  const mxArray *c57_jb_y = NULL;
  real_T c57_lb_u;
  const mxArray *c57_kb_y = NULL;
  real_T c57_mb_u;
  const mxArray *c57_lb_y = NULL;
  real_T c57_nb_u;
  const mxArray *c57_mb_y = NULL;
  real_T c57_ob_u;
  const mxArray *c57_nb_y = NULL;
  real_T c57_pb_u;
  const mxArray *c57_ob_y = NULL;
  real_T c57_qb_u;
  const mxArray *c57_pb_y = NULL;
  real_T c57_rb_u;
  const mxArray *c57_qb_y = NULL;
  real_T c57_sb_u;
  const mxArray *c57_rb_y = NULL;
  real_T c57_tb_u;
  const mxArray *c57_sb_y = NULL;
  real_T c57_ub_u;
  const mxArray *c57_tb_y = NULL;
  real_T c57_vb_u;
  const mxArray *c57_ub_y = NULL;
  int32_T c57_i219;
  real_T c57_wb_u[6];
  const mxArray *c57_vb_y = NULL;
  int32_T c57_i220;
  real_T c57_xb_u[6];
  const mxArray *c57_wb_y = NULL;
  real_T c57_yb_u;
  const mxArray *c57_xb_y = NULL;
  int32_T c57_i221;
  real_T c57_ac_u[6];
  const mxArray *c57_yb_y = NULL;
  int32_T c57_i222;
  real_T c57_bc_u[6];
  const mxArray *c57_ac_y = NULL;
  real_T c57_cc_u;
  const mxArray *c57_bc_y = NULL;
  int32_T c57_i223;
  real_T c57_dc_u[12];
  const mxArray *c57_cc_y = NULL;
  real_T c57_ec_u;
  const mxArray *c57_dc_y = NULL;
  real_T c57_fc_u;
  const mxArray *c57_ec_y = NULL;
  real_T c57_gc_u;
  const mxArray *c57_fc_y = NULL;
  real_T c57_hc_u;
  const mxArray *c57_gc_y = NULL;
  real_T c57_ic_u;
  const mxArray *c57_hc_y = NULL;
  real_T c57_jc_u;
  const mxArray *c57_ic_y = NULL;
  real_T c57_kc_u;
  const mxArray *c57_jc_y = NULL;
  c57_DiscreteParamsBus c57_lc_u;
  const mxArray *c57_kc_y = NULL;
  real_T c57_mc_u;
  const mxArray *c57_lc_y = NULL;
  real_T c57_nc_u;
  const mxArray *c57_mc_y = NULL;
  real_T c57_oc_u;
  const mxArray *c57_nc_y = NULL;
  real_T c57_pc_u;
  const mxArray *c57_oc_y = NULL;
  real_T c57_qc_u;
  const mxArray *c57_pc_y = NULL;
  real_T c57_rc_u;
  const mxArray *c57_qc_y = NULL;
  real_T c57_sc_u;
  const mxArray *c57_rc_y = NULL;
  real_T c57_tc_u;
  const mxArray *c57_sc_y = NULL;
  real_T c57_uc_u;
  const mxArray *c57_tc_y = NULL;
  real_T c57_vc_u;
  const mxArray *c57_uc_y = NULL;
  real_T c57_wc_u;
  const mxArray *c57_vc_y = NULL;
  c57_OutputParamsBus c57_xc_u;
  const mxArray *c57_wc_y = NULL;
  int32_T c57_i224;
  real_T c57_yc_u[78];
  const mxArray *c57_xc_y = NULL;
  int32_T c57_i225;
  real_T c57_ad_u[36];
  const mxArray *c57_yc_y = NULL;
  int32_T c57_i226;
  real_T c57_bd_u[2];
  const mxArray *c57_ad_y = NULL;
  c57_ThetaParamsBus c57_cd_u;
  const mxArray *c57_bd_y = NULL;
  real_T c57_dd_u;
  const mxArray *c57_cd_y = NULL;
  real_T c57_ed_u;
  const mxArray *c57_dd_y = NULL;
  int32_T c57_i227;
  real_T c57_fd_u[13];
  const mxArray *c57_ed_y = NULL;
  real_T c57_gd_u;
  const mxArray *c57_fd_y = NULL;
  int32_T c57_i228;
  real_T c57_hd_u[7];
  const mxArray *c57_gd_y = NULL;
  real_T c57_id_u;
  const mxArray *c57_hd_y = NULL;
  int32_T c57_i229;
  real_T c57_jd_u[2];
  const mxArray *c57_id_y = NULL;
  real_T c57_kd_u;
  const mxArray *c57_jd_y = NULL;
  real_T c57_ld_u;
  const mxArray *c57_kd_y = NULL;
  real_T c57_md_u;
  const mxArray *c57_ld_y = NULL;
  int32_T c57_i230;
  real_T c57_nd_u[30];
  const mxArray *c57_md_y = NULL;
  c57_PhiParamsBus c57_od_u;
  const mxArray *c57_nd_y = NULL;
  real_T c57_pd_u;
  const mxArray *c57_od_y = NULL;
  int32_T c57_i231;
  real_T c57_qd_u[13];
  const mxArray *c57_pd_y = NULL;
  int32_T c57_i232;
  real_T c57_rd_u[20];
  const mxArray *c57_qd_y = NULL;
  real_T c57_sd_u;
  const mxArray *c57_rd_y = NULL;
  int32_T c57_i233;
  real_T c57_td_u[2];
  const mxArray *c57_sd_y = NULL;
  int32_T c57_i234;
  real_T c57_ud_u[30];
  const mxArray *c57_td_y = NULL;
  int32_T c57_i235;
  real_T c57_vd_u[12];
  const mxArray *c57_ud_y = NULL;
  int32_T c57_i236;
  real_T c57_wd_u[36];
  const mxArray *c57_vd_y = NULL;
  real_T c57_xd_u;
  const mxArray *c57_wd_y = NULL;
  real_T c57_yd_u;
  const mxArray *c57_xd_y = NULL;
  c57_FeedbackParamsBus c57_ae_u;
  const mxArray *c57_yd_y = NULL;
  int32_T c57_i237;
  real_T c57_be_u[6];
  const mxArray *c57_ae_y = NULL;
  int32_T c57_i238;
  real_T c57_ce_u[6];
  const mxArray *c57_be_y = NULL;
  int32_T c57_i239;
  real_T c57_de_u[2];
  const mxArray *c57_ce_y = NULL;
  int32_T c57_i240;
  real_T c57_ee_u[2];
  const mxArray *c57_de_y = NULL;
  real_T c57_fe_u;
  const mxArray *c57_ee_y = NULL;
  int32_T c57_i241;
  real_T c57_ge_u[2];
  const mxArray *c57_fe_y = NULL;
  int32_T c57_i242;
  real_T c57_he_u[2];
  const mxArray *c57_ge_y = NULL;
  real_T c57_ie_u;
  const mxArray *c57_he_y = NULL;
  real_T c57_je_u;
  const mxArray *c57_ie_y = NULL;
  real_T c57_ke_u;
  const mxArray *c57_je_y = NULL;
  real_T c57_le_u;
  const mxArray *c57_ke_y = NULL;
  real_T c57_me_u;
  const mxArray *c57_le_y = NULL;
  real_T c57_ne_u;
  const mxArray *c57_me_y = NULL;
  real_T c57_oe_u;
  const mxArray *c57_ne_y = NULL;
  real_T c57_pe_u;
  const mxArray *c57_oe_y = NULL;
  int32_T c57_i243;
  real_T c57_qe_u[6];
  const mxArray *c57_pe_y = NULL;
  real_T c57_re_u;
  const mxArray *c57_qe_y = NULL;
  real_T c57_se_u;
  const mxArray *c57_re_y = NULL;
  real_T c57_te_u;
  const mxArray *c57_se_y = NULL;
  real_T c57_ue_u;
  const mxArray *c57_te_y = NULL;
  real_T c57_ve_u;
  const mxArray *c57_ue_y = NULL;
  real_T c57_we_u;
  const mxArray *c57_ve_y = NULL;
  real_T c57_xe_u;
  const mxArray *c57_we_y = NULL;
  real_T c57_ye_u;
  const mxArray *c57_xe_y = NULL;
  real_T c57_af_u;
  const mxArray *c57_ye_y = NULL;
  int32_T c57_i244;
  real_T c57_bf_u[6];
  const mxArray *c57_af_y = NULL;
  real_T c57_cf_u;
  const mxArray *c57_bf_y = NULL;
  c57_SaturationParamsBus c57_df_u;
  const mxArray *c57_cf_y = NULL;
  real_T c57_ef_u;
  const mxArray *c57_df_y = NULL;
  int32_T c57_i245;
  real_T c57_ff_u[2];
  const mxArray *c57_ef_y = NULL;
  real_T c57_gf_u;
  const mxArray *c57_ff_y = NULL;
  real_T c57_hf_u;
  const mxArray *c57_gf_y = NULL;
  real_T c57_if_u;
  const mxArray *c57_hf_y = NULL;
  real_T c57_jf_u;
  const mxArray *c57_if_y = NULL;
  real_T c57_kf_u;
  const mxArray *c57_jf_y = NULL;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_mxArrayOutData = NULL;
  c57_mxArrayOutData = NULL;
  c57_b_u = *(c57_ControlParamsBus *)c57_inData;
  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c57_c_u = c57_b_u.Supervisory;
  c57_b_y = NULL;
  sf_mex_assign(&c57_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c57_d_u = c57_c_u.EnableSwapOnKAAccel;
  c57_c_y = NULL;
  sf_mex_assign(&c57_c_y, sf_mex_create("y", &c57_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_c_y, "EnableSwapOnKAAccel", "EnableSwapOnKAAccel",
                  0);
  c57_e_u = c57_c_u.EnableSwapOnKASpring;
  c57_d_y = NULL;
  sf_mex_assign(&c57_d_y, sf_mex_create("y", &c57_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_d_y, "EnableSwapOnKASpring",
                  "EnableSwapOnKASpring", 0);
  c57_f_u = c57_c_u.EnableBackwardSwap;
  c57_e_y = NULL;
  sf_mex_assign(&c57_e_y, sf_mex_create("y", &c57_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_e_y, "EnableBackwardSwap", "EnableBackwardSwap",
                  0);
  c57_g_u = c57_c_u.ImpactThresholdKAAccel;
  c57_f_y = NULL;
  sf_mex_assign(&c57_f_y, sf_mex_create("y", &c57_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_f_y, "ImpactThresholdKAAccel",
                  "ImpactThresholdKAAccel", 0);
  c57_h_u = c57_c_u.ImpactThresholdKASpringAbs;
  c57_g_y = NULL;
  sf_mex_assign(&c57_g_y, sf_mex_create("y", &c57_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_g_y, "ImpactThresholdKASpringAbs",
                  "ImpactThresholdKASpringAbs", 0);
  c57_i_u = c57_c_u.ImpactThresholdKASpringRel;
  c57_h_y = NULL;
  sf_mex_assign(&c57_h_y, sf_mex_create("y", &c57_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_h_y, "ImpactThresholdKASpringRel",
                  "ImpactThresholdKASpringRel", 0);
  c57_j_u = c57_c_u.SwapThresholdS;
  c57_i_y = NULL;
  sf_mex_assign(&c57_i_y, sf_mex_create("y", &c57_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_i_y, "SwapThresholdS", "SwapThresholdS", 0);
  c57_k_u = c57_c_u.AllowDoubleSupport;
  c57_j_y = NULL;
  sf_mex_assign(&c57_j_y, sf_mex_create("y", &c57_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_j_y, "AllowDoubleSupport", "AllowDoubleSupport",
                  0);
  c57_l_u = c57_c_u.UseGaitTransition;
  c57_k_y = NULL;
  sf_mex_assign(&c57_k_y, sf_mex_create("y", &c57_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_k_y, "UseGaitTransition", "UseGaitTransition", 0);
  c57_m_u = c57_c_u.NumTransitionSteps;
  c57_l_y = NULL;
  sf_mex_assign(&c57_l_y, sf_mex_create("y", &c57_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_l_y, "NumTransitionSteps", "NumTransitionSteps",
                  0);
  c57_n_u = c57_c_u.TransitionThresholdTorsoVel;
  c57_m_y = NULL;
  sf_mex_assign(&c57_m_y, sf_mex_create("y", &c57_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_m_y, "TransitionThresholdTorsoVel",
                  "TransitionThresholdTorsoVel", 0);
  for (c57_i213 = 0; c57_i213 < 2; c57_i213++) {
    c57_o_u[c57_i213] = c57_c_u.KAInjection[c57_i213];
  }

  c57_n_y = NULL;
  sf_mex_assign(&c57_n_y, sf_mex_create("y", c57_o_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c57_b_y, c57_n_y, "KAInjection", "KAInjection", 0);
  c57_p_u = c57_c_u.MinDeltaThetaTransition;
  c57_o_y = NULL;
  sf_mex_assign(&c57_o_y, sf_mex_create("y", &c57_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_o_y, "MinDeltaThetaTransition",
                  "MinDeltaThetaTransition", 0);
  c57_q_u = c57_c_u.StartSecondGaitOnStep;
  c57_p_y = NULL;
  sf_mex_assign(&c57_p_y, sf_mex_create("y", &c57_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_p_y, "StartSecondGaitOnStep",
                  "StartSecondGaitOnStep", 0);
  for (c57_i214 = 0; c57_i214 < 6; c57_i214++) {
    c57_r_u[c57_i214] = c57_c_u.VBLAParams[c57_i214];
  }

  c57_q_y = NULL;
  sf_mex_assign(&c57_q_y, sf_mex_create("y", c57_r_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c57_b_y, c57_q_y, "VBLAParams", "VBLAParams", 0);
  for (c57_i215 = 0; c57_i215 < 13; c57_i215++) {
    c57_s_u[c57_i215] = c57_c_u.BalanceParams[c57_i215];
  }

  c57_r_y = NULL;
  sf_mex_assign(&c57_r_y, sf_mex_create("y", c57_s_u, 0, 0U, 1U, 0U, 1, 13),
                false);
  sf_mex_addfield(c57_b_y, c57_r_y, "BalanceParams", "BalanceParams", 0);
  for (c57_i216 = 0; c57_i216 < 5; c57_i216++) {
    c57_t_u[c57_i216] = c57_c_u.GaitTweaks[c57_i216];
  }

  c57_s_y = NULL;
  sf_mex_assign(&c57_s_y, sf_mex_create("y", c57_t_u, 0, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_addfield(c57_b_y, c57_s_y, "GaitTweaks", "GaitTweaks", 0);
  c57_u_u = c57_c_u.TStepInitial;
  c57_t_y = NULL;
  sf_mex_assign(&c57_t_y, sf_mex_create("y", &c57_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_t_y, "TStepInitial", "TStepInitial", 0);
  c57_v_u = c57_c_u.TMaxUpdate;
  c57_u_y = NULL;
  sf_mex_assign(&c57_u_y, sf_mex_create("y", &c57_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_u_y, "TMaxUpdate", "TMaxUpdate", 0);
  c57_w_u = c57_c_u.RunMode;
  c57_v_y = NULL;
  sf_mex_assign(&c57_v_y, sf_mex_create("y", &c57_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_v_y, "RunMode", "RunMode", 0);
  c57_x_u = c57_c_u.UseAbsoluteSwingLA;
  c57_w_y = NULL;
  sf_mex_assign(&c57_w_y, sf_mex_create("y", &c57_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_b_y, c57_w_y, "UseAbsoluteSwingLA", "UseAbsoluteSwingLA",
                  0);
  for (c57_i217 = 0; c57_i217 < 6; c57_i217++) {
    c57_y_u[c57_i217] = c57_c_u.ErrorZeroFactor[c57_i217];
  }

  c57_x_y = NULL;
  sf_mex_assign(&c57_x_y, sf_mex_create("y", c57_y_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c57_b_y, c57_x_y, "ErrorZeroFactor", "ErrorZeroFactor", 0);
  for (c57_i218 = 0; c57_i218 < 6; c57_i218++) {
    c57_ab_u[c57_i218] = c57_c_u.ErrorVelZeroFactor[c57_i218];
  }

  c57_y_y = NULL;
  sf_mex_assign(&c57_y_y, sf_mex_create("y", c57_ab_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c57_b_y, c57_y_y, "ErrorVelZeroFactor", "ErrorVelZeroFactor",
                  0);
  c57_bb_u = c57_c_u.StanceLegInit;
  c57_ab_y = NULL;
  sf_mex_assign(&c57_ab_y, sf_mex_create("y", &c57_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_ab_y, "StanceLegInit", "StanceLegInit", 0);
  c57_cb_u = c57_c_u.ControllerModeInit;
  c57_bb_y = NULL;
  sf_mex_assign(&c57_bb_y, sf_mex_create("y", &c57_cb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_bb_y, "ControllerModeInit", "ControllerModeInit",
                  0);
  c57_db_u = c57_c_u.UsePosingControl;
  c57_cb_y = NULL;
  sf_mex_assign(&c57_cb_y, sf_mex_create("y", &c57_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_cb_y, "UsePosingControl", "UsePosingControl", 0);
  c57_eb_u = c57_c_u.TPosing;
  c57_db_y = NULL;
  sf_mex_assign(&c57_db_y, sf_mex_create("y", &c57_eb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_db_y, "TPosing", "TPosing", 0);
  c57_fb_u = c57_c_u.TorsoBackAngle;
  c57_eb_y = NULL;
  sf_mex_assign(&c57_eb_y, sf_mex_create("y", &c57_fb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_eb_y, "TorsoBackAngle", "TorsoBackAngle", 0);
  c57_gb_u = c57_c_u.TorsoBackOnStep;
  c57_fb_y = NULL;
  sf_mex_assign(&c57_fb_y, sf_mex_create("y", &c57_gb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_fb_y, "TorsoBackOnStep", "TorsoBackOnStep", 0);
  c57_hb_u = c57_c_u.EnergyControlGain;
  c57_gb_y = NULL;
  sf_mex_assign(&c57_gb_y, sf_mex_create("y", &c57_hb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_gb_y, "EnergyControlGain", "EnergyControlGain", 0);
  c57_ib_u = c57_c_u.EnergyControlPhi0;
  c57_hb_y = NULL;
  sf_mex_assign(&c57_hb_y, sf_mex_create("y", &c57_ib_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_hb_y, "EnergyControlPhi0", "EnergyControlPhi0", 0);
  c57_jb_u = c57_c_u.VelocityControlTorsoMax;
  c57_ib_y = NULL;
  sf_mex_assign(&c57_ib_y, sf_mex_create("y", &c57_jb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_ib_y, "VelocityControlTorsoMax",
                  "VelocityControlTorsoMax", 0);
  c57_kb_u = c57_c_u.VelocityControlTorsoMin;
  c57_jb_y = NULL;
  sf_mex_assign(&c57_jb_y, sf_mex_create("y", &c57_kb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_jb_y, "VelocityControlTorsoMin",
                  "VelocityControlTorsoMin", 0);
  c57_lb_u = c57_c_u.VelocityControlTorsoGain;
  c57_kb_y = NULL;
  sf_mex_assign(&c57_kb_y, sf_mex_create("y", &c57_lb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_kb_y, "VelocityControlTorsoGain",
                  "VelocityControlTorsoGain", 0);
  c57_mb_u = c57_c_u.VelocityControlTorsoV0;
  c57_lb_y = NULL;
  sf_mex_assign(&c57_lb_y, sf_mex_create("y", &c57_mb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_lb_y, "VelocityControlTorsoV0",
                  "VelocityControlTorsoV0", 0);
  c57_nb_u = c57_c_u.MinDeltaTheta;
  c57_mb_y = NULL;
  sf_mex_assign(&c57_mb_y, sf_mex_create("y", &c57_nb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_mb_y, "MinDeltaTheta", "MinDeltaTheta", 0);
  c57_ob_u = c57_c_u.Theta0;
  c57_nb_y = NULL;
  sf_mex_assign(&c57_nb_y, sf_mex_create("y", &c57_ob_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_nb_y, "Theta0", "Theta0", 0);
  c57_pb_u = c57_c_u.KThetaPlus;
  c57_ob_y = NULL;
  sf_mex_assign(&c57_ob_y, sf_mex_create("y", &c57_pb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_ob_y, "KThetaPlus", "KThetaPlus", 0);
  c57_qb_u = c57_c_u.KThetaMinus;
  c57_pb_y = NULL;
  sf_mex_assign(&c57_pb_y, sf_mex_create("y", &c57_qb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_pb_y, "KThetaMinus", "KThetaMinus", 0);
  c57_rb_u = c57_c_u.RollPhaseVelocityThresh;
  c57_qb_y = NULL;
  sf_mex_assign(&c57_qb_y, sf_mex_create("y", &c57_rb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_qb_y, "RollPhaseVelocityThresh",
                  "RollPhaseVelocityThresh", 0);
  c57_sb_u = c57_c_u.RollPhaseSThresh;
  c57_rb_y = NULL;
  sf_mex_assign(&c57_rb_y, sf_mex_create("y", &c57_sb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_rb_y, "RollPhaseSThresh", "RollPhaseSThresh", 0);
  c57_tb_u = c57_c_u.MaxError;
  c57_sb_y = NULL;
  sf_mex_assign(&c57_sb_y, sf_mex_create("y", &c57_tb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_sb_y, "MaxError", "MaxError", 0);
  c57_ub_u = c57_c_u.MaxErrorVel;
  c57_tb_y = NULL;
  sf_mex_assign(&c57_tb_y, sf_mex_create("y", &c57_ub_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_tb_y, "MaxErrorVel", "MaxErrorVel", 0);
  c57_vb_u = c57_c_u.MaxErrorCount;
  c57_ub_y = NULL;
  sf_mex_assign(&c57_ub_y, sf_mex_create("y", &c57_vb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_ub_y, "MaxErrorCount", "MaxErrorCount", 0);
  for (c57_i219 = 0; c57_i219 < 6; c57_i219++) {
    c57_wb_u[c57_i219] = c57_c_u.K1MidStanceUpdate[c57_i219];
  }

  c57_vb_y = NULL;
  sf_mex_assign(&c57_vb_y, sf_mex_create("y", c57_wb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c57_b_y, c57_vb_y, "K1MidStanceUpdate", "K1MidStanceUpdate", 0);
  for (c57_i220 = 0; c57_i220 < 6; c57_i220++) {
    c57_xb_u[c57_i220] = c57_c_u.K2MidStanceUpdate[c57_i220];
  }

  c57_wb_y = NULL;
  sf_mex_assign(&c57_wb_y, sf_mex_create("y", c57_xb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c57_b_y, c57_wb_y, "K2MidStanceUpdate", "K2MidStanceUpdate", 0);
  c57_yb_u = c57_c_u.EnableVelocityBasedUpdate;
  c57_xb_y = NULL;
  sf_mex_assign(&c57_xb_y, sf_mex_create("y", &c57_yb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_xb_y, "EnableVelocityBasedUpdate",
                  "EnableVelocityBasedUpdate", 0);
  for (c57_i221 = 0; c57_i221 < 6; c57_i221++) {
    c57_ac_u[c57_i221] = c57_c_u.VelocityBasedUpdateK1[c57_i221];
  }

  c57_yb_y = NULL;
  sf_mex_assign(&c57_yb_y, sf_mex_create("y", c57_ac_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c57_b_y, c57_yb_y, "VelocityBasedUpdateK1",
                  "VelocityBasedUpdateK1", 0);
  for (c57_i222 = 0; c57_i222 < 6; c57_i222++) {
    c57_bc_u[c57_i222] = c57_c_u.VelocityBasedUpdateK2[c57_i222];
  }

  c57_ac_y = NULL;
  sf_mex_assign(&c57_ac_y, sf_mex_create("y", c57_bc_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c57_b_y, c57_ac_y, "VelocityBasedUpdateK2",
                  "VelocityBasedUpdateK2", 0);
  c57_cc_u = c57_c_u.VelocityBasedUpdateDTheta0;
  c57_bc_y = NULL;
  sf_mex_assign(&c57_bc_y, sf_mex_create("y", &c57_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_bc_y, "VelocityBasedUpdateDTheta0",
                  "VelocityBasedUpdateDTheta0", 0);
  for (c57_i223 = 0; c57_i223 < 12; c57_i223++) {
    c57_dc_u[c57_i223] = c57_c_u.VelocityBasedUpdateLimits[c57_i223];
  }

  c57_cc_y = NULL;
  sf_mex_assign(&c57_cc_y, sf_mex_create("y", c57_dc_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c57_b_y, c57_cc_y, "VelocityBasedUpdateLimits",
                  "VelocityBasedUpdateLimits", 0);
  c57_ec_u = c57_c_u.DesiredYawOffset;
  c57_dc_y = NULL;
  sf_mex_assign(&c57_dc_y, sf_mex_create("y", &c57_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_dc_y, "DesiredYawOffset", "DesiredYawOffset", 0);
  c57_fc_u = c57_c_u.dx_cmd;
  c57_ec_y = NULL;
  sf_mex_assign(&c57_ec_y, sf_mex_create("y", &c57_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_ec_y, "dx_cmd", "dx_cmd", 0);
  c57_gc_u = c57_c_u.ForBackward;
  c57_fc_y = NULL;
  sf_mex_assign(&c57_fc_y, sf_mex_create("y", &c57_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_fc_y, "ForBackward", "ForBackward", 0);
  c57_hc_u = c57_c_u.EnableFrictionID;
  c57_gc_y = NULL;
  sf_mex_assign(&c57_gc_y, sf_mex_create("y", &c57_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_gc_y, "EnableFrictionID", "EnableFrictionID", 0);
  c57_ic_u = c57_c_u.ResetFrictionPosing;
  c57_hc_y = NULL;
  sf_mex_assign(&c57_hc_y, sf_mex_create("y", &c57_ic_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_hc_y, "ResetFrictionPosing",
                  "ResetFrictionPosing", 0);
  c57_jc_u = c57_c_u.MoveLegIndex;
  c57_ic_y = NULL;
  sf_mex_assign(&c57_ic_y, sf_mex_create("y", &c57_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_ic_y, "MoveLegIndex", "MoveLegIndex", 0);
  c57_kc_u = c57_c_u.dy_cmd;
  c57_jc_y = NULL;
  sf_mex_assign(&c57_jc_y, sf_mex_create("y", &c57_kc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_b_y, c57_jc_y, "dy_cmd", "dy_cmd", 0);
  sf_mex_addfield(c57_y, c57_b_y, "Supervisory", "Supervisory", 0);
  c57_lc_u = c57_b_u.Discrete;
  c57_kc_y = NULL;
  sf_mex_assign(&c57_kc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c57_mc_u = c57_lc_u.TLastUpdate;
  c57_lc_y = NULL;
  sf_mex_assign(&c57_lc_y, sf_mex_create("y", &c57_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_kc_y, c57_lc_y, "TLastUpdate", "TLastUpdate", 0);
  c57_nc_u = c57_lc_u.VelocityControlLADelta;
  c57_mc_y = NULL;
  sf_mex_assign(&c57_mc_y, sf_mex_create("y", &c57_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_kc_y, c57_mc_y, "VelocityControlLADelta",
                  "VelocityControlLADelta", 0);
  c57_oc_u = c57_lc_u.VelocityControlTorsoDelta;
  c57_nc_y = NULL;
  sf_mex_assign(&c57_nc_y, sf_mex_create("y", &c57_oc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_kc_y, c57_nc_y, "VelocityControlTorsoDelta",
                  "VelocityControlTorsoDelta", 0);
  c57_pc_u = c57_lc_u.VelocityControlHipDistCur;
  c57_oc_y = NULL;
  sf_mex_assign(&c57_oc_y, sf_mex_create("y", &c57_pc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_kc_y, c57_oc_y, "VelocityControlHipDistCur",
                  "VelocityControlHipDistCur", 0);
  c57_qc_u = c57_lc_u.VelocityControlHipDistPrev;
  c57_pc_y = NULL;
  sf_mex_assign(&c57_pc_y, sf_mex_create("y", &c57_qc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_kc_y, c57_pc_y, "VelocityControlHipDistPrev",
                  "VelocityControlHipDistPrev", 0);
  c57_rc_u = c57_lc_u.VirtualSpringMode;
  c57_qc_y = NULL;
  sf_mex_assign(&c57_qc_y, sf_mex_create("y", &c57_rc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_kc_y, c57_qc_y, "VirtualSpringMode", "VirtualSpringMode",
                  0);
  c57_sc_u = c57_lc_u.VirtualSpringStiffness;
  c57_rc_y = NULL;
  sf_mex_assign(&c57_rc_y, sf_mex_create("y", &c57_sc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_kc_y, c57_rc_y, "VirtualSpringStiffness",
                  "VirtualSpringStiffness", 0);
  c57_tc_u = c57_lc_u.VirtualSpringDamping;
  c57_sc_y = NULL;
  sf_mex_assign(&c57_sc_y, sf_mex_create("y", &c57_tc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_kc_y, c57_sc_y, "VirtualSpringDamping",
                  "VirtualSpringDamping", 0);
  c57_uc_u = c57_lc_u.VirtualSpringModAmplitude;
  c57_tc_y = NULL;
  sf_mex_assign(&c57_tc_y, sf_mex_create("y", &c57_uc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_kc_y, c57_tc_y, "VirtualSpringModAmplitude",
                  "VirtualSpringModAmplitude", 0);
  c57_vc_u = c57_lc_u.VirtualSpringModRate;
  c57_uc_y = NULL;
  sf_mex_assign(&c57_uc_y, sf_mex_create("y", &c57_vc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_kc_y, c57_uc_y, "VirtualSpringModRate",
                  "VirtualSpringModRate", 0);
  c57_wc_u = c57_lc_u.VirtualSpringRestPos;
  c57_vc_y = NULL;
  sf_mex_assign(&c57_vc_y, sf_mex_create("y", &c57_wc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_kc_y, c57_vc_y, "VirtualSpringRestPos",
                  "VirtualSpringRestPos", 0);
  sf_mex_addfield(c57_y, c57_kc_y, "Discrete", "Discrete", 0);
  c57_xc_u = c57_b_u.Output;
  c57_wc_y = NULL;
  sf_mex_assign(&c57_wc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c57_i224 = 0; c57_i224 < 78; c57_i224++) {
    c57_yc_u[c57_i224] = c57_xc_u.H0[c57_i224];
  }

  c57_xc_y = NULL;
  sf_mex_assign(&c57_xc_y, sf_mex_create("y", c57_yc_u, 0, 0U, 1U, 0U, 2, 6, 13),
                false);
  sf_mex_addfield(c57_wc_y, c57_xc_y, "H0", "H0", 0);
  for (c57_i225 = 0; c57_i225 < 36; c57_i225++) {
    c57_ad_u[c57_i225] = c57_xc_u.HAlpha[c57_i225];
  }

  c57_yc_y = NULL;
  sf_mex_assign(&c57_yc_y, sf_mex_create("y", c57_ad_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c57_wc_y, c57_yc_y, "HAlpha", "HAlpha", 0);
  for (c57_i226 = 0; c57_i226 < 2; c57_i226++) {
    c57_bd_u[c57_i226] = c57_xc_u.ThetaLimits[c57_i226];
  }

  c57_ad_y = NULL;
  sf_mex_assign(&c57_ad_y, sf_mex_create("y", c57_bd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c57_wc_y, c57_ad_y, "ThetaLimits", "ThetaLimits", 0);
  c57_cd_u = c57_xc_u.Theta;
  c57_bd_y = NULL;
  sf_mex_assign(&c57_bd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c57_dd_u = c57_cd_u.c0;
  c57_cd_y = NULL;
  sf_mex_assign(&c57_cd_y, sf_mex_create("y", &c57_dd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_bd_y, c57_cd_y, "c0", "c0", 0);
  c57_ed_u = c57_cd_u.ct;
  c57_dd_y = NULL;
  sf_mex_assign(&c57_dd_y, sf_mex_create("y", &c57_ed_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_bd_y, c57_dd_y, "ct", "ct", 0);
  for (c57_i227 = 0; c57_i227 < 13; c57_i227++) {
    c57_fd_u[c57_i227] = c57_cd_u.cq[c57_i227];
  }

  c57_ed_y = NULL;
  sf_mex_assign(&c57_ed_y, sf_mex_create("y", c57_fd_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c57_bd_y, c57_ed_y, "cq", "cq", 0);
  c57_gd_u = c57_cd_u.t0;
  c57_fd_y = NULL;
  sf_mex_assign(&c57_fd_y, sf_mex_create("y", &c57_gd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_bd_y, c57_fd_y, "t0", "t0", 0);
  for (c57_i228 = 0; c57_i228 < 7; c57_i228++) {
    c57_hd_u[c57_i228] = c57_cd_u.cz[c57_i228];
  }

  c57_gd_y = NULL;
  sf_mex_assign(&c57_gd_y, sf_mex_create("y", c57_hd_u, 0, 0U, 1U, 0U, 2, 1, 7),
                false);
  sf_mex_addfield(c57_bd_y, c57_gd_y, "cz", "cz", 0);
  sf_mex_addfield(c57_wc_y, c57_bd_y, "Theta", "Theta", 0);
  c57_id_u = c57_xc_u.SaturateS;
  c57_hd_y = NULL;
  sf_mex_assign(&c57_hd_y, sf_mex_create("y", &c57_id_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_wc_y, c57_hd_y, "SaturateS", "SaturateS", 0);
  for (c57_i229 = 0; c57_i229 < 2; c57_i229++) {
    c57_jd_u[c57_i229] = c57_xc_u.SLimits[c57_i229];
  }

  c57_id_y = NULL;
  sf_mex_assign(&c57_id_y, sf_mex_create("y", c57_jd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c57_wc_y, c57_id_y, "SLimits", "SLimits", 0);
  c57_kd_u = c57_xc_u.EnforceIncreasingS;
  c57_jd_y = NULL;
  sf_mex_assign(&c57_jd_y, sf_mex_create("y", &c57_kd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_wc_y, c57_jd_y, "EnforceIncreasingS", "EnforceIncreasingS",
                  0);
  c57_ld_u = c57_xc_u.UseCorrection;
  c57_kd_y = NULL;
  sf_mex_assign(&c57_kd_y, sf_mex_create("y", &c57_ld_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_wc_y, c57_kd_y, "UseCorrection", "UseCorrection", 0);
  c57_md_u = c57_xc_u.SMaxCorrection;
  c57_ld_y = NULL;
  sf_mex_assign(&c57_ld_y, sf_mex_create("y", &c57_md_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_wc_y, c57_ld_y, "SMaxCorrection", "SMaxCorrection", 0);
  for (c57_i230 = 0; c57_i230 < 30; c57_i230++) {
    c57_nd_u[c57_i230] = c57_xc_u.HAlphaCorrection[c57_i230];
  }

  c57_md_y = NULL;
  sf_mex_assign(&c57_md_y, sf_mex_create("y", c57_nd_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c57_wc_y, c57_md_y, "HAlphaCorrection", "HAlphaCorrection", 0);
  c57_od_u = c57_xc_u.Phi;
  c57_nd_y = NULL;
  sf_mex_assign(&c57_nd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c57_pd_u = c57_od_u.c0;
  c57_od_y = NULL;
  sf_mex_assign(&c57_od_y, sf_mex_create("y", &c57_pd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_nd_y, c57_od_y, "c0", "c0", 0);
  for (c57_i231 = 0; c57_i231 < 13; c57_i231++) {
    c57_qd_u[c57_i231] = c57_od_u.cq[c57_i231];
  }

  c57_pd_y = NULL;
  sf_mex_assign(&c57_pd_y, sf_mex_create("y", c57_qd_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c57_nd_y, c57_pd_y, "cq", "cq", 0);
  sf_mex_addfield(c57_wc_y, c57_nd_y, "Phi", "Phi", 0);
  for (c57_i232 = 0; c57_i232 < 20; c57_i232++) {
    c57_rd_u[c57_i232] = c57_xc_u.PhiAlpha[c57_i232];
  }

  c57_qd_y = NULL;
  sf_mex_assign(&c57_qd_y, sf_mex_create("y", c57_rd_u, 0, 0U, 1U, 0U, 2, 1, 20),
                false);
  sf_mex_addfield(c57_wc_y, c57_qd_y, "PhiAlpha", "PhiAlpha", 0);
  c57_sd_u = c57_xc_u.SaturateR;
  c57_rd_y = NULL;
  sf_mex_assign(&c57_rd_y, sf_mex_create("y", &c57_sd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_wc_y, c57_rd_y, "SaturateR", "SaturateR", 0);
  for (c57_i233 = 0; c57_i233 < 2; c57_i233++) {
    c57_td_u[c57_i233] = c57_xc_u.RLimits[c57_i233];
  }

  c57_sd_y = NULL;
  sf_mex_assign(&c57_sd_y, sf_mex_create("y", c57_td_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c57_wc_y, c57_sd_y, "RLimits", "RLimits", 0);
  for (c57_i234 = 0; c57_i234 < 30; c57_i234++) {
    c57_ud_u[c57_i234] = c57_xc_u.HBarAlpha[c57_i234];
  }

  c57_td_y = NULL;
  sf_mex_assign(&c57_td_y, sf_mex_create("y", c57_ud_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c57_wc_y, c57_td_y, "HBarAlpha", "HBarAlpha", 0);
  for (c57_i235 = 0; c57_i235 < 12; c57_i235++) {
    c57_vd_u[c57_i235] = c57_xc_u.HBarLimits[c57_i235];
  }

  c57_ud_y = NULL;
  sf_mex_assign(&c57_ud_y, sf_mex_create("y", c57_vd_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c57_wc_y, c57_ud_y, "HBarLimits", "HBarLimits", 0);
  for (c57_i236 = 0; c57_i236 < 36; c57_i236++) {
    c57_wd_u[c57_i236] = c57_xc_u.HAlphaStar[c57_i236];
  }

  c57_vd_y = NULL;
  sf_mex_assign(&c57_vd_y, sf_mex_create("y", c57_wd_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c57_wc_y, c57_vd_y, "HAlphaStar", "HAlphaStar", 0);
  c57_xd_u = c57_xc_u.YawLimit;
  c57_wd_y = NULL;
  sf_mex_assign(&c57_wd_y, sf_mex_create("y", &c57_xd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_wc_y, c57_wd_y, "YawLimit", "YawLimit", 0);
  c57_yd_u = c57_xc_u.test;
  c57_xd_y = NULL;
  sf_mex_assign(&c57_xd_y, sf_mex_create("y", &c57_yd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_wc_y, c57_xd_y, "test", "test", 0);
  sf_mex_addfield(c57_y, c57_wc_y, "Output", "Output", 0);
  c57_ae_u = c57_b_u.Feedback;
  c57_yd_y = NULL;
  sf_mex_assign(&c57_yd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c57_i237 = 0; c57_i237 < 6; c57_i237++) {
    c57_be_u[c57_i237] = c57_ae_u.kp[c57_i237];
  }

  c57_ae_y = NULL;
  sf_mex_assign(&c57_ae_y, sf_mex_create("y", c57_be_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c57_yd_y, c57_ae_y, "kp", "kp", 0);
  for (c57_i238 = 0; c57_i238 < 6; c57_i238++) {
    c57_ce_u[c57_i238] = c57_ae_u.kd[c57_i238];
  }

  c57_be_y = NULL;
  sf_mex_assign(&c57_be_y, sf_mex_create("y", c57_ce_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c57_yd_y, c57_be_y, "kd", "kd", 0);
  for (c57_i239 = 0; c57_i239 < 2; c57_i239++) {
    c57_de_u[c57_i239] = c57_ae_u.epsilon[c57_i239];
  }

  c57_ce_y = NULL;
  sf_mex_assign(&c57_ce_y, sf_mex_create("y", c57_de_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c57_yd_y, c57_ce_y, "epsilon", "epsilon", 0);
  for (c57_i240 = 0; c57_i240 < 2; c57_i240++) {
    c57_ee_u[c57_i240] = c57_ae_u.kff_grav[c57_i240];
  }

  c57_de_y = NULL;
  sf_mex_assign(&c57_de_y, sf_mex_create("y", c57_ee_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c57_yd_y, c57_de_y, "kff_grav", "kff_grav", 0);
  c57_fe_u = c57_ae_u.delta_grav;
  c57_ee_y = NULL;
  sf_mex_assign(&c57_ee_y, sf_mex_create("y", &c57_fe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_ee_y, "delta_grav", "delta_grav", 0);
  for (c57_i241 = 0; c57_i241 < 2; c57_i241++) {
    c57_ge_u[c57_i241] = c57_ae_u.kff_decoup[c57_i241];
  }

  c57_fe_y = NULL;
  sf_mex_assign(&c57_fe_y, sf_mex_create("y", c57_ge_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c57_yd_y, c57_fe_y, "kff_decoup", "kff_decoup", 0);
  for (c57_i242 = 0; c57_i242 < 2; c57_i242++) {
    c57_he_u[c57_i242] = c57_ae_u.kd_torso[c57_i242];
  }

  c57_ge_y = NULL;
  sf_mex_assign(&c57_ge_y, sf_mex_create("y", c57_he_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c57_yd_y, c57_ge_y, "kd_torso", "kd_torso", 0);
  c57_ie_u = c57_ae_u.kp_2dof;
  c57_he_y = NULL;
  sf_mex_assign(&c57_he_y, sf_mex_create("y", &c57_ie_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_he_y, "kp_2dof", "kp_2dof", 0);
  c57_je_u = c57_ae_u.kd_2dof;
  c57_ie_y = NULL;
  sf_mex_assign(&c57_ie_y, sf_mex_create("y", &c57_je_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_ie_y, "kd_2dof", "kd_2dof", 0);
  c57_ke_u = c57_ae_u.kpre_2dof;
  c57_je_y = NULL;
  sf_mex_assign(&c57_je_y, sf_mex_create("y", &c57_ke_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_je_y, "kpre_2dof", "kpre_2dof", 0);
  c57_le_u = c57_ae_u.kp_lat;
  c57_ke_y = NULL;
  sf_mex_assign(&c57_ke_y, sf_mex_create("y", &c57_le_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_ke_y, "kp_lat", "kp_lat", 0);
  c57_me_u = c57_ae_u.kd_lat;
  c57_le_y = NULL;
  sf_mex_assign(&c57_le_y, sf_mex_create("y", &c57_me_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_le_y, "kd_lat", "kd_lat", 0);
  c57_ne_u = c57_ae_u.q3d_min_lat;
  c57_me_y = NULL;
  sf_mex_assign(&c57_me_y, sf_mex_create("y", &c57_ne_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_me_y, "q3d_min_lat", "q3d_min_lat", 0);
  c57_oe_u = c57_ae_u.q3d_max_lat;
  c57_ne_y = NULL;
  sf_mex_assign(&c57_ne_y, sf_mex_create("y", &c57_oe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_ne_y, "q3d_max_lat", "q3d_max_lat", 0);
  c57_pe_u = c57_ae_u.w_torso_lat;
  c57_oe_y = NULL;
  sf_mex_assign(&c57_oe_y, sf_mex_create("y", &c57_pe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_oe_y, "w_torso_lat", "w_torso_lat", 0);
  for (c57_i243 = 0; c57_i243 < 6; c57_i243++) {
    c57_qe_u[c57_i243] = c57_ae_u.u_ff[c57_i243];
  }

  c57_pe_y = NULL;
  sf_mex_assign(&c57_pe_y, sf_mex_create("y", c57_qe_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c57_yd_y, c57_pe_y, "u_ff", "u_ff", 0);
  c57_re_u = c57_ae_u.LateralControlMode;
  c57_qe_y = NULL;
  sf_mex_assign(&c57_qe_y, sf_mex_create("y", &c57_re_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_qe_y, "LateralControlMode", "LateralControlMode",
                  0);
  c57_se_u = c57_ae_u.DecouplingMode;
  c57_re_y = NULL;
  sf_mex_assign(&c57_re_y, sf_mex_create("y", &c57_se_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_re_y, "DecouplingMode", "DecouplingMode", 0);
  c57_te_u = c57_ae_u.Use2DOF;
  c57_se_y = NULL;
  sf_mex_assign(&c57_se_y, sf_mex_create("y", &c57_te_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_se_y, "Use2DOF", "Use2DOF", 0);
  c57_ue_u = c57_ae_u.UseDSGravComp;
  c57_te_y = NULL;
  sf_mex_assign(&c57_te_y, sf_mex_create("y", &c57_ue_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_te_y, "UseDSGravComp", "UseDSGravComp", 0);
  c57_ve_u = c57_ae_u.lat_bias;
  c57_ue_y = NULL;
  sf_mex_assign(&c57_ue_y, sf_mex_create("y", &c57_ve_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_ue_y, "lat_bias", "lat_bias", 0);
  c57_we_u = c57_ae_u.lat_bias2;
  c57_ve_y = NULL;
  sf_mex_assign(&c57_ve_y, sf_mex_create("y", &c57_we_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_ve_y, "lat_bias2", "lat_bias2", 0);
  c57_xe_u = c57_ae_u.linkFeedback;
  c57_we_y = NULL;
  sf_mex_assign(&c57_we_y, sf_mex_create("y", &c57_xe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_we_y, "linkFeedback", "linkFeedback", 0);
  c57_ye_u = c57_ae_u.RIO;
  c57_xe_y = NULL;
  sf_mex_assign(&c57_xe_y, sf_mex_create("y", &c57_ye_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_xe_y, "RIO", "RIO", 0);
  c57_af_u = c57_ae_u.SelectFeedforward;
  c57_ye_y = NULL;
  sf_mex_assign(&c57_ye_y, sf_mex_create("y", &c57_af_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_ye_y, "SelectFeedforward", "SelectFeedforward",
                  0);
  for (c57_i244 = 0; c57_i244 < 6; c57_i244++) {
    c57_bf_u[c57_i244] = c57_ae_u.FeedforwardGain[c57_i244];
  }

  c57_af_y = NULL;
  sf_mex_assign(&c57_af_y, sf_mex_create("y", c57_bf_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c57_yd_y, c57_af_y, "FeedforwardGain", "FeedforwardGain", 0);
  c57_cf_u = c57_ae_u.EnableFeedforwardOnStep;
  c57_bf_y = NULL;
  sf_mex_assign(&c57_bf_y, sf_mex_create("y", &c57_cf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_yd_y, c57_bf_y, "EnableFeedforwardOnStep",
                  "EnableFeedforwardOnStep", 0);
  sf_mex_addfield(c57_y, c57_yd_y, "Feedback", "Feedback", 0);
  c57_df_u = c57_b_u.Saturation;
  c57_cf_y = NULL;
  sf_mex_assign(&c57_cf_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c57_ef_u = c57_df_u.UseQPSaturation;
  c57_df_y = NULL;
  sf_mex_assign(&c57_df_y, sf_mex_create("y", &c57_ef_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_cf_y, c57_df_y, "UseQPSaturation", "UseQPSaturation", 0);
  for (c57_i245 = 0; c57_i245 < 2; c57_i245++) {
    c57_ff_u[c57_i245] = c57_df_u.QPWeight[c57_i245];
  }

  c57_ef_y = NULL;
  sf_mex_assign(&c57_ef_y, sf_mex_create("y", c57_ff_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c57_cf_y, c57_ef_y, "QPWeight", "QPWeight", 0);
  c57_gf_u = c57_df_u.UseKASaturation;
  c57_ff_y = NULL;
  sf_mex_assign(&c57_ff_y, sf_mex_create("y", &c57_gf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_cf_y, c57_ff_y, "UseKASaturation", "UseKASaturation", 0);
  c57_hf_u = c57_df_u.KASaturationS1;
  c57_gf_y = NULL;
  sf_mex_assign(&c57_gf_y, sf_mex_create("y", &c57_hf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_cf_y, c57_gf_y, "KASaturationS1", "KASaturationS1", 0);
  c57_if_u = c57_df_u.KASaturationS2;
  c57_hf_y = NULL;
  sf_mex_assign(&c57_hf_y, sf_mex_create("y", &c57_if_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_cf_y, c57_hf_y, "KASaturationS2", "KASaturationS2", 0);
  c57_jf_u = c57_df_u.KASaturationEarly;
  c57_if_y = NULL;
  sf_mex_assign(&c57_if_y, sf_mex_create("y", &c57_jf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_cf_y, c57_if_y, "KASaturationEarly", "KASaturationEarly",
                  0);
  c57_kf_u = c57_df_u.KASaturationMax;
  c57_jf_y = NULL;
  sf_mex_assign(&c57_jf_y, sf_mex_create("y", &c57_kf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c57_cf_y, c57_jf_y, "KASaturationMax", "KASaturationMax", 0);
  sf_mex_addfield(c57_y, c57_cf_y, "Saturation", "Saturation", 0);
  sf_mex_assign(&c57_mxArrayOutData, c57_y, false);
  return c57_mxArrayOutData;
}

static const mxArray *c57_c_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData)
{
  const mxArray *c57_mxArrayOutData = NULL;
  c57_ControlStateBus c57_b_u;
  const mxArray *c57_y = NULL;
  real_T c57_c_u;
  const mxArray *c57_b_y = NULL;
  real_T c57_d_u;
  const mxArray *c57_c_y = NULL;
  real_T c57_e_u;
  const mxArray *c57_d_y = NULL;
  real_T c57_f_u;
  const mxArray *c57_e_y = NULL;
  real_T c57_g_u;
  const mxArray *c57_f_y = NULL;
  real_T c57_h_u;
  const mxArray *c57_g_y = NULL;
  real_T c57_i_u;
  const mxArray *c57_h_y = NULL;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_mxArrayOutData = NULL;
  c57_b_u = *(c57_ControlStateBus *)c57_inData;
  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c57_c_u = c57_b_u.ControllerMode;
  c57_b_y = NULL;
  sf_mex_assign(&c57_b_y, sf_mex_create("y", &c57_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_y, c57_b_y, "ControllerMode", "ControllerMode", 0);
  c57_d_u = c57_b_u.SupportState;
  c57_c_y = NULL;
  sf_mex_assign(&c57_c_y, sf_mex_create("y", &c57_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_y, c57_c_y, "SupportState", "SupportState", 0);
  c57_e_u = c57_b_u.StanceLeg;
  c57_d_y = NULL;
  sf_mex_assign(&c57_d_y, sf_mex_create("y", &c57_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_y, c57_d_y, "StanceLeg", "StanceLeg", 0);
  c57_f_u = c57_b_u.InDoubleSupport;
  c57_e_y = NULL;
  sf_mex_assign(&c57_e_y, sf_mex_create("y", &c57_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_y, c57_e_y, "InDoubleSupport", "InDoubleSupport", 0);
  c57_g_u = c57_b_u.RollPhase;
  c57_f_y = NULL;
  sf_mex_assign(&c57_f_y, sf_mex_create("y", &c57_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_y, c57_f_y, "RollPhase", "RollPhase", 0);
  c57_h_u = c57_b_u.StepCount;
  c57_g_y = NULL;
  sf_mex_assign(&c57_g_y, sf_mex_create("y", &c57_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_y, c57_g_y, "StepCount", "StepCount", 0);
  c57_i_u = c57_b_u.Error;
  c57_h_y = NULL;
  sf_mex_assign(&c57_h_y, sf_mex_create("y", &c57_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c57_y, c57_h_y, "Error", "Error", 0);
  sf_mex_assign(&c57_mxArrayOutData, c57_y, false);
  return c57_mxArrayOutData;
}

static const mxArray *c57_d_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData)
{
  const mxArray *c57_mxArrayOutData = NULL;
  int32_T c57_i246;
  real_T c57_b_inData[2];
  int32_T c57_i247;
  real_T c57_b_u[2];
  const mxArray *c57_y = NULL;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_mxArrayOutData = NULL;
  for (c57_i246 = 0; c57_i246 < 2; c57_i246++) {
    c57_b_inData[c57_i246] = (*(real_T (*)[2])c57_inData)[c57_i246];
  }

  for (c57_i247 = 0; c57_i247 < 2; c57_i247++) {
    c57_b_u[c57_i247] = c57_b_inData[c57_i247];
  }

  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", c57_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c57_mxArrayOutData, c57_y, false);
  return c57_mxArrayOutData;
}

static const mxArray *c57_e_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData)
{
  const mxArray *c57_mxArrayOutData = NULL;
  real_T c57_b_u;
  const mxArray *c57_y = NULL;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_mxArrayOutData = NULL;
  c57_b_u = *(real_T *)c57_inData;
  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", &c57_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c57_mxArrayOutData, c57_y, false);
  return c57_mxArrayOutData;
}

static real_T c57_c_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId)
{
  real_T c57_y;
  real_T c57_d27;
  (void)chartInstance;
  sf_mex_import(c57_parentId, sf_mex_dup(c57_b_u), &c57_d27, 1, 0, 0U, 0, 0U, 0);
  c57_y = c57_d27;
  sf_mex_destroy(&c57_b_u);
  return c57_y;
}

static void c57_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData)
{
  const mxArray *c57_nargout;
  const char_T *c57_identifier;
  emlrtMsgIdentifier c57_thisId;
  real_T c57_y;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_nargout = sf_mex_dup(c57_mxArrayInData);
  c57_identifier = c57_varName;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_y = c57_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c57_nargout),
    &c57_thisId);
  sf_mex_destroy(&c57_nargout);
  *(real_T *)c57_outData = c57_y;
  sf_mex_destroy(&c57_mxArrayInData);
}

static const mxArray *c57_f_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData)
{
  const mxArray *c57_mxArrayOutData = NULL;
  int32_T c57_i248;
  int32_T c57_i249;
  int32_T c57_i250;
  real_T c57_b_inData[36];
  int32_T c57_i251;
  int32_T c57_i252;
  int32_T c57_i253;
  real_T c57_b_u[36];
  const mxArray *c57_y = NULL;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_mxArrayOutData = NULL;
  c57_i248 = 0;
  for (c57_i249 = 0; c57_i249 < 6; c57_i249++) {
    for (c57_i250 = 0; c57_i250 < 6; c57_i250++) {
      c57_b_inData[c57_i250 + c57_i248] = (*(real_T (*)[36])c57_inData)[c57_i250
        + c57_i248];
    }

    c57_i248 += 6;
  }

  c57_i251 = 0;
  for (c57_i252 = 0; c57_i252 < 6; c57_i252++) {
    for (c57_i253 = 0; c57_i253 < 6; c57_i253++) {
      c57_b_u[c57_i253 + c57_i251] = c57_b_inData[c57_i253 + c57_i251];
    }

    c57_i251 += 6;
  }

  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", c57_b_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_assign(&c57_mxArrayOutData, c57_y, false);
  return c57_mxArrayOutData;
}

static void c57_d_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId,
  real_T c57_y[36])
{
  real_T c57_dv5[36];
  int32_T c57_i254;
  (void)chartInstance;
  sf_mex_import(c57_parentId, sf_mex_dup(c57_b_u), c57_dv5, 1, 0, 0U, 1, 0U, 2,
                6, 6);
  for (c57_i254 = 0; c57_i254 < 36; c57_i254++) {
    c57_y[c57_i254] = c57_dv5[c57_i254];
  }

  sf_mex_destroy(&c57_b_u);
}

static void c57_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData)
{
  const mxArray *c57_T0;
  const char_T *c57_identifier;
  emlrtMsgIdentifier c57_thisId;
  real_T c57_y[36];
  int32_T c57_i255;
  int32_T c57_i256;
  int32_T c57_i257;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_T0 = sf_mex_dup(c57_mxArrayInData);
  c57_identifier = c57_varName;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c57_T0), &c57_thisId, c57_y);
  sf_mex_destroy(&c57_T0);
  c57_i255 = 0;
  for (c57_i256 = 0; c57_i256 < 6; c57_i256++) {
    for (c57_i257 = 0; c57_i257 < 6; c57_i257++) {
      (*(real_T (*)[36])c57_outData)[c57_i257 + c57_i255] = c57_y[c57_i257 +
        c57_i255];
    }

    c57_i255 += 6;
  }

  sf_mex_destroy(&c57_mxArrayInData);
}

static void c57_e_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId,
  real_T c57_y[2])
{
  real_T c57_dv6[2];
  int32_T c57_i258;
  (void)chartInstance;
  sf_mex_import(c57_parentId, sf_mex_dup(c57_b_u), c57_dv6, 1, 0, 0U, 1, 0U, 1,
                2);
  for (c57_i258 = 0; c57_i258 < 2; c57_i258++) {
    c57_y[c57_i258] = c57_dv6[c57_i258];
  }

  sf_mex_destroy(&c57_b_u);
}

static void c57_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData)
{
  const mxArray *c57_uL;
  const char_T *c57_identifier;
  emlrtMsgIdentifier c57_thisId;
  real_T c57_y[2];
  int32_T c57_i259;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_uL = sf_mex_dup(c57_mxArrayInData);
  c57_identifier = c57_varName;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c57_uL), &c57_thisId, c57_y);
  sf_mex_destroy(&c57_uL);
  for (c57_i259 = 0; c57_i259 < 2; c57_i259++) {
    (*(real_T (*)[2])c57_outData)[c57_i259] = c57_y[c57_i259];
  }

  sf_mex_destroy(&c57_mxArrayInData);
}

static const mxArray *c57_g_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData)
{
  const mxArray *c57_mxArrayOutData = NULL;
  int32_T c57_i260;
  real_T c57_b_inData[4];
  int32_T c57_i261;
  real_T c57_b_u[4];
  const mxArray *c57_y = NULL;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_mxArrayOutData = NULL;
  for (c57_i260 = 0; c57_i260 < 4; c57_i260++) {
    c57_b_inData[c57_i260] = (*(real_T (*)[4])c57_inData)[c57_i260];
  }

  for (c57_i261 = 0; c57_i261 < 4; c57_i261++) {
    c57_b_u[c57_i261] = c57_b_inData[c57_i261];
  }

  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", c57_b_u, 0, 0U, 1U, 0U, 1, 4), false);
  sf_mex_assign(&c57_mxArrayOutData, c57_y, false);
  return c57_mxArrayOutData;
}

static void c57_f_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId,
  real_T c57_y[4])
{
  real_T c57_dv7[4];
  int32_T c57_i262;
  (void)chartInstance;
  sf_mex_import(c57_parentId, sf_mex_dup(c57_b_u), c57_dv7, 1, 0, 0U, 1, 0U, 1,
                4);
  for (c57_i262 = 0; c57_i262 < 4; c57_i262++) {
    c57_y[c57_i262] = c57_dv7[c57_i262];
  }

  sf_mex_destroy(&c57_b_u);
}

static void c57_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData)
{
  const mxArray *c57_L_opt;
  const char_T *c57_identifier;
  emlrtMsgIdentifier c57_thisId;
  real_T c57_y[4];
  int32_T c57_i263;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_L_opt = sf_mex_dup(c57_mxArrayInData);
  c57_identifier = c57_varName;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c57_L_opt), &c57_thisId,
    c57_y);
  sf_mex_destroy(&c57_L_opt);
  for (c57_i263 = 0; c57_i263 < 4; c57_i263++) {
    (*(real_T (*)[4])c57_outData)[c57_i263] = c57_y[c57_i263];
  }

  sf_mex_destroy(&c57_mxArrayInData);
}

const mxArray *sf_c57_Walking01_DDA3D_get_eml_resolved_functions_info(void)
{
  const mxArray *c57_nameCaptureInfo = NULL;
  c57_nameCaptureInfo = NULL;
  sf_mex_assign(&c57_nameCaptureInfo, sf_mex_createstruct("structure", 2, 190, 1),
                false);
  c57_info_helper(&c57_nameCaptureInfo);
  c57_b_info_helper(&c57_nameCaptureInfo);
  c57_c_info_helper(&c57_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c57_nameCaptureInfo);
  return c57_nameCaptureInfo;
}

static void c57_info_helper(const mxArray **c57_info)
{
  const mxArray *c57_rhs0 = NULL;
  const mxArray *c57_lhs0 = NULL;
  const mxArray *c57_rhs1 = NULL;
  const mxArray *c57_lhs1 = NULL;
  const mxArray *c57_rhs2 = NULL;
  const mxArray *c57_lhs2 = NULL;
  const mxArray *c57_rhs3 = NULL;
  const mxArray *c57_lhs3 = NULL;
  const mxArray *c57_rhs4 = NULL;
  const mxArray *c57_lhs4 = NULL;
  const mxArray *c57_rhs5 = NULL;
  const mxArray *c57_lhs5 = NULL;
  const mxArray *c57_rhs6 = NULL;
  const mxArray *c57_lhs6 = NULL;
  const mxArray *c57_rhs7 = NULL;
  const mxArray *c57_lhs7 = NULL;
  const mxArray *c57_rhs8 = NULL;
  const mxArray *c57_lhs8 = NULL;
  const mxArray *c57_rhs9 = NULL;
  const mxArray *c57_lhs9 = NULL;
  const mxArray *c57_rhs10 = NULL;
  const mxArray *c57_lhs10 = NULL;
  const mxArray *c57_rhs11 = NULL;
  const mxArray *c57_lhs11 = NULL;
  const mxArray *c57_rhs12 = NULL;
  const mxArray *c57_lhs12 = NULL;
  const mxArray *c57_rhs13 = NULL;
  const mxArray *c57_lhs13 = NULL;
  const mxArray *c57_rhs14 = NULL;
  const mxArray *c57_lhs14 = NULL;
  const mxArray *c57_rhs15 = NULL;
  const mxArray *c57_lhs15 = NULL;
  const mxArray *c57_rhs16 = NULL;
  const mxArray *c57_lhs16 = NULL;
  const mxArray *c57_rhs17 = NULL;
  const mxArray *c57_lhs17 = NULL;
  const mxArray *c57_rhs18 = NULL;
  const mxArray *c57_lhs18 = NULL;
  const mxArray *c57_rhs19 = NULL;
  const mxArray *c57_lhs19 = NULL;
  const mxArray *c57_rhs20 = NULL;
  const mxArray *c57_lhs20 = NULL;
  const mxArray *c57_rhs21 = NULL;
  const mxArray *c57_lhs21 = NULL;
  const mxArray *c57_rhs22 = NULL;
  const mxArray *c57_lhs22 = NULL;
  const mxArray *c57_rhs23 = NULL;
  const mxArray *c57_lhs23 = NULL;
  const mxArray *c57_rhs24 = NULL;
  const mxArray *c57_lhs24 = NULL;
  const mxArray *c57_rhs25 = NULL;
  const mxArray *c57_lhs25 = NULL;
  const mxArray *c57_rhs26 = NULL;
  const mxArray *c57_lhs26 = NULL;
  const mxArray *c57_rhs27 = NULL;
  const mxArray *c57_lhs27 = NULL;
  const mxArray *c57_rhs28 = NULL;
  const mxArray *c57_lhs28 = NULL;
  const mxArray *c57_rhs29 = NULL;
  const mxArray *c57_lhs29 = NULL;
  const mxArray *c57_rhs30 = NULL;
  const mxArray *c57_lhs30 = NULL;
  const mxArray *c57_rhs31 = NULL;
  const mxArray *c57_lhs31 = NULL;
  const mxArray *c57_rhs32 = NULL;
  const mxArray *c57_lhs32 = NULL;
  const mxArray *c57_rhs33 = NULL;
  const mxArray *c57_lhs33 = NULL;
  const mxArray *c57_rhs34 = NULL;
  const mxArray *c57_lhs34 = NULL;
  const mxArray *c57_rhs35 = NULL;
  const mxArray *c57_lhs35 = NULL;
  const mxArray *c57_rhs36 = NULL;
  const mxArray *c57_lhs36 = NULL;
  const mxArray *c57_rhs37 = NULL;
  const mxArray *c57_lhs37 = NULL;
  const mxArray *c57_rhs38 = NULL;
  const mxArray *c57_lhs38 = NULL;
  const mxArray *c57_rhs39 = NULL;
  const mxArray *c57_lhs39 = NULL;
  const mxArray *c57_rhs40 = NULL;
  const mxArray *c57_lhs40 = NULL;
  const mxArray *c57_rhs41 = NULL;
  const mxArray *c57_lhs41 = NULL;
  const mxArray *c57_rhs42 = NULL;
  const mxArray *c57_lhs42 = NULL;
  const mxArray *c57_rhs43 = NULL;
  const mxArray *c57_lhs43 = NULL;
  const mxArray *c57_rhs44 = NULL;
  const mxArray *c57_lhs44 = NULL;
  const mxArray *c57_rhs45 = NULL;
  const mxArray *c57_lhs45 = NULL;
  const mxArray *c57_rhs46 = NULL;
  const mxArray *c57_lhs46 = NULL;
  const mxArray *c57_rhs47 = NULL;
  const mxArray *c57_lhs47 = NULL;
  const mxArray *c57_rhs48 = NULL;
  const mxArray *c57_lhs48 = NULL;
  const mxArray *c57_rhs49 = NULL;
  const mxArray *c57_lhs49 = NULL;
  const mxArray *c57_rhs50 = NULL;
  const mxArray *c57_lhs50 = NULL;
  const mxArray *c57_rhs51 = NULL;
  const mxArray *c57_lhs51 = NULL;
  const mxArray *c57_rhs52 = NULL;
  const mxArray *c57_lhs52 = NULL;
  const mxArray *c57_rhs53 = NULL;
  const mxArray *c57_lhs53 = NULL;
  const mxArray *c57_rhs54 = NULL;
  const mxArray *c57_lhs54 = NULL;
  const mxArray *c57_rhs55 = NULL;
  const mxArray *c57_lhs55 = NULL;
  const mxArray *c57_rhs56 = NULL;
  const mxArray *c57_lhs56 = NULL;
  const mxArray *c57_rhs57 = NULL;
  const mxArray *c57_lhs57 = NULL;
  const mxArray *c57_rhs58 = NULL;
  const mxArray *c57_lhs58 = NULL;
  const mxArray *c57_rhs59 = NULL;
  const mxArray *c57_lhs59 = NULL;
  const mxArray *c57_rhs60 = NULL;
  const mxArray *c57_lhs60 = NULL;
  const mxArray *c57_rhs61 = NULL;
  const mxArray *c57_lhs61 = NULL;
  const mxArray *c57_rhs62 = NULL;
  const mxArray *c57_lhs62 = NULL;
  const mxArray *c57_rhs63 = NULL;
  const mxArray *c57_lhs63 = NULL;
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 0);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c57_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 1);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c57_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 2);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c57_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 3);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 3);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c57_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 4);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c57_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 5);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  5);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c57_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 6);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c57_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 7);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c57_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 8);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 8);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c57_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 9);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 9);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c57_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 10);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 10);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c57_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 11);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 11);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c57_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 12);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.refblas.xgemm"), "name", "name", 12);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c57_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "context", "context", 13);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("mrdivide"), "name", "name",
                  13);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 13);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c57_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 14);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 14);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c57_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 15);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("rdivide"), "name", "name",
                  15);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c57_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 16);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c57_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 17);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c57_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_div"), "name", "name",
                  18);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c57_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 19);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c57_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "context", "context", 20);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("LA_LS_Revised_Saturation"),
                  "name", "name", 20);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1433294351U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c57_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 21);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_1"), "name", "name", 21);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_1.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1433294351U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c57_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_1.m"),
                  "context", "context", 22);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("mrdivide"), "name", "name",
                  22);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c57_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_2"), "name", "name", 23);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_2.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1433294351U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c57_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_2.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("mrdivide"), "name", "name",
                  24);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c57_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_3"), "name", "name", 25);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_3.m"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1433294351U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c57_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_3.m"),
                  "context", "context", 26);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("mrdivide"), "name", "name",
                  26);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c57_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 27);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_4"), "name", "name", 27);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_4.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1433294351U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c57_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_4.m"),
                  "context", "context", 28);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("mrdivide"), "name", "name",
                  28);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 28);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c57_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 29);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_5"), "name", "name", 29);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_5.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1433294351U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c57_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_5.m"),
                  "context", "context", 30);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("mrdivide"), "name", "name",
                  30);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c57_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 31);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_6"), "name", "name", 31);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_6.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1433294351U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c57_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_6.m"),
                  "context", "context", 32);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("mrdivide"), "name", "name",
                  32);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c57_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 33);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_7"), "name", "name", 33);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_7.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1433294351U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c57_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_7.m"),
                  "context", "context", 34);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("mrdivide"), "name", "name",
                  34);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 34);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c57_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 35);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_8"), "name", "name", 35);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_8.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1433294351U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c57_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_8.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("mrdivide"), "name", "name",
                  36);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c57_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "LA_LS_Revised_Saturation_Case_9"), "name", "name", 37);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_9.m"),
                  "resolved", "resolved", 37);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1433294351U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c57_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation_Case_9.m"),
                  "context", "context", 38);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("mrdivide"), "name", "name",
                  38);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c57_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 39);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("max"), "name", "name", 39);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c57_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 40);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c57_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 41);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_const_nonsingleton_dim"),
                  "name", "name", 41);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c57_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_const_nonsingleton_dim.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 42);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c57_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 43);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 43);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 43);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c57_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum"),
                  "context", "context", 44);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 44);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c57_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 45);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 45);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c57_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 46);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("isnan"), "name", "name", 46);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c57_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 47);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c57_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 48);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 48);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 48);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c57_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 49);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 49);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 49);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c57_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 50);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 50);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c57_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 51);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("isfi"), "name", "name", 51);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 51);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c57_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 52);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 52);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 52);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c57_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 53);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("intmax"), "name", "name", 53);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c57_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 54);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 54);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c57_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 55);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("intmin"), "name", "name", 55);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c57_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 56);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c57_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_extremum_sub"),
                  "context", "context", 57);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_relop"), "name", "name",
                  57);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("function_handle"),
                  "dominantType", "dominantType", 57);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_relop.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1342472782U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c57_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/QP/LA_LS_Revised_Saturation.m"),
                  "context", "context", 58);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("min"), "name", "name", 58);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c57_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 59);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c57_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "context", "context", 60);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("min"), "name", "name", 60);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 60);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c57_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 61);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 61);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 61);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c57_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 62);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 62);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 62);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c57_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 63);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 63);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c57_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c57_rhs0);
  sf_mex_destroy(&c57_lhs0);
  sf_mex_destroy(&c57_rhs1);
  sf_mex_destroy(&c57_lhs1);
  sf_mex_destroy(&c57_rhs2);
  sf_mex_destroy(&c57_lhs2);
  sf_mex_destroy(&c57_rhs3);
  sf_mex_destroy(&c57_lhs3);
  sf_mex_destroy(&c57_rhs4);
  sf_mex_destroy(&c57_lhs4);
  sf_mex_destroy(&c57_rhs5);
  sf_mex_destroy(&c57_lhs5);
  sf_mex_destroy(&c57_rhs6);
  sf_mex_destroy(&c57_lhs6);
  sf_mex_destroy(&c57_rhs7);
  sf_mex_destroy(&c57_lhs7);
  sf_mex_destroy(&c57_rhs8);
  sf_mex_destroy(&c57_lhs8);
  sf_mex_destroy(&c57_rhs9);
  sf_mex_destroy(&c57_lhs9);
  sf_mex_destroy(&c57_rhs10);
  sf_mex_destroy(&c57_lhs10);
  sf_mex_destroy(&c57_rhs11);
  sf_mex_destroy(&c57_lhs11);
  sf_mex_destroy(&c57_rhs12);
  sf_mex_destroy(&c57_lhs12);
  sf_mex_destroy(&c57_rhs13);
  sf_mex_destroy(&c57_lhs13);
  sf_mex_destroy(&c57_rhs14);
  sf_mex_destroy(&c57_lhs14);
  sf_mex_destroy(&c57_rhs15);
  sf_mex_destroy(&c57_lhs15);
  sf_mex_destroy(&c57_rhs16);
  sf_mex_destroy(&c57_lhs16);
  sf_mex_destroy(&c57_rhs17);
  sf_mex_destroy(&c57_lhs17);
  sf_mex_destroy(&c57_rhs18);
  sf_mex_destroy(&c57_lhs18);
  sf_mex_destroy(&c57_rhs19);
  sf_mex_destroy(&c57_lhs19);
  sf_mex_destroy(&c57_rhs20);
  sf_mex_destroy(&c57_lhs20);
  sf_mex_destroy(&c57_rhs21);
  sf_mex_destroy(&c57_lhs21);
  sf_mex_destroy(&c57_rhs22);
  sf_mex_destroy(&c57_lhs22);
  sf_mex_destroy(&c57_rhs23);
  sf_mex_destroy(&c57_lhs23);
  sf_mex_destroy(&c57_rhs24);
  sf_mex_destroy(&c57_lhs24);
  sf_mex_destroy(&c57_rhs25);
  sf_mex_destroy(&c57_lhs25);
  sf_mex_destroy(&c57_rhs26);
  sf_mex_destroy(&c57_lhs26);
  sf_mex_destroy(&c57_rhs27);
  sf_mex_destroy(&c57_lhs27);
  sf_mex_destroy(&c57_rhs28);
  sf_mex_destroy(&c57_lhs28);
  sf_mex_destroy(&c57_rhs29);
  sf_mex_destroy(&c57_lhs29);
  sf_mex_destroy(&c57_rhs30);
  sf_mex_destroy(&c57_lhs30);
  sf_mex_destroy(&c57_rhs31);
  sf_mex_destroy(&c57_lhs31);
  sf_mex_destroy(&c57_rhs32);
  sf_mex_destroy(&c57_lhs32);
  sf_mex_destroy(&c57_rhs33);
  sf_mex_destroy(&c57_lhs33);
  sf_mex_destroy(&c57_rhs34);
  sf_mex_destroy(&c57_lhs34);
  sf_mex_destroy(&c57_rhs35);
  sf_mex_destroy(&c57_lhs35);
  sf_mex_destroy(&c57_rhs36);
  sf_mex_destroy(&c57_lhs36);
  sf_mex_destroy(&c57_rhs37);
  sf_mex_destroy(&c57_lhs37);
  sf_mex_destroy(&c57_rhs38);
  sf_mex_destroy(&c57_lhs38);
  sf_mex_destroy(&c57_rhs39);
  sf_mex_destroy(&c57_lhs39);
  sf_mex_destroy(&c57_rhs40);
  sf_mex_destroy(&c57_lhs40);
  sf_mex_destroy(&c57_rhs41);
  sf_mex_destroy(&c57_lhs41);
  sf_mex_destroy(&c57_rhs42);
  sf_mex_destroy(&c57_lhs42);
  sf_mex_destroy(&c57_rhs43);
  sf_mex_destroy(&c57_lhs43);
  sf_mex_destroy(&c57_rhs44);
  sf_mex_destroy(&c57_lhs44);
  sf_mex_destroy(&c57_rhs45);
  sf_mex_destroy(&c57_lhs45);
  sf_mex_destroy(&c57_rhs46);
  sf_mex_destroy(&c57_lhs46);
  sf_mex_destroy(&c57_rhs47);
  sf_mex_destroy(&c57_lhs47);
  sf_mex_destroy(&c57_rhs48);
  sf_mex_destroy(&c57_lhs48);
  sf_mex_destroy(&c57_rhs49);
  sf_mex_destroy(&c57_lhs49);
  sf_mex_destroy(&c57_rhs50);
  sf_mex_destroy(&c57_lhs50);
  sf_mex_destroy(&c57_rhs51);
  sf_mex_destroy(&c57_lhs51);
  sf_mex_destroy(&c57_rhs52);
  sf_mex_destroy(&c57_lhs52);
  sf_mex_destroy(&c57_rhs53);
  sf_mex_destroy(&c57_lhs53);
  sf_mex_destroy(&c57_rhs54);
  sf_mex_destroy(&c57_lhs54);
  sf_mex_destroy(&c57_rhs55);
  sf_mex_destroy(&c57_lhs55);
  sf_mex_destroy(&c57_rhs56);
  sf_mex_destroy(&c57_lhs56);
  sf_mex_destroy(&c57_rhs57);
  sf_mex_destroy(&c57_lhs57);
  sf_mex_destroy(&c57_rhs58);
  sf_mex_destroy(&c57_lhs58);
  sf_mex_destroy(&c57_rhs59);
  sf_mex_destroy(&c57_lhs59);
  sf_mex_destroy(&c57_rhs60);
  sf_mex_destroy(&c57_lhs60);
  sf_mex_destroy(&c57_rhs61);
  sf_mex_destroy(&c57_lhs61);
  sf_mex_destroy(&c57_rhs62);
  sf_mex_destroy(&c57_lhs62);
  sf_mex_destroy(&c57_rhs63);
  sf_mex_destroy(&c57_lhs63);
}

static const mxArray *c57_emlrt_marshallOut(const char * c57_b_u)
{
  const mxArray *c57_y = NULL;
  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", c57_b_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c57_b_u)), false);
  return c57_y;
}

static const mxArray *c57_b_emlrt_marshallOut(const uint32_T c57_b_u)
{
  const mxArray *c57_y = NULL;
  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", &c57_b_u, 7, 0U, 0U, 0U, 0), false);
  return c57_y;
}

static void c57_b_info_helper(const mxArray **c57_info)
{
  const mxArray *c57_rhs64 = NULL;
  const mxArray *c57_lhs64 = NULL;
  const mxArray *c57_rhs65 = NULL;
  const mxArray *c57_lhs65 = NULL;
  const mxArray *c57_rhs66 = NULL;
  const mxArray *c57_lhs66 = NULL;
  const mxArray *c57_rhs67 = NULL;
  const mxArray *c57_lhs67 = NULL;
  const mxArray *c57_rhs68 = NULL;
  const mxArray *c57_lhs68 = NULL;
  const mxArray *c57_rhs69 = NULL;
  const mxArray *c57_lhs69 = NULL;
  const mxArray *c57_rhs70 = NULL;
  const mxArray *c57_lhs70 = NULL;
  const mxArray *c57_rhs71 = NULL;
  const mxArray *c57_lhs71 = NULL;
  const mxArray *c57_rhs72 = NULL;
  const mxArray *c57_lhs72 = NULL;
  const mxArray *c57_rhs73 = NULL;
  const mxArray *c57_lhs73 = NULL;
  const mxArray *c57_rhs74 = NULL;
  const mxArray *c57_lhs74 = NULL;
  const mxArray *c57_rhs75 = NULL;
  const mxArray *c57_lhs75 = NULL;
  const mxArray *c57_rhs76 = NULL;
  const mxArray *c57_lhs76 = NULL;
  const mxArray *c57_rhs77 = NULL;
  const mxArray *c57_lhs77 = NULL;
  const mxArray *c57_rhs78 = NULL;
  const mxArray *c57_lhs78 = NULL;
  const mxArray *c57_rhs79 = NULL;
  const mxArray *c57_lhs79 = NULL;
  const mxArray *c57_rhs80 = NULL;
  const mxArray *c57_lhs80 = NULL;
  const mxArray *c57_rhs81 = NULL;
  const mxArray *c57_lhs81 = NULL;
  const mxArray *c57_rhs82 = NULL;
  const mxArray *c57_lhs82 = NULL;
  const mxArray *c57_rhs83 = NULL;
  const mxArray *c57_lhs83 = NULL;
  const mxArray *c57_rhs84 = NULL;
  const mxArray *c57_lhs84 = NULL;
  const mxArray *c57_rhs85 = NULL;
  const mxArray *c57_lhs85 = NULL;
  const mxArray *c57_rhs86 = NULL;
  const mxArray *c57_lhs86 = NULL;
  const mxArray *c57_rhs87 = NULL;
  const mxArray *c57_lhs87 = NULL;
  const mxArray *c57_rhs88 = NULL;
  const mxArray *c57_lhs88 = NULL;
  const mxArray *c57_rhs89 = NULL;
  const mxArray *c57_lhs89 = NULL;
  const mxArray *c57_rhs90 = NULL;
  const mxArray *c57_lhs90 = NULL;
  const mxArray *c57_rhs91 = NULL;
  const mxArray *c57_lhs91 = NULL;
  const mxArray *c57_rhs92 = NULL;
  const mxArray *c57_lhs92 = NULL;
  const mxArray *c57_rhs93 = NULL;
  const mxArray *c57_lhs93 = NULL;
  const mxArray *c57_rhs94 = NULL;
  const mxArray *c57_lhs94 = NULL;
  const mxArray *c57_rhs95 = NULL;
  const mxArray *c57_lhs95 = NULL;
  const mxArray *c57_rhs96 = NULL;
  const mxArray *c57_lhs96 = NULL;
  const mxArray *c57_rhs97 = NULL;
  const mxArray *c57_lhs97 = NULL;
  const mxArray *c57_rhs98 = NULL;
  const mxArray *c57_lhs98 = NULL;
  const mxArray *c57_rhs99 = NULL;
  const mxArray *c57_lhs99 = NULL;
  const mxArray *c57_rhs100 = NULL;
  const mxArray *c57_lhs100 = NULL;
  const mxArray *c57_rhs101 = NULL;
  const mxArray *c57_lhs101 = NULL;
  const mxArray *c57_rhs102 = NULL;
  const mxArray *c57_lhs102 = NULL;
  const mxArray *c57_rhs103 = NULL;
  const mxArray *c57_lhs103 = NULL;
  const mxArray *c57_rhs104 = NULL;
  const mxArray *c57_lhs104 = NULL;
  const mxArray *c57_rhs105 = NULL;
  const mxArray *c57_lhs105 = NULL;
  const mxArray *c57_rhs106 = NULL;
  const mxArray *c57_lhs106 = NULL;
  const mxArray *c57_rhs107 = NULL;
  const mxArray *c57_lhs107 = NULL;
  const mxArray *c57_rhs108 = NULL;
  const mxArray *c57_lhs108 = NULL;
  const mxArray *c57_rhs109 = NULL;
  const mxArray *c57_lhs109 = NULL;
  const mxArray *c57_rhs110 = NULL;
  const mxArray *c57_lhs110 = NULL;
  const mxArray *c57_rhs111 = NULL;
  const mxArray *c57_lhs111 = NULL;
  const mxArray *c57_rhs112 = NULL;
  const mxArray *c57_lhs112 = NULL;
  const mxArray *c57_rhs113 = NULL;
  const mxArray *c57_lhs113 = NULL;
  const mxArray *c57_rhs114 = NULL;
  const mxArray *c57_lhs114 = NULL;
  const mxArray *c57_rhs115 = NULL;
  const mxArray *c57_lhs115 = NULL;
  const mxArray *c57_rhs116 = NULL;
  const mxArray *c57_lhs116 = NULL;
  const mxArray *c57_rhs117 = NULL;
  const mxArray *c57_lhs117 = NULL;
  const mxArray *c57_rhs118 = NULL;
  const mxArray *c57_lhs118 = NULL;
  const mxArray *c57_rhs119 = NULL;
  const mxArray *c57_lhs119 = NULL;
  const mxArray *c57_rhs120 = NULL;
  const mxArray *c57_lhs120 = NULL;
  const mxArray *c57_rhs121 = NULL;
  const mxArray *c57_lhs121 = NULL;
  const mxArray *c57_rhs122 = NULL;
  const mxArray *c57_lhs122 = NULL;
  const mxArray *c57_rhs123 = NULL;
  const mxArray *c57_lhs123 = NULL;
  const mxArray *c57_rhs124 = NULL;
  const mxArray *c57_lhs124 = NULL;
  const mxArray *c57_rhs125 = NULL;
  const mxArray *c57_lhs125 = NULL;
  const mxArray *c57_rhs126 = NULL;
  const mxArray *c57_lhs126 = NULL;
  const mxArray *c57_rhs127 = NULL;
  const mxArray *c57_lhs127 = NULL;
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 64);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 64);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c57_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 65);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 65);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 65);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c57_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 66);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 66);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c57_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 67);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 67);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c57_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 68);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  68);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c57_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 69);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 69);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c57_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 70);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.xdotu"),
                  "name", "name", 70);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c57_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "context", "context", 71);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 71);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c57_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 72);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 72);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c57_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 73);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 73);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 73);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c57_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 74);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 74);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c57_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 75);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.refblas.xdotx"), "name", "name", 75);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c57_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 76);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 76);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 76);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c57_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 77);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 77);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c57_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 78);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 78);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 78);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 78);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c57_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 79);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 79);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 79);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 79);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c57_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 80);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 80);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c57_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "context", "context", 81);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("max"), "name", "name", 81);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 81);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c57_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "context", "context", 82);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("mldivide"), "name", "name",
                  82);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "resolved",
                  "resolved", 82);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1319751566U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c57_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "context",
                  "context", 83);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_lusolve"), "name",
                  "name", 83);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m"), "resolved",
                  "resolved", 83);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1370031486U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c57_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 84);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_xgetrf"), "name", "name",
                  84);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1286840406U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c57_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "context", "context", 85);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_lapack_xgetrf"), "name",
                  "name", 85);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "resolved", "resolved", 85);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1286840410U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c57_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "context", "context", 86);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_matlab_zgetrf"), "name",
                  "name", 86);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1302710594U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c57_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 87);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("realmin"), "name", "name",
                  87);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 87);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c57_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 88);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_realmin"), "name",
                  "name", 88);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 88);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1307672844U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c57_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 89);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 89);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c57_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 90);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eps"), "name", "name", 90);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 90);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c57_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 91);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 91);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 91);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c57_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 92);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_eps"), "name", "name",
                  92);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 92);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c57_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 93);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 93);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c57_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 94);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("min"), "name", "name", 94);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 94);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 94);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c57_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 95);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 95);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 95);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 95);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c57_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 96);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 96);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 96);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 96);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c57_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 97);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 97);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 97);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 97);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c57_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 98);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 98);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 98);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c57_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 99);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 99);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 99);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 99);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c57_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 100);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 100);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 100);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 100);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c57_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs100), "rhs",
                  "rhs", 100);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs100), "lhs",
                  "lhs", 100);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 101);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("colon"), "name", "name", 101);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 101);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c57_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs101), "rhs",
                  "rhs", 101);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs101), "lhs",
                  "lhs", 101);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 102);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("colon"), "name", "name", 102);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 102);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c57_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs102), "rhs",
                  "rhs", 102);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs102), "lhs",
                  "lhs", 102);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 103);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 103);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 103);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c57_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs103), "rhs",
                  "rhs", 103);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs103), "lhs",
                  "lhs", 103);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 104);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 104);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 104);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 104);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c57_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs104), "rhs",
                  "rhs", 104);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs104), "lhs",
                  "lhs", 104);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 105);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("floor"), "name", "name", 105);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 105);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c57_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs105), "rhs",
                  "rhs", 105);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs105), "lhs",
                  "lhs", 105);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 106);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 106);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c57_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs106), "rhs",
                  "rhs", 106);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs106), "lhs",
                  "lhs", 106);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 107);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 107);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c57_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs107), "rhs",
                  "rhs", 107);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs107), "lhs",
                  "lhs", 107);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 108);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("intmin"), "name", "name",
                  108);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 108);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c57_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs108), "rhs",
                  "rhs", 108);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs108), "lhs",
                  "lhs", 108);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 109);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("intmax"), "name", "name",
                  109);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 109);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c57_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs109), "rhs",
                  "rhs", 109);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs109), "lhs",
                  "lhs", 109);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 110);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("intmin"), "name", "name",
                  110);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 110);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c57_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs110), "rhs",
                  "rhs", 110);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs110), "lhs",
                  "lhs", 110);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 111);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("intmax"), "name", "name",
                  111);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 111);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c57_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs111), "rhs",
                  "rhs", 111);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs111), "lhs",
                  "lhs", 111);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 112);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 112);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 112);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 112);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c57_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs112), "rhs",
                  "rhs", 112);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs112), "lhs",
                  "lhs", 112);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 113);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 113);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 113);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 113);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c57_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs113), "rhs",
                  "rhs", 113);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs113), "lhs",
                  "lhs", 113);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 114);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 114);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 114);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c57_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs114), "rhs",
                  "rhs", 114);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs114), "lhs",
                  "lhs", 114);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 115);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.unsignedClass"), "name", "name", 115);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 115);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 115);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c57_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs115), "rhs",
                  "rhs", 115);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs115), "lhs",
                  "lhs", 115);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 116);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 116);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 116);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c57_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs116), "rhs",
                  "rhs", 116);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs116), "lhs",
                  "lhs", 116);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 117);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 117);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 117);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c57_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs117), "rhs",
                  "rhs", 117);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs117), "lhs",
                  "lhs", 117);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 118);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 118);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 118);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 118);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c57_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs118), "rhs",
                  "rhs", 118);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs118), "lhs",
                  "lhs", 118);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 119);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("intmax"), "name", "name",
                  119);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 119);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 119);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c57_rhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs119), "rhs",
                  "rhs", 119);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs119), "lhs",
                  "lhs", 119);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 120);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_isa_uint"), "name",
                  "name", 120);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 120);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 120);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c57_rhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs120), "rhs",
                  "rhs", 120);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs120), "lhs",
                  "lhs", 120);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 121);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 121);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 121);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c57_rhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs121), "rhs",
                  "rhs", 121);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs121), "lhs",
                  "lhs", 121);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 122);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 122);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 122);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 122);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c57_rhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs122), "rhs",
                  "rhs", 122);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs122), "lhs",
                  "lhs", 122);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 123);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 123);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 123);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c57_rhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs123), "rhs",
                  "rhs", 123);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs123), "lhs",
                  "lhs", 123);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 124);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 124);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 124);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 124);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c57_rhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs124), "rhs",
                  "rhs", 124);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs124), "lhs",
                  "lhs", 124);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 125);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 125);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 125);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c57_rhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs125), "rhs",
                  "rhs", 125);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs125), "lhs",
                  "lhs", 125);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 126);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 126);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 126);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c57_rhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs126), "rhs",
                  "rhs", 126);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs126), "lhs",
                  "lhs", 126);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 127);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 127);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 127);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 127);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c57_rhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs127), "rhs",
                  "rhs", 127);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs127), "lhs",
                  "lhs", 127);
  sf_mex_destroy(&c57_rhs64);
  sf_mex_destroy(&c57_lhs64);
  sf_mex_destroy(&c57_rhs65);
  sf_mex_destroy(&c57_lhs65);
  sf_mex_destroy(&c57_rhs66);
  sf_mex_destroy(&c57_lhs66);
  sf_mex_destroy(&c57_rhs67);
  sf_mex_destroy(&c57_lhs67);
  sf_mex_destroy(&c57_rhs68);
  sf_mex_destroy(&c57_lhs68);
  sf_mex_destroy(&c57_rhs69);
  sf_mex_destroy(&c57_lhs69);
  sf_mex_destroy(&c57_rhs70);
  sf_mex_destroy(&c57_lhs70);
  sf_mex_destroy(&c57_rhs71);
  sf_mex_destroy(&c57_lhs71);
  sf_mex_destroy(&c57_rhs72);
  sf_mex_destroy(&c57_lhs72);
  sf_mex_destroy(&c57_rhs73);
  sf_mex_destroy(&c57_lhs73);
  sf_mex_destroy(&c57_rhs74);
  sf_mex_destroy(&c57_lhs74);
  sf_mex_destroy(&c57_rhs75);
  sf_mex_destroy(&c57_lhs75);
  sf_mex_destroy(&c57_rhs76);
  sf_mex_destroy(&c57_lhs76);
  sf_mex_destroy(&c57_rhs77);
  sf_mex_destroy(&c57_lhs77);
  sf_mex_destroy(&c57_rhs78);
  sf_mex_destroy(&c57_lhs78);
  sf_mex_destroy(&c57_rhs79);
  sf_mex_destroy(&c57_lhs79);
  sf_mex_destroy(&c57_rhs80);
  sf_mex_destroy(&c57_lhs80);
  sf_mex_destroy(&c57_rhs81);
  sf_mex_destroy(&c57_lhs81);
  sf_mex_destroy(&c57_rhs82);
  sf_mex_destroy(&c57_lhs82);
  sf_mex_destroy(&c57_rhs83);
  sf_mex_destroy(&c57_lhs83);
  sf_mex_destroy(&c57_rhs84);
  sf_mex_destroy(&c57_lhs84);
  sf_mex_destroy(&c57_rhs85);
  sf_mex_destroy(&c57_lhs85);
  sf_mex_destroy(&c57_rhs86);
  sf_mex_destroy(&c57_lhs86);
  sf_mex_destroy(&c57_rhs87);
  sf_mex_destroy(&c57_lhs87);
  sf_mex_destroy(&c57_rhs88);
  sf_mex_destroy(&c57_lhs88);
  sf_mex_destroy(&c57_rhs89);
  sf_mex_destroy(&c57_lhs89);
  sf_mex_destroy(&c57_rhs90);
  sf_mex_destroy(&c57_lhs90);
  sf_mex_destroy(&c57_rhs91);
  sf_mex_destroy(&c57_lhs91);
  sf_mex_destroy(&c57_rhs92);
  sf_mex_destroy(&c57_lhs92);
  sf_mex_destroy(&c57_rhs93);
  sf_mex_destroy(&c57_lhs93);
  sf_mex_destroy(&c57_rhs94);
  sf_mex_destroy(&c57_lhs94);
  sf_mex_destroy(&c57_rhs95);
  sf_mex_destroy(&c57_lhs95);
  sf_mex_destroy(&c57_rhs96);
  sf_mex_destroy(&c57_lhs96);
  sf_mex_destroy(&c57_rhs97);
  sf_mex_destroy(&c57_lhs97);
  sf_mex_destroy(&c57_rhs98);
  sf_mex_destroy(&c57_lhs98);
  sf_mex_destroy(&c57_rhs99);
  sf_mex_destroy(&c57_lhs99);
  sf_mex_destroy(&c57_rhs100);
  sf_mex_destroy(&c57_lhs100);
  sf_mex_destroy(&c57_rhs101);
  sf_mex_destroy(&c57_lhs101);
  sf_mex_destroy(&c57_rhs102);
  sf_mex_destroy(&c57_lhs102);
  sf_mex_destroy(&c57_rhs103);
  sf_mex_destroy(&c57_lhs103);
  sf_mex_destroy(&c57_rhs104);
  sf_mex_destroy(&c57_lhs104);
  sf_mex_destroy(&c57_rhs105);
  sf_mex_destroy(&c57_lhs105);
  sf_mex_destroy(&c57_rhs106);
  sf_mex_destroy(&c57_lhs106);
  sf_mex_destroy(&c57_rhs107);
  sf_mex_destroy(&c57_lhs107);
  sf_mex_destroy(&c57_rhs108);
  sf_mex_destroy(&c57_lhs108);
  sf_mex_destroy(&c57_rhs109);
  sf_mex_destroy(&c57_lhs109);
  sf_mex_destroy(&c57_rhs110);
  sf_mex_destroy(&c57_lhs110);
  sf_mex_destroy(&c57_rhs111);
  sf_mex_destroy(&c57_lhs111);
  sf_mex_destroy(&c57_rhs112);
  sf_mex_destroy(&c57_lhs112);
  sf_mex_destroy(&c57_rhs113);
  sf_mex_destroy(&c57_lhs113);
  sf_mex_destroy(&c57_rhs114);
  sf_mex_destroy(&c57_lhs114);
  sf_mex_destroy(&c57_rhs115);
  sf_mex_destroy(&c57_lhs115);
  sf_mex_destroy(&c57_rhs116);
  sf_mex_destroy(&c57_lhs116);
  sf_mex_destroy(&c57_rhs117);
  sf_mex_destroy(&c57_lhs117);
  sf_mex_destroy(&c57_rhs118);
  sf_mex_destroy(&c57_lhs118);
  sf_mex_destroy(&c57_rhs119);
  sf_mex_destroy(&c57_lhs119);
  sf_mex_destroy(&c57_rhs120);
  sf_mex_destroy(&c57_lhs120);
  sf_mex_destroy(&c57_rhs121);
  sf_mex_destroy(&c57_lhs121);
  sf_mex_destroy(&c57_rhs122);
  sf_mex_destroy(&c57_lhs122);
  sf_mex_destroy(&c57_rhs123);
  sf_mex_destroy(&c57_lhs123);
  sf_mex_destroy(&c57_rhs124);
  sf_mex_destroy(&c57_lhs124);
  sf_mex_destroy(&c57_rhs125);
  sf_mex_destroy(&c57_lhs125);
  sf_mex_destroy(&c57_rhs126);
  sf_mex_destroy(&c57_lhs126);
  sf_mex_destroy(&c57_rhs127);
  sf_mex_destroy(&c57_lhs127);
}

static void c57_c_info_helper(const mxArray **c57_info)
{
  const mxArray *c57_rhs128 = NULL;
  const mxArray *c57_lhs128 = NULL;
  const mxArray *c57_rhs129 = NULL;
  const mxArray *c57_lhs129 = NULL;
  const mxArray *c57_rhs130 = NULL;
  const mxArray *c57_lhs130 = NULL;
  const mxArray *c57_rhs131 = NULL;
  const mxArray *c57_lhs131 = NULL;
  const mxArray *c57_rhs132 = NULL;
  const mxArray *c57_lhs132 = NULL;
  const mxArray *c57_rhs133 = NULL;
  const mxArray *c57_lhs133 = NULL;
  const mxArray *c57_rhs134 = NULL;
  const mxArray *c57_lhs134 = NULL;
  const mxArray *c57_rhs135 = NULL;
  const mxArray *c57_lhs135 = NULL;
  const mxArray *c57_rhs136 = NULL;
  const mxArray *c57_lhs136 = NULL;
  const mxArray *c57_rhs137 = NULL;
  const mxArray *c57_lhs137 = NULL;
  const mxArray *c57_rhs138 = NULL;
  const mxArray *c57_lhs138 = NULL;
  const mxArray *c57_rhs139 = NULL;
  const mxArray *c57_lhs139 = NULL;
  const mxArray *c57_rhs140 = NULL;
  const mxArray *c57_lhs140 = NULL;
  const mxArray *c57_rhs141 = NULL;
  const mxArray *c57_lhs141 = NULL;
  const mxArray *c57_rhs142 = NULL;
  const mxArray *c57_lhs142 = NULL;
  const mxArray *c57_rhs143 = NULL;
  const mxArray *c57_lhs143 = NULL;
  const mxArray *c57_rhs144 = NULL;
  const mxArray *c57_lhs144 = NULL;
  const mxArray *c57_rhs145 = NULL;
  const mxArray *c57_lhs145 = NULL;
  const mxArray *c57_rhs146 = NULL;
  const mxArray *c57_lhs146 = NULL;
  const mxArray *c57_rhs147 = NULL;
  const mxArray *c57_lhs147 = NULL;
  const mxArray *c57_rhs148 = NULL;
  const mxArray *c57_lhs148 = NULL;
  const mxArray *c57_rhs149 = NULL;
  const mxArray *c57_lhs149 = NULL;
  const mxArray *c57_rhs150 = NULL;
  const mxArray *c57_lhs150 = NULL;
  const mxArray *c57_rhs151 = NULL;
  const mxArray *c57_lhs151 = NULL;
  const mxArray *c57_rhs152 = NULL;
  const mxArray *c57_lhs152 = NULL;
  const mxArray *c57_rhs153 = NULL;
  const mxArray *c57_lhs153 = NULL;
  const mxArray *c57_rhs154 = NULL;
  const mxArray *c57_lhs154 = NULL;
  const mxArray *c57_rhs155 = NULL;
  const mxArray *c57_lhs155 = NULL;
  const mxArray *c57_rhs156 = NULL;
  const mxArray *c57_lhs156 = NULL;
  const mxArray *c57_rhs157 = NULL;
  const mxArray *c57_lhs157 = NULL;
  const mxArray *c57_rhs158 = NULL;
  const mxArray *c57_lhs158 = NULL;
  const mxArray *c57_rhs159 = NULL;
  const mxArray *c57_lhs159 = NULL;
  const mxArray *c57_rhs160 = NULL;
  const mxArray *c57_lhs160 = NULL;
  const mxArray *c57_rhs161 = NULL;
  const mxArray *c57_lhs161 = NULL;
  const mxArray *c57_rhs162 = NULL;
  const mxArray *c57_lhs162 = NULL;
  const mxArray *c57_rhs163 = NULL;
  const mxArray *c57_lhs163 = NULL;
  const mxArray *c57_rhs164 = NULL;
  const mxArray *c57_lhs164 = NULL;
  const mxArray *c57_rhs165 = NULL;
  const mxArray *c57_lhs165 = NULL;
  const mxArray *c57_rhs166 = NULL;
  const mxArray *c57_lhs166 = NULL;
  const mxArray *c57_rhs167 = NULL;
  const mxArray *c57_lhs167 = NULL;
  const mxArray *c57_rhs168 = NULL;
  const mxArray *c57_lhs168 = NULL;
  const mxArray *c57_rhs169 = NULL;
  const mxArray *c57_lhs169 = NULL;
  const mxArray *c57_rhs170 = NULL;
  const mxArray *c57_lhs170 = NULL;
  const mxArray *c57_rhs171 = NULL;
  const mxArray *c57_lhs171 = NULL;
  const mxArray *c57_rhs172 = NULL;
  const mxArray *c57_lhs172 = NULL;
  const mxArray *c57_rhs173 = NULL;
  const mxArray *c57_lhs173 = NULL;
  const mxArray *c57_rhs174 = NULL;
  const mxArray *c57_lhs174 = NULL;
  const mxArray *c57_rhs175 = NULL;
  const mxArray *c57_lhs175 = NULL;
  const mxArray *c57_rhs176 = NULL;
  const mxArray *c57_lhs176 = NULL;
  const mxArray *c57_rhs177 = NULL;
  const mxArray *c57_lhs177 = NULL;
  const mxArray *c57_rhs178 = NULL;
  const mxArray *c57_lhs178 = NULL;
  const mxArray *c57_rhs179 = NULL;
  const mxArray *c57_lhs179 = NULL;
  const mxArray *c57_rhs180 = NULL;
  const mxArray *c57_lhs180 = NULL;
  const mxArray *c57_rhs181 = NULL;
  const mxArray *c57_lhs181 = NULL;
  const mxArray *c57_rhs182 = NULL;
  const mxArray *c57_lhs182 = NULL;
  const mxArray *c57_rhs183 = NULL;
  const mxArray *c57_lhs183 = NULL;
  const mxArray *c57_rhs184 = NULL;
  const mxArray *c57_lhs184 = NULL;
  const mxArray *c57_rhs185 = NULL;
  const mxArray *c57_lhs185 = NULL;
  const mxArray *c57_rhs186 = NULL;
  const mxArray *c57_lhs186 = NULL;
  const mxArray *c57_rhs187 = NULL;
  const mxArray *c57_lhs187 = NULL;
  const mxArray *c57_rhs188 = NULL;
  const mxArray *c57_lhs188 = NULL;
  const mxArray *c57_rhs189 = NULL;
  const mxArray *c57_lhs189 = NULL;
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 128);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 128);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 128);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 128);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c57_rhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs128), "rhs",
                  "rhs", 128);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs128), "lhs",
                  "lhs", 128);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 129);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 129);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 129);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 129);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 129);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 129);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 129);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 129);
  sf_mex_assign(&c57_rhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs129), "rhs",
                  "rhs", 129);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs129), "lhs",
                  "lhs", 129);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 130);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 130);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 130);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 130);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 130);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 130);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 130);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 130);
  sf_mex_assign(&c57_rhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs130), "rhs",
                  "rhs", 130);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs130), "lhs",
                  "lhs", 130);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 131);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 131);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 131);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 131);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 131);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 131);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 131);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 131);
  sf_mex_assign(&c57_rhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs131), "rhs",
                  "rhs", 131);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs131), "lhs",
                  "lhs", 131);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 132);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 132);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 132);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 132);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 132);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 132);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 132);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 132);
  sf_mex_assign(&c57_rhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs132), "rhs",
                  "rhs", 132);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs132), "lhs",
                  "lhs", 132);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 133);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 133);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 133);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 133);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 133);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 133);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 133);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 133);
  sf_mex_assign(&c57_rhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs133), "rhs",
                  "rhs", 133);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs133), "lhs",
                  "lhs", 133);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 134);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_ixamax"), "name", "name",
                  134);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 134);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "resolved", "resolved", 134);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 134);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 134);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 134);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 134);
  sf_mex_assign(&c57_rhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs134), "rhs",
                  "rhs", 134);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs134), "lhs",
                  "lhs", 134);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "context", "context", 135);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 135);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 135);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 135);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 135);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 135);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 135);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 135);
  sf_mex_assign(&c57_rhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs135), "rhs",
                  "rhs", 135);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs135), "lhs",
                  "lhs", 135);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "context", "context", 136);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.ixamax"),
                  "name", "name", 136);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 136);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "resolved", "resolved", 136);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 136);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 136);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 136);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 136);
  sf_mex_assign(&c57_rhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs136), "rhs",
                  "rhs", 136);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs136), "lhs",
                  "lhs", 136);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "context", "context", 137);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 137);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 137);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 137);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 137);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 137);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 137);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 137);
  sf_mex_assign(&c57_rhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs137), "rhs",
                  "rhs", 137);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs137), "lhs",
                  "lhs", 137);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                  "context", "context", 138);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 138);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 138);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 138);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 138);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 138);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 138);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 138);
  sf_mex_assign(&c57_rhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs138), "rhs",
                  "rhs", 138);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs138), "lhs",
                  "lhs", 138);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                  "context", "context", 139);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("length"), "name", "name",
                  139);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 139);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 139);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 139);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 139);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 139);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 139);
  sf_mex_assign(&c57_rhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs139), "rhs",
                  "rhs", 139);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs139), "lhs",
                  "lhs", 139);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 140);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 140);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 140);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 140);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 140);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 140);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 140);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 140);
  sf_mex_assign(&c57_rhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs140), "rhs",
                  "rhs", 140);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs140), "lhs",
                  "lhs", 140);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "context", "context", 141);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.refblas.ixamax"), "name", "name", 141);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 141);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "resolved", "resolved", 141);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 141);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 141);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 141);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 141);
  sf_mex_assign(&c57_rhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs141), "rhs",
                  "rhs", 141);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs141), "lhs",
                  "lhs", 141);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 142);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.refblas.xcabs1"), "name", "name", 142);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 142);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 142);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 142);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 142);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 142);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 142);
  sf_mex_assign(&c57_rhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs142), "rhs",
                  "rhs", 142);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs142), "lhs",
                  "lhs", 142);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "context", "context", 143);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("abs"), "name", "name", 143);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 143);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 143);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 143);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 143);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 143);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 143);
  sf_mex_assign(&c57_rhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs143), "rhs",
                  "rhs", 143);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs143), "lhs",
                  "lhs", 143);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 144);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 144);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 144);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 144);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 144);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 144);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 144);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 144);
  sf_mex_assign(&c57_rhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs144), "rhs",
                  "rhs", 144);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs144), "lhs",
                  "lhs", 144);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 145);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 145);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 145);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 145);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 145);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 145);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 145);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 145);
  sf_mex_assign(&c57_rhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs145), "rhs",
                  "rhs", 145);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs145), "lhs",
                  "lhs", 145);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 146);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 146);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 146);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 146);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 146);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 146);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 146);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 146);
  sf_mex_assign(&c57_rhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs146), "rhs",
                  "rhs", 146);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs146), "lhs",
                  "lhs", 146);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 147);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 147);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 147);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 147);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 147);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 147);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 147);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 147);
  sf_mex_assign(&c57_rhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs147), "rhs",
                  "rhs", 147);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs147), "lhs",
                  "lhs", 147);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 148);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_xswap"), "name", "name",
                  148);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 148);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"),
                  "resolved", "resolved", 148);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 148);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 148);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 148);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 148);
  sf_mex_assign(&c57_rhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs148), "rhs",
                  "rhs", 148);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs148), "lhs",
                  "lhs", 148);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 149);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 149);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 149);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 149);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 149);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 149);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 149);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 149);
  sf_mex_assign(&c57_rhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs149), "rhs",
                  "rhs", 149);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs149), "lhs",
                  "lhs", 149);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 150);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.xswap"),
                  "name", "name", 150);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 150);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "resolved", "resolved", 150);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 150);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 150);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 150);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 150);
  sf_mex_assign(&c57_rhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs150), "rhs",
                  "rhs", 150);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs150), "lhs",
                  "lhs", 150);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 151);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 151);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 151);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 151);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 151);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 151);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 151);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 151);
  sf_mex_assign(&c57_rhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs151), "rhs",
                  "rhs", 151);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs151), "lhs",
                  "lhs", 151);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p!below_threshold"),
                  "context", "context", 152);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 152);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 152);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 152);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 152);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 152);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 152);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 152);
  sf_mex_assign(&c57_rhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs152), "rhs",
                  "rhs", 152);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs152), "lhs",
                  "lhs", 152);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 153);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.refblas.xswap"), "name", "name", 153);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 153);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "resolved", "resolved", 153);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 153);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 153);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 153);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 153);
  sf_mex_assign(&c57_rhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs153), "rhs",
                  "rhs", 153);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs153), "lhs",
                  "lhs", 153);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 154);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("abs"), "name", "name", 154);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 154);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 154);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 154);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 154);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 154);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 154);
  sf_mex_assign(&c57_rhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs154), "rhs",
                  "rhs", 154);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs154), "lhs",
                  "lhs", 154);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 155);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 155);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 155);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 155);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 155);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 155);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 155);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 155);
  sf_mex_assign(&c57_rhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs155), "rhs",
                  "rhs", 155);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs155), "lhs",
                  "lhs", 155);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 156);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 156);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 156);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 156);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 156);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 156);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 156);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 156);
  sf_mex_assign(&c57_rhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs156), "rhs",
                  "rhs", 156);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs156), "lhs",
                  "lhs", 156);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 157);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 157);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 157);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 157);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 157);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 157);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 157);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 157);
  sf_mex_assign(&c57_rhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs157), "rhs",
                  "rhs", 157);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs157), "lhs",
                  "lhs", 157);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 158);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 158);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 158);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 158);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 158);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 158);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 158);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 158);
  sf_mex_assign(&c57_rhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs158), "rhs",
                  "rhs", 158);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs158), "lhs",
                  "lhs", 158);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 159);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_div"), "name", "name",
                  159);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 159);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 159);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 159);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 159);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 159);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 159);
  sf_mex_assign(&c57_rhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs159), "rhs",
                  "rhs", 159);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs159), "lhs",
                  "lhs", 159);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 160);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_xgeru"), "name", "name",
                  160);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 160);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"),
                  "resolved", "resolved", 160);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 160);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 160);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 160);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 160);
  sf_mex_assign(&c57_rhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs160), "rhs",
                  "rhs", 160);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs160), "lhs",
                  "lhs", 160);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 161);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 161);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 161);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 161);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 161);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 161);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 161);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 161);
  sf_mex_assign(&c57_rhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs161), "rhs",
                  "rhs", 161);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs161), "lhs",
                  "lhs", 161);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 162);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.xgeru"),
                  "name", "name", 162);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 162);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                  "resolved", "resolved", 162);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 162);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 162);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 162);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 162);
  sf_mex_assign(&c57_rhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs162), "rhs",
                  "rhs", 162);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs162), "lhs",
                  "lhs", 162);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                  "context", "context", 163);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.xger"),
                  "name", "name", 163);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 163);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "resolved", "resolved", 163);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 163);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 163);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 163);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 163);
  sf_mex_assign(&c57_rhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs163), "rhs",
                  "rhs", 163);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs163), "lhs",
                  "lhs", 163);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "context", "context", 164);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 164);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 164);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 164);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 164);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 164);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 164);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 164);
  sf_mex_assign(&c57_rhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs164), "rhs",
                  "rhs", 164);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs164), "lhs",
                  "lhs", 164);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 165);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 165);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 165);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 165);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 165);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 165);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 165);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 165);
  sf_mex_assign(&c57_rhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs165), "rhs",
                  "rhs", 165);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs165), "lhs",
                  "lhs", 165);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 166);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.int"),
                  "name", "name", 166);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 166);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/int.p"),
                  "resolved", "resolved", 166);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 166);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 166);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 166);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 166);
  sf_mex_assign(&c57_rhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs166), "rhs",
                  "rhs", 166);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs166), "lhs",
                  "lhs", 166);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 167);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("intmax"), "name", "name",
                  167);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 167);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 167);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 167);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 167);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 167);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 167);
  sf_mex_assign(&c57_rhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs167), "rhs",
                  "rhs", 167);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs167), "lhs",
                  "lhs", 167);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 168);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("min"), "name", "name", 168);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 168);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 168);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 168);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 168);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 168);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 168);
  sf_mex_assign(&c57_rhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs168), "rhs",
                  "rhs", 168);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs168), "lhs",
                  "lhs", 168);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "context", "context", 169);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.refblas.xger"),
                  "name", "name", 169);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 169);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                  "resolved", "resolved", 169);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 169);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 169);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 169);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 169);
  sf_mex_assign(&c57_rhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs169), "rhs",
                  "rhs", 169);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs169), "lhs",
                  "lhs", 169);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                  "context", "context", 170);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.refblas.xgerx"), "name", "name", 170);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 170);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "resolved", "resolved", 170);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 170);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 170);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 170);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 170);
  sf_mex_assign(&c57_rhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs170), "rhs",
                  "rhs", 170);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs170), "lhs",
                  "lhs", 170);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 171);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("abs"), "name", "name", 171);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 171);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 171);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 171);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 171);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 171);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 171);
  sf_mex_assign(&c57_rhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs171), "rhs",
                  "rhs", 171);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs171), "lhs",
                  "lhs", 171);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 172);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 172);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 172);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 172);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 172);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 172);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 172);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 172);
  sf_mex_assign(&c57_rhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs172), "rhs",
                  "rhs", 172);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs172), "lhs",
                  "lhs", 172);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 173);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 173);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 173);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 173);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 173);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 173);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 173);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 173);
  sf_mex_assign(&c57_rhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs173), "rhs",
                  "rhs", 173);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs173), "lhs",
                  "lhs", 173);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 174);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 174);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 174);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 174);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 174);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 174);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 174);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 174);
  sf_mex_assign(&c57_rhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs174), "rhs",
                  "rhs", 174);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs174), "lhs",
                  "lhs", 174);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 175);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 175);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 175);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 175);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 175);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 175);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 175);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 175);
  sf_mex_assign(&c57_rhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs175), "rhs",
                  "rhs", 175);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs175), "lhs",
                  "lhs", 175);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular"),
                  "context", "context", 176);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_warning"), "name",
                  "name", 176);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 176);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 176);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1286840402U), "fileTimeLo",
                  "fileTimeLo", 176);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 176);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 176);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 176);
  sf_mex_assign(&c57_rhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs176), "rhs",
                  "rhs", 176);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs176), "lhs",
                  "lhs", 176);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 177);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 177);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 177);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 177);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 177);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 177);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 177);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 177);
  sf_mex_assign(&c57_rhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs177), "rhs",
                  "rhs", 177);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs177), "lhs",
                  "lhs", 177);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 178);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 178);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 178);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 178);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 178);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 178);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 178);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 178);
  sf_mex_assign(&c57_rhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs178), "rhs",
                  "rhs", 178);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs178), "lhs",
                  "lhs", 178);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 179);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("eml_xtrsm"), "name", "name",
                  179);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 179);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"),
                  "resolved", "resolved", 179);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 179);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 179);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 179);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 179);
  sf_mex_assign(&c57_rhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs179), "rhs",
                  "rhs", 179);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs179), "lhs",
                  "lhs", 179);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                  "context", 180);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 180);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 180);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 180);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 180);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 180);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 180);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 180);
  sf_mex_assign(&c57_rhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs180), "rhs",
                  "rhs", 180);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs180), "lhs",
                  "lhs", 180);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                  "context", 181);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.blas.xtrsm"),
                  "name", "name", 181);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 181);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "resolved", "resolved", 181);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 181);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 181);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 181);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 181);
  sf_mex_assign(&c57_rhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs181), "rhs",
                  "rhs", 181);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs181), "lhs",
                  "lhs", 181);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 182);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 182);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 182);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 182);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 182);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 182);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 182);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 182);
  sf_mex_assign(&c57_rhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs182), "rhs",
                  "rhs", 182);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs182), "lhs",
                  "lhs", 182);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p!below_threshold"),
                  "context", "context", 183);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.blas.threshold"), "name", "name", 183);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 183);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 183);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 183);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 183);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 183);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 183);
  sf_mex_assign(&c57_rhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs183), "rhs",
                  "rhs", 183);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs183), "lhs",
                  "lhs", 183);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 184);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 184);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 184);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 184);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 184);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 184);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 184);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 184);
  sf_mex_assign(&c57_rhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs184), "rhs",
                  "rhs", 184);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs184), "lhs",
                  "lhs", 184);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 185);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "coder.internal.refblas.xtrsm"), "name", "name", 185);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 185);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "resolved", "resolved", 185);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 185);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 185);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 185);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 185);
  sf_mex_assign(&c57_rhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs185), "rhs",
                  "rhs", 185);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs185), "lhs",
                  "lhs", 185);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 186);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 186);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 186);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 186);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 186);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 186);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 186);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 186);
  sf_mex_assign(&c57_rhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs186), "rhs",
                  "rhs", 186);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs186), "lhs",
                  "lhs", 186);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 187);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 187);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 187);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 187);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 187);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 187);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 187);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 187);
  sf_mex_assign(&c57_rhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs187), "rhs",
                  "rhs", 187);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs187), "lhs",
                  "lhs", 187);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 188);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 188);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 188);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 188);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 188);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 188);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 188);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 188);
  sf_mex_assign(&c57_rhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs188), "rhs",
                  "rhs", 188);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs188), "lhs",
                  "lhs", 188);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 189);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("rdivide"), "name", "name",
                  189);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 189);
  sf_mex_addfield(*c57_info, c57_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 189);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 189);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 189);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 189);
  sf_mex_addfield(*c57_info, c57_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 189);
  sf_mex_assign(&c57_rhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c57_lhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_rhs189), "rhs",
                  "rhs", 189);
  sf_mex_addfield(*c57_info, sf_mex_duplicatearraysafe(&c57_lhs189), "lhs",
                  "lhs", 189);
  sf_mex_destroy(&c57_rhs128);
  sf_mex_destroy(&c57_lhs128);
  sf_mex_destroy(&c57_rhs129);
  sf_mex_destroy(&c57_lhs129);
  sf_mex_destroy(&c57_rhs130);
  sf_mex_destroy(&c57_lhs130);
  sf_mex_destroy(&c57_rhs131);
  sf_mex_destroy(&c57_lhs131);
  sf_mex_destroy(&c57_rhs132);
  sf_mex_destroy(&c57_lhs132);
  sf_mex_destroy(&c57_rhs133);
  sf_mex_destroy(&c57_lhs133);
  sf_mex_destroy(&c57_rhs134);
  sf_mex_destroy(&c57_lhs134);
  sf_mex_destroy(&c57_rhs135);
  sf_mex_destroy(&c57_lhs135);
  sf_mex_destroy(&c57_rhs136);
  sf_mex_destroy(&c57_lhs136);
  sf_mex_destroy(&c57_rhs137);
  sf_mex_destroy(&c57_lhs137);
  sf_mex_destroy(&c57_rhs138);
  sf_mex_destroy(&c57_lhs138);
  sf_mex_destroy(&c57_rhs139);
  sf_mex_destroy(&c57_lhs139);
  sf_mex_destroy(&c57_rhs140);
  sf_mex_destroy(&c57_lhs140);
  sf_mex_destroy(&c57_rhs141);
  sf_mex_destroy(&c57_lhs141);
  sf_mex_destroy(&c57_rhs142);
  sf_mex_destroy(&c57_lhs142);
  sf_mex_destroy(&c57_rhs143);
  sf_mex_destroy(&c57_lhs143);
  sf_mex_destroy(&c57_rhs144);
  sf_mex_destroy(&c57_lhs144);
  sf_mex_destroy(&c57_rhs145);
  sf_mex_destroy(&c57_lhs145);
  sf_mex_destroy(&c57_rhs146);
  sf_mex_destroy(&c57_lhs146);
  sf_mex_destroy(&c57_rhs147);
  sf_mex_destroy(&c57_lhs147);
  sf_mex_destroy(&c57_rhs148);
  sf_mex_destroy(&c57_lhs148);
  sf_mex_destroy(&c57_rhs149);
  sf_mex_destroy(&c57_lhs149);
  sf_mex_destroy(&c57_rhs150);
  sf_mex_destroy(&c57_lhs150);
  sf_mex_destroy(&c57_rhs151);
  sf_mex_destroy(&c57_lhs151);
  sf_mex_destroy(&c57_rhs152);
  sf_mex_destroy(&c57_lhs152);
  sf_mex_destroy(&c57_rhs153);
  sf_mex_destroy(&c57_lhs153);
  sf_mex_destroy(&c57_rhs154);
  sf_mex_destroy(&c57_lhs154);
  sf_mex_destroy(&c57_rhs155);
  sf_mex_destroy(&c57_lhs155);
  sf_mex_destroy(&c57_rhs156);
  sf_mex_destroy(&c57_lhs156);
  sf_mex_destroy(&c57_rhs157);
  sf_mex_destroy(&c57_lhs157);
  sf_mex_destroy(&c57_rhs158);
  sf_mex_destroy(&c57_lhs158);
  sf_mex_destroy(&c57_rhs159);
  sf_mex_destroy(&c57_lhs159);
  sf_mex_destroy(&c57_rhs160);
  sf_mex_destroy(&c57_lhs160);
  sf_mex_destroy(&c57_rhs161);
  sf_mex_destroy(&c57_lhs161);
  sf_mex_destroy(&c57_rhs162);
  sf_mex_destroy(&c57_lhs162);
  sf_mex_destroy(&c57_rhs163);
  sf_mex_destroy(&c57_lhs163);
  sf_mex_destroy(&c57_rhs164);
  sf_mex_destroy(&c57_lhs164);
  sf_mex_destroy(&c57_rhs165);
  sf_mex_destroy(&c57_lhs165);
  sf_mex_destroy(&c57_rhs166);
  sf_mex_destroy(&c57_lhs166);
  sf_mex_destroy(&c57_rhs167);
  sf_mex_destroy(&c57_lhs167);
  sf_mex_destroy(&c57_rhs168);
  sf_mex_destroy(&c57_lhs168);
  sf_mex_destroy(&c57_rhs169);
  sf_mex_destroy(&c57_lhs169);
  sf_mex_destroy(&c57_rhs170);
  sf_mex_destroy(&c57_lhs170);
  sf_mex_destroy(&c57_rhs171);
  sf_mex_destroy(&c57_lhs171);
  sf_mex_destroy(&c57_rhs172);
  sf_mex_destroy(&c57_lhs172);
  sf_mex_destroy(&c57_rhs173);
  sf_mex_destroy(&c57_lhs173);
  sf_mex_destroy(&c57_rhs174);
  sf_mex_destroy(&c57_lhs174);
  sf_mex_destroy(&c57_rhs175);
  sf_mex_destroy(&c57_lhs175);
  sf_mex_destroy(&c57_rhs176);
  sf_mex_destroy(&c57_lhs176);
  sf_mex_destroy(&c57_rhs177);
  sf_mex_destroy(&c57_lhs177);
  sf_mex_destroy(&c57_rhs178);
  sf_mex_destroy(&c57_lhs178);
  sf_mex_destroy(&c57_rhs179);
  sf_mex_destroy(&c57_lhs179);
  sf_mex_destroy(&c57_rhs180);
  sf_mex_destroy(&c57_lhs180);
  sf_mex_destroy(&c57_rhs181);
  sf_mex_destroy(&c57_lhs181);
  sf_mex_destroy(&c57_rhs182);
  sf_mex_destroy(&c57_lhs182);
  sf_mex_destroy(&c57_rhs183);
  sf_mex_destroy(&c57_lhs183);
  sf_mex_destroy(&c57_rhs184);
  sf_mex_destroy(&c57_lhs184);
  sf_mex_destroy(&c57_rhs185);
  sf_mex_destroy(&c57_lhs185);
  sf_mex_destroy(&c57_rhs186);
  sf_mex_destroy(&c57_lhs186);
  sf_mex_destroy(&c57_rhs187);
  sf_mex_destroy(&c57_lhs187);
  sf_mex_destroy(&c57_rhs188);
  sf_mex_destroy(&c57_lhs188);
  sf_mex_destroy(&c57_rhs189);
  sf_mex_destroy(&c57_lhs189);
}

static void c57_eml_scalar_eg(SFc57_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c57_threshold(SFc57_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c57_rdivide(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c57_x, real_T c57_y)
{
  real_T c57_b_x;
  real_T c57_b_y;
  real_T c57_c_x;
  real_T c57_c_y;
  (void)chartInstance;
  c57_b_x = c57_x;
  c57_b_y = c57_y;
  c57_c_x = c57_b_x;
  c57_c_y = c57_b_y;
  return c57_c_x / c57_c_y;
}

static void c57_eml_switch_helper(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c57_check_forloop_overflow_error(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, boolean_T c57_overflow)
{
  int32_T c57_i264;
  static char_T c57_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c57_b_u[34];
  const mxArray *c57_y = NULL;
  int32_T c57_i265;
  static char_T c57_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c57_c_u[5];
  const mxArray *c57_b_y = NULL;
  (void)chartInstance;
  if (!c57_overflow) {
  } else {
    for (c57_i264 = 0; c57_i264 < 34; c57_i264++) {
      c57_b_u[c57_i264] = c57_cv0[c57_i264];
    }

    c57_y = NULL;
    sf_mex_assign(&c57_y, sf_mex_create("y", c57_b_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c57_i265 = 0; c57_i265 < 5; c57_i265++) {
      c57_c_u[c57_i265] = c57_cv1[c57_i265];
    }

    c57_b_y = NULL;
    sf_mex_assign(&c57_b_y, sf_mex_create("y", c57_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c57_y, 14, c57_b_y));
  }
}

static void c57_b_eml_scalar_eg(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c57_c_eml_scalar_eg(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c57_eml_xdotu(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c57_x[2], real_T c57_y[2])
{
  real_T c57_d;
  int32_T c57_k;
  int32_T c57_b_k;
  c57_d = 0.0;
  c57_eml_switch_helper(chartInstance);
  for (c57_k = 1; c57_k < 3; c57_k++) {
    c57_b_k = c57_k;
    c57_d += c57_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
      "", (real_T)c57_b_k), 1, 2, 1, 0) - 1] * c57_y[_SFD_EML_ARRAY_BOUNDS_CHECK
      ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c57_b_k), 1, 2, 1, 0) - 1];
  }

  return c57_d;
}

static void c57_realmin(SFc57_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c57_eps(SFc57_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c57_eml_matlab_zgetrf(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, real_T c57_A[36], real_T c57_b_A[36], int32_T c57_ipiv[6],
  int32_T *c57_info)
{
  int32_T c57_i266;
  for (c57_i266 = 0; c57_i266 < 36; c57_i266++) {
    c57_b_A[c57_i266] = c57_A[c57_i266];
  }

  c57_b_eml_matlab_zgetrf(chartInstance, c57_b_A, c57_ipiv, c57_info);
}

static int32_T c57_eml_ixamax(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  int32_T c57_n, real_T c57_x[36], int32_T c57_ix0)
{
  int32_T c57_idxmax;
  int32_T c57_b_n;
  int32_T c57_b_ix0;
  int32_T c57_c_n;
  int32_T c57_c_ix0;
  int32_T c57_ix;
  real_T c57_b_x;
  real_T c57_c_x;
  real_T c57_d_x;
  real_T c57_y;
  real_T c57_e_x;
  real_T c57_f_x;
  real_T c57_b_y;
  real_T c57_smax;
  int32_T c57_d_n;
  int32_T c57_b;
  int32_T c57_b_b;
  boolean_T c57_overflow;
  int32_T c57_k;
  int32_T c57_b_k;
  int32_T c57_a;
  real_T c57_g_x;
  real_T c57_h_x;
  real_T c57_i_x;
  real_T c57_c_y;
  real_T c57_j_x;
  real_T c57_k_x;
  real_T c57_d_y;
  real_T c57_b_s;
  c57_b_n = c57_n;
  c57_b_ix0 = c57_ix0;
  c57_c_n = c57_b_n;
  c57_c_ix0 = c57_b_ix0;
  if (c57_c_n < 1) {
    c57_idxmax = 0;
  } else {
    c57_idxmax = 1;
    if (c57_c_n > 1) {
      c57_ix = c57_c_ix0;
      c57_b_x = c57_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_ix), 1, 36, 1, 0) - 1];
      c57_c_x = c57_b_x;
      c57_d_x = c57_c_x;
      c57_y = muDoubleScalarAbs(c57_d_x);
      c57_e_x = 0.0;
      c57_f_x = c57_e_x;
      c57_b_y = muDoubleScalarAbs(c57_f_x);
      c57_smax = c57_y + c57_b_y;
      c57_d_n = c57_c_n;
      c57_b = c57_d_n;
      c57_b_b = c57_b;
      if (2 > c57_b_b) {
        c57_overflow = false;
      } else {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_overflow = (c57_b_b > 2147483646);
      }

      if (c57_overflow) {
        c57_check_forloop_overflow_error(chartInstance, c57_overflow);
      }

      for (c57_k = 2; c57_k <= c57_d_n; c57_k++) {
        c57_b_k = c57_k;
        c57_a = c57_ix + 1;
        c57_ix = c57_a;
        c57_g_x = c57_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_ix), 1, 36, 1, 0) - 1];
        c57_h_x = c57_g_x;
        c57_i_x = c57_h_x;
        c57_c_y = muDoubleScalarAbs(c57_i_x);
        c57_j_x = 0.0;
        c57_k_x = c57_j_x;
        c57_d_y = muDoubleScalarAbs(c57_k_x);
        c57_b_s = c57_c_y + c57_d_y;
        if (c57_b_s > c57_smax) {
          c57_idxmax = c57_b_k;
          c57_smax = c57_b_s;
        }
      }
    }
  }

  return c57_idxmax;
}

static void c57_b_eml_switch_helper(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c57_eml_xgeru(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  int32_T c57_m, int32_T c57_n, real_T c57_alpha1, int32_T c57_ix0, int32_T
  c57_iy0, real_T c57_A[36], int32_T c57_ia0, real_T c57_b_A[36])
{
  int32_T c57_i267;
  for (c57_i267 = 0; c57_i267 < 36; c57_i267++) {
    c57_b_A[c57_i267] = c57_A[c57_i267];
  }

  c57_b_eml_xgeru(chartInstance, c57_m, c57_n, c57_alpha1, c57_ix0, c57_iy0,
                  c57_b_A, c57_ia0);
}

static void c57_eml_warning(SFc57_Walking01_DDA3DInstanceStruct *chartInstance)
{
  int32_T c57_i268;
  static char_T c57_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c57_b_u[27];
  const mxArray *c57_y = NULL;
  (void)chartInstance;
  for (c57_i268 = 0; c57_i268 < 27; c57_i268++) {
    c57_b_u[c57_i268] = c57_varargin_1[c57_i268];
  }

  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", c57_b_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c57_y));
}

static void c57_eml_xtrsm(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c57_A[36], real_T c57_B[6], real_T c57_b_B[6])
{
  int32_T c57_i269;
  int32_T c57_i270;
  real_T c57_b_A[36];
  for (c57_i269 = 0; c57_i269 < 6; c57_i269++) {
    c57_b_B[c57_i269] = c57_B[c57_i269];
  }

  for (c57_i270 = 0; c57_i270 < 36; c57_i270++) {
    c57_b_A[c57_i270] = c57_A[c57_i270];
  }

  c57_c_eml_xtrsm(chartInstance, c57_b_A, c57_b_B);
}

static void c57_below_threshold(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  c57_c_eml_switch_helper(chartInstance);
}

static void c57_c_eml_switch_helper(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c57_scalarEg(SFc57_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c57_b_eml_xtrsm(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c57_A[36], real_T c57_B[6], real_T c57_b_B[6])
{
  int32_T c57_i271;
  int32_T c57_i272;
  real_T c57_b_A[36];
  for (c57_i271 = 0; c57_i271 < 6; c57_i271++) {
    c57_b_B[c57_i271] = c57_B[c57_i271];
  }

  for (c57_i272 = 0; c57_i272 < 36; c57_i272++) {
    c57_b_A[c57_i272] = c57_A[c57_i272];
  }

  c57_d_eml_xtrsm(chartInstance, c57_b_A, c57_b_B);
}

static const mxArray *c57_h_sf_marshallOut(void *chartInstanceVoid, void
  *c57_inData)
{
  const mxArray *c57_mxArrayOutData = NULL;
  int32_T c57_b_u;
  const mxArray *c57_y = NULL;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_mxArrayOutData = NULL;
  c57_b_u = *(int32_T *)c57_inData;
  c57_y = NULL;
  sf_mex_assign(&c57_y, sf_mex_create("y", &c57_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c57_mxArrayOutData, c57_y, false);
  return c57_mxArrayOutData;
}

static int32_T c57_g_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId)
{
  int32_T c57_y;
  int32_T c57_i273;
  (void)chartInstance;
  sf_mex_import(c57_parentId, sf_mex_dup(c57_b_u), &c57_i273, 1, 6, 0U, 0, 0U, 0);
  c57_y = c57_i273;
  sf_mex_destroy(&c57_b_u);
  return c57_y;
}

static void c57_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c57_mxArrayInData, const char_T *c57_varName, void *c57_outData)
{
  const mxArray *c57_b_sfEvent;
  const char_T *c57_identifier;
  emlrtMsgIdentifier c57_thisId;
  int32_T c57_y;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_b_sfEvent = sf_mex_dup(c57_mxArrayInData);
  c57_identifier = c57_varName;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_y = c57_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c57_b_sfEvent),
    &c57_thisId);
  sf_mex_destroy(&c57_b_sfEvent);
  *(int32_T *)c57_outData = c57_y;
  sf_mex_destroy(&c57_mxArrayInData);
}

static const mxArray *c57_ControlState_bus_io(void *chartInstanceVoid, void
  *c57_pData)
{
  const mxArray *c57_mxVal = NULL;
  c57_ControlStateBus c57_tmp;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_mxVal = NULL;
  c57_tmp.ControllerMode = *(real_T *)&((char_T *)(c57_ControlStateBus *)
    c57_pData)[0];
  c57_tmp.SupportState = *(real_T *)&((char_T *)(c57_ControlStateBus *)c57_pData)
    [8];
  c57_tmp.StanceLeg = *(real_T *)&((char_T *)(c57_ControlStateBus *)c57_pData)
    [16];
  c57_tmp.InDoubleSupport = *(real_T *)&((char_T *)(c57_ControlStateBus *)
    c57_pData)[24];
  c57_tmp.RollPhase = *(real_T *)&((char_T *)(c57_ControlStateBus *)c57_pData)
    [32];
  c57_tmp.StepCount = *(real_T *)&((char_T *)(c57_ControlStateBus *)c57_pData)
    [40];
  c57_tmp.Error = *(real_T *)&((char_T *)(c57_ControlStateBus *)c57_pData)[48];
  sf_mex_assign(&c57_mxVal, c57_c_sf_marshallOut(chartInstance, &c57_tmp), false);
  return c57_mxVal;
}

static const mxArray *c57_ControlParams_bus_io(void *chartInstanceVoid, void
  *c57_pData)
{
  const mxArray *c57_mxVal = NULL;
  c57_ControlParamsBus c57_tmp;
  int32_T c57_i274;
  int32_T c57_i275;
  int32_T c57_i276;
  int32_T c57_i277;
  int32_T c57_i278;
  int32_T c57_i279;
  int32_T c57_i280;
  int32_T c57_i281;
  int32_T c57_i282;
  int32_T c57_i283;
  int32_T c57_i284;
  int32_T c57_i285;
  int32_T c57_i286;
  int32_T c57_i287;
  int32_T c57_i288;
  int32_T c57_i289;
  int32_T c57_i290;
  int32_T c57_i291;
  int32_T c57_i292;
  int32_T c57_i293;
  int32_T c57_i294;
  int32_T c57_i295;
  int32_T c57_i296;
  int32_T c57_i297;
  int32_T c57_i298;
  int32_T c57_i299;
  int32_T c57_i300;
  int32_T c57_i301;
  int32_T c57_i302;
  int32_T c57_i303;
  int32_T c57_i304;
  int32_T c57_i305;
  int32_T c57_i306;
  int32_T c57_i307;
  int32_T c57_i308;
  int32_T c57_i309;
  int32_T c57_i310;
  int32_T c57_i311;
  int32_T c57_i312;
  int32_T c57_i313;
  int32_T c57_i314;
  int32_T c57_i315;
  int32_T c57_i316;
  int32_T c57_i317;
  int32_T c57_i318;
  int32_T c57_i319;
  int32_T c57_i320;
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c57_mxVal = NULL;
  c57_tmp.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [0];
  c57_tmp.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [8];
  c57_tmp.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [16];
  c57_tmp.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [24];
  c57_tmp.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [32];
  c57_tmp.Supervisory.ImpactThresholdKASpringRel = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [40];
  c57_tmp.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [48];
  c57_tmp.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [56];
  c57_tmp.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [64];
  c57_tmp.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [72];
  c57_tmp.Supervisory.TransitionThresholdTorsoVel = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [80];
  for (c57_i274 = 0; c57_i274 < 2; c57_i274++) {
    c57_tmp.Supervisory.KAInjection[c57_i274] = ((real_T *)&((char_T *)
      (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [0])[88])[c57_i274];
  }

  c57_tmp.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [104];
  c57_tmp.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [112];
  for (c57_i275 = 0; c57_i275 < 6; c57_i275++) {
    c57_tmp.Supervisory.VBLAParams[c57_i275] = ((real_T *)&((char_T *)
      (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [0])[120])[c57_i275];
  }

  for (c57_i276 = 0; c57_i276 < 13; c57_i276++) {
    c57_tmp.Supervisory.BalanceParams[c57_i276] = ((real_T *)&((char_T *)
      (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [0])[168])[c57_i276];
  }

  for (c57_i277 = 0; c57_i277 < 5; c57_i277++) {
    c57_tmp.Supervisory.GaitTweaks[c57_i277] = ((real_T *)&((char_T *)
      (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [0])[272])[c57_i277];
  }

  c57_tmp.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [312];
  c57_tmp.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [320];
  c57_tmp.Supervisory.RunMode = *(real_T *)&((char_T *)(c57_SupervisoryParamsBus
    *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])[328];
  c57_tmp.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [336];
  for (c57_i278 = 0; c57_i278 < 6; c57_i278++) {
    c57_tmp.Supervisory.ErrorZeroFactor[c57_i278] = ((real_T *)&((char_T *)
      (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [0])[344])[c57_i278];
  }

  for (c57_i279 = 0; c57_i279 < 6; c57_i279++) {
    c57_tmp.Supervisory.ErrorVelZeroFactor[c57_i279] = ((real_T *)&((char_T *)
      (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [0])[392])[c57_i279];
  }

  c57_tmp.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [440];
  c57_tmp.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [448];
  c57_tmp.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [456];
  c57_tmp.Supervisory.TPosing = *(real_T *)&((char_T *)(c57_SupervisoryParamsBus
    *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])[464];
  c57_tmp.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [472];
  c57_tmp.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [480];
  c57_tmp.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [488];
  c57_tmp.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [496];
  c57_tmp.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [504];
  c57_tmp.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [512];
  c57_tmp.Supervisory.VelocityControlTorsoGain = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [520];
  c57_tmp.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [528];
  c57_tmp.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [536];
  c57_tmp.Supervisory.Theta0 = *(real_T *)&((char_T *)(c57_SupervisoryParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[0])[544];
  c57_tmp.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [552];
  c57_tmp.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [560];
  c57_tmp.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [568];
  c57_tmp.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [576];
  c57_tmp.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [584];
  c57_tmp.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [592];
  c57_tmp.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [600];
  for (c57_i280 = 0; c57_i280 < 6; c57_i280++) {
    c57_tmp.Supervisory.K1MidStanceUpdate[c57_i280] = ((real_T *)&((char_T *)
      (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [0])[608])[c57_i280];
  }

  for (c57_i281 = 0; c57_i281 < 6; c57_i281++) {
    c57_tmp.Supervisory.K2MidStanceUpdate[c57_i281] = ((real_T *)&((char_T *)
      (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [0])[656])[c57_i281];
  }

  c57_tmp.Supervisory.EnableVelocityBasedUpdate = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [704];
  for (c57_i282 = 0; c57_i282 < 6; c57_i282++) {
    c57_tmp.Supervisory.VelocityBasedUpdateK1[c57_i282] = ((real_T *)&((char_T *)
      (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [0])[712])[c57_i282];
  }

  for (c57_i283 = 0; c57_i283 < 6; c57_i283++) {
    c57_tmp.Supervisory.VelocityBasedUpdateK2[c57_i283] = ((real_T *)&((char_T *)
      (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [0])[760])[c57_i283];
  }

  c57_tmp.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [808];
  c57_i284 = 0;
  for (c57_i285 = 0; c57_i285 < 2; c57_i285++) {
    for (c57_i286 = 0; c57_i286 < 6; c57_i286++) {
      c57_tmp.Supervisory.VelocityBasedUpdateLimits[c57_i286 + c57_i284] =
        ((real_T *)&((char_T *)(c57_SupervisoryParamsBus *)&((char_T *)
           (c57_ControlParamsBus *)c57_pData)[0])[816])[c57_i286 + c57_i284];
    }

    c57_i284 += 6;
  }

  c57_tmp.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [912];
  c57_tmp.Supervisory.dx_cmd = *(real_T *)&((char_T *)(c57_SupervisoryParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[0])[920];
  c57_tmp.Supervisory.ForBackward = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [928];
  c57_tmp.Supervisory.EnableFrictionID = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [936];
  c57_tmp.Supervisory.ResetFrictionPosing = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [944];
  c57_tmp.Supervisory.MoveLegIndex = *(real_T *)&((char_T *)
    (c57_SupervisoryParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[0])
    [952];
  c57_tmp.Supervisory.dy_cmd = *(real_T *)&((char_T *)(c57_SupervisoryParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[0])[960];
  c57_tmp.Discrete.TLastUpdate = *(real_T *)&((char_T *)(c57_DiscreteParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[968])[0];
  c57_tmp.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[968])
    [8];
  c57_tmp.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[968])
    [16];
  c57_tmp.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[968])
    [24];
  c57_tmp.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[968])
    [32];
  c57_tmp.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[968])
    [40];
  c57_tmp.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[968])
    [48];
  c57_tmp.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[968])
    [56];
  c57_tmp.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[968])
    [64];
  c57_tmp.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[968])
    [72];
  c57_tmp.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c57_DiscreteParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[968])
    [80];
  c57_i287 = 0;
  for (c57_i288 = 0; c57_i288 < 13; c57_i288++) {
    for (c57_i289 = 0; c57_i289 < 6; c57_i289++) {
      c57_tmp.Output.H0[c57_i289 + c57_i287] = ((real_T *)&((char_T *)
        (c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
        [1056])[0])[c57_i289 + c57_i287];
    }

    c57_i287 += 6;
  }

  c57_i290 = 0;
  for (c57_i291 = 0; c57_i291 < 6; c57_i291++) {
    for (c57_i292 = 0; c57_i292 < 6; c57_i292++) {
      c57_tmp.Output.HAlpha[c57_i292 + c57_i290] = ((real_T *)&((char_T *)
        (c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
        [1056])[624])[c57_i292 + c57_i290];
    }

    c57_i290 += 6;
  }

  for (c57_i293 = 0; c57_i293 < 2; c57_i293++) {
    c57_tmp.Output.ThetaLimits[c57_i293] = ((real_T *)&((char_T *)
      (c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[1056])
      [912])[c57_i293];
  }

  c57_tmp.Output.Theta.c0 = *(real_T *)&((char_T *)(c57_ThetaParamsBus *)
    &((char_T *)(c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)
    c57_pData)[1056])[928])[0];
  c57_tmp.Output.Theta.ct = *(real_T *)&((char_T *)(c57_ThetaParamsBus *)
    &((char_T *)(c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)
    c57_pData)[1056])[928])[8];
  for (c57_i294 = 0; c57_i294 < 13; c57_i294++) {
    c57_tmp.Output.Theta.cq[c57_i294] = ((real_T *)&((char_T *)
      (c57_ThetaParamsBus *)&((char_T *)(c57_OutputParamsBus *)&((char_T *)
      (c57_ControlParamsBus *)c57_pData)[1056])[928])[16])[c57_i294];
  }

  c57_tmp.Output.Theta.t0 = *(real_T *)&((char_T *)(c57_ThetaParamsBus *)
    &((char_T *)(c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)
    c57_pData)[1056])[928])[120];
  for (c57_i295 = 0; c57_i295 < 7; c57_i295++) {
    c57_tmp.Output.Theta.cz[c57_i295] = ((real_T *)&((char_T *)
      (c57_ThetaParamsBus *)&((char_T *)(c57_OutputParamsBus *)&((char_T *)
      (c57_ControlParamsBus *)c57_pData)[1056])[928])[128])[c57_i295];
  }

  c57_tmp.Output.SaturateS = *(real_T *)&((char_T *)(c57_OutputParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[1056])[1112];
  for (c57_i296 = 0; c57_i296 < 2; c57_i296++) {
    c57_tmp.Output.SLimits[c57_i296] = ((real_T *)&((char_T *)
      (c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[1056])
      [1120])[c57_i296];
  }

  c57_tmp.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[1056])
    [1136];
  c57_tmp.Output.UseCorrection = *(real_T *)&((char_T *)(c57_OutputParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[1056])[1144];
  c57_tmp.Output.SMaxCorrection = *(real_T *)&((char_T *)(c57_OutputParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[1056])[1152];
  c57_i297 = 0;
  for (c57_i298 = 0; c57_i298 < 5; c57_i298++) {
    for (c57_i299 = 0; c57_i299 < 6; c57_i299++) {
      c57_tmp.Output.HAlphaCorrection[c57_i299 + c57_i297] = ((real_T *)
        &((char_T *)(c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)
        c57_pData)[1056])[1160])[c57_i299 + c57_i297];
    }

    c57_i297 += 6;
  }

  c57_tmp.Output.Phi.c0 = *(real_T *)&((char_T *)(c57_PhiParamsBus *)&((char_T *)
                                        (c57_OutputParamsBus *)&((char_T *)
    (c57_ControlParamsBus *)c57_pData)[1056])[1400])[0];
  for (c57_i300 = 0; c57_i300 < 13; c57_i300++) {
    c57_tmp.Output.Phi.cq[c57_i300] = ((real_T *)&((char_T *)(c57_PhiParamsBus *)
      &((char_T *)(c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)
      c57_pData)[1056])[1400])[8])[c57_i300];
  }

  for (c57_i301 = 0; c57_i301 < 20; c57_i301++) {
    c57_tmp.Output.PhiAlpha[c57_i301] = ((real_T *)&((char_T *)
      (c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[1056])
      [1512])[c57_i301];
  }

  c57_tmp.Output.SaturateR = *(real_T *)&((char_T *)(c57_OutputParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[1056])[1672];
  for (c57_i302 = 0; c57_i302 < 2; c57_i302++) {
    c57_tmp.Output.RLimits[c57_i302] = ((real_T *)&((char_T *)
      (c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[1056])
      [1680])[c57_i302];
  }

  c57_i303 = 0;
  for (c57_i304 = 0; c57_i304 < 5; c57_i304++) {
    for (c57_i305 = 0; c57_i305 < 6; c57_i305++) {
      c57_tmp.Output.HBarAlpha[c57_i305 + c57_i303] = ((real_T *)&((char_T *)
        (c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
        [1056])[1696])[c57_i305 + c57_i303];
    }

    c57_i303 += 6;
  }

  c57_i306 = 0;
  for (c57_i307 = 0; c57_i307 < 2; c57_i307++) {
    for (c57_i308 = 0; c57_i308 < 6; c57_i308++) {
      c57_tmp.Output.HBarLimits[c57_i308 + c57_i306] = ((real_T *)&((char_T *)
        (c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
        [1056])[1936])[c57_i308 + c57_i306];
    }

    c57_i306 += 6;
  }

  c57_i309 = 0;
  for (c57_i310 = 0; c57_i310 < 6; c57_i310++) {
    for (c57_i311 = 0; c57_i311 < 6; c57_i311++) {
      c57_tmp.Output.HAlphaStar[c57_i311 + c57_i309] = ((real_T *)&((char_T *)
        (c57_OutputParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
        [1056])[2032])[c57_i311 + c57_i309];
    }

    c57_i309 += 6;
  }

  c57_tmp.Output.YawLimit = *(real_T *)&((char_T *)(c57_OutputParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[1056])[2320];
  c57_tmp.Output.test = *(real_T *)&((char_T *)(c57_OutputParamsBus *)&((char_T *)
                                      (c57_ControlParamsBus *)c57_pData)[1056])
    [2328];
  for (c57_i312 = 0; c57_i312 < 6; c57_i312++) {
    c57_tmp.Feedback.kp[c57_i312] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [3392])[0])[c57_i312];
  }

  for (c57_i313 = 0; c57_i313 < 6; c57_i313++) {
    c57_tmp.Feedback.kd[c57_i313] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [3392])[48])[c57_i313];
  }

  for (c57_i314 = 0; c57_i314 < 2; c57_i314++) {
    c57_tmp.Feedback.epsilon[c57_i314] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [3392])[96])[c57_i314];
  }

  for (c57_i315 = 0; c57_i315 < 2; c57_i315++) {
    c57_tmp.Feedback.kff_grav[c57_i315] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [3392])[112])[c57_i315];
  }

  c57_tmp.Feedback.delta_grav = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[128];
  for (c57_i316 = 0; c57_i316 < 2; c57_i316++) {
    c57_tmp.Feedback.kff_decoup[c57_i316] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [3392])[136])[c57_i316];
  }

  for (c57_i317 = 0; c57_i317 < 2; c57_i317++) {
    c57_tmp.Feedback.kd_torso[c57_i317] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [3392])[152])[c57_i317];
  }

  c57_tmp.Feedback.kp_2dof = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[168];
  c57_tmp.Feedback.kd_2dof = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[176];
  c57_tmp.Feedback.kpre_2dof = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[184];
  c57_tmp.Feedback.kp_lat = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[192];
  c57_tmp.Feedback.kd_lat = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[200];
  c57_tmp.Feedback.q3d_min_lat = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[208];
  c57_tmp.Feedback.q3d_max_lat = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[216];
  c57_tmp.Feedback.w_torso_lat = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[224];
  for (c57_i318 = 0; c57_i318 < 6; c57_i318++) {
    c57_tmp.Feedback.u_ff[c57_i318] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [3392])[232])[c57_i318];
  }

  c57_tmp.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])
    [280];
  c57_tmp.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])
    [288];
  c57_tmp.Feedback.Use2DOF = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[296];
  c57_tmp.Feedback.UseDSGravComp = *(real_T *)&((char_T *)(c57_FeedbackParamsBus
    *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[304];
  c57_tmp.Feedback.lat_bias = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[312];
  c57_tmp.Feedback.lat_bias2 = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[320];
  c57_tmp.Feedback.linkFeedback = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[328];
  c57_tmp.Feedback.RIO = *(real_T *)&((char_T *)(c57_FeedbackParamsBus *)
    &((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])[336];
  c57_tmp.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])
    [344];
  for (c57_i319 = 0; c57_i319 < 6; c57_i319++) {
    c57_tmp.Feedback.FeedforwardGain[c57_i319] = ((real_T *)&((char_T *)
      (c57_FeedbackParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [3392])[352])[c57_i319];
  }

  c57_tmp.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c57_FeedbackParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)[3392])
    [400];
  c57_tmp.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c57_SaturationParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
    [3800])[0];
  for (c57_i320 = 0; c57_i320 < 2; c57_i320++) {
    c57_tmp.Saturation.QPWeight[c57_i320] = ((real_T *)&((char_T *)
      (c57_SaturationParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
      [3800])[8])[c57_i320];
  }

  c57_tmp.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c57_SaturationParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
    [3800])[24];
  c57_tmp.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c57_SaturationParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
    [3800])[32];
  c57_tmp.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c57_SaturationParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
    [3800])[40];
  c57_tmp.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c57_SaturationParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
    [3800])[48];
  c57_tmp.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c57_SaturationParamsBus *)&((char_T *)(c57_ControlParamsBus *)c57_pData)
    [3800])[56];
  sf_mex_assign(&c57_mxVal, c57_b_sf_marshallOut(chartInstance, &c57_tmp), false);
  return c57_mxVal;
}

static uint8_T c57_h_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_is_active_c57_Walking01_DDA3D, const
  char_T *c57_identifier)
{
  uint8_T c57_y;
  emlrtMsgIdentifier c57_thisId;
  c57_thisId.fIdentifier = c57_identifier;
  c57_thisId.fParent = NULL;
  c57_y = c57_i_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c57_b_is_active_c57_Walking01_DDA3D), &c57_thisId);
  sf_mex_destroy(&c57_b_is_active_c57_Walking01_DDA3D);
  return c57_y;
}

static uint8_T c57_i_emlrt_marshallIn(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c57_b_u, const emlrtMsgIdentifier *c57_parentId)
{
  uint8_T c57_y;
  uint8_T c57_u0;
  (void)chartInstance;
  sf_mex_import(c57_parentId, sf_mex_dup(c57_b_u), &c57_u0, 1, 3, 0U, 0, 0U, 0);
  c57_y = c57_u0;
  sf_mex_destroy(&c57_b_u);
  return c57_y;
}

static void c57_b_eml_matlab_zgetrf(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance, real_T c57_A[36], int32_T c57_ipiv[6], int32_T *c57_info)
{
  int32_T c57_i321;
  int32_T c57_j;
  int32_T c57_b_j;
  int32_T c57_a;
  int32_T c57_b_a;
  int32_T c57_jm1;
  int32_T c57_b;
  int32_T c57_b_b;
  int32_T c57_mmj;
  int32_T c57_c_a;
  int32_T c57_d_a;
  int32_T c57_c;
  int32_T c57_c_b;
  int32_T c57_d_b;
  int32_T c57_jj;
  int32_T c57_e_a;
  int32_T c57_f_a;
  int32_T c57_jp1j;
  int32_T c57_g_a;
  int32_T c57_h_a;
  int32_T c57_b_c;
  int32_T c57_i322;
  real_T c57_b_A[36];
  int32_T c57_i_a;
  int32_T c57_j_a;
  int32_T c57_jpiv_offset;
  int32_T c57_k_a;
  int32_T c57_e_b;
  int32_T c57_l_a;
  int32_T c57_f_b;
  int32_T c57_jpiv;
  int32_T c57_m_a;
  int32_T c57_g_b;
  int32_T c57_n_a;
  int32_T c57_h_b;
  int32_T c57_c_c;
  int32_T c57_i_b;
  int32_T c57_j_b;
  int32_T c57_jrow;
  int32_T c57_o_a;
  int32_T c57_k_b;
  int32_T c57_p_a;
  int32_T c57_l_b;
  int32_T c57_jprow;
  int32_T c57_ix0;
  int32_T c57_iy0;
  int32_T c57_b_ix0;
  int32_T c57_b_iy0;
  int32_T c57_c_ix0;
  int32_T c57_c_iy0;
  int32_T c57_ix;
  int32_T c57_iy;
  int32_T c57_k;
  real_T c57_temp;
  int32_T c57_q_a;
  int32_T c57_r_a;
  int32_T c57_b_jp1j;
  int32_T c57_s_a;
  int32_T c57_t_a;
  int32_T c57_d_c;
  int32_T c57_u_a;
  int32_T c57_m_b;
  int32_T c57_v_a;
  int32_T c57_n_b;
  int32_T c57_i323;
  int32_T c57_w_a;
  int32_T c57_o_b;
  int32_T c57_x_a;
  int32_T c57_p_b;
  boolean_T c57_overflow;
  int32_T c57_i;
  int32_T c57_b_i;
  real_T c57_x;
  real_T c57_y;
  real_T c57_b_x;
  real_T c57_b_y;
  real_T c57_z;
  int32_T c57_q_b;
  int32_T c57_r_b;
  int32_T c57_e_c;
  int32_T c57_y_a;
  int32_T c57_ab_a;
  int32_T c57_f_c;
  int32_T c57_bb_a;
  int32_T c57_cb_a;
  int32_T c57_g_c;
  c57_realmin(chartInstance);
  c57_eps(chartInstance);
  for (c57_i321 = 0; c57_i321 < 6; c57_i321++) {
    c57_ipiv[c57_i321] = 1 + c57_i321;
  }

  *c57_info = 0;
  c57_eml_switch_helper(chartInstance);
  for (c57_j = 1; c57_j < 6; c57_j++) {
    c57_b_j = c57_j;
    c57_a = c57_b_j;
    c57_b_a = c57_a - 1;
    c57_jm1 = c57_b_a;
    c57_b = c57_b_j;
    c57_b_b = c57_b;
    c57_mmj = 6 - c57_b_b;
    c57_c_a = c57_jm1;
    c57_d_a = c57_c_a;
    c57_c = c57_d_a * 7;
    c57_c_b = c57_c;
    c57_d_b = c57_c_b + 1;
    c57_jj = c57_d_b;
    c57_e_a = c57_jj;
    c57_f_a = c57_e_a + 1;
    c57_jp1j = c57_f_a;
    c57_g_a = c57_mmj;
    c57_h_a = c57_g_a;
    c57_b_c = c57_h_a;
    for (c57_i322 = 0; c57_i322 < 36; c57_i322++) {
      c57_b_A[c57_i322] = c57_A[c57_i322];
    }

    c57_i_a = c57_eml_ixamax(chartInstance, c57_b_c + 1, c57_b_A, c57_jj);
    c57_j_a = c57_i_a - 1;
    c57_jpiv_offset = c57_j_a;
    c57_k_a = c57_jj;
    c57_e_b = c57_jpiv_offset;
    c57_l_a = c57_k_a;
    c57_f_b = c57_e_b;
    c57_jpiv = c57_l_a + c57_f_b;
    if (c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c57_jpiv), 1, 36, 1, 0) - 1] != 0.0) {
      if (c57_jpiv_offset != 0) {
        c57_m_a = c57_b_j;
        c57_g_b = c57_jpiv_offset;
        c57_n_a = c57_m_a;
        c57_h_b = c57_g_b;
        c57_c_c = c57_n_a + c57_h_b;
        c57_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c57_b_j), 1, 6, 1, 0) - 1] = c57_c_c;
        c57_i_b = c57_jm1;
        c57_j_b = c57_i_b + 1;
        c57_jrow = c57_j_b;
        c57_o_a = c57_jrow;
        c57_k_b = c57_jpiv_offset;
        c57_p_a = c57_o_a;
        c57_l_b = c57_k_b;
        c57_jprow = c57_p_a + c57_l_b;
        c57_ix0 = c57_jrow;
        c57_iy0 = c57_jprow;
        c57_b_ix0 = c57_ix0;
        c57_b_iy0 = c57_iy0;
        c57_b_eml_switch_helper(chartInstance);
        c57_c_ix0 = c57_b_ix0;
        c57_c_iy0 = c57_b_iy0;
        c57_ix = c57_c_ix0;
        c57_iy = c57_c_iy0;
        c57_eml_switch_helper(chartInstance);
        for (c57_k = 1; c57_k < 7; c57_k++) {
          c57_temp = c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c57_ix), 1, 36, 1, 0) - 1];
          c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c57_ix), 1, 36, 1, 0) - 1] =
            c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c57_iy), 1, 36, 1, 0) - 1];
          c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c57_iy), 1, 36, 1, 0) - 1] = c57_temp;
          c57_q_a = c57_ix + 6;
          c57_ix = c57_q_a;
          c57_r_a = c57_iy + 6;
          c57_iy = c57_r_a;
        }
      }

      c57_b_jp1j = c57_jp1j;
      c57_s_a = c57_mmj;
      c57_t_a = c57_s_a;
      c57_d_c = c57_t_a;
      c57_u_a = c57_jp1j;
      c57_m_b = c57_d_c - 1;
      c57_v_a = c57_u_a;
      c57_n_b = c57_m_b;
      c57_i323 = c57_v_a + c57_n_b;
      c57_w_a = c57_b_jp1j;
      c57_o_b = c57_i323;
      c57_x_a = c57_w_a;
      c57_p_b = c57_o_b;
      if (c57_x_a > c57_p_b) {
        c57_overflow = false;
      } else {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_overflow = (c57_p_b > 2147483646);
      }

      if (c57_overflow) {
        c57_check_forloop_overflow_error(chartInstance, c57_overflow);
      }

      for (c57_i = c57_b_jp1j; c57_i <= c57_i323; c57_i++) {
        c57_b_i = c57_i;
        c57_x = c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_b_i), 1, 36, 1, 0) - 1];
        c57_y = c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c57_jj), 1, 36, 1, 0) - 1];
        c57_b_x = c57_x;
        c57_b_y = c57_y;
        c57_z = c57_b_x / c57_b_y;
        c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c57_b_i), 1, 36, 1, 0) - 1] = c57_z;
      }
    } else {
      *c57_info = c57_b_j;
    }

    c57_q_b = c57_b_j;
    c57_r_b = c57_q_b;
    c57_e_c = 6 - c57_r_b;
    c57_y_a = c57_jj;
    c57_ab_a = c57_y_a;
    c57_f_c = c57_ab_a;
    c57_bb_a = c57_jj;
    c57_cb_a = c57_bb_a;
    c57_g_c = c57_cb_a;
    c57_b_eml_xgeru(chartInstance, c57_mmj, c57_e_c, -1.0, c57_jp1j, c57_f_c + 6,
                    c57_A, c57_g_c + 7);
  }

  if (*c57_info == 0) {
    if (!(c57_A[35] != 0.0)) {
      *c57_info = 6;
    }
  }
}

static void c57_b_eml_xgeru(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  int32_T c57_m, int32_T c57_n, real_T c57_alpha1, int32_T c57_ix0, int32_T
  c57_iy0, real_T c57_A[36], int32_T c57_ia0)
{
  int32_T c57_b_m;
  int32_T c57_b_n;
  real_T c57_b_alpha1;
  int32_T c57_b_ix0;
  int32_T c57_b_iy0;
  int32_T c57_b_ia0;
  int32_T c57_c_m;
  int32_T c57_c_n;
  real_T c57_c_alpha1;
  int32_T c57_c_ix0;
  int32_T c57_c_iy0;
  int32_T c57_c_ia0;
  int32_T c57_d_m;
  int32_T c57_d_n;
  real_T c57_d_alpha1;
  int32_T c57_d_ix0;
  int32_T c57_d_iy0;
  int32_T c57_d_ia0;
  int32_T c57_e_m;
  int32_T c57_e_n;
  real_T c57_e_alpha1;
  int32_T c57_e_ix0;
  int32_T c57_e_iy0;
  int32_T c57_e_ia0;
  int32_T c57_ixstart;
  int32_T c57_a;
  int32_T c57_jA;
  int32_T c57_jy;
  int32_T c57_f_n;
  int32_T c57_b;
  int32_T c57_b_b;
  boolean_T c57_overflow;
  int32_T c57_j;
  real_T c57_yjy;
  real_T c57_temp;
  int32_T c57_ix;
  int32_T c57_c_b;
  int32_T c57_i324;
  int32_T c57_b_a;
  int32_T c57_d_b;
  int32_T c57_i325;
  int32_T c57_c_a;
  int32_T c57_e_b;
  int32_T c57_d_a;
  int32_T c57_f_b;
  boolean_T c57_b_overflow;
  int32_T c57_ijA;
  int32_T c57_b_ijA;
  int32_T c57_e_a;
  int32_T c57_f_a;
  int32_T c57_g_a;
  c57_b_m = c57_m;
  c57_b_n = c57_n;
  c57_b_alpha1 = c57_alpha1;
  c57_b_ix0 = c57_ix0;
  c57_b_iy0 = c57_iy0;
  c57_b_ia0 = c57_ia0;
  c57_c_m = c57_b_m;
  c57_c_n = c57_b_n;
  c57_c_alpha1 = c57_b_alpha1;
  c57_c_ix0 = c57_b_ix0;
  c57_c_iy0 = c57_b_iy0;
  c57_c_ia0 = c57_b_ia0;
  c57_d_m = c57_c_m;
  c57_d_n = c57_c_n;
  c57_d_alpha1 = c57_c_alpha1;
  c57_d_ix0 = c57_c_ix0;
  c57_d_iy0 = c57_c_iy0;
  c57_d_ia0 = c57_c_ia0;
  c57_e_m = c57_d_m;
  c57_e_n = c57_d_n;
  c57_e_alpha1 = c57_d_alpha1;
  c57_e_ix0 = c57_d_ix0;
  c57_e_iy0 = c57_d_iy0;
  c57_e_ia0 = c57_d_ia0;
  if (c57_e_alpha1 == 0.0) {
  } else {
    c57_ixstart = c57_e_ix0;
    c57_a = c57_e_ia0 - 1;
    c57_jA = c57_a;
    c57_jy = c57_e_iy0;
    c57_f_n = c57_e_n;
    c57_b = c57_f_n;
    c57_b_b = c57_b;
    if (1 > c57_b_b) {
      c57_overflow = false;
    } else {
      c57_eml_switch_helper(chartInstance);
      c57_eml_switch_helper(chartInstance);
      c57_overflow = (c57_b_b > 2147483646);
    }

    if (c57_overflow) {
      c57_check_forloop_overflow_error(chartInstance, c57_overflow);
    }

    for (c57_j = 1; c57_j <= c57_f_n; c57_j++) {
      c57_yjy = c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c57_jy), 1, 36, 1, 0) - 1];
      if (c57_yjy != 0.0) {
        c57_temp = c57_yjy * c57_e_alpha1;
        c57_ix = c57_ixstart;
        c57_c_b = c57_jA + 1;
        c57_i324 = c57_c_b;
        c57_b_a = c57_e_m;
        c57_d_b = c57_jA;
        c57_i325 = c57_b_a + c57_d_b;
        c57_c_a = c57_i324;
        c57_e_b = c57_i325;
        c57_d_a = c57_c_a;
        c57_f_b = c57_e_b;
        if (c57_d_a > c57_f_b) {
          c57_b_overflow = false;
        } else {
          c57_eml_switch_helper(chartInstance);
          c57_eml_switch_helper(chartInstance);
          c57_b_overflow = (c57_f_b > 2147483646);
        }

        if (c57_b_overflow) {
          c57_check_forloop_overflow_error(chartInstance, c57_b_overflow);
        }

        for (c57_ijA = c57_i324; c57_ijA <= c57_i325; c57_ijA++) {
          c57_b_ijA = c57_ijA;
          c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c57_b_ijA), 1, 36, 1, 0) - 1] =
            c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c57_b_ijA), 1, 36, 1, 0) - 1] +
            c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c57_ix), 1, 36, 1, 0) - 1] * c57_temp;
          c57_e_a = c57_ix + 1;
          c57_ix = c57_e_a;
        }
      }

      c57_f_a = c57_jy + 6;
      c57_jy = c57_f_a;
      c57_g_a = c57_jA + 6;
      c57_jA = c57_g_a;
    }
  }
}

static void c57_c_eml_xtrsm(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c57_A[36], real_T c57_B[6])
{
  int32_T c57_k;
  int32_T c57_b_k;
  int32_T c57_kAcol;
  int32_T c57_i326;
  int32_T c57_a;
  int32_T c57_b_a;
  boolean_T c57_overflow;
  int32_T c57_i;
  int32_T c57_b_i;
  c57_below_threshold(chartInstance);
  c57_scalarEg(chartInstance);
  c57_eml_switch_helper(chartInstance);
  for (c57_k = 1; c57_k < 7; c57_k++) {
    c57_b_k = c57_k;
    c57_kAcol = 6 * (c57_b_k - 1);
    if (c57_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c57_b_k), 1, 6, 1, 0) - 1] != 0.0) {
      c57_i326 = c57_b_k + 1;
      c57_a = c57_i326;
      c57_b_a = c57_a;
      if (c57_b_a > 6) {
        c57_overflow = false;
      } else {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_overflow = false;
      }

      if (c57_overflow) {
        c57_check_forloop_overflow_error(chartInstance, c57_overflow);
      }

      for (c57_i = c57_i326; c57_i < 7; c57_i++) {
        c57_b_i = c57_i;
        c57_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c57_b_i), 1, 6, 1, 0) - 1] = c57_B[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c57_b_i), 1, 6, 1, 0) - 1]
          - c57_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c57_b_k), 1, 6, 1, 0) - 1] * c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c57_b_i + c57_kAcol)), 1,
           36, 1, 0) - 1];
      }
    }
  }
}

static void c57_d_eml_xtrsm(SFc57_Walking01_DDA3DInstanceStruct *chartInstance,
  real_T c57_A[36], real_T c57_B[6])
{
  int32_T c57_k;
  int32_T c57_b_k;
  int32_T c57_kAcol;
  int32_T c57_i327;
  int32_T c57_b;
  int32_T c57_b_b;
  boolean_T c57_overflow;
  int32_T c57_i;
  int32_T c57_b_i;
  c57_below_threshold(chartInstance);
  c57_scalarEg(chartInstance);
  c57_eml_switch_helper(chartInstance);
  for (c57_k = 6; c57_k > 0; c57_k--) {
    c57_b_k = c57_k;
    c57_kAcol = 6 * (c57_b_k - 1);
    if (c57_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c57_b_k), 1, 6, 1, 0) - 1] != 0.0) {
      c57_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c57_b_k), 1, 6, 1, 0) - 1] = c57_rdivide(chartInstance,
        c57_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c57_b_k), 1, 6, 1, 0) - 1], c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c57_b_k + c57_kAcol)), 1, 36, 1,
        0) - 1]);
      c57_i327 = c57_b_k - 1;
      c57_b = c57_i327;
      c57_b_b = c57_b;
      if (1 > c57_b_b) {
        c57_overflow = false;
      } else {
        c57_eml_switch_helper(chartInstance);
        c57_eml_switch_helper(chartInstance);
        c57_overflow = (c57_b_b > 2147483646);
      }

      if (c57_overflow) {
        c57_check_forloop_overflow_error(chartInstance, c57_overflow);
      }

      for (c57_i = 1; c57_i <= c57_i327; c57_i++) {
        c57_b_i = c57_i;
        c57_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c57_b_i), 1, 6, 1, 0) - 1] = c57_B[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c57_b_i), 1, 6, 1, 0) - 1]
          - c57_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c57_b_k), 1, 6, 1, 0) - 1] * c57_A[_SFD_EML_ARRAY_BOUNDS_CHECK
          ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c57_b_i + c57_kAcol)), 1,
           36, 1, 0) - 1];
      }
    }
  }
}

static void init_dsm_address_info(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc57_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c57_u = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c57_s = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c57_u_sat = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c57_sat = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c57_ControlState = (c57_ControlStateBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c57_ControlParams = (c57_ControlParamsBus *)
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

void sf_c57_Walking01_DDA3D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1890351595U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4102761600U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(960657152U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1944951963U);
}

mxArray* sf_c57_Walking01_DDA3D_get_post_codegen_info(void);
mxArray *sf_c57_Walking01_DDA3D_get_autoinheritance_info(void)
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
    mxArray* mxPostCodegenInfo = sf_c57_Walking01_DDA3D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c57_Walking01_DDA3D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c57_Walking01_DDA3D_jit_fallback_info(void)
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

mxArray *sf_c57_Walking01_DDA3D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c57_Walking01_DDA3D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c57_Walking01_DDA3D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"u_sat\",},{M[8],M[0],T\"is_active_c57_Walking01_DDA3D\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c57_Walking01_DDA3D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_DDA3DMachineNumber_,
           57,
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
            1.0,0,0,(MexFcnForType)c57_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c57_e_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c57_sf_marshallOut,(MexInFcnForType)
            c57_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c57_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c57_ControlState_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c57_ControlParams_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c57_u);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c57_s);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c57_u_sat);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c57_sat);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c57_ControlState);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c57_ControlParams);
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
  return "zb3GepeATF4CN063tIxmaG";
}

static void sf_opaque_initialize_c57_Walking01_DDA3D(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc57_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c57_Walking01_DDA3D((SFc57_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
  initialize_c57_Walking01_DDA3D((SFc57_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c57_Walking01_DDA3D(void *chartInstanceVar)
{
  enable_c57_Walking01_DDA3D((SFc57_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c57_Walking01_DDA3D(void *chartInstanceVar)
{
  disable_c57_Walking01_DDA3D((SFc57_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c57_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_gateway_c57_Walking01_DDA3D((SFc57_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c57_Walking01_DDA3D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c57_Walking01_DDA3D((SFc57_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c57_Walking01_DDA3D(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c57_Walking01_DDA3D((SFc57_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c57_Walking01_DDA3D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc57_Walking01_DDA3DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_DDA3D_optimization_info();
    }

    finalize_c57_Walking01_DDA3D((SFc57_Walking01_DDA3DInstanceStruct*)
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
  initSimStructsc57_Walking01_DDA3D((SFc57_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c57_Walking01_DDA3D(SimStruct *S)
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
    initialize_params_c57_Walking01_DDA3D((SFc57_Walking01_DDA3DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c57_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      57);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,57,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,57,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,57);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,57,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,57,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,57);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2137476234U));
  ssSetChecksum1(S,(490241066U));
  ssSetChecksum2(S,(2611871372U));
  ssSetChecksum3(S,(3952351903U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c57_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c57_Walking01_DDA3D(SimStruct *S)
{
  SFc57_Walking01_DDA3DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc57_Walking01_DDA3DInstanceStruct *)utMalloc(sizeof
    (SFc57_Walking01_DDA3DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc57_Walking01_DDA3DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c57_Walking01_DDA3D;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c57_Walking01_DDA3D;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c57_Walking01_DDA3D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c57_Walking01_DDA3D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c57_Walking01_DDA3D;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c57_Walking01_DDA3D;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c57_Walking01_DDA3D;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c57_Walking01_DDA3D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c57_Walking01_DDA3D;
  chartInstance->chartInfo.mdlStart = mdlStart_c57_Walking01_DDA3D;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c57_Walking01_DDA3D;
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

void c57_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c57_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c57_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c57_Walking01_DDA3D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c57_Walking01_DDA3D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
