#ifndef __c26_Walking01_DDA3D_h__
#define __c26_Walking01_DDA3D_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc26_Walking01_DDA3DInstanceStruct
#define typedef_SFc26_Walking01_DDA3DInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c26_sfEvent;
  boolean_T c26_isStable;
  boolean_T c26_doneDoubleBufferReInit;
  uint8_T c26_is_active_c26_Walking01_DDA3D;
  real_T (*c26_MotorCurrentCommand)[6];
  real_T (*c26_MotorCurrentCommandSafe)[6];
  real_T *c26_MedullaCommand;
  boolean_T *c26_RequestSoftStop;
  real_T (*c26_q)[13];
  real_T (*c26_dq)[13];
  real_T *c26_Switches;
  real_T *c26_Thermistors;
  real_T *c26_SafetyCountIn;
  real_T *c26_MedullaCommandSafe;
  real_T *c26_SafetyState;
  real_T *c26_SafetyCountOut;
  real_T (*c26_FaultDetected)[4];
} SFc26_Walking01_DDA3DInstanceStruct;

#endif                                 /*typedef_SFc26_Walking01_DDA3DInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c26_Walking01_DDA3D_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c26_Walking01_DDA3D_get_check_sum(mxArray *plhs[]);
extern void c26_Walking01_DDA3D_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
