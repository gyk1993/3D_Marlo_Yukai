/* Include files */

#include "DDA2D_OSU3Dv2_cgxe.h"
#include "m_KVvGQhP9zVmL5NQhzh0cxF.h"

static unsigned int cgxeModelInitialized = 0;
emlrtContext emlrtContextGlobal = { true, true, EMLRT_VERSION_INFO, NULL, "",
  NULL, false, { 0, 0, 0, 0 }, NULL };

void *emlrtRootTLSGlobal = NULL;
char cgxeRtErrBuf[4096];

/* CGXE Glue Code */
void cgxe_DDA2D_OSU3Dv2_initializer(void)
{
  if (cgxeModelInitialized == 0) {
    cgxeModelInitialized = 1;
    emlrtRootTLSGlobal = NULL;
    emlrtCreateSimulinkRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
      false, 0);
  }
}

void cgxe_DDA2D_OSU3Dv2_terminator(void)
{
  if (cgxeModelInitialized != 0) {
    cgxeModelInitialized = 0;
    emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
    emlrtRootTLSGlobal = NULL;
  }
}

unsigned int cgxe_DDA2D_OSU3Dv2_method_dispatcher(SimStruct* S, int_T method,
  void* data)
{
  if (ssGetChecksum0(S) == 2155958618 &&
      ssGetChecksum1(S) == 3369238703 &&
      ssGetChecksum2(S) == 191814340 &&
      ssGetChecksum3(S) == 2360837547) {
    method_dispatcher_KVvGQhP9zVmL5NQhzh0cxF(S, method, data);
    return 1;
  }

  return 0;
}

int cgxe_DDA2D_OSU3Dv2_autoInfer_dispatcher(const mxArray* prhs, mxArray* lhs[],
  const char* commandName)
{
  char sid[64];
  mxGetString(prhs,sid, sizeof(sid)/sizeof(char));
  sid[(sizeof(sid)/sizeof(char)-1)] = '\0';
  if (strcmp(sid, "DDA2D_OSU3Dv2:7472:6938") == 0 ) {
    return autoInfer_dispatcher_KVvGQhP9zVmL5NQhzh0cxF(lhs, commandName);
  }

  return 0;
}
