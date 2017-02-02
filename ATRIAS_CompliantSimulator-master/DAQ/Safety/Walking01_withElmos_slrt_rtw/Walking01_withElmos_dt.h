/*
 * Walking01_withElmos_dt.h
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

#include "ext_types.h"

/* data type size table */
static uint_T rtDataTypeSizes[] = {
  sizeof(real_T),
  sizeof(real32_T),
  sizeof(int8_T),
  sizeof(uint8_T),
  sizeof(int16_T),
  sizeof(uint16_T),
  sizeof(int32_T),
  sizeof(uint32_T),
  sizeof(boolean_T),
  sizeof(fcn_call_T),
  sizeof(int_T),
  sizeof(pointer_T),
  sizeof(action_T),
  2*sizeof(uint32_T),
  sizeof(struct_ejS3XxP2cpNSLBrHRQpJ6B),
  sizeof(RobotCalibrationBus),
  sizeof(serialfifoptr),
  sizeof(ControlStateBus),
  sizeof(SupervisoryParamsBus),
  sizeof(DiscreteParamsBus),
  sizeof(ThetaParamsBus),
  sizeof(PhiParamsBus),
  sizeof(OutputParamsBus),
  sizeof(FeedbackParamsBus),
  sizeof(SaturationParamsBus),
  sizeof(ControlParamsBus),
  sizeof(struct_03rYgQwetGUfYPNCqYfA8C),
  sizeof(struct_sfpKF6f8kAqNBcgNOT1TeH),
  sizeof(struct_5fMnUe5Pdll1SHu9ujL08D),
  sizeof(struct_lKX5rZxiodED0xonMqNE4E),
  sizeof(struct_vVbQQSvlu4te0AbLB0kVdB),
  sizeof(struct_oI6LMO2QxWYqjYfxzs0Dp),
  sizeof(struct_UNZvwuE1nYalf4RiZWSyfE)
};

/* data type name table */
static const char_T * rtDataTypeNames[] = {
  "real_T",
  "real32_T",
  "int8_T",
  "uint8_T",
  "int16_T",
  "uint16_T",
  "int32_T",
  "uint32_T",
  "boolean_T",
  "fcn_call_T",
  "int_T",
  "pointer_T",
  "action_T",
  "timer_uint32_pair_T",
  "struct_ejS3XxP2cpNSLBrHRQpJ6B",
  "RobotCalibrationBus",
  "serialfifoptr",
  "ControlStateBus",
  "SupervisoryParamsBus",
  "DiscreteParamsBus",
  "ThetaParamsBus",
  "PhiParamsBus",
  "OutputParamsBus",
  "FeedbackParamsBus",
  "SaturationParamsBus",
  "ControlParamsBus",
  "struct_03rYgQwetGUfYPNCqYfA8C",
  "struct_sfpKF6f8kAqNBcgNOT1TeH",
  "struct_5fMnUe5Pdll1SHu9ujL08D",
  "struct_lKX5rZxiodED0xonMqNE4E",
  "struct_vVbQQSvlu4te0AbLB0kVdB",
  "struct_oI6LMO2QxWYqjYfxzs0Dp",
  "struct_UNZvwuE1nYalf4RiZWSyfE"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Walking01_withElmos_B.BusConversion_InsertedFor_State), 25, 0, 2
  },

  { (char_T *)(&Walking01_withElmos_B.VectorConcatenate[0]), 22, 0, 5 },

  { (char_T *)(&Walking01_withElmos_B.ControlState), 17, 0, 1 },

  { (char_T *)(&Walking01_withElmos_B.FIFOwrite1), 16, 0, 1 },

  { (char_T *)(&Walking01_withElmos_B.DataTypeConversion57), 0, 0, 121 },

  { (char_T *)(&Walking01_withElmos_B.EtherCATInit[0]), 6, 0, 20 },

  { (char_T *)(&Walking01_withElmos_B.EtherCATRxVar4), 7, 0, 132 },

  { (char_T *)(&Walking01_withElmos_B.EtherCATPDOReceive), 4, 0, 22 },

  { (char_T *)(&Walking01_withElmos_B.EtherCATRxVar_h), 5, 0, 92 },

  { (char_T *)(&Walking01_withElmos_B.EtherCATPDOReceive2), 2, 0, 4 },

  { (char_T *)(&Walking01_withElmos_B.EtherCATRxVar18), 3, 0, 42 },

  { (char_T *)(&Walking01_withElmos_B.LogicalOperator1), 8, 0, 21 },

  { (char_T *)(&Walking01_withElmos_B.sf_ComputeEulerAngles_i.ZYX[0]), 0, 0, 26
  },

  { (char_T *)(&Walking01_withElmos_B.CoreSubsys_p[2].RateTransition), 0, 0, 8 },

  { (char_T *)(&Walking01_withElmos_B.CoreSubsys_p[2].RateTransition7), 8, 0, 1
  },

  { (char_T *)(&Walking01_withElmos_B.CoreSubsys_p[2].
               sf_AnomalyDetection.q_clean), 0, 0, 2 },

  { (char_T *)(&Walking01_withElmos_B.sf_Chart_b.ControlWordIndex), 0, 0, 3 },

  { (char_T *)(&Walking01_withElmos_B.sf_Chart.ControlWordIndex), 0, 0, 3 },

  { (char_T *)(&Walking01_withElmos_B.sf_TypecastAndCast2.y[0]), 0, 0, 3 },

  { (char_T *)(&Walking01_withElmos_B.sf_TypecastAndCast1.y[0]), 0, 0, 3 },

  { (char_T *)(&Walking01_withElmos_B.CoreSubsys[18].UnitDelay), 0, 0, 2 },

  { (char_T *)(&Walking01_withElmos_B.CoreSubsys[18].sf_AnomalyDetection.q_clean),
    0, 0, 2 },

  { (char_T *)(&Walking01_withElmos_B.sf_ComputeEulerAngles.ZYX[0]), 0, 0, 26 }
  ,

  { (char_T *)(&Walking01_withElmos_DW.ControlParamsPrev), 25, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.ControlStatePrev), 17, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.UnitDelay1_DSTATE[0]), 0, 0, 2130 },

  { (char_T *)(&Walking01_withElmos_DW.FIFOwrite1_PWORK), 11, 0, 3 },

  { (char_T *)(&Walking01_withElmos_DW.sfEvent), 6, 0, 3 },

  { (char_T *)(&Walking01_withElmos_DW.RateTransition1_Buffer0_i), 7, 0, 4 },

  { (char_T *)(&Walking01_withElmos_DW.EtherCATRxVar4_IWORK[0]), 10, 0, 1422 },

  { (char_T *)(&Walking01_withElmos_DW.Counter_Count), 5, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.DelayInput1_DSTATE), 3, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.UnitDelay_DSTATE_n), 8, 0, 2 },

  { (char_T *)(&Walking01_withElmos_DW.ResetCPUOverloadCount_SubsysRan), 2, 0, 1
  },

  { (char_T *)(&Walking01_withElmos_DW.Counter_Count_o), 3, 0, 23 },

  { (char_T *)(&Walking01_withElmos_DW.isStable), 8, 0, 3 },

  { (char_T *)(&Walking01_withElmos_DW.CoreSubsys_p[2].UnitDelay_DSTATE), 0, 0,
    11 },

  { (char_T *)(&Walking01_withElmos_DW.CoreSubsys_p[2].
               RateTransition1_ActiveBufIdx), 2, 0, 3 },

  { (char_T *)(&Walking01_withElmos_DW.CoreSubsys_p[2].
               sf_AnomalyDetection.q_last), 0, 0, 2 },

  { (char_T *)(&Walking01_withElmos_DW.CoreSubsys_p[2].
               sf_AnomalyDetection.sfEvent), 6, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.CoreSubsys_p[2].
               sf_AnomalyDetection.temporalCounter_i1), 7, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.CoreSubsys_p[2].
               sf_AnomalyDetection.is_active_c3_Walking01_withElmo), 3, 0, 3 },

  { (char_T *)(&Walking01_withElmos_DW.CoreSubsys_p[2].
               sf_AnomalyDetection.isStable), 8, 0, 1 },

  { (char_T *)
    (&Walking01_withElmos_DW.NothingControlWord_m.NothingControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.FaultReset_i.FaultReset_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)
    (&Walking01_withElmos_DW.EnableControlWord_m.EnableControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Walking01_withElmos_DW.ShutdownControlWord_ju.ShutdownControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.sf_Chart_b.Timeout), 0, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.sf_Chart_b.sfEvent), 6, 0, 1 },

  { (char_T *)
    (&Walking01_withElmos_DW.sf_Chart_b.is_active_c22_Walking01_withElm), 3, 0,
    3 },

  { (char_T *)(&Walking01_withElmos_DW.sf_Chart_b.isStable), 8, 0, 1 },

  { (char_T *)
    (&Walking01_withElmos_DW.NothingControlWord_k.NothingControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.FaultReset_n.FaultReset_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)
    (&Walking01_withElmos_DW.EnableControlWord_l.EnableControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Walking01_withElmos_DW.ShutdownControlWord_j.ShutdownControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Walking01_withElmos_DW.NothingControlWord_d.NothingControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.FaultReset_c.FaultReset_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)
    (&Walking01_withElmos_DW.EnableControlWord_c.EnableControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Walking01_withElmos_DW.ShutdownControlWord_h.ShutdownControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.sf_Chart.Timeout), 0, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.sf_Chart.sfEvent), 6, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.sf_Chart.is_active_c22_Walking01_withElm),
    3, 0, 3 },

  { (char_T *)(&Walking01_withElmos_DW.sf_Chart.isStable), 8, 0, 1 },

  { (char_T *)
    (&Walking01_withElmos_DW.NothingControlWord.NothingControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.FaultReset.FaultReset_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)
    (&Walking01_withElmos_DW.EnableControlWord.EnableControlWord_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)
    (&Walking01_withElmos_DW.ShutdownControlWord.ShutdownControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.CoreSubsys[18].UnitDelay_DSTATE), 0, 0, 5
  },

  { (char_T *)(&Walking01_withElmos_DW.CoreSubsys[18].sf_AnomalyDetection.q_last),
    0, 0, 3 },

  { (char_T *)(&Walking01_withElmos_DW.CoreSubsys[18].
               sf_AnomalyDetection.sfEvent), 6, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.CoreSubsys[18].
               sf_AnomalyDetection.temporalCounter_i1), 7, 0, 1 },

  { (char_T *)(&Walking01_withElmos_DW.CoreSubsys[18].
               sf_AnomalyDetection.is_active_c9_Walking01_withElmo), 3, 0, 3 },

  { (char_T *)(&Walking01_withElmos_DW.CoreSubsys[18].
               sf_AnomalyDetection.isStable), 8, 0, 1 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  73U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Walking01_withElmos_P.AllowDoubleSupport), 0, 0, 831 },

  { (char_T *)(&Walking01_withElmos_P.EnableFT), 8, 0, 3 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  2U,
  rtPTransitions
};

/* [EOF] Walking01_withElmos_dt.h */
