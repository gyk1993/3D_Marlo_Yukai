/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:17 GMT-05:00
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
  t1 = x[3];
  t2 = Sin(t1);
  t3 = x[4];
  t4 = x[5];
  t5 = Cos(t1);
  t6 = Cos(t3);
  t7 = Cos(t4);
  t8 = Sin(t3);
  t9 = Sin(t4);
  t10 = t7*t2*t8;
  t11 = t5*t9;
  t12 = t10 + t11;
  t13 = t5*t7;
  t14 = -1.*t2*t8*t9;
  t15 = t13 + t14;
  t16 = Power(t6,2);
  t17 = -1.*t5*t7*t8;
  t18 = t2*t9;
  t19 = t17 + t18;
  t20 = t7*t2;
  t21 = t5*t8*t9;
  t22 = t20 + t21;
  t23 = t5*t7*t8;
  t24 = -1.*t2*t9;
  t25 = t23 + t24;
  p_output1[9]=t15*t5*t6 - 1.*t2*t6*(-1.*t2*t7 - 1.*t5*t8*t9);
  p_output1[10]=-1.*t19*t2*t6 - 1.*t12*t5*t6;
  p_output1[11]=t12*t22 + t15*t25;
  p_output1[12]=t16*Power(t2,2)*t9 + t16*Power(t5,2)*t9 + Power(t8,2)*t9;
  p_output1[13]=t16*t7 + t12*t2*t8 - 1.*t19*t5*t8;
  p_output1[14]=t15*t2*t6*t7 - 1.*t22*t5*t6*t7 + t6*t7*t8*t9;
  p_output1[15]=t25*t5*t6 - 1.*t6*t7*t8 - 1.*t2*t6*(-1.*t2*t7*t8 - 1.*t5*t9);
  p_output1[17]=Power(t15,2) + Power(t22,2) + t16*Power(t9,2);
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

#include "Jw_body_TorsoTop.hh"

namespace symbolic_expression
{
namespace basic
{

void Jw_body_TorsoTop_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
