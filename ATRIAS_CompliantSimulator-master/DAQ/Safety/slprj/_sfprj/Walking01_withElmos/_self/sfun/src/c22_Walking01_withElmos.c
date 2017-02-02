/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_withElmos_sfun.h"
#include "c22_Walking01_withElmos.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Walking01_withElmos_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c22_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c22_IN_FaultRunning            ((uint8_T)1U)
#define c22_IN_Initialization          ((uint8_T)2U)
#define c22_IN_Running                 ((uint8_T)3U)
#define c22_IN_Start1                  ((uint8_T)4U)
#define c22_IN_Fault                   ((uint8_T)1U)
#define c22_IN_ReadyToSwitchOn         ((uint8_T)2U)
#define c22_IN_SwitchOnDisabled        ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c22_debug_family_names[2] = { "nargin", "nargout" };

static const char * c22_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c22_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c22_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c22_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c22_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c22_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c22_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c22_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c22_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c22_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void initialize_params_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void enable_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void disable_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void c22_update_debugger_state_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void ext_mode_exec_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void set_sim_state_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance, const mxArray *c22_st);
static void c22_set_sim_state_side_effects_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void finalize_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void sf_gateway_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void mdl_start_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void c22_chartstep_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void initSimStructsc22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void c22_enter_atomic_Fault(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance);
static void c22_enter_atomic_SwitchOnDisabled
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void c22_enter_atomic_FaultRunning
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void c22_Initialization(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance);
static void c22_exit_internal_Initialization
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber);
static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static real_T c22_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_nargout, const char_T *c22_identifier);
static real_T c22_b_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static boolean_T c22_c_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct *
  chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static int32_T c22_d_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static const mxArray *c22_d_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData);
static uint8_T c22_e_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_b_is_Initialization, const char_T
  *c22_identifier);
static uint8_T c22_f_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId);
static void c22_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData);
static void c22_g_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_b_dataWrittenToVector, const char_T
  *c22_identifier, boolean_T c22_y[4]);
static void c22_h_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  boolean_T c22_y[4]);
static const mxArray *c22_i_emlrt_marshallIn
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance, const mxArray
   *c22_b_setSimStateSideEffectsInfo, const char_T *c22_identifier);
static const mxArray *c22_j_emlrt_marshallIn
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance, const mxArray *c22_u,
   const emlrtMsgIdentifier *c22_parentId);
static void c22_updateDataWrittenToVector
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance, uint32_T
   c22_vectorIndex);
static void c22_errorIfDataNotWrittenToFcn
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance, uint32_T
   c22_vectorIndex, uint32_T c22_dataNumber, uint32_T c22_ssIdOfSourceObject,
   int32_T c22_offsetInSourceObject, int32_T c22_lengthInSourceObject);
static void init_dsm_address_info(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  *chartInstance->c22_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c22_doSetSimStateSideEffects = 0U;
  chartInstance->c22_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c22_is_Initialization = c22_IN_NO_ACTIVE_CHILD;
  *chartInstance->c22_is_active_c22_Walking01_withElmos = 0U;
  *chartInstance->c22_is_c22_Walking01_withElmos = c22_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c22_update_debugger_state_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  uint32_T c22_prevAniVal;
  c22_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c22_is_active_c22_Walking01_withElmos == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 16U, *chartInstance->c22_sfEvent);
  }

  if (*chartInstance->c22_is_Initialization == c22_IN_Fault) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c22_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c22_sfEvent);
  }

  if (*chartInstance->c22_is_Initialization == c22_IN_SwitchOnDisabled) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c22_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c22_sfEvent);
  }

  if (*chartInstance->c22_is_c22_Walking01_withElmos == c22_IN_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c22_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c22_sfEvent);
  }

  if (*chartInstance->c22_is_c22_Walking01_withElmos == c22_IN_Start1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c22_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c22_sfEvent);
  }

  if (*chartInstance->c22_is_c22_Walking01_withElmos == c22_IN_FaultRunning) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c22_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c22_sfEvent);
  }

  if (*chartInstance->c22_is_c22_Walking01_withElmos == c22_IN_Initialization) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c22_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c22_sfEvent);
  }

  if (*chartInstance->c22_is_Initialization == c22_IN_ReadyToSwitchOn) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c22_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c22_sfEvent);
  }

  _SFD_SET_ANIMATION(c22_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  c22_update_debugger_state_c22_Walking01_withElmos(chartInstance);
}

static const mxArray *get_sim_state_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  const mxArray *c22_st;
  const mxArray *c22_y = NULL;
  real_T c22_hoistedGlobal;
  real_T c22_u;
  const mxArray *c22_b_y = NULL;
  real_T c22_b_hoistedGlobal;
  real_T c22_b_u;
  const mxArray *c22_c_y = NULL;
  real_T c22_c_hoistedGlobal;
  real_T c22_c_u;
  const mxArray *c22_d_y = NULL;
  real_T c22_d_hoistedGlobal;
  real_T c22_d_u;
  const mxArray *c22_e_y = NULL;
  uint8_T c22_e_hoistedGlobal;
  uint8_T c22_e_u;
  const mxArray *c22_f_y = NULL;
  uint8_T c22_f_hoistedGlobal;
  uint8_T c22_f_u;
  const mxArray *c22_g_y = NULL;
  uint8_T c22_g_hoistedGlobal;
  uint8_T c22_g_u;
  const mxArray *c22_h_y = NULL;
  int32_T c22_i0;
  boolean_T c22_h_u[4];
  const mxArray *c22_i_y = NULL;
  c22_st = NULL;
  c22_st = NULL;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_createcellmatrix(8, 1), false);
  c22_hoistedGlobal = *chartInstance->c22_ControlWordIndex;
  c22_u = c22_hoistedGlobal;
  c22_b_y = NULL;
  sf_mex_assign(&c22_b_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 0, c22_b_y);
  c22_b_hoistedGlobal = *chartInstance->c22_EnableTargetTorque;
  c22_b_u = c22_b_hoistedGlobal;
  c22_c_y = NULL;
  sf_mex_assign(&c22_c_y, sf_mex_create("y", &c22_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 1, c22_c_y);
  c22_c_hoistedGlobal = *chartInstance->c22_FaultDetected;
  c22_c_u = c22_c_hoistedGlobal;
  c22_d_y = NULL;
  sf_mex_assign(&c22_d_y, sf_mex_create("y", &c22_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 2, c22_d_y);
  c22_d_hoistedGlobal = *chartInstance->c22_Timeout;
  c22_d_u = c22_d_hoistedGlobal;
  c22_e_y = NULL;
  sf_mex_assign(&c22_e_y, sf_mex_create("y", &c22_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 3, c22_e_y);
  c22_e_hoistedGlobal = *chartInstance->c22_is_active_c22_Walking01_withElmos;
  c22_e_u = c22_e_hoistedGlobal;
  c22_f_y = NULL;
  sf_mex_assign(&c22_f_y, sf_mex_create("y", &c22_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 4, c22_f_y);
  c22_f_hoistedGlobal = *chartInstance->c22_is_c22_Walking01_withElmos;
  c22_f_u = c22_f_hoistedGlobal;
  c22_g_y = NULL;
  sf_mex_assign(&c22_g_y, sf_mex_create("y", &c22_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 5, c22_g_y);
  c22_g_hoistedGlobal = *chartInstance->c22_is_Initialization;
  c22_g_u = c22_g_hoistedGlobal;
  c22_h_y = NULL;
  sf_mex_assign(&c22_h_y, sf_mex_create("y", &c22_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c22_y, 6, c22_h_y);
  for (c22_i0 = 0; c22_i0 < 4; c22_i0++) {
    c22_h_u[c22_i0] = chartInstance->c22_dataWrittenToVector[c22_i0];
  }

  c22_i_y = NULL;
  sf_mex_assign(&c22_i_y, sf_mex_create("y", c22_h_u, 11, 0U, 1U, 0U, 1, 4),
                false);
  sf_mex_setcell(c22_y, 7, c22_i_y);
  sf_mex_assign(&c22_st, c22_y, false);
  return c22_st;
}

static void set_sim_state_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance, const mxArray *c22_st)
{
  const mxArray *c22_u;
  boolean_T c22_bv0[4];
  int32_T c22_i1;
  c22_u = sf_mex_dup(c22_st);
  *chartInstance->c22_ControlWordIndex = c22_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c22_u, 0)), "ControlWordIndex");
  *chartInstance->c22_EnableTargetTorque = c22_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c22_u, 1)), "EnableTargetTorque");
  *chartInstance->c22_FaultDetected = c22_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c22_u, 2)), "FaultDetected");
  *chartInstance->c22_Timeout = c22_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c22_u, 3)), "Timeout");
  *chartInstance->c22_is_active_c22_Walking01_withElmos = c22_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 4)),
     "is_active_c22_Walking01_withElmos");
  *chartInstance->c22_is_c22_Walking01_withElmos = c22_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 5)),
     "is_c22_Walking01_withElmos");
  *chartInstance->c22_is_Initialization = c22_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c22_u, 6)), "is_Initialization");
  c22_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c22_u, 7)),
    "dataWrittenToVector", c22_bv0);
  for (c22_i1 = 0; c22_i1 < 4; c22_i1++) {
    chartInstance->c22_dataWrittenToVector[c22_i1] = c22_bv0[c22_i1];
  }

  sf_mex_assign(&chartInstance->c22_setSimStateSideEffectsInfo,
                c22_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c22_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c22_u);
  chartInstance->c22_doSetSimStateSideEffects = 1U;
  c22_update_debugger_state_c22_Walking01_withElmos(chartInstance);
  sf_mex_destroy(&c22_st);
}

static void c22_set_sim_state_side_effects_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  if (chartInstance->c22_doSetSimStateSideEffects != 0) {
    chartInstance->c22_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c22_setSimStateSideEffectsInfo);
}

static void sf_gateway_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  c22_set_sim_state_side_effects_c22_Walking01_withElmos(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, *chartInstance->c22_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c22_SwitchOnDisabledMode, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c22_EnabledMode, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c22_ReadyToSwitchOnMode, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_ControlWordIndex, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_EnableTargetTorque, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_Timeout, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c22_FaultMode, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_FaultDetected, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_MedullaCommand, 8U);
  *chartInstance->c22_sfEvent = CALL_EVENT;
  c22_chartstep_c22_Walking01_withElmos(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_withElmosMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c22_chartstep_c22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  uint32_T c22_debug_family_var_map[2];
  real_T c22_nargin = 0.0;
  real_T c22_nargout = 0.0;
  uint32_T c22_b_debug_family_var_map[3];
  real_T c22_b_nargin = 0.0;
  real_T c22_b_nargout = 1.0;
  boolean_T c22_out;
  real_T c22_c_nargin = 0.0;
  real_T c22_c_nargout = 1.0;
  boolean_T c22_b_out;
  real_T c22_d_nargin = 0.0;
  real_T c22_d_nargout = 1.0;
  boolean_T c22_c_out;
  real_T c22_e_nargin = 0.0;
  real_T c22_e_nargout = 1.0;
  boolean_T c22_d_out;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, *chartInstance->c22_sfEvent);
  if (*chartInstance->c22_is_active_c22_Walking01_withElmos == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 16U,
                 *chartInstance->c22_sfEvent);
    *chartInstance->c22_is_active_c22_Walking01_withElmos = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, *chartInstance->c22_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c22_sfEvent);
    *chartInstance->c22_is_c22_Walking01_withElmos = c22_IN_Start1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c22_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c22_f_debug_family_names,
      c22_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargin, 0U, c22_sf_marshallOut,
      c22_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargout, 1U, c22_sf_marshallOut,
      c22_sf_marshallIn);
    *chartInstance->c22_ControlWordIndex = 0.0;
    c22_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c22_ControlWordIndex, 3U);
    *chartInstance->c22_EnableTargetTorque = 0.0;
    c22_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c22_EnableTargetTorque, 4U);
    *chartInstance->c22_FaultDetected = 0.0;
    c22_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c22_FaultDetected, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (*chartInstance->c22_is_c22_Walking01_withElmos) {
     case c22_IN_FaultRunning:
      CV_CHART_EVAL(16, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   *chartInstance->c22_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c22_sfEvent);
      break;

     case c22_IN_Initialization:
      CV_CHART_EVAL(16, 0, 2);
      c22_Initialization(chartInstance);
      break;

     case c22_IN_Running:
      CV_CHART_EVAL(16, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   *chartInstance->c22_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c22_l_debug_family_names,
        c22_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_b_nargin, 0U, c22_sf_marshallOut,
        c22_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_b_nargout, 1U,
        c22_sf_marshallOut, c22_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_out, 2U, c22_b_sf_marshallOut,
        c22_b_sf_marshallIn);
      c22_out = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, (real_T)
        *chartInstance->c22_FaultMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c22_FaultMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c22_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c22_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c22_sfEvent);
        *chartInstance->c22_is_c22_Walking01_withElmos = c22_IN_FaultRunning;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c22_sfEvent);
        c22_enter_atomic_FaultRunning(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                     *chartInstance->c22_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c22_p_debug_family_names,
          c22_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_c_nargin, 0U,
          c22_sf_marshallOut, c22_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_c_nargout, 1U,
          c22_sf_marshallOut, c22_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_b_out, 2U,
          c22_b_sf_marshallOut, c22_b_sf_marshallIn);
        guard2 = false;
        if (CV_EML_COND(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0,
              *chartInstance->c22_MedullaCommand, 4.0, -1, 0U,
              *chartInstance->c22_MedullaCommand == 4.0))) {
          guard2 = true;
        } else if (CV_EML_COND(9, 0, 1, CV_RELATIONAL_EVAL(5U, 9U, 1,
                     *chartInstance->c22_MedullaCommand, 5.0, -1, 0U,
                     *chartInstance->c22_MedullaCommand == 5.0))) {
          guard2 = true;
        } else {
          CV_EML_MCDC(9, 0, 0, false);
          CV_EML_IF(9, 0, 0, false);
          c22_b_out = false;
        }

        if (guard2 == true) {
          CV_EML_MCDC(9, 0, 0, true);
          CV_EML_IF(9, 0, 0, true);
          c22_b_out = true;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c22_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, *chartInstance->c22_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c22_sfEvent);
          *chartInstance->c22_is_c22_Walking01_withElmos = c22_IN_FaultRunning;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c22_sfEvent);
          c22_enter_atomic_FaultRunning(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                       *chartInstance->c22_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c22_sfEvent);
      break;

     case c22_IN_Start1:
      CV_CHART_EVAL(16, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                   *chartInstance->c22_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c22_s_debug_family_names,
        c22_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_d_nargin, 0U, c22_sf_marshallOut,
        c22_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_d_nargout, 1U,
        c22_sf_marshallOut, c22_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_c_out, 2U, c22_b_sf_marshallOut,
        c22_b_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(12, 0, 0, CV_RELATIONAL_EVAL(5U, 12U, 0,
            *chartInstance->c22_MedullaCommand, 4.0, -1, 0U,
            *chartInstance->c22_MedullaCommand == 4.0))) {
        guard1 = true;
      } else if (CV_EML_COND(12, 0, 1, CV_RELATIONAL_EVAL(5U, 12U, 1,
                   *chartInstance->c22_MedullaCommand, 5.0, -1, 0U,
                   *chartInstance->c22_MedullaCommand == 5.0))) {
        guard1 = true;
      } else {
        CV_EML_MCDC(12, 0, 0, false);
        CV_EML_IF(12, 0, 0, false);
        c22_c_out = false;
      }

      if (guard1 == true) {
        CV_EML_MCDC(12, 0, 0, true);
        CV_EML_IF(12, 0, 0, true);
        c22_c_out = true;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c22_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, *chartInstance->c22_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c22_sfEvent);
        *chartInstance->c22_is_c22_Walking01_withElmos = c22_IN_FaultRunning;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c22_sfEvent);
        c22_enter_atomic_FaultRunning(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     *chartInstance->c22_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c22_n_debug_family_names,
          c22_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_e_nargin, 0U,
          c22_sf_marshallOut, c22_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_e_nargout, 1U,
          c22_sf_marshallOut, c22_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_d_out, 2U,
          c22_b_sf_marshallOut, c22_b_sf_marshallIn);
        c22_d_out = CV_EML_IF(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0,
          *chartInstance->c22_MedullaCommand, 2.0, -1, 0U,
          *chartInstance->c22_MedullaCommand == 2.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c22_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *chartInstance->c22_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c22_sfEvent);
          *chartInstance->c22_is_c22_Walking01_withElmos = c22_IN_Initialization;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c22_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, *chartInstance->c22_sfEvent);
          *chartInstance->c22_is_Initialization = c22_IN_SwitchOnDisabled;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c22_sfEvent);
          c22_enter_atomic_SwitchOnDisabled(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                       *chartInstance->c22_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c22_sfEvent);
      break;

     default:
      CV_CHART_EVAL(16, 0, 0);
      *chartInstance->c22_is_c22_Walking01_withElmos = c22_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c22_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, *chartInstance->c22_sfEvent);
}

static void initSimStructsc22_Walking01_withElmos
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c22_enter_atomic_Fault(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance)
{
  uint32_T c22_debug_family_var_map[2];
  real_T c22_nargin = 0.0;
  real_T c22_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c22_debug_family_names,
    c22_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargin, 0U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargout, 1U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  *chartInstance->c22_ControlWordIndex = 3.0;
  c22_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_ControlWordIndex, 3U);
  *chartInstance->c22_EnableTargetTorque = 0.0;
  c22_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_EnableTargetTorque, 4U);
  *chartInstance->c22_Timeout = 0.0;
  c22_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_Timeout, 5U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c22_enter_atomic_SwitchOnDisabled
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  uint32_T c22_debug_family_var_map[2];
  real_T c22_nargin = 0.0;
  real_T c22_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c22_c_debug_family_names,
    c22_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargin, 0U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargout, 1U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  *chartInstance->c22_ControlWordIndex = 1.0;
  c22_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_ControlWordIndex, 3U);
  *chartInstance->c22_Timeout = 0.0;
  c22_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_Timeout, 5U);
  *chartInstance->c22_EnableTargetTorque = 0.0;
  c22_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_EnableTargetTorque, 4U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c22_enter_atomic_FaultRunning
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  uint32_T c22_debug_family_var_map[2];
  real_T c22_nargin = 0.0;
  real_T c22_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c22_g_debug_family_names,
    c22_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargin, 0U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargout, 1U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  *chartInstance->c22_ControlWordIndex = 1.0;
  c22_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_ControlWordIndex, 3U);
  *chartInstance->c22_EnableTargetTorque = 0.0;
  c22_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_EnableTargetTorque, 4U);
  *chartInstance->c22_FaultDetected = 1.0;
  c22_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c22_FaultDetected, 7U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c22_Initialization(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance)
{
  uint32_T c22_debug_family_var_map[3];
  real_T c22_nargin = 0.0;
  real_T c22_nargout = 1.0;
  boolean_T c22_out;
  real_T c22_b_nargin = 0.0;
  real_T c22_b_nargout = 1.0;
  boolean_T c22_b_out;
  real_T c22_c_nargin = 0.0;
  real_T c22_c_nargout = 1.0;
  boolean_T c22_c_out;
  uint32_T c22_b_debug_family_var_map[2];
  real_T c22_d_nargin = 0.0;
  real_T c22_d_nargout = 0.0;
  real_T c22_e_nargin = 0.0;
  real_T c22_e_nargout = 1.0;
  boolean_T c22_d_out;
  real_T c22_f_nargin = 0.0;
  real_T c22_f_nargout = 1.0;
  boolean_T c22_e_out;
  real_T c22_g_nargin = 0.0;
  real_T c22_g_nargout = 0.0;
  real_T c22_h_nargin = 0.0;
  real_T c22_h_nargout = 1.0;
  boolean_T c22_f_out;
  real_T c22_i_nargin = 0.0;
  real_T c22_i_nargout = 0.0;
  real_T c22_j_nargin = 0.0;
  real_T c22_j_nargout = 1.0;
  boolean_T c22_g_out;
  real_T c22_k_nargin = 0.0;
  real_T c22_k_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, *chartInstance->c22_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c22_j_debug_family_names,
    c22_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargin, 0U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_nargout, 1U, c22_sf_marshallOut,
    c22_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_out, 2U, c22_b_sf_marshallOut,
    c22_b_sf_marshallIn);
  guard2 = false;
  if (CV_EML_COND(0, 0, 0, CV_RELATIONAL_EVAL(5U, 0U, 0,
        *chartInstance->c22_MedullaCommand, 4.0, -1, 0U,
        *chartInstance->c22_MedullaCommand == 4.0))) {
    guard2 = true;
  } else if (CV_EML_COND(0, 0, 1, CV_RELATIONAL_EVAL(5U, 0U, 1,
               *chartInstance->c22_MedullaCommand, 5.0, -1, 0U,
               *chartInstance->c22_MedullaCommand == 5.0))) {
    guard2 = true;
  } else {
    CV_EML_MCDC(0, 0, 0, false);
    CV_EML_IF(0, 0, 0, false);
    c22_out = false;
  }

  if (guard2 == true) {
    CV_EML_MCDC(0, 0, 0, true);
    CV_EML_IF(0, 0, 0, true);
    c22_out = true;
  }

  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c22_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c22_sfEvent);
    c22_exit_internal_Initialization(chartInstance);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c22_sfEvent);
    *chartInstance->c22_is_c22_Walking01_withElmos = c22_IN_FaultRunning;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c22_sfEvent);
    c22_enter_atomic_FaultRunning(chartInstance);
    guard1 = true;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                 *chartInstance->c22_sfEvent);
    switch (*chartInstance->c22_is_Initialization) {
     case c22_IN_Fault:
      CV_STATE_EVAL(1, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   *chartInstance->c22_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c22_m_debug_family_names,
        c22_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_b_nargin, 0U, c22_sf_marshallOut,
        c22_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_b_nargout, 1U,
        c22_sf_marshallOut, c22_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_b_out, 2U, c22_b_sf_marshallOut,
        c22_b_sf_marshallIn);
      c22_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 107U, 1, 7);
      c22_b_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0,
        *chartInstance->c22_Timeout, 20.0, -1, 5U, *chartInstance->c22_Timeout >=
        20.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c22_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c22_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c22_sfEvent);
        *chartInstance->c22_is_Initialization = c22_IN_Fault;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c22_sfEvent);
        c22_enter_atomic_Fault(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                     *chartInstance->c22_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c22_r_debug_family_names,
          c22_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_c_nargin, 0U,
          c22_sf_marshallOut, c22_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_c_nargout, 1U,
          c22_sf_marshallOut, c22_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_c_out, 2U,
          c22_b_sf_marshallOut, c22_b_sf_marshallIn);
        c22_c_out = CV_EML_IF(11, 0, 0, CV_RELATIONAL_EVAL(5U, 11U, 0, (real_T)
          *chartInstance->c22_SwitchOnDisabledMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c22_SwitchOnDisabledMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c22_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, *chartInstance->c22_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c22_sfEvent);
          *chartInstance->c22_is_Initialization = c22_IN_SwitchOnDisabled;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c22_sfEvent);
          c22_enter_atomic_SwitchOnDisabled(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       *chartInstance->c22_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c22_b_debug_family_names,
            c22_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_d_nargin, 0U,
            c22_sf_marshallOut, c22_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_d_nargout, 1U,
            c22_sf_marshallOut, c22_sf_marshallIn);
          c22_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 96U, 106, 7);
          (*chartInstance->c22_Timeout)++;
          c22_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c22_Timeout, 5U);
          *chartInstance->c22_ControlWordIndex = 0.0;
          c22_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c22_ControlWordIndex, 3U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *chartInstance->c22_sfEvent);
      guard1 = true;
      break;

     case c22_IN_ReadyToSwitchOn:
      CV_STATE_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   *chartInstance->c22_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c22_q_debug_family_names,
        c22_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_e_nargin, 0U, c22_sf_marshallOut,
        c22_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_e_nargout, 1U,
        c22_sf_marshallOut, c22_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_d_out, 2U, c22_b_sf_marshallOut,
        c22_b_sf_marshallIn);
      c22_d_out = CV_EML_IF(10, 0, 0, CV_RELATIONAL_EVAL(5U, 10U, 0, (real_T)
        *chartInstance->c22_FaultMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c22_FaultMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c22_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, *chartInstance->c22_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c22_sfEvent);
        *chartInstance->c22_is_Initialization = c22_IN_Fault;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c22_sfEvent);
        c22_enter_atomic_Fault(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                     *chartInstance->c22_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c22_t_debug_family_names,
          c22_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_f_nargin, 0U,
          c22_sf_marshallOut, c22_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_f_nargout, 1U,
          c22_sf_marshallOut, c22_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_e_out, 2U,
          c22_b_sf_marshallOut, c22_b_sf_marshallIn);
        c22_e_out = CV_EML_IF(13, 0, 0, CV_RELATIONAL_EVAL(5U, 13U, 0, (real_T)
          *chartInstance->c22_SwitchOnDisabledMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c22_SwitchOnDisabledMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c22_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, *chartInstance->c22_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c22_sfEvent);
          *chartInstance->c22_is_Initialization = c22_IN_SwitchOnDisabled;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c22_sfEvent);
          c22_enter_atomic_SwitchOnDisabled(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c22_sfEvent);
          *chartInstance->c22_is_Initialization = c22_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c22_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c22_sfEvent);
          *chartInstance->c22_is_c22_Walking01_withElmos = c22_IN_Running;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c22_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c22_e_debug_family_names,
            c22_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_g_nargin, 0U,
            c22_sf_marshallOut, c22_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_g_nargout, 1U,
            c22_sf_marshallOut, c22_sf_marshallIn);
          *chartInstance->c22_ControlWordIndex = 2.0;
          c22_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c22_ControlWordIndex, 3U);
          *chartInstance->c22_EnableTargetTorque = 1.0;
          c22_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c22_EnableTargetTorque, 4U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c22_sfEvent);
      if (*chartInstance->c22_is_c22_Walking01_withElmos !=
          c22_IN_Initialization) {
      } else {
        guard1 = true;
      }
      break;

     case c22_IN_SwitchOnDisabled:
      CV_STATE_EVAL(1, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   *chartInstance->c22_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c22_k_debug_family_names,
        c22_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_h_nargin, 0U, c22_sf_marshallOut,
        c22_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_h_nargout, 1U,
        c22_sf_marshallOut, c22_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_f_out, 2U, c22_b_sf_marshallOut,
        c22_b_sf_marshallIn);
      c22_f_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, (real_T)
        *chartInstance->c22_ReadyToSwitchOnMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c22_ReadyToSwitchOnMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c22_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c22_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c22_sfEvent);
        *chartInstance->c22_is_Initialization = c22_IN_ReadyToSwitchOn;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c22_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c22_h_debug_family_names,
          c22_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_i_nargin, 0U,
          c22_sf_marshallOut, c22_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_i_nargout, 1U,
          c22_sf_marshallOut, c22_sf_marshallIn);
        *chartInstance->c22_ControlWordIndex = 2.0;
        c22_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c22_ControlWordIndex, 3U);
        *chartInstance->c22_Timeout = 0.0;
        c22_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c22_Timeout, 5U);
        *chartInstance->c22_EnableTargetTorque = 0.0;
        c22_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c22_EnableTargetTorque, 4U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                     *chartInstance->c22_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c22_o_debug_family_names,
          c22_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_j_nargin, 0U,
          c22_sf_marshallOut, c22_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_j_nargout, 1U,
          c22_sf_marshallOut, c22_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_g_out, 2U,
          c22_b_sf_marshallOut, c22_b_sf_marshallIn);
        c22_g_out = CV_EML_IF(7, 0, 0, CV_RELATIONAL_EVAL(5U, 7U, 0, (real_T)
          *chartInstance->c22_FaultMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c22_FaultMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c22_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, *chartInstance->c22_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c22_sfEvent);
          *chartInstance->c22_is_Initialization = c22_IN_Fault;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c22_sfEvent);
          c22_enter_atomic_Fault(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                       *chartInstance->c22_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c22_d_debug_family_names,
            c22_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_k_nargin, 0U,
            c22_sf_marshallOut, c22_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c22_k_nargout, 1U,
            c22_sf_marshallOut, c22_sf_marshallIn);
          c22_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 97U, 117, 7);
          (*chartInstance->c22_Timeout)++;
          c22_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c22_Timeout, 5U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *chartInstance->c22_sfEvent);
      guard1 = true;
      break;

     default:
      CV_STATE_EVAL(1, 0, 0);
      *chartInstance->c22_is_Initialization = c22_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c22_sfEvent);
      guard1 = true;
      break;
    }
  }

  if (guard1 == true) {
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c22_sfEvent);
  }
}

static void c22_exit_internal_Initialization
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance)
{
  switch (*chartInstance->c22_is_Initialization) {
   case c22_IN_Fault:
    CV_STATE_EVAL(1, 1, 1);
    *chartInstance->c22_is_Initialization = c22_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c22_sfEvent);
    break;

   case c22_IN_ReadyToSwitchOn:
    CV_STATE_EVAL(1, 1, 2);
    *chartInstance->c22_is_Initialization = c22_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c22_sfEvent);
    break;

   case c22_IN_SwitchOnDisabled:
    CV_STATE_EVAL(1, 1, 3);
    *chartInstance->c22_is_Initialization = c22_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c22_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    *chartInstance->c22_is_Initialization = c22_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c22_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c22_machineNumber, uint32_T
  c22_chartNumber, uint32_T c22_instanceNumber)
{
  (void)c22_machineNumber;
  (void)c22_chartNumber;
  (void)c22_instanceNumber;
}

static const mxArray *c22_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  real_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc22_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(real_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static real_T c22_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_nargout, const char_T *c22_identifier)
{
  real_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_nargout),
    &c22_thisId);
  sf_mex_destroy(&c22_nargout);
  return c22_y;
}

static real_T c22_b_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  real_T c22_y;
  real_T c22_d0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_d0, 1, 0, 0U, 0, 0U, 0);
  c22_y = c22_d0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_nargout;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  real_T c22_y;
  SFc22_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc22_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c22_nargout = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_nargout),
    &c22_thisId);
  sf_mex_destroy(&c22_nargout);
  *(real_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_b_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  boolean_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc22_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(boolean_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static boolean_T c22_c_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct *
  chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  boolean_T c22_y;
  boolean_T c22_b0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_b0, 1, 11, 0U, 0, 0U, 0);
  c22_y = c22_b0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_sf_internal_predicateOutput;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  boolean_T c22_y;
  SFc22_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc22_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c22_sf_internal_predicateOutput = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_sf_internal_predicateOutput), &c22_thisId);
  sf_mex_destroy(&c22_sf_internal_predicateOutput);
  *(boolean_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

const mxArray *sf_c22_Walking01_withElmos_get_eml_resolved_functions_info(void)
{
  const mxArray *c22_nameCaptureInfo = NULL;
  c22_nameCaptureInfo = NULL;
  sf_mex_assign(&c22_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c22_nameCaptureInfo;
}

static const mxArray *c22_c_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  int32_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc22_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(int32_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static int32_T c22_d_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  int32_T c22_y;
  int32_T c22_i2;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_i2, 1, 6, 0U, 0, 0U, 0);
  c22_y = c22_i2;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_sfEvent;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  int32_T c22_y;
  SFc22_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc22_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c22_b_sfEvent = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_sfEvent),
    &c22_thisId);
  sf_mex_destroy(&c22_b_sfEvent);
  *(int32_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static const mxArray *c22_d_sf_marshallOut(void *chartInstanceVoid, void
  *c22_inData)
{
  const mxArray *c22_mxArrayOutData = NULL;
  uint8_T c22_u;
  const mxArray *c22_y = NULL;
  SFc22_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc22_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c22_mxArrayOutData = NULL;
  c22_u = *(uint8_T *)c22_inData;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_create("y", &c22_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c22_mxArrayOutData, c22_y, false);
  return c22_mxArrayOutData;
}

static uint8_T c22_e_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_b_is_Initialization, const char_T
  *c22_identifier)
{
  uint8_T c22_y;
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_b_is_Initialization), &c22_thisId);
  sf_mex_destroy(&c22_b_is_Initialization);
  return c22_y;
}

static uint8_T c22_f_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId)
{
  uint8_T c22_y;
  uint8_T c22_u0;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), &c22_u0, 1, 3, 0U, 0, 0U, 0);
  c22_y = c22_u0;
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c22_mxArrayInData, const char_T *c22_varName, void *c22_outData)
{
  const mxArray *c22_b_is_Initialization;
  const char_T *c22_identifier;
  emlrtMsgIdentifier c22_thisId;
  uint8_T c22_y;
  SFc22_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc22_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c22_b_is_Initialization = sf_mex_dup(c22_mxArrayInData);
  c22_identifier = c22_varName;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_y = c22_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_b_is_Initialization), &c22_thisId);
  sf_mex_destroy(&c22_b_is_Initialization);
  *(uint8_T *)c22_outData = c22_y;
  sf_mex_destroy(&c22_mxArrayInData);
}

static void c22_g_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_b_dataWrittenToVector, const char_T
  *c22_identifier, boolean_T c22_y[4])
{
  emlrtMsgIdentifier c22_thisId;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  c22_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c22_b_dataWrittenToVector),
    &c22_thisId, c22_y);
  sf_mex_destroy(&c22_b_dataWrittenToVector);
}

static void c22_h_emlrt_marshallIn(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c22_u, const emlrtMsgIdentifier *c22_parentId,
  boolean_T c22_y[4])
{
  boolean_T c22_bv1[4];
  int32_T c22_i3;
  (void)chartInstance;
  sf_mex_import(c22_parentId, sf_mex_dup(c22_u), c22_bv1, 1, 11, 0U, 1, 0U, 1, 4);
  for (c22_i3 = 0; c22_i3 < 4; c22_i3++) {
    c22_y[c22_i3] = c22_bv1[c22_i3];
  }

  sf_mex_destroy(&c22_u);
}

static const mxArray *c22_i_emlrt_marshallIn
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance, const mxArray
   *c22_b_setSimStateSideEffectsInfo, const char_T *c22_identifier)
{
  const mxArray *c22_y = NULL;
  emlrtMsgIdentifier c22_thisId;
  c22_y = NULL;
  c22_thisId.fIdentifier = c22_identifier;
  c22_thisId.fParent = NULL;
  sf_mex_assign(&c22_y, c22_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c22_b_setSimStateSideEffectsInfo), &c22_thisId), false);
  sf_mex_destroy(&c22_b_setSimStateSideEffectsInfo);
  return c22_y;
}

static const mxArray *c22_j_emlrt_marshallIn
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance, const mxArray *c22_u,
   const emlrtMsgIdentifier *c22_parentId)
{
  const mxArray *c22_y = NULL;
  (void)chartInstance;
  (void)c22_parentId;
  c22_y = NULL;
  sf_mex_assign(&c22_y, sf_mex_duplicatearraysafe(&c22_u), false);
  sf_mex_destroy(&c22_u);
  return c22_y;
}

static void c22_updateDataWrittenToVector
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance, uint32_T
   c22_vectorIndex)
{
  chartInstance->c22_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK
    (0U, (int32_T)c22_vectorIndex, 0, 3, 1, 0)] = true;
}

static void c22_errorIfDataNotWrittenToFcn
  (SFc22_Walking01_withElmosInstanceStruct *chartInstance, uint32_T
   c22_vectorIndex, uint32_T c22_dataNumber, uint32_T c22_ssIdOfSourceObject,
   int32_T c22_offsetInSourceObject, int32_T c22_lengthInSourceObject)
{
  (void)c22_ssIdOfSourceObject;
  (void)c22_offsetInSourceObject;
  (void)c22_lengthInSourceObject;
  if (!chartInstance->c22_dataWrittenToVector[(uint32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK(0U, (int32_T)c22_vectorIndex, 0, 3, 1, 0)]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(c22_dataNumber);
  }
}

static void init_dsm_address_info(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc22_Walking01_withElmosInstanceStruct
  *chartInstance)
{
  chartInstance->c22_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c22_isStable = (boolean_T *)ssGetDWork_wrapper(chartInstance->S,
    1);
  chartInstance->c22_is_active_c22_Walking01_withElmos = (uint8_T *)
    ssGetDWork_wrapper(chartInstance->S, 2);
  chartInstance->c22_is_c22_Walking01_withElmos = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 3);
  chartInstance->c22_is_Initialization = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 4);
  chartInstance->c22_SwitchOnDisabledMode = (boolean_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c22_EnabledMode = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c22_ReadyToSwitchOnMode = (boolean_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c22_ControlWordIndex = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c22_EnableTargetTorque = (real_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c22_Timeout = (real_T *)ssGetDWork_wrapper(chartInstance->S, 5);
  chartInstance->c22_FaultMode = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c22_FaultDetected = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c22_MedullaCommand = (real_T *)ssGetInputPortSignal_wrapper
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
void sf_c22_Walking01_withElmos_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(298181604U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1095340483U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2168962230U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(106802920U);
}

mxArray* sf_c22_Walking01_withElmos_get_post_codegen_info(void);
mxArray *sf_c22_Walking01_withElmos_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("rj1C1AAyi8bTYSFUaqYqDD");
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
    mxArray* mxPostCodegenInfo =
      sf_c22_Walking01_withElmos_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c22_Walking01_withElmos_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c22_Walking01_withElmos_jit_fallback_info(void)
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

mxArray *sf_c22_Walking01_withElmos_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c22_Walking01_withElmos_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c22_Walking01_withElmos(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[23],T\"ControlWordIndex\",},{M[1],M[24],T\"EnableTargetTorque\",},{M[1],M[64],T\"FaultDetected\",},{M[3],M[25],T\"Timeout\",},{M[8],M[0],T\"is_active_c22_Walking01_withElmos\",},{M[9],M[0],T\"is_c22_Walking01_withElmos\",},{M[9],M[111],T\"is_Initialization\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c22_Walking01_withElmos_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc22_Walking01_withElmosInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc22_Walking01_withElmosInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_withElmosMachineNumber_,
           22,
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
        init_script_number_translation(_Walking01_withElmosMachineNumber_,
          chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Walking01_withElmosMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Walking01_withElmosMachineNumber_,
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
        _SFD_CV_INIT_TRANS(12,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(3,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(9,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(1,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(7,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(13,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(11,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);
        _SFD_CV_INIT_TRANS(10,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(2,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(4,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(5,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(6,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(0,1,0,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML(3,1,0,0,0,0,0,0,0,0,0);
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
        _SFD_CV_INIT_EML(2,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(2,0,0,1,25,1,25);
        _SFD_CV_INIT_EML_RELATIONAL(2,0,0,1,25,-1,0);
        _SFD_CV_INIT_EML(3,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(3,0,0,1,15,1,15);
        _SFD_CV_INIT_EML_RELATIONAL(3,0,0,1,15,-1,0);
        _SFD_CV_INIT_EML(5,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(5,0,0,1,13,1,13);
        _SFD_CV_INIT_EML_RELATIONAL(5,0,0,1,13,-1,5);
        _SFD_CV_INIT_EML(6,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(6,0,0,1,20,1,20);
        _SFD_CV_INIT_EML_RELATIONAL(6,0,0,1,20,-1,0);
        _SFD_CV_INIT_EML(7,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(7,0,0,1,15,1,15);
        _SFD_CV_INIT_EML_RELATIONAL(7,0,0,1,15,-1,0);
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
        _SFD_CV_INIT_EML(10,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(10,0,0,1,15,1,15);
        _SFD_CV_INIT_EML_RELATIONAL(10,0,0,1,15,-1,0);
        _SFD_CV_INIT_EML(11,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(11,0,0,1,26,1,26);
        _SFD_CV_INIT_EML_RELATIONAL(11,0,0,1,26,-1,0);
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
        _SFD_CV_INIT_EML(13,0,0,1,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_IF(13,0,0,1,26,1,26);
        _SFD_CV_INIT_EML_RELATIONAL(13,0,0,1,26,-1,0);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)c22_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)c22_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)c22_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)c22_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c22_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c22_SwitchOnDisabledMode);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c22_EnabledMode);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c22_ReadyToSwitchOnMode);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c22_ControlWordIndex);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c22_EnableTargetTorque);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c22_Timeout);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c22_FaultMode);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c22_FaultDetected);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c22_MedullaCommand);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Walking01_withElmosMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "7eY2IeKhDwzszN3wGMiYCE";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_Walking01_withElmos_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 22, "dworkChecksum");
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

static void sf_opaque_initialize_c22_Walking01_withElmos(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc22_Walking01_withElmosInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc22_Walking01_withElmosInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c22_Walking01_withElmos
    ((SFc22_Walking01_withElmosInstanceStruct*) chartInstanceVar);
  initialize_c22_Walking01_withElmos((SFc22_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c22_Walking01_withElmos(void *chartInstanceVar)
{
  enable_c22_Walking01_withElmos((SFc22_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c22_Walking01_withElmos(void *chartInstanceVar)
{
  disable_c22_Walking01_withElmos((SFc22_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c22_Walking01_withElmos(void *chartInstanceVar)
{
  sf_gateway_c22_Walking01_withElmos((SFc22_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c22_Walking01_withElmos(void
  *chartInstanceVar)
{
  ext_mode_exec_c22_Walking01_withElmos((SFc22_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c22_Walking01_withElmos(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c22_Walking01_withElmos
    ((SFc22_Walking01_withElmosInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c22_Walking01_withElmos(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c22_Walking01_withElmos((SFc22_Walking01_withElmosInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c22_Walking01_withElmos(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc22_Walking01_withElmosInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_withElmos_optimization_info();
    }

    finalize_c22_Walking01_withElmos((SFc22_Walking01_withElmosInstanceStruct*)
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
  initSimStructsc22_Walking01_withElmos((SFc22_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c22_Walking01_withElmos(SimStruct *S)
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
    initialize_params_c22_Walking01_withElmos
      ((SFc22_Walking01_withElmosInstanceStruct*)(chartInfo->chartInstance));
  }
}

mxArray *sf_c22_Walking01_withElmos_get_testpoint_info(void)
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

static void mdlSetWorkWidths_c22_Walking01_withElmos(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_withElmos_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      22);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,22,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,22,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,22);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,22,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,22,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,22);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(965790858U));
  ssSetChecksum1(S,(197827121U));
  ssSetChecksum2(S,(235667161U));
  ssSetChecksum3(S,(2182178103U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c22_Walking01_withElmos(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c22_Walking01_withElmos(SimStruct *S)
{
  SFc22_Walking01_withElmosInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc22_Walking01_withElmosInstanceStruct *)utMalloc(sizeof
    (SFc22_Walking01_withElmosInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc22_Walking01_withElmosInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c22_Walking01_withElmos;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c22_Walking01_withElmos;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c22_Walking01_withElmos;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c22_Walking01_withElmos;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c22_Walking01_withElmos;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c22_Walking01_withElmos;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c22_Walking01_withElmos;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c22_Walking01_withElmos;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c22_Walking01_withElmos;
  chartInstance->chartInfo.mdlStart = mdlStart_c22_Walking01_withElmos;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c22_Walking01_withElmos;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c22_Walking01_withElmos;
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

void c22_Walking01_withElmos_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c22_Walking01_withElmos(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c22_Walking01_withElmos(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c22_Walking01_withElmos(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c22_Walking01_withElmos_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
