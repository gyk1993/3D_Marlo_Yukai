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
  t1 = var[4];
  t2 = Cos(t1);
  t3 = var[3];
  t4 = Sin(t1);
  t5 = var[20];
  t6 = Cos(t3);
  t7 = var[19];
  t8 = Sin(t3);
  p_output1[0]=-0.58*t4*t5;
  p_output1[1]=1.;
  p_output1[2]=0.58*t2;
  p_output1[3]=0.58*t4*t5*t6 + 0.58*t2*t7*t8;
  p_output1[4]=0.58*t4*t6*t7 + 0.58*t2*t5*t8;
  p_output1[5]=1.;
  p_output1[6]=-0.58*t2*t6;
  p_output1[7]=0.58*t4*t8;
  p_output1[8]=-0.58*t2*t6*t7 + 0.58*t4*t5*t8;
  p_output1[9]=-0.58*t2*t5*t6 + 0.58*t4*t7*t8;
  p_output1[10]=1.;
  p_output1[11]=-0.58*t2*t8;
  p_output1[12]=-0.58*t4*t6;
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
    ( !(mrows == 32 && ncols == 1) && 
      !(mrows == 1 && ncols == 32))) 
    {
      mexErrMsgIdAndTxt( "MATLAB:MShaped:inputNotRealVector", "var is wrong.");
    }

  /*  Assign pointers to each input.  */
  var = mxGetPr(prhs[0]);
   


   
  /*  Create matrices for return arguments.  */
  plhs[0] = mxCreateDoubleMatrix((mwSize) 13, (mwSize) 1, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var);


}

#else // MATLAB_MEX_FILE

#include "J_holConstrVelocity_TorsoTop.hh"

namespace symbolic_expression
{
namespace basic
{

void J_holConstrVelocity_TorsoTop_raw(double *p_output1, const double *var)
{
  // Call Subroutines
  output1(p_output1, var);

}

}
}

#endif // MATLAB_MEX_FILE
