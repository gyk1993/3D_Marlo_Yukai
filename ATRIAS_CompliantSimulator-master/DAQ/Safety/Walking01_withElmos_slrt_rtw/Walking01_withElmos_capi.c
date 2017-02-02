/*
 * Walking01_withElmos_capi.c
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

#include "Walking01_withElmos.h"
#include "rtw_capi.h"
#include "Walking01_withElmos_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 1, "DAQ_WITH_SAFETY_IMU/AdjustForCOMOffset",
    "q", 0, 0, 0, 0, 0 },

  { 1, 50, "DAQ_WITH_SAFETY_IMU/SAFETY/p2",
    "MedullaCommandSafe", 1, 0, 1, 0, 0 },

  { 2, 50, "DAQ_WITH_SAFETY_IMU/SAFETY/p4",
    "SafetyCountOut", 3, 0, 1, 0, 0 },

  { 3, 0, "DAQ_WITH_SAFETY_IMU/Gain",
    "", 0, 0, 1, 0, 1 },

  { 4, 0, "DAQ_WITH_SAFETY_IMU/Rate Transition",
    "", 0, 1, 1, 0, 0 },

  { 5, 0, "DAQ_WITH_SAFETY_IMU/Rate Transition1",
    "", 0, 1, 1, 0, 0 },

  { 6, 0, "DAQ_WITH_SAFETY_IMU/Get Overload Counter ",
    "", 0, 1, 1, 0, 0 },

  { 7, 0, "DAQ_WITH_SAFETY_IMU/Get Overload Counter 1",
    "", 0, 1, 1, 0, 2 },

  { 8, 0, "DAQ_WITH_SAFETY_IMU/Get Overload Counter 2",
    "", 0, 1, 1, 0, 3 },

  { 9, 0, "DAQ_WITH_SAFETY_IMU/CPU Overload Regulator/Bias",
    "", 0, 0, 1, 0, 0 },

  { 10, 0, "DAQ_WITH_SAFETY_IMU/CPU Overload Regulator/Task Execution Time ",
    "", 0, 0, 1, 0, 0 },

  { 11, 0, "DAQ_WITH_SAFETY_IMU/DAQ/Rate Transition1",
    "", 0, 0, 2, 0, 0 },

  { 12, 0, "DAQ_WITH_SAFETY_IMU/DAQ/Rate Transition2",
    "", 0, 0, 2, 0, 0 },

  { 13, 0, "DAQ_WITH_SAFETY_IMU/DAQ/Rate Transition3",
    "", 0, 2, 1, 0, 3 },

  { 14, 51, "Walking/Continuous/CheckError/p2",
    "ErrorCount", 1, 0, 1, 0, 0 },

  { 15, 53, "Walking/Continuous/controller1/p5",
    "s", 4, 0, 1, 0, 0 },

  { 16, 54, "Walking/Discrete/StateLogic/p3",
    "SerialOut", 2, 0, 3, 0, 0 },

  { 17, 0, "Walking/Discrete/EnableTransition",
    "", 0, 0, 1, 0, 0 },

  { 18, 0, "Walking/Discrete/ResetControl",
    "", 0, 0, 1, 0, 0 },

  { 19, 0, "Walking/Discrete/Data Type Conversion1",
    "", 0, 0, 1, 0, 0 },

  { 20, 3, "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/ComputeEulerAngles/p1",
    "ZYX", 0, 0, 2, 0, 0 },

  { 21, 3, "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/ComputeEulerAngles/p2",
    "dZYX", 1, 0, 2, 0, 0 },

  { 22, 3, "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/ComputeEulerAngles/p3",
    "Rk", 2, 0, 4, 0, 0 },

  { 23, 3, "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/ComputeEulerAngles/p4",
    "R0", 3, 0, 4, 0, 0 },

  { 24, 3, "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/ComputeEulerAngles/p5",
    "YawRollover", 4, 0, 5, 0, 0 },

  { 25, 0, "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/calibrate/p1",
    "", 0, 0, 6, 0, 0 },

  { 26, 0, "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/calibrate/p2",
    "", 1, 0, 6, 0, 0 },

  { 27, 42, "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/calibrate/p3",
    "Rollover", 2, 0, 7, 0, 0 },

  { 28, 42, "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/calibrate/p4",
    "IncCalTick", 3, 0, 8, 0, 0 },

  { 29, 0, "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/Vector Concatenate",
    "", 0, 0, 6, 0, 0 },

  { 30, 0, "DAQ_WITH_SAFETY_IMU/DAQ/Reset/Logical Operator1",
    "", 0, 2, 1, 0, 0 },

  { 31, 0, "DAQ_WITH_SAFETY_IMU/DAQ/Reset/Logical Operator2",
    "", 0, 2, 1, 0, 0 },

  { 32, 49, "DAQ_WITH_SAFETY_IMU/DAQ/StateEstimator/GeneralizedCoordinates/p2",
    "dq_clean", 1, 0, 0, 0, 0 },

  { 33, 0, "Walking/Discrete/Detect Rise Positive2/FixPt Relational Operator",
    "", 0, 2, 1, 0, 0 },

  { 34, 0, "Walking/Discrete/KA Acceleration/Vector Concatenate",
    "", 0, 0, 5, 0, 0 },

  { 35, 0, "Walking/Discrete/KA Acceleration/Discrete State-Space",
    "", 0, 0, 5, 0, 0 },

  { 36, 0, "Walking/Discrete/KA Acceleration/Discrete State-Space1",
    "", 0, 0, 5, 0, 0 },

  { 37, 0, "Walking/Discrete/KA Acceleration/TKA",
    "", 0, 0, 5, 0, 0 },

  { 38, 2,
    "DAQ_WITH_SAFETY_IMU/CPU Overload Regulator/Reset CPU Overload Count/Set Overload Counter 1/Data Type  Conversion",
    "", 0, 1, 1, 0, 1 },

  { 39, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion104",
    "", 0, 0, 1, 0, 0 },

  { 40, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion119",
    "", 0, 0, 1, 0, 0 },

  { 41, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion141",
    "", 0, 0, 2, 0, 1 },

  { 42, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion33",
    "", 0, 0, 1, 0, 0 },

  { 43, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion57",
    "", 0, 0, 1, 0, 0 },

  { 44, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion81",
    "", 0, 0, 1, 0, 0 },

  { 45, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion9",
    "", 0, 0, 1, 0, 0 },

  { 46, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/Data Type Conversion97",
    "", 0, 0, 8, 0, 0 },

  { 47, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/EtherCAT Init ",
    "", 0, 3, 8, 0, 0 },

  { 48, 44, "DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/ComputeEulerAngles/p1",
    "ZYX", 0, 0, 2, 0, 3 },

  { 49, 44, "DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/ComputeEulerAngles/p2",
    "dZYX", 1, 0, 2, 0, 3 },

  { 50, 44, "DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/ComputeEulerAngles/p3",
    "Rk", 2, 0, 4, 0, 3 },

  { 51, 44, "DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/ComputeEulerAngles/p4",
    "R0", 3, 0, 4, 0, 3 },

  { 52, 44, "DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/ComputeEulerAngles/p5",
    "YawRollover", 4, 0, 5, 0, 3 },

  { 53, 0, "Walking/Discrete/Detect Rise Positive1/Positive/Compare",
    "", 0, 4, 1, 0, 0 },

  { 54, 0, "Walking/Discrete/Detect Rise Positive2/Positive/Compare",
    "", 0, 2, 1, 0, 0 },

  { 55, 4,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EncoderFilters/CheckAndFilterEncoder/AnomalyDetection/p1",
    "q_clean", 0, 0, 1, 0, 0 },

  { 56, 4,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EncoderFilters/CheckAndFilterEncoder/AnomalyDetection/p2",
    "ErrorCount", 1, 0, 1, 0, 0 },

  { 57, 5,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EncoderFilters/CheckAndFilterEncoder/Discrete State-Space",
    "", 0, 0, 1, 0, 0 },

  { 58, 5,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EncoderFilters/CheckAndFilterEncoder/Unit Delay",
    "", 0, 0, 1, 0, 0 },

  { 59, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/Data Type Conversion3",
    "", 0, 4, 1, 0, 0 },

  { 60, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/Data Type Conversion4",
    "", 0, 5, 1, 0, 0 },

  { 61, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/Data Type Conversion5",
    "", 0, 3, 1, 0, 0 },

  { 62, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var ",
    "", 0, 6, 1, 0, 0 },

  { 63, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 1",
    "", 0, 5, 1, 0, 0 },

  { 64, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 12",
    "", 0, 5, 1, 0, 0 },

  { 65, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 13",
    "", 0, 5, 1, 0, 0 },

  { 66, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 14",
    "", 0, 5, 1, 0, 0 },

  { 67, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 15",
    "", 0, 4, 1, 0, 0 },

  { 68, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 16",
    "", 0, 4, 1, 0, 0 },

  { 69, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 17",
    "", 0, 4, 1, 0, 0 },

  { 70, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 18",
    "", 0, 4, 1, 0, 0 },

  { 71, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 19",
    "", 0, 4, 1, 0, 0 },

  { 72, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 2",
    "", 0, 5, 1, 0, 0 },

  { 73, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 3",
    "", 0, 5, 1, 0, 0 },

  { 74, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 4",
    "", 0, 1, 1, 0, 0 },

  { 75, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 5",
    "", 0, 5, 1, 0, 0 },

  { 76, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L/EtherCAT Rx Var 6",
    "", 0, 5, 1, 0, 0 },

  { 77, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/Data Type Conversion3",
    "", 0, 4, 1, 0, 0 },

  { 78, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/Data Type Conversion4",
    "", 0, 5, 1, 0, 0 },

  { 79, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/Data Type Conversion5",
    "", 0, 3, 1, 0, 0 },

  { 80, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var ",
    "", 0, 6, 1, 0, 0 },

  { 81, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 1",
    "", 0, 5, 1, 0, 0 },

  { 82, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 12",
    "", 0, 5, 1, 0, 0 },

  { 83, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 13",
    "", 0, 5, 1, 0, 0 },

  { 84, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 14",
    "", 0, 5, 1, 0, 0 },

  { 85, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 15",
    "", 0, 4, 1, 0, 0 },

  { 86, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 16",
    "", 0, 4, 1, 0, 0 },

  { 87, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 17",
    "", 0, 4, 1, 0, 0 },

  { 88, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 18",
    "", 0, 4, 1, 0, 0 },

  { 89, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 19",
    "", 0, 4, 1, 0, 0 },

  { 90, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 2",
    "", 0, 5, 1, 0, 0 },

  { 91, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 3",
    "", 0, 5, 1, 0, 0 },

  { 92, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 4",
    "", 0, 1, 1, 0, 0 },

  { 93, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 5",
    "", 0, 5, 1, 0, 0 },

  { 94, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R/EtherCAT Rx Var 6",
    "", 0, 5, 1, 0, 0 },

  { 95, 13,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/TypecastAndCast1",
    "y", 0, 0, 2, 0, 0 },

  { 96, 14,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/TypecastAndCast2",
    "y", 0, 0, 2, 0, 0 },

  { 97, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/Data Type Conversion1",
    "", 0, 5, 1, 0, 0 },

  { 98, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/Data Type Conversion3",
    "", 0, 4, 1, 0, 0 },

  { 99, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/Data Type Conversion4",
    "", 0, 5, 1, 0, 0 },

  { 100, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 1",
    "", 0, 1, 1, 0, 0 },

  { 101, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 10",
    "", 0, 1, 1, 0, 0 },

  { 102, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 11",
    "", 0, 1, 1, 0, 0 },

  { 103, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 12",
    "", 0, 1, 1, 0, 0 },

  { 104, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 13",
    "", 0, 1, 1, 0, 0 },

  { 105, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 14",
    "", 0, 1, 1, 0, 0 },

  { 106, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 15",
    "", 0, 4, 1, 0, 0 },

  { 107, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 16",
    "", 0, 4, 1, 0, 0 },

  { 108, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 17",
    "", 0, 4, 1, 0, 0 },

  { 109, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 18",
    "", 0, 4, 1, 0, 0 },

  { 110, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 19",
    "", 0, 1, 1, 0, 0 },

  { 111, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 2",
    "", 0, 1, 1, 0, 0 },

  { 112, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 3",
    "", 0, 1, 1, 0, 0 },

  { 113, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 4",
    "", 0, 1, 1, 0, 0 },

  { 114, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 5",
    "", 0, 1, 1, 0, 0 },

  { 115, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 6",
    "", 0, 1, 1, 0, 0 },

  { 116, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 7",
    "", 0, 1, 1, 0, 0 },

  { 117, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 8",
    "", 0, 1, 1, 0, 0 },

  { 118, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/EtherCAT Rx Var 9",
    "", 0, 1, 1, 0, 0 },

  { 119, 16,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Chart/p1",
    "ControlWordIndex", 0, 0, 1, 0, 0 },

  { 120, 16,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Chart/p2",
    "EnableTargetTorque", 1, 0, 1, 0, 0 },

  { 121, 16,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Chart/p3",
    "FaultDetected", 2, 0, 1, 0, 0 },

  { 122, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Switch",
    "", 0, 6, 1, 0, 0 },

  { 123, 22,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Chart/p1",
    "ControlWordIndex", 0, 0, 1, 0, 0 },

  { 124, 22,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Chart/p2",
    "EnableTargetTorque", 1, 0, 1, 0, 0 },

  { 125, 22,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Chart/p3",
    "FaultDetected", 2, 0, 1, 0, 0 },

  { 126, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Switch",
    "", 0, 6, 1, 0, 0 },

  { 127, 28,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Chart/p1",
    "ControlWordIndex", 0, 0, 1, 0, 0 },

  { 128, 28,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Chart/p2",
    "EnableTargetTorque", 1, 0, 1, 0, 0 },

  { 129, 28,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Chart/p3",
    "FaultDetected", 2, 0, 1, 0, 0 },

  { 130, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Switch",
    "", 0, 6, 1, 0, 0 },

  { 131, 34,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Chart/p1",
    "ControlWordIndex", 0, 0, 1, 0, 0 },

  { 132, 34,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Chart/p2",
    "EnableTargetTorque", 1, 0, 1, 0, 0 },

  { 133, 34,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Chart/p3",
    "FaultDetected", 2, 0, 1, 0, 0 },

  { 134, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Switch",
    "", 0, 6, 1, 0, 0 },

  { 135, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/Data Type Conversion3",
    "", 0, 4, 1, 0, 0 },

  { 136, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/Data Type Conversion4",
    "", 0, 5, 1, 0, 0 },

  { 137, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/Data Type Conversion5",
    "", 0, 3, 1, 0, 0 },

  { 138, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var ",
    "", 0, 5, 1, 0, 0 },

  { 139, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 1",
    "", 0, 5, 1, 0, 0 },

  { 140, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 10",
    "", 0, 5, 1, 0, 0 },

  { 141, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 11",
    "", 0, 5, 1, 0, 0 },

  { 142, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 12",
    "", 0, 5, 1, 0, 0 },

  { 143, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 13",
    "", 0, 5, 1, 0, 0 },

  { 144, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 14",
    "", 0, 5, 1, 0, 0 },

  { 145, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 15",
    "", 0, 5, 1, 0, 0 },

  { 146, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 16",
    "", 0, 5, 1, 0, 0 },

  { 147, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 17",
    "", 0, 5, 1, 0, 0 },

  { 148, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 18",
    "", 0, 4, 1, 0, 0 },

  { 149, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 19",
    "", 0, 4, 1, 0, 0 },

  { 150, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 2",
    "", 0, 5, 1, 0, 0 },

  { 151, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 20",
    "", 0, 4, 1, 0, 0 },

  { 152, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 21",
    "", 0, 4, 1, 0, 0 },

  { 153, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 22",
    "", 0, 4, 1, 0, 0 },

  { 154, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 23",
    "", 0, 5, 1, 0, 0 },

  { 155, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 3",
    "", 0, 5, 1, 0, 0 },

  { 156, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 4",
    "", 0, 1, 1, 0, 0 },

  { 157, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 5",
    "", 0, 5, 1, 0, 0 },

  { 158, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 6",
    "", 0, 6, 1, 0, 0 },

  { 159, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 7",
    "", 0, 6, 1, 0, 0 },

  { 160, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 8",
    "", 0, 1, 1, 0, 0 },

  { 161, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L/EtherCAT Rx Var 9",
    "", 0, 5, 1, 0, 0 },

  { 162, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/Data Type Conversion3",
    "", 0, 4, 1, 0, 0 },

  { 163, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/Data Type Conversion4",
    "", 0, 5, 1, 0, 0 },

  { 164, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/Data Type Conversion5",
    "", 0, 3, 1, 0, 0 },

  { 165, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var ",
    "", 0, 5, 1, 0, 0 },

  { 166, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 1",
    "", 0, 5, 1, 0, 0 },

  { 167, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 10",
    "", 0, 5, 1, 0, 0 },

  { 168, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 11",
    "", 0, 5, 1, 0, 0 },

  { 169, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 12",
    "", 0, 5, 1, 0, 0 },

  { 170, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 13",
    "", 0, 5, 1, 0, 0 },

  { 171, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 14",
    "", 0, 5, 1, 0, 0 },

  { 172, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 15",
    "", 0, 5, 1, 0, 0 },

  { 173, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 16",
    "", 0, 5, 1, 0, 0 },

  { 174, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 17",
    "", 0, 5, 1, 0, 0 },

  { 175, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 18",
    "", 0, 4, 1, 0, 0 },

  { 176, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 19",
    "", 0, 4, 1, 0, 0 },

  { 177, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 2",
    "", 0, 5, 1, 0, 0 },

  { 178, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 20",
    "", 0, 4, 1, 0, 0 },

  { 179, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 21",
    "", 0, 4, 1, 0, 0 },

  { 180, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 22",
    "", 0, 4, 1, 0, 0 },

  { 181, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 23",
    "", 0, 5, 1, 0, 0 },

  { 182, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 3",
    "", 0, 5, 1, 0, 0 },

  { 183, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 4",
    "", 0, 1, 1, 0, 0 },

  { 184, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 5",
    "", 0, 5, 1, 0, 0 },

  { 185, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 6",
    "", 0, 6, 1, 0, 0 },

  { 186, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 7",
    "", 0, 6, 1, 0, 0 },

  { 187, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 8",
    "", 0, 1, 1, 0, 0 },

  { 188, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R/EtherCAT Rx Var 9",
    "", 0, 5, 1, 0, 0 },

  { 189, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/Data Type Conversion3",
    "", 0, 4, 1, 0, 0 },

  { 190, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/Data Type Conversion4",
    "", 0, 5, 1, 0, 0 },

  { 191, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/Data Type Conversion5",
    "", 0, 3, 1, 0, 0 },

  { 192, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var ",
    "", 0, 5, 1, 0, 0 },

  { 193, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 1",
    "", 0, 5, 1, 0, 0 },

  { 194, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 10",
    "", 0, 5, 1, 0, 0 },

  { 195, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 11",
    "", 0, 5, 1, 0, 0 },

  { 196, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 12",
    "", 0, 5, 1, 0, 0 },

  { 197, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 13",
    "", 0, 5, 1, 0, 0 },

  { 198, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 14",
    "", 0, 5, 1, 0, 0 },

  { 199, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 15",
    "", 0, 5, 1, 0, 0 },

  { 200, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 16",
    "", 0, 5, 1, 0, 0 },

  { 201, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 17",
    "", 0, 5, 1, 0, 0 },

  { 202, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 18",
    "", 0, 4, 1, 0, 0 },

  { 203, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 19",
    "", 0, 4, 1, 0, 0 },

  { 204, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 2",
    "", 0, 5, 1, 0, 0 },

  { 205, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 20",
    "", 0, 4, 1, 0, 0 },

  { 206, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 21",
    "", 0, 4, 1, 0, 0 },

  { 207, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 22",
    "", 0, 4, 1, 0, 0 },

  { 208, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 23",
    "", 0, 5, 1, 0, 0 },

  { 209, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 3",
    "", 0, 5, 1, 0, 0 },

  { 210, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 4",
    "", 0, 1, 1, 0, 0 },

  { 211, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 5",
    "", 0, 5, 1, 0, 0 },

  { 212, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 6",
    "", 0, 6, 1, 0, 0 },

  { 213, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 7",
    "", 0, 6, 1, 0, 0 },

  { 214, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 8",
    "", 0, 1, 1, 0, 0 },

  { 215, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L/EtherCAT Rx Var 9",
    "", 0, 5, 1, 0, 0 },

  { 216, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/Data Type Conversion3",
    "", 0, 4, 1, 0, 0 },

  { 217, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/Data Type Conversion4",
    "", 0, 5, 1, 0, 0 },

  { 218, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/Data Type Conversion5",
    "", 0, 3, 1, 0, 0 },

  { 219, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var ",
    "", 0, 5, 1, 0, 0 },

  { 220, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 1",
    "", 0, 5, 1, 0, 0 },

  { 221, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 10",
    "", 0, 5, 1, 0, 0 },

  { 222, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 11",
    "", 0, 5, 1, 0, 0 },

  { 223, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 12",
    "", 0, 5, 1, 0, 0 },

  { 224, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 13",
    "", 0, 5, 1, 0, 0 },

  { 225, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 14",
    "", 0, 5, 1, 0, 0 },

  { 226, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 15",
    "", 0, 5, 1, 0, 0 },

  { 227, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 16",
    "", 0, 5, 1, 0, 0 },

  { 228, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 17",
    "", 0, 5, 1, 0, 0 },

  { 229, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 18",
    "", 0, 4, 1, 0, 0 },

  { 230, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 19",
    "", 0, 4, 1, 0, 0 },

  { 231, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 2",
    "", 0, 5, 1, 0, 0 },

  { 232, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 20",
    "", 0, 4, 1, 0, 0 },

  { 233, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 21",
    "", 0, 4, 1, 0, 0 },

  { 234, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 22",
    "", 0, 4, 1, 0, 0 },

  { 235, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 23",
    "", 0, 5, 1, 0, 0 },

  { 236, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 3",
    "", 0, 5, 1, 0, 0 },

  { 237, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 4",
    "", 0, 1, 1, 0, 0 },

  { 238, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 5",
    "", 0, 5, 1, 0, 0 },

  { 239, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 6",
    "", 0, 6, 1, 0, 0 },

  { 240, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 7",
    "", 0, 6, 1, 0, 0 },

  { 241, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 8",
    "", 0, 1, 1, 0, 0 },

  { 242, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R/EtherCAT Rx Var 9",
    "", 0, 5, 1, 0, 0 },

  { 243, 39,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/AnomalyDetection/p1",
    "q_clean", 0, 0, 1, 0, 2 },

  { 244, 39,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/AnomalyDetection/p2",
    "ErrorCount", 1, 0, 1, 0, 2 },

  { 245, 40,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Rate Transition",
    "", 0, 0, 1, 0, 2 },

  { 246, 40,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Rate Transition3",
    "", 0, 0, 1, 0, 2 },

  { 247, 40,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Rate Transition4",
    "", 0, 0, 1, 0, 2 },

  { 248, 40,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Rate Transition5",
    "", 0, 0, 1, 0, 2 },

  { 249, 40,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Rate Transition6",
    "", 0, 0, 9, 0, 2 },

  { 250, 40,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Rate Transition7",
    "", 0, 2, 1, 0, 2 },

  { 251, 40,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Switch",
    "", 0, 0, 1, 0, 2 },

  { 252, 40,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/Unit Delay",
    "", 0, 0, 1, 0, 2 },

  { 253, 48,
    "DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/Subsystem/FIFO write 1",
    "", 0, 7, 1, 0, 3 },

  { 254, 48,
    "DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/Subsystem/Read HW FIFO",
    "", 0, 1, 10, 0, 3 },

  { 255, 47,
    "DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/UpdateOrientation/FIFO bin read ",
    "", 0, 1, 11, 0, 4 },

  { 256, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive",
    "", 0, 6, 1, 0, 0 },

  { 257, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive1",
    "", 0, 3, 1, 0, 0 },

  { 258, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive2",
    "", 0, 8, 1, 0, 0 },

  { 259, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive3",
    "", 0, 6, 1, 0, 0 },

  { 260, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive4",
    "", 0, 3, 1, 0, 0 },

  { 261, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem/EtherCAT PDO Receive5",
    "", 0, 5, 1, 0, 0 },

  { 262, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem1/Merge",
    "", 0, 5, 1, 0, 0 },

  { 263, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive",
    "", 0, 6, 1, 0, 0 },

  { 264, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive1",
    "", 0, 3, 1, 0, 0 },

  { 265, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive2",
    "", 0, 8, 1, 0, 0 },

  { 266, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive3",
    "", 0, 6, 1, 0, 0 },

  { 267, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive4",
    "", 0, 3, 1, 0, 0 },

  { 268, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem/EtherCAT PDO Receive5",
    "", 0, 5, 1, 0, 0 },

  { 269, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem1/Merge",
    "", 0, 5, 1, 0, 0 },

  { 270, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive",
    "", 0, 6, 1, 0, 0 },

  { 271, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive1",
    "", 0, 3, 1, 0, 0 },

  { 272, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive2",
    "", 0, 8, 1, 0, 0 },

  { 273, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive3",
    "", 0, 6, 1, 0, 0 },

  { 274, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive4",
    "", 0, 3, 1, 0, 0 },

  { 275, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem/EtherCAT PDO Receive5",
    "", 0, 5, 1, 0, 0 },

  { 276, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem1/Merge",
    "", 0, 5, 1, 0, 0 },

  { 277, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive",
    "", 0, 6, 1, 0, 0 },

  { 278, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive1",
    "", 0, 3, 1, 0, 0 },

  { 279, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive2",
    "", 0, 8, 1, 0, 0 },

  { 280, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive3",
    "", 0, 6, 1, 0, 0 },

  { 281, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive4",
    "", 0, 3, 1, 0, 0 },

  { 282, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem/EtherCAT PDO Receive5",
    "", 0, 5, 1, 0, 0 },

  { 283, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem1/Merge",
    "", 0, 5, 1, 0, 0 },

  { 284, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem2/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 285, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem3/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 286, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem4/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 287, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem5/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 288, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem2/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 289, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem3/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 290, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem4/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 291, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem5/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 292, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem2/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 293, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem3/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 294, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem4/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 295, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem5/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 296, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem2/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 297, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem3/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 298, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem4/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 299, 0,
    "DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem5/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

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

  //-----
  { 300, "AllowDoubleSupport", 0, 1, 0 },

  //----skip

  //-----
  { 301, "CommandSerialize", 0, 1, 0 },

  //----skip

  //-----
  { 302, "ControllerModeInit", 0, 1, 0 },

  //----skip

  //-----
  { 303, "DecouplingMode", 0, 1, 0 },

  //----skip

  //-----
  { 304, "DesiredYawOffset", 0, 1, 0 },

  //----skip

  //-----
  { 305, "EnableFeedforwardOnStep", 0, 1, 0 },

  //----skip

  //-----
  { 306, "EnableTransition", 0, 1, 0 },

  //----skip

  //-----
  { 307, "EnableVelocityBasedUpdate", 0, 1, 0 },

  //----skip

  //-----
  { 308, "ErrorVelZeroFactor", 0, 8, 0 },

  //----skip

  //-----
  { 309, "ErrorZeroFactor", 0, 8, 0 },

  //----skip

  //-----
  { 310, "FeedforwardGain", 0, 8, 0 },

  //----skip

  //-----
  { 311, "GearOffsets", 0, 12, 0 },

  //----skip

  //-----
  { 312, "H0Transition", 0, 13, 0 },

  //----skip

  //-----
  { 313, "H0WalkingDouble", 0, 13, 0 },

  //----skip

  //-----
  { 314, "H0WalkingSingle", 0, 13, 0 },

  //----skip

  //-----
  { 315, "HAlphaStarInjection", 0, 14, 0 },

  //----skip

  //-----
  { 316, "HAlphaStarPosing", 0, 14, 0 },

  //----skip

  //-----
  { 317, "HAlphaStarTransition", 0, 14, 0 },

  //----skip

  //-----
  { 318, "HAlphaStarWalkingDouble", 0, 14, 0 },

  //----skip

  //-----
  { 319, "HAlphaStarWalkingSingle", 0, 14, 0 },

  //----skip

  //-----
  { 320, "HAlphaTransition", 0, 14, 0 },

  //----skip

  //-----
  { 321, "HAlphaWalkingDouble", 0, 14, 0 },

  //----skip

  //-----
  { 322, "HAlphaWalkingSingle", 0, 14, 0 },

  //----skip

  //-----
  { 323, "HBarAlphaTransition", 0, 15, 0 },

  //----skip

  //-----
  { 324, "HBarAlphaWalkingDouble", 0, 15, 0 },

  //----skip

  //-----
  { 325, "HBarAlphaWalkingSingle", 0, 15, 0 },

  //----skip

  //-----
  { 326, "HBarLimitsTransition", 0, 16, 0 },

  //----skip

  //-----
  { 327, "HBarLimitsWalkingDouble", 0, 16, 0 },

  //----skip

  //-----
  { 328, "HBarLimitsWalkingSingle", 0, 16, 0 },

  //----skip

  //-----
  { 329, "IMUCommand", 0, 1, 0 },

  //----skip

  //-----
  { 330, "IMUThreshold", 0, 1, 0 },

  //----skip

  //-----
  { 331, "IMUTorsoOffsets", 0, 5, 0 },

  //----skip

  //-----
  { 332, "K1MidStanceUpdate", 0, 8, 0 },

  //----skip

  //-----
  { 333, "K2MidStanceUpdate", 0, 8, 0 },

  //----skip

  //-----
  { 334, "KASaturationEarly", 0, 1, 0 },

  //----skip

  //-----
  { 335, "KASaturationMax", 0, 1, 0 },

  //----skip

  //-----
  { 336, "KASaturationS1", 0, 1, 0 },

  //----skip

  //-----
  { 337, "KASaturationS2", 0, 1, 0 },

  //----skip

  //-----
  { 338, "KASpringOffsets", 0, 5, 0 },

  //----skip

  //-----
  { 339, "KThetaMinus", 0, 1, 0 },

  //----skip

  //-----
  { 340, "KThetaPlus", 0, 1, 0 },

  //----skip

  //-----
  { 341, "LegHipTorqueLimit", 0, 5, 0 },

  //----skip

  //-----
  { 342, "ManualSwap", 0, 1, 0 },

  //----skip

  //-----
  { 343, "MaxError", 0, 1, 0 },

  //----skip

  //-----
  { 344, "MaxErrorVel", 0, 1, 0 },

  //----skip

  //-----
  { 345, "MedullaCommand", 0, 1, 0 },

  //----skip

  //-----
  { 346, "MinDeltaTheta", 0, 1, 0 },

  //----skip

  //-----
  { 347, "MinDeltaThetaTransition", 0, 1, 0 },

  //----skip

  //-----
  { 348, "PhiOffset", 0, 1, 0 },

  //----skip

  //-----
  { 349, "RLimits", 0, 17, 0 },

  //----skip

  //-----
  { 350, "ResetControl", 0, 1, 0 },

  //----skip

  //-----
  { 351, "RollPhaseVelocityThresh", 0, 1, 0 },

  //----skip

  //-----
  { 352, "RunMode", 0, 1, 0 },

  //----skip

  //-----
  { 353, "SelectFeedforward", 0, 1, 0 },

  //----skip

  //-----
  { 354, "StanceLegInit", 0, 1, 0 },

  //----skip

  //-----
  { 355, "StartSecondGaitOnStep", 0, 1, 0 },

  //----skip

  //-----
  { 356, "TMaxUpdate", 0, 1, 0 },

  //----skip

  //-----
  { 357, "TPosing", 0, 1, 0 },

  //----skip

  //-----
  { 358, "Theta0", 0, 1, 0 },

  //----skip

  //-----
  { 359, "ThetaLimitsTransition", 0, 17, 0 },

  //----skip

  //-----
  { 360, "ThetaLimitsWalkingDouble", 0, 17, 0 },

  //----skip

  //-----
  { 361, "ThetaLimitsWalkingSingle", 0, 17, 0 },

  //----skip

  //-----
  { 362, "TorsoBackAngle", 0, 1, 0 },

  //----skip

  //-----
  { 363, "TorsoBackOnStep", 0, 1, 0 },

  //----skip

  //-----
  { 364, "TorsoCOMOffsets", 0, 5, 0 },

  //----skip

  //-----
  { 365, "UseKASaturation", 0, 1, 0 },

  //----skip

  //-----
  { 366, "UsePosingControl", 0, 1, 0 },

  //----skip

  //-----
  { 367, "VelocityBasedUpdateDTheta0", 0, 1, 0 },

  //----skip

  //-----
  { 368, "VelocityBasedUpdateK1", 0, 8, 0 },

  //----skip

  //-----
  { 369, "VelocityBasedUpdateK2", 0, 8, 0 },

  //----skip

  //-----
  { 370, "VelocityBasedUpdateLimits", 0, 16, 0 },

  //----skip

  //-----
  { 371, "VelocityControlTorsoGain", 0, 1, 0 },

  //----skip

  //-----
  { 372, "VelocityControlTorsoMax", 0, 1, 0 },

  //----skip

  //-----
  { 373, "VelocityControlTorsoMin", 0, 1, 0 },

  //----skip

  //-----
  { 374, "VelocityControlTorsoV0", 0, 1, 0 },

  //----skip

  //-----
  { 375, "YawLimit", 0, 1, 0 },

  //----skip

  //-----
  { 376, "epsilon", 0, 5, 0 },

  //----skip

  //-----
  { 377, "ff_params", 0, 3, 0 },

  //----skip

  //-----
  { 378, "hd_posing", 0, 8, 0 },

  //----skip

  //-----
  { 379, "k_precomp", 0, 1, 0 },

  //----skip

  //-----
  { 380, "kd", 0, 8, 0 },

  //----skip

  //-----
  { 381, "kd_2dof", 0, 1, 0 },

  //----skip

  //-----
  { 382, "kd_torso", 0, 5, 0 },

  //----skip

  //-----
  { 383, "kp", 0, 8, 0 },

  //----skip

  //-----
  { 384, "kp_2dof", 0, 1, 0 },

  //----skip

  //-----
  { 385, "lat_bias", 0, 1, 0 },

  //----skip

  //-----
  { 386, "lat_bias2", 0, 1, 0 },

  //----skip

  //-----
  { 387, "lateralParams", 0, 3, 0 },

  //----skip

  //-----
  { 388, "linkFeedback", 0, 1, 0 },

  //----skip

  //-----
  { 389, "optimal_sat_weights", 0, 5, 0 },

  //----skip

  //-----
  { 390, "step_params", 0, 3, 0 },

  //----skip

  //-----
  { 391, "swap_params", 0, 18, 0 },

  //----skip

  //-----
  { 392, "tStepInitial", 0, 1, 0 },

  //----skip

  //-----
  { 393, "transitionParams", 0, 3, 0 },

  //----skip

  //-----
  { 394, "u_ff", 0, 8, 0 },

  //----skip

  //-----
  { 395, "use2DOFHipControl", 0, 1, 0 },

  //----skip

  //-----
  { 396, "useOptimalSaturation", 0, 1, 0 },

  //----skip

  //-----
  { 397, "w_torso_lat", 0, 1, 0 },

  //----skip

  //-----
  { 398, "EnableFT", 2, 1, 0 },

  //----skip

  //-----
  { 399, "ResetDAQ", 2, 1, 0 },

  //----skip

  //-----
  { 400, "ResetYaw", 2, 1, 0 },

  { 0, NULL, 0, 0, 0 }
};

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &Walking01_withElmos_B.q[0],         /* 0: Signal */
  &Walking01_withElmos_B.MedullaCommandSafe,/* 1: Signal */
  &Walking01_withElmos_B.SafetyCountOut,/* 2: Signal */
  (void *) &Walking01_withElmos_ConstB.Gain,/* 3: Signal */
  &Walking01_withElmos_B.RateTransition,/* 4: Signal */
  &Walking01_withElmos_B.RateTransition1_p,/* 5: Signal */
  &Walking01_withElmos_B.GetOverloadCounter,/* 6: Signal */
  &Walking01_withElmos_B.GetOverloadCounter1,/* 7: Signal */
  &Walking01_withElmos_B.GetOverloadCounter2,/* 8: Signal */
  &Walking01_withElmos_B.Bias,         /* 9: Signal */
  &Walking01_withElmos_B.TaskExecutionTime,/* 10: Signal */
  &Walking01_withElmos_B.RateTransition1[0],/* 11: Signal */
  &Walking01_withElmos_B.RateTransition2[0],/* 12: Signal */
  &Walking01_withElmos_B.RateTransition3,/* 13: Signal */
  &Walking01_withElmos_B.ErrorCount,   /* 14: Signal */
  &Walking01_withElmos_B.s,            /* 15: Signal */
  &Walking01_withElmos_B.SerialOut[0], /* 16: Signal */
  &Walking01_withElmos_B.EnableTransition,/* 17: Signal */
  &Walking01_withElmos_B.ResetControl, /* 18: Signal */
  &Walking01_withElmos_B.DataTypeConversion1,/* 19: Signal */
  &Walking01_withElmos_B.sf_ComputeEulerAngles.ZYX[0],/* 20: Signal */
  &Walking01_withElmos_B.sf_ComputeEulerAngles.dZYX[0],/* 21: Signal */
  &Walking01_withElmos_B.sf_ComputeEulerAngles.Rk[0],/* 22: Signal */
  &Walking01_withElmos_B.sf_ComputeEulerAngles.R0[0],/* 23: Signal */
  &Walking01_withElmos_B.sf_ComputeEulerAngles.YawRollover[0],/* 24: Signal */
  &Walking01_withElmos_B.VectorConcatenate_m[0],/* 25: Signal */
  &Walking01_withElmos_B.VectorConcatenate_m[0],/* 26: Signal */
  &Walking01_withElmos_B.Rollover[0],  /* 27: Signal */
  &Walking01_withElmos_B.IncCalTick[0],/* 28: Signal */
  &Walking01_withElmos_B.VectorConcatenate_m[0],/* 29: Signal */
  &Walking01_withElmos_B.LogicalOperator1,/* 30: Signal */
  &Walking01_withElmos_B.LogicalOperator2,/* 31: Signal */
  &Walking01_withElmos_B.dq_clean[0],  /* 32: Signal */
  &Walking01_withElmos_B.FixPtRelationalOperator,/* 33: Signal */
  &Walking01_withElmos_B.VectorConcatenate_a[0],/* 34: Signal */
  &Walking01_withElmos_B.VectorConcatenate_a[0],/* 35: Signal */
  &Walking01_withElmos_B.VectorConcatenate_a[0],/* 36: Signal */
  &Walking01_withElmos_B.TKA[0],       /* 37: Signal */
  (void *) &Walking01_withElmos_ConstB.DataTypeConversion,/* 38: Signal */
  &Walking01_withElmos_B.DataTypeConversion104,/* 39: Signal */
  &Walking01_withElmos_B.DataTypeConversion119,/* 40: Signal */
  (void *) &Walking01_withElmos_ConstB.DataTypeConversion141[0],/* 41: Signal */
  &Walking01_withElmos_B.DataTypeConversion33,/* 42: Signal */
  &Walking01_withElmos_B.DataTypeConversion57,/* 43: Signal */
  &Walking01_withElmos_B.DataTypeConversion81,/* 44: Signal */
  &Walking01_withElmos_B.DataTypeConversion9,/* 45: Signal */
  &Walking01_withElmos_B.DataTypeConversion97[0],/* 46: Signal */
  &Walking01_withElmos_B.EtherCATInit[0],/* 47: Signal */
  &Walking01_withElmos_B.sf_ComputeEulerAngles_i.ZYX[0],/* 48: Signal */
  &Walking01_withElmos_B.sf_ComputeEulerAngles_i.dZYX[0],/* 49: Signal */
  &Walking01_withElmos_B.sf_ComputeEulerAngles_i.Rk[0],/* 50: Signal */
  &Walking01_withElmos_B.sf_ComputeEulerAngles_i.R0[0],/* 51: Signal */
  &Walking01_withElmos_B.sf_ComputeEulerAngles_i.YawRollover[0],/* 52: Signal */
  &Walking01_withElmos_B.Compare,      /* 53: Signal */
  &Walking01_withElmos_B.Compare_l,    /* 54: Signal */
  &Walking01_withElmos_B.CoreSubsys[18].sf_AnomalyDetection.q_clean,/* 55: Signal */
  &Walking01_withElmos_B.CoreSubsys[18].sf_AnomalyDetection.ErrorCount,/* 56: Signal */
  &Walking01_withElmos_B.CoreSubsys[18].DiscreteStateSpace,/* 57: Signal */
  &Walking01_withElmos_B.CoreSubsys[18].UnitDelay,/* 58: Signal */
  &Walking01_withElmos_B.DataTypeConversion3,/* 59: Signal */
  &Walking01_withElmos_B.DataTypeConversion4,/* 60: Signal */
  &Walking01_withElmos_B.DataTypeConversion5,/* 61: Signal */
  &Walking01_withElmos_B.EtherCATRxVar_i,/* 62: Signal */
  &Walking01_withElmos_B.EtherCATRxVar1_m,/* 63: Signal */
  &Walking01_withElmos_B.EtherCATRxVar12_pv,/* 64: Signal */
  &Walking01_withElmos_B.EtherCATRxVar13_e0,/* 65: Signal */
  &Walking01_withElmos_B.EtherCATRxVar14_b,/* 66: Signal */
  &Walking01_withElmos_B.EtherCATRxVar15_g,/* 67: Signal */
  &Walking01_withElmos_B.EtherCATRxVar16_d,/* 68: Signal */
  &Walking01_withElmos_B.EtherCATRxVar17_p,/* 69: Signal */
  &Walking01_withElmos_B.EtherCATRxVar18_h,/* 70: Signal */
  &Walking01_withElmos_B.EtherCATRxVar19_i,/* 71: Signal */
  &Walking01_withElmos_B.EtherCATRxVar2_i,/* 72: Signal */
  &Walking01_withElmos_B.EtherCATRxVar3_c,/* 73: Signal */
  &Walking01_withElmos_B.EtherCATRxVar4_nd,/* 74: Signal */
  &Walking01_withElmos_B.EtherCATRxVar5_d,/* 75: Signal */
  &Walking01_withElmos_B.EtherCATRxVar6_f,/* 76: Signal */
  &Walking01_withElmos_B.DataTypeConversion3_i,/* 77: Signal */
  &Walking01_withElmos_B.DataTypeConversion4_h,/* 78: Signal */
  &Walking01_withElmos_B.DataTypeConversion5_e,/* 79: Signal */
  &Walking01_withElmos_B.EtherCATRxVar,/* 80: Signal */
  &Walking01_withElmos_B.EtherCATRxVar1_p,/* 81: Signal */
  &Walking01_withElmos_B.EtherCATRxVar12_h,/* 82: Signal */
  &Walking01_withElmos_B.EtherCATRxVar13_e,/* 83: Signal */
  &Walking01_withElmos_B.EtherCATRxVar14_f,/* 84: Signal */
  &Walking01_withElmos_B.EtherCATRxVar15_b,/* 85: Signal */
  &Walking01_withElmos_B.EtherCATRxVar16_bt,/* 86: Signal */
  &Walking01_withElmos_B.EtherCATRxVar17_j,/* 87: Signal */
  &Walking01_withElmos_B.EtherCATRxVar18_j,/* 88: Signal */
  &Walking01_withElmos_B.EtherCATRxVar19_o,/* 89: Signal */
  &Walking01_withElmos_B.EtherCATRxVar2_g,/* 90: Signal */
  &Walking01_withElmos_B.EtherCATRxVar3_h,/* 91: Signal */
  &Walking01_withElmos_B.EtherCATRxVar4_m,/* 92: Signal */
  &Walking01_withElmos_B.EtherCATRxVar5_o,/* 93: Signal */
  &Walking01_withElmos_B.EtherCATRxVar6_a,/* 94: Signal */
  &Walking01_withElmos_B.sf_TypecastAndCast1.y[0],/* 95: Signal */
  &Walking01_withElmos_B.sf_TypecastAndCast2.y[0],/* 96: Signal */
  &Walking01_withElmos_B.DataTypeConversion1_l,/* 97: Signal */
  &Walking01_withElmos_B.DataTypeConversion3_j,/* 98: Signal */
  &Walking01_withElmos_B.DataTypeConversion4_a,/* 99: Signal */
  &Walking01_withElmos_B.EtherCATRxVar1,/* 100: Signal */
  &Walking01_withElmos_B.EtherCATRxVar10,/* 101: Signal */
  &Walking01_withElmos_B.EtherCATRxVar11,/* 102: Signal */
  &Walking01_withElmos_B.EtherCATRxVar12,/* 103: Signal */
  &Walking01_withElmos_B.EtherCATRxVar13,/* 104: Signal */
  &Walking01_withElmos_B.EtherCATRxVar14,/* 105: Signal */
  &Walking01_withElmos_B.EtherCATRxVar15_d,/* 106: Signal */
  &Walking01_withElmos_B.EtherCATRxVar16_k,/* 107: Signal */
  &Walking01_withElmos_B.EtherCATRxVar17_c,/* 108: Signal */
  &Walking01_withElmos_B.EtherCATRxVar18_k,/* 109: Signal */
  &Walking01_withElmos_B.EtherCATRxVar19,/* 110: Signal */
  &Walking01_withElmos_B.EtherCATRxVar2,/* 111: Signal */
  &Walking01_withElmos_B.EtherCATRxVar3,/* 112: Signal */
  &Walking01_withElmos_B.EtherCATRxVar4_ph,/* 113: Signal */
  &Walking01_withElmos_B.EtherCATRxVar5,/* 114: Signal */
  &Walking01_withElmos_B.EtherCATRxVar6,/* 115: Signal */
  &Walking01_withElmos_B.EtherCATRxVar7,/* 116: Signal */
  &Walking01_withElmos_B.EtherCATRxVar8_m,/* 117: Signal */
  &Walking01_withElmos_B.EtherCATRxVar9,/* 118: Signal */
  &Walking01_withElmos_B.ControlWordIndex_j,/* 119: Signal */
  &Walking01_withElmos_B.EnableTargetTorque_f,/* 120: Signal */
  &Walking01_withElmos_B.FaultDetected_n,/* 121: Signal */
  &Walking01_withElmos_B.Switch,       /* 122: Signal */
  &Walking01_withElmos_B.sf_Chart.ControlWordIndex,/* 123: Signal */
  &Walking01_withElmos_B.sf_Chart.EnableTargetTorque,/* 124: Signal */
  &Walking01_withElmos_B.sf_Chart.FaultDetected,/* 125: Signal */
  &Walking01_withElmos_B.Switch_a,     /* 126: Signal */
  &Walking01_withElmos_B.ControlWordIndex,/* 127: Signal */
  &Walking01_withElmos_B.EnableTargetTorque,/* 128: Signal */
  &Walking01_withElmos_B.FaultDetected,/* 129: Signal */
  &Walking01_withElmos_B.Switch_d,     /* 130: Signal */
  &Walking01_withElmos_B.sf_Chart_b.ControlWordIndex,/* 131: Signal */
  &Walking01_withElmos_B.sf_Chart_b.EnableTargetTorque,/* 132: Signal */
  &Walking01_withElmos_B.sf_Chart_b.FaultDetected,/* 133: Signal */
  &Walking01_withElmos_B.Switch_i,     /* 134: Signal */
  &Walking01_withElmos_B.DataTypeConversion3_f,/* 135: Signal */
  &Walking01_withElmos_B.DataTypeConversion4_k,/* 136: Signal */
  &Walking01_withElmos_B.DataTypeConversion5_n,/* 137: Signal */
  &Walking01_withElmos_B.EtherCATRxVar_o,/* 138: Signal */
  &Walking01_withElmos_B.EtherCATRxVar1_h,/* 139: Signal */
  &Walking01_withElmos_B.EtherCATRxVar10_b,/* 140: Signal */
  &Walking01_withElmos_B.EtherCATRxVar11_h,/* 141: Signal */
  &Walking01_withElmos_B.EtherCATRxVar12_b,/* 142: Signal */
  &Walking01_withElmos_B.EtherCATRxVar13_j,/* 143: Signal */
  &Walking01_withElmos_B.EtherCATRxVar14_fm,/* 144: Signal */
  &Walking01_withElmos_B.EtherCATRxVar15_n,/* 145: Signal */
  &Walking01_withElmos_B.EtherCATRxVar16_j,/* 146: Signal */
  &Walking01_withElmos_B.EtherCATRxVar17_l,/* 147: Signal */
  &Walking01_withElmos_B.EtherCATRxVar18_i,/* 148: Signal */
  &Walking01_withElmos_B.EtherCATRxVar19_e,/* 149: Signal */
  &Walking01_withElmos_B.EtherCATRxVar2_o,/* 150: Signal */
  &Walking01_withElmos_B.EtherCATRxVar20_c,/* 151: Signal */
  &Walking01_withElmos_B.EtherCATRxVar21_o,/* 152: Signal */
  &Walking01_withElmos_B.EtherCATRxVar22_g,/* 153: Signal */
  &Walking01_withElmos_B.EtherCATRxVar23,/* 154: Signal */
  &Walking01_withElmos_B.EtherCATRxVar3_j,/* 155: Signal */
  &Walking01_withElmos_B.EtherCATRxVar4_n,/* 156: Signal */
  &Walking01_withElmos_B.EtherCATRxVar5_n,/* 157: Signal */
  &Walking01_withElmos_B.EtherCATRxVar6_b,/* 158: Signal */
  &Walking01_withElmos_B.EtherCATRxVar7_b,/* 159: Signal */
  &Walking01_withElmos_B.EtherCATRxVar8_b,/* 160: Signal */
  &Walking01_withElmos_B.EtherCATRxVar9_p,/* 161: Signal */
  &Walking01_withElmos_B.DataTypeConversion3_g,/* 162: Signal */
  &Walking01_withElmos_B.DataTypeConversion4_i,/* 163: Signal */
  &Walking01_withElmos_B.DataTypeConversion5_b,/* 164: Signal */
  &Walking01_withElmos_B.EtherCATRxVar_h,/* 165: Signal */
  &Walking01_withElmos_B.EtherCATRxVar1_f,/* 166: Signal */
  &Walking01_withElmos_B.EtherCATRxVar10_c,/* 167: Signal */
  &Walking01_withElmos_B.EtherCATRxVar11_b,/* 168: Signal */
  &Walking01_withElmos_B.EtherCATRxVar12_p,/* 169: Signal */
  &Walking01_withElmos_B.EtherCATRxVar13_h,/* 170: Signal */
  &Walking01_withElmos_B.EtherCATRxVar14_h,/* 171: Signal */
  &Walking01_withElmos_B.EtherCATRxVar15,/* 172: Signal */
  &Walking01_withElmos_B.EtherCATRxVar16,/* 173: Signal */
  &Walking01_withElmos_B.EtherCATRxVar17,/* 174: Signal */
  &Walking01_withElmos_B.EtherCATRxVar18,/* 175: Signal */
  &Walking01_withElmos_B.EtherCATRxVar19_c,/* 176: Signal */
  &Walking01_withElmos_B.EtherCATRxVar2_n,/* 177: Signal */
  &Walking01_withElmos_B.EtherCATRxVar20_p,/* 178: Signal */
  &Walking01_withElmos_B.EtherCATRxVar21,/* 179: Signal */
  &Walking01_withElmos_B.EtherCATRxVar22,/* 180: Signal */
  &Walking01_withElmos_B.EtherCATRxVar23_e,/* 181: Signal */
  &Walking01_withElmos_B.EtherCATRxVar3_c4,/* 182: Signal */
  &Walking01_withElmos_B.EtherCATRxVar4,/* 183: Signal */
  &Walking01_withElmos_B.EtherCATRxVar5_k,/* 184: Signal */
  &Walking01_withElmos_B.EtherCATRxVar6_n,/* 185: Signal */
  &Walking01_withElmos_B.EtherCATRxVar7_g,/* 186: Signal */
  &Walking01_withElmos_B.EtherCATRxVar8,/* 187: Signal */
  &Walking01_withElmos_B.EtherCATRxVar9_i,/* 188: Signal */
  &Walking01_withElmos_B.DataTypeConversion3_o,/* 189: Signal */
  &Walking01_withElmos_B.DataTypeConversion4_n,/* 190: Signal */
  &Walking01_withElmos_B.DataTypeConversion5_by,/* 191: Signal */
  &Walking01_withElmos_B.EtherCATRxVar_p,/* 192: Signal */
  &Walking01_withElmos_B.EtherCATRxVar1_b,/* 193: Signal */
  &Walking01_withElmos_B.EtherCATRxVar10_g,/* 194: Signal */
  &Walking01_withElmos_B.EtherCATRxVar11_l,/* 195: Signal */
  &Walking01_withElmos_B.EtherCATRxVar12_i,/* 196: Signal */
  &Walking01_withElmos_B.EtherCATRxVar13_c,/* 197: Signal */
  &Walking01_withElmos_B.EtherCATRxVar14_n,/* 198: Signal */
  &Walking01_withElmos_B.EtherCATRxVar15_a,/* 199: Signal */
  &Walking01_withElmos_B.EtherCATRxVar16_a,/* 200: Signal */
  &Walking01_withElmos_B.EtherCATRxVar17_kd,/* 201: Signal */
  &Walking01_withElmos_B.EtherCATRxVar18_f,/* 202: Signal */
  &Walking01_withElmos_B.EtherCATRxVar19_d,/* 203: Signal */
  &Walking01_withElmos_B.EtherCATRxVar2_m,/* 204: Signal */
  &Walking01_withElmos_B.EtherCATRxVar20,/* 205: Signal */
  &Walking01_withElmos_B.EtherCATRxVar21_m,/* 206: Signal */
  &Walking01_withElmos_B.EtherCATRxVar22_a,/* 207: Signal */
  &Walking01_withElmos_B.EtherCATRxVar23_c,/* 208: Signal */
  &Walking01_withElmos_B.EtherCATRxVar3_o,/* 209: Signal */
  &Walking01_withElmos_B.EtherCATRxVar4_e,/* 210: Signal */
  &Walking01_withElmos_B.EtherCATRxVar5_l,/* 211: Signal */
  &Walking01_withElmos_B.EtherCATRxVar6_m,/* 212: Signal */
  &Walking01_withElmos_B.EtherCATRxVar7_gy,/* 213: Signal */
  &Walking01_withElmos_B.EtherCATRxVar8_bs,/* 214: Signal */
  &Walking01_withElmos_B.EtherCATRxVar9_a,/* 215: Signal */
  &Walking01_withElmos_B.DataTypeConversion3_f2,/* 216: Signal */
  &Walking01_withElmos_B.DataTypeConversion4_o,/* 217: Signal */
  &Walking01_withElmos_B.DataTypeConversion5_a,/* 218: Signal */
  &Walking01_withElmos_B.EtherCATRxVar_k,/* 219: Signal */
  &Walking01_withElmos_B.EtherCATRxVar1_pm,/* 220: Signal */
  &Walking01_withElmos_B.EtherCATRxVar10_f,/* 221: Signal */
  &Walking01_withElmos_B.EtherCATRxVar11_a,/* 222: Signal */
  &Walking01_withElmos_B.EtherCATRxVar12_c,/* 223: Signal */
  &Walking01_withElmos_B.EtherCATRxVar13_o,/* 224: Signal */
  &Walking01_withElmos_B.EtherCATRxVar14_g,/* 225: Signal */
  &Walking01_withElmos_B.EtherCATRxVar15_m,/* 226: Signal */
  &Walking01_withElmos_B.EtherCATRxVar16_b,/* 227: Signal */
  &Walking01_withElmos_B.EtherCATRxVar17_k,/* 228: Signal */
  &Walking01_withElmos_B.EtherCATRxVar18_c,/* 229: Signal */
  &Walking01_withElmos_B.EtherCATRxVar19_m,/* 230: Signal */
  &Walking01_withElmos_B.EtherCATRxVar2_p,/* 231: Signal */
  &Walking01_withElmos_B.EtherCATRxVar20_l,/* 232: Signal */
  &Walking01_withElmos_B.EtherCATRxVar21_b,/* 233: Signal */
  &Walking01_withElmos_B.EtherCATRxVar22_o,/* 234: Signal */
  &Walking01_withElmos_B.EtherCATRxVar23_p,/* 235: Signal */
  &Walking01_withElmos_B.EtherCATRxVar3_k,/* 236: Signal */
  &Walking01_withElmos_B.EtherCATRxVar4_p,/* 237: Signal */
  &Walking01_withElmos_B.EtherCATRxVar5_p,/* 238: Signal */
  &Walking01_withElmos_B.EtherCATRxVar6_o,/* 239: Signal */
  &Walking01_withElmos_B.EtherCATRxVar7_d,/* 240: Signal */
  &Walking01_withElmos_B.EtherCATRxVar8_h,/* 241: Signal */
  &Walking01_withElmos_B.EtherCATRxVar9_j,/* 242: Signal */
  &Walking01_withElmos_B.CoreSubsys_p[2].sf_AnomalyDetection.q_clean,/* 243: Signal */
  &Walking01_withElmos_B.CoreSubsys_p[2].sf_AnomalyDetection.ErrorCount,/* 244: Signal */
  &Walking01_withElmos_B.CoreSubsys_p[2].RateTransition,/* 245: Signal */
  &Walking01_withElmos_B.CoreSubsys_p[2].RateTransition3,/* 246: Signal */
  &Walking01_withElmos_B.CoreSubsys_p[2].RateTransition4,/* 247: Signal */
  &Walking01_withElmos_B.CoreSubsys_p[2].RateTransition5,/* 248: Signal */
  &Walking01_withElmos_B.CoreSubsys_p[2].RateTransition6[0],/* 249: Signal */
  &Walking01_withElmos_B.CoreSubsys_p[2].RateTransition7,/* 250: Signal */
  &Walking01_withElmos_B.CoreSubsys_p[2].Switch,/* 251: Signal */
  &Walking01_withElmos_B.CoreSubsys_p[2].UnitDelay,/* 252: Signal */
  &Walking01_withElmos_B.FIFOwrite1,   /* 253: Signal */
  &Walking01_withElmos_B.ReadHWFIFO[0],/* 254: Signal */
  &Walking01_withElmos_B.FIFObinread[0],/* 255: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive_n,/* 256: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive1_n,/* 257: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive2,/* 258: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive3_j,/* 259: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive4_b,/* 260: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive5_h,/* 261: Signal */
  &Walking01_withElmos_B.Merge,        /* 262: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive,/* 263: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive1,/* 264: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive2_k,/* 265: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive3,/* 266: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive4,/* 267: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive5,/* 268: Signal */
  &Walking01_withElmos_B.Merge_l,      /* 269: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive_nq,/* 270: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive1_i,/* 271: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive2_l,/* 272: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive3_n,/* 273: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive4_p,/* 274: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive5_p,/* 275: Signal */
  &Walking01_withElmos_B.Merge_h,      /* 276: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive_b,/* 277: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive1_f,/* 278: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive2_h,/* 279: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive3_b,/* 280: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive4_d,/* 281: Signal */
  &Walking01_withElmos_B.EtherCATPDOReceive5_d,/* 282: Signal */
  &Walking01_withElmos_B.Merge_e,      /* 283: Signal */
  &Walking01_withElmos_B.Compare_pz,   /* 284: Signal */
  &Walking01_withElmos_B.Compare_h,    /* 285: Signal */
  &Walking01_withElmos_B.Compare_e5,   /* 286: Signal */
  &Walking01_withElmos_B.Compare_g,    /* 287: Signal */
  &Walking01_withElmos_B.Compare_n,    /* 288: Signal */
  &Walking01_withElmos_B.Compare_lw,   /* 289: Signal */
  &Walking01_withElmos_B.Compare_a,    /* 290: Signal */
  &Walking01_withElmos_B.Compare_e,    /* 291: Signal */
  &Walking01_withElmos_B.Compare_n4,   /* 292: Signal */
  &Walking01_withElmos_B.Compare_f,    /* 293: Signal */
  &Walking01_withElmos_B.Compare_co,   /* 294: Signal */
  &Walking01_withElmos_B.Compare_ju,   /* 295: Signal */
  &Walking01_withElmos_B.Compare_p,    /* 296: Signal */
  &Walking01_withElmos_B.Compare_i,    /* 297: Signal */
  &Walking01_withElmos_B.Compare_j,    /* 298: Signal */
  &Walking01_withElmos_B.Compare_c,    /* 299: Signal */
  &Walking01_withElmos_P.AllowDoubleSupport,/* 300: Model Parameter */
  &Walking01_withElmos_P.CommandSerialize,/* 301: Model Parameter */
  &Walking01_withElmos_P.ControllerModeInit,/* 302: Model Parameter */
  &Walking01_withElmos_P.DecouplingMode,/* 303: Model Parameter */
  &Walking01_withElmos_P.DesiredYawOffset,/* 304: Model Parameter */
  &Walking01_withElmos_P.EnableFeedforwardOnStep,/* 305: Model Parameter */
  &Walking01_withElmos_P.EnableTransition,/* 306: Model Parameter */
  &Walking01_withElmos_P.EnableVelocityBasedUpdate,/* 307: Model Parameter */
  &Walking01_withElmos_P.ErrorVelZeroFactor[0],/* 308: Model Parameter */
  &Walking01_withElmos_P.ErrorZeroFactor[0],/* 309: Model Parameter */
  &Walking01_withElmos_P.FeedforwardGain[0],/* 310: Model Parameter */
  &Walking01_withElmos_P.GearOffsets[0],/* 311: Model Parameter */
  &Walking01_withElmos_P.H0Transition[0],/* 312: Model Parameter */
  &Walking01_withElmos_P.H0WalkingDouble[0],/* 313: Model Parameter */
  &Walking01_withElmos_P.H0WalkingSingle[0],/* 314: Model Parameter */
  &Walking01_withElmos_P.HAlphaStarInjection[0],/* 315: Model Parameter */
  &Walking01_withElmos_P.HAlphaStarPosing[0],/* 316: Model Parameter */
  &Walking01_withElmos_P.HAlphaStarTransition[0],/* 317: Model Parameter */
  &Walking01_withElmos_P.HAlphaStarWalkingDouble[0],/* 318: Model Parameter */
  &Walking01_withElmos_P.HAlphaStarWalkingSingle[0],/* 319: Model Parameter */
  &Walking01_withElmos_P.HAlphaTransition[0],/* 320: Model Parameter */
  &Walking01_withElmos_P.HAlphaWalkingDouble[0],/* 321: Model Parameter */
  &Walking01_withElmos_P.HAlphaWalkingSingle[0],/* 322: Model Parameter */
  &Walking01_withElmos_P.HBarAlphaTransition[0],/* 323: Model Parameter */
  &Walking01_withElmos_P.HBarAlphaWalkingDouble[0],/* 324: Model Parameter */
  &Walking01_withElmos_P.HBarAlphaWalkingSingle[0],/* 325: Model Parameter */
  &Walking01_withElmos_P.HBarLimitsTransition[0],/* 326: Model Parameter */
  &Walking01_withElmos_P.HBarLimitsWalkingDouble[0],/* 327: Model Parameter */
  &Walking01_withElmos_P.HBarLimitsWalkingSingle[0],/* 328: Model Parameter */
  &Walking01_withElmos_P.IMUCommand,   /* 329: Model Parameter */
  &Walking01_withElmos_P.IMUThreshold, /* 330: Model Parameter */
  &Walking01_withElmos_P.IMUTorsoOffsets[0],/* 331: Model Parameter */
  &Walking01_withElmos_P.K1MidStanceUpdate[0],/* 332: Model Parameter */
  &Walking01_withElmos_P.K2MidStanceUpdate[0],/* 333: Model Parameter */
  &Walking01_withElmos_P.KASaturationEarly,/* 334: Model Parameter */
  &Walking01_withElmos_P.KASaturationMax,/* 335: Model Parameter */
  &Walking01_withElmos_P.KASaturationS1,/* 336: Model Parameter */
  &Walking01_withElmos_P.KASaturationS2,/* 337: Model Parameter */
  &Walking01_withElmos_P.KASpringOffsets[0],/* 338: Model Parameter */
  &Walking01_withElmos_P.KThetaMinus,  /* 339: Model Parameter */
  &Walking01_withElmos_P.KThetaPlus,   /* 340: Model Parameter */
  &Walking01_withElmos_P.LegHipTorqueLimit[0],/* 341: Model Parameter */
  &Walking01_withElmos_P.ManualSwap,   /* 342: Model Parameter */
  &Walking01_withElmos_P.MaxError,     /* 343: Model Parameter */
  &Walking01_withElmos_P.MaxErrorVel,  /* 344: Model Parameter */
  &Walking01_withElmos_P.MedullaCommand,/* 345: Model Parameter */
  &Walking01_withElmos_P.MinDeltaTheta,/* 346: Model Parameter */
  &Walking01_withElmos_P.MinDeltaThetaTransition,/* 347: Model Parameter */
  &Walking01_withElmos_P.PhiOffset,    /* 348: Model Parameter */
  &Walking01_withElmos_P.RLimits[0],   /* 349: Model Parameter */
  &Walking01_withElmos_P.ResetControl, /* 350: Model Parameter */
  &Walking01_withElmos_P.RollPhaseVelocityThresh,/* 351: Model Parameter */
  &Walking01_withElmos_P.RunMode,      /* 352: Model Parameter */
  &Walking01_withElmos_P.SelectFeedforward,/* 353: Model Parameter */
  &Walking01_withElmos_P.StanceLegInit,/* 354: Model Parameter */
  &Walking01_withElmos_P.StartSecondGaitOnStep,/* 355: Model Parameter */
  &Walking01_withElmos_P.TMaxUpdate,   /* 356: Model Parameter */
  &Walking01_withElmos_P.TPosing,      /* 357: Model Parameter */
  &Walking01_withElmos_P.Theta0,       /* 358: Model Parameter */
  &Walking01_withElmos_P.ThetaLimitsTransition[0],/* 359: Model Parameter */
  &Walking01_withElmos_P.ThetaLimitsWalkingDouble[0],/* 360: Model Parameter */
  &Walking01_withElmos_P.ThetaLimitsWalkingSingle[0],/* 361: Model Parameter */
  &Walking01_withElmos_P.TorsoBackAngle,/* 362: Model Parameter */
  &Walking01_withElmos_P.TorsoBackOnStep,/* 363: Model Parameter */
  &Walking01_withElmos_P.TorsoCOMOffsets[0],/* 364: Model Parameter */
  &Walking01_withElmos_P.UseKASaturation,/* 365: Model Parameter */
  &Walking01_withElmos_P.UsePosingControl,/* 366: Model Parameter */
  &Walking01_withElmos_P.VelocityBasedUpdateDTheta0,/* 367: Model Parameter */
  &Walking01_withElmos_P.VelocityBasedUpdateK1[0],/* 368: Model Parameter */
  &Walking01_withElmos_P.VelocityBasedUpdateK2[0],/* 369: Model Parameter */
  &Walking01_withElmos_P.VelocityBasedUpdateLimits[0],/* 370: Model Parameter */
  &Walking01_withElmos_P.VelocityControlTorsoGain,/* 371: Model Parameter */
  &Walking01_withElmos_P.VelocityControlTorsoMax,/* 372: Model Parameter */
  &Walking01_withElmos_P.VelocityControlTorsoMin,/* 373: Model Parameter */
  &Walking01_withElmos_P.VelocityControlTorsoV0,/* 374: Model Parameter */
  &Walking01_withElmos_P.YawLimit,     /* 375: Model Parameter */
  &Walking01_withElmos_P.epsilon[0],   /* 376: Model Parameter */
  &Walking01_withElmos_P.ff_params[0], /* 377: Model Parameter */
  &Walking01_withElmos_P.hd_posing[0], /* 378: Model Parameter */
  &Walking01_withElmos_P.k_precomp,    /* 379: Model Parameter */
  &Walking01_withElmos_P.kd[0],        /* 380: Model Parameter */
  &Walking01_withElmos_P.kd_2dof,      /* 381: Model Parameter */
  &Walking01_withElmos_P.kd_torso[0],  /* 382: Model Parameter */
  &Walking01_withElmos_P.kp[0],        /* 383: Model Parameter */
  &Walking01_withElmos_P.kp_2dof,      /* 384: Model Parameter */
  &Walking01_withElmos_P.lat_bias,     /* 385: Model Parameter */
  &Walking01_withElmos_P.lat_bias2,    /* 386: Model Parameter */
  &Walking01_withElmos_P.lateralParams[0],/* 387: Model Parameter */
  &Walking01_withElmos_P.linkFeedback, /* 388: Model Parameter */
  &Walking01_withElmos_P.optimal_sat_weights[0],/* 389: Model Parameter */
  &Walking01_withElmos_P.step_params[0],/* 390: Model Parameter */
  &Walking01_withElmos_P.swap_params[0],/* 391: Model Parameter */
  &Walking01_withElmos_P.tStepInitial, /* 392: Model Parameter */
  &Walking01_withElmos_P.transitionParams[0],/* 393: Model Parameter */
  &Walking01_withElmos_P.u_ff[0],      /* 394: Model Parameter */
  &Walking01_withElmos_P.use2DOFHipControl,/* 395: Model Parameter */
  &Walking01_withElmos_P.useOptimalSaturation,/* 396: Model Parameter */
  &Walking01_withElmos_P.w_torso_lat,  /* 397: Model Parameter */
  &Walking01_withElmos_P.EnableFT,     /* 398: Model Parameter */
  &Walking01_withElmos_P.ResetDAQ,     /* 399: Model Parameter */
  &Walking01_withElmos_P.ResetYaw      /* 400: Model Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "int", "int32_T", 0, 0, sizeof(int32_T), SS_INT32, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "unsigned short", "uint16_T", 0, 0, sizeof(uint16_T), SS_UINT16, 0, 0 },

  { "short", "int16_T", 0, 0, sizeof(int16_T), SS_INT16, 0, 0 },

  { "numeric", "serialfifoptr", 0, 0, sizeof(serialfifoptr), SS_STRUCT, 0, 0 },

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
  { rtwCAPI_VECTOR, 0, 2, 0 },

  { rtwCAPI_SCALAR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 8, 2, 0 },

  { rtwCAPI_VECTOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_VECTOR, 14, 2, 0 },

  { rtwCAPI_VECTOR, 16, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 18, 2, 0 },

  { rtwCAPI_VECTOR, 20, 2, 0 },

  { rtwCAPI_VECTOR, 22, 2, 0 },

  { rtwCAPI_VECTOR, 24, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 26, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 28, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 30, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 32, 2, 0 },

  { rtwCAPI_VECTOR, 18, 2, 0 },

  { rtwCAPI_VECTOR, 34, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  13,                                  /* 0 */
  1,                                   /* 1 */
  1,                                   /* 2 */
  1,                                   /* 3 */
  3,                                   /* 4 */
  1,                                   /* 5 */
  5,                                   /* 6 */
  1,                                   /* 7 */
  3,                                   /* 8 */
  3,                                   /* 9 */
  2,                                   /* 10 */
  1,                                   /* 11 */
  19,                                  /* 12 */
  1,                                   /* 13 */
  9,                                   /* 14 */
  1,                                   /* 15 */
  6,                                   /* 16 */
  1,                                   /* 17 */
  1,                                   /* 18 */
  2,                                   /* 19 */
  65,                                  /* 20 */
  1,                                   /* 21 */
  37,                                  /* 22 */
  1,                                   /* 23 */
  4,                                   /* 24 */
  1,                                   /* 25 */
  6,                                   /* 26 */
  13,                                  /* 27 */
  6,                                   /* 28 */
  6,                                   /* 29 */
  6,                                   /* 30 */
  5,                                   /* 31 */
  6,                                   /* 32 */
  2,                                   /* 33 */
  7,                                   /* 34 */
  1                                    /* 35 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.0005, 0.0, 0.002, 0.001
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

  { (NULL), (NULL), -2, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[1],
    2, 0 },

  { (const void *) &rtcapiStoredFloats[3], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (NULL), (NULL), -1, 0 }
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
  { rtBlockSignals, 300 },

  { rtBlockParameters, 0,
    rtModelParameters, 101 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 654870487U,
    1233570073U,
    4040884438U,
    4144415613U },
  NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void Walking01_withElmos_InitializeDataMapInfo(RT_MODEL_Walking01_withElmos_T
  *Walking01_withElmos_M
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(Walking01_withElmos_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(Walking01_withElmos_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(Walking01_withElmos_M->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(Walking01_withElmos_M->DataMapInfo.mmi,
    rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(Walking01_withElmos_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(Walking01_withElmos_M->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(Walking01_withElmos_M->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(Walking01_withElmos_M->DataMapInfo.mmi, 0);
}

/* EOF: Walking01_withElmos_capi.c */
