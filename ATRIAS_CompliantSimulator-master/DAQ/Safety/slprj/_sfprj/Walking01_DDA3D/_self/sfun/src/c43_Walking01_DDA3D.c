/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_DDA3D_sfun.h"
#include "c43_Walking01_DDA3D.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Walking01_DDA3D_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c43_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c43_IN_FaultRunning            ((uint8_T)1U)
#define c43_IN_Initialization          ((uint8_T)2U)
#define c43_IN_Running                 ((uint8_T)3U)
#define c43_IN_Start1                  ((uint8_T)4U)
#define c43_IN_Fault                   ((uint8_T)1U)
#define c43_IN_ReadyToSwitchOn         ((uint8_T)2U)
#define c43_IN_SwitchOnDisabled        ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c43_debug_family_names[2] = { "nargin", "nargout" };

static const char * c43_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c43_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c43_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c43_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c43_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c43_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c43_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c43_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c43_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c43_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c43_Walking01_DDA3D(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initialize_params_c43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance);
static void enable_c43_Walking01_DDA3D(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void disable_c43_Walking01_DDA3D(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c43_update_debugger_state_c43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance);
static void ext_mode_exec_c43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance);
static void set_sim_state_c43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c43_st);
static void c43_set_sim_state_side_effects_c43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance);
static void finalize_c43_Walking01_DDA3D(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void sf_gateway_c43_Walking01_DDA3D(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void mdl_start_c43_Walking01_DDA3D(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initSimStructsc43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance);
static void c43_Initialization(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c43_exit_internal_Initialization(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c43_machineNumber, uint32_T
  c43_chartNumber, uint32_T c43_instanceNumber);
static const mxArray *c43_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static real_T c43_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_nargout, const char_T *c43_identifier);
static real_T c43_b_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_b_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static boolean_T c43_c_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_c_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static int32_T c43_d_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static const mxArray *c43_d_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData);
static uint8_T c43_e_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_b_is_Initialization, const char_T
  *c43_identifier);
static uint8_T c43_f_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData);
static void c43_g_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_b_dataWrittenToVector, const char_T
  *c43_identifier, boolean_T c43_y[4]);
static void c43_h_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId,
  boolean_T c43_y[4]);
static const mxArray *c43_i_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_b_setSimStateSideEffectsInfo, const char_T *
  c43_identifier);
static const mxArray *c43_j_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId);
static void c43_updateDataWrittenToVector(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, uint32_T c43_vectorIndex);
static void c43_errorIfDataNotWrittenToFcn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, uint32_T c43_vectorIndex, uint32_T c43_dataNumber, uint32_T
  c43_ssIdOfSourceObject, int32_T c43_offsetInSourceObject, int32_T
  c43_lengthInSourceObject);
static void init_dsm_address_info(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c43_Walking01_DDA3D(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  *chartInstance->c43_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c43_doSetSimStateSideEffects = 0U;
  chartInstance->c43_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c43_is_Initialization = c43_IN_NO_ACTIVE_CHILD;
  *chartInstance->c43_is_active_c43_Walking01_DDA3D = 0U;
  *chartInstance->c43_is_c43_Walking01_DDA3D = c43_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c43_Walking01_DDA3D(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c43_Walking01_DDA3D(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c43_update_debugger_state_c43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance)
{
  uint32_T c43_prevAniVal;
  c43_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c43_is_active_c43_Walking01_DDA3D == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 11U, *chartInstance->c43_sfEvent);
  }

  if (*chartInstance->c43_is_c43_Walking01_DDA3D == c43_IN_Start1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c43_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c43_sfEvent);
  }

  if (*chartInstance->c43_is_c43_Walking01_DDA3D == c43_IN_Initialization) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c43_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c43_sfEvent);
  }

  if (*chartInstance->c43_is_Initialization == c43_IN_SwitchOnDisabled) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c43_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c43_sfEvent);
  }

  if (*chartInstance->c43_is_Initialization == c43_IN_Fault) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c43_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c43_sfEvent);
  }

  if (*chartInstance->c43_is_Initialization == c43_IN_ReadyToSwitchOn) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c43_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c43_sfEvent);
  }

  if (*chartInstance->c43_is_c43_Walking01_DDA3D == c43_IN_FaultRunning) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c43_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c43_sfEvent);
  }

  if (*chartInstance->c43_is_c43_Walking01_DDA3D == c43_IN_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c43_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c43_sfEvent);
  }

  _SFD_SET_ANIMATION(c43_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance)
{
  c43_update_debugger_state_c43_Walking01_DDA3D(chartInstance);
}

static const mxArray *get_sim_state_c43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance)
{
  const mxArray *c43_st;
  const mxArray *c43_y = NULL;
  real_T c43_hoistedGlobal;
  real_T c43_u;
  const mxArray *c43_b_y = NULL;
  real_T c43_b_hoistedGlobal;
  real_T c43_b_u;
  const mxArray *c43_c_y = NULL;
  real_T c43_c_hoistedGlobal;
  real_T c43_c_u;
  const mxArray *c43_d_y = NULL;
  real_T c43_d_hoistedGlobal;
  real_T c43_d_u;
  const mxArray *c43_e_y = NULL;
  uint8_T c43_e_hoistedGlobal;
  uint8_T c43_e_u;
  const mxArray *c43_f_y = NULL;
  uint8_T c43_f_hoistedGlobal;
  uint8_T c43_f_u;
  const mxArray *c43_g_y = NULL;
  uint8_T c43_g_hoistedGlobal;
  uint8_T c43_g_u;
  const mxArray *c43_h_y = NULL;
  int32_T c43_i0;
  boolean_T c43_h_u[4];
  const mxArray *c43_i_y = NULL;
  c43_st = NULL;
  c43_st = NULL;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_createcellmatrix(8, 1), false);
  c43_hoistedGlobal = *chartInstance->c43_ControlWordIndex;
  c43_u = c43_hoistedGlobal;
  c43_b_y = NULL;
  sf_mex_assign(&c43_b_y, sf_mex_create("y", &c43_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c43_y, 0, c43_b_y);
  c43_b_hoistedGlobal = *chartInstance->c43_EnableTargetTorque;
  c43_b_u = c43_b_hoistedGlobal;
  c43_c_y = NULL;
  sf_mex_assign(&c43_c_y, sf_mex_create("y", &c43_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c43_y, 1, c43_c_y);
  c43_c_hoistedGlobal = *chartInstance->c43_FaultDetected;
  c43_c_u = c43_c_hoistedGlobal;
  c43_d_y = NULL;
  sf_mex_assign(&c43_d_y, sf_mex_create("y", &c43_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c43_y, 2, c43_d_y);
  c43_d_hoistedGlobal = *chartInstance->c43_Timeout;
  c43_d_u = c43_d_hoistedGlobal;
  c43_e_y = NULL;
  sf_mex_assign(&c43_e_y, sf_mex_create("y", &c43_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c43_y, 3, c43_e_y);
  c43_e_hoistedGlobal = *chartInstance->c43_is_active_c43_Walking01_DDA3D;
  c43_e_u = c43_e_hoistedGlobal;
  c43_f_y = NULL;
  sf_mex_assign(&c43_f_y, sf_mex_create("y", &c43_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c43_y, 4, c43_f_y);
  c43_f_hoistedGlobal = *chartInstance->c43_is_c43_Walking01_DDA3D;
  c43_f_u = c43_f_hoistedGlobal;
  c43_g_y = NULL;
  sf_mex_assign(&c43_g_y, sf_mex_create("y", &c43_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c43_y, 5, c43_g_y);
  c43_g_hoistedGlobal = *chartInstance->c43_is_Initialization;
  c43_g_u = c43_g_hoistedGlobal;
  c43_h_y = NULL;
  sf_mex_assign(&c43_h_y, sf_mex_create("y", &c43_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c43_y, 6, c43_h_y);
  for (c43_i0 = 0; c43_i0 < 4; c43_i0++) {
    c43_h_u[c43_i0] = chartInstance->c43_dataWrittenToVector[c43_i0];
  }

  c43_i_y = NULL;
  sf_mex_assign(&c43_i_y, sf_mex_create("y", c43_h_u, 11, 0U, 1U, 0U, 1, 4),
                false);
  sf_mex_setcell(c43_y, 7, c43_i_y);
  sf_mex_assign(&c43_st, c43_y, false);
  return c43_st;
}

static void set_sim_state_c43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c43_st)
{
  const mxArray *c43_u;
  boolean_T c43_bv0[4];
  int32_T c43_i1;
  c43_u = sf_mex_dup(c43_st);
  *chartInstance->c43_ControlWordIndex = c43_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c43_u, 0)), "ControlWordIndex");
  *chartInstance->c43_EnableTargetTorque = c43_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c43_u, 1)), "EnableTargetTorque");
  *chartInstance->c43_FaultDetected = c43_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c43_u, 2)), "FaultDetected");
  *chartInstance->c43_Timeout = c43_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c43_u, 3)), "Timeout");
  *chartInstance->c43_is_active_c43_Walking01_DDA3D = c43_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c43_u, 4)),
     "is_active_c43_Walking01_DDA3D");
  *chartInstance->c43_is_c43_Walking01_DDA3D = c43_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c43_u, 5)),
     "is_c43_Walking01_DDA3D");
  *chartInstance->c43_is_Initialization = c43_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c43_u, 6)), "is_Initialization");
  c43_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c43_u, 7)),
    "dataWrittenToVector", c43_bv0);
  for (c43_i1 = 0; c43_i1 < 4; c43_i1++) {
    chartInstance->c43_dataWrittenToVector[c43_i1] = c43_bv0[c43_i1];
  }

  sf_mex_assign(&chartInstance->c43_setSimStateSideEffectsInfo,
                c43_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c43_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c43_u);
  chartInstance->c43_doSetSimStateSideEffects = 1U;
  c43_update_debugger_state_c43_Walking01_DDA3D(chartInstance);
  sf_mex_destroy(&c43_st);
}

static void c43_set_sim_state_side_effects_c43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance)
{
  if (chartInstance->c43_doSetSimStateSideEffects != 0) {
    chartInstance->c43_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c43_Walking01_DDA3D(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c43_setSimStateSideEffectsInfo);
}

static void sf_gateway_c43_Walking01_DDA3D(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  uint32_T c43_debug_family_var_map[2];
  real_T c43_nargin = 0.0;
  real_T c43_nargout = 0.0;
  uint32_T c43_b_debug_family_var_map[3];
  real_T c43_b_nargin = 0.0;
  real_T c43_b_nargout = 1.0;
  boolean_T c43_out;
  real_T c43_c_nargin = 0.0;
  real_T c43_c_nargout = 0.0;
  real_T c43_d_nargin = 0.0;
  real_T c43_d_nargout = 1.0;
  boolean_T c43_b_out;
  real_T c43_e_nargin = 0.0;
  real_T c43_e_nargout = 0.0;
  real_T c43_f_nargin = 0.0;
  real_T c43_f_nargout = 1.0;
  boolean_T c43_c_out;
  real_T c43_g_nargin = 0.0;
  real_T c43_g_nargout = 0.0;
  boolean_T guard1 = false;
  c43_set_sim_state_side_effects_c43_Walking01_DDA3D(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, *chartInstance->c43_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c43_SwitchOnDisabledMode, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c43_EnabledMode, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c43_ReadyToSwitchOnMode, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c43_EnableTargetTorque, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c43_Timeout, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c43_FaultMode, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c43_FaultDetected, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c43_MedullaCommand, 8U);
  *chartInstance->c43_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, *chartInstance->c43_sfEvent);
  if (*chartInstance->c43_is_active_c43_Walking01_DDA3D == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 11U,
                 *chartInstance->c43_sfEvent);
    *chartInstance->c43_is_active_c43_Walking01_DDA3D = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, *chartInstance->c43_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c43_sfEvent);
    *chartInstance->c43_is_c43_Walking01_DDA3D = c43_IN_Start1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c43_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_debug_family_names,
      c43_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargin, 0U, c43_sf_marshallOut,
      c43_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargout, 1U, c43_sf_marshallOut,
      c43_sf_marshallIn);
    *chartInstance->c43_ControlWordIndex = 0.0;
    c43_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
    *chartInstance->c43_EnableTargetTorque = 0.0;
    c43_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c43_EnableTargetTorque, 4U);
    *chartInstance->c43_FaultDetected = 0.0;
    c43_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c43_FaultDetected, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (*chartInstance->c43_is_c43_Walking01_DDA3D) {
     case c43_IN_FaultRunning:
      CV_CHART_EVAL(11, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   *chartInstance->c43_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c43_sfEvent);
      break;

     case c43_IN_Initialization:
      CV_CHART_EVAL(11, 0, 2);
      c43_Initialization(chartInstance);
      break;

     case c43_IN_Running:
      CV_CHART_EVAL(11, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   *chartInstance->c43_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c43_r_debug_family_names,
        c43_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_b_nargin, 0U, c43_sf_marshallOut,
        c43_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_b_nargout, 1U,
        c43_sf_marshallOut, c43_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_out, 2U, c43_b_sf_marshallOut,
        c43_b_sf_marshallIn);
      c43_out = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, (real_T)
        *chartInstance->c43_FaultMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c43_FaultMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c43_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c43_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c43_sfEvent);
        *chartInstance->c43_is_c43_Walking01_DDA3D = c43_IN_FaultRunning;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c43_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_h_debug_family_names,
          c43_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_c_nargin, 0U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_c_nargout, 1U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        *chartInstance->c43_ControlWordIndex = 1.0;
        c43_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
        *chartInstance->c43_EnableTargetTorque = 0.0;
        c43_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_EnableTargetTorque, 4U);
        *chartInstance->c43_FaultDetected = 1.0;
        c43_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                     *chartInstance->c43_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c43_s_debug_family_names,
          c43_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_d_nargin, 0U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_d_nargout, 1U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_b_out, 2U,
          c43_b_sf_marshallOut, c43_b_sf_marshallIn);
        guard1 = false;
        if (CV_EML_COND(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0,
              *chartInstance->c43_MedullaCommand, 4.0, -1, 0U,
              *chartInstance->c43_MedullaCommand == 4.0))) {
          guard1 = true;
        } else if (CV_EML_COND(9, 0, 1, CV_RELATIONAL_EVAL(5U, 9U, 1,
                     *chartInstance->c43_MedullaCommand, 5.0, -1, 0U,
                     *chartInstance->c43_MedullaCommand == 5.0))) {
          guard1 = true;
        } else {
          CV_EML_MCDC(9, 0, 0, false);
          CV_EML_IF(9, 0, 0, false);
          c43_b_out = false;
        }

        if (guard1 == true) {
          CV_EML_MCDC(9, 0, 0, true);
          CV_EML_IF(9, 0, 0, true);
          c43_b_out = true;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c43_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, *chartInstance->c43_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c43_sfEvent);
          *chartInstance->c43_is_c43_Walking01_DDA3D = c43_IN_FaultRunning;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c43_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_h_debug_family_names,
            c43_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_e_nargin, 0U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_e_nargout, 1U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          *chartInstance->c43_ControlWordIndex = 1.0;
          c43_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
          *chartInstance->c43_EnableTargetTorque = 0.0;
          c43_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_EnableTargetTorque, 4U);
          *chartInstance->c43_FaultDetected = 1.0;
          c43_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_FaultDetected, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                       *chartInstance->c43_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c43_sfEvent);
      break;

     case c43_IN_Start1:
      CV_CHART_EVAL(11, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                   *chartInstance->c43_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c43_p_debug_family_names,
        c43_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_f_nargin, 0U, c43_sf_marshallOut,
        c43_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_f_nargout, 1U,
        c43_sf_marshallOut, c43_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_c_out, 2U, c43_b_sf_marshallOut,
        c43_b_sf_marshallIn);
      c43_c_out = CV_EML_IF(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0,
        *chartInstance->c43_MedullaCommand, 2.0, -1, 0U,
        *chartInstance->c43_MedullaCommand == 2.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c43_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *chartInstance->c43_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c43_sfEvent);
        *chartInstance->c43_is_c43_Walking01_DDA3D = c43_IN_Initialization;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c43_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, *chartInstance->c43_sfEvent);
        *chartInstance->c43_is_Initialization = c43_IN_SwitchOnDisabled;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c43_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_b_debug_family_names,
          c43_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_g_nargin, 0U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_g_nargout, 1U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        *chartInstance->c43_ControlWordIndex = 1.0;
        c43_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
        *chartInstance->c43_Timeout = 0.0;
        c43_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_Timeout, 5U);
        *chartInstance->c43_EnableTargetTorque = 0.0;
        c43_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_EnableTargetTorque, 4U);
        *chartInstance->c43_FaultDetected = 0.0;
        c43_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     *chartInstance->c43_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c43_sfEvent);
      break;

     default:
      CV_CHART_EVAL(11, 0, 0);
      *chartInstance->c43_is_c43_Walking01_DDA3D = c43_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c43_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, *chartInstance->c43_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_DDA3DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c43_Walking01_DDA3D(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc43_Walking01_DDA3D
  (SFc43_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c43_Initialization(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  uint32_T c43_debug_family_var_map[3];
  real_T c43_nargin = 0.0;
  real_T c43_nargout = 1.0;
  boolean_T c43_out;
  uint32_T c43_b_debug_family_var_map[2];
  real_T c43_b_nargin = 0.0;
  real_T c43_b_nargout = 0.0;
  real_T c43_c_nargin = 0.0;
  real_T c43_c_nargout = 1.0;
  boolean_T c43_b_out;
  real_T c43_d_nargin = 0.0;
  real_T c43_d_nargout = 0.0;
  real_T c43_e_nargin = 0.0;
  real_T c43_e_nargout = 1.0;
  boolean_T c43_c_out;
  real_T c43_f_nargin = 0.0;
  real_T c43_f_nargout = 0.0;
  real_T c43_g_nargin = 0.0;
  real_T c43_g_nargout = 0.0;
  real_T c43_h_nargin = 0.0;
  real_T c43_h_nargout = 1.0;
  boolean_T c43_d_out;
  real_T c43_i_nargin = 0.0;
  real_T c43_i_nargout = 0.0;
  real_T c43_j_nargin = 0.0;
  real_T c43_j_nargout = 1.0;
  boolean_T c43_e_out;
  real_T c43_k_nargin = 0.0;
  real_T c43_k_nargout = 0.0;
  real_T c43_l_nargin = 0.0;
  real_T c43_l_nargout = 1.0;
  boolean_T c43_f_out;
  real_T c43_m_nargin = 0.0;
  real_T c43_m_nargout = 0.0;
  real_T c43_n_nargin = 0.0;
  real_T c43_n_nargout = 0.0;
  real_T c43_o_nargin = 0.0;
  real_T c43_o_nargout = 1.0;
  boolean_T c43_g_out;
  real_T c43_p_nargin = 0.0;
  real_T c43_p_nargout = 0.0;
  real_T c43_q_nargin = 0.0;
  real_T c43_q_nargout = 1.0;
  boolean_T c43_h_out;
  real_T c43_r_nargin = 0.0;
  real_T c43_r_nargout = 0.0;
  real_T c43_s_nargin = 0.0;
  real_T c43_s_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, *chartInstance->c43_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c43_q_debug_family_names,
    c43_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargin, 0U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_nargout, 1U, c43_sf_marshallOut,
    c43_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_out, 2U, c43_b_sf_marshallOut,
    c43_b_sf_marshallIn);
  guard3 = false;
  if (CV_EML_COND(0, 0, 0, CV_RELATIONAL_EVAL(5U, 0U, 0,
        *chartInstance->c43_MedullaCommand, 4.0, -1, 0U,
        *chartInstance->c43_MedullaCommand == 4.0))) {
    guard3 = true;
  } else if (CV_EML_COND(0, 0, 1, CV_RELATIONAL_EVAL(5U, 0U, 1,
               *chartInstance->c43_MedullaCommand, 5.0, -1, 0U,
               *chartInstance->c43_MedullaCommand == 5.0))) {
    guard3 = true;
  } else {
    CV_EML_MCDC(0, 0, 0, false);
    CV_EML_IF(0, 0, 0, false);
    c43_out = false;
  }

  if (guard3 == true) {
    CV_EML_MCDC(0, 0, 0, true);
    CV_EML_IF(0, 0, 0, true);
    c43_out = true;
  }

  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c43_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c43_sfEvent);
    c43_exit_internal_Initialization(chartInstance);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c43_sfEvent);
    *chartInstance->c43_is_c43_Walking01_DDA3D = c43_IN_FaultRunning;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c43_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_h_debug_family_names,
      c43_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_b_nargin, 0U, c43_sf_marshallOut,
      c43_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_b_nargout, 1U, c43_sf_marshallOut,
      c43_sf_marshallIn);
    *chartInstance->c43_ControlWordIndex = 1.0;
    c43_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
    *chartInstance->c43_EnableTargetTorque = 0.0;
    c43_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c43_EnableTargetTorque, 4U);
    *chartInstance->c43_FaultDetected = 1.0;
    c43_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c43_FaultDetected, 7U);
    _SFD_SYMBOL_SCOPE_POP();
    guard1 = true;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                 *chartInstance->c43_sfEvent);
    switch (*chartInstance->c43_is_Initialization) {
     case c43_IN_Fault:
      CV_STATE_EVAL(1, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   *chartInstance->c43_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c43_k_debug_family_names,
        c43_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_c_nargin, 0U, c43_sf_marshallOut,
        c43_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_c_nargout, 1U,
        c43_sf_marshallOut, c43_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_b_out, 2U, c43_b_sf_marshallOut,
        c43_b_sf_marshallIn);
      c43_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 83U, 1, 7);
      c43_b_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0,
        *chartInstance->c43_Timeout, 20.0, -1, 5U, *chartInstance->c43_Timeout >=
        20.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c43_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c43_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c43_sfEvent);
        *chartInstance->c43_is_Initialization = c43_IN_Fault;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c43_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_d_debug_family_names,
          c43_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_d_nargin, 0U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_d_nargout, 1U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        *chartInstance->c43_ControlWordIndex = 3.0;
        c43_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
        *chartInstance->c43_EnableTargetTorque = 0.0;
        c43_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_EnableTargetTorque, 4U);
        *chartInstance->c43_Timeout = 0.0;
        c43_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_Timeout, 5U);
        *chartInstance->c43_FaultDetected = 0.0;
        c43_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                     *chartInstance->c43_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c43_m_debug_family_names,
          c43_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_e_nargin, 0U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_e_nargout, 1U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_c_out, 2U,
          c43_b_sf_marshallOut, c43_b_sf_marshallIn);
        c43_c_out = CV_EML_IF(11, 0, 0, CV_RELATIONAL_EVAL(5U, 11U, 0, (real_T)
          *chartInstance->c43_SwitchOnDisabledMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c43_SwitchOnDisabledMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c43_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, *chartInstance->c43_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c43_sfEvent);
          *chartInstance->c43_is_Initialization = c43_IN_SwitchOnDisabled;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c43_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_b_debug_family_names,
            c43_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_f_nargin, 0U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_f_nargout, 1U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          *chartInstance->c43_ControlWordIndex = 1.0;
          c43_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
          *chartInstance->c43_Timeout = 0.0;
          c43_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_Timeout, 5U);
          *chartInstance->c43_EnableTargetTorque = 0.0;
          c43_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_EnableTargetTorque, 4U);
          *chartInstance->c43_FaultDetected = 0.0;
          c43_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_FaultDetected, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       *chartInstance->c43_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_e_debug_family_names,
            c43_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_g_nargin, 0U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_g_nargout, 1U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          c43_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 72U, 129, 7);
          (*chartInstance->c43_Timeout)++;
          c43_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_Timeout, 5U);
          *chartInstance->c43_ControlWordIndex = 0.0;
          c43_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *chartInstance->c43_sfEvent);
      guard1 = true;
      break;

     case c43_IN_ReadyToSwitchOn:
      CV_STATE_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   *chartInstance->c43_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c43_o_debug_family_names,
        c43_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_h_nargin, 0U, c43_sf_marshallOut,
        c43_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_h_nargout, 1U,
        c43_sf_marshallOut, c43_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_d_out, 2U, c43_b_sf_marshallOut,
        c43_b_sf_marshallIn);
      c43_d_out = CV_EML_IF(10, 0, 0, CV_RELATIONAL_EVAL(5U, 10U, 0, (real_T)
        *chartInstance->c43_FaultMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c43_FaultMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c43_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, *chartInstance->c43_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c43_sfEvent);
        *chartInstance->c43_is_Initialization = c43_IN_Fault;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c43_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_d_debug_family_names,
          c43_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_i_nargin, 0U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_i_nargout, 1U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        *chartInstance->c43_ControlWordIndex = 3.0;
        c43_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
        *chartInstance->c43_EnableTargetTorque = 0.0;
        c43_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_EnableTargetTorque, 4U);
        *chartInstance->c43_Timeout = 0.0;
        c43_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_Timeout, 5U);
        *chartInstance->c43_FaultDetected = 0.0;
        c43_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                     *chartInstance->c43_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c43_l_debug_family_names,
          c43_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_j_nargin, 0U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_j_nargout, 1U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_e_out, 2U,
          c43_b_sf_marshallOut, c43_b_sf_marshallIn);
        c43_e_out = CV_EML_IF(12, 0, 0, CV_RELATIONAL_EVAL(5U, 12U, 0, (real_T)
          *chartInstance->c43_SwitchOnDisabledMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c43_SwitchOnDisabledMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c43_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, *chartInstance->c43_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c43_sfEvent);
          *chartInstance->c43_is_Initialization = c43_IN_SwitchOnDisabled;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c43_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_b_debug_family_names,
            c43_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_k_nargin, 0U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_k_nargout, 1U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          *chartInstance->c43_ControlWordIndex = 1.0;
          c43_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
          *chartInstance->c43_Timeout = 0.0;
          c43_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_Timeout, 5U);
          *chartInstance->c43_EnableTargetTorque = 0.0;
          c43_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_EnableTargetTorque, 4U);
          *chartInstance->c43_FaultDetected = 0.0;
          c43_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_FaultDetected, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                       *chartInstance->c43_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c43_t_debug_family_names,
            c43_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_l_nargin, 0U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_l_nargout, 1U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_f_out, 2U,
            c43_b_sf_marshallOut, c43_b_sf_marshallIn);
          guard2 = false;
          if (CV_EML_COND(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)
                *chartInstance->c43_EnabledMode, 1.0, -1, 0U, (real_T)
                *chartInstance->c43_EnabledMode == 1.0))) {
            if (CV_EML_COND(1, 0, 1, CV_RELATIONAL_EVAL(5U, 1U, 1, (real_T)
                  *chartInstance->c43_FaultMode, 0.0, -1, 0U, (real_T)
                  *chartInstance->c43_FaultMode == 0.0))) {
              CV_EML_MCDC(1, 0, 0, true);
              CV_EML_IF(1, 0, 0, true);
              c43_f_out = true;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }

          if (guard2 == true) {
            CV_EML_MCDC(1, 0, 0, false);
            CV_EML_IF(1, 0, 0, false);
            c43_f_out = false;
          }

          _SFD_SYMBOL_SCOPE_POP();
          if (c43_f_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c43_sfEvent);
            *chartInstance->c43_is_Initialization = c43_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c43_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c43_sfEvent);
            *chartInstance->c43_is_c43_Walking01_DDA3D = c43_IN_Running;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c43_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_i_debug_family_names,
              c43_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_m_nargin, 0U,
              c43_sf_marshallOut, c43_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_m_nargout, 1U,
              c43_sf_marshallOut, c43_sf_marshallIn);
            *chartInstance->c43_FaultDetected = 0.0;
            c43_updateDataWrittenToVector(chartInstance, 3U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c43_FaultDetected, 7U);
            *chartInstance->c43_ControlWordIndex = 2.0;
            c43_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
            *chartInstance->c43_EnableTargetTorque = 1.0;
            c43_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c43_EnableTargetTorque, 4U);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                         *chartInstance->c43_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_g_debug_family_names,
              c43_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_n_nargin, 0U,
              c43_sf_marshallOut, c43_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_n_nargout, 1U,
              c43_sf_marshallOut, c43_sf_marshallIn);
            c43_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 91U, 139, 7);
            (*chartInstance->c43_Timeout)++;
            c43_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c43_Timeout, 5U);
            _SFD_SYMBOL_SCOPE_POP();
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c43_sfEvent);
      if (*chartInstance->c43_is_c43_Walking01_DDA3D != c43_IN_Initialization) {
      } else {
        guard1 = true;
      }
      break;

     case c43_IN_SwitchOnDisabled:
      CV_STATE_EVAL(1, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   *chartInstance->c43_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c43_n_debug_family_names,
        c43_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_o_nargin, 0U, c43_sf_marshallOut,
        c43_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_o_nargout, 1U,
        c43_sf_marshallOut, c43_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_g_out, 2U, c43_b_sf_marshallOut,
        c43_b_sf_marshallIn);
      c43_g_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, (real_T)
        *chartInstance->c43_ReadyToSwitchOnMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c43_ReadyToSwitchOnMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c43_g_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c43_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c43_sfEvent);
        *chartInstance->c43_is_Initialization = c43_IN_ReadyToSwitchOn;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c43_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_f_debug_family_names,
          c43_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_p_nargin, 0U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_p_nargout, 1U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        *chartInstance->c43_ControlWordIndex = 2.0;
        c43_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
        *chartInstance->c43_Timeout = 0.0;
        c43_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_Timeout, 5U);
        *chartInstance->c43_EnableTargetTorque = 0.0;
        c43_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_EnableTargetTorque, 4U);
        *chartInstance->c43_FaultDetected = 0.0;
        c43_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c43_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                     *chartInstance->c43_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c43_j_debug_family_names,
          c43_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_q_nargin, 0U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_q_nargout, 1U,
          c43_sf_marshallOut, c43_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_h_out, 2U,
          c43_b_sf_marshallOut, c43_b_sf_marshallIn);
        c43_h_out = CV_EML_IF(7, 0, 0, CV_RELATIONAL_EVAL(5U, 7U, 0, (real_T)
          *chartInstance->c43_FaultMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c43_FaultMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c43_h_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, *chartInstance->c43_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c43_sfEvent);
          *chartInstance->c43_is_Initialization = c43_IN_Fault;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c43_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_d_debug_family_names,
            c43_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_r_nargin, 0U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_r_nargout, 1U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          *chartInstance->c43_ControlWordIndex = 3.0;
          c43_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_ControlWordIndex, 3U);
          *chartInstance->c43_EnableTargetTorque = 0.0;
          c43_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_EnableTargetTorque, 4U);
          *chartInstance->c43_Timeout = 0.0;
          c43_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_Timeout, 5U);
          *chartInstance->c43_FaultDetected = 0.0;
          c43_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_FaultDetected, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                       *chartInstance->c43_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c43_c_debug_family_names,
            c43_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_s_nargin, 0U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c43_s_nargout, 1U,
            c43_sf_marshallOut, c43_sf_marshallIn);
          c43_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 73U, 140, 7);
          (*chartInstance->c43_Timeout)++;
          c43_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c43_Timeout, 5U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *chartInstance->c43_sfEvent);
      guard1 = true;
      break;

     default:
      CV_STATE_EVAL(1, 0, 0);
      *chartInstance->c43_is_Initialization = c43_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c43_sfEvent);
      guard1 = true;
      break;
    }
  }

  if (guard1 == true) {
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c43_sfEvent);
  }
}

static void c43_exit_internal_Initialization(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  switch (*chartInstance->c43_is_Initialization) {
   case c43_IN_Fault:
    CV_STATE_EVAL(1, 1, 1);
    *chartInstance->c43_is_Initialization = c43_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c43_sfEvent);
    break;

   case c43_IN_ReadyToSwitchOn:
    CV_STATE_EVAL(1, 1, 2);
    *chartInstance->c43_is_Initialization = c43_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c43_sfEvent);
    break;

   case c43_IN_SwitchOnDisabled:
    CV_STATE_EVAL(1, 1, 3);
    *chartInstance->c43_is_Initialization = c43_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c43_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    *chartInstance->c43_is_Initialization = c43_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c43_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c43_machineNumber, uint32_T
  c43_chartNumber, uint32_T c43_instanceNumber)
{
  (void)c43_machineNumber;
  (void)c43_chartNumber;
  (void)c43_instanceNumber;
}

static const mxArray *c43_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  real_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc43_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(real_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static real_T c43_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_nargout, const char_T *c43_identifier)
{
  real_T c43_y;
  emlrtMsgIdentifier c43_thisId;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_nargout),
    &c43_thisId);
  sf_mex_destroy(&c43_nargout);
  return c43_y;
}

static real_T c43_b_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  real_T c43_y;
  real_T c43_d0;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_d0, 1, 0, 0U, 0, 0U, 0);
  c43_y = c43_d0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_nargout;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  real_T c43_y;
  SFc43_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc43_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c43_nargout = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_nargout),
    &c43_thisId);
  sf_mex_destroy(&c43_nargout);
  *(real_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

static const mxArray *c43_b_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  boolean_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc43_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(boolean_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static boolean_T c43_c_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  boolean_T c43_y;
  boolean_T c43_b0;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_b0, 1, 11, 0U, 0, 0U, 0);
  c43_y = c43_b0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_sf_internal_predicateOutput;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  boolean_T c43_y;
  SFc43_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc43_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c43_sf_internal_predicateOutput = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c43_sf_internal_predicateOutput), &c43_thisId);
  sf_mex_destroy(&c43_sf_internal_predicateOutput);
  *(boolean_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

const mxArray *sf_c43_Walking01_DDA3D_get_eml_resolved_functions_info(void)
{
  const mxArray *c43_nameCaptureInfo = NULL;
  c43_nameCaptureInfo = NULL;
  sf_mex_assign(&c43_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c43_nameCaptureInfo;
}

static const mxArray *c43_c_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  int32_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc43_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(int32_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static int32_T c43_d_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  int32_T c43_y;
  int32_T c43_i2;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_i2, 1, 6, 0U, 0, 0U, 0);
  c43_y = c43_i2;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_b_sfEvent;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  int32_T c43_y;
  SFc43_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc43_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c43_b_sfEvent = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_b_sfEvent),
    &c43_thisId);
  sf_mex_destroy(&c43_b_sfEvent);
  *(int32_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

static const mxArray *c43_d_sf_marshallOut(void *chartInstanceVoid, void
  *c43_inData)
{
  const mxArray *c43_mxArrayOutData = NULL;
  uint8_T c43_u;
  const mxArray *c43_y = NULL;
  SFc43_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc43_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c43_mxArrayOutData = NULL;
  c43_u = *(uint8_T *)c43_inData;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_create("y", &c43_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c43_mxArrayOutData, c43_y, false);
  return c43_mxArrayOutData;
}

static uint8_T c43_e_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_b_is_Initialization, const char_T
  *c43_identifier)
{
  uint8_T c43_y;
  emlrtMsgIdentifier c43_thisId;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c43_b_is_Initialization), &c43_thisId);
  sf_mex_destroy(&c43_b_is_Initialization);
  return c43_y;
}

static uint8_T c43_f_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  uint8_T c43_y;
  uint8_T c43_u0;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), &c43_u0, 1, 3, 0U, 0, 0U, 0);
  c43_y = c43_u0;
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c43_mxArrayInData, const char_T *c43_varName, void *c43_outData)
{
  const mxArray *c43_b_is_Initialization;
  const char_T *c43_identifier;
  emlrtMsgIdentifier c43_thisId;
  uint8_T c43_y;
  SFc43_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc43_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c43_b_is_Initialization = sf_mex_dup(c43_mxArrayInData);
  c43_identifier = c43_varName;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_y = c43_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c43_b_is_Initialization), &c43_thisId);
  sf_mex_destroy(&c43_b_is_Initialization);
  *(uint8_T *)c43_outData = c43_y;
  sf_mex_destroy(&c43_mxArrayInData);
}

static void c43_g_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_b_dataWrittenToVector, const char_T
  *c43_identifier, boolean_T c43_y[4])
{
  emlrtMsgIdentifier c43_thisId;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  c43_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c43_b_dataWrittenToVector),
    &c43_thisId, c43_y);
  sf_mex_destroy(&c43_b_dataWrittenToVector);
}

static void c43_h_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId,
  boolean_T c43_y[4])
{
  boolean_T c43_bv1[4];
  int32_T c43_i3;
  (void)chartInstance;
  sf_mex_import(c43_parentId, sf_mex_dup(c43_u), c43_bv1, 1, 11, 0U, 1, 0U, 1, 4);
  for (c43_i3 = 0; c43_i3 < 4; c43_i3++) {
    c43_y[c43_i3] = c43_bv1[c43_i3];
  }

  sf_mex_destroy(&c43_u);
}

static const mxArray *c43_i_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_b_setSimStateSideEffectsInfo, const char_T *
  c43_identifier)
{
  const mxArray *c43_y = NULL;
  emlrtMsgIdentifier c43_thisId;
  c43_y = NULL;
  c43_thisId.fIdentifier = c43_identifier;
  c43_thisId.fParent = NULL;
  sf_mex_assign(&c43_y, c43_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c43_b_setSimStateSideEffectsInfo), &c43_thisId), false);
  sf_mex_destroy(&c43_b_setSimStateSideEffectsInfo);
  return c43_y;
}

static const mxArray *c43_j_emlrt_marshallIn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c43_u, const emlrtMsgIdentifier *c43_parentId)
{
  const mxArray *c43_y = NULL;
  (void)chartInstance;
  (void)c43_parentId;
  c43_y = NULL;
  sf_mex_assign(&c43_y, sf_mex_duplicatearraysafe(&c43_u), false);
  sf_mex_destroy(&c43_u);
  return c43_y;
}

static void c43_updateDataWrittenToVector(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, uint32_T c43_vectorIndex)
{
  chartInstance->c43_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK
    (0U, (int32_T)c43_vectorIndex, 0, 3, 1, 0)] = true;
}

static void c43_errorIfDataNotWrittenToFcn(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance, uint32_T c43_vectorIndex, uint32_T c43_dataNumber, uint32_T
  c43_ssIdOfSourceObject, int32_T c43_offsetInSourceObject, int32_T
  c43_lengthInSourceObject)
{
  (void)c43_ssIdOfSourceObject;
  (void)c43_offsetInSourceObject;
  (void)c43_lengthInSourceObject;
  if (!chartInstance->c43_dataWrittenToVector[(uint32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK(0U, (int32_T)c43_vectorIndex, 0, 3, 1, 0)]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(c43_dataNumber);
  }
}

static void init_dsm_address_info(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc43_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c43_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c43_isStable = (boolean_T *)ssGetDWork_wrapper(chartInstance->S,
    1);
  chartInstance->c43_is_active_c43_Walking01_DDA3D = (uint8_T *)
    ssGetDWork_wrapper(chartInstance->S, 2);
  chartInstance->c43_is_c43_Walking01_DDA3D = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 3);
  chartInstance->c43_is_Initialization = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 4);
  chartInstance->c43_SwitchOnDisabledMode = (boolean_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c43_EnabledMode = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c43_ReadyToSwitchOnMode = (boolean_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c43_ControlWordIndex = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c43_EnableTargetTorque = (real_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c43_Timeout = (real_T *)ssGetDWork_wrapper(chartInstance->S, 5);
  chartInstance->c43_FaultMode = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c43_FaultDetected = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c43_MedullaCommand = (real_T *)ssGetInputPortSignal_wrapper
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

static uint32_T* sf_get_sfun_dwork_checksum(void);
void sf_c43_Walking01_DDA3D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3667290850U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2463151160U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2196709224U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4141291169U);
}

mxArray* sf_c43_Walking01_DDA3D_get_post_codegen_info(void);
mxArray *sf_c43_Walking01_DDA3D_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("TxaujBQiZR71hjzOPc7piE");
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
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
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxData);
  }

  {
    mxArray* mxPostCodegenInfo = sf_c43_Walking01_DDA3D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c43_Walking01_DDA3D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c43_Walking01_DDA3D_jit_fallback_info(void)
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

mxArray *sf_c43_Walking01_DDA3D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c43_Walking01_DDA3D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c43_Walking01_DDA3D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[23],T\"ControlWordIndex\",},{M[1],M[24],T\"EnableTargetTorque\",},{M[1],M[64],T\"FaultDetected\",},{M[3],M[25],T\"Timeout\",},{M[8],M[0],T\"is_active_c43_Walking01_DDA3D\",},{M[9],M[0],T\"is_c43_Walking01_DDA3D\",},{M[9],M[87],T\"is_Initialization\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c43_Walking01_DDA3D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc43_Walking01_DDA3DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc43_Walking01_DDA3DInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_DDA3DMachineNumber_,
           43,
           7,
           13,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"SwitchOnDisabledMode");
          _SFD_SET_DATA_PROPS(1,1,1,0,"EnabledMode");
          _SFD_SET_DATA_PROPS(2,1,1,0,"ReadyToSwitchOnMode");
          _SFD_SET_DATA_PROPS(3,2,0,1,"ControlWordIndex");
          _SFD_SET_DATA_PROPS(4,2,0,1,"EnableTargetTorque");
          _SFD_SET_DATA_PROPS(5,0,0,0,"Timeout");
          _SFD_SET_DATA_PROPS(6,1,1,0,"FaultMode");
          _SFD_SET_DATA_PROPS(7,2,0,1,"FaultDetected");
          _SFD_SET_DATA_PROPS(8,1,1,0,"MedullaCommand");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,0);
          _SFD_STATE_INFO(6,0,0);
          _SFD_CH_SUBSTATE_COUNT(4);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_CH_SUBSTATE_INDEX(2,5);
          _SFD_CH_SUBSTATE_INDEX(3,6);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,3);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_INDEX(1,2,4);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
          _SFD_ST_SUBSTATE_COUNT(5,0);
          _SFD_ST_SUBSTATE_COUNT(6,0);
        }

        _SFD_CV_INIT_CHART(4,1,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(1,3,1,1,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(2,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(3,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(4,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(5,0,0,0,0,0,NULL,NULL);
        }

        {
          _SFD_CV_INIT_STATE(6,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,15,1,15);
        _SFD_CV_INIT_EML_RELATIONAL(7,0,0,1,15,-1,0);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,13,1,13);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,13,-1,5);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(12,0,0,1,26,1,26);
        _SFD_CV_INIT_EML_RELATIONAL(12,0,0,1,26,-1,0);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,26,1,26);
        _SFD_CV_INIT_EML_RELATIONAL(11,0,0,1,26,-1,0);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,25,1,25);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,1,25,-1,0);
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,15,1,15);
        _SFD_CV_INIT_EML_RELATIONAL(10,0,0,1,15,-1,0);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,20,1,20);
        _SFD_CV_INIT_EML_RELATIONAL(6,0,0,1,20,-1,0);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(0,0,0,1,43,1,43);

        {
          static int condStart[] = { 1, 24 };

          static int condEnd[] = { 20, 43 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(0,0,0,1,43,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(0,0,0,1,20,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(0,0,1,24,43,-1,0);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,15,1,15);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,15,-1,0);
        _SFD_CV_INIT_EML(9,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(9,0,0,1,43,1,43);

        {
          static int condStart[] = { 1, 24 };

          static int condEnd[] = { 20, 43 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(9,0,0,1,43,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(9,0,0,1,20,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(9,0,1,24,43,-1,0);
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(1,0,0,1,35,1,35);

        {
          static int condStart[] = { 1, 21 };

          static int condEnd[] = { 17, 35 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(1,0,0,1,35,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,17,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,1,21,35,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)c43_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c43_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c43_SwitchOnDisabledMode);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c43_EnabledMode);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c43_ReadyToSwitchOnMode);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c43_ControlWordIndex);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c43_EnableTargetTorque);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c43_Timeout);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c43_FaultMode);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c43_FaultDetected);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c43_MedullaCommand);
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
  return "1i1enK4EbLDBOMyEiLozV";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 43, "dworkChecksum");
    if (mxRTWDWorkChecksum != NULL) {
      double *pr = mxGetPr(mxRTWDWorkChecksum);
      if ((uint32_T)pr[0] != sfunDWorkChecksum[0] ||
          (uint32_T)pr[1] != sfunDWorkChecksum[1] ||
          (uint32_T)pr[2] != sfunDWorkChecksum[2] ||
          (uint32_T)pr[3] != sfunDWorkChecksum[3]) {
        sf_mex_error_message("Code generation and simulation targets registered different sets of persistent variables for the block. "
                             "External or Rapid Accelerator mode simulation requires code generation and simulation targets to "
                             "register the same set of persistent variables for this block. "
                             "This discrepancy is typically caused by MATLAB functions that have different code paths for "
                             "simulation and code generation targets where these code paths define different sets of persistent variables. "
                             "Please identify these code paths in the offending block and rewrite the MATLAB code so that "
                             "the set of persistent variables is the same between simulation and code generation.");
      }
    }
  }
}

static void sf_opaque_initialize_c43_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc43_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc43_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c43_Walking01_DDA3D((SFc43_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
  initialize_c43_Walking01_DDA3D((SFc43_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c43_Walking01_DDA3D(void *chartInstanceVar)
{
  enable_c43_Walking01_DDA3D((SFc43_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c43_Walking01_DDA3D(void *chartInstanceVar)
{
  disable_c43_Walking01_DDA3D((SFc43_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c43_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_gateway_c43_Walking01_DDA3D((SFc43_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c43_Walking01_DDA3D(void *chartInstanceVar)
{
  ext_mode_exec_c43_Walking01_DDA3D((SFc43_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c43_Walking01_DDA3D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c43_Walking01_DDA3D((SFc43_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c43_Walking01_DDA3D(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c43_Walking01_DDA3D((SFc43_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c43_Walking01_DDA3D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc43_Walking01_DDA3DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_DDA3D_optimization_info();
    }

    finalize_c43_Walking01_DDA3D((SFc43_Walking01_DDA3DInstanceStruct*)
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
  initSimStructsc43_Walking01_DDA3D((SFc43_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c43_Walking01_DDA3D(SimStruct *S)
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
    initialize_params_c43_Walking01_DDA3D((SFc43_Walking01_DDA3DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

mxArray *sf_c43_Walking01_DDA3D_get_testpoint_info(void)
{
  return NULL;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x6'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size'{{T\"int32\",,,,,,,M[0],M[]},{T\"boolean\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"double\",,,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 6, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 681835801U, 929203061U, 1272024938U,
    1618980159U };

  return checksum;
}

static void mdlSetWorkWidths_c43_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      43);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,43,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,43,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,43);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,43,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,43,3);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=3; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 5; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,43);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3560221409U));
  ssSetChecksum1(S,(8411193U));
  ssSetChecksum2(S,(1830021795U));
  ssSetChecksum3(S,(2914740637U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c43_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c43_Walking01_DDA3D(SimStruct *S)
{
  SFc43_Walking01_DDA3DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc43_Walking01_DDA3DInstanceStruct *)utMalloc(sizeof
    (SFc43_Walking01_DDA3DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc43_Walking01_DDA3DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c43_Walking01_DDA3D;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c43_Walking01_DDA3D;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c43_Walking01_DDA3D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c43_Walking01_DDA3D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c43_Walking01_DDA3D;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c43_Walking01_DDA3D;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c43_Walking01_DDA3D;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c43_Walking01_DDA3D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c43_Walking01_DDA3D;
  chartInstance->chartInfo.mdlStart = mdlStart_c43_Walking01_DDA3D;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c43_Walking01_DDA3D;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c43_Walking01_DDA3D;
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

void c43_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c43_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c43_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c43_Walking01_DDA3D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c43_Walking01_DDA3D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}