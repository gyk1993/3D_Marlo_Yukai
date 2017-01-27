/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:36:56 GMT-05:00
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
  double t85;
  double t86;
  double t87;
  double t88;
  double t89;
  double t90;
  double t91;
  double t92;
  double t93;
  double t94;
  double t95;
  double t96;
  double t97;
  double t98;
  t1 = var[9];
  t2 = var[7];
  t3 = var[4];
  t4 = Cos(t1);
  t5 = Cos(t2);
  t6 = t4*t5;
  t7 = Sin(t1);
  t8 = Sin(t2);
  t9 = -1.*t7*t8;
  t10 = t6 + t9;
  t11 = var[6];
  t12 = var[5];
  t13 = Cos(t11);
  t14 = Sin(t3);
  t15 = Cos(t3);
  t16 = Cos(t12);
  t17 = t5*t7;
  t18 = t4*t8;
  t19 = t17 + t18;
  t20 = Sin(t11);
  t21 = Sin(t12);
  t22 = -1.*t5*t7;
  t23 = -1.*t4*t8;
  t24 = t22 + t23;
  t25 = var[3];
  t26 = t16*t10*t20;
  t27 = -1.*t24*t21;
  t28 = t26 + t27;
  t29 = Cos(t25);
  t30 = Sin(t25);
  t31 = t16*t19*t20;
  t32 = -1.*t10*t21;
  t33 = t31 + t32;
  t34 = t16*t24;
  t35 = t10*t20*t21;
  t36 = t34 + t35;
  t37 = t13*t15*t10;
  t38 = -1.*t14*t28;
  t39 = t37 + t38;
  t40 = t16*t10;
  t41 = t19*t20*t21;
  t42 = t40 + t41;
  t43 = t13*t15*t19;
  t44 = -1.*t14*t33;
  t45 = t43 + t44;
  t46 = 0.0014*t4;
  t47 = -0.1137*t7;
  t48 = t46 + t47;
  t49 = -1.*t4;
  t50 = 1. + t49;
  t51 = 0.4*t50;
  t52 = 0.5137*t4;
  t53 = 0.0014*t7;
  t54 = t51 + t52 + t53;
  t55 = t13*t10*t14;
  t56 = t15*t28;
  t57 = t55 + t56;
  t58 = t13*t15*t16;
  t59 = -1.*t20*t14;
  t60 = t58 + t59;
  t61 = t5*t54;
  t62 = t48*t8;
  t63 = t61 + t62;
  t64 = 0.1831*t13;
  t65 = t63*t20;
  t66 = t64 + t65;
  t67 = t5*t48;
  t68 = -1.*t54*t8;
  t69 = t67 + t68;
  t70 = t13*t63;
  t71 = -0.1831*t20;
  t72 = t70 + t71;
  t73 = t16*t66;
  t74 = -1.*t69*t21;
  t75 = t73 + t74;
  t76 = t16*t69;
  t77 = t66*t21;
  t78 = t76 + t77;
  t79 = t72*t14;
  t80 = t15*t75;
  t81 = t79 + t80;
  t82 = t15*t72;
  t83 = -1.*t14*t75;
  t84 = t82 + t83;
  t85 = t13*t19*t14;
  t86 = t15*t33;
  t87 = t85 + t86;
  t88 = -1.*t15*t20;
  t89 = -1.*t13*t16*t14;
  t90 = t88 + t89;
  t91 = -1.*t13*t21*t78;
  t92 = t42*t78;
  t93 = t13*t21*t78;
  t94 = -1.*t36*t78;
  t95 = t72*t20;
  t96 = t13*t19*t72;
  t97 = -1.*t72*t20;
  t98 = -1.*t13*t10*t72;
  p_output1[0]=(0.0009044*t57 - 0.0734502*t87)*(-1.*var[16] + var[32]) + (0.0009044*(t29*t36 - 1.*t30*t39) - 0.0734502*(t29*t42 - 1.*t30*t45))*(-1.*var[17] + var[33]) + (0.0009044*(t30*t36 + t29*t39) - 0.0734502*(t30*t42 + t29*t45))*(-1.*var[18] + var[34]) + (0.0176*t60 + 0.0009044*(t87*(-1.*t60*t81 - 1.*t84*t90 + t91) + t60*(t45*t84 + t81*t87 + t92)) - 0.0734502*(t57*(t60*t81 + t84*t90 + t93) + t60*(-1.*t57*t81 - 1.*t39*t84 + t94)))*(-1.*var[19] + var[35]) + (0.0176*t13*t21 + 0.0009044*(t42*(-1.*t13*t16*t75 + t91 + t95) + t13*t21*(t33*t75 + t92 + t96)) - 0.0734502*(t36*(t13*t16*t75 + t93 + t97) + t13*t21*(-1.*t28*t75 + t94 + t98)))*(-1.*var[20] + var[36]) + (-0.0176*t20 + 0.0009044*(t13*t19*(-1.*t13*t66 + t95) - 1.*t20*(t19*t20*t66 + t10*t69 + t96)) - 0.0734502*(t10*t13*(t13*t66 + t97) - 1.*t20*(-1.*t10*t20*t66 - 1.*t24*t69 + t98)))*(-1.*var[21] + var[37]) + (-0.00016559564*t10 - 0.01344873162*t24)*(-1.*var[22] + var[38]) + (0.0176 - 0.0734502*(-1.*t4*t54 + t48*t7) + 0.0009044*(t4*t48 + t54*t7))*(-1.*var[23] + var[39]) + 0.0259525539*(-1.*var[25] + var[41]);
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
  plhs[0] = mxCreateDoubleMatrix((mwSize) 1, (mwSize) 1, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var);


}

#else // MATLAB_MEX_FILE

#include "f_impactDynamics10.hh"

namespace symbolic_expression
{
namespace basic
{

void f_impactDynamics10_raw(double *p_output1, const double *var)
{
  // Call Subroutines
  output1(p_output1, var);

}

}
}

#endif // MATLAB_MEX_FILE
