#ifndef __Walking_ATRIAS_XPCOPTIONS_H___
#define __Walking_ATRIAS_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "Walking_ATRIAS.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_Walking_ATRIAS_T))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     10000000
#define PROFILINGFLAG                  0
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCMODELSTACKSIZEKB            512
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0
#define DOUBLEBUFFERING                0

/* Change all stepsize using the newBaseRateStepSize */
void Walking_ATRIAS_ChangeStepSize(real_T newBaseRateStepSize,
  RT_MODEL_Walking_ATRIAS_T *const Walking_ATRIAS_M)
{
  real_T ratio = newBaseRateStepSize / 0.001;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  Walking_ATRIAS_M->Timing.stepSize0 = Walking_ATRIAS_M->Timing.stepSize0 *
    ratio;
  Walking_ATRIAS_M->Timing.stepSize = Walking_ATRIAS_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  Walking_ATRIAS_ChangeStepSize(stepSize, Walking_ATRIAS_M);
}

#endif                                 /* __Walking_ATRIAS_XPCOPTIONS_H___ */
