/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:37:01 GMT-05:00
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
  p_output1[16]=2.;
  p_output1[17]=2.;
  p_output1[18]=2.;
  p_output1[19]=2.;
  p_output1[20]=2.;
  p_output1[21]=2.;
  p_output1[22]=2.;
  p_output1[23]=2.;
  p_output1[24]=2.;
  p_output1[25]=2.;
  p_output1[26]=2.;
  p_output1[27]=2.;
  p_output1[28]=2.;
  p_output1[29]=2.;
  p_output1[30]=2.;
  p_output1[31]=2.;
  p_output1[32]=2.;
  p_output1[33]=2.;
  p_output1[34]=2.;
  p_output1[35]=3.;
  p_output1[36]=3.;
  p_output1[37]=3.;
  p_output1[38]=3.;
  p_output1[39]=3.;
  p_output1[40]=3.;
  p_output1[41]=3.;
  p_output1[42]=3.;
  p_output1[43]=3.;
  p_output1[44]=3.;
  p_output1[45]=3.;
  p_output1[46]=3.;
  p_output1[47]=3.;
  p_output1[48]=3.;
  p_output1[49]=3.;
  p_output1[50]=3.;
  p_output1[51]=3.;
  p_output1[52]=3.;
  p_output1[53]=3.;
  p_output1[54]=5.;
  p_output1[55]=6.;
  p_output1[56]=7.;
  p_output1[57]=8.;
  p_output1[58]=10.;
  p_output1[59]=21.;
  p_output1[60]=22.;
  p_output1[61]=23.;
  p_output1[62]=24.;
  p_output1[63]=26.;
  p_output1[64]=33.;
  p_output1[65]=37.;
  p_output1[66]=38.;
  p_output1[67]=39.;
  p_output1[68]=40.;
  p_output1[69]=42.;
  p_output1[70]=4.;
  p_output1[71]=5.;
  p_output1[72]=6.;
  p_output1[73]=7.;
  p_output1[74]=8.;
  p_output1[75]=10.;
  p_output1[76]=20.;
  p_output1[77]=21.;
  p_output1[78]=22.;
  p_output1[79]=23.;
  p_output1[80]=24.;
  p_output1[81]=26.;
  p_output1[82]=34.;
  p_output1[83]=36.;
  p_output1[84]=37.;
  p_output1[85]=38.;
  p_output1[86]=39.;
  p_output1[87]=40.;
  p_output1[88]=42.;
  p_output1[89]=4.;
  p_output1[90]=5.;
  p_output1[91]=6.;
  p_output1[92]=7.;
  p_output1[93]=8.;
  p_output1[94]=10.;
  p_output1[95]=20.;
  p_output1[96]=21.;
  p_output1[97]=22.;
  p_output1[98]=23.;
  p_output1[99]=24.;
  p_output1[100]=26.;
  p_output1[101]=35.;
  p_output1[102]=36.;
  p_output1[103]=37.;
  p_output1[104]=38.;
  p_output1[105]=39.;
  p_output1[106]=40.;
  p_output1[107]=42.;
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
  plhs[0] = mxCreateDoubleMatrix((mwSize) 54, (mwSize) 2, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var);


}

#else // MATLAB_MEX_FILE

#include "Js_holConstrAcceleration_RightFourBarConnect.hh"

namespace symbolic_expression
{
namespace basic
{

void Js_holConstrAcceleration_RightFourBarConnect_raw(double *p_output1, const double *var)
{
  // Call Subroutines
  output1(p_output1, var);

}

}
}

#endif // MATLAB_MEX_FILE
