/*
 * Automatically Generated from Mathematica.
 * Thu 26 Jan 2017 21:34:13 GMT-05:00
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
  t1 = x[11];
  t2 = x[4];
  t3 = Cos(t2);
  t4 = x[12];
  t5 = x[5];
  t6 = Cos(t4);
  t7 = Cos(t5);
  t8 = Sin(t1);
  t9 = t3*t7*t8;
  t10 = Cos(t1);
  t11 = Sin(t2);
  t12 = t10*t11;
  t13 = t9 + t12;
  t14 = Sin(t4);
  t15 = Sin(t5);
  t16 = x[28];
  t17 = x[27];
  t18 = x[20];
  t19 = x[21];
  t20 = x[3];
  t21 = Cos(t20);
  t22 = Sin(t20);
  t23 = t7*t22;
  t24 = t21*t11*t15;
  t25 = t23 + t24;
  t26 = t10*t21*t3;
  t27 = -1.*t21*t7*t11;
  t28 = t22*t15;
  t29 = t27 + t28;
  t30 = t8*t29;
  t31 = t26 + t30;
  t32 = x[19];
  t33 = t21*t7;
  t34 = -1.*t22*t11*t15;
  t35 = t33 + t34;
  t36 = -1.*t10*t3*t22;
  t37 = t7*t22*t11;
  t38 = t21*t15;
  t39 = t37 + t38;
  t40 = t8*t39;
  t41 = t36 + t40;
  t42 = t10*t3*t7*t17;
  t43 = -1.*t8*t11*t17;
  t44 = t10*t3*t18;
  t45 = -1.*t7*t8*t11*t18;
  t46 = -1.*t3*t8*t15*t19;
  t47 = t42 + t43 + t44 + t45 + t46;
  t48 = t21*t7*t32;
  t49 = -1.*t22*t11*t15*t32;
  t50 = t21*t3*t15*t18;
  t51 = t21*t7*t11*t19;
  t52 = -1.*t22*t15*t19;
  t53 = t48 + t49 + t50 + t51 + t52;
  t54 = -1.*t21*t3*t8*t17;
  t55 = t10*t29*t17;
  t56 = -1.*t10*t3*t22*t32;
  t57 = -1.*t10*t21*t11*t18;
  t58 = t7*t22*t11*t32;
  t59 = t21*t15*t32;
  t60 = -1.*t21*t3*t7*t18;
  t61 = t7*t22*t19;
  t62 = t21*t11*t15*t19;
  t63 = t58 + t59 + t60 + t61 + t62;
  t64 = t8*t63;
  t65 = t54 + t55 + t56 + t57 + t64;
  t66 = -1.*t7*t22*t32;
  t67 = -1.*t21*t11*t15*t32;
  t68 = -1.*t3*t22*t15*t18;
  t69 = -1.*t7*t22*t11*t19;
  t70 = -1.*t21*t15*t19;
  t71 = t66 + t67 + t68 + t69 + t70;
  t72 = t3*t8*t22*t17;
  t73 = t10*t39*t17;
  t74 = -1.*t10*t21*t3*t32;
  t75 = t10*t22*t11*t18;
  t76 = t21*t7*t11*t32;
  t77 = -1.*t22*t15*t32;
  t78 = t3*t7*t22*t18;
  t79 = t21*t7*t19;
  t80 = -1.*t22*t11*t15*t19;
  t81 = t76 + t77 + t78 + t79 + t80;
  t82 = t8*t81;
  t83 = t72 + t73 + t74 + t75 + t82;
  p_output1[0]=(-1.*t14*t25 + t31*t6)*(-1.*t14*t16*t25 + t16*t31*t6 + t53*t6 + t14*t65) + (t14*t15*t3 + t13*t6)*(t14*t15*t16*t3 + t14*t47 + t13*t16*t6 + t11*t15*t18*t6 - 1.*t19*t3*t6*t7) + (-1.*t14*t35 + t41*t6)*(-1.*t14*t16*t35 + t16*t41*t6 + t6*t71 + t14*t83);
  p_output1[1]=(-1.*t13*t14*t16 - 1.*t11*t14*t15*t18 + t15*t16*t3*t6 + t47*t6 + t14*t19*t3*t7)*(t10*t3*t7 - 1.*t11*t8) + (-1.*t14*t16*t31 - 1.*t14*t53 - 1.*t16*t25*t6 + t6*t65)*(t10*t29 - 1.*t21*t3*t8) + (t10*t39 + t22*t3*t8)*(-1.*t14*t16*t41 - 1.*t16*t35*t6 - 1.*t14*t71 + t6*t83);
  p_output1[2]=(t14*t31 + t25*t6)*(-1.*t10*t17*t21*t3 + t10*t63 + t11*t18*t21*t8 - 1.*t17*t29*t8 + t22*t3*t32*t8) + (t13*t14 - 1.*t15*t3*t6)*(-1.*t10*t11*t17 - 1.*t10*t15*t19*t3 - 1.*t10*t11*t18*t7 - 1.*t18*t3*t8 - 1.*t17*t3*t7*t8) + (t14*t41 + t35*t6)*(t10*t17*t22*t3 - 1.*t11*t18*t22*t8 + t21*t3*t32*t8 - 1.*t17*t39*t8 + t10*t81);
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

#include "w_body_qALeft.hh"

namespace symbolic_expression
{
namespace basic
{

void w_body_qALeft_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
