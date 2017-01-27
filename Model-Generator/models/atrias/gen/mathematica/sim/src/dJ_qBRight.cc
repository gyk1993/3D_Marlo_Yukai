/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:08 GMT-05:00
 */
#include "math2mat.hpp"

/*
 * Sub functions
 */
static void output1(double *p_output1,const double *x)
{
  double t1;
  double t2;
  double t3;
  double t4;
  double t5;
  double t6;
  double t7;
  double t8;
  double t9;
  double t10;
  double t11;
  double t12;
  double t13;
  double t14;
  double t15;
  double t16;
  double t17;
  double t18;
  double t19;
  double t20;
  double t21;
  double t22;
  double t23;
  double t24;
  double t25;
  t1 = x[6];
  t2 = x[3];
  t3 = Cos(t2);
  t4 = x[4];
  t5 = x[5];
  t6 = x[22];
  t7 = Cos(t4);
  t8 = Sin(t1);
  t9 = Sin(t2);
  t10 = Sin(t4);
  t11 = Cos(t1);
  t12 = Cos(t5);
  t13 = x[19];
  t14 = Sin(t5);
  t15 = x[20];
  t16 = x[21];
  t17 = t12*t9*t10;
  t18 = t3*t14;
  t19 = t17 + t18;
  t20 = t3*t12*t10*t13;
  t21 = -1.*t9*t14*t13;
  t22 = t7*t12*t9*t15;
  t23 = t3*t12*t16;
  t24 = -1.*t9*t10*t14*t16;
  t25 = t20 + t21 + t22 + t23 + t24;
  p_output1[10]=0.1831*(t11*t3*t6*t7 - 1.*t10*t15*t3*t8 - 1.*t13*t7*t8*t9 - 1.*t6*t8*(t10*t12*t3 - 1.*t14*t9) + t11*(-1.*t13*t14*t3 - 1.*t10*t14*t16*t3 + t12*t15*t3*t7 - 1.*t10*t12*t13*t9 - 1.*t12*t16*t9));
  p_output1[11]=0.1831*(t11*t25 - 1.*t19*t6*t8 + t13*t3*t7*t8 + t11*t6*t7*t9 - 1.*t10*t15*t8*t9);
  p_output1[12]=0.1831*(t10*t11*t14*t16 - 1.*t11*t12*t15*t7 - 1.*t11*t6*t7 + t10*t15*t8 + t10*t12*t6*t8);
  p_output1[13]=0.1831*(t11*t12*t13*t3*t7 - 1.*t10*t13*t3*t8 - 1.*t10*t11*t12*t15*t9 - 1.*t10*t11*t6*t9 - 1.*t11*t14*t16*t7*t9 - 1.*t15*t7*t8*t9 - 1.*t12*t6*t7*t8*t9);
  p_output1[14]=0.1831*(t10*t11*t12*t15*t3 + t10*t11*t3*t6 + t11*t14*t16*t3*t7 + t15*t3*t7*t8 + t12*t3*t6*t7*t8 + t11*t12*t13*t7*t9 - 1.*t10*t13*t8*t9);
  p_output1[15]=0.1831*t10*t11*t14*t15 - 0.1831*t11*t12*t16*t7 + 0.1831*t14*t6*t7*t8;
  p_output1[16]=-0.1831*t6*t8*(t12*t3 - 1.*t10*t14*t9) + 0.1831*t11*(-1.*t10*t13*t14*t3 - 1.*t14*t16*t3 - 1.*t12*t13*t9 - 1.*t10*t12*t16*t9 - 1.*t14*t15*t7*t9);
  p_output1[17]=-0.1831*t6*t8*(t10*t14*t3 + t12*t9) + 0.1831*t11*(t12*t13*t3 + t10*t12*t16*t3 + t14*t15*t3*t7 - 1.*t10*t13*t14*t9 - 1.*t14*t16*t9);
  p_output1[18]=0.1831*(-1.*t11*t15*t7 - 1.*t11*t12*t6*t7 + t10*t12*t15*t8 + t10*t6*t8 + t14*t16*t7*t8);
  p_output1[19]=0.1831*(-1.*t11*t19*t6 + t11*t13*t3*t7 - 1.*t25*t8 - 1.*t10*t11*t15*t9 - 1.*t6*t7*t8*t9);
  p_output1[20]=0.1831*(t10*t11*t15*t3 + t3*t6*t7*t8 + t11*t13*t7*t9 - 1.*t11*t6*(-1.*t10*t12*t3 + t14*t9) - 1.*t8*(t13*t14*t3 + t10*t14*t16*t3 - 1.*t12*t15*t3*t7 + t10*t12*t13*t9 + t12*t16*t9));
}



#ifdef MATLAB_MEX_FILE

#include "mex.h"
#include "matrix.h"

/*
 * Main function
 */
void mexFunction( int nlhs, mxArray *plhs[],
                  int nrhs, const mxArray *prhs[] )
{
  size_t mrows, ncols;

  double *x;
  double *p_output1;

  /*  Check for proper number of arguments.  */ 
  if( nrhs != 1)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:invalidNumInputs", "One input(s) required (x).");
    }
  else if( nlhs > 1)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:maxlhs", "Too many output arguments.");
    }

  /*  The input must be a noncomplex double vector or scaler.  */
  mrows = mxGetM(prhs[0]);
  ncols = mxGetN(prhs[0]);
  if( !mxIsDouble(prhs[0]) || mxIsComplex(prhs[0]) ||
    ( !(mrows == 32 && ncols == 1) && 
      !(mrows == 1 && ncols == 32))) 
    {
      mexErrMsgIdAndTxt( "MATLAB:MShaped:inputNotRealVector", "x is wrong.");
    }

  /*  Assign pointers to each input.  */
  x = mxGetPr(prhs[0]);
   


   
  /*  Create matrices for return arguments.  */
  plhs[0] = mxCreateDoubleMatrix((mwSize) 3, (mwSize) 16, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,x);


}

#else // MATLAB_MEX_FILE

#include "dJ_qBRight.hh"

namespace symbolic_expression
{
namespace basic
{

void dJ_qBRight_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
