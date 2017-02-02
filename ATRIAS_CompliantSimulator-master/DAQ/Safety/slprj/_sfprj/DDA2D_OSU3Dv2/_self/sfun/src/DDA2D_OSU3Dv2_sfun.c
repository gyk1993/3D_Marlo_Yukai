/* Include files */

#define IN_SF_MACHINE_SOURCE           1
#include "DDA2D_OSU3Dv2_sfun.h"
#include "DDA2D_OSU3Dv2_sfun_debug_macros.h"
#include "c2_DDA2D_OSU3Dv2.h"
#include "c3_DDA2D_OSU3Dv2.h"
#include "c4_DDA2D_OSU3Dv2.h"
#include "c8_DDA2D_OSU3Dv2.h"
#include "c9_DDA2D_OSU3Dv2.h"
#include "c11_DDA2D_OSU3Dv2.h"
#include "c64_DDA2D_OSU3Dv2.h"
#include "c65_DDA2D_OSU3Dv2.h"
#include "c66_DDA2D_OSU3Dv2.h"
#include "c67_DDA2D_OSU3Dv2.h"
#include "c68_DDA2D_OSU3Dv2.h"
#include "c69_DDA2D_OSU3Dv2.h"
#include "c70_DDA2D_OSU3Dv2.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
uint32_T _DDA2D_OSU3Dv2MachineNumber_;

/* Function Declarations */

/* Function Definitions */
void DDA2D_OSU3Dv2_initializer(void)
{
}

void DDA2D_OSU3Dv2_terminator(void)
{
}

/* SFunction Glue Code */
unsigned int sf_DDA2D_OSU3Dv2_method_dispatcher(SimStruct *simstructPtr,
  unsigned int chartFileNumber, const char* specsCksum, int_T method, void *data)
{
  if (chartFileNumber==2) {
    c2_DDA2D_OSU3Dv2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==3) {
    c3_DDA2D_OSU3Dv2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==4) {
    c4_DDA2D_OSU3Dv2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==8) {
    c8_DDA2D_OSU3Dv2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==9) {
    c9_DDA2D_OSU3Dv2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==11) {
    c11_DDA2D_OSU3Dv2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==64) {
    c64_DDA2D_OSU3Dv2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==65) {
    c65_DDA2D_OSU3Dv2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==66) {
    c66_DDA2D_OSU3Dv2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==67) {
    c67_DDA2D_OSU3Dv2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==68) {
    c68_DDA2D_OSU3Dv2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==69) {
    c69_DDA2D_OSU3Dv2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  if (chartFileNumber==70) {
    c70_DDA2D_OSU3Dv2_method_dispatcher(simstructPtr, method, data);
    return 1;
  }

  return 0;
}

extern void sf_DDA2D_OSU3Dv2_uses_exported_functions(int nlhs, mxArray * plhs[],
  int nrhs, const mxArray * prhs[])
{
  plhs[0] = mxCreateLogicalScalar(0);
}

unsigned int sf_DDA2D_OSU3Dv2_process_testpoint_info_call( int nlhs, mxArray *
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
  if (!strcmp(machineName, "DDA2D_OSU3Dv2")) {
    unsigned int chartFileNumber;
    chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
    switch (chartFileNumber) {
     case 69:
      {
        extern mxArray *sf_c69_DDA2D_OSU3Dv2_get_testpoint_info(void);
        plhs[0] = sf_c69_DDA2D_OSU3Dv2_get_testpoint_info();
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

unsigned int sf_DDA2D_OSU3Dv2_process_check_sum_call( int nlhs, mxArray * plhs[],
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
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2629268504U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(1663538925U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(615990248U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(1596317957U);
    } else if (!strcmp(commandName,"exportedFcn")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0U);
    } else if (!strcmp(commandName,"makefile")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(2747782003U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3908068084U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(677186006U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(4234502947U);
    } else if (nrhs==3 && !strcmp(commandName,"chart")) {
      unsigned int chartFileNumber;
      chartFileNumber = (unsigned int)mxGetScalar(prhs[2]);
      switch (chartFileNumber) {
       case 2:
        {
          extern void sf_c2_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
          sf_c2_DDA2D_OSU3Dv2_get_check_sum(plhs);
          break;
        }

       case 3:
        {
          extern void sf_c3_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
          sf_c3_DDA2D_OSU3Dv2_get_check_sum(plhs);
          break;
        }

       case 4:
        {
          extern void sf_c4_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
          sf_c4_DDA2D_OSU3Dv2_get_check_sum(plhs);
          break;
        }

       case 8:
        {
          extern void sf_c8_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
          sf_c8_DDA2D_OSU3Dv2_get_check_sum(plhs);
          break;
        }

       case 9:
        {
          extern void sf_c9_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
          sf_c9_DDA2D_OSU3Dv2_get_check_sum(plhs);
          break;
        }

       case 11:
        {
          extern void sf_c11_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
          sf_c11_DDA2D_OSU3Dv2_get_check_sum(plhs);
          break;
        }

       case 64:
        {
          extern void sf_c64_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
          sf_c64_DDA2D_OSU3Dv2_get_check_sum(plhs);
          break;
        }

       case 65:
        {
          extern void sf_c65_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
          sf_c65_DDA2D_OSU3Dv2_get_check_sum(plhs);
          break;
        }

       case 66:
        {
          extern void sf_c66_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
          sf_c66_DDA2D_OSU3Dv2_get_check_sum(plhs);
          break;
        }

       case 67:
        {
          extern void sf_c67_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
          sf_c67_DDA2D_OSU3Dv2_get_check_sum(plhs);
          break;
        }

       case 68:
        {
          extern void sf_c68_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
          sf_c68_DDA2D_OSU3Dv2_get_check_sum(plhs);
          break;
        }

       case 69:
        {
          extern void sf_c69_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
          sf_c69_DDA2D_OSU3Dv2_get_check_sum(plhs);
          break;
        }

       case 70:
        {
          extern void sf_c70_DDA2D_OSU3Dv2_get_check_sum(mxArray *plhs[]);
          sf_c70_DDA2D_OSU3Dv2_get_check_sum(plhs);
          break;
        }

       default:
        ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(0.0);
        ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(0.0);
      }
    } else if (!strcmp(commandName,"target")) {
      ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(652122230U);
      ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2246797076U);
      ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(2778786795U);
      ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2072275154U);
    } else {
      return 0;
    }
  } else {
    ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1249449840U);
    ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3016451662U);
    ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(1592486080U);
    ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(416461212U);
  }

  return 1;

#else

  return 0;

#endif

}

unsigned int sf_DDA2D_OSU3Dv2_autoinheritance_info( int nlhs, mxArray * plhs[],
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
     case 2:
      {
        if (strcmp(aiChksum, "vEIWRLhIfBRUyNCl5zNtu") == 0) {
          extern mxArray *sf_c2_DDA2D_OSU3Dv2_get_autoinheritance_info(void);
          plhs[0] = sf_c2_DDA2D_OSU3Dv2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 3:
      {
        if (strcmp(aiChksum, "1CnjG2H1VJ51evOfceguAH") == 0) {
          extern mxArray *sf_c3_DDA2D_OSU3Dv2_get_autoinheritance_info(void);
          plhs[0] = sf_c3_DDA2D_OSU3Dv2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 4:
      {
        if (strcmp(aiChksum, "tzhUsPcxCAlzxo8JLTsA8B") == 0) {
          extern mxArray *sf_c4_DDA2D_OSU3Dv2_get_autoinheritance_info(void);
          plhs[0] = sf_c4_DDA2D_OSU3Dv2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 8:
      {
        if (strcmp(aiChksum, "1CnjG2H1VJ51evOfceguAH") == 0) {
          extern mxArray *sf_c8_DDA2D_OSU3Dv2_get_autoinheritance_info(void);
          plhs[0] = sf_c8_DDA2D_OSU3Dv2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 9:
      {
        if (strcmp(aiChksum, "jxIMOYl4hjxE1mpxGa1EtE") == 0) {
          extern mxArray *sf_c9_DDA2D_OSU3Dv2_get_autoinheritance_info(void);
          plhs[0] = sf_c9_DDA2D_OSU3Dv2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 11:
      {
        if (strcmp(aiChksum, "E2HAxAMZspJ0Ofd1RozEVB") == 0) {
          extern mxArray *sf_c11_DDA2D_OSU3Dv2_get_autoinheritance_info(void);
          plhs[0] = sf_c11_DDA2D_OSU3Dv2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 64:
      {
        if (strcmp(aiChksum, "BiioFsR1miNQT6nxbkj4XH") == 0) {
          extern mxArray *sf_c64_DDA2D_OSU3Dv2_get_autoinheritance_info(void);
          plhs[0] = sf_c64_DDA2D_OSU3Dv2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 65:
      {
        if (strcmp(aiChksum, "GUkVMi26Ya3YetSku7IwIC") == 0) {
          extern mxArray *sf_c65_DDA2D_OSU3Dv2_get_autoinheritance_info(void);
          plhs[0] = sf_c65_DDA2D_OSU3Dv2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 66:
      {
        if (strcmp(aiChksum, "ChS2lKeWPNZAFRBy7eM4rG") == 0) {
          extern mxArray *sf_c66_DDA2D_OSU3Dv2_get_autoinheritance_info(void);
          plhs[0] = sf_c66_DDA2D_OSU3Dv2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 67:
      {
        if (strcmp(aiChksum, "o1hm4vkhKUV3wzhDDCFrxF") == 0) {
          extern mxArray *sf_c67_DDA2D_OSU3Dv2_get_autoinheritance_info(void);
          plhs[0] = sf_c67_DDA2D_OSU3Dv2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 68:
      {
        if (strcmp(aiChksum, "sbmthWem3ms7TgwFWzJeyE") == 0) {
          extern mxArray *sf_c68_DDA2D_OSU3Dv2_get_autoinheritance_info(void);
          plhs[0] = sf_c68_DDA2D_OSU3Dv2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 69:
      {
        if (strcmp(aiChksum, "LtY1LK1Gc1laiwNaQIV0rF") == 0) {
          extern mxArray *sf_c69_DDA2D_OSU3Dv2_get_autoinheritance_info(void);
          plhs[0] = sf_c69_DDA2D_OSU3Dv2_get_autoinheritance_info();
          break;
        }

        plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
        break;
      }

     case 70:
      {
        if (strcmp(aiChksum, "nfOLpyB9fJrYrqS3PRQ8MH") == 0) {
          extern mxArray *sf_c70_DDA2D_OSU3Dv2_get_autoinheritance_info(void);
          plhs[0] = sf_c70_DDA2D_OSU3Dv2_get_autoinheritance_info();
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

unsigned int sf_DDA2D_OSU3Dv2_get_eml_resolved_functions_info( int nlhs, mxArray
  * plhs[], int nrhs, const mxArray * prhs[] )
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
     case 2:
      {
        extern const mxArray
          *sf_c2_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c2_DDA2D_OSU3Dv2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 3:
      {
        extern const mxArray
          *sf_c3_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c3_DDA2D_OSU3Dv2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 4:
      {
        extern const mxArray
          *sf_c4_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c4_DDA2D_OSU3Dv2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 8:
      {
        extern const mxArray
          *sf_c8_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c8_DDA2D_OSU3Dv2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 9:
      {
        extern const mxArray
          *sf_c9_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c9_DDA2D_OSU3Dv2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 11:
      {
        extern const mxArray
          *sf_c11_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c11_DDA2D_OSU3Dv2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 64:
      {
        extern const mxArray
          *sf_c64_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c64_DDA2D_OSU3Dv2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 65:
      {
        extern const mxArray
          *sf_c65_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c65_DDA2D_OSU3Dv2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 66:
      {
        extern const mxArray
          *sf_c66_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c66_DDA2D_OSU3Dv2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 67:
      {
        extern const mxArray
          *sf_c67_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c67_DDA2D_OSU3Dv2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 68:
      {
        extern const mxArray
          *sf_c68_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c68_DDA2D_OSU3Dv2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 69:
      {
        extern const mxArray
          *sf_c69_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c69_DDA2D_OSU3Dv2_get_eml_resolved_functions_info();
        plhs[0] = mxDuplicateArray(persistentMxArray);
        mxDestroyArray(persistentMxArray);
        break;
      }

     case 70:
      {
        extern const mxArray
          *sf_c70_DDA2D_OSU3Dv2_get_eml_resolved_functions_info(void);
        mxArray *persistentMxArray = (mxArray *)
          sf_c70_DDA2D_OSU3Dv2_get_eml_resolved_functions_info();
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

unsigned int sf_DDA2D_OSU3Dv2_third_party_uses_info( int nlhs, mxArray * plhs[],
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
     case 2:
      {
        if (strcmp(tpChksum, "xYxu92EniUSp1bUlgzckRF") == 0) {
          extern mxArray *sf_c2_DDA2D_OSU3Dv2_third_party_uses_info(void);
          plhs[0] = sf_c2_DDA2D_OSU3Dv2_third_party_uses_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "jozVARIf7424X7eC4xzmRG") == 0) {
          extern mxArray *sf_c3_DDA2D_OSU3Dv2_third_party_uses_info(void);
          plhs[0] = sf_c3_DDA2D_OSU3Dv2_third_party_uses_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "xVky7YK8spNffnrxsYZf9E") == 0) {
          extern mxArray *sf_c4_DDA2D_OSU3Dv2_third_party_uses_info(void);
          plhs[0] = sf_c4_DDA2D_OSU3Dv2_third_party_uses_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "jozVARIf7424X7eC4xzmRG") == 0) {
          extern mxArray *sf_c8_DDA2D_OSU3Dv2_third_party_uses_info(void);
          plhs[0] = sf_c8_DDA2D_OSU3Dv2_third_party_uses_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "vCdDf1Y4QLbRLMu4yQnxxF") == 0) {
          extern mxArray *sf_c9_DDA2D_OSU3Dv2_third_party_uses_info(void);
          plhs[0] = sf_c9_DDA2D_OSU3Dv2_third_party_uses_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "bjXFo3OIYVQJL2hv0nek2B") == 0) {
          extern mxArray *sf_c11_DDA2D_OSU3Dv2_third_party_uses_info(void);
          plhs[0] = sf_c11_DDA2D_OSU3Dv2_third_party_uses_info();
          break;
        }
      }

     case 64:
      {
        if (strcmp(tpChksum, "4rHvCGgzaPltmg9pfSHdYB") == 0) {
          extern mxArray *sf_c64_DDA2D_OSU3Dv2_third_party_uses_info(void);
          plhs[0] = sf_c64_DDA2D_OSU3Dv2_third_party_uses_info();
          break;
        }
      }

     case 65:
      {
        if (strcmp(tpChksum, "LpmaMG19KJccs1xh1NGlXH") == 0) {
          extern mxArray *sf_c65_DDA2D_OSU3Dv2_third_party_uses_info(void);
          plhs[0] = sf_c65_DDA2D_OSU3Dv2_third_party_uses_info();
          break;
        }
      }

     case 66:
      {
        if (strcmp(tpChksum, "5HdTWuvJJSfrkpdXos1p9D") == 0) {
          extern mxArray *sf_c66_DDA2D_OSU3Dv2_third_party_uses_info(void);
          plhs[0] = sf_c66_DDA2D_OSU3Dv2_third_party_uses_info();
          break;
        }
      }

     case 67:
      {
        if (strcmp(tpChksum, "jMXLkjmTKbjAEJqPdBIEM") == 0) {
          extern mxArray *sf_c67_DDA2D_OSU3Dv2_third_party_uses_info(void);
          plhs[0] = sf_c67_DDA2D_OSU3Dv2_third_party_uses_info();
          break;
        }
      }

     case 68:
      {
        if (strcmp(tpChksum, "shrUG2xDb3KPCyGwEegq7F") == 0) {
          extern mxArray *sf_c68_DDA2D_OSU3Dv2_third_party_uses_info(void);
          plhs[0] = sf_c68_DDA2D_OSU3Dv2_third_party_uses_info();
          break;
        }
      }

     case 69:
      {
        if (strcmp(tpChksum, "OJyNgPDga017dMB0pVIv9C") == 0) {
          extern mxArray *sf_c69_DDA2D_OSU3Dv2_third_party_uses_info(void);
          plhs[0] = sf_c69_DDA2D_OSU3Dv2_third_party_uses_info();
          break;
        }
      }

     case 70:
      {
        if (strcmp(tpChksum, "y6r5H1utZtVLrGXfpThPbH") == 0) {
          extern mxArray *sf_c70_DDA2D_OSU3Dv2_third_party_uses_info(void);
          plhs[0] = sf_c70_DDA2D_OSU3Dv2_third_party_uses_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_DDA2D_OSU3Dv2_jit_fallback_info( int nlhs, mxArray * plhs[], int
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
     case 2:
      {
        if (strcmp(tpChksum, "xYxu92EniUSp1bUlgzckRF") == 0) {
          extern mxArray *sf_c2_DDA2D_OSU3Dv2_jit_fallback_info(void);
          plhs[0] = sf_c2_DDA2D_OSU3Dv2_jit_fallback_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "jozVARIf7424X7eC4xzmRG") == 0) {
          extern mxArray *sf_c3_DDA2D_OSU3Dv2_jit_fallback_info(void);
          plhs[0] = sf_c3_DDA2D_OSU3Dv2_jit_fallback_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "xVky7YK8spNffnrxsYZf9E") == 0) {
          extern mxArray *sf_c4_DDA2D_OSU3Dv2_jit_fallback_info(void);
          plhs[0] = sf_c4_DDA2D_OSU3Dv2_jit_fallback_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "jozVARIf7424X7eC4xzmRG") == 0) {
          extern mxArray *sf_c8_DDA2D_OSU3Dv2_jit_fallback_info(void);
          plhs[0] = sf_c8_DDA2D_OSU3Dv2_jit_fallback_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "vCdDf1Y4QLbRLMu4yQnxxF") == 0) {
          extern mxArray *sf_c9_DDA2D_OSU3Dv2_jit_fallback_info(void);
          plhs[0] = sf_c9_DDA2D_OSU3Dv2_jit_fallback_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "bjXFo3OIYVQJL2hv0nek2B") == 0) {
          extern mxArray *sf_c11_DDA2D_OSU3Dv2_jit_fallback_info(void);
          plhs[0] = sf_c11_DDA2D_OSU3Dv2_jit_fallback_info();
          break;
        }
      }

     case 64:
      {
        if (strcmp(tpChksum, "4rHvCGgzaPltmg9pfSHdYB") == 0) {
          extern mxArray *sf_c64_DDA2D_OSU3Dv2_jit_fallback_info(void);
          plhs[0] = sf_c64_DDA2D_OSU3Dv2_jit_fallback_info();
          break;
        }
      }

     case 65:
      {
        if (strcmp(tpChksum, "LpmaMG19KJccs1xh1NGlXH") == 0) {
          extern mxArray *sf_c65_DDA2D_OSU3Dv2_jit_fallback_info(void);
          plhs[0] = sf_c65_DDA2D_OSU3Dv2_jit_fallback_info();
          break;
        }
      }

     case 66:
      {
        if (strcmp(tpChksum, "5HdTWuvJJSfrkpdXos1p9D") == 0) {
          extern mxArray *sf_c66_DDA2D_OSU3Dv2_jit_fallback_info(void);
          plhs[0] = sf_c66_DDA2D_OSU3Dv2_jit_fallback_info();
          break;
        }
      }

     case 67:
      {
        if (strcmp(tpChksum, "jMXLkjmTKbjAEJqPdBIEM") == 0) {
          extern mxArray *sf_c67_DDA2D_OSU3Dv2_jit_fallback_info(void);
          plhs[0] = sf_c67_DDA2D_OSU3Dv2_jit_fallback_info();
          break;
        }
      }

     case 68:
      {
        if (strcmp(tpChksum, "shrUG2xDb3KPCyGwEegq7F") == 0) {
          extern mxArray *sf_c68_DDA2D_OSU3Dv2_jit_fallback_info(void);
          plhs[0] = sf_c68_DDA2D_OSU3Dv2_jit_fallback_info();
          break;
        }
      }

     case 69:
      {
        if (strcmp(tpChksum, "OJyNgPDga017dMB0pVIv9C") == 0) {
          extern mxArray *sf_c69_DDA2D_OSU3Dv2_jit_fallback_info(void);
          plhs[0] = sf_c69_DDA2D_OSU3Dv2_jit_fallback_info();
          break;
        }
      }

     case 70:
      {
        if (strcmp(tpChksum, "y6r5H1utZtVLrGXfpThPbH") == 0) {
          extern mxArray *sf_c70_DDA2D_OSU3Dv2_jit_fallback_info(void);
          plhs[0] = sf_c70_DDA2D_OSU3Dv2_jit_fallback_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

unsigned int sf_DDA2D_OSU3Dv2_updateBuildInfo_args_info( int nlhs, mxArray *
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
     case 2:
      {
        if (strcmp(tpChksum, "xYxu92EniUSp1bUlgzckRF") == 0) {
          extern mxArray *sf_c2_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c2_DDA2D_OSU3Dv2_updateBuildInfo_args_info();
          break;
        }
      }

     case 3:
      {
        if (strcmp(tpChksum, "jozVARIf7424X7eC4xzmRG") == 0) {
          extern mxArray *sf_c3_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c3_DDA2D_OSU3Dv2_updateBuildInfo_args_info();
          break;
        }
      }

     case 4:
      {
        if (strcmp(tpChksum, "xVky7YK8spNffnrxsYZf9E") == 0) {
          extern mxArray *sf_c4_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c4_DDA2D_OSU3Dv2_updateBuildInfo_args_info();
          break;
        }
      }

     case 8:
      {
        if (strcmp(tpChksum, "jozVARIf7424X7eC4xzmRG") == 0) {
          extern mxArray *sf_c8_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c8_DDA2D_OSU3Dv2_updateBuildInfo_args_info();
          break;
        }
      }

     case 9:
      {
        if (strcmp(tpChksum, "vCdDf1Y4QLbRLMu4yQnxxF") == 0) {
          extern mxArray *sf_c9_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c9_DDA2D_OSU3Dv2_updateBuildInfo_args_info();
          break;
        }
      }

     case 11:
      {
        if (strcmp(tpChksum, "bjXFo3OIYVQJL2hv0nek2B") == 0) {
          extern mxArray *sf_c11_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c11_DDA2D_OSU3Dv2_updateBuildInfo_args_info();
          break;
        }
      }

     case 64:
      {
        if (strcmp(tpChksum, "4rHvCGgzaPltmg9pfSHdYB") == 0) {
          extern mxArray *sf_c64_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c64_DDA2D_OSU3Dv2_updateBuildInfo_args_info();
          break;
        }
      }

     case 65:
      {
        if (strcmp(tpChksum, "LpmaMG19KJccs1xh1NGlXH") == 0) {
          extern mxArray *sf_c65_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c65_DDA2D_OSU3Dv2_updateBuildInfo_args_info();
          break;
        }
      }

     case 66:
      {
        if (strcmp(tpChksum, "5HdTWuvJJSfrkpdXos1p9D") == 0) {
          extern mxArray *sf_c66_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c66_DDA2D_OSU3Dv2_updateBuildInfo_args_info();
          break;
        }
      }

     case 67:
      {
        if (strcmp(tpChksum, "jMXLkjmTKbjAEJqPdBIEM") == 0) {
          extern mxArray *sf_c67_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c67_DDA2D_OSU3Dv2_updateBuildInfo_args_info();
          break;
        }
      }

     case 68:
      {
        if (strcmp(tpChksum, "shrUG2xDb3KPCyGwEegq7F") == 0) {
          extern mxArray *sf_c68_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c68_DDA2D_OSU3Dv2_updateBuildInfo_args_info();
          break;
        }
      }

     case 69:
      {
        if (strcmp(tpChksum, "OJyNgPDga017dMB0pVIv9C") == 0) {
          extern mxArray *sf_c69_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c69_DDA2D_OSU3Dv2_updateBuildInfo_args_info();
          break;
        }
      }

     case 70:
      {
        if (strcmp(tpChksum, "y6r5H1utZtVLrGXfpThPbH") == 0) {
          extern mxArray *sf_c70_DDA2D_OSU3Dv2_updateBuildInfo_args_info(void);
          plhs[0] = sf_c70_DDA2D_OSU3Dv2_updateBuildInfo_args_info();
          break;
        }
      }

     default:
      plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
    }
  }

  return 1;
}

void sf_DDA2D_OSU3Dv2_get_post_codegen_info( int nlhs, mxArray * plhs[], int
  nrhs, const mxArray * prhs[] )
{
  unsigned int chartFileNumber = (unsigned int) mxGetScalar(prhs[0]);
  char tpChksum[64];
  mxGetString(prhs[1], tpChksum,sizeof(tpChksum)/sizeof(char));
  tpChksum[(sizeof(tpChksum)/sizeof(char)-1)] = '\0';
  switch (chartFileNumber) {
   case 2:
    {
      if (strcmp(tpChksum, "xYxu92EniUSp1bUlgzckRF") == 0) {
        extern mxArray *sf_c2_DDA2D_OSU3Dv2_get_post_codegen_info(void);
        plhs[0] = sf_c2_DDA2D_OSU3Dv2_get_post_codegen_info();
        return;
      }
    }
    break;

   case 3:
    {
      if (strcmp(tpChksum, "jozVARIf7424X7eC4xzmRG") == 0) {
        extern mxArray *sf_c3_DDA2D_OSU3Dv2_get_post_codegen_info(void);
        plhs[0] = sf_c3_DDA2D_OSU3Dv2_get_post_codegen_info();
        return;
      }
    }
    break;

   case 4:
    {
      if (strcmp(tpChksum, "xVky7YK8spNffnrxsYZf9E") == 0) {
        extern mxArray *sf_c4_DDA2D_OSU3Dv2_get_post_codegen_info(void);
        plhs[0] = sf_c4_DDA2D_OSU3Dv2_get_post_codegen_info();
        return;
      }
    }
    break;

   case 8:
    {
      if (strcmp(tpChksum, "jozVARIf7424X7eC4xzmRG") == 0) {
        extern mxArray *sf_c8_DDA2D_OSU3Dv2_get_post_codegen_info(void);
        plhs[0] = sf_c8_DDA2D_OSU3Dv2_get_post_codegen_info();
        return;
      }
    }
    break;

   case 9:
    {
      if (strcmp(tpChksum, "vCdDf1Y4QLbRLMu4yQnxxF") == 0) {
        extern mxArray *sf_c9_DDA2D_OSU3Dv2_get_post_codegen_info(void);
        plhs[0] = sf_c9_DDA2D_OSU3Dv2_get_post_codegen_info();
        return;
      }
    }
    break;

   case 11:
    {
      if (strcmp(tpChksum, "bjXFo3OIYVQJL2hv0nek2B") == 0) {
        extern mxArray *sf_c11_DDA2D_OSU3Dv2_get_post_codegen_info(void);
        plhs[0] = sf_c11_DDA2D_OSU3Dv2_get_post_codegen_info();
        return;
      }
    }
    break;

   case 64:
    {
      if (strcmp(tpChksum, "4rHvCGgzaPltmg9pfSHdYB") == 0) {
        extern mxArray *sf_c64_DDA2D_OSU3Dv2_get_post_codegen_info(void);
        plhs[0] = sf_c64_DDA2D_OSU3Dv2_get_post_codegen_info();
        return;
      }
    }
    break;

   case 65:
    {
      if (strcmp(tpChksum, "LpmaMG19KJccs1xh1NGlXH") == 0) {
        extern mxArray *sf_c65_DDA2D_OSU3Dv2_get_post_codegen_info(void);
        plhs[0] = sf_c65_DDA2D_OSU3Dv2_get_post_codegen_info();
        return;
      }
    }
    break;

   case 66:
    {
      if (strcmp(tpChksum, "5HdTWuvJJSfrkpdXos1p9D") == 0) {
        extern mxArray *sf_c66_DDA2D_OSU3Dv2_get_post_codegen_info(void);
        plhs[0] = sf_c66_DDA2D_OSU3Dv2_get_post_codegen_info();
        return;
      }
    }
    break;

   case 67:
    {
      if (strcmp(tpChksum, "jMXLkjmTKbjAEJqPdBIEM") == 0) {
        extern mxArray *sf_c67_DDA2D_OSU3Dv2_get_post_codegen_info(void);
        plhs[0] = sf_c67_DDA2D_OSU3Dv2_get_post_codegen_info();
        return;
      }
    }
    break;

   case 68:
    {
      if (strcmp(tpChksum, "shrUG2xDb3KPCyGwEegq7F") == 0) {
        extern mxArray *sf_c68_DDA2D_OSU3Dv2_get_post_codegen_info(void);
        plhs[0] = sf_c68_DDA2D_OSU3Dv2_get_post_codegen_info();
        return;
      }
    }
    break;

   case 69:
    {
      if (strcmp(tpChksum, "OJyNgPDga017dMB0pVIv9C") == 0) {
        extern mxArray *sf_c69_DDA2D_OSU3Dv2_get_post_codegen_info(void);
        plhs[0] = sf_c69_DDA2D_OSU3Dv2_get_post_codegen_info();
        return;
      }
    }
    break;

   case 70:
    {
      if (strcmp(tpChksum, "y6r5H1utZtVLrGXfpThPbH") == 0) {
        extern mxArray *sf_c70_DDA2D_OSU3Dv2_get_post_codegen_info(void);
        plhs[0] = sf_c70_DDA2D_OSU3Dv2_get_post_codegen_info();
        return;
      }
    }
    break;

   default:
    break;
  }

  plhs[0] = mxCreateDoubleMatrix(0,0,mxREAL);
}

void DDA2D_OSU3Dv2_debug_initialize(struct SfDebugInstanceStruct* debugInstance)
{
  _DDA2D_OSU3Dv2MachineNumber_ = sf_debug_initialize_machine(debugInstance,
    "DDA2D_OSU3Dv2","sfun",0,13,0,0,0);
  sf_debug_set_machine_event_thresholds(debugInstance,
    _DDA2D_OSU3Dv2MachineNumber_,0,0);
  sf_debug_set_machine_data_thresholds(debugInstance,
    _DDA2D_OSU3Dv2MachineNumber_,0);
}

void DDA2D_OSU3Dv2_register_exported_symbols(SimStruct* S)
{
}

static mxArray* sRtwOptimizationInfoStruct= NULL;
mxArray* load_DDA2D_OSU3Dv2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct==NULL) {
    sRtwOptimizationInfoStruct = sf_load_rtw_optimization_info("DDA2D_OSU3Dv2",
      "DDA2D_OSU3Dv2");
    mexMakeArrayPersistent(sRtwOptimizationInfoStruct);
  }

  return(sRtwOptimizationInfoStruct);
}

void unload_DDA2D_OSU3Dv2_optimization_info(void)
{
  if (sRtwOptimizationInfoStruct!=NULL) {
    mxDestroyArray(sRtwOptimizationInfoStruct);
    sRtwOptimizationInfoStruct = NULL;
  }
}
