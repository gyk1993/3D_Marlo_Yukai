/*
 * xpcosc_private.h
 *
 * Code generation for model "xpcosc".
 *
 * Model version              : 1.13
 * Simulink Coder version : 8.7 (R2014b) 08-Sep-2014
 * C source code generated on : Wed May 11 19:37:04 2016
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_xpcosc_private_h_
#define RTW_HEADER_xpcosc_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;

/* private model entry point functions */
extern void xpcosc_derivatives(void);

#endif                                 /* RTW_HEADER_xpcosc_private_h_ */
