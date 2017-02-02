/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Walking01_DDA3D_sfun.h"
#include "c48_Walking01_DDA3D.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Walking01_DDA3D_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c48_debug_family_names[4] = { "nargin", "nargout", "u",
  "u_zeroed" };

/* Function Declarations */
static void initialize_c48_Walking01_DDA3D(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initialize_params_c48_Walking01_DDA3D
  (SFc48_Walking01_DDA3DInstanceStruct *chartInstance);
static void enable_c48_Walking01_DDA3D(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void disable_c48_Walking01_DDA3D(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void c48_update_debugger_state_c48_Walking01_DDA3D
  (SFc48_Walking01_DDA3DInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c48_Walking01_DDA3D
  (SFc48_Walking01_DDA3DInstanceStruct *chartInstance);
static void set_sim_state_c48_Walking01_DDA3D
  (SFc48_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c48_st);
static void finalize_c48_Walking01_DDA3D(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void sf_gateway_c48_Walking01_DDA3D(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void mdl_start_c48_Walking01_DDA3D(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void initSimStructsc48_Walking01_DDA3D
  (SFc48_Walking01_DDA3DInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c48_machineNumber, uint32_T
  c48_chartNumber, uint32_T c48_instanceNumber);
static const mxArray *c48_sf_marshallOut(void *chartInstanceVoid, void
  *c48_inData);
static void c48_emlrt_marshallIn(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c48_b_u_zeroed, const char_T *c48_identifier,
  real_T c48_y[6]);
static void c48_b_emlrt_marshallIn(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c48_b_u, const emlrtMsgIdentifier *c48_parentId,
  real_T c48_y[6]);
static void c48_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c48_mxArrayInData, const char_T *c48_varName, void *c48_outData);
static const mxArray *c48_b_sf_marshallOut(void *chartInstanceVoid, void
  *c48_inData);
static real_T c48_c_emlrt_marshallIn(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c48_b_u, const emlrtMsgIdentifier *c48_parentId);
static void c48_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c48_mxArrayInData, const char_T *c48_varName, void *c48_outData);
static const mxArray *c48_c_sf_marshallOut(void *chartInstanceVoid, void
  *c48_inData);
static int32_T c48_d_emlrt_marshallIn(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c48_b_u, const emlrtMsgIdentifier *c48_parentId);
static void c48_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c48_mxArrayInData, const char_T *c48_varName, void *c48_outData);
static uint8_T c48_e_emlrt_marshallIn(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c48_b_is_active_c48_Walking01_DDA3D, const
  char_T *c48_identifier);
static uint8_T c48_f_emlrt_marshallIn(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c48_b_u, const emlrtMsgIdentifier *c48_parentId);
static void init_dsm_address_info(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance);
static void init_simulink_io_address(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c48_Walking01_DDA3D(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c48_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c48_is_active_c48_Walking01_DDA3D = 0U;
}

static void initialize_params_c48_Walking01_DDA3D
  (SFc48_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void enable_c48_Walking01_DDA3D(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c48_Walking01_DDA3D(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c48_update_debugger_state_c48_Walking01_DDA3D
  (SFc48_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c48_Walking01_DDA3D
  (SFc48_Walking01_DDA3DInstanceStruct *chartInstance)
{
  const mxArray *c48_st;
  const mxArray *c48_y = NULL;
  int32_T c48_i0;
  real_T c48_b_u[6];
  const mxArray *c48_b_y = NULL;
  uint8_T c48_hoistedGlobal;
  uint8_T c48_c_u;
  const mxArray *c48_c_y = NULL;
  c48_st = NULL;
  c48_st = NULL;
  c48_y = NULL;
  sf_mex_assign(&c48_y, sf_mex_createcellmatrix(2, 1), false);
  for (c48_i0 = 0; c48_i0 < 6; c48_i0++) {
    c48_b_u[c48_i0] = (*chartInstance->c48_u_zeroed)[c48_i0];
  }

  c48_b_y = NULL;
  sf_mex_assign(&c48_b_y, sf_mex_create("y", c48_b_u, 0, 0U, 1U, 0U, 1, 6),
                false);
  sf_mex_setcell(c48_y, 0, c48_b_y);
  c48_hoistedGlobal = chartInstance->c48_is_active_c48_Walking01_DDA3D;
  c48_c_u = c48_hoistedGlobal;
  c48_c_y = NULL;
  sf_mex_assign(&c48_c_y, sf_mex_create("y", &c48_c_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c48_y, 1, c48_c_y);
  sf_mex_assign(&c48_st, c48_y, false);
  return c48_st;
}

static void set_sim_state_c48_Walking01_DDA3D
  (SFc48_Walking01_DDA3DInstanceStruct *chartInstance, const mxArray *c48_st)
{
  const mxArray *c48_b_u;
  real_T c48_dv0[6];
  int32_T c48_i1;
  chartInstance->c48_doneDoubleBufferReInit = true;
  c48_b_u = sf_mex_dup(c48_st);
  c48_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c48_b_u, 0)),
                       "u_zeroed", c48_dv0);
  for (c48_i1 = 0; c48_i1 < 6; c48_i1++) {
    (*chartInstance->c48_u_zeroed)[c48_i1] = c48_dv0[c48_i1];
  }

  chartInstance->c48_is_active_c48_Walking01_DDA3D = c48_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c48_b_u, 1)),
     "is_active_c48_Walking01_DDA3D");
  sf_mex_destroy(&c48_b_u);
  c48_update_debugger_state_c48_Walking01_DDA3D(chartInstance);
  sf_mex_destroy(&c48_st);
}

static void finalize_c48_Walking01_DDA3D(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c48_Walking01_DDA3D(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  int32_T c48_i2;
  int32_T c48_i3;
  real_T c48_b_u[6];
  uint32_T c48_debug_family_var_map[4];
  real_T c48_nargin = 1.0;
  real_T c48_nargout = 1.0;
  real_T c48_b_u_zeroed[6];
  int32_T c48_i4;
  int32_T c48_i5;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 16U, chartInstance->c48_sfEvent);
  for (c48_i2 = 0; c48_i2 < 6; c48_i2++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c48_u)[c48_i2], 0U);
  }

  chartInstance->c48_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 16U, chartInstance->c48_sfEvent);
  for (c48_i3 = 0; c48_i3 < 6; c48_i3++) {
    c48_b_u[c48_i3] = (*chartInstance->c48_u)[c48_i3];
  }

  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 4U, 4U, c48_debug_family_names,
    c48_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c48_nargin, 0U, c48_b_sf_marshallOut,
    c48_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c48_nargout, 1U, c48_b_sf_marshallOut,
    c48_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(c48_b_u, 2U, c48_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c48_b_u_zeroed, 3U, c48_sf_marshallOut,
    c48_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c48_sfEvent, 10);
  c48_b_u_zeroed[0] = 0.0;
  c48_b_u_zeroed[1] = 0.0;
  c48_b_u_zeroed[2] = c48_b_u[2];
  c48_b_u_zeroed[3] = 0.0;
  c48_b_u_zeroed[4] = 0.0;
  c48_b_u_zeroed[5] = c48_b_u[5];
  _SFD_EML_CALL(0U, chartInstance->c48_sfEvent, -10);
  _SFD_SYMBOL_SCOPE_POP();
  for (c48_i4 = 0; c48_i4 < 6; c48_i4++) {
    (*chartInstance->c48_u_zeroed)[c48_i4] = c48_b_u_zeroed[c48_i4];
  }

  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 16U, chartInstance->c48_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Walking01_DDA3DMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
  for (c48_i5 = 0; c48_i5 < 6; c48_i5++) {
    _SFD_DATA_RANGE_CHECK((*chartInstance->c48_u_zeroed)[c48_i5], 1U);
  }
}

static void mdl_start_c48_Walking01_DDA3D(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc48_Walking01_DDA3D
  (SFc48_Walking01_DDA3DInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c48_machineNumber, uint32_T
  c48_chartNumber, uint32_T c48_instanceNumber)
{
  (void)c48_machineNumber;
  (void)c48_chartNumber;
  (void)c48_instanceNumber;
}

static const mxArray *c48_sf_marshallOut(void *chartInstanceVoid, void
  *c48_inData)
{
  const mxArray *c48_mxArrayOutData = NULL;
  int32_T c48_i6;
  real_T c48_b_inData[6];
  int32_T c48_i7;
  real_T c48_b_u[6];
  const mxArray *c48_y = NULL;
  SFc48_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc48_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c48_mxArrayOutData = NULL;
  for (c48_i6 = 0; c48_i6 < 6; c48_i6++) {
    c48_b_inData[c48_i6] = (*(real_T (*)[6])c48_inData)[c48_i6];
  }

  for (c48_i7 = 0; c48_i7 < 6; c48_i7++) {
    c48_b_u[c48_i7] = c48_b_inData[c48_i7];
  }

  c48_y = NULL;
  sf_mex_assign(&c48_y, sf_mex_create("y", c48_b_u, 0, 0U, 1U, 0U, 1, 6), false);
  sf_mex_assign(&c48_mxArrayOutData, c48_y, false);
  return c48_mxArrayOutData;
}

static void c48_emlrt_marshallIn(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c48_b_u_zeroed, const char_T *c48_identifier,
  real_T c48_y[6])
{
  emlrtMsgIdentifier c48_thisId;
  c48_thisId.fIdentifier = c48_identifier;
  c48_thisId.fParent = NULL;
  c48_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c48_b_u_zeroed), &c48_thisId,
    c48_y);
  sf_mex_destroy(&c48_b_u_zeroed);
}

static void c48_b_emlrt_marshallIn(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c48_b_u, const emlrtMsgIdentifier *c48_parentId,
  real_T c48_y[6])
{
  real_T c48_dv1[6];
  int32_T c48_i8;
  (void)chartInstance;
  sf_mex_import(c48_parentId, sf_mex_dup(c48_b_u), c48_dv1, 1, 0, 0U, 1, 0U, 1,
                6);
  for (c48_i8 = 0; c48_i8 < 6; c48_i8++) {
    c48_y[c48_i8] = c48_dv1[c48_i8];
  }

  sf_mex_destroy(&c48_b_u);
}

static void c48_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c48_mxArrayInData, const char_T *c48_varName, void *c48_outData)
{
  const mxArray *c48_b_u_zeroed;
  const char_T *c48_identifier;
  emlrtMsgIdentifier c48_thisId;
  real_T c48_y[6];
  int32_T c48_i9;
  SFc48_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc48_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c48_b_u_zeroed = sf_mex_dup(c48_mxArrayInData);
  c48_identifier = c48_varName;
  c48_thisId.fIdentifier = c48_identifier;
  c48_thisId.fParent = NULL;
  c48_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c48_b_u_zeroed), &c48_thisId,
    c48_y);
  sf_mex_destroy(&c48_b_u_zeroed);
  for (c48_i9 = 0; c48_i9 < 6; c48_i9++) {
    (*(real_T (*)[6])c48_outData)[c48_i9] = c48_y[c48_i9];
  }

  sf_mex_destroy(&c48_mxArrayInData);
}

static const mxArray *c48_b_sf_marshallOut(void *chartInstanceVoid, void
  *c48_inData)
{
  const mxArray *c48_mxArrayOutData = NULL;
  real_T c48_b_u;
  const mxArray *c48_y = NULL;
  SFc48_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc48_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c48_mxArrayOutData = NULL;
  c48_b_u = *(real_T *)c48_inData;
  c48_y = NULL;
  sf_mex_assign(&c48_y, sf_mex_create("y", &c48_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c48_mxArrayOutData, c48_y, false);
  return c48_mxArrayOutData;
}

static real_T c48_c_emlrt_marshallIn(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c48_b_u, const emlrtMsgIdentifier *c48_parentId)
{
  real_T c48_y;
  real_T c48_d0;
  (void)chartInstance;
  sf_mex_import(c48_parentId, sf_mex_dup(c48_b_u), &c48_d0, 1, 0, 0U, 0, 0U, 0);
  c48_y = c48_d0;
  sf_mex_destroy(&c48_b_u);
  return c48_y;
}

static void c48_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c48_mxArrayInData, const char_T *c48_varName, void *c48_outData)
{
  const mxArray *c48_nargout;
  const char_T *c48_identifier;
  emlrtMsgIdentifier c48_thisId;
  real_T c48_y;
  SFc48_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc48_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c48_nargout = sf_mex_dup(c48_mxArrayInData);
  c48_identifier = c48_varName;
  c48_thisId.fIdentifier = c48_identifier;
  c48_thisId.fParent = NULL;
  c48_y = c48_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c48_nargout),
    &c48_thisId);
  sf_mex_destroy(&c48_nargout);
  *(real_T *)c48_outData = c48_y;
  sf_mex_destroy(&c48_mxArrayInData);
}

const mxArray *sf_c48_Walking01_DDA3D_get_eml_resolved_functions_info(void)
{
  const mxArray *c48_nameCaptureInfo = NULL;
  c48_nameCaptureInfo = NULL;
  sf_mex_assign(&c48_nameCaptureInfo, sf_mex_create("nameCaptureInfo", NULL, 0,
    0U, 1U, 0U, 2, 0, 1), false);
  return c48_nameCaptureInfo;
}

static const mxArray *c48_c_sf_marshallOut(void *chartInstanceVoid, void
  *c48_inData)
{
  const mxArray *c48_mxArrayOutData = NULL;
  int32_T c48_b_u;
  const mxArray *c48_y = NULL;
  SFc48_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc48_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c48_mxArrayOutData = NULL;
  c48_b_u = *(int32_T *)c48_inData;
  c48_y = NULL;
  sf_mex_assign(&c48_y, sf_mex_create("y", &c48_b_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c48_mxArrayOutData, c48_y, false);
  return c48_mxArrayOutData;
}

static int32_T c48_d_emlrt_marshallIn(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c48_b_u, const emlrtMsgIdentifier *c48_parentId)
{
  int32_T c48_y;
  int32_T c48_i10;
  (void)chartInstance;
  sf_mex_import(c48_parentId, sf_mex_dup(c48_b_u), &c48_i10, 1, 6, 0U, 0, 0U, 0);
  c48_y = c48_i10;
  sf_mex_destroy(&c48_b_u);
  return c48_y;
}

static void c48_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c48_mxArrayInData, const char_T *c48_varName, void *c48_outData)
{
  const mxArray *c48_b_sfEvent;
  const char_T *c48_identifier;
  emlrtMsgIdentifier c48_thisId;
  int32_T c48_y;
  SFc48_Walking01_DDA3DInstanceStruct *chartInstance;
  chartInstance = (SFc48_Walking01_DDA3DInstanceStruct *)chartInstanceVoid;
  c48_b_sfEvent = sf_mex_dup(c48_mxArrayInData);
  c48_identifier = c48_varName;
  c48_thisId.fIdentifier = c48_identifier;
  c48_thisId.fParent = NULL;
  c48_y = c48_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c48_b_sfEvent),
    &c48_thisId);
  sf_mex_destroy(&c48_b_sfEvent);
  *(int32_T *)c48_outData = c48_y;
  sf_mex_destroy(&c48_mxArrayInData);
}

static uint8_T c48_e_emlrt_marshallIn(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c48_b_is_active_c48_Walking01_DDA3D, const
  char_T *c48_identifier)
{
  uint8_T c48_y;
  emlrtMsgIdentifier c48_thisId;
  c48_thisId.fIdentifier = c48_identifier;
  c48_thisId.fParent = NULL;
  c48_y = c48_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c48_b_is_active_c48_Walking01_DDA3D), &c48_thisId);
  sf_mex_destroy(&c48_b_is_active_c48_Walking01_DDA3D);
  return c48_y;
}

static uint8_T c48_f_emlrt_marshallIn(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance, const mxArray *c48_b_u, const emlrtMsgIdentifier *c48_parentId)
{
  uint8_T c48_y;
  uint8_T c48_u0;
  (void)chartInstance;
  sf_mex_import(c48_parentId, sf_mex_dup(c48_b_u), &c48_u0, 1, 3, 0U, 0, 0U, 0);
  c48_y = c48_u0;
  sf_mex_destroy(&c48_b_u);
  return c48_y;
}

static void init_dsm_address_info(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address(SFc48_Walking01_DDA3DInstanceStruct
  *chartInstance)
{
  chartInstance->c48_u = (real_T (*)[6])ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c48_u_zeroed = (real_T (*)[6])ssGetOutputPortSignal_wrapper
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

void sf_c48_Walking01_DDA3D_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1570600044U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(212795851U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2815571717U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2282375541U);
}

mxArray* sf_c48_Walking01_DDA3D_get_post_codegen_info(void);
mxArray *sf_c48_Walking01_DDA3D_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("JkCKksNvhwLKw3ZRa33DuE");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

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
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo = sf_c48_Walking01_DDA3D_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c48_Walking01_DDA3D_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c48_Walking01_DDA3D_jit_fallback_info(void)
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

mxArray *sf_c48_Walking01_DDA3D_updateBuildInfo_args_info(void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c48_Walking01_DDA3D_get_post_codegen_info(void)
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

static const mxArray *sf_get_sim_state_info_c48_Walking01_DDA3D(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x2'type','srcId','name','auxInfo'{{M[1],M[5],T\"u_zeroed\",},{M[8],M[0],T\"is_active_c48_Walking01_DDA3D\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 2, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c48_Walking01_DDA3D_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc48_Walking01_DDA3DInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc48_Walking01_DDA3DInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Walking01_DDA3DMachineNumber_,
           48,
           1,
           1,
           0,
           2,
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
          _SFD_SET_DATA_PROPS(0,1,1,0,"u");
          _SFD_SET_DATA_PROPS(1,2,0,1,"u_zeroed");
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
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,342);

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c48_sf_marshallOut,(MexInFcnForType)NULL);
        }

        {
          unsigned int dimVector[1];
          dimVector[0]= 6;
          _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,1,&(dimVector[0]),0,0,0,0.0,
            1.0,0,0,(MexFcnForType)c48_sf_marshallOut,(MexInFcnForType)
            c48_sf_marshallIn);
        }

        _SFD_SET_DATA_VALUE_PTR(0U, *chartInstance->c48_u);
        _SFD_SET_DATA_VALUE_PTR(1U, *chartInstance->c48_u_zeroed);
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
  return "SgCli4ihm2yHxkUrzfUrP";
}

static void sf_opaque_initialize_c48_Walking01_DDA3D(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc48_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c48_Walking01_DDA3D((SFc48_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
  initialize_c48_Walking01_DDA3D((SFc48_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c48_Walking01_DDA3D(void *chartInstanceVar)
{
  enable_c48_Walking01_DDA3D((SFc48_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c48_Walking01_DDA3D(void *chartInstanceVar)
{
  disable_c48_Walking01_DDA3D((SFc48_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c48_Walking01_DDA3D(void *chartInstanceVar)
{
  sf_gateway_c48_Walking01_DDA3D((SFc48_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

static const mxArray* sf_opaque_get_sim_state_c48_Walking01_DDA3D(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c48_Walking01_DDA3D((SFc48_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance);         /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c48_Walking01_DDA3D(SimStruct* S, const
  mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c48_Walking01_DDA3D((SFc48_Walking01_DDA3DInstanceStruct*)
    chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c48_Walking01_DDA3D(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc48_Walking01_DDA3DInstanceStruct*) chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Walking01_DDA3D_optimization_info();
    }

    finalize_c48_Walking01_DDA3D((SFc48_Walking01_DDA3DInstanceStruct*)
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
  initSimStructsc48_Walking01_DDA3D((SFc48_Walking01_DDA3DInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c48_Walking01_DDA3D(SimStruct *S)
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
    initialize_params_c48_Walking01_DDA3D((SFc48_Walking01_DDA3DInstanceStruct*)
      (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c48_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Walking01_DDA3D_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,
      48);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,48,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,48,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,48);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,48,1);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,48,1);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=1; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 1; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,48);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(3833561645U));
  ssSetChecksum1(S,(3975778633U));
  ssSetChecksum2(S,(2066315852U));
  ssSetChecksum3(S,(1474731297U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c48_Walking01_DDA3D(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c48_Walking01_DDA3D(SimStruct *S)
{
  SFc48_Walking01_DDA3DInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc48_Walking01_DDA3DInstanceStruct *)utMalloc(sizeof
    (SFc48_Walking01_DDA3DInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc48_Walking01_DDA3DInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c48_Walking01_DDA3D;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c48_Walking01_DDA3D;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c48_Walking01_DDA3D;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c48_Walking01_DDA3D;
  chartInstance->chartInfo.disableChart = sf_opaque_disable_c48_Walking01_DDA3D;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c48_Walking01_DDA3D;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c48_Walking01_DDA3D;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c48_Walking01_DDA3D;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c48_Walking01_DDA3D;
  chartInstance->chartInfo.mdlStart = mdlStart_c48_Walking01_DDA3D;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c48_Walking01_DDA3D;
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

void c48_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c48_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c48_Walking01_DDA3D(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c48_Walking01_DDA3D(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c48_Walking01_DDA3D_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
