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
  t1 = x[11];
  t2 = x[4];
  t3 = Cos(t2);
  t4 = Sin(t1);
  t5 = Cos(t1);
  t6 = x[5];
  t7 = Cos(t6);
  t8 = x[3];
  t9 = Sin(t8);
  t10 = Sin(t2);
  t11 = Cos(t8);
  t12 = Sin(t6);
  p_output1[0]=0. - 0.1831*(-1.*t10*t4 + t3*t5*t7) + x[0];
  p_output1[1]=0. - 0.1831*(t3*t4*t9 + t5*(t11*t12 + t10*t7*t9)) + x[1];
  p_output1[2]=0. - 0.1831*(-1.*t11*t3*t4 + t5*(-1.*t10*t11*t7 + t12*t9)) + x[2];
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

#include "p_qALeft.hh"

namespace symbolic_expression
{
namespace basic
{

void p_qALeft_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
