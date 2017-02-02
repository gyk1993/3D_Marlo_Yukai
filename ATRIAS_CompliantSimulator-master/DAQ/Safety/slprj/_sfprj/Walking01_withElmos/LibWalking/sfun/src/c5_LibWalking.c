/* Include files */

#include <stddef.h>
#include "blas.h"
#include "LibWalking_sfun.h"
#include "c5_LibWalking.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "LibWalking_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c5_debug_family_names[29] = { "HAlpha", "H", "B",
  "condDecoup", "nargin", "nargout", "t", "q", "dq", "ControlState",
  "ControlParams", "D", "G", "pcm", "vcm", "sprev", "u", "y", "dy", "hd", "s",
  "s_unsaturated", "ds", "theta", "phi", "r", "hdbar", "u_star", "u_pd" };

static const char * c5_b_debug_family_names[14] = { "StanceKneeAngleBias",
  "SwingKneeAngleBias1", "SwingKneeAngleBias2", "SwingKneeAngleBias3",
  "TorsoBias", "QTweakVec", "QTweaks", "SwingKeeAngleBias", "GetTweaks",
  "nargin", "nargout", "ControlState", "ControlParams", "HAlpha" };

static const char * c5_c_debug_family_names[13] = { "c", "nargin", "nargout",
  "t", "q", "dq", "theta_limits", "s", "ds", "dsdq", "th", "dth", "delta_theta"
};

static const char * c5_d_debug_family_names[6] = { "nargin", "nargout", "x",
  "lo", "hi", "y" };

static const char * c5_e_debug_family_names[15] = { "n", "m", "ns", "M", "k",
  "x", "y", "i", "idx", "j", "nargin", "nargout", "alpha", "s", "value" };

static const char * c5_f_debug_family_names[15] = { "n", "m", "ns", "M", "k",
  "x", "y", "i", "idx", "j", "nargin", "nargout", "afra", "s", "value" };

static const char * c5_g_debug_family_names[15] = { "n", "m", "ns", "M", "k",
  "x", "y", "i", "idx", "j", "nargin", "nargout", "alpha", "s", "value" };

static const char * c5_h_debug_family_names[13] = { "n", "m", "M", "k", "x", "y",
  "i", "j", "nargin", "nargout", "afra", "s", "value" };

static const char * c5_i_debug_family_names[6] = { "value", "n", "m", "M",
  "nargin", "nargout" };

static const char * c5_j_debug_family_names[6] = { "value", "n", "m", "M",
  "nargin", "nargout" };

static const char * c5_k_debug_family_names[11] = { "a0", "a1", "a2", "a3", "a4",
  "nargin", "nargout", "poly_cor", "s", "s_corr_max", "value" };

static const char * c5_l_debug_family_names[10] = { "a1", "a2", "a3", "a4",
  "nargin", "nargout", "poly_cor", "s", "s_corr_max", "value" };

static const char * c5_m_debug_family_names[9] = { "a2", "a3", "a4", "nargin",
  "nargout", "poly_cor", "s", "s_corr_max", "value" };

static const char * c5_n_debug_family_names[6] = { "nargin", "nargout", "x",
  "lo", "hi", "y" };

static const char * c5_o_debug_family_names[55] = { "Output", "T0", "T1", "c",
  "h_alpha", "delta", "dqyTds", "s6", "h_alpha_high", "h_alpha_low", "smin",
  "smax", "qmod", "hd", "jacob_hd", "jacob2_hd", "dhd", "dphi", "phid",
  "jacob_phid", "jacob2_phid", "RSaturated", "jacob_hdbar", "jacob2_hdbar",
  "idxsat", "hd_min", "hd_max", "sat_correction", "h_alpha_corr", "s_corr_max",
  "nargin", "nargout", "t", "q", "dq", "ControlState", "ControlParams", "sprev",
  "s", "ds", "h0", "y", "dy", "jacob_h0", "jacob_h", "s_unsaturated", "theta",
  "dtheta", "delta_theta", "dsdq", "jacob_jacobhdqdq", "phi", "r", "dr", "hdbar"
};

static const char * c5_p_debug_family_names[13] = { "n", "m", "M", "k", "x", "y",
  "i", "j", "nargin", "nargout", "afra", "s", "value" };

static const char * c5_q_debug_family_names[50] = { "condDecoup", "h0",
  "jacob_h0", "jacob_h", "dtheta", "delta_theta", "dsdq", "jacob_jacobhdqdq",
  "dr", "T0", "TLegHip", "L2fh", "T", "jacob_h_D_inv", "epsilon", "kp", "kd",
  "pd", "Ttemp", "kp_2dof", "kd_2dof", "kpre_2dof", "q3_swing", "dq3_swing",
  "e_swing", "u3_swing", "H", "B", "nargin", "nargout", "t", "q", "dq", "D",
  "ControlState", "ControlParams", "sprev", "u", "y", "dy", "hd", "s",
  "s_unsaturated", "ds", "theta", "u_star", "u_pd", "phi", "r", "hdbar" };

/* Function Declarations */
static void initialize_c5_LibWalking(SFc5_LibWalkingInstanceStruct
  *chartInstance);
static void initialize_params_c5_LibWalking(SFc5_LibWalkingInstanceStruct
  *chartInstance);
static void enable_c5_LibWalking(SFc5_LibWalkingInstanceStruct *chartInstance);
static void disable_c5_LibWalking(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_update_debugger_state_c5_LibWalking(SFc5_LibWalkingInstanceStruct
  *chartInstance);
static const mxArray *get_sim_state_c5_LibWalking(SFc5_LibWalkingInstanceStruct *
  chartInstance);
static void set_sim_state_c5_LibWalking(SFc5_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c5_st);
static void finalize_c5_LibWalking(SFc5_LibWalkingInstanceStruct *chartInstance);
static void sf_gateway_c5_LibWalking(SFc5_LibWalkingInstanceStruct
  *chartInstance);
static void mdl_start_c5_LibWalking(SFc5_LibWalkingInstanceStruct *chartInstance);
static void initSimStructsc5_LibWalking(SFc5_LibWalkingInstanceStruct
  *chartInstance);
static void c5_applyGaitTweaks2(SFc5_LibWalkingInstanceStruct *chartInstance,
  c5_ControlStateBus c5_b_ControlState, c5_ControlParamsBus *c5_b_ControlParams,
  real_T c5_HAlpha[36]);
static void c5_ATRIAS3D_ZD_s6(SFc5_LibWalkingInstanceStruct *chartInstance,
  real_T c5_b_t, real_T c5_b_q[13], real_T c5_b_dq[13], real_T c5_theta_limits[2],
  real_T c5_c[15], real_T *c5_b_s, real_T *c5_b_ds, real_T c5_dsdq[13], real_T
  *c5_th, real_T *c5_dth, real_T *c5_delta_theta);
static void c5_ATRIAS3D_ZD_Control06(SFc5_LibWalkingInstanceStruct
  *chartInstance, real_T c5_b_t, real_T c5_b_q[13], real_T c5_b_dq[13], real_T
  c5_b_D, c5_ControlStateBus c5_b_ControlState, c5_ControlParamsBus
  *c5_b_ControlParams, real_T c5_b_sprev, real_T c5_b_u[6], real_T c5_b_y[6],
  real_T c5_b_dy[6], real_T c5_b_hd[6], real_T *c5_b_s, real_T
  *c5_b_s_unsaturated, real_T *c5_b_ds, real_T *c5_b_theta, real_T c5_b_u_star[6],
  real_T c5_b_u_pd[6], real_T *c5_b_phi, real_T *c5_b_r, real_T c5_b_hdbar[6]);
static void c5_ATRIAS3D_ZD_Output03(SFc5_LibWalkingInstanceStruct *chartInstance,
  real_T c5_b_t, real_T c5_b_q[13], real_T c5_b_dq[13], c5_ControlStateBus
  c5_b_ControlState, c5_ControlParamsBus *c5_b_ControlParams, real_T c5_b_sprev,
  real_T *c5_b_s, real_T *c5_b_ds, real_T c5_h0[6], real_T c5_b_y[6], real_T
  c5_b_dy[6], real_T c5_jacob_h0[78], real_T c5_jacob_h[78], real_T
  *c5_b_s_unsaturated, real_T *c5_b_theta, real_T *c5_dtheta, real_T
  *c5_delta_theta, real_T c5_dsdq[13], real_T c5_jacob_jacobhdqdq[6], real_T
  *c5_b_phi, real_T *c5_b_r, real_T *c5_dr, real_T c5_b_hdbar[6]);
static real_T c5_sat(SFc5_LibWalkingInstanceStruct *chartInstance, real_T c5_x,
                     real_T c5_lo, real_T c5_hi);
static void c5_bezierv(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_alpha[36], real_T c5_b_s, real_T c5_value[6]);
static void c5_beziervd(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_afra[36], real_T c5_b_s, real_T c5_value[6]);
static void c5_bezierva(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_alpha[36], real_T c5_b_s, real_T c5_value[6]);
static real_T c5_bezier(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_afra[20], real_T c5_b_s);
static void c5_bezierd(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_beziera(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_polyv(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
                     c5_poly_cor[30], real_T c5_b_s, real_T c5_s_corr_max,
                     real_T c5_value[6]);
static void c5_polyvd(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
                      c5_poly_cor[30], real_T c5_b_s, real_T c5_s_corr_max,
                      real_T c5_value[6]);
static void c5_polyva(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
                      c5_poly_cor[30], real_T c5_b_s, real_T c5_s_corr_max,
                      real_T c5_value[6]);
static void c5_b_sat(SFc5_LibWalkingInstanceStruct *chartInstance, real_T c5_x[6],
                     real_T c5_lo[6], real_T c5_hi[6], real_T c5_b_y[6]);
static void c5_b_bezier(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_afra[36], real_T c5_b_s, real_T c5_value[6]);
static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber);
static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData);
static void c5_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u_pd, const char_T *c5_identifier, real_T c5_b_y[6]);
static void c5_b_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[6]);
static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static real_T c5_c_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_r, const char_T *c5_identifier);
static real_T c5_d_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_e_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[36]);
static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_f_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  c5_ControlParamsBus *c5_b_y);
static void c5_g_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  c5_SupervisoryParamsBus *c5_b_y);
static void c5_h_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[2]);
static void c5_i_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[13]);
static void c5_j_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[5]);
static void c5_k_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[12]);
static void c5_l_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  c5_DiscreteParamsBus *c5_b_y);
static void c5_m_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  c5_OutputParamsBus *c5_b_y);
static void c5_n_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[78]);
static void c5_o_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[2]);
static void c5_p_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  c5_ThetaParamsBus *c5_b_y);
static void c5_q_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[13]);
static void c5_r_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[7]);
static void c5_s_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[30]);
static void c5_t_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, c5_PhiParamsBus *
  c5_b_y);
static void c5_u_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[20]);
static void c5_v_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  c5_FeedbackParamsBus *c5_b_y);
static c5_SaturationParamsBus c5_w_emlrt_marshallIn
  (SFc5_LibWalkingInstanceStruct *chartInstance, const mxArray *c5_b_u, const
   emlrtMsgIdentifier *c5_parentId);
static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static c5_ControlStateBus c5_x_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_y_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[4]);
static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_ab_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[78]);
static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_j_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_k_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_bb_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[15]);
static void c5_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_l_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_m_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_cb_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[6]);
static void c5_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_n_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_db_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[5]);
static void c5_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_o_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_p_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_q_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_r_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_eb_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, boolean_T
  c5_b_y[6]);
static void c5_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static boolean_T c5_fb_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_s_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_t_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_u_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static void c5_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static void c5_info_helper(const mxArray **c5_info);
static const mxArray *c5_emlrt_marshallOut(const char * c5_b_u);
static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_b_u);
static void c5_b_info_helper(const mxArray **c5_info);
static void c5_c_info_helper(const mxArray **c5_info);
static void c5_d_info_helper(const mxArray **c5_info);
static void c5_e_info_helper(const mxArray **c5_info);
static real_T c5_rdivide(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_x, real_T c5_b_y);
static void c5_repmat(SFc5_LibWalkingInstanceStruct *chartInstance, real_T c5_a
                      [13], real_T c5_b[78]);
static void c5_eml_switch_helper(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_eml_scalar_eg(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_threshold(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_b_threshold(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_b_eml_scalar_eg(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_eml_li_find(SFc5_LibWalkingInstanceStruct *chartInstance,
  boolean_T c5_x, int32_T c5_y_data[], int32_T c5_y_sizes[2]);
static void c5_b_repmat(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_a, real_T c5_b[2]);
static void c5_c_repmat(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_a, real_T c5_b[6]);
static void c5_eps(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_b_eml_li_find(SFc5_LibWalkingInstanceStruct *chartInstance,
  boolean_T c5_x[6], int32_T c5_y_data[], int32_T *c5_y_sizes);
static void c5_c_eml_scalar_eg(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_d_eml_scalar_eg(SFc5_LibWalkingInstanceStruct *chartInstance);
static real_T c5_mpower(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_a);
static boolean_T c5_any(SFc5_LibWalkingInstanceStruct *chartInstance, boolean_T
  c5_x);
static void c5_e_eml_scalar_eg(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_mldivide(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_A[36], real_T c5_B[6], real_T c5_Y[6]);
static void c5_realmin(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_eml_matlab_zgetrf(SFc5_LibWalkingInstanceStruct *chartInstance,
  real_T c5_A[36], real_T c5_b_A[36], int32_T c5_ipiv[6], int32_T *c5_info);
static int32_T c5_eml_ixamax(SFc5_LibWalkingInstanceStruct *chartInstance,
  int32_T c5_n, real_T c5_x[36], int32_T c5_ix0);
static void c5_check_forloop_overflow_error(SFc5_LibWalkingInstanceStruct
  *chartInstance, boolean_T c5_overflow);
static void c5_b_eml_switch_helper(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_eml_xgeru(SFc5_LibWalkingInstanceStruct *chartInstance, int32_T
  c5_m, int32_T c5_n, real_T c5_alpha1, int32_T c5_ix0, int32_T c5_iy0, real_T
  c5_A[36], int32_T c5_ia0, real_T c5_b_A[36]);
static void c5_eml_warning(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_eml_xtrsm(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_A[36], real_T c5_B[6], real_T c5_b_B[6]);
static void c5_below_threshold(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_c_eml_switch_helper(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_scalarEg(SFc5_LibWalkingInstanceStruct *chartInstance);
static void c5_b_eml_xtrsm(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_A[36], real_T c5_B[6], real_T c5_b_B[6]);
static void c5_power(SFc5_LibWalkingInstanceStruct *chartInstance, real_T c5_a[6],
                     real_T c5_b_y[6]);
static void c5_b_rdivide(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_x[6], real_T c5_b_y[6], real_T c5_z[6]);
static const mxArray *c5_v_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData);
static int32_T c5_gb_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData);
static const mxArray *c5_ControlState_bus_io(void *chartInstanceVoid, void
  *c5_pData);
static const mxArray *c5_ControlParams_bus_io(void *chartInstanceVoid, void
  *c5_pData);
static uint8_T c5_hb_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_LibWalking, const char_T
  *c5_identifier);
static uint8_T c5_ib_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId);
static void c5_b_eml_matlab_zgetrf(SFc5_LibWalkingInstanceStruct *chartInstance,
  real_T c5_A[36], int32_T c5_ipiv[6], int32_T *c5_info);
static void c5_b_eml_xgeru(SFc5_LibWalkingInstanceStruct *chartInstance, int32_T
  c5_m, int32_T c5_n, real_T c5_alpha1, int32_T c5_ix0, int32_T c5_iy0, real_T
  c5_A[36], int32_T c5_ia0);
static void c5_c_eml_xtrsm(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_A[36], real_T c5_B[6]);
static void c5_d_eml_xtrsm(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_A[36], real_T c5_B[6]);
static void init_dsm_address_info(SFc5_LibWalkingInstanceStruct *chartInstance);
static void init_simulink_io_address(SFc5_LibWalkingInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c5_LibWalking(SFc5_LibWalkingInstanceStruct
  *chartInstance)
{
  chartInstance->c5_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c5_is_active_c5_LibWalking = 0U;
}

static void initialize_params_c5_LibWalking(SFc5_LibWalkingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void enable_c5_LibWalking(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c5_LibWalking(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c5_update_debugger_state_c5_LibWalking(SFc5_LibWalkingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c5_LibWalking(SFc5_LibWalkingInstanceStruct *
  chartInstance)
{
  const mxArray *c5_st;
  const mxArray *c5_b_y = NULL;
  real_T c5_hoistedGlobal;
  real_T c5_b_u;
  const mxArray *c5_c_y = NULL;
  int32_T c5_i0;
  real_T c5_c_u[6];
  const mxArray *c5_d_y = NULL;
  int32_T c5_i1;
  real_T c5_d_u[6];
  const mxArray *c5_e_y = NULL;
  int32_T c5_i2;
  real_T c5_e_u[6];
  const mxArray *c5_f_y = NULL;
  real_T c5_b_hoistedGlobal;
  real_T c5_f_u;
  const mxArray *c5_g_y = NULL;
  real_T c5_c_hoistedGlobal;
  real_T c5_g_u;
  const mxArray *c5_h_y = NULL;
  real_T c5_d_hoistedGlobal;
  real_T c5_h_u;
  const mxArray *c5_i_y = NULL;
  real_T c5_e_hoistedGlobal;
  real_T c5_i_u;
  const mxArray *c5_j_y = NULL;
  real_T c5_f_hoistedGlobal;
  real_T c5_j_u;
  const mxArray *c5_k_y = NULL;
  int32_T c5_i3;
  real_T c5_k_u[6];
  const mxArray *c5_l_y = NULL;
  int32_T c5_i4;
  real_T c5_l_u[6];
  const mxArray *c5_m_y = NULL;
  int32_T c5_i5;
  real_T c5_m_u[6];
  const mxArray *c5_n_y = NULL;
  int32_T c5_i6;
  real_T c5_n_u[6];
  const mxArray *c5_o_y = NULL;
  uint8_T c5_g_hoistedGlobal;
  uint8_T c5_o_u;
  const mxArray *c5_p_y = NULL;
  c5_st = NULL;
  c5_st = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createcellmatrix(14, 1), false);
  c5_hoistedGlobal = *chartInstance->c5_ds;
  c5_b_u = c5_hoistedGlobal;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_b_y, 0, c5_c_y);
  for (c5_i0 = 0; c5_i0 < 6; c5_i0++) {
    c5_c_u[c5_i0] = (*chartInstance->c5_dy)[c5_i0];
  }

  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c5_b_y, 1, c5_d_y);
  for (c5_i1 = 0; c5_i1 < 6; c5_i1++) {
    c5_d_u[c5_i1] = (*chartInstance->c5_hd)[c5_i1];
  }

  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_d_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c5_b_y, 2, c5_e_y);
  for (c5_i2 = 0; c5_i2 < 6; c5_i2++) {
    c5_e_u[c5_i2] = (*chartInstance->c5_hdbar)[c5_i2];
  }

  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", c5_e_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c5_b_y, 3, c5_f_y);
  c5_b_hoistedGlobal = *chartInstance->c5_phi;
  c5_f_u = c5_b_hoistedGlobal;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_b_y, 4, c5_g_y);
  c5_c_hoistedGlobal = *chartInstance->c5_r;
  c5_g_u = c5_c_hoistedGlobal;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_b_y, 5, c5_h_y);
  c5_d_hoistedGlobal = *chartInstance->c5_s;
  c5_h_u = c5_d_hoistedGlobal;
  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", &c5_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_b_y, 6, c5_i_y);
  c5_e_hoistedGlobal = *chartInstance->c5_s_unsaturated;
  c5_i_u = c5_e_hoistedGlobal;
  c5_j_y = NULL;
  sf_mex_assign(&c5_j_y, sf_mex_create("y", &c5_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_b_y, 7, c5_j_y);
  c5_f_hoistedGlobal = *chartInstance->c5_theta;
  c5_j_u = c5_f_hoistedGlobal;
  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_create("y", &c5_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_b_y, 8, c5_k_y);
  for (c5_i3 = 0; c5_i3 < 6; c5_i3++) {
    c5_k_u[c5_i3] = (*chartInstance->c5_u)[c5_i3];
  }

  c5_l_y = NULL;
  sf_mex_assign(&c5_l_y, sf_mex_create("y", c5_k_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c5_b_y, 9, c5_l_y);
  for (c5_i4 = 0; c5_i4 < 6; c5_i4++) {
    c5_l_u[c5_i4] = (*chartInstance->c5_u_pd)[c5_i4];
  }

  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_l_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c5_b_y, 10, c5_m_y);
  for (c5_i5 = 0; c5_i5 < 6; c5_i5++) {
    c5_m_u[c5_i5] = (*chartInstance->c5_u_star)[c5_i5];
  }

  c5_n_y = NULL;
  sf_mex_assign(&c5_n_y, sf_mex_create("y", c5_m_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c5_b_y, 11, c5_n_y);
  for (c5_i6 = 0; c5_i6 < 6; c5_i6++) {
    c5_n_u[c5_i6] = (*chartInstance->c5_y)[c5_i6];
  }

  c5_o_y = NULL;
  sf_mex_assign(&c5_o_y, sf_mex_create("y", c5_n_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_setcell(c5_b_y, 12, c5_o_y);
  c5_g_hoistedGlobal = chartInstance->c5_is_active_c5_LibWalking;
  c5_o_u = c5_g_hoistedGlobal;
  c5_p_y = NULL;
  sf_mex_assign(&c5_p_y, sf_mex_create("y", &c5_o_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c5_b_y, 13, c5_p_y);
  sf_mex_assign(&c5_st, c5_b_y, false);
  return c5_st;
}

static void set_sim_state_c5_LibWalking(SFc5_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c5_st)
{
  const mxArray *c5_b_u;
  real_T c5_dv0[6];
  int32_T c5_i7;
  real_T c5_dv1[6];
  int32_T c5_i8;
  real_T c5_dv2[6];
  int32_T c5_i9;
  real_T c5_dv3[6];
  int32_T c5_i10;
  real_T c5_dv4[6];
  int32_T c5_i11;
  real_T c5_dv5[6];
  int32_T c5_i12;
  real_T c5_dv6[6];
  int32_T c5_i13;
  chartInstance->c5_doneDoubleBufferReInit = true;
  c5_b_u = sf_mex_dup(c5_st);
  *chartInstance->c5_ds = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_b_u, 0)), "ds");
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_b_u, 1)), "dy",
                      c5_dv0);
  for (c5_i7 = 0; c5_i7 < 6; c5_i7++) {
    (*chartInstance->c5_dy)[c5_i7] = c5_dv0[c5_i7];
  }

  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_b_u, 2)), "hd",
                      c5_dv1);
  for (c5_i8 = 0; c5_i8 < 6; c5_i8++) {
    (*chartInstance->c5_hd)[c5_i8] = c5_dv1[c5_i8];
  }

  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_b_u, 3)),
                      "hdbar", c5_dv2);
  for (c5_i9 = 0; c5_i9 < 6; c5_i9++) {
    (*chartInstance->c5_hdbar)[c5_i9] = c5_dv2[c5_i9];
  }

  *chartInstance->c5_phi = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_b_u, 4)), "phi");
  *chartInstance->c5_r = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_b_u, 5)), "r");
  *chartInstance->c5_s = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_b_u, 6)), "s");
  *chartInstance->c5_s_unsaturated = c5_c_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c5_b_u, 7)), "s_unsaturated");
  *chartInstance->c5_theta = c5_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c5_b_u, 8)), "theta");
  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_b_u, 9)), "u",
                      c5_dv3);
  for (c5_i10 = 0; c5_i10 < 6; c5_i10++) {
    (*chartInstance->c5_u)[c5_i10] = c5_dv3[c5_i10];
  }

  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_b_u, 10)),
                      "u_pd", c5_dv4);
  for (c5_i11 = 0; c5_i11 < 6; c5_i11++) {
    (*chartInstance->c5_u_pd)[c5_i11] = c5_dv4[c5_i11];
  }

  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_b_u, 11)),
                      "u_star", c5_dv5);
  for (c5_i12 = 0; c5_i12 < 6; c5_i12++) {
    (*chartInstance->c5_u_star)[c5_i12] = c5_dv5[c5_i12];
  }

  c5_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c5_b_u, 12)), "y",
                      c5_dv6);
  for (c5_i13 = 0; c5_i13 < 6; c5_i13++) {
    (*chartInstance->c5_y)[c5_i13] = c5_dv6[c5_i13];
  }

  chartInstance->c5_is_active_c5_LibWalking = c5_hb_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c5_b_u, 13)),
     "is_active_c5_LibWalking");
  sf_mex_destroy(&c5_b_u);
  c5_update_debugger_state_c5_LibWalking(chartInstance);
  sf_mex_destroy(&c5_st);
}

static void finalize_c5_LibWalking(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c5_LibWalking(SFc5_LibWalkingInstanceStruct
  *chartInstance)
{
  int32_T c5_i14;
  int32_T c5_i15;
  real_T c5_hoistedGlobal;
  real_T c5_b_hoistedGlobal;
  real_T c5_c_hoistedGlobal;
  real_T c5_d_hoistedGlobal;
  real_T c5_e_hoistedGlobal;
  real_T c5_f_hoistedGlobal;
  real_T c5_b_t;
  int32_T c5_i16;
  real_T c5_b_q[13];
  int32_T c5_i17;
  real_T c5_b_dq[13];
  c5_ControlStateBus c5_b_ControlState;
  c5_ControlParamsBus c5_b_ControlParams;
  int32_T c5_i18;
  int32_T c5_i19;
  int32_T c5_i20;
  int32_T c5_i21;
  int32_T c5_i22;
  int32_T c5_i23;
  int32_T c5_i24;
  int32_T c5_i25;
  int32_T c5_i26;
  int32_T c5_i27;
  int32_T c5_i28;
  int32_T c5_i29;
  int32_T c5_i30;
  int32_T c5_i31;
  int32_T c5_i32;
  int32_T c5_i33;
  int32_T c5_i34;
  int32_T c5_i35;
  int32_T c5_i36;
  int32_T c5_i37;
  int32_T c5_i38;
  int32_T c5_i39;
  int32_T c5_i40;
  int32_T c5_i41;
  int32_T c5_i42;
  int32_T c5_i43;
  int32_T c5_i44;
  int32_T c5_i45;
  int32_T c5_i46;
  int32_T c5_i47;
  int32_T c5_i48;
  int32_T c5_i49;
  int32_T c5_i50;
  int32_T c5_i51;
  int32_T c5_i52;
  int32_T c5_i53;
  int32_T c5_i54;
  int32_T c5_i55;
  int32_T c5_i56;
  int32_T c5_i57;
  int32_T c5_i58;
  int32_T c5_i59;
  int32_T c5_i60;
  int32_T c5_i61;
  int32_T c5_i62;
  int32_T c5_i63;
  int32_T c5_i64;
  real_T c5_b_D;
  real_T c5_b_G;
  real_T c5_b_pcm;
  real_T c5_b_vcm;
  real_T c5_b_sprev;
  uint32_T c5_debug_family_var_map[29];
  real_T c5_HAlpha[36];
  real_T c5_H[13];
  real_T c5_B[78];
  real_T c5_condDecoup;
  real_T c5_nargin = 10.0;
  real_T c5_nargout = 13.0;
  real_T c5_b_u[6];
  real_T c5_b_y[6];
  real_T c5_b_dy[6];
  real_T c5_b_hd[6];
  real_T c5_b_s;
  real_T c5_b_s_unsaturated;
  real_T c5_b_ds;
  real_T c5_b_theta;
  real_T c5_b_phi;
  real_T c5_b_r;
  real_T c5_b_hdbar[6];
  real_T c5_b_u_star[6];
  real_T c5_b_u_pd[6];
  int32_T c5_i65;
  int32_T c5_i66;
  int32_T c5_i67;
  int32_T c5_i68;
  int32_T c5_i69;
  int32_T c5_i70;
  int32_T c5_i71;
  int32_T c5_i72;
  int32_T c5_i73;
  int32_T c5_i74;
  int32_T c5_i75;
  int32_T c5_i76;
  int32_T c5_i77;
  c5_ControlParamsBus c5_c_ControlParams;
  real_T c5_dv7[36];
  int32_T c5_i78;
  int32_T c5_i79;
  int32_T c5_i80;
  int32_T c5_i81;
  static real_T c5_dv8[78] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 26.7, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 26.7 };

  int32_T c5_i82;
  real_T c5_c_q[13];
  int32_T c5_i83;
  real_T c5_c_dq[13];
  c5_ControlParamsBus c5_d_ControlParams;
  real_T c5_c_hdbar[6];
  real_T c5_c_r;
  real_T c5_c_phi;
  real_T c5_c_u_pd[6];
  real_T c5_c_u_star[6];
  real_T c5_c_theta;
  real_T c5_c_ds;
  real_T c5_c_s_unsaturated;
  real_T c5_c_s;
  real_T c5_c_hd[6];
  real_T c5_c_dy[6];
  real_T c5_c_y[6];
  real_T c5_c_u[6];
  int32_T c5_i84;
  int32_T c5_i85;
  int32_T c5_i86;
  int32_T c5_i87;
  int32_T c5_i88;
  int32_T c5_i89;
  int32_T c5_i90;
  int32_T c5_i91;
  int32_T c5_i92;
  int32_T c5_i93;
  int32_T c5_i94;
  int32_T c5_i95;
  int32_T c5_i96;
  int32_T c5_i97;
  int32_T c5_i98;
  int32_T c5_i99;
  int32_T c5_i100;
  int32_T c5_i101;
  int32_T c5_i102;
  int32_T c5_i103;
  int32_T c5_i104;
  boolean_T guard1 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_t, 0U);
  for (c5_i14 = 0; c5_i14 < 13; c5_i14++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_q)[c5_i14], 1U);
  }

  for (c5_i15 = 0; c5_i15 < 13; c5_i15++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_dq)[c5_i15], 2U);
  }

  chartInstance->c5_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
  c5_hoistedGlobal = *chartInstance->c5_t;
  c5_b_hoistedGlobal = *chartInstance->c5_D;
  c5_c_hoistedGlobal = *chartInstance->c5_G;
  c5_d_hoistedGlobal = *chartInstance->c5_pcm;
  c5_e_hoistedGlobal = *chartInstance->c5_vcm;
  c5_f_hoistedGlobal = *chartInstance->c5_sprev;
  c5_b_t = c5_hoistedGlobal;
  for (c5_i16 = 0; c5_i16 < 13; c5_i16++) {
    c5_b_q[c5_i16] = (*chartInstance->c5_q)[c5_i16];
  }

  for (c5_i17 = 0; c5_i17 < 13; c5_i17++) {
    c5_b_dq[c5_i17] = (*chartInstance->c5_dq)[c5_i17];
  }

  c5_b_ControlState.ControllerMode = *(real_T *)&((char_T *)
    chartInstance->c5_ControlState)[0];
  c5_b_ControlState.SupportState = *(real_T *)&((char_T *)
    chartInstance->c5_ControlState)[8];
  c5_b_ControlState.StanceLeg = *(real_T *)&((char_T *)
    chartInstance->c5_ControlState)[16];
  c5_b_ControlState.InDoubleSupport = *(real_T *)&((char_T *)
    chartInstance->c5_ControlState)[24];
  c5_b_ControlState.RollPhase = *(real_T *)&((char_T *)
    chartInstance->c5_ControlState)[32];
  c5_b_ControlState.StepCount = *(real_T *)&((char_T *)
    chartInstance->c5_ControlState)[40];
  c5_b_ControlState.Error = *(real_T *)&((char_T *)
    chartInstance->c5_ControlState)[48];
  c5_b_ControlParams.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [0];
  c5_b_ControlParams.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [8];
  c5_b_ControlParams.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [16];
  c5_b_ControlParams.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [24];
  c5_b_ControlParams.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)
    &((char_T *)(c5_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c5_ControlParams)[0])[32];
  c5_b_ControlParams.Supervisory.ImpactThresholdKASpringRel = *(real_T *)
    &((char_T *)(c5_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c5_ControlParams)[0])[40];
  c5_b_ControlParams.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [48];
  c5_b_ControlParams.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [56];
  c5_b_ControlParams.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [64];
  c5_b_ControlParams.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [72];
  c5_b_ControlParams.Supervisory.TransitionThresholdTorsoVel = *(real_T *)
    &((char_T *)(c5_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c5_ControlParams)[0])[80];
  for (c5_i18 = 0; c5_i18 < 2; c5_i18++) {
    c5_b_ControlParams.Supervisory.KAInjection[c5_i18] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
      [88])[c5_i18];
  }

  c5_b_ControlParams.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [104];
  c5_b_ControlParams.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [112];
  for (c5_i19 = 0; c5_i19 < 6; c5_i19++) {
    c5_b_ControlParams.Supervisory.VBLAParams[c5_i19] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
      [120])[c5_i19];
  }

  for (c5_i20 = 0; c5_i20 < 13; c5_i20++) {
    c5_b_ControlParams.Supervisory.BalanceParams[c5_i20] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
      [168])[c5_i20];
  }

  for (c5_i21 = 0; c5_i21 < 5; c5_i21++) {
    c5_b_ControlParams.Supervisory.GaitTweaks[c5_i21] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
      [272])[c5_i21];
  }

  c5_b_ControlParams.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [312];
  c5_b_ControlParams.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [320];
  c5_b_ControlParams.Supervisory.RunMode = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [328];
  c5_b_ControlParams.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [336];
  for (c5_i22 = 0; c5_i22 < 6; c5_i22++) {
    c5_b_ControlParams.Supervisory.ErrorZeroFactor[c5_i22] = ((real_T *)
      &((char_T *)(c5_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c5_ControlParams)[0])[344])[c5_i22];
  }

  for (c5_i23 = 0; c5_i23 < 6; c5_i23++) {
    c5_b_ControlParams.Supervisory.ErrorVelZeroFactor[c5_i23] = ((real_T *)
      &((char_T *)(c5_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c5_ControlParams)[0])[392])[c5_i23];
  }

  c5_b_ControlParams.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [440];
  c5_b_ControlParams.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [448];
  c5_b_ControlParams.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [456];
  c5_b_ControlParams.Supervisory.TPosing = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [464];
  c5_b_ControlParams.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [472];
  c5_b_ControlParams.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [480];
  c5_b_ControlParams.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [488];
  c5_b_ControlParams.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [496];
  c5_b_ControlParams.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [504];
  c5_b_ControlParams.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [512];
  c5_b_ControlParams.Supervisory.VelocityControlTorsoGain = *(real_T *)&((char_T
    *)(c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [520];
  c5_b_ControlParams.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [528];
  c5_b_ControlParams.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [536];
  c5_b_ControlParams.Supervisory.Theta0 = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [544];
  c5_b_ControlParams.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [552];
  c5_b_ControlParams.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [560];
  c5_b_ControlParams.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [568];
  c5_b_ControlParams.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [576];
  c5_b_ControlParams.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [584];
  c5_b_ControlParams.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [592];
  c5_b_ControlParams.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [600];
  for (c5_i24 = 0; c5_i24 < 6; c5_i24++) {
    c5_b_ControlParams.Supervisory.K1MidStanceUpdate[c5_i24] = ((real_T *)
      &((char_T *)(c5_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c5_ControlParams)[0])[608])[c5_i24];
  }

  for (c5_i25 = 0; c5_i25 < 6; c5_i25++) {
    c5_b_ControlParams.Supervisory.K2MidStanceUpdate[c5_i25] = ((real_T *)
      &((char_T *)(c5_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c5_ControlParams)[0])[656])[c5_i25];
  }

  c5_b_ControlParams.Supervisory.EnableVelocityBasedUpdate = *(real_T *)
    &((char_T *)(c5_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c5_ControlParams)[0])[704];
  for (c5_i26 = 0; c5_i26 < 6; c5_i26++) {
    c5_b_ControlParams.Supervisory.VelocityBasedUpdateK1[c5_i26] = ((real_T *)
      &((char_T *)(c5_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c5_ControlParams)[0])[712])[c5_i26];
  }

  for (c5_i27 = 0; c5_i27 < 6; c5_i27++) {
    c5_b_ControlParams.Supervisory.VelocityBasedUpdateK2[c5_i27] = ((real_T *)
      &((char_T *)(c5_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c5_ControlParams)[0])[760])[c5_i27];
  }

  c5_b_ControlParams.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)
    &((char_T *)(c5_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c5_ControlParams)[0])[808];
  c5_i28 = 0;
  for (c5_i29 = 0; c5_i29 < 2; c5_i29++) {
    for (c5_i30 = 0; c5_i30 < 6; c5_i30++) {
      c5_b_ControlParams.Supervisory.VelocityBasedUpdateLimits[c5_i30 + c5_i28] =
        ((real_T *)&((char_T *)(c5_SupervisoryParamsBus *)&((char_T *)
           chartInstance->c5_ControlParams)[0])[816])[c5_i30 + c5_i28];
    }

    c5_i28 += 6;
  }

  c5_b_ControlParams.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[0])
    [912];
  c5_b_ControlParams.Discrete.TLastUpdate = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[920])[0];
  c5_b_ControlParams.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[920])[8];
  c5_b_ControlParams.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[920])
    [16];
  c5_b_ControlParams.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[920])
    [24];
  c5_b_ControlParams.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[920])
    [32];
  c5_b_ControlParams.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[920])
    [40];
  c5_b_ControlParams.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[920])
    [48];
  c5_b_ControlParams.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[920])
    [56];
  c5_b_ControlParams.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[920])
    [64];
  c5_b_ControlParams.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[920])
    [72];
  c5_b_ControlParams.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[920])
    [80];
  c5_i31 = 0;
  for (c5_i32 = 0; c5_i32 < 13; c5_i32++) {
    for (c5_i33 = 0; c5_i33 < 6; c5_i33++) {
      c5_b_ControlParams.Output.H0[c5_i33 + c5_i31] = ((real_T *)&((char_T *)
        (c5_OutputParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[1008])
        [0])[c5_i33 + c5_i31];
    }

    c5_i31 += 6;
  }

  c5_i34 = 0;
  for (c5_i35 = 0; c5_i35 < 6; c5_i35++) {
    for (c5_i36 = 0; c5_i36 < 6; c5_i36++) {
      c5_b_ControlParams.Output.HAlpha[c5_i36 + c5_i34] = ((real_T *)&((char_T *)
        (c5_OutputParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[1008])
        [624])[c5_i36 + c5_i34];
    }

    c5_i34 += 6;
  }

  for (c5_i37 = 0; c5_i37 < 2; c5_i37++) {
    c5_b_ControlParams.Output.ThetaLimits[c5_i37] = ((real_T *)&((char_T *)
      (c5_OutputParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[1008])
      [912])[c5_i37];
  }

  c5_b_ControlParams.Output.Theta.c0 = *(real_T *)&((char_T *)(c5_ThetaParamsBus
    *)&((char_T *)(c5_OutputParamsBus *)&((char_T *)
    chartInstance->c5_ControlParams)[1008])[928])[0];
  c5_b_ControlParams.Output.Theta.ct = *(real_T *)&((char_T *)(c5_ThetaParamsBus
    *)&((char_T *)(c5_OutputParamsBus *)&((char_T *)
    chartInstance->c5_ControlParams)[1008])[928])[8];
  for (c5_i38 = 0; c5_i38 < 13; c5_i38++) {
    c5_b_ControlParams.Output.Theta.cq[c5_i38] = ((real_T *)&((char_T *)
      (c5_ThetaParamsBus *)&((char_T *)(c5_OutputParamsBus *)&((char_T *)
      chartInstance->c5_ControlParams)[1008])[928])[16])[c5_i38];
  }

  c5_b_ControlParams.Output.Theta.t0 = *(real_T *)&((char_T *)(c5_ThetaParamsBus
    *)&((char_T *)(c5_OutputParamsBus *)&((char_T *)
    chartInstance->c5_ControlParams)[1008])[928])[120];
  for (c5_i39 = 0; c5_i39 < 7; c5_i39++) {
    c5_b_ControlParams.Output.Theta.cz[c5_i39] = ((real_T *)&((char_T *)
      (c5_ThetaParamsBus *)&((char_T *)(c5_OutputParamsBus *)&((char_T *)
      chartInstance->c5_ControlParams)[1008])[928])[128])[c5_i39];
  }

  c5_b_ControlParams.Output.SaturateS = *(real_T *)&((char_T *)
    (c5_OutputParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[1008])
    [1112];
  for (c5_i40 = 0; c5_i40 < 2; c5_i40++) {
    c5_b_ControlParams.Output.SLimits[c5_i40] = ((real_T *)&((char_T *)
      (c5_OutputParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[1008])
      [1120])[c5_i40];
  }

  c5_b_ControlParams.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c5_OutputParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[1008])
    [1136];
  c5_b_ControlParams.Output.UseCorrection = *(real_T *)&((char_T *)
    (c5_OutputParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[1008])
    [1144];
  c5_b_ControlParams.Output.SMaxCorrection = *(real_T *)&((char_T *)
    (c5_OutputParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[1008])
    [1152];
  c5_i41 = 0;
  for (c5_i42 = 0; c5_i42 < 5; c5_i42++) {
    for (c5_i43 = 0; c5_i43 < 6; c5_i43++) {
      c5_b_ControlParams.Output.HAlphaCorrection[c5_i43 + c5_i41] = ((real_T *)
        &((char_T *)(c5_OutputParamsBus *)&((char_T *)
        chartInstance->c5_ControlParams)[1008])[1160])[c5_i43 + c5_i41];
    }

    c5_i41 += 6;
  }

  c5_b_ControlParams.Output.Phi.c0 = *(real_T *)&((char_T *)(c5_PhiParamsBus *)
    &((char_T *)(c5_OutputParamsBus *)&((char_T *)
    chartInstance->c5_ControlParams)[1008])[1400])[0];
  for (c5_i44 = 0; c5_i44 < 13; c5_i44++) {
    c5_b_ControlParams.Output.Phi.cq[c5_i44] = ((real_T *)&((char_T *)
      (c5_PhiParamsBus *)&((char_T *)(c5_OutputParamsBus *)&((char_T *)
      chartInstance->c5_ControlParams)[1008])[1400])[8])[c5_i44];
  }

  for (c5_i45 = 0; c5_i45 < 20; c5_i45++) {
    c5_b_ControlParams.Output.PhiAlpha[c5_i45] = ((real_T *)&((char_T *)
      (c5_OutputParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[1008])
      [1512])[c5_i45];
  }

  c5_b_ControlParams.Output.SaturateR = *(real_T *)&((char_T *)
    (c5_OutputParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[1008])
    [1672];
  for (c5_i46 = 0; c5_i46 < 2; c5_i46++) {
    c5_b_ControlParams.Output.RLimits[c5_i46] = ((real_T *)&((char_T *)
      (c5_OutputParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[1008])
      [1680])[c5_i46];
  }

  c5_i47 = 0;
  for (c5_i48 = 0; c5_i48 < 5; c5_i48++) {
    for (c5_i49 = 0; c5_i49 < 6; c5_i49++) {
      c5_b_ControlParams.Output.HBarAlpha[c5_i49 + c5_i47] = ((real_T *)
        &((char_T *)(c5_OutputParamsBus *)&((char_T *)
        chartInstance->c5_ControlParams)[1008])[1696])[c5_i49 + c5_i47];
    }

    c5_i47 += 6;
  }

  c5_i50 = 0;
  for (c5_i51 = 0; c5_i51 < 2; c5_i51++) {
    for (c5_i52 = 0; c5_i52 < 6; c5_i52++) {
      c5_b_ControlParams.Output.HBarLimits[c5_i52 + c5_i50] = ((real_T *)
        &((char_T *)(c5_OutputParamsBus *)&((char_T *)
        chartInstance->c5_ControlParams)[1008])[1936])[c5_i52 + c5_i50];
    }

    c5_i50 += 6;
  }

  c5_i53 = 0;
  for (c5_i54 = 0; c5_i54 < 6; c5_i54++) {
    for (c5_i55 = 0; c5_i55 < 6; c5_i55++) {
      c5_b_ControlParams.Output.HAlphaStar[c5_i55 + c5_i53] = ((real_T *)
        &((char_T *)(c5_OutputParamsBus *)&((char_T *)
        chartInstance->c5_ControlParams)[1008])[2032])[c5_i55 + c5_i53];
    }

    c5_i53 += 6;
  }

  c5_b_ControlParams.Output.YawLimit = *(real_T *)&((char_T *)
    (c5_OutputParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[1008])
    [2320];
  for (c5_i56 = 0; c5_i56 < 6; c5_i56++) {
    c5_b_ControlParams.Feedback.kp[c5_i56] = ((real_T *)&((char_T *)
      (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
      [0])[c5_i56];
  }

  for (c5_i57 = 0; c5_i57 < 6; c5_i57++) {
    c5_b_ControlParams.Feedback.kd[c5_i57] = ((real_T *)&((char_T *)
      (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
      [48])[c5_i57];
  }

  for (c5_i58 = 0; c5_i58 < 2; c5_i58++) {
    c5_b_ControlParams.Feedback.epsilon[c5_i58] = ((real_T *)&((char_T *)
      (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
      [96])[c5_i58];
  }

  for (c5_i59 = 0; c5_i59 < 2; c5_i59++) {
    c5_b_ControlParams.Feedback.kff_grav[c5_i59] = ((real_T *)&((char_T *)
      (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
      [112])[c5_i59];
  }

  c5_b_ControlParams.Feedback.delta_grav = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [128];
  for (c5_i60 = 0; c5_i60 < 2; c5_i60++) {
    c5_b_ControlParams.Feedback.kff_decoup[c5_i60] = ((real_T *)&((char_T *)
      (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
      [136])[c5_i60];
  }

  for (c5_i61 = 0; c5_i61 < 2; c5_i61++) {
    c5_b_ControlParams.Feedback.kd_torso[c5_i61] = ((real_T *)&((char_T *)
      (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
      [152])[c5_i61];
  }

  c5_b_ControlParams.Feedback.kp_2dof = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [168];
  c5_b_ControlParams.Feedback.kd_2dof = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [176];
  c5_b_ControlParams.Feedback.kpre_2dof = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [184];
  c5_b_ControlParams.Feedback.kp_lat = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [192];
  c5_b_ControlParams.Feedback.kd_lat = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [200];
  c5_b_ControlParams.Feedback.q3d_min_lat = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [208];
  c5_b_ControlParams.Feedback.q3d_max_lat = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [216];
  c5_b_ControlParams.Feedback.w_torso_lat = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [224];
  for (c5_i62 = 0; c5_i62 < 6; c5_i62++) {
    c5_b_ControlParams.Feedback.u_ff[c5_i62] = ((real_T *)&((char_T *)
      (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
      [232])[c5_i62];
  }

  c5_b_ControlParams.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [280];
  c5_b_ControlParams.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [288];
  c5_b_ControlParams.Feedback.Use2DOF = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [296];
  c5_b_ControlParams.Feedback.UseDSGravComp = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [304];
  c5_b_ControlParams.Feedback.lat_bias = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [312];
  c5_b_ControlParams.Feedback.lat_bias2 = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [320];
  c5_b_ControlParams.Feedback.linkFeedback = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [328];
  c5_b_ControlParams.Feedback.RIO = *(real_T *)&((char_T *)(c5_FeedbackParamsBus
    *)&((char_T *)chartInstance->c5_ControlParams)[3336])[336];
  c5_b_ControlParams.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [344];
  for (c5_i63 = 0; c5_i63 < 6; c5_i63++) {
    c5_b_ControlParams.Feedback.FeedforwardGain[c5_i63] = ((real_T *)&((char_T *)
      (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
      [352])[c5_i63];
  }

  c5_b_ControlParams.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3336])
    [400];
  c5_b_ControlParams.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c5_SaturationParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3744])
    [0];
  for (c5_i64 = 0; c5_i64 < 2; c5_i64++) {
    c5_b_ControlParams.Saturation.QPWeight[c5_i64] = ((real_T *)&((char_T *)
      (c5_SaturationParamsBus *)&((char_T *)chartInstance->c5_ControlParams)
      [3744])[8])[c5_i64];
  }

  c5_b_ControlParams.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c5_SaturationParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3744])
    [24];
  c5_b_ControlParams.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c5_SaturationParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3744])
    [32];
  c5_b_ControlParams.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c5_SaturationParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3744])
    [40];
  c5_b_ControlParams.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c5_SaturationParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3744])
    [48];
  c5_b_ControlParams.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c5_SaturationParamsBus *)&((char_T *)chartInstance->c5_ControlParams)[3744])
    [56];
  c5_b_D = c5_b_hoistedGlobal;
  c5_b_G = c5_c_hoistedGlobal;
  c5_b_pcm = c5_d_hoistedGlobal;
  c5_b_vcm = c5_e_hoistedGlobal;
  c5_b_sprev = c5_f_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 29U, 29U, c5_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_HAlpha, 0U, c5_g_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_H, 1U, c5_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_B, 2U, c5_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_condDecoup, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 4U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 5U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_t, 6U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_q, 7U, c5_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_b_dq, 8U, c5_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_ControlState, 9U, c5_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_ControlParams, 10U, c5_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_D, 11U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_G, 12U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_pcm, 13U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_vcm, 14U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_b_sprev, 15U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_u, 16U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_y, 17U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_dy, 18U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_hd, 19U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_s, 20U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_s_unsaturated, 21U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_ds, 22U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_theta, 23U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_phi, 24U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_r, 25U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_hdbar, 26U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_u_star, 27U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_u_pd, 28U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 7);
  for (c5_i65 = 0; c5_i65 < 36; c5_i65++) {
    c5_HAlpha[c5_i65] = c5_b_ControlParams.Output.HAlpha[c5_i65];
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 9);
  guard1 = false;
  switch ((int32_T)_SFD_INTEGER_CHECK("ControlState.ControllerMode",
           c5_b_ControlState.ControllerMode)) {
   case 0:
    CV_EML_SWITCH(0, 1, 0, 1);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 12);
    for (c5_i66 = 0; c5_i66 < 6; c5_i66++) {
      c5_b_u[c5_i66] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 13);
    for (c5_i67 = 0; c5_i67 < 6; c5_i67++) {
      c5_b_y[c5_i67] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 14);
    for (c5_i68 = 0; c5_i68 < 6; c5_i68++) {
      c5_b_dy[c5_i68] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 15);
    for (c5_i69 = 0; c5_i69 < 6; c5_i69++) {
      c5_b_hd[c5_i69] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 16);
    c5_b_s = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 17);
    c5_b_s_unsaturated = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 18);
    c5_b_ds = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 19);
    c5_b_theta = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 20);
    c5_b_phi = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 21);
    c5_b_r = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 22);
    for (c5_i70 = 0; c5_i70 < 6; c5_i70++) {
      c5_b_hdbar[c5_i70] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 23);
    for (c5_i71 = 0; c5_i71 < 6; c5_i71++) {
      c5_b_u_star[c5_i71] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 24);
    for (c5_i72 = 0; c5_i72 < 6; c5_i72++) {
      c5_b_u_pd[c5_i72] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 25);
    break;

   case 1:
    CV_EML_SWITCH(0, 1, 0, 2);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 29);
    c5_b_ControlParams.Output.SaturateS = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 31);
    for (c5_i73 = 0; c5_i73 < 2; c5_i73++) {
      c5_b_ControlParams.Feedback.kff_grav[c5_i73] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 32);
    for (c5_i74 = 0; c5_i74 < 2; c5_i74++) {
      c5_b_ControlParams.Feedback.kff_decoup[c5_i74] = 0.0;
    }

    guard1 = true;
    break;

   case 2:
    CV_EML_SWITCH(0, 1, 0, 3);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 36);
    c5_b_ControlParams.Output.SaturateS = 1.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 37);
    c5_b_ControlParams.Feedback.Use2DOF = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 38);
    for (c5_i75 = 0; c5_i75 < 2; c5_i75++) {
      c5_b_ControlParams.Feedback.kff_grav[c5_i75] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 39);
    for (c5_i76 = 0; c5_i76 < 2; c5_i76++) {
      c5_b_ControlParams.Feedback.kff_decoup[c5_i76] = 0.0;
    }

    guard1 = true;
    break;

   case 3:
    CV_EML_SWITCH(0, 1, 0, 4);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 43);
    c5_b_ControlParams.Feedback.Use2DOF = 0.0;
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 44);
    for (c5_i77 = 0; c5_i77 < 2; c5_i77++) {
      c5_b_ControlParams.Feedback.kff_grav[c5_i77] = 0.0;
    }

    guard1 = true;
    break;

   case 4:
    CV_EML_SWITCH(0, 1, 0, 5);
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 50);
    if (CV_EML_IF(0, 1, 0, CV_EML_MCDC(0, 1, 0, !CV_EML_COND(0, 1, 0,
           c5_b_ControlState.InDoubleSupport != 0.0)))) {
      _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 51);
      c5_c_ControlParams = c5_b_ControlParams;
      c5_applyGaitTweaks2(chartInstance, c5_b_ControlState, &c5_c_ControlParams,
                          c5_dv7);
      for (c5_i78 = 0; c5_i78 < 36; c5_i78++) {
        c5_HAlpha[c5_i78] = c5_dv7[c5_i78];
      }
    }

    guard1 = true;
    break;

   default:
    CV_EML_SWITCH(0, 1, 0, 0);
    guard1 = true;
    break;
  }

  if (guard1 == true) {
    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 55);
    for (c5_i79 = 0; c5_i79 < 36; c5_i79++) {
      c5_b_ControlParams.Output.HAlpha[c5_i79] = c5_HAlpha[c5_i79];
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 58);
    for (c5_i80 = 0; c5_i80 < 13; c5_i80++) {
      c5_H[c5_i80] = 0.0;
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 59);
    for (c5_i81 = 0; c5_i81 < 78; c5_i81++) {
      c5_B[c5_i81] = c5_dv8[c5_i81];
    }

    _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, 63);
    for (c5_i82 = 0; c5_i82 < 13; c5_i82++) {
      c5_c_q[c5_i82] = c5_b_q[c5_i82];
    }

    for (c5_i83 = 0; c5_i83 < 13; c5_i83++) {
      c5_c_dq[c5_i83] = c5_b_dq[c5_i83];
    }

    c5_d_ControlParams = c5_b_ControlParams;
    c5_ATRIAS3D_ZD_Control06(chartInstance, c5_b_t, c5_c_q, c5_c_dq, c5_b_D,
      c5_b_ControlState, &c5_d_ControlParams, c5_b_sprev, c5_c_u, c5_c_y,
      c5_c_dy, c5_c_hd, &c5_c_s, &c5_c_s_unsaturated, &c5_c_ds, &c5_c_theta,
      c5_c_u_star, c5_c_u_pd, &c5_c_phi, &c5_c_r, c5_c_hdbar);
    for (c5_i84 = 0; c5_i84 < 6; c5_i84++) {
      c5_b_u[c5_i84] = c5_c_u[c5_i84];
    }

    for (c5_i85 = 0; c5_i85 < 6; c5_i85++) {
      c5_b_y[c5_i85] = c5_c_y[c5_i85];
    }

    for (c5_i86 = 0; c5_i86 < 6; c5_i86++) {
      c5_b_dy[c5_i86] = c5_c_dy[c5_i86];
    }

    for (c5_i87 = 0; c5_i87 < 6; c5_i87++) {
      c5_b_hd[c5_i87] = c5_c_hd[c5_i87];
    }

    c5_b_s = c5_c_s;
    c5_b_s_unsaturated = c5_c_s_unsaturated;
    c5_b_ds = c5_c_ds;
    c5_b_theta = c5_c_theta;
    for (c5_i88 = 0; c5_i88 < 6; c5_i88++) {
      c5_b_u_star[c5_i88] = c5_c_u_star[c5_i88];
    }

    for (c5_i89 = 0; c5_i89 < 6; c5_i89++) {
      c5_b_u_pd[c5_i89] = c5_c_u_pd[c5_i89];
    }

    c5_b_phi = c5_c_phi;
    c5_b_r = c5_c_r;
    for (c5_i90 = 0; c5_i90 < 6; c5_i90++) {
      c5_b_hdbar[c5_i90] = c5_c_hdbar[c5_i90];
    }

    c5_condDecoup = 0.0;
  }

  _SFD_EML_CALL(0U, chartInstance->c5_sfEvent, -63);
  _SFD_SYMBOL_SCOPE_POP();
  for (c5_i91 = 0; c5_i91 < 6; c5_i91++) {
    (*chartInstance->c5_u)[c5_i91] = c5_b_u[c5_i91];
  }

  for (c5_i92 = 0; c5_i92 < 6; c5_i92++) {
    (*chartInstance->c5_y)[c5_i92] = c5_b_y[c5_i92];
  }

  for (c5_i93 = 0; c5_i93 < 6; c5_i93++) {
    (*chartInstance->c5_dy)[c5_i93] = c5_b_dy[c5_i93];
  }

  for (c5_i94 = 0; c5_i94 < 6; c5_i94++) {
    (*chartInstance->c5_hd)[c5_i94] = c5_b_hd[c5_i94];
  }

  *chartInstance->c5_s = c5_b_s;
  *chartInstance->c5_s_unsaturated = c5_b_s_unsaturated;
  *chartInstance->c5_ds = c5_b_ds;
  *chartInstance->c5_theta = c5_b_theta;
  *chartInstance->c5_phi = c5_b_phi;
  *chartInstance->c5_r = c5_b_r;
  for (c5_i95 = 0; c5_i95 < 6; c5_i95++) {
    (*chartInstance->c5_hdbar)[c5_i95] = c5_b_hdbar[c5_i95];
  }

  for (c5_i96 = 0; c5_i96 < 6; c5_i96++) {
    (*chartInstance->c5_u_star)[c5_i96] = c5_b_u_star[c5_i96];
  }

  for (c5_i97 = 0; c5_i97 < 6; c5_i97++) {
    (*chartInstance->c5_u_pd)[c5_i97] = c5_b_u_pd[c5_i97];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, chartInstance->c5_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_LibWalkingMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c5_i98 = 0; c5_i98 < 6; c5_i98++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_u)[c5_i98], 5U);
  }

  for (c5_i99 = 0; c5_i99 < 6; c5_i99++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_y)[c5_i99], 6U);
  }

  for (c5_i100 = 0; c5_i100 < 6; c5_i100++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_dy)[c5_i100], 7U);
  }

  for (c5_i101 = 0; c5_i101 < 6; c5_i101++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_hd)[c5_i101], 8U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_s, 9U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_s_unsaturated, 10U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_ds, 11U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_theta, 12U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_phi, 13U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_r, 14U);
  for (c5_i102 = 0; c5_i102 < 6; c5_i102++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_hdbar)[c5_i102], 15U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_D, 16U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_G, 17U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_pcm, 18U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_vcm, 19U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c5_sprev, 20U);
  for (c5_i103 = 0; c5_i103 < 6; c5_i103++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_u_star)[c5_i103], 21U);
  }

  for (c5_i104 = 0; c5_i104 < 6; c5_i104++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c5_u_pd)[c5_i104], 22U);
  }
}

static void mdl_start_c5_LibWalking(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc5_LibWalking(SFc5_LibWalkingInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c5_applyGaitTweaks2(SFc5_LibWalkingInstanceStruct *chartInstance,
  c5_ControlStateBus c5_b_ControlState, c5_ControlParamsBus *c5_b_ControlParams,
  real_T c5_HAlpha[36])
{
  uint32_T c5_debug_family_var_map[14];
  real_T c5_StanceKneeAngleBias;
  real_T c5_SwingKneeAngleBias1;
  real_T c5_SwingKneeAngleBias2;
  real_T c5_SwingKneeAngleBias3;
  real_T c5_TorsoBias;
  real_T c5_QTweakVec[13];
  real_T c5_QTweaks[78];
  real_T c5_SwingKeeAngleBias[4];
  boolean_T c5_GetTweaks;
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  real_T c5_A;
  real_T c5_b_A;
  real_T c5_c_A;
  real_T c5_d_A;
  real_T c5_e_A;
  real_T c5_f_A;
  real_T c5_b_y;
  real_T c5_g_A;
  real_T c5_c_y;
  real_T c5_h_A;
  real_T c5_d_y;
  real_T c5_i_A;
  real_T c5_e_y;
  real_T c5_j_A;
  real_T c5_f_y;
  real_T c5_k_A;
  real_T c5_g_y;
  real_T c5_l_A;
  real_T c5_h_y;
  real_T c5_m_A;
  real_T c5_i_y;
  int32_T c5_i105;
  real_T c5_b_QTweakVec[13];
  real_T c5_dv9[78];
  int32_T c5_i106;
  real_T c5_n_A[4];
  int32_T c5_i107;
  int32_T c5_i108;
  int32_T c5_i109;
  int32_T c5_i110;
  int32_T c5_i111;
  int32_T c5_i112;
  int32_T c5_i113;
  int32_T c5_i114;
  int32_T c5_i115;
  int32_T c5_i116;
  real_T c5_a[78];
  int32_T c5_i117;
  real_T c5_b[78];
  int32_T c5_i118;
  int32_T c5_i119;
  int32_T c5_i120;
  real_T c5_C[36];
  int32_T c5_i121;
  int32_T c5_i122;
  int32_T c5_i123;
  int32_T c5_i124;
  int32_T c5_i125;
  int32_T c5_i126;
  int32_T c5_i127;
  int32_T c5_i128;
  int32_T c5_i129;
  int32_T c5_i130;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 14U, 14U, c5_b_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_StanceKneeAngleBias, 0U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_SwingKneeAngleBias1, 1U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_SwingKneeAngleBias2, 2U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_SwingKneeAngleBias3, 3U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_TorsoBias, 4U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_QTweakVec, 5U, c5_e_sf_marshallOut,
    c5_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_QTweaks, 6U, c5_f_sf_marshallOut,
    c5_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_SwingKeeAngleBias, 7U,
    c5_i_sf_marshallOut, c5_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_GetTweaks, 8U, c5_h_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 9U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 10U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_ControlState, 11U,
    c5_d_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_ControlParams, 12U,
    c5_c_sf_marshallOut, c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_HAlpha, 13U, c5_g_sf_marshallOut,
    c5_c_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 9);
  CV_RELATIONAL_EVAL(14U, 0U, 0, 2.0, 2.0, -1, 0U, 1);
  CV_SCRIPT_IF(0, 0, true);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 10);
  c5_GetTweaks = false;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 13);
  c5_A = c5_b_ControlParams->Supervisory.GaitTweaks[0] * 3.1415926535897931;
  c5_StanceKneeAngleBias = c5_rdivide(chartInstance, c5_A, 180.0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 14);
  c5_b_A = c5_b_ControlParams->Supervisory.GaitTweaks[1] * 3.1415926535897931;
  c5_SwingKneeAngleBias1 = c5_rdivide(chartInstance, c5_b_A, 180.0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 15);
  c5_c_A = c5_b_ControlParams->Supervisory.GaitTweaks[2] * 3.1415926535897931;
  c5_SwingKneeAngleBias2 = c5_rdivide(chartInstance, c5_c_A, 180.0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 16);
  c5_d_A = c5_b_ControlParams->Supervisory.GaitTweaks[3] * 3.1415926535897931;
  c5_SwingKneeAngleBias3 = c5_rdivide(chartInstance, c5_d_A, 180.0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 17);
  c5_e_A = c5_b_ControlParams->Supervisory.GaitTweaks[4] * 3.1415926535897931;
  c5_TorsoBias = c5_rdivide(chartInstance, c5_e_A, 180.0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 19);
  c5_f_A = -c5_StanceKneeAngleBias;
  c5_b_y = c5_rdivide(chartInstance, c5_f_A, 2.0);
  c5_g_A = c5_StanceKneeAngleBias;
  c5_c_y = c5_rdivide(chartInstance, c5_g_A, 2.0);
  c5_h_A = -c5_StanceKneeAngleBias;
  c5_d_y = c5_rdivide(chartInstance, c5_h_A, 2.0);
  c5_i_A = c5_StanceKneeAngleBias;
  c5_e_y = c5_rdivide(chartInstance, c5_i_A, 2.0);
  c5_j_A = -c5_StanceKneeAngleBias;
  c5_f_y = c5_rdivide(chartInstance, c5_j_A, 2.0);
  c5_k_A = c5_StanceKneeAngleBias;
  c5_g_y = c5_rdivide(chartInstance, c5_k_A, 2.0);
  c5_l_A = -c5_StanceKneeAngleBias;
  c5_h_y = c5_rdivide(chartInstance, c5_l_A, 2.0);
  c5_m_A = c5_StanceKneeAngleBias;
  c5_i_y = c5_rdivide(chartInstance, c5_m_A, 2.0);
  c5_QTweakVec[0] = 0.0;
  c5_QTweakVec[1] = 0.0;
  c5_QTweakVec[2] = c5_TorsoBias;
  c5_QTweakVec[3] = c5_b_y - c5_TorsoBias;
  c5_QTweakVec[4] = c5_c_y - c5_TorsoBias;
  c5_QTweakVec[5] = c5_d_y - c5_TorsoBias;
  c5_QTweakVec[6] = c5_e_y - c5_TorsoBias;
  c5_QTweakVec[7] = c5_f_y - c5_TorsoBias;
  c5_QTweakVec[8] = c5_g_y - c5_TorsoBias;
  c5_QTweakVec[9] = 0.0;
  c5_QTweakVec[10] = c5_h_y - c5_TorsoBias;
  c5_QTweakVec[11] = c5_i_y - c5_TorsoBias;
  c5_QTweakVec[12] = 0.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 33);
  for (c5_i105 = 0; c5_i105 < 13; c5_i105++) {
    c5_b_QTweakVec[c5_i105] = c5_QTweakVec[c5_i105];
  }

  c5_repmat(chartInstance, c5_b_QTweakVec, c5_dv9);
  for (c5_i106 = 0; c5_i106 < 78; c5_i106++) {
    c5_QTweaks[c5_i106] = c5_dv9[c5_i106];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 35);
  if (CV_SCRIPT_IF(0, 1, CV_RELATIONAL_EVAL(14U, 0U, 1,
        c5_b_ControlState.ControllerMode, 4.0, -1, 0U,
        c5_b_ControlState.ControllerMode == 4.0))) {
    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 36);
    c5_n_A[0] = c5_SwingKneeAngleBias1;
    c5_n_A[1] = c5_SwingKneeAngleBias2;
    c5_n_A[2] = c5_SwingKneeAngleBias2;
    c5_n_A[3] = c5_SwingKneeAngleBias3;
    for (c5_i107 = 0; c5_i107 < 4; c5_i107++) {
      c5_SwingKeeAngleBias[c5_i107] = c5_n_A[c5_i107] / 2.0;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 37);
    c5_i108 = 0;
    for (c5_i109 = 0; c5_i109 < 4; c5_i109++) {
      c5_QTweaks[c5_i108 + 18] = -c5_SwingKeeAngleBias[c5_i109] - c5_TorsoBias;
      c5_i108 += 13;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 38);
    c5_i110 = 0;
    for (c5_i111 = 0; c5_i111 < 4; c5_i111++) {
      c5_QTweaks[c5_i110 + 19] = c5_SwingKeeAngleBias[c5_i111] - c5_TorsoBias;
      c5_i110 += 13;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 39);
    c5_i112 = 0;
    for (c5_i113 = 0; c5_i113 < 4; c5_i113++) {
      c5_QTweaks[c5_i112 + 23] = -c5_SwingKeeAngleBias[c5_i113] - c5_TorsoBias;
      c5_i112 += 13;
    }

    _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 40);
    c5_i114 = 0;
    for (c5_i115 = 0; c5_i115 < 4; c5_i115++) {
      c5_QTweaks[c5_i114 + 24] = c5_SwingKeeAngleBias[c5_i115] - c5_TorsoBias;
      c5_i114 += 13;
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 43);
  for (c5_i116 = 0; c5_i116 < 78; c5_i116++) {
    c5_a[c5_i116] = c5_b_ControlParams->Output.H0[c5_i116];
  }

  for (c5_i117 = 0; c5_i117 < 78; c5_i117++) {
    c5_b[c5_i117] = c5_QTweaks[c5_i117];
  }

  c5_eml_scalar_eg(chartInstance);
  c5_eml_scalar_eg(chartInstance);
  for (c5_i118 = 0; c5_i118 < 36; c5_i118++) {
    c5_HAlpha[c5_i118] = 0.0;
  }

  for (c5_i119 = 0; c5_i119 < 36; c5_i119++) {
    c5_HAlpha[c5_i119] = 0.0;
  }

  for (c5_i120 = 0; c5_i120 < 36; c5_i120++) {
    c5_C[c5_i120] = c5_HAlpha[c5_i120];
  }

  for (c5_i121 = 0; c5_i121 < 36; c5_i121++) {
    c5_HAlpha[c5_i121] = c5_C[c5_i121];
  }

  c5_threshold(chartInstance);
  for (c5_i122 = 0; c5_i122 < 36; c5_i122++) {
    c5_C[c5_i122] = c5_HAlpha[c5_i122];
  }

  for (c5_i123 = 0; c5_i123 < 36; c5_i123++) {
    c5_HAlpha[c5_i123] = c5_C[c5_i123];
  }

  for (c5_i124 = 0; c5_i124 < 6; c5_i124++) {
    c5_i125 = 0;
    c5_i126 = 0;
    for (c5_i127 = 0; c5_i127 < 6; c5_i127++) {
      c5_HAlpha[c5_i125 + c5_i124] = 0.0;
      c5_i128 = 0;
      for (c5_i129 = 0; c5_i129 < 13; c5_i129++) {
        c5_HAlpha[c5_i125 + c5_i124] += c5_a[c5_i128 + c5_i124] * c5_b[c5_i129 +
          c5_i126];
        c5_i128 += 6;
      }

      c5_i125 += 6;
      c5_i126 += 13;
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 44);
  CV_SCRIPT_MCDC(0, 0, !CV_SCRIPT_COND(0, 0, c5_GetTweaks));
  CV_SCRIPT_IF(0, 2, true);
  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, 45);
  for (c5_i130 = 0; c5_i130 < 36; c5_i130++) {
    c5_HAlpha[c5_i130] += c5_b_ControlParams->Output.HAlpha[c5_i130];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c5_sfEvent, -45);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_ATRIAS3D_ZD_s6(SFc5_LibWalkingInstanceStruct *chartInstance,
  real_T c5_b_t, real_T c5_b_q[13], real_T c5_b_dq[13], real_T c5_theta_limits[2],
  real_T c5_c[15], real_T *c5_b_s, real_T *c5_b_ds, real_T c5_dsdq[13], real_T
  *c5_th, real_T *c5_dth, real_T *c5_delta_theta)
{
  uint32_T c5_debug_family_var_map[13];
  real_T c5_b_c[15];
  real_T c5_nargin = 5.0;
  real_T c5_nargout = 6.0;
  int32_T c5_i131;
  int32_T c5_i132;
  real_T c5_a[15];
  real_T c5_b[15];
  int32_T c5_i133;
  int32_T c5_k;
  int32_T c5_b_k;
  int32_T c5_i134;
  int32_T c5_i135;
  int32_T c5_c_k;
  int32_T c5_d_k;
  real_T c5_b_a;
  int32_T c5_i136;
  real_T c5_b_y[13];
  int32_T c5_i137;
  real_T c5_x[13];
  int32_T c5_i138;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 14U, c5_c_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_c, MAX_uint32_T, c5_k_sf_marshallOut,
    c5_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 2U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_t, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_q, 4U, c5_e_sf_marshallOut,
    c5_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_dq, 5U, c5_e_sf_marshallOut,
    c5_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_theta_limits, 6U, c5_l_sf_marshallOut,
    c5_k_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_c, 0U, c5_k_sf_marshallOut,
    c5_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_s, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_ds, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_dsdq, 9U, c5_j_sf_marshallOut,
    c5_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_th, 10U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_dth, 11U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_delta_theta, 12U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  for (c5_i131 = 0; c5_i131 < 15; c5_i131++) {
    c5_b_c[c5_i131] = c5_c[c5_i131];
  }

  _SFD_SYMBOL_SWITCH(0U, 0U);
  CV_SCRIPT_FCN(3, 0);
  _SFD_SCRIPT_CALL(3U, chartInstance->c5_sfEvent, 5);
  CV_RELATIONAL_EVAL(14U, 3U, 0, 5.0, 5.0, -1, 2U, 0);
  CV_SCRIPT_IF(3, 0, false);
  _SFD_SCRIPT_CALL(3U, chartInstance->c5_sfEvent, 11);
  CV_RELATIONAL_EVAL(14U, 3U, 2, 2.0, 2.0, -1, 0U, 1);
  CV_SCRIPT_COND(3, 0, true);
  CV_SCRIPT_COND(3, 1, false);
  CV_SCRIPT_MCDC(3, 0, false);
  CV_SCRIPT_IF(3, 2, false);
  _SFD_SCRIPT_CALL(3U, chartInstance->c5_sfEvent, 15);
  for (c5_i132 = 0; c5_i132 < 15; c5_i132++) {
    c5_a[c5_i132] = c5_b_c[c5_i132];
  }

  c5_b[0] = 1.0;
  c5_b[1] = c5_b_t;
  for (c5_i133 = 0; c5_i133 < 13; c5_i133++) {
    c5_b[c5_i133 + 2] = c5_b_q[c5_i133];
  }

  c5_b_threshold(chartInstance);
  *c5_th = 0.0;
  c5_eml_switch_helper(chartInstance);
  for (c5_k = 1; c5_k < 16; c5_k++) {
    c5_b_k = c5_k - 1;
    *c5_th += c5_a[c5_b_k] * c5_b[c5_b_k];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c5_sfEvent, 16);
  for (c5_i134 = 0; c5_i134 < 15; c5_i134++) {
    c5_a[c5_i134] = c5_b_c[c5_i134];
  }

  c5_b[0] = 0.0;
  c5_b[1] = 1.0;
  for (c5_i135 = 0; c5_i135 < 13; c5_i135++) {
    c5_b[c5_i135 + 2] = c5_b_dq[c5_i135];
  }

  c5_b_threshold(chartInstance);
  *c5_dth = 0.0;
  c5_eml_switch_helper(chartInstance);
  for (c5_c_k = 1; c5_c_k < 16; c5_c_k++) {
    c5_d_k = c5_c_k - 1;
    *c5_dth += c5_a[c5_d_k] * c5_b[c5_d_k];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c5_sfEvent, 17);
  *c5_delta_theta = c5_theta_limits[1] - c5_theta_limits[0];
  _SFD_SCRIPT_CALL(3U, chartInstance->c5_sfEvent, 18);
  *c5_b_s = c5_rdivide(chartInstance, *c5_th - c5_theta_limits[0],
                       *c5_delta_theta);
  _SFD_SCRIPT_CALL(3U, chartInstance->c5_sfEvent, 19);
  *c5_b_ds = c5_rdivide(chartInstance, *c5_dth, *c5_delta_theta);
  _SFD_SCRIPT_CALL(3U, chartInstance->c5_sfEvent, 20);
  c5_b_a = *c5_delta_theta;
  for (c5_i136 = 0; c5_i136 < 13; c5_i136++) {
    c5_b_y[c5_i136] = c5_b_a;
  }

  for (c5_i137 = 0; c5_i137 < 13; c5_i137++) {
    c5_x[c5_i137] = c5_b_c[c5_i137 + 2];
  }

  for (c5_i138 = 0; c5_i138 < 13; c5_i138++) {
    c5_dsdq[c5_i138] = c5_x[c5_i138] / c5_b_y[c5_i138];
  }

  _SFD_SCRIPT_CALL(3U, chartInstance->c5_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_ATRIAS3D_ZD_Control06(SFc5_LibWalkingInstanceStruct
  *chartInstance, real_T c5_b_t, real_T c5_b_q[13], real_T c5_b_dq[13], real_T
  c5_b_D, c5_ControlStateBus c5_b_ControlState, c5_ControlParamsBus
  *c5_b_ControlParams, real_T c5_b_sprev, real_T c5_b_u[6], real_T c5_b_y[6],
  real_T c5_b_dy[6], real_T c5_b_hd[6], real_T *c5_b_s, real_T
  *c5_b_s_unsaturated, real_T *c5_b_ds, real_T *c5_b_theta, real_T c5_b_u_star[6],
  real_T c5_b_u_pd[6], real_T *c5_b_phi, real_T *c5_b_r, real_T c5_b_hdbar[6])
{
  uint32_T c5_debug_family_var_map[50];
  real_T c5_condDecoup;
  real_T c5_h0[6];
  real_T c5_jacob_h0[78];
  real_T c5_jacob_h[78];
  real_T c5_dtheta;
  real_T c5_delta_theta;
  real_T c5_dsdq[13];
  real_T c5_jacob_jacobhdqdq[6];
  real_T c5_dr;
  real_T c5_T0[36];
  real_T c5_TLegHip[12];
  real_T c5_L2fh[6];
  real_T c5_T[36];
  real_T c5_jacob_h_D_inv[78];
  real_T c5_epsilon[2];
  real_T c5_kp[6];
  real_T c5_kd[6];
  real_T c5_pd[6];
  real_T c5_Ttemp[36];
  real_T c5_kp_2dof;
  real_T c5_kd_2dof;
  real_T c5_kpre_2dof;
  real_T c5_q3_swing;
  real_T c5_dq3_swing;
  real_T c5_e_swing;
  real_T c5_u3_swing;
  real_T c5_H[13];
  real_T c5_B[78];
  real_T c5_nargin = 10.0;
  real_T c5_nargout = 14.0;
  int32_T c5_i139;
  static real_T c5_b[78] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 26.7, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 26.7 };

  int32_T c5_i140;
  int32_T c5_i141;
  real_T c5_c_q[13];
  int32_T c5_i142;
  real_T c5_c_dq[13];
  c5_ControlParamsBus c5_c_ControlParams;
  real_T c5_c_hdbar[6];
  real_T c5_b_dr;
  real_T c5_c_r;
  real_T c5_c_phi;
  real_T c5_b_jacob_jacobhdqdq[6];
  real_T c5_b_dsdq[13];
  real_T c5_b_delta_theta;
  real_T c5_b_dtheta;
  real_T c5_c_theta;
  real_T c5_c_s_unsaturated;
  real_T c5_b_jacob_h[78];
  real_T c5_b_jacob_h0[78];
  real_T c5_c_dy[6];
  real_T c5_c_y[6];
  real_T c5_b_h0[6];
  real_T c5_c_ds;
  real_T c5_c_s;
  int32_T c5_i143;
  int32_T c5_i144;
  int32_T c5_i145;
  int32_T c5_i146;
  int32_T c5_i147;
  int32_T c5_i148;
  int32_T c5_i149;
  int32_T c5_i150;
  int32_T c5_i151;
  int32_T c5_i152;
  static real_T c5_dv10[36] = { 0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.5, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0,
    0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c5_i153;
  int32_T c5_i154;
  static int32_T c5_iv0[6] = { 1, 0, 3, 2, 5, 4 };

  real_T c5_b_T0[36];
  int32_T c5_i155;
  int32_T c5_i156;
  int32_T c5_i157;
  int32_T c5_i158;
  static real_T c5_dv11[12] = { 1.0, 1.0, 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 1.0, 0.0,
    0.0, 1.0 };

  int32_T c5_i159;
  int32_T c5_i160;
  int32_T c5_i161;
  real_T c5_a[36];
  int32_T c5_i162;
  int32_T c5_i163;
  int32_T c5_i164;
  real_T c5_C[36];
  int32_T c5_i165;
  int32_T c5_i166;
  int32_T c5_i167;
  int32_T c5_i168;
  int32_T c5_i169;
  int32_T c5_i170;
  int32_T c5_i171;
  int32_T c5_i172;
  static real_T c5_b_b[36] = { 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 26.7, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0,
    0.0, 0.0, 0.0, 0.0, 50.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 26.7 };

  int32_T c5_i173;
  int32_T c5_i174;
  int32_T c5_i175;
  int32_T c5_i176;
  int32_T c5_i177;
  int32_T c5_i178;
  int32_T c5_i179;
  int32_T c5_i180;
  int32_T c5_i181;
  int32_T c5_i182;
  int32_T c5_i183;
  int32_T c5_i184;
  int32_T c5_i185;
  int32_T c5_i186;
  real_T c5_b_T[36];
  int32_T c5_i187;
  real_T c5_b_L2fh[6];
  real_T c5_dv12[6];
  int32_T c5_i188;
  int32_T c5_i189;
  real_T c5_d_ControlParams[36];
  real_T c5_dv13[6];
  int32_T c5_i190;
  int32_T c5_i191;
  static int32_T c5_iv1[6] = { 3, 4, 5, 0, 1, 2 };

  real_T c5_c_u_star[6];
  int32_T c5_i192;
  int32_T c5_i193;
  int32_T c5_i194;
  int32_T c5_i195;
  real_T c5_b_epsilon[6];
  int32_T c5_i196;
  int32_T c5_i197;
  int32_T c5_i198;
  real_T c5_e_ControlParams[6];
  int32_T c5_i199;
  real_T c5_c_h0[6];
  real_T c5_dv14[6];
  int32_T c5_i200;
  int32_T c5_i201;
  real_T c5_f_ControlParams[6];
  int32_T c5_i202;
  real_T c5_c_epsilon[6];
  int32_T c5_i203;
  int32_T c5_i204;
  real_T c5_dv15[6];
  int32_T c5_i205;
  int32_T c5_i206;
  int32_T c5_i207;
  real_T c5_c_T[36];
  int32_T c5_i208;
  real_T c5_b_pd[6];
  real_T c5_dv16[6];
  int32_T c5_i209;
  int32_T c5_i210;
  int32_T c5_i211;
  static int32_T c5_iv2[6] = { 0, 2, 4, 1, 3, 5 };

  real_T c5_b_kp[6];
  int32_T c5_i212;
  int32_T c5_i213;
  real_T c5_b_kd[6];
  int32_T c5_i214;
  int32_T c5_i215;
  real_T c5_b_Ttemp[36];
  int32_T c5_i216;
  real_T c5_d_y[6];
  int32_T c5_i217;
  real_T c5_c_Ttemp[36];
  int32_T c5_i218;
  real_T c5_d_dy[6];
  int32_T c5_i219;
  int32_T c5_i220;
  int32_T c5_i221;
  int32_T c5_i222;
  real_T c5_c_b[13];
  int32_T c5_k;
  int32_T c5_b_k;
  int32_T c5_i223;
  int32_T c5_i224;
  int32_T c5_i225;
  int32_T c5_c_k;
  int32_T c5_d_k;
  int32_T c5_i226;
  real_T c5_b_B;
  real_T c5_e_y;
  real_T c5_f_y;
  real_T c5_g_y;
  int32_T c5_i227;
  int32_T c5_i228;
  int32_T c5_i229;
  int32_T c5_i230;
  int32_T c5_i231;
  int32_T c5_i232;
  int32_T c5_i233;
  int32_T c5_i234;
  int32_T c5_i235;
  int32_T c5_i236;
  int32_T c5_i237;
  int32_T c5_i238;
  int32_T c5_i239;
  int32_T c5_i240;
  int32_T c5_i241;
  int32_T c5_i242;
  int32_T c5_i243;
  int32_T c5_i244;
  int32_T c5_i245;
  int32_T c5_i246;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 50U, 50U, c5_q_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_condDecoup, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_h0, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_jacob_h0, 2U, c5_q_sf_marshallOut,
    c5_p_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_jacob_h, 3U, c5_q_sf_marshallOut,
    c5_p_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_dtheta, 4U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_delta_theta, 5U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_dsdq, 6U, c5_j_sf_marshallOut,
    c5_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_jacob_jacobhdqdq, 7U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_dr, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_T0, 9U, c5_g_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_TLegHip, 10U, c5_u_sf_marshallOut,
    c5_u_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_L2fh, 11U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_T, 12U, c5_g_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_jacob_h_D_inv, 13U,
    c5_q_sf_marshallOut, c5_p_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_epsilon, 14U, c5_s_sf_marshallOut,
    c5_s_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_kp, 15U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_kd, 16U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_pd, 17U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_Ttemp, 18U, c5_g_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_kp_2dof, 19U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_kd_2dof, 20U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_kpre_2dof, 21U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_q3_swing, 22U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_dq3_swing, 23U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_e_swing, 24U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_u3_swing, 25U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_H, 26U, c5_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c5_B, 27U, c5_f_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 28U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 29U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_t, 30U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_q, 31U, c5_e_sf_marshallOut,
    c5_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_dq, 32U, c5_e_sf_marshallOut,
    c5_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_D, 33U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_ControlState, 34U,
    c5_d_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_ControlParams, 35U,
    c5_c_sf_marshallOut, c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_sprev, 36U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_u, 37U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_y, 38U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_dy, 39U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_hd, 40U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_s, 41U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_s_unsaturated, 42U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_ds, 43U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_theta, 44U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_u_star, 45U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_u_pd, 46U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_phi, 47U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_r, 48U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_hdbar, 49U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  for (c5_i139 = 0; c5_i139 < 78; c5_i139++) {
    c5_B[c5_i139] = c5_b[c5_i139];
  }

  for (c5_i140 = 0; c5_i140 < 13; c5_i140++) {
    c5_H[c5_i140] = 0.0;
  }

  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 10);
  for (c5_i141 = 0; c5_i141 < 13; c5_i141++) {
    c5_c_q[c5_i141] = c5_b_q[c5_i141];
  }

  for (c5_i142 = 0; c5_i142 < 13; c5_i142++) {
    c5_c_dq[c5_i142] = c5_b_dq[c5_i142];
  }

  c5_c_ControlParams = *c5_b_ControlParams;
  c5_ATRIAS3D_ZD_Output03(chartInstance, c5_b_t, c5_c_q, c5_c_dq,
    c5_b_ControlState, &c5_c_ControlParams, c5_b_sprev, &c5_c_s, &c5_c_ds,
    c5_b_h0, c5_c_y, c5_c_dy, c5_b_jacob_h0, c5_b_jacob_h, &c5_c_s_unsaturated,
    &c5_c_theta, &c5_b_dtheta, &c5_b_delta_theta, c5_b_dsdq,
    c5_b_jacob_jacobhdqdq, &c5_c_phi, &c5_c_r, &c5_b_dr, c5_c_hdbar);
  *c5_b_s = c5_c_s;
  *c5_b_ds = c5_c_ds;
  for (c5_i143 = 0; c5_i143 < 6; c5_i143++) {
    c5_h0[c5_i143] = c5_b_h0[c5_i143];
  }

  for (c5_i144 = 0; c5_i144 < 6; c5_i144++) {
    c5_b_y[c5_i144] = c5_c_y[c5_i144];
  }

  for (c5_i145 = 0; c5_i145 < 6; c5_i145++) {
    c5_b_dy[c5_i145] = c5_c_dy[c5_i145];
  }

  for (c5_i146 = 0; c5_i146 < 78; c5_i146++) {
    c5_jacob_h0[c5_i146] = c5_b_jacob_h0[c5_i146];
  }

  for (c5_i147 = 0; c5_i147 < 78; c5_i147++) {
    c5_jacob_h[c5_i147] = c5_b_jacob_h[c5_i147];
  }

  *c5_b_s_unsaturated = c5_c_s_unsaturated;
  *c5_b_theta = c5_c_theta;
  c5_dtheta = c5_b_dtheta;
  c5_delta_theta = c5_b_delta_theta;
  for (c5_i148 = 0; c5_i148 < 13; c5_i148++) {
    c5_dsdq[c5_i148] = c5_b_dsdq[c5_i148];
  }

  for (c5_i149 = 0; c5_i149 < 6; c5_i149++) {
    c5_jacob_jacobhdqdq[c5_i149] = c5_b_jacob_jacobhdqdq[c5_i149];
  }

  *c5_b_phi = c5_c_phi;
  *c5_b_r = c5_c_r;
  c5_dr = c5_b_dr;
  for (c5_i150 = 0; c5_i150 < 6; c5_i150++) {
    c5_b_hdbar[c5_i150] = c5_c_hdbar[c5_i150];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 11);
  for (c5_i151 = 0; c5_i151 < 6; c5_i151++) {
    c5_b_hd[c5_i151] = c5_h0[c5_i151] - c5_b_y[c5_i151];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 17);
  for (c5_i152 = 0; c5_i152 < 36; c5_i152++) {
    c5_T0[c5_i152] = c5_dv10[c5_i152];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 18);
  if (CV_SCRIPT_IF(1, 0, CV_RELATIONAL_EVAL(14U, 1U, 0,
        c5_b_ControlState.StanceLeg, 1.0, -1, 0U, c5_b_ControlState.StanceLeg ==
        1.0))) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 19);
    for (c5_i153 = 0; c5_i153 < 6; c5_i153++) {
      for (c5_i154 = 0; c5_i154 < 6; c5_i154++) {
        c5_b_T0[c5_i154 + 6 * c5_i153] = c5_T0[c5_iv0[c5_i154] + 6 * c5_i153];
      }
    }

    c5_i155 = 0;
    for (c5_i156 = 0; c5_i156 < 6; c5_i156++) {
      for (c5_i157 = 0; c5_i157 < 6; c5_i157++) {
        c5_T0[c5_i157 + c5_i155] = c5_b_T0[c5_i157 + c5_i155];
      }

      c5_i155 += 6;
    }
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 24);
  for (c5_i158 = 0; c5_i158 < 12; c5_i158++) {
    c5_TLegHip[c5_i158] = c5_dv11[c5_i158];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 27);
  for (c5_i159 = 0; c5_i159 < 6; c5_i159++) {
    c5_b_u_star[c5_i159] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 28);
  for (c5_i160 = 0; c5_i160 < 6; c5_i160++) {
    c5_L2fh[c5_i160] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 29);
  switch ((int32_T)_SFD_INTEGER_CHECK("ControlParams.Feedback.DecouplingMode",
           c5_b_ControlParams->Feedback.DecouplingMode)) {
   case 1:
    CV_SCRIPT_SWITCH(1, 0, 1);
    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 33);
    for (c5_i161 = 0; c5_i161 < 36; c5_i161++) {
      c5_a[c5_i161] = c5_T0[c5_i161];
    }

    c5_e_eml_scalar_eg(chartInstance);
    c5_e_eml_scalar_eg(chartInstance);
    for (c5_i162 = 0; c5_i162 < 36; c5_i162++) {
      c5_T[c5_i162] = 0.0;
    }

    for (c5_i163 = 0; c5_i163 < 36; c5_i163++) {
      c5_T[c5_i163] = 0.0;
    }

    for (c5_i164 = 0; c5_i164 < 36; c5_i164++) {
      c5_C[c5_i164] = c5_T[c5_i164];
    }

    for (c5_i165 = 0; c5_i165 < 36; c5_i165++) {
      c5_T[c5_i165] = c5_C[c5_i165];
    }

    c5_threshold(chartInstance);
    for (c5_i166 = 0; c5_i166 < 36; c5_i166++) {
      c5_C[c5_i166] = c5_T[c5_i166];
    }

    for (c5_i167 = 0; c5_i167 < 36; c5_i167++) {
      c5_T[c5_i167] = c5_C[c5_i167];
    }

    for (c5_i168 = 0; c5_i168 < 6; c5_i168++) {
      c5_i169 = 0;
      for (c5_i170 = 0; c5_i170 < 6; c5_i170++) {
        c5_T[c5_i169 + c5_i168] = 0.0;
        c5_i171 = 0;
        for (c5_i172 = 0; c5_i172 < 6; c5_i172++) {
          c5_T[c5_i169 + c5_i168] += c5_a[c5_i171 + c5_i168] * c5_b_b[c5_i172 +
            c5_i169];
          c5_i171 += 6;
        }

        c5_i169 += 6;
      }
    }
    break;

   case 2:
    CV_SCRIPT_SWITCH(1, 0, 2);
    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 36);
    for (c5_i173 = 0; c5_i173 < 78; c5_i173++) {
      c5_b_jacob_h0[c5_i173] = c5_jacob_h0[c5_i173];
    }

    c5_eml_scalar_eg(chartInstance);
    c5_eml_scalar_eg(chartInstance);
    for (c5_i174 = 0; c5_i174 < 36; c5_i174++) {
      c5_T[c5_i174] = 0.0;
    }

    for (c5_i175 = 0; c5_i175 < 36; c5_i175++) {
      c5_T[c5_i175] = 0.0;
    }

    for (c5_i176 = 0; c5_i176 < 36; c5_i176++) {
      c5_C[c5_i176] = c5_T[c5_i176];
    }

    for (c5_i177 = 0; c5_i177 < 36; c5_i177++) {
      c5_T[c5_i177] = c5_C[c5_i177];
    }

    c5_threshold(chartInstance);
    for (c5_i178 = 0; c5_i178 < 36; c5_i178++) {
      c5_C[c5_i178] = c5_T[c5_i178];
    }

    for (c5_i179 = 0; c5_i179 < 36; c5_i179++) {
      c5_T[c5_i179] = c5_C[c5_i179];
    }

    for (c5_i180 = 0; c5_i180 < 6; c5_i180++) {
      c5_i181 = 0;
      c5_i182 = 0;
      for (c5_i183 = 0; c5_i183 < 6; c5_i183++) {
        c5_T[c5_i181 + c5_i180] = 0.0;
        c5_i184 = 0;
        for (c5_i185 = 0; c5_i185 < 13; c5_i185++) {
          c5_T[c5_i181 + c5_i180] += c5_b_jacob_h0[c5_i184 + c5_i180] *
            c5_b[c5_i185 + c5_i182];
          c5_i184 += 6;
        }

        c5_i181 += 6;
        c5_i182 += 13;
      }
    }
    break;

   default:
    CV_SCRIPT_SWITCH(1, 0, 0);
    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 39);
    for (c5_i227 = 0; c5_i227 < 78; c5_i227++) {
      c5_b_jacob_h0[c5_i227] = c5_jacob_h[c5_i227];
    }

    c5_b_B = c5_b_D;
    c5_e_y = c5_b_B;
    c5_f_y = c5_e_y;
    c5_g_y = c5_f_y;
    for (c5_i228 = 0; c5_i228 < 78; c5_i228++) {
      c5_jacob_h_D_inv[c5_i228] = c5_b_jacob_h0[c5_i228] / c5_g_y;
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 40);
    for (c5_i229 = 0; c5_i229 < 78; c5_i229++) {
      c5_b_jacob_h0[c5_i229] = c5_jacob_h_D_inv[c5_i229];
    }

    c5_eml_scalar_eg(chartInstance);
    c5_eml_scalar_eg(chartInstance);
    for (c5_i230 = 0; c5_i230 < 36; c5_i230++) {
      c5_T[c5_i230] = 0.0;
    }

    for (c5_i231 = 0; c5_i231 < 36; c5_i231++) {
      c5_T[c5_i231] = 0.0;
    }

    for (c5_i232 = 0; c5_i232 < 36; c5_i232++) {
      c5_C[c5_i232] = c5_T[c5_i232];
    }

    for (c5_i233 = 0; c5_i233 < 36; c5_i233++) {
      c5_T[c5_i233] = c5_C[c5_i233];
    }

    c5_threshold(chartInstance);
    for (c5_i234 = 0; c5_i234 < 36; c5_i234++) {
      c5_C[c5_i234] = c5_T[c5_i234];
    }

    for (c5_i235 = 0; c5_i235 < 36; c5_i235++) {
      c5_T[c5_i235] = c5_C[c5_i235];
    }

    for (c5_i236 = 0; c5_i236 < 6; c5_i236++) {
      c5_i243 = 0;
      c5_i244 = 0;
      for (c5_i237 = 0; c5_i237 < 6; c5_i237++) {
        c5_T[c5_i243 + c5_i236] = 0.0;
        c5_i245 = 0;
        for (c5_i238 = 0; c5_i238 < 13; c5_i238++) {
          c5_T[c5_i243 + c5_i236] += c5_b_jacob_h0[c5_i245 + c5_i236] *
            c5_b[c5_i238 + c5_i244];
          c5_i245 += 6;
        }

        c5_i243 += 6;
        c5_i244 += 13;
      }
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 41);
    for (c5_i239 = 0; c5_i239 < 78; c5_i239++) {
      c5_b_jacob_h0[c5_i239] = -c5_jacob_h_D_inv[c5_i239];
    }

    c5_c_eml_scalar_eg(chartInstance);
    c5_c_eml_scalar_eg(chartInstance);
    c5_threshold(chartInstance);
    for (c5_i240 = 0; c5_i240 < 6; c5_i240++) {
      c5_c_y[c5_i240] = 0.0;
      c5_i246 = 0;
      for (c5_i241 = 0; c5_i241 < 13; c5_i241++) {
        c5_c_y[c5_i240] += c5_b_jacob_h0[c5_i246 + c5_i240] * 0.0;
        c5_i246 += 6;
      }
    }

    for (c5_i242 = 0; c5_i242 < 6; c5_i242++) {
      c5_L2fh[c5_i242] = c5_c_y[c5_i242] + c5_jacob_jacobhdqdq[c5_i242];
    }
    break;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 44);
  if (CV_SCRIPT_IF(1, 1, CV_RELATIONAL_EVAL(14U, 1U, 1,
        c5_b_ControlState.StepCount,
        c5_b_ControlParams->Feedback.EnableFeedforwardOnStep, -1, 5U,
        c5_b_ControlState.StepCount >=
        c5_b_ControlParams->Feedback.EnableFeedforwardOnStep))) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 45);
    if (CV_SCRIPT_IF(1, 2, CV_RELATIONAL_EVAL(14U, 1U, 2,
          c5_b_ControlParams->Feedback.SelectFeedforward, 1.0, -1, 0U,
          c5_b_ControlParams->Feedback.SelectFeedforward == 1.0))) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 46);
      for (c5_i186 = 0; c5_i186 < 36; c5_i186++) {
        c5_b_T[c5_i186] = -c5_T[c5_i186];
      }

      for (c5_i187 = 0; c5_i187 < 6; c5_i187++) {
        c5_b_L2fh[c5_i187] = c5_L2fh[c5_i187];
      }

      c5_mldivide(chartInstance, c5_b_T, c5_b_L2fh, c5_dv12);
      for (c5_i188 = 0; c5_i188 < 6; c5_i188++) {
        c5_b_u_star[c5_i188] = c5_dv12[c5_i188];
      }
    } else {
      _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 47);
      if (CV_SCRIPT_IF(1, 3, CV_RELATIONAL_EVAL(14U, 1U, 3,
            c5_b_ControlParams->Feedback.SelectFeedforward, 2.0, -1, 0U,
            c5_b_ControlParams->Feedback.SelectFeedforward == 2.0))) {
        _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 48);
        for (c5_i189 = 0; c5_i189 < 36; c5_i189++) {
          c5_d_ControlParams[c5_i189] = c5_b_ControlParams->
            Output.HAlphaStar[c5_i189];
        }

        c5_b_bezier(chartInstance, c5_d_ControlParams, *c5_b_s, c5_dv13);
        for (c5_i190 = 0; c5_i190 < 6; c5_i190++) {
          c5_b_u_star[c5_i190] = c5_dv13[c5_i190];
        }

        _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 49);
        if (CV_SCRIPT_IF(1, 4, CV_RELATIONAL_EVAL(14U, 1U, 4,
              c5_b_ControlState.StanceLeg, 1.0, -1, 0U,
              c5_b_ControlState.StanceLeg == 1.0))) {
          _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 50);
          for (c5_i191 = 0; c5_i191 < 6; c5_i191++) {
            c5_c_u_star[c5_i191] = c5_b_u_star[c5_iv1[c5_i191]];
          }

          for (c5_i192 = 0; c5_i192 < 6; c5_i192++) {
            c5_b_u_star[c5_i192] = c5_c_u_star[c5_i192];
          }
        }
      }
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 53);
    for (c5_i193 = 0; c5_i193 < 6; c5_i193++) {
      c5_b_u_star[c5_i193] *= c5_b_ControlParams->
        Feedback.FeedforwardGain[c5_i193];
    }
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 56);
  CV_SCRIPT_IF(1, 5, false);
  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 60);
  c5_condDecoup = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 63);
  CV_SCRIPT_IF(1, 6, false);
  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 95);
  for (c5_i194 = 0; c5_i194 < 2; c5_i194++) {
    c5_epsilon[c5_i194] = c5_b_ControlParams->Feedback.epsilon[c5_i194];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 96);
  for (c5_i195 = 0; c5_i195 < 2; c5_i195++) {
    c5_b_epsilon[c5_i195] = c5_epsilon[c5_i195];
  }

  for (c5_i196 = 0; c5_i196 < 2; c5_i196++) {
    c5_b_epsilon[c5_i196 + 2] = c5_epsilon[c5_i196];
  }

  for (c5_i197 = 0; c5_i197 < 2; c5_i197++) {
    c5_b_epsilon[c5_i197 + 4] = c5_epsilon[c5_i197];
  }

  c5_power(chartInstance, c5_b_epsilon, c5_b_h0);
  for (c5_i198 = 0; c5_i198 < 6; c5_i198++) {
    c5_e_ControlParams[c5_i198] = c5_b_ControlParams->Feedback.kp[c5_i198];
  }

  for (c5_i199 = 0; c5_i199 < 6; c5_i199++) {
    c5_c_h0[c5_i199] = c5_b_h0[c5_i199];
  }

  c5_b_rdivide(chartInstance, c5_e_ControlParams, c5_c_h0, c5_dv14);
  for (c5_i200 = 0; c5_i200 < 6; c5_i200++) {
    c5_kp[c5_i200] = c5_dv14[c5_i200];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 97);
  for (c5_i201 = 0; c5_i201 < 6; c5_i201++) {
    c5_f_ControlParams[c5_i201] = c5_b_ControlParams->Feedback.kd[c5_i201];
  }

  for (c5_i202 = 0; c5_i202 < 2; c5_i202++) {
    c5_c_epsilon[c5_i202] = c5_epsilon[c5_i202];
  }

  for (c5_i203 = 0; c5_i203 < 2; c5_i203++) {
    c5_c_epsilon[c5_i203 + 2] = c5_epsilon[c5_i203];
  }

  for (c5_i204 = 0; c5_i204 < 2; c5_i204++) {
    c5_c_epsilon[c5_i204 + 4] = c5_epsilon[c5_i204];
  }

  c5_b_rdivide(chartInstance, c5_f_ControlParams, c5_c_epsilon, c5_dv15);
  for (c5_i205 = 0; c5_i205 < 6; c5_i205++) {
    c5_kd[c5_i205] = c5_dv15[c5_i205];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 100);
  if (CV_SCRIPT_IF(1, 8, CV_SCRIPT_MCDC(1, 0, !CV_SCRIPT_COND(1, 0,
         c5_b_ControlParams->Feedback.linkFeedback != 0.0)))) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 101);
    for (c5_i206 = 0; c5_i206 < 6; c5_i206++) {
      c5_pd[c5_i206] = c5_kp[c5_i206] * c5_b_y[c5_i206] + c5_kd[c5_i206] *
        c5_b_dy[c5_i206];
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 102);
    for (c5_i207 = 0; c5_i207 < 36; c5_i207++) {
      c5_c_T[c5_i207] = -c5_T[c5_i207];
    }

    for (c5_i208 = 0; c5_i208 < 6; c5_i208++) {
      c5_b_pd[c5_i208] = c5_pd[c5_i208];
    }

    c5_mldivide(chartInstance, c5_c_T, c5_b_pd, c5_dv16);
    for (c5_i209 = 0; c5_i209 < 6; c5_i209++) {
      c5_b_u_pd[c5_i209] = c5_dv16[c5_i209];
    }
  } else {
    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 105);
    for (c5_i210 = 0; c5_i210 < 36; c5_i210++) {
      c5_Ttemp[c5_i210] = c5_T[c5_i210];
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 108);
    for (c5_i211 = 0; c5_i211 < 6; c5_i211++) {
      c5_b_kp[c5_i211] = c5_kp[c5_iv2[c5_i211]];
    }

    for (c5_i212 = 0; c5_i212 < 6; c5_i212++) {
      c5_kp[c5_i212] = c5_b_kp[c5_i212];
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 109);
    for (c5_i213 = 0; c5_i213 < 6; c5_i213++) {
      c5_b_kd[c5_i213] = c5_kd[c5_iv2[c5_i213]];
    }

    for (c5_i214 = 0; c5_i214 < 6; c5_i214++) {
      c5_kd[c5_i214] = c5_b_kd[c5_i214];
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 110);
    for (c5_i215 = 0; c5_i215 < 36; c5_i215++) {
      c5_b_Ttemp[c5_i215] = c5_Ttemp[c5_i215];
    }

    for (c5_i216 = 0; c5_i216 < 6; c5_i216++) {
      c5_d_y[c5_i216] = c5_b_y[c5_i216];
    }

    c5_mldivide(chartInstance, c5_b_Ttemp, c5_d_y, c5_b_h0);
    for (c5_i217 = 0; c5_i217 < 36; c5_i217++) {
      c5_c_Ttemp[c5_i217] = c5_Ttemp[c5_i217];
    }

    for (c5_i218 = 0; c5_i218 < 6; c5_i218++) {
      c5_d_dy[c5_i218] = c5_b_dy[c5_i218];
    }

    c5_mldivide(chartInstance, c5_c_Ttemp, c5_d_dy, c5_c_y);
    for (c5_i219 = 0; c5_i219 < 6; c5_i219++) {
      c5_b_u_pd[c5_i219] = -c5_kp[c5_i219] * c5_b_h0[c5_i219] - c5_kd[c5_i219] *
        c5_c_y[c5_i219];
    }
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 115);
  if (CV_SCRIPT_IF(1, 9, c5_b_ControlParams->Feedback.Use2DOF != 0.0)) {
    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 116);
    c5_kp_2dof = c5_b_ControlParams->Feedback.kp_2dof;
    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 117);
    c5_kd_2dof = c5_b_ControlParams->Feedback.kd_2dof;
    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 118);
    c5_kpre_2dof = c5_b_ControlParams->Feedback.kpre_2dof;
    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 120);
    c5_i220 = 0;
    for (c5_i221 = 0; c5_i221 < 13; c5_i221++) {
      c5_b_dsdq[c5_i221] = c5_jacob_h0[c5_i220 + 5];
      c5_i220 += 6;
    }

    for (c5_i222 = 0; c5_i222 < 13; c5_i222++) {
      c5_c_b[c5_i222] = c5_b_q[c5_i222];
    }

    c5_b_threshold(chartInstance);
    c5_q3_swing = 0.0;
    c5_eml_switch_helper(chartInstance);
    for (c5_k = 1; c5_k < 14; c5_k++) {
      c5_b_k = c5_k - 1;
      c5_q3_swing += c5_b_dsdq[c5_b_k] * c5_c_b[c5_b_k];
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 121);
    c5_i223 = 0;
    for (c5_i224 = 0; c5_i224 < 13; c5_i224++) {
      c5_b_dsdq[c5_i224] = c5_jacob_h0[c5_i223 + 5];
      c5_i223 += 6;
    }

    for (c5_i225 = 0; c5_i225 < 13; c5_i225++) {
      c5_c_b[c5_i225] = c5_b_dq[c5_i225];
    }

    c5_b_threshold(chartInstance);
    c5_dq3_swing = 0.0;
    c5_eml_switch_helper(chartInstance);
    for (c5_c_k = 1; c5_c_k < 14; c5_c_k++) {
      c5_d_k = c5_c_k - 1;
      c5_dq3_swing += c5_b_dsdq[c5_d_k] * c5_c_b[c5_d_k];
    }

    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 122);
    c5_e_swing = c5_kpre_2dof * c5_b_hd[5] - c5_q3_swing;
    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 123);
    c5_u3_swing = c5_kp_2dof * c5_e_swing - c5_kd_2dof * c5_dq3_swing;
    _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 125);
    if (CV_SCRIPT_IF(1, 10, CV_RELATIONAL_EVAL(14U, 1U, 6,
          c5_b_ControlState.StanceLeg, 0.0, -1, 0U, c5_b_ControlState.StanceLeg ==
          0.0))) {
      _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 126);
      c5_b_u_pd[5] = c5_u3_swing;
    } else {
      _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 128U);
      c5_b_u_pd[2] = c5_u3_swing;
    }
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 132U);
  CV_SCRIPT_IF(1, 11, false);
  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, 157U);
  for (c5_i226 = 0; c5_i226 < 6; c5_i226++) {
    c5_b_u[c5_i226] = c5_b_u_pd[c5_i226] + c5_b_u_star[c5_i226];
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c5_sfEvent, -157);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_ATRIAS3D_ZD_Output03(SFc5_LibWalkingInstanceStruct *chartInstance,
  real_T c5_b_t, real_T c5_b_q[13], real_T c5_b_dq[13], c5_ControlStateBus
  c5_b_ControlState, c5_ControlParamsBus *c5_b_ControlParams, real_T c5_b_sprev,
  real_T *c5_b_s, real_T *c5_b_ds, real_T c5_h0[6], real_T c5_b_y[6], real_T
  c5_b_dy[6], real_T c5_jacob_h0[78], real_T c5_jacob_h[78], real_T
  *c5_b_s_unsaturated, real_T *c5_b_theta, real_T *c5_dtheta, real_T
  *c5_delta_theta, real_T c5_dsdq[13], real_T c5_jacob_jacobhdqdq[6], real_T
  *c5_b_phi, real_T *c5_b_r, real_T *c5_dr, real_T c5_b_hdbar[6])
{
  uint32_T c5_debug_family_var_map[55];
  c5_OutputParamsBus c5_Output;
  real_T c5_T0[36];
  real_T c5_T1[78];
  real_T c5_c[15];
  real_T c5_h_alpha[36];
  real_T c5_delta;
  real_T c5_dqyTds[2];
  real_T c5_s6[6];
  real_T c5_h_alpha_high[36];
  real_T c5_h_alpha_low[36];
  real_T c5_smin;
  real_T c5_smax;
  real_T c5_qmod[13];
  real_T c5_b_hd[6];
  real_T c5_jacob_hd[6];
  real_T c5_jacob2_hd[6];
  real_T c5_dhd[6];
  real_T c5_dphi;
  real_T c5_phid;
  real_T c5_jacob_phid;
  real_T c5_jacob2_phid;
  boolean_T c5_RSaturated;
  real_T c5_jacob_hdbar[6];
  real_T c5_jacob2_hdbar[6];
  boolean_T c5_idxsat[6];
  real_T c5_hd_min[6];
  real_T c5_hd_max[6];
  real_T c5_sat_correction[6];
  real_T c5_h_alpha_corr[30];
  real_T c5_s_corr_max;
  real_T c5_nargin = 6.0;
  real_T c5_nargout = 17.0;
  int32_T c5_i247;
  static real_T c5_dv17[36] = { 0.5, 0.0, -1.0, 0.0, 0.0, 0.0, 0.5, 0.0, 1.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.5, 0.0, -1.0, 0.0, 0.0,
    0.0, 0.5, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0 };

  int32_T c5_i248;
  int32_T c5_i249;
  static int32_T c5_iv3[6] = { 1, 0, 3, 2, 5, 4 };

  real_T c5_b_T0[36];
  int32_T c5_i250;
  int32_T c5_i251;
  int32_T c5_i252;
  int32_T c5_i253;
  int32_T c5_i254;
  int32_T c5_i255;
  int32_T c5_i256;
  int32_T c5_i257;
  int32_T c5_i258;
  int32_T c5_i259;
  int32_T c5_i260;
  int32_T c5_i261;
  static int32_T c5_iv4[13] = { 0, 1, 2, 5, 6, 3, 4, 10, 11, 12, 7, 8, 9 };

  int32_T c5_i262;
  int32_T c5_i263;
  int32_T c5_i264;
  int32_T c5_i265;
  int32_T c5_i266;
  int32_T c5_i267;
  int32_T c5_i268;
  real_T c5_c_q[13];
  int32_T c5_i269;
  real_T c5_c_dq[13];
  int32_T c5_i270;
  real_T c5_b_Output[2];
  int32_T c5_i271;
  real_T c5_b_c[15];
  real_T c5_b_delta_theta;
  real_T c5_b_dtheta;
  real_T c5_c_theta;
  real_T c5_b_dsdq[13];
  real_T c5_c_ds;
  real_T c5_c_s;
  int32_T c5_i272;
  real_T c5_varargin_1;
  real_T c5_varargin_2;
  real_T c5_b_varargin_2;
  real_T c5_varargin_3;
  real_T c5_x;
  real_T c5_c_y;
  real_T c5_b_x;
  real_T c5_d_y;
  real_T c5_xk;
  real_T c5_yk;
  real_T c5_c_x;
  real_T c5_e_y;
  int32_T c5_i273;
  real_T c5_dv18[1];
  int32_T c5_tmp_sizes[2];
  int32_T c5_tmp_data[1];
  int32_T c5_loop_ub;
  int32_T c5_i274;
  real_T c5_dv19[1];
  int32_T c5_b_loop_ub;
  int32_T c5_i275;
  real_T c5_dv20[1];
  int32_T c5_c_loop_ub;
  int32_T c5_i276;
  real_T c5_dv21[1];
  int32_T c5_d_loop_ub;
  int32_T c5_i277;
  real_T c5_dv22[2];
  int32_T c5_i278;
  real_T c5_dv23[6];
  int32_T c5_i279;
  int32_T c5_i280;
  real_T c5_a[6];
  int32_T c5_i281;
  int32_T c5_i282;
  int32_T c5_i283;
  int32_T c5_i284;
  real_T c5_b_a[2];
  int32_T c5_i285;
  int32_T c5_i286;
  int32_T c5_i287;
  static real_T c5_b[6] = { -1.0, -0.8, -0.6, -0.4, -0.2, 0.0 };

  real_T c5_f_y[12];
  int32_T c5_i288;
  int32_T c5_i289;
  int32_T c5_i290;
  int32_T c5_i291;
  int32_T c5_i292;
  real_T c5_c_varargin_2[2];
  int32_T c5_k;
  int32_T c5_b_k;
  real_T c5_b_yk;
  real_T c5_g_y;
  real_T c5_extremum;
  real_T c5_maxval[2];
  int32_T c5_i293;
  int32_T c5_i294;
  boolean_T c5_b_s6[6];
  int32_T c5_b_tmp_sizes;
  int32_T c5_b_tmp_data[6];
  int32_T c5_e_loop_ub;
  int32_T c5_i295;
  int32_T c5_i296;
  boolean_T c5_c_s6[6];
  int32_T c5_c_tmp_sizes;
  int32_T c5_c_tmp_data[6];
  int32_T c5_d_tmp_sizes[2];
  int32_T c5_i297;
  int32_T c5_f_loop_ub;
  int32_T c5_i298;
  real_T c5_d_tmp_data[36];
  int32_T c5_iv5[2];
  int32_T c5_i299;
  int32_T c5_g_loop_ub;
  int32_T c5_i300;
  int32_T c5_i301;
  int32_T c5_i302;
  int32_T c5_i303;
  int32_T c5_i304;
  int32_T c5_i305;
  boolean_T c5_d_s6[6];
  int32_T c5_h_loop_ub;
  int32_T c5_i306;
  int32_T c5_i307;
  boolean_T c5_e_s6[6];
  int32_T c5_i308;
  int32_T c5_i_loop_ub;
  int32_T c5_i309;
  int32_T c5_iv6[2];
  int32_T c5_i310;
  int32_T c5_j_loop_ub;
  int32_T c5_i311;
  int32_T c5_k_loop_ub;
  int32_T c5_i312;
  int32_T c5_l_loop_ub;
  int32_T c5_i313;
  int32_T c5_m_loop_ub;
  int32_T c5_i314;
  int32_T c5_n_loop_ub;
  int32_T c5_i315;
  int32_T c5_i316;
  int32_T c5_i317;
  real_T c5_c_a[78];
  int32_T c5_i318;
  real_T c5_b_b[13];
  int32_T c5_i319;
  int32_T c5_i320;
  int32_T c5_i321;
  int32_T c5_i322;
  int32_T c5_i323;
  int32_T c5_i324;
  int32_T c5_i325;
  int32_T c5_i326;
  int32_T c5_i327;
  int32_T c5_i328;
  real_T c5_b_h_alpha[36];
  real_T c5_dv24[6];
  int32_T c5_i329;
  int32_T c5_i330;
  real_T c5_c_h_alpha[36];
  real_T c5_dv25[6];
  int32_T c5_i331;
  int32_T c5_i332;
  real_T c5_d_h_alpha[36];
  real_T c5_dv26[6];
  int32_T c5_i333;
  int32_T c5_i334;
  int32_T c5_i335;
  int32_T c5_i336;
  int32_T c5_i337;
  int32_T c5_i338;
  int32_T c5_i339;
  int32_T c5_i340;
  real_T c5_d_ds;
  int32_T c5_i341;
  int32_T c5_i342;
  int32_T c5_i343;
  int32_T c5_c_k;
  int32_T c5_d_k;
  int32_T c5_i344;
  int32_T c5_i345;
  int32_T c5_e_k;
  int32_T c5_f_k;
  int32_T c5_i346;
  real_T c5_c_Output[20];
  int32_T c5_i347;
  real_T c5_d_Output[30];
  real_T c5_dv27[6];
  int32_T c5_i348;
  int32_T c5_i349;
  real_T c5_e_Output[30];
  real_T c5_dv28[6];
  int32_T c5_i350;
  int32_T c5_i351;
  real_T c5_f_Output[30];
  real_T c5_dv29[6];
  int32_T c5_i352;
  int32_T c5_i353;
  int32_T c5_i354;
  int32_T c5_i355;
  real_T c5_c_hdbar[6];
  int32_T c5_i356;
  real_T c5_g_Output[6];
  int32_T c5_i357;
  real_T c5_h_Output[6];
  real_T c5_dv30[6];
  int32_T c5_i358;
  int32_T c5_i359;
  boolean_T c5_bv0[6];
  int32_T c5_i360;
  boolean_T c5_bv1[6];
  int32_T c5_i361;
  int32_T c5_i362;
  boolean_T c5_b_idxsat[6];
  int32_T c5_iv7[1];
  int32_T c5_o_loop_ub;
  int32_T c5_i363;
  int32_T c5_i364;
  boolean_T c5_c_idxsat[6];
  int32_T c5_iv8[1];
  int32_T c5_p_loop_ub;
  int32_T c5_i365;
  int32_T c5_i366;
  int32_T c5_i367;
  int32_T c5_i368;
  int32_T c5_i369;
  int32_T c5_i370;
  int32_T c5_i371;
  int32_T c5_i372;
  int32_T c5_i373;
  int32_T c5_i374;
  int32_T c5_i375;
  int32_T c5_i376;
  real_T c5_c_b;
  int32_T c5_i377;
  int32_T c5_i378;
  real_T c5_d_a[6];
  real_T c5_d_b;
  int32_T c5_i379;
  int32_T c5_i380;
  int32_T c5_i381;
  static real_T c5_dv31[6] = { 2.6179938779914944, 2.6179938779914944,
    0.26179938779914941, 0.26179938779914941, -0.3490658503988659,
    -0.3490658503988659 };

  int32_T c5_i382;
  static real_T c5_dv32[6] = { 3.839724354387525, 3.839724354387525,
    2.0943951023931953, 2.0943951023931953, 0.3490658503988659,
    0.3490658503988659 };

  int32_T c5_i383;
  int32_T c5_i384;
  int32_T c5_i385;
  int32_T c5_i386;
  int32_T c5_i387;
  int32_T c5_i388;
  int32_T c5_i389;
  int32_T c5_i390;
  int32_T c5_i391;
  int32_T c5_i392;
  int32_T c5_i393;
  int32_T c5_i394;
  real_T c5_c_hd[6];
  int32_T c5_i395;
  real_T c5_b_hd_min[6];
  int32_T c5_i396;
  real_T c5_b_hd_max[6];
  real_T c5_dv33[6];
  int32_T c5_i397;
  int32_T c5_i398;
  int32_T c5_i399;
  int32_T c5_i400;
  int32_T c5_i401;
  boolean_T c5_d_idxsat[6];
  int32_T c5_q_loop_ub;
  int32_T c5_i402;
  int32_T c5_i403;
  boolean_T c5_e_idxsat[6];
  int32_T c5_i404;
  boolean_T c5_f_idxsat[6];
  int32_T c5_e_tmp_sizes;
  int32_T c5_r_loop_ub;
  int32_T c5_i405;
  real_T c5_e_tmp_data[6];
  int32_T c5_s_loop_ub;
  int32_T c5_i406;
  int32_T c5_i407;
  int32_T c5_i408;
  int32_T c5_i409;
  int32_T c5_i410;
  int32_T c5_i411;
  int32_T c5_i412;
  int32_T c5_i413;
  int32_T c5_i414;
  int32_T c5_i415;
  real_T c5_b_h_alpha_corr[30];
  int32_T c5_i416;
  int32_T c5_i417;
  real_T c5_c_h_alpha_corr[30];
  int32_T c5_i418;
  int32_T c5_i419;
  real_T c5_d_h_alpha_corr[30];
  real_T c5_e_ds;
  int32_T c5_i420;
  int32_T c5_i421;
  real_T c5_e_h_alpha_corr[30];
  int32_T c5_i422;
  int32_T c5_i423;
  int32_T c5_i424;
  int32_T c5_i425;
  int32_T c5_i426;
  boolean_T guard1 = false;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 55U, 55U, c5_o_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_Output, 0U, c5_t_sf_marshallOut,
    c5_t_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_T0, 1U, c5_g_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_T1, 2U, c5_q_sf_marshallOut,
    c5_p_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_c, 3U, c5_k_sf_marshallOut,
    c5_j_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_h_alpha, 4U, c5_g_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_delta, 5U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_dqyTds, 6U, c5_s_sf_marshallOut,
    c5_s_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_s6, 7U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_h_alpha_high, 8U, c5_g_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_h_alpha_low, 9U, c5_g_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_smin, 10U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_smax, 11U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_qmod, 12U, c5_e_sf_marshallOut,
    c5_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_hd, 13U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_jacob_hd, 14U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_jacob2_hd, 15U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_dhd, 16U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_dphi, 17U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_phid, 18U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_jacob_phid, 19U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_jacob2_phid, 20U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_RSaturated, 21U, c5_h_sf_marshallOut,
    c5_r_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_jacob_hdbar, 22U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_jacob2_hdbar, 23U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_idxsat, 24U, c5_r_sf_marshallOut,
    c5_q_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_hd_min, 25U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_hd_max, 26U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_sat_correction, 27U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_h_alpha_corr, 28U, c5_p_sf_marshallOut,
    c5_o_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_s_corr_max, 29U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 30U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 31U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_t, 32U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_q, 33U, c5_e_sf_marshallOut,
    c5_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_dq, 34U, c5_e_sf_marshallOut,
    c5_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_ControlState, 35U,
    c5_d_sf_marshallOut, c5_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_ControlParams, 36U,
    c5_c_sf_marshallOut, c5_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_sprev, 37U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_s, 38U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_ds, 39U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_h0, 40U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_y, 41U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_dy, 42U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_jacob_h0, 43U, c5_q_sf_marshallOut,
    c5_p_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_jacob_h, 44U, c5_q_sf_marshallOut,
    c5_p_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_s_unsaturated, 45U,
    c5_b_sf_marshallOut, c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_theta, 46U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_dtheta, 47U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_delta_theta, 48U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_dsdq, 49U, c5_j_sf_marshallOut,
    c5_i_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_jacob_jacobhdqdq, 50U,
    c5_sf_marshallOut, c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_phi, 51U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_r, 52U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_dr, 53U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_hdbar, 54U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_SCRIPT_FCN(2, 0);
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 4);
  c5_Output = c5_b_ControlParams->Output;
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 8);
  for (c5_i247 = 0; c5_i247 < 36; c5_i247++) {
    c5_T0[c5_i247] = c5_dv17[c5_i247];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 9);
  if (CV_SCRIPT_IF(2, 0, CV_RELATIONAL_EVAL(14U, 2U, 0,
        c5_b_ControlState.StanceLeg, 1.0, -1, 0U, c5_b_ControlState.StanceLeg ==
        1.0))) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 10);
    for (c5_i248 = 0; c5_i248 < 6; c5_i248++) {
      for (c5_i249 = 0; c5_i249 < 6; c5_i249++) {
        c5_b_T0[c5_i249 + 6 * c5_i248] = c5_T0[c5_iv3[c5_i249] + 6 * c5_i248];
      }
    }

    c5_i250 = 0;
    for (c5_i251 = 0; c5_i251 < 6; c5_i251++) {
      for (c5_i252 = 0; c5_i252 < 6; c5_i252++) {
        c5_T0[c5_i252 + c5_i250] = c5_b_T0[c5_i252 + c5_i250];
      }

      c5_i250 += 6;
    }
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 12);
  c5_i253 = 0;
  for (c5_i254 = 0; c5_i254 < 7; c5_i254++) {
    for (c5_i255 = 0; c5_i255 < 6; c5_i255++) {
      c5_T1[c5_i255 + c5_i253] = 0.0;
    }

    c5_i253 += 6;
  }

  c5_i256 = 0;
  for (c5_i257 = 0; c5_i257 < 6; c5_i257++) {
    for (c5_i258 = 0; c5_i258 < 6; c5_i258++) {
      c5_T1[(c5_i258 + c5_i256) + 42] = c5_T0[c5_i258 + c5_i256];
    }

    c5_i256 += 6;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 16);
  if (CV_SCRIPT_IF(2, 1, CV_RELATIONAL_EVAL(14U, 2U, 1,
        c5_b_ControlState.StanceLeg, 0.0, -1, 0U, c5_b_ControlState.StanceLeg ==
        0.0))) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 17);
    c5_c[0] = c5_Output.Theta.c0;
    c5_c[1] = c5_Output.Theta.ct;
    for (c5_i259 = 0; c5_i259 < 13; c5_i259++) {
      c5_c[c5_i259 + 2] = c5_Output.Theta.cq[c5_i259];
    }

    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 18);
    for (c5_i260 = 0; c5_i260 < 78; c5_i260++) {
      c5_jacob_h0[c5_i260] = c5_Output.H0[c5_i260];
    }
  } else {
    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 20);
    c5_c[0] = c5_Output.Theta.c0;
    c5_c[1] = c5_Output.Theta.ct;
    for (c5_i261 = 0; c5_i261 < 13; c5_i261++) {
      c5_c[c5_i261 + 2] = c5_Output.Theta.cq[c5_iv4[c5_i261]];
    }

    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 21);
    for (c5_i262 = 0; c5_i262 < 2; c5_i262++) {
      c5_c[c5_i262 + 2] = -c5_c[c5_i262 + 2];
    }

    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 22);
    for (c5_i263 = 0; c5_i263 < 13; c5_i263++) {
      for (c5_i264 = 0; c5_i264 < 6; c5_i264++) {
        c5_jacob_h0[c5_i264 + 6 * c5_i263] = c5_Output.H0[c5_i264 + 6 *
          c5_iv4[c5_i263]];
      }
    }

    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 23);
    c5_i265 = 0;
    for (c5_i266 = 0; c5_i266 < 2; c5_i266++) {
      for (c5_i267 = 0; c5_i267 < 6; c5_i267++) {
        c5_jacob_h0[c5_i267 + c5_i265] = -c5_jacob_h0[c5_i267 + c5_i265];
      }

      c5_i265 += 6;
    }
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 27);
  for (c5_i268 = 0; c5_i268 < 13; c5_i268++) {
    c5_c_q[c5_i268] = c5_b_q[c5_i268];
  }

  for (c5_i269 = 0; c5_i269 < 13; c5_i269++) {
    c5_c_dq[c5_i269] = c5_b_dq[c5_i269];
  }

  for (c5_i270 = 0; c5_i270 < 2; c5_i270++) {
    c5_b_Output[c5_i270] = c5_Output.ThetaLimits[c5_i270];
  }

  for (c5_i271 = 0; c5_i271 < 15; c5_i271++) {
    c5_b_c[c5_i271] = c5_c[c5_i271];
  }

  c5_ATRIAS3D_ZD_s6(chartInstance, c5_b_t - c5_Output.Theta.t0, c5_c_q, c5_c_dq,
                    c5_b_Output, c5_b_c, &c5_c_s, &c5_c_ds, c5_b_dsdq,
                    &c5_c_theta, &c5_b_dtheta, &c5_b_delta_theta);
  *c5_b_s = c5_c_s;
  *c5_b_ds = c5_c_ds;
  for (c5_i272 = 0; c5_i272 < 13; c5_i272++) {
    c5_dsdq[c5_i272] = c5_b_dsdq[c5_i272];
  }

  *c5_b_theta = c5_c_theta;
  *c5_dtheta = c5_b_dtheta;
  *c5_delta_theta = c5_b_delta_theta;
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 28);
  *c5_b_s_unsaturated = *c5_b_s;
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 30);
  if (CV_SCRIPT_IF(2, 2, c5_Output.EnforceIncreasingS != 0.0)) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 31);
    c5_varargin_1 = *c5_b_s;
    c5_varargin_2 = c5_b_sprev;
    c5_b_varargin_2 = c5_varargin_1;
    c5_varargin_3 = c5_varargin_2;
    c5_x = c5_b_varargin_2;
    c5_c_y = c5_varargin_3;
    c5_b_x = c5_x;
    c5_d_y = c5_c_y;
    c5_b_eml_scalar_eg(chartInstance);
    c5_xk = c5_b_x;
    c5_yk = c5_d_y;
    c5_c_x = c5_xk;
    c5_e_y = c5_yk;
    c5_b_eml_scalar_eg(chartInstance);
    *c5_b_s = muDoubleScalarMax(c5_c_x, c5_e_y);
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 34);
  for (c5_i273 = 0; c5_i273 < 36; c5_i273++) {
    c5_h_alpha[c5_i273] = c5_Output.HAlpha[c5_i273];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 35);
  CV_SCRIPT_IF(2, 3, CV_RELATIONAL_EVAL(14U, 2U, 2, c5_b_ControlState.StanceLeg,
    1.0, -1, 0U, c5_b_ControlState.StanceLeg == 1.0));
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 39);
  if (CV_SCRIPT_IF(2, 4, CV_RELATIONAL_EVAL(14U, 2U, 3, c5_Output.SaturateS, 1.0,
        -1, 0U, c5_Output.SaturateS == 1.0))) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 44);
    c5_delta = 0.1;
    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 45);
    c5_dv18[0] = *c5_b_ds;
    c5_eml_li_find(chartInstance, *c5_b_s > 1.1, c5_tmp_data, c5_tmp_sizes);
    c5_loop_ub = c5_tmp_sizes[0] * c5_tmp_sizes[1] - 1;
    for (c5_i274 = 0; c5_i274 <= c5_loop_ub; c5_i274++) {
      c5_dv18[c5_tmp_data[c5_i274] - 1] = 0.0;
    }

    *c5_b_ds = c5_dv18[0];
    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 46);
    c5_dv19[0] = *c5_b_s;
    c5_eml_li_find(chartInstance, *c5_b_s > 1.1, c5_tmp_data, c5_tmp_sizes);
    c5_b_loop_ub = c5_tmp_sizes[0] * c5_tmp_sizes[1] - 1;
    for (c5_i275 = 0; c5_i275 <= c5_b_loop_ub; c5_i275++) {
      c5_dv19[c5_tmp_data[c5_i275] - 1] = 1.1;
    }

    *c5_b_s = c5_dv19[0];
    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 47);
    c5_dv20[0] = *c5_b_ds;
    c5_eml_li_find(chartInstance, *c5_b_s < -0.1, c5_tmp_data, c5_tmp_sizes);
    c5_c_loop_ub = c5_tmp_sizes[0] * c5_tmp_sizes[1] - 1;
    for (c5_i276 = 0; c5_i276 <= c5_c_loop_ub; c5_i276++) {
      c5_dv20[c5_tmp_data[c5_i276] - 1] = 0.0;
    }

    *c5_b_ds = c5_dv20[0];
    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 48);
    c5_dv21[0] = *c5_b_s;
    c5_eml_li_find(chartInstance, *c5_b_s < -0.1, c5_tmp_data, c5_tmp_sizes);
    c5_d_loop_ub = c5_tmp_sizes[0] * c5_tmp_sizes[1] - 1;
    for (c5_i277 = 0; c5_i277 <= c5_d_loop_ub; c5_i277++) {
      c5_dv21[c5_tmp_data[c5_i277] - 1] = -0.1;
    }

    *c5_b_s = c5_dv21[0];
  } else {
    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 50);
    if (CV_SCRIPT_IF(2, 5, CV_RELATIONAL_EVAL(14U, 2U, 4, c5_Output.SaturateS,
          2.0, -1, 0U, c5_Output.SaturateS == 2.0))) {
      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 51);
      CV_RELATIONAL_EVAL(14U, 2U, 5, 1.0, 1.0, -1, 4U, 0);
      CV_SCRIPT_IF(2, 6, false);
      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 55);
      c5_b_repmat(chartInstance, c5_c[4] * *c5_delta_theta, c5_dv22);
      for (c5_i278 = 0; c5_i278 < 2; c5_i278++) {
        c5_dqyTds[c5_i278] = c5_dv22[c5_i278];
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 56);
      c5_c_repmat(chartInstance, *c5_b_s, c5_dv23);
      for (c5_i279 = 0; c5_i279 < 6; c5_i279++) {
        c5_s6[c5_i279] = c5_dv23[c5_i279];
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 61);
      for (c5_i280 = 0; c5_i280 < 6; c5_i280++) {
        c5_a[c5_i280] = c5_h_alpha[c5_i280 + 30];
      }

      for (c5_i281 = 0; c5_i281 < 6; c5_i281++) {
        c5_i282 = 0;
        for (c5_i283 = 0; c5_i283 < 6; c5_i283++) {
          c5_h_alpha_high[c5_i282 + c5_i281] = c5_a[c5_i281];
          c5_i282 += 6;
        }
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 62);
      for (c5_i284 = 0; c5_i284 < 2; c5_i284++) {
        c5_b_a[c5_i284] = c5_dqyTds[c5_i284];
      }

      for (c5_i285 = 0; c5_i285 < 2; c5_i285++) {
        c5_i286 = 0;
        for (c5_i287 = 0; c5_i287 < 6; c5_i287++) {
          c5_f_y[c5_i286 + c5_i285] = c5_b_a[c5_i285] * c5_b[c5_i287];
          c5_i286 += 2;
        }
      }

      c5_i288 = 0;
      c5_i289 = 0;
      for (c5_i290 = 0; c5_i290 < 6; c5_i290++) {
        for (c5_i291 = 0; c5_i291 < 2; c5_i291++) {
          c5_h_alpha_high[c5_i291 + c5_i288] += c5_f_y[c5_i291 + c5_i289];
        }

        c5_i288 += 6;
        c5_i289 += 2;
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 63);
      for (c5_i292 = 0; c5_i292 < 2; c5_i292++) {
        c5_c_varargin_2[c5_i292] = c5_h_alpha_high[c5_i292];
      }

      c5_eml_switch_helper(chartInstance);
      for (c5_k = 1; c5_k < 3; c5_k++) {
        c5_b_k = c5_k - 1;
        c5_b_yk = c5_c_varargin_2[c5_b_k];
        c5_g_y = c5_b_yk;
        c5_b_eml_scalar_eg(chartInstance);
        c5_extremum = muDoubleScalarMax(2.6179938779914944, c5_g_y);
        c5_maxval[c5_b_k] = c5_extremum;
      }

      for (c5_i293 = 0; c5_i293 < 2; c5_i293++) {
        c5_h_alpha_high[c5_i293] = c5_maxval[c5_i293];
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 64);
      for (c5_i294 = 0; c5_i294 < 6; c5_i294++) {
        c5_b_s6[c5_i294] = (c5_s6[c5_i294] > 1.0);
      }

      c5_b_eml_li_find(chartInstance, c5_b_s6, c5_b_tmp_data, &c5_b_tmp_sizes);
      c5_b_tmp_sizes;
      c5_e_loop_ub = c5_b_tmp_sizes - 1;
      for (c5_i295 = 0; c5_i295 <= c5_e_loop_ub; c5_i295++) {
        c5_b_tmp_data[c5_i295]--;
      }

      for (c5_i296 = 0; c5_i296 < 6; c5_i296++) {
        c5_c_s6[c5_i296] = (c5_s6[c5_i296] > 1.0);
      }

      c5_b_eml_li_find(chartInstance, c5_c_s6, c5_c_tmp_data, &c5_c_tmp_sizes);
      c5_d_tmp_sizes[0] = c5_c_tmp_sizes;
      c5_d_tmp_sizes[1] = 6;
      for (c5_i297 = 0; c5_i297 < 6; c5_i297++) {
        c5_f_loop_ub = c5_c_tmp_sizes - 1;
        for (c5_i298 = 0; c5_i298 <= c5_f_loop_ub; c5_i298++) {
          c5_d_tmp_data[c5_i298 + c5_d_tmp_sizes[0] * c5_i297] =
            c5_h_alpha_high[(c5_c_tmp_data[c5_i298] + 6 * c5_i297) - 1];
        }
      }

      c5_iv5[0] = c5_b_tmp_sizes;
      c5_iv5[1] = 6;
      _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c5_iv5, 2, c5_d_tmp_sizes, 2);
      for (c5_i299 = 0; c5_i299 < 6; c5_i299++) {
        c5_g_loop_ub = c5_d_tmp_sizes[0] - 1;
        for (c5_i300 = 0; c5_i300 <= c5_g_loop_ub; c5_i300++) {
          c5_h_alpha[c5_b_tmp_data[c5_i300] + 6 * c5_i299] =
            c5_d_tmp_data[c5_i300 + c5_d_tmp_sizes[0] * c5_i299];
        }
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 67);
      for (c5_i301 = 0; c5_i301 < 6; c5_i301++) {
        c5_a[c5_i301] = c5_h_alpha[c5_i301];
      }

      for (c5_i302 = 0; c5_i302 < 6; c5_i302++) {
        c5_i303 = 0;
        for (c5_i304 = 0; c5_i304 < 6; c5_i304++) {
          c5_h_alpha_low[c5_i303 + c5_i302] = c5_a[c5_i302];
          c5_i303 += 6;
        }
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 68);
      for (c5_i305 = 0; c5_i305 < 6; c5_i305++) {
        c5_d_s6[c5_i305] = (c5_s6[c5_i305] < 0.0);
      }

      c5_b_eml_li_find(chartInstance, c5_d_s6, c5_b_tmp_data, &c5_b_tmp_sizes);
      c5_b_tmp_sizes;
      c5_h_loop_ub = c5_b_tmp_sizes - 1;
      for (c5_i306 = 0; c5_i306 <= c5_h_loop_ub; c5_i306++) {
        c5_b_tmp_data[c5_i306]--;
      }

      for (c5_i307 = 0; c5_i307 < 6; c5_i307++) {
        c5_e_s6[c5_i307] = (c5_s6[c5_i307] < 0.0);
      }

      c5_b_eml_li_find(chartInstance, c5_e_s6, c5_c_tmp_data, &c5_c_tmp_sizes);
      c5_d_tmp_sizes[0] = c5_c_tmp_sizes;
      c5_d_tmp_sizes[1] = 6;
      for (c5_i308 = 0; c5_i308 < 6; c5_i308++) {
        c5_i_loop_ub = c5_c_tmp_sizes - 1;
        for (c5_i309 = 0; c5_i309 <= c5_i_loop_ub; c5_i309++) {
          c5_d_tmp_data[c5_i309 + c5_d_tmp_sizes[0] * c5_i308] = c5_h_alpha_low
            [(c5_c_tmp_data[c5_i309] + 6 * c5_i308) - 1];
        }
      }

      c5_iv6[0] = c5_b_tmp_sizes;
      c5_iv6[1] = 6;
      _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c5_iv6, 2, c5_d_tmp_sizes, 2);
      for (c5_i310 = 0; c5_i310 < 6; c5_i310++) {
        c5_j_loop_ub = c5_d_tmp_sizes[0] - 1;
        for (c5_i311 = 0; c5_i311 <= c5_j_loop_ub; c5_i311++) {
          c5_h_alpha[c5_b_tmp_data[c5_i311] + 6 * c5_i310] =
            c5_d_tmp_data[c5_i311 + c5_d_tmp_sizes[0] * c5_i310];
        }
      }
    } else {
      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 70);
      if (CV_SCRIPT_IF(2, 7, CV_RELATIONAL_EVAL(14U, 2U, 6, c5_Output.SaturateS,
            3.0, -1, 0U, c5_Output.SaturateS == 3.0))) {
        _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 71);
        c5_smin = c5_Output.SLimits[0];
        _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 72);
        c5_smax = c5_Output.SLimits[1];
        _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 73);
        c5_dv18[0] = *c5_b_ds;
        c5_eml_li_find(chartInstance, *c5_b_s > c5_smax, c5_tmp_data,
                       c5_tmp_sizes);
        c5_k_loop_ub = c5_tmp_sizes[0] * c5_tmp_sizes[1] - 1;
        for (c5_i312 = 0; c5_i312 <= c5_k_loop_ub; c5_i312++) {
          c5_dv18[c5_tmp_data[c5_i312] - 1] = 0.0;
        }

        *c5_b_ds = c5_dv18[0];
        _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 74);
        c5_dv19[0] = *c5_b_s;
        c5_eml_li_find(chartInstance, *c5_b_s > c5_smax, c5_tmp_data,
                       c5_tmp_sizes);
        c5_l_loop_ub = c5_tmp_sizes[0] * c5_tmp_sizes[1] - 1;
        for (c5_i313 = 0; c5_i313 <= c5_l_loop_ub; c5_i313++) {
          c5_dv19[c5_tmp_data[c5_i313] - 1] = c5_smax;
        }

        *c5_b_s = c5_dv19[0];
        _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 75);
        c5_dv20[0] = *c5_b_ds;
        c5_eml_li_find(chartInstance, *c5_b_s < c5_smin, c5_tmp_data,
                       c5_tmp_sizes);
        c5_m_loop_ub = c5_tmp_sizes[0] * c5_tmp_sizes[1] - 1;
        for (c5_i314 = 0; c5_i314 <= c5_m_loop_ub; c5_i314++) {
          c5_dv20[c5_tmp_data[c5_i314] - 1] = 0.0;
        }

        *c5_b_ds = c5_dv20[0];
        _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 76);
        c5_dv21[0] = *c5_b_s;
        c5_eml_li_find(chartInstance, *c5_b_s < c5_smin, c5_tmp_data,
                       c5_tmp_sizes);
        c5_n_loop_ub = c5_tmp_sizes[0] * c5_tmp_sizes[1] - 1;
        for (c5_i315 = 0; c5_i315 <= c5_n_loop_ub; c5_i315++) {
          c5_dv21[c5_tmp_data[c5_i315] - 1] = c5_smin;
        }

        *c5_b_s = c5_dv21[0];
      }
    }
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 80);
  for (c5_i316 = 0; c5_i316 < 13; c5_i316++) {
    c5_qmod[c5_i316] = c5_b_q[c5_i316];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 81);
  c5_qmod[0] = c5_sat(chartInstance, c5_qmod[0], -c5_Output.YawLimit,
                      c5_Output.YawLimit);
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 82);
  for (c5_i317 = 0; c5_i317 < 78; c5_i317++) {
    c5_c_a[c5_i317] = c5_jacob_h0[c5_i317];
  }

  for (c5_i318 = 0; c5_i318 < 13; c5_i318++) {
    c5_b_b[c5_i318] = c5_qmod[c5_i318];
  }

  c5_c_eml_scalar_eg(chartInstance);
  c5_c_eml_scalar_eg(chartInstance);
  for (c5_i319 = 0; c5_i319 < 6; c5_i319++) {
    c5_h0[c5_i319] = 0.0;
  }

  for (c5_i320 = 0; c5_i320 < 6; c5_i320++) {
    c5_h0[c5_i320] = 0.0;
  }

  for (c5_i321 = 0; c5_i321 < 6; c5_i321++) {
    c5_a[c5_i321] = c5_h0[c5_i321];
  }

  for (c5_i322 = 0; c5_i322 < 6; c5_i322++) {
    c5_h0[c5_i322] = c5_a[c5_i322];
  }

  c5_threshold(chartInstance);
  for (c5_i323 = 0; c5_i323 < 6; c5_i323++) {
    c5_a[c5_i323] = c5_h0[c5_i323];
  }

  for (c5_i324 = 0; c5_i324 < 6; c5_i324++) {
    c5_h0[c5_i324] = c5_a[c5_i324];
  }

  for (c5_i325 = 0; c5_i325 < 6; c5_i325++) {
    c5_h0[c5_i325] = 0.0;
    c5_i326 = 0;
    for (c5_i327 = 0; c5_i327 < 13; c5_i327++) {
      c5_h0[c5_i325] += c5_c_a[c5_i326 + c5_i325] * c5_b_b[c5_i327];
      c5_i326 += 6;
    }
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 83);
  for (c5_i328 = 0; c5_i328 < 36; c5_i328++) {
    c5_b_h_alpha[c5_i328] = c5_h_alpha[c5_i328];
  }

  c5_bezierv(chartInstance, c5_b_h_alpha, *c5_b_s, c5_dv24);
  for (c5_i329 = 0; c5_i329 < 6; c5_i329++) {
    c5_b_hd[c5_i329] = c5_dv24[c5_i329];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 84);
  for (c5_i330 = 0; c5_i330 < 36; c5_i330++) {
    c5_c_h_alpha[c5_i330] = c5_h_alpha[c5_i330];
  }

  c5_beziervd(chartInstance, c5_c_h_alpha, *c5_b_s, c5_dv25);
  for (c5_i331 = 0; c5_i331 < 6; c5_i331++) {
    c5_jacob_hd[c5_i331] = c5_dv25[c5_i331];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 85);
  for (c5_i332 = 0; c5_i332 < 36; c5_i332++) {
    c5_d_h_alpha[c5_i332] = c5_h_alpha[c5_i332];
  }

  c5_bezierva(chartInstance, c5_d_h_alpha, *c5_b_s, c5_dv26);
  for (c5_i333 = 0; c5_i333 < 6; c5_i333++) {
    c5_jacob2_hd[c5_i333] = c5_dv26[c5_i333];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 86);
  for (c5_i334 = 0; c5_i334 < 6; c5_i334++) {
    c5_dhd[c5_i334] = c5_jacob_hd[c5_i334] * *c5_b_ds;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 88);
  for (c5_i335 = 0; c5_i335 < 6; c5_i335++) {
    c5_a[c5_i335] = c5_jacob_hd[c5_i335];
  }

  for (c5_i336 = 0; c5_i336 < 13; c5_i336++) {
    c5_b_dsdq[c5_i336] = c5_dsdq[c5_i336];
  }

  for (c5_i337 = 0; c5_i337 < 6; c5_i337++) {
    c5_i338 = 0;
    for (c5_i339 = 0; c5_i339 < 13; c5_i339++) {
      c5_c_a[c5_i338 + c5_i337] = c5_a[c5_i337] * c5_b_dsdq[c5_i339];
      c5_i338 += 6;
    }
  }

  for (c5_i340 = 0; c5_i340 < 78; c5_i340++) {
    c5_jacob_h[c5_i340] = c5_jacob_h0[c5_i340] - c5_c_a[c5_i340];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 89);
  c5_d_ds = *c5_b_ds * *c5_b_ds;
  for (c5_i341 = 0; c5_i341 < 6; c5_i341++) {
    c5_jacob_jacobhdqdq[c5_i341] = -c5_jacob2_hd[c5_i341] * c5_d_ds;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 95);
  for (c5_i342 = 0; c5_i342 < 13; c5_i342++) {
    c5_b_dsdq[c5_i342] = c5_Output.Phi.cq[c5_i342];
  }

  for (c5_i343 = 0; c5_i343 < 13; c5_i343++) {
    c5_b_b[c5_i343] = c5_b_q[c5_i343];
  }

  c5_b_threshold(chartInstance);
  *c5_b_phi = 0.0;
  c5_eml_switch_helper(chartInstance);
  for (c5_c_k = 1; c5_c_k < 14; c5_c_k++) {
    c5_d_k = c5_c_k - 1;
    *c5_b_phi += c5_b_dsdq[c5_d_k] * c5_b_b[c5_d_k];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 96);
  for (c5_i344 = 0; c5_i344 < 13; c5_i344++) {
    c5_b_dsdq[c5_i344] = c5_Output.Phi.cq[c5_i344];
  }

  for (c5_i345 = 0; c5_i345 < 13; c5_i345++) {
    c5_b_b[c5_i345] = c5_b_dq[c5_i345];
  }

  c5_b_threshold(chartInstance);
  c5_dphi = 0.0;
  c5_eml_switch_helper(chartInstance);
  for (c5_e_k = 1; c5_e_k < 14; c5_e_k++) {
    c5_f_k = c5_e_k - 1;
    c5_dphi += c5_b_dsdq[c5_f_k] * c5_b_b[c5_f_k];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 98);
  for (c5_i346 = 0; c5_i346 < 20; c5_i346++) {
    c5_c_Output[c5_i346] = c5_Output.PhiAlpha[c5_i346];
  }

  c5_phid = c5_bezier(chartInstance, c5_c_Output, *c5_b_s);
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 99);
  c5_bezierd(chartInstance);
  c5_jacob_phid = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 100);
  c5_beziera(chartInstance);
  c5_jacob2_phid = 0.0;
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 102);
  *c5_b_r = *c5_b_phi - c5_phid;
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 103);
  *c5_dr = c5_dphi - 0.0 * *c5_b_ds;
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 104);
  c5_RSaturated = false;
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 105);
  if (CV_SCRIPT_IF(2, 8, c5_Output.SaturateR != 0.0)) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 106);
    if (CV_SCRIPT_IF(2, 9, CV_RELATIONAL_EVAL(14U, 2U, 7, *c5_b_r,
          c5_Output.RLimits[1], -1, 4U, *c5_b_r > c5_Output.RLimits[1]))) {
      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 107);
      *c5_b_r = c5_Output.RLimits[1];
      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 108);
      *c5_dr = 0.0;
      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 109);
      c5_RSaturated = true;
    } else {
      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 110);
      if (CV_SCRIPT_IF(2, 10, CV_RELATIONAL_EVAL(14U, 2U, 8, *c5_b_r,
            c5_Output.RLimits[0], -1, 2U, *c5_b_r < c5_Output.RLimits[0]))) {
        _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 111);
        *c5_b_r = c5_Output.RLimits[0];
        _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 112);
        *c5_dr = 0.0;
        _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 113);
        c5_RSaturated = true;
      }
    }
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 117);
  for (c5_i347 = 0; c5_i347 < 30; c5_i347++) {
    c5_d_Output[c5_i347] = c5_Output.HBarAlpha[c5_i347];
  }

  c5_polyv(chartInstance, c5_d_Output, *c5_b_r, rtInf, c5_dv27);
  for (c5_i348 = 0; c5_i348 < 6; c5_i348++) {
    c5_b_hdbar[c5_i348] = c5_dv27[c5_i348];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 118);
  if (CV_SCRIPT_IF(2, 11, CV_SCRIPT_MCDC(2, 0, !CV_SCRIPT_COND(2, 0,
         c5_RSaturated)))) {
    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 119);
    for (c5_i349 = 0; c5_i349 < 30; c5_i349++) {
      c5_e_Output[c5_i349] = c5_Output.HBarAlpha[c5_i349];
    }

    c5_polyvd(chartInstance, c5_e_Output, *c5_b_r, rtInf, c5_dv28);
    for (c5_i350 = 0; c5_i350 < 6; c5_i350++) {
      c5_jacob_hdbar[c5_i350] = c5_dv28[c5_i350];
    }

    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 120);
    for (c5_i351 = 0; c5_i351 < 30; c5_i351++) {
      c5_f_Output[c5_i351] = c5_Output.HBarAlpha[c5_i351];
    }

    c5_polyva(chartInstance, c5_f_Output, *c5_b_r, rtInf, c5_dv29);
    for (c5_i352 = 0; c5_i352 < 6; c5_i352++) {
      c5_jacob2_hdbar[c5_i352] = c5_dv29[c5_i352];
    }
  } else {
    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 122);
    for (c5_i353 = 0; c5_i353 < 6; c5_i353++) {
      c5_jacob_hdbar[c5_i353] = 0.0;
    }

    _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 123);
    for (c5_i354 = 0; c5_i354 < 6; c5_i354++) {
      c5_jacob2_hdbar[c5_i354] = 0.0;
    }
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 126);
  for (c5_i355 = 0; c5_i355 < 6; c5_i355++) {
    c5_c_hdbar[c5_i355] = c5_b_hdbar[c5_i355];
  }

  for (c5_i356 = 0; c5_i356 < 6; c5_i356++) {
    c5_g_Output[c5_i356] = c5_Output.HBarLimits[c5_i356];
  }

  for (c5_i357 = 0; c5_i357 < 6; c5_i357++) {
    c5_h_Output[c5_i357] = c5_Output.HBarLimits[c5_i357 + 6];
  }

  c5_b_sat(chartInstance, c5_c_hdbar, c5_g_Output, c5_h_Output, c5_dv30);
  for (c5_i358 = 0; c5_i358 < 6; c5_i358++) {
    c5_b_hdbar[c5_i358] = c5_dv30[c5_i358];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, MAX_int8_T);
  for (c5_i359 = 0; c5_i359 < 6; c5_i359++) {
    c5_bv0[c5_i359] = (c5_b_hdbar[c5_i359] == c5_Output.HBarLimits[c5_i359]);
  }

  for (c5_i360 = 0; c5_i360 < 6; c5_i360++) {
    c5_bv1[c5_i360] = (c5_b_hdbar[c5_i360] == c5_Output.HBarLimits[c5_i360 + 6]);
  }

  for (c5_i361 = 0; c5_i361 < 6; c5_i361++) {
    c5_idxsat[c5_i361] = (c5_bv0[c5_i361] || c5_bv1[c5_i361]);
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 128U);
  for (c5_i362 = 0; c5_i362 < 6; c5_i362++) {
    c5_b_idxsat[c5_i362] = c5_idxsat[c5_i362];
  }

  c5_b_eml_li_find(chartInstance, c5_b_idxsat, c5_b_tmp_data, &c5_b_tmp_sizes);
  c5_iv7[0] = c5_b_tmp_sizes;
  c5_o_loop_ub = c5_iv7[0] - 1;
  for (c5_i363 = 0; c5_i363 <= c5_o_loop_ub; c5_i363++) {
    c5_jacob_hdbar[c5_b_tmp_data[c5_i363] - 1] = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 129U);
  for (c5_i364 = 0; c5_i364 < 6; c5_i364++) {
    c5_c_idxsat[c5_i364] = c5_idxsat[c5_i364];
  }

  c5_b_eml_li_find(chartInstance, c5_c_idxsat, c5_b_tmp_data, &c5_b_tmp_sizes);
  c5_iv8[0] = c5_b_tmp_sizes;
  c5_p_loop_ub = c5_iv8[0] - 1;
  for (c5_i365 = 0; c5_i365 <= c5_p_loop_ub; c5_i365++) {
    c5_jacob2_hdbar[c5_b_tmp_data[c5_i365] - 1] = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 131U);
  for (c5_i366 = 0; c5_i366 < 6; c5_i366++) {
    c5_b_hd[c5_i366] += c5_b_hdbar[c5_i366];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 132U);
  for (c5_i367 = 0; c5_i367 < 13; c5_i367++) {
    c5_b_dsdq[c5_i367] = c5_dsdq[c5_i367];
  }

  for (c5_i368 = 0; c5_i368 < 13; c5_i368++) {
    c5_b_dsdq[c5_i368] *= 0.0;
  }

  for (c5_i369 = 0; c5_i369 < 6; c5_i369++) {
    c5_a[c5_i369] = c5_jacob_hdbar[c5_i369];
  }

  for (c5_i370 = 0; c5_i370 < 13; c5_i370++) {
    c5_b_dsdq[c5_i370] = c5_Output.Phi.cq[c5_i370] - c5_b_dsdq[c5_i370];
  }

  for (c5_i371 = 0; c5_i371 < 6; c5_i371++) {
    c5_i372 = 0;
    for (c5_i373 = 0; c5_i373 < 13; c5_i373++) {
      c5_c_a[c5_i372 + c5_i371] = c5_a[c5_i371] * c5_b_dsdq[c5_i373];
      c5_i372 += 6;
    }
  }

  for (c5_i374 = 0; c5_i374 < 78; c5_i374++) {
    c5_jacob_h[c5_i374] -= c5_c_a[c5_i374];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 133U);
  for (c5_i375 = 0; c5_i375 < 6; c5_i375++) {
    c5_a[c5_i375] = c5_jacob_hdbar[c5_i375];
  }

  for (c5_i376 = 0; c5_i376 < 6; c5_i376++) {
    c5_a[c5_i376] *= 0.0;
  }

  c5_c_b = c5_mpower(chartInstance, *c5_b_ds);
  for (c5_i377 = 0; c5_i377 < 6; c5_i377++) {
    c5_a[c5_i377] *= c5_c_b;
  }

  for (c5_i378 = 0; c5_i378 < 6; c5_i378++) {
    c5_d_a[c5_i378] = c5_jacob2_hdbar[c5_i378];
  }

  c5_d_b = (-0.0 * c5_mpower(chartInstance, *c5_b_ds) - c5_mpower(chartInstance,
             c5_dphi)) + 0.0 * c5_dphi * *c5_b_ds;
  for (c5_i379 = 0; c5_i379 < 6; c5_i379++) {
    c5_d_a[c5_i379] *= c5_d_b;
  }

  for (c5_i380 = 0; c5_i380 < 6; c5_i380++) {
    c5_jacob_jacobhdqdq[c5_i380] = (c5_jacob_jacobhdqdq[c5_i380] + c5_a[c5_i380])
      + c5_d_a[c5_i380];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 138U);
  for (c5_i381 = 0; c5_i381 < 6; c5_i381++) {
    c5_hd_min[c5_i381] = c5_dv31[c5_i381];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 139U);
  for (c5_i382 = 0; c5_i382 < 6; c5_i382++) {
    c5_hd_max[c5_i382] = c5_dv32[c5_i382];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 140U);
  for (c5_i383 = 0; c5_i383 < 78; c5_i383++) {
    c5_c_a[c5_i383] = c5_jacob_h0[c5_i383] - c5_T1[c5_i383];
  }

  for (c5_i384 = 0; c5_i384 < 13; c5_i384++) {
    c5_b_b[c5_i384] = c5_b_q[c5_i384];
  }

  c5_c_eml_scalar_eg(chartInstance);
  c5_c_eml_scalar_eg(chartInstance);
  for (c5_i385 = 0; c5_i385 < 6; c5_i385++) {
    c5_sat_correction[c5_i385] = 0.0;
  }

  for (c5_i386 = 0; c5_i386 < 6; c5_i386++) {
    c5_sat_correction[c5_i386] = 0.0;
  }

  for (c5_i387 = 0; c5_i387 < 6; c5_i387++) {
    c5_a[c5_i387] = c5_sat_correction[c5_i387];
  }

  for (c5_i388 = 0; c5_i388 < 6; c5_i388++) {
    c5_sat_correction[c5_i388] = c5_a[c5_i388];
  }

  c5_threshold(chartInstance);
  for (c5_i389 = 0; c5_i389 < 6; c5_i389++) {
    c5_a[c5_i389] = c5_sat_correction[c5_i389];
  }

  for (c5_i390 = 0; c5_i390 < 6; c5_i390++) {
    c5_sat_correction[c5_i390] = c5_a[c5_i390];
  }

  for (c5_i391 = 0; c5_i391 < 6; c5_i391++) {
    c5_sat_correction[c5_i391] = 0.0;
    c5_i392 = 0;
    for (c5_i393 = 0; c5_i393 < 13; c5_i393++) {
      c5_sat_correction[c5_i391] += c5_c_a[c5_i392 + c5_i391] * c5_b_b[c5_i393];
      c5_i392 += 6;
    }
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 141U);
  for (c5_i394 = 0; c5_i394 < 6; c5_i394++) {
    c5_c_hd[c5_i394] = c5_b_hd[c5_i394];
  }

  for (c5_i395 = 0; c5_i395 < 6; c5_i395++) {
    c5_b_hd_min[c5_i395] = c5_hd_min[c5_i395] + c5_sat_correction[c5_i395];
  }

  for (c5_i396 = 0; c5_i396 < 6; c5_i396++) {
    c5_b_hd_max[c5_i396] = c5_hd_max[c5_i396] + c5_sat_correction[c5_i396];
  }

  c5_b_sat(chartInstance, c5_c_hd, c5_b_hd_min, c5_b_hd_max, c5_dv33);
  for (c5_i397 = 0; c5_i397 < 6; c5_i397++) {
    c5_b_hd[c5_i397] = c5_dv33[c5_i397];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 142U);
  for (c5_i398 = 0; c5_i398 < 6; c5_i398++) {
    c5_bv0[c5_i398] = (c5_b_hd[c5_i398] == c5_hd_min[c5_i398] +
                       c5_sat_correction[c5_i398]);
  }

  for (c5_i399 = 0; c5_i399 < 6; c5_i399++) {
    c5_bv1[c5_i399] = (c5_b_hd[c5_i399] == c5_hd_max[c5_i399] +
                       c5_sat_correction[c5_i399]);
  }

  for (c5_i400 = 0; c5_i400 < 6; c5_i400++) {
    c5_idxsat[c5_i400] = (c5_bv0[c5_i400] || c5_bv1[c5_i400]);
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 143U);
  for (c5_i401 = 0; c5_i401 < 6; c5_i401++) {
    c5_d_idxsat[c5_i401] = c5_idxsat[c5_i401];
  }

  c5_b_eml_li_find(chartInstance, c5_d_idxsat, c5_b_tmp_data, &c5_b_tmp_sizes);
  c5_q_loop_ub = c5_b_tmp_sizes - 1;
  for (c5_i402 = 0; c5_i402 <= c5_q_loop_ub; c5_i402++) {
    c5_dhd[c5_b_tmp_data[c5_i402] - 1] = 0.0;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 144U);
  for (c5_i403 = 0; c5_i403 < 6; c5_i403++) {
    c5_e_idxsat[c5_i403] = c5_idxsat[c5_i403];
  }

  c5_b_eml_li_find(chartInstance, c5_e_idxsat, c5_b_tmp_data, &c5_b_tmp_sizes);
  for (c5_i404 = 0; c5_i404 < 6; c5_i404++) {
    c5_f_idxsat[c5_i404] = c5_idxsat[c5_i404];
  }

  c5_b_eml_li_find(chartInstance, c5_f_idxsat, c5_c_tmp_data, &c5_c_tmp_sizes);
  c5_e_tmp_sizes = c5_c_tmp_sizes;
  c5_r_loop_ub = c5_c_tmp_sizes - 1;
  for (c5_i405 = 0; c5_i405 <= c5_r_loop_ub; c5_i405++) {
    c5_e_tmp_data[c5_i405] = c5_jacob_h0[c5_c_tmp_data[c5_i405] - 1];
  }

  _SFD_SIZE_EQ_CHECK_1D(c5_b_tmp_sizes, c5_e_tmp_sizes);
  c5_s_loop_ub = c5_e_tmp_sizes - 1;
  for (c5_i406 = 0; c5_i406 <= c5_s_loop_ub; c5_i406++) {
    c5_jacob_h[c5_b_tmp_data[c5_i406] - 1] = c5_e_tmp_data[c5_i406];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 147U);
  for (c5_i407 = 0; c5_i407 < 6; c5_i407++) {
    c5_b_y[c5_i407] = c5_h0[c5_i407] - c5_b_hd[c5_i407];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 148U);
  for (c5_i408 = 0; c5_i408 < 78; c5_i408++) {
    c5_c_a[c5_i408] = c5_jacob_h0[c5_i408];
  }

  for (c5_i409 = 0; c5_i409 < 13; c5_i409++) {
    c5_b_b[c5_i409] = c5_b_dq[c5_i409];
  }

  c5_c_eml_scalar_eg(chartInstance);
  c5_c_eml_scalar_eg(chartInstance);
  c5_threshold(chartInstance);
  for (c5_i410 = 0; c5_i410 < 6; c5_i410++) {
    c5_a[c5_i410] = 0.0;
    c5_i411 = 0;
    for (c5_i412 = 0; c5_i412 < 13; c5_i412++) {
      c5_a[c5_i410] += c5_c_a[c5_i411 + c5_i410] * c5_b_b[c5_i412];
      c5_i411 += 6;
    }
  }

  for (c5_i413 = 0; c5_i413 < 6; c5_i413++) {
    c5_b_dy[c5_i413] = c5_a[c5_i413] - c5_dhd[c5_i413];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 152U);
  for (c5_i414 = 0; c5_i414 < 30; c5_i414++) {
    c5_h_alpha_corr[c5_i414] = c5_Output.HAlphaCorrection[c5_i414];
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 153U);
  c5_s_corr_max = c5_Output.SMaxCorrection;
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 154U);
  guard1 = false;
  if (CV_SCRIPT_COND(2, 1, c5_Output.UseCorrection != 0.0)) {
    if (CV_SCRIPT_COND(2, 2, c5_any(chartInstance, *c5_b_s <= c5_s_corr_max))) {
      CV_SCRIPT_MCDC(2, 1, true);
      CV_SCRIPT_IF(2, 12, true);
      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 155U);
      for (c5_i415 = 0; c5_i415 < 30; c5_i415++) {
        c5_b_h_alpha_corr[c5_i415] = c5_h_alpha_corr[c5_i415];
      }

      c5_polyv(chartInstance, c5_b_h_alpha_corr, *c5_b_s, c5_s_corr_max, c5_a);
      for (c5_i416 = 0; c5_i416 < 6; c5_i416++) {
        c5_b_y[c5_i416] -= c5_a[c5_i416];
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 156U);
      for (c5_i417 = 0; c5_i417 < 30; c5_i417++) {
        c5_c_h_alpha_corr[c5_i417] = c5_h_alpha_corr[c5_i417];
      }

      c5_polyvd(chartInstance, c5_c_h_alpha_corr, *c5_b_s, c5_s_corr_max, c5_a);
      for (c5_i418 = 0; c5_i418 < 6; c5_i418++) {
        c5_b_dy[c5_i418] -= c5_a[c5_i418] * *c5_b_ds;
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 157U);
      for (c5_i419 = 0; c5_i419 < 30; c5_i419++) {
        c5_d_h_alpha_corr[c5_i419] = c5_h_alpha_corr[c5_i419];
      }

      c5_polyva(chartInstance, c5_d_h_alpha_corr, *c5_b_s, c5_s_corr_max, c5_a);
      c5_e_ds = *c5_b_ds * *c5_b_ds;
      for (c5_i420 = 0; c5_i420 < 6; c5_i420++) {
        c5_jacob_jacobhdqdq[c5_i420] += c5_a[c5_i420] * c5_e_ds;
      }

      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 158U);
      CV_RELATIONAL_EVAL(14U, 2U, 9, 1.0, 1.0, -1, 4U, 0);
      CV_SCRIPT_IF(2, 13, false);
      _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 161U);
      for (c5_i421 = 0; c5_i421 < 30; c5_i421++) {
        c5_e_h_alpha_corr[c5_i421] = c5_h_alpha_corr[c5_i421];
      }

      c5_polyvd(chartInstance, c5_e_h_alpha_corr, *c5_b_s, c5_s_corr_max, c5_a);
      for (c5_i422 = 0; c5_i422 < 13; c5_i422++) {
        c5_b_dsdq[c5_i422] = c5_dsdq[c5_i422];
      }

      for (c5_i423 = 0; c5_i423 < 6; c5_i423++) {
        c5_i424 = 0;
        for (c5_i425 = 0; c5_i425 < 13; c5_i425++) {
          c5_c_a[c5_i424 + c5_i423] = c5_a[c5_i423] * c5_b_dsdq[c5_i425];
          c5_i424 += 6;
        }
      }

      for (c5_i426 = 0; c5_i426 < 78; c5_i426++) {
        c5_jacob_h[c5_i426] -= c5_c_a[c5_i426];
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_SCRIPT_MCDC(2, 1, false);
    CV_SCRIPT_IF(2, 12, false);
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, -161);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c5_sat(SFc5_LibWalkingInstanceStruct *chartInstance, real_T c5_x,
                     real_T c5_lo, real_T c5_hi)
{
  real_T c5_b_y;
  uint32_T c5_debug_family_var_map[6];
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  real_T c5_varargin_1;
  real_T c5_varargin_2;
  real_T c5_b_varargin_2;
  real_T c5_varargin_3;
  real_T c5_b_x;
  real_T c5_c_y;
  real_T c5_c_x;
  real_T c5_d_y;
  real_T c5_xk;
  real_T c5_yk;
  real_T c5_d_x;
  real_T c5_e_y;
  real_T c5_minval;
  real_T c5_b_varargin_1;
  real_T c5_c_varargin_2;
  real_T c5_d_varargin_2;
  real_T c5_b_varargin_3;
  real_T c5_e_x;
  real_T c5_f_y;
  real_T c5_f_x;
  real_T c5_g_y;
  real_T c5_b_xk;
  real_T c5_b_yk;
  real_T c5_g_x;
  real_T c5_h_y;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c5_d_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_x, 2U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_lo, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_hi, 4U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_y, 5U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  CV_SCRIPT_FCN(2, 1);
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 168U);
  c5_varargin_1 = c5_x;
  c5_varargin_2 = c5_hi;
  c5_b_varargin_2 = c5_varargin_1;
  c5_varargin_3 = c5_varargin_2;
  c5_b_x = c5_b_varargin_2;
  c5_c_y = c5_varargin_3;
  c5_c_x = c5_b_x;
  c5_d_y = c5_c_y;
  c5_b_eml_scalar_eg(chartInstance);
  c5_xk = c5_c_x;
  c5_yk = c5_d_y;
  c5_d_x = c5_xk;
  c5_e_y = c5_yk;
  c5_b_eml_scalar_eg(chartInstance);
  c5_minval = muDoubleScalarMin(c5_d_x, c5_e_y);
  c5_b_varargin_1 = c5_lo;
  c5_c_varargin_2 = c5_minval;
  c5_d_varargin_2 = c5_b_varargin_1;
  c5_b_varargin_3 = c5_c_varargin_2;
  c5_e_x = c5_d_varargin_2;
  c5_f_y = c5_b_varargin_3;
  c5_f_x = c5_e_x;
  c5_g_y = c5_f_y;
  c5_b_eml_scalar_eg(chartInstance);
  c5_b_xk = c5_f_x;
  c5_b_yk = c5_g_y;
  c5_g_x = c5_b_xk;
  c5_h_y = c5_b_yk;
  c5_b_eml_scalar_eg(chartInstance);
  c5_b_y = muDoubleScalarMax(c5_g_x, c5_h_y);
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, -168);
  _SFD_SYMBOL_SCOPE_POP();
  return c5_b_y;
}

static void c5_bezierv(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_alpha[36], real_T c5_b_s, real_T c5_value[6])
{
  uint32_T c5_debug_family_var_map[15];
  real_T c5_n;
  real_T c5_m;
  real_T c5_ns;
  real_T c5_M;
  real_T c5_k[6];
  real_T c5_x[6];
  real_T c5_b_y[6];
  real_T c5_i;
  real_T c5_idx;
  real_T c5_j;
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i427;
  int32_T c5_i428;
  static real_T c5_dv34[6] = { 1.0, 5.0, 10.0, 10.0, 5.0, 1.0 };

  int32_T c5_i429;
  int32_T c5_i430;
  int32_T c5_b_i;
  int32_T c5_c_i;
  int32_T c5_b_j;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c5_e_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_n, 0U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m, 1U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ns, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_M, 3U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_k, 4U, c5_m_sf_marshallOut,
    c5_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_x, 5U, c5_m_sf_marshallOut,
    c5_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_y, 6U, c5_m_sf_marshallOut,
    c5_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_i, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_idx, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_j, 9U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 10U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 11U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_alpha, 12U, c5_g_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_s, 13U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_value, 14U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_SCRIPT_FCN(4, 0);
  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 2);
  c5_n = 6.0;
  c5_m = 6.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 3);
  c5_ns = 1.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 4);
  for (c5_i427 = 0; c5_i427 < 6; c5_i427++) {
    c5_value[c5_i427] = 0.0;
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 5);
  c5_M = 5.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 6);
  CV_RELATIONAL_EVAL(14U, 4U, 0, c5_M, 3.0, -1, 0U, c5_M == 3.0);
  CV_SCRIPT_IF(4, 0, false);
  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 8);
  CV_RELATIONAL_EVAL(14U, 4U, 1, c5_M, 4.0, -1, 0U, c5_M == 4.0);
  CV_SCRIPT_IF(4, 1, false);
  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 10);
  CV_RELATIONAL_EVAL(14U, 4U, 2, c5_M, 5.0, -1, 0U, c5_M == 5.0);
  CV_SCRIPT_IF(4, 2, true);
  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 11);
  for (c5_i428 = 0; c5_i428 < 6; c5_i428++) {
    c5_k[c5_i428] = c5_dv34[c5_i428];
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 24);
  for (c5_i429 = 0; c5_i429 < 6; c5_i429++) {
    c5_x[c5_i429] = 1.0;
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 25);
  for (c5_i430 = 0; c5_i430 < 6; c5_i430++) {
    c5_b_y[c5_i430] = 1.0;
  }

  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 26);
  c5_i = 1.0;
  c5_b_i = 0;
  while (c5_b_i < 5) {
    c5_i = 1.0 + (real_T)c5_b_i;
    CV_SCRIPT_FOR(4, 0, 1);
    _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 27);
    c5_x[(int32_T)(c5_i + 1.0) - 1] = c5_b_s * c5_x[(int32_T)c5_i - 1];
    _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 28);
    c5_b_y[(int32_T)(c5_i + 1.0) - 1] = (1.0 - c5_b_s) * c5_b_y[(int32_T)c5_i -
      1];
    c5_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(4, 0, 0);
  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 30);
  c5_idx = 1.0;
  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 31);
  c5_i = 1.0;
  c5_c_i = 0;
  while (c5_c_i < 6) {
    c5_i = 1.0 + (real_T)c5_c_i;
    CV_SCRIPT_FOR(4, 1, 1);
    _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 32);
    c5_value[(int32_T)c5_i - 1] = 0.0;
    _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 33);
    c5_j = 1.0;
    c5_b_j = 0;
    while (c5_b_j < 6) {
      c5_j = 1.0 + (real_T)c5_b_j;
      CV_SCRIPT_FOR(4, 2, 1);
      _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 34);
      c5_value[(int32_T)c5_i - 1] += c5_alpha[((int32_T)c5_i + 6 * ((int32_T)
        c5_j - 1)) - 1] * c5_k[(int32_T)c5_j - 1] * c5_x[(int32_T)c5_j - 1] *
        c5_b_y[(int32_T)(7.0 - c5_j) - 1];
      c5_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_SCRIPT_FOR(4, 2, 0);
    _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, 36);
    c5_idx = 1.0;
    c5_c_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(4, 1, 0);
  _SFD_SCRIPT_CALL(4U, chartInstance->c5_sfEvent, -36);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_beziervd(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_afra[36], real_T c5_b_s, real_T c5_value[6])
{
  uint32_T c5_debug_family_var_map[15];
  real_T c5_n;
  real_T c5_m;
  real_T c5_ns;
  real_T c5_M;
  real_T c5_k[5];
  real_T c5_x[5];
  real_T c5_b_y[5];
  real_T c5_i;
  real_T c5_idx;
  real_T c5_j;
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i431;
  int32_T c5_i432;
  static real_T c5_dv35[5] = { 5.0, 20.0, 30.0, 20.0, 5.0 };

  int32_T c5_i433;
  int32_T c5_i434;
  int32_T c5_b_i;
  int32_T c5_c_i;
  int32_T c5_b_j;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c5_f_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_n, 0U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m, 1U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ns, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_M, 3U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_k, 4U, c5_n_sf_marshallOut,
    c5_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_x, 5U, c5_n_sf_marshallOut,
    c5_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_y, 6U, c5_n_sf_marshallOut,
    c5_m_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_i, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_idx, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_j, 9U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 10U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 11U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_afra, 12U, c5_g_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_s, 13U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_value, 14U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_SCRIPT_FCN(5, 0);
  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 2);
  c5_n = 6.0;
  c5_m = 6.0;
  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 3);
  c5_ns = 1.0;
  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 4);
  for (c5_i431 = 0; c5_i431 < 6; c5_i431++) {
    c5_value[c5_i431] = 0.0;
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 5);
  c5_M = 5.0;
  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 6);
  CV_RELATIONAL_EVAL(14U, 5U, 0, c5_M, 3.0, -1, 0U, c5_M == 3.0);
  CV_SCRIPT_IF(5, 0, false);
  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 8);
  CV_RELATIONAL_EVAL(14U, 5U, 1, c5_M, 4.0, -1, 0U, c5_M == 4.0);
  CV_SCRIPT_IF(5, 1, false);
  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 10);
  CV_RELATIONAL_EVAL(14U, 5U, 2, c5_M, 5.0, -1, 0U, c5_M == 5.0);
  CV_SCRIPT_IF(5, 2, true);
  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 11);
  for (c5_i432 = 0; c5_i432 < 5; c5_i432++) {
    c5_k[c5_i432] = c5_dv35[c5_i432];
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 24);
  for (c5_i433 = 0; c5_i433 < 5; c5_i433++) {
    c5_x[c5_i433] = 1.0;
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 25);
  for (c5_i434 = 0; c5_i434 < 5; c5_i434++) {
    c5_b_y[c5_i434] = 1.0;
  }

  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 26);
  c5_i = 1.0;
  c5_b_i = 0;
  while (c5_b_i < 4) {
    c5_i = 1.0 + (real_T)c5_b_i;
    CV_SCRIPT_FOR(5, 0, 1);
    _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 27);
    c5_x[(int32_T)(c5_i + 1.0) - 1] = c5_b_s * c5_x[(int32_T)c5_i - 1];
    _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 28);
    c5_b_y[(int32_T)(c5_i + 1.0) - 1] = (1.0 - c5_b_s) * c5_b_y[(int32_T)c5_i -
      1];
    c5_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(5, 0, 0);
  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 30);
  c5_idx = 1.0;
  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 31);
  c5_i = 1.0;
  c5_c_i = 0;
  while (c5_c_i < 6) {
    c5_i = 1.0 + (real_T)c5_c_i;
    CV_SCRIPT_FOR(5, 1, 1);
    _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 32);
    c5_value[(int32_T)c5_i - 1] = 0.0;
    _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 33);
    c5_j = 1.0;
    c5_b_j = 0;
    while (c5_b_j < 5) {
      c5_j = 1.0 + (real_T)c5_b_j;
      CV_SCRIPT_FOR(5, 2, 1);
      _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 34);
      c5_value[(int32_T)c5_i - 1] += (c5_afra[((int32_T)c5_i + 6 * ((int32_T)
        (c5_j + 1.0) - 1)) - 1] - c5_afra[((int32_T)c5_i + 6 * ((int32_T)c5_j -
        1)) - 1]) * c5_k[(int32_T)c5_j - 1] * c5_x[(int32_T)c5_j - 1] * c5_b_y
        [(int32_T)(6.0 - c5_j) - 1];
      c5_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_SCRIPT_FOR(5, 2, 0);
    _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, 36);
    c5_idx = 1.0;
    c5_c_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(5, 1, 0);
  _SFD_SCRIPT_CALL(5U, chartInstance->c5_sfEvent, -36);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_bezierva(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_alpha[36], real_T c5_b_s, real_T c5_value[6])
{
  uint32_T c5_debug_family_var_map[15];
  real_T c5_n;
  real_T c5_m;
  real_T c5_ns;
  real_T c5_M;
  real_T c5_k[4];
  real_T c5_x[4];
  real_T c5_b_y[4];
  real_T c5_i;
  real_T c5_idx;
  real_T c5_j;
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i435;
  int32_T c5_i436;
  static real_T c5_dv36[4] = { 20.0, 60.0, 60.0, 20.0 };

  int32_T c5_i437;
  int32_T c5_i438;
  int32_T c5_b_i;
  int32_T c5_c_i;
  int32_T c5_b_j;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 15U, 15U, c5_g_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_n, 0U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m, 1U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_ns, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_M, 3U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_k, 4U, c5_i_sf_marshallOut,
    c5_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_x, 5U, c5_i_sf_marshallOut,
    c5_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_y, 6U, c5_i_sf_marshallOut,
    c5_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_i, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_idx, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_j, 9U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 10U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 11U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_alpha, 12U, c5_g_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_s, 13U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_value, 14U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_SCRIPT_FCN(6, 0);
  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 2);
  c5_n = 6.0;
  c5_m = 6.0;
  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 3);
  c5_ns = 1.0;
  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 4);
  for (c5_i435 = 0; c5_i435 < 6; c5_i435++) {
    c5_value[c5_i435] = 0.0;
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 5);
  c5_M = 5.0;
  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 6);
  CV_RELATIONAL_EVAL(14U, 6U, 0, c5_M, 3.0, -1, 0U, c5_M == 3.0);
  CV_SCRIPT_IF(6, 0, false);
  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 8);
  CV_RELATIONAL_EVAL(14U, 6U, 1, c5_M, 4.0, -1, 0U, c5_M == 4.0);
  CV_SCRIPT_IF(6, 1, false);
  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 10);
  CV_RELATIONAL_EVAL(14U, 6U, 2, c5_M, 5.0, -1, 0U, c5_M == 5.0);
  CV_SCRIPT_IF(6, 2, true);
  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 11);
  for (c5_i436 = 0; c5_i436 < 4; c5_i436++) {
    c5_k[c5_i436] = c5_dv36[c5_i436];
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 24);
  for (c5_i437 = 0; c5_i437 < 4; c5_i437++) {
    c5_x[c5_i437] = 1.0;
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 25);
  for (c5_i438 = 0; c5_i438 < 4; c5_i438++) {
    c5_b_y[c5_i438] = 1.0;
  }

  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 26);
  c5_i = 1.0;
  c5_b_i = 0;
  while (c5_b_i < 3) {
    c5_i = 1.0 + (real_T)c5_b_i;
    CV_SCRIPT_FOR(6, 0, 1);
    _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 27);
    c5_x[(int32_T)(c5_i + 1.0) - 1] = c5_b_s * c5_x[(int32_T)c5_i - 1];
    _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 28);
    c5_b_y[(int32_T)(c5_i + 1.0) - 1] = (1.0 - c5_b_s) * c5_b_y[(int32_T)c5_i -
      1];
    c5_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(6, 0, 0);
  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 30);
  c5_idx = 1.0;
  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 31);
  c5_i = 1.0;
  c5_c_i = 0;
  while (c5_c_i < 6) {
    c5_i = 1.0 + (real_T)c5_c_i;
    CV_SCRIPT_FOR(6, 1, 1);
    _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 32);
    c5_value[(int32_T)c5_i - 1] = 0.0;
    _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 33);
    c5_j = 1.0;
    c5_b_j = 0;
    while (c5_b_j < 4) {
      c5_j = 1.0 + (real_T)c5_b_j;
      CV_SCRIPT_FOR(6, 2, 1);
      _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 34);
      c5_value[(int32_T)c5_i - 1] += ((c5_alpha[((int32_T)c5_i + 6 * ((int32_T)
        (c5_j + 2.0) - 1)) - 1] - 2.0 * c5_alpha[((int32_T)c5_i + 6 * ((int32_T)
        (c5_j + 1.0) - 1)) - 1]) + c5_alpha[((int32_T)c5_i + 6 * ((int32_T)c5_j
        - 1)) - 1]) * c5_k[(int32_T)c5_j - 1] * c5_x[(int32_T)c5_j - 1] *
        c5_b_y[(int32_T)(5.0 - c5_j) - 1];
      c5_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_SCRIPT_FOR(6, 2, 0);
    _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, 36);
    c5_idx = 1.0;
    c5_c_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(6, 1, 0);
  _SFD_SCRIPT_CALL(6U, chartInstance->c5_sfEvent, -36);
  _SFD_SYMBOL_SCOPE_POP();
}

static real_T c5_bezier(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_afra[20], real_T c5_b_s)
{
  real_T c5_value;
  uint32_T c5_debug_family_var_map[13];
  real_T c5_n;
  real_T c5_m;
  real_T c5_M;
  real_T c5_k[20];
  real_T c5_x[20];
  real_T c5_b_y[20];
  real_T c5_i;
  real_T c5_j;
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i439;
  static real_T c5_dv37[20] = { 1.0, 19.0, 171.0, 969.0, 3876.0, 11628.0,
    27132.0, 50388.0, 75582.0, 92378.0, 92378.0, 75582.0, 50388.0, 27132.0,
    11628.0, 3876.0, 969.0, 171.0, 19.0, 1.0 };

  int32_T c5_i440;
  int32_T c5_i441;
  int32_T c5_b_i;
  int32_T c5_b_j;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c5_h_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_n, 0U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m, 1U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_M, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_k, 3U, c5_o_sf_marshallOut,
    c5_n_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_x, 4U, c5_o_sf_marshallOut,
    c5_n_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_y, 5U, c5_o_sf_marshallOut,
    c5_n_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_i, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_j, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 9U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_afra, 10U, c5_o_sf_marshallOut,
    c5_n_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_s, 11U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_value, 12U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  CV_SCRIPT_FCN(7, 0);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 2);
  c5_n = 1.0;
  c5_m = 20.0;
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 3);
  c5_value = 0.0;
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 4);
  c5_M = 19.0;
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 5);
  CV_RELATIONAL_EVAL(14U, 7U, 0, c5_M, 3.0, -1, 0U, c5_M == 3.0);
  CV_SCRIPT_IF(7, 0, false);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 7);
  CV_RELATIONAL_EVAL(14U, 7U, 1, c5_M, 4.0, -1, 0U, c5_M == 4.0);
  CV_SCRIPT_IF(7, 1, false);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 9);
  CV_RELATIONAL_EVAL(14U, 7U, 2, c5_M, 5.0, -1, 0U, c5_M == 5.0);
  CV_SCRIPT_IF(7, 2, false);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 11);
  CV_RELATIONAL_EVAL(14U, 7U, 3, c5_M, 6.0, -1, 0U, c5_M == 6.0);
  CV_SCRIPT_IF(7, 3, false);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 13);
  CV_RELATIONAL_EVAL(14U, 7U, 4, c5_M, 7.0, -1, 0U, c5_M == 7.0);
  CV_SCRIPT_IF(7, 4, false);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 15);
  CV_RELATIONAL_EVAL(14U, 7U, 5, c5_M, 8.0, -1, 0U, c5_M == 8.0);
  CV_SCRIPT_IF(7, 5, false);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 17);
  CV_RELATIONAL_EVAL(14U, 7U, 6, c5_M, 9.0, -1, 0U, c5_M == 9.0);
  CV_SCRIPT_IF(7, 6, false);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 19);
  CV_RELATIONAL_EVAL(14U, 7U, 7, c5_M, 20.0, -1, 0U, c5_M == 20.0);
  CV_SCRIPT_IF(7, 7, false);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 24);
  for (c5_i439 = 0; c5_i439 < 20; c5_i439++) {
    c5_k[c5_i439] = c5_dv37[c5_i439];
  }

  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 27);
  for (c5_i440 = 0; c5_i440 < 20; c5_i440++) {
    c5_x[c5_i440] = 1.0;
  }

  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 28);
  for (c5_i441 = 0; c5_i441 < 20; c5_i441++) {
    c5_b_y[c5_i441] = 1.0;
  }

  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 29);
  c5_i = 1.0;
  c5_b_i = 0;
  while (c5_b_i < 19) {
    c5_i = 1.0 + (real_T)c5_b_i;
    CV_SCRIPT_FOR(7, 0, 1);
    _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 30);
    c5_x[(int32_T)(c5_i + 1.0) - 1] = c5_b_s * c5_x[(int32_T)c5_i - 1];
    _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 31);
    c5_b_y[(int32_T)(c5_i + 1.0) - 1] = (1.0 - c5_b_s) * c5_b_y[(int32_T)c5_i -
      1];
    c5_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(7, 0, 0);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 33);
  c5_i = 1.0;
  CV_SCRIPT_FOR(7, 1, 1);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 34);
  c5_value = 0.0;
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 35);
  c5_j = 1.0;
  c5_b_j = 0;
  while (c5_b_j < 20) {
    c5_j = 1.0 + (real_T)c5_b_j;
    CV_SCRIPT_FOR(7, 2, 1);
    _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 36);
    c5_value += c5_afra[(int32_T)c5_j - 1] * c5_k[(int32_T)c5_j - 1] * c5_x
      [(int32_T)c5_j - 1] * c5_b_y[(int32_T)(21.0 - c5_j) - 1];
    c5_b_j++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(7, 2, 0);
  CV_SCRIPT_FOR(7, 1, 0);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, -36);
  _SFD_SYMBOL_SCOPE_POP();
  return c5_value;
}

static void c5_bezierd(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[6];
  real_T c5_value;
  real_T c5_n;
  real_T c5_m;
  real_T c5_M;
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c5_i_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_value, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_n, 1U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_M, 3U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 4U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 5U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  CV_SCRIPT_FCN(9, 0);
  _SFD_SCRIPT_CALL(9U, chartInstance->c5_sfEvent, 2);
  c5_n = 1.0;
  c5_m = 20.0;
  _SFD_SCRIPT_CALL(9U, chartInstance->c5_sfEvent, 3);
  c5_value = 0.0;
  _SFD_SCRIPT_CALL(9U, chartInstance->c5_sfEvent, 4);
  c5_M = 19.0;
  _SFD_SCRIPT_CALL(9U, chartInstance->c5_sfEvent, 5);
  CV_RELATIONAL_EVAL(14U, 9U, 0, c5_M, 3.0, -1, 0U, c5_M == 3.0);
  CV_SCRIPT_IF(9, 0, false);
  _SFD_SCRIPT_CALL(9U, chartInstance->c5_sfEvent, 7);
  CV_RELATIONAL_EVAL(14U, 9U, 1, c5_M, 4.0, -1, 0U, c5_M == 4.0);
  CV_SCRIPT_IF(9, 1, false);
  _SFD_SCRIPT_CALL(9U, chartInstance->c5_sfEvent, 9);
  CV_RELATIONAL_EVAL(14U, 9U, 2, c5_M, 5.0, -1, 0U, c5_M == 5.0);
  CV_SCRIPT_IF(9, 2, false);
  _SFD_SCRIPT_CALL(9U, chartInstance->c5_sfEvent, 11);
  CV_RELATIONAL_EVAL(14U, 9U, 3, c5_M, 6.0, -1, 0U, c5_M == 6.0);
  CV_SCRIPT_IF(9, 3, false);
  _SFD_SCRIPT_CALL(9U, chartInstance->c5_sfEvent, 13);
  CV_RELATIONAL_EVAL(14U, 9U, 4, c5_M, 7.0, -1, 0U, c5_M == 7.0);
  CV_SCRIPT_IF(9, 4, false);
  _SFD_SCRIPT_CALL(9U, chartInstance->c5_sfEvent, 15);
  CV_RELATIONAL_EVAL(14U, 9U, 5, c5_M, 8.0, -1, 0U, c5_M == 8.0);
  CV_SCRIPT_IF(9, 5, false);
  _SFD_SCRIPT_CALL(9U, chartInstance->c5_sfEvent, 17);
  CV_RELATIONAL_EVAL(14U, 9U, 6, c5_M, 9.0, -1, 0U, c5_M == 9.0);
  CV_SCRIPT_IF(9, 6, false);
  _SFD_SCRIPT_CALL(9U, chartInstance->c5_sfEvent, 19);
  CV_RELATIONAL_EVAL(14U, 9U, 7, c5_M, 20.0, -1, 0U, c5_M == 20.0);
  CV_SCRIPT_IF(9, 7, false);
  _SFD_SCRIPT_CALL(9U, chartInstance->c5_sfEvent, 24);
  _SFD_SCRIPT_CALL(9U, chartInstance->c5_sfEvent, -36);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_beziera(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  uint32_T c5_debug_family_var_map[6];
  real_T c5_value;
  real_T c5_n;
  real_T c5_m;
  real_T c5_M;
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c5_j_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_value, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_n, 1U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_M, 3U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 4U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 5U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  CV_SCRIPT_FCN(10, 0);
  _SFD_SCRIPT_CALL(10U, chartInstance->c5_sfEvent, 2);
  c5_n = 1.0;
  c5_m = 20.0;
  _SFD_SCRIPT_CALL(10U, chartInstance->c5_sfEvent, 3);
  c5_value = 0.0;
  _SFD_SCRIPT_CALL(10U, chartInstance->c5_sfEvent, 4);
  c5_M = 19.0;
  _SFD_SCRIPT_CALL(10U, chartInstance->c5_sfEvent, 5);
  CV_RELATIONAL_EVAL(14U, 10U, 0, c5_M, 3.0, -1, 0U, c5_M == 3.0);
  CV_SCRIPT_IF(10, 0, false);
  _SFD_SCRIPT_CALL(10U, chartInstance->c5_sfEvent, 7);
  CV_RELATIONAL_EVAL(14U, 10U, 1, c5_M, 4.0, -1, 0U, c5_M == 4.0);
  CV_SCRIPT_IF(10, 1, false);
  _SFD_SCRIPT_CALL(10U, chartInstance->c5_sfEvent, 9);
  CV_RELATIONAL_EVAL(14U, 10U, 2, c5_M, 5.0, -1, 0U, c5_M == 5.0);
  CV_SCRIPT_IF(10, 2, false);
  _SFD_SCRIPT_CALL(10U, chartInstance->c5_sfEvent, 11);
  CV_RELATIONAL_EVAL(14U, 10U, 3, c5_M, 6.0, -1, 0U, c5_M == 6.0);
  CV_SCRIPT_IF(10, 3, false);
  _SFD_SCRIPT_CALL(10U, chartInstance->c5_sfEvent, 13);
  CV_RELATIONAL_EVAL(14U, 10U, 4, c5_M, 7.0, -1, 0U, c5_M == 7.0);
  CV_SCRIPT_IF(10, 4, false);
  _SFD_SCRIPT_CALL(10U, chartInstance->c5_sfEvent, 15);
  CV_RELATIONAL_EVAL(14U, 10U, 5, c5_M, 8.0, -1, 0U, c5_M == 8.0);
  CV_SCRIPT_IF(10, 5, false);
  _SFD_SCRIPT_CALL(10U, chartInstance->c5_sfEvent, 17);
  CV_RELATIONAL_EVAL(14U, 10U, 6, c5_M, 9.0, -1, 0U, c5_M == 9.0);
  CV_SCRIPT_IF(10, 6, false);
  _SFD_SCRIPT_CALL(10U, chartInstance->c5_sfEvent, 19);
  CV_RELATIONAL_EVAL(14U, 10U, 7, c5_M, 20.0, -1, 0U, c5_M == 20.0);
  CV_SCRIPT_IF(10, 7, false);
  _SFD_SCRIPT_CALL(10U, chartInstance->c5_sfEvent, 24);
  _SFD_SCRIPT_CALL(10U, chartInstance->c5_sfEvent, -36);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_polyv(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
                     c5_poly_cor[30], real_T c5_b_s, real_T c5_s_corr_max,
                     real_T c5_value[6])
{
  uint32_T c5_debug_family_var_map[11];
  real_T c5_a0[6];
  real_T c5_a1[6];
  real_T c5_a2[6];
  real_T c5_a3[6];
  real_T c5_a4[6];
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i442;
  int32_T c5_i443;
  int32_T c5_i444;
  int32_T c5_i445;
  int32_T c5_i446;
  int32_T c5_i447;
  real_T c5_c_s;
  int32_T c5_i448;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c5_k_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_a0, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_a1, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_a2, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_a3, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_a4, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 5U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_poly_cor, 7U, c5_p_sf_marshallOut,
    c5_o_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_s, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_s_corr_max, 9U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_value, 10U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_SCRIPT_FCN(11, 0);
  _SFD_SCRIPT_CALL(11U, chartInstance->c5_sfEvent, 2);
  CV_RELATIONAL_EVAL(14U, 11U, 0, 3.0, 3.0, -1, 2U, 0);
  CV_SCRIPT_IF(11, 0, false);
  _SFD_SCRIPT_CALL(11U, chartInstance->c5_sfEvent, 5);
  for (c5_i442 = 0; c5_i442 < 6; c5_i442++) {
    c5_a0[c5_i442] = c5_poly_cor[c5_i442];
  }

  _SFD_SCRIPT_CALL(11U, chartInstance->c5_sfEvent, 6);
  for (c5_i443 = 0; c5_i443 < 6; c5_i443++) {
    c5_a1[c5_i443] = c5_poly_cor[c5_i443 + 6];
  }

  _SFD_SCRIPT_CALL(11U, chartInstance->c5_sfEvent, 7);
  for (c5_i444 = 0; c5_i444 < 6; c5_i444++) {
    c5_a2[c5_i444] = c5_poly_cor[c5_i444 + 12];
  }

  _SFD_SCRIPT_CALL(11U, chartInstance->c5_sfEvent, 8);
  for (c5_i445 = 0; c5_i445 < 6; c5_i445++) {
    c5_a3[c5_i445] = c5_poly_cor[c5_i445 + 18];
  }

  _SFD_SCRIPT_CALL(11U, chartInstance->c5_sfEvent, 9);
  for (c5_i446 = 0; c5_i446 < 6; c5_i446++) {
    c5_a4[c5_i446] = c5_poly_cor[c5_i446 + 24];
  }

  _SFD_SCRIPT_CALL(11U, chartInstance->c5_sfEvent, 10);
  for (c5_i447 = 0; c5_i447 < 6; c5_i447++) {
    c5_value[c5_i447] = c5_a0[c5_i447] + c5_b_s * (c5_a1[c5_i447] + c5_b_s *
      (c5_a2[c5_i447] + c5_b_s * (c5_a3[c5_i447] + c5_b_s * c5_a4[c5_i447])));
  }

  _SFD_SCRIPT_CALL(11U, chartInstance->c5_sfEvent, 11);
  c5_c_s = (real_T)(c5_b_s <= c5_s_corr_max);
  for (c5_i448 = 0; c5_i448 < 6; c5_i448++) {
    c5_value[c5_i448] *= c5_c_s;
  }

  _SFD_SCRIPT_CALL(11U, chartInstance->c5_sfEvent, -11);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_polyvd(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
                      c5_poly_cor[30], real_T c5_b_s, real_T c5_s_corr_max,
                      real_T c5_value[6])
{
  uint32_T c5_debug_family_var_map[10];
  real_T c5_a1[6];
  real_T c5_a2[6];
  real_T c5_a3[6];
  real_T c5_a4[6];
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i449;
  int32_T c5_i450;
  int32_T c5_i451;
  int32_T c5_i452;
  int32_T c5_i453;
  real_T c5_b[6];
  int32_T c5_i454;
  int32_T c5_i455;
  real_T c5_b_b[6];
  int32_T c5_i456;
  real_T c5_d0;
  int32_T c5_i457;
  real_T c5_c_s;
  int32_T c5_i458;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 10U, 10U, c5_l_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_a1, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_a2, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_a3, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_a4, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 4U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 5U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_poly_cor, 6U, c5_p_sf_marshallOut,
    c5_o_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_s, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_s_corr_max, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_value, 9U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_SCRIPT_FCN(12, 0);
  _SFD_SCRIPT_CALL(12U, chartInstance->c5_sfEvent, 2);
  CV_RELATIONAL_EVAL(14U, 12U, 0, 3.0, 3.0, -1, 2U, 0);
  CV_SCRIPT_IF(12, 0, false);
  _SFD_SCRIPT_CALL(12U, chartInstance->c5_sfEvent, 5);
  for (c5_i449 = 0; c5_i449 < 6; c5_i449++) {
    c5_a1[c5_i449] = c5_poly_cor[c5_i449 + 6];
  }

  _SFD_SCRIPT_CALL(12U, chartInstance->c5_sfEvent, 6);
  for (c5_i450 = 0; c5_i450 < 6; c5_i450++) {
    c5_a2[c5_i450] = c5_poly_cor[c5_i450 + 12];
  }

  _SFD_SCRIPT_CALL(12U, chartInstance->c5_sfEvent, 7);
  for (c5_i451 = 0; c5_i451 < 6; c5_i451++) {
    c5_a3[c5_i451] = c5_poly_cor[c5_i451 + 18];
  }

  _SFD_SCRIPT_CALL(12U, chartInstance->c5_sfEvent, 8);
  for (c5_i452 = 0; c5_i452 < 6; c5_i452++) {
    c5_a4[c5_i452] = c5_poly_cor[c5_i452 + 24];
  }

  _SFD_SCRIPT_CALL(12U, chartInstance->c5_sfEvent, 9);
  for (c5_i453 = 0; c5_i453 < 6; c5_i453++) {
    c5_b[c5_i453] = c5_a2[c5_i453];
  }

  for (c5_i454 = 0; c5_i454 < 6; c5_i454++) {
    c5_b[c5_i454] *= 2.0;
  }

  for (c5_i455 = 0; c5_i455 < 6; c5_i455++) {
    c5_b_b[c5_i455] = c5_a3[c5_i455];
  }

  for (c5_i456 = 0; c5_i456 < 6; c5_i456++) {
    c5_b_b[c5_i456] *= 3.0;
  }

  c5_d0 = 4.0 * c5_b_s;
  for (c5_i457 = 0; c5_i457 < 6; c5_i457++) {
    c5_value[c5_i457] = c5_a1[c5_i457] + c5_b_s * (c5_b[c5_i457] + c5_b_s *
      (c5_b_b[c5_i457] + c5_d0 * c5_a4[c5_i457]));
  }

  _SFD_SCRIPT_CALL(12U, chartInstance->c5_sfEvent, 10);
  c5_c_s = (real_T)(c5_b_s <= c5_s_corr_max);
  for (c5_i458 = 0; c5_i458 < 6; c5_i458++) {
    c5_value[c5_i458] *= c5_c_s;
  }

  _SFD_SCRIPT_CALL(12U, chartInstance->c5_sfEvent, -10);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_polyva(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
                      c5_poly_cor[30], real_T c5_b_s, real_T c5_s_corr_max,
                      real_T c5_value[6])
{
  uint32_T c5_debug_family_var_map[9];
  real_T c5_a2[6];
  real_T c5_a3[6];
  real_T c5_a4[6];
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i459;
  int32_T c5_i460;
  int32_T c5_i461;
  int32_T c5_i462;
  real_T c5_b[6];
  int32_T c5_i463;
  int32_T c5_i464;
  real_T c5_b_b[6];
  int32_T c5_i465;
  real_T c5_d1;
  int32_T c5_i466;
  real_T c5_c_s;
  int32_T c5_i467;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 9U, 9U, c5_m_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_a2, 0U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_a3, 1U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_a4, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 3U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 4U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_poly_cor, 5U, c5_p_sf_marshallOut,
    c5_o_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_s, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_s_corr_max, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_value, 8U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_SCRIPT_FCN(13, 0);
  _SFD_SCRIPT_CALL(13U, chartInstance->c5_sfEvent, 2);
  CV_RELATIONAL_EVAL(14U, 13U, 0, 3.0, 3.0, -1, 2U, 0);
  CV_SCRIPT_IF(13, 0, false);
  _SFD_SCRIPT_CALL(13U, chartInstance->c5_sfEvent, 5);
  for (c5_i459 = 0; c5_i459 < 6; c5_i459++) {
    c5_a2[c5_i459] = c5_poly_cor[c5_i459 + 12];
  }

  _SFD_SCRIPT_CALL(13U, chartInstance->c5_sfEvent, 6);
  for (c5_i460 = 0; c5_i460 < 6; c5_i460++) {
    c5_a3[c5_i460] = c5_poly_cor[c5_i460 + 18];
  }

  _SFD_SCRIPT_CALL(13U, chartInstance->c5_sfEvent, 7);
  for (c5_i461 = 0; c5_i461 < 6; c5_i461++) {
    c5_a4[c5_i461] = c5_poly_cor[c5_i461 + 24];
  }

  _SFD_SCRIPT_CALL(13U, chartInstance->c5_sfEvent, 8);
  for (c5_i462 = 0; c5_i462 < 6; c5_i462++) {
    c5_b[c5_i462] = c5_a2[c5_i462];
  }

  for (c5_i463 = 0; c5_i463 < 6; c5_i463++) {
    c5_b[c5_i463] *= 2.0;
  }

  for (c5_i464 = 0; c5_i464 < 6; c5_i464++) {
    c5_b_b[c5_i464] = c5_a3[c5_i464];
  }

  for (c5_i465 = 0; c5_i465 < 6; c5_i465++) {
    c5_b_b[c5_i465] *= 6.0;
  }

  c5_d1 = 12.0 * c5_b_s;
  for (c5_i466 = 0; c5_i466 < 6; c5_i466++) {
    c5_value[c5_i466] = c5_b[c5_i466] + c5_b_s * (c5_b_b[c5_i466] + c5_d1 *
      c5_a4[c5_i466]);
  }

  _SFD_SCRIPT_CALL(13U, chartInstance->c5_sfEvent, 9);
  c5_c_s = (real_T)(c5_b_s <= c5_s_corr_max);
  for (c5_i467 = 0; c5_i467 < 6; c5_i467++) {
    c5_value[c5_i467] *= c5_c_s;
  }

  _SFD_SCRIPT_CALL(13U, chartInstance->c5_sfEvent, -9);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_b_sat(SFc5_LibWalkingInstanceStruct *chartInstance, real_T c5_x[6],
                     real_T c5_lo[6], real_T c5_hi[6], real_T c5_b_y[6])
{
  uint32_T c5_debug_family_var_map[6];
  real_T c5_nargin = 3.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i468;
  real_T c5_varargin_1[6];
  int32_T c5_i469;
  real_T c5_varargin_2[6];
  int32_T c5_k;
  int32_T c5_b_k;
  real_T c5_xk;
  real_T c5_yk;
  real_T c5_b_x;
  real_T c5_c_y;
  real_T c5_extremum;
  real_T c5_minval[6];
  int32_T c5_i470;
  int32_T c5_c_k;
  int32_T c5_d_k;
  real_T c5_b_xk;
  real_T c5_b_yk;
  real_T c5_c_x;
  real_T c5_d_y;
  real_T c5_b_extremum;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 6U, 6U, c5_n_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 0U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 1U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_x, 2U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_lo, 3U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_hi, 4U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_y, 5U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_SCRIPT_FCN(2, 1);
  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, 168U);
  for (c5_i468 = 0; c5_i468 < 6; c5_i468++) {
    c5_varargin_1[c5_i468] = c5_x[c5_i468];
  }

  for (c5_i469 = 0; c5_i469 < 6; c5_i469++) {
    c5_varargin_2[c5_i469] = c5_hi[c5_i469];
  }

  c5_d_eml_scalar_eg(chartInstance);
  c5_eml_switch_helper(chartInstance);
  for (c5_k = 1; c5_k < 7; c5_k++) {
    c5_b_k = c5_k - 1;
    c5_xk = c5_varargin_1[c5_b_k];
    c5_yk = c5_varargin_2[c5_b_k];
    c5_b_x = c5_xk;
    c5_c_y = c5_yk;
    c5_b_eml_scalar_eg(chartInstance);
    c5_extremum = muDoubleScalarMin(c5_b_x, c5_c_y);
    c5_minval[c5_b_k] = c5_extremum;
  }

  for (c5_i470 = 0; c5_i470 < 6; c5_i470++) {
    c5_varargin_1[c5_i470] = c5_lo[c5_i470];
  }

  c5_d_eml_scalar_eg(chartInstance);
  c5_eml_switch_helper(chartInstance);
  for (c5_c_k = 1; c5_c_k < 7; c5_c_k++) {
    c5_d_k = c5_c_k - 1;
    c5_b_xk = c5_varargin_1[c5_d_k];
    c5_b_yk = c5_minval[c5_d_k];
    c5_c_x = c5_b_xk;
    c5_d_y = c5_b_yk;
    c5_b_eml_scalar_eg(chartInstance);
    c5_b_extremum = muDoubleScalarMax(c5_c_x, c5_d_y);
    c5_b_y[c5_d_k] = c5_b_extremum;
  }

  _SFD_SCRIPT_CALL(2U, chartInstance->c5_sfEvent, -168);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c5_b_bezier(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_afra[36], real_T c5_b_s, real_T c5_value[6])
{
  uint32_T c5_debug_family_var_map[13];
  real_T c5_n;
  real_T c5_m;
  real_T c5_M;
  real_T c5_k[6];
  real_T c5_x[6];
  real_T c5_b_y[6];
  real_T c5_i;
  real_T c5_j;
  real_T c5_nargin = 2.0;
  real_T c5_nargout = 1.0;
  int32_T c5_i471;
  int32_T c5_i472;
  static real_T c5_dv38[6] = { 1.0, 5.0, 10.0, 10.0, 5.0, 1.0 };

  int32_T c5_i473;
  int32_T c5_i474;
  int32_T c5_b_i;
  int32_T c5_c_i;
  int32_T c5_b_j;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 13U, 13U, c5_p_debug_family_names,
    c5_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_n, 0U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_m, 1U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c5_M, 2U, c5_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_k, 3U, c5_m_sf_marshallOut,
    c5_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_x, 4U, c5_m_sf_marshallOut,
    c5_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_b_y, 5U, c5_m_sf_marshallOut,
    c5_l_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_i, 6U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_j, 7U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargin, 8U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_nargout, 9U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_afra, 10U, c5_g_sf_marshallOut,
    c5_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c5_b_s, 11U, c5_b_sf_marshallOut,
    c5_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c5_value, 12U, c5_sf_marshallOut,
    c5_sf_marshallIn);
  CV_SCRIPT_FCN(7, 0);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 2);
  c5_n = 6.0;
  c5_m = 6.0;
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 3);
  for (c5_i471 = 0; c5_i471 < 6; c5_i471++) {
    c5_value[c5_i471] = 0.0;
  }

  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 4);
  c5_M = 5.0;
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 5);
  CV_RELATIONAL_EVAL(14U, 7U, 0, c5_M, 3.0, -1, 0U, c5_M == 3.0);
  CV_SCRIPT_IF(7, 0, false);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 7);
  CV_RELATIONAL_EVAL(14U, 7U, 1, c5_M, 4.0, -1, 0U, c5_M == 4.0);
  CV_SCRIPT_IF(7, 1, false);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 9);
  CV_RELATIONAL_EVAL(14U, 7U, 2, c5_M, 5.0, -1, 0U, c5_M == 5.0);
  CV_SCRIPT_IF(7, 2, true);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 10);
  for (c5_i472 = 0; c5_i472 < 6; c5_i472++) {
    c5_k[c5_i472] = c5_dv38[c5_i472];
  }

  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 27);
  for (c5_i473 = 0; c5_i473 < 6; c5_i473++) {
    c5_x[c5_i473] = 1.0;
  }

  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 28);
  for (c5_i474 = 0; c5_i474 < 6; c5_i474++) {
    c5_b_y[c5_i474] = 1.0;
  }

  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 29);
  c5_i = 1.0;
  c5_b_i = 0;
  while (c5_b_i < 5) {
    c5_i = 1.0 + (real_T)c5_b_i;
    CV_SCRIPT_FOR(7, 0, 1);
    _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 30);
    c5_x[(int32_T)(c5_i + 1.0) - 1] = c5_b_s * c5_x[(int32_T)c5_i - 1];
    _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 31);
    c5_b_y[(int32_T)(c5_i + 1.0) - 1] = (1.0 - c5_b_s) * c5_b_y[(int32_T)c5_i -
      1];
    c5_b_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(7, 0, 0);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 33);
  c5_i = 1.0;
  c5_c_i = 0;
  while (c5_c_i < 6) {
    c5_i = 1.0 + (real_T)c5_c_i;
    CV_SCRIPT_FOR(7, 1, 1);
    _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 34);
    c5_value[(int32_T)c5_i - 1] = 0.0;
    _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 35);
    c5_j = 1.0;
    c5_b_j = 0;
    while (c5_b_j < 6) {
      c5_j = 1.0 + (real_T)c5_b_j;
      CV_SCRIPT_FOR(7, 2, 1);
      _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, 36);
      c5_value[(int32_T)c5_i - 1] += c5_afra[((int32_T)c5_i + 6 * ((int32_T)c5_j
        - 1)) - 1] * c5_k[(int32_T)c5_j - 1] * c5_x[(int32_T)c5_j - 1] * c5_b_y
        [(int32_T)(7.0 - c5_j) - 1];
      c5_b_j++;
      _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
    }

    CV_SCRIPT_FOR(7, 2, 0);
    c5_c_i++;
    _SF_MEX_LISTEN_FOR_CTRL_C(chartInstance->S);
  }

  CV_SCRIPT_FOR(7, 1, 0);
  _SFD_SCRIPT_CALL(7U, chartInstance->c5_sfEvent, -36);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c5_machineNumber, uint32_T
  c5_chartNumber, uint32_T c5_instanceNumber)
{
  (void)c5_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\FeedbackControl\\applyGaitTweaks2.m"));
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\FeedbackControl\\ATRIAS3D_ZD_Control06.m"));
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 2U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\FeedbackControl\\ATRIAS3D_ZD_Output03.m"));
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 3U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\Walking\\InPlace\\Rocking\\FeedbackControl\\ATRIAS3D_ZD_s6.m"));
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 4U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\shared_utils\\Polynomial\\bezierv.m"));
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 5U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\shared_utils\\Polynomial\\beziervd.m"));
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 6U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\shared_utils\\Polynomial\\bezierva.m"));
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 7U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\shared_utils\\Polynomial\\bezier.m"));
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 8U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\shared_utils\\Polynomial\\binom.m"));
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 9U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\shared_utils\\Polynomial\\bezierd.m"));
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 10U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\shared_utils\\Polynomial\\beziera.m"));
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 11U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\shared_utils\\Polynomial\\polyv.m"));
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 12U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\shared_utils\\Polynomial\\polyvd.m"));
  _SFD_SCRIPT_TRANSLATION(c5_chartNumber, c5_instanceNumber, 13U,
    sf_debug_get_script_id(
    "C:\\Users\\rosshart\\Desktop\\SVN\\MARLO_3D_Controllers\\shared_utils\\Polynomial\\polyva.m"));
}

static const mxArray *c5_sf_marshallOut(void *chartInstanceVoid, void *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i475;
  real_T c5_b_inData[6];
  int32_T c5_i476;
  real_T c5_b_u[6];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i475 = 0; c5_i475 < 6; c5_i475++) {
    c5_b_inData[c5_i475] = (*(real_T (*)[6])c5_inData)[c5_i475];
  }

  for (c5_i476 = 0; c5_i476 < 6; c5_i476++) {
    c5_b_u[c5_i476] = c5_b_inData[c5_i476];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u_pd, const char_T *c5_identifier, real_T c5_b_y[6])
{
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_u_pd), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_b_u_pd);
}

static void c5_b_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[6])
{
  real_T c5_dv39[6];
  int32_T c5_i477;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv39, 1, 0, 0U, 1, 0U, 1, 6);
  for (c5_i477 = 0; c5_i477 < 6; c5_i477++) {
    c5_b_y[c5_i477] = c5_dv39[c5_i477];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_u_pd;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[6];
  int32_T c5_i478;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_b_u_pd = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_u_pd), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_b_u_pd);
  for (c5_i478 = 0; c5_i478 < 6; c5_i478++) {
    (*(real_T (*)[6])c5_outData)[c5_i478] = c5_b_y[c5_i478];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_b_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  real_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(real_T *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static real_T c5_c_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_r, const char_T *c5_identifier)
{
  real_T c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_r), &c5_thisId);
  sf_mex_destroy(&c5_b_r);
  return c5_b_y;
}

static real_T c5_d_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  real_T c5_b_y;
  real_T c5_d2;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), &c5_d2, 1, 0, 0U, 0, 0U, 0);
  c5_b_y = c5_d2;
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_r;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_b_r = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_y = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_r), &c5_thisId);
  sf_mex_destroy(&c5_b_r);
  *(real_T *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_c_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  c5_ControlParamsBus c5_b_u;
  const mxArray *c5_b_y = NULL;
  c5_SupervisoryParamsBus c5_c_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  real_T c5_e_u;
  const mxArray *c5_e_y = NULL;
  real_T c5_f_u;
  const mxArray *c5_f_y = NULL;
  real_T c5_g_u;
  const mxArray *c5_g_y = NULL;
  real_T c5_h_u;
  const mxArray *c5_h_y = NULL;
  real_T c5_i_u;
  const mxArray *c5_i_y = NULL;
  real_T c5_j_u;
  const mxArray *c5_j_y = NULL;
  real_T c5_k_u;
  const mxArray *c5_k_y = NULL;
  real_T c5_l_u;
  const mxArray *c5_l_y = NULL;
  real_T c5_m_u;
  const mxArray *c5_m_y = NULL;
  real_T c5_n_u;
  const mxArray *c5_n_y = NULL;
  int32_T c5_i479;
  real_T c5_o_u[2];
  const mxArray *c5_o_y = NULL;
  real_T c5_p_u;
  const mxArray *c5_p_y = NULL;
  real_T c5_q_u;
  const mxArray *c5_q_y = NULL;
  int32_T c5_i480;
  real_T c5_r_u[6];
  const mxArray *c5_r_y = NULL;
  int32_T c5_i481;
  real_T c5_s_u[13];
  const mxArray *c5_s_y = NULL;
  int32_T c5_i482;
  real_T c5_t_u[5];
  const mxArray *c5_t_y = NULL;
  real_T c5_u_u;
  const mxArray *c5_u_y = NULL;
  real_T c5_v_u;
  const mxArray *c5_v_y = NULL;
  real_T c5_w_u;
  const mxArray *c5_w_y = NULL;
  real_T c5_x_u;
  const mxArray *c5_x_y = NULL;
  int32_T c5_i483;
  real_T c5_y_u[6];
  const mxArray *c5_y_y = NULL;
  int32_T c5_i484;
  real_T c5_ab_u[6];
  const mxArray *c5_ab_y = NULL;
  real_T c5_bb_u;
  const mxArray *c5_bb_y = NULL;
  real_T c5_cb_u;
  const mxArray *c5_cb_y = NULL;
  real_T c5_db_u;
  const mxArray *c5_db_y = NULL;
  real_T c5_eb_u;
  const mxArray *c5_eb_y = NULL;
  real_T c5_fb_u;
  const mxArray *c5_fb_y = NULL;
  real_T c5_gb_u;
  const mxArray *c5_gb_y = NULL;
  real_T c5_hb_u;
  const mxArray *c5_hb_y = NULL;
  real_T c5_ib_u;
  const mxArray *c5_ib_y = NULL;
  real_T c5_jb_u;
  const mxArray *c5_jb_y = NULL;
  real_T c5_kb_u;
  const mxArray *c5_kb_y = NULL;
  real_T c5_lb_u;
  const mxArray *c5_lb_y = NULL;
  real_T c5_mb_u;
  const mxArray *c5_mb_y = NULL;
  real_T c5_nb_u;
  const mxArray *c5_nb_y = NULL;
  real_T c5_ob_u;
  const mxArray *c5_ob_y = NULL;
  real_T c5_pb_u;
  const mxArray *c5_pb_y = NULL;
  real_T c5_qb_u;
  const mxArray *c5_qb_y = NULL;
  real_T c5_rb_u;
  const mxArray *c5_rb_y = NULL;
  real_T c5_sb_u;
  const mxArray *c5_sb_y = NULL;
  real_T c5_tb_u;
  const mxArray *c5_tb_y = NULL;
  real_T c5_ub_u;
  const mxArray *c5_ub_y = NULL;
  real_T c5_vb_u;
  const mxArray *c5_vb_y = NULL;
  int32_T c5_i485;
  real_T c5_wb_u[6];
  const mxArray *c5_wb_y = NULL;
  int32_T c5_i486;
  real_T c5_xb_u[6];
  const mxArray *c5_xb_y = NULL;
  real_T c5_yb_u;
  const mxArray *c5_yb_y = NULL;
  int32_T c5_i487;
  real_T c5_ac_u[6];
  const mxArray *c5_ac_y = NULL;
  int32_T c5_i488;
  real_T c5_bc_u[6];
  const mxArray *c5_bc_y = NULL;
  real_T c5_cc_u;
  const mxArray *c5_cc_y = NULL;
  int32_T c5_i489;
  real_T c5_dc_u[12];
  const mxArray *c5_dc_y = NULL;
  real_T c5_ec_u;
  const mxArray *c5_ec_y = NULL;
  c5_DiscreteParamsBus c5_fc_u;
  const mxArray *c5_fc_y = NULL;
  real_T c5_gc_u;
  const mxArray *c5_gc_y = NULL;
  real_T c5_hc_u;
  const mxArray *c5_hc_y = NULL;
  real_T c5_ic_u;
  const mxArray *c5_ic_y = NULL;
  real_T c5_jc_u;
  const mxArray *c5_jc_y = NULL;
  real_T c5_kc_u;
  const mxArray *c5_kc_y = NULL;
  real_T c5_lc_u;
  const mxArray *c5_lc_y = NULL;
  real_T c5_mc_u;
  const mxArray *c5_mc_y = NULL;
  real_T c5_nc_u;
  const mxArray *c5_nc_y = NULL;
  real_T c5_oc_u;
  const mxArray *c5_oc_y = NULL;
  real_T c5_pc_u;
  const mxArray *c5_pc_y = NULL;
  real_T c5_qc_u;
  const mxArray *c5_qc_y = NULL;
  c5_OutputParamsBus c5_rc_u;
  const mxArray *c5_rc_y = NULL;
  int32_T c5_i490;
  real_T c5_sc_u[78];
  const mxArray *c5_sc_y = NULL;
  int32_T c5_i491;
  real_T c5_tc_u[36];
  const mxArray *c5_tc_y = NULL;
  int32_T c5_i492;
  real_T c5_uc_u[2];
  const mxArray *c5_uc_y = NULL;
  c5_ThetaParamsBus c5_vc_u;
  const mxArray *c5_vc_y = NULL;
  real_T c5_wc_u;
  const mxArray *c5_wc_y = NULL;
  real_T c5_xc_u;
  const mxArray *c5_xc_y = NULL;
  int32_T c5_i493;
  real_T c5_yc_u[13];
  const mxArray *c5_yc_y = NULL;
  real_T c5_ad_u;
  const mxArray *c5_ad_y = NULL;
  int32_T c5_i494;
  real_T c5_bd_u[7];
  const mxArray *c5_bd_y = NULL;
  real_T c5_cd_u;
  const mxArray *c5_cd_y = NULL;
  int32_T c5_i495;
  real_T c5_dd_u[2];
  const mxArray *c5_dd_y = NULL;
  real_T c5_ed_u;
  const mxArray *c5_ed_y = NULL;
  real_T c5_fd_u;
  const mxArray *c5_fd_y = NULL;
  real_T c5_gd_u;
  const mxArray *c5_gd_y = NULL;
  int32_T c5_i496;
  real_T c5_hd_u[30];
  const mxArray *c5_hd_y = NULL;
  c5_PhiParamsBus c5_id_u;
  const mxArray *c5_id_y = NULL;
  real_T c5_jd_u;
  const mxArray *c5_jd_y = NULL;
  int32_T c5_i497;
  real_T c5_kd_u[13];
  const mxArray *c5_kd_y = NULL;
  int32_T c5_i498;
  real_T c5_ld_u[20];
  const mxArray *c5_ld_y = NULL;
  real_T c5_md_u;
  const mxArray *c5_md_y = NULL;
  int32_T c5_i499;
  real_T c5_nd_u[2];
  const mxArray *c5_nd_y = NULL;
  int32_T c5_i500;
  real_T c5_od_u[30];
  const mxArray *c5_od_y = NULL;
  int32_T c5_i501;
  real_T c5_pd_u[12];
  const mxArray *c5_pd_y = NULL;
  int32_T c5_i502;
  real_T c5_qd_u[36];
  const mxArray *c5_qd_y = NULL;
  real_T c5_rd_u;
  const mxArray *c5_rd_y = NULL;
  c5_FeedbackParamsBus c5_sd_u;
  const mxArray *c5_sd_y = NULL;
  int32_T c5_i503;
  real_T c5_td_u[6];
  const mxArray *c5_td_y = NULL;
  int32_T c5_i504;
  real_T c5_ud_u[6];
  const mxArray *c5_ud_y = NULL;
  int32_T c5_i505;
  real_T c5_vd_u[2];
  const mxArray *c5_vd_y = NULL;
  int32_T c5_i506;
  real_T c5_wd_u[2];
  const mxArray *c5_wd_y = NULL;
  real_T c5_xd_u;
  const mxArray *c5_xd_y = NULL;
  int32_T c5_i507;
  real_T c5_yd_u[2];
  const mxArray *c5_yd_y = NULL;
  int32_T c5_i508;
  real_T c5_ae_u[2];
  const mxArray *c5_ae_y = NULL;
  real_T c5_be_u;
  const mxArray *c5_be_y = NULL;
  real_T c5_ce_u;
  const mxArray *c5_ce_y = NULL;
  real_T c5_de_u;
  const mxArray *c5_de_y = NULL;
  real_T c5_ee_u;
  const mxArray *c5_ee_y = NULL;
  real_T c5_fe_u;
  const mxArray *c5_fe_y = NULL;
  real_T c5_ge_u;
  const mxArray *c5_ge_y = NULL;
  real_T c5_he_u;
  const mxArray *c5_he_y = NULL;
  real_T c5_ie_u;
  const mxArray *c5_ie_y = NULL;
  int32_T c5_i509;
  real_T c5_je_u[6];
  const mxArray *c5_je_y = NULL;
  real_T c5_ke_u;
  const mxArray *c5_ke_y = NULL;
  real_T c5_le_u;
  const mxArray *c5_le_y = NULL;
  real_T c5_me_u;
  const mxArray *c5_me_y = NULL;
  real_T c5_ne_u;
  const mxArray *c5_ne_y = NULL;
  real_T c5_oe_u;
  const mxArray *c5_oe_y = NULL;
  real_T c5_pe_u;
  const mxArray *c5_pe_y = NULL;
  real_T c5_qe_u;
  const mxArray *c5_qe_y = NULL;
  real_T c5_re_u;
  const mxArray *c5_re_y = NULL;
  real_T c5_se_u;
  const mxArray *c5_se_y = NULL;
  int32_T c5_i510;
  real_T c5_te_u[6];
  const mxArray *c5_te_y = NULL;
  real_T c5_ue_u;
  const mxArray *c5_ue_y = NULL;
  c5_SaturationParamsBus c5_ve_u;
  const mxArray *c5_ve_y = NULL;
  real_T c5_we_u;
  const mxArray *c5_we_y = NULL;
  int32_T c5_i511;
  real_T c5_xe_u[2];
  const mxArray *c5_xe_y = NULL;
  real_T c5_ye_u;
  const mxArray *c5_ye_y = NULL;
  real_T c5_af_u;
  const mxArray *c5_af_y = NULL;
  real_T c5_bf_u;
  const mxArray *c5_bf_y = NULL;
  real_T c5_cf_u;
  const mxArray *c5_cf_y = NULL;
  real_T c5_df_u;
  const mxArray *c5_df_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(c5_ControlParamsBus *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_c_u = c5_b_u.Supervisory;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_d_u = c5_c_u.EnableSwapOnKAAccel;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_d_y, "EnableSwapOnKAAccel", "EnableSwapOnKAAccel",
                  0);
  c5_e_u = c5_c_u.EnableSwapOnKASpring;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_e_y, "EnableSwapOnKASpring", "EnableSwapOnKASpring",
                  0);
  c5_f_u = c5_c_u.EnableBackwardSwap;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_f_y, "EnableBackwardSwap", "EnableBackwardSwap", 0);
  c5_g_u = c5_c_u.ImpactThresholdKAAccel;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_g_y, "ImpactThresholdKAAccel",
                  "ImpactThresholdKAAccel", 0);
  c5_h_u = c5_c_u.ImpactThresholdKASpringAbs;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_h_y, "ImpactThresholdKASpringAbs",
                  "ImpactThresholdKASpringAbs", 0);
  c5_i_u = c5_c_u.ImpactThresholdKASpringRel;
  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", &c5_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_i_y, "ImpactThresholdKASpringRel",
                  "ImpactThresholdKASpringRel", 0);
  c5_j_u = c5_c_u.SwapThresholdS;
  c5_j_y = NULL;
  sf_mex_assign(&c5_j_y, sf_mex_create("y", &c5_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_j_y, "SwapThresholdS", "SwapThresholdS", 0);
  c5_k_u = c5_c_u.AllowDoubleSupport;
  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_create("y", &c5_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_k_y, "AllowDoubleSupport", "AllowDoubleSupport", 0);
  c5_l_u = c5_c_u.UseGaitTransition;
  c5_l_y = NULL;
  sf_mex_assign(&c5_l_y, sf_mex_create("y", &c5_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_l_y, "UseGaitTransition", "UseGaitTransition", 0);
  c5_m_u = c5_c_u.NumTransitionSteps;
  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_create("y", &c5_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_m_y, "NumTransitionSteps", "NumTransitionSteps", 0);
  c5_n_u = c5_c_u.TransitionThresholdTorsoVel;
  c5_n_y = NULL;
  sf_mex_assign(&c5_n_y, sf_mex_create("y", &c5_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_n_y, "TransitionThresholdTorsoVel",
                  "TransitionThresholdTorsoVel", 0);
  for (c5_i479 = 0; c5_i479 < 2; c5_i479++) {
    c5_o_u[c5_i479] = c5_c_u.KAInjection[c5_i479];
  }

  c5_o_y = NULL;
  sf_mex_assign(&c5_o_y, sf_mex_create("y", c5_o_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_addfield(c5_c_y, c5_o_y, "KAInjection", "KAInjection", 0);
  c5_p_u = c5_c_u.MinDeltaThetaTransition;
  c5_p_y = NULL;
  sf_mex_assign(&c5_p_y, sf_mex_create("y", &c5_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_p_y, "MinDeltaThetaTransition",
                  "MinDeltaThetaTransition", 0);
  c5_q_u = c5_c_u.StartSecondGaitOnStep;
  c5_q_y = NULL;
  sf_mex_assign(&c5_q_y, sf_mex_create("y", &c5_q_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_q_y, "StartSecondGaitOnStep",
                  "StartSecondGaitOnStep", 0);
  for (c5_i480 = 0; c5_i480 < 6; c5_i480++) {
    c5_r_u[c5_i480] = c5_c_u.VBLAParams[c5_i480];
  }

  c5_r_y = NULL;
  sf_mex_assign(&c5_r_y, sf_mex_create("y", c5_r_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_addfield(c5_c_y, c5_r_y, "VBLAParams", "VBLAParams", 0);
  for (c5_i481 = 0; c5_i481 < 13; c5_i481++) {
    c5_s_u[c5_i481] = c5_c_u.BalanceParams[c5_i481];
  }

  c5_s_y = NULL;
  sf_mex_assign(&c5_s_y, sf_mex_create("y", c5_s_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_addfield(c5_c_y, c5_s_y, "BalanceParams", "BalanceParams", 0);
  for (c5_i482 = 0; c5_i482 < 5; c5_i482++) {
    c5_t_u[c5_i482] = c5_c_u.GaitTweaks[c5_i482];
  }

  c5_t_y = NULL;
  sf_mex_assign(&c5_t_y, sf_mex_create("y", c5_t_u, 0, 0U, 1U, 0U, 1, 5), false);
  sf_mex_addfield(c5_c_y, c5_t_y, "GaitTweaks", "GaitTweaks", 0);
  c5_u_u = c5_c_u.TStepInitial;
  c5_u_y = NULL;
  sf_mex_assign(&c5_u_y, sf_mex_create("y", &c5_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_u_y, "TStepInitial", "TStepInitial", 0);
  c5_v_u = c5_c_u.TMaxUpdate;
  c5_v_y = NULL;
  sf_mex_assign(&c5_v_y, sf_mex_create("y", &c5_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_v_y, "TMaxUpdate", "TMaxUpdate", 0);
  c5_w_u = c5_c_u.RunMode;
  c5_w_y = NULL;
  sf_mex_assign(&c5_w_y, sf_mex_create("y", &c5_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_w_y, "RunMode", "RunMode", 0);
  c5_x_u = c5_c_u.UseAbsoluteSwingLA;
  c5_x_y = NULL;
  sf_mex_assign(&c5_x_y, sf_mex_create("y", &c5_x_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_x_y, "UseAbsoluteSwingLA", "UseAbsoluteSwingLA", 0);
  for (c5_i483 = 0; c5_i483 < 6; c5_i483++) {
    c5_y_u[c5_i483] = c5_c_u.ErrorZeroFactor[c5_i483];
  }

  c5_y_y = NULL;
  sf_mex_assign(&c5_y_y, sf_mex_create("y", c5_y_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_addfield(c5_c_y, c5_y_y, "ErrorZeroFactor", "ErrorZeroFactor", 0);
  for (c5_i484 = 0; c5_i484 < 6; c5_i484++) {
    c5_ab_u[c5_i484] = c5_c_u.ErrorVelZeroFactor[c5_i484];
  }

  c5_ab_y = NULL;
  sf_mex_assign(&c5_ab_y, sf_mex_create("y", c5_ab_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c5_c_y, c5_ab_y, "ErrorVelZeroFactor", "ErrorVelZeroFactor", 0);
  c5_bb_u = c5_c_u.StanceLegInit;
  c5_bb_y = NULL;
  sf_mex_assign(&c5_bb_y, sf_mex_create("y", &c5_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_bb_y, "StanceLegInit", "StanceLegInit", 0);
  c5_cb_u = c5_c_u.ControllerModeInit;
  c5_cb_y = NULL;
  sf_mex_assign(&c5_cb_y, sf_mex_create("y", &c5_cb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_cb_y, "ControllerModeInit", "ControllerModeInit", 0);
  c5_db_u = c5_c_u.UsePosingControl;
  c5_db_y = NULL;
  sf_mex_assign(&c5_db_y, sf_mex_create("y", &c5_db_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_db_y, "UsePosingControl", "UsePosingControl", 0);
  c5_eb_u = c5_c_u.TPosing;
  c5_eb_y = NULL;
  sf_mex_assign(&c5_eb_y, sf_mex_create("y", &c5_eb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_eb_y, "TPosing", "TPosing", 0);
  c5_fb_u = c5_c_u.TorsoBackAngle;
  c5_fb_y = NULL;
  sf_mex_assign(&c5_fb_y, sf_mex_create("y", &c5_fb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_fb_y, "TorsoBackAngle", "TorsoBackAngle", 0);
  c5_gb_u = c5_c_u.TorsoBackOnStep;
  c5_gb_y = NULL;
  sf_mex_assign(&c5_gb_y, sf_mex_create("y", &c5_gb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_gb_y, "TorsoBackOnStep", "TorsoBackOnStep", 0);
  c5_hb_u = c5_c_u.EnergyControlGain;
  c5_hb_y = NULL;
  sf_mex_assign(&c5_hb_y, sf_mex_create("y", &c5_hb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_hb_y, "EnergyControlGain", "EnergyControlGain", 0);
  c5_ib_u = c5_c_u.EnergyControlPhi0;
  c5_ib_y = NULL;
  sf_mex_assign(&c5_ib_y, sf_mex_create("y", &c5_ib_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_ib_y, "EnergyControlPhi0", "EnergyControlPhi0", 0);
  c5_jb_u = c5_c_u.VelocityControlTorsoMax;
  c5_jb_y = NULL;
  sf_mex_assign(&c5_jb_y, sf_mex_create("y", &c5_jb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_jb_y, "VelocityControlTorsoMax",
                  "VelocityControlTorsoMax", 0);
  c5_kb_u = c5_c_u.VelocityControlTorsoMin;
  c5_kb_y = NULL;
  sf_mex_assign(&c5_kb_y, sf_mex_create("y", &c5_kb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_kb_y, "VelocityControlTorsoMin",
                  "VelocityControlTorsoMin", 0);
  c5_lb_u = c5_c_u.VelocityControlTorsoGain;
  c5_lb_y = NULL;
  sf_mex_assign(&c5_lb_y, sf_mex_create("y", &c5_lb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_lb_y, "VelocityControlTorsoGain",
                  "VelocityControlTorsoGain", 0);
  c5_mb_u = c5_c_u.VelocityControlTorsoV0;
  c5_mb_y = NULL;
  sf_mex_assign(&c5_mb_y, sf_mex_create("y", &c5_mb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_mb_y, "VelocityControlTorsoV0",
                  "VelocityControlTorsoV0", 0);
  c5_nb_u = c5_c_u.MinDeltaTheta;
  c5_nb_y = NULL;
  sf_mex_assign(&c5_nb_y, sf_mex_create("y", &c5_nb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_nb_y, "MinDeltaTheta", "MinDeltaTheta", 0);
  c5_ob_u = c5_c_u.Theta0;
  c5_ob_y = NULL;
  sf_mex_assign(&c5_ob_y, sf_mex_create("y", &c5_ob_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_ob_y, "Theta0", "Theta0", 0);
  c5_pb_u = c5_c_u.KThetaPlus;
  c5_pb_y = NULL;
  sf_mex_assign(&c5_pb_y, sf_mex_create("y", &c5_pb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_pb_y, "KThetaPlus", "KThetaPlus", 0);
  c5_qb_u = c5_c_u.KThetaMinus;
  c5_qb_y = NULL;
  sf_mex_assign(&c5_qb_y, sf_mex_create("y", &c5_qb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_qb_y, "KThetaMinus", "KThetaMinus", 0);
  c5_rb_u = c5_c_u.RollPhaseVelocityThresh;
  c5_rb_y = NULL;
  sf_mex_assign(&c5_rb_y, sf_mex_create("y", &c5_rb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_rb_y, "RollPhaseVelocityThresh",
                  "RollPhaseVelocityThresh", 0);
  c5_sb_u = c5_c_u.RollPhaseSThresh;
  c5_sb_y = NULL;
  sf_mex_assign(&c5_sb_y, sf_mex_create("y", &c5_sb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_sb_y, "RollPhaseSThresh", "RollPhaseSThresh", 0);
  c5_tb_u = c5_c_u.MaxError;
  c5_tb_y = NULL;
  sf_mex_assign(&c5_tb_y, sf_mex_create("y", &c5_tb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_tb_y, "MaxError", "MaxError", 0);
  c5_ub_u = c5_c_u.MaxErrorVel;
  c5_ub_y = NULL;
  sf_mex_assign(&c5_ub_y, sf_mex_create("y", &c5_ub_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_ub_y, "MaxErrorVel", "MaxErrorVel", 0);
  c5_vb_u = c5_c_u.MaxErrorCount;
  c5_vb_y = NULL;
  sf_mex_assign(&c5_vb_y, sf_mex_create("y", &c5_vb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_vb_y, "MaxErrorCount", "MaxErrorCount", 0);
  for (c5_i485 = 0; c5_i485 < 6; c5_i485++) {
    c5_wb_u[c5_i485] = c5_c_u.K1MidStanceUpdate[c5_i485];
  }

  c5_wb_y = NULL;
  sf_mex_assign(&c5_wb_y, sf_mex_create("y", c5_wb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c5_c_y, c5_wb_y, "K1MidStanceUpdate", "K1MidStanceUpdate", 0);
  for (c5_i486 = 0; c5_i486 < 6; c5_i486++) {
    c5_xb_u[c5_i486] = c5_c_u.K2MidStanceUpdate[c5_i486];
  }

  c5_xb_y = NULL;
  sf_mex_assign(&c5_xb_y, sf_mex_create("y", c5_xb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c5_c_y, c5_xb_y, "K2MidStanceUpdate", "K2MidStanceUpdate", 0);
  c5_yb_u = c5_c_u.EnableVelocityBasedUpdate;
  c5_yb_y = NULL;
  sf_mex_assign(&c5_yb_y, sf_mex_create("y", &c5_yb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_yb_y, "EnableVelocityBasedUpdate",
                  "EnableVelocityBasedUpdate", 0);
  for (c5_i487 = 0; c5_i487 < 6; c5_i487++) {
    c5_ac_u[c5_i487] = c5_c_u.VelocityBasedUpdateK1[c5_i487];
  }

  c5_ac_y = NULL;
  sf_mex_assign(&c5_ac_y, sf_mex_create("y", c5_ac_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c5_c_y, c5_ac_y, "VelocityBasedUpdateK1",
                  "VelocityBasedUpdateK1", 0);
  for (c5_i488 = 0; c5_i488 < 6; c5_i488++) {
    c5_bc_u[c5_i488] = c5_c_u.VelocityBasedUpdateK2[c5_i488];
  }

  c5_bc_y = NULL;
  sf_mex_assign(&c5_bc_y, sf_mex_create("y", c5_bc_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c5_c_y, c5_bc_y, "VelocityBasedUpdateK2",
                  "VelocityBasedUpdateK2", 0);
  c5_cc_u = c5_c_u.VelocityBasedUpdateDTheta0;
  c5_cc_y = NULL;
  sf_mex_assign(&c5_cc_y, sf_mex_create("y", &c5_cc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_cc_y, "VelocityBasedUpdateDTheta0",
                  "VelocityBasedUpdateDTheta0", 0);
  for (c5_i489 = 0; c5_i489 < 12; c5_i489++) {
    c5_dc_u[c5_i489] = c5_c_u.VelocityBasedUpdateLimits[c5_i489];
  }

  c5_dc_y = NULL;
  sf_mex_assign(&c5_dc_y, sf_mex_create("y", c5_dc_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c5_c_y, c5_dc_y, "VelocityBasedUpdateLimits",
                  "VelocityBasedUpdateLimits", 0);
  c5_ec_u = c5_c_u.DesiredYawOffset;
  c5_ec_y = NULL;
  sf_mex_assign(&c5_ec_y, sf_mex_create("y", &c5_ec_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_c_y, c5_ec_y, "DesiredYawOffset", "DesiredYawOffset", 0);
  sf_mex_addfield(c5_b_y, c5_c_y, "Supervisory", "Supervisory", 0);
  c5_fc_u = c5_b_u.Discrete;
  c5_fc_y = NULL;
  sf_mex_assign(&c5_fc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_gc_u = c5_fc_u.TLastUpdate;
  c5_gc_y = NULL;
  sf_mex_assign(&c5_gc_y, sf_mex_create("y", &c5_gc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_fc_y, c5_gc_y, "TLastUpdate", "TLastUpdate", 0);
  c5_hc_u = c5_fc_u.VelocityControlLADelta;
  c5_hc_y = NULL;
  sf_mex_assign(&c5_hc_y, sf_mex_create("y", &c5_hc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_fc_y, c5_hc_y, "VelocityControlLADelta",
                  "VelocityControlLADelta", 0);
  c5_ic_u = c5_fc_u.VelocityControlTorsoDelta;
  c5_ic_y = NULL;
  sf_mex_assign(&c5_ic_y, sf_mex_create("y", &c5_ic_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_fc_y, c5_ic_y, "VelocityControlTorsoDelta",
                  "VelocityControlTorsoDelta", 0);
  c5_jc_u = c5_fc_u.VelocityControlHipDistCur;
  c5_jc_y = NULL;
  sf_mex_assign(&c5_jc_y, sf_mex_create("y", &c5_jc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_fc_y, c5_jc_y, "VelocityControlHipDistCur",
                  "VelocityControlHipDistCur", 0);
  c5_kc_u = c5_fc_u.VelocityControlHipDistPrev;
  c5_kc_y = NULL;
  sf_mex_assign(&c5_kc_y, sf_mex_create("y", &c5_kc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_fc_y, c5_kc_y, "VelocityControlHipDistPrev",
                  "VelocityControlHipDistPrev", 0);
  c5_lc_u = c5_fc_u.VirtualSpringMode;
  c5_lc_y = NULL;
  sf_mex_assign(&c5_lc_y, sf_mex_create("y", &c5_lc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_fc_y, c5_lc_y, "VirtualSpringMode", "VirtualSpringMode", 0);
  c5_mc_u = c5_fc_u.VirtualSpringStiffness;
  c5_mc_y = NULL;
  sf_mex_assign(&c5_mc_y, sf_mex_create("y", &c5_mc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_fc_y, c5_mc_y, "VirtualSpringStiffness",
                  "VirtualSpringStiffness", 0);
  c5_nc_u = c5_fc_u.VirtualSpringDamping;
  c5_nc_y = NULL;
  sf_mex_assign(&c5_nc_y, sf_mex_create("y", &c5_nc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_fc_y, c5_nc_y, "VirtualSpringDamping",
                  "VirtualSpringDamping", 0);
  c5_oc_u = c5_fc_u.VirtualSpringModAmplitude;
  c5_oc_y = NULL;
  sf_mex_assign(&c5_oc_y, sf_mex_create("y", &c5_oc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_fc_y, c5_oc_y, "VirtualSpringModAmplitude",
                  "VirtualSpringModAmplitude", 0);
  c5_pc_u = c5_fc_u.VirtualSpringModRate;
  c5_pc_y = NULL;
  sf_mex_assign(&c5_pc_y, sf_mex_create("y", &c5_pc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_fc_y, c5_pc_y, "VirtualSpringModRate",
                  "VirtualSpringModRate", 0);
  c5_qc_u = c5_fc_u.VirtualSpringRestPos;
  c5_qc_y = NULL;
  sf_mex_assign(&c5_qc_y, sf_mex_create("y", &c5_qc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_fc_y, c5_qc_y, "VirtualSpringRestPos",
                  "VirtualSpringRestPos", 0);
  sf_mex_addfield(c5_b_y, c5_fc_y, "Discrete", "Discrete", 0);
  c5_rc_u = c5_b_u.Output;
  c5_rc_y = NULL;
  sf_mex_assign(&c5_rc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c5_i490 = 0; c5_i490 < 78; c5_i490++) {
    c5_sc_u[c5_i490] = c5_rc_u.H0[c5_i490];
  }

  c5_sc_y = NULL;
  sf_mex_assign(&c5_sc_y, sf_mex_create("y", c5_sc_u, 0, 0U, 1U, 0U, 2, 6, 13),
                false);
  sf_mex_addfield(c5_rc_y, c5_sc_y, "H0", "H0", 0);
  for (c5_i491 = 0; c5_i491 < 36; c5_i491++) {
    c5_tc_u[c5_i491] = c5_rc_u.HAlpha[c5_i491];
  }

  c5_tc_y = NULL;
  sf_mex_assign(&c5_tc_y, sf_mex_create("y", c5_tc_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c5_rc_y, c5_tc_y, "HAlpha", "HAlpha", 0);
  for (c5_i492 = 0; c5_i492 < 2; c5_i492++) {
    c5_uc_u[c5_i492] = c5_rc_u.ThetaLimits[c5_i492];
  }

  c5_uc_y = NULL;
  sf_mex_assign(&c5_uc_y, sf_mex_create("y", c5_uc_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c5_rc_y, c5_uc_y, "ThetaLimits", "ThetaLimits", 0);
  c5_vc_u = c5_rc_u.Theta;
  c5_vc_y = NULL;
  sf_mex_assign(&c5_vc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_wc_u = c5_vc_u.c0;
  c5_wc_y = NULL;
  sf_mex_assign(&c5_wc_y, sf_mex_create("y", &c5_wc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_vc_y, c5_wc_y, "c0", "c0", 0);
  c5_xc_u = c5_vc_u.ct;
  c5_xc_y = NULL;
  sf_mex_assign(&c5_xc_y, sf_mex_create("y", &c5_xc_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_vc_y, c5_xc_y, "ct", "ct", 0);
  for (c5_i493 = 0; c5_i493 < 13; c5_i493++) {
    c5_yc_u[c5_i493] = c5_vc_u.cq[c5_i493];
  }

  c5_yc_y = NULL;
  sf_mex_assign(&c5_yc_y, sf_mex_create("y", c5_yc_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c5_vc_y, c5_yc_y, "cq", "cq", 0);
  c5_ad_u = c5_vc_u.t0;
  c5_ad_y = NULL;
  sf_mex_assign(&c5_ad_y, sf_mex_create("y", &c5_ad_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_vc_y, c5_ad_y, "t0", "t0", 0);
  for (c5_i494 = 0; c5_i494 < 7; c5_i494++) {
    c5_bd_u[c5_i494] = c5_vc_u.cz[c5_i494];
  }

  c5_bd_y = NULL;
  sf_mex_assign(&c5_bd_y, sf_mex_create("y", c5_bd_u, 0, 0U, 1U, 0U, 2, 1, 7),
                false);
  sf_mex_addfield(c5_vc_y, c5_bd_y, "cz", "cz", 0);
  sf_mex_addfield(c5_rc_y, c5_vc_y, "Theta", "Theta", 0);
  c5_cd_u = c5_rc_u.SaturateS;
  c5_cd_y = NULL;
  sf_mex_assign(&c5_cd_y, sf_mex_create("y", &c5_cd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_rc_y, c5_cd_y, "SaturateS", "SaturateS", 0);
  for (c5_i495 = 0; c5_i495 < 2; c5_i495++) {
    c5_dd_u[c5_i495] = c5_rc_u.SLimits[c5_i495];
  }

  c5_dd_y = NULL;
  sf_mex_assign(&c5_dd_y, sf_mex_create("y", c5_dd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c5_rc_y, c5_dd_y, "SLimits", "SLimits", 0);
  c5_ed_u = c5_rc_u.EnforceIncreasingS;
  c5_ed_y = NULL;
  sf_mex_assign(&c5_ed_y, sf_mex_create("y", &c5_ed_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_rc_y, c5_ed_y, "EnforceIncreasingS", "EnforceIncreasingS",
                  0);
  c5_fd_u = c5_rc_u.UseCorrection;
  c5_fd_y = NULL;
  sf_mex_assign(&c5_fd_y, sf_mex_create("y", &c5_fd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_rc_y, c5_fd_y, "UseCorrection", "UseCorrection", 0);
  c5_gd_u = c5_rc_u.SMaxCorrection;
  c5_gd_y = NULL;
  sf_mex_assign(&c5_gd_y, sf_mex_create("y", &c5_gd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_rc_y, c5_gd_y, "SMaxCorrection", "SMaxCorrection", 0);
  for (c5_i496 = 0; c5_i496 < 30; c5_i496++) {
    c5_hd_u[c5_i496] = c5_rc_u.HAlphaCorrection[c5_i496];
  }

  c5_hd_y = NULL;
  sf_mex_assign(&c5_hd_y, sf_mex_create("y", c5_hd_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c5_rc_y, c5_hd_y, "HAlphaCorrection", "HAlphaCorrection", 0);
  c5_id_u = c5_rc_u.Phi;
  c5_id_y = NULL;
  sf_mex_assign(&c5_id_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_jd_u = c5_id_u.c0;
  c5_jd_y = NULL;
  sf_mex_assign(&c5_jd_y, sf_mex_create("y", &c5_jd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_id_y, c5_jd_y, "c0", "c0", 0);
  for (c5_i497 = 0; c5_i497 < 13; c5_i497++) {
    c5_kd_u[c5_i497] = c5_id_u.cq[c5_i497];
  }

  c5_kd_y = NULL;
  sf_mex_assign(&c5_kd_y, sf_mex_create("y", c5_kd_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c5_id_y, c5_kd_y, "cq", "cq", 0);
  sf_mex_addfield(c5_rc_y, c5_id_y, "Phi", "Phi", 0);
  for (c5_i498 = 0; c5_i498 < 20; c5_i498++) {
    c5_ld_u[c5_i498] = c5_rc_u.PhiAlpha[c5_i498];
  }

  c5_ld_y = NULL;
  sf_mex_assign(&c5_ld_y, sf_mex_create("y", c5_ld_u, 0, 0U, 1U, 0U, 2, 1, 20),
                false);
  sf_mex_addfield(c5_rc_y, c5_ld_y, "PhiAlpha", "PhiAlpha", 0);
  c5_md_u = c5_rc_u.SaturateR;
  c5_md_y = NULL;
  sf_mex_assign(&c5_md_y, sf_mex_create("y", &c5_md_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_rc_y, c5_md_y, "SaturateR", "SaturateR", 0);
  for (c5_i499 = 0; c5_i499 < 2; c5_i499++) {
    c5_nd_u[c5_i499] = c5_rc_u.RLimits[c5_i499];
  }

  c5_nd_y = NULL;
  sf_mex_assign(&c5_nd_y, sf_mex_create("y", c5_nd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c5_rc_y, c5_nd_y, "RLimits", "RLimits", 0);
  for (c5_i500 = 0; c5_i500 < 30; c5_i500++) {
    c5_od_u[c5_i500] = c5_rc_u.HBarAlpha[c5_i500];
  }

  c5_od_y = NULL;
  sf_mex_assign(&c5_od_y, sf_mex_create("y", c5_od_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c5_rc_y, c5_od_y, "HBarAlpha", "HBarAlpha", 0);
  for (c5_i501 = 0; c5_i501 < 12; c5_i501++) {
    c5_pd_u[c5_i501] = c5_rc_u.HBarLimits[c5_i501];
  }

  c5_pd_y = NULL;
  sf_mex_assign(&c5_pd_y, sf_mex_create("y", c5_pd_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c5_rc_y, c5_pd_y, "HBarLimits", "HBarLimits", 0);
  for (c5_i502 = 0; c5_i502 < 36; c5_i502++) {
    c5_qd_u[c5_i502] = c5_rc_u.HAlphaStar[c5_i502];
  }

  c5_qd_y = NULL;
  sf_mex_assign(&c5_qd_y, sf_mex_create("y", c5_qd_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c5_rc_y, c5_qd_y, "HAlphaStar", "HAlphaStar", 0);
  c5_rd_u = c5_rc_u.YawLimit;
  c5_rd_y = NULL;
  sf_mex_assign(&c5_rd_y, sf_mex_create("y", &c5_rd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_rc_y, c5_rd_y, "YawLimit", "YawLimit", 0);
  sf_mex_addfield(c5_b_y, c5_rc_y, "Output", "Output", 0);
  c5_sd_u = c5_b_u.Feedback;
  c5_sd_y = NULL;
  sf_mex_assign(&c5_sd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c5_i503 = 0; c5_i503 < 6; c5_i503++) {
    c5_td_u[c5_i503] = c5_sd_u.kp[c5_i503];
  }

  c5_td_y = NULL;
  sf_mex_assign(&c5_td_y, sf_mex_create("y", c5_td_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c5_sd_y, c5_td_y, "kp", "kp", 0);
  for (c5_i504 = 0; c5_i504 < 6; c5_i504++) {
    c5_ud_u[c5_i504] = c5_sd_u.kd[c5_i504];
  }

  c5_ud_y = NULL;
  sf_mex_assign(&c5_ud_y, sf_mex_create("y", c5_ud_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c5_sd_y, c5_ud_y, "kd", "kd", 0);
  for (c5_i505 = 0; c5_i505 < 2; c5_i505++) {
    c5_vd_u[c5_i505] = c5_sd_u.epsilon[c5_i505];
  }

  c5_vd_y = NULL;
  sf_mex_assign(&c5_vd_y, sf_mex_create("y", c5_vd_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c5_sd_y, c5_vd_y, "epsilon", "epsilon", 0);
  for (c5_i506 = 0; c5_i506 < 2; c5_i506++) {
    c5_wd_u[c5_i506] = c5_sd_u.kff_grav[c5_i506];
  }

  c5_wd_y = NULL;
  sf_mex_assign(&c5_wd_y, sf_mex_create("y", c5_wd_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c5_sd_y, c5_wd_y, "kff_grav", "kff_grav", 0);
  c5_xd_u = c5_sd_u.delta_grav;
  c5_xd_y = NULL;
  sf_mex_assign(&c5_xd_y, sf_mex_create("y", &c5_xd_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_xd_y, "delta_grav", "delta_grav", 0);
  for (c5_i507 = 0; c5_i507 < 2; c5_i507++) {
    c5_yd_u[c5_i507] = c5_sd_u.kff_decoup[c5_i507];
  }

  c5_yd_y = NULL;
  sf_mex_assign(&c5_yd_y, sf_mex_create("y", c5_yd_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c5_sd_y, c5_yd_y, "kff_decoup", "kff_decoup", 0);
  for (c5_i508 = 0; c5_i508 < 2; c5_i508++) {
    c5_ae_u[c5_i508] = c5_sd_u.kd_torso[c5_i508];
  }

  c5_ae_y = NULL;
  sf_mex_assign(&c5_ae_y, sf_mex_create("y", c5_ae_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c5_sd_y, c5_ae_y, "kd_torso", "kd_torso", 0);
  c5_be_u = c5_sd_u.kp_2dof;
  c5_be_y = NULL;
  sf_mex_assign(&c5_be_y, sf_mex_create("y", &c5_be_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_be_y, "kp_2dof", "kp_2dof", 0);
  c5_ce_u = c5_sd_u.kd_2dof;
  c5_ce_y = NULL;
  sf_mex_assign(&c5_ce_y, sf_mex_create("y", &c5_ce_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_ce_y, "kd_2dof", "kd_2dof", 0);
  c5_de_u = c5_sd_u.kpre_2dof;
  c5_de_y = NULL;
  sf_mex_assign(&c5_de_y, sf_mex_create("y", &c5_de_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_de_y, "kpre_2dof", "kpre_2dof", 0);
  c5_ee_u = c5_sd_u.kp_lat;
  c5_ee_y = NULL;
  sf_mex_assign(&c5_ee_y, sf_mex_create("y", &c5_ee_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_ee_y, "kp_lat", "kp_lat", 0);
  c5_fe_u = c5_sd_u.kd_lat;
  c5_fe_y = NULL;
  sf_mex_assign(&c5_fe_y, sf_mex_create("y", &c5_fe_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_fe_y, "kd_lat", "kd_lat", 0);
  c5_ge_u = c5_sd_u.q3d_min_lat;
  c5_ge_y = NULL;
  sf_mex_assign(&c5_ge_y, sf_mex_create("y", &c5_ge_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_ge_y, "q3d_min_lat", "q3d_min_lat", 0);
  c5_he_u = c5_sd_u.q3d_max_lat;
  c5_he_y = NULL;
  sf_mex_assign(&c5_he_y, sf_mex_create("y", &c5_he_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_he_y, "q3d_max_lat", "q3d_max_lat", 0);
  c5_ie_u = c5_sd_u.w_torso_lat;
  c5_ie_y = NULL;
  sf_mex_assign(&c5_ie_y, sf_mex_create("y", &c5_ie_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_ie_y, "w_torso_lat", "w_torso_lat", 0);
  for (c5_i509 = 0; c5_i509 < 6; c5_i509++) {
    c5_je_u[c5_i509] = c5_sd_u.u_ff[c5_i509];
  }

  c5_je_y = NULL;
  sf_mex_assign(&c5_je_y, sf_mex_create("y", c5_je_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c5_sd_y, c5_je_y, "u_ff", "u_ff", 0);
  c5_ke_u = c5_sd_u.LateralControlMode;
  c5_ke_y = NULL;
  sf_mex_assign(&c5_ke_y, sf_mex_create("y", &c5_ke_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_ke_y, "LateralControlMode", "LateralControlMode",
                  0);
  c5_le_u = c5_sd_u.DecouplingMode;
  c5_le_y = NULL;
  sf_mex_assign(&c5_le_y, sf_mex_create("y", &c5_le_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_le_y, "DecouplingMode", "DecouplingMode", 0);
  c5_me_u = c5_sd_u.Use2DOF;
  c5_me_y = NULL;
  sf_mex_assign(&c5_me_y, sf_mex_create("y", &c5_me_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_me_y, "Use2DOF", "Use2DOF", 0);
  c5_ne_u = c5_sd_u.UseDSGravComp;
  c5_ne_y = NULL;
  sf_mex_assign(&c5_ne_y, sf_mex_create("y", &c5_ne_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_ne_y, "UseDSGravComp", "UseDSGravComp", 0);
  c5_oe_u = c5_sd_u.lat_bias;
  c5_oe_y = NULL;
  sf_mex_assign(&c5_oe_y, sf_mex_create("y", &c5_oe_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_oe_y, "lat_bias", "lat_bias", 0);
  c5_pe_u = c5_sd_u.lat_bias2;
  c5_pe_y = NULL;
  sf_mex_assign(&c5_pe_y, sf_mex_create("y", &c5_pe_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_pe_y, "lat_bias2", "lat_bias2", 0);
  c5_qe_u = c5_sd_u.linkFeedback;
  c5_qe_y = NULL;
  sf_mex_assign(&c5_qe_y, sf_mex_create("y", &c5_qe_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_qe_y, "linkFeedback", "linkFeedback", 0);
  c5_re_u = c5_sd_u.RIO;
  c5_re_y = NULL;
  sf_mex_assign(&c5_re_y, sf_mex_create("y", &c5_re_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_re_y, "RIO", "RIO", 0);
  c5_se_u = c5_sd_u.SelectFeedforward;
  c5_se_y = NULL;
  sf_mex_assign(&c5_se_y, sf_mex_create("y", &c5_se_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_se_y, "SelectFeedforward", "SelectFeedforward", 0);
  for (c5_i510 = 0; c5_i510 < 6; c5_i510++) {
    c5_te_u[c5_i510] = c5_sd_u.FeedforwardGain[c5_i510];
  }

  c5_te_y = NULL;
  sf_mex_assign(&c5_te_y, sf_mex_create("y", c5_te_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c5_sd_y, c5_te_y, "FeedforwardGain", "FeedforwardGain", 0);
  c5_ue_u = c5_sd_u.EnableFeedforwardOnStep;
  c5_ue_y = NULL;
  sf_mex_assign(&c5_ue_y, sf_mex_create("y", &c5_ue_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_sd_y, c5_ue_y, "EnableFeedforwardOnStep",
                  "EnableFeedforwardOnStep", 0);
  sf_mex_addfield(c5_b_y, c5_sd_y, "Feedback", "Feedback", 0);
  c5_ve_u = c5_b_u.Saturation;
  c5_ve_y = NULL;
  sf_mex_assign(&c5_ve_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_we_u = c5_ve_u.UseQPSaturation;
  c5_we_y = NULL;
  sf_mex_assign(&c5_we_y, sf_mex_create("y", &c5_we_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_ve_y, c5_we_y, "UseQPSaturation", "UseQPSaturation", 0);
  for (c5_i511 = 0; c5_i511 < 2; c5_i511++) {
    c5_xe_u[c5_i511] = c5_ve_u.QPWeight[c5_i511];
  }

  c5_xe_y = NULL;
  sf_mex_assign(&c5_xe_y, sf_mex_create("y", c5_xe_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c5_ve_y, c5_xe_y, "QPWeight", "QPWeight", 0);
  c5_ye_u = c5_ve_u.UseKASaturation;
  c5_ye_y = NULL;
  sf_mex_assign(&c5_ye_y, sf_mex_create("y", &c5_ye_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_ve_y, c5_ye_y, "UseKASaturation", "UseKASaturation", 0);
  c5_af_u = c5_ve_u.KASaturationS1;
  c5_af_y = NULL;
  sf_mex_assign(&c5_af_y, sf_mex_create("y", &c5_af_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_ve_y, c5_af_y, "KASaturationS1", "KASaturationS1", 0);
  c5_bf_u = c5_ve_u.KASaturationS2;
  c5_bf_y = NULL;
  sf_mex_assign(&c5_bf_y, sf_mex_create("y", &c5_bf_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_ve_y, c5_bf_y, "KASaturationS2", "KASaturationS2", 0);
  c5_cf_u = c5_ve_u.KASaturationEarly;
  c5_cf_y = NULL;
  sf_mex_assign(&c5_cf_y, sf_mex_create("y", &c5_cf_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_ve_y, c5_cf_y, "KASaturationEarly", "KASaturationEarly", 0);
  c5_df_u = c5_ve_u.KASaturationMax;
  c5_df_y = NULL;
  sf_mex_assign(&c5_df_y, sf_mex_create("y", &c5_df_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_ve_y, c5_df_y, "KASaturationMax", "KASaturationMax", 0);
  sf_mex_addfield(c5_b_y, c5_ve_y, "Saturation", "Saturation", 0);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_d_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  c5_ControlStateBus c5_b_u;
  const mxArray *c5_b_y = NULL;
  real_T c5_c_u;
  const mxArray *c5_c_y = NULL;
  real_T c5_d_u;
  const mxArray *c5_d_y = NULL;
  real_T c5_e_u;
  const mxArray *c5_e_y = NULL;
  real_T c5_f_u;
  const mxArray *c5_f_y = NULL;
  real_T c5_g_u;
  const mxArray *c5_g_y = NULL;
  real_T c5_h_u;
  const mxArray *c5_h_y = NULL;
  real_T c5_i_u;
  const mxArray *c5_i_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(c5_ControlStateBus *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_c_u = c5_b_u.ControllerMode;
  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", &c5_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_c_y, "ControllerMode", "ControllerMode", 0);
  c5_d_u = c5_b_u.SupportState;
  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", &c5_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_d_y, "SupportState", "SupportState", 0);
  c5_e_u = c5_b_u.StanceLeg;
  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", &c5_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_e_y, "StanceLeg", "StanceLeg", 0);
  c5_f_u = c5_b_u.InDoubleSupport;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_create("y", &c5_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_f_y, "InDoubleSupport", "InDoubleSupport", 0);
  c5_g_u = c5_b_u.RollPhase;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_g_y, "RollPhase", "RollPhase", 0);
  c5_h_u = c5_b_u.StepCount;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_h_y, "StepCount", "StepCount", 0);
  c5_i_u = c5_b_u.Error;
  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", &c5_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_i_y, "Error", "Error", 0);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_e_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i512;
  real_T c5_b_inData[13];
  int32_T c5_i513;
  real_T c5_b_u[13];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i512 = 0; c5_i512 < 13; c5_i512++) {
    c5_b_inData[c5_i512] = (*(real_T (*)[13])c5_inData)[c5_i512];
  }

  for (c5_i513 = 0; c5_i513 < 13; c5_i513++) {
    c5_b_u[c5_i513] = c5_b_inData[c5_i513];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_f_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i514;
  int32_T c5_i515;
  int32_T c5_i516;
  real_T c5_b_inData[78];
  int32_T c5_i517;
  int32_T c5_i518;
  int32_T c5_i519;
  real_T c5_b_u[78];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i514 = 0;
  for (c5_i515 = 0; c5_i515 < 6; c5_i515++) {
    for (c5_i516 = 0; c5_i516 < 13; c5_i516++) {
      c5_b_inData[c5_i516 + c5_i514] = (*(real_T (*)[78])c5_inData)[c5_i516 +
        c5_i514];
    }

    c5_i514 += 13;
  }

  c5_i517 = 0;
  for (c5_i518 = 0; c5_i518 < 6; c5_i518++) {
    for (c5_i519 = 0; c5_i519 < 13; c5_i519++) {
      c5_b_u[c5_i519 + c5_i517] = c5_b_inData[c5_i519 + c5_i517];
    }

    c5_i517 += 13;
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 2, 13, 6),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_g_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i520;
  int32_T c5_i521;
  int32_T c5_i522;
  real_T c5_b_inData[36];
  int32_T c5_i523;
  int32_T c5_i524;
  int32_T c5_i525;
  real_T c5_b_u[36];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i520 = 0;
  for (c5_i521 = 0; c5_i521 < 6; c5_i521++) {
    for (c5_i522 = 0; c5_i522 < 6; c5_i522++) {
      c5_b_inData[c5_i522 + c5_i520] = (*(real_T (*)[36])c5_inData)[c5_i522 +
        c5_i520];
    }

    c5_i520 += 6;
  }

  c5_i523 = 0;
  for (c5_i524 = 0; c5_i524 < 6; c5_i524++) {
    for (c5_i525 = 0; c5_i525 < 6; c5_i525++) {
      c5_b_u[c5_i525 + c5_i523] = c5_b_inData[c5_i525 + c5_i523];
    }

    c5_i523 += 6;
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_e_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[36])
{
  real_T c5_dv40[36];
  int32_T c5_i526;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv40, 1, 0, 0U, 1, 0U, 2, 6,
                6);
  for (c5_i526 = 0; c5_i526 < 36; c5_i526++) {
    c5_b_y[c5_i526] = c5_dv40[c5_i526];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_HAlpha;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[36];
  int32_T c5_i527;
  int32_T c5_i528;
  int32_T c5_i529;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_HAlpha = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_HAlpha), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_HAlpha);
  c5_i527 = 0;
  for (c5_i528 = 0; c5_i528 < 6; c5_i528++) {
    for (c5_i529 = 0; c5_i529 < 6; c5_i529++) {
      (*(real_T (*)[36])c5_outData)[c5_i529 + c5_i527] = c5_b_y[c5_i529 +
        c5_i527];
    }

    c5_i527 += 6;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static void c5_f_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  c5_ControlParamsBus *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[5] = { "Supervisory", "Discrete", "Output",
    "Feedback", "Saturation" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_b_u, 5, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "Supervisory";
  c5_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "Supervisory", "Supervisory", 0)), &c5_thisId, &c5_b_y->Supervisory);
  c5_thisId.fIdentifier = "Discrete";
  c5_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "Discrete", "Discrete", 0)), &c5_thisId, &c5_b_y->Discrete);
  c5_thisId.fIdentifier = "Output";
  c5_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "Output", "Output", 0)), &c5_thisId, &c5_b_y->Output);
  c5_thisId.fIdentifier = "Feedback";
  c5_v_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "Feedback", "Feedback", 0)), &c5_thisId, &c5_b_y->Feedback);
  c5_thisId.fIdentifier = "Saturation";
  c5_b_y->Saturation = c5_w_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "Saturation", "Saturation", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
}

static void c5_g_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  c5_SupervisoryParamsBus *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[52] = { "EnableSwapOnKAAccel",
    "EnableSwapOnKASpring", "EnableBackwardSwap", "ImpactThresholdKAAccel",
    "ImpactThresholdKASpringAbs", "ImpactThresholdKASpringRel", "SwapThresholdS",
    "AllowDoubleSupport", "UseGaitTransition", "NumTransitionSteps",
    "TransitionThresholdTorsoVel", "KAInjection", "MinDeltaThetaTransition",
    "StartSecondGaitOnStep", "VBLAParams", "BalanceParams", "GaitTweaks",
    "TStepInitial", "TMaxUpdate", "RunMode", "UseAbsoluteSwingLA",
    "ErrorZeroFactor", "ErrorVelZeroFactor", "StanceLegInit",
    "ControllerModeInit", "UsePosingControl", "TPosing", "TorsoBackAngle",
    "TorsoBackOnStep", "EnergyControlGain", "EnergyControlPhi0",
    "VelocityControlTorsoMax", "VelocityControlTorsoMin",
    "VelocityControlTorsoGain", "VelocityControlTorsoV0", "MinDeltaTheta",
    "Theta0", "KThetaPlus", "KThetaMinus", "RollPhaseVelocityThresh",
    "RollPhaseSThresh", "MaxError", "MaxErrorVel", "MaxErrorCount",
    "K1MidStanceUpdate", "K2MidStanceUpdate", "EnableVelocityBasedUpdate",
    "VelocityBasedUpdateK1", "VelocityBasedUpdateK2",
    "VelocityBasedUpdateDTheta0", "VelocityBasedUpdateLimits",
    "DesiredYawOffset" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_b_u, 52, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "EnableSwapOnKAAccel";
  c5_b_y->EnableSwapOnKAAccel = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "EnableSwapOnKAAccel", "EnableSwapOnKAAccel", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "EnableSwapOnKASpring";
  c5_b_y->EnableSwapOnKASpring = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "EnableSwapOnKASpring", "EnableSwapOnKASpring", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "EnableBackwardSwap";
  c5_b_y->EnableBackwardSwap = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "EnableBackwardSwap", "EnableBackwardSwap", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "ImpactThresholdKAAccel";
  c5_b_y->ImpactThresholdKAAccel = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "ImpactThresholdKAAccel",
    "ImpactThresholdKAAccel", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "ImpactThresholdKASpringAbs";
  c5_b_y->ImpactThresholdKASpringAbs = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "ImpactThresholdKASpringAbs",
    "ImpactThresholdKASpringAbs", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "ImpactThresholdKASpringRel";
  c5_b_y->ImpactThresholdKASpringRel = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "ImpactThresholdKASpringRel",
    "ImpactThresholdKASpringRel", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "SwapThresholdS";
  c5_b_y->SwapThresholdS = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "SwapThresholdS", "SwapThresholdS", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "AllowDoubleSupport";
  c5_b_y->AllowDoubleSupport = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "AllowDoubleSupport", "AllowDoubleSupport", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "UseGaitTransition";
  c5_b_y->UseGaitTransition = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "UseGaitTransition", "UseGaitTransition", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "NumTransitionSteps";
  c5_b_y->NumTransitionSteps = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "NumTransitionSteps", "NumTransitionSteps", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "TransitionThresholdTorsoVel";
  c5_b_y->TransitionThresholdTorsoVel = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "TransitionThresholdTorsoVel",
    "TransitionThresholdTorsoVel", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "KAInjection";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "KAInjection", "KAInjection", 0)), &c5_thisId, c5_b_y->KAInjection);
  c5_thisId.fIdentifier = "MinDeltaThetaTransition";
  c5_b_y->MinDeltaThetaTransition = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "MinDeltaThetaTransition",
    "MinDeltaThetaTransition", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "StartSecondGaitOnStep";
  c5_b_y->StartSecondGaitOnStep = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "StartSecondGaitOnStep",
    "StartSecondGaitOnStep", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "VBLAParams";
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "VBLAParams", "VBLAParams", 0)), &c5_thisId, c5_b_y->VBLAParams);
  c5_thisId.fIdentifier = "BalanceParams";
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "BalanceParams", "BalanceParams", 0)), &c5_thisId, c5_b_y->BalanceParams);
  c5_thisId.fIdentifier = "GaitTweaks";
  c5_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "GaitTweaks", "GaitTweaks", 0)), &c5_thisId, c5_b_y->GaitTweaks);
  c5_thisId.fIdentifier = "TStepInitial";
  c5_b_y->TStepInitial = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "TStepInitial", "TStepInitial", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "TMaxUpdate";
  c5_b_y->TMaxUpdate = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "TMaxUpdate", "TMaxUpdate", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "RunMode";
  c5_b_y->RunMode = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "RunMode", "RunMode", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "UseAbsoluteSwingLA";
  c5_b_y->UseAbsoluteSwingLA = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "UseAbsoluteSwingLA", "UseAbsoluteSwingLA", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "ErrorZeroFactor";
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "ErrorZeroFactor", "ErrorZeroFactor", 0)), &c5_thisId,
                        c5_b_y->ErrorZeroFactor);
  c5_thisId.fIdentifier = "ErrorVelZeroFactor";
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "ErrorVelZeroFactor", "ErrorVelZeroFactor", 0)), &c5_thisId,
                        c5_b_y->ErrorVelZeroFactor);
  c5_thisId.fIdentifier = "StanceLegInit";
  c5_b_y->StanceLegInit = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "StanceLegInit", "StanceLegInit", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "ControllerModeInit";
  c5_b_y->ControllerModeInit = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "ControllerModeInit", "ControllerModeInit", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "UsePosingControl";
  c5_b_y->UsePosingControl = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "UsePosingControl", "UsePosingControl", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "TPosing";
  c5_b_y->TPosing = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "TPosing", "TPosing", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "TorsoBackAngle";
  c5_b_y->TorsoBackAngle = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "TorsoBackAngle", "TorsoBackAngle", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "TorsoBackOnStep";
  c5_b_y->TorsoBackOnStep = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "TorsoBackOnStep", "TorsoBackOnStep", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "EnergyControlGain";
  c5_b_y->EnergyControlGain = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "EnergyControlGain", "EnergyControlGain", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "EnergyControlPhi0";
  c5_b_y->EnergyControlPhi0 = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "EnergyControlPhi0", "EnergyControlPhi0", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "VelocityControlTorsoMax";
  c5_b_y->VelocityControlTorsoMax = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "VelocityControlTorsoMax",
    "VelocityControlTorsoMax", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "VelocityControlTorsoMin";
  c5_b_y->VelocityControlTorsoMin = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "VelocityControlTorsoMin",
    "VelocityControlTorsoMin", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "VelocityControlTorsoGain";
  c5_b_y->VelocityControlTorsoGain = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "VelocityControlTorsoGain",
    "VelocityControlTorsoGain", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "VelocityControlTorsoV0";
  c5_b_y->VelocityControlTorsoV0 = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "VelocityControlTorsoV0",
    "VelocityControlTorsoV0", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "MinDeltaTheta";
  c5_b_y->MinDeltaTheta = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "MinDeltaTheta", "MinDeltaTheta", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "Theta0";
  c5_b_y->Theta0 = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "Theta0", "Theta0", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "KThetaPlus";
  c5_b_y->KThetaPlus = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "KThetaPlus", "KThetaPlus", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "KThetaMinus";
  c5_b_y->KThetaMinus = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "KThetaMinus", "KThetaMinus", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "RollPhaseVelocityThresh";
  c5_b_y->RollPhaseVelocityThresh = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "RollPhaseVelocityThresh",
    "RollPhaseVelocityThresh", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "RollPhaseSThresh";
  c5_b_y->RollPhaseSThresh = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "RollPhaseSThresh", "RollPhaseSThresh", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "MaxError";
  c5_b_y->MaxError = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "MaxError", "MaxError", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "MaxErrorVel";
  c5_b_y->MaxErrorVel = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "MaxErrorVel", "MaxErrorVel", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "MaxErrorCount";
  c5_b_y->MaxErrorCount = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "MaxErrorCount", "MaxErrorCount", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "K1MidStanceUpdate";
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "K1MidStanceUpdate", "K1MidStanceUpdate", 0)), &c5_thisId,
                        c5_b_y->K1MidStanceUpdate);
  c5_thisId.fIdentifier = "K2MidStanceUpdate";
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "K2MidStanceUpdate", "K2MidStanceUpdate", 0)), &c5_thisId,
                        c5_b_y->K2MidStanceUpdate);
  c5_thisId.fIdentifier = "EnableVelocityBasedUpdate";
  c5_b_y->EnableVelocityBasedUpdate = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "EnableVelocityBasedUpdate",
    "EnableVelocityBasedUpdate", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "VelocityBasedUpdateK1";
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "VelocityBasedUpdateK1", "VelocityBasedUpdateK1", 0)), &c5_thisId,
                        c5_b_y->VelocityBasedUpdateK1);
  c5_thisId.fIdentifier = "VelocityBasedUpdateK2";
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "VelocityBasedUpdateK2", "VelocityBasedUpdateK2", 0)), &c5_thisId,
                        c5_b_y->VelocityBasedUpdateK2);
  c5_thisId.fIdentifier = "VelocityBasedUpdateDTheta0";
  c5_b_y->VelocityBasedUpdateDTheta0 = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "VelocityBasedUpdateDTheta0",
    "VelocityBasedUpdateDTheta0", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "VelocityBasedUpdateLimits";
  c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "VelocityBasedUpdateLimits", "VelocityBasedUpdateLimits", 0)), &c5_thisId,
                        c5_b_y->VelocityBasedUpdateLimits);
  c5_thisId.fIdentifier = "DesiredYawOffset";
  c5_b_y->DesiredYawOffset = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "DesiredYawOffset", "DesiredYawOffset", 0)),
    &c5_thisId);
  sf_mex_destroy(&c5_b_u);
}

static void c5_h_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[2])
{
  real_T c5_dv41[2];
  int32_T c5_i530;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv41, 1, 0, 0U, 1, 0U, 1, 2);
  for (c5_i530 = 0; c5_i530 < 2; c5_i530++) {
    c5_b_y[c5_i530] = c5_dv41[c5_i530];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_i_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[13])
{
  real_T c5_dv42[13];
  int32_T c5_i531;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv42, 1, 0, 0U, 1, 0U, 1, 13);
  for (c5_i531 = 0; c5_i531 < 13; c5_i531++) {
    c5_b_y[c5_i531] = c5_dv42[c5_i531];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_j_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[5])
{
  real_T c5_dv43[5];
  int32_T c5_i532;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv43, 1, 0, 0U, 1, 0U, 1, 5);
  for (c5_i532 = 0; c5_i532 < 5; c5_i532++) {
    c5_b_y[c5_i532] = c5_dv43[c5_i532];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_k_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[12])
{
  real_T c5_dv44[12];
  int32_T c5_i533;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv44, 1, 0, 0U, 1, 0U, 2, 6,
                2);
  for (c5_i533 = 0; c5_i533 < 12; c5_i533++) {
    c5_b_y[c5_i533] = c5_dv44[c5_i533];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_l_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  c5_DiscreteParamsBus *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[11] = { "TLastUpdate",
    "VelocityControlLADelta", "VelocityControlTorsoDelta",
    "VelocityControlHipDistCur", "VelocityControlHipDistPrev",
    "VirtualSpringMode", "VirtualSpringStiffness", "VirtualSpringDamping",
    "VirtualSpringModAmplitude", "VirtualSpringModRate", "VirtualSpringRestPos"
  };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_b_u, 11, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "TLastUpdate";
  c5_b_y->TLastUpdate = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "TLastUpdate", "TLastUpdate", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "VelocityControlLADelta";
  c5_b_y->VelocityControlLADelta = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "VelocityControlLADelta",
    "VelocityControlLADelta", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "VelocityControlTorsoDelta";
  c5_b_y->VelocityControlTorsoDelta = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "VelocityControlTorsoDelta",
    "VelocityControlTorsoDelta", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "VelocityControlHipDistCur";
  c5_b_y->VelocityControlHipDistCur = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "VelocityControlHipDistCur",
    "VelocityControlHipDistCur", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "VelocityControlHipDistPrev";
  c5_b_y->VelocityControlHipDistPrev = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "VelocityControlHipDistPrev",
    "VelocityControlHipDistPrev", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "VirtualSpringMode";
  c5_b_y->VirtualSpringMode = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "VirtualSpringMode", "VirtualSpringMode", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "VirtualSpringStiffness";
  c5_b_y->VirtualSpringStiffness = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "VirtualSpringStiffness",
    "VirtualSpringStiffness", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "VirtualSpringDamping";
  c5_b_y->VirtualSpringDamping = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "VirtualSpringDamping", "VirtualSpringDamping", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "VirtualSpringModAmplitude";
  c5_b_y->VirtualSpringModAmplitude = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "VirtualSpringModAmplitude",
    "VirtualSpringModAmplitude", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "VirtualSpringModRate";
  c5_b_y->VirtualSpringModRate = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "VirtualSpringModRate", "VirtualSpringModRate", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "VirtualSpringRestPos";
  c5_b_y->VirtualSpringRestPos = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "VirtualSpringRestPos", "VirtualSpringRestPos", 0)),
    &c5_thisId);
  sf_mex_destroy(&c5_b_u);
}

static void c5_m_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  c5_OutputParamsBus *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[18] = { "H0", "HAlpha", "ThetaLimits",
    "Theta", "SaturateS", "SLimits", "EnforceIncreasingS", "UseCorrection",
    "SMaxCorrection", "HAlphaCorrection", "Phi", "PhiAlpha", "SaturateR",
    "RLimits", "HBarAlpha", "HBarLimits", "HAlphaStar", "YawLimit" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_b_u, 18, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "H0";
  c5_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "H0",
    "H0", 0)), &c5_thisId, c5_b_y->H0);
  c5_thisId.fIdentifier = "HAlpha";
  c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "HAlpha", "HAlpha", 0)), &c5_thisId, c5_b_y->HAlpha);
  c5_thisId.fIdentifier = "ThetaLimits";
  c5_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "ThetaLimits", "ThetaLimits", 0)), &c5_thisId, c5_b_y->ThetaLimits);
  c5_thisId.fIdentifier = "Theta";
  c5_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "Theta", "Theta", 0)), &c5_thisId, &c5_b_y->Theta);
  c5_thisId.fIdentifier = "SaturateS";
  c5_b_y->SaturateS = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "SaturateS", "SaturateS", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "SLimits";
  c5_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "SLimits", "SLimits", 0)), &c5_thisId, c5_b_y->SLimits);
  c5_thisId.fIdentifier = "EnforceIncreasingS";
  c5_b_y->EnforceIncreasingS = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "EnforceIncreasingS", "EnforceIncreasingS", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "UseCorrection";
  c5_b_y->UseCorrection = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "UseCorrection", "UseCorrection", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "SMaxCorrection";
  c5_b_y->SMaxCorrection = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "SMaxCorrection", "SMaxCorrection", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "HAlphaCorrection";
  c5_s_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "HAlphaCorrection", "HAlphaCorrection", 0)), &c5_thisId,
                        c5_b_y->HAlphaCorrection);
  c5_thisId.fIdentifier = "Phi";
  c5_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "Phi",
    "Phi", 0)), &c5_thisId, &c5_b_y->Phi);
  c5_thisId.fIdentifier = "PhiAlpha";
  c5_u_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "PhiAlpha", "PhiAlpha", 0)), &c5_thisId, c5_b_y->PhiAlpha);
  c5_thisId.fIdentifier = "SaturateR";
  c5_b_y->SaturateR = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "SaturateR", "SaturateR", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "RLimits";
  c5_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "RLimits", "RLimits", 0)), &c5_thisId, c5_b_y->RLimits);
  c5_thisId.fIdentifier = "HBarAlpha";
  c5_s_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "HBarAlpha", "HBarAlpha", 0)), &c5_thisId, c5_b_y->HBarAlpha);
  c5_thisId.fIdentifier = "HBarLimits";
  c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "HBarLimits", "HBarLimits", 0)), &c5_thisId, c5_b_y->HBarLimits);
  c5_thisId.fIdentifier = "HAlphaStar";
  c5_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "HAlphaStar", "HAlphaStar", 0)), &c5_thisId, c5_b_y->HAlphaStar);
  c5_thisId.fIdentifier = "YawLimit";
  c5_b_y->YawLimit = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "YawLimit", "YawLimit", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
}

static void c5_n_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[78])
{
  real_T c5_dv45[78];
  int32_T c5_i534;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv45, 1, 0, 0U, 1, 0U, 2, 6,
                13);
  for (c5_i534 = 0; c5_i534 < 78; c5_i534++) {
    c5_b_y[c5_i534] = c5_dv45[c5_i534];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_o_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[2])
{
  real_T c5_dv46[2];
  int32_T c5_i535;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv46, 1, 0, 0U, 1, 0U, 2, 1,
                2);
  for (c5_i535 = 0; c5_i535 < 2; c5_i535++) {
    c5_b_y[c5_i535] = c5_dv46[c5_i535];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_p_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  c5_ThetaParamsBus *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[5] = { "c0", "ct", "cq", "t0", "cz" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_b_u, 5, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "c0";
  c5_b_y->c0 = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "c0", "c0", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "ct";
  c5_b_y->ct = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "ct", "ct", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "cq";
  c5_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "cq",
    "cq", 0)), &c5_thisId, c5_b_y->cq);
  c5_thisId.fIdentifier = "t0";
  c5_b_y->t0 = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "t0", "t0", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "cz";
  c5_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "cz",
    "cz", 0)), &c5_thisId, c5_b_y->cz);
  sf_mex_destroy(&c5_b_u);
}

static void c5_q_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[13])
{
  real_T c5_dv47[13];
  int32_T c5_i536;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv47, 1, 0, 0U, 1, 0U, 2, 1,
                13);
  for (c5_i536 = 0; c5_i536 < 13; c5_i536++) {
    c5_b_y[c5_i536] = c5_dv47[c5_i536];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_r_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[7])
{
  real_T c5_dv48[7];
  int32_T c5_i537;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv48, 1, 0, 0U, 1, 0U, 2, 1,
                7);
  for (c5_i537 = 0; c5_i537 < 7; c5_i537++) {
    c5_b_y[c5_i537] = c5_dv48[c5_i537];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_s_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[30])
{
  real_T c5_dv49[30];
  int32_T c5_i538;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv49, 1, 0, 0U, 1, 0U, 2, 6,
                5);
  for (c5_i538 = 0; c5_i538 < 30; c5_i538++) {
    c5_b_y[c5_i538] = c5_dv49[c5_i538];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_t_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, c5_PhiParamsBus *
  c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[2] = { "c0", "cq" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_b_u, 2, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "c0";
  c5_b_y->c0 = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "c0", "c0", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "cq";
  c5_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "cq",
    "cq", 0)), &c5_thisId, c5_b_y->cq);
  sf_mex_destroy(&c5_b_u);
}

static void c5_u_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[20])
{
  real_T c5_dv50[20];
  int32_T c5_i539;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv50, 1, 0, 0U, 1, 0U, 2, 1,
                20);
  for (c5_i539 = 0; c5_i539 < 20; c5_i539++) {
    c5_b_y[c5_i539] = c5_dv50[c5_i539];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_v_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId,
  c5_FeedbackParamsBus *c5_b_y)
{
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[27] = { "kp", "kd", "epsilon", "kff_grav",
    "delta_grav", "kff_decoup", "kd_torso", "kp_2dof", "kd_2dof", "kpre_2dof",
    "kp_lat", "kd_lat", "q3d_min_lat", "q3d_max_lat", "w_torso_lat", "u_ff",
    "LateralControlMode", "DecouplingMode", "Use2DOF", "UseDSGravComp",
    "lat_bias", "lat_bias2", "linkFeedback", "RIO", "SelectFeedforward",
    "FeedforwardGain", "EnableFeedforwardOnStep" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_b_u, 27, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "kp";
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "kp",
    "kp", 0)), &c5_thisId, c5_b_y->kp);
  c5_thisId.fIdentifier = "kd";
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "kd",
    "kd", 0)), &c5_thisId, c5_b_y->kd);
  c5_thisId.fIdentifier = "epsilon";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "epsilon", "epsilon", 0)), &c5_thisId, c5_b_y->epsilon);
  c5_thisId.fIdentifier = "kff_grav";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "kff_grav", "kff_grav", 0)), &c5_thisId, c5_b_y->kff_grav);
  c5_thisId.fIdentifier = "delta_grav";
  c5_b_y->delta_grav = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "delta_grav", "delta_grav", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "kff_decoup";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "kff_decoup", "kff_decoup", 0)), &c5_thisId, c5_b_y->kff_decoup);
  c5_thisId.fIdentifier = "kd_torso";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "kd_torso", "kd_torso", 0)), &c5_thisId, c5_b_y->kd_torso);
  c5_thisId.fIdentifier = "kp_2dof";
  c5_b_y->kp_2dof = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "kp_2dof", "kp_2dof", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "kd_2dof";
  c5_b_y->kd_2dof = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "kd_2dof", "kd_2dof", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "kpre_2dof";
  c5_b_y->kpre_2dof = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "kpre_2dof", "kpre_2dof", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "kp_lat";
  c5_b_y->kp_lat = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "kp_lat", "kp_lat", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "kd_lat";
  c5_b_y->kd_lat = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "kd_lat", "kd_lat", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "q3d_min_lat";
  c5_b_y->q3d_min_lat = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "q3d_min_lat", "q3d_min_lat", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "q3d_max_lat";
  c5_b_y->q3d_max_lat = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "q3d_max_lat", "q3d_max_lat", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "w_torso_lat";
  c5_b_y->w_torso_lat = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "w_torso_lat", "w_torso_lat", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "u_ff";
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u, "u_ff",
    "u_ff", 0)), &c5_thisId, c5_b_y->u_ff);
  c5_thisId.fIdentifier = "LateralControlMode";
  c5_b_y->LateralControlMode = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "LateralControlMode", "LateralControlMode", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "DecouplingMode";
  c5_b_y->DecouplingMode = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "DecouplingMode", "DecouplingMode", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "Use2DOF";
  c5_b_y->Use2DOF = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "Use2DOF", "Use2DOF", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "UseDSGravComp";
  c5_b_y->UseDSGravComp = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "UseDSGravComp", "UseDSGravComp", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "lat_bias";
  c5_b_y->lat_bias = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "lat_bias", "lat_bias", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "lat_bias2";
  c5_b_y->lat_bias2 = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "lat_bias2", "lat_bias2", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "linkFeedback";
  c5_b_y->linkFeedback = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "linkFeedback", "linkFeedback", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "RIO";
  c5_b_y->RIO = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c5_b_u, "RIO", "RIO", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "SelectFeedforward";
  c5_b_y->SelectFeedforward = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "SelectFeedforward", "SelectFeedforward", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "FeedforwardGain";
  c5_b_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "FeedforwardGain", "FeedforwardGain", 0)), &c5_thisId,
                        c5_b_y->FeedforwardGain);
  c5_thisId.fIdentifier = "EnableFeedforwardOnStep";
  c5_b_y->EnableFeedforwardOnStep = c5_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c5_b_u, "EnableFeedforwardOnStep",
    "EnableFeedforwardOnStep", 0)), &c5_thisId);
  sf_mex_destroy(&c5_b_u);
}

static c5_SaturationParamsBus c5_w_emlrt_marshallIn
  (SFc5_LibWalkingInstanceStruct *chartInstance, const mxArray *c5_b_u, const
   emlrtMsgIdentifier *c5_parentId)
{
  c5_SaturationParamsBus c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[7] = { "UseQPSaturation", "QPWeight",
    "UseKASaturation", "KASaturationS1", "KASaturationS2", "KASaturationEarly",
    "KASaturationMax" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_b_u, 7, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "UseQPSaturation";
  c5_b_y.UseQPSaturation = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "UseQPSaturation", "UseQPSaturation", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "QPWeight";
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c5_b_u,
    "QPWeight", "QPWeight", 0)), &c5_thisId, c5_b_y.QPWeight);
  c5_thisId.fIdentifier = "UseKASaturation";
  c5_b_y.UseKASaturation = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "UseKASaturation", "UseKASaturation", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "KASaturationS1";
  c5_b_y.KASaturationS1 = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "KASaturationS1", "KASaturationS1", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "KASaturationS2";
  c5_b_y.KASaturationS2 = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "KASaturationS2", "KASaturationS2", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "KASaturationEarly";
  c5_b_y.KASaturationEarly = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "KASaturationEarly", "KASaturationEarly", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "KASaturationMax";
  c5_b_y.KASaturationMax = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "KASaturationMax", "KASaturationMax", 0)),
    &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_ControlParams;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  c5_ControlParamsBus c5_b_y;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_b_ControlParams = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_ControlParams),
                        &c5_thisId, &c5_b_y);
  sf_mex_destroy(&c5_b_ControlParams);
  *(c5_ControlParamsBus *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static c5_ControlStateBus c5_x_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  c5_ControlStateBus c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  static const char * c5_fieldNames[7] = { "ControllerMode", "SupportState",
    "StanceLeg", "InDoubleSupport", "RollPhase", "StepCount", "Error" };

  c5_thisId.fParent = c5_parentId;
  sf_mex_check_struct(c5_parentId, c5_b_u, 7, c5_fieldNames, 0U, NULL);
  c5_thisId.fIdentifier = "ControllerMode";
  c5_b_y.ControllerMode = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "ControllerMode", "ControllerMode", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "SupportState";
  c5_b_y.SupportState = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "SupportState", "SupportState", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "StanceLeg";
  c5_b_y.StanceLeg = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "StanceLeg", "StanceLeg", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "InDoubleSupport";
  c5_b_y.InDoubleSupport = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "InDoubleSupport", "InDoubleSupport", 0)),
    &c5_thisId);
  c5_thisId.fIdentifier = "RollPhase";
  c5_b_y.RollPhase = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "RollPhase", "RollPhase", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "StepCount";
  c5_b_y.StepCount = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c5_b_u, "StepCount", "StepCount", 0)), &c5_thisId);
  c5_thisId.fIdentifier = "Error";
  c5_b_y.Error = c5_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c5_b_u, "Error", "Error", 0)),
    &c5_thisId);
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_ControlState;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  c5_ControlStateBus c5_b_y;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_b_ControlState = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_y = c5_x_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_ControlState),
    &c5_thisId);
  sf_mex_destroy(&c5_b_ControlState);
  *(c5_ControlStateBus *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_h_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  boolean_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(boolean_T *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static const mxArray *c5_i_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i540;
  real_T c5_b_inData[4];
  int32_T c5_i541;
  real_T c5_b_u[4];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i540 = 0; c5_i540 < 4; c5_i540++) {
    c5_b_inData[c5_i540] = (*(real_T (*)[4])c5_inData)[c5_i540];
  }

  for (c5_i541 = 0; c5_i541 < 4; c5_i541++) {
    c5_b_u[c5_i541] = c5_b_inData[c5_i541];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 2, 1, 4),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_y_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[4])
{
  real_T c5_dv51[4];
  int32_T c5_i542;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv51, 1, 0, 0U, 1, 0U, 2, 1,
                4);
  for (c5_i542 = 0; c5_i542 < 4; c5_i542++) {
    c5_b_y[c5_i542] = c5_dv51[c5_i542];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_SwingKeeAngleBias;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[4];
  int32_T c5_i543;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_SwingKeeAngleBias = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_y_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_SwingKeeAngleBias),
                        &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_SwingKeeAngleBias);
  for (c5_i543 = 0; c5_i543 < 4; c5_i543++) {
    (*(real_T (*)[4])c5_outData)[c5_i543] = c5_b_y[c5_i543];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static void c5_ab_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[78])
{
  real_T c5_dv52[78];
  int32_T c5_i544;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv52, 1, 0, 0U, 1, 0U, 2, 13,
                6);
  for (c5_i544 = 0; c5_i544 < 78; c5_i544++) {
    c5_b_y[c5_i544] = c5_dv52[c5_i544];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_QTweaks;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[78];
  int32_T c5_i545;
  int32_T c5_i546;
  int32_T c5_i547;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_QTweaks = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_ab_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_QTweaks), &c5_thisId,
    c5_b_y);
  sf_mex_destroy(&c5_QTweaks);
  c5_i545 = 0;
  for (c5_i546 = 0; c5_i546 < 6; c5_i546++) {
    for (c5_i547 = 0; c5_i547 < 13; c5_i547++) {
      (*(real_T (*)[78])c5_outData)[c5_i547 + c5_i545] = c5_b_y[c5_i547 +
        c5_i545];
    }

    c5_i545 += 13;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static void c5_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_QTweakVec;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[13];
  int32_T c5_i548;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_QTweakVec = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_QTweakVec), &c5_thisId,
                        c5_b_y);
  sf_mex_destroy(&c5_QTweakVec);
  for (c5_i548 = 0; c5_i548 < 13; c5_i548++) {
    (*(real_T (*)[13])c5_outData)[c5_i548] = c5_b_y[c5_i548];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_j_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i549;
  real_T c5_b_inData[13];
  int32_T c5_i550;
  real_T c5_b_u[13];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i549 = 0; c5_i549 < 13; c5_i549++) {
    c5_b_inData[c5_i549] = (*(real_T (*)[13])c5_inData)[c5_i549];
  }

  for (c5_i550 = 0; c5_i550 < 13; c5_i550++) {
    c5_b_u[c5_i550] = c5_b_inData[c5_i550];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_dsdq;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[13];
  int32_T c5_i551;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_dsdq = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_q_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_dsdq), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_dsdq);
  for (c5_i551 = 0; c5_i551 < 13; c5_i551++) {
    (*(real_T (*)[13])c5_outData)[c5_i551] = c5_b_y[c5_i551];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_k_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i552;
  real_T c5_b_inData[15];
  int32_T c5_i553;
  real_T c5_b_u[15];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i552 = 0; c5_i552 < 15; c5_i552++) {
    c5_b_inData[c5_i552] = (*(real_T (*)[15])c5_inData)[c5_i552];
  }

  for (c5_i553 = 0; c5_i553 < 15; c5_i553++) {
    c5_b_u[c5_i553] = c5_b_inData[c5_i553];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 2, 1, 15),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_bb_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[15])
{
  real_T c5_dv53[15];
  int32_T c5_i554;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv53, 1, 0, 0U, 1, 0U, 2, 1,
                15);
  for (c5_i554 = 0; c5_i554 < 15; c5_i554++) {
    c5_b_y[c5_i554] = c5_dv53[c5_i554];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_j_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_c;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[15];
  int32_T c5_i555;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_c = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_bb_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_c), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_c);
  for (c5_i555 = 0; c5_i555 < 15; c5_i555++) {
    (*(real_T (*)[15])c5_outData)[c5_i555] = c5_b_y[c5_i555];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_l_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i556;
  real_T c5_b_inData[2];
  int32_T c5_i557;
  real_T c5_b_u[2];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i556 = 0; c5_i556 < 2; c5_i556++) {
    c5_b_inData[c5_i556] = (*(real_T (*)[2])c5_inData)[c5_i556];
  }

  for (c5_i557 = 0; c5_i557 < 2; c5_i557++) {
    c5_b_u[c5_i557] = c5_b_inData[c5_i557];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_k_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_theta_limits;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[2];
  int32_T c5_i558;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_theta_limits = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_o_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_theta_limits), &c5_thisId,
                        c5_b_y);
  sf_mex_destroy(&c5_theta_limits);
  for (c5_i558 = 0; c5_i558 < 2; c5_i558++) {
    (*(real_T (*)[2])c5_outData)[c5_i558] = c5_b_y[c5_i558];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_m_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i559;
  real_T c5_b_inData[6];
  int32_T c5_i560;
  real_T c5_b_u[6];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i559 = 0; c5_i559 < 6; c5_i559++) {
    c5_b_inData[c5_i559] = (*(real_T (*)[6])c5_inData)[c5_i559];
  }

  for (c5_i560 = 0; c5_i560 < 6; c5_i560++) {
    c5_b_u[c5_i560] = c5_b_inData[c5_i560];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 2, 1, 6),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_cb_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[6])
{
  real_T c5_dv54[6];
  int32_T c5_i561;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv54, 1, 0, 0U, 1, 0U, 2, 1,
                6);
  for (c5_i561 = 0; c5_i561 < 6; c5_i561++) {
    c5_b_y[c5_i561] = c5_dv54[c5_i561];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_l_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_y;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_c_y[6];
  int32_T c5_i562;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_b_y = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_cb_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_y), &c5_thisId, c5_c_y);
  sf_mex_destroy(&c5_b_y);
  for (c5_i562 = 0; c5_i562 < 6; c5_i562++) {
    (*(real_T (*)[6])c5_outData)[c5_i562] = c5_c_y[c5_i562];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_n_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i563;
  real_T c5_b_inData[5];
  int32_T c5_i564;
  real_T c5_b_u[5];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i563 = 0; c5_i563 < 5; c5_i563++) {
    c5_b_inData[c5_i563] = (*(real_T (*)[5])c5_inData)[c5_i563];
  }

  for (c5_i564 = 0; c5_i564 < 5; c5_i564++) {
    c5_b_u[c5_i564] = c5_b_inData[c5_i564];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_db_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, real_T c5_b_y[5])
{
  real_T c5_dv55[5];
  int32_T c5_i565;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_dv55, 1, 0, 0U, 1, 0U, 2, 1,
                5);
  for (c5_i565 = 0; c5_i565 < 5; c5_i565++) {
    c5_b_y[c5_i565] = c5_dv55[c5_i565];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_m_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_y;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_c_y[5];
  int32_T c5_i566;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_b_y = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_db_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_y), &c5_thisId, c5_c_y);
  sf_mex_destroy(&c5_b_y);
  for (c5_i566 = 0; c5_i566 < 5; c5_i566++) {
    (*(real_T (*)[5])c5_outData)[c5_i566] = c5_c_y[c5_i566];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_o_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i567;
  real_T c5_b_inData[20];
  int32_T c5_i568;
  real_T c5_b_u[20];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i567 = 0; c5_i567 < 20; c5_i567++) {
    c5_b_inData[c5_i567] = (*(real_T (*)[20])c5_inData)[c5_i567];
  }

  for (c5_i568 = 0; c5_i568 < 20; c5_i568++) {
    c5_b_u[c5_i568] = c5_b_inData[c5_i568];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 2, 1, 20),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_n_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_afra;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[20];
  int32_T c5_i569;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_afra = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_u_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_afra), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_afra);
  for (c5_i569 = 0; c5_i569 < 20; c5_i569++) {
    (*(real_T (*)[20])c5_outData)[c5_i569] = c5_b_y[c5_i569];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_p_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i570;
  int32_T c5_i571;
  int32_T c5_i572;
  real_T c5_b_inData[30];
  int32_T c5_i573;
  int32_T c5_i574;
  int32_T c5_i575;
  real_T c5_b_u[30];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i570 = 0;
  for (c5_i571 = 0; c5_i571 < 5; c5_i571++) {
    for (c5_i572 = 0; c5_i572 < 6; c5_i572++) {
      c5_b_inData[c5_i572 + c5_i570] = (*(real_T (*)[30])c5_inData)[c5_i572 +
        c5_i570];
    }

    c5_i570 += 6;
  }

  c5_i573 = 0;
  for (c5_i574 = 0; c5_i574 < 5; c5_i574++) {
    for (c5_i575 = 0; c5_i575 < 6; c5_i575++) {
      c5_b_u[c5_i575 + c5_i573] = c5_b_inData[c5_i575 + c5_i573];
    }

    c5_i573 += 6;
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_o_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_poly_cor;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[30];
  int32_T c5_i576;
  int32_T c5_i577;
  int32_T c5_i578;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_poly_cor = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_s_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_poly_cor), &c5_thisId,
                        c5_b_y);
  sf_mex_destroy(&c5_poly_cor);
  c5_i576 = 0;
  for (c5_i577 = 0; c5_i577 < 5; c5_i577++) {
    for (c5_i578 = 0; c5_i578 < 6; c5_i578++) {
      (*(real_T (*)[30])c5_outData)[c5_i578 + c5_i576] = c5_b_y[c5_i578 +
        c5_i576];
    }

    c5_i576 += 6;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_q_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i579;
  int32_T c5_i580;
  int32_T c5_i581;
  real_T c5_b_inData[78];
  int32_T c5_i582;
  int32_T c5_i583;
  int32_T c5_i584;
  real_T c5_b_u[78];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i579 = 0;
  for (c5_i580 = 0; c5_i580 < 13; c5_i580++) {
    for (c5_i581 = 0; c5_i581 < 6; c5_i581++) {
      c5_b_inData[c5_i581 + c5_i579] = (*(real_T (*)[78])c5_inData)[c5_i581 +
        c5_i579];
    }

    c5_i579 += 6;
  }

  c5_i582 = 0;
  for (c5_i583 = 0; c5_i583 < 13; c5_i583++) {
    for (c5_i584 = 0; c5_i584 < 6; c5_i584++) {
      c5_b_u[c5_i584 + c5_i582] = c5_b_inData[c5_i584 + c5_i582];
    }

    c5_i582 += 6;
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 2, 6, 13),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_p_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_jacob_h;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[78];
  int32_T c5_i585;
  int32_T c5_i586;
  int32_T c5_i587;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_jacob_h = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_n_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_jacob_h), &c5_thisId,
                        c5_b_y);
  sf_mex_destroy(&c5_jacob_h);
  c5_i585 = 0;
  for (c5_i586 = 0; c5_i586 < 13; c5_i586++) {
    for (c5_i587 = 0; c5_i587 < 6; c5_i587++) {
      (*(real_T (*)[78])c5_outData)[c5_i587 + c5_i585] = c5_b_y[c5_i587 +
        c5_i585];
    }

    c5_i585 += 6;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_r_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i588;
  boolean_T c5_b_inData[6];
  int32_T c5_i589;
  boolean_T c5_b_u[6];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i588 = 0; c5_i588 < 6; c5_i588++) {
    c5_b_inData[c5_i588] = (*(boolean_T (*)[6])c5_inData)[c5_i588];
  }

  for (c5_i589 = 0; c5_i589 < 6; c5_i589++) {
    c5_b_u[c5_i589] = c5_b_inData[c5_i589];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 11, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_eb_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct *chartInstance,
  const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId, boolean_T
  c5_b_y[6])
{
  boolean_T c5_bv2[6];
  int32_T c5_i590;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), c5_bv2, 1, 11, 0U, 1, 0U, 1, 6);
  for (c5_i590 = 0; c5_i590 < 6; c5_i590++) {
    c5_b_y[c5_i590] = c5_bv2[c5_i590];
  }

  sf_mex_destroy(&c5_b_u);
}

static void c5_q_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_idxsat;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  boolean_T c5_b_y[6];
  int32_T c5_i591;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_idxsat = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_eb_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_idxsat), &c5_thisId,
    c5_b_y);
  sf_mex_destroy(&c5_idxsat);
  for (c5_i591 = 0; c5_i591 < 6; c5_i591++) {
    (*(boolean_T (*)[6])c5_outData)[c5_i591] = c5_b_y[c5_i591];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static boolean_T c5_fb_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  boolean_T c5_b_y;
  boolean_T c5_b0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), &c5_b0, 1, 11, 0U, 0, 0U, 0);
  c5_b_y = c5_b0;
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_r_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_RSaturated;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  boolean_T c5_b_y;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_RSaturated = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_y = c5_fb_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_RSaturated),
    &c5_thisId);
  sf_mex_destroy(&c5_RSaturated);
  *(boolean_T *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_s_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i592;
  real_T c5_b_inData[2];
  int32_T c5_i593;
  real_T c5_b_u[2];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  for (c5_i592 = 0; c5_i592 < 2; c5_i592++) {
    c5_b_inData[c5_i592] = (*(real_T (*)[2])c5_inData)[c5_i592];
  }

  for (c5_i593 = 0; c5_i593 < 2; c5_i593++) {
    c5_b_u[c5_i593] = c5_b_inData[c5_i593];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_s_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_dqyTds;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[2];
  int32_T c5_i594;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_dqyTds = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_dqyTds), &c5_thisId, c5_b_y);
  sf_mex_destroy(&c5_dqyTds);
  for (c5_i594 = 0; c5_i594 < 2; c5_i594++) {
    (*(real_T (*)[2])c5_outData)[c5_i594] = c5_b_y[c5_i594];
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_t_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData;
  c5_OutputParamsBus c5_b_u;
  const mxArray *c5_b_y = NULL;
  int32_T c5_i595;
  real_T c5_c_u[78];
  const mxArray *c5_c_y = NULL;
  int32_T c5_i596;
  real_T c5_d_u[36];
  const mxArray *c5_d_y = NULL;
  int32_T c5_i597;
  real_T c5_e_u[2];
  const mxArray *c5_e_y = NULL;
  c5_ThetaParamsBus c5_f_u;
  const mxArray *c5_f_y = NULL;
  real_T c5_g_u;
  const mxArray *c5_g_y = NULL;
  real_T c5_h_u;
  const mxArray *c5_h_y = NULL;
  int32_T c5_i598;
  real_T c5_i_u[13];
  const mxArray *c5_i_y = NULL;
  real_T c5_j_u;
  const mxArray *c5_j_y = NULL;
  int32_T c5_i599;
  real_T c5_k_u[7];
  const mxArray *c5_k_y = NULL;
  real_T c5_l_u;
  const mxArray *c5_l_y = NULL;
  int32_T c5_i600;
  real_T c5_m_u[2];
  const mxArray *c5_m_y = NULL;
  real_T c5_n_u;
  const mxArray *c5_n_y = NULL;
  real_T c5_o_u;
  const mxArray *c5_o_y = NULL;
  real_T c5_p_u;
  const mxArray *c5_p_y = NULL;
  int32_T c5_i601;
  real_T c5_q_u[30];
  const mxArray *c5_q_y = NULL;
  c5_PhiParamsBus c5_r_u;
  const mxArray *c5_r_y = NULL;
  real_T c5_s_u;
  const mxArray *c5_s_y = NULL;
  int32_T c5_i602;
  real_T c5_t_u[13];
  const mxArray *c5_t_y = NULL;
  int32_T c5_i603;
  real_T c5_u_u[20];
  const mxArray *c5_u_y = NULL;
  real_T c5_v_u;
  const mxArray *c5_v_y = NULL;
  int32_T c5_i604;
  real_T c5_w_u[2];
  const mxArray *c5_w_y = NULL;
  int32_T c5_i605;
  real_T c5_x_u[30];
  const mxArray *c5_x_y = NULL;
  int32_T c5_i606;
  real_T c5_y_u[12];
  const mxArray *c5_y_y = NULL;
  int32_T c5_i607;
  real_T c5_ab_u[36];
  const mxArray *c5_ab_y = NULL;
  real_T c5_bb_u;
  const mxArray *c5_bb_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(c5_OutputParamsBus *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c5_i595 = 0; c5_i595 < 78; c5_i595++) {
    c5_c_u[c5_i595] = c5_b_u.H0[c5_i595];
  }

  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_c_u, 0, 0U, 1U, 0U, 2, 6, 13),
                false);
  sf_mex_addfield(c5_b_y, c5_c_y, "H0", "H0", 0);
  for (c5_i596 = 0; c5_i596 < 36; c5_i596++) {
    c5_d_u[c5_i596] = c5_b_u.HAlpha[c5_i596];
  }

  c5_d_y = NULL;
  sf_mex_assign(&c5_d_y, sf_mex_create("y", c5_d_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c5_b_y, c5_d_y, "HAlpha", "HAlpha", 0);
  for (c5_i597 = 0; c5_i597 < 2; c5_i597++) {
    c5_e_u[c5_i597] = c5_b_u.ThetaLimits[c5_i597];
  }

  c5_e_y = NULL;
  sf_mex_assign(&c5_e_y, sf_mex_create("y", c5_e_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c5_b_y, c5_e_y, "ThetaLimits", "ThetaLimits", 0);
  c5_f_u = c5_b_u.Theta;
  c5_f_y = NULL;
  sf_mex_assign(&c5_f_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_g_u = c5_f_u.c0;
  c5_g_y = NULL;
  sf_mex_assign(&c5_g_y, sf_mex_create("y", &c5_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_f_y, c5_g_y, "c0", "c0", 0);
  c5_h_u = c5_f_u.ct;
  c5_h_y = NULL;
  sf_mex_assign(&c5_h_y, sf_mex_create("y", &c5_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_f_y, c5_h_y, "ct", "ct", 0);
  for (c5_i598 = 0; c5_i598 < 13; c5_i598++) {
    c5_i_u[c5_i598] = c5_f_u.cq[c5_i598];
  }

  c5_i_y = NULL;
  sf_mex_assign(&c5_i_y, sf_mex_create("y", c5_i_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c5_f_y, c5_i_y, "cq", "cq", 0);
  c5_j_u = c5_f_u.t0;
  c5_j_y = NULL;
  sf_mex_assign(&c5_j_y, sf_mex_create("y", &c5_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_f_y, c5_j_y, "t0", "t0", 0);
  for (c5_i599 = 0; c5_i599 < 7; c5_i599++) {
    c5_k_u[c5_i599] = c5_f_u.cz[c5_i599];
  }

  c5_k_y = NULL;
  sf_mex_assign(&c5_k_y, sf_mex_create("y", c5_k_u, 0, 0U, 1U, 0U, 2, 1, 7),
                false);
  sf_mex_addfield(c5_f_y, c5_k_y, "cz", "cz", 0);
  sf_mex_addfield(c5_b_y, c5_f_y, "Theta", "Theta", 0);
  c5_l_u = c5_b_u.SaturateS;
  c5_l_y = NULL;
  sf_mex_assign(&c5_l_y, sf_mex_create("y", &c5_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_l_y, "SaturateS", "SaturateS", 0);
  for (c5_i600 = 0; c5_i600 < 2; c5_i600++) {
    c5_m_u[c5_i600] = c5_b_u.SLimits[c5_i600];
  }

  c5_m_y = NULL;
  sf_mex_assign(&c5_m_y, sf_mex_create("y", c5_m_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c5_b_y, c5_m_y, "SLimits", "SLimits", 0);
  c5_n_u = c5_b_u.EnforceIncreasingS;
  c5_n_y = NULL;
  sf_mex_assign(&c5_n_y, sf_mex_create("y", &c5_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_n_y, "EnforceIncreasingS", "EnforceIncreasingS", 0);
  c5_o_u = c5_b_u.UseCorrection;
  c5_o_y = NULL;
  sf_mex_assign(&c5_o_y, sf_mex_create("y", &c5_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_o_y, "UseCorrection", "UseCorrection", 0);
  c5_p_u = c5_b_u.SMaxCorrection;
  c5_p_y = NULL;
  sf_mex_assign(&c5_p_y, sf_mex_create("y", &c5_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_p_y, "SMaxCorrection", "SMaxCorrection", 0);
  for (c5_i601 = 0; c5_i601 < 30; c5_i601++) {
    c5_q_u[c5_i601] = c5_b_u.HAlphaCorrection[c5_i601];
  }

  c5_q_y = NULL;
  sf_mex_assign(&c5_q_y, sf_mex_create("y", c5_q_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c5_b_y, c5_q_y, "HAlphaCorrection", "HAlphaCorrection", 0);
  c5_r_u = c5_b_u.Phi;
  c5_r_y = NULL;
  sf_mex_assign(&c5_r_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c5_s_u = c5_r_u.c0;
  c5_s_y = NULL;
  sf_mex_assign(&c5_s_y, sf_mex_create("y", &c5_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_r_y, c5_s_y, "c0", "c0", 0);
  for (c5_i602 = 0; c5_i602 < 13; c5_i602++) {
    c5_t_u[c5_i602] = c5_r_u.cq[c5_i602];
  }

  c5_t_y = NULL;
  sf_mex_assign(&c5_t_y, sf_mex_create("y", c5_t_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c5_r_y, c5_t_y, "cq", "cq", 0);
  sf_mex_addfield(c5_b_y, c5_r_y, "Phi", "Phi", 0);
  for (c5_i603 = 0; c5_i603 < 20; c5_i603++) {
    c5_u_u[c5_i603] = c5_b_u.PhiAlpha[c5_i603];
  }

  c5_u_y = NULL;
  sf_mex_assign(&c5_u_y, sf_mex_create("y", c5_u_u, 0, 0U, 1U, 0U, 2, 1, 20),
                false);
  sf_mex_addfield(c5_b_y, c5_u_y, "PhiAlpha", "PhiAlpha", 0);
  c5_v_u = c5_b_u.SaturateR;
  c5_v_y = NULL;
  sf_mex_assign(&c5_v_y, sf_mex_create("y", &c5_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_v_y, "SaturateR", "SaturateR", 0);
  for (c5_i604 = 0; c5_i604 < 2; c5_i604++) {
    c5_w_u[c5_i604] = c5_b_u.RLimits[c5_i604];
  }

  c5_w_y = NULL;
  sf_mex_assign(&c5_w_y, sf_mex_create("y", c5_w_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c5_b_y, c5_w_y, "RLimits", "RLimits", 0);
  for (c5_i605 = 0; c5_i605 < 30; c5_i605++) {
    c5_x_u[c5_i605] = c5_b_u.HBarAlpha[c5_i605];
  }

  c5_x_y = NULL;
  sf_mex_assign(&c5_x_y, sf_mex_create("y", c5_x_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c5_b_y, c5_x_y, "HBarAlpha", "HBarAlpha", 0);
  for (c5_i606 = 0; c5_i606 < 12; c5_i606++) {
    c5_y_u[c5_i606] = c5_b_u.HBarLimits[c5_i606];
  }

  c5_y_y = NULL;
  sf_mex_assign(&c5_y_y, sf_mex_create("y", c5_y_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c5_b_y, c5_y_y, "HBarLimits", "HBarLimits", 0);
  for (c5_i607 = 0; c5_i607 < 36; c5_i607++) {
    c5_ab_u[c5_i607] = c5_b_u.HAlphaStar[c5_i607];
  }

  c5_ab_y = NULL;
  sf_mex_assign(&c5_ab_y, sf_mex_create("y", c5_ab_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c5_b_y, c5_ab_y, "HAlphaStar", "HAlphaStar", 0);
  c5_bb_u = c5_b_u.YawLimit;
  c5_bb_y = NULL;
  sf_mex_assign(&c5_bb_y, sf_mex_create("y", &c5_bb_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c5_b_y, c5_bb_y, "YawLimit", "YawLimit", 0);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_t_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_Output;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  c5_OutputParamsBus c5_b_y;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_Output = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_m_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_Output), &c5_thisId,
                        &c5_b_y);
  sf_mex_destroy(&c5_Output);
  *(c5_OutputParamsBus *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_u_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_i608;
  int32_T c5_i609;
  int32_T c5_i610;
  real_T c5_b_inData[12];
  int32_T c5_i611;
  int32_T c5_i612;
  int32_T c5_i613;
  real_T c5_b_u[12];
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_i608 = 0;
  for (c5_i609 = 0; c5_i609 < 2; c5_i609++) {
    for (c5_i610 = 0; c5_i610 < 6; c5_i610++) {
      c5_b_inData[c5_i610 + c5_i608] = (*(real_T (*)[12])c5_inData)[c5_i610 +
        c5_i608];
    }

    c5_i608 += 6;
  }

  c5_i611 = 0;
  for (c5_i612 = 0; c5_i612 < 2; c5_i612++) {
    for (c5_i613 = 0; c5_i613 < 6; c5_i613++) {
      c5_b_u[c5_i613 + c5_i611] = c5_b_inData[c5_i613 + c5_i611];
    }

    c5_i611 += 6;
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static void c5_u_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_TLegHip;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  real_T c5_b_y[12];
  int32_T c5_i614;
  int32_T c5_i615;
  int32_T c5_i616;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_TLegHip = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_TLegHip), &c5_thisId,
                        c5_b_y);
  sf_mex_destroy(&c5_TLegHip);
  c5_i614 = 0;
  for (c5_i615 = 0; c5_i615 < 2; c5_i615++) {
    for (c5_i616 = 0; c5_i616 < 6; c5_i616++) {
      (*(real_T (*)[12])c5_outData)[c5_i616 + c5_i614] = c5_b_y[c5_i616 +
        c5_i614];
    }

    c5_i614 += 6;
  }

  sf_mex_destroy(&c5_mxArrayInData);
}

const mxArray *sf_c5_LibWalking_get_eml_resolved_functions_info(void)
{
  const mxArray *c5_nameCaptureInfo = NULL;
  c5_nameCaptureInfo = NULL;
  sf_mex_assign(&c5_nameCaptureInfo, sf_mex_createstruct("structure", 2, 269, 1),
                false);
  c5_info_helper(&c5_nameCaptureInfo);
  c5_b_info_helper(&c5_nameCaptureInfo);
  c5_c_info_helper(&c5_nameCaptureInfo);
  c5_d_info_helper(&c5_nameCaptureInfo);
  c5_e_info_helper(&c5_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c5_nameCaptureInfo);
  return c5_nameCaptureInfo;
}

static void c5_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs0 = NULL;
  const mxArray *c5_lhs0 = NULL;
  const mxArray *c5_rhs1 = NULL;
  const mxArray *c5_lhs1 = NULL;
  const mxArray *c5_rhs2 = NULL;
  const mxArray *c5_lhs2 = NULL;
  const mxArray *c5_rhs3 = NULL;
  const mxArray *c5_lhs3 = NULL;
  const mxArray *c5_rhs4 = NULL;
  const mxArray *c5_lhs4 = NULL;
  const mxArray *c5_rhs5 = NULL;
  const mxArray *c5_lhs5 = NULL;
  const mxArray *c5_rhs6 = NULL;
  const mxArray *c5_lhs6 = NULL;
  const mxArray *c5_rhs7 = NULL;
  const mxArray *c5_lhs7 = NULL;
  const mxArray *c5_rhs8 = NULL;
  const mxArray *c5_lhs8 = NULL;
  const mxArray *c5_rhs9 = NULL;
  const mxArray *c5_lhs9 = NULL;
  const mxArray *c5_rhs10 = NULL;
  const mxArray *c5_lhs10 = NULL;
  const mxArray *c5_rhs11 = NULL;
  const mxArray *c5_lhs11 = NULL;
  const mxArray *c5_rhs12 = NULL;
  const mxArray *c5_lhs12 = NULL;
  const mxArray *c5_rhs13 = NULL;
  const mxArray *c5_lhs13 = NULL;
  const mxArray *c5_rhs14 = NULL;
  const mxArray *c5_lhs14 = NULL;
  const mxArray *c5_rhs15 = NULL;
  const mxArray *c5_lhs15 = NULL;
  const mxArray *c5_rhs16 = NULL;
  const mxArray *c5_lhs16 = NULL;
  const mxArray *c5_rhs17 = NULL;
  const mxArray *c5_lhs17 = NULL;
  const mxArray *c5_rhs18 = NULL;
  const mxArray *c5_lhs18 = NULL;
  const mxArray *c5_rhs19 = NULL;
  const mxArray *c5_lhs19 = NULL;
  const mxArray *c5_rhs20 = NULL;
  const mxArray *c5_lhs20 = NULL;
  const mxArray *c5_rhs21 = NULL;
  const mxArray *c5_lhs21 = NULL;
  const mxArray *c5_rhs22 = NULL;
  const mxArray *c5_lhs22 = NULL;
  const mxArray *c5_rhs23 = NULL;
  const mxArray *c5_lhs23 = NULL;
  const mxArray *c5_rhs24 = NULL;
  const mxArray *c5_lhs24 = NULL;
  const mxArray *c5_rhs25 = NULL;
  const mxArray *c5_lhs25 = NULL;
  const mxArray *c5_rhs26 = NULL;
  const mxArray *c5_lhs26 = NULL;
  const mxArray *c5_rhs27 = NULL;
  const mxArray *c5_lhs27 = NULL;
  const mxArray *c5_rhs28 = NULL;
  const mxArray *c5_lhs28 = NULL;
  const mxArray *c5_rhs29 = NULL;
  const mxArray *c5_lhs29 = NULL;
  const mxArray *c5_rhs30 = NULL;
  const mxArray *c5_lhs30 = NULL;
  const mxArray *c5_rhs31 = NULL;
  const mxArray *c5_lhs31 = NULL;
  const mxArray *c5_rhs32 = NULL;
  const mxArray *c5_lhs32 = NULL;
  const mxArray *c5_rhs33 = NULL;
  const mxArray *c5_lhs33 = NULL;
  const mxArray *c5_rhs34 = NULL;
  const mxArray *c5_lhs34 = NULL;
  const mxArray *c5_rhs35 = NULL;
  const mxArray *c5_lhs35 = NULL;
  const mxArray *c5_rhs36 = NULL;
  const mxArray *c5_lhs36 = NULL;
  const mxArray *c5_rhs37 = NULL;
  const mxArray *c5_lhs37 = NULL;
  const mxArray *c5_rhs38 = NULL;
  const mxArray *c5_lhs38 = NULL;
  const mxArray *c5_rhs39 = NULL;
  const mxArray *c5_lhs39 = NULL;
  const mxArray *c5_rhs40 = NULL;
  const mxArray *c5_lhs40 = NULL;
  const mxArray *c5_rhs41 = NULL;
  const mxArray *c5_lhs41 = NULL;
  const mxArray *c5_rhs42 = NULL;
  const mxArray *c5_lhs42 = NULL;
  const mxArray *c5_rhs43 = NULL;
  const mxArray *c5_lhs43 = NULL;
  const mxArray *c5_rhs44 = NULL;
  const mxArray *c5_lhs44 = NULL;
  const mxArray *c5_rhs45 = NULL;
  const mxArray *c5_lhs45 = NULL;
  const mxArray *c5_rhs46 = NULL;
  const mxArray *c5_lhs46 = NULL;
  const mxArray *c5_rhs47 = NULL;
  const mxArray *c5_lhs47 = NULL;
  const mxArray *c5_rhs48 = NULL;
  const mxArray *c5_lhs48 = NULL;
  const mxArray *c5_rhs49 = NULL;
  const mxArray *c5_lhs49 = NULL;
  const mxArray *c5_rhs50 = NULL;
  const mxArray *c5_lhs50 = NULL;
  const mxArray *c5_rhs51 = NULL;
  const mxArray *c5_lhs51 = NULL;
  const mxArray *c5_rhs52 = NULL;
  const mxArray *c5_lhs52 = NULL;
  const mxArray *c5_rhs53 = NULL;
  const mxArray *c5_lhs53 = NULL;
  const mxArray *c5_rhs54 = NULL;
  const mxArray *c5_lhs54 = NULL;
  const mxArray *c5_rhs55 = NULL;
  const mxArray *c5_lhs55 = NULL;
  const mxArray *c5_rhs56 = NULL;
  const mxArray *c5_lhs56 = NULL;
  const mxArray *c5_rhs57 = NULL;
  const mxArray *c5_lhs57 = NULL;
  const mxArray *c5_rhs58 = NULL;
  const mxArray *c5_lhs58 = NULL;
  const mxArray *c5_rhs59 = NULL;
  const mxArray *c5_lhs59 = NULL;
  const mxArray *c5_rhs60 = NULL;
  const mxArray *c5_lhs60 = NULL;
  const mxArray *c5_rhs61 = NULL;
  const mxArray *c5_lhs61 = NULL;
  const mxArray *c5_rhs62 = NULL;
  const mxArray *c5_lhs62 = NULL;
  const mxArray *c5_rhs63 = NULL;
  const mxArray *c5_lhs63 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("applyGaitTweaks2"), "name",
                  "name", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/applyGaitTweaks2.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837256U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c5_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/applyGaitTweaks2.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mrdivide"), "name", "name", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c5_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c5_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("rdivide"), "name", "name", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c5_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c5_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c5_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_div"), "name", "name", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c5_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c5_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/applyGaitTweaks2.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("repmat"), "name", "name", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "resolved",
                  "resolved", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604014U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c5_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c5_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_assert_valid_size_arg"),
                  "name", "name", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1368204630U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c5_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c5_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                  "context", "context", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isinf"), "name", "name", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c5_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c5_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_is_integer_class"), "name",
                  "name", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c5_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c5_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context",
                  "context", 16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c5_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmin"), "name", "name", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c5_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c5_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                  "context", "context", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexIntRelop"),
                  "name", "name", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1326749922U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c5_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                  "context", "context", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c5_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                  "context", "context", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c5_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                  "context", "context", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmin"), "name", "name", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c5_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c5_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                  "context", "context", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c5_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs24), "lhs", "lhs",
                  24);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context",
                  "context", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("max"), "name", "name", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 25);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 25);
  sf_mex_assign(&c5_rhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs25, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs25), "rhs", "rhs",
                  25);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs25), "lhs", "lhs",
                  25);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context",
                  "context", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 26);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 26);
  sf_mex_assign(&c5_rhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs26, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs26), "rhs", "rhs",
                  26);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs26), "lhs", "lhs",
                  26);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 27);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 27);
  sf_mex_assign(&c5_rhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs27, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs27), "rhs", "rhs",
                  27);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs27), "lhs", "lhs",
                  27);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 28);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 28);
  sf_mex_assign(&c5_rhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs28, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs28), "rhs", "rhs",
                  28);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs28), "lhs", "lhs",
                  28);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 29);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 29);
  sf_mex_assign(&c5_rhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs29, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs29), "rhs", "rhs",
                  29);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs29), "lhs", "lhs",
                  29);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 30);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 30);
  sf_mex_assign(&c5_rhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs30, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs30), "rhs", "rhs",
                  30);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs30), "lhs", "lhs",
                  30);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 31);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 31);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 31);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 31);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 31);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 31);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 31);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 31);
  sf_mex_assign(&c5_rhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs31, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs31), "rhs", "rhs",
                  31);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs31), "lhs", "lhs",
                  31);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 32);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 32);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 32);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 32);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 32);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 32);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 32);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 32);
  sf_mex_assign(&c5_rhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs32, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs32), "rhs", "rhs",
                  32);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs32), "lhs", "lhs",
                  32);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 33);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 33);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 33);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 33);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 33);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 33);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 33);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 33);
  sf_mex_assign(&c5_rhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs33, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs33), "rhs", "rhs",
                  33);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs33), "lhs", "lhs",
                  33);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context",
                  "context", 34);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 34);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 34);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 34);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 34);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 34);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 34);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 34);
  sf_mex_assign(&c5_rhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs34, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs34), "rhs", "rhs",
                  34);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs34), "lhs", "lhs",
                  34);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 35);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isfi"), "name", "name", 35);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 35);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved",
                  "resolved", 35);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 35);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 35);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 35);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 35);
  sf_mex_assign(&c5_rhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs35, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs35), "rhs", "rhs",
                  35);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs35), "lhs", "lhs",
                  35);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context",
                  "context", 36);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isnumerictype"), "name",
                  "name", 36);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 36);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                  "resolved", 36);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1398897198U), "fileTimeLo",
                  "fileTimeLo", 36);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 36);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 36);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 36);
  sf_mex_assign(&c5_rhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs36, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs36), "rhs", "rhs",
                  36);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs36), "lhs", "lhs",
                  36);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 37);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 37);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 37);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 37);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 37);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 37);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 37);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 37);
  sf_mex_assign(&c5_rhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs37, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs37), "rhs", "rhs",
                  37);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs37), "lhs", "lhs",
                  37);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                  "context", "context", 38);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmin"), "name", "name", 38);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 38);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 38);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 38);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 38);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 38);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 38);
  sf_mex_assign(&c5_rhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs38, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs38), "rhs", "rhs",
                  38);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs38), "lhs", "lhs",
                  38);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context",
                  "context", 39);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 39);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 39);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 39);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 39);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 39);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 39);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 39);
  sf_mex_assign(&c5_rhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs39, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs39), "rhs", "rhs",
                  39);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs39), "lhs", "lhs",
                  39);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 40);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 40);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 40);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 40);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 40);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 40);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 40);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 40);
  sf_mex_assign(&c5_rhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs40, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs40), "rhs", "rhs",
                  40);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs40), "lhs", "lhs",
                  40);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context",
                  "context", 41);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.prodsize"),
                  "name", "name", 41);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 41);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/prodsize.m"),
                  "resolved", "resolved", 41);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1360304188U), "fileTimeLo",
                  "fileTimeLo", 41);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 41);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 41);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 41);
  sf_mex_assign(&c5_rhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs41, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs41), "rhs", "rhs",
                  41);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs41), "lhs", "lhs",
                  41);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/applyGaitTweaks2.m"),
                  "context", "context", 42);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 42);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 42);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 42);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 42);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 42);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 42);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 42);
  sf_mex_assign(&c5_rhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs42, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs42), "rhs", "rhs",
                  42);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs42), "lhs", "lhs",
                  42);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 43);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 43);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 43);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 43);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 43);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 43);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 43);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 43);
  sf_mex_assign(&c5_rhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs43, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs43), "rhs", "rhs",
                  43);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs43), "lhs", "lhs",
                  43);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 44);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 44);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 44);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 44);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 44);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 44);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 44);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 44);
  sf_mex_assign(&c5_rhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs44, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs44), "rhs", "rhs",
                  44);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs44), "lhs", "lhs",
                  44);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 45);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 45);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 45);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 45);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 45);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 45);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 45);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 45);
  sf_mex_assign(&c5_rhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs45, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs45), "rhs", "rhs",
                  45);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs45), "lhs", "lhs",
                  45);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 46);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  46);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 46);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 46);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 46);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 46);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 46);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 46);
  sf_mex_assign(&c5_rhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs46, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs46), "rhs", "rhs",
                  46);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs46), "lhs", "lhs",
                  46);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 47);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 47);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 47);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 47);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 47);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 47);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 47);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 47);
  sf_mex_assign(&c5_rhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs47, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs47), "rhs", "rhs",
                  47);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs47), "lhs", "lhs",
                  47);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 48);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 48);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 48);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 48);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 48);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 48);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 48);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 48);
  sf_mex_assign(&c5_rhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs48, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs48), "rhs", "rhs",
                  48);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs48), "lhs", "lhs",
                  48);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 49);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 49);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 49);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 49);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 49);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 49);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 49);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 49);
  sf_mex_assign(&c5_rhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs49, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs49), "rhs", "rhs",
                  49);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs49), "lhs", "lhs",
                  49);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 50);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 50);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 50);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 50);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 50);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 50);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 50);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 50);
  sf_mex_assign(&c5_rhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs50, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs50), "rhs", "rhs",
                  50);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs50), "lhs", "lhs",
                  50);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 51);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 51);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 51);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 51);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 51);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 51);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 51);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 51);
  sf_mex_assign(&c5_rhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs51, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs51), "rhs", "rhs",
                  51);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs51), "lhs", "lhs",
                  51);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 52);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 52);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 52);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 52);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 52);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 52);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 52);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 52);
  sf_mex_assign(&c5_rhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs52, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs52), "rhs", "rhs",
                  52);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs52), "lhs", "lhs",
                  52);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 53);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.refblas.xgemm"),
                  "name", "name", 53);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 53);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 53);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 53);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 53);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 53);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 53);
  sf_mex_assign(&c5_rhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs53, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs53), "rhs", "rhs",
                  53);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs53), "lhs", "lhs",
                  53);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 54);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("diag"), "name", "name", 54);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 54);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "resolved",
                  "resolved", 54);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 54);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 54);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 54);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 54);
  sf_mex_assign(&c5_rhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs54, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs54), "rhs", "rhs",
                  54);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs54), "lhs", "lhs",
                  54);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "context",
                  "context", 55);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("ismatrix"), "name", "name", 55);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 55);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 55);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1331326458U), "fileTimeLo",
                  "fileTimeLo", 55);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 55);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 55);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 55);
  sf_mex_assign(&c5_rhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs55, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs55), "rhs", "rhs",
                  55);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs55), "lhs", "lhs",
                  55);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "context",
                  "context", 56);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 56);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 56);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 56);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 56);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 56);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 56);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 56);
  sf_mex_assign(&c5_rhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs56, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs56), "rhs", "rhs",
                  56);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs56), "lhs", "lhs",
                  56);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "context",
                  "context", 57);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 57);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 57);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 57);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 57);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 57);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 57);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 57);
  sf_mex_assign(&c5_rhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs57, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs57), "rhs", "rhs",
                  57);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs57), "lhs", "lhs",
                  57);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/diag.m"), "context",
                  "context", 58);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 58);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 58);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 58);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 58);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 58);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 58);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 58);
  sf_mex_assign(&c5_rhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs58, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs58), "rhs", "rhs",
                  58);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs58), "lhs", "lhs",
                  58);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "context", "context", 59);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("ATRIAS3D_ZD_Control06"),
                  "name", "name", 59);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 59);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Control06.m"),
                  "resolved", "resolved", 59);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837255U), "fileTimeLo",
                  "fileTimeLo", 59);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 59);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 59);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 59);
  sf_mex_assign(&c5_rhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs59, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs59), "rhs", "rhs",
                  59);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs59), "lhs", "lhs",
                  59);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Control06.m"),
                  "context", "context", 60);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("ATRIAS3D_ZD_Output03"), "name",
                  "name", 60);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("struct"), "dominantType",
                  "dominantType", 60);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "resolved", "resolved", 60);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837255U), "fileTimeLo",
                  "fileTimeLo", 60);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 60);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 60);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 60);
  sf_mex_assign(&c5_rhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs60, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs60), "rhs", "rhs",
                  60);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs60), "lhs", "lhs",
                  60);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 61);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("ATRIAS3D_ZD_s6"), "name",
                  "name", 61);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 61);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_s6.m"),
                  "resolved", "resolved", 61);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837256U), "fileTimeLo",
                  "fileTimeLo", 61);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 61);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 61);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 61);
  sf_mex_assign(&c5_rhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs61, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs61), "rhs", "rhs",
                  61);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs61), "lhs", "lhs",
                  61);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_s6.m"),
                  "context", "context", 62);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("iscolumn"), "name", "name", 62);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 62);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/iscolumn.m"), "resolved",
                  "resolved", 62);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1346531958U), "fileTimeLo",
                  "fileTimeLo", 62);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 62);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 62);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 62);
  sf_mex_assign(&c5_rhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs62, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs62), "rhs", "rhs",
                  62);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs62), "lhs", "lhs",
                  62);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_s6.m"),
                  "context", "context", 63);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 63);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 63);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 63);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 63);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 63);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 63);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 63);
  sf_mex_assign(&c5_rhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs63, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs63), "rhs", "rhs",
                  63);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs63), "lhs", "lhs",
                  63);
  sf_mex_destroy(&c5_rhs0);
  sf_mex_destroy(&c5_lhs0);
  sf_mex_destroy(&c5_rhs1);
  sf_mex_destroy(&c5_lhs1);
  sf_mex_destroy(&c5_rhs2);
  sf_mex_destroy(&c5_lhs2);
  sf_mex_destroy(&c5_rhs3);
  sf_mex_destroy(&c5_lhs3);
  sf_mex_destroy(&c5_rhs4);
  sf_mex_destroy(&c5_lhs4);
  sf_mex_destroy(&c5_rhs5);
  sf_mex_destroy(&c5_lhs5);
  sf_mex_destroy(&c5_rhs6);
  sf_mex_destroy(&c5_lhs6);
  sf_mex_destroy(&c5_rhs7);
  sf_mex_destroy(&c5_lhs7);
  sf_mex_destroy(&c5_rhs8);
  sf_mex_destroy(&c5_lhs8);
  sf_mex_destroy(&c5_rhs9);
  sf_mex_destroy(&c5_lhs9);
  sf_mex_destroy(&c5_rhs10);
  sf_mex_destroy(&c5_lhs10);
  sf_mex_destroy(&c5_rhs11);
  sf_mex_destroy(&c5_lhs11);
  sf_mex_destroy(&c5_rhs12);
  sf_mex_destroy(&c5_lhs12);
  sf_mex_destroy(&c5_rhs13);
  sf_mex_destroy(&c5_lhs13);
  sf_mex_destroy(&c5_rhs14);
  sf_mex_destroy(&c5_lhs14);
  sf_mex_destroy(&c5_rhs15);
  sf_mex_destroy(&c5_lhs15);
  sf_mex_destroy(&c5_rhs16);
  sf_mex_destroy(&c5_lhs16);
  sf_mex_destroy(&c5_rhs17);
  sf_mex_destroy(&c5_lhs17);
  sf_mex_destroy(&c5_rhs18);
  sf_mex_destroy(&c5_lhs18);
  sf_mex_destroy(&c5_rhs19);
  sf_mex_destroy(&c5_lhs19);
  sf_mex_destroy(&c5_rhs20);
  sf_mex_destroy(&c5_lhs20);
  sf_mex_destroy(&c5_rhs21);
  sf_mex_destroy(&c5_lhs21);
  sf_mex_destroy(&c5_rhs22);
  sf_mex_destroy(&c5_lhs22);
  sf_mex_destroy(&c5_rhs23);
  sf_mex_destroy(&c5_lhs23);
  sf_mex_destroy(&c5_rhs24);
  sf_mex_destroy(&c5_lhs24);
  sf_mex_destroy(&c5_rhs25);
  sf_mex_destroy(&c5_lhs25);
  sf_mex_destroy(&c5_rhs26);
  sf_mex_destroy(&c5_lhs26);
  sf_mex_destroy(&c5_rhs27);
  sf_mex_destroy(&c5_lhs27);
  sf_mex_destroy(&c5_rhs28);
  sf_mex_destroy(&c5_lhs28);
  sf_mex_destroy(&c5_rhs29);
  sf_mex_destroy(&c5_lhs29);
  sf_mex_destroy(&c5_rhs30);
  sf_mex_destroy(&c5_lhs30);
  sf_mex_destroy(&c5_rhs31);
  sf_mex_destroy(&c5_lhs31);
  sf_mex_destroy(&c5_rhs32);
  sf_mex_destroy(&c5_lhs32);
  sf_mex_destroy(&c5_rhs33);
  sf_mex_destroy(&c5_lhs33);
  sf_mex_destroy(&c5_rhs34);
  sf_mex_destroy(&c5_lhs34);
  sf_mex_destroy(&c5_rhs35);
  sf_mex_destroy(&c5_lhs35);
  sf_mex_destroy(&c5_rhs36);
  sf_mex_destroy(&c5_lhs36);
  sf_mex_destroy(&c5_rhs37);
  sf_mex_destroy(&c5_lhs37);
  sf_mex_destroy(&c5_rhs38);
  sf_mex_destroy(&c5_lhs38);
  sf_mex_destroy(&c5_rhs39);
  sf_mex_destroy(&c5_lhs39);
  sf_mex_destroy(&c5_rhs40);
  sf_mex_destroy(&c5_lhs40);
  sf_mex_destroy(&c5_rhs41);
  sf_mex_destroy(&c5_lhs41);
  sf_mex_destroy(&c5_rhs42);
  sf_mex_destroy(&c5_lhs42);
  sf_mex_destroy(&c5_rhs43);
  sf_mex_destroy(&c5_lhs43);
  sf_mex_destroy(&c5_rhs44);
  sf_mex_destroy(&c5_lhs44);
  sf_mex_destroy(&c5_rhs45);
  sf_mex_destroy(&c5_lhs45);
  sf_mex_destroy(&c5_rhs46);
  sf_mex_destroy(&c5_lhs46);
  sf_mex_destroy(&c5_rhs47);
  sf_mex_destroy(&c5_lhs47);
  sf_mex_destroy(&c5_rhs48);
  sf_mex_destroy(&c5_lhs48);
  sf_mex_destroy(&c5_rhs49);
  sf_mex_destroy(&c5_lhs49);
  sf_mex_destroy(&c5_rhs50);
  sf_mex_destroy(&c5_lhs50);
  sf_mex_destroy(&c5_rhs51);
  sf_mex_destroy(&c5_lhs51);
  sf_mex_destroy(&c5_rhs52);
  sf_mex_destroy(&c5_lhs52);
  sf_mex_destroy(&c5_rhs53);
  sf_mex_destroy(&c5_lhs53);
  sf_mex_destroy(&c5_rhs54);
  sf_mex_destroy(&c5_lhs54);
  sf_mex_destroy(&c5_rhs55);
  sf_mex_destroy(&c5_lhs55);
  sf_mex_destroy(&c5_rhs56);
  sf_mex_destroy(&c5_lhs56);
  sf_mex_destroy(&c5_rhs57);
  sf_mex_destroy(&c5_lhs57);
  sf_mex_destroy(&c5_rhs58);
  sf_mex_destroy(&c5_lhs58);
  sf_mex_destroy(&c5_rhs59);
  sf_mex_destroy(&c5_lhs59);
  sf_mex_destroy(&c5_rhs60);
  sf_mex_destroy(&c5_lhs60);
  sf_mex_destroy(&c5_rhs61);
  sf_mex_destroy(&c5_lhs61);
  sf_mex_destroy(&c5_rhs62);
  sf_mex_destroy(&c5_lhs62);
  sf_mex_destroy(&c5_rhs63);
  sf_mex_destroy(&c5_lhs63);
}

static const mxArray *c5_emlrt_marshallOut(const char * c5_b_u)
{
  const mxArray *c5_b_y = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 15, 0U, 0U, 0U, 2, 1, strlen
                 (c5_b_u)), false);
  return c5_b_y;
}

static const mxArray *c5_b_emlrt_marshallOut(const uint32_T c5_b_u)
{
  const mxArray *c5_b_y = NULL;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 7, 0U, 0U, 0U, 0), false);
  return c5_b_y;
}

static void c5_b_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs64 = NULL;
  const mxArray *c5_lhs64 = NULL;
  const mxArray *c5_rhs65 = NULL;
  const mxArray *c5_lhs65 = NULL;
  const mxArray *c5_rhs66 = NULL;
  const mxArray *c5_lhs66 = NULL;
  const mxArray *c5_rhs67 = NULL;
  const mxArray *c5_lhs67 = NULL;
  const mxArray *c5_rhs68 = NULL;
  const mxArray *c5_lhs68 = NULL;
  const mxArray *c5_rhs69 = NULL;
  const mxArray *c5_lhs69 = NULL;
  const mxArray *c5_rhs70 = NULL;
  const mxArray *c5_lhs70 = NULL;
  const mxArray *c5_rhs71 = NULL;
  const mxArray *c5_lhs71 = NULL;
  const mxArray *c5_rhs72 = NULL;
  const mxArray *c5_lhs72 = NULL;
  const mxArray *c5_rhs73 = NULL;
  const mxArray *c5_lhs73 = NULL;
  const mxArray *c5_rhs74 = NULL;
  const mxArray *c5_lhs74 = NULL;
  const mxArray *c5_rhs75 = NULL;
  const mxArray *c5_lhs75 = NULL;
  const mxArray *c5_rhs76 = NULL;
  const mxArray *c5_lhs76 = NULL;
  const mxArray *c5_rhs77 = NULL;
  const mxArray *c5_lhs77 = NULL;
  const mxArray *c5_rhs78 = NULL;
  const mxArray *c5_lhs78 = NULL;
  const mxArray *c5_rhs79 = NULL;
  const mxArray *c5_lhs79 = NULL;
  const mxArray *c5_rhs80 = NULL;
  const mxArray *c5_lhs80 = NULL;
  const mxArray *c5_rhs81 = NULL;
  const mxArray *c5_lhs81 = NULL;
  const mxArray *c5_rhs82 = NULL;
  const mxArray *c5_lhs82 = NULL;
  const mxArray *c5_rhs83 = NULL;
  const mxArray *c5_lhs83 = NULL;
  const mxArray *c5_rhs84 = NULL;
  const mxArray *c5_lhs84 = NULL;
  const mxArray *c5_rhs85 = NULL;
  const mxArray *c5_lhs85 = NULL;
  const mxArray *c5_rhs86 = NULL;
  const mxArray *c5_lhs86 = NULL;
  const mxArray *c5_rhs87 = NULL;
  const mxArray *c5_lhs87 = NULL;
  const mxArray *c5_rhs88 = NULL;
  const mxArray *c5_lhs88 = NULL;
  const mxArray *c5_rhs89 = NULL;
  const mxArray *c5_lhs89 = NULL;
  const mxArray *c5_rhs90 = NULL;
  const mxArray *c5_lhs90 = NULL;
  const mxArray *c5_rhs91 = NULL;
  const mxArray *c5_lhs91 = NULL;
  const mxArray *c5_rhs92 = NULL;
  const mxArray *c5_lhs92 = NULL;
  const mxArray *c5_rhs93 = NULL;
  const mxArray *c5_lhs93 = NULL;
  const mxArray *c5_rhs94 = NULL;
  const mxArray *c5_lhs94 = NULL;
  const mxArray *c5_rhs95 = NULL;
  const mxArray *c5_lhs95 = NULL;
  const mxArray *c5_rhs96 = NULL;
  const mxArray *c5_lhs96 = NULL;
  const mxArray *c5_rhs97 = NULL;
  const mxArray *c5_lhs97 = NULL;
  const mxArray *c5_rhs98 = NULL;
  const mxArray *c5_lhs98 = NULL;
  const mxArray *c5_rhs99 = NULL;
  const mxArray *c5_lhs99 = NULL;
  const mxArray *c5_rhs100 = NULL;
  const mxArray *c5_lhs100 = NULL;
  const mxArray *c5_rhs101 = NULL;
  const mxArray *c5_lhs101 = NULL;
  const mxArray *c5_rhs102 = NULL;
  const mxArray *c5_lhs102 = NULL;
  const mxArray *c5_rhs103 = NULL;
  const mxArray *c5_lhs103 = NULL;
  const mxArray *c5_rhs104 = NULL;
  const mxArray *c5_lhs104 = NULL;
  const mxArray *c5_rhs105 = NULL;
  const mxArray *c5_lhs105 = NULL;
  const mxArray *c5_rhs106 = NULL;
  const mxArray *c5_lhs106 = NULL;
  const mxArray *c5_rhs107 = NULL;
  const mxArray *c5_lhs107 = NULL;
  const mxArray *c5_rhs108 = NULL;
  const mxArray *c5_lhs108 = NULL;
  const mxArray *c5_rhs109 = NULL;
  const mxArray *c5_lhs109 = NULL;
  const mxArray *c5_rhs110 = NULL;
  const mxArray *c5_lhs110 = NULL;
  const mxArray *c5_rhs111 = NULL;
  const mxArray *c5_lhs111 = NULL;
  const mxArray *c5_rhs112 = NULL;
  const mxArray *c5_lhs112 = NULL;
  const mxArray *c5_rhs113 = NULL;
  const mxArray *c5_lhs113 = NULL;
  const mxArray *c5_rhs114 = NULL;
  const mxArray *c5_lhs114 = NULL;
  const mxArray *c5_rhs115 = NULL;
  const mxArray *c5_lhs115 = NULL;
  const mxArray *c5_rhs116 = NULL;
  const mxArray *c5_lhs116 = NULL;
  const mxArray *c5_rhs117 = NULL;
  const mxArray *c5_lhs117 = NULL;
  const mxArray *c5_rhs118 = NULL;
  const mxArray *c5_lhs118 = NULL;
  const mxArray *c5_rhs119 = NULL;
  const mxArray *c5_lhs119 = NULL;
  const mxArray *c5_rhs120 = NULL;
  const mxArray *c5_lhs120 = NULL;
  const mxArray *c5_rhs121 = NULL;
  const mxArray *c5_lhs121 = NULL;
  const mxArray *c5_rhs122 = NULL;
  const mxArray *c5_lhs122 = NULL;
  const mxArray *c5_rhs123 = NULL;
  const mxArray *c5_lhs123 = NULL;
  const mxArray *c5_rhs124 = NULL;
  const mxArray *c5_lhs124 = NULL;
  const mxArray *c5_rhs125 = NULL;
  const mxArray *c5_lhs125 = NULL;
  const mxArray *c5_rhs126 = NULL;
  const mxArray *c5_lhs126 = NULL;
  const mxArray *c5_rhs127 = NULL;
  const mxArray *c5_lhs127 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 64);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 64);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 64);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 64);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 64);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 64);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 64);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 64);
  sf_mex_assign(&c5_rhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs64, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs64), "rhs", "rhs",
                  64);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs64), "lhs", "lhs",
                  64);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 65);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_xdotu"), "name", "name",
                  65);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 65);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"),
                  "resolved", "resolved", 65);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 65);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 65);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 65);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 65);
  sf_mex_assign(&c5_rhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs65, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs65), "rhs", "rhs",
                  65);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs65), "lhs", "lhs",
                  65);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 66);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 66);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 66);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 66);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 66);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 66);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 66);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 66);
  sf_mex_assign(&c5_rhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs66, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs66), "rhs", "rhs",
                  66);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs66), "lhs", "lhs",
                  66);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xdotu.m"), "context",
                  "context", 67);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.xdotu"),
                  "name", "name", 67);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 67);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "resolved", "resolved", 67);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 67);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 67);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 67);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 67);
  sf_mex_assign(&c5_rhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs67, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs67), "rhs", "rhs",
                  67);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs67), "lhs", "lhs",
                  67);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdotu.p"),
                  "context", "context", 68);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.xdot"),
                  "name", "name", 68);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 68);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "resolved", "resolved", 68);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 68);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 68);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 68);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 68);
  sf_mex_assign(&c5_rhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs68, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs68), "rhs", "rhs",
                  68);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs68), "lhs", "lhs",
                  68);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 69);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 69);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 69);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 69);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 69);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 69);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 69);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 69);
  sf_mex_assign(&c5_rhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs69, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs69), "rhs", "rhs",
                  69);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs69), "lhs", "lhs",
                  69);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p!below_threshold"),
                  "context", "context", 70);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 70);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 70);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 70);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 70);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 70);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 70);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 70);
  sf_mex_assign(&c5_rhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs70, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs70), "rhs", "rhs",
                  70);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs70), "lhs", "lhs",
                  70);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xdot.p"),
                  "context", "context", 71);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.refblas.xdot"),
                  "name", "name", 71);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 71);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "resolved", "resolved", 71);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 71);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 71);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 71);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 71);
  sf_mex_assign(&c5_rhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs71, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs71), "rhs", "rhs",
                  71);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs71), "lhs", "lhs",
                  71);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdot.p"),
                  "context", "context", 72);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.refblas.xdotx"),
                  "name", "name", 72);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 72);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "resolved", "resolved", 72);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 72);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 72);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 72);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 72);
  sf_mex_assign(&c5_rhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs72, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs72), "rhs", "rhs",
                  72);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs72), "lhs", "lhs",
                  72);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 73);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 73);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 73);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 73);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 73);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 73);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 73);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 73);
  sf_mex_assign(&c5_rhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs73, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs73), "rhs", "rhs",
                  73);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs73), "lhs", "lhs",
                  73);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 74);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 74);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 74);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 74);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 74);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 74);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 74);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 74);
  sf_mex_assign(&c5_rhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs74, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs74), "rhs", "rhs",
                  74);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs74), "lhs", "lhs",
                  74);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 75);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 75);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 75);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 75);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 75);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 75);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 75);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 75);
  sf_mex_assign(&c5_rhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs75, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs75), "rhs", "rhs",
                  75);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs75), "lhs", "lhs",
                  75);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 76);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 76);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 76);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 76);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 76);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 76);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 76);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 76);
  sf_mex_assign(&c5_rhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs76, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs76), "rhs", "rhs",
                  76);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs76), "lhs", "lhs",
                  76);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xdotx.p"),
                  "context", "context", 77);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 77);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 77);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 77);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 77);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 77);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 77);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 77);
  sf_mex_assign(&c5_rhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs77, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs77), "rhs", "rhs",
                  77);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs77), "lhs", "lhs",
                  77);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_s6.m"),
                  "context", "context", 78);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("rdivide"), "name", "name", 78);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 78);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 78);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 78);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 78);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 78);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 78);
  sf_mex_assign(&c5_rhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs78, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs78), "rhs", "rhs",
                  78);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs78), "lhs", "lhs",
                  78);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_s6.m"),
                  "context", "context", 79);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("length"), "name", "name", 79);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 79);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 79);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 79);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 79);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 79);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 79);
  sf_mex_assign(&c5_rhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs79, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs79), "rhs", "rhs",
                  79);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs79), "lhs", "lhs",
                  79);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "context", "context", 80);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isequal"), "name", "name", 80);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 80);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 80);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840358U), "fileTimeLo",
                  "fileTimeLo", 80);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 80);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 80);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 80);
  sf_mex_assign(&c5_rhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs80, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs80), "rhs", "rhs",
                  80);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs80), "lhs", "lhs",
                  80);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context",
                  "context", 81);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_isequal_core"), "name",
                  "name", 81);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 81);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                  "resolved", "resolved", 81);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 81);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 81);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 81);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 81);
  sf_mex_assign(&c5_rhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs81, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs81), "rhs", "rhs",
                  81);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs81), "lhs", "lhs",
                  81);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                  "context", "context", 82);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isnan"), "name", "name", 82);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 82);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 82);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 82);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 82);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 82);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 82);
  sf_mex_assign(&c5_rhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs82, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs82), "rhs", "rhs",
                  82);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs82), "lhs", "lhs",
                  82);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 83);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 83);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 83);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 83);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 83);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 83);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 83);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 83);
  sf_mex_assign(&c5_rhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs83, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs83), "rhs", "rhs",
                  83);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs83), "lhs", "lhs",
                  83);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 84);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("max"), "name", "name", 84);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 84);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 84);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 84);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 84);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 84);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 84);
  sf_mex_assign(&c5_rhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs84, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs84), "rhs", "rhs",
                  84);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs84), "lhs", "lhs",
                  84);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 85);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 85);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 85);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 85);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 85);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 85);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 85);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 85);
  sf_mex_assign(&c5_rhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs85, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs85), "rhs", "rhs",
                  85);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs85), "lhs", "lhs",
                  85);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 86);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 86);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 86);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 86);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 86);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 86);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 86);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 86);
  sf_mex_assign(&c5_rhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs86, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs86), "rhs", "rhs",
                  86);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs86), "lhs", "lhs",
                  86);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 87);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 87);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 87);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 87);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 87);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 87);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 87);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 87);
  sf_mex_assign(&c5_rhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs87, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs87), "rhs", "rhs",
                  87);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs87), "lhs", "lhs",
                  87);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 88);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 88);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 88);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 88);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 88);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 88);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 88);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 88);
  sf_mex_assign(&c5_rhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs88, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs88), "rhs", "rhs",
                  88);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs88), "lhs", "lhs",
                  88);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                  "context", "context", 89);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 89);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 89);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 89);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 89);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 89);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 89);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 89);
  sf_mex_assign(&c5_rhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs89, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs89), "rhs", "rhs",
                  89);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs89), "lhs", "lhs",
                  89);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 90);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_li_find"), "name", "name",
                  90);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 90);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "resolved",
                  "resolved", 90);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 90);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 90);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 90);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 90);
  sf_mex_assign(&c5_rhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs90, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs90), "rhs", "rhs",
                  90);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs90), "lhs", "lhs",
                  90);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 91);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 91);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 91);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 91);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 91);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 91);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 91);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 91);
  sf_mex_assign(&c5_rhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs91, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs91), "rhs", "rhs",
                  91);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs91), "lhs", "lhs",
                  91);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 92);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 92);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 92);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 92);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 92);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 92);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 92);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 92);
  sf_mex_assign(&c5_rhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs92, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs92), "rhs", "rhs",
                  92);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs92), "lhs", "lhs",
                  92);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 93);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 93);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 93);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 93);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 93);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 93);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 93);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 93);
  sf_mex_assign(&c5_rhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs93, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs93), "rhs", "rhs",
                  93);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs93), "lhs", "lhs",
                  93);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 94);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 94);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 94);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 94);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 94);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 94);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 94);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 94);
  sf_mex_assign(&c5_rhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs94, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs94), "rhs", "rhs",
                  94);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs94), "lhs", "lhs",
                  94);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 95);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 95);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 95);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 95);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 95);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 95);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 95);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 95);
  sf_mex_assign(&c5_rhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs95, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs95), "rhs", "rhs",
                  95);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs95), "lhs", "lhs",
                  95);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 96);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("length"), "name", "name", 96);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 96);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 96);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 96);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 96);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 96);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 96);
  sf_mex_assign(&c5_rhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs96, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs96), "rhs", "rhs",
                  96);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs96), "lhs", "lhs",
                  96);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 97);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("repmat"), "name", "name", 97);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 97);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "resolved",
                  "resolved", 97);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604014U), "fileTimeLo",
                  "fileTimeLo", 97);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 97);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 97);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 97);
  sf_mex_assign(&c5_rhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs97, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs97), "rhs", "rhs",
                  97);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs97), "lhs", "lhs",
                  97);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 98);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 98);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 98);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 98);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 98);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 98);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 98);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 98);
  sf_mex_assign(&c5_rhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs98, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs98), "rhs", "rhs",
                  98);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs98), "lhs", "lhs",
                  98);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 99);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("colon"), "name", "name", 99);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 99);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 99);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 99);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 99);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 99);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 99);
  sf_mex_assign(&c5_rhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs99, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs99), "rhs", "rhs",
                  99);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs99), "lhs", "lhs",
                  99);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 100);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 100);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 100);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 100);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 100);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 100);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 100);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 100);
  sf_mex_assign(&c5_rhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs100, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs100), "rhs", "rhs",
                  100);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs100), "lhs", "lhs",
                  100);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                  "context", "context", 101);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isfinite"), "name", "name",
                  101);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 101);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                  "resolved", 101);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 101);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 101);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 101);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 101);
  sf_mex_assign(&c5_rhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs101, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs101), "rhs", "rhs",
                  101);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs101), "lhs", "lhs",
                  101);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 102);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 102);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 102);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 102);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 102);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 102);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 102);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 102);
  sf_mex_assign(&c5_rhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs102, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs102), "rhs", "rhs",
                  102);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs102), "lhs", "lhs",
                  102);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 103);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isinf"), "name", "name", 103);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 103);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 103);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 103);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 103);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 103);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 103);
  sf_mex_assign(&c5_rhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs103, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs103), "rhs", "rhs",
                  103);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs103), "lhs", "lhs",
                  103);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                  "context", 104);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isnan"), "name", "name", 104);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 104);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 104);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 104);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 104);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 104);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 104);
  sf_mex_assign(&c5_rhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs104, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs104), "rhs", "rhs",
                  104);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs104), "lhs", "lhs",
                  104);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!is_flint_colon"),
                  "context", "context", 105);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("floor"), "name", "name", 105);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 105);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 105);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 105);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 105);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 105);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 105);
  sf_mex_assign(&c5_rhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs105, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs105), "rhs", "rhs",
                  105);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs105), "lhs", "lhs",
                  105);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 106);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 106);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 106);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 106);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 106);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 106);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 106);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 106);
  sf_mex_assign(&c5_rhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs106, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs106), "rhs", "rhs",
                  106);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs106), "lhs", "lhs",
                  106);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 107);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 107);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 107);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 107);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 107);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 107);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 107);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 107);
  sf_mex_assign(&c5_rhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs107, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs107), "rhs", "rhs",
                  107);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs107), "lhs", "lhs",
                  107);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 108);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("realmax"), "name", "name", 108);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 108);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                  "resolved", 108);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 108);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 108);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 108);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 108);
  sf_mex_assign(&c5_rhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs108, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs108), "rhs", "rhs",
                  108);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs108), "lhs", "lhs",
                  108);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context",
                  "context", 109);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_realmax"), "name", "name",
                  109);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 109);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                  "resolved", 109);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 109);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 109);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 109);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 109);
  sf_mex_assign(&c5_rhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs109, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs109), "rhs", "rhs",
                  109);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs109), "lhs", "lhs",
                  109);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                  "context", 110);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 110);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 110);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 110);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 110);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 110);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 110);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 110);
  sf_mex_assign(&c5_rhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs110, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs110), "rhs", "rhs",
                  110);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs110), "lhs", "lhs",
                  110);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 111);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isnan"), "name", "name", 111);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 111);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 111);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 111);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 111);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 111);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 111);
  sf_mex_assign(&c5_rhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs111, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs111), "rhs", "rhs",
                  111);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs111), "lhs", "lhs",
                  111);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 112);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isinf"), "name", "name", 112);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 112);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved",
                  "resolved", 112);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731856U), "fileTimeLo",
                  "fileTimeLo", 112);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 112);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 112);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 112);
  sf_mex_assign(&c5_rhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs112, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs112), "rhs", "rhs",
                  112);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs112), "lhs", "lhs",
                  112);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 113);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("floor"), "name", "name", 113);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 113);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 113);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 113);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 113);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 113);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 113);
  sf_mex_assign(&c5_rhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs113, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs113), "rhs", "rhs",
                  113);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs113), "lhs", "lhs",
                  113);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 114);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("abs"), "name", "name", 114);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 114);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 114);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 114);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 114);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 114);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 114);
  sf_mex_assign(&c5_rhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs114, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs114), "rhs", "rhs",
                  114);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs114), "lhs", "lhs",
                  114);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 115);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 115);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 115);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 115);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 115);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 115);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 115);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 115);
  sf_mex_assign(&c5_rhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs115, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs115), "rhs", "rhs",
                  115);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs115), "lhs", "lhs",
                  115);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 116);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 116);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 116);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 116);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 116);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 116);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 116);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 116);
  sf_mex_assign(&c5_rhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs116, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs116), "rhs", "rhs",
                  116);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs116), "lhs", "lhs",
                  116);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 117);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eps"), "name", "name", 117);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 117);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 117);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 117);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 117);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 117);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 117);
  sf_mex_assign(&c5_rhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs117, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs117), "rhs", "rhs",
                  117);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs117), "lhs", "lhs",
                  117);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 118);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_is_float_class"), "name",
                  "name", 118);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 118);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                  "resolved", "resolved", 118);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840382U), "fileTimeLo",
                  "fileTimeLo", 118);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 118);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 118);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 118);
  sf_mex_assign(&c5_rhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs118, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs118), "rhs", "rhs",
                  118);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs118), "lhs", "lhs",
                  118);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context",
                  "context", 119);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_eps"), "name", "name", 119);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 119);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved",
                  "resolved", 119);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 119);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 119);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 119);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 119);
  sf_mex_assign(&c5_rhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs119, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs119), "rhs", "rhs",
                  119);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs119), "lhs", "lhs",
                  119);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context",
                  "context", 120);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 120);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 120);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 120);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 120);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 120);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 120);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 120);
  sf_mex_assign(&c5_rhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs120, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs120), "rhs", "rhs",
                  120);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs120), "lhs", "lhs",
                  120);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!maxabs"), "context",
                  "context", 121);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("abs"), "name", "name", 121);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 121);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 121);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 121);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 121);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 121);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 121);
  sf_mex_assign(&c5_rhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs121, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs121), "rhs", "rhs",
                  121);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs121), "lhs", "lhs",
                  121);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 122);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 122);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 122);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 122);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 122);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 122);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 122);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 122);
  sf_mex_assign(&c5_rhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs122, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs122), "rhs", "rhs",
                  122);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs122), "lhs", "lhs",
                  122);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 123);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 123);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 123);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 123);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 123);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 123);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 123);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 123);
  sf_mex_assign(&c5_rhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs123, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs123), "rhs", "rhs",
                  123);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs123), "lhs", "lhs",
                  123);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!float_colon_length"),
                  "context", "context", 124);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexIntRelop"),
                  "name", "name", 124);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 124);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                  "resolved", "resolved", 124);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1326749922U), "fileTimeLo",
                  "fileTimeLo", 124);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 124);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 124);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 124);
  sf_mex_assign(&c5_rhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs124, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs124), "rhs", "rhs",
                  124);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs124), "lhs", "lhs",
                  124);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon"),
                  "context", "context", 125);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 125);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 125);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 125);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 125);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 125);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 125);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 125);
  sf_mex_assign(&c5_rhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs125, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs125), "rhs", "rhs",
                  125);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs125), "lhs", "lhs",
                  125);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 126);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 126);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 126);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 126);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 126);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 126);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 126);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 126);
  sf_mex_assign(&c5_rhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs126, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs126), "rhs", "rhs",
                  126);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs126), "lhs", "lhs",
                  126);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon"),
                  "context", "context", 127);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_rdivide"), "name",
                  "name", 127);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 127);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "resolved", "resolved", 127);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 127);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 127);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 127);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 127);
  sf_mex_assign(&c5_rhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs127, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs127), "rhs", "rhs",
                  127);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs127), "lhs", "lhs",
                  127);
  sf_mex_destroy(&c5_rhs64);
  sf_mex_destroy(&c5_lhs64);
  sf_mex_destroy(&c5_rhs65);
  sf_mex_destroy(&c5_lhs65);
  sf_mex_destroy(&c5_rhs66);
  sf_mex_destroy(&c5_lhs66);
  sf_mex_destroy(&c5_rhs67);
  sf_mex_destroy(&c5_lhs67);
  sf_mex_destroy(&c5_rhs68);
  sf_mex_destroy(&c5_lhs68);
  sf_mex_destroy(&c5_rhs69);
  sf_mex_destroy(&c5_lhs69);
  sf_mex_destroy(&c5_rhs70);
  sf_mex_destroy(&c5_lhs70);
  sf_mex_destroy(&c5_rhs71);
  sf_mex_destroy(&c5_lhs71);
  sf_mex_destroy(&c5_rhs72);
  sf_mex_destroy(&c5_lhs72);
  sf_mex_destroy(&c5_rhs73);
  sf_mex_destroy(&c5_lhs73);
  sf_mex_destroy(&c5_rhs74);
  sf_mex_destroy(&c5_lhs74);
  sf_mex_destroy(&c5_rhs75);
  sf_mex_destroy(&c5_lhs75);
  sf_mex_destroy(&c5_rhs76);
  sf_mex_destroy(&c5_lhs76);
  sf_mex_destroy(&c5_rhs77);
  sf_mex_destroy(&c5_lhs77);
  sf_mex_destroy(&c5_rhs78);
  sf_mex_destroy(&c5_lhs78);
  sf_mex_destroy(&c5_rhs79);
  sf_mex_destroy(&c5_lhs79);
  sf_mex_destroy(&c5_rhs80);
  sf_mex_destroy(&c5_lhs80);
  sf_mex_destroy(&c5_rhs81);
  sf_mex_destroy(&c5_lhs81);
  sf_mex_destroy(&c5_rhs82);
  sf_mex_destroy(&c5_lhs82);
  sf_mex_destroy(&c5_rhs83);
  sf_mex_destroy(&c5_lhs83);
  sf_mex_destroy(&c5_rhs84);
  sf_mex_destroy(&c5_lhs84);
  sf_mex_destroy(&c5_rhs85);
  sf_mex_destroy(&c5_lhs85);
  sf_mex_destroy(&c5_rhs86);
  sf_mex_destroy(&c5_lhs86);
  sf_mex_destroy(&c5_rhs87);
  sf_mex_destroy(&c5_lhs87);
  sf_mex_destroy(&c5_rhs88);
  sf_mex_destroy(&c5_lhs88);
  sf_mex_destroy(&c5_rhs89);
  sf_mex_destroy(&c5_lhs89);
  sf_mex_destroy(&c5_rhs90);
  sf_mex_destroy(&c5_lhs90);
  sf_mex_destroy(&c5_rhs91);
  sf_mex_destroy(&c5_lhs91);
  sf_mex_destroy(&c5_rhs92);
  sf_mex_destroy(&c5_lhs92);
  sf_mex_destroy(&c5_rhs93);
  sf_mex_destroy(&c5_lhs93);
  sf_mex_destroy(&c5_rhs94);
  sf_mex_destroy(&c5_lhs94);
  sf_mex_destroy(&c5_rhs95);
  sf_mex_destroy(&c5_lhs95);
  sf_mex_destroy(&c5_rhs96);
  sf_mex_destroy(&c5_lhs96);
  sf_mex_destroy(&c5_rhs97);
  sf_mex_destroy(&c5_lhs97);
  sf_mex_destroy(&c5_rhs98);
  sf_mex_destroy(&c5_lhs98);
  sf_mex_destroy(&c5_rhs99);
  sf_mex_destroy(&c5_lhs99);
  sf_mex_destroy(&c5_rhs100);
  sf_mex_destroy(&c5_lhs100);
  sf_mex_destroy(&c5_rhs101);
  sf_mex_destroy(&c5_lhs101);
  sf_mex_destroy(&c5_rhs102);
  sf_mex_destroy(&c5_lhs102);
  sf_mex_destroy(&c5_rhs103);
  sf_mex_destroy(&c5_lhs103);
  sf_mex_destroy(&c5_rhs104);
  sf_mex_destroy(&c5_lhs104);
  sf_mex_destroy(&c5_rhs105);
  sf_mex_destroy(&c5_lhs105);
  sf_mex_destroy(&c5_rhs106);
  sf_mex_destroy(&c5_lhs106);
  sf_mex_destroy(&c5_rhs107);
  sf_mex_destroy(&c5_lhs107);
  sf_mex_destroy(&c5_rhs108);
  sf_mex_destroy(&c5_lhs108);
  sf_mex_destroy(&c5_rhs109);
  sf_mex_destroy(&c5_lhs109);
  sf_mex_destroy(&c5_rhs110);
  sf_mex_destroy(&c5_lhs110);
  sf_mex_destroy(&c5_rhs111);
  sf_mex_destroy(&c5_lhs111);
  sf_mex_destroy(&c5_rhs112);
  sf_mex_destroy(&c5_lhs112);
  sf_mex_destroy(&c5_rhs113);
  sf_mex_destroy(&c5_lhs113);
  sf_mex_destroy(&c5_rhs114);
  sf_mex_destroy(&c5_lhs114);
  sf_mex_destroy(&c5_rhs115);
  sf_mex_destroy(&c5_lhs115);
  sf_mex_destroy(&c5_rhs116);
  sf_mex_destroy(&c5_lhs116);
  sf_mex_destroy(&c5_rhs117);
  sf_mex_destroy(&c5_lhs117);
  sf_mex_destroy(&c5_rhs118);
  sf_mex_destroy(&c5_lhs118);
  sf_mex_destroy(&c5_rhs119);
  sf_mex_destroy(&c5_lhs119);
  sf_mex_destroy(&c5_rhs120);
  sf_mex_destroy(&c5_lhs120);
  sf_mex_destroy(&c5_rhs121);
  sf_mex_destroy(&c5_lhs121);
  sf_mex_destroy(&c5_rhs122);
  sf_mex_destroy(&c5_lhs122);
  sf_mex_destroy(&c5_rhs123);
  sf_mex_destroy(&c5_lhs123);
  sf_mex_destroy(&c5_rhs124);
  sf_mex_destroy(&c5_lhs124);
  sf_mex_destroy(&c5_rhs125);
  sf_mex_destroy(&c5_lhs125);
  sf_mex_destroy(&c5_rhs126);
  sf_mex_destroy(&c5_lhs126);
  sf_mex_destroy(&c5_rhs127);
  sf_mex_destroy(&c5_lhs127);
}

static void c5_c_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs128 = NULL;
  const mxArray *c5_lhs128 = NULL;
  const mxArray *c5_rhs129 = NULL;
  const mxArray *c5_lhs129 = NULL;
  const mxArray *c5_rhs130 = NULL;
  const mxArray *c5_lhs130 = NULL;
  const mxArray *c5_rhs131 = NULL;
  const mxArray *c5_lhs131 = NULL;
  const mxArray *c5_rhs132 = NULL;
  const mxArray *c5_lhs132 = NULL;
  const mxArray *c5_rhs133 = NULL;
  const mxArray *c5_lhs133 = NULL;
  const mxArray *c5_rhs134 = NULL;
  const mxArray *c5_lhs134 = NULL;
  const mxArray *c5_rhs135 = NULL;
  const mxArray *c5_lhs135 = NULL;
  const mxArray *c5_rhs136 = NULL;
  const mxArray *c5_lhs136 = NULL;
  const mxArray *c5_rhs137 = NULL;
  const mxArray *c5_lhs137 = NULL;
  const mxArray *c5_rhs138 = NULL;
  const mxArray *c5_lhs138 = NULL;
  const mxArray *c5_rhs139 = NULL;
  const mxArray *c5_lhs139 = NULL;
  const mxArray *c5_rhs140 = NULL;
  const mxArray *c5_lhs140 = NULL;
  const mxArray *c5_rhs141 = NULL;
  const mxArray *c5_lhs141 = NULL;
  const mxArray *c5_rhs142 = NULL;
  const mxArray *c5_lhs142 = NULL;
  const mxArray *c5_rhs143 = NULL;
  const mxArray *c5_lhs143 = NULL;
  const mxArray *c5_rhs144 = NULL;
  const mxArray *c5_lhs144 = NULL;
  const mxArray *c5_rhs145 = NULL;
  const mxArray *c5_lhs145 = NULL;
  const mxArray *c5_rhs146 = NULL;
  const mxArray *c5_lhs146 = NULL;
  const mxArray *c5_rhs147 = NULL;
  const mxArray *c5_lhs147 = NULL;
  const mxArray *c5_rhs148 = NULL;
  const mxArray *c5_lhs148 = NULL;
  const mxArray *c5_rhs149 = NULL;
  const mxArray *c5_lhs149 = NULL;
  const mxArray *c5_rhs150 = NULL;
  const mxArray *c5_lhs150 = NULL;
  const mxArray *c5_rhs151 = NULL;
  const mxArray *c5_lhs151 = NULL;
  const mxArray *c5_rhs152 = NULL;
  const mxArray *c5_lhs152 = NULL;
  const mxArray *c5_rhs153 = NULL;
  const mxArray *c5_lhs153 = NULL;
  const mxArray *c5_rhs154 = NULL;
  const mxArray *c5_lhs154 = NULL;
  const mxArray *c5_rhs155 = NULL;
  const mxArray *c5_lhs155 = NULL;
  const mxArray *c5_rhs156 = NULL;
  const mxArray *c5_lhs156 = NULL;
  const mxArray *c5_rhs157 = NULL;
  const mxArray *c5_lhs157 = NULL;
  const mxArray *c5_rhs158 = NULL;
  const mxArray *c5_lhs158 = NULL;
  const mxArray *c5_rhs159 = NULL;
  const mxArray *c5_lhs159 = NULL;
  const mxArray *c5_rhs160 = NULL;
  const mxArray *c5_lhs160 = NULL;
  const mxArray *c5_rhs161 = NULL;
  const mxArray *c5_lhs161 = NULL;
  const mxArray *c5_rhs162 = NULL;
  const mxArray *c5_lhs162 = NULL;
  const mxArray *c5_rhs163 = NULL;
  const mxArray *c5_lhs163 = NULL;
  const mxArray *c5_rhs164 = NULL;
  const mxArray *c5_lhs164 = NULL;
  const mxArray *c5_rhs165 = NULL;
  const mxArray *c5_lhs165 = NULL;
  const mxArray *c5_rhs166 = NULL;
  const mxArray *c5_lhs166 = NULL;
  const mxArray *c5_rhs167 = NULL;
  const mxArray *c5_lhs167 = NULL;
  const mxArray *c5_rhs168 = NULL;
  const mxArray *c5_lhs168 = NULL;
  const mxArray *c5_rhs169 = NULL;
  const mxArray *c5_lhs169 = NULL;
  const mxArray *c5_rhs170 = NULL;
  const mxArray *c5_lhs170 = NULL;
  const mxArray *c5_rhs171 = NULL;
  const mxArray *c5_lhs171 = NULL;
  const mxArray *c5_rhs172 = NULL;
  const mxArray *c5_lhs172 = NULL;
  const mxArray *c5_rhs173 = NULL;
  const mxArray *c5_lhs173 = NULL;
  const mxArray *c5_rhs174 = NULL;
  const mxArray *c5_lhs174 = NULL;
  const mxArray *c5_rhs175 = NULL;
  const mxArray *c5_lhs175 = NULL;
  const mxArray *c5_rhs176 = NULL;
  const mxArray *c5_lhs176 = NULL;
  const mxArray *c5_rhs177 = NULL;
  const mxArray *c5_lhs177 = NULL;
  const mxArray *c5_rhs178 = NULL;
  const mxArray *c5_lhs178 = NULL;
  const mxArray *c5_rhs179 = NULL;
  const mxArray *c5_lhs179 = NULL;
  const mxArray *c5_rhs180 = NULL;
  const mxArray *c5_lhs180 = NULL;
  const mxArray *c5_rhs181 = NULL;
  const mxArray *c5_lhs181 = NULL;
  const mxArray *c5_rhs182 = NULL;
  const mxArray *c5_lhs182 = NULL;
  const mxArray *c5_rhs183 = NULL;
  const mxArray *c5_lhs183 = NULL;
  const mxArray *c5_rhs184 = NULL;
  const mxArray *c5_lhs184 = NULL;
  const mxArray *c5_rhs185 = NULL;
  const mxArray *c5_lhs185 = NULL;
  const mxArray *c5_rhs186 = NULL;
  const mxArray *c5_lhs186 = NULL;
  const mxArray *c5_rhs187 = NULL;
  const mxArray *c5_lhs187 = NULL;
  const mxArray *c5_rhs188 = NULL;
  const mxArray *c5_lhs188 = NULL;
  const mxArray *c5_rhs189 = NULL;
  const mxArray *c5_lhs189 = NULL;
  const mxArray *c5_rhs190 = NULL;
  const mxArray *c5_lhs190 = NULL;
  const mxArray *c5_rhs191 = NULL;
  const mxArray *c5_lhs191 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_rdivide.m"),
                  "context", "context", 128);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexDivide"),
                  "name", "name", 128);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 128);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexDivide.m"),
                  "resolved", "resolved", 128);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 128);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 128);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 128);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 128);
  sf_mex_assign(&c5_rhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs128, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs128), "rhs", "rhs",
                  128);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs128), "lhs", "lhs",
                  128);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon"),
                  "context", "context", 129);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 129);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 129);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 129);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 129);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 129);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 129);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 129);
  sf_mex_assign(&c5_rhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs129, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs129), "rhs", "rhs",
                  129);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs129), "lhs", "lhs",
                  129);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 130);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 130);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 130);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 130);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 130);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 130);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 130);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 130);
  sf_mex_assign(&c5_rhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs130, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs130), "rhs", "rhs",
                  130);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs130), "lhs", "lhs",
                  130);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon"),
                  "context", "context", 131);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 131);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 131);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 131);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 131);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 131);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 131);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 131);
  sf_mex_assign(&c5_rhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs131, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs131), "rhs", "rhs",
                  131);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs131), "lhs", "lhs",
                  131);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_float_colon"),
                  "context", "context", 132);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 132);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 132);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 132);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 132);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 132);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 132);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 132);
  sf_mex_assign(&c5_rhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs132, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs132), "rhs", "rhs",
                  132);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs132), "lhs", "lhs",
                  132);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "context", "context", 133);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 133);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 133);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 133);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 133);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 133);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 133);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 133);
  sf_mex_assign(&c5_rhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs133, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs133), "rhs", "rhs",
                  133);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs133), "lhs", "lhs",
                  133);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 134);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mrdivide"), "name", "name",
                  134);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 134);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 134);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 134);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 134);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 134);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 134);
  sf_mex_assign(&c5_rhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs134, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs134), "rhs", "rhs",
                  134);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs134), "lhs", "lhs",
                  134);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                  "context", "context", 135);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 135);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 135);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 135);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 135);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 135);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 135);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 135);
  sf_mex_assign(&c5_rhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs135, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs135), "rhs", "rhs",
                  135);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs135), "lhs", "lhs",
                  135);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 136);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 136);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 136);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 136);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 136);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 136);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 136);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 136);
  sf_mex_assign(&c5_rhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs136, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs136), "rhs", "rhs",
                  136);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs136), "lhs", "lhs",
                  136);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 137);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 137);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 137);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 137);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 137);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 137);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 137);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 137);
  sf_mex_assign(&c5_rhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs137, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs137), "rhs", "rhs",
                  137);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs137), "lhs", "lhs",
                  137);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m!sat"),
                  "context", "context", 138);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("min"), "name", "name", 138);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 138);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 138);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 138);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 138);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 138);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 138);
  sf_mex_assign(&c5_rhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs138, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs138), "rhs", "rhs",
                  138);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs138), "lhs", "lhs",
                  138);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context",
                  "context", 139);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_min_or_max"), "name",
                  "name", 139);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 139);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                  "resolved", "resolved", 139);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1378317584U), "fileTimeLo",
                  "fileTimeLo", 139);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 139);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 139);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 139);
  sf_mex_assign(&c5_rhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs139, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs139), "rhs", "rhs",
                  139);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs139), "lhs", "lhs",
                  139);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m!sat"),
                  "context", "context", 140);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("max"), "name", "name", 140);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 140);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 140);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 140);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 140);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 140);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 140);
  sf_mex_assign(&c5_rhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs140, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs140), "rhs", "rhs",
                  140);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs140), "lhs", "lhs",
                  140);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 141);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("bezierv"), "name", "name", 141);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 141);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/bezierv.m"),
                  "resolved", "resolved", 141);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837205U), "fileTimeLo",
                  "fileTimeLo", 141);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 141);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 141);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 141);
  sf_mex_assign(&c5_rhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs141, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs141), "rhs", "rhs",
                  141);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs141), "lhs", "lhs",
                  141);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 142);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("beziervd"), "name", "name",
                  142);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 142);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/beziervd.m"),
                  "resolved", "resolved", 142);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837205U), "fileTimeLo",
                  "fileTimeLo", 142);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 142);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 142);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 142);
  sf_mex_assign(&c5_rhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs142, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs142), "rhs", "rhs",
                  142);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs142), "lhs", "lhs",
                  142);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 143);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("bezierva"), "name", "name",
                  143);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 143);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/bezierva.m"),
                  "resolved", "resolved", 143);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837205U), "fileTimeLo",
                  "fileTimeLo", 143);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 143);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 143);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 143);
  sf_mex_assign(&c5_rhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs143, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs143), "rhs", "rhs",
                  143);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs143), "lhs", "lhs",
                  143);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 144);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("bezier"), "name", "name", 144);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 144);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/bezier.m"),
                  "resolved", "resolved", 144);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837205U), "fileTimeLo",
                  "fileTimeLo", 144);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 144);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 144);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 144);
  sf_mex_assign(&c5_rhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs144, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs144), "rhs", "rhs",
                  144);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs144), "lhs", "lhs",
                  144);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/bezier.m"),
                  "context", "context", 145);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("binom"), "name", "name", 145);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 145);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/binom.m"),
                  "resolved", "resolved", 145);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837205U), "fileTimeLo",
                  "fileTimeLo", 145);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 145);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 145);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 145);
  sf_mex_assign(&c5_rhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs145, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs145), "rhs", "rhs",
                  145);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs145), "lhs", "lhs",
                  145);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 146);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("bezierd"), "name", "name", 146);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 146);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/bezierd.m"),
                  "resolved", "resolved", 146);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837205U), "fileTimeLo",
                  "fileTimeLo", 146);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 146);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 146);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 146);
  sf_mex_assign(&c5_rhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs146, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs146), "rhs", "rhs",
                  146);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs146), "lhs", "lhs",
                  146);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 147);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("beziera"), "name", "name", 147);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 147);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/beziera.m"),
                  "resolved", "resolved", 147);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837205U), "fileTimeLo",
                  "fileTimeLo", 147);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 147);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 147);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 147);
  sf_mex_assign(&c5_rhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs147, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs147), "rhs", "rhs",
                  147);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs147), "lhs", "lhs",
                  147);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 148);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("polyv"), "name", "name", 148);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 148);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/polyv.m"),
                  "resolved", "resolved", 148);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837205U), "fileTimeLo",
                  "fileTimeLo", 148);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 148);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 148);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 148);
  sf_mex_assign(&c5_rhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs148, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs148), "rhs", "rhs",
                  148);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs148), "lhs", "lhs",
                  148);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 149);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("polyvd"), "name", "name", 149);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 149);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/polyvd.m"),
                  "resolved", "resolved", 149);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837205U), "fileTimeLo",
                  "fileTimeLo", 149);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 149);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 149);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 149);
  sf_mex_assign(&c5_rhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs149, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs149), "rhs", "rhs",
                  149);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs149), "lhs", "lhs",
                  149);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/polyvd.m"),
                  "context", "context", 150);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 150);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 150);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 150);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 150);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 150);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 150);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 150);
  sf_mex_assign(&c5_rhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs150, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs150), "rhs", "rhs",
                  150);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs150), "lhs", "lhs",
                  150);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 151);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("polyva"), "name", "name", 151);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 151);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/polyva.m"),
                  "resolved", "resolved", 151);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837205U), "fileTimeLo",
                  "fileTimeLo", 151);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 151);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 151);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 151);
  sf_mex_assign(&c5_rhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs151, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs151), "rhs", "rhs",
                  151);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs151), "lhs", "lhs",
                  151);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/polyva.m"),
                  "context", "context", 152);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 152);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 152);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 152);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 152);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 152);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 152);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 152);
  sf_mex_assign(&c5_rhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs152, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs152), "rhs", "rhs",
                  152);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs152), "lhs", "lhs",
                  152);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p!equalsize"),
                  "context", "context", 153);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("max"), "name", "name", 153);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 153);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved",
                  "resolved", 153);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1311276916U), "fileTimeLo",
                  "fileTimeLo", 153);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 153);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 153);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 153);
  sf_mex_assign(&c5_rhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs153, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs153), "rhs", "rhs",
                  153);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs153), "lhs", "lhs",
                  153);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 154);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mpower"), "name", "name", 154);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 154);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 154);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731878U), "fileTimeLo",
                  "fileTimeLo", 154);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 154);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 154);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 154);
  sf_mex_assign(&c5_rhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs154, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs154), "rhs", "rhs",
                  154);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs154), "lhs", "lhs",
                  154);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 155);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 155);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 155);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 155);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 155);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 155);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 155);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 155);
  sf_mex_assign(&c5_rhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs155, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs155), "rhs", "rhs",
                  155);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs155), "lhs", "lhs",
                  155);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 156);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("ismatrix"), "name", "name",
                  156);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 156);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 156);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1331326458U), "fileTimeLo",
                  "fileTimeLo", 156);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 156);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 156);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 156);
  sf_mex_assign(&c5_rhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs156, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs156), "rhs", "rhs",
                  156);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs156), "lhs", "lhs",
                  156);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 157);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("power"), "name", "name", 157);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 157);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 157);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395346506U), "fileTimeLo",
                  "fileTimeLo", 157);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 157);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 157);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 157);
  sf_mex_assign(&c5_rhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs157, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs157), "rhs", "rhs",
                  157);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs157), "lhs", "lhs",
                  157);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 158);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 158);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 158);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 158);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 158);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 158);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 158);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 158);
  sf_mex_assign(&c5_rhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs158, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs158), "rhs", "rhs",
                  158);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs158), "lhs", "lhs",
                  158);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 159);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 159);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 159);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 159);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 159);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 159);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 159);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 159);
  sf_mex_assign(&c5_rhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs159, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs159), "rhs", "rhs",
                  159);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs159), "lhs", "lhs",
                  159);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 160);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 160);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 160);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 160);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 160);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 160);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 160);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 160);
  sf_mex_assign(&c5_rhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs160, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs160), "rhs", "rhs",
                  160);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs160), "lhs", "lhs",
                  160);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 161);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("floor"), "name", "name", 161);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 161);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 161);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 161);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 161);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 161);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 161);
  sf_mex_assign(&c5_rhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs161, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs161), "rhs", "rhs",
                  161);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs161), "lhs", "lhs",
                  161);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 162);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 162);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 162);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 162);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 162);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 162);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 162);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 162);
  sf_mex_assign(&c5_rhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs162, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs162), "rhs", "rhs",
                  162);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs162), "lhs", "lhs",
                  162);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Output03.m"),
                  "context", "context", 163);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("any"), "name", "name", 163);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 163);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m"), "resolved",
                  "resolved", 163);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 163);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 163);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 163);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 163);
  sf_mex_assign(&c5_rhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs163, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs163), "rhs", "rhs",
                  163);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs163), "lhs", "lhs",
                  163);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m"), "context", "context",
                  164);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 164);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 164);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 164);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 164);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 164);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 164);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 164);
  sf_mex_assign(&c5_rhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs164, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs164), "rhs", "rhs",
                  164);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs164), "lhs", "lhs",
                  164);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m"), "context", "context",
                  165);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 165);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 165);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 165);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 165);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 165);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 165);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 165);
  sf_mex_assign(&c5_rhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs165, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs165), "rhs", "rhs",
                  165);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs165), "lhs", "lhs",
                  165);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/any.m"), "context", "context",
                  166);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.allOrAny"),
                  "name", "name", 166);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 166);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "resolved", "resolved", 166);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604758U), "fileTimeLo",
                  "fileTimeLo", 166);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 166);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 166);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 166);
  sf_mex_assign(&c5_rhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs166, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs166), "rhs", "rhs",
                  166);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs166), "lhs", "lhs",
                  166);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 167);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 167);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 167);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 167);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 167);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 167);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 167);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 167);
  sf_mex_assign(&c5_rhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs167, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs167), "rhs", "rhs",
                  167);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs167), "lhs", "lhs",
                  167);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 168);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isequal"), "name", "name", 168);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 168);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                  "resolved", 168);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840358U), "fileTimeLo",
                  "fileTimeLo", 168);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 168);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 168);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 168);
  sf_mex_assign(&c5_rhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs168, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs168), "rhs", "rhs",
                  168);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs168), "lhs", "lhs",
                  168);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 169);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.constNonSingletonDim"), "name", "name", 169);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 169);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                  "resolved", "resolved", 169);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 169);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 169);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 169);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 169);
  sf_mex_assign(&c5_rhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs169, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs169), "rhs", "rhs",
                  169);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs169), "lhs", "lhs",
                  169);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/allOrAny.m"),
                  "context", "context", 170);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("isnan"), "name", "name", 170);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 170);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved",
                  "resolved", 170);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731858U), "fileTimeLo",
                  "fileTimeLo", 170);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 170);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 170);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 170);
  sf_mex_assign(&c5_rhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs170, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs170), "rhs", "rhs",
                  170);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs170), "lhs", "lhs",
                  170);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context",
                  "context", 171);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 171);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("logical"), "dominantType",
                  "dominantType", 171);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 171);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 171);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 171);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 171);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 171);
  sf_mex_assign(&c5_rhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs171, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs171), "rhs", "rhs",
                  171);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs171), "lhs", "lhs",
                  171);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Control06.m"),
                  "context", "context", 172);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 172);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 172);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 172);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 172);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 172);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 172);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 172);
  sf_mex_assign(&c5_rhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs172, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs172), "rhs", "rhs",
                  172);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs172), "lhs", "lhs",
                  172);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Control06.m"),
                  "context", "context", 173);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mrdivide"), "name", "name",
                  173);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 173);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 173);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 173);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 173);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 173);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 173);
  sf_mex_assign(&c5_rhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs173, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs173), "rhs", "rhs",
                  173);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs173), "lhs", "lhs",
                  173);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Control06.m"),
                  "context", "context", 174);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("mldivide"), "name", "name",
                  174);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 174);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "resolved",
                  "resolved", 174);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 174);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 174);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1319751566U), "mFileTimeLo",
                  "mFileTimeLo", 174);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 174);
  sf_mex_assign(&c5_rhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs174, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs174), "rhs", "rhs",
                  174);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs174), "lhs", "lhs",
                  174);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "context",
                  "context", 175);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_lusolve"), "name", "name",
                  175);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 175);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m"), "resolved",
                  "resolved", 175);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1370031486U), "fileTimeLo",
                  "fileTimeLo", 175);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 175);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 175);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 175);
  sf_mex_assign(&c5_rhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs175, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs175), "rhs", "rhs",
                  175);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs175), "lhs", "lhs",
                  175);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 176);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_xgetrf"), "name", "name",
                  176);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 176);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "resolved", "resolved", 176);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840406U), "fileTimeLo",
                  "fileTimeLo", 176);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 176);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 176);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 176);
  sf_mex_assign(&c5_rhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs176, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs176), "rhs", "rhs",
                  176);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs176), "lhs", "lhs",
                  176);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                  "context", "context", 177);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_lapack_xgetrf"), "name",
                  "name", 177);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 177);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "resolved", "resolved", 177);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840410U), "fileTimeLo",
                  "fileTimeLo", 177);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 177);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 177);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 177);
  sf_mex_assign(&c5_rhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs177, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs177), "rhs", "rhs",
                  177);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs177), "lhs", "lhs",
                  177);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                  "context", "context", 178);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_matlab_zgetrf"), "name",
                  "name", 178);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 178);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "resolved", "resolved", 178);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1302710594U), "fileTimeLo",
                  "fileTimeLo", 178);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 178);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 178);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 178);
  sf_mex_assign(&c5_rhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs178, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs178), "rhs", "rhs",
                  178);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs178), "lhs", "lhs",
                  178);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 179);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("realmin"), "name", "name", 179);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 179);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                  "resolved", 179);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1307672842U), "fileTimeLo",
                  "fileTimeLo", 179);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 179);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 179);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 179);
  sf_mex_assign(&c5_rhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs179, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs179), "rhs", "rhs",
                  179);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs179), "lhs", "lhs",
                  179);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context",
                  "context", 180);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_realmin"), "name", "name",
                  180);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 180);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                  "resolved", 180);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1307672844U), "fileTimeLo",
                  "fileTimeLo", 180);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 180);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 180);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 180);
  sf_mex_assign(&c5_rhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs180, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs180), "rhs", "rhs",
                  180);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs180), "lhs", "lhs",
                  180);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                  "context", 181);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_float_model"), "name",
                  "name", 181);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 181);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                  "resolved", "resolved", 181);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 181);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 181);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 181);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 181);
  sf_mex_assign(&c5_rhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs181, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs181), "rhs", "rhs",
                  181);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs181), "lhs", "lhs",
                  181);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 182);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eps"), "name", "name", 182);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 182);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved",
                  "resolved", 182);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1326749596U), "fileTimeLo",
                  "fileTimeLo", 182);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 182);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 182);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 182);
  sf_mex_assign(&c5_rhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs182, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs182), "rhs", "rhs",
                  182);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs182), "lhs", "lhs",
                  182);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 183);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("min"), "name", "name", 183);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 183);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 183);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 183);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 183);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 183);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 183);
  sf_mex_assign(&c5_rhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs183, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs183), "rhs", "rhs",
                  183);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs183), "lhs", "lhs",
                  183);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 184);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("colon"), "name", "name", 184);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 184);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 184);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 184);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 184);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 184);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 184);
  sf_mex_assign(&c5_rhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs184, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs184), "rhs", "rhs",
                  184);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs184), "lhs", "lhs",
                  184);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 185);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("colon"), "name", "name", 185);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 185);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved",
                  "resolved", 185);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1378317588U), "fileTimeLo",
                  "fileTimeLo", 185);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 185);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 185);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 185);
  sf_mex_assign(&c5_rhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs185, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs185), "rhs", "rhs",
                  185);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs185), "lhs", "lhs",
                  185);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 186);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 186);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 186);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 186);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 186);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 186);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 186);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 186);
  sf_mex_assign(&c5_rhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs186, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs186), "rhs", "rhs",
                  186);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs186), "lhs", "lhs",
                  186);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context",
                  "context", 187);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("floor"), "name", "name", 187);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 187);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 187);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 187);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 187);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 187);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 187);
  sf_mex_assign(&c5_rhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs187, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs187), "rhs", "rhs",
                  187);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs187), "lhs", "lhs",
                  187);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 188);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmin"), "name", "name", 188);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 188);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 188);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 188);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 188);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 188);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 188);
  sf_mex_assign(&c5_rhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs188, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs188), "rhs", "rhs",
                  188);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs188), "lhs", "lhs",
                  188);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                  "context", "context", 189);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 189);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 189);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 189);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 189);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 189);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 189);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 189);
  sf_mex_assign(&c5_rhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs189, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs189), "rhs", "rhs",
                  189);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs189), "lhs", "lhs",
                  189);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 190);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmin"), "name", "name", 190);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 190);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved",
                  "resolved", 190);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 190);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 190);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 190);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 190);
  sf_mex_assign(&c5_rhs190, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs190, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs190), "rhs", "rhs",
                  190);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs190), "lhs", "lhs",
                  190);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 191);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 191);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 191);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 191);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 191);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 191);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 191);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 191);
  sf_mex_assign(&c5_rhs191, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs191, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs191), "rhs", "rhs",
                  191);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs191), "lhs", "lhs",
                  191);
  sf_mex_destroy(&c5_rhs128);
  sf_mex_destroy(&c5_lhs128);
  sf_mex_destroy(&c5_rhs129);
  sf_mex_destroy(&c5_lhs129);
  sf_mex_destroy(&c5_rhs130);
  sf_mex_destroy(&c5_lhs130);
  sf_mex_destroy(&c5_rhs131);
  sf_mex_destroy(&c5_lhs131);
  sf_mex_destroy(&c5_rhs132);
  sf_mex_destroy(&c5_lhs132);
  sf_mex_destroy(&c5_rhs133);
  sf_mex_destroy(&c5_lhs133);
  sf_mex_destroy(&c5_rhs134);
  sf_mex_destroy(&c5_lhs134);
  sf_mex_destroy(&c5_rhs135);
  sf_mex_destroy(&c5_lhs135);
  sf_mex_destroy(&c5_rhs136);
  sf_mex_destroy(&c5_lhs136);
  sf_mex_destroy(&c5_rhs137);
  sf_mex_destroy(&c5_lhs137);
  sf_mex_destroy(&c5_rhs138);
  sf_mex_destroy(&c5_lhs138);
  sf_mex_destroy(&c5_rhs139);
  sf_mex_destroy(&c5_lhs139);
  sf_mex_destroy(&c5_rhs140);
  sf_mex_destroy(&c5_lhs140);
  sf_mex_destroy(&c5_rhs141);
  sf_mex_destroy(&c5_lhs141);
  sf_mex_destroy(&c5_rhs142);
  sf_mex_destroy(&c5_lhs142);
  sf_mex_destroy(&c5_rhs143);
  sf_mex_destroy(&c5_lhs143);
  sf_mex_destroy(&c5_rhs144);
  sf_mex_destroy(&c5_lhs144);
  sf_mex_destroy(&c5_rhs145);
  sf_mex_destroy(&c5_lhs145);
  sf_mex_destroy(&c5_rhs146);
  sf_mex_destroy(&c5_lhs146);
  sf_mex_destroy(&c5_rhs147);
  sf_mex_destroy(&c5_lhs147);
  sf_mex_destroy(&c5_rhs148);
  sf_mex_destroy(&c5_lhs148);
  sf_mex_destroy(&c5_rhs149);
  sf_mex_destroy(&c5_lhs149);
  sf_mex_destroy(&c5_rhs150);
  sf_mex_destroy(&c5_lhs150);
  sf_mex_destroy(&c5_rhs151);
  sf_mex_destroy(&c5_lhs151);
  sf_mex_destroy(&c5_rhs152);
  sf_mex_destroy(&c5_lhs152);
  sf_mex_destroy(&c5_rhs153);
  sf_mex_destroy(&c5_lhs153);
  sf_mex_destroy(&c5_rhs154);
  sf_mex_destroy(&c5_lhs154);
  sf_mex_destroy(&c5_rhs155);
  sf_mex_destroy(&c5_lhs155);
  sf_mex_destroy(&c5_rhs156);
  sf_mex_destroy(&c5_lhs156);
  sf_mex_destroy(&c5_rhs157);
  sf_mex_destroy(&c5_lhs157);
  sf_mex_destroy(&c5_rhs158);
  sf_mex_destroy(&c5_lhs158);
  sf_mex_destroy(&c5_rhs159);
  sf_mex_destroy(&c5_lhs159);
  sf_mex_destroy(&c5_rhs160);
  sf_mex_destroy(&c5_lhs160);
  sf_mex_destroy(&c5_rhs161);
  sf_mex_destroy(&c5_lhs161);
  sf_mex_destroy(&c5_rhs162);
  sf_mex_destroy(&c5_lhs162);
  sf_mex_destroy(&c5_rhs163);
  sf_mex_destroy(&c5_lhs163);
  sf_mex_destroy(&c5_rhs164);
  sf_mex_destroy(&c5_lhs164);
  sf_mex_destroy(&c5_rhs165);
  sf_mex_destroy(&c5_lhs165);
  sf_mex_destroy(&c5_rhs166);
  sf_mex_destroy(&c5_lhs166);
  sf_mex_destroy(&c5_rhs167);
  sf_mex_destroy(&c5_lhs167);
  sf_mex_destroy(&c5_rhs168);
  sf_mex_destroy(&c5_lhs168);
  sf_mex_destroy(&c5_rhs169);
  sf_mex_destroy(&c5_lhs169);
  sf_mex_destroy(&c5_rhs170);
  sf_mex_destroy(&c5_lhs170);
  sf_mex_destroy(&c5_rhs171);
  sf_mex_destroy(&c5_lhs171);
  sf_mex_destroy(&c5_rhs172);
  sf_mex_destroy(&c5_lhs172);
  sf_mex_destroy(&c5_rhs173);
  sf_mex_destroy(&c5_lhs173);
  sf_mex_destroy(&c5_rhs174);
  sf_mex_destroy(&c5_lhs174);
  sf_mex_destroy(&c5_rhs175);
  sf_mex_destroy(&c5_lhs175);
  sf_mex_destroy(&c5_rhs176);
  sf_mex_destroy(&c5_lhs176);
  sf_mex_destroy(&c5_rhs177);
  sf_mex_destroy(&c5_lhs177);
  sf_mex_destroy(&c5_rhs178);
  sf_mex_destroy(&c5_lhs178);
  sf_mex_destroy(&c5_rhs179);
  sf_mex_destroy(&c5_lhs179);
  sf_mex_destroy(&c5_rhs180);
  sf_mex_destroy(&c5_lhs180);
  sf_mex_destroy(&c5_rhs181);
  sf_mex_destroy(&c5_lhs181);
  sf_mex_destroy(&c5_rhs182);
  sf_mex_destroy(&c5_lhs182);
  sf_mex_destroy(&c5_rhs183);
  sf_mex_destroy(&c5_lhs183);
  sf_mex_destroy(&c5_rhs184);
  sf_mex_destroy(&c5_lhs184);
  sf_mex_destroy(&c5_rhs185);
  sf_mex_destroy(&c5_lhs185);
  sf_mex_destroy(&c5_rhs186);
  sf_mex_destroy(&c5_lhs186);
  sf_mex_destroy(&c5_rhs187);
  sf_mex_destroy(&c5_lhs187);
  sf_mex_destroy(&c5_rhs188);
  sf_mex_destroy(&c5_lhs188);
  sf_mex_destroy(&c5_rhs189);
  sf_mex_destroy(&c5_lhs189);
  sf_mex_destroy(&c5_rhs190);
  sf_mex_destroy(&c5_lhs190);
  sf_mex_destroy(&c5_rhs191);
  sf_mex_destroy(&c5_lhs191);
}

static void c5_d_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs192 = NULL;
  const mxArray *c5_lhs192 = NULL;
  const mxArray *c5_rhs193 = NULL;
  const mxArray *c5_lhs193 = NULL;
  const mxArray *c5_rhs194 = NULL;
  const mxArray *c5_lhs194 = NULL;
  const mxArray *c5_rhs195 = NULL;
  const mxArray *c5_lhs195 = NULL;
  const mxArray *c5_rhs196 = NULL;
  const mxArray *c5_lhs196 = NULL;
  const mxArray *c5_rhs197 = NULL;
  const mxArray *c5_lhs197 = NULL;
  const mxArray *c5_rhs198 = NULL;
  const mxArray *c5_lhs198 = NULL;
  const mxArray *c5_rhs199 = NULL;
  const mxArray *c5_lhs199 = NULL;
  const mxArray *c5_rhs200 = NULL;
  const mxArray *c5_lhs200 = NULL;
  const mxArray *c5_rhs201 = NULL;
  const mxArray *c5_lhs201 = NULL;
  const mxArray *c5_rhs202 = NULL;
  const mxArray *c5_lhs202 = NULL;
  const mxArray *c5_rhs203 = NULL;
  const mxArray *c5_lhs203 = NULL;
  const mxArray *c5_rhs204 = NULL;
  const mxArray *c5_lhs204 = NULL;
  const mxArray *c5_rhs205 = NULL;
  const mxArray *c5_lhs205 = NULL;
  const mxArray *c5_rhs206 = NULL;
  const mxArray *c5_lhs206 = NULL;
  const mxArray *c5_rhs207 = NULL;
  const mxArray *c5_lhs207 = NULL;
  const mxArray *c5_rhs208 = NULL;
  const mxArray *c5_lhs208 = NULL;
  const mxArray *c5_rhs209 = NULL;
  const mxArray *c5_lhs209 = NULL;
  const mxArray *c5_rhs210 = NULL;
  const mxArray *c5_lhs210 = NULL;
  const mxArray *c5_rhs211 = NULL;
  const mxArray *c5_lhs211 = NULL;
  const mxArray *c5_rhs212 = NULL;
  const mxArray *c5_lhs212 = NULL;
  const mxArray *c5_rhs213 = NULL;
  const mxArray *c5_lhs213 = NULL;
  const mxArray *c5_rhs214 = NULL;
  const mxArray *c5_lhs214 = NULL;
  const mxArray *c5_rhs215 = NULL;
  const mxArray *c5_lhs215 = NULL;
  const mxArray *c5_rhs216 = NULL;
  const mxArray *c5_lhs216 = NULL;
  const mxArray *c5_rhs217 = NULL;
  const mxArray *c5_lhs217 = NULL;
  const mxArray *c5_rhs218 = NULL;
  const mxArray *c5_lhs218 = NULL;
  const mxArray *c5_rhs219 = NULL;
  const mxArray *c5_lhs219 = NULL;
  const mxArray *c5_rhs220 = NULL;
  const mxArray *c5_lhs220 = NULL;
  const mxArray *c5_rhs221 = NULL;
  const mxArray *c5_lhs221 = NULL;
  const mxArray *c5_rhs222 = NULL;
  const mxArray *c5_lhs222 = NULL;
  const mxArray *c5_rhs223 = NULL;
  const mxArray *c5_lhs223 = NULL;
  const mxArray *c5_rhs224 = NULL;
  const mxArray *c5_lhs224 = NULL;
  const mxArray *c5_rhs225 = NULL;
  const mxArray *c5_lhs225 = NULL;
  const mxArray *c5_rhs226 = NULL;
  const mxArray *c5_lhs226 = NULL;
  const mxArray *c5_rhs227 = NULL;
  const mxArray *c5_lhs227 = NULL;
  const mxArray *c5_rhs228 = NULL;
  const mxArray *c5_lhs228 = NULL;
  const mxArray *c5_rhs229 = NULL;
  const mxArray *c5_lhs229 = NULL;
  const mxArray *c5_rhs230 = NULL;
  const mxArray *c5_lhs230 = NULL;
  const mxArray *c5_rhs231 = NULL;
  const mxArray *c5_lhs231 = NULL;
  const mxArray *c5_rhs232 = NULL;
  const mxArray *c5_lhs232 = NULL;
  const mxArray *c5_rhs233 = NULL;
  const mxArray *c5_lhs233 = NULL;
  const mxArray *c5_rhs234 = NULL;
  const mxArray *c5_lhs234 = NULL;
  const mxArray *c5_rhs235 = NULL;
  const mxArray *c5_lhs235 = NULL;
  const mxArray *c5_rhs236 = NULL;
  const mxArray *c5_lhs236 = NULL;
  const mxArray *c5_rhs237 = NULL;
  const mxArray *c5_lhs237 = NULL;
  const mxArray *c5_rhs238 = NULL;
  const mxArray *c5_lhs238 = NULL;
  const mxArray *c5_rhs239 = NULL;
  const mxArray *c5_lhs239 = NULL;
  const mxArray *c5_rhs240 = NULL;
  const mxArray *c5_lhs240 = NULL;
  const mxArray *c5_rhs241 = NULL;
  const mxArray *c5_lhs241 = NULL;
  const mxArray *c5_rhs242 = NULL;
  const mxArray *c5_lhs242 = NULL;
  const mxArray *c5_rhs243 = NULL;
  const mxArray *c5_lhs243 = NULL;
  const mxArray *c5_rhs244 = NULL;
  const mxArray *c5_lhs244 = NULL;
  const mxArray *c5_rhs245 = NULL;
  const mxArray *c5_lhs245 = NULL;
  const mxArray *c5_rhs246 = NULL;
  const mxArray *c5_lhs246 = NULL;
  const mxArray *c5_rhs247 = NULL;
  const mxArray *c5_lhs247 = NULL;
  const mxArray *c5_rhs248 = NULL;
  const mxArray *c5_lhs248 = NULL;
  const mxArray *c5_rhs249 = NULL;
  const mxArray *c5_lhs249 = NULL;
  const mxArray *c5_rhs250 = NULL;
  const mxArray *c5_lhs250 = NULL;
  const mxArray *c5_rhs251 = NULL;
  const mxArray *c5_lhs251 = NULL;
  const mxArray *c5_rhs252 = NULL;
  const mxArray *c5_lhs252 = NULL;
  const mxArray *c5_rhs253 = NULL;
  const mxArray *c5_lhs253 = NULL;
  const mxArray *c5_rhs254 = NULL;
  const mxArray *c5_lhs254 = NULL;
  const mxArray *c5_rhs255 = NULL;
  const mxArray *c5_lhs255 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                  "context", "context", 192);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_isa_uint"), "name", "name",
                  192);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 192);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 192);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 192);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 192);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 192);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 192);
  sf_mex_assign(&c5_rhs192, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs192, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs192), "rhs", "rhs",
                  192);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs192), "lhs", "lhs",
                  192);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                  "context", 193);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.isaUint"),
                  "name", "name", 193);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 193);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                  "resolved", "resolved", 193);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 193);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 193);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 193);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 193);
  sf_mex_assign(&c5_rhs193, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs193, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs193), "rhs", "rhs",
                  193);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs193), "lhs", "lhs",
                  193);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 194);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_unsigned_class"), "name",
                  "name", 194);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 194);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "resolved", "resolved", 194);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 194);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 194);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 194);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 194);
  sf_mex_assign(&c5_rhs194, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs194, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs194), "rhs", "rhs",
                  194);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs194), "lhs", "lhs",
                  194);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                  "context", "context", 195);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.unsignedClass"),
                  "name", "name", 195);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 195);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "resolved", "resolved", 195);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 195);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 195);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 195);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 195);
  sf_mex_assign(&c5_rhs195, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs195, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs195), "rhs", "rhs",
                  195);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs195), "lhs", "lhs",
                  195);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 196);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 196);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 196);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 196);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 196);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 196);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 196);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 196);
  sf_mex_assign(&c5_rhs196, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs196, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs196), "rhs", "rhs",
                  196);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs196), "lhs", "lhs",
                  196);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                  "context", "context", 197);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 197);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 197);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 197);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 197);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 197);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 197);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 197);
  sf_mex_assign(&c5_rhs197, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs197, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs197), "rhs", "rhs",
                  197);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs197), "lhs", "lhs",
                  197);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 198);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 198);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 198);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 198);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 198);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 198);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 198);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 198);
  sf_mex_assign(&c5_rhs198, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs198, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs198), "rhs", "rhs",
                  198);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs198), "lhs", "lhs",
                  198);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 199);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 199);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 199);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 199);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 199);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 199);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 199);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 199);
  sf_mex_assign(&c5_rhs199, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs199, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs199), "rhs", "rhs",
                  199);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs199), "lhs", "lhs",
                  199);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 200);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_isa_uint"), "name", "name",
                  200);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 200);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                  "resolved", 200);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 200);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 200);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 200);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 200);
  sf_mex_assign(&c5_rhs200, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs200, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs200), "rhs", "rhs",
                  200);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs200), "lhs", "lhs",
                  200);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                  "context", "context", 201);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 201);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 201);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 201);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 201);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 201);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 201);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 201);
  sf_mex_assign(&c5_rhs201, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs201, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs201), "rhs", "rhs",
                  201);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs201), "lhs", "lhs",
                  201);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                  "context", "context", 202);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 202);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 202);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 202);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 202);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 202);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 202);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 202);
  sf_mex_assign(&c5_rhs202, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs202, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs202), "rhs", "rhs",
                  202);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs202), "lhs", "lhs",
                  202);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 203);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 203);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 203);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 203);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 203);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 203);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 203);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 203);
  sf_mex_assign(&c5_rhs203, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs203, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs203), "rhs", "rhs",
                  203);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs203), "lhs", "lhs",
                  203);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 204);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 204);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 204);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 204);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 204);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 204);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 204);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 204);
  sf_mex_assign(&c5_rhs204, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs204, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs204), "rhs", "rhs",
                  204);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs204), "lhs", "lhs",
                  204);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 205);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 205);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 205);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 205);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 205);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 205);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 205);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 205);
  sf_mex_assign(&c5_rhs205, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs205, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs205), "rhs", "rhs",
                  205);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs205), "lhs", "lhs",
                  205);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 206);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 206);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 206);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 206);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 206);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 206);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 206);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 206);
  sf_mex_assign(&c5_rhs206, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs206, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs206), "rhs", "rhs",
                  206);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs206), "lhs", "lhs",
                  206);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 207);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_minus"), "name",
                  "name", 207);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 207);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                  "resolved", "resolved", 207);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 207);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 207);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 207);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 207);
  sf_mex_assign(&c5_rhs207, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs207, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs207), "rhs", "rhs",
                  207);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs207), "lhs", "lhs",
                  207);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 208);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_times"), "name",
                  "name", 208);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 208);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "resolved", "resolved", 208);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 208);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 208);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 208);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 208);
  sf_mex_assign(&c5_rhs208, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs208, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs208), "rhs", "rhs",
                  208);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs208), "lhs", "lhs",
                  208);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                  "context", "context", 209);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexTimes"),
                  "name", "name", 209);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 209);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                  "resolved", "resolved", 209);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 209);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 209);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 209);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 209);
  sf_mex_assign(&c5_rhs209, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs209, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs209), "rhs", "rhs",
                  209);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs209), "lhs", "lhs",
                  209);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 210);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 210);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 210);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 210);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 210);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 210);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 210);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 210);
  sf_mex_assign(&c5_rhs210, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs210, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs210), "rhs", "rhs",
                  210);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs210), "lhs", "lhs",
                  210);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 211);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 211);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 211);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 211);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 211);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 211);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 211);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 211);
  sf_mex_assign(&c5_rhs211, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs211, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs211), "rhs", "rhs",
                  211);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs211), "lhs", "lhs",
                  211);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 212);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_ixamax"), "name", "name",
                  212);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 212);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "resolved", "resolved", 212);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 212);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 212);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 212);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 212);
  sf_mex_assign(&c5_rhs212, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs212, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs212), "rhs", "rhs",
                  212);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs212), "lhs", "lhs",
                  212);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "context", "context", 213);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 213);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 213);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 213);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 213);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 213);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 213);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 213);
  sf_mex_assign(&c5_rhs213, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs213, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs213), "rhs", "rhs",
                  213);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs213), "lhs", "lhs",
                  213);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                  "context", "context", 214);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.ixamax"),
                  "name", "name", 214);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 214);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "resolved", "resolved", 214);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 214);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 214);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 214);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 214);
  sf_mex_assign(&c5_rhs214, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs214, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs214), "rhs", "rhs",
                  214);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs214), "lhs", "lhs",
                  214);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "context", "context", 215);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 215);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 215);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 215);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 215);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 215);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 215);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 215);
  sf_mex_assign(&c5_rhs215, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs215, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs215), "rhs", "rhs",
                  215);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs215), "lhs", "lhs",
                  215);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                  "context", "context", 216);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 216);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 216);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 216);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 216);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 216);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 216);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 216);
  sf_mex_assign(&c5_rhs216, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs216, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs216), "rhs", "rhs",
                  216);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs216), "lhs", "lhs",
                  216);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                  "context", "context", 217);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("length"), "name", "name", 217);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 217);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved",
                  "resolved", 217);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1303167806U), "fileTimeLo",
                  "fileTimeLo", 217);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 217);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 217);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 217);
  sf_mex_assign(&c5_rhs217, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs217, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs217), "rhs", "rhs",
                  217);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs217), "lhs", "lhs",
                  217);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                  "context", "context", 218);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 218);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 218);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 218);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 218);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 218);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 218);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 218);
  sf_mex_assign(&c5_rhs218, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs218, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs218), "rhs", "rhs",
                  218);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs218), "lhs", "lhs",
                  218);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                  "context", "context", 219);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.refblas.ixamax"),
                  "name", "name", 219);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 219);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "resolved", "resolved", 219);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 219);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 219);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 219);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 219);
  sf_mex_assign(&c5_rhs219, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs219, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs219), "rhs", "rhs",
                  219);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs219), "lhs", "lhs",
                  219);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 220);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.refblas.xcabs1"),
                  "name", "name", 220);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 220);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "resolved", "resolved", 220);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 220);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 220);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 220);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 220);
  sf_mex_assign(&c5_rhs220, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs220, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs220), "rhs", "rhs",
                  220);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs220), "lhs", "lhs",
                  220);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                  "context", "context", 221);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("abs"), "name", "name", 221);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 221);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 221);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 221);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 221);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 221);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 221);
  sf_mex_assign(&c5_rhs221, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs221, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs221), "rhs", "rhs",
                  221);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs221), "lhs", "lhs",
                  221);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 222);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 222);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 222);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 222);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 222);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 222);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 222);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 222);
  sf_mex_assign(&c5_rhs222, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs222, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs222), "rhs", "rhs",
                  222);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs222), "lhs", "lhs",
                  222);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                  "context", "context", 223);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 223);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 223);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 223);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 223);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 223);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 223);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 223);
  sf_mex_assign(&c5_rhs223, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs223, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs223), "rhs", "rhs",
                  223);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs223), "lhs", "lhs",
                  223);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 224);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_xswap"), "name", "name",
                  224);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 224);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"),
                  "resolved", "resolved", 224);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 224);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 224);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 224);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 224);
  sf_mex_assign(&c5_rhs224, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs224, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs224), "rhs", "rhs",
                  224);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs224), "lhs", "lhs",
                  224);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 225);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 225);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 225);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 225);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 225);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 225);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 225);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 225);
  sf_mex_assign(&c5_rhs225, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs225, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs225), "rhs", "rhs",
                  225);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs225), "lhs", "lhs",
                  225);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                  "context", 226);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.xswap"),
                  "name", "name", 226);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 226);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "resolved", "resolved", 226);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 226);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 226);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 226);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 226);
  sf_mex_assign(&c5_rhs226, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs226, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs226), "rhs", "rhs",
                  226);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs226), "lhs", "lhs",
                  226);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 227);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 227);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 227);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 227);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 227);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 227);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 227);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 227);
  sf_mex_assign(&c5_rhs227, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs227, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs227), "rhs", "rhs",
                  227);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs227), "lhs", "lhs",
                  227);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p!below_threshold"),
                  "context", "context", 228);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 228);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 228);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 228);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 228);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 228);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 228);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 228);
  sf_mex_assign(&c5_rhs228, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs228, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs228), "rhs", "rhs",
                  228);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs228), "lhs", "lhs",
                  228);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                  "context", "context", 229);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.refblas.xswap"),
                  "name", "name", 229);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 229);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "resolved", "resolved", 229);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 229);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 229);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 229);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 229);
  sf_mex_assign(&c5_rhs229, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs229, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs229), "rhs", "rhs",
                  229);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs229), "lhs", "lhs",
                  229);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 230);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("abs"), "name", "name", 230);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 230);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 230);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 230);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 230);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 230);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 230);
  sf_mex_assign(&c5_rhs230, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs230, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs230), "rhs", "rhs",
                  230);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs230), "lhs", "lhs",
                  230);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 231);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 231);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 231);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 231);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 231);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 231);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 231);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 231);
  sf_mex_assign(&c5_rhs231, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs231, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs231), "rhs", "rhs",
                  231);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs231), "lhs", "lhs",
                  231);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 232);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 232);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 232);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 232);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
                  "fileTimeLo", 232);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 232);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 232);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 232);
  sf_mex_assign(&c5_rhs232, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs232, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs232), "rhs", "rhs",
                  232);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs232), "lhs", "lhs",
                  232);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 233);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 233);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 233);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 233);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 233);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 233);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 233);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 233);
  sf_mex_assign(&c5_rhs233, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs233, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs233), "rhs", "rhs",
                  233);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs233), "lhs", "lhs",
                  233);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                  "context", "context", 234);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 234);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 234);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 234);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 234);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 234);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 234);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 234);
  sf_mex_assign(&c5_rhs234, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs234, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs234), "rhs", "rhs",
                  234);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs234), "lhs", "lhs",
                  234);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 235);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_div"), "name", "name", 235);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 235);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 235);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 235);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 235);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 235);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 235);
  sf_mex_assign(&c5_rhs235, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs235, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs235), "rhs", "rhs",
                  235);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs235), "lhs", "lhs",
                  235);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                  "context", "context", 236);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_xgeru"), "name", "name",
                  236);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 236);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"),
                  "resolved", "resolved", 236);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 236);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 236);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 236);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 236);
  sf_mex_assign(&c5_rhs236, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs236, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs236), "rhs", "rhs",
                  236);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs236), "lhs", "lhs",
                  236);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 237);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 237);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 237);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 237);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 237);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 237);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 237);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 237);
  sf_mex_assign(&c5_rhs237, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs237, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs237), "rhs", "rhs",
                  237);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs237), "lhs", "lhs",
                  237);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                  "context", 238);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.xgeru"),
                  "name", "name", 238);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 238);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                  "resolved", "resolved", 238);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 238);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 238);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 238);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 238);
  sf_mex_assign(&c5_rhs238, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs238, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs238), "rhs", "rhs",
                  238);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs238), "lhs", "lhs",
                  238);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                  "context", "context", 239);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.xger"),
                  "name", "name", 239);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 239);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "resolved", "resolved", 239);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 239);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 239);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 239);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 239);
  sf_mex_assign(&c5_rhs239, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs239, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs239), "rhs", "rhs",
                  239);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs239), "lhs", "lhs",
                  239);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "context", "context", 240);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 240);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 240);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 240);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 240);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 240);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 240);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 240);
  sf_mex_assign(&c5_rhs240, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs240, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs240), "rhs", "rhs",
                  240);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs240), "lhs", "lhs",
                  240);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 241);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 241);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 241);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 241);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 241);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 241);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 241);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 241);
  sf_mex_assign(&c5_rhs241, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs241, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs241), "rhs", "rhs",
                  241);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs241), "lhs", "lhs",
                  241);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 242);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.int"),
                  "name", "name", 242);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 242);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/int.p"),
                  "resolved", "resolved", 242);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 242);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 242);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 242);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 242);
  sf_mex_assign(&c5_rhs242, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs242, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs242), "rhs", "rhs",
                  242);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs242), "lhs", "lhs",
                  242);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 243);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("intmax"), "name", "name", 243);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 243);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved",
                  "resolved", 243);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1362283482U), "fileTimeLo",
                  "fileTimeLo", 243);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 243);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 243);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 243);
  sf_mex_assign(&c5_rhs243, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs243, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs243), "rhs", "rhs",
                  243);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs243), "lhs", "lhs",
                  243);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                  "context", "context", 244);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("min"), "name", "name", 244);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 244);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved",
                  "resolved", 244);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1311276918U), "fileTimeLo",
                  "fileTimeLo", 244);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 244);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 244);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 244);
  sf_mex_assign(&c5_rhs244, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs244, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs244), "rhs", "rhs",
                  244);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs244), "lhs", "lhs",
                  244);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                  "context", "context", 245);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.refblas.xger"),
                  "name", "name", 245);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 245);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                  "resolved", "resolved", 245);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 245);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 245);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 245);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 245);
  sf_mex_assign(&c5_rhs245, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs245, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs245), "rhs", "rhs",
                  245);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs245), "lhs", "lhs",
                  245);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                  "context", "context", 246);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.refblas.xgerx"),
                  "name", "name", 246);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 246);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "resolved", "resolved", 246);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 246);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 246);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 246);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 246);
  sf_mex_assign(&c5_rhs246, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs246, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs246), "rhs", "rhs",
                  246);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs246), "lhs", "lhs",
                  246);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 247);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("abs"), "name", "name", 247);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 247);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 247);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
                  "fileTimeLo", 247);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 247);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 247);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 247);
  sf_mex_assign(&c5_rhs247, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs247, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs247), "rhs", "rhs",
                  247);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs247), "lhs", "lhs",
                  247);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 248);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexMinus"),
                  "name", "name", 248);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 248);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                  "resolved", "resolved", 248);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 248);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 248);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 248);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 248);
  sf_mex_assign(&c5_rhs248, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs248, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs248), "rhs", "rhs",
                  248);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs248), "lhs", "lhs",
                  248);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 249);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 249);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 249);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 249);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 249);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 249);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 249);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 249);
  sf_mex_assign(&c5_rhs249, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs249, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs249), "rhs", "rhs",
                  249);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs249), "lhs", "lhs",
                  249);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 250);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 250);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 250);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 250);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 250);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 250);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 250);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 250);
  sf_mex_assign(&c5_rhs250, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs250, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs250), "rhs", "rhs",
                  250);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs250), "lhs", "lhs",
                  250);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                  "context", "context", 251);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 251);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.indexInt"),
                  "dominantType", "dominantType", 251);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 251);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 251);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 251);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 251);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 251);
  sf_mex_assign(&c5_rhs251, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs251, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs251), "rhs", "rhs",
                  251);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs251), "lhs", "lhs",
                  251);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!warn_singular"),
                  "context", "context", 252);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_warning"), "name", "name",
                  252);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 252);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                  "resolved", 252);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1286840402U), "fileTimeLo",
                  "fileTimeLo", 252);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 252);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 252);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 252);
  sf_mex_assign(&c5_rhs252, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs252, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs252), "rhs", "rhs",
                  252);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs252), "lhs", "lhs",
                  252);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 253);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 253);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 253);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 253);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 253);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 253);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 253);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 253);
  sf_mex_assign(&c5_rhs253, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs253, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs253), "rhs", "rhs",
                  253);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs253), "lhs", "lhs",
                  253);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 254);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 254);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 254);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 254);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 254);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 254);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 254);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 254);
  sf_mex_assign(&c5_rhs254, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs254, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs254), "rhs", "rhs",
                  254);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs254), "lhs", "lhs",
                  254);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                  "context", "context", 255);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("eml_xtrsm"), "name", "name",
                  255);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 255);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"),
                  "resolved", "resolved", 255);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1376002292U), "fileTimeLo",
                  "fileTimeLo", 255);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 255);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 255);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 255);
  sf_mex_assign(&c5_rhs255, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs255, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs255), "rhs", "rhs",
                  255);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs255), "lhs", "lhs",
                  255);
  sf_mex_destroy(&c5_rhs192);
  sf_mex_destroy(&c5_lhs192);
  sf_mex_destroy(&c5_rhs193);
  sf_mex_destroy(&c5_lhs193);
  sf_mex_destroy(&c5_rhs194);
  sf_mex_destroy(&c5_lhs194);
  sf_mex_destroy(&c5_rhs195);
  sf_mex_destroy(&c5_lhs195);
  sf_mex_destroy(&c5_rhs196);
  sf_mex_destroy(&c5_lhs196);
  sf_mex_destroy(&c5_rhs197);
  sf_mex_destroy(&c5_lhs197);
  sf_mex_destroy(&c5_rhs198);
  sf_mex_destroy(&c5_lhs198);
  sf_mex_destroy(&c5_rhs199);
  sf_mex_destroy(&c5_lhs199);
  sf_mex_destroy(&c5_rhs200);
  sf_mex_destroy(&c5_lhs200);
  sf_mex_destroy(&c5_rhs201);
  sf_mex_destroy(&c5_lhs201);
  sf_mex_destroy(&c5_rhs202);
  sf_mex_destroy(&c5_lhs202);
  sf_mex_destroy(&c5_rhs203);
  sf_mex_destroy(&c5_lhs203);
  sf_mex_destroy(&c5_rhs204);
  sf_mex_destroy(&c5_lhs204);
  sf_mex_destroy(&c5_rhs205);
  sf_mex_destroy(&c5_lhs205);
  sf_mex_destroy(&c5_rhs206);
  sf_mex_destroy(&c5_lhs206);
  sf_mex_destroy(&c5_rhs207);
  sf_mex_destroy(&c5_lhs207);
  sf_mex_destroy(&c5_rhs208);
  sf_mex_destroy(&c5_lhs208);
  sf_mex_destroy(&c5_rhs209);
  sf_mex_destroy(&c5_lhs209);
  sf_mex_destroy(&c5_rhs210);
  sf_mex_destroy(&c5_lhs210);
  sf_mex_destroy(&c5_rhs211);
  sf_mex_destroy(&c5_lhs211);
  sf_mex_destroy(&c5_rhs212);
  sf_mex_destroy(&c5_lhs212);
  sf_mex_destroy(&c5_rhs213);
  sf_mex_destroy(&c5_lhs213);
  sf_mex_destroy(&c5_rhs214);
  sf_mex_destroy(&c5_lhs214);
  sf_mex_destroy(&c5_rhs215);
  sf_mex_destroy(&c5_lhs215);
  sf_mex_destroy(&c5_rhs216);
  sf_mex_destroy(&c5_lhs216);
  sf_mex_destroy(&c5_rhs217);
  sf_mex_destroy(&c5_lhs217);
  sf_mex_destroy(&c5_rhs218);
  sf_mex_destroy(&c5_lhs218);
  sf_mex_destroy(&c5_rhs219);
  sf_mex_destroy(&c5_lhs219);
  sf_mex_destroy(&c5_rhs220);
  sf_mex_destroy(&c5_lhs220);
  sf_mex_destroy(&c5_rhs221);
  sf_mex_destroy(&c5_lhs221);
  sf_mex_destroy(&c5_rhs222);
  sf_mex_destroy(&c5_lhs222);
  sf_mex_destroy(&c5_rhs223);
  sf_mex_destroy(&c5_lhs223);
  sf_mex_destroy(&c5_rhs224);
  sf_mex_destroy(&c5_lhs224);
  sf_mex_destroy(&c5_rhs225);
  sf_mex_destroy(&c5_lhs225);
  sf_mex_destroy(&c5_rhs226);
  sf_mex_destroy(&c5_lhs226);
  sf_mex_destroy(&c5_rhs227);
  sf_mex_destroy(&c5_lhs227);
  sf_mex_destroy(&c5_rhs228);
  sf_mex_destroy(&c5_lhs228);
  sf_mex_destroy(&c5_rhs229);
  sf_mex_destroy(&c5_lhs229);
  sf_mex_destroy(&c5_rhs230);
  sf_mex_destroy(&c5_lhs230);
  sf_mex_destroy(&c5_rhs231);
  sf_mex_destroy(&c5_lhs231);
  sf_mex_destroy(&c5_rhs232);
  sf_mex_destroy(&c5_lhs232);
  sf_mex_destroy(&c5_rhs233);
  sf_mex_destroy(&c5_lhs233);
  sf_mex_destroy(&c5_rhs234);
  sf_mex_destroy(&c5_lhs234);
  sf_mex_destroy(&c5_rhs235);
  sf_mex_destroy(&c5_lhs235);
  sf_mex_destroy(&c5_rhs236);
  sf_mex_destroy(&c5_lhs236);
  sf_mex_destroy(&c5_rhs237);
  sf_mex_destroy(&c5_lhs237);
  sf_mex_destroy(&c5_rhs238);
  sf_mex_destroy(&c5_lhs238);
  sf_mex_destroy(&c5_rhs239);
  sf_mex_destroy(&c5_lhs239);
  sf_mex_destroy(&c5_rhs240);
  sf_mex_destroy(&c5_lhs240);
  sf_mex_destroy(&c5_rhs241);
  sf_mex_destroy(&c5_lhs241);
  sf_mex_destroy(&c5_rhs242);
  sf_mex_destroy(&c5_lhs242);
  sf_mex_destroy(&c5_rhs243);
  sf_mex_destroy(&c5_lhs243);
  sf_mex_destroy(&c5_rhs244);
  sf_mex_destroy(&c5_lhs244);
  sf_mex_destroy(&c5_rhs245);
  sf_mex_destroy(&c5_lhs245);
  sf_mex_destroy(&c5_rhs246);
  sf_mex_destroy(&c5_lhs246);
  sf_mex_destroy(&c5_rhs247);
  sf_mex_destroy(&c5_lhs247);
  sf_mex_destroy(&c5_rhs248);
  sf_mex_destroy(&c5_lhs248);
  sf_mex_destroy(&c5_rhs249);
  sf_mex_destroy(&c5_lhs249);
  sf_mex_destroy(&c5_rhs250);
  sf_mex_destroy(&c5_lhs250);
  sf_mex_destroy(&c5_rhs251);
  sf_mex_destroy(&c5_lhs251);
  sf_mex_destroy(&c5_rhs252);
  sf_mex_destroy(&c5_lhs252);
  sf_mex_destroy(&c5_rhs253);
  sf_mex_destroy(&c5_lhs253);
  sf_mex_destroy(&c5_rhs254);
  sf_mex_destroy(&c5_lhs254);
  sf_mex_destroy(&c5_rhs255);
  sf_mex_destroy(&c5_lhs255);
}

static void c5_e_info_helper(const mxArray **c5_info)
{
  const mxArray *c5_rhs256 = NULL;
  const mxArray *c5_lhs256 = NULL;
  const mxArray *c5_rhs257 = NULL;
  const mxArray *c5_lhs257 = NULL;
  const mxArray *c5_rhs258 = NULL;
  const mxArray *c5_lhs258 = NULL;
  const mxArray *c5_rhs259 = NULL;
  const mxArray *c5_lhs259 = NULL;
  const mxArray *c5_rhs260 = NULL;
  const mxArray *c5_lhs260 = NULL;
  const mxArray *c5_rhs261 = NULL;
  const mxArray *c5_lhs261 = NULL;
  const mxArray *c5_rhs262 = NULL;
  const mxArray *c5_lhs262 = NULL;
  const mxArray *c5_rhs263 = NULL;
  const mxArray *c5_lhs263 = NULL;
  const mxArray *c5_rhs264 = NULL;
  const mxArray *c5_lhs264 = NULL;
  const mxArray *c5_rhs265 = NULL;
  const mxArray *c5_lhs265 = NULL;
  const mxArray *c5_rhs266 = NULL;
  const mxArray *c5_lhs266 = NULL;
  const mxArray *c5_rhs267 = NULL;
  const mxArray *c5_lhs267 = NULL;
  const mxArray *c5_rhs268 = NULL;
  const mxArray *c5_lhs268 = NULL;
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                  "context", 256);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 256);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 256);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 256);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 256);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 256);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 256);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 256);
  sf_mex_assign(&c5_rhs256, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs256, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs256), "rhs", "rhs",
                  256);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs256), "lhs", "lhs",
                  256);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                  "context", 257);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.xtrsm"),
                  "name", "name", 257);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 257);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "resolved", "resolved", 257);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 257);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 257);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 257);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 257);
  sf_mex_assign(&c5_rhs257, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs257, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs257), "rhs", "rhs",
                  257);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs257), "lhs", "lhs",
                  257);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 258);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 258);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 258);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 258);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 258);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 258);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 258);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 258);
  sf_mex_assign(&c5_rhs258, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs258, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs258), "rhs", "rhs",
                  258);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs258), "lhs", "lhs",
                  258);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p!below_threshold"),
                  "context", "context", 259);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 259);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 259);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 259);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 259);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 259);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 259);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 259);
  sf_mex_assign(&c5_rhs259, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs259, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs259), "rhs", "rhs",
                  259);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs259), "lhs", "lhs",
                  259);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 260);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 260);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 260);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 260);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 260);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 260);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 260);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 260);
  sf_mex_assign(&c5_rhs260, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs260, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs260), "rhs", "rhs",
                  260);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs260), "lhs", "lhs",
                  260);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                  "context", "context", 261);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.refblas.xtrsm"),
                  "name", "name", 261);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 261);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "resolved", "resolved", 261);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 261);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 261);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 261);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 261);
  sf_mex_assign(&c5_rhs261, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs261, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs261), "rhs", "rhs",
                  261);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs261), "lhs", "lhs",
                  261);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 262);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 262);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 262);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 262);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 262);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 262);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 262);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 262);
  sf_mex_assign(&c5_rhs262, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs262, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs262), "rhs", "rhs",
                  262);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs262), "lhs", "lhs",
                  262);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 263);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 263);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 263);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 263);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 263);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 263);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 263);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 263);
  sf_mex_assign(&c5_rhs263, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs263, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs263), "rhs", "rhs",
                  263);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs263), "lhs", "lhs",
                  263);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 264);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "eml_int_forloop_overflow_check"), "name", "name", 264);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 264);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                  "resolved", "resolved", 264);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1397279022U), "fileTimeLo",
                  "fileTimeLo", 264);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 264);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 264);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 264);
  sf_mex_assign(&c5_rhs264, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs264, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs264), "rhs", "rhs",
                  264);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs264), "lhs", "lhs",
                  264);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                  "context", "context", 265);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("rdivide"), "name", "name", 265);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 265);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 265);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 265);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 265);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 265);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 265);
  sf_mex_assign(&c5_rhs265, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs265, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs265), "rhs", "rhs",
                  265);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs265), "lhs", "lhs",
                  265);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Control06.m"),
                  "context", "context", 266);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("bezier"), "name", "name", 266);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 266);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/shared_utils/Polynomial/bezier.m"),
                  "resolved", "resolved", 266);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1432837205U), "fileTimeLo",
                  "fileTimeLo", 266);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 266);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 266);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 266);
  sf_mex_assign(&c5_rhs266, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs266, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs266), "rhs", "rhs",
                  266);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs266), "lhs", "lhs",
                  266);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Control06.m"),
                  "context", "context", 267);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("power"), "name", "name", 267);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 267);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 267);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1395346506U), "fileTimeLo",
                  "fileTimeLo", 267);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 267);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 267);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 267);
  sf_mex_assign(&c5_rhs267, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs267, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs267), "rhs", "rhs",
                  267);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs267), "lhs", "lhs",
                  267);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[E]C:/Users/rosshart/Desktop/SVN/MARLO_3D_Controllers/Walking/InPlace/Rocking/FeedbackControl/ATRIAS3D_ZD_Control06.m"),
                  "context", "context", 268);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("rdivide"), "name", "name", 268);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 268);
  sf_mex_addfield(*c5_info, c5_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 268);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 268);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 268);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 268);
  sf_mex_addfield(*c5_info, c5_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 268);
  sf_mex_assign(&c5_rhs268, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c5_lhs268, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_rhs268), "rhs", "rhs",
                  268);
  sf_mex_addfield(*c5_info, sf_mex_duplicatearraysafe(&c5_lhs268), "lhs", "lhs",
                  268);
  sf_mex_destroy(&c5_rhs256);
  sf_mex_destroy(&c5_lhs256);
  sf_mex_destroy(&c5_rhs257);
  sf_mex_destroy(&c5_lhs257);
  sf_mex_destroy(&c5_rhs258);
  sf_mex_destroy(&c5_lhs258);
  sf_mex_destroy(&c5_rhs259);
  sf_mex_destroy(&c5_lhs259);
  sf_mex_destroy(&c5_rhs260);
  sf_mex_destroy(&c5_lhs260);
  sf_mex_destroy(&c5_rhs261);
  sf_mex_destroy(&c5_lhs261);
  sf_mex_destroy(&c5_rhs262);
  sf_mex_destroy(&c5_lhs262);
  sf_mex_destroy(&c5_rhs263);
  sf_mex_destroy(&c5_lhs263);
  sf_mex_destroy(&c5_rhs264);
  sf_mex_destroy(&c5_lhs264);
  sf_mex_destroy(&c5_rhs265);
  sf_mex_destroy(&c5_lhs265);
  sf_mex_destroy(&c5_rhs266);
  sf_mex_destroy(&c5_lhs266);
  sf_mex_destroy(&c5_rhs267);
  sf_mex_destroy(&c5_lhs267);
  sf_mex_destroy(&c5_rhs268);
  sf_mex_destroy(&c5_lhs268);
}

static real_T c5_rdivide(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_x, real_T c5_b_y)
{
  real_T c5_b_x;
  real_T c5_c_y;
  real_T c5_c_x;
  real_T c5_d_y;
  (void)chartInstance;
  c5_b_x = c5_x;
  c5_c_y = c5_b_y;
  c5_c_x = c5_b_x;
  c5_d_y = c5_c_y;
  return c5_c_x / c5_d_y;
}

static void c5_repmat(SFc5_LibWalkingInstanceStruct *chartInstance, real_T c5_a
                      [13], real_T c5_b[78])
{
  int32_T c5_jtilecol;
  int32_T c5_b_jtilecol;
  int32_T c5_ibtile;
  int32_T c5_ibmat;
  int32_T c5_ibcol;
  int32_T c5_k;
  int32_T c5_b_k;
  c5_eml_switch_helper(chartInstance);
  c5_eml_switch_helper(chartInstance);
  for (c5_jtilecol = 1; c5_jtilecol < 7; c5_jtilecol++) {
    c5_b_jtilecol = c5_jtilecol - 1;
    c5_ibtile = c5_b_jtilecol * 13;
    c5_ibmat = c5_ibtile;
    c5_ibcol = c5_ibmat;
    c5_eml_switch_helper(chartInstance);
    for (c5_k = 1; c5_k < 14; c5_k++) {
      c5_b_k = c5_k - 1;
      c5_b[c5_ibcol + c5_b_k] = c5_a[c5_b_k];
    }
  }
}

static void c5_eml_switch_helper(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_eml_scalar_eg(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_threshold(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_b_threshold(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_b_eml_scalar_eg(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_eml_li_find(SFc5_LibWalkingInstanceStruct *chartInstance,
  boolean_T c5_x, int32_T c5_y_data[], int32_T c5_y_sizes[2])
{
  boolean_T c5_b_x;
  int32_T c5_k;
  int32_T c5_tmp_sizes[2];
  int32_T c5_iv9[2];
  int32_T c5_i617;
  int32_T c5_i618;
  int32_T c5_loop_ub;
  int32_T c5_i619;
  int32_T c5_tmp_data[1];
  int32_T c5_i620;
  (void)chartInstance;
  c5_b_x = c5_x;
  c5_k = 0;
  if (c5_b_x) {
    c5_k = 1;
  }

  c5_tmp_sizes[0] = 1;
  c5_iv9[0] = 1;
  c5_iv9[1] = c5_k;
  c5_tmp_sizes[1] = c5_iv9[1];
  c5_i617 = c5_tmp_sizes[0];
  c5_i618 = c5_tmp_sizes[1];
  c5_loop_ub = c5_k - 1;
  for (c5_i619 = 0; c5_i619 <= c5_loop_ub; c5_i619++) {
    c5_tmp_data[c5_i619] = 0;
  }

  for (c5_i620 = 0; c5_i620 < 2; c5_i620++) {
    c5_y_sizes[c5_i620] = c5_tmp_sizes[c5_i620];
  }

  if (c5_x) {
    _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c5_y_sizes[1], 1, 0);
    c5_y_data[0] = 1;
  }
}

static void c5_b_repmat(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_a, real_T c5_b[2])
{
  int32_T c5_i621;
  c5_eml_switch_helper(chartInstance);
  for (c5_i621 = 0; c5_i621 < 2; c5_i621++) {
    c5_b[c5_i621] = c5_a;
  }
}

static void c5_c_repmat(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_a, real_T c5_b[6])
{
  int32_T c5_i622;
  c5_eml_switch_helper(chartInstance);
  for (c5_i622 = 0; c5_i622 < 6; c5_i622++) {
    c5_b[c5_i622] = c5_a;
  }
}

static void c5_eps(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_b_eml_li_find(SFc5_LibWalkingInstanceStruct *chartInstance,
  boolean_T c5_x[6], int32_T c5_y_data[], int32_T *c5_y_sizes)
{
  int32_T c5_k;
  int32_T c5_i;
  int32_T c5_b_i;
  int32_T c5_a;
  int32_T c5_b_a;
  const mxArray *c5_b_y = NULL;
  int32_T c5_tmp_sizes;
  int32_T c5_loop_ub;
  int32_T c5_i623;
  int32_T c5_tmp_data[6];
  int32_T c5_j;
  int32_T c5_c_i;
  int32_T c5_d_i;
  int32_T c5_c_a;
  int32_T c5_d_a;
  c5_k = 0;
  c5_eml_switch_helper(chartInstance);
  for (c5_i = 1; c5_i < 7; c5_i++) {
    c5_b_i = c5_i - 1;
    if (c5_x[c5_b_i]) {
      c5_a = c5_k;
      c5_b_a = c5_a + 1;
      c5_k = c5_b_a;
    }
  }

  if (c5_k <= 6) {
  } else {
    c5_b_y = NULL;
    sf_mex_assign(&c5_b_y, sf_mex_create("y", "Assertion failed.", 15, 0U, 0U,
      0U, 2, 1, strlen("Assertion failed.")), false);
    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14, c5_b_y);
  }

  c5_tmp_sizes = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c5_k);
  c5_loop_ub = (int32_T)_SFD_NON_NEGATIVE_CHECK("", (real_T)c5_k) - 1;
  for (c5_i623 = 0; c5_i623 <= c5_loop_ub; c5_i623++) {
    c5_tmp_data[c5_i623] = 0;
  }

  *c5_y_sizes = c5_tmp_sizes;
  c5_j = 1;
  c5_eml_switch_helper(chartInstance);
  for (c5_c_i = 1; c5_c_i < 7; c5_c_i++) {
    c5_d_i = c5_c_i;
    if (c5_x[c5_d_i - 1]) {
      c5_y_data[_SFD_EML_ARRAY_BOUNDS_CHECK("", c5_j, 1, *c5_y_sizes, 1, 0) - 1]
        = c5_d_i;
      c5_c_a = c5_j;
      c5_d_a = c5_c_a + 1;
      c5_j = c5_d_a;
    }
  }
}

static void c5_c_eml_scalar_eg(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_d_eml_scalar_eg(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static real_T c5_mpower(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_a)
{
  real_T c5_b_a;
  real_T c5_c_a;
  real_T c5_ak;
  real_T c5_d_a;
  c5_b_a = c5_a;
  c5_c_a = c5_b_a;
  c5_b_eml_scalar_eg(chartInstance);
  c5_ak = c5_c_a;
  c5_d_a = c5_ak;
  c5_b_eml_scalar_eg(chartInstance);
  return c5_d_a * c5_d_a;
}

static boolean_T c5_any(SFc5_LibWalkingInstanceStruct *chartInstance, boolean_T
  c5_x)
{
  boolean_T c5_b_x;
  boolean_T c5_b1;
  (void)chartInstance;
  c5_b_x = c5_x;
  c5_b1 = ((real_T)c5_b_x == 0.0);
  return !c5_b1;
}

static void c5_e_eml_scalar_eg(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_mldivide(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_A[36], real_T c5_B[6], real_T c5_Y[6])
{
  int32_T c5_i624;
  real_T c5_b_A[36];
  int32_T c5_info;
  int32_T c5_ipiv[6];
  int32_T c5_b_info;
  int32_T c5_c_info;
  int32_T c5_d_info;
  int32_T c5_i625;
  int32_T c5_xi;
  int32_T c5_b_xi;
  int32_T c5_ip;
  real_T c5_temp;
  int32_T c5_i626;
  real_T c5_c_A[36];
  int32_T c5_i627;
  real_T c5_d_A[36];
  for (c5_i624 = 0; c5_i624 < 36; c5_i624++) {
    c5_b_A[c5_i624] = c5_A[c5_i624];
  }

  c5_b_eml_matlab_zgetrf(chartInstance, c5_b_A, c5_ipiv, &c5_info);
  c5_b_info = c5_info;
  c5_c_info = c5_b_info;
  c5_d_info = c5_c_info;
  if (c5_d_info > 0) {
    c5_eml_warning(chartInstance);
  }

  for (c5_i625 = 0; c5_i625 < 6; c5_i625++) {
    c5_Y[c5_i625] = c5_B[c5_i625];
  }

  c5_eml_switch_helper(chartInstance);
  for (c5_xi = 1; c5_xi < 6; c5_xi++) {
    c5_b_xi = c5_xi - 1;
    if (c5_ipiv[c5_b_xi] != c5_b_xi + 1) {
      c5_ip = c5_ipiv[c5_b_xi];
      c5_temp = c5_Y[c5_b_xi];
      c5_Y[c5_b_xi] = c5_Y[_SFD_EML_ARRAY_BOUNDS_CHECK("", c5_ip, 1, 6, 1, 0) -
        1];
      c5_Y[c5_ip - 1] = c5_temp;
    }
  }

  for (c5_i626 = 0; c5_i626 < 36; c5_i626++) {
    c5_c_A[c5_i626] = c5_b_A[c5_i626];
  }

  c5_c_eml_xtrsm(chartInstance, c5_c_A, c5_Y);
  for (c5_i627 = 0; c5_i627 < 36; c5_i627++) {
    c5_d_A[c5_i627] = c5_b_A[c5_i627];
  }

  c5_d_eml_xtrsm(chartInstance, c5_d_A, c5_Y);
}

static void c5_realmin(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_eml_matlab_zgetrf(SFc5_LibWalkingInstanceStruct *chartInstance,
  real_T c5_A[36], real_T c5_b_A[36], int32_T c5_ipiv[6], int32_T *c5_info)
{
  int32_T c5_i628;
  for (c5_i628 = 0; c5_i628 < 36; c5_i628++) {
    c5_b_A[c5_i628] = c5_A[c5_i628];
  }

  c5_b_eml_matlab_zgetrf(chartInstance, c5_b_A, c5_ipiv, c5_info);
}

static int32_T c5_eml_ixamax(SFc5_LibWalkingInstanceStruct *chartInstance,
  int32_T c5_n, real_T c5_x[36], int32_T c5_ix0)
{
  int32_T c5_idxmax;
  int32_T c5_b_n;
  int32_T c5_b_ix0;
  int32_T c5_c_n;
  int32_T c5_c_ix0;
  int32_T c5_ix;
  real_T c5_b_x;
  real_T c5_c_x;
  real_T c5_d_x;
  real_T c5_b_y;
  real_T c5_e_x;
  real_T c5_f_x;
  real_T c5_c_y;
  real_T c5_smax;
  int32_T c5_d_n;
  int32_T c5_k;
  int32_T c5_b_k;
  int32_T c5_a;
  real_T c5_g_x;
  real_T c5_h_x;
  real_T c5_i_x;
  real_T c5_d_y;
  real_T c5_j_x;
  real_T c5_k_x;
  real_T c5_e_y;
  real_T c5_b_s;
  c5_b_n = c5_n;
  c5_b_ix0 = c5_ix0;
  c5_c_n = c5_b_n;
  c5_c_ix0 = c5_b_ix0;
  c5_idxmax = 1;
  c5_ix = c5_c_ix0;
  c5_b_x = c5_x[c5_ix - 1];
  c5_c_x = c5_b_x;
  c5_d_x = c5_c_x;
  c5_b_y = muDoubleScalarAbs(c5_d_x);
  c5_e_x = 0.0;
  c5_f_x = c5_e_x;
  c5_c_y = muDoubleScalarAbs(c5_f_x);
  c5_smax = c5_b_y + c5_c_y;
  c5_d_n = c5_c_n;
  c5_eml_switch_helper(chartInstance);
  c5_eml_switch_helper(chartInstance);
  for (c5_k = 2; c5_k <= c5_d_n; c5_k++) {
    c5_b_k = c5_k;
    c5_a = c5_ix + 1;
    c5_ix = c5_a;
    c5_g_x = c5_x[_SFD_EML_ARRAY_BOUNDS_CHECK("", c5_ix, 1, 36, 1, 0) - 1];
    c5_h_x = c5_g_x;
    c5_i_x = c5_h_x;
    c5_d_y = muDoubleScalarAbs(c5_i_x);
    c5_j_x = 0.0;
    c5_k_x = c5_j_x;
    c5_e_y = muDoubleScalarAbs(c5_k_x);
    c5_b_s = c5_d_y + c5_e_y;
    if (c5_b_s > c5_smax) {
      c5_idxmax = c5_b_k;
      c5_smax = c5_b_s;
    }
  }

  return c5_idxmax;
}

static void c5_check_forloop_overflow_error(SFc5_LibWalkingInstanceStruct
  *chartInstance, boolean_T c5_overflow)
{
  int32_T c5_i629;
  static char_T c5_cv0[34] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'i', 'n', 't', '_', 'f', 'o', 'r', 'l', 'o', 'o', 'p',
    '_', 'o', 'v', 'e', 'r', 'f', 'l', 'o', 'w' };

  char_T c5_b_u[34];
  const mxArray *c5_b_y = NULL;
  int32_T c5_i630;
  static char_T c5_cv1[5] = { 'i', 'n', 't', '3', '2' };

  char_T c5_c_u[5];
  const mxArray *c5_c_y = NULL;
  (void)chartInstance;
  (void)c5_overflow;
  for (c5_i629 = 0; c5_i629 < 34; c5_i629++) {
    c5_b_u[c5_i629] = c5_cv0[c5_i629];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 34),
                false);
  for (c5_i630 = 0; c5_i630 < 5; c5_i630++) {
    c5_c_u[c5_i630] = c5_cv1[c5_i630];
  }

  c5_c_y = NULL;
  sf_mex_assign(&c5_c_y, sf_mex_create("y", c5_c_u, 10, 0U, 1U, 0U, 2, 1, 5),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "error", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    2U, 14, c5_b_y, 14, c5_c_y));
}

static void c5_b_eml_switch_helper(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_eml_xgeru(SFc5_LibWalkingInstanceStruct *chartInstance, int32_T
  c5_m, int32_T c5_n, real_T c5_alpha1, int32_T c5_ix0, int32_T c5_iy0, real_T
  c5_A[36], int32_T c5_ia0, real_T c5_b_A[36])
{
  int32_T c5_i631;
  for (c5_i631 = 0; c5_i631 < 36; c5_i631++) {
    c5_b_A[c5_i631] = c5_A[c5_i631];
  }

  c5_b_eml_xgeru(chartInstance, c5_m, c5_n, c5_alpha1, c5_ix0, c5_iy0, c5_b_A,
                 c5_ia0);
}

static void c5_eml_warning(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  int32_T c5_i632;
  static char_T c5_varargin_1[27] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A',
    'T', 'L', 'A', 'B', ':', 's', 'i', 'n', 'g', 'u', 'l', 'a', 'r', 'M', 'a',
    't', 'r', 'i', 'x' };

  char_T c5_b_u[27];
  const mxArray *c5_b_y = NULL;
  (void)chartInstance;
  for (c5_i632 = 0; c5_i632 < 27; c5_i632++) {
    c5_b_u[c5_i632] = c5_varargin_1[c5_i632];
  }

  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", c5_b_u, 10, 0U, 1U, 0U, 2, 1, 27),
                false);
  sf_mex_call_debug(sfGlobalDebugInstanceStruct, "warning", 0U, 1U, 14,
                    sf_mex_call_debug(sfGlobalDebugInstanceStruct, "message", 1U,
    1U, 14, c5_b_y));
}

static void c5_eml_xtrsm(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_A[36], real_T c5_B[6], real_T c5_b_B[6])
{
  int32_T c5_i633;
  int32_T c5_i634;
  real_T c5_b_A[36];
  for (c5_i633 = 0; c5_i633 < 6; c5_i633++) {
    c5_b_B[c5_i633] = c5_B[c5_i633];
  }

  for (c5_i634 = 0; c5_i634 < 36; c5_i634++) {
    c5_b_A[c5_i634] = c5_A[c5_i634];
  }

  c5_c_eml_xtrsm(chartInstance, c5_b_A, c5_b_B);
}

static void c5_below_threshold(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  c5_c_eml_switch_helper(chartInstance);
}

static void c5_c_eml_switch_helper(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_scalarEg(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c5_b_eml_xtrsm(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_A[36], real_T c5_B[6], real_T c5_b_B[6])
{
  int32_T c5_i635;
  int32_T c5_i636;
  real_T c5_b_A[36];
  for (c5_i635 = 0; c5_i635 < 6; c5_i635++) {
    c5_b_B[c5_i635] = c5_B[c5_i635];
  }

  for (c5_i636 = 0; c5_i636 < 36; c5_i636++) {
    c5_b_A[c5_i636] = c5_A[c5_i636];
  }

  c5_d_eml_xtrsm(chartInstance, c5_b_A, c5_b_B);
}

static void c5_power(SFc5_LibWalkingInstanceStruct *chartInstance, real_T c5_a[6],
                     real_T c5_b_y[6])
{
  int32_T c5_k;
  real_T c5_b_k;
  real_T c5_ak;
  real_T c5_b_a;
  real_T c5_c_y;
  for (c5_k = 0; c5_k < 6; c5_k++) {
    c5_b_k = 1.0 + (real_T)c5_k;
    c5_ak = c5_a[(int32_T)c5_b_k - 1];
    c5_b_a = c5_ak;
    c5_b_eml_scalar_eg(chartInstance);
    c5_c_y = c5_b_a * c5_b_a;
    c5_b_y[(int32_T)c5_b_k - 1] = c5_c_y;
  }
}

static void c5_b_rdivide(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_x[6], real_T c5_b_y[6], real_T c5_z[6])
{
  int32_T c5_i637;
  (void)chartInstance;
  for (c5_i637 = 0; c5_i637 < 6; c5_i637++) {
    c5_z[c5_i637] = c5_x[c5_i637] / c5_b_y[c5_i637];
  }
}

static const mxArray *c5_v_sf_marshallOut(void *chartInstanceVoid, void
  *c5_inData)
{
  const mxArray *c5_mxArrayOutData = NULL;
  int32_T c5_b_u;
  const mxArray *c5_b_y = NULL;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxArrayOutData = NULL;
  c5_b_u = *(int32_T *)c5_inData;
  c5_b_y = NULL;
  sf_mex_assign(&c5_b_y, sf_mex_create("y", &c5_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c5_mxArrayOutData, c5_b_y, false);
  return c5_mxArrayOutData;
}

static int32_T c5_gb_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  int32_T c5_b_y;
  int32_T c5_i638;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), &c5_i638, 1, 6, 0U, 0, 0U, 0);
  c5_b_y = c5_i638;
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_v_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c5_mxArrayInData, const char_T *c5_varName, void *c5_outData)
{
  const mxArray *c5_b_sfEvent;
  const char_T *c5_identifier;
  emlrtMsgIdentifier c5_thisId;
  int32_T c5_b_y;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_b_sfEvent = sf_mex_dup(c5_mxArrayInData);
  c5_identifier = c5_varName;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_y = c5_gb_emlrt_marshallIn(chartInstance, sf_mex_dup(c5_b_sfEvent),
    &c5_thisId);
  sf_mex_destroy(&c5_b_sfEvent);
  *(int32_T *)c5_outData = c5_b_y;
  sf_mex_destroy(&c5_mxArrayInData);
}

static const mxArray *c5_ControlState_bus_io(void *chartInstanceVoid, void
  *c5_pData)
{
  const mxArray *c5_mxVal = NULL;
  c5_ControlStateBus c5_tmp;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxVal = NULL;
  c5_tmp.ControllerMode = *(real_T *)&((char_T *)(c5_ControlStateBus *)c5_pData)
    [0];
  c5_tmp.SupportState = *(real_T *)&((char_T *)(c5_ControlStateBus *)c5_pData)[8];
  c5_tmp.StanceLeg = *(real_T *)&((char_T *)(c5_ControlStateBus *)c5_pData)[16];
  c5_tmp.InDoubleSupport = *(real_T *)&((char_T *)(c5_ControlStateBus *)c5_pData)
    [24];
  c5_tmp.RollPhase = *(real_T *)&((char_T *)(c5_ControlStateBus *)c5_pData)[32];
  c5_tmp.StepCount = *(real_T *)&((char_T *)(c5_ControlStateBus *)c5_pData)[40];
  c5_tmp.Error = *(real_T *)&((char_T *)(c5_ControlStateBus *)c5_pData)[48];
  sf_mex_assign(&c5_mxVal, c5_d_sf_marshallOut(chartInstance, &c5_tmp), false);
  return c5_mxVal;
}

static const mxArray *c5_ControlParams_bus_io(void *chartInstanceVoid, void
  *c5_pData)
{
  const mxArray *c5_mxVal = NULL;
  c5_ControlParamsBus c5_tmp;
  int32_T c5_i639;
  int32_T c5_i640;
  int32_T c5_i641;
  int32_T c5_i642;
  int32_T c5_i643;
  int32_T c5_i644;
  int32_T c5_i645;
  int32_T c5_i646;
  int32_T c5_i647;
  int32_T c5_i648;
  int32_T c5_i649;
  int32_T c5_i650;
  int32_T c5_i651;
  int32_T c5_i652;
  int32_T c5_i653;
  int32_T c5_i654;
  int32_T c5_i655;
  int32_T c5_i656;
  int32_T c5_i657;
  int32_T c5_i658;
  int32_T c5_i659;
  int32_T c5_i660;
  int32_T c5_i661;
  int32_T c5_i662;
  int32_T c5_i663;
  int32_T c5_i664;
  int32_T c5_i665;
  int32_T c5_i666;
  int32_T c5_i667;
  int32_T c5_i668;
  int32_T c5_i669;
  int32_T c5_i670;
  int32_T c5_i671;
  int32_T c5_i672;
  int32_T c5_i673;
  int32_T c5_i674;
  int32_T c5_i675;
  int32_T c5_i676;
  int32_T c5_i677;
  int32_T c5_i678;
  int32_T c5_i679;
  int32_T c5_i680;
  int32_T c5_i681;
  int32_T c5_i682;
  int32_T c5_i683;
  int32_T c5_i684;
  int32_T c5_i685;
  SFc5_LibWalkingInstanceStruct *chartInstance;
  chartInstance = (SFc5_LibWalkingInstanceStruct *)chartInstanceVoid;
  c5_mxVal = NULL;
  c5_tmp.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [0];
  c5_tmp.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [8];
  c5_tmp.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [16];
  c5_tmp.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [24];
  c5_tmp.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [32];
  c5_tmp.Supervisory.ImpactThresholdKASpringRel = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [40];
  c5_tmp.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [48];
  c5_tmp.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [56];
  c5_tmp.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [64];
  c5_tmp.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [72];
  c5_tmp.Supervisory.TransitionThresholdTorsoVel = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [80];
  for (c5_i639 = 0; c5_i639 < 2; c5_i639++) {
    c5_tmp.Supervisory.KAInjection[c5_i639] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
      [88])[c5_i639];
  }

  c5_tmp.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [104];
  c5_tmp.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [112];
  for (c5_i640 = 0; c5_i640 < 6; c5_i640++) {
    c5_tmp.Supervisory.VBLAParams[c5_i640] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
      [120])[c5_i640];
  }

  for (c5_i641 = 0; c5_i641 < 13; c5_i641++) {
    c5_tmp.Supervisory.BalanceParams[c5_i641] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
      [168])[c5_i641];
  }

  for (c5_i642 = 0; c5_i642 < 5; c5_i642++) {
    c5_tmp.Supervisory.GaitTweaks[c5_i642] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
      [272])[c5_i642];
  }

  c5_tmp.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [312];
  c5_tmp.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [320];
  c5_tmp.Supervisory.RunMode = *(real_T *)&((char_T *)(c5_SupervisoryParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[0])[328];
  c5_tmp.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [336];
  for (c5_i643 = 0; c5_i643 < 6; c5_i643++) {
    c5_tmp.Supervisory.ErrorZeroFactor[c5_i643] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
      [344])[c5_i643];
  }

  for (c5_i644 = 0; c5_i644 < 6; c5_i644++) {
    c5_tmp.Supervisory.ErrorVelZeroFactor[c5_i644] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
      [392])[c5_i644];
  }

  c5_tmp.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [440];
  c5_tmp.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [448];
  c5_tmp.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [456];
  c5_tmp.Supervisory.TPosing = *(real_T *)&((char_T *)(c5_SupervisoryParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[0])[464];
  c5_tmp.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [472];
  c5_tmp.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [480];
  c5_tmp.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [488];
  c5_tmp.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [496];
  c5_tmp.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [504];
  c5_tmp.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [512];
  c5_tmp.Supervisory.VelocityControlTorsoGain = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [520];
  c5_tmp.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [528];
  c5_tmp.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [536];
  c5_tmp.Supervisory.Theta0 = *(real_T *)&((char_T *)(c5_SupervisoryParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[0])[544];
  c5_tmp.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [552];
  c5_tmp.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [560];
  c5_tmp.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [568];
  c5_tmp.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [576];
  c5_tmp.Supervisory.MaxError = *(real_T *)&((char_T *)(c5_SupervisoryParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[0])[584];
  c5_tmp.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [592];
  c5_tmp.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [600];
  for (c5_i645 = 0; c5_i645 < 6; c5_i645++) {
    c5_tmp.Supervisory.K1MidStanceUpdate[c5_i645] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
      [608])[c5_i645];
  }

  for (c5_i646 = 0; c5_i646 < 6; c5_i646++) {
    c5_tmp.Supervisory.K2MidStanceUpdate[c5_i646] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
      [656])[c5_i646];
  }

  c5_tmp.Supervisory.EnableVelocityBasedUpdate = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [704];
  for (c5_i647 = 0; c5_i647 < 6; c5_i647++) {
    c5_tmp.Supervisory.VelocityBasedUpdateK1[c5_i647] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
      [712])[c5_i647];
  }

  for (c5_i648 = 0; c5_i648 < 6; c5_i648++) {
    c5_tmp.Supervisory.VelocityBasedUpdateK2[c5_i648] = ((real_T *)&((char_T *)
      (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
      [760])[c5_i648];
  }

  c5_tmp.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [808];
  c5_i649 = 0;
  for (c5_i650 = 0; c5_i650 < 2; c5_i650++) {
    for (c5_i651 = 0; c5_i651 < 6; c5_i651++) {
      c5_tmp.Supervisory.VelocityBasedUpdateLimits[c5_i651 + c5_i649] = ((real_T
        *)&((char_T *)(c5_SupervisoryParamsBus *)&((char_T *)
        (c5_ControlParamsBus *)c5_pData)[0])[816])[c5_i651 + c5_i649];
    }

    c5_i649 += 6;
  }

  c5_tmp.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c5_SupervisoryParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[0])
    [912];
  c5_tmp.Discrete.TLastUpdate = *(real_T *)&((char_T *)(c5_DiscreteParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[920])[0];
  c5_tmp.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[920])[8];
  c5_tmp.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[920])
    [16];
  c5_tmp.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[920])
    [24];
  c5_tmp.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[920])
    [32];
  c5_tmp.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[920])
    [40];
  c5_tmp.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[920])
    [48];
  c5_tmp.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[920])
    [56];
  c5_tmp.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[920])
    [64];
  c5_tmp.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[920])
    [72];
  c5_tmp.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c5_DiscreteParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[920])
    [80];
  c5_i652 = 0;
  for (c5_i653 = 0; c5_i653 < 13; c5_i653++) {
    for (c5_i654 = 0; c5_i654 < 6; c5_i654++) {
      c5_tmp.Output.H0[c5_i654 + c5_i652] = ((real_T *)&((char_T *)
        (c5_OutputParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])
        [0])[c5_i654 + c5_i652];
    }

    c5_i652 += 6;
  }

  c5_i655 = 0;
  for (c5_i656 = 0; c5_i656 < 6; c5_i656++) {
    for (c5_i657 = 0; c5_i657 < 6; c5_i657++) {
      c5_tmp.Output.HAlpha[c5_i657 + c5_i655] = ((real_T *)&((char_T *)
        (c5_OutputParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])
        [624])[c5_i657 + c5_i655];
    }

    c5_i655 += 6;
  }

  for (c5_i658 = 0; c5_i658 < 2; c5_i658++) {
    c5_tmp.Output.ThetaLimits[c5_i658] = ((real_T *)&((char_T *)
      (c5_OutputParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])
      [912])[c5_i658];
  }

  c5_tmp.Output.Theta.c0 = *(real_T *)&((char_T *)(c5_ThetaParamsBus *)&((char_T
    *)(c5_OutputParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])
    [928])[0];
  c5_tmp.Output.Theta.ct = *(real_T *)&((char_T *)(c5_ThetaParamsBus *)&((char_T
    *)(c5_OutputParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])
    [928])[8];
  for (c5_i659 = 0; c5_i659 < 13; c5_i659++) {
    c5_tmp.Output.Theta.cq[c5_i659] = ((real_T *)&((char_T *)(c5_ThetaParamsBus *)
      &((char_T *)(c5_OutputParamsBus *)&((char_T *)(c5_ControlParamsBus *)
      c5_pData)[1008])[928])[16])[c5_i659];
  }

  c5_tmp.Output.Theta.t0 = *(real_T *)&((char_T *)(c5_ThetaParamsBus *)&((char_T
    *)(c5_OutputParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])
    [928])[120];
  for (c5_i660 = 0; c5_i660 < 7; c5_i660++) {
    c5_tmp.Output.Theta.cz[c5_i660] = ((real_T *)&((char_T *)(c5_ThetaParamsBus *)
      &((char_T *)(c5_OutputParamsBus *)&((char_T *)(c5_ControlParamsBus *)
      c5_pData)[1008])[928])[128])[c5_i660];
  }

  c5_tmp.Output.SaturateS = *(real_T *)&((char_T *)(c5_OutputParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])[1112];
  for (c5_i661 = 0; c5_i661 < 2; c5_i661++) {
    c5_tmp.Output.SLimits[c5_i661] = ((real_T *)&((char_T *)(c5_OutputParamsBus *)
      &((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])[1120])[c5_i661];
  }

  c5_tmp.Output.EnforceIncreasingS = *(real_T *)&((char_T *)(c5_OutputParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])[1136];
  c5_tmp.Output.UseCorrection = *(real_T *)&((char_T *)(c5_OutputParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])[1144];
  c5_tmp.Output.SMaxCorrection = *(real_T *)&((char_T *)(c5_OutputParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])[1152];
  c5_i662 = 0;
  for (c5_i663 = 0; c5_i663 < 5; c5_i663++) {
    for (c5_i664 = 0; c5_i664 < 6; c5_i664++) {
      c5_tmp.Output.HAlphaCorrection[c5_i664 + c5_i662] = ((real_T *)&((char_T *)
        (c5_OutputParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])
        [1160])[c5_i664 + c5_i662];
    }

    c5_i662 += 6;
  }

  c5_tmp.Output.Phi.c0 = *(real_T *)&((char_T *)(c5_PhiParamsBus *)&((char_T *)
    (c5_OutputParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])
    [1400])[0];
  for (c5_i665 = 0; c5_i665 < 13; c5_i665++) {
    c5_tmp.Output.Phi.cq[c5_i665] = ((real_T *)&((char_T *)(c5_PhiParamsBus *)
                                      &((char_T *)(c5_OutputParamsBus *)
      &((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])[1400])[8])[c5_i665];
  }

  for (c5_i666 = 0; c5_i666 < 20; c5_i666++) {
    c5_tmp.Output.PhiAlpha[c5_i666] = ((real_T *)&((char_T *)(c5_OutputParamsBus
      *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])[1512])[c5_i666];
  }

  c5_tmp.Output.SaturateR = *(real_T *)&((char_T *)(c5_OutputParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])[1672];
  for (c5_i667 = 0; c5_i667 < 2; c5_i667++) {
    c5_tmp.Output.RLimits[c5_i667] = ((real_T *)&((char_T *)(c5_OutputParamsBus *)
      &((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])[1680])[c5_i667];
  }

  c5_i668 = 0;
  for (c5_i669 = 0; c5_i669 < 5; c5_i669++) {
    for (c5_i670 = 0; c5_i670 < 6; c5_i670++) {
      c5_tmp.Output.HBarAlpha[c5_i670 + c5_i668] = ((real_T *)&((char_T *)
        (c5_OutputParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])
        [1696])[c5_i670 + c5_i668];
    }

    c5_i668 += 6;
  }

  c5_i671 = 0;
  for (c5_i672 = 0; c5_i672 < 2; c5_i672++) {
    for (c5_i673 = 0; c5_i673 < 6; c5_i673++) {
      c5_tmp.Output.HBarLimits[c5_i673 + c5_i671] = ((real_T *)&((char_T *)
        (c5_OutputParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])
        [1936])[c5_i673 + c5_i671];
    }

    c5_i671 += 6;
  }

  c5_i674 = 0;
  for (c5_i675 = 0; c5_i675 < 6; c5_i675++) {
    for (c5_i676 = 0; c5_i676 < 6; c5_i676++) {
      c5_tmp.Output.HAlphaStar[c5_i676 + c5_i674] = ((real_T *)&((char_T *)
        (c5_OutputParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])
        [2032])[c5_i676 + c5_i674];
    }

    c5_i674 += 6;
  }

  c5_tmp.Output.YawLimit = *(real_T *)&((char_T *)(c5_OutputParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[1008])[2320];
  for (c5_i677 = 0; c5_i677 < 6; c5_i677++) {
    c5_tmp.Feedback.kp[c5_i677] = ((real_T *)&((char_T *)(c5_FeedbackParamsBus *)
      &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[0])[c5_i677];
  }

  for (c5_i678 = 0; c5_i678 < 6; c5_i678++) {
    c5_tmp.Feedback.kd[c5_i678] = ((real_T *)&((char_T *)(c5_FeedbackParamsBus *)
      &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[48])[c5_i678];
  }

  for (c5_i679 = 0; c5_i679 < 2; c5_i679++) {
    c5_tmp.Feedback.epsilon[c5_i679] = ((real_T *)&((char_T *)
      (c5_FeedbackParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])
      [96])[c5_i679];
  }

  for (c5_i680 = 0; c5_i680 < 2; c5_i680++) {
    c5_tmp.Feedback.kff_grav[c5_i680] = ((real_T *)&((char_T *)
      (c5_FeedbackParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])
      [112])[c5_i680];
  }

  c5_tmp.Feedback.delta_grav = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[128];
  for (c5_i681 = 0; c5_i681 < 2; c5_i681++) {
    c5_tmp.Feedback.kff_decoup[c5_i681] = ((real_T *)&((char_T *)
      (c5_FeedbackParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])
      [136])[c5_i681];
  }

  for (c5_i682 = 0; c5_i682 < 2; c5_i682++) {
    c5_tmp.Feedback.kd_torso[c5_i682] = ((real_T *)&((char_T *)
      (c5_FeedbackParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])
      [152])[c5_i682];
  }

  c5_tmp.Feedback.kp_2dof = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[168];
  c5_tmp.Feedback.kd_2dof = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[176];
  c5_tmp.Feedback.kpre_2dof = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[184];
  c5_tmp.Feedback.kp_lat = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[192];
  c5_tmp.Feedback.kd_lat = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[200];
  c5_tmp.Feedback.q3d_min_lat = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[208];
  c5_tmp.Feedback.q3d_max_lat = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[216];
  c5_tmp.Feedback.w_torso_lat = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[224];
  for (c5_i683 = 0; c5_i683 < 6; c5_i683++) {
    c5_tmp.Feedback.u_ff[c5_i683] = ((real_T *)&((char_T *)(c5_FeedbackParamsBus
      *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[232])[c5_i683];
  }

  c5_tmp.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])
    [280];
  c5_tmp.Feedback.DecouplingMode = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[288];
  c5_tmp.Feedback.Use2DOF = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[296];
  c5_tmp.Feedback.UseDSGravComp = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[304];
  c5_tmp.Feedback.lat_bias = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[312];
  c5_tmp.Feedback.lat_bias2 = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[320];
  c5_tmp.Feedback.linkFeedback = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)
    &((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])[328];
  c5_tmp.Feedback.RIO = *(real_T *)&((char_T *)(c5_FeedbackParamsBus *)&((char_T
    *)(c5_ControlParamsBus *)c5_pData)[3336])[336];
  c5_tmp.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])
    [344];
  for (c5_i684 = 0; c5_i684 < 6; c5_i684++) {
    c5_tmp.Feedback.FeedforwardGain[c5_i684] = ((real_T *)&((char_T *)
      (c5_FeedbackParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])
      [352])[c5_i684];
  }

  c5_tmp.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c5_FeedbackParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3336])
    [400];
  c5_tmp.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c5_SaturationParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3744])
    [0];
  for (c5_i685 = 0; c5_i685 < 2; c5_i685++) {
    c5_tmp.Saturation.QPWeight[c5_i685] = ((real_T *)&((char_T *)
      (c5_SaturationParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)
      [3744])[8])[c5_i685];
  }

  c5_tmp.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c5_SaturationParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3744])
    [24];
  c5_tmp.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c5_SaturationParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3744])
    [32];
  c5_tmp.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c5_SaturationParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3744])
    [40];
  c5_tmp.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c5_SaturationParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3744])
    [48];
  c5_tmp.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c5_SaturationParamsBus *)&((char_T *)(c5_ControlParamsBus *)c5_pData)[3744])
    [56];
  sf_mex_assign(&c5_mxVal, c5_c_sf_marshallOut(chartInstance, &c5_tmp), false);
  return c5_mxVal;
}

static uint8_T c5_hb_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c5_b_is_active_c5_LibWalking, const char_T
  *c5_identifier)
{
  uint8_T c5_b_y;
  emlrtMsgIdentifier c5_thisId;
  c5_thisId.fIdentifier = c5_identifier;
  c5_thisId.fParent = NULL;
  c5_b_y = c5_ib_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c5_b_is_active_c5_LibWalking), &c5_thisId);
  sf_mex_destroy(&c5_b_is_active_c5_LibWalking);
  return c5_b_y;
}

static uint8_T c5_ib_emlrt_marshallIn(SFc5_LibWalkingInstanceStruct
  *chartInstance, const mxArray *c5_b_u, const emlrtMsgIdentifier *c5_parentId)
{
  uint8_T c5_b_y;
  uint8_T c5_u0;
  (void)chartInstance;
  sf_mex_import(c5_parentId, sf_mex_dup(c5_b_u), &c5_u0, 1, 3, 0U, 0, 0U, 0);
  c5_b_y = c5_u0;
  sf_mex_destroy(&c5_b_u);
  return c5_b_y;
}

static void c5_b_eml_matlab_zgetrf(SFc5_LibWalkingInstanceStruct *chartInstance,
  real_T c5_A[36], int32_T c5_ipiv[6], int32_T *c5_info)
{
  int32_T c5_i686;
  int32_T c5_j;
  int32_T c5_b_j;
  int32_T c5_a;
  int32_T c5_b_a;
  int32_T c5_jm1;
  int32_T c5_b;
  int32_T c5_b_b;
  int32_T c5_mmj;
  int32_T c5_c_a;
  int32_T c5_d_a;
  int32_T c5_c;
  int32_T c5_c_b;
  int32_T c5_d_b;
  int32_T c5_jj;
  int32_T c5_e_a;
  int32_T c5_f_a;
  int32_T c5_jp1j;
  int32_T c5_g_a;
  int32_T c5_h_a;
  int32_T c5_b_c;
  int32_T c5_i687;
  real_T c5_b_A[36];
  int32_T c5_i_a;
  int32_T c5_j_a;
  int32_T c5_jpiv_offset;
  int32_T c5_k_a;
  int32_T c5_e_b;
  int32_T c5_l_a;
  int32_T c5_f_b;
  int32_T c5_jpiv;
  int32_T c5_m_a;
  int32_T c5_g_b;
  int32_T c5_n_a;
  int32_T c5_h_b;
  int32_T c5_c_c;
  int32_T c5_i_b;
  int32_T c5_j_b;
  int32_T c5_jrow;
  int32_T c5_o_a;
  int32_T c5_k_b;
  int32_T c5_p_a;
  int32_T c5_l_b;
  int32_T c5_jprow;
  int32_T c5_ix0;
  int32_T c5_iy0;
  int32_T c5_b_ix0;
  int32_T c5_b_iy0;
  int32_T c5_c_ix0;
  int32_T c5_c_iy0;
  int32_T c5_ix;
  int32_T c5_iy;
  int32_T c5_k;
  real_T c5_temp;
  int32_T c5_q_a;
  int32_T c5_r_a;
  int32_T c5_b_jp1j;
  int32_T c5_s_a;
  int32_T c5_t_a;
  int32_T c5_d_c;
  int32_T c5_u_a;
  int32_T c5_m_b;
  int32_T c5_v_a;
  int32_T c5_n_b;
  int32_T c5_i688;
  int32_T c5_w_a;
  int32_T c5_o_b;
  int32_T c5_x_a;
  int32_T c5_p_b;
  boolean_T c5_overflow;
  int32_T c5_i;
  int32_T c5_b_i;
  real_T c5_x;
  real_T c5_b_y;
  real_T c5_b_x;
  real_T c5_c_y;
  real_T c5_z;
  int32_T c5_q_b;
  int32_T c5_r_b;
  int32_T c5_e_c;
  int32_T c5_y_a;
  int32_T c5_ab_a;
  int32_T c5_f_c;
  int32_T c5_bb_a;
  int32_T c5_cb_a;
  int32_T c5_g_c;
  c5_realmin(chartInstance);
  c5_eps(chartInstance);
  for (c5_i686 = 0; c5_i686 < 6; c5_i686++) {
    c5_ipiv[c5_i686] = 1 + c5_i686;
  }

  *c5_info = 0;
  c5_eml_switch_helper(chartInstance);
  for (c5_j = 1; c5_j < 6; c5_j++) {
    c5_b_j = c5_j;
    c5_a = c5_b_j;
    c5_b_a = c5_a - 1;
    c5_jm1 = c5_b_a;
    c5_b = c5_b_j;
    c5_b_b = c5_b;
    c5_mmj = 6 - c5_b_b;
    c5_c_a = c5_jm1;
    c5_d_a = c5_c_a;
    c5_c = c5_d_a * 7;
    c5_c_b = c5_c;
    c5_d_b = c5_c_b + 1;
    c5_jj = c5_d_b;
    c5_e_a = c5_jj;
    c5_f_a = c5_e_a + 1;
    c5_jp1j = c5_f_a;
    c5_g_a = c5_mmj;
    c5_h_a = c5_g_a;
    c5_b_c = c5_h_a;
    for (c5_i687 = 0; c5_i687 < 36; c5_i687++) {
      c5_b_A[c5_i687] = c5_A[c5_i687];
    }

    c5_i_a = c5_eml_ixamax(chartInstance, c5_b_c + 1, c5_b_A, c5_jj);
    c5_j_a = c5_i_a - 1;
    c5_jpiv_offset = c5_j_a;
    c5_k_a = c5_jj;
    c5_e_b = c5_jpiv_offset;
    c5_l_a = c5_k_a;
    c5_f_b = c5_e_b;
    c5_jpiv = (c5_l_a + c5_f_b) - 1;
    if (c5_A[c5_jpiv] != 0.0) {
      if (c5_jpiv_offset != 0) {
        c5_m_a = c5_b_j;
        c5_g_b = c5_jpiv_offset;
        c5_n_a = c5_m_a;
        c5_h_b = c5_g_b;
        c5_c_c = c5_n_a + c5_h_b;
        c5_ipiv[c5_b_j - 1] = c5_c_c;
        c5_i_b = c5_jm1;
        c5_j_b = c5_i_b + 1;
        c5_jrow = c5_j_b;
        c5_o_a = c5_jrow;
        c5_k_b = c5_jpiv_offset;
        c5_p_a = c5_o_a;
        c5_l_b = c5_k_b;
        c5_jprow = c5_p_a + c5_l_b;
        c5_ix0 = c5_jrow;
        c5_iy0 = c5_jprow;
        c5_b_ix0 = c5_ix0;
        c5_b_iy0 = c5_iy0;
        c5_b_eml_switch_helper(chartInstance);
        c5_c_ix0 = c5_b_ix0;
        c5_c_iy0 = c5_b_iy0;
        c5_ix = c5_c_ix0;
        c5_iy = c5_c_iy0;
        c5_eml_switch_helper(chartInstance);
        for (c5_k = 1; c5_k < 7; c5_k++) {
          c5_temp = c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c5_ix, 1, 36, 1, 0) - 1];
          c5_A[c5_ix - 1] = c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c5_iy, 1, 36, 1,
            0) - 1];
          c5_A[c5_iy - 1] = c5_temp;
          c5_q_a = c5_ix + 6;
          c5_ix = c5_q_a;
          c5_r_a = c5_iy + 6;
          c5_iy = c5_r_a;
        }
      }

      c5_b_jp1j = c5_jp1j;
      c5_s_a = c5_mmj;
      c5_t_a = c5_s_a;
      c5_d_c = c5_t_a;
      c5_u_a = c5_jp1j;
      c5_m_b = c5_d_c - 1;
      c5_v_a = c5_u_a;
      c5_n_b = c5_m_b;
      c5_i688 = c5_v_a + c5_n_b;
      c5_w_a = c5_b_jp1j;
      c5_o_b = c5_i688;
      c5_x_a = c5_w_a;
      c5_p_b = c5_o_b;
      if (c5_x_a > c5_p_b) {
        c5_overflow = false;
      } else {
        c5_eml_switch_helper(chartInstance);
        c5_eml_switch_helper(chartInstance);
        c5_overflow = (c5_p_b > 2147483646);
      }

      if (c5_overflow) {
        c5_check_forloop_overflow_error(chartInstance, true);
      }

      for (c5_i = c5_b_jp1j; c5_i <= c5_i688; c5_i++) {
        c5_b_i = c5_i - 1;
        c5_x = c5_A[c5_b_i];
        c5_b_y = c5_A[c5_jj - 1];
        c5_b_x = c5_x;
        c5_c_y = c5_b_y;
        c5_z = c5_b_x / c5_c_y;
        c5_A[c5_b_i] = c5_z;
      }
    } else {
      *c5_info = c5_b_j;
    }

    c5_q_b = c5_b_j;
    c5_r_b = c5_q_b;
    c5_e_c = 6 - c5_r_b;
    c5_y_a = c5_jj;
    c5_ab_a = c5_y_a;
    c5_f_c = c5_ab_a;
    c5_bb_a = c5_jj;
    c5_cb_a = c5_bb_a;
    c5_g_c = c5_cb_a;
    c5_b_eml_xgeru(chartInstance, c5_mmj, c5_e_c, -1.0, c5_jp1j, c5_f_c + 6,
                   c5_A, c5_g_c + 7);
  }

  if (*c5_info == 0) {
    if (!(c5_A[35] != 0.0)) {
      *c5_info = 6;
    }
  }
}

static void c5_b_eml_xgeru(SFc5_LibWalkingInstanceStruct *chartInstance, int32_T
  c5_m, int32_T c5_n, real_T c5_alpha1, int32_T c5_ix0, int32_T c5_iy0, real_T
  c5_A[36], int32_T c5_ia0)
{
  int32_T c5_b_m;
  int32_T c5_b_n;
  int32_T c5_b_ix0;
  int32_T c5_b_iy0;
  int32_T c5_b_ia0;
  int32_T c5_c_m;
  int32_T c5_c_n;
  int32_T c5_c_ix0;
  int32_T c5_c_iy0;
  int32_T c5_c_ia0;
  int32_T c5_d_m;
  int32_T c5_d_n;
  int32_T c5_d_ix0;
  int32_T c5_d_iy0;
  int32_T c5_d_ia0;
  int32_T c5_e_m;
  int32_T c5_e_n;
  int32_T c5_e_ix0;
  int32_T c5_e_iy0;
  int32_T c5_e_ia0;
  int32_T c5_ixstart;
  int32_T c5_a;
  int32_T c5_jA;
  int32_T c5_jy;
  int32_T c5_f_n;
  int32_T c5_b;
  int32_T c5_b_b;
  int32_T c5_j;
  real_T c5_yjy;
  real_T c5_temp;
  int32_T c5_ix;
  int32_T c5_c_b;
  int32_T c5_i689;
  int32_T c5_b_a;
  int32_T c5_d_b;
  int32_T c5_i690;
  int32_T c5_c_a;
  int32_T c5_e_b;
  int32_T c5_d_a;
  int32_T c5_f_b;
  boolean_T c5_overflow;
  int32_T c5_ijA;
  int32_T c5_b_ijA;
  int32_T c5_e_a;
  int32_T c5_f_a;
  int32_T c5_g_a;
  (void)c5_alpha1;
  c5_b_m = c5_m;
  c5_b_n = c5_n;
  c5_b_ix0 = c5_ix0;
  c5_b_iy0 = c5_iy0;
  c5_b_ia0 = c5_ia0;
  c5_c_m = c5_b_m;
  c5_c_n = c5_b_n;
  c5_c_ix0 = c5_b_ix0;
  c5_c_iy0 = c5_b_iy0;
  c5_c_ia0 = c5_b_ia0;
  c5_d_m = c5_c_m;
  c5_d_n = c5_c_n;
  c5_d_ix0 = c5_c_ix0;
  c5_d_iy0 = c5_c_iy0;
  c5_d_ia0 = c5_c_ia0;
  c5_e_m = c5_d_m;
  c5_e_n = c5_d_n;
  c5_e_ix0 = c5_d_ix0;
  c5_e_iy0 = c5_d_iy0;
  c5_e_ia0 = c5_d_ia0;
  c5_ixstart = c5_e_ix0;
  c5_a = c5_e_ia0 - 1;
  c5_jA = c5_a;
  c5_jy = c5_e_iy0;
  c5_f_n = c5_e_n;
  c5_b = c5_f_n;
  c5_b_b = c5_b;
  if (1 > c5_b_b) {
  } else {
    c5_eml_switch_helper(chartInstance);
    c5_eml_switch_helper(chartInstance);
  }

  for (c5_j = 1; c5_j <= c5_f_n; c5_j++) {
    c5_yjy = c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c5_jy, 1, 36, 1, 0) - 1];
    if (c5_yjy != 0.0) {
      c5_temp = -c5_yjy;
      c5_ix = c5_ixstart;
      c5_c_b = c5_jA + 1;
      c5_i689 = c5_c_b;
      c5_b_a = c5_e_m;
      c5_d_b = c5_jA;
      c5_i690 = c5_b_a + c5_d_b;
      c5_c_a = c5_i689;
      c5_e_b = c5_i690;
      c5_d_a = c5_c_a;
      c5_f_b = c5_e_b;
      if (c5_d_a > c5_f_b) {
        c5_overflow = false;
      } else {
        c5_eml_switch_helper(chartInstance);
        c5_eml_switch_helper(chartInstance);
        c5_overflow = (c5_f_b > 2147483646);
      }

      if (c5_overflow) {
        c5_check_forloop_overflow_error(chartInstance, true);
      }

      for (c5_ijA = c5_i689; c5_ijA <= c5_i690; c5_ijA++) {
        c5_b_ijA = c5_ijA;
        c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c5_b_ijA, 1, 36, 1, 0) - 1] =
          c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c5_b_ijA, 1, 36, 1, 0) - 1] +
          c5_A[_SFD_EML_ARRAY_BOUNDS_CHECK("", c5_ix, 1, 36, 1, 0) - 1] *
          c5_temp;
        c5_e_a = c5_ix + 1;
        c5_ix = c5_e_a;
      }
    }

    c5_f_a = c5_jy + 6;
    c5_jy = c5_f_a;
    c5_g_a = c5_jA + 6;
    c5_jA = c5_g_a;
  }
}

static void c5_c_eml_xtrsm(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_A[36], real_T c5_B[6])
{
  int32_T c5_k;
  int32_T c5_b_k;
  int32_T c5_kAcol;
  int32_T c5_i691;
  int32_T c5_a;
  int32_T c5_b_a;
  int32_T c5_i;
  int32_T c5_b_i;
  c5_below_threshold(chartInstance);
  c5_scalarEg(chartInstance);
  c5_eml_switch_helper(chartInstance);
  for (c5_k = 1; c5_k < 7; c5_k++) {
    c5_b_k = c5_k - 1;
    c5_kAcol = 6 * c5_b_k - 1;
    if (c5_B[c5_b_k] != 0.0) {
      c5_i691 = c5_b_k + 2;
      c5_a = c5_i691;
      c5_b_a = c5_a;
      if (c5_b_a > 6) {
      } else {
        c5_eml_switch_helper(chartInstance);
        c5_eml_switch_helper(chartInstance);
      }

      for (c5_i = c5_i691; c5_i < 7; c5_i++) {
        c5_b_i = c5_i - 1;
        c5_B[c5_b_i] -= c5_B[c5_b_k] * c5_A[(c5_b_i + c5_kAcol) + 1];
      }
    }
  }
}

static void c5_d_eml_xtrsm(SFc5_LibWalkingInstanceStruct *chartInstance, real_T
  c5_A[36], real_T c5_B[6])
{
  int32_T c5_k;
  int32_T c5_b_k;
  int32_T c5_kAcol;
  int32_T c5_i692;
  int32_T c5_b;
  int32_T c5_b_b;
  int32_T c5_i;
  int32_T c5_b_i;
  c5_below_threshold(chartInstance);
  c5_scalarEg(chartInstance);
  c5_eml_switch_helper(chartInstance);
  for (c5_k = 6; c5_k > 0; c5_k--) {
    c5_b_k = c5_k - 1;
    c5_kAcol = 6 * c5_b_k - 1;
    if (c5_B[c5_b_k] != 0.0) {
      c5_B[c5_b_k] = c5_rdivide(chartInstance, c5_B[c5_b_k], c5_A[(c5_b_k +
        c5_kAcol) + 1]);
      c5_i692 = c5_b_k;
      c5_b = c5_i692;
      c5_b_b = c5_b;
      if (1 > c5_b_b) {
      } else {
        c5_eml_switch_helper(chartInstance);
        c5_eml_switch_helper(chartInstance);
      }

      for (c5_i = 1; c5_i <= c5_i692; c5_i++) {
        c5_b_i = c5_i - 1;
        c5_B[c5_b_i] -= c5_B[c5_b_k] * c5_A[(c5_b_i + c5_kAcol) + 1];
      }
    }
  }
}

static void init_dsm_address_info(SFc5_LibWalkingInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc5_LibWalkingInstanceStruct
  *chartInstance)
{
  chartInstance->c5_t = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c5_q = (real_T (*)[13])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_dq = (real_T (*)[13])ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c5_ControlState = (c5_ControlStateBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c5_ControlParams = (c5_ControlParamsBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 4);
  chartInstance->c5_u = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c5_y = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c5_dy = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c5_hd = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c5_s = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    5);
  chartInstance->c5_s_unsaturated = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c5_ds = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c5_theta = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c5_phi = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c5_r = (real_T *)ssGetOutputPortSignal_wrapper(chartInstance->S,
    10);
  chartInstance->c5_hdbar = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 11);
  chartInstance->c5_D = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    5);
  chartInstance->c5_G = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    6);
  chartInstance->c5_pcm = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c5_vcm = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c5_sprev = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 9);
  chartInstance->c5_u_star = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 12);
  chartInstance->c5_u_pd = (real_T (*)[6])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 13);
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

void sf_c5_LibWalking_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(923444444U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4224930932U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2073145531U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4056928666U);
}

mxArray* sf_c5_LibWalking_get_post_codegen_info(void);
mxArray *sf_c5_LibWalking_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("Yo05vwjsCH0dErjCih6XQ");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,10,3,dataFields);

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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(13);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,13,3,dataFields);

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
      pr[0] = (double)(6);
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
      pr[0] = (double)(1);
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
      pr[0] = (double)(1);
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

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,10,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,10,"type",mxType);
    }

    mxSetField(mxData,10,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,11,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,11,"type",mxType);
    }

    mxSetField(mxData,11,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(6);
      pr[1] = (double)(1);
      mxSetField(mxData,12,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,12,"type",mxType);
    }

    mxSetField(mxData,12,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c5_LibWalking_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c5_LibWalking_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c5_LibWalking_jit_fallback_info(void)
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

mxArray *sf_c5_LibWalking_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c5_LibWalking_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c5_LibWalking(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x10'type','srcId','name','auxInfo'{{M[1],M[81],T\"ds\",},{M[1],M[8],T\"dy\",},{M[1],M[37],T\"hd\",},{M[1],M[57],T\"hdbar\",},{M[1],M[98],T\"phi\",},{M[1],M[45],T\"r\",},{M[1],M[36],T\"s\",},{M[1],M[47],T\"s_unsaturated\",},{M[1],M[48],T\"theta\",},{M[1],M[4],T\"u\",}}",
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[100],T\"u_pd\",},{M[1],M[99],T\"u_star\",},{M[1],M[5],T\"y\",},{M[8],M[0],T\"is_active_c5_LibWalking\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 14, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c5_LibWalking_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc5_LibWalkingInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc5_LibWalkingInstanceStruct *) chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _LibWalkingMachineNumber_,
           5,
           1,
           1,
           0,
           23,
           0,
           0,
           0,
           0,
           14,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation(_LibWalkingMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_LibWalkingMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _LibWalkingMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"t");
          _SFD_SET_DATA_PROPS(1,1,1,0,"q");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dq");
          _SFD_SET_DATA_PROPS(3,1,1,0,"ControlState");
          _SFD_SET_DATA_PROPS(4,1,1,0,"ControlParams");
          _SFD_SET_DATA_PROPS(5,2,0,1,"u");
          _SFD_SET_DATA_PROPS(6,2,0,1,"y");
          _SFD_SET_DATA_PROPS(7,2,0,1,"dy");
          _SFD_SET_DATA_PROPS(8,2,0,1,"hd");
          _SFD_SET_DATA_PROPS(9,2,0,1,"s");
          _SFD_SET_DATA_PROPS(10,2,0,1,"s_unsaturated");
          _SFD_SET_DATA_PROPS(11,2,0,1,"ds");
          _SFD_SET_DATA_PROPS(12,2,0,1,"theta");
          _SFD_SET_DATA_PROPS(13,2,0,1,"phi");
          _SFD_SET_DATA_PROPS(14,2,0,1,"r");
          _SFD_SET_DATA_PROPS(15,2,0,1,"hdbar");
          _SFD_SET_DATA_PROPS(16,1,1,0,"D");
          _SFD_SET_DATA_PROPS(17,1,1,0,"G");
          _SFD_SET_DATA_PROPS(18,1,1,0,"pcm");
          _SFD_SET_DATA_PROPS(19,1,1,0,"vcm");
          _SFD_SET_DATA_PROPS(20,1,1,0,"sprev");
          _SFD_SET_DATA_PROPS(21,2,0,1,"u_star");
          _SFD_SET_DATA_PROPS(22,2,0,1,"u_pd");
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
        _SFD_CV_INIT_EML(0,1,1,1,0,0,1,0,0,1,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,2533);
        _SFD_CV_INIT_EML_IF(0,1,0,1908,1942,-1,2030);

        {
          static int caseStart[] = { -1, 335, 1033, 1298, 1564, 1859 };

          static int caseExprEnd[] = { 8, 341, 1039, 1304, 1570, 1865 };

          _SFD_CV_INIT_EML_SWITCH(0,1,0,290,326,2038,6,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        {
          static int condStart[] = { 1913 };

          static int condEnd[] = { 1941 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,1912,1941,1,0,&(condStart[0]),&(condEnd[0]),
                                2,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT(0,1,3,0,0,0,0,0,1,1);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"applyGaitTweaks2",0,-1,1922);
        _SFD_CV_INIT_SCRIPT_IF(0,0,427,439,-1,474);
        _SFD_CV_INIT_SCRIPT_IF(0,1,1394,1431,-1,1784);
        _SFD_CV_INIT_SCRIPT_IF(0,2,1842,1855,-1,1918);

        {
          static int condStart[] = { 1846 };

          static int condEnd[] = { 1855 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_SCRIPT_MCDC(0,0,1845,1855,1,0,&(condStart[0]),&(condEnd[0]),
            2,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,0,430,439,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(0,1,1398,1430,-1,0);
        _SFD_CV_INIT_SCRIPT(1,1,13,0,0,1,0,0,1,1);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"ATRIAS3D_ZD_Control06",0,-1,5760);
        _SFD_CV_INIT_SCRIPT_IF(1,0,957,985,-1,1027);
        _SFD_CV_INIT_SCRIPT_IF(1,1,1799,1876,-1,2289);
        _SFD_CV_INIT_SCRIPT_IF(1,2,1885,1935,1974,2028);
        _SFD_CV_INIT_SCRIPT_IF(1,3,1974,2028,-1,2028);
        _SFD_CV_INIT_SCRIPT_IF(1,4,2106,2138,-1,2202);
        _SFD_CV_INIT_SCRIPT_IF(1,5,2299,2324,2402,2438);
        _SFD_CV_INIT_SCRIPT_IF(1,6,2448,2452,3509,3559);
        _SFD_CV_INIT_SCRIPT_IF(1,7,3300,3321,-1,3440);
        _SFD_CV_INIT_SCRIPT_IF(1,8,3851,3892,3961,4315);
        _SFD_CV_INIT_SCRIPT_IF(1,9,4354,4389,-1,4875);
        _SFD_CV_INIT_SCRIPT_IF(1,10,4750,4778,4819,4867);
        _SFD_CV_INIT_SCRIPT_IF(1,11,4885,4889,-1,5449);
        _SFD_CV_INIT_SCRIPT_IF(1,12,5245,5273,-1,5325);

        {
          static int caseStart[] = { 1572, 1362, 1495 };

          static int caseExprEnd[] = { 1581, 1368, 1501 };

          _SFD_CV_INIT_SCRIPT_SWITCH(1,0,1307,1353,1789,3,&(caseStart[0]),
            &(caseExprEnd[0]));
        }

        {
          static int condStart[] = { 3856 };

          static int condEnd[] = { 3891 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_SCRIPT_MCDC(1,0,3854,3892,1,0,&(condStart[0]),&(condEnd[0]),
            2,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,0,960,985,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,1,1803,1875,-1,5);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,2,1889,1934,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,3,1982,2027,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,4,2110,2137,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(1,6,4753,4778,-1,0);
        _SFD_CV_INIT_SCRIPT(2,2,14,0,0,0,0,0,3,2);
        _SFD_CV_INIT_SCRIPT_FCN(2,0,"ATRIAS3D_ZD_Output03",0,-1,5822);
        _SFD_CV_INIT_SCRIPT_FCN(2,1,"sat",5824,-1,5882);
        _SFD_CV_INIT_SCRIPT_IF(2,0,510,540,-1,582);
        _SFD_CV_INIT_SCRIPT_IF(2,1,729,759,857,1106);
        _SFD_CV_INIT_SCRIPT_IF(2,2,1257,1287,-1,1322);
        _SFD_CV_INIT_SCRIPT_IF(2,3,1361,1391,-1,1430);
        _SFD_CV_INIT_SCRIPT_IF(2,4,1440,1462,1825,1851);
        _SFD_CV_INIT_SCRIPT_IF(2,5,1825,1851,2615,2819);
        _SFD_CV_INIT_SCRIPT_IF(2,6,1860,1876,1956,2063);
        _SFD_CV_INIT_SCRIPT_IF(2,7,2615,2641,-1,2641);
        _SFD_CV_INIT_SCRIPT_IF(2,8,3654,3673,-1,3939);
        _SFD_CV_INIT_SCRIPT_IF(2,9,3682,3708,3803,3833);
        _SFD_CV_INIT_SCRIPT_IF(2,10,3803,3833,-1,3833);
        _SFD_CV_INIT_SCRIPT_IF(2,11,3995,4009,4127,4208);
        _SFD_CV_INIT_SCRIPT_IF(2,12,5309,5356,-1,5813);
        _SFD_CV_INIT_SCRIPT_IF(2,13,5595,5611,5715,5805);

        {
          static int condStart[] = { 3999 };

          static int condEnd[] = { 4009 };

          static int pfixExpr[] = { 0, -1 };

          _SFD_CV_INIT_SCRIPT_MCDC(2,0,3998,4009,1,0,&(condStart[0]),&(condEnd[0]),
            2,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 5312, 5336 };

          static int condEnd[] = { 5332, 5356 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(2,1,5312,5356,2,1,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,0,514,539,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,1,733,758,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,2,1365,1390,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,3,1443,1462,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,4,1832,1851,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,5,1864,1875,-1,4);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,6,2622,2641,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,7,3686,3707,-1,4);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,8,3811,3832,-1,2);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(2,9,5599,5610,-1,4);
        _SFD_CV_INIT_SCRIPT(3,1,3,0,0,0,0,0,2,1);
        _SFD_CV_INIT_SCRIPT_FCN(3,0,"ATRIAS3D_ZD_s6",0,-1,754);
        _SFD_CV_INIT_SCRIPT_IF(3,0,230,241,-1,388);
        _SFD_CV_INIT_SCRIPT_IF(3,1,311,337,-1,380);
        _SFD_CV_INIT_SCRIPT_IF(3,2,393,444,-1,491);

        {
          static int condStart[] = { 396, 422 };

          static int condEnd[] = { 418, 444 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_SCRIPT_MCDC(3,0,396,444,2,0,&(condStart[0]),&(condEnd[0]),
            3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_SCRIPT_RELATIONAL(3,0,233,241,-1,2);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(3,2,396,418,-1,0);
        _SFD_CV_INIT_SCRIPT(4,1,7,0,0,0,3,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(4,0,"bezierv",0,-1,657);
        _SFD_CV_INIT_SCRIPT_IF(4,0,102,109,127,391);
        _SFD_CV_INIT_SCRIPT_IF(4,1,127,138,158,391);
        _SFD_CV_INIT_SCRIPT_IF(4,2,158,169,193,391);
        _SFD_CV_INIT_SCRIPT_IF(4,3,193,204,231,391);
        _SFD_CV_INIT_SCRIPT_IF(4,4,231,242,272,391);
        _SFD_CV_INIT_SCRIPT_IF(4,5,272,283,317,391);
        _SFD_CV_INIT_SCRIPT_IF(4,6,317,328,367,391);
        _SFD_CV_INIT_SCRIPT_FOR(4,0,433,443,498);
        _SFD_CV_INIT_SCRIPT_FOR(4,1,508,518,656);
        _SFD_CV_INIT_SCRIPT_FOR(4,2,540,552,629);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(4,0,105,109,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(4,1,134,138,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(4,2,165,169,-1,0);
        _SFD_CV_INIT_SCRIPT(5,1,7,0,0,0,3,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(5,0,"beziervd",0,-1,669);
        _SFD_CV_INIT_SCRIPT_IF(5,0,101,108,124,395);
        _SFD_CV_INIT_SCRIPT_IF(5,1,124,135,155,395);
        _SFD_CV_INIT_SCRIPT_IF(5,2,155,166,189,395);
        _SFD_CV_INIT_SCRIPT_IF(5,3,189,200,226,395);
        _SFD_CV_INIT_SCRIPT_IF(5,4,226,237,269,395);
        _SFD_CV_INIT_SCRIPT_IF(5,5,269,280,316,395);
        _SFD_CV_INIT_SCRIPT_IF(5,6,316,327,367,395);
        _SFD_CV_INIT_SCRIPT_FOR(5,0,433,445,500);
        _SFD_CV_INIT_SCRIPT_FOR(5,1,510,520,668);
        _SFD_CV_INIT_SCRIPT_FOR(5,2,542,552,641);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(5,0,104,108,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(5,1,131,135,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(5,2,162,166,-1,0);
        _SFD_CV_INIT_SCRIPT(6,1,7,0,0,0,3,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(6,0,"bezierva",0,-1,699);
        _SFD_CV_INIT_SCRIPT_IF(6,0,103,110,124,409);
        _SFD_CV_INIT_SCRIPT_IF(6,1,124,135,154,409);
        _SFD_CV_INIT_SCRIPT_IF(6,2,154,165,189,409);
        _SFD_CV_INIT_SCRIPT_IF(6,3,189,200,228,409);
        _SFD_CV_INIT_SCRIPT_IF(6,4,228,239,271,409);
        _SFD_CV_INIT_SCRIPT_IF(6,5,271,282,319,409);
        _SFD_CV_INIT_SCRIPT_IF(6,6,319,330,375,409);
        _SFD_CV_INIT_SCRIPT_FOR(6,0,451,463,518);
        _SFD_CV_INIT_SCRIPT_FOR(6,1,528,538,698);
        _SFD_CV_INIT_SCRIPT_FOR(6,2,558,570,672);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(6,0,106,110,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(6,1,131,135,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(6,2,161,165,-1,0);
        _SFD_CV_INIT_SCRIPT(7,1,8,0,0,0,3,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(7,0,"bezier",0,-1,872);
        _SFD_CV_INIT_SCRIPT_IF(7,0,83,90,108,655);
        _SFD_CV_INIT_SCRIPT_IF(7,1,108,119,139,655);
        _SFD_CV_INIT_SCRIPT_IF(7,2,139,150,174,655);
        _SFD_CV_INIT_SCRIPT_IF(7,3,174,185,212,655);
        _SFD_CV_INIT_SCRIPT_IF(7,4,212,223,255,655);
        _SFD_CV_INIT_SCRIPT_IF(7,5,255,266,301,655);
        _SFD_CV_INIT_SCRIPT_IF(7,6,301,312,352,655);
        _SFD_CV_INIT_SCRIPT_IF(7,7,352,364,629,655);
        _SFD_CV_INIT_SCRIPT_FOR(7,0,699,709,754);
        _SFD_CV_INIT_SCRIPT_FOR(7,1,755,765,866);
        _SFD_CV_INIT_SCRIPT_FOR(7,2,785,797,862);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(7,0,86,90,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(7,1,115,119,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(7,2,146,150,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(7,3,181,185,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(7,4,219,223,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(7,5,262,266,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(7,6,308,312,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(7,7,359,364,-1,0);
        _SFD_CV_INIT_SCRIPT(8,1,0,0,0,0,1,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(8,0,"binom",0,-1,171);
        _SFD_CV_INIT_SCRIPT_FOR(8,0,118,128,167);
        _SFD_CV_INIT_SCRIPT(9,1,8,0,0,0,3,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(9,0,"bezierd",0,-1,917);
        _SFD_CV_INIT_SCRIPT_IF(9,0,84,91,107,698);
        _SFD_CV_INIT_SCRIPT_IF(9,1,107,118,138,698);
        _SFD_CV_INIT_SCRIPT_IF(9,2,138,149,172,698);
        _SFD_CV_INIT_SCRIPT_IF(9,3,172,183,209,698);
        _SFD_CV_INIT_SCRIPT_IF(9,4,209,220,271,698);
        _SFD_CV_INIT_SCRIPT_IF(9,5,271,282,339,698);
        _SFD_CV_INIT_SCRIPT_IF(9,6,339,350,412,698);
        _SFD_CV_INIT_SCRIPT_IF(9,7,412,424,678,698);
        _SFD_CV_INIT_SCRIPT_FOR(9,0,734,746,791);
        _SFD_CV_INIT_SCRIPT_FOR(9,1,792,802,914);
        _SFD_CV_INIT_SCRIPT_FOR(9,2,822,832,910);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(9,0,87,91,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(9,1,114,118,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(9,2,145,149,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(9,3,179,183,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(9,4,216,220,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(9,5,278,282,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(9,6,346,350,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(9,7,419,424,-1,0);
        _SFD_CV_INIT_SCRIPT(10,1,8,0,0,0,3,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(10,0,"beziera",0,-1,988);
        _SFD_CV_INIT_SCRIPT_IF(10,0,84,91,105,750);
        _SFD_CV_INIT_SCRIPT_IF(10,1,105,116,135,750);
        _SFD_CV_INIT_SCRIPT_IF(10,2,135,146,170,750);
        _SFD_CV_INIT_SCRIPT_IF(10,3,170,181,209,750);
        _SFD_CV_INIT_SCRIPT_IF(10,4,209,221,266,750);
        _SFD_CV_INIT_SCRIPT_IF(10,5,266,277,364,750);
        _SFD_CV_INIT_SCRIPT_IF(10,6,364,375,475,750);
        _SFD_CV_INIT_SCRIPT_IF(10,7,475,487,730,750);
        _SFD_CV_INIT_SCRIPT_FOR(10,0,790,802,847);
        _SFD_CV_INIT_SCRIPT_FOR(10,1,848,858,985);
        _SFD_CV_INIT_SCRIPT_FOR(10,2,878,890,981);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(10,0,87,91,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(10,1,112,116,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(10,2,142,146,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(10,3,177,181,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(10,4,216,221,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(10,5,273,277,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(10,6,371,375,-1,0);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(10,7,482,487,-1,0);
        _SFD_CV_INIT_SCRIPT(11,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(11,0,"polyv",0,-1,289);
        _SFD_CV_INIT_SCRIPT_IF(11,0,51,62,-1,97);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(11,0,54,62,-1,2);
        _SFD_CV_INIT_SCRIPT(12,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(12,0,"polyvd",0,-1,267);
        _SFD_CV_INIT_SCRIPT_IF(12,0,54,65,-1,99);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(12,0,57,65,-1,2);
        _SFD_CV_INIT_SCRIPT(13,1,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(13,0,"polyva",0,-1,248);
        _SFD_CV_INIT_SCRIPT_IF(13,0,55,66,-1,100);
        _SFD_CV_INIT_SCRIPT_RELATIONAL(13,0,58,66,-1,2);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_ControlState_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_ControlParams_bus_io,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)c5_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(15,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        _SFD_SET_DATA_COMPILED_PROPS(16,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(17,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(18,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(19,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(20,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c5_b_sf_marshallOut,(MexInFcnForType)NULL);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(21,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(22,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c5_sf_marshallOut,(MexInFcnForType)
            c5_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c5_t);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c5_q);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c5_dq);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c5_ControlState);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c5_ControlParams);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c5_u);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c5_y);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c5_dy);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c5_hd);
        _SFD_SET_DATA_VALUE_PTR(9U, chartInstance->c5_s);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c5_s_unsaturated);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c5_ds);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c5_theta);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c5_phi);
        _SFD_SET_DATA_VALUE_PTR(14U, chartInstance->c5_r);
        _SFD_SET_DATA_VALUE_PTR(15U, *chartInstance->c5_hdbar);
        _SFD_SET_DATA_VALUE_PTR(16U, chartInstance->c5_D);
        _SFD_SET_DATA_VALUE_PTR(17U, chartInstance->c5_G);
        _SFD_SET_DATA_VALUE_PTR(18U, chartInstance->c5_pcm);
        _SFD_SET_DATA_VALUE_PTR(19U, chartInstance->c5_vcm);
        _SFD_SET_DATA_VALUE_PTR(20U, chartInstance->c5_sprev);
        _SFD_SET_DATA_VALUE_PTR(21U, *chartInstance->c5_u_star);
        _SFD_SET_DATA_VALUE_PTR(22U, *chartInstance->c5_u_pd);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _LibWalkingMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "0Zev8eyKjjv7iALhv7B0eG";
}

static void sf_opaque_initialize_c5_LibWalking(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc5_LibWalkingInstanceStruct*) chartInstanceVar
    )->S,0);
  initialize_params_c5_LibWalking((SFc5_LibWalkingInstanceStruct*)
    chartInstanceVar);
  initialize_c5_LibWalking((SFc5_LibWalkingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_enable_c5_LibWalking(void *chartInstanceVar)
{
  enable_c5_LibWalking((SFc5_LibWalkingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c5_LibWalking(void *chartInstanceVar)
{
  disable_c5_LibWalking((SFc5_LibWalkingInstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c5_LibWalking(void *chartInstanceVar)
{
  sf_gateway_c5_LibWalking((SFc5_LibWalkingInstanceStruct*) chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c5_LibWalking(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c5_LibWalking((SFc5_LibWalkingInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c5_LibWalking(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c5_LibWalking((SFc5_LibWalkingInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c5_LibWalking(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc5_LibWalkingInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_LibWalking_optimization_info();
    }

    finalize_c5_LibWalking((SFc5_LibWalkingInstanceStruct*) chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc5_LibWalking((SFc5_LibWalkingInstanceStruct*) chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c5_LibWalking(SimStruct *S)
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
    initialize_params_c5_LibWalking((SFc5_LibWalkingInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c5_LibWalking(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_LibWalking_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,5);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,5,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,5,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,5);
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
        infoStruct,5,10);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,5,13);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=13; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 10; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,5);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1245326364U));
  ssSetChecksum1(S,(23059807U));
  ssSetChecksum2(S,(1538214945U));
  ssSetChecksum3(S,(3103044636U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c5_LibWalking(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c5_LibWalking(SimStruct *S)
{
  SFc5_LibWalkingInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc5_LibWalkingInstanceStruct *)utMalloc(sizeof
    (SFc5_LibWalkingInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc5_LibWalkingInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c5_LibWalking;
  chartInstance->chartInfo.initializeChart = sf_opaque_initialize_c5_LibWalking;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c5_LibWalking;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c5_LibWalking;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c5_LibWalking;
  chartInstance->chartInfo.getSimState = sf_opaque_get_sim_state_c5_LibWalking;
  chartInstance->chartInfo.setSimState = sf_opaque_set_sim_state_c5_LibWalking;
  chartInstance->chartInfo.getSimStateInfo = sf_get_sim_state_info_c5_LibWalking;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c5_LibWalking;
  chartInstance->chartInfo.mdlStart = mdlStart_c5_LibWalking;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c5_LibWalking;
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

void c5_LibWalking_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c5_LibWalking(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c5_LibWalking(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c5_LibWalking(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c5_LibWalking_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
