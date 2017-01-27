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
  t1 = x[6];
  t2 = x[4];
  t3 = Cos(t2);
  t4 = x[5];
  t5 = Cos(t4);
  t6 = Sin(t1);
  t7 = Cos(t1);
  t8 = Sin(t2);
  t9 = x[3];
  t10 = Sin(t9);
  t11 = Sin(t4);
  t12 = Cos(t9);
  t13 = x[19];
  t14 = x[20];
  t15 = x[21];
  t16 = t3*t5*t6;
  t17 = t7*t8;
  t18 = t16 + t17;
  t19 = x[22];
  t20 = -1.*t12*t5*t8;
  t21 = t10*t11;
  t22 = t20 + t21;
  t23 = t5*t10*t8;
  t24 = t12*t11;
  t25 = t23 + t24;
  t26 = t7*t3*t5;
  t27 = -1.*t6*t8;
  t28 = t26 + t27;
  t29 = t5*t10*t8*t13;
  t30 = t12*t11*t13;
  t31 = -1.*t12*t3*t5*t14;
  t32 = t5*t10*t15;
  t33 = t12*t8*t11*t15;
  t34 = t29 + t30 + t31 + t32 + t33;
  t35 = t12*t5*t8*t13;
  t36 = -1.*t10*t11*t13;
  t37 = t3*t5*t10*t14;
  t38 = t12*t5*t15;
  t39 = -1.*t10*t8*t11*t15;
  t40 = t35 + t36 + t37 + t38 + t39;
  t41 = t3*t6*t10;
  t42 = t7*t25;
  t43 = t41 + t42;
  t44 = t8*t11*t14;
  t45 = -1.*t3*t5*t15;
  t46 = t44 + t45;
  t47 = t18*t46;
  t48 = -1.*t7*t3*t10;
  t49 = t6*t25;
  t50 = t48 + t49;
  t51 = -1.*t5*t10*t13;
  t52 = -1.*t12*t8*t11*t13;
  t53 = -1.*t3*t10*t11*t14;
  t54 = -1.*t5*t10*t8*t15;
  t55 = -1.*t12*t11*t15;
  t56 = t51 + t52 + t53 + t54 + t55;
  t57 = t50*t56;
  t58 = t7*t12*t3;
  t59 = t6*t22;
  t60 = t58 + t59;
  t61 = t12*t5*t13;
  t62 = -1.*t10*t8*t11*t13;
  t63 = t12*t3*t11*t14;
  t64 = t12*t5*t8*t15;
  t65 = -1.*t10*t11*t15;
  t66 = t61 + t62 + t63 + t64 + t65;
  t67 = t60*t66;
  t68 = t47 + t57 + t67;
  t69 = -1.*t3*t5*t6*t19;
  t70 = -1.*t7*t8*t19;
  t71 = -1.*t3*t6*t14;
  t72 = -1.*t7*t5*t8*t14;
  t73 = -1.*t7*t3*t11*t15;
  t74 = t69 + t70 + t71 + t72 + t73;
  t75 = -1.*t3*t11*t74;
  t76 = t5*t10;
  t77 = t12*t8*t11;
  t78 = t76 + t77;
  t79 = -1.*t7*t12*t3*t19;
  t80 = -1.*t6*t22*t19;
  t81 = t3*t6*t10*t13;
  t82 = t12*t6*t8*t14;
  t83 = t7*t34;
  t84 = t79 + t80 + t81 + t82 + t83;
  t85 = t78*t84;
  t86 = t12*t5;
  t87 = -1.*t10*t8*t11;
  t88 = t86 + t87;
  t89 = t7*t3*t10*t19;
  t90 = -1.*t6*t25*t19;
  t91 = t12*t3*t6*t13;
  t92 = -1.*t6*t10*t8*t14;
  t93 = t7*t40;
  t94 = t89 + t90 + t91 + t92 + t93;
  t95 = t88*t94;
  t96 = t75 + t85 + t95;
  t97 = t7*t3*t5*t19;
  t98 = -1.*t6*t8*t19;
  t99 = t7*t3*t14;
  t100 = -1.*t5*t6*t8*t14;
  t101 = -1.*t3*t6*t11*t15;
  t102 = t97 + t98 + t99 + t100 + t101;
  t103 = t28*t102;
  t104 = -1.*t12*t3*t6;
  t105 = t7*t22;
  t106 = t104 + t105;
  t107 = -1.*t12*t3*t6*t19;
  t108 = t7*t22*t19;
  t109 = -1.*t7*t3*t10*t13;
  t110 = -1.*t7*t12*t8*t14;
  t111 = t6*t34;
  t112 = t107 + t108 + t109 + t110 + t111;
  t113 = t106*t112;
  t114 = t3*t6*t10*t19;
  t115 = t7*t25*t19;
  t116 = -1.*t7*t12*t3*t13;
  t117 = t7*t10*t8*t14;
  t118 = t6*t40;
  t119 = t114 + t115 + t116 + t117 + t118;
  t120 = t43*t119;
  t121 = t103 + t113 + t120;
  p_output1[0]=-1.*t11*t121*t3 + t28*t68 + t18*t96;
  p_output1[1]=t43*t68 + t121*t88 + t50*t96;
  p_output1[2]=t106*t68 + t121*t78 + t60*t96;
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

#include "w_world_qHRight.hh"

namespace symbolic_expression
{
namespace basic
{

void w_world_qHRight_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
