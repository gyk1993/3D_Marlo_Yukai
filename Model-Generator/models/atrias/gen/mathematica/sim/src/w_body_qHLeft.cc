/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:12 GMT-05:00
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
  double t23;
  double t24;
  double t25;
  double t26;
  double t27;
  double t28;
  double t29;
  double t30;
  double t31;
  double t32;
  double t33;
  double t34;
  t1 = x[11];
  t2 = x[4];
  t3 = Sin(t2);
  t4 = x[5];
  t5 = Cos(t2);
  t6 = Cos(t4);
  t7 = Cos(t1);
  t8 = Sin(t1);
  t9 = x[3];
  t10 = Sin(t9);
  t11 = Sin(t4);
  t12 = Cos(t9);
  t13 = x[19];
  t14 = x[20];
  t15 = x[21];
  t16 = x[27];
  t17 = -1.*t12*t6*t3;
  t18 = t10*t11;
  t19 = t17 + t18;
  t20 = t6*t10*t3;
  t21 = t12*t11;
  t22 = t20 + t21;
  t23 = t6*t10*t3*t13;
  t24 = t12*t11*t13;
  t25 = -1.*t12*t5*t6*t14;
  t26 = t6*t10*t15;
  t27 = t12*t3*t11*t15;
  t28 = t23 + t24 + t25 + t26 + t27;
  t29 = t12*t6*t3*t13;
  t30 = -1.*t10*t11*t13;
  t31 = t5*t6*t10*t14;
  t32 = t12*t6*t15;
  t33 = -1.*t10*t3*t11*t15;
  t34 = t29 + t30 + t31 + t32 + t33;
  p_output1[0]=(-1.*t10*t11*t15 - 1.*t10*t11*t13*t3 + t11*t12*t14*t5 + t12*t13*t6 + t12*t15*t3*t6)*(t12*t5*t7 + t19*t8) + (-1.*t11*t12*t15 - 1.*t11*t12*t13*t3 - 1.*t10*t11*t14*t5 - 1.*t10*t13*t6 - 1.*t10*t15*t3*t6)*(-1.*t10*t5*t7 + t22*t8) + (t11*t14*t3 - 1.*t15*t5*t6)*(t3*t7 + t5*t6*t8);
  p_output1[1]=(t22*t7 + t10*t5*t8)*(t16*t22*t7 + t10*t14*t3*t7 - 1.*t12*t13*t5*t7 + t34*t8 + t10*t16*t5*t8) + (t19*t7 - 1.*t12*t5*t8)*(t16*t19*t7 - 1.*t12*t14*t3*t7 - 1.*t10*t13*t5*t7 + t28*t8 - 1.*t12*t16*t5*t8) + (t5*t6*t7 - 1.*t3*t8)*(t14*t5*t7 + t16*t5*t6*t7 - 1.*t16*t3*t8 - 1.*t11*t15*t5*t8 - 1.*t14*t3*t6*t8);
  p_output1[2]=(t11*t12*t3 + t10*t6)*(t28*t7 - 1.*t12*t16*t5*t7 - 1.*t16*t19*t8 + t12*t14*t3*t8 + t10*t13*t5*t8) + (-1.*t10*t11*t3 + t12*t6)*(t34*t7 + t10*t16*t5*t7 - 1.*t16*t22*t8 - 1.*t10*t14*t3*t8 + t12*t13*t5*t8) - 1.*t11*t5*(-1.*t16*t3*t7 - 1.*t11*t15*t5*t7 - 1.*t14*t3*t6*t7 - 1.*t14*t5*t8 - 1.*t16*t5*t6*t8);
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
  plhs[0] = mxCreateDoubleMatrix((mwSize) 3, (mwSize) 1, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,x);


}

#else // MATLAB_MEX_FILE

#include "w_body_qHLeft.hh"

namespace symbolic_expression
{
namespace basic
{

void w_body_qHLeft_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
