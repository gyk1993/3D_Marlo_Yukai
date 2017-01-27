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
  t1 = x[11];
  t2 = x[4];
  t3 = x[12];
  t4 = Cos(t2);
  t5 = x[5];
  t6 = x[14];
  t7 = Cos(t3);
  t8 = Cos(t5);
  t9 = Sin(t1);
  t10 = t4*t8*t9;
  t11 = Cos(t1);
  t12 = Sin(t2);
  t13 = t11*t12;
  t14 = t10 + t13;
  t15 = Sin(t3);
  t16 = Sin(t5);
  t17 = Sin(t6);
  t18 = t15*t14;
  t19 = -1.*t7*t4*t16;
  t20 = t18 + t19;
  t21 = Cos(t6);
  t22 = t7*t14;
  t23 = t4*t15*t16;
  t24 = t22 + t23;
  t25 = x[30];
  t26 = x[28];
  t27 = x[27];
  t28 = x[20];
  t29 = x[21];
  t30 = t11*t4*t8*t27;
  t31 = -1.*t9*t12*t27;
  t32 = t11*t4*t28;
  t33 = -1.*t8*t9*t12*t28;
  t34 = -1.*t4*t9*t16*t29;
  t35 = t30 + t31 + t32 + t33 + t34;
  t36 = x[3];
  t37 = Cos(t36);
  t38 = Sin(t36);
  t39 = t8*t38;
  t40 = t37*t12*t16;
  t41 = t39 + t40;
  t42 = t11*t37*t4;
  t43 = -1.*t37*t8*t12;
  t44 = t38*t16;
  t45 = t43 + t44;
  t46 = t9*t45;
  t47 = t42 + t46;
  t48 = -1.*t15*t41;
  t49 = t7*t47;
  t50 = t48 + t49;
  t51 = t7*t41;
  t52 = t15*t47;
  t53 = t51 + t52;
  t54 = x[19];
  t55 = t37*t8*t54;
  t56 = -1.*t38*t12*t16*t54;
  t57 = t37*t4*t16*t28;
  t58 = t37*t8*t12*t29;
  t59 = -1.*t38*t16*t29;
  t60 = t55 + t56 + t57 + t58 + t59;
  t61 = -1.*t37*t4*t9*t27;
  t62 = t11*t45*t27;
  t63 = -1.*t11*t4*t38*t54;
  t64 = -1.*t11*t37*t12*t28;
  t65 = t8*t38*t12*t54;
  t66 = t37*t16*t54;
  t67 = -1.*t37*t4*t8*t28;
  t68 = t8*t38*t29;
  t69 = t37*t12*t16*t29;
  t70 = t65 + t66 + t67 + t68 + t69;
  t71 = t9*t70;
  t72 = t61 + t62 + t63 + t64 + t71;
  t73 = t37*t8;
  t74 = -1.*t38*t12*t16;
  t75 = t73 + t74;
  t76 = -1.*t11*t4*t38;
  t77 = t8*t38*t12;
  t78 = t37*t16;
  t79 = t77 + t78;
  t80 = t9*t79;
  t81 = t76 + t80;
  t82 = -1.*t15*t75;
  t83 = t7*t81;
  t84 = t82 + t83;
  t85 = t7*t75;
  t86 = t15*t81;
  t87 = t85 + t86;
  t88 = -1.*t8*t38*t54;
  t89 = -1.*t37*t12*t16*t54;
  t90 = -1.*t4*t38*t16*t28;
  t91 = -1.*t8*t38*t12*t29;
  t92 = -1.*t37*t16*t29;
  t93 = t88 + t89 + t90 + t91 + t92;
  t94 = t4*t9*t38*t27;
  t95 = t11*t79*t27;
  t96 = -1.*t11*t37*t4*t54;
  t97 = t11*t38*t12*t28;
  t98 = t37*t8*t12*t54;
  t99 = -1.*t38*t16*t54;
  t100 = t4*t8*t38*t28;
  t101 = t37*t8*t29;
  t102 = -1.*t38*t12*t16*t29;
  t103 = t98 + t99 + t100 + t101 + t102;
  t104 = t9*t103;
  t105 = t94 + t95 + t96 + t97 + t104;
  t106 = -1.*t15*t14*t26;
  t107 = t7*t4*t16*t26;
  t108 = -1.*t15*t12*t16*t28;
  t109 = t4*t8*t15*t29;
  t110 = t7*t35;
  t111 = t106 + t107 + t108 + t109 + t110;
  t112 = t7*t14*t26;
  t113 = t4*t15*t16*t26;
  t114 = t7*t12*t16*t28;
  t115 = -1.*t7*t4*t8*t29;
  t116 = t15*t35;
  t117 = t112 + t113 + t114 + t115 + t116;
  t118 = -1.*t7*t41*t26;
  t119 = -1.*t15*t47*t26;
  t120 = -1.*t15*t60;
  t121 = t7*t72;
  t122 = t118 + t119 + t120 + t121;
  t123 = -1.*t15*t41*t26;
  t124 = t7*t47*t26;
  t125 = t7*t60;
  t126 = t15*t72;
  t127 = t123 + t124 + t125 + t126;
  t128 = -1.*t7*t75*t26;
  t129 = -1.*t15*t81*t26;
  t130 = -1.*t15*t93;
  t131 = t7*t105;
  t132 = t128 + t129 + t130 + t131;
  t133 = -1.*t15*t75*t26;
  t134 = t7*t81*t26;
  t135 = t7*t93;
  t136 = t15*t105;
  t137 = t133 + t134 + t135 + t136;
  p_output1[0]=(-1.*t17*t20 + t21*t24)*(t111*t17 + t117*t21 - 1.*t17*t20*t25 + t21*t24*t25) + (t21*t50 - 1.*t17*t53)*(t122*t17 + t127*t21 + t21*t25*t50 - 1.*t17*t25*t53) + (t21*t84 - 1.*t17*t87)*(t132*t17 + t137*t21 + t21*t25*t84 - 1.*t17*t25*t87);
  p_output1[1]=(-1.*t117*t17 + t111*t21 - 1.*t20*t21*t25 - 1.*t17*t24*t25)*(t11*t4*t8 - 1.*t12*t9) + (-1.*t127*t17 + t122*t21 - 1.*t17*t25*t50 - 1.*t21*t25*t53)*(t11*t45 - 1.*t37*t4*t9) + (-1.*t137*t17 + t132*t21 - 1.*t17*t25*t84 - 1.*t21*t25*t87)*(t11*t79 + t38*t4*t9);
  p_output1[2]=(t17*t50 + t21*t53)*(-1.*t11*t27*t37*t4 + t11*t70 + t12*t28*t37*t9 - 1.*t27*t45*t9 + t38*t4*t54*t9) + (t17*t84 + t21*t87)*(t103*t11 + t11*t27*t38*t4 - 1.*t12*t28*t38*t9 + t37*t4*t54*t9 - 1.*t27*t79*t9) + (t20*t21 + t17*t24)*(-1.*t11*t12*t27 - 1.*t11*t16*t29*t4 - 1.*t11*t12*t28*t8 - 1.*t28*t4*t9 - 1.*t27*t4*t8*t9);
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

#include "w_body_fourBarALeft.hh"

namespace symbolic_expression
{
namespace basic
{

void w_body_fourBarALeft_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
