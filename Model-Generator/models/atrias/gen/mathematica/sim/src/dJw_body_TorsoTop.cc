/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:17 GMT-05:00
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
  double t60;
  double t61;
  double t62;
  double t63;
  double t64;
  double t65;
  double t66;
  double t67;
  double t68;
  t1 = x[3];
  t2 = Cos(t1);
  t3 = x[4];
  t4 = x[5];
  t5 = Cos(t3);
  t6 = Sin(t1);
  t7 = Cos(t4);
  t8 = Sin(t3);
  t9 = Sin(t4);
  t10 = x[19];
  t11 = -1.*t7*t6;
  t12 = -1.*t2*t8*t9;
  t13 = t11 + t12;
  t14 = t2*t7;
  t15 = -1.*t6*t8*t9;
  t16 = t14 + t15;
  t17 = x[20];
  t18 = x[21];
  t19 = t7*t6*t8;
  t20 = t2*t9;
  t21 = t19 + t20;
  t22 = -1.*t2*t7*t8;
  t23 = t6*t9;
  t24 = t22 + t23;
  t25 = -1.*t7*t6*t10;
  t26 = -1.*t2*t8*t9*t10;
  t27 = -1.*t5*t6*t9*t17;
  t28 = -1.*t7*t6*t8*t18;
  t29 = -1.*t2*t9*t18;
  t30 = t25 + t26 + t27 + t28 + t29;
  t31 = t2*t7*t8*t10;
  t32 = -1.*t6*t9*t10;
  t33 = t5*t7*t6*t17;
  t34 = t2*t7*t18;
  t35 = -1.*t6*t8*t9*t18;
  t36 = t31 + t32 + t33 + t34 + t35;
  t37 = Power(t2,2);
  t38 = Power(t5,2);
  t39 = Power(t6,2);
  t40 = t7*t6*t8*t10;
  t41 = t2*t9*t10;
  t42 = -1.*t2*t5*t7*t17;
  t43 = t7*t6*t18;
  t44 = t2*t8*t9*t18;
  t45 = t40 + t41 + t42 + t43 + t44;
  t46 = t7*t6;
  t47 = t2*t8*t9;
  t48 = t46 + t47;
  t49 = Power(t8,2);
  t50 = t2*t7*t10;
  t51 = -1.*t6*t8*t9*t10;
  t52 = t2*t5*t9*t17;
  t53 = t2*t7*t8*t18;
  t54 = -1.*t6*t9*t18;
  t55 = t50 + t51 + t52 + t53 + t54;
  t56 = t2*t7*t8;
  t57 = -1.*t6*t9;
  t58 = t56 + t57;
  t59 = -1.*t7*t6*t8;
  t60 = -1.*t2*t9;
  t61 = t59 + t60;
  t62 = -1.*t7*t6*t8*t10;
  t63 = -1.*t2*t9*t10;
  t64 = t2*t5*t7*t17;
  t65 = -1.*t7*t6*t18;
  t66 = -1.*t2*t8*t9*t18;
  t67 = t62 + t63 + t64 + t65 + t66;
  t68 = Power(t9,2);
  p_output1[9]=-1.*t10*t13*t2*t5 + t2*t30*t5 - 1.*t10*t16*t5*t6 - 1.*t16*t17*t2*t8 + t13*t17*t6*t8 - 1.*t5*t6*(-1.*t10*t2*t7 - 1.*t18*t2*t7*t8 - 1.*t17*t2*t5*t9 + t18*t6*t9 + t10*t6*t8*t9);
  p_output1[10]=-1.*t10*t2*t24*t5 - 1.*t2*t36*t5 + t10*t21*t5*t6 - 1.*t45*t5*t6 + t17*t2*t21*t8 + t17*t24*t6*t8;
  p_output1[11]=t36*t48 + t21*t55 + t30*t58 + t16*t67;
  p_output1[12]=t18*t37*t38*t7 + t18*t38*t39*t7 + t18*t49*t7 + 2.*t17*t5*t8*t9 - 2.*t17*t37*t5*t8*t9 - 2.*t17*t39*t5*t8*t9;
  p_output1[13]=-1.*t17*t2*t24*t5 + t17*t21*t5*t6 + t10*t2*t21*t8 - 1.*t2*t45*t8 + t10*t24*t6*t8 + t36*t6*t8 - 2.*t17*t5*t7*t8 - 1.*t18*t38*t9;
  p_output1[14]=t10*t16*t2*t5*t7 - 1.*t2*t5*t55*t7 + t30*t5*t6*t7 + t10*t48*t5*t6*t7 - 1.*t18*t5*t68*t8 + t17*t2*t48*t7*t8 - 1.*t16*t17*t6*t7*t8 + t18*t5*Power(t7,2)*t8 + t18*t2*t48*t5*t9 - 1.*t16*t18*t5*t6*t9 + t17*t38*t7*t9 - 1.*t17*t49*t7*t9;
  p_output1[15]=-1.*t10*t5*t58*t6 - 1.*t10*t2*t5*t61 + t2*t5*t67 - 1.*t17*t38*t7 + t17*t49*t7 - 1.*t17*t2*t58*t8 + t17*t6*t61*t8 + t18*t5*t8*t9 - 1.*t5*t6*(-1.*t18*t2*t7 - 1.*t17*t5*t6*t7 - 1.*t10*t2*t7*t8 + t10*t6*t9 + t18*t6*t8*t9);
  p_output1[17]=2.*t16*t30 + 2.*t48*t55 - 2.*t17*t5*t68*t8 + 2.*t18*t38*t7*t9;
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
  plhs[0] = mxCreateDoubleMatrix((mwSize) 3, (mwSize) 16, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,x);


}

#else // MATLAB_MEX_FILE

#include "dJw_body_TorsoTop.hh"

namespace symbolic_expression
{
namespace basic
{

void dJw_body_TorsoTop_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
