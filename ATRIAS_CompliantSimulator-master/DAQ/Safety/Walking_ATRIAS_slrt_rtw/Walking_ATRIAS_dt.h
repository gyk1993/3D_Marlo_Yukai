/*
 * Walking_ATRIAS_dt.h
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
  sizeof(Controller3DHZD_obj_2_Walking_T)
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
  "Controller3DHZD_obj_2_Walking_T"
};

/* data type transitions for block I/O structure */
static DataTypeTransition rtBTransitions[] = {
  { (char_T *)(&Walking_ATRIAS_B.DataTypeConversion49), 0, 0, 801 },

  { (char_T *)(&Walking_ATRIAS_B.EtherCATRxVar6), 1, 0, 6 },

  { (char_T *)(&Walking_ATRIAS_B.EtherCATInit[0]), 6, 0, 16 },

  { (char_T *)(&Walking_ATRIAS_B.EtherCATRxVar4), 7, 0, 10 },

  { (char_T *)(&Walking_ATRIAS_B.EtherCATRxVar6_b), 4, 0, 23 },

  { (char_T *)(&Walking_ATRIAS_B.EtherCATRxVar_n), 5, 0, 107 },

  { (char_T *)(&Walking_ATRIAS_B.EtherCATPDOReceive2), 2, 0, 4 },

  { (char_T *)(&Walking_ATRIAS_B.EtherCATRxVar18), 3, 0, 43 },

  { (char_T *)(&Walking_ATRIAS_B.UnitDelay_l), 8, 0, 52 },

  { (char_T *)(&Walking_ATRIAS_B.sf_Chart_mz.ControlWordIndex), 0, 0, 3 },

  { (char_T *)(&Walking_ATRIAS_B.sf_Chart_m.ControlWordIndex), 0, 0, 3 },

  { (char_T *)(&Walking_ATRIAS_B.CoreSubsys[18].Uk1), 0, 0, 8 }
  ,

  { (char_T *)(&Walking_ATRIAS_DW.obj), 16, 0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.UnitDelay1_DSTATE[0]), 0, 0, 82 },

  { (char_T *)(&Walking_ATRIAS_DW.Scope1_PWORK.LoggedData), 11, 0, 23 },

  { (char_T *)(&Walking_ATRIAS_DW.sfEvent), 6, 0, 2 },

  { (char_T *)(&Walking_ATRIAS_DW.EtherCATRxVar4_IWORK[0]), 10, 0, 1321 },

  { (char_T *)(&Walking_ATRIAS_DW.Counter_Count), 5, 0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.UnitDelay_DSTATE_b), 8, 0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.DiscreteTimeIntegrator1_PrevRes), 2, 0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.is_active_c45_Walking_ATRIAS), 3, 0, 6 },

  { (char_T *)(&Walking_ATRIAS_DW.isStable), 8, 0, 3 },

  { (char_T *)
    (&Walking_ATRIAS_DW.NothingControlWord_jg.NothingControlWord_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.FaultReset_l.FaultReset_SubsysRanBC), 2, 0, 1
  },

  { (char_T *)
    (&Walking_ATRIAS_DW.EnableControlWord_n.EnableControlWord_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)
    (&Walking_ATRIAS_DW.ShutdownControlWord_l.ShutdownControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.sf_Chart_mz.Timeout), 0, 0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.sf_Chart_mz.sfEvent), 6, 0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.sf_Chart_mz.is_active_c44_Walking_ATRIAS), 3,
    0, 3 },

  { (char_T *)(&Walking_ATRIAS_DW.sf_Chart_mz.isStable), 8, 0, 1 },

  { (char_T *)
    (&Walking_ATRIAS_DW.NothingControlWord_j.NothingControlWord_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.FaultReset_k.FaultReset_SubsysRanBC), 2, 0, 1
  },

  { (char_T *)
    (&Walking_ATRIAS_DW.EnableControlWord_k.EnableControlWord_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)
    (&Walking_ATRIAS_DW.ShutdownControlWord_b.ShutdownControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)
    (&Walking_ATRIAS_DW.NothingControlWord_n.NothingControlWord_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.FaultReset_a.FaultReset_SubsysRanBC), 2, 0, 1
  },

  { (char_T *)
    (&Walking_ATRIAS_DW.EnableControlWord_h.EnableControlWord_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)
    (&Walking_ATRIAS_DW.ShutdownControlWord_p.ShutdownControlWord_SubsysRanBC),
    2, 0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.sf_Chart_m.Timeout), 0, 0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.sf_Chart_m.sfEvent), 6, 0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.sf_Chart_m.is_active_c44_Walking_ATRIAS), 3, 0,
    3 },

  { (char_T *)(&Walking_ATRIAS_DW.sf_Chart_m.isStable), 8, 0, 1 },

  { (char_T *)
    (&Walking_ATRIAS_DW.NothingControlWord.NothingControlWord_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)(&Walking_ATRIAS_DW.FaultReset.FaultReset_SubsysRanBC), 2, 0, 1 },

  { (char_T *)
    (&Walking_ATRIAS_DW.EnableControlWord.EnableControlWord_SubsysRanBC), 2, 0,
    1 },

  { (char_T *)
    (&Walking_ATRIAS_DW.ShutdownControlWord.ShutdownControlWord_SubsysRanBC), 2,
    0, 1 },

  { (char_T *)(&Walking_ATRIAS_DW.CoreSubsys[18].UD_DSTATE), 0, 0, 6 }
};

/* data type transition table for block I/O structure */
static DataTypeTransitionTable rtBTransTable = {
  47U,
  rtBTransitions
};

/* data type transitions for Parameters structure */
static DataTypeTransition rtPTransitions[] = {
  { (char_T *)(&Walking_ATRIAS_P.Calibration), 15, 0, 1 },

  { (char_T *)(&Walking_ATRIAS_P.GearOffsets[0]), 0, 0, 432 },

  { (char_T *)(&Walking_ATRIAS_P.isSetHipConst), 8, 0, 6 }
};

/* data type transition table for Parameters structure */
static DataTypeTransitionTable rtPTransTable = {
  3U,
  rtPTransitions
};

/* [EOF] Walking_ATRIAS_dt.h */
