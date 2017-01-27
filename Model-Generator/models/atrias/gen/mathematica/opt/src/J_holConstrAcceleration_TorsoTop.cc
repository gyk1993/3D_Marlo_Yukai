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
  double t11;
  double t12;
  double t13;
  double t14;
  double t15;
  double t16;
  double t17;
  double t18;
  double t19;
  double t20;
  double t21;
  double t22;
  t1 = var[4];
  t2 = Sin(t1);
  t3 = var[20];
  t4 = Cos(t1);
  t5 = var[3];
  t6 = var[19];
  t7 = Cos(t5);
  t8 = Sin(t5);
  t9 = var[36];
  t10 = -0.58*t8*t2*t6;
  t11 = 0.58*t7*t4*t3;
  t12 = t10 + t11;
  t13 = 0.58*t7*t4*t6;
  t14 = -0.58*t8*t2*t3;
  t15 = t13 + t14;
  t16 = var[35];
  t17 = 0.58*t7*t2*t6;
  t18 = 0.58*t4*t8*t3;
  t19 = t17 + t18;
  t20 = 0.58*t4*t8*t6;
  t21 = 0.58*t7*t2*t3;
  t22 = t20 + t21;
  p_output1[0]=-0.58*Power(t3,2)*t4 - 0.58*t2*t9;
  p_output1[1]=-1.16*t2*t3;
  p_output1[2]=1.;
  p_output1[3]=0.58*t4;
  p_output1[4]=t12*t3 + t15*t6 + 0.58*t16*t4*t8 + 0.58*t2*t7*t9;
  p_output1[5]=t15*t3 + t12*t6 + 0.58*t16*t2*t7 + 0.58*t4*t8*t9;
  p_output1[6]=1.16*t2*t3*t7 + 1.16*t4*t6*t8;
  p_output1[7]=1.16*t2*t6*t7 + 1.16*t3*t4*t8;
  p_output1[8]=1.;
  p_output1[9]=-0.58*t4*t7;
  p_output1[10]=0.58*t2*t8;
  p_output1[11]=t19*t3 + t22*t6 - 0.58*t16*t4*t7 + 0.58*t2*t8*t9;
  p_output1[12]=t22*t3 + t19*t6 + 0.58*t16*t2*t8 - 0.58*t4*t7*t9;
  p_output1[13]=-1.16*t4*t6*t7 + 1.16*t2*t3*t8;
  p_output1[14]=-1.16*t3*t4*t7 + 1.16*t2*t6*t8;
  p_output1[15]=1.;
  p_output1[16]=-0.58*t4*t8;
  p_output1[17]=-0.58*t2*t7;
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
  plhs[0] = mxCreateDoubleMatrix((mwSize) 18, (mwSize) 1, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var);


}

#else // MATLAB_MEX_FILE

#include "J_holConstrAcceleration_TorsoTop.hh"

namespace symbolic_expression
{
namespace basic
{

void J_holConstrAcceleration_TorsoTop_raw(double *p_output1, const double *var)
{
  // Call Subroutines
  output1(p_output1, var);

}

}
}

#endif // MATLAB_MEX_FILE
