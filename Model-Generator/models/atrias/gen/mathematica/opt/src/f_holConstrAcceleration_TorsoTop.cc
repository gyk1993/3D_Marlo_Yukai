/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:36:58 GMT-05:00
 */
#include "math2mat.hpp"

/*
 * Sub functions
 */
static void output1(double *p_output1,const double *var)
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
  t1 = var[4];
  t2 = var[20];
  t3 = Sin(t1);
  t4 = Cos(t1);
  t5 = var[3];
  t6 = var[19];
  t7 = Sin(t5);
  t8 = Cos(t5);
  t9 = var[36];
  t10 = var[35];
  p_output1[0]=-0.58*Power(t2,2)*t3 + 0.58*t4*t9 + var[32];
  p_output1[1]=-0.58*t10*t4*t8 + t6*(0.58*t4*t6*t7 + 0.58*t2*t3*t8) + t2*(0.58*t2*t4*t7 + 0.58*t3*t6*t8) + 0.58*t3*t7*t9 + var[33];
  p_output1[2]=-0.58*t10*t4*t7 + t2*(0.58*t3*t6*t7 - 0.58*t2*t4*t8) + t6*(0.58*t2*t3*t7 - 0.58*t4*t6*t8) - 0.58*t3*t8*t9 + var[34];
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

  double *var;
  double *p_output1;

  /*  Check for proper number of arguments.  */ 
  if( nrhs != 1)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:invalidNumInputs", "One input(s) required (var).");
    }
  else if( nlhs > 1)
    {
      mexErrMsgIdAndTxt("MATLAB:MShaped:maxlhs", "Too many output arguments.");
    }

  /*  The input must be a noncomplex double vector or scaler.  */
  mrows = mxGetM(prhs[0]);
  ncols = mxGetN(prhs[0]);
  if( !mxIsDouble(prhs[0]) || mxIsComplex(prhs[0]) ||
    ( !(mrows == 48 && ncols == 1) && 
      !(mrows == 1 && ncols == 48))) 
    {
      mexErrMsgIdAndTxt( "MATLAB:MShaped:inputNotRealVector", "var is wrong.");
    }

  /*  Assign pointers to each input.  */
  var = mxGetPr(prhs[0]);
   


   
  /*  Create matrices for return arguments.  */
  plhs[0] = mxCreateDoubleMatrix((mwSize) 3, (mwSize) 1, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var);


}

#else // MATLAB_MEX_FILE

#include "f_holConstrAcceleration_TorsoTop.hh"

namespace symbolic_expression
{
namespace basic
{

void f_holConstrAcceleration_TorsoTop_raw(double *p_output1, const double *var)
{
  // Call Subroutines
  output1(p_output1, var);

}

}
}

#endif // MATLAB_MEX_FILE
