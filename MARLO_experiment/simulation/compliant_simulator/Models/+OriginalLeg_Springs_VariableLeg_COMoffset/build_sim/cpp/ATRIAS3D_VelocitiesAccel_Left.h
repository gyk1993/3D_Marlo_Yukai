#ifndef _ATRIAS3D_VelocitiesAccel_Left_h_
#define _ATRIAS3D_VelocitiesAccel_Left_h_

#include <math.h>

void ATRIAS3D_VelocitiesAccel_Left(const double q[13], const double dq[13], const double extra_vars[4], double vcm[3], double J_cm[13][3], double dJ_cm[13][3], double v0T[3], double vHL[3], double vHR[3], double v0[3]) ;


#endif /* _ATRIAS3D_VelocitiesAccel_Left_h_ */
