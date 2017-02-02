/* Include files */

#include "Walking01_DDA3D_sfun.h"
#include "Walking01_DDA3D_sfun_debug_macros.h"
#include "c31_Walking01_DDA3D.h"
#include "c33_Walking01_DDA3D.h"
#include "c34_Walking01_DDA3D.h"
#include "c35_Walking01_DDA3D.h"
#include "c36_Walking01_DDA3D.h"
#include "c37_Walking01_DDA3D.h"
#include "c38_Walking01_DDA3D.h"
#include "c39_Walking01_DDA3D.h"
#include "c40_Walking01_DDA3D.h"
#include "c41_Walking01_DDA3D.h"
#include "c42_Walking01_DDA3D.h"
#include "c43_Walking01_DDA3D.h"
#include "c44_Walking01_DDA3D.h"
#include "c45_Walking01_DDA3D.h"
#include "c46_Walking01_DDA3D.h"
#include "c47_Walking01_DDA3D.h"
#include "c48_Walking01_DDA3D.h"
#include "c49_Walking01_DDA3D.h"
#include "c50_Walking01_DDA3D.h"
#include "c56_Walking01_DDA3D.h"
#include "c57_Walking01_DDA3D.h"
#include "c58_Walking01_DDA3D.h"
#include "c59_Walking01_DDA3D.h"
#include "c60_Walking01_DDA3D.h"
#include "c92_Walking01_DDA3D.h"
#include "c93_Walking01_DDA3D.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Walking01_DDA3DMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Walking01_DDA3D_initializer(void)
{
}

void Walking01_DDA3D_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Walking01_DDA3D_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==31) {
    c31_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==33) {
    c33_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==34) {
    c34_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==35) {
    c35_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==36) {
    c36_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==37) {
    c37_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==38) {
    c38_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==39) {
    c39_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==40) {
    c40_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==41) {
    c41_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==42) {
    c42_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==43) {
    c43_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==44) {
    c44_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==45) {
    c45_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==46) {
    c46_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==47) {
    c47_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==48) {
    c48_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==49) {
    c49_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==50) {
    c50_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==56) {
    c56_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==57) {
    c57_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==58) {
    c58_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==59) {
    c59_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==60) {
    c60_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==92) {
    c92_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==93) {
    c93_Walking01_DDA3D_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_Walking01_DDA3D_uses_exported_functions(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_Walking01_DDA3D_process_testpoint_info_call( int nlhs, mxArray *
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
  if (!strcmp(machineName, "Walking01_DDA3D")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 34:
      {
        extern mxArray *sf_c34_Walking01_DDA3D_get_testpoint_info(void);
        plhs[0] = sf_c34_Walking01_DDA3D_get_testpoint_info();
        break;
      }

     case 43:
      {
        extern mxArray *sf_c43_Walking01_DDA3D_get_testpoint_info(void);
        plhs[0] = sf_c43_Walking01_DDA3D_get_testpoint_info();
        break;
      }

     case 44:
      {
        extern mxArray *sf_c44_Walking01_DDA3D_get_testpoint_info(void);
        plhs[0] = sf_c44_Walking01_DDA3D_get_testpoint_info();
        break;
      }

     case 45:
      {
        extern mxArray *sf_c45_Walking01_DDA3D_get_testpoint_info(void);
        plhs[0] = sf_c45_Walking01_DDA3D_get_testpoint_info();
        break;
      }

     case 46:
      {
        extern mxArray *sf_c46_Walking01_DDA3D_get_testpoint_info(void);
        plhs[0] = sf_c46_Walking01_DDA3D_get_testpoint_info();
        break;
      }

     case 47:
      {
        extern mxArray *sf_c47_Walking01_DDA3D_get_testpoint_info(void);
        plhs[0] = sf_c47_Walking01_DDA3D_get_testpoint_info();
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

unsigned int sf_Walking01_DDA3D_process_check_sum_call( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2724115173U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3159950616U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1822041541U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2922857587U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(408078598U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3891770368U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3426731299U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(946044274U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 31:
        {
          extern void sf_c31_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c31_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 33:
        {
          extern void sf_c33_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c33_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 34:
        {
          extern void sf_c34_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c34_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 35:
        {
          extern void sf_c35_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c35_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 36:
        {
          extern void sf_c36_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c36_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 37:
        {
          extern void sf_c37_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c37_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 38:
        {
          extern void sf_c38_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c38_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 39:
        {
          extern void sf_c39_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c39_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 40:
        {
          extern void sf_c40_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c40_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 41:
        {
          extern void sf_c41_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c41_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 42:
        {
          extern void sf_c42_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c42_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 43:
        {
          extern void sf_c43_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c43_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 44:
        {
          extern void sf_c44_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c44_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 45:
        {
          extern void sf_c45_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c45_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 46:
        {
          extern void sf_c46_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c46_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 47:
        {
          extern void sf_c47_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c47_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 48:
        {
          extern void sf_c48_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c48_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 49:
        {
          extern void sf_c49_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c49_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 50:
        {
          extern void sf_c50_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c50_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 56:
        {
          extern void sf_c56_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c56_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 57:
        {
          extern void sf_c57_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c57_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 58:
        {
          extern void sf_c58_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c58_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 59:
        {
          extern void sf_c59_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c59_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 60:
        {
          extern void sf_c60_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c60_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 92:
        {
          extern void sf_c92_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c92_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       case 93:
        {
          extern void sf_c93_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
          sf_c93_Walking01_DDA3D_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(662671135U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2943540802U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1577259173U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(743832277U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(3826974556U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1544455290U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2636105852U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1058093508U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Walking01_DDA3D_autoinheritance_info( int nlhs, mxArray * plhs[],
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
     case 31:
      {
        if (strcmp(aiChksum, "ZdLCzn8wGHYiH1uX6IlPRF") == 0) {
          extern mxArray *sf_c31_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c31_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 33:
      {
        if (strcmp(aiChksum, "V699iiUYGcKUYsuOEAQYIE") == 0) {
          extern mxArray *sf_c33_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c33_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 34:
      {
        if (strcmp(aiChksum, "rmLs1hEgNboBi0ypdo8omE") == 0) {
          extern mxArray *sf_c34_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c34_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 35:
      {
        if (strcmp(aiChksum, "Nu4OGymYFyFuqoEGD5ET3B") == 0) {
          extern mxArray *sf_c35_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c35_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 36:
      {
        if (strcmp(aiChksum, "vgH1OJuVPdEocvJupYgJ6B") == 0) {
          extern mxArray *sf_c36_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c36_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 37:
      {
        if (strcmp(aiChksum, "kRjh6w16qR2ajJq3FHwusF") == 0) {
          extern mxArray *sf_c37_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c37_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 38:
      {
        if (strcmp(aiChksum, "W7wwGVdr6vaSCAWUQ67eLD") == 0) {
          extern mxArray *sf_c38_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c38_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 39:
      {
        if (strcmp(aiChksum, "xmhS1ASqFy18QLEWKqnyWD") == 0) {
          extern mxArray *sf_c39_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c39_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 40:
      {
        if (strcmp(aiChksum, "cvbCWAEsbRZc6yd2VRq6SG") == 0) {
          extern mxArray *sf_c40_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c40_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 41:
      {
        if (strcmp(aiChksum, "mlClvD5IRO2Pz7XcbxGyEF") == 0) {
          extern mxArray *sf_c41_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c41_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 42:
      {
        if (strcmp(aiChksum, "mlClvD5IRO2Pz7XcbxGyEF") == 0) {
          extern mxArray *sf_c42_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c42_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 43:
      {
        if (strcmp(aiChksum, "TxaujBQiZR71hjzOPc7piE") == 0) {
          extern mxArray *sf_c43_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c43_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 44:
      {
        if (strcmp(aiChksum, "TxaujBQiZR71hjzOPc7piE") == 0) {
          extern mxArray *sf_c44_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c44_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 45:
      {
        if (strcmp(aiChksum, "TxaujBQiZR71hjzOPc7piE") == 0) {
          extern mxArray *sf_c45_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c45_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 46:
      {
        if (strcmp(aiChksum, "TxaujBQiZR71hjzOPc7piE") == 0) {
          extern mxArray *sf_c46_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c46_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 47:
      {
        if (strcmp(aiChksum, "hHNt928gQKItxqEcoHjKRF") == 0) {
          extern mxArray *sf_c47_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c47_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 48:
      {
        if (strcmp(aiChksum, "JkCKksNvhwLKw3ZRa33DuE") == 0) {
          extern mxArray *sf_c48_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c48_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 49:
      {
        if (strcmp(aiChksum, "a4BLA4EmTVlKbO9yUahgOH") == 0) {
          extern mxArray *sf_c49_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c49_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 50:
      {
        if (strcmp(aiChksum, "ZRDEY1y09s8YDEVqmnEAKE") == 0) {
          extern mxArray *sf_c50_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c50_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 56:
      {
        if (strcmp(aiChksum, "V699iiUYGcKUYsuOEAQYIE") == 0) {
          extern mxArray *sf_c56_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c56_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 57:
      {
        if (strcmp(aiChksum, "J5Wk73nkP900bHm3NMjsmH") == 0) {
          extern mxArray *sf_c57_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c57_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 58:
      {
        if (strcmp(aiChksum, "PjNphwNBnwuwvoE8moWXf") == 0) {
          extern mxArray *sf_c58_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c58_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 59:
      {
        if (strcmp(aiChksum, "hSRA6mI8M2hg2rpL5QdxuD") == 0) {
          extern mxArray *sf_c59_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c59_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 60:
      {
        if (strcmp(aiChksum, "J3rFn3HzlI8snWVX5oGsK") == 0) {
          extern mxArray *sf_c60_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c60_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 92:
      {
        if (strcmp(aiChksum, "pvG7TXaXBdRFGeuDtQ4GbD") == 0) {
          extern mxArray *sf_c92_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c92_Walking01_DDA3D_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 93:
      {
        if (strcmp(aiChksum, "1mU39Zfe7Wsa8QVzr7IfGC") == 0) {
          extern mxArray *sf_c93_Walking01_DDA3D_get_autoinheritance_info(void);
          plhs[0] = sf_c93_Walking01_DDA3D_get_autoinheritance_info();
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

unsigned int sf_Walking01_DDA3D_get_eml_resolved_functions_info( int nlhs,
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
     case 31:
      {
        extern const mxArray
          *sf_c31_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c31_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 33:
      {
        extern const mxArray
          *sf_c33_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c33_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 34:
      {
        extern const mxArray
          *sf_c34_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c34_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 35:
      {
        extern const mxArray
          *sf_c35_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c35_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 36:
      {
        extern const mxArray
          *sf_c36_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c36_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 37:
      {
        extern const mxArray
          *sf_c37_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c37_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 38:
      {
        extern const mxArray
          *sf_c38_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c38_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 39:
      {
        extern const mxArray
          *sf_c39_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c39_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 40:
      {
        extern const mxArray
          *sf_c40_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c40_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 41:
      {
        extern const mxArray
          *sf_c41_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c41_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 42:
      {
        extern const mxArray
          *sf_c42_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c42_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 43:
      {
        extern const mxArray
          *sf_c43_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c43_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 44:
      {
        extern const mxArray
          *sf_c44_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c44_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 45:
      {
        extern const mxArray
          *sf_c45_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c45_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 46:
      {
        extern const mxArray
          *sf_c46_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c46_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 47:
      {
        extern const mxArray
          *sf_c47_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c47_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 48:
      {
        extern const mxArray
          *sf_c48_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c48_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 49:
      {
        extern const mxArray
          *sf_c49_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c49_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 50:
      {
        extern const mxArray
          *sf_c50_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c50_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 56:
      {
        extern const mxArray
          *sf_c56_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c56_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 57:
      {
        extern const mxArray
          *sf_c57_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c57_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 58:
      {
        extern const mxArray
          *sf_c58_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c58_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 59:
      {
        extern const mxArray
          *sf_c59_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c59_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 60:
      {
        extern const mxArray
          *sf_c60_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c60_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 92:
      {
        extern const mxArray
          *sf_c92_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c92_Walking01_DDA3D_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 93:
      {
        extern const mxArray
          *sf_c93_Walking01_DDA3D_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c93_Walking01_DDA3D_get_eml_resolved_functions_info();
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

unsigned int sf_Walking01_DDA3D_third_party_uses_info( int nlhs, mxArray * plhs[],
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
     case 31:
      {
        if (strcmp(tpChksum, "vnzLWXguRHZfcDe80NRhwF") == 0) {
          extern mxArray *sf_c31_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c31_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 33:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c33_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c33_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 34:
      {
        if (strcmp(tpChksum, "VHMA4mlzML9q61UItY3YMB") == 0) {
          extern mxArray *sf_c34_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c34_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "qB0qk8dCX4yOBjrH83k3ZG") == 0) {
          extern mxArray *sf_c35_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c35_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "fRYnfhRY9uzxFezFZl0zND") == 0) {
          extern mxArray *sf_c36_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c36_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "ctmA7vBYMeRwVpCT8K4e7C") == 0) {
          extern mxArray *sf_c37_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c37_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "6beAmsSsvLwRDN88zUKPnB") == 0) {
          extern mxArray *sf_c38_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c38_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "71WIr8ml2bwzQstRISnWiE") == 0) {
          extern mxArray *sf_c39_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c39_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "jKgAKaX2WSqj8ZiWsQ1uVD") == 0) {
          extern mxArray *sf_c40_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c40_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
          extern mxArray *sf_c41_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c41_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 42:
      {
        if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
          extern mxArray *sf_c42_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c42_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "1i1enK4EbLDBOMyEiLozV") == 0) {
          extern mxArray *sf_c43_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c43_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "p9oqaJ0zB0rcP7ESVZ6xdD") == 0) {
          extern mxArray *sf_c44_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c44_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 45:
      {
        if (strcmp(tpChksum, "VA7C3SkkKJYTGOIpcl5SmH") == 0) {
          extern mxArray *sf_c45_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c45_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 46:
      {
        if (strcmp(tpChksum, "p9oqaJ0zB0rcP7ESVZ6xdD") == 0) {
          extern mxArray *sf_c46_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c46_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 47:
      {
        if (strcmp(tpChksum, "SjtkZZxyw5jP8NWyl6PAiB") == 0) {
          extern mxArray *sf_c47_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c47_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 48:
      {
        if (strcmp(tpChksum, "SgCli4ihm2yHxkUrzfUrP") == 0) {
          extern mxArray *sf_c48_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c48_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 49:
      {
        if (strcmp(tpChksum, "mfov7pLG2vXuk5uP140IbE") == 0) {
          extern mxArray *sf_c49_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c49_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 50:
      {
        if (strcmp(tpChksum, "V8DcCJKGSDtSAUYceOllI") == 0) {
          extern mxArray *sf_c50_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c50_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 56:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c56_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c56_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 57:
      {
        if (strcmp(tpChksum, "lpJvuKaf6wET1A4puNGxCG") == 0) {
          extern mxArray *sf_c57_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c57_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 58:
      {
        if (strcmp(tpChksum, "5ycb0rqNkFZszaDdsfMMHG") == 0) {
          extern mxArray *sf_c58_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c58_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 59:
      {
        if (strcmp(tpChksum, "2qz1POYjbxzHMbF40o6G3") == 0) {
          extern mxArray *sf_c59_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c59_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 60:
      {
        if (strcmp(tpChksum, "YHuXDaGGbsHhHnCKpqjYGE") == 0) {
          extern mxArray *sf_c60_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c60_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 92:
      {
        if (strcmp(tpChksum, "ulneSYGweuiNpoRUyNLGP") == 0) {
          extern mxArray *sf_c92_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c92_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     case 93:
      {
        if (strcmp(tpChksum, "D6wsj60IMLHf4DjqsHgJW") == 0) {
          extern mxArray *sf_c93_Walking01_DDA3D_third_party_uses_info(void);
          plhs[0] = sf_c93_Walking01_DDA3D_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Walking01_DDA3D_jit_fallback_info( int nlhs, mxArray * plhs[],
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
     case 31:
      {
        if (strcmp(tpChksum, "vnzLWXguRHZfcDe80NRhwF") == 0) {
          extern mxArray *sf_c31_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c31_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 33:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c33_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c33_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 34:
      {
        if (strcmp(tpChksum, "VHMA4mlzML9q61UItY3YMB") == 0) {
          extern mxArray *sf_c34_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c34_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "qB0qk8dCX4yOBjrH83k3ZG") == 0) {
          extern mxArray *sf_c35_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c35_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "fRYnfhRY9uzxFezFZl0zND") == 0) {
          extern mxArray *sf_c36_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c36_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "ctmA7vBYMeRwVpCT8K4e7C") == 0) {
          extern mxArray *sf_c37_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c37_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "6beAmsSsvLwRDN88zUKPnB") == 0) {
          extern mxArray *sf_c38_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c38_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "71WIr8ml2bwzQstRISnWiE") == 0) {
          extern mxArray *sf_c39_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c39_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "jKgAKaX2WSqj8ZiWsQ1uVD") == 0) {
          extern mxArray *sf_c40_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c40_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
          extern mxArray *sf_c41_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c41_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 42:
      {
        if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
          extern mxArray *sf_c42_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c42_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "1i1enK4EbLDBOMyEiLozV") == 0) {
          extern mxArray *sf_c43_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c43_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "p9oqaJ0zB0rcP7ESVZ6xdD") == 0) {
          extern mxArray *sf_c44_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c44_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 45:
      {
        if (strcmp(tpChksum, "VA7C3SkkKJYTGOIpcl5SmH") == 0) {
          extern mxArray *sf_c45_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c45_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 46:
      {
        if (strcmp(tpChksum, "p9oqaJ0zB0rcP7ESVZ6xdD") == 0) {
          extern mxArray *sf_c46_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c46_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 47:
      {
        if (strcmp(tpChksum, "SjtkZZxyw5jP8NWyl6PAiB") == 0) {
          extern mxArray *sf_c47_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c47_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 48:
      {
        if (strcmp(tpChksum, "SgCli4ihm2yHxkUrzfUrP") == 0) {
          extern mxArray *sf_c48_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c48_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 49:
      {
        if (strcmp(tpChksum, "mfov7pLG2vXuk5uP140IbE") == 0) {
          extern mxArray *sf_c49_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c49_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 50:
      {
        if (strcmp(tpChksum, "V8DcCJKGSDtSAUYceOllI") == 0) {
          extern mxArray *sf_c50_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c50_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 56:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c56_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c56_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 57:
      {
        if (strcmp(tpChksum, "lpJvuKaf6wET1A4puNGxCG") == 0) {
          extern mxArray *sf_c57_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c57_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 58:
      {
        if (strcmp(tpChksum, "5ycb0rqNkFZszaDdsfMMHG") == 0) {
          extern mxArray *sf_c58_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c58_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 59:
      {
        if (strcmp(tpChksum, "2qz1POYjbxzHMbF40o6G3") == 0) {
          extern mxArray *sf_c59_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c59_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 60:
      {
        if (strcmp(tpChksum, "YHuXDaGGbsHhHnCKpqjYGE") == 0) {
          extern mxArray *sf_c60_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c60_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 92:
      {
        if (strcmp(tpChksum, "ulneSYGweuiNpoRUyNLGP") == 0) {
          extern mxArray *sf_c92_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c92_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     case 93:
      {
        if (strcmp(tpChksum, "D6wsj60IMLHf4DjqsHgJW") == 0) {
          extern mxArray *sf_c93_Walking01_DDA3D_jit_fallback_info(void);
          plhs[0] = sf_c93_Walking01_DDA3D_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Walking01_DDA3D_updateBuildInfo_args_info( int nlhs, mxArray *
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
     case 31:
      {
        if (strcmp(tpChksum, "vnzLWXguRHZfcDe80NRhwF") == 0) {
          extern mxArray *sf_c31_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c31_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 33:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c33_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c33_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 34:
      {
        if (strcmp(tpChksum, "VHMA4mlzML9q61UItY3YMB") == 0) {
          extern mxArray *sf_c34_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c34_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 35:
      {
        if (strcmp(tpChksum, "qB0qk8dCX4yOBjrH83k3ZG") == 0) {
          extern mxArray *sf_c35_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c35_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 36:
      {
        if (strcmp(tpChksum, "fRYnfhRY9uzxFezFZl0zND") == 0) {
          extern mxArray *sf_c36_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c36_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 37:
      {
        if (strcmp(tpChksum, "ctmA7vBYMeRwVpCT8K4e7C") == 0) {
          extern mxArray *sf_c37_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c37_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 38:
      {
        if (strcmp(tpChksum, "6beAmsSsvLwRDN88zUKPnB") == 0) {
          extern mxArray *sf_c38_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c38_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 39:
      {
        if (strcmp(tpChksum, "71WIr8ml2bwzQstRISnWiE") == 0) {
          extern mxArray *sf_c39_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c39_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 40:
      {
        if (strcmp(tpChksum, "jKgAKaX2WSqj8ZiWsQ1uVD") == 0) {
          extern mxArray *sf_c40_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c40_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 41:
      {
        if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
          extern mxArray *sf_c41_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c41_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 42:
      {
        if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
          extern mxArray *sf_c42_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c42_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 43:
      {
        if (strcmp(tpChksum, "1i1enK4EbLDBOMyEiLozV") == 0) {
          extern mxArray *sf_c43_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c43_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 44:
      {
        if (strcmp(tpChksum, "p9oqaJ0zB0rcP7ESVZ6xdD") == 0) {
          extern mxArray *sf_c44_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c44_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 45:
      {
        if (strcmp(tpChksum, "VA7C3SkkKJYTGOIpcl5SmH") == 0) {
          extern mxArray *sf_c45_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c45_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 46:
      {
        if (strcmp(tpChksum, "p9oqaJ0zB0rcP7ESVZ6xdD") == 0) {
          extern mxArray *sf_c46_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c46_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 47:
      {
        if (strcmp(tpChksum, "SjtkZZxyw5jP8NWyl6PAiB") == 0) {
          extern mxArray *sf_c47_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c47_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 48:
      {
        if (strcmp(tpChksum, "SgCli4ihm2yHxkUrzfUrP") == 0) {
          extern mxArray *sf_c48_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c48_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 49:
      {
        if (strcmp(tpChksum, "mfov7pLG2vXuk5uP140IbE") == 0) {
          extern mxArray *sf_c49_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c49_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 50:
      {
        if (strcmp(tpChksum, "V8DcCJKGSDtSAUYceOllI") == 0) {
          extern mxArray *sf_c50_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c50_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 56:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c56_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c56_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 57:
      {
        if (strcmp(tpChksum, "lpJvuKaf6wET1A4puNGxCG") == 0) {
          extern mxArray *sf_c57_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c57_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 58:
      {
        if (strcmp(tpChksum, "5ycb0rqNkFZszaDdsfMMHG") == 0) {
          extern mxArray *sf_c58_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c58_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 59:
      {
        if (strcmp(tpChksum, "2qz1POYjbxzHMbF40o6G3") == 0) {
          extern mxArray *sf_c59_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c59_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 60:
      {
        if (strcmp(tpChksum, "YHuXDaGGbsHhHnCKpqjYGE") == 0) {
          extern mxArray *sf_c60_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c60_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 92:
      {
        if (strcmp(tpChksum, "ulneSYGweuiNpoRUyNLGP") == 0) {
          extern mxArray *sf_c92_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c92_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     case 93:
      {
        if (strcmp(tpChksum, "D6wsj60IMLHf4DjqsHgJW") == 0) {
          extern mxArray *sf_c93_Walking01_DDA3D_updateBuildInfo_args_info(void);
          plhs[0] = sf_c93_Walking01_DDA3D_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_Walking01_DDA3D_get_post_codegen_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 31:
    {
      if (strcmp(tpChksum, "vnzLWXguRHZfcDe80NRhwF") == 0) {
        extern mxArray *sf_c31_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c31_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 33:
    {
      if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
        extern mxArray *sf_c33_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c33_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 34:
    {
      if (strcmp(tpChksum, "VHMA4mlzML9q61UItY3YMB") == 0) {
        extern mxArray *sf_c34_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c34_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 35:
    {
      if (strcmp(tpChksum, "qB0qk8dCX4yOBjrH83k3ZG") == 0) {
        extern mxArray *sf_c35_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c35_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 36:
    {
      if (strcmp(tpChksum, "fRYnfhRY9uzxFezFZl0zND") == 0) {
        extern mxArray *sf_c36_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c36_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 37:
    {
      if (strcmp(tpChksum, "ctmA7vBYMeRwVpCT8K4e7C") == 0) {
        extern mxArray *sf_c37_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c37_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 38:
    {
      if (strcmp(tpChksum, "6beAmsSsvLwRDN88zUKPnB") == 0) {
        extern mxArray *sf_c38_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c38_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 39:
    {
      if (strcmp(tpChksum, "71WIr8ml2bwzQstRISnWiE") == 0) {
        extern mxArray *sf_c39_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c39_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 40:
    {
      if (strcmp(tpChksum, "jKgAKaX2WSqj8ZiWsQ1uVD") == 0) {
        extern mxArray *sf_c40_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c40_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 41:
    {
      if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
        extern mxArray *sf_c41_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c41_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 42:
    {
      if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
        extern mxArray *sf_c42_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c42_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 43:
    {
      if (strcmp(tpChksum, "1i1enK4EbLDBOMyEiLozV") == 0) {
        extern mxArray *sf_c43_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c43_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 44:
    {
      if (strcmp(tpChksum, "p9oqaJ0zB0rcP7ESVZ6xdD") == 0) {
        extern mxArray *sf_c44_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c44_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 45:
    {
      if (strcmp(tpChksum, "VA7C3SkkKJYTGOIpcl5SmH") == 0) {
        extern mxArray *sf_c45_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c45_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 46:
    {
      if (strcmp(tpChksum, "p9oqaJ0zB0rcP7ESVZ6xdD") == 0) {
        extern mxArray *sf_c46_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c46_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 47:
    {
      if (strcmp(tpChksum, "SjtkZZxyw5jP8NWyl6PAiB") == 0) {
        extern mxArray *sf_c47_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c47_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 48:
    {
      if (strcmp(tpChksum, "SgCli4ihm2yHxkUrzfUrP") == 0) {
        extern mxArray *sf_c48_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c48_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 49:
    {
      if (strcmp(tpChksum, "mfov7pLG2vXuk5uP140IbE") == 0) {
        extern mxArray *sf_c49_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c49_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 50:
    {
      if (strcmp(tpChksum, "V8DcCJKGSDtSAUYceOllI") == 0) {
        extern mxArray *sf_c50_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c50_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 56:
    {
      if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
        extern mxArray *sf_c56_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c56_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 57:
    {
      if (strcmp(tpChksum, "lpJvuKaf6wET1A4puNGxCG") == 0) {
        extern mxArray *sf_c57_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c57_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 58:
    {
      if (strcmp(tpChksum, "5ycb0rqNkFZszaDdsfMMHG") == 0) {
        extern mxArray *sf_c58_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c58_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 59:
    {
      if (strcmp(tpChksum, "2qz1POYjbxzHMbF40o6G3") == 0) {
        extern mxArray *sf_c59_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c59_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 60:
    {
      if (strcmp(tpChksum, "YHuXDaGGbsHhHnCKpqjYGE") == 0) {
        extern mxArray *sf_c60_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c60_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 92:
    {
      if (strcmp(tpChksum, "ulneSYGweuiNpoRUyNLGP") == 0) {
        extern mxArray *sf_c92_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c92_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   case 93:
    {
      if (strcmp(tpChksum, "D6wsj60IMLHf4DjqsHgJW") == 0) {
        extern mxArray *sf_c93_Walking01_DDA3D_get_post_codegen_info(void);
        plhs[0] = sf_c93_Walking01_DDA3D_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void Walking01_DDA3D_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _Walking01_DDA3DMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Walking01_DDA3D","sfun",0,26,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Walking01_DDA3DMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Walking01_DDA3DMachineNumber_,0);
}

void Walking01_DDA3D_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Walking01_DDA3D_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("Walking01_DDA3D",
      "Walking01_DDA3D");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Walking01_DDA3D_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
