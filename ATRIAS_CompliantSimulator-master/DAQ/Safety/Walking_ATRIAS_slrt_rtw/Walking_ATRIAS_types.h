/*
 * Walking_ATRIAS_types.h
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
#ifndef RTW_HEADER_Walking_ATRIAS_types_h_
#define RTW_HEADER_Walking_ATRIAS_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#ifndef _DEFINED_TYPEDEF_FOR_struct_ejS3XxP2cpNSLBrHRQpJ6B_
#define _DEFINED_TYPEDEF_FOR_struct_ejS3XxP2cpNSLBrHRQpJ6B_

typedef struct {
  real_T AbsCalTick[10];
  real_T BoomCalTick[3];
  real_T AbsCalConst[10];
  real_T AbsCalAngle[10];
  real_T AbsMaxTick[10];
  real_T IncCalConst[6];
  real_T IncMaxTick[6];
  real_T BoomCalConst[3];
  real_T BoomCalAngle[3];
  real_T BoomMaxTick[3];
  real_T MaxTick[9];
  real_T Motors[9];
  real_T KVHOrientation[9];
  real_T MicrostrainOrientation[9];
} struct_ejS3XxP2cpNSLBrHRQpJ6B;

#endif

#ifndef _DEFINED_TYPEDEF_FOR_RobotCalibrationBus_
#define _DEFINED_TYPEDEF_FOR_RobotCalibrationBus_

typedef struct {
  real_T AbsCalTick[10];
  real_T BoomCalTick[3];
  real_T AbsCalConst[10];
  real_T AbsCalAngle[10];
  real_T AbsMaxTick[10];
  real_T IncCalConst[6];
  real_T IncMaxTick[6];
  real_T BoomCalConst[3];
  real_T BoomCalAngle[3];
  real_T BoomMaxTick[3];
  real_T MaxTick[9];
  real_T Motors[9];
  real_T KVHOrientation[9];
  real_T MicrostrainOrientation[9];
} RobotCalibrationBus;

#endif

#ifndef struct_sLHbLZPqh9Sb5Qu7JBIxssF
#define struct_sLHbLZPqh9Sb5Qu7JBIxssF

struct sLHbLZPqh9Sb5Qu7JBIxssF
{
  boolean_T value;
  boolean_T isPressed;
  real_T clickDuration;
  real_T clickCount;
  real_T time;
  real_T timePressed;
  real_T sampleInterval;
  real_T clickInterval;
};

#endif                                 /*struct_sLHbLZPqh9Sb5Qu7JBIxssF*/

#ifndef typedef_PS3Button_Walking_ATRIAS_T
#define typedef_PS3Button_Walking_ATRIAS_T

typedef struct sLHbLZPqh9Sb5Qu7JBIxssF PS3Button_Walking_ATRIAS_T;

#endif                                 /*typedef_PS3Button_Walking_ATRIAS_T*/

#ifndef struct_s0jaimZLyvDhCsxcpzPcwBD
#define struct_s0jaimZLyvDhCsxcpzPcwBD

struct s0jaimZLyvDhCsxcpzPcwBD
{
  real_T leftStickY;
  real_T rightStickX;
  real_T rightStickY;
  PS3Button_Walking_ATRIAS_T select;
  PS3Button_Walking_ATRIAS_T l3;
  PS3Button_Walking_ATRIAS_T r3;
  PS3Button_Walking_ATRIAS_T start;
  PS3Button_Walking_ATRIAS_T up;
  PS3Button_Walking_ATRIAS_T right;
  PS3Button_Walking_ATRIAS_T down;
  PS3Button_Walking_ATRIAS_T left;
  PS3Button_Walking_ATRIAS_T l2;
  PS3Button_Walking_ATRIAS_T r2;
  PS3Button_Walking_ATRIAS_T l1;
  PS3Button_Walking_ATRIAS_T r1;
  PS3Button_Walking_ATRIAS_T triangle;
  PS3Button_Walking_ATRIAS_T circle;
  PS3Button_Walking_ATRIAS_T cross;
  PS3Button_Walking_ATRIAS_T square;
  PS3Button_Walking_ATRIAS_T ps;
};

#endif                                 /*struct_s0jaimZLyvDhCsxcpzPcwBD*/

#ifndef typedef_PS3Controller_2_Walking_ATRIA_T
#define typedef_PS3Controller_2_Walking_ATRIA_T

typedef struct s0jaimZLyvDhCsxcpzPcwBD PS3Controller_2_Walking_ATRIA_T;

#endif                                 /*typedef_PS3Controller_2_Walking_ATRIA_T*/

#ifndef typedef_GaitMode_Walking_ATRIAS_T
#define typedef_GaitMode_Walking_ATRIAS_T

typedef int8_T GaitMode_Walking_ATRIAS_T;

#endif                                 /*typedef_GaitMode_Walking_ATRIAS_T*/

#ifndef GaitMode_constants
#define GaitMode_constants

/* enum GaitMode */
#define Cross                          ((GaitMode_Walking_ATRIAS_T)0)
#define Circle                         ((GaitMode_Walking_ATRIAS_T)1)
#define Triangle                       ((GaitMode_Walking_ATRIAS_T)2)
#define Square                         ((GaitMode_Walking_ATRIAS_T)3)
#endif                                 /*GaitMode_constants*/

#ifndef struct_sIRBuCNvFw77WEwwpdF7VjF
#define struct_sIRBuCNvFw77WEwwpdF7VjF

struct sIRBuCNvFw77WEwwpdF7VjF
{
  boolean_T isInitialized;
  boolean_T isReleased;
  boolean_T TunablePropsChanged;
  boolean_T isSim;
  real_T u_lim;
  PS3Controller_2_Walking_ATRIA_T ps3;
  real_T runTime;
  boolean_T isRun;
  real_T t0_step;
  real_T t_gain;
  real_T kp_st_leg;
  real_T kd_st_leg;
  real_T kp_sw_leg;
  real_T kd_sw_leg;
  real_T kp_hip;
  real_T kd_hip;
  real_T kp_vs;
  real_T kd_vs;
  real_T kp_yaw;
  real_T kd_yaw;
  real_T s_l_A;
  real_T s_l_B;
  real_T s_r_A;
  real_T s_r_B;
  real_T thres_lo;
  real_T thres_hi;
  real_T tau;
  real_T dx_gain;
  real_T dx_err_p_gain;
  real_T dx_err_d_gain;
  real_T dy_gain;
  real_T dy_err_p_gain;
  real_T dy_err_d_gain;
  real_T y0_offset;
  real_T y0_gain;
  boolean_T isTest5;
  boolean_T isTest7;
  boolean_T isTest8;
  boolean_T isTest11;
  boolean_T isTest12;
  real_T EnableYawControl;
  real_T uHipGravity;
  real_T stanceLeg;
  GaitMode_Walking_ATRIAS_T gaitMode;
  real_T t;
  real_T x_offset;
  real_T y_offset;
  real_T z_offset;
  real_T q_yaw_tgt;
  real_T q_yaw;
  real_T dq_yaw;
  real_T x_est;
  real_T y_est;
  real_T dx_est;
  real_T dy_est;
  real_T dy_est_avg;
  real_T dx_tgt;
  real_T dy_tgt;
  real_T dx_est_last;
  real_T dy_est_last;
  real_T output[2];
  real_T sDDA;
  real_T dsDDA;
  real_T dsDDA_est;
  real_T ds_last;
  real_T thetaMin;
  real_T dx;
  real_T dy;
  real_T theta;
  real_T tauPhase;
  real_T hd_last[4];
  real_T dhd_last[4];
  real_T dq_yaw_est;
  real_T dq_yaw_tgt;
  real_T leftHeight;
  real_T rightHeight;
  real_T rightBelieve;
  real_T leftBelieve;
  real_T hBelieve;
  real_T PressTime;
  real_T yawReset;
  real_T contactGround;
};

#endif                                 /*struct_sIRBuCNvFw77WEwwpdF7VjF*/

#ifndef typedef_Controller3DHZD_obj_2_Walking_T
#define typedef_Controller3DHZD_obj_2_Walking_T

typedef struct sIRBuCNvFw77WEwwpdF7VjF Controller3DHZD_obj_2_Walking_T;

#endif                                 /*typedef_Controller3DHZD_obj_2_Walking_T*/

/* Parameters (auto storage) */
typedef struct P_Walking_ATRIAS_T_ P_Walking_ATRIAS_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_Walking_ATRIAS_T RT_MODEL_Walking_ATRIAS_T;

#endif                                 /* RTW_HEADER_Walking_ATRIAS_types_h_ */
