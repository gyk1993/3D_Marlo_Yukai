/*
 * Walking_ATRIAS_capi.c
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

#include "Walking_ATRIAS.h"
#include "rtw_capi.h"
#include "Walking_ATRIAS_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, "Data Type Conversion",
    "", 0, 0, 0, 0, 0 },

  { 1, 0, "Digital Clock",
    "", 0, 1, 0, 0, 0 },

  { 2, 0, "Gain1",
    "", 0, 1, 1, 0, 0 },

  { 3, 0, "rad2deg",
    "", 0, 1, 2, 0, 0 },

  { 4, 0, "Add",
    "", 0, 1, 1, 0, 0 },

  { 5, 0, "RoughTerrain1/Constant3",
    "", 0, 1, 3, 0, 0 },

  { 6, 0, "RoughTerrain1/Constant4",
    "", 0, 1, 4, 0, 0 },

  { 7, 0, "RoughTerrain1/Data Type Conversion",
    "", 0, 1, 0, 0, 0 },

  { 8, 0, "RoughTerrain1/Gain",
    "", 0, 1, 3, 0, 0 },

  { 9, 0, "RoughTerrain1/Gain1",
    "", 0, 1, 3, 0, 0 },

  { 10, 0, "RoughTerrain1/Gain2",
    "", 0, 1, 3, 0, 0 },

  { 11, 0, "RoughTerrain1/Reshape",
    "", 0, 1, 3, 0, 0 },

  { 12, 0, "RoughTerrain1/Reshape1",
    "", 0, 1, 5, 0, 0 },

  { 13, 0, "RoughTerrain1/Reshape3",
    "", 0, 1, 3, 0, 0 },

  { 14, 0, "RoughTerrain1/Reshape4",
    "", 0, 1, 3, 0, 0 },

  { 15, 1, "RoughTerrain1/Controller3/p1",
    "", 0, 0, 0, 0, 0 },

  { 16, 1, "RoughTerrain1/Controller3/p2",
    "", 1, 1, 6, 0, 0 },

  { 17, 1, "RoughTerrain1/Controller3/p3",
    "", 2, 1, 7, 0, 0 },

  { 18, 1, "RoughTerrain1/Controller3/p4",
    "", 3, 1, 8, 0, 0 },

  { 19, 1, "RoughTerrain1/Controller3/p5",
    "", 4, 1, 8, 0, 0 },

  { 20, 2, "Subsystem1/AdjustForCOMOffset",
    "q", 0, 1, 2, 0, 0 },

  { 21, 3, "Subsystem1/SAFETY/p1",
    "MotorCurrentCommandSafe", 0, 1, 3, 0, 0 },

  { 22, 3, "Subsystem1/SAFETY/p2",
    "MedullaCommandSafe", 1, 1, 0, 0, 0 },

  { 23, 3, "Subsystem1/SAFETY/p3",
    "SafetyState", 2, 1, 0, 0, 0 },

  { 24, 3, "Subsystem1/SAFETY/p4",
    "SafetyCountOut", 3, 1, 0, 0, 0 },

  { 25, 0, "Subsystem1/Constant2",
    "", 0, 1, 0, 0, 1 },

  { 26, 0, "Subsystem1/Gain",
    "", 0, 1, 0, 0, 1 },

  { 27, 0, "Subsystem1/TorqueToCurrent",
    "current_unsat", 0, 1, 3, 0, 0 },

  { 28, 0, "Subsystem1/Unit Delay",
    "", 0, 1, 0, 0, 0 },

  { 29, 0, "Subsystem1/Unit Delay1",
    "", 0, 1, 2, 0, 0 },

  { 30, 0, "Subsystem1/Unit Delay2",
    "", 0, 1, 2, 0, 0 },

  { 31, 0, "RoughTerrain1/Saturation/Data Type Conversion1",
    "torque_sat", 0, 1, 3, 0, 0 },

  { 32, 0, "RoughTerrain1/Saturation/Gain",
    "", 0, 1, 3, 0, 0 },

  { 33, 0, "RoughTerrain1/Saturation/Gain1",
    "", 0, 1, 3, 0, 0 },

  { 34, 0, "RoughTerrain1/TrackHold/Discrete-Time Integrator1",
    "", 0, 1, 0, 0, 0 },

  { 35, 0, "RoughTerrain1/TrackHold/Divide",
    "", 0, 1, 0, 0, 0 },

  { 36, 0, "RoughTerrain1/TrackHold/Switch",
    "", 0, 1, 0, 0, 0 },

  { 37, 0, "RoughTerrain1/TrackHold/Unit Delay",
    "", 0, 1, 0, 0, 0 },

  { 38, 0, "RoughTerrain1/UM2OSU Cooridnate Change/Gain",
    "", 0, 1, 2, 0, 0 },

  { 39, 0, "RoughTerrain1/UM2OSU Cooridnate Change/Add",
    "", 0, 1, 2, 0, 0 },

  { 40, 0, "RoughTerrain1/UM2OSU Cooridnate Change2/Gain",
    "", 0, 1, 2, 0, 0 },

  { 41, 0, "Subsystem1/Reset/Digital Clock",
    "", 0, 1, 0, 0, 0 },

  { 42, 0, "Subsystem1/Reset/Logical Operator",
    "", 0, 0, 0, 0, 0 },

  { 43, 0, "Subsystem1/Reset/Logical Operator1",
    "", 0, 0, 0, 0, 0 },

  { 44, 0, "Subsystem1/Reset/Logical Operator2",
    "", 0, 0, 0, 0, 0 },

  { 45, 0, "Subsystem1/Reset/Unit Delay",
    "", 0, 0, 0, 0, 0 },

  { 46, 0, "Subsystem1/Saturation Dynamic/LowerRelop1",
    "", 0, 0, 3, 0, 0 },

  { 47, 0, "Subsystem1/Saturation Dynamic/UpperRelop",
    "", 0, 0, 3, 0, 0 },

  { 48, 0, "Subsystem1/Saturation Dynamic/Switch",
    "", 0, 1, 3, 0, 0 },

  { 49, 0, "Subsystem1/Saturation Dynamic/Switch2",
    "", 0, 1, 3, 0, 0 },

  { 50, 4, "Subsystem1/StateEstimator/GeneralizedCoordinates/p1",
    "q_clean", 0, 1, 2, 0, 0 },

  { 51, 4, "Subsystem1/StateEstimator/GeneralizedCoordinates/p2",
    "dq_clean", 1, 1, 2, 0, 0 },

  { 52, 5, "Subsystem1/Subsystem/ComputeEulerAngles1/p1",
    "ZYX", 0, 1, 9, 0, 0 },

  { 53, 5, "Subsystem1/Subsystem/ComputeEulerAngles1/p2",
    "dZYX", 1, 1, 9, 0, 0 },

  { 54, 5, "Subsystem1/Subsystem/ComputeEulerAngles1/p3",
    "Rk", 2, 1, 10, 0, 0 },

  { 55, 5, "Subsystem1/Subsystem/ComputeEulerAngles1/p4",
    "R0", 3, 1, 10, 0, 0 },

  { 56, 5, "Subsystem1/Subsystem/ComputeEulerAngles1/p5",
    "YawRollover", 4, 1, 11, 0, 0 },

  { 57, 9, "Subsystem1/Subsystem/EstimateOrientation/p1",
    "Rk", 0, 1, 10, 0, 0 },

  { 58, 9, "Subsystem1/Subsystem/EstimateOrientation/p2",
    "wk", 1, 1, 9, 0, 0 },

  { 59, 9, "Subsystem1/Subsystem/EstimateOrientation/p3",
    "Ak", 2, 1, 9, 0, 0 },

  { 60, 9, "Subsystem1/Subsystem/EstimateOrientation/p4",
    "Seqk", 3, 1, 0, 0, 0 },

  { 61, 9, "Subsystem1/Subsystem/EstimateOrientation/p5",
    "ValidStates", 4, 0, 9, 0, 0 },

  { 62, 39, "Subsystem1/Subsystem/ZeroingLegs",
    "u_zeroed", 0, 1, 3, 0, 0 },

  { 63, 0, "Subsystem1/Subsystem/calibrate/p1",
    "", 0, 1, 12, 0, 0 },

  { 64, 0, "Subsystem1/Subsystem/calibrate/p2",
    "", 1, 1, 12, 0, 0 },

  { 65, 40, "Subsystem1/Subsystem/calibrate/p3",
    "Rollover", 2, 1, 13, 0, 0 },

  { 66, 40, "Subsystem1/Subsystem/calibrate/p4",
    "IncCalTick", 3, 1, 3, 0, 0 },

  { 67, 41, "Subsystem1/Subsystem/convert_mtr_current_to_pwm",
    "y", 0, 1, 3, 0, 0 },

  { 68, 0, "Subsystem1/Subsystem/Vector Concatenate",
    "", 0, 1, 12, 0, 0 },

  { 69, 0, "Subsystem1/Subsystem/Data Type Conversion7",
    "", 0, 1, 9, 0, 0 },

  { 70, 0, "Subsystem1/Subsystem/Reshape3",
    "", 0, 1, 13, 0, 0 },

  { 71, 0, "Subsystem1/Subsystem/Current Saturation",
    "", 0, 1, 3, 0, 0 },

  { 72, 0, "Subsystem1/Subsystem/Unit Delay",
    "", 0, 1, 13, 0, 0 },

  { 73, 0, "Subsystem1/Subsystem/Unit Delay1",
    "", 0, 1, 13, 0, 0 },

  { 74, 0, "Subsystem1/Subsystem/Unit Delay10",
    "", 0, 1, 10, 0, 0 },

  { 75, 0, "Subsystem1/Subsystem/Unit Delay2",
    "", 0, 1, 3, 0, 0 },

  { 76, 0, "Subsystem1/Subsystem/Unit Delay5",
    "", 0, 1, 9, 0, 0 },

  { 77, 0, "Subsystem1/Subsystem/Unit Delay6",
    "", 0, 1, 10, 0, 0 },

  { 78, 0, "Subsystem1/Subsystem/Unit Delay7",
    "", 0, 1, 9, 0, 0 },

  { 79, 0, "Subsystem1/Subsystem/Unit Delay8",
    "", 0, 1, 0, 0, 0 },

  { 80, 0, "Subsystem1/Subsystem/Unit Delay9",
    "", 0, 1, 11, 0, 0 },

  { 81, 0, "RoughTerrain1/Saturation/Saturation Dynamic/LowerRelop1",
    "", 0, 0, 3, 0, 0 },

  { 82, 0, "RoughTerrain1/Saturation/Saturation Dynamic/UpperRelop",
    "", 0, 0, 3, 0, 0 },

  { 83, 0, "RoughTerrain1/Saturation/Saturation Dynamic/Switch",
    "", 0, 1, 3, 0, 0 },

  { 84, 0, "RoughTerrain1/Saturation/Saturation Dynamic/Switch2",
    "", 0, 1, 3, 0, 0 },

  { 85, 0, "RoughTerrain1/TrackHold/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 86, 0, "Subsystem1/Reset/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 87, 0, "Subsystem1/Reset/Compare To Constant1/Compare",
    "", 0, 0, 0, 0, 0 },

  { 88, 10, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/ConvertAmpCurrent",
    "measuredCurrent", 0, 1, 14, 0, 0 },

  { 89, 11, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/ConvertLogicVoltage",
    "logicVoltage", 0, 1, 3, 0, 0 },

  { 90, 12, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/ConvertMotorVoltage",
    "motorVoltage", 0, 1, 3, 0, 0 },

  { 91, 13, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/ConvertThermistors",
    "Temperatures", 0, 1, 15, 0, 0 },

  { 92, 14, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/EncodeSwitches",
    "LimitSwitchesEncoded", 0, 1, 0, 0, 0 },

  { 93, 0, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion1",
    "", 0, 1, 0, 0, 0 },

  { 94, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion10",
    "", 0, 1, 0, 0, 0 },

  { 95, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion101",
    "", 0, 1, 0, 0, 0 },

  { 96, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion102",
    "", 0, 1, 9, 0, 0 },

  { 97, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion103",
    "", 0, 1, 0, 0, 0 },

  { 98, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion104",
    "", 0, 1, 0, 0, 0 },

  { 99, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion105",
    "", 0, 1, 0, 0, 0 },

  { 100, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion106",
    "", 0, 1, 0, 0, 0 },

  { 101, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion107",
    "", 0, 1, 0, 0, 0 },

  { 102, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion108",
    "", 0, 1, 0, 0, 0 },

  { 103, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion109",
    "", 0, 1, 0, 0, 0 },

  { 104, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion11",
    "", 0, 1, 0, 0, 0 },

  { 105, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion110",
    "", 0, 1, 0, 0, 0 },

  { 106, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion111",
    "", 0, 1, 0, 0, 0 },

  { 107, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion112",
    "", 0, 1, 0, 0, 0 },

  { 108, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion114",
    "", 0, 1, 0, 0, 0 },

  { 109, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion116",
    "", 0, 1, 0, 0, 0 },

  { 110, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion117",
    "", 0, 1, 9, 0, 0 },

  { 111, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion118",
    "", 0, 1, 0, 0, 0 },

  { 112, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion119",
    "", 0, 1, 0, 0, 0 },

  { 113, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion12",
    "", 0, 1, 0, 0, 0 },

  { 114, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion120",
    "", 0, 1, 0, 0, 0 },

  { 115, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion121",
    "", 0, 1, 0, 0, 0 },

  { 116, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion122",
    "", 0, 1, 0, 0, 0 },

  { 117, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion123",
    "", 0, 1, 0, 0, 0 },

  { 118, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion124",
    "", 0, 1, 0, 0, 0 },

  { 119, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion125",
    "", 0, 1, 0, 0, 0 },

  { 120, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion126",
    "", 0, 1, 0, 0, 0 },

  { 121, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion13",
    "", 0, 1, 0, 0, 0 },

  { 122, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion14",
    "", 0, 1, 0, 0, 0 },

  { 123, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion141",
    "", 0, 1, 9, 0, 1 },

  { 124, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion15",
    "", 0, 1, 3, 0, 0 },

  { 125, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion157",
    "", 0, 1, 0, 0, 0 },

  { 126, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion16",
    "", 0, 1, 0, 0, 0 },

  { 127, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion17",
    "", 0, 1, 0, 0, 0 },

  { 128, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion18",
    "", 0, 1, 0, 0, 0 },

  { 129, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion19",
    "", 0, 1, 0, 0, 0 },

  { 130, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion2",
    "", 0, 1, 0, 0, 0 },

  { 131, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion20",
    "", 0, 1, 9, 0, 0 },

  { 132, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion21",
    "", 0, 1, 11, 0, 0 },

  { 133, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion22",
    "", 0, 1, 9, 0, 0 },

  { 134, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion23",
    "", 0, 1, 11, 0, 0 },

  { 135, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion24",
    "", 0, 1, 0, 0, 0 },

  { 136, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion25",
    "", 0, 1, 0, 0, 0 },

  { 137, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion26",
    "", 0, 1, 0, 0, 0 },

  { 138, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion27",
    "", 0, 1, 0, 0, 0 },

  { 139, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion28",
    "", 0, 1, 0, 0, 0 },

  { 140, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion29",
    "", 0, 1, 0, 0, 0 },

  { 141, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion3",
    "", 0, 1, 0, 0, 0 },

  { 142, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion30",
    "", 0, 1, 0, 0, 0 },

  { 143, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion31",
    "", 0, 1, 0, 0, 0 },

  { 144, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion32",
    "", 0, 1, 0, 0, 0 },

  { 145, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion33",
    "", 0, 1, 0, 0, 0 },

  { 146, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion34",
    "", 0, 1, 0, 0, 0 },

  { 147, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion35",
    "", 0, 1, 0, 0, 0 },

  { 148, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion36",
    "", 0, 1, 0, 0, 0 },

  { 149, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion37",
    "", 0, 1, 0, 0, 0 },

  { 150, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion38",
    "", 0, 1, 0, 0, 0 },

  { 151, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion39",
    "", 0, 1, 3, 0, 0 },

  { 152, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion4",
    "", 0, 1, 0, 0, 0 },

  { 153, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion45",
    "", 0, 1, 11, 0, 0 },

  { 154, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion47",
    "", 0, 1, 11, 0, 0 },

  { 155, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion49",
    "", 0, 1, 0, 0, 0 },

  { 156, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion5",
    "", 0, 1, 0, 0, 0 },

  { 157, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion50",
    "", 0, 1, 0, 0, 0 },

  { 158, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion51",
    "", 0, 1, 0, 0, 0 },

  { 159, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion52",
    "", 0, 1, 0, 0, 0 },

  { 160, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion53",
    "", 0, 1, 0, 0, 0 },

  { 161, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion54",
    "", 0, 1, 0, 0, 0 },

  { 162, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion55",
    "", 0, 1, 0, 0, 0 },

  { 163, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion56",
    "", 0, 1, 0, 0, 0 },

  { 164, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion57",
    "", 0, 1, 0, 0, 0 },

  { 165, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion58",
    "", 0, 1, 0, 0, 0 },

  { 166, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion59",
    "", 0, 1, 0, 0, 0 },

  { 167, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion6",
    "", 0, 1, 0, 0, 0 },

  { 168, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion60",
    "", 0, 1, 0, 0, 0 },

  { 169, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion61",
    "", 0, 1, 0, 0, 0 },

  { 170, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion62",
    "", 0, 1, 0, 0, 0 },

  { 171, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion63",
    "", 0, 1, 3, 0, 0 },

  { 172, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion69",
    "", 0, 1, 11, 0, 0 },

  { 173, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion7",
    "", 0, 1, 0, 0, 0 },

  { 174, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion71",
    "", 0, 1, 11, 0, 0 },

  { 175, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion73",
    "", 0, 1, 0, 0, 0 },

  { 176, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion74",
    "", 0, 1, 0, 0, 0 },

  { 177, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion75",
    "", 0, 1, 0, 0, 0 },

  { 178, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion76",
    "", 0, 1, 0, 0, 0 },

  { 179, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion77",
    "", 0, 1, 0, 0, 0 },

  { 180, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion78",
    "", 0, 1, 0, 0, 0 },

  { 181, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion79",
    "", 0, 1, 0, 0, 0 },

  { 182, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion8",
    "", 0, 1, 0, 0, 0 },

  { 183, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion80",
    "", 0, 1, 0, 0, 0 },

  { 184, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion81",
    "", 0, 1, 0, 0, 0 },

  { 185, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion82",
    "", 0, 1, 0, 0, 0 },

  { 186, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion83",
    "", 0, 1, 0, 0, 0 },

  { 187, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion84",
    "", 0, 1, 0, 0, 0 },

  { 188, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion85",
    "", 0, 1, 0, 0, 0 },

  { 189, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion86",
    "", 0, 1, 0, 0, 0 },

  { 190, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion87",
    "", 0, 1, 3, 0, 0 },

  { 191, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion9",
    "", 0, 1, 0, 0, 0 },

  { 192, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion93",
    "", 0, 1, 11, 0, 0 },

  { 193, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion95",
    "", 0, 1, 11, 0, 0 },

  { 194, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion97",
    "", 0, 1, 3, 0, 0 },

  { 195, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Data Type Conversion98",
    "", 0, 1, 0, 0, 0 },

  { 196, 0, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Make3x1",
    "", 0, 1, 9, 0, 1 },

  { 197, 0, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Counter/p1",
    "", 0, 1, 0, 0, 0 },

  { 198, 0, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/Counter/p2",
    "", 1, 1, 0, 0, 0 },

  { 199, 0, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/EtherCAT Init ",
    "", 0, 2, 3, 0, 0 },

  { 200, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/Data Type Conversion3",
    "", 0, 3, 0, 0, 0 },

  { 201, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/Data Type Conversion4",
    "", 0, 4, 0, 0, 0 },

  { 202, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/Data Type Conversion5",
    "", 0, 2, 0, 0, 0 },

  { 203, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var ",
    "", 0, 5, 0, 0, 0 },

  { 204, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 1",
    "", 0, 4, 0, 0, 0 },

  { 205, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 12",
    "", 0, 4, 0, 0, 0 },

  { 206, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 13",
    "", 0, 4, 0, 0, 0 },

  { 207, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 14",
    "", 0, 4, 0, 0, 0 },

  { 208, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 15",
    "", 0, 3, 0, 0, 0 },

  { 209, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 16",
    "", 0, 3, 0, 0, 0 },

  { 210, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 17",
    "", 0, 3, 0, 0, 0 },

  { 211, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 18",
    "", 0, 3, 0, 0, 0 },

  { 212, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 19",
    "", 0, 3, 0, 0, 0 },

  { 213, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 2",
    "", 0, 4, 0, 0, 0 },

  { 214, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 3",
    "", 0, 4, 0, 0, 0 },

  { 215, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 4",
    "", 0, 6, 0, 0, 0 },

  { 216, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 5",
    "", 0, 4, 0, 0, 0 },

  { 217, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 6",
    "", 0, 4, 0, 0, 0 },

  { 218, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/Data Type Conversion3",
    "", 0, 3, 0, 0, 0 },

  { 219, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/Data Type Conversion4",
    "", 0, 4, 0, 0, 0 },

  { 220, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/Data Type Conversion5",
    "", 0, 2, 0, 0, 0 },

  { 221, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var ",
    "", 0, 5, 0, 0, 0 },

  { 222, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 1",
    "", 0, 4, 0, 0, 0 },

  { 223, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 12",
    "", 0, 4, 0, 0, 0 },

  { 224, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 13",
    "", 0, 4, 0, 0, 0 },

  { 225, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 14",
    "", 0, 4, 0, 0, 0 },

  { 226, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 15",
    "", 0, 3, 0, 0, 0 },

  { 227, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 16",
    "", 0, 3, 0, 0, 0 },

  { 228, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 17",
    "", 0, 3, 0, 0, 0 },

  { 229, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 18",
    "", 0, 3, 0, 0, 0 },

  { 230, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 19",
    "", 0, 3, 0, 0, 0 },

  { 231, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 2",
    "", 0, 4, 0, 0, 0 },

  { 232, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 3",
    "", 0, 4, 0, 0, 0 },

  { 233, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 4",
    "", 0, 6, 0, 0, 0 },

  { 234, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 5",
    "", 0, 4, 0, 0, 0 },

  { 235, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 6",
    "", 0, 4, 0, 0, 0 },

  { 236, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/Data Type Conversion3",
    "", 0, 3, 0, 0, 0 },

  { 237, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/Data Type Conversion4",
    "", 0, 4, 0, 0, 0 },

  { 238, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 1",
    "", 0, 7, 0, 0, 0 },

  { 239, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 11",
    "", 0, 7, 0, 0, 0 },

  { 240, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 12",
    "", 0, 7, 0, 0, 0 },

  { 241, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 15",
    "", 0, 3, 0, 0, 0 },

  { 242, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 16",
    "", 0, 3, 0, 0, 0 },

  { 243, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 17",
    "", 0, 3, 0, 0, 0 },

  { 244, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 18",
    "", 0, 3, 0, 0, 0 },

  { 245, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 2",
    "", 0, 7, 0, 0, 0 },

  { 246, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 3",
    "", 0, 3, 0, 0, 0 },

  { 247, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 4",
    "", 0, 5, 0, 0, 0 },

  { 248, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 5",
    "", 0, 3, 0, 0, 0 },

  { 249, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 6",
    "", 0, 7, 0, 0, 0 },

  { 250, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 9",
    "", 0, 7, 0, 0, 0 },

  { 251, 16, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Chart/p1",
    "ControlWordIndex", 0, 1, 0, 0, 0 },

  { 252, 16, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Chart/p2",
    "EnableTargetTorque", 1, 1, 0, 0, 0 },

  { 253, 16, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Chart/p3",
    "FaultDetected", 2, 1, 0, 0, 0 },

  { 254, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Data Type Conversion2",
    "", 0, 1, 11, 0, 0 },

  { 255, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Data Type Conversion20",
    "", 0, 1, 0, 0, 0 },

  { 256, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Data Type Conversion42",
    "", 0, 1, 0, 0, 0 },

  { 257, 0, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Switch",
    "", 0, 5, 0, 0, 0 },

  { 258, 22, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Chart/p1",
    "ControlWordIndex", 0, 1, 0, 0, 0 },

  { 259, 22, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Chart/p2",
    "EnableTargetTorque", 1, 1, 0, 0, 0 },

  { 260, 22, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Chart/p3",
    "FaultDetected", 2, 1, 0, 0, 0 },

  { 261, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Data Type Conversion20",
    "", 0, 1, 0, 0, 0 },

  { 262, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Data Type Conversion3",
    "", 0, 1, 11, 0, 0 },

  { 263, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Data Type Conversion42",
    "", 0, 1, 0, 0, 0 },

  { 264, 0, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Switch",
    "", 0, 5, 0, 0, 0 },

  { 265, 28, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Chart/p1",
    "ControlWordIndex", 0, 1, 0, 0, 0 },

  { 266, 28, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Chart/p2",
    "EnableTargetTorque", 1, 1, 0, 0, 0 },

  { 267, 28, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Chart/p3",
    "FaultDetected", 2, 1, 0, 0, 0 },

  { 268, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Data Type Conversion2",
    "", 0, 1, 11, 0, 0 },

  { 269, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Data Type Conversion20",
    "", 0, 1, 0, 0, 0 },

  { 270, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Data Type Conversion42",
    "", 0, 1, 0, 0, 0 },

  { 271, 0, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Switch",
    "", 0, 5, 0, 0, 0 },

  { 272, 34, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Chart/p1",
    "ControlWordIndex", 0, 1, 0, 0, 0 },

  { 273, 34, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Chart/p2",
    "EnableTargetTorque", 1, 1, 0, 0, 0 },

  { 274, 34, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Chart/p3",
    "FaultDetected", 2, 1, 0, 0, 0 },

  { 275, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Data Type Conversion2",
    "", 0, 1, 11, 0, 0 },

  { 276, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Data Type Conversion20",
    "", 0, 1, 0, 0, 0 },

  { 277, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Data Type Conversion42",
    "", 0, 1, 0, 0, 0 },

  { 278, 0, "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Switch",
    "", 0, 5, 0, 0, 0 },

  { 279, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/Data Type Conversion3",
    "", 0, 3, 0, 0, 0 },

  { 280, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/Data Type Conversion4",
    "", 0, 4, 0, 0, 0 },

  { 281, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/Data Type Conversion5",
    "", 0, 2, 0, 0, 0 },

  { 282, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var ",
    "", 0, 4, 0, 0, 0 },

  { 283, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 1",
    "", 0, 4, 0, 0, 0 },

  { 284, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 10",
    "", 0, 4, 0, 0, 0 },

  { 285, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 11",
    "", 0, 4, 0, 0, 0 },

  { 286, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 12",
    "", 0, 4, 0, 0, 0 },

  { 287, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 13",
    "", 0, 4, 0, 0, 0 },

  { 288, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 14",
    "", 0, 4, 0, 0, 0 },

  { 289, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 15",
    "", 0, 4, 0, 0, 0 },

  { 290, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 16",
    "", 0, 4, 0, 0, 0 },

  { 291, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 17",
    "", 0, 4, 0, 0, 0 },

  { 292, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 18",
    "", 0, 3, 0, 0, 0 },

  { 293, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 19",
    "", 0, 3, 0, 0, 0 },

  { 294, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 2",
    "", 0, 4, 0, 0, 0 },

  { 295, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 20",
    "", 0, 3, 0, 0, 0 },

  { 296, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 21",
    "", 0, 3, 0, 0, 0 },

  { 297, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 22",
    "", 0, 3, 0, 0, 0 },

  { 298, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 23",
    "", 0, 4, 0, 0, 0 },

  { 299, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 3",
    "", 0, 4, 0, 0, 0 },

  { 300, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 4",
    "", 0, 6, 0, 0, 0 },

  { 301, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 5",
    "", 0, 4, 0, 0, 0 },

  { 302, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 6",
    "", 0, 5, 0, 0, 0 },

  { 303, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 7",
    "", 0, 5, 0, 0, 0 },

  { 304, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 8",
    "", 0, 6, 0, 0, 0 },

  { 305, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 9",
    "", 0, 4, 0, 0, 0 },

  { 306, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/Data Type Conversion3",
    "", 0, 3, 0, 0, 0 },

  { 307, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/Data Type Conversion4",
    "", 0, 4, 0, 0, 0 },

  { 308, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/Data Type Conversion5",
    "", 0, 2, 0, 0, 0 },

  { 309, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var ",
    "", 0, 4, 0, 0, 0 },

  { 310, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 1",
    "", 0, 4, 0, 0, 0 },

  { 311, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 10",
    "", 0, 4, 0, 0, 0 },

  { 312, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 11",
    "", 0, 4, 0, 0, 0 },

  { 313, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 12",
    "", 0, 4, 0, 0, 0 },

  { 314, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 13",
    "", 0, 4, 0, 0, 0 },

  { 315, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 14",
    "", 0, 4, 0, 0, 0 },

  { 316, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 15",
    "", 0, 4, 0, 0, 0 },

  { 317, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 16",
    "", 0, 4, 0, 0, 0 },

  { 318, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 17",
    "", 0, 4, 0, 0, 0 },

  { 319, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 18",
    "", 0, 3, 0, 0, 0 },

  { 320, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 19",
    "", 0, 3, 0, 0, 0 },

  { 321, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 2",
    "", 0, 4, 0, 0, 0 },

  { 322, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 20",
    "", 0, 3, 0, 0, 0 },

  { 323, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 21",
    "", 0, 3, 0, 0, 0 },

  { 324, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 22",
    "", 0, 3, 0, 0, 0 },

  { 325, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 23",
    "", 0, 4, 0, 0, 0 },

  { 326, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 3",
    "", 0, 4, 0, 0, 0 },

  { 327, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 4",
    "", 0, 6, 0, 0, 0 },

  { 328, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 5",
    "", 0, 4, 0, 0, 0 },

  { 329, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 6",
    "", 0, 5, 0, 0, 0 },

  { 330, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 7",
    "", 0, 5, 0, 0, 0 },

  { 331, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 8",
    "", 0, 6, 0, 0, 0 },

  { 332, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 9",
    "", 0, 4, 0, 0, 0 },

  { 333, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/Data Type Conversion3",
    "", 0, 3, 0, 0, 0 },

  { 334, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/Data Type Conversion4",
    "", 0, 4, 0, 0, 0 },

  { 335, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/Data Type Conversion5",
    "", 0, 2, 0, 0, 0 },

  { 336, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var ",
    "", 0, 4, 0, 0, 0 },

  { 337, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 1",
    "", 0, 4, 0, 0, 0 },

  { 338, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 10",
    "", 0, 4, 0, 0, 0 },

  { 339, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 11",
    "", 0, 4, 0, 0, 0 },

  { 340, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 12",
    "", 0, 4, 0, 0, 0 },

  { 341, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 13",
    "", 0, 4, 0, 0, 0 },

  { 342, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 14",
    "", 0, 4, 0, 0, 0 },

  { 343, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 15",
    "", 0, 4, 0, 0, 0 },

  { 344, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 16",
    "", 0, 4, 0, 0, 0 },

  { 345, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 17",
    "", 0, 4, 0, 0, 0 },

  { 346, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 18",
    "", 0, 3, 0, 0, 0 },

  { 347, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 19",
    "", 0, 3, 0, 0, 0 },

  { 348, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 2",
    "", 0, 4, 0, 0, 0 },

  { 349, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 20",
    "", 0, 3, 0, 0, 0 },

  { 350, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 21",
    "", 0, 3, 0, 0, 0 },

  { 351, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 22",
    "", 0, 3, 0, 0, 0 },

  { 352, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 23",
    "", 0, 4, 0, 0, 0 },

  { 353, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 3",
    "", 0, 4, 0, 0, 0 },

  { 354, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 4",
    "", 0, 6, 0, 0, 0 },

  { 355, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 5",
    "", 0, 4, 0, 0, 0 },

  { 356, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 6",
    "", 0, 5, 0, 0, 0 },

  { 357, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 7",
    "", 0, 5, 0, 0, 0 },

  { 358, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 8",
    "", 0, 6, 0, 0, 0 },

  { 359, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 9",
    "", 0, 4, 0, 0, 0 },

  { 360, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/Data Type Conversion3",
    "", 0, 3, 0, 0, 0 },

  { 361, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/Data Type Conversion4",
    "", 0, 4, 0, 0, 0 },

  { 362, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/Data Type Conversion5",
    "", 0, 2, 0, 0, 0 },

  { 363, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var ",
    "", 0, 4, 0, 0, 0 },

  { 364, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 1",
    "", 0, 4, 0, 0, 0 },

  { 365, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 10",
    "", 0, 4, 0, 0, 0 },

  { 366, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 11",
    "", 0, 4, 0, 0, 0 },

  { 367, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 12",
    "", 0, 4, 0, 0, 0 },

  { 368, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 13",
    "", 0, 4, 0, 0, 0 },

  { 369, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 14",
    "", 0, 4, 0, 0, 0 },

  { 370, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 15",
    "", 0, 4, 0, 0, 0 },

  { 371, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 16",
    "", 0, 4, 0, 0, 0 },

  { 372, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 17",
    "", 0, 4, 0, 0, 0 },

  { 373, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 18",
    "", 0, 3, 0, 0, 0 },

  { 374, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 19",
    "", 0, 3, 0, 0, 0 },

  { 375, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 2",
    "", 0, 4, 0, 0, 0 },

  { 376, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 20",
    "", 0, 3, 0, 0, 0 },

  { 377, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 21",
    "", 0, 3, 0, 0, 0 },

  { 378, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 22",
    "", 0, 3, 0, 0, 0 },

  { 379, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 23",
    "", 0, 4, 0, 0, 0 },

  { 380, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 3",
    "", 0, 4, 0, 0, 0 },

  { 381, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 4",
    "", 0, 6, 0, 0, 0 },

  { 382, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 5",
    "", 0, 4, 0, 0, 0 },

  { 383, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 6",
    "", 0, 5, 0, 0, 0 },

  { 384, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 7",
    "", 0, 5, 0, 0, 0 },

  { 385, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 8",
    "", 0, 6, 0, 0, 0 },

  { 386, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 9",
    "", 0, 4, 0, 0, 0 },

  { 387, 6,
    "Subsystem1/Subsystem/EncoderFilters1/CheckAndFilterEncoder/Velocity Filter/Logic Filter/p1",
    "dq_out", 0, 1, 0, 0, 0 },

  { 388, 6,
    "Subsystem1/Subsystem/EncoderFilters1/CheckAndFilterEncoder/Velocity Filter/Logic Filter/p2",
    "dq_good", 1, 1, 0, 0, 0 },

  { 389, 7,
    "Subsystem1/Subsystem/EncoderFilters1/CheckAndFilterEncoder/Velocity Filter/Unit Delay1",
    "", 0, 1, 0, 0, 0 },

  { 390, 7,
    "Subsystem1/Subsystem/EncoderFilters1/CheckAndFilterEncoder/Velocity Filter/Unit Delay2",
    "", 0, 1, 0, 0, 0 },

  { 391, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive",
    "", 0, 5, 0, 0, 0 },

  { 392, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive1",
    "", 0, 2, 0, 0, 0 },

  { 393, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive2",
    "", 0, 8, 0, 0, 0 },

  { 394, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive5",
    "", 0, 4, 0, 0, 0 },

  { 395, 15,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem/Vector Concatenate",
    "", 0, 1, 11, 0, 0 },

  { 396, 15,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem/Data Type Conversion6",
    "", 0, 5, 0, 0, 0 },

  { 397, 15,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem/Fcn",
    "", 0, 1, 0, 0, 0 },

  { 398, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem1/Merge",
    "", 0, 4, 0, 0, 0 },

  { 399, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem2/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 400, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem3/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 401, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem4/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 402, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem5/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 403, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem6/Vector Concatenate",
    "", 0, 1, 11, 0, 0 },

  { 404, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem6/Fcn",
    "", 0, 1, 0, 0, 0 },

  { 405, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive",
    "", 0, 5, 0, 0, 0 },

  { 406, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive1",
    "", 0, 2, 0, 0, 0 },

  { 407, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive2",
    "", 0, 8, 0, 0, 0 },

  { 408, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive5",
    "", 0, 4, 0, 0, 0 },

  { 409, 21,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem/Vector Concatenate",
    "", 0, 1, 11, 0, 0 },

  { 410, 21,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem/Data Type Conversion6",
    "", 0, 5, 0, 0, 0 },

  { 411, 21,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem/Fcn",
    "", 0, 1, 0, 0, 0 },

  { 412, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem1/Merge",
    "", 0, 4, 0, 0, 0 },

  { 413, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem2/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 414, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem3/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 415, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem4/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 416, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem5/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 417, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem6/Vector Concatenate",
    "", 0, 1, 11, 0, 0 },

  { 418, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem6/Fcn",
    "", 0, 1, 0, 0, 0 },

  { 419, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive",
    "", 0, 5, 0, 0, 0 },

  { 420, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive1",
    "", 0, 2, 0, 0, 0 },

  { 421, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive2",
    "", 0, 8, 0, 0, 0 },

  { 422, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive5",
    "", 0, 4, 0, 0, 0 },

  { 423, 27,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem/Vector Concatenate",
    "", 0, 1, 11, 0, 0 },

  { 424, 27,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem/Data Type Conversion6",
    "", 0, 5, 0, 0, 0 },

  { 425, 27,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem/Fcn",
    "", 0, 1, 0, 0, 0 },

  { 426, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem1/Merge",
    "", 0, 4, 0, 0, 0 },

  { 427, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem2/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 428, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem3/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 429, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem4/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 430, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem5/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 431, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem6/Vector Concatenate",
    "", 0, 1, 11, 0, 0 },

  { 432, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem6/Fcn",
    "", 0, 1, 0, 0, 0 },

  { 433, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive",
    "", 0, 5, 0, 0, 0 },

  { 434, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive1",
    "", 0, 2, 0, 0, 0 },

  { 435, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive3",
    "", 0, 8, 0, 0, 0 },

  { 436, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive5",
    "", 0, 4, 0, 0, 0 },

  { 437, 33,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem/Vector Concatenate",
    "", 0, 1, 11, 0, 0 },

  { 438, 33,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem/Data Type Conversion6",
    "", 0, 5, 0, 0, 0 },

  { 439, 33,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem/Fcn",
    "", 0, 1, 0, 0, 0 },

  { 440, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem1/Merge",
    "", 0, 4, 0, 0, 0 },

  { 441, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem2/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 442, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem3/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 443, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem4/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 444, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem5/Bitwise Operator",
    "", 0, 4, 0, 0, 0 },

  { 445, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem6/Vector Concatenate",
    "", 0, 1, 11, 0, 0 },

  { 446, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem6/Fcn",
    "", 0, 1, 0, 0, 0 },

  { 447, 7,
    "Subsystem1/Subsystem/EncoderFilters1/CheckAndFilterEncoder/Velocity Filter/OSU_filter/Gain1",
    "", 0, 1, 0, 0, 0 },

  { 448, 7,
    "Subsystem1/Subsystem/EncoderFilters1/CheckAndFilterEncoder/Velocity Filter/OSU_filter/two_pole_filter",
    "", 0, 1, 0, 0, 0 },

  { 449, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem2/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 450, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem3/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 451, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem4/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 452, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem5/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 453, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem2/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 454, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem3/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 455, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem4/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 456, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem5/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 457, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem2/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 458, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem3/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 459, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem4/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 460, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem5/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 461, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem2/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 462, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem3/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 463, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem4/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 464, 0,
    "Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem5/Compare To Constant/Compare",
    "", 0, 0, 0, 0, 0 },

  { 465, 7,
    "Subsystem1/Subsystem/EncoderFilters1/CheckAndFilterEncoder/Velocity Filter/OSU_filter/difference/Diff",
    "", 0, 1, 0, 0, 0 },

  { 466, 7,
    "Subsystem1/Subsystem/EncoderFilters1/CheckAndFilterEncoder/Velocity Filter/OSU_filter/difference/UD",
    "U(k-1)", 0, 1, 0, 0, 0 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

/* Individual block tuning is not valid when inline parameters is *
 * selected. An empty map is produced to provide a consistent     *
 * interface independent  of inlining parameters.                 *
 */
static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  {
    0, NULL, NULL, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */

  //----skip

  //----skip

  //-----
  { 467, "GearOffsets", 1, 1, 0 },

  //----skip

  //-----
  { 468, "IMUTorsoOffsets", 1, 11, 0 },

  //----skip

  //-----
  { 469, "LegHipTorqueLimit", 1, 11, 0 },

  //----skip

  //-----
  { 470, "MedullaCommand", 1, 0, 0 },

  //----skip

  //-----
  { 471, "TorsoCOMOffsets", 1, 11, 0 },

  //----skip

  //-----
  { 472, "dx_err_d_gain", 1, 0, 0 },

  //----skip

  //-----
  { 473, "dx_err_p_gain", 1, 0, 0 },

  //----skip

  //-----
  { 474, "dx_gain", 1, 0, 0 },

  //----skip

  //-----
  { 475, "dy_err_d_gain", 1, 0, 0 },

  //----skip

  //-----
  { 476, "dy_err_p_gain", 1, 0, 0 },

  //----skip

  //-----
  { 477, "dy_gain", 1, 0, 0 },

  //----skip

  //-----
  { 478, "hAlphaSet", 1, 16, 0 },

  //----skip

  //-----
  { 479, "hip_gain", 1, 0, 0 },

  //----skip

  //-----
  { 480, "hip_offset", 1, 0, 0 },

  //----skip

  //-----
  { 481, "isTrackHold", 1, 0, 0 },

  //----skip

  //-----
  { 482, "kd_hip", 1, 0, 0 },

  //----skip

  //-----
  { 483, "kd_st_leg", 1, 0, 0 },

  //----skip

  //-----
  { 484, "kd_sw_leg", 1, 0, 0 },

  //----skip

  //-----
  { 485, "kd_vs", 1, 0, 0 },

  //----skip

  //-----
  { 486, "kd_yaw", 1, 0, 0 },

  //----skip

  //-----
  { 487, "kp_hip", 1, 0, 0 },

  //----skip

  //-----
  { 488, "kp_st_leg", 1, 0, 0 },

  //----skip

  //-----
  { 489, "kp_sw_leg", 1, 0, 0 },

  //----skip

  //-----
  { 490, "kp_vs", 1, 0, 0 },

  //----skip

  //-----
  { 491, "kp_yaw", 1, 0, 0 },

  //----skip

  //-----
  { 492, "lbForce", 1, 0, 0 },

  //----skip

  //-----
  { 493, "ps3Axes", 1, 17, 0 },

  //----skip

  //-----
  { 494, "ps3Buttons", 1, 18, 0 },

  //----skip

  //-----
  { 495, "ps3Pov", 1, 0, 0 },

  //----skip

  //-----
  { 496, "step_gain", 1, 0, 0 },

  //----skip

  //-----
  { 497, "t0_step", 1, 0, 0 },

  //----skip

  //-----
  { 498, "theta_limits_norm", 1, 19, 0 },

  //----skip

  //-----
  { 499, "uHipGravity", 1, 0, 0 },

  //----skip

  //-----
  { 500, "ubForce", 1, 0, 0 },

  //----skip

  //-----
  { 501, "velFilConst", 1, 0, 0 },

  //----skip

  //-----
  { 502, "isSetHipConst", 0, 0, 0 },

  //----skip

  //-----
  { 503, "isSim", 0, 0, 0 },

  //----skip

  //-----
  { 504, "isTestGravity", 0, 0, 0 },

  //----skip

  //-----
  { 505, "isTestHipTrack", 0, 0, 0 },

  //----skip

  //-----
  { 506, "isVCtracking", 0, 0, 0 },

  //----skip

  //-----
  { 507, "isVirtualConstraint", 0, 0, 0 },

  { 0, NULL, 0, 0, 0 }
};

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &Walking_ATRIAS_B.DataTypeConversion_h,/* 0: Signal */
  &Walking_ATRIAS_B.DigitalClock,      /* 1: Signal */
  &Walking_ATRIAS_B.Gain1_o[0],        /* 2: Signal */
  &Walking_ATRIAS_B.rad2deg[0],        /* 3: Signal */
  &Walking_ATRIAS_B.Add_j[0],          /* 4: Signal */
  &Walking_ATRIAS_B.Constant3[0],      /* 5: Signal */
  &Walking_ATRIAS_B.Constant4[0],      /* 6: Signal */
  &Walking_ATRIAS_B.DataTypeConversion,/* 7: Signal */
  &Walking_ATRIAS_B.Gain_d[0],         /* 8: Signal */
  &Walking_ATRIAS_B.Gain1_i[0],        /* 9: Signal */
  &Walking_ATRIAS_B.Gain2[0],          /* 10: Signal */
  &Walking_ATRIAS_B.Reshape[0],        /* 11: Signal */
  &Walking_ATRIAS_B.Reshape1[0],       /* 12: Signal */
  &Walking_ATRIAS_B.Reshape3_i[0],     /* 13: Signal */
  &Walking_ATRIAS_B.Reshape4[0],       /* 14: Signal */
  &Walking_ATRIAS_B.Controller3_o1,    /* 15: Signal */
  &Walking_ATRIAS_B.Controller3_o2[0], /* 16: Signal */
  &Walking_ATRIAS_B.Controller3_o3[0], /* 17: Signal */
  &Walking_ATRIAS_B.Controller3_o4[0], /* 18: Signal */
  &Walking_ATRIAS_B.Controller3_o5[0], /* 19: Signal */
  &Walking_ATRIAS_B.q[0],              /* 20: Signal */
  &Walking_ATRIAS_B.MotorCurrentCommandSafe[0],/* 21: Signal */
  &Walking_ATRIAS_B.MedullaCommandSafe,/* 22: Signal */
  &Walking_ATRIAS_B.SafetyState,       /* 23: Signal */
  &Walking_ATRIAS_B.SafetyCountOut,    /* 24: Signal */
  (void *) &Walking_ATRIAS_ConstB.Constant2,/* 25: Signal */
  (void *) &Walking_ATRIAS_ConstB.Gain,/* 26: Signal */
  &Walking_ATRIAS_B.current_unsat[0],  /* 27: Signal */
  &Walking_ATRIAS_B.UnitDelay_a,       /* 28: Signal */
  &Walking_ATRIAS_B.UnitDelay1_h[0],   /* 29: Signal */
  &Walking_ATRIAS_B.UnitDelay2_o[0],   /* 30: Signal */
  &Walking_ATRIAS_B.torque_sat[0],     /* 31: Signal */
  &Walking_ATRIAS_B.Gain_e[0],         /* 32: Signal */
  &Walking_ATRIAS_B.Gain1[0],          /* 33: Signal */
  &Walking_ATRIAS_B.DiscreteTimeIntegrator1,/* 34: Signal */
  &Walking_ATRIAS_B.Divide,            /* 35: Signal */
  &Walking_ATRIAS_B.Switch_f,          /* 36: Signal */
  &Walking_ATRIAS_B.UnitDelay_m,       /* 37: Signal */
  &Walking_ATRIAS_B.Gain[0],           /* 38: Signal */
  &Walking_ATRIAS_B.Add[0],            /* 39: Signal */
  &Walking_ATRIAS_B.Gain_a[0],         /* 40: Signal */
  &Walking_ATRIAS_B.DigitalClock_e,    /* 41: Signal */
  &Walking_ATRIAS_B.LogicalOperator,   /* 42: Signal */
  &Walking_ATRIAS_B.LogicalOperator1,  /* 43: Signal */
  &Walking_ATRIAS_B.LogicalOperator2,  /* 44: Signal */
  &Walking_ATRIAS_B.UnitDelay_l,       /* 45: Signal */
  &Walking_ATRIAS_B.LowerRelop1_k[0],  /* 46: Signal */
  &Walking_ATRIAS_B.UpperRelop_j[0],   /* 47: Signal */
  &Walking_ATRIAS_B.Switch_b[0],       /* 48: Signal */
  &Walking_ATRIAS_B.Switch2_d[0],      /* 49: Signal */
  &Walking_ATRIAS_B.q_clean[0],        /* 50: Signal */
  &Walking_ATRIAS_B.dq_clean[0],       /* 51: Signal */
  &Walking_ATRIAS_B.ZYX[0],            /* 52: Signal */
  &Walking_ATRIAS_B.dZYX[0],           /* 53: Signal */
  &Walking_ATRIAS_B.Rk_g[0],           /* 54: Signal */
  &Walking_ATRIAS_B.R0[0],             /* 55: Signal */
  &Walking_ATRIAS_B.YawRollover[0],    /* 56: Signal */
  &Walking_ATRIAS_B.Rk[0],             /* 57: Signal */
  &Walking_ATRIAS_B.wk[0],             /* 58: Signal */
  &Walking_ATRIAS_B.Ak[0],             /* 59: Signal */
  &Walking_ATRIAS_B.Seqk,              /* 60: Signal */
  &Walking_ATRIAS_B.ValidStates[0],    /* 61: Signal */
  &Walking_ATRIAS_B.u_zeroed[0],       /* 62: Signal */
  &Walking_ATRIAS_B.VectorConcatenate[0],/* 63: Signal */
  &Walking_ATRIAS_B.VectorConcatenate[0],/* 64: Signal */
  &Walking_ATRIAS_B.Rollover[0],       /* 65: Signal */
  &Walking_ATRIAS_B.IncCalTick[0],     /* 66: Signal */
  &Walking_ATRIAS_B.y[0],              /* 67: Signal */
  &Walking_ATRIAS_B.VectorConcatenate[0],/* 68: Signal */
  &Walking_ATRIAS_B.DataTypeConversion7[0],/* 69: Signal */
  &Walking_ATRIAS_B.Reshape3[0],       /* 70: Signal */
  &Walking_ATRIAS_B.CurrentSaturation[0],/* 71: Signal */
  &Walking_ATRIAS_B.UnitDelay[0],      /* 72: Signal */
  &Walking_ATRIAS_B.UnitDelay1[0],     /* 73: Signal */
  &Walking_ATRIAS_B.UnitDelay10[0],    /* 74: Signal */
  &Walking_ATRIAS_B.UnitDelay2[0],     /* 75: Signal */
  &Walking_ATRIAS_B.UnitDelay5[0],     /* 76: Signal */
  &Walking_ATRIAS_B.UnitDelay6[0],     /* 77: Signal */
  &Walking_ATRIAS_B.UnitDelay7[0],     /* 78: Signal */
  &Walking_ATRIAS_B.UnitDelay8,        /* 79: Signal */
  &Walking_ATRIAS_B.UnitDelay9[0],     /* 80: Signal */
  &Walking_ATRIAS_B.LowerRelop1[0],    /* 81: Signal */
  &Walking_ATRIAS_B.UpperRelop[0],     /* 82: Signal */
  &Walking_ATRIAS_B.Switch[0],         /* 83: Signal */
  &Walking_ATRIAS_B.Switch2[0],        /* 84: Signal */
  &Walking_ATRIAS_B.Compare,           /* 85: Signal */
  &Walking_ATRIAS_B.Compare_k,         /* 86: Signal */
  &Walking_ATRIAS_B.Compare_m,         /* 87: Signal */
  &Walking_ATRIAS_B.measuredCurrent[0],/* 88: Signal */
  &Walking_ATRIAS_B.logicVoltage[0],   /* 89: Signal */
  &Walking_ATRIAS_B.motorVoltage[0],   /* 90: Signal */
  &Walking_ATRIAS_B.Temperatures[0],   /* 91: Signal */
  &Walking_ATRIAS_B.LimitSwitchesEncoded,/* 92: Signal */
  &Walking_ATRIAS_B.DataTypeConversion1,/* 93: Signal */
  &Walking_ATRIAS_B.DataTypeConversion10,/* 94: Signal */
  &Walking_ATRIAS_B.DataTypeConversion101,/* 95: Signal */
  &Walking_ATRIAS_B.DataTypeConversion102[0],/* 96: Signal */
  &Walking_ATRIAS_B.DataTypeConversion103,/* 97: Signal */
  &Walking_ATRIAS_B.DataTypeConversion104,/* 98: Signal */
  &Walking_ATRIAS_B.DataTypeConversion105,/* 99: Signal */
  &Walking_ATRIAS_B.DataTypeConversion106,/* 100: Signal */
  &Walking_ATRIAS_B.DataTypeConversion107,/* 101: Signal */
  &Walking_ATRIAS_B.DataTypeConversion108,/* 102: Signal */
  &Walking_ATRIAS_B.DataTypeConversion109,/* 103: Signal */
  &Walking_ATRIAS_B.DataTypeConversion11,/* 104: Signal */
  &Walking_ATRIAS_B.DataTypeConversion110,/* 105: Signal */
  &Walking_ATRIAS_B.DataTypeConversion111,/* 106: Signal */
  &Walking_ATRIAS_B.DataTypeConversion112,/* 107: Signal */
  &Walking_ATRIAS_B.DataTypeConversion114,/* 108: Signal */
  &Walking_ATRIAS_B.DataTypeConversion116,/* 109: Signal */
  &Walking_ATRIAS_B.DataTypeConversion117[0],/* 110: Signal */
  &Walking_ATRIAS_B.DataTypeConversion118,/* 111: Signal */
  &Walking_ATRIAS_B.DataTypeConversion119,/* 112: Signal */
  &Walking_ATRIAS_B.DataTypeConversion12,/* 113: Signal */
  &Walking_ATRIAS_B.DataTypeConversion120,/* 114: Signal */
  &Walking_ATRIAS_B.DataTypeConversion121,/* 115: Signal */
  &Walking_ATRIAS_B.DataTypeConversion122,/* 116: Signal */
  &Walking_ATRIAS_B.DataTypeConversion123,/* 117: Signal */
  &Walking_ATRIAS_B.DataTypeConversion124,/* 118: Signal */
  &Walking_ATRIAS_B.DataTypeConversion125,/* 119: Signal */
  &Walking_ATRIAS_B.DataTypeConversion126,/* 120: Signal */
  &Walking_ATRIAS_B.DataTypeConversion13,/* 121: Signal */
  &Walking_ATRIAS_B.DataTypeConversion14,/* 122: Signal */
  (void *) &Walking_ATRIAS_ConstB.DataTypeConversion141[0],/* 123: Signal */
  &Walking_ATRIAS_B.DataTypeConversion15[0],/* 124: Signal */
  &Walking_ATRIAS_B.DataTypeConversion157,/* 125: Signal */
  &Walking_ATRIAS_B.DataTypeConversion16,/* 126: Signal */
  &Walking_ATRIAS_B.DataTypeConversion17,/* 127: Signal */
  &Walking_ATRIAS_B.DataTypeConversion18,/* 128: Signal */
  &Walking_ATRIAS_B.DataTypeConversion19,/* 129: Signal */
  &Walking_ATRIAS_B.DataTypeConversion2,/* 130: Signal */
  &Walking_ATRIAS_B.DataTypeConversion20[0],/* 131: Signal */
  &Walking_ATRIAS_B.DataTypeConversion21[0],/* 132: Signal */
  &Walking_ATRIAS_B.DataTypeConversion22[0],/* 133: Signal */
  &Walking_ATRIAS_B.DataTypeConversion23[0],/* 134: Signal */
  &Walking_ATRIAS_B.DataTypeConversion24,/* 135: Signal */
  &Walking_ATRIAS_B.DataTypeConversion25,/* 136: Signal */
  &Walking_ATRIAS_B.DataTypeConversion26,/* 137: Signal */
  &Walking_ATRIAS_B.DataTypeConversion27,/* 138: Signal */
  &Walking_ATRIAS_B.DataTypeConversion28,/* 139: Signal */
  &Walking_ATRIAS_B.DataTypeConversion29,/* 140: Signal */
  &Walking_ATRIAS_B.DataTypeConversion3,/* 141: Signal */
  &Walking_ATRIAS_B.DataTypeConversion30,/* 142: Signal */
  &Walking_ATRIAS_B.DataTypeConversion31,/* 143: Signal */
  &Walking_ATRIAS_B.DataTypeConversion32,/* 144: Signal */
  &Walking_ATRIAS_B.DataTypeConversion33,/* 145: Signal */
  &Walking_ATRIAS_B.DataTypeConversion34,/* 146: Signal */
  &Walking_ATRIAS_B.DataTypeConversion35,/* 147: Signal */
  &Walking_ATRIAS_B.DataTypeConversion36,/* 148: Signal */
  &Walking_ATRIAS_B.DataTypeConversion37,/* 149: Signal */
  &Walking_ATRIAS_B.DataTypeConversion38,/* 150: Signal */
  &Walking_ATRIAS_B.DataTypeConversion39[0],/* 151: Signal */
  &Walking_ATRIAS_B.DataTypeConversion4,/* 152: Signal */
  &Walking_ATRIAS_B.DataTypeConversion45[0],/* 153: Signal */
  &Walking_ATRIAS_B.DataTypeConversion47[0],/* 154: Signal */
  &Walking_ATRIAS_B.DataTypeConversion49,/* 155: Signal */
  &Walking_ATRIAS_B.DataTypeConversion5,/* 156: Signal */
  &Walking_ATRIAS_B.DataTypeConversion50,/* 157: Signal */
  &Walking_ATRIAS_B.DataTypeConversion51,/* 158: Signal */
  &Walking_ATRIAS_B.DataTypeConversion52,/* 159: Signal */
  &Walking_ATRIAS_B.DataTypeConversion53,/* 160: Signal */
  &Walking_ATRIAS_B.DataTypeConversion54,/* 161: Signal */
  &Walking_ATRIAS_B.DataTypeConversion55,/* 162: Signal */
  &Walking_ATRIAS_B.DataTypeConversion56,/* 163: Signal */
  &Walking_ATRIAS_B.DataTypeConversion57,/* 164: Signal */
  &Walking_ATRIAS_B.DataTypeConversion58,/* 165: Signal */
  &Walking_ATRIAS_B.DataTypeConversion59,/* 166: Signal */
  &Walking_ATRIAS_B.DataTypeConversion6,/* 167: Signal */
  &Walking_ATRIAS_B.DataTypeConversion60,/* 168: Signal */
  &Walking_ATRIAS_B.DataTypeConversion61,/* 169: Signal */
  &Walking_ATRIAS_B.DataTypeConversion62,/* 170: Signal */
  &Walking_ATRIAS_B.DataTypeConversion63[0],/* 171: Signal */
  &Walking_ATRIAS_B.DataTypeConversion69[0],/* 172: Signal */
  &Walking_ATRIAS_B.DataTypeConversion7_l,/* 173: Signal */
  &Walking_ATRIAS_B.DataTypeConversion71[0],/* 174: Signal */
  &Walking_ATRIAS_B.DataTypeConversion73,/* 175: Signal */
  &Walking_ATRIAS_B.DataTypeConversion74,/* 176: Signal */
  &Walking_ATRIAS_B.DataTypeConversion75,/* 177: Signal */
  &Walking_ATRIAS_B.DataTypeConversion76,/* 178: Signal */
  &Walking_ATRIAS_B.DataTypeConversion77,/* 179: Signal */
  &Walking_ATRIAS_B.DataTypeConversion78,/* 180: Signal */
  &Walking_ATRIAS_B.DataTypeConversion79,/* 181: Signal */
  &Walking_ATRIAS_B.DataTypeConversion8,/* 182: Signal */
  &Walking_ATRIAS_B.DataTypeConversion80,/* 183: Signal */
  &Walking_ATRIAS_B.DataTypeConversion81,/* 184: Signal */
  &Walking_ATRIAS_B.DataTypeConversion82,/* 185: Signal */
  &Walking_ATRIAS_B.DataTypeConversion83,/* 186: Signal */
  &Walking_ATRIAS_B.DataTypeConversion84,/* 187: Signal */
  &Walking_ATRIAS_B.DataTypeConversion85,/* 188: Signal */
  &Walking_ATRIAS_B.DataTypeConversion86,/* 189: Signal */
  &Walking_ATRIAS_B.DataTypeConversion87[0],/* 190: Signal */
  &Walking_ATRIAS_B.DataTypeConversion9,/* 191: Signal */
  &Walking_ATRIAS_B.DataTypeConversion93[0],/* 192: Signal */
  &Walking_ATRIAS_B.DataTypeConversion95[0],/* 193: Signal */
  &Walking_ATRIAS_B.DataTypeConversion97[0],/* 194: Signal */
  &Walking_ATRIAS_B.DataTypeConversion98,/* 195: Signal */
  (void *) &Walking_ATRIAS_ConstB.Make3x1[0],/* 196: Signal */
  &Walking_ATRIAS_B.Counter_o1,        /* 197: Signal */
  &Walking_ATRIAS_B.Counter_o2,        /* 198: Signal */
  &Walking_ATRIAS_B.EtherCATInit[0],   /* 199: Signal */
  &Walking_ATRIAS_B.DataTypeConversion3_o,/* 200: Signal */
  &Walking_ATRIAS_B.DataTypeConversion4_d,/* 201: Signal */
  &Walking_ATRIAS_B.DataTypeConversion5_a,/* 202: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar_h,   /* 203: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar1_b,  /* 204: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar12_k, /* 205: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar13_g, /* 206: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar14_d, /* 207: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar15_j, /* 208: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar16_l, /* 209: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar17_i, /* 210: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar18_a, /* 211: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar19_p, /* 212: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar2_p,  /* 213: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar3_f,  /* 214: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar4_j,  /* 215: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar5_f,  /* 216: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar6_n,  /* 217: Signal */
  &Walking_ATRIAS_B.DataTypeConversion3_m,/* 218: Signal */
  &Walking_ATRIAS_B.DataTypeConversion4_l,/* 219: Signal */
  &Walking_ATRIAS_B.DataTypeConversion5_d,/* 220: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar,     /* 221: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar1_n,  /* 222: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar12_l, /* 223: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar13_f, /* 224: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar14_f, /* 225: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar15_d, /* 226: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar16_e, /* 227: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar17_f, /* 228: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar18_n, /* 229: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar19,   /* 230: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar2_i,  /* 231: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar3,    /* 232: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar4_e,  /* 233: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar5_h,  /* 234: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar6_p,  /* 235: Signal */
  &Walking_ATRIAS_B.DataTypeConversion3_m4,/* 236: Signal */
  &Walking_ATRIAS_B.DataTypeConversion4_li,/* 237: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar1,    /* 238: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar11,   /* 239: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar12,   /* 240: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar15_e, /* 241: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar16_e3,/* 242: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar17_n, /* 243: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar18,   /* 244: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar2,    /* 245: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar3_g,  /* 246: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar4_d,  /* 247: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar5_hj, /* 248: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar6,    /* 249: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar9,    /* 250: Signal */
  &Walking_ATRIAS_B.ControlWordIndex_m,/* 251: Signal */
  &Walking_ATRIAS_B.EnableTargetTorque_h,/* 252: Signal */
  &Walking_ATRIAS_B.FaultDetected_g,   /* 253: Signal */
  &Walking_ATRIAS_B.VectorConcatenate_g[0],/* 254: Signal */
  &Walking_ATRIAS_B.DataTypeConversion20_f,/* 255: Signal */
  &Walking_ATRIAS_B.DataTypeConversion42,/* 256: Signal */
  &Walking_ATRIAS_B.Switch_fb,         /* 257: Signal */
  &Walking_ATRIAS_B.sf_Chart_m.ControlWordIndex,/* 258: Signal */
  &Walking_ATRIAS_B.sf_Chart_m.EnableTargetTorque,/* 259: Signal */
  &Walking_ATRIAS_B.sf_Chart_m.FaultDetected,/* 260: Signal */
  &Walking_ATRIAS_B.DataTypeConversion20_o,/* 261: Signal */
  &Walking_ATRIAS_B.VectorConcatenate_f[0],/* 262: Signal */
  &Walking_ATRIAS_B.DataTypeConversion42_e,/* 263: Signal */
  &Walking_ATRIAS_B.Switch_fg,         /* 264: Signal */
  &Walking_ATRIAS_B.ControlWordIndex,  /* 265: Signal */
  &Walking_ATRIAS_B.EnableTargetTorque,/* 266: Signal */
  &Walking_ATRIAS_B.FaultDetected,     /* 267: Signal */
  &Walking_ATRIAS_B.VectorConcatenate_d[0],/* 268: Signal */
  &Walking_ATRIAS_B.DataTypeConversion20_n,/* 269: Signal */
  &Walking_ATRIAS_B.DataTypeConversion42_h,/* 270: Signal */
  &Walking_ATRIAS_B.Switch_d,          /* 271: Signal */
  &Walking_ATRIAS_B.sf_Chart_mz.ControlWordIndex,/* 272: Signal */
  &Walking_ATRIAS_B.sf_Chart_mz.EnableTargetTorque,/* 273: Signal */
  &Walking_ATRIAS_B.sf_Chart_mz.FaultDetected,/* 274: Signal */
  &Walking_ATRIAS_B.VectorConcatenate_p[0],/* 275: Signal */
  &Walking_ATRIAS_B.DataTypeConversion20_h,/* 276: Signal */
  &Walking_ATRIAS_B.DataTypeConversion42_i,/* 277: Signal */
  &Walking_ATRIAS_B.Switch_i,          /* 278: Signal */
  &Walking_ATRIAS_B.DataTypeConversion3_h,/* 279: Signal */
  &Walking_ATRIAS_B.DataTypeConversion4_g,/* 280: Signal */
  &Walking_ATRIAS_B.DataTypeConversion5_i,/* 281: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar_nk,  /* 282: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar1_c,  /* 283: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar10_h, /* 284: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar11_k, /* 285: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar12_og,/* 286: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar13_h, /* 287: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar14_l, /* 288: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar15_k, /* 289: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar16_b, /* 290: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar17_g, /* 291: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar18_b, /* 292: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar19_ma,/* 293: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar2_g,  /* 294: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar20_n, /* 295: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar21_f, /* 296: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar22_i, /* 297: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar23,   /* 298: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar3_e,  /* 299: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar4_o,  /* 300: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar5,    /* 301: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar6_h,  /* 302: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar7_g,  /* 303: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar8_h,  /* 304: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar9_p,  /* 305: Signal */
  &Walking_ATRIAS_B.DataTypeConversion3_m4p,/* 306: Signal */
  &Walking_ATRIAS_B.DataTypeConversion4_a,/* 307: Signal */
  &Walking_ATRIAS_B.DataTypeConversion5_p,/* 308: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar_n,   /* 309: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar1_m,  /* 310: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar10,   /* 311: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar11_b, /* 312: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar12_f, /* 313: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar13,   /* 314: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar14,   /* 315: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar15,   /* 316: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar16,   /* 317: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar17,   /* 318: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar18_e, /* 319: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar19_m, /* 320: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar2_f,  /* 321: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar20_h, /* 322: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar21_p, /* 323: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar22_l, /* 324: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar23_n, /* 325: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar3_b,  /* 326: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar4,    /* 327: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar5_e,  /* 328: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar6_b,  /* 329: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar7,    /* 330: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar8,    /* 331: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar9_nz, /* 332: Signal */
  &Walking_ATRIAS_B.DataTypeConversion3_f,/* 333: Signal */
  &Walking_ATRIAS_B.DataTypeConversion4_di,/* 334: Signal */
  &Walking_ATRIAS_B.DataTypeConversion5_h,/* 335: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar_o,   /* 336: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar1_g,  /* 337: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar10_l, /* 338: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar11_l, /* 339: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar12_m, /* 340: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar13_n, /* 341: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar14_b, /* 342: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar15_mh,/* 343: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar16_hz,/* 344: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar17_bq,/* 345: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar18_d, /* 346: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar19_p0,/* 347: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar2_iw, /* 348: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar20,   /* 349: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar21,   /* 350: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar22,   /* 351: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar23_d, /* 352: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar3_k,  /* 353: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar4_h,  /* 354: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar5_g,  /* 355: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar6_bg, /* 356: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar7_h,  /* 357: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar8_bx, /* 358: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar9_n,  /* 359: Signal */
  &Walking_ATRIAS_B.DataTypeConversion3_l,/* 360: Signal */
  &Walking_ATRIAS_B.DataTypeConversion4_f,/* 361: Signal */
  &Walking_ATRIAS_B.DataTypeConversion5_b,/* 362: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar_k,   /* 363: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar1_o,  /* 364: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar10_i, /* 365: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar11_e, /* 366: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar12_o, /* 367: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar13_b, /* 368: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar14_j, /* 369: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar15_m, /* 370: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar16_h, /* 371: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar17_b, /* 372: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar18_o, /* 373: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar19_c, /* 374: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar2_d,  /* 375: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar20_e, /* 376: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar21_l, /* 377: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar22_a, /* 378: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar23_b, /* 379: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar3_c,  /* 380: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar4_l,  /* 381: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar5_gi, /* 382: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar6_j,  /* 383: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar7_p,  /* 384: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar8_b,  /* 385: Signal */
  &Walking_ATRIAS_B.EtherCATRxVar9_e,  /* 386: Signal */
  &Walking_ATRIAS_B.CoreSubsys[18].dq_out,/* 387: Signal */
  &Walking_ATRIAS_B.CoreSubsys[18].dq_good,/* 388: Signal */
  &Walking_ATRIAS_B.CoreSubsys[18].UnitDelay1,/* 389: Signal */
  &Walking_ATRIAS_B.CoreSubsys[18].UnitDelay2,/* 390: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive,/* 391: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive1,/* 392: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive2,/* 393: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive5,/* 394: Signal */
  &Walking_ATRIAS_B.VectorConcatenate_f0[0],/* 395: Signal */
  &Walking_ATRIAS_B.DataTypeConversion6_f,/* 396: Signal */
  &Walking_ATRIAS_B.Fcn_c,             /* 397: Signal */
  &Walking_ATRIAS_B.Merge,             /* 398: Signal */
  &Walking_ATRIAS_B.BitwiseOperator,   /* 399: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_c, /* 400: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_j, /* 401: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_m, /* 402: Signal */
  &Walking_ATRIAS_B.VectorConcatenate_g[0],/* 403: Signal */
  &Walking_ATRIAS_B.Fcn,               /* 404: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive_d,/* 405: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive1_d,/* 406: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive2_n,/* 407: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive5_d,/* 408: Signal */
  &Walking_ATRIAS_B.VectorConcatenate_c[0],/* 409: Signal */
  &Walking_ATRIAS_B.DataTypeConversion6_eq,/* 410: Signal */
  &Walking_ATRIAS_B.Fcn_h,             /* 411: Signal */
  &Walking_ATRIAS_B.Merge_b,           /* 412: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_h, /* 413: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_d, /* 414: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_k, /* 415: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_he,/* 416: Signal */
  &Walking_ATRIAS_B.VectorConcatenate_f[0],/* 417: Signal */
  &Walking_ATRIAS_B.Fcn_m,             /* 418: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive_p,/* 419: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive1_n,/* 420: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive2_f,/* 421: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive5_dm,/* 422: Signal */
  &Walking_ATRIAS_B.VectorConcatenate_n[0],/* 423: Signal */
  &Walking_ATRIAS_B.DataTypeConversion6_e,/* 424: Signal */
  &Walking_ATRIAS_B.Fcn_f,             /* 425: Signal */
  &Walking_ATRIAS_B.Merge_e,           /* 426: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_hh,/* 427: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_f, /* 428: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_cf,/* 429: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_e, /* 430: Signal */
  &Walking_ATRIAS_B.VectorConcatenate_d[0],/* 431: Signal */
  &Walking_ATRIAS_B.Fcn_k,             /* 432: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive_o,/* 433: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive1_f,/* 434: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive3,/* 435: Signal */
  &Walking_ATRIAS_B.EtherCATPDOReceive5_m,/* 436: Signal */
  &Walking_ATRIAS_B.VectorConcatenate_dr[0],/* 437: Signal */
  &Walking_ATRIAS_B.DataTypeConversion6_h,/* 438: Signal */
  &Walking_ATRIAS_B.Fcn_i,             /* 439: Signal */
  &Walking_ATRIAS_B.Merge_k,           /* 440: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_d5,/* 441: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_g, /* 442: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_o, /* 443: Signal */
  &Walking_ATRIAS_B.BitwiseOperator_hb,/* 444: Signal */
  &Walking_ATRIAS_B.VectorConcatenate_p[0],/* 445: Signal */
  &Walking_ATRIAS_B.Fcn_mq,            /* 446: Signal */
  &Walking_ATRIAS_B.CoreSubsys[18].Gain1,/* 447: Signal */
  &Walking_ATRIAS_B.CoreSubsys[18].two_pole_filter,/* 448: Signal */
  &Walking_ATRIAS_B.Compare_o,         /* 449: Signal */
  &Walking_ATRIAS_B.Compare_l,         /* 450: Signal */
  &Walking_ATRIAS_B.Compare_ly,        /* 451: Signal */
  &Walking_ATRIAS_B.Compare_d,         /* 452: Signal */
  &Walking_ATRIAS_B.Compare_d0,        /* 453: Signal */
  &Walking_ATRIAS_B.Compare_p,         /* 454: Signal */
  &Walking_ATRIAS_B.Compare_om,        /* 455: Signal */
  &Walking_ATRIAS_B.Compare_n,         /* 456: Signal */
  &Walking_ATRIAS_B.Compare_e,         /* 457: Signal */
  &Walking_ATRIAS_B.Compare_lx,        /* 458: Signal */
  &Walking_ATRIAS_B.Compare_k0,        /* 459: Signal */
  &Walking_ATRIAS_B.Compare_la,        /* 460: Signal */
  &Walking_ATRIAS_B.Compare_i,         /* 461: Signal */
  &Walking_ATRIAS_B.Compare_ls,        /* 462: Signal */
  &Walking_ATRIAS_B.Compare_da,        /* 463: Signal */
  &Walking_ATRIAS_B.Compare_dh,        /* 464: Signal */
  &Walking_ATRIAS_B.CoreSubsys[18].Diff,/* 465: Signal */
  &Walking_ATRIAS_B.CoreSubsys[18].Uk1,/* 466: Signal */
  &Walking_ATRIAS_P.GearOffsets[0],    /* 467: Model Parameter */
  &Walking_ATRIAS_P.IMUTorsoOffsets[0],/* 468: Model Parameter */
  &Walking_ATRIAS_P.LegHipTorqueLimit[0],/* 469: Model Parameter */
  &Walking_ATRIAS_P.MedullaCommand,    /* 470: Model Parameter */
  &Walking_ATRIAS_P.TorsoCOMOffsets[0],/* 471: Model Parameter */
  &Walking_ATRIAS_P.dx_err_d_gain,     /* 472: Model Parameter */
  &Walking_ATRIAS_P.dx_err_p_gain,     /* 473: Model Parameter */
  &Walking_ATRIAS_P.dx_gain,           /* 474: Model Parameter */
  &Walking_ATRIAS_P.dy_err_d_gain,     /* 475: Model Parameter */
  &Walking_ATRIAS_P.dy_err_p_gain,     /* 476: Model Parameter */
  &Walking_ATRIAS_P.dy_gain,           /* 477: Model Parameter */
  &Walking_ATRIAS_P.hAlphaSet[0],      /* 478: Model Parameter */
  &Walking_ATRIAS_P.hip_gain,          /* 479: Model Parameter */
  &Walking_ATRIAS_P.hip_offset,        /* 480: Model Parameter */
  &Walking_ATRIAS_P.isTrackHold,       /* 481: Model Parameter */
  &Walking_ATRIAS_P.kd_hip,            /* 482: Model Parameter */
  &Walking_ATRIAS_P.kd_st_leg,         /* 483: Model Parameter */
  &Walking_ATRIAS_P.kd_sw_leg,         /* 484: Model Parameter */
  &Walking_ATRIAS_P.kd_vs,             /* 485: Model Parameter */
  &Walking_ATRIAS_P.kd_yaw,            /* 486: Model Parameter */
  &Walking_ATRIAS_P.kp_hip,            /* 487: Model Parameter */
  &Walking_ATRIAS_P.kp_st_leg,         /* 488: Model Parameter */
  &Walking_ATRIAS_P.kp_sw_leg,         /* 489: Model Parameter */
  &Walking_ATRIAS_P.kp_vs,             /* 490: Model Parameter */
  &Walking_ATRIAS_P.kp_yaw,            /* 491: Model Parameter */
  &Walking_ATRIAS_P.lbForce,           /* 492: Model Parameter */
  &Walking_ATRIAS_P.ps3Axes[0],        /* 493: Model Parameter */
  &Walking_ATRIAS_P.ps3Buttons[0],     /* 494: Model Parameter */
  &Walking_ATRIAS_P.ps3Pov,            /* 495: Model Parameter */
  &Walking_ATRIAS_P.step_gain,         /* 496: Model Parameter */
  &Walking_ATRIAS_P.t0_step,           /* 497: Model Parameter */
  &Walking_ATRIAS_P.theta_limits_norm[0],/* 498: Model Parameter */
  &Walking_ATRIAS_P.uHipGravity,       /* 499: Model Parameter */
  &Walking_ATRIAS_P.ubForce,           /* 500: Model Parameter */
  &Walking_ATRIAS_P.velFilConst,       /* 501: Model Parameter */
  &Walking_ATRIAS_P.isSetHipConst,     /* 502: Model Parameter */
  &Walking_ATRIAS_P.isSim,             /* 503: Model Parameter */
  &Walking_ATRIAS_P.isTestGravity,     /* 504: Model Parameter */
  &Walking_ATRIAS_P.isTestHipTrack,    /* 505: Model Parameter */
  &Walking_ATRIAS_P.isVCtracking,      /* 506: Model Parameter */
  &Walking_ATRIAS_P.isVirtualConstraint/* 507: Model Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "int", "int32_T", 0, 0, sizeof(int32_T), SS_INT32, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "unsigned short", "uint16_T", 0, 0, sizeof(uint16_T), SS_UINT16, 0, 0 },

  { "short", "int16_T", 0, 0, sizeof(int16_T), SS_INT16, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 },

  { "float", "real32_T", 0, 0, sizeof(real32_T), SS_SINGLE, 0, 0 },

  { "signed char", "int8_T", 0, 0, sizeof(int8_T), SS_INT8, 0, 0 }
};

/* Structure Element Map - use elemMapIndex to access this structure */
static const rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { NULL, 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 12, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 14, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 6, 2, 0 },

  { rtwCAPI_VECTOR, 16, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 18, 2, 0 },

  { rtwCAPI_VECTOR, 20, 2, 0 },

  { rtwCAPI_VECTOR, 22, 2, 0 },

  { rtwCAPI_VECTOR, 24, 2, 0 },

  { rtwCAPI_VECTOR, 26, 2, 0 },

  { rtwCAPI_VECTOR, 28, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR_ND, 30, 4, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_VECTOR, 34, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 36, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  4,                                   /* 2 */
  1,                                   /* 3 */
  13,                                  /* 4 */
  1,                                   /* 5 */
  6,                                   /* 6 */
  1,                                   /* 7 */
  11,                                  /* 8 */
  1,                                   /* 9 */
  16,                                  /* 10 */
  1,                                   /* 11 */
  1,                                   /* 12 */
  6,                                   /* 13 */
  1,                                   /* 14 */
  16,                                  /* 15 */
  3,                                   /* 16 */
  1,                                   /* 17 */
  3,                                   /* 18 */
  3,                                   /* 19 */
  2,                                   /* 20 */
  1,                                   /* 21 */
  19,                                  /* 22 */
  1,                                   /* 23 */
  9,                                   /* 24 */
  1,                                   /* 25 */
  10,                                  /* 26 */
  1,                                   /* 27 */
  30,                                  /* 28 */
  1,                                   /* 29 */
  4,                                   /* 30 */
  6,                                   /* 31 */
  5,                                   /* 32 */
  3,                                   /* 33 */
  1,                                   /* 34 */
  11,                                  /* 35 */
  9,                                   /* 36 */
  2                                    /* 37 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.001, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    0, 0 },

  { (NULL), (NULL), -2, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 467 },

  { rtBlockParameters, 0,
    rtModelParameters, 41 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 2385601952U,
    804019991U,
    783034396U,
    4003235734U },
  NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void Walking_ATRIAS_InitializeDataMapInfo(RT_MODEL_Walking_ATRIAS_T
  *Walking_ATRIAS_M
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(Walking_ATRIAS_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(Walking_ATRIAS_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(Walking_ATRIAS_M->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(Walking_ATRIAS_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(Walking_ATRIAS_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(Walking_ATRIAS_M->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(Walking_ATRIAS_M->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(Walking_ATRIAS_M->DataMapInfo.mmi, 0);
}

/* EOF: Walking_ATRIAS_capi.c */
