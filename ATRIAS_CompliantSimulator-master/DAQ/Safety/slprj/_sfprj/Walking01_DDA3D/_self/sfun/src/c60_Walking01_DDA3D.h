#ifndef __c60_Walking01_DDA3D_h__
#define __c60_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc60_Walking01_DDA3DInstanceStruct
#define typedef_SFc60_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c60_sfEvent;
  boolean_T c60_isStable;
  boolean_T c60_doneDoubleBufferReInit;
  uint8_T c60_is_active_c60_Walking01_DDA3D;
  real_T (*c60_MotorCurrentCommand)[6];
  real_T (*c60_MotorCurrentCommandSafe)[6];
  real_T *c60_MedullaCommand;
  boolean_T *c60_RequestSoftStop;
  real_T (*c60_q)[13];
  real_T (*c60_dq)[13];
  real_T *c60_Switches;
  real_T *c60_Thermistors;
  real_T *c60_SafetyCountIn;
  real_T *c60_MedullaCommandSafe;
  real_T *c60_SafetyState;
  real_T *c60_SafetyCountOut;
  real_T (*c60_FaultDetected)[4];
} SFc60_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc60_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c60_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c60_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c60_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
