/* Include files */

#include "LibWalking_sfun.h"
#include "LibWalking_sfun_debug_macros.h"
#include "c5_LibWalking.h"
#include "c12_LibWalking.h"
#include "c13_LibWalking.h"
#include "c22_LibWalking.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _LibWalkingMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void LibWalking_initializer(void)
{
}

void LibWalking_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_LibWalking_method_dispatcher(SimStruct *simstructPtr, unsigned
  int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==5) {
    c5_LibWalking_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==12) {
    c12_LibWalking_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==13) {
    c13_LibWalking_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_LibWalking_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_LibWalking_uses_exported_functions(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_LibWalking_process_testpoint_info_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char machineName[128];
  if (nrhs < 3 || !mxIsChar(prhs[0]) || !mxIsChar(prhs[1]))
    return 0;

  /* Possible call to get testpoint info. */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_testpoint_info"))
    return 0;
  mxGetString(prhs[1], machineName, sizeof(machineName)/sizeof(char));
  machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
  if (!strcmp(machineName, "LibWalking")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 22:
      {
        extern mxArray *sf_c22_LibWalking_get_testpoint_info(void);
        plhs[0] = sf_c22_LibWalking_get_testpoint_info();
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }

    return 1;
  }

  return 0;

#else

  return 0;

#endif

}

unsigned int sf_LibWalking_process_check_sum_call( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[20];
  if (nrhs<1 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the checksum */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"sf_get_check_sum"))
    return 0;
  plhs[0] = mxCreateDoubleMatrix( 1,4,mxREAL);
  if (nrhs>2 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"library")) {
      char machineName[100];
      mxGetString(prhs[2], machineName,sizeof(machineName)/sizeof(char));
      machineName[(sizeof(machineName)/sizeof(char)-1)] = '\0';
      if (!strcmp(machineName,"LibWalking")) {
        if (nrhs==3) {
          ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(934217168U);
          ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2324175733U);
          ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(807929884U);
          ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(642932352U);
        } else if (nrhs==4) {
          unsigned int chartFileNumber;
          chartFileNumber = (unsigned int)mxGetScalar(prhs[3]);
          switch (chartFileNumber) {
           case 5:
            {
              extern void sf_c5_LibWalking_get_check_sum(mxArray *plhs[]);
              sf_c5_LibWalking_get_check_sum(plhs);
              break;
            }

           case 12:
            {
              extern void sf_c12_LibWalking_get_check_sum(mxArray *plhs[]);
              sf_c12_LibWalking_get_check_sum(plhs);
              break;
            }

           case 13:
            {
              extern void sf_c13_LibWalking_get_check_sum(mxArray *plhs[]);
              sf_c13_LibWalking_get_check_sum(plhs);
              break;
            }

           case 22:
            {
              extern void sf_c22_LibWalking_get_check_sum(mxArray *plhs[]);
              sf_c22_LibWalking_get_check_sum(plhs);
              break;
            }

           default:
            ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
            ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
          }
        } else {
          return 0;
        }
      } else {
        return 0;
      }
    } else {
      return 0;
    }
  } else {
    return 0;
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_LibWalking_autoinheritance_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[32];
  char aiChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]) )
    return 0;

  /* Possible call to get the autoinheritance_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_autoinheritance_info"))
    return 0;
  mxGetString(prhs[2], aiChksum,sizeof(aiChksum)/sizeof(char));
  aiChksum[(sizeof(aiChksum)/sizeof(char)-1)] = '\0';

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 5:
      {
        if (strcmp(aiChksum, "Yo05vwjsCH0dErjCih6XQ") == 0) {
          extern mxArray *sf_c5_LibWalking_get_autoinheritance_info(void);
          plhs[0] = sf_c5_LibWalking_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 12:
      {
        if (strcmp(aiChksum, "GUkVMi26Ya3YetSku7IwIC") == 0) {
          extern mxArray *sf_c12_LibWalking_get_autoinheritance_info(void);
          plhs[0] = sf_c12_LibWalking_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 13:
      {
        if (strcmp(aiChksum, "o1hm4vkhKUV3wzhDDCFrxF") == 0) {
          extern mxArray *sf_c13_LibWalking_get_autoinheritance_info(void);
          plhs[0] = sf_c13_LibWalking_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "ilGtnrbzPKen4ko0ysIguD") == 0) {
          extern mxArray *sf_c22_LibWalking_get_autoinheritance_info(void);
          plhs[0] = sf_c22_LibWalking_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_LibWalking_get_eml_resolved_functions_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
{

#ifdef MATLAB_MEX_FILE

  char commandName[64];
  if (nrhs<2 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the get_eml_resolved_functions_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_eml_resolved_functions_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 5:
      {
        extern const mxArray *sf_c5_LibWalking_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_LibWalking_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 12:
      {
        extern const mxArray *sf_c12_LibWalking_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c12_LibWalking_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 13:
      {
        extern const mxArray *sf_c13_LibWalking_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c13_LibWalking_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray *sf_c22_LibWalking_get_eml_resolved_functions_info
          (void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_LibWalking_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_LibWalking_third_party_uses_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the third_party_uses_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_third_party_uses_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 5:
      {
        if (strcmp(tpChksum, "0Zev8eyKjjv7iALhv7B0eG") == 0) {
          extern mxArray *sf_c5_LibWalking_third_party_uses_info(void);
          plhs[0] = sf_c5_LibWalking_third_party_uses_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "3fvRgRfmQpwavI4cWFNMpH") == 0) {
          extern mxArray *sf_c12_LibWalking_third_party_uses_info(void);
          plhs[0] = sf_c12_LibWalking_third_party_uses_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "LuzVU0U1PyESmKdnlgrsEF") == 0) {
          extern mxArray *sf_c13_LibWalking_third_party_uses_info(void);
          plhs[0] = sf_c13_LibWalking_third_party_uses_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "yF6EqtfoCQRl85FFLRc2kF") == 0) {
          extern mxArray *sf_c22_LibWalking_third_party_uses_info(void);
          plhs[0] = sf_c22_LibWalking_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_LibWalking_jit_fallback_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the jit_fallback_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_jit_fallback_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 5:
      {
        if (strcmp(tpChksum, "0Zev8eyKjjv7iALhv7B0eG") == 0) {
          extern mxArray *sf_c5_LibWalking_jit_fallback_info(void);
          plhs[0] = sf_c5_LibWalking_jit_fallback_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "3fvRgRfmQpwavI4cWFNMpH") == 0) {
          extern mxArray *sf_c12_LibWalking_jit_fallback_info(void);
          plhs[0] = sf_c12_LibWalking_jit_fallback_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "LuzVU0U1PyESmKdnlgrsEF") == 0) {
          extern mxArray *sf_c13_LibWalking_jit_fallback_info(void);
          plhs[0] = sf_c13_LibWalking_jit_fallback_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "yF6EqtfoCQRl85FFLRc2kF") == 0) {
          extern mxArray *sf_c22_LibWalking_jit_fallback_info(void);
          plhs[0] = sf_c22_LibWalking_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_LibWalking_updateBuildInfo_args_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  char commandName[64];
  char tpChksum[64];
  if (nrhs<3 || !mxIsChar(prhs[0]))
    return 0;

  /* Possible call to get the updateBuildInfo_args_info */
  mxGetString(prhs[0], commandName,sizeof(commandName)/sizeof(char));
  commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
  mxGetString(prhs[2], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  if (strcmp(commandName,"get_updateBuildInfo_args_info"))
    return 0;

  {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[1]);
    switch (chartFileNumber) {
     case 5:
      {
        if (strcmp(tpChksum, "0Zev8eyKjjv7iALhv7B0eG") == 0) {
          extern mxArray *sf_c5_LibWalking_updateBuildInfo_args_info(void);
          plhs[0] = sf_c5_LibWalking_updateBuildInfo_args_info();
          break;
        }
      }

     case 12:
      {
        if (strcmp(tpChksum, "3fvRgRfmQpwavI4cWFNMpH") == 0) {
          extern mxArray *sf_c12_LibWalking_updateBuildInfo_args_info(void);
          plhs[0] = sf_c12_LibWalking_updateBuildInfo_args_info();
          break;
        }
      }

     case 13:
      {
        if (strcmp(tpChksum, "LuzVU0U1PyESmKdnlgrsEF") == 0) {
          extern mxArray *sf_c13_LibWalking_updateBuildInfo_args_info(void);
          plhs[0] = sf_c13_LibWalking_updateBuildInfo_args_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "yF6EqtfoCQRl85FFLRc2kF") == 0) {
          extern mxArray *sf_c22_LibWalking_updateBuildInfo_args_info(void);
          plhs[0] = sf_c22_LibWalking_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_LibWalking_get_post_codegen_info( int nlhs, mxArray * plhs[], int nrhs,
  const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 5:
    {
      if (strcmp(tpChksum, "0Zev8eyKjjv7iALhv7B0eG") == 0) {
        extern mxArray *sf_c5_LibWalking_get_post_codegen_info(void);
        plhs[0] = sf_c5_LibWalking_get_post_codegen_info();
        return;
      }
    }
    break;

   case 12:
    {
      if (strcmp(tpChksum, "3fvRgRfmQpwavI4cWFNMpH") == 0) {
        extern mxArray *sf_c12_LibWalking_get_post_codegen_info(void);
        plhs[0] = sf_c12_LibWalking_get_post_codegen_info();
        return;
      }
    }
    break;

   case 13:
    {
      if (strcmp(tpChksum, "LuzVU0U1PyESmKdnlgrsEF") == 0) {
        extern mxArray *sf_c13_LibWalking_get_post_codegen_info(void);
        plhs[0] = sf_c13_LibWalking_get_post_codegen_info();
        return;
      }
    }
    break;

   case 22:
    {
      if (strcmp(tpChksum, "yF6EqtfoCQRl85FFLRc2kF") == 0) {
        extern mxArray *sf_c22_LibWalking_get_post_codegen_info(void);
        plhs[0] = sf_c22_LibWalking_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void LibWalking_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _LibWalkingMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "LibWalking","sfun",1,4,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,_LibWalkingMachineNumber_,
    0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,_LibWalkingMachineNumber_,0);
}

void LibWalking_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_LibWalking_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("LibWalking",
      "Walking01_withElmos");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_LibWalking_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
