/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_DDA3D_sfun.h"
#include "c9_Walking01_DDA3D.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Walking01_DDA3D_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)
#define c9_IN_NO_ACTIVE_CHILD          ((uint8_T)0U)
#define c9_IN_Init                     ((uint8_T)1U)
#define c9_IN_Run                      ((uint8_T)2U)
#define c9_IN_Error                    ((uint8_T)1U)
#define c9_IN_MissedPacket             ((uint8_T)2U)
#define c9_IN_Nominal                  ((uint8_T)3U)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c9_debug_family_names[3] = { "nargin", "nargout", "err" };

/* Function Declarations */
static void initialize_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initialize_params_c9_Walking01_DDA3D
  (SFc9_Walking01_DDA3DInstanceStruct *chartInstance);
static void enable_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void disable_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c9_update_debugger_state_c9_Walking01_DDA3D
  (SFc9_Walking01_DDA3DInstanceStruct *chartInstance);
static void ext_mode_exec_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct *
  chartInstance);
static const mxArray *get_sim_state_c9_Walking01_DDA3D
  (SFc9_Walking01_DDA3DInstanceStruct *chartInstance);
static void set_sim_state_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct *
  chartInstance, const mxArray *c9_st);
static void c9_set_sim_state_side_effects_c9_Walking01_DDA3D
  (SFc9_Walking01_DDA3DInstanceStruct *chartInstance);
static void finalize_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void sf_gateway_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void mdl_start_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initSimStructsc9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct *
  chartInstance);
static void c9_Run(SFc9_Walking01_DDA3DInstanceStruct *chartInstance);
static void c9_exit_internal_Run(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber);
static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData);
static boolean_T c9_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static real_T c9_b_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_nargout, const char_T *c9_identifier);
static real_T c9_c_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static void c9_info_helper(const mxArray **c9_info);
static const mxArray *c9_emlrt_marshallOut(const char * c9_u);
static const mxArray *c9_b_emlrt_marshallOut(const uint32_T c9_u);
static boolean_T c9_check_error(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance);
static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static int32_T c9_d_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static uint8_T c9_e_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_b_is_Run, const char_T *c9_identifier);
static uint8_T c9_f_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData);
static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData);
static uint32_T c9_g_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_b_temporalCounter_i1, const char_T
  *c9_identifier);
static uint32_T c9_h_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static const mxArray *c9_i_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_b_setSimStateSideEffectsInfo, const char_T
  *c9_identifier);
static const mxArray *c9_j_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId);
static void init_dsm_address_info(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  *chartInstance->c9_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c9_doSetSimStateSideEffects = 0U;
  chartInstance->c9_setSimStateSideEffectsInfo = NULL;
  *chartInstance->c9_temporalCounter_i1 = 0U;
  *chartInstance->c9_is_Run = c9_IN_NO_ACTIVE_CHILD;
  *chartInstance->c9_is_active_c9_Walking01_DDA3D = 0U;
  *chartInstance->c9_is_c9_Walking01_DDA3D = c9_IN_NO_ACTIVE_CHILD;
  *chartInstance->c9_q_last = 0.0;
  *chartInstance->c9_dq_last = 0.0;
  *chartInstance->c9_Counter_last = 0.0;
  if (!(sf_get_output_port_reusable(chartInstance->S, 1) != 0)) {
    *chartInstance->c9_q_clean = 0.0;
  }

  if (!(sf_get_output_port_reusable(chartInstance->S, 2) != 0)) {
    *chartInstance->c9_ErrorCount = 0.0;
  }
}

static void initialize_params_c9_Walking01_DDA3D
  (SFc9_Walking01_DDA3DInstanceStruct *chartInstance)
{
  real_T c9_d0;
  real_T c9_d1;
  sf_mex_import_named("MAX_ANOMALY", sf_mex_get_sfun_param(chartInstance->S, 1,
    0), &c9_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c9_MAX_ANOMALY = c9_d0;
  sf_mex_import_named("ANOMALY_INIT", sf_mex_get_sfun_param(chartInstance->S, 0,
    0), &c9_d1, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c9_ANOMALY_INIT = c9_d1;
}

static void enable_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c9_update_debugger_state_c9_Walking01_DDA3D
  (SFc9_Walking01_DDA3DInstanceStruct *chartInstance)
{
  uint32_T c9_prevAniVal;
  c9_prevAniVal = _SFD_GET_ANIMATION();
  _SFD_SET_ANIMATION(0U);
  _SFD_SET_HONOR_BREAKPOINTS(0U);
  if (*chartInstance->c9_is_active_c9_Walking01_DDA3D == 1U) {
    _SFD_CC_CALL(CHART_ACTIVE_TAG, 6U, *chartInstance->c9_sfEvent);
  }

  if (*chartInstance->c9_is_c9_Walking01_DDA3D == c9_IN_Run) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c9_sfEvent);
  }

  if (*chartInstance->c9_is_Run == c9_IN_Nominal) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c9_sfEvent);
  }

  if (*chartInstance->c9_is_Run == c9_IN_MissedPacket) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c9_sfEvent);
  }

  if (*chartInstance->c9_is_Run == c9_IN_Error) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c9_sfEvent);
  }

  if (*chartInstance->c9_is_c9_Walking01_DDA3D == c9_IN_Init) {
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c9_sfEvent);
  } else {
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c9_sfEvent);
  }

  _SFD_SET_ANIMATION(c9_prevAniVal);
  _SFD_SET_HONOR_BREAKPOINTS(1U);
  _SFD_ANIMATE();
}

static void ext_mode_exec_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct *
  chartInstance)
{
  c9_update_debugger_state_c9_Walking01_DDA3D(chartInstance);
}

static const mxArray *get_sim_state_c9_Walking01_DDA3D
  (SFc9_Walking01_DDA3DInstanceStruct *chartInstance)
{
  const mxArray *c9_st;
  const mxArray *c9_y = NULL;
  real_T c9_hoistedGlobal;
  real_T c9_u;
  const mxArray *c9_b_y = NULL;
  real_T c9_b_hoistedGlobal;
  real_T c9_b_u;
  const mxArray *c9_c_y = NULL;
  real_T c9_c_hoistedGlobal;
  real_T c9_c_u;
  const mxArray *c9_d_y = NULL;
  real_T c9_d_hoistedGlobal;
  real_T c9_d_u;
  const mxArray *c9_e_y = NULL;
  real_T c9_e_hoistedGlobal;
  real_T c9_e_u;
  const mxArray *c9_f_y = NULL;
  uint8_T c9_f_hoistedGlobal;
  uint8_T c9_f_u;
  const mxArray *c9_g_y = NULL;
  uint8_T c9_g_hoistedGlobal;
  uint8_T c9_g_u;
  const mxArray *c9_h_y = NULL;
  uint8_T c9_h_hoistedGlobal;
  uint8_T c9_h_u;
  const mxArray *c9_i_y = NULL;
  uint32_T c9_i_hoistedGlobal;
  uint32_T c9_i_u;
  const mxArray *c9_j_y = NULL;
  c9_st = NULL;
  c9_st = NULL;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_createcellmatrix(9, 1), false);
  c9_hoistedGlobal = *chartInstance->c9_ErrorCount;
  c9_u = c9_hoistedGlobal;
  c9_b_y = NULL;
  sf_mex_assign(&c9_b_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 0, c9_b_y);
  c9_b_hoistedGlobal = *chartInstance->c9_q_clean;
  c9_b_u = c9_b_hoistedGlobal;
  c9_c_y = NULL;
  sf_mex_assign(&c9_c_y, sf_mex_create("y", &c9_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 1, c9_c_y);
  c9_c_hoistedGlobal = *chartInstance->c9_Counter_last;
  c9_c_u = c9_c_hoistedGlobal;
  c9_d_y = NULL;
  sf_mex_assign(&c9_d_y, sf_mex_create("y", &c9_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 2, c9_d_y);
  c9_d_hoistedGlobal = *chartInstance->c9_dq_last;
  c9_d_u = c9_d_hoistedGlobal;
  c9_e_y = NULL;
  sf_mex_assign(&c9_e_y, sf_mex_create("y", &c9_d_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 3, c9_e_y);
  c9_e_hoistedGlobal = *chartInstance->c9_q_last;
  c9_e_u = c9_e_hoistedGlobal;
  c9_f_y = NULL;
  sf_mex_assign(&c9_f_y, sf_mex_create("y", &c9_e_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 4, c9_f_y);
  c9_f_hoistedGlobal = *chartInstance->c9_is_active_c9_Walking01_DDA3D;
  c9_f_u = c9_f_hoistedGlobal;
  c9_g_y = NULL;
  sf_mex_assign(&c9_g_y, sf_mex_create("y", &c9_f_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 5, c9_g_y);
  c9_g_hoistedGlobal = *chartInstance->c9_is_c9_Walking01_DDA3D;
  c9_g_u = c9_g_hoistedGlobal;
  c9_h_y = NULL;
  sf_mex_assign(&c9_h_y, sf_mex_create("y", &c9_g_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 6, c9_h_y);
  c9_h_hoistedGlobal = *chartInstance->c9_is_Run;
  c9_h_u = c9_h_hoistedGlobal;
  c9_i_y = NULL;
  sf_mex_assign(&c9_i_y, sf_mex_create("y", &c9_h_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 7, c9_i_y);
  c9_i_hoistedGlobal = *chartInstance->c9_temporalCounter_i1;
  c9_i_u = c9_i_hoistedGlobal;
  c9_j_y = NULL;
  sf_mex_assign(&c9_j_y, sf_mex_create("y", &c9_i_u, 7, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c9_y, 8, c9_j_y);
  sf_mex_assign(&c9_st, c9_y, false);
  return c9_st;
}

static void set_sim_state_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct *
  chartInstance, const mxArray *c9_st)
{
  const mxArray *c9_u;
  c9_u = sf_mex_dup(c9_st);
  *chartInstance->c9_ErrorCount = c9_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 0)), "ErrorCount");
  *chartInstance->c9_q_clean = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 1)), "q_clean");
  *chartInstance->c9_Counter_last = c9_b_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 2)), "Counter_last");
  *chartInstance->c9_dq_last = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 3)), "dq_last");
  *chartInstance->c9_q_last = c9_b_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 4)), "q_last");
  *chartInstance->c9_is_active_c9_Walking01_DDA3D = c9_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c9_u, 5)),
     "is_active_c9_Walking01_DDA3D");
  *chartInstance->c9_is_c9_Walking01_DDA3D = c9_e_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 6)), "is_c9_Walking01_DDA3D");
  *chartInstance->c9_is_Run = c9_e_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c9_u, 7)), "is_Run");
  *chartInstance->c9_temporalCounter_i1 = c9_g_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c9_u, 8)), "temporalCounter_i1");
  sf_mex_assign(&chartInstance->c9_setSimStateSideEffectsInfo,
                c9_i_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c9_u, 9)), "setSimStateSideEffectsInfo"), true);
  sf_mex_destroy(&c9_u);
  chartInstance->c9_doSetSimStateSideEffects = 1U;
  c9_update_debugger_state_c9_Walking01_DDA3D(chartInstance);
  sf_mex_destroy(&c9_st);
}

static void c9_set_sim_state_side_effects_c9_Walking01_DDA3D
  (SFc9_Walking01_DDA3DInstanceStruct *chartInstance)
{
  if (chartInstance->c9_doSetSimStateSideEffects != 0) {
    if (*chartInstance->c9_is_c9_Walking01_DDA3D == c9_IN_Init) {
      if (sf_mex_sub(chartInstance->c9_setSimStateSideEffectsInfo,
                     "setSimStateSideEffectsInfo", 1, 2) == 0.0) {
        *chartInstance->c9_temporalCounter_i1 = 0U;
      }
    }

    chartInstance->c9_doSetSimStateSideEffects = 0U;
  }
}

static void finalize_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  sf_mex_destroy(&chartInstance->c9_setSimStateSideEffectsInfo);
}

static void sf_gateway_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  int32_T c9_i0;
  boolean_T c9_temp;
  uint32_T c9_u0;
  boolean_T c9_out;
  c9_set_sim_state_side_effects_c9_Walking01_DDA3D(chartInstance);
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 6U, *chartInstance->c9_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q, 0U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_dq, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_Counter, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_clean, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ErrorCount, 4U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_MAX_ANOMALY, 5U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_last, 6U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_dq_last, 7U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c9_ANOMALY_INIT, 8U);
  for (c9_i0 = 0; c9_i0 < 2; c9_i0++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c9_q_limits)[c9_i0], 9U);
  }

  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_Threshold, 10U);
  _SFD_DATA_RANGE_CHECK((real_T)*chartInstance->c9_Reset, 11U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ANOMALY_DT, 12U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c9_Counter_last, 13U);
  *chartInstance->c9_sfEvent = CALL_EVENT;
  if (*chartInstance->c9_temporalCounter_i1 < MAX_uint32_T) {
    (*chartInstance->c9_temporalCounter_i1)++;
  }

  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 6U, *chartInstance->c9_sfEvent);
  if (*chartInstance->c9_is_active_c9_Walking01_DDA3D == 0U) {
    _SFD_CC_CALL(CHART_ENTER_ENTRY_FUNCTION_TAG, 6U, *chartInstance->c9_sfEvent);
    *chartInstance->c9_is_active_c9_Walking01_DDA3D = 1U;
    _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c9_sfEvent);
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 2U, *chartInstance->c9_sfEvent);
    *chartInstance->c9_is_c9_Walking01_DDA3D = c9_IN_Init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c9_sfEvent);
    *chartInstance->c9_temporalCounter_i1 = 0U;
    *chartInstance->c9_q_clean = *chartInstance->c9_q;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_clean, 3U);
    *chartInstance->c9_q_last = *chartInstance->c9_q;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_last, 6U);
    *chartInstance->c9_dq_last = *chartInstance->c9_dq;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c9_dq_last, 7U);
    *chartInstance->c9_ErrorCount = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ErrorCount, 4U);
  } else {
    switch (*chartInstance->c9_is_c9_Walking01_DDA3D) {
     case c9_IN_Init:
      CV_CHART_EVAL(6, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 3U,
                   *chartInstance->c9_sfEvent);
      c9_temp = !(_SFD_CCP_CALL(3U, 0, *chartInstance->c9_Reset != 0U,
        *chartInstance->c9_sfEvent) != 0);
      if (c9_temp) {
        c9_u0 = _SFD_TRANS_TEMPORAL_THRESHOLD((uint32_T)
          chartInstance->c9_ANOMALY_INIT, 32U, 3U);
        c9_temp = (_SFD_CCP_CALL(3U, 1, *chartInstance->c9_temporalCounter_i1 >=
                    c9_u0 != 0U, *chartInstance->c9_sfEvent) != 0);
      }

      c9_out = (CV_TRANSITION_EVAL(3U, (int32_T)c9_temp) != 0);
      if (c9_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 3U, *chartInstance->c9_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c9_sfEvent);
        *chartInstance->c9_is_c9_Walking01_DDA3D = c9_IN_Run;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 1U, *chartInstance->c9_sfEvent);
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 5U, *chartInstance->c9_sfEvent);
        *chartInstance->c9_is_Run = c9_IN_Nominal;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c9_sfEvent);
        *chartInstance->c9_q_clean = *chartInstance->c9_q;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_clean, 3U);
        *chartInstance->c9_q_last = *chartInstance->c9_q;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_last, 6U);
        *chartInstance->c9_dq_last = *chartInstance->c9_dq;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_dq_last, 7U);
        *chartInstance->c9_Counter_last = *chartInstance->c9_Counter;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_Counter_last, 13U);
        *chartInstance->c9_ErrorCount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ErrorCount, 4U);
      } else {
        _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 0U,
                     *chartInstance->c9_sfEvent);
        *chartInstance->c9_q_clean = *chartInstance->c9_q;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_clean, 3U);
        *chartInstance->c9_q_last = *chartInstance->c9_q;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_last, 6U);
        *chartInstance->c9_dq_last = *chartInstance->c9_dq;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_dq_last, 7U);
        *chartInstance->c9_ErrorCount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ErrorCount, 4U);
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 0U, *chartInstance->c9_sfEvent);
      break;

     case c9_IN_Run:
      CV_CHART_EVAL(6, 0, 2);
      c9_Run(chartInstance);
      break;

     default:
      CV_CHART_EVAL(6, 0, 0);
      *chartInstance->c9_is_c9_Walking01_DDA3D = c9_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 0U, *chartInstance->c9_sfEvent);
      break;
    }
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 6U, *chartInstance->c9_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_DDA3DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void mdl_start_c9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc9_Walking01_DDA3D(SFc9_Walking01_DDA3DInstanceStruct *
  chartInstance)
{
  (void)chartInstance;
}

static void c9_Run(SFc9_Walking01_DDA3DInstanceStruct *chartInstance)
{
  boolean_T c9_out;
  boolean_T c9_b_out;
  boolean_T c9_c_out;
  boolean_T c9_temp;
  boolean_T c9_d_out;
  boolean_T c9_e_out;
  boolean_T guard1 = false;
  _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 4U, *chartInstance->c9_sfEvent);
  c9_out = (CV_TRANSITION_EVAL(4U, (int32_T)_SFD_CCP_CALL(4U, 0,
              *chartInstance->c9_Reset != 0U, *chartInstance->c9_sfEvent)) != 0);
  guard1 = false;
  if (c9_out) {
    _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 4U, *chartInstance->c9_sfEvent);
    c9_exit_internal_Run(chartInstance);
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c9_sfEvent);
    *chartInstance->c9_is_c9_Walking01_DDA3D = c9_IN_Init;
    _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c9_sfEvent);
    *chartInstance->c9_temporalCounter_i1 = 0U;
    *chartInstance->c9_q_clean = *chartInstance->c9_q;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_clean, 3U);
    *chartInstance->c9_q_last = *chartInstance->c9_q;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_last, 6U);
    *chartInstance->c9_dq_last = *chartInstance->c9_dq;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c9_dq_last, 7U);
    *chartInstance->c9_ErrorCount = 0.0;
    _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ErrorCount, 4U);
    guard1 = true;
  } else {
    _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 1U, *chartInstance->c9_sfEvent);
    switch (*chartInstance->c9_is_Run) {
     case c9_IN_Error:
      CV_STATE_EVAL(1, 0, 1);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 1U,
                   *chartInstance->c9_sfEvent);
      c9_b_out = (CV_TRANSITION_EVAL(1U, (int32_T)_SFD_CCP_CALL(1U, 0,
        CV_RELATIONAL_EVAL(5U, 1U, 0, *chartInstance->c9_ErrorCount,
                           chartInstance->c9_MAX_ANOMALY, -1, 4U,
                           *chartInstance->c9_ErrorCount >
                           chartInstance->c9_MAX_ANOMALY) != 0U,
        *chartInstance->c9_sfEvent)) != 0);
      if (c9_b_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 1U, *chartInstance->c9_sfEvent);
        *chartInstance->c9_is_Run = c9_IN_NO_ACTIVE_CHILD;
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c9_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 1U, *chartInstance->c9_sfEvent);
        *chartInstance->c9_is_c9_Walking01_DDA3D = c9_IN_Init;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 0U, *chartInstance->c9_sfEvent);
        *chartInstance->c9_temporalCounter_i1 = 0U;
        *chartInstance->c9_q_clean = *chartInstance->c9_q;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_clean, 3U);
        *chartInstance->c9_q_last = *chartInstance->c9_q;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_last, 6U);
        *chartInstance->c9_dq_last = *chartInstance->c9_dq;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_dq_last, 7U);
        *chartInstance->c9_ErrorCount = 0.0;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ErrorCount, 4U);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 6U,
                     *chartInstance->c9_sfEvent);
        c9_c_out = (CV_TRANSITION_EVAL(6U, !(_SFD_CCP_CALL(6U, 0, c9_check_error
                       (chartInstance) != 0U, *chartInstance->c9_sfEvent) != 0))
                    != 0);
        if (c9_c_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 6U, *chartInstance->c9_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c9_sfEvent);
          *chartInstance->c9_is_Run = c9_IN_Nominal;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c9_sfEvent);
          *chartInstance->c9_q_clean = *chartInstance->c9_q;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_clean, 3U);
          *chartInstance->c9_q_last = *chartInstance->c9_q;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_last, 6U);
          *chartInstance->c9_dq_last = *chartInstance->c9_dq;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_dq_last, 7U);
          *chartInstance->c9_Counter_last = *chartInstance->c9_Counter;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_Counter_last, 13U);
          *chartInstance->c9_ErrorCount = 0.0;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ErrorCount, 4U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 2U,
                       *chartInstance->c9_sfEvent);
          (*chartInstance->c9_ErrorCount)++;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ErrorCount, 4U);
          *chartInstance->c9_q_clean = *chartInstance->c9_q_last +
            *chartInstance->c9_ErrorCount * *chartInstance->c9_dq_last *
            *chartInstance->c9_ANOMALY_DT;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_clean, 3U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, *chartInstance->c9_sfEvent);
      if (*chartInstance->c9_is_c9_Walking01_DDA3D != c9_IN_Run) {
      } else {
        guard1 = true;
      }
      break;

     case c9_IN_MissedPacket:
      CV_STATE_EVAL(1, 0, 2);
      _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 8U, *chartInstance->c9_sfEvent);
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c9_sfEvent);
      *chartInstance->c9_is_Run = c9_IN_Nominal;
      _SFD_CS_CALL(STATE_ACTIVE_TAG, 4U, *chartInstance->c9_sfEvent);
      *chartInstance->c9_q_clean = *chartInstance->c9_q;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_clean, 3U);
      *chartInstance->c9_q_last = *chartInstance->c9_q;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_last, 6U);
      *chartInstance->c9_dq_last = *chartInstance->c9_dq;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c9_dq_last, 7U);
      *chartInstance->c9_Counter_last = *chartInstance->c9_Counter;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c9_Counter_last, 13U);
      *chartInstance->c9_ErrorCount = 0.0;
      _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ErrorCount, 4U);
      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 3U, *chartInstance->c9_sfEvent);
      guard1 = true;
      break;

     case c9_IN_Nominal:
      CV_STATE_EVAL(1, 0, 3);
      _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 7U,
                   *chartInstance->c9_sfEvent);
      c9_temp = (_SFD_CCP_CALL(7U, 0, 0 != 0U, *chartInstance->c9_sfEvent) != 0);
      if (c9_temp) {
        c9_temp = (_SFD_CCP_CALL(7U, 1, CV_RELATIONAL_EVAL(5U, 7U, 0,
          *chartInstance->c9_Counter, *chartInstance->c9_Counter_last, -1, 0U,
          *chartInstance->c9_Counter == *chartInstance->c9_Counter_last) != 0U, *
                    chartInstance->c9_sfEvent) != 0);
      }

      c9_d_out = (CV_TRANSITION_EVAL(7U, (int32_T)c9_temp) != 0);
      if (c9_d_out) {
        _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 7U, *chartInstance->c9_sfEvent);
        _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c9_sfEvent);
        *chartInstance->c9_is_Run = c9_IN_MissedPacket;
        _SFD_CS_CALL(STATE_ACTIVE_TAG, 3U, *chartInstance->c9_sfEvent);
        *chartInstance->c9_q_clean = *chartInstance->c9_q_last +
          *chartInstance->c9_dq_last * *chartInstance->c9_ANOMALY_DT;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_clean, 3U);
        (*chartInstance->c9_ErrorCount)--;
        _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ErrorCount, 4U);
      } else {
        _SFD_CT_CALL(TRANSITION_BEFORE_PROCESSING_TAG, 0U,
                     *chartInstance->c9_sfEvent);
        c9_e_out = (CV_TRANSITION_EVAL(0U, (int32_T)_SFD_CCP_CALL(0U, 0,
          c9_check_error(chartInstance) != 0U, *chartInstance->c9_sfEvent)) != 0);
        if (c9_e_out) {
          _SFD_CT_CALL(TRANSITION_ACTIVE_TAG, 0U, *chartInstance->c9_sfEvent);
          _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c9_sfEvent);
          *chartInstance->c9_is_Run = c9_IN_Error;
          _SFD_CS_CALL(STATE_ACTIVE_TAG, 2U, *chartInstance->c9_sfEvent);
          *chartInstance->c9_dq_last = *chartInstance->c9_dq;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_dq_last, 7U);
          (*chartInstance->c9_ErrorCount)++;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ErrorCount, 4U);
          *chartInstance->c9_q_clean = *chartInstance->c9_q_last +
            *chartInstance->c9_ErrorCount * *chartInstance->c9_dq_last *
            *chartInstance->c9_ANOMALY_DT;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_clean, 3U);
        } else {
          _SFD_CS_CALL(STATE_ENTER_DURING_FUNCTION_TAG, 4U,
                       *chartInstance->c9_sfEvent);
          *chartInstance->c9_q_clean = *chartInstance->c9_q;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_clean, 3U);
          *chartInstance->c9_q_last = *chartInstance->c9_q;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_q_last, 6U);
          *chartInstance->c9_dq_last = *chartInstance->c9_dq;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_dq_last, 7U);
          *chartInstance->c9_Counter_last = *chartInstance->c9_Counter;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_Counter_last, 13U);
          *chartInstance->c9_ErrorCount = 0.0;
          _SFD_DATA_RANGE_CHECK(*chartInstance->c9_ErrorCount, 4U);
        }
      }

      _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 4U, *chartInstance->c9_sfEvent);
      guard1 = true;
      break;

     default:
      CV_STATE_EVAL(1, 0, 0);
      *chartInstance->c9_is_Run = c9_IN_NO_ACTIVE_CHILD;
      _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c9_sfEvent);
      guard1 = true;
      break;
    }
  }

  if (guard1 == true) {
    _SFD_CS_CALL(EXIT_OUT_OF_FUNCTION_TAG, 1U, *chartInstance->c9_sfEvent);
  }
}

static void c9_exit_internal_Run(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  switch (*chartInstance->c9_is_Run) {
   case c9_IN_Error:
    CV_STATE_EVAL(1, 1, 1);
    *chartInstance->c9_is_Run = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c9_sfEvent);
    break;

   case c9_IN_MissedPacket:
    CV_STATE_EVAL(1, 1, 2);
    *chartInstance->c9_is_Run = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 3U, *chartInstance->c9_sfEvent);
    break;

   case c9_IN_Nominal:
    CV_STATE_EVAL(1, 1, 3);
    *chartInstance->c9_is_Run = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 4U, *chartInstance->c9_sfEvent);
    break;

   default:
    CV_STATE_EVAL(1, 1, 0);
    *chartInstance->c9_is_Run = c9_IN_NO_ACTIVE_CHILD;
    _SFD_CS_CALL(STATE_INACTIVE_TAG, 2U, *chartInstance->c9_sfEvent);
    break;
  }
}

static void init_script_number_translation(uint32_T c9_machineNumber, uint32_T
  c9_chartNumber, uint32_T c9_instanceNumber)
{
  (void)c9_machineNumber;
  (void)c9_chartNumber;
  (void)c9_instanceNumber;
}

static const mxArray *c9_sf_marshallOut(void *chartInstanceVoid, void *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  boolean_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc9_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(boolean_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static boolean_T c9_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  boolean_T c9_y;
  boolean_T c9_b0;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_b0, 1, 11, 0U, 0, 0U, 0);
  c9_y = c9_b0;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_err;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  boolean_T c9_y;
  SFc9_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc9_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c9_err = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_err), &c9_thisId);
  sf_mex_destroy(&c9_err);
  *(boolean_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_b_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  real_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc9_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(real_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static real_T c9_b_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_nargout, const char_T *c9_identifier)
{
  real_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  return c9_y;
}

static real_T c9_c_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  real_T c9_y;
  real_T c9_d2;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_d2, 1, 0, 0U, 0, 0U, 0);
  c9_y = c9_d2;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_nargout;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  real_T c9_y;
  SFc9_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc9_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c9_nargout = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_nargout), &c9_thisId);
  sf_mex_destroy(&c9_nargout);
  *(real_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

const mxArray *sf_c9_Walking01_DDA3D_get_eml_resolved_functions_info(void)
{
  const mxArray *c9_nameCaptureInfo = NULL;
  c9_nameCaptureInfo = NULL;
  sf_mex_assign(&c9_nameCaptureInfo, sf_mex_createstruct("structure", 2, 3, 1),
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
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("abs"), "name", "name", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1363731852U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1395949856U), "fileTimeLo",
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
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context",
                  "context", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("eml_scalar_abs"), "name",
                  "name", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c9_info, c9_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                  "resolved", "resolved", 2);
  sf_mex_addfield(*c9_info, c9_b_emlrt_marshallOut(1286840312U), "fileTimeLo",
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
  sf_mex_destroy(&c9_rhs0);
  sf_mex_destroy(&c9_lhs0);
  sf_mex_destroy(&c9_rhs1);
  sf_mex_destroy(&c9_lhs1);
  sf_mex_destroy(&c9_rhs2);
  sf_mex_destroy(&c9_lhs2);
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

static boolean_T c9_check_error(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  boolean_T c9_err;
  uint32_T c9_debug_family_var_map[3];
  real_T c9_nargin = 0.0;
  real_T c9_nargout = 1.0;
  real_T c9_hoistedGlobal;
  real_T c9_b_hoistedGlobal;
  real_T c9_x;
  real_T c9_b_x;
  real_T c9_y;
  boolean_T c9_b1;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  _SFD_SET_DATA_VALUE_PTR(14U, &c9_err);
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 3U, 3U, c9_debug_family_names,
    c9_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargin, 0U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_nargout, 1U, c9_b_sf_marshallOut,
    c9_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c9_err, 2U, c9_sf_marshallOut,
    c9_sf_marshallIn);
  CV_EML_FCN(5, 0);
  _SFD_EML_CALL(5U, *chartInstance->c9_sfEvent, 3);
  guard1 = false;
  guard2 = false;
  if (*chartInstance->c9_q < (*chartInstance->c9_q_limits)[0]) {
    guard2 = true;
  } else if (*chartInstance->c9_q > (*chartInstance->c9_q_limits)[1]) {
    guard2 = true;
  } else {
    c9_hoistedGlobal = *chartInstance->c9_q;
    c9_b_hoistedGlobal = *chartInstance->c9_q_clean;
    c9_x = c9_hoistedGlobal - c9_b_hoistedGlobal;
    c9_b_x = c9_x;
    c9_y = muDoubleScalarAbs(c9_b_x);
    if (c9_y > (*chartInstance->c9_ErrorCount + 1.0) *
        *chartInstance->c9_Threshold) {
      guard1 = true;
    } else {
      c9_b1 = false;
    }
  }

  if (guard2 == true) {
    guard1 = true;
  }

  if (guard1 == true) {
    c9_b1 = true;
  }

  c9_err = c9_b1;
  _SFD_EML_CALL(5U, *chartInstance->c9_sfEvent, -3);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_UNSET_DATA_VALUE_PTR(14U);
  return c9_err;
}

static const mxArray *c9_c_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc9_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(int32_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static int32_T c9_d_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  int32_T c9_y;
  int32_T c9_i1;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_i1, 1, 6, 0U, 0, 0U, 0);
  c9_y = c9_i1;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_sfEvent;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  int32_T c9_y;
  SFc9_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc9_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c9_b_sfEvent = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_sfEvent),
    &c9_thisId);
  sf_mex_destroy(&c9_b_sfEvent);
  *(int32_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_d_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  uint8_T c9_u;
  const mxArray *c9_y = NULL;
  SFc9_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc9_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  c9_u = *(uint8_T *)c9_inData;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", &c9_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static uint8_T c9_e_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_b_is_Run, const char_T *c9_identifier)
{
  uint8_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_is_Run),
    &c9_thisId);
  sf_mex_destroy(&c9_b_is_Run);
  return c9_y;
}

static uint8_T c9_f_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint8_T c9_y;
  uint8_T c9_u1;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u1, 1, 3, 0U, 0, 0U, 0);
  c9_y = c9_u1;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void c9_d_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c9_mxArrayInData, const char_T *c9_varName, void *c9_outData)
{
  const mxArray *c9_b_is_Run;
  const char_T *c9_identifier;
  emlrtMsgIdentifier c9_thisId;
  uint8_T c9_y;
  SFc9_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc9_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c9_b_is_Run = sf_mex_dup(c9_mxArrayInData);
  c9_identifier = c9_varName;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_f_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_is_Run),
    &c9_thisId);
  sf_mex_destroy(&c9_b_is_Run);
  *(uint8_T *)c9_outData = c9_y;
  sf_mex_destroy(&c9_mxArrayInData);
}

static const mxArray *c9_e_sf_marshallOut(void *chartInstanceVoid, void
  *c9_inData)
{
  const mxArray *c9_mxArrayOutData = NULL;
  int32_T c9_i2;
  real_T c9_b_inData[2];
  int32_T c9_i3;
  real_T c9_u[2];
  const mxArray *c9_y = NULL;
  SFc9_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc9_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c9_mxArrayOutData = NULL;
  for (c9_i2 = 0; c9_i2 < 2; c9_i2++) {
    c9_b_inData[c9_i2] = (*(real_T (*)[2])c9_inData)[c9_i2];
  }

  for (c9_i3 = 0; c9_i3 < 2; c9_i3++) {
    c9_u[c9_i3] = c9_b_inData[c9_i3];
  }

  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_create("y", c9_u, 0, 0U, 1U, 0U, 1, 2), false);
  sf_mex_assign(&c9_mxArrayOutData, c9_y, false);
  return c9_mxArrayOutData;
}

static uint32_T c9_g_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_b_temporalCounter_i1, const char_T
  *c9_identifier)
{
  uint32_T c9_y;
  emlrtMsgIdentifier c9_thisId;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  c9_y = c9_h_emlrt_marshallIn(chartInstance, sf_mex_dup(c9_b_temporalCounter_i1),
    &c9_thisId);
  sf_mex_destroy(&c9_b_temporalCounter_i1);
  return c9_y;
}

static uint32_T c9_h_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  uint32_T c9_y;
  uint32_T c9_u2;
  (void)chartInstance;
  sf_mex_import(c9_parentId, sf_mex_dup(c9_u), &c9_u2, 1, 7, 0U, 0, 0U, 0);
  c9_y = c9_u2;
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static const mxArray *c9_i_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_b_setSimStateSideEffectsInfo, const char_T
  *c9_identifier)
{
  const mxArray *c9_y = NULL;
  emlrtMsgIdentifier c9_thisId;
  c9_y = NULL;
  c9_thisId.fIdentifier = c9_identifier;
  c9_thisId.fParent = NULL;
  sf_mex_assign(&c9_y, c9_j_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c9_b_setSimStateSideEffectsInfo), &c9_thisId), false);
  sf_mex_destroy(&c9_b_setSimStateSideEffectsInfo);
  return c9_y;
}

static const mxArray *c9_j_emlrt_marshallIn(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c9_u, const emlrtMsgIdentifier *c9_parentId)
{
  const mxArray *c9_y = NULL;
  (void)chartInstance;
  (void)c9_parentId;
  c9_y = NULL;
  sf_mex_assign(&c9_y, sf_mex_duplicatearraysafe(&c9_u), false);
  sf_mex_destroy(&c9_u);
  return c9_y;
}

static void init_dsm_address_info(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc9_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c9_sfEvent = (int32_T *)ssGetDWork_wrapper(chartInstance->S, 0);
  chartInstance->c9_isStable = (boolean_T *)ssGetDWork_wrapper(chartInstance->S,
    1);
  chartInstance->c9_is_active_c9_Walking01_DDA3D = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 2);
  chartInstance->c9_is_c9_Walking01_DDA3D = (uint8_T *)ssGetDWork_wrapper
    (chartInstance->S, 3);
  chartInstance->c9_is_Run = (uint8_T *)ssGetDWork_wrapper(chartInstance->S, 4);
  chartInstance->c9_q = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    0);
  chartInstance->c9_dq = (real_T *)ssGetInputPortSignal_wrapper(chartInstance->S,
    1);
  chartInstance->c9_Counter = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c9_q_clean = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c9_ErrorCount = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c9_q_last = (real_T *)ssGetDWork_wrapper(chartInstance->S, 5);
  chartInstance->c9_dq_last = (real_T *)ssGetDWork_wrapper(chartInstance->S, 6);
  chartInstance->c9_q_limits = (real_T (*)[2])ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c9_Threshold = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 4);
  chartInstance->c9_Reset = (boolean_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 5);
  chartInstance->c9_ANOMALY_DT = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 6);
  chartInstance->c9_Counter_last = (real_T *)ssGetDWork_wrapper(chartInstance->S,
    7);
  chartInstance->c9_temporalCounter_i1 = (uint32_T *)ssGetDWork_wrapper
    (chartInstance->S, 8);
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
void sf_c9_Walking01_DDA3D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1368240904U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2568106752U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3437178597U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3231854645U);
}

mxArray* sf_c9_Walking01_DDA3D_get_post_codegen_info(void);
mxArray *sf_c9_Walking01_DDA3D_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("rmLs1hEgNboBi0ypdo8omE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,7,3,dataFields);

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
      pr[0] = (double)(2);
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
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(1));
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
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c9_Walking01_DDA3D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c9_Walking01_DDA3D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c9_Walking01_DDA3D_jit_fallback_info(void)
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

mxArray *sf_c9_Walking01_DDA3D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c9_Walking01_DDA3D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c9_Walking01_DDA3D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x9'type','srcId','name','auxInfo'{{M[1],M[12],T\"ErrorCount\",},{M[1],M[8],T\"q_clean\",},{M[3],M[34],T\"Counter_last\",},{M[3],M[18],T\"dq_last\",},{M[3],M[17],T\"q_last\",},{M[8],M[0],T\"is_active_c9_Walking01_DDA3D\",},{M[9],M[0],T\"is_c9_Walking01_DDA3D\",},{M[9],M[27],T\"is_Run\",},{M[11],M[0],T\"temporalCounter_i1\",S'et','os','ct'{{T\"wu\",M[20],M[1]}}}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 9, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c9_Walking01_DDA3D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc9_Walking01_DDA3DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc9_Walking01_DDA3DInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_DDA3DMachineNumber_,
           9,
           6,
           9,
           0,
           15,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"q");
          _SFD_SET_DATA_PROPS(1,1,1,0,"dq");
          _SFD_SET_DATA_PROPS(2,1,1,0,"Counter");
          _SFD_SET_DATA_PROPS(3,2,0,1,"q_clean");
          _SFD_SET_DATA_PROPS(4,2,0,1,"ErrorCount");
          _SFD_SET_DATA_PROPS(5,10,0,0,"MAX_ANOMALY");
          _SFD_SET_DATA_PROPS(6,0,0,0,"q_last");
          _SFD_SET_DATA_PROPS(7,0,0,0,"dq_last");
          _SFD_SET_DATA_PROPS(8,10,0,0,"ANOMALY_INIT");
          _SFD_SET_DATA_PROPS(9,1,1,0,"q_limits");
          _SFD_SET_DATA_PROPS(10,1,1,0,"Threshold");
          _SFD_SET_DATA_PROPS(11,1,1,0,"Reset");
          _SFD_SET_DATA_PROPS(12,1,1,0,"ANOMALY_DT");
          _SFD_SET_DATA_PROPS(13,0,0,0,"Counter_last");
          _SFD_SET_DATA_PROPS(14,9,0,0,"");
          _SFD_STATE_INFO(0,0,0);
          _SFD_STATE_INFO(1,0,0);
          _SFD_STATE_INFO(2,0,0);
          _SFD_STATE_INFO(3,0,0);
          _SFD_STATE_INFO(4,0,0);
          _SFD_STATE_INFO(5,0,2);
          _SFD_CH_SUBSTATE_COUNT(2);
          _SFD_CH_SUBSTATE_DECOMP(0);
          _SFD_CH_SUBSTATE_INDEX(0,0);
          _SFD_CH_SUBSTATE_INDEX(1,1);
          _SFD_ST_SUBSTATE_COUNT(0,0);
          _SFD_ST_SUBSTATE_COUNT(1,3);
          _SFD_ST_SUBSTATE_INDEX(1,0,2);
          _SFD_ST_SUBSTATE_INDEX(1,1,3);
          _SFD_ST_SUBSTATE_INDEX(1,2,4);
          _SFD_ST_SUBSTATE_COUNT(2,0);
          _SFD_ST_SUBSTATE_COUNT(3,0);
          _SFD_ST_SUBSTATE_COUNT(4,0);
        }

        _SFD_CV_INIT_CHART(2,1,0,0);

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

        _SFD_CV_INIT_TRANS(2,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 2, 11 };

          static unsigned int sEndGuardMap[] = { 7, 36 };

          static int sPostFixPredicateTree[] = { 0, -1, 1, -3 };

          _SFD_CV_INIT_TRANS(3,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),4,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 6 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(4,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 23 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(1,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 1 };

          static unsigned int sEndRelationalopMap[] = { 23 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 4 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(1,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(5,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1, 6 };

          static unsigned int sEndGuardMap[] = { 2, 29 };

          static int sPostFixPredicateTree[] = { 0, 1, -3 };

          _SFD_CV_INIT_TRANS(7,2,&(sStartGuardMap[0]),&(sEndGuardMap[0]),3,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartRelationalopMap[] = { 6 };

          static unsigned int sEndRelationalopMap[] = { 29 };

          static int sRelationalopEps[] = { -1 };

          static int sRelationalopType[] = { 0 };

          _SFD_CV_INIT_TRANSITION_RELATIONALOP(7,1,&(sStartRelationalopMap[0]),
            &(sEndRelationalopMap[0]),&(sRelationalopEps[0]),
            &(sRelationalopType[0]));
        }

        _SFD_CV_INIT_TRANS(8,0,NULL,NULL,0,NULL);

        {
          static unsigned int sStartGuardMap[] = { 1 };

          static unsigned int sEndGuardMap[] = { 14 };

          static int sPostFixPredicateTree[] = { 0 };

          _SFD_CV_INIT_TRANS(0,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),1,
                             &(sPostFixPredicateTree[0]));
        }

        {
          static unsigned int sStartGuardMap[] = { 2 };

          static unsigned int sEndGuardMap[] = { 15 };

          static int sPostFixPredicateTree[] = { 0, -1 };

          _SFD_CV_INIT_TRANS(6,1,&(sStartGuardMap[0]),&(sEndGuardMap[0]),2,
                             &(sPostFixPredicateTree[0]));
        }

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(5,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(5,0,"check_error",0,-1,151);
        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(8,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);

        {
          unsigned int dimVector[1];
          dimVector[0]= 2;
          _SFD_SET_DATA_COMPILED_PROPS(9,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c9_e_sf_marshallOut,(MexInFcnForType)NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(10,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(11,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(12,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(13,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_b_sf_marshallOut,(MexInFcnForType)c9_b_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(14,SF_UINT8,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c9_sf_marshallOut,(MexInFcnForType)c9_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(14,(void *)(NULL));
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c9_q);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c9_dq);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c9_Counter);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c9_q_clean);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c9_ErrorCount);
        _SFD_SET_DATA_VALUE_PTR(5U, &chartInstance->c9_MAX_ANOMALY);
        _SFD_SET_DATA_VALUE_PTR(6U, chartInstance->c9_q_last);
        _SFD_SET_DATA_VALUE_PTR(7U, chartInstance->c9_dq_last);
        _SFD_SET_DATA_VALUE_PTR(8U, &chartInstance->c9_ANOMALY_INIT);
        _SFD_SET_DATA_VALUE_PTR(9U, *chartInstance->c9_q_limits);
        _SFD_SET_DATA_VALUE_PTR(10U, chartInstance->c9_Threshold);
        _SFD_SET_DATA_VALUE_PTR(11U, chartInstance->c9_Reset);
        _SFD_SET_DATA_VALUE_PTR(12U, chartInstance->c9_ANOMALY_DT);
        _SFD_SET_DATA_VALUE_PTR(13U, chartInstance->c9_Counter_last);
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
  return "VHMA4mlzML9q61UItY3YMB";
}

static void sf_check_dwork_consistency(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    const uint32_T *sfunDWorkChecksum = sf_get_sfun_dwork_checksum();
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    mxArray* mxRTWDWorkChecksum = sf_get_dwork_info_from_mat_file(S,
      sf_get_instance_specialization(), infoStruct, 9, "dworkChecksum");
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

static void sf_opaque_initialize_c9_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_check_dwork_consistency(((SFc9_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S);
  chart_debug_initialization(((SFc9_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c9_Walking01_DDA3D((SFc9_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
  initialize_c9_Walking01_DDA3D((SFc9_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c9_Walking01_DDA3D(void *chartInstanceVar)
{
  enable_c9_Walking01_DDA3D((SFc9_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c9_Walking01_DDA3D(void *chartInstanceVar)
{
  disable_c9_Walking01_DDA3D((SFc9_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c9_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_gateway_c9_Walking01_DDA3D((SFc9_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_ext_mode_exec_c9_Walking01_DDA3D(void *chartInstanceVar)
{
  ext_mode_exec_c9_Walking01_DDA3D((SFc9_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c9_Walking01_DDA3D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c9_Walking01_DDA3D((SFc9_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c9_Walking01_DDA3D(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c9_Walking01_DDA3D((SFc9_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c9_Walking01_DDA3D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc9_Walking01_DDA3DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_DDA3D_optimization_info();
    }

    finalize_c9_Walking01_DDA3D((SFc9_Walking01_DDA3DInstanceStruct*)
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
  initSimStructsc9_Walking01_DDA3D((SFc9_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c9_Walking01_DDA3D(SimStruct *S)
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
    initialize_params_c9_Walking01_DDA3D((SFc9_Walking01_DDA3DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

mxArray *sf_c9_Walking01_DDA3D_get_testpoint_info(void)
{
  return NULL;
}

static void sf_set_sfun_dwork_info(SimStruct *S)
{
  const char *dworkEncStr[] = {
    "100 S1x9'type','isSigned','wordLength','bias','slope','exponent','isScaledDouble','isComplex','size'{{T\"int32\",,,,,,,M[0],M[]},{T\"boolean\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"uint8\",,,,,,,M[0],M[]},{T\"double\",,,,,,,M[0],M[]},{T\"double\",,,,,,,M[0],M[]},{T\"double\",,,,,,,M[0],M[]},{T\"uint32\",,,,,,,M[0],M[]}}"
  };

  sf_set_encoded_dwork_info(S, dworkEncStr, 9, 10);
}

static uint32_T* sf_get_sfun_dwork_checksum()
{
  static uint32_T checksum[4] = { 1672225869U, 1074911835U, 3625433105U,
    1239145603U };

  return checksum;
}

static void mdlSetWorkWidths_c9_Walking01_DDA3D(SimStruct *S)
{
  /* Actual parameters from chart:
     ANOMALY_INIT MAX_ANOMALY
   */
  const char_T *rtParamNames[] = { "ANOMALY_INIT", "MAX_ANOMALY" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for ANOMALY_INIT*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);

  /* registration for MAX_ANOMALY*/
  ssRegDlgParamAsRunTimeParam(S, 1, 1, rtParamNames[1], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
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
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 4, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 5, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 6, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,9,7);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,9,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 7; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,9);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
    sf_set_sfun_dwork_info(S);
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3720808796U));
  ssSetChecksum1(S,(4058630828U));
  ssSetChecksum2(S,(2115828798U));
  ssSetChecksum3(S,(1454417581U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c9_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Stateflow");
  }
}

static void mdlStart_c9_Walking01_DDA3D(SimStruct *S)
{
  SFc9_Walking01_DDA3DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc9_Walking01_DDA3DInstanceStruct *)utMalloc(sizeof
    (SFc9_Walking01_DDA3DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc9_Walking01_DDA3DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c9_Walking01_DDA3D;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c9_Walking01_DDA3D;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c9_Walking01_DDA3D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c9_Walking01_DDA3D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c9_Walking01_DDA3D;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c9_Walking01_DDA3D;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c9_Walking01_DDA3D;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c9_Walking01_DDA3D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c9_Walking01_DDA3D;
  chartInstance->chartInfo.mdlStart = mdlStart_c9_Walking01_DDA3D;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c9_Walking01_DDA3D;
  chartInstance->chartInfo.extModeExec =
    sf_opaque_ext_mode_exec_c9_Walking01_DDA3D;
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

void c9_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c9_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c9_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c9_Walking01_DDA3D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c9_Walking01_DDA3D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
