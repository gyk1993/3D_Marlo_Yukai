/*
 * Walking01_withElmos_private.h
 *
 * Code generation for model "Walking01_withElmos".
 *
 * Model version              : 1.1128
 * Simulink Coder version : 8.7 (R2014b) 08-Sep-2014
 * C source code generated on : Mon Jun 08 18:00:32 2015
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_Walking01_withElmos_private_h_
#define RTW_HEADER_Walking01_withElmos_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_roundd_snf(real_T u);
extern void xpcsetoverload(SimStruct *rts);
extern void fiforeadbinhdrmultiple(SimStruct *rts);
extern void board_setup_tews_XR17D15x(SimStruct *rts);
extern void setup_tews_XR17D15x(SimStruct *rts);
extern void read_hw_fifo_XR17D15x(SimStruct *rts);
extern void fifowrite(SimStruct *rts);
extern void xpcethercatpdorx(SimStruct *rts);
extern void xpctimeinfo(SimStruct *rts);
extern void xpcgetoverload(SimStruct *rts);
extern void xpcethercatpdotx(SimStruct *rts);
extern void Walking01_wi_ComputeEulerAngles(const real_T rtu_RkIn[9], const
  real_T rtu_wk[3], const real_T rtu_RCal[9], boolean_T rtu_Reset, const real_T
  rtu_R0In[9], const real_T rtu_YawRolloverIn[2],
  B_ComputeEulerAngles_Walking0_T *localB);
extern void Walking01_AnomalyDetection_Init(B_AnomalyDetection_Walking01__T
  *localB, DW_AnomalyDetection_Walking01_T *localDW);
extern void Walking0_AnomalyDetection_Start(B_AnomalyDetection_Walking01__T
  *localB);
extern void Walking01_with_AnomalyDetection(real_T rtu_q, real_T rtu_dq, real_T
  rtu_Counter, const real_T rtu_q_limits[2], real_T rtu_Threshold, boolean_T
  rtu_Reset, real_T rtu_ANOMALY_DT, B_AnomalyDetection_Walking01__T *localB,
  DW_AnomalyDetection_Walking01_T *localDW);
extern void Walking01_with_TypecastAndCast1(uint32_T rtu_u, uint32_T rtu_u_f,
  uint32_T rtu_u_a, B_TypecastAndCast1_Walking01__T *localB);
extern void Walking01_w_ShutdownControlWord(uint16_T *rty_ControlWord);
extern void Walking01_wit_EnableControlWord(uint16_T *rty_ControlWord);
extern void Walking01_withElmos_FaultReset(uint16_T *rty_ControlWord);
extern void Walking01_wi_NothingControlWord(uint16_T *rty_ControlWord);
extern void Walking01_withElmos_Chart_Init(DW_Chart_Walking01_withElmos_T
  *localDW);
extern void Walking01_withElmos_Chart(boolean_T rtu_SwitchOnDisabledMode,
  boolean_T rtu_ReadyToSwitchOnMode, boolean_T rtu_FaultMode, real_T
  rtu_MedullaCommand, B_Chart_Walking01_withElmos_T *localB,
  DW_Chart_Walking01_withElmos_T *localDW);
extern void Walking_AnomalyDetection_h_Init(B_AnomalyDetection_Walking0_h_T
  *localB, DW_AnomalyDetection_Walking_m_T *localDW);
extern void Walkin_AnomalyDetection_g_Start(B_AnomalyDetection_Walking0_h_T
  *localB);
extern void Walking01_wi_AnomalyDetection_h(real_T rtu_q, real_T rtu_dq, const
  real_T rtu_q_limits[2], real_T rtu_Threshold, boolean_T rtu_Reset, real_T
  rtu_ANOMALY_DT, B_AnomalyDetection_Walking0_h_T *localB,
  DW_AnomalyDetection_Walking_m_T *localDW);
void Walking01_withElmos_output0(void);
void Walking01_withElmos_update0(void);
void Walking01_withElmos_output1(void);
void Walking01_withElmos_update1(void);
void Walking01_withElmos_output2(void);
void Walking01_withElmos_update2(void);

#endif                                 /* RTW_HEADER_Walking01_withElmos_private_h_ */
