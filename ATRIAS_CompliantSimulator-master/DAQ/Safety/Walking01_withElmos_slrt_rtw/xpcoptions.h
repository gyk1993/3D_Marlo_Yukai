#ifndef __Walking01_withElmos_XPCOPTIONS_H___
#define __Walking01_withElmos_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "Walking01_withElmos.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_Walking01_withElmos_T))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000000
#define PROFILINGFLAG                  0
#define EVENTNUMBER                    0
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    1000
#define MAXOVERLOADLEN                 1000
#define XPCMODELSTACKSIZEKB            128
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0
#define DOUBLEBUFFERING                0

/* Change all stepsize using the newBaseRateStepSize */
void Walking01_withElmos_ChangeStepSize(real_T newBaseRateStepSize,
  RT_MODEL_Walking01_withElmos_T *const Walking01_withElmos_M)
{
  real_T ratio = newBaseRateStepSize / 0.0005;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  Walking01_withElmos_M->Timing.stepSize0 =
    Walking01_withElmos_M->Timing.stepSize0 * ratio;
  Walking01_withElmos_M->Timing.stepSize1 =
    Walking01_withElmos_M->Timing.stepSize1 * ratio;
  Walking01_withElmos_M->Timing.stepSize2 =
    Walking01_withElmos_M->Timing.stepSize2 * ratio;
  Walking01_withElmos_M->Timing.stepSize =
    Walking01_withElmos_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  Walking01_withElmos_ChangeStepSize(stepSize, Walking01_withElmos_M);
}

#endif                                 /* __Walking01_withElmos_XPCOPTIONS_H___ */
