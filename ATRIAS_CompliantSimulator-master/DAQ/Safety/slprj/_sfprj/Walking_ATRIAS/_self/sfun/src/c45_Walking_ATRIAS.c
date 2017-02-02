/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking_ATRIAS_sfun.h"
#include "c45_Walking_ATRIAS.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Walking_ATRIAS_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c45_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c45_IN_FaultRunning            ((uint8_T)1U)
#define c45_IN_Initialization          ((uint8_T)2U)
#define c45_IN_Running                 ((uint8_T)3U)
#define c45_IN_Start1                  ((uint8_T)4U)
#define c45_IN_Fault                   ((uint8_T)1U)
#define c45_IN_ReadyToSwitchOn         ((uint8_T)2U)
#define c45_IN_SwitchOnDisabled        ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c45_debug_family_names[2] = { "nargin", "nargout" };

static const char * c45_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c45_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c45_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c45_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c45_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c45_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c45_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c45_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c45_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_gb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c45_hb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance);
static void initialize_params_c45_Walking_ATRIAS
  (SFc45_Walking_ATRIASInstanceStruct *chartInstance);
static void enable_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance);
static void disable_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance);
static void c45_update_debugger_state_c45_Walking_ATRIAS
  (SFc45_Walking_ATRIASInstanceStruct *chartInstance);
static void ext_mode_exec_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c45_Walking_ATRIAS
  (SFc45_Walking_ATRIASInstanceStruct *chartInstance);
static void set_sim_state_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c45_st);
static void c45_set_sim_state_side_effects_c45_Walking_ATRIAS
  (SFc45_Walking_ATRIASInstanceStruct *chartInstance);
static void finalize_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance);
static void sf_gateway_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance);
static void mdl_start_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance);
static void c45_chartstep_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance);
static void initSimStructsc45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance);
static void c45_Initialization(SFc45_Walking_ATRIASInstanceStruct *chartInstance);
static void c45_exit_internal_Initialization(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance);
static void init_script_number_translation(uint32_T c45_machineNumber, uint32_T
  c45_chartNumber, uint32_T c45_instanceNumber);
static const mxArray *c45_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static real_T c45_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_nargout, const char_T *c45_identifier);
static real_T c45_b_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static const mxArray *c45_b_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static boolean_T c45_c_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static const mxArray *c45_c_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static int32_T c45_d_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static const mxArray *c45_d_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData);
static uint8_T c45_e_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_b_is_Initialization, const char_T
  *c45_identifier);
static uint8_T c45_f_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData);
static void c45_g_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_b_dataWrittenToVector, const char_T
  *c45_identifier, boolean_T c45_y[4]);
static void c45_h_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId,
  boolean_T c45_y[4]);
static const mxArray *c45_i_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c45_b_setSimStateSideEffectsInfo, const char_T
  *c45_identifier);
static const mxArray *c45_j_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId);
static void c45_updateDataWrittenToVector(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, uint32_T c45_vectorIndex);
static void c45_errorIfDataNotWrittenToFcn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, uint32_T c45_vectorIndex, uint32_T c45_dataNumber, uint32_T
  c45_ssIdOfSourceObject, int32_T c45_offsetInSourceObject, int32_T
  c45_lengthInSourceObject);
static void init_dsm_address_info(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  *chartInstance->c45_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c45_doSetSimStateSideEffects = 0U;
  chartInstance->c45_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c45_is_Initialization = c45_IN_NO_ACTIVE_CHILD;
  *chartInstance->c45_is_active_c45_Walking_ATRIAS = 0U;
  *chartInstance->c45_is_c45_Walking_ATRIAS = c45_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c45_Walking_ATRIAS
  (SFc45_Walking_ATRIASInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c45_update_debugger_state_c45_Walking_ATRIAS
  (SFc45_Walking_ATRIASInstanceStruct *chartInstance)
{
  uint32_T c45_prevAniVal;
  c45_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c45_is_active_c45_Walking_ATRIAS == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 11U, *chartInstance->c45_sfEvent);
  }

  if (*chartInstance->c45_is_c45_Walking_ATRIAS == c45_IN_Start1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c45_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c45_sfEvent);
  }

  if (*chartInstance->c45_is_c45_Walking_ATRIAS == c45_IN_Initialization) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c45_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c45_sfEvent);
  }

  if (*chartInstance->c45_is_Initialization == c45_IN_SwitchOnDisabled) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c45_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c45_sfEvent);
  }

  if (*chartInstance->c45_is_Initialization == c45_IN_Fault) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c45_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c45_sfEvent);
  }

  if (*chartInstance->c45_is_Initialization == c45_IN_ReadyToSwitchOn) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c45_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c45_sfEvent);
  }

  if (*chartInstance->c45_is_c45_Walking_ATRIAS == c45_IN_FaultRunning) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c45_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c45_sfEvent);
  }

  if (*chartInstance->c45_is_c45_Walking_ATRIAS == c45_IN_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c45_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c45_sfEvent);
  }

  _SFD_SET_ANIMATION(c45_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance)
{
  c45_update_debugger_state_c45_Walking_ATRIAS(chartInstance);
}

static const mxArray *get_sim_state_c45_Walking_ATRIAS
  (SFc45_Walking_ATRIASInstanceStruct *chartInstance)
{
  const mxArray *c45_st;
  const mxArray *c45_y = NULL;
  real_T c45_hoistedGlobal;
  real_T c45_u;
  const mxArray *c45_b_y = NULL;
  real_T c45_b_hoistedGlobal;
  real_T c45_b_u;
  const mxArray *c45_c_y = NULL;
  real_T c45_c_hoistedGlobal;
  real_T c45_c_u;
  const mxArray *c45_d_y = NULL;
  real_T c45_d_hoistedGlobal;
  real_T c45_d_u;
  const mxArray *c45_e_y = NULL;
  uint8_T c45_e_hoistedGlobal;
  uint8_T c45_e_u;
  const mxArray *c45_f_y = NULL;
  uint8_T c45_f_hoistedGlobal;
  uint8_T c45_f_u;
  const mxArray *c45_g_y = NULL;
  uint8_T c45_g_hoistedGlobal;
  uint8_T c45_g_u;
  const mxArray *c45_h_y = NULL;
  int32_T c45_i0;
  boolean_T c45_h_u[4];
  const mxArray *c45_i_y = NULL;
  c45_st = NULL;
  c45_st = NULL;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_createcellmatrix(8, 1), false);
  c45_hoistedGlobal = *chartInstance->c45_ControlWordIndex;
  c45_u = c45_hoistedGlobal;
  c45_b_y = NULL;
  sf_mex_assign(&c45_b_y, sf_mex_create("y", &c45_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c45_y, 0, c45_b_y);
  c45_b_hoistedGlobal = *chartInstance->c45_EnableTargetTorque;
  c45_b_u = c45_b_hoistedGlobal;
  c45_c_y = NULL;
  sf_mex_assign(&c45_c_y, sf_mex_create("y", &c45_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c45_y, 1, c45_c_y);
  c45_c_hoistedGlobal = *chartInstance->c45_FaultDetected;
  c45_c_u = c45_c_hoistedGlobal;
  c45_d_y = NULL;
  sf_mex_assign(&c45_d_y, sf_mex_create("y", &c45_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c45_y, 2, c45_d_y);
  c45_d_hoistedGlobal = *chartInstance->c45_Timeout;
  c45_d_u = c45_d_hoistedGlobal;
  c45_e_y = NULL;
  sf_mex_assign(&c45_e_y, sf_mex_create("y", &c45_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c45_y, 3, c45_e_y);
  c45_e_hoistedGlobal = *chartInstance->c45_is_active_c45_Walking_ATRIAS;
  c45_e_u = c45_e_hoistedGlobal;
  c45_f_y = NULL;
  sf_mex_assign(&c45_f_y, sf_mex_create("y", &c45_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c45_y, 4, c45_f_y);
  c45_f_hoistedGlobal = *chartInstance->c45_is_c45_Walking_ATRIAS;
  c45_f_u = c45_f_hoistedGlobal;
  c45_g_y = NULL;
  sf_mex_assign(&c45_g_y, sf_mex_create("y", &c45_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c45_y, 5, c45_g_y);
  c45_g_hoistedGlobal = *chartInstance->c45_is_Initialization;
  c45_g_u = c45_g_hoistedGlobal;
  c45_h_y = NULL;
  sf_mex_assign(&c45_h_y, sf_mex_create("y", &c45_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c45_y, 6, c45_h_y);
  for (c45_i0 = 0; c45_i0 < 4; c45_i0++) {
    c45_h_u[c45_i0] = chartInstance->c45_dataWrittenToVector[c45_i0];
  }

  c45_i_y = NULL;
  sf_mex_assign(&c45_i_y, sf_mex_create("y", c45_h_u, 11, 0U, 1U, 0U, 1, 4),
                false);
  sf_mex_setcell(c45_y, 7, c45_i_y);
  sf_mex_assign(&c45_st, c45_y, false);
  return c45_st;
}

static void set_sim_state_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c45_st)
{
  const mxArray *c45_u;
  boolean_T c45_bv0[4];
  int32_T c45_i1;
  c45_u = sf_mex_dup(c45_st);
  *chartInstance->c45_ControlWordIndex = c45_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c45_u, 0)), "ControlWordIndex");
  *chartInstance->c45_EnableTargetTorque = c45_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c45_u, 1)), "EnableTargetTorque");
  *chartInstance->c45_FaultDetected = c45_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c45_u, 2)), "FaultDetected");
  *chartInstance->c45_Timeout = c45_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c45_u, 3)), "Timeout");
  *chartInstance->c45_is_active_c45_Walking_ATRIAS = c45_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c45_u, 4)),
     "is_active_c45_Walking_ATRIAS");
  *chartInstance->c45_is_c45_Walking_ATRIAS = c45_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c45_u, 5)),
     "is_c45_Walking_ATRIAS");
  *chartInstance->c45_is_Initialization = c45_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c45_u, 6)), "is_Initialization");
  c45_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c45_u, 7)),
    "dataWrittenToVector", c45_bv0);
  for (c45_i1 = 0; c45_i1 < 4; c45_i1++) {
    chartInstance->c45_dataWrittenToVector[c45_i1] = c45_bv0[c45_i1];
  }

  sf_mex_assign(&chartInstance->c45_setSimStateSideEffectsInfo,
                c45_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c45_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c45_u);
  chartInstance->c45_doSetSimStateSideEffects = 1U;
  c45_update_debugger_state_c45_Walking_ATRIAS(chartInstance);
  sf_mex_destroy(&c45_st);
}

static void c45_set_sim_state_side_effects_c45_Walking_ATRIAS
  (SFc45_Walking_ATRIASInstanceStruct *chartInstance)
{
  if (chartInstance->c45_doSetSimStateSideEffects != 0) {
    chartInstance->c45_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c45_setSimStateSideEffectsInfo);
}

static void sf_gateway_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  c45_set_sim_state_side_effects_c45_Walking_ATRIAS(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 11U, *chartInstance->c45_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c45_SwitchOnDisabledMode, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c45_EnabledMode, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c45_ReadyToSwitchOnMode, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c45_Timeout, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c45_FaultMode, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c45_MedullaCommand, 8U);
  *chartInstance->c45_sfEvent = CALL_EVENT;
  c45_chartstep_c45_Walking_ATRIAS(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking_ATRIASMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void c45_chartstep_c45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance)
{
  uint32_T c45_debug_family_var_map[2];
  real_T c45_nargin = 0.0;
  real_T c45_nargout = 0.0;
  uint32_T c45_b_debug_family_var_map[3];
  real_T c45_b_nargin = 0.0;
  real_T c45_b_nargout = 1.0;
  boolean_T c45_out;
  real_T c45_c_nargin = 0.0;
  real_T c45_c_nargout = 0.0;
  real_T c45_d_nargin = 0.0;
  real_T c45_d_nargout = 1.0;
  boolean_T c45_b_out;
  real_T c45_e_nargin = 0.0;
  real_T c45_e_nargout = 0.0;
  real_T c45_f_nargin = 0.0;
  real_T c45_f_nargout = 1.0;
  boolean_T c45_c_out;
  real_T c45_g_nargin = 0.0;
  real_T c45_g_nargout = 0.0;
  real_T c45_h_nargin = 0.0;
  real_T c45_h_nargout = 1.0;
  boolean_T c45_d_out;
  real_T c45_i_nargin = 0.0;
  real_T c45_i_nargout = 0.0;
  boolean_T guard1 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 11U, *chartInstance->c45_sfEvent);
  if (*chartInstance->c45_is_active_c45_Walking_ATRIAS == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 11U,
                 *chartInstance->c45_sfEvent);
    *chartInstance->c45_is_active_c45_Walking_ATRIAS = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, *chartInstance->c45_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, *chartInstance->c45_sfEvent);
    *chartInstance->c45_is_c45_Walking_ATRIAS = c45_IN_Start1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c45_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_debug_family_names,
      c45_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_nargin, 0U, c45_sf_marshallOut,
      c45_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_nargout, 1U, c45_sf_marshallOut,
      c45_sf_marshallIn);
    *chartInstance->c45_ControlWordIndex = 0.0;
    c45_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
    *chartInstance->c45_EnableTargetTorque = 0.0;
    c45_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
    *chartInstance->c45_FaultDetected = 0.0;
    c45_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (*chartInstance->c45_is_c45_Walking_ATRIAS) {
     case c45_IN_FaultRunning:
      CV_CHART_EVAL(11, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                   *chartInstance->c45_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c45_q_debug_family_names,
        c45_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_b_nargin, 0U, c45_sf_marshallOut,
        c45_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_b_nargout, 1U,
        c45_sf_marshallOut, c45_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_out, 2U, c45_b_sf_marshallOut,
        c45_b_sf_marshallIn);
      c45_out = CV_EML_IF(13, 0, 0, CV_RELATIONAL_EVAL(5U, 13U, 0,
        *chartInstance->c45_MedullaCommand, 6.0, -1, 0U,
        *chartInstance->c45_MedullaCommand == 6.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c45_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, *chartInstance->c45_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c45_sfEvent);
        *chartInstance->c45_is_c45_Walking_ATRIAS = c45_IN_Start1;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c45_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_debug_family_names,
          c45_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_c_nargin, 0U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_c_nargout, 1U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        *chartInstance->c45_ControlWordIndex = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
        *chartInstance->c45_EnableTargetTorque = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
        *chartInstance->c45_FaultDetected = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     *chartInstance->c45_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c45_sfEvent);
      break;

     case c45_IN_Initialization:
      CV_CHART_EVAL(11, 0, 2);
      c45_Initialization(chartInstance);
      break;

     case c45_IN_Running:
      CV_CHART_EVAL(11, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   *chartInstance->c45_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c45_s_debug_family_names,
        c45_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_d_nargin, 0U, c45_sf_marshallOut,
        c45_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_d_nargout, 1U,
        c45_sf_marshallOut, c45_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_b_out, 2U, c45_b_sf_marshallOut,
        c45_b_sf_marshallIn);
      c45_b_out = CV_EML_IF(1, 0, 0, CV_RELATIONAL_EVAL(5U, 1U, 0, (real_T)
        *chartInstance->c45_FaultMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c45_FaultMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c45_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c45_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c45_sfEvent);
        *chartInstance->c45_is_c45_Walking_ATRIAS = c45_IN_FaultRunning;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c45_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_h_debug_family_names,
          c45_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_e_nargin, 0U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_e_nargout, 1U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        *chartInstance->c45_ControlWordIndex = 1.0;
        c45_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
        *chartInstance->c45_EnableTargetTorque = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
        *chartInstance->c45_FaultDetected = 1.0;
        c45_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                     *chartInstance->c45_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c45_t_debug_family_names,
          c45_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_f_nargin, 0U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_f_nargout, 1U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_c_out, 2U,
          c45_b_sf_marshallOut, c45_b_sf_marshallIn);
        guard1 = false;
        if (CV_EML_COND(12, 0, 0, CV_RELATIONAL_EVAL(5U, 12U, 0,
              *chartInstance->c45_MedullaCommand, 4.0, -1, 0U,
              *chartInstance->c45_MedullaCommand == 4.0))) {
          guard1 = true;
        } else if (CV_EML_COND(12, 0, 1, CV_RELATIONAL_EVAL(5U, 12U, 1,
                     *chartInstance->c45_MedullaCommand, 5.0, -1, 0U,
                     *chartInstance->c45_MedullaCommand == 5.0))) {
          guard1 = true;
        } else {
          CV_EML_MCDC(12, 0, 0, false);
          CV_EML_IF(12, 0, 0, false);
          c45_c_out = false;
        }

        if (guard1 == true) {
          CV_EML_MCDC(12, 0, 0, true);
          CV_EML_IF(12, 0, 0, true);
          c45_c_out = true;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c45_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, *chartInstance->c45_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c45_sfEvent);
          *chartInstance->c45_is_c45_Walking_ATRIAS = c45_IN_FaultRunning;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c45_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_h_debug_family_names,
            c45_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_g_nargin, 0U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_g_nargout, 1U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          *chartInstance->c45_ControlWordIndex = 1.0;
          c45_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
          *chartInstance->c45_EnableTargetTorque = 0.0;
          c45_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
          *chartInstance->c45_FaultDetected = 1.0;
          c45_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                       *chartInstance->c45_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c45_sfEvent);
      break;

     case c45_IN_Start1:
      CV_CHART_EVAL(11, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   *chartInstance->c45_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c45_p_debug_family_names,
        c45_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_h_nargin, 0U, c45_sf_marshallOut,
        c45_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_h_nargout, 1U,
        c45_sf_marshallOut, c45_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_d_out, 2U, c45_b_sf_marshallOut,
        c45_b_sf_marshallIn);
      c45_d_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0,
        *chartInstance->c45_MedullaCommand, 2.0, -1, 0U,
        *chartInstance->c45_MedullaCommand == 2.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c45_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c45_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c45_sfEvent);
        *chartInstance->c45_is_c45_Walking_ATRIAS = c45_IN_Initialization;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c45_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, *chartInstance->c45_sfEvent);
        *chartInstance->c45_is_Initialization = c45_IN_SwitchOnDisabled;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c45_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_b_debug_family_names,
          c45_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_i_nargin, 0U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_i_nargout, 1U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        *chartInstance->c45_ControlWordIndex = 1.0;
        c45_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
        *chartInstance->c45_Timeout = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_Timeout, 5U);
        *chartInstance->c45_EnableTargetTorque = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
        *chartInstance->c45_FaultDetected = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                     *chartInstance->c45_sfEvent);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c45_sfEvent);
      break;

     default:
      CV_CHART_EVAL(11, 0, 0);
      *chartInstance->c45_is_c45_Walking_ATRIAS = c45_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c45_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 11U, *chartInstance->c45_sfEvent);
}

static void initSimStructsc45_Walking_ATRIAS(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c45_Initialization(SFc45_Walking_ATRIASInstanceStruct *chartInstance)
{
  uint32_T c45_debug_family_var_map[3];
  real_T c45_nargin = 0.0;
  real_T c45_nargout = 1.0;
  boolean_T c45_out;
  uint32_T c45_b_debug_family_var_map[2];
  real_T c45_b_nargin = 0.0;
  real_T c45_b_nargout = 0.0;
  real_T c45_c_nargin = 0.0;
  real_T c45_c_nargout = 1.0;
  boolean_T c45_b_out;
  real_T c45_d_nargin = 0.0;
  real_T c45_d_nargout = 0.0;
  real_T c45_e_nargin = 0.0;
  real_T c45_e_nargout = 1.0;
  boolean_T c45_c_out;
  real_T c45_f_nargin = 0.0;
  real_T c45_f_nargout = 0.0;
  real_T c45_g_nargin = 0.0;
  real_T c45_g_nargout = 0.0;
  real_T c45_h_nargin = 0.0;
  real_T c45_h_nargout = 1.0;
  boolean_T c45_d_out;
  real_T c45_i_nargin = 0.0;
  real_T c45_i_nargout = 0.0;
  real_T c45_j_nargin = 0.0;
  real_T c45_j_nargout = 1.0;
  boolean_T c45_e_out;
  real_T c45_k_nargin = 0.0;
  real_T c45_k_nargout = 0.0;
  real_T c45_l_nargin = 0.0;
  real_T c45_l_nargout = 1.0;
  boolean_T c45_f_out;
  real_T c45_m_nargin = 0.0;
  real_T c45_m_nargout = 0.0;
  real_T c45_n_nargin = 0.0;
  real_T c45_n_nargout = 0.0;
  real_T c45_o_nargin = 0.0;
  real_T c45_o_nargout = 1.0;
  boolean_T c45_g_out;
  real_T c45_p_nargin = 0.0;
  real_T c45_p_nargout = 0.0;
  real_T c45_q_nargin = 0.0;
  real_T c45_q_nargout = 1.0;
  boolean_T c45_h_out;
  real_T c45_r_nargin = 0.0;
  real_T c45_r_nargout = 0.0;
  real_T c45_s_nargin = 0.0;
  real_T c45_s_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U, *chartInstance->c45_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c45_r_debug_family_names,
    c45_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_nargin, 0U, c45_sf_marshallOut,
    c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_nargout, 1U, c45_sf_marshallOut,
    c45_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_out, 2U, c45_b_sf_marshallOut,
    c45_b_sf_marshallIn);
  guard3 = false;
  if (CV_EML_COND(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0,
        *chartInstance->c45_MedullaCommand, 4.0, -1, 0U,
        *chartInstance->c45_MedullaCommand == 4.0))) {
    guard3 = true;
  } else if (CV_EML_COND(9, 0, 1, CV_RELATIONAL_EVAL(5U, 9U, 1,
               *chartInstance->c45_MedullaCommand, 5.0, -1, 0U,
               *chartInstance->c45_MedullaCommand == 5.0))) {
    guard3 = true;
  } else {
    CV_EML_MCDC(9, 0, 0, false);
    CV_EML_IF(9, 0, 0, false);
    c45_out = false;
  }

  if (guard3 == true) {
    CV_EML_MCDC(9, 0, 0, true);
    CV_EML_IF(9, 0, 0, true);
    c45_out = true;
  }

  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c45_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, *chartInstance->c45_sfEvent);
    c45_exit_internal_Initialization(chartInstance);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c45_sfEvent);
    *chartInstance->c45_is_c45_Walking_ATRIAS = c45_IN_FaultRunning;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c45_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_h_debug_family_names,
      c45_b_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_b_nargin, 0U, c45_sf_marshallOut,
      c45_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_b_nargout, 1U, c45_sf_marshallOut,
      c45_sf_marshallIn);
    *chartInstance->c45_ControlWordIndex = 1.0;
    c45_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
    *chartInstance->c45_EnableTargetTorque = 0.0;
    c45_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
    *chartInstance->c45_FaultDetected = 1.0;
    c45_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
    _SFD_SYMBOL_SCOPE_POP();
    guard1 = true;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                 *chartInstance->c45_sfEvent);
    switch (*chartInstance->c45_is_Initialization) {
     case c45_IN_Fault:
      CV_STATE_EVAL(1, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                   *chartInstance->c45_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c45_k_debug_family_names,
        c45_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_c_nargin, 0U, c45_sf_marshallOut,
        c45_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_c_nargout, 1U,
        c45_sf_marshallOut, c45_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_b_out, 2U, c45_b_sf_marshallOut,
        c45_b_sf_marshallIn);
      c45_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 164U, 1, 7);
      c45_b_out = CV_EML_IF(11, 0, 0, CV_RELATIONAL_EVAL(5U, 11U, 0,
        *chartInstance->c45_Timeout, 20.0, -1, 5U, *chartInstance->c45_Timeout >=
        20.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c45_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, *chartInstance->c45_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c45_sfEvent);
        *chartInstance->c45_is_Initialization = c45_IN_Fault;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c45_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_d_debug_family_names,
          c45_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_d_nargin, 0U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_d_nargout, 1U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        *chartInstance->c45_ControlWordIndex = 3.0;
        c45_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
        *chartInstance->c45_EnableTargetTorque = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
        *chartInstance->c45_Timeout = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_Timeout, 5U);
        *chartInstance->c45_FaultDetected = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U,
                     *chartInstance->c45_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c45_m_debug_family_names,
          c45_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_e_nargin, 0U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_e_nargout, 1U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_c_out, 2U,
          c45_b_sf_marshallOut, c45_b_sf_marshallIn);
        c45_c_out = CV_EML_IF(4, 0, 0, CV_RELATIONAL_EVAL(5U, 4U, 0, (real_T)
          *chartInstance->c45_SwitchOnDisabledMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c45_SwitchOnDisabledMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c45_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c45_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c45_sfEvent);
          *chartInstance->c45_is_Initialization = c45_IN_SwitchOnDisabled;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c45_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_b_debug_family_names,
            c45_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_f_nargin, 0U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_f_nargout, 1U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          *chartInstance->c45_ControlWordIndex = 1.0;
          c45_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
          *chartInstance->c45_Timeout = 0.0;
          c45_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_Timeout, 5U);
          *chartInstance->c45_EnableTargetTorque = 0.0;
          c45_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
          *chartInstance->c45_FaultDetected = 0.0;
          c45_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       *chartInstance->c45_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_e_debug_family_names,
            c45_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_g_nargin, 0U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_g_nargout, 1U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          c45_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 163U, 129, 7);
          (*chartInstance->c45_Timeout)++;
          c45_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_Timeout, 5U);
          *chartInstance->c45_ControlWordIndex = 0.0;
          c45_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *chartInstance->c45_sfEvent);
      guard1 = true;
      break;

     case c45_IN_ReadyToSwitchOn:
      CV_STATE_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                   *chartInstance->c45_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c45_o_debug_family_names,
        c45_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_h_nargin, 0U, c45_sf_marshallOut,
        c45_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_h_nargout, 1U,
        c45_sf_marshallOut, c45_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_d_out, 2U, c45_b_sf_marshallOut,
        c45_b_sf_marshallIn);
      c45_d_out = CV_EML_IF(0, 0, 0, CV_RELATIONAL_EVAL(5U, 0U, 0, (real_T)
        *chartInstance->c45_FaultMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c45_FaultMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c45_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c45_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c45_sfEvent);
        *chartInstance->c45_is_Initialization = c45_IN_Fault;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c45_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_d_debug_family_names,
          c45_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_i_nargin, 0U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_i_nargout, 1U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        *chartInstance->c45_ControlWordIndex = 3.0;
        c45_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
        *chartInstance->c45_EnableTargetTorque = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
        *chartInstance->c45_Timeout = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_Timeout, 5U);
        *chartInstance->c45_FaultDetected = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     *chartInstance->c45_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c45_l_debug_family_names,
          c45_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_j_nargin, 0U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_j_nargout, 1U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_e_out, 2U,
          c45_b_sf_marshallOut, c45_b_sf_marshallIn);
        c45_e_out = CV_EML_IF(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0, (real_T)
          *chartInstance->c45_SwitchOnDisabledMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c45_SwitchOnDisabledMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c45_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *chartInstance->c45_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c45_sfEvent);
          *chartInstance->c45_is_Initialization = c45_IN_SwitchOnDisabled;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c45_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_b_debug_family_names,
            c45_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_k_nargin, 0U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_k_nargout, 1U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          *chartInstance->c45_ControlWordIndex = 1.0;
          c45_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
          *chartInstance->c45_Timeout = 0.0;
          c45_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_Timeout, 5U);
          *chartInstance->c45_EnableTargetTorque = 0.0;
          c45_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
          *chartInstance->c45_FaultDetected = 0.0;
          c45_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 8U,
                       *chartInstance->c45_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c45_u_debug_family_names,
            c45_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_l_nargin, 0U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_l_nargout, 1U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_f_out, 2U,
            c45_b_sf_marshallOut, c45_b_sf_marshallIn);
          guard2 = false;
          if (CV_EML_COND(8, 0, 0, CV_RELATIONAL_EVAL(5U, 8U, 0, (real_T)
                *chartInstance->c45_EnabledMode, 1.0, -1, 0U, (real_T)
                *chartInstance->c45_EnabledMode == 1.0))) {
            if (CV_EML_COND(8, 0, 1, CV_RELATIONAL_EVAL(5U, 8U, 1, (real_T)
                  *chartInstance->c45_FaultMode, 0.0, -1, 0U, (real_T)
                  *chartInstance->c45_FaultMode == 0.0))) {
              CV_EML_MCDC(8, 0, 0, true);
              CV_EML_IF(8, 0, 0, true);
              c45_f_out = true;
            } else {
              guard2 = true;
            }
          } else {
            guard2 = true;
          }

          if (guard2 == true) {
            CV_EML_MCDC(8, 0, 0, false);
            CV_EML_IF(8, 0, 0, false);
            c45_f_out = false;
          }

          _SFD_SYMBOL_SCOPE_POP();
          if (c45_f_out) {
            _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, *chartInstance->c45_sfEvent);
            *chartInstance->c45_is_Initialization = c45_IN_NO_ACTIVE_CHILD;
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c45_sfEvent);
            _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c45_sfEvent);
            *chartInstance->c45_is_c45_Walking_ATRIAS = c45_IN_Running;
            _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c45_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_i_debug_family_names,
              c45_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_m_nargin, 0U,
              c45_sf_marshallOut, c45_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_m_nargout, 1U,
              c45_sf_marshallOut, c45_sf_marshallIn);
            *chartInstance->c45_FaultDetected = 0.0;
            c45_updateDataWrittenToVector(chartInstance, 3U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
            *chartInstance->c45_ControlWordIndex = 2.0;
            c45_updateDataWrittenToVector(chartInstance, 0U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
            *chartInstance->c45_EnableTargetTorque = 1.0;
            c45_updateDataWrittenToVector(chartInstance, 1U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
            _SFD_SYMBOL_SCOPE_POP();
          } else {
            _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 3U,
                         *chartInstance->c45_sfEvent);
            _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_g_debug_family_names,
              c45_b_debug_family_var_map);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_n_nargin, 0U,
              c45_sf_marshallOut, c45_sf_marshallIn);
            _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_n_nargout, 1U,
              c45_sf_marshallOut, c45_sf_marshallIn);
            c45_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 162U, 139, 7);
            (*chartInstance->c45_Timeout)++;
            c45_updateDataWrittenToVector(chartInstance, 2U);
            _SFD_DATA_RANGE_CHECK(*chartInstance->c45_Timeout, 5U);
            _SFD_SYMBOL_SCOPE_POP();
          }
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c45_sfEvent);
      if (*chartInstance->c45_is_c45_Walking_ATRIAS != c45_IN_Initialization) {
      } else {
        guard1 = true;
      }
      break;

     case c45_IN_SwitchOnDisabled:
      CV_STATE_EVAL(1, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   *chartInstance->c45_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c45_n_debug_family_names,
        c45_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_o_nargin, 0U, c45_sf_marshallOut,
        c45_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_o_nargout, 1U,
        c45_sf_marshallOut, c45_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_g_out, 2U, c45_b_sf_marshallOut,
        c45_b_sf_marshallIn);
      c45_g_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, (real_T)
        *chartInstance->c45_ReadyToSwitchOnMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c45_ReadyToSwitchOnMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c45_g_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c45_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c45_sfEvent);
        *chartInstance->c45_is_Initialization = c45_IN_ReadyToSwitchOn;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c45_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_f_debug_family_names,
          c45_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_p_nargin, 0U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_p_nargout, 1U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        *chartInstance->c45_ControlWordIndex = 2.0;
        c45_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
        *chartInstance->c45_Timeout = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_Timeout, 5U);
        *chartInstance->c45_EnableTargetTorque = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
        *chartInstance->c45_FaultDetected = 0.0;
        c45_updateDataWrittenToVector(chartInstance, 3U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                     *chartInstance->c45_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c45_j_debug_family_names,
          c45_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_q_nargin, 0U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_q_nargout, 1U,
          c45_sf_marshallOut, c45_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_h_out, 2U,
          c45_b_sf_marshallOut, c45_b_sf_marshallIn);
        c45_h_out = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, (real_T)
          *chartInstance->c45_FaultMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c45_FaultMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c45_h_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c45_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c45_sfEvent);
          *chartInstance->c45_is_Initialization = c45_IN_Fault;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c45_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_d_debug_family_names,
            c45_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_r_nargin, 0U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_r_nargout, 1U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          *chartInstance->c45_ControlWordIndex = 3.0;
          c45_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_ControlWordIndex, 3U);
          *chartInstance->c45_EnableTargetTorque = 0.0;
          c45_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_EnableTargetTorque, 4U);
          *chartInstance->c45_Timeout = 0.0;
          c45_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_Timeout, 5U);
          *chartInstance->c45_FaultDetected = 0.0;
          c45_updateDataWrittenToVector(chartInstance, 3U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_FaultDetected, 7U);
          _SFD_SYMBOL_SCOPE_POP();
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                       *chartInstance->c45_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c45_c_debug_family_names,
            c45_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_s_nargin, 0U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c45_s_nargout, 1U,
            c45_sf_marshallOut, c45_sf_marshallIn);
          c45_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 159U, 140, 7);
          (*chartInstance->c45_Timeout)++;
          c45_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c45_Timeout, 5U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *chartInstance->c45_sfEvent);
      guard1 = true;
      break;

     default:
      CV_STATE_EVAL(1, 0, 0);
      *chartInstance->c45_is_Initialization = c45_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c45_sfEvent);
      guard1 = true;
      break;
    }
  }

  if (guard1 == true) {
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c45_sfEvent);
  }
}

static void c45_exit_internal_Initialization(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance)
{
  switch (*chartInstance->c45_is_Initialization) {
   case c45_IN_Fault:
    CV_STATE_EVAL(1, 1, 1);
    *chartInstance->c45_is_Initialization = c45_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c45_sfEvent);
    break;

   case c45_IN_ReadyToSwitchOn:
    CV_STATE_EVAL(1, 1, 2);
    *chartInstance->c45_is_Initialization = c45_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c45_sfEvent);
    break;

   case c45_IN_SwitchOnDisabled:
    CV_STATE_EVAL(1, 1, 3);
    *chartInstance->c45_is_Initialization = c45_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c45_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    *chartInstance->c45_is_Initialization = c45_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c45_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c45_machineNumber, uint32_T
  c45_chartNumber, uint32_T c45_instanceNumber)
{
  (void)c45_machineNumber;
  (void)c45_chartNumber;
  (void)c45_instanceNumber;
}

static const mxArray *c45_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  real_T c45_u;
  const mxArray *c45_y = NULL;
  SFc45_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc45_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_u = *(real_T *)c45_inData;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static real_T c45_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_nargout, const char_T *c45_identifier)
{
  real_T c45_y;
  emlrtMsgIdentifier c45_thisId;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_nargout),
    &c45_thisId);
  sf_mex_destroy(&c45_nargout);
  return c45_y;
}

static real_T c45_b_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  real_T c45_y;
  real_T c45_d0;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_d0, 1, 0, 0U, 0, 0U, 0);
  c45_y = c45_d0;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_nargout;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  real_T c45_y;
  SFc45_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc45_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c45_nargout = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_nargout),
    &c45_thisId);
  sf_mex_destroy(&c45_nargout);
  *(real_T *)c45_outData = c45_y;
  sf_mex_destroy(&c45_mxArrayInData);
}

static const mxArray *c45_b_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  boolean_T c45_u;
  const mxArray *c45_y = NULL;
  SFc45_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc45_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_u = *(boolean_T *)c45_inData;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static boolean_T c45_c_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  boolean_T c45_y;
  boolean_T c45_b0;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_b0, 1, 11, 0U, 0, 0U, 0);
  c45_y = c45_b0;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_sf_internal_predicateOutput;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  boolean_T c45_y;
  SFc45_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc45_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c45_sf_internal_predicateOutput = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c45_sf_internal_predicateOutput), &c45_thisId);
  sf_mex_destroy(&c45_sf_internal_predicateOutput);
  *(boolean_T *)c45_outData = c45_y;
  sf_mex_destroy(&c45_mxArrayInData);
}

const mxArray *sf_c45_Walking_ATRIAS_get_eml_resolved_functions_info(void)
{
  const mxArray *c45_nameCaptureInfo = NULL;
  c45_nameCaptureInfo = NULL;
  sf_mex_assign(&c45_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c45_nameCaptureInfo;
}

static const mxArray *c45_c_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  int32_T c45_u;
  const mxArray *c45_y = NULL;
  SFc45_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc45_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_u = *(int32_T *)c45_inData;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static int32_T c45_d_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  int32_T c45_y;
  int32_T c45_i2;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_i2, 1, 6, 0U, 0, 0U, 0);
  c45_y = c45_i2;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_b_sfEvent;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  int32_T c45_y;
  SFc45_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc45_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c45_b_sfEvent = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_b_sfEvent),
    &c45_thisId);
  sf_mex_destroy(&c45_b_sfEvent);
  *(int32_T *)c45_outData = c45_y;
  sf_mex_destroy(&c45_mxArrayInData);
}

static const mxArray *c45_d_sf_marshallOut(void *chartInstanceVoid, void
  *c45_inData)
{
  const mxArray *c45_mxArrayOutData = NULL;
  uint8_T c45_u;
  const mxArray *c45_y = NULL;
  SFc45_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc45_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c45_mxArrayOutData = NULL;
  c45_u = *(uint8_T *)c45_inData;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_create("y", &c45_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c45_mxArrayOutData, c45_y, false);
  return c45_mxArrayOutData;
}

static uint8_T c45_e_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_b_is_Initialization, const char_T
  *c45_identifier)
{
  uint8_T c45_y;
  emlrtMsgIdentifier c45_thisId;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c45_b_is_Initialization), &c45_thisId);
  sf_mex_destroy(&c45_b_is_Initialization);
  return c45_y;
}

static uint8_T c45_f_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  uint8_T c45_y;
  uint8_T c45_u0;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), &c45_u0, 1, 3, 0U, 0, 0U, 0);
  c45_y = c45_u0;
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c45_mxArrayInData, const char_T *c45_varName, void *c45_outData)
{
  const mxArray *c45_b_is_Initialization;
  const char_T *c45_identifier;
  emlrtMsgIdentifier c45_thisId;
  uint8_T c45_y;
  SFc45_Walking_ATRIASInstanceStruct *chartInstance;
  chartInstance = (SFc45_Walking_ATRIASInstanceStruct *)chartInstanceVoid;
  c45_b_is_Initialization = sf_mex_dup(c45_mxArrayInData);
  c45_identifier = c45_varName;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_y = c45_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c45_b_is_Initialization), &c45_thisId);
  sf_mex_destroy(&c45_b_is_Initialization);
  *(uint8_T *)c45_outData = c45_y;
  sf_mex_destroy(&c45_mxArrayInData);
}

static void c45_g_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_b_dataWrittenToVector, const char_T
  *c45_identifier, boolean_T c45_y[4])
{
  emlrtMsgIdentifier c45_thisId;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  c45_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c45_b_dataWrittenToVector),
    &c45_thisId, c45_y);
  sf_mex_destroy(&c45_b_dataWrittenToVector);
}

static void c45_h_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId,
  boolean_T c45_y[4])
{
  boolean_T c45_bv1[4];
  int32_T c45_i3;
  (void)chartInstance;
  sf_mex_import(c45_parentId, sf_mex_dup(c45_u), c45_bv1, 1, 11, 0U, 1, 0U, 1, 4);
  for (c45_i3 = 0; c45_i3 < 4; c45_i3++) {
    c45_y[c45_i3] = c45_bv1[c45_i3];
  }

  sf_mex_destroy(&c45_u);
}

static const mxArray *c45_i_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c45_b_setSimStateSideEffectsInfo, const char_T
  *c45_identifier)
{
  const mxArray *c45_y = NULL;
  emlrtMsgIdentifier c45_thisId;
  c45_y = NULL;
  c45_thisId.fIdentifier = c45_identifier;
  c45_thisId.fParent = NULL;
  sf_mex_assign(&c45_y, c45_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c45_b_setSimStateSideEffectsInfo), &c45_thisId), false);
  sf_mex_destroy(&c45_b_setSimStateSideEffectsInfo);
  return c45_y;
}

static const mxArray *c45_j_emlrt_marshallIn(SFc45_Walking_ATRIASInstanceStruct *
  chartInstance, const mxArray *c45_u, const emlrtMsgIdentifier *c45_parentId)
{
  const mxArray *c45_y = NULL;
  (void)chartInstance;
  (void)c45_parentId;
  c45_y = NULL;
  sf_mex_assign(&c45_y, sf_mex_duplicatearraysafe(&c45_u), false);
  sf_mex_destroy(&c45_u);
  return c45_y;
}

static void c45_updateDataWrittenToVector(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, uint32_T c45_vectorIndex)
{
  chartInstance->c45_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK
    (0U, (int32_T)c45_vectorIndex, 0, 3, 1, 0)] = true;
}

static void c45_errorIfDataNotWrittenToFcn(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance, uint32_T c45_vectorIndex, uint32_T c45_dataNumber, uint32_T
  c45_ssIdOfSourceObject, int32_T c45_offsetInSourceObject, int32_T
  c45_lengthInSourceObject)
{
  (void)c45_ssIdOfSourceObject;
  (void)c45_offsetInSourceObject;
  (void)c45_lengthInSourceObject;
  if (!chartInstance->c45_dataWrittenToVector[(uint32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK(0U, (int32_T)c45_vectorIndex, 0, 3, 1, 0)]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(c45_dataNumber);
  }
}

static void init_dsm_address_info(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc45_Walking_ATRIASInstanceStruct
  *chartInstance)
{
  chartInstance->c45_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c45_isStable = (boolean_T *)ssGetDWork_wrapper(chartInstance->S,
    1);
  chartInstance->c45_is_active_c45_Walking_ATRIAS = (uint8_T *)
    ssGetDWork_wrapper(chartInstance->S, 2);
  chartInstance->c45_is_c45_Walking_ATRIAS = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 3);
  chartInstance->c45_is_Initialization = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 4);
  chartInstance->c45_SwitchOnDisabledMode = (boolean_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c45_EnabledMode = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c45_ReadyToSwitchOnMode = (boolean_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c45_ControlWordIndex = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c45_EnableTargetTorque = (real_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c45_Timeout = (real_T *)ssGetDWork_wrapper(chartInstance->S, 5);
  chartInstance->c45_FaultMode = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c45_FaultDetected = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c45_MedullaCommand = (real_T *)ssGetInputPortSignal_wrapper
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
void sf_c45_Walking_ATRIAS_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(970640993U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(411423021U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(942268629U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1617527152U);
}

mxArray* sf_c45_Walking_ATRIAS_get_post_codegen_info(void);
mxArray *sf_c45_Walking_ATRIAS_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("uiorEU5nAdBqLtvTuxvn8B");
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
    mxArray* mxPostCodegenInfo = sf_c45_Walking_ATRIAS_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c45_Walking_ATRIAS_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c45_Walking_ATRIAS_jit_fallback_info(void)
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

mxArray *sf_c45_Walking_ATRIAS_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c45_Walking_ATRIAS_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c45_Walking_ATRIAS(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[23],T\"ControlWordIndex\",},{M[1],M[24],T\"EnableTargetTorque\",},{M[1],M[64],T\"FaultDetected\",},{M[3],M[25],T\"Timeout\",},{M[8],M[0],T\"is_active_c45_Walking_ATRIAS\",},{M[9],M[0],T\"is_c45_Walking_ATRIAS\",},{M[9],M[144],T\"is_Initialization\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c45_Walking_ATRIAS_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc45_Walking_ATRIASInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc45_Walking_ATRIASInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking_ATRIASMachineNumber_,
           45,
           7,
           14,
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
        init_script_number_translation(_Walking_ATRIASMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Walking_ATRIASMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Walking_ATRIASMachineNumber_,
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

        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(6,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(4,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,15,1,15);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,15,-1,0);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,13,1,13);
        _SFD_CV_INIT_EML_RELATIONAL(11,0,0,1,13,-1,5);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,26,1,26);
        _SFD_CV_INIT_EML_RELATIONAL(6,0,0,1,26,-1,0);
        _SFD_CV_INIT_EML(4,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(4,0,0,1,26,1,26);
        _SFD_CV_INIT_EML_RELATIONAL(4,0,0,1,26,-1,0);
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,25,1,25);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,1,25,-1,0);
        _SFD_CV_INIT_EML(0,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(0,0,0,1,15,1,15);
        _SFD_CV_INIT_EML_RELATIONAL(0,0,0,1,15,-1,0);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,20,1,20);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,20,-1,0);
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,20,1,20);
        _SFD_CV_INIT_EML_RELATIONAL(13,0,0,1,20,-1,0);
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
        _SFD_CV_INIT_EML(1,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(1,0,0,1,15,1,15);
        _SFD_CV_INIT_EML_RELATIONAL(1,0,0,1,15,-1,0);
        _SFD_CV_INIT_EML(12,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(12,0,0,1,43,1,43);

        {
          static int condStart[] = { 1, 24 };

          static int condEnd[] = { 20, 43 };

          static int pfixExpr[] = { 0, 1, -2 };

          _SFD_CV_INIT_EML_MCDC(12,0,0,1,43,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(12,0,0,1,20,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(12,0,1,24,43,-1,0);
        _SFD_CV_INIT_EML(8,0,0,1,0,0,0,0,0,2,1);
        _SFD_CV_INIT_EML_IF(8,0,0,1,35,1,35);

        {
          static int condStart[] = { 1, 21 };

          static int condEnd[] = { 17, 35 };

          static int pfixExpr[] = { 0, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(8,0,0,1,35,2,0,&(condStart[0]),&(condEnd[0]),3,
                                &(pfixExpr[0]));
        }

        _SFD_CV_INIT_EML_RELATIONAL(8,0,0,1,17,-1,0);
        _SFD_CV_INIT_EML_RELATIONAL(8,0,1,21,35,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)c45_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)c45_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)c45_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)c45_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c45_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c45_SwitchOnDisabledMode);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c45_EnabledMode);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c45_ReadyToSwitchOnMode);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c45_ControlWordIndex);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c45_EnableTargetTorque);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c45_Timeout);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c45_FaultMode);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c45_FaultDetected);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c45_MedullaCommand);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Walking_ATRIASMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "UNiliVhUDkBQ82vaoyWQmG";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_Walking_ATRIAS_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 45, "dworkChecksum");
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

static void sf_opaque_initialize_c45_Walking_ATRIAS(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc45_Walking_ATRIASInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc45_Walking_ATRIASInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c45_Walking_ATRIAS((SFc45_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
  initialize_c45_Walking_ATRIAS((SFc45_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c45_Walking_ATRIAS(void *chartInstanceVar)
{
  enable_c45_Walking_ATRIAS((SFc45_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c45_Walking_ATRIAS(void *chartInstanceVar)
{
  disable_c45_Walking_ATRIAS((SFc45_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c45_Walking_ATRIAS(void *chartInstanceVar)
{
  sf_gateway_c45_Walking_ATRIAS((SFc45_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c45_Walking_ATRIAS(void *chartInstanceVar)
{
  ext_mode_exec_c45_Walking_ATRIAS((SFc45_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c45_Walking_ATRIAS(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c45_Walking_ATRIAS((SFc45_Walking_ATRIASInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c45_Walking_ATRIAS(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c45_Walking_ATRIAS((SFc45_Walking_ATRIASInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c45_Walking_ATRIAS(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc45_Walking_ATRIASInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking_ATRIAS_optimization_info();
    }

    finalize_c45_Walking_ATRIAS((SFc45_Walking_ATRIASInstanceStruct*)
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
  initSimStructsc45_Walking_ATRIAS((SFc45_Walking_ATRIASInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c45_Walking_ATRIAS(SimStruct *S)
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
    initialize_params_c45_Walking_ATRIAS((SFc45_Walking_ATRIASInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

mxArray *sf_c45_Walking_ATRIAS_get_testpoint_info(void)
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

static void mdlSetWorkWidths_c45_Walking_ATRIAS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking_ATRIAS_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      45);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,45,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,45,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,45);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,45,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,45,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,45);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(665169481U));
  ssSetChecksum1(S,(3605150411U));
  ssSetChecksum2(S,(2027137207U));
  ssSetChecksum3(S,(2182768420U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c45_Walking_ATRIAS(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c45_Walking_ATRIAS(SimStruct *S)
{
  SFc45_Walking_ATRIASInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc45_Walking_ATRIASInstanceStruct *)utMalloc(sizeof
    (SFc45_Walking_ATRIASInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc45_Walking_ATRIASInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c45_Walking_ATRIAS;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c45_Walking_ATRIAS;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c45_Walking_ATRIAS;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c45_Walking_ATRIAS;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c45_Walking_ATRIAS;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c45_Walking_ATRIAS;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c45_Walking_ATRIAS;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c45_Walking_ATRIAS;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c45_Walking_ATRIAS;
  chartInstance->chartInfo.mdlStart = mdlStart_c45_Walking_ATRIAS;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c45_Walking_ATRIAS;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c45_Walking_ATRIAS;
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

void c45_Walking_ATRIAS_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c45_Walking_ATRIAS(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c45_Walking_ATRIAS(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c45_Walking_ATRIAS(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c45_Walking_ATRIAS_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
