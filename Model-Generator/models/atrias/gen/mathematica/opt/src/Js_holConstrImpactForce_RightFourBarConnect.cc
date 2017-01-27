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
  p_output1[1]=2.;
  p_output1[2]=3.;
  p_output1[3]=4.;
  p_output1[4]=4.;
  p_output1[5]=4.;
  p_output1[6]=4.;
  p_output1[7]=4.;
  p_output1[8]=4.;
  p_output1[9]=4.;
  p_output1[10]=4.;
  p_output1[11]=5.;
  p_output1[12]=5.;
  p_output1[13]=5.;
  p_output1[14]=5.;
  p_output1[15]=5.;
  p_output1[16]=5.;
  p_output1[17]=5.;
  p_output1[18]=5.;
  p_output1[19]=5.;
  p_output1[20]=6.;
  p_output1[21]=6.;
  p_output1[22]=6.;
  p_output1[23]=6.;
  p_output1[24]=6.;
  p_output1[25]=6.;
  p_output1[26]=6.;
  p_output1[27]=6.;
  p_output1[28]=6.;
  p_output1[29]=7.;
  p_output1[30]=7.;
  p_output1[31]=7.;
  p_output1[32]=7.;
  p_output1[33]=7.;
  p_output1[34]=7.;
  p_output1[35]=7.;
  p_output1[36]=7.;
  p_output1[37]=7.;
  p_output1[38]=8.;
  p_output1[39]=8.;
  p_output1[40]=8.;
  p_output1[41]=8.;
  p_output1[42]=8.;
  p_output1[43]=8.;
  p_output1[44]=8.;
  p_output1[45]=8.;
  p_output1[46]=8.;
  p_output1[47]=10.;
  p_output1[48]=10.;
  p_output1[49]=10.;
  p_output1[50]=10.;
  p_output1[51]=10.;
  p_output1[52]=10.;
  p_output1[53]=10.;
  p_output1[54]=10.;
  p_output1[55]=10.;
  p_output1[56]=17.;
  p_output1[57]=18.;
  p_output1[58]=19.;
  p_output1[59]=4.;
  p_output1[60]=5.;
  p_output1[61]=6.;
  p_output1[62]=7.;
  p_output1[63]=8.;
  p_output1[64]=10.;
  p_output1[65]=18.;
  p_output1[66]=19.;
  p_output1[67]=4.;
  p_output1[68]=5.;
  p_output1[69]=6.;
  p_output1[70]=7.;
  p_output1[71]=8.;
  p_output1[72]=10.;
  p_output1[73]=17.;
  p_output1[74]=18.;
  p_output1[75]=19.;
  p_output1[76]=4.;
  p_output1[77]=5.;
  p_output1[78]=6.;
  p_output1[79]=7.;
  p_output1[80]=8.;
  p_output1[81]=10.;
  p_output1[82]=17.;
  p_output1[83]=18.;
  p_output1[84]=19.;
  p_output1[85]=4.;
  p_output1[86]=5.;
  p_output1[87]=6.;
  p_output1[88]=7.;
  p_output1[89]=8.;
  p_output1[90]=10.;
  p_output1[91]=17.;
  p_output1[92]=18.;
  p_output1[93]=19.;
  p_output1[94]=4.;
  p_output1[95]=5.;
  p_output1[96]=6.;
  p_output1[97]=7.;
  p_output1[98]=8.;
  p_output1[99]=10.;
  p_output1[100]=17.;
  p_output1[101]=18.;
  p_output1[102]=19.;
  p_output1[103]=4.;
  p_output1[104]=5.;
  p_output1[105]=6.;
  p_output1[106]=7.;
  p_output1[107]=8.;
  p_output1[108]=10.;
  p_output1[109]=17.;
  p_output1[110]=18.;
  p_output1[111]=19.;
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
  plhs[0] = mxCreateDoubleMatrix((mwSize) 56, (mwSize) 2, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var);


}

#else // MATLAB_MEX_FILE

#include "Js_holConstrImpactForce_RightFourBarConnect.hh"

namespace symbolic_expression
{
namespace basic
{

void Js_holConstrImpactForce_RightFourBarConnect_raw(double *p_output1, const double *var)
{
  // Call Subroutines
  output1(p_output1, var);

}

}
}

#endif // MATLAB_MEX_FILE
