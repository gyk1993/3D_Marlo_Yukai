#ifndef _ATRIAS3D_VelocitiesAccel_Hip_h_
#define _ATRIAS3D_VelocitiesAccel_Hip_h_

#include <math.h>

void ATRIAS3D_VelocitiesAccel_Hip(const double q[16], const double dq[16], const double extra_vars[4], double vcm[3], double J_cm[16][3], double dJ_cm[16][3], double v0T[3], double vHL[3], double vHR[3], double v0[3]) ;


#endif /* _ATRIAS3D_VelocitiesAccel_Hip_h_ */
