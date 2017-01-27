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
  t1 = x[4];
  t2 = Cos(t1);
  t3 = x[5];
  t4 = x[3];
  t5 = Cos(t4);
  t6 = Sin(t3);
  t7 = Sin(t4);
  t8 = Cos(t3);
  t9 = Sin(t1);
  t10 = t8*t7*t9;
  t11 = t5*t6;
  t12 = t10 + t11;
  t13 = t5*t8;
  t14 = -1.*t7*t9*t6;
  t15 = t13 + t14;
  t16 = -1.*t5*t2*t12;
  t17 = -1.*t5*t8*t9;
  t18 = t7*t6;
  t19 = t17 + t18;
  t20 = -1.*t2*t7*t19;
  t21 = t16 + t20;
  t22 = -1.*t8*t7;
  t23 = -1.*t5*t9*t6;
  t24 = t22 + t23;
  t25 = -1.*t2*t7*t24;
  t26 = t5*t2*t15;
  t27 = t25 + t26;
  t28 = t8*t7;
  t29 = t5*t9*t6;
  t30 = t28 + t29;
  t31 = t12*t30;
  t32 = t5*t8*t9;
  t33 = -1.*t7*t6;
  t34 = t32 + t33;
  t35 = t34*t15;
  t36 = t31 + t35;
  t37 = Power(t2,2);
  t38 = Power(t5,2);
  t39 = t38*t37*t6;
  t40 = Power(t7,2);
  t41 = t37*t40*t6;
  t42 = Power(t9,2);
  t43 = t42*t6;
  t44 = t39 + t41 + t43;
  t45 = t37*t8;
  t46 = t7*t9*t12;
  t47 = -1.*t5*t9*t19;
  t48 = t45 + t46 + t47;
  t49 = t2*t8*t9*t6;
  t50 = -1.*t5*t2*t8*t30;
  t51 = t2*t8*t7*t15;
  t52 = t49 + t50 + t51;
  t53 = -1.*t2*t8*t9;
  t54 = -1.*t8*t7*t9;
  t55 = -1.*t5*t6;
  t56 = t54 + t55;
  t57 = -1.*t2*t7*t56;
  t58 = t5*t2*t34;
  t59 = t53 + t57 + t58;
  t60 = Power(t6,2);
  t61 = t37*t60;
  t62 = Power(t30,2);
  t63 = Power(t15,2);
  t64 = t61 + t62 + t63;
  p_output1[9]=-1.*t2*t21*t6 + t2*t27*t8 + t36*t9;
  p_output1[10]=t15*t21 + t12*t27 - 1.*t2*t36*t7;
  p_output1[11]=t19*t27 + t21*t30 + t2*t36*t5;
  p_output1[12]=-1.*t2*t48*t6 + t2*t44*t8 + t52*t9;
  p_output1[13]=t12*t44 + t15*t48 - 1.*t2*t52*t7;
  p_output1[14]=t19*t44 + t30*t48 + t2*t5*t52;
  p_output1[15]=t2*t59*t8 + t64*t9;
  p_output1[16]=t12*t59 - 1.*t2*t64*t7;
  p_output1[17]=t19*t59 + t2*t5*t64;
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

#include "Jw_world_TorsoTop.hh"

namespace symbolic_expression
{
namespace basic
{

void Jw_world_TorsoTop_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
