/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DDA2D_OSU3Dv2_sfun.h"
#include "c9_DDA2D_OSU3Dv2.h"
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
static const char * c9_debug_family_names[12] = { "nargin", "nargout", "x",
  "FootPoints", "pR", "vR", "J4R", "JR1Col", "pL", "vL", "J4L", "JR5Col" };

static const char * c9_b_debug_family_names[106] = { "xT", "yT", "zT", "qzT",
  "qyT", "qxT", "q1R", "q2R", "q1L", "q2L", "qgr1R", "qgr2R", "q3R", "qgr1L",
  "qgr2L", "q3L", "t1", "t2", "t3", "t4", "t7", "t8", "t10", "t11", "t12", "t14",
  "t15", "t20", "t21", "t26", "t27", "t30", "t33", "t37", "t41", "t43", "t48",
  "t53", "t63", "t66", "t71", "t6", "t9", "t13", "t19", "t24", "t25", "t31",
  "t34", "t36", "t45", "t52", "t55", "t59", "t5", "t40", "t44", "t50", "t61",
  "t69", "t79", "t80", "t81", "t92", "t93", "t94", "t119", "t131", "t141",
  "t142", "t154", "t162", "t165", "t170", "t178", "t181", "t195", "t196", "t197",
  "t210", "t17", "t32", "t35", "t47", "t56", "t60", "t68", "t72", "t77", "t85",
  "t89", "t96", "t98", "t102", "t114", "nargin", "nargout", "q", "p4R", "R1",
  "J4R", "JR1Col", "p4L", "R5", "J4L", "JR5Col" };

static const char * c9_c_debug_family_names[24] = { "q", "dq", "nPoints", "p4R",
  "R1", "p4L", "R5", "k", "DR", "DL", "v4R", "v4L", "nargin", "nargout", "x",
  "FootPoints", "pR", "vR", "J4R", "JR1Col", "pL", "vL", "J4L", "JR5Col" };

/* Function Declarations */
static void initialize_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initialize_params_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct *
  chartInstance);
static void enable_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void disable_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c9_update_debugger_state_c9_DDA2D_OSU3Dv2
  (SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static const mxArray *get_sim_state_c9_DDA2D_OSU3Dv2
  (SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void set_sim_state_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_st);
static void finalize_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void sf_gateway_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void mdl_start_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void initSimStructsc9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void c9_FootHeightAndVelocity(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c9_b_x[32], real_T c9_b_FootPoints[3], real_T c9_b_pR[3],
  real_T c9_b_vR[3], real_T c9_b_J4R[48], real_T c9_b_JR1Col[144], real_T
  c9_b_pL[3], real_T c9_b_vL[3], real_T c9_b_J4L[48], real_T c9_b_JR5Col[144]);
static void c9_ATRIAS3D_FootPointPosJacob_Hip(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c9_q[16], real_T c9_p4R[3], real_T c9_R1[9], real_T
  c9_b_J4R[48], real_T c9_b_JR1Col[144], real_T c9_p4L[3], real_T c9_R5[9],
  real_T c9_b_J4L[48], real_T c9_b_JR5Col[144]);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static void c9_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  const mxArray *c9_b_JR5Col, const char_T *c9_identifier, real_T c9_y[144]);
static void c9_b_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[144]);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_c_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_b_J4L, const char_T *c9_identifier, real_T
  c9_y[48]);
static void c9_d_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[48]);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_e_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_b_vL, const char_T *c9_identifier, real_T
  c9_y[3]);
static void c9_f_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[3]);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_g_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_h_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[9]);
static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_i_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[16]);
static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_j_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[32]);
static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static void c9_k_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[9]);
static void c9_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_info_helper(const mxArray **c9_info);
static const mxArray *c9_emlrt_marshallOut(const char * c9_u);
static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u);
static void c9_eml_scalar_eg(SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c9_threshold(SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c9_b_eml_scalar_eg(SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c9_c_eml_scalar_eg(SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance);
static void c9_eml_li_find(SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  boolean_T c9_b_x, int32_T c9_y_data[], int32_T c9_y_sizes[2]);
static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_l_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static uint8_T c9_m_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_DDA2D_OSU3Dv2, const char_T
  *c9_identifier);
static uint8_T c9_n_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_is_active_c9_DDA2D_OSU3Dv2 = 0U;
}

static void initialize_params_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void enable_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c9_update_debugger_state_c9_DDA2D_OSU3Dv2
  (SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c9_DDA2D_OSU3Dv2
  (SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  int32_T c9_i0;
  real_T c9_u[48];
  const mxArray *c9_b_y = NULL;
  int32_T c9_i1;
  real_T c9_b_u[48];
  const mxArray *c9_c_y = NULL;
  int32_T c9_i2;
  real_T c9_c_u[144];
  const mxArray *c9_d_y = NULL;
  int32_T c9_i3;
  real_T c9_d_u[144];
  const mxArray *c9_e_y = NULL;
  int32_T c9_i4;
  real_T c9_e_u[3];
  const mxArray *c9_f_y = NULL;
  int32_T c9_i5;
  real_T c9_f_u[3];
  const mxArray *c9_g_y = NULL;
  int32_T c9_i6;
  real_T c9_g_u[3];
  const mxArray *c9_h_y = NULL;
  int32_T c9_i7;
  real_T c9_h_u[3];
  const mxArray *c9_i_y = NULL;
  uint8_T c9_hoistedGlobal;
  uint8_T c9_i_u;
  const mxArray *c9_j_y = NULL;
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(9, 1), false);
  for (c9_i0 = 0; c9_i0 < 48; c9_i0++) {
    c9_u[c9_i0] = (*chartInstance->c9_J4L)[c9_i0];
  }

  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 3, 16),
                false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  for (c9_i1 = 0; c9_i1 < 48; c9_i1++) {
    c9_b_u[c9_i1] = (*chartInstance->c9_J4R)[c9_i1];
  }

  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", c9_b_u, 0, 0U, 1U, 0U, 2, 3, 16),
                false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  for (c9_i2 = 0; c9_i2 < 144; c9_i2++) {
    c9_c_u[c9_i2] = (*chartInstance->c9_JR1Col)[c9_i2];
  }

  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", c9_c_u, 0, 0U, 1U, 0U, 2, 9, 16),
                false);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  for (c9_i3 = 0; c9_i3 < 144; c9_i3++) {
    c9_d_u[c9_i3] = (*chartInstance->c9_JR5Col)[c9_i3];
  }

  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", c9_d_u, 0, 0U, 1U, 0U, 2, 9, 16),
                false);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  for (c9_i4 = 0; c9_i4 < 3; c9_i4++) {
    c9_e_u[c9_i4] = (*chartInstance->c9_pL)[c9_i4];
  }

  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", c9_e_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c9_y, 4, c9_f_y);
  for (c9_i5 = 0; c9_i5 < 3; c9_i5++) {
    c9_f_u[c9_i5] = (*chartInstance->c9_pR)[c9_i5];
  }

  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", c9_f_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c9_y, 5, c9_g_y);
  for (c9_i6 = 0; c9_i6 < 3; c9_i6++) {
    c9_g_u[c9_i6] = (*chartInstance->c9_vL)[c9_i6];
  }

  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", c9_g_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c9_y, 6, c9_h_y);
  for (c9_i7 = 0; c9_i7 < 3; c9_i7++) {
    c9_h_u[c9_i7] = (*chartInstance->c9_vR)[c9_i7];
  }

  c9_i_y = NULL;
  sf_mex_assign(&c9_i_y, sf_mex_create("y", c9_h_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_setcell(c9_y, 7, c9_i_y);
  c9_hoistedGlobal = chartInstance->c9_is_active_c9_DDA2D_OSU3Dv2;
  c9_i_u = c9_hoistedGlobal;
  c9_j_y = NULL;
  sf_mex_assign(&c9_j_y, sf_mex_create("y", &c9_i_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 8, c9_j_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  real_T c9_dv0[48];
  int32_T c9_i8;
  real_T c9_dv1[48];
  int32_T c9_i9;
  real_T c9_dv2[144];
  int32_T c9_i10;
  real_T c9_dv3[144];
  int32_T c9_i11;
  real_T c9_dv4[3];
  int32_T c9_i12;
  real_T c9_dv5[3];
  int32_T c9_i13;
  real_T c9_dv6[3];
  int32_T c9_i14;
  real_T c9_dv7[3];
  int32_T c9_i15;
  chartInstance->c9_doneDoubleBufferReInit = true;
  c9_u = sf_mex_dup(c9_st);
  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 0)),
                        "J4L", c9_dv0);
  for (c9_i8 = 0; c9_i8 < 48; c9_i8++) {
    (*chartInstance->c9_J4L)[c9_i8] = c9_dv0[c9_i8];
  }

  c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 1)),
                        "J4R", c9_dv1);
  for (c9_i9 = 0; c9_i9 < 48; c9_i9++) {
    (*chartInstance->c9_J4R)[c9_i9] = c9_dv1[c9_i9];
  }

  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 2)),
                      "JR1Col", c9_dv2);
  for (c9_i10 = 0; c9_i10 < 144; c9_i10++) {
    (*chartInstance->c9_JR1Col)[c9_i10] = c9_dv2[c9_i10];
  }

  c9_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 3)),
                      "JR5Col", c9_dv3);
  for (c9_i11 = 0; c9_i11 < 144; c9_i11++) {
    (*chartInstance->c9_JR5Col)[c9_i11] = c9_dv3[c9_i11];
  }

  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 4)), "pL",
                        c9_dv4);
  for (c9_i12 = 0; c9_i12 < 3; c9_i12++) {
    (*chartInstance->c9_pL)[c9_i12] = c9_dv4[c9_i12];
  }

  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 5)), "pR",
                        c9_dv5);
  for (c9_i13 = 0; c9_i13 < 3; c9_i13++) {
    (*chartInstance->c9_pR)[c9_i13] = c9_dv5[c9_i13];
  }

  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 6)), "vL",
                        c9_dv6);
  for (c9_i14 = 0; c9_i14 < 3; c9_i14++) {
    (*chartInstance->c9_vL)[c9_i14] = c9_dv6[c9_i14];
  }

  c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 7)), "vR",
                        c9_dv7);
  for (c9_i15 = 0; c9_i15 < 3; c9_i15++) {
    (*chartInstance->c9_vR)[c9_i15] = c9_dv7[c9_i15];
  }

  chartInstance->c9_is_active_c9_DDA2D_OSU3Dv2 = c9_m_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 8)),
     "is_active_c9_DDA2D_OSU3Dv2");
  sf_mex_destroy(&c9_u);
  c9_update_debugger_state_c9_DDA2D_OSU3Dv2(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void finalize_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  int32_T c9_i16;
  int32_T c9_i17;
  real_T c9_b_x[32];
  int32_T c9_i18;
  real_T c9_b_FootPoints[3];
  uint32_T c9_debug_family_var_map[12];
  real_T c9_nargin = 2.0;
  real_T c9_nargout = 8.0;
  real_T c9_b_pR[3];
  real_T c9_b_vR[3];
  real_T c9_b_J4R[48];
  real_T c9_b_JR1Col[144];
  real_T c9_b_pL[3];
  real_T c9_b_vL[3];
  real_T c9_b_J4L[48];
  real_T c9_b_JR5Col[144];
  int32_T c9_i19;
  real_T c9_c_x[32];
  int32_T c9_i20;
  real_T c9_c_FootPoints[3];
  real_T c9_c_JR5Col[144];
  real_T c9_c_J4L[48];
  real_T c9_c_vL[3];
  real_T c9_c_pL[3];
  real_T c9_c_JR1Col[144];
  real_T c9_c_J4R[48];
  real_T c9_c_vR[3];
  real_T c9_c_pR[3];
  int32_T c9_i21;
  int32_T c9_i22;
  int32_T c9_i23;
  int32_T c9_i24;
  int32_T c9_i25;
  int32_T c9_i26;
  int32_T c9_i27;
  int32_T c9_i28;
  int32_T c9_i29;
  int32_T c9_i30;
  int32_T c9_i31;
  int32_T c9_i32;
  int32_T c9_i33;
  int32_T c9_i34;
  int32_T c9_i35;
  int32_T c9_i36;
  int32_T c9_i37;
  int32_T c9_i38;
  int32_T c9_i39;
  int32_T c9_i40;
  int32_T c9_i41;
  int32_T c9_i42;
  int32_T c9_i43;
  int32_T c9_i44;
  int32_T c9_i45;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 4U, chartInstance->c9_sfEvent);
  for (c9_i16 = 0; c9_i16 < 32; c9_i16++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_x)[c9_i16], 0U);
  }

  chartInstance->c9_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 4U, chartInstance->c9_sfEvent);
  for (c9_i17 = 0; c9_i17 < 32; c9_i17++) {
    c9_b_x[c9_i17] = (*chartInstance->c9_x)[c9_i17];
  }

  for (c9_i18 = 0; c9_i18 < 3; c9_i18++) {
    c9_b_FootPoints[c9_i18] = (*chartInstance->c9_FootPoints)[c9_i18];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 12U, 12U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_b_x, 2U, c9_d_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(c9_b_FootPoints, 3U, c9_c_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_pR, 4U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_vR, 5U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_J4R, 6U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_JR1Col, 7U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_pL, 8U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_vL, 9U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_J4L, 10U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_JR5Col, 11U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, 3);
  for (c9_i19 = 0; c9_i19 < 32; c9_i19++) {
    c9_c_x[c9_i19] = c9_b_x[c9_i19];
  }

  for (c9_i20 = 0; c9_i20 < 3; c9_i20++) {
    c9_c_FootPoints[c9_i20] = c9_b_FootPoints[c9_i20];
  }

  c9_FootHeightAndVelocity(chartInstance, c9_c_x, c9_c_FootPoints, c9_c_pR,
    c9_c_vR, c9_c_J4R, c9_c_JR1Col, c9_c_pL, c9_c_vL, c9_c_J4L, c9_c_JR5Col);
  for (c9_i21 = 0; c9_i21 < 3; c9_i21++) {
    c9_b_pR[c9_i21] = c9_c_pR[c9_i21];
  }

  for (c9_i22 = 0; c9_i22 < 3; c9_i22++) {
    c9_b_vR[c9_i22] = c9_c_vR[c9_i22];
  }

  for (c9_i23 = 0; c9_i23 < 48; c9_i23++) {
    c9_b_J4R[c9_i23] = c9_c_J4R[c9_i23];
  }

  for (c9_i24 = 0; c9_i24 < 144; c9_i24++) {
    c9_b_JR1Col[c9_i24] = c9_c_JR1Col[c9_i24];
  }

  for (c9_i25 = 0; c9_i25 < 3; c9_i25++) {
    c9_b_pL[c9_i25] = c9_c_pL[c9_i25];
  }

  for (c9_i26 = 0; c9_i26 < 3; c9_i26++) {
    c9_b_vL[c9_i26] = c9_c_vL[c9_i26];
  }

  for (c9_i27 = 0; c9_i27 < 48; c9_i27++) {
    c9_b_J4L[c9_i27] = c9_c_J4L[c9_i27];
  }

  for (c9_i28 = 0; c9_i28 < 144; c9_i28++) {
    c9_b_JR5Col[c9_i28] = c9_c_JR5Col[c9_i28];
  }

  _SFD_EML_CALL(0U, chartInstance->c9_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  for (c9_i29 = 0; c9_i29 < 3; c9_i29++) {
    (*chartInstance->c9_pR)[c9_i29] = c9_b_pR[c9_i29];
  }

  for (c9_i30 = 0; c9_i30 < 3; c9_i30++) {
    (*chartInstance->c9_vR)[c9_i30] = c9_b_vR[c9_i30];
  }

  for (c9_i31 = 0; c9_i31 < 48; c9_i31++) {
    (*chartInstance->c9_J4R)[c9_i31] = c9_b_J4R[c9_i31];
  }

  for (c9_i32 = 0; c9_i32 < 144; c9_i32++) {
    (*chartInstance->c9_JR1Col)[c9_i32] = c9_b_JR1Col[c9_i32];
  }

  for (c9_i33 = 0; c9_i33 < 3; c9_i33++) {
    (*chartInstance->c9_pL)[c9_i33] = c9_b_pL[c9_i33];
  }

  for (c9_i34 = 0; c9_i34 < 3; c9_i34++) {
    (*chartInstance->c9_vL)[c9_i34] = c9_b_vL[c9_i34];
  }

  for (c9_i35 = 0; c9_i35 < 48; c9_i35++) {
    (*chartInstance->c9_J4L)[c9_i35] = c9_b_J4L[c9_i35];
  }

  for (c9_i36 = 0; c9_i36 < 144; c9_i36++) {
    (*chartInstance->c9_JR5Col)[c9_i36] = c9_b_JR5Col[c9_i36];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_DDA2D_OSU3Dv2MachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c9_i37 = 0; c9_i37 < 3; c9_i37++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_pR)[c9_i37], 1U);
  }

  for (c9_i38 = 0; c9_i38 < 3; c9_i38++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_vR)[c9_i38], 2U);
  }

  for (c9_i39 = 0; c9_i39 < 48; c9_i39++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_J4R)[c9_i39], 3U);
  }

  for (c9_i40 = 0; c9_i40 < 144; c9_i40++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_JR1Col)[c9_i40], 4U);
  }

  for (c9_i41 = 0; c9_i41 < 3; c9_i41++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_pL)[c9_i41], 5U);
  }

  for (c9_i42 = 0; c9_i42 < 3; c9_i42++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_vL)[c9_i42], 6U);
  }

  for (c9_i43 = 0; c9_i43 < 48; c9_i43++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_J4L)[c9_i43], 7U);
  }

  for (c9_i44 = 0; c9_i44 < 144; c9_i44++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_JR5Col)[c9_i44], 8U);
  }

  for (c9_i45 = 0; c9_i45 < 3; c9_i45++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_FootPoints)[c9_i45], 9U);
  }
}

static void mdl_start_c9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc9_DDA2D_OSU3Dv2(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c9_FootHeightAndVelocity(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c9_b_x[32], real_T c9_b_FootPoints[3], real_T c9_b_pR[3],
  real_T c9_b_vR[3], real_T c9_b_J4R[48], real_T c9_b_JR1Col[144], real_T
  c9_b_pL[3], real_T c9_b_vL[3], real_T c9_b_J4L[48], real_T c9_b_JR5Col[144])
{
  uint32_T c9_debug_family_var_map[24];
  real_T c9_q[16];
  real_T c9_dq[16];
  real_T c9_nPoints;
  real_T c9_p4R[3];
  real_T c9_R1[9];
  real_T c9_p4L[3];
  real_T c9_R5[9];
  real_T c9_k;
  real_T c9_DR[9];
  real_T c9_DL[9];
  real_T c9_v4R[3];
  real_T c9_v4L[3];
  real_T c9_nargin = 2.0;
  real_T c9_nargout = 8.0;
  int32_T c9_i46;
  int32_T c9_i47;
  int32_T c9_i48;
  real_T c9_b_q[16];
  real_T c9_c_JR5Col[144];
  real_T c9_c_J4L[48];
  real_T c9_b_R5[9];
  real_T c9_b_p4L[3];
  real_T c9_c_JR1Col[144];
  real_T c9_c_J4R[48];
  real_T c9_b_R1[9];
  real_T c9_b_p4R[3];
  int32_T c9_i49;
  int32_T c9_i50;
  int32_T c9_i51;
  int32_T c9_i52;
  int32_T c9_i53;
  int32_T c9_i54;
  int32_T c9_i55;
  int32_T c9_i56;
  int32_T c9_i57;
  int32_T c9_i58;
  int32_T c9_i59;
  int32_T c9_i60;
  int32_T c9_i61;
  int32_T c9_i62;
  int32_T c9_i63;
  int32_T c9_i64;
  real_T c9_b[3];
  int32_T c9_i65;
  int32_T c9_i66;
  int32_T c9_i67;
  int32_T c9_i68;
  int32_T c9_i69;
  int32_T c9_i70;
  int32_T c9_i71;
  int32_T c9_i72;
  int32_T c9_i73;
  int32_T c9_i74;
  int32_T c9_i75;
  int32_T c9_i76;
  int32_T c9_i77;
  int32_T c9_i78;
  real_T c9_b_b[16];
  int32_T c9_i79;
  int32_T c9_i80;
  int32_T c9_i81;
  real_T c9_C[9];
  int32_T c9_i82;
  int32_T c9_i83;
  int32_T c9_i84;
  int32_T c9_i85;
  int32_T c9_i86;
  int32_T c9_i87;
  int32_T c9_i88;
  int32_T c9_i89;
  int32_T c9_i90;
  int32_T c9_i91;
  int32_T c9_i92;
  int32_T c9_i93;
  int32_T c9_i94;
  int32_T c9_i95;
  int32_T c9_i96;
  int32_T c9_i97;
  int32_T c9_i98;
  int32_T c9_i99;
  int32_T c9_i100;
  int32_T c9_i101;
  int32_T c9_i102;
  int32_T c9_i103;
  int32_T c9_i104;
  int32_T c9_i105;
  int32_T c9_i106;
  int32_T c9_i107;
  int32_T c9_i108;
  int32_T c9_i109;
  int32_T c9_i110;
  int32_T c9_i111;
  int32_T c9_i112;
  int32_T c9_i113;
  int32_T c9_i114;
  int32_T c9_i115;
  int32_T c9_i116;
  int32_T c9_i117;
  int32_T c9_i118;
  int32_T c9_i119;
  int32_T c9_i120;
  real_T c9_a;
  int32_T c9_i121;
  int32_T c9_i122;
  real_T c9_b_a;
  int32_T c9_i123;
  int32_T c9_i124;
  real_T c9_c_a;
  int32_T c9_i125;
  int32_T c9_i126;
  int32_T c9_i127;
  real_T c9_d_a;
  int32_T c9_i128;
  int32_T c9_i129;
  real_T c9_e_a;
  int32_T c9_i130;
  int32_T c9_i131;
  real_T c9_f_a;
  int32_T c9_i132;
  int32_T c9_i133;
  int32_T c9_i134;
  int32_T c9_tmp_sizes[2];
  int32_T c9_tmp_data[1];
  int32_T c9_b_tmp_sizes;
  int32_T c9_loop_ub;
  int32_T c9_i135;
  int32_T c9_b_tmp_data[1];
  int32_T c9_c_tmp_sizes[2];
  int32_T c9_b_loop_ub;
  int32_T c9_i136;
  real_T c9_c_tmp_data[1];
  int32_T c9_iv0[2];
  int32_T c9_c_loop_ub;
  int32_T c9_i137;
  int32_T c9_d_loop_ub;
  int32_T c9_i138;
  int32_T c9_e_loop_ub;
  int32_T c9_i139;
  int32_T c9_iv1[2];
  int32_T c9_f_loop_ub;
  int32_T c9_i140;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 24U, 24U, c9_c_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_q, 0U, c9_g_sf_marshallOut,
    c9_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_dq, 1U, c9_g_sf_marshallOut,
    c9_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_nPoints, 2U, c9_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_p4R, 3U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_R1, 4U, c9_f_sf_marshallOut,
    c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_p4L, 5U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_R5, 6U, c9_f_sf_marshallOut,
    c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c9_k, 7U, c9_e_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_DR, 8U, c9_h_sf_marshallOut,
    c9_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_DL, 9U, c9_h_sf_marshallOut,
    c9_h_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_v4R, 10U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_v4L, 11U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 12U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 13U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_x, 14U, c9_d_sf_marshallOut,
    c9_g_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_FootPoints, 15U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_pR, 16U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_vR, 17U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_J4R, 18U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_JR1Col, 19U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_pL, 20U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_vL, 21U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_J4L, 22U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_JR5Col, 23U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_SCRIPT_FCN(0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 3);
  for (c9_i46 = 0; c9_i46 < 16; c9_i46++) {
    c9_q[c9_i46] = c9_b_x[c9_i46];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 4);
  for (c9_i47 = 0; c9_i47 < 16; c9_i47++) {
    c9_dq[c9_i47] = c9_b_x[c9_i47 + 16];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 6);
  c9_nPoints = 1.0;
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 8);
  for (c9_i48 = 0; c9_i48 < 16; c9_i48++) {
    c9_b_q[c9_i48] = c9_q[c9_i48];
  }

  c9_ATRIAS3D_FootPointPosJacob_Hip(chartInstance, c9_b_q, c9_b_p4R, c9_b_R1,
    c9_c_J4R, c9_c_JR1Col, c9_b_p4L, c9_b_R5, c9_c_J4L, c9_c_JR5Col);
  for (c9_i49 = 0; c9_i49 < 3; c9_i49++) {
    c9_p4R[c9_i49] = c9_b_p4R[c9_i49];
  }

  for (c9_i50 = 0; c9_i50 < 9; c9_i50++) {
    c9_R1[c9_i50] = c9_b_R1[c9_i50];
  }

  for (c9_i51 = 0; c9_i51 < 48; c9_i51++) {
    c9_b_J4R[c9_i51] = c9_c_J4R[c9_i51];
  }

  for (c9_i52 = 0; c9_i52 < 144; c9_i52++) {
    c9_b_JR1Col[c9_i52] = c9_c_JR1Col[c9_i52];
  }

  for (c9_i53 = 0; c9_i53 < 3; c9_i53++) {
    c9_p4L[c9_i53] = c9_b_p4L[c9_i53];
  }

  for (c9_i54 = 0; c9_i54 < 9; c9_i54++) {
    c9_R5[c9_i54] = c9_b_R5[c9_i54];
  }

  for (c9_i55 = 0; c9_i55 < 48; c9_i55++) {
    c9_b_J4L[c9_i55] = c9_c_J4L[c9_i55];
  }

  for (c9_i56 = 0; c9_i56 < 144; c9_i56++) {
    c9_b_JR5Col[c9_i56] = c9_c_JR5Col[c9_i56];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 11);
  for (c9_i57 = 0; c9_i57 < 3; c9_i57++) {
    c9_R5[c9_i57] = -c9_R5[c9_i57];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 12);
  c9_i58 = 0;
  for (c9_i59 = 0; c9_i59 < 16; c9_i59++) {
    for (c9_i60 = 0; c9_i60 < 3; c9_i60++) {
      c9_b_JR5Col[c9_i60 + c9_i58] = -c9_b_JR5Col[c9_i60 + c9_i58];
    }

    c9_i58 += 9;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 15);
  for (c9_i61 = 0; c9_i61 < 3; c9_i61++) {
    c9_b_pR[c9_i61] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 16);
  for (c9_i62 = 0; c9_i62 < 3; c9_i62++) {
    c9_b_pL[c9_i62] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 18);
  c9_k = 1.0;
  CV_SCRIPT_FOR(0, 0, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 19);
  for (c9_i63 = 0; c9_i63 < 9; c9_i63++) {
    c9_b_R1[c9_i63] = c9_R1[c9_i63];
  }

  for (c9_i64 = 0; c9_i64 < 3; c9_i64++) {
    c9_b[c9_i64] = c9_b_FootPoints[c9_i64];
  }

  c9_eml_scalar_eg(chartInstance);
  c9_eml_scalar_eg(chartInstance);
  c9_threshold(chartInstance);
  for (c9_i65 = 0; c9_i65 < 3; c9_i65++) {
    c9_b_p4R[c9_i65] = 0.0;
    c9_i66 = 0;
    for (c9_i67 = 0; c9_i67 < 3; c9_i67++) {
      c9_b_p4R[c9_i65] += c9_b_R1[c9_i66 + c9_i65] * c9_b[c9_i67];
      c9_i66 += 3;
    }
  }

  for (c9_i68 = 0; c9_i68 < 3; c9_i68++) {
    c9_b_pR[c9_i68] = c9_p4R[c9_i68] + c9_b_p4R[c9_i68];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 20);
  for (c9_i69 = 0; c9_i69 < 9; c9_i69++) {
    c9_b_R1[c9_i69] = c9_R5[c9_i69];
  }

  for (c9_i70 = 0; c9_i70 < 3; c9_i70++) {
    c9_b[c9_i70] = c9_b_FootPoints[c9_i70];
  }

  c9_eml_scalar_eg(chartInstance);
  c9_eml_scalar_eg(chartInstance);
  c9_threshold(chartInstance);
  for (c9_i71 = 0; c9_i71 < 3; c9_i71++) {
    c9_b_p4R[c9_i71] = 0.0;
    c9_i72 = 0;
    for (c9_i73 = 0; c9_i73 < 3; c9_i73++) {
      c9_b_p4R[c9_i71] += c9_b_R1[c9_i72 + c9_i71] * c9_b[c9_i73];
      c9_i72 += 3;
    }
  }

  for (c9_i74 = 0; c9_i74 < 3; c9_i74++) {
    c9_b_pL[c9_i74] = c9_p4L[c9_i74] + c9_b_p4R[c9_i74];
  }

  CV_SCRIPT_FOR(0, 0, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 24);
  for (c9_i75 = 0; c9_i75 < 3; c9_i75++) {
    c9_b_vR[c9_i75] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 25);
  for (c9_i76 = 0; c9_i76 < 3; c9_i76++) {
    c9_b_vL[c9_i76] = 0.0;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 26);
  for (c9_i77 = 0; c9_i77 < 144; c9_i77++) {
    c9_c_JR1Col[c9_i77] = c9_b_JR1Col[c9_i77];
  }

  for (c9_i78 = 0; c9_i78 < 16; c9_i78++) {
    c9_b_b[c9_i78] = c9_dq[c9_i78];
  }

  c9_b_eml_scalar_eg(chartInstance);
  c9_b_eml_scalar_eg(chartInstance);
  for (c9_i79 = 0; c9_i79 < 9; c9_i79++) {
    c9_DR[c9_i79] = 0.0;
  }

  for (c9_i80 = 0; c9_i80 < 9; c9_i80++) {
    c9_DR[c9_i80] = 0.0;
  }

  for (c9_i81 = 0; c9_i81 < 9; c9_i81++) {
    c9_C[c9_i81] = c9_DR[c9_i81];
  }

  for (c9_i82 = 0; c9_i82 < 9; c9_i82++) {
    c9_DR[c9_i82] = c9_C[c9_i82];
  }

  c9_threshold(chartInstance);
  for (c9_i83 = 0; c9_i83 < 9; c9_i83++) {
    c9_C[c9_i83] = c9_DR[c9_i83];
  }

  for (c9_i84 = 0; c9_i84 < 9; c9_i84++) {
    c9_DR[c9_i84] = c9_C[c9_i84];
  }

  for (c9_i85 = 0; c9_i85 < 9; c9_i85++) {
    c9_DR[c9_i85] = 0.0;
    c9_i86 = 0;
    for (c9_i87 = 0; c9_i87 < 16; c9_i87++) {
      c9_DR[c9_i85] += c9_c_JR1Col[c9_i86 + c9_i85] * c9_b_b[c9_i87];
      c9_i86 += 9;
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 27);
  for (c9_i88 = 0; c9_i88 < 144; c9_i88++) {
    c9_c_JR1Col[c9_i88] = c9_b_JR5Col[c9_i88];
  }

  for (c9_i89 = 0; c9_i89 < 16; c9_i89++) {
    c9_b_b[c9_i89] = c9_dq[c9_i89];
  }

  c9_b_eml_scalar_eg(chartInstance);
  c9_b_eml_scalar_eg(chartInstance);
  for (c9_i90 = 0; c9_i90 < 9; c9_i90++) {
    c9_DL[c9_i90] = 0.0;
  }

  for (c9_i91 = 0; c9_i91 < 9; c9_i91++) {
    c9_DL[c9_i91] = 0.0;
  }

  for (c9_i92 = 0; c9_i92 < 9; c9_i92++) {
    c9_C[c9_i92] = c9_DL[c9_i92];
  }

  for (c9_i93 = 0; c9_i93 < 9; c9_i93++) {
    c9_DL[c9_i93] = c9_C[c9_i93];
  }

  c9_threshold(chartInstance);
  for (c9_i94 = 0; c9_i94 < 9; c9_i94++) {
    c9_C[c9_i94] = c9_DL[c9_i94];
  }

  for (c9_i95 = 0; c9_i95 < 9; c9_i95++) {
    c9_DL[c9_i95] = c9_C[c9_i95];
  }

  for (c9_i96 = 0; c9_i96 < 9; c9_i96++) {
    c9_DL[c9_i96] = 0.0;
    c9_i97 = 0;
    for (c9_i98 = 0; c9_i98 < 16; c9_i98++) {
      c9_DL[c9_i96] += c9_c_JR1Col[c9_i97 + c9_i96] * c9_b_b[c9_i98];
      c9_i97 += 9;
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 28);
  for (c9_i99 = 0; c9_i99 < 48; c9_i99++) {
    c9_c_J4R[c9_i99] = c9_b_J4R[c9_i99];
  }

  for (c9_i100 = 0; c9_i100 < 16; c9_i100++) {
    c9_b_b[c9_i100] = c9_dq[c9_i100];
  }

  c9_c_eml_scalar_eg(chartInstance);
  c9_c_eml_scalar_eg(chartInstance);
  for (c9_i101 = 0; c9_i101 < 3; c9_i101++) {
    c9_v4R[c9_i101] = 0.0;
  }

  for (c9_i102 = 0; c9_i102 < 3; c9_i102++) {
    c9_v4R[c9_i102] = 0.0;
  }

  for (c9_i103 = 0; c9_i103 < 3; c9_i103++) {
    c9_b_p4R[c9_i103] = c9_v4R[c9_i103];
  }

  for (c9_i104 = 0; c9_i104 < 3; c9_i104++) {
    c9_v4R[c9_i104] = c9_b_p4R[c9_i104];
  }

  c9_threshold(chartInstance);
  for (c9_i105 = 0; c9_i105 < 3; c9_i105++) {
    c9_b_p4R[c9_i105] = c9_v4R[c9_i105];
  }

  for (c9_i106 = 0; c9_i106 < 3; c9_i106++) {
    c9_v4R[c9_i106] = c9_b_p4R[c9_i106];
  }

  for (c9_i107 = 0; c9_i107 < 3; c9_i107++) {
    c9_v4R[c9_i107] = 0.0;
    c9_i108 = 0;
    for (c9_i109 = 0; c9_i109 < 16; c9_i109++) {
      c9_v4R[c9_i107] += c9_c_J4R[c9_i108 + c9_i107] * c9_b_b[c9_i109];
      c9_i108 += 3;
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 29);
  for (c9_i110 = 0; c9_i110 < 48; c9_i110++) {
    c9_c_J4R[c9_i110] = c9_b_J4L[c9_i110];
  }

  for (c9_i111 = 0; c9_i111 < 16; c9_i111++) {
    c9_b_b[c9_i111] = c9_dq[c9_i111];
  }

  c9_c_eml_scalar_eg(chartInstance);
  c9_c_eml_scalar_eg(chartInstance);
  for (c9_i112 = 0; c9_i112 < 3; c9_i112++) {
    c9_v4L[c9_i112] = 0.0;
  }

  for (c9_i113 = 0; c9_i113 < 3; c9_i113++) {
    c9_v4L[c9_i113] = 0.0;
  }

  for (c9_i114 = 0; c9_i114 < 3; c9_i114++) {
    c9_b_p4R[c9_i114] = c9_v4L[c9_i114];
  }

  for (c9_i115 = 0; c9_i115 < 3; c9_i115++) {
    c9_v4L[c9_i115] = c9_b_p4R[c9_i115];
  }

  c9_threshold(chartInstance);
  for (c9_i116 = 0; c9_i116 < 3; c9_i116++) {
    c9_b_p4R[c9_i116] = c9_v4L[c9_i116];
  }

  for (c9_i117 = 0; c9_i117 < 3; c9_i117++) {
    c9_v4L[c9_i117] = c9_b_p4R[c9_i117];
  }

  for (c9_i118 = 0; c9_i118 < 3; c9_i118++) {
    c9_v4L[c9_i118] = 0.0;
    c9_i119 = 0;
    for (c9_i120 = 0; c9_i120 < 16; c9_i120++) {
      c9_v4L[c9_i118] += c9_c_J4R[c9_i119 + c9_i118] * c9_b_b[c9_i120];
      c9_i119 += 3;
    }
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 31);
  c9_k = 1.0;
  CV_SCRIPT_FOR(0, 1, 1);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 32);
  c9_a = c9_b_FootPoints[0];
  for (c9_i121 = 0; c9_i121 < 3; c9_i121++) {
    c9_b[c9_i121] = c9_DR[c9_i121];
  }

  for (c9_i122 = 0; c9_i122 < 3; c9_i122++) {
    c9_b[c9_i122] *= c9_a;
  }

  c9_b_a = c9_b_FootPoints[1];
  for (c9_i123 = 0; c9_i123 < 3; c9_i123++) {
    c9_b_p4R[c9_i123] = c9_DR[c9_i123 + 3];
  }

  for (c9_i124 = 0; c9_i124 < 3; c9_i124++) {
    c9_b_p4R[c9_i124] *= c9_b_a;
  }

  c9_c_a = c9_b_FootPoints[2];
  for (c9_i125 = 0; c9_i125 < 3; c9_i125++) {
    c9_b_p4L[c9_i125] = c9_DR[c9_i125 + 6];
  }

  for (c9_i126 = 0; c9_i126 < 3; c9_i126++) {
    c9_b_p4L[c9_i126] *= c9_c_a;
  }

  for (c9_i127 = 0; c9_i127 < 3; c9_i127++) {
    c9_b_vR[c9_i127] = ((c9_v4R[c9_i127] + c9_b[c9_i127]) + c9_b_p4R[c9_i127]) +
      c9_b_p4L[c9_i127];
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 33);
  c9_d_a = c9_b_FootPoints[0];
  for (c9_i128 = 0; c9_i128 < 3; c9_i128++) {
    c9_b[c9_i128] = c9_DL[c9_i128];
  }

  for (c9_i129 = 0; c9_i129 < 3; c9_i129++) {
    c9_b[c9_i129] *= c9_d_a;
  }

  c9_e_a = c9_b_FootPoints[1];
  for (c9_i130 = 0; c9_i130 < 3; c9_i130++) {
    c9_b_p4R[c9_i130] = c9_DL[c9_i130 + 3];
  }

  for (c9_i131 = 0; c9_i131 < 3; c9_i131++) {
    c9_b_p4R[c9_i131] *= c9_e_a;
  }

  c9_f_a = c9_b_FootPoints[2];
  for (c9_i132 = 0; c9_i132 < 3; c9_i132++) {
    c9_b_p4L[c9_i132] = c9_DL[c9_i132 + 6];
  }

  for (c9_i133 = 0; c9_i133 < 3; c9_i133++) {
    c9_b_p4L[c9_i133] *= c9_f_a;
  }

  for (c9_i134 = 0; c9_i134 < 3; c9_i134++) {
    c9_b_vL[c9_i134] = ((c9_v4L[c9_i134] + c9_b[c9_i134]) + c9_b_p4R[c9_i134]) +
      c9_b_p4L[c9_i134];
  }

  CV_SCRIPT_FOR(0, 1, 0);
  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 37);
  c9_eml_li_find(chartInstance, c9_b_pR[1] < 0.0, c9_tmp_data, c9_tmp_sizes);
  c9_b_tmp_sizes = c9_tmp_sizes[1];
  c9_loop_ub = c9_tmp_sizes[1] - 1;
  for (c9_i135 = 0; c9_i135 <= c9_loop_ub; c9_i135++) {
    c9_b_tmp_data[c9_i135] = c9_tmp_data[c9_tmp_sizes[0] * c9_i135] - 1;
  }

  c9_eml_li_find(chartInstance, c9_b_pR[1] < 0.0, c9_tmp_data, c9_tmp_sizes);
  c9_c_tmp_sizes[0] = 1;
  c9_c_tmp_sizes[1] = c9_tmp_sizes[1];
  c9_b_loop_ub = c9_tmp_sizes[1] - 1;
  for (c9_i136 = 0; c9_i136 <= c9_b_loop_ub; c9_i136++) {
    c9_c_tmp_data[c9_c_tmp_sizes[0] * c9_i136] = c9_b_pR[2];
  }

  c9_iv0[0] = 1;
  c9_iv0[1] = c9_b_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c9_iv0, 2, c9_c_tmp_sizes, 2);
  c9_c_loop_ub = c9_c_tmp_sizes[1] - 1;
  for (c9_i137 = 0; c9_i137 <= c9_c_loop_ub; c9_i137++) {
    c9_b_pR[2] = c9_c_tmp_data[c9_c_tmp_sizes[0] * c9_i137] - 0.01;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, 38);
  c9_eml_li_find(chartInstance, c9_b_pL[1] < 0.0, c9_tmp_data, c9_tmp_sizes);
  c9_b_tmp_sizes = c9_tmp_sizes[1];
  c9_d_loop_ub = c9_tmp_sizes[1] - 1;
  for (c9_i138 = 0; c9_i138 <= c9_d_loop_ub; c9_i138++) {
    c9_b_tmp_data[c9_i138] = c9_tmp_data[c9_tmp_sizes[0] * c9_i138] - 1;
  }

  c9_eml_li_find(chartInstance, c9_b_pL[1] < 0.0, c9_tmp_data, c9_tmp_sizes);
  c9_c_tmp_sizes[0] = 1;
  c9_c_tmp_sizes[1] = c9_tmp_sizes[1];
  c9_e_loop_ub = c9_tmp_sizes[1] - 1;
  for (c9_i139 = 0; c9_i139 <= c9_e_loop_ub; c9_i139++) {
    c9_c_tmp_data[c9_c_tmp_sizes[0] * c9_i139] = c9_b_pL[2];
  }

  c9_iv1[0] = 1;
  c9_iv1[1] = c9_b_tmp_sizes;
  _SFD_SUB_ASSIGN_SIZE_CHECK_ND(c9_iv1, 2, c9_c_tmp_sizes, 2);
  c9_f_loop_ub = c9_c_tmp_sizes[1] - 1;
  for (c9_i140 = 0; c9_i140 <= c9_f_loop_ub; c9_i140++) {
    c9_b_pL[2] = c9_c_tmp_data[c9_c_tmp_sizes[0] * c9_i140] - 0.01;
  }

  _SFD_SCRIPT_CALL(0U, chartInstance->c9_sfEvent, -38);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c9_ATRIAS3D_FootPointPosJacob_Hip(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, real_T c9_q[16], real_T c9_p4R[3], real_T c9_R1[9], real_T
  c9_b_J4R[48], real_T c9_b_JR1Col[144], real_T c9_p4L[3], real_T c9_R5[9],
  real_T c9_b_J4L[48], real_T c9_b_JR5Col[144])
{
  uint32_T c9_debug_family_var_map[106];
  real_T c9_xT;
  real_T c9_yT;
  real_T c9_zT;
  real_T c9_qzT;
  real_T c9_qyT;
  real_T c9_qxT;
  real_T c9_q1R;
  real_T c9_q2R;
  real_T c9_q1L;
  real_T c9_q2L;
  real_T c9_qgr1R;
  real_T c9_qgr2R;
  real_T c9_q3R;
  real_T c9_qgr1L;
  real_T c9_qgr2L;
  real_T c9_q3L;
  real_T c9_t1;
  real_T c9_t2;
  real_T c9_t3;
  real_T c9_t4;
  real_T c9_t7;
  real_T c9_t8;
  real_T c9_t10;
  real_T c9_t11;
  real_T c9_t12;
  real_T c9_t14;
  real_T c9_t15;
  real_T c9_t20;
  real_T c9_t21;
  real_T c9_t26;
  real_T c9_t27;
  real_T c9_t30;
  real_T c9_t33;
  real_T c9_t37;
  real_T c9_t41;
  real_T c9_t43;
  real_T c9_t48;
  real_T c9_t53;
  real_T c9_t63;
  real_T c9_t66;
  real_T c9_t71;
  real_T c9_t6;
  real_T c9_t9;
  real_T c9_t13;
  real_T c9_t19;
  real_T c9_t24;
  real_T c9_t25;
  real_T c9_t31;
  real_T c9_t34;
  real_T c9_t36;
  real_T c9_t45;
  real_T c9_t52;
  real_T c9_t55;
  real_T c9_t59;
  real_T c9_t5;
  real_T c9_t40;
  real_T c9_t44;
  real_T c9_t50;
  real_T c9_t61;
  real_T c9_t69;
  real_T c9_t79;
  real_T c9_t80;
  real_T c9_t81;
  real_T c9_t92;
  real_T c9_t93;
  real_T c9_t94;
  real_T c9_t119;
  real_T c9_t131;
  real_T c9_t141;
  real_T c9_t142;
  real_T c9_t154;
  real_T c9_t162;
  real_T c9_t165;
  real_T c9_t170;
  real_T c9_t178;
  real_T c9_t181;
  real_T c9_t195;
  real_T c9_t196;
  real_T c9_t197;
  real_T c9_t210;
  real_T c9_t17;
  real_T c9_t32;
  real_T c9_t35;
  real_T c9_t47;
  real_T c9_t56;
  real_T c9_t60;
  real_T c9_t68;
  real_T c9_t72;
  real_T c9_t77;
  real_T c9_t85;
  real_T c9_t89;
  real_T c9_t96;
  real_T c9_t98;
  real_T c9_t102;
  real_T c9_t114;
  real_T c9_nargin = 1.0;
  real_T c9_nargout = 8.0;
  int32_T c9_i141;
  real_T c9_b_x;
  real_T c9_c_x;
  real_T c9_d_x;
  real_T c9_e_x;
  real_T c9_f_x;
  real_T c9_g_x;
  real_T c9_h_x;
  real_T c9_i_x;
  real_T c9_j_x;
  real_T c9_k_x;
  real_T c9_l_x;
  real_T c9_m_x;
  real_T c9_n_x;
  real_T c9_o_x;
  real_T c9_p_x;
  real_T c9_q_x;
  real_T c9_r_x;
  real_T c9_s_x;
  real_T c9_t_x;
  real_T c9_u_x;
  real_T c9_v_x;
  real_T c9_w_x;
  real_T c9_x_x;
  real_T c9_y_x;
  int32_T c9_i142;
  real_T c9_ab_x;
  real_T c9_bb_x;
  real_T c9_cb_x;
  real_T c9_db_x;
  real_T c9_eb_x;
  real_T c9_fb_x;
  real_T c9_gb_x;
  real_T c9_hb_x;
  real_T c9_ib_x;
  real_T c9_jb_x;
  real_T c9_kb_x;
  real_T c9_lb_x;
  real_T c9_mb_x;
  real_T c9_nb_x;
  real_T c9_ob_x;
  real_T c9_pb_x;
  real_T c9_qb_x;
  real_T c9_rb_x;
  real_T c9_sb_x;
  real_T c9_tb_x;
  int32_T c9_i143;
  real_T c9_ub_x;
  real_T c9_vb_x;
  real_T c9_wb_x;
  real_T c9_xb_x;
  real_T c9_yb_x;
  real_T c9_ac_x;
  real_T c9_bc_x;
  real_T c9_cc_x;
  real_T c9_dc_x;
  real_T c9_ec_x;
  real_T c9_fc_x;
  real_T c9_gc_x;
  real_T c9_hc_x;
  real_T c9_ic_x;
  real_T c9_jc_x;
  real_T c9_kc_x;
  real_T c9_lc_x;
  real_T c9_mc_x;
  real_T c9_nc_x;
  real_T c9_oc_x;
  real_T c9_pc_x;
  real_T c9_qc_x;
  real_T c9_rc_x;
  real_T c9_sc_x;
  int32_T c9_i144;
  real_T c9_tc_x;
  real_T c9_uc_x;
  real_T c9_vc_x;
  real_T c9_wc_x;
  real_T c9_xc_x;
  real_T c9_yc_x;
  real_T c9_ad_x;
  real_T c9_bd_x;
  real_T c9_cd_x;
  real_T c9_dd_x;
  real_T c9_ed_x;
  real_T c9_fd_x;
  real_T c9_gd_x;
  real_T c9_hd_x;
  real_T c9_id_x;
  real_T c9_jd_x;
  real_T c9_kd_x;
  real_T c9_ld_x;
  real_T c9_md_x;
  real_T c9_nd_x;
  int32_T c9_i145;
  real_T c9_od_x;
  real_T c9_pd_x;
  real_T c9_qd_x;
  real_T c9_rd_x;
  real_T c9_sd_x;
  real_T c9_td_x;
  real_T c9_ud_x;
  real_T c9_vd_x;
  real_T c9_wd_x;
  real_T c9_xd_x;
  real_T c9_yd_x;
  real_T c9_ae_x;
  real_T c9_be_x;
  real_T c9_ce_x;
  real_T c9_de_x;
  real_T c9_ee_x;
  real_T c9_fe_x;
  real_T c9_ge_x;
  real_T c9_he_x;
  real_T c9_ie_x;
  real_T c9_je_x;
  real_T c9_ke_x;
  real_T c9_le_x;
  real_T c9_me_x;
  int32_T c9_i146;
  real_T c9_ne_x;
  real_T c9_oe_x;
  real_T c9_pe_x;
  real_T c9_qe_x;
  real_T c9_re_x;
  real_T c9_se_x;
  real_T c9_te_x;
  real_T c9_ue_x;
  real_T c9_ve_x;
  real_T c9_we_x;
  real_T c9_xe_x;
  real_T c9_ye_x;
  real_T c9_af_x;
  real_T c9_bf_x;
  real_T c9_cf_x;
  real_T c9_df_x;
  real_T c9_ef_x;
  real_T c9_ff_x;
  real_T c9_gf_x;
  real_T c9_hf_x;
  int32_T c9_i147;
  real_T c9_if_x;
  real_T c9_jf_x;
  real_T c9_kf_x;
  real_T c9_lf_x;
  real_T c9_mf_x;
  real_T c9_nf_x;
  real_T c9_of_x;
  real_T c9_pf_x;
  real_T c9_qf_x;
  real_T c9_rf_x;
  real_T c9_sf_x;
  real_T c9_tf_x;
  real_T c9_uf_x;
  real_T c9_vf_x;
  real_T c9_wf_x;
  real_T c9_xf_x;
  real_T c9_yf_x;
  real_T c9_ag_x;
  real_T c9_bg_x;
  real_T c9_cg_x;
  real_T c9_dg_x;
  real_T c9_eg_x;
  real_T c9_fg_x;
  real_T c9_gg_x;
  int32_T c9_i148;
  real_T c9_hg_x;
  real_T c9_ig_x;
  real_T c9_jg_x;
  real_T c9_kg_x;
  real_T c9_lg_x;
  real_T c9_mg_x;
  real_T c9_ng_x;
  real_T c9_og_x;
  real_T c9_pg_x;
  real_T c9_qg_x;
  real_T c9_rg_x;
  real_T c9_sg_x;
  real_T c9_tg_x;
  real_T c9_ug_x;
  real_T c9_vg_x;
  real_T c9_wg_x;
  real_T c9_xg_x;
  real_T c9_yg_x;
  real_T c9_ah_x;
  real_T c9_bh_x;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 106U, 106U, c9_b_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_xT, 0U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_yT, 1U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_zT, 2U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_qzT, 3U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_qyT, 4U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_qxT, 5U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_q1R, 6U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_q2R, 7U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_q1L, 8U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_q2L, 9U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_qgr1R, 10U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_qgr2R, 11U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_q3R, 12U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_qgr1L, 13U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_qgr2L, 14U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_q3L, 15U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t1, 16U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t2, 17U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t3, 18U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t4, 19U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t7, 20U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t8, 21U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t10, 22U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t11, 23U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t12, 24U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t14, 25U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t15, 26U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t20, 27U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t21, 28U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t26, 29U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t27, 30U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t30, 31U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t33, 32U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t37, 33U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t41, 34U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t43, 35U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t48, 36U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t53, 37U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t63, 38U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t66, 39U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t71, 40U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t6, 41U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t9, 42U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t13, 43U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t19, 44U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t24, 45U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t25, 46U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t31, 47U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t34, 48U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t36, 49U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t45, 50U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t52, 51U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t55, 52U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t59, 53U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t5, 54U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t40, 55U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t44, 56U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t50, 57U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t61, 58U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t69, 59U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t79, 60U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t80, 61U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t81, 62U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t92, 63U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t93, 64U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t94, 65U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t119, 66U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t131, 67U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t141, 68U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t142, 69U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t154, 70U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t162, 71U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t165, 72U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t170, 73U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t178, 74U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t181, 75U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t195, 76U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t196, 77U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t197, 78U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t210, 79U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t17, 80U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t32, 81U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t35, 82U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t47, 83U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t56, 84U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t60, 85U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t68, 86U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t72, 87U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t77, 88U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t85, 89U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t89, 90U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t96, 91U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t98, 92U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t102, 93U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_t114, 94U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 95U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 96U, c9_e_sf_marshallOut,
    c9_d_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_q, 97U, c9_g_sf_marshallOut,
    c9_f_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_p4R, 98U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_R1, 99U, c9_f_sf_marshallOut,
    c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_J4R, 100U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_JR1Col, 101U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_p4L, 102U, c9_c_sf_marshallOut,
    c9_c_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_R5, 103U, c9_f_sf_marshallOut,
    c9_e_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_J4L, 104U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c9_b_JR5Col, 105U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_SCRIPT_FCN(1, 0);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 4);
  c9_xT = c9_q[0];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 5);
  c9_yT = c9_q[1];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 6);
  c9_zT = c9_q[2];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 7);
  c9_qzT = c9_q[3];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 8);
  c9_qyT = c9_q[4];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 9);
  c9_qxT = c9_q[5];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 10);
  c9_q1R = c9_q[6];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 11);
  c9_q2R = c9_q[7];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 12);
  c9_q1L = c9_q[8];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 13);
  c9_q2L = c9_q[9];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 14);
  c9_qgr1R = c9_q[10];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 15);
  c9_qgr2R = c9_q[11];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 16);
  c9_q3R = c9_q[12];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 17);
  c9_qgr1L = c9_q[13];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 18);
  c9_qgr2L = c9_q[14];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 19);
  c9_q3L = c9_q[15];
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 21);
  for (c9_i141 = 0; c9_i141 < 3; c9_i141++) {
    c9_p4R[c9_i141] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 22);
  c9_b_x = c9_qzT;
  c9_t1 = c9_b_x;
  c9_c_x = c9_t1;
  c9_t1 = c9_c_x;
  c9_t1 = muDoubleScalarCos(c9_t1);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 23);
  c9_d_x = c9_qyT;
  c9_t2 = c9_d_x;
  c9_e_x = c9_t2;
  c9_t2 = c9_e_x;
  c9_t2 = muDoubleScalarCos(c9_t2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 24);
  c9_t3 = c9_t1 * c9_t2;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 25);
  c9_f_x = c9_q3R;
  c9_t4 = c9_f_x;
  c9_g_x = c9_t4;
  c9_t4 = c9_g_x;
  c9_t4 = muDoubleScalarCos(c9_t4);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 26);
  c9_h_x = c9_qzT;
  c9_t7 = c9_h_x;
  c9_i_x = c9_t7;
  c9_t7 = c9_i_x;
  c9_t7 = muDoubleScalarSin(c9_t7);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 27);
  c9_j_x = c9_qxT;
  c9_t8 = c9_j_x;
  c9_k_x = c9_t8;
  c9_t8 = c9_k_x;
  c9_t8 = muDoubleScalarSin(c9_t8);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 28);
  c9_l_x = c9_qyT;
  c9_t10 = c9_l_x;
  c9_m_x = c9_t10;
  c9_t10 = c9_m_x;
  c9_t10 = muDoubleScalarSin(c9_t10);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 29);
  c9_t11 = c9_t1 * c9_t10;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 30);
  c9_n_x = c9_qxT;
  c9_t12 = c9_n_x;
  c9_o_x = c9_t12;
  c9_t12 = c9_o_x;
  c9_t12 = muDoubleScalarCos(c9_t12);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 31);
  c9_t14 = c9_t7 * c9_t8 + c9_t11 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 32);
  c9_p_x = c9_q3R;
  c9_t15 = c9_p_x;
  c9_q_x = c9_t15;
  c9_t15 = c9_q_x;
  c9_t15 = muDoubleScalarSin(c9_t15);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 33);
  c9_t20 = -c9_t7 * c9_t12 + c9_t11 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 34);
  c9_r_x = c9_q2R;
  c9_t21 = c9_r_x;
  c9_s_x = c9_t21;
  c9_t21 = c9_s_x;
  c9_t21 = muDoubleScalarSin(c9_t21);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 35);
  c9_t26 = c9_t3 * c9_t15 + c9_t14 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 36);
  c9_t_x = c9_q2R;
  c9_t27 = c9_t_x;
  c9_u_x = c9_t27;
  c9_t27 = c9_u_x;
  c9_t27 = muDoubleScalarCos(c9_t27);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 37);
  c9_v_x = c9_q1R;
  c9_t30 = c9_v_x;
  c9_w_x = c9_t30;
  c9_t30 = c9_w_x;
  c9_t30 = muDoubleScalarSin(c9_t30);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 38);
  c9_x_x = c9_q1R;
  c9_t33 = c9_x_x;
  c9_y_x = c9_t33;
  c9_t33 = c9_y_x;
  c9_t33 = muDoubleScalarCos(c9_t33);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 39);
  c9_t37 = c9_t2 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 40);
  c9_t41 = c9_t10 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 41);
  c9_t43 = -c9_t1 * c9_t8 + c9_t41 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 42);
  c9_t48 = c9_t1 * c9_t12 + c9_t41 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 43);
  c9_t53 = c9_t37 * c9_t15 + c9_t43 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 44);
  c9_t63 = c9_t2 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 45);
  c9_t66 = c9_t2 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 46);
  c9_t71 = -c9_t10 * c9_t15 + c9_t63 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 47);
  c9_p4R[0] = (((((c9_xT + 0.1834 * c9_t3 * c9_t4) - 0.1834 * c9_t14 * c9_t15) -
                 0.5 * c9_t20 * c9_t21) + 0.5 * c9_t26 * c9_t27) - 0.5 * c9_t20 *
               c9_t30) + 0.5 * c9_t26 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 48);
  c9_p4R[1] = (((((c9_yT + 0.1834 * c9_t37 * c9_t4) - 0.1834 * c9_t43 * c9_t15)
                 - 0.5 * c9_t48 * c9_t21) + 0.5 * c9_t53 * c9_t27) - 0.5 *
               c9_t48 * c9_t30) + 0.5 * c9_t53 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 49);
  c9_p4R[2] = (((((c9_zT - 0.1834 * c9_t10 * c9_t4) - 0.1834 * c9_t63 * c9_t15)
                 - 0.5 * c9_t66 * c9_t21) + 0.5 * c9_t71 * c9_t27) - 0.5 *
               c9_t66 * c9_t30) + 0.5 * c9_t71 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 51);
  for (c9_i142 = 0; c9_i142 < 9; c9_i142++) {
    c9_R1[c9_i142] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 52);
  c9_ab_x = c9_qzT;
  c9_t1 = c9_ab_x;
  c9_bb_x = c9_t1;
  c9_t1 = c9_bb_x;
  c9_t1 = muDoubleScalarCos(c9_t1);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 53);
  c9_cb_x = c9_qyT;
  c9_t2 = c9_cb_x;
  c9_db_x = c9_t2;
  c9_t2 = c9_db_x;
  c9_t2 = muDoubleScalarCos(c9_t2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 54);
  c9_t3 = c9_t1 * c9_t2;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 55);
  c9_eb_x = c9_q3R;
  c9_t4 = c9_eb_x;
  c9_fb_x = c9_t4;
  c9_t4 = c9_fb_x;
  c9_t4 = muDoubleScalarCos(c9_t4);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 56);
  c9_gb_x = c9_qzT;
  c9_t6 = c9_gb_x;
  c9_hb_x = c9_t6;
  c9_t6 = c9_hb_x;
  c9_t6 = muDoubleScalarSin(c9_t6);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 57);
  c9_ib_x = c9_qxT;
  c9_t7 = c9_ib_x;
  c9_jb_x = c9_t7;
  c9_t7 = c9_jb_x;
  c9_t7 = muDoubleScalarSin(c9_t7);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 58);
  c9_kb_x = c9_qyT;
  c9_t9 = c9_kb_x;
  c9_lb_x = c9_t9;
  c9_t9 = c9_lb_x;
  c9_t9 = muDoubleScalarSin(c9_t9);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 59);
  c9_t10 = c9_t1 * c9_t9;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 60);
  c9_mb_x = c9_qxT;
  c9_t11 = c9_mb_x;
  c9_nb_x = c9_t11;
  c9_t11 = c9_nb_x;
  c9_t11 = muDoubleScalarCos(c9_t11);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 61);
  c9_t13 = c9_t6 * c9_t7 + c9_t10 * c9_t11;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 62);
  c9_ob_x = c9_q3R;
  c9_t14 = c9_ob_x;
  c9_pb_x = c9_t14;
  c9_t14 = c9_pb_x;
  c9_t14 = muDoubleScalarSin(c9_t14);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 63);
  c9_t19 = -c9_t6 * c9_t11 + c9_t10 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 64);
  c9_qb_x = c9_q1R;
  c9_t20 = c9_qb_x;
  c9_rb_x = c9_t20;
  c9_t20 = c9_rb_x;
  c9_t20 = muDoubleScalarCos(c9_t20);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 65);
  c9_t24 = c9_t3 * c9_t14 + c9_t13 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 66);
  c9_sb_x = c9_q1R;
  c9_t25 = c9_sb_x;
  c9_tb_x = c9_t25;
  c9_t25 = c9_tb_x;
  c9_t25 = muDoubleScalarSin(c9_t25);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 67);
  c9_t31 = c9_t2 * c9_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 68);
  c9_t34 = c9_t9 * c9_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 69);
  c9_t36 = -c9_t1 * c9_t7 + c9_t34 * c9_t11;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 70);
  c9_t41 = c9_t1 * c9_t11 + c9_t34 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 71);
  c9_t45 = c9_t31 * c9_t14 + c9_t36 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 72);
  c9_t52 = c9_t11 * c9_t2;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 73);
  c9_t55 = c9_t2 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 74);
  c9_t59 = -c9_t9 * c9_t14 + c9_t52 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 75);
  c9_R1[0] = c9_t3 * c9_t4 - c9_t13 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 76);
  c9_R1[3] = c9_t19 * c9_t20 + c9_t24 * c9_t25;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 77);
  c9_R1[6] = -c9_t19 * c9_t25 + c9_t24 * c9_t20;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 78);
  c9_R1[1] = c9_t31 * c9_t4 - c9_t36 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 79);
  c9_R1[4] = c9_t41 * c9_t20 + c9_t45 * c9_t25;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 80);
  c9_R1[7] = -c9_t41 * c9_t25 + c9_t45 * c9_t20;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 81);
  c9_R1[2] = -c9_t9 * c9_t4 - c9_t52 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 82);
  c9_R1[5] = c9_t55 * c9_t20 + c9_t59 * c9_t25;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 83);
  c9_R1[8] = -c9_t55 * c9_t25 + c9_t59 * c9_t20;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 85);
  for (c9_i143 = 0; c9_i143 < 48; c9_i143++) {
    c9_b_J4R[c9_i143] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 86);
  c9_ub_x = c9_qzT;
  c9_t1 = c9_ub_x;
  c9_vb_x = c9_t1;
  c9_t1 = c9_vb_x;
  c9_t1 = muDoubleScalarSin(c9_t1);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 87);
  c9_wb_x = c9_qyT;
  c9_t2 = c9_wb_x;
  c9_xb_x = c9_t2;
  c9_t2 = c9_xb_x;
  c9_t2 = muDoubleScalarCos(c9_t2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 88);
  c9_t3 = c9_t1 * c9_t2;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 89);
  c9_yb_x = c9_q3R;
  c9_t4 = c9_yb_x;
  c9_ac_x = c9_t4;
  c9_t4 = c9_ac_x;
  c9_t4 = muDoubleScalarCos(c9_t4);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 90);
  c9_t5 = c9_t3 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 91);
  c9_bc_x = c9_qzT;
  c9_t7 = c9_bc_x;
  c9_cc_x = c9_t7;
  c9_t7 = c9_cc_x;
  c9_t7 = muDoubleScalarCos(c9_t7);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 92);
  c9_dc_x = c9_qxT;
  c9_t8 = c9_dc_x;
  c9_ec_x = c9_t8;
  c9_t8 = c9_ec_x;
  c9_t8 = muDoubleScalarSin(c9_t8);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 93);
  c9_fc_x = c9_qyT;
  c9_t10 = c9_fc_x;
  c9_gc_x = c9_t10;
  c9_t10 = c9_gc_x;
  c9_t10 = muDoubleScalarSin(c9_t10);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 94);
  c9_t11 = c9_t1 * c9_t10;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 95);
  c9_hc_x = c9_qxT;
  c9_t12 = c9_hc_x;
  c9_ic_x = c9_t12;
  c9_t12 = c9_ic_x;
  c9_t12 = muDoubleScalarCos(c9_t12);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 96);
  c9_t14 = c9_t7 * c9_t8 - c9_t11 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 97);
  c9_jc_x = c9_q3R;
  c9_t15 = c9_jc_x;
  c9_kc_x = c9_t15;
  c9_t15 = c9_kc_x;
  c9_t15 = muDoubleScalarSin(c9_t15);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 98);
  c9_t20 = -c9_t7 * c9_t12 - c9_t11 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 99);
  c9_lc_x = c9_q2R;
  c9_t21 = c9_lc_x;
  c9_mc_x = c9_t21;
  c9_t21 = c9_mc_x;
  c9_t21 = muDoubleScalarSin(c9_t21);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 100);
  c9_t24 = c9_t3 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 101);
  c9_t26 = -c9_t24 + c9_t14 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 102);
  c9_nc_x = c9_q2R;
  c9_t27 = c9_nc_x;
  c9_oc_x = c9_t27;
  c9_t27 = c9_oc_x;
  c9_t27 = muDoubleScalarCos(c9_t27);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 103);
  c9_pc_x = c9_q1R;
  c9_t30 = c9_pc_x;
  c9_qc_x = c9_t30;
  c9_t30 = c9_qc_x;
  c9_t30 = muDoubleScalarSin(c9_t30);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 104);
  c9_rc_x = c9_q1R;
  c9_t33 = c9_rc_x;
  c9_sc_x = c9_t33;
  c9_t33 = c9_sc_x;
  c9_t33 = muDoubleScalarCos(c9_t33);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 105);
  c9_t37 = c9_t10 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 106);
  c9_t40 = c9_t2 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 107);
  c9_t41 = c9_t12 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 108);
  c9_t44 = c9_t8 * c9_t21;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 109);
  c9_t48 = c9_t12 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 110);
  c9_t50 = -c9_t37 * c9_t15 + c9_t40 * c9_t48;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 111);
  c9_t53 = c9_t8 * c9_t30;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 112);
  c9_t61 = c9_t1 * c9_t12 - c9_t37 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 113);
  c9_t66 = c9_t1 * c9_t8 + c9_t37 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 114);
  c9_t69 = c9_t61 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 115);
  c9_t79 = c9_t40 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 116);
  c9_t80 = c9_t66 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 117);
  c9_t81 = c9_t79 + c9_t80;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 118);
  c9_t92 = c9_t40 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 119);
  c9_t93 = c9_t66 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 120);
  c9_t94 = c9_t92 - c9_t93;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 121);
  c9_t119 = -c9_t11 * c9_t15 + c9_t3 * c9_t48;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 122);
  c9_t131 = c9_t20 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 123);
  c9_t141 = -c9_t14 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 124);
  c9_t142 = c9_t24 + c9_t141;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 125);
  c9_t154 = c9_t5 + c9_t14 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 126);
  c9_t162 = c9_t10 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, MAX_int8_T);
  c9_t165 = c9_t10 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 128U);
  c9_t170 = -c9_t2 * c9_t15 - c9_t162 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 129U);
  c9_t178 = c9_t2 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 130U);
  c9_t181 = c9_t2 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 131U);
  c9_t195 = c9_t10 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 132U);
  c9_t196 = c9_t181 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 133U);
  c9_t197 = -c9_t195 + c9_t196;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 134U);
  c9_t210 = -c9_t10 * c9_t4 - c9_t181 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 135U);
  c9_b_J4R[0] = 1.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 136U);
  c9_b_J4R[3] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 137U);
  c9_b_J4R[6] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 138U);
  c9_b_J4R[9] = ((((-0.1834 * c9_t5 - 0.1834 * c9_t14 * c9_t15) - 0.5 * c9_t20 *
                   c9_t21) + 0.5 * c9_t26 * c9_t27) - 0.5 * c9_t20 * c9_t30) +
    0.5 * c9_t26 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 139U);
  c9_b_J4R[12] = ((((-0.1834 * c9_t37 * c9_t4 - 0.1834 * c9_t40 * c9_t41) - 0.5 *
                    c9_t40 * c9_t44) + 0.5 * c9_t50 * c9_t27) - 0.5 * c9_t40 *
                  c9_t53) + 0.5 * c9_t50 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 140U);
  c9_b_J4R[15] = (((-0.1834 * c9_t61 * c9_t15 - 0.5 * c9_t66 * c9_t21) + 0.5 *
                   c9_t69 * c9_t27) - 0.5 * c9_t66 * c9_t30) + 0.5 * c9_t69 *
    c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 141U);
  c9_b_J4R[18] = 0.5 * c9_t61 * c9_t33 - 0.5 * c9_t81 * c9_t30;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 142U);
  c9_b_J4R[21] = 0.5 * c9_t61 * c9_t27 - 0.5 * c9_t81 * c9_t21;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 143U);
  c9_b_J4R[24] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 144U);
  c9_b_J4R[27] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 145U);
  c9_b_J4R[30] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 146U);
  c9_b_J4R[33] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 147U);
  c9_b_J4R[36] = ((-0.1834 * c9_t79 - 0.1834 * c9_t80) + 0.5 * c9_t94 * c9_t27)
    + 0.5 * c9_t94 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 148U);
  c9_b_J4R[39] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 149U);
  c9_b_J4R[42] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 150U);
  c9_b_J4R[45] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 151U);
  c9_b_J4R[1] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 152U);
  c9_b_J4R[4] = 1.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 153U);
  c9_b_J4R[7] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 154U);
  c9_b_J4R[10] = ((((0.1834 * c9_t92 - 0.1834 * c9_t93) + 0.5 * c9_t61 * c9_t21)
                   + 0.5 * c9_t81 * c9_t27) + 0.5 * c9_t61 * c9_t30) + 0.5 *
    c9_t81 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 155U);
  c9_b_J4R[13] = ((((-0.1834 * c9_t4 * c9_t11 - 0.1834 * c9_t3 * c9_t41) - 0.5 *
                    c9_t3 * c9_t44) + 0.5 * c9_t119 * c9_t27) - 0.5 * c9_t3 *
                  c9_t53) + 0.5 * c9_t119 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 156U);
  c9_b_J4R[16] = (((-0.1834 * c9_t20 * c9_t15 + 0.5 * c9_t14 * c9_t21) + 0.5 *
                   c9_t131 * c9_t27) + 0.5 * c9_t14 * c9_t30) + 0.5 * c9_t131 *
    c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 157U);
  c9_b_J4R[19] = 0.5 * c9_t20 * c9_t33 - 0.5 * c9_t142 * c9_t30;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 158U);
  c9_b_J4R[22] = 0.5 * c9_t20 * c9_t27 - 0.5 * c9_t142 * c9_t21;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 159U);
  c9_b_J4R[25] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 160U);
  c9_b_J4R[28] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 161U);
  c9_b_J4R[31] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 162U);
  c9_b_J4R[34] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 163U);
  c9_b_J4R[37] = ((-0.1834 * c9_t24 - 0.1834 * c9_t141) + 0.5 * c9_t154 * c9_t27)
    + 0.5 * c9_t154 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 164U);
  c9_b_J4R[40] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 165U);
  c9_b_J4R[43] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 166U);
  c9_b_J4R[46] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 167U);
  c9_b_J4R[2] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 168U);
  c9_b_J4R[5] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 169U);
  c9_b_J4R[8] = 1.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 170U);
  c9_b_J4R[11] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 171U);
  c9_b_J4R[14] = ((((-0.1834 * c9_t4 * c9_t2 + 0.1834 * c9_t162 * c9_t15) + 0.5 *
                    c9_t165 * c9_t21) + 0.5 * c9_t170 * c9_t27) + 0.5 * c9_t165 *
                  c9_t30) + 0.5 * c9_t170 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 172U);
  c9_b_J4R[17] = (((0.1834 * c9_t178 * c9_t15 - 0.5 * c9_t181 * c9_t21) - 0.5 *
                   c9_t178 * c9_t4 * c9_t27) - 0.5 * c9_t181 * c9_t30) - 0.5 *
    c9_t178 * c9_t4 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 173U);
  c9_b_J4R[20] = -0.5 * c9_t178 * c9_t33 - 0.5 * c9_t197 * c9_t30;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 174U);
  c9_b_J4R[23] = -0.5 * c9_t178 * c9_t27 - 0.5 * c9_t197 * c9_t21;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 175U);
  c9_b_J4R[26] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 176U);
  c9_b_J4R[29] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 177U);
  c9_b_J4R[32] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 178U);
  c9_b_J4R[35] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 179U);
  c9_b_J4R[38] = ((0.1834 * c9_t195 - 0.1834 * c9_t196) + 0.5 * c9_t210 * c9_t27)
    + 0.5 * c9_t210 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 180U);
  c9_b_J4R[41] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 181U);
  c9_b_J4R[44] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 182U);
  c9_b_J4R[47] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 184U);
  for (c9_i144 = 0; c9_i144 < 144; c9_i144++) {
    c9_b_JR1Col[c9_i144] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 185U);
  c9_tc_x = c9_qzT;
  c9_t1 = c9_tc_x;
  c9_uc_x = c9_t1;
  c9_t1 = c9_uc_x;
  c9_t1 = muDoubleScalarSin(c9_t1);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 186U);
  c9_vc_x = c9_qyT;
  c9_t2 = c9_vc_x;
  c9_wc_x = c9_t2;
  c9_t2 = c9_wc_x;
  c9_t2 = muDoubleScalarCos(c9_t2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 187U);
  c9_t3 = c9_t1 * c9_t2;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 188U);
  c9_xc_x = c9_q3R;
  c9_t4 = c9_xc_x;
  c9_yc_x = c9_t4;
  c9_t4 = c9_yc_x;
  c9_t4 = muDoubleScalarCos(c9_t4);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 189U);
  c9_t5 = c9_t3 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 190U);
  c9_ad_x = c9_qzT;
  c9_t6 = c9_ad_x;
  c9_bd_x = c9_t6;
  c9_t6 = c9_bd_x;
  c9_t6 = muDoubleScalarCos(c9_t6);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 191U);
  c9_cd_x = c9_qxT;
  c9_t7 = c9_cd_x;
  c9_dd_x = c9_t7;
  c9_t7 = c9_dd_x;
  c9_t7 = muDoubleScalarSin(c9_t7);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 192U);
  c9_ed_x = c9_qyT;
  c9_t9 = c9_ed_x;
  c9_fd_x = c9_t9;
  c9_t9 = c9_fd_x;
  c9_t9 = muDoubleScalarSin(c9_t9);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 193U);
  c9_t10 = c9_t1 * c9_t9;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 194U);
  c9_gd_x = c9_qxT;
  c9_t11 = c9_gd_x;
  c9_hd_x = c9_t11;
  c9_t11 = c9_hd_x;
  c9_t11 = muDoubleScalarCos(c9_t11);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 195U);
  c9_t13 = c9_t6 * c9_t7 - c9_t10 * c9_t11;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 196U);
  c9_id_x = c9_q3R;
  c9_t14 = c9_id_x;
  c9_jd_x = c9_t14;
  c9_t14 = c9_jd_x;
  c9_t14 = muDoubleScalarSin(c9_t14);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 197U);
  c9_t17 = c9_t9 * c9_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 198U);
  c9_t19 = c9_t2 * c9_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 199U);
  c9_t20 = c9_t11 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 200U);
  c9_t25 = c9_t1 * c9_t11 - c9_t17 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 201U);
  c9_t30 = c9_t1 * c9_t7 + c9_t17 * c9_t11;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 202U);
  c9_t32 = -c9_t19 * c9_t14 - c9_t30 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 203U);
  c9_t35 = c9_t19 * c9_t4 - c9_t14 * c9_t30;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 204U);
  c9_t41 = -c9_t6 * c9_t11 - c9_t10 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 205U);
  c9_t43 = c9_t3 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 206U);
  c9_t45 = -c9_t43 + c9_t13 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 207U);
  c9_t47 = c9_t9 * c9_t11;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 208U);
  c9_t50 = c9_t2 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 209U);
  c9_t53 = c9_t11 * c9_t2;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 210U);
  c9_t55 = c9_t9 * c9_t14 - c9_t53 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 211U);
  c9_kd_x = c9_q1R;
  c9_t56 = c9_kd_x;
  c9_ld_x = c9_t56;
  c9_t56 = c9_ld_x;
  c9_t56 = muDoubleScalarCos(c9_t56);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 212U);
  c9_t59 = -c9_t43 + c9_t13 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 213U);
  c9_md_x = c9_q1R;
  c9_t60 = c9_md_x;
  c9_nd_x = c9_t60;
  c9_t60 = c9_nd_x;
  c9_t60 = muDoubleScalarSin(c9_t60);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 214U);
  c9_t63 = c9_t7 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 215U);
  c9_t66 = c9_t4 * c9_t11;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 216U);
  c9_t68 = -c9_t17 * c9_t14 + c9_t19 * c9_t66;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 217U);
  c9_t72 = c9_t25 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 218U);
  c9_t77 = c9_t25 * c9_t60 - c9_t32 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 219U);
  c9_t81 = -c9_t25 * c9_t56 - c9_t32 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 220U);
  c9_t85 = -c9_t10 * c9_t14 + c9_t3 * c9_t66;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 221U);
  c9_t89 = c9_t41 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 222U);
  c9_t96 = c9_t5 + c9_t13 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 223U);
  c9_t98 = c9_t9 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 224U);
  c9_t102 = -c9_t2 * c9_t14 - c9_t47 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 225U);
  c9_t114 = -c9_t9 * c9_t4 - c9_t53 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 226U);
  c9_t119 = c9_t7 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 227U);
  c9_b_JR1Col[0] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 228U);
  c9_b_JR1Col[9] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 229U);
  c9_b_JR1Col[18] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 230U);
  c9_b_JR1Col[27] = -c9_t5 - c9_t13 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 231U);
  c9_b_JR1Col[36] = -c9_t17 * c9_t4 - c9_t19 * c9_t20;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 232U);
  c9_b_JR1Col[45] = -(c9_t25 * c9_t14);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 233U);
  c9_b_JR1Col[54] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 234U);
  c9_b_JR1Col[63] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 235U);
  c9_b_JR1Col[72] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 236U);
  c9_b_JR1Col[81] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 237U);
  c9_b_JR1Col[90] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 238U);
  c9_b_JR1Col[99] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 239U);
  c9_b_JR1Col[108] = c9_t32;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 240U);
  c9_b_JR1Col[117] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 241U);
  c9_b_JR1Col[126] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 242U);
  c9_b_JR1Col[135] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 243U);
  c9_b_JR1Col[1] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 244U);
  c9_b_JR1Col[10] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 245U);
  c9_b_JR1Col[19] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 246U);
  c9_b_JR1Col[28] = c9_t35;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 247U);
  c9_b_JR1Col[37] = -c9_t10 * c9_t4 - c9_t3 * c9_t20;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 248U);
  c9_b_JR1Col[46] = -(c9_t41 * c9_t14);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 249U);
  c9_b_JR1Col[55] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 250U);
  c9_b_JR1Col[64] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 251U);
  c9_b_JR1Col[73] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 252U);
  c9_b_JR1Col[82] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 253U);
  c9_b_JR1Col[91] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 254U);
  c9_b_JR1Col[100] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, MAX_uint8_T);
  c9_b_JR1Col[109] = c9_t45;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 256);
  c9_b_JR1Col[118] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 257);
  c9_b_JR1Col[127] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 258);
  c9_b_JR1Col[136] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 259);
  c9_b_JR1Col[2] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 260);
  c9_b_JR1Col[11] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 261);
  c9_b_JR1Col[20] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 262);
  c9_b_JR1Col[29] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 263);
  c9_b_JR1Col[38] = -c9_t4 * c9_t2 + c9_t47 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 264);
  c9_b_JR1Col[47] = c9_t50 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 265);
  c9_b_JR1Col[56] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 266);
  c9_b_JR1Col[65] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 267);
  c9_b_JR1Col[74] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 268);
  c9_b_JR1Col[83] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 269);
  c9_b_JR1Col[92] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 270);
  c9_b_JR1Col[101] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 271);
  c9_b_JR1Col[110] = c9_t55;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 272);
  c9_b_JR1Col[119] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 273);
  c9_b_JR1Col[128] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 274);
  c9_b_JR1Col[137] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 275);
  c9_b_JR1Col[3] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 276);
  c9_b_JR1Col[12] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 277);
  c9_b_JR1Col[21] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 278);
  c9_b_JR1Col[30] = c9_t41 * c9_t56 + c9_t59 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 279);
  c9_b_JR1Col[39] = c9_t19 * c9_t63 + c9_t68 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 280);
  c9_b_JR1Col[48] = c9_t30 * c9_t56 + c9_t72 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 281);
  c9_b_JR1Col[57] = c9_t77;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 282);
  c9_b_JR1Col[66] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 283);
  c9_b_JR1Col[75] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 284);
  c9_b_JR1Col[84] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 285);
  c9_b_JR1Col[93] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 286);
  c9_b_JR1Col[102] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 287);
  c9_b_JR1Col[111] = c9_t35 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 288);
  c9_b_JR1Col[120] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 289);
  c9_b_JR1Col[129] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 290);
  c9_b_JR1Col[138] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 291);
  c9_b_JR1Col[4] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 292);
  c9_b_JR1Col[13] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 293);
  c9_b_JR1Col[22] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 294);
  c9_b_JR1Col[31] = c9_t81;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 295);
  c9_b_JR1Col[40] = c9_t3 * c9_t63 + c9_t85 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 296);
  c9_b_JR1Col[49] = -c9_t13 * c9_t56 + c9_t89 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 297);
  c9_b_JR1Col[58] = c9_t41 * c9_t60 - c9_t45 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 298);
  c9_b_JR1Col[67] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 299);
  c9_b_JR1Col[76] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 300);
  c9_b_JR1Col[85] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 301);
  c9_b_JR1Col[94] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 302);
  c9_b_JR1Col[103] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 303);
  c9_b_JR1Col[112] = c9_t96 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 304);
  c9_b_JR1Col[121] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 305);
  c9_b_JR1Col[130] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 306);
  c9_b_JR1Col[139] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 307);
  c9_b_JR1Col[5] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 308);
  c9_b_JR1Col[14] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 309);
  c9_b_JR1Col[23] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 310);
  c9_b_JR1Col[32] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 311);
  c9_b_JR1Col[41] = -c9_t98 * c9_t56 + c9_t102 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 312);
  c9_b_JR1Col[50] = c9_t53 * c9_t56 - c9_t50 * c9_t4 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 313);
  c9_b_JR1Col[59] = -c9_t50 * c9_t60 - c9_t55 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 314);
  c9_b_JR1Col[68] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 315);
  c9_b_JR1Col[77] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 316);
  c9_b_JR1Col[86] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 317);
  c9_b_JR1Col[95] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 318);
  c9_b_JR1Col[104] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 319);
  c9_b_JR1Col[113] = c9_t114 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 320);
  c9_b_JR1Col[122] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 321);
  c9_b_JR1Col[131] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 322);
  c9_b_JR1Col[140] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 323);
  c9_b_JR1Col[6] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 324);
  c9_b_JR1Col[15] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 325);
  c9_b_JR1Col[24] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 326);
  c9_b_JR1Col[33] = -c9_t41 * c9_t60 + c9_t59 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 327);
  c9_b_JR1Col[42] = -c9_t19 * c9_t119 + c9_t68 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 328);
  c9_b_JR1Col[51] = -c9_t30 * c9_t60 + c9_t72 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 329);
  c9_b_JR1Col[60] = -c9_t81;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 330);
  c9_b_JR1Col[69] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 331);
  c9_b_JR1Col[78] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 332);
  c9_b_JR1Col[87] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 333);
  c9_b_JR1Col[96] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 334);
  c9_b_JR1Col[105] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 335);
  c9_b_JR1Col[114] = c9_t35 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 336);
  c9_b_JR1Col[123] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 337);
  c9_b_JR1Col[132] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 338);
  c9_b_JR1Col[141] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 339);
  c9_b_JR1Col[7] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 340);
  c9_b_JR1Col[16] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 341);
  c9_b_JR1Col[25] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 342);
  c9_b_JR1Col[34] = c9_t77;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 343);
  c9_b_JR1Col[43] = -c9_t3 * c9_t119 + c9_t85 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 344);
  c9_b_JR1Col[52] = c9_t13 * c9_t60 + c9_t89 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 345);
  c9_b_JR1Col[61] = c9_t41 * c9_t56 + c9_t45 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 346);
  c9_b_JR1Col[70] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 347);
  c9_b_JR1Col[79] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 348);
  c9_b_JR1Col[88] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 349);
  c9_b_JR1Col[97] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 350);
  c9_b_JR1Col[106] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 351);
  c9_b_JR1Col[115] = c9_t96 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 352);
  c9_b_JR1Col[124] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 353);
  c9_b_JR1Col[133] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 354);
  c9_b_JR1Col[142] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 355);
  c9_b_JR1Col[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 356);
  c9_b_JR1Col[17] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 357);
  c9_b_JR1Col[26] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 358);
  c9_b_JR1Col[35] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 359);
  c9_b_JR1Col[44] = c9_t98 * c9_t60 + c9_t102 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 360);
  c9_b_JR1Col[53] = -c9_t53 * c9_t60 - c9_t50 * c9_t4 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 361);
  c9_b_JR1Col[62] = -c9_t50 * c9_t56 + c9_t55 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 362);
  c9_b_JR1Col[71] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 363);
  c9_b_JR1Col[80] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 364);
  c9_b_JR1Col[89] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 365);
  c9_b_JR1Col[98] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 366);
  c9_b_JR1Col[107] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 367);
  c9_b_JR1Col[116] = c9_t114 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 368);
  c9_b_JR1Col[125] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 369);
  c9_b_JR1Col[134] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 370);
  c9_b_JR1Col[143] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 372);
  for (c9_i145 = 0; c9_i145 < 3; c9_i145++) {
    c9_p4L[c9_i145] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 373);
  c9_od_x = c9_qzT;
  c9_t1 = c9_od_x;
  c9_pd_x = c9_t1;
  c9_t1 = c9_pd_x;
  c9_t1 = muDoubleScalarCos(c9_t1);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 374);
  c9_qd_x = c9_qyT;
  c9_t2 = c9_qd_x;
  c9_rd_x = c9_t2;
  c9_t2 = c9_rd_x;
  c9_t2 = muDoubleScalarCos(c9_t2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 375);
  c9_t3 = c9_t1 * c9_t2;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 376);
  c9_sd_x = c9_q3L;
  c9_t4 = c9_sd_x;
  c9_td_x = c9_t4;
  c9_t4 = c9_td_x;
  c9_t4 = muDoubleScalarCos(c9_t4);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 377);
  c9_ud_x = c9_qzT;
  c9_t7 = c9_ud_x;
  c9_vd_x = c9_t7;
  c9_t7 = c9_vd_x;
  c9_t7 = muDoubleScalarSin(c9_t7);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 378);
  c9_wd_x = c9_qxT;
  c9_t8 = c9_wd_x;
  c9_xd_x = c9_t8;
  c9_t8 = c9_xd_x;
  c9_t8 = muDoubleScalarSin(c9_t8);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 379);
  c9_yd_x = c9_qyT;
  c9_t10 = c9_yd_x;
  c9_ae_x = c9_t10;
  c9_t10 = c9_ae_x;
  c9_t10 = muDoubleScalarSin(c9_t10);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 380);
  c9_t11 = c9_t1 * c9_t10;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 381);
  c9_be_x = c9_qxT;
  c9_t12 = c9_be_x;
  c9_ce_x = c9_t12;
  c9_t12 = c9_ce_x;
  c9_t12 = muDoubleScalarCos(c9_t12);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 382);
  c9_t14 = c9_t7 * c9_t8 + c9_t11 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 383);
  c9_de_x = c9_q3L;
  c9_t15 = c9_de_x;
  c9_ee_x = c9_t15;
  c9_t15 = c9_ee_x;
  c9_t15 = muDoubleScalarSin(c9_t15);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 384);
  c9_t20 = -c9_t7 * c9_t12 + c9_t11 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 385);
  c9_fe_x = c9_q2L;
  c9_t21 = c9_fe_x;
  c9_ge_x = c9_t21;
  c9_t21 = c9_ge_x;
  c9_t21 = muDoubleScalarSin(c9_t21);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 386);
  c9_t26 = -c9_t3 * c9_t15 + c9_t14 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 387);
  c9_he_x = c9_q2L;
  c9_t27 = c9_he_x;
  c9_ie_x = c9_t27;
  c9_t27 = c9_ie_x;
  c9_t27 = muDoubleScalarCos(c9_t27);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 388);
  c9_je_x = c9_q1L;
  c9_t30 = c9_je_x;
  c9_ke_x = c9_t30;
  c9_t30 = c9_ke_x;
  c9_t30 = muDoubleScalarSin(c9_t30);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 389);
  c9_le_x = c9_q1L;
  c9_t33 = c9_le_x;
  c9_me_x = c9_t33;
  c9_t33 = c9_me_x;
  c9_t33 = muDoubleScalarCos(c9_t33);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 390);
  c9_t37 = c9_t2 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 391);
  c9_t41 = c9_t10 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 392);
  c9_t43 = -c9_t1 * c9_t8 + c9_t41 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 393);
  c9_t48 = c9_t1 * c9_t12 + c9_t41 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 394);
  c9_t53 = -c9_t37 * c9_t15 + c9_t43 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 395);
  c9_t63 = c9_t2 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 396);
  c9_t66 = c9_t2 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 397);
  c9_t71 = c9_t10 * c9_t15 + c9_t63 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 398);
  c9_p4L[0] = (((((c9_xT - 0.1834 * c9_t3 * c9_t4) - 0.1834 * c9_t14 * c9_t15) -
                 0.5 * c9_t20 * c9_t21) + 0.5 * c9_t26 * c9_t27) - 0.5 * c9_t20 *
               c9_t30) + 0.5 * c9_t26 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 399);
  c9_p4L[1] = (((((c9_yT - 0.1834 * c9_t37 * c9_t4) - 0.1834 * c9_t43 * c9_t15)
                 - 0.5 * c9_t48 * c9_t21) + 0.5 * c9_t53 * c9_t27) - 0.5 *
               c9_t48 * c9_t30) + 0.5 * c9_t53 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 400);
  c9_p4L[2] = (((((c9_zT + 0.1834 * c9_t10 * c9_t4) - 0.1834 * c9_t63 * c9_t15)
                 - 0.5 * c9_t66 * c9_t21) + 0.5 * c9_t71 * c9_t27) - 0.5 *
               c9_t66 * c9_t30) + 0.5 * c9_t71 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 402);
  for (c9_i146 = 0; c9_i146 < 9; c9_i146++) {
    c9_R5[c9_i146] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 403);
  c9_ne_x = c9_qzT;
  c9_t1 = c9_ne_x;
  c9_oe_x = c9_t1;
  c9_t1 = c9_oe_x;
  c9_t1 = muDoubleScalarCos(c9_t1);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 404);
  c9_pe_x = c9_qyT;
  c9_t2 = c9_pe_x;
  c9_qe_x = c9_t2;
  c9_t2 = c9_qe_x;
  c9_t2 = muDoubleScalarCos(c9_t2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 405);
  c9_t3 = c9_t1 * c9_t2;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 406);
  c9_re_x = c9_q3L;
  c9_t4 = c9_re_x;
  c9_se_x = c9_t4;
  c9_t4 = c9_se_x;
  c9_t4 = muDoubleScalarCos(c9_t4);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 407);
  c9_te_x = c9_qzT;
  c9_t6 = c9_te_x;
  c9_ue_x = c9_t6;
  c9_t6 = c9_ue_x;
  c9_t6 = muDoubleScalarSin(c9_t6);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 408);
  c9_ve_x = c9_qxT;
  c9_t7 = c9_ve_x;
  c9_we_x = c9_t7;
  c9_t7 = c9_we_x;
  c9_t7 = muDoubleScalarSin(c9_t7);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 409);
  c9_xe_x = c9_qyT;
  c9_t9 = c9_xe_x;
  c9_ye_x = c9_t9;
  c9_t9 = c9_ye_x;
  c9_t9 = muDoubleScalarSin(c9_t9);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 410);
  c9_t10 = c9_t1 * c9_t9;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 411);
  c9_af_x = c9_qxT;
  c9_t11 = c9_af_x;
  c9_bf_x = c9_t11;
  c9_t11 = c9_bf_x;
  c9_t11 = muDoubleScalarCos(c9_t11);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 412);
  c9_t13 = c9_t6 * c9_t7 + c9_t10 * c9_t11;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 413);
  c9_cf_x = c9_q3L;
  c9_t14 = c9_cf_x;
  c9_df_x = c9_t14;
  c9_t14 = c9_df_x;
  c9_t14 = muDoubleScalarSin(c9_t14);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 414);
  c9_t19 = -c9_t6 * c9_t11 + c9_t10 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 415);
  c9_ef_x = c9_q1L;
  c9_t20 = c9_ef_x;
  c9_ff_x = c9_t20;
  c9_t20 = c9_ff_x;
  c9_t20 = muDoubleScalarCos(c9_t20);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 416);
  c9_t24 = -c9_t3 * c9_t14 + c9_t13 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 417);
  c9_gf_x = c9_q1L;
  c9_t25 = c9_gf_x;
  c9_hf_x = c9_t25;
  c9_t25 = c9_hf_x;
  c9_t25 = muDoubleScalarSin(c9_t25);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 418);
  c9_t31 = c9_t2 * c9_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 419);
  c9_t34 = c9_t9 * c9_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 420);
  c9_t36 = -c9_t1 * c9_t7 + c9_t34 * c9_t11;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 421);
  c9_t41 = c9_t1 * c9_t11 + c9_t34 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 422);
  c9_t45 = -c9_t31 * c9_t14 + c9_t36 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 423);
  c9_t52 = c9_t11 * c9_t2;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 424);
  c9_t55 = c9_t2 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 425);
  c9_t59 = c9_t9 * c9_t14 + c9_t52 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 426);
  c9_R5[0] = c9_t3 * c9_t4 + c9_t13 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 427);
  c9_R5[3] = c9_t19 * c9_t20 + c9_t24 * c9_t25;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 428);
  c9_R5[6] = -c9_t19 * c9_t25 + c9_t24 * c9_t20;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 429);
  c9_R5[1] = c9_t31 * c9_t4 + c9_t36 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 430);
  c9_R5[4] = c9_t41 * c9_t20 + c9_t45 * c9_t25;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 431);
  c9_R5[7] = -c9_t41 * c9_t25 + c9_t45 * c9_t20;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 432);
  c9_R5[2] = -c9_t9 * c9_t4 + c9_t52 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 433);
  c9_R5[5] = c9_t55 * c9_t20 + c9_t59 * c9_t25;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 434);
  c9_R5[8] = -c9_t55 * c9_t25 + c9_t59 * c9_t20;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 436);
  for (c9_i147 = 0; c9_i147 < 48; c9_i147++) {
    c9_b_J4L[c9_i147] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 437);
  c9_if_x = c9_qzT;
  c9_t1 = c9_if_x;
  c9_jf_x = c9_t1;
  c9_t1 = c9_jf_x;
  c9_t1 = muDoubleScalarSin(c9_t1);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 438);
  c9_kf_x = c9_qyT;
  c9_t2 = c9_kf_x;
  c9_lf_x = c9_t2;
  c9_t2 = c9_lf_x;
  c9_t2 = muDoubleScalarCos(c9_t2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 439);
  c9_t3 = c9_t1 * c9_t2;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 440);
  c9_mf_x = c9_q3L;
  c9_t4 = c9_mf_x;
  c9_nf_x = c9_t4;
  c9_t4 = c9_nf_x;
  c9_t4 = muDoubleScalarCos(c9_t4);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 441);
  c9_t5 = c9_t3 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 442);
  c9_of_x = c9_qzT;
  c9_t7 = c9_of_x;
  c9_pf_x = c9_t7;
  c9_t7 = c9_pf_x;
  c9_t7 = muDoubleScalarCos(c9_t7);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 443);
  c9_qf_x = c9_qxT;
  c9_t8 = c9_qf_x;
  c9_rf_x = c9_t8;
  c9_t8 = c9_rf_x;
  c9_t8 = muDoubleScalarSin(c9_t8);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 444);
  c9_sf_x = c9_qyT;
  c9_t10 = c9_sf_x;
  c9_tf_x = c9_t10;
  c9_t10 = c9_tf_x;
  c9_t10 = muDoubleScalarSin(c9_t10);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 445);
  c9_t11 = c9_t1 * c9_t10;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 446);
  c9_uf_x = c9_qxT;
  c9_t12 = c9_uf_x;
  c9_vf_x = c9_t12;
  c9_t12 = c9_vf_x;
  c9_t12 = muDoubleScalarCos(c9_t12);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 447);
  c9_t14 = c9_t7 * c9_t8 - c9_t11 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 448);
  c9_wf_x = c9_q3L;
  c9_t15 = c9_wf_x;
  c9_xf_x = c9_t15;
  c9_t15 = c9_xf_x;
  c9_t15 = muDoubleScalarSin(c9_t15);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 449);
  c9_t20 = -c9_t7 * c9_t12 - c9_t11 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 450);
  c9_yf_x = c9_q2L;
  c9_t21 = c9_yf_x;
  c9_ag_x = c9_t21;
  c9_t21 = c9_ag_x;
  c9_t21 = muDoubleScalarSin(c9_t21);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 451);
  c9_t24 = c9_t3 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 452);
  c9_t26 = c9_t24 + c9_t14 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 453);
  c9_bg_x = c9_q2L;
  c9_t27 = c9_bg_x;
  c9_cg_x = c9_t27;
  c9_t27 = c9_cg_x;
  c9_t27 = muDoubleScalarCos(c9_t27);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 454);
  c9_dg_x = c9_q1L;
  c9_t30 = c9_dg_x;
  c9_eg_x = c9_t30;
  c9_t30 = c9_eg_x;
  c9_t30 = muDoubleScalarSin(c9_t30);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 455);
  c9_fg_x = c9_q1L;
  c9_t33 = c9_fg_x;
  c9_gg_x = c9_t33;
  c9_t33 = c9_gg_x;
  c9_t33 = muDoubleScalarCos(c9_t33);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 456);
  c9_t37 = c9_t10 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 457);
  c9_t40 = c9_t2 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 458);
  c9_t41 = c9_t12 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 459);
  c9_t44 = c9_t8 * c9_t21;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 460);
  c9_t48 = c9_t12 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 461);
  c9_t50 = c9_t37 * c9_t15 + c9_t40 * c9_t48;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 462);
  c9_t53 = c9_t8 * c9_t30;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 463);
  c9_t61 = c9_t1 * c9_t12 - c9_t37 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 464);
  c9_t66 = c9_t1 * c9_t8 + c9_t37 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 465);
  c9_t69 = c9_t61 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 466);
  c9_t79 = c9_t40 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 467);
  c9_t80 = c9_t66 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 468);
  c9_t81 = -c9_t79 + c9_t80;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 469);
  c9_t92 = c9_t40 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 470);
  c9_t93 = c9_t66 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 471);
  c9_t94 = -c9_t92 - c9_t93;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 472);
  c9_t119 = c9_t11 * c9_t15 + c9_t3 * c9_t48;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 473);
  c9_t131 = c9_t20 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 474);
  c9_t141 = -c9_t14 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 475);
  c9_t142 = -c9_t24 + c9_t141;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 476);
  c9_t154 = -c9_t5 + c9_t14 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 477);
  c9_t162 = c9_t10 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 478);
  c9_t165 = c9_t10 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 479);
  c9_t170 = c9_t2 * c9_t15 - c9_t162 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 480);
  c9_t178 = c9_t2 * c9_t8;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 481);
  c9_t181 = c9_t2 * c9_t12;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 482);
  c9_t195 = c9_t10 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 483);
  c9_t196 = c9_t181 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 484);
  c9_t197 = c9_t195 + c9_t196;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 485);
  c9_t210 = c9_t10 * c9_t4 - c9_t181 * c9_t15;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 486);
  c9_b_J4L[0] = 1.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 487);
  c9_b_J4L[3] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 488);
  c9_b_J4L[6] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 489);
  c9_b_J4L[9] = ((((0.1834 * c9_t5 - 0.1834 * c9_t14 * c9_t15) - 0.5 * c9_t20 *
                   c9_t21) + 0.5 * c9_t26 * c9_t27) - 0.5 * c9_t20 * c9_t30) +
    0.5 * c9_t26 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 490);
  c9_b_J4L[12] = ((((0.1834 * c9_t37 * c9_t4 - 0.1834 * c9_t40 * c9_t41) - 0.5 *
                    c9_t40 * c9_t44) + 0.5 * c9_t50 * c9_t27) - 0.5 * c9_t40 *
                  c9_t53) + 0.5 * c9_t50 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 491);
  c9_b_J4L[15] = (((-0.1834 * c9_t61 * c9_t15 - 0.5 * c9_t66 * c9_t21) + 0.5 *
                   c9_t69 * c9_t27) - 0.5 * c9_t66 * c9_t30) + 0.5 * c9_t69 *
    c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 492);
  c9_b_J4L[18] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 493);
  c9_b_J4L[21] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 494);
  c9_b_J4L[24] = 0.5 * c9_t61 * c9_t33 - 0.5 * c9_t81 * c9_t30;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 495);
  c9_b_J4L[27] = 0.5 * c9_t61 * c9_t27 - 0.5 * c9_t81 * c9_t21;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 496);
  c9_b_J4L[30] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 497);
  c9_b_J4L[33] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 498);
  c9_b_J4L[36] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 499);
  c9_b_J4L[39] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 500);
  c9_b_J4L[42] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 501);
  c9_b_J4L[45] = ((0.1834 * c9_t79 - 0.1834 * c9_t80) + 0.5 * c9_t94 * c9_t27) +
    0.5 * c9_t94 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 502);
  c9_b_J4L[1] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 503);
  c9_b_J4L[4] = 1.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 504);
  c9_b_J4L[7] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 505);
  c9_b_J4L[10] = ((((-0.1834 * c9_t92 - 0.1834 * c9_t93) + 0.5 * c9_t61 * c9_t21)
                   + 0.5 * c9_t81 * c9_t27) + 0.5 * c9_t61 * c9_t30) + 0.5 *
    c9_t81 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 506);
  c9_b_J4L[13] = ((((0.1834 * c9_t4 * c9_t11 - 0.1834 * c9_t3 * c9_t41) - 0.5 *
                    c9_t3 * c9_t44) + 0.5 * c9_t119 * c9_t27) - 0.5 * c9_t3 *
                  c9_t53) + 0.5 * c9_t119 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 507);
  c9_b_J4L[16] = (((-0.1834 * c9_t20 * c9_t15 + 0.5 * c9_t14 * c9_t21) + 0.5 *
                   c9_t131 * c9_t27) + 0.5 * c9_t14 * c9_t30) + 0.5 * c9_t131 *
    c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 508);
  c9_b_J4L[19] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 509);
  c9_b_J4L[22] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 510);
  c9_b_J4L[25] = 0.5 * c9_t20 * c9_t33 - 0.5 * c9_t142 * c9_t30;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 511);
  c9_b_J4L[28] = 0.5 * c9_t20 * c9_t27 - 0.5 * c9_t142 * c9_t21;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 512);
  c9_b_J4L[31] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 513);
  c9_b_J4L[34] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 514);
  c9_b_J4L[37] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 515);
  c9_b_J4L[40] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 516);
  c9_b_J4L[43] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 517);
  c9_b_J4L[46] = ((0.1834 * c9_t24 - 0.1834 * c9_t141) + 0.5 * c9_t154 * c9_t27)
    + 0.5 * c9_t154 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 518);
  c9_b_J4L[2] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 519);
  c9_b_J4L[5] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 520);
  c9_b_J4L[8] = 1.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 521);
  c9_b_J4L[11] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 522);
  c9_b_J4L[14] = ((((0.1834 * c9_t4 * c9_t2 + 0.1834 * c9_t162 * c9_t15) + 0.5 *
                    c9_t165 * c9_t21) + 0.5 * c9_t170 * c9_t27) + 0.5 * c9_t165 *
                  c9_t30) + 0.5 * c9_t170 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 523);
  c9_b_J4L[17] = (((0.1834 * c9_t178 * c9_t15 - 0.5 * c9_t181 * c9_t21) - 0.5 *
                   c9_t178 * c9_t4 * c9_t27) - 0.5 * c9_t181 * c9_t30) - 0.5 *
    c9_t178 * c9_t4 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 524);
  c9_b_J4L[20] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 525);
  c9_b_J4L[23] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 526);
  c9_b_J4L[26] = -0.5 * c9_t178 * c9_t33 - 0.5 * c9_t197 * c9_t30;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 527);
  c9_b_J4L[29] = -0.5 * c9_t178 * c9_t27 - 0.5 * c9_t197 * c9_t21;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 528);
  c9_b_J4L[32] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 529);
  c9_b_J4L[35] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 530);
  c9_b_J4L[38] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 531);
  c9_b_J4L[41] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 532);
  c9_b_J4L[44] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 533);
  c9_b_J4L[47] = ((-0.1834 * c9_t195 - 0.1834 * c9_t196) + 0.5 * c9_t210 *
                  c9_t27) + 0.5 * c9_t210 * c9_t33;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 535);
  for (c9_i148 = 0; c9_i148 < 144; c9_i148++) {
    c9_b_JR5Col[c9_i148] = 0.0;
  }

  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 536);
  c9_hg_x = c9_qzT;
  c9_t1 = c9_hg_x;
  c9_ig_x = c9_t1;
  c9_t1 = c9_ig_x;
  c9_t1 = muDoubleScalarSin(c9_t1);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 537);
  c9_jg_x = c9_qyT;
  c9_t2 = c9_jg_x;
  c9_kg_x = c9_t2;
  c9_t2 = c9_kg_x;
  c9_t2 = muDoubleScalarCos(c9_t2);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 538);
  c9_t3 = c9_t1 * c9_t2;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 539);
  c9_lg_x = c9_q3L;
  c9_t4 = c9_lg_x;
  c9_mg_x = c9_t4;
  c9_t4 = c9_mg_x;
  c9_t4 = muDoubleScalarCos(c9_t4);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 540);
  c9_t5 = c9_t3 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 541);
  c9_ng_x = c9_qzT;
  c9_t6 = c9_ng_x;
  c9_og_x = c9_t6;
  c9_t6 = c9_og_x;
  c9_t6 = muDoubleScalarCos(c9_t6);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 542);
  c9_pg_x = c9_qxT;
  c9_t7 = c9_pg_x;
  c9_qg_x = c9_t7;
  c9_t7 = c9_qg_x;
  c9_t7 = muDoubleScalarSin(c9_t7);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 543);
  c9_rg_x = c9_qyT;
  c9_t9 = c9_rg_x;
  c9_sg_x = c9_t9;
  c9_t9 = c9_sg_x;
  c9_t9 = muDoubleScalarSin(c9_t9);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 544);
  c9_t10 = c9_t1 * c9_t9;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 545);
  c9_tg_x = c9_qxT;
  c9_t11 = c9_tg_x;
  c9_ug_x = c9_t11;
  c9_t11 = c9_ug_x;
  c9_t11 = muDoubleScalarCos(c9_t11);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 546);
  c9_t13 = c9_t6 * c9_t7 - c9_t10 * c9_t11;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 547);
  c9_vg_x = c9_q3L;
  c9_t14 = c9_vg_x;
  c9_wg_x = c9_t14;
  c9_t14 = c9_wg_x;
  c9_t14 = muDoubleScalarSin(c9_t14);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 548);
  c9_t17 = c9_t9 * c9_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 549);
  c9_t19 = c9_t2 * c9_t6;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 550);
  c9_t20 = c9_t11 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 551);
  c9_t25 = c9_t1 * c9_t11 - c9_t17 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 552);
  c9_t30 = c9_t1 * c9_t7 + c9_t17 * c9_t11;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 553);
  c9_t32 = -c9_t19 * c9_t14 + c9_t30 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 554);
  c9_t35 = c9_t19 * c9_t4 + c9_t14 * c9_t30;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 555);
  c9_t41 = -c9_t6 * c9_t11 - c9_t10 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 556);
  c9_t43 = c9_t3 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 557);
  c9_t45 = -c9_t43 - c9_t13 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 558);
  c9_t47 = c9_t9 * c9_t11;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 559);
  c9_t50 = c9_t2 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 560);
  c9_t53 = c9_t11 * c9_t2;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 561);
  c9_t55 = c9_t9 * c9_t14 + c9_t53 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 562);
  c9_xg_x = c9_q1L;
  c9_t56 = c9_xg_x;
  c9_yg_x = c9_t56;
  c9_t56 = c9_yg_x;
  c9_t56 = muDoubleScalarCos(c9_t56);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 563);
  c9_t59 = c9_t43 + c9_t13 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 564);
  c9_ah_x = c9_q1L;
  c9_t60 = c9_ah_x;
  c9_bh_x = c9_t60;
  c9_t60 = c9_bh_x;
  c9_t60 = muDoubleScalarSin(c9_t60);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 565);
  c9_t63 = c9_t7 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 566);
  c9_t66 = c9_t4 * c9_t11;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 567);
  c9_t68 = c9_t17 * c9_t14 + c9_t19 * c9_t66;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 568);
  c9_t72 = c9_t25 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 569);
  c9_t77 = c9_t25 * c9_t60 + c9_t32 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 570);
  c9_t81 = -c9_t25 * c9_t56 + c9_t32 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 571);
  c9_t85 = c9_t10 * c9_t14 + c9_t3 * c9_t66;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 572);
  c9_t89 = c9_t41 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 573);
  c9_t96 = -c9_t5 + c9_t13 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 574);
  c9_t98 = c9_t9 * c9_t7;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 575);
  c9_t102 = c9_t2 * c9_t14 - c9_t47 * c9_t4;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 576);
  c9_t114 = c9_t9 * c9_t4 - c9_t53 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 577);
  c9_t119 = c9_t7 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 578);
  c9_b_JR5Col[0] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 579);
  c9_b_JR5Col[9] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 580);
  c9_b_JR5Col[18] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 581);
  c9_b_JR5Col[27] = -c9_t5 + c9_t13 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 582);
  c9_b_JR5Col[36] = -c9_t17 * c9_t4 + c9_t19 * c9_t20;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 583);
  c9_b_JR5Col[45] = c9_t25 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 584);
  c9_b_JR5Col[54] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 585);
  c9_b_JR5Col[63] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 586);
  c9_b_JR5Col[72] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 587);
  c9_b_JR5Col[81] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 588);
  c9_b_JR5Col[90] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 589);
  c9_b_JR5Col[99] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 590);
  c9_b_JR5Col[108] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 591);
  c9_b_JR5Col[117] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 592);
  c9_b_JR5Col[126] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 593);
  c9_b_JR5Col[135] = c9_t32;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 594);
  c9_b_JR5Col[1] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 595);
  c9_b_JR5Col[10] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 596);
  c9_b_JR5Col[19] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 597);
  c9_b_JR5Col[28] = c9_t35;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 598);
  c9_b_JR5Col[37] = -c9_t10 * c9_t4 + c9_t3 * c9_t20;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 599);
  c9_b_JR5Col[46] = c9_t41 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 600);
  c9_b_JR5Col[55] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 601);
  c9_b_JR5Col[64] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 602);
  c9_b_JR5Col[73] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 603);
  c9_b_JR5Col[82] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 604);
  c9_b_JR5Col[91] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 605);
  c9_b_JR5Col[100] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 606);
  c9_b_JR5Col[109] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 607);
  c9_b_JR5Col[118] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 608);
  c9_b_JR5Col[127] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 609);
  c9_b_JR5Col[136] = c9_t45;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 610);
  c9_b_JR5Col[2] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 611);
  c9_b_JR5Col[11] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 612);
  c9_b_JR5Col[20] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 613);
  c9_b_JR5Col[29] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 614);
  c9_b_JR5Col[38] = -c9_t4 * c9_t2 - c9_t47 * c9_t14;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 615);
  c9_b_JR5Col[47] = -(c9_t50 * c9_t14);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 616);
  c9_b_JR5Col[56] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 617);
  c9_b_JR5Col[65] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 618);
  c9_b_JR5Col[74] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 619);
  c9_b_JR5Col[83] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 620);
  c9_b_JR5Col[92] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 621);
  c9_b_JR5Col[101] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 622);
  c9_b_JR5Col[110] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 623);
  c9_b_JR5Col[119] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 624);
  c9_b_JR5Col[128] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 625);
  c9_b_JR5Col[137] = c9_t55;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 626);
  c9_b_JR5Col[3] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 627);
  c9_b_JR5Col[12] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 628);
  c9_b_JR5Col[21] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 629);
  c9_b_JR5Col[30] = c9_t41 * c9_t56 + c9_t59 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 630);
  c9_b_JR5Col[39] = c9_t19 * c9_t63 + c9_t68 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 631);
  c9_b_JR5Col[48] = c9_t30 * c9_t56 + c9_t72 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 632);
  c9_b_JR5Col[57] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 633);
  c9_b_JR5Col[66] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 634);
  c9_b_JR5Col[75] = c9_t77;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 635);
  c9_b_JR5Col[84] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 636);
  c9_b_JR5Col[93] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 637);
  c9_b_JR5Col[102] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 638);
  c9_b_JR5Col[111] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 639);
  c9_b_JR5Col[120] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 640);
  c9_b_JR5Col[129] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 641);
  c9_b_JR5Col[138] = -(c9_t35 * c9_t60);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 642);
  c9_b_JR5Col[4] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 643);
  c9_b_JR5Col[13] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 644);
  c9_b_JR5Col[22] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 645);
  c9_b_JR5Col[31] = c9_t81;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 646);
  c9_b_JR5Col[40] = c9_t3 * c9_t63 + c9_t85 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 647);
  c9_b_JR5Col[49] = -c9_t13 * c9_t56 + c9_t89 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 648);
  c9_b_JR5Col[58] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 649);
  c9_b_JR5Col[67] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 650);
  c9_b_JR5Col[76] = c9_t41 * c9_t60 + c9_t45 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 651);
  c9_b_JR5Col[85] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 652);
  c9_b_JR5Col[94] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 653);
  c9_b_JR5Col[103] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 654);
  c9_b_JR5Col[112] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 655);
  c9_b_JR5Col[121] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 656);
  c9_b_JR5Col[130] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 657);
  c9_b_JR5Col[139] = c9_t96 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 658);
  c9_b_JR5Col[5] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 659);
  c9_b_JR5Col[14] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 660);
  c9_b_JR5Col[23] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 661);
  c9_b_JR5Col[32] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 662);
  c9_b_JR5Col[41] = -c9_t98 * c9_t56 + c9_t102 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 663);
  c9_b_JR5Col[50] = c9_t53 * c9_t56 - c9_t50 * c9_t4 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 664);
  c9_b_JR5Col[59] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 665);
  c9_b_JR5Col[68] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 666);
  c9_b_JR5Col[77] = -c9_t50 * c9_t60 + c9_t55 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 667);
  c9_b_JR5Col[86] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 668);
  c9_b_JR5Col[95] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 669);
  c9_b_JR5Col[104] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 670);
  c9_b_JR5Col[113] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 671);
  c9_b_JR5Col[122] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 672);
  c9_b_JR5Col[131] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 673);
  c9_b_JR5Col[140] = c9_t114 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 674);
  c9_b_JR5Col[6] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 675);
  c9_b_JR5Col[15] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 676);
  c9_b_JR5Col[24] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 677);
  c9_b_JR5Col[33] = -c9_t41 * c9_t60 + c9_t59 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 678);
  c9_b_JR5Col[42] = -c9_t19 * c9_t119 + c9_t68 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 679);
  c9_b_JR5Col[51] = -c9_t30 * c9_t60 + c9_t72 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 680);
  c9_b_JR5Col[60] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 681);
  c9_b_JR5Col[69] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 682);
  c9_b_JR5Col[78] = -c9_t81;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 683);
  c9_b_JR5Col[87] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 684);
  c9_b_JR5Col[96] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 685);
  c9_b_JR5Col[105] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 686);
  c9_b_JR5Col[114] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 687);
  c9_b_JR5Col[123] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 688);
  c9_b_JR5Col[132] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 689);
  c9_b_JR5Col[141] = -(c9_t35 * c9_t56);
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 690);
  c9_b_JR5Col[7] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 691);
  c9_b_JR5Col[16] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 692);
  c9_b_JR5Col[25] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 693);
  c9_b_JR5Col[34] = c9_t77;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 694);
  c9_b_JR5Col[43] = -c9_t3 * c9_t119 + c9_t85 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 695);
  c9_b_JR5Col[52] = c9_t13 * c9_t60 + c9_t89 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 696);
  c9_b_JR5Col[61] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 697);
  c9_b_JR5Col[70] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 698);
  c9_b_JR5Col[79] = c9_t41 * c9_t56 - c9_t45 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 699);
  c9_b_JR5Col[88] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 700);
  c9_b_JR5Col[97] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 701);
  c9_b_JR5Col[106] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 702);
  c9_b_JR5Col[115] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 703);
  c9_b_JR5Col[124] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 704);
  c9_b_JR5Col[133] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 705);
  c9_b_JR5Col[142] = c9_t96 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 706);
  c9_b_JR5Col[8] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 707);
  c9_b_JR5Col[17] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 708);
  c9_b_JR5Col[26] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 709);
  c9_b_JR5Col[35] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 710);
  c9_b_JR5Col[44] = c9_t98 * c9_t60 + c9_t102 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 711);
  c9_b_JR5Col[53] = -c9_t53 * c9_t60 - c9_t50 * c9_t4 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 712);
  c9_b_JR5Col[62] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 713);
  c9_b_JR5Col[71] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 714);
  c9_b_JR5Col[80] = -c9_t50 * c9_t56 - c9_t55 * c9_t60;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 715);
  c9_b_JR5Col[89] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 716);
  c9_b_JR5Col[98] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 717);
  c9_b_JR5Col[107] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 718);
  c9_b_JR5Col[116] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 719);
  c9_b_JR5Col[125] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 720);
  c9_b_JR5Col[134] = 0.0;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, 721);
  c9_b_JR5Col[143] = c9_t114 * c9_t56;
  _SFD_SCRIPT_CALL(1U, chartInstance->c9_sfEvent, -721);
  _SFD_SYMBOL_SCOPE_POP();
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, c9_instanceNumber, 0U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Sims\\Model\\FootHeightAndVelocity.m"));
  _SFD_SCRIPT_TRANSLATION(c9_chartNumber, c9_instanceNumber, 1U,
    sf_debug_get_script_id(
    "C:\\Users\\xingye\\Documents\\SVN\\MARLO_Models\\OriginalLeg_Updated\\m\\ATRIAS3D_FootPointPosJacob_Hip.m"));
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i149;
  int32_T c9_i150;
  int32_T c9_i151;
  real_T c9_b_inData[144];
  int32_T c9_i152;
  int32_T c9_i153;
  int32_T c9_i154;
  real_T c9_u[144];
  const mxArray *c9_y = NULL;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i149 = 0;
  for (c9_i150 = 0; c9_i150 < 16; c9_i150++) {
    for (c9_i151 = 0; c9_i151 < 9; c9_i151++) {
      c9_b_inData[c9_i151 + c9_i149] = (*(real_T (*)[144])c9_inData)[c9_i151 +
        c9_i149];
    }

    c9_i149 += 9;
  }

  c9_i152 = 0;
  for (c9_i153 = 0; c9_i153 < 16; c9_i153++) {
    for (c9_i154 = 0; c9_i154 < 9; c9_i154++) {
      c9_u[c9_i154 + c9_i152] = c9_b_inData[c9_i154 + c9_i152];
    }

    c9_i152 += 9;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 9, 16), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  const mxArray *c9_b_JR5Col, const char_T *c9_identifier, real_T c9_y[144])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_JR5Col), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_JR5Col);
}

static void c9_b_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[144])
{
  real_T c9_dv8[144];
  int32_T c9_i155;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv8, 1, 0, 0U, 1, 0U, 2, 9, 16);
  for (c9_i155 = 0; c9_i155 < 144; c9_i155++) {
    c9_y[c9_i155] = c9_dv8[c9_i155];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_JR5Col;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[144];
  int32_T c9_i156;
  int32_T c9_i157;
  int32_T c9_i158;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_b_JR5Col = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_JR5Col), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_JR5Col);
  c9_i156 = 0;
  for (c9_i157 = 0; c9_i157 < 16; c9_i157++) {
    for (c9_i158 = 0; c9_i158 < 9; c9_i158++) {
      (*(real_T (*)[144])c9_outData)[c9_i158 + c9_i156] = c9_y[c9_i158 + c9_i156];
    }

    c9_i156 += 9;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i159;
  int32_T c9_i160;
  int32_T c9_i161;
  real_T c9_b_inData[48];
  int32_T c9_i162;
  int32_T c9_i163;
  int32_T c9_i164;
  real_T c9_u[48];
  const mxArray *c9_y = NULL;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i159 = 0;
  for (c9_i160 = 0; c9_i160 < 16; c9_i160++) {
    for (c9_i161 = 0; c9_i161 < 3; c9_i161++) {
      c9_b_inData[c9_i161 + c9_i159] = (*(real_T (*)[48])c9_inData)[c9_i161 +
        c9_i159];
    }

    c9_i159 += 3;
  }

  c9_i162 = 0;
  for (c9_i163 = 0; c9_i163 < 16; c9_i163++) {
    for (c9_i164 = 0; c9_i164 < 3; c9_i164++) {
      c9_u[c9_i164 + c9_i162] = c9_b_inData[c9_i164 + c9_i162];
    }

    c9_i162 += 3;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 3, 16), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_c_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_b_J4L, const char_T *c9_identifier, real_T
  c9_y[48])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_J4L), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_J4L);
}

static void c9_d_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[48])
{
  real_T c9_dv9[48];
  int32_T c9_i165;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv9, 1, 0, 0U, 1, 0U, 2, 3, 16);
  for (c9_i165 = 0; c9_i165 < 48; c9_i165++) {
    c9_y[c9_i165] = c9_dv9[c9_i165];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_J4L;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[48];
  int32_T c9_i166;
  int32_T c9_i167;
  int32_T c9_i168;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_b_J4L = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_J4L), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_J4L);
  c9_i166 = 0;
  for (c9_i167 = 0; c9_i167 < 16; c9_i167++) {
    for (c9_i168 = 0; c9_i168 < 3; c9_i168++) {
      (*(real_T (*)[48])c9_outData)[c9_i168 + c9_i166] = c9_y[c9_i168 + c9_i166];
    }

    c9_i166 += 3;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i169;
  real_T c9_b_inData[3];
  int32_T c9_i170;
  real_T c9_u[3];
  const mxArray *c9_y = NULL;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i169 = 0; c9_i169 < 3; c9_i169++) {
    c9_b_inData[c9_i169] = (*(real_T (*)[3])c9_inData)[c9_i169];
  }

  for (c9_i170 = 0; c9_i170 < 3; c9_i170++) {
    c9_u[c9_i170] = c9_b_inData[c9_i170];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 3), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_e_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_b_vL, const char_T *c9_identifier, real_T
  c9_y[3])
{
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_vL), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_vL);
}

static void c9_f_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[3])
{
  real_T c9_dv10[3];
  int32_T c9_i171;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv10, 1, 0, 0U, 1, 0U, 1, 3);
  for (c9_i171 = 0; c9_i171 < 3; c9_i171++) {
    c9_y[c9_i171] = c9_dv10[c9_i171];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_vL;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[3];
  int32_T c9_i172;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_b_vL = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_vL), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_vL);
  for (c9_i172 = 0; c9_i172 < 3; c9_i172++) {
    (*(real_T (*)[3])c9_outData)[c9_i172] = c9_y[c9_i172];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i173;
  real_T c9_b_inData[32];
  int32_T c9_i174;
  real_T c9_u[32];
  const mxArray *c9_y = NULL;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i173 = 0; c9_i173 < 32; c9_i173++) {
    c9_b_inData[c9_i173] = (*(real_T (*)[32])c9_inData)[c9_i173];
  }

  for (c9_i174 = 0; c9_i174 < 32; c9_i174++) {
    c9_u[c9_i174] = c9_b_inData[c9_i174];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 32), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_g_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d0, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_g_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_f_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i175;
  int32_T c9_i176;
  int32_T c9_i177;
  real_T c9_b_inData[9];
  int32_T c9_i178;
  int32_T c9_i179;
  int32_T c9_i180;
  real_T c9_u[9];
  const mxArray *c9_y = NULL;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_i175 = 0;
  for (c9_i176 = 0; c9_i176 < 3; c9_i176++) {
    for (c9_i177 = 0; c9_i177 < 3; c9_i177++) {
      c9_b_inData[c9_i177 + c9_i175] = (*(real_T (*)[9])c9_inData)[c9_i177 +
        c9_i175];
    }

    c9_i175 += 3;
  }

  c9_i178 = 0;
  for (c9_i179 = 0; c9_i179 < 3; c9_i179++) {
    for (c9_i180 = 0; c9_i180 < 3; c9_i180++) {
      c9_u[c9_i180 + c9_i178] = c9_b_inData[c9_i180 + c9_i178];
    }

    c9_i178 += 3;
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 2, 3, 3), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_h_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[9])
{
  real_T c9_dv11[9];
  int32_T c9_i181;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv11, 1, 0, 0U, 1, 0U, 2, 3, 3);
  for (c9_i181 = 0; c9_i181 < 9; c9_i181++) {
    c9_y[c9_i181] = c9_dv11[c9_i181];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_e_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_R5;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[9];
  int32_T c9_i182;
  int32_T c9_i183;
  int32_T c9_i184;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_R5 = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_R5), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_R5);
  c9_i182 = 0;
  for (c9_i183 = 0; c9_i183 < 3; c9_i183++) {
    for (c9_i184 = 0; c9_i184 < 3; c9_i184++) {
      (*(real_T (*)[9])c9_outData)[c9_i184 + c9_i182] = c9_y[c9_i184 + c9_i182];
    }

    c9_i182 += 3;
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_g_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i185;
  real_T c9_b_inData[16];
  int32_T c9_i186;
  real_T c9_u[16];
  const mxArray *c9_y = NULL;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i185 = 0; c9_i185 < 16; c9_i185++) {
    c9_b_inData[c9_i185] = (*(real_T (*)[16])c9_inData)[c9_i185];
  }

  for (c9_i186 = 0; c9_i186 < 16; c9_i186++) {
    c9_u[c9_i186] = c9_b_inData[c9_i186];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 16), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_i_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[16])
{
  real_T c9_dv12[16];
  int32_T c9_i187;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv12, 1, 0, 0U, 1, 0U, 1, 16);
  for (c9_i187 = 0; c9_i187 < 16; c9_i187++) {
    c9_y[c9_i187] = c9_dv12[c9_i187];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_f_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_q;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[16];
  int32_T c9_i188;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_q = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_q), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_q);
  for (c9_i188 = 0; c9_i188 < 16; c9_i188++) {
    (*(real_T (*)[16])c9_outData)[c9_i188] = c9_y[c9_i188];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static void c9_j_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[32])
{
  real_T c9_dv13[32];
  int32_T c9_i189;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv13, 1, 0, 0U, 1, 0U, 1, 32);
  for (c9_i189 = 0; c9_i189 < 32; c9_i189++) {
    c9_y[c9_i189] = c9_dv13[c9_i189];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_g_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_x;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[32];
  int32_T c9_i190;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_b_x = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_x), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_b_x);
  for (c9_i190 = 0; c9_i190 < 32; c9_i190++) {
    (*(real_T (*)[32])c9_outData)[c9_i190] = c9_y[c9_i190];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_h_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i191;
  real_T c9_b_inData[9];
  int32_T c9_i192;
  real_T c9_u[9];
  const mxArray *c9_y = NULL;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i191 = 0; c9_i191 < 9; c9_i191++) {
    c9_b_inData[c9_i191] = (*(real_T (*)[9])c9_inData)[c9_i191];
  }

  for (c9_i192 = 0; c9_i192 < 9; c9_i192++) {
    c9_u[c9_i192] = c9_b_inData[c9_i192];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 9), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static void c9_k_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId,
  real_T c9_y[9])
{
  real_T c9_dv14[9];
  int32_T c9_i193;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), c9_dv14, 1, 0, 0U, 1, 0U, 1, 9);
  for (c9_i193 = 0; c9_i193 < 9; c9_i193++) {
    c9_y[c9_i193] = c9_dv14[c9_i193];
  }

  sf_mex_destroy(&c9_u);
}

static void c9_h_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_DL;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y[9];
  int32_T c9_i194;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_DL = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_k_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_DL), &c9_thisId, c9_y);
  sf_mex_destroy(&c9_DL);
  for (c9_i194 = 0; c9_i194 < 9; c9_i194++) {
    (*(real_T (*)[9])c9_outData)[c9_i194] = c9_y[c9_i194];
  }

  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_createstruct("structure", 2, 25, 1),
                false);
  c9_info_helper(&c9_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c9_nameCaptureInfo);
  return c9_nameCaptureInfo;
}

static void c9_info_helper(const mxArray **c9_info)
{
  const mxArray *c9_rhs0 = NULL;
  const mxArray *c9_lhs0 = NULL;
  const mxArray *c9_rhs1 = NULL;
  const mxArray *c9_lhs1 = NULL;
  const mxArray *c9_rhs2 = NULL;
  const mxArray *c9_lhs2 = NULL;
  const mxArray *c9_rhs3 = NULL;
  const mxArray *c9_lhs3 = NULL;
  const mxArray *c9_rhs4 = NULL;
  const mxArray *c9_lhs4 = NULL;
  const mxArray *c9_rhs5 = NULL;
  const mxArray *c9_lhs5 = NULL;
  const mxArray *c9_rhs6 = NULL;
  const mxArray *c9_lhs6 = NULL;
  const mxArray *c9_rhs7 = NULL;
  const mxArray *c9_lhs7 = NULL;
  const mxArray *c9_rhs8 = NULL;
  const mxArray *c9_lhs8 = NULL;
  const mxArray *c9_rhs9 = NULL;
  const mxArray *c9_lhs9 = NULL;
  const mxArray *c9_rhs10 = NULL;
  const mxArray *c9_lhs10 = NULL;
  const mxArray *c9_rhs11 = NULL;
  const mxArray *c9_lhs11 = NULL;
  const mxArray *c9_rhs12 = NULL;
  const mxArray *c9_lhs12 = NULL;
  const mxArray *c9_rhs13 = NULL;
  const mxArray *c9_lhs13 = NULL;
  const mxArray *c9_rhs14 = NULL;
  const mxArray *c9_lhs14 = NULL;
  const mxArray *c9_rhs15 = NULL;
  const mxArray *c9_lhs15 = NULL;
  const mxArray *c9_rhs16 = NULL;
  const mxArray *c9_lhs16 = NULL;
  const mxArray *c9_rhs17 = NULL;
  const mxArray *c9_lhs17 = NULL;
  const mxArray *c9_rhs18 = NULL;
  const mxArray *c9_lhs18 = NULL;
  const mxArray *c9_rhs19 = NULL;
  const mxArray *c9_lhs19 = NULL;
  const mxArray *c9_rhs20 = NULL;
  const mxArray *c9_lhs20 = NULL;
  const mxArray *c9_rhs21 = NULL;
  const mxArray *c9_lhs21 = NULL;
  const mxArray *c9_rhs22 = NULL;
  const mxArray *c9_lhs22 = NULL;
  const mxArray *c9_rhs23 = NULL;
  const mxArray *c9_lhs23 = NULL;
  const mxArray *c9_rhs24 = NULL;
  const mxArray *c9_lhs24 = NULL;
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("FootHeightAndVelocity"),
                  "name", "name", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/FootHeightAndVelocity.m"),
                  "resolved", "resolved", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1444269963U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c9_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/FootHeightAndVelocity.m"),
                  "context", "context", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "ATRIAS3D_FootPointPosJacob_Hip"), "name", "name", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Models/OriginalLeg_Updated/m/ATRIAS3D_FootPointPosJacob_Hip.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1444616514U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c9_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Models/OriginalLeg_Updated/m/ATRIAS3D_FootPointPosJacob_Hip.m"),
                  "context", "context", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("cos"), "name", "name", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1395346496U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c9_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_cos"), "name",
                  "name", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286840322U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c9_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Models/OriginalLeg_Updated/m/ATRIAS3D_FootPointPosJacob_Hip.m"),
                  "context", "context", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("sin"), "name", "name", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved",
                  "resolved", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1395346504U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c9_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_sin"), "name",
                  "name", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                  "resolved", "resolved", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286840336U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c9_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/FootHeightAndVelocity.m"),
                  "context", "context", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_mtimes_helper"), "name",
                  "name", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "resolved", "resolved", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1383898894U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c9_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs6), "lhs", "lhs", 6);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                  "context", "context", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
                  "fileTimeLo", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 7);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 7);
  sf_mex_assign(&c9_rhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs7, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs7), "rhs", "rhs", 7);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs7), "lhs", "lhs", 7);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 8);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 8);
  sf_mex_assign(&c9_rhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs8, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs8), "rhs", "rhs", 8);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs8), "lhs", "lhs", 8);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_eg"), "name",
                  "name", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                  "resolved", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376002288U), "fileTimeLo",
                  "fileTimeLo", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 9);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 9);
  sf_mex_assign(&c9_rhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs9, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs9), "rhs", "rhs", 9);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs9), "lhs", "lhs", 9);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                  "context", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 10);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 10);
  sf_mex_assign(&c9_rhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs10, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs10), "rhs", "rhs",
                  10);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs10), "lhs", "lhs",
                  10);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                  "context", "context", 11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_xgemm"), "name", "name",
                  11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"),
                  "resolved", "resolved", 11);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1376002290U), "fileTimeLo",
                  "fileTimeLo", 11);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 11);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 11);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 11);
  sf_mex_assign(&c9_rhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs11, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs11), "rhs", "rhs",
                  11);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs11), "lhs", "lhs",
                  11);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.blas.inline"),
                  "name", "name", 12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                  "resolved", "resolved", 12);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 12);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 12);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 12);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 12);
  sf_mex_assign(&c9_rhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs12, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs12), "rhs", "rhs",
                  12);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs12), "lhs", "lhs",
                  12);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgemm.m"), "context",
                  "context", 13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.blas.xgemm"),
                  "name", "name", 13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "resolved", "resolved", 13);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 13);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 13);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 13);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 13);
  sf_mex_assign(&c9_rhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs13, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs13), "rhs", "rhs",
                  13);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs13), "lhs", "lhs",
                  13);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.blas.use_refblas"), "name", "name", 14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                  "resolved", "resolved", 14);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 14);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 14);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 14);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 14);
  sf_mex_assign(&c9_rhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs14, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs14), "rhs", "rhs",
                  14);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs14), "lhs", "lhs",
                  14);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p!below_threshold"),
                  "context", "context", 15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.blas.threshold"),
                  "name", "name", 15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "resolved", "resolved", 15);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 15);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 15);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 15);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 15);
  sf_mex_assign(&c9_rhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs15, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs15), "rhs", "rhs",
                  15);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs15), "lhs", "lhs",
                  15);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                  "context", "context", 16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_switch_helper"), "name",
                  "name", 16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                  "resolved", "resolved", 16);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1393352458U), "fileTimeLo",
                  "fileTimeLo", 16);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 16);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 16);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 16);
  sf_mex_assign(&c9_rhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs16, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs16), "rhs", "rhs",
                  16);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs16), "lhs", "lhs",
                  16);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.scalarEg"),
                  "name", "name", 17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                  "resolved", "resolved", 17);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1410829370U), "fileTimeLo",
                  "fileTimeLo", 17);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 17);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 17);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 17);
  sf_mex_assign(&c9_rhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs17, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs17), "rhs", "rhs",
                  17);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs17), "lhs", "lhs",
                  17);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgemm.p"),
                  "context", "context", 18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.refblas.xgemm"),
                  "name", "name", 18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgemm.p"),
                  "resolved", "resolved", 18);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1410829372U), "fileTimeLo",
                  "fileTimeLo", 18);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 18);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 18);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 18);
  sf_mex_assign(&c9_rhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs18, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs18), "rhs", "rhs",
                  18);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs18), "lhs", "lhs",
                  18);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Sims/Model/FootHeightAndVelocity.m"),
                  "context", "context", 19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_li_find"), "name", "name",
                  19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "resolved",
                  "resolved", 19);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286840386U), "fileTimeLo",
                  "fileTimeLo", 19);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 19);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 19);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 19);
  sf_mex_assign(&c9_rhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs19, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs19), "rhs", "rhs",
                  19);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs19), "lhs", "lhs",
                  19);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 20);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 20);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 20);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 20);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 20);
  sf_mex_assign(&c9_rhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs20, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs20), "rhs", "rhs",
                  20);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs20), "lhs", "lhs",
                  20);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_class"), "name",
                  "name", 21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "dominantType",
                  "dominantType", 21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                  "resolved", "resolved", 21);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1323192178U), "fileTimeLo",
                  "fileTimeLo", 21);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 21);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 21);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 21);
  sf_mex_assign(&c9_rhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs21, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs21), "rhs", "rhs",
                  21);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs21), "lhs", "lhs",
                  21);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m!compute_nones"),
                  "context", "context", 22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 22);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 22);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 22);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 22);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 22);
  sf_mex_assign(&c9_rhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs22, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs22), "rhs", "rhs",
                  22);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs22), "lhs", "lhs",
                  22);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                  "context", 23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("coder.internal.indexPlus"),
                  "name", "name", 23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                  "resolved", "resolved", 23);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1372604760U), "fileTimeLo",
                  "fileTimeLo", 23);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 23);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 23);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 23);
  sf_mex_assign(&c9_rhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs23, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs23), "rhs", "rhs",
                  23);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs23), "lhs", "lhs",
                  23);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_li_find.m"), "context",
                  "context", 24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_index_plus"), "name",
                  "name", 24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 24);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                  "resolved", "resolved", 24);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1372604016U), "fileTimeLo",
                  "fileTimeLo", 24);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 24);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 24);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 24);
  sf_mex_assign(&c9_rhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c9_lhs24, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_rhs24), "rhs", "rhs",
                  24);
  sf_mex_addfield(*c9_info, sf_mex_duplicatearraysafe(&c9_lhs24), "lhs", "lhs",
                  24);
  sf_mex_destroy(&c9_rhs0);
  sf_mex_destroy(&c9_lhs0);
  sf_mex_destroy(&c9_rhs1);
  sf_mex_destroy(&c9_lhs1);
  sf_mex_destroy(&c9_rhs2);
  sf_mex_destroy(&c9_lhs2);
  sf_mex_destroy(&c9_rhs3);
  sf_mex_destroy(&c9_lhs3);
  sf_mex_destroy(&c9_rhs4);
  sf_mex_destroy(&c9_lhs4);
  sf_mex_destroy(&c9_rhs5);
  sf_mex_destroy(&c9_lhs5);
  sf_mex_destroy(&c9_rhs6);
  sf_mex_destroy(&c9_lhs6);
  sf_mex_destroy(&c9_rhs7);
  sf_mex_destroy(&c9_lhs7);
  sf_mex_destroy(&c9_rhs8);
  sf_mex_destroy(&c9_lhs8);
  sf_mex_destroy(&c9_rhs9);
  sf_mex_destroy(&c9_lhs9);
  sf_mex_destroy(&c9_rhs10);
  sf_mex_destroy(&c9_lhs10);
  sf_mex_destroy(&c9_rhs11);
  sf_mex_destroy(&c9_lhs11);
  sf_mex_destroy(&c9_rhs12);
  sf_mex_destroy(&c9_lhs12);
  sf_mex_destroy(&c9_rhs13);
  sf_mex_destroy(&c9_lhs13);
  sf_mex_destroy(&c9_rhs14);
  sf_mex_destroy(&c9_lhs14);
  sf_mex_destroy(&c9_rhs15);
  sf_mex_destroy(&c9_lhs15);
  sf_mex_destroy(&c9_rhs16);
  sf_mex_destroy(&c9_lhs16);
  sf_mex_destroy(&c9_rhs17);
  sf_mex_destroy(&c9_lhs17);
  sf_mex_destroy(&c9_rhs18);
  sf_mex_destroy(&c9_lhs18);
  sf_mex_destroy(&c9_rhs19);
  sf_mex_destroy(&c9_lhs19);
  sf_mex_destroy(&c9_rhs20);
  sf_mex_destroy(&c9_lhs20);
  sf_mex_destroy(&c9_rhs21);
  sf_mex_destroy(&c9_lhs21);
  sf_mex_destroy(&c9_rhs22);
  sf_mex_destroy(&c9_lhs22);
  sf_mex_destroy(&c9_rhs23);
  sf_mex_destroy(&c9_lhs23);
  sf_mex_destroy(&c9_rhs24);
  sf_mex_destroy(&c9_lhs24);
}

static const mxArray *c9_emlrt_marshallOut(const char * c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c9_u)), false);
  return c9_y;
}

static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u)
{
  const mxArray *c9_y = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 7, 0U, 0U, 0U, 0), false);
  return c9_y;
}

static void c9_eml_scalar_eg(SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_threshold(SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_b_eml_scalar_eg(SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_c_eml_scalar_eg(SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c9_eml_li_find(SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance,
  boolean_T c9_b_x, int32_T c9_y_data[], int32_T c9_y_sizes[2])
{
  boolean_T c9_c_x;
  int32_T c9_k;
  int32_T c9_tmp_sizes[2];
  int32_T c9_iv2[2];
  int32_T c9_i195;
  int32_T c9_i196;
  int32_T c9_loop_ub;
  int32_T c9_i197;
  int32_T c9_tmp_data[1];
  int32_T c9_i198;
  (void)chartInstance;
  c9_c_x = c9_b_x;
  c9_k = 0;
  if (c9_c_x) {
    c9_k = 1;
  }

  c9_tmp_sizes[0] = 1;
  c9_iv2[0] = 1;
  c9_iv2[1] = c9_k;
  c9_tmp_sizes[1] = c9_iv2[1];
  c9_i195 = c9_tmp_sizes[0];
  c9_i196 = c9_tmp_sizes[1];
  c9_loop_ub = c9_k - 1;
  for (c9_i197 = 0; c9_i197 <= c9_loop_ub; c9_i197++) {
    c9_tmp_data[c9_i197] = 0;
  }

  for (c9_i198 = 0; c9_i198 < 2; c9_i198++) {
    c9_y_sizes[c9_i198] = c9_tmp_sizes[c9_i198];
  }

  if (c9_b_x) {
    _SFD_EML_ARRAY_BOUNDS_CHECK("", 1, 1, c9_y_sizes[1], 1, 0);
    c9_y_data[0] = 1;
  }
}

static const mxArray *c9_i_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_l_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i199;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i199, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i199;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_i_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_l_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static uint8_T c9_m_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_b_is_active_c9_DDA2D_OSU3Dv2, const char_T
  *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_n_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_is_active_c9_DDA2D_OSU3Dv2), &c9_thisId);
  sf_mex_destroy(&c9_b_is_active_c9_DDA2D_OSU3Dv2);
  return c9_y;
}

static uint8_T c9_n_emlrt_marshallIn(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u0, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc9_DDA2D_OSU3Dv2InstanceStruct
  *chartInstance)
{
  chartInstance->c9_x = (real_T (*)[32])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c9_pR = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_vR = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c9_J4R = (real_T (*)[48])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c9_JR1Col = (real_T (*)[144])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c9_pL = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c9_vL = (real_T (*)[3])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c9_J4L = (real_T (*)[48])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 7);
  chartInstance->c9_JR5Col = (real_T (*)[144])ssGetOutputPortSignal_wrapper
    (chartInstance->S, 8);
  chartInstance->c9_FootPoints = (real_T (*)[3])ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
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

void sf_c9_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(814535541U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1897972474U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3917786361U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2114987078U);
}

mxArray* sf_c9_DDA2D_OSU3Dv2_get_post_codegen_info(void);
mxArray *sf_c9_DDA2D_OSU3Dv2_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("jxIMOYl4hjxE1mpxGa1EtE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,8,3,dataFields);

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
      pr[0] = (double)(3);
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
      pr[0] = (double)(9);
      pr[1] = (double)(16);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
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
      pr[0] = (double)(3);
      pr[1] = (double)(16);
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
      pr[0] = (double)(9);
      pr[1] = (double)(16);
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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c9_DDA2D_OSU3Dv2_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_DDA2D_OSU3Dv2_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_DDA2D_OSU3Dv2_jit_fallback_info(void)
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

mxArray *sf_c9_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c9_DDA2D_OSU3Dv2_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c9_DDA2D_OSU3Dv2(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[14],T\"J4L\",},{M[1],M[10],T\"J4R\",},{M[1],M[11],T\"JR1Col\",},{M[1],M[15],T\"JR5Col\",},{M[1],M[12],T\"pL\",},{M[1],M[5],T\"pR\",},{M[1],M[13],T\"vL\",},{M[1],M[9],T\"vR\",},{M[8],M[0],T\"is_active_c9_DDA2D_OSU3Dv2\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_DDA2D_OSU3Dv2_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _DDA2D_OSU3Dv2MachineNumber_,
           9,
           1,
           1,
           0,
           10,
           0,
           0,
           0,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(1,2,0,1,"pR");
          _SFD_SET_DATA_PROPS(2,2,0,1,"vR");
          _SFD_SET_DATA_PROPS(3,2,0,1,"J4R");
          _SFD_SET_DATA_PROPS(4,2,0,1,"JR1Col");
          _SFD_SET_DATA_PROPS(5,2,0,1,"pL");
          _SFD_SET_DATA_PROPS(6,2,0,1,"vL");
          _SFD_SET_DATA_PROPS(7,2,0,1,"J4L");
          _SFD_SET_DATA_PROPS(8,2,0,1,"JR5Col");
          _SFD_SET_DATA_PROPS(9,1,1,0,"FootPoints");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,198);
        _SFD_CV_INIT_SCRIPT(0,1,0,0,0,0,2,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(0,0,"FootHeightAndVelocity",0,-1,1164);
        _SFD_CV_INIT_SCRIPT_FOR(0,0,521,537,633);
        _SFD_CV_INIT_SCRIPT_FOR(0,1,810,826,1035);
        _SFD_CV_INIT_SCRIPT(1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_SCRIPT_FCN(1,0,"ATRIAS3D_FootPointPosJacob_Hip",0,-1,17069);

        {
          unsigned int dimVector[1];
          dimVector[0]= 32;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_d_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)
            c9_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)
            c9_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 16;
          _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 9;
          dimVector[1]= 16;
          _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)
            c9_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)
            c9_c_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 3;
          dimVector[1]= 16;
          _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)
            c9_b_sf_marshallIn);
        }

        {
          unsigned int dimVector[2];
          dimVector[0]= 9;
          dimVector[1]= 16;
          _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,2,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)
            c9_sf_marshallIn);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 3;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_c_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c9_x);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c9_pR);
        _SFD_SET_DATA_VALUE_PTR(2U, *chartInstance->c9_vR);
        _SFD_SET_DATA_VALUE_PTR(3U, *chartInstance->c9_J4R);
        _SFD_SET_DATA_VALUE_PTR(4U, *chartInstance->c9_JR1Col);
        _SFD_SET_DATA_VALUE_PTR(5U, *chartInstance->c9_pL);
        _SFD_SET_DATA_VALUE_PTR(6U, *chartInstance->c9_vL);
        _SFD_SET_DATA_VALUE_PTR(7U, *chartInstance->c9_J4L);
        _SFD_SET_DATA_VALUE_PTR(8U, *chartInstance->c9_JR5Col);
        _SFD_SET_DATA_VALUE_PTR(9U, *chartInstance->c9_FootPoints);
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
  return "vCdDf1Y4QLbRLMu4yQnxxF";
}

static void sf_opaque_initialize_c9_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc9_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_DDA2D_OSU3Dv2((SFc9_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
  initialize_c9_DDA2D_OSU3Dv2((SFc9_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  enable_c9_DDA2D_OSU3Dv2((SFc9_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_disable_c9_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  disable_c9_DDA2D_OSU3Dv2((SFc9_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar);
}

static void sf_opaque_gateway_c9_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  sf_gateway_c9_DDA2D_OSU3Dv2((SFc9_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c9_DDA2D_OSU3Dv2(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c9_DDA2D_OSU3Dv2((SFc9_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c9_DDA2D_OSU3Dv2(SimStruct* S, const mxArray
  *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c9_DDA2D_OSU3Dv2((SFc9_DDA2D_OSU3Dv2InstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c9_DDA2D_OSU3Dv2(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_DDA2D_OSU3Dv2InstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_DDA2D_OSU3Dv2_optimization_info();
    }

    finalize_c9_DDA2D_OSU3Dv2((SFc9_DDA2D_OSU3Dv2InstanceStruct*)
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
  initSimStructsc9_DDA2D_OSU3Dv2((SFc9_DDA2D_OSU3Dv2InstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_DDA2D_OSU3Dv2(SimStruct *S)
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
    initialize_params_c9_DDA2D_OSU3Dv2((SFc9_DDA2D_OSU3Dv2InstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c9_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_DDA2D_OSU3Dv2_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,9);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,9,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,9,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,9);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,2);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,8);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=8; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 2; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(4278356459U));
  ssSetChecksum1(S,(3446051750U));
  ssSetChecksum2(S,(1738497246U));
  ssSetChecksum3(S,(2655600201U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_DDA2D_OSU3Dv2(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c9_DDA2D_OSU3Dv2(SimStruct *S)
{
  SFc9_DDA2D_OSU3Dv2InstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc9_DDA2D_OSU3Dv2InstanceStruct *)utMalloc(sizeof
    (SFc9_DDA2D_OSU3Dv2InstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_DDA2D_OSU3Dv2InstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway = sf_opaque_gateway_c9_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.terminateChart = sf_opaque_terminate_c9_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_DDA2D_OSU3Dv2;
  chartInstance->chartInfo.mdlSetWorkWidths = mdlSetWorkWidths_c9_DDA2D_OSU3Dv2;
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

void c9_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_DDA2D_OSU3Dv2(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_DDA2D_OSU3Dv2(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_DDA2D_OSU3Dv2_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
