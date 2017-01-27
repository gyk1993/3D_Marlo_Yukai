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
  double _NotUsed;
  NULL;
  p_output1[0]=1.;
  p_output1[1]=2.;
  p_output1[2]=3.;
  p_output1[3]=4.;
  p_output1[4]=4.;
  p_output1[5]=4.;
  p_output1[6]=4.;
  p_output1[7]=5.;
  p_output1[8]=5.;
  p_output1[9]=5.;
  p_output1[10]=5.;
  p_output1[11]=5.;
  p_output1[12]=17.;
  p_output1[13]=18.;
  p_output1[14]=19.;
  p_output1[15]=4.;
  p_output1[16]=5.;
  p_output1[17]=18.;
  p_output1[18]=19.;
  p_output1[19]=4.;
  p_output1[20]=5.;
  p_output1[21]=17.;
  p_output1[22]=18.;
  p_output1[23]=19.;
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
    ( !(mrows == 1 && ncols == 1) && 
      !(mrows == 1 && ncols == 1))) 
    {
      mexErrMsgIdAndTxt( "MATLAB:MShaped:inputNotRealVector", "var is wrong.");
    }

  /*  Assign pointers to each input.  */
  var = mxGetPr(prhs[0]);
   


   
  /*  Create matrices for return arguments.  */
  plhs[0] = mxCreateDoubleMatrix((mwSize) 12, (mwSize) 2, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var);


}

#else // MATLAB_MEX_FILE

#include "Js_holConstrImpactForce_TorsoTop.hh"

namespace symbolic_expression
{
namespace basic
{

void Js_holConstrImpactForce_TorsoTop_raw(double *p_output1, const double *var)
{
  // Call Subroutines
  output1(p_output1, var);

}

}
}

#endif // MATLAB_MEX_FILE
