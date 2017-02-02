/*
 * Walking_ATRIAS_private.h
 *
 * Code generation for model "Walking_ATRIAS".
 *
 * Model version              : 1.290
 * Simulink Coder version : 8.7 (R2014b) 08-Sep-2014
 * C source code generated on : Wed Jul 20 18:48:36 2016
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Walking_ATRIAS_private_h_
#define RTW_HEADER_Walking_ATRIAS_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern const char *getRefMdlPath(const char *refMdl);
extern int getRefMdlSignalNumber(const char *mdlBlock, const char *signalName);
extern void xpcethercatpdorx(SimStruct *rts);
extern void xpcethercatpdotx(SimStruct *rts);
extern void Walking_ATR_ShutdownControlWord(uint16_T *rty_ControlWord);
extern void Walking_ATRIA_EnableControlWord(uint16_T *rty_ControlWord);
extern void Walking_ATRIAS_FaultReset(uint16_T *rty_ControlWord);
extern void Walking_ATRI_NothingControlWord(uint16_T *rty_ControlWord);
extern void Walking_ATRIAS_Chart_Init(DW_Chart_Walking_ATRIAS_T *localDW);
extern void Walking_ATRIAS_Chart(boolean_T rtu_SwitchOnDisabledMode, boolean_T
  rtu_EnabledMode, boolean_T rtu_ReadyToSwitchOnMode, boolean_T rtu_FaultMode,
  real_T rtu_MedullaCommand, B_Chart_Walking_ATRIAS_T *localB,
  DW_Chart_Walking_ATRIAS_T *localDW);

#endif                                 /* RTW_HEADER_Walking_ATRIAS_private_h_ */
