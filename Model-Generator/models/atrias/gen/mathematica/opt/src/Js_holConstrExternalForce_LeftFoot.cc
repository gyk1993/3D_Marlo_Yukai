/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:37:00 GMT-05:00
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
  p_output1[29]=12.;
  p_output1[30]=12.;
  p_output1[31]=12.;
  p_output1[32]=12.;
  p_output1[33]=12.;
  p_output1[34]=12.;
  p_output1[35]=12.;
  p_output1[36]=12.;
  p_output1[37]=12.;
  p_output1[38]=14.;
  p_output1[39]=14.;
  p_output1[40]=14.;
  p_output1[41]=14.;
  p_output1[42]=14.;
  p_output1[43]=14.;
  p_output1[44]=14.;
  p_output1[45]=14.;
  p_output1[46]=14.;
  p_output1[47]=16.;
  p_output1[48]=16.;
  p_output1[49]=16.;
  p_output1[50]=16.;
  p_output1[51]=16.;
  p_output1[52]=16.;
  p_output1[53]=16.;
  p_output1[54]=16.;
  p_output1[55]=16.;
  p_output1[56]=17.;
  p_output1[57]=18.;
  p_output1[58]=19.;
  p_output1[59]=4.;
  p_output1[60]=5.;
  p_output1[61]=6.;
  p_output1[62]=12.;
  p_output1[63]=14.;
  p_output1[64]=16.;
  p_output1[65]=18.;
  p_output1[66]=19.;
  p_output1[67]=4.;
  p_output1[68]=5.;
  p_output1[69]=6.;
  p_output1[70]=12.;
  p_output1[71]=14.;
  p_output1[72]=16.;
  p_output1[73]=17.;
  p_output1[74]=18.;
  p_output1[75]=19.;
  p_output1[76]=4.;
  p_output1[77]=5.;
  p_output1[78]=6.;
  p_output1[79]=12.;
  p_output1[80]=14.;
  p_output1[81]=16.;
  p_output1[82]=17.;
  p_output1[83]=18.;
  p_output1[84]=19.;
  p_output1[85]=4.;
  p_output1[86]=5.;
  p_output1[87]=6.;
  p_output1[88]=12.;
  p_output1[89]=14.;
  p_output1[90]=16.;
  p_output1[91]=17.;
  p_output1[92]=18.;
  p_output1[93]=19.;
  p_output1[94]=4.;
  p_output1[95]=5.;
  p_output1[96]=6.;
  p_output1[97]=12.;
  p_output1[98]=14.;
  p_output1[99]=16.;
  p_output1[100]=17.;
  p_output1[101]=18.;
  p_output1[102]=19.;
  p_output1[103]=4.;
  p_output1[104]=5.;
  p_output1[105]=6.;
  p_output1[106]=12.;
  p_output1[107]=14.;
  p_output1[108]=16.;
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

#include "Js_holConstrExternalForce_LeftFoot.hh"

namespace symbolic_expression
{
namespace basic
{

void Js_holConstrExternalForce_LeftFoot_raw(double *p_output1, const double *var)
{
  // Call Subroutines
  output1(p_output1, var);

}

}
}

#endif // MATLAB_MEX_FILE
