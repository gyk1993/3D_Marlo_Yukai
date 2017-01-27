/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:13 GMT-05:00
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
  t1 = x[11];
  t2 = x[3];
  t3 = Cos(t2);
  t4 = x[4];
  t5 = x[5];
  t6 = Cos(t4);
  t7 = Sin(t1);
  t8 = Sin(t2);
  t9 = Cos(t1);
  t10 = Cos(t5);
  t11 = Sin(t4);
  t12 = Sin(t5);
  t13 = t10*t8*t11;
  t14 = t3*t12;
  t15 = t13 + t14;
  p_output1[0]=1.;
  p_output1[4]=1.;
  p_output1[8]=1.;
  p_output1[10]=-0.1831*(t3*t6*t7 + (t10*t11*t3 - 1.*t12*t8)*t9);
  p_output1[11]=-0.1831*(t6*t7*t8 + t15*t9);
  p_output1[12]=-0.1831*(-1.*t6*t7 - 1.*t10*t11*t9);
  p_output1[13]=-0.1831*(-1.*t11*t7*t8 + t10*t6*t8*t9);
  p_output1[14]=-0.1831*(t11*t3*t7 - 1.*t10*t3*t6*t9);
  p_output1[15]=0.1831*t12*t6*t9;
  p_output1[16]=-0.1831*(t10*t3 - 1.*t11*t12*t8)*t9;
  p_output1[17]=-0.1831*(t11*t12*t3 + t10*t8)*t9;
  p_output1[33]=-0.1831*(-1.*t10*t6*t7 - 1.*t11*t9);
  p_output1[34]=-0.1831*(-1.*t15*t7 + t6*t8*t9);
  p_output1[35]=-0.1831*(-1.*t7*(-1.*t10*t11*t3 + t12*t8) - 1.*t3*t6*t9);
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

#include "J_qALeft.hh"

namespace symbolic_expression
{
namespace basic
{

void J_qALeft_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
