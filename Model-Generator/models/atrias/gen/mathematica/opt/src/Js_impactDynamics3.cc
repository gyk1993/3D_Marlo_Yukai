/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:36:51 GMT-05:00
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
  p_output1[11]=1.;
  p_output1[12]=1.;
  p_output1[13]=1.;
  p_output1[14]=1.;
  p_output1[15]=1.;
  p_output1[16]=1.;
  p_output1[17]=1.;
  p_output1[18]=1.;
  p_output1[19]=1.;
  p_output1[20]=1.;
  p_output1[21]=1.;
  p_output1[22]=1.;
  p_output1[23]=1.;
  p_output1[24]=1.;
  p_output1[25]=1.;
  p_output1[26]=1.;
  p_output1[27]=1.;
  p_output1[28]=1.;
  p_output1[29]=1.;
  p_output1[30]=1.;
  p_output1[31]=1.;
  p_output1[32]=1.;
  p_output1[33]=1.;
  p_output1[34]=1.;
  p_output1[35]=1.;
  p_output1[36]=1.;
  p_output1[37]=1.;
  p_output1[38]=1.;
  p_output1[39]=1.;
  p_output1[40]=1.;
  p_output1[41]=1.;
  p_output1[42]=1.;
  p_output1[43]=1.;
  p_output1[44]=1.;
  p_output1[45]=4.;
  p_output1[46]=5.;
  p_output1[47]=6.;
  p_output1[48]=7.;
  p_output1[49]=8.;
  p_output1[50]=9.;
  p_output1[51]=10.;
  p_output1[52]=11.;
  p_output1[53]=12.;
  p_output1[54]=13.;
  p_output1[55]=14.;
  p_output1[56]=15.;
  p_output1[57]=16.;
  p_output1[58]=17.;
  p_output1[59]=18.;
  p_output1[60]=19.;
  p_output1[61]=20.;
  p_output1[62]=21.;
  p_output1[63]=22.;
  p_output1[64]=23.;
  p_output1[65]=24.;
  p_output1[66]=25.;
  p_output1[67]=26.;
  p_output1[68]=27.;
  p_output1[69]=28.;
  p_output1[70]=29.;
  p_output1[71]=30.;
  p_output1[72]=31.;
  p_output1[73]=32.;
  p_output1[74]=33.;
  p_output1[75]=34.;
  p_output1[76]=35.;
  p_output1[77]=36.;
  p_output1[78]=37.;
  p_output1[79]=38.;
  p_output1[80]=39.;
  p_output1[81]=40.;
  p_output1[82]=41.;
  p_output1[83]=42.;
  p_output1[84]=43.;
  p_output1[85]=44.;
  p_output1[86]=45.;
  p_output1[87]=46.;
  p_output1[88]=47.;
  p_output1[89]=48.;
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
  plhs[0] = mxCreateDoubleMatrix((mwSize) 45, (mwSize) 2, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var);


}

#else // MATLAB_MEX_FILE

#include "Js_impactDynamics3.hh"

namespace symbolic_expression
{
namespace basic
{

void Js_impactDynamics3_raw(double *p_output1, const double *var)
{
  // Call Subroutines
  output1(p_output1, var);

}

}
}

#endif // MATLAB_MEX_FILE
