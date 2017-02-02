/*
 * Walking_ATRIAS.h
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
#ifndef RTW_HEADER_Walking_ATRIAS_h_
#define RTW_HEADER_Walking_ATRIAS_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include "rtw_modelmap.h"
#ifndef Walking_ATRIAS_COMMON_INCLUDES_
# define Walking_ATRIAS_COMMON_INCLUDES_
#include <xpcimports.h>
#include <xpcdatatypes.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "stddef.h"
#include "stdlib.h"
#include "xpcethercatutils.h"
#include "xpctarget.h"
#include "io_config_xml_3.h"
#endif                                 /* Walking_ATRIAS_COMMON_INCLUDES_ */

#include "Walking_ATRIAS_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) 0
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)
#define rtModel_Walking_ATRIAS         RT_MODEL_Walking_ATRIAS_T

/* Definition for use in the target main file */
#define Walking_ATRIAS_rtModel         RT_MODEL_Walking_ATRIAS_T

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals for system '<S43>/CoreSubsys' */
typedef struct {
  real_T Uk1;                          /* '<S53>/UD' */
  real_T Diff;                         /* '<S53>/Diff' */
  real_T Gain1;                        /* '<S52>/Gain1' */
  real_T two_pole_filter;              /* '<S52>/two_pole_filter' */
  real_T UnitDelay2;                   /* '<S50>/Unit Delay2' */
  real_T UnitDelay1;                   /* '<S50>/Unit Delay1' */
  real_T dq_out;                       /* '<S50>/Logic Filter' */
  real_T dq_good;                      /* '<S50>/Logic Filter' */
} B_CoreSubsys_Walking_ATRIAS_T;

/* Block states (auto storage) for system '<S43>/CoreSubsys' */
typedef struct {
  real_T UD_DSTATE;                    /* '<S53>/UD' */
  real_T two_pole_filter_states[2];    /* '<S52>/two_pole_filter' */
  real_T UnitDelay2_DSTATE;            /* '<S50>/Unit Delay2' */
  real_T UnitDelay1_DSTATE;            /* '<S50>/Unit Delay1' */
  real_T two_pole_filter_tmp;          /* '<S52>/two_pole_filter' */
} DW_CoreSubsys_Walking_ATRIAS_T;

/* Block states (auto storage) for system '<S73>/ShutdownControlWord' */
typedef struct {
  int8_T ShutdownControlWord_SubsysRanBC;/* '<S73>/ShutdownControlWord' */
} DW_ShutdownControlWord_Walkin_T;

/* Block states (auto storage) for system '<S73>/EnableControlWord' */
typedef struct {
  int8_T EnableControlWord_SubsysRanBC;/* '<S73>/EnableControlWord' */
} DW_EnableControlWord_Walking__T;

/* Block states (auto storage) for system '<S73>/FaultReset' */
typedef struct {
  int8_T FaultReset_SubsysRanBC;       /* '<S73>/FaultReset' */
} DW_FaultReset_Walking_ATRIAS_T;

/* Block states (auto storage) for system '<S73>/NothingControlWord' */
typedef struct {
  int8_T NothingControlWord_SubsysRanBC;/* '<S73>/NothingControlWord' */
} DW_NothingControlWord_Walking_T;

/* Block signals for system '<S63>/Chart' */
typedef struct {
  real_T ControlWordIndex;             /* '<S63>/Chart' */
  real_T EnableTargetTorque;           /* '<S63>/Chart' */
  real_T FaultDetected;                /* '<S63>/Chart' */
} B_Chart_Walking_ATRIAS_T;

/* Block states (auto storage) for system '<S63>/Chart' */
typedef struct {
  real_T Timeout;                      /* '<S63>/Chart' */
  int32_T sfEvent;                     /* '<S63>/Chart' */
  uint8_T is_active_c44_Walking_ATRIAS;/* '<S63>/Chart' */
  uint8_T is_c44_Walking_ATRIAS;       /* '<S63>/Chart' */
  uint8_T is_Initialization;           /* '<S63>/Chart' */
  boolean_T isStable;                  /* '<S63>/Chart' */
} DW_Chart_Walking_ATRIAS_T;

/* Block signals (auto storage) */
typedef struct {
  real_T DataTypeConversion49;         /* '<S45>/Data Type Conversion49' */
  real_T DataTypeConversion73;         /* '<S45>/Data Type Conversion73' */
  real_T DataTypeConversion3;          /* '<S45>/Data Type Conversion3' */
  real_T DataTypeConversion25;         /* '<S45>/Data Type Conversion25' */
  real_T DataTypeConversion50;         /* '<S45>/Data Type Conversion50' */
  real_T DataTypeConversion74;         /* '<S45>/Data Type Conversion74' */
  real_T DataTypeConversion1;          /* '<S45>/Data Type Conversion1' */
  real_T DataTypeConversion26;         /* '<S45>/Data Type Conversion26' */
  real_T DataTypeConversion98;         /* '<S45>/Data Type Conversion98' */
  real_T DataTypeConversion114;        /* '<S45>/Data Type Conversion114' */
  real_T DataTypeConversion57;         /* '<S45>/Data Type Conversion57' */
  real_T DataTypeConversion81;         /* '<S45>/Data Type Conversion81' */
  real_T DataTypeConversion9;          /* '<S45>/Data Type Conversion9' */
  real_T DataTypeConversion33;         /* '<S45>/Data Type Conversion33' */
  real_T DataTypeConversion104;        /* '<S45>/Data Type Conversion104' */
  real_T DataTypeConversion119;        /* '<S45>/Data Type Conversion119' */
  real_T UnitDelay1[9];                /* '<S38>/Unit Delay1' */
  real_T UnitDelay[9];                 /* '<S38>/Unit Delay' */
  real_T UnitDelay2[6];                /* '<S38>/Unit Delay2' */
  real_T VectorConcatenate[19];        /* '<S38>/Vector Concatenate' */
  real_T DataTypeConversion20[3];      /* '<S45>/Data Type Conversion20' */
  real_T DataTypeConversion22[3];      /* '<S45>/Data Type Conversion22' */
  real_T DataTypeConversion17;         /* '<S45>/Data Type Conversion17' */
  real_T DataTypeConversion24;         /* '<S45>/Data Type Conversion24' */
  real_T UnitDelay6[9];                /* '<S38>/Unit Delay6' */
  real_T UnitDelay7[3];                /* '<S38>/Unit Delay7' */
  real_T UnitDelay5[3];                /* '<S38>/Unit Delay5' */
  real_T UnitDelay8;                   /* '<S38>/Unit Delay8' */
  real_T UnitDelay10[9];               /* '<S38>/Unit Delay10' */
  real_T UnitDelay9[2];                /* '<S38>/Unit Delay9' */
  real_T DataTypeConversion7[3];       /* '<S38>/Data Type Conversion7' */
  real_T Reshape3[9];                  /* '<S38>/Reshape3' */
  real_T Gain1[6];                     /* '<S20>/Gain1' */
  real_T Gain[13];                     /* '<S28>/Gain' */
  real_T Add[13];                      /* '<S28>/Add' */
  real_T Gain_a[13];                   /* '<S29>/Gain' */
  real_T UnitDelay_m;                  /* '<S27>/Unit Delay' */
  real_T DiscreteTimeIntegrator1;      /* '<S27>/Discrete-Time Integrator1' */
  real_T Divide;                       /* '<S27>/Divide' */
  real_T Constant3[6];                 /* '<S2>/Constant3' */
  real_T Constant4[11];                /* '<S2>/Constant4' */
  real_T Reshape[6];                   /* '<S2>/Reshape' */
  real_T Gain2[6];                     /* '<S2>/Gain2' */
  real_T Gain_e[6];                    /* '<S20>/Gain' */
  real_T Switch[6];                    /* '<S30>/Switch' */
  real_T Switch2[6];                   /* '<S30>/Switch2' */
  real_T torque_sat[6];                /* '<S20>/Data Type Conversion1' */
  real_T current_unsat[6];             /* '<S8>/TorqueToCurrent' */
  real_T Switch_b[6];                  /* '<S35>/Switch' */
  real_T Switch2_d[6];                 /* '<S35>/Switch2' */
  real_T DataTypeConversion;           /* '<S2>/Data Type Conversion' */
  real_T UnitDelay2_o[13];             /* '<S8>/Unit Delay2' */
  real_T UnitDelay1_h[13];             /* '<S8>/Unit Delay1' */
  real_T UnitDelay_a;                  /* '<S8>/Unit Delay' */
  real_T Reshape3_i[6];                /* '<S2>/Reshape3' */
  real_T Reshape4[6];                  /* '<S2>/Reshape4' */
  real_T Reshape1[16];                 /* '<S2>/Reshape1' */
  real_T rad2deg[13];                  /* '<Root>/rad2deg' */
  real_T Add_j[4];                     /* '<Root>/Add' */
  real_T DigitalClock;                 /* '<Root>/Digital Clock' */
  real_T Gain1_o[4];                   /* '<Root>/Gain1' */
  real_T Gain_d[6];                    /* '<S2>/Gain' */
  real_T Gain1_i[6];                   /* '<S2>/Gain1' */
  real_T Switch_f;                     /* '<S27>/Switch' */
  real_T DigitalClock_e;               /* '<S33>/Digital Clock' */
  real_T DataTypeConversion97[6];      /* '<S45>/Data Type Conversion97' */
  real_T CurrentSaturation[6];         /* '<S38>/Current Saturation' */
  real_T DataTypeConversion69[2];      /* '<S45>/Data Type Conversion69' */
  real_T DataTypeConversion93[2];      /* '<S45>/Data Type Conversion93' */
  real_T DataTypeConversion111;        /* '<S45>/Data Type Conversion111' */
  real_T DataTypeConversion21[2];      /* '<S45>/Data Type Conversion21' */
  real_T DataTypeConversion45[2];      /* '<S45>/Data Type Conversion45' */
  real_T DataTypeConversion126;        /* '<S45>/Data Type Conversion126' */
  real_T DataTypeConversion62;         /* '<S45>/Data Type Conversion62' */
  real_T DataTypeConversion86;         /* '<S45>/Data Type Conversion86' */
  real_T DataTypeConversion103;        /* '<S45>/Data Type Conversion103' */
  real_T DataTypeConversion14;         /* '<S45>/Data Type Conversion14' */
  real_T DataTypeConversion38;         /* '<S45>/Data Type Conversion38' */
  real_T DataTypeConversion118;        /* '<S45>/Data Type Conversion118' */
  real_T DataTypeConversion61;         /* '<S45>/Data Type Conversion61' */
  real_T DataTypeConversion85;         /* '<S45>/Data Type Conversion85' */
  real_T DataTypeConversion101;        /* '<S45>/Data Type Conversion101' */
  real_T DataTypeConversion13;         /* '<S45>/Data Type Conversion13' */
  real_T DataTypeConversion37;         /* '<S45>/Data Type Conversion37' */
  real_T DataTypeConversion116;        /* '<S45>/Data Type Conversion116' */
  real_T DataTypeConversion63[6];      /* '<S45>/Data Type Conversion63' */
  real_T DataTypeConversion87[6];      /* '<S45>/Data Type Conversion87' */
  real_T DataTypeConversion102[3];     /* '<S45>/Data Type Conversion102' */
  real_T DataTypeConversion15[6];      /* '<S45>/Data Type Conversion15' */
  real_T DataTypeConversion39[6];      /* '<S45>/Data Type Conversion39' */
  real_T DataTypeConversion117[3];     /* '<S45>/Data Type Conversion117' */
  real_T Counter_o1;                   /* '<S45>/Counter' */
  real_T Counter_o2;                   /* '<S45>/Counter' */
  real_T DataTypeConversion10;         /* '<S45>/Data Type Conversion10' */
  real_T DataTypeConversion105;        /* '<S45>/Data Type Conversion105' */
  real_T DataTypeConversion106;        /* '<S45>/Data Type Conversion106' */
  real_T DataTypeConversion107;        /* '<S45>/Data Type Conversion107' */
  real_T DataTypeConversion108;        /* '<S45>/Data Type Conversion108' */
  real_T DataTypeConversion109;        /* '<S45>/Data Type Conversion109' */
  real_T DataTypeConversion11;         /* '<S45>/Data Type Conversion11' */
  real_T DataTypeConversion110;        /* '<S45>/Data Type Conversion110' */
  real_T DataTypeConversion112;        /* '<S45>/Data Type Conversion112' */
  real_T DataTypeConversion12;         /* '<S45>/Data Type Conversion12' */
  real_T DataTypeConversion120;        /* '<S45>/Data Type Conversion120' */
  real_T DataTypeConversion121;        /* '<S45>/Data Type Conversion121' */
  real_T DataTypeConversion122;        /* '<S45>/Data Type Conversion122' */
  real_T DataTypeConversion123;        /* '<S45>/Data Type Conversion123' */
  real_T DataTypeConversion124;        /* '<S45>/Data Type Conversion124' */
  real_T DataTypeConversion125;        /* '<S45>/Data Type Conversion125' */
  real_T DataTypeConversion157;        /* '<S45>/Data Type Conversion157' */
  real_T DataTypeConversion16;         /* '<S45>/Data Type Conversion16' */
  real_T DataTypeConversion18;         /* '<S45>/Data Type Conversion18' */
  real_T DataTypeConversion19;         /* '<S45>/Data Type Conversion19' */
  real_T DataTypeConversion2;          /* '<S45>/Data Type Conversion2' */
  real_T DataTypeConversion23[2];      /* '<S45>/Data Type Conversion23' */
  real_T DataTypeConversion27;         /* '<S45>/Data Type Conversion27' */
  real_T DataTypeConversion28;         /* '<S45>/Data Type Conversion28' */
  real_T DataTypeConversion29;         /* '<S45>/Data Type Conversion29' */
  real_T DataTypeConversion30;         /* '<S45>/Data Type Conversion30' */
  real_T DataTypeConversion31;         /* '<S45>/Data Type Conversion31' */
  real_T DataTypeConversion32;         /* '<S45>/Data Type Conversion32' */
  real_T DataTypeConversion34;         /* '<S45>/Data Type Conversion34' */
  real_T DataTypeConversion35;         /* '<S45>/Data Type Conversion35' */
  real_T DataTypeConversion36;         /* '<S45>/Data Type Conversion36' */
  real_T DataTypeConversion4;          /* '<S45>/Data Type Conversion4' */
  real_T DataTypeConversion47[2];      /* '<S45>/Data Type Conversion47' */
  real_T DataTypeConversion5;          /* '<S45>/Data Type Conversion5' */
  real_T DataTypeConversion51;         /* '<S45>/Data Type Conversion51' */
  real_T DataTypeConversion52;         /* '<S45>/Data Type Conversion52' */
  real_T DataTypeConversion53;         /* '<S45>/Data Type Conversion53' */
  real_T DataTypeConversion54;         /* '<S45>/Data Type Conversion54' */
  real_T DataTypeConversion55;         /* '<S45>/Data Type Conversion55' */
  real_T DataTypeConversion56;         /* '<S45>/Data Type Conversion56' */
  real_T DataTypeConversion58;         /* '<S45>/Data Type Conversion58' */
  real_T DataTypeConversion59;         /* '<S45>/Data Type Conversion59' */
  real_T DataTypeConversion6;          /* '<S45>/Data Type Conversion6' */
  real_T DataTypeConversion60;         /* '<S45>/Data Type Conversion60' */
  real_T DataTypeConversion7_l;        /* '<S45>/Data Type Conversion7' */
  real_T DataTypeConversion71[2];      /* '<S45>/Data Type Conversion71' */
  real_T DataTypeConversion75;         /* '<S45>/Data Type Conversion75' */
  real_T DataTypeConversion76;         /* '<S45>/Data Type Conversion76' */
  real_T DataTypeConversion77;         /* '<S45>/Data Type Conversion77' */
  real_T DataTypeConversion78;         /* '<S45>/Data Type Conversion78' */
  real_T DataTypeConversion79;         /* '<S45>/Data Type Conversion79' */
  real_T DataTypeConversion8;          /* '<S45>/Data Type Conversion8' */
  real_T DataTypeConversion80;         /* '<S45>/Data Type Conversion80' */
  real_T DataTypeConversion82;         /* '<S45>/Data Type Conversion82' */
  real_T DataTypeConversion83;         /* '<S45>/Data Type Conversion83' */
  real_T DataTypeConversion84;         /* '<S45>/Data Type Conversion84' */
  real_T DataTypeConversion95[2];      /* '<S45>/Data Type Conversion95' */
  real_T VectorConcatenate_g[2];       /* '<S78>/Vector Concatenate' */
  real_T Fcn;                          /* '<S78>/Fcn' */
  real_T DataTypeConversion20_f;       /* '<S62>/Data Type Conversion20' */
  real_T DataTypeConversion42;         /* '<S62>/Data Type Conversion42' */
  real_T VectorConcatenate_f[2];       /* '<S95>/Vector Concatenate' */
  real_T Fcn_m;                        /* '<S95>/Fcn' */
  real_T DataTypeConversion20_o;       /* '<S63>/Data Type Conversion20' */
  real_T DataTypeConversion42_e;       /* '<S63>/Data Type Conversion42' */
  real_T VectorConcatenate_d[2];       /* '<S112>/Vector Concatenate' */
  real_T Fcn_k;                        /* '<S112>/Fcn' */
  real_T DataTypeConversion20_n;       /* '<S64>/Data Type Conversion20' */
  real_T DataTypeConversion42_h;       /* '<S64>/Data Type Conversion42' */
  real_T VectorConcatenate_p[2];       /* '<S129>/Vector Concatenate' */
  real_T Fcn_mq;                       /* '<S129>/Fcn' */
  real_T DataTypeConversion20_h;       /* '<S65>/Data Type Conversion20' */
  real_T DataTypeConversion42_i;       /* '<S65>/Data Type Conversion42' */
  real_T y[6];                         /* '<S38>/convert_mtr_current_to_pwm' */
  real_T TmpSignalConversionAtSFunctionI[10];/* '<S38>/calibrate' */
  real_T TmpSignalConversionAtSFunctio_d[9];/* '<S38>/calibrate' */
  real_T Rollover[9];                  /* '<S38>/calibrate' */
  real_T IncCalTick[6];                /* '<S38>/calibrate' */
  real_T u_zeroed[6];                  /* '<S38>/ZeroingLegs' */
  real_T VectorConcatenate_dr[2];      /* '<S123>/Vector Concatenate' */
  real_T Fcn_i;                        /* '<S123>/Fcn' */
  real_T ControlWordIndex;             /* '<S64>/Chart' */
  real_T EnableTargetTorque;           /* '<S64>/Chart' */
  real_T FaultDetected;                /* '<S64>/Chart' */
  real_T VectorConcatenate_n[2];       /* '<S106>/Vector Concatenate' */
  real_T Fcn_f;                        /* '<S106>/Fcn' */
  real_T VectorConcatenate_c[2];       /* '<S89>/Vector Concatenate' */
  real_T Fcn_h;                        /* '<S89>/Fcn' */
  real_T ControlWordIndex_m;           /* '<S62>/Chart' */
  real_T EnableTargetTorque_h;         /* '<S62>/Chart' */
  real_T FaultDetected_g;              /* '<S62>/Chart' */
  real_T VectorConcatenate_f0[2];      /* '<S72>/Vector Concatenate' */
  real_T Fcn_c;                        /* '<S72>/Fcn' */
  real_T TmpSignalConversionAtSFunctio_e[6];/* '<S45>/EncodeSwitches' */
  real_T LimitSwitchesEncoded;         /* '<S45>/EncodeSwitches' */
  real_T TmpSignalConversionAtSFunctio_a[30];/* '<S45>/ConvertThermistors' */
  real_T Temperatures[30];             /* '<S45>/ConvertThermistors' */
  real_T TmpSignalConversionAtSFunctio_l[6];/* '<S45>/ConvertMotorVoltage' */
  real_T motorVoltage[6];              /* '<S45>/ConvertMotorVoltage' */
  real_T TmpSignalConversionAtSFunctio_o[6];/* '<S45>/ConvertLogicVoltage' */
  real_T logicVoltage[6];              /* '<S45>/ConvertLogicVoltage' */
  real_T TmpSignalConversionAtSFunctio_c[10];/* '<S45>/ConvertAmpCurrent' */
  real_T measuredCurrent[10];          /* '<S45>/ConvertAmpCurrent' */
  real_T Rk[9];                        /* '<S38>/EstimateOrientation' */
  real_T wk[3];                        /* '<S38>/EstimateOrientation' */
  real_T Ak[3];                        /* '<S38>/EstimateOrientation' */
  real_T Seqk;                         /* '<S38>/EstimateOrientation' */
  real_T ImpAsg_InsertedFor_q_clean_at_i[19];/* '<S43>/CheckAndFilterEncoder' */
  real_T ImpAsg_InsertedFor_dq_clean_at_[19];/* '<S43>/CheckAndFilterEncoder' */
  real_T ZYX[3];                       /* '<S38>/ComputeEulerAngles1' */
  real_T dZYX[3];                      /* '<S38>/ComputeEulerAngles1' */
  real_T Rk_g[9];                      /* '<S38>/ComputeEulerAngles1' */
  real_T R0[9];                        /* '<S38>/ComputeEulerAngles1' */
  real_T YawRollover[2];               /* '<S38>/ComputeEulerAngles1' */
  real_T q_clean[13];                  /* '<S37>/GeneralizedCoordinates' */
  real_T dq_clean[13];                 /* '<S37>/GeneralizedCoordinates' */
  real_T MotorCurrentCommandSafe[6];   /* '<S8>/SAFETY' */
  real_T MedullaCommandSafe;           /* '<S8>/SAFETY' */
  real_T SafetyState;                  /* '<S8>/SAFETY' */
  real_T SafetyCountOut;               /* '<S8>/SAFETY' */
  real_T q[13];                        /* '<S8>/AdjustForCOMOffset' */
  real_T Controller3_o2[6];            /* '<S2>/Controller3' */
  real_T Controller3_o3[16];           /* '<S2>/Controller3' */
  real_T Controller3_o4[6];            /* '<S2>/Controller3' */
  real_T Controller3_o5[6];            /* '<S2>/Controller3' */
  real32_T EtherCATRxVar6;             /* '<S61>/EtherCAT Rx Var 6' */
  real32_T EtherCATRxVar1;             /* '<S61>/EtherCAT Rx Var 1' */
  real32_T EtherCATRxVar2;             /* '<S61>/EtherCAT Rx Var 2' */
  real32_T EtherCATRxVar9;             /* '<S61>/EtherCAT Rx Var 9' */
  real32_T EtherCATRxVar11;            /* '<S61>/EtherCAT Rx Var 11' */
  real32_T EtherCATRxVar12;            /* '<S61>/EtherCAT Rx Var 12' */
  int32_T EtherCATInit[6];             /* '<S45>/EtherCAT Init ' */
  int32_T DataTypeConversion5_a;       /* '<S59>/Data Type Conversion5' */
  int32_T DataTypeConversion5_d;       /* '<S60>/Data Type Conversion5' */
  int32_T EtherCATPDOReceive1;         /* '<S71>/EtherCAT PDO Receive1' */
  int32_T EtherCATPDOReceive1_d;       /* '<S88>/EtherCAT PDO Receive1' */
  int32_T EtherCATPDOReceive1_n;       /* '<S105>/EtherCAT PDO Receive1' */
  int32_T EtherCATPDOReceive1_f;       /* '<S122>/EtherCAT PDO Receive1' */
  int32_T DataTypeConversion5_i;       /* '<S66>/Data Type Conversion5' */
  int32_T DataTypeConversion5_p;       /* '<S67>/Data Type Conversion5' */
  int32_T DataTypeConversion5_h;       /* '<S68>/Data Type Conversion5' */
  int32_T DataTypeConversion5_b;       /* '<S69>/Data Type Conversion5' */
  uint32_T EtherCATRxVar4;             /* '<S67>/EtherCAT Rx Var 4' */
  uint32_T EtherCATRxVar4_l;           /* '<S69>/EtherCAT Rx Var 4' */
  uint32_T EtherCATRxVar4_o;           /* '<S66>/EtherCAT Rx Var 4' */
  uint32_T EtherCATRxVar4_h;           /* '<S68>/EtherCAT Rx Var 4' */
  uint32_T EtherCATRxVar8;             /* '<S67>/EtherCAT Rx Var 8' */
  uint32_T EtherCATRxVar8_b;           /* '<S69>/EtherCAT Rx Var 8' */
  uint32_T EtherCATRxVar8_h;           /* '<S66>/EtherCAT Rx Var 8' */
  uint32_T EtherCATRxVar8_bx;          /* '<S68>/EtherCAT Rx Var 8' */
  uint32_T EtherCATRxVar4_e;           /* '<S60>/EtherCAT Rx Var 4' */
  uint32_T EtherCATRxVar4_j;           /* '<S59>/EtherCAT Rx Var 4' */
  int16_T EtherCATRxVar6_b;            /* '<S67>/EtherCAT Rx Var 6' */
  int16_T EtherCATRxVar7;              /* '<S67>/EtherCAT Rx Var 7' */
  int16_T EtherCATRxVar6_j;            /* '<S69>/EtherCAT Rx Var 6' */
  int16_T EtherCATRxVar7_p;            /* '<S69>/EtherCAT Rx Var 7' */
  int16_T EtherCATRxVar;               /* '<S60>/EtherCAT Rx Var ' */
  int16_T EtherCATRxVar6_h;            /* '<S66>/EtherCAT Rx Var 6' */
  int16_T EtherCATRxVar7_g;            /* '<S66>/EtherCAT Rx Var 7' */
  int16_T EtherCATRxVar6_bg;           /* '<S68>/EtherCAT Rx Var 6' */
  int16_T EtherCATRxVar7_h;            /* '<S68>/EtherCAT Rx Var 7' */
  int16_T EtherCATRxVar_h;             /* '<S59>/EtherCAT Rx Var ' */
  int16_T EtherCATRxVar4_d;            /* '<S61>/EtherCAT Rx Var 4' */
  int16_T EtherCATPDOReceive;          /* '<S71>/EtherCAT PDO Receive' */
  int16_T Switch_fb;                   /* '<S62>/Switch' */
  int16_T EtherCATPDOReceive_d;        /* '<S88>/EtherCAT PDO Receive' */
  int16_T Switch_fg;                   /* '<S63>/Switch' */
  int16_T EtherCATPDOReceive_p;        /* '<S105>/EtherCAT PDO Receive' */
  int16_T Switch_d;                    /* '<S64>/Switch' */
  int16_T EtherCATPDOReceive_o;        /* '<S122>/EtherCAT PDO Receive' */
  int16_T Switch_i;                    /* '<S65>/Switch' */
  int16_T DataTypeConversion6_h;       /* '<S123>/Data Type Conversion6' */
  int16_T DataTypeConversion6_e;       /* '<S106>/Data Type Conversion6' */
  int16_T DataTypeConversion6_eq;      /* '<S89>/Data Type Conversion6' */
  int16_T DataTypeConversion6_f;       /* '<S72>/Data Type Conversion6' */
  uint16_T EtherCATRxVar_n;            /* '<S67>/EtherCAT Rx Var ' */
  uint16_T EtherCATRxVar_k;            /* '<S69>/EtherCAT Rx Var ' */
  uint16_T EtherCATRxVar_nk;           /* '<S66>/EtherCAT Rx Var ' */
  uint16_T EtherCATRxVar_o;            /* '<S68>/EtherCAT Rx Var ' */
  uint16_T EtherCATRxVar2_i;           /* '<S60>/EtherCAT Rx Var 2' */
  uint16_T EtherCATRxVar2_p;           /* '<S59>/EtherCAT Rx Var 2' */
  uint16_T EtherCATRxVar10;            /* '<S67>/EtherCAT Rx Var 10' */
  uint16_T EtherCATRxVar10_i;          /* '<S69>/EtherCAT Rx Var 10' */
  uint16_T EtherCATRxVar6_p;           /* '<S60>/EtherCAT Rx Var 6' */
  uint16_T EtherCATRxVar10_h;          /* '<S66>/EtherCAT Rx Var 10' */
  uint16_T EtherCATRxVar10_l;          /* '<S68>/EtherCAT Rx Var 10' */
  uint16_T EtherCATRxVar6_n;           /* '<S59>/EtherCAT Rx Var 6' */
  uint16_T EtherCATRxVar11_b;          /* '<S67>/EtherCAT Rx Var 11' */
  uint16_T EtherCATRxVar11_e;          /* '<S69>/EtherCAT Rx Var 11' */
  uint16_T EtherCATRxVar1_n;           /* '<S60>/EtherCAT Rx Var 1' */
  uint16_T EtherCATRxVar11_k;          /* '<S66>/EtherCAT Rx Var 11' */
  uint16_T EtherCATRxVar11_l;          /* '<S68>/EtherCAT Rx Var 11' */
  uint16_T EtherCATRxVar1_b;           /* '<S59>/EtherCAT Rx Var 1' */
  uint16_T EtherCATRxVar12_f;          /* '<S67>/EtherCAT Rx Var 12' */
  uint16_T EtherCATRxVar13;            /* '<S67>/EtherCAT Rx Var 13' */
  uint16_T EtherCATRxVar14;            /* '<S67>/EtherCAT Rx Var 14' */
  uint16_T EtherCATRxVar15;            /* '<S67>/EtherCAT Rx Var 15' */
  uint16_T EtherCATRxVar16;            /* '<S67>/EtherCAT Rx Var 16' */
  uint16_T EtherCATRxVar17;            /* '<S67>/EtherCAT Rx Var 17' */
  uint16_T EtherCATRxVar12_o;          /* '<S69>/EtherCAT Rx Var 12' */
  uint16_T EtherCATRxVar13_b;          /* '<S69>/EtherCAT Rx Var 13' */
  uint16_T EtherCATRxVar14_j;          /* '<S69>/EtherCAT Rx Var 14' */
  uint16_T EtherCATRxVar15_m;          /* '<S69>/EtherCAT Rx Var 15' */
  uint16_T EtherCATRxVar16_h;          /* '<S69>/EtherCAT Rx Var 16' */
  uint16_T EtherCATRxVar17_b;          /* '<S69>/EtherCAT Rx Var 17' */
  uint16_T EtherCATRxVar12_l;          /* '<S60>/EtherCAT Rx Var 12' */
  uint16_T EtherCATRxVar13_f;          /* '<S60>/EtherCAT Rx Var 13' */
  uint16_T EtherCATRxVar14_f;          /* '<S60>/EtherCAT Rx Var 14' */
  uint16_T EtherCATRxVar12_og;         /* '<S66>/EtherCAT Rx Var 12' */
  uint16_T EtherCATRxVar13_h;          /* '<S66>/EtherCAT Rx Var 13' */
  uint16_T EtherCATRxVar14_l;          /* '<S66>/EtherCAT Rx Var 14' */
  uint16_T EtherCATRxVar15_k;          /* '<S66>/EtherCAT Rx Var 15' */
  uint16_T EtherCATRxVar16_b;          /* '<S66>/EtherCAT Rx Var 16' */
  uint16_T EtherCATRxVar17_g;          /* '<S66>/EtherCAT Rx Var 17' */
  uint16_T EtherCATRxVar12_m;          /* '<S68>/EtherCAT Rx Var 12' */
  uint16_T EtherCATRxVar13_n;          /* '<S68>/EtherCAT Rx Var 13' */
  uint16_T EtherCATRxVar14_b;          /* '<S68>/EtherCAT Rx Var 14' */
  uint16_T EtherCATRxVar15_mh;         /* '<S68>/EtherCAT Rx Var 15' */
  uint16_T EtherCATRxVar16_hz;         /* '<S68>/EtherCAT Rx Var 16' */
  uint16_T EtherCATRxVar17_bq;         /* '<S68>/EtherCAT Rx Var 17' */
  uint16_T EtherCATRxVar12_k;          /* '<S59>/EtherCAT Rx Var 12' */
  uint16_T EtherCATRxVar13_g;          /* '<S59>/EtherCAT Rx Var 13' */
  uint16_T EtherCATRxVar14_d;          /* '<S59>/EtherCAT Rx Var 14' */
  uint16_T EtherCATRxVar5;             /* '<S66>/EtherCAT Rx Var 5' */
  uint16_T EtherCATRxVar5_h;           /* '<S60>/EtherCAT Rx Var 5' */
  uint16_T EtherCATRxVar3;             /* '<S60>/EtherCAT Rx Var 3' */
  uint16_T EtherCATRxVar9_p;           /* '<S66>/EtherCAT Rx Var 9' */
  uint16_T EtherCATRxVar1_c;           /* '<S66>/EtherCAT Rx Var 1' */
  uint16_T EtherCATRxVar5_f;           /* '<S59>/EtherCAT Rx Var 5' */
  uint16_T EtherCATRxVar3_f;           /* '<S59>/EtherCAT Rx Var 3' */
  uint16_T EtherCATRxVar23;            /* '<S66>/EtherCAT Rx Var 23' */
  uint16_T EtherCATRxVar2_g;           /* '<S66>/EtherCAT Rx Var 2' */
  uint16_T EtherCATRxVar3_e;           /* '<S66>/EtherCAT Rx Var 3' */
  uint16_T EtherCATRxVar23_d;          /* '<S68>/EtherCAT Rx Var 23' */
  uint16_T EtherCATRxVar5_g;           /* '<S68>/EtherCAT Rx Var 5' */
  uint16_T EtherCATRxVar9_n;           /* '<S68>/EtherCAT Rx Var 9' */
  uint16_T EtherCATRxVar1_g;           /* '<S68>/EtherCAT Rx Var 1' */
  uint16_T EtherCATRxVar2_iw;          /* '<S68>/EtherCAT Rx Var 2' */
  uint16_T EtherCATRxVar3_k;           /* '<S68>/EtherCAT Rx Var 3' */
  uint16_T EtherCATRxVar23_n;          /* '<S67>/EtherCAT Rx Var 23' */
  uint16_T EtherCATRxVar5_e;           /* '<S67>/EtherCAT Rx Var 5' */
  uint16_T EtherCATRxVar9_nz;          /* '<S67>/EtherCAT Rx Var 9' */
  uint16_T EtherCATRxVar1_m;           /* '<S67>/EtherCAT Rx Var 1' */
  uint16_T EtherCATRxVar2_f;           /* '<S67>/EtherCAT Rx Var 2' */
  uint16_T EtherCATRxVar3_b;           /* '<S67>/EtherCAT Rx Var 3' */
  uint16_T EtherCATRxVar23_b;          /* '<S69>/EtherCAT Rx Var 23' */
  uint16_T EtherCATRxVar5_gi;          /* '<S69>/EtherCAT Rx Var 5' */
  uint16_T EtherCATRxVar9_e;           /* '<S69>/EtherCAT Rx Var 9' */
  uint16_T EtherCATRxVar1_o;           /* '<S69>/EtherCAT Rx Var 1' */
  uint16_T EtherCATRxVar2_d;           /* '<S69>/EtherCAT Rx Var 2' */
  uint16_T EtherCATRxVar3_c;           /* '<S69>/EtherCAT Rx Var 3' */
  uint16_T DataTypeConversion4_d;      /* '<S59>/Data Type Conversion4' */
  uint16_T DataTypeConversion4_l;      /* '<S60>/Data Type Conversion4' */
  uint16_T DataTypeConversion4_li;     /* '<S61>/Data Type Conversion4' */
  uint16_T EtherCATPDOReceive5;        /* '<S71>/EtherCAT PDO Receive5' */
  uint16_T BitwiseOperator;            /* '<S74>/Bitwise Operator' */
  uint16_T BitwiseOperator_c;          /* '<S75>/Bitwise Operator' */
  uint16_T BitwiseOperator_j;          /* '<S76>/Bitwise Operator' */
  uint16_T BitwiseOperator_m;          /* '<S77>/Bitwise Operator' */
  uint16_T Merge;                      /* '<S73>/Merge' */
  uint16_T EtherCATPDOReceive5_d;      /* '<S88>/EtherCAT PDO Receive5' */
  uint16_T BitwiseOperator_h;          /* '<S91>/Bitwise Operator' */
  uint16_T BitwiseOperator_d;          /* '<S92>/Bitwise Operator' */
  uint16_T BitwiseOperator_k;          /* '<S93>/Bitwise Operator' */
  uint16_T BitwiseOperator_he;         /* '<S94>/Bitwise Operator' */
  uint16_T Merge_b;                    /* '<S90>/Merge' */
  uint16_T EtherCATPDOReceive5_dm;     /* '<S105>/EtherCAT PDO Receive5' */
  uint16_T BitwiseOperator_hh;         /* '<S108>/Bitwise Operator' */
  uint16_T BitwiseOperator_f;          /* '<S109>/Bitwise Operator' */
  uint16_T BitwiseOperator_cf;         /* '<S110>/Bitwise Operator' */
  uint16_T BitwiseOperator_e;          /* '<S111>/Bitwise Operator' */
  uint16_T Merge_e;                    /* '<S107>/Merge' */
  uint16_T EtherCATPDOReceive5_m;      /* '<S122>/EtherCAT PDO Receive5' */
  uint16_T BitwiseOperator_d5;         /* '<S125>/Bitwise Operator' */
  uint16_T BitwiseOperator_g;          /* '<S126>/Bitwise Operator' */
  uint16_T BitwiseOperator_o;          /* '<S127>/Bitwise Operator' */
  uint16_T BitwiseOperator_hb;         /* '<S128>/Bitwise Operator' */
  uint16_T Merge_k;                    /* '<S124>/Merge' */
  uint16_T DataTypeConversion4_g;      /* '<S66>/Data Type Conversion4' */
  uint16_T DataTypeConversion4_a;      /* '<S67>/Data Type Conversion4' */
  uint16_T DataTypeConversion4_di;     /* '<S68>/Data Type Conversion4' */
  uint16_T DataTypeConversion4_f;      /* '<S69>/Data Type Conversion4' */
  int8_T EtherCATPDOReceive2;          /* '<S71>/EtherCAT PDO Receive2' */
  int8_T EtherCATPDOReceive2_n;        /* '<S88>/EtherCAT PDO Receive2' */
  int8_T EtherCATPDOReceive2_f;        /* '<S105>/EtherCAT PDO Receive2' */
  int8_T EtherCATPDOReceive3;          /* '<S122>/EtherCAT PDO Receive3' */
  uint8_T EtherCATRxVar18;             /* '<S61>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar5_hj;           /* '<S61>/EtherCAT Rx Var 5' */
  uint8_T EtherCATRxVar19;             /* '<S60>/EtherCAT Rx Var 19' */
  uint8_T EtherCATRxVar16_e;           /* '<S60>/EtherCAT Rx Var 16' */
  uint8_T EtherCATRxVar15_d;           /* '<S60>/EtherCAT Rx Var 15' */
  uint8_T EtherCATRxVar17_f;           /* '<S60>/EtherCAT Rx Var 17' */
  uint8_T EtherCATRxVar18_a;           /* '<S59>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar19_p;           /* '<S59>/EtherCAT Rx Var 19' */
  uint8_T EtherCATRxVar16_l;           /* '<S59>/EtherCAT Rx Var 16' */
  uint8_T EtherCATRxVar15_j;           /* '<S59>/EtherCAT Rx Var 15' */
  uint8_T EtherCATRxVar17_i;           /* '<S59>/EtherCAT Rx Var 17' */
  uint8_T EtherCATRxVar18_n;           /* '<S60>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar16_e3;          /* '<S61>/EtherCAT Rx Var 16' */
  uint8_T EtherCATRxVar17_n;           /* '<S61>/EtherCAT Rx Var 17' */
  uint8_T EtherCATRxVar15_e;           /* '<S61>/EtherCAT Rx Var 15' */
  uint8_T EtherCATRxVar21;             /* '<S68>/EtherCAT Rx Var 21' */
  uint8_T EtherCATRxVar20;             /* '<S68>/EtherCAT Rx Var 20' */
  uint8_T EtherCATRxVar22;             /* '<S68>/EtherCAT Rx Var 22' */
  uint8_T EtherCATRxVar18_d;           /* '<S68>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar19_p0;          /* '<S68>/EtherCAT Rx Var 19' */
  uint8_T EtherCATRxVar21_f;           /* '<S66>/EtherCAT Rx Var 21' */
  uint8_T EtherCATRxVar20_n;           /* '<S66>/EtherCAT Rx Var 20' */
  uint8_T EtherCATRxVar21_p;           /* '<S67>/EtherCAT Rx Var 21' */
  uint8_T EtherCATRxVar20_h;           /* '<S67>/EtherCAT Rx Var 20' */
  uint8_T EtherCATRxVar22_l;           /* '<S67>/EtherCAT Rx Var 22' */
  uint8_T EtherCATRxVar18_e;           /* '<S67>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar19_m;           /* '<S67>/EtherCAT Rx Var 19' */
  uint8_T EtherCATRxVar22_i;           /* '<S66>/EtherCAT Rx Var 22' */
  uint8_T EtherCATRxVar18_b;           /* '<S66>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar21_l;           /* '<S69>/EtherCAT Rx Var 21' */
  uint8_T EtherCATRxVar20_e;           /* '<S69>/EtherCAT Rx Var 20' */
  uint8_T EtherCATRxVar22_a;           /* '<S69>/EtherCAT Rx Var 22' */
  uint8_T EtherCATRxVar18_o;           /* '<S69>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar19_ma;          /* '<S66>/EtherCAT Rx Var 19' */
  uint8_T EtherCATRxVar19_c;           /* '<S69>/EtherCAT Rx Var 19' */
  uint8_T DataTypeConversion3_o;       /* '<S59>/Data Type Conversion3' */
  uint8_T DataTypeConversion3_m;       /* '<S60>/Data Type Conversion3' */
  uint8_T EtherCATRxVar3_g;            /* '<S61>/EtherCAT Rx Var 3' */
  uint8_T DataTypeConversion3_m4;      /* '<S61>/Data Type Conversion3' */
  uint8_T DataTypeConversion3_h;       /* '<S66>/Data Type Conversion3' */
  uint8_T DataTypeConversion3_m4p;     /* '<S67>/Data Type Conversion3' */
  uint8_T DataTypeConversion3_f;       /* '<S68>/Data Type Conversion3' */
  uint8_T DataTypeConversion3_l;       /* '<S69>/Data Type Conversion3' */
  boolean_T UnitDelay_l;               /* '<S33>/Unit Delay' */
  boolean_T LogicalOperator1;          /* '<S33>/Logical Operator1' */
  boolean_T Compare;                   /* '<S31>/Compare' */
  boolean_T LowerRelop1[6];            /* '<S30>/LowerRelop1' */
  boolean_T UpperRelop[6];             /* '<S30>/UpperRelop' */
  boolean_T LowerRelop1_k[6];          /* '<S35>/LowerRelop1' */
  boolean_T UpperRelop_j[6];           /* '<S35>/UpperRelop' */
  boolean_T DataTypeConversion_h;      /* '<Root>/Data Type Conversion' */
  boolean_T Compare_k;                 /* '<S39>/Compare' */
  boolean_T Compare_m;                 /* '<S40>/Compare' */
  boolean_T LogicalOperator;           /* '<S33>/Logical Operator' */
  boolean_T LogicalOperator2;          /* '<S33>/Logical Operator2' */
  boolean_T Compare_o;                 /* '<S83>/Compare' */
  boolean_T Compare_l;                 /* '<S84>/Compare' */
  boolean_T Compare_ly;                /* '<S85>/Compare' */
  boolean_T Compare_d;                 /* '<S86>/Compare' */
  boolean_T Compare_d0;                /* '<S100>/Compare' */
  boolean_T Compare_p;                 /* '<S101>/Compare' */
  boolean_T Compare_om;                /* '<S102>/Compare' */
  boolean_T Compare_n;                 /* '<S103>/Compare' */
  boolean_T Compare_e;                 /* '<S117>/Compare' */
  boolean_T Compare_lx;                /* '<S118>/Compare' */
  boolean_T Compare_k0;                /* '<S119>/Compare' */
  boolean_T Compare_la;                /* '<S120>/Compare' */
  boolean_T Compare_i;                 /* '<S134>/Compare' */
  boolean_T Compare_ls;                /* '<S135>/Compare' */
  boolean_T Compare_da;                /* '<S136>/Compare' */
  boolean_T Compare_dh;                /* '<S137>/Compare' */
  boolean_T ValidStates[3];            /* '<S38>/EstimateOrientation' */
  boolean_T Controller3_o1;            /* '<S2>/Controller3' */
  B_Chart_Walking_ATRIAS_T sf_Chart_mz;/* '<S65>/Chart' */
  B_Chart_Walking_ATRIAS_T sf_Chart_m; /* '<S63>/Chart' */
  B_CoreSubsys_Walking_ATRIAS_T CoreSubsys[19];/* '<S43>/CoreSubsys' */
} B_Walking_ATRIAS_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  Controller3DHZD_obj_2_Walking_T obj; /* '<S2>/Controller3' */
  real_T UnitDelay1_DSTATE[9];         /* '<S38>/Unit Delay1' */
  real_T UnitDelay_DSTATE[9];          /* '<S38>/Unit Delay' */
  real_T UnitDelay2_DSTATE[6];         /* '<S38>/Unit Delay2' */
  real_T UnitDelay6_DSTATE[9];         /* '<S38>/Unit Delay6' */
  real_T UnitDelay7_DSTATE[3];         /* '<S38>/Unit Delay7' */
  real_T UnitDelay5_DSTATE[3];         /* '<S38>/Unit Delay5' */
  real_T UnitDelay8_DSTATE;            /* '<S38>/Unit Delay8' */
  real_T UnitDelay10_DSTATE[9];        /* '<S38>/Unit Delay10' */
  real_T UnitDelay9_DSTATE[2];         /* '<S38>/Unit Delay9' */
  real_T UnitDelay_DSTATE_l;           /* '<S27>/Unit Delay' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S27>/Discrete-Time Integrator1' */
  real_T UnitDelay2_DSTATE_h[13];      /* '<S8>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_j[13];      /* '<S8>/Unit Delay1' */
  real_T UnitDelay_DSTATE_k;           /* '<S8>/Unit Delay' */
  real_T Timeout;                      /* '<S64>/Chart' */
  real_T Timeout_b;                    /* '<S62>/Chart' */
  struct {
    void *LoggedData;
  } Scope1_PWORK;                      /* '<S2>/Scope1' */

  struct {
    void *LoggedData;
  } Scope10_PWORK;                     /* '<S2>/Scope10' */

  struct {
    void *LoggedData;
  } Scope11_PWORK;                     /* '<S2>/Scope11' */

  struct {
    void *LoggedData;
  } Scope12_PWORK;                     /* '<S2>/Scope12' */

  struct {
    void *LoggedData;
  } Scope14_PWORK;                     /* '<S2>/Scope14' */

  struct {
    void *LoggedData;
  } Scope15_PWORK;                     /* '<S2>/Scope15' */

  struct {
    void *LoggedData;
  } Scope16_PWORK;                     /* '<S2>/Scope16' */

  struct {
    void *LoggedData;
  } Scope17_PWORK;                     /* '<S2>/Scope17' */

  struct {
    void *LoggedData;
  } Scope18_PWORK;                     /* '<S2>/Scope18' */

  struct {
    void *LoggedData;
  } Scope19_PWORK;                     /* '<S2>/Scope19' */

  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<S2>/Scope2' */

  struct {
    void *LoggedData;
  } Scope20_PWORK;                     /* '<S2>/Scope20' */

  struct {
    void *LoggedData;
  } Scope3_PWORK;                      /* '<S2>/Scope3' */

  struct {
    void *LoggedData;
  } Scope4_PWORK;                      /* '<S2>/Scope4' */

  struct {
    void *LoggedData;
  } Scope5_PWORK;                      /* '<S2>/Scope5' */

  struct {
    void *LoggedData;
  } Scope6_PWORK;                      /* '<S2>/Scope6' */

  struct {
    void *LoggedData;
  } Scope7_PWORK;                      /* '<S2>/Scope7' */

  struct {
    void *LoggedData;
  } Scope8_PWORK;                      /* '<S2>/Scope8' */

  struct {
    void *LoggedData;
  } Scope9_PWORK;                      /* '<S2>/Scope9' */

  struct {
    void *LoggedData;
  } ToWorkspace1_PWORK;                /* '<S2>/To Workspace1' */

  struct {
    void *LoggedData;
  } ToWorkspace12_PWORK;               /* '<S2>/To Workspace12' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<S2>/To Workspace2' */

  void *Controller3_PWORK;             /* '<S2>/Controller3' */
  int32_T sfEvent;                     /* '<S64>/Chart' */
  int32_T sfEvent_l;                   /* '<S62>/Chart' */
  int_T EtherCATRxVar4_IWORK[7];       /* '<S67>/EtherCAT Rx Var 4' */
  int_T EtherCATRxVar4_IWORK_j[7];     /* '<S69>/EtherCAT Rx Var 4' */
  int_T EtherCATRxVar4_IWORK_g[7];     /* '<S66>/EtherCAT Rx Var 4' */
  int_T EtherCATRxVar4_IWORK_k[7];     /* '<S68>/EtherCAT Rx Var 4' */
  int_T EtherCATRxVar8_IWORK[7];       /* '<S67>/EtherCAT Rx Var 8' */
  int_T EtherCATRxVar8_IWORK_g[7];     /* '<S69>/EtherCAT Rx Var 8' */
  int_T EtherCATRxVar8_IWORK_a[7];     /* '<S66>/EtherCAT Rx Var 8' */
  int_T EtherCATRxVar8_IWORK_k[7];     /* '<S68>/EtherCAT Rx Var 8' */
  int_T EtherCATRxVar4_IWORK_d[7];     /* '<S60>/EtherCAT Rx Var 4' */
  int_T EtherCATRxVar4_IWORK_dc[7];    /* '<S59>/EtherCAT Rx Var 4' */
  int_T EtherCATRxVar_IWORK[7];        /* '<S67>/EtherCAT Rx Var ' */
  int_T EtherCATRxVar_IWORK_o[7];      /* '<S69>/EtherCAT Rx Var ' */
  int_T EtherCATRxVar_IWORK_d[7];      /* '<S66>/EtherCAT Rx Var ' */
  int_T EtherCATRxVar_IWORK_g[7];      /* '<S68>/EtherCAT Rx Var ' */
  int_T EtherCATRxVar2_IWORK[7];       /* '<S60>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar2_IWORK_g[7];     /* '<S59>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar6_IWORK[7];       /* '<S61>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar1_IWORK[7];       /* '<S61>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar2_IWORK_a[7];     /* '<S61>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar9_IWORK[7];       /* '<S61>/EtherCAT Rx Var 9' */
  int_T EtherCATRxVar11_IWORK[7];      /* '<S61>/EtherCAT Rx Var 11' */
  int_T EtherCATRxVar12_IWORK[7];      /* '<S61>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar18_IWORK[7];      /* '<S61>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar5_IWORK[7];       /* '<S61>/EtherCAT Rx Var 5' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S3>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_m;                 /* '<S4>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_m1;                /* '<S5>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_l;                 /* '<S6>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_k;                 /* '<S7>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_o;                 /* '<S21>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_b;                 /* '<S22>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_j;                 /* '<S23>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_n;                 /* '<S24>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_h;                 /* '<S25>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_c;                 /* '<S26>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_i;                 /* '<S36>/S-Function' */

  int_T EtherCATRxVar6_IWORK_a[7];     /* '<S67>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar7_IWORK[7];       /* '<S67>/EtherCAT Rx Var 7' */
  int_T EtherCATRxVar6_IWORK_b[7];     /* '<S69>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar7_IWORK_d[7];     /* '<S69>/EtherCAT Rx Var 7' */
  int_T EtherCATRxVar_IWORK_p[7];      /* '<S60>/EtherCAT Rx Var ' */
  int_T EtherCATRxVar6_IWORK_l[7];     /* '<S66>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar7_IWORK_h[7];     /* '<S66>/EtherCAT Rx Var 7' */
  int_T EtherCATRxVar6_IWORK_g[7];     /* '<S68>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar7_IWORK_b[7];     /* '<S68>/EtherCAT Rx Var 7' */
  int_T EtherCATRxVar_IWORK_dh[7];     /* '<S59>/EtherCAT Rx Var ' */
  int_T EtherCATRxVar10_IWORK[7];      /* '<S67>/EtherCAT Rx Var 10' */
  int_T EtherCATRxVar10_IWORK_f[7];    /* '<S69>/EtherCAT Rx Var 10' */
  int_T EtherCATRxVar6_IWORK_bw[7];    /* '<S60>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar10_IWORK_g[7];    /* '<S66>/EtherCAT Rx Var 10' */
  int_T EtherCATRxVar10_IWORK_h[7];    /* '<S68>/EtherCAT Rx Var 10' */
  int_T EtherCATRxVar6_IWORK_l0[7];    /* '<S59>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar11_IWORK_n[7];    /* '<S67>/EtherCAT Rx Var 11' */
  int_T EtherCATRxVar11_IWORK_p[7];    /* '<S69>/EtherCAT Rx Var 11' */
  int_T EtherCATRxVar1_IWORK_p[7];     /* '<S60>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar11_IWORK_i[7];    /* '<S66>/EtherCAT Rx Var 11' */
  int_T EtherCATRxVar11_IWORK_f[7];    /* '<S68>/EtherCAT Rx Var 11' */
  int_T EtherCATRxVar1_IWORK_i[7];     /* '<S59>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar12_IWORK_m[7];    /* '<S67>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar13_IWORK[7];      /* '<S67>/EtherCAT Rx Var 13' */
  int_T EtherCATRxVar14_IWORK[7];      /* '<S67>/EtherCAT Rx Var 14' */
  int_T EtherCATRxVar15_IWORK[7];      /* '<S67>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar16_IWORK[7];      /* '<S67>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar17_IWORK[7];      /* '<S67>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar12_IWORK_f[7];    /* '<S69>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar13_IWORK_e[7];    /* '<S69>/EtherCAT Rx Var 13' */
  int_T EtherCATRxVar14_IWORK_c[7];    /* '<S69>/EtherCAT Rx Var 14' */
  int_T EtherCATRxVar15_IWORK_i[7];    /* '<S69>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar16_IWORK_e[7];    /* '<S69>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar17_IWORK_e[7];    /* '<S69>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar12_IWORK_j[7];    /* '<S60>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar13_IWORK_h[7];    /* '<S60>/EtherCAT Rx Var 13' */
  int_T EtherCATRxVar14_IWORK_cr[7];   /* '<S60>/EtherCAT Rx Var 14' */
  int_T EtherCATRxVar12_IWORK_o[7];    /* '<S66>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar13_IWORK_j[7];    /* '<S66>/EtherCAT Rx Var 13' */
  int_T EtherCATRxVar14_IWORK_p[7];    /* '<S66>/EtherCAT Rx Var 14' */
  int_T EtherCATRxVar15_IWORK_g[7];    /* '<S66>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar16_IWORK_l[7];    /* '<S66>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar17_IWORK_j[7];    /* '<S66>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar12_IWORK_b[7];    /* '<S68>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar13_IWORK_g[7];    /* '<S68>/EtherCAT Rx Var 13' */
  int_T EtherCATRxVar14_IWORK_k[7];    /* '<S68>/EtherCAT Rx Var 14' */
  int_T EtherCATRxVar15_IWORK_b[7];    /* '<S68>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar16_IWORK_h[7];    /* '<S68>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar17_IWORK_p[7];    /* '<S68>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar12_IWORK_c[7];    /* '<S59>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar13_IWORK_b[7];    /* '<S59>/EtherCAT Rx Var 13' */
  int_T EtherCATRxVar14_IWORK_g[7];    /* '<S59>/EtherCAT Rx Var 14' */
  int_T EtherCATRxVar5_IWORK_c[7];     /* '<S66>/EtherCAT Rx Var 5' */
  int_T EtherCATRxVar19_IWORK[7];      /* '<S60>/EtherCAT Rx Var 19' */
  int_T EtherCATRxVar16_IWORK_j[7];    /* '<S60>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar15_IWORK_bk[7];   /* '<S60>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar5_IWORK_p[7];     /* '<S60>/EtherCAT Rx Var 5' */
  int_T EtherCATRxVar3_IWORK[7];       /* '<S60>/EtherCAT Rx Var 3' */
  int_T EtherCATRxVar9_IWORK_a[7];     /* '<S66>/EtherCAT Rx Var 9' */
  int_T EtherCATRxVar17_IWORK_i[7];    /* '<S60>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar18_IWORK_o[7];    /* '<S59>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar1_IWORK_h[7];     /* '<S66>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar19_IWORK_o[7];    /* '<S59>/EtherCAT Rx Var 19' */
  int_T EtherCATRxVar16_IWORK_p[7];    /* '<S59>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar15_IWORK_o[7];    /* '<S59>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar5_IWORK_g[7];     /* '<S59>/EtherCAT Rx Var 5' */
  int_T EtherCATRxVar3_IWORK_p[7];     /* '<S59>/EtherCAT Rx Var 3' */
  int_T EtherCATRxVar17_IWORK_m[7];    /* '<S59>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar18_IWORK_c[7];    /* '<S60>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar16_IWORK_d[7];    /* '<S61>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar17_IWORK_l[7];    /* '<S61>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar15_IWORK_c[7];    /* '<S61>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar23_IWORK[7];      /* '<S66>/EtherCAT Rx Var 23' */
  int_T EtherCATRxVar2_IWORK_k[7];     /* '<S66>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar3_IWORK_i[7];     /* '<S66>/EtherCAT Rx Var 3' */
  int_T EtherCATRxVar23_IWORK_f[7];    /* '<S68>/EtherCAT Rx Var 23' */
  int_T EtherCATRxVar21_IWORK[7];      /* '<S68>/EtherCAT Rx Var 21' */
  int_T EtherCATRxVar20_IWORK[7];      /* '<S68>/EtherCAT Rx Var 20' */
  int_T EtherCATRxVar22_IWORK[7];      /* '<S68>/EtherCAT Rx Var 22' */
  int_T EtherCATRxVar18_IWORK_k[7];    /* '<S68>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar19_IWORK_i[7];    /* '<S68>/EtherCAT Rx Var 19' */
  int_T EtherCATRxVar5_IWORK_i[7];     /* '<S68>/EtherCAT Rx Var 5' */
  int_T EtherCATRxVar9_IWORK_f[7];     /* '<S68>/EtherCAT Rx Var 9' */
  int_T EtherCATRxVar1_IWORK_d[7];     /* '<S68>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar21_IWORK_n[7];    /* '<S66>/EtherCAT Rx Var 21' */
  int_T EtherCATRxVar2_IWORK_f[7];     /* '<S68>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar3_IWORK_j[7];     /* '<S68>/EtherCAT Rx Var 3' */
  int_T EtherCATRxVar20_IWORK_d[7];    /* '<S66>/EtherCAT Rx Var 20' */
  int_T EtherCATRxVar23_IWORK_b[7];    /* '<S67>/EtherCAT Rx Var 23' */
  int_T EtherCATRxVar21_IWORK_i[7];    /* '<S67>/EtherCAT Rx Var 21' */
  int_T EtherCATRxVar20_IWORK_o[7];    /* '<S67>/EtherCAT Rx Var 20' */
  int_T EtherCATRxVar22_IWORK_i[7];    /* '<S67>/EtherCAT Rx Var 22' */
  int_T EtherCATRxVar18_IWORK_j[7];    /* '<S67>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar19_IWORK_p[7];    /* '<S67>/EtherCAT Rx Var 19' */
  int_T EtherCATRxVar5_IWORK_j[7];     /* '<S67>/EtherCAT Rx Var 5' */
  int_T EtherCATRxVar9_IWORK_n[7];     /* '<S67>/EtherCAT Rx Var 9' */
  int_T EtherCATRxVar22_IWORK_m[7];    /* '<S66>/EtherCAT Rx Var 22' */
  int_T EtherCATRxVar1_IWORK_pv[7];    /* '<S67>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar18_IWORK_b[7];    /* '<S66>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar2_IWORK_h[7];     /* '<S67>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar3_IWORK_o[7];     /* '<S67>/EtherCAT Rx Var 3' */
  int_T EtherCATRxVar23_IWORK_n[7];    /* '<S69>/EtherCAT Rx Var 23' */
  int_T EtherCATRxVar21_IWORK_h[7];    /* '<S69>/EtherCAT Rx Var 21' */
  int_T EtherCATRxVar20_IWORK_c[7];    /* '<S69>/EtherCAT Rx Var 20' */
  int_T EtherCATRxVar22_IWORK_j[7];    /* '<S69>/EtherCAT Rx Var 22' */
  int_T EtherCATRxVar18_IWORK_l[7];    /* '<S69>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar19_IWORK_a[7];    /* '<S66>/EtherCAT Rx Var 19' */
  int_T EtherCATRxVar19_IWORK_c[7];    /* '<S69>/EtherCAT Rx Var 19' */
  int_T EtherCATRxVar5_IWORK_a[7];     /* '<S69>/EtherCAT Rx Var 5' */
  int_T EtherCATRxVar9_IWORK_c[7];     /* '<S69>/EtherCAT Rx Var 9' */
  int_T EtherCATRxVar1_IWORK_k[7];     /* '<S69>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar2_IWORK_m[7];     /* '<S69>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar3_IWORK_k[7];     /* '<S69>/EtherCAT Rx Var 3' */
  int_T EtherCATTxVar3_IWORK[7];       /* '<S59>/EtherCAT Tx Var 3' */
  int_T EtherCATTxVar4_IWORK[7];       /* '<S59>/EtherCAT Tx Var 4' */
  int_T EtherCATTxVar5_IWORK[7];       /* '<S59>/EtherCAT Tx Var 5' */
  int_T EtherCATTxVar3_IWORK_g[7];     /* '<S60>/EtherCAT Tx Var 3' */
  int_T EtherCATTxVar4_IWORK_e[7];     /* '<S60>/EtherCAT Tx Var 4' */
  int_T EtherCATTxVar5_IWORK_p[7];     /* '<S60>/EtherCAT Tx Var 5' */
  int_T EtherCATRxVar3_IWORK_f[7];     /* '<S61>/EtherCAT Rx Var 3' */
  int_T EtherCATRxVar4_IWORK_l[7];     /* '<S61>/EtherCAT Rx Var 4' */
  int_T EtherCATTxVar_IWORK[7];        /* '<S61>/EtherCAT Tx Var ' */
  int_T EtherCATTxVar1_IWORK[7];       /* '<S61>/EtherCAT Tx Var 1' */
  int_T EtherCATPDOReceive5_IWORK[7];  /* '<S71>/EtherCAT PDO Receive5' */
  int_T EtherCATPDOReceive_IWORK[7];   /* '<S71>/EtherCAT PDO Receive' */
  int_T EtherCATPDOReceive1_IWORK[7];  /* '<S71>/EtherCAT PDO Receive1' */
  int_T EtherCATPDOReceive2_IWORK[7];  /* '<S71>/EtherCAT PDO Receive2' */
  int_T EtherCATPDOTransmit_IWORK[7];  /* '<S71>/EtherCAT PDO Transmit' */
  int_T EtherCATPDOTransmit1_IWORK[7]; /* '<S71>/EtherCAT PDO Transmit1' */
  int_T EtherCATPDOTransmit2_IWORK[7]; /* '<S71>/EtherCAT PDO Transmit2' */
  int_T EtherCATPDOReceive5_IWORK_o[7];/* '<S88>/EtherCAT PDO Receive5' */
  int_T EtherCATPDOReceive_IWORK_d[7]; /* '<S88>/EtherCAT PDO Receive' */
  int_T EtherCATPDOReceive1_IWORK_k[7];/* '<S88>/EtherCAT PDO Receive1' */
  int_T EtherCATPDOReceive2_IWORK_j[7];/* '<S88>/EtherCAT PDO Receive2' */
  int_T EtherCATPDOTransmit_IWORK_b[7];/* '<S88>/EtherCAT PDO Transmit' */
  int_T EtherCATPDOTransmit1_IWORK_c[7];/* '<S88>/EtherCAT PDO Transmit1' */
  int_T EtherCATPDOTransmit2_IWORK_h[7];/* '<S88>/EtherCAT PDO Transmit2' */
  int_T EtherCATPDOReceive5_IWORK_p[7];/* '<S105>/EtherCAT PDO Receive5' */
  int_T EtherCATPDOReceive_IWORK_i[7]; /* '<S105>/EtherCAT PDO Receive' */
  int_T EtherCATPDOReceive1_IWORK_d[7];/* '<S105>/EtherCAT PDO Receive1' */
  int_T EtherCATPDOReceive2_IWORK_h[7];/* '<S105>/EtherCAT PDO Receive2' */
  int_T EtherCATPDOTransmit_IWORK_g[7];/* '<S105>/EtherCAT PDO Transmit' */
  int_T EtherCATPDOTransmit1_IWORK_g[7];/* '<S105>/EtherCAT PDO Transmit1' */
  int_T EtherCATPDOTransmit2_IWORK_hi[7];/* '<S105>/EtherCAT PDO Transmit2' */
  int_T EtherCATPDOReceive5_IWORK_m[7];/* '<S122>/EtherCAT PDO Receive5' */
  int_T EtherCATPDOReceive_IWORK_m[7]; /* '<S122>/EtherCAT PDO Receive' */
  int_T EtherCATPDOReceive1_IWORK_p[7];/* '<S122>/EtherCAT PDO Receive1' */
  int_T EtherCATPDOReceive3_IWORK[7];  /* '<S122>/EtherCAT PDO Receive3' */
  int_T EtherCATPDOTransmit_IWORK_l[7];/* '<S122>/EtherCAT PDO Transmit' */
  int_T EtherCATPDOTransmit1_IWORK_ci[7];/* '<S122>/EtherCAT PDO Transmit1' */
  int_T EtherCATPDOTransmit2_IWORK_o[7];/* '<S122>/EtherCAT PDO Transmit2' */
  int_T EtherCATTxVar3_IWORK_o[7];     /* '<S66>/EtherCAT Tx Var 3' */
  int_T EtherCATTxVar4_IWORK_a[7];     /* '<S66>/EtherCAT Tx Var 4' */
  int_T EtherCATTxVar5_IWORK_k[7];     /* '<S66>/EtherCAT Tx Var 5' */
  int_T EtherCATTxVar3_IWORK_i[7];     /* '<S67>/EtherCAT Tx Var 3' */
  int_T EtherCATTxVar4_IWORK_p[7];     /* '<S67>/EtherCAT Tx Var 4' */
  int_T EtherCATTxVar5_IWORK_a[7];     /* '<S67>/EtherCAT Tx Var 5' */
  int_T EtherCATTxVar3_IWORK_a[7];     /* '<S68>/EtherCAT Tx Var 3' */
  int_T EtherCATTxVar4_IWORK_f[7];     /* '<S68>/EtherCAT Tx Var 4' */
  int_T EtherCATTxVar5_IWORK_kq[7];    /* '<S68>/EtherCAT Tx Var 5' */
  int_T EtherCATTxVar3_IWORK_e[7];     /* '<S69>/EtherCAT Tx Var 3' */
  int_T EtherCATTxVar4_IWORK_d[7];     /* '<S69>/EtherCAT Tx Var 4' */
  int_T EtherCATTxVar5_IWORK_a3[7];    /* '<S69>/EtherCAT Tx Var 5' */
  uint16_T Counter_Count;              /* '<S45>/Counter' */
  boolean_T UnitDelay_DSTATE_b;        /* '<S33>/Unit Delay' */
  int8_T DiscreteTimeIntegrator1_PrevRes;/* '<S27>/Discrete-Time Integrator1' */
  uint8_T is_active_c45_Walking_ATRIAS;/* '<S64>/Chart' */
  uint8_T is_c45_Walking_ATRIAS;       /* '<S64>/Chart' */
  uint8_T is_Initialization;           /* '<S64>/Chart' */
  uint8_T is_active_c43_Walking_ATRIAS;/* '<S62>/Chart' */
  uint8_T is_c43_Walking_ATRIAS;       /* '<S62>/Chart' */
  uint8_T is_Initialization_a;         /* '<S62>/Chart' */
  boolean_T isStable;                  /* '<S64>/Chart' */
  boolean_T isStable_i;                /* '<S62>/Chart' */
  boolean_T objisempty;                /* '<S2>/Controller3' */
  DW_NothingControlWord_Walking_T NothingControlWord_jg;/* '<S124>/NothingControlWord' */
  DW_FaultReset_Walking_ATRIAS_T FaultReset_l;/* '<S124>/FaultReset' */
  DW_EnableControlWord_Walking__T EnableControlWord_n;/* '<S124>/EnableControlWord' */
  DW_ShutdownControlWord_Walkin_T ShutdownControlWord_l;/* '<S124>/ShutdownControlWord' */
  DW_Chart_Walking_ATRIAS_T sf_Chart_mz;/* '<S65>/Chart' */
  DW_NothingControlWord_Walking_T NothingControlWord_j;/* '<S107>/NothingControlWord' */
  DW_FaultReset_Walking_ATRIAS_T FaultReset_k;/* '<S107>/FaultReset' */
  DW_EnableControlWord_Walking__T EnableControlWord_k;/* '<S107>/EnableControlWord' */
  DW_ShutdownControlWord_Walkin_T ShutdownControlWord_b;/* '<S107>/ShutdownControlWord' */
  DW_NothingControlWord_Walking_T NothingControlWord_n;/* '<S90>/NothingControlWord' */
  DW_FaultReset_Walking_ATRIAS_T FaultReset_a;/* '<S90>/FaultReset' */
  DW_EnableControlWord_Walking__T EnableControlWord_h;/* '<S90>/EnableControlWord' */
  DW_ShutdownControlWord_Walkin_T ShutdownControlWord_p;/* '<S90>/ShutdownControlWord' */
  DW_Chart_Walking_ATRIAS_T sf_Chart_m;/* '<S63>/Chart' */
  DW_NothingControlWord_Walking_T NothingControlWord;/* '<S73>/NothingControlWord' */
  DW_FaultReset_Walking_ATRIAS_T FaultReset;/* '<S73>/FaultReset' */
  DW_EnableControlWord_Walking__T EnableControlWord;/* '<S73>/EnableControlWord' */
  DW_ShutdownControlWord_Walkin_T ShutdownControlWord;/* '<S73>/ShutdownControlWord' */
  DW_CoreSubsys_Walking_ATRIAS_T CoreSubsys[19];/* '<S43>/CoreSubsys' */
} DW_Walking_ATRIAS_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T Make3x1[3];             /* '<S45>/Make3x1' */
  const real_T DataTypeConversion141[3];/* '<S45>/Data Type Conversion141' */
  const real_T Gain;                   /* '<S8>/Gain' */
  const real_T Constant2;              /* '<S8>/Constant2' */
} ConstB_Walking_ATRIAS_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Computed Parameter: EtherCATRxVar4_P1_Siz
   * Referenced by: '<S67>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar4_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1[60];

  /* Computed Parameter: EtherCATRxVar4_P2_Siz
   * Referenced by: '<S67>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  real_T pooled3[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  real_T pooled4;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive1'
   */
  real_T pooled5[2];

  /* Pooled Parameter (Expression: type_size)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive1'
   */
  real_T pooled6;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  real_T pooled7[2];

  /* Pooled Parameter (Expression: sig_dim)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  real_T pooled8;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  real_T pooled9[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  real_T pooled10;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  real_T pooled11[2];

  /* Pooled Parameter (Expression: sample_time)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 4'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 4'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 8'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 4'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 8'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 4'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 8'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 4'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 8'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Receive2'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S71>/EtherCAT PDO Transmit2'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive2'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Transmit2'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive2'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Transmit2'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive3'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  real_T pooled12;

  /* Computed Parameter: EtherCATRxVar4_P1_S_m
   * Referenced by: '<S69>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_S_m[2];

  /* Computed Parameter: EtherCATRxVar4_P1_n
   * Referenced by: '<S69>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_n[60];

  /* Computed Parameter: EtherCATRxVar4_P2_S_g
   * Referenced by: '<S69>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_S_g[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_l;

  /* Computed Parameter: EtherCATRxVar4_P1_S_a
   * Referenced by: '<S66>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_S_a[2];

  /* Computed Parameter: EtherCATRxVar4_P1_m
   * Referenced by: '<S66>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_m[60];

  /* Computed Parameter: EtherCATRxVar4_P2_S_f
   * Referenced by: '<S66>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_S_f[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_f;

  /* Computed Parameter: EtherCATRxVar4_P1_S_c
   * Referenced by: '<S68>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_S_c[2];

  /* Computed Parameter: EtherCATRxVar4_P1_e
   * Referenced by: '<S68>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_e[60];

  /* Computed Parameter: EtherCATRxVar4_P2_S_c
   * Referenced by: '<S68>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_S_c[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_j;

  /* Computed Parameter: EtherCATRxVar8_P1_Siz
   * Referenced by: '<S67>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar8_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1[64];

  /* Computed Parameter: EtherCATRxVar8_P2_Siz
   * Referenced by: '<S67>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2;

  /* Computed Parameter: EtherCATRxVar8_P1_S_g
   * Referenced by: '<S69>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_S_g[2];

  /* Computed Parameter: EtherCATRxVar8_P1_l
   * Referenced by: '<S69>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_l[64];

  /* Computed Parameter: EtherCATRxVar8_P2_S_e
   * Referenced by: '<S69>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_S_e[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_l;

  /* Computed Parameter: EtherCATRxVar8_P1_S_j
   * Referenced by: '<S66>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_S_j[2];

  /* Computed Parameter: EtherCATRxVar8_P1_d
   * Referenced by: '<S66>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_d[64];

  /* Computed Parameter: EtherCATRxVar8_P2_S_o
   * Referenced by: '<S66>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_S_o[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_m;

  /* Computed Parameter: EtherCATRxVar8_P1_S_l
   * Referenced by: '<S68>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_S_l[2];

  /* Computed Parameter: EtherCATRxVar8_P1_m
   * Referenced by: '<S68>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_m[64];

  /* Computed Parameter: EtherCATRxVar8_P2_S_b
   * Referenced by: '<S68>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_S_b[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_n;

  /* Computed Parameter: EtherCATRxVar4_P1_S_e
   * Referenced by: '<S60>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_S_e[2];

  /* Computed Parameter: EtherCATRxVar4_P1_em
   * Referenced by: '<S60>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_em[57];

  /* Computed Parameter: EtherCATRxVar4_P2_S_m
   * Referenced by: '<S60>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_S_m[2];

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_m;

  /* Computed Parameter: EtherCATRxVar4_P1_S_o
   * Referenced by: '<S59>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_S_o[2];

  /* Computed Parameter: EtherCATRxVar4_P1_mc
   * Referenced by: '<S59>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_mc[56];

  /* Computed Parameter: EtherCATRxVar4_P2_S_e
   * Referenced by: '<S59>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_S_e[2];

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_a;

  /* Computed Parameter: EtherCATRxVar_P1_Size
   * Referenced by: '<S67>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_Size[2];

  /* Computed Parameter: EtherCATRxVar_P1
   * Referenced by: '<S67>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1[76];

  /* Computed Parameter: EtherCATRxVar_P2_Size
   * Referenced by: '<S67>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_Size[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit1'
   */
  real_T pooled13[2];

  /* Pooled Parameter (Expression: sig_type)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit1'
   */
  real_T pooled14;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   */
  real_T pooled15[2];

  /* Pooled Parameter (Expression: type_size)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S59>/EtherCAT Rx Var 1'
   *   '<S59>/EtherCAT Rx Var 12'
   *   '<S59>/EtherCAT Rx Var 13'
   *   '<S59>/EtherCAT Rx Var 14'
   *   '<S59>/EtherCAT Rx Var 2'
   *   '<S59>/EtherCAT Rx Var 3'
   *   '<S59>/EtherCAT Rx Var 5'
   *   '<S59>/EtherCAT Rx Var 6'
   *   '<S59>/EtherCAT Tx Var 4'
   *   '<S60>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var 1'
   *   '<S60>/EtherCAT Rx Var 12'
   *   '<S60>/EtherCAT Rx Var 13'
   *   '<S60>/EtherCAT Rx Var 14'
   *   '<S60>/EtherCAT Rx Var 2'
   *   '<S60>/EtherCAT Rx Var 3'
   *   '<S60>/EtherCAT Rx Var 5'
   *   '<S60>/EtherCAT Rx Var 6'
   *   '<S60>/EtherCAT Tx Var 4'
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S61>/EtherCAT Tx Var 1'
   *   '<S66>/EtherCAT Rx Var '
   *   '<S66>/EtherCAT Rx Var 1'
   *   '<S66>/EtherCAT Rx Var 10'
   *   '<S66>/EtherCAT Rx Var 11'
   *   '<S66>/EtherCAT Rx Var 12'
   *   '<S66>/EtherCAT Rx Var 13'
   *   '<S66>/EtherCAT Rx Var 14'
   *   '<S66>/EtherCAT Rx Var 15'
   *   '<S66>/EtherCAT Rx Var 16'
   *   '<S66>/EtherCAT Rx Var 17'
   *   '<S66>/EtherCAT Rx Var 2'
   *   '<S66>/EtherCAT Rx Var 23'
   *   '<S66>/EtherCAT Rx Var 3'
   *   '<S66>/EtherCAT Rx Var 5'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S66>/EtherCAT Rx Var 9'
   *   '<S66>/EtherCAT Tx Var 4'
   *   '<S67>/EtherCAT Rx Var '
   *   '<S67>/EtherCAT Rx Var 1'
   *   '<S67>/EtherCAT Rx Var 10'
   *   '<S67>/EtherCAT Rx Var 11'
   *   '<S67>/EtherCAT Rx Var 12'
   *   '<S67>/EtherCAT Rx Var 13'
   *   '<S67>/EtherCAT Rx Var 14'
   *   '<S67>/EtherCAT Rx Var 15'
   *   '<S67>/EtherCAT Rx Var 16'
   *   '<S67>/EtherCAT Rx Var 17'
   *   '<S67>/EtherCAT Rx Var 2'
   *   '<S67>/EtherCAT Rx Var 23'
   *   '<S67>/EtherCAT Rx Var 3'
   *   '<S67>/EtherCAT Rx Var 5'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 9'
   *   '<S67>/EtherCAT Tx Var 4'
   *   '<S68>/EtherCAT Rx Var '
   *   '<S68>/EtherCAT Rx Var 1'
   *   '<S68>/EtherCAT Rx Var 10'
   *   '<S68>/EtherCAT Rx Var 11'
   *   '<S68>/EtherCAT Rx Var 12'
   *   '<S68>/EtherCAT Rx Var 13'
   *   '<S68>/EtherCAT Rx Var 14'
   *   '<S68>/EtherCAT Rx Var 15'
   *   '<S68>/EtherCAT Rx Var 16'
   *   '<S68>/EtherCAT Rx Var 17'
   *   '<S68>/EtherCAT Rx Var 2'
   *   '<S68>/EtherCAT Rx Var 23'
   *   '<S68>/EtherCAT Rx Var 3'
   *   '<S68>/EtherCAT Rx Var 5'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 9'
   *   '<S68>/EtherCAT Tx Var 4'
   *   '<S69>/EtherCAT Rx Var '
   *   '<S69>/EtherCAT Rx Var 1'
   *   '<S69>/EtherCAT Rx Var 10'
   *   '<S69>/EtherCAT Rx Var 11'
   *   '<S69>/EtherCAT Rx Var 12'
   *   '<S69>/EtherCAT Rx Var 13'
   *   '<S69>/EtherCAT Rx Var 14'
   *   '<S69>/EtherCAT Rx Var 15'
   *   '<S69>/EtherCAT Rx Var 16'
   *   '<S69>/EtherCAT Rx Var 17'
   *   '<S69>/EtherCAT Rx Var 2'
   *   '<S69>/EtherCAT Rx Var 23'
   *   '<S69>/EtherCAT Rx Var 3'
   *   '<S69>/EtherCAT Rx Var 5'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 9'
   *   '<S69>/EtherCAT Tx Var 4'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Receive5'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S71>/EtherCAT PDO Transmit1'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Receive5'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Transmit1'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Receive5'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Transmit1'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Receive5'
   *   '<S122>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Transmit1'
   */
  real_T pooled16;

  /* Computed Parameter: EtherCATRxVar_P1_Si_a
   * Referenced by: '<S69>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_Si_a[2];

  /* Computed Parameter: EtherCATRxVar_P1_l
   * Referenced by: '<S69>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_l[76];

  /* Computed Parameter: EtherCATRxVar_P2_Si_a
   * Referenced by: '<S69>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_Si_a[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_n;

  /* Computed Parameter: EtherCATRxVar_P1_Si_k
   * Referenced by: '<S66>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_Si_k[2];

  /* Computed Parameter: EtherCATRxVar_P1_i
   * Referenced by: '<S66>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_i[76];

  /* Computed Parameter: EtherCATRxVar_P2_Si_b
   * Referenced by: '<S66>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_Si_b[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_n1;

  /* Computed Parameter: EtherCATRxVar_P1_Si_n
   * Referenced by: '<S68>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_Si_n[2];

  /* Computed Parameter: EtherCATRxVar_P1_p
   * Referenced by: '<S68>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_p[76];

  /* Computed Parameter: EtherCATRxVar_P2_Si_m
   * Referenced by: '<S68>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_Si_m[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_l;

  /* Computed Parameter: EtherCATRxVar2_P1_Siz
   * Referenced by: '<S60>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar2_P1
   * Referenced by: '<S60>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1[77];

  /* Computed Parameter: EtherCATRxVar2_P2_Siz
   * Referenced by: '<S60>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2;

  /* Computed Parameter: EtherCATRxVar2_P1_S_i
   * Referenced by: '<S59>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_S_i[2];

  /* Computed Parameter: EtherCATRxVar2_P1_g
   * Referenced by: '<S59>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_g[76];

  /* Computed Parameter: EtherCATRxVar2_P2_S_m
   * Referenced by: '<S59>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_S_m[2];

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_n;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S38>/Unit Delay'
   *   '<S38>/Unit Delay10'
   *   '<S38>/Unit Delay6'
   */
  real_T pooled18[9];

  /* Expression: zeros(6,1)
   * Referenced by: '<S38>/Unit Delay2'
   */
  real_T UnitDelay2_InitialCon[6];

  /* Computed Parameter: EtherCATRxVar6_P1_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar6_P1
   * Referenced by: '<S61>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1[47];

  /* Computed Parameter: EtherCATRxVar6_P2_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   */
  real_T pooled19[2];

  /* Pooled Parameter (Expression: sig_type)
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 1'
   *   '<S61>/EtherCAT Rx Var 11'
   *   '<S61>/EtherCAT Rx Var 12'
   *   '<S61>/EtherCAT Rx Var 2'
   *   '<S61>/EtherCAT Rx Var 6'
   *   '<S61>/EtherCAT Rx Var 9'
   */
  real_T pooled20;

  /* Computed Parameter: EtherCATRxVar1_P1_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar1_P1
   * Referenced by: '<S61>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1[47];

  /* Computed Parameter: EtherCATRxVar1_P2_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2;

  /* Computed Parameter: EtherCATRxVar2_P1_S_n
   * Referenced by: '<S61>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_S_n[2];

  /* Computed Parameter: EtherCATRxVar2_P1_e
   * Referenced by: '<S61>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_e[47];

  /* Computed Parameter: EtherCATRxVar2_P2_S_e
   * Referenced by: '<S61>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_S_e[2];

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_d;

  /* Computed Parameter: EtherCATRxVar9_P1_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar9_P1
   * Referenced by: '<S61>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1[51];

  /* Computed Parameter: EtherCATRxVar9_P2_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2;

  /* Computed Parameter: EtherCATRxVar11_P1_Si
   * Referenced by: '<S61>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar11_P1
   * Referenced by: '<S61>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1[51];

  /* Computed Parameter: EtherCATRxVar11_P2_Si
   * Referenced by: '<S61>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2;

  /* Computed Parameter: EtherCATRxVar12_P1_Si
   * Referenced by: '<S61>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar12_P1
   * Referenced by: '<S61>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1[51];

  /* Computed Parameter: EtherCATRxVar12_P2_Si
   * Referenced by: '<S61>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   */
  real_T pooled21[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   */
  real_T pooled22[50];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   */
  real_T pooled23[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   */
  real_T pooled24;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Tx Var 3'
   */
  real_T pooled25[2];

  /* Pooled Parameter (Expression: sig_type)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 15'
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Rx Var 18'
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Tx Var 3'
   *   '<S60>/EtherCAT Rx Var 15'
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Rx Var 18'
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Tx Var 3'
   *   '<S61>/EtherCAT Rx Var 15'
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Rx Var 17'
   *   '<S61>/EtherCAT Rx Var 18'
   *   '<S61>/EtherCAT Rx Var 3'
   *   '<S61>/EtherCAT Rx Var 5'
   *   '<S61>/EtherCAT Tx Var '
   *   '<S66>/EtherCAT Rx Var 18'
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Rx Var 21'
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Tx Var 3'
   *   '<S67>/EtherCAT Rx Var 18'
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 21'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Tx Var 3'
   *   '<S68>/EtherCAT Rx Var 18'
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Rx Var 21'
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Tx Var 3'
   *   '<S69>/EtherCAT Rx Var 18'
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Rx Var 21'
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Tx Var 3'
   */
  real_T pooled26;

  /* Computed Parameter: EtherCATRxVar5_P1_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar5_P1
   * Referenced by: '<S61>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1[52];

  /* Computed Parameter: EtherCATRxVar5_P2_Siz
   * Referenced by: '<S61>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2;

  /* Expression: [1 0; 1 0; 0 1; 1 0; 1 0; 0 1]
   * Referenced by: '<S20>/Gain1'
   */
  real_T Gain1_Gain_d[12];

  /* Expression: [2*pi*ones(8,1); zeros(5,1)]
   * Referenced by: '<S28>/Constant'
   */
  real_T Constant_Value[13];

  /* Expression: 1./[50 50 26.7 50 50 26.7]
   * Referenced by: '<S2>/Gain2'
   */
  real_T Gain2_Gain[6];

  /* Expression: [10; 10; 5.5; 10; 10; 5.5]
   * Referenced by: '<S8>/TorqueToCurrent'
   */
  real_T TorqueToCurrent_Gain[6];

  /* Computed Parameter: EtherCATRxVar6_P1_S_m
   * Referenced by: '<S67>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_S_m[2];

  /* Computed Parameter: EtherCATRxVar6_P1_i
   * Referenced by: '<S67>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_i[76];

  /* Computed Parameter: EtherCATRxVar6_P2_S_k
   * Referenced by: '<S67>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_S_k[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_b;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var '
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Transmit'
   */
  real_T pooled31[2];

  /* Pooled Parameter (Expression: sig_type)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var '
   *   '<S60>/EtherCAT Rx Var '
   *   '<S61>/EtherCAT Rx Var 4'
   *   '<S66>/EtherCAT Rx Var 6'
   *   '<S66>/EtherCAT Rx Var 7'
   *   '<S67>/EtherCAT Rx Var 6'
   *   '<S67>/EtherCAT Rx Var 7'
   *   '<S68>/EtherCAT Rx Var 6'
   *   '<S68>/EtherCAT Rx Var 7'
   *   '<S69>/EtherCAT Rx Var 6'
   *   '<S69>/EtherCAT Rx Var 7'
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Transmit'
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Transmit'
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Transmit'
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Transmit'
   */
  real_T pooled32;

  /* Computed Parameter: EtherCATRxVar7_P1_Siz
   * Referenced by: '<S67>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar7_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1[76];

  /* Computed Parameter: EtherCATRxVar7_P2_Siz
   * Referenced by: '<S67>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2;

  /* Computed Parameter: EtherCATRxVar6_P1_S_c
   * Referenced by: '<S69>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_S_c[2];

  /* Computed Parameter: EtherCATRxVar6_P1_a
   * Referenced by: '<S69>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_a[76];

  /* Computed Parameter: EtherCATRxVar6_P2_S_c
   * Referenced by: '<S69>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_S_c[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_e;

  /* Computed Parameter: EtherCATRxVar7_P1_S_l
   * Referenced by: '<S69>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_S_l[2];

  /* Computed Parameter: EtherCATRxVar7_P1_d
   * Referenced by: '<S69>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_d[76];

  /* Computed Parameter: EtherCATRxVar7_P2_S_b
   * Referenced by: '<S69>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_S_b[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_a;

  /* Computed Parameter: EtherCATRxVar_P1_Si_g
   * Referenced by: '<S60>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_Si_g[2];

  /* Computed Parameter: EtherCATRxVar_P1_f
   * Referenced by: '<S60>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_f[75];

  /* Computed Parameter: EtherCATRxVar_P2_Si_i
   * Referenced by: '<S60>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_Si_i[2];

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_m;

  /* Computed Parameter: EtherCATRxVar6_P1_S_f
   * Referenced by: '<S66>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_S_f[2];

  /* Computed Parameter: EtherCATRxVar6_P1_ik
   * Referenced by: '<S66>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_ik[76];

  /* Computed Parameter: EtherCATRxVar6_P2_S_d
   * Referenced by: '<S66>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_S_d[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_f;

  /* Computed Parameter: EtherCATRxVar7_P1_S_k
   * Referenced by: '<S66>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_S_k[2];

  /* Computed Parameter: EtherCATRxVar7_P1_b
   * Referenced by: '<S66>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_b[76];

  /* Computed Parameter: EtherCATRxVar7_P2__b3
   * Referenced by: '<S66>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2__b3[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_g;

  /* Computed Parameter: EtherCATRxVar6_P1_S_h
   * Referenced by: '<S68>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_S_h[2];

  /* Computed Parameter: EtherCATRxVar6_P1_b
   * Referenced by: '<S68>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_b[76];

  /* Computed Parameter: EtherCATRxVar6_P2_S_p
   * Referenced by: '<S68>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_S_p[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_j;

  /* Computed Parameter: EtherCATRxVar7_P1_S_o
   * Referenced by: '<S68>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_S_o[2];

  /* Computed Parameter: EtherCATRxVar7_P1_h
   * Referenced by: '<S68>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_h[76];

  /* Computed Parameter: EtherCATRxVar7_P2_S_k
   * Referenced by: '<S68>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_S_k[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_b;

  /* Computed Parameter: EtherCATRxVar_P1_Si_p
   * Referenced by: '<S59>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_Si_p[2];

  /* Computed Parameter: EtherCATRxVar_P1_j
   * Referenced by: '<S59>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_j[74];

  /* Computed Parameter: EtherCATRxVar_P2_Si_p
   * Referenced by: '<S59>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_Si_p[2];

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_p;

  /* Computed Parameter: EtherCATRxVar10_P1_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar10_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1[56];

  /* Computed Parameter: EtherCATRxVar10_P2_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2;

  /* Computed Parameter: EtherCATRxVar10_P1__g
   * Referenced by: '<S69>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1__g[2];

  /* Computed Parameter: EtherCATRxVar10_P1_l
   * Referenced by: '<S69>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1_l[56];

  /* Computed Parameter: EtherCATRxVar10_P2__l
   * Referenced by: '<S69>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2__l[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2_p;

  /* Computed Parameter: EtherCATRxVar6_P1_S_a
   * Referenced by: '<S60>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_S_a[2];

  /* Computed Parameter: EtherCATRxVar6_P1_j
   * Referenced by: '<S60>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_j[57];

  /* Computed Parameter: EtherCATRxVar6_P2_S_m
   * Referenced by: '<S60>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_S_m[2];

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_bv;

  /* Computed Parameter: EtherCATRxVar10_P1__e
   * Referenced by: '<S66>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1__e[2];

  /* Computed Parameter: EtherCATRxVar10_P1_m
   * Referenced by: '<S66>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1_m[56];

  /* Computed Parameter: EtherCATRxVar10_P2__e
   * Referenced by: '<S66>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2__e[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2_k;

  /* Computed Parameter: EtherCATRxVar10_P1__k
   * Referenced by: '<S68>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1__k[2];

  /* Computed Parameter: EtherCATRxVar10_P1_c
   * Referenced by: '<S68>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1_c[56];

  /* Computed Parameter: EtherCATRxVar10_P2__g
   * Referenced by: '<S68>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2__g[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2_m;

  /* Computed Parameter: EtherCATRxVar6_P1_S_p
   * Referenced by: '<S59>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_S_p[2];

  /* Computed Parameter: EtherCATRxVar6_P1_h
   * Referenced by: '<S59>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_h[56];

  /* Computed Parameter: EtherCATRxVar6_P2_S_g
   * Referenced by: '<S59>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_S_g[2];

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_g;

  /* Computed Parameter: EtherCATRxVar11_P1__c
   * Referenced by: '<S67>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1__c[2];

  /* Computed Parameter: EtherCATRxVar11_P1_g
   * Referenced by: '<S67>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1_g[56];

  /* Computed Parameter: EtherCATRxVar11_P2__p
   * Referenced by: '<S67>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2__p[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2_e;

  /* Computed Parameter: EtherCATRxVar11_P1__e
   * Referenced by: '<S69>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1__e[2];

  /* Computed Parameter: EtherCATRxVar11_P1_l
   * Referenced by: '<S69>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1_l[56];

  /* Computed Parameter: EtherCATRxVar11_P2__k
   * Referenced by: '<S69>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2__k[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2_g;

  /* Computed Parameter: EtherCATRxVar1_P1_S_c
   * Referenced by: '<S60>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_S_c[2];

  /* Computed Parameter: EtherCATRxVar1_P1_k
   * Referenced by: '<S60>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_k[57];

  /* Computed Parameter: EtherCATRxVar1_P2_S_h
   * Referenced by: '<S60>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_S_h[2];

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_b;

  /* Computed Parameter: EtherCATRxVar11_P1__m
   * Referenced by: '<S66>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1__m[2];

  /* Computed Parameter: EtherCATRxVar11_P1_e
   * Referenced by: '<S66>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1_e[56];

  /* Computed Parameter: EtherCATRxVar11_P2__j
   * Referenced by: '<S66>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2__j[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2_l;

  /* Computed Parameter: EtherCATRxVar11_P1_en
   * Referenced by: '<S68>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1_en[2];

  /* Computed Parameter: EtherCATRxVar11_P1_a
   * Referenced by: '<S68>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1_a[56];

  /* Computed Parameter: EtherCATRxVar11_P2_po
   * Referenced by: '<S68>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2_po[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2_b;

  /* Computed Parameter: EtherCATRxVar1_P1_S_e
   * Referenced by: '<S59>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_S_e[2];

  /* Computed Parameter: EtherCATRxVar1_P1_e
   * Referenced by: '<S59>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_e[56];

  /* Computed Parameter: EtherCATRxVar1_P2_S_i
   * Referenced by: '<S59>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_S_i[2];

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_a;

  /* Computed Parameter: EtherCATRxVar12_P1__k
   * Referenced by: '<S67>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1__k[2];

  /* Computed Parameter: EtherCATRxVar12_P1_g
   * Referenced by: '<S67>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_g[61];

  /* Computed Parameter: EtherCATRxVar12_P2__o
   * Referenced by: '<S67>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2__o[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_c;

  /* Computed Parameter: EtherCATRxVar13_P1_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar13_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1[61];

  /* Computed Parameter: EtherCATRxVar13_P2_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2;

  /* Computed Parameter: EtherCATRxVar14_P1_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar14_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1[61];

  /* Computed Parameter: EtherCATRxVar14_P2_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2;

  /* Computed Parameter: EtherCATRxVar15_P1_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar15_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1[61];

  /* Computed Parameter: EtherCATRxVar15_P2_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2;

  /* Computed Parameter: EtherCATRxVar16_P1_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar16_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1[61];

  /* Computed Parameter: EtherCATRxVar16_P2_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2;

  /* Computed Parameter: EtherCATRxVar17_P1_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar17_P1
   * Referenced by: '<S67>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1[61];

  /* Computed Parameter: EtherCATRxVar17_P2_Si
   * Referenced by: '<S67>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2;

  /* Computed Parameter: EtherCATRxVar12_P1__n
   * Referenced by: '<S69>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1__n[2];

  /* Computed Parameter: EtherCATRxVar12_P1_p
   * Referenced by: '<S69>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_p[61];

  /* Computed Parameter: EtherCATRxVar12_P2__k
   * Referenced by: '<S69>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2__k[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_n;

  /* Computed Parameter: EtherCATRxVar13_P1__o
   * Referenced by: '<S69>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1__o[2];

  /* Computed Parameter: EtherCATRxVar13_P1_n
   * Referenced by: '<S69>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1_n[61];

  /* Computed Parameter: EtherCATRxVar13_P2__k
   * Referenced by: '<S69>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2__k[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_j;

  /* Computed Parameter: EtherCATRxVar14_P1__j
   * Referenced by: '<S69>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1__j[2];

  /* Computed Parameter: EtherCATRxVar14_P1_c
   * Referenced by: '<S69>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1_c[61];

  /* Computed Parameter: EtherCATRxVar14_P2__c
   * Referenced by: '<S69>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2__c[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_a;

  /* Computed Parameter: EtherCATRxVar15_P1__b
   * Referenced by: '<S69>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1__b[2];

  /* Computed Parameter: EtherCATRxVar15_P1_a
   * Referenced by: '<S69>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_a[61];

  /* Computed Parameter: EtherCATRxVar15_P2__m
   * Referenced by: '<S69>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2__m[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_d;

  /* Computed Parameter: EtherCATRxVar16_P1__b
   * Referenced by: '<S69>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1__b[2];

  /* Computed Parameter: EtherCATRxVar16_P1_h
   * Referenced by: '<S69>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_h[61];

  /* Computed Parameter: EtherCATRxVar16_P2__h
   * Referenced by: '<S69>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2__h[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2_n;

  /* Computed Parameter: EtherCATRxVar17_P1__m
   * Referenced by: '<S69>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1__m[2];

  /* Computed Parameter: EtherCATRxVar17_P1_d
   * Referenced by: '<S69>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_d[61];

  /* Computed Parameter: EtherCATRxVar17_P2__n
   * Referenced by: '<S69>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2__n[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2_g;

  /* Computed Parameter: EtherCATRxVar12_P1__p
   * Referenced by: '<S60>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1__p[2];

  /* Computed Parameter: EtherCATRxVar12_P1_l
   * Referenced by: '<S60>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_l[62];

  /* Computed Parameter: EtherCATRxVar12_P2_kk
   * Referenced by: '<S60>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_kk[2];

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_o;

  /* Computed Parameter: EtherCATRxVar13_P1__e
   * Referenced by: '<S60>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1__e[2];

  /* Computed Parameter: EtherCATRxVar13_P1_j
   * Referenced by: '<S60>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1_j[62];

  /* Computed Parameter: EtherCATRxVar13_P2__f
   * Referenced by: '<S60>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2__f[2];

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_a;

  /* Computed Parameter: EtherCATRxVar14_P1__b
   * Referenced by: '<S60>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1__b[2];

  /* Computed Parameter: EtherCATRxVar14_P1_n
   * Referenced by: '<S60>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1_n[62];

  /* Computed Parameter: EtherCATRxVar14_P2_ce
   * Referenced by: '<S60>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_ce[2];

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_l;

  /* Computed Parameter: EtherCATRxVar12_P1_pv
   * Referenced by: '<S66>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_pv[2];

  /* Computed Parameter: EtherCATRxVar12_P1_k
   * Referenced by: '<S66>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_k[61];

  /* Computed Parameter: EtherCATRxVar12_P2__c
   * Referenced by: '<S66>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2__c[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_p;

  /* Computed Parameter: EtherCATRxVar13_P1__g
   * Referenced by: '<S66>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1__g[2];

  /* Computed Parameter: EtherCATRxVar13_P_jx
   * Referenced by: '<S66>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P_jx[61];

  /* Computed Parameter: EtherCATRxVar13_P2__h
   * Referenced by: '<S66>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2__h[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_f;

  /* Computed Parameter: EtherCATRxVar14_P1__p
   * Referenced by: '<S66>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1__p[2];

  /* Computed Parameter: EtherCATRxVar14_P1_p
   * Referenced by: '<S66>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1_p[61];

  /* Computed Parameter: EtherCATRxVar14_P2__b
   * Referenced by: '<S66>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2__b[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_g;

  /* Computed Parameter: EtherCATRxVar15_P1_bc
   * Referenced by: '<S66>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_bc[2];

  /* Computed Parameter: EtherCATRxVar15_P1_c
   * Referenced by: '<S66>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_c[61];

  /* Computed Parameter: EtherCATRxVar15_P2__n
   * Referenced by: '<S66>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2__n[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_l;

  /* Computed Parameter: EtherCATRxVar16_P1__c
   * Referenced by: '<S66>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1__c[2];

  /* Computed Parameter: EtherCATRxVar16_P1_a
   * Referenced by: '<S66>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_a[61];

  /* Computed Parameter: EtherCATRxVar16_P2__e
   * Referenced by: '<S66>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2__e[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2_m;

  /* Computed Parameter: EtherCATRxVar17_P1__j
   * Referenced by: '<S66>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1__j[2];

  /* Computed Parameter: EtherCATRxVar17_P1_k
   * Referenced by: '<S66>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_k[61];

  /* Computed Parameter: EtherCATRxVar17_P2__m
   * Referenced by: '<S66>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2__m[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2_a;

  /* Computed Parameter: EtherCATRxVar12_P1__o
   * Referenced by: '<S68>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1__o[2];

  /* Computed Parameter: EtherCATRxVar12_P_pi
   * Referenced by: '<S68>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P_pi[61];

  /* Computed Parameter: EtherCATRxVar12_P2_kj
   * Referenced by: '<S68>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_kj[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_h;

  /* Computed Parameter: EtherCATRxVar13_P1__h
   * Referenced by: '<S68>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1__h[2];

  /* Computed Parameter: EtherCATRxVar13_P1_o
   * Referenced by: '<S68>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1_o[61];

  /* Computed Parameter: EtherCATRxVar13_P2__n
   * Referenced by: '<S68>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2__n[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_c;

  /* Computed Parameter: EtherCATRxVar14_P1__c
   * Referenced by: '<S68>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1__c[2];

  /* Computed Parameter: EtherCATRxVar14_P1_g
   * Referenced by: '<S68>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1_g[61];

  /* Computed Parameter: EtherCATRxVar14_P2_ck
   * Referenced by: '<S68>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_ck[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_m;

  /* Computed Parameter: EtherCATRxVar15_P1__j
   * Referenced by: '<S68>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1__j[2];

  /* Computed Parameter: EtherCATRxVar15_P1_d
   * Referenced by: '<S68>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_d[61];

  /* Computed Parameter: EtherCATRxVar15_P2__l
   * Referenced by: '<S68>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2__l[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_g;

  /* Computed Parameter: EtherCATRxVar16_P1_c1
   * Referenced by: '<S68>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_c1[2];

  /* Computed Parameter: EtherCATRxVar16_P1_o
   * Referenced by: '<S68>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_o[61];

  /* Computed Parameter: EtherCATRxVar16_P2__p
   * Referenced by: '<S68>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2__p[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2_d;

  /* Computed Parameter: EtherCATRxVar17_P1__l
   * Referenced by: '<S68>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1__l[2];

  /* Computed Parameter: EtherCATRxVar17_P1_c
   * Referenced by: '<S68>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_c[61];

  /* Computed Parameter: EtherCATRxVar17_P2__h
   * Referenced by: '<S68>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2__h[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2_b;

  /* Computed Parameter: EtherCATRxVar12_P1_pu
   * Referenced by: '<S59>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_pu[2];

  /* Computed Parameter: EtherCATRxVar12_P1_j
   * Referenced by: '<S59>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_j[61];

  /* Computed Parameter: EtherCATRxVar12_P2__n
   * Referenced by: '<S59>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2__n[2];

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_m;

  /* Computed Parameter: EtherCATRxVar13_P1__f
   * Referenced by: '<S59>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1__f[2];

  /* Computed Parameter: EtherCATRxVar13_P1_d
   * Referenced by: '<S59>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1_d[61];

  /* Computed Parameter: EtherCATRxVar13_P2_fq
   * Referenced by: '<S59>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_fq[2];

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_at;

  /* Computed Parameter: EtherCATRxVar14_P1__f
   * Referenced by: '<S59>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1__f[2];

  /* Computed Parameter: EtherCATRxVar14_P1_j
   * Referenced by: '<S59>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1_j[61];

  /* Computed Parameter: EtherCATRxVar14_P2__d
   * Referenced by: '<S59>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2__d[2];

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_lx;

  /* Computed Parameter: EtherCATRxVar5_P1_S_l
   * Referenced by: '<S66>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_S_l[2];

  /* Computed Parameter: EtherCATRxVar5_P1_p
   * Referenced by: '<S66>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_p[70];

  /* Computed Parameter: EtherCATRxVar5_P2_S_f
   * Referenced by: '<S66>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_S_f[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_c;

  /* Computed Parameter: EtherCATRxVar19_P1_Si
   * Referenced by: '<S60>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar19_P1
   * Referenced by: '<S60>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1[62];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Tx Var 4'
   */
  real_T pooled33[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S60>/EtherCAT Rx Var 19'
   *   '<S60>/EtherCAT Tx Var 4'
   */
  real_T pooled34;

  /* Computed Parameter: EtherCATRxVar16_P1__p
   * Referenced by: '<S60>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1__p[2];

  /* Computed Parameter: EtherCATRxVar16_P1_b
   * Referenced by: '<S60>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_b[68];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Tx Var 5'
   */
  real_T pooled35[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S60>/EtherCAT Rx Var 16'
   *   '<S60>/EtherCAT Tx Var 5'
   */
  real_T pooled36;

  /* Computed Parameter: EtherCATRxVar15_P1__l
   * Referenced by: '<S60>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1__l[2];

  /* Computed Parameter: EtherCATRxVar15_P_av
   * Referenced by: '<S60>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P_av[64];

  /* Computed Parameter: EtherCATRxVar15_P2__b
   * Referenced by: '<S60>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2__b[2];

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_lg;

  /* Computed Parameter: EtherCATRxVar5_P1__lt
   * Referenced by: '<S60>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1__lt[2];

  /* Computed Parameter: EtherCATRxVar5_P1_g
   * Referenced by: '<S60>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_g[87];

  /* Computed Parameter: EtherCATRxVar5_P2_S_c
   * Referenced by: '<S60>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_S_c[2];

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_cp;

  /* Computed Parameter: EtherCATRxVar3_P1_Siz
   * Referenced by: '<S60>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar3_P1
   * Referenced by: '<S60>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1[59];

  /* Computed Parameter: EtherCATRxVar3_P2_Siz
   * Referenced by: '<S60>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2;

  /* Computed Parameter: EtherCATRxVar9_P1_S_i
   * Referenced by: '<S66>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_S_i[2];

  /* Computed Parameter: EtherCATRxVar9_P1_j
   * Referenced by: '<S66>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_j[74];

  /* Computed Parameter: EtherCATRxVar9_P2_S_d
   * Referenced by: '<S66>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_S_d[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_j;

  /* Computed Parameter: EtherCATRxVar17_P1__n
   * Referenced by: '<S60>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1__n[2];

  /* Computed Parameter: EtherCATRxVar17_P1_g
   * Referenced by: '<S60>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_g[59];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Tx Var 3'
   */
  real_T pooled37[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S60>/EtherCAT Rx Var 17'
   *   '<S60>/EtherCAT Tx Var 3'
   */
  real_T pooled38;

  /* Computed Parameter: EtherCATRxVar18_P1_Si
   * Referenced by: '<S59>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar18_P1
   * Referenced by: '<S59>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1[68];

  /* Computed Parameter: EtherCATRxVar18_P2_Si
   * Referenced by: '<S59>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2;

  /* Computed Parameter: EtherCATRxVar1_P1_S_j
   * Referenced by: '<S66>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_S_j[2];

  /* Computed Parameter: EtherCATRxVar1_P1_j
   * Referenced by: '<S66>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_j[86];

  /* Computed Parameter: EtherCATRxVar1_P2_S_e
   * Referenced by: '<S66>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_S_e[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_p;

  /* Computed Parameter: EtherCATRxVar19_P1__h
   * Referenced by: '<S59>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1__h[2];

  /* Computed Parameter: EtherCATRxVar19_P1_j
   * Referenced by: '<S59>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_j[61];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Tx Var 4'
   */
  real_T pooled39[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 19'
   *   '<S59>/EtherCAT Tx Var 4'
   */
  real_T pooled40;

  /* Computed Parameter: EtherCATRxVar16_P1__l
   * Referenced by: '<S59>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1__l[2];

  /* Computed Parameter: EtherCATRxVar16_P_hj
   * Referenced by: '<S59>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P_hj[67];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Tx Var 5'
   */
  real_T pooled41[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 16'
   *   '<S59>/EtherCAT Tx Var 5'
   */
  real_T pooled42;

  /* Computed Parameter: EtherCATRxVar15_P1__o
   * Referenced by: '<S59>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1__o[2];

  /* Computed Parameter: EtherCATRxVar15_P1_j
   * Referenced by: '<S59>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_j[63];

  /* Computed Parameter: EtherCATRxVar15_P2_bp
   * Referenced by: '<S59>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_bp[2];

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_gr;

  /* Computed Parameter: EtherCATRxVar5_P1_S_g
   * Referenced by: '<S59>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_S_g[2];

  /* Computed Parameter: EtherCATRxVar5_P1_k
   * Referenced by: '<S59>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_k[86];

  /* Computed Parameter: EtherCATRxVar5_P2_S_b
   * Referenced by: '<S59>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_S_b[2];

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_j;

  /* Computed Parameter: EtherCATRxVar3_P1_S_i
   * Referenced by: '<S59>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_S_i[2];

  /* Computed Parameter: EtherCATRxVar3_P1_n
   * Referenced by: '<S59>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_n[58];

  /* Computed Parameter: EtherCATRxVar3_P2_S_b
   * Referenced by: '<S59>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_S_b[2];

  /* Expression: sig_offset
   * Referenced by: '<S59>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_m;

  /* Computed Parameter: EtherCATRxVar17_P1_nw
   * Referenced by: '<S59>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_nw[2];

  /* Computed Parameter: EtherCATRxVar17_P_ky
   * Referenced by: '<S59>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P_ky[58];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Tx Var 3'
   */
  real_T pooled43[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S59>/EtherCAT Rx Var 17'
   *   '<S59>/EtherCAT Tx Var 3'
   */
  real_T pooled44;

  /* Computed Parameter: EtherCATRxVar18_P1__e
   * Referenced by: '<S60>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1__e[2];

  /* Computed Parameter: EtherCATRxVar18_P1_p
   * Referenced by: '<S60>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1_p[69];

  /* Computed Parameter: EtherCATRxVar18_P2__a
   * Referenced by: '<S60>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2__a[2];

  /* Expression: sig_offset
   * Referenced by: '<S60>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2_h;

  /* Computed Parameter: EtherCATRxVar16_P1__k
   * Referenced by: '<S61>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1__k[2];

  /* Computed Parameter: EtherCATRxVar16_P1_m
   * Referenced by: '<S61>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_m[58];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Tx Var '
   */
  real_T pooled45[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S61>/EtherCAT Rx Var 16'
   *   '<S61>/EtherCAT Tx Var '
   */
  real_T pooled46;

  /* Computed Parameter: EtherCATRxVar17_P1__b
   * Referenced by: '<S61>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1__b[2];

  /* Computed Parameter: EtherCATRxVar17_P1_p
   * Referenced by: '<S61>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_p[63];

  /* Computed Parameter: EtherCATRxVar17_P2__p
   * Referenced by: '<S61>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2__p[2];

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2_d;

  /* Computed Parameter: EtherCATRxVar15_P1__d
   * Referenced by: '<S61>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1__d[2];

  /* Computed Parameter: EtherCATRxVar15_P1_i
   * Referenced by: '<S61>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_i[67];

  /* Computed Parameter: EtherCATRxVar15_P2__c
   * Referenced by: '<S61>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2__c[2];

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_f;

  /* Computed Parameter: EtherCATRxVar23_P1_Si
   * Referenced by: '<S66>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar23_P1
   * Referenced by: '<S66>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1[66];

  /* Computed Parameter: EtherCATRxVar23_P2_Si
   * Referenced by: '<S66>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2;

  /* Computed Parameter: EtherCATRxVar2_P1_S_f
   * Referenced by: '<S66>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_S_f[2];

  /* Computed Parameter: EtherCATRxVar2_P1_l
   * Referenced by: '<S66>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_l[60];

  /* Computed Parameter: EtherCATRxVar2_P2_S_g
   * Referenced by: '<S66>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_S_g[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_i;

  /* Computed Parameter: EtherCATRxVar3_P1_S_k
   * Referenced by: '<S66>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_S_k[2];

  /* Computed Parameter: EtherCATRxVar3_P1_e
   * Referenced by: '<S66>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_e[60];

  /* Computed Parameter: EtherCATRxVar3_P2_S_p
   * Referenced by: '<S66>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_S_p[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_o;

  /* Computed Parameter: EtherCATRxVar23_P1__d
   * Referenced by: '<S68>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1__d[2];

  /* Computed Parameter: EtherCATRxVar23_P1_g
   * Referenced by: '<S68>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1_g[66];

  /* Computed Parameter: EtherCATRxVar23_P2__o
   * Referenced by: '<S68>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2__o[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2_c;

  /* Computed Parameter: EtherCATRxVar21_P1_Si
   * Referenced by: '<S68>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar21_P1
   * Referenced by: '<S68>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1[68];

  /* Computed Parameter: EtherCATRxVar21_P2_Si
   * Referenced by: '<S68>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2;

  /* Computed Parameter: EtherCATRxVar20_P1_Si
   * Referenced by: '<S68>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar20_P1
   * Referenced by: '<S68>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1[58];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Tx Var 3'
   */
  real_T pooled47[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S68>/EtherCAT Rx Var 20'
   *   '<S68>/EtherCAT Tx Var 3'
   */
  real_T pooled48;

  /* Computed Parameter: EtherCATRxVar22_P1_Si
   * Referenced by: '<S68>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar22_P1
   * Referenced by: '<S68>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1[61];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Tx Var 4'
   */
  real_T pooled49[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S68>/EtherCAT Rx Var 22'
   *   '<S68>/EtherCAT Tx Var 4'
   */
  real_T pooled50;

  /* Computed Parameter: EtherCATRxVar18_P1__d
   * Referenced by: '<S68>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1__d[2];

  /* Computed Parameter: EtherCATRxVar18_P1_k
   * Referenced by: '<S68>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1_k[63];

  /* Computed Parameter: EtherCATRxVar18_P2__b
   * Referenced by: '<S68>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2__b[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2_f;

  /* Computed Parameter: EtherCATRxVar19_P1_hi
   * Referenced by: '<S68>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_hi[2];

  /* Computed Parameter: EtherCATRxVar19_P1_k
   * Referenced by: '<S68>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_k[67];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Tx Var 5'
   */
  real_T pooled51[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S68>/EtherCAT Rx Var 19'
   *   '<S68>/EtherCAT Tx Var 5'
   */
  real_T pooled52;

  /* Computed Parameter: EtherCATRxVar5_P1_S_k
   * Referenced by: '<S68>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_S_k[2];

  /* Computed Parameter: EtherCATRxVar5_P1_a
   * Referenced by: '<S68>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_a[70];

  /* Computed Parameter: EtherCATRxVar5_P2_S_a
   * Referenced by: '<S68>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_S_a[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_l;

  /* Computed Parameter: EtherCATRxVar9_P1_S_a
   * Referenced by: '<S68>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_S_a[2];

  /* Computed Parameter: EtherCATRxVar9_P1_l
   * Referenced by: '<S68>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_l[74];

  /* Computed Parameter: EtherCATRxVar9_P2_S_h
   * Referenced by: '<S68>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_S_h[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_g;

  /* Computed Parameter: EtherCATRxVar1_P1_S_i
   * Referenced by: '<S68>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_S_i[2];

  /* Computed Parameter: EtherCATRxVar1_P1_d
   * Referenced by: '<S68>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_d[86];

  /* Computed Parameter: EtherCATRxVar1_P2_S_g
   * Referenced by: '<S68>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_S_g[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_e;

  /* Computed Parameter: EtherCATRxVar21_P1__p
   * Referenced by: '<S66>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1__p[2];

  /* Computed Parameter: EtherCATRxVar21_P1_p
   * Referenced by: '<S66>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1_p[68];

  /* Computed Parameter: EtherCATRxVar21_P2__h
   * Referenced by: '<S66>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2__h[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2_a;

  /* Computed Parameter: EtherCATRxVar2_P1_S_m
   * Referenced by: '<S68>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_S_m[2];

  /* Computed Parameter: EtherCATRxVar2_P1_c
   * Referenced by: '<S68>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_c[60];

  /* Computed Parameter: EtherCATRxVar2_P2_S_d
   * Referenced by: '<S68>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_S_d[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_m;

  /* Computed Parameter: EtherCATRxVar3_P1__kr
   * Referenced by: '<S68>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1__kr[2];

  /* Computed Parameter: EtherCATRxVar3_P1_h
   * Referenced by: '<S68>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_h[60];

  /* Computed Parameter: EtherCATRxVar3_P2_S_i
   * Referenced by: '<S68>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_S_i[2];

  /* Expression: sig_offset
   * Referenced by: '<S68>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_k;

  /* Computed Parameter: EtherCATRxVar20_P1__b
   * Referenced by: '<S66>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1__b[2];

  /* Computed Parameter: EtherCATRxVar20_P1_n
   * Referenced by: '<S66>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1_n[58];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Tx Var 3'
   */
  real_T pooled53[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S66>/EtherCAT Rx Var 20'
   *   '<S66>/EtherCAT Tx Var 3'
   */
  real_T pooled54;

  /* Computed Parameter: EtherCATRxVar23_P1__l
   * Referenced by: '<S67>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1__l[2];

  /* Computed Parameter: EtherCATRxVar23_P1_c
   * Referenced by: '<S67>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1_c[66];

  /* Computed Parameter: EtherCATRxVar23_P2__a
   * Referenced by: '<S67>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2__a[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2_h;

  /* Computed Parameter: EtherCATRxVar21_P1__i
   * Referenced by: '<S67>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1__i[2];

  /* Computed Parameter: EtherCATRxVar21_P1_n
   * Referenced by: '<S67>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1_n[68];

  /* Computed Parameter: EtherCATRxVar21_P2__n
   * Referenced by: '<S67>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2__n[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2_f;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 22'
   */
  real_T pooled55[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 22'
   */
  real_T pooled56[61];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Tx Var 4'
   */
  real_T pooled57[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S67>/EtherCAT Rx Var 20'
   *   '<S67>/EtherCAT Rx Var 22'
   *   '<S67>/EtherCAT Tx Var 4'
   */
  real_T pooled58;

  /* Computed Parameter: EtherCATRxVar18_P1__g
   * Referenced by: '<S67>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1__g[2];

  /* Computed Parameter: EtherCATRxVar18_P1_o
   * Referenced by: '<S67>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1_o[63];

  /* Computed Parameter: EtherCATRxVar18_P2__h
   * Referenced by: '<S67>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2__h[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2_b;

  /* Computed Parameter: EtherCATRxVar19_P1__e
   * Referenced by: '<S67>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1__e[2];

  /* Computed Parameter: EtherCATRxVar19_P1_i
   * Referenced by: '<S67>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_i[67];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Tx Var 5'
   */
  real_T pooled59[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S67>/EtherCAT Rx Var 19'
   *   '<S67>/EtherCAT Tx Var 5'
   */
  real_T pooled60;

  /* Computed Parameter: EtherCATRxVar5_P1_S_h
   * Referenced by: '<S67>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_S_h[2];

  /* Computed Parameter: EtherCATRxVar5_P1_d
   * Referenced by: '<S67>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_d[70];

  /* Computed Parameter: EtherCATRxVar5_P2_S_g
   * Referenced by: '<S67>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_S_g[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_b;

  /* Computed Parameter: EtherCATRxVar9_P1_S_l
   * Referenced by: '<S67>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_S_l[2];

  /* Computed Parameter: EtherCATRxVar9_P1_p
   * Referenced by: '<S67>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_p[74];

  /* Computed Parameter: EtherCATRxVar9_P2_S_a
   * Referenced by: '<S67>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_S_a[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_c;

  /* Computed Parameter: EtherCATRxVar22_P1__f
   * Referenced by: '<S66>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1__f[2];

  /* Computed Parameter: EtherCATRxVar22_P1_d
   * Referenced by: '<S66>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1_d[61];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Tx Var 4'
   */
  real_T pooled61[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S66>/EtherCAT Rx Var 22'
   *   '<S66>/EtherCAT Tx Var 4'
   */
  real_T pooled62;

  /* Computed Parameter: EtherCATRxVar1_P1__c1
   * Referenced by: '<S67>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1__c1[2];

  /* Computed Parameter: EtherCATRxVar1_P1_g
   * Referenced by: '<S67>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_g[86];

  /* Computed Parameter: EtherCATRxVar1_P2_S_o
   * Referenced by: '<S67>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_S_o[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_o;

  /* Computed Parameter: EtherCATRxVar18_P1__k
   * Referenced by: '<S66>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1__k[2];

  /* Computed Parameter: EtherCATRxVar18_P1_i
   * Referenced by: '<S66>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1_i[63];

  /* Computed Parameter: EtherCATRxVar18_P2__p
   * Referenced by: '<S66>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2__p[2];

  /* Expression: sig_offset
   * Referenced by: '<S66>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2_i;

  /* Computed Parameter: EtherCATRxVar2_P1_S_a
   * Referenced by: '<S67>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_S_a[2];

  /* Computed Parameter: EtherCATRxVar2_P1_d
   * Referenced by: '<S67>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_d[60];

  /* Computed Parameter: EtherCATRxVar2_P2__en
   * Referenced by: '<S67>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2__en[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_o;

  /* Computed Parameter: EtherCATRxVar3_P1__kp
   * Referenced by: '<S67>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1__kp[2];

  /* Computed Parameter: EtherCATRxVar3_P1_m
   * Referenced by: '<S67>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_m[60];

  /* Computed Parameter: EtherCATRxVar3_P2_S_h
   * Referenced by: '<S67>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_S_h[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_mg;

  /* Computed Parameter: EtherCATRxVar23_P1__o
   * Referenced by: '<S69>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1__o[2];

  /* Computed Parameter: EtherCATRxVar23_P1_j
   * Referenced by: '<S69>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1_j[66];

  /* Computed Parameter: EtherCATRxVar23_P2__i
   * Referenced by: '<S69>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2__i[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2_e;

  /* Computed Parameter: EtherCATRxVar21_P1_if
   * Referenced by: '<S69>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1_if[2];

  /* Computed Parameter: EtherCATRxVar21_P1_m
   * Referenced by: '<S69>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1_m[68];

  /* Computed Parameter: EtherCATRxVar21_P2__d
   * Referenced by: '<S69>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2__d[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2_p;

  /* Computed Parameter: EtherCATRxVar20_P1__a
   * Referenced by: '<S69>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1__a[2];

  /* Computed Parameter: EtherCATRxVar20_P1_k
   * Referenced by: '<S69>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1_k[58];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Tx Var 3'
   */
  real_T pooled63[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S69>/EtherCAT Rx Var 20'
   *   '<S69>/EtherCAT Tx Var 3'
   */
  real_T pooled64;

  /* Computed Parameter: EtherCATRxVar22_P1__d
   * Referenced by: '<S69>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1__d[2];

  /* Computed Parameter: EtherCATRxVar22_P1_a
   * Referenced by: '<S69>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1_a[61];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Tx Var 4'
   */
  real_T pooled65[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S69>/EtherCAT Rx Var 22'
   *   '<S69>/EtherCAT Tx Var 4'
   */
  real_T pooled66;

  /* Computed Parameter: EtherCATRxVar18_P1__f
   * Referenced by: '<S69>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1__f[2];

  /* Computed Parameter: EtherCATRxVar18_P1_b
   * Referenced by: '<S69>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1_b[63];

  /* Computed Parameter: EtherCATRxVar18_P2__f
   * Referenced by: '<S69>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2__f[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2_k;

  /* Computed Parameter: EtherCATRxVar19_P1__f
   * Referenced by: '<S66>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1__f[2];

  /* Computed Parameter: EtherCATRxVar19_P1_e
   * Referenced by: '<S66>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_e[67];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Tx Var 5'
   */
  real_T pooled67[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S66>/EtherCAT Rx Var 19'
   *   '<S66>/EtherCAT Tx Var 5'
   */
  real_T pooled68;

  /* Computed Parameter: EtherCATRxVar19_P1__i
   * Referenced by: '<S69>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1__i[2];

  /* Computed Parameter: EtherCATRxVar19_P1_n
   * Referenced by: '<S69>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_n[67];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Tx Var 5'
   */
  real_T pooled69[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S69>/EtherCAT Rx Var 19'
   *   '<S69>/EtherCAT Tx Var 5'
   */
  real_T pooled70;

  /* Computed Parameter: EtherCATRxVar5_P1__ko
   * Referenced by: '<S69>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1__ko[2];

  /* Computed Parameter: EtherCATRxVar5_P1_kn
   * Referenced by: '<S69>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_kn[70];

  /* Computed Parameter: EtherCATRxVar5_P2__gf
   * Referenced by: '<S69>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2__gf[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_d;

  /* Computed Parameter: EtherCATRxVar9_P1_S_m
   * Referenced by: '<S69>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_S_m[2];

  /* Computed Parameter: EtherCATRxVar9_P1_d
   * Referenced by: '<S69>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_d[74];

  /* Computed Parameter: EtherCATRxVar9_P2__db
   * Referenced by: '<S69>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2__db[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_e;

  /* Computed Parameter: EtherCATRxVar1_P1_S_f
   * Referenced by: '<S69>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_S_f[2];

  /* Computed Parameter: EtherCATRxVar1_P1_i
   * Referenced by: '<S69>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_i[86];

  /* Computed Parameter: EtherCATRxVar1_P2_S_j
   * Referenced by: '<S69>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_S_j[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_bg;

  /* Computed Parameter: EtherCATRxVar2_P1_S_k
   * Referenced by: '<S69>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_S_k[2];

  /* Computed Parameter: EtherCATRxVar2_P1_i
   * Referenced by: '<S69>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_i[60];

  /* Computed Parameter: EtherCATRxVar2_P2_S_c
   * Referenced by: '<S69>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_S_c[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_mk;

  /* Computed Parameter: EtherCATRxVar3_P1_S_d
   * Referenced by: '<S69>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_S_d[2];

  /* Computed Parameter: EtherCATRxVar3_P1_h3
   * Referenced by: '<S69>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_h3[60];

  /* Computed Parameter: EtherCATRxVar3_P2__it
   * Referenced by: '<S69>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2__it[2];

  /* Expression: sig_offset
   * Referenced by: '<S69>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_j;

  /* Computed Parameter: EtherCATTxVar3_P1_Siz
   * Referenced by: '<S59>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_Siz[2];

  /* Computed Parameter: EtherCATTxVar3_P1
   * Referenced by: '<S59>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1[61];

  /* Computed Parameter: EtherCATTxVar4_P1_Siz
   * Referenced by: '<S59>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_Siz[2];

  /* Computed Parameter: EtherCATTxVar4_P1
   * Referenced by: '<S59>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1[61];

  /* Computed Parameter: EtherCATTxVar5_P1_Siz
   * Referenced by: '<S59>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_Siz[2];

  /* Computed Parameter: EtherCATTxVar5_P1
   * Referenced by: '<S59>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1[67];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive1'
   */
  real_T pooled71[2];

  /* Pooled Parameter (Expression: sig_type)
   * Referenced by:
   *   '<S59>/EtherCAT Tx Var 5'
   *   '<S60>/EtherCAT Tx Var 5'
   *   '<S66>/EtherCAT Tx Var 5'
   *   '<S67>/EtherCAT Tx Var 5'
   *   '<S68>/EtherCAT Tx Var 5'
   *   '<S69>/EtherCAT Tx Var 5'
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Receive1'
   */
  real_T pooled72;

  /* Computed Parameter: EtherCATTxVar3_P1_S_d
   * Referenced by: '<S60>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_S_d[2];

  /* Computed Parameter: EtherCATTxVar3_P1_g
   * Referenced by: '<S60>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_g[62];

  /* Computed Parameter: EtherCATTxVar4_P1_S_k
   * Referenced by: '<S60>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_S_k[2];

  /* Computed Parameter: EtherCATTxVar4_P1_h
   * Referenced by: '<S60>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_h[62];

  /* Computed Parameter: EtherCATTxVar5_P1_S_i
   * Referenced by: '<S60>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_S_i[2];

  /* Computed Parameter: EtherCATTxVar5_P1_e
   * Referenced by: '<S60>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_e[68];

  /* Computed Parameter: EtherCATRxVar4_P1_S_h
   * Referenced by: '<S61>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_S_h[2];

  /* Computed Parameter: EtherCATRxVar4_P1_f
   * Referenced by: '<S61>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_f[55];

  /* Computed Parameter: EtherCATRxVar4_P2_S_b
   * Referenced by: '<S61>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_S_b[2];

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_mr;

  /* Computed Parameter: EtherCATTxVar_P1_Size
   * Referenced by: '<S61>/EtherCAT Tx Var '
   */
  real_T EtherCATTxVar_P1_Size[2];

  /* Computed Parameter: EtherCATTxVar_P1
   * Referenced by: '<S61>/EtherCAT Tx Var '
   */
  real_T EtherCATTxVar_P1[61];

  /* Computed Parameter: EtherCATTxVar1_P1_Siz
   * Referenced by: '<S61>/EtherCAT Tx Var 1'
   */
  real_T EtherCATTxVar1_P1_Siz[2];

  /* Computed Parameter: EtherCATTxVar1_P1
   * Referenced by: '<S61>/EtherCAT Tx Var 1'
   */
  real_T EtherCATTxVar1_P1[61];

  /* Computed Parameter: EtherCATTxVar1_P2_Siz
   * Referenced by: '<S61>/EtherCAT Tx Var 1'
   */
  real_T EtherCATTxVar1_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S61>/EtherCAT Tx Var 1'
   */
  real_T EtherCATTxVar1_P2;

  /* Computed Parameter: EtherCATPDOReceive5_P
   * Referenced by: '<S71>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_P[2];

  /* Computed Parameter: EtherCATPDOReceive5_
   * Referenced by: '<S71>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_[37];

  /* Computed Parameter: EtherCATPDOReceive5_a
   * Referenced by: '<S71>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_a[2];

  /* Expression: sig_offset
   * Referenced by: '<S71>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_P2;

  /* Computed Parameter: EtherCATPDOReceive_P1
   * Referenced by: '<S71>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_P1[2];

  /* Computed Parameter: EtherCATPDOReceive_P
   * Referenced by: '<S71>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_P[45];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Transmit2'
   */
  real_T pooled73[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S71>/EtherCAT PDO Receive'
   *   '<S71>/EtherCAT PDO Transmit2'
   */
  real_T pooled74;

  /* Computed Parameter: EtherCATPDOReceive1_P
   * Referenced by: '<S71>/EtherCAT PDO Receive1'
   */
  real_T EtherCATPDOReceive1_P[2];

  /* Computed Parameter: EtherCATPDOReceive1_
   * Referenced by: '<S71>/EtherCAT PDO Receive1'
   */
  real_T EtherCATPDOReceive1_[47];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Transmit'
   */
  real_T pooled76[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S71>/EtherCAT PDO Receive1'
   *   '<S71>/EtherCAT PDO Transmit'
   */
  real_T pooled77;

  /* Computed Parameter: EtherCATPDOReceive2_P
   * Referenced by: '<S71>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_P[2];

  /* Computed Parameter: EtherCATPDOReceive2_
   * Referenced by: '<S71>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_[51];

  /* Computed Parameter: EtherCATPDOReceive2_e
   * Referenced by: '<S71>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_e[2];

  /* Expression: sig_offset
   * Referenced by: '<S71>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_P2;

  /* Computed Parameter: EtherCATPDOTransmit_P
   * Referenced by: '<S71>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmit_P[2];

  /* Computed Parameter: EtherCATPDOTransmit_
   * Referenced by: '<S71>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmit_[40];

  /* Computed Parameter: EtherCATPDOTransmit1_
   * Referenced by: '<S71>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit1_[2];

  /* Computed Parameter: EtherCATPDOTransmit1
   * Referenced by: '<S71>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit1[39];

  /* Computed Parameter: EtherCATPDOTransmit_d
   * Referenced by: '<S71>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit_d[2];

  /* Expression: sig_offset
   * Referenced by: '<S71>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit1_P2;

  /* Computed Parameter: EtherCATPDOTransmit2_
   * Referenced by: '<S71>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmit2_[2];

  /* Computed Parameter: EtherCATPDOTransmit2
   * Referenced by: '<S71>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmit2[44];

  /* Computed Parameter: EtherCATPDOReceive5_m
   * Referenced by: '<S88>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_m[2];

  /* Computed Parameter: EtherCATPDOReceive_o
   * Referenced by: '<S88>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive_o[38];

  /* Computed Parameter: EtherCATPDOReceive5_g
   * Referenced by: '<S88>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_g[2];

  /* Expression: sig_offset
   * Referenced by: '<S88>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_P2_f;

  /* Computed Parameter: EtherCATPDOReceive__o
   * Referenced by: '<S88>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive__o[2];

  /* Computed Parameter: EtherCATPDOReceive_a
   * Referenced by: '<S88>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_a[46];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Transmit2'
   */
  real_T pooled78[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S88>/EtherCAT PDO Receive'
   *   '<S88>/EtherCAT PDO Transmit2'
   */
  real_T pooled79;

  /* Computed Parameter: EtherCATPDOReceive1_h
   * Referenced by: '<S88>/EtherCAT PDO Receive1'
   */
  real_T EtherCATPDOReceive1_h[2];

  /* Computed Parameter: EtherCATPDOReceive_b
   * Referenced by: '<S88>/EtherCAT PDO Receive1'
   */
  real_T EtherCATPDOReceive_b[48];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Transmit'
   */
  real_T pooled80[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S88>/EtherCAT PDO Receive1'
   *   '<S88>/EtherCAT PDO Transmit'
   */
  real_T pooled81;

  /* Computed Parameter: EtherCATPDOReceive2_b
   * Referenced by: '<S88>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_b[2];

  /* Computed Parameter: EtherCATPDOReceive_h
   * Referenced by: '<S88>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive_h[52];

  /* Computed Parameter: EtherCATPDOReceive2_l
   * Referenced by: '<S88>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_l[2];

  /* Expression: sig_offset
   * Referenced by: '<S88>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_P2_n;

  /* Computed Parameter: EtherCATPDOTransmit_p
   * Referenced by: '<S88>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmit_p[2];

  /* Computed Parameter: EtherCATPDOTransmi_j
   * Referenced by: '<S88>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmi_j[41];

  /* Computed Parameter: EtherCATPDOTransmit_l
   * Referenced by: '<S88>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit_l[2];

  /* Computed Parameter: EtherCATPDOTransmi_n
   * Referenced by: '<S88>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmi_n[40];

  /* Computed Parameter: EtherCATPDOTransmit_n
   * Referenced by: '<S88>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit_n[2];

  /* Expression: sig_offset
   * Referenced by: '<S88>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit1_P2_e;

  /* Computed Parameter: EtherCATPDOTransmit_k
   * Referenced by: '<S88>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmit_k[2];

  /* Computed Parameter: EtherCATPDOTransmi_f
   * Referenced by: '<S88>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmi_f[45];

  /* Computed Parameter: EtherCATPDOReceive5_o
   * Referenced by: '<S105>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_o[2];

  /* Computed Parameter: EtherCATPDOReceive_n
   * Referenced by: '<S105>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive_n[37];

  /* Computed Parameter: EtherCATPDOReceive5_k
   * Referenced by: '<S105>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_k[2];

  /* Expression: sig_offset
   * Referenced by: '<S105>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_P2_b;

  /* Computed Parameter: EtherCATPDOReceive__p
   * Referenced by: '<S105>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive__p[2];

  /* Computed Parameter: EtherCATPDOReceive_j
   * Referenced by: '<S105>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_j[45];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Transmit2'
   */
  real_T pooled82[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S105>/EtherCAT PDO Receive'
   *   '<S105>/EtherCAT PDO Transmit2'
   */
  real_T pooled83;

  /* Computed Parameter: EtherCATPDOReceive1_o
   * Referenced by: '<S105>/EtherCAT PDO Receive1'
   */
  real_T EtherCATPDOReceive1_o[2];

  /* Computed Parameter: EtherCATPDOReceive_i
   * Referenced by: '<S105>/EtherCAT PDO Receive1'
   */
  real_T EtherCATPDOReceive_i[47];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Transmit'
   */
  real_T pooled84[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S105>/EtherCAT PDO Receive1'
   *   '<S105>/EtherCAT PDO Transmit'
   */
  real_T pooled85;

  /* Computed Parameter: EtherCATPDOReceive2_n
   * Referenced by: '<S105>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_n[2];

  /* Computed Parameter: EtherCATPDOReceive_m
   * Referenced by: '<S105>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive_m[51];

  /* Computed Parameter: EtherCATPDOReceive_nt
   * Referenced by: '<S105>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive_nt[2];

  /* Expression: sig_offset
   * Referenced by: '<S105>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_P2_c;

  /* Computed Parameter: EtherCATPDOTransmit_m
   * Referenced by: '<S105>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmit_m[2];

  /* Computed Parameter: EtherCATPDOTransm_nh
   * Referenced by: '<S105>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransm_nh[40];

  /* Computed Parameter: EtherCATPDOTransmit_h
   * Referenced by: '<S105>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit_h[2];

  /* Computed Parameter: EtherCATPDOTransmi_p
   * Referenced by: '<S105>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmi_p[39];

  /* Computed Parameter: EtherCATPDOTransmit_a
   * Referenced by: '<S105>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit_a[2];

  /* Expression: sig_offset
   * Referenced by: '<S105>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit1_P2_ec;

  /* Computed Parameter: EtherCATPDOTransmit_e
   * Referenced by: '<S105>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmit_e[2];

  /* Computed Parameter: EtherCATPDOTransm_fh
   * Referenced by: '<S105>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransm_fh[44];

  /* Computed Parameter: EtherCATPDOReceive5_p
   * Referenced by: '<S122>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_p[2];

  /* Computed Parameter: EtherCATPDOReceive_g
   * Referenced by: '<S122>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive_g[37];

  /* Computed Parameter: EtherCATPDOReceive_kx
   * Referenced by: '<S122>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive_kx[2];

  /* Expression: sig_offset
   * Referenced by: '<S122>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_P2_l;

  /* Computed Parameter: EtherCATPDOReceive__f
   * Referenced by: '<S122>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive__f[2];

  /* Computed Parameter: EtherCATPDOReceive_e
   * Referenced by: '<S122>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_e[45];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  real_T pooled86[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S122>/EtherCAT PDO Receive'
   *   '<S122>/EtherCAT PDO Transmit2'
   */
  real_T pooled87;

  /* Computed Parameter: EtherCATPDOReceive1_d
   * Referenced by: '<S122>/EtherCAT PDO Receive1'
   */
  real_T EtherCATPDOReceive1_d[2];

  /* Computed Parameter: EtherCATPDOReceiv_ja
   * Referenced by: '<S122>/EtherCAT PDO Receive1'
   */
  real_T EtherCATPDOReceiv_ja[47];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Transmit'
   */
  real_T pooled88[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S122>/EtherCAT PDO Receive1'
   *   '<S122>/EtherCAT PDO Transmit'
   */
  real_T pooled89;

  /* Computed Parameter: EtherCATPDOReceive3_P
   * Referenced by: '<S122>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_P[2];

  /* Computed Parameter: EtherCATPDOReceive3_
   * Referenced by: '<S122>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_[51];

  /* Computed Parameter: EtherCATPDOReceive3_f
   * Referenced by: '<S122>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_f[2];

  /* Expression: sig_offset
   * Referenced by: '<S122>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_P2;

  /* Computed Parameter: EtherCATPDOTransmit_g
   * Referenced by: '<S122>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmit_g[2];

  /* Computed Parameter: EtherCATPDOTransmi_e
   * Referenced by: '<S122>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmi_e[40];

  /* Computed Parameter: EtherCATPDOTransmi_mm
   * Referenced by: '<S122>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmi_mm[2];

  /* Computed Parameter: EtherCATPDOTransmi_m
   * Referenced by: '<S122>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmi_m[39];

  /* Computed Parameter: EtherCATPDOTransmi_gs
   * Referenced by: '<S122>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmi_gs[2];

  /* Expression: sig_offset
   * Referenced by: '<S122>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit1_P2_n;

  /* Computed Parameter: EtherCATPDOTransmi_gc
   * Referenced by: '<S122>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmi_gc[2];

  /* Computed Parameter: EtherCATPDOTransm_ea
   * Referenced by: '<S122>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransm_ea[44];

  /* Computed Parameter: EtherCATTxVar3_P1_S_e
   * Referenced by: '<S66>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_S_e[2];

  /* Computed Parameter: EtherCATTxVar3_P1_h
   * Referenced by: '<S66>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_h[61];

  /* Computed Parameter: EtherCATTxVar4_P1_S_f
   * Referenced by: '<S66>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_S_f[2];

  /* Computed Parameter: EtherCATTxVar4_P1_c
   * Referenced by: '<S66>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_c[61];

  /* Computed Parameter: EtherCATTxVar5_P1_S_j
   * Referenced by: '<S66>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_S_j[2];

  /* Computed Parameter: EtherCATTxVar5_P1_n
   * Referenced by: '<S66>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_n[67];

  /* Computed Parameter: EtherCATTxVar3_P1_S_o
   * Referenced by: '<S67>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_S_o[2];

  /* Computed Parameter: EtherCATTxVar3_P1_k
   * Referenced by: '<S67>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_k[61];

  /* Computed Parameter: EtherCATTxVar3_P2_Siz
   * Referenced by: '<S67>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S67>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P2;

  /* Computed Parameter: EtherCATTxVar4_P1_S_p
   * Referenced by: '<S67>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_S_p[2];

  /* Computed Parameter: EtherCATTxVar4_P1_ct
   * Referenced by: '<S67>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_ct[61];

  /* Computed Parameter: EtherCATTxVar5_P1_S_o
   * Referenced by: '<S67>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_S_o[2];

  /* Computed Parameter: EtherCATTxVar5_P1_g
   * Referenced by: '<S67>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_g[67];

  /* Computed Parameter: EtherCATTxVar3_P1_S_b
   * Referenced by: '<S68>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_S_b[2];

  /* Computed Parameter: EtherCATTxVar3_P1_b
   * Referenced by: '<S68>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_b[61];

  /* Computed Parameter: EtherCATTxVar4_P1_S_b
   * Referenced by: '<S68>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_S_b[2];

  /* Computed Parameter: EtherCATTxVar4_P1_p
   * Referenced by: '<S68>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_p[61];

  /* Computed Parameter: EtherCATTxVar5_P1__og
   * Referenced by: '<S68>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1__og[2];

  /* Computed Parameter: EtherCATTxVar5_P1_g4
   * Referenced by: '<S68>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_g4[67];

  /* Computed Parameter: EtherCATTxVar3_P1_S_i
   * Referenced by: '<S69>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_S_i[2];

  /* Computed Parameter: EtherCATTxVar3_P1_d
   * Referenced by: '<S69>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_d[61];

  /* Computed Parameter: EtherCATTxVar4_P1__bt
   * Referenced by: '<S69>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1__bt[2];

  /* Computed Parameter: EtherCATTxVar4_P1_m
   * Referenced by: '<S69>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_m[61];

  /* Computed Parameter: EtherCATTxVar5_P1_S_k
   * Referenced by: '<S69>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_S_k[2];

  /* Computed Parameter: EtherCATTxVar5_P1_a
   * Referenced by: '<S69>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_a[67];

  /* Pooled Parameter (Expression: 4)
   * Referenced by:
   *   '<S62>/ModeOfOperation'
   *   '<S63>/ModeOfOperation'
   *   '<S64>/ModeOfOperation'
   *   '<S65>/ModeOfOperation'
   */
  int8_T pooled101;
} ConstP_Walking_ATRIAS_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T q[13];                        /* '<Root>/q' */
  real_T dq[13];                       /* '<Root>/dq' */
  real_T EncoderAnglesClean[19];       /* '<Root>/EncoderAnglesClean' */
  real_T EncoderDerivsClean[19];       /* '<Root>/EncoderDerivsClean' */
  real_T MicrostrainEulerAnglesClean[3];/* '<Root>/MicrostrainEulerAnglesClean' */
  real_T MicrostrainEulerDerivsClean[3];/* '<Root>/MicrostrainEulerDerivsClean' */
  real_T AbsTick[10];                  /* '<Root>/AbsTick' */
  real_T IncTick[9];                   /* '<Root>/IncTick' */
  real_T ValidStates[3];               /* '<Root>/ValidStates' */
  real_T RotationMatrix[9];            /* '<Root>/RotationMatrix' */
  real_T MotorCurrentSafe[6];          /* '<Root>/MotorCurrentSafe' */
  real_T MedullaCommandSafe;           /* '<Root>/MedullaCommandSafe' */
  real_T SafetyState;                  /* '<Root>/SafetyState' */
  real_T u[6];                         /* '<Root>/u' */
  real_T y[6];                         /* '<Root>/y' */
  real_T dy[6];                        /* '<Root>/dy' */
  real_T ControlOutput[16];            /* '<Root>/ControlOutput' */
} ExtY_Walking_ATRIAS_T;

/* Backward compatible GRT Identifiers */
#define rtB                            Walking_ATRIAS_B
#define BlockIO                        B_Walking_ATRIAS_T
#define rtY                            Walking_ATRIAS_Y
#define ExternalOutputs                ExtY_Walking_ATRIAS_T
#define rtP                            Walking_ATRIAS_P
#define Parameters                     P_Walking_ATRIAS_T
#define rtDWork                        Walking_ATRIAS_DW
#define D_Work                         DW_Walking_ATRIAS_T
#define tConstBlockIOType              ConstB_Walking_ATRIAS_T
#define rtC                            Walking_ATRIAS_ConstB
#define ConstParam                     ConstP_Walking_ATRIAS_T
#define rtcP                           Walking_ATRIAS_ConstP

/* Parameters (auto storage) */
struct P_Walking_ATRIAS_T_ {
  RobotCalibrationBus Calibration;     /* Variable: Calibration
                                        * Referenced by:
                                        *   '<S38>/Calibration'
                                        *   '<S38>/KVHOrientation'
                                        *   '<S38>/MotorParameters'
                                        */
  real_T GearOffsets[4];               /* Variable: GearOffsets
                                        * Referenced by: '<S8>/GearOffset'
                                        */
  real_T IMUTorsoOffsets[2];           /* Variable: IMUTorsoOffsets
                                        * Referenced by: '<S8>/IMUTorsoOffset'
                                        */
  real_T LegHipTorqueLimit[2];         /* Variable: LegHipTorqueLimit
                                        * Referenced by: '<S20>/LegHipTorqueSat'
                                        */
  real_T MedullaCommand;               /* Variable: MedullaCommand
                                        * Referenced by: '<S8>/MedullaCommand'
                                        */
  real_T TorsoCOMOffsets[2];           /* Variable: TorsoCOMOffsets
                                        * Referenced by: '<S8>/TorsoCOMOffsets'
                                        */
  real_T dx_err_d_gain;                /* Variable: dx_err_d_gain
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T dx_err_p_gain;                /* Variable: dx_err_p_gain
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T dx_gain;                      /* Variable: dx_gain
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T dy_err_d_gain;                /* Variable: dy_err_d_gain
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T dy_err_p_gain;                /* Variable: dy_err_p_gain
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T dy_gain;                      /* Variable: dy_gain
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T hAlphaSet[360];               /* Variable: hAlphaSet
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T hip_gain;                     /* Variable: hip_gain
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T hip_offset;                   /* Variable: hip_offset
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T isTrackHold;                  /* Variable: isTrackHold
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T kd_hip;                       /* Variable: kd_hip
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T kd_st_leg;                    /* Variable: kd_st_leg
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T kd_sw_leg;                    /* Variable: kd_sw_leg
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T kd_vs;                        /* Variable: kd_vs
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T kd_yaw;                       /* Variable: kd_yaw
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T kp_hip;                       /* Variable: kp_hip
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T kp_st_leg;                    /* Variable: kp_st_leg
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T kp_sw_leg;                    /* Variable: kp_sw_leg
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T kp_vs;                        /* Variable: kp_vs
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T kp_yaw;                       /* Variable: kp_yaw
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T lbForce;                      /* Variable: lbForce
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T ps3Axes[6];                   /* Variable: ps3Axes
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T ps3Buttons[11];               /* Variable: ps3Buttons
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T ps3Pov;                       /* Variable: ps3Pov
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T step_gain;                    /* Variable: step_gain
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T t0_step;                      /* Variable: t0_step
                                        * Referenced by:
                                        *   '<S2>/Constant5'
                                        *   '<S2>/Controller3'
                                        */
  real_T theta_limits_norm[18];        /* Variable: theta_limits_norm
                                        * Referenced by: '<S2>/Constant'
                                        */
  real_T uHipGravity;                  /* Variable: uHipGravity
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T ubForce;                      /* Variable: ubForce
                                        * Referenced by: '<S2>/Controller3'
                                        */
  real_T velFilConst;                  /* Variable: velFilConst
                                        * Referenced by: '<S2>/Controller3'
                                        */
  boolean_T isSetHipConst;             /* Variable: isSetHipConst
                                        * Referenced by: '<S2>/Controller3'
                                        */
  boolean_T isSim;                     /* Variable: isSim
                                        * Referenced by: '<S2>/Controller3'
                                        */
  boolean_T isTestGravity;             /* Variable: isTestGravity
                                        * Referenced by: '<S2>/Controller3'
                                        */
  boolean_T isTestHipTrack;            /* Variable: isTestHipTrack
                                        * Referenced by: '<S2>/Controller3'
                                        */
  boolean_T isVCtracking;              /* Variable: isVCtracking
                                        * Referenced by: '<S2>/Controller3'
                                        */
  boolean_T isVirtualConstraint;       /* Variable: isVirtualConstraint
                                        * Referenced by: '<S2>/Controller3'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Walking_ATRIAS_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[1];
    SimStruct childSFunctions[187];
    SimStruct *childSFunctionPtrs[187];
    struct _ssBlkInfo2 blkInfo2[187];
    struct _ssSFcnModelMethods2 methods2[187];
    struct _ssSFcnModelMethods3 methods3[187];
    struct _ssStatesInfo2 statesInfo2[187];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn11;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn12;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn13;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn14;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn15;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn16;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn17;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn18;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn19;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn20;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn21;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn22;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn23;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn24;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn25;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn26;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn27;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn28;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn29;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn30;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn31;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn32;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn33;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn34;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn35;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn36;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn37;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn38;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn39;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn40;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn41;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn42;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn43;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn44;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn45;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn46;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn47;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn48;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn49;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn50;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn51;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn52;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn53;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn54;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn55;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn56;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn57;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn58;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn59;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn60;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn61;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn62;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn63;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn64;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn65;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn66;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn67;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn68;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn69;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn70;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn71;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn72;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn73;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn74;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn75;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn76;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn77;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn78;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn79;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn80;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn81;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn82;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn83;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn84;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn85;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn86;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn87;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn88;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn89;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn90;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn91;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn92;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn93;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn94;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn95;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn96;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn97;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn98;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn99;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn100;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn101;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn102;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn103;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn104;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn105;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn106;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn107;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn108;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn109;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn110;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn111;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn112;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn113;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn114;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn115;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn116;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn117;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn118;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn119;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn120;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn121;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn122;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn123;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn124;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn125;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn126;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn127;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn128;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn129;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn130;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn131;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn132;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn133;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn134;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn135;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn136;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn137;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn138;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn139;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn140;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn141;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn142;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn143;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn144;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn145;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn146;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn147;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn148;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn149;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn150;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn151;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn152;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn153;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn154;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn155;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn156;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn157;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn158;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn159;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn160;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn161;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn162;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn163;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn164;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn165;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn166;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn167;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn168;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn169;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn170;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn171;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn172;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn173;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn174;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn175;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn176;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn177;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn178;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn179;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn180;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn181;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn182;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn183;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn184;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn185;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn186;
  } NonInlinedSFcns;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[1];
    time_T offsetTimesArray[1];
    int_T sampleTimeTaskIDArray[1];
    int_T sampleHitArray[1];
    int_T perTaskSampleHitsArray[1];
    time_T tArray[1];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Walking_ATRIAS_T Walking_ATRIAS_P;

/* Block signals (auto storage) */
extern B_Walking_ATRIAS_T Walking_ATRIAS_B;

/* Block states (auto storage) */
extern DW_Walking_ATRIAS_T Walking_ATRIAS_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Walking_ATRIAS_T Walking_ATRIAS_Y;
extern const ConstB_Walking_ATRIAS_T Walking_ATRIAS_ConstB;/* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstP_Walking_ATRIAS_T Walking_ATRIAS_ConstP;

/* Model entry point functions */
extern void Walking_ATRIAS_initialize(void);
extern void Walking_ATRIAS_output(void);
extern void Walking_ATRIAS_update(void);
extern void Walking_ATRIAS_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Walking_ATRIAS_rtModel *Walking_ATRIAS(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Walking_ATRIAS_T *const Walking_ATRIAS_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'Walking_ATRIAS'
 * '<S1>'   : 'Walking_ATRIAS/Controller_Test1'
 * '<S2>'   : 'Walking_ATRIAS/RoughTerrain1'
 * '<S3>'   : 'Walking_ATRIAS/Scope 1'
 * '<S4>'   : 'Walking_ATRIAS/Scope 2'
 * '<S5>'   : 'Walking_ATRIAS/Scope 3'
 * '<S6>'   : 'Walking_ATRIAS/Scope 4'
 * '<S7>'   : 'Walking_ATRIAS/Scope 5'
 * '<S8>'   : 'Walking_ATRIAS/Subsystem1'
 * '<S9>'   : 'Walking_ATRIAS/Controller_Test1/MATLAB Function'
 * '<S10>'  : 'Walking_ATRIAS/Controller_Test1/Saturation'
 * '<S11>'  : 'Walking_ATRIAS/Controller_Test1/Scope 1'
 * '<S12>'  : 'Walking_ATRIAS/Controller_Test1/Scope 2'
 * '<S13>'  : 'Walking_ATRIAS/Controller_Test1/Scope 3'
 * '<S14>'  : 'Walking_ATRIAS/Controller_Test1/Scope 4'
 * '<S15>'  : 'Walking_ATRIAS/Controller_Test1/Scope 5'
 * '<S16>'  : 'Walking_ATRIAS/Controller_Test1/Scope 6'
 * '<S17>'  : 'Walking_ATRIAS/Controller_Test1/TrackHold'
 * '<S18>'  : 'Walking_ATRIAS/Controller_Test1/Saturation/Saturation Dynamic'
 * '<S19>'  : 'Walking_ATRIAS/Controller_Test1/TrackHold/Compare To Constant'
 * '<S20>'  : 'Walking_ATRIAS/RoughTerrain1/Saturation'
 * '<S21>'  : 'Walking_ATRIAS/RoughTerrain1/Scope 1'
 * '<S22>'  : 'Walking_ATRIAS/RoughTerrain1/Scope 2'
 * '<S23>'  : 'Walking_ATRIAS/RoughTerrain1/Scope 3'
 * '<S24>'  : 'Walking_ATRIAS/RoughTerrain1/Scope 4'
 * '<S25>'  : 'Walking_ATRIAS/RoughTerrain1/Scope 5'
 * '<S26>'  : 'Walking_ATRIAS/RoughTerrain1/Scope 6'
 * '<S27>'  : 'Walking_ATRIAS/RoughTerrain1/TrackHold'
 * '<S28>'  : 'Walking_ATRIAS/RoughTerrain1/UM2OSU Cooridnate Change'
 * '<S29>'  : 'Walking_ATRIAS/RoughTerrain1/UM2OSU Cooridnate Change2'
 * '<S30>'  : 'Walking_ATRIAS/RoughTerrain1/Saturation/Saturation Dynamic'
 * '<S31>'  : 'Walking_ATRIAS/RoughTerrain1/TrackHold/Compare To Constant'
 * '<S32>'  : 'Walking_ATRIAS/Subsystem1/AdjustForCOMOffset'
 * '<S33>'  : 'Walking_ATRIAS/Subsystem1/Reset'
 * '<S34>'  : 'Walking_ATRIAS/Subsystem1/SAFETY'
 * '<S35>'  : 'Walking_ATRIAS/Subsystem1/Saturation Dynamic'
 * '<S36>'  : 'Walking_ATRIAS/Subsystem1/Scope 5'
 * '<S37>'  : 'Walking_ATRIAS/Subsystem1/StateEstimator'
 * '<S38>'  : 'Walking_ATRIAS/Subsystem1/Subsystem'
 * '<S39>'  : 'Walking_ATRIAS/Subsystem1/Reset/Compare To Constant'
 * '<S40>'  : 'Walking_ATRIAS/Subsystem1/Reset/Compare To Constant1'
 * '<S41>'  : 'Walking_ATRIAS/Subsystem1/StateEstimator/GeneralizedCoordinates'
 * '<S42>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/ComputeEulerAngles1'
 * '<S43>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EncoderFilters1'
 * '<S44>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EstimateOrientation'
 * '<S45>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain'
 * '<S46>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/ZeroingLegs'
 * '<S47>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/calibrate'
 * '<S48>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/convert_mtr_current_to_pwm'
 * '<S49>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EncoderFilters1/CheckAndFilterEncoder'
 * '<S50>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EncoderFilters1/CheckAndFilterEncoder/Velocity Filter'
 * '<S51>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EncoderFilters1/CheckAndFilterEncoder/Velocity Filter/Logic Filter'
 * '<S52>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EncoderFilters1/CheckAndFilterEncoder/Velocity Filter/OSU_filter'
 * '<S53>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EncoderFilters1/CheckAndFilterEncoder/Velocity Filter/OSU_filter/difference'
 * '<S54>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/ConvertAmpCurrent'
 * '<S55>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/ConvertLogicVoltage'
 * '<S56>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/ConvertMotorVoltage'
 * '<S57>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/ConvertThermistors'
 * '<S58>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/EncodeSwitches'
 * '<S59>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3L'
 * '<S60>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/HipMedulla_3R'
 * '<S61>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/IMU_Medulla'
 * '<S62>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L'
 * '<S63>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R'
 * '<S64>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L'
 * '<S65>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R'
 * '<S66>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1L'
 * '<S67>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_1R'
 * '<S68>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2L'
 * '<S69>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegMedulla_2R'
 * '<S70>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Chart'
 * '<S71>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem'
 * '<S72>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem'
 * '<S73>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem1'
 * '<S74>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem2'
 * '<S75>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem3'
 * '<S76>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem4'
 * '<S77>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem5'
 * '<S78>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem6'
 * '<S79>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem1/EnableControlWord'
 * '<S80>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem1/FaultReset'
 * '<S81>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem1/NothingControlWord'
 * '<S82>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem1/ShutdownControlWord'
 * '<S83>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem2/Compare To Constant'
 * '<S84>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem3/Compare To Constant'
 * '<S85>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem4/Compare To Constant'
 * '<S86>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem5/Compare To Constant'
 * '<S87>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Chart'
 * '<S88>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem'
 * '<S89>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem'
 * '<S90>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem1'
 * '<S91>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem2'
 * '<S92>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem3'
 * '<S93>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem4'
 * '<S94>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem5'
 * '<S95>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem6'
 * '<S96>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem1/EnableControlWord'
 * '<S97>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem1/FaultReset'
 * '<S98>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem1/NothingControlWord'
 * '<S99>'  : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem1/ShutdownControlWord'
 * '<S100>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem2/Compare To Constant'
 * '<S101>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem3/Compare To Constant'
 * '<S102>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem4/Compare To Constant'
 * '<S103>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem5/Compare To Constant'
 * '<S104>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Chart'
 * '<S105>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem'
 * '<S106>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem'
 * '<S107>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem1'
 * '<S108>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem2'
 * '<S109>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem3'
 * '<S110>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem4'
 * '<S111>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem5'
 * '<S112>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem6'
 * '<S113>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem1/EnableControlWord'
 * '<S114>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem1/FaultReset'
 * '<S115>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem1/NothingControlWord'
 * '<S116>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem1/ShutdownControlWord'
 * '<S117>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem2/Compare To Constant'
 * '<S118>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem3/Compare To Constant'
 * '<S119>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem4/Compare To Constant'
 * '<S120>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem5/Compare To Constant'
 * '<S121>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Chart'
 * '<S122>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem'
 * '<S123>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem'
 * '<S124>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem1'
 * '<S125>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem2'
 * '<S126>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem3'
 * '<S127>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem4'
 * '<S128>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem5'
 * '<S129>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem6'
 * '<S130>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem1/EnableControlWord'
 * '<S131>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem1/FaultReset'
 * '<S132>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem1/NothingControlWord'
 * '<S133>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem1/ShutdownControlWord'
 * '<S134>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem2/Compare To Constant'
 * '<S135>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem3/Compare To Constant'
 * '<S136>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem4/Compare To Constant'
 * '<S137>' : 'Walking_ATRIAS/Subsystem1/Subsystem/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem5/Compare To Constant'
 */
#endif                                 /* RTW_HEADER_Walking_ATRIAS_h_ */
