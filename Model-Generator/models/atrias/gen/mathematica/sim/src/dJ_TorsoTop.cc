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
  t1 = x[3];
  t2 = x[4];
  t3 = Cos(t1);
  t4 = Cos(t2);
  t5 = x[19];
  t6 = Sin(t1);
  t7 = Sin(t2);
  t8 = x[20];
  p_output1[10]=0.58*t4*t5*t6 + 0.58*t3*t7*t8;
  p_output1[11]=-0.58*t3*t4*t5 + 0.58*t6*t7*t8;
  p_output1[12]=-0.58*t7*t8;
  p_output1[13]=0.58*t3*t5*t7 + 0.58*t4*t6*t8;
  p_output1[14]=0.58*t5*t6*t7 - 0.58*t3*t4*t8;
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

#include "dJ_TorsoTop.hh"

namespace symbolic_expression
{
namespace basic
{

void dJ_TorsoTop_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
