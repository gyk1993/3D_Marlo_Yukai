/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_J_aSymmetry_RightStance_info.c
 *
 * Code generation for function '_coder_J_aSymmetry_RightStance_info'
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "J_aSymmetry_RightStance.h"
#include "_coder_J_aSymmetry_RightStance_info.h"

/* Function Definitions */
mxArray *emlrtMexFcnProperties(void)
{
  mxArray *xResult;
  mxArray *xEntryPoints;
  const char * fldNames[4] = { "Name", "NumberOfInputs", "NumberOfOutputs",
    "ConstantInputs" };

  mxArray *xInputs;
  const char * b_fldNames[4] = { "Version", "ResolvedFunctions", "EntryPoints",
    "CoverageInfo" };

  xEntryPoints = emlrtCreateStructMatrix(1, 1, 4, fldNames);
  xInputs = emlrtCreateLogicalMatrix(1, 1);
  emlrtSetField(xEntryPoints, 0, "Name", mxCreateString(
    "J_aSymmetry_RightStance"));
  emlrtSetField(xEntryPoints, 0, "NumberOfInputs", mxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "NumberOfOutputs", mxCreateDoubleScalar(1.0));
  emlrtSetField(xEntryPoints, 0, "ConstantInputs", xInputs);
  xResult = emlrtCreateStructMatrix(1, 1, 4, b_fldNames);
  emlrtSetField(xResult, 0, "Version", mxCreateString("9.0.0.341360 (R2016a)"));
  emlrtSetField(xResult, 0, "ResolvedFunctions", (mxArray *)
                emlrtMexFcnResolvedFunctionsInfo());
  emlrtSetField(xResult, 0, "EntryPoints", xEntryPoints);
  return xResult;
}

const mxArray *emlrtMexFcnResolvedFunctionsInfo(void)
{
  const mxArray *nameCaptureInfo;
  const char * data[13] = {
    "789ced5b4f6fdc44149fa03494430189035414e85e5051455c4042a8a7a46dd26c4848b4f943688b9c59ef7877d4f1cc6aec0d1b4e0b48a8478e7c048484b872"
    "e50370830fc1811b1f8019af9d78679d1dc7f62e4e3a969ccd5bcf9b79ff7ef3decc78c15c7d1388eb657177f70158109f57c5fd02185e57227a4edc37a2cfe1",
    "f7f3e05a447f2b6e87d100f583e1430a3d04e2abc53c4c210d768fbb0870e43372845ae1131713b48b3db4c112c41a1684b79a787442c847bce39ff40c489218"
    "5e528f1fc1a91ef3297ab4137abc1ad18f57bebc7fd7daf311f7ad06f37deb01737a1ea2816f3dacef5a9bac85c8fb0f11451c068c5b9ea47d0b061c43df6a23",
    "6a793020b069b16e6079d6ba0d778e3d0f05fcd86ee07627d8092075d0a217caf78946be1715f9242d0cd781c28059f81714fe85d00bbd264143fb0c34fc9f2a"
    "fc927e5cdf38084db4cd599b43efa6748a6f6d2eef6e2cdfb31a1fdef9e06368058c9126eb5bc82316c1cdd82688887fac48036183d84f493d1652e4984bc8f1",
    "52f4bd90fee76fbef86b393f3f28387e79fcb712fc7329fc20f199a7fd0054c3cf6b1a39de50e490b42300c617b198543885649142dec6d4e93c95fddd99d05f"
    "7c25fb8be5f84123c71385efc979ed2114e7a86585b2477f6f471fb126d68926430315c0c16b771b7f1a1c64687f11fc9e26d715452e49bb84319e91bf681ea8",
    "2bfcf5f3da656c7e707bd40a3588668742f1f3fbdebb260f94910766e5e76d8d1cef2872485ac903d8bfd7c324a8d3cf4471c6b1530a0e9e69f80f14fe833cf6"
    "91f7d8a4a0aab3e81588a7b59b7f987c7099f0f0a62287a4153cf80e24902fc65961d86fdefa4887833d856f2f8f5d5271707ba847c24645d6079f5f3779e122",
    "e1e05023c77b8a1c92567000bb5d72bc1306d16a8f3a0166b44eb7097450629c25cd38af28e348da8d7ab33b90b608cab4bfd054fa69e6b15b2a4ece56333668"
    "81b8e3ff7e647093a57dd5fd3fadbc32ed3acbe497e70b272d30ea6f4997b8ff548bfeb38f200f17df76c06c1f7f8d62f90e34f2d514f924ade61ddf473cd887",
    "04b77644cfcbbc7d867ff2e045b76ff148e17f94c77ee9f3cc985ac5f3cbc0e93e30b8c9d2beaa7e37eb77b37eaf023e74790581517f4b7a7af8a8615f3e179d"
    "9214fb65ddd7959db819f9abb7af2bf36ea84119fbbabf9afa2a5bfb01a8869f4d5e3079a10a78a8605e68b21e6df9201b4ede52e493f4184eea32d7207e9f88",
    "31817ebf772efaeeb4df79e07420cf828f7d459efdd2ec35aa869c4ccc7adce023cf7c2f86f060bf180e061abe7565dcf53c7619cfa3a1e425ecdb9a7a2963fb"
    "cb1aff985ed4f8c7d4c4ff29fff31effbafae886229fa4d5fa88b6505fd4160d445837d67b5aef0b1e2a7c87e7b55796f7c646342ab28e18fcbd420d4eb2b4ff",
    "0d4cf6fb7760d4ef929eb6df6b2e6130b01d592fdbf2657b88a96fc78de2d540361c5d57e497b482a370b4f0a5f7845da6b5ce6828f234ce6bcf33e79d53354a"
    "38bf30eb8c8ced7f0293fddd07a3fe96f4d4f1837ddbc76d8a5aa3a0317597a9bba68d87aa9ee799b837716fe27e5c2eb3cf64e2be48dc0fc0643f57e57777af",
    "2b72483af53dc095f64ccea5b715feed3c76499d0f62350a9dc3ddfa67cbc47f19f13f2b3f2f69e4b8a6c82169ecd3e1916d207fae3e9bf731b614fead3cf690"
    "f3818bfba8d565c21cd6881e29bf3b3f47dcfc62e6fd8b15f7ba78bdaac82169ecbb586491ce2ce2bdb43a6724de87f29750e79878cfd8fe1998ece7e9bd5f73",
    "1aef3517733f70719eba5cc64c19f1ded7f0af2afcab79ec9012efc5de9b30719eb5fdffeddf25cdf859eb9869ad5b4dfd7239e27c0026fb7956eb56ddf9d5db"
    "8a1c92165ddb226e6c9771c258d7664788bb847d653b1de43cadf839b06a9761da9ba04fa17360b38f93b1bdee1cf87b30ea77494fdbefb5c90dec0e225dc4f3",
    "cdf7713db4a6e1cbb06f149fb155227f9abc6170320927e63cc09c07187c948f0f734e6cf0a16bff1f3de0d529",
    "" };

  nameCaptureInfo = NULL;
  emlrtNameCaptureMxArrayR2016a(data, 22144U, &nameCaptureInfo);
  return nameCaptureInfo;
}

/* End of code generation (_coder_J_aSymmetry_RightStance_info.c) */
