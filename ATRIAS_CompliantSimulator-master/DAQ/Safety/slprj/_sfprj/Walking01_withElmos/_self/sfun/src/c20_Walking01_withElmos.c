/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_withElmos_sfun.h"
#include "c20_Walking01_withElmos.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Walking01_withElmos_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c20_IN_NO_ACTIVE_CHILD         ((uint8_T)0U)
#define c20_IN_FaultRunning            ((uint8_T)1U)
#define c20_IN_Initialization          ((uint8_T)2U)
#define c20_IN_Running                 ((uint8_T)3U)
#define c20_IN_Start1                  ((uint8_T)4U)
#define c20_IN_Fault                   ((uint8_T)1U)
#define c20_IN_ReadyToSwitchOn         ((uint8_T)2U)
#define c20_IN_SwitchOnDisabled        ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c20_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_b_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_c_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_d_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_e_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_f_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_g_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_h_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_i_debug_family_names[2] = { "nargin", "nargout" };

static const char * c20_j_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_k_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_l_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_m_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_n_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_o_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_p_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_q_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_r_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_s_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_t_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_u_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_v_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_w_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_x_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_y_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_ab_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_bb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_cb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_db_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_eb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

static const char * c20_fb_debug_family_names[3] = { "nargin", "nargout",
  "sf_internal_predicateOutput" };

/* Function Declarations */
static void initialize_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void initialize_params_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void enable_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void disable_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void c20_update_debugger_state_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void ext_mode_exec_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void set_sim_state_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance, const mxArray *c20_st);
static void c20_set_sim_state_side_effects_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void finalize_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void sf_gateway_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void mdl_start_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void c20_chartstep_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void initSimStructsc20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void c20_enter_atomic_Fault(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance);
static void c20_enter_atomic_SwitchOnDisabled
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void c20_enter_atomic_FaultRunning
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void c20_Initialization(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance);
static void c20_exit_internal_Initialization
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber);
static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static real_T c20_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_nargout, const char_T *c20_identifier);
static real_T c20_b_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static boolean_T c20_c_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct *
  chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static int32_T c20_d_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData);
static uint8_T c20_e_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_b_is_Initialization, const char_T
  *c20_identifier);
static uint8_T c20_f_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId);
static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData);
static void c20_g_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_b_dataWrittenToVector, const char_T
  *c20_identifier, boolean_T c20_y[4]);
static void c20_h_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  boolean_T c20_y[4]);
static const mxArray *c20_i_emlrt_marshallIn
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance, const mxArray
   *c20_b_setSimStateSideEffectsInfo, const char_T *c20_identifier);
static const mxArray *c20_j_emlrt_marshallIn
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance, const mxArray *c20_u,
   const emlrtMsgIdentifier *c20_parentId);
static void c20_updateDataWrittenToVector
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance, uint32_T
   c20_vectorIndex);
static void c20_errorIfDataNotWrittenToFcn
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance, uint32_T
   c20_vectorIndex, uint32_T c20_dataNumber, uint32_T c20_ssIdOfSourceObject,
   int32_T c20_offsetInSourceObject, int32_T c20_lengthInSourceObject);
static void init_dsm_address_info(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  *chartInstance->c20_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c20_doSetSimStateSideEffects = 0U;
  chartInstance->c20_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c20_is_Initialization = c20_IN_NO_ACTIVE_CHILD;
  *chartInstance->c20_is_active_c20_Walking01_withElmos = 0U;
  *chartInstance->c20_is_c20_Walking01_withElmos = c20_IN_NO_ACTIVE_CHILD;
}

static void initialize_params_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c20_update_debugger_state_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  uint32_T c20_prevAniVal;
  c20_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c20_is_active_c20_Walking01_withElmos == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 14U, *chartInstance->c20_sfEvent);
  }

  if (*chartInstance->c20_is_Initialization == c20_IN_Fault) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c20_sfEvent);
  }

  if (*chartInstance->c20_is_Initialization == c20_IN_SwitchOnDisabled) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c20_sfEvent);
  }

  if (*chartInstance->c20_is_c20_Walking01_withElmos == c20_IN_Running) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c20_sfEvent);
  }

  if (*chartInstance->c20_is_c20_Walking01_withElmos == c20_IN_Start1) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c20_sfEvent);
  }

  if (*chartInstance->c20_is_c20_Walking01_withElmos == c20_IN_FaultRunning) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c20_sfEvent);
  }

  if (*chartInstance->c20_is_c20_Walking01_withElmos == c20_IN_Initialization) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c20_sfEvent);
  }

  if (*chartInstance->c20_is_Initialization == c20_IN_ReadyToSwitchOn) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c20_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c20_sfEvent);
  }

  _SFD_SET_ANIMATION(c20_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  c20_update_debugger_state_c20_Walking01_withElmos(chartInstance);
}

static const mxArray *get_sim_state_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  const mxArray *c20_st;
  const mxArray *c20_y = NULL;
  real_T c20_hoistedGlobal;
  real_T c20_u;
  const mxArray *c20_b_y = NULL;
  real_T c20_b_hoistedGlobal;
  real_T c20_b_u;
  const mxArray *c20_c_y = NULL;
  real_T c20_c_hoistedGlobal;
  real_T c20_c_u;
  const mxArray *c20_d_y = NULL;
  real_T c20_d_hoistedGlobal;
  real_T c20_d_u;
  const mxArray *c20_e_y = NULL;
  uint8_T c20_e_hoistedGlobal;
  uint8_T c20_e_u;
  const mxArray *c20_f_y = NULL;
  uint8_T c20_f_hoistedGlobal;
  uint8_T c20_f_u;
  const mxArray *c20_g_y = NULL;
  uint8_T c20_g_hoistedGlobal;
  uint8_T c20_g_u;
  const mxArray *c20_h_y = NULL;
  int32_T c20_i0;
  boolean_T c20_h_u[4];
  const mxArray *c20_i_y = NULL;
  c20_st = NULL;
  c20_st = NULL;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_createcellmatrix(8, 1), false);
  c20_hoistedGlobal = *chartInstance->c20_ControlWordIndex;
  c20_u = c20_hoistedGlobal;
  c20_b_y = NULL;
  sf_mex_assign(&c20_b_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 0, c20_b_y);
  c20_b_hoistedGlobal = *chartInstance->c20_EnableTargetTorque;
  c20_b_u = c20_b_hoistedGlobal;
  c20_c_y = NULL;
  sf_mex_assign(&c20_c_y, sf_mex_create("y", &c20_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 1, c20_c_y);
  c20_c_hoistedGlobal = *chartInstance->c20_FaultDetected;
  c20_c_u = c20_c_hoistedGlobal;
  c20_d_y = NULL;
  sf_mex_assign(&c20_d_y, sf_mex_create("y", &c20_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 2, c20_d_y);
  c20_d_hoistedGlobal = *chartInstance->c20_Timeout;
  c20_d_u = c20_d_hoistedGlobal;
  c20_e_y = NULL;
  sf_mex_assign(&c20_e_y, sf_mex_create("y", &c20_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 3, c20_e_y);
  c20_e_hoistedGlobal = *chartInstance->c20_is_active_c20_Walking01_withElmos;
  c20_e_u = c20_e_hoistedGlobal;
  c20_f_y = NULL;
  sf_mex_assign(&c20_f_y, sf_mex_create("y", &c20_e_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 4, c20_f_y);
  c20_f_hoistedGlobal = *chartInstance->c20_is_c20_Walking01_withElmos;
  c20_f_u = c20_f_hoistedGlobal;
  c20_g_y = NULL;
  sf_mex_assign(&c20_g_y, sf_mex_create("y", &c20_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 5, c20_g_y);
  c20_g_hoistedGlobal = *chartInstance->c20_is_Initialization;
  c20_g_u = c20_g_hoistedGlobal;
  c20_h_y = NULL;
  sf_mex_assign(&c20_h_y, sf_mex_create("y", &c20_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c20_y, 6, c20_h_y);
  for (c20_i0 = 0; c20_i0 < 4; c20_i0++) {
    c20_h_u[c20_i0] = chartInstance->c20_dataWrittenToVector[c20_i0];
  }

  c20_i_y = NULL;
  sf_mex_assign(&c20_i_y, sf_mex_create("y", c20_h_u, 11, 0U, 1U, 0U, 1, 4),
                false);
  sf_mex_setcell(c20_y, 7, c20_i_y);
  sf_mex_assign(&c20_st, c20_y, false);
  return c20_st;
}

static void set_sim_state_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance, const mxArray *c20_st)
{
  const mxArray *c20_u;
  boolean_T c20_bv0[4];
  int32_T c20_i1;
  c20_u = sf_mex_dup(c20_st);
  *chartInstance->c20_ControlWordIndex = c20_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c20_u, 0)), "ControlWordIndex");
  *chartInstance->c20_EnableTargetTorque = c20_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c20_u, 1)), "EnableTargetTorque");
  *chartInstance->c20_FaultDetected = c20_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c20_u, 2)), "FaultDetected");
  *chartInstance->c20_Timeout = c20_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c20_u, 3)), "Timeout");
  *chartInstance->c20_is_active_c20_Walking01_withElmos = c20_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 4)),
     "is_active_c20_Walking01_withElmos");
  *chartInstance->c20_is_c20_Walking01_withElmos = c20_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 5)),
     "is_c20_Walking01_withElmos");
  *chartInstance->c20_is_Initialization = c20_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c20_u, 6)), "is_Initialization");
  c20_g_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c20_u, 7)),
    "dataWrittenToVector", c20_bv0);
  for (c20_i1 = 0; c20_i1 < 4; c20_i1++) {
    chartInstance->c20_dataWrittenToVector[c20_i1] = c20_bv0[c20_i1];
  }

  sf_mex_assign(&chartInstance->c20_setSimStateSideEffectsInfo,
                c20_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c20_u, 8)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c20_u);
  chartInstance->c20_doSetSimStateSideEffects = 1U;
  c20_update_debugger_state_c20_Walking01_withElmos(chartInstance);
  sf_mex_destroy(&c20_st);
}

static void c20_set_sim_state_side_effects_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  if (chartInstance->c20_doSetSimStateSideEffects != 0) {
    chartInstance->c20_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  sf_mex_destroy(&chartInstance->c20_setSimStateSideEffectsInfo);
}

static void sf_gateway_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  c20_set_sim_state_side_effects_c20_Walking01_withElmos(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 14U, *chartInstance->c20_sfEvent);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_SwitchOnDisabledMode, 0U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_EnabledMode, 1U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_ReadyToSwitchOnMode, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_ControlWordIndex, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_EnableTargetTorque, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_Timeout, 5U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c20_FaultMode, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_FaultDetected, 7U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_MedullaCommand, 8U);
  *chartInstance->c20_sfEvent = CALL_EVENT;
  c20_chartstep_c20_Walking01_withElmos(chartInstance);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_withElmosMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c20_chartstep_c20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  uint32_T c20_b_debug_family_var_map[3];
  real_T c20_b_nargin = 0.0;
  real_T c20_b_nargout = 1.0;
  boolean_T c20_out;
  real_T c20_c_nargin = 0.0;
  real_T c20_c_nargout = 1.0;
  boolean_T c20_b_out;
  real_T c20_d_nargin = 0.0;
  real_T c20_d_nargout = 1.0;
  boolean_T c20_c_out;
  real_T c20_e_nargin = 0.0;
  real_T c20_e_nargout = 1.0;
  boolean_T c20_d_out;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 14U, *chartInstance->c20_sfEvent);
  if (*chartInstance->c20_is_active_c20_Walking01_withElmos == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 14U,
                 *chartInstance->c20_sfEvent);
    *chartInstance->c20_is_active_c20_Walking01_withElmos = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, *chartInstance->c20_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c20_sfEvent);
    *chartInstance->c20_is_c20_Walking01_withElmos = c20_IN_Start1;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 6U, *chartInstance->c20_sfEvent);
    _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_f_debug_family_names,
      c20_debug_family_var_map);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_sf_marshallOut,
      c20_sf_marshallIn);
    _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_sf_marshallOut,
      c20_sf_marshallIn);
    *chartInstance->c20_ControlWordIndex = 0.0;
    c20_updateDataWrittenToVector(chartInstance, 0U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c20_ControlWordIndex, 3U);
    *chartInstance->c20_EnableTargetTorque = 0.0;
    c20_updateDataWrittenToVector(chartInstance, 1U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c20_EnableTargetTorque, 4U);
    *chartInstance->c20_FaultDetected = 0.0;
    c20_updateDataWrittenToVector(chartInstance, 3U);
    _SFD_DATA_RANGE_CHECK(*chartInstance->c20_FaultDetected, 7U);
    _SFD_SYMBOL_SCOPE_POP();
  } else {
    switch (*chartInstance->c20_is_c20_Walking01_withElmos) {
     case c20_IN_FaultRunning:
      CV_CHART_EVAL(14, 0, 1);
      _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                   *chartInstance->c20_sfEvent);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c20_sfEvent);
      break;

     case c20_IN_Initialization:
      CV_CHART_EVAL(14, 0, 2);
      c20_Initialization(chartInstance);
      break;

     case c20_IN_Running:
      CV_CHART_EVAL(14, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   *chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_l_debug_family_names,
        c20_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 0U, c20_sf_marshallOut,
        c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 1U,
        c20_sf_marshallOut, c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_out, 2U, c20_b_sf_marshallOut,
        c20_b_sf_marshallIn);
      c20_out = CV_EML_IF(3, 0, 0, CV_RELATIONAL_EVAL(5U, 3U, 0, (real_T)
        *chartInstance->c20_FaultMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c20_FaultMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c20_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c20_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c20_sfEvent);
        *chartInstance->c20_is_c20_Walking01_withElmos = c20_IN_FaultRunning;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c20_sfEvent);
        c20_enter_atomic_FaultRunning(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 9U,
                     *chartInstance->c20_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_p_debug_family_names,
          c20_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargin, 0U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargout, 1U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_out, 2U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        guard2 = false;
        if (CV_EML_COND(9, 0, 0, CV_RELATIONAL_EVAL(5U, 9U, 0,
              *chartInstance->c20_MedullaCommand, 4.0, -1, 0U,
              *chartInstance->c20_MedullaCommand == 4.0))) {
          guard2 = true;
        } else if (CV_EML_COND(9, 0, 1, CV_RELATIONAL_EVAL(5U, 9U, 1,
                     *chartInstance->c20_MedullaCommand, 5.0, -1, 0U,
                     *chartInstance->c20_MedullaCommand == 5.0))) {
          guard2 = true;
        } else {
          CV_EML_MCDC(9, 0, 0, false);
          CV_EML_IF(9, 0, 0, false);
          c20_b_out = false;
        }

        if (guard2 == true) {
          CV_EML_MCDC(9, 0, 0, true);
          CV_EML_IF(9, 0, 0, true);
          c20_b_out = true;
        }

        _SFD_SYMBOL_SCOPE_POP();
        if (c20_b_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 9U, *chartInstance->c20_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 5U, *chartInstance->c20_sfEvent);
          *chartInstance->c20_is_c20_Walking01_withElmos = c20_IN_FaultRunning;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c20_sfEvent);
          c20_enter_atomic_FaultRunning(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 5U,
                       *chartInstance->c20_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 5U, *chartInstance->c20_sfEvent);
      break;

     case c20_IN_Start1:
      CV_CHART_EVAL(14, 0, 4);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 12U,
                   *chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_s_debug_family_names,
        c20_b_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargin, 0U, c20_sf_marshallOut,
        c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargout, 1U,
        c20_sf_marshallOut, c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_out, 2U, c20_b_sf_marshallOut,
        c20_b_sf_marshallIn);
      guard1 = false;
      if (CV_EML_COND(12, 0, 0, CV_RELATIONAL_EVAL(5U, 12U, 0,
            *chartInstance->c20_MedullaCommand, 4.0, -1, 0U,
            *chartInstance->c20_MedullaCommand == 4.0))) {
        guard1 = true;
      } else if (CV_EML_COND(12, 0, 1, CV_RELATIONAL_EVAL(5U, 12U, 1,
                   *chartInstance->c20_MedullaCommand, 5.0, -1, 0U,
                   *chartInstance->c20_MedullaCommand == 5.0))) {
        guard1 = true;
      } else {
        CV_EML_MCDC(12, 0, 0, false);
        CV_EML_IF(12, 0, 0, false);
        c20_c_out = false;
      }

      if (guard1 == true) {
        CV_EML_MCDC(12, 0, 0, true);
        CV_EML_IF(12, 0, 0, true);
        c20_c_out = true;
      }

      _SFD_SYMBOL_SCOPE_POP();
      if (c20_c_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 12U, *chartInstance->c20_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c20_sfEvent);
        *chartInstance->c20_is_c20_Walking01_withElmos = c20_IN_FaultRunning;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c20_sfEvent);
        c20_enter_atomic_FaultRunning(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     *chartInstance->c20_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_n_debug_family_names,
          c20_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargin, 0U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargout, 1U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_out, 2U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        c20_d_out = CV_EML_IF(6, 0, 0, CV_RELATIONAL_EVAL(5U, 6U, 0,
          *chartInstance->c20_MedullaCommand, 2.0, -1, 0U,
          *chartInstance->c20_MedullaCommand == 2.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c20_d_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *chartInstance->c20_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 6U, *chartInstance->c20_sfEvent);
          *chartInstance->c20_is_c20_Walking01_withElmos = c20_IN_Initialization;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c20_sfEvent);
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, *chartInstance->c20_sfEvent);
          *chartInstance->c20_is_Initialization = c20_IN_SwitchOnDisabled;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c20_sfEvent);
          c20_enter_atomic_SwitchOnDisabled(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 6U,
                       *chartInstance->c20_sfEvent);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c20_sfEvent);
      break;

     default:
      CV_CHART_EVAL(14, 0, 0);
      *chartInstance->c20_is_c20_Walking01_withElmos = c20_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c20_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 14U, *chartInstance->c20_sfEvent);
}

static void initSimStructsc20_Walking01_withElmos
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void c20_enter_atomic_Fault(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  *chartInstance->c20_ControlWordIndex = 3.0;
  c20_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_ControlWordIndex, 3U);
  *chartInstance->c20_EnableTargetTorque = 0.0;
  c20_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_EnableTargetTorque, 4U);
  *chartInstance->c20_Timeout = 0.0;
  c20_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_Timeout, 5U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_enter_atomic_SwitchOnDisabled
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_c_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  *chartInstance->c20_ControlWordIndex = 1.0;
  c20_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_ControlWordIndex, 3U);
  *chartInstance->c20_Timeout = 0.0;
  c20_updateDataWrittenToVector(chartInstance, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_Timeout, 5U);
  *chartInstance->c20_EnableTargetTorque = 0.0;
  c20_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_EnableTargetTorque, 4U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_enter_atomic_FaultRunning
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  uint32_T c20_debug_family_var_map[2];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 0.0;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_g_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  *chartInstance->c20_ControlWordIndex = 1.0;
  c20_updateDataWrittenToVector(chartInstance, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_ControlWordIndex, 3U);
  *chartInstance->c20_EnableTargetTorque = 0.0;
  c20_updateDataWrittenToVector(chartInstance, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_EnableTargetTorque, 4U);
  *chartInstance->c20_FaultDetected = 1.0;
  c20_updateDataWrittenToVector(chartInstance, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c20_FaultDetected, 7U);
  _SFD_SYMBOL_SCOPE_POP();
}

static void c20_Initialization(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance)
{
  uint32_T c20_debug_family_var_map[3];
  real_T c20_nargin = 0.0;
  real_T c20_nargout = 1.0;
  boolean_T c20_out;
  real_T c20_b_nargin = 0.0;
  real_T c20_b_nargout = 1.0;
  boolean_T c20_b_out;
  real_T c20_c_nargin = 0.0;
  real_T c20_c_nargout = 1.0;
  boolean_T c20_c_out;
  uint32_T c20_b_debug_family_var_map[2];
  real_T c20_d_nargin = 0.0;
  real_T c20_d_nargout = 0.0;
  real_T c20_e_nargin = 0.0;
  real_T c20_e_nargout = 1.0;
  boolean_T c20_d_out;
  real_T c20_f_nargin = 0.0;
  real_T c20_f_nargout = 1.0;
  boolean_T c20_e_out;
  real_T c20_g_nargin = 0.0;
  real_T c20_g_nargout = 0.0;
  real_T c20_h_nargin = 0.0;
  real_T c20_h_nargout = 1.0;
  boolean_T c20_f_out;
  real_T c20_i_nargin = 0.0;
  real_T c20_i_nargout = 0.0;
  real_T c20_j_nargin = 0.0;
  real_T c20_j_nargout = 1.0;
  boolean_T c20_g_out;
  real_T c20_k_nargin = 0.0;
  real_T c20_k_nargout = 0.0;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U, *chartInstance->c20_sfEvent);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_j_debug_family_names,
    c20_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargin, 0U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_nargout, 1U, c20_sf_marshallOut,
    c20_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_out, 2U, c20_b_sf_marshallOut,
    c20_b_sf_marshallIn);
  guard2 = false;
  if (CV_EML_COND(0, 0, 0, CV_RELATIONAL_EVAL(5U, 0U, 0,
        *chartInstance->c20_MedullaCommand, 4.0, -1, 0U,
        *chartInstance->c20_MedullaCommand == 4.0))) {
    guard2 = true;
  } else if (CV_EML_COND(0, 0, 1, CV_RELATIONAL_EVAL(5U, 0U, 1,
               *chartInstance->c20_MedullaCommand, 5.0, -1, 0U,
               *chartInstance->c20_MedullaCommand == 5.0))) {
    guard2 = true;
  } else {
    CV_EML_MCDC(0, 0, 0, false);
    CV_EML_IF(0, 0, 0, false);
    c20_out = false;
  }

  if (guard2 == true) {
    CV_EML_MCDC(0, 0, 0, true);
    CV_EML_IF(0, 0, 0, true);
    c20_out = true;
  }

  _SFD_SYMBOL_SCOPE_POP();
  guard1 = false;
  if (c20_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c20_sfEvent);
    c20_exit_internal_Initialization(chartInstance);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c20_sfEvent);
    *chartInstance->c20_is_c20_Walking01_withElmos = c20_IN_FaultRunning;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c20_sfEvent);
    c20_enter_atomic_FaultRunning(chartInstance);
    guard1 = true;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U,
                 *chartInstance->c20_sfEvent);
    switch (*chartInstance->c20_is_Initialization) {
     case c20_IN_Fault:
      CV_STATE_EVAL(1, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 5U,
                   *chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_m_debug_family_names,
        c20_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargin, 0U, c20_sf_marshallOut,
        c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_nargout, 1U,
        c20_sf_marshallOut, c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_b_out, 2U, c20_b_sf_marshallOut,
        c20_b_sf_marshallIn);
      c20_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 83U, 1, 7);
      c20_b_out = CV_EML_IF(5, 0, 0, CV_RELATIONAL_EVAL(5U, 5U, 0,
        *chartInstance->c20_Timeout, 20.0, -1, 5U, *chartInstance->c20_Timeout >=
        20.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c20_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c20_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c20_sfEvent);
        *chartInstance->c20_is_Initialization = c20_IN_Fault;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c20_sfEvent);
        c20_enter_atomic_Fault(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 11U,
                     *chartInstance->c20_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_r_debug_family_names,
          c20_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargin, 0U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_nargout, 1U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_c_out, 2U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        c20_c_out = CV_EML_IF(11, 0, 0, CV_RELATIONAL_EVAL(5U, 11U, 0, (real_T)
          *chartInstance->c20_SwitchOnDisabledMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c20_SwitchOnDisabledMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c20_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 11U, *chartInstance->c20_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c20_sfEvent);
          *chartInstance->c20_is_Initialization = c20_IN_SwitchOnDisabled;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c20_sfEvent);
          c20_enter_atomic_SwitchOnDisabled(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       *chartInstance->c20_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_b_debug_family_names,
            c20_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargin, 0U,
            c20_sf_marshallOut, c20_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_nargout, 1U,
            c20_sf_marshallOut, c20_sf_marshallIn);
          c20_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 72U, 106, 7);
          (*chartInstance->c20_Timeout)++;
          c20_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c20_Timeout, 5U);
          *chartInstance->c20_ControlWordIndex = 0.0;
          c20_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c20_ControlWordIndex, 3U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *chartInstance->c20_sfEvent);
      guard1 = true;
      break;

     case c20_IN_ReadyToSwitchOn:
      CV_STATE_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 10U,
                   *chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_q_debug_family_names,
        c20_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargin, 0U, c20_sf_marshallOut,
        c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_nargout, 1U,
        c20_sf_marshallOut, c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_d_out, 2U, c20_b_sf_marshallOut,
        c20_b_sf_marshallIn);
      c20_d_out = CV_EML_IF(10, 0, 0, CV_RELATIONAL_EVAL(5U, 10U, 0, (real_T)
        *chartInstance->c20_FaultMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c20_FaultMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c20_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 10U, *chartInstance->c20_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c20_sfEvent);
        *chartInstance->c20_is_Initialization = c20_IN_Fault;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c20_sfEvent);
        c20_enter_atomic_Fault(chartInstance);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 13U,
                     *chartInstance->c20_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_t_debug_family_names,
          c20_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_nargin, 0U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_nargout, 1U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_e_out, 2U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        c20_e_out = CV_EML_IF(13, 0, 0, CV_RELATIONAL_EVAL(5U, 13U, 0, (real_T)
          *chartInstance->c20_SwitchOnDisabledMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c20_SwitchOnDisabledMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c20_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 13U, *chartInstance->c20_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c20_sfEvent);
          *chartInstance->c20_is_Initialization = c20_IN_SwitchOnDisabled;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c20_sfEvent);
          c20_enter_atomic_SwitchOnDisabled(chartInstance);
        } else {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c20_sfEvent);
          *chartInstance->c20_is_Initialization = c20_IN_NO_ACTIVE_CHILD;
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c20_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c20_sfEvent);
          *chartInstance->c20_is_c20_Walking01_withElmos = c20_IN_Running;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 5U, *chartInstance->c20_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_e_debug_family_names,
            c20_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_g_nargin, 0U,
            c20_sf_marshallOut, c20_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_g_nargout, 1U,
            c20_sf_marshallOut, c20_sf_marshallIn);
          *chartInstance->c20_ControlWordIndex = 2.0;
          c20_updateDataWrittenToVector(chartInstance, 0U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c20_ControlWordIndex, 3U);
          *chartInstance->c20_EnableTargetTorque = 1.0;
          c20_updateDataWrittenToVector(chartInstance, 1U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c20_EnableTargetTorque, 4U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c20_sfEvent);
      if (*chartInstance->c20_is_c20_Walking01_withElmos !=
          c20_IN_Initialization) {
      } else {
        guard1 = true;
      }
      break;

     case c20_IN_SwitchOnDisabled:
      CV_STATE_EVAL(1, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 2U,
                   *chartInstance->c20_sfEvent);
      _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_k_debug_family_names,
        c20_debug_family_var_map);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_h_nargin, 0U, c20_sf_marshallOut,
        c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_h_nargout, 1U,
        c20_sf_marshallOut, c20_sf_marshallIn);
      _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_f_out, 2U, c20_b_sf_marshallOut,
        c20_b_sf_marshallIn);
      c20_f_out = CV_EML_IF(2, 0, 0, CV_RELATIONAL_EVAL(5U, 2U, 0, (real_T)
        *chartInstance->c20_ReadyToSwitchOnMode, 1.0, -1, 0U, (real_T)
        *chartInstance->c20_ReadyToSwitchOnMode == 1.0));
      _SFD_SYMBOL_SCOPE_POP();
      if (c20_f_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c20_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c20_sfEvent);
        *chartInstance->c20_is_Initialization = c20_IN_ReadyToSwitchOn;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c20_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_h_debug_family_names,
          c20_b_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_i_nargin, 0U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_i_nargout, 1U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        *chartInstance->c20_ControlWordIndex = 2.0;
        c20_updateDataWrittenToVector(chartInstance, 0U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c20_ControlWordIndex, 3U);
        *chartInstance->c20_Timeout = 0.0;
        c20_updateDataWrittenToVector(chartInstance, 2U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c20_Timeout, 5U);
        *chartInstance->c20_EnableTargetTorque = 0.0;
        c20_updateDataWrittenToVector(chartInstance, 1U);
        _SFD_DATA_RANGE_CHECK(*chartInstance->c20_EnableTargetTorque, 4U);
        _SFD_SYMBOL_SCOPE_POP();
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                     *chartInstance->c20_sfEvent);
        _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c20_o_debug_family_names,
          c20_debug_family_var_map);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_j_nargin, 0U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_j_nargout, 1U,
          c20_sf_marshallOut, c20_sf_marshallIn);
        _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_g_out, 2U,
          c20_b_sf_marshallOut, c20_b_sf_marshallIn);
        c20_g_out = CV_EML_IF(7, 0, 0, CV_RELATIONAL_EVAL(5U, 7U, 0, (real_T)
          *chartInstance->c20_FaultMode, 1.0, -1, 0U, (real_T)
          *chartInstance->c20_FaultMode == 1.0));
        _SFD_SYMBOL_SCOPE_POP();
        if (c20_g_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, *chartInstance->c20_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c20_sfEvent);
          *chartInstance->c20_is_Initialization = c20_IN_Fault;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c20_sfEvent);
          c20_enter_atomic_Fault(chartInstance);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                       *chartInstance->c20_sfEvent);
          _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 2U, 2U, c20_d_debug_family_names,
            c20_b_debug_family_var_map);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_k_nargin, 0U,
            c20_sf_marshallOut, c20_sf_marshallIn);
          _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c20_k_nargout, 1U,
            c20_sf_marshallOut, c20_sf_marshallIn);
          c20_errorIfDataNotWrittenToFcn(chartInstance, 2U, 5U, 73U, 117, 7);
          (*chartInstance->c20_Timeout)++;
          c20_updateDataWrittenToVector(chartInstance, 2U);
          _SFD_DATA_RANGE_CHECK(*chartInstance->c20_Timeout, 5U);
          _SFD_SYMBOL_SCOPE_POP();
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *chartInstance->c20_sfEvent);
      guard1 = true;
      break;

     default:
      CV_STATE_EVAL(1, 0, 0);
      *chartInstance->c20_is_Initialization = c20_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c20_sfEvent);
      guard1 = true;
      break;
    }
  }

  if (guard1 == true) {
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c20_sfEvent);
  }
}

static void c20_exit_internal_Initialization
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance)
{
  switch (*chartInstance->c20_is_Initialization) {
   case c20_IN_Fault:
    CV_STATE_EVAL(1, 1, 1);
    *chartInstance->c20_is_Initialization = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c20_sfEvent);
    break;

   case c20_IN_ReadyToSwitchOn:
    CV_STATE_EVAL(1, 1, 2);
    *chartInstance->c20_is_Initialization = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c20_sfEvent);
    break;

   case c20_IN_SwitchOnDisabled:
    CV_STATE_EVAL(1, 1, 3);
    *chartInstance->c20_is_Initialization = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c20_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    *chartInstance->c20_is_Initialization = c20_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c20_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c20_machineNumber, uint32_T
  c20_chartNumber, uint32_T c20_instanceNumber)
{
  (void)c20_machineNumber;
  (void)c20_chartNumber;
  (void)c20_instanceNumber;
}

static const mxArray *c20_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  real_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc20_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(real_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static real_T c20_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_nargout, const char_T *c20_identifier)
{
  real_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_nargout),
    &c20_thisId);
  sf_mex_destroy(&c20_nargout);
  return c20_y;
}

static real_T c20_b_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  real_T c20_y;
  real_T c20_d0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_d0, 1, 0, 0U, 0, 0U, 0);
  c20_y = c20_d0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_nargout;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  real_T c20_y;
  SFc20_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc20_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c20_nargout = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_nargout),
    &c20_thisId);
  sf_mex_destroy(&c20_nargout);
  *(real_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_b_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  boolean_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc20_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(boolean_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static boolean_T c20_c_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct *
  chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  boolean_T c20_y;
  boolean_T c20_b0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_b0, 1, 11, 0U, 0, 0U, 0);
  c20_y = c20_b0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_sf_internal_predicateOutput;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  boolean_T c20_y;
  SFc20_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc20_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c20_sf_internal_predicateOutput = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_sf_internal_predicateOutput), &c20_thisId);
  sf_mex_destroy(&c20_sf_internal_predicateOutput);
  *(boolean_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

const mxArray *sf_c20_Walking01_withElmos_get_eml_resolved_functions_info(void)
{
  const mxArray *c20_nameCaptureInfo = NULL;
  c20_nameCaptureInfo = NULL;
  sf_mex_assign(&c20_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c20_nameCaptureInfo;
}

static const mxArray *c20_c_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  int32_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc20_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(int32_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static int32_T c20_d_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  int32_T c20_y;
  int32_T c20_i2;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_i2, 1, 6, 0U, 0, 0U, 0);
  c20_y = c20_i2;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_sfEvent;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  int32_T c20_y;
  SFc20_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc20_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c20_b_sfEvent = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_sfEvent),
    &c20_thisId);
  sf_mex_destroy(&c20_b_sfEvent);
  *(int32_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static const mxArray *c20_d_sf_marshallOut(void *chartInstanceVoid, void
  *c20_inData)
{
  const mxArray *c20_mxArrayOutData = NULL;
  uint8_T c20_u;
  const mxArray *c20_y = NULL;
  SFc20_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc20_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c20_mxArrayOutData = NULL;
  c20_u = *(uint8_T *)c20_inData;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_create("y", &c20_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c20_mxArrayOutData, c20_y, false);
  return c20_mxArrayOutData;
}

static uint8_T c20_e_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_b_is_Initialization, const char_T
  *c20_identifier)
{
  uint8_T c20_y;
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_is_Initialization), &c20_thisId);
  sf_mex_destroy(&c20_b_is_Initialization);
  return c20_y;
}

static uint8_T c20_f_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId)
{
  uint8_T c20_y;
  uint8_T c20_u0;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), &c20_u0, 1, 3, 0U, 0, 0U, 0);
  c20_y = c20_u0;
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c20_mxArrayInData, const char_T *c20_varName, void *c20_outData)
{
  const mxArray *c20_b_is_Initialization;
  const char_T *c20_identifier;
  emlrtMsgIdentifier c20_thisId;
  uint8_T c20_y;
  SFc20_Walking01_withElmosInstanceStruct *chartInstance;
  chartInstance = (SFc20_Walking01_withElmosInstanceStruct *)chartInstanceVoid;
  c20_b_is_Initialization = sf_mex_dup(c20_mxArrayInData);
  c20_identifier = c20_varName;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_y = c20_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_is_Initialization), &c20_thisId);
  sf_mex_destroy(&c20_b_is_Initialization);
  *(uint8_T *)c20_outData = c20_y;
  sf_mex_destroy(&c20_mxArrayInData);
}

static void c20_g_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_b_dataWrittenToVector, const char_T
  *c20_identifier, boolean_T c20_y[4])
{
  emlrtMsgIdentifier c20_thisId;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  c20_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c20_b_dataWrittenToVector),
    &c20_thisId, c20_y);
  sf_mex_destroy(&c20_b_dataWrittenToVector);
}

static void c20_h_emlrt_marshallIn(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance, const mxArray *c20_u, const emlrtMsgIdentifier *c20_parentId,
  boolean_T c20_y[4])
{
  boolean_T c20_bv1[4];
  int32_T c20_i3;
  (void)chartInstance;
  sf_mex_import(c20_parentId, sf_mex_dup(c20_u), c20_bv1, 1, 11, 0U, 1, 0U, 1, 4);
  for (c20_i3 = 0; c20_i3 < 4; c20_i3++) {
    c20_y[c20_i3] = c20_bv1[c20_i3];
  }

  sf_mex_destroy(&c20_u);
}

static const mxArray *c20_i_emlrt_marshallIn
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance, const mxArray
   *c20_b_setSimStateSideEffectsInfo, const char_T *c20_identifier)
{
  const mxArray *c20_y = NULL;
  emlrtMsgIdentifier c20_thisId;
  c20_y = NULL;
  c20_thisId.fIdentifier = c20_identifier;
  c20_thisId.fParent = NULL;
  sf_mex_assign(&c20_y, c20_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c20_b_setSimStateSideEffectsInfo), &c20_thisId), false);
  sf_mex_destroy(&c20_b_setSimStateSideEffectsInfo);
  return c20_y;
}

static const mxArray *c20_j_emlrt_marshallIn
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance, const mxArray *c20_u,
   const emlrtMsgIdentifier *c20_parentId)
{
  const mxArray *c20_y = NULL;
  (void)chartInstance;
  (void)c20_parentId;
  c20_y = NULL;
  sf_mex_assign(&c20_y, sf_mex_duplicatearraysafe(&c20_u), false);
  sf_mex_destroy(&c20_u);
  return c20_y;
}

static void c20_updateDataWrittenToVector
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance, uint32_T
   c20_vectorIndex)
{
  chartInstance->c20_dataWrittenToVector[(uint32_T)_SFD_EML_ARRAY_BOUNDS_CHECK
    (0U, (int32_T)c20_vectorIndex, 0, 3, 1, 0)] = true;
}

static void c20_errorIfDataNotWrittenToFcn
  (SFc20_Walking01_withElmosInstanceStruct *chartInstance, uint32_T
   c20_vectorIndex, uint32_T c20_dataNumber, uint32_T c20_ssIdOfSourceObject,
   int32_T c20_offsetInSourceObject, int32_T c20_lengthInSourceObject)
{
  (void)c20_ssIdOfSourceObject;
  (void)c20_offsetInSourceObject;
  (void)c20_lengthInSourceObject;
  if (!chartInstance->c20_dataWrittenToVector[(uint32_T)
      _SFD_EML_ARRAY_BOUNDS_CHECK(0U, (int32_T)c20_vectorIndex, 0, 3, 1, 0)]) {
    _SFD_DATA_READ_BEFORE_WRITE_ERROR(c20_dataNumber);
  }
}

static void init_dsm_address_info(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc20_Walking01_withElmosInstanceStruct
  *chartInstance)
{
  chartInstance->c20_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c20_isStable = (boolean_T *)ssGetDWork_wrapper(chartInstance->S,
    1);
  chartInstance->c20_is_active_c20_Walking01_withElmos = (uint8_T *)
    ssGetDWork_wrapper(chartInstance->S, 2);
  chartInstance->c20_is_c20_Walking01_withElmos = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 3);
  chartInstance->c20_is_Initialization = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 4);
  chartInstance->c20_SwitchOnDisabledMode = (boolean_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 0);
  chartInstance->c20_EnabledMode = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c20_ReadyToSwitchOnMode = (boolean_T *)
    ssGetInputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c20_ControlWordIndex = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c20_EnableTargetTorque = (real_T *)
    ssGetOutputPortSignal_wrapper(chartInstance->S, 2);
  chartInstance->c20_Timeout = (real_T *)ssGetDWork_wrapper(chartInstance->S, 5);
  chartInstance->c20_FaultMode = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c20_FaultDetected = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c20_MedullaCommand = (real_T *)ssGetInputPortSignal_wrapper
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
void sf_c20_Walking01_withElmos_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(95137086U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3355523361U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1324736782U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1289530824U);
}

mxArray* sf_c20_Walking01_withElmos_get_post_codegen_info(void);
mxArray *sf_c20_Walking01_withElmos_get_autoinheritance_info(void)
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
      sf_c20_Walking01_withElmos_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c20_Walking01_withElmos_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c20_Walking01_withElmos_jit_fallback_info(void)
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

mxArray *sf_c20_Walking01_withElmos_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c20_Walking01_withElmos_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c20_Walking01_withElmos(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x8'type','srcId','name','auxInfo'{{M[1],M[23],T\"ControlWordIndex\",},{M[1],M[24],T\"EnableTargetTorque\",},{M[1],M[64],T\"FaultDetected\",},{M[3],M[25],T\"Timeout\",},{M[8],M[0],T\"is_active_c20_Walking01_withElmos\",},{M[9],M[0],T\"is_c20_Walking01_withElmos\",},{M[9],M[87],T\"is_Initialization\",},{M[15],M[0],T\"dataWrittenToVector\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 8, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c20_Walking01_withElmos_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc20_Walking01_withElmosInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc20_Walking01_withElmosInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_withElmosMachineNumber_,
           20,
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
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)c20_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c20_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c20_SwitchOnDisabledMode);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c20_EnabledMode);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c20_ReadyToSwitchOnMode);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c20_ControlWordIndex);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c20_EnableTargetTorque);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c20_Timeout);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c20_FaultMode);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c20_FaultDetected);
        _SFD_SET_DATA_VALUE_PTR(8U, chartInstance->c20_MedullaCommand);
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
  return "QcyolaGX62rbNZaAtl54zB";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_Walking01_withElmos_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 20, "dworkChecksum");
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

static void sf_opaque_initialize_c20_Walking01_withElmos(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc20_Walking01_withElmosInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc20_Walking01_withElmosInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c20_Walking01_withElmos
    ((SFc20_Walking01_withElmosInstanceStruct*) chartInstanceVar);
  initialize_c20_Walking01_withElmos((SFc20_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c20_Walking01_withElmos(void *chartInstanceVar)
{
  enable_c20_Walking01_withElmos((SFc20_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c20_Walking01_withElmos(void *chartInstanceVar)
{
  disable_c20_Walking01_withElmos((SFc20_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c20_Walking01_withElmos(void *chartInstanceVar)
{
  sf_gateway_c20_Walking01_withElmos((SFc20_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c20_Walking01_withElmos(void
  *chartInstanceVar)
{
  ext_mode_exec_c20_Walking01_withElmos((SFc20_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c20_Walking01_withElmos(SimStruct*
  S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c20_Walking01_withElmos
    ((SFc20_Walking01_withElmosInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
}

static void sf_opaque_set_sim_state_c20_Walking01_withElmos(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c20_Walking01_withElmos((SFc20_Walking01_withElmosInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c20_Walking01_withElmos(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc20_Walking01_withElmosInstanceStruct*) chartInstanceVar
      )->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_withElmos_optimization_info();
    }

    finalize_c20_Walking01_withElmos((SFc20_Walking01_withElmosInstanceStruct*)
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
  initSimStructsc20_Walking01_withElmos((SFc20_Walking01_withElmosInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c20_Walking01_withElmos(SimStruct *S)
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
    initialize_params_c20_Walking01_withElmos
      ((SFc20_Walking01_withElmosInstanceStruct*)(chartInfo->chartInstance));
  }
}

mxArray *sf_c20_Walking01_withElmos_get_testpoint_info(void)
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

static void mdlSetWorkWidths_c20_Walking01_withElmos(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_withElmos_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      20);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,20,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,20,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,20);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,20,5);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,20,3);
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

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,20);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(1139229030U));
  ssSetChecksum1(S,(2041377195U));
  ssSetChecksum2(S,(1156566449U));
  ssSetChecksum3(S,(2340254799U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c20_Walking01_withElmos(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c20_Walking01_withElmos(SimStruct *S)
{
  SFc20_Walking01_withElmosInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc20_Walking01_withElmosInstanceStruct *)utMalloc(sizeof
    (SFc20_Walking01_withElmosInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc20_Walking01_withElmosInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c20_Walking01_withElmos;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c20_Walking01_withElmos;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c20_Walking01_withElmos;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c20_Walking01_withElmos;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c20_Walking01_withElmos;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c20_Walking01_withElmos;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c20_Walking01_withElmos;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c20_Walking01_withElmos;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c20_Walking01_withElmos;
  chartInstance->chartInfo.mdlStart = mdlStart_c20_Walking01_withElmos;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c20_Walking01_withElmos;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c20_Walking01_withElmos;
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

void c20_Walking01_withElmos_method_dispatcher(SimStruct *S, int_T method, void *
  data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c20_Walking01_withElmos(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c20_Walking01_withElmos(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c20_Walking01_withElmos(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c20_Walking01_withElmos_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
