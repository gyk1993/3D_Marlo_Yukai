#ifndef _ATRIAS3D_FootPointPosJacob_Hip_h_
#define _ATRIAS3D_FootPointPosJacob_Hip_h_

#include <math.h>

void ATRIAS3D_FootPointPosJacob_Hip(const double q[16], const double extra_vars[4], double p4R[3], double R1[3][3], double J4R[16][3], double JR1Col[16][9], double p4L[3], double R5[3][3], double J4L[16][3], double JR5Col[16][9]) ;


#endif /* _ATRIAS3D_FootPointPosJacob_Hip_h_ */
