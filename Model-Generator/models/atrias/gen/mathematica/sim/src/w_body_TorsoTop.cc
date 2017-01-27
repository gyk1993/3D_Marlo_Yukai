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
  t1 = x[4];
  t2 = Sin(t1);
  t3 = x[5];
  t4 = Cos(t1);
  t5 = Cos(t3);
  t6 = x[3];
  t7 = Sin(t6);
  t8 = Sin(t3);
  t9 = x[19];
  t10 = x[20];
  t11 = x[21];
  t12 = Cos(t6);
  p_output1[0]=t2*(-1.*t11*t4*t5 + t10*t2*t8) - 1.*t4*t7*(-1.*t11*t2*t5*t7 - 1.*t11*t12*t8 - 1.*t10*t4*t7*t8 - 1.*t5*t7*t9 - 1.*t12*t2*t8*t9) + t12*t4*(t11*t12*t2*t5 + t10*t12*t4*t8 - 1.*t11*t7*t8 + t12*t5*t9 - 1.*t2*t7*t8*t9);
  p_output1[1]=t10*Power(t4,2)*t5 + (t2*t5*t7 + t12*t8)*(t10*t2*t7 - 1.*t12*t4*t9) + (-1.*t12*t2*t5 + t7*t8)*(-1.*t10*t12*t2 - 1.*t4*t7*t9);
  p_output1[2]=-1.*t4*t8*(-1.*t10*t2*t5 - 1.*t11*t4*t8) + (t5*t7 + t12*t2*t8)*(-1.*t10*t12*t4*t5 + t11*t5*t7 + t11*t12*t2*t8 + t2*t5*t7*t9 + t12*t8*t9) + (t12*t5 - 1.*t2*t7*t8)*(t11*t12*t5 + t10*t4*t5*t7 - 1.*t11*t2*t7*t8 + t12*t2*t5*t9 - 1.*t7*t8*t9);
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
  plhs[0] = mxCreateDoubleMatrix((mwSize) 3, (mwSize) 1, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,x);


}

#else // MATLAB_MEX_FILE

#include "w_body_TorsoTop.hh"

namespace symbolic_expression
{
namespace basic
{

void w_body_TorsoTop_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
