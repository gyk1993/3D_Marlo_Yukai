/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:14 GMT-05:00
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
  double t69;
  double t70;
  double t71;
  double t72;
  double t73;
  double t74;
  double t75;
  double t76;
  double t77;
  double t78;
  double t79;
  double t80;
  double t81;
  double t82;
  double t83;
  double t84;
  t1 = x[3];
  t2 = x[5];
  t3 = x[13];
  t4 = x[4];
  t5 = Sin(t1);
  t6 = x[11];
  t7 = Cos(t2);
  t8 = Sin(t4);
  t9 = Cos(t1);
  t10 = Sin(t2);
  t11 = Cos(t3);
  t12 = Sin(t3);
  t13 = Cos(t6);
  t14 = Cos(t4);
  t15 = Sin(t6);
  t16 = t9*t7;
  t17 = -1.*t5*t8*t10;
  t18 = t16 + t17;
  t19 = -1.*t13*t14*t5;
  t20 = t7*t5*t8;
  t21 = t9*t10;
  t22 = t20 + t21;
  t23 = t15*t22;
  t24 = t19 + t23;
  t25 = -1.*t9*t7*t8;
  t26 = t5*t10;
  t27 = t25 + t26;
  t28 = -1.*t12*t18;
  t29 = t11*t24;
  t30 = t28 + t29;
  t31 = -1.*t7*t5;
  t32 = -1.*t9*t8*t10;
  t33 = t31 + t32;
  t34 = -1.*t13*t9*t14;
  t35 = t9*t7*t8;
  t36 = -1.*t5*t10;
  t37 = t35 + t36;
  t38 = t15*t37;
  t39 = t34 + t38;
  t40 = t11*t18;
  t41 = t12*t24;
  t42 = t40 + t41;
  t43 = t14*t15*t5;
  t44 = t13*t22;
  t45 = t43 + t44;
  t46 = t7*t5;
  t47 = t9*t8*t10;
  t48 = t46 + t47;
  t49 = t13*t9*t14;
  t50 = t15*t27;
  t51 = t49 + t50;
  t52 = -1.*t12*t48;
  t53 = t11*t51;
  t54 = t52 + t53;
  t55 = t13*t14;
  t56 = -1.*t7*t15*t8;
  t57 = t55 + t56;
  t58 = t14*t7*t15*t5;
  t59 = t13*t5*t8;
  t60 = t58 + t59;
  t61 = -1.*t9*t14*t7*t15;
  t62 = -1.*t13*t9*t8;
  t63 = t61 + t62;
  t64 = -1.*t9*t14*t15;
  t65 = t13*t27;
  t66 = t64 + t65;
  t67 = t14*t7*t15;
  t68 = t13*t8;
  t69 = t67 + t68;
  t70 = t11*t48;
  t71 = t12*t51;
  t72 = t70 + t71;
  t73 = t11*t69;
  t74 = t14*t12*t10;
  t75 = t73 + t74;
  t76 = t13*t14*t7;
  t77 = -1.*t15*t8;
  t78 = t76 + t77;
  t79 = -1.*t7*t5*t8;
  t80 = -1.*t9*t10;
  t81 = t79 + t80;
  t82 = t12*t69;
  t83 = -1.*t11*t14*t10;
  t84 = t82 + t83;
  p_output1[9]=t30*(t11*t33 + t12*t39) + t42*t54;
  p_output1[10]=(-1.*t12*t33 + t11*t39)*t45 + t30*t66;
  p_output1[11]=t45*t72 + t42*(t13*t37 + t14*t15*t9);
  p_output1[12]=t30*(-1.*t10*t11*t14*t5 + t12*t60) + t75*(t12*t57 + t10*t11*t8) + t54*(t12*t63 + t10*t11*t14*t9);
  p_output1[13]=t45*(t10*t12*t14*t5 + t11*t60) + t78*(t11*t57 - 1.*t10*t12*t8) + t66*(t11*t63 - 1.*t10*t12*t14*t9);
  p_output1[14]=t42*(t13*t14*t5*t7 - 1.*t15*t5*t8) + (-1.*t14*t15 - 1.*t13*t7*t8)*t84 + t72*(-1.*t13*t14*t7*t9 + t15*t8*t9);
  p_output1[15]=(t11*t37 + t12*t15*t48)*t54 + (-1.*t10*t12*t14*t15 - 1.*t11*t14*t7)*t75 + t30*(t12*t15*t18 + t11*t81);
  p_output1[16]=(-1.*t12*t37 + t11*t15*t48)*t66 + (-1.*t10*t11*t14*t15 + t12*t14*t7)*t78 + t45*(t11*t15*t18 - 1.*t12*t81);
  p_output1[17]=t13*t18*t42 + t13*t48*t72 - 1.*t10*t13*t14*t84;
  p_output1[33]=t12*t30*t45 + t12*t54*t66 + t12*t75*t78;
  p_output1[34]=t11*Power(t45,2) + t11*Power(t66,2) + t11*Power(t78,2);
  p_output1[35]=t42*(-1.*t15*t22 + t13*t14*t5) + (-1.*t15*t27 + t34)*t72 + (-1.*t14*t15*t7 - 1.*t13*t8)*t84;
  p_output1[39]=Power(t30,2) + Power(t54,2) + Power(t75,2);
  p_output1[40]=(-1.*t11*t18 - 1.*t12*t24)*t45 + (-1.*t11*t48 - 1.*t12*t51)*t66 + (t10*t11*t14 - 1.*t12*t69)*t78;
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

#include "Jw_body_qBLeft.hh"

namespace symbolic_expression
{
namespace basic
{

void Jw_body_qBLeft_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
