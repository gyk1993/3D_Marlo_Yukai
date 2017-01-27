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
  double t99;
  double t100;
  double t101;
  double t102;
  double t103;
  double t104;
  double t105;
  double t106;
  double t107;
  double t108;
  double t109;
  double t110;
  double t111;
  double t112;
  double t113;
  double t114;
  double t115;
  double t116;
  double t117;
  double t118;
  double t119;
  double t120;
  double t121;
  double t122;
  double t123;
  double t124;
  double t125;
  double t126;
  double t127;
  double t128;
  double t129;
  double t130;
  double t131;
  double t132;
  double t133;
  double t134;
  double t135;
  double t136;
  double t137;
  double t138;
  double t139;
  double t140;
  double t141;
  double t142;
  double t143;
  double t144;
  double t145;
  double t146;
  t1 = x[11];
  t2 = x[3];
  t3 = Cos(t2);
  t4 = x[4];
  t5 = x[5];
  t6 = Cos(t5);
  t7 = Sin(t2);
  t8 = Sin(t4);
  t9 = Sin(t5);
  t10 = x[12];
  t11 = Cos(t1);
  t12 = Cos(t4);
  t13 = Sin(t1);
  t14 = t3*t6*t8;
  t15 = -1.*t7*t9;
  t16 = t14 + t15;
  t17 = x[14];
  t18 = Cos(t10);
  t19 = -1.*t6*t7;
  t20 = -1.*t3*t8*t9;
  t21 = t19 + t20;
  t22 = Sin(t10);
  t23 = -1.*t11*t3*t12;
  t24 = t13*t16;
  t25 = t23 + t24;
  t26 = Cos(t17);
  t27 = -1.*t22*t21;
  t28 = t18*t25;
  t29 = t27 + t28;
  t30 = Sin(t17);
  t31 = t18*t21;
  t32 = t22*t25;
  t33 = t31 + t32;
  t34 = -1.*t26;
  t35 = 1. + t34;
  t36 = t6*t7*t8;
  t37 = t3*t9;
  t38 = t36 + t37;
  t39 = t3*t6;
  t40 = -1.*t7*t8*t9;
  t41 = t39 + t40;
  t42 = -1.*t11*t12*t7;
  t43 = t13*t38;
  t44 = t42 + t43;
  t45 = -1.*t22*t41;
  t46 = t18*t44;
  t47 = t45 + t46;
  t48 = t18*t41;
  t49 = t22*t44;
  t50 = t48 + t49;
  t51 = t11*t12;
  t52 = -1.*t6*t13*t8;
  t53 = t51 + t52;
  t54 = t22*t53;
  t55 = t18*t8*t9;
  t56 = t54 + t55;
  t57 = t18*t53;
  t58 = -1.*t22*t8*t9;
  t59 = t57 + t58;
  t60 = t12*t6*t13*t7;
  t61 = t11*t7*t8;
  t62 = t60 + t61;
  t63 = t22*t62;
  t64 = -1.*t18*t12*t7*t9;
  t65 = t63 + t64;
  t66 = t18*t62;
  t67 = t12*t22*t7*t9;
  t68 = t66 + t67;
  t69 = -1.*t3*t12*t6*t13;
  t70 = -1.*t11*t3*t8;
  t71 = t69 + t70;
  t72 = t22*t71;
  t73 = t18*t3*t12*t9;
  t74 = t72 + t73;
  t75 = t18*t71;
  t76 = -1.*t3*t12*t22*t9;
  t77 = t75 + t76;
  t78 = t12*t6*t22;
  t79 = -1.*t18*t12*t13*t9;
  t80 = t78 + t79;
  t81 = -1.*t18*t12*t6;
  t82 = -1.*t12*t22*t13*t9;
  t83 = t81 + t82;
  t84 = -1.*t6*t7*t8;
  t85 = -1.*t3*t9;
  t86 = t84 + t85;
  t87 = -1.*t22*t86;
  t88 = t18*t13*t41;
  t89 = t87 + t88;
  t90 = t18*t86;
  t91 = t22*t13*t41;
  t92 = t90 + t91;
  t93 = t6*t7;
  t94 = t3*t8*t9;
  t95 = t93 + t94;
  t96 = -1.*t22*t16;
  t97 = t18*t13*t95;
  t98 = t96 + t97;
  t99 = t18*t16;
  t100 = t22*t13*t95;
  t101 = t99 + t100;
  t102 = t11*t12*t6;
  t103 = -1.*t13*t8;
  t104 = t102 + t103;
  t105 = t12*t13*t7;
  t106 = t11*t38;
  t107 = t105 + t106;
  t108 = -1.*t3*t12*t13;
  t109 = -1.*t3*t6*t8;
  t110 = t7*t9;
  t111 = t109 + t110;
  t112 = t11*t111;
  t113 = t108 + t112;
  t114 = t12*t6*t13;
  t115 = t11*t8;
  t116 = t114 + t115;
  t117 = -1.*t22*t116;
  t118 = t18*t12*t9;
  t119 = t117 + t118;
  t120 = t18*t116;
  t121 = t12*t22*t9;
  t122 = t120 + t121;
  t123 = -1.*t18*t41;
  t124 = -1.*t22*t44;
  t125 = t123 + t124;
  t126 = t11*t3*t12;
  t127 = t13*t111;
  t128 = t126 + t127;
  t129 = -1.*t22*t95;
  t130 = t18*t128;
  t131 = t129 + t130;
  t132 = -1.*t18*t95;
  t133 = -1.*t22*t128;
  t134 = t132 + t133;
  t135 = 0.4*t30*t122;
  t136 = t22*t116;
  t137 = -1.*t18*t12*t9;
  t138 = t136 + t137;
  t139 = -1.*t30*t122;
  t140 = 0.4*t30*t47;
  t141 = -1.*t30*t47;
  t142 = 0.4*t30*t131;
  t143 = -1.*t30*t131;
  t144 = t18*t95;
  t145 = t22*t128;
  t146 = t144 + t145;
  p_output1[0]=1.;
  p_output1[4]=1.;
  p_output1[8]=1.;
  p_output1[10]=-0.1831*(t11*t16 + t12*t13*t3) + 0.4*t30*t33 + 0.4*(t26*t29 - 1.*t30*t33) + 0.4*t29*t35;
  p_output1[11]=-0.1831*t107 + 0.4*t35*t47 + 0.4*t30*t50 + 0.4*(t26*t47 - 1.*t30*t50);
  p_output1[12]=0.4*t30*t56 + 0.4*t35*t59 + 0.4*(-1.*t30*t56 + t26*t59) - 0.1831*(-1.*t12*t13 - 1.*t11*t6*t8);
  p_output1[13]=0.4*t30*t65 + 0.4*t35*t68 + 0.4*(-1.*t30*t65 + t26*t68) - 0.1831*(t11*t12*t6*t7 - 1.*t13*t7*t8);
  p_output1[14]=0.4*t30*t74 + 0.4*t35*t77 + 0.4*(-1.*t30*t74 + t26*t77) - 0.1831*(-1.*t11*t12*t3*t6 + t13*t3*t8);
  p_output1[15]=0.4*t35*t80 + 0.4*t30*t83 + 0.4*(t26*t80 - 1.*t30*t83) + 0.1831*t11*t12*t9;
  p_output1[16]=-0.1831*t11*t41 + 0.4*t35*t89 + 0.4*t30*t92 + 0.4*(t26*t89 - 1.*t30*t92);
  p_output1[17]=0.4*t101*t30 - 0.1831*t11*t95 + 0.4*t35*t98 + 0.4*(-1.*t101*t30 + t26*t98);
  p_output1[33]=0.4*t104*t22*t30 + 0.4*(t104*t18*t26 - 1.*t104*t22*t30) + 0.4*t104*t18*t35 - 0.1831*(-1.*t12*t13*t6 - 1.*t11*t8);
  p_output1[34]=0.4*t107*t22*t30 + 0.4*(t107*t18*t26 - 1.*t107*t22*t30) + 0.4*t107*t18*t35 - 0.1831*(-1.*t13*t38 + t11*t12*t7);
  p_output1[35]=-0.1831*(-1.*t111*t13 + t23) + 0.4*t113*t22*t30 + 0.4*(t113*t18*t26 - 1.*t113*t22*t30) + 0.4*t113*t18*t35;
  p_output1[36]=t135 + 0.4*(t139 + t119*t26) + 0.4*t119*t35;
  p_output1[37]=t140 + 0.4*(t141 + t125*t26) + 0.4*t125*t35;
  p_output1[38]=t142 + 0.4*(t143 + t134*t26) + 0.4*t134*t35;
  p_output1[42]=t135 + 0.4*t138*t26 + 0.4*(t139 - 1.*t138*t26);
  p_output1[43]=t140 + 0.4*t26*t50 + 0.4*(t141 - 1.*t26*t50);
  p_output1[44]=t142 + 0.4*t146*t26 + 0.4*(t143 - 1.*t146*t26);
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

#include "J_fourBarALeft.hh"

namespace symbolic_expression
{
namespace basic
{

void J_fourBarALeft_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
