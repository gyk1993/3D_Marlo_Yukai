/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:07 GMT-05:00
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
  t1 = x[6];
  t2 = x[3];
  t3 = Cos(t2);
  t4 = x[4];
  t5 = x[5];
  t6 = Cos(t5);
  t7 = Sin(t2);
  t8 = Sin(t4);
  t9 = Sin(t5);
  t10 = x[19];
  t11 = Cos(t4);
  t12 = x[21];
  t13 = Cos(t1);
  t14 = Sin(t1);
  t15 = x[20];
  t16 = -1.*t3*t6*t8;
  t17 = t7*t9;
  t18 = t16 + t17;
  t19 = x[22];
  t20 = t6*t7*t8;
  t21 = t3*t9;
  t22 = t20 + t21;
  t23 = -1.*t13*t11*t7;
  t24 = t14*t22;
  t25 = t23 + t24;
  t26 = t6*t7*t8*t10;
  t27 = t3*t9*t10;
  t28 = -1.*t3*t11*t6*t15;
  t29 = t6*t7*t12;
  t30 = t3*t8*t9*t12;
  t31 = t26 + t27 + t28 + t29 + t30;
  t32 = t3*t6*t8;
  t33 = -1.*t7*t9;
  t34 = t32 + t33;
  t35 = t3*t6*t8*t10;
  t36 = -1.*t7*t9*t10;
  t37 = t11*t6*t7*t15;
  t38 = t3*t6*t12;
  t39 = -1.*t7*t8*t9*t12;
  t40 = t35 + t36 + t37 + t38 + t39;
  t41 = t11*t14*t7*t19;
  t42 = t13*t22*t19;
  t43 = -1.*t13*t3*t11*t10;
  t44 = t13*t7*t8*t15;
  t45 = t14*t40;
  t46 = t41 + t42 + t43 + t44 + t45;
  t47 = -1.*t6*t7*t10;
  t48 = -1.*t3*t8*t9*t10;
  t49 = -1.*t11*t7*t9*t15;
  t50 = -1.*t6*t7*t8*t12;
  t51 = -1.*t3*t9*t12;
  t52 = t47 + t48 + t49 + t50 + t51;
  t53 = t11*t14*t7;
  t54 = t13*t22;
  t55 = t53 + t54;
  t56 = t3*t6;
  t57 = -1.*t7*t8*t9;
  t58 = t56 + t57;
  t59 = -1.*t6*t7*t8*t10;
  t60 = -1.*t3*t9*t10;
  t61 = t3*t11*t6*t15;
  t62 = -1.*t6*t7*t12;
  t63 = -1.*t3*t8*t9*t12;
  t64 = t59 + t60 + t61 + t62 + t63;
  t65 = t13*t11*t7*t19;
  t66 = -1.*t14*t22*t19;
  t67 = t3*t11*t14*t10;
  t68 = -1.*t14*t7*t8*t15;
  t69 = t13*t40;
  t70 = t65 + t66 + t67 + t68 + t69;
  t71 = t13*t3*t11;
  t72 = t14*t18;
  t73 = t71 + t72;
  t74 = t11*t6*t14;
  t75 = t13*t8;
  t76 = t74 + t75;
  t77 = -1.*t3*t11*t14*t19;
  t78 = t13*t18*t19;
  t79 = -1.*t13*t11*t7*t10;
  t80 = -1.*t13*t3*t8*t15;
  t81 = t14*t31;
  t82 = t77 + t78 + t79 + t80 + t81;
  t83 = -1.*t3*t11*t14;
  t84 = t13*t18;
  t85 = t83 + t84;
  t86 = -1.*t13*t3*t11*t19;
  t87 = -1.*t14*t18*t19;
  t88 = t11*t14*t7*t10;
  t89 = t3*t14*t8*t15;
  t90 = t13*t31;
  t91 = t86 + t87 + t88 + t89 + t90;
  t92 = -1.*t11*t14;
  t93 = -1.*t13*t6*t8;
  t94 = t92 + t93;
  t95 = t6*t7;
  t96 = t3*t8*t9;
  t97 = t95 + t96;
  t98 = t3*t6*t10;
  t99 = -1.*t7*t8*t9*t10;
  t100 = t3*t11*t9*t15;
  t101 = t3*t6*t8*t12;
  t102 = -1.*t7*t9*t12;
  t103 = t98 + t99 + t100 + t101 + t102;
  t104 = t13*t11*t6*t19;
  t105 = -1.*t14*t8*t19;
  t106 = t13*t11*t15;
  t107 = -1.*t6*t14*t8*t15;
  t108 = -1.*t11*t14*t9*t12;
  t109 = t104 + t105 + t106 + t107 + t108;
  t110 = t13*t11*t6;
  t111 = -1.*t14*t8;
  t112 = t110 + t111;
  t113 = -1.*t11*t6*t14*t19;
  t114 = -1.*t13*t8*t19;
  t115 = -1.*t11*t14*t15;
  t116 = -1.*t13*t6*t8*t15;
  t117 = -1.*t13*t11*t9*t12;
  t118 = t113 + t114 + t115 + t116 + t117;
  t119 = Power(t9,2);
  t120 = Power(t11,2);
  t121 = -1.*t11*t6*t14;
  t122 = -1.*t13*t8;
  t123 = t121 + t122;
  t124 = -1.*t13*t3*t11;
  t125 = t3*t11*t14*t19;
  t126 = t13*t11*t7*t10;
  t127 = t13*t3*t8*t15;
  p_output1[9]=t52*t73 + t58*t82 + t46*(-1.*t6*t7 - 1.*t3*t8*t9) + t25*(-1.*t10*t3*t6 - 1.*t12*t3*t6*t8 - 1.*t11*t15*t3*t9 + t12*t7*t9 + t10*t7*t8*t9);
  p_output1[10]=t55*(t125 + t126 + t127 + t13*t19*t34 + t14*t64) + (t124 + t14*t34)*t70 + t46*t85 + t25*t91;
  p_output1[11]=(t11*t14*t3 + t13*t34)*t52 + t103*t55 + t58*(t11*t13*t19*t3 - 1.*t14*t19*t34 + t13*t64 - 1.*t10*t11*t14*t7 - 1.*t14*t15*t3*t8) + t70*t97;
  p_output1[12]=-1.*t11*t12*t25*t6*t7 + t11*t12*t3*t6*t73 + t12*t6*t76*t8 - 1.*t10*t11*t25*t3*t9 - 1.*t11*t46*t7*t9 - 1.*t10*t11*t7*t73*t9 + t11*t15*t76*t9 + t109*t8*t9 + t15*t25*t7*t8*t9 - 1.*t15*t3*t73*t8*t9 + t11*t3*t82*t9;
  p_output1[13]=t118*(t11*t13 - 1.*t14*t6*t8) + t70*(t11*t14*t6*t7 + t13*t7*t8) + t85*(-1.*t11*t13*t15*t3 - 1.*t11*t13*t19*t3*t6 + t10*t11*t14*t6*t7 + t14*t19*t3*t8 + t14*t15*t3*t6*t8 + t10*t13*t7*t8 + t11*t12*t14*t3*t9) + t55*(t10*t11*t14*t3*t6 + t11*t13*t15*t7 + t11*t13*t19*t6*t7 + t10*t13*t3*t8 - 1.*t14*t19*t7*t8 - 1.*t14*t15*t6*t7*t8 - 1.*t11*t12*t14*t7*t9) + t112*(-1.*t11*t14*t19 - 1.*t11*t14*t15*t6 - 1.*t13*t15*t8 - 1.*t13*t19*t6*t8 + t12*t14*t8*t9) + (-1.*t11*t14*t3*t6 - 1.*t13*t3*t8)*t91;
  p_output1[14]=t103*(-1.*t11*t13*t3*t6 + t14*t3*t8) + t52*(t11*t13*t6*t7 - 1.*t14*t7*t8) + t58*(t10*t11*t13*t3*t6 - 1.*t11*t14*t15*t7 - 1.*t11*t14*t19*t6*t7 - 1.*t10*t14*t3*t8 - 1.*t13*t19*t7*t8 - 1.*t13*t15*t6*t7*t8 - 1.*t11*t12*t13*t7*t9) - 1.*t11*t9*(-1.*t11*t13*t19 - 1.*t11*t13*t15*t6 + t14*t15*t8 + t14*t19*t6*t8 + t12*t13*t8*t9) - 1.*t11*t12*t6*t94 + t15*t8*t9*t94 + (t11*t14*t15*t3 + t11*t14*t19*t3*t6 + t10*t11*t13*t6*t7 + t13*t19*t3*t8 + t13*t15*t3*t6*t8 - 1.*t10*t14*t7*t8 + t11*t12*t13*t3*t9)*t97;
  p_output1[15]=-1.*t109*t11*t6 + t64*t73 + t15*t6*t76*t8 + t34*t82 + t11*t12*t76*t9 + t46*(-1.*t6*t7*t8 - 1.*t3*t9) + t25*(-1.*t12*t3*t6 - 1.*t11*t15*t6*t7 - 1.*t10*t3*t6*t8 + t10*t7*t9 + t12*t7*t8*t9);
  p_output1[16]=t14*t52*t55 + t13*t19*t55*t58 - 1.*t11*t112*t12*t14*t6 + t14*t58*t70 + t103*t14*t85 - 1.*t11*t118*t14*t9 - 1.*t11*t112*t13*t19*t9 + t112*t14*t15*t8*t9 + t13*t19*t85*t97 + t14*t91*t97;
  p_output1[17]=-1.*t119*t120*t14*t19 + 2.*t13*t52*t58 - 1.*t14*t19*Power(t58,2) - 2.*t11*t119*t13*t15*t8 + 2.*t12*t120*t13*t6*t9 + 2.*t103*t13*t97 - 1.*t14*t19*Power(t97,2);
  p_output1[19]=2.*t112*t118 + 2.*t55*t70 + 2.*t85*t91;
  p_output1[20]=t103*(t124 - 1.*t14*t18) - 1.*t11*t12*t123*t6 + t52*(-1.*t14*t22 + t11*t13*t7) + t58*(-1.*t13*t19*t22 + t10*t11*t13*t3 - 1.*t14*t40 - 1.*t11*t14*t19*t7 - 1.*t13*t15*t7*t8) + t123*t15*t8*t9 - 1.*t11*t9*(-1.*t11*t13*t15 - 1.*t11*t13*t19*t6 + t14*t19*t8 + t14*t15*t6*t8 + t11*t12*t14*t9) + (t125 + t126 + t127 - 1.*t13*t18*t19 - 1.*t14*t31)*t97;
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

#include "dJw_body_qHRight.hh"

namespace symbolic_expression
{
namespace basic
{

void dJw_body_qHRight_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
