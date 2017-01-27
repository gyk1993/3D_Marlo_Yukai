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
  t1 = x[3];
  t2 = x[5];
  t3 = x[4];
  t4 = Sin(t1);
  t5 = x[6];
  t6 = Cos(t2);
  t7 = Sin(t3);
  t8 = Cos(t1);
  t9 = Sin(t2);
  t10 = Cos(t5);
  t11 = Cos(t3);
  t12 = Sin(t5);
  t13 = t6*t4*t7;
  t14 = t8*t9;
  t15 = t13 + t14;
  t16 = -1.*t10*t11*t4;
  t17 = t12*t15;
  t18 = t16 + t17;
  t19 = -1.*t8*t6*t7;
  t20 = t4*t9;
  t21 = t19 + t20;
  t22 = t11*t12*t4;
  t23 = t10*t15;
  t24 = t22 + t23;
  t25 = t8*t6;
  t26 = -1.*t4*t7*t9;
  t27 = t25 + t26;
  t28 = t8*t6*t7;
  t29 = -1.*t4*t9;
  t30 = t28 + t29;
  t31 = t10*t8*t11;
  t32 = t12*t21;
  t33 = t31 + t32;
  t34 = -1.*t8*t11*t12;
  t35 = t10*t21;
  t36 = t34 + t35;
  t37 = t6*t4;
  t38 = t8*t7*t9;
  t39 = t37 + t38;
  t40 = t11*t6*t12;
  t41 = t10*t7;
  t42 = t40 + t41;
  t43 = t10*t11*t6;
  t44 = -1.*t12*t7;
  t45 = t43 + t44;
  t46 = -1.*t10*t8*t11;
  p_output1[9]=t27*t33 + t18*(-1.*t4*t6 - 1.*t7*t8*t9);
  p_output1[10]=t18*t36 + t24*(t12*t30 + t46);
  p_output1[11]=t24*t39 + t27*(t10*t30 + t11*t12*t8);
  p_output1[12]=-1.*t11*t18*t4*t9 + t42*t7*t9 + t11*t33*t8*t9;
  p_output1[13]=t24*(t11*t12*t4*t6 + t10*t4*t7) + t45*(t10*t11 - 1.*t12*t6*t7) + t36*(-1.*t11*t12*t6*t8 - 1.*t10*t7*t8);
  p_output1[14]=t27*(t10*t11*t4*t6 - 1.*t12*t4*t7) + t39*(-1.*t10*t11*t6*t8 + t12*t7*t8) - 1.*t11*(-1.*t11*t12 - 1.*t10*t6*t7)*t9;
  p_output1[15]=t30*t33 - 1.*t11*t42*t6 + t18*(-1.*t4*t6*t7 - 1.*t8*t9);
  p_output1[16]=t12*t24*t27 + t12*t36*t39 - 1.*t11*t12*t45*t9;
  p_output1[17]=t10*Power(t27,2) + t10*Power(t39,2) + t10*Power(t11,2)*Power(t9,2);
  p_output1[19]=Power(t24,2) + Power(t36,2) + Power(t45,2);
  p_output1[20]=t27*(-1.*t12*t15 + t10*t11*t4) + t39*(-1.*t12*t21 + t46) - 1.*t11*(-1.*t11*t12*t6 - 1.*t10*t7)*t9;
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

#include "Jw_body_qHRight.hh"

namespace symbolic_expression
{
namespace basic
{

void Jw_body_qHRight_raw(double *p_output1, const double *x)
{
  // Call Subroutines
  output1(p_output1, x);

}

}
}

#endif // MATLAB_MEX_FILE
