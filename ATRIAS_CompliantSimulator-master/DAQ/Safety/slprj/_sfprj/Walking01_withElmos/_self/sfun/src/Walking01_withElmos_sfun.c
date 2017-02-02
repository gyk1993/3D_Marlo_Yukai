/* Include files */

#include "Walking01_withElmos_sfun.h"
#include "Walking01_withElmos_sfun_debug_macros.h"
#include "c1_Walking01_withElmos.h"
#include "c2_Walking01_withElmos.h"
#include "c3_Walking01_withElmos.h"
#include "c5_Walking01_withElmos.h"
#include "c6_Walking01_withElmos.h"
#include "c7_Walking01_withElmos.h"
#include "c9_Walking01_withElmos.h"
#include "c10_Walking01_withElmos.h"
#include "c11_Walking01_withElmos.h"
#include "c15_Walking01_withElmos.h"
#include "c16_Walking01_withElmos.h"
#include "c17_Walking01_withElmos.h"
#include "c18_Walking01_withElmos.h"
#include "c19_Walking01_withElmos.h"
#include "c20_Walking01_withElmos.h"
#include "c21_Walking01_withElmos.h"
#include "c22_Walking01_withElmos.h"
#include "c23_Walking01_withElmos.h"
#include "c24_Walking01_withElmos.h"
#include "c25_Walking01_withElmos.h"
#include "c26_Walking01_withElmos.h"
#include "c27_Walking01_withElmos.h"
#include "c32_Walking01_withElmos.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _Walking01_withElmosMachineNumber_;

/* Function Declarations */

/* Function Definitions */
void Walking01_withElmos_initializer(void)
{
}

void Walking01_withElmos_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_Walking01_withElmos_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==1) {
    c1_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==2) {
    c2_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==5) {
    c5_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==6) {
    c6_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==7) {
    c7_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==10) {
    c10_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==15) {
    c15_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==16) {
    c16_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==17) {
    c17_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==18) {
    c18_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==19) {
    c19_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==20) {
    c20_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==21) {
    c21_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==22) {
    c22_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==23) {
    c23_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==24) {
    c24_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==25) {
    c25_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==26) {
    c26_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==27) {
    c27_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==32) {
    c32_Walking01_withElmos_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_Walking01_withElmos_uses_exported_functions(int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_Walking01_withElmos_process_testpoint_info_call( int nlhs,
  mxArray * plhs[], int nrhs, const mxArray * prhs[] )
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
  if (!strcmp(machineName, "Walking01_withElmos")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 3:
      {
        extern mxArray *sf_c3_Walking01_withElmos_get_testpoint_info(void);
        plhs[0] = sf_c3_Walking01_withElmos_get_testpoint_info();
        break;
      }

     case 9:
      {
        extern mxArray *sf_c9_Walking01_withElmos_get_testpoint_info(void);
        plhs[0] = sf_c9_Walking01_withElmos_get_testpoint_info();
        break;
      }

     case 20:
      {
        extern mxArray *sf_c20_Walking01_withElmos_get_testpoint_info(void);
        plhs[0] = sf_c20_Walking01_withElmos_get_testpoint_info();
        break;
      }

     case 22:
      {
        extern mxArray *sf_c22_Walking01_withElmos_get_testpoint_info(void);
        plhs[0] = sf_c22_Walking01_withElmos_get_testpoint_info();
        break;
      }

     case 23:
      {
        extern mxArray *sf_c23_Walking01_withElmos_get_testpoint_info(void);
        plhs[0] = sf_c23_Walking01_withElmos_get_testpoint_info();
        break;
      }

     case 27:
      {
        extern mxArray *sf_c27_Walking01_withElmos_get_testpoint_info(void);
        plhs[0] = sf_c27_Walking01_withElmos_get_testpoint_info();
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

unsigned int sf_Walking01_withElmos_process_check_sum_call( int nlhs, mxArray *
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1857674259U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(342936202U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3323295881U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2540893447U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2678151740U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3006918869U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1161428818U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(257077496U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 1:
        {
          extern void sf_c1_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c1_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 2:
        {
          extern void sf_c2_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c2_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c3_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 5:
        {
          extern void sf_c5_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c5_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 6:
        {
          extern void sf_c6_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c6_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 7:
        {
          extern void sf_c7_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c7_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c9_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 10:
        {
          extern void sf_c10_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c10_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c11_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 15:
        {
          extern void sf_c15_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c15_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 16:
        {
          extern void sf_c16_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c16_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 17:
        {
          extern void sf_c17_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c17_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 18:
        {
          extern void sf_c18_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c18_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 19:
        {
          extern void sf_c19_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c19_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 20:
        {
          extern void sf_c20_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c20_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 21:
        {
          extern void sf_c21_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c21_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 22:
        {
          extern void sf_c22_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c22_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 23:
        {
          extern void sf_c23_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c23_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 24:
        {
          extern void sf_c24_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c24_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 25:
        {
          extern void sf_c25_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c25_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 26:
        {
          extern void sf_c26_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c26_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 27:
        {
          extern void sf_c27_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c27_Walking01_withElmos_get_check_sum(plhs);
          break;
        }

       case 32:
        {
          extern void sf_c32_Walking01_withElmos_get_check_sum(mxArray *plhs[]);
          sf_c32_Walking01_withElmos_get_check_sum(plhs);
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
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1837768268U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(4271479003U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(789976541U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2883870116U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_Walking01_withElmos_autoinheritance_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(aiChksum, "mlClvD5IRO2Pz7XcbxGyEF") == 0) {
          extern mxArray *sf_c1_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c1_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 2:
      {
        if (strcmp(aiChksum, "ZdLCzn8wGHYiH1uX6IlPRF") == 0) {
          extern mxArray *sf_c2_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c2_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "hHNt928gQKItxqEcoHjKRF") == 0) {
          extern mxArray *sf_c3_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c3_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 5:
      {
        if (strcmp(aiChksum, "J5Wk73nkP900bHm3NMjsmH") == 0) {
          extern mxArray *sf_c5_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c5_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 6:
      {
        if (strcmp(aiChksum, "mlClvD5IRO2Pz7XcbxGyEF") == 0) {
          extern mxArray *sf_c6_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c6_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 7:
      {
        if (strcmp(aiChksum, "V699iiUYGcKUYsuOEAQYIE") == 0) {
          extern mxArray *sf_c7_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c7_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "rmLs1hEgNboBi0ypdo8omE") == 0) {
          extern mxArray *sf_c9_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c9_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 10:
      {
        if (strcmp(aiChksum, "Nu4OGymYFyFuqoEGD5ET3B") == 0) {
          extern mxArray *sf_c10_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c10_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "PjNphwNBnwuwvoE8moWXf") == 0) {
          extern mxArray *sf_c11_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c11_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 15:
      {
        if (strcmp(aiChksum, "vgH1OJuVPdEocvJupYgJ6B") == 0) {
          extern mxArray *sf_c15_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c15_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 16:
      {
        if (strcmp(aiChksum, "kRjh6w16qR2ajJq3FHwusF") == 0) {
          extern mxArray *sf_c16_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c16_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 17:
      {
        if (strcmp(aiChksum, "L5NTAplzklVqshecPa4hj") == 0) {
          extern mxArray *sf_c17_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c17_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 18:
      {
        if (strcmp(aiChksum, "xmhS1ASqFy18QLEWKqnyWD") == 0) {
          extern mxArray *sf_c18_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c18_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 19:
      {
        if (strcmp(aiChksum, "OvsGwFOI3NQZsNJX1vUMKF") == 0) {
          extern mxArray *sf_c19_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c19_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 20:
      {
        if (strcmp(aiChksum, "bdZKT28qm3neZHSrbQ4FEH") == 0) {
          extern mxArray *sf_c20_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c20_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 21:
      {
        if (strcmp(aiChksum, "V699iiUYGcKUYsuOEAQYIE") == 0) {
          extern mxArray *sf_c21_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c21_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 22:
      {
        if (strcmp(aiChksum, "bdZKT28qm3neZHSrbQ4FEH") == 0) {
          extern mxArray *sf_c22_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c22_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 23:
      {
        if (strcmp(aiChksum, "bdZKT28qm3neZHSrbQ4FEH") == 0) {
          extern mxArray *sf_c23_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c23_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 24:
      {
        if (strcmp(aiChksum, "a4BLA4EmTVlKbO9yUahgOH") == 0) {
          extern mxArray *sf_c24_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c24_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 25:
      {
        if (strcmp(aiChksum, "ZRDEY1y09s8YDEVqmnEAKE") == 0) {
          extern mxArray *sf_c25_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c25_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 26:
      {
        if (strcmp(aiChksum, "VjDRurwmAGoDOdI1WxbcUF") == 0) {
          extern mxArray *sf_c26_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c26_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 27:
      {
        if (strcmp(aiChksum, "bdZKT28qm3neZHSrbQ4FEH") == 0) {
          extern mxArray *sf_c27_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c27_Walking01_withElmos_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 32:
      {
        if (strcmp(aiChksum, "cvbCWAEsbRZc6yd2VRq6SG") == 0) {
          extern mxArray *sf_c32_Walking01_withElmos_get_autoinheritance_info
            (void);
          plhs[0] = sf_c32_Walking01_withElmos_get_autoinheritance_info();
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

unsigned int sf_Walking01_withElmos_get_eml_resolved_functions_info( int nlhs,
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
          *sf_c1_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c1_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 2:
      {
        extern const mxArray
          *sf_c2_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 5:
      {
        extern const mxArray
          *sf_c5_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c5_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 6:
      {
        extern const mxArray
          *sf_c6_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c6_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 7:
      {
        extern const mxArray
          *sf_c7_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c7_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 10:
      {
        extern const mxArray
          *sf_c10_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c10_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 15:
      {
        extern const mxArray
          *sf_c15_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c15_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 16:
      {
        extern const mxArray
          *sf_c16_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c16_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 17:
      {
        extern const mxArray
          *sf_c17_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c17_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 18:
      {
        extern const mxArray
          *sf_c18_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c18_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 19:
      {
        extern const mxArray
          *sf_c19_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c19_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 20:
      {
        extern const mxArray
          *sf_c20_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c20_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 21:
      {
        extern const mxArray
          *sf_c21_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c21_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 22:
      {
        extern const mxArray
          *sf_c22_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c22_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 23:
      {
        extern const mxArray
          *sf_c23_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c23_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 24:
      {
        extern const mxArray
          *sf_c24_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c24_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 25:
      {
        extern const mxArray
          *sf_c25_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c25_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 26:
      {
        extern const mxArray
          *sf_c26_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c26_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 27:
      {
        extern const mxArray
          *sf_c27_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c27_Walking01_withElmos_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 32:
      {
        extern const mxArray
          *sf_c32_Walking01_withElmos_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c32_Walking01_withElmos_get_eml_resolved_functions_info();
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

unsigned int sf_Walking01_withElmos_third_party_uses_info( int nlhs, mxArray *
  plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
          extern mxArray *sf_c1_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c1_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "vnzLWXguRHZfcDe80NRhwF") == 0) {
          extern mxArray *sf_c2_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c2_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "SjtkZZxyw5jP8NWyl6PAiB") == 0) {
          extern mxArray *sf_c3_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c3_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "lpJvuKaf6wET1A4puNGxCG") == 0) {
          extern mxArray *sf_c5_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c5_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
          extern mxArray *sf_c6_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c6_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c7_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c7_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "VHMA4mlzML9q61UItY3YMB") == 0) {
          extern mxArray *sf_c9_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c9_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "qB0qk8dCX4yOBjrH83k3ZG") == 0) {
          extern mxArray *sf_c10_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c10_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "5ycb0rqNkFZszaDdsfMMHG") == 0) {
          extern mxArray *sf_c11_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c11_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "fRYnfhRY9uzxFezFZl0zND") == 0) {
          extern mxArray *sf_c15_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c15_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "ctmA7vBYMeRwVpCT8K4e7C") == 0) {
          extern mxArray *sf_c16_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c16_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "Fymzr2ID0LmlYewmp9SoiB") == 0) {
          extern mxArray *sf_c17_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c17_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "71WIr8ml2bwzQstRISnWiE") == 0) {
          extern mxArray *sf_c18_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c18_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "9cc6KRo2aVDe0Hcoi5bDAD") == 0) {
          extern mxArray *sf_c19_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c19_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "QcyolaGX62rbNZaAtl54zB") == 0) {
          extern mxArray *sf_c20_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c20_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c21_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c21_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "7eY2IeKhDwzszN3wGMiYCE") == 0) {
          extern mxArray *sf_c22_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c22_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "jxKXL3eWLGWglct8H7LDvD") == 0) {
          extern mxArray *sf_c23_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c23_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "mfov7pLG2vXuk5uP140IbE") == 0) {
          extern mxArray *sf_c24_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c24_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "V8DcCJKGSDtSAUYceOllI") == 0) {
          extern mxArray *sf_c25_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c25_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "EYxtjDFFZ2nzClfv96SCvF") == 0) {
          extern mxArray *sf_c26_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c26_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "7eY2IeKhDwzszN3wGMiYCE") == 0) {
          extern mxArray *sf_c27_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c27_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "jKgAKaX2WSqj8ZiWsQ1uVD") == 0) {
          extern mxArray *sf_c32_Walking01_withElmos_third_party_uses_info(void);
          plhs[0] = sf_c32_Walking01_withElmos_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Walking01_withElmos_jit_fallback_info( int nlhs, mxArray * plhs[],
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
        if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
          extern mxArray *sf_c1_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c1_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "vnzLWXguRHZfcDe80NRhwF") == 0) {
          extern mxArray *sf_c2_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c2_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "SjtkZZxyw5jP8NWyl6PAiB") == 0) {
          extern mxArray *sf_c3_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c3_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "lpJvuKaf6wET1A4puNGxCG") == 0) {
          extern mxArray *sf_c5_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c5_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
          extern mxArray *sf_c6_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c6_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c7_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c7_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "VHMA4mlzML9q61UItY3YMB") == 0) {
          extern mxArray *sf_c9_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c9_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "qB0qk8dCX4yOBjrH83k3ZG") == 0) {
          extern mxArray *sf_c10_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c10_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "5ycb0rqNkFZszaDdsfMMHG") == 0) {
          extern mxArray *sf_c11_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c11_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "fRYnfhRY9uzxFezFZl0zND") == 0) {
          extern mxArray *sf_c15_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c15_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "ctmA7vBYMeRwVpCT8K4e7C") == 0) {
          extern mxArray *sf_c16_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c16_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "Fymzr2ID0LmlYewmp9SoiB") == 0) {
          extern mxArray *sf_c17_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c17_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "71WIr8ml2bwzQstRISnWiE") == 0) {
          extern mxArray *sf_c18_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c18_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "9cc6KRo2aVDe0Hcoi5bDAD") == 0) {
          extern mxArray *sf_c19_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c19_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "QcyolaGX62rbNZaAtl54zB") == 0) {
          extern mxArray *sf_c20_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c20_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c21_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c21_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "7eY2IeKhDwzszN3wGMiYCE") == 0) {
          extern mxArray *sf_c22_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c22_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "jxKXL3eWLGWglct8H7LDvD") == 0) {
          extern mxArray *sf_c23_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c23_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "mfov7pLG2vXuk5uP140IbE") == 0) {
          extern mxArray *sf_c24_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c24_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "V8DcCJKGSDtSAUYceOllI") == 0) {
          extern mxArray *sf_c25_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c25_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "EYxtjDFFZ2nzClfv96SCvF") == 0) {
          extern mxArray *sf_c26_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c26_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "7eY2IeKhDwzszN3wGMiYCE") == 0) {
          extern mxArray *sf_c27_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c27_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "jKgAKaX2WSqj8ZiWsQ1uVD") == 0) {
          extern mxArray *sf_c32_Walking01_withElmos_jit_fallback_info(void);
          plhs[0] = sf_c32_Walking01_withElmos_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_Walking01_withElmos_updateBuildInfo_args_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
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
        if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
          extern mxArray *sf_c1_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c1_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 2:
      {
        if (strcmp(tpChksum, "vnzLWXguRHZfcDe80NRhwF") == 0) {
          extern mxArray *sf_c2_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c2_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "SjtkZZxyw5jP8NWyl6PAiB") == 0) {
          extern mxArray *sf_c3_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c3_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 5:
      {
        if (strcmp(tpChksum, "lpJvuKaf6wET1A4puNGxCG") == 0) {
          extern mxArray *sf_c5_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c5_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 6:
      {
        if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
          extern mxArray *sf_c6_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c6_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 7:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c7_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c7_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "VHMA4mlzML9q61UItY3YMB") == 0) {
          extern mxArray *sf_c9_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c9_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 10:
      {
        if (strcmp(tpChksum, "qB0qk8dCX4yOBjrH83k3ZG") == 0) {
          extern mxArray *sf_c10_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c10_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "5ycb0rqNkFZszaDdsfMMHG") == 0) {
          extern mxArray *sf_c11_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c11_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 15:
      {
        if (strcmp(tpChksum, "fRYnfhRY9uzxFezFZl0zND") == 0) {
          extern mxArray *sf_c15_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c15_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 16:
      {
        if (strcmp(tpChksum, "ctmA7vBYMeRwVpCT8K4e7C") == 0) {
          extern mxArray *sf_c16_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c16_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 17:
      {
        if (strcmp(tpChksum, "Fymzr2ID0LmlYewmp9SoiB") == 0) {
          extern mxArray *sf_c17_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c17_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 18:
      {
        if (strcmp(tpChksum, "71WIr8ml2bwzQstRISnWiE") == 0) {
          extern mxArray *sf_c18_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c18_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 19:
      {
        if (strcmp(tpChksum, "9cc6KRo2aVDe0Hcoi5bDAD") == 0) {
          extern mxArray *sf_c19_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c19_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 20:
      {
        if (strcmp(tpChksum, "QcyolaGX62rbNZaAtl54zB") == 0) {
          extern mxArray *sf_c20_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c20_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 21:
      {
        if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
          extern mxArray *sf_c21_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c21_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 22:
      {
        if (strcmp(tpChksum, "7eY2IeKhDwzszN3wGMiYCE") == 0) {
          extern mxArray *sf_c22_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c22_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 23:
      {
        if (strcmp(tpChksum, "jxKXL3eWLGWglct8H7LDvD") == 0) {
          extern mxArray *sf_c23_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c23_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 24:
      {
        if (strcmp(tpChksum, "mfov7pLG2vXuk5uP140IbE") == 0) {
          extern mxArray *sf_c24_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c24_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 25:
      {
        if (strcmp(tpChksum, "V8DcCJKGSDtSAUYceOllI") == 0) {
          extern mxArray *sf_c25_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c25_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 26:
      {
        if (strcmp(tpChksum, "EYxtjDFFZ2nzClfv96SCvF") == 0) {
          extern mxArray *sf_c26_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c26_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 27:
      {
        if (strcmp(tpChksum, "7eY2IeKhDwzszN3wGMiYCE") == 0) {
          extern mxArray *sf_c27_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c27_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     case 32:
      {
        if (strcmp(tpChksum, "jKgAKaX2WSqj8ZiWsQ1uVD") == 0) {
          extern mxArray *sf_c32_Walking01_withElmos_updateBuildInfo_args_info
            (void);
          plhs[0] = sf_c32_Walking01_withElmos_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_Walking01_withElmos_get_post_codegen_info( int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 1:
    {
      if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
        extern mxArray *sf_c1_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c1_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 2:
    {
      if (strcmp(tpChksum, "vnzLWXguRHZfcDe80NRhwF") == 0) {
        extern mxArray *sf_c2_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c2_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "SjtkZZxyw5jP8NWyl6PAiB") == 0) {
        extern mxArray *sf_c3_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c3_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 5:
    {
      if (strcmp(tpChksum, "lpJvuKaf6wET1A4puNGxCG") == 0) {
        extern mxArray *sf_c5_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c5_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 6:
    {
      if (strcmp(tpChksum, "SyLw0dFP35AsXquPnQ1VRB") == 0) {
        extern mxArray *sf_c6_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c6_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 7:
    {
      if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
        extern mxArray *sf_c7_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c7_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "VHMA4mlzML9q61UItY3YMB") == 0) {
        extern mxArray *sf_c9_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c9_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 10:
    {
      if (strcmp(tpChksum, "qB0qk8dCX4yOBjrH83k3ZG") == 0) {
        extern mxArray *sf_c10_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c10_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 11:
    {
      if (strcmp(tpChksum, "5ycb0rqNkFZszaDdsfMMHG") == 0) {
        extern mxArray *sf_c11_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c11_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 15:
    {
      if (strcmp(tpChksum, "fRYnfhRY9uzxFezFZl0zND") == 0) {
        extern mxArray *sf_c15_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c15_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 16:
    {
      if (strcmp(tpChksum, "ctmA7vBYMeRwVpCT8K4e7C") == 0) {
        extern mxArray *sf_c16_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c16_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 17:
    {
      if (strcmp(tpChksum, "Fymzr2ID0LmlYewmp9SoiB") == 0) {
        extern mxArray *sf_c17_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c17_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 18:
    {
      if (strcmp(tpChksum, "71WIr8ml2bwzQstRISnWiE") == 0) {
        extern mxArray *sf_c18_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c18_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 19:
    {
      if (strcmp(tpChksum, "9cc6KRo2aVDe0Hcoi5bDAD") == 0) {
        extern mxArray *sf_c19_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c19_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 20:
    {
      if (strcmp(tpChksum, "QcyolaGX62rbNZaAtl54zB") == 0) {
        extern mxArray *sf_c20_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c20_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 21:
    {
      if (strcmp(tpChksum, "ufxMySglYksJ0YipIiDyrD") == 0) {
        extern mxArray *sf_c21_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c21_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 22:
    {
      if (strcmp(tpChksum, "7eY2IeKhDwzszN3wGMiYCE") == 0) {
        extern mxArray *sf_c22_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c22_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 23:
    {
      if (strcmp(tpChksum, "jxKXL3eWLGWglct8H7LDvD") == 0) {
        extern mxArray *sf_c23_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c23_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 24:
    {
      if (strcmp(tpChksum, "mfov7pLG2vXuk5uP140IbE") == 0) {
        extern mxArray *sf_c24_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c24_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 25:
    {
      if (strcmp(tpChksum, "V8DcCJKGSDtSAUYceOllI") == 0) {
        extern mxArray *sf_c25_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c25_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 26:
    {
      if (strcmp(tpChksum, "EYxtjDFFZ2nzClfv96SCvF") == 0) {
        extern mxArray *sf_c26_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c26_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 27:
    {
      if (strcmp(tpChksum, "7eY2IeKhDwzszN3wGMiYCE") == 0) {
        extern mxArray *sf_c27_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c27_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   case 32:
    {
      if (strcmp(tpChksum, "jKgAKaX2WSqj8ZiWsQ1uVD") == 0) {
        extern mxArray *sf_c32_Walking01_withElmos_get_post_codegen_info(void);
        plhs[0] = sf_c32_Walking01_withElmos_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void Walking01_withElmos_debug_initialize(struct SfDebugInstanceStruct*
  debugInstance)
{
  _Walking01_withElmosMachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "Walking01_withElmos","sfun",0,23,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _Walking01_withElmosMachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _Walking01_withElmosMachineNumber_,0);
}

void Walking01_withElmos_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_Walking01_withElmos_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info(
      "Walking01_withElmos", "Walking01_withElmos");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_Walking01_withElmos_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
