/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:15 GMT-05:00
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
  t1 = x[11];
  t2 = x[4];
  t3 = Cos(t2);
  t4 = Sin(t1);
  t5 = Cos(t1);
  t6 = x[5];
  t7 = Cos(t6);
  t8 = x[3];
  t9 = Sin(t8);
  t10 = Sin(t2);
  t11 = Cos(t8);
  t12 = Sin(t6);
  t13 = x[12];
  t14 = x[14];
  t15 = Cos(t13);
  t16 = t3*t7*t4;
  t17 = t5*t10;
  t18 = t16 + t17;
  t19 = Sin(t13);
  t20 = Sin(t14);
  t21 = t7*t9*t10;
  t22 = t11*t12;
  t23 = t21 + t22;
  t24 = Cos(t14);
  t25 = t11*t7;
  t26 = -1.*t9*t10*t12;
  t27 = t25 + t26;
  t28 = -1.*t5*t3*t9;
  t29 = t4*t23;
  t30 = t28 + t29;
  t31 = -1.*t11*t7*t10;
  t32 = t9*t12;
  t33 = t31 + t32;
  t34 = t7*t9;
  t35 = t11*t10*t12;
  t36 = t34 + t35;
  t37 = t5*t11*t3;
  t38 = t4*t33;
  t39 = t37 + t38;
  t40 = t19*t18;
  t41 = -1.*t15*t3*t12;
  t42 = t40 + t41;
  t43 = t15*t18;
  t44 = t3*t19*t12;
  t45 = t43 + t44;
  t46 = -1.*t19*t27;
  t47 = t15*t30;
  t48 = t46 + t47;
  t49 = t15*t27;
  t50 = t19*t30;
  t51 = t49 + t50;
  t52 = -1.*t19*t36;
  t53 = t15*t39;
  t54 = t52 + t53;
  t55 = t15*t36;
  t56 = t19*t39;
  t57 = t55 + t56;
  p_output1[0]=-1.*t10*t4 + t3*t5*t7;
  p_output1[1]=t23*t5 + t3*t4*t9;
  p_output1[2]=-1.*t11*t3*t4 + t33*t5;
  p_output1[3]=t24*t42 + t20*t45;
  p_output1[4]=t20*t48 + t24*t51;
  p_output1[5]=t20*t54 + t24*t57;
  p_output1[6]=-1.*t20*t42 + t24*t45;
  p_output1[7]=t24*t48 - 1.*t20*t51;
  p_output1[8]=t24*t54 - 1.*t20*t57;
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
  plhs[0] = mxCreateDoubleMatrix((mwSize) 3, (mwSize) 3, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,x);


}

#else // MATLAB_MEX_FILE

#include "R_fourBarALeft.hh"

namespace symbolic_expression
{
namespace basic
{

void R_fourBarALeft_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
