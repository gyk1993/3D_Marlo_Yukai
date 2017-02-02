/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DDA2D_OSU3Dv2_sfun.h"
#include "c70_DDA2D_OSU3Dv2.h"
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
static const char * c70_debug_family_names[8] = { "nargin", "nargout", "isSim",
  "t", "dx_est", "ControlParams", "ForBackwardPrev", "ControlParams1" };

/* Function Declarations */
static void initialize_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initialize_params_c70_DDA2D_OSU3Dv2
  (SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void enable_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void disable_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c70_update_debugger_state_c70_DDA2D_OSU3Dv2
  (SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c70_DDA2D_OSU3Dv2
  (SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void set_sim_state_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_st);
static void finalize_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void sf_gateway_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void mdl_start_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initSimStructsc70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c70_machineNumber, uint32_T
  c70_chartNumber, uint32_T c70_instanceNumber);
static const mxArray *c70_sf_marshallOut(void *chartInstanceVoid, void
  *c70_inData);
static void c70_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_b_ControlParams1, const char_T
  *c70_identifier, c70_ControlParamsBus *c70_y);
static void c70_b_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_ControlParamsBus *c70_y);
static void c70_c_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_SupervisoryParamsBus *c70_y);
static real_T c70_d_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId);
static void c70_e_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[2]);
static void c70_f_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[6]);
static void c70_g_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[13]);
static void c70_h_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[5]);
static void c70_i_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[12]);
static void c70_j_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_DiscreteParamsBus *c70_y);
static void c70_k_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_OutputParamsBus *c70_y);
static void c70_l_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[78]);
static void c70_m_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[36]);
static void c70_n_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[2]);
static void c70_o_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_ThetaParamsBus *c70_y);
static void c70_p_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[13]);
static void c70_q_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[7]);
static void c70_r_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[30]);
static void c70_s_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_PhiParamsBus *c70_y);
static void c70_t_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[20]);
static void c70_u_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_FeedbackParamsBus *c70_y);
static c70_SaturationParamsBus c70_v_emlrt_marshallIn
  (SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance, const mxArray *c70_u, const
   emlrtMsgIdentifier *c70_parentId);
static void c70_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c70_mxArrayInData, const char_T *c70_varName, void *c70_outData);
static const mxArray *c70_b_sf_marshallOut(void *chartInstanceVoid, void
  *c70_inData);
static const mxArray *c70_c_sf_marshallOut(void *chartInstanceVoid, void
  *c70_inData);
static void c70_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c70_mxArrayInData, const char_T *c70_varName, void *c70_outData);
static const mxArray *c70_d_sf_marshallOut(void *chartInstanceVoid, void
  *c70_inData);
static int32_T c70_w_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId);
static void c70_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c70_mxArrayInData, const char_T *c70_varName, void *c70_outData);
static const mxArray *c70_ControlParams1_bus_io(void *chartInstanceVoid, void
  *c70_pData);
static uint8_T c70_x_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_b_is_active_c70_DDA2D_OSU3Dv2, const char_T
  *c70_identifier);
static uint8_T c70_y_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId);
static void init_dsm_address_info(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c70_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c70_is_active_c70_DDA2D_OSU3Dv2 = 0U;
}

static void initialize_params_c70_DDA2D_OSU3Dv2
  (SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c70_update_debugger_state_c70_DDA2D_OSU3Dv2
  (SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c70_DDA2D_OSU3Dv2
  (SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  const mxArray *c70_st;
  const mxArray *c70_y = NULL;
  const mxArray *c70_b_y = NULL;
  c70_SupervisoryParamsBus c70_u;
  int32_T c70_i0;
  int32_T c70_i1;
  int32_T c70_i2;
  int32_T c70_i3;
  int32_T c70_i4;
  int32_T c70_i5;
  int32_T c70_i6;
  int32_T c70_i7;
  int32_T c70_i8;
  int32_T c70_i9;
  int32_T c70_i10;
  int32_T c70_i11;
  int32_T c70_i12;
  int32_T c70_i13;
  const mxArray *c70_c_y = NULL;
  real_T c70_b_u;
  const mxArray *c70_d_y = NULL;
  real_T c70_c_u;
  const mxArray *c70_e_y = NULL;
  real_T c70_d_u;
  const mxArray *c70_f_y = NULL;
  real_T c70_e_u;
  const mxArray *c70_g_y = NULL;
  real_T c70_f_u;
  const mxArray *c70_h_y = NULL;
  real_T c70_g_u;
  const mxArray *c70_i_y = NULL;
  real_T c70_h_u;
  const mxArray *c70_j_y = NULL;
  real_T c70_i_u;
  const mxArray *c70_k_y = NULL;
  real_T c70_j_u;
  const mxArray *c70_l_y = NULL;
  real_T c70_k_u;
  const mxArray *c70_m_y = NULL;
  real_T c70_l_u;
  const mxArray *c70_n_y = NULL;
  int32_T c70_i14;
  real_T c70_m_u[2];
  const mxArray *c70_o_y = NULL;
  real_T c70_n_u;
  const mxArray *c70_p_y = NULL;
  real_T c70_o_u;
  const mxArray *c70_q_y = NULL;
  int32_T c70_i15;
  real_T c70_p_u[6];
  const mxArray *c70_r_y = NULL;
  int32_T c70_i16;
  real_T c70_q_u[13];
  const mxArray *c70_s_y = NULL;
  int32_T c70_i17;
  real_T c70_r_u[5];
  const mxArray *c70_t_y = NULL;
  real_T c70_s_u;
  const mxArray *c70_u_y = NULL;
  real_T c70_t_u;
  const mxArray *c70_v_y = NULL;
  real_T c70_u_u;
  const mxArray *c70_w_y = NULL;
  real_T c70_v_u;
  const mxArray *c70_x_y = NULL;
  int32_T c70_i18;
  real_T c70_w_u[6];
  const mxArray *c70_y_y = NULL;
  int32_T c70_i19;
  real_T c70_x_u[6];
  const mxArray *c70_ab_y = NULL;
  real_T c70_y_u;
  const mxArray *c70_bb_y = NULL;
  real_T c70_ab_u;
  const mxArray *c70_cb_y = NULL;
  real_T c70_bb_u;
  const mxArray *c70_db_y = NULL;
  real_T c70_cb_u;
  const mxArray *c70_eb_y = NULL;
  real_T c70_db_u;
  const mxArray *c70_fb_y = NULL;
  real_T c70_eb_u;
  const mxArray *c70_gb_y = NULL;
  real_T c70_fb_u;
  const mxArray *c70_hb_y = NULL;
  real_T c70_gb_u;
  const mxArray *c70_ib_y = NULL;
  real_T c70_hb_u;
  const mxArray *c70_jb_y = NULL;
  real_T c70_ib_u;
  const mxArray *c70_kb_y = NULL;
  real_T c70_jb_u;
  const mxArray *c70_lb_y = NULL;
  real_T c70_kb_u;
  const mxArray *c70_mb_y = NULL;
  real_T c70_lb_u;
  const mxArray *c70_nb_y = NULL;
  real_T c70_mb_u;
  const mxArray *c70_ob_y = NULL;
  real_T c70_nb_u;
  const mxArray *c70_pb_y = NULL;
  real_T c70_ob_u;
  const mxArray *c70_qb_y = NULL;
  real_T c70_pb_u;
  const mxArray *c70_rb_y = NULL;
  real_T c70_qb_u;
  const mxArray *c70_sb_y = NULL;
  real_T c70_rb_u;
  const mxArray *c70_tb_y = NULL;
  real_T c70_sb_u;
  const mxArray *c70_ub_y = NULL;
  real_T c70_tb_u;
  const mxArray *c70_vb_y = NULL;
  int32_T c70_i20;
  real_T c70_ub_u[6];
  const mxArray *c70_wb_y = NULL;
  int32_T c70_i21;
  real_T c70_vb_u[6];
  const mxArray *c70_xb_y = NULL;
  real_T c70_wb_u;
  const mxArray *c70_yb_y = NULL;
  int32_T c70_i22;
  real_T c70_xb_u[6];
  const mxArray *c70_ac_y = NULL;
  int32_T c70_i23;
  real_T c70_yb_u[6];
  const mxArray *c70_bc_y = NULL;
  real_T c70_ac_u;
  const mxArray *c70_cc_y = NULL;
  int32_T c70_i24;
  real_T c70_bc_u[12];
  const mxArray *c70_dc_y = NULL;
  real_T c70_cc_u;
  const mxArray *c70_ec_y = NULL;
  real_T c70_dc_u;
  const mxArray *c70_fc_y = NULL;
  real_T c70_ec_u;
  const mxArray *c70_gc_y = NULL;
  real_T c70_fc_u;
  const mxArray *c70_hc_y = NULL;
  real_T c70_gc_u;
  const mxArray *c70_ic_y = NULL;
  real_T c70_hc_u;
  const mxArray *c70_jc_y = NULL;
  real_T c70_ic_u;
  const mxArray *c70_kc_y = NULL;
  real_T c70_jc_u;
  const mxArray *c70_lc_y = NULL;
  real_T c70_kc_u;
  const mxArray *c70_mc_y = NULL;
  real_T c70_lc_u;
  const mxArray *c70_nc_y = NULL;
  real_T c70_mc_u;
  const mxArray *c70_oc_y = NULL;
  int32_T c70_i25;
  real_T c70_nc_u[6];
  const mxArray *c70_pc_y = NULL;
  c70_DiscreteParamsBus c70_oc_u;
  const mxArray *c70_qc_y = NULL;
  real_T c70_pc_u;
  const mxArray *c70_rc_y = NULL;
  real_T c70_qc_u;
  const mxArray *c70_sc_y = NULL;
  real_T c70_rc_u;
  const mxArray *c70_tc_y = NULL;
  real_T c70_sc_u;
  const mxArray *c70_uc_y = NULL;
  real_T c70_tc_u;
  const mxArray *c70_vc_y = NULL;
  real_T c70_uc_u;
  const mxArray *c70_wc_y = NULL;
  real_T c70_vc_u;
  const mxArray *c70_xc_y = NULL;
  real_T c70_wc_u;
  const mxArray *c70_yc_y = NULL;
  real_T c70_xc_u;
  const mxArray *c70_ad_y = NULL;
  real_T c70_yc_u;
  const mxArray *c70_bd_y = NULL;
  real_T c70_ad_u;
  const mxArray *c70_cd_y = NULL;
  int32_T c70_i26;
  int32_T c70_i27;
  int32_T c70_i28;
  c70_OutputParamsBus c70_bd_u;
  int32_T c70_i29;
  int32_T c70_i30;
  int32_T c70_i31;
  int32_T c70_i32;
  int32_T c70_i33;
  int32_T c70_i34;
  int32_T c70_i35;
  int32_T c70_i36;
  int32_T c70_i37;
  int32_T c70_i38;
  int32_T c70_i39;
  int32_T c70_i40;
  int32_T c70_i41;
  int32_T c70_i42;
  int32_T c70_i43;
  int32_T c70_i44;
  int32_T c70_i45;
  int32_T c70_i46;
  int32_T c70_i47;
  int32_T c70_i48;
  int32_T c70_i49;
  int32_T c70_i50;
  const mxArray *c70_dd_y = NULL;
  int32_T c70_i51;
  real_T c70_cd_u[78];
  const mxArray *c70_ed_y = NULL;
  int32_T c70_i52;
  real_T c70_dd_u[36];
  const mxArray *c70_fd_y = NULL;
  int32_T c70_i53;
  real_T c70_ed_u[2];
  const mxArray *c70_gd_y = NULL;
  c70_ThetaParamsBus c70_fd_u;
  const mxArray *c70_hd_y = NULL;
  real_T c70_gd_u;
  const mxArray *c70_id_y = NULL;
  real_T c70_hd_u;
  const mxArray *c70_jd_y = NULL;
  int32_T c70_i54;
  real_T c70_id_u[13];
  const mxArray *c70_kd_y = NULL;
  real_T c70_jd_u;
  const mxArray *c70_ld_y = NULL;
  int32_T c70_i55;
  real_T c70_kd_u[7];
  const mxArray *c70_md_y = NULL;
  real_T c70_ld_u;
  const mxArray *c70_nd_y = NULL;
  int32_T c70_i56;
  real_T c70_md_u[2];
  const mxArray *c70_od_y = NULL;
  real_T c70_nd_u;
  const mxArray *c70_pd_y = NULL;
  real_T c70_od_u;
  const mxArray *c70_qd_y = NULL;
  real_T c70_pd_u;
  const mxArray *c70_rd_y = NULL;
  int32_T c70_i57;
  real_T c70_qd_u[30];
  const mxArray *c70_sd_y = NULL;
  c70_PhiParamsBus c70_rd_u;
  const mxArray *c70_td_y = NULL;
  real_T c70_sd_u;
  const mxArray *c70_ud_y = NULL;
  int32_T c70_i58;
  real_T c70_td_u[13];
  const mxArray *c70_vd_y = NULL;
  int32_T c70_i59;
  real_T c70_ud_u[20];
  const mxArray *c70_wd_y = NULL;
  real_T c70_vd_u;
  const mxArray *c70_xd_y = NULL;
  int32_T c70_i60;
  real_T c70_wd_u[2];
  const mxArray *c70_yd_y = NULL;
  int32_T c70_i61;
  real_T c70_xd_u[30];
  const mxArray *c70_ae_y = NULL;
  int32_T c70_i62;
  real_T c70_yd_u[12];
  const mxArray *c70_be_y = NULL;
  int32_T c70_i63;
  real_T c70_ae_u[36];
  const mxArray *c70_ce_y = NULL;
  real_T c70_be_u;
  const mxArray *c70_de_y = NULL;
  real_T c70_ce_u;
  const mxArray *c70_ee_y = NULL;
  int32_T c70_i64;
  c70_FeedbackParamsBus c70_de_u;
  int32_T c70_i65;
  int32_T c70_i66;
  int32_T c70_i67;
  int32_T c70_i68;
  int32_T c70_i69;
  int32_T c70_i70;
  int32_T c70_i71;
  const mxArray *c70_fe_y = NULL;
  int32_T c70_i72;
  real_T c70_ee_u[6];
  const mxArray *c70_ge_y = NULL;
  int32_T c70_i73;
  real_T c70_fe_u[6];
  const mxArray *c70_he_y = NULL;
  int32_T c70_i74;
  real_T c70_ge_u[2];
  const mxArray *c70_ie_y = NULL;
  int32_T c70_i75;
  real_T c70_he_u[2];
  const mxArray *c70_je_y = NULL;
  real_T c70_ie_u;
  const mxArray *c70_ke_y = NULL;
  int32_T c70_i76;
  real_T c70_je_u[2];
  const mxArray *c70_le_y = NULL;
  int32_T c70_i77;
  real_T c70_ke_u[2];
  const mxArray *c70_me_y = NULL;
  real_T c70_le_u;
  const mxArray *c70_ne_y = NULL;
  real_T c70_me_u;
  const mxArray *c70_oe_y = NULL;
  real_T c70_ne_u;
  const mxArray *c70_pe_y = NULL;
  real_T c70_oe_u;
  const mxArray *c70_qe_y = NULL;
  real_T c70_pe_u;
  const mxArray *c70_re_y = NULL;
  real_T c70_qe_u;
  const mxArray *c70_se_y = NULL;
  real_T c70_re_u;
  const mxArray *c70_te_y = NULL;
  real_T c70_se_u;
  const mxArray *c70_ue_y = NULL;
  int32_T c70_i78;
  real_T c70_te_u[6];
  const mxArray *c70_ve_y = NULL;
  real_T c70_ue_u;
  const mxArray *c70_we_y = NULL;
  real_T c70_ve_u;
  const mxArray *c70_xe_y = NULL;
  real_T c70_we_u;
  const mxArray *c70_ye_y = NULL;
  real_T c70_xe_u;
  const mxArray *c70_af_y = NULL;
  real_T c70_ye_u;
  const mxArray *c70_bf_y = NULL;
  real_T c70_af_u;
  const mxArray *c70_cf_y = NULL;
  real_T c70_bf_u;
  const mxArray *c70_df_y = NULL;
  real_T c70_cf_u;
  const mxArray *c70_ef_y = NULL;
  real_T c70_df_u;
  const mxArray *c70_ff_y = NULL;
  int32_T c70_i79;
  real_T c70_ef_u[6];
  const mxArray *c70_gf_y = NULL;
  real_T c70_ff_u;
  const mxArray *c70_hf_y = NULL;
  c70_SaturationParamsBus c70_gf_u;
  int32_T c70_i80;
  const mxArray *c70_if_y = NULL;
  real_T c70_hf_u;
  const mxArray *c70_jf_y = NULL;
  int32_T c70_i81;
  real_T c70_if_u[2];
  const mxArray *c70_kf_y = NULL;
  real_T c70_jf_u;
  const mxArray *c70_lf_y = NULL;
  real_T c70_kf_u;
  const mxArray *c70_mf_y = NULL;
  real_T c70_lf_u;
  const mxArray *c70_nf_y = NULL;
  real_T c70_mf_u;
  const mxArray *c70_of_y = NULL;
  real_T c70_nf_u;
  const mxArray *c70_pf_y = NULL;
  uint8_T c70_hoistedGlobal;
  uint8_T c70_of_u;
  const mxArray *c70_qf_y = NULL;
  c70_st = NULL;
  c70_st = NULL;
  c70_y = NULL;
  sf_mex_assign(&c70_y, sf_mex_createcellmatrix(2, 1), false);
  c70_b_y = NULL;
  sf_mex_assign(&c70_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c70_u.EnableSwapOnKAAccel = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[0];
  c70_u.EnableSwapOnKASpring = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[8];
  c70_u.EnableBackwardSwap = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[16];
  c70_u.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[0])
    [24];
  c70_u.ImpactThresholdKASpringAbs = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[0])
    [32];
  c70_u.ImpactThresholdKASpringRel = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[0])
    [40];
  c70_u.SwapThresholdS = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[48];
  c70_u.AllowDoubleSupport = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[56];
  c70_u.UseGaitTransition = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[64];
  c70_u.NumTransitionSteps = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[72];
  c70_u.TransitionThresholdTorsoVel = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[0])
    [80];
  for (c70_i0 = 0; c70_i0 < 2; c70_i0++) {
    c70_u.KAInjection[c70_i0] = ((real_T *)&((char_T *)(c70_SupervisoryParamsBus
      *)&((char_T *)chartInstance->c70_ControlParams1)[0])[88])[c70_i0];
  }

  c70_u.MinDeltaThetaTransition = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[0])
    [104];
  c70_u.StartSecondGaitOnStep = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus
    *)&((char_T *)chartInstance->c70_ControlParams1)[0])[112];
  for (c70_i1 = 0; c70_i1 < 6; c70_i1++) {
    c70_u.VBLAParams[c70_i1] = ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
      &((char_T *)chartInstance->c70_ControlParams1)[0])[120])[c70_i1];
  }

  for (c70_i2 = 0; c70_i2 < 13; c70_i2++) {
    c70_u.BalanceParams[c70_i2] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
      [0])[168])[c70_i2];
  }

  for (c70_i3 = 0; c70_i3 < 5; c70_i3++) {
    c70_u.GaitTweaks[c70_i3] = ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
      &((char_T *)chartInstance->c70_ControlParams1)[0])[272])[c70_i3];
  }

  c70_u.TStepInitial = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[312];
  c70_u.TMaxUpdate = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[320];
  c70_u.RunMode = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[328];
  c70_u.UseAbsoluteSwingLA = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[336];
  for (c70_i4 = 0; c70_i4 < 6; c70_i4++) {
    c70_u.ErrorZeroFactor[c70_i4] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
      [0])[344])[c70_i4];
  }

  for (c70_i5 = 0; c70_i5 < 6; c70_i5++) {
    c70_u.ErrorVelZeroFactor[c70_i5] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
      [0])[392])[c70_i5];
  }

  c70_u.StanceLegInit = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[440];
  c70_u.ControllerModeInit = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[448];
  c70_u.UsePosingControl = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
                                        &((char_T *)
    chartInstance->c70_ControlParams1)[0])[456];
  c70_u.TPosing = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[464];
  c70_u.TorsoBackAngle = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[472];
  c70_u.TorsoBackOnStep = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[480];
  c70_u.EnergyControlGain = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[488];
  c70_u.EnergyControlPhi0 = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[496];
  c70_u.VelocityControlTorsoMax = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[0])
    [504];
  c70_u.VelocityControlTorsoMin = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[0])
    [512];
  c70_u.VelocityControlTorsoGain = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[0])
    [520];
  c70_u.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[0])
    [528];
  c70_u.MinDeltaTheta = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[536];
  c70_u.Theta0 = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[544];
  c70_u.KThetaPlus = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[552];
  c70_u.KThetaMinus = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[560];
  c70_u.RollPhaseVelocityThresh = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[0])
    [568];
  c70_u.RollPhaseSThresh = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
                                        &((char_T *)
    chartInstance->c70_ControlParams1)[0])[576];
  c70_u.MaxError = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[584];
  c70_u.MaxErrorVel = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[592];
  c70_u.MaxErrorCount = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[600];
  for (c70_i6 = 0; c70_i6 < 6; c70_i6++) {
    c70_u.K1MidStanceUpdate[c70_i6] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
      [0])[608])[c70_i6];
  }

  for (c70_i7 = 0; c70_i7 < 6; c70_i7++) {
    c70_u.K2MidStanceUpdate[c70_i7] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
      [0])[656])[c70_i7];
  }

  c70_u.EnableVelocityBasedUpdate = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[0])
    [704];
  for (c70_i8 = 0; c70_i8 < 6; c70_i8++) {
    c70_u.VelocityBasedUpdateK1[c70_i8] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
      [0])[712])[c70_i8];
  }

  for (c70_i9 = 0; c70_i9 < 6; c70_i9++) {
    c70_u.VelocityBasedUpdateK2[c70_i9] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
      [0])[760])[c70_i9];
  }

  c70_u.VelocityBasedUpdateDTheta0 = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[0])
    [808];
  c70_i10 = 0;
  for (c70_i11 = 0; c70_i11 < 2; c70_i11++) {
    for (c70_i12 = 0; c70_i12 < 6; c70_i12++) {
      c70_u.VelocityBasedUpdateLimits[c70_i12 + c70_i10] = ((real_T *)&((char_T *)
        (c70_SupervisoryParamsBus *)&((char_T *)
        chartInstance->c70_ControlParams1)[0])[816])[c70_i12 + c70_i10];
    }

    c70_i10 += 6;
  }

  c70_u.DesiredYawOffset = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
                                        &((char_T *)
    chartInstance->c70_ControlParams1)[0])[912];
  c70_u.dx_cmd = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[920];
  c70_u.ForBackward = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[928];
  c70_u.EnableFrictionID = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
                                        &((char_T *)
    chartInstance->c70_ControlParams1)[0])[936];
  c70_u.ResetFrictionPosing = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[944];
  c70_u.MoveLegIndex = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[952];
  c70_u.dy_cmd = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[960];
  c70_u.TauDelay = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[968];
  c70_u.TrackFrequency = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[976];
  c70_u.EnablePDControl = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[0])[984];
  c70_u.TorqueAmp = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T
    *)chartInstance->c70_ControlParams1)[0])[992];
  for (c70_i13 = 0; c70_i13 < 6; c70_i13++) {
    c70_u.hdPosing[c70_i13] = ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
      &((char_T *)chartInstance->c70_ControlParams1)[0])[1000])[c70_i13];
  }

  c70_c_y = NULL;
  sf_mex_assign(&c70_c_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c70_b_u = c70_u.EnableSwapOnKAAccel;
  c70_d_y = NULL;
  sf_mex_assign(&c70_d_y, sf_mex_create("y", &c70_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_d_y, "EnableSwapOnKAAccel", "EnableSwapOnKAAccel",
                  0);
  c70_c_u = c70_u.EnableSwapOnKASpring;
  c70_e_y = NULL;
  sf_mex_assign(&c70_e_y, sf_mex_create("y", &c70_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_e_y, "EnableSwapOnKASpring",
                  "EnableSwapOnKASpring", 0);
  c70_d_u = c70_u.EnableBackwardSwap;
  c70_f_y = NULL;
  sf_mex_assign(&c70_f_y, sf_mex_create("y", &c70_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_f_y, "EnableBackwardSwap", "EnableBackwardSwap",
                  0);
  c70_e_u = c70_u.ImpactThresholdKAAccel;
  c70_g_y = NULL;
  sf_mex_assign(&c70_g_y, sf_mex_create("y", &c70_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_g_y, "ImpactThresholdKAAccel",
                  "ImpactThresholdKAAccel", 0);
  c70_f_u = c70_u.ImpactThresholdKASpringAbs;
  c70_h_y = NULL;
  sf_mex_assign(&c70_h_y, sf_mex_create("y", &c70_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_h_y, "ImpactThresholdKASpringAbs",
                  "ImpactThresholdKASpringAbs", 0);
  c70_g_u = c70_u.ImpactThresholdKASpringRel;
  c70_i_y = NULL;
  sf_mex_assign(&c70_i_y, sf_mex_create("y", &c70_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_i_y, "ImpactThresholdKASpringRel",
                  "ImpactThresholdKASpringRel", 0);
  c70_h_u = c70_u.SwapThresholdS;
  c70_j_y = NULL;
  sf_mex_assign(&c70_j_y, sf_mex_create("y", &c70_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_j_y, "SwapThresholdS", "SwapThresholdS", 0);
  c70_i_u = c70_u.AllowDoubleSupport;
  c70_k_y = NULL;
  sf_mex_assign(&c70_k_y, sf_mex_create("y", &c70_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_k_y, "AllowDoubleSupport", "AllowDoubleSupport",
                  0);
  c70_j_u = c70_u.UseGaitTransition;
  c70_l_y = NULL;
  sf_mex_assign(&c70_l_y, sf_mex_create("y", &c70_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_l_y, "UseGaitTransition", "UseGaitTransition", 0);
  c70_k_u = c70_u.NumTransitionSteps;
  c70_m_y = NULL;
  sf_mex_assign(&c70_m_y, sf_mex_create("y", &c70_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_m_y, "NumTransitionSteps", "NumTransitionSteps",
                  0);
  c70_l_u = c70_u.TransitionThresholdTorsoVel;
  c70_n_y = NULL;
  sf_mex_assign(&c70_n_y, sf_mex_create("y", &c70_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_n_y, "TransitionThresholdTorsoVel",
                  "TransitionThresholdTorsoVel", 0);
  for (c70_i14 = 0; c70_i14 < 2; c70_i14++) {
    c70_m_u[c70_i14] = c70_u.KAInjection[c70_i14];
  }

  c70_o_y = NULL;
  sf_mex_assign(&c70_o_y, sf_mex_create("y", c70_m_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c70_c_y, c70_o_y, "KAInjection", "KAInjection", 0);
  c70_n_u = c70_u.MinDeltaThetaTransition;
  c70_p_y = NULL;
  sf_mex_assign(&c70_p_y, sf_mex_create("y", &c70_n_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_p_y, "MinDeltaThetaTransition",
                  "MinDeltaThetaTransition", 0);
  c70_o_u = c70_u.StartSecondGaitOnStep;
  c70_q_y = NULL;
  sf_mex_assign(&c70_q_y, sf_mex_create("y", &c70_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_q_y, "StartSecondGaitOnStep",
                  "StartSecondGaitOnStep", 0);
  for (c70_i15 = 0; c70_i15 < 6; c70_i15++) {
    c70_p_u[c70_i15] = c70_u.VBLAParams[c70_i15];
  }

  c70_r_y = NULL;
  sf_mex_assign(&c70_r_y, sf_mex_create("y", c70_p_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_c_y, c70_r_y, "VBLAParams", "VBLAParams", 0);
  for (c70_i16 = 0; c70_i16 < 13; c70_i16++) {
    c70_q_u[c70_i16] = c70_u.BalanceParams[c70_i16];
  }

  c70_s_y = NULL;
  sf_mex_assign(&c70_s_y, sf_mex_create("y", c70_q_u, 0, 0U, 1U, 0U, 1, 13),
                false);
  sf_mex_addfield(c70_c_y, c70_s_y, "BalanceParams", "BalanceParams", 0);
  for (c70_i17 = 0; c70_i17 < 5; c70_i17++) {
    c70_r_u[c70_i17] = c70_u.GaitTweaks[c70_i17];
  }

  c70_t_y = NULL;
  sf_mex_assign(&c70_t_y, sf_mex_create("y", c70_r_u, 0, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_addfield(c70_c_y, c70_t_y, "GaitTweaks", "GaitTweaks", 0);
  c70_s_u = c70_u.TStepInitial;
  c70_u_y = NULL;
  sf_mex_assign(&c70_u_y, sf_mex_create("y", &c70_s_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_u_y, "TStepInitial", "TStepInitial", 0);
  c70_t_u = c70_u.TMaxUpdate;
  c70_v_y = NULL;
  sf_mex_assign(&c70_v_y, sf_mex_create("y", &c70_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_v_y, "TMaxUpdate", "TMaxUpdate", 0);
  c70_u_u = c70_u.RunMode;
  c70_w_y = NULL;
  sf_mex_assign(&c70_w_y, sf_mex_create("y", &c70_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_w_y, "RunMode", "RunMode", 0);
  c70_v_u = c70_u.UseAbsoluteSwingLA;
  c70_x_y = NULL;
  sf_mex_assign(&c70_x_y, sf_mex_create("y", &c70_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_x_y, "UseAbsoluteSwingLA", "UseAbsoluteSwingLA",
                  0);
  for (c70_i18 = 0; c70_i18 < 6; c70_i18++) {
    c70_w_u[c70_i18] = c70_u.ErrorZeroFactor[c70_i18];
  }

  c70_y_y = NULL;
  sf_mex_assign(&c70_y_y, sf_mex_create("y", c70_w_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_c_y, c70_y_y, "ErrorZeroFactor", "ErrorZeroFactor", 0);
  for (c70_i19 = 0; c70_i19 < 6; c70_i19++) {
    c70_x_u[c70_i19] = c70_u.ErrorVelZeroFactor[c70_i19];
  }

  c70_ab_y = NULL;
  sf_mex_assign(&c70_ab_y, sf_mex_create("y", c70_x_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_c_y, c70_ab_y, "ErrorVelZeroFactor", "ErrorVelZeroFactor",
                  0);
  c70_y_u = c70_u.StanceLegInit;
  c70_bb_y = NULL;
  sf_mex_assign(&c70_bb_y, sf_mex_create("y", &c70_y_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_c_y, c70_bb_y, "StanceLegInit", "StanceLegInit", 0);
  c70_ab_u = c70_u.ControllerModeInit;
  c70_cb_y = NULL;
  sf_mex_assign(&c70_cb_y, sf_mex_create("y", &c70_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_cb_y, "ControllerModeInit", "ControllerModeInit",
                  0);
  c70_bb_u = c70_u.UsePosingControl;
  c70_db_y = NULL;
  sf_mex_assign(&c70_db_y, sf_mex_create("y", &c70_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_db_y, "UsePosingControl", "UsePosingControl", 0);
  c70_cb_u = c70_u.TPosing;
  c70_eb_y = NULL;
  sf_mex_assign(&c70_eb_y, sf_mex_create("y", &c70_cb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_eb_y, "TPosing", "TPosing", 0);
  c70_db_u = c70_u.TorsoBackAngle;
  c70_fb_y = NULL;
  sf_mex_assign(&c70_fb_y, sf_mex_create("y", &c70_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_fb_y, "TorsoBackAngle", "TorsoBackAngle", 0);
  c70_eb_u = c70_u.TorsoBackOnStep;
  c70_gb_y = NULL;
  sf_mex_assign(&c70_gb_y, sf_mex_create("y", &c70_eb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_gb_y, "TorsoBackOnStep", "TorsoBackOnStep", 0);
  c70_fb_u = c70_u.EnergyControlGain;
  c70_hb_y = NULL;
  sf_mex_assign(&c70_hb_y, sf_mex_create("y", &c70_fb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_hb_y, "EnergyControlGain", "EnergyControlGain", 0);
  c70_gb_u = c70_u.EnergyControlPhi0;
  c70_ib_y = NULL;
  sf_mex_assign(&c70_ib_y, sf_mex_create("y", &c70_gb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_ib_y, "EnergyControlPhi0", "EnergyControlPhi0", 0);
  c70_hb_u = c70_u.VelocityControlTorsoMax;
  c70_jb_y = NULL;
  sf_mex_assign(&c70_jb_y, sf_mex_create("y", &c70_hb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_jb_y, "VelocityControlTorsoMax",
                  "VelocityControlTorsoMax", 0);
  c70_ib_u = c70_u.VelocityControlTorsoMin;
  c70_kb_y = NULL;
  sf_mex_assign(&c70_kb_y, sf_mex_create("y", &c70_ib_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_kb_y, "VelocityControlTorsoMin",
                  "VelocityControlTorsoMin", 0);
  c70_jb_u = c70_u.VelocityControlTorsoGain;
  c70_lb_y = NULL;
  sf_mex_assign(&c70_lb_y, sf_mex_create("y", &c70_jb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_lb_y, "VelocityControlTorsoGain",
                  "VelocityControlTorsoGain", 0);
  c70_kb_u = c70_u.VelocityControlTorsoV0;
  c70_mb_y = NULL;
  sf_mex_assign(&c70_mb_y, sf_mex_create("y", &c70_kb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_mb_y, "VelocityControlTorsoV0",
                  "VelocityControlTorsoV0", 0);
  c70_lb_u = c70_u.MinDeltaTheta;
  c70_nb_y = NULL;
  sf_mex_assign(&c70_nb_y, sf_mex_create("y", &c70_lb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_nb_y, "MinDeltaTheta", "MinDeltaTheta", 0);
  c70_mb_u = c70_u.Theta0;
  c70_ob_y = NULL;
  sf_mex_assign(&c70_ob_y, sf_mex_create("y", &c70_mb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_ob_y, "Theta0", "Theta0", 0);
  c70_nb_u = c70_u.KThetaPlus;
  c70_pb_y = NULL;
  sf_mex_assign(&c70_pb_y, sf_mex_create("y", &c70_nb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_pb_y, "KThetaPlus", "KThetaPlus", 0);
  c70_ob_u = c70_u.KThetaMinus;
  c70_qb_y = NULL;
  sf_mex_assign(&c70_qb_y, sf_mex_create("y", &c70_ob_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_qb_y, "KThetaMinus", "KThetaMinus", 0);
  c70_pb_u = c70_u.RollPhaseVelocityThresh;
  c70_rb_y = NULL;
  sf_mex_assign(&c70_rb_y, sf_mex_create("y", &c70_pb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_rb_y, "RollPhaseVelocityThresh",
                  "RollPhaseVelocityThresh", 0);
  c70_qb_u = c70_u.RollPhaseSThresh;
  c70_sb_y = NULL;
  sf_mex_assign(&c70_sb_y, sf_mex_create("y", &c70_qb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_sb_y, "RollPhaseSThresh", "RollPhaseSThresh", 0);
  c70_rb_u = c70_u.MaxError;
  c70_tb_y = NULL;
  sf_mex_assign(&c70_tb_y, sf_mex_create("y", &c70_rb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_tb_y, "MaxError", "MaxError", 0);
  c70_sb_u = c70_u.MaxErrorVel;
  c70_ub_y = NULL;
  sf_mex_assign(&c70_ub_y, sf_mex_create("y", &c70_sb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_ub_y, "MaxErrorVel", "MaxErrorVel", 0);
  c70_tb_u = c70_u.MaxErrorCount;
  c70_vb_y = NULL;
  sf_mex_assign(&c70_vb_y, sf_mex_create("y", &c70_tb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_vb_y, "MaxErrorCount", "MaxErrorCount", 0);
  for (c70_i20 = 0; c70_i20 < 6; c70_i20++) {
    c70_ub_u[c70_i20] = c70_u.K1MidStanceUpdate[c70_i20];
  }

  c70_wb_y = NULL;
  sf_mex_assign(&c70_wb_y, sf_mex_create("y", c70_ub_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_c_y, c70_wb_y, "K1MidStanceUpdate", "K1MidStanceUpdate", 0);
  for (c70_i21 = 0; c70_i21 < 6; c70_i21++) {
    c70_vb_u[c70_i21] = c70_u.K2MidStanceUpdate[c70_i21];
  }

  c70_xb_y = NULL;
  sf_mex_assign(&c70_xb_y, sf_mex_create("y", c70_vb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_c_y, c70_xb_y, "K2MidStanceUpdate", "K2MidStanceUpdate", 0);
  c70_wb_u = c70_u.EnableVelocityBasedUpdate;
  c70_yb_y = NULL;
  sf_mex_assign(&c70_yb_y, sf_mex_create("y", &c70_wb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_yb_y, "EnableVelocityBasedUpdate",
                  "EnableVelocityBasedUpdate", 0);
  for (c70_i22 = 0; c70_i22 < 6; c70_i22++) {
    c70_xb_u[c70_i22] = c70_u.VelocityBasedUpdateK1[c70_i22];
  }

  c70_ac_y = NULL;
  sf_mex_assign(&c70_ac_y, sf_mex_create("y", c70_xb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_c_y, c70_ac_y, "VelocityBasedUpdateK1",
                  "VelocityBasedUpdateK1", 0);
  for (c70_i23 = 0; c70_i23 < 6; c70_i23++) {
    c70_yb_u[c70_i23] = c70_u.VelocityBasedUpdateK2[c70_i23];
  }

  c70_bc_y = NULL;
  sf_mex_assign(&c70_bc_y, sf_mex_create("y", c70_yb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_c_y, c70_bc_y, "VelocityBasedUpdateK2",
                  "VelocityBasedUpdateK2", 0);
  c70_ac_u = c70_u.VelocityBasedUpdateDTheta0;
  c70_cc_y = NULL;
  sf_mex_assign(&c70_cc_y, sf_mex_create("y", &c70_ac_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_cc_y, "VelocityBasedUpdateDTheta0",
                  "VelocityBasedUpdateDTheta0", 0);
  for (c70_i24 = 0; c70_i24 < 12; c70_i24++) {
    c70_bc_u[c70_i24] = c70_u.VelocityBasedUpdateLimits[c70_i24];
  }

  c70_dc_y = NULL;
  sf_mex_assign(&c70_dc_y, sf_mex_create("y", c70_bc_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c70_c_y, c70_dc_y, "VelocityBasedUpdateLimits",
                  "VelocityBasedUpdateLimits", 0);
  c70_cc_u = c70_u.DesiredYawOffset;
  c70_ec_y = NULL;
  sf_mex_assign(&c70_ec_y, sf_mex_create("y", &c70_cc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_ec_y, "DesiredYawOffset", "DesiredYawOffset", 0);
  c70_dc_u = c70_u.dx_cmd;
  c70_fc_y = NULL;
  sf_mex_assign(&c70_fc_y, sf_mex_create("y", &c70_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_fc_y, "dx_cmd", "dx_cmd", 0);
  c70_ec_u = c70_u.ForBackward;
  c70_gc_y = NULL;
  sf_mex_assign(&c70_gc_y, sf_mex_create("y", &c70_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_gc_y, "ForBackward", "ForBackward", 0);
  c70_fc_u = c70_u.EnableFrictionID;
  c70_hc_y = NULL;
  sf_mex_assign(&c70_hc_y, sf_mex_create("y", &c70_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_hc_y, "EnableFrictionID", "EnableFrictionID", 0);
  c70_gc_u = c70_u.ResetFrictionPosing;
  c70_ic_y = NULL;
  sf_mex_assign(&c70_ic_y, sf_mex_create("y", &c70_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_ic_y, "ResetFrictionPosing",
                  "ResetFrictionPosing", 0);
  c70_hc_u = c70_u.MoveLegIndex;
  c70_jc_y = NULL;
  sf_mex_assign(&c70_jc_y, sf_mex_create("y", &c70_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_jc_y, "MoveLegIndex", "MoveLegIndex", 0);
  c70_ic_u = c70_u.dy_cmd;
  c70_kc_y = NULL;
  sf_mex_assign(&c70_kc_y, sf_mex_create("y", &c70_ic_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_kc_y, "dy_cmd", "dy_cmd", 0);
  c70_jc_u = c70_u.TauDelay;
  c70_lc_y = NULL;
  sf_mex_assign(&c70_lc_y, sf_mex_create("y", &c70_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_lc_y, "TauDelay", "TauDelay", 0);
  c70_kc_u = c70_u.TrackFrequency;
  c70_mc_y = NULL;
  sf_mex_assign(&c70_mc_y, sf_mex_create("y", &c70_kc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_mc_y, "TrackFrequency", "TrackFrequency", 0);
  c70_lc_u = c70_u.EnablePDControl;
  c70_nc_y = NULL;
  sf_mex_assign(&c70_nc_y, sf_mex_create("y", &c70_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_nc_y, "EnablePDControl", "EnablePDControl", 0);
  c70_mc_u = c70_u.TorqueAmp;
  c70_oc_y = NULL;
  sf_mex_assign(&c70_oc_y, sf_mex_create("y", &c70_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_c_y, c70_oc_y, "TorqueAmp", "TorqueAmp", 0);
  for (c70_i25 = 0; c70_i25 < 6; c70_i25++) {
    c70_nc_u[c70_i25] = c70_u.hdPosing[c70_i25];
  }

  c70_pc_y = NULL;
  sf_mex_assign(&c70_pc_y, sf_mex_create("y", c70_nc_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_c_y, c70_pc_y, "hdPosing", "hdPosing", 0);
  sf_mex_addfield(c70_b_y, c70_c_y, "Supervisory", "Supervisory", 0);
  c70_oc_u.TLastUpdate = *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1048])[0];
  c70_oc_u.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[1048])
    [8];
  c70_oc_u.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[1048])
    [16];
  c70_oc_u.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[1048])
    [24];
  c70_oc_u.VelocityControlHipDistPrev = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[1048])
    [32];
  c70_oc_u.VirtualSpringMode = *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1048])[40];
  c70_oc_u.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[1048])
    [48];
  c70_oc_u.VirtualSpringDamping = *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1048])[56];
  c70_oc_u.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[1048])
    [64];
  c70_oc_u.VirtualSpringModRate = *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1048])[72];
  c70_oc_u.VirtualSpringRestPos = *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1048])[80];
  c70_qc_y = NULL;
  sf_mex_assign(&c70_qc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c70_pc_u = c70_oc_u.TLastUpdate;
  c70_rc_y = NULL;
  sf_mex_assign(&c70_rc_y, sf_mex_create("y", &c70_pc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_qc_y, c70_rc_y, "TLastUpdate", "TLastUpdate", 0);
  c70_qc_u = c70_oc_u.VelocityControlLADelta;
  c70_sc_y = NULL;
  sf_mex_assign(&c70_sc_y, sf_mex_create("y", &c70_qc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_qc_y, c70_sc_y, "VelocityControlLADelta",
                  "VelocityControlLADelta", 0);
  c70_rc_u = c70_oc_u.VelocityControlTorsoDelta;
  c70_tc_y = NULL;
  sf_mex_assign(&c70_tc_y, sf_mex_create("y", &c70_rc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_qc_y, c70_tc_y, "VelocityControlTorsoDelta",
                  "VelocityControlTorsoDelta", 0);
  c70_sc_u = c70_oc_u.VelocityControlHipDistCur;
  c70_uc_y = NULL;
  sf_mex_assign(&c70_uc_y, sf_mex_create("y", &c70_sc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_qc_y, c70_uc_y, "VelocityControlHipDistCur",
                  "VelocityControlHipDistCur", 0);
  c70_tc_u = c70_oc_u.VelocityControlHipDistPrev;
  c70_vc_y = NULL;
  sf_mex_assign(&c70_vc_y, sf_mex_create("y", &c70_tc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_qc_y, c70_vc_y, "VelocityControlHipDistPrev",
                  "VelocityControlHipDistPrev", 0);
  c70_uc_u = c70_oc_u.VirtualSpringMode;
  c70_wc_y = NULL;
  sf_mex_assign(&c70_wc_y, sf_mex_create("y", &c70_uc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_qc_y, c70_wc_y, "VirtualSpringMode", "VirtualSpringMode",
                  0);
  c70_vc_u = c70_oc_u.VirtualSpringStiffness;
  c70_xc_y = NULL;
  sf_mex_assign(&c70_xc_y, sf_mex_create("y", &c70_vc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_qc_y, c70_xc_y, "VirtualSpringStiffness",
                  "VirtualSpringStiffness", 0);
  c70_wc_u = c70_oc_u.VirtualSpringDamping;
  c70_yc_y = NULL;
  sf_mex_assign(&c70_yc_y, sf_mex_create("y", &c70_wc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_qc_y, c70_yc_y, "VirtualSpringDamping",
                  "VirtualSpringDamping", 0);
  c70_xc_u = c70_oc_u.VirtualSpringModAmplitude;
  c70_ad_y = NULL;
  sf_mex_assign(&c70_ad_y, sf_mex_create("y", &c70_xc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_qc_y, c70_ad_y, "VirtualSpringModAmplitude",
                  "VirtualSpringModAmplitude", 0);
  c70_yc_u = c70_oc_u.VirtualSpringModRate;
  c70_bd_y = NULL;
  sf_mex_assign(&c70_bd_y, sf_mex_create("y", &c70_yc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_qc_y, c70_bd_y, "VirtualSpringModRate",
                  "VirtualSpringModRate", 0);
  c70_ad_u = c70_oc_u.VirtualSpringRestPos;
  c70_cd_y = NULL;
  sf_mex_assign(&c70_cd_y, sf_mex_create("y", &c70_ad_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_qc_y, c70_cd_y, "VirtualSpringRestPos",
                  "VirtualSpringRestPos", 0);
  sf_mex_addfield(c70_b_y, c70_qc_y, "Discrete", "Discrete", 0);
  c70_i26 = 0;
  for (c70_i27 = 0; c70_i27 < 13; c70_i27++) {
    for (c70_i28 = 0; c70_i28 < 6; c70_i28++) {
      c70_bd_u.H0[c70_i28 + c70_i26] = ((real_T *)&((char_T *)
        (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
        [1136])[0])[c70_i28 + c70_i26];
    }

    c70_i26 += 6;
  }

  c70_i29 = 0;
  for (c70_i30 = 0; c70_i30 < 6; c70_i30++) {
    for (c70_i31 = 0; c70_i31 < 6; c70_i31++) {
      c70_bd_u.HAlpha[c70_i31 + c70_i29] = ((real_T *)&((char_T *)
        (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
        [1136])[624])[c70_i31 + c70_i29];
    }

    c70_i29 += 6;
  }

  for (c70_i32 = 0; c70_i32 < 2; c70_i32++) {
    c70_bd_u.ThetaLimits[c70_i32] = ((real_T *)&((char_T *)(c70_OutputParamsBus *)
      &((char_T *)chartInstance->c70_ControlParams1)[1136])[912])[c70_i32];
  }

  c70_bd_u.Theta.c0 = *(real_T *)&((char_T *)(c70_ThetaParamsBus *)&((char_T *)
    (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[1136])
    [928])[0];
  c70_bd_u.Theta.ct = *(real_T *)&((char_T *)(c70_ThetaParamsBus *)&((char_T *)
    (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[1136])
    [928])[8];
  for (c70_i33 = 0; c70_i33 < 13; c70_i33++) {
    c70_bd_u.Theta.cq[c70_i33] = ((real_T *)&((char_T *)(c70_ThetaParamsBus *)
                                   &((char_T *)(c70_OutputParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams1)[1136])[928])[16])[c70_i33];
  }

  c70_bd_u.Theta.t0 = *(real_T *)&((char_T *)(c70_ThetaParamsBus *)&((char_T *)
    (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[1136])
    [928])[120];
  for (c70_i34 = 0; c70_i34 < 7; c70_i34++) {
    c70_bd_u.Theta.cz[c70_i34] = ((real_T *)&((char_T *)(c70_ThetaParamsBus *)
                                   &((char_T *)(c70_OutputParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams1)[1136])[928])[128])[c70_i34];
  }

  c70_bd_u.SaturateS = *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[1112];
  for (c70_i35 = 0; c70_i35 < 2; c70_i35++) {
    c70_bd_u.SLimits[c70_i35] = ((real_T *)&((char_T *)(c70_OutputParamsBus *)
                                  &((char_T *)chartInstance->c70_ControlParams1)
      [1136])[1120])[c70_i35];
  }

  c70_bd_u.EnforceIncreasingS = *(real_T *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1136])[1136];
  c70_bd_u.UseCorrection = *(real_T *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1136])[1144];
  c70_bd_u.SMaxCorrection = *(real_T *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1136])[1152];
  c70_i36 = 0;
  for (c70_i37 = 0; c70_i37 < 5; c70_i37++) {
    for (c70_i38 = 0; c70_i38 < 6; c70_i38++) {
      c70_bd_u.HAlphaCorrection[c70_i38 + c70_i36] = ((real_T *)&((char_T *)
        (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
        [1136])[1160])[c70_i38 + c70_i36];
    }

    c70_i36 += 6;
  }

  c70_bd_u.Phi.c0 = *(real_T *)&((char_T *)(c70_PhiParamsBus *)&((char_T *)
    (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[1136])
    [1400])[0];
  for (c70_i39 = 0; c70_i39 < 13; c70_i39++) {
    c70_bd_u.Phi.cq[c70_i39] = ((real_T *)&((char_T *)(c70_PhiParamsBus *)
      &((char_T *)(c70_OutputParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams1)[1136])[1400])[8])[c70_i39];
  }

  for (c70_i40 = 0; c70_i40 < 20; c70_i40++) {
    c70_bd_u.PhiAlpha[c70_i40] = ((real_T *)&((char_T *)(c70_OutputParamsBus *)
                                   &((char_T *)chartInstance->c70_ControlParams1)
      [1136])[1512])[c70_i40];
  }

  c70_bd_u.SaturateR = *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[1672];
  for (c70_i41 = 0; c70_i41 < 2; c70_i41++) {
    c70_bd_u.RLimits[c70_i41] = ((real_T *)&((char_T *)(c70_OutputParamsBus *)
                                  &((char_T *)chartInstance->c70_ControlParams1)
      [1136])[1680])[c70_i41];
  }

  c70_i42 = 0;
  for (c70_i43 = 0; c70_i43 < 5; c70_i43++) {
    for (c70_i44 = 0; c70_i44 < 6; c70_i44++) {
      c70_bd_u.HBarAlpha[c70_i44 + c70_i42] = ((real_T *)&((char_T *)
        (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
        [1136])[1696])[c70_i44 + c70_i42];
    }

    c70_i42 += 6;
  }

  c70_i45 = 0;
  for (c70_i46 = 0; c70_i46 < 2; c70_i46++) {
    for (c70_i47 = 0; c70_i47 < 6; c70_i47++) {
      c70_bd_u.HBarLimits[c70_i47 + c70_i45] = ((real_T *)&((char_T *)
        (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
        [1136])[1936])[c70_i47 + c70_i45];
    }

    c70_i45 += 6;
  }

  c70_i48 = 0;
  for (c70_i49 = 0; c70_i49 < 6; c70_i49++) {
    for (c70_i50 = 0; c70_i50 < 6; c70_i50++) {
      c70_bd_u.HAlphaStar[c70_i50 + c70_i48] = ((real_T *)&((char_T *)
        (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
        [1136])[2032])[c70_i50 + c70_i48];
    }

    c70_i48 += 6;
  }

  c70_bd_u.YawLimit = *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[2320];
  c70_bd_u.test = *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[2328];
  c70_dd_y = NULL;
  sf_mex_assign(&c70_dd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c70_i51 = 0; c70_i51 < 78; c70_i51++) {
    c70_cd_u[c70_i51] = c70_bd_u.H0[c70_i51];
  }

  c70_ed_y = NULL;
  sf_mex_assign(&c70_ed_y, sf_mex_create("y", c70_cd_u, 0, 0U, 1U, 0U, 2, 6, 13),
                false);
  sf_mex_addfield(c70_dd_y, c70_ed_y, "H0", "H0", 0);
  for (c70_i52 = 0; c70_i52 < 36; c70_i52++) {
    c70_dd_u[c70_i52] = c70_bd_u.HAlpha[c70_i52];
  }

  c70_fd_y = NULL;
  sf_mex_assign(&c70_fd_y, sf_mex_create("y", c70_dd_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c70_dd_y, c70_fd_y, "HAlpha", "HAlpha", 0);
  for (c70_i53 = 0; c70_i53 < 2; c70_i53++) {
    c70_ed_u[c70_i53] = c70_bd_u.ThetaLimits[c70_i53];
  }

  c70_gd_y = NULL;
  sf_mex_assign(&c70_gd_y, sf_mex_create("y", c70_ed_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c70_dd_y, c70_gd_y, "ThetaLimits", "ThetaLimits", 0);
  c70_fd_u = c70_bd_u.Theta;
  c70_hd_y = NULL;
  sf_mex_assign(&c70_hd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c70_gd_u = c70_fd_u.c0;
  c70_id_y = NULL;
  sf_mex_assign(&c70_id_y, sf_mex_create("y", &c70_gd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_hd_y, c70_id_y, "c0", "c0", 0);
  c70_hd_u = c70_fd_u.ct;
  c70_jd_y = NULL;
  sf_mex_assign(&c70_jd_y, sf_mex_create("y", &c70_hd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_hd_y, c70_jd_y, "ct", "ct", 0);
  for (c70_i54 = 0; c70_i54 < 13; c70_i54++) {
    c70_id_u[c70_i54] = c70_fd_u.cq[c70_i54];
  }

  c70_kd_y = NULL;
  sf_mex_assign(&c70_kd_y, sf_mex_create("y", c70_id_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c70_hd_y, c70_kd_y, "cq", "cq", 0);
  c70_jd_u = c70_fd_u.t0;
  c70_ld_y = NULL;
  sf_mex_assign(&c70_ld_y, sf_mex_create("y", &c70_jd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_hd_y, c70_ld_y, "t0", "t0", 0);
  for (c70_i55 = 0; c70_i55 < 7; c70_i55++) {
    c70_kd_u[c70_i55] = c70_fd_u.cz[c70_i55];
  }

  c70_md_y = NULL;
  sf_mex_assign(&c70_md_y, sf_mex_create("y", c70_kd_u, 0, 0U, 1U, 0U, 2, 1, 7),
                false);
  sf_mex_addfield(c70_hd_y, c70_md_y, "cz", "cz", 0);
  sf_mex_addfield(c70_dd_y, c70_hd_y, "Theta", "Theta", 0);
  c70_ld_u = c70_bd_u.SaturateS;
  c70_nd_y = NULL;
  sf_mex_assign(&c70_nd_y, sf_mex_create("y", &c70_ld_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_dd_y, c70_nd_y, "SaturateS", "SaturateS", 0);
  for (c70_i56 = 0; c70_i56 < 2; c70_i56++) {
    c70_md_u[c70_i56] = c70_bd_u.SLimits[c70_i56];
  }

  c70_od_y = NULL;
  sf_mex_assign(&c70_od_y, sf_mex_create("y", c70_md_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c70_dd_y, c70_od_y, "SLimits", "SLimits", 0);
  c70_nd_u = c70_bd_u.EnforceIncreasingS;
  c70_pd_y = NULL;
  sf_mex_assign(&c70_pd_y, sf_mex_create("y", &c70_nd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_dd_y, c70_pd_y, "EnforceIncreasingS", "EnforceIncreasingS",
                  0);
  c70_od_u = c70_bd_u.UseCorrection;
  c70_qd_y = NULL;
  sf_mex_assign(&c70_qd_y, sf_mex_create("y", &c70_od_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_dd_y, c70_qd_y, "UseCorrection", "UseCorrection", 0);
  c70_pd_u = c70_bd_u.SMaxCorrection;
  c70_rd_y = NULL;
  sf_mex_assign(&c70_rd_y, sf_mex_create("y", &c70_pd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_dd_y, c70_rd_y, "SMaxCorrection", "SMaxCorrection", 0);
  for (c70_i57 = 0; c70_i57 < 30; c70_i57++) {
    c70_qd_u[c70_i57] = c70_bd_u.HAlphaCorrection[c70_i57];
  }

  c70_sd_y = NULL;
  sf_mex_assign(&c70_sd_y, sf_mex_create("y", c70_qd_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c70_dd_y, c70_sd_y, "HAlphaCorrection", "HAlphaCorrection", 0);
  c70_rd_u = c70_bd_u.Phi;
  c70_td_y = NULL;
  sf_mex_assign(&c70_td_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c70_sd_u = c70_rd_u.c0;
  c70_ud_y = NULL;
  sf_mex_assign(&c70_ud_y, sf_mex_create("y", &c70_sd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_td_y, c70_ud_y, "c0", "c0", 0);
  for (c70_i58 = 0; c70_i58 < 13; c70_i58++) {
    c70_td_u[c70_i58] = c70_rd_u.cq[c70_i58];
  }

  c70_vd_y = NULL;
  sf_mex_assign(&c70_vd_y, sf_mex_create("y", c70_td_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c70_td_y, c70_vd_y, "cq", "cq", 0);
  sf_mex_addfield(c70_dd_y, c70_td_y, "Phi", "Phi", 0);
  for (c70_i59 = 0; c70_i59 < 20; c70_i59++) {
    c70_ud_u[c70_i59] = c70_bd_u.PhiAlpha[c70_i59];
  }

  c70_wd_y = NULL;
  sf_mex_assign(&c70_wd_y, sf_mex_create("y", c70_ud_u, 0, 0U, 1U, 0U, 2, 1, 20),
                false);
  sf_mex_addfield(c70_dd_y, c70_wd_y, "PhiAlpha", "PhiAlpha", 0);
  c70_vd_u = c70_bd_u.SaturateR;
  c70_xd_y = NULL;
  sf_mex_assign(&c70_xd_y, sf_mex_create("y", &c70_vd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_dd_y, c70_xd_y, "SaturateR", "SaturateR", 0);
  for (c70_i60 = 0; c70_i60 < 2; c70_i60++) {
    c70_wd_u[c70_i60] = c70_bd_u.RLimits[c70_i60];
  }

  c70_yd_y = NULL;
  sf_mex_assign(&c70_yd_y, sf_mex_create("y", c70_wd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c70_dd_y, c70_yd_y, "RLimits", "RLimits", 0);
  for (c70_i61 = 0; c70_i61 < 30; c70_i61++) {
    c70_xd_u[c70_i61] = c70_bd_u.HBarAlpha[c70_i61];
  }

  c70_ae_y = NULL;
  sf_mex_assign(&c70_ae_y, sf_mex_create("y", c70_xd_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c70_dd_y, c70_ae_y, "HBarAlpha", "HBarAlpha", 0);
  for (c70_i62 = 0; c70_i62 < 12; c70_i62++) {
    c70_yd_u[c70_i62] = c70_bd_u.HBarLimits[c70_i62];
  }

  c70_be_y = NULL;
  sf_mex_assign(&c70_be_y, sf_mex_create("y", c70_yd_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c70_dd_y, c70_be_y, "HBarLimits", "HBarLimits", 0);
  for (c70_i63 = 0; c70_i63 < 36; c70_i63++) {
    c70_ae_u[c70_i63] = c70_bd_u.HAlphaStar[c70_i63];
  }

  c70_ce_y = NULL;
  sf_mex_assign(&c70_ce_y, sf_mex_create("y", c70_ae_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c70_dd_y, c70_ce_y, "HAlphaStar", "HAlphaStar", 0);
  c70_be_u = c70_bd_u.YawLimit;
  c70_de_y = NULL;
  sf_mex_assign(&c70_de_y, sf_mex_create("y", &c70_be_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_dd_y, c70_de_y, "YawLimit", "YawLimit", 0);
  c70_ce_u = c70_bd_u.test;
  c70_ee_y = NULL;
  sf_mex_assign(&c70_ee_y, sf_mex_create("y", &c70_ce_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_dd_y, c70_ee_y, "test", "test", 0);
  sf_mex_addfield(c70_b_y, c70_dd_y, "Output", "Output", 0);
  for (c70_i64 = 0; c70_i64 < 6; c70_i64++) {
    c70_de_u.kp[c70_i64] = ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)
      &((char_T *)chartInstance->c70_ControlParams1)[3472])[0])[c70_i64];
  }

  for (c70_i65 = 0; c70_i65 < 6; c70_i65++) {
    c70_de_u.kd[c70_i65] = ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)
      &((char_T *)chartInstance->c70_ControlParams1)[3472])[48])[c70_i65];
  }

  for (c70_i66 = 0; c70_i66 < 2; c70_i66++) {
    c70_de_u.epsilon[c70_i66] = ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)
      &((char_T *)chartInstance->c70_ControlParams1)[3472])[96])[c70_i66];
  }

  for (c70_i67 = 0; c70_i67 < 2; c70_i67++) {
    c70_de_u.kff_grav[c70_i67] = ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)
      &((char_T *)chartInstance->c70_ControlParams1)[3472])[112])[c70_i67];
  }

  c70_de_u.delta_grav = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3472])[128];
  for (c70_i68 = 0; c70_i68 < 2; c70_i68++) {
    c70_de_u.kff_decoup[c70_i68] = ((real_T *)&((char_T *)(c70_FeedbackParamsBus
      *)&((char_T *)chartInstance->c70_ControlParams1)[3472])[136])[c70_i68];
  }

  for (c70_i69 = 0; c70_i69 < 2; c70_i69++) {
    c70_de_u.kd_torso[c70_i69] = ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)
      &((char_T *)chartInstance->c70_ControlParams1)[3472])[152])[c70_i69];
  }

  c70_de_u.kp_2dof = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[168];
  c70_de_u.kd_2dof = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[176];
  c70_de_u.kpre_2dof = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T
    *)chartInstance->c70_ControlParams1)[3472])[184];
  c70_de_u.kp_lat = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[192];
  c70_de_u.kd_lat = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[200];
  c70_de_u.q3d_min_lat = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3472])[208];
  c70_de_u.q3d_max_lat = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3472])[216];
  c70_de_u.w_torso_lat = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3472])[224];
  for (c70_i70 = 0; c70_i70 < 6; c70_i70++) {
    c70_de_u.u_ff[c70_i70] = ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)
      &((char_T *)chartInstance->c70_ControlParams1)[3472])[232])[c70_i70];
  }

  c70_de_u.LateralControlMode = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3472])[280];
  c70_de_u.DecouplingMode = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3472])[288];
  c70_de_u.Use2DOF = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[296];
  c70_de_u.UseDSGravComp = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3472])[304];
  c70_de_u.lat_bias = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[312];
  c70_de_u.lat_bias2 = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T
    *)chartInstance->c70_ControlParams1)[3472])[320];
  c70_de_u.linkFeedback = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3472])[328];
  c70_de_u.RIO = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[336];
  c70_de_u.SelectFeedforward = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3472])[344];
  for (c70_i71 = 0; c70_i71 < 6; c70_i71++) {
    c70_de_u.FeedforwardGain[c70_i71] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
      [3472])[352])[c70_i71];
  }

  c70_de_u.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)[3472])
    [400];
  c70_fe_y = NULL;
  sf_mex_assign(&c70_fe_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c70_i72 = 0; c70_i72 < 6; c70_i72++) {
    c70_ee_u[c70_i72] = c70_de_u.kp[c70_i72];
  }

  c70_ge_y = NULL;
  sf_mex_assign(&c70_ge_y, sf_mex_create("y", c70_ee_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_fe_y, c70_ge_y, "kp", "kp", 0);
  for (c70_i73 = 0; c70_i73 < 6; c70_i73++) {
    c70_fe_u[c70_i73] = c70_de_u.kd[c70_i73];
  }

  c70_he_y = NULL;
  sf_mex_assign(&c70_he_y, sf_mex_create("y", c70_fe_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_fe_y, c70_he_y, "kd", "kd", 0);
  for (c70_i74 = 0; c70_i74 < 2; c70_i74++) {
    c70_ge_u[c70_i74] = c70_de_u.epsilon[c70_i74];
  }

  c70_ie_y = NULL;
  sf_mex_assign(&c70_ie_y, sf_mex_create("y", c70_ge_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c70_fe_y, c70_ie_y, "epsilon", "epsilon", 0);
  for (c70_i75 = 0; c70_i75 < 2; c70_i75++) {
    c70_he_u[c70_i75] = c70_de_u.kff_grav[c70_i75];
  }

  c70_je_y = NULL;
  sf_mex_assign(&c70_je_y, sf_mex_create("y", c70_he_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c70_fe_y, c70_je_y, "kff_grav", "kff_grav", 0);
  c70_ie_u = c70_de_u.delta_grav;
  c70_ke_y = NULL;
  sf_mex_assign(&c70_ke_y, sf_mex_create("y", &c70_ie_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_ke_y, "delta_grav", "delta_grav", 0);
  for (c70_i76 = 0; c70_i76 < 2; c70_i76++) {
    c70_je_u[c70_i76] = c70_de_u.kff_decoup[c70_i76];
  }

  c70_le_y = NULL;
  sf_mex_assign(&c70_le_y, sf_mex_create("y", c70_je_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c70_fe_y, c70_le_y, "kff_decoup", "kff_decoup", 0);
  for (c70_i77 = 0; c70_i77 < 2; c70_i77++) {
    c70_ke_u[c70_i77] = c70_de_u.kd_torso[c70_i77];
  }

  c70_me_y = NULL;
  sf_mex_assign(&c70_me_y, sf_mex_create("y", c70_ke_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c70_fe_y, c70_me_y, "kd_torso", "kd_torso", 0);
  c70_le_u = c70_de_u.kp_2dof;
  c70_ne_y = NULL;
  sf_mex_assign(&c70_ne_y, sf_mex_create("y", &c70_le_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_ne_y, "kp_2dof", "kp_2dof", 0);
  c70_me_u = c70_de_u.kd_2dof;
  c70_oe_y = NULL;
  sf_mex_assign(&c70_oe_y, sf_mex_create("y", &c70_me_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_oe_y, "kd_2dof", "kd_2dof", 0);
  c70_ne_u = c70_de_u.kpre_2dof;
  c70_pe_y = NULL;
  sf_mex_assign(&c70_pe_y, sf_mex_create("y", &c70_ne_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_pe_y, "kpre_2dof", "kpre_2dof", 0);
  c70_oe_u = c70_de_u.kp_lat;
  c70_qe_y = NULL;
  sf_mex_assign(&c70_qe_y, sf_mex_create("y", &c70_oe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_qe_y, "kp_lat", "kp_lat", 0);
  c70_pe_u = c70_de_u.kd_lat;
  c70_re_y = NULL;
  sf_mex_assign(&c70_re_y, sf_mex_create("y", &c70_pe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_re_y, "kd_lat", "kd_lat", 0);
  c70_qe_u = c70_de_u.q3d_min_lat;
  c70_se_y = NULL;
  sf_mex_assign(&c70_se_y, sf_mex_create("y", &c70_qe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_se_y, "q3d_min_lat", "q3d_min_lat", 0);
  c70_re_u = c70_de_u.q3d_max_lat;
  c70_te_y = NULL;
  sf_mex_assign(&c70_te_y, sf_mex_create("y", &c70_re_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_te_y, "q3d_max_lat", "q3d_max_lat", 0);
  c70_se_u = c70_de_u.w_torso_lat;
  c70_ue_y = NULL;
  sf_mex_assign(&c70_ue_y, sf_mex_create("y", &c70_se_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_ue_y, "w_torso_lat", "w_torso_lat", 0);
  for (c70_i78 = 0; c70_i78 < 6; c70_i78++) {
    c70_te_u[c70_i78] = c70_de_u.u_ff[c70_i78];
  }

  c70_ve_y = NULL;
  sf_mex_assign(&c70_ve_y, sf_mex_create("y", c70_te_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_fe_y, c70_ve_y, "u_ff", "u_ff", 0);
  c70_ue_u = c70_de_u.LateralControlMode;
  c70_we_y = NULL;
  sf_mex_assign(&c70_we_y, sf_mex_create("y", &c70_ue_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_we_y, "LateralControlMode", "LateralControlMode",
                  0);
  c70_ve_u = c70_de_u.DecouplingMode;
  c70_xe_y = NULL;
  sf_mex_assign(&c70_xe_y, sf_mex_create("y", &c70_ve_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_xe_y, "DecouplingMode", "DecouplingMode", 0);
  c70_we_u = c70_de_u.Use2DOF;
  c70_ye_y = NULL;
  sf_mex_assign(&c70_ye_y, sf_mex_create("y", &c70_we_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_ye_y, "Use2DOF", "Use2DOF", 0);
  c70_xe_u = c70_de_u.UseDSGravComp;
  c70_af_y = NULL;
  sf_mex_assign(&c70_af_y, sf_mex_create("y", &c70_xe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_af_y, "UseDSGravComp", "UseDSGravComp", 0);
  c70_ye_u = c70_de_u.lat_bias;
  c70_bf_y = NULL;
  sf_mex_assign(&c70_bf_y, sf_mex_create("y", &c70_ye_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_bf_y, "lat_bias", "lat_bias", 0);
  c70_af_u = c70_de_u.lat_bias2;
  c70_cf_y = NULL;
  sf_mex_assign(&c70_cf_y, sf_mex_create("y", &c70_af_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_cf_y, "lat_bias2", "lat_bias2", 0);
  c70_bf_u = c70_de_u.linkFeedback;
  c70_df_y = NULL;
  sf_mex_assign(&c70_df_y, sf_mex_create("y", &c70_bf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_df_y, "linkFeedback", "linkFeedback", 0);
  c70_cf_u = c70_de_u.RIO;
  c70_ef_y = NULL;
  sf_mex_assign(&c70_ef_y, sf_mex_create("y", &c70_cf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_ef_y, "RIO", "RIO", 0);
  c70_df_u = c70_de_u.SelectFeedforward;
  c70_ff_y = NULL;
  sf_mex_assign(&c70_ff_y, sf_mex_create("y", &c70_df_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_ff_y, "SelectFeedforward", "SelectFeedforward",
                  0);
  for (c70_i79 = 0; c70_i79 < 6; c70_i79++) {
    c70_ef_u[c70_i79] = c70_de_u.FeedforwardGain[c70_i79];
  }

  c70_gf_y = NULL;
  sf_mex_assign(&c70_gf_y, sf_mex_create("y", c70_ef_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_fe_y, c70_gf_y, "FeedforwardGain", "FeedforwardGain", 0);
  c70_ff_u = c70_de_u.EnableFeedforwardOnStep;
  c70_hf_y = NULL;
  sf_mex_assign(&c70_hf_y, sf_mex_create("y", &c70_ff_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_fe_y, c70_hf_y, "EnableFeedforwardOnStep",
                  "EnableFeedforwardOnStep", 0);
  sf_mex_addfield(c70_b_y, c70_fe_y, "Feedback", "Feedback", 0);
  c70_gf_u.UseQPSaturation = *(real_T *)&((char_T *)(c70_SaturationParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3880])[0];
  for (c70_i80 = 0; c70_i80 < 2; c70_i80++) {
    c70_gf_u.QPWeight[c70_i80] = ((real_T *)&((char_T *)(c70_SaturationParamsBus
      *)&((char_T *)chartInstance->c70_ControlParams1)[3880])[8])[c70_i80];
  }

  c70_gf_u.UseKASaturation = *(real_T *)&((char_T *)(c70_SaturationParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3880])[24];
  c70_gf_u.KASaturationS1 = *(real_T *)&((char_T *)(c70_SaturationParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3880])[32];
  c70_gf_u.KASaturationS2 = *(real_T *)&((char_T *)(c70_SaturationParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3880])[40];
  c70_gf_u.KASaturationEarly = *(real_T *)&((char_T *)(c70_SaturationParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3880])[48];
  c70_gf_u.KASaturationMax = *(real_T *)&((char_T *)(c70_SaturationParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[3880])[56];
  c70_if_y = NULL;
  sf_mex_assign(&c70_if_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c70_hf_u = c70_gf_u.UseQPSaturation;
  c70_jf_y = NULL;
  sf_mex_assign(&c70_jf_y, sf_mex_create("y", &c70_hf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_if_y, c70_jf_y, "UseQPSaturation", "UseQPSaturation", 0);
  for (c70_i81 = 0; c70_i81 < 2; c70_i81++) {
    c70_if_u[c70_i81] = c70_gf_u.QPWeight[c70_i81];
  }

  c70_kf_y = NULL;
  sf_mex_assign(&c70_kf_y, sf_mex_create("y", c70_if_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c70_if_y, c70_kf_y, "QPWeight", "QPWeight", 0);
  c70_jf_u = c70_gf_u.UseKASaturation;
  c70_lf_y = NULL;
  sf_mex_assign(&c70_lf_y, sf_mex_create("y", &c70_jf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_if_y, c70_lf_y, "UseKASaturation", "UseKASaturation", 0);
  c70_kf_u = c70_gf_u.KASaturationS1;
  c70_mf_y = NULL;
  sf_mex_assign(&c70_mf_y, sf_mex_create("y", &c70_kf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_if_y, c70_mf_y, "KASaturationS1", "KASaturationS1", 0);
  c70_lf_u = c70_gf_u.KASaturationS2;
  c70_nf_y = NULL;
  sf_mex_assign(&c70_nf_y, sf_mex_create("y", &c70_lf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_if_y, c70_nf_y, "KASaturationS2", "KASaturationS2", 0);
  c70_mf_u = c70_gf_u.KASaturationEarly;
  c70_of_y = NULL;
  sf_mex_assign(&c70_of_y, sf_mex_create("y", &c70_mf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_if_y, c70_of_y, "KASaturationEarly", "KASaturationEarly",
                  0);
  c70_nf_u = c70_gf_u.KASaturationMax;
  c70_pf_y = NULL;
  sf_mex_assign(&c70_pf_y, sf_mex_create("y", &c70_nf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_if_y, c70_pf_y, "KASaturationMax", "KASaturationMax", 0);
  sf_mex_addfield(c70_b_y, c70_if_y, "Saturation", "Saturation", 0);
  sf_mex_setcell(c70_y, 0, c70_b_y);
  c70_hoistedGlobal = chartInstance->c70_is_active_c70_DDA2D_OSU3Dv2;
  c70_of_u = c70_hoistedGlobal;
  c70_qf_y = NULL;
  sf_mex_assign(&c70_qf_y, sf_mex_create("y", &c70_of_u, 3, 0U, 0U, 0U, 0),
                false);
  sf_mex_setcell(c70_y, 1, c70_qf_y);
  sf_mex_assign(&c70_st, c70_y, false);
  return c70_st;
}

static void set_sim_state_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_st)
{
  const mxArray *c70_u;
  c70_ControlParamsBus c70_r0;
  int32_T c70_i82;
  int32_T c70_i83;
  int32_T c70_i84;
  int32_T c70_i85;
  int32_T c70_i86;
  int32_T c70_i87;
  int32_T c70_i88;
  int32_T c70_i89;
  int32_T c70_i90;
  int32_T c70_i91;
  int32_T c70_i92;
  int32_T c70_i93;
  int32_T c70_i94;
  int32_T c70_i95;
  int32_T c70_i96;
  int32_T c70_i97;
  int32_T c70_i98;
  int32_T c70_i99;
  int32_T c70_i100;
  int32_T c70_i101;
  int32_T c70_i102;
  int32_T c70_i103;
  int32_T c70_i104;
  int32_T c70_i105;
  int32_T c70_i106;
  int32_T c70_i107;
  int32_T c70_i108;
  int32_T c70_i109;
  int32_T c70_i110;
  int32_T c70_i111;
  int32_T c70_i112;
  int32_T c70_i113;
  int32_T c70_i114;
  int32_T c70_i115;
  int32_T c70_i116;
  int32_T c70_i117;
  int32_T c70_i118;
  int32_T c70_i119;
  int32_T c70_i120;
  int32_T c70_i121;
  int32_T c70_i122;
  int32_T c70_i123;
  int32_T c70_i124;
  int32_T c70_i125;
  int32_T c70_i126;
  int32_T c70_i127;
  int32_T c70_i128;
  int32_T c70_i129;
  chartInstance->c70_doneDoubleBufferReInit = true;
  c70_u = sf_mex_dup(c70_st);
  c70_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c70_u, 0)),
                       "ControlParams1", &c70_r0);
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[0] =
    c70_r0.Supervisory.EnableSwapOnKAAccel;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[8] =
    c70_r0.Supervisory.EnableSwapOnKASpring;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[16] =
    c70_r0.Supervisory.EnableBackwardSwap;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[24] =
    c70_r0.Supervisory.ImpactThresholdKAAccel;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[32] =
    c70_r0.Supervisory.ImpactThresholdKASpringAbs;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[40] =
    c70_r0.Supervisory.ImpactThresholdKASpringRel;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[48] =
    c70_r0.Supervisory.SwapThresholdS;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[56] =
    c70_r0.Supervisory.AllowDoubleSupport;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[64] =
    c70_r0.Supervisory.UseGaitTransition;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[72] =
    c70_r0.Supervisory.NumTransitionSteps;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[80] =
    c70_r0.Supervisory.TransitionThresholdTorsoVel;
  for (c70_i82 = 0; c70_i82 < 2; c70_i82++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[88])[c70_i82] =
      c70_r0.Supervisory.KAInjection[c70_i82];
  }

  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[104] =
    c70_r0.Supervisory.MinDeltaThetaTransition;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[112] =
    c70_r0.Supervisory.StartSecondGaitOnStep;
  for (c70_i83 = 0; c70_i83 < 6; c70_i83++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[120])[c70_i83] =
      c70_r0.Supervisory.VBLAParams[c70_i83];
  }

  for (c70_i84 = 0; c70_i84 < 13; c70_i84++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[168])[c70_i84] =
      c70_r0.Supervisory.BalanceParams[c70_i84];
  }

  for (c70_i85 = 0; c70_i85 < 5; c70_i85++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[272])[c70_i85] =
      c70_r0.Supervisory.GaitTweaks[c70_i85];
  }

  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[312] =
    c70_r0.Supervisory.TStepInitial;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[320] = c70_r0.Supervisory.TMaxUpdate;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[328] = c70_r0.Supervisory.RunMode;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[336] =
    c70_r0.Supervisory.UseAbsoluteSwingLA;
  for (c70_i86 = 0; c70_i86 < 6; c70_i86++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[344])[c70_i86] =
      c70_r0.Supervisory.ErrorZeroFactor[c70_i86];
  }

  for (c70_i87 = 0; c70_i87 < 6; c70_i87++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[392])[c70_i87] =
      c70_r0.Supervisory.ErrorVelZeroFactor[c70_i87];
  }

  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[440] =
    c70_r0.Supervisory.StanceLegInit;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[448] =
    c70_r0.Supervisory.ControllerModeInit;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[456] =
    c70_r0.Supervisory.UsePosingControl;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[464] = c70_r0.Supervisory.TPosing;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[472] =
    c70_r0.Supervisory.TorsoBackAngle;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[480] =
    c70_r0.Supervisory.TorsoBackOnStep;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[488] =
    c70_r0.Supervisory.EnergyControlGain;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[496] =
    c70_r0.Supervisory.EnergyControlPhi0;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[504] =
    c70_r0.Supervisory.VelocityControlTorsoMax;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[512] =
    c70_r0.Supervisory.VelocityControlTorsoMin;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[520] =
    c70_r0.Supervisory.VelocityControlTorsoGain;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[528] =
    c70_r0.Supervisory.VelocityControlTorsoV0;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[536] =
    c70_r0.Supervisory.MinDeltaTheta;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[544] = c70_r0.Supervisory.Theta0;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[552] = c70_r0.Supervisory.KThetaPlus;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[560] = c70_r0.Supervisory.KThetaMinus;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[568] =
    c70_r0.Supervisory.RollPhaseVelocityThresh;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[576] =
    c70_r0.Supervisory.RollPhaseSThresh;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[584] = c70_r0.Supervisory.MaxError;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[592] = c70_r0.Supervisory.MaxErrorVel;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[600] =
    c70_r0.Supervisory.MaxErrorCount;
  for (c70_i88 = 0; c70_i88 < 6; c70_i88++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[608])[c70_i88] =
      c70_r0.Supervisory.K1MidStanceUpdate[c70_i88];
  }

  for (c70_i89 = 0; c70_i89 < 6; c70_i89++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[656])[c70_i89] =
      c70_r0.Supervisory.K2MidStanceUpdate[c70_i89];
  }

  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[704] =
    c70_r0.Supervisory.EnableVelocityBasedUpdate;
  for (c70_i90 = 0; c70_i90 < 6; c70_i90++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[712])[c70_i90] =
      c70_r0.Supervisory.VelocityBasedUpdateK1[c70_i90];
  }

  for (c70_i91 = 0; c70_i91 < 6; c70_i91++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[760])[c70_i91] =
      c70_r0.Supervisory.VelocityBasedUpdateK2[c70_i91];
  }

  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[808] =
    c70_r0.Supervisory.VelocityBasedUpdateDTheta0;
  c70_i92 = 0;
  for (c70_i93 = 0; c70_i93 < 2; c70_i93++) {
    for (c70_i94 = 0; c70_i94 < 6; c70_i94++) {
      ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[0])[816])[c70_i94 + c70_i92] =
        c70_r0.Supervisory.VelocityBasedUpdateLimits[c70_i94 + c70_i92];
    }

    c70_i92 += 6;
  }

  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[912] =
    c70_r0.Supervisory.DesiredYawOffset;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[920] = c70_r0.Supervisory.dx_cmd;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[928] = c70_r0.Supervisory.ForBackward;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[936] =
    c70_r0.Supervisory.EnableFrictionID;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[944] =
    c70_r0.Supervisory.ResetFrictionPosing;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[952] =
    c70_r0.Supervisory.MoveLegIndex;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[960] = c70_r0.Supervisory.dy_cmd;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[968] = c70_r0.Supervisory.TauDelay;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[976] =
    c70_r0.Supervisory.TrackFrequency;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[984] =
    c70_r0.Supervisory.EnablePDControl;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[992] = c70_r0.Supervisory.TorqueAmp;
  for (c70_i95 = 0; c70_i95 < 6; c70_i95++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[1000])[c70_i95] =
      c70_r0.Supervisory.hdPosing[c70_i95];
  }

  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[0] = c70_r0.Discrete.TLastUpdate;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[8] =
    c70_r0.Discrete.VelocityControlLADelta;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[16] =
    c70_r0.Discrete.VelocityControlTorsoDelta;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[24] =
    c70_r0.Discrete.VelocityControlHipDistCur;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[32] =
    c70_r0.Discrete.VelocityControlHipDistPrev;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[40] =
    c70_r0.Discrete.VirtualSpringMode;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[48] =
    c70_r0.Discrete.VirtualSpringStiffness;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[56] =
    c70_r0.Discrete.VirtualSpringDamping;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[64] =
    c70_r0.Discrete.VirtualSpringModAmplitude;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[72] =
    c70_r0.Discrete.VirtualSpringModRate;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[80] =
    c70_r0.Discrete.VirtualSpringRestPos;
  c70_i96 = 0;
  for (c70_i97 = 0; c70_i97 < 13; c70_i97++) {
    for (c70_i98 = 0; c70_i98 < 6; c70_i98++) {
      ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[1136])[0])[c70_i98 + c70_i96] =
        c70_r0.Output.H0[c70_i98 + c70_i96];
    }

    c70_i96 += 6;
  }

  c70_i99 = 0;
  for (c70_i100 = 0; c70_i100 < 6; c70_i100++) {
    for (c70_i101 = 0; c70_i101 < 6; c70_i101++) {
      ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[1136])[624])[c70_i101 + c70_i99] =
        c70_r0.Output.HAlpha[c70_i101 + c70_i99];
    }

    c70_i99 += 6;
  }

  for (c70_i102 = 0; c70_i102 < 2; c70_i102++) {
    ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[1136])[912])[c70_i102] =
      c70_r0.Output.ThetaLimits[c70_i102];
  }

  *(real_T *)&((char_T *)(c70_ThetaParamsBus *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1136])[928])[0] =
    c70_r0.Output.Theta.c0;
  *(real_T *)&((char_T *)(c70_ThetaParamsBus *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1136])[928])[8] =
    c70_r0.Output.Theta.ct;
  for (c70_i103 = 0; c70_i103 < 13; c70_i103++) {
    ((real_T *)&((char_T *)(c70_ThetaParamsBus *)&((char_T *)
       (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
       [1136])[928])[16])[c70_i103] = c70_r0.Output.Theta.cq[c70_i103];
  }

  *(real_T *)&((char_T *)(c70_ThetaParamsBus *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1136])[928])[120] =
    c70_r0.Output.Theta.t0;
  for (c70_i104 = 0; c70_i104 < 7; c70_i104++) {
    ((real_T *)&((char_T *)(c70_ThetaParamsBus *)&((char_T *)
       (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
       [1136])[928])[128])[c70_i104] = c70_r0.Output.Theta.cz[c70_i104];
  }

  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[1112] = c70_r0.Output.SaturateS;
  for (c70_i105 = 0; c70_i105 < 2; c70_i105++) {
    ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[1136])[1120])[c70_i105] =
      c70_r0.Output.SLimits[c70_i105];
  }

  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[1136] =
    c70_r0.Output.EnforceIncreasingS;
  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[1144] =
    c70_r0.Output.UseCorrection;
  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[1152] =
    c70_r0.Output.SMaxCorrection;
  c70_i106 = 0;
  for (c70_i107 = 0; c70_i107 < 5; c70_i107++) {
    for (c70_i108 = 0; c70_i108 < 6; c70_i108++) {
      ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[1136])[1160])[c70_i108 + c70_i106] =
        c70_r0.Output.HAlphaCorrection[c70_i108 + c70_i106];
    }

    c70_i106 += 6;
  }

  *(real_T *)&((char_T *)(c70_PhiParamsBus *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1136])[1400])[0] =
    c70_r0.Output.Phi.c0;
  for (c70_i109 = 0; c70_i109 < 13; c70_i109++) {
    ((real_T *)&((char_T *)(c70_PhiParamsBus *)&((char_T *)(c70_OutputParamsBus *)
       &((char_T *)chartInstance->c70_ControlParams1)[1136])[1400])[8])[c70_i109]
      = c70_r0.Output.Phi.cq[c70_i109];
  }

  for (c70_i110 = 0; c70_i110 < 20; c70_i110++) {
    ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[1136])[1512])[c70_i110] =
      c70_r0.Output.PhiAlpha[c70_i110];
  }

  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[1672] = c70_r0.Output.SaturateR;
  for (c70_i111 = 0; c70_i111 < 2; c70_i111++) {
    ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[1136])[1680])[c70_i111] =
      c70_r0.Output.RLimits[c70_i111];
  }

  c70_i112 = 0;
  for (c70_i113 = 0; c70_i113 < 5; c70_i113++) {
    for (c70_i114 = 0; c70_i114 < 6; c70_i114++) {
      ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[1136])[1696])[c70_i114 + c70_i112] =
        c70_r0.Output.HBarAlpha[c70_i114 + c70_i112];
    }

    c70_i112 += 6;
  }

  c70_i115 = 0;
  for (c70_i116 = 0; c70_i116 < 2; c70_i116++) {
    for (c70_i117 = 0; c70_i117 < 6; c70_i117++) {
      ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[1136])[1936])[c70_i117 + c70_i115] =
        c70_r0.Output.HBarLimits[c70_i117 + c70_i115];
    }

    c70_i115 += 6;
  }

  c70_i118 = 0;
  for (c70_i119 = 0; c70_i119 < 6; c70_i119++) {
    for (c70_i120 = 0; c70_i120 < 6; c70_i120++) {
      ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[1136])[2032])[c70_i120 + c70_i118] =
        c70_r0.Output.HAlphaStar[c70_i120 + c70_i118];
    }

    c70_i118 += 6;
  }

  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[2320] = c70_r0.Output.YawLimit;
  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[2328] = c70_r0.Output.test;
  for (c70_i121 = 0; c70_i121 < 6; c70_i121++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[0])[c70_i121] =
      c70_r0.Feedback.kp[c70_i121];
  }

  for (c70_i122 = 0; c70_i122 < 6; c70_i122++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[48])[c70_i122] =
      c70_r0.Feedback.kd[c70_i122];
  }

  for (c70_i123 = 0; c70_i123 < 2; c70_i123++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[96])[c70_i123] =
      c70_r0.Feedback.epsilon[c70_i123];
  }

  for (c70_i124 = 0; c70_i124 < 2; c70_i124++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[112])[c70_i124] =
      c70_r0.Feedback.kff_grav[c70_i124];
  }

  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[128] = c70_r0.Feedback.delta_grav;
  for (c70_i125 = 0; c70_i125 < 2; c70_i125++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[136])[c70_i125] =
      c70_r0.Feedback.kff_decoup[c70_i125];
  }

  for (c70_i126 = 0; c70_i126 < 2; c70_i126++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[152])[c70_i126] =
      c70_r0.Feedback.kd_torso[c70_i126];
  }

  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[168] = c70_r0.Feedback.kp_2dof;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[176] = c70_r0.Feedback.kd_2dof;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[184] = c70_r0.Feedback.kpre_2dof;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[192] = c70_r0.Feedback.kp_lat;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[200] = c70_r0.Feedback.kd_lat;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[208] = c70_r0.Feedback.q3d_min_lat;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[216] = c70_r0.Feedback.q3d_max_lat;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[224] = c70_r0.Feedback.w_torso_lat;
  for (c70_i127 = 0; c70_i127 < 6; c70_i127++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[232])[c70_i127] =
      c70_r0.Feedback.u_ff[c70_i127];
  }

  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[280] =
    c70_r0.Feedback.LateralControlMode;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[288] =
    c70_r0.Feedback.DecouplingMode;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[296] = c70_r0.Feedback.Use2DOF;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[304] =
    c70_r0.Feedback.UseDSGravComp;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[312] = c70_r0.Feedback.lat_bias;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[320] = c70_r0.Feedback.lat_bias2;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[328] =
    c70_r0.Feedback.linkFeedback;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[336] = c70_r0.Feedback.RIO;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[344] =
    c70_r0.Feedback.SelectFeedforward;
  for (c70_i128 = 0; c70_i128 < 6; c70_i128++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[352])[c70_i128] =
      c70_r0.Feedback.FeedforwardGain[c70_i128];
  }

  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[400] =
    c70_r0.Feedback.EnableFeedforwardOnStep;
  *(real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3880])[0] =
    c70_r0.Saturation.UseQPSaturation;
  for (c70_i129 = 0; c70_i129 < 2; c70_i129++) {
    ((real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3880])[8])[c70_i129] =
      c70_r0.Saturation.QPWeight[c70_i129];
  }

  *(real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3880])[24] =
    c70_r0.Saturation.UseKASaturation;
  *(real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3880])[32] =
    c70_r0.Saturation.KASaturationS1;
  *(real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3880])[40] =
    c70_r0.Saturation.KASaturationS2;
  *(real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3880])[48] =
    c70_r0.Saturation.KASaturationEarly;
  *(real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3880])[56] =
    c70_r0.Saturation.KASaturationMax;
  chartInstance->c70_is_active_c70_DDA2D_OSU3Dv2 = c70_x_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c70_u, 1)),
     "is_active_c70_DDA2D_OSU3Dv2");
  sf_mex_destroy(&c70_u);
  c70_update_debugger_state_c70_DDA2D_OSU3Dv2(chartInstance);
  sf_mex_destroy(&c70_st);
}

static void finalize_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  boolean_T c70_hoistedGlobal;
  real_T c70_b_hoistedGlobal;
  real_T c70_c_hoistedGlobal;
  real_T c70_d_hoistedGlobal;
  boolean_T c70_b_isSim;
  real_T c70_b_t;
  real_T c70_b_dx_est;
  c70_ControlParamsBus c70_b_ControlParams;
  int32_T c70_i130;
  int32_T c70_i131;
  int32_T c70_i132;
  int32_T c70_i133;
  int32_T c70_i134;
  int32_T c70_i135;
  int32_T c70_i136;
  int32_T c70_i137;
  int32_T c70_i138;
  int32_T c70_i139;
  int32_T c70_i140;
  int32_T c70_i141;
  int32_T c70_i142;
  int32_T c70_i143;
  int32_T c70_i144;
  int32_T c70_i145;
  int32_T c70_i146;
  int32_T c70_i147;
  int32_T c70_i148;
  int32_T c70_i149;
  int32_T c70_i150;
  int32_T c70_i151;
  int32_T c70_i152;
  int32_T c70_i153;
  int32_T c70_i154;
  int32_T c70_i155;
  int32_T c70_i156;
  int32_T c70_i157;
  int32_T c70_i158;
  int32_T c70_i159;
  int32_T c70_i160;
  int32_T c70_i161;
  int32_T c70_i162;
  int32_T c70_i163;
  int32_T c70_i164;
  int32_T c70_i165;
  int32_T c70_i166;
  int32_T c70_i167;
  int32_T c70_i168;
  int32_T c70_i169;
  int32_T c70_i170;
  int32_T c70_i171;
  int32_T c70_i172;
  int32_T c70_i173;
  int32_T c70_i174;
  int32_T c70_i175;
  int32_T c70_i176;
  int32_T c70_i177;
  real_T c70_b_ForBackwardPrev;
  uint32_T c70_debug_family_var_map[8];
  real_T c70_nargin = 5.0;
  real_T c70_nargout = 1.0;
  c70_ControlParamsBus c70_b_ControlParams1;
  int32_T c70_i178;
  int32_T c70_i179;
  int32_T c70_i180;
  int32_T c70_i181;
  int32_T c70_i182;
  int32_T c70_i183;
  int32_T c70_i184;
  int32_T c70_i185;
  int32_T c70_i186;
  int32_T c70_i187;
  int32_T c70_i188;
  int32_T c70_i189;
  int32_T c70_i190;
  int32_T c70_i191;
  int32_T c70_i192;
  int32_T c70_i193;
  int32_T c70_i194;
  int32_T c70_i195;
  int32_T c70_i196;
  int32_T c70_i197;
  int32_T c70_i198;
  int32_T c70_i199;
  int32_T c70_i200;
  int32_T c70_i201;
  int32_T c70_i202;
  int32_T c70_i203;
  int32_T c70_i204;
  int32_T c70_i205;
  int32_T c70_i206;
  int32_T c70_i207;
  int32_T c70_i208;
  int32_T c70_i209;
  int32_T c70_i210;
  int32_T c70_i211;
  int32_T c70_i212;
  int32_T c70_i213;
  int32_T c70_i214;
  int32_T c70_i215;
  int32_T c70_i216;
  int32_T c70_i217;
  int32_T c70_i218;
  int32_T c70_i219;
  int32_T c70_i220;
  int32_T c70_i221;
  int32_T c70_i222;
  int32_T c70_i223;
  int32_T c70_i224;
  int32_T c70_i225;
  boolean_T guard1 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 12U, chartInstance->c70_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c70_isSim, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c70_t, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c70_dx_est, 2U);
  chartInstance->c70_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 12U, chartInstance->c70_sfEvent);
  c70_hoistedGlobal = *chartInstance->c70_isSim;
  c70_b_hoistedGlobal = *chartInstance->c70_t;
  c70_c_hoistedGlobal = *chartInstance->c70_dx_est;
  c70_d_hoistedGlobal = *chartInstance->c70_ForBackwardPrev;
  c70_b_isSim = c70_hoistedGlobal;
  c70_b_t = c70_b_hoistedGlobal;
  c70_b_dx_est = c70_c_hoistedGlobal;
  c70_b_ControlParams.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [0];
  c70_b_ControlParams.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [8];
  c70_b_ControlParams.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [16];
  c70_b_ControlParams.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [24];
  c70_b_ControlParams.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)
    &((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams)[0])[32];
  c70_b_ControlParams.Supervisory.ImpactThresholdKASpringRel = *(real_T *)
    &((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams)[0])[40];
  c70_b_ControlParams.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [48];
  c70_b_ControlParams.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [56];
  c70_b_ControlParams.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [64];
  c70_b_ControlParams.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [72];
  c70_b_ControlParams.Supervisory.TransitionThresholdTorsoVel = *(real_T *)
    &((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams)[0])[80];
  for (c70_i130 = 0; c70_i130 < 2; c70_i130++) {
    c70_b_ControlParams.Supervisory.KAInjection[c70_i130] = ((real_T *)&((char_T
      *)(c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
      [0])[88])[c70_i130];
  }

  c70_b_ControlParams.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T
    *)(c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
    [0])[104];
  c70_b_ControlParams.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [112];
  for (c70_i131 = 0; c70_i131 < 6; c70_i131++) {
    c70_b_ControlParams.Supervisory.VBLAParams[c70_i131] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
      [0])[120])[c70_i131];
  }

  for (c70_i132 = 0; c70_i132 < 13; c70_i132++) {
    c70_b_ControlParams.Supervisory.BalanceParams[c70_i132] = ((real_T *)
      &((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams)[0])[168])[c70_i132];
  }

  for (c70_i133 = 0; c70_i133 < 5; c70_i133++) {
    c70_b_ControlParams.Supervisory.GaitTweaks[c70_i133] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
      [0])[272])[c70_i133];
  }

  c70_b_ControlParams.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [312];
  c70_b_ControlParams.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [320];
  c70_b_ControlParams.Supervisory.RunMode = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [328];
  c70_b_ControlParams.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [336];
  for (c70_i134 = 0; c70_i134 < 6; c70_i134++) {
    c70_b_ControlParams.Supervisory.ErrorZeroFactor[c70_i134] = ((real_T *)
      &((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams)[0])[344])[c70_i134];
  }

  for (c70_i135 = 0; c70_i135 < 6; c70_i135++) {
    c70_b_ControlParams.Supervisory.ErrorVelZeroFactor[c70_i135] = ((real_T *)
      &((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams)[0])[392])[c70_i135];
  }

  c70_b_ControlParams.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [440];
  c70_b_ControlParams.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [448];
  c70_b_ControlParams.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [456];
  c70_b_ControlParams.Supervisory.TPosing = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [464];
  c70_b_ControlParams.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [472];
  c70_b_ControlParams.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [480];
  c70_b_ControlParams.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [488];
  c70_b_ControlParams.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [496];
  c70_b_ControlParams.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T
    *)(c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
    [0])[504];
  c70_b_ControlParams.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T
    *)(c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
    [0])[512];
  c70_b_ControlParams.Supervisory.VelocityControlTorsoGain = *(real_T *)
    &((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams)[0])[520];
  c70_b_ControlParams.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [528];
  c70_b_ControlParams.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [536];
  c70_b_ControlParams.Supervisory.Theta0 = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [544];
  c70_b_ControlParams.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [552];
  c70_b_ControlParams.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [560];
  c70_b_ControlParams.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T
    *)(c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
    [0])[568];
  c70_b_ControlParams.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [576];
  c70_b_ControlParams.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [584];
  c70_b_ControlParams.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [592];
  c70_b_ControlParams.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [600];
  for (c70_i136 = 0; c70_i136 < 6; c70_i136++) {
    c70_b_ControlParams.Supervisory.K1MidStanceUpdate[c70_i136] = ((real_T *)
      &((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams)[0])[608])[c70_i136];
  }

  for (c70_i137 = 0; c70_i137 < 6; c70_i137++) {
    c70_b_ControlParams.Supervisory.K2MidStanceUpdate[c70_i137] = ((real_T *)
      &((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams)[0])[656])[c70_i137];
  }

  c70_b_ControlParams.Supervisory.EnableVelocityBasedUpdate = *(real_T *)
    &((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams)[0])[704];
  for (c70_i138 = 0; c70_i138 < 6; c70_i138++) {
    c70_b_ControlParams.Supervisory.VelocityBasedUpdateK1[c70_i138] = ((real_T *)
      &((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams)[0])[712])[c70_i138];
  }

  for (c70_i139 = 0; c70_i139 < 6; c70_i139++) {
    c70_b_ControlParams.Supervisory.VelocityBasedUpdateK2[c70_i139] = ((real_T *)
      &((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams)[0])[760])[c70_i139];
  }

  c70_b_ControlParams.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)
    &((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams)[0])[808];
  c70_i140 = 0;
  for (c70_i141 = 0; c70_i141 < 2; c70_i141++) {
    for (c70_i142 = 0; c70_i142 < 6; c70_i142++) {
      c70_b_ControlParams.Supervisory.VelocityBasedUpdateLimits[c70_i142 +
        c70_i140] = ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T
        *)chartInstance->c70_ControlParams)[0])[816])[c70_i142 + c70_i140];
    }

    c70_i140 += 6;
  }

  c70_b_ControlParams.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [912];
  c70_b_ControlParams.Supervisory.dx_cmd = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [920];
  c70_b_ControlParams.Supervisory.ForBackward = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [928];
  c70_b_ControlParams.Supervisory.EnableFrictionID = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [936];
  c70_b_ControlParams.Supervisory.ResetFrictionPosing = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [944];
  c70_b_ControlParams.Supervisory.MoveLegIndex = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [952];
  c70_b_ControlParams.Supervisory.dy_cmd = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [960];
  c70_b_ControlParams.Supervisory.TauDelay = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [968];
  c70_b_ControlParams.Supervisory.TrackFrequency = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [976];
  c70_b_ControlParams.Supervisory.EnablePDControl = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [984];
  c70_b_ControlParams.Supervisory.TorqueAmp = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[0])
    [992];
  for (c70_i143 = 0; c70_i143 < 6; c70_i143++) {
    c70_b_ControlParams.Supervisory.hdPosing[c70_i143] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
      [0])[1000])[c70_i143];
  }

  c70_b_ControlParams.Discrete.TLastUpdate = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1048])
    [0];
  c70_b_ControlParams.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1048])
    [8];
  c70_b_ControlParams.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1048])
    [16];
  c70_b_ControlParams.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1048])
    [24];
  c70_b_ControlParams.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T
    *)(c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
    [1048])[32];
  c70_b_ControlParams.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1048])
    [40];
  c70_b_ControlParams.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1048])
    [48];
  c70_b_ControlParams.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1048])
    [56];
  c70_b_ControlParams.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1048])
    [64];
  c70_b_ControlParams.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1048])
    [72];
  c70_b_ControlParams.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1048])
    [80];
  c70_i144 = 0;
  for (c70_i145 = 0; c70_i145 < 13; c70_i145++) {
    for (c70_i146 = 0; c70_i146 < 6; c70_i146++) {
      c70_b_ControlParams.Output.H0[c70_i146 + c70_i144] = ((real_T *)&((char_T *)
        (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
        [1136])[0])[c70_i146 + c70_i144];
    }

    c70_i144 += 6;
  }

  c70_i147 = 0;
  for (c70_i148 = 0; c70_i148 < 6; c70_i148++) {
    for (c70_i149 = 0; c70_i149 < 6; c70_i149++) {
      c70_b_ControlParams.Output.HAlpha[c70_i149 + c70_i147] = ((real_T *)
        &((char_T *)(c70_OutputParamsBus *)&((char_T *)
        chartInstance->c70_ControlParams)[1136])[624])[c70_i149 + c70_i147];
    }

    c70_i147 += 6;
  }

  for (c70_i150 = 0; c70_i150 < 2; c70_i150++) {
    c70_b_ControlParams.Output.ThetaLimits[c70_i150] = ((real_T *)&((char_T *)
      (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1136])
      [912])[c70_i150];
  }

  c70_b_ControlParams.Output.Theta.c0 = *(real_T *)&((char_T *)
    (c70_ThetaParamsBus *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams)[1136])[928])[0];
  c70_b_ControlParams.Output.Theta.ct = *(real_T *)&((char_T *)
    (c70_ThetaParamsBus *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams)[1136])[928])[8];
  for (c70_i151 = 0; c70_i151 < 13; c70_i151++) {
    c70_b_ControlParams.Output.Theta.cq[c70_i151] = ((real_T *)&((char_T *)
      (c70_ThetaParamsBus *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams)[1136])[928])[16])[c70_i151];
  }

  c70_b_ControlParams.Output.Theta.t0 = *(real_T *)&((char_T *)
    (c70_ThetaParamsBus *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams)[1136])[928])[120];
  for (c70_i152 = 0; c70_i152 < 7; c70_i152++) {
    c70_b_ControlParams.Output.Theta.cz[c70_i152] = ((real_T *)&((char_T *)
      (c70_ThetaParamsBus *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams)[1136])[928])[128])[c70_i152];
  }

  c70_b_ControlParams.Output.SaturateS = *(real_T *)&((char_T *)
    (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1136])
    [1112];
  for (c70_i153 = 0; c70_i153 < 2; c70_i153++) {
    c70_b_ControlParams.Output.SLimits[c70_i153] = ((real_T *)&((char_T *)
      (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1136])
      [1120])[c70_i153];
  }

  c70_b_ControlParams.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1136])
    [1136];
  c70_b_ControlParams.Output.UseCorrection = *(real_T *)&((char_T *)
    (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1136])
    [1144];
  c70_b_ControlParams.Output.SMaxCorrection = *(real_T *)&((char_T *)
    (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1136])
    [1152];
  c70_i154 = 0;
  for (c70_i155 = 0; c70_i155 < 5; c70_i155++) {
    for (c70_i156 = 0; c70_i156 < 6; c70_i156++) {
      c70_b_ControlParams.Output.HAlphaCorrection[c70_i156 + c70_i154] =
        ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
           chartInstance->c70_ControlParams)[1136])[1160])[c70_i156 + c70_i154];
    }

    c70_i154 += 6;
  }

  c70_b_ControlParams.Output.Phi.c0 = *(real_T *)&((char_T *)(c70_PhiParamsBus *)
    &((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams)[1136])[1400])[0];
  for (c70_i157 = 0; c70_i157 < 13; c70_i157++) {
    c70_b_ControlParams.Output.Phi.cq[c70_i157] = ((real_T *)&((char_T *)
      (c70_PhiParamsBus *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams)[1136])[1400])[8])[c70_i157];
  }

  for (c70_i158 = 0; c70_i158 < 20; c70_i158++) {
    c70_b_ControlParams.Output.PhiAlpha[c70_i158] = ((real_T *)&((char_T *)
      (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1136])
      [1512])[c70_i158];
  }

  c70_b_ControlParams.Output.SaturateR = *(real_T *)&((char_T *)
    (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1136])
    [1672];
  for (c70_i159 = 0; c70_i159 < 2; c70_i159++) {
    c70_b_ControlParams.Output.RLimits[c70_i159] = ((real_T *)&((char_T *)
      (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1136])
      [1680])[c70_i159];
  }

  c70_i160 = 0;
  for (c70_i161 = 0; c70_i161 < 5; c70_i161++) {
    for (c70_i162 = 0; c70_i162 < 6; c70_i162++) {
      c70_b_ControlParams.Output.HBarAlpha[c70_i162 + c70_i160] = ((real_T *)
        &((char_T *)(c70_OutputParamsBus *)&((char_T *)
        chartInstance->c70_ControlParams)[1136])[1696])[c70_i162 + c70_i160];
    }

    c70_i160 += 6;
  }

  c70_i163 = 0;
  for (c70_i164 = 0; c70_i164 < 2; c70_i164++) {
    for (c70_i165 = 0; c70_i165 < 6; c70_i165++) {
      c70_b_ControlParams.Output.HBarLimits[c70_i165 + c70_i163] = ((real_T *)
        &((char_T *)(c70_OutputParamsBus *)&((char_T *)
        chartInstance->c70_ControlParams)[1136])[1936])[c70_i165 + c70_i163];
    }

    c70_i163 += 6;
  }

  c70_i166 = 0;
  for (c70_i167 = 0; c70_i167 < 6; c70_i167++) {
    for (c70_i168 = 0; c70_i168 < 6; c70_i168++) {
      c70_b_ControlParams.Output.HAlphaStar[c70_i168 + c70_i166] = ((real_T *)
        &((char_T *)(c70_OutputParamsBus *)&((char_T *)
        chartInstance->c70_ControlParams)[1136])[2032])[c70_i168 + c70_i166];
    }

    c70_i166 += 6;
  }

  c70_b_ControlParams.Output.YawLimit = *(real_T *)&((char_T *)
    (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[1136])
    [2320];
  c70_b_ControlParams.Output.test = *(real_T *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams)[1136])[2328];
  for (c70_i169 = 0; c70_i169 < 6; c70_i169++) {
    c70_b_ControlParams.Feedback.kp[c70_i169] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
      [3472])[0])[c70_i169];
  }

  for (c70_i170 = 0; c70_i170 < 6; c70_i170++) {
    c70_b_ControlParams.Feedback.kd[c70_i170] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
      [3472])[48])[c70_i170];
  }

  for (c70_i171 = 0; c70_i171 < 2; c70_i171++) {
    c70_b_ControlParams.Feedback.epsilon[c70_i171] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
      [3472])[96])[c70_i171];
  }

  for (c70_i172 = 0; c70_i172 < 2; c70_i172++) {
    c70_b_ControlParams.Feedback.kff_grav[c70_i172] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
      [3472])[112])[c70_i172];
  }

  c70_b_ControlParams.Feedback.delta_grav = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [128];
  for (c70_i173 = 0; c70_i173 < 2; c70_i173++) {
    c70_b_ControlParams.Feedback.kff_decoup[c70_i173] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
      [3472])[136])[c70_i173];
  }

  for (c70_i174 = 0; c70_i174 < 2; c70_i174++) {
    c70_b_ControlParams.Feedback.kd_torso[c70_i174] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
      [3472])[152])[c70_i174];
  }

  c70_b_ControlParams.Feedback.kp_2dof = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [168];
  c70_b_ControlParams.Feedback.kd_2dof = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [176];
  c70_b_ControlParams.Feedback.kpre_2dof = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [184];
  c70_b_ControlParams.Feedback.kp_lat = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [192];
  c70_b_ControlParams.Feedback.kd_lat = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [200];
  c70_b_ControlParams.Feedback.q3d_min_lat = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [208];
  c70_b_ControlParams.Feedback.q3d_max_lat = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [216];
  c70_b_ControlParams.Feedback.w_torso_lat = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [224];
  for (c70_i175 = 0; c70_i175 < 6; c70_i175++) {
    c70_b_ControlParams.Feedback.u_ff[c70_i175] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
      [3472])[232])[c70_i175];
  }

  c70_b_ControlParams.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [280];
  c70_b_ControlParams.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [288];
  c70_b_ControlParams.Feedback.Use2DOF = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [296];
  c70_b_ControlParams.Feedback.UseDSGravComp = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [304];
  c70_b_ControlParams.Feedback.lat_bias = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [312];
  c70_b_ControlParams.Feedback.lat_bias2 = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [320];
  c70_b_ControlParams.Feedback.linkFeedback = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [328];
  c70_b_ControlParams.Feedback.RIO = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [336];
  c70_b_ControlParams.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [344];
  for (c70_i176 = 0; c70_i176 < 6; c70_i176++) {
    c70_b_ControlParams.Feedback.FeedforwardGain[c70_i176] = ((real_T *)
      &((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
      chartInstance->c70_ControlParams)[3472])[352])[c70_i176];
  }

  c70_b_ControlParams.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)chartInstance->c70_ControlParams)[3472])
    [400];
  c70_b_ControlParams.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c70_SaturationParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
    [3880])[0];
  for (c70_i177 = 0; c70_i177 < 2; c70_i177++) {
    c70_b_ControlParams.Saturation.QPWeight[c70_i177] = ((real_T *)&((char_T *)
      (c70_SaturationParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
      [3880])[8])[c70_i177];
  }

  c70_b_ControlParams.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c70_SaturationParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
    [3880])[24];
  c70_b_ControlParams.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c70_SaturationParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
    [3880])[32];
  c70_b_ControlParams.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c70_SaturationParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
    [3880])[40];
  c70_b_ControlParams.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c70_SaturationParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
    [3880])[48];
  c70_b_ControlParams.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c70_SaturationParamsBus *)&((char_T *)chartInstance->c70_ControlParams)
    [3880])[56];
  c70_b_ForBackwardPrev = c70_d_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 8U, 8U, c70_debug_family_names,
    c70_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c70_nargin, 0U, c70_b_sf_marshallOut,
    c70_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c70_nargout, 1U, c70_b_sf_marshallOut,
    c70_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c70_b_isSim, 2U, c70_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c70_b_t, 3U, c70_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c70_b_dx_est, 4U, c70_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c70_b_ControlParams, 5U, c70_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c70_b_ForBackwardPrev, 6U, c70_b_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c70_b_ControlParams1, 7U,
    c70_sf_marshallOut, c70_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c70_sfEvent, 4);
  c70_b_ControlParams1 = c70_b_ControlParams;
  _SFD_EML_CALL(0U, chartInstance->c70_sfEvent, 5);
  CV_EML_IF(0, 1, 0, c70_b_isSim);
  _SFD_EML_CALL(0U, chartInstance->c70_sfEvent, 14);
  guard1 = false;
  if (CV_EML_COND(0, 1, 0, CV_RELATIONAL_EVAL(4U, 0U, 0, c70_b_dx_est, 0.15, -1,
        2U, c70_b_dx_est < 0.15))) {
    if (CV_EML_COND(0, 1, 1, CV_RELATIONAL_EVAL(4U, 0U, 1, c70_b_dx_est, -0.15,
          -1, 4U, c70_b_dx_est > -0.15))) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 1, true);
      _SFD_EML_CALL(0U, chartInstance->c70_sfEvent, 15);
      if (CV_EML_IF(0, 1, 2, CV_RELATIONAL_EVAL(4U, 0U, 2,
            c70_b_ControlParams1.Supervisory.dx_cmd, 0.0, -1, 5U,
            c70_b_ControlParams1.Supervisory.dx_cmd >= 0.0))) {
        _SFD_EML_CALL(0U, chartInstance->c70_sfEvent, 16);
        c70_b_ControlParams1.Supervisory.ForBackward = 1.0;
      } else {
        _SFD_EML_CALL(0U, chartInstance->c70_sfEvent, 18);
        c70_b_ControlParams1.Supervisory.ForBackward = -1.0;
      }
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 1, false);
    _SFD_EML_CALL(0U, chartInstance->c70_sfEvent, 21);
    c70_b_ControlParams1.Supervisory.ForBackward = c70_b_ForBackwardPrev;
  }

  _SFD_EML_CALL(0U, chartInstance->c70_sfEvent, -21);
  _SFD_SYMBOL_SCOPE_POP();
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[0] =
    c70_b_ControlParams1.Supervisory.EnableSwapOnKAAccel;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[8] =
    c70_b_ControlParams1.Supervisory.EnableSwapOnKASpring;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[16] =
    c70_b_ControlParams1.Supervisory.EnableBackwardSwap;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[24] =
    c70_b_ControlParams1.Supervisory.ImpactThresholdKAAccel;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[32] =
    c70_b_ControlParams1.Supervisory.ImpactThresholdKASpringAbs;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[40] =
    c70_b_ControlParams1.Supervisory.ImpactThresholdKASpringRel;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[48] =
    c70_b_ControlParams1.Supervisory.SwapThresholdS;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[56] =
    c70_b_ControlParams1.Supervisory.AllowDoubleSupport;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[64] =
    c70_b_ControlParams1.Supervisory.UseGaitTransition;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[72] =
    c70_b_ControlParams1.Supervisory.NumTransitionSteps;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[80] =
    c70_b_ControlParams1.Supervisory.TransitionThresholdTorsoVel;
  for (c70_i178 = 0; c70_i178 < 2; c70_i178++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[88])[c70_i178] =
      c70_b_ControlParams1.Supervisory.KAInjection[c70_i178];
  }

  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[104] =
    c70_b_ControlParams1.Supervisory.MinDeltaThetaTransition;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[112] =
    c70_b_ControlParams1.Supervisory.StartSecondGaitOnStep;
  for (c70_i179 = 0; c70_i179 < 6; c70_i179++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[120])[c70_i179] =
      c70_b_ControlParams1.Supervisory.VBLAParams[c70_i179];
  }

  for (c70_i180 = 0; c70_i180 < 13; c70_i180++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[168])[c70_i180] =
      c70_b_ControlParams1.Supervisory.BalanceParams[c70_i180];
  }

  for (c70_i181 = 0; c70_i181 < 5; c70_i181++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[272])[c70_i181] =
      c70_b_ControlParams1.Supervisory.GaitTweaks[c70_i181];
  }

  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[312] =
    c70_b_ControlParams1.Supervisory.TStepInitial;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[320] =
    c70_b_ControlParams1.Supervisory.TMaxUpdate;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[328] =
    c70_b_ControlParams1.Supervisory.RunMode;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[336] =
    c70_b_ControlParams1.Supervisory.UseAbsoluteSwingLA;
  for (c70_i182 = 0; c70_i182 < 6; c70_i182++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[344])[c70_i182] =
      c70_b_ControlParams1.Supervisory.ErrorZeroFactor[c70_i182];
  }

  for (c70_i183 = 0; c70_i183 < 6; c70_i183++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[392])[c70_i183] =
      c70_b_ControlParams1.Supervisory.ErrorVelZeroFactor[c70_i183];
  }

  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[440] =
    c70_b_ControlParams1.Supervisory.StanceLegInit;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[448] =
    c70_b_ControlParams1.Supervisory.ControllerModeInit;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[456] =
    c70_b_ControlParams1.Supervisory.UsePosingControl;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[464] =
    c70_b_ControlParams1.Supervisory.TPosing;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[472] =
    c70_b_ControlParams1.Supervisory.TorsoBackAngle;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[480] =
    c70_b_ControlParams1.Supervisory.TorsoBackOnStep;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[488] =
    c70_b_ControlParams1.Supervisory.EnergyControlGain;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[496] =
    c70_b_ControlParams1.Supervisory.EnergyControlPhi0;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[504] =
    c70_b_ControlParams1.Supervisory.VelocityControlTorsoMax;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[512] =
    c70_b_ControlParams1.Supervisory.VelocityControlTorsoMin;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[520] =
    c70_b_ControlParams1.Supervisory.VelocityControlTorsoGain;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[528] =
    c70_b_ControlParams1.Supervisory.VelocityControlTorsoV0;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[536] =
    c70_b_ControlParams1.Supervisory.MinDeltaTheta;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[544] =
    c70_b_ControlParams1.Supervisory.Theta0;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[552] =
    c70_b_ControlParams1.Supervisory.KThetaPlus;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[560] =
    c70_b_ControlParams1.Supervisory.KThetaMinus;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[568] =
    c70_b_ControlParams1.Supervisory.RollPhaseVelocityThresh;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[576] =
    c70_b_ControlParams1.Supervisory.RollPhaseSThresh;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[584] =
    c70_b_ControlParams1.Supervisory.MaxError;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[592] =
    c70_b_ControlParams1.Supervisory.MaxErrorVel;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[600] =
    c70_b_ControlParams1.Supervisory.MaxErrorCount;
  for (c70_i184 = 0; c70_i184 < 6; c70_i184++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[608])[c70_i184] =
      c70_b_ControlParams1.Supervisory.K1MidStanceUpdate[c70_i184];
  }

  for (c70_i185 = 0; c70_i185 < 6; c70_i185++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[656])[c70_i185] =
      c70_b_ControlParams1.Supervisory.K2MidStanceUpdate[c70_i185];
  }

  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[704] =
    c70_b_ControlParams1.Supervisory.EnableVelocityBasedUpdate;
  for (c70_i186 = 0; c70_i186 < 6; c70_i186++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[712])[c70_i186] =
      c70_b_ControlParams1.Supervisory.VelocityBasedUpdateK1[c70_i186];
  }

  for (c70_i187 = 0; c70_i187 < 6; c70_i187++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[760])[c70_i187] =
      c70_b_ControlParams1.Supervisory.VelocityBasedUpdateK2[c70_i187];
  }

  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[808] =
    c70_b_ControlParams1.Supervisory.VelocityBasedUpdateDTheta0;
  c70_i188 = 0;
  for (c70_i189 = 0; c70_i189 < 2; c70_i189++) {
    for (c70_i190 = 0; c70_i190 < 6; c70_i190++) {
      ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[0])[816])[c70_i190 + c70_i188] =
        c70_b_ControlParams1.Supervisory.VelocityBasedUpdateLimits[c70_i190 +
        c70_i188];
    }

    c70_i188 += 6;
  }

  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[912] =
    c70_b_ControlParams1.Supervisory.DesiredYawOffset;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[920] =
    c70_b_ControlParams1.Supervisory.dx_cmd;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[928] =
    c70_b_ControlParams1.Supervisory.ForBackward;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[936] =
    c70_b_ControlParams1.Supervisory.EnableFrictionID;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[944] =
    c70_b_ControlParams1.Supervisory.ResetFrictionPosing;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[952] =
    c70_b_ControlParams1.Supervisory.MoveLegIndex;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[960] =
    c70_b_ControlParams1.Supervisory.dy_cmd;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[968] =
    c70_b_ControlParams1.Supervisory.TauDelay;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[976] =
    c70_b_ControlParams1.Supervisory.TrackFrequency;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[984] =
    c70_b_ControlParams1.Supervisory.EnablePDControl;
  *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[0])[992] =
    c70_b_ControlParams1.Supervisory.TorqueAmp;
  for (c70_i191 = 0; c70_i191 < 6; c70_i191++) {
    ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[0])[1000])[c70_i191] =
      c70_b_ControlParams1.Supervisory.hdPosing[c70_i191];
  }

  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[0] =
    c70_b_ControlParams1.Discrete.TLastUpdate;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[8] =
    c70_b_ControlParams1.Discrete.VelocityControlLADelta;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[16] =
    c70_b_ControlParams1.Discrete.VelocityControlTorsoDelta;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[24] =
    c70_b_ControlParams1.Discrete.VelocityControlHipDistCur;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[32] =
    c70_b_ControlParams1.Discrete.VelocityControlHipDistPrev;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[40] =
    c70_b_ControlParams1.Discrete.VirtualSpringMode;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[48] =
    c70_b_ControlParams1.Discrete.VirtualSpringStiffness;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[56] =
    c70_b_ControlParams1.Discrete.VirtualSpringDamping;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[64] =
    c70_b_ControlParams1.Discrete.VirtualSpringModAmplitude;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[72] =
    c70_b_ControlParams1.Discrete.VirtualSpringModRate;
  *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1048])[80] =
    c70_b_ControlParams1.Discrete.VirtualSpringRestPos;
  c70_i192 = 0;
  for (c70_i193 = 0; c70_i193 < 13; c70_i193++) {
    for (c70_i194 = 0; c70_i194 < 6; c70_i194++) {
      ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[1136])[0])[c70_i194 + c70_i192] =
        c70_b_ControlParams1.Output.H0[c70_i194 + c70_i192];
    }

    c70_i192 += 6;
  }

  c70_i195 = 0;
  for (c70_i196 = 0; c70_i196 < 6; c70_i196++) {
    for (c70_i197 = 0; c70_i197 < 6; c70_i197++) {
      ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[1136])[624])[c70_i197 + c70_i195] =
        c70_b_ControlParams1.Output.HAlpha[c70_i197 + c70_i195];
    }

    c70_i195 += 6;
  }

  for (c70_i198 = 0; c70_i198 < 2; c70_i198++) {
    ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[1136])[912])[c70_i198] =
      c70_b_ControlParams1.Output.ThetaLimits[c70_i198];
  }

  *(real_T *)&((char_T *)(c70_ThetaParamsBus *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1136])[928])[0] =
    c70_b_ControlParams1.Output.Theta.c0;
  *(real_T *)&((char_T *)(c70_ThetaParamsBus *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1136])[928])[8] =
    c70_b_ControlParams1.Output.Theta.ct;
  for (c70_i199 = 0; c70_i199 < 13; c70_i199++) {
    ((real_T *)&((char_T *)(c70_ThetaParamsBus *)&((char_T *)
       (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
       [1136])[928])[16])[c70_i199] =
      c70_b_ControlParams1.Output.Theta.cq[c70_i199];
  }

  *(real_T *)&((char_T *)(c70_ThetaParamsBus *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1136])[928])[120] =
    c70_b_ControlParams1.Output.Theta.t0;
  for (c70_i200 = 0; c70_i200 < 7; c70_i200++) {
    ((real_T *)&((char_T *)(c70_ThetaParamsBus *)&((char_T *)
       (c70_OutputParamsBus *)&((char_T *)chartInstance->c70_ControlParams1)
       [1136])[928])[128])[c70_i200] =
      c70_b_ControlParams1.Output.Theta.cz[c70_i200];
  }

  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[1112] =
    c70_b_ControlParams1.Output.SaturateS;
  for (c70_i201 = 0; c70_i201 < 2; c70_i201++) {
    ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[1136])[1120])[c70_i201] =
      c70_b_ControlParams1.Output.SLimits[c70_i201];
  }

  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[1136] =
    c70_b_ControlParams1.Output.EnforceIncreasingS;
  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[1144] =
    c70_b_ControlParams1.Output.UseCorrection;
  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[1152] =
    c70_b_ControlParams1.Output.SMaxCorrection;
  c70_i202 = 0;
  for (c70_i203 = 0; c70_i203 < 5; c70_i203++) {
    for (c70_i204 = 0; c70_i204 < 6; c70_i204++) {
      ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[1136])[1160])[c70_i204 + c70_i202] =
        c70_b_ControlParams1.Output.HAlphaCorrection[c70_i204 + c70_i202];
    }

    c70_i202 += 6;
  }

  *(real_T *)&((char_T *)(c70_PhiParamsBus *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)chartInstance->c70_ControlParams1)[1136])[1400])[0] =
    c70_b_ControlParams1.Output.Phi.c0;
  for (c70_i205 = 0; c70_i205 < 13; c70_i205++) {
    ((real_T *)&((char_T *)(c70_PhiParamsBus *)&((char_T *)(c70_OutputParamsBus *)
       &((char_T *)chartInstance->c70_ControlParams1)[1136])[1400])[8])[c70_i205]
      = c70_b_ControlParams1.Output.Phi.cq[c70_i205];
  }

  for (c70_i206 = 0; c70_i206 < 20; c70_i206++) {
    ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[1136])[1512])[c70_i206] =
      c70_b_ControlParams1.Output.PhiAlpha[c70_i206];
  }

  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[1672] =
    c70_b_ControlParams1.Output.SaturateR;
  for (c70_i207 = 0; c70_i207 < 2; c70_i207++) {
    ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[1136])[1680])[c70_i207] =
      c70_b_ControlParams1.Output.RLimits[c70_i207];
  }

  c70_i208 = 0;
  for (c70_i209 = 0; c70_i209 < 5; c70_i209++) {
    for (c70_i210 = 0; c70_i210 < 6; c70_i210++) {
      ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[1136])[1696])[c70_i210 + c70_i208] =
        c70_b_ControlParams1.Output.HBarAlpha[c70_i210 + c70_i208];
    }

    c70_i208 += 6;
  }

  c70_i211 = 0;
  for (c70_i212 = 0; c70_i212 < 2; c70_i212++) {
    for (c70_i213 = 0; c70_i213 < 6; c70_i213++) {
      ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[1136])[1936])[c70_i213 + c70_i211] =
        c70_b_ControlParams1.Output.HBarLimits[c70_i213 + c70_i211];
    }

    c70_i211 += 6;
  }

  c70_i214 = 0;
  for (c70_i215 = 0; c70_i215 < 6; c70_i215++) {
    for (c70_i216 = 0; c70_i216 < 6; c70_i216++) {
      ((real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
         chartInstance->c70_ControlParams1)[1136])[2032])[c70_i216 + c70_i214] =
        c70_b_ControlParams1.Output.HAlphaStar[c70_i216 + c70_i214];
    }

    c70_i214 += 6;
  }

  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[2320] =
    c70_b_ControlParams1.Output.YawLimit;
  *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[1136])[2328] =
    c70_b_ControlParams1.Output.test;
  for (c70_i217 = 0; c70_i217 < 6; c70_i217++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[0])[c70_i217] =
      c70_b_ControlParams1.Feedback.kp[c70_i217];
  }

  for (c70_i218 = 0; c70_i218 < 6; c70_i218++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[48])[c70_i218] =
      c70_b_ControlParams1.Feedback.kd[c70_i218];
  }

  for (c70_i219 = 0; c70_i219 < 2; c70_i219++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[96])[c70_i219] =
      c70_b_ControlParams1.Feedback.epsilon[c70_i219];
  }

  for (c70_i220 = 0; c70_i220 < 2; c70_i220++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[112])[c70_i220] =
      c70_b_ControlParams1.Feedback.kff_grav[c70_i220];
  }

  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[128] =
    c70_b_ControlParams1.Feedback.delta_grav;
  for (c70_i221 = 0; c70_i221 < 2; c70_i221++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[136])[c70_i221] =
      c70_b_ControlParams1.Feedback.kff_decoup[c70_i221];
  }

  for (c70_i222 = 0; c70_i222 < 2; c70_i222++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[152])[c70_i222] =
      c70_b_ControlParams1.Feedback.kd_torso[c70_i222];
  }

  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[168] =
    c70_b_ControlParams1.Feedback.kp_2dof;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[176] =
    c70_b_ControlParams1.Feedback.kd_2dof;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[184] =
    c70_b_ControlParams1.Feedback.kpre_2dof;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[192] =
    c70_b_ControlParams1.Feedback.kp_lat;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[200] =
    c70_b_ControlParams1.Feedback.kd_lat;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[208] =
    c70_b_ControlParams1.Feedback.q3d_min_lat;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[216] =
    c70_b_ControlParams1.Feedback.q3d_max_lat;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[224] =
    c70_b_ControlParams1.Feedback.w_torso_lat;
  for (c70_i223 = 0; c70_i223 < 6; c70_i223++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[232])[c70_i223] =
      c70_b_ControlParams1.Feedback.u_ff[c70_i223];
  }

  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[280] =
    c70_b_ControlParams1.Feedback.LateralControlMode;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[288] =
    c70_b_ControlParams1.Feedback.DecouplingMode;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[296] =
    c70_b_ControlParams1.Feedback.Use2DOF;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[304] =
    c70_b_ControlParams1.Feedback.UseDSGravComp;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[312] =
    c70_b_ControlParams1.Feedback.lat_bias;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[320] =
    c70_b_ControlParams1.Feedback.lat_bias2;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[328] =
    c70_b_ControlParams1.Feedback.linkFeedback;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[336] =
    c70_b_ControlParams1.Feedback.RIO;
  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[344] =
    c70_b_ControlParams1.Feedback.SelectFeedforward;
  for (c70_i224 = 0; c70_i224 < 6; c70_i224++) {
    ((real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3472])[352])[c70_i224] =
      c70_b_ControlParams1.Feedback.FeedforwardGain[c70_i224];
  }

  *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3472])[400] =
    c70_b_ControlParams1.Feedback.EnableFeedforwardOnStep;
  *(real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3880])[0] =
    c70_b_ControlParams1.Saturation.UseQPSaturation;
  for (c70_i225 = 0; c70_i225 < 2; c70_i225++) {
    ((real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
       chartInstance->c70_ControlParams1)[3880])[8])[c70_i225] =
      c70_b_ControlParams1.Saturation.QPWeight[c70_i225];
  }

  *(real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3880])[24] =
    c70_b_ControlParams1.Saturation.UseKASaturation;
  *(real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3880])[32] =
    c70_b_ControlParams1.Saturation.KASaturationS1;
  *(real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3880])[40] =
    c70_b_ControlParams1.Saturation.KASaturationS2;
  *(real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3880])[48] =
    c70_b_ControlParams1.Saturation.KASaturationEarly;
  *(real_T *)&((char_T *)(c70_SaturationParamsBus *)&((char_T *)
    chartInstance->c70_ControlParams1)[3880])[56] =
    c70_b_ControlParams1.Saturation.KASaturationMax;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 12U, chartInstance->c70_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DDA2D_OSU3Dv2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c70_ForBackwardPrev, 5U);
}

static void mdl_start_c70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc70_DDA2D_OSU3Dv2(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c70_machineNumber, uint32_T
  c70_chartNumber, uint32_T c70_instanceNumber)
{
  (void)c70_machineNumber;
  (void)c70_chartNumber;
  (void)c70_instanceNumber;
}

static const mxArray *c70_sf_marshallOut(void *chartInstanceVoid, void
  *c70_inData)
{
  const mxArray *c70_mxArrayOutData;
  c70_ControlParamsBus c70_u;
  const mxArray *c70_y = NULL;
  c70_SupervisoryParamsBus c70_b_u;
  const mxArray *c70_b_y = NULL;
  real_T c70_c_u;
  const mxArray *c70_c_y = NULL;
  real_T c70_d_u;
  const mxArray *c70_d_y = NULL;
  real_T c70_e_u;
  const mxArray *c70_e_y = NULL;
  real_T c70_f_u;
  const mxArray *c70_f_y = NULL;
  real_T c70_g_u;
  const mxArray *c70_g_y = NULL;
  real_T c70_h_u;
  const mxArray *c70_h_y = NULL;
  real_T c70_i_u;
  const mxArray *c70_i_y = NULL;
  real_T c70_j_u;
  const mxArray *c70_j_y = NULL;
  real_T c70_k_u;
  const mxArray *c70_k_y = NULL;
  real_T c70_l_u;
  const mxArray *c70_l_y = NULL;
  real_T c70_m_u;
  const mxArray *c70_m_y = NULL;
  int32_T c70_i226;
  real_T c70_n_u[2];
  const mxArray *c70_n_y = NULL;
  real_T c70_o_u;
  const mxArray *c70_o_y = NULL;
  real_T c70_p_u;
  const mxArray *c70_p_y = NULL;
  int32_T c70_i227;
  real_T c70_q_u[6];
  const mxArray *c70_q_y = NULL;
  int32_T c70_i228;
  real_T c70_r_u[13];
  const mxArray *c70_r_y = NULL;
  int32_T c70_i229;
  real_T c70_s_u[5];
  const mxArray *c70_s_y = NULL;
  real_T c70_t_u;
  const mxArray *c70_t_y = NULL;
  real_T c70_u_u;
  const mxArray *c70_u_y = NULL;
  real_T c70_v_u;
  const mxArray *c70_v_y = NULL;
  real_T c70_w_u;
  const mxArray *c70_w_y = NULL;
  int32_T c70_i230;
  real_T c70_x_u[6];
  const mxArray *c70_x_y = NULL;
  int32_T c70_i231;
  real_T c70_y_u[6];
  const mxArray *c70_y_y = NULL;
  real_T c70_ab_u;
  const mxArray *c70_ab_y = NULL;
  real_T c70_bb_u;
  const mxArray *c70_bb_y = NULL;
  real_T c70_cb_u;
  const mxArray *c70_cb_y = NULL;
  real_T c70_db_u;
  const mxArray *c70_db_y = NULL;
  real_T c70_eb_u;
  const mxArray *c70_eb_y = NULL;
  real_T c70_fb_u;
  const mxArray *c70_fb_y = NULL;
  real_T c70_gb_u;
  const mxArray *c70_gb_y = NULL;
  real_T c70_hb_u;
  const mxArray *c70_hb_y = NULL;
  real_T c70_ib_u;
  const mxArray *c70_ib_y = NULL;
  real_T c70_jb_u;
  const mxArray *c70_jb_y = NULL;
  real_T c70_kb_u;
  const mxArray *c70_kb_y = NULL;
  real_T c70_lb_u;
  const mxArray *c70_lb_y = NULL;
  real_T c70_mb_u;
  const mxArray *c70_mb_y = NULL;
  real_T c70_nb_u;
  const mxArray *c70_nb_y = NULL;
  real_T c70_ob_u;
  const mxArray *c70_ob_y = NULL;
  real_T c70_pb_u;
  const mxArray *c70_pb_y = NULL;
  real_T c70_qb_u;
  const mxArray *c70_qb_y = NULL;
  real_T c70_rb_u;
  const mxArray *c70_rb_y = NULL;
  real_T c70_sb_u;
  const mxArray *c70_sb_y = NULL;
  real_T c70_tb_u;
  const mxArray *c70_tb_y = NULL;
  real_T c70_ub_u;
  const mxArray *c70_ub_y = NULL;
  int32_T c70_i232;
  real_T c70_vb_u[6];
  const mxArray *c70_vb_y = NULL;
  int32_T c70_i233;
  real_T c70_wb_u[6];
  const mxArray *c70_wb_y = NULL;
  real_T c70_xb_u;
  const mxArray *c70_xb_y = NULL;
  int32_T c70_i234;
  real_T c70_yb_u[6];
  const mxArray *c70_yb_y = NULL;
  int32_T c70_i235;
  real_T c70_ac_u[6];
  const mxArray *c70_ac_y = NULL;
  real_T c70_bc_u;
  const mxArray *c70_bc_y = NULL;
  int32_T c70_i236;
  real_T c70_cc_u[12];
  const mxArray *c70_cc_y = NULL;
  real_T c70_dc_u;
  const mxArray *c70_dc_y = NULL;
  real_T c70_ec_u;
  const mxArray *c70_ec_y = NULL;
  real_T c70_fc_u;
  const mxArray *c70_fc_y = NULL;
  real_T c70_gc_u;
  const mxArray *c70_gc_y = NULL;
  real_T c70_hc_u;
  const mxArray *c70_hc_y = NULL;
  real_T c70_ic_u;
  const mxArray *c70_ic_y = NULL;
  real_T c70_jc_u;
  const mxArray *c70_jc_y = NULL;
  real_T c70_kc_u;
  const mxArray *c70_kc_y = NULL;
  real_T c70_lc_u;
  const mxArray *c70_lc_y = NULL;
  real_T c70_mc_u;
  const mxArray *c70_mc_y = NULL;
  real_T c70_nc_u;
  const mxArray *c70_nc_y = NULL;
  int32_T c70_i237;
  real_T c70_oc_u[6];
  const mxArray *c70_oc_y = NULL;
  c70_DiscreteParamsBus c70_pc_u;
  const mxArray *c70_pc_y = NULL;
  real_T c70_qc_u;
  const mxArray *c70_qc_y = NULL;
  real_T c70_rc_u;
  const mxArray *c70_rc_y = NULL;
  real_T c70_sc_u;
  const mxArray *c70_sc_y = NULL;
  real_T c70_tc_u;
  const mxArray *c70_tc_y = NULL;
  real_T c70_uc_u;
  const mxArray *c70_uc_y = NULL;
  real_T c70_vc_u;
  const mxArray *c70_vc_y = NULL;
  real_T c70_wc_u;
  const mxArray *c70_wc_y = NULL;
  real_T c70_xc_u;
  const mxArray *c70_xc_y = NULL;
  real_T c70_yc_u;
  const mxArray *c70_yc_y = NULL;
  real_T c70_ad_u;
  const mxArray *c70_ad_y = NULL;
  real_T c70_bd_u;
  const mxArray *c70_bd_y = NULL;
  c70_OutputParamsBus c70_cd_u;
  const mxArray *c70_cd_y = NULL;
  int32_T c70_i238;
  real_T c70_dd_u[78];
  const mxArray *c70_dd_y = NULL;
  int32_T c70_i239;
  real_T c70_ed_u[36];
  const mxArray *c70_ed_y = NULL;
  int32_T c70_i240;
  real_T c70_fd_u[2];
  const mxArray *c70_fd_y = NULL;
  c70_ThetaParamsBus c70_gd_u;
  const mxArray *c70_gd_y = NULL;
  real_T c70_hd_u;
  const mxArray *c70_hd_y = NULL;
  real_T c70_id_u;
  const mxArray *c70_id_y = NULL;
  int32_T c70_i241;
  real_T c70_jd_u[13];
  const mxArray *c70_jd_y = NULL;
  real_T c70_kd_u;
  const mxArray *c70_kd_y = NULL;
  int32_T c70_i242;
  real_T c70_ld_u[7];
  const mxArray *c70_ld_y = NULL;
  real_T c70_md_u;
  const mxArray *c70_md_y = NULL;
  int32_T c70_i243;
  real_T c70_nd_u[2];
  const mxArray *c70_nd_y = NULL;
  real_T c70_od_u;
  const mxArray *c70_od_y = NULL;
  real_T c70_pd_u;
  const mxArray *c70_pd_y = NULL;
  real_T c70_qd_u;
  const mxArray *c70_qd_y = NULL;
  int32_T c70_i244;
  real_T c70_rd_u[30];
  const mxArray *c70_rd_y = NULL;
  c70_PhiParamsBus c70_sd_u;
  const mxArray *c70_sd_y = NULL;
  real_T c70_td_u;
  const mxArray *c70_td_y = NULL;
  int32_T c70_i245;
  real_T c70_ud_u[13];
  const mxArray *c70_ud_y = NULL;
  int32_T c70_i246;
  real_T c70_vd_u[20];
  const mxArray *c70_vd_y = NULL;
  real_T c70_wd_u;
  const mxArray *c70_wd_y = NULL;
  int32_T c70_i247;
  real_T c70_xd_u[2];
  const mxArray *c70_xd_y = NULL;
  int32_T c70_i248;
  real_T c70_yd_u[30];
  const mxArray *c70_yd_y = NULL;
  int32_T c70_i249;
  real_T c70_ae_u[12];
  const mxArray *c70_ae_y = NULL;
  int32_T c70_i250;
  real_T c70_be_u[36];
  const mxArray *c70_be_y = NULL;
  real_T c70_ce_u;
  const mxArray *c70_ce_y = NULL;
  real_T c70_de_u;
  const mxArray *c70_de_y = NULL;
  c70_FeedbackParamsBus c70_ee_u;
  const mxArray *c70_ee_y = NULL;
  int32_T c70_i251;
  real_T c70_fe_u[6];
  const mxArray *c70_fe_y = NULL;
  int32_T c70_i252;
  real_T c70_ge_u[6];
  const mxArray *c70_ge_y = NULL;
  int32_T c70_i253;
  real_T c70_he_u[2];
  const mxArray *c70_he_y = NULL;
  int32_T c70_i254;
  real_T c70_ie_u[2];
  const mxArray *c70_ie_y = NULL;
  real_T c70_je_u;
  const mxArray *c70_je_y = NULL;
  int32_T c70_i255;
  real_T c70_ke_u[2];
  const mxArray *c70_ke_y = NULL;
  int32_T c70_i256;
  real_T c70_le_u[2];
  const mxArray *c70_le_y = NULL;
  real_T c70_me_u;
  const mxArray *c70_me_y = NULL;
  real_T c70_ne_u;
  const mxArray *c70_ne_y = NULL;
  real_T c70_oe_u;
  const mxArray *c70_oe_y = NULL;
  real_T c70_pe_u;
  const mxArray *c70_pe_y = NULL;
  real_T c70_qe_u;
  const mxArray *c70_qe_y = NULL;
  real_T c70_re_u;
  const mxArray *c70_re_y = NULL;
  real_T c70_se_u;
  const mxArray *c70_se_y = NULL;
  real_T c70_te_u;
  const mxArray *c70_te_y = NULL;
  int32_T c70_i257;
  real_T c70_ue_u[6];
  const mxArray *c70_ue_y = NULL;
  real_T c70_ve_u;
  const mxArray *c70_ve_y = NULL;
  real_T c70_we_u;
  const mxArray *c70_we_y = NULL;
  real_T c70_xe_u;
  const mxArray *c70_xe_y = NULL;
  real_T c70_ye_u;
  const mxArray *c70_ye_y = NULL;
  real_T c70_af_u;
  const mxArray *c70_af_y = NULL;
  real_T c70_bf_u;
  const mxArray *c70_bf_y = NULL;
  real_T c70_cf_u;
  const mxArray *c70_cf_y = NULL;
  real_T c70_df_u;
  const mxArray *c70_df_y = NULL;
  real_T c70_ef_u;
  const mxArray *c70_ef_y = NULL;
  int32_T c70_i258;
  real_T c70_ff_u[6];
  const mxArray *c70_ff_y = NULL;
  real_T c70_gf_u;
  const mxArray *c70_gf_y = NULL;
  c70_SaturationParamsBus c70_hf_u;
  const mxArray *c70_hf_y = NULL;
  real_T c70_if_u;
  const mxArray *c70_if_y = NULL;
  int32_T c70_i259;
  real_T c70_jf_u[2];
  const mxArray *c70_jf_y = NULL;
  real_T c70_kf_u;
  const mxArray *c70_kf_y = NULL;
  real_T c70_lf_u;
  const mxArray *c70_lf_y = NULL;
  real_T c70_mf_u;
  const mxArray *c70_mf_y = NULL;
  real_T c70_nf_u;
  const mxArray *c70_nf_y = NULL;
  real_T c70_of_u;
  const mxArray *c70_of_y = NULL;
  SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc70_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c70_mxArrayOutData = NULL;
  c70_mxArrayOutData = NULL;
  c70_u = *(c70_ControlParamsBus *)c70_inData;
  c70_y = NULL;
  sf_mex_assign(&c70_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c70_b_u = c70_u.Supervisory;
  c70_b_y = NULL;
  sf_mex_assign(&c70_b_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c70_c_u = c70_b_u.EnableSwapOnKAAccel;
  c70_c_y = NULL;
  sf_mex_assign(&c70_c_y, sf_mex_create("y", &c70_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_c_y, "EnableSwapOnKAAccel", "EnableSwapOnKAAccel",
                  0);
  c70_d_u = c70_b_u.EnableSwapOnKASpring;
  c70_d_y = NULL;
  sf_mex_assign(&c70_d_y, sf_mex_create("y", &c70_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_d_y, "EnableSwapOnKASpring",
                  "EnableSwapOnKASpring", 0);
  c70_e_u = c70_b_u.EnableBackwardSwap;
  c70_e_y = NULL;
  sf_mex_assign(&c70_e_y, sf_mex_create("y", &c70_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_e_y, "EnableBackwardSwap", "EnableBackwardSwap",
                  0);
  c70_f_u = c70_b_u.ImpactThresholdKAAccel;
  c70_f_y = NULL;
  sf_mex_assign(&c70_f_y, sf_mex_create("y", &c70_f_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_f_y, "ImpactThresholdKAAccel",
                  "ImpactThresholdKAAccel", 0);
  c70_g_u = c70_b_u.ImpactThresholdKASpringAbs;
  c70_g_y = NULL;
  sf_mex_assign(&c70_g_y, sf_mex_create("y", &c70_g_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_g_y, "ImpactThresholdKASpringAbs",
                  "ImpactThresholdKASpringAbs", 0);
  c70_h_u = c70_b_u.ImpactThresholdKASpringRel;
  c70_h_y = NULL;
  sf_mex_assign(&c70_h_y, sf_mex_create("y", &c70_h_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_h_y, "ImpactThresholdKASpringRel",
                  "ImpactThresholdKASpringRel", 0);
  c70_i_u = c70_b_u.SwapThresholdS;
  c70_i_y = NULL;
  sf_mex_assign(&c70_i_y, sf_mex_create("y", &c70_i_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_i_y, "SwapThresholdS", "SwapThresholdS", 0);
  c70_j_u = c70_b_u.AllowDoubleSupport;
  c70_j_y = NULL;
  sf_mex_assign(&c70_j_y, sf_mex_create("y", &c70_j_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_j_y, "AllowDoubleSupport", "AllowDoubleSupport",
                  0);
  c70_k_u = c70_b_u.UseGaitTransition;
  c70_k_y = NULL;
  sf_mex_assign(&c70_k_y, sf_mex_create("y", &c70_k_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_k_y, "UseGaitTransition", "UseGaitTransition", 0);
  c70_l_u = c70_b_u.NumTransitionSteps;
  c70_l_y = NULL;
  sf_mex_assign(&c70_l_y, sf_mex_create("y", &c70_l_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_l_y, "NumTransitionSteps", "NumTransitionSteps",
                  0);
  c70_m_u = c70_b_u.TransitionThresholdTorsoVel;
  c70_m_y = NULL;
  sf_mex_assign(&c70_m_y, sf_mex_create("y", &c70_m_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_m_y, "TransitionThresholdTorsoVel",
                  "TransitionThresholdTorsoVel", 0);
  for (c70_i226 = 0; c70_i226 < 2; c70_i226++) {
    c70_n_u[c70_i226] = c70_b_u.KAInjection[c70_i226];
  }

  c70_n_y = NULL;
  sf_mex_assign(&c70_n_y, sf_mex_create("y", c70_n_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c70_b_y, c70_n_y, "KAInjection", "KAInjection", 0);
  c70_o_u = c70_b_u.MinDeltaThetaTransition;
  c70_o_y = NULL;
  sf_mex_assign(&c70_o_y, sf_mex_create("y", &c70_o_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_o_y, "MinDeltaThetaTransition",
                  "MinDeltaThetaTransition", 0);
  c70_p_u = c70_b_u.StartSecondGaitOnStep;
  c70_p_y = NULL;
  sf_mex_assign(&c70_p_y, sf_mex_create("y", &c70_p_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_p_y, "StartSecondGaitOnStep",
                  "StartSecondGaitOnStep", 0);
  for (c70_i227 = 0; c70_i227 < 6; c70_i227++) {
    c70_q_u[c70_i227] = c70_b_u.VBLAParams[c70_i227];
  }

  c70_q_y = NULL;
  sf_mex_assign(&c70_q_y, sf_mex_create("y", c70_q_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_b_y, c70_q_y, "VBLAParams", "VBLAParams", 0);
  for (c70_i228 = 0; c70_i228 < 13; c70_i228++) {
    c70_r_u[c70_i228] = c70_b_u.BalanceParams[c70_i228];
  }

  c70_r_y = NULL;
  sf_mex_assign(&c70_r_y, sf_mex_create("y", c70_r_u, 0, 0U, 1U, 0U, 1, 13),
                false);
  sf_mex_addfield(c70_b_y, c70_r_y, "BalanceParams", "BalanceParams", 0);
  for (c70_i229 = 0; c70_i229 < 5; c70_i229++) {
    c70_s_u[c70_i229] = c70_b_u.GaitTweaks[c70_i229];
  }

  c70_s_y = NULL;
  sf_mex_assign(&c70_s_y, sf_mex_create("y", c70_s_u, 0, 0U, 1U, 0U, 1, 5),
                false);
  sf_mex_addfield(c70_b_y, c70_s_y, "GaitTweaks", "GaitTweaks", 0);
  c70_t_u = c70_b_u.TStepInitial;
  c70_t_y = NULL;
  sf_mex_assign(&c70_t_y, sf_mex_create("y", &c70_t_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_t_y, "TStepInitial", "TStepInitial", 0);
  c70_u_u = c70_b_u.TMaxUpdate;
  c70_u_y = NULL;
  sf_mex_assign(&c70_u_y, sf_mex_create("y", &c70_u_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_u_y, "TMaxUpdate", "TMaxUpdate", 0);
  c70_v_u = c70_b_u.RunMode;
  c70_v_y = NULL;
  sf_mex_assign(&c70_v_y, sf_mex_create("y", &c70_v_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_v_y, "RunMode", "RunMode", 0);
  c70_w_u = c70_b_u.UseAbsoluteSwingLA;
  c70_w_y = NULL;
  sf_mex_assign(&c70_w_y, sf_mex_create("y", &c70_w_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_addfield(c70_b_y, c70_w_y, "UseAbsoluteSwingLA", "UseAbsoluteSwingLA",
                  0);
  for (c70_i230 = 0; c70_i230 < 6; c70_i230++) {
    c70_x_u[c70_i230] = c70_b_u.ErrorZeroFactor[c70_i230];
  }

  c70_x_y = NULL;
  sf_mex_assign(&c70_x_y, sf_mex_create("y", c70_x_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_b_y, c70_x_y, "ErrorZeroFactor", "ErrorZeroFactor", 0);
  for (c70_i231 = 0; c70_i231 < 6; c70_i231++) {
    c70_y_u[c70_i231] = c70_b_u.ErrorVelZeroFactor[c70_i231];
  }

  c70_y_y = NULL;
  sf_mex_assign(&c70_y_y, sf_mex_create("y", c70_y_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_b_y, c70_y_y, "ErrorVelZeroFactor", "ErrorVelZeroFactor",
                  0);
  c70_ab_u = c70_b_u.StanceLegInit;
  c70_ab_y = NULL;
  sf_mex_assign(&c70_ab_y, sf_mex_create("y", &c70_ab_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_ab_y, "StanceLegInit", "StanceLegInit", 0);
  c70_bb_u = c70_b_u.ControllerModeInit;
  c70_bb_y = NULL;
  sf_mex_assign(&c70_bb_y, sf_mex_create("y", &c70_bb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_bb_y, "ControllerModeInit", "ControllerModeInit",
                  0);
  c70_cb_u = c70_b_u.UsePosingControl;
  c70_cb_y = NULL;
  sf_mex_assign(&c70_cb_y, sf_mex_create("y", &c70_cb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_cb_y, "UsePosingControl", "UsePosingControl", 0);
  c70_db_u = c70_b_u.TPosing;
  c70_db_y = NULL;
  sf_mex_assign(&c70_db_y, sf_mex_create("y", &c70_db_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_db_y, "TPosing", "TPosing", 0);
  c70_eb_u = c70_b_u.TorsoBackAngle;
  c70_eb_y = NULL;
  sf_mex_assign(&c70_eb_y, sf_mex_create("y", &c70_eb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_eb_y, "TorsoBackAngle", "TorsoBackAngle", 0);
  c70_fb_u = c70_b_u.TorsoBackOnStep;
  c70_fb_y = NULL;
  sf_mex_assign(&c70_fb_y, sf_mex_create("y", &c70_fb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_fb_y, "TorsoBackOnStep", "TorsoBackOnStep", 0);
  c70_gb_u = c70_b_u.EnergyControlGain;
  c70_gb_y = NULL;
  sf_mex_assign(&c70_gb_y, sf_mex_create("y", &c70_gb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_gb_y, "EnergyControlGain", "EnergyControlGain", 0);
  c70_hb_u = c70_b_u.EnergyControlPhi0;
  c70_hb_y = NULL;
  sf_mex_assign(&c70_hb_y, sf_mex_create("y", &c70_hb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_hb_y, "EnergyControlPhi0", "EnergyControlPhi0", 0);
  c70_ib_u = c70_b_u.VelocityControlTorsoMax;
  c70_ib_y = NULL;
  sf_mex_assign(&c70_ib_y, sf_mex_create("y", &c70_ib_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_ib_y, "VelocityControlTorsoMax",
                  "VelocityControlTorsoMax", 0);
  c70_jb_u = c70_b_u.VelocityControlTorsoMin;
  c70_jb_y = NULL;
  sf_mex_assign(&c70_jb_y, sf_mex_create("y", &c70_jb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_jb_y, "VelocityControlTorsoMin",
                  "VelocityControlTorsoMin", 0);
  c70_kb_u = c70_b_u.VelocityControlTorsoGain;
  c70_kb_y = NULL;
  sf_mex_assign(&c70_kb_y, sf_mex_create("y", &c70_kb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_kb_y, "VelocityControlTorsoGain",
                  "VelocityControlTorsoGain", 0);
  c70_lb_u = c70_b_u.VelocityControlTorsoV0;
  c70_lb_y = NULL;
  sf_mex_assign(&c70_lb_y, sf_mex_create("y", &c70_lb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_lb_y, "VelocityControlTorsoV0",
                  "VelocityControlTorsoV0", 0);
  c70_mb_u = c70_b_u.MinDeltaTheta;
  c70_mb_y = NULL;
  sf_mex_assign(&c70_mb_y, sf_mex_create("y", &c70_mb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_mb_y, "MinDeltaTheta", "MinDeltaTheta", 0);
  c70_nb_u = c70_b_u.Theta0;
  c70_nb_y = NULL;
  sf_mex_assign(&c70_nb_y, sf_mex_create("y", &c70_nb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_nb_y, "Theta0", "Theta0", 0);
  c70_ob_u = c70_b_u.KThetaPlus;
  c70_ob_y = NULL;
  sf_mex_assign(&c70_ob_y, sf_mex_create("y", &c70_ob_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_ob_y, "KThetaPlus", "KThetaPlus", 0);
  c70_pb_u = c70_b_u.KThetaMinus;
  c70_pb_y = NULL;
  sf_mex_assign(&c70_pb_y, sf_mex_create("y", &c70_pb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_pb_y, "KThetaMinus", "KThetaMinus", 0);
  c70_qb_u = c70_b_u.RollPhaseVelocityThresh;
  c70_qb_y = NULL;
  sf_mex_assign(&c70_qb_y, sf_mex_create("y", &c70_qb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_qb_y, "RollPhaseVelocityThresh",
                  "RollPhaseVelocityThresh", 0);
  c70_rb_u = c70_b_u.RollPhaseSThresh;
  c70_rb_y = NULL;
  sf_mex_assign(&c70_rb_y, sf_mex_create("y", &c70_rb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_rb_y, "RollPhaseSThresh", "RollPhaseSThresh", 0);
  c70_sb_u = c70_b_u.MaxError;
  c70_sb_y = NULL;
  sf_mex_assign(&c70_sb_y, sf_mex_create("y", &c70_sb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_sb_y, "MaxError", "MaxError", 0);
  c70_tb_u = c70_b_u.MaxErrorVel;
  c70_tb_y = NULL;
  sf_mex_assign(&c70_tb_y, sf_mex_create("y", &c70_tb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_tb_y, "MaxErrorVel", "MaxErrorVel", 0);
  c70_ub_u = c70_b_u.MaxErrorCount;
  c70_ub_y = NULL;
  sf_mex_assign(&c70_ub_y, sf_mex_create("y", &c70_ub_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_ub_y, "MaxErrorCount", "MaxErrorCount", 0);
  for (c70_i232 = 0; c70_i232 < 6; c70_i232++) {
    c70_vb_u[c70_i232] = c70_b_u.K1MidStanceUpdate[c70_i232];
  }

  c70_vb_y = NULL;
  sf_mex_assign(&c70_vb_y, sf_mex_create("y", c70_vb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_b_y, c70_vb_y, "K1MidStanceUpdate", "K1MidStanceUpdate", 0);
  for (c70_i233 = 0; c70_i233 < 6; c70_i233++) {
    c70_wb_u[c70_i233] = c70_b_u.K2MidStanceUpdate[c70_i233];
  }

  c70_wb_y = NULL;
  sf_mex_assign(&c70_wb_y, sf_mex_create("y", c70_wb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_b_y, c70_wb_y, "K2MidStanceUpdate", "K2MidStanceUpdate", 0);
  c70_xb_u = c70_b_u.EnableVelocityBasedUpdate;
  c70_xb_y = NULL;
  sf_mex_assign(&c70_xb_y, sf_mex_create("y", &c70_xb_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_xb_y, "EnableVelocityBasedUpdate",
                  "EnableVelocityBasedUpdate", 0);
  for (c70_i234 = 0; c70_i234 < 6; c70_i234++) {
    c70_yb_u[c70_i234] = c70_b_u.VelocityBasedUpdateK1[c70_i234];
  }

  c70_yb_y = NULL;
  sf_mex_assign(&c70_yb_y, sf_mex_create("y", c70_yb_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_b_y, c70_yb_y, "VelocityBasedUpdateK1",
                  "VelocityBasedUpdateK1", 0);
  for (c70_i235 = 0; c70_i235 < 6; c70_i235++) {
    c70_ac_u[c70_i235] = c70_b_u.VelocityBasedUpdateK2[c70_i235];
  }

  c70_ac_y = NULL;
  sf_mex_assign(&c70_ac_y, sf_mex_create("y", c70_ac_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_b_y, c70_ac_y, "VelocityBasedUpdateK2",
                  "VelocityBasedUpdateK2", 0);
  c70_bc_u = c70_b_u.VelocityBasedUpdateDTheta0;
  c70_bc_y = NULL;
  sf_mex_assign(&c70_bc_y, sf_mex_create("y", &c70_bc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_bc_y, "VelocityBasedUpdateDTheta0",
                  "VelocityBasedUpdateDTheta0", 0);
  for (c70_i236 = 0; c70_i236 < 12; c70_i236++) {
    c70_cc_u[c70_i236] = c70_b_u.VelocityBasedUpdateLimits[c70_i236];
  }

  c70_cc_y = NULL;
  sf_mex_assign(&c70_cc_y, sf_mex_create("y", c70_cc_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c70_b_y, c70_cc_y, "VelocityBasedUpdateLimits",
                  "VelocityBasedUpdateLimits", 0);
  c70_dc_u = c70_b_u.DesiredYawOffset;
  c70_dc_y = NULL;
  sf_mex_assign(&c70_dc_y, sf_mex_create("y", &c70_dc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_dc_y, "DesiredYawOffset", "DesiredYawOffset", 0);
  c70_ec_u = c70_b_u.dx_cmd;
  c70_ec_y = NULL;
  sf_mex_assign(&c70_ec_y, sf_mex_create("y", &c70_ec_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_ec_y, "dx_cmd", "dx_cmd", 0);
  c70_fc_u = c70_b_u.ForBackward;
  c70_fc_y = NULL;
  sf_mex_assign(&c70_fc_y, sf_mex_create("y", &c70_fc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_fc_y, "ForBackward", "ForBackward", 0);
  c70_gc_u = c70_b_u.EnableFrictionID;
  c70_gc_y = NULL;
  sf_mex_assign(&c70_gc_y, sf_mex_create("y", &c70_gc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_gc_y, "EnableFrictionID", "EnableFrictionID", 0);
  c70_hc_u = c70_b_u.ResetFrictionPosing;
  c70_hc_y = NULL;
  sf_mex_assign(&c70_hc_y, sf_mex_create("y", &c70_hc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_hc_y, "ResetFrictionPosing",
                  "ResetFrictionPosing", 0);
  c70_ic_u = c70_b_u.MoveLegIndex;
  c70_ic_y = NULL;
  sf_mex_assign(&c70_ic_y, sf_mex_create("y", &c70_ic_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_ic_y, "MoveLegIndex", "MoveLegIndex", 0);
  c70_jc_u = c70_b_u.dy_cmd;
  c70_jc_y = NULL;
  sf_mex_assign(&c70_jc_y, sf_mex_create("y", &c70_jc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_jc_y, "dy_cmd", "dy_cmd", 0);
  c70_kc_u = c70_b_u.TauDelay;
  c70_kc_y = NULL;
  sf_mex_assign(&c70_kc_y, sf_mex_create("y", &c70_kc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_kc_y, "TauDelay", "TauDelay", 0);
  c70_lc_u = c70_b_u.TrackFrequency;
  c70_lc_y = NULL;
  sf_mex_assign(&c70_lc_y, sf_mex_create("y", &c70_lc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_lc_y, "TrackFrequency", "TrackFrequency", 0);
  c70_mc_u = c70_b_u.EnablePDControl;
  c70_mc_y = NULL;
  sf_mex_assign(&c70_mc_y, sf_mex_create("y", &c70_mc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_mc_y, "EnablePDControl", "EnablePDControl", 0);
  c70_nc_u = c70_b_u.TorqueAmp;
  c70_nc_y = NULL;
  sf_mex_assign(&c70_nc_y, sf_mex_create("y", &c70_nc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_b_y, c70_nc_y, "TorqueAmp", "TorqueAmp", 0);
  for (c70_i237 = 0; c70_i237 < 6; c70_i237++) {
    c70_oc_u[c70_i237] = c70_b_u.hdPosing[c70_i237];
  }

  c70_oc_y = NULL;
  sf_mex_assign(&c70_oc_y, sf_mex_create("y", c70_oc_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_b_y, c70_oc_y, "hdPosing", "hdPosing", 0);
  sf_mex_addfield(c70_y, c70_b_y, "Supervisory", "Supervisory", 0);
  c70_pc_u = c70_u.Discrete;
  c70_pc_y = NULL;
  sf_mex_assign(&c70_pc_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c70_qc_u = c70_pc_u.TLastUpdate;
  c70_qc_y = NULL;
  sf_mex_assign(&c70_qc_y, sf_mex_create("y", &c70_qc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_pc_y, c70_qc_y, "TLastUpdate", "TLastUpdate", 0);
  c70_rc_u = c70_pc_u.VelocityControlLADelta;
  c70_rc_y = NULL;
  sf_mex_assign(&c70_rc_y, sf_mex_create("y", &c70_rc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_pc_y, c70_rc_y, "VelocityControlLADelta",
                  "VelocityControlLADelta", 0);
  c70_sc_u = c70_pc_u.VelocityControlTorsoDelta;
  c70_sc_y = NULL;
  sf_mex_assign(&c70_sc_y, sf_mex_create("y", &c70_sc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_pc_y, c70_sc_y, "VelocityControlTorsoDelta",
                  "VelocityControlTorsoDelta", 0);
  c70_tc_u = c70_pc_u.VelocityControlHipDistCur;
  c70_tc_y = NULL;
  sf_mex_assign(&c70_tc_y, sf_mex_create("y", &c70_tc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_pc_y, c70_tc_y, "VelocityControlHipDistCur",
                  "VelocityControlHipDistCur", 0);
  c70_uc_u = c70_pc_u.VelocityControlHipDistPrev;
  c70_uc_y = NULL;
  sf_mex_assign(&c70_uc_y, sf_mex_create("y", &c70_uc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_pc_y, c70_uc_y, "VelocityControlHipDistPrev",
                  "VelocityControlHipDistPrev", 0);
  c70_vc_u = c70_pc_u.VirtualSpringMode;
  c70_vc_y = NULL;
  sf_mex_assign(&c70_vc_y, sf_mex_create("y", &c70_vc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_pc_y, c70_vc_y, "VirtualSpringMode", "VirtualSpringMode",
                  0);
  c70_wc_u = c70_pc_u.VirtualSpringStiffness;
  c70_wc_y = NULL;
  sf_mex_assign(&c70_wc_y, sf_mex_create("y", &c70_wc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_pc_y, c70_wc_y, "VirtualSpringStiffness",
                  "VirtualSpringStiffness", 0);
  c70_xc_u = c70_pc_u.VirtualSpringDamping;
  c70_xc_y = NULL;
  sf_mex_assign(&c70_xc_y, sf_mex_create("y", &c70_xc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_pc_y, c70_xc_y, "VirtualSpringDamping",
                  "VirtualSpringDamping", 0);
  c70_yc_u = c70_pc_u.VirtualSpringModAmplitude;
  c70_yc_y = NULL;
  sf_mex_assign(&c70_yc_y, sf_mex_create("y", &c70_yc_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_pc_y, c70_yc_y, "VirtualSpringModAmplitude",
                  "VirtualSpringModAmplitude", 0);
  c70_ad_u = c70_pc_u.VirtualSpringModRate;
  c70_ad_y = NULL;
  sf_mex_assign(&c70_ad_y, sf_mex_create("y", &c70_ad_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_pc_y, c70_ad_y, "VirtualSpringModRate",
                  "VirtualSpringModRate", 0);
  c70_bd_u = c70_pc_u.VirtualSpringRestPos;
  c70_bd_y = NULL;
  sf_mex_assign(&c70_bd_y, sf_mex_create("y", &c70_bd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_pc_y, c70_bd_y, "VirtualSpringRestPos",
                  "VirtualSpringRestPos", 0);
  sf_mex_addfield(c70_y, c70_pc_y, "Discrete", "Discrete", 0);
  c70_cd_u = c70_u.Output;
  c70_cd_y = NULL;
  sf_mex_assign(&c70_cd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c70_i238 = 0; c70_i238 < 78; c70_i238++) {
    c70_dd_u[c70_i238] = c70_cd_u.H0[c70_i238];
  }

  c70_dd_y = NULL;
  sf_mex_assign(&c70_dd_y, sf_mex_create("y", c70_dd_u, 0, 0U, 1U, 0U, 2, 6, 13),
                false);
  sf_mex_addfield(c70_cd_y, c70_dd_y, "H0", "H0", 0);
  for (c70_i239 = 0; c70_i239 < 36; c70_i239++) {
    c70_ed_u[c70_i239] = c70_cd_u.HAlpha[c70_i239];
  }

  c70_ed_y = NULL;
  sf_mex_assign(&c70_ed_y, sf_mex_create("y", c70_ed_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c70_cd_y, c70_ed_y, "HAlpha", "HAlpha", 0);
  for (c70_i240 = 0; c70_i240 < 2; c70_i240++) {
    c70_fd_u[c70_i240] = c70_cd_u.ThetaLimits[c70_i240];
  }

  c70_fd_y = NULL;
  sf_mex_assign(&c70_fd_y, sf_mex_create("y", c70_fd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c70_cd_y, c70_fd_y, "ThetaLimits", "ThetaLimits", 0);
  c70_gd_u = c70_cd_u.Theta;
  c70_gd_y = NULL;
  sf_mex_assign(&c70_gd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c70_hd_u = c70_gd_u.c0;
  c70_hd_y = NULL;
  sf_mex_assign(&c70_hd_y, sf_mex_create("y", &c70_hd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_gd_y, c70_hd_y, "c0", "c0", 0);
  c70_id_u = c70_gd_u.ct;
  c70_id_y = NULL;
  sf_mex_assign(&c70_id_y, sf_mex_create("y", &c70_id_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_gd_y, c70_id_y, "ct", "ct", 0);
  for (c70_i241 = 0; c70_i241 < 13; c70_i241++) {
    c70_jd_u[c70_i241] = c70_gd_u.cq[c70_i241];
  }

  c70_jd_y = NULL;
  sf_mex_assign(&c70_jd_y, sf_mex_create("y", c70_jd_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c70_gd_y, c70_jd_y, "cq", "cq", 0);
  c70_kd_u = c70_gd_u.t0;
  c70_kd_y = NULL;
  sf_mex_assign(&c70_kd_y, sf_mex_create("y", &c70_kd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_gd_y, c70_kd_y, "t0", "t0", 0);
  for (c70_i242 = 0; c70_i242 < 7; c70_i242++) {
    c70_ld_u[c70_i242] = c70_gd_u.cz[c70_i242];
  }

  c70_ld_y = NULL;
  sf_mex_assign(&c70_ld_y, sf_mex_create("y", c70_ld_u, 0, 0U, 1U, 0U, 2, 1, 7),
                false);
  sf_mex_addfield(c70_gd_y, c70_ld_y, "cz", "cz", 0);
  sf_mex_addfield(c70_cd_y, c70_gd_y, "Theta", "Theta", 0);
  c70_md_u = c70_cd_u.SaturateS;
  c70_md_y = NULL;
  sf_mex_assign(&c70_md_y, sf_mex_create("y", &c70_md_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_cd_y, c70_md_y, "SaturateS", "SaturateS", 0);
  for (c70_i243 = 0; c70_i243 < 2; c70_i243++) {
    c70_nd_u[c70_i243] = c70_cd_u.SLimits[c70_i243];
  }

  c70_nd_y = NULL;
  sf_mex_assign(&c70_nd_y, sf_mex_create("y", c70_nd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c70_cd_y, c70_nd_y, "SLimits", "SLimits", 0);
  c70_od_u = c70_cd_u.EnforceIncreasingS;
  c70_od_y = NULL;
  sf_mex_assign(&c70_od_y, sf_mex_create("y", &c70_od_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_cd_y, c70_od_y, "EnforceIncreasingS", "EnforceIncreasingS",
                  0);
  c70_pd_u = c70_cd_u.UseCorrection;
  c70_pd_y = NULL;
  sf_mex_assign(&c70_pd_y, sf_mex_create("y", &c70_pd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_cd_y, c70_pd_y, "UseCorrection", "UseCorrection", 0);
  c70_qd_u = c70_cd_u.SMaxCorrection;
  c70_qd_y = NULL;
  sf_mex_assign(&c70_qd_y, sf_mex_create("y", &c70_qd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_cd_y, c70_qd_y, "SMaxCorrection", "SMaxCorrection", 0);
  for (c70_i244 = 0; c70_i244 < 30; c70_i244++) {
    c70_rd_u[c70_i244] = c70_cd_u.HAlphaCorrection[c70_i244];
  }

  c70_rd_y = NULL;
  sf_mex_assign(&c70_rd_y, sf_mex_create("y", c70_rd_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c70_cd_y, c70_rd_y, "HAlphaCorrection", "HAlphaCorrection", 0);
  c70_sd_u = c70_cd_u.Phi;
  c70_sd_y = NULL;
  sf_mex_assign(&c70_sd_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c70_td_u = c70_sd_u.c0;
  c70_td_y = NULL;
  sf_mex_assign(&c70_td_y, sf_mex_create("y", &c70_td_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_sd_y, c70_td_y, "c0", "c0", 0);
  for (c70_i245 = 0; c70_i245 < 13; c70_i245++) {
    c70_ud_u[c70_i245] = c70_sd_u.cq[c70_i245];
  }

  c70_ud_y = NULL;
  sf_mex_assign(&c70_ud_y, sf_mex_create("y", c70_ud_u, 0, 0U, 1U, 0U, 2, 1, 13),
                false);
  sf_mex_addfield(c70_sd_y, c70_ud_y, "cq", "cq", 0);
  sf_mex_addfield(c70_cd_y, c70_sd_y, "Phi", "Phi", 0);
  for (c70_i246 = 0; c70_i246 < 20; c70_i246++) {
    c70_vd_u[c70_i246] = c70_cd_u.PhiAlpha[c70_i246];
  }

  c70_vd_y = NULL;
  sf_mex_assign(&c70_vd_y, sf_mex_create("y", c70_vd_u, 0, 0U, 1U, 0U, 2, 1, 20),
                false);
  sf_mex_addfield(c70_cd_y, c70_vd_y, "PhiAlpha", "PhiAlpha", 0);
  c70_wd_u = c70_cd_u.SaturateR;
  c70_wd_y = NULL;
  sf_mex_assign(&c70_wd_y, sf_mex_create("y", &c70_wd_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_cd_y, c70_wd_y, "SaturateR", "SaturateR", 0);
  for (c70_i247 = 0; c70_i247 < 2; c70_i247++) {
    c70_xd_u[c70_i247] = c70_cd_u.RLimits[c70_i247];
  }

  c70_xd_y = NULL;
  sf_mex_assign(&c70_xd_y, sf_mex_create("y", c70_xd_u, 0, 0U, 1U, 0U, 2, 1, 2),
                false);
  sf_mex_addfield(c70_cd_y, c70_xd_y, "RLimits", "RLimits", 0);
  for (c70_i248 = 0; c70_i248 < 30; c70_i248++) {
    c70_yd_u[c70_i248] = c70_cd_u.HBarAlpha[c70_i248];
  }

  c70_yd_y = NULL;
  sf_mex_assign(&c70_yd_y, sf_mex_create("y", c70_yd_u, 0, 0U, 1U, 0U, 2, 6, 5),
                false);
  sf_mex_addfield(c70_cd_y, c70_yd_y, "HBarAlpha", "HBarAlpha", 0);
  for (c70_i249 = 0; c70_i249 < 12; c70_i249++) {
    c70_ae_u[c70_i249] = c70_cd_u.HBarLimits[c70_i249];
  }

  c70_ae_y = NULL;
  sf_mex_assign(&c70_ae_y, sf_mex_create("y", c70_ae_u, 0, 0U, 1U, 0U, 2, 6, 2),
                false);
  sf_mex_addfield(c70_cd_y, c70_ae_y, "HBarLimits", "HBarLimits", 0);
  for (c70_i250 = 0; c70_i250 < 36; c70_i250++) {
    c70_be_u[c70_i250] = c70_cd_u.HAlphaStar[c70_i250];
  }

  c70_be_y = NULL;
  sf_mex_assign(&c70_be_y, sf_mex_create("y", c70_be_u, 0, 0U, 1U, 0U, 2, 6, 6),
                false);
  sf_mex_addfield(c70_cd_y, c70_be_y, "HAlphaStar", "HAlphaStar", 0);
  c70_ce_u = c70_cd_u.YawLimit;
  c70_ce_y = NULL;
  sf_mex_assign(&c70_ce_y, sf_mex_create("y", &c70_ce_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_cd_y, c70_ce_y, "YawLimit", "YawLimit", 0);
  c70_de_u = c70_cd_u.test;
  c70_de_y = NULL;
  sf_mex_assign(&c70_de_y, sf_mex_create("y", &c70_de_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_cd_y, c70_de_y, "test", "test", 0);
  sf_mex_addfield(c70_y, c70_cd_y, "Output", "Output", 0);
  c70_ee_u = c70_u.Feedback;
  c70_ee_y = NULL;
  sf_mex_assign(&c70_ee_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  for (c70_i251 = 0; c70_i251 < 6; c70_i251++) {
    c70_fe_u[c70_i251] = c70_ee_u.kp[c70_i251];
  }

  c70_fe_y = NULL;
  sf_mex_assign(&c70_fe_y, sf_mex_create("y", c70_fe_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_ee_y, c70_fe_y, "kp", "kp", 0);
  for (c70_i252 = 0; c70_i252 < 6; c70_i252++) {
    c70_ge_u[c70_i252] = c70_ee_u.kd[c70_i252];
  }

  c70_ge_y = NULL;
  sf_mex_assign(&c70_ge_y, sf_mex_create("y", c70_ge_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_ee_y, c70_ge_y, "kd", "kd", 0);
  for (c70_i253 = 0; c70_i253 < 2; c70_i253++) {
    c70_he_u[c70_i253] = c70_ee_u.epsilon[c70_i253];
  }

  c70_he_y = NULL;
  sf_mex_assign(&c70_he_y, sf_mex_create("y", c70_he_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c70_ee_y, c70_he_y, "epsilon", "epsilon", 0);
  for (c70_i254 = 0; c70_i254 < 2; c70_i254++) {
    c70_ie_u[c70_i254] = c70_ee_u.kff_grav[c70_i254];
  }

  c70_ie_y = NULL;
  sf_mex_assign(&c70_ie_y, sf_mex_create("y", c70_ie_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c70_ee_y, c70_ie_y, "kff_grav", "kff_grav", 0);
  c70_je_u = c70_ee_u.delta_grav;
  c70_je_y = NULL;
  sf_mex_assign(&c70_je_y, sf_mex_create("y", &c70_je_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_je_y, "delta_grav", "delta_grav", 0);
  for (c70_i255 = 0; c70_i255 < 2; c70_i255++) {
    c70_ke_u[c70_i255] = c70_ee_u.kff_decoup[c70_i255];
  }

  c70_ke_y = NULL;
  sf_mex_assign(&c70_ke_y, sf_mex_create("y", c70_ke_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c70_ee_y, c70_ke_y, "kff_decoup", "kff_decoup", 0);
  for (c70_i256 = 0; c70_i256 < 2; c70_i256++) {
    c70_le_u[c70_i256] = c70_ee_u.kd_torso[c70_i256];
  }

  c70_le_y = NULL;
  sf_mex_assign(&c70_le_y, sf_mex_create("y", c70_le_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c70_ee_y, c70_le_y, "kd_torso", "kd_torso", 0);
  c70_me_u = c70_ee_u.kp_2dof;
  c70_me_y = NULL;
  sf_mex_assign(&c70_me_y, sf_mex_create("y", &c70_me_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_me_y, "kp_2dof", "kp_2dof", 0);
  c70_ne_u = c70_ee_u.kd_2dof;
  c70_ne_y = NULL;
  sf_mex_assign(&c70_ne_y, sf_mex_create("y", &c70_ne_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_ne_y, "kd_2dof", "kd_2dof", 0);
  c70_oe_u = c70_ee_u.kpre_2dof;
  c70_oe_y = NULL;
  sf_mex_assign(&c70_oe_y, sf_mex_create("y", &c70_oe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_oe_y, "kpre_2dof", "kpre_2dof", 0);
  c70_pe_u = c70_ee_u.kp_lat;
  c70_pe_y = NULL;
  sf_mex_assign(&c70_pe_y, sf_mex_create("y", &c70_pe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_pe_y, "kp_lat", "kp_lat", 0);
  c70_qe_u = c70_ee_u.kd_lat;
  c70_qe_y = NULL;
  sf_mex_assign(&c70_qe_y, sf_mex_create("y", &c70_qe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_qe_y, "kd_lat", "kd_lat", 0);
  c70_re_u = c70_ee_u.q3d_min_lat;
  c70_re_y = NULL;
  sf_mex_assign(&c70_re_y, sf_mex_create("y", &c70_re_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_re_y, "q3d_min_lat", "q3d_min_lat", 0);
  c70_se_u = c70_ee_u.q3d_max_lat;
  c70_se_y = NULL;
  sf_mex_assign(&c70_se_y, sf_mex_create("y", &c70_se_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_se_y, "q3d_max_lat", "q3d_max_lat", 0);
  c70_te_u = c70_ee_u.w_torso_lat;
  c70_te_y = NULL;
  sf_mex_assign(&c70_te_y, sf_mex_create("y", &c70_te_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_te_y, "w_torso_lat", "w_torso_lat", 0);
  for (c70_i257 = 0; c70_i257 < 6; c70_i257++) {
    c70_ue_u[c70_i257] = c70_ee_u.u_ff[c70_i257];
  }

  c70_ue_y = NULL;
  sf_mex_assign(&c70_ue_y, sf_mex_create("y", c70_ue_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_ee_y, c70_ue_y, "u_ff", "u_ff", 0);
  c70_ve_u = c70_ee_u.LateralControlMode;
  c70_ve_y = NULL;
  sf_mex_assign(&c70_ve_y, sf_mex_create("y", &c70_ve_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_ve_y, "LateralControlMode", "LateralControlMode",
                  0);
  c70_we_u = c70_ee_u.DecouplingMode;
  c70_we_y = NULL;
  sf_mex_assign(&c70_we_y, sf_mex_create("y", &c70_we_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_we_y, "DecouplingMode", "DecouplingMode", 0);
  c70_xe_u = c70_ee_u.Use2DOF;
  c70_xe_y = NULL;
  sf_mex_assign(&c70_xe_y, sf_mex_create("y", &c70_xe_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_xe_y, "Use2DOF", "Use2DOF", 0);
  c70_ye_u = c70_ee_u.UseDSGravComp;
  c70_ye_y = NULL;
  sf_mex_assign(&c70_ye_y, sf_mex_create("y", &c70_ye_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_ye_y, "UseDSGravComp", "UseDSGravComp", 0);
  c70_af_u = c70_ee_u.lat_bias;
  c70_af_y = NULL;
  sf_mex_assign(&c70_af_y, sf_mex_create("y", &c70_af_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_af_y, "lat_bias", "lat_bias", 0);
  c70_bf_u = c70_ee_u.lat_bias2;
  c70_bf_y = NULL;
  sf_mex_assign(&c70_bf_y, sf_mex_create("y", &c70_bf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_bf_y, "lat_bias2", "lat_bias2", 0);
  c70_cf_u = c70_ee_u.linkFeedback;
  c70_cf_y = NULL;
  sf_mex_assign(&c70_cf_y, sf_mex_create("y", &c70_cf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_cf_y, "linkFeedback", "linkFeedback", 0);
  c70_df_u = c70_ee_u.RIO;
  c70_df_y = NULL;
  sf_mex_assign(&c70_df_y, sf_mex_create("y", &c70_df_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_df_y, "RIO", "RIO", 0);
  c70_ef_u = c70_ee_u.SelectFeedforward;
  c70_ef_y = NULL;
  sf_mex_assign(&c70_ef_y, sf_mex_create("y", &c70_ef_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_ef_y, "SelectFeedforward", "SelectFeedforward",
                  0);
  for (c70_i258 = 0; c70_i258 < 6; c70_i258++) {
    c70_ff_u[c70_i258] = c70_ee_u.FeedforwardGain[c70_i258];
  }

  c70_ff_y = NULL;
  sf_mex_assign(&c70_ff_y, sf_mex_create("y", c70_ff_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_addfield(c70_ee_y, c70_ff_y, "FeedforwardGain", "FeedforwardGain", 0);
  c70_gf_u = c70_ee_u.EnableFeedforwardOnStep;
  c70_gf_y = NULL;
  sf_mex_assign(&c70_gf_y, sf_mex_create("y", &c70_gf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_ee_y, c70_gf_y, "EnableFeedforwardOnStep",
                  "EnableFeedforwardOnStep", 0);
  sf_mex_addfield(c70_y, c70_ee_y, "Feedback", "Feedback", 0);
  c70_hf_u = c70_u.Saturation;
  c70_hf_y = NULL;
  sf_mex_assign(&c70_hf_y, sf_mex_createstruct("structure", 2, 1, 1), false);
  c70_if_u = c70_hf_u.UseQPSaturation;
  c70_if_y = NULL;
  sf_mex_assign(&c70_if_y, sf_mex_create("y", &c70_if_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_hf_y, c70_if_y, "UseQPSaturation", "UseQPSaturation", 0);
  for (c70_i259 = 0; c70_i259 < 2; c70_i259++) {
    c70_jf_u[c70_i259] = c70_hf_u.QPWeight[c70_i259];
  }

  c70_jf_y = NULL;
  sf_mex_assign(&c70_jf_y, sf_mex_create("y", c70_jf_u, 0, 0U, 1U, 0U, 1, 2),
                false);
  sf_mex_addfield(c70_hf_y, c70_jf_y, "QPWeight", "QPWeight", 0);
  c70_kf_u = c70_hf_u.UseKASaturation;
  c70_kf_y = NULL;
  sf_mex_assign(&c70_kf_y, sf_mex_create("y", &c70_kf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_hf_y, c70_kf_y, "UseKASaturation", "UseKASaturation", 0);
  c70_lf_u = c70_hf_u.KASaturationS1;
  c70_lf_y = NULL;
  sf_mex_assign(&c70_lf_y, sf_mex_create("y", &c70_lf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_hf_y, c70_lf_y, "KASaturationS1", "KASaturationS1", 0);
  c70_mf_u = c70_hf_u.KASaturationS2;
  c70_mf_y = NULL;
  sf_mex_assign(&c70_mf_y, sf_mex_create("y", &c70_mf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_hf_y, c70_mf_y, "KASaturationS2", "KASaturationS2", 0);
  c70_nf_u = c70_hf_u.KASaturationEarly;
  c70_nf_y = NULL;
  sf_mex_assign(&c70_nf_y, sf_mex_create("y", &c70_nf_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_hf_y, c70_nf_y, "KASaturationEarly", "KASaturationEarly",
                  0);
  c70_of_u = c70_hf_u.KASaturationMax;
  c70_of_y = NULL;
  sf_mex_assign(&c70_of_y, sf_mex_create("y", &c70_of_u, 0, 0U, 0U, 0U, 0),
                false);
  sf_mex_addfield(c70_hf_y, c70_of_y, "KASaturationMax", "KASaturationMax", 0);
  sf_mex_addfield(c70_y, c70_hf_y, "Saturation", "Saturation", 0);
  sf_mex_assign(&c70_mxArrayOutData, c70_y, false);
  return c70_mxArrayOutData;
}

static void c70_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_b_ControlParams1, const char_T
  *c70_identifier, c70_ControlParamsBus *c70_y)
{
  emlrtMsgIdentifier c70_thisId;
  c70_thisId.fIdentifier = c70_identifier;
  c70_thisId.fParent = NULL;
  c70_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c70_b_ControlParams1),
    &c70_thisId, c70_y);
  sf_mex_destroy(&c70_b_ControlParams1);
}

static void c70_b_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_ControlParamsBus *c70_y)
{
  emlrtMsgIdentifier c70_thisId;
  static const char * c70_fieldNames[5] = { "Supervisory", "Discrete", "Output",
    "Feedback", "Saturation" };

  c70_thisId.fParent = c70_parentId;
  sf_mex_check_struct(c70_parentId, c70_u, 5, c70_fieldNames, 0U, NULL);
  c70_thisId.fIdentifier = "Supervisory";
  c70_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "Supervisory", "Supervisory", 0)), &c70_thisId, &c70_y->Supervisory);
  c70_thisId.fIdentifier = "Discrete";
  c70_j_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "Discrete", "Discrete", 0)), &c70_thisId, &c70_y->Discrete);
  c70_thisId.fIdentifier = "Output";
  c70_k_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "Output", "Output", 0)), &c70_thisId, &c70_y->Output);
  c70_thisId.fIdentifier = "Feedback";
  c70_u_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "Feedback", "Feedback", 0)), &c70_thisId, &c70_y->Feedback);
  c70_thisId.fIdentifier = "Saturation";
  c70_y->Saturation = c70_v_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "Saturation", "Saturation", 0)), &c70_thisId);
  sf_mex_destroy(&c70_u);
}

static void c70_c_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_SupervisoryParamsBus *c70_y)
{
  emlrtMsgIdentifier c70_thisId;
  static const char * c70_fieldNames[63] = { "EnableSwapOnKAAccel",
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
    "DesiredYawOffset", "dx_cmd", "ForBackward", "EnableFrictionID",
    "ResetFrictionPosing", "MoveLegIndex", "dy_cmd", "TauDelay",
    "TrackFrequency", "EnablePDControl", "TorqueAmp", "hdPosing" };

  c70_thisId.fParent = c70_parentId;
  sf_mex_check_struct(c70_parentId, c70_u, 63, c70_fieldNames, 0U, NULL);
  c70_thisId.fIdentifier = "EnableSwapOnKAAccel";
  c70_y->EnableSwapOnKAAccel = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "EnableSwapOnKAAccel", "EnableSwapOnKAAccel", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "EnableSwapOnKASpring";
  c70_y->EnableSwapOnKASpring = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "EnableSwapOnKASpring", "EnableSwapOnKASpring", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "EnableBackwardSwap";
  c70_y->EnableBackwardSwap = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "EnableBackwardSwap", "EnableBackwardSwap", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "ImpactThresholdKAAccel";
  c70_y->ImpactThresholdKAAccel = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "ImpactThresholdKAAccel",
    "ImpactThresholdKAAccel", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "ImpactThresholdKASpringAbs";
  c70_y->ImpactThresholdKASpringAbs = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "ImpactThresholdKASpringAbs",
    "ImpactThresholdKASpringAbs", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "ImpactThresholdKASpringRel";
  c70_y->ImpactThresholdKASpringRel = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "ImpactThresholdKASpringRel",
    "ImpactThresholdKASpringRel", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "SwapThresholdS";
  c70_y->SwapThresholdS = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "SwapThresholdS", "SwapThresholdS", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "AllowDoubleSupport";
  c70_y->AllowDoubleSupport = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "AllowDoubleSupport", "AllowDoubleSupport", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "UseGaitTransition";
  c70_y->UseGaitTransition = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "UseGaitTransition", "UseGaitTransition", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "NumTransitionSteps";
  c70_y->NumTransitionSteps = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "NumTransitionSteps", "NumTransitionSteps", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "TransitionThresholdTorsoVel";
  c70_y->TransitionThresholdTorsoVel = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "TransitionThresholdTorsoVel",
    "TransitionThresholdTorsoVel", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "KAInjection";
  c70_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "KAInjection", "KAInjection", 0)), &c70_thisId, c70_y->KAInjection);
  c70_thisId.fIdentifier = "MinDeltaThetaTransition";
  c70_y->MinDeltaThetaTransition = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "MinDeltaThetaTransition",
    "MinDeltaThetaTransition", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "StartSecondGaitOnStep";
  c70_y->StartSecondGaitOnStep = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "StartSecondGaitOnStep",
    "StartSecondGaitOnStep", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "VBLAParams";
  c70_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "VBLAParams", "VBLAParams", 0)), &c70_thisId, c70_y->VBLAParams);
  c70_thisId.fIdentifier = "BalanceParams";
  c70_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "BalanceParams", "BalanceParams", 0)), &c70_thisId, c70_y->BalanceParams);
  c70_thisId.fIdentifier = "GaitTweaks";
  c70_h_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "GaitTweaks", "GaitTweaks", 0)), &c70_thisId, c70_y->GaitTweaks);
  c70_thisId.fIdentifier = "TStepInitial";
  c70_y->TStepInitial = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "TStepInitial", "TStepInitial", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "TMaxUpdate";
  c70_y->TMaxUpdate = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "TMaxUpdate", "TMaxUpdate", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "RunMode";
  c70_y->RunMode = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "RunMode", "RunMode", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "UseAbsoluteSwingLA";
  c70_y->UseAbsoluteSwingLA = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "UseAbsoluteSwingLA", "UseAbsoluteSwingLA", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "ErrorZeroFactor";
  c70_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "ErrorZeroFactor", "ErrorZeroFactor", 0)), &c70_thisId,
    c70_y->ErrorZeroFactor);
  c70_thisId.fIdentifier = "ErrorVelZeroFactor";
  c70_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "ErrorVelZeroFactor", "ErrorVelZeroFactor", 0)), &c70_thisId,
    c70_y->ErrorVelZeroFactor);
  c70_thisId.fIdentifier = "StanceLegInit";
  c70_y->StanceLegInit = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "StanceLegInit", "StanceLegInit", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "ControllerModeInit";
  c70_y->ControllerModeInit = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "ControllerModeInit", "ControllerModeInit", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "UsePosingControl";
  c70_y->UsePosingControl = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "UsePosingControl", "UsePosingControl", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "TPosing";
  c70_y->TPosing = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "TPosing", "TPosing", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "TorsoBackAngle";
  c70_y->TorsoBackAngle = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "TorsoBackAngle", "TorsoBackAngle", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "TorsoBackOnStep";
  c70_y->TorsoBackOnStep = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "TorsoBackOnStep", "TorsoBackOnStep", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "EnergyControlGain";
  c70_y->EnergyControlGain = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "EnergyControlGain", "EnergyControlGain", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "EnergyControlPhi0";
  c70_y->EnergyControlPhi0 = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "EnergyControlPhi0", "EnergyControlPhi0", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "VelocityControlTorsoMax";
  c70_y->VelocityControlTorsoMax = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "VelocityControlTorsoMax",
    "VelocityControlTorsoMax", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "VelocityControlTorsoMin";
  c70_y->VelocityControlTorsoMin = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "VelocityControlTorsoMin",
    "VelocityControlTorsoMin", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "VelocityControlTorsoGain";
  c70_y->VelocityControlTorsoGain = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "VelocityControlTorsoGain",
    "VelocityControlTorsoGain", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "VelocityControlTorsoV0";
  c70_y->VelocityControlTorsoV0 = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "VelocityControlTorsoV0",
    "VelocityControlTorsoV0", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "MinDeltaTheta";
  c70_y->MinDeltaTheta = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "MinDeltaTheta", "MinDeltaTheta", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "Theta0";
  c70_y->Theta0 = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "Theta0", "Theta0", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "KThetaPlus";
  c70_y->KThetaPlus = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "KThetaPlus", "KThetaPlus", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "KThetaMinus";
  c70_y->KThetaMinus = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "KThetaMinus", "KThetaMinus", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "RollPhaseVelocityThresh";
  c70_y->RollPhaseVelocityThresh = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "RollPhaseVelocityThresh",
    "RollPhaseVelocityThresh", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "RollPhaseSThresh";
  c70_y->RollPhaseSThresh = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "RollPhaseSThresh", "RollPhaseSThresh", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "MaxError";
  c70_y->MaxError = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "MaxError", "MaxError", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "MaxErrorVel";
  c70_y->MaxErrorVel = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "MaxErrorVel", "MaxErrorVel", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "MaxErrorCount";
  c70_y->MaxErrorCount = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "MaxErrorCount", "MaxErrorCount", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "K1MidStanceUpdate";
  c70_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "K1MidStanceUpdate", "K1MidStanceUpdate", 0)), &c70_thisId,
    c70_y->K1MidStanceUpdate);
  c70_thisId.fIdentifier = "K2MidStanceUpdate";
  c70_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "K2MidStanceUpdate", "K2MidStanceUpdate", 0)), &c70_thisId,
    c70_y->K2MidStanceUpdate);
  c70_thisId.fIdentifier = "EnableVelocityBasedUpdate";
  c70_y->EnableVelocityBasedUpdate = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "EnableVelocityBasedUpdate",
    "EnableVelocityBasedUpdate", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "VelocityBasedUpdateK1";
  c70_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "VelocityBasedUpdateK1", "VelocityBasedUpdateK1", 0)), &c70_thisId,
    c70_y->VelocityBasedUpdateK1);
  c70_thisId.fIdentifier = "VelocityBasedUpdateK2";
  c70_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "VelocityBasedUpdateK2", "VelocityBasedUpdateK2", 0)), &c70_thisId,
    c70_y->VelocityBasedUpdateK2);
  c70_thisId.fIdentifier = "VelocityBasedUpdateDTheta0";
  c70_y->VelocityBasedUpdateDTheta0 = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "VelocityBasedUpdateDTheta0",
    "VelocityBasedUpdateDTheta0", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "VelocityBasedUpdateLimits";
  c70_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "VelocityBasedUpdateLimits", "VelocityBasedUpdateLimits", 0)), &c70_thisId,
    c70_y->VelocityBasedUpdateLimits);
  c70_thisId.fIdentifier = "DesiredYawOffset";
  c70_y->DesiredYawOffset = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "DesiredYawOffset", "DesiredYawOffset", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "dx_cmd";
  c70_y->dx_cmd = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "dx_cmd", "dx_cmd", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "ForBackward";
  c70_y->ForBackward = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "ForBackward", "ForBackward", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "EnableFrictionID";
  c70_y->EnableFrictionID = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "EnableFrictionID", "EnableFrictionID", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "ResetFrictionPosing";
  c70_y->ResetFrictionPosing = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "ResetFrictionPosing", "ResetFrictionPosing", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "MoveLegIndex";
  c70_y->MoveLegIndex = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "MoveLegIndex", "MoveLegIndex", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "dy_cmd";
  c70_y->dy_cmd = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "dy_cmd", "dy_cmd", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "TauDelay";
  c70_y->TauDelay = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "TauDelay", "TauDelay", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "TrackFrequency";
  c70_y->TrackFrequency = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "TrackFrequency", "TrackFrequency", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "EnablePDControl";
  c70_y->EnablePDControl = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "EnablePDControl", "EnablePDControl", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "TorqueAmp";
  c70_y->TorqueAmp = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "TorqueAmp", "TorqueAmp", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "hdPosing";
  c70_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "hdPosing", "hdPosing", 0)), &c70_thisId, c70_y->hdPosing);
  sf_mex_destroy(&c70_u);
}

static real_T c70_d_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId)
{
  real_T c70_y;
  real_T c70_d0;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), &c70_d0, 1, 0, 0U, 0, 0U, 0);
  c70_y = c70_d0;
  sf_mex_destroy(&c70_u);
  return c70_y;
}

static void c70_e_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[2])
{
  real_T c70_dv0[2];
  int32_T c70_i260;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), c70_dv0, 1, 0, 0U, 1, 0U, 1, 2);
  for (c70_i260 = 0; c70_i260 < 2; c70_i260++) {
    c70_y[c70_i260] = c70_dv0[c70_i260];
  }

  sf_mex_destroy(&c70_u);
}

static void c70_f_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[6])
{
  real_T c70_dv1[6];
  int32_T c70_i261;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), c70_dv1, 1, 0, 0U, 1, 0U, 1, 6);
  for (c70_i261 = 0; c70_i261 < 6; c70_i261++) {
    c70_y[c70_i261] = c70_dv1[c70_i261];
  }

  sf_mex_destroy(&c70_u);
}

static void c70_g_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[13])
{
  real_T c70_dv2[13];
  int32_T c70_i262;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), c70_dv2, 1, 0, 0U, 1, 0U, 1, 13);
  for (c70_i262 = 0; c70_i262 < 13; c70_i262++) {
    c70_y[c70_i262] = c70_dv2[c70_i262];
  }

  sf_mex_destroy(&c70_u);
}

static void c70_h_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[5])
{
  real_T c70_dv3[5];
  int32_T c70_i263;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), c70_dv3, 1, 0, 0U, 1, 0U, 1, 5);
  for (c70_i263 = 0; c70_i263 < 5; c70_i263++) {
    c70_y[c70_i263] = c70_dv3[c70_i263];
  }

  sf_mex_destroy(&c70_u);
}

static void c70_i_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[12])
{
  real_T c70_dv4[12];
  int32_T c70_i264;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), c70_dv4, 1, 0, 0U, 1, 0U, 2, 6,
                2);
  for (c70_i264 = 0; c70_i264 < 12; c70_i264++) {
    c70_y[c70_i264] = c70_dv4[c70_i264];
  }

  sf_mex_destroy(&c70_u);
}

static void c70_j_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_DiscreteParamsBus *c70_y)
{
  emlrtMsgIdentifier c70_thisId;
  static const char * c70_fieldNames[11] = { "TLastUpdate",
    "VelocityControlLADelta", "VelocityControlTorsoDelta",
    "VelocityControlHipDistCur", "VelocityControlHipDistPrev",
    "VirtualSpringMode", "VirtualSpringStiffness", "VirtualSpringDamping",
    "VirtualSpringModAmplitude", "VirtualSpringModRate", "VirtualSpringRestPos"
  };

  c70_thisId.fParent = c70_parentId;
  sf_mex_check_struct(c70_parentId, c70_u, 11, c70_fieldNames, 0U, NULL);
  c70_thisId.fIdentifier = "TLastUpdate";
  c70_y->TLastUpdate = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "TLastUpdate", "TLastUpdate", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "VelocityControlLADelta";
  c70_y->VelocityControlLADelta = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "VelocityControlLADelta",
    "VelocityControlLADelta", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "VelocityControlTorsoDelta";
  c70_y->VelocityControlTorsoDelta = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "VelocityControlTorsoDelta",
    "VelocityControlTorsoDelta", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "VelocityControlHipDistCur";
  c70_y->VelocityControlHipDistCur = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "VelocityControlHipDistCur",
    "VelocityControlHipDistCur", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "VelocityControlHipDistPrev";
  c70_y->VelocityControlHipDistPrev = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "VelocityControlHipDistPrev",
    "VelocityControlHipDistPrev", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "VirtualSpringMode";
  c70_y->VirtualSpringMode = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "VirtualSpringMode", "VirtualSpringMode", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "VirtualSpringStiffness";
  c70_y->VirtualSpringStiffness = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "VirtualSpringStiffness",
    "VirtualSpringStiffness", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "VirtualSpringDamping";
  c70_y->VirtualSpringDamping = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "VirtualSpringDamping", "VirtualSpringDamping", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "VirtualSpringModAmplitude";
  c70_y->VirtualSpringModAmplitude = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "VirtualSpringModAmplitude",
    "VirtualSpringModAmplitude", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "VirtualSpringModRate";
  c70_y->VirtualSpringModRate = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "VirtualSpringModRate", "VirtualSpringModRate", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "VirtualSpringRestPos";
  c70_y->VirtualSpringRestPos = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "VirtualSpringRestPos", "VirtualSpringRestPos", 0)),
    &c70_thisId);
  sf_mex_destroy(&c70_u);
}

static void c70_k_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_OutputParamsBus *c70_y)
{
  emlrtMsgIdentifier c70_thisId;
  static const char * c70_fieldNames[19] = { "H0", "HAlpha", "ThetaLimits",
    "Theta", "SaturateS", "SLimits", "EnforceIncreasingS", "UseCorrection",
    "SMaxCorrection", "HAlphaCorrection", "Phi", "PhiAlpha", "SaturateR",
    "RLimits", "HBarAlpha", "HBarLimits", "HAlphaStar", "YawLimit", "test" };

  c70_thisId.fParent = c70_parentId;
  sf_mex_check_struct(c70_parentId, c70_u, 19, c70_fieldNames, 0U, NULL);
  c70_thisId.fIdentifier = "H0";
  c70_l_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u, "H0",
    "H0", 0)), &c70_thisId, c70_y->H0);
  c70_thisId.fIdentifier = "HAlpha";
  c70_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "HAlpha", "HAlpha", 0)), &c70_thisId, c70_y->HAlpha);
  c70_thisId.fIdentifier = "ThetaLimits";
  c70_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "ThetaLimits", "ThetaLimits", 0)), &c70_thisId, c70_y->ThetaLimits);
  c70_thisId.fIdentifier = "Theta";
  c70_o_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "Theta", "Theta", 0)), &c70_thisId, &c70_y->Theta);
  c70_thisId.fIdentifier = "SaturateS";
  c70_y->SaturateS = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "SaturateS", "SaturateS", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "SLimits";
  c70_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "SLimits", "SLimits", 0)), &c70_thisId, c70_y->SLimits);
  c70_thisId.fIdentifier = "EnforceIncreasingS";
  c70_y->EnforceIncreasingS = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "EnforceIncreasingS", "EnforceIncreasingS", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "UseCorrection";
  c70_y->UseCorrection = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "UseCorrection", "UseCorrection", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "SMaxCorrection";
  c70_y->SMaxCorrection = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "SMaxCorrection", "SMaxCorrection", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "HAlphaCorrection";
  c70_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "HAlphaCorrection", "HAlphaCorrection", 0)), &c70_thisId,
    c70_y->HAlphaCorrection);
  c70_thisId.fIdentifier = "Phi";
  c70_s_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u, "Phi",
    "Phi", 0)), &c70_thisId, &c70_y->Phi);
  c70_thisId.fIdentifier = "PhiAlpha";
  c70_t_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "PhiAlpha", "PhiAlpha", 0)), &c70_thisId, c70_y->PhiAlpha);
  c70_thisId.fIdentifier = "SaturateR";
  c70_y->SaturateR = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "SaturateR", "SaturateR", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "RLimits";
  c70_n_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "RLimits", "RLimits", 0)), &c70_thisId, c70_y->RLimits);
  c70_thisId.fIdentifier = "HBarAlpha";
  c70_r_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "HBarAlpha", "HBarAlpha", 0)), &c70_thisId, c70_y->HBarAlpha);
  c70_thisId.fIdentifier = "HBarLimits";
  c70_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "HBarLimits", "HBarLimits", 0)), &c70_thisId, c70_y->HBarLimits);
  c70_thisId.fIdentifier = "HAlphaStar";
  c70_m_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "HAlphaStar", "HAlphaStar", 0)), &c70_thisId, c70_y->HAlphaStar);
  c70_thisId.fIdentifier = "YawLimit";
  c70_y->YawLimit = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "YawLimit", "YawLimit", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "test";
  c70_y->test = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
                                        (c70_u, "test", "test", 0)), &c70_thisId);
  sf_mex_destroy(&c70_u);
}

static void c70_l_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[78])
{
  real_T c70_dv5[78];
  int32_T c70_i265;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), c70_dv5, 1, 0, 0U, 1, 0U, 2, 6,
                13);
  for (c70_i265 = 0; c70_i265 < 78; c70_i265++) {
    c70_y[c70_i265] = c70_dv5[c70_i265];
  }

  sf_mex_destroy(&c70_u);
}

static void c70_m_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[36])
{
  real_T c70_dv6[36];
  int32_T c70_i266;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), c70_dv6, 1, 0, 0U, 1, 0U, 2, 6,
                6);
  for (c70_i266 = 0; c70_i266 < 36; c70_i266++) {
    c70_y[c70_i266] = c70_dv6[c70_i266];
  }

  sf_mex_destroy(&c70_u);
}

static void c70_n_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[2])
{
  real_T c70_dv7[2];
  int32_T c70_i267;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), c70_dv7, 1, 0, 0U, 1, 0U, 2, 1,
                2);
  for (c70_i267 = 0; c70_i267 < 2; c70_i267++) {
    c70_y[c70_i267] = c70_dv7[c70_i267];
  }

  sf_mex_destroy(&c70_u);
}

static void c70_o_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_ThetaParamsBus *c70_y)
{
  emlrtMsgIdentifier c70_thisId;
  static const char * c70_fieldNames[5] = { "c0", "ct", "cq", "t0", "cz" };

  c70_thisId.fParent = c70_parentId;
  sf_mex_check_struct(c70_parentId, c70_u, 5, c70_fieldNames, 0U, NULL);
  c70_thisId.fIdentifier = "c0";
  c70_y->c0 = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c70_u, "c0", "c0", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "ct";
  c70_y->ct = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c70_u, "ct", "ct", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "cq";
  c70_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u, "cq",
    "cq", 0)), &c70_thisId, c70_y->cq);
  c70_thisId.fIdentifier = "t0";
  c70_y->t0 = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c70_u, "t0", "t0", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "cz";
  c70_q_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u, "cz",
    "cz", 0)), &c70_thisId, c70_y->cz);
  sf_mex_destroy(&c70_u);
}

static void c70_p_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[13])
{
  real_T c70_dv8[13];
  int32_T c70_i268;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), c70_dv8, 1, 0, 0U, 1, 0U, 2, 1,
                13);
  for (c70_i268 = 0; c70_i268 < 13; c70_i268++) {
    c70_y[c70_i268] = c70_dv8[c70_i268];
  }

  sf_mex_destroy(&c70_u);
}

static void c70_q_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[7])
{
  real_T c70_dv9[7];
  int32_T c70_i269;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), c70_dv9, 1, 0, 0U, 1, 0U, 2, 1,
                7);
  for (c70_i269 = 0; c70_i269 < 7; c70_i269++) {
    c70_y[c70_i269] = c70_dv9[c70_i269];
  }

  sf_mex_destroy(&c70_u);
}

static void c70_r_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[30])
{
  real_T c70_dv10[30];
  int32_T c70_i270;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), c70_dv10, 1, 0, 0U, 1, 0U, 2, 6,
                5);
  for (c70_i270 = 0; c70_i270 < 30; c70_i270++) {
    c70_y[c70_i270] = c70_dv10[c70_i270];
  }

  sf_mex_destroy(&c70_u);
}

static void c70_s_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_PhiParamsBus *c70_y)
{
  emlrtMsgIdentifier c70_thisId;
  static const char * c70_fieldNames[2] = { "c0", "cq" };

  c70_thisId.fParent = c70_parentId;
  sf_mex_check_struct(c70_parentId, c70_u, 2, c70_fieldNames, 0U, NULL);
  c70_thisId.fIdentifier = "c0";
  c70_y->c0 = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c70_u, "c0", "c0", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "cq";
  c70_p_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u, "cq",
    "cq", 0)), &c70_thisId, c70_y->cq);
  sf_mex_destroy(&c70_u);
}

static void c70_t_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  real_T c70_y[20])
{
  real_T c70_dv11[20];
  int32_T c70_i271;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), c70_dv11, 1, 0, 0U, 1, 0U, 2, 1,
                20);
  for (c70_i271 = 0; c70_i271 < 20; c70_i271++) {
    c70_y[c70_i271] = c70_dv11[c70_i271];
  }

  sf_mex_destroy(&c70_u);
}

static void c70_u_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId,
  c70_FeedbackParamsBus *c70_y)
{
  emlrtMsgIdentifier c70_thisId;
  static const char * c70_fieldNames[27] = { "kp", "kd", "epsilon", "kff_grav",
    "delta_grav", "kff_decoup", "kd_torso", "kp_2dof", "kd_2dof", "kpre_2dof",
    "kp_lat", "kd_lat", "q3d_min_lat", "q3d_max_lat", "w_torso_lat", "u_ff",
    "LateralControlMode", "DecouplingMode", "Use2DOF", "UseDSGravComp",
    "lat_bias", "lat_bias2", "linkFeedback", "RIO", "SelectFeedforward",
    "FeedforwardGain", "EnableFeedforwardOnStep" };

  c70_thisId.fParent = c70_parentId;
  sf_mex_check_struct(c70_parentId, c70_u, 27, c70_fieldNames, 0U, NULL);
  c70_thisId.fIdentifier = "kp";
  c70_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u, "kp",
    "kp", 0)), &c70_thisId, c70_y->kp);
  c70_thisId.fIdentifier = "kd";
  c70_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u, "kd",
    "kd", 0)), &c70_thisId, c70_y->kd);
  c70_thisId.fIdentifier = "epsilon";
  c70_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "epsilon", "epsilon", 0)), &c70_thisId, c70_y->epsilon);
  c70_thisId.fIdentifier = "kff_grav";
  c70_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "kff_grav", "kff_grav", 0)), &c70_thisId, c70_y->kff_grav);
  c70_thisId.fIdentifier = "delta_grav";
  c70_y->delta_grav = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "delta_grav", "delta_grav", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "kff_decoup";
  c70_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "kff_decoup", "kff_decoup", 0)), &c70_thisId, c70_y->kff_decoup);
  c70_thisId.fIdentifier = "kd_torso";
  c70_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "kd_torso", "kd_torso", 0)), &c70_thisId, c70_y->kd_torso);
  c70_thisId.fIdentifier = "kp_2dof";
  c70_y->kp_2dof = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "kp_2dof", "kp_2dof", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "kd_2dof";
  c70_y->kd_2dof = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "kd_2dof", "kd_2dof", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "kpre_2dof";
  c70_y->kpre_2dof = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "kpre_2dof", "kpre_2dof", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "kp_lat";
  c70_y->kp_lat = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "kp_lat", "kp_lat", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "kd_lat";
  c70_y->kd_lat = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "kd_lat", "kd_lat", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "q3d_min_lat";
  c70_y->q3d_min_lat = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "q3d_min_lat", "q3d_min_lat", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "q3d_max_lat";
  c70_y->q3d_max_lat = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "q3d_max_lat", "q3d_max_lat", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "w_torso_lat";
  c70_y->w_torso_lat = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "w_torso_lat", "w_torso_lat", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "u_ff";
  c70_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u, "u_ff",
    "u_ff", 0)), &c70_thisId, c70_y->u_ff);
  c70_thisId.fIdentifier = "LateralControlMode";
  c70_y->LateralControlMode = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "LateralControlMode", "LateralControlMode", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "DecouplingMode";
  c70_y->DecouplingMode = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "DecouplingMode", "DecouplingMode", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "Use2DOF";
  c70_y->Use2DOF = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "Use2DOF", "Use2DOF", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "UseDSGravComp";
  c70_y->UseDSGravComp = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "UseDSGravComp", "UseDSGravComp", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "lat_bias";
  c70_y->lat_bias = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "lat_bias", "lat_bias", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "lat_bias2";
  c70_y->lat_bias2 = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "lat_bias2", "lat_bias2", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "linkFeedback";
  c70_y->linkFeedback = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "linkFeedback", "linkFeedback", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "RIO";
  c70_y->RIO = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield
    (c70_u, "RIO", "RIO", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "SelectFeedforward";
  c70_y->SelectFeedforward = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "SelectFeedforward", "SelectFeedforward", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "FeedforwardGain";
  c70_f_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "FeedforwardGain", "FeedforwardGain", 0)), &c70_thisId,
    c70_y->FeedforwardGain);
  c70_thisId.fIdentifier = "EnableFeedforwardOnStep";
  c70_y->EnableFeedforwardOnStep = c70_d_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getfield(c70_u, "EnableFeedforwardOnStep",
    "EnableFeedforwardOnStep", 0)), &c70_thisId);
  sf_mex_destroy(&c70_u);
}

static c70_SaturationParamsBus c70_v_emlrt_marshallIn
  (SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance, const mxArray *c70_u, const
   emlrtMsgIdentifier *c70_parentId)
{
  c70_SaturationParamsBus c70_y;
  emlrtMsgIdentifier c70_thisId;
  static const char * c70_fieldNames[7] = { "UseQPSaturation", "QPWeight",
    "UseKASaturation", "KASaturationS1", "KASaturationS2", "KASaturationEarly",
    "KASaturationMax" };

  c70_thisId.fParent = c70_parentId;
  sf_mex_check_struct(c70_parentId, c70_u, 7, c70_fieldNames, 0U, NULL);
  c70_thisId.fIdentifier = "UseQPSaturation";
  c70_y.UseQPSaturation = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "UseQPSaturation", "UseQPSaturation", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "QPWeight";
  c70_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getfield(c70_u,
    "QPWeight", "QPWeight", 0)), &c70_thisId, c70_y.QPWeight);
  c70_thisId.fIdentifier = "UseKASaturation";
  c70_y.UseKASaturation = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "UseKASaturation", "UseKASaturation", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "KASaturationS1";
  c70_y.KASaturationS1 = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "KASaturationS1", "KASaturationS1", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "KASaturationS2";
  c70_y.KASaturationS2 = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "KASaturationS2", "KASaturationS2", 0)), &c70_thisId);
  c70_thisId.fIdentifier = "KASaturationEarly";
  c70_y.KASaturationEarly = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "KASaturationEarly", "KASaturationEarly", 0)),
    &c70_thisId);
  c70_thisId.fIdentifier = "KASaturationMax";
  c70_y.KASaturationMax = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getfield(c70_u, "KASaturationMax", "KASaturationMax", 0)),
    &c70_thisId);
  sf_mex_destroy(&c70_u);
  return c70_y;
}

static void c70_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c70_mxArrayInData, const char_T *c70_varName, void *c70_outData)
{
  const mxArray *c70_b_ControlParams1;
  const char_T *c70_identifier;
  emlrtMsgIdentifier c70_thisId;
  c70_ControlParamsBus c70_y;
  SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc70_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c70_b_ControlParams1 = sf_mex_dup(c70_mxArrayInData);
  c70_identifier = c70_varName;
  c70_thisId.fIdentifier = c70_identifier;
  c70_thisId.fParent = NULL;
  c70_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c70_b_ControlParams1),
    &c70_thisId, &c70_y);
  sf_mex_destroy(&c70_b_ControlParams1);
  *(c70_ControlParamsBus *)c70_outData = c70_y;
  sf_mex_destroy(&c70_mxArrayInData);
}

static const mxArray *c70_b_sf_marshallOut(void *chartInstanceVoid, void
  *c70_inData)
{
  const mxArray *c70_mxArrayOutData = NULL;
  real_T c70_u;
  const mxArray *c70_y = NULL;
  SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc70_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c70_mxArrayOutData = NULL;
  c70_u = *(real_T *)c70_inData;
  c70_y = NULL;
  sf_mex_assign(&c70_y, sf_mex_create("y", &c70_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c70_mxArrayOutData, c70_y, false);
  return c70_mxArrayOutData;
}

static const mxArray *c70_c_sf_marshallOut(void *chartInstanceVoid, void
  *c70_inData)
{
  const mxArray *c70_mxArrayOutData = NULL;
  boolean_T c70_u;
  const mxArray *c70_y = NULL;
  SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc70_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c70_mxArrayOutData = NULL;
  c70_u = *(boolean_T *)c70_inData;
  c70_y = NULL;
  sf_mex_assign(&c70_y, sf_mex_create("y", &c70_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c70_mxArrayOutData, c70_y, false);
  return c70_mxArrayOutData;
}

static void c70_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c70_mxArrayInData, const char_T *c70_varName, void *c70_outData)
{
  const mxArray *c70_nargout;
  const char_T *c70_identifier;
  emlrtMsgIdentifier c70_thisId;
  real_T c70_y;
  SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc70_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c70_nargout = sf_mex_dup(c70_mxArrayInData);
  c70_identifier = c70_varName;
  c70_thisId.fIdentifier = c70_identifier;
  c70_thisId.fParent = NULL;
  c70_y = c70_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c70_nargout),
    &c70_thisId);
  sf_mex_destroy(&c70_nargout);
  *(real_T *)c70_outData = c70_y;
  sf_mex_destroy(&c70_mxArrayInData);
}

const mxArray *sf_c70_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void)
{
  const mxArray *c70_nameCaptureInfo = NULL;
  c70_nameCaptureInfo = NULL;
  sf_mex_assign(&c70_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c70_nameCaptureInfo;
}

static const mxArray *c70_d_sf_marshallOut(void *chartInstanceVoid, void
  *c70_inData)
{
  const mxArray *c70_mxArrayOutData = NULL;
  int32_T c70_u;
  const mxArray *c70_y = NULL;
  SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc70_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c70_mxArrayOutData = NULL;
  c70_u = *(int32_T *)c70_inData;
  c70_y = NULL;
  sf_mex_assign(&c70_y, sf_mex_create("y", &c70_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c70_mxArrayOutData, c70_y, false);
  return c70_mxArrayOutData;
}

static int32_T c70_w_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId)
{
  int32_T c70_y;
  int32_T c70_i272;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), &c70_i272, 1, 6, 0U, 0, 0U, 0);
  c70_y = c70_i272;
  sf_mex_destroy(&c70_u);
  return c70_y;
}

static void c70_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c70_mxArrayInData, const char_T *c70_varName, void *c70_outData)
{
  const mxArray *c70_b_sfEvent;
  const char_T *c70_identifier;
  emlrtMsgIdentifier c70_thisId;
  int32_T c70_y;
  SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc70_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c70_b_sfEvent = sf_mex_dup(c70_mxArrayInData);
  c70_identifier = c70_varName;
  c70_thisId.fIdentifier = c70_identifier;
  c70_thisId.fParent = NULL;
  c70_y = c70_w_emlrt_marshallIn(chartInstance, sf_mex_dup(c70_b_sfEvent),
    &c70_thisId);
  sf_mex_destroy(&c70_b_sfEvent);
  *(int32_T *)c70_outData = c70_y;
  sf_mex_destroy(&c70_mxArrayInData);
}

static const mxArray *c70_ControlParams1_bus_io(void *chartInstanceVoid, void
  *c70_pData)
{
  const mxArray *c70_mxVal = NULL;
  c70_ControlParamsBus c70_tmp;
  int32_T c70_i273;
  int32_T c70_i274;
  int32_T c70_i275;
  int32_T c70_i276;
  int32_T c70_i277;
  int32_T c70_i278;
  int32_T c70_i279;
  int32_T c70_i280;
  int32_T c70_i281;
  int32_T c70_i282;
  int32_T c70_i283;
  int32_T c70_i284;
  int32_T c70_i285;
  int32_T c70_i286;
  int32_T c70_i287;
  int32_T c70_i288;
  int32_T c70_i289;
  int32_T c70_i290;
  int32_T c70_i291;
  int32_T c70_i292;
  int32_T c70_i293;
  int32_T c70_i294;
  int32_T c70_i295;
  int32_T c70_i296;
  int32_T c70_i297;
  int32_T c70_i298;
  int32_T c70_i299;
  int32_T c70_i300;
  int32_T c70_i301;
  int32_T c70_i302;
  int32_T c70_i303;
  int32_T c70_i304;
  int32_T c70_i305;
  int32_T c70_i306;
  int32_T c70_i307;
  int32_T c70_i308;
  int32_T c70_i309;
  int32_T c70_i310;
  int32_T c70_i311;
  int32_T c70_i312;
  int32_T c70_i313;
  int32_T c70_i314;
  int32_T c70_i315;
  int32_T c70_i316;
  int32_T c70_i317;
  int32_T c70_i318;
  int32_T c70_i319;
  int32_T c70_i320;
  SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc70_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c70_mxVal = NULL;
  c70_tmp.Supervisory.EnableSwapOnKAAccel = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [0];
  c70_tmp.Supervisory.EnableSwapOnKASpring = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [8];
  c70_tmp.Supervisory.EnableBackwardSwap = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [16];
  c70_tmp.Supervisory.ImpactThresholdKAAccel = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [24];
  c70_tmp.Supervisory.ImpactThresholdKASpringAbs = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [32];
  c70_tmp.Supervisory.ImpactThresholdKASpringRel = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [40];
  c70_tmp.Supervisory.SwapThresholdS = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [48];
  c70_tmp.Supervisory.AllowDoubleSupport = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [56];
  c70_tmp.Supervisory.UseGaitTransition = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [64];
  c70_tmp.Supervisory.NumTransitionSteps = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [72];
  c70_tmp.Supervisory.TransitionThresholdTorsoVel = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [80];
  for (c70_i273 = 0; c70_i273 < 2; c70_i273++) {
    c70_tmp.Supervisory.KAInjection[c70_i273] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [0])[88])[c70_i273];
  }

  c70_tmp.Supervisory.MinDeltaThetaTransition = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [104];
  c70_tmp.Supervisory.StartSecondGaitOnStep = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [112];
  for (c70_i274 = 0; c70_i274 < 6; c70_i274++) {
    c70_tmp.Supervisory.VBLAParams[c70_i274] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [0])[120])[c70_i274];
  }

  for (c70_i275 = 0; c70_i275 < 13; c70_i275++) {
    c70_tmp.Supervisory.BalanceParams[c70_i275] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [0])[168])[c70_i275];
  }

  for (c70_i276 = 0; c70_i276 < 5; c70_i276++) {
    c70_tmp.Supervisory.GaitTweaks[c70_i276] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [0])[272])[c70_i276];
  }

  c70_tmp.Supervisory.TStepInitial = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [312];
  c70_tmp.Supervisory.TMaxUpdate = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [320];
  c70_tmp.Supervisory.RunMode = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus
    *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])[328];
  c70_tmp.Supervisory.UseAbsoluteSwingLA = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [336];
  for (c70_i277 = 0; c70_i277 < 6; c70_i277++) {
    c70_tmp.Supervisory.ErrorZeroFactor[c70_i277] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [0])[344])[c70_i277];
  }

  for (c70_i278 = 0; c70_i278 < 6; c70_i278++) {
    c70_tmp.Supervisory.ErrorVelZeroFactor[c70_i278] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [0])[392])[c70_i278];
  }

  c70_tmp.Supervisory.StanceLegInit = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [440];
  c70_tmp.Supervisory.ControllerModeInit = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [448];
  c70_tmp.Supervisory.UsePosingControl = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [456];
  c70_tmp.Supervisory.TPosing = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus
    *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])[464];
  c70_tmp.Supervisory.TorsoBackAngle = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [472];
  c70_tmp.Supervisory.TorsoBackOnStep = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [480];
  c70_tmp.Supervisory.EnergyControlGain = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [488];
  c70_tmp.Supervisory.EnergyControlPhi0 = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [496];
  c70_tmp.Supervisory.VelocityControlTorsoMax = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [504];
  c70_tmp.Supervisory.VelocityControlTorsoMin = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [512];
  c70_tmp.Supervisory.VelocityControlTorsoGain = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [520];
  c70_tmp.Supervisory.VelocityControlTorsoV0 = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [528];
  c70_tmp.Supervisory.MinDeltaTheta = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [536];
  c70_tmp.Supervisory.Theta0 = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[0])[544];
  c70_tmp.Supervisory.KThetaPlus = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [552];
  c70_tmp.Supervisory.KThetaMinus = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [560];
  c70_tmp.Supervisory.RollPhaseVelocityThresh = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [568];
  c70_tmp.Supervisory.RollPhaseSThresh = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [576];
  c70_tmp.Supervisory.MaxError = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [584];
  c70_tmp.Supervisory.MaxErrorVel = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [592];
  c70_tmp.Supervisory.MaxErrorCount = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [600];
  for (c70_i279 = 0; c70_i279 < 6; c70_i279++) {
    c70_tmp.Supervisory.K1MidStanceUpdate[c70_i279] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [0])[608])[c70_i279];
  }

  for (c70_i280 = 0; c70_i280 < 6; c70_i280++) {
    c70_tmp.Supervisory.K2MidStanceUpdate[c70_i280] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [0])[656])[c70_i280];
  }

  c70_tmp.Supervisory.EnableVelocityBasedUpdate = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [704];
  for (c70_i281 = 0; c70_i281 < 6; c70_i281++) {
    c70_tmp.Supervisory.VelocityBasedUpdateK1[c70_i281] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [0])[712])[c70_i281];
  }

  for (c70_i282 = 0; c70_i282 < 6; c70_i282++) {
    c70_tmp.Supervisory.VelocityBasedUpdateK2[c70_i282] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [0])[760])[c70_i282];
  }

  c70_tmp.Supervisory.VelocityBasedUpdateDTheta0 = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [808];
  c70_i283 = 0;
  for (c70_i284 = 0; c70_i284 < 2; c70_i284++) {
    for (c70_i285 = 0; c70_i285 < 6; c70_i285++) {
      c70_tmp.Supervisory.VelocityBasedUpdateLimits[c70_i285 + c70_i283] =
        ((real_T *)&((char_T *)(c70_SupervisoryParamsBus *)&((char_T *)
           (c70_ControlParamsBus *)c70_pData)[0])[816])[c70_i285 + c70_i283];
    }

    c70_i283 += 6;
  }

  c70_tmp.Supervisory.DesiredYawOffset = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [912];
  c70_tmp.Supervisory.dx_cmd = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[0])[920];
  c70_tmp.Supervisory.ForBackward = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [928];
  c70_tmp.Supervisory.EnableFrictionID = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [936];
  c70_tmp.Supervisory.ResetFrictionPosing = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [944];
  c70_tmp.Supervisory.MoveLegIndex = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [952];
  c70_tmp.Supervisory.dy_cmd = *(real_T *)&((char_T *)(c70_SupervisoryParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[0])[960];
  c70_tmp.Supervisory.TauDelay = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [968];
  c70_tmp.Supervisory.TrackFrequency = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [976];
  c70_tmp.Supervisory.EnablePDControl = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [984];
  c70_tmp.Supervisory.TorqueAmp = *(real_T *)&((char_T *)
    (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[0])
    [992];
  for (c70_i286 = 0; c70_i286 < 6; c70_i286++) {
    c70_tmp.Supervisory.hdPosing[c70_i286] = ((real_T *)&((char_T *)
      (c70_SupervisoryParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [0])[1000])[c70_i286];
  }

  c70_tmp.Discrete.TLastUpdate = *(real_T *)&((char_T *)(c70_DiscreteParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[1048])[0];
  c70_tmp.Discrete.VelocityControlLADelta = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1048])
    [8];
  c70_tmp.Discrete.VelocityControlTorsoDelta = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1048])
    [16];
  c70_tmp.Discrete.VelocityControlHipDistCur = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1048])
    [24];
  c70_tmp.Discrete.VelocityControlHipDistPrev = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1048])
    [32];
  c70_tmp.Discrete.VirtualSpringMode = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1048])
    [40];
  c70_tmp.Discrete.VirtualSpringStiffness = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1048])
    [48];
  c70_tmp.Discrete.VirtualSpringDamping = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1048])
    [56];
  c70_tmp.Discrete.VirtualSpringModAmplitude = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1048])
    [64];
  c70_tmp.Discrete.VirtualSpringModRate = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1048])
    [72];
  c70_tmp.Discrete.VirtualSpringRestPos = *(real_T *)&((char_T *)
    (c70_DiscreteParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1048])
    [80];
  c70_i287 = 0;
  for (c70_i288 = 0; c70_i288 < 13; c70_i288++) {
    for (c70_i289 = 0; c70_i289 < 6; c70_i289++) {
      c70_tmp.Output.H0[c70_i289 + c70_i287] = ((real_T *)&((char_T *)
        (c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
        [1136])[0])[c70_i289 + c70_i287];
    }

    c70_i287 += 6;
  }

  c70_i290 = 0;
  for (c70_i291 = 0; c70_i291 < 6; c70_i291++) {
    for (c70_i292 = 0; c70_i292 < 6; c70_i292++) {
      c70_tmp.Output.HAlpha[c70_i292 + c70_i290] = ((real_T *)&((char_T *)
        (c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
        [1136])[624])[c70_i292 + c70_i290];
    }

    c70_i290 += 6;
  }

  for (c70_i293 = 0; c70_i293 < 2; c70_i293++) {
    c70_tmp.Output.ThetaLimits[c70_i293] = ((real_T *)&((char_T *)
      (c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1136])
      [912])[c70_i293];
  }

  c70_tmp.Output.Theta.c0 = *(real_T *)&((char_T *)(c70_ThetaParamsBus *)
    &((char_T *)(c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)
    c70_pData)[1136])[928])[0];
  c70_tmp.Output.Theta.ct = *(real_T *)&((char_T *)(c70_ThetaParamsBus *)
    &((char_T *)(c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)
    c70_pData)[1136])[928])[8];
  for (c70_i294 = 0; c70_i294 < 13; c70_i294++) {
    c70_tmp.Output.Theta.cq[c70_i294] = ((real_T *)&((char_T *)
      (c70_ThetaParamsBus *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
      (c70_ControlParamsBus *)c70_pData)[1136])[928])[16])[c70_i294];
  }

  c70_tmp.Output.Theta.t0 = *(real_T *)&((char_T *)(c70_ThetaParamsBus *)
    &((char_T *)(c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)
    c70_pData)[1136])[928])[120];
  for (c70_i295 = 0; c70_i295 < 7; c70_i295++) {
    c70_tmp.Output.Theta.cz[c70_i295] = ((real_T *)&((char_T *)
      (c70_ThetaParamsBus *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
      (c70_ControlParamsBus *)c70_pData)[1136])[928])[128])[c70_i295];
  }

  c70_tmp.Output.SaturateS = *(real_T *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[1136])[1112];
  for (c70_i296 = 0; c70_i296 < 2; c70_i296++) {
    c70_tmp.Output.SLimits[c70_i296] = ((real_T *)&((char_T *)
      (c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1136])
      [1120])[c70_i296];
  }

  c70_tmp.Output.EnforceIncreasingS = *(real_T *)&((char_T *)
    (c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1136])
    [1136];
  c70_tmp.Output.UseCorrection = *(real_T *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[1136])[1144];
  c70_tmp.Output.SMaxCorrection = *(real_T *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[1136])[1152];
  c70_i297 = 0;
  for (c70_i298 = 0; c70_i298 < 5; c70_i298++) {
    for (c70_i299 = 0; c70_i299 < 6; c70_i299++) {
      c70_tmp.Output.HAlphaCorrection[c70_i299 + c70_i297] = ((real_T *)
        &((char_T *)(c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)
        c70_pData)[1136])[1160])[c70_i299 + c70_i297];
    }

    c70_i297 += 6;
  }

  c70_tmp.Output.Phi.c0 = *(real_T *)&((char_T *)(c70_PhiParamsBus *)&((char_T *)
                                        (c70_OutputParamsBus *)&((char_T *)
    (c70_ControlParamsBus *)c70_pData)[1136])[1400])[0];
  for (c70_i300 = 0; c70_i300 < 13; c70_i300++) {
    c70_tmp.Output.Phi.cq[c70_i300] = ((real_T *)&((char_T *)(c70_PhiParamsBus *)
      &((char_T *)(c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)
      c70_pData)[1136])[1400])[8])[c70_i300];
  }

  for (c70_i301 = 0; c70_i301 < 20; c70_i301++) {
    c70_tmp.Output.PhiAlpha[c70_i301] = ((real_T *)&((char_T *)
      (c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1136])
      [1512])[c70_i301];
  }

  c70_tmp.Output.SaturateR = *(real_T *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[1136])[1672];
  for (c70_i302 = 0; c70_i302 < 2; c70_i302++) {
    c70_tmp.Output.RLimits[c70_i302] = ((real_T *)&((char_T *)
      (c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[1136])
      [1680])[c70_i302];
  }

  c70_i303 = 0;
  for (c70_i304 = 0; c70_i304 < 5; c70_i304++) {
    for (c70_i305 = 0; c70_i305 < 6; c70_i305++) {
      c70_tmp.Output.HBarAlpha[c70_i305 + c70_i303] = ((real_T *)&((char_T *)
        (c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
        [1136])[1696])[c70_i305 + c70_i303];
    }

    c70_i303 += 6;
  }

  c70_i306 = 0;
  for (c70_i307 = 0; c70_i307 < 2; c70_i307++) {
    for (c70_i308 = 0; c70_i308 < 6; c70_i308++) {
      c70_tmp.Output.HBarLimits[c70_i308 + c70_i306] = ((real_T *)&((char_T *)
        (c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
        [1136])[1936])[c70_i308 + c70_i306];
    }

    c70_i306 += 6;
  }

  c70_i309 = 0;
  for (c70_i310 = 0; c70_i310 < 6; c70_i310++) {
    for (c70_i311 = 0; c70_i311 < 6; c70_i311++) {
      c70_tmp.Output.HAlphaStar[c70_i311 + c70_i309] = ((real_T *)&((char_T *)
        (c70_OutputParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
        [1136])[2032])[c70_i311 + c70_i309];
    }

    c70_i309 += 6;
  }

  c70_tmp.Output.YawLimit = *(real_T *)&((char_T *)(c70_OutputParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[1136])[2320];
  c70_tmp.Output.test = *(real_T *)&((char_T *)(c70_OutputParamsBus *)&((char_T *)
                                      (c70_ControlParamsBus *)c70_pData)[1136])
    [2328];
  for (c70_i312 = 0; c70_i312 < 6; c70_i312++) {
    c70_tmp.Feedback.kp[c70_i312] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [3472])[0])[c70_i312];
  }

  for (c70_i313 = 0; c70_i313 < 6; c70_i313++) {
    c70_tmp.Feedback.kd[c70_i313] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [3472])[48])[c70_i313];
  }

  for (c70_i314 = 0; c70_i314 < 2; c70_i314++) {
    c70_tmp.Feedback.epsilon[c70_i314] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [3472])[96])[c70_i314];
  }

  for (c70_i315 = 0; c70_i315 < 2; c70_i315++) {
    c70_tmp.Feedback.kff_grav[c70_i315] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [3472])[112])[c70_i315];
  }

  c70_tmp.Feedback.delta_grav = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[128];
  for (c70_i316 = 0; c70_i316 < 2; c70_i316++) {
    c70_tmp.Feedback.kff_decoup[c70_i316] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [3472])[136])[c70_i316];
  }

  for (c70_i317 = 0; c70_i317 < 2; c70_i317++) {
    c70_tmp.Feedback.kd_torso[c70_i317] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [3472])[152])[c70_i317];
  }

  c70_tmp.Feedback.kp_2dof = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[168];
  c70_tmp.Feedback.kd_2dof = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[176];
  c70_tmp.Feedback.kpre_2dof = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[184];
  c70_tmp.Feedback.kp_lat = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[192];
  c70_tmp.Feedback.kd_lat = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[200];
  c70_tmp.Feedback.q3d_min_lat = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[208];
  c70_tmp.Feedback.q3d_max_lat = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[216];
  c70_tmp.Feedback.w_torso_lat = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[224];
  for (c70_i318 = 0; c70_i318 < 6; c70_i318++) {
    c70_tmp.Feedback.u_ff[c70_i318] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [3472])[232])[c70_i318];
  }

  c70_tmp.Feedback.LateralControlMode = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])
    [280];
  c70_tmp.Feedback.DecouplingMode = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])
    [288];
  c70_tmp.Feedback.Use2DOF = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[296];
  c70_tmp.Feedback.UseDSGravComp = *(real_T *)&((char_T *)(c70_FeedbackParamsBus
    *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[304];
  c70_tmp.Feedback.lat_bias = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[312];
  c70_tmp.Feedback.lat_bias2 = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[320];
  c70_tmp.Feedback.linkFeedback = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[328];
  c70_tmp.Feedback.RIO = *(real_T *)&((char_T *)(c70_FeedbackParamsBus *)
    &((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])[336];
  c70_tmp.Feedback.SelectFeedforward = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])
    [344];
  for (c70_i319 = 0; c70_i319 < 6; c70_i319++) {
    c70_tmp.Feedback.FeedforwardGain[c70_i319] = ((real_T *)&((char_T *)
      (c70_FeedbackParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [3472])[352])[c70_i319];
  }

  c70_tmp.Feedback.EnableFeedforwardOnStep = *(real_T *)&((char_T *)
    (c70_FeedbackParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)[3472])
    [400];
  c70_tmp.Saturation.UseQPSaturation = *(real_T *)&((char_T *)
    (c70_SaturationParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
    [3880])[0];
  for (c70_i320 = 0; c70_i320 < 2; c70_i320++) {
    c70_tmp.Saturation.QPWeight[c70_i320] = ((real_T *)&((char_T *)
      (c70_SaturationParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
      [3880])[8])[c70_i320];
  }

  c70_tmp.Saturation.UseKASaturation = *(real_T *)&((char_T *)
    (c70_SaturationParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
    [3880])[24];
  c70_tmp.Saturation.KASaturationS1 = *(real_T *)&((char_T *)
    (c70_SaturationParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
    [3880])[32];
  c70_tmp.Saturation.KASaturationS2 = *(real_T *)&((char_T *)
    (c70_SaturationParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
    [3880])[40];
  c70_tmp.Saturation.KASaturationEarly = *(real_T *)&((char_T *)
    (c70_SaturationParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
    [3880])[48];
  c70_tmp.Saturation.KASaturationMax = *(real_T *)&((char_T *)
    (c70_SaturationParamsBus *)&((char_T *)(c70_ControlParamsBus *)c70_pData)
    [3880])[56];
  sf_mex_assign(&c70_mxVal, c70_sf_marshallOut(chartInstance, &c70_tmp), false);
  return c70_mxVal;
}

static uint8_T c70_x_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_b_is_active_c70_DDA2D_OSU3Dv2, const char_T
  *c70_identifier)
{
  uint8_T c70_y;
  emlrtMsgIdentifier c70_thisId;
  c70_thisId.fIdentifier = c70_identifier;
  c70_thisId.fParent = NULL;
  c70_y = c70_y_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c70_b_is_active_c70_DDA2D_OSU3Dv2), &c70_thisId);
  sf_mex_destroy(&c70_b_is_active_c70_DDA2D_OSU3Dv2);
  return c70_y;
}

static uint8_T c70_y_emlrt_marshallIn(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c70_u, const emlrtMsgIdentifier *c70_parentId)
{
  uint8_T c70_y;
  uint8_T c70_u0;
  (void)chartInstance;
  sf_mex_import(c70_parentId, sf_mex_dup(c70_u), &c70_u0, 1, 3, 0U, 0, 0U, 0);
  c70_y = c70_u0;
  sf_mex_destroy(&c70_u);
  return c70_y;
}

static void init_dsm_address_info(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc70_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c70_isSim = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c70_t = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c70_dx_est = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c70_ControlParams1 = (c70_ControlParamsBus *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 1);
  chartInstance->c70_ControlParams = (c70_ControlParamsBus *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 3);
  chartInstance->c70_ForBackwardPrev = (real_T *)ssGetInputPortSignal_wrapper
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

void sf_c70_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2829425254U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(871294255U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(433785607U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(460395232U);
}

mxArray* sf_c70_DDA2D_OSU3Dv2_get_post_codegen_info(void);
mxArray *sf_c70_DDA2D_OSU3Dv2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("nfOLpyB9fJrYrqS3PRQ8MH");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,5,3,dataFields);

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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c70_DDA2D_OSU3Dv2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c70_DDA2D_OSU3Dv2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c70_DDA2D_OSU3Dv2_jit_fallback_info(void)
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

mxArray *sf_c70_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c70_DDA2D_OSU3Dv2_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c70_DDA2D_OSU3Dv2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"ControlParams1\",},{M[8],M[0],T\"is_active_c70_DDA2D_OSU3Dv2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c70_DDA2D_OSU3Dv2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc70_DDA2D_OSU3Dv2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DDA2D_OSU3Dv2MachineNumber_,
           70,
           1,
           1,
           0,
           6,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"isSim");
          _SFD_SET_DATA_PROPS(1,1,1,0,"t");
          _SFD_SET_DATA_PROPS(2,1,1,0,"dx_est");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ControlParams1");
          _SFD_SET_DATA_PROPS(4,1,1,0,"ControlParams");
          _SFD_SET_DATA_PROPS(5,1,1,0,"ForBackwardPrev");
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
        _SFD_CV_INIT_EML(0,1,1,3,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,796);
        _SFD_CV_INIT_EML_IF(0,1,0,139,147,-1,449);
        _SFD_CV_INIT_EML_IF(0,1,1,458,491,706,792);
        _SFD_CV_INIT_EML_IF(0,1,2,504,543,616,697);

        {
          static int condStart[] = { 461, 478 };

          static int condEnd[] = { 474, 491 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,461,491,2,0,&(condStart[0]),&(condEnd[0]),
                                3,&(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,1,0,461,474,-1,2);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,1,478,491,-1,4);
        _SFD_CV_INIT_EML_RELATIONAL(0,1,2,507,543,-1,5);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c70_c_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c70_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c70_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c70_ControlParams1_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_STRUCT,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c70_ControlParams1_bus_io,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c70_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c70_isSim);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c70_t);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c70_dx_est);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c70_ControlParams1);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c70_ControlParams);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c70_ForBackwardPrev);
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
  return "y6r5H1utZtVLrGXfpThPbH";
}

static void sf_opaque_initialize_c70_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc70_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c70_DDA2D_OSU3Dv2((SFc70_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
  initialize_c70_DDA2D_OSU3Dv2((SFc70_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c70_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  enable_c70_DDA2D_OSU3Dv2((SFc70_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c70_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  disable_c70_DDA2D_OSU3Dv2((SFc70_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c70_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  sf_gateway_c70_DDA2D_OSU3Dv2((SFc70_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c70_DDA2D_OSU3Dv2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c70_DDA2D_OSU3Dv2((SFc70_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c70_DDA2D_OSU3Dv2(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c70_DDA2D_OSU3Dv2((SFc70_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c70_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc70_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DDA2D_OSU3Dv2_optimization_info();
    }

    finalize_c70_DDA2D_OSU3Dv2((SFc70_DDA2D_OSU3Dv2InstanceStruct*)
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
  initSimStructsc70_DDA2D_OSU3Dv2((SFc70_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c70_DDA2D_OSU3Dv2(SimStruct *S)
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
    initialize_params_c70_DDA2D_OSU3Dv2((SFc70_DDA2D_OSU3Dv2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c70_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DDA2D_OSU3Dv2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      70);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,70,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,70,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,70);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,70,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,70,1);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,70);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1137849567U));
  ssSetChecksum1(S,(1721108098U));
  ssSetChecksum2(S,(2018554452U));
  ssSetChecksum3(S,(344086923U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c70_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c70_DDA2D_OSU3Dv2(SimStruct *S)
{
  SFc70_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc70_DDA2D_OSU3Dv2InstanceStruct *)utMalloc(sizeof
    (SFc70_DDA2D_OSU3Dv2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc70_DDA2D_OSU3Dv2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c70_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c70_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c70_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c70_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c70_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c70_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c70_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c70_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c70_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlStart = mdlStart_c70_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c70_DDA2D_OSU3Dv2;
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

void c70_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c70_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c70_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c70_DDA2D_OSU3Dv2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c70_DDA2D_OSU3Dv2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
