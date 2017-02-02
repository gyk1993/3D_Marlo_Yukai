/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DDA2D_OSU3Dv2_sfun.h"
#include "c66_DDA2D_OSU3Dv2.h"
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
static const char * c66_debug_family_names[48] = { "ks_leg", "m_torso",
  "m_total", "g", "l_h", "l_st_h", "f_c", "f_v", "z_offset", "y_offset",
  "x_offset", "q_st_mA", "dq_st_mA", "q_st_mB", "dq_st_mB", "q_st_lA",
  "dq_st_lA", "q_st_lB", "dq_st_lB", "q_st_h", "dq_st_h", "q_sw_mA", "dq_sw_mA",
  "q_sw_mB", "dq_sw_mB", "q_sw_lA", "dq_sw_lA", "q_sw_lB", "dq_sw_lB", "q_sw_h",
  "dq_sw_h", "q_yaw", "dq_yaw", "q_pitch", "dq_pitch", "q_roll", "dq_roll",
  "nargin", "nargout", "q", "dq", "stanceLeg", "dy", "dy_prev", "ddy_prev", "dx",
  "dx_prev", "ddx_prev" };

/* Function Declarations */
static void initialize_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initialize_params_c66_DDA2D_OSU3Dv2
  (SFc66_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void enable_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void disable_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c66_update_debugger_state_c66_DDA2D_OSU3Dv2
  (SFc66_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c66_DDA2D_OSU3Dv2
  (SFc66_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void set_sim_state_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c66_st);
static void finalize_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void sf_gateway_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void mdl_start_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c66_chartstep_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initSimStructsc66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c66_machineNumber, uint32_T
  c66_chartNumber, uint32_T c66_instanceNumber);
static const mxArray *c66_sf_marshallOut(void *chartInstanceVoid, void
  *c66_inData);
static real_T c66_emlrt_marshallIn(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c66_b_ddx_prev, const char_T *c66_identifier);
static real_T c66_b_emlrt_marshallIn(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c66_u, const emlrtMsgIdentifier *c66_parentId);
static void c66_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c66_mxArrayInData, const char_T *c66_varName, void *c66_outData);
static const mxArray *c66_b_sf_marshallOut(void *chartInstanceVoid, void
  *c66_inData);
static void c66_info_helper(const mxArray **c66_info);
static const mxArray *c66_emlrt_marshallOut(const char * c66_u);
static const mxArray *c66_b_emlrt_marshallOut(const uint32_T c66_u);
static const mxArray *c66_c_sf_marshallOut(void *chartInstanceVoid, void
  *c66_inData);
static int32_T c66_c_emlrt_marshallIn(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c66_u, const emlrtMsgIdentifier *c66_parentId);
static void c66_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c66_mxArrayInData, const char_T *c66_varName, void *c66_outData);
static uint8_T c66_d_emlrt_marshallIn(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c66_b_is_active_c66_DDA2D_OSU3Dv2, const char_T
  *c66_identifier);
static uint8_T c66_e_emlrt_marshallIn(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c66_u, const emlrtMsgIdentifier *c66_parentId);
static void init_dsm_address_info(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c66_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c66_is_active_c66_DDA2D_OSU3Dv2 = 0U;
}

static void initialize_params_c66_DDA2D_OSU3Dv2
  (SFc66_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c66_update_debugger_state_c66_DDA2D_OSU3Dv2
  (SFc66_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c66_DDA2D_OSU3Dv2
  (SFc66_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  const mxArray *c66_st;
  const mxArray *c66_y = NULL;
  real_T c66_hoistedGlobal;
  real_T c66_u;
  const mxArray *c66_b_y = NULL;
  real_T c66_b_hoistedGlobal;
  real_T c66_b_u;
  const mxArray *c66_c_y = NULL;
  real_T c66_c_hoistedGlobal;
  real_T c66_c_u;
  const mxArray *c66_d_y = NULL;
  real_T c66_d_hoistedGlobal;
  real_T c66_d_u;
  const mxArray *c66_e_y = NULL;
  real_T c66_e_hoistedGlobal;
  real_T c66_e_u;
  const mxArray *c66_f_y = NULL;
  real_T c66_f_hoistedGlobal;
  real_T c66_f_u;
  const mxArray *c66_g_y = NULL;
  uint8_T c66_g_hoistedGlobal;
  uint8_T c66_g_u;
  const mxArray *c66_h_y = NULL;
  c66_st = NULL;
  c66_st = NULL;
  c66_y = NULL;
  sf_mex_assign(&c66_y, sf_mex_createcellmatrix(7, 1), false);
  c66_hoistedGlobal = *chartInstance->c66_ddx_prev;
  c66_u = c66_hoistedGlobal;
  c66_b_y = NULL;
  sf_mex_assign(&c66_b_y, sf_mex_create("y", &c66_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c66_y, 0, c66_b_y);
  c66_b_hoistedGlobal = *chartInstance->c66_ddy_prev;
  c66_b_u = c66_b_hoistedGlobal;
  c66_c_y = NULL;
  sf_mex_assign(&c66_c_y, sf_mex_create("y", &c66_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c66_y, 1, c66_c_y);
  c66_c_hoistedGlobal = *chartInstance->c66_dx;
  c66_c_u = c66_c_hoistedGlobal;
  c66_d_y = NULL;
  sf_mex_assign(&c66_d_y, sf_mex_create("y", &c66_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c66_y, 2, c66_d_y);
  c66_d_hoistedGlobal = *chartInstance->c66_dx_prev;
  c66_d_u = c66_d_hoistedGlobal;
  c66_e_y = NULL;
  sf_mex_assign(&c66_e_y, sf_mex_create("y", &c66_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c66_y, 3, c66_e_y);
  c66_e_hoistedGlobal = *chartInstance->c66_dy;
  c66_e_u = c66_e_hoistedGlobal;
  c66_f_y = NULL;
  sf_mex_assign(&c66_f_y, sf_mex_create("y", &c66_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c66_y, 4, c66_f_y);
  c66_f_hoistedGlobal = *chartInstance->c66_dy_prev;
  c66_f_u = c66_f_hoistedGlobal;
  c66_g_y = NULL;
  sf_mex_assign(&c66_g_y, sf_mex_create("y", &c66_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c66_y, 5, c66_g_y);
  c66_g_hoistedGlobal = chartInstance->c66_is_active_c66_DDA2D_OSU3Dv2;
  c66_g_u = c66_g_hoistedGlobal;
  c66_h_y = NULL;
  sf_mex_assign(&c66_h_y, sf_mex_create("y", &c66_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c66_y, 6, c66_h_y);
  sf_mex_assign(&c66_st, c66_y, false);
  return c66_st;
}

static void set_sim_state_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c66_st)
{
  const mxArray *c66_u;
  chartInstance->c66_doneDoubleBufferReInit = true;
  c66_u = sf_mex_dup(c66_st);
  *chartInstance->c66_ddx_prev = c66_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c66_u, 0)), "ddx_prev");
  *chartInstance->c66_ddy_prev = c66_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c66_u, 1)), "ddy_prev");
  *chartInstance->c66_dx = c66_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c66_u, 2)), "dx");
  *chartInstance->c66_dx_prev = c66_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c66_u, 3)), "dx_prev");
  *chartInstance->c66_dy = c66_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c66_u, 4)), "dy");
  *chartInstance->c66_dy_prev = c66_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c66_u, 5)), "dy_prev");
  chartInstance->c66_is_active_c66_DDA2D_OSU3Dv2 = c66_d_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c66_u, 6)),
     "is_active_c66_DDA2D_OSU3Dv2");
  sf_mex_destroy(&c66_u);
  c66_update_debugger_state_c66_DDA2D_OSU3Dv2(chartInstance);
  sf_mex_destroy(&c66_st);
}

static void finalize_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  int32_T c66_i0;
  int32_T c66_i1;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 8U, chartInstance->c66_sfEvent);
  for (c66_i0 = 0; c66_i0 < 13; c66_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c66_q)[c66_i0], 0U);
  }

  for (c66_i1 = 0; c66_i1 < 13; c66_i1++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c66_dq)[c66_i1], 1U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c66_stanceLeg, 2U);
  chartInstance->c66_sfEvent = CALL_EVENT;
  c66_chartstep_c66_DDA2D_OSU3Dv2(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DDA2D_OSU3Dv2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c66_dy, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c66_dy_prev, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c66_ddy_prev, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c66_dx, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c66_dx_prev, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c66_ddx_prev, 8U);
}

static void mdl_start_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c66_chartstep_c66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  real_T c66_hoistedGlobal;
  int32_T c66_i2;
  real_T c66_b_q[13];
  int32_T c66_i3;
  real_T c66_b_dq[13];
  real_T c66_b_stanceLeg;
  uint32_T c66_debug_family_var_map[48];
  real_T c66_ks_leg;
  real_T c66_m_torso;
  real_T c66_m_total;
  real_T c66_g;
  real_T c66_l_h;
  real_T c66_l_st_h;
  real_T c66_f_c;
  real_T c66_f_v;
  real_T c66_z_offset;
  real_T c66_y_offset;
  real_T c66_x_offset;
  real_T c66_q_st_mA;
  real_T c66_dq_st_mA;
  real_T c66_q_st_mB;
  real_T c66_dq_st_mB;
  real_T c66_q_st_lA;
  real_T c66_dq_st_lA;
  real_T c66_q_st_lB;
  real_T c66_dq_st_lB;
  real_T c66_q_st_h;
  real_T c66_dq_st_h;
  real_T c66_q_sw_mA;
  real_T c66_dq_sw_mA;
  real_T c66_q_sw_mB;
  real_T c66_dq_sw_mB;
  real_T c66_q_sw_lA;
  real_T c66_dq_sw_lA;
  real_T c66_q_sw_lB;
  real_T c66_dq_sw_lB;
  real_T c66_q_sw_h;
  real_T c66_dq_sw_h;
  real_T c66_q_yaw;
  real_T c66_dq_yaw;
  real_T c66_q_pitch;
  real_T c66_dq_pitch;
  real_T c66_q_roll;
  real_T c66_dq_roll;
  real_T c66_nargin = 3.0;
  real_T c66_nargout = 6.0;
  real_T c66_b_dy;
  real_T c66_b_dy_prev;
  real_T c66_b_ddy_prev;
  real_T c66_b_dx;
  real_T c66_b_dx_prev;
  real_T c66_b_ddx_prev;
  real_T c66_x;
  real_T c66_b_x;
  real_T c66_c_x;
  real_T c66_d_x;
  real_T c66_A;
  real_T c66_e_x;
  real_T c66_f_x;
  real_T c66_g_x;
  real_T c66_y;
  real_T c66_h_x;
  real_T c66_i_x;
  real_T c66_j_x;
  real_T c66_k_x;
  real_T c66_b_A;
  real_T c66_l_x;
  real_T c66_m_x;
  real_T c66_n_x;
  real_T c66_b_y;
  real_T c66_o_x;
  real_T c66_p_x;
  real_T c66_q_x;
  real_T c66_r_x;
  real_T c66_c_A;
  real_T c66_s_x;
  real_T c66_t_x;
  real_T c66_u_x;
  real_T c66_c_y;
  real_T c66_v_x;
  real_T c66_w_x;
  real_T c66_x_x;
  real_T c66_y_x;
  real_T c66_d_A;
  real_T c66_ab_x;
  real_T c66_bb_x;
  real_T c66_cb_x;
  real_T c66_d_y;
  real_T c66_db_x;
  real_T c66_eb_x;
  real_T c66_fb_x;
  real_T c66_gb_x;
  real_T c66_hb_x;
  real_T c66_ib_x;
  real_T c66_jb_x;
  real_T c66_kb_x;
  real_T c66_lb_x;
  real_T c66_mb_x;
  real_T c66_nb_x;
  real_T c66_ob_x;
  real_T c66_pb_x;
  real_T c66_qb_x;
  real_T c66_rb_x;
  real_T c66_sb_x;
  real_T c66_tb_x;
  real_T c66_ub_x;
  real_T c66_vb_x;
  real_T c66_wb_x;
  real_T c66_xb_x;
  real_T c66_yb_x;
  real_T c66_ac_x;
  real_T c66_bc_x;
  real_T c66_cc_x;
  real_T c66_dc_x;
  real_T c66_e_A;
  real_T c66_ec_x;
  real_T c66_fc_x;
  real_T c66_gc_x;
  real_T c66_e_y;
  real_T c66_hc_x;
  real_T c66_ic_x;
  real_T c66_jc_x;
  real_T c66_kc_x;
  real_T c66_lc_x;
  real_T c66_mc_x;
  real_T c66_nc_x;
  real_T c66_oc_x;
  real_T c66_f_A;
  real_T c66_pc_x;
  real_T c66_qc_x;
  real_T c66_rc_x;
  real_T c66_f_y;
  real_T c66_sc_x;
  real_T c66_tc_x;
  real_T c66_uc_x;
  real_T c66_vc_x;
  real_T c66_wc_x;
  real_T c66_xc_x;
  real_T c66_yc_x;
  real_T c66_ad_x;
  real_T c66_g_A;
  real_T c66_bd_x;
  real_T c66_cd_x;
  real_T c66_dd_x;
  real_T c66_g_y;
  real_T c66_ed_x;
  real_T c66_fd_x;
  real_T c66_gd_x;
  real_T c66_hd_x;
  real_T c66_id_x;
  real_T c66_jd_x;
  real_T c66_kd_x;
  real_T c66_ld_x;
  real_T c66_h_A;
  real_T c66_md_x;
  real_T c66_nd_x;
  real_T c66_od_x;
  real_T c66_h_y;
  real_T c66_pd_x;
  real_T c66_qd_x;
  real_T c66_rd_x;
  real_T c66_sd_x;
  real_T c66_td_x;
  real_T c66_ud_x;
  real_T c66_vd_x;
  real_T c66_wd_x;
  real_T c66_i_A;
  real_T c66_xd_x;
  real_T c66_yd_x;
  real_T c66_ae_x;
  real_T c66_i_y;
  real_T c66_be_x;
  real_T c66_ce_x;
  real_T c66_de_x;
  real_T c66_ee_x;
  real_T c66_fe_x;
  real_T c66_ge_x;
  real_T c66_he_x;
  real_T c66_ie_x;
  real_T c66_j_A;
  real_T c66_je_x;
  real_T c66_ke_x;
  real_T c66_le_x;
  real_T c66_j_y;
  real_T c66_me_x;
  real_T c66_ne_x;
  real_T c66_oe_x;
  real_T c66_pe_x;
  real_T c66_qe_x;
  real_T c66_re_x;
  real_T c66_se_x;
  real_T c66_te_x;
  real_T c66_k_A;
  real_T c66_ue_x;
  real_T c66_ve_x;
  real_T c66_we_x;
  real_T c66_k_y;
  real_T c66_xe_x;
  real_T c66_ye_x;
  real_T c66_af_x;
  real_T c66_bf_x;
  real_T c66_cf_x;
  real_T c66_df_x;
  real_T c66_ef_x;
  real_T c66_ff_x;
  real_T c66_l_A;
  real_T c66_gf_x;
  real_T c66_hf_x;
  real_T c66_if_x;
  real_T c66_l_y;
  real_T c66_jf_x;
  real_T c66_kf_x;
  real_T c66_lf_x;
  real_T c66_mf_x;
  real_T c66_nf_x;
  real_T c66_of_x;
  real_T c66_pf_x;
  real_T c66_qf_x;
  real_T c66_m_A;
  real_T c66_rf_x;
  real_T c66_sf_x;
  real_T c66_tf_x;
  real_T c66_m_y;
  real_T c66_uf_x;
  real_T c66_vf_x;
  real_T c66_wf_x;
  real_T c66_xf_x;
  real_T c66_yf_x;
  real_T c66_ag_x;
  real_T c66_bg_x;
  real_T c66_cg_x;
  real_T c66_n_A;
  real_T c66_dg_x;
  real_T c66_eg_x;
  real_T c66_fg_x;
  real_T c66_n_y;
  real_T c66_gg_x;
  real_T c66_hg_x;
  real_T c66_ig_x;
  real_T c66_jg_x;
  real_T c66_kg_x;
  real_T c66_lg_x;
  real_T c66_mg_x;
  real_T c66_ng_x;
  real_T c66_o_A;
  real_T c66_og_x;
  real_T c66_pg_x;
  real_T c66_qg_x;
  real_T c66_o_y;
  real_T c66_rg_x;
  real_T c66_sg_x;
  real_T c66_tg_x;
  real_T c66_ug_x;
  real_T c66_vg_x;
  real_T c66_wg_x;
  real_T c66_xg_x;
  real_T c66_yg_x;
  real_T c66_p_A;
  real_T c66_ah_x;
  real_T c66_bh_x;
  real_T c66_ch_x;
  real_T c66_p_y;
  real_T c66_dh_x;
  real_T c66_eh_x;
  real_T c66_fh_x;
  real_T c66_gh_x;
  real_T c66_hh_x;
  real_T c66_ih_x;
  real_T c66_jh_x;
  real_T c66_kh_x;
  real_T c66_q_A;
  real_T c66_lh_x;
  real_T c66_mh_x;
  real_T c66_nh_x;
  real_T c66_q_y;
  real_T c66_oh_x;
  real_T c66_ph_x;
  real_T c66_qh_x;
  real_T c66_rh_x;
  real_T c66_sh_x;
  real_T c66_th_x;
  real_T c66_uh_x;
  real_T c66_vh_x;
  real_T c66_r_A;
  real_T c66_wh_x;
  real_T c66_xh_x;
  real_T c66_yh_x;
  real_T c66_r_y;
  real_T c66_ai_x;
  real_T c66_bi_x;
  real_T c66_ci_x;
  real_T c66_di_x;
  real_T c66_ei_x;
  real_T c66_fi_x;
  real_T c66_gi_x;
  real_T c66_hi_x;
  real_T c66_ii_x;
  real_T c66_ji_x;
  real_T c66_ki_x;
  real_T c66_li_x;
  real_T c66_mi_x;
  real_T c66_ni_x;
  real_T c66_oi_x;
  real_T c66_pi_x;
  real_T c66_qi_x;
  real_T c66_ri_x;
  real_T c66_si_x;
  real_T c66_ti_x;
  real_T c66_ui_x;
  real_T c66_vi_x;
  real_T c66_wi_x;
  real_T c66_xi_x;
  real_T c66_yi_x;
  real_T c66_aj_x;
  real_T c66_bj_x;
  real_T c66_cj_x;
  real_T c66_dj_x;
  real_T c66_ej_x;
  real_T c66_fj_x;
  real_T c66_gj_x;
  real_T c66_s_A;
  real_T c66_hj_x;
  real_T c66_ij_x;
  real_T c66_jj_x;
  real_T c66_s_y;
  real_T c66_kj_x;
  real_T c66_lj_x;
  real_T c66_mj_x;
  real_T c66_nj_x;
  real_T c66_oj_x;
  real_T c66_pj_x;
  real_T c66_qj_x;
  real_T c66_rj_x;
  real_T c66_t_A;
  real_T c66_sj_x;
  real_T c66_tj_x;
  real_T c66_uj_x;
  real_T c66_t_y;
  real_T c66_vj_x;
  real_T c66_wj_x;
  real_T c66_xj_x;
  real_T c66_yj_x;
  real_T c66_ak_x;
  real_T c66_bk_x;
  real_T c66_ck_x;
  real_T c66_dk_x;
  real_T c66_ek_x;
  real_T c66_fk_x;
  real_T c66_gk_x;
  real_T c66_hk_x;
  real_T c66_ik_x;
  real_T c66_jk_x;
  real_T c66_kk_x;
  real_T c66_lk_x;
  real_T c66_mk_x;
  real_T c66_nk_x;
  real_T c66_ok_x;
  real_T c66_pk_x;
  real_T c66_qk_x;
  real_T c66_rk_x;
  real_T c66_sk_x;
  real_T c66_tk_x;
  real_T c66_u_A;
  real_T c66_uk_x;
  real_T c66_vk_x;
  real_T c66_wk_x;
  real_T c66_u_y;
  real_T c66_xk_x;
  real_T c66_yk_x;
  real_T c66_al_x;
  real_T c66_bl_x;
  real_T c66_cl_x;
  real_T c66_dl_x;
  real_T c66_v_A;
  real_T c66_el_x;
  real_T c66_fl_x;
  real_T c66_gl_x;
  real_T c66_v_y;
  real_T c66_hl_x;
  real_T c66_il_x;
  real_T c66_jl_x;
  real_T c66_kl_x;
  real_T c66_ll_x;
  real_T c66_ml_x;
  real_T c66_w_A;
  real_T c66_nl_x;
  real_T c66_ol_x;
  real_T c66_pl_x;
  real_T c66_w_y;
  real_T c66_ql_x;
  real_T c66_rl_x;
  real_T c66_sl_x;
  real_T c66_tl_x;
  real_T c66_ul_x;
  real_T c66_vl_x;
  real_T c66_x_A;
  real_T c66_wl_x;
  real_T c66_xl_x;
  real_T c66_yl_x;
  real_T c66_x_y;
  real_T c66_am_x;
  real_T c66_bm_x;
  real_T c66_cm_x;
  real_T c66_dm_x;
  real_T c66_em_x;
  real_T c66_fm_x;
  real_T c66_y_A;
  real_T c66_gm_x;
  real_T c66_hm_x;
  real_T c66_im_x;
  real_T c66_y_y;
  real_T c66_jm_x;
  real_T c66_km_x;
  real_T c66_lm_x;
  real_T c66_mm_x;
  real_T c66_nm_x;
  real_T c66_om_x;
  real_T c66_ab_A;
  real_T c66_pm_x;
  real_T c66_qm_x;
  real_T c66_rm_x;
  real_T c66_ab_y;
  real_T c66_sm_x;
  real_T c66_tm_x;
  real_T c66_um_x;
  real_T c66_vm_x;
  real_T c66_wm_x;
  real_T c66_xm_x;
  real_T c66_bb_A;
  real_T c66_ym_x;
  real_T c66_an_x;
  real_T c66_bn_x;
  real_T c66_bb_y;
  real_T c66_cn_x;
  real_T c66_dn_x;
  real_T c66_en_x;
  real_T c66_fn_x;
  real_T c66_gn_x;
  real_T c66_hn_x;
  real_T c66_cb_A;
  real_T c66_in_x;
  real_T c66_jn_x;
  real_T c66_kn_x;
  real_T c66_cb_y;
  real_T c66_ln_x;
  real_T c66_mn_x;
  real_T c66_nn_x;
  real_T c66_on_x;
  real_T c66_pn_x;
  real_T c66_qn_x;
  real_T c66_rn_x;
  real_T c66_sn_x;
  real_T c66_tn_x;
  real_T c66_un_x;
  real_T c66_vn_x;
  real_T c66_wn_x;
  real_T c66_xn_x;
  real_T c66_yn_x;
  real_T c66_ao_x;
  real_T c66_bo_x;
  real_T c66_co_x;
  real_T c66_do_x;
  real_T c66_eo_x;
  real_T c66_fo_x;
  real_T c66_db_A;
  real_T c66_go_x;
  real_T c66_ho_x;
  real_T c66_io_x;
  real_T c66_db_y;
  real_T c66_jo_x;
  real_T c66_ko_x;
  real_T c66_lo_x;
  real_T c66_mo_x;
  real_T c66_no_x;
  real_T c66_oo_x;
  real_T c66_eb_A;
  real_T c66_po_x;
  real_T c66_qo_x;
  real_T c66_ro_x;
  real_T c66_eb_y;
  real_T c66_so_x;
  real_T c66_to_x;
  real_T c66_uo_x;
  real_T c66_vo_x;
  real_T c66_wo_x;
  real_T c66_xo_x;
  real_T c66_fb_A;
  real_T c66_yo_x;
  real_T c66_ap_x;
  real_T c66_bp_x;
  real_T c66_fb_y;
  real_T c66_cp_x;
  real_T c66_dp_x;
  real_T c66_ep_x;
  real_T c66_fp_x;
  real_T c66_gp_x;
  real_T c66_hp_x;
  real_T c66_gb_A;
  real_T c66_ip_x;
  real_T c66_jp_x;
  real_T c66_kp_x;
  real_T c66_gb_y;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 8U, chartInstance->c66_sfEvent);
  c66_hoistedGlobal = *chartInstance->c66_stanceLeg;
  for (c66_i2 = 0; c66_i2 < 13; c66_i2++) {
    c66_b_q[c66_i2] = (*chartInstance->c66_q)[c66_i2];
  }

  for (c66_i3 = 0; c66_i3 < 13; c66_i3++) {
    c66_b_dq[c66_i3] = (*chartInstance->c66_dq)[c66_i3];
  }

  c66_b_stanceLeg = c66_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 48U, 48U, c66_debug_family_names,
    c66_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_ks_leg, 0U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_m_torso, 1U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_m_total, 2U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_g, 3U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_l_h, 4U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_l_st_h, 5U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_f_c, 6U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_f_v, 7U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c66_z_offset, 8U, c66_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c66_y_offset, 9U, c66_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c66_x_offset, 10U, c66_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_q_st_mA, 11U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_dq_st_mA, 12U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_q_st_mB, 13U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_dq_st_mB, 14U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_q_st_lA, 15U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_dq_st_lA, 16U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_q_st_lB, 17U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_dq_st_lB, 18U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_q_st_h, 19U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_dq_st_h, 20U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_q_sw_mA, 21U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_dq_sw_mA, 22U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_q_sw_mB, 23U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_dq_sw_mB, 24U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_q_sw_lA, 25U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_dq_sw_lA, 26U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_q_sw_lB, 27U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_dq_sw_lB, 28U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_q_sw_h, 29U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_dq_sw_h, 30U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_q_yaw, 31U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_dq_yaw, 32U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_q_pitch, 33U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_dq_pitch, 34U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_q_roll, 35U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_dq_roll, 36U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_nargin, 37U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_nargout, 38U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c66_b_q, 39U, c66_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c66_b_dq, 40U, c66_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c66_b_stanceLeg, 41U, c66_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_b_dy, 42U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_b_dy_prev, 43U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_b_ddy_prev, 44U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_b_dx, 45U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_b_dx_prev, 46U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c66_b_ddx_prev, 47U, c66_sf_marshallOut,
    c66_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 5);
  c66_ks_leg = 9081.45;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 7);
  c66_m_torso = 22.2;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 9);
  c66_m_total = 61.24;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 11);
  c66_g = 9.81;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 13);
  c66_l_h = 0.1831;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 15);
  if (CV_EML_IF(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c66_b_stanceLeg, 1.0, -1,
        0U, c66_b_stanceLeg == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 16);
    c66_l_st_h = c66_l_h;
  } else {
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 18);
    c66_l_st_h = -c66_l_h;
  }

  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 21);
  c66_f_c = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 23);
  c66_f_v = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 25);
  c66_z_offset = 0.2087;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 27);
  c66_y_offset = 0.05;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 29);
  c66_x_offset = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 32);
  if (CV_EML_IF(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c66_b_stanceLeg, 1.0, -1,
        0U, c66_b_stanceLeg == 1.0))) {
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 33);
    c66_q_st_mA = c66_b_q[7];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 33);
    c66_dq_st_mA = c66_b_dq[7];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 33);
    c66_q_st_mB = c66_b_q[5];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 33);
    c66_dq_st_mB = c66_b_dq[5];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 34);
    c66_q_st_lA = c66_b_q[6];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 34);
    c66_dq_st_lA = c66_b_dq[6];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 34);
    c66_q_st_lB = c66_b_q[4];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 34);
    c66_dq_st_lB = c66_b_dq[4];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 35);
    c66_q_st_h = c66_b_q[9];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 35);
    c66_dq_st_h = c66_b_dq[9];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 36);
    c66_q_sw_mA = c66_b_q[3];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 36);
    c66_dq_sw_mA = c66_b_dq[3];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 36);
    c66_q_sw_mB = c66_b_q[1];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 36);
    c66_dq_sw_mB = c66_b_dq[1];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 37);
    c66_q_sw_lA = c66_b_q[2];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 37);
    c66_dq_sw_lA = c66_b_dq[2];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 37);
    c66_q_sw_lB = c66_b_q[0];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 37);
    c66_dq_sw_lB = c66_b_dq[0];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 38);
    c66_q_sw_h = -c66_b_q[8];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 38);
    c66_dq_sw_h = -c66_b_dq[8];
  } else {
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 40);
    c66_q_st_mA = c66_b_q[3];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 40);
    c66_dq_st_mA = c66_b_dq[3];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 40);
    c66_q_st_mB = c66_b_q[1];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 40);
    c66_dq_st_mB = c66_b_dq[1];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 41);
    c66_q_st_lA = c66_b_q[2];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 41);
    c66_dq_st_lA = c66_b_dq[2];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 41);
    c66_q_st_lB = c66_b_q[0];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 41);
    c66_dq_st_lB = c66_b_dq[0];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 42);
    c66_q_st_h = -c66_b_q[8];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 42);
    c66_dq_st_h = -c66_b_dq[8];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 43);
    c66_q_sw_mA = c66_b_q[7];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 43);
    c66_dq_sw_mA = c66_b_dq[7];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 43);
    c66_q_sw_mB = c66_b_q[5];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 43);
    c66_dq_sw_mB = c66_b_dq[5];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 44);
    c66_q_sw_lA = c66_b_q[6];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 44);
    c66_dq_sw_lA = c66_b_dq[6];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 44);
    c66_q_sw_lB = c66_b_q[4];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 44);
    c66_dq_sw_lB = c66_b_dq[4];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 45);
    c66_q_sw_h = c66_b_q[9];
    _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 45);
    c66_dq_sw_h = c66_b_dq[9];
  }

  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 49);
  c66_q_yaw = c66_b_q[11];
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 49);
  c66_dq_yaw = c66_b_dq[11];
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 50);
  c66_q_pitch = c66_b_q[12];
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 50);
  c66_dq_pitch = c66_b_dq[12];
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 51);
  c66_q_roll = c66_b_q[10];
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 51);
  c66_dq_roll = c66_b_dq[10];
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 53);
  c66_b_dy_prev = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 54);
  c66_b_ddy_prev = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 55);
  c66_b_dx_prev = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 56);
  c66_b_ddx_prev = 0.0;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 58);
  c66_x = c66_q_pitch;
  c66_b_x = c66_x;
  c66_b_x = muDoubleScalarSin(c66_b_x);
  c66_c_x = c66_q_st_lA;
  c66_d_x = c66_c_x;
  c66_d_x = muDoubleScalarSin(c66_d_x);
  c66_A = c66_b_x * c66_d_x * c66_dq_pitch;
  c66_e_x = c66_A;
  c66_f_x = c66_e_x;
  c66_g_x = c66_f_x;
  c66_y = c66_g_x / 2.0;
  c66_h_x = c66_q_pitch;
  c66_i_x = c66_h_x;
  c66_i_x = muDoubleScalarCos(c66_i_x);
  c66_j_x = c66_q_st_lB;
  c66_k_x = c66_j_x;
  c66_k_x = muDoubleScalarCos(c66_k_x);
  c66_b_A = c66_i_x * c66_k_x * c66_dq_st_lB;
  c66_l_x = c66_b_A;
  c66_m_x = c66_l_x;
  c66_n_x = c66_m_x;
  c66_b_y = c66_n_x / 2.0;
  c66_o_x = c66_q_pitch;
  c66_p_x = c66_o_x;
  c66_p_x = muDoubleScalarCos(c66_p_x);
  c66_q_x = c66_q_st_lA;
  c66_r_x = c66_q_x;
  c66_r_x = muDoubleScalarCos(c66_r_x);
  c66_c_A = c66_p_x * c66_r_x * c66_dq_st_lA;
  c66_s_x = c66_c_A;
  c66_t_x = c66_s_x;
  c66_u_x = c66_t_x;
  c66_c_y = c66_u_x / 2.0;
  c66_v_x = c66_q_pitch;
  c66_w_x = c66_v_x;
  c66_w_x = muDoubleScalarSin(c66_w_x);
  c66_x_x = c66_q_st_lB;
  c66_y_x = c66_x_x;
  c66_y_x = muDoubleScalarSin(c66_y_x);
  c66_d_A = c66_w_x * c66_y_x * c66_dq_pitch;
  c66_ab_x = c66_d_A;
  c66_bb_x = c66_ab_x;
  c66_cb_x = c66_bb_x;
  c66_d_y = c66_cb_x / 2.0;
  c66_db_x = c66_q_pitch;
  c66_eb_x = c66_db_x;
  c66_eb_x = muDoubleScalarSin(c66_eb_x);
  c66_fb_x = c66_q_pitch;
  c66_gb_x = c66_fb_x;
  c66_gb_x = muDoubleScalarCos(c66_gb_x);
  c66_hb_x = c66_q_roll;
  c66_ib_x = c66_hb_x;
  c66_ib_x = muDoubleScalarCos(c66_ib_x);
  c66_jb_x = c66_q_pitch;
  c66_kb_x = c66_jb_x;
  c66_kb_x = muDoubleScalarCos(c66_kb_x);
  c66_lb_x = c66_q_roll;
  c66_mb_x = c66_lb_x;
  c66_mb_x = muDoubleScalarSin(c66_mb_x);
  c66_nb_x = c66_q_roll;
  c66_ob_x = c66_nb_x;
  c66_ob_x = muDoubleScalarCos(c66_ob_x);
  c66_pb_x = c66_q_pitch;
  c66_qb_x = c66_pb_x;
  c66_qb_x = muDoubleScalarSin(c66_qb_x);
  c66_rb_x = c66_q_pitch;
  c66_sb_x = c66_rb_x;
  c66_sb_x = muDoubleScalarSin(c66_sb_x);
  c66_tb_x = c66_q_roll;
  c66_ub_x = c66_tb_x;
  c66_ub_x = muDoubleScalarSin(c66_ub_x);
  c66_vb_x = c66_q_pitch;
  c66_wb_x = c66_vb_x;
  c66_wb_x = muDoubleScalarCos(c66_wb_x);
  c66_xb_x = c66_q_roll;
  c66_yb_x = c66_xb_x;
  c66_yb_x = muDoubleScalarCos(c66_yb_x);
  c66_ac_x = c66_q_st_h;
  c66_bc_x = c66_ac_x;
  c66_bc_x = muDoubleScalarCos(c66_bc_x);
  c66_cc_x = c66_q_st_lA;
  c66_dc_x = c66_cc_x;
  c66_dc_x = muDoubleScalarCos(c66_dc_x);
  c66_e_A = c66_wb_x * c66_yb_x * c66_bc_x * c66_dc_x * c66_dq_pitch;
  c66_ec_x = c66_e_A;
  c66_fc_x = c66_ec_x;
  c66_gc_x = c66_fc_x;
  c66_e_y = c66_gc_x / 2.0;
  c66_hc_x = c66_q_pitch;
  c66_ic_x = c66_hc_x;
  c66_ic_x = muDoubleScalarCos(c66_ic_x);
  c66_jc_x = c66_q_roll;
  c66_kc_x = c66_jc_x;
  c66_kc_x = muDoubleScalarCos(c66_kc_x);
  c66_lc_x = c66_q_st_h;
  c66_mc_x = c66_lc_x;
  c66_mc_x = muDoubleScalarCos(c66_mc_x);
  c66_nc_x = c66_q_st_lB;
  c66_oc_x = c66_nc_x;
  c66_oc_x = muDoubleScalarCos(c66_oc_x);
  c66_f_A = c66_ic_x * c66_kc_x * c66_mc_x * c66_oc_x * c66_dq_pitch;
  c66_pc_x = c66_f_A;
  c66_qc_x = c66_pc_x;
  c66_rc_x = c66_qc_x;
  c66_f_y = c66_rc_x / 2.0;
  c66_sc_x = c66_q_pitch;
  c66_tc_x = c66_sc_x;
  c66_tc_x = muDoubleScalarCos(c66_tc_x);
  c66_uc_x = c66_q_st_lA;
  c66_vc_x = c66_uc_x;
  c66_vc_x = muDoubleScalarCos(c66_vc_x);
  c66_wc_x = c66_q_roll;
  c66_xc_x = c66_wc_x;
  c66_xc_x = muDoubleScalarSin(c66_xc_x);
  c66_yc_x = c66_q_st_h;
  c66_ad_x = c66_yc_x;
  c66_ad_x = muDoubleScalarSin(c66_ad_x);
  c66_g_A = c66_tc_x * c66_vc_x * c66_xc_x * c66_ad_x * c66_dq_pitch;
  c66_bd_x = c66_g_A;
  c66_cd_x = c66_bd_x;
  c66_dd_x = c66_cd_x;
  c66_g_y = c66_dd_x / 2.0;
  c66_ed_x = c66_q_pitch;
  c66_fd_x = c66_ed_x;
  c66_fd_x = muDoubleScalarCos(c66_fd_x);
  c66_gd_x = c66_q_st_lB;
  c66_hd_x = c66_gd_x;
  c66_hd_x = muDoubleScalarCos(c66_hd_x);
  c66_id_x = c66_q_roll;
  c66_jd_x = c66_id_x;
  c66_jd_x = muDoubleScalarSin(c66_jd_x);
  c66_kd_x = c66_q_st_h;
  c66_ld_x = c66_kd_x;
  c66_ld_x = muDoubleScalarSin(c66_ld_x);
  c66_h_A = c66_fd_x * c66_hd_x * c66_jd_x * c66_ld_x * c66_dq_pitch;
  c66_md_x = c66_h_A;
  c66_nd_x = c66_md_x;
  c66_od_x = c66_nd_x;
  c66_h_y = c66_od_x / 2.0;
  c66_pd_x = c66_q_roll;
  c66_qd_x = c66_pd_x;
  c66_qd_x = muDoubleScalarCos(c66_qd_x);
  c66_rd_x = c66_q_st_lA;
  c66_sd_x = c66_rd_x;
  c66_sd_x = muDoubleScalarCos(c66_sd_x);
  c66_td_x = c66_q_pitch;
  c66_ud_x = c66_td_x;
  c66_ud_x = muDoubleScalarSin(c66_ud_x);
  c66_vd_x = c66_q_st_h;
  c66_wd_x = c66_vd_x;
  c66_wd_x = muDoubleScalarSin(c66_wd_x);
  c66_i_A = c66_qd_x * c66_sd_x * c66_ud_x * c66_wd_x * c66_dq_roll;
  c66_xd_x = c66_i_A;
  c66_yd_x = c66_xd_x;
  c66_ae_x = c66_yd_x;
  c66_i_y = c66_ae_x / 2.0;
  c66_be_x = c66_q_st_h;
  c66_ce_x = c66_be_x;
  c66_ce_x = muDoubleScalarCos(c66_ce_x);
  c66_de_x = c66_q_st_lA;
  c66_ee_x = c66_de_x;
  c66_ee_x = muDoubleScalarCos(c66_ee_x);
  c66_fe_x = c66_q_pitch;
  c66_ge_x = c66_fe_x;
  c66_ge_x = muDoubleScalarSin(c66_ge_x);
  c66_he_x = c66_q_roll;
  c66_ie_x = c66_he_x;
  c66_ie_x = muDoubleScalarSin(c66_ie_x);
  c66_j_A = c66_ce_x * c66_ee_x * c66_ge_x * c66_ie_x * c66_dq_roll;
  c66_je_x = c66_j_A;
  c66_ke_x = c66_je_x;
  c66_le_x = c66_ke_x;
  c66_j_y = c66_le_x / 2.0;
  c66_me_x = c66_q_roll;
  c66_ne_x = c66_me_x;
  c66_ne_x = muDoubleScalarCos(c66_ne_x);
  c66_oe_x = c66_q_st_lB;
  c66_pe_x = c66_oe_x;
  c66_pe_x = muDoubleScalarCos(c66_pe_x);
  c66_qe_x = c66_q_pitch;
  c66_re_x = c66_qe_x;
  c66_re_x = muDoubleScalarSin(c66_re_x);
  c66_se_x = c66_q_st_h;
  c66_te_x = c66_se_x;
  c66_te_x = muDoubleScalarSin(c66_te_x);
  c66_k_A = c66_ne_x * c66_pe_x * c66_re_x * c66_te_x * c66_dq_roll;
  c66_ue_x = c66_k_A;
  c66_ve_x = c66_ue_x;
  c66_we_x = c66_ve_x;
  c66_k_y = c66_we_x / 2.0;
  c66_xe_x = c66_q_st_h;
  c66_ye_x = c66_xe_x;
  c66_ye_x = muDoubleScalarCos(c66_ye_x);
  c66_af_x = c66_q_st_lB;
  c66_bf_x = c66_af_x;
  c66_bf_x = muDoubleScalarCos(c66_bf_x);
  c66_cf_x = c66_q_pitch;
  c66_df_x = c66_cf_x;
  c66_df_x = muDoubleScalarSin(c66_df_x);
  c66_ef_x = c66_q_roll;
  c66_ff_x = c66_ef_x;
  c66_ff_x = muDoubleScalarSin(c66_ff_x);
  c66_l_A = c66_ye_x * c66_bf_x * c66_df_x * c66_ff_x * c66_dq_roll;
  c66_gf_x = c66_l_A;
  c66_hf_x = c66_gf_x;
  c66_if_x = c66_hf_x;
  c66_l_y = c66_if_x / 2.0;
  c66_jf_x = c66_q_roll;
  c66_kf_x = c66_jf_x;
  c66_kf_x = muDoubleScalarCos(c66_kf_x);
  c66_lf_x = c66_q_st_lA;
  c66_mf_x = c66_lf_x;
  c66_mf_x = muDoubleScalarCos(c66_mf_x);
  c66_nf_x = c66_q_pitch;
  c66_of_x = c66_nf_x;
  c66_of_x = muDoubleScalarSin(c66_of_x);
  c66_pf_x = c66_q_st_h;
  c66_qf_x = c66_pf_x;
  c66_qf_x = muDoubleScalarSin(c66_qf_x);
  c66_m_A = c66_kf_x * c66_mf_x * c66_of_x * c66_qf_x * c66_dq_st_h;
  c66_rf_x = c66_m_A;
  c66_sf_x = c66_rf_x;
  c66_tf_x = c66_sf_x;
  c66_m_y = c66_tf_x / 2.0;
  c66_uf_x = c66_q_st_h;
  c66_vf_x = c66_uf_x;
  c66_vf_x = muDoubleScalarCos(c66_vf_x);
  c66_wf_x = c66_q_st_lA;
  c66_xf_x = c66_wf_x;
  c66_xf_x = muDoubleScalarCos(c66_xf_x);
  c66_yf_x = c66_q_pitch;
  c66_ag_x = c66_yf_x;
  c66_ag_x = muDoubleScalarSin(c66_ag_x);
  c66_bg_x = c66_q_roll;
  c66_cg_x = c66_bg_x;
  c66_cg_x = muDoubleScalarSin(c66_cg_x);
  c66_n_A = c66_vf_x * c66_xf_x * c66_ag_x * c66_cg_x * c66_dq_st_h;
  c66_dg_x = c66_n_A;
  c66_eg_x = c66_dg_x;
  c66_fg_x = c66_eg_x;
  c66_n_y = c66_fg_x / 2.0;
  c66_gg_x = c66_q_roll;
  c66_hg_x = c66_gg_x;
  c66_hg_x = muDoubleScalarCos(c66_hg_x);
  c66_ig_x = c66_q_st_lB;
  c66_jg_x = c66_ig_x;
  c66_jg_x = muDoubleScalarCos(c66_jg_x);
  c66_kg_x = c66_q_pitch;
  c66_lg_x = c66_kg_x;
  c66_lg_x = muDoubleScalarSin(c66_lg_x);
  c66_mg_x = c66_q_st_h;
  c66_ng_x = c66_mg_x;
  c66_ng_x = muDoubleScalarSin(c66_ng_x);
  c66_o_A = c66_hg_x * c66_jg_x * c66_lg_x * c66_ng_x * c66_dq_st_h;
  c66_og_x = c66_o_A;
  c66_pg_x = c66_og_x;
  c66_qg_x = c66_pg_x;
  c66_o_y = c66_qg_x / 2.0;
  c66_rg_x = c66_q_st_h;
  c66_sg_x = c66_rg_x;
  c66_sg_x = muDoubleScalarCos(c66_sg_x);
  c66_tg_x = c66_q_st_lB;
  c66_ug_x = c66_tg_x;
  c66_ug_x = muDoubleScalarCos(c66_ug_x);
  c66_vg_x = c66_q_pitch;
  c66_wg_x = c66_vg_x;
  c66_wg_x = muDoubleScalarSin(c66_wg_x);
  c66_xg_x = c66_q_roll;
  c66_yg_x = c66_xg_x;
  c66_yg_x = muDoubleScalarSin(c66_yg_x);
  c66_p_A = c66_sg_x * c66_ug_x * c66_wg_x * c66_yg_x * c66_dq_st_h;
  c66_ah_x = c66_p_A;
  c66_bh_x = c66_ah_x;
  c66_ch_x = c66_bh_x;
  c66_p_y = c66_ch_x / 2.0;
  c66_dh_x = c66_q_roll;
  c66_eh_x = c66_dh_x;
  c66_eh_x = muDoubleScalarCos(c66_eh_x);
  c66_fh_x = c66_q_st_h;
  c66_gh_x = c66_fh_x;
  c66_gh_x = muDoubleScalarCos(c66_gh_x);
  c66_hh_x = c66_q_pitch;
  c66_ih_x = c66_hh_x;
  c66_ih_x = muDoubleScalarSin(c66_ih_x);
  c66_jh_x = c66_q_st_lA;
  c66_kh_x = c66_jh_x;
  c66_kh_x = muDoubleScalarSin(c66_kh_x);
  c66_q_A = c66_eh_x * c66_gh_x * c66_ih_x * c66_kh_x * c66_dq_st_lA;
  c66_lh_x = c66_q_A;
  c66_mh_x = c66_lh_x;
  c66_nh_x = c66_mh_x;
  c66_q_y = c66_nh_x / 2.0;
  c66_oh_x = c66_q_roll;
  c66_ph_x = c66_oh_x;
  c66_ph_x = muDoubleScalarCos(c66_ph_x);
  c66_qh_x = c66_q_st_h;
  c66_rh_x = c66_qh_x;
  c66_rh_x = muDoubleScalarCos(c66_rh_x);
  c66_sh_x = c66_q_pitch;
  c66_th_x = c66_sh_x;
  c66_th_x = muDoubleScalarSin(c66_th_x);
  c66_uh_x = c66_q_st_lB;
  c66_vh_x = c66_uh_x;
  c66_vh_x = muDoubleScalarSin(c66_vh_x);
  c66_r_A = c66_ph_x * c66_rh_x * c66_th_x * c66_vh_x * c66_dq_st_lB;
  c66_wh_x = c66_r_A;
  c66_xh_x = c66_wh_x;
  c66_yh_x = c66_xh_x;
  c66_r_y = c66_yh_x / 2.0;
  c66_ai_x = c66_q_pitch;
  c66_bi_x = c66_ai_x;
  c66_bi_x = muDoubleScalarCos(c66_bi_x);
  c66_ci_x = c66_q_roll;
  c66_di_x = c66_ci_x;
  c66_di_x = muDoubleScalarCos(c66_di_x);
  c66_ei_x = c66_q_st_h;
  c66_fi_x = c66_ei_x;
  c66_fi_x = muDoubleScalarSin(c66_fi_x);
  c66_gi_x = c66_q_pitch;
  c66_hi_x = c66_gi_x;
  c66_hi_x = muDoubleScalarCos(c66_hi_x);
  c66_ii_x = c66_q_st_h;
  c66_ji_x = c66_ii_x;
  c66_ji_x = muDoubleScalarCos(c66_ji_x);
  c66_ki_x = c66_q_roll;
  c66_li_x = c66_ki_x;
  c66_li_x = muDoubleScalarSin(c66_li_x);
  c66_mi_x = c66_q_roll;
  c66_ni_x = c66_mi_x;
  c66_ni_x = muDoubleScalarCos(c66_ni_x);
  c66_oi_x = c66_q_st_h;
  c66_pi_x = c66_oi_x;
  c66_pi_x = muDoubleScalarCos(c66_pi_x);
  c66_qi_x = c66_q_pitch;
  c66_ri_x = c66_qi_x;
  c66_ri_x = muDoubleScalarSin(c66_ri_x);
  c66_si_x = c66_q_roll;
  c66_ti_x = c66_si_x;
  c66_ti_x = muDoubleScalarCos(c66_ti_x);
  c66_ui_x = c66_q_st_h;
  c66_vi_x = c66_ui_x;
  c66_vi_x = muDoubleScalarCos(c66_vi_x);
  c66_wi_x = c66_q_pitch;
  c66_xi_x = c66_wi_x;
  c66_xi_x = muDoubleScalarSin(c66_xi_x);
  c66_yi_x = c66_q_pitch;
  c66_aj_x = c66_yi_x;
  c66_aj_x = muDoubleScalarSin(c66_aj_x);
  c66_bj_x = c66_q_roll;
  c66_cj_x = c66_bj_x;
  c66_cj_x = muDoubleScalarSin(c66_cj_x);
  c66_dj_x = c66_q_st_h;
  c66_ej_x = c66_dj_x;
  c66_ej_x = muDoubleScalarSin(c66_ej_x);
  c66_fj_x = c66_q_st_lA;
  c66_gj_x = c66_fj_x;
  c66_gj_x = muDoubleScalarSin(c66_gj_x);
  c66_s_A = c66_aj_x * c66_cj_x * c66_ej_x * c66_gj_x * c66_dq_st_lA;
  c66_hj_x = c66_s_A;
  c66_ij_x = c66_hj_x;
  c66_jj_x = c66_ij_x;
  c66_s_y = c66_jj_x / 2.0;
  c66_kj_x = c66_q_pitch;
  c66_lj_x = c66_kj_x;
  c66_lj_x = muDoubleScalarSin(c66_lj_x);
  c66_mj_x = c66_q_roll;
  c66_nj_x = c66_mj_x;
  c66_nj_x = muDoubleScalarSin(c66_nj_x);
  c66_oj_x = c66_q_st_h;
  c66_pj_x = c66_oj_x;
  c66_pj_x = muDoubleScalarSin(c66_pj_x);
  c66_qj_x = c66_q_st_lB;
  c66_rj_x = c66_qj_x;
  c66_rj_x = muDoubleScalarSin(c66_rj_x);
  c66_t_A = c66_lj_x * c66_nj_x * c66_pj_x * c66_rj_x * c66_dq_st_lB;
  c66_sj_x = c66_t_A;
  c66_tj_x = c66_sj_x;
  c66_uj_x = c66_tj_x;
  c66_t_y = c66_uj_x / 2.0;
  c66_vj_x = c66_q_pitch;
  c66_wj_x = c66_vj_x;
  c66_wj_x = muDoubleScalarSin(c66_wj_x);
  c66_xj_x = c66_q_roll;
  c66_yj_x = c66_xj_x;
  c66_yj_x = muDoubleScalarSin(c66_yj_x);
  c66_ak_x = c66_q_st_h;
  c66_bk_x = c66_ak_x;
  c66_bk_x = muDoubleScalarSin(c66_bk_x);
  c66_ck_x = c66_q_pitch;
  c66_dk_x = c66_ck_x;
  c66_dk_x = muDoubleScalarSin(c66_dk_x);
  c66_ek_x = c66_q_roll;
  c66_fk_x = c66_ek_x;
  c66_fk_x = muDoubleScalarSin(c66_fk_x);
  c66_gk_x = c66_q_st_h;
  c66_hk_x = c66_gk_x;
  c66_hk_x = muDoubleScalarSin(c66_hk_x);
  c66_b_dx = (((((((((((((((((((((((((((((c66_y - c66_b_y) - c66_c_y) + c66_d_y)
    - 0.0 * c66_eb_x * c66_dq_pitch) + 0.2087 * c66_gb_x * c66_ib_x *
    c66_dq_pitch) + 0.05 * c66_kb_x * c66_mb_x * c66_dq_pitch) + 0.05 * c66_ob_x
    * c66_qb_x * c66_dq_roll) - 0.2087 * c66_sb_x * c66_ub_x * c66_dq_roll) -
    c66_e_y) - c66_f_y) + c66_g_y) + c66_h_y) + c66_i_y) + c66_j_y) + c66_k_y) +
    c66_l_y) + c66_m_y) + c66_n_y) + c66_o_y) + c66_p_y) + c66_q_y) + c66_r_y) -
                    c66_l_st_h * c66_bi_x * c66_di_x * c66_fi_x * c66_dq_pitch)
                   - c66_l_st_h * c66_hi_x * c66_ji_x * c66_li_x * c66_dq_pitch)
                  - c66_l_st_h * c66_ni_x * c66_pi_x * c66_ri_x * c66_dq_roll) -
                 c66_l_st_h * c66_ti_x * c66_vi_x * c66_xi_x * c66_dq_st_h) -
                c66_s_y) - c66_t_y) + c66_l_st_h * c66_wj_x * c66_yj_x *
              c66_bk_x * c66_dq_roll) + c66_l_st_h * c66_dk_x * c66_fk_x *
    c66_hk_x * c66_dq_st_h;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, 59);
  c66_ik_x = c66_q_roll;
  c66_jk_x = c66_ik_x;
  c66_jk_x = muDoubleScalarCos(c66_jk_x);
  c66_kk_x = c66_q_st_h;
  c66_lk_x = c66_kk_x;
  c66_lk_x = muDoubleScalarSin(c66_lk_x);
  c66_mk_x = c66_q_roll;
  c66_nk_x = c66_mk_x;
  c66_nk_x = muDoubleScalarSin(c66_nk_x);
  c66_ok_x = c66_q_st_lA;
  c66_pk_x = c66_ok_x;
  c66_pk_x = muDoubleScalarCos(c66_pk_x);
  c66_qk_x = c66_q_roll;
  c66_rk_x = c66_qk_x;
  c66_rk_x = muDoubleScalarSin(c66_rk_x);
  c66_sk_x = c66_q_st_h;
  c66_tk_x = c66_sk_x;
  c66_tk_x = muDoubleScalarSin(c66_tk_x);
  c66_u_A = c66_pk_x * c66_rk_x * c66_tk_x * c66_dq_roll;
  c66_uk_x = c66_u_A;
  c66_vk_x = c66_uk_x;
  c66_wk_x = c66_vk_x;
  c66_u_y = c66_wk_x / 2.0;
  c66_xk_x = c66_q_st_lB;
  c66_yk_x = c66_xk_x;
  c66_yk_x = muDoubleScalarCos(c66_yk_x);
  c66_al_x = c66_q_roll;
  c66_bl_x = c66_al_x;
  c66_bl_x = muDoubleScalarSin(c66_bl_x);
  c66_cl_x = c66_q_st_h;
  c66_dl_x = c66_cl_x;
  c66_dl_x = muDoubleScalarSin(c66_dl_x);
  c66_v_A = c66_yk_x * c66_bl_x * c66_dl_x * c66_dq_roll;
  c66_el_x = c66_v_A;
  c66_fl_x = c66_el_x;
  c66_gl_x = c66_fl_x;
  c66_v_y = c66_gl_x / 2.0;
  c66_hl_x = c66_q_st_lA;
  c66_il_x = c66_hl_x;
  c66_il_x = muDoubleScalarCos(c66_il_x);
  c66_jl_x = c66_q_roll;
  c66_kl_x = c66_jl_x;
  c66_kl_x = muDoubleScalarSin(c66_kl_x);
  c66_ll_x = c66_q_st_h;
  c66_ml_x = c66_ll_x;
  c66_ml_x = muDoubleScalarSin(c66_ml_x);
  c66_w_A = c66_il_x * c66_kl_x * c66_ml_x * c66_dq_st_h;
  c66_nl_x = c66_w_A;
  c66_ol_x = c66_nl_x;
  c66_pl_x = c66_ol_x;
  c66_w_y = c66_pl_x / 2.0;
  c66_ql_x = c66_q_st_lB;
  c66_rl_x = c66_ql_x;
  c66_rl_x = muDoubleScalarCos(c66_rl_x);
  c66_sl_x = c66_q_roll;
  c66_tl_x = c66_sl_x;
  c66_tl_x = muDoubleScalarSin(c66_tl_x);
  c66_ul_x = c66_q_st_h;
  c66_vl_x = c66_ul_x;
  c66_vl_x = muDoubleScalarSin(c66_vl_x);
  c66_x_A = c66_rl_x * c66_tl_x * c66_vl_x * c66_dq_st_h;
  c66_wl_x = c66_x_A;
  c66_xl_x = c66_wl_x;
  c66_yl_x = c66_xl_x;
  c66_x_y = c66_yl_x / 2.0;
  c66_am_x = c66_q_roll;
  c66_bm_x = c66_am_x;
  c66_bm_x = muDoubleScalarCos(c66_bm_x);
  c66_cm_x = c66_q_st_h;
  c66_dm_x = c66_cm_x;
  c66_dm_x = muDoubleScalarSin(c66_dm_x);
  c66_em_x = c66_q_st_lA;
  c66_fm_x = c66_em_x;
  c66_fm_x = muDoubleScalarSin(c66_fm_x);
  c66_y_A = c66_bm_x * c66_dm_x * c66_fm_x * c66_dq_st_lA;
  c66_gm_x = c66_y_A;
  c66_hm_x = c66_gm_x;
  c66_im_x = c66_hm_x;
  c66_y_y = c66_im_x / 2.0;
  c66_jm_x = c66_q_st_h;
  c66_km_x = c66_jm_x;
  c66_km_x = muDoubleScalarCos(c66_km_x);
  c66_lm_x = c66_q_roll;
  c66_mm_x = c66_lm_x;
  c66_mm_x = muDoubleScalarSin(c66_mm_x);
  c66_nm_x = c66_q_st_lA;
  c66_om_x = c66_nm_x;
  c66_om_x = muDoubleScalarSin(c66_om_x);
  c66_ab_A = c66_km_x * c66_mm_x * c66_om_x * c66_dq_st_lA;
  c66_pm_x = c66_ab_A;
  c66_qm_x = c66_pm_x;
  c66_rm_x = c66_qm_x;
  c66_ab_y = c66_rm_x / 2.0;
  c66_sm_x = c66_q_roll;
  c66_tm_x = c66_sm_x;
  c66_tm_x = muDoubleScalarCos(c66_tm_x);
  c66_um_x = c66_q_st_h;
  c66_vm_x = c66_um_x;
  c66_vm_x = muDoubleScalarSin(c66_vm_x);
  c66_wm_x = c66_q_st_lB;
  c66_xm_x = c66_wm_x;
  c66_xm_x = muDoubleScalarSin(c66_xm_x);
  c66_bb_A = c66_tm_x * c66_vm_x * c66_xm_x * c66_dq_st_lB;
  c66_ym_x = c66_bb_A;
  c66_an_x = c66_ym_x;
  c66_bn_x = c66_an_x;
  c66_bb_y = c66_bn_x / 2.0;
  c66_cn_x = c66_q_st_h;
  c66_dn_x = c66_cn_x;
  c66_dn_x = muDoubleScalarCos(c66_dn_x);
  c66_en_x = c66_q_roll;
  c66_fn_x = c66_en_x;
  c66_fn_x = muDoubleScalarSin(c66_fn_x);
  c66_gn_x = c66_q_st_lB;
  c66_hn_x = c66_gn_x;
  c66_hn_x = muDoubleScalarSin(c66_hn_x);
  c66_cb_A = c66_dn_x * c66_fn_x * c66_hn_x * c66_dq_st_lB;
  c66_in_x = c66_cb_A;
  c66_jn_x = c66_in_x;
  c66_kn_x = c66_jn_x;
  c66_cb_y = c66_kn_x / 2.0;
  c66_ln_x = c66_q_roll;
  c66_mn_x = c66_ln_x;
  c66_mn_x = muDoubleScalarCos(c66_mn_x);
  c66_nn_x = c66_q_st_h;
  c66_on_x = c66_nn_x;
  c66_on_x = muDoubleScalarCos(c66_on_x);
  c66_pn_x = c66_q_roll;
  c66_qn_x = c66_pn_x;
  c66_qn_x = muDoubleScalarSin(c66_qn_x);
  c66_rn_x = c66_q_roll;
  c66_sn_x = c66_rn_x;
  c66_sn_x = muDoubleScalarCos(c66_sn_x);
  c66_tn_x = c66_q_st_h;
  c66_un_x = c66_tn_x;
  c66_un_x = muDoubleScalarSin(c66_un_x);
  c66_vn_x = c66_q_st_h;
  c66_wn_x = c66_vn_x;
  c66_wn_x = muDoubleScalarCos(c66_wn_x);
  c66_xn_x = c66_q_roll;
  c66_yn_x = c66_xn_x;
  c66_yn_x = muDoubleScalarSin(c66_yn_x);
  c66_ao_x = c66_q_roll;
  c66_bo_x = c66_ao_x;
  c66_bo_x = muDoubleScalarCos(c66_bo_x);
  c66_co_x = c66_q_st_h;
  c66_do_x = c66_co_x;
  c66_do_x = muDoubleScalarCos(c66_do_x);
  c66_eo_x = c66_q_st_lA;
  c66_fo_x = c66_eo_x;
  c66_fo_x = muDoubleScalarCos(c66_fo_x);
  c66_db_A = c66_bo_x * c66_do_x * c66_fo_x * c66_dq_roll;
  c66_go_x = c66_db_A;
  c66_ho_x = c66_go_x;
  c66_io_x = c66_ho_x;
  c66_db_y = c66_io_x / 2.0;
  c66_jo_x = c66_q_roll;
  c66_ko_x = c66_jo_x;
  c66_ko_x = muDoubleScalarCos(c66_ko_x);
  c66_lo_x = c66_q_st_h;
  c66_mo_x = c66_lo_x;
  c66_mo_x = muDoubleScalarCos(c66_mo_x);
  c66_no_x = c66_q_st_lB;
  c66_oo_x = c66_no_x;
  c66_oo_x = muDoubleScalarCos(c66_oo_x);
  c66_eb_A = c66_ko_x * c66_mo_x * c66_oo_x * c66_dq_roll;
  c66_po_x = c66_eb_A;
  c66_qo_x = c66_po_x;
  c66_ro_x = c66_qo_x;
  c66_eb_y = c66_ro_x / 2.0;
  c66_so_x = c66_q_roll;
  c66_to_x = c66_so_x;
  c66_to_x = muDoubleScalarCos(c66_to_x);
  c66_uo_x = c66_q_st_h;
  c66_vo_x = c66_uo_x;
  c66_vo_x = muDoubleScalarCos(c66_vo_x);
  c66_wo_x = c66_q_st_lA;
  c66_xo_x = c66_wo_x;
  c66_xo_x = muDoubleScalarCos(c66_xo_x);
  c66_fb_A = c66_to_x * c66_vo_x * c66_xo_x * c66_dq_st_h;
  c66_yo_x = c66_fb_A;
  c66_ap_x = c66_yo_x;
  c66_bp_x = c66_ap_x;
  c66_fb_y = c66_bp_x / 2.0;
  c66_cp_x = c66_q_roll;
  c66_dp_x = c66_cp_x;
  c66_dp_x = muDoubleScalarCos(c66_dp_x);
  c66_ep_x = c66_q_st_h;
  c66_fp_x = c66_ep_x;
  c66_fp_x = muDoubleScalarCos(c66_fp_x);
  c66_gp_x = c66_q_st_lB;
  c66_hp_x = c66_gp_x;
  c66_hp_x = muDoubleScalarCos(c66_hp_x);
  c66_gb_A = c66_dp_x * c66_fp_x * c66_hp_x * c66_dq_st_h;
  c66_ip_x = c66_gb_A;
  c66_jp_x = c66_ip_x;
  c66_kp_x = c66_jp_x;
  c66_gb_y = c66_kp_x / 2.0;
  c66_b_dy = ((((((((((((((((c66_l_st_h * c66_jk_x * c66_lk_x * c66_dq_roll -
    0.05 * c66_nk_x * c66_dq_roll) - c66_u_y) - c66_v_y) - c66_w_y) - c66_x_y) -
                        c66_y_y) - c66_ab_y) - c66_bb_y) - c66_cb_y) - 0.2087 *
                    c66_mn_x * c66_dq_roll) + c66_l_st_h * c66_on_x * c66_qn_x *
                   c66_dq_roll) + c66_l_st_h * c66_sn_x * c66_un_x * c66_dq_st_h)
                 + c66_l_st_h * c66_wn_x * c66_yn_x * c66_dq_st_h) + c66_db_y) +
               c66_eb_y) + c66_fb_y) + c66_gb_y;
  _SFD_EML_CALL(0U, chartInstance->c66_sfEvent, -59);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c66_dy = c66_b_dy;
  *chartInstance->c66_dy_prev = c66_b_dy_prev;
  *chartInstance->c66_ddy_prev = c66_b_ddy_prev;
  *chartInstance->c66_dx = c66_b_dx;
  *chartInstance->c66_dx_prev = c66_b_dx_prev;
  *chartInstance->c66_ddx_prev = c66_b_ddx_prev;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 8U, chartInstance->c66_sfEvent);
}

static void initSimStructsc66_DDA2D_OSU3Dv2(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c66_machineNumber, uint32_T
  c66_chartNumber, uint32_T c66_instanceNumber)
{
  (void)c66_machineNumber;
  (void)c66_chartNumber;
  (void)c66_instanceNumber;
}

static const mxArray *c66_sf_marshallOut(void *chartInstanceVoid, void
  *c66_inData)
{
  const mxArray *c66_mxArrayOutData = NULL;
  real_T c66_u;
  const mxArray *c66_y = NULL;
  SFc66_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc66_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c66_mxArrayOutData = NULL;
  c66_u = *(real_T *)c66_inData;
  c66_y = NULL;
  sf_mex_assign(&c66_y, sf_mex_create("y", &c66_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c66_mxArrayOutData, c66_y, false);
  return c66_mxArrayOutData;
}

static real_T c66_emlrt_marshallIn(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c66_b_ddx_prev, const char_T *c66_identifier)
{
  real_T c66_y;
  emlrtMsgIdentifier c66_thisId;
  c66_thisId.fIdentifier = c66_identifier;
  c66_thisId.fParent = NULL;
  c66_y = c66_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c66_b_ddx_prev),
    &c66_thisId);
  sf_mex_destroy(&c66_b_ddx_prev);
  return c66_y;
}

static real_T c66_b_emlrt_marshallIn(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c66_u, const emlrtMsgIdentifier *c66_parentId)
{
  real_T c66_y;
  real_T c66_d0;
  (void)chartInstance;
  sf_mex_import(c66_parentId, sf_mex_dup(c66_u), &c66_d0, 1, 0, 0U, 0, 0U, 0);
  c66_y = c66_d0;
  sf_mex_destroy(&c66_u);
  return c66_y;
}

static void c66_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c66_mxArrayInData, const char_T *c66_varName, void *c66_outData)
{
  const mxArray *c66_b_ddx_prev;
  const char_T *c66_identifier;
  emlrtMsgIdentifier c66_thisId;
  real_T c66_y;
  SFc66_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc66_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c66_b_ddx_prev = sf_mex_dup(c66_mxArrayInData);
  c66_identifier = c66_varName;
  c66_thisId.fIdentifier = c66_identifier;
  c66_thisId.fParent = NULL;
  c66_y = c66_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c66_b_ddx_prev),
    &c66_thisId);
  sf_mex_destroy(&c66_b_ddx_prev);
  *(real_T *)c66_outData = c66_y;
  sf_mex_destroy(&c66_mxArrayInData);
}

static const mxArray *c66_b_sf_marshallOut(void *chartInstanceVoid, void
  *c66_inData)
{
  const mxArray *c66_mxArrayOutData = NULL;
  int32_T c66_i4;
  real_T c66_b_inData[13];
  int32_T c66_i5;
  real_T c66_u[13];
  const mxArray *c66_y = NULL;
  SFc66_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc66_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c66_mxArrayOutData = NULL;
  for (c66_i4 = 0; c66_i4 < 13; c66_i4++) {
    c66_b_inData[c66_i4] = (*(real_T (*)[13])c66_inData)[c66_i4];
  }

  for (c66_i5 = 0; c66_i5 < 13; c66_i5++) {
    c66_u[c66_i5] = c66_b_inData[c66_i5];
  }

  c66_y = NULL;
  sf_mex_assign(&c66_y, sf_mex_create("y", c66_u, 0, 0U, 1U, 0U, 1, 13), false);
  sf_mex_assign(&c66_mxArrayOutData, c66_y, false);
  return c66_mxArrayOutData;
}

const mxArray *sf_c66_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void)
{
  const mxArray *c66_nameCaptureInfo = NULL;
  c66_nameCaptureInfo = NULL;
  sf_mex_assign(&c66_nameCaptureInfo, sf_mex_createstruct("structure", 2, 24, 1),
                false);
  c66_info_helper(&c66_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c66_nameCaptureInfo);
  return c66_nameCaptureInfo;
}

static void c66_info_helper(const mxArray **c66_info)
{
  const mxArray *c66_rhs0 = NULL;
  const mxArray *c66_lhs0 = NULL;
  const mxArray *c66_rhs1 = NULL;
  const mxArray *c66_lhs1 = NULL;
  const mxArray *c66_rhs2 = NULL;
  const mxArray *c66_lhs2 = NULL;
  const mxArray *c66_rhs3 = NULL;
  const mxArray *c66_lhs3 = NULL;
  const mxArray *c66_rhs4 = NULL;
  const mxArray *c66_lhs4 = NULL;
  const mxArray *c66_rhs5 = NULL;
  const mxArray *c66_lhs5 = NULL;
  const mxArray *c66_rhs6 = NULL;
  const mxArray *c66_lhs6 = NULL;
  const mxArray *c66_rhs7 = NULL;
  const mxArray *c66_lhs7 = NULL;
  const mxArray *c66_rhs8 = NULL;
  const mxArray *c66_lhs8 = NULL;
  const mxArray *c66_rhs9 = NULL;
  const mxArray *c66_lhs9 = NULL;
  const mxArray *c66_rhs10 = NULL;
  const mxArray *c66_lhs10 = NULL;
  const mxArray *c66_rhs11 = NULL;
  const mxArray *c66_lhs11 = NULL;
  const mxArray *c66_rhs12 = NULL;
  const mxArray *c66_lhs12 = NULL;
  const mxArray *c66_rhs13 = NULL;
  const mxArray *c66_lhs13 = NULL;
  const mxArray *c66_rhs14 = NULL;
  const mxArray *c66_lhs14 = NULL;
  const mxArray *c66_rhs15 = NULL;
  const mxArray *c66_lhs15 = NULL;
  const mxArray *c66_rhs16 = NULL;
  const mxArray *c66_lhs16 = NULL;
  const mxArray *c66_rhs17 = NULL;
  const mxArray *c66_lhs17 = NULL;
  const mxArray *c66_rhs18 = NULL;
  const mxArray *c66_lhs18 = NULL;
  const mxArray *c66_rhs19 = NULL;
  const mxArray *c66_lhs19 = NULL;
  const mxArray *c66_rhs20 = NULL;
  const mxArray *c66_lhs20 = NULL;
  const mxArray *c66_rhs21 = NULL;
  const mxArray *c66_lhs21 = NULL;
  const mxArray *c66_rhs22 = NULL;
  const mxArray *c66_lhs22 = NULL;
  const mxArray *c66_rhs23 = NULL;
  const mxArray *c66_lhs23 = NULL;
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("mrdivide"), "name", "name",
                  0);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1410829248U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1370031486U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c66_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs0), "rhs", "rhs",
                  0);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs0), "lhs", "lhs",
                  0);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1389739374U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c66_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs1), "rhs", "rhs",
                  1);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs1), "lhs", "lhs",
                  1);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1363731880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c66_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs2), "rhs", "rhs",
                  2);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs2), "lhs", "lhs",
                  2);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c66_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs3), "rhs", "rhs",
                  3);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs3), "lhs", "lhs",
                  3);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1286840396U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c66_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs4), "rhs", "rhs",
                  4);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs4), "lhs", "lhs",
                  4);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1386445552U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c66_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs5), "rhs", "rhs",
                  5);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs5), "lhs", "lhs",
                  5);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c66_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs6), "rhs", "rhs",
                  6);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs6), "lhs", "lhs",
                  6);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(""), "context", "context", 7);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("mpower"), "name", "name", 7);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved",
                  "resolved", 7);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1363731878U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c66_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs7), "rhs", "rhs",
                  7);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs7), "lhs", "lhs",
                  7);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 8);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 8);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c66_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs8), "rhs", "rhs",
                  8);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs8), "lhs", "lhs",
                  8);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 9);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("ismatrix"), "name", "name",
                  9);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1331326458U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c66_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs9), "rhs", "rhs",
                  9);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs9), "lhs", "lhs",
                  9);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("power"), "name", "name", 10);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved",
                  "resolved", 10);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1395346506U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c66_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context",
                  "context", 11);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 11);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c66_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 12);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 12);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 12);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c66_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 13);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c66_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 14);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("eml_scalexp_alloc"), "name",
                  "name", 14);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c66_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                  "context", "context", 15);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("coder.internal.scalexpAlloc"),
                  "name", "name", 15);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c66_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                  "context", 16);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("floor"), "name", "name", 16);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved",
                  "resolved", 16);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1363731854U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c66_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 17);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 17);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c66_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context",
                  "context", 18);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("eml_scalar_floor"), "name",
                  "name", 18);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1286840326U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c66_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                  "context", "context", 19);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 19);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c66_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(""), "context", "context", 20);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("sin"), "name", "name", 20);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 20);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c66_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 21);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 21);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1286840336U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c66_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(""), "context", "context", 22);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("cos"), "name", "name", 22);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 22);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c66_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 23);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c66_info, c66_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(1286840322U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c66_info, c66_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c66_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c66_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c66_info, sf_mex_duplicatearraysafe(&c66_lhs23), "lhs", "lhs",
                  23);
  sf_mex_destroy(&c66_rhs0);
  sf_mex_destroy(&c66_lhs0);
  sf_mex_destroy(&c66_rhs1);
  sf_mex_destroy(&c66_lhs1);
  sf_mex_destroy(&c66_rhs2);
  sf_mex_destroy(&c66_lhs2);
  sf_mex_destroy(&c66_rhs3);
  sf_mex_destroy(&c66_lhs3);
  sf_mex_destroy(&c66_rhs4);
  sf_mex_destroy(&c66_lhs4);
  sf_mex_destroy(&c66_rhs5);
  sf_mex_destroy(&c66_lhs5);
  sf_mex_destroy(&c66_rhs6);
  sf_mex_destroy(&c66_lhs6);
  sf_mex_destroy(&c66_rhs7);
  sf_mex_destroy(&c66_lhs7);
  sf_mex_destroy(&c66_rhs8);
  sf_mex_destroy(&c66_lhs8);
  sf_mex_destroy(&c66_rhs9);
  sf_mex_destroy(&c66_lhs9);
  sf_mex_destroy(&c66_rhs10);
  sf_mex_destroy(&c66_lhs10);
  sf_mex_destroy(&c66_rhs11);
  sf_mex_destroy(&c66_lhs11);
  sf_mex_destroy(&c66_rhs12);
  sf_mex_destroy(&c66_lhs12);
  sf_mex_destroy(&c66_rhs13);
  sf_mex_destroy(&c66_lhs13);
  sf_mex_destroy(&c66_rhs14);
  sf_mex_destroy(&c66_lhs14);
  sf_mex_destroy(&c66_rhs15);
  sf_mex_destroy(&c66_lhs15);
  sf_mex_destroy(&c66_rhs16);
  sf_mex_destroy(&c66_lhs16);
  sf_mex_destroy(&c66_rhs17);
  sf_mex_destroy(&c66_lhs17);
  sf_mex_destroy(&c66_rhs18);
  sf_mex_destroy(&c66_lhs18);
  sf_mex_destroy(&c66_rhs19);
  sf_mex_destroy(&c66_lhs19);
  sf_mex_destroy(&c66_rhs20);
  sf_mex_destroy(&c66_lhs20);
  sf_mex_destroy(&c66_rhs21);
  sf_mex_destroy(&c66_lhs21);
  sf_mex_destroy(&c66_rhs22);
  sf_mex_destroy(&c66_lhs22);
  sf_mex_destroy(&c66_rhs23);
  sf_mex_destroy(&c66_lhs23);
}

static const mxArray *c66_emlrt_marshallOut(const char * c66_u)
{
  const mxArray *c66_y = NULL;
  c66_y = NULL;
  sf_mex_assign(&c66_y, sf_mex_create("y", c66_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c66_u)), false);
  return c66_y;
}

static const mxArray *c66_b_emlrt_marshallOut(const uint32_T c66_u)
{
  const mxArray *c66_y = NULL;
  c66_y = NULL;
  sf_mex_assign(&c66_y, sf_mex_create("y", &c66_u, 7, 0U, 0U, 0U, 0), false);
  return c66_y;
}

static const mxArray *c66_c_sf_marshallOut(void *chartInstanceVoid, void
  *c66_inData)
{
  const mxArray *c66_mxArrayOutData = NULL;
  int32_T c66_u;
  const mxArray *c66_y = NULL;
  SFc66_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc66_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c66_mxArrayOutData = NULL;
  c66_u = *(int32_T *)c66_inData;
  c66_y = NULL;
  sf_mex_assign(&c66_y, sf_mex_create("y", &c66_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c66_mxArrayOutData, c66_y, false);
  return c66_mxArrayOutData;
}

static int32_T c66_c_emlrt_marshallIn(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c66_u, const emlrtMsgIdentifier *c66_parentId)
{
  int32_T c66_y;
  int32_T c66_i6;
  (void)chartInstance;
  sf_mex_import(c66_parentId, sf_mex_dup(c66_u), &c66_i6, 1, 6, 0U, 0, 0U, 0);
  c66_y = c66_i6;
  sf_mex_destroy(&c66_u);
  return c66_y;
}

static void c66_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c66_mxArrayInData, const char_T *c66_varName, void *c66_outData)
{
  const mxArray *c66_b_sfEvent;
  const char_T *c66_identifier;
  emlrtMsgIdentifier c66_thisId;
  int32_T c66_y;
  SFc66_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc66_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c66_b_sfEvent = sf_mex_dup(c66_mxArrayInData);
  c66_identifier = c66_varName;
  c66_thisId.fIdentifier = c66_identifier;
  c66_thisId.fParent = NULL;
  c66_y = c66_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c66_b_sfEvent),
    &c66_thisId);
  sf_mex_destroy(&c66_b_sfEvent);
  *(int32_T *)c66_outData = c66_y;
  sf_mex_destroy(&c66_mxArrayInData);
}

static uint8_T c66_d_emlrt_marshallIn(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c66_b_is_active_c66_DDA2D_OSU3Dv2, const char_T
  *c66_identifier)
{
  uint8_T c66_y;
  emlrtMsgIdentifier c66_thisId;
  c66_thisId.fIdentifier = c66_identifier;
  c66_thisId.fParent = NULL;
  c66_y = c66_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c66_b_is_active_c66_DDA2D_OSU3Dv2), &c66_thisId);
  sf_mex_destroy(&c66_b_is_active_c66_DDA2D_OSU3Dv2);
  return c66_y;
}

static uint8_T c66_e_emlrt_marshallIn(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c66_u, const emlrtMsgIdentifier *c66_parentId)
{
  uint8_T c66_y;
  uint8_T c66_u0;
  (void)chartInstance;
  sf_mex_import(c66_parentId, sf_mex_dup(c66_u), &c66_u0, 1, 3, 0U, 0, 0U, 0);
  c66_y = c66_u0;
  sf_mex_destroy(&c66_u);
  return c66_y;
}

static void init_dsm_address_info(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc66_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c66_q = (real_T (*)[13])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c66_dq = (real_T (*)[13])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c66_stanceLeg = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c66_dy = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c66_dy_prev = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c66_ddy_prev = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c66_dx = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c66_dx_prev = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c66_ddx_prev = (real_T *)ssGetOutputPortSignal_wrapper
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

void sf_c66_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(4183888584U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2357310381U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(447437182U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1916670200U);
}

mxArray* sf_c66_DDA2D_OSU3Dv2_get_post_codegen_info(void);
mxArray *sf_c66_DDA2D_OSU3Dv2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("ChS2lKeWPNZAFRBy7eM4rG");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
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
      pr[0] = (double)(1);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c66_DDA2D_OSU3Dv2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c66_DDA2D_OSU3Dv2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c66_DDA2D_OSU3Dv2_jit_fallback_info(void)
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

mxArray *sf_c66_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c66_DDA2D_OSU3Dv2_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c66_DDA2D_OSU3Dv2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x7'type','srcId','name','auxInfo'{{M[1],M[15],T\"ddx_prev\",},{M[1],M[12],T\"ddy_prev\",},{M[1],M[13],T\"dx\",},{M[1],M[14],T\"dx_prev\",},{M[1],M[10],T\"dy\",},{M[1],M[11],T\"dy_prev\",},{M[8],M[0],T\"is_active_c66_DDA2D_OSU3Dv2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 7, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c66_DDA2D_OSU3Dv2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc66_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc66_DDA2D_OSU3Dv2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DDA2D_OSU3Dv2MachineNumber_,
           66,
           1,
           1,
           0,
           9,
           0,
           0,
           0,
           0,
           0,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"q");
          _SFD_SET_DATA_PROPS(1,1,1,0,"dq");
          _SFD_SET_DATA_PROPS(2,1,1,0,"stanceLeg");
          _SFD_SET_DATA_PROPS(3,2,0,1,"dy");
          _SFD_SET_DATA_PROPS(4,2,0,1,"dy_prev");
          _SFD_SET_DATA_PROPS(5,2,0,1,"ddy_prev");
          _SFD_SET_DATA_PROPS(6,2,0,1,"dx");
          _SFD_SET_DATA_PROPS(7,2,0,1,"dx_prev");
          _SFD_SET_DATA_PROPS(8,2,0,1,"ddx_prev");
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
        _SFD_CV_INIT_EML(0,1,1,2,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,4191);
        _SFD_CV_INIT_EML_IF(0,1,0,320,337,356,383);
        _SFD_CV_INIT_EML_IF(0,1,1,690,707,1055,1411);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,323,337,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,693,707,-1,0);

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c66_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 13;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c66_b_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c66_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c66_sf_marshallOut,(MexInFcnForType)c66_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c66_sf_marshallOut,(MexInFcnForType)c66_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c66_sf_marshallOut,(MexInFcnForType)c66_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c66_sf_marshallOut,(MexInFcnForType)c66_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c66_sf_marshallOut,(MexInFcnForType)c66_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c66_sf_marshallOut,(MexInFcnForType)c66_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c66_q);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c66_dq);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c66_stanceLeg);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c66_dy);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c66_dy_prev);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c66_ddy_prev);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c66_dx);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c66_dx_prev);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c66_ddx_prev);
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
  return "5HdTWuvJJSfrkpdXos1p9D";
}

static void sf_opaque_initialize_c66_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc66_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c66_DDA2D_OSU3Dv2((SFc66_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
  initialize_c66_DDA2D_OSU3Dv2((SFc66_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c66_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  enable_c66_DDA2D_OSU3Dv2((SFc66_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c66_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  disable_c66_DDA2D_OSU3Dv2((SFc66_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c66_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  sf_gateway_c66_DDA2D_OSU3Dv2((SFc66_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c66_DDA2D_OSU3Dv2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c66_DDA2D_OSU3Dv2((SFc66_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c66_DDA2D_OSU3Dv2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c66_DDA2D_OSU3Dv2((SFc66_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c66_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc66_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DDA2D_OSU3Dv2_optimization_info();
    }

    finalize_c66_DDA2D_OSU3Dv2((SFc66_DDA2D_OSU3Dv2InstanceStruct*)
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
  initSimStructsc66_DDA2D_OSU3Dv2((SFc66_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c66_DDA2D_OSU3Dv2(SimStruct *S)
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
    initialize_params_c66_DDA2D_OSU3Dv2((SFc66_DDA2D_OSU3Dv2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c66_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DDA2D_OSU3Dv2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      66);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,66,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,66,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,66);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,66,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,66,6);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=6; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,66);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1290587174U));
  ssSetChecksum1(S,(2621693992U));
  ssSetChecksum2(S,(2069801584U));
  ssSetChecksum3(S,(3603826246U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c66_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c66_DDA2D_OSU3Dv2(SimStruct *S)
{
  SFc66_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc66_DDA2D_OSU3Dv2InstanceStruct *)utMalloc(sizeof
    (SFc66_DDA2D_OSU3Dv2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc66_DDA2D_OSU3Dv2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c66_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c66_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c66_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c66_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c66_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c66_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c66_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c66_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c66_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlStart = mdlStart_c66_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c66_DDA2D_OSU3Dv2;
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

void c66_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c66_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c66_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c66_DDA2D_OSU3Dv2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c66_DDA2D_OSU3Dv2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
