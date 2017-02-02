/*
 * Walking01_withElmos.h
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
#ifndef RTW_HEADER_Walking01_withElmos_h_
#define RTW_HEADER_Walking01_withElmos_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include "rtw_modelmap.h"
#ifndef Walking01_withElmos_COMMON_INCLUDES_
# define Walking01_withElmos_COMMON_INCLUDES_
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
#include "io_config_xml_0.h"
#endif                                 /* Walking01_withElmos_COMMON_INCLUDES_ */

#include "Walking01_withElmos_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include "rt_defines.h"

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
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
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
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
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
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
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
#define rtModel_Walking01_withElmos    RT_MODEL_Walking01_withElmos_T

/* Definition for use in the target main file */
#define Walking01_withElmos_rtModel    RT_MODEL_Walking01_withElmos_T

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals for system '<S13>/ComputeEulerAngles' */
typedef struct {
  real_T ZYX[3];                       /* '<S13>/ComputeEulerAngles' */
  real_T dZYX[3];                      /* '<S13>/ComputeEulerAngles' */
  real_T Rk[9];                        /* '<S13>/ComputeEulerAngles' */
  real_T R0[9];                        /* '<S13>/ComputeEulerAngles' */
  real_T YawRollover[2];               /* '<S13>/ComputeEulerAngles' */
} B_ComputeEulerAngles_Walking0_T;

/* Block signals for system '<S24>/AnomalyDetection' */
typedef struct {
  real_T q_clean;                      /* '<S24>/AnomalyDetection' */
  real_T ErrorCount;                   /* '<S24>/AnomalyDetection' */
} B_AnomalyDetection_Walking01__T;

/* Block states (auto storage) for system '<S24>/AnomalyDetection' */
typedef struct {
  real_T q_last;                       /* '<S24>/AnomalyDetection' */
  real_T dq_last;                      /* '<S24>/AnomalyDetection' */
  real_T Counter_last;                 /* '<S24>/AnomalyDetection' */
  int32_T sfEvent;                     /* '<S24>/AnomalyDetection' */
  uint32_T temporalCounter_i1;         /* '<S24>/AnomalyDetection' */
  uint8_T is_active_c9_Walking01_withElmo;/* '<S24>/AnomalyDetection' */
  uint8_T is_c9_Walking01_withElmos;   /* '<S24>/AnomalyDetection' */
  uint8_T is_Run;                      /* '<S24>/AnomalyDetection' */
  boolean_T isStable;                  /* '<S24>/AnomalyDetection' */
} DW_AnomalyDetection_Walking01_T;

/* Block signals for system '<S18>/CoreSubsys' */
typedef struct {
  real_T UnitDelay;                    /* '<S24>/Unit Delay' */
  real_T DiscreteStateSpace;           /* '<S24>/Discrete State-Space' */
  B_AnomalyDetection_Walking01__T sf_AnomalyDetection;/* '<S24>/AnomalyDetection' */
} B_CoreSubsys_Walking01_withEl_T;

/* Block states (auto storage) for system '<S18>/CoreSubsys' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S24>/Unit Delay' */
  real_T DiscreteStateSpace_DSTATE[4]; /* '<S24>/Discrete State-Space' */
  DW_AnomalyDetection_Walking01_T sf_AnomalyDetection;/* '<S24>/AnomalyDetection' */
} DW_CoreSubsys_Walking01_withE_T;

/* Block signals for system '<S33>/TypecastAndCast1' */
typedef struct {
  real_T y[3];                         /* '<S33>/TypecastAndCast1' */
} B_TypecastAndCast1_Walking01__T;

/* Block states (auto storage) for system '<S48>/ShutdownControlWord' */
typedef struct {
  int8_T ShutdownControlWord_SubsysRanBC;/* '<S48>/ShutdownControlWord' */
} DW_ShutdownControlWord_Walkin_T;

/* Block states (auto storage) for system '<S48>/EnableControlWord' */
typedef struct {
  int8_T EnableControlWord_SubsysRanBC;/* '<S48>/EnableControlWord' */
} DW_EnableControlWord_Walking0_T;

/* Block states (auto storage) for system '<S48>/FaultReset' */
typedef struct {
  int8_T FaultReset_SubsysRanBC;       /* '<S48>/FaultReset' */
} DW_FaultReset_Walking01_withE_T;

/* Block states (auto storage) for system '<S48>/NothingControlWord' */
typedef struct {
  int8_T NothingControlWord_SubsysRanBC;/* '<S48>/NothingControlWord' */
} DW_NothingControlWord_Walking_T;

/* Block signals for system '<S35>/Chart' */
typedef struct {
  real_T ControlWordIndex;             /* '<S35>/Chart' */
  real_T EnableTargetTorque;           /* '<S35>/Chart' */
  real_T FaultDetected;                /* '<S35>/Chart' */
} B_Chart_Walking01_withElmos_T;

/* Block states (auto storage) for system '<S35>/Chart' */
typedef struct {
  real_T Timeout;                      /* '<S35>/Chart' */
  int32_T sfEvent;                     /* '<S35>/Chart' */
  uint8_T is_active_c22_Walking01_withElm;/* '<S35>/Chart' */
  uint8_T is_c22_Walking01_withElmos;  /* '<S35>/Chart' */
  uint8_T is_Initialization;           /* '<S35>/Chart' */
  boolean_T isStable;                  /* '<S35>/Chart' */
} DW_Chart_Walking01_withElmos_T;

/* Block signals for system '<S117>/AnomalyDetection' */
typedef struct {
  real_T q_clean;                      /* '<S117>/AnomalyDetection' */
  real_T ErrorCount;                   /* '<S117>/AnomalyDetection' */
} B_AnomalyDetection_Walking0_h_T;

/* Block states (auto storage) for system '<S117>/AnomalyDetection' */
typedef struct {
  real_T q_last;                       /* '<S117>/AnomalyDetection' */
  real_T dq_last;                      /* '<S117>/AnomalyDetection' */
  int32_T sfEvent;                     /* '<S117>/AnomalyDetection' */
  uint32_T temporalCounter_i1;         /* '<S117>/AnomalyDetection' */
  uint8_T is_active_c3_Walking01_withElmo;/* '<S117>/AnomalyDetection' */
  uint8_T is_c3_Walking01_withElmos;   /* '<S117>/AnomalyDetection' */
  uint8_T is_Run;                      /* '<S117>/AnomalyDetection' */
  boolean_T isStable;                  /* '<S117>/AnomalyDetection' */
} DW_AnomalyDetection_Walking_m_T;

/* Block signals for system '<S20>/CoreSubsys' */
typedef struct {
  real_T RateTransition;               /* '<S117>/Rate Transition' */
  real_T UnitDelay;                    /* '<S117>/Unit Delay' */
  real_T RateTransition6[2];           /* '<S117>/Rate Transition6' */
  real_T RateTransition5;              /* '<S117>/Rate Transition5' */
  real_T RateTransition3;              /* '<S117>/Rate Transition3' */
  real_T RateTransition4;              /* '<S117>/Rate Transition4' */
  real_T Switch;                       /* '<S117>/Switch' */
  boolean_T RateTransition7;           /* '<S117>/Rate Transition7' */
  B_AnomalyDetection_Walking0_h_T sf_AnomalyDetection;/* '<S117>/AnomalyDetection' */
} B_CoreSubsys_Walking01_with_c_T;

/* Block states (auto storage) for system '<S20>/CoreSubsys' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S117>/Unit Delay' */
  real_T DiscreteStateSpace_DSTATE[4]; /* '<S117>/Discrete State-Space' */
  real_T RateTransition1_Buffer[2];    /* '<S117>/Rate Transition1' */
  real_T RateTransition2_Buffer[2];    /* '<S117>/Rate Transition2' */
  real_T RateTransition8_Buffer[2];    /* '<S117>/Rate Transition8' */
  int8_T RateTransition1_ActiveBufIdx; /* '<S117>/Rate Transition1' */
  int8_T RateTransition2_ActiveBufIdx; /* '<S117>/Rate Transition2' */
  int8_T RateTransition8_ActiveBufIdx; /* '<S117>/Rate Transition8' */
  DW_AnomalyDetection_Walking_m_T sf_AnomalyDetection;/* '<S117>/AnomalyDetection' */
} DW_CoreSubsys_Walking01_wit_f_T;

/* Block signals (auto storage) */
typedef struct {
  ControlParamsBus BusConversion_InsertedFor_State;
  ControlParamsBus ControlParams;      /* '<S202>/StateLogic' */
  OutputParamsBus VectorConcatenate[5];/* '<S201>/Vector Concatenate' */
  ControlStateBus ControlState;        /* '<S202>/StateLogic' */
  serialfifoptr FIFOwrite1;            /* '<S193>/FIFO write 1' */
  real_T DataTypeConversion57;         /* '<S19>/Data Type Conversion57' */
  real_T DataTypeConversion81;         /* '<S19>/Data Type Conversion81' */
  real_T DataTypeConversion9;          /* '<S19>/Data Type Conversion9' */
  real_T DataTypeConversion33;         /* '<S19>/Data Type Conversion33' */
  real_T DataTypeConversion104;        /* '<S19>/Data Type Conversion104' */
  real_T DataTypeConversion119;        /* '<S19>/Data Type Conversion119' */
  real_T VectorConcatenate_m[19];      /* '<S13>/Vector Concatenate' */
  real_T TmpSignalConversionAtEncoderFil[19];
  real_T RateTransition2[3];           /* '<S5>/Rate Transition2' */
  real_T RateTransition1[3];           /* '<S5>/Rate Transition1' */
  real_T TKA[2];                       /* '<S214>/TKA' */
  real_T VectorConcatenate_a[2];       /* '<S214>/Vector Concatenate' */
  real_T EnableTransition;             /* '<S202>/EnableTransition' */
  real_T DataTypeConversion1;          /* '<S202>/Data Type Conversion1' */
  real_T ResetControl;                 /* '<S202>/ResetControl' */
  real_T DataTypeConversion97[6];      /* '<S19>/Data Type Conversion97' */
  real_T TaskExecutionTime;            /* '<S4>/Task Execution Time ' */
  real_T Bias;                         /* '<S4>/Bias' */
  real_T SerialOut[5];                 /* '<S202>/StateLogic' */
  real_T s;                            /* '<S200>/controller1' */
  real_T ErrorCount;                   /* '<S200>/CheckError' */
  real_T MedullaCommandSafe;           /* '<S1>/SAFETY' */
  real_T SafetyCountOut;               /* '<S1>/SAFETY' */
  real_T dq_clean[13];                 /* '<S16>/GeneralizedCoordinates' */
  real_T Rollover[9];                  /* '<S13>/calibrate' */
  real_T IncCalTick[6];                /* '<S13>/calibrate' */
  real_T ControlWordIndex;             /* '<S36>/Chart' */
  real_T EnableTargetTorque;           /* '<S36>/Chart' */
  real_T FaultDetected;                /* '<S36>/Chart' */
  real_T ControlWordIndex_j;           /* '<S34>/Chart' */
  real_T EnableTargetTorque_f;         /* '<S34>/Chart' */
  real_T FaultDetected_n;              /* '<S34>/Chart' */
  real_T q[13];                        /* '<S1>/AdjustForCOMOffset' */
  int32_T EtherCATInit[6];             /* '<S19>/EtherCAT Init ' */
  int32_T EtherCATPDOReceive1;         /* '<S64>/EtherCAT PDO Receive1' */
  int32_T EtherCATPDOReceive1_f;       /* '<S100>/EtherCAT PDO Receive1' */
  int32_T EtherCATPDOReceive1_n;       /* '<S46>/EtherCAT PDO Receive1' */
  int32_T EtherCATPDOReceive1_i;       /* '<S82>/EtherCAT PDO Receive1' */
  int32_T EtherCATPDOReceive4;         /* '<S64>/EtherCAT PDO Receive4' */
  int32_T EtherCATPDOReceive4_d;       /* '<S100>/EtherCAT PDO Receive4' */
  int32_T EtherCATPDOReceive4_b;       /* '<S46>/EtherCAT PDO Receive4' */
  int32_T EtherCATPDOReceive4_p;       /* '<S82>/EtherCAT PDO Receive4' */
  int32_T DataTypeConversion5;         /* '<S31>/Data Type Conversion5' */
  int32_T DataTypeConversion5_e;       /* '<S32>/Data Type Conversion5' */
  int32_T DataTypeConversion5_n;       /* '<S38>/Data Type Conversion5' */
  int32_T DataTypeConversion5_b;       /* '<S39>/Data Type Conversion5' */
  int32_T DataTypeConversion5_by;      /* '<S40>/Data Type Conversion5' */
  int32_T DataTypeConversion5_a;       /* '<S41>/Data Type Conversion5' */
  uint32_T EtherCATRxVar4;             /* '<S39>/EtherCAT Rx Var 4' */
  uint32_T EtherCATRxVar4_p;           /* '<S41>/EtherCAT Rx Var 4' */
  uint32_T EtherCATRxVar4_n;           /* '<S38>/EtherCAT Rx Var 4' */
  uint32_T EtherCATRxVar4_e;           /* '<S40>/EtherCAT Rx Var 4' */
  uint32_T EtherCATRxVar8;             /* '<S39>/EtherCAT Rx Var 8' */
  uint32_T EtherCATRxVar8_h;           /* '<S41>/EtherCAT Rx Var 8' */
  uint32_T EtherCATRxVar8_b;           /* '<S38>/EtherCAT Rx Var 8' */
  uint32_T EtherCATRxVar8_bs;          /* '<S40>/EtherCAT Rx Var 8' */
  uint32_T EtherCATRxVar4_m;           /* '<S32>/EtherCAT Rx Var 4' */
  uint32_T EtherCATRxVar4_nd;          /* '<S31>/EtherCAT Rx Var 4' */
  uint32_T EtherCATRxVar6;             /* '<S33>/EtherCAT Rx Var 6' */
  uint32_T EtherCATRxVar1;             /* '<S33>/EtherCAT Rx Var 1' */
  uint32_T EtherCATRxVar2;             /* '<S33>/EtherCAT Rx Var 2' */
  uint32_T EtherCATRxVar5;             /* '<S33>/EtherCAT Rx Var 5' */
  uint32_T EtherCATRxVar3;             /* '<S33>/EtherCAT Rx Var 3' */
  uint32_T EtherCATRxVar4_ph;          /* '<S33>/EtherCAT Rx Var 4' */
  uint32_T EtherCATRxVar19;            /* '<S33>/EtherCAT Rx Var 19' */
  uint32_T EtherCATRxVar7;             /* '<S33>/EtherCAT Rx Var 7' */
  uint32_T EtherCATRxVar8_m;           /* '<S33>/EtherCAT Rx Var 8' */
  uint32_T EtherCATRxVar10;            /* '<S33>/EtherCAT Rx Var 10' */
  uint32_T EtherCATRxVar14;            /* '<S33>/EtherCAT Rx Var 14' */
  uint32_T EtherCATRxVar13;            /* '<S33>/EtherCAT Rx Var 13' */
  uint32_T GetOverloadCounter;         /* '<S1>/Get Overload Counter ' */
  uint32_T RateTransition1_p;          /* '<S1>/Rate Transition1' */
  uint32_T RateTransition;             /* '<S1>/Rate Transition' */
  uint32_T EtherCATRxVar11;            /* '<S33>/EtherCAT Rx Var 11' */
  uint32_T EtherCATRxVar12;            /* '<S33>/EtherCAT Rx Var 12' */
  uint32_T EtherCATRxVar9;             /* '<S33>/EtherCAT Rx Var 9' */
  uint32_T GetOverloadCounter1;        /* '<S1>/Get Overload Counter 1' */
  uint32_T GetOverloadCounter2;        /* '<S1>/Get Overload Counter 2' */
  uint32_T ReadHWFIFO[65];             /* '<S193>/Read HW FIFO' */
  uint32_T FIFObinread[37];            /* '<S194>/FIFO bin read ' */
  int16_T EtherCATPDOReceive;          /* '<S64>/EtherCAT PDO Receive' */
  int16_T EtherCATPDOReceive_b;        /* '<S100>/EtherCAT PDO Receive' */
  int16_T EtherCATPDOReceive_n;        /* '<S46>/EtherCAT PDO Receive' */
  int16_T EtherCATPDOReceive_nq;       /* '<S82>/EtherCAT PDO Receive' */
  int16_T EtherCATPDOReceive3;         /* '<S64>/EtherCAT PDO Receive3' */
  int16_T EtherCATPDOReceive3_b;       /* '<S100>/EtherCAT PDO Receive3' */
  int16_T EtherCATPDOReceive3_j;       /* '<S46>/EtherCAT PDO Receive3' */
  int16_T EtherCATPDOReceive3_n;       /* '<S82>/EtherCAT PDO Receive3' */
  int16_T EtherCATRxVar6_n;            /* '<S39>/EtherCAT Rx Var 6' */
  int16_T EtherCATRxVar7_g;            /* '<S39>/EtherCAT Rx Var 7' */
  int16_T EtherCATRxVar6_o;            /* '<S41>/EtherCAT Rx Var 6' */
  int16_T EtherCATRxVar7_d;            /* '<S41>/EtherCAT Rx Var 7' */
  int16_T EtherCATRxVar;               /* '<S32>/EtherCAT Rx Var ' */
  int16_T EtherCATRxVar6_b;            /* '<S38>/EtherCAT Rx Var 6' */
  int16_T EtherCATRxVar7_b;            /* '<S38>/EtherCAT Rx Var 7' */
  int16_T EtherCATRxVar6_m;            /* '<S40>/EtherCAT Rx Var 6' */
  int16_T EtherCATRxVar7_gy;           /* '<S40>/EtherCAT Rx Var 7' */
  int16_T EtherCATRxVar_i;             /* '<S31>/EtherCAT Rx Var ' */
  int16_T Switch;                      /* '<S34>/Switch' */
  int16_T Switch_a;                    /* '<S35>/Switch' */
  int16_T Switch_d;                    /* '<S36>/Switch' */
  int16_T Switch_i;                    /* '<S37>/Switch' */
  uint16_T EtherCATRxVar_h;            /* '<S39>/EtherCAT Rx Var ' */
  uint16_T EtherCATRxVar_k;            /* '<S41>/EtherCAT Rx Var ' */
  uint16_T EtherCATRxVar_o;            /* '<S38>/EtherCAT Rx Var ' */
  uint16_T EtherCATRxVar_p;            /* '<S40>/EtherCAT Rx Var ' */
  uint16_T EtherCATRxVar2_g;           /* '<S32>/EtherCAT Rx Var 2' */
  uint16_T EtherCATRxVar2_i;           /* '<S31>/EtherCAT Rx Var 2' */
  uint16_T EtherCATRxVar12_p;          /* '<S39>/EtherCAT Rx Var 12' */
  uint16_T EtherCATRxVar13_h;          /* '<S39>/EtherCAT Rx Var 13' */
  uint16_T EtherCATRxVar14_h;          /* '<S39>/EtherCAT Rx Var 14' */
  uint16_T EtherCATRxVar15;            /* '<S39>/EtherCAT Rx Var 15' */
  uint16_T EtherCATRxVar16;            /* '<S39>/EtherCAT Rx Var 16' */
  uint16_T EtherCATRxVar17;            /* '<S39>/EtherCAT Rx Var 17' */
  uint16_T EtherCATRxVar12_c;          /* '<S41>/EtherCAT Rx Var 12' */
  uint16_T EtherCATRxVar13_o;          /* '<S41>/EtherCAT Rx Var 13' */
  uint16_T EtherCATRxVar14_g;          /* '<S41>/EtherCAT Rx Var 14' */
  uint16_T EtherCATRxVar15_m;          /* '<S41>/EtherCAT Rx Var 15' */
  uint16_T EtherCATRxVar16_b;          /* '<S41>/EtherCAT Rx Var 16' */
  uint16_T EtherCATRxVar17_k;          /* '<S41>/EtherCAT Rx Var 17' */
  uint16_T EtherCATRxVar12_h;          /* '<S32>/EtherCAT Rx Var 12' */
  uint16_T EtherCATRxVar13_e;          /* '<S32>/EtherCAT Rx Var 13' */
  uint16_T EtherCATRxVar14_f;          /* '<S32>/EtherCAT Rx Var 14' */
  uint16_T EtherCATRxVar12_b;          /* '<S38>/EtherCAT Rx Var 12' */
  uint16_T EtherCATRxVar13_j;          /* '<S38>/EtherCAT Rx Var 13' */
  uint16_T EtherCATRxVar14_fm;         /* '<S38>/EtherCAT Rx Var 14' */
  uint16_T EtherCATRxVar15_n;          /* '<S38>/EtherCAT Rx Var 15' */
  uint16_T EtherCATRxVar16_j;          /* '<S38>/EtherCAT Rx Var 16' */
  uint16_T EtherCATRxVar17_l;          /* '<S38>/EtherCAT Rx Var 17' */
  uint16_T EtherCATRxVar12_i;          /* '<S40>/EtherCAT Rx Var 12' */
  uint16_T EtherCATRxVar13_c;          /* '<S40>/EtherCAT Rx Var 13' */
  uint16_T EtherCATRxVar14_n;          /* '<S40>/EtherCAT Rx Var 14' */
  uint16_T EtherCATRxVar15_a;          /* '<S40>/EtherCAT Rx Var 15' */
  uint16_T EtherCATRxVar16_a;          /* '<S40>/EtherCAT Rx Var 16' */
  uint16_T EtherCATRxVar17_kd;         /* '<S40>/EtherCAT Rx Var 17' */
  uint16_T EtherCATRxVar12_pv;         /* '<S31>/EtherCAT Rx Var 12' */
  uint16_T EtherCATRxVar13_e0;         /* '<S31>/EtherCAT Rx Var 13' */
  uint16_T EtherCATRxVar14_b;          /* '<S31>/EtherCAT Rx Var 14' */
  uint16_T EtherCATPDOReceive5;        /* '<S64>/EtherCAT PDO Receive5' */
  uint16_T EtherCATPDOReceive5_d;      /* '<S100>/EtherCAT PDO Receive5' */
  uint16_T EtherCATPDOReceive5_h;      /* '<S46>/EtherCAT PDO Receive5' */
  uint16_T EtherCATPDOReceive5_p;      /* '<S82>/EtherCAT PDO Receive5' */
  uint16_T EtherCATRxVar10_c;          /* '<S39>/EtherCAT Rx Var 10' */
  uint16_T EtherCATRxVar10_f;          /* '<S41>/EtherCAT Rx Var 10' */
  uint16_T EtherCATRxVar6_a;           /* '<S32>/EtherCAT Rx Var 6' */
  uint16_T EtherCATRxVar10_b;          /* '<S38>/EtherCAT Rx Var 10' */
  uint16_T EtherCATRxVar10_g;          /* '<S40>/EtherCAT Rx Var 10' */
  uint16_T EtherCATRxVar6_f;           /* '<S31>/EtherCAT Rx Var 6' */
  uint16_T EtherCATRxVar11_b;          /* '<S39>/EtherCAT Rx Var 11' */
  uint16_T EtherCATRxVar11_a;          /* '<S41>/EtherCAT Rx Var 11' */
  uint16_T EtherCATRxVar1_p;           /* '<S32>/EtherCAT Rx Var 1' */
  uint16_T EtherCATRxVar11_h;          /* '<S38>/EtherCAT Rx Var 11' */
  uint16_T EtherCATRxVar11_l;          /* '<S40>/EtherCAT Rx Var 11' */
  uint16_T EtherCATRxVar1_m;           /* '<S31>/EtherCAT Rx Var 1' */
  uint16_T EtherCATRxVar5_n;           /* '<S38>/EtherCAT Rx Var 5' */
  uint16_T EtherCATRxVar5_o;           /* '<S32>/EtherCAT Rx Var 5' */
  uint16_T EtherCATRxVar3_h;           /* '<S32>/EtherCAT Rx Var 3' */
  uint16_T EtherCATRxVar9_p;           /* '<S38>/EtherCAT Rx Var 9' */
  uint16_T EtherCATRxVar1_h;           /* '<S38>/EtherCAT Rx Var 1' */
  uint16_T EtherCATRxVar5_d;           /* '<S31>/EtherCAT Rx Var 5' */
  uint16_T EtherCATRxVar3_c;           /* '<S31>/EtherCAT Rx Var 3' */
  uint16_T EtherCATRxVar23;            /* '<S38>/EtherCAT Rx Var 23' */
  uint16_T EtherCATRxVar2_o;           /* '<S38>/EtherCAT Rx Var 2' */
  uint16_T EtherCATRxVar3_j;           /* '<S38>/EtherCAT Rx Var 3' */
  uint16_T EtherCATRxVar23_c;          /* '<S40>/EtherCAT Rx Var 23' */
  uint16_T EtherCATRxVar5_l;           /* '<S40>/EtherCAT Rx Var 5' */
  uint16_T EtherCATRxVar9_a;           /* '<S40>/EtherCAT Rx Var 9' */
  uint16_T EtherCATRxVar1_b;           /* '<S40>/EtherCAT Rx Var 1' */
  uint16_T EtherCATRxVar2_m;           /* '<S40>/EtherCAT Rx Var 2' */
  uint16_T EtherCATRxVar3_o;           /* '<S40>/EtherCAT Rx Var 3' */
  uint16_T EtherCATRxVar23_e;          /* '<S39>/EtherCAT Rx Var 23' */
  uint16_T EtherCATRxVar5_k;           /* '<S39>/EtherCAT Rx Var 5' */
  uint16_T EtherCATRxVar9_i;           /* '<S39>/EtherCAT Rx Var 9' */
  uint16_T EtherCATRxVar1_f;           /* '<S39>/EtherCAT Rx Var 1' */
  uint16_T EtherCATRxVar2_n;           /* '<S39>/EtherCAT Rx Var 2' */
  uint16_T EtherCATRxVar3_c4;          /* '<S39>/EtherCAT Rx Var 3' */
  uint16_T EtherCATRxVar23_p;          /* '<S41>/EtherCAT Rx Var 23' */
  uint16_T EtherCATRxVar5_p;           /* '<S41>/EtherCAT Rx Var 5' */
  uint16_T EtherCATRxVar9_j;           /* '<S41>/EtherCAT Rx Var 9' */
  uint16_T EtherCATRxVar1_pm;          /* '<S41>/EtherCAT Rx Var 1' */
  uint16_T EtherCATRxVar2_p;           /* '<S41>/EtherCAT Rx Var 2' */
  uint16_T EtherCATRxVar3_k;           /* '<S41>/EtherCAT Rx Var 3' */
  uint16_T DataTypeConversion4;        /* '<S31>/Data Type Conversion4' */
  uint16_T DataTypeConversion4_h;      /* '<S32>/Data Type Conversion4' */
  uint16_T DataTypeConversion4_a;      /* '<S33>/Data Type Conversion4' */
  uint16_T DataTypeConversion1_l;      /* '<S33>/Data Type Conversion1' */
  uint16_T Merge;                      /* '<S48>/Merge' */
  uint16_T Merge_l;                    /* '<S66>/Merge' */
  uint16_T Merge_h;                    /* '<S84>/Merge' */
  uint16_T Merge_e;                    /* '<S102>/Merge' */
  uint16_T DataTypeConversion4_k;      /* '<S38>/Data Type Conversion4' */
  uint16_T DataTypeConversion4_i;      /* '<S39>/Data Type Conversion4' */
  uint16_T DataTypeConversion4_n;      /* '<S40>/Data Type Conversion4' */
  uint16_T DataTypeConversion4_o;      /* '<S41>/Data Type Conversion4' */
  int8_T EtherCATPDOReceive2;          /* '<S46>/EtherCAT PDO Receive2' */
  int8_T EtherCATPDOReceive2_k;        /* '<S64>/EtherCAT PDO Receive2' */
  int8_T EtherCATPDOReceive2_l;        /* '<S82>/EtherCAT PDO Receive2' */
  int8_T EtherCATPDOReceive2_h;        /* '<S100>/EtherCAT PDO Receive2' */
  uint8_T EtherCATRxVar18;             /* '<S39>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar18_c;           /* '<S41>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar18_i;           /* '<S38>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar18_f;           /* '<S40>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar15_b;           /* '<S32>/EtherCAT Rx Var 15' */
  uint8_T EtherCATRxVar15_g;           /* '<S31>/EtherCAT Rx Var 15' */
  uint8_T EtherCATRxVar17_c;           /* '<S33>/EtherCAT Rx Var 17' */
  uint8_T Compare;                     /* '<S216>/Compare' */
  uint8_T EtherCATRxVar21;             /* '<S39>/EtherCAT Rx Var 21' */
  uint8_T EtherCATRxVar21_b;           /* '<S41>/EtherCAT Rx Var 21' */
  uint8_T EtherCATRxVar18_j;           /* '<S32>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar21_o;           /* '<S38>/EtherCAT Rx Var 21' */
  uint8_T EtherCATRxVar21_m;           /* '<S40>/EtherCAT Rx Var 21' */
  uint8_T EtherCATRxVar18_h;           /* '<S31>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar22;             /* '<S39>/EtherCAT Rx Var 22' */
  uint8_T EtherCATRxVar22_o;           /* '<S41>/EtherCAT Rx Var 22' */
  uint8_T EtherCATRxVar19_o;           /* '<S32>/EtherCAT Rx Var 19' */
  uint8_T EtherCATRxVar22_g;           /* '<S38>/EtherCAT Rx Var 22' */
  uint8_T EtherCATRxVar22_a;           /* '<S40>/EtherCAT Rx Var 22' */
  uint8_T EtherCATRxVar19_i;           /* '<S31>/EtherCAT Rx Var 19' */
  uint8_T EtherCATRxVar18_k;           /* '<S33>/EtherCAT Rx Var 18' */
  uint8_T EtherCATRxVar19_c;           /* '<S39>/EtherCAT Rx Var 19' */
  uint8_T EtherCATRxVar19_m;           /* '<S41>/EtherCAT Rx Var 19' */
  uint8_T EtherCATRxVar16_bt;          /* '<S32>/EtherCAT Rx Var 16' */
  uint8_T EtherCATRxVar19_e;           /* '<S38>/EtherCAT Rx Var 19' */
  uint8_T EtherCATRxVar19_d;           /* '<S40>/EtherCAT Rx Var 19' */
  uint8_T EtherCATRxVar16_d;           /* '<S31>/EtherCAT Rx Var 16' */
  uint8_T EtherCATRxVar15_d;           /* '<S33>/EtherCAT Rx Var 15' */
  uint8_T EtherCATRxVar17_j;           /* '<S32>/EtherCAT Rx Var 17' */
  uint8_T EtherCATRxVar17_p;           /* '<S31>/EtherCAT Rx Var 17' */
  uint8_T EtherCATRxVar16_k;           /* '<S33>/EtherCAT Rx Var 16' */
  uint8_T EtherCATRxVar20;             /* '<S40>/EtherCAT Rx Var 20' */
  uint8_T EtherCATRxVar20_c;           /* '<S38>/EtherCAT Rx Var 20' */
  uint8_T EtherCATRxVar20_p;           /* '<S39>/EtherCAT Rx Var 20' */
  uint8_T EtherCATRxVar20_l;           /* '<S41>/EtherCAT Rx Var 20' */
  uint8_T DataTypeConversion3;         /* '<S31>/Data Type Conversion3' */
  uint8_T DataTypeConversion3_i;       /* '<S32>/Data Type Conversion3' */
  uint8_T DataTypeConversion3_j;       /* '<S33>/Data Type Conversion3' */
  uint8_T DataTypeConversion3_f;       /* '<S38>/Data Type Conversion3' */
  uint8_T DataTypeConversion3_g;       /* '<S39>/Data Type Conversion3' */
  uint8_T DataTypeConversion3_o;       /* '<S40>/Data Type Conversion3' */
  uint8_T DataTypeConversion3_f2;      /* '<S41>/Data Type Conversion3' */
  boolean_T LogicalOperator1;          /* '<S14>/Logical Operator1' */
  boolean_T Compare_l;                 /* '<S217>/Compare' */
  boolean_T FixPtRelationalOperator;   /* '<S213>/FixPt Relational Operator' */
  boolean_T RateTransition3;           /* '<S5>/Rate Transition3' */
  boolean_T Compare_n;                 /* '<S77>/Compare' */
  boolean_T Compare_lw;                /* '<S78>/Compare' */
  boolean_T Compare_a;                 /* '<S79>/Compare' */
  boolean_T Compare_e;                 /* '<S80>/Compare' */
  boolean_T Compare_p;                 /* '<S113>/Compare' */
  boolean_T Compare_i;                 /* '<S114>/Compare' */
  boolean_T Compare_j;                 /* '<S115>/Compare' */
  boolean_T Compare_c;                 /* '<S116>/Compare' */
  boolean_T Compare_pz;                /* '<S59>/Compare' */
  boolean_T Compare_h;                 /* '<S60>/Compare' */
  boolean_T Compare_e5;                /* '<S61>/Compare' */
  boolean_T Compare_g;                 /* '<S62>/Compare' */
  boolean_T Compare_n4;                /* '<S95>/Compare' */
  boolean_T Compare_f;                 /* '<S96>/Compare' */
  boolean_T Compare_co;                /* '<S97>/Compare' */
  boolean_T Compare_ju;                /* '<S98>/Compare' */
  boolean_T LogicalOperator2;          /* '<S14>/Logical Operator2' */
  B_ComputeEulerAngles_Walking0_T sf_ComputeEulerAngles_i;/* '<S124>/ComputeEulerAngles' */
  B_CoreSubsys_Walking01_with_c_T CoreSubsys_p[3];/* '<S20>/CoreSubsys' */
  B_Chart_Walking01_withElmos_T sf_Chart_b;/* '<S37>/Chart' */
  B_Chart_Walking01_withElmos_T sf_Chart;/* '<S35>/Chart' */
  B_TypecastAndCast1_Walking01__T sf_TypecastAndCast2;/* '<S33>/TypecastAndCast2' */
  B_TypecastAndCast1_Walking01__T sf_TypecastAndCast1;/* '<S33>/TypecastAndCast1' */
  B_CoreSubsys_Walking01_withEl_T CoreSubsys[19];/* '<S18>/CoreSubsys' */
  B_ComputeEulerAngles_Walking0_T sf_ComputeEulerAngles;/* '<S13>/ComputeEulerAngles' */
} B_Walking01_withElmos_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  ControlParamsBus ControlParamsPrev;  /* '<S202>/StateLogic' */
  ControlStateBus ControlStatePrev;    /* '<S202>/StateLogic' */
  real_T UnitDelay1_DSTATE[9];         /* '<S13>/Unit Delay1' */
  real_T UnitDelay_DSTATE[9];          /* '<S13>/Unit Delay' */
  real_T UnitDelay2_DSTATE[6];         /* '<S13>/Unit Delay2' */
  real_T UnitDelay4_DSTATE[9];         /* '<S13>/Unit Delay4' */
  real_T UnitDelay3_DSTATE[2];         /* '<S13>/Unit Delay3' */
  real_T DiscreteStateSpace_DSTATE[4]; /* '<S214>/Discrete State-Space' */
  real_T DiscreteStateSpace1_DSTATE[4];/* '<S214>/Discrete State-Space1' */
  real_T UnitDelay_DSTATE_d;           /* '<S200>/Unit Delay' */
  real_T UnitDelay1_DSTATE_g;          /* '<S200>/Unit Delay1' */
  real_T DiscreteFilter_states[30];    /* '<S21>/Discrete Filter' */
  real_T UnitDelay_DSTATE_k;           /* '<S1>/Unit Delay' */
  real_T UnitDelay1_DSTATE_h[4];       /* '<S1>/Unit Delay1' */
  real_T ResettableDelay_DSTATE;       /* '<S4>/Resettable Delay' */
  real_T UnitDelay2_DSTATE_o[9];       /* '<S124>/Unit Delay2' */
  real_T UnitDelay1_DSTATE_c[2];       /* '<S124>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_l[9];       /* '<S194>/Unit Delay1' */
  real_T UnitDelay2_DSTATE_p[3];       /* '<S194>/Unit Delay2' */
  real_T UnitDelay_DSTATE_p[3];        /* '<S194>/Unit Delay' */
  real_T UnitDelay3_DSTATE_j;          /* '<S194>/Unit Delay3' */
  real_T RateTransition2_Buffer0[3];   /* '<S5>/Rate Transition2' */
  real_T RateTransition1_Buffer0[3];   /* '<S5>/Rate Transition1' */
  real_T DiscreteFilter_tmp[30];       /* '<S21>/Discrete Filter' */
  real_T SerialBuffer[1976];           /* '<S202>/StateLogic' */
  real_T SerialIdx;                    /* '<S202>/StateLogic' */
  real_T TransitionStepCount;          /* '<S202>/StateLogic' */
  real_T WalkingStepCount;             /* '<S202>/StateLogic' */
  real_T s;                            /* '<S202>/StateLogic' */
  real_T SerialBufferBegin;            /* '<S202>/StateLogic' */
  real_T SerialBufferEnd;              /* '<S202>/StateLogic' */
  real_T theta;                        /* '<S202>/StateLogic' */
  real_T tLastSend;                    /* '<S202>/StateLogic' */
  real_T Timeout;                      /* '<S36>/Chart' */
  real_T Timeout_i;                    /* '<S34>/Chart' */
  void *FIFOwrite1_PWORK;              /* '<S193>/FIFO write 1' */
  void *FIFObinread_PWORK[2];          /* '<S194>/FIFO bin read ' */
  int32_T sfEvent;                     /* '<S202>/StateLogic' */
  int32_T sfEvent_p;                   /* '<S36>/Chart' */
  int32_T sfEvent_a;                   /* '<S34>/Chart' */
  uint32_T RateTransition1_Buffer0_i;  /* '<S1>/Rate Transition1' */
  uint32_T RateTransition_Buffer0;     /* '<S1>/Rate Transition' */
  uint32_T temporalCounter_i1;         /* '<S202>/StateLogic' */
  uint32_T temporalCounter_i2;         /* '<S202>/StateLogic' */
  int_T EtherCATRxVar4_IWORK[7];       /* '<S39>/EtherCAT Rx Var 4' */
  int_T EtherCATRxVar4_IWORK_p[7];     /* '<S41>/EtherCAT Rx Var 4' */
  int_T EtherCATRxVar4_IWORK_n[7];     /* '<S38>/EtherCAT Rx Var 4' */
  int_T EtherCATRxVar4_IWORK_k[7];     /* '<S40>/EtherCAT Rx Var 4' */
  int_T EtherCATRxVar8_IWORK[7];       /* '<S39>/EtherCAT Rx Var 8' */
  int_T EtherCATRxVar8_IWORK_m[7];     /* '<S41>/EtherCAT Rx Var 8' */
  int_T EtherCATRxVar8_IWORK_c[7];     /* '<S38>/EtherCAT Rx Var 8' */
  int_T EtherCATRxVar8_IWORK_l[7];     /* '<S40>/EtherCAT Rx Var 8' */
  int_T EtherCATRxVar4_IWORK_nb[7];    /* '<S32>/EtherCAT Rx Var 4' */
  int_T EtherCATRxVar4_IWORK_l[7];     /* '<S31>/EtherCAT Rx Var 4' */
  int_T EtherCATRxVar_IWORK[7];        /* '<S39>/EtherCAT Rx Var ' */
  int_T EtherCATRxVar_IWORK_b[7];      /* '<S41>/EtherCAT Rx Var ' */
  int_T EtherCATRxVar_IWORK_f[7];      /* '<S38>/EtherCAT Rx Var ' */
  int_T EtherCATRxVar_IWORK_c[7];      /* '<S40>/EtherCAT Rx Var ' */
  int_T EtherCATRxVar2_IWORK[7];       /* '<S32>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar2_IWORK_g[7];     /* '<S31>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar18_IWORK[7];      /* '<S39>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar18_IWORK_b[7];    /* '<S41>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar18_IWORK_c[7];    /* '<S38>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar18_IWORK_m[7];    /* '<S40>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar15_IWORK[7];      /* '<S32>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar15_IWORK_m[7];    /* '<S31>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar17_IWORK[7];      /* '<S33>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar6_IWORK[7];       /* '<S33>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar1_IWORK[7];       /* '<S33>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar2_IWORK_g0[7];    /* '<S33>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar5_IWORK[7];       /* '<S33>/EtherCAT Rx Var 5' */
  int_T EtherCATRxVar3_IWORK[7];       /* '<S33>/EtherCAT Rx Var 3' */
  int_T EtherCATRxVar4_IWORK_c[7];     /* '<S33>/EtherCAT Rx Var 4' */
  int_T EtherCATRxVar19_IWORK[7];      /* '<S33>/EtherCAT Rx Var 19' */
  int_T EtherCATRxVar7_IWORK[7];       /* '<S33>/EtherCAT Rx Var 7' */
  int_T EtherCATRxVar8_IWORK_d[7];     /* '<S33>/EtherCAT Rx Var 8' */
  int_T EtherCATRxVar10_IWORK[7];      /* '<S33>/EtherCAT Rx Var 10' */
  int_T EtherCATRxVar14_IWORK[7];      /* '<S33>/EtherCAT Rx Var 14' */
  int_T EtherCATRxVar13_IWORK[7];      /* '<S33>/EtherCAT Rx Var 13' */
  int_T EtherCATRxVar21_IWORK[7];      /* '<S39>/EtherCAT Rx Var 21' */
  int_T EtherCATRxVar21_IWORK_o[7];    /* '<S41>/EtherCAT Rx Var 21' */
  int_T EtherCATRxVar18_IWORK_i[7];    /* '<S32>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar21_IWORK_i[7];    /* '<S38>/EtherCAT Rx Var 21' */
  int_T EtherCATRxVar21_IWORK_g[7];    /* '<S40>/EtherCAT Rx Var 21' */
  int_T EtherCATRxVar18_IWORK_j[7];    /* '<S31>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar22_IWORK[7];      /* '<S39>/EtherCAT Rx Var 22' */
  int_T EtherCATRxVar22_IWORK_h[7];    /* '<S41>/EtherCAT Rx Var 22' */
  int_T EtherCATRxVar19_IWORK_i[7];    /* '<S32>/EtherCAT Rx Var 19' */
  int_T EtherCATRxVar22_IWORK_d[7];    /* '<S38>/EtherCAT Rx Var 22' */
  int_T EtherCATRxVar22_IWORK_o[7];    /* '<S40>/EtherCAT Rx Var 22' */
  int_T EtherCATRxVar19_IWORK_m[7];    /* '<S31>/EtherCAT Rx Var 19' */
  int_T EtherCATRxVar18_IWORK_e[7];    /* '<S33>/EtherCAT Rx Var 18' */
  int_T EtherCATRxVar19_IWORK_k[7];    /* '<S39>/EtherCAT Rx Var 19' */
  int_T EtherCATRxVar19_IWORK_h[7];    /* '<S41>/EtherCAT Rx Var 19' */
  int_T EtherCATRxVar16_IWORK[7];      /* '<S32>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar19_IWORK_n[7];    /* '<S38>/EtherCAT Rx Var 19' */
  int_T EtherCATRxVar19_IWORK_j[7];    /* '<S40>/EtherCAT Rx Var 19' */
  int_T EtherCATRxVar16_IWORK_e[7];    /* '<S31>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar15_IWORK_k[7];    /* '<S33>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar12_IWORK[7];      /* '<S39>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar13_IWORK_e[7];    /* '<S39>/EtherCAT Rx Var 13' */
  int_T EtherCATRxVar14_IWORK_i[7];    /* '<S39>/EtherCAT Rx Var 14' */
  int_T EtherCATRxVar15_IWORK_e[7];    /* '<S39>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar16_IWORK_d[7];    /* '<S39>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar17_IWORK_j[7];    /* '<S39>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar12_IWORK_p[7];    /* '<S41>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar13_IWORK_d[7];    /* '<S41>/EtherCAT Rx Var 13' */
  int_T EtherCATRxVar14_IWORK_n[7];    /* '<S41>/EtherCAT Rx Var 14' */
  int_T EtherCATRxVar15_IWORK_l[7];    /* '<S41>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar16_IWORK_a[7];    /* '<S41>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar17_IWORK_m[7];    /* '<S41>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar12_IWORK_c[7];    /* '<S32>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar13_IWORK_k[7];    /* '<S32>/EtherCAT Rx Var 13' */
  int_T EtherCATRxVar14_IWORK_b[7];    /* '<S32>/EtherCAT Rx Var 14' */
  int_T EtherCATRxVar12_IWORK_a[7];    /* '<S38>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar13_IWORK_eu[7];   /* '<S38>/EtherCAT Rx Var 13' */
  int_T EtherCATRxVar14_IWORK_p[7];    /* '<S38>/EtherCAT Rx Var 14' */
  int_T EtherCATRxVar15_IWORK_p[7];    /* '<S38>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar16_IWORK_n[7];    /* '<S38>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar17_IWORK_b[7];    /* '<S38>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar12_IWORK_l[7];    /* '<S40>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar13_IWORK_i[7];    /* '<S40>/EtherCAT Rx Var 13' */
  int_T EtherCATRxVar14_IWORK_f[7];    /* '<S40>/EtherCAT Rx Var 14' */
  int_T EtherCATRxVar15_IWORK_i[7];    /* '<S40>/EtherCAT Rx Var 15' */
  int_T EtherCATRxVar16_IWORK_nl[7];   /* '<S40>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar17_IWORK_p[7];    /* '<S40>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar12_IWORK_n[7];    /* '<S31>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar13_IWORK_g[7];    /* '<S31>/EtherCAT Rx Var 13' */
  int_T EtherCATRxVar14_IWORK_d[7];    /* '<S31>/EtherCAT Rx Var 14' */
  int_T EtherCATPDOReceive_IWORK[7];   /* '<S64>/EtherCAT PDO Receive' */
  int_T EtherCATPDOReceive_IWORK_f[7]; /* '<S100>/EtherCAT PDO Receive' */
  int_T EtherCATPDOReceive_IWORK_d[7]; /* '<S46>/EtherCAT PDO Receive' */
  int_T EtherCATPDOReceive_IWORK_o[7]; /* '<S82>/EtherCAT PDO Receive' */
  int_T EtherCATPDOReceive3_IWORK[7];  /* '<S64>/EtherCAT PDO Receive3' */
  int_T EtherCATPDOReceive3_IWORK_n[7];/* '<S100>/EtherCAT PDO Receive3' */
  int_T EtherCATPDOReceive3_IWORK_b[7];/* '<S46>/EtherCAT PDO Receive3' */
  int_T EtherCATPDOReceive3_IWORK_l[7];/* '<S82>/EtherCAT PDO Receive3' */
  int_T EtherCATPDOReceive1_IWORK[7];  /* '<S64>/EtherCAT PDO Receive1' */
  int_T EtherCATPDOReceive1_IWORK_f[7];/* '<S100>/EtherCAT PDO Receive1' */
  int_T EtherCATPDOReceive1_IWORK_m[7];/* '<S46>/EtherCAT PDO Receive1' */
  int_T EtherCATPDOReceive1_IWORK_l[7];/* '<S82>/EtherCAT PDO Receive1' */
  int_T EtherCATPDOReceive4_IWORK[7];  /* '<S64>/EtherCAT PDO Receive4' */
  int_T EtherCATPDOReceive4_IWORK_m[7];/* '<S100>/EtherCAT PDO Receive4' */
  int_T EtherCATPDOReceive4_IWORK_b[7];/* '<S46>/EtherCAT PDO Receive4' */
  int_T EtherCATPDOReceive4_IWORK_n[7];/* '<S82>/EtherCAT PDO Receive4' */
  int_T EtherCATPDOReceive5_IWORK[7];  /* '<S64>/EtherCAT PDO Receive5' */
  int_T EtherCATPDOReceive5_IWORK_b[7];/* '<S100>/EtherCAT PDO Receive5' */
  int_T EtherCATPDOReceive5_IWORK_c[7];/* '<S46>/EtherCAT PDO Receive5' */
  int_T EtherCATPDOReceive5_IWORK_j[7];/* '<S82>/EtherCAT PDO Receive5' */
  int_T EtherCATRxVar6_IWORK_l[7];     /* '<S39>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar7_IWORK_m[7];     /* '<S39>/EtherCAT Rx Var 7' */
  int_T EtherCATRxVar6_IWORK_p[7];     /* '<S41>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar7_IWORK_n[7];     /* '<S41>/EtherCAT Rx Var 7' */
  int_T EtherCATRxVar_IWORK_o[7];      /* '<S32>/EtherCAT Rx Var ' */
  int_T EtherCATRxVar6_IWORK_e[7];     /* '<S38>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar7_IWORK_mw[7];    /* '<S38>/EtherCAT Rx Var 7' */
  int_T EtherCATRxVar6_IWORK_j[7];     /* '<S40>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar7_IWORK_a[7];     /* '<S40>/EtherCAT Rx Var 7' */
  int_T EtherCATRxVar_IWORK_h[7];      /* '<S31>/EtherCAT Rx Var ' */
  int_T EtherCATRxVar10_IWORK_a[7];    /* '<S39>/EtherCAT Rx Var 10' */
  int_T EtherCATRxVar10_IWORK_h[7];    /* '<S41>/EtherCAT Rx Var 10' */
  int_T EtherCATRxVar6_IWORK_pu[7];    /* '<S32>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar10_IWORK_c[7];    /* '<S38>/EtherCAT Rx Var 10' */
  int_T EtherCATRxVar10_IWORK_n[7];    /* '<S40>/EtherCAT Rx Var 10' */
  int_T EtherCATRxVar6_IWORK_n[7];     /* '<S31>/EtherCAT Rx Var 6' */
  int_T EtherCATRxVar11_IWORK[7];      /* '<S39>/EtherCAT Rx Var 11' */
  int_T EtherCATRxVar11_IWORK_m[7];    /* '<S41>/EtherCAT Rx Var 11' */
  int_T EtherCATRxVar1_IWORK_m[7];     /* '<S32>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar11_IWORK_g[7];    /* '<S38>/EtherCAT Rx Var 11' */
  int_T EtherCATRxVar11_IWORK_d[7];    /* '<S40>/EtherCAT Rx Var 11' */
  int_T EtherCATRxVar1_IWORK_f[7];     /* '<S31>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar5_IWORK_d[7];     /* '<S38>/EtherCAT Rx Var 5' */
  int_T EtherCATRxVar5_IWORK_i[7];     /* '<S32>/EtherCAT Rx Var 5' */
  int_T EtherCATRxVar3_IWORK_h[7];     /* '<S32>/EtherCAT Rx Var 3' */
  int_T EtherCATRxVar9_IWORK[7];       /* '<S38>/EtherCAT Rx Var 9' */
  int_T EtherCATRxVar17_IWORK_i[7];    /* '<S32>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar1_IWORK_n[7];     /* '<S38>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar5_IWORK_p[7];     /* '<S31>/EtherCAT Rx Var 5' */
  int_T EtherCATRxVar3_IWORK_hk[7];    /* '<S31>/EtherCAT Rx Var 3' */
  int_T EtherCATRxVar17_IWORK_a[7];    /* '<S31>/EtherCAT Rx Var 17' */
  int_T EtherCATRxVar16_IWORK_m[7];    /* '<S33>/EtherCAT Rx Var 16' */
  int_T EtherCATRxVar23_IWORK[7];      /* '<S38>/EtherCAT Rx Var 23' */
  int_T EtherCATRxVar2_IWORK_o[7];     /* '<S38>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar3_IWORK_a[7];     /* '<S38>/EtherCAT Rx Var 3' */
  int_T EtherCATRxVar23_IWORK_k[7];    /* '<S40>/EtherCAT Rx Var 23' */
  int_T EtherCATRxVar20_IWORK[7];      /* '<S40>/EtherCAT Rx Var 20' */
  int_T EtherCATRxVar5_IWORK_ds[7];    /* '<S40>/EtherCAT Rx Var 5' */
  int_T EtherCATRxVar9_IWORK_d[7];     /* '<S40>/EtherCAT Rx Var 9' */
  int_T EtherCATRxVar1_IWORK_a[7];     /* '<S40>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar2_IWORK_a[7];     /* '<S40>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar3_IWORK_e[7];     /* '<S40>/EtherCAT Rx Var 3' */
  int_T EtherCATRxVar20_IWORK_e[7];    /* '<S38>/EtherCAT Rx Var 20' */
  int_T EtherCATRxVar23_IWORK_l[7];    /* '<S39>/EtherCAT Rx Var 23' */
  int_T EtherCATRxVar20_IWORK_c[7];    /* '<S39>/EtherCAT Rx Var 20' */
  int_T EtherCATRxVar5_IWORK_o[7];     /* '<S39>/EtherCAT Rx Var 5' */
  int_T EtherCATRxVar9_IWORK_j[7];     /* '<S39>/EtherCAT Rx Var 9' */
  int_T EtherCATRxVar1_IWORK_mc[7];    /* '<S39>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar2_IWORK_p[7];     /* '<S39>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar3_IWORK_j[7];     /* '<S39>/EtherCAT Rx Var 3' */
  int_T EtherCATRxVar23_IWORK_l4[7];   /* '<S41>/EtherCAT Rx Var 23' */
  int_T EtherCATRxVar20_IWORK_i[7];    /* '<S41>/EtherCAT Rx Var 20' */
  int_T EtherCATRxVar5_IWORK_h[7];     /* '<S41>/EtherCAT Rx Var 5' */
  int_T EtherCATRxVar9_IWORK_f[7];     /* '<S41>/EtherCAT Rx Var 9' */
  int_T EtherCATRxVar1_IWORK_ff[7];    /* '<S41>/EtherCAT Rx Var 1' */
  int_T EtherCATRxVar2_IWORK_h[7];     /* '<S41>/EtherCAT Rx Var 2' */
  int_T EtherCATRxVar3_IWORK_b[7];     /* '<S41>/EtherCAT Rx Var 3' */
  int_T EtherCATTxVar3_IWORK[7];       /* '<S31>/EtherCAT Tx Var 3' */
  int_T EtherCATTxVar4_IWORK[7];       /* '<S31>/EtherCAT Tx Var 4' */
  int_T EtherCATTxVar5_IWORK[7];       /* '<S31>/EtherCAT Tx Var 5' */
  int_T EtherCATTxVar3_IWORK_i[7];     /* '<S32>/EtherCAT Tx Var 3' */
  int_T EtherCATTxVar4_IWORK_l[7];     /* '<S32>/EtherCAT Tx Var 4' */
  int_T EtherCATTxVar5_IWORK_g[7];     /* '<S32>/EtherCAT Tx Var 5' */
  int_T EtherCATRxVar11_IWORK_c[7];    /* '<S33>/EtherCAT Rx Var 11' */
  int_T EtherCATRxVar12_IWORK_m[7];    /* '<S33>/EtherCAT Rx Var 12' */
  int_T EtherCATRxVar9_IWORK_o[7];     /* '<S33>/EtherCAT Rx Var 9' */
  int_T EtherCATTxVar_IWORK[7];        /* '<S33>/EtherCAT Tx Var ' */
  int_T EtherCATTxVar1_IWORK[7];       /* '<S33>/EtherCAT Tx Var 1' */
  int_T EtherCATTxVar2_IWORK[7];       /* '<S33>/EtherCAT Tx Var 2' */
  int_T EtherCATPDOReceive2_IWORK[7];  /* '<S46>/EtherCAT PDO Receive2' */
  int_T EtherCATPDOTransmit_IWORK[7];  /* '<S46>/EtherCAT PDO Transmit' */
  int_T EtherCATPDOTransmit1_IWORK[7]; /* '<S46>/EtherCAT PDO Transmit1' */
  int_T EtherCATPDOTransmit2_IWORK[7]; /* '<S46>/EtherCAT PDO Transmit2' */
  int_T EtherCATPDOReceive2_IWORK_p[7];/* '<S64>/EtherCAT PDO Receive2' */
  int_T EtherCATPDOTransmit_IWORK_i[7];/* '<S64>/EtherCAT PDO Transmit' */
  int_T EtherCATPDOTransmit1_IWORK_m[7];/* '<S64>/EtherCAT PDO Transmit1' */
  int_T EtherCATPDOTransmit2_IWORK_l[7];/* '<S64>/EtherCAT PDO Transmit2' */
  int_T EtherCATPDOReceive2_IWORK_k[7];/* '<S82>/EtherCAT PDO Receive2' */
  int_T EtherCATPDOTransmit_IWORK_o[7];/* '<S82>/EtherCAT PDO Transmit' */
  int_T EtherCATPDOTransmit1_IWORK_p[7];/* '<S82>/EtherCAT PDO Transmit1' */
  int_T EtherCATPDOTransmit2_IWORK_lo[7];/* '<S82>/EtherCAT PDO Transmit2' */
  int_T EtherCATPDOReceive2_IWORK_f[7];/* '<S100>/EtherCAT PDO Receive2' */
  int_T EtherCATPDOTransmit_IWORK_l[7];/* '<S100>/EtherCAT PDO Transmit' */
  int_T EtherCATPDOTransmit1_IWORK_pr[7];/* '<S100>/EtherCAT PDO Transmit1' */
  int_T EtherCATPDOTransmit2_IWORK_m[7];/* '<S100>/EtherCAT PDO Transmit2' */
  int_T EtherCATTxVar3_IWORK_ix[7];    /* '<S38>/EtherCAT Tx Var 3' */
  int_T EtherCATTxVar4_IWORK_h[7];     /* '<S38>/EtherCAT Tx Var 4' */
  int_T EtherCATTxVar5_IWORK_m[7];     /* '<S38>/EtherCAT Tx Var 5' */
  int_T EtherCATTxVar3_IWORK_k[7];     /* '<S39>/EtherCAT Tx Var 3' */
  int_T EtherCATTxVar4_IWORK_d[7];     /* '<S39>/EtherCAT Tx Var 4' */
  int_T EtherCATTxVar5_IWORK_e[7];     /* '<S39>/EtherCAT Tx Var 5' */
  int_T EtherCATTxVar3_IWORK_j[7];     /* '<S40>/EtherCAT Tx Var 3' */
  int_T EtherCATTxVar4_IWORK_e[7];     /* '<S40>/EtherCAT Tx Var 4' */
  int_T EtherCATTxVar5_IWORK_er[7];    /* '<S40>/EtherCAT Tx Var 5' */
  int_T EtherCATTxVar3_IWORK_f[7];     /* '<S41>/EtherCAT Tx Var 3' */
  int_T EtherCATTxVar4_IWORK_a[7];     /* '<S41>/EtherCAT Tx Var 4' */
  int_T EtherCATTxVar5_IWORK_n[7];     /* '<S41>/EtherCAT Tx Var 5' */
  int_T BoardSetup_IWORK;              /* '<S193>/Board Setup' */
  int_T Setup3_IWORK[3];               /* '<S193>/Setup3' */
  int_T ReadHWFIFO_IWORK;              /* '<S193>/Read HW FIFO' */
  int_T FIFOwrite1_IWORK[3];           /* '<S193>/FIFO write 1' */
  uint16_T Counter_Count;              /* '<S19>/Counter' */
  uint8_T DelayInput1_DSTATE;          /* '<S212>/Delay Input1' */
  boolean_T UnitDelay_DSTATE_n;        /* '<S14>/Unit Delay' */
  boolean_T DelayInput1_DSTATE_c;      /* '<S213>/Delay Input1' */
  int8_T ResetCPUOverloadCount_SubsysRan;/* '<S4>/Reset CPU Overload Count' */
  uint8_T Counter_Count_o;             /* '<S21>/Counter' */
  uint8_T icLoad;                      /* '<S4>/Resettable Delay' */
  uint8_T is_active_c22_LibWalking;    /* '<S202>/StateLogic' */
  uint8_T is_Main;                     /* '<S202>/StateLogic' */
  uint8_T is_active_Main;              /* '<S202>/StateLogic' */
  uint8_T is_Support;                  /* '<S202>/StateLogic' */
  uint8_T is_active_Support;           /* '<S202>/StateLogic' */
  uint8_T is_Stage;                    /* '<S202>/StateLogic' */
  uint8_T is_active_Stage;             /* '<S202>/StateLogic' */
  uint8_T is_ControllerMode;           /* '<S202>/StateLogic' */
  uint8_T is_active_ControllerMode;    /* '<S202>/StateLogic' */
  uint8_T is_Transition;               /* '<S202>/StateLogic' */
  uint8_T is_active_Serialize;         /* '<S202>/StateLogic' */
  uint8_T is_ControlStatus;            /* '<S202>/StateLogic' */
  uint8_T is_active_ControlStatus;     /* '<S202>/StateLogic' */
  uint8_T is_SerialState;              /* '<S202>/StateLogic' */
  uint8_T is_active_SerialState;       /* '<S202>/StateLogic' */
  uint8_T is_active_c23_Walking01_withElm;/* '<S36>/Chart' */
  uint8_T is_c23_Walking01_withElmos;  /* '<S36>/Chart' */
  uint8_T is_Initialization;           /* '<S36>/Chart' */
  uint8_T is_active_c20_Walking01_withElm;/* '<S34>/Chart' */
  uint8_T is_c20_Walking01_withElmos;  /* '<S34>/Chart' */
  uint8_T is_Initialization_h;         /* '<S34>/Chart' */
  boolean_T isStable;                  /* '<S202>/StateLogic' */
  boolean_T isStable_d;                /* '<S36>/Chart' */
  boolean_T isStable_m;                /* '<S34>/Chart' */
  DW_CoreSubsys_Walking01_wit_f_T CoreSubsys_p[3];/* '<S20>/CoreSubsys' */
  DW_NothingControlWord_Walking_T NothingControlWord_m;/* '<S102>/NothingControlWord' */
  DW_FaultReset_Walking01_withE_T FaultReset_i;/* '<S102>/FaultReset' */
  DW_EnableControlWord_Walking0_T EnableControlWord_m;/* '<S102>/EnableControlWord' */
  DW_ShutdownControlWord_Walkin_T ShutdownControlWord_ju;/* '<S102>/ShutdownControlWord' */
  DW_Chart_Walking01_withElmos_T sf_Chart_b;/* '<S37>/Chart' */
  DW_NothingControlWord_Walking_T NothingControlWord_k;/* '<S84>/NothingControlWord' */
  DW_FaultReset_Walking01_withE_T FaultReset_n;/* '<S84>/FaultReset' */
  DW_EnableControlWord_Walking0_T EnableControlWord_l;/* '<S84>/EnableControlWord' */
  DW_ShutdownControlWord_Walkin_T ShutdownControlWord_j;/* '<S84>/ShutdownControlWord' */
  DW_NothingControlWord_Walking_T NothingControlWord_d;/* '<S66>/NothingControlWord' */
  DW_FaultReset_Walking01_withE_T FaultReset_c;/* '<S66>/FaultReset' */
  DW_EnableControlWord_Walking0_T EnableControlWord_c;/* '<S66>/EnableControlWord' */
  DW_ShutdownControlWord_Walkin_T ShutdownControlWord_h;/* '<S66>/ShutdownControlWord' */
  DW_Chart_Walking01_withElmos_T sf_Chart;/* '<S35>/Chart' */
  DW_NothingControlWord_Walking_T NothingControlWord;/* '<S48>/NothingControlWord' */
  DW_FaultReset_Walking01_withE_T FaultReset;/* '<S48>/FaultReset' */
  DW_EnableControlWord_Walking0_T EnableControlWord;/* '<S48>/EnableControlWord' */
  DW_ShutdownControlWord_Walkin_T ShutdownControlWord;/* '<S48>/ShutdownControlWord' */
  DW_CoreSubsys_Walking01_withE_T CoreSubsys[19];/* '<S18>/CoreSubsys' */
} DW_Walking01_withElmos_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T DataTypeConversion141[3];/* '<S19>/Data Type Conversion141' */
  const real_T Gain;                   /* '<S1>/Gain' */
  const uint32_T DataTypeConversion;   /* '<S12>/Data Type  Conversion' */
} ConstB_Walking01_withElmos_T;

/* Constant parameters (auto storage) */
typedef struct {
  /* Expression: OutputPosing
   * Referenced by: '<S201>/OutputPosing'
   */
  OutputParamsBus OutputPosing_Value;

  /* Expression: OutputInjection
   * Referenced by: '<S201>/OutputInjection'
   */
  OutputParamsBus OutputInjection_Value;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S201>/OutputTransition'
   *   '<S201>/OutputWalkingDouble'
   *   '<S201>/OutputWalkingSingle'
   */
  OutputParamsBus pooled1;

  /* Expression: DefaultSupervisoryParams
   * Referenced by: '<S201>/DefaultSupervisoryParams'
   */
  SupervisoryParamsBus DefaultSupervisoryParams_V;

  /* Expression: Calibration
   * Referenced by: '<S13>/CalibrationParameters'
   */
  RobotCalibrationBus CalibrationParameters_Valu;

  /* Expression: DefaultFeedbackParams
   * Referenced by: '<S201>/DefaultFeedbackParams'
   */
  FeedbackParamsBus DefaultFeedbackParams_Valu;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S12>/xPC Set Overload Counter'
   *   '<S193>/FIFO write 1'
   *   '<S194>/FIFO bin read '
   */
  real_T pooled3[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S12>/xPC Set Overload Counter'
   *   '<S193>/FIFO write 1'
   *   '<S194>/FIFO bin read '
   */
  real_T pooled4;

  /* Pooled Parameter (Expression: )
   * Referenced by: '<S194>/FIFO bin read '
   */
  real_T pooled15[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by: '<S194>/FIFO bin read '
   */
  real_T pooled16;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S193>/FIFO write 1'
   *   '<S193>/Setup3'
   *   '<S194>/FIFO bin read '
   */
  real_T pooled17[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S193>/FIFO write 1'
   *   '<S193>/Setup3'
   *   '<S194>/FIFO bin read '
   */
  real_T pooled18;

  /* Computed Parameter: FIFObinread_P4_Size
   * Referenced by: '<S194>/FIFO bin read '
   */
  real_T FIFObinread_P4_Size[2];

  /* Expression: hdr
   * Referenced by: '<S194>/FIFO bin read '
   */
  real_T FIFObinread_P4[4];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 15'
   *   '<S31>/EtherCAT Rx Var 16'
   *   '<S31>/EtherCAT Rx Var 17'
   *   '<S31>/EtherCAT Rx Var 18'
   *   '<S31>/EtherCAT Rx Var 19'
   *   '<S31>/EtherCAT Tx Var 3'
   *   '<S32>/EtherCAT Rx Var 15'
   *   '<S32>/EtherCAT Rx Var 16'
   *   '<S32>/EtherCAT Rx Var 17'
   *   '<S32>/EtherCAT Rx Var 18'
   *   '<S32>/EtherCAT Rx Var 19'
   *   '<S32>/EtherCAT Tx Var 3'
   *   '<S33>/EtherCAT Rx Var 15'
   *   '<S33>/EtherCAT Rx Var 16'
   *   '<S33>/EtherCAT Rx Var 17'
   *   '<S33>/EtherCAT Rx Var 18'
   *   '<S33>/EtherCAT Tx Var '
   *   '<S38>/EtherCAT Rx Var 18'
   *   '<S38>/EtherCAT Rx Var 19'
   *   '<S38>/EtherCAT Rx Var 20'
   *   '<S38>/EtherCAT Rx Var 21'
   *   '<S38>/EtherCAT Rx Var 22'
   *   '<S38>/EtherCAT Tx Var 3'
   *   '<S39>/EtherCAT Rx Var 18'
   *   '<S39>/EtherCAT Rx Var 19'
   *   '<S39>/EtherCAT Rx Var 20'
   *   '<S39>/EtherCAT Rx Var 21'
   *   '<S39>/EtherCAT Rx Var 22'
   *   '<S39>/EtherCAT Tx Var 3'
   *   '<S40>/EtherCAT Rx Var 18'
   *   '<S40>/EtherCAT Rx Var 19'
   *   '<S40>/EtherCAT Rx Var 20'
   *   '<S40>/EtherCAT Rx Var 21'
   *   '<S40>/EtherCAT Rx Var 22'
   *   '<S40>/EtherCAT Tx Var 3'
   *   '<S41>/EtherCAT Rx Var 18'
   *   '<S41>/EtherCAT Rx Var 19'
   *   '<S41>/EtherCAT Rx Var 20'
   *   '<S41>/EtherCAT Rx Var 21'
   *   '<S41>/EtherCAT Rx Var 22'
   *   '<S41>/EtherCAT Tx Var 3'
   *   '<S193>/Setup3'
   *   '<S194>/FIFO bin read '
   */
  real_T pooled19[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 15'
   *   '<S31>/EtherCAT Rx Var 16'
   *   '<S31>/EtherCAT Rx Var 17'
   *   '<S31>/EtherCAT Rx Var 18'
   *   '<S31>/EtherCAT Rx Var 19'
   *   '<S31>/EtherCAT Tx Var 3'
   *   '<S32>/EtherCAT Rx Var 15'
   *   '<S32>/EtherCAT Rx Var 16'
   *   '<S32>/EtherCAT Rx Var 17'
   *   '<S32>/EtherCAT Rx Var 18'
   *   '<S32>/EtherCAT Rx Var 19'
   *   '<S32>/EtherCAT Tx Var 3'
   *   '<S33>/EtherCAT Rx Var 15'
   *   '<S33>/EtherCAT Rx Var 16'
   *   '<S33>/EtherCAT Rx Var 17'
   *   '<S33>/EtherCAT Rx Var 18'
   *   '<S33>/EtherCAT Tx Var '
   *   '<S38>/EtherCAT Rx Var 18'
   *   '<S38>/EtherCAT Rx Var 19'
   *   '<S38>/EtherCAT Rx Var 20'
   *   '<S38>/EtherCAT Rx Var 21'
   *   '<S38>/EtherCAT Rx Var 22'
   *   '<S38>/EtherCAT Tx Var 3'
   *   '<S39>/EtherCAT Rx Var 18'
   *   '<S39>/EtherCAT Rx Var 19'
   *   '<S39>/EtherCAT Rx Var 20'
   *   '<S39>/EtherCAT Rx Var 21'
   *   '<S39>/EtherCAT Rx Var 22'
   *   '<S39>/EtherCAT Tx Var 3'
   *   '<S40>/EtherCAT Rx Var 18'
   *   '<S40>/EtherCAT Rx Var 19'
   *   '<S40>/EtherCAT Rx Var 20'
   *   '<S40>/EtherCAT Rx Var 21'
   *   '<S40>/EtherCAT Rx Var 22'
   *   '<S40>/EtherCAT Tx Var 3'
   *   '<S41>/EtherCAT Rx Var 18'
   *   '<S41>/EtherCAT Rx Var 19'
   *   '<S41>/EtherCAT Rx Var 20'
   *   '<S41>/EtherCAT Rx Var 21'
   *   '<S41>/EtherCAT Rx Var 22'
   *   '<S41>/EtherCAT Tx Var 3'
   *   '<S193>/Setup3'
   *   '<S194>/FIFO bin read '
   */
  real_T pooled20;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var '
   *   '<S31>/EtherCAT Rx Var 1'
   *   '<S31>/EtherCAT Rx Var 12'
   *   '<S31>/EtherCAT Rx Var 13'
   *   '<S31>/EtherCAT Rx Var 14'
   *   '<S31>/EtherCAT Rx Var 15'
   *   '<S31>/EtherCAT Rx Var 16'
   *   '<S31>/EtherCAT Rx Var 17'
   *   '<S31>/EtherCAT Rx Var 18'
   *   '<S31>/EtherCAT Rx Var 19'
   *   '<S31>/EtherCAT Rx Var 2'
   *   '<S31>/EtherCAT Rx Var 3'
   *   '<S31>/EtherCAT Rx Var 4'
   *   '<S31>/EtherCAT Rx Var 5'
   *   '<S31>/EtherCAT Rx Var 6'
   *   '<S31>/EtherCAT Tx Var 3'
   *   '<S31>/EtherCAT Tx Var 4'
   *   '<S31>/EtherCAT Tx Var 5'
   *   '<S32>/EtherCAT Rx Var '
   *   '<S32>/EtherCAT Rx Var 1'
   *   '<S32>/EtherCAT Rx Var 12'
   *   '<S32>/EtherCAT Rx Var 13'
   *   '<S32>/EtherCAT Rx Var 14'
   *   '<S32>/EtherCAT Rx Var 15'
   *   '<S32>/EtherCAT Rx Var 16'
   *   '<S32>/EtherCAT Rx Var 17'
   *   '<S32>/EtherCAT Rx Var 18'
   *   '<S32>/EtherCAT Rx Var 19'
   *   '<S32>/EtherCAT Rx Var 2'
   *   '<S32>/EtherCAT Rx Var 3'
   *   '<S32>/EtherCAT Rx Var 4'
   *   '<S32>/EtherCAT Rx Var 5'
   *   '<S32>/EtherCAT Rx Var 6'
   *   '<S32>/EtherCAT Tx Var 3'
   *   '<S32>/EtherCAT Tx Var 4'
   *   '<S32>/EtherCAT Tx Var 5'
   *   '<S33>/EtherCAT Rx Var 1'
   *   '<S33>/EtherCAT Rx Var 10'
   *   '<S33>/EtherCAT Rx Var 11'
   *   '<S33>/EtherCAT Rx Var 12'
   *   '<S33>/EtherCAT Rx Var 13'
   *   '<S33>/EtherCAT Rx Var 14'
   *   '<S33>/EtherCAT Rx Var 15'
   *   '<S33>/EtherCAT Rx Var 16'
   *   '<S33>/EtherCAT Rx Var 17'
   *   '<S33>/EtherCAT Rx Var 18'
   *   '<S33>/EtherCAT Rx Var 19'
   *   '<S33>/EtherCAT Rx Var 2'
   *   '<S33>/EtherCAT Rx Var 3'
   *   '<S33>/EtherCAT Rx Var 4'
   *   '<S33>/EtherCAT Rx Var 5'
   *   '<S33>/EtherCAT Rx Var 6'
   *   '<S33>/EtherCAT Rx Var 7'
   *   '<S33>/EtherCAT Rx Var 8'
   *   '<S33>/EtherCAT Rx Var 9'
   *   '<S33>/EtherCAT Tx Var '
   *   '<S33>/EtherCAT Tx Var 1'
   *   '<S33>/EtherCAT Tx Var 2'
   *   '<S38>/EtherCAT Rx Var '
   *   '<S38>/EtherCAT Rx Var 1'
   *   '<S38>/EtherCAT Rx Var 10'
   *   '<S38>/EtherCAT Rx Var 11'
   *   '<S38>/EtherCAT Rx Var 12'
   *   '<S38>/EtherCAT Rx Var 13'
   *   '<S38>/EtherCAT Rx Var 14'
   *   '<S38>/EtherCAT Rx Var 15'
   *   '<S38>/EtherCAT Rx Var 16'
   *   '<S38>/EtherCAT Rx Var 17'
   *   '<S38>/EtherCAT Rx Var 18'
   *   '<S38>/EtherCAT Rx Var 19'
   *   '<S38>/EtherCAT Rx Var 2'
   *   '<S38>/EtherCAT Rx Var 20'
   *   '<S38>/EtherCAT Rx Var 21'
   *   '<S38>/EtherCAT Rx Var 22'
   *   '<S38>/EtherCAT Rx Var 23'
   *   '<S38>/EtherCAT Rx Var 3'
   *   '<S38>/EtherCAT Rx Var 4'
   *   '<S38>/EtherCAT Rx Var 5'
   *   '<S38>/EtherCAT Rx Var 6'
   *   '<S38>/EtherCAT Rx Var 7'
   *   '<S38>/EtherCAT Rx Var 8'
   *   '<S38>/EtherCAT Rx Var 9'
   *   '<S38>/EtherCAT Tx Var 3'
   *   '<S38>/EtherCAT Tx Var 4'
   *   '<S38>/EtherCAT Tx Var 5'
   *   '<S39>/EtherCAT Rx Var '
   *   '<S39>/EtherCAT Rx Var 1'
   *   '<S39>/EtherCAT Rx Var 10'
   *   '<S39>/EtherCAT Rx Var 11'
   *   '<S39>/EtherCAT Rx Var 12'
   *   '<S39>/EtherCAT Rx Var 13'
   *   '<S39>/EtherCAT Rx Var 14'
   *   '<S39>/EtherCAT Rx Var 15'
   *   '<S39>/EtherCAT Rx Var 16'
   *   '<S39>/EtherCAT Rx Var 17'
   *   '<S39>/EtherCAT Rx Var 18'
   *   '<S39>/EtherCAT Rx Var 19'
   *   '<S39>/EtherCAT Rx Var 2'
   *   '<S39>/EtherCAT Rx Var 20'
   *   '<S39>/EtherCAT Rx Var 21'
   *   '<S39>/EtherCAT Rx Var 22'
   *   '<S39>/EtherCAT Rx Var 23'
   *   '<S39>/EtherCAT Rx Var 3'
   *   '<S39>/EtherCAT Rx Var 4'
   *   '<S39>/EtherCAT Rx Var 5'
   *   '<S39>/EtherCAT Rx Var 6'
   *   '<S39>/EtherCAT Rx Var 7'
   *   '<S39>/EtherCAT Rx Var 8'
   *   '<S39>/EtherCAT Rx Var 9'
   *   '<S39>/EtherCAT Tx Var 3'
   *   '<S39>/EtherCAT Tx Var 4'
   *   '<S39>/EtherCAT Tx Var 5'
   *   '<S40>/EtherCAT Rx Var '
   *   '<S40>/EtherCAT Rx Var 1'
   *   '<S40>/EtherCAT Rx Var 10'
   *   '<S40>/EtherCAT Rx Var 11'
   *   '<S40>/EtherCAT Rx Var 12'
   *   '<S40>/EtherCAT Rx Var 13'
   *   '<S40>/EtherCAT Rx Var 14'
   *   '<S40>/EtherCAT Rx Var 15'
   *   '<S40>/EtherCAT Rx Var 16'
   *   '<S40>/EtherCAT Rx Var 17'
   *   '<S40>/EtherCAT Rx Var 18'
   *   '<S40>/EtherCAT Rx Var 19'
   *   '<S40>/EtherCAT Rx Var 2'
   *   '<S40>/EtherCAT Rx Var 20'
   *   '<S40>/EtherCAT Rx Var 21'
   *   '<S40>/EtherCAT Rx Var 22'
   *   '<S40>/EtherCAT Rx Var 23'
   *   '<S40>/EtherCAT Rx Var 3'
   *   '<S40>/EtherCAT Rx Var 4'
   *   '<S40>/EtherCAT Rx Var 5'
   *   '<S40>/EtherCAT Rx Var 6'
   *   '<S40>/EtherCAT Rx Var 7'
   *   '<S40>/EtherCAT Rx Var 8'
   *   '<S40>/EtherCAT Rx Var 9'
   *   '<S40>/EtherCAT Tx Var 3'
   *   '<S40>/EtherCAT Tx Var 4'
   *   '<S40>/EtherCAT Tx Var 5'
   *   '<S41>/EtherCAT Rx Var '
   *   '<S41>/EtherCAT Rx Var 1'
   *   '<S41>/EtherCAT Rx Var 10'
   *   '<S41>/EtherCAT Rx Var 11'
   *   '<S41>/EtherCAT Rx Var 12'
   *   '<S41>/EtherCAT Rx Var 13'
   *   '<S41>/EtherCAT Rx Var 14'
   *   '<S41>/EtherCAT Rx Var 15'
   *   '<S41>/EtherCAT Rx Var 16'
   *   '<S41>/EtherCAT Rx Var 17'
   *   '<S41>/EtherCAT Rx Var 18'
   *   '<S41>/EtherCAT Rx Var 19'
   *   '<S41>/EtherCAT Rx Var 2'
   *   '<S41>/EtherCAT Rx Var 20'
   *   '<S41>/EtherCAT Rx Var 21'
   *   '<S41>/EtherCAT Rx Var 22'
   *   '<S41>/EtherCAT Rx Var 23'
   *   '<S41>/EtherCAT Rx Var 3'
   *   '<S41>/EtherCAT Rx Var 4'
   *   '<S41>/EtherCAT Rx Var 5'
   *   '<S41>/EtherCAT Rx Var 6'
   *   '<S41>/EtherCAT Rx Var 7'
   *   '<S41>/EtherCAT Rx Var 8'
   *   '<S41>/EtherCAT Rx Var 9'
   *   '<S41>/EtherCAT Tx Var 3'
   *   '<S41>/EtherCAT Tx Var 4'
   *   '<S41>/EtherCAT Tx Var 5'
   *   '<S193>/FIFO write 1'
   *   '<S193>/Setup3'
   *   '<S194>/FIFO bin read '
   *   '<S46>/EtherCAT PDO Receive'
   *   '<S46>/EtherCAT PDO Receive1'
   *   '<S46>/EtherCAT PDO Receive2'
   *   '<S46>/EtherCAT PDO Receive3'
   *   '<S46>/EtherCAT PDO Receive4'
   *   '<S46>/EtherCAT PDO Receive5'
   *   '<S46>/EtherCAT PDO Transmit'
   *   '<S46>/EtherCAT PDO Transmit1'
   *   '<S46>/EtherCAT PDO Transmit2'
   *   '<S64>/EtherCAT PDO Receive'
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S64>/EtherCAT PDO Receive2'
   *   '<S64>/EtherCAT PDO Receive3'
   *   '<S64>/EtherCAT PDO Receive4'
   *   '<S64>/EtherCAT PDO Receive5'
   *   '<S64>/EtherCAT PDO Transmit'
   *   '<S64>/EtherCAT PDO Transmit1'
   *   '<S64>/EtherCAT PDO Transmit2'
   *   '<S82>/EtherCAT PDO Receive'
   *   '<S82>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive2'
   *   '<S82>/EtherCAT PDO Receive3'
   *   '<S82>/EtherCAT PDO Receive4'
   *   '<S82>/EtherCAT PDO Receive5'
   *   '<S82>/EtherCAT PDO Transmit'
   *   '<S82>/EtherCAT PDO Transmit1'
   *   '<S82>/EtherCAT PDO Transmit2'
   *   '<S100>/EtherCAT PDO Receive'
   *   '<S100>/EtherCAT PDO Receive1'
   *   '<S100>/EtherCAT PDO Receive2'
   *   '<S100>/EtherCAT PDO Receive3'
   *   '<S100>/EtherCAT PDO Receive4'
   *   '<S100>/EtherCAT PDO Receive5'
   *   '<S100>/EtherCAT PDO Transmit'
   *   '<S100>/EtherCAT PDO Transmit1'
   *   '<S100>/EtherCAT PDO Transmit2'
   */
  real_T pooled21[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var '
   *   '<S31>/EtherCAT Rx Var 1'
   *   '<S31>/EtherCAT Rx Var 12'
   *   '<S31>/EtherCAT Rx Var 13'
   *   '<S31>/EtherCAT Rx Var 14'
   *   '<S31>/EtherCAT Rx Var 15'
   *   '<S31>/EtherCAT Rx Var 16'
   *   '<S31>/EtherCAT Rx Var 17'
   *   '<S31>/EtherCAT Rx Var 18'
   *   '<S31>/EtherCAT Rx Var 19'
   *   '<S31>/EtherCAT Rx Var 2'
   *   '<S31>/EtherCAT Rx Var 3'
   *   '<S31>/EtherCAT Rx Var 4'
   *   '<S31>/EtherCAT Rx Var 5'
   *   '<S31>/EtherCAT Rx Var 6'
   *   '<S31>/EtherCAT Tx Var 3'
   *   '<S31>/EtherCAT Tx Var 4'
   *   '<S31>/EtherCAT Tx Var 5'
   *   '<S32>/EtherCAT Rx Var '
   *   '<S32>/EtherCAT Rx Var 1'
   *   '<S32>/EtherCAT Rx Var 12'
   *   '<S32>/EtherCAT Rx Var 13'
   *   '<S32>/EtherCAT Rx Var 14'
   *   '<S32>/EtherCAT Rx Var 15'
   *   '<S32>/EtherCAT Rx Var 16'
   *   '<S32>/EtherCAT Rx Var 17'
   *   '<S32>/EtherCAT Rx Var 18'
   *   '<S32>/EtherCAT Rx Var 19'
   *   '<S32>/EtherCAT Rx Var 2'
   *   '<S32>/EtherCAT Rx Var 3'
   *   '<S32>/EtherCAT Rx Var 4'
   *   '<S32>/EtherCAT Rx Var 5'
   *   '<S32>/EtherCAT Rx Var 6'
   *   '<S32>/EtherCAT Tx Var 3'
   *   '<S32>/EtherCAT Tx Var 4'
   *   '<S32>/EtherCAT Tx Var 5'
   *   '<S33>/EtherCAT Rx Var 1'
   *   '<S33>/EtherCAT Rx Var 10'
   *   '<S33>/EtherCAT Rx Var 11'
   *   '<S33>/EtherCAT Rx Var 12'
   *   '<S33>/EtherCAT Rx Var 13'
   *   '<S33>/EtherCAT Rx Var 14'
   *   '<S33>/EtherCAT Rx Var 15'
   *   '<S33>/EtherCAT Rx Var 16'
   *   '<S33>/EtherCAT Rx Var 17'
   *   '<S33>/EtherCAT Rx Var 18'
   *   '<S33>/EtherCAT Rx Var 19'
   *   '<S33>/EtherCAT Rx Var 2'
   *   '<S33>/EtherCAT Rx Var 3'
   *   '<S33>/EtherCAT Rx Var 4'
   *   '<S33>/EtherCAT Rx Var 5'
   *   '<S33>/EtherCAT Rx Var 6'
   *   '<S33>/EtherCAT Rx Var 7'
   *   '<S33>/EtherCAT Rx Var 8'
   *   '<S33>/EtherCAT Rx Var 9'
   *   '<S33>/EtherCAT Tx Var '
   *   '<S33>/EtherCAT Tx Var 1'
   *   '<S33>/EtherCAT Tx Var 2'
   *   '<S38>/EtherCAT Rx Var '
   *   '<S38>/EtherCAT Rx Var 1'
   *   '<S38>/EtherCAT Rx Var 10'
   *   '<S38>/EtherCAT Rx Var 11'
   *   '<S38>/EtherCAT Rx Var 12'
   *   '<S38>/EtherCAT Rx Var 13'
   *   '<S38>/EtherCAT Rx Var 14'
   *   '<S38>/EtherCAT Rx Var 15'
   *   '<S38>/EtherCAT Rx Var 16'
   *   '<S38>/EtherCAT Rx Var 17'
   *   '<S38>/EtherCAT Rx Var 18'
   *   '<S38>/EtherCAT Rx Var 19'
   *   '<S38>/EtherCAT Rx Var 2'
   *   '<S38>/EtherCAT Rx Var 20'
   *   '<S38>/EtherCAT Rx Var 21'
   *   '<S38>/EtherCAT Rx Var 22'
   *   '<S38>/EtherCAT Rx Var 23'
   *   '<S38>/EtherCAT Rx Var 3'
   *   '<S38>/EtherCAT Rx Var 4'
   *   '<S38>/EtherCAT Rx Var 5'
   *   '<S38>/EtherCAT Rx Var 6'
   *   '<S38>/EtherCAT Rx Var 7'
   *   '<S38>/EtherCAT Rx Var 8'
   *   '<S38>/EtherCAT Rx Var 9'
   *   '<S38>/EtherCAT Tx Var 3'
   *   '<S38>/EtherCAT Tx Var 4'
   *   '<S38>/EtherCAT Tx Var 5'
   *   '<S39>/EtherCAT Rx Var '
   *   '<S39>/EtherCAT Rx Var 1'
   *   '<S39>/EtherCAT Rx Var 10'
   *   '<S39>/EtherCAT Rx Var 11'
   *   '<S39>/EtherCAT Rx Var 12'
   *   '<S39>/EtherCAT Rx Var 13'
   *   '<S39>/EtherCAT Rx Var 14'
   *   '<S39>/EtherCAT Rx Var 15'
   *   '<S39>/EtherCAT Rx Var 16'
   *   '<S39>/EtherCAT Rx Var 17'
   *   '<S39>/EtherCAT Rx Var 18'
   *   '<S39>/EtherCAT Rx Var 19'
   *   '<S39>/EtherCAT Rx Var 2'
   *   '<S39>/EtherCAT Rx Var 20'
   *   '<S39>/EtherCAT Rx Var 21'
   *   '<S39>/EtherCAT Rx Var 22'
   *   '<S39>/EtherCAT Rx Var 23'
   *   '<S39>/EtherCAT Rx Var 3'
   *   '<S39>/EtherCAT Rx Var 4'
   *   '<S39>/EtherCAT Rx Var 5'
   *   '<S39>/EtherCAT Rx Var 6'
   *   '<S39>/EtherCAT Rx Var 7'
   *   '<S39>/EtherCAT Rx Var 8'
   *   '<S39>/EtherCAT Rx Var 9'
   *   '<S39>/EtherCAT Tx Var 3'
   *   '<S39>/EtherCAT Tx Var 4'
   *   '<S39>/EtherCAT Tx Var 5'
   *   '<S40>/EtherCAT Rx Var '
   *   '<S40>/EtherCAT Rx Var 1'
   *   '<S40>/EtherCAT Rx Var 10'
   *   '<S40>/EtherCAT Rx Var 11'
   *   '<S40>/EtherCAT Rx Var 12'
   *   '<S40>/EtherCAT Rx Var 13'
   *   '<S40>/EtherCAT Rx Var 14'
   *   '<S40>/EtherCAT Rx Var 15'
   *   '<S40>/EtherCAT Rx Var 16'
   *   '<S40>/EtherCAT Rx Var 17'
   *   '<S40>/EtherCAT Rx Var 18'
   *   '<S40>/EtherCAT Rx Var 19'
   *   '<S40>/EtherCAT Rx Var 2'
   *   '<S40>/EtherCAT Rx Var 20'
   *   '<S40>/EtherCAT Rx Var 21'
   *   '<S40>/EtherCAT Rx Var 22'
   *   '<S40>/EtherCAT Rx Var 23'
   *   '<S40>/EtherCAT Rx Var 3'
   *   '<S40>/EtherCAT Rx Var 4'
   *   '<S40>/EtherCAT Rx Var 5'
   *   '<S40>/EtherCAT Rx Var 6'
   *   '<S40>/EtherCAT Rx Var 7'
   *   '<S40>/EtherCAT Rx Var 8'
   *   '<S40>/EtherCAT Rx Var 9'
   *   '<S40>/EtherCAT Tx Var 3'
   *   '<S40>/EtherCAT Tx Var 4'
   *   '<S40>/EtherCAT Tx Var 5'
   *   '<S41>/EtherCAT Rx Var '
   *   '<S41>/EtherCAT Rx Var 1'
   *   '<S41>/EtherCAT Rx Var 10'
   *   '<S41>/EtherCAT Rx Var 11'
   *   '<S41>/EtherCAT Rx Var 12'
   *   '<S41>/EtherCAT Rx Var 13'
   *   '<S41>/EtherCAT Rx Var 14'
   *   '<S41>/EtherCAT Rx Var 15'
   *   '<S41>/EtherCAT Rx Var 16'
   *   '<S41>/EtherCAT Rx Var 17'
   *   '<S41>/EtherCAT Rx Var 18'
   *   '<S41>/EtherCAT Rx Var 19'
   *   '<S41>/EtherCAT Rx Var 2'
   *   '<S41>/EtherCAT Rx Var 20'
   *   '<S41>/EtherCAT Rx Var 21'
   *   '<S41>/EtherCAT Rx Var 22'
   *   '<S41>/EtherCAT Rx Var 23'
   *   '<S41>/EtherCAT Rx Var 3'
   *   '<S41>/EtherCAT Rx Var 4'
   *   '<S41>/EtherCAT Rx Var 5'
   *   '<S41>/EtherCAT Rx Var 6'
   *   '<S41>/EtherCAT Rx Var 7'
   *   '<S41>/EtherCAT Rx Var 8'
   *   '<S41>/EtherCAT Rx Var 9'
   *   '<S41>/EtherCAT Tx Var 3'
   *   '<S41>/EtherCAT Tx Var 4'
   *   '<S41>/EtherCAT Tx Var 5'
   *   '<S193>/FIFO write 1'
   *   '<S193>/Setup3'
   *   '<S194>/FIFO bin read '
   *   '<S46>/EtherCAT PDO Receive'
   *   '<S46>/EtherCAT PDO Receive1'
   *   '<S46>/EtherCAT PDO Receive2'
   *   '<S46>/EtherCAT PDO Receive3'
   *   '<S46>/EtherCAT PDO Receive4'
   *   '<S46>/EtherCAT PDO Receive5'
   *   '<S46>/EtherCAT PDO Transmit'
   *   '<S46>/EtherCAT PDO Transmit1'
   *   '<S46>/EtherCAT PDO Transmit2'
   *   '<S64>/EtherCAT PDO Receive'
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S64>/EtherCAT PDO Receive2'
   *   '<S64>/EtherCAT PDO Receive3'
   *   '<S64>/EtherCAT PDO Receive4'
   *   '<S64>/EtherCAT PDO Receive5'
   *   '<S64>/EtherCAT PDO Transmit'
   *   '<S64>/EtherCAT PDO Transmit1'
   *   '<S64>/EtherCAT PDO Transmit2'
   *   '<S82>/EtherCAT PDO Receive'
   *   '<S82>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive2'
   *   '<S82>/EtherCAT PDO Receive3'
   *   '<S82>/EtherCAT PDO Receive4'
   *   '<S82>/EtherCAT PDO Receive5'
   *   '<S82>/EtherCAT PDO Transmit'
   *   '<S82>/EtherCAT PDO Transmit1'
   *   '<S82>/EtherCAT PDO Transmit2'
   *   '<S100>/EtherCAT PDO Receive'
   *   '<S100>/EtherCAT PDO Receive1'
   *   '<S100>/EtherCAT PDO Receive2'
   *   '<S100>/EtherCAT PDO Receive3'
   *   '<S100>/EtherCAT PDO Receive4'
   *   '<S100>/EtherCAT PDO Receive5'
   *   '<S100>/EtherCAT PDO Transmit'
   *   '<S100>/EtherCAT PDO Transmit1'
   *   '<S100>/EtherCAT PDO Transmit2'
   */
  real_T pooled22;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S13>/Unit Delay'
   *   '<S13>/Unit Delay4'
   *   '<S124>/Unit Delay2'
   *   '<S194>/Rk'
   *   '<S194>/Unit Delay1'
   */
  real_T pooled23[9];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S193>/Board Setup'
   *   '<S193>/Read HW FIFO'
   *   '<S193>/Setup3'
   */
  real_T pooled25[2];

  /* Pooled Parameter (Expression: slot)
   * Referenced by:
   *   '<S193>/Board Setup'
   *   '<S193>/Read HW FIFO'
   *   '<S193>/Setup3'
   */
  real_T pooled26[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var '
   *   '<S32>/EtherCAT Rx Var '
   *   '<S38>/EtherCAT Rx Var 6'
   *   '<S38>/EtherCAT Rx Var 7'
   *   '<S39>/EtherCAT Rx Var 6'
   *   '<S39>/EtherCAT Rx Var 7'
   *   '<S40>/EtherCAT Rx Var 6'
   *   '<S40>/EtherCAT Rx Var 7'
   *   '<S41>/EtherCAT Rx Var 6'
   *   '<S41>/EtherCAT Rx Var 7'
   *   '<S193>/Board Setup'
   *   '<S46>/EtherCAT PDO Receive'
   *   '<S46>/EtherCAT PDO Receive3'
   *   '<S46>/EtherCAT PDO Transmit'
   *   '<S64>/EtherCAT PDO Receive'
   *   '<S64>/EtherCAT PDO Receive3'
   *   '<S64>/EtherCAT PDO Transmit'
   *   '<S82>/EtherCAT PDO Receive'
   *   '<S82>/EtherCAT PDO Receive3'
   *   '<S82>/EtherCAT PDO Transmit'
   *   '<S100>/EtherCAT PDO Receive'
   *   '<S100>/EtherCAT PDO Receive3'
   *   '<S100>/EtherCAT PDO Transmit'
   */
  real_T pooled27[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var '
   *   '<S32>/EtherCAT Rx Var '
   *   '<S38>/EtherCAT Rx Var 6'
   *   '<S38>/EtherCAT Rx Var 7'
   *   '<S39>/EtherCAT Rx Var 6'
   *   '<S39>/EtherCAT Rx Var 7'
   *   '<S40>/EtherCAT Rx Var 6'
   *   '<S40>/EtherCAT Rx Var 7'
   *   '<S41>/EtherCAT Rx Var 6'
   *   '<S41>/EtherCAT Rx Var 7'
   *   '<S193>/Board Setup'
   *   '<S46>/EtherCAT PDO Receive'
   *   '<S46>/EtherCAT PDO Receive3'
   *   '<S46>/EtherCAT PDO Transmit'
   *   '<S64>/EtherCAT PDO Receive'
   *   '<S64>/EtherCAT PDO Receive3'
   *   '<S64>/EtherCAT PDO Transmit'
   *   '<S82>/EtherCAT PDO Receive'
   *   '<S82>/EtherCAT PDO Receive3'
   *   '<S82>/EtherCAT PDO Transmit'
   *   '<S100>/EtherCAT PDO Receive'
   *   '<S100>/EtherCAT PDO Receive3'
   *   '<S100>/EtherCAT PDO Transmit'
   */
  real_T pooled28;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S193>/Board Setup'
   *   '<S193>/Read HW FIFO'
   *   '<S193>/Setup3'
   */
  real_T pooled29[2];

  /* Pooled Parameter (Expression: 102)
   * Referenced by:
   *   '<S193>/Board Setup'
   *   '<S193>/Read HW FIFO'
   *   '<S193>/Setup3'
   */
  real_T pooled30;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S193>/Read HW FIFO'
   *   '<S193>/Setup3'
   *   '<S46>/EtherCAT PDO Receive2'
   *   '<S46>/EtherCAT PDO Transmit2'
   *   '<S64>/EtherCAT PDO Receive2'
   *   '<S64>/EtherCAT PDO Transmit2'
   *   '<S82>/EtherCAT PDO Receive2'
   *   '<S82>/EtherCAT PDO Transmit2'
   *   '<S100>/EtherCAT PDO Receive2'
   *   '<S100>/EtherCAT PDO Transmit2'
   */
  real_T pooled31[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S193>/Read HW FIFO'
   *   '<S193>/Setup3'
   *   '<S46>/EtherCAT PDO Receive2'
   *   '<S46>/EtherCAT PDO Transmit2'
   *   '<S64>/EtherCAT PDO Receive2'
   *   '<S64>/EtherCAT PDO Transmit2'
   *   '<S82>/EtherCAT PDO Receive2'
   *   '<S82>/EtherCAT PDO Transmit2'
   *   '<S100>/EtherCAT PDO Receive2'
   *   '<S100>/EtherCAT PDO Transmit2'
   */
  real_T pooled32;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S4>/Task Execution Time '
   *   '<S31>/EtherCAT Rx Var '
   *   '<S31>/EtherCAT Rx Var 1'
   *   '<S31>/EtherCAT Rx Var 12'
   *   '<S31>/EtherCAT Rx Var 13'
   *   '<S31>/EtherCAT Rx Var 14'
   *   '<S31>/EtherCAT Rx Var 15'
   *   '<S31>/EtherCAT Rx Var 16'
   *   '<S31>/EtherCAT Rx Var 17'
   *   '<S31>/EtherCAT Rx Var 18'
   *   '<S31>/EtherCAT Rx Var 19'
   *   '<S31>/EtherCAT Rx Var 2'
   *   '<S31>/EtherCAT Rx Var 3'
   *   '<S31>/EtherCAT Rx Var 4'
   *   '<S31>/EtherCAT Rx Var 5'
   *   '<S31>/EtherCAT Rx Var 6'
   *   '<S31>/EtherCAT Tx Var 3'
   *   '<S31>/EtherCAT Tx Var 4'
   *   '<S31>/EtherCAT Tx Var 5'
   *   '<S32>/EtherCAT Rx Var '
   *   '<S32>/EtherCAT Rx Var 1'
   *   '<S32>/EtherCAT Rx Var 12'
   *   '<S32>/EtherCAT Rx Var 13'
   *   '<S32>/EtherCAT Rx Var 14'
   *   '<S32>/EtherCAT Rx Var 15'
   *   '<S32>/EtherCAT Rx Var 16'
   *   '<S32>/EtherCAT Rx Var 17'
   *   '<S32>/EtherCAT Rx Var 18'
   *   '<S32>/EtherCAT Rx Var 19'
   *   '<S32>/EtherCAT Rx Var 2'
   *   '<S32>/EtherCAT Rx Var 3'
   *   '<S32>/EtherCAT Rx Var 4'
   *   '<S32>/EtherCAT Rx Var 5'
   *   '<S32>/EtherCAT Rx Var 6'
   *   '<S32>/EtherCAT Tx Var 3'
   *   '<S32>/EtherCAT Tx Var 4'
   *   '<S32>/EtherCAT Tx Var 5'
   *   '<S33>/EtherCAT Rx Var 1'
   *   '<S33>/EtherCAT Rx Var 10'
   *   '<S33>/EtherCAT Rx Var 11'
   *   '<S33>/EtherCAT Rx Var 12'
   *   '<S33>/EtherCAT Rx Var 13'
   *   '<S33>/EtherCAT Rx Var 14'
   *   '<S33>/EtherCAT Rx Var 15'
   *   '<S33>/EtherCAT Rx Var 16'
   *   '<S33>/EtherCAT Rx Var 17'
   *   '<S33>/EtherCAT Rx Var 18'
   *   '<S33>/EtherCAT Rx Var 19'
   *   '<S33>/EtherCAT Rx Var 2'
   *   '<S33>/EtherCAT Rx Var 3'
   *   '<S33>/EtherCAT Rx Var 4'
   *   '<S33>/EtherCAT Rx Var 5'
   *   '<S33>/EtherCAT Rx Var 6'
   *   '<S33>/EtherCAT Rx Var 7'
   *   '<S33>/EtherCAT Rx Var 8'
   *   '<S33>/EtherCAT Rx Var 9'
   *   '<S33>/EtherCAT Tx Var '
   *   '<S33>/EtherCAT Tx Var 1'
   *   '<S33>/EtherCAT Tx Var 2'
   *   '<S38>/EtherCAT Rx Var '
   *   '<S38>/EtherCAT Rx Var 1'
   *   '<S38>/EtherCAT Rx Var 10'
   *   '<S38>/EtherCAT Rx Var 11'
   *   '<S38>/EtherCAT Rx Var 12'
   *   '<S38>/EtherCAT Rx Var 13'
   *   '<S38>/EtherCAT Rx Var 14'
   *   '<S38>/EtherCAT Rx Var 15'
   *   '<S38>/EtherCAT Rx Var 16'
   *   '<S38>/EtherCAT Rx Var 17'
   *   '<S38>/EtherCAT Rx Var 18'
   *   '<S38>/EtherCAT Rx Var 19'
   *   '<S38>/EtherCAT Rx Var 2'
   *   '<S38>/EtherCAT Rx Var 20'
   *   '<S38>/EtherCAT Rx Var 21'
   *   '<S38>/EtherCAT Rx Var 22'
   *   '<S38>/EtherCAT Rx Var 23'
   *   '<S38>/EtherCAT Rx Var 3'
   *   '<S38>/EtherCAT Rx Var 4'
   *   '<S38>/EtherCAT Rx Var 5'
   *   '<S38>/EtherCAT Rx Var 6'
   *   '<S38>/EtherCAT Rx Var 7'
   *   '<S38>/EtherCAT Rx Var 8'
   *   '<S38>/EtherCAT Rx Var 9'
   *   '<S38>/EtherCAT Tx Var 3'
   *   '<S38>/EtherCAT Tx Var 4'
   *   '<S38>/EtherCAT Tx Var 5'
   *   '<S39>/EtherCAT Rx Var '
   *   '<S39>/EtherCAT Rx Var 1'
   *   '<S39>/EtherCAT Rx Var 10'
   *   '<S39>/EtherCAT Rx Var 11'
   *   '<S39>/EtherCAT Rx Var 12'
   *   '<S39>/EtherCAT Rx Var 13'
   *   '<S39>/EtherCAT Rx Var 14'
   *   '<S39>/EtherCAT Rx Var 15'
   *   '<S39>/EtherCAT Rx Var 16'
   *   '<S39>/EtherCAT Rx Var 17'
   *   '<S39>/EtherCAT Rx Var 18'
   *   '<S39>/EtherCAT Rx Var 19'
   *   '<S39>/EtherCAT Rx Var 2'
   *   '<S39>/EtherCAT Rx Var 20'
   *   '<S39>/EtherCAT Rx Var 21'
   *   '<S39>/EtherCAT Rx Var 22'
   *   '<S39>/EtherCAT Rx Var 23'
   *   '<S39>/EtherCAT Rx Var 3'
   *   '<S39>/EtherCAT Rx Var 4'
   *   '<S39>/EtherCAT Rx Var 5'
   *   '<S39>/EtherCAT Rx Var 6'
   *   '<S39>/EtherCAT Rx Var 7'
   *   '<S39>/EtherCAT Rx Var 8'
   *   '<S39>/EtherCAT Rx Var 9'
   *   '<S39>/EtherCAT Tx Var 3'
   *   '<S39>/EtherCAT Tx Var 4'
   *   '<S39>/EtherCAT Tx Var 5'
   *   '<S40>/EtherCAT Rx Var '
   *   '<S40>/EtherCAT Rx Var 1'
   *   '<S40>/EtherCAT Rx Var 10'
   *   '<S40>/EtherCAT Rx Var 11'
   *   '<S40>/EtherCAT Rx Var 12'
   *   '<S40>/EtherCAT Rx Var 13'
   *   '<S40>/EtherCAT Rx Var 14'
   *   '<S40>/EtherCAT Rx Var 15'
   *   '<S40>/EtherCAT Rx Var 16'
   *   '<S40>/EtherCAT Rx Var 17'
   *   '<S40>/EtherCAT Rx Var 18'
   *   '<S40>/EtherCAT Rx Var 19'
   *   '<S40>/EtherCAT Rx Var 2'
   *   '<S40>/EtherCAT Rx Var 20'
   *   '<S40>/EtherCAT Rx Var 21'
   *   '<S40>/EtherCAT Rx Var 22'
   *   '<S40>/EtherCAT Rx Var 23'
   *   '<S40>/EtherCAT Rx Var 3'
   *   '<S40>/EtherCAT Rx Var 4'
   *   '<S40>/EtherCAT Rx Var 5'
   *   '<S40>/EtherCAT Rx Var 6'
   *   '<S40>/EtherCAT Rx Var 7'
   *   '<S40>/EtherCAT Rx Var 8'
   *   '<S40>/EtherCAT Rx Var 9'
   *   '<S40>/EtherCAT Tx Var 3'
   *   '<S40>/EtherCAT Tx Var 4'
   *   '<S40>/EtherCAT Tx Var 5'
   *   '<S41>/EtherCAT Rx Var '
   *   '<S41>/EtherCAT Rx Var 1'
   *   '<S41>/EtherCAT Rx Var 10'
   *   '<S41>/EtherCAT Rx Var 11'
   *   '<S41>/EtherCAT Rx Var 12'
   *   '<S41>/EtherCAT Rx Var 13'
   *   '<S41>/EtherCAT Rx Var 14'
   *   '<S41>/EtherCAT Rx Var 15'
   *   '<S41>/EtherCAT Rx Var 16'
   *   '<S41>/EtherCAT Rx Var 17'
   *   '<S41>/EtherCAT Rx Var 18'
   *   '<S41>/EtherCAT Rx Var 19'
   *   '<S41>/EtherCAT Rx Var 2'
   *   '<S41>/EtherCAT Rx Var 20'
   *   '<S41>/EtherCAT Rx Var 21'
   *   '<S41>/EtherCAT Rx Var 22'
   *   '<S41>/EtherCAT Rx Var 23'
   *   '<S41>/EtherCAT Rx Var 3'
   *   '<S41>/EtherCAT Rx Var 4'
   *   '<S41>/EtherCAT Rx Var 5'
   *   '<S41>/EtherCAT Rx Var 6'
   *   '<S41>/EtherCAT Rx Var 7'
   *   '<S41>/EtherCAT Rx Var 8'
   *   '<S41>/EtherCAT Rx Var 9'
   *   '<S41>/EtherCAT Tx Var 3'
   *   '<S41>/EtherCAT Tx Var 4'
   *   '<S41>/EtherCAT Tx Var 5'
   *   '<S193>/Read HW FIFO'
   *   '<S193>/Setup3'
   *   '<S46>/EtherCAT PDO Receive'
   *   '<S46>/EtherCAT PDO Receive1'
   *   '<S46>/EtherCAT PDO Receive2'
   *   '<S46>/EtherCAT PDO Receive3'
   *   '<S46>/EtherCAT PDO Receive4'
   *   '<S46>/EtherCAT PDO Receive5'
   *   '<S46>/EtherCAT PDO Transmit'
   *   '<S46>/EtherCAT PDO Transmit1'
   *   '<S46>/EtherCAT PDO Transmit2'
   *   '<S64>/EtherCAT PDO Receive'
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S64>/EtherCAT PDO Receive2'
   *   '<S64>/EtherCAT PDO Receive3'
   *   '<S64>/EtherCAT PDO Receive4'
   *   '<S64>/EtherCAT PDO Receive5'
   *   '<S64>/EtherCAT PDO Transmit'
   *   '<S64>/EtherCAT PDO Transmit1'
   *   '<S64>/EtherCAT PDO Transmit2'
   *   '<S82>/EtherCAT PDO Receive'
   *   '<S82>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive2'
   *   '<S82>/EtherCAT PDO Receive3'
   *   '<S82>/EtherCAT PDO Receive4'
   *   '<S82>/EtherCAT PDO Receive5'
   *   '<S82>/EtherCAT PDO Transmit'
   *   '<S82>/EtherCAT PDO Transmit1'
   *   '<S82>/EtherCAT PDO Transmit2'
   *   '<S100>/EtherCAT PDO Receive'
   *   '<S100>/EtherCAT PDO Receive1'
   *   '<S100>/EtherCAT PDO Receive2'
   *   '<S100>/EtherCAT PDO Receive3'
   *   '<S100>/EtherCAT PDO Receive4'
   *   '<S100>/EtherCAT PDO Receive5'
   *   '<S100>/EtherCAT PDO Transmit'
   *   '<S100>/EtherCAT PDO Transmit1'
   *   '<S100>/EtherCAT PDO Transmit2'
   */
  real_T pooled33[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S4>/Task Execution Time '
   *   '<S31>/EtherCAT Rx Var '
   *   '<S31>/EtherCAT Rx Var 1'
   *   '<S31>/EtherCAT Rx Var 12'
   *   '<S31>/EtherCAT Rx Var 13'
   *   '<S31>/EtherCAT Rx Var 14'
   *   '<S31>/EtherCAT Rx Var 15'
   *   '<S31>/EtherCAT Rx Var 16'
   *   '<S31>/EtherCAT Rx Var 17'
   *   '<S31>/EtherCAT Rx Var 18'
   *   '<S31>/EtherCAT Rx Var 19'
   *   '<S31>/EtherCAT Rx Var 2'
   *   '<S31>/EtherCAT Rx Var 3'
   *   '<S31>/EtherCAT Rx Var 4'
   *   '<S31>/EtherCAT Rx Var 5'
   *   '<S31>/EtherCAT Rx Var 6'
   *   '<S31>/EtherCAT Tx Var 3'
   *   '<S31>/EtherCAT Tx Var 4'
   *   '<S31>/EtherCAT Tx Var 5'
   *   '<S32>/EtherCAT Rx Var '
   *   '<S32>/EtherCAT Rx Var 1'
   *   '<S32>/EtherCAT Rx Var 12'
   *   '<S32>/EtherCAT Rx Var 13'
   *   '<S32>/EtherCAT Rx Var 14'
   *   '<S32>/EtherCAT Rx Var 15'
   *   '<S32>/EtherCAT Rx Var 16'
   *   '<S32>/EtherCAT Rx Var 17'
   *   '<S32>/EtherCAT Rx Var 18'
   *   '<S32>/EtherCAT Rx Var 19'
   *   '<S32>/EtherCAT Rx Var 2'
   *   '<S32>/EtherCAT Rx Var 3'
   *   '<S32>/EtherCAT Rx Var 4'
   *   '<S32>/EtherCAT Rx Var 5'
   *   '<S32>/EtherCAT Rx Var 6'
   *   '<S32>/EtherCAT Tx Var 3'
   *   '<S32>/EtherCAT Tx Var 4'
   *   '<S32>/EtherCAT Tx Var 5'
   *   '<S33>/EtherCAT Rx Var 1'
   *   '<S33>/EtherCAT Rx Var 10'
   *   '<S33>/EtherCAT Rx Var 11'
   *   '<S33>/EtherCAT Rx Var 12'
   *   '<S33>/EtherCAT Rx Var 13'
   *   '<S33>/EtherCAT Rx Var 14'
   *   '<S33>/EtherCAT Rx Var 15'
   *   '<S33>/EtherCAT Rx Var 16'
   *   '<S33>/EtherCAT Rx Var 17'
   *   '<S33>/EtherCAT Rx Var 18'
   *   '<S33>/EtherCAT Rx Var 19'
   *   '<S33>/EtherCAT Rx Var 2'
   *   '<S33>/EtherCAT Rx Var 3'
   *   '<S33>/EtherCAT Rx Var 4'
   *   '<S33>/EtherCAT Rx Var 5'
   *   '<S33>/EtherCAT Rx Var 6'
   *   '<S33>/EtherCAT Rx Var 7'
   *   '<S33>/EtherCAT Rx Var 8'
   *   '<S33>/EtherCAT Rx Var 9'
   *   '<S33>/EtherCAT Tx Var '
   *   '<S33>/EtherCAT Tx Var 1'
   *   '<S33>/EtherCAT Tx Var 2'
   *   '<S38>/EtherCAT Rx Var '
   *   '<S38>/EtherCAT Rx Var 1'
   *   '<S38>/EtherCAT Rx Var 10'
   *   '<S38>/EtherCAT Rx Var 11'
   *   '<S38>/EtherCAT Rx Var 12'
   *   '<S38>/EtherCAT Rx Var 13'
   *   '<S38>/EtherCAT Rx Var 14'
   *   '<S38>/EtherCAT Rx Var 15'
   *   '<S38>/EtherCAT Rx Var 16'
   *   '<S38>/EtherCAT Rx Var 17'
   *   '<S38>/EtherCAT Rx Var 18'
   *   '<S38>/EtherCAT Rx Var 19'
   *   '<S38>/EtherCAT Rx Var 2'
   *   '<S38>/EtherCAT Rx Var 20'
   *   '<S38>/EtherCAT Rx Var 21'
   *   '<S38>/EtherCAT Rx Var 22'
   *   '<S38>/EtherCAT Rx Var 23'
   *   '<S38>/EtherCAT Rx Var 3'
   *   '<S38>/EtherCAT Rx Var 4'
   *   '<S38>/EtherCAT Rx Var 5'
   *   '<S38>/EtherCAT Rx Var 6'
   *   '<S38>/EtherCAT Rx Var 7'
   *   '<S38>/EtherCAT Rx Var 8'
   *   '<S38>/EtherCAT Rx Var 9'
   *   '<S38>/EtherCAT Tx Var 3'
   *   '<S38>/EtherCAT Tx Var 4'
   *   '<S38>/EtherCAT Tx Var 5'
   *   '<S39>/EtherCAT Rx Var '
   *   '<S39>/EtherCAT Rx Var 1'
   *   '<S39>/EtherCAT Rx Var 10'
   *   '<S39>/EtherCAT Rx Var 11'
   *   '<S39>/EtherCAT Rx Var 12'
   *   '<S39>/EtherCAT Rx Var 13'
   *   '<S39>/EtherCAT Rx Var 14'
   *   '<S39>/EtherCAT Rx Var 15'
   *   '<S39>/EtherCAT Rx Var 16'
   *   '<S39>/EtherCAT Rx Var 17'
   *   '<S39>/EtherCAT Rx Var 18'
   *   '<S39>/EtherCAT Rx Var 19'
   *   '<S39>/EtherCAT Rx Var 2'
   *   '<S39>/EtherCAT Rx Var 20'
   *   '<S39>/EtherCAT Rx Var 21'
   *   '<S39>/EtherCAT Rx Var 22'
   *   '<S39>/EtherCAT Rx Var 23'
   *   '<S39>/EtherCAT Rx Var 3'
   *   '<S39>/EtherCAT Rx Var 4'
   *   '<S39>/EtherCAT Rx Var 5'
   *   '<S39>/EtherCAT Rx Var 6'
   *   '<S39>/EtherCAT Rx Var 7'
   *   '<S39>/EtherCAT Rx Var 8'
   *   '<S39>/EtherCAT Rx Var 9'
   *   '<S39>/EtherCAT Tx Var 3'
   *   '<S39>/EtherCAT Tx Var 4'
   *   '<S39>/EtherCAT Tx Var 5'
   *   '<S40>/EtherCAT Rx Var '
   *   '<S40>/EtherCAT Rx Var 1'
   *   '<S40>/EtherCAT Rx Var 10'
   *   '<S40>/EtherCAT Rx Var 11'
   *   '<S40>/EtherCAT Rx Var 12'
   *   '<S40>/EtherCAT Rx Var 13'
   *   '<S40>/EtherCAT Rx Var 14'
   *   '<S40>/EtherCAT Rx Var 15'
   *   '<S40>/EtherCAT Rx Var 16'
   *   '<S40>/EtherCAT Rx Var 17'
   *   '<S40>/EtherCAT Rx Var 18'
   *   '<S40>/EtherCAT Rx Var 19'
   *   '<S40>/EtherCAT Rx Var 2'
   *   '<S40>/EtherCAT Rx Var 20'
   *   '<S40>/EtherCAT Rx Var 21'
   *   '<S40>/EtherCAT Rx Var 22'
   *   '<S40>/EtherCAT Rx Var 23'
   *   '<S40>/EtherCAT Rx Var 3'
   *   '<S40>/EtherCAT Rx Var 4'
   *   '<S40>/EtherCAT Rx Var 5'
   *   '<S40>/EtherCAT Rx Var 6'
   *   '<S40>/EtherCAT Rx Var 7'
   *   '<S40>/EtherCAT Rx Var 8'
   *   '<S40>/EtherCAT Rx Var 9'
   *   '<S40>/EtherCAT Tx Var 3'
   *   '<S40>/EtherCAT Tx Var 4'
   *   '<S40>/EtherCAT Tx Var 5'
   *   '<S41>/EtherCAT Rx Var '
   *   '<S41>/EtherCAT Rx Var 1'
   *   '<S41>/EtherCAT Rx Var 10'
   *   '<S41>/EtherCAT Rx Var 11'
   *   '<S41>/EtherCAT Rx Var 12'
   *   '<S41>/EtherCAT Rx Var 13'
   *   '<S41>/EtherCAT Rx Var 14'
   *   '<S41>/EtherCAT Rx Var 15'
   *   '<S41>/EtherCAT Rx Var 16'
   *   '<S41>/EtherCAT Rx Var 17'
   *   '<S41>/EtherCAT Rx Var 18'
   *   '<S41>/EtherCAT Rx Var 19'
   *   '<S41>/EtherCAT Rx Var 2'
   *   '<S41>/EtherCAT Rx Var 20'
   *   '<S41>/EtherCAT Rx Var 21'
   *   '<S41>/EtherCAT Rx Var 22'
   *   '<S41>/EtherCAT Rx Var 23'
   *   '<S41>/EtherCAT Rx Var 3'
   *   '<S41>/EtherCAT Rx Var 4'
   *   '<S41>/EtherCAT Rx Var 5'
   *   '<S41>/EtherCAT Rx Var 6'
   *   '<S41>/EtherCAT Rx Var 7'
   *   '<S41>/EtherCAT Rx Var 8'
   *   '<S41>/EtherCAT Rx Var 9'
   *   '<S41>/EtherCAT Tx Var 3'
   *   '<S41>/EtherCAT Tx Var 4'
   *   '<S41>/EtherCAT Tx Var 5'
   *   '<S193>/Read HW FIFO'
   *   '<S193>/Setup3'
   *   '<S46>/EtherCAT PDO Receive'
   *   '<S46>/EtherCAT PDO Receive1'
   *   '<S46>/EtherCAT PDO Receive2'
   *   '<S46>/EtherCAT PDO Receive3'
   *   '<S46>/EtherCAT PDO Receive4'
   *   '<S46>/EtherCAT PDO Receive5'
   *   '<S46>/EtherCAT PDO Transmit'
   *   '<S46>/EtherCAT PDO Transmit1'
   *   '<S46>/EtherCAT PDO Transmit2'
   *   '<S64>/EtherCAT PDO Receive'
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S64>/EtherCAT PDO Receive2'
   *   '<S64>/EtherCAT PDO Receive3'
   *   '<S64>/EtherCAT PDO Receive4'
   *   '<S64>/EtherCAT PDO Receive5'
   *   '<S64>/EtherCAT PDO Transmit'
   *   '<S64>/EtherCAT PDO Transmit1'
   *   '<S64>/EtherCAT PDO Transmit2'
   *   '<S82>/EtherCAT PDO Receive'
   *   '<S82>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive2'
   *   '<S82>/EtherCAT PDO Receive3'
   *   '<S82>/EtherCAT PDO Receive4'
   *   '<S82>/EtherCAT PDO Receive5'
   *   '<S82>/EtherCAT PDO Transmit'
   *   '<S82>/EtherCAT PDO Transmit1'
   *   '<S82>/EtherCAT PDO Transmit2'
   *   '<S100>/EtherCAT PDO Receive'
   *   '<S100>/EtherCAT PDO Receive1'
   *   '<S100>/EtherCAT PDO Receive2'
   *   '<S100>/EtherCAT PDO Receive3'
   *   '<S100>/EtherCAT PDO Receive4'
   *   '<S100>/EtherCAT PDO Receive5'
   *   '<S100>/EtherCAT PDO Transmit'
   *   '<S100>/EtherCAT PDO Transmit1'
   *   '<S100>/EtherCAT PDO Transmit2'
   */
  real_T pooled34;

  /* Computed Parameter: Setup3_P15_Size
   * Referenced by: '<S193>/Setup3'
   */
  real_T Setup3_P15_Size[2];

  /* Expression: xon
   * Referenced by: '<S193>/Setup3'
   */
  real_T Setup3_P15;

  /* Computed Parameter: Setup3_P16_Size
   * Referenced by: '<S193>/Setup3'
   */
  real_T Setup3_P16_Size[2];

  /* Expression: xoff
   * Referenced by: '<S193>/Setup3'
   */
  real_T Setup3_P16;

  /* Computed Parameter: FIFOwrite1_P1_Size
   * Referenced by: '<S193>/FIFO write 1'
   */
  real_T FIFOwrite1_P1_Size[2];

  /* Expression: size
   * Referenced by: '<S193>/FIFO write 1'
   */
  real_T FIFOwrite1_P1;

  /* Computed Parameter: FIFOwrite1_P5_Size
   * Referenced by: '<S193>/FIFO write 1'
   */
  real_T FIFOwrite1_P5_Size[2];

  /* Computed Parameter: FIFOwrite1_P5
   * Referenced by: '<S193>/FIFO write 1'
   */
  real_T FIFOwrite1_P5[20];

  /* Expression: Calibration.KVHOrientation
   * Referenced by: '<S124>/KVHOrientation'
   */
  real_T KVHOrientation_Value[9];

  /* Computed Parameter: EtherCATRxVar4_P1_Siz
   * Referenced by: '<S39>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar4_P1
   * Referenced by: '<S39>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1[60];

  /* Computed Parameter: EtherCATRxVar4_P2_Siz
   * Referenced by: '<S39>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 15'
   *   '<S31>/EtherCAT Rx Var 16'
   *   '<S31>/EtherCAT Rx Var 17'
   *   '<S31>/EtherCAT Rx Var 18'
   *   '<S31>/EtherCAT Rx Var 19'
   *   '<S31>/EtherCAT Rx Var 4'
   *   '<S31>/EtherCAT Tx Var 3'
   *   '<S32>/EtherCAT Rx Var 15'
   *   '<S32>/EtherCAT Rx Var 16'
   *   '<S32>/EtherCAT Rx Var 17'
   *   '<S32>/EtherCAT Rx Var 18'
   *   '<S32>/EtherCAT Rx Var 19'
   *   '<S32>/EtherCAT Rx Var 4'
   *   '<S32>/EtherCAT Tx Var 3'
   *   '<S33>/EtherCAT Rx Var 1'
   *   '<S33>/EtherCAT Rx Var 10'
   *   '<S33>/EtherCAT Rx Var 11'
   *   '<S33>/EtherCAT Rx Var 12'
   *   '<S33>/EtherCAT Rx Var 13'
   *   '<S33>/EtherCAT Rx Var 14'
   *   '<S33>/EtherCAT Rx Var 15'
   *   '<S33>/EtherCAT Rx Var 16'
   *   '<S33>/EtherCAT Rx Var 17'
   *   '<S33>/EtherCAT Rx Var 18'
   *   '<S33>/EtherCAT Rx Var 19'
   *   '<S33>/EtherCAT Rx Var 2'
   *   '<S33>/EtherCAT Rx Var 3'
   *   '<S33>/EtherCAT Rx Var 4'
   *   '<S33>/EtherCAT Rx Var 5'
   *   '<S33>/EtherCAT Rx Var 6'
   *   '<S33>/EtherCAT Rx Var 7'
   *   '<S33>/EtherCAT Rx Var 8'
   *   '<S33>/EtherCAT Rx Var 9'
   *   '<S33>/EtherCAT Tx Var '
   *   '<S38>/EtherCAT Rx Var 18'
   *   '<S38>/EtherCAT Rx Var 19'
   *   '<S38>/EtherCAT Rx Var 20'
   *   '<S38>/EtherCAT Rx Var 21'
   *   '<S38>/EtherCAT Rx Var 22'
   *   '<S38>/EtherCAT Rx Var 4'
   *   '<S38>/EtherCAT Rx Var 8'
   *   '<S38>/EtherCAT Tx Var 3'
   *   '<S39>/EtherCAT Rx Var 18'
   *   '<S39>/EtherCAT Rx Var 19'
   *   '<S39>/EtherCAT Rx Var 20'
   *   '<S39>/EtherCAT Rx Var 21'
   *   '<S39>/EtherCAT Rx Var 22'
   *   '<S39>/EtherCAT Rx Var 4'
   *   '<S39>/EtherCAT Rx Var 8'
   *   '<S39>/EtherCAT Tx Var 3'
   *   '<S40>/EtherCAT Rx Var 18'
   *   '<S40>/EtherCAT Rx Var 19'
   *   '<S40>/EtherCAT Rx Var 20'
   *   '<S40>/EtherCAT Rx Var 21'
   *   '<S40>/EtherCAT Rx Var 22'
   *   '<S40>/EtherCAT Rx Var 4'
   *   '<S40>/EtherCAT Rx Var 8'
   *   '<S40>/EtherCAT Tx Var 3'
   *   '<S41>/EtherCAT Rx Var 18'
   *   '<S41>/EtherCAT Rx Var 19'
   *   '<S41>/EtherCAT Rx Var 20'
   *   '<S41>/EtherCAT Rx Var 21'
   *   '<S41>/EtherCAT Rx Var 22'
   *   '<S41>/EtherCAT Rx Var 4'
   *   '<S41>/EtherCAT Rx Var 8'
   *   '<S41>/EtherCAT Tx Var 3'
   *   '<S46>/EtherCAT PDO Receive2'
   *   '<S46>/EtherCAT PDO Transmit2'
   *   '<S64>/EtherCAT PDO Receive2'
   *   '<S64>/EtherCAT PDO Transmit2'
   *   '<S82>/EtherCAT PDO Receive2'
   *   '<S82>/EtherCAT PDO Transmit2'
   *   '<S100>/EtherCAT PDO Receive2'
   *   '<S100>/EtherCAT PDO Transmit2'
   */
  real_T pooled35[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 15'
   *   '<S31>/EtherCAT Rx Var 16'
   *   '<S31>/EtherCAT Rx Var 17'
   *   '<S31>/EtherCAT Rx Var 18'
   *   '<S31>/EtherCAT Rx Var 19'
   *   '<S31>/EtherCAT Rx Var 4'
   *   '<S31>/EtherCAT Tx Var 3'
   *   '<S32>/EtherCAT Rx Var 15'
   *   '<S32>/EtherCAT Rx Var 16'
   *   '<S32>/EtherCAT Rx Var 17'
   *   '<S32>/EtherCAT Rx Var 18'
   *   '<S32>/EtherCAT Rx Var 19'
   *   '<S32>/EtherCAT Rx Var 4'
   *   '<S32>/EtherCAT Tx Var 3'
   *   '<S33>/EtherCAT Rx Var 1'
   *   '<S33>/EtherCAT Rx Var 10'
   *   '<S33>/EtherCAT Rx Var 11'
   *   '<S33>/EtherCAT Rx Var 12'
   *   '<S33>/EtherCAT Rx Var 13'
   *   '<S33>/EtherCAT Rx Var 14'
   *   '<S33>/EtherCAT Rx Var 15'
   *   '<S33>/EtherCAT Rx Var 16'
   *   '<S33>/EtherCAT Rx Var 17'
   *   '<S33>/EtherCAT Rx Var 18'
   *   '<S33>/EtherCAT Rx Var 19'
   *   '<S33>/EtherCAT Rx Var 2'
   *   '<S33>/EtherCAT Rx Var 3'
   *   '<S33>/EtherCAT Rx Var 4'
   *   '<S33>/EtherCAT Rx Var 5'
   *   '<S33>/EtherCAT Rx Var 6'
   *   '<S33>/EtherCAT Rx Var 7'
   *   '<S33>/EtherCAT Rx Var 8'
   *   '<S33>/EtherCAT Rx Var 9'
   *   '<S33>/EtherCAT Tx Var '
   *   '<S38>/EtherCAT Rx Var 18'
   *   '<S38>/EtherCAT Rx Var 19'
   *   '<S38>/EtherCAT Rx Var 20'
   *   '<S38>/EtherCAT Rx Var 21'
   *   '<S38>/EtherCAT Rx Var 22'
   *   '<S38>/EtherCAT Rx Var 4'
   *   '<S38>/EtherCAT Rx Var 8'
   *   '<S38>/EtherCAT Tx Var 3'
   *   '<S39>/EtherCAT Rx Var 18'
   *   '<S39>/EtherCAT Rx Var 19'
   *   '<S39>/EtherCAT Rx Var 20'
   *   '<S39>/EtherCAT Rx Var 21'
   *   '<S39>/EtherCAT Rx Var 22'
   *   '<S39>/EtherCAT Rx Var 4'
   *   '<S39>/EtherCAT Rx Var 8'
   *   '<S39>/EtherCAT Tx Var 3'
   *   '<S40>/EtherCAT Rx Var 18'
   *   '<S40>/EtherCAT Rx Var 19'
   *   '<S40>/EtherCAT Rx Var 20'
   *   '<S40>/EtherCAT Rx Var 21'
   *   '<S40>/EtherCAT Rx Var 22'
   *   '<S40>/EtherCAT Rx Var 4'
   *   '<S40>/EtherCAT Rx Var 8'
   *   '<S40>/EtherCAT Tx Var 3'
   *   '<S41>/EtherCAT Rx Var 18'
   *   '<S41>/EtherCAT Rx Var 19'
   *   '<S41>/EtherCAT Rx Var 20'
   *   '<S41>/EtherCAT Rx Var 21'
   *   '<S41>/EtherCAT Rx Var 22'
   *   '<S41>/EtherCAT Rx Var 4'
   *   '<S41>/EtherCAT Rx Var 8'
   *   '<S41>/EtherCAT Tx Var 3'
   *   '<S46>/EtherCAT PDO Receive2'
   *   '<S46>/EtherCAT PDO Transmit2'
   *   '<S64>/EtherCAT PDO Receive2'
   *   '<S64>/EtherCAT PDO Transmit2'
   *   '<S82>/EtherCAT PDO Receive2'
   *   '<S82>/EtherCAT PDO Transmit2'
   *   '<S100>/EtherCAT PDO Receive2'
   *   '<S100>/EtherCAT PDO Transmit2'
   */
  real_T pooled36;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 4'
   *   '<S31>/EtherCAT Tx Var 5'
   *   '<S32>/EtherCAT Rx Var 4'
   *   '<S32>/EtherCAT Tx Var 5'
   *   '<S33>/EtherCAT Rx Var 1'
   *   '<S33>/EtherCAT Rx Var 10'
   *   '<S33>/EtherCAT Rx Var 11'
   *   '<S33>/EtherCAT Rx Var 12'
   *   '<S33>/EtherCAT Rx Var 13'
   *   '<S33>/EtherCAT Rx Var 14'
   *   '<S33>/EtherCAT Rx Var 19'
   *   '<S33>/EtherCAT Rx Var 2'
   *   '<S33>/EtherCAT Rx Var 3'
   *   '<S33>/EtherCAT Rx Var 4'
   *   '<S33>/EtherCAT Rx Var 5'
   *   '<S33>/EtherCAT Rx Var 6'
   *   '<S33>/EtherCAT Rx Var 7'
   *   '<S33>/EtherCAT Rx Var 8'
   *   '<S33>/EtherCAT Rx Var 9'
   *   '<S38>/EtherCAT Rx Var 4'
   *   '<S38>/EtherCAT Rx Var 8'
   *   '<S38>/EtherCAT Tx Var 5'
   *   '<S39>/EtherCAT Rx Var 4'
   *   '<S39>/EtherCAT Rx Var 8'
   *   '<S39>/EtherCAT Tx Var 5'
   *   '<S40>/EtherCAT Rx Var 4'
   *   '<S40>/EtherCAT Rx Var 8'
   *   '<S40>/EtherCAT Tx Var 5'
   *   '<S41>/EtherCAT Rx Var 4'
   *   '<S41>/EtherCAT Rx Var 8'
   *   '<S41>/EtherCAT Tx Var 5'
   *   '<S46>/EtherCAT PDO Receive1'
   *   '<S46>/EtherCAT PDO Receive4'
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S64>/EtherCAT PDO Receive4'
   *   '<S82>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive4'
   *   '<S100>/EtherCAT PDO Receive1'
   *   '<S100>/EtherCAT PDO Receive4'
   */
  real_T pooled37[2];

  /* Pooled Parameter (Expression: type_size)
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 4'
   *   '<S31>/EtherCAT Tx Var 5'
   *   '<S32>/EtherCAT Rx Var 4'
   *   '<S32>/EtherCAT Tx Var 5'
   *   '<S33>/EtherCAT Rx Var 1'
   *   '<S33>/EtherCAT Rx Var 10'
   *   '<S33>/EtherCAT Rx Var 11'
   *   '<S33>/EtherCAT Rx Var 12'
   *   '<S33>/EtherCAT Rx Var 13'
   *   '<S33>/EtherCAT Rx Var 14'
   *   '<S33>/EtherCAT Rx Var 19'
   *   '<S33>/EtherCAT Rx Var 2'
   *   '<S33>/EtherCAT Rx Var 3'
   *   '<S33>/EtherCAT Rx Var 4'
   *   '<S33>/EtherCAT Rx Var 5'
   *   '<S33>/EtherCAT Rx Var 6'
   *   '<S33>/EtherCAT Rx Var 7'
   *   '<S33>/EtherCAT Rx Var 8'
   *   '<S33>/EtherCAT Rx Var 9'
   *   '<S38>/EtherCAT Rx Var 4'
   *   '<S38>/EtherCAT Rx Var 8'
   *   '<S38>/EtherCAT Tx Var 5'
   *   '<S39>/EtherCAT Rx Var 4'
   *   '<S39>/EtherCAT Rx Var 8'
   *   '<S39>/EtherCAT Tx Var 5'
   *   '<S40>/EtherCAT Rx Var 4'
   *   '<S40>/EtherCAT Rx Var 8'
   *   '<S40>/EtherCAT Tx Var 5'
   *   '<S41>/EtherCAT Rx Var 4'
   *   '<S41>/EtherCAT Rx Var 8'
   *   '<S41>/EtherCAT Tx Var 5'
   *   '<S46>/EtherCAT PDO Receive1'
   *   '<S46>/EtherCAT PDO Receive4'
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S64>/EtherCAT PDO Receive4'
   *   '<S82>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive4'
   *   '<S100>/EtherCAT PDO Receive1'
   *   '<S100>/EtherCAT PDO Receive4'
   */
  real_T pooled38;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S1>/Get Overload Counter '
   *   '<S4>/Task Execution Time '
   *   '<S31>/EtherCAT Rx Var '
   *   '<S31>/EtherCAT Rx Var 1'
   *   '<S31>/EtherCAT Rx Var 12'
   *   '<S31>/EtherCAT Rx Var 13'
   *   '<S31>/EtherCAT Rx Var 14'
   *   '<S31>/EtherCAT Rx Var 15'
   *   '<S31>/EtherCAT Rx Var 16'
   *   '<S31>/EtherCAT Rx Var 17'
   *   '<S31>/EtherCAT Rx Var 18'
   *   '<S31>/EtherCAT Rx Var 19'
   *   '<S31>/EtherCAT Rx Var 2'
   *   '<S31>/EtherCAT Rx Var 3'
   *   '<S31>/EtherCAT Rx Var 4'
   *   '<S31>/EtherCAT Rx Var 5'
   *   '<S31>/EtherCAT Rx Var 6'
   *   '<S31>/EtherCAT Tx Var 3'
   *   '<S31>/EtherCAT Tx Var 4'
   *   '<S31>/EtherCAT Tx Var 5'
   *   '<S32>/EtherCAT Rx Var '
   *   '<S32>/EtherCAT Rx Var 1'
   *   '<S32>/EtherCAT Rx Var 12'
   *   '<S32>/EtherCAT Rx Var 13'
   *   '<S32>/EtherCAT Rx Var 14'
   *   '<S32>/EtherCAT Rx Var 15'
   *   '<S32>/EtherCAT Rx Var 16'
   *   '<S32>/EtherCAT Rx Var 17'
   *   '<S32>/EtherCAT Rx Var 18'
   *   '<S32>/EtherCAT Rx Var 19'
   *   '<S32>/EtherCAT Rx Var 2'
   *   '<S32>/EtherCAT Rx Var 3'
   *   '<S32>/EtherCAT Rx Var 4'
   *   '<S32>/EtherCAT Rx Var 5'
   *   '<S32>/EtherCAT Rx Var 6'
   *   '<S32>/EtherCAT Tx Var 3'
   *   '<S32>/EtherCAT Tx Var 4'
   *   '<S32>/EtherCAT Tx Var 5'
   *   '<S33>/EtherCAT Rx Var 1'
   *   '<S33>/EtherCAT Rx Var 10'
   *   '<S33>/EtherCAT Rx Var 11'
   *   '<S33>/EtherCAT Rx Var 12'
   *   '<S33>/EtherCAT Rx Var 13'
   *   '<S33>/EtherCAT Rx Var 14'
   *   '<S33>/EtherCAT Rx Var 15'
   *   '<S33>/EtherCAT Rx Var 16'
   *   '<S33>/EtherCAT Rx Var 17'
   *   '<S33>/EtherCAT Rx Var 18'
   *   '<S33>/EtherCAT Rx Var 19'
   *   '<S33>/EtherCAT Rx Var 2'
   *   '<S33>/EtherCAT Rx Var 3'
   *   '<S33>/EtherCAT Rx Var 4'
   *   '<S33>/EtherCAT Rx Var 5'
   *   '<S33>/EtherCAT Rx Var 6'
   *   '<S33>/EtherCAT Rx Var 7'
   *   '<S33>/EtherCAT Rx Var 8'
   *   '<S33>/EtherCAT Rx Var 9'
   *   '<S33>/EtherCAT Tx Var '
   *   '<S33>/EtherCAT Tx Var 1'
   *   '<S33>/EtherCAT Tx Var 2'
   *   '<S38>/EtherCAT Rx Var '
   *   '<S38>/EtherCAT Rx Var 1'
   *   '<S38>/EtherCAT Rx Var 10'
   *   '<S38>/EtherCAT Rx Var 11'
   *   '<S38>/EtherCAT Rx Var 12'
   *   '<S38>/EtherCAT Rx Var 13'
   *   '<S38>/EtherCAT Rx Var 14'
   *   '<S38>/EtherCAT Rx Var 15'
   *   '<S38>/EtherCAT Rx Var 16'
   *   '<S38>/EtherCAT Rx Var 17'
   *   '<S38>/EtherCAT Rx Var 18'
   *   '<S38>/EtherCAT Rx Var 19'
   *   '<S38>/EtherCAT Rx Var 2'
   *   '<S38>/EtherCAT Rx Var 20'
   *   '<S38>/EtherCAT Rx Var 21'
   *   '<S38>/EtherCAT Rx Var 22'
   *   '<S38>/EtherCAT Rx Var 23'
   *   '<S38>/EtherCAT Rx Var 3'
   *   '<S38>/EtherCAT Rx Var 4'
   *   '<S38>/EtherCAT Rx Var 5'
   *   '<S38>/EtherCAT Rx Var 6'
   *   '<S38>/EtherCAT Rx Var 7'
   *   '<S38>/EtherCAT Rx Var 8'
   *   '<S38>/EtherCAT Rx Var 9'
   *   '<S38>/EtherCAT Tx Var 3'
   *   '<S38>/EtherCAT Tx Var 4'
   *   '<S38>/EtherCAT Tx Var 5'
   *   '<S39>/EtherCAT Rx Var '
   *   '<S39>/EtherCAT Rx Var 1'
   *   '<S39>/EtherCAT Rx Var 10'
   *   '<S39>/EtherCAT Rx Var 11'
   *   '<S39>/EtherCAT Rx Var 12'
   *   '<S39>/EtherCAT Rx Var 13'
   *   '<S39>/EtherCAT Rx Var 14'
   *   '<S39>/EtherCAT Rx Var 15'
   *   '<S39>/EtherCAT Rx Var 16'
   *   '<S39>/EtherCAT Rx Var 17'
   *   '<S39>/EtherCAT Rx Var 18'
   *   '<S39>/EtherCAT Rx Var 19'
   *   '<S39>/EtherCAT Rx Var 2'
   *   '<S39>/EtherCAT Rx Var 20'
   *   '<S39>/EtherCAT Rx Var 21'
   *   '<S39>/EtherCAT Rx Var 22'
   *   '<S39>/EtherCAT Rx Var 23'
   *   '<S39>/EtherCAT Rx Var 3'
   *   '<S39>/EtherCAT Rx Var 4'
   *   '<S39>/EtherCAT Rx Var 5'
   *   '<S39>/EtherCAT Rx Var 6'
   *   '<S39>/EtherCAT Rx Var 7'
   *   '<S39>/EtherCAT Rx Var 8'
   *   '<S39>/EtherCAT Rx Var 9'
   *   '<S39>/EtherCAT Tx Var 3'
   *   '<S39>/EtherCAT Tx Var 4'
   *   '<S39>/EtherCAT Tx Var 5'
   *   '<S40>/EtherCAT Rx Var '
   *   '<S40>/EtherCAT Rx Var 1'
   *   '<S40>/EtherCAT Rx Var 10'
   *   '<S40>/EtherCAT Rx Var 11'
   *   '<S40>/EtherCAT Rx Var 12'
   *   '<S40>/EtherCAT Rx Var 13'
   *   '<S40>/EtherCAT Rx Var 14'
   *   '<S40>/EtherCAT Rx Var 15'
   *   '<S40>/EtherCAT Rx Var 16'
   *   '<S40>/EtherCAT Rx Var 17'
   *   '<S40>/EtherCAT Rx Var 18'
   *   '<S40>/EtherCAT Rx Var 19'
   *   '<S40>/EtherCAT Rx Var 2'
   *   '<S40>/EtherCAT Rx Var 20'
   *   '<S40>/EtherCAT Rx Var 21'
   *   '<S40>/EtherCAT Rx Var 22'
   *   '<S40>/EtherCAT Rx Var 23'
   *   '<S40>/EtherCAT Rx Var 3'
   *   '<S40>/EtherCAT Rx Var 4'
   *   '<S40>/EtherCAT Rx Var 5'
   *   '<S40>/EtherCAT Rx Var 6'
   *   '<S40>/EtherCAT Rx Var 7'
   *   '<S40>/EtherCAT Rx Var 8'
   *   '<S40>/EtherCAT Rx Var 9'
   *   '<S40>/EtherCAT Tx Var 3'
   *   '<S40>/EtherCAT Tx Var 4'
   *   '<S40>/EtherCAT Tx Var 5'
   *   '<S41>/EtherCAT Rx Var '
   *   '<S41>/EtherCAT Rx Var 1'
   *   '<S41>/EtherCAT Rx Var 10'
   *   '<S41>/EtherCAT Rx Var 11'
   *   '<S41>/EtherCAT Rx Var 12'
   *   '<S41>/EtherCAT Rx Var 13'
   *   '<S41>/EtherCAT Rx Var 14'
   *   '<S41>/EtherCAT Rx Var 15'
   *   '<S41>/EtherCAT Rx Var 16'
   *   '<S41>/EtherCAT Rx Var 17'
   *   '<S41>/EtherCAT Rx Var 18'
   *   '<S41>/EtherCAT Rx Var 19'
   *   '<S41>/EtherCAT Rx Var 2'
   *   '<S41>/EtherCAT Rx Var 20'
   *   '<S41>/EtherCAT Rx Var 21'
   *   '<S41>/EtherCAT Rx Var 22'
   *   '<S41>/EtherCAT Rx Var 23'
   *   '<S41>/EtherCAT Rx Var 3'
   *   '<S41>/EtherCAT Rx Var 4'
   *   '<S41>/EtherCAT Rx Var 5'
   *   '<S41>/EtherCAT Rx Var 6'
   *   '<S41>/EtherCAT Rx Var 7'
   *   '<S41>/EtherCAT Rx Var 8'
   *   '<S41>/EtherCAT Rx Var 9'
   *   '<S41>/EtherCAT Tx Var 3'
   *   '<S41>/EtherCAT Tx Var 4'
   *   '<S41>/EtherCAT Tx Var 5'
   *   '<S46>/EtherCAT PDO Receive'
   *   '<S46>/EtherCAT PDO Receive1'
   *   '<S46>/EtherCAT PDO Receive2'
   *   '<S46>/EtherCAT PDO Receive3'
   *   '<S46>/EtherCAT PDO Receive4'
   *   '<S46>/EtherCAT PDO Receive5'
   *   '<S46>/EtherCAT PDO Transmit'
   *   '<S46>/EtherCAT PDO Transmit1'
   *   '<S46>/EtherCAT PDO Transmit2'
   *   '<S64>/EtherCAT PDO Receive'
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S64>/EtherCAT PDO Receive2'
   *   '<S64>/EtherCAT PDO Receive3'
   *   '<S64>/EtherCAT PDO Receive4'
   *   '<S64>/EtherCAT PDO Receive5'
   *   '<S64>/EtherCAT PDO Transmit'
   *   '<S64>/EtherCAT PDO Transmit1'
   *   '<S64>/EtherCAT PDO Transmit2'
   *   '<S82>/EtherCAT PDO Receive'
   *   '<S82>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive2'
   *   '<S82>/EtherCAT PDO Receive3'
   *   '<S82>/EtherCAT PDO Receive4'
   *   '<S82>/EtherCAT PDO Receive5'
   *   '<S82>/EtherCAT PDO Transmit'
   *   '<S82>/EtherCAT PDO Transmit1'
   *   '<S82>/EtherCAT PDO Transmit2'
   *   '<S100>/EtherCAT PDO Receive'
   *   '<S100>/EtherCAT PDO Receive1'
   *   '<S100>/EtherCAT PDO Receive2'
   *   '<S100>/EtherCAT PDO Receive3'
   *   '<S100>/EtherCAT PDO Receive4'
   *   '<S100>/EtherCAT PDO Receive5'
   *   '<S100>/EtherCAT PDO Transmit'
   *   '<S100>/EtherCAT PDO Transmit1'
   *   '<S100>/EtherCAT PDO Transmit2'
   */
  real_T pooled39[2];

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S1>/Get Overload Counter '
   *   '<S4>/Task Execution Time '
   *   '<S31>/EtherCAT Rx Var '
   *   '<S31>/EtherCAT Rx Var 1'
   *   '<S31>/EtherCAT Rx Var 12'
   *   '<S31>/EtherCAT Rx Var 13'
   *   '<S31>/EtherCAT Rx Var 14'
   *   '<S31>/EtherCAT Rx Var 15'
   *   '<S31>/EtherCAT Rx Var 16'
   *   '<S31>/EtherCAT Rx Var 17'
   *   '<S31>/EtherCAT Rx Var 18'
   *   '<S31>/EtherCAT Rx Var 19'
   *   '<S31>/EtherCAT Rx Var 2'
   *   '<S31>/EtherCAT Rx Var 3'
   *   '<S31>/EtherCAT Rx Var 4'
   *   '<S31>/EtherCAT Rx Var 5'
   *   '<S31>/EtherCAT Rx Var 6'
   *   '<S31>/EtherCAT Tx Var 3'
   *   '<S31>/EtherCAT Tx Var 4'
   *   '<S31>/EtherCAT Tx Var 5'
   *   '<S32>/EtherCAT Rx Var '
   *   '<S32>/EtherCAT Rx Var 1'
   *   '<S32>/EtherCAT Rx Var 12'
   *   '<S32>/EtherCAT Rx Var 13'
   *   '<S32>/EtherCAT Rx Var 14'
   *   '<S32>/EtherCAT Rx Var 15'
   *   '<S32>/EtherCAT Rx Var 16'
   *   '<S32>/EtherCAT Rx Var 17'
   *   '<S32>/EtherCAT Rx Var 18'
   *   '<S32>/EtherCAT Rx Var 19'
   *   '<S32>/EtherCAT Rx Var 2'
   *   '<S32>/EtherCAT Rx Var 3'
   *   '<S32>/EtherCAT Rx Var 4'
   *   '<S32>/EtherCAT Rx Var 5'
   *   '<S32>/EtherCAT Rx Var 6'
   *   '<S32>/EtherCAT Tx Var 3'
   *   '<S32>/EtherCAT Tx Var 4'
   *   '<S32>/EtherCAT Tx Var 5'
   *   '<S33>/EtherCAT Rx Var 1'
   *   '<S33>/EtherCAT Rx Var 10'
   *   '<S33>/EtherCAT Rx Var 11'
   *   '<S33>/EtherCAT Rx Var 12'
   *   '<S33>/EtherCAT Rx Var 13'
   *   '<S33>/EtherCAT Rx Var 14'
   *   '<S33>/EtherCAT Rx Var 15'
   *   '<S33>/EtherCAT Rx Var 16'
   *   '<S33>/EtherCAT Rx Var 17'
   *   '<S33>/EtherCAT Rx Var 18'
   *   '<S33>/EtherCAT Rx Var 19'
   *   '<S33>/EtherCAT Rx Var 2'
   *   '<S33>/EtherCAT Rx Var 3'
   *   '<S33>/EtherCAT Rx Var 4'
   *   '<S33>/EtherCAT Rx Var 5'
   *   '<S33>/EtherCAT Rx Var 6'
   *   '<S33>/EtherCAT Rx Var 7'
   *   '<S33>/EtherCAT Rx Var 8'
   *   '<S33>/EtherCAT Rx Var 9'
   *   '<S33>/EtherCAT Tx Var '
   *   '<S33>/EtherCAT Tx Var 1'
   *   '<S33>/EtherCAT Tx Var 2'
   *   '<S38>/EtherCAT Rx Var '
   *   '<S38>/EtherCAT Rx Var 1'
   *   '<S38>/EtherCAT Rx Var 10'
   *   '<S38>/EtherCAT Rx Var 11'
   *   '<S38>/EtherCAT Rx Var 12'
   *   '<S38>/EtherCAT Rx Var 13'
   *   '<S38>/EtherCAT Rx Var 14'
   *   '<S38>/EtherCAT Rx Var 15'
   *   '<S38>/EtherCAT Rx Var 16'
   *   '<S38>/EtherCAT Rx Var 17'
   *   '<S38>/EtherCAT Rx Var 18'
   *   '<S38>/EtherCAT Rx Var 19'
   *   '<S38>/EtherCAT Rx Var 2'
   *   '<S38>/EtherCAT Rx Var 20'
   *   '<S38>/EtherCAT Rx Var 21'
   *   '<S38>/EtherCAT Rx Var 22'
   *   '<S38>/EtherCAT Rx Var 23'
   *   '<S38>/EtherCAT Rx Var 3'
   *   '<S38>/EtherCAT Rx Var 4'
   *   '<S38>/EtherCAT Rx Var 5'
   *   '<S38>/EtherCAT Rx Var 6'
   *   '<S38>/EtherCAT Rx Var 7'
   *   '<S38>/EtherCAT Rx Var 8'
   *   '<S38>/EtherCAT Rx Var 9'
   *   '<S38>/EtherCAT Tx Var 3'
   *   '<S38>/EtherCAT Tx Var 4'
   *   '<S38>/EtherCAT Tx Var 5'
   *   '<S39>/EtherCAT Rx Var '
   *   '<S39>/EtherCAT Rx Var 1'
   *   '<S39>/EtherCAT Rx Var 10'
   *   '<S39>/EtherCAT Rx Var 11'
   *   '<S39>/EtherCAT Rx Var 12'
   *   '<S39>/EtherCAT Rx Var 13'
   *   '<S39>/EtherCAT Rx Var 14'
   *   '<S39>/EtherCAT Rx Var 15'
   *   '<S39>/EtherCAT Rx Var 16'
   *   '<S39>/EtherCAT Rx Var 17'
   *   '<S39>/EtherCAT Rx Var 18'
   *   '<S39>/EtherCAT Rx Var 19'
   *   '<S39>/EtherCAT Rx Var 2'
   *   '<S39>/EtherCAT Rx Var 20'
   *   '<S39>/EtherCAT Rx Var 21'
   *   '<S39>/EtherCAT Rx Var 22'
   *   '<S39>/EtherCAT Rx Var 23'
   *   '<S39>/EtherCAT Rx Var 3'
   *   '<S39>/EtherCAT Rx Var 4'
   *   '<S39>/EtherCAT Rx Var 5'
   *   '<S39>/EtherCAT Rx Var 6'
   *   '<S39>/EtherCAT Rx Var 7'
   *   '<S39>/EtherCAT Rx Var 8'
   *   '<S39>/EtherCAT Rx Var 9'
   *   '<S39>/EtherCAT Tx Var 3'
   *   '<S39>/EtherCAT Tx Var 4'
   *   '<S39>/EtherCAT Tx Var 5'
   *   '<S40>/EtherCAT Rx Var '
   *   '<S40>/EtherCAT Rx Var 1'
   *   '<S40>/EtherCAT Rx Var 10'
   *   '<S40>/EtherCAT Rx Var 11'
   *   '<S40>/EtherCAT Rx Var 12'
   *   '<S40>/EtherCAT Rx Var 13'
   *   '<S40>/EtherCAT Rx Var 14'
   *   '<S40>/EtherCAT Rx Var 15'
   *   '<S40>/EtherCAT Rx Var 16'
   *   '<S40>/EtherCAT Rx Var 17'
   *   '<S40>/EtherCAT Rx Var 18'
   *   '<S40>/EtherCAT Rx Var 19'
   *   '<S40>/EtherCAT Rx Var 2'
   *   '<S40>/EtherCAT Rx Var 20'
   *   '<S40>/EtherCAT Rx Var 21'
   *   '<S40>/EtherCAT Rx Var 22'
   *   '<S40>/EtherCAT Rx Var 23'
   *   '<S40>/EtherCAT Rx Var 3'
   *   '<S40>/EtherCAT Rx Var 4'
   *   '<S40>/EtherCAT Rx Var 5'
   *   '<S40>/EtherCAT Rx Var 6'
   *   '<S40>/EtherCAT Rx Var 7'
   *   '<S40>/EtherCAT Rx Var 8'
   *   '<S40>/EtherCAT Rx Var 9'
   *   '<S40>/EtherCAT Tx Var 3'
   *   '<S40>/EtherCAT Tx Var 4'
   *   '<S40>/EtherCAT Tx Var 5'
   *   '<S41>/EtherCAT Rx Var '
   *   '<S41>/EtherCAT Rx Var 1'
   *   '<S41>/EtherCAT Rx Var 10'
   *   '<S41>/EtherCAT Rx Var 11'
   *   '<S41>/EtherCAT Rx Var 12'
   *   '<S41>/EtherCAT Rx Var 13'
   *   '<S41>/EtherCAT Rx Var 14'
   *   '<S41>/EtherCAT Rx Var 15'
   *   '<S41>/EtherCAT Rx Var 16'
   *   '<S41>/EtherCAT Rx Var 17'
   *   '<S41>/EtherCAT Rx Var 18'
   *   '<S41>/EtherCAT Rx Var 19'
   *   '<S41>/EtherCAT Rx Var 2'
   *   '<S41>/EtherCAT Rx Var 20'
   *   '<S41>/EtherCAT Rx Var 21'
   *   '<S41>/EtherCAT Rx Var 22'
   *   '<S41>/EtherCAT Rx Var 23'
   *   '<S41>/EtherCAT Rx Var 3'
   *   '<S41>/EtherCAT Rx Var 4'
   *   '<S41>/EtherCAT Rx Var 5'
   *   '<S41>/EtherCAT Rx Var 6'
   *   '<S41>/EtherCAT Rx Var 7'
   *   '<S41>/EtherCAT Rx Var 8'
   *   '<S41>/EtherCAT Rx Var 9'
   *   '<S41>/EtherCAT Tx Var 3'
   *   '<S41>/EtherCAT Tx Var 4'
   *   '<S41>/EtherCAT Tx Var 5'
   *   '<S46>/EtherCAT PDO Receive'
   *   '<S46>/EtherCAT PDO Receive1'
   *   '<S46>/EtherCAT PDO Receive2'
   *   '<S46>/EtherCAT PDO Receive3'
   *   '<S46>/EtherCAT PDO Receive4'
   *   '<S46>/EtherCAT PDO Receive5'
   *   '<S46>/EtherCAT PDO Transmit'
   *   '<S46>/EtherCAT PDO Transmit1'
   *   '<S46>/EtherCAT PDO Transmit2'
   *   '<S64>/EtherCAT PDO Receive'
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S64>/EtherCAT PDO Receive2'
   *   '<S64>/EtherCAT PDO Receive3'
   *   '<S64>/EtherCAT PDO Receive4'
   *   '<S64>/EtherCAT PDO Receive5'
   *   '<S64>/EtherCAT PDO Transmit'
   *   '<S64>/EtherCAT PDO Transmit1'
   *   '<S64>/EtherCAT PDO Transmit2'
   *   '<S82>/EtherCAT PDO Receive'
   *   '<S82>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive2'
   *   '<S82>/EtherCAT PDO Receive3'
   *   '<S82>/EtherCAT PDO Receive4'
   *   '<S82>/EtherCAT PDO Receive5'
   *   '<S82>/EtherCAT PDO Transmit'
   *   '<S82>/EtherCAT PDO Transmit1'
   *   '<S82>/EtherCAT PDO Transmit2'
   *   '<S100>/EtherCAT PDO Receive'
   *   '<S100>/EtherCAT PDO Receive1'
   *   '<S100>/EtherCAT PDO Receive2'
   *   '<S100>/EtherCAT PDO Receive3'
   *   '<S100>/EtherCAT PDO Receive4'
   *   '<S100>/EtherCAT PDO Receive5'
   *   '<S100>/EtherCAT PDO Transmit'
   *   '<S100>/EtherCAT PDO Transmit1'
   *   '<S100>/EtherCAT PDO Transmit2'
   */
  real_T pooled40;

  /* Computed Parameter: EtherCATRxVar4_P1_S_d
   * Referenced by: '<S41>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_S_d[2];

  /* Computed Parameter: EtherCATRxVar4_P1_a
   * Referenced by: '<S41>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_a[60];

  /* Computed Parameter: EtherCATRxVar4_P2_S_h
   * Referenced by: '<S41>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_S_h[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_c;

  /* Computed Parameter: EtherCATRxVar4_P1_S_a
   * Referenced by: '<S38>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_S_a[2];

  /* Computed Parameter: EtherCATRxVar4_P1_d
   * Referenced by: '<S38>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_d[60];

  /* Computed Parameter: EtherCATRxVar4_P2_S_b
   * Referenced by: '<S38>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_S_b[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_h;

  /* Computed Parameter: EtherCATRxVar4_P1_S_h
   * Referenced by: '<S40>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_S_h[2];

  /* Computed Parameter: EtherCATRxVar4_P1_l
   * Referenced by: '<S40>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_l[60];

  /* Computed Parameter: EtherCATRxVar4_P2_S_e
   * Referenced by: '<S40>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_S_e[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_l;

  /* Computed Parameter: EtherCATRxVar8_P1_Siz
   * Referenced by: '<S39>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar8_P1
   * Referenced by: '<S39>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1[64];

  /* Computed Parameter: EtherCATRxVar8_P2_Siz
   * Referenced by: '<S39>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2;

  /* Computed Parameter: EtherCATRxVar8_P1_S_b
   * Referenced by: '<S41>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_S_b[2];

  /* Computed Parameter: EtherCATRxVar8_P1_n
   * Referenced by: '<S41>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_n[64];

  /* Computed Parameter: EtherCATRxVar8_P2_S_f
   * Referenced by: '<S41>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_S_f[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_g;

  /* Computed Parameter: EtherCATRxVar8_P1_S_i
   * Referenced by: '<S38>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_S_i[2];

  /* Computed Parameter: EtherCATRxVar8_P1_c
   * Referenced by: '<S38>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_c[64];

  /* Computed Parameter: EtherCATRxVar8_P2_S_n
   * Referenced by: '<S38>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_S_n[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_f;

  /* Computed Parameter: EtherCATRxVar8_P1_S_o
   * Referenced by: '<S40>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_S_o[2];

  /* Computed Parameter: EtherCATRxVar8_P1_o
   * Referenced by: '<S40>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_o[64];

  /* Computed Parameter: EtherCATRxVar8_P2_S_i
   * Referenced by: '<S40>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_S_i[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_n;

  /* Computed Parameter: EtherCATRxVar4_P1_S_f
   * Referenced by: '<S32>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_S_f[2];

  /* Computed Parameter: EtherCATRxVar4_P1_o
   * Referenced by: '<S32>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_o[56];

  /* Computed Parameter: EtherCATRxVar4_P2_S_l
   * Referenced by: '<S32>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_S_l[2];

  /* Expression: sig_offset
   * Referenced by: '<S32>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_b;

  /* Computed Parameter: EtherCATRxVar4_P1__de
   * Referenced by: '<S31>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1__de[2];

  /* Computed Parameter: EtherCATRxVar4_P1_j
   * Referenced by: '<S31>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_j[56];

  /* Computed Parameter: EtherCATRxVar4_P2__bc
   * Referenced by: '<S31>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2__bc[2];

  /* Expression: sig_offset
   * Referenced by: '<S31>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_g;

  /* Computed Parameter: EtherCATRxVar_P1_Size
   * Referenced by: '<S39>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_Size[2];

  /* Computed Parameter: EtherCATRxVar_P1
   * Referenced by: '<S39>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1[76];

  /* Computed Parameter: EtherCATRxVar_P2_Size
   * Referenced by: '<S39>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_Size[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 1'
   *   '<S31>/EtherCAT Rx Var 12'
   *   '<S31>/EtherCAT Rx Var 13'
   *   '<S31>/EtherCAT Rx Var 14'
   *   '<S31>/EtherCAT Rx Var 2'
   *   '<S31>/EtherCAT Rx Var 3'
   *   '<S31>/EtherCAT Rx Var 5'
   *   '<S31>/EtherCAT Rx Var 6'
   *   '<S31>/EtherCAT Tx Var 4'
   *   '<S32>/EtherCAT Rx Var 1'
   *   '<S32>/EtherCAT Rx Var 12'
   *   '<S32>/EtherCAT Rx Var 13'
   *   '<S32>/EtherCAT Rx Var 14'
   *   '<S32>/EtherCAT Rx Var 2'
   *   '<S32>/EtherCAT Rx Var 3'
   *   '<S32>/EtherCAT Rx Var 5'
   *   '<S32>/EtherCAT Rx Var 6'
   *   '<S32>/EtherCAT Tx Var 4'
   *   '<S33>/EtherCAT Tx Var 1'
   *   '<S33>/EtherCAT Tx Var 2'
   *   '<S38>/EtherCAT Rx Var '
   *   '<S38>/EtherCAT Rx Var 1'
   *   '<S38>/EtherCAT Rx Var 10'
   *   '<S38>/EtherCAT Rx Var 11'
   *   '<S38>/EtherCAT Rx Var 12'
   *   '<S38>/EtherCAT Rx Var 13'
   *   '<S38>/EtherCAT Rx Var 14'
   *   '<S38>/EtherCAT Rx Var 15'
   *   '<S38>/EtherCAT Rx Var 16'
   *   '<S38>/EtherCAT Rx Var 17'
   *   '<S38>/EtherCAT Rx Var 2'
   *   '<S38>/EtherCAT Rx Var 23'
   *   '<S38>/EtherCAT Rx Var 3'
   *   '<S38>/EtherCAT Rx Var 5'
   *   '<S38>/EtherCAT Rx Var 9'
   *   '<S38>/EtherCAT Tx Var 4'
   *   '<S39>/EtherCAT Rx Var '
   *   '<S39>/EtherCAT Rx Var 1'
   *   '<S39>/EtherCAT Rx Var 10'
   *   '<S39>/EtherCAT Rx Var 11'
   *   '<S39>/EtherCAT Rx Var 12'
   *   '<S39>/EtherCAT Rx Var 13'
   *   '<S39>/EtherCAT Rx Var 14'
   *   '<S39>/EtherCAT Rx Var 15'
   *   '<S39>/EtherCAT Rx Var 16'
   *   '<S39>/EtherCAT Rx Var 17'
   *   '<S39>/EtherCAT Rx Var 2'
   *   '<S39>/EtherCAT Rx Var 23'
   *   '<S39>/EtherCAT Rx Var 3'
   *   '<S39>/EtherCAT Rx Var 5'
   *   '<S39>/EtherCAT Rx Var 9'
   *   '<S39>/EtherCAT Tx Var 4'
   *   '<S40>/EtherCAT Rx Var '
   *   '<S40>/EtherCAT Rx Var 1'
   *   '<S40>/EtherCAT Rx Var 10'
   *   '<S40>/EtherCAT Rx Var 11'
   *   '<S40>/EtherCAT Rx Var 12'
   *   '<S40>/EtherCAT Rx Var 13'
   *   '<S40>/EtherCAT Rx Var 14'
   *   '<S40>/EtherCAT Rx Var 15'
   *   '<S40>/EtherCAT Rx Var 16'
   *   '<S40>/EtherCAT Rx Var 17'
   *   '<S40>/EtherCAT Rx Var 2'
   *   '<S40>/EtherCAT Rx Var 23'
   *   '<S40>/EtherCAT Rx Var 3'
   *   '<S40>/EtherCAT Rx Var 5'
   *   '<S40>/EtherCAT Rx Var 9'
   *   '<S40>/EtherCAT Tx Var 4'
   *   '<S41>/EtherCAT Rx Var '
   *   '<S41>/EtherCAT Rx Var 1'
   *   '<S41>/EtherCAT Rx Var 10'
   *   '<S41>/EtherCAT Rx Var 11'
   *   '<S41>/EtherCAT Rx Var 12'
   *   '<S41>/EtherCAT Rx Var 13'
   *   '<S41>/EtherCAT Rx Var 14'
   *   '<S41>/EtherCAT Rx Var 15'
   *   '<S41>/EtherCAT Rx Var 16'
   *   '<S41>/EtherCAT Rx Var 17'
   *   '<S41>/EtherCAT Rx Var 2'
   *   '<S41>/EtherCAT Rx Var 23'
   *   '<S41>/EtherCAT Rx Var 3'
   *   '<S41>/EtherCAT Rx Var 5'
   *   '<S41>/EtherCAT Rx Var 9'
   *   '<S41>/EtherCAT Tx Var 4'
   *   '<S46>/EtherCAT PDO Receive5'
   *   '<S46>/EtherCAT PDO Transmit1'
   *   '<S64>/EtherCAT PDO Receive5'
   *   '<S64>/EtherCAT PDO Transmit1'
   *   '<S82>/EtherCAT PDO Receive5'
   *   '<S82>/EtherCAT PDO Transmit1'
   *   '<S100>/EtherCAT PDO Receive5'
   *   '<S100>/EtherCAT PDO Transmit1'
   */
  real_T pooled41[2];

  /* Pooled Parameter (Expression: sig_type)
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 1'
   *   '<S31>/EtherCAT Rx Var 12'
   *   '<S31>/EtherCAT Rx Var 13'
   *   '<S31>/EtherCAT Rx Var 14'
   *   '<S31>/EtherCAT Rx Var 2'
   *   '<S31>/EtherCAT Rx Var 3'
   *   '<S31>/EtherCAT Rx Var 5'
   *   '<S31>/EtherCAT Rx Var 6'
   *   '<S31>/EtherCAT Tx Var 4'
   *   '<S32>/EtherCAT Rx Var 1'
   *   '<S32>/EtherCAT Rx Var 12'
   *   '<S32>/EtherCAT Rx Var 13'
   *   '<S32>/EtherCAT Rx Var 14'
   *   '<S32>/EtherCAT Rx Var 2'
   *   '<S32>/EtherCAT Rx Var 3'
   *   '<S32>/EtherCAT Rx Var 5'
   *   '<S32>/EtherCAT Rx Var 6'
   *   '<S32>/EtherCAT Tx Var 4'
   *   '<S33>/EtherCAT Tx Var 1'
   *   '<S33>/EtherCAT Tx Var 2'
   *   '<S38>/EtherCAT Rx Var '
   *   '<S38>/EtherCAT Rx Var 1'
   *   '<S38>/EtherCAT Rx Var 10'
   *   '<S38>/EtherCAT Rx Var 11'
   *   '<S38>/EtherCAT Rx Var 12'
   *   '<S38>/EtherCAT Rx Var 13'
   *   '<S38>/EtherCAT Rx Var 14'
   *   '<S38>/EtherCAT Rx Var 15'
   *   '<S38>/EtherCAT Rx Var 16'
   *   '<S38>/EtherCAT Rx Var 17'
   *   '<S38>/EtherCAT Rx Var 2'
   *   '<S38>/EtherCAT Rx Var 23'
   *   '<S38>/EtherCAT Rx Var 3'
   *   '<S38>/EtherCAT Rx Var 5'
   *   '<S38>/EtherCAT Rx Var 9'
   *   '<S38>/EtherCAT Tx Var 4'
   *   '<S39>/EtherCAT Rx Var '
   *   '<S39>/EtherCAT Rx Var 1'
   *   '<S39>/EtherCAT Rx Var 10'
   *   '<S39>/EtherCAT Rx Var 11'
   *   '<S39>/EtherCAT Rx Var 12'
   *   '<S39>/EtherCAT Rx Var 13'
   *   '<S39>/EtherCAT Rx Var 14'
   *   '<S39>/EtherCAT Rx Var 15'
   *   '<S39>/EtherCAT Rx Var 16'
   *   '<S39>/EtherCAT Rx Var 17'
   *   '<S39>/EtherCAT Rx Var 2'
   *   '<S39>/EtherCAT Rx Var 23'
   *   '<S39>/EtherCAT Rx Var 3'
   *   '<S39>/EtherCAT Rx Var 5'
   *   '<S39>/EtherCAT Rx Var 9'
   *   '<S39>/EtherCAT Tx Var 4'
   *   '<S40>/EtherCAT Rx Var '
   *   '<S40>/EtherCAT Rx Var 1'
   *   '<S40>/EtherCAT Rx Var 10'
   *   '<S40>/EtherCAT Rx Var 11'
   *   '<S40>/EtherCAT Rx Var 12'
   *   '<S40>/EtherCAT Rx Var 13'
   *   '<S40>/EtherCAT Rx Var 14'
   *   '<S40>/EtherCAT Rx Var 15'
   *   '<S40>/EtherCAT Rx Var 16'
   *   '<S40>/EtherCAT Rx Var 17'
   *   '<S40>/EtherCAT Rx Var 2'
   *   '<S40>/EtherCAT Rx Var 23'
   *   '<S40>/EtherCAT Rx Var 3'
   *   '<S40>/EtherCAT Rx Var 5'
   *   '<S40>/EtherCAT Rx Var 9'
   *   '<S40>/EtherCAT Tx Var 4'
   *   '<S41>/EtherCAT Rx Var '
   *   '<S41>/EtherCAT Rx Var 1'
   *   '<S41>/EtherCAT Rx Var 10'
   *   '<S41>/EtherCAT Rx Var 11'
   *   '<S41>/EtherCAT Rx Var 12'
   *   '<S41>/EtherCAT Rx Var 13'
   *   '<S41>/EtherCAT Rx Var 14'
   *   '<S41>/EtherCAT Rx Var 15'
   *   '<S41>/EtherCAT Rx Var 16'
   *   '<S41>/EtherCAT Rx Var 17'
   *   '<S41>/EtherCAT Rx Var 2'
   *   '<S41>/EtherCAT Rx Var 23'
   *   '<S41>/EtherCAT Rx Var 3'
   *   '<S41>/EtherCAT Rx Var 5'
   *   '<S41>/EtherCAT Rx Var 9'
   *   '<S41>/EtherCAT Tx Var 4'
   *   '<S46>/EtherCAT PDO Receive5'
   *   '<S46>/EtherCAT PDO Transmit1'
   *   '<S64>/EtherCAT PDO Receive5'
   *   '<S64>/EtherCAT PDO Transmit1'
   *   '<S82>/EtherCAT PDO Receive5'
   *   '<S82>/EtherCAT PDO Transmit1'
   *   '<S100>/EtherCAT PDO Receive5'
   *   '<S100>/EtherCAT PDO Transmit1'
   */
  real_T pooled42;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var '
   *   '<S31>/EtherCAT Rx Var 1'
   *   '<S31>/EtherCAT Rx Var 12'
   *   '<S31>/EtherCAT Rx Var 13'
   *   '<S31>/EtherCAT Rx Var 14'
   *   '<S31>/EtherCAT Rx Var 2'
   *   '<S31>/EtherCAT Rx Var 3'
   *   '<S31>/EtherCAT Rx Var 5'
   *   '<S31>/EtherCAT Rx Var 6'
   *   '<S31>/EtherCAT Tx Var 4'
   *   '<S32>/EtherCAT Rx Var '
   *   '<S32>/EtherCAT Rx Var 1'
   *   '<S32>/EtherCAT Rx Var 12'
   *   '<S32>/EtherCAT Rx Var 13'
   *   '<S32>/EtherCAT Rx Var 14'
   *   '<S32>/EtherCAT Rx Var 2'
   *   '<S32>/EtherCAT Rx Var 3'
   *   '<S32>/EtherCAT Rx Var 5'
   *   '<S32>/EtherCAT Rx Var 6'
   *   '<S32>/EtherCAT Tx Var 4'
   *   '<S33>/EtherCAT Tx Var 1'
   *   '<S33>/EtherCAT Tx Var 2'
   *   '<S38>/EtherCAT Rx Var '
   *   '<S38>/EtherCAT Rx Var 1'
   *   '<S38>/EtherCAT Rx Var 10'
   *   '<S38>/EtherCAT Rx Var 11'
   *   '<S38>/EtherCAT Rx Var 12'
   *   '<S38>/EtherCAT Rx Var 13'
   *   '<S38>/EtherCAT Rx Var 14'
   *   '<S38>/EtherCAT Rx Var 15'
   *   '<S38>/EtherCAT Rx Var 16'
   *   '<S38>/EtherCAT Rx Var 17'
   *   '<S38>/EtherCAT Rx Var 2'
   *   '<S38>/EtherCAT Rx Var 23'
   *   '<S38>/EtherCAT Rx Var 3'
   *   '<S38>/EtherCAT Rx Var 5'
   *   '<S38>/EtherCAT Rx Var 6'
   *   '<S38>/EtherCAT Rx Var 7'
   *   '<S38>/EtherCAT Rx Var 9'
   *   '<S38>/EtherCAT Tx Var 4'
   *   '<S39>/EtherCAT Rx Var '
   *   '<S39>/EtherCAT Rx Var 1'
   *   '<S39>/EtherCAT Rx Var 10'
   *   '<S39>/EtherCAT Rx Var 11'
   *   '<S39>/EtherCAT Rx Var 12'
   *   '<S39>/EtherCAT Rx Var 13'
   *   '<S39>/EtherCAT Rx Var 14'
   *   '<S39>/EtherCAT Rx Var 15'
   *   '<S39>/EtherCAT Rx Var 16'
   *   '<S39>/EtherCAT Rx Var 17'
   *   '<S39>/EtherCAT Rx Var 2'
   *   '<S39>/EtherCAT Rx Var 23'
   *   '<S39>/EtherCAT Rx Var 3'
   *   '<S39>/EtherCAT Rx Var 5'
   *   '<S39>/EtherCAT Rx Var 6'
   *   '<S39>/EtherCAT Rx Var 7'
   *   '<S39>/EtherCAT Rx Var 9'
   *   '<S39>/EtherCAT Tx Var 4'
   *   '<S40>/EtherCAT Rx Var '
   *   '<S40>/EtherCAT Rx Var 1'
   *   '<S40>/EtherCAT Rx Var 10'
   *   '<S40>/EtherCAT Rx Var 11'
   *   '<S40>/EtherCAT Rx Var 12'
   *   '<S40>/EtherCAT Rx Var 13'
   *   '<S40>/EtherCAT Rx Var 14'
   *   '<S40>/EtherCAT Rx Var 15'
   *   '<S40>/EtherCAT Rx Var 16'
   *   '<S40>/EtherCAT Rx Var 17'
   *   '<S40>/EtherCAT Rx Var 2'
   *   '<S40>/EtherCAT Rx Var 23'
   *   '<S40>/EtherCAT Rx Var 3'
   *   '<S40>/EtherCAT Rx Var 5'
   *   '<S40>/EtherCAT Rx Var 6'
   *   '<S40>/EtherCAT Rx Var 7'
   *   '<S40>/EtherCAT Rx Var 9'
   *   '<S40>/EtherCAT Tx Var 4'
   *   '<S41>/EtherCAT Rx Var '
   *   '<S41>/EtherCAT Rx Var 1'
   *   '<S41>/EtherCAT Rx Var 10'
   *   '<S41>/EtherCAT Rx Var 11'
   *   '<S41>/EtherCAT Rx Var 12'
   *   '<S41>/EtherCAT Rx Var 13'
   *   '<S41>/EtherCAT Rx Var 14'
   *   '<S41>/EtherCAT Rx Var 15'
   *   '<S41>/EtherCAT Rx Var 16'
   *   '<S41>/EtherCAT Rx Var 17'
   *   '<S41>/EtherCAT Rx Var 2'
   *   '<S41>/EtherCAT Rx Var 23'
   *   '<S41>/EtherCAT Rx Var 3'
   *   '<S41>/EtherCAT Rx Var 5'
   *   '<S41>/EtherCAT Rx Var 6'
   *   '<S41>/EtherCAT Rx Var 7'
   *   '<S41>/EtherCAT Rx Var 9'
   *   '<S41>/EtherCAT Tx Var 4'
   *   '<S46>/EtherCAT PDO Receive'
   *   '<S46>/EtherCAT PDO Receive3'
   *   '<S46>/EtherCAT PDO Receive5'
   *   '<S46>/EtherCAT PDO Transmit'
   *   '<S46>/EtherCAT PDO Transmit1'
   *   '<S64>/EtherCAT PDO Receive'
   *   '<S64>/EtherCAT PDO Receive3'
   *   '<S64>/EtherCAT PDO Receive5'
   *   '<S64>/EtherCAT PDO Transmit'
   *   '<S64>/EtherCAT PDO Transmit1'
   *   '<S82>/EtherCAT PDO Receive'
   *   '<S82>/EtherCAT PDO Receive3'
   *   '<S82>/EtherCAT PDO Receive5'
   *   '<S82>/EtherCAT PDO Transmit'
   *   '<S82>/EtherCAT PDO Transmit1'
   *   '<S100>/EtherCAT PDO Receive'
   *   '<S100>/EtherCAT PDO Receive3'
   *   '<S100>/EtherCAT PDO Receive5'
   *   '<S100>/EtherCAT PDO Transmit'
   *   '<S100>/EtherCAT PDO Transmit1'
   */
  real_T pooled43[2];

  /* Pooled Parameter (Expression: type_size)
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var '
   *   '<S31>/EtherCAT Rx Var 1'
   *   '<S31>/EtherCAT Rx Var 12'
   *   '<S31>/EtherCAT Rx Var 13'
   *   '<S31>/EtherCAT Rx Var 14'
   *   '<S31>/EtherCAT Rx Var 2'
   *   '<S31>/EtherCAT Rx Var 3'
   *   '<S31>/EtherCAT Rx Var 5'
   *   '<S31>/EtherCAT Rx Var 6'
   *   '<S31>/EtherCAT Tx Var 4'
   *   '<S32>/EtherCAT Rx Var '
   *   '<S32>/EtherCAT Rx Var 1'
   *   '<S32>/EtherCAT Rx Var 12'
   *   '<S32>/EtherCAT Rx Var 13'
   *   '<S32>/EtherCAT Rx Var 14'
   *   '<S32>/EtherCAT Rx Var 2'
   *   '<S32>/EtherCAT Rx Var 3'
   *   '<S32>/EtherCAT Rx Var 5'
   *   '<S32>/EtherCAT Rx Var 6'
   *   '<S32>/EtherCAT Tx Var 4'
   *   '<S33>/EtherCAT Tx Var 1'
   *   '<S33>/EtherCAT Tx Var 2'
   *   '<S38>/EtherCAT Rx Var '
   *   '<S38>/EtherCAT Rx Var 1'
   *   '<S38>/EtherCAT Rx Var 10'
   *   '<S38>/EtherCAT Rx Var 11'
   *   '<S38>/EtherCAT Rx Var 12'
   *   '<S38>/EtherCAT Rx Var 13'
   *   '<S38>/EtherCAT Rx Var 14'
   *   '<S38>/EtherCAT Rx Var 15'
   *   '<S38>/EtherCAT Rx Var 16'
   *   '<S38>/EtherCAT Rx Var 17'
   *   '<S38>/EtherCAT Rx Var 2'
   *   '<S38>/EtherCAT Rx Var 23'
   *   '<S38>/EtherCAT Rx Var 3'
   *   '<S38>/EtherCAT Rx Var 5'
   *   '<S38>/EtherCAT Rx Var 6'
   *   '<S38>/EtherCAT Rx Var 7'
   *   '<S38>/EtherCAT Rx Var 9'
   *   '<S38>/EtherCAT Tx Var 4'
   *   '<S39>/EtherCAT Rx Var '
   *   '<S39>/EtherCAT Rx Var 1'
   *   '<S39>/EtherCAT Rx Var 10'
   *   '<S39>/EtherCAT Rx Var 11'
   *   '<S39>/EtherCAT Rx Var 12'
   *   '<S39>/EtherCAT Rx Var 13'
   *   '<S39>/EtherCAT Rx Var 14'
   *   '<S39>/EtherCAT Rx Var 15'
   *   '<S39>/EtherCAT Rx Var 16'
   *   '<S39>/EtherCAT Rx Var 17'
   *   '<S39>/EtherCAT Rx Var 2'
   *   '<S39>/EtherCAT Rx Var 23'
   *   '<S39>/EtherCAT Rx Var 3'
   *   '<S39>/EtherCAT Rx Var 5'
   *   '<S39>/EtherCAT Rx Var 6'
   *   '<S39>/EtherCAT Rx Var 7'
   *   '<S39>/EtherCAT Rx Var 9'
   *   '<S39>/EtherCAT Tx Var 4'
   *   '<S40>/EtherCAT Rx Var '
   *   '<S40>/EtherCAT Rx Var 1'
   *   '<S40>/EtherCAT Rx Var 10'
   *   '<S40>/EtherCAT Rx Var 11'
   *   '<S40>/EtherCAT Rx Var 12'
   *   '<S40>/EtherCAT Rx Var 13'
   *   '<S40>/EtherCAT Rx Var 14'
   *   '<S40>/EtherCAT Rx Var 15'
   *   '<S40>/EtherCAT Rx Var 16'
   *   '<S40>/EtherCAT Rx Var 17'
   *   '<S40>/EtherCAT Rx Var 2'
   *   '<S40>/EtherCAT Rx Var 23'
   *   '<S40>/EtherCAT Rx Var 3'
   *   '<S40>/EtherCAT Rx Var 5'
   *   '<S40>/EtherCAT Rx Var 6'
   *   '<S40>/EtherCAT Rx Var 7'
   *   '<S40>/EtherCAT Rx Var 9'
   *   '<S40>/EtherCAT Tx Var 4'
   *   '<S41>/EtherCAT Rx Var '
   *   '<S41>/EtherCAT Rx Var 1'
   *   '<S41>/EtherCAT Rx Var 10'
   *   '<S41>/EtherCAT Rx Var 11'
   *   '<S41>/EtherCAT Rx Var 12'
   *   '<S41>/EtherCAT Rx Var 13'
   *   '<S41>/EtherCAT Rx Var 14'
   *   '<S41>/EtherCAT Rx Var 15'
   *   '<S41>/EtherCAT Rx Var 16'
   *   '<S41>/EtherCAT Rx Var 17'
   *   '<S41>/EtherCAT Rx Var 2'
   *   '<S41>/EtherCAT Rx Var 23'
   *   '<S41>/EtherCAT Rx Var 3'
   *   '<S41>/EtherCAT Rx Var 5'
   *   '<S41>/EtherCAT Rx Var 6'
   *   '<S41>/EtherCAT Rx Var 7'
   *   '<S41>/EtherCAT Rx Var 9'
   *   '<S41>/EtherCAT Tx Var 4'
   *   '<S46>/EtherCAT PDO Receive'
   *   '<S46>/EtherCAT PDO Receive3'
   *   '<S46>/EtherCAT PDO Receive5'
   *   '<S46>/EtherCAT PDO Transmit'
   *   '<S46>/EtherCAT PDO Transmit1'
   *   '<S64>/EtherCAT PDO Receive'
   *   '<S64>/EtherCAT PDO Receive3'
   *   '<S64>/EtherCAT PDO Receive5'
   *   '<S64>/EtherCAT PDO Transmit'
   *   '<S64>/EtherCAT PDO Transmit1'
   *   '<S82>/EtherCAT PDO Receive'
   *   '<S82>/EtherCAT PDO Receive3'
   *   '<S82>/EtherCAT PDO Receive5'
   *   '<S82>/EtherCAT PDO Transmit'
   *   '<S82>/EtherCAT PDO Transmit1'
   *   '<S100>/EtherCAT PDO Receive'
   *   '<S100>/EtherCAT PDO Receive3'
   *   '<S100>/EtherCAT PDO Receive5'
   *   '<S100>/EtherCAT PDO Transmit'
   *   '<S100>/EtherCAT PDO Transmit1'
   */
  real_T pooled44;

  /* Computed Parameter: EtherCATRxVar_P1_Si_c
   * Referenced by: '<S41>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_Si_c[2];

  /* Computed Parameter: EtherCATRxVar_P1_m
   * Referenced by: '<S41>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_m[76];

  /* Computed Parameter: EtherCATRxVar_P2_Si_e
   * Referenced by: '<S41>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_Si_e[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_j;

  /* Computed Parameter: EtherCATRxVar_P1_Si_k
   * Referenced by: '<S38>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_Si_k[2];

  /* Computed Parameter: EtherCATRxVar_P1_h
   * Referenced by: '<S38>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_h[76];

  /* Computed Parameter: EtherCATRxVar_P2_S_e2
   * Referenced by: '<S38>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_S_e2[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_p;

  /* Computed Parameter: EtherCATRxVar_P1_Si_b
   * Referenced by: '<S40>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_Si_b[2];

  /* Computed Parameter: EtherCATRxVar_P1_e
   * Referenced by: '<S40>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_e[76];

  /* Computed Parameter: EtherCATRxVar_P2_Si_m
   * Referenced by: '<S40>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_Si_m[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_pi;

  /* Computed Parameter: EtherCATRxVar2_P1_Siz
   * Referenced by: '<S32>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar2_P1
   * Referenced by: '<S32>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1[76];

  /* Computed Parameter: EtherCATRxVar2_P2_Siz
   * Referenced by: '<S32>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S32>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2;

  /* Computed Parameter: EtherCATRxVar2_P1_S_n
   * Referenced by: '<S31>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_S_n[2];

  /* Computed Parameter: EtherCATRxVar2_P1_p
   * Referenced by: '<S31>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_p[76];

  /* Computed Parameter: EtherCATRxVar2_P2_S_p
   * Referenced by: '<S31>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_S_p[2];

  /* Expression: sig_offset
   * Referenced by: '<S31>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_n;

  /* Expression: zeros(6,1)
   * Referenced by: '<S13>/Unit Delay2'
   */
  real_T UnitDelay2_InitialCon[6];

  /* Expression: EncoderThreshold
   * Referenced by: '<S13>/EncoderThreshold'
   */
  real_T EncoderThreshold_Val[19];

  /* Computed Parameter: EtherCATRxVar18_P1_Si
   * Referenced by: '<S39>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar18_P1
   * Referenced by: '<S39>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1[63];

  /* Computed Parameter: EtherCATRxVar18_P2_Si
   * Referenced by: '<S39>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2;

  /* Computed Parameter: EtherCATRxVar18_P1__m
   * Referenced by: '<S41>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1__m[2];

  /* Computed Parameter: EtherCATRxVar18_P1_p
   * Referenced by: '<S41>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1_p[63];

  /* Computed Parameter: EtherCATRxVar18_P2__m
   * Referenced by: '<S41>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2__m[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2_d;

  /* Computed Parameter: EtherCATRxVar18_P1__e
   * Referenced by: '<S38>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1__e[2];

  /* Computed Parameter: EtherCATRxVar18_P_pq
   * Referenced by: '<S38>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P_pq[63];

  /* Computed Parameter: EtherCATRxVar18_P2__o
   * Referenced by: '<S38>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2__o[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2_k;

  /* Computed Parameter: EtherCATRxVar18_P1__p
   * Referenced by: '<S40>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1__p[2];

  /* Computed Parameter: EtherCATRxVar18_P1_d
   * Referenced by: '<S40>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1_d[63];

  /* Computed Parameter: EtherCATRxVar18_P2__e
   * Referenced by: '<S40>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2__e[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2_e;

  /* Computed Parameter: EtherCATRxVar15_P1_Si
   * Referenced by: '<S32>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar15_P1
   * Referenced by: '<S32>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1[63];

  /* Computed Parameter: EtherCATRxVar15_P2_Si
   * Referenced by: '<S32>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S32>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2;

  /* Computed Parameter: EtherCATRxVar15_P1__k
   * Referenced by: '<S31>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1__k[2];

  /* Computed Parameter: EtherCATRxVar15_P1_c
   * Referenced by: '<S31>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_c[63];

  /* Computed Parameter: EtherCATRxVar15_P2__d
   * Referenced by: '<S31>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2__d[2];

  /* Expression: sig_offset
   * Referenced by: '<S31>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_i;

  /* Computed Parameter: EtherCATRxVar17_P1_Si
   * Referenced by: '<S33>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar17_P1
   * Referenced by: '<S33>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1[75];

  /* Computed Parameter: EtherCATRxVar17_P2_Si
   * Referenced by: '<S33>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2;

  /* Computed Parameter: EtherCATRxVar6_P1_Siz
   * Referenced by: '<S33>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar6_P1
   * Referenced by: '<S33>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1[54];

  /* Computed Parameter: EtherCATRxVar6_P2_Siz
   * Referenced by: '<S33>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2;

  /* Computed Parameter: EtherCATRxVar1_P1_Siz
   * Referenced by: '<S33>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar1_P1
   * Referenced by: '<S33>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1[54];

  /* Computed Parameter: EtherCATRxVar1_P2_Siz
   * Referenced by: '<S33>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2;

  /* Computed Parameter: EtherCATRxVar2_P1_S_h
   * Referenced by: '<S33>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_S_h[2];

  /* Computed Parameter: EtherCATRxVar2_P1_pe
   * Referenced by: '<S33>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_pe[54];

  /* Computed Parameter: EtherCATRxVar2_P2_S_f
   * Referenced by: '<S33>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_S_f[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_o;

  /* Computed Parameter: EtherCATRxVar5_P1_Siz
   * Referenced by: '<S33>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar5_P1
   * Referenced by: '<S33>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1[54];

  /* Computed Parameter: EtherCATRxVar5_P2_Siz
   * Referenced by: '<S33>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2;

  /* Computed Parameter: EtherCATRxVar3_P1_Siz
   * Referenced by: '<S33>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar3_P1
   * Referenced by: '<S33>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1[54];

  /* Computed Parameter: EtherCATRxVar3_P2_Siz
   * Referenced by: '<S33>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2;

  /* Computed Parameter: EtherCATRxVar4_P1_S_c
   * Referenced by: '<S33>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_S_c[2];

  /* Computed Parameter: EtherCATRxVar4_P1_g
   * Referenced by: '<S33>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P1_g[54];

  /* Computed Parameter: EtherCATRxVar4_P2__lp
   * Referenced by: '<S33>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2__lp[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 4'
   */
  real_T EtherCATRxVar4_P2_h3;

  /* Computed Parameter: EtherCATRxVar19_P1_Si
   * Referenced by: '<S33>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar19_P1
   * Referenced by: '<S33>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1[54];

  /* Computed Parameter: EtherCATRxVar19_P2_Si
   * Referenced by: '<S33>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P2;

  /* Computed Parameter: EtherCATRxVar7_P1_Siz
   * Referenced by: '<S33>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar7_P1
   * Referenced by: '<S33>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1[54];

  /* Computed Parameter: EtherCATRxVar7_P2_Siz
   * Referenced by: '<S33>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2;

  /* Computed Parameter: EtherCATRxVar8_P1_S_k
   * Referenced by: '<S33>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_S_k[2];

  /* Computed Parameter: EtherCATRxVar8_P1_g
   * Referenced by: '<S33>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P1_g[54];

  /* Computed Parameter: EtherCATRxVar8_P2_S_h
   * Referenced by: '<S33>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_S_h[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 8'
   */
  real_T EtherCATRxVar8_P2_k;

  /* Expression: [0 1 0; 1 0 0; 0 0 -1]
   * Referenced by: '<S13>/Gain'
   */
  real_T Gain_Gain[9];

  /* Computed Parameter: EtherCATRxVar10_P1_Si
   * Referenced by: '<S33>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar10_P1
   * Referenced by: '<S33>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1[63];

  /* Computed Parameter: EtherCATRxVar10_P2_Si
   * Referenced by: '<S33>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2;

  /* Computed Parameter: EtherCATRxVar14_P1_Si
   * Referenced by: '<S33>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar14_P1
   * Referenced by: '<S33>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1[63];

  /* Computed Parameter: EtherCATRxVar14_P2_Si
   * Referenced by: '<S33>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2;

  /* Computed Parameter: EtherCATRxVar13_P1_Si
   * Referenced by: '<S33>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar13_P1
   * Referenced by: '<S33>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1[63];

  /* Computed Parameter: EtherCATRxVar13_P2_Si
   * Referenced by: '<S33>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2;

  /* Expression: Calibration.MicrostrainOrientation
   * Referenced by: '<S13>/MisalignmentMatrixParams'
   */
  real_T MisalignmentMatrixPar[9];

  /* Expression: IMUAngleLimits
   * Referenced by: '<S13>/IMUAngleLimits'
   */
  real_T IMUAngleLimits_Value[6];

  /* Expression: [1 0; 1 0; 0 1; 1 0; 1 0; 0 1]
   * Referenced by: '<S204>/Gain1'
   */
  real_T Gain1_Gain[12];

  /* Expression: TKA
   * Referenced by: '<S214>/TKA'
   */
  real_T TKA_Gain[26];

  /* Expression: VBLAOptions
   * Referenced by: '<S201>/VBLAOptions'
   */
  real_T VBLAOptions_Value[6];

  /* Expression: balanceParams
   * Referenced by: '<S201>/balanceParams'
   */
  real_T balanceParams_Value[13];

  /* Expression: [1 1 1 1 1 1]*pi/180
   * Referenced by: '<S201>/Gain'
   */
  real_T Gain_Gain_a[6];

  /* Computed Parameter: EtherCATRxVar21_P1_Si
   * Referenced by: '<S39>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar21_P1
   * Referenced by: '<S39>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1[68];

  /* Computed Parameter: EtherCATRxVar21_P2_Si
   * Referenced by: '<S39>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2;

  /* Computed Parameter: EtherCATRxVar21_P1__a
   * Referenced by: '<S41>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1__a[2];

  /* Computed Parameter: EtherCATRxVar21_P1_n
   * Referenced by: '<S41>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1_n[68];

  /* Computed Parameter: EtherCATRxVar21_P2__k
   * Referenced by: '<S41>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2__k[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2_g;

  /* Computed Parameter: EtherCATRxVar18_P1__c
   * Referenced by: '<S32>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1__c[2];

  /* Computed Parameter: EtherCATRxVar18_P1_l
   * Referenced by: '<S32>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1_l[68];

  /* Computed Parameter: EtherCATRxVar18_P2__l
   * Referenced by: '<S32>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2__l[2];

  /* Expression: sig_offset
   * Referenced by: '<S32>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2_d2;

  /* Computed Parameter: EtherCATRxVar21_P1__e
   * Referenced by: '<S38>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1__e[2];

  /* Computed Parameter: EtherCATRxVar21_P1_b
   * Referenced by: '<S38>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1_b[68];

  /* Computed Parameter: EtherCATRxVar21_P2__f
   * Referenced by: '<S38>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2__f[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2_m;

  /* Computed Parameter: EtherCATRxVar21_P1__g
   * Referenced by: '<S40>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1__g[2];

  /* Computed Parameter: EtherCATRxVar21_P1_e
   * Referenced by: '<S40>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P1_e[68];

  /* Computed Parameter: EtherCATRxVar21_P2__p
   * Referenced by: '<S40>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2__p[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 21'
   */
  real_T EtherCATRxVar21_P2_i;

  /* Computed Parameter: EtherCATRxVar18_P1__o
   * Referenced by: '<S31>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1__o[2];

  /* Computed Parameter: EtherCATRxVar18_P1_n
   * Referenced by: '<S31>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1_n[68];

  /* Computed Parameter: EtherCATRxVar18_P2__a
   * Referenced by: '<S31>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2__a[2];

  /* Expression: sig_offset
   * Referenced by: '<S31>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P2_a;

  /* Computed Parameter: EtherCATRxVar22_P1_Si
   * Referenced by: '<S39>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar22_P1
   * Referenced by: '<S39>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1[61];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S39>/EtherCAT Rx Var 22'
   *   '<S39>/EtherCAT Tx Var 4'
   */
  real_T pooled47[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S39>/EtherCAT Rx Var 22'
   *   '<S39>/EtherCAT Tx Var 4'
   */
  real_T pooled48;

  /* Computed Parameter: EtherCATRxVar22_P1__p
   * Referenced by: '<S41>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1__p[2];

  /* Computed Parameter: EtherCATRxVar22_P1_g
   * Referenced by: '<S41>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1_g[61];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S41>/EtherCAT Rx Var 22'
   *   '<S41>/EtherCAT Tx Var 4'
   */
  real_T pooled49[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S41>/EtherCAT Rx Var 22'
   *   '<S41>/EtherCAT Tx Var 4'
   */
  real_T pooled50;

  /* Computed Parameter: EtherCATRxVar19_P1__e
   * Referenced by: '<S32>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1__e[2];

  /* Computed Parameter: EtherCATRxVar19_P1_c
   * Referenced by: '<S32>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_c[61];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S32>/EtherCAT Rx Var 19'
   *   '<S32>/EtherCAT Tx Var 4'
   */
  real_T pooled51[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S32>/EtherCAT Rx Var 19'
   *   '<S32>/EtherCAT Tx Var 4'
   */
  real_T pooled52;

  /* Computed Parameter: EtherCATRxVar22_P1__e
   * Referenced by: '<S38>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1__e[2];

  /* Computed Parameter: EtherCATRxVar22_P1_j
   * Referenced by: '<S38>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1_j[61];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S38>/EtherCAT Rx Var 22'
   *   '<S38>/EtherCAT Tx Var 4'
   */
  real_T pooled53[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S38>/EtherCAT Rx Var 22'
   *   '<S38>/EtherCAT Tx Var 4'
   */
  real_T pooled54;

  /* Computed Parameter: EtherCATRxVar22_P1__b
   * Referenced by: '<S40>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1__b[2];

  /* Computed Parameter: EtherCATRxVar22_P1_k
   * Referenced by: '<S40>/EtherCAT Rx Var 22'
   */
  real_T EtherCATRxVar22_P1_k[61];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S40>/EtherCAT Rx Var 22'
   *   '<S40>/EtherCAT Tx Var 4'
   */
  real_T pooled55[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S40>/EtherCAT Rx Var 22'
   *   '<S40>/EtherCAT Tx Var 4'
   */
  real_T pooled56;

  /* Computed Parameter: EtherCATRxVar19_P1__f
   * Referenced by: '<S31>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1__f[2];

  /* Computed Parameter: EtherCATRxVar19_P1_l
   * Referenced by: '<S31>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_l[61];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 19'
   *   '<S31>/EtherCAT Tx Var 4'
   */
  real_T pooled57[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 19'
   *   '<S31>/EtherCAT Tx Var 4'
   */
  real_T pooled58;

  /* Computed Parameter: EtherCATRxVar18_P1__f
   * Referenced by: '<S33>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1__f[2];

  /* Computed Parameter: EtherCATRxVar18_P1_j
   * Referenced by: '<S33>/EtherCAT Rx Var 18'
   */
  real_T EtherCATRxVar18_P1_j[73];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S33>/EtherCAT Rx Var 18'
   *   '<S33>/EtherCAT Tx Var 1'
   */
  real_T pooled59[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S33>/EtherCAT Rx Var 18'
   *   '<S33>/EtherCAT Tx Var 1'
   */
  real_T pooled60;

  /* Computed Parameter: EtherCATRxVar19_P1__k
   * Referenced by: '<S39>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1__k[2];

  /* Computed Parameter: EtherCATRxVar19_P1_d
   * Referenced by: '<S39>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_d[67];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S39>/EtherCAT Rx Var 19'
   *   '<S39>/EtherCAT Tx Var 5'
   */
  real_T pooled61[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S39>/EtherCAT Rx Var 19'
   *   '<S39>/EtherCAT Tx Var 5'
   */
  real_T pooled62;

  /* Computed Parameter: EtherCATRxVar19_P1__m
   * Referenced by: '<S41>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1__m[2];

  /* Computed Parameter: EtherCATRxVar19_P1_i
   * Referenced by: '<S41>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_i[67];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S41>/EtherCAT Rx Var 19'
   *   '<S41>/EtherCAT Tx Var 5'
   */
  real_T pooled63[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S41>/EtherCAT Rx Var 19'
   *   '<S41>/EtherCAT Tx Var 5'
   */
  real_T pooled64;

  /* Computed Parameter: EtherCATRxVar16_P1_Si
   * Referenced by: '<S32>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar16_P1
   * Referenced by: '<S32>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1[67];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S32>/EtherCAT Rx Var 16'
   *   '<S32>/EtherCAT Tx Var 5'
   */
  real_T pooled65[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S32>/EtherCAT Rx Var 16'
   *   '<S32>/EtherCAT Tx Var 5'
   */
  real_T pooled66;

  /* Computed Parameter: EtherCATRxVar19_P1__p
   * Referenced by: '<S38>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1__p[2];

  /* Computed Parameter: EtherCATRxVar19_P1_m
   * Referenced by: '<S38>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_m[67];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S38>/EtherCAT Rx Var 19'
   *   '<S38>/EtherCAT Tx Var 5'
   */
  real_T pooled67[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S38>/EtherCAT Rx Var 19'
   *   '<S38>/EtherCAT Tx Var 5'
   */
  real_T pooled68;

  /* Computed Parameter: EtherCATRxVar19_P1__a
   * Referenced by: '<S40>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1__a[2];

  /* Computed Parameter: EtherCATRxVar19_P1_g
   * Referenced by: '<S40>/EtherCAT Rx Var 19'
   */
  real_T EtherCATRxVar19_P1_g[67];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S40>/EtherCAT Rx Var 19'
   *   '<S40>/EtherCAT Tx Var 5'
   */
  real_T pooled69[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S40>/EtherCAT Rx Var 19'
   *   '<S40>/EtherCAT Tx Var 5'
   */
  real_T pooled70;

  /* Computed Parameter: EtherCATRxVar16_P1__i
   * Referenced by: '<S31>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1__i[2];

  /* Computed Parameter: EtherCATRxVar16_P1_n
   * Referenced by: '<S31>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_n[67];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 16'
   *   '<S31>/EtherCAT Tx Var 5'
   */
  real_T pooled71[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 16'
   *   '<S31>/EtherCAT Tx Var 5'
   */
  real_T pooled72;

  /* Computed Parameter: EtherCATRxVar15_P1__c
   * Referenced by: '<S33>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1__c[2];

  /* Computed Parameter: EtherCATRxVar15_P1_e
   * Referenced by: '<S33>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_e[79];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S33>/EtherCAT Rx Var 15'
   *   '<S33>/EtherCAT Tx Var 2'
   */
  real_T pooled73[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S33>/EtherCAT Rx Var 15'
   *   '<S33>/EtherCAT Tx Var 2'
   */
  real_T pooled74;

  /* Expression: [10; 10; 5.5; 10; 10; 5.5]
   * Referenced by: '<S1>/TorqueToCurrent'
   */
  real_T TorqueToCurrent_Gain[6];

  /* Computed Parameter: EtherCATRxVar12_P1_Si
   * Referenced by: '<S39>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar12_P1
   * Referenced by: '<S39>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1[61];

  /* Computed Parameter: EtherCATRxVar12_P2_Si
   * Referenced by: '<S39>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2;

  /* Computed Parameter: EtherCATRxVar13_P1__j
   * Referenced by: '<S39>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1__j[2];

  /* Computed Parameter: EtherCATRxVar13_P1_e
   * Referenced by: '<S39>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1_e[61];

  /* Computed Parameter: EtherCATRxVar13_P2__d
   * Referenced by: '<S39>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2__d[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_k;

  /* Computed Parameter: EtherCATRxVar14_P1__a
   * Referenced by: '<S39>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1__a[2];

  /* Computed Parameter: EtherCATRxVar14_P1_i
   * Referenced by: '<S39>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1_i[61];

  /* Computed Parameter: EtherCATRxVar14_P2__h
   * Referenced by: '<S39>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2__h[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_p;

  /* Computed Parameter: EtherCATRxVar15_P1_ks
   * Referenced by: '<S39>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_ks[2];

  /* Computed Parameter: EtherCATRxVar15_P1_a
   * Referenced by: '<S39>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_a[61];

  /* Computed Parameter: EtherCATRxVar15_P2__a
   * Referenced by: '<S39>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2__a[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_l;

  /* Computed Parameter: EtherCATRxVar16_P1_iu
   * Referenced by: '<S39>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_iu[2];

  /* Computed Parameter: EtherCATRxVar16_P1_d
   * Referenced by: '<S39>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_d[61];

  /* Computed Parameter: EtherCATRxVar16_P2_Si
   * Referenced by: '<S39>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2;

  /* Computed Parameter: EtherCATRxVar17_P1__f
   * Referenced by: '<S39>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1__f[2];

  /* Computed Parameter: EtherCATRxVar17_P1_g
   * Referenced by: '<S39>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_g[61];

  /* Computed Parameter: EtherCATRxVar17_P2__b
   * Referenced by: '<S39>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2__b[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2_e;

  /* Computed Parameter: EtherCATRxVar12_P1__c
   * Referenced by: '<S41>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1__c[2];

  /* Computed Parameter: EtherCATRxVar12_P1_f
   * Referenced by: '<S41>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_f[61];

  /* Computed Parameter: EtherCATRxVar12_P2__b
   * Referenced by: '<S41>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2__b[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_j;

  /* Computed Parameter: EtherCATRxVar13_P1__p
   * Referenced by: '<S41>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1__p[2];

  /* Computed Parameter: EtherCATRxVar13_P1_j
   * Referenced by: '<S41>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1_j[61];

  /* Computed Parameter: EtherCATRxVar13_P2__i
   * Referenced by: '<S41>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2__i[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_h;

  /* Computed Parameter: EtherCATRxVar14_P1_ap
   * Referenced by: '<S41>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1_ap[2];

  /* Computed Parameter: EtherCATRxVar14_P1_g
   * Referenced by: '<S41>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1_g[61];

  /* Computed Parameter: EtherCATRxVar14_P2__i
   * Referenced by: '<S41>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2__i[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_n;

  /* Computed Parameter: EtherCATRxVar15_P1_cb
   * Referenced by: '<S41>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_cb[2];

  /* Computed Parameter: EtherCATRxVar15_P1_h
   * Referenced by: '<S41>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_h[61];

  /* Computed Parameter: EtherCATRxVar15_P2__f
   * Referenced by: '<S41>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2__f[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_a;

  /* Computed Parameter: EtherCATRxVar16_P1_ih
   * Referenced by: '<S41>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_ih[2];

  /* Computed Parameter: EtherCATRxVar16_P1_l
   * Referenced by: '<S41>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_l[61];

  /* Computed Parameter: EtherCATRxVar16_P2__k
   * Referenced by: '<S41>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2__k[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2_m;

  /* Computed Parameter: EtherCATRxVar17_P1__a
   * Referenced by: '<S41>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1__a[2];

  /* Computed Parameter: EtherCATRxVar17_P1_l
   * Referenced by: '<S41>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_l[61];

  /* Computed Parameter: EtherCATRxVar17_P2__p
   * Referenced by: '<S41>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2__p[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2_n;

  /* Computed Parameter: EtherCATRxVar12_P1__m
   * Referenced by: '<S32>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1__m[2];

  /* Computed Parameter: EtherCATRxVar12_P1_h
   * Referenced by: '<S32>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_h[61];

  /* Computed Parameter: EtherCATRxVar12_P2_bx
   * Referenced by: '<S32>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_bx[2];

  /* Expression: sig_offset
   * Referenced by: '<S32>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_b;

  /* Computed Parameter: EtherCATRxVar13_P1_p5
   * Referenced by: '<S32>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1_p5[2];

  /* Computed Parameter: EtherCATRxVar13_P1_d
   * Referenced by: '<S32>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1_d[61];

  /* Computed Parameter: EtherCATRxVar13_P2_ib
   * Referenced by: '<S32>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_ib[2];

  /* Expression: sig_offset
   * Referenced by: '<S32>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_o;

  /* Computed Parameter: EtherCATRxVar14_P1__l
   * Referenced by: '<S32>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1__l[2];

  /* Computed Parameter: EtherCATRxVar14_P1_o
   * Referenced by: '<S32>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1_o[61];

  /* Computed Parameter: EtherCATRxVar14_P2__l
   * Referenced by: '<S32>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2__l[2];

  /* Expression: sig_offset
   * Referenced by: '<S32>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_pr;

  /* Computed Parameter: EtherCATRxVar12_P1__o
   * Referenced by: '<S38>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1__o[2];

  /* Computed Parameter: EtherCATRxVar12_P1_p
   * Referenced by: '<S38>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_p[61];

  /* Computed Parameter: EtherCATRxVar12_P2__j
   * Referenced by: '<S38>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2__j[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_k;

  /* Computed Parameter: EtherCATRxVar13_P1_pb
   * Referenced by: '<S38>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1_pb[2];

  /* Computed Parameter: EtherCATRxVar13_P_ek
   * Referenced by: '<S38>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P_ek[61];

  /* Computed Parameter: EtherCATRxVar13_P2_dd
   * Referenced by: '<S38>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_dd[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_c;

  /* Computed Parameter: EtherCATRxVar14_P1__p
   * Referenced by: '<S38>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1__p[2];

  /* Computed Parameter: EtherCATRxVar14_P1_n
   * Referenced by: '<S38>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1_n[61];

  /* Computed Parameter: EtherCATRxVar14_P2__g
   * Referenced by: '<S38>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2__g[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_c;

  /* Computed Parameter: EtherCATRxVar15_P1__l
   * Referenced by: '<S38>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1__l[2];

  /* Computed Parameter: EtherCATRxVar15_P1_k
   * Referenced by: '<S38>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_k[61];

  /* Computed Parameter: EtherCATRxVar15_P2__j
   * Referenced by: '<S38>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2__j[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_iy;

  /* Computed Parameter: EtherCATRxVar16_P1__d
   * Referenced by: '<S38>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1__d[2];

  /* Computed Parameter: EtherCATRxVar16_P1_h
   * Referenced by: '<S38>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_h[61];

  /* Computed Parameter: EtherCATRxVar16_P2__e
   * Referenced by: '<S38>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2__e[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2_l;

  /* Computed Parameter: EtherCATRxVar17_P1__i
   * Referenced by: '<S38>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1__i[2];

  /* Computed Parameter: EtherCATRxVar17_P1_h
   * Referenced by: '<S38>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_h[61];

  /* Computed Parameter: EtherCATRxVar17_P2__h
   * Referenced by: '<S38>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2__h[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2_h;

  /* Computed Parameter: EtherCATRxVar12_P1__d
   * Referenced by: '<S40>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1__d[2];

  /* Computed Parameter: EtherCATRxVar12_P_fu
   * Referenced by: '<S40>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P_fu[61];

  /* Computed Parameter: EtherCATRxVar12_P2__g
   * Referenced by: '<S40>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2__g[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_d;

  /* Computed Parameter: EtherCATRxVar13_P1__m
   * Referenced by: '<S40>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1__m[2];

  /* Computed Parameter: EtherCATRxVar13_P1_b
   * Referenced by: '<S40>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1_b[61];

  /* Computed Parameter: EtherCATRxVar13_P2__m
   * Referenced by: '<S40>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2__m[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_i;

  /* Computed Parameter: EtherCATRxVar14_P1__n
   * Referenced by: '<S40>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1__n[2];

  /* Computed Parameter: EtherCATRxVar14_P_n4
   * Referenced by: '<S40>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P_n4[61];

  /* Computed Parameter: EtherCATRxVar14_P2_ib
   * Referenced by: '<S40>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_ib[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_h;

  /* Computed Parameter: EtherCATRxVar15_P1__d
   * Referenced by: '<S40>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1__d[2];

  /* Computed Parameter: EtherCATRxVar15_P1_d
   * Referenced by: '<S40>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P1_d[61];

  /* Computed Parameter: EtherCATRxVar15_P2__m
   * Referenced by: '<S40>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2__m[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 15'
   */
  real_T EtherCATRxVar15_P2_ak;

  /* Computed Parameter: EtherCATRxVar16_P1__p
   * Referenced by: '<S40>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1__p[2];

  /* Computed Parameter: EtherCATRxVar16_P1_p
   * Referenced by: '<S40>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1_p[61];

  /* Computed Parameter: EtherCATRxVar16_P2__o
   * Referenced by: '<S40>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2__o[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P2_p;

  /* Computed Parameter: EtherCATRxVar17_P1__p
   * Referenced by: '<S40>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1__p[2];

  /* Computed Parameter: EtherCATRxVar17_P1_j
   * Referenced by: '<S40>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_j[61];

  /* Computed Parameter: EtherCATRxVar17_P2__e
   * Referenced by: '<S40>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2__e[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P2_a;

  /* Computed Parameter: EtherCATRxVar12_P1__a
   * Referenced by: '<S31>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1__a[2];

  /* Computed Parameter: EtherCATRxVar12_P1_k
   * Referenced by: '<S31>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_k[61];

  /* Computed Parameter: EtherCATRxVar12_P2__c
   * Referenced by: '<S31>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2__c[2];

  /* Expression: sig_offset
   * Referenced by: '<S31>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_p;

  /* Computed Parameter: EtherCATRxVar13_P1__b
   * Referenced by: '<S31>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1__b[2];

  /* Computed Parameter: EtherCATRxVar13_P1_l
   * Referenced by: '<S31>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P1_l[61];

  /* Computed Parameter: EtherCATRxVar13_P2__f
   * Referenced by: '<S31>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2__f[2];

  /* Expression: sig_offset
   * Referenced by: '<S31>/EtherCAT Rx Var 13'
   */
  real_T EtherCATRxVar13_P2_o3;

  /* Computed Parameter: EtherCATRxVar14_P1__b
   * Referenced by: '<S31>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1__b[2];

  /* Computed Parameter: EtherCATRxVar14_P1_m
   * Referenced by: '<S31>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P1_m[61];

  /* Computed Parameter: EtherCATRxVar14_P2__f
   * Referenced by: '<S31>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2__f[2];

  /* Expression: sig_offset
   * Referenced by: '<S31>/EtherCAT Rx Var 14'
   */
  real_T EtherCATRxVar14_P2_f;

  /* Expression: zeros(30,1)
   * Referenced by: '<S21>/Discrete Filter'
   */
  real_T DiscreteFilter_Initi[30];

  /* Computed Parameter: EtherCATPDOReceive_P1
   * Referenced by: '<S64>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_P1[2];

  /* Computed Parameter: EtherCATPDOReceive_P
   * Referenced by: '<S64>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_P[33];

  /* Computed Parameter: EtherCATPDOReceive_P2
   * Referenced by: '<S64>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_P2[2];

  /* Expression: sig_offset
   * Referenced by: '<S64>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_P2_c;

  /* Computed Parameter: EtherCATPDOReceive__f
   * Referenced by: '<S100>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive__f[2];

  /* Computed Parameter: EtherCATPDOReceive_p
   * Referenced by: '<S100>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_p[33];

  /* Computed Parameter: EtherCATPDOReceive__e
   * Referenced by: '<S100>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive__e[2];

  /* Expression: sig_offset
   * Referenced by: '<S100>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_P2_f;

  /* Computed Parameter: EtherCATPDOReceive__g
   * Referenced by: '<S46>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive__g[2];

  /* Computed Parameter: EtherCATPDOReceive_n
   * Referenced by: '<S46>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_n[33];

  /* Computed Parameter: EtherCATPDOReceive__l
   * Referenced by: '<S46>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive__l[2];

  /* Expression: sig_offset
   * Referenced by: '<S46>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_P2_i;

  /* Computed Parameter: EtherCATPDOReceive__p
   * Referenced by: '<S82>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive__p[2];

  /* Computed Parameter: EtherCATPDOReceive_f
   * Referenced by: '<S82>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_f[33];

  /* Computed Parameter: EtherCATPDOReceive__k
   * Referenced by: '<S82>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive__k[2];

  /* Expression: sig_offset
   * Referenced by: '<S82>/EtherCAT PDO Receive'
   */
  real_T EtherCATPDOReceive_P2_n;

  /* Computed Parameter: EtherCATPDOReceive3_P
   * Referenced by: '<S64>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_P[2];

  /* Computed Parameter: EtherCATPDOReceive3_
   * Referenced by: '<S64>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_[33];

  /* Computed Parameter: EtherCATPDOReceive3_i
   * Referenced by: '<S64>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_i[2];

  /* Expression: sig_offset
   * Referenced by: '<S64>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_P2;

  /* Computed Parameter: EtherCATPDOReceive3_l
   * Referenced by: '<S100>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_l[2];

  /* Computed Parameter: EtherCATPDOReceive_o
   * Referenced by: '<S100>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive_o[33];

  /* Computed Parameter: EtherCATPDOReceive3_e
   * Referenced by: '<S100>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_e[2];

  /* Expression: sig_offset
   * Referenced by: '<S100>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_P2_b;

  /* Computed Parameter: EtherCATPDOReceive3_c
   * Referenced by: '<S46>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_c[2];

  /* Computed Parameter: EtherCATPDOReceive_c
   * Referenced by: '<S46>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive_c[33];

  /* Computed Parameter: EtherCATPDOReceive_ef
   * Referenced by: '<S46>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive_ef[2];

  /* Expression: sig_offset
   * Referenced by: '<S46>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_P2_h;

  /* Computed Parameter: EtherCATPDOReceive_e4
   * Referenced by: '<S82>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive_e4[2];

  /* Computed Parameter: EtherCATPDOReceive_m
   * Referenced by: '<S82>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive_m[33];

  /* Computed Parameter: EtherCATPDOReceive3_m
   * Referenced by: '<S82>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_m[2];

  /* Expression: sig_offset
   * Referenced by: '<S82>/EtherCAT PDO Receive3'
   */
  real_T EtherCATPDOReceive3_P2_m;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive1'
   */
  real_T pooled77[2];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive1'
   */
  real_T pooled78[35];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Transmit'
   */
  real_T pooled79[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Transmit'
   */
  real_T pooled80;

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S31>/EtherCAT Tx Var 5'
   *   '<S32>/EtherCAT Tx Var 5'
   *   '<S38>/EtherCAT Tx Var 5'
   *   '<S39>/EtherCAT Tx Var 5'
   *   '<S40>/EtherCAT Tx Var 5'
   *   '<S41>/EtherCAT Tx Var 5'
   *   '<S46>/EtherCAT PDO Receive1'
   *   '<S46>/EtherCAT PDO Receive4'
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S64>/EtherCAT PDO Receive4'
   *   '<S82>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive4'
   *   '<S100>/EtherCAT PDO Receive1'
   *   '<S100>/EtherCAT PDO Receive4'
   */
  real_T pooled81[2];

  /* Pooled Parameter (Expression: sig_type)
   * Referenced by:
   *   '<S31>/EtherCAT Tx Var 5'
   *   '<S32>/EtherCAT Tx Var 5'
   *   '<S38>/EtherCAT Tx Var 5'
   *   '<S39>/EtherCAT Tx Var 5'
   *   '<S40>/EtherCAT Tx Var 5'
   *   '<S41>/EtherCAT Tx Var 5'
   *   '<S46>/EtherCAT PDO Receive1'
   *   '<S46>/EtherCAT PDO Receive4'
   *   '<S64>/EtherCAT PDO Receive1'
   *   '<S64>/EtherCAT PDO Receive4'
   *   '<S82>/EtherCAT PDO Receive1'
   *   '<S82>/EtherCAT PDO Receive4'
   *   '<S100>/EtherCAT PDO Receive1'
   *   '<S100>/EtherCAT PDO Receive4'
   */
  real_T pooled82;

  /* Computed Parameter: EtherCATPDOReceive1_P
   * Referenced by: '<S100>/EtherCAT PDO Receive1'
   */
  real_T EtherCATPDOReceive1_P[2];

  /* Computed Parameter: EtherCATPDOReceive1_
   * Referenced by: '<S100>/EtherCAT PDO Receive1'
   */
  real_T EtherCATPDOReceive1_[35];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S100>/EtherCAT PDO Receive1'
   *   '<S100>/EtherCAT PDO Transmit'
   */
  real_T pooled83[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S100>/EtherCAT PDO Receive1'
   *   '<S100>/EtherCAT PDO Transmit'
   */
  real_T pooled84;

  /* Computed Parameter: EtherCATPDOReceive1_b
   * Referenced by: '<S46>/EtherCAT PDO Receive1'
   */
  real_T EtherCATPDOReceive1_b[2];

  /* Computed Parameter: EtherCATPDOReceive_j
   * Referenced by: '<S46>/EtherCAT PDO Receive1'
   */
  real_T EtherCATPDOReceive_j[35];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S46>/EtherCAT PDO Receive1'
   *   '<S46>/EtherCAT PDO Transmit'
   */
  real_T pooled85[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S46>/EtherCAT PDO Receive1'
   *   '<S46>/EtherCAT PDO Transmit'
   */
  real_T pooled86;

  /* Computed Parameter: EtherCATPDOReceive4_P
   * Referenced by: '<S64>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive4_P[2];

  /* Computed Parameter: EtherCATPDOReceive4_
   * Referenced by: '<S64>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive4_[35];

  /* Computed Parameter: EtherCATPDOReceive4_l
   * Referenced by: '<S64>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive4_l[2];

  /* Expression: sig_offset
   * Referenced by: '<S64>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive4_P2;

  /* Computed Parameter: EtherCATPDOReceive4_i
   * Referenced by: '<S100>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive4_i[2];

  /* Computed Parameter: EtherCATPDOReceiv_pe
   * Referenced by: '<S100>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceiv_pe[35];

  /* Computed Parameter: EtherCATPDOReceive4_p
   * Referenced by: '<S100>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive4_p[2];

  /* Expression: sig_offset
   * Referenced by: '<S100>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive4_P2_n;

  /* Computed Parameter: EtherCATPDOReceive4_d
   * Referenced by: '<S46>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive4_d[2];

  /* Computed Parameter: EtherCATPDOReceive_g
   * Referenced by: '<S46>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive_g[35];

  /* Computed Parameter: EtherCATPDOReceive_ie
   * Referenced by: '<S46>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive_ie[2];

  /* Expression: sig_offset
   * Referenced by: '<S46>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive4_P2_h;

  /* Computed Parameter: EtherCATPDOReceive4_e
   * Referenced by: '<S82>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive4_e[2];

  /* Computed Parameter: EtherCATPDOReceiv_oa
   * Referenced by: '<S82>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceiv_oa[35];

  /* Computed Parameter: EtherCATPDOReceive4_b
   * Referenced by: '<S82>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive4_b[2];

  /* Expression: sig_offset
   * Referenced by: '<S82>/EtherCAT PDO Receive4'
   */
  real_T EtherCATPDOReceive4_P2_nx;

  /* Computed Parameter: EtherCATPDOReceive5_P
   * Referenced by: '<S64>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_P[2];

  /* Computed Parameter: EtherCATPDOReceive5_
   * Referenced by: '<S64>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_[25];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S64>/EtherCAT PDO Receive5'
   *   '<S64>/EtherCAT PDO Transmit1'
   */
  real_T pooled87[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S64>/EtherCAT PDO Receive5'
   *   '<S64>/EtherCAT PDO Transmit1'
   */
  real_T pooled88;

  /* Computed Parameter: EtherCATPDOReceive5_p
   * Referenced by: '<S100>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_p[2];

  /* Computed Parameter: EtherCATPDOReceiv_nt
   * Referenced by: '<S100>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceiv_nt[25];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S100>/EtherCAT PDO Receive5'
   *   '<S100>/EtherCAT PDO Transmit1'
   */
  real_T pooled89[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S100>/EtherCAT PDO Receive5'
   *   '<S100>/EtherCAT PDO Transmit1'
   */
  real_T pooled90;

  /* Computed Parameter: EtherCATPDOReceive5_h
   * Referenced by: '<S46>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive5_h[2];

  /* Computed Parameter: EtherCATPDOReceive_d
   * Referenced by: '<S46>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive_d[25];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S46>/EtherCAT PDO Receive5'
   *   '<S46>/EtherCAT PDO Transmit1'
   */
  real_T pooled91[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S46>/EtherCAT PDO Receive5'
   *   '<S46>/EtherCAT PDO Transmit1'
   */
  real_T pooled92;

  /* Computed Parameter: EtherCATPDOReceive_hn
   * Referenced by: '<S82>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceive_hn[2];

  /* Computed Parameter: EtherCATPDOReceiv_p2
   * Referenced by: '<S82>/EtherCAT PDO Receive5'
   */
  real_T EtherCATPDOReceiv_p2[25];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S82>/EtherCAT PDO Receive5'
   *   '<S82>/EtherCAT PDO Transmit1'
   */
  real_T pooled93[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S82>/EtherCAT PDO Receive5'
   *   '<S82>/EtherCAT PDO Transmit1'
   */
  real_T pooled94;

  /* Computed Parameter: EtherCATRxVar6_P1_S_o
   * Referenced by: '<S39>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_S_o[2];

  /* Computed Parameter: EtherCATRxVar6_P1_e
   * Referenced by: '<S39>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_e[76];

  /* Computed Parameter: EtherCATRxVar6_P2_S_c
   * Referenced by: '<S39>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_S_c[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_g;

  /* Computed Parameter: EtherCATRxVar7_P1_S_e
   * Referenced by: '<S39>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_S_e[2];

  /* Computed Parameter: EtherCATRxVar7_P1_f
   * Referenced by: '<S39>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_f[76];

  /* Computed Parameter: EtherCATRxVar7_P2_S_n
   * Referenced by: '<S39>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_S_n[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_j;

  /* Computed Parameter: EtherCATRxVar6_P1_S_g
   * Referenced by: '<S41>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_S_g[2];

  /* Computed Parameter: EtherCATRxVar6_P1_k
   * Referenced by: '<S41>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_k[76];

  /* Computed Parameter: EtherCATRxVar6_P2_S_l
   * Referenced by: '<S41>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_S_l[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_c;

  /* Computed Parameter: EtherCATRxVar7_P1_S_d
   * Referenced by: '<S41>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_S_d[2];

  /* Computed Parameter: EtherCATRxVar7_P1_n
   * Referenced by: '<S41>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_n[76];

  /* Computed Parameter: EtherCATRxVar7_P2_S_p
   * Referenced by: '<S41>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_S_p[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_n;

  /* Computed Parameter: EtherCATRxVar_P1_Si_e
   * Referenced by: '<S32>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_Si_e[2];

  /* Computed Parameter: EtherCATRxVar_P1_en
   * Referenced by: '<S32>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_en[74];

  /* Computed Parameter: EtherCATRxVar_P2_Si_a
   * Referenced by: '<S32>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_Si_a[2];

  /* Expression: sig_offset
   * Referenced by: '<S32>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_h;

  /* Computed Parameter: EtherCATRxVar6_P1_S_i
   * Referenced by: '<S38>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_S_i[2];

  /* Computed Parameter: EtherCATRxVar6_P1_d
   * Referenced by: '<S38>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_d[76];

  /* Computed Parameter: EtherCATRxVar6_P2_S_o
   * Referenced by: '<S38>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_S_o[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_h;

  /* Computed Parameter: EtherCATRxVar7_P1_S_m
   * Referenced by: '<S38>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_S_m[2];

  /* Computed Parameter: EtherCATRxVar7_P1_h
   * Referenced by: '<S38>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_h[76];

  /* Computed Parameter: EtherCATRxVar7_P2_S_f
   * Referenced by: '<S38>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_S_f[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_p;

  /* Computed Parameter: EtherCATRxVar6_P1__ie
   * Referenced by: '<S40>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1__ie[2];

  /* Computed Parameter: EtherCATRxVar6_P1_c
   * Referenced by: '<S40>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_c[76];

  /* Computed Parameter: EtherCATRxVar6_P2_S_e
   * Referenced by: '<S40>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_S_e[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_l;

  /* Computed Parameter: EtherCATRxVar7_P1_S_p
   * Referenced by: '<S40>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_S_p[2];

  /* Computed Parameter: EtherCATRxVar7_P1_o
   * Referenced by: '<S40>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P1_o[76];

  /* Computed Parameter: EtherCATRxVar7_P2_S_b
   * Referenced by: '<S40>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_S_b[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 7'
   */
  real_T EtherCATRxVar7_P2_d;

  /* Computed Parameter: EtherCATRxVar_P1_Si_d
   * Referenced by: '<S31>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_Si_d[2];

  /* Computed Parameter: EtherCATRxVar_P1_j
   * Referenced by: '<S31>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P1_j[74];

  /* Computed Parameter: EtherCATRxVar_P2_Si_n
   * Referenced by: '<S31>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_Si_n[2];

  /* Expression: sig_offset
   * Referenced by: '<S31>/EtherCAT Rx Var '
   */
  real_T EtherCATRxVar_P2_f;

  /* Computed Parameter: EtherCATRxVar10_P1__i
   * Referenced by: '<S39>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1__i[2];

  /* Computed Parameter: EtherCATRxVar10_P1_e
   * Referenced by: '<S39>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1_e[56];

  /* Computed Parameter: EtherCATRxVar10_P2__d
   * Referenced by: '<S39>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2__d[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2_n;

  /* Computed Parameter: EtherCATRxVar10_P1__o
   * Referenced by: '<S41>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1__o[2];

  /* Computed Parameter: EtherCATRxVar10_P_eu
   * Referenced by: '<S41>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P_eu[56];

  /* Computed Parameter: EtherCATRxVar10_P2__b
   * Referenced by: '<S41>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2__b[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2_e;

  /* Computed Parameter: EtherCATRxVar6_P1_S_p
   * Referenced by: '<S32>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_S_p[2];

  /* Computed Parameter: EtherCATRxVar6_P1_cf
   * Referenced by: '<S32>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_cf[56];

  /* Computed Parameter: EtherCATRxVar6_P2__ce
   * Referenced by: '<S32>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2__ce[2];

  /* Expression: sig_offset
   * Referenced by: '<S32>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_j;

  /* Computed Parameter: EtherCATRxVar10_P1__g
   * Referenced by: '<S38>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1__g[2];

  /* Computed Parameter: EtherCATRxVar10_P1_i
   * Referenced by: '<S38>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1_i[56];

  /* Computed Parameter: EtherCATRxVar10_P2__o
   * Referenced by: '<S38>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2__o[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2_nd;

  /* Computed Parameter: EtherCATRxVar10_P1_ib
   * Referenced by: '<S40>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1_ib[2];

  /* Computed Parameter: EtherCATRxVar10_P1_h
   * Referenced by: '<S40>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P1_h[56];

  /* Computed Parameter: EtherCATRxVar10_P2__a
   * Referenced by: '<S40>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2__a[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 10'
   */
  real_T EtherCATRxVar10_P2_m;

  /* Computed Parameter: EtherCATRxVar6_P1_S_j
   * Referenced by: '<S31>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_S_j[2];

  /* Computed Parameter: EtherCATRxVar6_P1_ex
   * Referenced by: '<S31>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P1_ex[56];

  /* Computed Parameter: EtherCATRxVar6_P2_S_k
   * Referenced by: '<S31>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_S_k[2];

  /* Expression: sig_offset
   * Referenced by: '<S31>/EtherCAT Rx Var 6'
   */
  real_T EtherCATRxVar6_P2_o;

  /* Computed Parameter: EtherCATRxVar11_P1_Si
   * Referenced by: '<S39>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar11_P1
   * Referenced by: '<S39>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1[56];

  /* Computed Parameter: EtherCATRxVar11_P2_Si
   * Referenced by: '<S39>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2;

  /* Computed Parameter: EtherCATRxVar11_P1__m
   * Referenced by: '<S41>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1__m[2];

  /* Computed Parameter: EtherCATRxVar11_P1_n
   * Referenced by: '<S41>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1_n[56];

  /* Computed Parameter: EtherCATRxVar11_P2__m
   * Referenced by: '<S41>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2__m[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2_e;

  /* Computed Parameter: EtherCATRxVar1_P1_S_h
   * Referenced by: '<S32>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_S_h[2];

  /* Computed Parameter: EtherCATRxVar1_P1_p
   * Referenced by: '<S32>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_p[56];

  /* Computed Parameter: EtherCATRxVar1_P2_S_d
   * Referenced by: '<S32>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_S_d[2];

  /* Expression: sig_offset
   * Referenced by: '<S32>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_b;

  /* Computed Parameter: EtherCATRxVar11_P1__i
   * Referenced by: '<S38>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1__i[2];

  /* Computed Parameter: EtherCATRxVar11_P_ny
   * Referenced by: '<S38>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P_ny[56];

  /* Computed Parameter: EtherCATRxVar11_P2__g
   * Referenced by: '<S38>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2__g[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2_h;

  /* Computed Parameter: EtherCATRxVar11_P1_ic
   * Referenced by: '<S40>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1_ic[2];

  /* Computed Parameter: EtherCATRxVar11_P1_j
   * Referenced by: '<S40>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1_j[56];

  /* Computed Parameter: EtherCATRxVar11_P2__b
   * Referenced by: '<S40>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2__b[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2_n;

  /* Computed Parameter: EtherCATRxVar1_P1_S_d
   * Referenced by: '<S31>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_S_d[2];

  /* Computed Parameter: EtherCATRxVar1_P1_i
   * Referenced by: '<S31>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_i[56];

  /* Computed Parameter: EtherCATRxVar1_P2_S_a
   * Referenced by: '<S31>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_S_a[2];

  /* Expression: sig_offset
   * Referenced by: '<S31>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_k;

  /* Computed Parameter: EtherCATRxVar5_P1_S_l
   * Referenced by: '<S38>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_S_l[2];

  /* Computed Parameter: EtherCATRxVar5_P1_o
   * Referenced by: '<S38>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_o[70];

  /* Computed Parameter: EtherCATRxVar5_P2_S_l
   * Referenced by: '<S38>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_S_l[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_d;

  /* Computed Parameter: EtherCATRxVar5_P1_S_d
   * Referenced by: '<S32>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_S_d[2];

  /* Computed Parameter: EtherCATRxVar5_P1_n
   * Referenced by: '<S32>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_n[86];

  /* Computed Parameter: EtherCATRxVar5_P2_S_o
   * Referenced by: '<S32>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_S_o[2];

  /* Expression: sig_offset
   * Referenced by: '<S32>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_j;

  /* Computed Parameter: EtherCATRxVar3_P1_S_a
   * Referenced by: '<S32>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_S_a[2];

  /* Computed Parameter: EtherCATRxVar3_P1_k
   * Referenced by: '<S32>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_k[58];

  /* Computed Parameter: EtherCATRxVar3_P2_S_d
   * Referenced by: '<S32>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_S_d[2];

  /* Expression: sig_offset
   * Referenced by: '<S32>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_e;

  /* Computed Parameter: EtherCATRxVar9_P1_Siz
   * Referenced by: '<S38>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_Siz[2];

  /* Computed Parameter: EtherCATRxVar9_P1
   * Referenced by: '<S38>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1[74];

  /* Computed Parameter: EtherCATRxVar9_P2_Siz
   * Referenced by: '<S38>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_Siz[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2;

  /* Computed Parameter: EtherCATRxVar17_P1__b
   * Referenced by: '<S32>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1__b[2];

  /* Computed Parameter: EtherCATRxVar17_P1_o
   * Referenced by: '<S32>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_o[58];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S32>/EtherCAT Rx Var 17'
   *   '<S32>/EtherCAT Tx Var 3'
   */
  real_T pooled95[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S32>/EtherCAT Rx Var 17'
   *   '<S32>/EtherCAT Tx Var 3'
   */
  real_T pooled96;

  /* Computed Parameter: EtherCATRxVar1_P1_S_m
   * Referenced by: '<S38>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_S_m[2];

  /* Computed Parameter: EtherCATRxVar1_P1_l
   * Referenced by: '<S38>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_l[86];

  /* Computed Parameter: EtherCATRxVar1_P2_S_p
   * Referenced by: '<S38>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_S_p[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_d;

  /* Computed Parameter: EtherCATRxVar5_P1_S_a
   * Referenced by: '<S31>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_S_a[2];

  /* Computed Parameter: EtherCATRxVar5_P1_oz
   * Referenced by: '<S31>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_oz[86];

  /* Computed Parameter: EtherCATRxVar5_P2_S_m
   * Referenced by: '<S31>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_S_m[2];

  /* Expression: sig_offset
   * Referenced by: '<S31>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_b;

  /* Computed Parameter: EtherCATRxVar3_P1_S_i
   * Referenced by: '<S31>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_S_i[2];

  /* Computed Parameter: EtherCATRxVar3_P1_o
   * Referenced by: '<S31>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_o[58];

  /* Computed Parameter: EtherCATRxVar3_P2_S_n
   * Referenced by: '<S31>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_S_n[2];

  /* Expression: sig_offset
   * Referenced by: '<S31>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_ef;

  /* Computed Parameter: EtherCATRxVar17_P1_bu
   * Referenced by: '<S31>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P1_bu[2];

  /* Computed Parameter: EtherCATRxVar17_P_oy
   * Referenced by: '<S31>/EtherCAT Rx Var 17'
   */
  real_T EtherCATRxVar17_P_oy[58];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 17'
   *   '<S31>/EtherCAT Tx Var 3'
   */
  real_T pooled97[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S31>/EtherCAT Rx Var 17'
   *   '<S31>/EtherCAT Tx Var 3'
   */
  real_T pooled98;

  /* Computed Parameter: EtherCATRxVar16_P1__l
   * Referenced by: '<S33>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P1__l[2];

  /* Computed Parameter: EtherCATRxVar16_P_n0
   * Referenced by: '<S33>/EtherCAT Rx Var 16'
   */
  real_T EtherCATRxVar16_P_n0[70];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S33>/EtherCAT Rx Var 16'
   *   '<S33>/EtherCAT Tx Var '
   */
  real_T pooled99[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S33>/EtherCAT Rx Var 16'
   *   '<S33>/EtherCAT Tx Var '
   */
  real_T pooled100;

  /* Computed Parameter: EtherCATRxVar23_P1_Si
   * Referenced by: '<S38>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar23_P1
   * Referenced by: '<S38>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1[66];

  /* Computed Parameter: EtherCATRxVar23_P2_Si
   * Referenced by: '<S38>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2_Si[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2;

  /* Computed Parameter: EtherCATRxVar2_P1_S_f
   * Referenced by: '<S38>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_S_f[2];

  /* Computed Parameter: EtherCATRxVar2_P1_f
   * Referenced by: '<S38>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_f[60];

  /* Computed Parameter: EtherCATRxVar2_P2_S_n
   * Referenced by: '<S38>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_S_n[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_l;

  /* Computed Parameter: EtherCATRxVar3_P1_S_g
   * Referenced by: '<S38>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_S_g[2];

  /* Computed Parameter: EtherCATRxVar3_P1_os
   * Referenced by: '<S38>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_os[60];

  /* Computed Parameter: EtherCATRxVar3_P2_S_c
   * Referenced by: '<S38>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_S_c[2];

  /* Expression: sig_offset
   * Referenced by: '<S38>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_b;

  /* Computed Parameter: EtherCATRxVar23_P1__o
   * Referenced by: '<S40>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1__o[2];

  /* Computed Parameter: EtherCATRxVar23_P1_l
   * Referenced by: '<S40>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1_l[66];

  /* Computed Parameter: EtherCATRxVar23_P2__d
   * Referenced by: '<S40>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2__d[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2_l;

  /* Computed Parameter: EtherCATRxVar20_P1_Si
   * Referenced by: '<S40>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1_Si[2];

  /* Computed Parameter: EtherCATRxVar20_P1
   * Referenced by: '<S40>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1[58];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S40>/EtherCAT Rx Var 20'
   *   '<S40>/EtherCAT Tx Var 3'
   */
  real_T pooled101[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S40>/EtherCAT Rx Var 20'
   *   '<S40>/EtherCAT Tx Var 3'
   */
  real_T pooled102;

  /* Computed Parameter: EtherCATRxVar5_P1_S_k
   * Referenced by: '<S40>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_S_k[2];

  /* Computed Parameter: EtherCATRxVar5_P1_a
   * Referenced by: '<S40>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_a[70];

  /* Computed Parameter: EtherCATRxVar5_P2_S_f
   * Referenced by: '<S40>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_S_f[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_a;

  /* Computed Parameter: EtherCATRxVar9_P1_S_b
   * Referenced by: '<S40>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_S_b[2];

  /* Computed Parameter: EtherCATRxVar9_P1_p
   * Referenced by: '<S40>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_p[74];

  /* Computed Parameter: EtherCATRxVar9_P2_S_a
   * Referenced by: '<S40>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_S_a[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_d;

  /* Computed Parameter: EtherCATRxVar1_P1_S_p
   * Referenced by: '<S40>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_S_p[2];

  /* Computed Parameter: EtherCATRxVar1_P1_h
   * Referenced by: '<S40>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_h[86];

  /* Computed Parameter: EtherCATRxVar1_P2__az
   * Referenced by: '<S40>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2__az[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_h;

  /* Computed Parameter: EtherCATRxVar2_P1__nz
   * Referenced by: '<S40>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1__nz[2];

  /* Computed Parameter: EtherCATRxVar2_P1_c
   * Referenced by: '<S40>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_c[60];

  /* Computed Parameter: EtherCATRxVar2_P2_S_d
   * Referenced by: '<S40>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_S_d[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_m;

  /* Computed Parameter: EtherCATRxVar3_P1__il
   * Referenced by: '<S40>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1__il[2];

  /* Computed Parameter: EtherCATRxVar3_P1_f
   * Referenced by: '<S40>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_f[60];

  /* Computed Parameter: EtherCATRxVar3_P2__dw
   * Referenced by: '<S40>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2__dw[2];

  /* Expression: sig_offset
   * Referenced by: '<S40>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_a;

  /* Computed Parameter: EtherCATRxVar20_P1__m
   * Referenced by: '<S38>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1__m[2];

  /* Computed Parameter: EtherCATRxVar20_P1_d
   * Referenced by: '<S38>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1_d[58];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S38>/EtherCAT Rx Var 20'
   *   '<S38>/EtherCAT Tx Var 3'
   */
  real_T pooled103[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S38>/EtherCAT Rx Var 20'
   *   '<S38>/EtherCAT Tx Var 3'
   */
  real_T pooled104;

  /* Computed Parameter: EtherCATRxVar23_P1__d
   * Referenced by: '<S39>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1__d[2];

  /* Computed Parameter: EtherCATRxVar23_P1_a
   * Referenced by: '<S39>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1_a[66];

  /* Computed Parameter: EtherCATRxVar23_P2__c
   * Referenced by: '<S39>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2__c[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2_p;

  /* Computed Parameter: EtherCATRxVar20_P1__c
   * Referenced by: '<S39>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1__c[2];

  /* Computed Parameter: EtherCATRxVar20_P1_h
   * Referenced by: '<S39>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1_h[58];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S39>/EtherCAT Rx Var 20'
   *   '<S39>/EtherCAT Tx Var 3'
   */
  real_T pooled105[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S39>/EtherCAT Rx Var 20'
   *   '<S39>/EtherCAT Tx Var 3'
   */
  real_T pooled106;

  /* Computed Parameter: EtherCATRxVar5_P1__k3
   * Referenced by: '<S39>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1__k3[2];

  /* Computed Parameter: EtherCATRxVar5_P1_l
   * Referenced by: '<S39>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_l[70];

  /* Computed Parameter: EtherCATRxVar5_P2_S_k
   * Referenced by: '<S39>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_S_k[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_ax;

  /* Computed Parameter: EtherCATRxVar9_P1_S_c
   * Referenced by: '<S39>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_S_c[2];

  /* Computed Parameter: EtherCATRxVar9_P1_o
   * Referenced by: '<S39>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_o[74];

  /* Computed Parameter: EtherCATRxVar9_P2_S_n
   * Referenced by: '<S39>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_S_n[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_f;

  /* Computed Parameter: EtherCATRxVar1_P1_S_o
   * Referenced by: '<S39>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_S_o[2];

  /* Computed Parameter: EtherCATRxVar1_P1_m
   * Referenced by: '<S39>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_m[86];

  /* Computed Parameter: EtherCATRxVar1_P2_S_j
   * Referenced by: '<S39>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_S_j[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_n;

  /* Computed Parameter: EtherCATRxVar2_P1_S_a
   * Referenced by: '<S39>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_S_a[2];

  /* Computed Parameter: EtherCATRxVar2_P1_c2
   * Referenced by: '<S39>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_c2[60];

  /* Computed Parameter: EtherCATRxVar2_P2_S_i
   * Referenced by: '<S39>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_S_i[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_d;

  /* Computed Parameter: EtherCATRxVar3_P1_S_d
   * Referenced by: '<S39>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_S_d[2];

  /* Computed Parameter: EtherCATRxVar3_P1_l
   * Referenced by: '<S39>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_l[60];

  /* Computed Parameter: EtherCATRxVar3_P2_S_a
   * Referenced by: '<S39>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_S_a[2];

  /* Expression: sig_offset
   * Referenced by: '<S39>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_k;

  /* Computed Parameter: EtherCATRxVar23_P1__n
   * Referenced by: '<S41>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1__n[2];

  /* Computed Parameter: EtherCATRxVar23_P1_o
   * Referenced by: '<S41>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P1_o[66];

  /* Computed Parameter: EtherCATRxVar23_P2__p
   * Referenced by: '<S41>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2__p[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 23'
   */
  real_T EtherCATRxVar23_P2_o;

  /* Computed Parameter: EtherCATRxVar20_P1_mp
   * Referenced by: '<S41>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1_mp[2];

  /* Computed Parameter: EtherCATRxVar20_P1_n
   * Referenced by: '<S41>/EtherCAT Rx Var 20'
   */
  real_T EtherCATRxVar20_P1_n[58];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S41>/EtherCAT Rx Var 20'
   *   '<S41>/EtherCAT Tx Var 3'
   */
  real_T pooled107[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S41>/EtherCAT Rx Var 20'
   *   '<S41>/EtherCAT Tx Var 3'
   */
  real_T pooled108;

  /* Computed Parameter: EtherCATRxVar5_P1_S_b
   * Referenced by: '<S41>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_S_b[2];

  /* Computed Parameter: EtherCATRxVar5_P1_b
   * Referenced by: '<S41>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P1_b[70];

  /* Computed Parameter: EtherCATRxVar5_P2_S_j
   * Referenced by: '<S41>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_S_j[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 5'
   */
  real_T EtherCATRxVar5_P2_ai;

  /* Computed Parameter: EtherCATRxVar9_P1__bg
   * Referenced by: '<S41>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1__bg[2];

  /* Computed Parameter: EtherCATRxVar9_P1_a
   * Referenced by: '<S41>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_a[74];

  /* Computed Parameter: EtherCATRxVar9_P2_S_l
   * Referenced by: '<S41>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_S_l[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_m;

  /* Computed Parameter: EtherCATRxVar1_P1_S_f
   * Referenced by: '<S41>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_S_f[2];

  /* Computed Parameter: EtherCATRxVar1_P1_f
   * Referenced by: '<S41>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P1_f[86];

  /* Computed Parameter: EtherCATRxVar1_P2__dj
   * Referenced by: '<S41>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2__dj[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 1'
   */
  real_T EtherCATRxVar1_P2_bw;

  /* Computed Parameter: EtherCATRxVar2_P1_S_d
   * Referenced by: '<S41>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_S_d[2];

  /* Computed Parameter: EtherCATRxVar2_P1_a
   * Referenced by: '<S41>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P1_a[60];

  /* Computed Parameter: EtherCATRxVar2_P2_S_l
   * Referenced by: '<S41>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_S_l[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 2'
   */
  real_T EtherCATRxVar2_P2_a;

  /* Computed Parameter: EtherCATRxVar3_P1_S_k
   * Referenced by: '<S41>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_S_k[2];

  /* Computed Parameter: EtherCATRxVar3_P1_h
   * Referenced by: '<S41>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P1_h[60];

  /* Computed Parameter: EtherCATRxVar3_P2_S_b
   * Referenced by: '<S41>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_S_b[2];

  /* Expression: sig_offset
   * Referenced by: '<S41>/EtherCAT Rx Var 3'
   */
  real_T EtherCATRxVar3_P2_e4;

  /* Computed Parameter: EtherCATTxVar3_P1_Siz
   * Referenced by: '<S31>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_Siz[2];

  /* Computed Parameter: EtherCATTxVar3_P1
   * Referenced by: '<S31>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1[61];

  /* Computed Parameter: EtherCATTxVar4_P1_Siz
   * Referenced by: '<S31>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_Siz[2];

  /* Computed Parameter: EtherCATTxVar4_P1
   * Referenced by: '<S31>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1[61];

  /* Computed Parameter: EtherCATTxVar5_P1_Siz
   * Referenced by: '<S31>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_Siz[2];

  /* Computed Parameter: EtherCATTxVar5_P1
   * Referenced by: '<S31>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1[67];

  /* Computed Parameter: EtherCATTxVar3_P1_S_i
   * Referenced by: '<S32>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_S_i[2];

  /* Computed Parameter: EtherCATTxVar3_P1_m
   * Referenced by: '<S32>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_m[61];

  /* Computed Parameter: EtherCATTxVar4_P1_S_o
   * Referenced by: '<S32>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_S_o[2];

  /* Computed Parameter: EtherCATTxVar4_P1_f
   * Referenced by: '<S32>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_f[61];

  /* Computed Parameter: EtherCATTxVar5_P1_S_a
   * Referenced by: '<S32>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_S_a[2];

  /* Computed Parameter: EtherCATTxVar5_P1_p
   * Referenced by: '<S32>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_p[67];

  /* Computed Parameter: EtherCATRxVar11_P1__p
   * Referenced by: '<S33>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1__p[2];

  /* Computed Parameter: EtherCATRxVar11_P1_h
   * Referenced by: '<S33>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P1_h[61];

  /* Computed Parameter: EtherCATRxVar11_P2__p
   * Referenced by: '<S33>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2__p[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 11'
   */
  real_T EtherCATRxVar11_P2_d;

  /* Computed Parameter: EtherCATRxVar12_P1__j
   * Referenced by: '<S33>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1__j[2];

  /* Computed Parameter: EtherCATRxVar12_P1_n
   * Referenced by: '<S33>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P1_n[61];

  /* Computed Parameter: EtherCATRxVar12_P2__o
   * Referenced by: '<S33>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2__o[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 12'
   */
  real_T EtherCATRxVar12_P2_a;

  /* Computed Parameter: EtherCATRxVar9_P1_S_j
   * Referenced by: '<S33>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_S_j[2];

  /* Computed Parameter: EtherCATRxVar9_P1_n
   * Referenced by: '<S33>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P1_n[61];

  /* Computed Parameter: EtherCATRxVar9_P2__no
   * Referenced by: '<S33>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2__no[2];

  /* Expression: sig_offset
   * Referenced by: '<S33>/EtherCAT Rx Var 9'
   */
  real_T EtherCATRxVar9_P2_j;

  /* Computed Parameter: EtherCATTxVar_P1_Size
   * Referenced by: '<S33>/EtherCAT Tx Var '
   */
  real_T EtherCATTxVar_P1_Size[2];

  /* Computed Parameter: EtherCATTxVar_P1
   * Referenced by: '<S33>/EtherCAT Tx Var '
   */
  real_T EtherCATTxVar_P1[73];

  /* Computed Parameter: EtherCATTxVar1_P1_Siz
   * Referenced by: '<S33>/EtherCAT Tx Var 1'
   */
  real_T EtherCATTxVar1_P1_Siz[2];

  /* Computed Parameter: EtherCATTxVar1_P1
   * Referenced by: '<S33>/EtherCAT Tx Var 1'
   */
  real_T EtherCATTxVar1_P1[73];

  /* Computed Parameter: EtherCATTxVar2_P1_Siz
   * Referenced by: '<S33>/EtherCAT Tx Var 2'
   */
  real_T EtherCATTxVar2_P1_Siz[2];

  /* Computed Parameter: EtherCATTxVar2_P1
   * Referenced by: '<S33>/EtherCAT Tx Var 2'
   */
  real_T EtherCATTxVar2_P1[73];

  /* Computed Parameter: EtherCATPDOReceive2_P
   * Referenced by: '<S46>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_P[2];

  /* Computed Parameter: EtherCATPDOReceive2_
   * Referenced by: '<S46>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_[39];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S46>/EtherCAT PDO Receive2'
   *   '<S46>/EtherCAT PDO Transmit2'
   */
  real_T pooled109[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S46>/EtherCAT PDO Receive2'
   *   '<S46>/EtherCAT PDO Transmit2'
   */
  real_T pooled110;

  /* Computed Parameter: EtherCATPDOTransmit_P
   * Referenced by: '<S46>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmit_P[2];

  /* Computed Parameter: EtherCATPDOTransmit_
   * Referenced by: '<S46>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmit_[28];

  /* Computed Parameter: EtherCATPDOTransmit1_
   * Referenced by: '<S46>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit1_[2];

  /* Computed Parameter: EtherCATPDOTransmit1
   * Referenced by: '<S46>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit1[27];

  /* Computed Parameter: EtherCATPDOTransmit2_
   * Referenced by: '<S46>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmit2_[2];

  /* Computed Parameter: EtherCATPDOTransmit2
   * Referenced by: '<S46>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmit2[32];

  /* Computed Parameter: EtherCATPDOReceive2_h
   * Referenced by: '<S64>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_h[2];

  /* Computed Parameter: EtherCATPDOReceiv_n1
   * Referenced by: '<S64>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceiv_n1[39];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S64>/EtherCAT PDO Receive2'
   *   '<S64>/EtherCAT PDO Transmit2'
   */
  real_T pooled111[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S64>/EtherCAT PDO Receive2'
   *   '<S64>/EtherCAT PDO Transmit2'
   */
  real_T pooled112;

  /* Computed Parameter: EtherCATPDOTransmit_e
   * Referenced by: '<S64>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmit_e[2];

  /* Computed Parameter: EtherCATPDOTransmi_p
   * Referenced by: '<S64>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmi_p[28];

  /* Computed Parameter: EtherCATPDOTransmit_f
   * Referenced by: '<S64>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmit_f[2];

  /* Expression: sig_offset
   * Referenced by: '<S64>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmit_P2;

  /* Computed Parameter: EtherCATPDOTransmit_d
   * Referenced by: '<S64>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit_d[2];

  /* Computed Parameter: EtherCATPDOTransmi_c
   * Referenced by: '<S64>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmi_c[27];

  /* Computed Parameter: EtherCATPDOTransmi_dz
   * Referenced by: '<S64>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmi_dz[2];

  /* Computed Parameter: EtherCATPDOTransmi_d
   * Referenced by: '<S64>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmi_d[32];

  /* Computed Parameter: EtherCATPDOReceive2_p
   * Referenced by: '<S82>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_p[2];

  /* Computed Parameter: EtherCATPDOReceiv_py
   * Referenced by: '<S82>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceiv_py[39];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S82>/EtherCAT PDO Receive2'
   *   '<S82>/EtherCAT PDO Transmit2'
   */
  real_T pooled113[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S82>/EtherCAT PDO Receive2'
   *   '<S82>/EtherCAT PDO Transmit2'
   */
  real_T pooled114;

  /* Computed Parameter: EtherCATPDOTransmit_a
   * Referenced by: '<S82>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmit_a[2];

  /* Computed Parameter: EtherCATPDOTransmi_a
   * Referenced by: '<S82>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmi_a[28];

  /* Computed Parameter: EtherCATPDOTransmit_n
   * Referenced by: '<S82>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit_n[2];

  /* Computed Parameter: EtherCATPDOTransm_cs
   * Referenced by: '<S82>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransm_cs[27];

  /* Computed Parameter: EtherCATPDOTransmit_k
   * Referenced by: '<S82>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmit_k[2];

  /* Computed Parameter: EtherCATPDOTransmi_n
   * Referenced by: '<S82>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmi_n[32];

  /* Computed Parameter: EtherCATPDOReceive2_c
   * Referenced by: '<S100>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceive2_c[2];

  /* Computed Parameter: EtherCATPDOReceiv_fb
   * Referenced by: '<S100>/EtherCAT PDO Receive2'
   */
  real_T EtherCATPDOReceiv_fb[39];

  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S100>/EtherCAT PDO Receive2'
   *   '<S100>/EtherCAT PDO Transmit2'
   */
  real_T pooled115[2];

  /* Pooled Parameter (Expression: sig_offset)
   * Referenced by:
   *   '<S100>/EtherCAT PDO Receive2'
   *   '<S100>/EtherCAT PDO Transmit2'
   */
  real_T pooled116;

  /* Computed Parameter: EtherCATPDOTransmit_p
   * Referenced by: '<S100>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmit_p[2];

  /* Computed Parameter: EtherCATPDOTransmi_o
   * Referenced by: '<S100>/EtherCAT PDO Transmit'
   */
  real_T EtherCATPDOTransmi_o[28];

  /* Computed Parameter: EtherCATPDOTransmit_i
   * Referenced by: '<S100>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmit_i[2];

  /* Computed Parameter: EtherCATPDOTransmi_h
   * Referenced by: '<S100>/EtherCAT PDO Transmit1'
   */
  real_T EtherCATPDOTransmi_h[27];

  /* Computed Parameter: EtherCATPDOTransmit_h
   * Referenced by: '<S100>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmit_h[2];

  /* Computed Parameter: EtherCATPDOTransmi_m
   * Referenced by: '<S100>/EtherCAT PDO Transmit2'
   */
  real_T EtherCATPDOTransmi_m[32];

  /* Computed Parameter: EtherCATTxVar3_P1__ib
   * Referenced by: '<S38>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1__ib[2];

  /* Computed Parameter: EtherCATTxVar3_P1_f
   * Referenced by: '<S38>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_f[61];

  /* Computed Parameter: EtherCATTxVar4_P1_S_p
   * Referenced by: '<S38>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_S_p[2];

  /* Computed Parameter: EtherCATTxVar4_P1_d
   * Referenced by: '<S38>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_d[61];

  /* Computed Parameter: EtherCATTxVar5_P1_S_m
   * Referenced by: '<S38>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_S_m[2];

  /* Computed Parameter: EtherCATTxVar5_P1_h
   * Referenced by: '<S38>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_h[67];

  /* Computed Parameter: EtherCATTxVar3_P1_S_f
   * Referenced by: '<S39>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_S_f[2];

  /* Computed Parameter: EtherCATTxVar3_P1_g
   * Referenced by: '<S39>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_g[61];

  /* Computed Parameter: EtherCATTxVar4_P1_S_i
   * Referenced by: '<S39>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_S_i[2];

  /* Computed Parameter: EtherCATTxVar4_P1_i
   * Referenced by: '<S39>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_i[61];

  /* Computed Parameter: EtherCATTxVar5_P1_S_o
   * Referenced by: '<S39>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_S_o[2];

  /* Computed Parameter: EtherCATTxVar5_P1_hr
   * Referenced by: '<S39>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_hr[67];

  /* Computed Parameter: EtherCATTxVar3_P1_S_g
   * Referenced by: '<S40>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_S_g[2];

  /* Computed Parameter: EtherCATTxVar3_P1_ga
   * Referenced by: '<S40>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_ga[61];

  /* Computed Parameter: EtherCATTxVar4_P1_S_m
   * Referenced by: '<S40>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_S_m[2];

  /* Computed Parameter: EtherCATTxVar4_P1_g
   * Referenced by: '<S40>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_g[61];

  /* Computed Parameter: EtherCATTxVar5_P1_S_h
   * Referenced by: '<S40>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_S_h[2];

  /* Computed Parameter: EtherCATTxVar5_P1_n
   * Referenced by: '<S40>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_n[67];

  /* Computed Parameter: EtherCATTxVar3_P1__iy
   * Referenced by: '<S41>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1__iy[2];

  /* Computed Parameter: EtherCATTxVar3_P1_mo
   * Referenced by: '<S41>/EtherCAT Tx Var 3'
   */
  real_T EtherCATTxVar3_P1_mo[61];

  /* Computed Parameter: EtherCATTxVar4_P1_S_e
   * Referenced by: '<S41>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_S_e[2];

  /* Computed Parameter: EtherCATTxVar4_P1_l
   * Referenced by: '<S41>/EtherCAT Tx Var 4'
   */
  real_T EtherCATTxVar4_P1_l[61];

  /* Computed Parameter: EtherCATTxVar5_P1_S_j
   * Referenced by: '<S41>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_S_j[2];

  /* Computed Parameter: EtherCATTxVar5_P1_k
   * Referenced by: '<S41>/EtherCAT Tx Var 5'
   */
  real_T EtherCATTxVar5_P1_k[67];

  /* Computed Parameter: GetOverloadCounter1_P
   * Referenced by: '<S1>/Get Overload Counter 1'
   */
  real_T GetOverloadCounter1_P[2];

  /* Expression: ts
   * Referenced by: '<S1>/Get Overload Counter 1'
   */
  real_T GetOverloadCounter1_P1;

  /* Computed Parameter: GetOverloadCounter2_P
   * Referenced by: '<S1>/Get Overload Counter 2'
   */
  real_T GetOverloadCounter2_P[2];

  /* Expression: ts
   * Referenced by: '<S1>/Get Overload Counter 2'
   */
  real_T GetOverloadCounter2_P1;

  /* Pooled Parameter (Mixed Expressions)
   * Referenced by:
   *   '<S4>/Resettable Delay'
   *   '<S193>/Constant'
   */
  uint32_T pooled117;

  /* Pooled Parameter (Expression: 4)
   * Referenced by:
   *   '<S34>/ModeOfOperation'
   *   '<S35>/ModeOfOperation'
   *   '<S36>/ModeOfOperation'
   *   '<S37>/ModeOfOperation'
   */
  int8_T pooled130;
} ConstP_Walking01_withElmos_T;

/* Constant parameters with dynamic initialization (auto storage) */
typedef struct {
  /* Expression: EncoderAngleLimits
   * Referenced by: '<S13>/EncoderAngleLimits'
   */
  real_T EncoderAngleLimits_V[38];
} ConstInitP_Walking01_withElmos_T;

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T q[13];                        /* '<Root>/q' */
  real_T dq[13];                       /* '<Root>/dq' */
  real_T u[6];                         /* '<Root>/u' */
  real_T y[6];                         /* '<Root>/y' */
  real_T dy[6];                        /* '<Root>/dy' */
  real_T hd[6];                        /* '<Root>/hd' */
  real_T s;                            /* '<Root>/s' */
  real_T s_unsaturated;                /* '<Root>/s_unsaturated' */
  real_T ds;                           /* '<Root>/ds' */
  real_T theta;                        /* '<Root>/theta' */
  real_T phi;                          /* '<Root>/phi' */
  real_T r;                            /* '<Root>/r' */
  real_T hdbar[6];                     /* '<Root>/hdbar' */
  real_T ControlState[7];              /* '<Root>/ControlState' */
  real_T SerialOut[5];                 /* '<Root>/SerialOut' */
  real_T u_star[6];                    /* '<Root>/u_star' */
  real_T u_pd[6];                      /* '<Root>/u_pd' */
  real_T Switches;                     /* '<Root>/Switches' */
  real_T MedullaState[7];              /* '<Root>/MedullaState' */
  real_T ErrorFlags[7];                /* '<Root>/ErrorFlags' */
  real_T Counters[7];                  /* '<Root>/Counters' */
  real_T EtherCATStatus[6];            /* '<Root>/EtherCATStatus' */
  real_T KVHEulerAngles[3];            /* '<Root>/KVHEulerAngles' */
  real_T KVHEulerAngleDeriv[3];        /* '<Root>/KVHEulerAngleDeriv' */
  real_T KVHStatus;                    /* '<Root>/KVHStatus' */
  real_T KVHSequence[2];               /* '<Root>/KVHSequence' */
  real_T KVHValid;                     /* '<Root>/KVHValid' */
  real_T AnomalyCounts[22];            /* '<Root>/AnomalyCounts' */
  real_T MicrostrainEulerAnglesClean[3];/* '<Root>/MicrostrainEulerAnglesClean' */
  real_T MicrostrainEulerAngleDerivsClea[3];/* '<Root>/MicrostrainEulerAngleDerivsClean' */
  real_T SafetyState;                  /* '<Root>/SafetyState' */
  real_T MotorCurrentSafe[6];          /* '<Root>/MotorCurrentSafe' */
  real_T CPUOverloadRegulator;         /* '<Root>/CPUOverloadRegulator' */
  real_T CPUOverloadCounter[3];        /* '<Root>/CPUOverloadCounter' */
  real_T MedullaCommandSafe;           /* '<Root>/MedullaCommandSafe' */
  real_T FTStatus;                     /* '<Root>/FTStatus' */
  real_T FT;                           /* '<Root>/FT' */
  real_T EncoderAnglesDirty[19];       /* '<Root>/EncoderAnglesDirty' */
  real_T CurrentActual[4];             /* '<Root>/CurrentActual' */
  real_T CurrentDemanded[4];           /* '<Root>/CurrentDemanded' */
  real_T HallPosition[4];              /* '<Root>/HallPosition' */
  real_T HallVelocity[4];              /* '<Root>/HallVelocity' */
  real_T FaultDetected[4];             /* '<Root>/FaultDetected' */
} ExtY_Walking01_withElmos_T;

/* Backward compatible GRT Identifiers */
#define rtB                            Walking01_withElmos_B
#define BlockIO                        B_Walking01_withElmos_T
#define rtY                            Walking01_withElmos_Y
#define ExternalOutputs                ExtY_Walking01_withElmos_T
#define rtP                            Walking01_withElmos_P
#define Parameters                     P_Walking01_withElmos_T
#define rtDWork                        Walking01_withElmos_DW
#define D_Work                         DW_Walking01_withElmos_T
#define tConstBlockIOType              ConstB_Walking01_withElmos_T
#define rtC                            Walking01_withElmos_ConstB
#define ConstParam                     ConstP_Walking01_withElmos_T
#define rtcP                           Walking01_withElmos_ConstP
#define ConstParamWithInit             ConstInitP_Walking01_withElmos_T
#define rtcWithInitP                   Walking01_withElmos_ConstInitP

/* Parameters (auto storage) */
struct P_Walking01_withElmos_T_ {
  real_T AllowDoubleSupport;           /* Variable: AllowDoubleSupport
                                        * Referenced by: '<S201>/AllowDoubleSupport'
                                        */
  real_T CommandSerialize;             /* Variable: CommandSerialize
                                        * Referenced by: '<S202>/CommandSerialize'
                                        */
  real_T ControllerModeInit;           /* Variable: ControllerModeInit
                                        * Referenced by: '<S201>/ControllerModeInit'
                                        */
  real_T DecouplingMode;               /* Variable: DecouplingMode
                                        * Referenced by: '<S201>/DecouplingMode'
                                        */
  real_T DesiredYawOffset;             /* Variable: DesiredYawOffset
                                        * Referenced by: '<S201>/DesiredYawOffset'
                                        */
  real_T EnableFeedforwardOnStep;      /* Variable: EnableFeedforwardOnStep
                                        * Referenced by: '<S201>/EnableFeedforwardOnStep'
                                        */
  real_T EnableTransition;             /* Variable: EnableTransition
                                        * Referenced by: '<S202>/EnableTransition'
                                        */
  real_T EnableVelocityBasedUpdate;    /* Variable: EnableVelocityBasedUpdate
                                        * Referenced by: '<S201>/EnableVelocityBasedUpdate'
                                        */
  real_T ErrorVelZeroFactor[6];        /* Variable: ErrorVelZeroFactor
                                        * Referenced by: '<S201>/ErrorVelZeroFactor'
                                        */
  real_T ErrorZeroFactor[6];           /* Variable: ErrorZeroFactor
                                        * Referenced by: '<S201>/ErrorZeroFactor'
                                        */
  real_T FeedforwardGain[6];           /* Variable: FeedforwardGain
                                        * Referenced by: '<S201>/FeedforwardGain'
                                        */
  real_T GearOffsets[4];               /* Variable: GearOffsets
                                        * Referenced by: '<S5>/GearOffset'
                                        */
  real_T H0Transition[78];             /* Variable: H0Transition
                                        * Referenced by: '<S201>/H0Transition'
                                        */
  real_T H0WalkingDouble[78];          /* Variable: H0WalkingDouble
                                        * Referenced by: '<S201>/H0WalkingDouble'
                                        */
  real_T H0WalkingSingle[78];          /* Variable: H0WalkingSingle
                                        * Referenced by: '<S201>/H0WalkingSingle'
                                        */
  real_T HAlphaStarInjection[36];      /* Variable: HAlphaStarInjection
                                        * Referenced by: '<S201>/HAlphaStarInjection'
                                        */
  real_T HAlphaStarPosing[36];         /* Variable: HAlphaStarPosing
                                        * Referenced by: '<S201>/HAlphaStarPosing'
                                        */
  real_T HAlphaStarTransition[36];     /* Variable: HAlphaStarTransition
                                        * Referenced by: '<S201>/HAlphaStarTransition'
                                        */
  real_T HAlphaStarWalkingDouble[36];  /* Variable: HAlphaStarWalkingDouble
                                        * Referenced by: '<S201>/HAlphaStarDouble'
                                        */
  real_T HAlphaStarWalkingSingle[36];  /* Variable: HAlphaStarWalkingSingle
                                        * Referenced by: '<S201>/HAlphaStarSingle'
                                        */
  real_T HAlphaTransition[36];         /* Variable: HAlphaTransition
                                        * Referenced by: '<S201>/HAlphaTransition'
                                        */
  real_T HAlphaWalkingDouble[36];      /* Variable: HAlphaWalkingDouble
                                        * Referenced by: '<S201>/HAlphaWalkingDouble'
                                        */
  real_T HAlphaWalkingSingle[36];      /* Variable: HAlphaWalkingSingle
                                        * Referenced by: '<S201>/HAlphaWalkingSingle'
                                        */
  real_T HBarAlphaTransition[30];      /* Variable: HBarAlphaTransition
                                        * Referenced by: '<S201>/HBarAlphaTransition'
                                        */
  real_T HBarAlphaWalkingDouble[30];   /* Variable: HBarAlphaWalkingDouble
                                        * Referenced by: '<S201>/HBarAlphaWalkingDouble'
                                        */
  real_T HBarAlphaWalkingSingle[30];   /* Variable: HBarAlphaWalkingSingle
                                        * Referenced by: '<S201>/HBarAlphaWalkingSingle'
                                        */
  real_T HBarLimitsTransition[12];     /* Variable: HBarLimitsTransition
                                        * Referenced by: '<S201>/HBarLimitsTransition'
                                        */
  real_T HBarLimitsWalkingDouble[12];  /* Variable: HBarLimitsWalkingDouble
                                        * Referenced by: '<S201>/HBarLimitsWalkingDouble'
                                        */
  real_T HBarLimitsWalkingSingle[12];  /* Variable: HBarLimitsWalkingSingle
                                        * Referenced by: '<S201>/HBarLimitsWalkingSingle'
                                        */
  real_T IMUCommand;                   /* Variable: IMUCommand
                                        * Referenced by: '<S5>/ResetYaw1'
                                        */
  real_T IMUThreshold;                 /* Variable: IMUThreshold
                                        * Referenced by: '<S13>/IMUThreshold'
                                        */
  real_T IMUTorsoOffsets[2];           /* Variable: IMUTorsoOffsets
                                        * Referenced by: '<S5>/IMUTorsoOffset'
                                        */
  real_T K1MidStanceUpdate[6];         /* Variable: K1MidStanceUpdate
                                        * Referenced by: '<S201>/K1MidStanceUpdate'
                                        */
  real_T K2MidStanceUpdate[6];         /* Variable: K2MidStanceUpdate
                                        * Referenced by: '<S201>/K2MidStanceUpdate'
                                        */
  real_T KASaturationEarly;            /* Variable: KASaturationEarly
                                        * Referenced by: '<S201>/KASaturationEarly'
                                        */
  real_T KASaturationMax;              /* Variable: KASaturationMax
                                        * Referenced by: '<S201>/KASaturationMax'
                                        */
  real_T KASaturationS1;               /* Variable: KASaturationS1
                                        * Referenced by: '<S201>/KASaturationS1'
                                        */
  real_T KASaturationS2;               /* Variable: KASaturationS2
                                        * Referenced by: '<S201>/KASaturationS2'
                                        */
  real_T KASpringOffsets[2];           /* Variable: KASpringOffsets
                                        * Referenced by: '<S202>/StateLogic'
                                        */
  real_T KThetaMinus;                  /* Variable: KThetaMinus
                                        * Referenced by: '<S201>/KThetaMinus'
                                        */
  real_T KThetaPlus;                   /* Variable: KThetaPlus
                                        * Referenced by: '<S201>/KThetaPlus'
                                        */
  real_T LegHipTorqueLimit[2];         /* Variable: LegHipTorqueLimit
                                        * Referenced by: '<S204>/LegHipTorqueSat'
                                        */
  real_T ManualSwap;                   /* Variable: ManualSwap
                                        * Referenced by: '<S202>/ManualSwap'
                                        */
  real_T MaxError;                     /* Variable: MaxError
                                        * Referenced by: '<S201>/MaxError'
                                        */
  real_T MaxErrorVel;                  /* Variable: MaxErrorVel
                                        * Referenced by: '<S201>/MaxErrorVel'
                                        */
  real_T MedullaCommand;               /* Variable: MedullaCommand
                                        * Referenced by: '<S1>/MedullaCommand'
                                        */
  real_T MinDeltaTheta;                /* Variable: MinDeltaTheta
                                        * Referenced by: '<S201>/MinDeltaTheta'
                                        */
  real_T MinDeltaThetaTransition;      /* Variable: MinDeltaThetaTransition
                                        * Referenced by: '<S201>/MinDeltaThetaTransition'
                                        */
  real_T PhiOffset;                    /* Variable: PhiOffset
                                        * Referenced by: '<S201>/PhiOffset'
                                        */
  real_T RLimits[2];                   /* Variable: RLimits
                                        * Referenced by: '<S201>/RLimits'
                                        */
  real_T ResetControl;                 /* Variable: ResetControl
                                        * Referenced by: '<S202>/ResetControl'
                                        */
  real_T RollPhaseVelocityThresh;      /* Variable: RollPhaseVelocityThresh
                                        * Referenced by: '<S201>/RollPhaseVelocityThresh'
                                        */
  real_T RunMode;                      /* Variable: RunMode
                                        * Referenced by: '<S201>/RunMode'
                                        */
  real_T SelectFeedforward;            /* Variable: SelectFeedforward
                                        * Referenced by: '<S201>/SelectFeedforward'
                                        */
  real_T StanceLegInit;                /* Variable: StanceLegInit
                                        * Referenced by: '<S201>/StanceLegInit'
                                        */
  real_T StartSecondGaitOnStep;        /* Variable: StartSecondGaitOnStep
                                        * Referenced by: '<S201>/StartSecondGaitOnStep'
                                        */
  real_T TMaxUpdate;                   /* Variable: TMaxUpdate
                                        * Referenced by: '<S201>/TMaxUpdate'
                                        */
  real_T TPosing;                      /* Variable: TPosing
                                        * Referenced by: '<S201>/TPosing'
                                        */
  real_T Theta0;                       /* Variable: Theta0
                                        * Referenced by: '<S201>/Theta0'
                                        */
  real_T ThetaLimitsTransition[2];     /* Variable: ThetaLimitsTransition
                                        * Referenced by: '<S201>/ThetaLimitsTransition'
                                        */
  real_T ThetaLimitsWalkingDouble[2];  /* Variable: ThetaLimitsWalkingDouble
                                        * Referenced by: '<S201>/ThetaLimitsWalkingDouble'
                                        */
  real_T ThetaLimitsWalkingSingle[2];  /* Variable: ThetaLimitsWalkingSingle
                                        * Referenced by: '<S201>/ThetaLimitsWalkingSingle'
                                        */
  real_T TorsoBackAngle;               /* Variable: TorsoBackAngle
                                        * Referenced by: '<S201>/TorsoBackAngle'
                                        */
  real_T TorsoBackOnStep;              /* Variable: TorsoBackOnStep
                                        * Referenced by: '<S201>/TorsoBackOnStep'
                                        */
  real_T TorsoCOMOffsets[2];           /* Variable: TorsoCOMOffsets
                                        * Referenced by: '<S1>/TorsoCOMOffsets'
                                        */
  real_T UseKASaturation;              /* Variable: UseKASaturation
                                        * Referenced by: '<S201>/UseKASaturation'
                                        */
  real_T UsePosingControl;             /* Variable: UsePosingControl
                                        * Referenced by: '<S201>/UsePosingControl'
                                        */
  real_T VelocityBasedUpdateDTheta0;   /* Variable: VelocityBasedUpdateDTheta0
                                        * Referenced by: '<S201>/VelocityBasedUpdateDTheta0'
                                        */
  real_T VelocityBasedUpdateK1[6];     /* Variable: VelocityBasedUpdateK1
                                        * Referenced by: '<S201>/VelocityBasedUpdateK1'
                                        */
  real_T VelocityBasedUpdateK2[6];     /* Variable: VelocityBasedUpdateK2
                                        * Referenced by: '<S201>/VelocityBasedUpdateK2'
                                        */
  real_T VelocityBasedUpdateLimits[12];/* Variable: VelocityBasedUpdateLimits
                                        * Referenced by: '<S201>/VelocityBasedUpdateLimits'
                                        */
  real_T VelocityControlTorsoGain;     /* Variable: VelocityControlTorsoGain
                                        * Referenced by: '<S201>/VelocityControlTorsoGain'
                                        */
  real_T VelocityControlTorsoMax;      /* Variable: VelocityControlTorsoMax
                                        * Referenced by: '<S201>/VelocityControlTorsoMax'
                                        */
  real_T VelocityControlTorsoMin;      /* Variable: VelocityControlTorsoMin
                                        * Referenced by: '<S201>/VelocityControlTorsoMin'
                                        */
  real_T VelocityControlTorsoV0;       /* Variable: VelocityControlTorsoV0
                                        * Referenced by: '<S201>/VelocityControlTorsoV0'
                                        */
  real_T YawLimit;                     /* Variable: YawLimit
                                        * Referenced by: '<S201>/YawLimit'
                                        */
  real_T epsilon[2];                   /* Variable: epsilon
                                        * Referenced by: '<S201>/epsilon'
                                        */
  real_T ff_params[5];                 /* Variable: ff_params
                                        * Referenced by: '<S201>/ff_params'
                                        */
  real_T hd_posing[6];                 /* Variable: hd_posing
                                        * Referenced by: '<S201>/hd_posing'
                                        */
  real_T k_precomp;                    /* Variable: k_precomp
                                        * Referenced by: '<S201>/k_precomp'
                                        */
  real_T kd[6];                        /* Variable: kd
                                        * Referenced by: '<S201>/kd'
                                        */
  real_T kd_2dof;                      /* Variable: kd_2dof
                                        * Referenced by: '<S201>/kd_2dof'
                                        */
  real_T kd_torso[2];                  /* Variable: kd_torso
                                        * Referenced by: '<S201>/kd_torso'
                                        */
  real_T kp[6];                        /* Variable: kp
                                        * Referenced by: '<S201>/kp'
                                        */
  real_T kp_2dof;                      /* Variable: kp_2dof
                                        * Referenced by: '<S201>/kp_2dof'
                                        */
  real_T lat_bias;                     /* Variable: lat_bias
                                        * Referenced by: '<S201>/lat_bias'
                                        */
  real_T lat_bias2;                    /* Variable: lat_bias2
                                        * Referenced by: '<S201>/lat_bias2'
                                        */
  real_T lateralParams[5];             /* Variable: lateralParams
                                        * Referenced by: '<S201>/lateralParams'
                                        */
  real_T linkFeedback;                 /* Variable: linkFeedback
                                        * Referenced by: '<S201>/linkFeedback'
                                        */
  real_T optimal_sat_weights[2];       /* Variable: optimal_sat_weights
                                        * Referenced by: '<S201>/optimal_sat_weights'
                                        */
  real_T step_params[5];               /* Variable: step_params
                                        * Referenced by: '<S201>/step_params'
                                        */
  real_T swap_params[7];               /* Variable: swap_params
                                        * Referenced by: '<S201>/swap_params'
                                        */
  real_T tStepInitial;                 /* Variable: tStepInitial
                                        * Referenced by: '<S201>/tStepInitial'
                                        */
  real_T transitionParams[5];          /* Variable: transitionParams
                                        * Referenced by: '<S201>/transitionParams'
                                        */
  real_T u_ff[6];                      /* Variable: u_ff
                                        * Referenced by: '<S201>/u_ff'
                                        */
  real_T use2DOFHipControl;            /* Variable: use2DOFHipControl
                                        * Referenced by: '<S201>/use2DOFHipControl'
                                        */
  real_T useOptimalSaturation;         /* Variable: useOptimalSaturation
                                        * Referenced by: '<S201>/useOptimalSaturation'
                                        */
  real_T w_torso_lat;                  /* Variable: w_torso_lat
                                        * Referenced by: '<S201>/w_torso_lat'
                                        */
  boolean_T EnableFT;                  /* Variable: EnableFT
                                        * Referenced by: '<S15>/EnableFT'
                                        */
  boolean_T ResetDAQ;                  /* Variable: ResetDAQ
                                        * Referenced by: '<S14>/ResetDAQ1'
                                        */
  boolean_T ResetYaw;                  /* Variable: ResetYaw
                                        * Referenced by:
                                        *   '<S5>/ResetYaw'
                                        *   '<S15>/ResetYaw'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Walking01_withElmos_T {
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
    time_T *taskTimePtrs[3];
    SimStruct childSFunctions[212];
    SimStruct *childSFunctionPtrs[212];
    struct _ssBlkInfo2 blkInfo2[212];
    struct _ssSFcnModelMethods2 methods2[212];
    struct _ssSFcnModelMethods3 methods3[212];
    struct _ssStatesInfo2 statesInfo2[212];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[3];
      mxArray *params[3];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      uint_T attribs[19];
      mxArray *params[19];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[4];
      mxArray *params[4];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
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
      uint_T attribs[2];
      mxArray *params[2];
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
      uint_T attribs[1];
      mxArray *params[1];
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
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn137;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn138;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn139;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn140;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn141;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
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
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn145;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
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
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn151;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn152;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
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
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn158;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn159;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
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
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn165;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn166;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
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
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn170;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
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
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn176;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn177;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
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
      struct _ssPortOutputs outputPortInfo[1];
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
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn186;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn187;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn188;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn189;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn190;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn191;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn192;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn193;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn194;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn195;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn196;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn197;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn198;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn199;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn200;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn201;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn202;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn203;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn204;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn205;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn206;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn207;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn208;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn209;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn210;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn211;
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
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    struct {
      uint8_T TID[3];
    } TaskCounters;

    struct {
      boolean_T TID0_1;
      boolean_T TID0_2;
    } RateInteraction;

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
    time_T sampleTimesArray[3];
    time_T offsetTimesArray[3];
    int_T sampleTimeTaskIDArray[3];
    int_T sampleHitArray[3];
    int_T perTaskSampleHitsArray[9];
    time_T tArray[3];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_Walking01_withElmos_T Walking01_withElmos_P;

/* Block signals (auto storage) */
extern B_Walking01_withElmos_T Walking01_withElmos_B;

/* Block states (auto storage) */
extern DW_Walking01_withElmos_T Walking01_withElmos_DW;

/* External outputs (root outports fed by signals with auto storage) */
extern ExtY_Walking01_withElmos_T Walking01_withElmos_Y;
extern const ConstB_Walking01_withElmos_T Walking01_withElmos_ConstB;/* constant block i/o */

/* Constant parameters (auto storage) */
extern const ConstP_Walking01_withElmos_T Walking01_withElmos_ConstP;

/* Constant parameters with dynamic initialization (auto storage) */
extern ConstInitP_Walking01_withElmos_T Walking01_withElmos_ConstInitP;/* constant parameters */

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* External data declarations for dependent source files */
extern const DiscreteParamsBus Walking01_withElmos_rtZDiscreteParamsBus;/* DiscreteParamsBus ground */

/* Model entry point functions */
extern void Walking01_withElmos_initialize(void);
extern void Walking01_withElmos_output(int_T tid);
extern void Walking01_withElmos_update(int_T tid);
extern void Walking01_withElmos_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern Walking01_withElmos_rtModel *Walking01_withElmos(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_Walking01_withElmos_T *const Walking01_withElmos_M;

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
 * '<Root>' : 'Walking01_withElmos'
 * '<S1>'   : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU'
 * '<S2>'   : 'Walking01_withElmos/Walking'
 * '<S3>'   : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/AdjustForCOMOffset'
 * '<S4>'   : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/CPU Overload Regulator'
 * '<S5>'   : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ'
 * '<S6>'   : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/SAFETY'
 * '<S7>'   : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/Saturation Dynamic'
 * '<S8>'   : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/CPU Overload Regulator/Compare To Constant'
 * '<S9>'   : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/CPU Overload Regulator/Compare To Constant1'
 * '<S10>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/CPU Overload Regulator/Compare To Zero'
 * '<S11>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/CPU Overload Regulator/Reset CPU Overload Count'
 * '<S12>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/CPU Overload Regulator/Reset CPU Overload Count/Set Overload Counter 1'
 * '<S13>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork'
 * '<S14>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/Reset'
 * '<S15>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces'
 * '<S16>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/StateEstimator'
 * '<S17>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/ComputeEulerAngles'
 * '<S18>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EncoderFilters'
 * '<S19>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain'
 * '<S20>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters'
 * '<S21>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/Subsystem'
 * '<S22>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/calibrate'
 * '<S23>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/convert_mtr_current_to_pwm'
 * '<S24>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EncoderFilters/CheckAndFilterEncoder'
 * '<S25>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EncoderFilters/CheckAndFilterEncoder/AnomalyDetection'
 * '<S26>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/ConvertAmpCurrent'
 * '<S27>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/ConvertLogicVoltage'
 * '<S28>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/ConvertMotorVoltage'
 * '<S29>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/ConvertThermistors'
 * '<S30>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/EncodeSwitches'
 * '<S31>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3L'
 * '<S32>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/HipMedulla_3R'
 * '<S33>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla'
 * '<S34>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L'
 * '<S35>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R'
 * '<S36>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L'
 * '<S37>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R'
 * '<S38>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1L'
 * '<S39>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_1R'
 * '<S40>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2L'
 * '<S41>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegMedulla_2R'
 * '<S42>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/TypecastAndCast'
 * '<S43>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/TypecastAndCast1'
 * '<S44>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/IMU_Medulla/TypecastAndCast2'
 * '<S45>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Chart'
 * '<S46>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/EtherCATSubsystem'
 * '<S47>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem'
 * '<S48>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem1'
 * '<S49>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem2'
 * '<S50>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem3'
 * '<S51>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem4'
 * '<S52>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem5'
 * '<S53>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem6'
 * '<S54>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem7'
 * '<S55>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem1/EnableControlWord'
 * '<S56>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem1/FaultReset'
 * '<S57>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem1/NothingControlWord'
 * '<S58>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem1/ShutdownControlWord'
 * '<S59>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem2/Compare To Constant'
 * '<S60>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem3/Compare To Constant'
 * '<S61>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem4/Compare To Constant'
 * '<S62>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1L/Subsystem5/Compare To Constant'
 * '<S63>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Chart'
 * '<S64>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/EtherCATSubsystem'
 * '<S65>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem'
 * '<S66>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem1'
 * '<S67>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem2'
 * '<S68>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem3'
 * '<S69>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem4'
 * '<S70>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem5'
 * '<S71>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem6'
 * '<S72>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem7'
 * '<S73>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem1/EnableControlWord'
 * '<S74>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem1/FaultReset'
 * '<S75>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem1/NothingControlWord'
 * '<S76>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem1/ShutdownControlWord'
 * '<S77>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem2/Compare To Constant'
 * '<S78>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem3/Compare To Constant'
 * '<S79>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem4/Compare To Constant'
 * '<S80>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_1R/Subsystem5/Compare To Constant'
 * '<S81>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Chart'
 * '<S82>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/EtherCATSubsystem'
 * '<S83>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem'
 * '<S84>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem1'
 * '<S85>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem2'
 * '<S86>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem3'
 * '<S87>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem4'
 * '<S88>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem5'
 * '<S89>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem6'
 * '<S90>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem7'
 * '<S91>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem1/EnableControlWord'
 * '<S92>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem1/FaultReset'
 * '<S93>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem1/NothingControlWord'
 * '<S94>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem1/ShutdownControlWord'
 * '<S95>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem2/Compare To Constant'
 * '<S96>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem3/Compare To Constant'
 * '<S97>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem4/Compare To Constant'
 * '<S98>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2L/Subsystem5/Compare To Constant'
 * '<S99>'  : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Chart'
 * '<S100>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/EtherCATSubsystem'
 * '<S101>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem'
 * '<S102>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem1'
 * '<S103>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem2'
 * '<S104>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem3'
 * '<S105>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem4'
 * '<S106>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem5'
 * '<S107>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem6'
 * '<S108>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem7'
 * '<S109>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem1/EnableControlWord'
 * '<S110>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem1/FaultReset'
 * '<S111>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem1/NothingControlWord'
 * '<S112>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem1/ShutdownControlWord'
 * '<S113>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem2/Compare To Constant'
 * '<S114>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem3/Compare To Constant'
 * '<S115>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem4/Compare To Constant'
 * '<S116>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/EtherCATRobotMicrostrain/LegElmo_2R/Subsystem5/Compare To Constant'
 * '<S117>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU'
 * '<S118>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/EtherCATNetwork/IMUFilters/CheckAndFilterIMU/AnomalyDetection'
 * '<S119>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/Reset/Compare To Constant'
 * '<S120>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/Reset/Compare To Constant1'
 * '<S121>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/Reset/Compare To Constant2'
 * '<S122>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN'
 * '<S123>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTInterface'
 * '<S124>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH'
 * '<S125>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/CANMessageOut'
 * '<S126>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Chart'
 * '<S127>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/ComputeCalibratedTorques'
 * '<S128>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/ComputeCalibratedTorques1'
 * '<S129>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem'
 * '<S130>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/CANMessageOut/ReadFirmwareVersion'
 * '<S131>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/CANMessageOut/ReadMatrixRow1'
 * '<S132>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/CANMessageOut/ReadMatrixRow2'
 * '<S133>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/CANMessageOut/ReadMatrixRow3'
 * '<S134>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/CANMessageOut/ReadMatrixRow4'
 * '<S135>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/CANMessageOut/ReadMatrixRow5'
 * '<S136>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/CANMessageOut/ReadMatrixRow6'
 * '<S137>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/CANMessageOut/ReadSGData'
 * '<S138>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/CANMessageOut/SetActiveCalibration'
 * '<S139>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/ComputeCalibratedTorques/ComputeCalibratedTorques'
 * '<S140>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/ComputeCalibratedTorques/Latch'
 * '<S141>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/ComputeCalibratedTorques1/ComputeCalibratedTorques'
 * '<S142>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/ComputeCalibratedTorques1/Latch'
 * '<S143>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock'
 * '<S144>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock1'
 * '<S145>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/ReadCalibrationMatrixRow_FlipFlops'
 * '<S146>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/ReadCalibrationMatrixRow_FlipFlops1'
 * '<S147>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/SG_Latch'
 * '<S148>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/SG_Latch1'
 * '<S149>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo'
 * '<S150>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo1'
 * '<S151>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/SelectedIndex_Latch'
 * '<S152>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/SelectedIndex_Latch1'
 * '<S153>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/TimestapRecorder'
 * '<S154>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/TimestapRecorder1'
 * '<S155>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock/Fx'
 * '<S156>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock/Fy'
 * '<S157>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock/Fz'
 * '<S158>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock/Tx'
 * '<S159>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock/Ty'
 * '<S160>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock/Tz'
 * '<S161>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock1/Fx'
 * '<S162>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock1/Fy'
 * '<S163>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock1/Fz'
 * '<S164>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock1/Tx'
 * '<S165>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock1/Ty'
 * '<S166>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/CalibrationMatrixBlock1/Tz'
 * '<S167>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/ReadCalibrationMatrixRow_FlipFlops/Subsystem'
 * '<S168>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/ReadCalibrationMatrixRow_FlipFlops/Subsystem1'
 * '<S169>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/ReadCalibrationMatrixRow_FlipFlops/Subsystem2'
 * '<S170>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/ReadCalibrationMatrixRow_FlipFlops1/Subsystem'
 * '<S171>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/ReadCalibrationMatrixRow_FlipFlops1/Subsystem1'
 * '<S172>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/ReadCalibrationMatrixRow_FlipFlops1/Subsystem2'
 * '<S173>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo/ReadRow1'
 * '<S174>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo/ReadRow2'
 * '<S175>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo/ReadRow3'
 * '<S176>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo/ReadRow4'
 * '<S177>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo/ReadRow5'
 * '<S178>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo/ReadRow6'
 * '<S179>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo1/ReadRow1'
 * '<S180>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo1/ReadRow2'
 * '<S181>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo1/ReadRow3'
 * '<S182>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo1/ReadRow4'
 * '<S183>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo1/ReadRow5'
 * '<S184>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTCAN/Read_and_Process_Subsystem/Select_SetCalibrationMatrixColumn_From_CommandNo1/ReadRow6'
 * '<S185>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTInterface/ATI Serial NoInt'
 * '<S186>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTInterface/Subsystem'
 * '<S187>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTInterface/Subsystem/ComputeCalibratedTorques'
 * '<S188>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTInterface/Subsystem/FTStateMachine'
 * '<S189>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTInterface/Subsystem/ComputeCalibratedTorques/ComputeCalibratedTorques'
 * '<S190>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/FTInterface/Subsystem/ComputeCalibratedTorques/Latch'
 * '<S191>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/ComputeEulerAngles'
 * '<S192>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/Send Receive1'
 * '<S193>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/Subsystem'
 * '<S194>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/UpdateOrientation'
 * '<S195>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/UpdateOrientation/EstimateOrientation'
 * '<S196>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/SerialInterfaces/KVH/UpdateOrientation/MATLAB Function'
 * '<S197>' : 'Walking01_withElmos/DAQ_WITH_SAFETY_IMU/DAQ/StateEstimator/GeneralizedCoordinates'
 * '<S198>' : 'Walking01_withElmos/Walking/AdjustYaw'
 * '<S199>' : 'Walking01_withElmos/Walking/Compare To Zero'
 * '<S200>' : 'Walking01_withElmos/Walking/Continuous'
 * '<S201>' : 'Walking01_withElmos/Walking/ControlParameters'
 * '<S202>' : 'Walking01_withElmos/Walking/Discrete'
 * '<S203>' : 'Walking01_withElmos/Walking/Continuous/CheckError'
 * '<S204>' : 'Walking01_withElmos/Walking/Continuous/Saturation'
 * '<S205>' : 'Walking01_withElmos/Walking/Continuous/StanceModel'
 * '<S206>' : 'Walking01_withElmos/Walking/Continuous/controller1'
 * '<S207>' : 'Walking01_withElmos/Walking/Continuous/Saturation/Saturation Dynamic'
 * '<S208>' : 'Walking01_withElmos/Walking/Continuous/Saturation/SmartSaturation'
 * '<S209>' : 'Walking01_withElmos/Walking/ControlParameters/Subsystem'
 * '<S210>' : 'Walking01_withElmos/Walking/ControlParameters/Subsystem1'
 * '<S211>' : 'Walking01_withElmos/Walking/ControlParameters/Subsystem2'
 * '<S212>' : 'Walking01_withElmos/Walking/Discrete/Detect Rise Positive1'
 * '<S213>' : 'Walking01_withElmos/Walking/Discrete/Detect Rise Positive2'
 * '<S214>' : 'Walking01_withElmos/Walking/Discrete/KA Acceleration'
 * '<S215>' : 'Walking01_withElmos/Walking/Discrete/StateLogic'
 * '<S216>' : 'Walking01_withElmos/Walking/Discrete/Detect Rise Positive1/Positive'
 * '<S217>' : 'Walking01_withElmos/Walking/Discrete/Detect Rise Positive2/Positive'
 */
#endif                                 /* RTW_HEADER_Walking01_withElmos_h_ */
