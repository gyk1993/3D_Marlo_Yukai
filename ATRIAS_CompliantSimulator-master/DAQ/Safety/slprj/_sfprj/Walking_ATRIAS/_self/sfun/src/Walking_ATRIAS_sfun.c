/* Include files */

#include "Walking_ATRIAS_sfun.h"
#include "Walking_ATRIAS_sfun_debug_macros.h"
#include "c1_Walking_ATRIAS.h"
#include "c2_Walking_ATRIAS.h"
#include "c4_Walking_ATRIAS.h"
#include "c31_Walking_ATRIAS.h"
#include "c35_Walking_ATRIAS.h"
#include "c36_Walking_ATRIAS.h"
#include "c37_Walking_ATRIAS.h"
#include "c38_Walking_ATRIAS.h"
#include "c39_Walking_ATRIAS.h"
#include "c43_Walking_ATRIAS.h"
#include "c44_Walking_ATRIAS.h"
#include "c45_Walking_ATRIAS.h"
#include "c46_Walking_ATRIAS.h"
#include "c48_Walking_ATRIAS.h"
#include "c49_Walking_ATRIAS.h"
#include "c50_Walking_ATRIAS.h"
#include "c59_Walking_ATRIAS.h"
#include "c60_Walking_ATRIAS.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Walking_ATRIASMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Walking_ATRIAS_initializer(void)
{
}

void Walking_ATRIAS_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Walking_ATRIAS_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==31) {
    c31_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==35) {
    c35_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==38) {
    c38_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==39) {
    c39_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==43) {
    c43_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==44) {
    c44_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==45) {
    c45_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==46) {
    c46_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==48) {
    c48_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==49) {
    c49_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==50) {
    c50_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==59) {
    c59_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==60) {
    c60_Walking_ATRIAS_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_Walking_ATRIAS_uses_exported_functions(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_Walking_ATRIAS_process_testpoint_info_call( int nlhs, mxArray *
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
  if (!strcmp(machineName, "Walking_ATRIAS")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 43:
      {
        extern mxArray *sf_c43_Walking_ATRIAS_get_testpoint_info(void);
        plhs[0] = sf_c43_Walking_ATRIAS_get_testpoint_info();
        break;
      }

     case 44:
      {
        extern mxArray *sf_c44_Walking_ATRIAS_get_testpoint_info(void);
        plhs[0] = sf_c44_Walking_ATRIAS_get_testpoint_info();
        break;
      }

     case 45:
      {
        extern mxArray *sf_c45_Walking_ATRIAS_get_testpoint_info(void);
        plhs[0] = sf_c45_Walking_ATRIAS_get_testpoint_info();
        break;
      }

     case 46:
      {
        extern mxArray *sf_c46_Walking_ATRIAS_get_testpoint_info(void);
        plhs[0] = sf_c46_Walking_ATRIAS_get_testpoint_info();
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

unsigned int sf_Walking_ATRIAS_process_check_sum_call( int nlhs, mxArray * plhs[],
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
  if (nrhs>1 && mxIsChar(prhs[1])) {
    mxGetString(prhs[1], commandName,sizeof(commandName)/sizeof(char));
    commandName[(sizeof(commandName)/sizeof(char)-1)] = '\0';
    if (!strcmp(commandName,"machine")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(29799773U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3038186706U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2036428005U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2374711784U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1036053097U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1658155419U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3015549184U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(655400861U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c1_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c2_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c4_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 31:
        {
          extern void sf_c31_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c31_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 35:
        {
          extern void sf_c35_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c35_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c36_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c37_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 38:
        {
          extern void sf_c38_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c38_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 39:
        {
          extern void sf_c39_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c39_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 43:
        {
          extern void sf_c43_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c43_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 44:
        {
          extern void sf_c44_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c44_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 45:
        {
          extern void sf_c45_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c45_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 46:
        {
          extern void sf_c46_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c46_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 48:
        {
          extern void sf_c48_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c48_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 49:
        {
          extern void sf_c49_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c49_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 50:
        {
          extern void sf_c50_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c50_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 59:
        {
          extern void sf_c59_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c59_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       case 60:
        {
          extern void sf_c60_Walking_ATRIAS_get_check_sum(mxArray *plhs[]);
          sf_c60_Walking_ATRIAS_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(108609133U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(692001687U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1642343410U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(894934366U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1323709548U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(570284033U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2801702953U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2159515044U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Walking_ATRIAS_autoinheritance_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(aiChksum, "lZuG7pREAFJ0Yx87uzQANB") == 0) {
          extern mxArray *sf_c1_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c1_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "V699iiUYGcKUYsuOEAQYIE") == 0) {
          extern mxArray *sf_c2_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c2_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "shX5x60ikOc3cpvt9KD7RH") == 0) {
          extern mxArray *sf_c4_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c4_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 31:
      {
        if (strcmp(aiChksum, "ZdLCzn8wGHYiH1uX6IlPRF") == 0) {
          extern mxArray *sf_c31_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c31_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 35:
      {
        if (strcmp(aiChksum, "Nu4OGymYFyFuqoEGD5ET3B") == 0) {
          extern mxArray *sf_c35_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c35_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 36:
      {
        if (strcmp(aiChksum, "vgH1OJuVPdEocvJupYgJ6B") == 0) {
          extern mxArray *sf_c36_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c36_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 37:
      {
        if (strcmp(aiChksum, "kRjh6w16qR2ajJq3FHwusF") == 0) {
          extern mxArray *sf_c37_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c37_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 38:
      {
        if (strcmp(aiChksum, "W7wwGVdr6vaSCAWUQ67eLD") == 0) {
          extern mxArray *sf_c38_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c38_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 39:
      {
        if (strcmp(aiChksum, "xmhS1ASqFy18QLEWKqnyWD") == 0) {
          extern mxArray *sf_c39_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c39_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 43:
      {
        if (strcmp(aiChksum, "uiorEU5nAdBqLtvTuxvn8B") == 0) {
          extern mxArray *sf_c43_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c43_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 44:
      {
        if (strcmp(aiChksum, "uiorEU5nAdBqLtvTuxvn8B") == 0) {
          extern mxArray *sf_c44_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c44_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 45:
      {
        if (strcmp(aiChksum, "uiorEU5nAdBqLtvTuxvn8B") == 0) {
          extern mxArray *sf_c45_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c45_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 46:
      {
        if (strcmp(aiChksum, "uiorEU5nAdBqLtvTuxvn8B") == 0) {
          extern mxArray *sf_c46_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c46_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 48:
      {
        if (strcmp(aiChksum, "JkCKksNvhwLKw3ZRa33DuE") == 0) {
          extern mxArray *sf_c48_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c48_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 49:
      {
        if (strcmp(aiChksum, "gamjViGitfhU5dptTnMx1B") == 0) {
          extern mxArray *sf_c49_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c49_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 50:
      {
        if (strcmp(aiChksum, "ZRDEY1y09s8YDEVqmnEAKE") == 0) {
          extern mxArray *sf_c50_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c50_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 59:
      {
        if (strcmp(aiChksum, "hSRA6mI8M2hg2rpL5QdxuD") == 0) {
          extern mxArray *sf_c59_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c59_Walking_ATRIAS_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 60:
      {
        if (strcmp(aiChksum, "tzKTAgW4FxXcIy2ZoPNODG") == 0) {
          extern mxArray *sf_c60_Walking_ATRIAS_get_autoinheritance_info(void);
          plhs[0] = sf_c60_Walking_ATRIAS_get_autoinheritance_info();
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

unsigned int sf_Walking_ATRIAS_get_eml_resolved_functions_info( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        extern const mxArray
          *sf_c1_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 31:
      {
        extern const mxArray
          *sf_c31_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c31_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 35:
      {
        extern const mxArray
          *sf_c35_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c35_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray
          *sf_c36_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray
          *sf_c37_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 38:
      {
        extern const mxArray
          *sf_c38_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c38_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 39:
      {
        extern const mxArray
          *sf_c39_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c39_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 43:
      {
        extern const mxArray
          *sf_c43_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c43_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 44:
      {
        extern const mxArray
          *sf_c44_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c44_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 45:
      {
        extern const mxArray
          *sf_c45_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c45_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 46:
      {
        extern const mxArray
          *sf_c46_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c46_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 48:
      {
        extern const mxArray
          *sf_c48_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c48_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 49:
      {
        extern const mxArray
          *sf_c49_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c49_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 50:
      {
        extern const mxArray
          *sf_c50_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c50_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 59:
      {
        extern const mxArray
          *sf_c59_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c59_Walking_ATRIAS_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 60:
      {
        extern const mxArray
          *sf_c60_Walking_ATRIAS_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c60_Walking_ATRIAS_get_eml_resolved_functions_info();
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

unsigned int sf_Walking_ATRIAS_third_party_uses_info( int nlhs, mxArray * plhs[],
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
     case 1:
      {
        if (strcmp(tpChksum, "VON2w88ZVzM41DnxV76MSF") == 0) {
          extern mxArray *sf_c1_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c1_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c2_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c2_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "6krPjmcnl1hOkVJuTqZykF") == 0) {
          extern mxArray *sf_c4_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c4_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "vnzLWXguRHZfcDe80NRhwF") == 0) {
          extern mxArray *sf_c31_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c31_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "qB0qk8dCX4yOBjrH83k3ZG") == 0) {
          extern mxArray *sf_c35_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c35_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "fRYnfhRY9uzxFezFZl0zND") == 0) {
          extern mxArray *sf_c36_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c36_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "ctmA7vBYMeRwVpCT8K4e7C") == 0) {
          extern mxArray *sf_c37_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c37_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "6beAmsSsvLwRDN88zUKPnB") == 0) {
          extern mxArray *sf_c38_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c38_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "71WIr8ml2bwzQstRISnWiE") == 0) {
          extern mxArray *sf_c39_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c39_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "nUHZbW8pIrLJQwItNlumF") == 0) {
          extern mxArray *sf_c43_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c43_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "J3xb2L46CnKUFYNqcbsjeC") == 0) {
          extern mxArray *sf_c44_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c44_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 45:
      {
        if (strcmp(tpChksum, "UNiliVhUDkBQ82vaoyWQmG") == 0) {
          extern mxArray *sf_c45_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c45_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 46:
      {
        if (strcmp(tpChksum, "J3xb2L46CnKUFYNqcbsjeC") == 0) {
          extern mxArray *sf_c46_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c46_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 48:
      {
        if (strcmp(tpChksum, "SgCli4ihm2yHxkUrzfUrP") == 0) {
          extern mxArray *sf_c48_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c48_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 49:
      {
        if (strcmp(tpChksum, "QSTMJemHZNYcPsVACP6BGG") == 0) {
          extern mxArray *sf_c49_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c49_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 50:
      {
        if (strcmp(tpChksum, "V8DcCJKGSDtSAUYceOllI") == 0) {
          extern mxArray *sf_c50_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c50_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 59:
      {
        if (strcmp(tpChksum, "2qz1POYjbxzHMbF40o6G3") == 0) {
          extern mxArray *sf_c59_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c59_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     case 60:
      {
        if (strcmp(tpChksum, "3s1XSvO3KC37wfj7igJu8D") == 0) {
          extern mxArray *sf_c60_Walking_ATRIAS_third_party_uses_info(void);
          plhs[0] = sf_c60_Walking_ATRIAS_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Walking_ATRIAS_jit_fallback_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(tpChksum, "VON2w88ZVzM41DnxV76MSF") == 0) {
          extern mxArray *sf_c1_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c1_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c2_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c2_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "6krPjmcnl1hOkVJuTqZykF") == 0) {
          extern mxArray *sf_c4_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c4_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "vnzLWXguRHZfcDe80NRhwF") == 0) {
          extern mxArray *sf_c31_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c31_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "qB0qk8dCX4yOBjrH83k3ZG") == 0) {
          extern mxArray *sf_c35_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c35_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "fRYnfhRY9uzxFezFZl0zND") == 0) {
          extern mxArray *sf_c36_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c36_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "ctmA7vBYMeRwVpCT8K4e7C") == 0) {
          extern mxArray *sf_c37_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c37_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "6beAmsSsvLwRDN88zUKPnB") == 0) {
          extern mxArray *sf_c38_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c38_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "71WIr8ml2bwzQstRISnWiE") == 0) {
          extern mxArray *sf_c39_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c39_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "nUHZbW8pIrLJQwItNlumF") == 0) {
          extern mxArray *sf_c43_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c43_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "J3xb2L46CnKUFYNqcbsjeC") == 0) {
          extern mxArray *sf_c44_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c44_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 45:
      {
        if (strcmp(tpChksum, "UNiliVhUDkBQ82vaoyWQmG") == 0) {
          extern mxArray *sf_c45_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c45_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 46:
      {
        if (strcmp(tpChksum, "J3xb2L46CnKUFYNqcbsjeC") == 0) {
          extern mxArray *sf_c46_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c46_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 48:
      {
        if (strcmp(tpChksum, "SgCli4ihm2yHxkUrzfUrP") == 0) {
          extern mxArray *sf_c48_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c48_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 49:
      {
        if (strcmp(tpChksum, "QSTMJemHZNYcPsVACP6BGG") == 0) {
          extern mxArray *sf_c49_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c49_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 50:
      {
        if (strcmp(tpChksum, "V8DcCJKGSDtSAUYceOllI") == 0) {
          extern mxArray *sf_c50_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c50_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 59:
      {
        if (strcmp(tpChksum, "2qz1POYjbxzHMbF40o6G3") == 0) {
          extern mxArray *sf_c59_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c59_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     case 60:
      {
        if (strcmp(tpChksum, "3s1XSvO3KC37wfj7igJu8D") == 0) {
          extern mxArray *sf_c60_Walking_ATRIAS_jit_fallback_info(void);
          plhs[0] = sf_c60_Walking_ATRIAS_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Walking_ATRIAS_updateBuildInfo_args_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
     case 1:
      {
        if (strcmp(tpChksum, "VON2w88ZVzM41DnxV76MSF") == 0) {
          extern mxArray *sf_c1_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c1_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c2_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "6krPjmcnl1hOkVJuTqZykF") == 0) {
          extern mxArray *sf_c4_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 31:
      {
        if (strcmp(tpChksum, "vnzLWXguRHZfcDe80NRhwF") == 0) {
          extern mxArray *sf_c31_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c31_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "qB0qk8dCX4yOBjrH83k3ZG") == 0) {
          extern mxArray *sf_c35_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c35_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "fRYnfhRY9uzxFezFZl0zND") == 0) {
          extern mxArray *sf_c36_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c36_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "ctmA7vBYMeRwVpCT8K4e7C") == 0) {
          extern mxArray *sf_c37_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c37_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "6beAmsSsvLwRDN88zUKPnB") == 0) {
          extern mxArray *sf_c38_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c38_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "71WIr8ml2bwzQstRISnWiE") == 0) {
          extern mxArray *sf_c39_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c39_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "nUHZbW8pIrLJQwItNlumF") == 0) {
          extern mxArray *sf_c43_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c43_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "J3xb2L46CnKUFYNqcbsjeC") == 0) {
          extern mxArray *sf_c44_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c44_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 45:
      {
        if (strcmp(tpChksum, "UNiliVhUDkBQ82vaoyWQmG") == 0) {
          extern mxArray *sf_c45_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c45_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 46:
      {
        if (strcmp(tpChksum, "J3xb2L46CnKUFYNqcbsjeC") == 0) {
          extern mxArray *sf_c46_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c46_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 48:
      {
        if (strcmp(tpChksum, "SgCli4ihm2yHxkUrzfUrP") == 0) {
          extern mxArray *sf_c48_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c48_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 49:
      {
        if (strcmp(tpChksum, "QSTMJemHZNYcPsVACP6BGG") == 0) {
          extern mxArray *sf_c49_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c49_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 50:
      {
        if (strcmp(tpChksum, "V8DcCJKGSDtSAUYceOllI") == 0) {
          extern mxArray *sf_c50_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c50_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 59:
      {
        if (strcmp(tpChksum, "2qz1POYjbxzHMbF40o6G3") == 0) {
          extern mxArray *sf_c59_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c59_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     case 60:
      {
        if (strcmp(tpChksum, "3s1XSvO3KC37wfj7igJu8D") == 0) {
          extern mxArray *sf_c60_Walking_ATRIAS_updateBuildInfo_args_info(void);
          plhs[0] = sf_c60_Walking_ATRIAS_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_Walking_ATRIAS_get_post_codegen_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "VON2w88ZVzM41DnxV76MSF") == 0) {
        extern mxArray *sf_c1_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c1_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
        extern mxArray *sf_c2_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c2_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "6krPjmcnl1hOkVJuTqZykF") == 0) {
        extern mxArray *sf_c4_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c4_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 31:
    {
      if (strcmp(tpChksum, "vnzLWXguRHZfcDe80NRhwF") == 0) {
        extern mxArray *sf_c31_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c31_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 35:
    {
      if (strcmp(tpChksum, "qB0qk8dCX4yOBjrH83k3ZG") == 0) {
        extern mxArray *sf_c35_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c35_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 36:
    {
      if (strcmp(tpChksum, "fRYnfhRY9uzxFezFZl0zND") == 0) {
        extern mxArray *sf_c36_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c36_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 37:
    {
      if (strcmp(tpChksum, "ctmA7vBYMeRwVpCT8K4e7C") == 0) {
        extern mxArray *sf_c37_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c37_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 38:
    {
      if (strcmp(tpChksum, "6beAmsSsvLwRDN88zUKPnB") == 0) {
        extern mxArray *sf_c38_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c38_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 39:
    {
      if (strcmp(tpChksum, "71WIr8ml2bwzQstRISnWiE") == 0) {
        extern mxArray *sf_c39_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c39_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 43:
    {
      if (strcmp(tpChksum, "nUHZbW8pIrLJQwItNlumF") == 0) {
        extern mxArray *sf_c43_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c43_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 44:
    {
      if (strcmp(tpChksum, "J3xb2L46CnKUFYNqcbsjeC") == 0) {
        extern mxArray *sf_c44_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c44_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 45:
    {
      if (strcmp(tpChksum, "UNiliVhUDkBQ82vaoyWQmG") == 0) {
        extern mxArray *sf_c45_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c45_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 46:
    {
      if (strcmp(tpChksum, "J3xb2L46CnKUFYNqcbsjeC") == 0) {
        extern mxArray *sf_c46_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c46_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 48:
    {
      if (strcmp(tpChksum, "SgCli4ihm2yHxkUrzfUrP") == 0) {
        extern mxArray *sf_c48_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c48_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 49:
    {
      if (strcmp(tpChksum, "QSTMJemHZNYcPsVACP6BGG") == 0) {
        extern mxArray *sf_c49_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c49_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 50:
    {
      if (strcmp(tpChksum, "V8DcCJKGSDtSAUYceOllI") == 0) {
        extern mxArray *sf_c50_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c50_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 59:
    {
      if (strcmp(tpChksum, "2qz1POYjbxzHMbF40o6G3") == 0) {
        extern mxArray *sf_c59_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c59_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   case 60:
    {
      if (strcmp(tpChksum, "3s1XSvO3KC37wfj7igJu8D") == 0) {
        extern mxArray *sf_c60_Walking_ATRIAS_get_post_codegen_info(void);
        plhs[0] = sf_c60_Walking_ATRIAS_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void Walking_ATRIAS_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _Walking_ATRIASMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Walking_ATRIAS","sfun",0,18,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Walking_ATRIASMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Walking_ATRIASMachineNumber_,0);
}

void Walking_ATRIAS_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Walking_ATRIAS_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Walking_ATRIAS",
      "Walking_ATRIAS");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Walking_ATRIAS_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
