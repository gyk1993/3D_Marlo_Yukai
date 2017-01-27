/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:22 GMT-05:00
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
  double t35;
  double t36;
  double t37;
  double t38;
  double t39;
  double t40;
  double t41;
  double t42;
  double t43;
  double t44;
  double t45;
  double t46;
  double t47;
  double t48;
  double t49;
  double t50;
  double t51;
  double t52;
  double t53;
  double t54;
  double t55;
  double t56;
  double t57;
  double t58;
  double t59;
  t1 = x[11];
  t2 = x[4];
  t3 = Cos(t2);
  t4 = x[5];
  t5 = Cos(t4);
  t6 = Sin(t1);
  t7 = Cos(t1);
  t8 = Sin(t2);
  t9 = x[12];
  t10 = x[14];
  t11 = Cos(t9);
  t12 = t3*t5*t6;
  t13 = t7*t8;
  t14 = t12 + t13;
  t15 = Sin(t9);
  t16 = Sin(t4);
  t17 = Sin(t10);
  t18 = t15*t14;
  t19 = -1.*t11*t3*t16;
  t20 = t18 + t19;
  t21 = Cos(t10);
  t22 = t11*t14;
  t23 = t3*t15*t16;
  t24 = t22 + t23;
  t25 = x[3];
  t26 = Sin(t25);
  t27 = -1.*t21;
  t28 = 1. + t27;
  t29 = Cos(t25);
  t30 = t5*t26*t8;
  t31 = t29*t16;
  t32 = t30 + t31;
  t33 = t29*t5;
  t34 = -1.*t26*t8*t16;
  t35 = t33 + t34;
  t36 = -1.*t7*t3*t26;
  t37 = t6*t32;
  t38 = t36 + t37;
  t39 = -1.*t15*t35;
  t40 = t11*t38;
  t41 = t39 + t40;
  t42 = t11*t35;
  t43 = t15*t38;
  t44 = t42 + t43;
  t45 = -1.*t29*t5*t8;
  t46 = t26*t16;
  t47 = t45 + t46;
  t48 = t5*t26;
  t49 = t29*t8*t16;
  t50 = t48 + t49;
  t51 = t7*t29*t3;
  t52 = t6*t47;
  t53 = t51 + t52;
  t54 = -1.*t15*t50;
  t55 = t11*t53;
  t56 = t54 + t55;
  t57 = t11*t50;
  t58 = t15*t53;
  t59 = t57 + t58;
  p_output1[0]=0. + 0.4*t17*t20 + 0.9*(-1.*t17*t20 + t21*t24) + 0.4*t24*t28 - 0.1831*(t3*t5*t7 - 1.*t6*t8) + x[0];
  p_output1[1]=0. + 0.4*t28*t41 + 0.4*t17*t44 + 0.9*(t21*t41 - 1.*t17*t44) - 0.1831*(t26*t3*t6 + t32*t7) + x[1];
  p_output1[2]=0. + 0.4*t28*t56 + 0.4*t17*t59 + 0.9*(t21*t56 - 1.*t17*t59) - 0.1831*(-1.*t29*t3*t6 + t47*t7) + x[2];
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

#include "p_LeftFourBarConnect.hh"

namespace symbolic_expression
{
namespace basic
{

void p_LeftFourBarConnect_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
