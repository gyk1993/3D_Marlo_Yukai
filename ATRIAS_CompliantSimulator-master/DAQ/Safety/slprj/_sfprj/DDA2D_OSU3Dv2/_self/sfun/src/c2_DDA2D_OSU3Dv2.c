/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DDA2D_OSU3Dv2_sfun.h"
#include "c2_DDA2D_OSU3Dv2.h"
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
static const char * c2_debug_family_names[43] = { "q", "dq", "K_spring",
  "K_damping", "FSpring", "H", "kpboom", "kdboom", "C", "alpha", "KP", "KD",
  "v_con", "CDinv", "CinvCDinvC", "proj", "JBoom", "dJBoom", "pB", "vB", "eB",
  "JBoom_D", "A", "P", "ddq", "nargin", "nargout", "x", "u", "D", "Cdq", "G",
  "B", "FGround", "Fstiction", "spring_k", "spring_zeta", "ProjectTo2D",
  "ExternalHipForce", "BoomParams", "pBInitial", "Ttime", "x_dot" };

static const char * c2_b_debug_family_names[8] = { "k_damping", "K_matrix",
  "nargin", "nargout", "k_spring", "zeta", "K_spring", "K_damping" };

static const char * c2_c_debug_family_names[42] = { "xT", "dxT", "yT", "dyT",
  "zT", "dzT", "qzT", "dqzT", "qyT", "dqyT", "qxT", "dqxT", "q1R", "dq1R", "q2R",
  "dq2R", "q1L", "dq1L", "q2L", "dq2L", "qgr1R", "dqgr1R", "qgr2R", "dqgr2R",
  "q3R", "dq3R", "qgr1L", "dqgr1L", "qgr2L", "dqgr2L", "q3L", "dq3L", "xB", "yB",
  "zB", "nargin", "nargout", "q", "dq", "BoomParams", "jacob_pB0",
  "jacob_jacob_pB0" };

static const char * c2_d_debug_family_names[24] = { "xT", "yT", "zT", "qzT",
  "qyT", "qxT", "q1R", "q2R", "q1L", "q2L", "qgr1R", "qgr2R", "q3R", "qgr1L",
  "qgr2L", "q3L", "xB", "yB", "zB", "nargin", "nargout", "q", "BoomParams",
  "pB0" };

/* Function Declarations */
static void initialize_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initialize_params_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct *
  chartInstance);
static void enable_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void disable_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c2_update_debugger_state_c2_DDA2D_OSU3Dv2
  (SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c2_DDA2D_OSU3Dv2
  (SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void set_sim_state_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_st);
static void finalize_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void sf_gateway_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void mdl_start_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c2_chartstep_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initSimStructsc2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c2_ATRIAS3D_Spring_Constants(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c2_k_spring, real_T c2_zeta, real_T c2_K_spring[256],
  real_T c2_K_damping[256]);
static void c2_JacobBoomHip_FixParams(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c2_q[16], real_T c2_dq[16], real_T c2_b_BoomParams[3],
  real_T c2_jacob_pB0[48], real_T c2_jacob_jacob_pB0[3]);
static void c2_BoomPositionHip_FixParams(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c2_q[16], real_T c2_b_BoomParams[3], real_T c2_pB0[3]);
static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber);
static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData);
static void c2_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  const mxArray *c2_b_x_dot, const char_T *c2_identifier, real_T c2_y[32]);
static void c2_b_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[32]);
static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_c_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3]);
static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static real_T c2_d_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_e_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5]);
static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_f_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16]);
static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_g_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256]);
static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_h_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[48]);
static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_i_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[48]);
static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_j_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3]);
static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_l_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_k_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[80]);
static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static const mxArray *c2_m_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static void c2_l_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[80]);
static void c2_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static void c2_info_helper(const mxArray **c2_info);
static const mxArray *c2_emlrt_marshallOut(const char * c2_b_u);
static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_b_u);
static void c2_b_info_helper(const mxArray **c2_info);
static void c2_c_info_helper(const mxArray **c2_info);
static void c2_eml_error(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_b_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static real_T c2_mpower(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_a);
static void c2_c_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_d_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_mrdivide(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_A[80], real_T c2_b_B[256], real_T c2_y[80]);
static void c2_eml_lusolve(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[80], real_T c2_X[80]);
static void c2_realmin(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_eps(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_eml_switch_helper(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_eml_matlab_zgetrf(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_A[256], int32_T c2_ipiv[16], int32_T *c2_info);
static void c2_b_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_check_forloop_overflow_error(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, boolean_T c2_overflow);
static void c2_eml_xswap(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_b_x[256], int32_T c2_ix0, int32_T c2_iy0, real_T c2_c_x[256]);
static void c2_b_eml_switch_helper(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c2_eml_xgeru(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_A[256], int32_T c2_ia0, real_T c2_b_A[256]);
static void c2_c_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_eml_warning(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_A[256], real_T c2_b_B[80], real_T c2_c_B[80]);
static void c2_below_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_c_eml_switch_helper(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static real_T c2_rdivide(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_b_x, real_T c2_y);
static void c2_b_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[80], real_T c2_c_B[80]);
static void c2_e_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_b_mrdivide(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[80], real_T c2_b_B[25], real_T c2_y[80]);
static void c2_b_eml_matlab_zgetrf(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c2_A[25], real_T c2_b_A[25], int32_T c2_ipiv[5],
  int32_T *c2_info);
static void c2_b_eml_xgeru(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_A[25], int32_T c2_ia0, real_T c2_b_A[25]);
static void c2_c_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[25], real_T c2_b_B[80], real_T c2_c_B[80]);
static void c2_b_below_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_scalarEg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_d_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[25], real_T c2_b_B[80], real_T c2_c_B[80]);
static void c2_eye(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c2_I
                   [256]);
static void c2_f_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_eml_xgemm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_A[80], real_T c2_b_B[80], real_T c2_C[256], real_T c2_b_C[256]);
static void c2_g_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_h_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_c_mrdivide(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[48], real_T c2_b_B[256], real_T c2_y[48]);
static void c2_b_eml_lusolve(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[48], real_T c2_X[48]);
static void c2_e_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[48], real_T c2_c_B[48]);
static void c2_c_below_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_f_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[48], real_T c2_c_B[48]);
static void c2_i_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_d_mrdivide(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[48], real_T c2_b_B[9], real_T c2_y[48]);
static void c2_c_eml_lusolve(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[9], real_T c2_b_B[48], real_T c2_X[48]);
static void c2_b_eye(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
                     c2_I[256]);
static void c2_j_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_b_eml_xgemm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[48], real_T c2_b_B[48], real_T c2_C[256], real_T c2_b_C[256]);
static void c2_k_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_mldivide(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_A[256], real_T c2_b_B[16], real_T c2_Y[16]);
static void c2_g_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[16], real_T c2_c_B[16]);
static void c2_d_below_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_b_scalarEg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c2_h_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[16], real_T c2_c_B[16]);
static const mxArray *c2_n_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData);
static int32_T c2_m_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData);
static uint8_T c2_n_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_DDA2D_OSU3Dv2, const char_T
  *c2_identifier);
static uint8_T c2_o_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId);
static void c2_c_eml_matlab_zgetrf(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c2_A[256], int32_T c2_ipiv[16], int32_T *c2_info);
static void c2_b_eml_xswap(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_b_x[256], int32_T c2_ix0, int32_T c2_iy0);
static void c2_c_eml_xgeru(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_A[256], int32_T c2_ia0);
static void c2_i_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[80]);
static void c2_j_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[80]);
static void c2_d_eml_matlab_zgetrf(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c2_A[25], int32_T c2_ipiv[5], int32_T *c2_info);
static void c2_d_eml_xgeru(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_A[25], int32_T c2_ia0);
static void c2_k_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[25], real_T c2_b_B[80]);
static void c2_l_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[25], real_T c2_b_B[80]);
static void c2_c_eml_xgemm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[80], real_T c2_b_B[80], real_T c2_C[256]);
static void c2_m_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[48]);
static void c2_n_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[48]);
static void c2_d_eml_xgemm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[48], real_T c2_b_B[48], real_T c2_C[256]);
static void c2_o_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[16]);
static void c2_p_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[16]);
static void init_dsm_address_info(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c2_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c2_is_active_c2_DDA2D_OSU3Dv2 = 0U;
}

static void initialize_params_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct *
  chartInstance)
{
  real_T c2_d0;
  real_T c2_d1;
  real_T c2_d2;
  real_T c2_dv0[3];
  int32_T c2_i0;
  real_T c2_dv1[3];
  int32_T c2_i1;
  sf_mex_import_named("spring_k", sf_mex_get_sfun_param(chartInstance->S, 3, 0),
                      &c2_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_spring_k = c2_d0;
  sf_mex_import_named("spring_zeta", sf_mex_get_sfun_param(chartInstance->S, 4,
    0), &c2_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_spring_zeta = c2_d1;
  sf_mex_import_named("ProjectTo2D", sf_mex_get_sfun_param(chartInstance->S, 1,
    0), &c2_d2, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c2_ProjectTo2D = c2_d2;
  sf_mex_import_named("BoomParams", sf_mex_get_sfun_param(chartInstance->S, 0, 0),
                      c2_dv0, 0, 0, 0U, 1, 0U, 2, 3, 1);
  for (c2_i0 = 0; c2_i0 < 3; c2_i0++) {
    chartInstance->c2_BoomParams[c2_i0] = c2_dv0[c2_i0];
  }

  sf_mex_import_named("pBInitial", sf_mex_get_sfun_param(chartInstance->S, 2, 0),
                      c2_dv1, 0, 0, 0U, 1, 0U, 2, 3, 1);
  for (c2_i1 = 0; c2_i1 < 3; c2_i1++) {
    chartInstance->c2_pBInitial[c2_i1] = c2_dv1[c2_i1];
  }
}

static void enable_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c2_update_debugger_state_c2_DDA2D_OSU3Dv2
  (SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c2_DDA2D_OSU3Dv2
  (SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  const mxArray *c2_st;
  const mxArray *c2_y = NULL;
  int32_T c2_i2;
  real_T c2_b_u[32];
  const mxArray *c2_b_y = NULL;
  uint8_T c2_hoistedGlobal;
  uint8_T c2_c_u;
  const mxArray *c2_c_y = NULL;
  c2_st = NULL;
  c2_st = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_createcellmatrix(2, 1), false);
  for (c2_i2 = 0; c2_i2 < 32; c2_i2++) {
    c2_b_u[c2_i2] = (*chartInstance->c2_x_dot)[c2_i2];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_setcell(c2_y, 0, c2_b_y);
  c2_hoistedGlobal = chartInstance->c2_is_active_c2_DDA2D_OSU3Dv2;
  c2_c_u = c2_hoistedGlobal;
  c2_c_y = NULL;
  sf_mex_assign(&c2_c_y, sf_mex_create("y", &c2_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c2_y, 1, c2_c_y);
  sf_mex_assign(&c2_st, c2_y, false);
  return c2_st;
}

static void set_sim_state_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_st)
{
  const mxArray *c2_b_u;
  real_T c2_dv2[32];
  int32_T c2_i3;
  chartInstance->c2_doneDoubleBufferReInit = true;
  c2_b_u = sf_mex_dup(c2_st);
  c2_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c2_b_u, 0)),
                      "x_dot", c2_dv2);
  for (c2_i3 = 0; c2_i3 < 32; c2_i3++) {
    (*chartInstance->c2_x_dot)[c2_i3] = c2_dv2[c2_i3];
  }

  chartInstance->c2_is_active_c2_DDA2D_OSU3Dv2 = c2_n_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c2_b_u, 1)),
     "is_active_c2_DDA2D_OSU3Dv2");
  sf_mex_destroy(&c2_b_u);
  c2_update_debugger_state_c2_DDA2D_OSU3Dv2(chartInstance);
  sf_mex_destroy(&c2_st);
}

static void finalize_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  int32_T c2_i4;
  int32_T c2_i5;
  int32_T c2_i6;
  int32_T c2_i7;
  int32_T c2_i8;
  int32_T c2_i9;
  int32_T c2_i10;
  int32_T c2_i11;
  int32_T c2_i12;
  int32_T c2_i13;
  int32_T c2_i14;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  for (c2_i4 = 0; c2_i4 < 32; c2_i4++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_x)[c2_i4], 0U);
  }

  for (c2_i5 = 0; c2_i5 < 6; c2_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_u)[c2_i5], 1U);
  }

  for (c2_i6 = 0; c2_i6 < 256; c2_i6++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_D)[c2_i6], 2U);
  }

  for (c2_i7 = 0; c2_i7 < 16; c2_i7++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_Cdq)[c2_i7], 3U);
  }

  for (c2_i8 = 0; c2_i8 < 16; c2_i8++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_G)[c2_i8], 4U);
  }

  for (c2_i9 = 0; c2_i9 < 96; c2_i9++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_B)[c2_i9], 5U);
  }

  for (c2_i10 = 0; c2_i10 < 16; c2_i10++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_FGround)[c2_i10], 6U);
  }

  for (c2_i11 = 0; c2_i11 < 6; c2_i11++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_Fstiction)[c2_i11], 7U);
  }

  chartInstance->c2_sfEvent = CALL_EVENT;
  c2_chartstep_c2_DDA2D_OSU3Dv2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DDA2D_OSU3Dv2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c2_i12 = 0; c2_i12 < 32; c2_i12++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c2_x_dot)[c2_i12], 8U);
  }

  _SFD_DATA_RANGE_CHECK(chartInstance->c2_spring_k, 9U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_spring_zeta, 10U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c2_ProjectTo2D, 11U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_ExternalHipForce, 12U);
  for (c2_i13 = 0; c2_i13 < 3; c2_i13++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c2_BoomParams[c2_i13], 13U);
  }

  for (c2_i14 = 0; c2_i14 < 3; c2_i14++) {
    _SFD_DATA_RANGE_CHECK(chartInstance->c2_pBInitial[c2_i14], 14U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c2_Ttime, 15U);
}

static void mdl_start_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_chartstep_c2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  real_T c2_hoistedGlobal;
  real_T c2_b_hoistedGlobal;
  real_T c2_c_hoistedGlobal;
  real_T c2_d_hoistedGlobal;
  real_T c2_e_hoistedGlobal;
  int32_T c2_i15;
  real_T c2_b_x[32];
  int32_T c2_i16;
  real_T c2_b_u[6];
  int32_T c2_i17;
  real_T c2_b_D[256];
  int32_T c2_i18;
  real_T c2_b_Cdq[16];
  int32_T c2_i19;
  real_T c2_b_G[16];
  int32_T c2_i20;
  real_T c2_b_B[96];
  int32_T c2_i21;
  real_T c2_b_FGround[16];
  int32_T c2_i22;
  real_T c2_b_Fstiction[6];
  real_T c2_b_spring_k;
  real_T c2_b_spring_zeta;
  real_T c2_b_ProjectTo2D;
  real_T c2_b_ExternalHipForce;
  int32_T c2_i23;
  real_T c2_b_BoomParams[3];
  int32_T c2_i24;
  real_T c2_b_pBInitial[3];
  real_T c2_b_Ttime;
  uint32_T c2_debug_family_var_map[43];
  real_T c2_q[16];
  real_T c2_dq[16];
  real_T c2_K_spring[256];
  real_T c2_K_damping[256];
  real_T c2_FSpring[16];
  real_T c2_H[16];
  real_T c2_kpboom;
  real_T c2_kdboom;
  real_T c2_C[80];
  real_T c2_alpha;
  real_T c2_KP;
  real_T c2_KD;
  real_T c2_v_con[3];
  real_T c2_CDinv[80];
  real_T c2_CinvCDinvC[80];
  real_T c2_proj[256];
  real_T c2_JBoom[48];
  real_T c2_dJBoom[3];
  real_T c2_pB[3];
  real_T c2_vB[3];
  real_T c2_eB[3];
  real_T c2_JBoom_D[48];
  real_T c2_A[48];
  real_T c2_P[256];
  real_T c2_ddq[16];
  real_T c2_b_v_con[5];
  real_T c2_nargin = 15.0;
  real_T c2_nargout = 1.0;
  real_T c2_b_x_dot[32];
  int32_T c2_i25;
  int32_T c2_i26;
  real_T c2_b_K_damping[256];
  real_T c2_b_K_spring[256];
  int32_T c2_i27;
  int32_T c2_i28;
  int32_T c2_i29;
  int32_T c2_i30;
  real_T c2_b[16];
  int32_T c2_i31;
  real_T c2_y[16];
  int32_T c2_i32;
  int32_T c2_i33;
  int32_T c2_i34;
  int32_T c2_i35;
  int32_T c2_i36;
  real_T c2_b_y[16];
  int32_T c2_i37;
  int32_T c2_i38;
  int32_T c2_i39;
  int32_T c2_i40;
  real_T c2_a[96];
  int32_T c2_i41;
  real_T c2_b_b[6];
  int32_T c2_i42;
  int32_T c2_i43;
  int32_T c2_i44;
  int32_T c2_i45;
  int32_T c2_i46;
  int32_T c2_i47;
  real_T c2_c_b[80];
  int32_T c2_i48;
  int32_T c2_i49;
  int32_T c2_i50;
  real_T c2_c_y[5];
  int32_T c2_i51;
  int32_T c2_i52;
  int32_T c2_i53;
  int32_T c2_i54;
  int32_T c2_i55;
  int32_T c2_i56;
  real_T c2_d_y[5];
  int32_T c2_i57;
  int32_T c2_i58;
  int32_T c2_i59;
  int32_T c2_i60;
  real_T c2_b_C[80];
  int32_T c2_i61;
  real_T c2_c_D[256];
  real_T c2_dv3[80];
  int32_T c2_i62;
  int32_T c2_i63;
  int32_T c2_i64;
  int32_T c2_i65;
  int32_T c2_i66;
  int32_T c2_i67;
  real_T c2_d_b[80];
  int32_T c2_i68;
  int32_T c2_i69;
  int32_T c2_i70;
  int32_T c2_i71;
  real_T c2_e_y[25];
  int32_T c2_i72;
  int32_T c2_i73;
  int32_T c2_i74;
  int32_T c2_i75;
  int32_T c2_i76;
  int32_T c2_i77;
  real_T c2_c_C[80];
  int32_T c2_i78;
  real_T c2_f_y[25];
  real_T c2_dv4[80];
  int32_T c2_i79;
  int32_T c2_i80;
  int32_T c2_i81;
  int32_T c2_i82;
  int32_T c2_i83;
  real_T c2_e_b[80];
  int32_T c2_i84;
  real_T c2_f_b[80];
  int32_T c2_i85;
  int32_T c2_i86;
  int32_T c2_i87;
  int32_T c2_i88;
  int32_T c2_i89;
  int32_T c2_i90;
  int32_T c2_i91;
  int32_T c2_i92;
  int32_T c2_i93;
  int32_T c2_i94;
  int32_T c2_i95;
  int32_T c2_i96;
  int32_T c2_i97;
  real_T c2_b_q[16];
  int32_T c2_i98;
  real_T c2_b_dq[16];
  int32_T c2_i99;
  real_T c2_c_BoomParams[3];
  real_T c2_b_dJBoom[3];
  real_T c2_b_JBoom[48];
  int32_T c2_i100;
  int32_T c2_i101;
  int32_T c2_i102;
  real_T c2_c_q[16];
  int32_T c2_i103;
  real_T c2_d_BoomParams[3];
  real_T c2_dv5[3];
  int32_T c2_i104;
  int32_T c2_i105;
  int32_T c2_i106;
  int32_T c2_i107;
  int32_T c2_i108;
  int32_T c2_i109;
  int32_T c2_i110;
  int32_T c2_i111;
  int32_T c2_i112;
  int32_T c2_i113;
  int32_T c2_i114;
  int32_T c2_i115;
  int32_T c2_i116;
  int32_T c2_i117;
  int32_T c2_i118;
  int32_T c2_i119;
  real_T c2_g_b[3];
  int32_T c2_i120;
  int32_T c2_i121;
  int32_T c2_i122;
  real_T c2_c_JBoom[48];
  int32_T c2_i123;
  real_T c2_d_D[256];
  real_T c2_dv6[48];
  int32_T c2_i124;
  int32_T c2_i125;
  int32_T c2_i126;
  int32_T c2_i127;
  int32_T c2_i128;
  int32_T c2_i129;
  real_T c2_h_b[48];
  int32_T c2_i130;
  int32_T c2_i131;
  int32_T c2_i132;
  int32_T c2_i133;
  real_T c2_g_y[9];
  int32_T c2_i134;
  int32_T c2_i135;
  int32_T c2_i136;
  int32_T c2_i137;
  int32_T c2_i138;
  int32_T c2_i139;
  real_T c2_d_JBoom[48];
  int32_T c2_i140;
  real_T c2_h_y[9];
  real_T c2_dv7[48];
  int32_T c2_i141;
  int32_T c2_i142;
  int32_T c2_i143;
  int32_T c2_i144;
  int32_T c2_i145;
  real_T c2_i_b[48];
  int32_T c2_i146;
  real_T c2_e_JBoom[48];
  int32_T c2_i147;
  int32_T c2_i148;
  int32_T c2_i149;
  int32_T c2_i150;
  int32_T c2_i151;
  int32_T c2_i152;
  int32_T c2_i153;
  int32_T c2_i154;
  int32_T c2_i155;
  int32_T c2_i156;
  int32_T c2_i157;
  int32_T c2_i158;
  int32_T c2_i159;
  real_T c2_e_D[256];
  int32_T c2_i160;
  real_T c2_b_H[16];
  real_T c2_dv8[16];
  int32_T c2_i161;
  int32_T c2_i162;
  int32_T c2_i163;
  int32_T c2_i164;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
  c2_hoistedGlobal = chartInstance->c2_spring_k;
  c2_b_hoistedGlobal = chartInstance->c2_spring_zeta;
  c2_c_hoistedGlobal = chartInstance->c2_ProjectTo2D;
  c2_d_hoistedGlobal = *chartInstance->c2_ExternalHipForce;
  c2_e_hoistedGlobal = *chartInstance->c2_Ttime;
  for (c2_i15 = 0; c2_i15 < 32; c2_i15++) {
    c2_b_x[c2_i15] = (*chartInstance->c2_x)[c2_i15];
  }

  for (c2_i16 = 0; c2_i16 < 6; c2_i16++) {
    c2_b_u[c2_i16] = (*chartInstance->c2_u)[c2_i16];
  }

  for (c2_i17 = 0; c2_i17 < 256; c2_i17++) {
    c2_b_D[c2_i17] = (*chartInstance->c2_D)[c2_i17];
  }

  for (c2_i18 = 0; c2_i18 < 16; c2_i18++) {
    c2_b_Cdq[c2_i18] = (*chartInstance->c2_Cdq)[c2_i18];
  }

  for (c2_i19 = 0; c2_i19 < 16; c2_i19++) {
    c2_b_G[c2_i19] = (*chartInstance->c2_G)[c2_i19];
  }

  for (c2_i20 = 0; c2_i20 < 96; c2_i20++) {
    c2_b_B[c2_i20] = (*chartInstance->c2_B)[c2_i20];
  }

  for (c2_i21 = 0; c2_i21 < 16; c2_i21++) {
    c2_b_FGround[c2_i21] = (*chartInstance->c2_FGround)[c2_i21];
  }

  for (c2_i22 = 0; c2_i22 < 6; c2_i22++) {
    c2_b_Fstiction[c2_i22] = (*chartInstance->c2_Fstiction)[c2_i22];
  }

  c2_b_spring_k = c2_hoistedGlobal;
  c2_b_spring_zeta = c2_b_hoistedGlobal;
  c2_b_ProjectTo2D = c2_c_hoistedGlobal;
  c2_b_ExternalHipForce = c2_d_hoistedGlobal;
  for (c2_i23 = 0; c2_i23 < 3; c2_i23++) {
    c2_b_BoomParams[c2_i23] = chartInstance->c2_BoomParams[c2_i23];
  }

  for (c2_i24 = 0; c2_i24 < 3; c2_i24++) {
    c2_b_pBInitial[c2_i24] = chartInstance->c2_pBInitial[c2_i24];
  }

  c2_b_Ttime = c2_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 43U, 44U, c2_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_q, 0U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_dq, 1U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_K_spring, 2U, c2_g_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_K_damping, 3U, c2_g_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_FSpring, 4U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_H, 5U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_kpboom, 6U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_kdboom, 7U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_C, 8U, c2_m_sf_marshallOut,
    c2_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_alpha, 9U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_KP, 10U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_KD, 11U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_v_con, MAX_uint32_T,
    c2_k_sf_marshallOut, c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_CDinv, 13U, c2_m_sf_marshallOut,
    c2_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_CinvCDinvC, 14U, c2_l_sf_marshallOut,
    c2_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_proj, 15U, c2_g_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_JBoom, 16U, c2_j_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_dJBoom, 17U, c2_k_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_pB, 18U, c2_k_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_vB, 19U, c2_k_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_eB, 20U, c2_k_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_JBoom_D, 21U, c2_j_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_A, 22U, c2_i_sf_marshallOut,
    c2_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_P, 23U, c2_g_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_ddq, 24U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_v_con, MAX_uint32_T,
    c2_h_sf_marshallOut, c2_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 25U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 26U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_x, 27U, c2_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_u, 28U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_D, 29U, c2_g_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_Cdq, 30U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_G, 31U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_B, 32U, c2_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_FGround, 33U, c2_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c2_b_Fstiction, 34U, c2_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_spring_k, 35U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_spring_zeta, 36U,
    c2_b_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_b_ProjectTo2D, 37U,
    c2_b_sf_marshallOut, c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_ExternalHipForce, 38U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_BoomParams, 39U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_pBInitial, 40U, c2_c_sf_marshallOut,
    c2_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c2_b_Ttime, 41U, c2_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_x_dot, 42U, c2_sf_marshallOut,
    c2_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 4);
  for (c2_i25 = 0; c2_i25 < 16; c2_i25++) {
    c2_q[c2_i25] = c2_b_x[c2_i25];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 5);
  for (c2_i26 = 0; c2_i26 < 16; c2_i26++) {
    c2_dq[c2_i26] = c2_b_x[c2_i26 + 16];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_ATRIAS3D_Spring_Constants(chartInstance, c2_b_spring_k, c2_b_spring_zeta,
    c2_b_K_spring, c2_b_K_damping);
  for (c2_i27 = 0; c2_i27 < 256; c2_i27++) {
    c2_K_spring[c2_i27] = c2_b_K_spring[c2_i27];
  }

  for (c2_i28 = 0; c2_i28 < 256; c2_i28++) {
    c2_K_damping[c2_i28] = c2_b_K_damping[c2_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 12);
  for (c2_i29 = 0; c2_i29 < 256; c2_i29++) {
    c2_b_K_spring[c2_i29] = c2_K_spring[c2_i29];
  }

  for (c2_i30 = 0; c2_i30 < 16; c2_i30++) {
    c2_b[c2_i30] = c2_q[c2_i30];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  c2_threshold(chartInstance);
  for (c2_i31 = 0; c2_i31 < 16; c2_i31++) {
    c2_y[c2_i31] = 0.0;
    c2_i32 = 0;
    for (c2_i33 = 0; c2_i33 < 16; c2_i33++) {
      c2_y[c2_i31] += c2_b_K_spring[c2_i32 + c2_i31] * c2_b[c2_i33];
      c2_i32 += 16;
    }
  }

  for (c2_i34 = 0; c2_i34 < 256; c2_i34++) {
    c2_b_K_spring[c2_i34] = c2_K_damping[c2_i34];
  }

  for (c2_i35 = 0; c2_i35 < 16; c2_i35++) {
    c2_b[c2_i35] = c2_dq[c2_i35];
  }

  c2_eml_scalar_eg(chartInstance);
  c2_eml_scalar_eg(chartInstance);
  c2_threshold(chartInstance);
  for (c2_i36 = 0; c2_i36 < 16; c2_i36++) {
    c2_b_y[c2_i36] = 0.0;
    c2_i37 = 0;
    for (c2_i38 = 0; c2_i38 < 16; c2_i38++) {
      c2_b_y[c2_i36] += c2_b_K_spring[c2_i37 + c2_i36] * c2_b[c2_i38];
      c2_i37 += 16;
    }
  }

  for (c2_i39 = 0; c2_i39 < 16; c2_i39++) {
    c2_FSpring[c2_i39] = c2_y[c2_i39] + c2_b_y[c2_i39];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 15);
  for (c2_i40 = 0; c2_i40 < 96; c2_i40++) {
    c2_a[c2_i40] = c2_b_B[c2_i40];
  }

  for (c2_i41 = 0; c2_i41 < 6; c2_i41++) {
    c2_b_b[c2_i41] = c2_b_u[c2_i41] - c2_b_Fstiction[c2_i41];
  }

  c2_b_eml_scalar_eg(chartInstance);
  c2_b_eml_scalar_eg(chartInstance);
  c2_threshold(chartInstance);
  for (c2_i42 = 0; c2_i42 < 16; c2_i42++) {
    c2_y[c2_i42] = 0.0;
    c2_i43 = 0;
    for (c2_i44 = 0; c2_i44 < 6; c2_i44++) {
      c2_y[c2_i42] += c2_a[c2_i43 + c2_i42] * c2_b_b[c2_i44];
      c2_i43 += 16;
    }
  }

  for (c2_i45 = 0; c2_i45 < 16; c2_i45++) {
    c2_H[c2_i45] = (((c2_b_Cdq[c2_i45] + c2_b_G[c2_i45]) + c2_FSpring[c2_i45]) -
                    c2_b_FGround[c2_i45]) - c2_y[c2_i45];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 18);
  c2_H[1] += c2_b_ExternalHipForce;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_kpboom = 10000.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_kdboom = 1000.0;
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 23);
  CV_EML_IF(0, 1, 0, true);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_H[3] = (c2_H[3] + 10000.0 * c2_q[3]) + 1000.0 * c2_dq[3];
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 28);
  CV_EML_IF(0, 1, 1, false);
  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 40);
  if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 0, c2_b_ProjectTo2D, 1.0, -1,
        0U, c2_b_ProjectTo2D == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 41);
    for (c2_i46 = 0; c2_i46 < 80; c2_i46++) {
      c2_C[c2_i46] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 42);
    c2_C[0] = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 43);
    c2_C[16] = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 44);
    c2_C[22] = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 45);
    c2_C[63] = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 46);
    c2_C[79] = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 47);
    c2_alpha = 100.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 48);
    c2_KP = 10000.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 49);
    c2_KD = 200.0;
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 50);
    for (c2_i47 = 0; c2_i47 < 80; c2_i47++) {
      c2_c_b[c2_i47] = c2_C[c2_i47];
    }

    for (c2_i48 = 0; c2_i48 < 80; c2_i48++) {
      c2_c_b[c2_i48] *= -10000.0;
    }

    for (c2_i49 = 0; c2_i49 < 16; c2_i49++) {
      c2_b[c2_i49] = c2_q[c2_i49];
    }

    c2_d_eml_scalar_eg(chartInstance);
    c2_d_eml_scalar_eg(chartInstance);
    c2_threshold(chartInstance);
    for (c2_i50 = 0; c2_i50 < 5; c2_i50++) {
      c2_c_y[c2_i50] = 0.0;
      c2_i51 = 0;
      for (c2_i52 = 0; c2_i52 < 16; c2_i52++) {
        c2_c_y[c2_i50] += c2_c_b[c2_i51 + c2_i50] * c2_b[c2_i52];
        c2_i51 += 5;
      }
    }

    for (c2_i53 = 0; c2_i53 < 80; c2_i53++) {
      c2_c_b[c2_i53] = c2_C[c2_i53];
    }

    for (c2_i54 = 0; c2_i54 < 80; c2_i54++) {
      c2_c_b[c2_i54] *= 200.0;
    }

    for (c2_i55 = 0; c2_i55 < 16; c2_i55++) {
      c2_b[c2_i55] = c2_dq[c2_i55];
    }

    c2_d_eml_scalar_eg(chartInstance);
    c2_d_eml_scalar_eg(chartInstance);
    c2_threshold(chartInstance);
    for (c2_i56 = 0; c2_i56 < 5; c2_i56++) {
      c2_d_y[c2_i56] = 0.0;
      c2_i57 = 0;
      for (c2_i58 = 0; c2_i58 < 16; c2_i58++) {
        c2_d_y[c2_i56] += c2_c_b[c2_i57 + c2_i56] * c2_b[c2_i58];
        c2_i57 += 5;
      }
    }

    for (c2_i59 = 0; c2_i59 < 5; c2_i59++) {
      c2_b_v_con[c2_i59] = c2_c_y[c2_i59] - c2_d_y[c2_i59];
    }

    _SFD_SYMBOL_SWITCH(12U, 25U);
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 53);
    for (c2_i60 = 0; c2_i60 < 80; c2_i60++) {
      c2_b_C[c2_i60] = c2_C[c2_i60];
    }

    for (c2_i61 = 0; c2_i61 < 256; c2_i61++) {
      c2_c_D[c2_i61] = c2_b_D[c2_i61];
    }

    c2_mrdivide(chartInstance, c2_b_C, c2_c_D, c2_dv3);
    for (c2_i62 = 0; c2_i62 < 80; c2_i62++) {
      c2_CDinv[c2_i62] = c2_dv3[c2_i62];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 54);
    for (c2_i63 = 0; c2_i63 < 80; c2_i63++) {
      c2_c_b[c2_i63] = c2_CDinv[c2_i63];
    }

    c2_i64 = 0;
    for (c2_i65 = 0; c2_i65 < 5; c2_i65++) {
      c2_i66 = 0;
      for (c2_i67 = 0; c2_i67 < 16; c2_i67++) {
        c2_d_b[c2_i67 + c2_i64] = c2_C[c2_i66 + c2_i65];
        c2_i66 += 5;
      }

      c2_i64 += 16;
    }

    c2_e_eml_scalar_eg(chartInstance);
    c2_e_eml_scalar_eg(chartInstance);
    c2_threshold(chartInstance);
    for (c2_i68 = 0; c2_i68 < 5; c2_i68++) {
      c2_i69 = 0;
      c2_i70 = 0;
      for (c2_i71 = 0; c2_i71 < 5; c2_i71++) {
        c2_e_y[c2_i69 + c2_i68] = 0.0;
        c2_i72 = 0;
        for (c2_i73 = 0; c2_i73 < 16; c2_i73++) {
          c2_e_y[c2_i69 + c2_i68] += c2_c_b[c2_i72 + c2_i68] * c2_d_b[c2_i73 +
            c2_i70];
          c2_i72 += 5;
        }

        c2_i69 += 5;
        c2_i70 += 16;
      }
    }

    c2_i74 = 0;
    for (c2_i75 = 0; c2_i75 < 5; c2_i75++) {
      c2_i76 = 0;
      for (c2_i77 = 0; c2_i77 < 16; c2_i77++) {
        c2_c_C[c2_i77 + c2_i74] = c2_C[c2_i76 + c2_i75];
        c2_i76 += 5;
      }

      c2_i74 += 16;
    }

    for (c2_i78 = 0; c2_i78 < 25; c2_i78++) {
      c2_f_y[c2_i78] = c2_e_y[c2_i78];
    }

    c2_b_mrdivide(chartInstance, c2_c_C, c2_f_y, c2_dv4);
    for (c2_i79 = 0; c2_i79 < 80; c2_i79++) {
      c2_CinvCDinvC[c2_i79] = c2_dv4[c2_i79];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 55);
    for (c2_i80 = 0; c2_i80 < 80; c2_i80++) {
      c2_d_b[c2_i80] = c2_CinvCDinvC[c2_i80];
    }

    for (c2_i81 = 0; c2_i81 < 80; c2_i81++) {
      c2_c_b[c2_i81] = c2_CDinv[c2_i81];
    }

    c2_f_eml_scalar_eg(chartInstance);
    c2_f_eml_scalar_eg(chartInstance);
    for (c2_i82 = 0; c2_i82 < 256; c2_i82++) {
      c2_b_K_spring[c2_i82] = 0.0;
    }

    for (c2_i83 = 0; c2_i83 < 80; c2_i83++) {
      c2_e_b[c2_i83] = c2_d_b[c2_i83];
    }

    for (c2_i84 = 0; c2_i84 < 80; c2_i84++) {
      c2_f_b[c2_i84] = c2_c_b[c2_i84];
    }

    c2_c_eml_xgemm(chartInstance, c2_e_b, c2_f_b, c2_b_K_spring);
    c2_eye(chartInstance, c2_b_K_damping);
    for (c2_i85 = 0; c2_i85 < 256; c2_i85++) {
      c2_proj[c2_i85] = c2_b_K_damping[c2_i85] - c2_b_K_spring[c2_i85];
    }

    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 56);
    for (c2_i86 = 0; c2_i86 < 256; c2_i86++) {
      c2_b_K_spring[c2_i86] = c2_proj[c2_i86];
    }

    for (c2_i87 = 0; c2_i87 < 16; c2_i87++) {
      c2_b[c2_i87] = c2_H[c2_i87];
    }

    c2_eml_scalar_eg(chartInstance);
    c2_eml_scalar_eg(chartInstance);
    c2_threshold(chartInstance);
    for (c2_i88 = 0; c2_i88 < 16; c2_i88++) {
      c2_y[c2_i88] = 0.0;
      c2_i89 = 0;
      for (c2_i90 = 0; c2_i90 < 16; c2_i90++) {
        c2_y[c2_i88] += c2_b_K_spring[c2_i89 + c2_i88] * c2_b[c2_i90];
        c2_i89 += 16;
      }
    }

    for (c2_i91 = 0; c2_i91 < 80; c2_i91++) {
      c2_d_b[c2_i91] = c2_CinvCDinvC[c2_i91];
    }

    for (c2_i92 = 0; c2_i92 < 5; c2_i92++) {
      c2_c_y[c2_i92] = c2_b_v_con[c2_i92];
    }

    c2_g_eml_scalar_eg(chartInstance);
    c2_g_eml_scalar_eg(chartInstance);
    c2_threshold(chartInstance);
    for (c2_i93 = 0; c2_i93 < 16; c2_i93++) {
      c2_b_y[c2_i93] = 0.0;
      c2_i94 = 0;
      for (c2_i95 = 0; c2_i95 < 5; c2_i95++) {
        c2_b_y[c2_i93] += c2_d_b[c2_i94 + c2_i93] * c2_c_y[c2_i95];
        c2_i94 += 16;
      }
    }

    for (c2_i96 = 0; c2_i96 < 16; c2_i96++) {
      c2_H[c2_i96] = c2_y[c2_i96] - c2_b_y[c2_i96];
    }
  } else {
    _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 57);
    if (CV_EML_IF(0, 1, 3, CV_RELATIONAL_EVAL(4U, 0U, 1, c2_b_ProjectTo2D, 2.0,
          -1, 0U, c2_b_ProjectTo2D == 2.0))) {
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 59);
      for (c2_i97 = 0; c2_i97 < 16; c2_i97++) {
        c2_b_q[c2_i97] = c2_q[c2_i97];
      }

      for (c2_i98 = 0; c2_i98 < 16; c2_i98++) {
        c2_b_dq[c2_i98] = c2_dq[c2_i98];
      }

      for (c2_i99 = 0; c2_i99 < 3; c2_i99++) {
        c2_c_BoomParams[c2_i99] = c2_b_BoomParams[c2_i99];
      }

      c2_JacobBoomHip_FixParams(chartInstance, c2_b_q, c2_b_dq, c2_c_BoomParams,
        c2_b_JBoom, c2_b_dJBoom);
      for (c2_i100 = 0; c2_i100 < 48; c2_i100++) {
        c2_JBoom[c2_i100] = c2_b_JBoom[c2_i100];
      }

      for (c2_i101 = 0; c2_i101 < 3; c2_i101++) {
        c2_dJBoom[c2_i101] = c2_b_dJBoom[c2_i101];
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 60);
      for (c2_i102 = 0; c2_i102 < 16; c2_i102++) {
        c2_c_q[c2_i102] = c2_q[c2_i102];
      }

      for (c2_i103 = 0; c2_i103 < 3; c2_i103++) {
        c2_d_BoomParams[c2_i103] = c2_b_BoomParams[c2_i103];
      }

      c2_BoomPositionHip_FixParams(chartInstance, c2_c_q, c2_d_BoomParams,
        c2_dv5);
      for (c2_i104 = 0; c2_i104 < 3; c2_i104++) {
        c2_pB[c2_i104] = c2_dv5[c2_i104];
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 61);
      for (c2_i105 = 0; c2_i105 < 48; c2_i105++) {
        c2_b_JBoom[c2_i105] = c2_JBoom[c2_i105];
      }

      for (c2_i106 = 0; c2_i106 < 16; c2_i106++) {
        c2_b[c2_i106] = c2_dq[c2_i106];
      }

      c2_h_eml_scalar_eg(chartInstance);
      c2_h_eml_scalar_eg(chartInstance);
      for (c2_i107 = 0; c2_i107 < 3; c2_i107++) {
        c2_vB[c2_i107] = 0.0;
      }

      for (c2_i108 = 0; c2_i108 < 3; c2_i108++) {
        c2_vB[c2_i108] = 0.0;
      }

      for (c2_i109 = 0; c2_i109 < 3; c2_i109++) {
        c2_b_dJBoom[c2_i109] = c2_vB[c2_i109];
      }

      for (c2_i110 = 0; c2_i110 < 3; c2_i110++) {
        c2_vB[c2_i110] = c2_b_dJBoom[c2_i110];
      }

      c2_threshold(chartInstance);
      for (c2_i111 = 0; c2_i111 < 3; c2_i111++) {
        c2_b_dJBoom[c2_i111] = c2_vB[c2_i111];
      }

      for (c2_i112 = 0; c2_i112 < 3; c2_i112++) {
        c2_vB[c2_i112] = c2_b_dJBoom[c2_i112];
      }

      for (c2_i113 = 0; c2_i113 < 3; c2_i113++) {
        c2_vB[c2_i113] = 0.0;
        c2_i114 = 0;
        for (c2_i115 = 0; c2_i115 < 16; c2_i115++) {
          c2_vB[c2_i113] += c2_b_JBoom[c2_i114 + c2_i113] * c2_b[c2_i115];
          c2_i114 += 3;
        }
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 62);
      for (c2_i116 = 0; c2_i116 < 3; c2_i116++) {
        c2_eB[c2_i116] = c2_pB[c2_i116] - c2_b_pBInitial[c2_i116];
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 64);
      c2_alpha = 100.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 65);
      c2_KP = 10000.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 66);
      c2_KD = 200.0;
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 67);
      for (c2_i117 = 0; c2_i117 < 3; c2_i117++) {
        c2_b_dJBoom[c2_i117] = c2_eB[c2_i117];
      }

      for (c2_i118 = 0; c2_i118 < 3; c2_i118++) {
        c2_b_dJBoom[c2_i118] *= -10000.0;
      }

      for (c2_i119 = 0; c2_i119 < 3; c2_i119++) {
        c2_g_b[c2_i119] = c2_vB[c2_i119];
      }

      for (c2_i120 = 0; c2_i120 < 3; c2_i120++) {
        c2_g_b[c2_i120] *= 200.0;
      }

      for (c2_i121 = 0; c2_i121 < 3; c2_i121++) {
        c2_v_con[c2_i121] = c2_b_dJBoom[c2_i121] - c2_g_b[c2_i121];
      }

      _SFD_SYMBOL_SWITCH(12U, 12U);
      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 69);
      for (c2_i122 = 0; c2_i122 < 48; c2_i122++) {
        c2_c_JBoom[c2_i122] = c2_JBoom[c2_i122];
      }

      for (c2_i123 = 0; c2_i123 < 256; c2_i123++) {
        c2_d_D[c2_i123] = c2_b_D[c2_i123];
      }

      c2_c_mrdivide(chartInstance, c2_c_JBoom, c2_d_D, c2_dv6);
      for (c2_i124 = 0; c2_i124 < 48; c2_i124++) {
        c2_JBoom_D[c2_i124] = c2_dv6[c2_i124];
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 70);
      for (c2_i125 = 0; c2_i125 < 48; c2_i125++) {
        c2_b_JBoom[c2_i125] = c2_JBoom_D[c2_i125];
      }

      c2_i126 = 0;
      for (c2_i127 = 0; c2_i127 < 3; c2_i127++) {
        c2_i128 = 0;
        for (c2_i129 = 0; c2_i129 < 16; c2_i129++) {
          c2_h_b[c2_i129 + c2_i126] = c2_JBoom[c2_i128 + c2_i127];
          c2_i128 += 3;
        }

        c2_i126 += 16;
      }

      c2_i_eml_scalar_eg(chartInstance);
      c2_i_eml_scalar_eg(chartInstance);
      c2_threshold(chartInstance);
      for (c2_i130 = 0; c2_i130 < 3; c2_i130++) {
        c2_i131 = 0;
        c2_i132 = 0;
        for (c2_i133 = 0; c2_i133 < 3; c2_i133++) {
          c2_g_y[c2_i131 + c2_i130] = 0.0;
          c2_i134 = 0;
          for (c2_i135 = 0; c2_i135 < 16; c2_i135++) {
            c2_g_y[c2_i131 + c2_i130] += c2_b_JBoom[c2_i134 + c2_i130] *
              c2_h_b[c2_i135 + c2_i132];
            c2_i134 += 3;
          }

          c2_i131 += 3;
          c2_i132 += 16;
        }
      }

      c2_i136 = 0;
      for (c2_i137 = 0; c2_i137 < 3; c2_i137++) {
        c2_i138 = 0;
        for (c2_i139 = 0; c2_i139 < 16; c2_i139++) {
          c2_d_JBoom[c2_i139 + c2_i136] = c2_JBoom[c2_i138 + c2_i137];
          c2_i138 += 3;
        }

        c2_i136 += 16;
      }

      for (c2_i140 = 0; c2_i140 < 9; c2_i140++) {
        c2_h_y[c2_i140] = c2_g_y[c2_i140];
      }

      c2_d_mrdivide(chartInstance, c2_d_JBoom, c2_h_y, c2_dv7);
      for (c2_i141 = 0; c2_i141 < 48; c2_i141++) {
        c2_A[c2_i141] = c2_dv7[c2_i141];
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 71);
      for (c2_i142 = 0; c2_i142 < 48; c2_i142++) {
        c2_h_b[c2_i142] = c2_A[c2_i142];
      }

      for (c2_i143 = 0; c2_i143 < 48; c2_i143++) {
        c2_b_JBoom[c2_i143] = c2_JBoom_D[c2_i143];
      }

      c2_j_eml_scalar_eg(chartInstance);
      c2_j_eml_scalar_eg(chartInstance);
      for (c2_i144 = 0; c2_i144 < 256; c2_i144++) {
        c2_b_K_spring[c2_i144] = 0.0;
      }

      for (c2_i145 = 0; c2_i145 < 48; c2_i145++) {
        c2_i_b[c2_i145] = c2_h_b[c2_i145];
      }

      for (c2_i146 = 0; c2_i146 < 48; c2_i146++) {
        c2_e_JBoom[c2_i146] = c2_b_JBoom[c2_i146];
      }

      c2_d_eml_xgemm(chartInstance, c2_i_b, c2_e_JBoom, c2_b_K_spring);
      c2_b_eye(chartInstance, c2_b_K_damping);
      for (c2_i147 = 0; c2_i147 < 256; c2_i147++) {
        c2_P[c2_i147] = c2_b_K_damping[c2_i147] - c2_b_K_spring[c2_i147];
      }

      _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 72);
      for (c2_i148 = 0; c2_i148 < 256; c2_i148++) {
        c2_b_K_spring[c2_i148] = c2_P[c2_i148];
      }

      for (c2_i149 = 0; c2_i149 < 16; c2_i149++) {
        c2_b[c2_i149] = c2_H[c2_i149];
      }

      c2_eml_scalar_eg(chartInstance);
      c2_eml_scalar_eg(chartInstance);
      c2_threshold(chartInstance);
      for (c2_i150 = 0; c2_i150 < 16; c2_i150++) {
        c2_y[c2_i150] = 0.0;
        c2_i151 = 0;
        for (c2_i152 = 0; c2_i152 < 16; c2_i152++) {
          c2_y[c2_i150] += c2_b_K_spring[c2_i151 + c2_i150] * c2_b[c2_i152];
          c2_i151 += 16;
        }
      }

      for (c2_i153 = 0; c2_i153 < 48; c2_i153++) {
        c2_h_b[c2_i153] = c2_A[c2_i153];
      }

      for (c2_i154 = 0; c2_i154 < 3; c2_i154++) {
        c2_b_dJBoom[c2_i154] = c2_dJBoom[c2_i154] - c2_v_con[c2_i154];
      }

      c2_k_eml_scalar_eg(chartInstance);
      c2_k_eml_scalar_eg(chartInstance);
      c2_threshold(chartInstance);
      for (c2_i155 = 0; c2_i155 < 16; c2_i155++) {
        c2_b_y[c2_i155] = 0.0;
        c2_i156 = 0;
        for (c2_i157 = 0; c2_i157 < 3; c2_i157++) {
          c2_b_y[c2_i155] += c2_h_b[c2_i156 + c2_i155] * c2_b_dJBoom[c2_i157];
          c2_i156 += 16;
        }
      }

      for (c2_i158 = 0; c2_i158 < 16; c2_i158++) {
        c2_H[c2_i158] = c2_y[c2_i158] + c2_b_y[c2_i158];
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 76);
  for (c2_i159 = 0; c2_i159 < 256; c2_i159++) {
    c2_e_D[c2_i159] = -c2_b_D[c2_i159];
  }

  for (c2_i160 = 0; c2_i160 < 16; c2_i160++) {
    c2_b_H[c2_i160] = c2_H[c2_i160];
  }

  c2_mldivide(chartInstance, c2_e_D, c2_b_H, c2_dv8);
  for (c2_i161 = 0; c2_i161 < 16; c2_i161++) {
    c2_ddq[c2_i161] = c2_dv8[c2_i161];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, 77);
  for (c2_i162 = 0; c2_i162 < 16; c2_i162++) {
    c2_b_x_dot[c2_i162] = c2_dq[c2_i162];
  }

  for (c2_i163 = 0; c2_i163 < 16; c2_i163++) {
    c2_b_x_dot[c2_i163 + 16] = c2_ddq[c2_i163];
  }

  _SFD_EML_CALL(0U, chartInstance->c2_sfEvent, -77);
  _SFD_SYMBOL_SCOPE_POP();
  for (c2_i164 = 0; c2_i164 < 32; c2_i164++) {
    (*chartInstance->c2_x_dot)[c2_i164] = c2_b_x_dot[c2_i164];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c2_sfEvent);
}

static void initSimStructsc2_DDA2D_OSU3Dv2(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_ATRIAS3D_Spring_Constants(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c2_k_spring, real_T c2_zeta, real_T c2_K_spring[256],
  real_T c2_K_damping[256])
{
  uint32_T c2_debug_family_var_map[8];
  real_T c2_k_damping;
  real_T c2_K_matrix[256];
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 2.0;
  real_T c2_b_x;
  real_T c2_c_x;
  int32_T c2_i165;
  real_T c2_a;
  int32_T c2_i166;
  real_T c2_b[256];
  int32_T c2_i167;
  real_T c2_b_a;
  int32_T c2_i168;
  int32_T c2_i169;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c2_b_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_k_damping, 0U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_K_matrix, 1U, c2_g_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 2U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 3U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_k_spring, 4U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_zeta, 5U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_K_spring, 6U, c2_g_sf_marshallOut,
    c2_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_K_damping, 7U, c2_g_sf_marshallOut,
    c2_f_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 6);
  c2_b_x = c2_k_spring;
  c2_c_x = c2_b_x;
  if (c2_c_x < 0.0) {
    c2_eml_error(chartInstance);
  }

  c2_c_x = muDoubleScalarSqrt(c2_c_x);
  c2_k_damping = 2.0 * c2_zeta * c2_c_x;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 8);
  for (c2_i165 = 0; c2_i165 < 256; c2_i165++) {
    c2_K_matrix[c2_i165] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 10);
  c2_K_matrix[102] = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 11);
  c2_K_matrix[119] = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 12);
  c2_K_matrix[136] = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 13);
  c2_K_matrix[153] = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 14);
  c2_K_matrix[170] = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 15);
  c2_K_matrix[187] = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 16);
  c2_K_matrix[221] = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 17);
  c2_K_matrix[238] = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 19);
  c2_K_matrix[166] = -1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 20);
  c2_K_matrix[183] = -1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 21);
  c2_K_matrix[216] = -1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 22);
  c2_K_matrix[233] = -1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 23);
  c2_K_matrix[106] = -1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 24);
  c2_K_matrix[123] = -1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 25);
  c2_K_matrix[141] = -1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 26);
  c2_K_matrix[158] = -1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 28);
  c2_a = c2_k_spring;
  for (c2_i166 = 0; c2_i166 < 256; c2_i166++) {
    c2_b[c2_i166] = c2_K_matrix[c2_i166];
  }

  for (c2_i167 = 0; c2_i167 < 256; c2_i167++) {
    c2_K_spring[c2_i167] = c2_a * c2_b[c2_i167];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, 29);
  c2_b_a = c2_k_damping;
  for (c2_i168 = 0; c2_i168 < 256; c2_i168++) {
    c2_b[c2_i168] = c2_K_matrix[c2_i168];
  }

  for (c2_i169 = 0; c2_i169 < 256; c2_i169++) {
    c2_K_damping[c2_i169] = c2_b_a * c2_b[c2_i169];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c2_sfEvent, -29);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_JacobBoomHip_FixParams(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c2_q[16], real_T c2_dq[16], real_T c2_b_BoomParams[3],
  real_T c2_jacob_pB0[48], real_T c2_jacob_jacob_pB0[3])
{
  uint32_T c2_debug_family_var_map[42];
  real_T c2_xT;
  real_T c2_dxT;
  real_T c2_yT;
  real_T c2_dyT;
  real_T c2_zT;
  real_T c2_dzT;
  real_T c2_qzT;
  real_T c2_dqzT;
  real_T c2_qyT;
  real_T c2_dqyT;
  real_T c2_qxT;
  real_T c2_dqxT;
  real_T c2_q1R;
  real_T c2_dq1R;
  real_T c2_q2R;
  real_T c2_dq2R;
  real_T c2_q1L;
  real_T c2_dq1L;
  real_T c2_q2L;
  real_T c2_dq2L;
  real_T c2_qgr1R;
  real_T c2_dqgr1R;
  real_T c2_qgr2R;
  real_T c2_dqgr2R;
  real_T c2_q3R;
  real_T c2_dq3R;
  real_T c2_qgr1L;
  real_T c2_dqgr1L;
  real_T c2_qgr2L;
  real_T c2_dqgr2L;
  real_T c2_q3L;
  real_T c2_dq3L;
  real_T c2_xB;
  real_T c2_yB;
  real_T c2_zB;
  real_T c2_nargin = 3.0;
  real_T c2_nargout = 2.0;
  int32_T c2_i170;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_db_x;
  real_T c2_eb_x;
  real_T c2_fb_x;
  real_T c2_gb_x;
  real_T c2_hb_x;
  real_T c2_ib_x;
  real_T c2_jb_x;
  real_T c2_kb_x;
  real_T c2_lb_x;
  real_T c2_mb_x;
  real_T c2_nb_x;
  real_T c2_ob_x;
  real_T c2_pb_x;
  real_T c2_qb_x;
  real_T c2_rb_x;
  real_T c2_sb_x;
  real_T c2_tb_x;
  real_T c2_ub_x;
  real_T c2_vb_x;
  real_T c2_wb_x;
  real_T c2_xb_x;
  real_T c2_yb_x;
  real_T c2_ac_x;
  real_T c2_bc_x;
  real_T c2_cc_x;
  real_T c2_dc_x;
  real_T c2_ec_x;
  real_T c2_fc_x;
  real_T c2_gc_x;
  real_T c2_hc_x;
  real_T c2_ic_x;
  real_T c2_jc_x;
  real_T c2_kc_x;
  real_T c2_lc_x;
  real_T c2_mc_x;
  real_T c2_nc_x;
  real_T c2_oc_x;
  real_T c2_pc_x;
  real_T c2_qc_x;
  real_T c2_rc_x;
  real_T c2_sc_x;
  real_T c2_tc_x;
  real_T c2_uc_x;
  real_T c2_vc_x;
  real_T c2_wc_x;
  real_T c2_xc_x;
  real_T c2_yc_x;
  real_T c2_ad_x;
  real_T c2_bd_x;
  real_T c2_cd_x;
  real_T c2_dd_x;
  real_T c2_ed_x;
  real_T c2_fd_x;
  real_T c2_gd_x;
  real_T c2_hd_x;
  real_T c2_id_x;
  real_T c2_jd_x;
  real_T c2_kd_x;
  real_T c2_ld_x;
  real_T c2_md_x;
  real_T c2_nd_x;
  real_T c2_od_x;
  real_T c2_pd_x;
  real_T c2_qd_x;
  real_T c2_rd_x;
  real_T c2_sd_x;
  real_T c2_td_x;
  real_T c2_ud_x;
  real_T c2_vd_x;
  real_T c2_wd_x;
  real_T c2_xd_x;
  real_T c2_yd_x;
  real_T c2_ae_x;
  real_T c2_be_x;
  real_T c2_ce_x;
  real_T c2_de_x;
  real_T c2_ee_x;
  real_T c2_fe_x;
  real_T c2_ge_x;
  real_T c2_he_x;
  real_T c2_ie_x;
  real_T c2_je_x;
  real_T c2_ke_x;
  real_T c2_le_x;
  real_T c2_me_x;
  real_T c2_ne_x;
  real_T c2_oe_x;
  real_T c2_pe_x;
  real_T c2_qe_x;
  real_T c2_re_x;
  real_T c2_se_x;
  real_T c2_te_x;
  real_T c2_ue_x;
  real_T c2_ve_x;
  real_T c2_we_x;
  real_T c2_xe_x;
  real_T c2_ye_x;
  real_T c2_af_x;
  real_T c2_bf_x;
  real_T c2_cf_x;
  real_T c2_df_x;
  int32_T c2_i171;
  real_T c2_ef_x;
  real_T c2_ff_x;
  real_T c2_gf_x;
  real_T c2_hf_x;
  real_T c2_if_x;
  real_T c2_jf_x;
  real_T c2_kf_x;
  real_T c2_lf_x;
  real_T c2_mf_x;
  real_T c2_nf_x;
  real_T c2_of_x;
  real_T c2_pf_x;
  real_T c2_qf_x;
  real_T c2_rf_x;
  real_T c2_sf_x;
  real_T c2_tf_x;
  real_T c2_uf_x;
  real_T c2_vf_x;
  real_T c2_wf_x;
  real_T c2_xf_x;
  real_T c2_yf_x;
  real_T c2_ag_x;
  real_T c2_bg_x;
  real_T c2_cg_x;
  real_T c2_dg_x;
  real_T c2_eg_x;
  real_T c2_fg_x;
  real_T c2_gg_x;
  real_T c2_hg_x;
  real_T c2_ig_x;
  real_T c2_jg_x;
  real_T c2_kg_x;
  real_T c2_lg_x;
  real_T c2_mg_x;
  real_T c2_ng_x;
  real_T c2_og_x;
  real_T c2_pg_x;
  real_T c2_qg_x;
  real_T c2_rg_x;
  real_T c2_sg_x;
  real_T c2_tg_x;
  real_T c2_ug_x;
  real_T c2_vg_x;
  real_T c2_wg_x;
  real_T c2_xg_x;
  real_T c2_yg_x;
  real_T c2_ah_x;
  real_T c2_bh_x;
  real_T c2_ch_x;
  real_T c2_dh_x;
  real_T c2_eh_x;
  real_T c2_fh_x;
  real_T c2_gh_x;
  real_T c2_hh_x;
  real_T c2_ih_x;
  real_T c2_jh_x;
  real_T c2_kh_x;
  real_T c2_lh_x;
  real_T c2_mh_x;
  real_T c2_nh_x;
  real_T c2_oh_x;
  real_T c2_ph_x;
  real_T c2_qh_x;
  real_T c2_rh_x;
  real_T c2_sh_x;
  real_T c2_th_x;
  real_T c2_uh_x;
  real_T c2_vh_x;
  real_T c2_wh_x;
  real_T c2_xh_x;
  real_T c2_yh_x;
  real_T c2_ai_x;
  real_T c2_bi_x;
  real_T c2_ci_x;
  real_T c2_di_x;
  real_T c2_ei_x;
  real_T c2_fi_x;
  real_T c2_gi_x;
  real_T c2_hi_x;
  real_T c2_ii_x;
  real_T c2_ji_x;
  real_T c2_ki_x;
  real_T c2_li_x;
  real_T c2_mi_x;
  real_T c2_ni_x;
  real_T c2_oi_x;
  real_T c2_pi_x;
  real_T c2_qi_x;
  real_T c2_ri_x;
  real_T c2_si_x;
  real_T c2_ti_x;
  real_T c2_ui_x;
  real_T c2_vi_x;
  real_T c2_wi_x;
  real_T c2_xi_x;
  real_T c2_yi_x;
  real_T c2_aj_x;
  real_T c2_bj_x;
  real_T c2_cj_x;
  real_T c2_dj_x;
  real_T c2_ej_x;
  real_T c2_fj_x;
  real_T c2_gj_x;
  real_T c2_hj_x;
  real_T c2_ij_x;
  real_T c2_jj_x;
  real_T c2_kj_x;
  real_T c2_lj_x;
  real_T c2_mj_x;
  real_T c2_nj_x;
  real_T c2_oj_x;
  real_T c2_pj_x;
  real_T c2_qj_x;
  real_T c2_rj_x;
  real_T c2_sj_x;
  real_T c2_tj_x;
  real_T c2_uj_x;
  real_T c2_vj_x;
  real_T c2_wj_x;
  real_T c2_xj_x;
  real_T c2_yj_x;
  real_T c2_ak_x;
  real_T c2_bk_x;
  real_T c2_ck_x;
  real_T c2_dk_x;
  real_T c2_ek_x;
  real_T c2_fk_x;
  real_T c2_gk_x;
  real_T c2_hk_x;
  real_T c2_ik_x;
  real_T c2_jk_x;
  real_T c2_kk_x;
  real_T c2_lk_x;
  real_T c2_mk_x;
  real_T c2_nk_x;
  real_T c2_ok_x;
  real_T c2_pk_x;
  real_T c2_qk_x;
  real_T c2_rk_x;
  real_T c2_sk_x;
  real_T c2_tk_x;
  real_T c2_uk_x;
  real_T c2_vk_x;
  real_T c2_wk_x;
  real_T c2_xk_x;
  real_T c2_yk_x;
  real_T c2_al_x;
  real_T c2_bl_x;
  real_T c2_cl_x;
  real_T c2_dl_x;
  real_T c2_el_x;
  real_T c2_fl_x;
  real_T c2_gl_x;
  real_T c2_hl_x;
  real_T c2_il_x;
  real_T c2_jl_x;
  real_T c2_kl_x;
  real_T c2_ll_x;
  real_T c2_ml_x;
  real_T c2_nl_x;
  real_T c2_ol_x;
  real_T c2_pl_x;
  real_T c2_ql_x;
  real_T c2_rl_x;
  real_T c2_sl_x;
  real_T c2_tl_x;
  real_T c2_ul_x;
  real_T c2_vl_x;
  real_T c2_wl_x;
  real_T c2_xl_x;
  real_T c2_yl_x;
  real_T c2_am_x;
  real_T c2_bm_x;
  real_T c2_cm_x;
  real_T c2_dm_x;
  real_T c2_em_x;
  real_T c2_fm_x;
  real_T c2_gm_x;
  real_T c2_hm_x;
  real_T c2_im_x;
  real_T c2_jm_x;
  real_T c2_km_x;
  real_T c2_lm_x;
  real_T c2_mm_x;
  real_T c2_nm_x;
  real_T c2_om_x;
  real_T c2_pm_x;
  real_T c2_qm_x;
  real_T c2_rm_x;
  real_T c2_sm_x;
  real_T c2_tm_x;
  real_T c2_um_x;
  real_T c2_vm_x;
  real_T c2_wm_x;
  real_T c2_xm_x;
  real_T c2_ym_x;
  real_T c2_an_x;
  real_T c2_bn_x;
  real_T c2_cn_x;
  real_T c2_dn_x;
  real_T c2_en_x;
  real_T c2_fn_x;
  real_T c2_gn_x;
  real_T c2_hn_x;
  real_T c2_in_x;
  real_T c2_jn_x;
  real_T c2_kn_x;
  real_T c2_ln_x;
  real_T c2_mn_x;
  real_T c2_nn_x;
  real_T c2_on_x;
  real_T c2_pn_x;
  real_T c2_qn_x;
  real_T c2_rn_x;
  real_T c2_sn_x;
  real_T c2_tn_x;
  real_T c2_un_x;
  real_T c2_vn_x;
  real_T c2_wn_x;
  real_T c2_xn_x;
  real_T c2_yn_x;
  real_T c2_ao_x;
  real_T c2_bo_x;
  real_T c2_co_x;
  real_T c2_do_x;
  real_T c2_eo_x;
  real_T c2_fo_x;
  real_T c2_go_x;
  real_T c2_ho_x;
  real_T c2_io_x;
  real_T c2_jo_x;
  real_T c2_ko_x;
  real_T c2_lo_x;
  real_T c2_mo_x;
  real_T c2_no_x;
  real_T c2_oo_x;
  real_T c2_po_x;
  real_T c2_qo_x;
  real_T c2_ro_x;
  real_T c2_so_x;
  real_T c2_to_x;
  real_T c2_uo_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 42U, 42U, c2_c_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_xT, 0U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dxT, 1U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_yT, 2U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dyT, 3U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_zT, 4U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dzT, 5U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qzT, 6U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dqzT, 7U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qyT, 8U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dqyT, 9U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qxT, 10U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dqxT, 11U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q1R, 12U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dq1R, 13U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q2R, 14U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dq2R, 15U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q1L, 16U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dq1L, 17U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q2L, 18U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dq2L, 19U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qgr1R, 20U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dqgr1R, 21U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qgr2R, 22U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dqgr2R, 23U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q3R, 24U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dq3R, 25U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qgr1L, 26U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dqgr1L, 27U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qgr2L, 28U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dqgr2L, 29U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q3L, 30U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_dq3L, 31U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_xB, 32U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_yB, 33U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_zB, 34U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 35U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 36U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_q, 37U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_dq, 38U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_BoomParams, 39U, c2_k_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_jacob_pB0, 40U, c2_j_sf_marshallOut,
    c2_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_jacob_jacob_pB0, 41U,
    c2_k_sf_marshallOut, c2_i_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 8);
  c2_xT = c2_q[0];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 8);
  c2_dxT = c2_dq[0];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 9);
  c2_yT = c2_q[1];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 9);
  c2_dyT = c2_dq[1];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 10);
  c2_zT = c2_q[2];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 10);
  c2_dzT = c2_dq[2];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 11);
  c2_qzT = c2_q[3];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 11);
  c2_dqzT = c2_dq[3];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 12);
  c2_qyT = c2_q[4];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 12);
  c2_dqyT = c2_dq[4];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 13);
  c2_qxT = c2_q[5];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 13);
  c2_dqxT = c2_dq[5];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 14);
  c2_q1R = c2_q[6];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 14);
  c2_dq1R = c2_dq[6];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 15);
  c2_q2R = c2_q[7];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 15);
  c2_dq2R = c2_dq[7];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 16);
  c2_q1L = c2_q[8];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 16);
  c2_dq1L = c2_dq[8];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 17);
  c2_q2L = c2_q[9];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 17);
  c2_dq2L = c2_dq[9];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 18);
  c2_qgr1R = c2_q[10];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 18);
  c2_dqgr1R = c2_dq[10];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 19);
  c2_qgr2R = c2_q[11];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 19);
  c2_dqgr2R = c2_dq[11];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 20);
  c2_q3R = c2_q[12];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 20);
  c2_dq3R = c2_dq[12];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 21);
  c2_qgr1L = c2_q[13];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 21);
  c2_dqgr1L = c2_dq[13];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 22);
  c2_qgr2L = c2_q[14];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 22);
  c2_dqgr2L = c2_dq[14];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 23);
  c2_q3L = c2_q[15];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 23);
  c2_dq3L = c2_dq[15];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 25);
  c2_xB = c2_b_BoomParams[0];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 26);
  c2_yB = c2_b_BoomParams[1];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 27);
  c2_zB = c2_b_BoomParams[2];
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 30);
  for (c2_i170 = 0; c2_i170 < 48; c2_i170++) {
    c2_jacob_pB0[c2_i170] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 31);
  c2_jacob_pB0[0] = 1.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 32);
  c2_b_x = c2_qzT;
  c2_c_x = c2_b_x;
  c2_c_x = muDoubleScalarSin(c2_c_x);
  c2_d_x = c2_qyT;
  c2_e_x = c2_d_x;
  c2_e_x = muDoubleScalarCos(c2_e_x);
  c2_f_x = c2_qzT;
  c2_g_x = c2_f_x;
  c2_g_x = muDoubleScalarCos(c2_g_x);
  c2_h_x = c2_qxT;
  c2_i_x = c2_h_x;
  c2_i_x = muDoubleScalarCos(c2_i_x);
  c2_j_x = c2_qzT;
  c2_k_x = c2_j_x;
  c2_k_x = muDoubleScalarSin(c2_k_x);
  c2_l_x = c2_qyT;
  c2_m_x = c2_l_x;
  c2_m_x = muDoubleScalarSin(c2_m_x);
  c2_n_x = c2_qxT;
  c2_o_x = c2_n_x;
  c2_o_x = muDoubleScalarSin(c2_o_x);
  c2_p_x = c2_qzT;
  c2_q_x = c2_p_x;
  c2_q_x = muDoubleScalarCos(c2_q_x);
  c2_r_x = c2_qxT;
  c2_s_x = c2_r_x;
  c2_s_x = muDoubleScalarSin(c2_s_x);
  c2_t_x = c2_qzT;
  c2_u_x = c2_t_x;
  c2_u_x = muDoubleScalarSin(c2_u_x);
  c2_v_x = c2_qyT;
  c2_w_x = c2_v_x;
  c2_w_x = muDoubleScalarSin(c2_w_x);
  c2_x_x = c2_qxT;
  c2_y_x = c2_x_x;
  c2_y_x = muDoubleScalarCos(c2_y_x);
  c2_jacob_pB0[9] = (((-c2_c_x * c2_e_x * c2_xB - c2_yB * c2_g_x * c2_i_x) -
                      c2_yB * c2_k_x * c2_m_x * c2_o_x) + c2_zB * c2_q_x *
                     c2_s_x) - c2_zB * c2_u_x * c2_w_x * c2_y_x;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 35);
  c2_ab_x = c2_qzT;
  c2_bb_x = c2_ab_x;
  c2_bb_x = muDoubleScalarCos(c2_bb_x);
  c2_cb_x = c2_qyT;
  c2_db_x = c2_cb_x;
  c2_db_x = muDoubleScalarSin(c2_db_x);
  c2_eb_x = c2_qyT;
  c2_fb_x = c2_eb_x;
  c2_fb_x = muDoubleScalarCos(c2_fb_x);
  c2_gb_x = c2_qxT;
  c2_hb_x = c2_gb_x;
  c2_hb_x = muDoubleScalarSin(c2_hb_x);
  c2_ib_x = c2_qyT;
  c2_jb_x = c2_ib_x;
  c2_jb_x = muDoubleScalarCos(c2_jb_x);
  c2_kb_x = c2_qxT;
  c2_lb_x = c2_kb_x;
  c2_lb_x = muDoubleScalarCos(c2_lb_x);
  c2_jacob_pB0[12] = c2_bb_x * ((-c2_db_x * c2_xB + c2_fb_x * c2_hb_x * c2_yB) +
    c2_jb_x * c2_lb_x * c2_zB);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 37);
  c2_mb_x = c2_qzT;
  c2_nb_x = c2_mb_x;
  c2_nb_x = muDoubleScalarSin(c2_nb_x);
  c2_ob_x = c2_qxT;
  c2_pb_x = c2_ob_x;
  c2_pb_x = muDoubleScalarSin(c2_pb_x);
  c2_qb_x = c2_qzT;
  c2_rb_x = c2_qb_x;
  c2_rb_x = muDoubleScalarCos(c2_rb_x);
  c2_sb_x = c2_qyT;
  c2_tb_x = c2_sb_x;
  c2_tb_x = muDoubleScalarSin(c2_tb_x);
  c2_ub_x = c2_qxT;
  c2_vb_x = c2_ub_x;
  c2_vb_x = muDoubleScalarCos(c2_vb_x);
  c2_wb_x = c2_qzT;
  c2_xb_x = c2_wb_x;
  c2_xb_x = muDoubleScalarSin(c2_xb_x);
  c2_yb_x = c2_qxT;
  c2_ac_x = c2_yb_x;
  c2_ac_x = muDoubleScalarCos(c2_ac_x);
  c2_bc_x = c2_qzT;
  c2_cc_x = c2_bc_x;
  c2_cc_x = muDoubleScalarCos(c2_cc_x);
  c2_dc_x = c2_qyT;
  c2_ec_x = c2_dc_x;
  c2_ec_x = muDoubleScalarSin(c2_ec_x);
  c2_fc_x = c2_qxT;
  c2_gc_x = c2_fc_x;
  c2_gc_x = muDoubleScalarSin(c2_gc_x);
  c2_jacob_pB0[15] = ((c2_yB * c2_nb_x * c2_pb_x + c2_yB * c2_rb_x * c2_tb_x *
                       c2_vb_x) + c2_zB * c2_xb_x * c2_ac_x) - c2_zB * c2_cc_x *
    c2_ec_x * c2_gc_x;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 39);
  c2_jacob_pB0[4] = 1.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 40);
  c2_hc_x = c2_qzT;
  c2_ic_x = c2_hc_x;
  c2_ic_x = muDoubleScalarCos(c2_ic_x);
  c2_jc_x = c2_qyT;
  c2_kc_x = c2_jc_x;
  c2_kc_x = muDoubleScalarCos(c2_kc_x);
  c2_lc_x = c2_qzT;
  c2_mc_x = c2_lc_x;
  c2_mc_x = muDoubleScalarSin(c2_mc_x);
  c2_nc_x = c2_qxT;
  c2_oc_x = c2_nc_x;
  c2_oc_x = muDoubleScalarCos(c2_oc_x);
  c2_pc_x = c2_qzT;
  c2_qc_x = c2_pc_x;
  c2_qc_x = muDoubleScalarCos(c2_qc_x);
  c2_rc_x = c2_qyT;
  c2_sc_x = c2_rc_x;
  c2_sc_x = muDoubleScalarSin(c2_sc_x);
  c2_tc_x = c2_qxT;
  c2_uc_x = c2_tc_x;
  c2_uc_x = muDoubleScalarSin(c2_uc_x);
  c2_vc_x = c2_qzT;
  c2_wc_x = c2_vc_x;
  c2_wc_x = muDoubleScalarSin(c2_wc_x);
  c2_xc_x = c2_qxT;
  c2_yc_x = c2_xc_x;
  c2_yc_x = muDoubleScalarSin(c2_yc_x);
  c2_ad_x = c2_qzT;
  c2_bd_x = c2_ad_x;
  c2_bd_x = muDoubleScalarCos(c2_bd_x);
  c2_cd_x = c2_qyT;
  c2_dd_x = c2_cd_x;
  c2_dd_x = muDoubleScalarSin(c2_dd_x);
  c2_ed_x = c2_qxT;
  c2_fd_x = c2_ed_x;
  c2_fd_x = muDoubleScalarCos(c2_fd_x);
  c2_jacob_pB0[10] = (((c2_ic_x * c2_kc_x * c2_xB - c2_yB * c2_mc_x * c2_oc_x) +
                       c2_yB * c2_qc_x * c2_sc_x * c2_uc_x) + c2_zB * c2_wc_x *
                      c2_yc_x) + c2_zB * c2_bd_x * c2_dd_x * c2_fd_x;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 43);
  c2_gd_x = c2_qzT;
  c2_hd_x = c2_gd_x;
  c2_hd_x = muDoubleScalarSin(c2_hd_x);
  c2_id_x = c2_qyT;
  c2_jd_x = c2_id_x;
  c2_jd_x = muDoubleScalarSin(c2_jd_x);
  c2_kd_x = c2_qyT;
  c2_ld_x = c2_kd_x;
  c2_ld_x = muDoubleScalarCos(c2_ld_x);
  c2_md_x = c2_qxT;
  c2_nd_x = c2_md_x;
  c2_nd_x = muDoubleScalarSin(c2_nd_x);
  c2_od_x = c2_qyT;
  c2_pd_x = c2_od_x;
  c2_pd_x = muDoubleScalarCos(c2_pd_x);
  c2_qd_x = c2_qxT;
  c2_rd_x = c2_qd_x;
  c2_rd_x = muDoubleScalarCos(c2_rd_x);
  c2_jacob_pB0[13] = c2_hd_x * ((-c2_jd_x * c2_xB + c2_ld_x * c2_nd_x * c2_yB) +
    c2_pd_x * c2_rd_x * c2_zB);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 45);
  c2_sd_x = c2_qzT;
  c2_td_x = c2_sd_x;
  c2_td_x = muDoubleScalarCos(c2_td_x);
  c2_ud_x = c2_qxT;
  c2_vd_x = c2_ud_x;
  c2_vd_x = muDoubleScalarSin(c2_vd_x);
  c2_wd_x = c2_qzT;
  c2_xd_x = c2_wd_x;
  c2_xd_x = muDoubleScalarSin(c2_xd_x);
  c2_yd_x = c2_qyT;
  c2_ae_x = c2_yd_x;
  c2_ae_x = muDoubleScalarSin(c2_ae_x);
  c2_be_x = c2_qxT;
  c2_ce_x = c2_be_x;
  c2_ce_x = muDoubleScalarCos(c2_ce_x);
  c2_de_x = c2_qzT;
  c2_ee_x = c2_de_x;
  c2_ee_x = muDoubleScalarCos(c2_ee_x);
  c2_fe_x = c2_qxT;
  c2_ge_x = c2_fe_x;
  c2_ge_x = muDoubleScalarCos(c2_ge_x);
  c2_he_x = c2_qzT;
  c2_ie_x = c2_he_x;
  c2_ie_x = muDoubleScalarSin(c2_ie_x);
  c2_je_x = c2_qyT;
  c2_ke_x = c2_je_x;
  c2_ke_x = muDoubleScalarSin(c2_ke_x);
  c2_le_x = c2_qxT;
  c2_me_x = c2_le_x;
  c2_me_x = muDoubleScalarSin(c2_me_x);
  c2_jacob_pB0[16] = ((-c2_yB * c2_td_x * c2_vd_x + c2_yB * c2_xd_x * c2_ae_x *
                       c2_ce_x) - c2_zB * c2_ee_x * c2_ge_x) - c2_zB * c2_ie_x *
    c2_ke_x * c2_me_x;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 47);
  c2_jacob_pB0[8] = 1.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 48);
  c2_ne_x = c2_qyT;
  c2_oe_x = c2_ne_x;
  c2_oe_x = muDoubleScalarCos(c2_oe_x);
  c2_pe_x = c2_qyT;
  c2_qe_x = c2_pe_x;
  c2_qe_x = muDoubleScalarSin(c2_qe_x);
  c2_re_x = c2_qxT;
  c2_se_x = c2_re_x;
  c2_se_x = muDoubleScalarSin(c2_se_x);
  c2_te_x = c2_qyT;
  c2_ue_x = c2_te_x;
  c2_ue_x = muDoubleScalarSin(c2_ue_x);
  c2_ve_x = c2_qxT;
  c2_we_x = c2_ve_x;
  c2_we_x = muDoubleScalarCos(c2_we_x);
  c2_jacob_pB0[14] = (-c2_oe_x * c2_xB - c2_qe_x * c2_se_x * c2_yB) - c2_ue_x *
    c2_we_x * c2_zB;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 50);
  c2_xe_x = c2_qyT;
  c2_ye_x = c2_xe_x;
  c2_ye_x = muDoubleScalarCos(c2_ye_x);
  c2_af_x = c2_qxT;
  c2_bf_x = c2_af_x;
  c2_bf_x = muDoubleScalarCos(c2_bf_x);
  c2_cf_x = c2_qxT;
  c2_df_x = c2_cf_x;
  c2_df_x = muDoubleScalarSin(c2_df_x);
  c2_jacob_pB0[17] = -c2_ye_x * (-c2_bf_x * c2_yB + c2_df_x * c2_zB);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 51);
  for (c2_i171 = 0; c2_i171 < 3; c2_i171++) {
    c2_jacob_jacob_pB0[c2_i171] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 52);
  c2_ef_x = c2_qzT;
  c2_ff_x = c2_ef_x;
  c2_ff_x = muDoubleScalarCos(c2_ff_x);
  c2_gf_x = c2_qyT;
  c2_hf_x = c2_gf_x;
  c2_hf_x = muDoubleScalarCos(c2_hf_x);
  c2_if_x = c2_qzT;
  c2_jf_x = c2_if_x;
  c2_jf_x = muDoubleScalarSin(c2_jf_x);
  c2_kf_x = c2_qxT;
  c2_lf_x = c2_kf_x;
  c2_lf_x = muDoubleScalarCos(c2_lf_x);
  c2_mf_x = c2_qzT;
  c2_nf_x = c2_mf_x;
  c2_nf_x = muDoubleScalarSin(c2_nf_x);
  c2_of_x = c2_qxT;
  c2_pf_x = c2_of_x;
  c2_pf_x = muDoubleScalarSin(c2_pf_x);
  c2_qf_x = c2_qzT;
  c2_rf_x = c2_qf_x;
  c2_rf_x = muDoubleScalarCos(c2_rf_x);
  c2_sf_x = c2_qyT;
  c2_tf_x = c2_sf_x;
  c2_tf_x = muDoubleScalarCos(c2_tf_x);
  c2_uf_x = c2_qzT;
  c2_vf_x = c2_uf_x;
  c2_vf_x = muDoubleScalarSin(c2_vf_x);
  c2_wf_x = c2_qyT;
  c2_xf_x = c2_wf_x;
  c2_xf_x = muDoubleScalarSin(c2_xf_x);
  c2_yf_x = c2_qzT;
  c2_ag_x = c2_yf_x;
  c2_ag_x = muDoubleScalarSin(c2_ag_x);
  c2_bg_x = c2_qyT;
  c2_cg_x = c2_bg_x;
  c2_cg_x = muDoubleScalarCos(c2_cg_x);
  c2_dg_x = c2_qxT;
  c2_eg_x = c2_dg_x;
  c2_eg_x = muDoubleScalarSin(c2_eg_x);
  c2_fg_x = c2_qzT;
  c2_gg_x = c2_fg_x;
  c2_gg_x = muDoubleScalarSin(c2_gg_x);
  c2_hg_x = c2_qyT;
  c2_ig_x = c2_hg_x;
  c2_ig_x = muDoubleScalarCos(c2_ig_x);
  c2_jg_x = c2_qxT;
  c2_kg_x = c2_jg_x;
  c2_kg_x = muDoubleScalarCos(c2_kg_x);
  c2_lg_x = c2_qzT;
  c2_mg_x = c2_lg_x;
  c2_mg_x = muDoubleScalarCos(c2_mg_x);
  c2_ng_x = c2_qxT;
  c2_og_x = c2_ng_x;
  c2_og_x = muDoubleScalarSin(c2_og_x);
  c2_pg_x = c2_qzT;
  c2_qg_x = c2_pg_x;
  c2_qg_x = muDoubleScalarSin(c2_qg_x);
  c2_rg_x = c2_qyT;
  c2_sg_x = c2_rg_x;
  c2_sg_x = muDoubleScalarSin(c2_sg_x);
  c2_tg_x = c2_qxT;
  c2_ug_x = c2_tg_x;
  c2_ug_x = muDoubleScalarCos(c2_ug_x);
  c2_vg_x = c2_qzT;
  c2_wg_x = c2_vg_x;
  c2_wg_x = muDoubleScalarCos(c2_wg_x);
  c2_xg_x = c2_qxT;
  c2_yg_x = c2_xg_x;
  c2_yg_x = muDoubleScalarCos(c2_yg_x);
  c2_ah_x = c2_qzT;
  c2_bh_x = c2_ah_x;
  c2_bh_x = muDoubleScalarCos(c2_bh_x);
  c2_ch_x = c2_qyT;
  c2_dh_x = c2_ch_x;
  c2_dh_x = muDoubleScalarSin(c2_dh_x);
  c2_eh_x = c2_qxT;
  c2_fh_x = c2_eh_x;
  c2_fh_x = muDoubleScalarSin(c2_fh_x);
  c2_gh_x = c2_qzT;
  c2_hh_x = c2_gh_x;
  c2_hh_x = muDoubleScalarCos(c2_hh_x);
  c2_ih_x = c2_qyT;
  c2_jh_x = c2_ih_x;
  c2_jh_x = muDoubleScalarSin(c2_jh_x);
  c2_kh_x = c2_qxT;
  c2_lh_x = c2_kh_x;
  c2_lh_x = muDoubleScalarCos(c2_lh_x);
  c2_mh_x = c2_qzT;
  c2_nh_x = c2_mh_x;
  c2_nh_x = muDoubleScalarSin(c2_nh_x);
  c2_oh_x = c2_qyT;
  c2_ph_x = c2_oh_x;
  c2_ph_x = muDoubleScalarSin(c2_ph_x);
  c2_qh_x = c2_qxT;
  c2_rh_x = c2_qh_x;
  c2_rh_x = muDoubleScalarSin(c2_rh_x);
  c2_sh_x = c2_qzT;
  c2_th_x = c2_sh_x;
  c2_th_x = muDoubleScalarCos(c2_th_x);
  c2_uh_x = c2_qyT;
  c2_vh_x = c2_uh_x;
  c2_vh_x = muDoubleScalarSin(c2_vh_x);
  c2_wh_x = c2_qxT;
  c2_xh_x = c2_wh_x;
  c2_xh_x = muDoubleScalarSin(c2_xh_x);
  c2_yh_x = c2_qzT;
  c2_ai_x = c2_yh_x;
  c2_ai_x = muDoubleScalarCos(c2_ai_x);
  c2_bi_x = c2_qyT;
  c2_ci_x = c2_bi_x;
  c2_ci_x = muDoubleScalarSin(c2_ci_x);
  c2_di_x = c2_qxT;
  c2_ei_x = c2_di_x;
  c2_ei_x = muDoubleScalarCos(c2_ei_x);
  c2_fi_x = c2_qzT;
  c2_gi_x = c2_fi_x;
  c2_gi_x = muDoubleScalarCos(c2_gi_x);
  c2_hi_x = c2_qyT;
  c2_ii_x = c2_hi_x;
  c2_ii_x = muDoubleScalarCos(c2_ii_x);
  c2_ji_x = c2_qxT;
  c2_ki_x = c2_ji_x;
  c2_ki_x = muDoubleScalarCos(c2_ki_x);
  c2_li_x = c2_qzT;
  c2_mi_x = c2_li_x;
  c2_mi_x = muDoubleScalarCos(c2_mi_x);
  c2_ni_x = c2_qyT;
  c2_oi_x = c2_ni_x;
  c2_oi_x = muDoubleScalarCos(c2_oi_x);
  c2_pi_x = c2_qxT;
  c2_qi_x = c2_pi_x;
  c2_qi_x = muDoubleScalarSin(c2_qi_x);
  c2_ri_x = c2_qzT;
  c2_si_x = c2_ri_x;
  c2_si_x = muDoubleScalarSin(c2_si_x);
  c2_ti_x = c2_qxT;
  c2_ui_x = c2_ti_x;
  c2_ui_x = muDoubleScalarCos(c2_ui_x);
  c2_vi_x = c2_qzT;
  c2_wi_x = c2_vi_x;
  c2_wi_x = muDoubleScalarCos(c2_wi_x);
  c2_xi_x = c2_qyT;
  c2_yi_x = c2_xi_x;
  c2_yi_x = muDoubleScalarSin(c2_yi_x);
  c2_aj_x = c2_qxT;
  c2_bj_x = c2_aj_x;
  c2_bj_x = muDoubleScalarCos(c2_bj_x);
  c2_cj_x = c2_qzT;
  c2_dj_x = c2_cj_x;
  c2_dj_x = muDoubleScalarCos(c2_dj_x);
  c2_ej_x = c2_qyT;
  c2_fj_x = c2_ej_x;
  c2_fj_x = muDoubleScalarSin(c2_fj_x);
  c2_gj_x = c2_qxT;
  c2_hj_x = c2_gj_x;
  c2_hj_x = muDoubleScalarSin(c2_hj_x);
  c2_ij_x = c2_qzT;
  c2_jj_x = c2_ij_x;
  c2_jj_x = muDoubleScalarSin(c2_jj_x);
  c2_kj_x = c2_qxT;
  c2_lj_x = c2_kj_x;
  c2_lj_x = muDoubleScalarSin(c2_lj_x);
  c2_jacob_jacob_pB0[0] = (((((((((((((((((((-c2_mpower(chartInstance, c2_dqzT) *
    c2_ff_x * c2_hf_x * c2_xB + c2_mpower(chartInstance, c2_dqzT) * c2_yB *
    c2_jf_x * c2_lf_x) - c2_mpower(chartInstance, c2_dqzT) * c2_zB * c2_nf_x *
    c2_pf_x) - c2_rf_x * c2_mpower(chartInstance, c2_dqyT) * c2_tf_x * c2_xB) +
    2.0 * c2_dqzT * c2_vf_x * c2_dqyT * c2_xf_x * c2_xB) - 2.0 * c2_dqzT *
    c2_ag_x * c2_dqyT * c2_cg_x * c2_eg_x * c2_yB) - 2.0 * c2_dqzT * c2_gg_x *
    c2_dqyT * c2_ig_x * c2_kg_x * c2_zB) + 2.0 * c2_dqzT * c2_dqxT * c2_yB *
    c2_mg_x * c2_og_x) - 2.0 * c2_dqzT * c2_dqxT * c2_yB * c2_qg_x * c2_sg_x *
    c2_ug_x) + 2.0 * c2_dqzT * c2_dqxT * c2_zB * c2_wg_x * c2_yg_x) - c2_mpower
    (chartInstance, c2_dqzT) * c2_yB * c2_bh_x * c2_dh_x * c2_fh_x) - c2_mpower
    (chartInstance, c2_dqzT) * c2_zB * c2_hh_x * c2_jh_x * c2_lh_x) + 2.0 *
    c2_dqzT * c2_dqxT * c2_zB * c2_nh_x * c2_ph_x * c2_rh_x) - c2_th_x *
    c2_mpower(chartInstance, c2_dqyT) * c2_vh_x * c2_xh_x * c2_yB) - c2_ai_x *
    c2_mpower(chartInstance, c2_dqyT) * c2_ci_x * c2_ei_x * c2_zB) + 2.0 *
    c2_dqyT * c2_dqxT * c2_yB * c2_gi_x * c2_ii_x * c2_ki_x) - 2.0 * c2_dqyT *
    c2_dqxT * c2_zB * c2_mi_x * c2_oi_x * c2_qi_x) + c2_mpower(chartInstance,
    c2_dqxT) * c2_yB * c2_si_x * c2_ui_x) - c2_mpower(chartInstance, c2_dqxT) *
    c2_zB * c2_wi_x * c2_yi_x * c2_bj_x) - c2_mpower(chartInstance, c2_dqxT) *
    c2_yB * c2_dj_x * c2_fj_x * c2_hj_x) - c2_mpower(chartInstance, c2_dqxT) *
    c2_zB * c2_jj_x * c2_lj_x;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 65);
  c2_mj_x = c2_qzT;
  c2_nj_x = c2_mj_x;
  c2_nj_x = muDoubleScalarSin(c2_nj_x);
  c2_oj_x = c2_qyT;
  c2_pj_x = c2_oj_x;
  c2_pj_x = muDoubleScalarCos(c2_pj_x);
  c2_qj_x = c2_qzT;
  c2_rj_x = c2_qj_x;
  c2_rj_x = muDoubleScalarCos(c2_rj_x);
  c2_sj_x = c2_qxT;
  c2_tj_x = c2_sj_x;
  c2_tj_x = muDoubleScalarCos(c2_tj_x);
  c2_uj_x = c2_qzT;
  c2_vj_x = c2_uj_x;
  c2_vj_x = muDoubleScalarCos(c2_vj_x);
  c2_wj_x = c2_qxT;
  c2_xj_x = c2_wj_x;
  c2_xj_x = muDoubleScalarSin(c2_xj_x);
  c2_yj_x = c2_qzT;
  c2_ak_x = c2_yj_x;
  c2_ak_x = muDoubleScalarSin(c2_ak_x);
  c2_bk_x = c2_qyT;
  c2_ck_x = c2_bk_x;
  c2_ck_x = muDoubleScalarSin(c2_ck_x);
  c2_dk_x = c2_qxT;
  c2_ek_x = c2_dk_x;
  c2_ek_x = muDoubleScalarSin(c2_ek_x);
  c2_fk_x = c2_qzT;
  c2_gk_x = c2_fk_x;
  c2_gk_x = muDoubleScalarSin(c2_gk_x);
  c2_hk_x = c2_qyT;
  c2_ik_x = c2_hk_x;
  c2_ik_x = muDoubleScalarSin(c2_ik_x);
  c2_jk_x = c2_qxT;
  c2_kk_x = c2_jk_x;
  c2_kk_x = muDoubleScalarCos(c2_kk_x);
  c2_lk_x = c2_qzT;
  c2_mk_x = c2_lk_x;
  c2_mk_x = muDoubleScalarCos(c2_mk_x);
  c2_nk_x = c2_qyT;
  c2_ok_x = c2_nk_x;
  c2_ok_x = muDoubleScalarSin(c2_ok_x);
  c2_pk_x = c2_qzT;
  c2_qk_x = c2_pk_x;
  c2_qk_x = muDoubleScalarCos(c2_qk_x);
  c2_rk_x = c2_qyT;
  c2_sk_x = c2_rk_x;
  c2_sk_x = muDoubleScalarCos(c2_sk_x);
  c2_tk_x = c2_qxT;
  c2_uk_x = c2_tk_x;
  c2_uk_x = muDoubleScalarSin(c2_uk_x);
  c2_vk_x = c2_qzT;
  c2_wk_x = c2_vk_x;
  c2_wk_x = muDoubleScalarCos(c2_wk_x);
  c2_xk_x = c2_qyT;
  c2_yk_x = c2_xk_x;
  c2_yk_x = muDoubleScalarCos(c2_yk_x);
  c2_al_x = c2_qxT;
  c2_bl_x = c2_al_x;
  c2_bl_x = muDoubleScalarCos(c2_bl_x);
  c2_cl_x = c2_qzT;
  c2_dl_x = c2_cl_x;
  c2_dl_x = muDoubleScalarSin(c2_dl_x);
  c2_el_x = c2_qxT;
  c2_fl_x = c2_el_x;
  c2_fl_x = muDoubleScalarSin(c2_fl_x);
  c2_gl_x = c2_qzT;
  c2_hl_x = c2_gl_x;
  c2_hl_x = muDoubleScalarCos(c2_hl_x);
  c2_il_x = c2_qyT;
  c2_jl_x = c2_il_x;
  c2_jl_x = muDoubleScalarSin(c2_jl_x);
  c2_kl_x = c2_qxT;
  c2_ll_x = c2_kl_x;
  c2_ll_x = muDoubleScalarCos(c2_ll_x);
  c2_ml_x = c2_qzT;
  c2_nl_x = c2_ml_x;
  c2_nl_x = muDoubleScalarSin(c2_nl_x);
  c2_ol_x = c2_qxT;
  c2_pl_x = c2_ol_x;
  c2_pl_x = muDoubleScalarCos(c2_pl_x);
  c2_ql_x = c2_qzT;
  c2_rl_x = c2_ql_x;
  c2_rl_x = muDoubleScalarCos(c2_rl_x);
  c2_sl_x = c2_qyT;
  c2_tl_x = c2_sl_x;
  c2_tl_x = muDoubleScalarSin(c2_tl_x);
  c2_ul_x = c2_qxT;
  c2_vl_x = c2_ul_x;
  c2_vl_x = muDoubleScalarSin(c2_vl_x);
  c2_wl_x = c2_qzT;
  c2_xl_x = c2_wl_x;
  c2_xl_x = muDoubleScalarSin(c2_xl_x);
  c2_yl_x = c2_qyT;
  c2_am_x = c2_yl_x;
  c2_am_x = muDoubleScalarCos(c2_am_x);
  c2_bm_x = c2_qzT;
  c2_cm_x = c2_bm_x;
  c2_cm_x = muDoubleScalarSin(c2_cm_x);
  c2_dm_x = c2_qyT;
  c2_em_x = c2_dm_x;
  c2_em_x = muDoubleScalarSin(c2_em_x);
  c2_fm_x = c2_qxT;
  c2_gm_x = c2_fm_x;
  c2_gm_x = muDoubleScalarSin(c2_gm_x);
  c2_hm_x = c2_qzT;
  c2_im_x = c2_hm_x;
  c2_im_x = muDoubleScalarSin(c2_im_x);
  c2_jm_x = c2_qyT;
  c2_km_x = c2_jm_x;
  c2_km_x = muDoubleScalarSin(c2_km_x);
  c2_lm_x = c2_qxT;
  c2_mm_x = c2_lm_x;
  c2_mm_x = muDoubleScalarCos(c2_mm_x);
  c2_nm_x = c2_qzT;
  c2_om_x = c2_nm_x;
  c2_om_x = muDoubleScalarSin(c2_om_x);
  c2_pm_x = c2_qyT;
  c2_qm_x = c2_pm_x;
  c2_qm_x = muDoubleScalarCos(c2_qm_x);
  c2_rm_x = c2_qxT;
  c2_sm_x = c2_rm_x;
  c2_sm_x = muDoubleScalarCos(c2_sm_x);
  c2_tm_x = c2_qzT;
  c2_um_x = c2_tm_x;
  c2_um_x = muDoubleScalarSin(c2_um_x);
  c2_vm_x = c2_qyT;
  c2_wm_x = c2_vm_x;
  c2_wm_x = muDoubleScalarCos(c2_wm_x);
  c2_xm_x = c2_qxT;
  c2_ym_x = c2_xm_x;
  c2_ym_x = muDoubleScalarSin(c2_ym_x);
  c2_an_x = c2_qzT;
  c2_bn_x = c2_an_x;
  c2_bn_x = muDoubleScalarCos(c2_bn_x);
  c2_cn_x = c2_qxT;
  c2_dn_x = c2_cn_x;
  c2_dn_x = muDoubleScalarCos(c2_dn_x);
  c2_en_x = c2_qzT;
  c2_fn_x = c2_en_x;
  c2_fn_x = muDoubleScalarCos(c2_fn_x);
  c2_gn_x = c2_qxT;
  c2_hn_x = c2_gn_x;
  c2_hn_x = muDoubleScalarSin(c2_hn_x);
  c2_in_x = c2_qzT;
  c2_jn_x = c2_in_x;
  c2_jn_x = muDoubleScalarSin(c2_jn_x);
  c2_kn_x = c2_qyT;
  c2_ln_x = c2_kn_x;
  c2_ln_x = muDoubleScalarSin(c2_ln_x);
  c2_mn_x = c2_qxT;
  c2_nn_x = c2_mn_x;
  c2_nn_x = muDoubleScalarSin(c2_nn_x);
  c2_on_x = c2_qzT;
  c2_pn_x = c2_on_x;
  c2_pn_x = muDoubleScalarSin(c2_pn_x);
  c2_qn_x = c2_qyT;
  c2_rn_x = c2_qn_x;
  c2_rn_x = muDoubleScalarSin(c2_rn_x);
  c2_sn_x = c2_qxT;
  c2_tn_x = c2_sn_x;
  c2_tn_x = muDoubleScalarCos(c2_tn_x);
  c2_jacob_jacob_pB0[1] = (((((((((((((((((((-c2_mpower(chartInstance, c2_dqzT) *
    c2_nj_x * c2_pj_x * c2_xB - c2_mpower(chartInstance, c2_dqzT) * c2_yB *
    c2_rj_x * c2_tj_x) + c2_mpower(chartInstance, c2_dqzT) * c2_zB * c2_vj_x *
    c2_xj_x) - c2_mpower(chartInstance, c2_dqzT) * c2_yB * c2_ak_x * c2_ck_x *
    c2_ek_x) - c2_mpower(chartInstance, c2_dqzT) * c2_zB * c2_gk_x * c2_ik_x *
    c2_kk_x) - 2.0 * c2_dqzT * c2_mk_x * c2_dqyT * c2_ok_x * c2_xB) + 2.0 *
    c2_dqzT * c2_qk_x * c2_dqyT * c2_sk_x * c2_uk_x * c2_yB) + 2.0 * c2_dqzT *
    c2_wk_x * c2_dqyT * c2_yk_x * c2_bl_x * c2_zB) + 2.0 * c2_dqzT * c2_dqxT *
    c2_yB * c2_dl_x * c2_fl_x) + 2.0 * c2_dqzT * c2_dqxT * c2_yB * c2_hl_x *
    c2_jl_x * c2_ll_x) + 2.0 * c2_dqzT * c2_dqxT * c2_zB * c2_nl_x * c2_pl_x) -
    2.0 * c2_dqzT * c2_dqxT * c2_zB * c2_rl_x * c2_tl_x * c2_vl_x) - c2_xl_x *
    c2_mpower(chartInstance, c2_dqyT) * c2_am_x * c2_xB) - c2_cm_x * c2_mpower
    (chartInstance, c2_dqyT) * c2_em_x * c2_gm_x * c2_yB) - c2_im_x * c2_mpower
    (chartInstance, c2_dqyT) * c2_km_x * c2_mm_x * c2_zB) + 2.0 * c2_dqyT *
    c2_dqxT * c2_yB * c2_om_x * c2_qm_x * c2_sm_x) - 2.0 * c2_dqyT * c2_dqxT *
    c2_zB * c2_um_x * c2_wm_x * c2_ym_x) - c2_mpower(chartInstance, c2_dqxT) *
    c2_yB * c2_bn_x * c2_dn_x) + c2_mpower(chartInstance, c2_dqxT) * c2_zB *
    c2_fn_x * c2_hn_x) - c2_mpower(chartInstance, c2_dqxT) * c2_yB * c2_jn_x *
    c2_ln_x * c2_nn_x) - c2_mpower(chartInstance, c2_dqxT) * c2_zB * c2_pn_x *
    c2_rn_x * c2_tn_x;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 78);
  c2_un_x = c2_qyT;
  c2_vn_x = c2_un_x;
  c2_vn_x = muDoubleScalarSin(c2_vn_x);
  c2_wn_x = c2_qyT;
  c2_xn_x = c2_wn_x;
  c2_xn_x = muDoubleScalarCos(c2_xn_x);
  c2_yn_x = c2_qxT;
  c2_ao_x = c2_yn_x;
  c2_ao_x = muDoubleScalarSin(c2_ao_x);
  c2_bo_x = c2_qyT;
  c2_co_x = c2_bo_x;
  c2_co_x = muDoubleScalarCos(c2_co_x);
  c2_do_x = c2_qxT;
  c2_eo_x = c2_do_x;
  c2_eo_x = muDoubleScalarCos(c2_eo_x);
  c2_fo_x = c2_qyT;
  c2_go_x = c2_fo_x;
  c2_go_x = muDoubleScalarSin(c2_go_x);
  c2_ho_x = c2_qxT;
  c2_io_x = c2_ho_x;
  c2_io_x = muDoubleScalarCos(c2_io_x);
  c2_jo_x = c2_qyT;
  c2_ko_x = c2_jo_x;
  c2_ko_x = muDoubleScalarSin(c2_ko_x);
  c2_lo_x = c2_qxT;
  c2_mo_x = c2_lo_x;
  c2_mo_x = muDoubleScalarSin(c2_mo_x);
  c2_no_x = c2_qyT;
  c2_oo_x = c2_no_x;
  c2_oo_x = muDoubleScalarCos(c2_oo_x);
  c2_po_x = c2_qxT;
  c2_qo_x = c2_po_x;
  c2_qo_x = muDoubleScalarSin(c2_qo_x);
  c2_ro_x = c2_qyT;
  c2_so_x = c2_ro_x;
  c2_so_x = muDoubleScalarCos(c2_so_x);
  c2_to_x = c2_qxT;
  c2_uo_x = c2_to_x;
  c2_uo_x = muDoubleScalarCos(c2_uo_x);
  c2_jacob_jacob_pB0[2] = (((((c2_mpower(chartInstance, c2_dqyT) * c2_vn_x *
    c2_xB - c2_mpower(chartInstance, c2_dqyT) * c2_xn_x * c2_ao_x * c2_yB) -
    c2_mpower(chartInstance, c2_dqyT) * c2_co_x * c2_eo_x * c2_zB) - 2.0 *
    c2_dqyT * c2_go_x * c2_dqxT * c2_io_x * c2_yB) + 2.0 * c2_dqyT * c2_ko_x *
    c2_dqxT * c2_mo_x * c2_zB) - c2_oo_x * c2_mpower(chartInstance, c2_dqxT) *
    c2_qo_x * c2_yB) - c2_so_x * c2_mpower(chartInstance, c2_dqxT) * c2_uo_x *
    c2_zB;
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, 84);
  _SFD_SCRIPT_CALL(1U, chartInstance->c2_sfEvent, -84);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c2_BoomPositionHip_FixParams(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c2_q[16], real_T c2_b_BoomParams[3], real_T c2_pB0[3])
{
  uint32_T c2_debug_family_var_map[24];
  real_T c2_xT;
  real_T c2_yT;
  real_T c2_zT;
  real_T c2_qzT;
  real_T c2_qyT;
  real_T c2_qxT;
  real_T c2_q1R;
  real_T c2_q2R;
  real_T c2_q1L;
  real_T c2_q2L;
  real_T c2_qgr1R;
  real_T c2_qgr2R;
  real_T c2_q3R;
  real_T c2_qgr1L;
  real_T c2_qgr2L;
  real_T c2_q3L;
  real_T c2_xB;
  real_T c2_yB;
  real_T c2_zB;
  real_T c2_nargin = 2.0;
  real_T c2_nargout = 1.0;
  int32_T c2_i172;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_x_x;
  real_T c2_y_x;
  real_T c2_ab_x;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_db_x;
  real_T c2_eb_x;
  real_T c2_fb_x;
  real_T c2_gb_x;
  real_T c2_hb_x;
  real_T c2_ib_x;
  real_T c2_jb_x;
  real_T c2_kb_x;
  real_T c2_lb_x;
  real_T c2_mb_x;
  real_T c2_nb_x;
  real_T c2_ob_x;
  real_T c2_pb_x;
  real_T c2_qb_x;
  real_T c2_rb_x;
  real_T c2_sb_x;
  real_T c2_tb_x;
  real_T c2_ub_x;
  real_T c2_vb_x;
  real_T c2_wb_x;
  real_T c2_xb_x;
  real_T c2_yb_x;
  real_T c2_ac_x;
  real_T c2_bc_x;
  real_T c2_cc_x;
  real_T c2_dc_x;
  real_T c2_ec_x;
  real_T c2_fc_x;
  real_T c2_gc_x;
  real_T c2_hc_x;
  real_T c2_ic_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 24U, 24U, c2_d_debug_family_names,
    c2_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_xT, 0U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_yT, 1U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_zT, 2U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qzT, 3U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qyT, 4U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qxT, 5U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q1R, 6U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q2R, 7U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q1L, 8U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q2L, 9U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qgr1R, 10U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qgr2R, 11U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q3R, 12U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qgr1L, 13U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_qgr2L, 14U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_q3L, 15U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_xB, 16U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_yB, 17U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_zB, 18U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargin, 19U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c2_nargout, 20U, c2_b_sf_marshallOut,
    c2_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_q, 21U, c2_e_sf_marshallOut,
    c2_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_b_BoomParams, 22U, c2_k_sf_marshallOut,
    c2_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c2_pB0, 23U, c2_k_sf_marshallOut,
    c2_i_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 8);
  c2_xT = c2_q[0];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 9);
  c2_yT = c2_q[1];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 10);
  c2_zT = c2_q[2];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 11);
  c2_qzT = c2_q[3];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 12);
  c2_qyT = c2_q[4];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 13);
  c2_qxT = c2_q[5];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 14);
  c2_q1R = c2_q[6];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 15);
  c2_q2R = c2_q[7];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 16);
  c2_q1L = c2_q[8];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 17);
  c2_q2L = c2_q[9];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 18);
  c2_qgr1R = c2_q[10];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 19);
  c2_qgr2R = c2_q[11];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 20);
  c2_q3R = c2_q[12];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 21);
  c2_qgr1L = c2_q[13];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 22);
  c2_qgr2L = c2_q[14];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 23);
  c2_q3L = c2_q[15];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 24);
  c2_xB = c2_b_BoomParams[0];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 25);
  c2_yB = c2_b_BoomParams[1];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 26);
  c2_zB = c2_b_BoomParams[2];
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 29);
  for (c2_i172 = 0; c2_i172 < 3; c2_i172++) {
    c2_pB0[c2_i172] = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 30);
  c2_b_x = c2_qzT;
  c2_c_x = c2_b_x;
  c2_c_x = muDoubleScalarCos(c2_c_x);
  c2_d_x = c2_qyT;
  c2_e_x = c2_d_x;
  c2_e_x = muDoubleScalarCos(c2_e_x);
  c2_f_x = c2_qzT;
  c2_g_x = c2_f_x;
  c2_g_x = muDoubleScalarSin(c2_g_x);
  c2_h_x = c2_qxT;
  c2_i_x = c2_h_x;
  c2_i_x = muDoubleScalarCos(c2_i_x);
  c2_j_x = c2_qzT;
  c2_k_x = c2_j_x;
  c2_k_x = muDoubleScalarCos(c2_k_x);
  c2_l_x = c2_qyT;
  c2_m_x = c2_l_x;
  c2_m_x = muDoubleScalarSin(c2_m_x);
  c2_n_x = c2_qxT;
  c2_o_x = c2_n_x;
  c2_o_x = muDoubleScalarSin(c2_o_x);
  c2_p_x = c2_qzT;
  c2_q_x = c2_p_x;
  c2_q_x = muDoubleScalarSin(c2_q_x);
  c2_r_x = c2_qxT;
  c2_s_x = c2_r_x;
  c2_s_x = muDoubleScalarSin(c2_s_x);
  c2_t_x = c2_qzT;
  c2_u_x = c2_t_x;
  c2_u_x = muDoubleScalarCos(c2_u_x);
  c2_v_x = c2_qyT;
  c2_w_x = c2_v_x;
  c2_w_x = muDoubleScalarSin(c2_w_x);
  c2_x_x = c2_qxT;
  c2_y_x = c2_x_x;
  c2_y_x = muDoubleScalarCos(c2_y_x);
  c2_pB0[0] = ((c2_xT + c2_c_x * c2_e_x * c2_xB) + (-c2_g_x * c2_i_x + c2_k_x *
    c2_m_x * c2_o_x) * c2_yB) + (c2_q_x * c2_s_x + c2_u_x * c2_w_x * c2_y_x) *
    c2_zB;
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 33);
  c2_ab_x = c2_qzT;
  c2_bb_x = c2_ab_x;
  c2_bb_x = muDoubleScalarSin(c2_bb_x);
  c2_cb_x = c2_qyT;
  c2_db_x = c2_cb_x;
  c2_db_x = muDoubleScalarCos(c2_db_x);
  c2_eb_x = c2_qzT;
  c2_fb_x = c2_eb_x;
  c2_fb_x = muDoubleScalarCos(c2_fb_x);
  c2_gb_x = c2_qxT;
  c2_hb_x = c2_gb_x;
  c2_hb_x = muDoubleScalarCos(c2_hb_x);
  c2_ib_x = c2_qzT;
  c2_jb_x = c2_ib_x;
  c2_jb_x = muDoubleScalarSin(c2_jb_x);
  c2_kb_x = c2_qyT;
  c2_lb_x = c2_kb_x;
  c2_lb_x = muDoubleScalarSin(c2_lb_x);
  c2_mb_x = c2_qxT;
  c2_nb_x = c2_mb_x;
  c2_nb_x = muDoubleScalarSin(c2_nb_x);
  c2_ob_x = c2_qzT;
  c2_pb_x = c2_ob_x;
  c2_pb_x = muDoubleScalarCos(c2_pb_x);
  c2_qb_x = c2_qxT;
  c2_rb_x = c2_qb_x;
  c2_rb_x = muDoubleScalarSin(c2_rb_x);
  c2_sb_x = c2_qzT;
  c2_tb_x = c2_sb_x;
  c2_tb_x = muDoubleScalarSin(c2_tb_x);
  c2_ub_x = c2_qyT;
  c2_vb_x = c2_ub_x;
  c2_vb_x = muDoubleScalarSin(c2_vb_x);
  c2_wb_x = c2_qxT;
  c2_xb_x = c2_wb_x;
  c2_xb_x = muDoubleScalarCos(c2_xb_x);
  c2_pB0[1] = ((c2_yT + c2_bb_x * c2_db_x * c2_xB) + (c2_fb_x * c2_hb_x +
    c2_jb_x * c2_lb_x * c2_nb_x) * c2_yB) + (-c2_pb_x * c2_rb_x + c2_tb_x *
    c2_vb_x * c2_xb_x) * c2_zB;
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 36);
  c2_yb_x = c2_qyT;
  c2_ac_x = c2_yb_x;
  c2_ac_x = muDoubleScalarSin(c2_ac_x);
  c2_bc_x = c2_qyT;
  c2_cc_x = c2_bc_x;
  c2_cc_x = muDoubleScalarCos(c2_cc_x);
  c2_dc_x = c2_qxT;
  c2_ec_x = c2_dc_x;
  c2_ec_x = muDoubleScalarSin(c2_ec_x);
  c2_fc_x = c2_qyT;
  c2_gc_x = c2_fc_x;
  c2_gc_x = muDoubleScalarCos(c2_gc_x);
  c2_hc_x = c2_qxT;
  c2_ic_x = c2_hc_x;
  c2_ic_x = muDoubleScalarCos(c2_ic_x);
  c2_pB0[2] = ((c2_zT - c2_ac_x * c2_xB) + c2_cc_x * c2_ec_x * c2_yB) + c2_gc_x *
    c2_ic_x * c2_zB;
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, 40);
  _SFD_SCRIPT_CALL(2U, chartInstance->c2_sfEvent, -40);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c2_machineNumber, uint32_T
  c2_chartNumber, uint32_T c2_instanceNumber)
{
  (void)c2_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, c2_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Sims\\Model\\ATRIAS3D_Spring_Constants.m"));
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, c2_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Sims\\Model\\JacobBoomHip_FixParams.m"));
  _SFD_SCRIPT_TRANSLATION(c2_chartNumber, c2_instanceNumber, 2U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Sims\\Model\\BoomPositionHip_FixParams.m"));
}

static const mxArray *c2_sf_marshallOut(void *chartInstanceVoid, void *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i173;
  real_T c2_b_inData[32];
  int32_T c2_i174;
  real_T c2_b_u[32];
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i173 = 0; c2_i173 < 32; c2_i173++) {
    c2_b_inData[c2_i173] = (*(real_T (*)[32])c2_inData)[c2_i173];
  }

  for (c2_i174 = 0; c2_i174 < 32; c2_i174++) {
    c2_b_u[c2_i174] = c2_b_inData[c2_i174];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  const mxArray *c2_b_x_dot, const char_T *c2_identifier, real_T c2_y[32])
{
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_x_dot), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_x_dot);
}

static void c2_b_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[32])
{
  real_T c2_dv9[32];
  int32_T c2_i175;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv9, 1, 0, 0U, 1, 0U, 1, 32);
  for (c2_i175 = 0; c2_i175 < 32; c2_i175++) {
    c2_y[c2_i175] = c2_dv9[c2_i175];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_x_dot;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[32];
  int32_T c2_i176;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_b_x_dot = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_x_dot), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_b_x_dot);
  for (c2_i176 = 0; c2_i176 < 32; c2_i176++) {
    (*(real_T (*)[32])c2_outData)[c2_i176] = c2_y[c2_i176];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_b_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  real_T c2_b_u;
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(real_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_c_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i177;
  real_T c2_b_inData[3];
  int32_T c2_i178;
  real_T c2_b_u[3];
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i177 = 0; c2_i177 < 3; c2_i177++) {
    c2_b_inData[c2_i177] = (*(real_T (*)[3])c2_inData)[c2_i177];
  }

  for (c2_i178 = 0; c2_i178 < 3; c2_i178++) {
    c2_b_u[c2_i178] = c2_b_inData[c2_i178];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 3, 1), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_c_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3])
{
  real_T c2_dv10[3];
  int32_T c2_i179;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv10, 1, 0, 0U, 1, 0U, 2, 3,
                1);
  for (c2_i179 = 0; c2_i179 < 3; c2_i179++) {
    c2_y[c2_i179] = c2_dv10[c2_i179];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_pBInitial;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i180;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_b_pBInitial = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_pBInitial), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_b_pBInitial);
  for (c2_i180 = 0; c2_i180 < 3; c2_i180++) {
    (*(real_T (*)[3])c2_outData)[c2_i180] = c2_y[c2_i180];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static real_T c2_d_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  real_T c2_y;
  real_T c2_d3;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_d3, 1, 0, 0U, 0, 0U, 0);
  c2_y = c2_d3;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void c2_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_ProjectTo2D;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_b_ProjectTo2D = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_ProjectTo2D),
    &c2_thisId);
  sf_mex_destroy(&c2_b_ProjectTo2D);
  *(real_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_d_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i181;
  real_T c2_b_inData[6];
  int32_T c2_i182;
  real_T c2_b_u[6];
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i181 = 0; c2_i181 < 6; c2_i181++) {
    c2_b_inData[c2_i181] = (*(real_T (*)[6])c2_inData)[c2_i181];
  }

  for (c2_i182 = 0; c2_i182 < 6; c2_i182++) {
    c2_b_u[c2_i182] = c2_b_inData[c2_i182];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_e_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i183;
  real_T c2_b_inData[16];
  int32_T c2_i184;
  real_T c2_b_u[16];
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i183 = 0; c2_i183 < 16; c2_i183++) {
    c2_b_inData[c2_i183] = (*(real_T (*)[16])c2_inData)[c2_i183];
  }

  for (c2_i184 = 0; c2_i184 < 16; c2_i184++) {
    c2_b_u[c2_i184] = c2_b_inData[c2_i184];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 16), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_f_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i185;
  int32_T c2_i186;
  int32_T c2_i187;
  real_T c2_b_inData[96];
  int32_T c2_i188;
  int32_T c2_i189;
  int32_T c2_i190;
  real_T c2_b_u[96];
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i185 = 0;
  for (c2_i186 = 0; c2_i186 < 6; c2_i186++) {
    for (c2_i187 = 0; c2_i187 < 16; c2_i187++) {
      c2_b_inData[c2_i187 + c2_i185] = (*(real_T (*)[96])c2_inData)[c2_i187 +
        c2_i185];
    }

    c2_i185 += 16;
  }

  c2_i188 = 0;
  for (c2_i189 = 0; c2_i189 < 6; c2_i189++) {
    for (c2_i190 = 0; c2_i190 < 16; c2_i190++) {
      c2_b_u[c2_i190 + c2_i188] = c2_b_inData[c2_i190 + c2_i188];
    }

    c2_i188 += 16;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 16, 6),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_g_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i191;
  int32_T c2_i192;
  int32_T c2_i193;
  real_T c2_b_inData[256];
  int32_T c2_i194;
  int32_T c2_i195;
  int32_T c2_i196;
  real_T c2_b_u[256];
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i191 = 0;
  for (c2_i192 = 0; c2_i192 < 16; c2_i192++) {
    for (c2_i193 = 0; c2_i193 < 16; c2_i193++) {
      c2_b_inData[c2_i193 + c2_i191] = (*(real_T (*)[256])c2_inData)[c2_i193 +
        c2_i191];
    }

    c2_i191 += 16;
  }

  c2_i194 = 0;
  for (c2_i195 = 0; c2_i195 < 16; c2_i195++) {
    for (c2_i196 = 0; c2_i196 < 16; c2_i196++) {
      c2_b_u[c2_i196 + c2_i194] = c2_b_inData[c2_i196 + c2_i194];
    }

    c2_i194 += 16;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 16, 16),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static const mxArray *c2_h_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i197;
  real_T c2_b_inData[5];
  int32_T c2_i198;
  real_T c2_b_u[5];
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i197 = 0; c2_i197 < 5; c2_i197++) {
    c2_b_inData[c2_i197] = (*(real_T (*)[5])c2_inData)[c2_i197];
  }

  for (c2_i198 = 0; c2_i198 < 5; c2_i198++) {
    c2_b_u[c2_i198] = c2_b_inData[c2_i198];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_e_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[5])
{
  real_T c2_dv11[5];
  int32_T c2_i199;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv11, 1, 0, 0U, 1, 0U, 1, 5);
  for (c2_i199 = 0; c2_i199 < 5; c2_i199++) {
    c2_y[c2_i199] = c2_dv11[c2_i199];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_v_con;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[5];
  int32_T c2_i200;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_v_con = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_v_con), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_v_con);
  for (c2_i200 = 0; c2_i200 < 5; c2_i200++) {
    (*(real_T (*)[5])c2_outData)[c2_i200] = c2_y[c2_i200];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_f_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[16])
{
  real_T c2_dv12[16];
  int32_T c2_i201;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv12, 1, 0, 0U, 1, 0U, 1, 16);
  for (c2_i201 = 0; c2_i201 < 16; c2_i201++) {
    c2_y[c2_i201] = c2_dv12[c2_i201];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_ddq;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[16];
  int32_T c2_i202;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_ddq = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_ddq), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_ddq);
  for (c2_i202 = 0; c2_i202 < 16; c2_i202++) {
    (*(real_T (*)[16])c2_outData)[c2_i202] = c2_y[c2_i202];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static void c2_g_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[256])
{
  real_T c2_dv13[256];
  int32_T c2_i203;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv13, 1, 0, 0U, 1, 0U, 2, 16,
                16);
  for (c2_i203 = 0; c2_i203 < 256; c2_i203++) {
    c2_y[c2_i203] = c2_dv13[c2_i203];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_P;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[256];
  int32_T c2_i204;
  int32_T c2_i205;
  int32_T c2_i206;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_P = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_P), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_P);
  c2_i204 = 0;
  for (c2_i205 = 0; c2_i205 < 16; c2_i205++) {
    for (c2_i206 = 0; c2_i206 < 16; c2_i206++) {
      (*(real_T (*)[256])c2_outData)[c2_i206 + c2_i204] = c2_y[c2_i206 + c2_i204];
    }

    c2_i204 += 16;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_i_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i207;
  int32_T c2_i208;
  int32_T c2_i209;
  real_T c2_b_inData[48];
  int32_T c2_i210;
  int32_T c2_i211;
  int32_T c2_i212;
  real_T c2_b_u[48];
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i207 = 0;
  for (c2_i208 = 0; c2_i208 < 3; c2_i208++) {
    for (c2_i209 = 0; c2_i209 < 16; c2_i209++) {
      c2_b_inData[c2_i209 + c2_i207] = (*(real_T (*)[48])c2_inData)[c2_i209 +
        c2_i207];
    }

    c2_i207 += 16;
  }

  c2_i210 = 0;
  for (c2_i211 = 0; c2_i211 < 3; c2_i211++) {
    for (c2_i212 = 0; c2_i212 < 16; c2_i212++) {
      c2_b_u[c2_i212 + c2_i210] = c2_b_inData[c2_i212 + c2_i210];
    }

    c2_i210 += 16;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 16, 3),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_h_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[48])
{
  real_T c2_dv14[48];
  int32_T c2_i213;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv14, 1, 0, 0U, 1, 0U, 2, 16,
                3);
  for (c2_i213 = 0; c2_i213 < 48; c2_i213++) {
    c2_y[c2_i213] = c2_dv14[c2_i213];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_A;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[48];
  int32_T c2_i214;
  int32_T c2_i215;
  int32_T c2_i216;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_A = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_A), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_A);
  c2_i214 = 0;
  for (c2_i215 = 0; c2_i215 < 3; c2_i215++) {
    for (c2_i216 = 0; c2_i216 < 16; c2_i216++) {
      (*(real_T (*)[48])c2_outData)[c2_i216 + c2_i214] = c2_y[c2_i216 + c2_i214];
    }

    c2_i214 += 16;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_j_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i217;
  int32_T c2_i218;
  int32_T c2_i219;
  real_T c2_b_inData[48];
  int32_T c2_i220;
  int32_T c2_i221;
  int32_T c2_i222;
  real_T c2_b_u[48];
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i217 = 0;
  for (c2_i218 = 0; c2_i218 < 16; c2_i218++) {
    for (c2_i219 = 0; c2_i219 < 3; c2_i219++) {
      c2_b_inData[c2_i219 + c2_i217] = (*(real_T (*)[48])c2_inData)[c2_i219 +
        c2_i217];
    }

    c2_i217 += 3;
  }

  c2_i220 = 0;
  for (c2_i221 = 0; c2_i221 < 16; c2_i221++) {
    for (c2_i222 = 0; c2_i222 < 3; c2_i222++) {
      c2_b_u[c2_i222 + c2_i220] = c2_b_inData[c2_i222 + c2_i220];
    }

    c2_i220 += 3;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 3, 16),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_i_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[48])
{
  real_T c2_dv15[48];
  int32_T c2_i223;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv15, 1, 0, 0U, 1, 0U, 2, 3,
                16);
  for (c2_i223 = 0; c2_i223 < 48; c2_i223++) {
    c2_y[c2_i223] = c2_dv15[c2_i223];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_JBoom_D;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[48];
  int32_T c2_i224;
  int32_T c2_i225;
  int32_T c2_i226;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_JBoom_D = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_JBoom_D), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_JBoom_D);
  c2_i224 = 0;
  for (c2_i225 = 0; c2_i225 < 16; c2_i225++) {
    for (c2_i226 = 0; c2_i226 < 3; c2_i226++) {
      (*(real_T (*)[48])c2_outData)[c2_i226 + c2_i224] = c2_y[c2_i226 + c2_i224];
    }

    c2_i224 += 3;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_k_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i227;
  real_T c2_b_inData[3];
  int32_T c2_i228;
  real_T c2_b_u[3];
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  for (c2_i227 = 0; c2_i227 < 3; c2_i227++) {
    c2_b_inData[c2_i227] = (*(real_T (*)[3])c2_inData)[c2_i227];
  }

  for (c2_i228 = 0; c2_i228 < 3; c2_i228++) {
    c2_b_u[c2_i228] = c2_b_inData[c2_i228];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_j_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[3])
{
  real_T c2_dv16[3];
  int32_T c2_i229;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv16, 1, 0, 0U, 1, 0U, 1, 3);
  for (c2_i229 = 0; c2_i229 < 3; c2_i229++) {
    c2_y[c2_i229] = c2_dv16[c2_i229];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_eB;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[3];
  int32_T c2_i230;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_eB = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_eB), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_eB);
  for (c2_i230 = 0; c2_i230 < 3; c2_i230++) {
    (*(real_T (*)[3])c2_outData)[c2_i230] = c2_y[c2_i230];
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_l_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i231;
  int32_T c2_i232;
  int32_T c2_i233;
  real_T c2_b_inData[80];
  int32_T c2_i234;
  int32_T c2_i235;
  int32_T c2_i236;
  real_T c2_b_u[80];
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i231 = 0;
  for (c2_i232 = 0; c2_i232 < 5; c2_i232++) {
    for (c2_i233 = 0; c2_i233 < 16; c2_i233++) {
      c2_b_inData[c2_i233 + c2_i231] = (*(real_T (*)[80])c2_inData)[c2_i233 +
        c2_i231];
    }

    c2_i231 += 16;
  }

  c2_i234 = 0;
  for (c2_i235 = 0; c2_i235 < 5; c2_i235++) {
    for (c2_i236 = 0; c2_i236 < 16; c2_i236++) {
      c2_b_u[c2_i236 + c2_i234] = c2_b_inData[c2_i236 + c2_i234];
    }

    c2_i234 += 16;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 16, 5),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_k_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[80])
{
  real_T c2_dv17[80];
  int32_T c2_i237;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv17, 1, 0, 0U, 1, 0U, 2, 16,
                5);
  for (c2_i237 = 0; c2_i237 < 80; c2_i237++) {
    c2_y[c2_i237] = c2_dv17[c2_i237];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_CinvCDinvC;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[80];
  int32_T c2_i238;
  int32_T c2_i239;
  int32_T c2_i240;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_CinvCDinvC = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_CinvCDinvC), &c2_thisId,
                        c2_y);
  sf_mex_destroy(&c2_CinvCDinvC);
  c2_i238 = 0;
  for (c2_i239 = 0; c2_i239 < 5; c2_i239++) {
    for (c2_i240 = 0; c2_i240 < 16; c2_i240++) {
      (*(real_T (*)[80])c2_outData)[c2_i240 + c2_i238] = c2_y[c2_i240 + c2_i238];
    }

    c2_i238 += 16;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

static const mxArray *c2_m_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_i241;
  int32_T c2_i242;
  int32_T c2_i243;
  real_T c2_b_inData[80];
  int32_T c2_i244;
  int32_T c2_i245;
  int32_T c2_i246;
  real_T c2_b_u[80];
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_i241 = 0;
  for (c2_i242 = 0; c2_i242 < 16; c2_i242++) {
    for (c2_i243 = 0; c2_i243 < 5; c2_i243++) {
      c2_b_inData[c2_i243 + c2_i241] = (*(real_T (*)[80])c2_inData)[c2_i243 +
        c2_i241];
    }

    c2_i241 += 5;
  }

  c2_i244 = 0;
  for (c2_i245 = 0; c2_i245 < 16; c2_i245++) {
    for (c2_i246 = 0; c2_i246 < 5; c2_i246++) {
      c2_b_u[c2_i246 + c2_i244] = c2_b_inData[c2_i246 + c2_i244];
    }

    c2_i244 += 5;
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 0, 0U, 1U, 0U, 2, 5, 16),
                false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static void c2_l_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId,
  real_T c2_y[80])
{
  real_T c2_dv18[80];
  int32_T c2_i247;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), c2_dv18, 1, 0, 0U, 1, 0U, 2, 5,
                16);
  for (c2_i247 = 0; c2_i247 < 80; c2_i247++) {
    c2_y[c2_i247] = c2_dv18[c2_i247];
  }

  sf_mex_destroy(&c2_b_u);
}

static void c2_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_CDinv;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  real_T c2_y[80];
  int32_T c2_i248;
  int32_T c2_i249;
  int32_T c2_i250;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_CDinv = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_CDinv), &c2_thisId, c2_y);
  sf_mex_destroy(&c2_CDinv);
  c2_i248 = 0;
  for (c2_i249 = 0; c2_i249 < 16; c2_i249++) {
    for (c2_i250 = 0; c2_i250 < 5; c2_i250++) {
      (*(real_T (*)[80])c2_outData)[c2_i250 + c2_i248] = c2_y[c2_i250 + c2_i248];
    }

    c2_i248 += 5;
  }

  sf_mex_destroy(&c2_mxArrayInData);
}

const mxArray *sf_c2_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void)
{
  const mxArray *c2_nameCaptureInfo = NULL;
  c2_nameCaptureInfo = NULL;
  sf_mex_assign(&c2_nameCaptureInfo, sf_mex_createstruct("structure", 2, 192, 1),
                false);
  c2_info_helper(&c2_nameCaptureInfo);
  c2_b_info_helper(&c2_nameCaptureInfo);
  c2_c_info_helper(&c2_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c2_nameCaptureInfo);
  return c2_nameCaptureInfo;
}

static void c2_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs0 = NULL;
  const mxArray *c2_lhs0 = NULL;
  const mxArray *c2_rhs1 = NULL;
  const mxArray *c2_lhs1 = NULL;
  const mxArray *c2_rhs2 = NULL;
  const mxArray *c2_lhs2 = NULL;
  const mxArray *c2_rhs3 = NULL;
  const mxArray *c2_lhs3 = NULL;
  const mxArray *c2_rhs4 = NULL;
  const mxArray *c2_lhs4 = NULL;
  const mxArray *c2_rhs5 = NULL;
  const mxArray *c2_lhs5 = NULL;
  const mxArray *c2_rhs6 = NULL;
  const mxArray *c2_lhs6 = NULL;
  const mxArray *c2_rhs7 = NULL;
  const mxArray *c2_lhs7 = NULL;
  const mxArray *c2_rhs8 = NULL;
  const mxArray *c2_lhs8 = NULL;
  const mxArray *c2_rhs9 = NULL;
  const mxArray *c2_lhs9 = NULL;
  const mxArray *c2_rhs10 = NULL;
  const mxArray *c2_lhs10 = NULL;
  const mxArray *c2_rhs11 = NULL;
  const mxArray *c2_lhs11 = NULL;
  const mxArray *c2_rhs12 = NULL;
  const mxArray *c2_lhs12 = NULL;
  const mxArray *c2_rhs13 = NULL;
  const mxArray *c2_lhs13 = NULL;
  const mxArray *c2_rhs14 = NULL;
  const mxArray *c2_lhs14 = NULL;
  const mxArray *c2_rhs15 = NULL;
  const mxArray *c2_lhs15 = NULL;
  const mxArray *c2_rhs16 = NULL;
  const mxArray *c2_lhs16 = NULL;
  const mxArray *c2_rhs17 = NULL;
  const mxArray *c2_lhs17 = NULL;
  const mxArray *c2_rhs18 = NULL;
  const mxArray *c2_lhs18 = NULL;
  const mxArray *c2_rhs19 = NULL;
  const mxArray *c2_lhs19 = NULL;
  const mxArray *c2_rhs20 = NULL;
  const mxArray *c2_lhs20 = NULL;
  const mxArray *c2_rhs21 = NULL;
  const mxArray *c2_lhs21 = NULL;
  const mxArray *c2_rhs22 = NULL;
  const mxArray *c2_lhs22 = NULL;
  const mxArray *c2_rhs23 = NULL;
  const mxArray *c2_lhs23 = NULL;
  const mxArray *c2_rhs24 = NULL;
  const mxArray *c2_lhs24 = NULL;
  const mxArray *c2_rhs25 = NULL;
  const mxArray *c2_lhs25 = NULL;
  const mxArray *c2_rhs26 = NULL;
  const mxArray *c2_lhs26 = NULL;
  const mxArray *c2_rhs27 = NULL;
  const mxArray *c2_lhs27 = NULL;
  const mxArray *c2_rhs28 = NULL;
  const mxArray *c2_lhs28 = NULL;
  const mxArray *c2_rhs29 = NULL;
  const mxArray *c2_lhs29 = NULL;
  const mxArray *c2_rhs30 = NULL;
  const mxArray *c2_lhs30 = NULL;
  const mxArray *c2_rhs31 = NULL;
  const mxArray *c2_lhs31 = NULL;
  const mxArray *c2_rhs32 = NULL;
  const mxArray *c2_lhs32 = NULL;
  const mxArray *c2_rhs33 = NULL;
  const mxArray *c2_lhs33 = NULL;
  const mxArray *c2_rhs34 = NULL;
  const mxArray *c2_lhs34 = NULL;
  const mxArray *c2_rhs35 = NULL;
  const mxArray *c2_lhs35 = NULL;
  const mxArray *c2_rhs36 = NULL;
  const mxArray *c2_lhs36 = NULL;
  const mxArray *c2_rhs37 = NULL;
  const mxArray *c2_lhs37 = NULL;
  const mxArray *c2_rhs38 = NULL;
  const mxArray *c2_lhs38 = NULL;
  const mxArray *c2_rhs39 = NULL;
  const mxArray *c2_lhs39 = NULL;
  const mxArray *c2_rhs40 = NULL;
  const mxArray *c2_lhs40 = NULL;
  const mxArray *c2_rhs41 = NULL;
  const mxArray *c2_lhs41 = NULL;
  const mxArray *c2_rhs42 = NULL;
  const mxArray *c2_lhs42 = NULL;
  const mxArray *c2_rhs43 = NULL;
  const mxArray *c2_lhs43 = NULL;
  const mxArray *c2_rhs44 = NULL;
  const mxArray *c2_lhs44 = NULL;
  const mxArray *c2_rhs45 = NULL;
  const mxArray *c2_lhs45 = NULL;
  const mxArray *c2_rhs46 = NULL;
  const mxArray *c2_lhs46 = NULL;
  const mxArray *c2_rhs47 = NULL;
  const mxArray *c2_lhs47 = NULL;
  const mxArray *c2_rhs48 = NULL;
  const mxArray *c2_lhs48 = NULL;
  const mxArray *c2_rhs49 = NULL;
  const mxArray *c2_lhs49 = NULL;
  const mxArray *c2_rhs50 = NULL;
  const mxArray *c2_lhs50 = NULL;
  const mxArray *c2_rhs51 = NULL;
  const mxArray *c2_lhs51 = NULL;
  const mxArray *c2_rhs52 = NULL;
  const mxArray *c2_lhs52 = NULL;
  const mxArray *c2_rhs53 = NULL;
  const mxArray *c2_lhs53 = NULL;
  const mxArray *c2_rhs54 = NULL;
  const mxArray *c2_lhs54 = NULL;
  const mxArray *c2_rhs55 = NULL;
  const mxArray *c2_lhs55 = NULL;
  const mxArray *c2_rhs56 = NULL;
  const mxArray *c2_lhs56 = NULL;
  const mxArray *c2_rhs57 = NULL;
  const mxArray *c2_lhs57 = NULL;
  const mxArray *c2_rhs58 = NULL;
  const mxArray *c2_lhs58 = NULL;
  const mxArray *c2_rhs59 = NULL;
  const mxArray *c2_lhs59 = NULL;
  const mxArray *c2_rhs60 = NULL;
  const mxArray *c2_lhs60 = NULL;
  const mxArray *c2_rhs61 = NULL;
  const mxArray *c2_lhs61 = NULL;
  const mxArray *c2_rhs62 = NULL;
  const mxArray *c2_lhs62 = NULL;
  const mxArray *c2_rhs63 = NULL;
  const mxArray *c2_lhs63 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("ATRIAS3D_Spring_Constants"),
                  "name", "name", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/ATRIAS3D_Spring_Constants.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1444269963U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c2_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/ATRIAS3D_Spring_Constants.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("sqrt"), "name", "name", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343851986U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c2_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_error"), "name", "name", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1343851958U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c2_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_sqrt"), "name",
                  "name", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286840338U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c2_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/ATRIAS3D_Spring_Constants.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c2_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c2_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c2_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c2_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c2_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c2_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c2_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c2_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c2_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c2_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c2_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c2_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c2_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.refblas.xgemm"),
                  "name", "name", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c2_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mpower"), "name", "name", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363731878U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c2_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c2_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("ismatrix"), "name", "name", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1331326458U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c2_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("power"), "name", "name", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395346506U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c2_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c2_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c2_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c2_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c2_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("floor"), "name", "name", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c2_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c2_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c2_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c2_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mrdivide"), "name", "name", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c2_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c2_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("ismatrix"), "name", "name", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1331326458U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c2_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_lusolve"), "name", "name",
                  33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m"), "resolved",
                  "resolved", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1370031486U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c2_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xgetrf"), "name", "name",
                  34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286840406U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c2_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "context", "context", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_lapack_xgetrf"), "name",
                  "name", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "resolved", "resolved", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286840410U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c2_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "context", "context", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_matlab_zgetrf"), "name",
                  "name", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "resolved", "resolved", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1302710594U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c2_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("realmin"), "name", "name", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c2_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_realmin"), "name", "name",
                  38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1307672844U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c2_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c2_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 40);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eps"), "name", "name", 40);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 40);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c2_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 41);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c2_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 42);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_eps"), "name", "name", 42);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 42);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c2_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 43);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 43);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c2_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("min"), "name", "name", 44);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 44);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 44);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c2_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 45);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 45);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 45);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c2_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 46);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 46);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 46);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 46);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c2_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 47);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 47);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c2_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 48);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 48);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 48);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c2_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 49);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 49);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 49);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c2_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 50);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 50);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c2_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 51);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 51);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 51);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 51);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c2_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 52);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 52);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 52);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c2_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 53);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("colon"), "name", "name", 53);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 53);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c2_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 54);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("colon"), "name", "name", 54);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c2_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 55);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 55);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c2_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 56);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 56);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c2_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("floor"), "name", "name", 57);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c2_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 58);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmin"), "name", "name", 58);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 58);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c2_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 59);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 59);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c2_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 60);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmax"), "name", "name", 60);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 60);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c2_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 61);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 61);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c2_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 62);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmin"), "name", "name", 62);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c2_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 63);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmax"), "name", "name", 63);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 63);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c2_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c2_rhs0);
  sf_mex_destroy(&c2_lhs0);
  sf_mex_destroy(&c2_rhs1);
  sf_mex_destroy(&c2_lhs1);
  sf_mex_destroy(&c2_rhs2);
  sf_mex_destroy(&c2_lhs2);
  sf_mex_destroy(&c2_rhs3);
  sf_mex_destroy(&c2_lhs3);
  sf_mex_destroy(&c2_rhs4);
  sf_mex_destroy(&c2_lhs4);
  sf_mex_destroy(&c2_rhs5);
  sf_mex_destroy(&c2_lhs5);
  sf_mex_destroy(&c2_rhs6);
  sf_mex_destroy(&c2_lhs6);
  sf_mex_destroy(&c2_rhs7);
  sf_mex_destroy(&c2_lhs7);
  sf_mex_destroy(&c2_rhs8);
  sf_mex_destroy(&c2_lhs8);
  sf_mex_destroy(&c2_rhs9);
  sf_mex_destroy(&c2_lhs9);
  sf_mex_destroy(&c2_rhs10);
  sf_mex_destroy(&c2_lhs10);
  sf_mex_destroy(&c2_rhs11);
  sf_mex_destroy(&c2_lhs11);
  sf_mex_destroy(&c2_rhs12);
  sf_mex_destroy(&c2_lhs12);
  sf_mex_destroy(&c2_rhs13);
  sf_mex_destroy(&c2_lhs13);
  sf_mex_destroy(&c2_rhs14);
  sf_mex_destroy(&c2_lhs14);
  sf_mex_destroy(&c2_rhs15);
  sf_mex_destroy(&c2_lhs15);
  sf_mex_destroy(&c2_rhs16);
  sf_mex_destroy(&c2_lhs16);
  sf_mex_destroy(&c2_rhs17);
  sf_mex_destroy(&c2_lhs17);
  sf_mex_destroy(&c2_rhs18);
  sf_mex_destroy(&c2_lhs18);
  sf_mex_destroy(&c2_rhs19);
  sf_mex_destroy(&c2_lhs19);
  sf_mex_destroy(&c2_rhs20);
  sf_mex_destroy(&c2_lhs20);
  sf_mex_destroy(&c2_rhs21);
  sf_mex_destroy(&c2_lhs21);
  sf_mex_destroy(&c2_rhs22);
  sf_mex_destroy(&c2_lhs22);
  sf_mex_destroy(&c2_rhs23);
  sf_mex_destroy(&c2_lhs23);
  sf_mex_destroy(&c2_rhs24);
  sf_mex_destroy(&c2_lhs24);
  sf_mex_destroy(&c2_rhs25);
  sf_mex_destroy(&c2_lhs25);
  sf_mex_destroy(&c2_rhs26);
  sf_mex_destroy(&c2_lhs26);
  sf_mex_destroy(&c2_rhs27);
  sf_mex_destroy(&c2_lhs27);
  sf_mex_destroy(&c2_rhs28);
  sf_mex_destroy(&c2_lhs28);
  sf_mex_destroy(&c2_rhs29);
  sf_mex_destroy(&c2_lhs29);
  sf_mex_destroy(&c2_rhs30);
  sf_mex_destroy(&c2_lhs30);
  sf_mex_destroy(&c2_rhs31);
  sf_mex_destroy(&c2_lhs31);
  sf_mex_destroy(&c2_rhs32);
  sf_mex_destroy(&c2_lhs32);
  sf_mex_destroy(&c2_rhs33);
  sf_mex_destroy(&c2_lhs33);
  sf_mex_destroy(&c2_rhs34);
  sf_mex_destroy(&c2_lhs34);
  sf_mex_destroy(&c2_rhs35);
  sf_mex_destroy(&c2_lhs35);
  sf_mex_destroy(&c2_rhs36);
  sf_mex_destroy(&c2_lhs36);
  sf_mex_destroy(&c2_rhs37);
  sf_mex_destroy(&c2_lhs37);
  sf_mex_destroy(&c2_rhs38);
  sf_mex_destroy(&c2_lhs38);
  sf_mex_destroy(&c2_rhs39);
  sf_mex_destroy(&c2_lhs39);
  sf_mex_destroy(&c2_rhs40);
  sf_mex_destroy(&c2_lhs40);
  sf_mex_destroy(&c2_rhs41);
  sf_mex_destroy(&c2_lhs41);
  sf_mex_destroy(&c2_rhs42);
  sf_mex_destroy(&c2_lhs42);
  sf_mex_destroy(&c2_rhs43);
  sf_mex_destroy(&c2_lhs43);
  sf_mex_destroy(&c2_rhs44);
  sf_mex_destroy(&c2_lhs44);
  sf_mex_destroy(&c2_rhs45);
  sf_mex_destroy(&c2_lhs45);
  sf_mex_destroy(&c2_rhs46);
  sf_mex_destroy(&c2_lhs46);
  sf_mex_destroy(&c2_rhs47);
  sf_mex_destroy(&c2_lhs47);
  sf_mex_destroy(&c2_rhs48);
  sf_mex_destroy(&c2_lhs48);
  sf_mex_destroy(&c2_rhs49);
  sf_mex_destroy(&c2_lhs49);
  sf_mex_destroy(&c2_rhs50);
  sf_mex_destroy(&c2_lhs50);
  sf_mex_destroy(&c2_rhs51);
  sf_mex_destroy(&c2_lhs51);
  sf_mex_destroy(&c2_rhs52);
  sf_mex_destroy(&c2_lhs52);
  sf_mex_destroy(&c2_rhs53);
  sf_mex_destroy(&c2_lhs53);
  sf_mex_destroy(&c2_rhs54);
  sf_mex_destroy(&c2_lhs54);
  sf_mex_destroy(&c2_rhs55);
  sf_mex_destroy(&c2_lhs55);
  sf_mex_destroy(&c2_rhs56);
  sf_mex_destroy(&c2_lhs56);
  sf_mex_destroy(&c2_rhs57);
  sf_mex_destroy(&c2_lhs57);
  sf_mex_destroy(&c2_rhs58);
  sf_mex_destroy(&c2_lhs58);
  sf_mex_destroy(&c2_rhs59);
  sf_mex_destroy(&c2_lhs59);
  sf_mex_destroy(&c2_rhs60);
  sf_mex_destroy(&c2_lhs60);
  sf_mex_destroy(&c2_rhs61);
  sf_mex_destroy(&c2_lhs61);
  sf_mex_destroy(&c2_rhs62);
  sf_mex_destroy(&c2_lhs62);
  sf_mex_destroy(&c2_rhs63);
  sf_mex_destroy(&c2_lhs63);
}

static const mxArray *c2_emlrt_marshallOut(const char * c2_b_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c2_b_u)), false);
  return c2_y;
}

static const mxArray *c2_b_emlrt_marshallOut(const uint32_T c2_b_u)
{
  const mxArray *c2_y = NULL;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_b_u, 7, 0U, 0U, 0U, 0), false);
  return c2_y;
}

static void c2_b_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs64 = NULL;
  const mxArray *c2_lhs64 = NULL;
  const mxArray *c2_rhs65 = NULL;
  const mxArray *c2_lhs65 = NULL;
  const mxArray *c2_rhs66 = NULL;
  const mxArray *c2_lhs66 = NULL;
  const mxArray *c2_rhs67 = NULL;
  const mxArray *c2_lhs67 = NULL;
  const mxArray *c2_rhs68 = NULL;
  const mxArray *c2_lhs68 = NULL;
  const mxArray *c2_rhs69 = NULL;
  const mxArray *c2_lhs69 = NULL;
  const mxArray *c2_rhs70 = NULL;
  const mxArray *c2_lhs70 = NULL;
  const mxArray *c2_rhs71 = NULL;
  const mxArray *c2_lhs71 = NULL;
  const mxArray *c2_rhs72 = NULL;
  const mxArray *c2_lhs72 = NULL;
  const mxArray *c2_rhs73 = NULL;
  const mxArray *c2_lhs73 = NULL;
  const mxArray *c2_rhs74 = NULL;
  const mxArray *c2_lhs74 = NULL;
  const mxArray *c2_rhs75 = NULL;
  const mxArray *c2_lhs75 = NULL;
  const mxArray *c2_rhs76 = NULL;
  const mxArray *c2_lhs76 = NULL;
  const mxArray *c2_rhs77 = NULL;
  const mxArray *c2_lhs77 = NULL;
  const mxArray *c2_rhs78 = NULL;
  const mxArray *c2_lhs78 = NULL;
  const mxArray *c2_rhs79 = NULL;
  const mxArray *c2_lhs79 = NULL;
  const mxArray *c2_rhs80 = NULL;
  const mxArray *c2_lhs80 = NULL;
  const mxArray *c2_rhs81 = NULL;
  const mxArray *c2_lhs81 = NULL;
  const mxArray *c2_rhs82 = NULL;
  const mxArray *c2_lhs82 = NULL;
  const mxArray *c2_rhs83 = NULL;
  const mxArray *c2_lhs83 = NULL;
  const mxArray *c2_rhs84 = NULL;
  const mxArray *c2_lhs84 = NULL;
  const mxArray *c2_rhs85 = NULL;
  const mxArray *c2_lhs85 = NULL;
  const mxArray *c2_rhs86 = NULL;
  const mxArray *c2_lhs86 = NULL;
  const mxArray *c2_rhs87 = NULL;
  const mxArray *c2_lhs87 = NULL;
  const mxArray *c2_rhs88 = NULL;
  const mxArray *c2_lhs88 = NULL;
  const mxArray *c2_rhs89 = NULL;
  const mxArray *c2_lhs89 = NULL;
  const mxArray *c2_rhs90 = NULL;
  const mxArray *c2_lhs90 = NULL;
  const mxArray *c2_rhs91 = NULL;
  const mxArray *c2_lhs91 = NULL;
  const mxArray *c2_rhs92 = NULL;
  const mxArray *c2_lhs92 = NULL;
  const mxArray *c2_rhs93 = NULL;
  const mxArray *c2_lhs93 = NULL;
  const mxArray *c2_rhs94 = NULL;
  const mxArray *c2_lhs94 = NULL;
  const mxArray *c2_rhs95 = NULL;
  const mxArray *c2_lhs95 = NULL;
  const mxArray *c2_rhs96 = NULL;
  const mxArray *c2_lhs96 = NULL;
  const mxArray *c2_rhs97 = NULL;
  const mxArray *c2_lhs97 = NULL;
  const mxArray *c2_rhs98 = NULL;
  const mxArray *c2_lhs98 = NULL;
  const mxArray *c2_rhs99 = NULL;
  const mxArray *c2_lhs99 = NULL;
  const mxArray *c2_rhs100 = NULL;
  const mxArray *c2_lhs100 = NULL;
  const mxArray *c2_rhs101 = NULL;
  const mxArray *c2_lhs101 = NULL;
  const mxArray *c2_rhs102 = NULL;
  const mxArray *c2_lhs102 = NULL;
  const mxArray *c2_rhs103 = NULL;
  const mxArray *c2_lhs103 = NULL;
  const mxArray *c2_rhs104 = NULL;
  const mxArray *c2_lhs104 = NULL;
  const mxArray *c2_rhs105 = NULL;
  const mxArray *c2_lhs105 = NULL;
  const mxArray *c2_rhs106 = NULL;
  const mxArray *c2_lhs106 = NULL;
  const mxArray *c2_rhs107 = NULL;
  const mxArray *c2_lhs107 = NULL;
  const mxArray *c2_rhs108 = NULL;
  const mxArray *c2_lhs108 = NULL;
  const mxArray *c2_rhs109 = NULL;
  const mxArray *c2_lhs109 = NULL;
  const mxArray *c2_rhs110 = NULL;
  const mxArray *c2_lhs110 = NULL;
  const mxArray *c2_rhs111 = NULL;
  const mxArray *c2_lhs111 = NULL;
  const mxArray *c2_rhs112 = NULL;
  const mxArray *c2_lhs112 = NULL;
  const mxArray *c2_rhs113 = NULL;
  const mxArray *c2_lhs113 = NULL;
  const mxArray *c2_rhs114 = NULL;
  const mxArray *c2_lhs114 = NULL;
  const mxArray *c2_rhs115 = NULL;
  const mxArray *c2_lhs115 = NULL;
  const mxArray *c2_rhs116 = NULL;
  const mxArray *c2_lhs116 = NULL;
  const mxArray *c2_rhs117 = NULL;
  const mxArray *c2_lhs117 = NULL;
  const mxArray *c2_rhs118 = NULL;
  const mxArray *c2_lhs118 = NULL;
  const mxArray *c2_rhs119 = NULL;
  const mxArray *c2_lhs119 = NULL;
  const mxArray *c2_rhs120 = NULL;
  const mxArray *c2_lhs120 = NULL;
  const mxArray *c2_rhs121 = NULL;
  const mxArray *c2_lhs121 = NULL;
  const mxArray *c2_rhs122 = NULL;
  const mxArray *c2_lhs122 = NULL;
  const mxArray *c2_rhs123 = NULL;
  const mxArray *c2_lhs123 = NULL;
  const mxArray *c2_rhs124 = NULL;
  const mxArray *c2_lhs124 = NULL;
  const mxArray *c2_rhs125 = NULL;
  const mxArray *c2_lhs125 = NULL;
  const mxArray *c2_rhs126 = NULL;
  const mxArray *c2_lhs126 = NULL;
  const mxArray *c2_rhs127 = NULL;
  const mxArray *c2_lhs127 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 64);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_isa_uint"), "name", "name",
                  64);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 64);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 64);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c2_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 65);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 65);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 65);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c2_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 66);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 66);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c2_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 67);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.unsignedClass"),
                  "name", "name", 67);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c2_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 68);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 68);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c2_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 69);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 69);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c2_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 70);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 70);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c2_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 71);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmax"), "name", "name", 71);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 71);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c2_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 72);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_isa_uint"), "name", "name",
                  72);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 72);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 72);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c2_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 73);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 73);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 73);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c2_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 74);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 74);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c2_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 75);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 75);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 75);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c2_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 76);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("isfi"), "name", "name", 76);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 76);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 76);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c2_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 77);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 77);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 77);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c2_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 78);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmax"), "name", "name", 78);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 78);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c2_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 79);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmin"), "name", "name", 79);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 79);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c2_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 80);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 80);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 80);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c2_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 81);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 81);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 81);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c2_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 82);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 82);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 82);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c2_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 83);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 83);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 83);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c2_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 84);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 84);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 84);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c2_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 85);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 85);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 85);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 85);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c2_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 86);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 86);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 86);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c2_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 87);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 87);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 87);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 87);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c2_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 88);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 88);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 88);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 88);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c2_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 89);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 89);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 89);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c2_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 90);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 90);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 90);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 90);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c2_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 91);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_ixamax"), "name", "name",
                  91);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "resolved", "resolved", 91);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c2_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "context", "context", 92);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 92);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 92);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c2_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "context", "context", 93);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.ixamax"),
                  "name", "name", 93);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c2_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "context", "context", 94);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 94);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 94);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c2_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                  "context", "context", 95);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 95);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 95);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 95);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c2_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                  "context", "context", 96);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("length"), "name", "name", 96);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 96);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 96);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c2_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 97);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 97);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 97);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 97);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c2_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "context", "context", 98);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.refblas.ixamax"),
                  "name", "name", 98);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 98);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c2_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 99);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.refblas.xcabs1"),
                  "name", "name", 99);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 99);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 99);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c2_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "context", "context", 100);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("abs"), "name", "name", 100);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 100);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 100);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c2_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs100), "rhs", "rhs",
                  100);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs100), "lhs", "lhs",
                  100);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 101);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 101);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 101);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c2_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs101), "rhs", "rhs",
                  101);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs101), "lhs", "lhs",
                  101);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 102);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 102);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 102);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c2_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs102), "rhs", "rhs",
                  102);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs102), "lhs", "lhs",
                  102);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 103);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 103);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 103);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c2_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs103), "rhs", "rhs",
                  103);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs103), "lhs", "lhs",
                  103);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 104);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 104);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 104);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 104);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c2_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs104), "rhs", "rhs",
                  104);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs104), "lhs", "lhs",
                  104);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 105);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xswap"), "name", "name",
                  105);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"),
                  "resolved", "resolved", 105);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c2_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs105), "rhs", "rhs",
                  105);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs105), "lhs", "lhs",
                  105);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 106);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 106);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c2_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs106), "rhs", "rhs",
                  106);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs106), "lhs", "lhs",
                  106);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 107);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.xswap"),
                  "name", "name", 107);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c2_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs107), "rhs", "rhs",
                  107);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs107), "lhs", "lhs",
                  107);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 108);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 108);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 108);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c2_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs108), "rhs", "rhs",
                  108);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs108), "lhs", "lhs",
                  108);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p!below_threshold"),
                  "context", "context", 109);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 109);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 109);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c2_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs109), "rhs", "rhs",
                  109);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs109), "lhs", "lhs",
                  109);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 110);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.refblas.xswap"),
                  "name", "name", 110);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "resolved", "resolved", 110);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c2_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs110), "rhs", "rhs",
                  110);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs110), "lhs", "lhs",
                  110);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 111);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("abs"), "name", "name", 111);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 111);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 111);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c2_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs111), "rhs", "rhs",
                  111);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs111), "lhs", "lhs",
                  111);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 112);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 112);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 112);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 112);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c2_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs112), "rhs", "rhs",
                  112);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs112), "lhs", "lhs",
                  112);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 113);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 113);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 113);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 113);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c2_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs113), "rhs", "rhs",
                  113);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs113), "lhs", "lhs",
                  113);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 114);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 114);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 114);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c2_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs114), "rhs", "rhs",
                  114);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs114), "lhs", "lhs",
                  114);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 115);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 115);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 115);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 115);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c2_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs115), "rhs", "rhs",
                  115);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs115), "lhs", "lhs",
                  115);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 116);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_div"), "name", "name", 116);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 116);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c2_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs116), "rhs", "rhs",
                  116);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs116), "lhs", "lhs",
                  116);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 117);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 117);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 117);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c2_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs117), "rhs", "rhs",
                  117);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs117), "lhs", "lhs",
                  117);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 118);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xgeru"), "name", "name",
                  118);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 118);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"),
                  "resolved", "resolved", 118);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c2_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs118), "rhs", "rhs",
                  118);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs118), "lhs", "lhs",
                  118);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 119);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 119);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 119);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 119);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c2_rhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs119), "rhs", "rhs",
                  119);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs119), "lhs", "lhs",
                  119);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 120);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.xgeru"),
                  "name", "name", 120);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 120);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                  "resolved", "resolved", 120);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c2_rhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs120), "rhs", "rhs",
                  120);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs120), "lhs", "lhs",
                  120);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                  "context", "context", 121);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.xger"),
                  "name", "name", 121);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "resolved", "resolved", 121);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c2_rhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs121), "rhs", "rhs",
                  121);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs121), "lhs", "lhs",
                  121);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "context", "context", 122);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 122);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 122);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 122);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c2_rhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs122), "rhs", "rhs",
                  122);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs122), "lhs", "lhs",
                  122);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 123);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 123);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 123);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c2_rhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs123), "rhs", "rhs",
                  123);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs123), "lhs", "lhs",
                  123);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 124);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.int"),
                  "name", "name", 124);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 124);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/int.p"),
                  "resolved", "resolved", 124);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c2_rhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs124), "rhs", "rhs",
                  124);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs124), "lhs", "lhs",
                  124);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 125);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmax"), "name", "name", 125);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 125);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c2_rhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs125), "rhs", "rhs",
                  125);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs125), "lhs", "lhs",
                  125);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 126);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("min"), "name", "name", 126);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 126);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c2_rhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs126), "rhs", "rhs",
                  126);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs126), "lhs", "lhs",
                  126);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 127);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 127);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 127);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 127);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c2_rhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs127), "rhs", "rhs",
                  127);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs127), "lhs", "lhs",
                  127);
  sf_mex_destroy(&c2_rhs64);
  sf_mex_destroy(&c2_lhs64);
  sf_mex_destroy(&c2_rhs65);
  sf_mex_destroy(&c2_lhs65);
  sf_mex_destroy(&c2_rhs66);
  sf_mex_destroy(&c2_lhs66);
  sf_mex_destroy(&c2_rhs67);
  sf_mex_destroy(&c2_lhs67);
  sf_mex_destroy(&c2_rhs68);
  sf_mex_destroy(&c2_lhs68);
  sf_mex_destroy(&c2_rhs69);
  sf_mex_destroy(&c2_lhs69);
  sf_mex_destroy(&c2_rhs70);
  sf_mex_destroy(&c2_lhs70);
  sf_mex_destroy(&c2_rhs71);
  sf_mex_destroy(&c2_lhs71);
  sf_mex_destroy(&c2_rhs72);
  sf_mex_destroy(&c2_lhs72);
  sf_mex_destroy(&c2_rhs73);
  sf_mex_destroy(&c2_lhs73);
  sf_mex_destroy(&c2_rhs74);
  sf_mex_destroy(&c2_lhs74);
  sf_mex_destroy(&c2_rhs75);
  sf_mex_destroy(&c2_lhs75);
  sf_mex_destroy(&c2_rhs76);
  sf_mex_destroy(&c2_lhs76);
  sf_mex_destroy(&c2_rhs77);
  sf_mex_destroy(&c2_lhs77);
  sf_mex_destroy(&c2_rhs78);
  sf_mex_destroy(&c2_lhs78);
  sf_mex_destroy(&c2_rhs79);
  sf_mex_destroy(&c2_lhs79);
  sf_mex_destroy(&c2_rhs80);
  sf_mex_destroy(&c2_lhs80);
  sf_mex_destroy(&c2_rhs81);
  sf_mex_destroy(&c2_lhs81);
  sf_mex_destroy(&c2_rhs82);
  sf_mex_destroy(&c2_lhs82);
  sf_mex_destroy(&c2_rhs83);
  sf_mex_destroy(&c2_lhs83);
  sf_mex_destroy(&c2_rhs84);
  sf_mex_destroy(&c2_lhs84);
  sf_mex_destroy(&c2_rhs85);
  sf_mex_destroy(&c2_lhs85);
  sf_mex_destroy(&c2_rhs86);
  sf_mex_destroy(&c2_lhs86);
  sf_mex_destroy(&c2_rhs87);
  sf_mex_destroy(&c2_lhs87);
  sf_mex_destroy(&c2_rhs88);
  sf_mex_destroy(&c2_lhs88);
  sf_mex_destroy(&c2_rhs89);
  sf_mex_destroy(&c2_lhs89);
  sf_mex_destroy(&c2_rhs90);
  sf_mex_destroy(&c2_lhs90);
  sf_mex_destroy(&c2_rhs91);
  sf_mex_destroy(&c2_lhs91);
  sf_mex_destroy(&c2_rhs92);
  sf_mex_destroy(&c2_lhs92);
  sf_mex_destroy(&c2_rhs93);
  sf_mex_destroy(&c2_lhs93);
  sf_mex_destroy(&c2_rhs94);
  sf_mex_destroy(&c2_lhs94);
  sf_mex_destroy(&c2_rhs95);
  sf_mex_destroy(&c2_lhs95);
  sf_mex_destroy(&c2_rhs96);
  sf_mex_destroy(&c2_lhs96);
  sf_mex_destroy(&c2_rhs97);
  sf_mex_destroy(&c2_lhs97);
  sf_mex_destroy(&c2_rhs98);
  sf_mex_destroy(&c2_lhs98);
  sf_mex_destroy(&c2_rhs99);
  sf_mex_destroy(&c2_lhs99);
  sf_mex_destroy(&c2_rhs100);
  sf_mex_destroy(&c2_lhs100);
  sf_mex_destroy(&c2_rhs101);
  sf_mex_destroy(&c2_lhs101);
  sf_mex_destroy(&c2_rhs102);
  sf_mex_destroy(&c2_lhs102);
  sf_mex_destroy(&c2_rhs103);
  sf_mex_destroy(&c2_lhs103);
  sf_mex_destroy(&c2_rhs104);
  sf_mex_destroy(&c2_lhs104);
  sf_mex_destroy(&c2_rhs105);
  sf_mex_destroy(&c2_lhs105);
  sf_mex_destroy(&c2_rhs106);
  sf_mex_destroy(&c2_lhs106);
  sf_mex_destroy(&c2_rhs107);
  sf_mex_destroy(&c2_lhs107);
  sf_mex_destroy(&c2_rhs108);
  sf_mex_destroy(&c2_lhs108);
  sf_mex_destroy(&c2_rhs109);
  sf_mex_destroy(&c2_lhs109);
  sf_mex_destroy(&c2_rhs110);
  sf_mex_destroy(&c2_lhs110);
  sf_mex_destroy(&c2_rhs111);
  sf_mex_destroy(&c2_lhs111);
  sf_mex_destroy(&c2_rhs112);
  sf_mex_destroy(&c2_lhs112);
  sf_mex_destroy(&c2_rhs113);
  sf_mex_destroy(&c2_lhs113);
  sf_mex_destroy(&c2_rhs114);
  sf_mex_destroy(&c2_lhs114);
  sf_mex_destroy(&c2_rhs115);
  sf_mex_destroy(&c2_lhs115);
  sf_mex_destroy(&c2_rhs116);
  sf_mex_destroy(&c2_lhs116);
  sf_mex_destroy(&c2_rhs117);
  sf_mex_destroy(&c2_lhs117);
  sf_mex_destroy(&c2_rhs118);
  sf_mex_destroy(&c2_lhs118);
  sf_mex_destroy(&c2_rhs119);
  sf_mex_destroy(&c2_lhs119);
  sf_mex_destroy(&c2_rhs120);
  sf_mex_destroy(&c2_lhs120);
  sf_mex_destroy(&c2_rhs121);
  sf_mex_destroy(&c2_lhs121);
  sf_mex_destroy(&c2_rhs122);
  sf_mex_destroy(&c2_lhs122);
  sf_mex_destroy(&c2_rhs123);
  sf_mex_destroy(&c2_lhs123);
  sf_mex_destroy(&c2_rhs124);
  sf_mex_destroy(&c2_lhs124);
  sf_mex_destroy(&c2_rhs125);
  sf_mex_destroy(&c2_lhs125);
  sf_mex_destroy(&c2_rhs126);
  sf_mex_destroy(&c2_lhs126);
  sf_mex_destroy(&c2_rhs127);
  sf_mex_destroy(&c2_lhs127);
}

static void c2_c_info_helper(const mxArray **c2_info)
{
  const mxArray *c2_rhs128 = NULL;
  const mxArray *c2_lhs128 = NULL;
  const mxArray *c2_rhs129 = NULL;
  const mxArray *c2_lhs129 = NULL;
  const mxArray *c2_rhs130 = NULL;
  const mxArray *c2_lhs130 = NULL;
  const mxArray *c2_rhs131 = NULL;
  const mxArray *c2_lhs131 = NULL;
  const mxArray *c2_rhs132 = NULL;
  const mxArray *c2_lhs132 = NULL;
  const mxArray *c2_rhs133 = NULL;
  const mxArray *c2_lhs133 = NULL;
  const mxArray *c2_rhs134 = NULL;
  const mxArray *c2_lhs134 = NULL;
  const mxArray *c2_rhs135 = NULL;
  const mxArray *c2_lhs135 = NULL;
  const mxArray *c2_rhs136 = NULL;
  const mxArray *c2_lhs136 = NULL;
  const mxArray *c2_rhs137 = NULL;
  const mxArray *c2_lhs137 = NULL;
  const mxArray *c2_rhs138 = NULL;
  const mxArray *c2_lhs138 = NULL;
  const mxArray *c2_rhs139 = NULL;
  const mxArray *c2_lhs139 = NULL;
  const mxArray *c2_rhs140 = NULL;
  const mxArray *c2_lhs140 = NULL;
  const mxArray *c2_rhs141 = NULL;
  const mxArray *c2_lhs141 = NULL;
  const mxArray *c2_rhs142 = NULL;
  const mxArray *c2_lhs142 = NULL;
  const mxArray *c2_rhs143 = NULL;
  const mxArray *c2_lhs143 = NULL;
  const mxArray *c2_rhs144 = NULL;
  const mxArray *c2_lhs144 = NULL;
  const mxArray *c2_rhs145 = NULL;
  const mxArray *c2_lhs145 = NULL;
  const mxArray *c2_rhs146 = NULL;
  const mxArray *c2_lhs146 = NULL;
  const mxArray *c2_rhs147 = NULL;
  const mxArray *c2_lhs147 = NULL;
  const mxArray *c2_rhs148 = NULL;
  const mxArray *c2_lhs148 = NULL;
  const mxArray *c2_rhs149 = NULL;
  const mxArray *c2_lhs149 = NULL;
  const mxArray *c2_rhs150 = NULL;
  const mxArray *c2_lhs150 = NULL;
  const mxArray *c2_rhs151 = NULL;
  const mxArray *c2_lhs151 = NULL;
  const mxArray *c2_rhs152 = NULL;
  const mxArray *c2_lhs152 = NULL;
  const mxArray *c2_rhs153 = NULL;
  const mxArray *c2_lhs153 = NULL;
  const mxArray *c2_rhs154 = NULL;
  const mxArray *c2_lhs154 = NULL;
  const mxArray *c2_rhs155 = NULL;
  const mxArray *c2_lhs155 = NULL;
  const mxArray *c2_rhs156 = NULL;
  const mxArray *c2_lhs156 = NULL;
  const mxArray *c2_rhs157 = NULL;
  const mxArray *c2_lhs157 = NULL;
  const mxArray *c2_rhs158 = NULL;
  const mxArray *c2_lhs158 = NULL;
  const mxArray *c2_rhs159 = NULL;
  const mxArray *c2_lhs159 = NULL;
  const mxArray *c2_rhs160 = NULL;
  const mxArray *c2_lhs160 = NULL;
  const mxArray *c2_rhs161 = NULL;
  const mxArray *c2_lhs161 = NULL;
  const mxArray *c2_rhs162 = NULL;
  const mxArray *c2_lhs162 = NULL;
  const mxArray *c2_rhs163 = NULL;
  const mxArray *c2_lhs163 = NULL;
  const mxArray *c2_rhs164 = NULL;
  const mxArray *c2_lhs164 = NULL;
  const mxArray *c2_rhs165 = NULL;
  const mxArray *c2_lhs165 = NULL;
  const mxArray *c2_rhs166 = NULL;
  const mxArray *c2_lhs166 = NULL;
  const mxArray *c2_rhs167 = NULL;
  const mxArray *c2_lhs167 = NULL;
  const mxArray *c2_rhs168 = NULL;
  const mxArray *c2_lhs168 = NULL;
  const mxArray *c2_rhs169 = NULL;
  const mxArray *c2_lhs169 = NULL;
  const mxArray *c2_rhs170 = NULL;
  const mxArray *c2_lhs170 = NULL;
  const mxArray *c2_rhs171 = NULL;
  const mxArray *c2_lhs171 = NULL;
  const mxArray *c2_rhs172 = NULL;
  const mxArray *c2_lhs172 = NULL;
  const mxArray *c2_rhs173 = NULL;
  const mxArray *c2_lhs173 = NULL;
  const mxArray *c2_rhs174 = NULL;
  const mxArray *c2_lhs174 = NULL;
  const mxArray *c2_rhs175 = NULL;
  const mxArray *c2_lhs175 = NULL;
  const mxArray *c2_rhs176 = NULL;
  const mxArray *c2_lhs176 = NULL;
  const mxArray *c2_rhs177 = NULL;
  const mxArray *c2_lhs177 = NULL;
  const mxArray *c2_rhs178 = NULL;
  const mxArray *c2_lhs178 = NULL;
  const mxArray *c2_rhs179 = NULL;
  const mxArray *c2_lhs179 = NULL;
  const mxArray *c2_rhs180 = NULL;
  const mxArray *c2_lhs180 = NULL;
  const mxArray *c2_rhs181 = NULL;
  const mxArray *c2_lhs181 = NULL;
  const mxArray *c2_rhs182 = NULL;
  const mxArray *c2_lhs182 = NULL;
  const mxArray *c2_rhs183 = NULL;
  const mxArray *c2_lhs183 = NULL;
  const mxArray *c2_rhs184 = NULL;
  const mxArray *c2_lhs184 = NULL;
  const mxArray *c2_rhs185 = NULL;
  const mxArray *c2_lhs185 = NULL;
  const mxArray *c2_rhs186 = NULL;
  const mxArray *c2_lhs186 = NULL;
  const mxArray *c2_rhs187 = NULL;
  const mxArray *c2_lhs187 = NULL;
  const mxArray *c2_rhs188 = NULL;
  const mxArray *c2_lhs188 = NULL;
  const mxArray *c2_rhs189 = NULL;
  const mxArray *c2_lhs189 = NULL;
  const mxArray *c2_rhs190 = NULL;
  const mxArray *c2_lhs190 = NULL;
  const mxArray *c2_rhs191 = NULL;
  const mxArray *c2_lhs191 = NULL;
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 128);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 128);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 128);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 128);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c2_rhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs128), "rhs", "rhs",
                  128);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs128), "lhs", "lhs",
                  128);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 129);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 129);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 129);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 129);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 129);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 129);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 129);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 129);
  sf_mex_assign(&c2_rhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs129), "rhs", "rhs",
                  129);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs129), "lhs", "lhs",
                  129);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 130);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 130);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 130);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 130);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 130);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 130);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 130);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 130);
  sf_mex_assign(&c2_rhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs130), "rhs", "rhs",
                  130);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs130), "lhs", "lhs",
                  130);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "context", "context", 131);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.refblas.xger"),
                  "name", "name", 131);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 131);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                  "resolved", "resolved", 131);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 131);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 131);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 131);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 131);
  sf_mex_assign(&c2_rhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs131), "rhs", "rhs",
                  131);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs131), "lhs", "lhs",
                  131);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                  "context", "context", 132);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.refblas.xgerx"),
                  "name", "name", 132);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 132);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "resolved", "resolved", 132);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 132);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 132);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 132);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 132);
  sf_mex_assign(&c2_rhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs132), "rhs", "rhs",
                  132);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs132), "lhs", "lhs",
                  132);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 133);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("abs"), "name", "name", 133);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 133);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 133);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 133);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 133);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 133);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 133);
  sf_mex_assign(&c2_rhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs133), "rhs", "rhs",
                  133);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs133), "lhs", "lhs",
                  133);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 134);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 134);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 134);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 134);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 134);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 134);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 134);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 134);
  sf_mex_assign(&c2_rhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs134), "rhs", "rhs",
                  134);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs134), "lhs", "lhs",
                  134);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 135);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 135);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 135);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 135);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 135);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 135);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 135);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 135);
  sf_mex_assign(&c2_rhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs135), "rhs", "rhs",
                  135);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs135), "lhs", "lhs",
                  135);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 136);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 136);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 136);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 136);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 136);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 136);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 136);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 136);
  sf_mex_assign(&c2_rhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs136), "rhs", "rhs",
                  136);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs136), "lhs", "lhs",
                  136);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 137);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 137);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 137);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 137);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 137);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 137);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 137);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 137);
  sf_mex_assign(&c2_rhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs137), "rhs", "rhs",
                  137);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs137), "lhs", "lhs",
                  137);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular"),
                  "context", "context", 138);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_warning"), "name", "name",
                  138);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 138);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 138);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286840402U), "fileTimeLo",
                  "fileTimeLo", 138);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 138);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 138);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 138);
  sf_mex_assign(&c2_rhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs138), "rhs", "rhs",
                  138);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs138), "lhs", "lhs",
                  138);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 139);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 139);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 139);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 139);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 139);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 139);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 139);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 139);
  sf_mex_assign(&c2_rhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs139), "rhs", "rhs",
                  139);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs139), "lhs", "lhs",
                  139);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 140);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xtrsm"), "name", "name",
                  140);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 140);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"),
                  "resolved", "resolved", 140);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 140);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 140);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 140);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 140);
  sf_mex_assign(&c2_rhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs140), "rhs", "rhs",
                  140);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs140), "lhs", "lhs",
                  140);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                  "context", 141);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 141);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 141);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 141);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 141);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 141);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 141);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 141);
  sf_mex_assign(&c2_rhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs141), "rhs", "rhs",
                  141);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs141), "lhs", "lhs",
                  141);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                  "context", 142);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.xtrsm"),
                  "name", "name", 142);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 142);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "resolved", "resolved", 142);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 142);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 142);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 142);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 142);
  sf_mex_assign(&c2_rhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs142), "rhs", "rhs",
                  142);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs142), "lhs", "lhs",
                  142);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 143);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 143);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 143);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 143);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 143);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 143);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 143);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 143);
  sf_mex_assign(&c2_rhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs143), "rhs", "rhs",
                  143);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs143), "lhs", "lhs",
                  143);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p!below_threshold"),
                  "context", "context", 144);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 144);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 144);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 144);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 144);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 144);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 144);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 144);
  sf_mex_assign(&c2_rhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs144), "rhs", "rhs",
                  144);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs144), "lhs", "lhs",
                  144);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 145);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 145);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 145);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 145);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 145);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 145);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 145);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 145);
  sf_mex_assign(&c2_rhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs145), "rhs", "rhs",
                  145);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs145), "lhs", "lhs",
                  145);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 146);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.refblas.xtrsm"),
                  "name", "name", 146);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 146);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "resolved", "resolved", 146);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 146);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 146);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 146);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 146);
  sf_mex_assign(&c2_rhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs146), "rhs", "rhs",
                  146);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs146), "lhs", "lhs",
                  146);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 147);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 147);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 147);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 147);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 147);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 147);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 147);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 147);
  sf_mex_assign(&c2_rhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs147), "rhs", "rhs",
                  147);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs147), "lhs", "lhs",
                  147);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 148);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 148);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 148);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 148);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 148);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 148);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 148);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 148);
  sf_mex_assign(&c2_rhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs148), "rhs", "rhs",
                  148);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs148), "lhs", "lhs",
                  148);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 149);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 149);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 149);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 149);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 149);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 149);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 149);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 149);
  sf_mex_assign(&c2_rhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs149), "rhs", "rhs",
                  149);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs149), "lhs", "lhs",
                  149);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 150);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("rdivide"), "name", "name", 150);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 150);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 150);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 150);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 150);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 150);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 150);
  sf_mex_assign(&c2_rhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs150), "rhs", "rhs",
                  150);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs150), "lhs", "lhs",
                  150);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 151);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 151);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 151);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 151);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 151);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 151);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 151);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 151);
  sf_mex_assign(&c2_rhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs151), "rhs", "rhs",
                  151);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs151), "lhs", "lhs",
                  151);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 152);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 152);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 152);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 152);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 152);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 152);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 152);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 152);
  sf_mex_assign(&c2_rhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs152), "rhs", "rhs",
                  152);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs152), "lhs", "lhs",
                  152);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 153);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_div"), "name", "name", 153);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 153);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 153);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 153);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 153);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 153);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 153);
  sf_mex_assign(&c2_rhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs153), "rhs", "rhs",
                  153);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs153), "lhs", "lhs",
                  153);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 154);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.int"),
                  "name", "name", 154);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 154);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/int.p"),
                  "resolved", "resolved", 154);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 154);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 154);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 154);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 154);
  sf_mex_assign(&c2_rhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs154), "rhs", "rhs",
                  154);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs154), "lhs", "lhs",
                  154);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p!ceval_xtrsm"),
                  "context", "context", 155);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.size_ptr"),
                  "name", "name", 155);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 155);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/size_ptr.p"),
                  "resolved", "resolved", 155);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 155);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 155);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 155);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 155);
  sf_mex_assign(&c2_rhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs155), "rhs", "rhs",
                  155);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs155), "lhs", "lhs",
                  155);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p!ceval_xtrsm"),
                  "context", "context", 156);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.c_cast"),
                  "name", "name", 156);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 156);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/c_cast.p"),
                  "resolved", "resolved", 156);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 156);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 156);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 156);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 156);
  sf_mex_assign(&c2_rhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs156), "rhs", "rhs",
                  156);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs156), "lhs", "lhs",
                  156);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 157);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 157);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 157);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 157);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 157);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 157);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 157);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 157);
  sf_mex_assign(&c2_rhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs157), "rhs", "rhs",
                  157);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs157), "lhs", "lhs",
                  157);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 158);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eye"), "name", "name", 158);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 158);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "resolved",
                  "resolved", 158);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1406834748U), "fileTimeLo",
                  "fileTimeLo", 158);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 158);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 158);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 158);
  sf_mex_assign(&c2_rhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs158), "rhs", "rhs",
                  158);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs158), "lhs", "lhs",
                  158);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 159);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 159);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 159);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 159);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1368204630U), "fileTimeLo",
                  "fileTimeLo", 159);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 159);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 159);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 159);
  sf_mex_assign(&c2_rhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs159), "rhs", "rhs",
                  159);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs159), "lhs", "lhs",
                  159);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 160);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 160);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 160);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 160);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 160);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 160);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 160);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 160);
  sf_mex_assign(&c2_rhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs160), "rhs", "rhs",
                  160);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs160), "lhs", "lhs",
                  160);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 161);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("isinf"), "name", "name", 161);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 161);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 161);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 161);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 161);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 161);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 161);
  sf_mex_assign(&c2_rhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs161), "rhs", "rhs",
                  161);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs161), "lhs", "lhs",
                  161);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 162);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 162);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 162);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 162);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 162);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 162);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 162);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 162);
  sf_mex_assign(&c2_rhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs162), "rhs", "rhs",
                  162);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs162), "lhs", "lhs",
                  162);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 163);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_is_integer_class"), "name",
                  "name", 163);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 163);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 163);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 163);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 163);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 163);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 163);
  sf_mex_assign(&c2_rhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs163), "rhs", "rhs",
                  163);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs163), "lhs", "lhs",
                  163);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 164);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmax"), "name", "name", 164);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 164);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 164);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 164);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 164);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 164);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 164);
  sf_mex_assign(&c2_rhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs164), "rhs", "rhs",
                  164);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs164), "lhs", "lhs",
                  164);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 165);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmin"), "name", "name", 165);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 165);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 165);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 165);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 165);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 165);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 165);
  sf_mex_assign(&c2_rhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs165), "rhs", "rhs",
                  165);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs165), "lhs", "lhs",
                  165);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 166);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.indexIntRelop"),
                  "name", "name", 166);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 166);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 166);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326749922U), "fileTimeLo",
                  "fileTimeLo", 166);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 166);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 166);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 166);
  sf_mex_assign(&c2_rhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs166), "rhs", "rhs",
                  166);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs166), "lhs", "lhs",
                  166);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 167);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 167);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 167);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 167);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 167);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 167);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 167);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 167);
  sf_mex_assign(&c2_rhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs167), "rhs", "rhs",
                  167);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs167), "lhs", "lhs",
                  167);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 168);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 168);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 168);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 168);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 168);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 168);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 168);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 168);
  sf_mex_assign(&c2_rhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs168), "rhs", "rhs",
                  168);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs168), "lhs", "lhs",
                  168);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 169);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmin"), "name", "name", 169);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 169);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 169);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 169);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 169);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 169);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 169);
  sf_mex_assign(&c2_rhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs169), "rhs", "rhs",
                  169);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs169), "lhs", "lhs",
                  169);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 170);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 170);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 170);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 170);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 170);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 170);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 170);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 170);
  sf_mex_assign(&c2_rhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs170), "rhs", "rhs",
                  170);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs170), "lhs", "lhs",
                  170);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 171);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("intmax"), "name", "name", 171);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 171);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 171);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 171);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 171);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 171);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 171);
  sf_mex_assign(&c2_rhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs171), "rhs", "rhs",
                  171);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs171), "lhs", "lhs",
                  171);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eye.m"), "context",
                  "context", 172);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 172);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 172);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 172);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 172);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 172);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 172);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 172);
  sf_mex_assign(&c2_rhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs172), "rhs", "rhs",
                  172);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs172), "lhs", "lhs",
                  172);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 173);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.int"),
                  "name", "name", 173);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 173);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/int.p"),
                  "resolved", "resolved", 173);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 173);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 173);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 173);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 173);
  sf_mex_assign(&c2_rhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs173), "rhs", "rhs",
                  173);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs173), "lhs", "lhs",
                  173);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!ceval_xgemm"),
                  "context", "context", 174);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.blas.size_ptr"),
                  "name", "name", 174);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 174);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/size_ptr.p"),
                  "resolved", "resolved", 174);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 174);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 174);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 174);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 174);
  sf_mex_assign(&c2_rhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs174), "rhs", "rhs",
                  174);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs174), "lhs", "lhs",
                  174);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!ceval_xgemm"),
                  "context", "context", 175);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.c_cast"),
                  "name", "name", 175);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("int32"), "dominantType",
                  "dominantType", 175);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/c_cast.p"),
                  "resolved", "resolved", 175);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 175);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 175);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 175);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 175);
  sf_mex_assign(&c2_rhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs175), "rhs", "rhs",
                  175);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs175), "lhs", "lhs",
                  175);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 176);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("JacobBoomHip_FixParams"),
                  "name", "name", 176);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 176);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/JacobBoomHip_FixParams.m"),
                  "resolved", "resolved", 176);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1444269963U), "fileTimeLo",
                  "fileTimeLo", 176);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 176);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 176);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 176);
  sf_mex_assign(&c2_rhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs176), "rhs", "rhs",
                  176);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs176), "lhs", "lhs",
                  176);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/JacobBoomHip_FixParams.m"),
                  "context", "context", 177);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("sin"), "name", "name", 177);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 177);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 177);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 177);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 177);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 177);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 177);
  sf_mex_assign(&c2_rhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs177), "rhs", "rhs",
                  177);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs177), "lhs", "lhs",
                  177);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 178);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 178);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 178);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 178);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286840336U), "fileTimeLo",
                  "fileTimeLo", 178);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 178);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 178);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 178);
  sf_mex_assign(&c2_rhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs178), "rhs", "rhs",
                  178);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs178), "lhs", "lhs",
                  178);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/JacobBoomHip_FixParams.m"),
                  "context", "context", 179);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("cos"), "name", "name", 179);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 179);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 179);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 179);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 179);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 179);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 179);
  sf_mex_assign(&c2_rhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs179), "rhs", "rhs",
                  179);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs179), "lhs", "lhs",
                  179);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 180);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 180);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 180);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 180);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1286840322U), "fileTimeLo",
                  "fileTimeLo", 180);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 180);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 180);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 180);
  sf_mex_assign(&c2_rhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs180), "rhs", "rhs",
                  180);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs180), "lhs", "lhs",
                  180);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/JacobBoomHip_FixParams.m"),
                  "context", "context", 181);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mpower"), "name", "name", 181);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 181);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 181);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363731878U), "fileTimeLo",
                  "fileTimeLo", 181);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 181);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 181);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 181);
  sf_mex_assign(&c2_rhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs181), "rhs", "rhs",
                  181);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs181), "lhs", "lhs",
                  181);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 182);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("BoomPositionHip_FixParams"),
                  "name", "name", 182);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 182);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/BoomPositionHip_FixParams.m"),
                  "resolved", "resolved", 182);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1444269963U), "fileTimeLo",
                  "fileTimeLo", 182);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 182);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 182);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 182);
  sf_mex_assign(&c2_rhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs182), "rhs", "rhs",
                  182);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs182), "lhs", "lhs",
                  182);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/BoomPositionHip_FixParams.m"),
                  "context", "context", 183);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("cos"), "name", "name", 183);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 183);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 183);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 183);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 183);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 183);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 183);
  sf_mex_assign(&c2_rhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs183), "rhs", "rhs",
                  183);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs183), "lhs", "lhs",
                  183);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/BoomPositionHip_FixParams.m"),
                  "context", "context", 184);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("sin"), "name", "name", 184);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 184);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 184);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 184);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 184);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 184);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 184);
  sf_mex_assign(&c2_rhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs184), "rhs", "rhs",
                  184);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs184), "lhs", "lhs",
                  184);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve3x3"),
                  "context", "context", 185);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_xcabs1"), "name", "name",
                  185);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 185);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "resolved", "resolved", 185);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 185);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 185);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 185);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 185);
  sf_mex_assign(&c2_rhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs185), "rhs", "rhs",
                  185);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs185), "lhs", "lhs",
                  185);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xcabs1.m"),
                  "context", "context", 186);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("coder.internal.refblas.xcabs1"),
                  "name", "name", 186);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 186);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 186);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 186);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 186);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 186);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 186);
  sf_mex_assign(&c2_rhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs186), "rhs", "rhs",
                  186);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs186), "lhs", "lhs",
                  186);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve3x3"),
                  "context", "context", 187);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("rdivide"), "name", "name", 187);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 187);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 187);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 187);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 187);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 187);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 187);
  sf_mex_assign(&c2_rhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs187), "rhs", "rhs",
                  187);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs187), "lhs", "lhs",
                  187);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve3x3"),
                  "context", "context", 188);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 188);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 188);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 188);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 188);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 188);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 188);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 188);
  sf_mex_assign(&c2_rhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs188), "rhs", "rhs",
                  188);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs188), "lhs", "lhs",
                  188);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolve3x3"),
                  "context", "context", 189);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 189);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 189);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 189);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 189);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 189);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 189);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 189);
  sf_mex_assign(&c2_rhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs189), "rhs", "rhs",
                  189);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs189), "lhs", "lhs",
                  189);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(""), "context", "context", 190);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("mldivide"), "name", "name",
                  190);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 190);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "resolved",
                  "resolved", 190);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 190);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 190);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1319751566U), "mFileTimeLo",
                  "mFileTimeLo", 190);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 190);
  sf_mex_assign(&c2_rhs190, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs190, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs190), "rhs", "rhs",
                  190);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs190), "lhs", "lhs",
                  190);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "context",
                  "context", 191);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("eml_lusolve"), "name", "name",
                  191);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 191);
  sf_mex_addfield(*c2_info, c2_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m"), "resolved",
                  "resolved", 191);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(1370031486U), "fileTimeLo",
                  "fileTimeLo", 191);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 191);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 191);
  sf_mex_addfield(*c2_info, c2_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 191);
  sf_mex_assign(&c2_rhs191, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c2_lhs191, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_rhs191), "rhs", "rhs",
                  191);
  sf_mex_addfield(*c2_info, sf_mex_duplicatearraysafe(&c2_lhs191), "lhs", "lhs",
                  191);
  sf_mex_destroy(&c2_rhs128);
  sf_mex_destroy(&c2_lhs128);
  sf_mex_destroy(&c2_rhs129);
  sf_mex_destroy(&c2_lhs129);
  sf_mex_destroy(&c2_rhs130);
  sf_mex_destroy(&c2_lhs130);
  sf_mex_destroy(&c2_rhs131);
  sf_mex_destroy(&c2_lhs131);
  sf_mex_destroy(&c2_rhs132);
  sf_mex_destroy(&c2_lhs132);
  sf_mex_destroy(&c2_rhs133);
  sf_mex_destroy(&c2_lhs133);
  sf_mex_destroy(&c2_rhs134);
  sf_mex_destroy(&c2_lhs134);
  sf_mex_destroy(&c2_rhs135);
  sf_mex_destroy(&c2_lhs135);
  sf_mex_destroy(&c2_rhs136);
  sf_mex_destroy(&c2_lhs136);
  sf_mex_destroy(&c2_rhs137);
  sf_mex_destroy(&c2_lhs137);
  sf_mex_destroy(&c2_rhs138);
  sf_mex_destroy(&c2_lhs138);
  sf_mex_destroy(&c2_rhs139);
  sf_mex_destroy(&c2_lhs139);
  sf_mex_destroy(&c2_rhs140);
  sf_mex_destroy(&c2_lhs140);
  sf_mex_destroy(&c2_rhs141);
  sf_mex_destroy(&c2_lhs141);
  sf_mex_destroy(&c2_rhs142);
  sf_mex_destroy(&c2_lhs142);
  sf_mex_destroy(&c2_rhs143);
  sf_mex_destroy(&c2_lhs143);
  sf_mex_destroy(&c2_rhs144);
  sf_mex_destroy(&c2_lhs144);
  sf_mex_destroy(&c2_rhs145);
  sf_mex_destroy(&c2_lhs145);
  sf_mex_destroy(&c2_rhs146);
  sf_mex_destroy(&c2_lhs146);
  sf_mex_destroy(&c2_rhs147);
  sf_mex_destroy(&c2_lhs147);
  sf_mex_destroy(&c2_rhs148);
  sf_mex_destroy(&c2_lhs148);
  sf_mex_destroy(&c2_rhs149);
  sf_mex_destroy(&c2_lhs149);
  sf_mex_destroy(&c2_rhs150);
  sf_mex_destroy(&c2_lhs150);
  sf_mex_destroy(&c2_rhs151);
  sf_mex_destroy(&c2_lhs151);
  sf_mex_destroy(&c2_rhs152);
  sf_mex_destroy(&c2_lhs152);
  sf_mex_destroy(&c2_rhs153);
  sf_mex_destroy(&c2_lhs153);
  sf_mex_destroy(&c2_rhs154);
  sf_mex_destroy(&c2_lhs154);
  sf_mex_destroy(&c2_rhs155);
  sf_mex_destroy(&c2_lhs155);
  sf_mex_destroy(&c2_rhs156);
  sf_mex_destroy(&c2_lhs156);
  sf_mex_destroy(&c2_rhs157);
  sf_mex_destroy(&c2_lhs157);
  sf_mex_destroy(&c2_rhs158);
  sf_mex_destroy(&c2_lhs158);
  sf_mex_destroy(&c2_rhs159);
  sf_mex_destroy(&c2_lhs159);
  sf_mex_destroy(&c2_rhs160);
  sf_mex_destroy(&c2_lhs160);
  sf_mex_destroy(&c2_rhs161);
  sf_mex_destroy(&c2_lhs161);
  sf_mex_destroy(&c2_rhs162);
  sf_mex_destroy(&c2_lhs162);
  sf_mex_destroy(&c2_rhs163);
  sf_mex_destroy(&c2_lhs163);
  sf_mex_destroy(&c2_rhs164);
  sf_mex_destroy(&c2_lhs164);
  sf_mex_destroy(&c2_rhs165);
  sf_mex_destroy(&c2_lhs165);
  sf_mex_destroy(&c2_rhs166);
  sf_mex_destroy(&c2_lhs166);
  sf_mex_destroy(&c2_rhs167);
  sf_mex_destroy(&c2_lhs167);
  sf_mex_destroy(&c2_rhs168);
  sf_mex_destroy(&c2_lhs168);
  sf_mex_destroy(&c2_rhs169);
  sf_mex_destroy(&c2_lhs169);
  sf_mex_destroy(&c2_rhs170);
  sf_mex_destroy(&c2_lhs170);
  sf_mex_destroy(&c2_rhs171);
  sf_mex_destroy(&c2_lhs171);
  sf_mex_destroy(&c2_rhs172);
  sf_mex_destroy(&c2_lhs172);
  sf_mex_destroy(&c2_rhs173);
  sf_mex_destroy(&c2_lhs173);
  sf_mex_destroy(&c2_rhs174);
  sf_mex_destroy(&c2_lhs174);
  sf_mex_destroy(&c2_rhs175);
  sf_mex_destroy(&c2_lhs175);
  sf_mex_destroy(&c2_rhs176);
  sf_mex_destroy(&c2_lhs176);
  sf_mex_destroy(&c2_rhs177);
  sf_mex_destroy(&c2_lhs177);
  sf_mex_destroy(&c2_rhs178);
  sf_mex_destroy(&c2_lhs178);
  sf_mex_destroy(&c2_rhs179);
  sf_mex_destroy(&c2_lhs179);
  sf_mex_destroy(&c2_rhs180);
  sf_mex_destroy(&c2_lhs180);
  sf_mex_destroy(&c2_rhs181);
  sf_mex_destroy(&c2_lhs181);
  sf_mex_destroy(&c2_rhs182);
  sf_mex_destroy(&c2_lhs182);
  sf_mex_destroy(&c2_rhs183);
  sf_mex_destroy(&c2_lhs183);
  sf_mex_destroy(&c2_rhs184);
  sf_mex_destroy(&c2_lhs184);
  sf_mex_destroy(&c2_rhs185);
  sf_mex_destroy(&c2_lhs185);
  sf_mex_destroy(&c2_rhs186);
  sf_mex_destroy(&c2_lhs186);
  sf_mex_destroy(&c2_rhs187);
  sf_mex_destroy(&c2_lhs187);
  sf_mex_destroy(&c2_rhs188);
  sf_mex_destroy(&c2_lhs188);
  sf_mex_destroy(&c2_rhs189);
  sf_mex_destroy(&c2_lhs189);
  sf_mex_destroy(&c2_rhs190);
  sf_mex_destroy(&c2_lhs190);
  sf_mex_destroy(&c2_rhs191);
  sf_mex_destroy(&c2_lhs191);
}

static void c2_eml_error(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  int32_T c2_i251;
  static char_T c2_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c2_b_u[30];
  const mxArray *c2_y = NULL;
  int32_T c2_i252;
  static char_T c2_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c2_c_u[4];
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  for (c2_i251 = 0; c2_i251 < 30; c2_i251++) {
    c2_b_u[c2_i251] = c2_cv0[c2_i251];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 30),
                false);
  for (c2_i252 = 0; c2_i252 < 4; c2_i252++) {
    c2_c_u[c2_i252] = c2_cv1[c2_i252];
  }

  c2_b_y = NULL;
  sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u, 10, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c2_y, 14, c2_b_y));
}

static void c2_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_b_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c2_mpower(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_a)
{
  real_T c2_b_a;
  real_T c2_c_a;
  real_T c2_ak;
  real_T c2_d_a;
  c2_b_a = c2_a;
  c2_c_a = c2_b_a;
  c2_c_eml_scalar_eg(chartInstance);
  c2_ak = c2_c_a;
  c2_d_a = c2_ak;
  c2_c_eml_scalar_eg(chartInstance);
  return c2_d_a * c2_d_a;
}

static void c2_c_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_d_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_mrdivide(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_A[80], real_T c2_b_B[256], real_T c2_y[80])
{
  int32_T c2_i253;
  real_T c2_c_B[256];
  int32_T c2_i254;
  real_T c2_b_A[80];
  for (c2_i253 = 0; c2_i253 < 256; c2_i253++) {
    c2_c_B[c2_i253] = c2_b_B[c2_i253];
  }

  for (c2_i254 = 0; c2_i254 < 80; c2_i254++) {
    c2_b_A[c2_i254] = c2_A[c2_i254];
  }

  c2_eml_lusolve(chartInstance, c2_c_B, c2_b_A, c2_y);
}

static void c2_eml_lusolve(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[80], real_T c2_X[80])
{
  int32_T c2_i255;
  real_T c2_b_A[256];
  int32_T c2_info;
  int32_T c2_ipiv[16];
  int32_T c2_b_info;
  int32_T c2_c_info;
  int32_T c2_d_info;
  int32_T c2_i256;
  int32_T c2_i257;
  real_T c2_c_A[256];
  int32_T c2_i258;
  real_T c2_d_A[256];
  int32_T c2_xj;
  int32_T c2_b_xj;
  int32_T c2_jp;
  int32_T c2_xi;
  int32_T c2_b_xi;
  real_T c2_temp;
  for (c2_i255 = 0; c2_i255 < 256; c2_i255++) {
    c2_b_A[c2_i255] = c2_A[c2_i255];
  }

  c2_c_eml_matlab_zgetrf(chartInstance, c2_b_A, c2_ipiv, &c2_info);
  c2_b_info = c2_info;
  c2_c_info = c2_b_info;
  c2_d_info = c2_c_info;
  if (c2_d_info > 0) {
    c2_eml_warning(chartInstance);
  }

  for (c2_i256 = 0; c2_i256 < 80; c2_i256++) {
    c2_X[c2_i256] = c2_b_B[c2_i256];
  }

  for (c2_i257 = 0; c2_i257 < 256; c2_i257++) {
    c2_c_A[c2_i257] = c2_b_A[c2_i257];
  }

  c2_i_eml_xtrsm(chartInstance, c2_c_A, c2_X);
  for (c2_i258 = 0; c2_i258 < 256; c2_i258++) {
    c2_d_A[c2_i258] = c2_b_A[c2_i258];
  }

  c2_j_eml_xtrsm(chartInstance, c2_d_A, c2_X);
  c2_eml_switch_helper(chartInstance);
  for (c2_xj = 15; c2_xj > 0; c2_xj--) {
    c2_b_xj = c2_xj;
    if (c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_xj), 1, 16, 1, 0) - 1] != c2_b_xj) {
      c2_jp = c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_b_xj), 1, 16, 1, 0) - 1];
      c2_eml_switch_helper(chartInstance);
      for (c2_xi = 1; c2_xi < 6; c2_xi++) {
        c2_b_xi = c2_xi;
        c2_temp = c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_xi), 1, 5, 1, 0) + 5 *
                        (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_xj), 1, 16, 2, 0) - 1)) - 1];
        c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_xi), 1, 5, 1, 0) + 5 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_xj), 1, 16, 2,
                0) - 1)) - 1] = c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_xi), 1, 5, 1, 0) + 5 *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_jp), 1, 16, 2, 0) - 1)) - 1];
        c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_xi), 1, 5, 1, 0) + 5 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_jp), 1, 16, 2, 0)
               - 1)) - 1] = c2_temp;
      }
    }
  }
}

static void c2_realmin(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_eps(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_eml_switch_helper(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_eml_matlab_zgetrf(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_A[256], int32_T c2_ipiv[16], int32_T *c2_info)
{
  int32_T c2_i259;
  for (c2_i259 = 0; c2_i259 < 256; c2_i259++) {
    c2_b_A[c2_i259] = c2_A[c2_i259];
  }

  c2_c_eml_matlab_zgetrf(chartInstance, c2_b_A, c2_ipiv, c2_info);
}

static void c2_b_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_check_forloop_overflow_error(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, boolean_T c2_overflow)
{
  int32_T c2_i260;
  static char_T c2_cv2[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c2_b_u[34];
  const mxArray *c2_y = NULL;
  int32_T c2_i261;
  static char_T c2_cv3[5] = { 'i', 'n', 't', '3', '2' };

  char_T c2_c_u[5];
  const mxArray *c2_b_y = NULL;
  (void)chartInstance;
  if (!c2_overflow) {
  } else {
    for (c2_i260 = 0; c2_i260 < 34; c2_i260++) {
      c2_b_u[c2_i260] = c2_cv2[c2_i260];
    }

    c2_y = NULL;
    sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 34),
                  false);
    for (c2_i261 = 0; c2_i261 < 5; c2_i261++) {
      c2_c_u[c2_i261] = c2_cv3[c2_i261];
    }

    c2_b_y = NULL;
    sf_mex_assign(&c2_b_y, sf_mex_create("y", c2_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                  false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                      sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message",
      1U, 2U, 14, c2_y, 14, c2_b_y));
  }
}

static void c2_eml_xswap(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_b_x[256], int32_T c2_ix0, int32_T c2_iy0, real_T c2_c_x[256])
{
  int32_T c2_i262;
  for (c2_i262 = 0; c2_i262 < 256; c2_i262++) {
    c2_c_x[c2_i262] = c2_b_x[c2_i262];
  }

  c2_b_eml_xswap(chartInstance, c2_c_x, c2_ix0, c2_iy0);
}

static void c2_b_eml_switch_helper(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c2_eml_xgeru(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_A[256], int32_T c2_ia0, real_T c2_b_A[256])
{
  int32_T c2_i263;
  for (c2_i263 = 0; c2_i263 < 256; c2_i263++) {
    c2_b_A[c2_i263] = c2_A[c2_i263];
  }

  c2_c_eml_xgeru(chartInstance, c2_m, c2_n, c2_alpha1, c2_ix0, c2_iy0, c2_b_A,
                 c2_ia0);
}

static void c2_c_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_eml_warning(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  int32_T c2_i264;
  static char_T c2_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c2_b_u[27];
  const mxArray *c2_y = NULL;
  (void)chartInstance;
  for (c2_i264 = 0; c2_i264 < 27; c2_i264++) {
    c2_b_u[c2_i264] = c2_varargin_1[c2_i264];
  }

  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", c2_b_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c2_y));
}

static void c2_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_A[256], real_T c2_b_B[80], real_T c2_c_B[80])
{
  int32_T c2_i265;
  int32_T c2_i266;
  real_T c2_b_A[256];
  for (c2_i265 = 0; c2_i265 < 80; c2_i265++) {
    c2_c_B[c2_i265] = c2_b_B[c2_i265];
  }

  for (c2_i266 = 0; c2_i266 < 256; c2_i266++) {
    c2_b_A[c2_i266] = c2_A[c2_i266];
  }

  c2_i_eml_xtrsm(chartInstance, c2_b_A, c2_c_B);
}

static void c2_below_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  c2_c_eml_switch_helper(chartInstance);
}

static void c2_c_eml_switch_helper(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static real_T c2_rdivide(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_b_x, real_T c2_y)
{
  real_T c2_c_x;
  real_T c2_b_y;
  real_T c2_d_x;
  real_T c2_c_y;
  (void)chartInstance;
  c2_c_x = c2_b_x;
  c2_b_y = c2_y;
  c2_d_x = c2_c_x;
  c2_c_y = c2_b_y;
  return c2_d_x / c2_c_y;
}

static void c2_b_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[80], real_T c2_c_B[80])
{
  int32_T c2_i267;
  int32_T c2_i268;
  real_T c2_b_A[256];
  for (c2_i267 = 0; c2_i267 < 80; c2_i267++) {
    c2_c_B[c2_i267] = c2_b_B[c2_i267];
  }

  for (c2_i268 = 0; c2_i268 < 256; c2_i268++) {
    c2_b_A[c2_i268] = c2_A[c2_i268];
  }

  c2_j_eml_xtrsm(chartInstance, c2_b_A, c2_c_B);
}

static void c2_e_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_b_mrdivide(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[80], real_T c2_b_B[25], real_T c2_y[80])
{
  int32_T c2_i269;
  real_T c2_b_A[25];
  int32_T c2_info;
  int32_T c2_ipiv[5];
  int32_T c2_b_info;
  int32_T c2_c_info;
  int32_T c2_d_info;
  int32_T c2_i270;
  int32_T c2_i271;
  real_T c2_c_A[25];
  int32_T c2_i272;
  real_T c2_d_A[25];
  int32_T c2_xj;
  int32_T c2_b_xj;
  int32_T c2_jp;
  int32_T c2_xi;
  int32_T c2_b_xi;
  real_T c2_temp;
  for (c2_i269 = 0; c2_i269 < 25; c2_i269++) {
    c2_b_A[c2_i269] = c2_b_B[c2_i269];
  }

  c2_d_eml_matlab_zgetrf(chartInstance, c2_b_A, c2_ipiv, &c2_info);
  c2_b_info = c2_info;
  c2_c_info = c2_b_info;
  c2_d_info = c2_c_info;
  if (c2_d_info > 0) {
    c2_eml_warning(chartInstance);
  }

  for (c2_i270 = 0; c2_i270 < 80; c2_i270++) {
    c2_y[c2_i270] = c2_A[c2_i270];
  }

  for (c2_i271 = 0; c2_i271 < 25; c2_i271++) {
    c2_c_A[c2_i271] = c2_b_A[c2_i271];
  }

  c2_k_eml_xtrsm(chartInstance, c2_c_A, c2_y);
  for (c2_i272 = 0; c2_i272 < 25; c2_i272++) {
    c2_d_A[c2_i272] = c2_b_A[c2_i272];
  }

  c2_l_eml_xtrsm(chartInstance, c2_d_A, c2_y);
  c2_eml_switch_helper(chartInstance);
  for (c2_xj = 4; c2_xj > 0; c2_xj--) {
    c2_b_xj = c2_xj;
    if (c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_xj), 1, 5, 1, 0) - 1] != c2_b_xj) {
      c2_jp = c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_b_xj), 1, 5, 1, 0) - 1];
      c2_eml_switch_helper(chartInstance);
      for (c2_xi = 1; c2_xi < 17; c2_xi++) {
        c2_b_xi = c2_xi;
        c2_temp = c2_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_xi), 1, 16, 1, 0) +
                        ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_xj), 1, 5, 2, 0) - 1) << 4)) - 1];
        c2_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_xi), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
                 "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_xj), 1, 5, 2,
                 0) - 1) << 4)) - 1] = c2_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("",
          (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_xi), 1, 16, 1, 0) +
          ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_jp), 1, 5, 2, 0) - 1) << 4)) - 1];
        c2_y[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_xi), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK(
                 "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_jp), 1, 5, 2, 0)
                - 1) << 4)) - 1] = c2_temp;
      }
    }
  }
}

static void c2_b_eml_matlab_zgetrf(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c2_A[25], real_T c2_b_A[25], int32_T c2_ipiv[5],
  int32_T *c2_info)
{
  int32_T c2_i273;
  for (c2_i273 = 0; c2_i273 < 25; c2_i273++) {
    c2_b_A[c2_i273] = c2_A[c2_i273];
  }

  c2_d_eml_matlab_zgetrf(chartInstance, c2_b_A, c2_ipiv, c2_info);
}

static void c2_b_eml_xgeru(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_A[25], int32_T c2_ia0, real_T c2_b_A[25])
{
  int32_T c2_i274;
  for (c2_i274 = 0; c2_i274 < 25; c2_i274++) {
    c2_b_A[c2_i274] = c2_A[c2_i274];
  }

  c2_d_eml_xgeru(chartInstance, c2_m, c2_n, c2_alpha1, c2_ix0, c2_iy0, c2_b_A,
                 c2_ia0);
}

static void c2_c_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[25], real_T c2_b_B[80], real_T c2_c_B[80])
{
  int32_T c2_i275;
  int32_T c2_i276;
  real_T c2_b_A[25];
  for (c2_i275 = 0; c2_i275 < 80; c2_i275++) {
    c2_c_B[c2_i275] = c2_b_B[c2_i275];
  }

  for (c2_i276 = 0; c2_i276 < 25; c2_i276++) {
    c2_b_A[c2_i276] = c2_A[c2_i276];
  }

  c2_k_eml_xtrsm(chartInstance, c2_b_A, c2_c_B);
}

static void c2_b_below_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  c2_c_eml_switch_helper(chartInstance);
}

static void c2_scalarEg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_d_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[25], real_T c2_b_B[80], real_T c2_c_B[80])
{
  int32_T c2_i277;
  int32_T c2_i278;
  real_T c2_b_A[25];
  for (c2_i277 = 0; c2_i277 < 80; c2_i277++) {
    c2_c_B[c2_i277] = c2_b_B[c2_i277];
  }

  for (c2_i278 = 0; c2_i278 < 25; c2_i278++) {
    c2_b_A[c2_i278] = c2_A[c2_i278];
  }

  c2_l_eml_xtrsm(chartInstance, c2_b_A, c2_c_B);
}

static void c2_eye(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T c2_I
                   [256])
{
  int32_T c2_i279;
  int32_T c2_k;
  int32_T c2_b_k;
  for (c2_i279 = 0; c2_i279 < 256; c2_i279++) {
    c2_I[c2_i279] = 0.0;
  }

  c2_eml_switch_helper(chartInstance);
  for (c2_k = 1; c2_k < 17; c2_k++) {
    c2_b_k = c2_k;
    c2_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 2, 0) - 1) <<
           4)) - 1] = 1.0;
  }
}

static void c2_f_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_eml_xgemm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_A[80], real_T c2_b_B[80], real_T c2_C[256], real_T c2_b_C[256])
{
  int32_T c2_i280;
  int32_T c2_i281;
  real_T c2_b_A[80];
  int32_T c2_i282;
  real_T c2_c_B[80];
  for (c2_i280 = 0; c2_i280 < 256; c2_i280++) {
    c2_b_C[c2_i280] = c2_C[c2_i280];
  }

  for (c2_i281 = 0; c2_i281 < 80; c2_i281++) {
    c2_b_A[c2_i281] = c2_A[c2_i281];
  }

  for (c2_i282 = 0; c2_i282 < 80; c2_i282++) {
    c2_c_B[c2_i282] = c2_b_B[c2_i282];
  }

  c2_c_eml_xgemm(chartInstance, c2_b_A, c2_c_B, c2_b_C);
}

static void c2_g_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_h_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_c_mrdivide(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[48], real_T c2_b_B[256], real_T c2_y[48])
{
  int32_T c2_i283;
  real_T c2_c_B[256];
  int32_T c2_i284;
  real_T c2_b_A[48];
  for (c2_i283 = 0; c2_i283 < 256; c2_i283++) {
    c2_c_B[c2_i283] = c2_b_B[c2_i283];
  }

  for (c2_i284 = 0; c2_i284 < 48; c2_i284++) {
    c2_b_A[c2_i284] = c2_A[c2_i284];
  }

  c2_b_eml_lusolve(chartInstance, c2_c_B, c2_b_A, c2_y);
}

static void c2_b_eml_lusolve(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[48], real_T c2_X[48])
{
  int32_T c2_i285;
  real_T c2_b_A[256];
  int32_T c2_info;
  int32_T c2_ipiv[16];
  int32_T c2_b_info;
  int32_T c2_c_info;
  int32_T c2_d_info;
  int32_T c2_i286;
  int32_T c2_i287;
  real_T c2_c_A[256];
  int32_T c2_i288;
  real_T c2_d_A[256];
  int32_T c2_xj;
  int32_T c2_b_xj;
  int32_T c2_jp;
  int32_T c2_xi;
  int32_T c2_b_xi;
  real_T c2_temp;
  for (c2_i285 = 0; c2_i285 < 256; c2_i285++) {
    c2_b_A[c2_i285] = c2_A[c2_i285];
  }

  c2_c_eml_matlab_zgetrf(chartInstance, c2_b_A, c2_ipiv, &c2_info);
  c2_b_info = c2_info;
  c2_c_info = c2_b_info;
  c2_d_info = c2_c_info;
  if (c2_d_info > 0) {
    c2_eml_warning(chartInstance);
  }

  for (c2_i286 = 0; c2_i286 < 48; c2_i286++) {
    c2_X[c2_i286] = c2_b_B[c2_i286];
  }

  for (c2_i287 = 0; c2_i287 < 256; c2_i287++) {
    c2_c_A[c2_i287] = c2_b_A[c2_i287];
  }

  c2_m_eml_xtrsm(chartInstance, c2_c_A, c2_X);
  for (c2_i288 = 0; c2_i288 < 256; c2_i288++) {
    c2_d_A[c2_i288] = c2_b_A[c2_i288];
  }

  c2_n_eml_xtrsm(chartInstance, c2_d_A, c2_X);
  c2_eml_switch_helper(chartInstance);
  for (c2_xj = 15; c2_xj > 0; c2_xj--) {
    c2_b_xj = c2_xj;
    if (c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_xj), 1, 16, 1, 0) - 1] != c2_b_xj) {
      c2_jp = c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_b_xj), 1, 16, 1, 0) - 1];
      c2_eml_switch_helper(chartInstance);
      for (c2_xi = 1; c2_xi < 4; c2_xi++) {
        c2_b_xi = c2_xi;
        c2_temp = c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_xi), 1, 3, 1, 0) + 3 *
                        (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_xj), 1, 16, 2, 0) - 1)) - 1];
        c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_xi), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_xj), 1, 16, 2,
                0) - 1)) - 1] = c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_xi), 1, 3, 1, 0) + 3 *
          (_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_jp), 1, 16, 2, 0) - 1)) - 1];
        c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
                (real_T)c2_b_xi), 1, 3, 1, 0) + 3 * (_SFD_EML_ARRAY_BOUNDS_CHECK
               ("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_jp), 1, 16, 2, 0)
               - 1)) - 1] = c2_temp;
      }
    }
  }
}

static void c2_e_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[48], real_T c2_c_B[48])
{
  int32_T c2_i289;
  int32_T c2_i290;
  real_T c2_b_A[256];
  for (c2_i289 = 0; c2_i289 < 48; c2_i289++) {
    c2_c_B[c2_i289] = c2_b_B[c2_i289];
  }

  for (c2_i290 = 0; c2_i290 < 256; c2_i290++) {
    c2_b_A[c2_i290] = c2_A[c2_i290];
  }

  c2_m_eml_xtrsm(chartInstance, c2_b_A, c2_c_B);
}

static void c2_c_below_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  c2_c_eml_switch_helper(chartInstance);
}

static void c2_f_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[48], real_T c2_c_B[48])
{
  int32_T c2_i291;
  int32_T c2_i292;
  real_T c2_b_A[256];
  for (c2_i291 = 0; c2_i291 < 48; c2_i291++) {
    c2_c_B[c2_i291] = c2_b_B[c2_i291];
  }

  for (c2_i292 = 0; c2_i292 < 256; c2_i292++) {
    c2_b_A[c2_i292] = c2_A[c2_i292];
  }

  c2_n_eml_xtrsm(chartInstance, c2_b_A, c2_c_B);
}

static void c2_i_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_d_mrdivide(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[48], real_T c2_b_B[9], real_T c2_y[48])
{
  int32_T c2_i293;
  real_T c2_c_B[9];
  int32_T c2_i294;
  real_T c2_b_A[48];
  for (c2_i293 = 0; c2_i293 < 9; c2_i293++) {
    c2_c_B[c2_i293] = c2_b_B[c2_i293];
  }

  for (c2_i294 = 0; c2_i294 < 48; c2_i294++) {
    c2_b_A[c2_i294] = c2_A[c2_i294];
  }

  c2_c_eml_lusolve(chartInstance, c2_c_B, c2_b_A, c2_y);
}

static void c2_c_eml_lusolve(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[9], real_T c2_b_B[48], real_T c2_X[48])
{
  int32_T c2_i295;
  real_T c2_b_A[9];
  int32_T c2_r1;
  int32_T c2_r2;
  int32_T c2_r3;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_e_x;
  real_T c2_y;
  real_T c2_f_x;
  real_T c2_g_x;
  real_T c2_b_y;
  real_T c2_maxval;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_c_y;
  real_T c2_l_x;
  real_T c2_m_x;
  real_T c2_d_y;
  real_T c2_a21;
  real_T c2_n_x;
  real_T c2_o_x;
  real_T c2_p_x;
  real_T c2_q_x;
  real_T c2_e_y;
  real_T c2_r_x;
  real_T c2_s_x;
  real_T c2_f_y;
  real_T c2_d;
  real_T c2_t_x;
  real_T c2_u_x;
  real_T c2_v_x;
  real_T c2_w_x;
  real_T c2_g_y;
  real_T c2_x_x;
  real_T c2_y_x;
  real_T c2_h_y;
  real_T c2_b_d;
  real_T c2_ab_x;
  real_T c2_bb_x;
  real_T c2_cb_x;
  real_T c2_db_x;
  real_T c2_i_y;
  real_T c2_eb_x;
  real_T c2_fb_x;
  real_T c2_j_y;
  real_T c2_c_d;
  int32_T c2_rtemp;
  int32_T c2_k;
  int32_T c2_b_k;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  for (c2_i295 = 0; c2_i295 < 9; c2_i295++) {
    c2_b_A[c2_i295] = c2_A[c2_i295];
  }

  c2_r1 = 1;
  c2_r2 = 2;
  c2_r3 = 3;
  c2_b_x = c2_b_A[0];
  c2_c_x = c2_b_x;
  c2_d_x = c2_c_x;
  c2_e_x = c2_d_x;
  c2_y = muDoubleScalarAbs(c2_e_x);
  c2_f_x = 0.0;
  c2_g_x = c2_f_x;
  c2_b_y = muDoubleScalarAbs(c2_g_x);
  c2_maxval = c2_y + c2_b_y;
  c2_h_x = c2_b_A[1];
  c2_i_x = c2_h_x;
  c2_j_x = c2_i_x;
  c2_k_x = c2_j_x;
  c2_c_y = muDoubleScalarAbs(c2_k_x);
  c2_l_x = 0.0;
  c2_m_x = c2_l_x;
  c2_d_y = muDoubleScalarAbs(c2_m_x);
  c2_a21 = c2_c_y + c2_d_y;
  if (c2_a21 > c2_maxval) {
    c2_maxval = c2_a21;
    c2_r1 = 2;
    c2_r2 = 1;
  }

  c2_n_x = c2_b_A[2];
  c2_o_x = c2_n_x;
  c2_p_x = c2_o_x;
  c2_q_x = c2_p_x;
  c2_e_y = muDoubleScalarAbs(c2_q_x);
  c2_r_x = 0.0;
  c2_s_x = c2_r_x;
  c2_f_y = muDoubleScalarAbs(c2_s_x);
  c2_d = c2_e_y + c2_f_y;
  if (c2_d > c2_maxval) {
    c2_r1 = 3;
    c2_r2 = 2;
    c2_r3 = 1;
  }

  c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_r2), 1, 3, 1, 0) - 1] = c2_rdivide(chartInstance,
    c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r2), 1, 3, 1, 0) - 1], c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r1), 1, 3, 1, 0) - 1]);
  c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_r3), 1, 3, 1, 0) - 1] = c2_rdivide(chartInstance,
    c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r3), 1, 3, 1, 0) - 1], c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r1), 1, 3, 1, 0) - 1]);
  c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_r2), 1, 3, 1, 0) + 2] = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c2_r2), 1, 3, 1, 0) + 2] -
    c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r2), 1, 3, 1, 0) - 1] * c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r1), 1, 3, 1, 0) + 2];
  c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_r3), 1, 3, 1, 0) + 2] = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c2_r3), 1, 3, 1, 0) + 2] -
    c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r3), 1, 3, 1, 0) - 1] * c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r1), 1, 3, 1, 0) + 2];
  c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_r2), 1, 3, 1, 0) + 5] = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c2_r2), 1, 3, 1, 0) + 5] -
    c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r2), 1, 3, 1, 0) - 1] * c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r1), 1, 3, 1, 0) + 5];
  c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_r3), 1, 3, 1, 0) + 5] = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c2_r3), 1, 3, 1, 0) + 5] -
    c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r3), 1, 3, 1, 0) - 1] * c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r1), 1, 3, 1, 0) + 5];
  c2_t_x = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r3), 1, 3, 1, 0) + 2];
  c2_u_x = c2_t_x;
  c2_v_x = c2_u_x;
  c2_w_x = c2_v_x;
  c2_g_y = muDoubleScalarAbs(c2_w_x);
  c2_x_x = 0.0;
  c2_y_x = c2_x_x;
  c2_h_y = muDoubleScalarAbs(c2_y_x);
  c2_b_d = c2_g_y + c2_h_y;
  c2_ab_x = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
    "", (real_T)c2_r2), 1, 3, 1, 0) + 2];
  c2_bb_x = c2_ab_x;
  c2_cb_x = c2_bb_x;
  c2_db_x = c2_cb_x;
  c2_i_y = muDoubleScalarAbs(c2_db_x);
  c2_eb_x = 0.0;
  c2_fb_x = c2_eb_x;
  c2_j_y = muDoubleScalarAbs(c2_fb_x);
  c2_c_d = c2_i_y + c2_j_y;
  if (c2_b_d > c2_c_d) {
    c2_rtemp = c2_r2;
    c2_r2 = c2_r3;
    c2_r3 = c2_rtemp;
  }

  c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_r3), 1, 3, 1, 0) + 2] = c2_rdivide(chartInstance,
    c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r3), 1, 3, 1, 0) + 2], c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r2), 1, 3, 1, 0) + 2]);
  c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
    c2_r3), 1, 3, 1, 0) + 5] = c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
    _SFD_INTEGER_CHECK("", (real_T)c2_r3), 1, 3, 1, 0) + 5] -
    c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
    (real_T)c2_r3), 1, 3, 1, 0) + 2] * c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
    (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r2), 1, 3, 1, 0) + 5];
  guard1 = false;
  guard2 = false;
  if (c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_r1), 1, 3, 1, 0) - 1] == 0.0) {
    guard2 = true;
  } else if (c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
               "", (real_T)c2_r2), 1, 3, 1, 0) + 2] == 0.0) {
    guard2 = true;
  } else {
    if (c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_r3), 1, 3, 1, 0) + 5] == 0.0) {
      guard1 = true;
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c2_eml_warning(chartInstance);
  }

  c2_eml_switch_helper(chartInstance);
  for (c2_k = 1; c2_k < 17; c2_k++) {
    c2_b_k = c2_k;
    c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r1), 1, 3, 2, 0) - 1) <<
           4)) - 1] = c2_rdivide(chartInstance,
      c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_b_k), 1, 16, 1, 0) - 1], c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                                  (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r1),
      1, 3, 1, 0) - 1]);
    c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r2), 1, 3, 2, 0) - 1) <<
           4)) - 1] = c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 1, 0) + 15] - c2_X
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c2_r1), 1, 3, 2, 0) - 1) << 4)) - 1] *
      c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_r1), 1, 3, 1, 0) + 2];
    c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r3), 1, 3, 2, 0) - 1) <<
           4)) - 1] = c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 1, 0) + 31] - c2_X
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
          c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
           _SFD_INTEGER_CHECK("", (real_T)c2_r1), 1, 3, 2, 0) - 1) << 4)) - 1] *
      c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_r1), 1, 3, 1, 0) + 5];
    c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r2), 1, 3, 2, 0) - 1) <<
           4)) - 1] = c2_rdivide(chartInstance, c2_X
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_r2), 1, 3, 2, 0) - 1) << 4)) - 1],
      c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_r2), 1, 3, 1, 0) + 2]);
    c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r3), 1, 3, 2, 0) - 1) <<
           4)) - 1] = c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 1, 0) +
      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_r3), 1, 3, 2, 0) - 1) << 4)) - 1] - c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 1, 0) +
      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_r2), 1, 3, 2, 0) - 1) << 4)) - 1] * c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r2), 1, 3, 1, 0) + 5];
    c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r3), 1, 3, 2, 0) - 1) <<
           4)) - 1] = c2_rdivide(chartInstance, c2_X
      [(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_r3), 1, 3, 2, 0) - 1) << 4)) - 1],
      c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_r3), 1, 3, 1, 0) + 5]);
    c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r2), 1, 3, 2, 0) - 1) <<
           4)) - 1] = c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 1, 0) +
      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_r2), 1, 3, 2, 0) - 1) << 4)) - 1] - c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 1, 0) +
      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_r3), 1, 3, 2, 0) - 1) << 4)) - 1] * c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r3), 1, 3, 1, 0) + 2];
    c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r1), 1, 3, 2, 0) - 1) <<
           4)) - 1] = c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 1, 0) +
      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_r1), 1, 3, 2, 0) - 1) << 4)) - 1] - c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 1, 0) +
      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_r3), 1, 3, 2, 0) - 1) << 4)) - 1] * c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r3), 1, 3, 1, 0) - 1];
    c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r1), 1, 3, 2, 0) - 1) <<
           4)) - 1] = c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
      _SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 1, 0) +
      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_r1), 1, 3, 2, 0) - 1) << 4)) - 1] - c2_X[(_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 1, 0) +
      ((_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("", (real_T)
      c2_r2), 1, 3, 2, 0) - 1) << 4)) - 1] * c2_b_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
      "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_r2), 1, 3, 1, 0) - 1];
  }
}

static void c2_b_eye(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
                     c2_I[256])
{
  int32_T c2_i296;
  int32_T c2_k;
  int32_T c2_b_k;
  for (c2_i296 = 0; c2_i296 < 256; c2_i296++) {
    c2_I[c2_i296] = 0.0;
  }

  c2_eml_switch_helper(chartInstance);
  for (c2_k = 1; c2_k < 17; c2_k++) {
    c2_b_k = c2_k;
    c2_I[(_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_k), 1, 16, 1, 0) + ((_SFD_EML_ARRAY_BOUNDS_CHECK("",
             (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_b_k), 1, 16, 2, 0) - 1) <<
           4)) - 1] = 1.0;
  }
}

static void c2_j_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_b_eml_xgemm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[48], real_T c2_b_B[48], real_T c2_C[256], real_T c2_b_C[256])
{
  int32_T c2_i297;
  int32_T c2_i298;
  real_T c2_b_A[48];
  int32_T c2_i299;
  real_T c2_c_B[48];
  for (c2_i297 = 0; c2_i297 < 256; c2_i297++) {
    c2_b_C[c2_i297] = c2_C[c2_i297];
  }

  for (c2_i298 = 0; c2_i298 < 48; c2_i298++) {
    c2_b_A[c2_i298] = c2_A[c2_i298];
  }

  for (c2_i299 = 0; c2_i299 < 48; c2_i299++) {
    c2_c_B[c2_i299] = c2_b_B[c2_i299];
  }

  c2_d_eml_xgemm(chartInstance, c2_b_A, c2_c_B, c2_b_C);
}

static void c2_k_eml_scalar_eg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_mldivide(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance, real_T
  c2_A[256], real_T c2_b_B[16], real_T c2_Y[16])
{
  int32_T c2_i300;
  real_T c2_b_A[256];
  int32_T c2_info;
  int32_T c2_ipiv[16];
  int32_T c2_b_info;
  int32_T c2_c_info;
  int32_T c2_d_info;
  int32_T c2_i301;
  int32_T c2_xi;
  int32_T c2_b_xi;
  int32_T c2_ip;
  real_T c2_temp;
  int32_T c2_i302;
  real_T c2_c_A[256];
  int32_T c2_i303;
  real_T c2_d_A[256];
  for (c2_i300 = 0; c2_i300 < 256; c2_i300++) {
    c2_b_A[c2_i300] = c2_A[c2_i300];
  }

  c2_c_eml_matlab_zgetrf(chartInstance, c2_b_A, c2_ipiv, &c2_info);
  c2_b_info = c2_info;
  c2_c_info = c2_b_info;
  c2_d_info = c2_c_info;
  if (c2_d_info > 0) {
    c2_eml_warning(chartInstance);
  }

  c2_eml_scalar_eg(chartInstance);
  for (c2_i301 = 0; c2_i301 < 16; c2_i301++) {
    c2_Y[c2_i301] = c2_b_B[c2_i301];
  }

  c2_eml_switch_helper(chartInstance);
  for (c2_xi = 1; c2_xi < 16; c2_xi++) {
    c2_b_xi = c2_xi;
    if (c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_xi), 1, 16, 1, 0) - 1] != c2_b_xi) {
      c2_ip = c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
        _SFD_INTEGER_CHECK("", (real_T)c2_b_xi), 1, 16, 1, 0) - 1];
      c2_temp = c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
        ("", (real_T)c2_b_xi), 1, 16, 1, 0) - 1];
      c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_xi), 1, 16, 1, 0) - 1] = c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK(
        "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_ip), 1, 16, 1, 0) - 1];
      c2_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_ip), 1, 16, 1, 0) - 1] = c2_temp;
    }
  }

  for (c2_i302 = 0; c2_i302 < 256; c2_i302++) {
    c2_c_A[c2_i302] = c2_b_A[c2_i302];
  }

  c2_o_eml_xtrsm(chartInstance, c2_c_A, c2_Y);
  for (c2_i303 = 0; c2_i303 < 256; c2_i303++) {
    c2_d_A[c2_i303] = c2_b_A[c2_i303];
  }

  c2_p_eml_xtrsm(chartInstance, c2_d_A, c2_Y);
}

static void c2_g_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[16], real_T c2_c_B[16])
{
  int32_T c2_i304;
  int32_T c2_i305;
  real_T c2_b_A[256];
  for (c2_i304 = 0; c2_i304 < 16; c2_i304++) {
    c2_c_B[c2_i304] = c2_b_B[c2_i304];
  }

  for (c2_i305 = 0; c2_i305 < 256; c2_i305++) {
    c2_b_A[c2_i305] = c2_A[c2_i305];
  }

  c2_o_eml_xtrsm(chartInstance, c2_b_A, c2_c_B);
}

static void c2_d_below_threshold(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  c2_c_eml_switch_helper(chartInstance);
}

static void c2_b_scalarEg(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c2_h_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[16], real_T c2_c_B[16])
{
  int32_T c2_i306;
  int32_T c2_i307;
  real_T c2_b_A[256];
  for (c2_i306 = 0; c2_i306 < 16; c2_i306++) {
    c2_c_B[c2_i306] = c2_b_B[c2_i306];
  }

  for (c2_i307 = 0; c2_i307 < 256; c2_i307++) {
    c2_b_A[c2_i307] = c2_A[c2_i307];
  }

  c2_p_eml_xtrsm(chartInstance, c2_b_A, c2_c_B);
}

static const mxArray *c2_n_sf_marshallOut(void *chartInstanceVoid, void
  *c2_inData)
{
  const mxArray *c2_mxArrayOutData = NULL;
  int32_T c2_b_u;
  const mxArray *c2_y = NULL;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_mxArrayOutData = NULL;
  c2_b_u = *(int32_T *)c2_inData;
  c2_y = NULL;
  sf_mex_assign(&c2_y, sf_mex_create("y", &c2_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c2_mxArrayOutData, c2_y, false);
  return c2_mxArrayOutData;
}

static int32_T c2_m_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  int32_T c2_y;
  int32_T c2_i308;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_i308, 1, 6, 0U, 0, 0U, 0);
  c2_y = c2_i308;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void c2_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c2_mxArrayInData, const char_T *c2_varName, void *c2_outData)
{
  const mxArray *c2_b_sfEvent;
  const char_T *c2_identifier;
  emlrtMsgIdentifier c2_thisId;
  int32_T c2_y;
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c2_b_sfEvent = sf_mex_dup(c2_mxArrayInData);
  c2_identifier = c2_varName;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c2_b_sfEvent),
    &c2_thisId);
  sf_mex_destroy(&c2_b_sfEvent);
  *(int32_T *)c2_outData = c2_y;
  sf_mex_destroy(&c2_mxArrayInData);
}

static uint8_T c2_n_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_is_active_c2_DDA2D_OSU3Dv2, const char_T
  *c2_identifier)
{
  uint8_T c2_y;
  emlrtMsgIdentifier c2_thisId;
  c2_thisId.fIdentifier = c2_identifier;
  c2_thisId.fParent = NULL;
  c2_y = c2_o_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c2_b_is_active_c2_DDA2D_OSU3Dv2), &c2_thisId);
  sf_mex_destroy(&c2_b_is_active_c2_DDA2D_OSU3Dv2);
  return c2_y;
}

static uint8_T c2_o_emlrt_marshallIn(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c2_b_u, const emlrtMsgIdentifier *c2_parentId)
{
  uint8_T c2_y;
  uint8_T c2_u0;
  (void)chartInstance;
  sf_mex_import(c2_parentId, sf_mex_dup(c2_b_u), &c2_u0, 1, 3, 0U, 0, 0U, 0);
  c2_y = c2_u0;
  sf_mex_destroy(&c2_b_u);
  return c2_y;
}

static void c2_c_eml_matlab_zgetrf(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c2_A[256], int32_T c2_ipiv[16], int32_T *c2_info)
{
  int32_T c2_i309;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_a;
  int32_T c2_b_a;
  int32_T c2_jm1;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_mmj;
  int32_T c2_c_a;
  int32_T c2_d_a;
  int32_T c2_c;
  int32_T c2_c_b;
  int32_T c2_d_b;
  int32_T c2_jj;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_jp1j;
  int32_T c2_g_a;
  int32_T c2_h_a;
  int32_T c2_b_c;
  int32_T c2_n;
  int32_T c2_ix0;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_c_n;
  int32_T c2_c_ix0;
  int32_T c2_idxmax;
  int32_T c2_ix;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_b_y;
  real_T c2_smax;
  int32_T c2_d_n;
  int32_T c2_e_b;
  int32_T c2_f_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_i_a;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_c_y;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_d_y;
  real_T c2_s;
  int32_T c2_j_a;
  int32_T c2_k_a;
  int32_T c2_jpiv_offset;
  int32_T c2_l_a;
  int32_T c2_g_b;
  int32_T c2_m_a;
  int32_T c2_h_b;
  int32_T c2_jpiv;
  int32_T c2_n_a;
  int32_T c2_i_b;
  int32_T c2_o_a;
  int32_T c2_j_b;
  int32_T c2_c_c;
  int32_T c2_k_b;
  int32_T c2_l_b;
  int32_T c2_jrow;
  int32_T c2_p_a;
  int32_T c2_m_b;
  int32_T c2_q_a;
  int32_T c2_n_b;
  int32_T c2_jprow;
  int32_T c2_b_jp1j;
  int32_T c2_r_a;
  int32_T c2_s_a;
  int32_T c2_d_c;
  int32_T c2_t_a;
  int32_T c2_o_b;
  int32_T c2_u_a;
  int32_T c2_p_b;
  int32_T c2_i310;
  int32_T c2_v_a;
  int32_T c2_q_b;
  int32_T c2_w_a;
  int32_T c2_r_b;
  boolean_T c2_b_overflow;
  int32_T c2_i;
  int32_T c2_b_i;
  real_T c2_l_x;
  real_T c2_e_y;
  real_T c2_m_x;
  real_T c2_f_y;
  real_T c2_z;
  int32_T c2_s_b;
  int32_T c2_t_b;
  int32_T c2_e_c;
  int32_T c2_x_a;
  int32_T c2_y_a;
  int32_T c2_f_c;
  int32_T c2_ab_a;
  int32_T c2_bb_a;
  int32_T c2_g_c;
  c2_realmin(chartInstance);
  c2_eps(chartInstance);
  for (c2_i309 = 0; c2_i309 < 16; c2_i309++) {
    c2_ipiv[c2_i309] = 1 + c2_i309;
  }

  *c2_info = 0;
  c2_eml_switch_helper(chartInstance);
  for (c2_j = 1; c2_j < 16; c2_j++) {
    c2_b_j = c2_j;
    c2_a = c2_b_j;
    c2_b_a = c2_a - 1;
    c2_jm1 = c2_b_a;
    c2_b = c2_b_j;
    c2_b_b = c2_b;
    c2_mmj = 16 - c2_b_b;
    c2_c_a = c2_jm1;
    c2_d_a = c2_c_a;
    c2_c = c2_d_a * 17;
    c2_c_b = c2_c;
    c2_d_b = c2_c_b + 1;
    c2_jj = c2_d_b;
    c2_e_a = c2_jj;
    c2_f_a = c2_e_a + 1;
    c2_jp1j = c2_f_a;
    c2_g_a = c2_mmj;
    c2_h_a = c2_g_a;
    c2_b_c = c2_h_a;
    c2_n = c2_b_c + 1;
    c2_ix0 = c2_jj;
    c2_b_n = c2_n;
    c2_b_ix0 = c2_ix0;
    c2_b_threshold(chartInstance);
    c2_c_n = c2_b_n;
    c2_c_ix0 = c2_b_ix0;
    if (c2_c_n < 1) {
      c2_idxmax = 0;
    } else {
      c2_idxmax = 1;
      if (c2_c_n > 1) {
        c2_ix = c2_c_ix0;
        c2_b_x = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 256, 1, 0) - 1];
        c2_c_x = c2_b_x;
        c2_d_x = c2_c_x;
        c2_y = muDoubleScalarAbs(c2_d_x);
        c2_e_x = 0.0;
        c2_f_x = c2_e_x;
        c2_b_y = muDoubleScalarAbs(c2_f_x);
        c2_smax = c2_y + c2_b_y;
        c2_d_n = c2_c_n;
        c2_e_b = c2_d_n;
        c2_f_b = c2_e_b;
        if (2 > c2_f_b) {
          c2_overflow = false;
        } else {
          c2_eml_switch_helper(chartInstance);
          c2_eml_switch_helper(chartInstance);
          c2_overflow = (c2_f_b > 2147483646);
        }

        if (c2_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_overflow);
        }

        for (c2_k = 2; c2_k <= c2_d_n; c2_k++) {
          c2_b_k = c2_k;
          c2_i_a = c2_ix + 1;
          c2_ix = c2_i_a;
          c2_g_x = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 256, 1, 0) - 1];
          c2_h_x = c2_g_x;
          c2_i_x = c2_h_x;
          c2_c_y = muDoubleScalarAbs(c2_i_x);
          c2_j_x = 0.0;
          c2_k_x = c2_j_x;
          c2_d_y = muDoubleScalarAbs(c2_k_x);
          c2_s = c2_c_y + c2_d_y;
          if (c2_s > c2_smax) {
            c2_idxmax = c2_b_k;
            c2_smax = c2_s;
          }
        }
      }
    }

    c2_j_a = c2_idxmax;
    c2_k_a = c2_j_a - 1;
    c2_jpiv_offset = c2_k_a;
    c2_l_a = c2_jj;
    c2_g_b = c2_jpiv_offset;
    c2_m_a = c2_l_a;
    c2_h_b = c2_g_b;
    c2_jpiv = c2_m_a + c2_h_b;
    if (c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_jpiv), 1, 256, 1, 0) - 1] != 0.0) {
      if (c2_jpiv_offset != 0) {
        c2_n_a = c2_b_j;
        c2_i_b = c2_jpiv_offset;
        c2_o_a = c2_n_a;
        c2_j_b = c2_i_b;
        c2_c_c = c2_o_a + c2_j_b;
        c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_j), 1, 16, 1, 0) - 1] = c2_c_c;
        c2_k_b = c2_jm1;
        c2_l_b = c2_k_b + 1;
        c2_jrow = c2_l_b;
        c2_p_a = c2_jrow;
        c2_m_b = c2_jpiv_offset;
        c2_q_a = c2_p_a;
        c2_n_b = c2_m_b;
        c2_jprow = c2_q_a + c2_n_b;
        c2_b_eml_xswap(chartInstance, c2_A, c2_jrow, c2_jprow);
      }

      c2_b_jp1j = c2_jp1j;
      c2_r_a = c2_mmj;
      c2_s_a = c2_r_a;
      c2_d_c = c2_s_a;
      c2_t_a = c2_jp1j;
      c2_o_b = c2_d_c - 1;
      c2_u_a = c2_t_a;
      c2_p_b = c2_o_b;
      c2_i310 = c2_u_a + c2_p_b;
      c2_v_a = c2_b_jp1j;
      c2_q_b = c2_i310;
      c2_w_a = c2_v_a;
      c2_r_b = c2_q_b;
      if (c2_w_a > c2_r_b) {
        c2_b_overflow = false;
      } else {
        c2_eml_switch_helper(chartInstance);
        c2_eml_switch_helper(chartInstance);
        c2_b_overflow = (c2_r_b > 2147483646);
      }

      if (c2_b_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_b_overflow);
      }

      for (c2_i = c2_b_jp1j; c2_i <= c2_i310; c2_i++) {
        c2_b_i = c2_i;
        c2_l_x = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 256, 1, 0) - 1];
        c2_e_y = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_jj), 1, 256, 1, 0) - 1];
        c2_m_x = c2_l_x;
        c2_f_y = c2_e_y;
        c2_z = c2_m_x / c2_f_y;
        c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_i), 1, 256, 1, 0) - 1] = c2_z;
      }
    } else {
      *c2_info = c2_b_j;
    }

    c2_s_b = c2_b_j;
    c2_t_b = c2_s_b;
    c2_e_c = 16 - c2_t_b;
    c2_x_a = c2_jj;
    c2_y_a = c2_x_a;
    c2_f_c = c2_y_a;
    c2_ab_a = c2_jj;
    c2_bb_a = c2_ab_a;
    c2_g_c = c2_bb_a;
    c2_c_eml_xgeru(chartInstance, c2_mmj, c2_e_c, -1.0, c2_jp1j, c2_f_c + 16,
                   c2_A, c2_g_c + 17);
  }

  if (*c2_info == 0) {
    if (!(c2_A[255] != 0.0)) {
      *c2_info = 16;
    }
  }
}

static void c2_b_eml_xswap(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_b_x[256], int32_T c2_ix0, int32_T c2_iy0)
{
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_ix;
  int32_T c2_iy;
  int32_T c2_k;
  real_T c2_temp;
  int32_T c2_a;
  int32_T c2_b_a;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_b_eml_switch_helper(chartInstance);
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  c2_ix = c2_c_ix0;
  c2_iy = c2_c_iy0;
  c2_eml_switch_helper(chartInstance);
  for (c2_k = 1; c2_k < 17; c2_k++) {
    c2_temp = c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK
      ("", (real_T)c2_ix), 1, 256, 1, 0) - 1];
    c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_ix), 1, 256, 1, 0) - 1] = c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("",
      (int32_T)_SFD_INTEGER_CHECK("", (real_T)c2_iy), 1, 256, 1, 0) - 1];
    c2_b_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
      (real_T)c2_iy), 1, 256, 1, 0) - 1] = c2_temp;
    c2_a = c2_ix + 16;
    c2_ix = c2_a;
    c2_b_a = c2_iy + 16;
    c2_iy = c2_b_a;
  }
}

static void c2_c_eml_xgeru(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_A[256], int32_T c2_ia0)
{
  int32_T c2_b_m;
  int32_T c2_b_n;
  real_T c2_b_alpha1;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_ia0;
  int32_T c2_c_m;
  int32_T c2_c_n;
  real_T c2_c_alpha1;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_c_ia0;
  int32_T c2_d_m;
  int32_T c2_d_n;
  real_T c2_d_alpha1;
  int32_T c2_d_ix0;
  int32_T c2_d_iy0;
  int32_T c2_d_ia0;
  int32_T c2_e_m;
  int32_T c2_e_n;
  real_T c2_e_alpha1;
  int32_T c2_e_ix0;
  int32_T c2_e_iy0;
  int32_T c2_e_ia0;
  int32_T c2_ixstart;
  int32_T c2_a;
  int32_T c2_jA;
  int32_T c2_jy;
  int32_T c2_f_n;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_j;
  real_T c2_yjy;
  real_T c2_temp;
  int32_T c2_ix;
  int32_T c2_c_b;
  int32_T c2_i311;
  int32_T c2_b_a;
  int32_T c2_d_b;
  int32_T c2_i312;
  int32_T c2_c_a;
  int32_T c2_e_b;
  int32_T c2_d_a;
  int32_T c2_f_b;
  boolean_T c2_b_overflow;
  int32_T c2_ijA;
  int32_T c2_b_ijA;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_g_a;
  c2_b_m = c2_m;
  c2_b_n = c2_n;
  c2_b_alpha1 = c2_alpha1;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_b_ia0 = c2_ia0;
  c2_c_m = c2_b_m;
  c2_c_n = c2_b_n;
  c2_c_alpha1 = c2_b_alpha1;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  c2_c_ia0 = c2_b_ia0;
  c2_c_threshold(chartInstance);
  c2_d_m = c2_c_m;
  c2_d_n = c2_c_n;
  c2_d_alpha1 = c2_c_alpha1;
  c2_d_ix0 = c2_c_ix0;
  c2_d_iy0 = c2_c_iy0;
  c2_d_ia0 = c2_c_ia0;
  c2_e_m = c2_d_m;
  c2_e_n = c2_d_n;
  c2_e_alpha1 = c2_d_alpha1;
  c2_e_ix0 = c2_d_ix0;
  c2_e_iy0 = c2_d_iy0;
  c2_e_ia0 = c2_d_ia0;
  if (c2_e_alpha1 == 0.0) {
  } else {
    c2_ixstart = c2_e_ix0;
    c2_a = c2_e_ia0 - 1;
    c2_jA = c2_a;
    c2_jy = c2_e_iy0;
    c2_f_n = c2_e_n;
    c2_b = c2_f_n;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_eml_switch_helper(chartInstance);
      c2_eml_switch_helper(chartInstance);
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_j = 1; c2_j <= c2_f_n; c2_j++) {
      c2_yjy = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c2_jy), 1, 256, 1, 0) - 1];
      if (c2_yjy != 0.0) {
        c2_temp = c2_yjy * c2_e_alpha1;
        c2_ix = c2_ixstart;
        c2_c_b = c2_jA + 1;
        c2_i311 = c2_c_b;
        c2_b_a = c2_e_m;
        c2_d_b = c2_jA;
        c2_i312 = c2_b_a + c2_d_b;
        c2_c_a = c2_i311;
        c2_e_b = c2_i312;
        c2_d_a = c2_c_a;
        c2_f_b = c2_e_b;
        if (c2_d_a > c2_f_b) {
          c2_b_overflow = false;
        } else {
          c2_eml_switch_helper(chartInstance);
          c2_eml_switch_helper(chartInstance);
          c2_b_overflow = (c2_f_b > 2147483646);
        }

        if (c2_b_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_b_overflow);
        }

        for (c2_ijA = c2_i311; c2_ijA <= c2_i312; c2_ijA++) {
          c2_b_ijA = c2_ijA;
          c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_ijA), 1, 256, 1, 0) - 1] =
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_ijA), 1, 256, 1, 0) - 1] +
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_ix), 1, 256, 1, 0) - 1] * c2_temp;
          c2_e_a = c2_ix + 1;
          c2_ix = c2_e_a;
        }
      }

      c2_f_a = c2_jy + 16;
      c2_jy = c2_f_a;
      c2_g_a = c2_jA + 16;
      c2_jA = c2_g_a;
    }
  }
}

static void c2_i_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[80])
{
  real_T c2_alpha1;
  char_T c2_DIAGA;
  char_T c2_TRANSA;
  char_T c2_UPLO;
  char_T c2_SIDE;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  double * c2_Aia0_t;
  double * c2_Bib0_t;
  double * c2_alpha1_t;
  c2_below_threshold(chartInstance);
  c2_alpha1 = 1.0;
  c2_DIAGA = 'N';
  c2_TRANSA = 'N';
  c2_UPLO = 'U';
  c2_SIDE = 'R';
  c2_m_t = (ptrdiff_t)(5);
  c2_n_t = (ptrdiff_t)(16);
  c2_lda_t = (ptrdiff_t)(16);
  c2_ldb_t = (ptrdiff_t)(5);
  c2_Aia0_t = (double *)(&c2_A[0]);
  c2_Bib0_t = (double *)(&c2_b_B[0]);
  c2_alpha1_t = (double *)(&c2_alpha1);
  dtrsm(&c2_SIDE, &c2_UPLO, &c2_TRANSA, &c2_DIAGA, &c2_m_t, &c2_n_t, c2_alpha1_t,
        c2_Aia0_t, &c2_lda_t, c2_Bib0_t, &c2_ldb_t);
}

static void c2_j_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[80])
{
  real_T c2_alpha1;
  char_T c2_DIAGA;
  char_T c2_TRANSA;
  char_T c2_UPLO;
  char_T c2_SIDE;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  double * c2_Aia0_t;
  double * c2_Bib0_t;
  double * c2_alpha1_t;
  c2_below_threshold(chartInstance);
  c2_alpha1 = 1.0;
  c2_DIAGA = 'U';
  c2_TRANSA = 'N';
  c2_UPLO = 'L';
  c2_SIDE = 'R';
  c2_m_t = (ptrdiff_t)(5);
  c2_n_t = (ptrdiff_t)(16);
  c2_lda_t = (ptrdiff_t)(16);
  c2_ldb_t = (ptrdiff_t)(5);
  c2_Aia0_t = (double *)(&c2_A[0]);
  c2_Bib0_t = (double *)(&c2_b_B[0]);
  c2_alpha1_t = (double *)(&c2_alpha1);
  dtrsm(&c2_SIDE, &c2_UPLO, &c2_TRANSA, &c2_DIAGA, &c2_m_t, &c2_n_t, c2_alpha1_t,
        c2_Aia0_t, &c2_lda_t, c2_Bib0_t, &c2_ldb_t);
}

static void c2_d_eml_matlab_zgetrf(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c2_A[25], int32_T c2_ipiv[5], int32_T *c2_info)
{
  int32_T c2_i313;
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_a;
  int32_T c2_b_a;
  int32_T c2_jm1;
  int32_T c2_b;
  int32_T c2_b_b;
  int32_T c2_mmj;
  int32_T c2_c_a;
  int32_T c2_d_a;
  int32_T c2_c;
  int32_T c2_c_b;
  int32_T c2_d_b;
  int32_T c2_jj;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_jp1j;
  int32_T c2_g_a;
  int32_T c2_h_a;
  int32_T c2_b_c;
  int32_T c2_n;
  int32_T c2_ix0;
  int32_T c2_b_n;
  int32_T c2_b_ix0;
  int32_T c2_c_n;
  int32_T c2_c_ix0;
  int32_T c2_idxmax;
  int32_T c2_ix;
  real_T c2_b_x;
  real_T c2_c_x;
  real_T c2_d_x;
  real_T c2_y;
  real_T c2_e_x;
  real_T c2_f_x;
  real_T c2_b_y;
  real_T c2_smax;
  int32_T c2_d_n;
  int32_T c2_e_b;
  int32_T c2_f_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_i_a;
  real_T c2_g_x;
  real_T c2_h_x;
  real_T c2_i_x;
  real_T c2_c_y;
  real_T c2_j_x;
  real_T c2_k_x;
  real_T c2_d_y;
  real_T c2_s;
  int32_T c2_j_a;
  int32_T c2_k_a;
  int32_T c2_jpiv_offset;
  int32_T c2_l_a;
  int32_T c2_g_b;
  int32_T c2_m_a;
  int32_T c2_h_b;
  int32_T c2_jpiv;
  int32_T c2_n_a;
  int32_T c2_i_b;
  int32_T c2_o_a;
  int32_T c2_j_b;
  int32_T c2_c_c;
  int32_T c2_k_b;
  int32_T c2_l_b;
  int32_T c2_jrow;
  int32_T c2_p_a;
  int32_T c2_m_b;
  int32_T c2_q_a;
  int32_T c2_n_b;
  int32_T c2_jprow;
  int32_T c2_d_ix0;
  int32_T c2_iy0;
  int32_T c2_e_ix0;
  int32_T c2_b_iy0;
  int32_T c2_f_ix0;
  int32_T c2_c_iy0;
  int32_T c2_b_ix;
  int32_T c2_iy;
  int32_T c2_c_k;
  real_T c2_temp;
  int32_T c2_r_a;
  int32_T c2_s_a;
  int32_T c2_b_jp1j;
  int32_T c2_t_a;
  int32_T c2_u_a;
  int32_T c2_d_c;
  int32_T c2_v_a;
  int32_T c2_o_b;
  int32_T c2_w_a;
  int32_T c2_p_b;
  int32_T c2_i314;
  int32_T c2_x_a;
  int32_T c2_q_b;
  int32_T c2_y_a;
  int32_T c2_r_b;
  boolean_T c2_b_overflow;
  int32_T c2_i;
  int32_T c2_b_i;
  real_T c2_l_x;
  real_T c2_e_y;
  real_T c2_m_x;
  real_T c2_f_y;
  real_T c2_z;
  int32_T c2_s_b;
  int32_T c2_t_b;
  int32_T c2_e_c;
  int32_T c2_ab_a;
  int32_T c2_bb_a;
  int32_T c2_f_c;
  int32_T c2_cb_a;
  int32_T c2_db_a;
  int32_T c2_g_c;
  c2_realmin(chartInstance);
  c2_eps(chartInstance);
  for (c2_i313 = 0; c2_i313 < 5; c2_i313++) {
    c2_ipiv[c2_i313] = 1 + c2_i313;
  }

  *c2_info = 0;
  c2_eml_switch_helper(chartInstance);
  for (c2_j = 1; c2_j < 5; c2_j++) {
    c2_b_j = c2_j;
    c2_a = c2_b_j;
    c2_b_a = c2_a - 1;
    c2_jm1 = c2_b_a;
    c2_b = c2_b_j;
    c2_b_b = c2_b;
    c2_mmj = 5 - c2_b_b;
    c2_c_a = c2_jm1;
    c2_d_a = c2_c_a;
    c2_c = c2_d_a * 6;
    c2_c_b = c2_c;
    c2_d_b = c2_c_b + 1;
    c2_jj = c2_d_b;
    c2_e_a = c2_jj;
    c2_f_a = c2_e_a + 1;
    c2_jp1j = c2_f_a;
    c2_g_a = c2_mmj;
    c2_h_a = c2_g_a;
    c2_b_c = c2_h_a;
    c2_n = c2_b_c + 1;
    c2_ix0 = c2_jj;
    c2_b_n = c2_n;
    c2_b_ix0 = c2_ix0;
    c2_b_threshold(chartInstance);
    c2_c_n = c2_b_n;
    c2_c_ix0 = c2_b_ix0;
    if (c2_c_n < 1) {
      c2_idxmax = 0;
    } else {
      c2_idxmax = 1;
      if (c2_c_n > 1) {
        c2_ix = c2_c_ix0;
        c2_b_x = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 25, 1, 0) - 1];
        c2_c_x = c2_b_x;
        c2_d_x = c2_c_x;
        c2_y = muDoubleScalarAbs(c2_d_x);
        c2_e_x = 0.0;
        c2_f_x = c2_e_x;
        c2_b_y = muDoubleScalarAbs(c2_f_x);
        c2_smax = c2_y + c2_b_y;
        c2_d_n = c2_c_n;
        c2_e_b = c2_d_n;
        c2_f_b = c2_e_b;
        if (2 > c2_f_b) {
          c2_overflow = false;
        } else {
          c2_eml_switch_helper(chartInstance);
          c2_eml_switch_helper(chartInstance);
          c2_overflow = (c2_f_b > 2147483646);
        }

        if (c2_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_overflow);
        }

        for (c2_k = 2; c2_k <= c2_d_n; c2_k++) {
          c2_b_k = c2_k;
          c2_i_a = c2_ix + 1;
          c2_ix = c2_i_a;
          c2_g_x = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_ix), 1, 25, 1, 0) - 1];
          c2_h_x = c2_g_x;
          c2_i_x = c2_h_x;
          c2_c_y = muDoubleScalarAbs(c2_i_x);
          c2_j_x = 0.0;
          c2_k_x = c2_j_x;
          c2_d_y = muDoubleScalarAbs(c2_k_x);
          c2_s = c2_c_y + c2_d_y;
          if (c2_s > c2_smax) {
            c2_idxmax = c2_b_k;
            c2_smax = c2_s;
          }
        }
      }
    }

    c2_j_a = c2_idxmax;
    c2_k_a = c2_j_a - 1;
    c2_jpiv_offset = c2_k_a;
    c2_l_a = c2_jj;
    c2_g_b = c2_jpiv_offset;
    c2_m_a = c2_l_a;
    c2_h_b = c2_g_b;
    c2_jpiv = c2_m_a + c2_h_b;
    if (c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_jpiv), 1, 25, 1, 0) - 1] != 0.0) {
      if (c2_jpiv_offset != 0) {
        c2_n_a = c2_b_j;
        c2_i_b = c2_jpiv_offset;
        c2_o_a = c2_n_a;
        c2_j_b = c2_i_b;
        c2_c_c = c2_o_a + c2_j_b;
        c2_ipiv[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_j), 1, 5, 1, 0) - 1] = c2_c_c;
        c2_k_b = c2_jm1;
        c2_l_b = c2_k_b + 1;
        c2_jrow = c2_l_b;
        c2_p_a = c2_jrow;
        c2_m_b = c2_jpiv_offset;
        c2_q_a = c2_p_a;
        c2_n_b = c2_m_b;
        c2_jprow = c2_q_a + c2_n_b;
        c2_d_ix0 = c2_jrow;
        c2_iy0 = c2_jprow;
        c2_e_ix0 = c2_d_ix0;
        c2_b_iy0 = c2_iy0;
        c2_b_eml_switch_helper(chartInstance);
        c2_f_ix0 = c2_e_ix0;
        c2_c_iy0 = c2_b_iy0;
        c2_b_ix = c2_f_ix0;
        c2_iy = c2_c_iy0;
        c2_eml_switch_helper(chartInstance);
        for (c2_c_k = 1; c2_c_k < 6; c2_c_k++) {
          c2_temp = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
            _SFD_INTEGER_CHECK("", (real_T)c2_b_ix), 1, 25, 1, 0) - 1];
          c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_ix), 1, 25, 1, 0) - 1] =
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_iy), 1, 25, 1, 0) - 1];
          c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_iy), 1, 25, 1, 0) - 1] = c2_temp;
          c2_r_a = c2_b_ix + 5;
          c2_b_ix = c2_r_a;
          c2_s_a = c2_iy + 5;
          c2_iy = c2_s_a;
        }
      }

      c2_b_jp1j = c2_jp1j;
      c2_t_a = c2_mmj;
      c2_u_a = c2_t_a;
      c2_d_c = c2_u_a;
      c2_v_a = c2_jp1j;
      c2_o_b = c2_d_c - 1;
      c2_w_a = c2_v_a;
      c2_p_b = c2_o_b;
      c2_i314 = c2_w_a + c2_p_b;
      c2_x_a = c2_b_jp1j;
      c2_q_b = c2_i314;
      c2_y_a = c2_x_a;
      c2_r_b = c2_q_b;
      if (c2_y_a > c2_r_b) {
        c2_b_overflow = false;
      } else {
        c2_eml_switch_helper(chartInstance);
        c2_eml_switch_helper(chartInstance);
        c2_b_overflow = (c2_r_b > 2147483646);
      }

      if (c2_b_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_b_overflow);
      }

      for (c2_i = c2_b_jp1j; c2_i <= c2_i314; c2_i++) {
        c2_b_i = c2_i;
        c2_l_x = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_b_i), 1, 25, 1, 0) - 1];
        c2_e_y = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)
          _SFD_INTEGER_CHECK("", (real_T)c2_jj), 1, 25, 1, 0) - 1];
        c2_m_x = c2_l_x;
        c2_f_y = c2_e_y;
        c2_z = c2_m_x / c2_f_y;
        c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_i), 1, 25, 1, 0) - 1] = c2_z;
      }
    } else {
      *c2_info = c2_b_j;
    }

    c2_s_b = c2_b_j;
    c2_t_b = c2_s_b;
    c2_e_c = 5 - c2_t_b;
    c2_ab_a = c2_jj;
    c2_bb_a = c2_ab_a;
    c2_f_c = c2_bb_a;
    c2_cb_a = c2_jj;
    c2_db_a = c2_cb_a;
    c2_g_c = c2_db_a;
    c2_d_eml_xgeru(chartInstance, c2_mmj, c2_e_c, -1.0, c2_jp1j, c2_f_c + 5,
                   c2_A, c2_g_c + 6);
  }

  if (*c2_info == 0) {
    if (!(c2_A[24] != 0.0)) {
      *c2_info = 5;
    }
  }
}

static void c2_d_eml_xgeru(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  int32_T c2_m, int32_T c2_n, real_T c2_alpha1, int32_T c2_ix0, int32_T c2_iy0,
  real_T c2_A[25], int32_T c2_ia0)
{
  int32_T c2_b_m;
  int32_T c2_b_n;
  real_T c2_b_alpha1;
  int32_T c2_b_ix0;
  int32_T c2_b_iy0;
  int32_T c2_b_ia0;
  int32_T c2_c_m;
  int32_T c2_c_n;
  real_T c2_c_alpha1;
  int32_T c2_c_ix0;
  int32_T c2_c_iy0;
  int32_T c2_c_ia0;
  int32_T c2_d_m;
  int32_T c2_d_n;
  real_T c2_d_alpha1;
  int32_T c2_d_ix0;
  int32_T c2_d_iy0;
  int32_T c2_d_ia0;
  int32_T c2_e_m;
  int32_T c2_e_n;
  real_T c2_e_alpha1;
  int32_T c2_e_ix0;
  int32_T c2_e_iy0;
  int32_T c2_e_ia0;
  int32_T c2_ixstart;
  int32_T c2_a;
  int32_T c2_jA;
  int32_T c2_jy;
  int32_T c2_f_n;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_j;
  real_T c2_yjy;
  real_T c2_temp;
  int32_T c2_ix;
  int32_T c2_c_b;
  int32_T c2_i315;
  int32_T c2_b_a;
  int32_T c2_d_b;
  int32_T c2_i316;
  int32_T c2_c_a;
  int32_T c2_e_b;
  int32_T c2_d_a;
  int32_T c2_f_b;
  boolean_T c2_b_overflow;
  int32_T c2_ijA;
  int32_T c2_b_ijA;
  int32_T c2_e_a;
  int32_T c2_f_a;
  int32_T c2_g_a;
  c2_b_m = c2_m;
  c2_b_n = c2_n;
  c2_b_alpha1 = c2_alpha1;
  c2_b_ix0 = c2_ix0;
  c2_b_iy0 = c2_iy0;
  c2_b_ia0 = c2_ia0;
  c2_c_m = c2_b_m;
  c2_c_n = c2_b_n;
  c2_c_alpha1 = c2_b_alpha1;
  c2_c_ix0 = c2_b_ix0;
  c2_c_iy0 = c2_b_iy0;
  c2_c_ia0 = c2_b_ia0;
  c2_c_threshold(chartInstance);
  c2_d_m = c2_c_m;
  c2_d_n = c2_c_n;
  c2_d_alpha1 = c2_c_alpha1;
  c2_d_ix0 = c2_c_ix0;
  c2_d_iy0 = c2_c_iy0;
  c2_d_ia0 = c2_c_ia0;
  c2_e_m = c2_d_m;
  c2_e_n = c2_d_n;
  c2_e_alpha1 = c2_d_alpha1;
  c2_e_ix0 = c2_d_ix0;
  c2_e_iy0 = c2_d_iy0;
  c2_e_ia0 = c2_d_ia0;
  if (c2_e_alpha1 == 0.0) {
  } else {
    c2_ixstart = c2_e_ix0;
    c2_a = c2_e_ia0 - 1;
    c2_jA = c2_a;
    c2_jy = c2_e_iy0;
    c2_f_n = c2_e_n;
    c2_b = c2_f_n;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_eml_switch_helper(chartInstance);
      c2_eml_switch_helper(chartInstance);
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_j = 1; c2_j <= c2_f_n; c2_j++) {
      c2_yjy = c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
        "", (real_T)c2_jy), 1, 25, 1, 0) - 1];
      if (c2_yjy != 0.0) {
        c2_temp = c2_yjy * c2_e_alpha1;
        c2_ix = c2_ixstart;
        c2_c_b = c2_jA + 1;
        c2_i315 = c2_c_b;
        c2_b_a = c2_e_m;
        c2_d_b = c2_jA;
        c2_i316 = c2_b_a + c2_d_b;
        c2_c_a = c2_i315;
        c2_e_b = c2_i316;
        c2_d_a = c2_c_a;
        c2_f_b = c2_e_b;
        if (c2_d_a > c2_f_b) {
          c2_b_overflow = false;
        } else {
          c2_eml_switch_helper(chartInstance);
          c2_eml_switch_helper(chartInstance);
          c2_b_overflow = (c2_f_b > 2147483646);
        }

        if (c2_b_overflow) {
          c2_check_forloop_overflow_error(chartInstance, c2_b_overflow);
        }

        for (c2_ijA = c2_i315; c2_ijA <= c2_i316; c2_ijA++) {
          c2_b_ijA = c2_ijA;
          c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_ijA), 1, 25, 1, 0) - 1] =
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_b_ijA), 1, 25, 1, 0) - 1] +
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)c2_ix), 1, 25, 1, 0) - 1] * c2_temp;
          c2_e_a = c2_ix + 1;
          c2_ix = c2_e_a;
        }
      }

      c2_f_a = c2_jy + 5;
      c2_jy = c2_f_a;
      c2_g_a = c2_jA + 5;
      c2_jA = c2_g_a;
    }
  }
}

static void c2_k_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[25], real_T c2_b_B[80])
{
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_jBcol;
  int32_T c2_jAcol;
  int32_T c2_i317;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_kBcol;
  int32_T c2_i;
  int32_T c2_b_i;
  real_T c2_temp;
  int32_T c2_c_i;
  c2_b_below_threshold(chartInstance);
  c2_scalarEg(chartInstance);
  c2_eml_switch_helper(chartInstance);
  for (c2_j = 1; c2_j < 6; c2_j++) {
    c2_b_j = c2_j - 1;
    c2_jBcol = c2_b_j << 4;
    c2_jAcol = 5 * c2_b_j;
    c2_i317 = c2_b_j;
    c2_b = c2_i317;
    c2_b_b = c2_b;
    if (1 > c2_b_b) {
      c2_overflow = false;
    } else {
      c2_eml_switch_helper(chartInstance);
      c2_eml_switch_helper(chartInstance);
      c2_overflow = (c2_b_b > 2147483646);
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_k = 1; c2_k <= c2_i317; c2_k++) {
      c2_b_k = c2_k;
      c2_kBcol = (c2_b_k - 1) << 4;
      if (c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_b_k + c2_jAcol)), 1, 25, 1, 0) - 1] != 0.0) {
        c2_eml_switch_helper(chartInstance);
        for (c2_i = 1; c2_i < 17; c2_i++) {
          c2_b_i = c2_i;
          c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_b_i + c2_jBcol)), 1, 80, 1, 0) - 1] =
            c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)(c2_b_i + c2_jBcol)), 1, 80, 1, 0) - 1] -
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_b_k + c2_jAcol)), 1, 25, 1, 0) - 1] *
            c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)(c2_b_i + c2_kBcol)), 1, 80, 1, 0) - 1];
        }
      }
    }

    c2_temp = c2_rdivide(chartInstance, 1.0, c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
                          (int32_T)_SFD_INTEGER_CHECK("", (real_T)((c2_b_j +
      c2_jAcol) + 1)), 1, 25, 1, 0) - 1]);
    c2_eml_switch_helper(chartInstance);
    for (c2_c_i = 1; c2_c_i < 17; c2_c_i++) {
      c2_b_i = c2_c_i;
      c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_b_i + c2_jBcol)), 1, 80, 1, 0) - 1] = c2_temp *
        c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)(c2_b_i + c2_jBcol)), 1, 80, 1, 0) - 1];
    }
  }
}

static void c2_l_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[25], real_T c2_b_B[80])
{
  int32_T c2_j;
  int32_T c2_b_j;
  int32_T c2_jBcol;
  int32_T c2_jAcol;
  int32_T c2_i318;
  int32_T c2_a;
  int32_T c2_b_a;
  boolean_T c2_overflow;
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_kBcol;
  int32_T c2_i;
  int32_T c2_b_i;
  c2_b_below_threshold(chartInstance);
  c2_scalarEg(chartInstance);
  c2_eml_switch_helper(chartInstance);
  for (c2_j = 5; c2_j > 0; c2_j--) {
    c2_b_j = c2_j - 1;
    c2_jBcol = c2_b_j << 4;
    c2_jAcol = 5 * c2_b_j;
    c2_i318 = c2_b_j + 2;
    c2_a = c2_i318;
    c2_b_a = c2_a;
    if (c2_b_a > 5) {
      c2_overflow = false;
    } else {
      c2_eml_switch_helper(chartInstance);
      c2_eml_switch_helper(chartInstance);
      c2_overflow = false;
    }

    if (c2_overflow) {
      c2_check_forloop_overflow_error(chartInstance, c2_overflow);
    }

    for (c2_k = c2_i318; c2_k < 6; c2_k++) {
      c2_b_k = c2_k;
      c2_kBcol = (c2_b_k - 1) << 4;
      if (c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_b_k + c2_jAcol)), 1, 25, 1, 0) - 1] != 0.0) {
        c2_eml_switch_helper(chartInstance);
        for (c2_i = 1; c2_i < 17; c2_i++) {
          c2_b_i = c2_i;
          c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_b_i + c2_jBcol)), 1, 80, 1, 0) - 1] =
            c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)(c2_b_i + c2_jBcol)), 1, 80, 1, 0) - 1] -
            c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
            (real_T)(c2_b_k + c2_jAcol)), 1, 25, 1, 0) - 1] *
            c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK(
            "", (real_T)(c2_b_i + c2_kBcol)), 1, 80, 1, 0) - 1];
        }
      }
    }
  }
}

static void c2_c_eml_xgemm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[80], real_T c2_b_B[80], real_T c2_C[256])
{
  real_T c2_alpha1;
  real_T c2_beta1;
  char_T c2_TRANSB;
  char_T c2_TRANSA;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_k_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  ptrdiff_t c2_ldc_t;
  double * c2_alpha1_t;
  double * c2_Aia0_t;
  double * c2_Bib0_t;
  double * c2_beta1_t;
  double * c2_Cic0_t;
  c2_threshold(chartInstance);
  c2_alpha1 = 1.0;
  c2_beta1 = 0.0;
  c2_TRANSB = 'N';
  c2_TRANSA = 'N';
  c2_m_t = (ptrdiff_t)(16);
  c2_n_t = (ptrdiff_t)(16);
  c2_k_t = (ptrdiff_t)(5);
  c2_lda_t = (ptrdiff_t)(16);
  c2_ldb_t = (ptrdiff_t)(5);
  c2_ldc_t = (ptrdiff_t)(16);
  c2_alpha1_t = (double *)(&c2_alpha1);
  c2_Aia0_t = (double *)(&c2_A[0]);
  c2_Bib0_t = (double *)(&c2_b_B[0]);
  c2_beta1_t = (double *)(&c2_beta1);
  c2_Cic0_t = (double *)(&c2_C[0]);
  dgemm(&c2_TRANSA, &c2_TRANSB, &c2_m_t, &c2_n_t, &c2_k_t, c2_alpha1_t,
        c2_Aia0_t, &c2_lda_t, c2_Bib0_t, &c2_ldb_t, c2_beta1_t, c2_Cic0_t,
        &c2_ldc_t);
}

static void c2_m_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[48])
{
  real_T c2_alpha1;
  char_T c2_DIAGA;
  char_T c2_TRANSA;
  char_T c2_UPLO;
  char_T c2_SIDE;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  double * c2_Aia0_t;
  double * c2_Bib0_t;
  double * c2_alpha1_t;
  c2_c_below_threshold(chartInstance);
  c2_alpha1 = 1.0;
  c2_DIAGA = 'N';
  c2_TRANSA = 'N';
  c2_UPLO = 'U';
  c2_SIDE = 'R';
  c2_m_t = (ptrdiff_t)(3);
  c2_n_t = (ptrdiff_t)(16);
  c2_lda_t = (ptrdiff_t)(16);
  c2_ldb_t = (ptrdiff_t)(3);
  c2_Aia0_t = (double *)(&c2_A[0]);
  c2_Bib0_t = (double *)(&c2_b_B[0]);
  c2_alpha1_t = (double *)(&c2_alpha1);
  dtrsm(&c2_SIDE, &c2_UPLO, &c2_TRANSA, &c2_DIAGA, &c2_m_t, &c2_n_t, c2_alpha1_t,
        c2_Aia0_t, &c2_lda_t, c2_Bib0_t, &c2_ldb_t);
}

static void c2_n_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[48])
{
  real_T c2_alpha1;
  char_T c2_DIAGA;
  char_T c2_TRANSA;
  char_T c2_UPLO;
  char_T c2_SIDE;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  double * c2_Aia0_t;
  double * c2_Bib0_t;
  double * c2_alpha1_t;
  c2_c_below_threshold(chartInstance);
  c2_alpha1 = 1.0;
  c2_DIAGA = 'U';
  c2_TRANSA = 'N';
  c2_UPLO = 'L';
  c2_SIDE = 'R';
  c2_m_t = (ptrdiff_t)(3);
  c2_n_t = (ptrdiff_t)(16);
  c2_lda_t = (ptrdiff_t)(16);
  c2_ldb_t = (ptrdiff_t)(3);
  c2_Aia0_t = (double *)(&c2_A[0]);
  c2_Bib0_t = (double *)(&c2_b_B[0]);
  c2_alpha1_t = (double *)(&c2_alpha1);
  dtrsm(&c2_SIDE, &c2_UPLO, &c2_TRANSA, &c2_DIAGA, &c2_m_t, &c2_n_t, c2_alpha1_t,
        c2_Aia0_t, &c2_lda_t, c2_Bib0_t, &c2_ldb_t);
}

static void c2_d_eml_xgemm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[48], real_T c2_b_B[48], real_T c2_C[256])
{
  real_T c2_alpha1;
  real_T c2_beta1;
  char_T c2_TRANSB;
  char_T c2_TRANSA;
  ptrdiff_t c2_m_t;
  ptrdiff_t c2_n_t;
  ptrdiff_t c2_k_t;
  ptrdiff_t c2_lda_t;
  ptrdiff_t c2_ldb_t;
  ptrdiff_t c2_ldc_t;
  double * c2_alpha1_t;
  double * c2_Aia0_t;
  double * c2_Bib0_t;
  double * c2_beta1_t;
  double * c2_Cic0_t;
  c2_threshold(chartInstance);
  c2_alpha1 = 1.0;
  c2_beta1 = 0.0;
  c2_TRANSB = 'N';
  c2_TRANSA = 'N';
  c2_m_t = (ptrdiff_t)(16);
  c2_n_t = (ptrdiff_t)(16);
  c2_k_t = (ptrdiff_t)(3);
  c2_lda_t = (ptrdiff_t)(16);
  c2_ldb_t = (ptrdiff_t)(3);
  c2_ldc_t = (ptrdiff_t)(16);
  c2_alpha1_t = (double *)(&c2_alpha1);
  c2_Aia0_t = (double *)(&c2_A[0]);
  c2_Bib0_t = (double *)(&c2_b_B[0]);
  c2_beta1_t = (double *)(&c2_beta1);
  c2_Cic0_t = (double *)(&c2_C[0]);
  dgemm(&c2_TRANSA, &c2_TRANSB, &c2_m_t, &c2_n_t, &c2_k_t, c2_alpha1_t,
        c2_Aia0_t, &c2_lda_t, c2_Bib0_t, &c2_ldb_t, c2_beta1_t, c2_Cic0_t,
        &c2_ldc_t);
}

static void c2_o_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[16])
{
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_kAcol;
  int32_T c2_i319;
  int32_T c2_a;
  int32_T c2_b_a;
  boolean_T c2_overflow;
  int32_T c2_i;
  int32_T c2_b_i;
  c2_d_below_threshold(chartInstance);
  c2_b_scalarEg(chartInstance);
  c2_eml_switch_helper(chartInstance);
  for (c2_k = 1; c2_k < 17; c2_k++) {
    c2_b_k = c2_k;
    c2_kAcol = (c2_b_k - 1) << 4;
    if (c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_k), 1, 16, 1, 0) - 1] != 0.0) {
      c2_i319 = c2_b_k + 1;
      c2_a = c2_i319;
      c2_b_a = c2_a;
      if (c2_b_a > 16) {
        c2_overflow = false;
      } else {
        c2_eml_switch_helper(chartInstance);
        c2_eml_switch_helper(chartInstance);
        c2_overflow = false;
      }

      if (c2_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_overflow);
      }

      for (c2_i = c2_i319; c2_i < 17; c2_i++) {
        c2_b_i = c2_i;
        c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_i), 1, 16, 1, 0) - 1] =
          c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_i), 1, 16, 1, 0) - 1] -
          c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_k), 1, 16, 1, 0) - 1] * c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c2_b_i + c2_kAcol)), 1,
          256, 1, 0) - 1];
      }
    }
  }
}

static void c2_p_eml_xtrsm(SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  real_T c2_A[256], real_T c2_b_B[16])
{
  int32_T c2_k;
  int32_T c2_b_k;
  int32_T c2_kAcol;
  int32_T c2_i320;
  int32_T c2_b;
  int32_T c2_b_b;
  boolean_T c2_overflow;
  int32_T c2_i;
  int32_T c2_b_i;
  c2_d_below_threshold(chartInstance);
  c2_b_scalarEg(chartInstance);
  c2_eml_switch_helper(chartInstance);
  for (c2_k = 16; c2_k > 0; c2_k--) {
    c2_b_k = c2_k;
    c2_kAcol = (c2_b_k - 1) << 4;
    if (c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_k), 1, 16, 1, 0) - 1] != 0.0) {
      c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_k), 1, 16, 1, 0) - 1] = c2_rdivide(chartInstance,
        c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
        (real_T)c2_b_k), 1, 16, 1, 0) - 1], c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK("",
        (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c2_b_k + c2_kAcol)), 1, 256, 1,
        0) - 1]);
      c2_i320 = c2_b_k - 1;
      c2_b = c2_i320;
      c2_b_b = c2_b;
      if (1 > c2_b_b) {
        c2_overflow = false;
      } else {
        c2_eml_switch_helper(chartInstance);
        c2_eml_switch_helper(chartInstance);
        c2_overflow = (c2_b_b > 2147483646);
      }

      if (c2_overflow) {
        c2_check_forloop_overflow_error(chartInstance, c2_overflow);
      }

      for (c2_i = 1; c2_i <= c2_i320; c2_i++) {
        c2_b_i = c2_i;
        c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_i), 1, 16, 1, 0) - 1] =
          c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_i), 1, 16, 1, 0) - 1] -
          c2_b_B[_SFD_EML_ARRAY_BOUNDS_CHECK("", (int32_T)_SFD_INTEGER_CHECK("",
          (real_T)c2_b_k), 1, 16, 1, 0) - 1] * c2_A[_SFD_EML_ARRAY_BOUNDS_CHECK(
          "", (int32_T)_SFD_INTEGER_CHECK("", (real_T)(c2_b_i + c2_kAcol)), 1,
          256, 1, 0) - 1];
      }
    }
  }
}

static void init_dsm_address_info(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc2_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c2_x = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c2_u = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_D = (real_T (*)[256])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c2_Cdq = (real_T (*)[16])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c2_G = (real_T (*)[16])ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c2_B = (real_T (*)[96])ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c2_FGround = (real_T (*)[16])ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c2_Fstiction = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c2_x_dot = (real_T (*)[32])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c2_ExternalHipForce = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c2_Ttime = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
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

void sf_c2_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1855427982U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1750551997U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3941609760U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(714251065U);
}

mxArray* sf_c2_DDA2D_OSU3Dv2_get_post_codegen_info(void);
mxArray *sf_c2_DDA2D_OSU3Dv2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("vEIWRLhIfBRUyNCl5zNtu");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
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
      pr[0] = (double)(16);
      pr[1] = (double)(16);
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
      pr[0] = (double)(16);
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
      pr[0] = (double)(16);
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
      pr[0] = (double)(16);
      pr[1] = (double)(6);
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
      pr[0] = (double)(16);
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
      pr[0] = (double)(6);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,8,"type",mxType);
    }

    mxSetField(mxData,8,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,9,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,9,"type",mxType);
    }

    mxSetField(mxData,9,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c2_DDA2D_OSU3Dv2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c2_DDA2D_OSU3Dv2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c2_DDA2D_OSU3Dv2_jit_fallback_info(void)
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

mxArray *sf_c2_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c2_DDA2D_OSU3Dv2_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c2_DDA2D_OSU3Dv2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"x_dot\",},{M[8],M[0],T\"is_active_c2_DDA2D_OSU3Dv2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c2_DDA2D_OSU3Dv2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DDA2D_OSU3Dv2MachineNumber_,
           2,
           1,
           1,
           0,
           16,
           0,
           0,
           0,
           0,
           3,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"x");
          _SFD_SET_DATA_PROPS(1,1,1,0,"u");
          _SFD_SET_DATA_PROPS(2,1,1,0,"D");
          _SFD_SET_DATA_PROPS(3,1,1,0,"Cdq");
          _SFD_SET_DATA_PROPS(4,1,1,0,"G");
          _SFD_SET_DATA_PROPS(5,1,1,0,"B");
          _SFD_SET_DATA_PROPS(6,1,1,0,"FGround");
          _SFD_SET_DATA_PROPS(7,1,1,0,"Fstiction");
          _SFD_SET_DATA_PROPS(8,2,0,1,"x_dot");
          _SFD_SET_DATA_PROPS(9,10,0,0,"spring_k");
          _SFD_SET_DATA_PROPS(10,10,0,0,"spring_zeta");
          _SFD_SET_DATA_PROPS(11,10,0,0,"ProjectTo2D");
          _SFD_SET_DATA_PROPS(12,1,1,0,"ExternalHipForce");
          _SFD_SET_DATA_PROPS(13,10,0,0,"BoomParams");
          _SFD_SET_DATA_PROPS(14,10,0,0,"pBInitial");
          _SFD_SET_DATA_PROPS(15,1,1,0,"Ttime");
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
        _SFD_CV_INIT_EML(0,1,1,4,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2291);
        _SFD_CV_INIT_EML_IF(0,1,0,591,595,-1,1210);
        _SFD_CV_INIT_EML_IF(0,1,1,808,812,-1,1206);
        _SFD_CV_INIT_EML_IF(0,1,2,1226,1243,1736,1757);
        _SFD_CV_INIT_EML_IF(0,1,3,1736,1757,-1,1757);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,1229,1243,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,1743,1757,-1,0);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"ATRIAS3D_Spring_Constants",0,-1,635);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"JacobBoomHip_FixParams",0,-1,3783);
        _SFD_CV_INIT_SCRIPT(2,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"BoomPositionHip_FixParams",0,-1,869);

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 16;
          dimVector[1]= 16;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_g_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 16;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 16;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 16;
          dimVector[1]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_f_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 16;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_sf_marshallOut,(MexInFcnForType)
            c2_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)c2_c_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 1;
          _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c2_c_sf_marshallOut,(MexInFcnForType)
            c2_b_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c2_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c2_x);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c2_u);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c2_D);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c2_Cdq);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c2_G);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c2_B);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c2_FGround);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c2_Fstiction);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c2_x_dot);
        _SFD_SET_DATA_VALUE_PTR(9U, &chartInstance->c2_spring_k);
        _SFD_SET_DATA_VALUE_PTR(10U, &chartInstance->c2_spring_zeta);
        _SFD_SET_DATA_VALUE_PTR(11U, &chartInstance->c2_ProjectTo2D);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c2_ExternalHipForce);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c2_BoomParams);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c2_pBInitial);
        _SFD_SET_DATA_VALUE_PTR(15U, chartInstance->c2_Ttime);
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
  return "xYxu92EniUSp1bUlgzckRF";
}

static void sf_opaque_initialize_c2_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc2_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c2_DDA2D_OSU3Dv2((SFc2_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
  initialize_c2_DDA2D_OSU3Dv2((SFc2_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c2_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  enable_c2_DDA2D_OSU3Dv2((SFc2_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c2_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  disable_c2_DDA2D_OSU3Dv2((SFc2_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c2_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  sf_gateway_c2_DDA2D_OSU3Dv2((SFc2_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c2_DDA2D_OSU3Dv2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c2_DDA2D_OSU3Dv2((SFc2_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c2_DDA2D_OSU3Dv2(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c2_DDA2D_OSU3Dv2((SFc2_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c2_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc2_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DDA2D_OSU3Dv2_optimization_info();
    }

    finalize_c2_DDA2D_OSU3Dv2((SFc2_DDA2D_OSU3Dv2InstanceStruct*)
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
  initSimStructsc2_DDA2D_OSU3Dv2((SFc2_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c2_DDA2D_OSU3Dv2(SimStruct *S)
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
    initialize_params_c2_DDA2D_OSU3Dv2((SFc2_DDA2D_OSU3Dv2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c2_DDA2D_OSU3Dv2(SimStruct *S)
{
  /* Actual parameters from chart:
     BoomParams ProjectTo2D pBInitial spring_k spring_zeta
   */
  const char_T *rtParamNames[] = { "BoomParams", "ProjectTo2D", "pBInitial",
    "spring_k", "spring_zeta" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for BoomParams*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for ProjectTo2D*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);

  /* registration for pBInitial*/
  ssRegDlgParamAsRunTimeParam(S, 2, 2, rtParamNames[2], SS_DOUBLE);

  /* registration for spring_k*/
  ssRegDlgParamAsRunTimeParam(S, 3, 3, rtParamNames[3], SS_DOUBLE);

  /* registration for spring_zeta*/
  ssRegDlgParamAsRunTimeParam(S, 4, 4, rtParamNames[4], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DDA2D_OSU3Dv2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,2);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,2,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,2,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,2);
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
      ssSetInputPortOptimOpts(S, 9, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,2,10);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,2,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 10; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,2);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1972915610U));
  ssSetChecksum1(S,(1568045618U));
  ssSetChecksum2(S,(1498912768U));
  ssSetChecksum3(S,(1079068374U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c2_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c2_DDA2D_OSU3Dv2(SimStruct *S)
{
  SFc2_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc2_DDA2D_OSU3Dv2InstanceStruct *)utMalloc(sizeof
    (SFc2_DDA2D_OSU3Dv2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc2_DDA2D_OSU3Dv2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c2_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c2_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c2_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c2_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c2_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c2_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c2_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c2_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c2_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlStart = mdlStart_c2_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c2_DDA2D_OSU3Dv2;
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

void c2_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c2_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c2_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c2_DDA2D_OSU3Dv2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c2_DDA2D_OSU3Dv2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
