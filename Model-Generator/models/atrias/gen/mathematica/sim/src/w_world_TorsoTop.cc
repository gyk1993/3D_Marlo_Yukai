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
  double t69;
  double t70;
  double t71;
  double t72;
  double t73;
  t1 = x[4];
  t2 = Cos(t1);
  t3 = x[5];
  t4 = Cos(t3);
  t5 = x[3];
  t6 = Sin(t3);
  t7 = Sin(t5);
  t8 = Cos(t5);
  t9 = Sin(t1);
  t10 = x[20];
  t11 = x[19];
  t12 = x[21];
  t13 = t8*t4;
  t14 = -1.*t7*t9*t6;
  t15 = t13 + t14;
  t16 = Power(t2,2);
  t17 = t16*t4*t10;
  t18 = -1.*t8*t4*t9;
  t19 = t7*t6;
  t20 = t18 + t19;
  t21 = -1.*t2*t7*t11;
  t22 = -1.*t8*t9*t10;
  t23 = t21 + t22;
  t24 = t20*t23;
  t25 = t4*t7*t9;
  t26 = t8*t6;
  t27 = t25 + t26;
  t28 = -1.*t8*t2*t11;
  t29 = t7*t9*t10;
  t30 = t28 + t29;
  t31 = t27*t30;
  t32 = t17 + t24 + t31;
  t33 = t9*t6*t10;
  t34 = -1.*t2*t4*t12;
  t35 = t33 + t34;
  t36 = t9*t35;
  t37 = -1.*t4*t7*t11;
  t38 = -1.*t8*t9*t6*t11;
  t39 = -1.*t2*t7*t6*t10;
  t40 = -1.*t4*t7*t9*t12;
  t41 = -1.*t8*t6*t12;
  t42 = t37 + t38 + t39 + t40 + t41;
  t43 = -1.*t2*t7*t42;
  t44 = t8*t4*t11;
  t45 = -1.*t7*t9*t6*t11;
  t46 = t8*t2*t6*t10;
  t47 = t8*t4*t9*t12;
  t48 = -1.*t7*t6*t12;
  t49 = t44 + t45 + t46 + t47 + t48;
  t50 = t8*t2*t49;
  t51 = t36 + t43 + t50;
  t52 = -1.*t4*t9*t10;
  t53 = -1.*t2*t6*t12;
  t54 = t52 + t53;
  t55 = -1.*t2*t6*t54;
  t56 = t4*t7;
  t57 = t8*t9*t6;
  t58 = t56 + t57;
  t59 = t4*t7*t9*t11;
  t60 = t8*t6*t11;
  t61 = -1.*t8*t2*t4*t10;
  t62 = t4*t7*t12;
  t63 = t8*t9*t6*t12;
  t64 = t59 + t60 + t61 + t62 + t63;
  t65 = t58*t64;
  t66 = t8*t4*t9*t11;
  t67 = -1.*t7*t6*t11;
  t68 = t2*t4*t7*t10;
  t69 = t8*t4*t12;
  t70 = -1.*t7*t9*t6*t12;
  t71 = t66 + t67 + t68 + t69 + t70;
  t72 = t15*t71;
  t73 = t55 + t65 + t72;
  p_output1[0]=t2*t4*t51 - 1.*t2*t32*t6 + t73*t9;
  p_output1[1]=t15*t32 + t27*t51 - 1.*t2*t7*t73;
  p_output1[2]=t20*t51 + t32*t58 + t2*t73*t8;
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

#include "w_world_TorsoTop.hh"

namespace symbolic_expression
{
namespace basic
{

void w_world_TorsoTop_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
