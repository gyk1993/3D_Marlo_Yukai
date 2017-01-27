/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_J_aSymmetry_RightStance_api.c
 *
 * Code generation for function '_coder_J_aSymmetry_RightStance_api'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "J_aSymmetry_RightStance.h"
#include "_coder_J_aSymmetry_RightStance_api.h"
#include "J_aSymmetry_RightStance_data.h"

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[72];
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[72];
static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *in1, const
  char_T *identifier))[72];
static const mxArray *emlrt_marshallOut(const real_T u[2592]);

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u, const
  emlrtMsgIdentifier *parentId))[72]
{
  real_T (*y)[72];
  y = c_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
  static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
  const emlrtMsgIdentifier *msgId))[72]
{
  real_T (*ret)[72];
  static const int32_T dims[2] = { 1, 72 };

  emlrtCheckBuiltInR2012b(sp, msgId, src, "double", false, 2U, dims);
  ret = (real_T (*)[72])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *in1, const
  char_T *identifier))[72]
{
  real_T (*y)[72];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(in1), &thisId);
  emlrtDestroyArray(&in1);
  return y;
}
  static const mxArray *emlrt_marshallOut(const real_T u[2592])
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv1[2] = { 0, 0 };

  static const int32_T iv2[2] = { 36, 72 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv1, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)u);
  emlrtSetDimensions((mxArray *)m0, iv2, 2);
  emlrtAssign(&y, m0);
  return y;
}

void J_aSymmetry_RightStance_api(const mxArray * const prhs[1], const mxArray
  *plhs[1])
{
  real_T (*out1)[2592];
  real_T (*in1)[72];
  emlrtStack st = { NULL, NULL, NULL };

  st.tls = emlrtRootTLSGlobal;
  out1 = (real_T (*)[2592])mxMalloc(sizeof(real_T [2592]));

  /* Marshall function inputs */
  in1 = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "in1");

  /* Invoke the target function */
  J_aSymmetry_RightStance(*in1, *out1);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*out1);
}

/* End of code generation (_coder_J_aSymmetry_RightStance_api.c) */
