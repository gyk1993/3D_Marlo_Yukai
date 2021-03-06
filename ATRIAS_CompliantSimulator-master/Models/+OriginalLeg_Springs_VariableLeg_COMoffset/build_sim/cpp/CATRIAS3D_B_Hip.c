/* ATRIAS3D_B_HIP 
 * Generated by writeOptimizedFunctions (13 Oct 2016 15:06:29)
 */

#include <mex.h>
#include "ATRIAS3D_B_Hip.h"

void mexFunction(int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{
	double * q ;
	double (*B)[][16] ;

	/* Check for proper number of arguments. */
	if(nlhs!=1) mexErrMsgTxt("MEX function ATRIAS3D_B_Hip expects 1 output arguments.");
	if(nrhs!=1) mexErrMsgTxt("MEX function ATRIAS3D_B_Hip expects 1 input arguments.");

	/* Process Inputs */
	if(!(mxGetM(prhs[0])==16 && mxGetN(prhs[0])==1) && !(mxGetM(prhs[0])==1 && mxGetN(prhs[0])==16) )
		mexErrMsgTxt("Incorrect dimensions for input #1 - Should be a vector of length 16") ;
	q = mxGetPr(prhs[0]) ;


	/* Define Output variables */
	plhs[0] = mxCreateDoubleMatrix(16,6, mxREAL);
	B = (double (*)[][16]) mxGetPr(plhs[0]) ;

	/* Invoke function */
	ATRIAS3D_B_Hip(q, *B) ;
}
