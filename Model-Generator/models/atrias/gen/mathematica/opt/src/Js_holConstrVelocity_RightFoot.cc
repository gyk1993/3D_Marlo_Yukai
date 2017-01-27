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
  p_output1[1]=1.;
  p_output1[2]=1.;
  p_output1[3]=1.;
  p_output1[4]=1.;
  p_output1[5]=1.;
  p_output1[6]=1.;
  p_output1[7]=1.;
  p_output1[8]=1.;
  p_output1[9]=1.;
  p_output1[10]=1.;
  p_output1[11]=2.;
  p_output1[12]=2.;
  p_output1[13]=2.;
  p_output1[14]=2.;
  p_output1[15]=2.;
  p_output1[16]=2.;
  p_output1[17]=2.;
  p_output1[18]=2.;
  p_output1[19]=2.;
  p_output1[20]=2.;
  p_output1[21]=2.;
  p_output1[22]=2.;
  p_output1[23]=2.;
  p_output1[24]=3.;
  p_output1[25]=3.;
  p_output1[26]=3.;
  p_output1[27]=3.;
  p_output1[28]=3.;
  p_output1[29]=3.;
  p_output1[30]=3.;
  p_output1[31]=3.;
  p_output1[32]=3.;
  p_output1[33]=3.;
  p_output1[34]=3.;
  p_output1[35]=3.;
  p_output1[36]=3.;
  p_output1[37]=5.;
  p_output1[38]=6.;
  p_output1[39]=7.;
  p_output1[40]=9.;
  p_output1[41]=11.;
  p_output1[42]=17.;
  p_output1[43]=21.;
  p_output1[44]=22.;
  p_output1[45]=23.;
  p_output1[46]=25.;
  p_output1[47]=27.;
  p_output1[48]=4.;
  p_output1[49]=5.;
  p_output1[50]=6.;
  p_output1[51]=7.;
  p_output1[52]=9.;
  p_output1[53]=11.;
  p_output1[54]=18.;
  p_output1[55]=20.;
  p_output1[56]=21.;
  p_output1[57]=22.;
  p_output1[58]=23.;
  p_output1[59]=25.;
  p_output1[60]=27.;
  p_output1[61]=4.;
  p_output1[62]=5.;
  p_output1[63]=6.;
  p_output1[64]=7.;
  p_output1[65]=9.;
  p_output1[66]=11.;
  p_output1[67]=19.;
  p_output1[68]=20.;
  p_output1[69]=21.;
  p_output1[70]=22.;
  p_output1[71]=23.;
  p_output1[72]=25.;
  p_output1[73]=27.;
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
  plhs[0] = mxCreateDoubleMatrix((mwSize) 37, (mwSize) 2, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var);


}

#else // MATLAB_MEX_FILE

#include "Js_holConstrVelocity_RightFoot.hh"

namespace symbolic_expression
{
namespace basic
{

void Js_holConstrVelocity_RightFoot_raw(double *p_output1, const double *var)
{
  // Call Subroutines
  output1(p_output1, var);

}

}
}

#endif // MATLAB_MEX_FILE
