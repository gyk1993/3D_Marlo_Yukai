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
  t1 = var[6];
  t2 = var[4];
  t3 = Cos(t1);
  t4 = Cos(t2);
  t5 = var[5];
  t6 = Cos(t5);
  t7 = Sin(t1);
  t8 = Sin(t2);
  t9 = var[7];
  t10 = var[9];
  t11 = Cos(t9);
  t12 = t3*t4;
  t13 = -1.*t6*t7*t8;
  t14 = t12 + t13;
  t15 = Sin(t9);
  t16 = Sin(t5);
  t17 = Sin(t10);
  t18 = t15*t14;
  t19 = t11*t8*t16;
  t20 = t18 + t19;
  t21 = Cos(t10);
  t22 = t11*t14;
  t23 = -1.*t15*t8*t16;
  t24 = t22 + t23;
  t25 = -1.*t21;
  t26 = 1. + t25;
  t27 = t4*t6*t15;
  t28 = -1.*t11*t4*t7*t16;
  t29 = t27 + t28;
  t30 = -1.*t11*t4*t6;
  t31 = -1.*t4*t15*t7*t16;
  t32 = t30 + t31;
  t33 = t3*t4*t6;
  t34 = -1.*t7*t8;
  t35 = t33 + t34;
  t36 = t4*t6*t7;
  t37 = t3*t8;
  t38 = t36 + t37;
  t39 = -1.*t15*t38;
  t40 = t11*t4*t16;
  t41 = t39 + t40;
  t42 = t11*t38;
  t43 = t4*t15*t16;
  t44 = t42 + t43;
  t45 = 0.4*t17*t44;
  t46 = t15*t38;
  t47 = -1.*t11*t4*t16;
  t48 = t46 + t47;
  t49 = -1.*t17*t44;
  t50 = var[3];
  t51 = Cos(t50);
  t52 = Sin(t50);
  t53 = t51*t6*t8;
  t54 = -1.*t52*t16;
  t55 = t53 + t54;
  t56 = -1.*t6*t52;
  t57 = -1.*t51*t8*t16;
  t58 = t56 + t57;
  t59 = -1.*t3*t51*t4;
  t60 = t7*t55;
  t61 = t59 + t60;
  t62 = -1.*t15*t58;
  t63 = t11*t61;
  t64 = t62 + t63;
  t65 = t11*t58;
  t66 = t15*t61;
  t67 = t65 + t66;
  t68 = t4*t6*t7*t52;
  t69 = t3*t52*t8;
  t70 = t68 + t69;
  t71 = t15*t70;
  t72 = -1.*t11*t4*t52*t16;
  t73 = t71 + t72;
  t74 = t11*t70;
  t75 = t4*t15*t52*t16;
  t76 = t74 + t75;
  t77 = t51*t6;
  t78 = -1.*t52*t8*t16;
  t79 = t77 + t78;
  t80 = -1.*t6*t52*t8;
  t81 = -1.*t51*t16;
  t82 = t80 + t81;
  t83 = -1.*t15*t82;
  t84 = t11*t7*t79;
  t85 = t83 + t84;
  t86 = t11*t82;
  t87 = t15*t7*t79;
  t88 = t86 + t87;
  t89 = t4*t7*t52;
  t90 = t6*t52*t8;
  t91 = t51*t16;
  t92 = t90 + t91;
  t93 = t3*t92;
  t94 = t89 + t93;
  t95 = -1.*t3*t4*t52;
  t96 = t7*t92;
  t97 = t95 + t96;
  t98 = -1.*t15*t79;
  t99 = t11*t97;
  t100 = t98 + t99;
  t101 = -1.*t11*t79;
  t102 = -1.*t15*t97;
  t103 = t101 + t102;
  t104 = 0.4*t17*t100;
  t105 = -1.*t17*t100;
  t106 = t11*t79;
  t107 = t15*t97;
  t108 = t106 + t107;
  t109 = -1.*t51*t4*t6*t7;
  t110 = -1.*t3*t51*t8;
  t111 = t109 + t110;
  t112 = t15*t111;
  t113 = t11*t51*t4*t16;
  t114 = t112 + t113;
  t115 = t11*t111;
  t116 = -1.*t51*t4*t15*t16;
  t117 = t115 + t116;
  t118 = t6*t52;
  t119 = t51*t8*t16;
  t120 = t118 + t119;
  t121 = -1.*t15*t55;
  t122 = t11*t7*t120;
  t123 = t121 + t122;
  t124 = t11*t55;
  t125 = t15*t7*t120;
  t126 = t124 + t125;
  t127 = -1.*t51*t4*t7;
  t128 = -1.*t51*t6*t8;
  t129 = t52*t16;
  t130 = t128 + t129;
  t131 = t3*t130;
  t132 = t127 + t131;
  t133 = t3*t51*t4;
  t134 = t7*t130;
  t135 = t133 + t134;
  t136 = -1.*t15*t120;
  t137 = t11*t135;
  t138 = t136 + t137;
  t139 = -1.*t11*t120;
  t140 = -1.*t15*t135;
  t141 = t139 + t140;
  t142 = 0.4*t17*t138;
  t143 = -1.*t17*t138;
  t144 = t11*t120;
  t145 = t15*t135;
  t146 = t144 + t145;
  p_output1[0]=1.;
  p_output1[1]=0.4*t17*t20 + 0.9*(-1.*t17*t20 + t21*t24) + 0.4*t24*t26 + 0.1831*(-1.*t4*t7 - 1.*t3*t6*t8);
  p_output1[2]=0.4*t26*t29 + 0.4*t17*t32 + 0.9*(t21*t29 - 1.*t17*t32) - 0.1831*t16*t3*t4;
  p_output1[3]=0.4*t15*t17*t35 + 0.4*t11*t26*t35 + 0.9*(-1.*t15*t17*t35 + t11*t21*t35) + 0.1831*(-1.*t4*t6*t7 - 1.*t3*t8);
  p_output1[4]=0.4*t26*t41 + t45 + 0.9*(t21*t41 + t49);
  p_output1[5]=t45 + 0.4*t21*t48 + 0.9*(-1.*t21*t48 + t49);
  p_output1[6]=-1.;
  p_output1[7]=1.;
  p_output1[8]=0.4*t26*t64 + 0.4*t17*t67 + 0.9*(t21*t64 - 1.*t17*t67) + 0.1831*(t3*t55 + t4*t51*t7);
  p_output1[9]=0.4*t17*t73 + 0.4*t26*t76 + 0.9*(-1.*t17*t73 + t21*t76) + 0.1831*(t3*t4*t52*t6 - 1.*t52*t7*t8);
  p_output1[10]=0.1831*t3*t79 + 0.4*t26*t85 + 0.4*t17*t88 + 0.9*(t21*t85 - 1.*t17*t88);
  p_output1[11]=0.1831*(t3*t4*t52 - 1.*t7*t92) + 0.4*t15*t17*t94 + 0.4*t11*t26*t94 + 0.9*(-1.*t15*t17*t94 + t11*t21*t94);
  p_output1[12]=t104 + 0.9*(t105 + t103*t21) + 0.4*t103*t26;
  p_output1[13]=t104 + 0.4*t108*t21 + 0.9*(t105 - 1.*t108*t21);
  p_output1[14]=-1.;
  p_output1[15]=1.;
  p_output1[16]=0.4*t108*t17 + 0.9*(-1.*t108*t17 + t100*t21) + 0.4*t100*t26 + 0.1831*t94;
  p_output1[17]=0.4*t114*t17 + 0.9*(-1.*t114*t17 + t117*t21) + 0.4*t117*t26 + 0.1831*(-1.*t3*t4*t51*t6 + t51*t7*t8);
  p_output1[18]=0.4*t126*t17 + 0.9*(-1.*t126*t17 + t123*t21) + 0.4*t123*t26 + 0.1831*t120*t3;
  p_output1[19]=0.4*t132*t15*t17 + 0.9*(-1.*t132*t15*t17 + t11*t132*t21) + 0.4*t11*t132*t26 + 0.1831*(t59 - 1.*t130*t7);
  p_output1[20]=t142 + 0.9*(t143 + t141*t21) + 0.4*t141*t26;
  p_output1[21]=t142 + 0.4*t146*t21 + 0.9*(t143 - 1.*t146*t21);
  p_output1[22]=-1.;
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
    ( !(mrows == 19 && ncols == 1) && 
      !(mrows == 1 && ncols == 19))) 
    {
      mexErrMsgIdAndTxt( "MATLAB:MShaped:inputNotRealVector", "var is wrong.");
    }

  /*  Assign pointers to each input.  */
  var = mxGetPr(prhs[0]);
   


   
  /*  Create matrices for return arguments.  */
  plhs[0] = mxCreateDoubleMatrix((mwSize) 23, (mwSize) 1, mxREAL);
  p_output1 = mxGetPr(plhs[0]);


  /* Call the calculation subroutine. */
  output1(p_output1,var);


}

#else // MATLAB_MEX_FILE

#include "J_holConstrPosition_RightFourBarConnect.hh"

namespace symbolic_expression
{
namespace basic
{

void J_holConstrPosition_RightFourBarConnect_raw(double *p_output1, const double *var)
{
  // Call Subroutines
  output1(p_output1, var);

}

}
}

#endif // MATLAB_MEX_FILE
