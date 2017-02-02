#ifndef _ATRIAS3D_Lagrange_Hip_h_
#define _ATRIAS3D_Lagrange_Hip_h_

#include <math.h>

void ATRIAS3D_Lagrange_Hip(const double q[16], const double dq[16], const double extra_vars[4], double D_retval[16][16], double Cdq[16], double G[16], double B[6][16]) ;


#endif /* _ATRIAS3D_Lagrange_Hip_h_ */