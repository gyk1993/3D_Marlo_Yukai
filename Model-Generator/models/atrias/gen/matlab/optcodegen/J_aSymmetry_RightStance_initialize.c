/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * J_aSymmetry_RightStance_initialize.c
 *
 * Code generation for function 'J_aSymmetry_RightStance_initialize'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "J_aSymmetry_RightStance.h"
#include "J_aSymmetry_RightStance_initialize.h"
#include "_coder_J_aSymmetry_RightStance_mex.h"
#include "J_aSymmetry_RightStance_data.h"

/* Function Definitions */
void J_aSymmetry_RightStance_initialize(void)
{
  emlrtStack st = { NULL, NULL, NULL };

  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, 0);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (J_aSymmetry_RightStance_initialize.c) */
