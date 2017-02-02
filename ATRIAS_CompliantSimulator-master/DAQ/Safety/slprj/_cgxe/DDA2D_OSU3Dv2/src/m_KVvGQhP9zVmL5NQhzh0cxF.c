/* Include files */

#include <stddef.h>
#include "blas.h"
#include "DDA2D_OSU3Dv2_cgxe.h"
#include "m_KVvGQhP9zVmL5NQhzh0cxF.h"
#include "mwmathutil.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */
static emlrtMCInfo emlrtMCI = { 1, 1, "SystemCore",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\shared\\system\\coder\\+matlab\\+system\\+coder\\SystemCore.p"
};

static emlrtMCInfo b_emlrtMCI = { 20, 34, "eml_error",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_error.m"
};

static emlrtMCInfo c_emlrtMCI = { 87, 9, "eml_int_forloop_overflow_check",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

static emlrtMCInfo d_emlrtMCI = { 86, 15, "eml_int_forloop_overflow_check",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_overflow_check.m"
};

static emlrtMCInfo e_emlrtMCI = { 27, 5, "nchoosek",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\specfun\\nchoosek.m"
};

static emlrtMCInfo f_emlrtMCI = { 25, 15, "nchoosek",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\specfun\\nchoosek.m"
};

static emlrtMCInfo g_emlrtMCI = { 16, 13, "eml_warning",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_warning.m"
};

static emlrtMCInfo h_emlrtMCI = { 16, 5, "eml_warning",
  "C:\\Program Files\\MATLAB\\R2014b\\toolbox\\eml\\lib\\matlab\\eml\\eml_warning.m"
};

/* Function Declarations */
static void SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void b_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void c_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void d_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void e_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void f_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void g_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void h_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void i_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void j_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void k_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void l_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void m_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void n_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void o_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void p_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void q_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void r_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void s_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void t_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void u_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void v_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void w_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void x_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void y_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void ab_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void bb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void cb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void db_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void eb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void fb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void gb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void hb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void ib_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void jb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void kb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void lb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void mb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void nb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void ob_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void pb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void qb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void rb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void sb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void tb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void ub_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void vb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void wb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void xb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void yb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void ac_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void bc_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void SystemCore_setup(MikhailController_MARLO_Steeringv2_2 *obj);
static void MikhailController_MARLO_Steeringv2_userSetup
  (MikhailController_MARLO_Steeringv2_2 *obj);
static void mw__internal__system___fcn(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance, real_T varargin_1, real_T varargin_2, real_T varargin_3,
  real_T varargin_4, real_T varargin_5, real_T varargin_6, real_T varargin_7,
  real_T varargin_8, real_T varargin_9, real_T varargin_10, real_T varargin_11,
  real_T varargin_12, real_T varargin_13, real_T varargin_14, real_T varargin_15,
  real_T varargin_16, real_T varargin_17, real_T varargin_18, real_T varargin_19,
  real_T varargin_20, real_T varargin_21, real_T varargin_22, real_T varargin_23,
  real_T varargin_24, real_T varargin_25, real_T varargin_26, real_T varargin_27,
  boolean_T varargin_28, boolean_T varargin_29, boolean_T varargin_30, boolean_T
  varargin_31, boolean_T varargin_32, boolean_T varargin_33, boolean_T
  varargin_34, boolean_T varargin_35, boolean_T varargin_36, boolean_T
  varargin_37, boolean_T varargin_38, boolean_T varargin_39, real_T varargin_40,
  real_T varargin_41, real_T varargin_42, real_T varargin_43, real_T varargin_44,
  real_T varargin_45, real_T varargin_46, real_T varargin_47, boolean_T
  varargin_48, real_T varargin_49[4], real_T varargin_50[17], real_T varargin_51,
  real_T varargin_52[13], real_T varargin_53[13], real_T varargin_54[2], real_T
  varargin_55[2], real_T varargin_56[2], real_T varargin_57[36], boolean_T
  *varargout_1, real_T varargout_2[6], real_T varargout_3[9], real_T
  *varargout_4, real_T varargout_5[6], real_T varargout_6[6], real_T
  *varargout_7);
static boolean_T isequal(real_T varargin_1, real_T varargin_2);
static boolean_T b_isequal(boolean_T varargin_1, boolean_T varargin_2);
static void SystemCore_step(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance, MikhailController_MARLO_Steeringv2_2 *obj, real_T varargin_1
  [13], real_T varargin_2[13], real_T varargin_3[2], real_T varargin_4[2],
  real_T varargin_5[2], real_T varargin_6[36], boolean_T *varargout_1, real_T
  varargout_2[6], real_T varargout_3[9], real_T *varargout_4, real_T
  varargout_5[6], real_T varargout_6[6], real_T *varargout_7);
static void PS3Button_update(PS3Button *obj, boolean_T value);
static void MikhailController_MARLO_Steeringv2_userStep
  (InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance,
   MikhailController_MARLO_Steeringv2_2 *obj, real_T q[13], real_T dq[13],
   real_T ControlState[2], real_T ControlParams[2], real_T theta_limits_nom[2],
   real_T HAlphaDDA[36], real_T u[6], real_T y_out[6], real_T dy_out[6], real_T *
   s);
static void MikhailController_MARLO_Steeringv2_parsePS3Controller
  (MikhailController_MARLO_Steeringv2_2 *obj, real_T ControlParams[2]);
static real_T clamp(real_T a, real_T lim1, real_T lim2);
static real_T scaleFactor(real_T f, real_T tl, real_T tu);
static real_T cubic_interp(real_T x0[2], real_T c_y0[2], real_T dy0[2], real_T
  b_x, real_T dx);
static void b_cubic_interp(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance,
  real_T x0[4], real_T c_y0[4], real_T dy0[4], real_T b_x, real_T dx, real_T *y,
  real_T *dy);
static real_T mean(real_T b_x[2]);
static void c_cubic_interp(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance,
  real_T x0[3], real_T c_y0[3], real_T dy0[3], real_T b_x, real_T dx, real_T *y,
  real_T *dy);
static real_T atans(real_T b_x, real_T slope, real_T y_lim);
static void d_cubic_interp(real_T x0[2], real_T c_y0[2], real_T dy0[2], real_T
  b_x, real_T dx, real_T *y, real_T *dy);
static void eml_error(void);
static void b_eml_error(void);
static void bezierval(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance,
                      real_T alpha[24], real_T s, real_T y[4]);
static void eml_warning(void);
static void cgxe_mdl_start(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance);
static void cgxe_mdl_initialize(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance);
static void cgxe_mdl_outputs(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance);
static void cgxe_mdl_update(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance);
static void cgxe_mdl_terminate(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance);
static const mxArray *mw__internal__name__resolution__fcn(void);
static void info_helper(const mxArray **info);
static const mxArray *emlrt_marshallOut(const char * u);
static const mxArray *b_emlrt_marshallOut(const uint32_T u);
static void b_info_helper(const mxArray **info);
static void c_info_helper(const mxArray **info);
static void d_info_helper(const mxArray **info);
static void e_info_helper(const mxArray **info);
static const mxArray *mw__internal__autoInference__fcn(void);
static const mxArray *c_emlrt_marshallOut(const PS3Controller_2 *u);
static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance);
static void emlrt_marshallIn(const mxArray *b_sysobj, const char_T *identifier,
  MikhailController_MARLO_Steeringv2_2 *y);
static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, MikhailController_MARLO_Steeringv2_2 *y);
static boolean_T c_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[4]);
static void e_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[17]);
static real_T f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void g_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, PS3Controller_2 *y);
static PS3Button h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static GaitMode i_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static void j_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[4]);
static boolean_T k_emlrt_marshallIn(const mxArray *b_sysobj_not_empty, const
  char_T *identifier);
static void mw__internal__setSimState__fcn(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance, const mxArray *st);
static const mxArray *message(const mxArray *b, const mxArray *c, emlrtMCInfo
  *location);
static void error(const mxArray *b, emlrtMCInfo *location);
static const mxArray *b_message(const mxArray *b, emlrtMCInfo *location);
static void warning(const mxArray *b, emlrtMCInfo *location);
static boolean_T l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static void m_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[4]);
static void n_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[17]);
static real_T o_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static void p_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[4]);
static void b_acos(creal_T *b_x);
static void eml_scalar_sqrt(creal_T *b_x);
static void b_asin(real_T *b_x);
static void mldivide(real_T B[24]);

/* Function Definitions */
static void SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void b_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void c_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void d_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void e_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void f_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void g_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void h_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void i_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void j_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void k_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void l_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void m_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void n_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void o_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void p_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void q_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void r_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void s_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void t_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void u_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void v_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void w_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void x_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void y_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void ab_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void bb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void cb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void db_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void eb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void fb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void gb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void hb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void ib_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void jb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void kb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void lb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void mb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void nb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void ob_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void pb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void qb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void rb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void sb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void tb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void ub_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void vb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void wb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void xb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void yb_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void ac_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void bc_SystemProp_matlabCodegenNotifyAnyProp
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  b_obj = obj;
  if (b_obj->isInitialized && !b_obj->isReleased) {
    flag = true;
  } else {
    flag = false;
  }

  if (flag) {
    obj->TunablePropsChanged = true;
  }
}

static void SystemCore_setup(MikhailController_MARLO_Steeringv2_2 *obj)
{
  const mxArray *y;
  static const int32_T iv0[2] = { 1, 51 };

  const mxArray *m0;
  char_T cv0[51];
  int32_T i0;
  static char_T cv1[51] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'L', 'o', 'c', 'k', 'e', 'd', 'R', 'e', 'l', 'e',
    'a', 's', 'e', 'd', 'C', 'o', 'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv1[2] = { 1, 5 };

  char_T cv2[5];
  static char_T cv3[5] = { 's', 'e', 't', 'u', 'p' };

  MikhailController_MARLO_Steeringv2_2 *b_obj;
  if (obj->isInitialized) {
    y = NULL;
    m0 = emlrtCreateCharArray(2, iv0);
    for (i0 = 0; i0 < 51; i0++) {
      cv0[i0] = cv1[i0];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 51, m0, cv0);
    emlrtAssign(&y, m0);
    b_y = NULL;
    m0 = emlrtCreateCharArray(2, iv1);
    for (i0 = 0; i0 < 5; i0++) {
      cv2[i0] = cv3[i0];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m0, cv2);
    emlrtAssign(&b_y, m0);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  obj->isInitialized = true;
  b_obj = obj;
  b_obj->ps3._select.value = false;
  b_obj->ps3._select.clickDuration = 0.0;
  b_obj->ps3._select.clickCount = 0.0;
  b_obj->ps3._select.time = 0.0;
  b_obj->ps3._select.timePressed = 0.0;
  b_obj->ps3._select.sampleInterval = 0.001;
  b_obj->ps3._select.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.l3.value = false;
  b_obj->ps3.l3.clickDuration = 0.0;
  b_obj->ps3.l3.clickCount = 0.0;
  b_obj->ps3.l3.time = 0.0;
  b_obj->ps3.l3.timePressed = 0.0;
  b_obj->ps3.l3.sampleInterval = 0.001;
  b_obj->ps3.l3.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.r3.value = false;
  b_obj->ps3.r3.clickDuration = 0.0;
  b_obj->ps3.r3.clickCount = 0.0;
  b_obj->ps3.r3.time = 0.0;
  b_obj->ps3.r3.timePressed = 0.0;
  b_obj->ps3.r3.sampleInterval = 0.001;
  b_obj->ps3.r3.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.start.value = false;
  b_obj->ps3.start.clickDuration = 0.0;
  b_obj->ps3.start.clickCount = 0.0;
  b_obj->ps3.start.time = 0.0;
  b_obj->ps3.start.timePressed = 0.0;
  b_obj->ps3.start.sampleInterval = 0.001;
  b_obj->ps3.start.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.up.value = false;
  b_obj->ps3.up.clickDuration = 0.0;
  b_obj->ps3.up.clickCount = 0.0;
  b_obj->ps3.up.time = 0.0;
  b_obj->ps3.up.timePressed = 0.0;
  b_obj->ps3.up.sampleInterval = 0.001;
  b_obj->ps3.up.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.right.value = false;
  b_obj->ps3.right.clickDuration = 0.0;
  b_obj->ps3.right.clickCount = 0.0;
  b_obj->ps3.right.time = 0.0;
  b_obj->ps3.right.timePressed = 0.0;
  b_obj->ps3.right.sampleInterval = 0.001;
  b_obj->ps3.right.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.down.value = false;
  b_obj->ps3.down.clickDuration = 0.0;
  b_obj->ps3.down.clickCount = 0.0;
  b_obj->ps3.down.time = 0.0;
  b_obj->ps3.down.timePressed = 0.0;
  b_obj->ps3.down.sampleInterval = 0.001;
  b_obj->ps3.down.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.left.value = false;
  b_obj->ps3.left.clickDuration = 0.0;
  b_obj->ps3.left.clickCount = 0.0;
  b_obj->ps3.left.time = 0.0;
  b_obj->ps3.left.timePressed = 0.0;
  b_obj->ps3.left.sampleInterval = 0.001;
  b_obj->ps3.left.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.l2.value = false;
  b_obj->ps3.l2.clickDuration = 0.0;
  b_obj->ps3.l2.clickCount = 0.0;
  b_obj->ps3.l2.time = 0.0;
  b_obj->ps3.l2.timePressed = 0.0;
  b_obj->ps3.l2.sampleInterval = 0.001;
  b_obj->ps3.l2.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.r2.value = false;
  b_obj->ps3.r2.clickDuration = 0.0;
  b_obj->ps3.r2.clickCount = 0.0;
  b_obj->ps3.r2.time = 0.0;
  b_obj->ps3.r2.timePressed = 0.0;
  b_obj->ps3.r2.sampleInterval = 0.001;
  b_obj->ps3.r2.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.l1.value = false;
  b_obj->ps3.l1.clickDuration = 0.0;
  b_obj->ps3.l1.clickCount = 0.0;
  b_obj->ps3.l1.time = 0.0;
  b_obj->ps3.l1.timePressed = 0.0;
  b_obj->ps3.l1.sampleInterval = 0.001;
  b_obj->ps3.l1.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.r1.value = false;
  b_obj->ps3.r1.clickDuration = 0.0;
  b_obj->ps3.r1.clickCount = 0.0;
  b_obj->ps3.r1.time = 0.0;
  b_obj->ps3.r1.timePressed = 0.0;
  b_obj->ps3.r1.sampleInterval = 0.001;
  b_obj->ps3.r1.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.triangle.value = false;
  b_obj->ps3.triangle.clickDuration = 0.0;
  b_obj->ps3.triangle.clickCount = 0.0;
  b_obj->ps3.triangle.time = 0.0;
  b_obj->ps3.triangle.timePressed = 0.0;
  b_obj->ps3.triangle.sampleInterval = 0.001;
  b_obj->ps3.triangle.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.circle.value = false;
  b_obj->ps3.circle.clickDuration = 0.0;
  b_obj->ps3.circle.clickCount = 0.0;
  b_obj->ps3.circle.time = 0.0;
  b_obj->ps3.circle.timePressed = 0.0;
  b_obj->ps3.circle.sampleInterval = 0.001;
  b_obj->ps3.circle.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.cross.value = false;
  b_obj->ps3.cross.clickDuration = 0.0;
  b_obj->ps3.cross.clickCount = 0.0;
  b_obj->ps3.cross.time = 0.0;
  b_obj->ps3.cross.timePressed = 0.0;
  b_obj->ps3.cross.sampleInterval = 0.001;
  b_obj->ps3.cross.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.square.value = false;
  b_obj->ps3.square.clickDuration = 0.0;
  b_obj->ps3.square.clickCount = 0.0;
  b_obj->ps3.square.time = 0.0;
  b_obj->ps3.square.timePressed = 0.0;
  b_obj->ps3.square.sampleInterval = 0.001;
  b_obj->ps3.square.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  b_obj->ps3.ps.value = false;
  b_obj->ps3.ps.clickDuration = 0.0;
  b_obj->ps3.ps.clickCount = 0.0;
  b_obj->ps3.ps.time = 0.0;
  b_obj->ps3.ps.timePressed = 0.0;
  b_obj->ps3.ps.sampleInterval = 0.001;
  b_obj->ps3.ps.clickInterval = 0.5;

  /*  update */
  /*  methods */
  /*  classdef */
  /*  update */
  /*  methods */
  /*  classdef */
  MikhailController_MARLO_Steeringv2_userSetup(b_obj);
  obj->TunablePropsChanged = false;
}

static void MikhailController_MARLO_Steeringv2_userSetup
  (MikhailController_MARLO_Steeringv2_2 *obj)
{
  int32_T i1;
  obj->gaitMode = Cross;
  obj->t = 0.0;
  obj->x_est = 0.0;
  obj->y_est = 0.0;
  obj->dx_est = 0.0;
  obj->dy_est = 0.0;
  obj->dy_est_avg = 0.0;
  obj->dx_tgt = 0.0;
  obj->dy_tgt = 0.0;
  obj->dx_est_last = 0.0;
  obj->dy_est_last = 0.0;
  obj->x_sw_last = 0.0;
  obj->dx_sw_last = 0.0;
  obj->y_sw_last = 0.0;
  obj->dy_sw_last = 0.0;
  obj->l_st_last = obj->l0_leg;
  obj->dl_st_last = 0.0;
  obj->l_sw_last = obj->l0_leg;
  obj->dl_sw_last = 0.0;
  obj->dx = 0.0;
  obj->dy = 0.0;
  obj->theta = 0.0;
  obj->sDDA = 0.0;
  obj->tauPhase = 0.0;
  for (i1 = 0; i1 < 4; i1++) {
    obj->hd_q[i1] = 0.0;
  }

  obj->switch_phase = 0.0;
  obj->switch_phase_last = 0.0;
  obj->Jz = 0.0;
}

static void mw__internal__system___fcn(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance, real_T varargin_1, real_T varargin_2, real_T varargin_3,
  real_T varargin_4, real_T varargin_5, real_T varargin_6, real_T varargin_7,
  real_T varargin_8, real_T varargin_9, real_T varargin_10, real_T varargin_11,
  real_T varargin_12, real_T varargin_13, real_T varargin_14, real_T varargin_15,
  real_T varargin_16, real_T varargin_17, real_T varargin_18, real_T varargin_19,
  real_T varargin_20, real_T varargin_21, real_T varargin_22, real_T varargin_23,
  real_T varargin_24, real_T varargin_25, real_T varargin_26, real_T varargin_27,
  boolean_T varargin_28, boolean_T varargin_29, boolean_T varargin_30, boolean_T
  varargin_31, boolean_T varargin_32, boolean_T varargin_33, boolean_T
  varargin_34, boolean_T varargin_35, boolean_T varargin_36, boolean_T
  varargin_37, boolean_T varargin_38, boolean_T varargin_39, real_T varargin_40,
  real_T varargin_41, real_T varargin_42, real_T varargin_43, real_T varargin_44,
  real_T varargin_45, real_T varargin_46, real_T varargin_47, boolean_T
  varargin_48, real_T varargin_49[4], real_T varargin_50[17], real_T varargin_51,
  real_T varargin_52[13], real_T varargin_53[13], real_T varargin_54[2], real_T
  varargin_55[2], real_T varargin_56[2], real_T varargin_57[36], boolean_T
  *varargout_1, real_T varargout_2[6], real_T varargout_3[9], real_T
  *varargout_4, real_T varargout_5[6], real_T varargout_6[6], real_T
  *varargout_7)
{
  int32_T k;
  boolean_T hoistedGlobal_isSim;
  boolean_T p;
  boolean_T b_p;
  real_T hoistedGlobal_ps3Axes[4];
  boolean_T exitg2;
  real_T hoistedGlobal_ps3Buttons[17];
  boolean_T exitg1;
  real_T hoistedGlobal_u_lim;
  if (!moduleInstance->sysobj_not_empty) {
    moduleInstance->sysobj.stanceLeg = -1.0;
    moduleInstance->sysobj.q_yaw = 0.0;
    moduleInstance->sysobj.z_offset = 0.2087;
    moduleInstance->sysobj.runTime = 0.0;
    moduleInstance->sysobj.isInitialized = false;
    moduleInstance->sysobj.isReleased = false;
    moduleInstance->sysobj_not_empty = true;
    SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    b_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.t0_step = varargin_1;
    c_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.t_gain = varargin_2;
    d_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_st_leg = varargin_3;
    e_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_st_leg = varargin_4;
    f_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_sw_leg = varargin_5;
    g_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_sw_leg = varargin_6;
    h_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_hip = varargin_7;
    i_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_hip = varargin_8;
    j_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_l_A = varargin_9;
    k_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_l_B = varargin_10;
    l_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_r_A = varargin_11;
    m_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_r_B = varargin_12;
    n_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.thres_lo = varargin_13;
    o_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.thres_hi = varargin_14;
    p_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.tau = varargin_15;
    q_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dx_gain = varargin_16;
    r_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dx_err_p_gain = varargin_17;
    s_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dx_err_d_gain = varargin_18;
    t_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dy_gain = varargin_19;
    u_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dy_err_p_gain = varargin_20;
    v_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dy_err_d_gain = varargin_21;
    w_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.y0_offset = varargin_22;
    x_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.y0_gain = varargin_23;
    y_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.l0_leg = varargin_24;
    ab_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.l_ret = varargin_25;
    bb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.l_ext_gain = varargin_26;
    cb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_overlap = varargin_27;
    db_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest1 = varargin_28;
    eb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest2 = varargin_29;
    fb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest3 = varargin_30;
    gb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest4 = varargin_31;
    hb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest5 = varargin_32;
    ib_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest6 = varargin_33;
    jb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest7 = varargin_34;
    kb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest8 = varargin_35;
    lb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest9 = varargin_36;
    mb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest10 = varargin_37;
    nb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest11 = varargin_38;
    ob_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest12 = varargin_39;
    pb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.x_offset = varargin_40;
    qb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.steering_offset = varargin_41;
    rb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.q_yaw_tgt = varargin_42;
    sb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.y_offset = varargin_43;
    tb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.EnableYawControl = varargin_44;
    ub_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.uHipGravity = varargin_45;
    vb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_rate = varargin_46;
    wb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_rate = varargin_47;
    xb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isSim = varargin_48;
    yb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    for (k = 0; k < 4; k++) {
      moduleInstance->sysobj.ps3Axes[k] = varargin_49[k];
    }

    ac_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    for (k = 0; k < 17; k++) {
      moduleInstance->sysobj.ps3Buttons[k] = varargin_50[k];
    }

    bc_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.u_lim = varargin_51;
  }

  if (!isequal(moduleInstance->sysobj.t0_step, varargin_1)) {
    b_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.t0_step = varargin_1;
  }

  if (!isequal(moduleInstance->sysobj.t_gain, varargin_2)) {
    c_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.t_gain = varargin_2;
  }

  if (!isequal(moduleInstance->sysobj.kp_st_leg, varargin_3)) {
    d_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_st_leg = varargin_3;
  }

  if (!isequal(moduleInstance->sysobj.kd_st_leg, varargin_4)) {
    e_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_st_leg = varargin_4;
  }

  if (!isequal(moduleInstance->sysobj.kp_sw_leg, varargin_5)) {
    f_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_sw_leg = varargin_5;
  }

  if (!isequal(moduleInstance->sysobj.kd_sw_leg, varargin_6)) {
    g_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_sw_leg = varargin_6;
  }

  if (!isequal(moduleInstance->sysobj.kp_hip, varargin_7)) {
    h_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_hip = varargin_7;
  }

  if (!isequal(moduleInstance->sysobj.kd_hip, varargin_8)) {
    i_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_hip = varargin_8;
  }

  if (!isequal(moduleInstance->sysobj.s_l_A, varargin_9)) {
    j_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_l_A = varargin_9;
  }

  if (!isequal(moduleInstance->sysobj.s_l_B, varargin_10)) {
    k_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_l_B = varargin_10;
  }

  if (!isequal(moduleInstance->sysobj.s_r_A, varargin_11)) {
    l_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_r_A = varargin_11;
  }

  if (!isequal(moduleInstance->sysobj.s_r_B, varargin_12)) {
    m_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_r_B = varargin_12;
  }

  if (!isequal(moduleInstance->sysobj.thres_lo, varargin_13)) {
    n_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.thres_lo = varargin_13;
  }

  if (!isequal(moduleInstance->sysobj.thres_hi, varargin_14)) {
    o_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.thres_hi = varargin_14;
  }

  if (!isequal(moduleInstance->sysobj.tau, varargin_15)) {
    p_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.tau = varargin_15;
  }

  if (!isequal(moduleInstance->sysobj.dx_gain, varargin_16)) {
    q_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dx_gain = varargin_16;
  }

  if (!isequal(moduleInstance->sysobj.dx_err_p_gain, varargin_17)) {
    r_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dx_err_p_gain = varargin_17;
  }

  if (!isequal(moduleInstance->sysobj.dx_err_d_gain, varargin_18)) {
    s_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dx_err_d_gain = varargin_18;
  }

  if (!isequal(moduleInstance->sysobj.dy_gain, varargin_19)) {
    t_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dy_gain = varargin_19;
  }

  if (!isequal(moduleInstance->sysobj.dy_err_p_gain, varargin_20)) {
    u_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dy_err_p_gain = varargin_20;
  }

  if (!isequal(moduleInstance->sysobj.dy_err_d_gain, varargin_21)) {
    v_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dy_err_d_gain = varargin_21;
  }

  if (!isequal(moduleInstance->sysobj.y0_offset, varargin_22)) {
    w_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.y0_offset = varargin_22;
  }

  if (!isequal(moduleInstance->sysobj.y0_gain, varargin_23)) {
    x_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.y0_gain = varargin_23;
  }

  if (!isequal(moduleInstance->sysobj.l0_leg, varargin_24)) {
    y_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.l0_leg = varargin_24;
  }

  if (!isequal(moduleInstance->sysobj.l_ret, varargin_25)) {
    ab_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.l_ret = varargin_25;
  }

  if (!isequal(moduleInstance->sysobj.l_ext_gain, varargin_26)) {
    bb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.l_ext_gain = varargin_26;
  }

  if (!isequal(moduleInstance->sysobj.s_overlap, varargin_27)) {
    cb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_overlap = varargin_27;
  }

  if (!b_isequal(moduleInstance->sysobj.isTest1, varargin_28)) {
    db_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest1 = varargin_28;
  }

  if (!b_isequal(moduleInstance->sysobj.isTest2, varargin_29)) {
    eb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest2 = varargin_29;
  }

  if (!b_isequal(moduleInstance->sysobj.isTest3, varargin_30)) {
    fb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest3 = varargin_30;
  }

  if (!b_isequal(moduleInstance->sysobj.isTest4, varargin_31)) {
    gb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest4 = varargin_31;
  }

  if (!b_isequal(moduleInstance->sysobj.isTest5, varargin_32)) {
    hb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest5 = varargin_32;
  }

  if (!b_isequal(moduleInstance->sysobj.isTest6, varargin_33)) {
    ib_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest6 = varargin_33;
  }

  if (!b_isequal(moduleInstance->sysobj.isTest7, varargin_34)) {
    jb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest7 = varargin_34;
  }

  if (!b_isequal(moduleInstance->sysobj.isTest8, varargin_35)) {
    kb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest8 = varargin_35;
  }

  if (!b_isequal(moduleInstance->sysobj.isTest9, varargin_36)) {
    lb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest9 = varargin_36;
  }

  if (!b_isequal(moduleInstance->sysobj.isTest10, varargin_37)) {
    mb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest10 = varargin_37;
  }

  if (!b_isequal(moduleInstance->sysobj.isTest11, varargin_38)) {
    nb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest11 = varargin_38;
  }

  if (!b_isequal(moduleInstance->sysobj.isTest12, varargin_39)) {
    ob_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.isTest12 = varargin_39;
  }

  if (!isequal(moduleInstance->sysobj.x_offset, varargin_40)) {
    pb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.x_offset = varargin_40;
  }

  if (!isequal(moduleInstance->sysobj.steering_offset, varargin_41)) {
    qb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.steering_offset = varargin_41;
  }

  if (!isequal(moduleInstance->sysobj.q_yaw_tgt, varargin_42)) {
    rb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.q_yaw_tgt = varargin_42;
  }

  if (!isequal(moduleInstance->sysobj.y_offset, varargin_43)) {
    sb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.y_offset = varargin_43;
  }

  if (!isequal(moduleInstance->sysobj.EnableYawControl, varargin_44)) {
    tb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.EnableYawControl = varargin_44;
  }

  if (!isequal(moduleInstance->sysobj.uHipGravity, varargin_45)) {
    ub_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.uHipGravity = varargin_45;
  }

  if (!isequal(moduleInstance->sysobj.kp_rate, varargin_46)) {
    vb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_rate = varargin_46;
  }

  if (!isequal(moduleInstance->sysobj.kd_rate, varargin_47)) {
    wb_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_rate = varargin_47;
  }

  hoistedGlobal_isSim = moduleInstance->sysobj.isSim;
  p = false;
  b_p = true;
  if (!((int32_T)hoistedGlobal_isSim == (int32_T)varargin_48)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      hoistedGlobal_isSim = true;
    } else {
      hoistedGlobal_isSim = false;
    }

    if (hoistedGlobal_isSim) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isSim = varargin_48;
  }

  for (k = 0; k < 4; k++) {
    hoistedGlobal_ps3Axes[k] = moduleInstance->sysobj.ps3Axes[k];
  }

  p = false;
  b_p = true;
  k = 0;
  exitg2 = false;
  while (exitg2 == false && k < 4) {
    if (!(hoistedGlobal_ps3Axes[k] == varargin_49[k])) {
      b_p = false;
      exitg2 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      hoistedGlobal_isSim = true;
    } else {
      hoistedGlobal_isSim = false;
    }

    if (hoistedGlobal_isSim) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (k = 0; k < 4; k++) {
      moduleInstance->sysobj.ps3Axes[k] = varargin_49[k];
    }
  }

  for (k = 0; k < 17; k++) {
    hoistedGlobal_ps3Buttons[k] = moduleInstance->sysobj.ps3Buttons[k];
  }

  p = false;
  b_p = true;
  k = 0;
  exitg1 = false;
  while (exitg1 == false && k < 17) {
    if (!(hoistedGlobal_ps3Buttons[k] == varargin_50[k])) {
      b_p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      hoistedGlobal_isSim = true;
    } else {
      hoistedGlobal_isSim = false;
    }

    if (hoistedGlobal_isSim) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (k = 0; k < 17; k++) {
      moduleInstance->sysobj.ps3Buttons[k] = varargin_50[k];
    }
  }

  hoistedGlobal_u_lim = moduleInstance->sysobj.u_lim;
  p = false;
  b_p = true;
  if (!(hoistedGlobal_u_lim == varargin_51)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  if (!p) {
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      hoistedGlobal_isSim = true;
    } else {
      hoistedGlobal_isSim = false;
    }

    if (hoistedGlobal_isSim) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.u_lim = varargin_51;
  }

  SystemCore_step(moduleInstance, &moduleInstance->sysobj, varargin_52,
                  varargin_53, varargin_54, varargin_55, varargin_56,
                  varargin_57, varargout_1, varargout_2, varargout_3,
                  varargout_4, varargout_5, varargout_6, varargout_7);
  *varargout_4 = 0.0;
}

static boolean_T isequal(real_T varargin_1, real_T varargin_2)
{
  boolean_T p;
  boolean_T b_p;
  p = false;
  b_p = true;
  if (!(varargin_1 == varargin_2)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static boolean_T b_isequal(boolean_T varargin_1, boolean_T varargin_2)
{
  boolean_T p;
  boolean_T b_p;
  p = false;
  b_p = true;
  if (!((int32_T)varargin_1 == (int32_T)varargin_2)) {
    b_p = false;
  }

  if (b_p) {
    p = true;
  }

  return p;
}

static void SystemCore_step(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance, MikhailController_MARLO_Steeringv2_2 *obj, real_T varargin_1
  [13], real_T varargin_2[13], real_T varargin_3[2], real_T varargin_4[2],
  real_T varargin_5[2], real_T varargin_6[36], boolean_T *varargout_1, real_T
  varargout_2[6], real_T varargout_3[9], real_T *varargout_4, real_T
  varargout_5[6], real_T varargout_6[6], real_T *varargout_7)
{
  const mxArray *y;
  static const int32_T iv2[2] = { 1, 45 };

  const mxArray *m1;
  char_T cv4[45];
  int32_T k;
  static char_T cv5[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv3[2] = { 1, 4 };

  char_T cv6[4];
  static char_T cv7[4] = { 's', 't', 'e', 'p' };

  MikhailController_MARLO_Steeringv2_2 *b_obj;
  real_T q[13];
  real_T dq[13];
  real_T axes[4];
  real_T buttons[17];
  boolean_T b_buttons[17];
  static int8_T iv4[4] = { 0, 1, 3, 4 };

  real_T a_max;
  real_T lim2;
  real_T a_min;
  if (obj->isReleased) {
    y = NULL;
    m1 = emlrtCreateCharArray(2, iv2);
    for (k = 0; k < 45; k++) {
      cv4[k] = cv5[k];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m1, cv4);
    emlrtAssign(&y, m1);
    b_y = NULL;
    m1 = emlrtCreateCharArray(2, iv3);
    for (k = 0; k < 4; k++) {
      cv6[k] = cv7[k];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 4, m1, cv6);
    emlrtAssign(&b_y, m1);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  if (!obj->isInitialized) {
    b_obj = obj;
    SystemCore_setup(b_obj);
  }

  b_obj = obj;
  if (b_obj->TunablePropsChanged) {
    b_obj->TunablePropsChanged = false;
  }

  b_obj = obj;
  for (k = 0; k < 13; k++) {
    q[k] = varargin_1[k];
    dq[k] = varargin_2[k];
  }

  /* CONTROLLER Controller superclass. */
  /*  PUBLIC PROPERTIES ===================================================== */
  /*  Simulation flag */
  /*  properties */
  /*  PS3 controller joysticks */
  /*  PS3 controller buttons */
  /*  Torque limit (N*m) */
  /*  MARLO */
  /*  properties */
  /*  PROTECTED PROPERTIES ================================================== */
  /*  PS3 controller object */
  /*  Run time (s) */
  /*  Controller run state */
  /*  Last Phase Switch */
  /*  switch phase update */
  /*  properties */
  /*  CONSTANT PROPERTIES =================================================== */
  /*  Sample interval time (s) */
  /* MARLO sample time */
  /*  properties */
  /*  ABSTRACT METHODS ====================================================== */
  /*  methods */
  /*  PROTECTED METHODS ===================================================== */
  /* SETUPIMPL Initialize system object. */
  /*  Initialize PS3 controller interface */
  /*  Run controller specific initialization */
  /*  setupImpl */
  /* STEPIMPL System output and state update equations. */
  /*  Initialize control input */
  for (k = 0; k < 6; k++) {
    varargout_2[k] = 0.0;
  }

  /*  Simulation overrides */
  /*        if obj.isSim */
  /*  Coordinate transformation for simulator */
  q[8] = -varargin_1[8];
  dq[8] = -varargin_2[8];

  /*  Always run controller */
  b_obj->isRun = true;

  /*        end % if */
  /*  Update PS3 controller */
  for (k = 0; k < 4; k++) {
    axes[k] = b_obj->ps3Axes[k];
  }

  for (k = 0; k < 17; k++) {
    buttons[k] = b_obj->ps3Buttons[k];
  }

  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  PROTECTED PROPERTIES ================================================== */
  /*  Joysticks */
  /*  Buttons */
  /*  properties */
  /*  PUBLIC METHODS ======================================================== */
  /* PS3CONTROLLER PS3 controller class constructor. */
  /*  Initialize buttons */
  /*  PS3Controller */
  /* UPDATE Update PS3 controller object with controller data. */
  /*  Update joysticks */
  b_obj->ps3.leftStickY = -axes[1];
  b_obj->ps3.rightStickX = -axes[2];

  /*  Convert button vector to logical */
  for (k = 0; k < 17; k++) {
    b_buttons[k] = buttons[k] != 0.0;
  }

  /*  Update button objects */
  PS3Button_update(&b_obj->ps3._select, b_buttons[0]);
  PS3Button_update(&b_obj->ps3.l3, b_buttons[1]);
  PS3Button_update(&b_obj->ps3.r3, b_buttons[2]);
  PS3Button_update(&b_obj->ps3.start, b_buttons[3]);
  PS3Button_update(&b_obj->ps3.up, b_buttons[4]);
  PS3Button_update(&b_obj->ps3.right, b_buttons[5]);
  PS3Button_update(&b_obj->ps3.down, b_buttons[6]);
  PS3Button_update(&b_obj->ps3.left, b_buttons[7]);
  PS3Button_update(&b_obj->ps3.l2, b_buttons[8]);
  PS3Button_update(&b_obj->ps3.r2, b_buttons[9]);
  PS3Button_update(&b_obj->ps3.l1, b_buttons[10]);
  PS3Button_update(&b_obj->ps3.r1, b_buttons[11]);
  PS3Button_update(&b_obj->ps3.triangle, b_buttons[12]);
  PS3Button_update(&b_obj->ps3.circle, b_buttons[13]);
  PS3Button_update(&b_obj->ps3.cross, b_buttons[14]);
  PS3Button_update(&b_obj->ps3.square, b_buttons[15]);
  PS3Button_update(&b_obj->ps3.ps, b_buttons[16]);

  /*  Parse start button data */
  if (b_obj->ps3.start.clickDuration > 1.0) {
    b_obj->isRun = true;
  } else {
    if (b_obj->ps3.start.isPressed) {
      b_obj->isRun = false;
    }
  }

  /*  if */
  /*  Parse PS button data */
  *varargout_1 = b_obj->ps3.ps.isPressed;

  /*  if */
  /*  Run controller logic */
  if (b_obj->isRun) {
    if (b_obj->switch_phase_last != b_obj->switch_phase) {
      b_obj->runTime = 0.0;
    } else {
      /*  Update run time */
      b_obj->runTime += 0.0005;
    }

    /*  Run controller */
    MikhailController_MARLO_Steeringv2_userStep(moduleInstance, b_obj, q, dq,
      varargin_3, varargin_4, varargin_5, varargin_6, varargout_2, varargout_5,
      varargout_6, varargout_7);

    /*  Enable ramp up sequence */
    /*          if ~obj.isSim */
    /*            % Slowly increase torque limit */
    /*            u_lim = obj.u_lim*clamp(obj.runTime/2, 0, 1); */
    /*   */
    /*            % Limit torque commands */
    /*            u = clamp(u, -u_lim, u_lim); */
    /*          end % if */
  } else {
    /*  Reset run time */
    b_obj->runTime = 0.0;

    /*  Run controller specific initialization */
    MikhailController_MARLO_Steeringv2_userSetup(b_obj);

    /*  Damping gains */
    /*  Leg actuator torques computed to behave like virtual dampers */
    for (k = 0; k < 4; k++) {
      varargout_2[iv4[k]] = (0.0 - dq[1 + (k << 1)]) * 150.0;
    }

    for (k = 0; k < 2; k++) {
      varargout_2[2 + 3 * k] = (0.0 - dq[8 + k]) * 50.0;
    }

    for (k = 0; k < 6; k++) {
      varargout_5[k] = 0.0;
      varargout_6[k] = 0.0;
    }

    *varargout_7 = 0.0;
  }

  /*  if */
  /*  Limit torque commands */
  a_max = -b_obj->u_lim;
  lim2 = b_obj->u_lim;

  /*  stepImpl */
  /*  methods */
  /*  classdef */
  /* % LOCAL FUNCTIONS ======================================================== */
  /* CLAMP Clamp value between two bounds. */
  /*  Find which limit is min and max */
  a_min = muDoubleScalarMin(a_max, lim2);
  a_max = muDoubleScalarMax(a_max, lim2);

  /*  Clamp value between limits */
  for (k = 0; k < 6; k++) {
    /*        % Simulation overrides */
    /*        if obj.isSim */
    /*          % Coordinate transformation for simulator */
    varargout_2[k] = -muDoubleScalarMax(muDoubleScalarMin(varargout_2[k], a_max),
      a_min);
  }

  /*          u([3 6]) = -u([3 6]); */
  varargout_2[2] = -varargout_2[2];

  /*        end % if */
  /*  User output */
  a_min = b_obj->dy_est + b_obj->dy_est_last;
  a_max = b_obj->dx_est;
  a_max = b_obj->t_gain * muDoubleScalarAbs(a_max);

  /* CLAMP Clamp value between two bounds. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  Find which limit is min and max */
  /*  Clamp value between limits */
  /*  clamp */
  lim2 = b_obj->t;
  a_max = b_obj->t0_step - muDoubleScalarMax(muDoubleScalarMin(a_max, 0.1), 0.0);
  varargout_3[0] = b_obj->dx_est;
  varargout_3[1] = a_min / 2.0;
  varargout_3[2] = b_obj->sDDA;
  varargout_3[3] = b_obj->dx_est_last;
  varargout_3[4] = b_obj->tauPhase;
  varargout_3[5] = lim2 / a_max;
  varargout_3[6] = b_obj->switch_phase;
  varargout_3[7] = b_obj->x_est;
  varargout_3[8] = b_obj->y_est;
  *varargout_4 = 0.0;
}

static void PS3Button_update(PS3Button *obj, boolean_T value)
{
  boolean_T b0;
  real_T b;

  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  PROTECTED PROPERTIES ================================================== */
  /*  Current button state */
  /*  Button was just pushed */
  /*  Button was just released */
  /*  Duration button has been held down */
  /*  Number of button presses */
  /*  Time since initialization (s) */
  /*  Time at which button was last pressed (s) */
  /*  Fixed sample interval time (s) */
  /*  Acceptable interval to count click (s) */
  /*  properties */
  /*  PUBLIC METHODS ======================================================== */
  /* UPDATE Update PS3 button object with controller data. */
  /*  Update time */
  obj->time += obj->sampleInterval;

  /*  Check if button was pressed */
  if (!obj->value && value) {
    b0 = true;
  } else {
    b0 = false;
  }

  obj->isPressed = b0;

  /*  Check if button was released */
  /*  Update click duration */
  if (obj->isPressed) {
    obj->timePressed = obj->time;
  } else {
    b = obj->time - obj->timePressed;
    obj->clickDuration = (real_T)value * b;
  }

  /*  if */
  /*  Update click count */
  if (obj->time - obj->timePressed < obj->clickInterval) {
    obj->clickCount += (real_T)obj->isPressed;
  } else {
    obj->clickCount = 0.0;
  }

  /*  if */
  /*  Update button state */
  obj->value = value;
}

static void MikhailController_MARLO_Steeringv2_userStep
  (InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance,
   MikhailController_MARLO_Steeringv2_2 *obj, real_T q[13], real_T dq[13],
   real_T ControlState[2], real_T ControlParams[2], real_T theta_limits_nom[2],
   real_T HAlphaDDA[36], real_T u[6], real_T y_out[6], real_T dy_out[6], real_T *
   s)
{
  real_T q_st_mA;
  real_T dq_st_mA;
  real_T q_st_mB;
  real_T dq_st_mB;
  real_T q_st_lA;
  real_T dq_st_lA;
  real_T q_st_lB;
  real_T dq_st_lB;
  real_T q_st_h;
  real_T dq_st_h;
  real_T q_sw_mA;
  real_T dq_sw_mA;
  real_T q_sw_mB;
  real_T dq_sw_mB;
  real_T q_sw_lA;
  real_T dq_sw_lA;
  real_T q_sw_lB;
  real_T dq_sw_lB;
  real_T q_sw_h;
  real_T dq_sw_h;
  real_T l_st_h;
  real_T l_sw_h;
  real_T x_t;
  real_T y_t;
  real_T dx;
  real_T dy;
  real_T fz_st;
  real_T fz_sw;
  real_T s_st;
  real_T s_sw;
  real_T u_st_A;
  real_T u_st_B;
  real_T theta_limits[2];
  int32_T runTimeDelay;
  real_T kp;
  real_T ds;
  real_T dv0[2];
  real_T b_obj[2];
  real_T dv1[4];
  real_T c_obj[4];
  real_T A[4];
  real_T dl_st;
  real_T l_st;
  real_T b_q_st_lA[2];
  real_T q_st;
  real_T b_dq_st_lA[2];
  creal_T dc0;
  real_T d0;
  real_T d1;
  real_T dq_st_mA_tgt;
  real_T d2;
  real_T d3;
  real_T dq_st_mB_tgt;
  real_T dv2[3];
  real_T d_obj[3];
  real_T b_A[3];
  real_T dl_sw;
  real_T l_sw;
  boolean_T b;
  real_T e_obj[2];
  real_T c_A[2];
  real_T q_sw;
  real_T d4;
  real_T d5;
  real_T dq_sw_mA_tgt;
  real_T d6;
  real_T d7;
  real_T dq_sw_mB_tgt;
  real_T f_obj[2];
  real_T g_obj[2];
  real_T L;
  real_T dq_sw_h_tgt;
  real_T q_sw_h_tgt;
  real_T kd;
  real_T dv3[24];
  int32_T i2;
  real_T dv4[24];
  obj->t += 0.0005;
  MikhailController_MARLO_Steeringv2_parsePS3Controller(obj, ControlParams);
  if (obj->stanceLeg == 1.0) {
    q_st_mA = q[7];
    dq_st_mA = dq[7];
    q_st_mB = q[5];
    dq_st_mB = dq[5];
    q_st_lA = q[6];
    dq_st_lA = dq[6];
    q_st_lB = q[4];
    dq_st_lB = dq[4];
    q_st_h = q[9];
    dq_st_h = dq[9];
    q_sw_mA = q[3];
    dq_sw_mA = dq[3];
    q_sw_mB = q[1];
    dq_sw_mB = dq[1];
    q_sw_lA = q[2];
    dq_sw_lA = dq[2];
    q_sw_lB = q[0];
    dq_sw_lB = dq[0];
    q_sw_h = q[8];
    dq_sw_h = dq[8];
  } else {
    q_st_mA = q[3];
    dq_st_mA = dq[3];
    q_st_mB = q[1];
    dq_st_mB = dq[1];
    q_st_lA = q[2];
    dq_st_lA = dq[2];
    q_st_lB = q[0];
    dq_st_lB = dq[0];
    q_st_h = q[8];
    dq_st_h = dq[8];
    q_sw_mA = q[7];
    dq_sw_mA = dq[7];
    q_sw_mB = q[5];
    dq_sw_mB = dq[5];
    q_sw_lA = q[6];
    dq_sw_lA = dq[6];
    q_sw_lB = q[4];
    dq_sw_lB = dq[4];
    q_sw_h = q[9];
    dq_sw_h = dq[9];
  }

  obj->q_yaw = q[11];
  l_st_h = 0.1831 * obj->stanceLeg;
  l_sw_h = -0.1831 * obj->stanceLeg;
  x_t = obj->x_offset * muDoubleScalarCos(q[12]) + obj->z_offset *
    muDoubleScalarCos(q[10]) * muDoubleScalarSin(q[12]) + obj->y_offset *
    muDoubleScalarSin(q[12]) * muDoubleScalarSin(q[10]);
  y_t = obj->y_offset * muDoubleScalarCos(q[10]) - obj->z_offset *
    muDoubleScalarSin(q[10]);
  dx = muDoubleScalarSin(q[12]) * muDoubleScalarSin(q_st_lA) * dq[12] / 2.0 -
    muDoubleScalarCos(q[12]) * muDoubleScalarCos(q_st_lB) * dq_st_lB / 2.0 -
    muDoubleScalarCos(q[12]) * muDoubleScalarCos(q_st_lA) * dq_st_lA / 2.0 +
    muDoubleScalarSin(q[12]) * muDoubleScalarSin(q_st_lB) * dq[12] / 2.0 -
    obj->x_offset * muDoubleScalarSin(q[12]) * dq[12] + obj->z_offset *
    muDoubleScalarCos(q[12]) * muDoubleScalarCos(q[10]) * dq[12] + obj->y_offset
    * muDoubleScalarCos(q[12]) * muDoubleScalarSin(q[10]) * dq[12] +
    obj->y_offset * muDoubleScalarCos(q[10]) * muDoubleScalarSin(q[12]) * dq[10]
    - obj->z_offset * muDoubleScalarSin(q[12]) * muDoubleScalarSin(q[10]) * dq
    [10] - muDoubleScalarCos(q[12]) * muDoubleScalarCos(q[10]) *
    muDoubleScalarCos(q_st_h) * muDoubleScalarCos(q_st_lA) * dq[12] / 2.0 -
    muDoubleScalarCos(q[12]) * muDoubleScalarCos(q[10]) * muDoubleScalarCos
    (q_st_h) * muDoubleScalarCos(q_st_lB) * dq[12] / 2.0 + muDoubleScalarCos(q
    [12]) * muDoubleScalarCos(q_st_lA) * muDoubleScalarSin(q[10]) *
    muDoubleScalarSin(q_st_h) * dq[12] / 2.0 + muDoubleScalarCos(q[12]) *
    muDoubleScalarCos(q_st_lB) * muDoubleScalarSin(q[10]) * muDoubleScalarSin
    (q_st_h) * dq[12] / 2.0 + muDoubleScalarCos(q[10]) * muDoubleScalarCos
    (q_st_lA) * muDoubleScalarSin(q[12]) * muDoubleScalarSin(q_st_h) * dq[10] /
    2.0 + muDoubleScalarCos(q_st_h) * muDoubleScalarCos(q_st_lA) *
    muDoubleScalarSin(q[12]) * muDoubleScalarSin(q[10]) * dq[10] / 2.0 +
    muDoubleScalarCos(q[10]) * muDoubleScalarCos(q_st_lB) * muDoubleScalarSin(q
    [12]) * muDoubleScalarSin(q_st_h) * dq[10] / 2.0 + muDoubleScalarCos(q_st_h)
    * muDoubleScalarCos(q_st_lB) * muDoubleScalarSin(q[12]) * muDoubleScalarSin
    (q[10]) * dq[10] / 2.0 + muDoubleScalarCos(q[10]) * muDoubleScalarCos
    (q_st_lA) * muDoubleScalarSin(q[12]) * muDoubleScalarSin(q_st_h) * dq_st_h /
    2.0 + muDoubleScalarCos(q_st_h) * muDoubleScalarCos(q_st_lA) *
    muDoubleScalarSin(q[12]) * muDoubleScalarSin(q[10]) * dq_st_h / 2.0 +
    muDoubleScalarCos(q[10]) * muDoubleScalarCos(q_st_lB) * muDoubleScalarSin(q
    [12]) * muDoubleScalarSin(q_st_h) * dq_st_h / 2.0 + muDoubleScalarCos(q_st_h)
    * muDoubleScalarCos(q_st_lB) * muDoubleScalarSin(q[12]) * muDoubleScalarSin
    (q[10]) * dq_st_h / 2.0 + muDoubleScalarCos(q[10]) * muDoubleScalarCos
    (q_st_h) * muDoubleScalarSin(q[12]) * muDoubleScalarSin(q_st_lA) * dq_st_lA /
    2.0 + muDoubleScalarCos(q[10]) * muDoubleScalarCos(q_st_h) *
    muDoubleScalarSin(q[12]) * muDoubleScalarSin(q_st_lB) * dq_st_lB / 2.0 -
    l_st_h * muDoubleScalarCos(q[12]) * muDoubleScalarCos(q[10]) *
    muDoubleScalarSin(q_st_h) * dq[12] - l_st_h * muDoubleScalarCos(q[12]) *
    muDoubleScalarCos(q_st_h) * muDoubleScalarSin(q[10]) * dq[12] - l_st_h *
    muDoubleScalarCos(q[10]) * muDoubleScalarCos(q_st_h) * muDoubleScalarSin(q
    [12]) * dq[10] - l_st_h * muDoubleScalarCos(q[10]) * muDoubleScalarCos
    (q_st_h) * muDoubleScalarSin(q[12]) * dq_st_h - muDoubleScalarSin(q[12]) *
    muDoubleScalarSin(q[10]) * muDoubleScalarSin(q_st_h) * muDoubleScalarSin
    (q_st_lA) * dq_st_lA / 2.0 - muDoubleScalarSin(q[12]) * muDoubleScalarSin(q
    [10]) * muDoubleScalarSin(q_st_h) * muDoubleScalarSin(q_st_lB) * dq_st_lB /
    2.0 + l_st_h * muDoubleScalarSin(q[12]) * muDoubleScalarSin(q[10]) *
    muDoubleScalarSin(q_st_h) * dq[10] + l_st_h * muDoubleScalarSin(q[12]) *
    muDoubleScalarSin(q[10]) * muDoubleScalarSin(q_st_h) * dq_st_h;
  dy = l_st_h * muDoubleScalarCos(q[10]) * muDoubleScalarSin(q_st_h) * dq[10] -
    obj->y_offset * muDoubleScalarSin(q[10]) * dq[10] - muDoubleScalarCos
    (q_st_lA) * muDoubleScalarSin(q[10]) * muDoubleScalarSin(q_st_h) * dq[10] /
    2.0 - muDoubleScalarCos(q_st_lB) * muDoubleScalarSin(q[10]) *
    muDoubleScalarSin(q_st_h) * dq[10] / 2.0 - muDoubleScalarCos(q_st_lA) *
    muDoubleScalarSin(q[10]) * muDoubleScalarSin(q_st_h) * dq_st_h / 2.0 -
    muDoubleScalarCos(q_st_lB) * muDoubleScalarSin(q[10]) * muDoubleScalarSin
    (q_st_h) * dq_st_h / 2.0 - muDoubleScalarCos(q[10]) * muDoubleScalarSin
    (q_st_h) * muDoubleScalarSin(q_st_lA) * dq_st_lA / 2.0 - muDoubleScalarCos
    (q_st_h) * muDoubleScalarSin(q[10]) * muDoubleScalarSin(q_st_lA) * dq_st_lA /
    2.0 - muDoubleScalarCos(q[10]) * muDoubleScalarSin(q_st_h) *
    muDoubleScalarSin(q_st_lB) * dq_st_lB / 2.0 - muDoubleScalarCos(q_st_h) *
    muDoubleScalarSin(q[10]) * muDoubleScalarSin(q_st_lB) * dq_st_lB / 2.0 -
    obj->z_offset * muDoubleScalarCos(q[10]) * dq[10] + l_st_h *
    muDoubleScalarCos(q_st_h) * muDoubleScalarSin(q[10]) * dq[10] + l_st_h *
    muDoubleScalarCos(q[10]) * muDoubleScalarSin(q_st_h) * dq_st_h + l_st_h *
    muDoubleScalarCos(q_st_h) * muDoubleScalarSin(q[10]) * dq_st_h +
    muDoubleScalarCos(q[10]) * muDoubleScalarCos(q_st_h) * muDoubleScalarCos
    (q_st_lA) * dq[10] / 2.0 + muDoubleScalarCos(q[10]) * muDoubleScalarCos
    (q_st_h) * muDoubleScalarCos(q_st_lB) * dq[10] / 2.0 + muDoubleScalarCos(q
    [10]) * muDoubleScalarCos(q_st_h) * muDoubleScalarCos(q_st_lA) * dq_st_h /
    2.0 + muDoubleScalarCos(q[10]) * muDoubleScalarCos(q_st_h) *
    muDoubleScalarCos(q_st_lB) * dq_st_h / 2.0;
  obj->dx = dx;
  obj->dy = dy;
  fz_st = 18162.9 * (muDoubleScalarCos(q[12] + q_st_lB) * (q_st_mA - q_st_lA) -
                     muDoubleScalarCos(q[12] + q_st_lA) * (q_st_mB - q_st_lB)) /
    muDoubleScalarSin(q_st_lA - q_st_lB);
  fz_sw = 18162.9 * (muDoubleScalarCos(q[12] + q_sw_lB) * (q_sw_mA - q_sw_lA) -
                     muDoubleScalarCos(q[12] + q_sw_lA) * (q_sw_mB - q_sw_lB)) /
    muDoubleScalarSin(q_sw_lA - q_sw_lB);
  s_st = scaleFactor(fz_st, obj->thres_lo, obj->thres_hi);
  s_sw = scaleFactor(fz_sw, obj->thres_lo, obj->thres_hi);
  obj->Jz = obj->Jz + s_st * fz_st * 0.0005 + s_sw * fz_sw * 0.0005;
  fz_sw = obj->tau + 0.0005;
  fz_st = s_st * 0.0005 / fz_sw;
  u_st_A = fz_st * (dx - obj->dx_est);
  obj->dx_est += u_st_A * (real_T)(muDoubleScalarAbs(dx) < 4.0);
  u_st_A = fz_st * (dy - obj->dy_est);
  obj->dy_est += u_st_A * (real_T)(muDoubleScalarAbs(dy) < 1.0);
  if ((int32_T)obj->isTest9 == 1) {
    u_st_B = obj->q_yaw;
    fz_st = obj->q_yaw;
    obj->x_est += 0.0005 * (muDoubleScalarCos(u_st_B) * obj->dx_est +
      muDoubleScalarSin(fz_st) * obj->dy_est);
    u_st_B = obj->q_yaw;
    fz_st = obj->q_yaw;
    obj->y_est += 0.0005 * (muDoubleScalarSin(u_st_B) * obj->dx_est +
      muDoubleScalarCos(fz_st) * obj->dy_est);
  } else {
    u_st_B = obj->q_yaw;
    fz_st = obj->q_yaw;
    obj->x_est += muDoubleScalarMax(s_st, s_sw) * 0.0005 * (muDoubleScalarCos
      (u_st_B) * obj->dx_est + muDoubleScalarSin(fz_st) * obj->dy_est);
    u_st_B = obj->q_yaw;
    fz_st = obj->q_yaw;
    obj->y_est += muDoubleScalarMax(s_st, s_sw) * 0.0005 * (muDoubleScalarSin
      (u_st_B) * obj->dx_est + muDoubleScalarCos(fz_st) * obj->dy_est);
  }

  u_st_B = obj->dx_est;
  dx = obj->t0_step - clamp(obj->t_gain * muDoubleScalarAbs(u_st_B), 0.0, 0.1);
  if (ControlState[0] == 1.0) {
    dx = 10000.0;
  }

  obj->theta = q[12] + (q_st_lA + q_st_lB) / 2.0;
  for (runTimeDelay = 0; runTimeDelay < 2; runTimeDelay++) {
    theta_limits[runTimeDelay] = theta_limits_nom[runTimeDelay] +
      1.5707963267948966;
  }

  kp = obj->theta - theta_limits[0];
  obj->sDDA = kp / (theta_limits[1] - theta_limits[0]);
  u_st_B = obj->dx_est_last - obj->dx_est;
  u_st_A = scaleFactor(obj->dx_est, 0.4, 0.8) * 50.0;
  fz_st = u_st_A * (real_T)(muDoubleScalarAbs(u_st_B) < 0.1);
  obj->tauPhase += 0.0005 * (1.0 / dx + fz_st * (obj->sDDA - obj->tauPhase));
  if ((int32_T)obj->isSim == 1) {
    runTimeDelay = 2;
  } else {
    runTimeDelay = 10;
  }

  if ((fz_st >= 30.0 && obj->sDDA >= 0.35 && obj->sDDA <= 0.4 &&
       obj->switch_phase == 0.0 && obj->runTime >= (real_T)runTimeDelay) ||
      (obj->dx_est >= 0.1 && obj->switch_phase == 1.0) || (int32_T)obj->isTest11
      == 1) {
    obj->switch_phase = 1.0;
  } else {
    obj->switch_phase = 0.0;
  }

  if (obj->switch_phase == 0.0) {
    kp = obj->t;
    *s = clamp(kp / dx, 0.0, 1.0);
    ds = 1.0 / dx;
  } else {
    *s = clamp(obj->sDDA, 0.0, 1.0);
    ds = (dq[12] + (dq_st_lA + dq_st_lB) / 2.0) / (theta_limits[1] -
      theta_limits[0]);
  }

  u_st_B = obj->dx_est;
  for (runTimeDelay = 0; runTimeDelay < 2; runTimeDelay++) {
    theta_limits[runTimeDelay] = 2.0 * (real_T)runTimeDelay;
    dv0[runTimeDelay] = 0.0;
  }

  b_obj[0] = obj->s_overlap;
  b_obj[1] = 0.0;
  dy = cubic_interp(theta_limits, b_obj, dv0, muDoubleScalarAbs(u_st_B), 0.0);
  u_st_B = obj->dx_tgt;
  fz_st = obj->dx_tgt;
  fz_sw = obj->dx_est;
  u_st_A = obj->l_ext_gain * muDoubleScalarAbs(u_st_B);
  fz_st = clamp(u_st_A * (real_T)(muDoubleScalarSign(fz_st) ==
    muDoubleScalarSign(fz_sw)), 0.0, 0.96 - obj->l0_leg);
  kp = obj->dl_st_last;
  dv1[0] = 0.0;
  dv1[1] = dy;
  dv1[2] = 0.4;
  dv1[3] = 1.0;
  c_obj[0] = obj->l_st_last;
  c_obj[1] = obj->l0_leg;
  c_obj[2] = obj->l0_leg;
  c_obj[3] = obj->l0_leg + fz_st;
  A[0] = kp / ds;
  A[1] = 0.0;
  A[2] = 0.0;
  A[3] = 0.0;
  b_cubic_interp(moduleInstance, dv1, c_obj, A, *s, ds, &l_st, &dl_st);
  if (obj->isTest2) {
    obj->Jz_tgt = 1.05 * *s * 61.24 * 9.81 * dx;
    u_st_B = obj->dx_est;
    u_st_A = 0.002 * (obj->Jz_tgt - obj->Jz);
    l_st += clamp(u_st_A * (real_T)(muDoubleScalarAbs(u_st_B) > 1.0), -0.02,
                  0.02);
  }

  b_q_st_lA[0] = q_st_lA;
  b_q_st_lA[1] = q_st_lB;
  q_st = mean(b_q_st_lA);
  b_dq_st_lA[0] = dq_st_lA;
  b_dq_st_lA[1] = dq_st_lB;
  fz_sw = mean(b_dq_st_lA);
  dc0.re = 1.0 - l_st * l_st;
  dc0.im = 0.0;
  eml_scalar_sqrt(&dc0);
  if (dc0.im == 0.0) {
    fz_st = dl_st / dc0.re;
  } else if (dc0.re == 0.0) {
    if (dl_st == 0.0) {
      fz_st = 0.0 / dc0.im;
    } else {
      fz_st = 0.0;
    }
  } else {
    fz_st = muDoubleScalarAbs(dc0.re);
    dx = muDoubleScalarAbs(dc0.im);
    if (fz_st > dx) {
      fz_st = dc0.im / dc0.re;
      fz_st = (dl_st + fz_st * 0.0) / (dc0.re + fz_st * dc0.im);
    } else if (dx == fz_st) {
      if (dc0.re > 0.0) {
        d0 = 0.5;
      } else {
        d0 = -0.5;
      }

      if (dc0.im > 0.0) {
        d1 = 0.5;
      } else {
        d1 = -0.5;
      }

      fz_st = (dl_st * d0 + 0.0 * d1) / fz_st;
    } else {
      fz_st = dc0.re / dc0.im;
      fz_st = fz_st * dl_st / (dc0.im + fz_st * dc0.re);
    }
  }

  dq_st_mA_tgt = fz_sw + fz_st;
  dc0.re = 1.0 - l_st * l_st;
  dc0.im = 0.0;
  eml_scalar_sqrt(&dc0);
  if (dc0.im == 0.0) {
    fz_st = dl_st / dc0.re;
  } else if (dc0.re == 0.0) {
    if (dl_st == 0.0) {
      fz_st = 0.0 / dc0.im;
    } else {
      fz_st = 0.0;
    }
  } else {
    fz_st = muDoubleScalarAbs(dc0.re);
    dx = muDoubleScalarAbs(dc0.im);
    if (fz_st > dx) {
      fz_st = dc0.im / dc0.re;
      fz_st = (dl_st + fz_st * 0.0) / (dc0.re + fz_st * dc0.im);
    } else if (dx == fz_st) {
      if (dc0.re > 0.0) {
        d2 = 0.5;
      } else {
        d2 = -0.5;
      }

      if (dc0.im > 0.0) {
        d3 = 0.5;
      } else {
        d3 = -0.5;
      }

      fz_st = (dl_st * d2 + 0.0 * d3) / fz_st;
    } else {
      fz_st = dc0.re / dc0.im;
      fz_st = fz_st * dl_st / (dc0.im + fz_st * dc0.re);
    }
  }

  dq_st_mB_tgt = fz_sw - fz_st;
  kp = obj->dl_sw_last;
  dv2[0] = 0.0;
  dv2[1] = 0.35 + dy / 2.0;
  dv2[2] = 1.0 + dy;
  d_obj[0] = obj->l_sw_last;
  d_obj[1] = obj->l0_leg - obj->l_ret;
  d_obj[2] = obj->l0_leg;
  b_A[0] = kp / ds;
  b_A[1] = 0.0;
  b_A[2] = 0.0;
  c_cubic_interp(moduleInstance, dv2, d_obj, b_A, *s, ds, &l_sw, &dl_sw);
  fz_st = obj->dx_gain * obj->dx_est + obj->dx_err_p_gain * (obj->dx_est -
    obj->dx_tgt) + obj->dx_err_d_gain * (obj->dx_est - obj->dx_est_last);
  fz_st = atans(fz_st, 1.0, 1.0);
  kp = obj->dx_sw_last;
  dx = -obj->dx_est;
  b = obj->isTest4;
  for (runTimeDelay = 0; runTimeDelay < 2; runTimeDelay++) {
    theta_limits[runTimeDelay] = 0.8 * (real_T)runTimeDelay;
  }

  e_obj[0] = obj->x_sw_last;
  e_obj[1] = fz_st;
  c_A[0] = kp / ds;
  c_A[1] = dx / ds * (real_T)b;
  d_cubic_interp(theta_limits, e_obj, c_A, *s, ds, &fz_sw, &dx);
  kp = (fz_sw + x_t) / l_sw;
  b_asin(&kp);
  q_sw = 3.1415926535897931 - q[12] - kp;
  u_st_A = fz_sw + x_t;
  fz_st = u_st_A * u_st_A / (l_sw * l_sw);
  if (1.0 - fz_st < 0.0) {
    b_eml_error();
  }

  fz_sw = -((dx / l_sw - (fz_sw + x_t) * dl_sw / (l_sw * l_sw)) /
            muDoubleScalarSqrt(1.0 - fz_st)) - dq[12];
  dc0.re = 1.0 - l_sw * l_sw;
  dc0.im = 0.0;
  eml_scalar_sqrt(&dc0);
  if (dc0.im == 0.0) {
    fz_st = dl_sw / dc0.re;
  } else if (dc0.re == 0.0) {
    if (dl_sw == 0.0) {
      fz_st = 0.0 / dc0.im;
    } else {
      fz_st = 0.0;
    }
  } else {
    fz_st = muDoubleScalarAbs(dc0.re);
    dx = muDoubleScalarAbs(dc0.im);
    if (fz_st > dx) {
      fz_st = dc0.im / dc0.re;
      fz_st = (dl_sw + fz_st * 0.0) / (dc0.re + fz_st * dc0.im);
    } else if (dx == fz_st) {
      if (dc0.re > 0.0) {
        d4 = 0.5;
      } else {
        d4 = -0.5;
      }

      if (dc0.im > 0.0) {
        d5 = 0.5;
      } else {
        d5 = -0.5;
      }

      fz_st = (dl_sw * d4 + 0.0 * d5) / fz_st;
    } else {
      fz_st = dc0.re / dc0.im;
      fz_st = fz_st * dl_sw / (dc0.im + fz_st * dc0.re);
    }
  }

  dq_sw_mA_tgt = fz_sw + fz_st;
  dc0.re = 1.0 - l_sw * l_sw;
  dc0.im = 0.0;
  eml_scalar_sqrt(&dc0);
  if (dc0.im == 0.0) {
    fz_st = dl_sw / dc0.re;
  } else if (dc0.re == 0.0) {
    if (dl_sw == 0.0) {
      fz_st = 0.0 / dc0.im;
    } else {
      fz_st = 0.0;
    }
  } else {
    fz_st = muDoubleScalarAbs(dc0.re);
    dx = muDoubleScalarAbs(dc0.im);
    if (fz_st > dx) {
      fz_st = dc0.im / dc0.re;
      fz_st = (dl_sw + fz_st * 0.0) / (dc0.re + fz_st * dc0.im);
    } else if (dx == fz_st) {
      if (dc0.re > 0.0) {
        d6 = 0.5;
      } else {
        d6 = -0.5;
      }

      if (dc0.im > 0.0) {
        d7 = 0.5;
      } else {
        d7 = -0.5;
      }

      fz_st = (dl_sw * d6 + 0.0 * d7) / fz_st;
    } else {
      fz_st = dc0.re / dc0.im;
      fz_st = fz_st * dl_sw / (dc0.im + fz_st * dc0.re);
    }
  }

  dq_sw_mB_tgt = fz_sw - fz_st;
  u_st_B = obj->dx_est;
  kp = obj->dy_est + obj->dy_est_last;
  dx = obj->dy_est + obj->dy_est_last;
  fz_st = -obj->stanceLeg * (obj->y0_offset - obj->y0_gain * muDoubleScalarAbs
    (u_st_B)) + obj->dy_gain * obj->dy_est + obj->dy_err_p_gain * (kp / 2.0 -
    obj->dy_tgt) + obj->dy_err_d_gain * (dx / 2.0 - obj->dy_est_avg);
  if (obj->isTest2) {
    for (runTimeDelay = 0; runTimeDelay < 2; runTimeDelay++) {
      theta_limits[runTimeDelay] = 0.8 * (real_T)runTimeDelay;
    }

    f_obj[0] = obj->y_sw_last;
    f_obj[1] = fz_st;
    g_obj[0] = obj->dy_sw_last;
    g_obj[1] = 0.0;
    d_cubic_interp(theta_limits, f_obj, g_obj, *s, ds, &fz_st, &dx);
  } else {
    dx = 0.0;
  }

  u_st_A = obj->l0_leg;
  u_st_B = u_st_A * u_st_A + l_sw_h * l_sw_h;
  if (u_st_B < 0.0) {
    b_eml_error();
  }

  L = muDoubleScalarSqrt(u_st_B);
  kp = (fz_st + y_t) / L;
  b_asin(&kp);
  dy = l_sw_h / L;
  b_asin(&dy);
  u_st_A = fz_st + y_t;
  fz_st = u_st_A * u_st_A;
  fz_sw = L * L;
  if (1.0 - fz_st / fz_sw < 0.0) {
    b_eml_error();
  }

  dq_sw_h_tgt = dx / (L * muDoubleScalarSqrt(1.0 - fz_st / fz_sw));
  q_sw_h_tgt = clamp(kp - dy, -0.26179938779914941 * obj->stanceLeg,
                     muDoubleScalarMin(0.13962634015954636, 0.26179938779914941
    - muDoubleScalarAbs(q_st_h)) * obj->stanceLeg);
  kp = s_st * obj->kp_st_leg + (1.0 - s_st) * obj->kp_sw_leg;
  kd = s_st * obj->kd_st_leg + (1.0 - s_st) * obj->kd_sw_leg;
  if ((int32_T)obj->isTest6 == 0) {
    dc0.re = l_st;
    dc0.im = 0.0;
    b_acos(&dc0);
    u_st_A = 0.0 * muDoubleScalarSign(dq_st_mA_tgt) + 0.0 * dq_st_mA_tgt + kp *
      (q_st - dc0.re - q_st_mA) + kd * (dq_st_mA_tgt - dq_st_mA);
    dc0.re = l_st;
    dc0.im = 0.0;
    b_acos(&dc0);
    u_st_B = 0.0 * muDoubleScalarSign(dq_st_mB_tgt) + 0.0 * dq_st_mB_tgt + kp *
      (q_st + dc0.re - q_st_mB) + kd * (dq_st_mB_tgt - dq_st_mB);
  } else {
    u_st_A = obj->kp_st_leg * (2.8274333882308138 - q_st_lA) + obj->kd_st_leg *
      (0.0 - dq_st_lA);
    u_st_B = obj->kp_st_leg * (3.4557519189487729 - q_st_lB) + obj->kd_st_leg *
      (0.0 - dq_st_lB);
  }

  kp = s_sw * obj->kp_st_leg + (1.0 - s_sw) * obj->kp_sw_leg;
  kd = s_sw * obj->kd_st_leg + (1.0 - s_sw) * obj->kd_sw_leg;
  if ((int32_T)obj->isTest6 == 0) {
    dc0.re = l_sw;
    dc0.im = 0.0;
    b_acos(&dc0);
    dy = 0.0 * muDoubleScalarSign(dq_sw_mA_tgt) + 0.0 * dq_sw_mA_tgt + kp *
      (q_sw - dc0.re - q_sw_mA) + kd * (dq_sw_mA_tgt - dq_sw_mA);
    dc0.re = l_sw;
    dc0.im = 0.0;
    b_acos(&dc0);
    fz_sw = 0.0 * muDoubleScalarSign(dq_sw_mB_tgt) + 0.0 * dq_sw_mB_tgt + kp *
      (q_sw + dc0.re - q_sw_mB) + kd * (dq_sw_mB_tgt - dq_sw_mB);
  } else {
    dy = obj->kp_sw_leg * (2.5132741228718345 - q_sw_lA) + obj->kd_sw_leg * (0.0
      - dq_sw_lA);
    fz_sw = obj->kp_sw_leg * (3.7699111843077517 - q_sw_lB) + obj->kd_sw_leg *
      (0.0 - dq_sw_lB);
  }

  u_st_A += s_st * (obj->kp_st_leg * q[12] + obj->kd_st_leg * dq[12]);
  u_st_B += s_st * (obj->kp_st_leg * q[12] + obj->kd_st_leg * dq[12]);
  dy += s_sw * (obj->kp_st_leg * q[12] + obj->kd_st_leg * dq[12]);
  fz_sw += s_sw * (obj->kp_st_leg * q[12] + obj->kd_st_leg * dq[12]);
  if (obj->isSim) {
    dx = 172.0674 * l_st_h;
    fz_st = 172.0674 * l_sw_h;
  } else {
    dx = obj->uHipGravity * 26.7 * obj->stanceLeg;
    fz_st = -obj->uHipGravity * 26.7 * obj->stanceLeg;
  }

  if (ControlState[0] == 1.0) {
    dx = obj->kp_hip * (0.034906585039886591 * obj->stanceLeg - q_st_h) +
      obj->kd_hip * (0.0 - dq_st_h);
    fz_st = obj->kp_hip * (-0.034906585039886591 * obj->stanceLeg - q_sw_h) +
      obj->kd_hip * (0.0 - dq_sw_h);
  } else if ((int32_T)obj->isTest7 == 1) {
    dx = dx + obj->kp_hip * ((2.0 + 5.0 * muDoubleScalarSin(6.2831853071795862 *
      *s)) * 3.1415926535897931 / 180.0 * obj->stanceLeg - q_st_h) + obj->kd_hip
      * (5.0 * muDoubleScalarCos(6.2831853071795862 * *s) * 2.0 *
         3.1415926535897931 * ds * 3.1415926535897931 / 180.0 * obj->stanceLeg -
         dq_st_h);
    fz_st = fz_st + obj->kp_hip * (-(2.0 + 5.0 * muDoubleScalarSin
      (6.2831853071795862 * *s)) * 3.1415926535897931 / 180.0 * obj->stanceLeg -
      q_sw_h) + obj->kd_hip * (-(5.0 * muDoubleScalarCos(6.2831853071795862 * *s))
      * 2.0 * 3.1415926535897931 * ds * 3.1415926535897931 / 180.0 *
      obj->stanceLeg - dq_sw_h);
  } else if ((int32_T)obj->isTest5 == 1) {
    if ((int32_T)obj->isTest11 == 1 || (int32_T)obj->isTest12 == 1) {
      dx = obj->kp_hip * (-0.034906585039886591 * obj->stanceLeg - q_st_h) +
        obj->kd_hip * (0.0 - dq_st_h);
      fz_st = obj->kp_hip * (0.034906585039886591 * obj->stanceLeg - q_sw_h) +
        obj->kd_hip * (0.0 - dq_sw_h);
    } else {
      dx += (1.0 - s_st) * (obj->kp_hip * (0.034906585039886591 * obj->stanceLeg
        - q_st_h) + obj->kd_hip * (0.0 - dq_st_h));
      fz_st += (1.0 - s_sw) * (obj->kp_hip * (-0.034906585039886591 *
        obj->stanceLeg - q_sw_h) + obj->kd_hip * (0.0 - dq_sw_h));
      dx += s_st * (obj->kp_hip * q[10] + obj->kd_hip * dq[10]);
      fz_st += s_sw * (obj->kp_hip * q[10] + obj->kd_hip * dq[10]);
    }
  } else {
    if ((int32_T)obj->isTest8 != 1) {
      if ((int32_T)obj->isTest10 == 1) {
        dx += (1.0 - s_st) * (obj->kp_hip * (0.034906585039886591 *
          obj->stanceLeg - q_st_h) + obj->kd_hip * (0.0 - dq_st_h));
        fz_st += (1.0 - s_sw) * (obj->kp_hip * (q_sw_h_tgt - q_sw_h) +
          obj->kd_hip * (dq_sw_h_tgt - dq_sw_h));
        dx += s_st * (obj->kp_hip * q[10] + obj->kd_hip * dq[10]);
        fz_st += s_sw * (obj->kp_hip * q[10] + obj->kd_hip * dq[10]);
      } else {
        if (obj->isTest2) {
          fz_st = fz_st + (1.0 - s_sw) * obj->kp_hip * (q_sw_h_tgt - q_sw_h) +
            obj->kd_hip * (dq_sw_h_tgt - dq_sw_h);
        } else {
          fz_st = fz_st + *s * (1.0 - s_sw) * obj->kp_hip * (q_sw_h_tgt - q_sw_h)
            + (1.0 - s_sw) * obj->kd_hip * (dq_sw_h_tgt - dq_sw_h);
        }

        dx = dx + s_st * (obj->kp_hip * q[10] + obj->kd_hip * dq[10]) + (1.0 -
          s_st) * obj->kd_hip * (0.0 - dq_st_h);
        fz_st += s_sw * (obj->kp_hip * q[10] + obj->kd_hip * dq[10]);
      }
    }
  }

  if (obj->switch_phase == 1.0 || (int32_T)obj->isTest12 == 1) {
    for (runTimeDelay = 0; runTimeDelay < 6; runTimeDelay++) {
      for (i2 = 0; i2 < 4; i2++) {
        dv3[i2 + (runTimeDelay << 2)] = HAlphaDDA[i2 + 6 * runTimeDelay];
      }
    }

    mldivide(dv3);
    for (runTimeDelay = 0; runTimeDelay < 24; runTimeDelay++) {
      dv4[runTimeDelay] = 6.2831853071795862 - dv3[runTimeDelay];
    }

    bezierval(moduleInstance, dv4, *s, dv1);
    for (runTimeDelay = 0; runTimeDelay < 4; runTimeDelay++) {
      obj->hd_q[runTimeDelay] = dv1[runTimeDelay];
    }

    if ((int32_T)obj->isTest12 == 1) {
      u_st_A = kp * obj->kp_rate * ((160.0 + 15.0 * (real_T)(*s > 0.5) - 15.0 *
                                     (real_T)(*s <= 0.5)) * 3.1415926535897931 /
        180.0 - q_st_mA) + kd * obj->kd_rate * -dq_st_mA;
      u_st_B = kp * obj->kp_rate * ((200.0 + 15.0 * (real_T)(*s > 0.5) - 15.0 *
                                     (real_T)(*s <= 0.5)) * 3.1415926535897931 /
        180.0 - q_st_mB) + kd * obj->kd_rate * -dq_st_mB;
      dy = kp * obj->kp_rate * ((160.0 + 15.0 * (real_T)(*s > 0.5) - 15.0 *
        (real_T)(*s <= 0.5)) * 3.1415926535897931 / 180.0 - q_sw_mA) + kd *
        obj->kd_rate * -dq_sw_mA;
      fz_sw = kp * obj->kp_rate * ((200.0 + 15.0 * (real_T)(*s > 0.5) - 15.0 *
        (real_T)(*s <= 0.5)) * 3.1415926535897931 / 180.0 - q_sw_mB) + kd *
        obj->kd_rate * -dq_sw_mB;
    } else {
      u_st_A = kp * obj->kp_rate * (obj->hd_q[0] - q_st_mA) + kd * obj->kd_rate *
        -dq_st_mA;
      u_st_B = kp * obj->kp_rate * (obj->hd_q[1] - q_st_mB) + kd * obj->kd_rate *
        -dq_st_mB;
      dy = kp * obj->kp_rate * (obj->hd_q[2] - q_sw_mA) + kd * obj->kd_rate *
        -dq_sw_mA;
      fz_sw = kp * obj->kp_rate * (obj->hd_q[3] - q_sw_mB) + kd * obj->kd_rate *
        -dq_sw_mB;
    }
  }

  if ((*s >= 0.7 && s_sw >= 1.0 && obj->switch_phase == 1.0) || (*s >= 1.0 &&
       obj->switch_phase == 0.0)) {
    obj->x_sw_last = l_st * muDoubleScalarSin(q[12] + q_st) - x_t;
    if (obj->isTest3) {
      obj->dx_sw_last = -obj->dx_est;
    } else {
      obj->dx_sw_last = 0.0;
    }

    kp = l_st_h / L;
    b_asin(&kp);
    obj->y_sw_last = L * muDoubleScalarSin(q[10] + q_st_h + kp) - y_t;
    obj->dy_sw_last = 0.0;
    obj->l_st_last = l_sw;
    obj->dl_st_last = dl_sw;
    obj->l_sw_last = l_st;
    obj->dl_sw_last = dl_st;
    kp = obj->dy_est + obj->dy_est_last;
    obj->dy_est_avg = kp / 2.0;
    obj->dx_est_last = obj->dx_est;
    obj->dy_est_last = obj->dy_est;
    obj->tauPhase = 0.0;
    obj->switch_phase_last = obj->switch_phase;
    obj->Jz = 0.0;
    obj->t = 0.0;
  }

  if (obj->stanceLeg == 1.0) {
    u[0] = obj->s_r_B * fz_sw;
    u[1] = obj->s_r_A * dy;
    u[2] = fz_st;
    u[3] = obj->s_l_B * u_st_B;
    u[4] = obj->s_l_A * u_st_A;
    u[5] = dx;
  } else {
    u[0] = obj->s_l_B * u_st_B;
    u[1] = obj->s_l_A * u_st_A;
    u[2] = dx;
    u[3] = obj->s_r_B * fz_sw;
    u[4] = obj->s_r_A * dy;
    u[5] = fz_st;
  }

  if (obj->switch_phase == 0.0 && (int32_T)obj->isTest12 == 0) {
    if ((int32_T)obj->isTest7 == 1) {
      y_out[0] = (2.0 + 5.0 * muDoubleScalarSin(6.2831853071795862 * *s)) *
        3.1415926535897931 / 180.0 * obj->stanceLeg;
      y_out[1] = q_st_h;
      y_out[2] = -(2.0 + 5.0 * muDoubleScalarSin(6.2831853071795862 * *s)) *
        3.1415926535897931 / 180.0 * obj->stanceLeg;
      y_out[3] = q_sw_h;
      y_out[4] = (2.0 + 5.0 * muDoubleScalarSin(6.2831853071795862 * *s)) *
        3.1415926535897931 / 180.0 * obj->stanceLeg - q_st_h;
      y_out[5] = -(2.0 + 5.0 * muDoubleScalarSin(6.2831853071795862 * *s)) *
        3.1415926535897931 / 180.0 * obj->stanceLeg - q_sw_h;
    } else if ((int32_T)obj->isTest2 == 1) {
      y_out[0] = 0.0;
      y_out[1] = q[10];
      y_out[2] = q_sw_h_tgt;
      y_out[3] = q_sw_h;
      y_out[4] = 0.0 - q[10];
      y_out[5] = q_sw_h_tgt - q_sw_h;
    } else {
      y_out[0] = 0.0;
      y_out[1] = q[10];
      y_out[2] = q_sw_h_tgt;
      y_out[3] = q_sw_h;
      y_out[4] = 0.0 - q[10];
      y_out[5] = *s * (q_sw_h_tgt - q_sw_h);
    }

    kp = obj->dx;
    dx = obj->dx_est;
    fz_st = obj->dy;
    fz_sw = obj->dy_est;
    dy_out[0] = kp / 180.0 * 3.1415926535897931;
    dy_out[1] = dx / 180.0 * 3.1415926535897931;
    dy_out[2] = fz_st / 180.0 * 3.1415926535897931;
    dy_out[3] = fz_sw / 180.0 * 3.1415926535897931;
    dy_out[4] = s_st / 180.0 * 3.1415926535897931;
    dy_out[5] = s_sw / 180.0 * 3.1415926535897931;
  } else {
    if ((int32_T)obj->isTest12 == 1) {
      y_out[0] = (160.0 + 15.0 * (real_T)(*s > 0.5) - 15.0 * (real_T)(*s <= 0.5))
        * 3.1415926535897931 / 180.0 - q_st_mA;
      y_out[1] = (200.0 + 15.0 * (real_T)(*s > 0.5) - 15.0 * (real_T)(*s <= 0.5))
        * 3.1415926535897931 / 180.0 - q_st_mB;
      y_out[2] = (160.0 + 15.0 * (real_T)(*s > 0.5) - 15.0 * (real_T)(*s <= 0.5))
        * 3.1415926535897931 / 180.0 - q_sw_mA;
      y_out[3] = (200.0 + 15.0 * (real_T)(*s > 0.5) - 15.0 * (real_T)(*s <= 0.5))
        * 3.1415926535897931 / 180.0 - q_sw_mB;
      y_out[4] = (160.0 + 15.0 * (real_T)(*s > 0.5) - 15.0 * (real_T)(*s <= 0.5))
        * 3.1415926535897931 / 180.0 / 10.0;
      y_out[5] = q_sw_mA / 10.0;
    } else {
      kp = obj->hd_q[2];
      y_out[0] = obj->hd_q[0] - q_st_mA;
      y_out[1] = obj->hd_q[1] - q_st_mB;
      y_out[2] = obj->hd_q[2] - q_sw_mA;
      y_out[3] = obj->hd_q[3] - q_sw_mB;
      y_out[4] = kp / 10.0;
      y_out[5] = q_sw_mA / 10.0;
    }

    dy_out[0] = -dq_st_mA / 10.0;
    dy_out[1] = -dq_st_mB / 10.0;
    dy_out[2] = -dq_sw_mA / 10.0;
    dy_out[3] = -dq_sw_mB / 10.0;
    dy_out[4] = s_st / 180.0 * 3.1415926535897931;
    dy_out[5] = s_sw / 180.0 * 3.1415926535897931;
  }

  if ((*s >= 0.7 && s_sw >= 1.0 && obj->switch_phase == 1.0) || (*s >= 1.0 &&
       obj->switch_phase == 0.0)) {
    obj->stanceLeg = -obj->stanceLeg;
  }
}

static void MikhailController_MARLO_Steeringv2_parsePS3Controller
  (MikhailController_MARLO_Steeringv2_2 *obj, real_T ControlParams[2])
{
  MikhailController_MARLO_Steeringv2_2 *b_obj;
  boolean_T flag;
  real_T dy_cmd;
  real_T dx_cmd;
  real_T b_x;

  /* MIKHAILCONTROLLER Mikhail's controller. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  PUBLIC PROPERTIES ===================================================== */
  /*  Step Duration (s) */
  /*  Step Duration Gain */
  /*  Stance Leg P Gain (N*m/rad) */
  /*  Stance Leg D Gain (N*m*s/rad) */
  /*  Swing Leg P Gain (N*m/rad) */
  /*  Swing Leg D Gain (N*m*s/rad) */
  /*  Hip P Gain (N*m/rad) */
  /*  Hip D Gain (N*m*s/rad) */
  /*  Left A Motor Torque Scaling Factor */
  /*  Left B Motor Torque Scaling Factor */
  /*  Right A Motor Torque Scaling Factor */
  /*  Right B Motor Torque Scaling Factor */
  /*  Lower Force Threshold (N) */
  /*  Upper Force Threshold (N) */
  /*  Velocity Filter Time Constant (s) */
  /*  X Velocity Feed-Forward Gain */
  /*  X Velocity Error P Gain */
  /*  X Velocity Error D Gain */
  /*  Y Velocity Feed-Forward Gain */
  /*  Y Velocity Error P Gain */
  /*  Y Velocity Error D Gain */
  /*  Hip Offset (m) */
  /*  Hip Offset Gain */
  /*  Nominal Leg Length (m) */
  /*      l0_leg@double = 0.9 */
  /*  Swing Leg Retraction (m) */
  /*      l_ret@double = 0.18 */
  /*  Leg Extension Gain (m) */
  /*      l_ext_gain@double = 0.009 */
  /*  Double support overlap */
  /*  Test impulse control */
  /*  Test cubic hip trajectory */
  /*  Test using last swing leg dx */
  /*  Test using ground speed matching */
  /*  Set hip to constant */
  /*  Set leg to constant */
  /*  Test hip tracking */
  /*  Test hip gravity compensation */
  /*  Test hold position mode */
  /*  Test swing hip placement */
  /*  Test Virtual Contraint */
  /*  Test VC tracking */
  /*  X Center of Mass Offset (m) */
  /*  MARLO walk in place */
  /*  Steering Offset (m) */
  /*  Turn right: Positive */
  /*  Heading (rad) */
  /*  Y Center of Mass Offset (m) */
  /*  Enable Yaw Control (m) */
  /*  Hip Gravity Compensation Torque (Nm) */
  /*  2DoF Kp rate */
  /*  2DoF Kd rate */
  /*  properties */
  /*  PROTECTED PROPERTIES ================================================== */
  /*  Current stance leg (1 == Left, -1 == Right) */
  /*  Gait mode */
  /*  Time since last step (s) */
  /*  Heading (rad) */
  /*      X Center of Mass Offset (m) */
  /*      x_offset@double = 0.003 */
  /*      Y Center of Mass Offset (m) */
  /*      y_offset@double = -0.014 */
  /*      Z Center of Mass Offset (m) */
  /*      % Z Center of Mass Offset (m) */
  /*      z_offset@double = 0.1179 */
  /*  Estimated X position (m) */
  /*  Estimated Y position (m) */
  /*  Estimated X velocity (m/s) */
  /*  Estimated Y velocity (m/s) */
  /*  Estimated average Y velocity of last step (m/s) */
  /*  Target X velocity (m/s) */
  /*  Target Y velocity (m/s) */
  /*  Estimated X velocity of last step (m/s) */
  /*  Estimated Y velocity of last step (m/s) */
  /*  Length of stance leg at switch (m) */
  /*      l_st_last@double = 0.92 */
  /*  Length rate of stance leg at switch (m/s) */
  /*  Length of swing leg at switch (m) */
  /*      l_sw_last@double = 0.92 */
  /*  Length rate of swing leg at switch (m/s) */
  /*  Stance toe X position of last step (m) */
  /*  Stance toe X velocity of last step (m/s) */
  /*  Swing toe X position of last step (m) */
  /*  Swing toe X velocity of last step (m/s) */
  /*  Swing toe Y position of last step (m) */
  /*  Swing toe Y velocity of last step (m/s) */
  /*  Storage for passing signals to output function */
  /*  phase variable */
  /*      s@double = 0; */
  /*  phase variable */
  /*  switch back to walk in place (s) */
  /*  velocity threshold (m/s) */
  /*  TODO */
  /*  Z impulse () */
  /*  properties */
  /*  CONSTANT PROPERTIES =================================================== */
  /*  Center of mass offset trim increment (m) */
  /*  Leg rotational spring constant (N*m/rad) */
  /*      ks_leg = 2950 */
  /*      ks_leg = 2690.8    % MARLO 8 mm spring */
  /*  MARLO 12 mm spring */
  /*  Torso mass (kg) */
  /*  Total mass (kg) */
  /*      m_total = 62.9 */
  /*  MARLO */
  /*  Leg mass (kg) */
  /*      m_leg@double = 20.35 */
  /*  Gravity */
  /*  Hip length */
  /*      l_h = 0.17 */
  /*  Leg motor coulomb friction */
  /*  Leg motor viscous friction */
  /*  properties */
  /*  PUBLIC METHODS ======================================================== */
  /* USERSETUP Initialize system object. */
  /*  Reset objects */
  /*        obj.gaitMode = GaitMode.Square; */
  /*  Reset parameters */
  /*  TODO */
  /*  userSetup */
  /* USEROUTPUT User output function. */
  /*        userOut = [... */
  /*          obj.output, ... */
  /*          obj.Jz/100, ... */
  /*          obj.Jz_tgt/100, ... */
  /* obj.x_est, obj.y_est, ... */
  /*          obj.dx_est, obj.dy_est, ... */
  /*          obj.dx_tgt, obj.dy_tgt]; */
  /*            userOut = [obj.dx_est]; */
  /*  userOutput */
  /* USERSTEP System output and state update equations. */
  /*  Update stance duration timer */
  /*  Parse PS3 controller data */
  /*  Relabel leg state variables in terms of stance and swing */
  /*  Left */
  /*  Right */
  /*  if */
  /*  Relabel torso state variables */
  /*  Store heading for use in hold position mode */
  /*  Hip lengths */
  /*  Compute hip to center of mass distances and velocities */
  /* obj.z_offset*cos(q_pitch)*cos(q_roll)*dq_pitch - obj.x_offset*sin(q_pitch)*dq_pitch + obj.y_offset*cos(q_pitch)*sin(q_roll)*dq_pitch + obj.y_offset*cos(q_roll)*sin(q_pitch)*dq_roll - obj.z_offset*sin(q_pitch)*sin(q_roll)*dq_roll; */
  /* -(obj.z_offset*cos(q_roll) + obj.y_offset*sin(q_roll))*dq_roll; */
  /*  Compute toe to center of mass distances and velocities */
  /*  Scaling factors representing a normalized vertical GRF */
  /*  Vertical ground impulse */
  /*  Compute smoothing factor based on confidence leg is on the ground */
  /*  Filter velocity estimate, ignoring bad (large) values */
  /*  Update CoM position estimates */
  /*  Step duration */
  /*        if obj.dx_est < obj.dx_thrs || obj.runTime >= obj.stop_time */
  /*  Define a time variant parameter normalized between 0 and 1 */
  /*  Phase Estimator */
  /*          if obj.dx_est ~=0 */
  /*              x_est_forward = t_step*obj.dx_est; */
  /*              obj.sDDA = obj.x_est/x_est_forward; */
  /* ControlParams.Output.ThetaLimits; */
  /*          else */
  /*              obj.sDDA = 0; */
  /*          end */
  /*        s = clamp(obj.tauPhase,0,1); */
  /*        s = obj.tauPhase; */
  /*        s = obj.sDDA; */
  /*        ds = dsDDA; */
  /*        ds = 1/t_step + alpha_L*(obj.sDDA - obj.tauPhase); */
  /*  Phase overlap (double to single support transition) */
  /*  Compute Stance Leg Target Positions ------------------------------- */
  /*  Stance leg extension policy for energy injection */
  /*  Clamp stance leg length to avoid mechanical limits */
  /*        l_ext = clamp(l_ext, 0, 1 - obj.l0_leg); */
  /*  Target stance leg length (cubic extension in second half of stance) */
  /*  TODO: Impulse control needs enable disable button. */
  /*  if */
  /*  Target stance leg angle and velocity (zero hip torque) */
  /*  Target stance leg actuator angles and velocities */
  /*  Compute Swing Leg Target Positions -------------------------------- */
  /*  Target swing leg length and velocity */
  /*  Target swing leg foot placement policy */
  /*  Steering Offset */
  /*        if obj.EnableYawControl == 1 */
  /*  %       obj.steering_offset = atans((obj.q_yaw_tgt-obj.q_yaw),5,0.0873) + atans((0-obj.dq_yaw),5,0.0873*5); */
  /*        obj.steering_offset = -atans((obj.q_yaw_tgt-obj.q_yaw),0.0175*2,0.0873*3); */
  /*        end */
  /*         */
  /*        if obj.stanceLeg == 1 */
  /*            obj.steering_offset = -obj.steering_offset; */
  /*        end */
  /*        x_sw_tgt = x_sw_tgt + obj.steering_offset; */
  /*  Smooth clamp target swing leg foot placement */
  /*  Target swing leg cartesian position and velocity */
  /*  TODO: set second velocity term to zero for robust mode */
  /*  Target swing leg angle and velocity */
  /*  Target swing leg actuator angles and velocities */
  /*  Target swing leg foot placement policy */
  /*  Smooth clamp target swing leg foot placement */
  /*  y_sw_tgt = atans(y_sw_tgt, 1, 0.5); */
  /*  Target swing leg cartesian position and velocity */
  /*  if */
  /*  Target swing hip angle and velocity */
  /*        q_sw_h_tgt = real(asin((y_sw + y_t)/L) - asin(l_sw_h/L) - q_roll); */
  /*        dq_sw_h_tgt = real((dy_sw + dy_t)/(L *sqrt(1 - (y_sw + y_t)^2/L^2)) - dq_roll); */
  /*  DDA mirror without roll angle */
  /*  Clamp swing hip angles to avoid mechanical limits */
  /*        q_sw_h_tgt = clamp(q_sw_h_tgt, -0.1*obj.stanceLeg, 0.35*obj.stanceLeg); */
  /*  for MARLO */
  /*  Compute Control Inputs -------------------------------------------- */
  /*  No drift feedback control */
  /*        leg_angle_st = (q_st_lA+q_st_lB)/2; */
  /*        leg_angle_sw = (q_sw_lA+q_sw_lB)/2; */
  /*        dleg_angle_st = (dq_st_lA+dq_st_lB)/2; */
  /*        dleg_angle_sw = (dq_sw_lA+dq_sw_lB)/2; */
  /*        rate_kp = 0.05; */
  /*        rate_kp = 0.0; */
  /*        rate_kd = 0.2; */
  /*  Impact Reduction Rate */
  /*        k_rate = atan(s*(1-s)*20)/(pi/2)*0.8+0.2; */
  /*        k_rate = 1; */
  /*  Scale stance leg gains based on force */
  /*        kp = kp*k_rate; */
  /*        kd = kd*k_rate; */
  /*  Stance leg actuator torques from PD controller */
  /*  Set leg to constant */
  /*  Scale swing leg gains based on force */
  /*        kp = kp*k_rate; */
  /*        kd = kd*k_rate; */
  /*  Swing leg actuator torques from PD controller */
  /*  Set leg to constant */
  /*  Torso stabilization PD controller scaled based on leg force */
  /*  Hip feed-forward torque for gravity compensation */
  /*            u_st_h = (1 - s_st)*obj.m_leg*obj.g*l_st_h; */
  /*            u_sw_h = (1 - s_sw)*obj.m_leg*obj.g*l_sw_h; */
  /*            u_st_h = max(s_st, s_sw)*obj.m_leg*obj.g*l_st_h; */
  /*            u_sw_h = max(s_st, s_sw)*obj.m_leg*obj.g*l_sw_h; */
  /*            u_st_h = 0; */
  /*            u_sw_h = 0; */
  /*            u_st_h = (1 - s_st)*0.8*26.7*obj.stanceLeg; */
  /*            u_sw_h = -(1 - s_sw)*0.8*26.7*obj.stanceLeg; */
  /*            u_st_h = max(s_st, s_sw)*0.8*26.7*obj.stanceLeg; */
  /*            u_sw_h = -max(s_st, s_sw)*0.8*26.7*obj.stanceLeg; */
  /*            u_st_h = 0; */
  /*            u_sw_h = 0; */
  /*  Swing leg hip PD controller */
  /*  TODO: remove s scaling when trajectory is re-enabled */
  /*  Torso stabilization PD controller scaled based on leg force */
  /*  Test hip tracking */
  /* Set hip to constant */
  /*  Test hip gravity compensation */
  /*  if */
  /*                      u_st_h = u_st_h + obj.kp_hip*(0 - q_st_h) + obj.kd_hip*(0 - dq_st_h);    % prevent for drift */
  /*  DDA controller     */
  /*             HAlphaDDA = [    3.5843    3.5464    3.3828    3.3335    3.3069    3.3084 */
  /*                              3.3084    3.3049    3.0812    3.8560    3.7471    3.5843 */
  /*                              0.4713    0.4888    0.5923    0.4034    0.4666    0.5100 */
  /*                              0.5100    0.5426    2.5512    0.7511    0.6256    0.4713]; */
  /*              if obj.switch_phase_last ~= obj.switch_phase */
  /*                   index_b = 3; */
  /*                   if obj.switch_phase_n_1 ~= obj.switch_phase */
  /*                      dy_minus = [dq_st_mA;dq_st_mB;dq_sw_mA;dq_sw_mB]; */
  /*                      y_minus = -kp.\(obj.u_last+kd/2.*dy_minus); */
  /*                      h0 = [q_st_mA;q_st_mB;q_sw_mA;q_sw_mB]; */
  /*                      b = bezierterm(HAlphaDDA,s); */
  /*                      % -- update b3 only -- */
  /*                      index_left = setdiff(1:size(HAlphaDDA,2),index_b); */
  /*                      halpha_left = HAlphaDDA(:,index_left); */
  /*                      b_4 = b(index_b); */
  /*                      b_left = b(index_left); */
  /*                      hd_left = halpha_left*b_left; */
  /*                      equ_left = y_minus-h0+hd_left; */
  /*                      A = -b_4; */
  /*                      obj.halpha_4_plus = equ_left/A;    */
  /*                   end */
  /*                   HAlphaDDA(:,index_b) = obj.halpha_4_plus; */
  /*              end */
  /*                u_st_A = kp*obj.kp_rate*((160+gainA*2*sin(2*pi*s))*pi/180-q_st_mA) + kd*obj.kd_rate*(-dq_st_mA); */
  /*                u_st_B = kp*obj.kp_rate*((200+gainA*2*sin(2*pi*s))*pi/180-q_st_mB) + kd*obj.kd_rate*(-dq_st_mB); */
  /*                u_sw_A = kp*obj.kp_rate*((160+gainA*2*sin(2*pi*s))*pi/180-q_sw_mA) + kd*obj.kd_rate*(-dq_sw_mA); */
  /*                u_sw_B = kp*obj.kp_rate*((200+gainA*2*sin(2*pi*s))*pi/180-q_sw_mB) + kd*obj.kd_rate*(-dq_sw_mB);      */
  /*  Detect when time or force thresholds have been reached */
  /*        if s >= 1 */
  /*  Store exit conditions */
  /*  TODO: for running */
  /*  obj.dx_sw_last = sin(q_pitch + q_st)*dl_st - dx_t + cos(q_pitch + q_st)*l_st*(dq_pitch + dq_st); */
  /*  TODO: for robust standing */
  /*  obj.dy_sw_last = -obj.dy_est; */
  /*  obj.dy_sw_last = L*cos(asin(l_st_h/L) + q_roll + q_st_h)*(dq_roll + dq_st_h); */
  /*  TODO */
  /*  Reset time since last switch */
  /*  if */
  /*  Compute actual leg states */
  /*  Store signals in object for logging */
  /*  Control Switch */
  /*          if (((obj.dx_est < obj.dx_thrs && (obj.switch_phase == 0 || obj.dx_est<-0.1)) || ((s <=0.2 || s >=0.25) && obj.switch_phase == 0) || (obj.runTime >= obj.stop_time1)) && (obj.runTime <= 13))||... */
  /*              ((obj.runTime>13) && ((obj.dx_est > -obj.dx_thrs && (obj.switch_phase == 0 || obj.dx_est>0.1)) || ((obj.sDDA <=0.2 || obj.sDDA >=0.25) && obj.switch_phase == 0) || (obj.runTime >= obj.stop_time2))) */
  /*  Set commanded torque vector */
  /*  Left */
  /*  Right */
  /*  if */
  /*              obj.switch_phase = 0; */
  /*          else */
  /*              u = DDAcontroller(obj,q,dq,1); */
  /*              if obj.stanceLeg == 1 % Left */
  /*                  u = [obj.s_r_B*u_sw_B, obj.s_r_A*u_sw_A, u_sw_h, ... */
  /*                      obj.s_l_B*u_st_B, obj.s_l_A*u_st_A, u_st_h]; */
  /*              else % Right */
  /*                  u = [obj.s_l_B*u_st_B, obj.s_l_A*u_st_A, u_st_h, ... */
  /*                      obj.s_r_B*u_sw_B, obj.s_r_A*u_sw_A, u_sw_h]; */
  /*              end % if */
  /*              obj.switch_phase = 1; */
  /*          end */
  /*      %  == Swap Controller == */
  /*      if obj.dx_est>0 % forward walk */
  /*          if ((obj.dx_est < obj.dx_thrs || (s <0.4 || s> 0.5) || ControlState(2) == 1) && obj.switch_phase == 0) || (obj.dx_est<0.15 && (s_DDA >0.2 && s_DDA< 0.6))% use osu controller, only swap in right st leg   */
  /*              obj.switch_phase = 0; */
  /*          else                                                    % use DDA controller */
  /*              if ((obj.dx_est < obj.dx_thrs+0.05 || (s_DDA <0.4 || s_DDA> 0.5)) && obj.switch_phase ~= 2) */
  /*                  ControlSwitch = 1; */
  /*                  obj.switch_phase = 1; */
  /*              else  */
  /*                  ControlSwitch = 1; */
  /*                  obj.switch_phase = 1; */
  /*              end */
  /*          end */
  /*      else           % backward walk */
  /*          if ((obj.dx_est > -obj.dx_thrs || (s <0.4 || s> 0.5) || ControlState(2) == 0) && obj.switch_phase == 0) || (obj.dx_est>-0.15 && (s_DDA >0.2 && s_DDA< 0.6))% use osu controller, only swap on left st leg   */
  /*              ControlSwitch = 0; */
  /*              obj.switch_phase = 0; */
  /*          else                                                    % use DDA controller */
  /*              if ((obj.dx_est > -obj.dx_thrs-0.05 || (s_DDA <0.4 || s_DDA> 0.5)) && obj.switch_phase ~= 2) */
  /*                  ControlSwitch = 1; */
  /*                  obj.switch_phase = 1; */
  /*              else  */
  /*                  ControlSwitch = 1; */
  /*                  obj.switch_phase = 1; */
  /*              end */
  /*          end */
  /*           */
  /*      end */
  /*  Test hip tracking */
  /*      dy_out = [(q_st_mA_tgt - q_st_mA) + s_st*(q_pitch - 0);... */
  /*                (q_st_mB_tgt - q_st_mB) + s_st*(q_pitch - 0);... */
  /*                (q_sw_mA_tgt - q_sw_mA) + s_sw*(q_pitch - 0);... */
  /*                (q_sw_mB_tgt - q_sw_mB) + s_sw*(q_pitch - 0);... */
  /*              s_st/180*pi;... */
  /*              s_sw/180*pi]; % ;(dq_pitch - 0) */
  /*              y_out = [(160+gainA*2*sin(2*pi*s))*pi/180-q_st_mA;... */
  /*                   (200+gainA*2*sin(2*pi*s))*pi/180-q_st_mB;... */
  /*                   (160+gainA*2*sin(2*pi*s))*pi/180-q_sw_mA;... */
  /*                   (200+gainA*2*sin(2*pi*s))*pi/180-q_sw_mB;... */
  /*                   (160+gainA*2*sin(2*pi*s))*pi/180/10;... */
  /*                       q_sw_mA/10]; */
  /*  ;(dq_pitch - 0) */
  /*      if s >= 1 */
  /*  userStep */
  /* PARSEPS3CONTROLLER */
  /*  Parse D-Pad for velocity trimming */
  if (obj->ps3.up.isPressed) {
    /*  Trim forward */
    b_obj = obj;
    if (b_obj->isInitialized && !b_obj->isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      b_obj->TunablePropsChanged = true;
    }

    obj->x_offset -= 0.001;
  } else if (obj->ps3.right.isPressed) {
    /*  Trim right */
    b_obj = obj;
    if (b_obj->isInitialized && !b_obj->isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      b_obj->TunablePropsChanged = true;
    }

    obj->y_offset += 0.001;
  } else if (obj->ps3.down.isPressed) {
    /*  Trim backward */
    b_obj = obj;
    if (b_obj->isInitialized && !b_obj->isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      b_obj->TunablePropsChanged = true;
    }

    obj->x_offset += 0.001;
  } else {
    if (obj->ps3.left.isPressed) {
      /*  Trim left */
      b_obj = obj;
      if (b_obj->isInitialized && !b_obj->isReleased) {
        flag = true;
      } else {
        flag = false;
      }

      if (flag) {
        b_obj->TunablePropsChanged = true;
      }

      obj->y_offset -= 0.001;
    }
  }

  /*  if */
  /*  Parse gait modes */
  if (obj->ps3.cross.isPressed) {
    obj->gaitMode = Cross;
  } else if (obj->ps3.circle.isPressed) {
    obj->gaitMode = Circle;
  } else if (obj->ps3.triangle.isPressed) {
    obj->gaitMode = Triangle;
  } else {
    if (obj->ps3.square.isPressed) {
      obj->gaitMode = Square;
    }
  }

  /*  if */
  /*  Parse select button for reset home */
  if (obj->ps3._select.isPressed) {
    obj->x_est = 0.0;
    obj->y_est = 0.0;
  }

  /*  if */
  /*  Parse left joystick data for X Velocity */
  dy_cmd = obj->ps3.leftStickY;

  /* CLAMP Clamp value between two bounds. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  Find which limit is min and max */
  /*  Clamp value between limits */
  dx_cmd = muDoubleScalarMax(muDoubleScalarMin(dy_cmd, 1.0), -1.0);

  /*  clamp */
  /*  Parse right joystick data for Y Velocity */
  dy_cmd = obj->ps3.rightStickX;

  /* CLAMP Clamp value between two bounds. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  Find which limit is min and max */
  /*  Clamp value between limits */
  dy_cmd = muDoubleScalarMax(muDoubleScalarMin(dy_cmd, 1.0), -1.0);

  /*  clamp */
  /*  Set gait mode specific tweaks */
  if ((int32_T)obj->isTest9 == 1) {
    switch (obj->gaitMode) {
     case Cross:
      /*  Hold position mode */
      b_x = obj->q_yaw;
      dy_cmd = obj->q_yaw;
      dy_cmd = -4.0 * (muDoubleScalarCos(b_x) * obj->x_est + muDoubleScalarSin
                       (dy_cmd) * obj->y_est);

      /* CLAMP Clamp value between two bounds. */
      /*  */
      /*  Copyright 2015 Mikhail S. Jones */
      /*  Find which limit is min and max */
      /*  Clamp value between limits */
      dx_cmd = muDoubleScalarMax(muDoubleScalarMin(dy_cmd, 0.6), -0.6);

      /*  clamp */
      b_x = obj->q_yaw;
      dy_cmd = obj->q_yaw;
      dy_cmd = -(muDoubleScalarCos(b_x) * obj->y_est - muDoubleScalarSin(dy_cmd)
                 * obj->x_est);

      /* CLAMP Clamp value between two bounds. */
      /*  */
      /*  Copyright 2015 Mikhail S. Jones */
      /*  Find which limit is min and max */
      /*  Clamp value between limits */
      dy_cmd = muDoubleScalarMax(muDoubleScalarMin(dy_cmd, 0.4), -0.4);

      /*  clamp */
      break;

     case Circle:
      /*  Robust stand/walk mode */
      dx_cmd *= 0.75;
      dy_cmd *= 0.2;
      break;

     case Triangle:
      /*  Fast walk/run mode */
      dx_cmd *= 1.5;
      dy_cmd *= 0.2;
      break;

     default:
      /*  GaitMode.Square */
      /*  Hop mode (TODO) */
      dx_cmd *= 0.2;
      dy_cmd *= 0.2;
      break;
    }

    /*  switch */
    /*        % Simulation overrides */
  } else {
    /*          obj.gaitMode = GaitMode.Triangle; */
    /*          obj.gaitMode = GaitMode.Cross; */
    /*          dx_cmd = 0; */
    /*          % dy_cmd = 0.2*((obj.runTime >= 15) - 2*(obj.runTime >= 30)); */
    /*          % dx_cmd = 1.5*round(sin(obj.runTime*2*pi/15)); */
    /*          % dx_cmd = clamp(0.25*floor(obj.runTime/5), 0, 3); */
    /*          % dx_cmd = 3*(obj.runTime >= 5 && obj.runTime <= 10); */
    dx_cmd = ControlParams[0];
    dy_cmd = ControlParams[1];
  }

  /*  Parse right lower trigger for turbo mode */
  if (obj->ps3.r2.value) {
    dx_cmd *= 2.0;
  }

  /*  if */
  /*  Parse left lower trigger for auto speed regulation mode */
  if (obj->ps3.l2.value) {
    b_x = obj->dy_est_avg;
    if (muDoubleScalarAbs(b_x) >= 0.05) {
      dx_cmd /= 2.0;
    }

    /*  if */
  }

  /*  if */
  /*  Filter target X velocity command */
  obj->dx_tgt += 0.00024993751562109469 * (dx_cmd - obj->dx_tgt);

  /*  Filter target Y velocity command */
  obj->dy_tgt += 0.00099900099900099922 * (dy_cmd - obj->dy_tgt);
}

static real_T clamp(real_T a, real_T lim1, real_T lim2)
{
  real_T b;

  /* CLAMP Clamp value between two bounds. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  Find which limit is min and max */
  /*  Clamp value between limits */
  b = muDoubleScalarMax(muDoubleScalarMin(a, muDoubleScalarMax(lim1, lim2)),
                        muDoubleScalarMin(lim1, lim2));

  /*  clamp */
  return b;
}

static real_T scaleFactor(real_T f, real_T tl, real_T tu)
{
  /*  parsePS3Controller */
  /*  methods */
  /*  classdef */
  /* % LOCAL FUNCTIONS ======================================================== */
  /* SCALEFACTOR Compute scalar (0 to 1) representing forces in leg. */
  /* CLAMP Clamp value between two bounds. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  Find which limit is min and max */
  /*  Clamp value between limits */
  /*  clamp */
  return (muDoubleScalarMax(muDoubleScalarMin(f, muDoubleScalarMax(tl, tu)),
           muDoubleScalarMin(tl, tu)) - tl) / (tu - tl);
}

static real_T cubic_interp(real_T x0[2], real_T c_y0[2], real_T dy0[2], real_T
  b_x, real_T dx)
{
  real_T y;
  real_T a3;
  real_T s;
  (void)x0;
  (void)dy0;
  (void)dx;

  /* CUBIC_INTERP Cubic interpolation between values. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  Check size of reference trajectory */
  /*  if */
  /*  Check size of interpolation point */
  /*  if */
  /*  Limit range since curve fit is only valid within range */
  /* CLAMP Clamp value between two bounds. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  Find which limit is min and max */
  /*  Clamp value between limits */
  b_x = muDoubleScalarMax(muDoubleScalarMin(b_x, 2.0), 0.0);

  /*  clamp */
  /*  Initialize ouputs */
  y = c_y0[0];

  /*  Loop through intervals */
  /*  Find interval covering current point */
  if (b_x >= 0.0) {
    /*  Interpolate */
    a3 = 2.0 * c_y0[0];
    s = b_x / 2.0;
    y = c_y0[0] + (0.0 - c_y0[0] - a3) * (s * s) + a3 * muDoubleScalarPower(s,
      3.0);
  }

  /*  if */
  /*  for */
  /*  cubic_interp */
  return y;
}

static void b_cubic_interp(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance,
  real_T x0[4], real_T c_y0[4], real_T dy0[4], real_T b_x, real_T dx, real_T *y,
  real_T *dy)
{
  int32_T i;
  real_T a3;
  real_T a2;
  real_T a1;
  real_T s;
  real_T a;

  /* CUBIC_INTERP Cubic interpolation between values. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  Check size of reference trajectory */
  /*  if */
  /*  Check size of interpolation point */
  /*  if */
  /*  Limit range since curve fit is only valid within range */
  /* CLAMP Clamp value between two bounds. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  Find which limit is min and max */
  /*  Clamp value between limits */
  b_x = muDoubleScalarMax(muDoubleScalarMin(b_x, 1.0), 0.0);

  /*  clamp */
  /*  Initialize ouputs */
  *y = c_y0[0];
  *dy = 0.0;

  /*  Loop through intervals */
  for (i = 0; i < 3; i++) {
    /*  Find interval covering current point */
    if (b_x >= x0[i] && b_x <= x0[1 + i]) {
      /*  Interpolate */
      a3 = 2.0 * (c_y0[i] - c_y0[1 + i]) + dy0[i] * (x0[1 + i] - x0[i]);
      a2 = c_y0[1 + i] - c_y0[i] - dy0[i] * (x0[1 + i] - x0[i]) - a3;
      a1 = dy0[i] * (x0[1 + i] - x0[i]);
      s = (b_x - x0[i]) / (x0[1 + i] - x0[i]);
      *y = c_y0[i] + a1 * s + a2 * (s * s) + a3 * muDoubleScalarPower(s, 3.0);
      s = x0[i] - x0[1 + i];
      a = b_x - x0[i];
      *dy = dx * (-a1 / (x0[i] - x0[1 + i]) + 2.0 * a2 * (b_x - x0[i]) / (s * s)
                  - 3.0 * a3 * (a * a) / muDoubleScalarPower(x0[i] - x0[1 + i],
        3.0));
    }

    /*  if */
    cgxe_listen_for_ctrl_c(moduleInstance->S, emlrtRootTLSGlobal);
  }

  /*  for */
  /*  cubic_interp */
}

static real_T mean(real_T b_x[2])
{
  return (b_x[0] + b_x[1]) / 2.0;
}

static void c_cubic_interp(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance,
  real_T x0[3], real_T c_y0[3], real_T dy0[3], real_T b_x, real_T dx, real_T *y,
  real_T *dy)
{
  int32_T i;
  real_T a3;
  real_T a2;
  real_T a1;
  real_T s;
  real_T a;

  /* CUBIC_INTERP Cubic interpolation between values. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  Check size of reference trajectory */
  /*  if */
  /*  Check size of interpolation point */
  /*  if */
  /*  Limit range since curve fit is only valid within range */
  /* CLAMP Clamp value between two bounds. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  Find which limit is min and max */
  /*  Clamp value between limits */
  b_x = muDoubleScalarMax(muDoubleScalarMin(b_x, muDoubleScalarMax(0.0, x0[2])),
    muDoubleScalarMin(0.0, x0[2]));

  /*  clamp */
  /*  Initialize ouputs */
  *y = c_y0[0];
  *dy = 0.0;

  /*  Loop through intervals */
  for (i = 0; i < 2; i++) {
    /*  Find interval covering current point */
    if (b_x >= x0[i] && b_x <= x0[1 + i]) {
      /*  Interpolate */
      a3 = 2.0 * (c_y0[i] - c_y0[1 + i]) + dy0[i] * (x0[1 + i] - x0[i]);
      a2 = c_y0[1 + i] - c_y0[i] - dy0[i] * (x0[1 + i] - x0[i]) - a3;
      a1 = dy0[i] * (x0[1 + i] - x0[i]);
      s = (b_x - x0[i]) / (x0[1 + i] - x0[i]);
      *y = c_y0[i] + a1 * s + a2 * (s * s) + a3 * muDoubleScalarPower(s, 3.0);
      s = x0[i] - x0[1 + i];
      a = b_x - x0[i];
      *dy = dx * (-a1 / (x0[i] - x0[1 + i]) + 2.0 * a2 * (b_x - x0[i]) / (s * s)
                  - 3.0 * a3 * (a * a) / muDoubleScalarPower(x0[i] - x0[1 + i],
        3.0));
    }

    /*  if */
    cgxe_listen_for_ctrl_c(moduleInstance->S, emlrtRootTLSGlobal);
  }

  /*  for */
  /*  cubic_interp */
}

static real_T atans(real_T b_x, real_T slope, real_T y_lim)
{
  (void)slope;
  (void)y_lim;

  /*  scaleFactor */
  /* ATANS Arctangent smooth clamp function */
  /*   */
  /*  Rescale Y limit for arctangent function */
  /*  Arctangent scaled to have desired slope at 0 and desired clamp at Inf */
  return 0.63661977236758138 * muDoubleScalarAtan(b_x / 0.63661977236758138);
}

static void d_cubic_interp(real_T x0[2], real_T c_y0[2], real_T dy0[2], real_T
  b_x, real_T dx, real_T *y, real_T *dy)
{
  real_T a3;
  real_T a2;
  real_T a1;
  real_T s;
  (void)x0;

  /* CUBIC_INTERP Cubic interpolation between values. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  Check size of reference trajectory */
  /*  if */
  /*  Check size of interpolation point */
  /*  if */
  /*  Limit range since curve fit is only valid within range */
  /* CLAMP Clamp value between two bounds. */
  /*  */
  /*  Copyright 2015 Mikhail S. Jones */
  /*  Find which limit is min and max */
  /*  Clamp value between limits */
  b_x = muDoubleScalarMax(muDoubleScalarMin(b_x, 0.8), 0.0);

  /*  clamp */
  /*  Initialize ouputs */
  *y = c_y0[0];
  *dy = 0.0;

  /*  Loop through intervals */
  /*  Find interval covering current point */
  if (b_x >= 0.0) {
    /*  Interpolate */
    a3 = 2.0 * (c_y0[0] - c_y0[1]) + (dy0[0] + dy0[1]) * 0.8;
    a2 = c_y0[1] - c_y0[0] - dy0[0] * 0.8 - a3;
    a1 = dy0[0] * 0.8;
    s = b_x / 0.8;
    *y = c_y0[0] + a1 * s + a2 * (s * s) + a3 * muDoubleScalarPower(s, 3.0);
    *dy = dx * (-a1 / -0.8 + 2.0 * a2 * b_x / 0.64000000000000012 - 3.0 * a3 *
                (b_x * b_x) / -0.51200000000000012);
  }

  /*  if */
  /*  for */
  /*  cubic_interp */
}

static void eml_error(void)
{
  const mxArray *y;
  static const int32_T iv5[2] = { 1, 30 };

  const mxArray *m2;
  char_T cv8[30];
  int32_T i3;
  static char_T cv9[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *b_y;
  static const int32_T iv6[2] = { 1, 4 };

  char_T cv10[4];
  static char_T cv11[4] = { 'a', 's', 'i', 'n' };

  y = NULL;
  m2 = emlrtCreateCharArray(2, iv5);
  for (i3 = 0; i3 < 30; i3++) {
    cv8[i3] = cv9[i3];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 30, m2, cv8);
  emlrtAssign(&y, m2);
  b_y = NULL;
  m2 = emlrtCreateCharArray(2, iv6);
  for (i3 = 0; i3 < 4; i3++) {
    cv10[i3] = cv11[i3];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 4, m2, cv10);
  emlrtAssign(&b_y, m2);
  error(message(y, b_y, &b_emlrtMCI), &b_emlrtMCI);
}

static void b_eml_error(void)
{
  const mxArray *y;
  static const int32_T iv7[2] = { 1, 30 };

  const mxArray *m3;
  char_T cv12[30];
  int32_T i4;
  static char_T cv13[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  const mxArray *b_y;
  static const int32_T iv8[2] = { 1, 4 };

  char_T cv14[4];
  static char_T cv15[4] = { 's', 'q', 'r', 't' };

  y = NULL;
  m3 = emlrtCreateCharArray(2, iv7);
  for (i4 = 0; i4 < 30; i4++) {
    cv12[i4] = cv13[i4];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 30, m3, cv12);
  emlrtAssign(&y, m3);
  b_y = NULL;
  m3 = emlrtCreateCharArray(2, iv8);
  for (i4 = 0; i4 < 4; i4++) {
    cv14[i4] = cv15[i4];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 4, m3, cv14);
  emlrtAssign(&b_y, m3);
  error(message(y, b_y, &b_emlrtMCI), &b_emlrtMCI);
}

static void bezierval(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance,
                      real_T alpha[24], real_T s, real_T y[4])
{
  int32_T k;
  int32_T b_k;
  real_T b_y;
  int32_T j;
  real_T b;
  for (k = 0; k < 4; k++) {
    y[k] = 0.0;
  }

  for (b_k = 0; b_k < 6; b_k++) {
    k = b_k;
    if ((real_T)b_k > 2.5) {
      k = 5 - b_k;
    }

    b_y = 1.0;
    for (j = 0; j < k; j++) {
      b_y *= ((real_T)(j - k) + 6.0) / (1.0 + (real_T)j);
    }

    b_y = muDoubleScalarRound(b_y);
    if (!(b_y <= 9.007199254740992E+15)) {
      eml_warning();
    }

    b = muDoubleScalarPower(s, (real_T)b_k) * muDoubleScalarPower(1.0 - s, 5.0 -
      (real_T)b_k);
    for (k = 0; k < 4; k++) {
      y[k] += alpha[k + (b_k << 2)] * b_y * b;
    }

    cgxe_listen_for_ctrl_c(moduleInstance->S, emlrtRootTLSGlobal);
  }
}

static void eml_warning(void)
{
  const mxArray *y;
  static const int32_T iv9[2] = { 1, 38 };

  const mxArray *m4;
  char_T cv16[38];
  int32_T i5;
  static char_T cv17[38] = { 'C', 'o', 'd', 'e', 'r', ':', 'M', 'A', 'T', 'L',
    'A', 'B', ':', 'n', 'c', 'h', 'o', 'o', 's', 'e', 'k', '_', 'L', 'a', 'r',
    'g', 'e', 'C', 'o', 'e', 'f', 'f', 'i', 'c', 'i', 'e', 'n', 't' };

  y = NULL;
  m4 = emlrtCreateCharArray(2, iv9);
  for (i5 = 0; i5 < 38; i5++) {
    cv16[i5] = cv17[i5];
  }

  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 38, m4, cv16);
  emlrtAssign(&y, m4);
  warning(b_message(y, &g_emlrtMCI), &h_emlrtMCI);
}

static void cgxe_mdl_start(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance)
{
  boolean_T flag;
  int32_T i6;
  real_T *t0_step;
  real_T *t_gain;
  real_T *kp_st_leg;
  real_T *kd_st_leg;
  real_T *kp_sw_leg;
  real_T *kd_sw_leg;
  real_T *kp_hip;
  real_T *kd_hip;
  real_T *s_l_A;
  real_T *s_l_B;
  real_T *s_r_A;
  real_T *s_r_B;
  real_T *thres_lo;
  real_T *thres_hi;
  real_T *tau;
  real_T *dx_gain;
  real_T *dx_err_p_gain;
  real_T *dx_err_d_gain;
  real_T *dy_gain;
  real_T *dy_err_p_gain;
  real_T *dy_err_d_gain;
  real_T *y0_offset;
  real_T *y0_gain;
  real_T *l0_leg;
  real_T *l_ret;
  real_T *l_ext_gain;
  real_T *s_overlap;
  boolean_T *isTest1;
  boolean_T *isTest2;
  boolean_T *isTest3;
  boolean_T *isTest4;
  boolean_T *isTest5;
  boolean_T *isTest6;
  boolean_T *isTest7;
  boolean_T *isTest8;
  boolean_T *isTest9;
  boolean_T *isTest10;
  boolean_T *isTest11;
  boolean_T *isTest12;
  real_T *x_offset;
  real_T *steering_offset;
  real_T *q_yaw_tgt;
  real_T *y_offset;
  real_T *EnableYawControl;
  real_T *uHipGravity;
  real_T *kp_rate;
  real_T *kd_rate;
  boolean_T *isSim;
  real_T *u_lim;
  real_T (*ps3Buttons)[17];
  real_T (*ps3Axes)[4];
  u_lim = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 50U))->data;
  ps3Buttons = (real_T (*)[17])(ssGetRunTimeParamInfo(moduleInstance->S, 49U))
    ->data;
  ps3Axes = (real_T (*)[4])(ssGetRunTimeParamInfo(moduleInstance->S, 48U))->data;
  isSim = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 47U))->data;
  kd_rate = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 46U))->data;
  kp_rate = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 45U))->data;
  uHipGravity = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 44U))->data;
  EnableYawControl = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 43U))
    ->data;
  y_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 42U))->data;
  q_yaw_tgt = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 41U))->data;
  steering_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 40U))
    ->data;
  x_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 39U))->data;
  isTest12 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 38U))->data;
  isTest11 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 37U))->data;
  isTest10 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 36U))->data;
  isTest9 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 35U))->data;
  isTest8 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 34U))->data;
  isTest7 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 33U))->data;
  isTest6 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 32U))->data;
  isTest5 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 31U))->data;
  isTest4 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 30U))->data;
  isTest3 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 29U))->data;
  isTest2 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 28U))->data;
  isTest1 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 27U))->data;
  s_overlap = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 26U))->data;
  l_ext_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 25U))->data;
  l_ret = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 24U))->data;
  l0_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 23U))->data;
  y0_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 22U))->data;
  y0_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 21U))->data;
  dy_err_d_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 20U))
    ->data;
  dy_err_p_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 19U))
    ->data;
  dy_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 18U))->data;
  dx_err_d_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 17U))
    ->data;
  dx_err_p_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 16U))
    ->data;
  dx_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 15U))->data;
  tau = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 14U))->data;
  thres_hi = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 13U))->data;
  thres_lo = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 12U))->data;
  s_r_B = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 11U))->data;
  s_r_A = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 10U))->data;
  s_l_B = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 9U))->data;
  s_l_A = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 8U))->data;
  kd_hip = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 7U))->data;
  kp_hip = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 6U))->data;
  kd_sw_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 5U))->data;
  kp_sw_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 4U))->data;
  kd_st_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 3U))->data;
  kp_st_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 2U))->data;
  t_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 1U))->data;
  t0_step = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 0U))->data;
  if (!moduleInstance->sysobj_not_empty) {
    moduleInstance->sysobj.stanceLeg = -1.0;
    moduleInstance->sysobj.q_yaw = 0.0;
    moduleInstance->sysobj.z_offset = 0.2087;
    moduleInstance->sysobj.runTime = 0.0;
    moduleInstance->sysobj.isInitialized = false;
    moduleInstance->sysobj.isReleased = false;
    moduleInstance->sysobj_not_empty = true;
    SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    b_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.t0_step = *t0_step;
    c_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.t_gain = *t_gain;
    d_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_st_leg = *kp_st_leg;
    e_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_st_leg = *kd_st_leg;
    f_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_sw_leg = *kp_sw_leg;
    g_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_sw_leg = *kd_sw_leg;
    h_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_hip = *kp_hip;
    i_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_hip = *kd_hip;
    j_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_l_A = *s_l_A;
    k_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_l_B = *s_l_B;
    l_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_r_A = *s_r_A;
    m_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_r_B = *s_r_B;
    n_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.thres_lo = *thres_lo;
    o_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.thres_hi = *thres_hi;
    p_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.tau = *tau;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dx_gain = *dx_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dx_err_p_gain = *dx_err_p_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dx_err_d_gain = *dx_err_d_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dy_gain = *dy_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dy_err_p_gain = *dy_err_p_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dy_err_d_gain = *dy_err_d_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.y0_offset = *y0_offset;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.y0_gain = *y0_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.l0_leg = *l0_leg;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.l_ret = *l_ret;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.l_ext_gain = *l_ext_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.s_overlap = *s_overlap;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest1 = *isTest1;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest2 = *isTest2;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest3 = *isTest3;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest4 = *isTest4;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest5 = *isTest5;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest6 = *isTest6;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest7 = *isTest7;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest8 = *isTest8;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest9 = *isTest9;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest10 = *isTest10;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest11 = *isTest11;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest12 = *isTest12;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.x_offset = *x_offset;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.steering_offset = *steering_offset;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.q_yaw_tgt = *q_yaw_tgt;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.y_offset = *y_offset;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.EnableYawControl = *EnableYawControl;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.uHipGravity = *uHipGravity;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.kp_rate = *kp_rate;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.kd_rate = *kd_rate;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isSim = *isSim;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i6 = 0; i6 < 4; i6++) {
      moduleInstance->sysobj.ps3Axes[i6] = (*ps3Axes)[i6];
    }

    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i6 = 0; i6 < 17; i6++) {
      moduleInstance->sysobj.ps3Buttons[i6] = (*ps3Buttons)[i6];
    }

    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.u_lim = *u_lim;
  }

  SystemCore_setup(&moduleInstance->sysobj);
}

static void cgxe_mdl_initialize(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance)
{
  boolean_T flag;
  int32_T i7;
  MikhailController_MARLO_Steeringv2_2 *obj;
  const mxArray *y;
  static const int32_T iv10[2] = { 1, 45 };

  const mxArray *m5;
  char_T cv18[45];
  static char_T cv19[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv11[2] = { 1, 8 };

  char_T cv20[8];
  static char_T cv21[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  const mxArray *c_y;
  static const int32_T iv12[2] = { 1, 45 };

  const mxArray *d_y;
  static const int32_T iv13[2] = { 1, 5 };

  char_T cv22[5];
  static char_T cv23[5] = { 'r', 'e', 's', 'e', 't' };

  real_T *t0_step;
  real_T *t_gain;
  real_T *kp_st_leg;
  real_T *kd_st_leg;
  real_T *kp_sw_leg;
  real_T *kd_sw_leg;
  real_T *kp_hip;
  real_T *kd_hip;
  real_T *s_l_A;
  real_T *s_l_B;
  real_T *s_r_A;
  real_T *s_r_B;
  real_T *thres_lo;
  real_T *thres_hi;
  real_T *tau;
  real_T *dx_gain;
  real_T *dx_err_p_gain;
  real_T *dx_err_d_gain;
  real_T *dy_gain;
  real_T *dy_err_p_gain;
  real_T *dy_err_d_gain;
  real_T *y0_offset;
  real_T *y0_gain;
  real_T *l0_leg;
  real_T *l_ret;
  real_T *l_ext_gain;
  real_T *s_overlap;
  boolean_T *isTest1;
  boolean_T *isTest2;
  boolean_T *isTest3;
  boolean_T *isTest4;
  boolean_T *isTest5;
  boolean_T *isTest6;
  boolean_T *isTest7;
  boolean_T *isTest8;
  boolean_T *isTest9;
  boolean_T *isTest10;
  boolean_T *isTest11;
  boolean_T *isTest12;
  real_T *x_offset;
  real_T *steering_offset;
  real_T *q_yaw_tgt;
  real_T *y_offset;
  real_T *EnableYawControl;
  real_T *uHipGravity;
  real_T *kp_rate;
  real_T *kd_rate;
  boolean_T *isSim;
  real_T *u_lim;
  real_T (*ps3Buttons)[17];
  real_T (*ps3Axes)[4];
  u_lim = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 50U))->data;
  ps3Buttons = (real_T (*)[17])(ssGetRunTimeParamInfo(moduleInstance->S, 49U))
    ->data;
  ps3Axes = (real_T (*)[4])(ssGetRunTimeParamInfo(moduleInstance->S, 48U))->data;
  isSim = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 47U))->data;
  kd_rate = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 46U))->data;
  kp_rate = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 45U))->data;
  uHipGravity = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 44U))->data;
  EnableYawControl = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 43U))
    ->data;
  y_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 42U))->data;
  q_yaw_tgt = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 41U))->data;
  steering_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 40U))
    ->data;
  x_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 39U))->data;
  isTest12 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 38U))->data;
  isTest11 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 37U))->data;
  isTest10 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 36U))->data;
  isTest9 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 35U))->data;
  isTest8 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 34U))->data;
  isTest7 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 33U))->data;
  isTest6 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 32U))->data;
  isTest5 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 31U))->data;
  isTest4 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 30U))->data;
  isTest3 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 29U))->data;
  isTest2 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 28U))->data;
  isTest1 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 27U))->data;
  s_overlap = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 26U))->data;
  l_ext_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 25U))->data;
  l_ret = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 24U))->data;
  l0_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 23U))->data;
  y0_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 22U))->data;
  y0_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 21U))->data;
  dy_err_d_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 20U))
    ->data;
  dy_err_p_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 19U))
    ->data;
  dy_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 18U))->data;
  dx_err_d_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 17U))
    ->data;
  dx_err_p_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 16U))
    ->data;
  dx_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 15U))->data;
  tau = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 14U))->data;
  thres_hi = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 13U))->data;
  thres_lo = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 12U))->data;
  s_r_B = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 11U))->data;
  s_r_A = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 10U))->data;
  s_l_B = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 9U))->data;
  s_l_A = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 8U))->data;
  kd_hip = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 7U))->data;
  kp_hip = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 6U))->data;
  kd_sw_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 5U))->data;
  kp_sw_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 4U))->data;
  kd_st_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 3U))->data;
  kp_st_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 2U))->data;
  t_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 1U))->data;
  t0_step = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 0U))->data;
  if (!moduleInstance->sysobj_not_empty) {
    moduleInstance->sysobj.stanceLeg = -1.0;
    moduleInstance->sysobj.q_yaw = 0.0;
    moduleInstance->sysobj.z_offset = 0.2087;
    moduleInstance->sysobj.runTime = 0.0;
    moduleInstance->sysobj.isInitialized = false;
    moduleInstance->sysobj.isReleased = false;
    moduleInstance->sysobj_not_empty = true;
    SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    b_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.t0_step = *t0_step;
    c_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.t_gain = *t_gain;
    d_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_st_leg = *kp_st_leg;
    e_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_st_leg = *kd_st_leg;
    f_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_sw_leg = *kp_sw_leg;
    g_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_sw_leg = *kd_sw_leg;
    h_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_hip = *kp_hip;
    i_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_hip = *kd_hip;
    j_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_l_A = *s_l_A;
    k_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_l_B = *s_l_B;
    l_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_r_A = *s_r_A;
    m_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_r_B = *s_r_B;
    n_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.thres_lo = *thres_lo;
    o_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.thres_hi = *thres_hi;
    p_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.tau = *tau;
    q_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dx_gain = *dx_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dx_err_p_gain = *dx_err_p_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dx_err_d_gain = *dx_err_d_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dy_gain = *dy_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dy_err_p_gain = *dy_err_p_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dy_err_d_gain = *dy_err_d_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.y0_offset = *y0_offset;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.y0_gain = *y0_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.l0_leg = *l0_leg;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.l_ret = *l_ret;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.l_ext_gain = *l_ext_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.s_overlap = *s_overlap;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest1 = *isTest1;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest2 = *isTest2;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest3 = *isTest3;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest4 = *isTest4;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest5 = *isTest5;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest6 = *isTest6;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest7 = *isTest7;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest8 = *isTest8;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest9 = *isTest9;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest10 = *isTest10;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest11 = *isTest11;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest12 = *isTest12;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.x_offset = *x_offset;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.steering_offset = *steering_offset;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.q_yaw_tgt = *q_yaw_tgt;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.y_offset = *y_offset;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.EnableYawControl = *EnableYawControl;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.uHipGravity = *uHipGravity;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.kp_rate = *kp_rate;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.kd_rate = *kd_rate;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isSim = *isSim;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i7 = 0; i7 < 4; i7++) {
      moduleInstance->sysobj.ps3Axes[i7] = (*ps3Axes)[i7];
    }

    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i7 = 0; i7 < 17; i7++) {
      moduleInstance->sysobj.ps3Buttons[i7] = (*ps3Buttons)[i7];
    }

    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.u_lim = *u_lim;
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isReleased) {
    y = NULL;
    m5 = emlrtCreateCharArray(2, iv10);
    for (i7 = 0; i7 < 45; i7++) {
      cv18[i7] = cv19[i7];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m5, cv18);
    emlrtAssign(&y, m5);
    b_y = NULL;
    m5 = emlrtCreateCharArray(2, iv11);
    for (i7 = 0; i7 < 8; i7++) {
      cv20[i7] = cv21[i7];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m5, cv20);
    emlrtAssign(&b_y, m5);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  flag = obj->isInitialized;
  if (flag && moduleInstance->sysobj.isReleased) {
    c_y = NULL;
    m5 = emlrtCreateCharArray(2, iv12);
    for (i7 = 0; i7 < 45; i7++) {
      cv18[i7] = cv19[i7];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m5, cv18);
    emlrtAssign(&c_y, m5);
    d_y = NULL;
    m5 = emlrtCreateCharArray(2, iv13);
    for (i7 = 0; i7 < 5; i7++) {
      cv22[i7] = cv23[i7];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 5, m5, cv22);
    emlrtAssign(&d_y, m5);
    error(message(c_y, d_y, &emlrtMCI), &emlrtMCI);
  }
}

static void cgxe_mdl_outputs(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance)
{
  real_T dv5[4];
  int32_T i8;
  real_T dv6[17];
  real_T dv7[13];
  real_T dv8[13];
  real_T dv9[2];
  real_T dv10[2];
  real_T dv11[2];
  real_T dv12[36];
  real_T b_y6;
  real_T b_y5[6];
  real_T b_y4[6];
  real_T b_y3;
  real_T b_y2[9];
  real_T c_y1[6];
  boolean_T c_y0;
  boolean_T *b_y0;
  real_T *y3;
  real_T *y6;
  real_T *t0_step;
  real_T *t_gain;
  real_T *kp_st_leg;
  real_T *kd_st_leg;
  real_T *kp_sw_leg;
  real_T *kd_sw_leg;
  real_T *kp_hip;
  real_T *kd_hip;
  real_T *s_l_A;
  real_T *s_l_B;
  real_T *s_r_A;
  real_T *s_r_B;
  real_T *thres_lo;
  real_T *thres_hi;
  real_T *tau;
  real_T *dx_gain;
  real_T *dx_err_p_gain;
  real_T *dx_err_d_gain;
  real_T *dy_gain;
  real_T *dy_err_p_gain;
  real_T *dy_err_d_gain;
  real_T *y0_offset;
  real_T *y0_gain;
  real_T *l0_leg;
  real_T *l_ret;
  real_T *l_ext_gain;
  real_T *s_overlap;
  boolean_T *isTest1;
  boolean_T *isTest2;
  boolean_T *isTest3;
  boolean_T *isTest4;
  boolean_T *isTest5;
  boolean_T *isTest6;
  boolean_T *isTest7;
  boolean_T *isTest8;
  boolean_T *isTest9;
  boolean_T *isTest10;
  boolean_T *isTest11;
  boolean_T *isTest12;
  real_T *x_offset;
  real_T *steering_offset;
  real_T *q_yaw_tgt;
  real_T *y_offset;
  real_T *EnableYawControl;
  real_T *uHipGravity;
  real_T *kp_rate;
  real_T *kd_rate;
  boolean_T *isSim;
  real_T *u_lim;
  real_T (*y4)[6];
  real_T (*y5)[6];
  real_T (*y2)[9];
  real_T (*b_y1)[6];
  real_T (*u5)[36];
  real_T (*u2)[2];
  real_T (*u3)[2];
  real_T (*u4)[2];
  real_T (*u0)[13];
  real_T (*u1)[13];
  real_T (*ps3Buttons)[17];
  real_T (*ps3Axes)[4];
  u_lim = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 50U))->data;
  ps3Buttons = (real_T (*)[17])(ssGetRunTimeParamInfo(moduleInstance->S, 49U))
    ->data;
  ps3Axes = (real_T (*)[4])(ssGetRunTimeParamInfo(moduleInstance->S, 48U))->data;
  isSim = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 47U))->data;
  kd_rate = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 46U))->data;
  kp_rate = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 45U))->data;
  uHipGravity = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 44U))->data;
  EnableYawControl = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 43U))
    ->data;
  y_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 42U))->data;
  q_yaw_tgt = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 41U))->data;
  steering_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 40U))
    ->data;
  x_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 39U))->data;
  isTest12 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 38U))->data;
  isTest11 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 37U))->data;
  isTest10 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 36U))->data;
  isTest9 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 35U))->data;
  isTest8 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 34U))->data;
  isTest7 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 33U))->data;
  isTest6 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 32U))->data;
  isTest5 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 31U))->data;
  isTest4 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 30U))->data;
  isTest3 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 29U))->data;
  isTest2 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 28U))->data;
  isTest1 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 27U))->data;
  s_overlap = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 26U))->data;
  l_ext_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 25U))->data;
  l_ret = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 24U))->data;
  l0_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 23U))->data;
  y0_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 22U))->data;
  y0_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 21U))->data;
  dy_err_d_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 20U))
    ->data;
  dy_err_p_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 19U))
    ->data;
  dy_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 18U))->data;
  dx_err_d_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 17U))
    ->data;
  dx_err_p_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 16U))
    ->data;
  dx_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 15U))->data;
  tau = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 14U))->data;
  thres_hi = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 13U))->data;
  thres_lo = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 12U))->data;
  s_r_B = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 11U))->data;
  s_r_A = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 10U))->data;
  s_l_B = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 9U))->data;
  s_l_A = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 8U))->data;
  kd_hip = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 7U))->data;
  kp_hip = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 6U))->data;
  kd_sw_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 5U))->data;
  kp_sw_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 4U))->data;
  kd_st_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 3U))->data;
  kp_st_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 2U))->data;
  t_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 1U))->data;
  t0_step = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 0U))->data;
  y6 = (real_T *)ssGetOutputPortSignal(moduleInstance->S, 6U);
  y5 = (real_T (*)[6])ssGetOutputPortSignal(moduleInstance->S, 5U);
  y4 = (real_T (*)[6])ssGetOutputPortSignal(moduleInstance->S, 4U);
  y3 = (real_T *)ssGetOutputPortSignal(moduleInstance->S, 3U);
  y2 = (real_T (*)[9])ssGetOutputPortSignal(moduleInstance->S, 2U);
  b_y1 = (real_T (*)[6])ssGetOutputPortSignal(moduleInstance->S, 1U);
  b_y0 = (boolean_T *)ssGetOutputPortSignal(moduleInstance->S, 0U);
  u5 = (real_T (*)[36])ssGetInputPortSignal(moduleInstance->S, 5U);
  u4 = (real_T (*)[2])ssGetInputPortSignal(moduleInstance->S, 4U);
  u3 = (real_T (*)[2])ssGetInputPortSignal(moduleInstance->S, 3U);
  u2 = (real_T (*)[2])ssGetInputPortSignal(moduleInstance->S, 2U);
  u1 = (real_T (*)[13])ssGetInputPortSignal(moduleInstance->S, 1U);
  u0 = (real_T (*)[13])ssGetInputPortSignal(moduleInstance->S, 0U);
  for (i8 = 0; i8 < 4; i8++) {
    dv5[i8] = (*ps3Axes)[i8];
  }

  for (i8 = 0; i8 < 17; i8++) {
    dv6[i8] = (*ps3Buttons)[i8];
  }

  for (i8 = 0; i8 < 13; i8++) {
    dv7[i8] = (*u0)[i8];
    dv8[i8] = (*u1)[i8];
  }

  for (i8 = 0; i8 < 2; i8++) {
    dv9[i8] = (*u2)[i8];
    dv10[i8] = (*u3)[i8];
    dv11[i8] = (*u4)[i8];
  }

  for (i8 = 0; i8 < 36; i8++) {
    dv12[i8] = (*u5)[i8];
  }

  mw__internal__system___fcn(moduleInstance, *t0_step, *t_gain, *kp_st_leg,
    *kd_st_leg, *kp_sw_leg, *kd_sw_leg, *kp_hip, *kd_hip, *s_l_A, *s_l_B, *s_r_A,
    *s_r_B, *thres_lo, *thres_hi, *tau, *dx_gain, *dx_err_p_gain, *dx_err_d_gain,
    *dy_gain, *dy_err_p_gain, *dy_err_d_gain, *y0_offset, *y0_gain, *l0_leg,
    *l_ret, *l_ext_gain, *s_overlap, *isTest1, *isTest2, *isTest3, *isTest4,
    *isTest5, *isTest6, *isTest7, *isTest8, *isTest9, *isTest10, *isTest11,
    *isTest12, *x_offset, *steering_offset, *q_yaw_tgt, *y_offset,
    *EnableYawControl, *uHipGravity, *kp_rate, *kd_rate, *isSim, dv5, dv6,
    *u_lim, dv7, dv8, dv9, dv10, dv11, dv12, &c_y0, c_y1, b_y2, &b_y3, b_y4,
    b_y5, &b_y6);
  *b_y0 = c_y0;
  for (i8 = 0; i8 < 6; i8++) {
    (*b_y1)[i8] = c_y1[i8];
  }

  for (i8 = 0; i8 < 9; i8++) {
    (*y2)[i8] = b_y2[i8];
  }

  *y3 = 0.0;
  for (i8 = 0; i8 < 6; i8++) {
    (*y4)[i8] = b_y4[i8];
    (*y5)[i8] = b_y5[i8];
  }

  *y6 = b_y6;
}

static void cgxe_mdl_update(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance)
{
  (void)moduleInstance;
}

static void cgxe_mdl_terminate(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance)
{
  boolean_T flag;
  int32_T i9;
  MikhailController_MARLO_Steeringv2_2 *obj;
  const mxArray *y;
  static const int32_T iv14[2] = { 1, 45 };

  const mxArray *m6;
  char_T cv24[45];
  static char_T cv25[45] = { 'M', 'A', 'T', 'L', 'A', 'B', ':', 's', 'y', 's',
    't', 'e', 'm', ':', 'm', 'e', 't', 'h', 'o', 'd', 'C', 'a', 'l', 'l', 'e',
    'd', 'W', 'h', 'e', 'n', 'R', 'e', 'l', 'e', 'a', 's', 'e', 'd', 'C', 'o',
    'd', 'e', 'g', 'e', 'n' };

  const mxArray *b_y;
  static const int32_T iv15[2] = { 1, 8 };

  char_T cv26[8];
  static char_T cv27[8] = { 'i', 's', 'L', 'o', 'c', 'k', 'e', 'd' };

  const mxArray *c_y;
  static const int32_T iv16[2] = { 1, 45 };

  const mxArray *d_y;
  static const int32_T iv17[2] = { 1, 7 };

  char_T cv28[7];
  static char_T cv29[7] = { 'r', 'e', 'l', 'e', 'a', 's', 'e' };

  real_T *t0_step;
  real_T *t_gain;
  real_T *kp_st_leg;
  real_T *kd_st_leg;
  real_T *kp_sw_leg;
  real_T *kd_sw_leg;
  real_T *kp_hip;
  real_T *kd_hip;
  real_T *s_l_A;
  real_T *s_l_B;
  real_T *s_r_A;
  real_T *s_r_B;
  real_T *thres_lo;
  real_T *thres_hi;
  real_T *tau;
  real_T *dx_gain;
  real_T *dx_err_p_gain;
  real_T *dx_err_d_gain;
  real_T *dy_gain;
  real_T *dy_err_p_gain;
  real_T *dy_err_d_gain;
  real_T *y0_offset;
  real_T *y0_gain;
  real_T *l0_leg;
  real_T *l_ret;
  real_T *l_ext_gain;
  real_T *s_overlap;
  boolean_T *isTest1;
  boolean_T *isTest2;
  boolean_T *isTest3;
  boolean_T *isTest4;
  boolean_T *isTest5;
  boolean_T *isTest6;
  boolean_T *isTest7;
  boolean_T *isTest8;
  boolean_T *isTest9;
  boolean_T *isTest10;
  boolean_T *isTest11;
  boolean_T *isTest12;
  real_T *x_offset;
  real_T *steering_offset;
  real_T *q_yaw_tgt;
  real_T *y_offset;
  real_T *EnableYawControl;
  real_T *uHipGravity;
  real_T *kp_rate;
  real_T *kd_rate;
  boolean_T *isSim;
  real_T *u_lim;
  real_T (*ps3Buttons)[17];
  real_T (*ps3Axes)[4];
  u_lim = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 50U))->data;
  ps3Buttons = (real_T (*)[17])(ssGetRunTimeParamInfo(moduleInstance->S, 49U))
    ->data;
  ps3Axes = (real_T (*)[4])(ssGetRunTimeParamInfo(moduleInstance->S, 48U))->data;
  isSim = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 47U))->data;
  kd_rate = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 46U))->data;
  kp_rate = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 45U))->data;
  uHipGravity = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 44U))->data;
  EnableYawControl = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 43U))
    ->data;
  y_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 42U))->data;
  q_yaw_tgt = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 41U))->data;
  steering_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 40U))
    ->data;
  x_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 39U))->data;
  isTest12 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 38U))->data;
  isTest11 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 37U))->data;
  isTest10 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 36U))->data;
  isTest9 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 35U))->data;
  isTest8 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 34U))->data;
  isTest7 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 33U))->data;
  isTest6 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 32U))->data;
  isTest5 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 31U))->data;
  isTest4 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 30U))->data;
  isTest3 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 29U))->data;
  isTest2 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 28U))->data;
  isTest1 = (boolean_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 27U))->data;
  s_overlap = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 26U))->data;
  l_ext_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 25U))->data;
  l_ret = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 24U))->data;
  l0_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 23U))->data;
  y0_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 22U))->data;
  y0_offset = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 21U))->data;
  dy_err_d_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 20U))
    ->data;
  dy_err_p_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 19U))
    ->data;
  dy_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 18U))->data;
  dx_err_d_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 17U))
    ->data;
  dx_err_p_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 16U))
    ->data;
  dx_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 15U))->data;
  tau = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 14U))->data;
  thres_hi = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 13U))->data;
  thres_lo = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 12U))->data;
  s_r_B = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 11U))->data;
  s_r_A = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 10U))->data;
  s_l_B = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 9U))->data;
  s_l_A = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 8U))->data;
  kd_hip = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 7U))->data;
  kp_hip = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 6U))->data;
  kd_sw_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 5U))->data;
  kp_sw_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 4U))->data;
  kd_st_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 3U))->data;
  kp_st_leg = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 2U))->data;
  t_gain = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 1U))->data;
  t0_step = (real_T *)(ssGetRunTimeParamInfo(moduleInstance->S, 0U))->data;
  if (!moduleInstance->sysobj_not_empty) {
    moduleInstance->sysobj.stanceLeg = -1.0;
    moduleInstance->sysobj.q_yaw = 0.0;
    moduleInstance->sysobj.z_offset = 0.2087;
    moduleInstance->sysobj.runTime = 0.0;
    moduleInstance->sysobj.isInitialized = false;
    moduleInstance->sysobj.isReleased = false;
    moduleInstance->sysobj_not_empty = true;
    SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    b_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.t0_step = *t0_step;
    c_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.t_gain = *t_gain;
    d_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_st_leg = *kp_st_leg;
    e_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_st_leg = *kd_st_leg;
    f_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_sw_leg = *kp_sw_leg;
    g_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_sw_leg = *kd_sw_leg;
    h_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kp_hip = *kp_hip;
    i_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.kd_hip = *kd_hip;
    j_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_l_A = *s_l_A;
    k_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_l_B = *s_l_B;
    l_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_r_A = *s_r_A;
    m_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.s_r_B = *s_r_B;
    n_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.thres_lo = *thres_lo;
    o_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.thres_hi = *thres_hi;
    p_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.tau = *tau;
    q_SystemProp_matlabCodegenNotifyAnyProp(&moduleInstance->sysobj);
    moduleInstance->sysobj.dx_gain = *dx_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dx_err_p_gain = *dx_err_p_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dx_err_d_gain = *dx_err_d_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dy_gain = *dy_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dy_err_p_gain = *dy_err_p_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.dy_err_d_gain = *dy_err_d_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.y0_offset = *y0_offset;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.y0_gain = *y0_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.l0_leg = *l0_leg;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.l_ret = *l_ret;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.l_ext_gain = *l_ext_gain;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.s_overlap = *s_overlap;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest1 = *isTest1;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest2 = *isTest2;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest3 = *isTest3;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest4 = *isTest4;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest5 = *isTest5;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest6 = *isTest6;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest7 = *isTest7;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest8 = *isTest8;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest9 = *isTest9;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest10 = *isTest10;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest11 = *isTest11;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isTest12 = *isTest12;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.x_offset = *x_offset;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.steering_offset = *steering_offset;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.q_yaw_tgt = *q_yaw_tgt;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.y_offset = *y_offset;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.EnableYawControl = *EnableYawControl;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.uHipGravity = *uHipGravity;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.kp_rate = *kp_rate;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.kd_rate = *kd_rate;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.isSim = *isSim;
    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i9 = 0; i9 < 4; i9++) {
      moduleInstance->sysobj.ps3Axes[i9] = (*ps3Axes)[i9];
    }

    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    for (i9 = 0; i9 < 17; i9++) {
      moduleInstance->sysobj.ps3Buttons[i9] = (*ps3Buttons)[i9];
    }

    if (moduleInstance->sysobj.isInitialized &&
        !moduleInstance->sysobj.isReleased) {
      flag = true;
    } else {
      flag = false;
    }

    if (flag) {
      moduleInstance->sysobj.TunablePropsChanged = true;
    }

    moduleInstance->sysobj.u_lim = *u_lim;
  }

  obj = &moduleInstance->sysobj;
  if (moduleInstance->sysobj.isReleased) {
    y = NULL;
    m6 = emlrtCreateCharArray(2, iv14);
    for (i9 = 0; i9 < 45; i9++) {
      cv24[i9] = cv25[i9];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m6, cv24);
    emlrtAssign(&y, m6);
    b_y = NULL;
    m6 = emlrtCreateCharArray(2, iv15);
    for (i9 = 0; i9 < 8; i9++) {
      cv26[i9] = cv27[i9];
    }

    emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 8, m6, cv26);
    emlrtAssign(&b_y, m6);
    error(message(y, b_y, &emlrtMCI), &emlrtMCI);
  }

  flag = obj->isInitialized;
  if (flag) {
    obj = &moduleInstance->sysobj;
    if (moduleInstance->sysobj.isReleased) {
      c_y = NULL;
      m6 = emlrtCreateCharArray(2, iv16);
      for (i9 = 0; i9 < 45; i9++) {
        cv24[i9] = cv25[i9];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 45, m6, cv24);
      emlrtAssign(&c_y, m6);
      d_y = NULL;
      m6 = emlrtCreateCharArray(2, iv17);
      for (i9 = 0; i9 < 7; i9++) {
        cv28[i9] = cv29[i9];
      }

      emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 7, m6, cv28);
      emlrtAssign(&d_y, m6);
      error(message(c_y, d_y, &emlrtMCI), &emlrtMCI);
    }

    if (obj->isInitialized) {
      obj->isReleased = true;
    }
  }
}

static const mxArray *mw__internal__name__resolution__fcn(void)
{
  const mxArray *nameCaptureInfo;
  nameCaptureInfo = NULL;
  emlrtAssign(&nameCaptureInfo, emlrtCreateStructMatrix(288, 1, 0, NULL));
  info_helper(&nameCaptureInfo);
  b_info_helper(&nameCaptureInfo);
  c_info_helper(&nameCaptureInfo);
  d_info_helper(&nameCaptureInfo);
  e_info_helper(&nameCaptureInfo);
  emlrtNameCapturePostProcessR2013b(&nameCaptureInfo);
  return nameCaptureInfo;
}

static void info_helper(const mxArray **info)
{
  emlrtAddField(*info, emlrt_marshallOut(""), "context", 0);
  emlrtAddField(*info, emlrt_marshallOut("repmat"), "name", 0);
  emlrtAddField(*info, emlrt_marshallOut("struct"), "dominantType", 0);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "resolved", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604014U), "fileTimeLo", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 0);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 0);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 1);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 1);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 1);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(1389739374U), "fileTimeLo", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 1);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 1);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 2);
  emlrtAddField(*info, emlrt_marshallOut("eml_assert_valid_size_arg"), "name", 2);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 2);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "resolved", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(1368204630U), "fileTimeLo", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 2);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 2);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 3);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 3);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 3);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 3);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 3);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isintegral"),
                "context", 4);
  emlrtAddField(*info, emlrt_marshallOut("isinf"), "name", 4);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 4);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731856U), "fileTimeLo", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 4);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 4);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "context", 5);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 5);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 5);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 5);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 5);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 6);
  emlrtAddField(*info, emlrt_marshallOut("eml_is_integer_class"), "name", 6);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 6);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_integer_class.m"),
                "resolved", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840382U), "fileTimeLo", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 6);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 6);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 7);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 7);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 7);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 7);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 7);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "context", 8);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 8);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 8);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(1393352458U), "fileTimeLo", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 8);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 8);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 9);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 9);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 9);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 9);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 9);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "context", 10);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 10);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 10);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(1393352458U), "fileTimeLo", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 10);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 10);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m!isinbounds"),
                "context", 11);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexIntRelop"), "name",
                11);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 11);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m"),
                "resolved", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(1326749922U), "fileTimeLo", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 11);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 11);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!apply_float_relop"),
                "context", 12);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 12);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 12);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(1393352458U), "fileTimeLo", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 12);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 12);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!float_class_contains_indexIntClass"),
                "context", 13);
  emlrtAddField(*info, emlrt_marshallOut("eml_float_model"), "name", 13);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 13);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                "resolved", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(1326749596U), "fileTimeLo", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 13);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 13);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexIntRelop.m!is_signed_indexIntClass"),
                "context", 14);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 14);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 14);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 14);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 14);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 15);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 15);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 15);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(1323192178U), "fileTimeLo", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 15);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 15);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_assert_valid_size_arg.m"),
                "context", 16);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 16);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 16);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 16);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 16);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 17);
  emlrtAddField(*info, emlrt_marshallOut("max"), "name", 17);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 17);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(1311276916U), "fileTimeLo", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 17);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 17);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "context", 18);
  emlrtAddField(*info, emlrt_marshallOut("eml_min_or_max"), "name", 18);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 18);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                "resolved", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(1378317584U), "fileTimeLo", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 18);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 18);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 19);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 19);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 19);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                19);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 19);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 19);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                20);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 20);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 20);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 20);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 20);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 21);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_alloc"), "name", 21);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 21);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "resolved", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 21);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 21);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "context", 22);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalexpAlloc"), "name",
                22);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 22);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                "resolved", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 22);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 22);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 23);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 23);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 23);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(1323192178U), "fileTimeLo", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 23);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 23);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 24);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 24);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 24);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                24);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 24);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 24);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 25);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 25);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 25);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 25);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 25);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/repmat.m"), "context", 26);
  emlrtAddField(*info, emlrt_marshallOut("eml_int_forloop_overflow_check"),
                "name", 26);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 26);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                "resolved", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(1397279022U), "fileTimeLo", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 26);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 26);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                "context", 27);
  emlrtAddField(*info, emlrt_marshallOut("isfi"), "name", 27);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 27);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "resolved", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(1346531958U), "fileTimeLo", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 27);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 27);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isfi.m"), "context", 28);
  emlrtAddField(*info, emlrt_marshallOut("isnumerictype"), "name", 28);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 28);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/fixedpoint/isnumerictype.m"), "resolved",
                28);
  emlrtAddField(*info, b_emlrt_marshallOut(1398897198U), "fileTimeLo", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 28);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 28);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                "context", 29);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 29);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 29);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 29);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 29);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m!eml_int_forloop_overflow_check_helper"),
                "context", 30);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 30);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 30);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 30);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 30);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 31);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 31);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 31);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 31);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 31);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "context", 32);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemProp"),
                "name", 32);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 32);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "resolved", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829222U), "fileTimeLo", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 32);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 32);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "context", 33);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 33);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 33);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 33);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 33);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "context", 34);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemCore"),
                "name", 34);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 34);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "resolved", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829222U), "fileTimeLo", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 34);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 34);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/Controller_MARLO.m"), "context", 35);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.System"), "name",
                35);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 35);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/System.p"),
                "resolved", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829222U), "fileTimeLo", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 35);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 35);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 36);
  emlrtAddField(*info, emlrt_marshallOut("Controller_MARLO"), "name", 36);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 36);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/Controller_MARLO.m"), "resolved", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(1446514649U), "fileTimeLo", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 36);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 36);
  emlrtAddField(*info, emlrt_marshallOut(""), "context", 37);
  emlrtAddField(*info, emlrt_marshallOut("MikhailController_MARLO_Steeringv2"),
                "name", 37);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 37);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "resolved", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(1446518988U), "fileTimeLo", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 37);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 37);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "context", 38);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemProp"),
                "name", 38);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 38);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemProp.p"),
                "resolved", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829222U), "fileTimeLo", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 38);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 38);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "context", 39);
  emlrtAddField(*info, emlrt_marshallOut("matlab.system.coder.SystemCore"),
                "name", 39);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 39);
  emlrtAddField(*info, emlrt_marshallOut(
    "[IXC]$matlabroot$/toolbox/shared/system/coder/+matlab/+system/+coder/SystemCore.p"),
                "resolved", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829222U), "fileTimeLo", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 39);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 39);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/PS3Controller.m"), "context", 40);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 40);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 40);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 40);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 40);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/Controller_MARLO.m"), "context", 41);
  emlrtAddField(*info, emlrt_marshallOut("PS3Controller"), "name", 41);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 41);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/PS3Controller.m"), "resolved", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(1434030903U), "fileTimeLo", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 41);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 41);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/PS3Button.m"), "context", 42);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.matlabCodegenHandle"),
                "name", 42);
  emlrtAddField(*info, emlrt_marshallOut("unknown"), "dominantType", 42);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXC]$matlabroot$/toolbox/coder/coder/+coder/+internal/matlabCodegenHandle.p"),
                "resolved", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 42);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 42);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/PS3Controller.m"), "context", 43);
  emlrtAddField(*info, emlrt_marshallOut("PS3Button"), "name", 43);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 43);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/PS3Button.m"), "resolved", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(1434030903U), "fileTimeLo", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 43);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 43);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 44);
  emlrtAddField(*info, emlrt_marshallOut("GaitMode"), "name", 44);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 44);
  emlrtAddField(*info, emlrt_marshallOut(
    "[N]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/controllers/osu/simple-walk-3d/GaitMode.m"), "resolved", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(1434030903U), "fileTimeLo", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 44);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 44);
  emlrtAddField(*info, emlrt_marshallOut(""), "context", 45);
  emlrtAddField(*info, emlrt_marshallOut("isequal"), "name", 45);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 45);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840358U), "fileTimeLo", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 45);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 45);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context", 46);
  emlrtAddField(*info, emlrt_marshallOut("eml_isequal_core"), "name", 46);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 46);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                "resolved", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840386U), "fileTimeLo", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 46);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 46);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                "context", 47);
  emlrtAddField(*info, emlrt_marshallOut("isnan"), "name", 47);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 47);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731858U), "fileTimeLo", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 47);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 47);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context", 48);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 48);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 48);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 48);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 48);
  emlrtAddField(*info, emlrt_marshallOut(""), "context", 49);
  emlrtAddField(*info, emlrt_marshallOut("isequal"), "name", 49);
  emlrtAddField(*info, emlrt_marshallOut("logical"), "dominantType", 49);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840358U), "fileTimeLo", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 49);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 49);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "context", 50);
  emlrtAddField(*info, emlrt_marshallOut("eml_isequal_core"), "name", 50);
  emlrtAddField(*info, emlrt_marshallOut("logical"), "dominantType", 50);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m"),
                "resolved", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840386U), "fileTimeLo", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 50);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 50);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isequal_core.m!isequal_scalar"),
                "context", 51);
  emlrtAddField(*info, emlrt_marshallOut("isnan"), "name", 51);
  emlrtAddField(*info, emlrt_marshallOut("logical"), "dominantType", 51);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731858U), "fileTimeLo", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 51);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 51);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "context", 52);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 52);
  emlrtAddField(*info, emlrt_marshallOut("logical"), "dominantType", 52);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 52);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 52);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/PS3Button.m"), "context", 53);
  emlrtAddField(*info, emlrt_marshallOut("eml_mtimes_helper"), "name", 53);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 53);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                "resolved", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(1383898894U), "fileTimeLo", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 53);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 53);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                "context", 54);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 54);
  emlrtAddField(*info, emlrt_marshallOut("logical"), "dominantType", 54);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 54);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 54);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m!common_checks"),
                "context", 55);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 55);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 55);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 55);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 55);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 56);
  emlrtAddField(*info, emlrt_marshallOut("clamp"), "name", 56);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 56);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/clamp.m"), "resolved", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(1434030903U), "fileTimeLo", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 56);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 56);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/clamp.m"), "context", 57);
  emlrtAddField(*info, emlrt_marshallOut("min"), "name", 57);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 57);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(1311276918U), "fileTimeLo", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 57);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 57);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "context", 58);
  emlrtAddField(*info, emlrt_marshallOut("eml_min_or_max"), "name", 58);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 58);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m"),
                "resolved", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(1378317584U), "fileTimeLo", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 58);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 58);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 59);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 59);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 59);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                59);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 59);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 59);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "context",
                60);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 60);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 60);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 60);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 60);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 61);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_alloc"), "name", 61);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 61);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "resolved", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 61);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 61);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "context", 62);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalexpAlloc"), "name",
                62);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 62);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                "resolved", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 62);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 62);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 63);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 63);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 63);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                63);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 63);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 63);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 63);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 63);
}

static const mxArray *emlrt_marshallOut(const char * u)
{
  const mxArray *y;
  const mxArray *m7;
  y = NULL;
  m7 = emlrtCreateString(u);
  emlrtAssign(&y, m7);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const uint32_T u)
{
  const mxArray *y;
  const mxArray *m8;
  y = NULL;
  m8 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)mxGetData(m8) = u;
  emlrtAssign(&y, m8);
  return y;
}

static void b_info_helper(const mxArray **info)
{
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_scalar_bin_extremum"),
                "context", 64);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 64);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 64);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 64);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 64);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/clamp.m"), "context", 65);
  emlrtAddField(*info, emlrt_marshallOut("max"), "name", 65);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 65);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(1311276916U), "fileTimeLo", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 65);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 65);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 66);
  emlrtAddField(*info, emlrt_marshallOut("cos"), "name", 66);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 66);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "resolved", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(1395346496U), "fileTimeLo", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 66);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 66);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m"), "context", 67);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_cos"), "name", 67);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 67);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m"),
                "resolved", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840322U), "fileTimeLo", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 67);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 67);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 68);
  emlrtAddField(*info, emlrt_marshallOut("sin"), "name", 68);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 68);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "resolved", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(1395346504U), "fileTimeLo", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 68);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 68);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m"), "context", 69);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_sin"), "name", 69);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 69);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m"),
                "resolved", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840336U), "fileTimeLo", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 69);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 69);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 70);
  emlrtAddField(*info, emlrt_marshallOut("abs"), "name", 70);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 70);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731852U), "fileTimeLo", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 70);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 70);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context", 71);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 71);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 71);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 71);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 71);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context", 72);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_abs"), "name", 72);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 72);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                "resolved", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840312U), "fileTimeLo", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 72);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 72);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 73);
  emlrtAddField(*info, emlrt_marshallOut("mrdivide"), "name", 73);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 73);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829248U), "fileTimeLo", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(1370031486U), "mFileTimeLo", 73);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 73);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context", 74);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 74);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 74);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(1389739374U), "fileTimeLo", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 74);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 74);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context", 75);
  emlrtAddField(*info, emlrt_marshallOut("rdivide"), "name", 75);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 75);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731880U), "fileTimeLo", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 75);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 75);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context", 76);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 76);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 76);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 76);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 76);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context", 77);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_compatible"), "name", 77);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 77);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                "resolved", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840396U), "fileTimeLo", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 77);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 77);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context", 78);
  emlrtAddField(*info, emlrt_marshallOut("eml_div"), "name", 78);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 78);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(1386445552U), "fileTimeLo", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 78);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 78);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context", 79);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.div"), "name", 79);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 79);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                79);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 79);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 79);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m!sc"
    "aleFactor"), "context", 80);
  emlrtAddField(*info, emlrt_marshallOut("clamp"), "name", 80);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 80);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/clamp.m"), "resolved", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(1434030903U), "fileTimeLo", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 80);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 80);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m!sc"
    "aleFactor"), "context", 81);
  emlrtAddField(*info, emlrt_marshallOut("mrdivide"), "name", 81);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 81);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829248U), "fileTimeLo", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(1370031486U), "mFileTimeLo", 81);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 81);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 82);
  emlrtAddField(*info, emlrt_marshallOut("eml_mtimes_helper"), "name", 82);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 82);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                "resolved", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(1383898894U), "fileTimeLo", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 82);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 82);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 83);
  emlrtAddField(*info, emlrt_marshallOut("max"), "name", 83);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 83);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(1311276916U), "fileTimeLo", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 83);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 83);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 84);
  emlrtAddField(*info, emlrt_marshallOut("cubic_interp"), "name", 84);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 84);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/cubic_interp.m"), "resolved", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(1434030903U), "fileTimeLo", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 84);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 84);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/cubic_interp.m"), "context", 85);
  emlrtAddField(*info, emlrt_marshallOut("isequal"), "name", 85);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 85);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840358U), "fileTimeLo", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 85);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 85);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/cubic_interp.m"), "context", 86);
  emlrtAddField(*info, emlrt_marshallOut("clamp"), "name", 86);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 86);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/clamp.m"), "resolved", 86);
  emlrtAddField(*info, b_emlrt_marshallOut(1434030903U), "fileTimeLo", 86);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 86);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 86);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 86);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/cubic_interp.m"), "context", 87);
  emlrtAddField(*info, emlrt_marshallOut("mrdivide"), "name", 87);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 87);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved", 87);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829248U), "fileTimeLo", 87);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 87);
  emlrtAddField(*info, b_emlrt_marshallOut(1370031486U), "mFileTimeLo", 87);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 87);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/cubic_interp.m"), "context", 88);
  emlrtAddField(*info, emlrt_marshallOut("mpower"), "name", 88);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 88);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved", 88);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731878U), "fileTimeLo", 88);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 88);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 88);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 88);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context", 89);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 89);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 89);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 89);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 89);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 89);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 89);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 89);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context", 90);
  emlrtAddField(*info, emlrt_marshallOut("ismatrix"), "name", 90);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 90);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/ismatrix.m"), "resolved",
                90);
  emlrtAddField(*info, b_emlrt_marshallOut(1331326458U), "fileTimeLo", 90);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 90);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 90);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 90);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "context", 91);
  emlrtAddField(*info, emlrt_marshallOut("power"), "name", 91);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 91);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved", 91);
  emlrtAddField(*info, b_emlrt_marshallOut(1395346506U), "fileTimeLo", 91);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 91);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 91);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 91);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "context", 92);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 92);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 92);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 92);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 92);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 92);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 92);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 92);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                93);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 93);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 93);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                93);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 93);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 93);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 93);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 93);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                94);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalexp_alloc"), "name", 94);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 94);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_alloc.m"),
                "resolved", 94);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 94);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 94);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 94);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 94);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                95);
  emlrtAddField(*info, emlrt_marshallOut("floor"), "name", 95);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 95);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved", 95);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731854U), "fileTimeLo", 95);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 95);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 95);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 95);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context", 96);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 96);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 96);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 96);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 96);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 96);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 96);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 96);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "context", 97);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_floor"), "name", 97);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 97);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_floor.m"),
                "resolved", 97);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840326U), "fileTimeLo", 97);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 97);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 97);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 97);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!scalar_float_power"),
                "context", 98);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 98);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 98);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                98);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 98);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 98);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 98);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 98);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 99);
  emlrtAddField(*info, emlrt_marshallOut("sign"), "name", 99);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 99);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "resolved", 99);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731856U), "fileTimeLo", 99);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 99);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 99);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 99);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context", 100);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 100);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 100);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 100);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 100);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 100);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 100);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 100);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sign.m"), "context", 101);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_sign"), "name", 101);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 101);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sign.m"),
                "resolved", 101);
  emlrtAddField(*info, b_emlrt_marshallOut(1356563094U), "fileTimeLo", 101);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 101);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 101);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 101);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 102);
  emlrtAddField(*info, emlrt_marshallOut("mean"), "name", 102);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 102);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "resolved", 102);
  emlrtAddField(*info, b_emlrt_marshallOut(1397279022U), "fileTimeLo", 102);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 102);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 102);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 102);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context", 103);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 103);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 103);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 103);
  emlrtAddField(*info, b_emlrt_marshallOut(1389739374U), "fileTimeLo", 103);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 103);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 103);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 103);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context", 104);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 104);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 104);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 104);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 104);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 104);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 104);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 104);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context", 105);
  emlrtAddField(*info, emlrt_marshallOut("process_sumprod_inputs"), "name", 105);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 105);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                "resolved", 105);
  emlrtAddField(*info, b_emlrt_marshallOut(1395948302U), "fileTimeLo", 105);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 105);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 105);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 105);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                "context", 106);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.narginchk"), "name",
                106);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 106);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                "resolved", 106);
  emlrtAddField(*info, b_emlrt_marshallOut(1363732558U), "fileTimeLo", 106);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 106);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 106);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 106);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                "context", 107);
  emlrtAddField(*info, emlrt_marshallOut("floor"), "name", 107);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 107);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved", 107);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731854U), "fileTimeLo", 107);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 107);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 107);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 107);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/narginchk.m"),
                "context", 108);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 108);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 108);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 108);
  emlrtAddField(*info, b_emlrt_marshallOut(1389739374U), "fileTimeLo", 108);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 108);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 108);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 108);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                "context", 109);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.constNonSingletonDim"),
                "name", 109);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 109);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/constNonSingletonDim.m"),
                "resolved", 109);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604760U), "fileTimeLo", 109);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 109);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 109);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 109);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                "context", 110);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 110);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 110);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 110);
  emlrtAddField(*info, b_emlrt_marshallOut(1389739374U), "fileTimeLo", 110);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 110);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 110);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 110);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/process_sumprod_inputs.m"),
                "context", 111);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 111);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 111);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                111);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 111);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 111);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 111);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 111);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context", 112);
  emlrtAddField(*info, emlrt_marshallOut("isequal"), "name", 112);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 112);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isequal.m"), "resolved",
                112);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840358U), "fileTimeLo", 112);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 112);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 112);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 112);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context", 113);
  emlrtAddField(*info, emlrt_marshallOut("combine_vector_elements"), "name", 113);
  emlrtAddField(*info, emlrt_marshallOut("function_handle"), "dominantType", 113);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXPE]$matlabroot$/toolbox/eml/lib/matlab/datafun/private/combine_vector_elements.m"),
                "resolved", 113);
  emlrtAddField(*info, b_emlrt_marshallOut(1395948302U), "fileTimeLo", 113);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 113);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 113);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 113);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/mean.m"), "context", 114);
  emlrtAddField(*info, emlrt_marshallOut("rdivide"), "name", 114);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 114);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved", 114);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731880U), "fileTimeLo", 114);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 114);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 114);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 114);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 115);
  emlrtAddField(*info, emlrt_marshallOut("acos"), "name", 115);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 115);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m"), "resolved", 115);
  emlrtAddField(*info, b_emlrt_marshallOut(1395346492U), "fileTimeLo", 115);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 115);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 115);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 115);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/acos.m"), "context", 116);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_acos"), "name", 116);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 116);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m"),
                "resolved", 116);
  emlrtAddField(*info, b_emlrt_marshallOut(1343851976U), "fileTimeLo", 116);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 116);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 116);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 116);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m"),
                "context", 117);
  emlrtAddField(*info, emlrt_marshallOut("abs"), "name", 117);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 117);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved", 117);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731852U), "fileTimeLo", 117);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 117);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 117);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 117);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m"),
                "context", 118);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_sqrt"), "name", 118);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 118);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                "resolved", 118);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840338U), "fileTimeLo", 118);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 118);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 118);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 118);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                "context", 119);
  emlrtAddField(*info, emlrt_marshallOut("rdivide"), "name", 119);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 119);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved", 119);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731880U), "fileTimeLo", 119);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 119);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 119);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 119);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                "context", 120);
  emlrtAddField(*info, emlrt_marshallOut("isnan"), "name", 120);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 120);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved", 120);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731858U), "fileTimeLo", 120);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 120);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 120);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 120);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                "context", 121);
  emlrtAddField(*info, emlrt_marshallOut("eml_guarded_nan"), "name", 121);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 121);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                "resolved", 121);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840376U), "fileTimeLo", 121);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 121);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 121);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 121);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                "context", 122);
  emlrtAddField(*info, emlrt_marshallOut("eml_is_float_class"), "name", 122);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 122);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                "resolved", 122);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840382U), "fileTimeLo", 122);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 122);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 122);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 122);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                "context", 123);
  emlrtAddField(*info, emlrt_marshallOut("isinf"), "name", 123);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 123);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved", 123);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731856U), "fileTimeLo", 123);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 123);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 123);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 123);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                "context", 124);
  emlrtAddField(*info, emlrt_marshallOut("eml_guarded_inf"), "name", 124);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 124);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m"),
                "resolved", 124);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840376U), "fileTimeLo", 124);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 124);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 124);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 124);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m"),
                "context", 125);
  emlrtAddField(*info, emlrt_marshallOut("eml_is_float_class"), "name", 125);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 125);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                "resolved", 125);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840382U), "fileTimeLo", 125);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 125);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 125);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 125);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                "context", 126);
  emlrtAddField(*info, emlrt_marshallOut("realmax"), "name", 126);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 126);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                126);
  emlrtAddField(*info, b_emlrt_marshallOut(1307672842U), "fileTimeLo", 126);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 126);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 126);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 126);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "context", 127);
  emlrtAddField(*info, emlrt_marshallOut("eml_realmax"), "name", 127);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 127);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "resolved",
                127);
  emlrtAddField(*info, b_emlrt_marshallOut(1326749596U), "fileTimeLo", 127);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 127);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 127);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 127);
}

static void c_info_helper(const mxArray **info)
{
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmax.m"), "context",
                128);
  emlrtAddField(*info, emlrt_marshallOut("eml_float_model"), "name", 128);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 128);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                "resolved", 128);
  emlrtAddField(*info, b_emlrt_marshallOut(1326749596U), "fileTimeLo", 128);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 128);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 128);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 128);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                "context", 129);
  emlrtAddField(*info, emlrt_marshallOut("mrdivide"), "name", 129);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 129);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved", 129);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829248U), "fileTimeLo", 129);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 129);
  emlrtAddField(*info, b_emlrt_marshallOut(1370031486U), "mFileTimeLo", 129);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 129);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m!eml_complex_scalar_sqrt"),
                "context", 130);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_hypot"), "name", 130);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 130);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                "resolved", 130);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840326U), "fileTimeLo", 130);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 130);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 130);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 130);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                "context", 131);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 131);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 131);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                131);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 131);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 131);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 131);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 131);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_hypot.m"),
                "context", 132);
  emlrtAddField(*info, emlrt_marshallOut("eml_dlapy2"), "name", 132);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 132);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_dlapy2.m"), "resolved",
                132);
  emlrtAddField(*info, b_emlrt_marshallOut(1350432254U), "fileTimeLo", 132);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 132);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 132);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 132);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m"),
                "context", 133);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_asinh"), "name", 133);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 133);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asinh.m"),
                "resolved", 133);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840318U), "fileTimeLo", 133);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 133);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 133);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 133);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asinh.m"),
                "context", 134);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_log1p"), "name", 134);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 134);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log1p.m"),
                "resolved", 134);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840328U), "fileTimeLo", 134);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 134);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 134);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 134);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log1p.m"),
                "context", 135);
  emlrtAddField(*info, emlrt_marshallOut("abs"), "name", 135);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 135);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved", 135);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731852U), "fileTimeLo", 135);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 135);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 135);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 135);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log1p.m"),
                "context", 136);
  emlrtAddField(*info, emlrt_marshallOut("eps"), "name", 136);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 136);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved", 136);
  emlrtAddField(*info, b_emlrt_marshallOut(1326749596U), "fileTimeLo", 136);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 136);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 136);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 136);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context", 137);
  emlrtAddField(*info, emlrt_marshallOut("eml_is_float_class"), "name", 137);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 137);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_is_float_class.m"),
                "resolved", 137);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840382U), "fileTimeLo", 137);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 137);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 137);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 137);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "context", 138);
  emlrtAddField(*info, emlrt_marshallOut("eml_eps"), "name", 138);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 138);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "resolved", 138);
  emlrtAddField(*info, b_emlrt_marshallOut(1326749596U), "fileTimeLo", 138);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 138);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 138);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 138);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_eps.m"), "context", 139);
  emlrtAddField(*info, emlrt_marshallOut("eml_float_model"), "name", 139);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 139);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                "resolved", 139);
  emlrtAddField(*info, b_emlrt_marshallOut(1326749596U), "fileTimeLo", 139);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 139);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 139);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 139);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log1p.m"),
                "context", 140);
  emlrtAddField(*info, emlrt_marshallOut("isfinite"), "name", 140);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 140);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                140);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731856U), "fileTimeLo", 140);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 140);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 140);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 140);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                141);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 141);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 141);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 141);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 141);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 141);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 141);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 141);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                142);
  emlrtAddField(*info, emlrt_marshallOut("isinf"), "name", 142);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 142);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isinf.m"), "resolved", 142);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731856U), "fileTimeLo", 142);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 142);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 142);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 142);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "context",
                143);
  emlrtAddField(*info, emlrt_marshallOut("isnan"), "name", 143);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 143);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isnan.m"), "resolved", 143);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731858U), "fileTimeLo", 143);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 143);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 143);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 143);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log1p.m"),
                "context", 144);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_log"), "name", 144);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 144);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log.m"),
                "resolved", 144);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840328U), "fileTimeLo", 144);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 144);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 144);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 144);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log.m"),
                "context", 145);
  emlrtAddField(*info, emlrt_marshallOut("realmax"), "name", 145);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 145);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmax.m"), "resolved",
                145);
  emlrtAddField(*info, b_emlrt_marshallOut(1307672842U), "fileTimeLo", 145);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 145);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 145);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 145);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_log.m"),
                "context", 146);
  emlrtAddField(*info, emlrt_marshallOut("mrdivide"), "name", 146);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 146);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved", 146);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829248U), "fileTimeLo", 146);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 146);
  emlrtAddField(*info, b_emlrt_marshallOut(1370031486U), "mFileTimeLo", 146);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 146);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m"),
                "context", 147);
  emlrtAddField(*info, emlrt_marshallOut("mrdivide"), "name", 147);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 147);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved", 147);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829248U), "fileTimeLo", 147);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 147);
  emlrtAddField(*info, b_emlrt_marshallOut(1370031486U), "mFileTimeLo", 147);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 147);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m"),
                "context", 148);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_abs"), "name", 148);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 148);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                "resolved", 148);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840312U), "fileTimeLo", 148);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 148);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 148);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 148);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_acos.m"),
                "context", 149);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_atan2"), "name", 149);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 149);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan2.m"),
                "resolved", 149);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840320U), "fileTimeLo", 149);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 149);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 149);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 149);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 150);
  emlrtAddField(*info, emlrt_marshallOut("mpower"), "name", 150);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 150);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mpower.m"), "resolved", 150);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731878U), "fileTimeLo", 150);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 150);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 150);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 150);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 151);
  emlrtAddField(*info, emlrt_marshallOut("sqrt"), "name", 151);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 151);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "resolved", 151);
  emlrtAddField(*info, b_emlrt_marshallOut(1343851986U), "fileTimeLo", 151);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 151);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 151);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 151);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context", 152);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_sqrt"), "name", 152);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 152);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m"),
                "resolved", 152);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840338U), "fileTimeLo", 152);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 152);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 152);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 152);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_fldiv"),
                "context", 153);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 153);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 153);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 153);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 153);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 153);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 153);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 153);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_fldiv"),
                "context", 154);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalexpAlloc"), "name",
                154);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 154);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalexpAlloc.p"),
                "resolved", 154);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 154);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 154);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 154);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 154);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p!eml_fldiv"),
                "context", 155);
  emlrtAddField(*info, emlrt_marshallOut("abs"), "name", 155);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 155);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved", 155);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731852U), "fileTimeLo", 155);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 155);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 155);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 155);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m!at"
    "ans"), "context", 156);
  emlrtAddField(*info, emlrt_marshallOut("mrdivide"), "name", 156);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 156);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved", 156);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829248U), "fileTimeLo", 156);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 156);
  emlrtAddField(*info, b_emlrt_marshallOut(1370031486U), "mFileTimeLo", 156);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 156);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m!at"
    "ans"), "context", 157);
  emlrtAddField(*info, emlrt_marshallOut("atan"), "name", 157);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 157);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m"), "resolved", 157);
  emlrtAddField(*info, b_emlrt_marshallOut(1395346496U), "fileTimeLo", 157);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 157);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 157);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 157);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/atan.m"), "context", 158);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_atan"), "name", 158);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 158);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_atan.m"),
                "resolved", 158);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840318U), "fileTimeLo", 158);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 158);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 158);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 158);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 159);
  emlrtAddField(*info, emlrt_marshallOut("asin"), "name", 159);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 159);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "resolved", 159);
  emlrtAddField(*info, b_emlrt_marshallOut(1395346494U), "fileTimeLo", 159);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 159);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 159);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 159);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "context", 160);
  emlrtAddField(*info, emlrt_marshallOut("eml_error"), "name", 160);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 160);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                160);
  emlrtAddField(*info, b_emlrt_marshallOut(1343851958U), "fileTimeLo", 160);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 160);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 160);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 160);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/asin.m"), "context", 161);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_asin"), "name", 161);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 161);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_asin.m"),
                "resolved", 161);
  emlrtAddField(*info, b_emlrt_marshallOut(1343851976U), "fileTimeLo", 161);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 161);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 161);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 161);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m"), "context", 162);
  emlrtAddField(*info, emlrt_marshallOut("eml_error"), "name", 162);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 162);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                162);
  emlrtAddField(*info, b_emlrt_marshallOut(1343851958U), "fileTimeLo", 162);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 162);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 162);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 162);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 163);
  emlrtAddField(*info, emlrt_marshallOut("min"), "name", 163);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 163);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved", 163);
  emlrtAddField(*info, b_emlrt_marshallOut(1311276918U), "fileTimeLo", 163);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 163);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 163);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 163);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 164);
  emlrtAddField(*info, emlrt_marshallOut("mldivide"), "name", 164);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 164);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "resolved", 164);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829248U), "fileTimeLo", 164);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 164);
  emlrtAddField(*info, b_emlrt_marshallOut(1319751566U), "mFileTimeLo", 164);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 164);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mldivide.p"), "context", 165);
  emlrtAddField(*info, emlrt_marshallOut("eml_lusolve"), "name", 165);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 165);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m"), "resolved",
                165);
  emlrtAddField(*info, b_emlrt_marshallOut(1370031486U), "fileTimeLo", 165);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 165);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 165);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 165);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                "context", 166);
  emlrtAddField(*info, emlrt_marshallOut("eml_xgetrf"), "name", 166);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 166);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                "resolved", 166);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840406U), "fileTimeLo", 166);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 166);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 166);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 166);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/eml_xgetrf.m"),
                "context", 167);
  emlrtAddField(*info, emlrt_marshallOut("eml_lapack_xgetrf"), "name", 167);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 167);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                "resolved", 167);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840410U), "fileTimeLo", 167);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 167);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 167);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 167);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/internal/eml_lapack_xgetrf.m"),
                "context", 168);
  emlrtAddField(*info, emlrt_marshallOut("eml_matlab_zgetrf"), "name", 168);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 168);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "resolved", 168);
  emlrtAddField(*info, b_emlrt_marshallOut(1302710594U), "fileTimeLo", 168);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 168);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 168);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 168);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 169);
  emlrtAddField(*info, emlrt_marshallOut("realmin"), "name", 169);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 169);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "resolved",
                169);
  emlrtAddField(*info, b_emlrt_marshallOut(1307672842U), "fileTimeLo", 169);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 169);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 169);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 169);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/realmin.m"), "context", 170);
  emlrtAddField(*info, emlrt_marshallOut("eml_realmin"), "name", 170);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 170);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "resolved",
                170);
  emlrtAddField(*info, b_emlrt_marshallOut(1307672844U), "fileTimeLo", 170);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 170);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 170);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 170);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_realmin.m"), "context",
                171);
  emlrtAddField(*info, emlrt_marshallOut("eml_float_model"), "name", 171);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 171);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                "resolved", 171);
  emlrtAddField(*info, b_emlrt_marshallOut(1326749596U), "fileTimeLo", 171);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 171);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 171);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 171);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 172);
  emlrtAddField(*info, emlrt_marshallOut("eps"), "name", 172);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 172);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/eps.m"), "resolved", 172);
  emlrtAddField(*info, b_emlrt_marshallOut(1326749596U), "fileTimeLo", 172);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 172);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 172);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 172);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 173);
  emlrtAddField(*info, emlrt_marshallOut("min"), "name", 173);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 173);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved", 173);
  emlrtAddField(*info, b_emlrt_marshallOut(1311276918U), "fileTimeLo", 173);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 173);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 173);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 173);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 174);
  emlrtAddField(*info, emlrt_marshallOut("colon"), "name", 174);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 174);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved", 174);
  emlrtAddField(*info, b_emlrt_marshallOut(1378317588U), "fileTimeLo", 174);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 174);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 174);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 174);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context", 175);
  emlrtAddField(*info, emlrt_marshallOut("colon"), "name", 175);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 175);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "resolved", 175);
  emlrtAddField(*info, b_emlrt_marshallOut(1378317588U), "fileTimeLo", 175);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 175);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 175);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 175);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context", 176);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 176);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 176);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 176);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 176);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 176);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 176);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 176);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context", 177);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 177);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 177);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 177);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 177);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 177);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 177);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 177);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m"), "context", 178);
  emlrtAddField(*info, emlrt_marshallOut("floor"), "name", 178);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 178);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved", 178);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731854U), "fileTimeLo", 178);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 178);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 178);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 178);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                "context", 179);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 179);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 179);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 179);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 179);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 179);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 179);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 179);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!checkrange"),
                "context", 180);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 180);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 180);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 180);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 180);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 180);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 180);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 180);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                "context", 181);
  emlrtAddField(*info, emlrt_marshallOut("intmin"), "name", 181);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 181);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmin.m"), "resolved", 181);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 181);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 181);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 181);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 181);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                "context", 182);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 182);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 182);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 182);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 182);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 182);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 182);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 182);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_integer_colon_dispatcher"),
                "context", 183);
  emlrtAddField(*info, emlrt_marshallOut("eml_isa_uint"), "name", 183);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 183);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                183);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 183);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 183);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 183);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 183);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "context",
                184);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isaUint"), "name", 184);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 184);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/isaUint.p"),
                "resolved", 184);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 184);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 184);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 184);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 184);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                "context", 185);
  emlrtAddField(*info, emlrt_marshallOut("eml_unsigned_class"), "name", 185);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 185);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                "resolved", 185);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 185);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 185);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 185);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 185);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_unsigned_class.m"),
                "context", 186);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.unsignedClass"), "name",
                186);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 186);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                "resolved", 186);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 186);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 186);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 186);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 186);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                "context", 187);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 187);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 187);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 187);
  emlrtAddField(*info, b_emlrt_marshallOut(1393352458U), "fileTimeLo", 187);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 187);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 187);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 187);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/unsignedClass.p"),
                "context", 188);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 188);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 188);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 188);
  emlrtAddField(*info, b_emlrt_marshallOut(1323192178U), "fileTimeLo", 188);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 188);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 188);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 188);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                "context", 189);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 189);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 189);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 189);
  emlrtAddField(*info, b_emlrt_marshallOut(1323192178U), "fileTimeLo", 189);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 189);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 189);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 189);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                "context", 190);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 190);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 190);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 190);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 190);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 190);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 190);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 190);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                "context", 191);
  emlrtAddField(*info, emlrt_marshallOut("eml_isa_uint"), "name", 191);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 191);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_isa_uint.m"), "resolved",
                191);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 191);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 191);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 191);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 191);
}

static void d_info_helper(const mxArray **info)
{
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!integer_colon_length_nonnegd"),
                "context", 192);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_plus"), "name", 192);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 192);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                "resolved", 192);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604016U), "fileTimeLo", 192);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 192);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 192);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 192);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                193);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexPlus"), "name",
                193);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 193);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                "resolved", 193);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604760U), "fileTimeLo", 193);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 193);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 193);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 193);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/colon.m!eml_signed_integer_colon"),
                "context", 194);
  emlrtAddField(*info, emlrt_marshallOut("eml_int_forloop_overflow_check"),
                "name", 194);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 194);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                "resolved", 194);
  emlrtAddField(*info, b_emlrt_marshallOut(1397279022U), "fileTimeLo", 194);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 194);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 194);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 194);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 195);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 195);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 195);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 195);
  emlrtAddField(*info, b_emlrt_marshallOut(1323192178U), "fileTimeLo", 195);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 195);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 195);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 195);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 196);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_plus"), "name", 196);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 196);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                "resolved", 196);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604016U), "fileTimeLo", 196);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 196);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 196);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 196);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 197);
  emlrtAddField(*info, emlrt_marshallOut("eml_int_forloop_overflow_check"),
                "name", 197);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 197);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                "resolved", 197);
  emlrtAddField(*info, b_emlrt_marshallOut(1397279022U), "fileTimeLo", 197);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 197);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 197);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 197);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 198);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_minus"), "name", 198);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 198);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                "resolved", 198);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604016U), "fileTimeLo", 198);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 198);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 198);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 198);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                "context", 199);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexMinus"), "name",
                199);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 199);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                "resolved", 199);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604760U), "fileTimeLo", 199);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 199);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 199);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 199);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 200);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_minus"), "name", 200);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 200);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                "resolved", 200);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604016U), "fileTimeLo", 200);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 200);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 200);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 200);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_minus.m"),
                "context", 201);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexMinus"), "name",
                201);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 201);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                "resolved", 201);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604760U), "fileTimeLo", 201);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 201);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 201);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 201);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 202);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_times"), "name", 202);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 202);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                "resolved", 202);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604016U), "fileTimeLo", 202);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 202);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 202);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 202);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_times.m"),
                "context", 203);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexTimes"), "name",
                203);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 203);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexTimes.m"),
                "resolved", 203);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604760U), "fileTimeLo", 203);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 203);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 203);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 203);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 204);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_plus"), "name", 204);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 204);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"),
                "resolved", 204);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604016U), "fileTimeLo", 204);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 204);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 204);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 204);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_plus.m"), "context",
                205);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexPlus"), "name",
                205);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 205);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                "resolved", 205);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604760U), "fileTimeLo", 205);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 205);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 205);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 205);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 206);
  emlrtAddField(*info, emlrt_marshallOut("eml_ixamax"), "name", 206);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 206);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                "resolved", 206);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 206);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 206);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 206);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 206);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                "context", 207);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.inline"), "name",
                207);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 207);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                "resolved", 207);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 207);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 207);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 207);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 207);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_ixamax.m"),
                "context", 208);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.ixamax"), "name",
                208);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 208);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                "resolved", 208);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 208);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 208);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 208);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 208);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                "context", 209);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.use_refblas"),
                "name", 209);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 209);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                "resolved", 209);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 209);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 209);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 209);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 209);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                "context", 210);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.threshold"),
                "name", 210);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 210);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                "resolved", 210);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 210);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 210);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 210);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 210);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                "context", 211);
  emlrtAddField(*info, emlrt_marshallOut("eml_switch_helper"), "name", 211);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 211);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_switch_helper.m"),
                "resolved", 211);
  emlrtAddField(*info, b_emlrt_marshallOut(1393352458U), "fileTimeLo", 211);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 211);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 211);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 211);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p!below_threshold"),
                "context", 212);
  emlrtAddField(*info, emlrt_marshallOut("length"), "name", 212);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 212);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved", 212);
  emlrtAddField(*info, b_emlrt_marshallOut(1303167806U), "fileTimeLo", 212);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 212);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 212);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 212);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m!intlength"),
                "context", 213);
  emlrtAddField(*info, emlrt_marshallOut("eml_index_class"), "name", 213);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 213);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_index_class.m"),
                "resolved", 213);
  emlrtAddField(*info, b_emlrt_marshallOut(1323192178U), "fileTimeLo", 213);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 213);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 213);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 213);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/ixamax.p"),
                "context", 214);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.refblas.ixamax"),
                "name", 214);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 214);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                "resolved", 214);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 214);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 214);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 214);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 214);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                "context", 215);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.refblas.xcabs1"),
                "name", 215);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 215);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                "resolved", 215);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 215);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 215);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 215);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 215);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xcabs1.p"),
                "context", 216);
  emlrtAddField(*info, emlrt_marshallOut("abs"), "name", 216);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 216);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved", 216);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731852U), "fileTimeLo", 216);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 216);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 216);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 216);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                "context", 217);
  emlrtAddField(*info, emlrt_marshallOut("eml_int_forloop_overflow_check"),
                "name", 217);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 217);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                "resolved", 217);
  emlrtAddField(*info, b_emlrt_marshallOut(1397279022U), "fileTimeLo", 217);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 217);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 217);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 217);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/ixamax.p"),
                "context", 218);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexPlus"), "name",
                218);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 218);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                "resolved", 218);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604760U), "fileTimeLo", 218);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 218);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 218);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 218);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 219);
  emlrtAddField(*info, emlrt_marshallOut("eml_xswap"), "name", 219);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 219);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"),
                "resolved", 219);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002292U), "fileTimeLo", 219);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 219);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 219);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 219);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                220);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.inline"), "name",
                220);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 220);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                "resolved", 220);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 220);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 220);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 220);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 220);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xswap.m"), "context",
                221);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.xswap"), "name",
                221);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 221);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                "resolved", 221);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 221);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 221);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 221);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 221);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                "context", 222);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.use_refblas"),
                "name", 222);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 222);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                "resolved", 222);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 222);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 222);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 222);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 222);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p!below_threshold"),
                "context", 223);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.threshold"),
                "name", 223);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 223);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                "resolved", 223);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 223);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 223);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 223);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 223);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xswap.p"),
                "context", 224);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.refblas.xswap"), "name",
                224);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 224);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                "resolved", 224);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 224);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 224);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 224);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 224);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                "context", 225);
  emlrtAddField(*info, emlrt_marshallOut("abs"), "name", 225);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 225);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved", 225);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731852U), "fileTimeLo", 225);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 225);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 225);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 225);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context", 226);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 226);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 226);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 226);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 226);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 226);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 226);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 226);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "context", 227);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_abs"), "name", 227);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 227);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_abs.m"),
                "resolved", 227);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840312U), "fileTimeLo", 227);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 227);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 227);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 227);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                "context", 228);
  emlrtAddField(*info, emlrt_marshallOut("eml_int_forloop_overflow_check"),
                "name", 228);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 228);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                "resolved", 228);
  emlrtAddField(*info, b_emlrt_marshallOut(1397279022U), "fileTimeLo", 228);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 228);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 228);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 228);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xswap.p"),
                "context", 229);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexPlus"), "name",
                229);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 229);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                "resolved", 229);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604760U), "fileTimeLo", 229);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 229);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 229);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 229);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 230);
  emlrtAddField(*info, emlrt_marshallOut("eml_div"), "name", 230);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 230);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved", 230);
  emlrtAddField(*info, b_emlrt_marshallOut(1386445552U), "fileTimeLo", 230);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 230);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 230);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 230);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/lapack/matlab/eml_matlab_zgetrf.m"),
                "context", 231);
  emlrtAddField(*info, emlrt_marshallOut("eml_xgeru"), "name", 231);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 231);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"),
                "resolved", 231);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002290U), "fileTimeLo", 231);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 231);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 231);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 231);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                232);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.inline"), "name",
                232);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 232);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                "resolved", 232);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 232);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 232);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 232);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 232);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xgeru.m"), "context",
                233);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.xgeru"), "name",
                233);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 233);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                "resolved", 233);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 233);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 233);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 233);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 233);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xgeru.p"),
                "context", 234);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.xger"), "name",
                234);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 234);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                "resolved", 234);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 234);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 234);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 234);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 234);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                "context", 235);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.use_refblas"),
                "name", 235);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 235);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                "resolved", 235);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 235);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 235);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 235);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 235);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                "context", 236);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.threshold"),
                "name", 236);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 236);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                "resolved", 236);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 236);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 236);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 236);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 236);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                "context", 237);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.int"), "name", 237);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 237);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/int.p"),
                "resolved", 237);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 237);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 237);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 237);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 237);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                "context", 238);
  emlrtAddField(*info, emlrt_marshallOut("intmax"), "name", 238);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 238);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/intmax.m"), "resolved", 238);
  emlrtAddField(*info, b_emlrt_marshallOut(1362283482U), "fileTimeLo", 238);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 238);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 238);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 238);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p!below_threshold"),
                "context", 239);
  emlrtAddField(*info, emlrt_marshallOut("min"), "name", 239);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 239);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved", 239);
  emlrtAddField(*info, b_emlrt_marshallOut(1311276918U), "fileTimeLo", 239);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 239);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 239);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 239);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xger.p"),
                "context", 240);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.refblas.xger"), "name",
                240);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 240);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                "resolved", 240);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 240);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 240);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 240);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 240);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xger.p"),
                "context", 241);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.refblas.xgerx"), "name",
                241);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 241);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                "resolved", 241);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 241);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 241);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 241);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 241);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                "context", 242);
  emlrtAddField(*info, emlrt_marshallOut("abs"), "name", 242);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 242);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/abs.m"), "resolved", 242);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731852U), "fileTimeLo", 242);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 242);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 242);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 242);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                "context", 243);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexMinus"), "name",
                243);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 243);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexMinus.m"),
                "resolved", 243);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604760U), "fileTimeLo", 243);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 243);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 243);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 243);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                "context", 244);
  emlrtAddField(*info, emlrt_marshallOut("eml_int_forloop_overflow_check"),
                "name", 244);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 244);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                "resolved", 244);
  emlrtAddField(*info, b_emlrt_marshallOut(1397279022U), "fileTimeLo", 244);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 244);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 244);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 244);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                "context", 245);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexPlus"), "name",
                245);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 245);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                "resolved", 245);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604760U), "fileTimeLo", 245);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 245);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 245);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 245);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xgerx.p"),
                "context", 246);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexPlus"), "name",
                246);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.indexInt"),
                "dominantType", 246);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/indexPlus.m"),
                "resolved", 246);
  emlrtAddField(*info, b_emlrt_marshallOut(1372604760U), "fileTimeLo", 246);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 246);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 246);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 246);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                "context", 247);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 247);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 247);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                247);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 247);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 247);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 247);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 247);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                "context", 248);
  emlrtAddField(*info, emlrt_marshallOut("eml_int_forloop_overflow_check"),
                "name", 248);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 248);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                "resolved", 248);
  emlrtAddField(*info, b_emlrt_marshallOut(1397279022U), "fileTimeLo", 248);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 248);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 248);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 248);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_lusolve.m!lusolveNxN"),
                "context", 249);
  emlrtAddField(*info, emlrt_marshallOut("eml_xtrsm"), "name", 249);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 249);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"),
                "resolved", 249);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002292U), "fileTimeLo", 249);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 249);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 249);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 249);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                250);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.inline"), "name",
                250);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 250);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/inline.p"),
                "resolved", 250);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 250);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 250);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 250);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 250);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/blas/eml_xtrsm.m"), "context",
                251);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.xtrsm"), "name",
                251);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 251);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                "resolved", 251);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 251);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 251);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 251);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 251);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                "context", 252);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.use_refblas"),
                "name", 252);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 252);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/use_refblas.p"),
                "resolved", 252);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 252);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 252);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 252);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 252);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p!below_threshold"),
                "context", 253);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.blas.threshold"),
                "name", 253);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 253);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/threshold.p"),
                "resolved", 253);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 253);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 253);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 253);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 253);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                "context", 254);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 254);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 254);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 254);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 254);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 254);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 254);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 254);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+blas/xtrsm.p"),
                "context", 255);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.refblas.xtrsm"), "name",
                255);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 255);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                "resolved", 255);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829372U), "fileTimeLo", 255);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 255);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 255);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 255);
}

static void e_info_helper(const mxArray **info)
{
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                "context", 256);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 256);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 256);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 256);
  emlrtAddField(*info, b_emlrt_marshallOut(1389739374U), "fileTimeLo", 256);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 256);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 256);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 256);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                "context", 257);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.scalarEg"), "name", 257);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 257);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/scalarEg.p"),
                "resolved", 257);
  emlrtAddField(*info, b_emlrt_marshallOut(1410829370U), "fileTimeLo", 257);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 257);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 257);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 257);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                "context", 258);
  emlrtAddField(*info, emlrt_marshallOut("eml_int_forloop_overflow_check"),
                "name", 258);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 258);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                "resolved", 258);
  emlrtAddField(*info, b_emlrt_marshallOut(1397279022U), "fileTimeLo", 258);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 258);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 258);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 258);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/+refblas/xtrsm.p"),
                "context", 259);
  emlrtAddField(*info, emlrt_marshallOut("rdivide"), "name", 259);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 259);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved", 259);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731880U), "fileTimeLo", 259);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 259);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 259);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 259);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/MikhailController_MARLO_Steeringv2.m"),
                "context", 260);
  emlrtAddField(*info, emlrt_marshallOut("bezierval"), "name", 260);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 260);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/FeedbackControl/DDAcontroller/bezierval.m"),
                "resolved", 260);
  emlrtAddField(*info, b_emlrt_marshallOut(1428339786U), "fileTimeLo", 260);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 260);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 260);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 260);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/FeedbackControl/DDAcontroller/bezierval.m"),
                "context", 261);
  emlrtAddField(*info, emlrt_marshallOut("length"), "name", 261);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 261);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/length.m"), "resolved", 261);
  emlrtAddField(*info, b_emlrt_marshallOut(1303167806U), "fileTimeLo", 261);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 261);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 261);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 261);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/FeedbackControl/DDAcontroller/bezierval.m"),
                "context", 262);
  emlrtAddField(*info, emlrt_marshallOut("nchoosek"), "name", 262);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 262);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m"), "resolved",
                262);
  emlrtAddField(*info, b_emlrt_marshallOut(1368204634U), "fileTimeLo", 262);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 262);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 262);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 262);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m"), "context",
                263);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.is64BitInteger"),
                "name", 263);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 263);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/is64BitInteger.m"),
                "resolved", 263);
  emlrtAddField(*info, b_emlrt_marshallOut(1368205894U), "fileTimeLo", 263);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 263);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 263);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 263);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m"), "context",
                264);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 264);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 264);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 264);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 264);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 264);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 264);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 264);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m"), "context",
                265);
  emlrtAddField(*info, emlrt_marshallOut("floor"), "name", 265);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 265);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/floor.m"), "resolved", 265);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731854U), "fileTimeLo", 265);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 265);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 265);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 265);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m"), "context",
                266);
  emlrtAddField(*info, emlrt_marshallOut("eml_error"), "name", 266);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 266);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                266);
  emlrtAddField(*info, b_emlrt_marshallOut(1343851958U), "fileTimeLo", 266);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 266);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 266);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 266);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m"), "context",
                267);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 267);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 267);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                267);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 267);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 267);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 267);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 267);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m"), "context",
                268);
  emlrtAddField(*info, emlrt_marshallOut("eml_guarded_nan"), "name", 268);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 268);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                "resolved", 268);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840376U), "fileTimeLo", 268);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 268);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 268);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 268);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m"), "context",
                269);
  emlrtAddField(*info, emlrt_marshallOut("flintmax"), "name", 269);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 269);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m"), "resolved",
                269);
  emlrtAddField(*info, b_emlrt_marshallOut(1348213516U), "fileTimeLo", 269);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 269);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 269);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 269);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m"), "context",
                270);
  emlrtAddField(*info, emlrt_marshallOut("eml_float_model"), "name", 270);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 270);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_float_model.m"),
                "resolved", 270);
  emlrtAddField(*info, b_emlrt_marshallOut(1326749596U), "fileTimeLo", 270);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 270);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 270);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 270);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m"), "context",
                271);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.assert"), "name", 271);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 271);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                "resolved", 271);
  emlrtAddField(*info, b_emlrt_marshallOut(1389739374U), "fileTimeLo", 271);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 271);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 271);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 271);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m!nCk"),
                "context", 272);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_eg"), "name", 272);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 272);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalar_eg.m"), "resolved",
                272);
  emlrtAddField(*info, b_emlrt_marshallOut(1376002288U), "fileTimeLo", 272);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 272);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 272);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 272);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m!nCk"),
                "context", 273);
  emlrtAddField(*info, emlrt_marshallOut("isfinite"), "name", 273);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 273);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/isfinite.m"), "resolved",
                273);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731856U), "fileTimeLo", 273);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 273);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 273);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 273);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m!nCk"),
                "context", 274);
  emlrtAddField(*info, emlrt_marshallOut("eml_guarded_inf"), "name", 274);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 274);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_inf.m"),
                "resolved", 274);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840376U), "fileTimeLo", 274);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 274);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 274);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 274);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m!nCk"),
                "context", 275);
  emlrtAddField(*info, emlrt_marshallOut("round"), "name", 275);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 275);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "resolved", 275);
  emlrtAddField(*info, b_emlrt_marshallOut(1363731854U), "fileTimeLo", 275);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 275);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 275);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 275);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context", 276);
  emlrtAddField(*info, emlrt_marshallOut("coder.internal.isBuiltInNumeric"),
                "name", 276);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 276);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                "resolved", 276);
  emlrtAddField(*info, b_emlrt_marshallOut(1395949856U), "fileTimeLo", 276);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 276);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 276);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 276);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/round.m"), "context", 277);
  emlrtAddField(*info, emlrt_marshallOut("eml_scalar_round"), "name", 277);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 277);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_round.m"),
                "resolved", 277);
  emlrtAddField(*info, b_emlrt_marshallOut(1307672838U), "fileTimeLo", 277);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 277);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 277);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 277);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m!nCk"),
                "context", 278);
  emlrtAddField(*info, emlrt_marshallOut("eml_guarded_nan"), "name", 278);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 278);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_guarded_nan.m"),
                "resolved", 278);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840376U), "fileTimeLo", 278);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 278);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 278);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 278);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m!nCk"),
                "context", 279);
  emlrtAddField(*info, emlrt_marshallOut("flintmax"), "name", 279);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 279);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elmat/flintmax.m"), "resolved",
                279);
  emlrtAddField(*info, b_emlrt_marshallOut(1348213516U), "fileTimeLo", 279);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 279);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 279);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 279);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/specfun/nchoosek.m!nCk"),
                "context", 280);
  emlrtAddField(*info, emlrt_marshallOut("eml_warning"), "name", 280);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 280);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_warning.m"), "resolved",
                280);
  emlrtAddField(*info, b_emlrt_marshallOut(1286840402U), "fileTimeLo", 280);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 280);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 280);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 280);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/FeedbackControl/DDAcontroller/bezierval.m"),
                "context", 281);
  emlrtAddField(*info, emlrt_marshallOut("power"), "name", 281);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 281);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m"), "resolved", 281);
  emlrtAddField(*info, b_emlrt_marshallOut(1395346506U), "fileTimeLo", 281);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 281);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 281);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 281);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/power.m!fltpower"), "context",
                282);
  emlrtAddField(*info, emlrt_marshallOut("eml_error"), "name", 282);
  emlrtAddField(*info, emlrt_marshallOut("char"), "dominantType", 282);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m"), "resolved",
                282);
  emlrtAddField(*info, b_emlrt_marshallOut(1343851958U), "fileTimeLo", 282);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 282);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 282);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 282);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/FeedbackControl/DDAcontroller/bezierval.m"),
                "context", 283);
  emlrtAddField(*info, emlrt_marshallOut("eml_mtimes_helper"), "name", 283);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 283);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                "resolved", 283);
  emlrtAddField(*info, b_emlrt_marshallOut(1383898894U), "fileTimeLo", 283);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 283);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 283);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 283);
  emlrtAddField(*info, emlrt_marshallOut(
    "[C]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/Controller_MARLO.m"), "context", 284);
  emlrtAddField(*info, emlrt_marshallOut("eml_mtimes_helper"), "name", 284);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 284);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/eml_mtimes_helper.m"),
                "resolved", 284);
  emlrtAddField(*info, b_emlrt_marshallOut(1383898894U), "fileTimeLo", 284);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 284);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 284);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 284);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/Controller_MARLO.m!clamp"), "context", 285);
  emlrtAddField(*info, emlrt_marshallOut("min"), "name", 285);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 285);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/min.m"), "resolved", 285);
  emlrtAddField(*info, b_emlrt_marshallOut(1311276918U), "fileTimeLo", 285);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 285);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 285);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 285);
  emlrtAddField(*info, emlrt_marshallOut(
    "[E]C:/Users/xingye/Documents/SVN/MARLO_Controllers/Walking/InPlace/Rocking/OSUcontroller/atrias-matlab-master/atrias-matlab-mast"
    "er/tools/Controller_MARLO.m!clamp"), "context", 286);
  emlrtAddField(*info, emlrt_marshallOut("max"), "name", 286);
  emlrtAddField(*info, emlrt_marshallOut("double"), "dominantType", 286);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/datafun/max.m"), "resolved", 286);
  emlrtAddField(*info, b_emlrt_marshallOut(1311276916U), "fileTimeLo", 286);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 286);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 286);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 286);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_min_or_max.m!eml_bin_extremum"),
                "context", 287);
  emlrtAddField(*info, emlrt_marshallOut("eml_int_forloop_overflow_check"),
                "name", 287);
  emlrtAddField(*info, emlrt_marshallOut(""), "dominantType", 287);
  emlrtAddField(*info, emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_int_forloop_overflow_check.m"),
                "resolved", 287);
  emlrtAddField(*info, b_emlrt_marshallOut(1397279022U), "fileTimeLo", 287);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "fileTimeHi", 287);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeLo", 287);
  emlrtAddField(*info, b_emlrt_marshallOut(0U), "mFileTimeHi", 287);
}

static const mxArray *mw__internal__autoInference__fcn(void)
{
  const mxArray *infoCache;
  sfOd2wElE6un66xmZCZog7F Ports_data[7];
  sfOd2wElE6un66xmZCZog7F_size Ports_elems_sizes[7];
  int32_T i10;
  static int8_T iv18[4] = { 1, 2, 1, 1 };

  static int8_T iv19[4] = { 6, 2, 1, 6 };

  static int8_T iv20[4] = { 9, 2, 1, 9 };

  static int8_T iv21[4] = { 6, 2, 6, 1 };

  char_T t2_objTypeName[36];
  static char_T cv30[36] = { 'M', 'i', 'k', 'h', 'a', 'i', 'l', 'C', 'o', 'n',
    't', 'r', 'o', 'l', 'l', 'e', 'r', '_', 'M', 'A', 'R', 'L', 'O', '_', 'S',
    't', 'e', 'e', 'r', 'i', 'n', 'g', 'v', '2', '_', '2' };

  char_T t2_sysObjChksum[22];
  static char_T cv31[22] = { 'I', 'C', 'u', 'E', 'L', 'q', 'C', 'p', 'h', '5',
    '1', 'a', 'w', 'D', 'd', 'M', '2', 'j', 'i', 'a', 'u', 'C' };

  uint32_T t1_cgxeChksum[4];
  static uint32_T uv0[4] = { 2155958618U, 3369238703U, 191814340U, 2360837547U };

  static uint32_T t3_chksum[4] = { 868722322U, 4231782148U, 5994823U,
    3390936957U };

  s7UBIGHSehQY1gCsIQWwr5C checksums[4];
  static uint32_T t4_chksum[4] = { 442631090U, 1163151205U, 2816277734U,
    3043477015U };

  static uint32_T t5_chksum[4] = { 3338633494U, 2949072608U, 3269904792U,
    184460082U };

  static int32_T t6_chksum[4] = { 596326832, 1037680396, 2124121065, 1539362939
  };

  uint32_T b_t5_chksum[4];
  static uint32_T t7_codeGenChksum[4] = { 907274058U, 3220786148U, 779473529U,
    2769831971U };

  char_T u_slVer[3];
  static char_T cv32[3] = { '8', '.', '4' };

  const mxArray *y;
  const mxArray *b_y;
  const mxArray *c_y;
  sfOd2wElE6un66xmZCZog7F_size u_elems_sizes[7];
  sfOd2wElE6un66xmZCZog7F u_data[7];
  const mxArray *d_y;
  int32_T iv22[2];
  const sfOd2wElE6un66xmZCZog7F_size *tmp_elems_sizes;
  const sfOd2wElE6un66xmZCZog7F *tmp_data;
  real_T u;
  const mxArray *e_y;
  const mxArray *m9;
  int32_T u_sizes[2];
  int32_T i11;
  int32_T i;
  real_T b_u[4];
  int32_T tmp_sizes;
  real_T b_u_data[4];
  const mxArray *f_y;
  real_T *pData;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  static const int32_T iv23[2] = { 1, 36 };

  const mxArray *l_y;
  const mxArray *m_y;
  const mxArray *n_y;
  static const int32_T iv24[2] = { 1, 22 };

  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *r_y;
  const mxArray *s_y;
  int32_T b_u_sizes[2];
  const mxArray *t_y;
  const mxArray *u_y;
  static const int32_T iv25[2] = { 1, 4 };

  const mxArray *v_y;
  s7UBIGHSehQY1gCsIQWwr5C c_u[4];
  const mxArray *w_y;
  const s7UBIGHSehQY1gCsIQWwr5C *r0;
  const mxArray *x_y;
  static const int32_T iv26[2] = { 1, 4 };

  const mxArray *y_y;
  const mxArray *ab_y;
  static const int32_T iv27[2] = { 1, 4 };

  const mxArray *bb_y;
  static const int32_T iv28[2] = { 1, 3 };

  infoCache = NULL;
  Ports_data[0].dimModes = 0.0;
  Ports_elems_sizes[0].dims[0] = 1;
  Ports_elems_sizes[0].dims[1] = 4;
  for (i10 = 0; i10 < 4; i10++) {
    Ports_data[0].dims[i10] = (real_T)iv18[i10];
  }

  Ports_data[0].dType = 8.0;
  Ports_data[0].complexity = 0.0;
  Ports_data[0].outputBuiltInDTEqUsed = 0.0;
  Ports_data[1].dimModes = 0.0;
  Ports_elems_sizes[1].dims[0] = 1;
  Ports_elems_sizes[1].dims[1] = 4;
  for (i10 = 0; i10 < 4; i10++) {
    Ports_data[1].dims[i10] = (real_T)iv19[i10];
  }

  Ports_data[1].dType = 0.0;
  Ports_data[1].complexity = 0.0;
  Ports_data[1].outputBuiltInDTEqUsed = 0.0;
  Ports_data[2].dimModes = 0.0;
  Ports_elems_sizes[2].dims[0] = 1;
  Ports_elems_sizes[2].dims[1] = 4;
  for (i10 = 0; i10 < 4; i10++) {
    Ports_data[2].dims[i10] = (real_T)iv20[i10];
  }

  Ports_data[2].dType = 0.0;
  Ports_data[2].complexity = 0.0;
  Ports_data[2].outputBuiltInDTEqUsed = 0.0;
  Ports_data[3].dimModes = 0.0;
  Ports_elems_sizes[3].dims[0] = 1;
  Ports_elems_sizes[3].dims[1] = 4;
  for (i10 = 0; i10 < 4; i10++) {
    Ports_data[3].dims[i10] = (real_T)iv18[i10];
  }

  Ports_data[3].dType = 0.0;
  Ports_data[3].complexity = 0.0;
  Ports_data[3].outputBuiltInDTEqUsed = 0.0;
  Ports_data[4].dimModes = 0.0;
  Ports_elems_sizes[4].dims[0] = 1;
  Ports_elems_sizes[4].dims[1] = 4;
  for (i10 = 0; i10 < 4; i10++) {
    Ports_data[4].dims[i10] = (real_T)iv21[i10];
  }

  Ports_data[4].dType = 0.0;
  Ports_data[4].complexity = 0.0;
  Ports_data[4].outputBuiltInDTEqUsed = 0.0;
  Ports_data[5].dimModes = 0.0;
  Ports_elems_sizes[5].dims[0] = 1;
  Ports_elems_sizes[5].dims[1] = 4;
  for (i10 = 0; i10 < 4; i10++) {
    Ports_data[5].dims[i10] = (real_T)iv21[i10];
  }

  Ports_data[5].dType = 0.0;
  Ports_data[5].complexity = 0.0;
  Ports_data[5].outputBuiltInDTEqUsed = 0.0;
  Ports_data[6].dimModes = 0.0;
  Ports_elems_sizes[6].dims[0] = 1;
  Ports_elems_sizes[6].dims[1] = 4;
  for (i10 = 0; i10 < 4; i10++) {
    Ports_data[6].dims[i10] = (real_T)iv18[i10];
  }

  Ports_data[6].dType = 0.0;
  Ports_data[6].complexity = 0.0;
  Ports_data[6].outputBuiltInDTEqUsed = 0.0;
  for (i10 = 0; i10 < 36; i10++) {
    t2_objTypeName[i10] = cv30[i10];
  }

  for (i10 = 0; i10 < 22; i10++) {
    t2_sysObjChksum[i10] = cv31[i10];
  }

  for (i10 = 0; i10 < 4; i10++) {
    t1_cgxeChksum[i10] = uv0[i10];
  }

  for (i10 = 0; i10 < 4; i10++) {
    checksums[0].chksum[i10] = (real_T)t3_chksum[i10];
  }

  for (i10 = 0; i10 < 4; i10++) {
    checksums[1].chksum[i10] = (real_T)t4_chksum[i10];
  }

  for (i10 = 0; i10 < 4; i10++) {
    checksums[2].chksum[i10] = (real_T)t5_chksum[i10];
  }

  for (i10 = 0; i10 < 4; i10++) {
    checksums[3].chksum[i10] = (real_T)t6_chksum[i10];
  }

  for (i10 = 0; i10 < 4; i10++) {
    b_t5_chksum[i10] = t7_codeGenChksum[i10];
  }

  for (i10 = 0; i10 < 3; i10++) {
    u_slVer[i10] = cv32[i10];
  }

  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  c_y = NULL;
  emlrtAssign(&c_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  for (i10 = 0; i10 < 7; i10++) {
    u_elems_sizes[i10] = Ports_elems_sizes[i10];
    u_data[i10] = Ports_data[i10];
  }

  d_y = NULL;
  for (i10 = 0; i10 < 2; i10++) {
    iv22[i10] = 1 + 6 * i10;
  }

  emlrtAssign(&d_y, emlrtCreateStructArray(2, iv22, 0, NULL));
  for (i10 = 0; i10 < 7; i10++) {
    tmp_elems_sizes = &u_elems_sizes[i10];
    tmp_data = &u_data[i10];
    u = tmp_data->dimModes;
    e_y = NULL;
    m9 = emlrtCreateDoubleScalar(u);
    emlrtAssign(&e_y, m9);
    emlrtAddField(d_y, e_y, "dimModes", i10);
    u_sizes[0] = 1;
    u_sizes[1] = tmp_elems_sizes->dims[1];
    i11 = tmp_elems_sizes->dims[0];
    i = tmp_elems_sizes->dims[1];
    tmp_sizes = i11 * i;
    i *= i11;
    for (i11 = 0; i11 < i; i11++) {
      b_u[i11] = tmp_data->dims[i11];
    }

    for (i11 = 0; i11 < tmp_sizes; i11++) {
      b_u_data[i11] = b_u[i11];
    }

    f_y = NULL;
    m9 = emlrtCreateNumericArray(2, u_sizes, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T *)mxGetPr(m9);
    i11 = 0;
    for (i = 0; i < u_sizes[1]; i++) {
      pData[i11] = b_u_data[u_sizes[0] * i];
      i11++;
    }

    emlrtAssign(&f_y, m9);
    emlrtAddField(d_y, f_y, "dims", i10);
    u = tmp_data->dType;
    g_y = NULL;
    m9 = emlrtCreateDoubleScalar(u);
    emlrtAssign(&g_y, m9);
    emlrtAddField(d_y, g_y, "dType", i10);
    u = tmp_data->complexity;
    h_y = NULL;
    m9 = emlrtCreateDoubleScalar(u);
    emlrtAssign(&h_y, m9);
    emlrtAddField(d_y, h_y, "complexity", i10);
    u = tmp_data->outputBuiltInDTEqUsed;
    i_y = NULL;
    m9 = emlrtCreateDoubleScalar(u);
    emlrtAssign(&i_y, m9);
    emlrtAddField(d_y, i_y, "outputBuiltInDTEqUsed", i10);
  }

  emlrtAddField(c_y, d_y, "Ports", 0);
  j_y = NULL;
  for (i10 = 0; i10 < 2; i10++) {
    iv22[i10] = 1 - i10;
  }

  emlrtAssign(&j_y, emlrtCreateStructArray(2, iv22, 0, NULL));
  emlrtAddField(j_y, NULL, "names", 0);
  emlrtAddField(j_y, NULL, "dims", 0);
  emlrtAddField(j_y, NULL, "dType", 0);
  emlrtAddField(j_y, NULL, "complexity", 0);
  emlrtAddField(c_y, j_y, "dWork", 0);
  k_y = NULL;
  m9 = emlrtCreateCharArray(2, iv23);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 36, m9, t2_objTypeName);
  emlrtAssign(&k_y, m9);
  emlrtAddField(c_y, k_y, "objTypeName", 0);
  l_y = NULL;
  m9 = emlrtCreateDoubleScalar(1744.0);
  emlrtAssign(&l_y, m9);
  emlrtAddField(c_y, l_y, "objTypeSize", 0);
  m_y = NULL;
  for (i10 = 0; i10 < 2; i10++) {
    iv22[i10] = 1 - i10;
  }

  emlrtAssign(&m_y, emlrtCreateStructArray(2, iv22, 0, NULL));
  emlrtAddField(m_y, NULL, "names", 0);
  emlrtAddField(m_y, NULL, "dims", 0);
  emlrtAddField(m_y, NULL, "dType", 0);
  emlrtAddField(m_y, NULL, "dTypeSize", 0);
  emlrtAddField(m_y, NULL, "dTypeName", 0);
  emlrtAddField(m_y, NULL, "dTypeIndex", 0);
  emlrtAddField(m_y, NULL, "dTypeChksum", 0);
  emlrtAddField(m_y, NULL, "complexity", 0);
  emlrtAddField(c_y, m_y, "persisVarDWork", 0);
  n_y = NULL;
  m9 = emlrtCreateCharArray(2, iv24);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 22, m9, t2_sysObjChksum);
  emlrtAssign(&n_y, m9);
  emlrtAddField(c_y, n_y, "sysObjChksum", 0);
  o_y = NULL;
  emlrtAssign(&o_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  p_y = NULL;
  for (i10 = 0; i10 < 2; i10++) {
    iv22[i10] = 1 - i10;
  }

  emlrtAssign(&p_y, emlrtCreateStructArray(2, iv22, 0, NULL));
  emlrtAddField(p_y, NULL, "Index", 0);
  emlrtAddField(p_y, NULL, "DataType", 0);
  emlrtAddField(p_y, NULL, "IsSigned", 0);
  emlrtAddField(p_y, NULL, "MantBits", 0);
  emlrtAddField(p_y, NULL, "FixExp", 0);
  emlrtAddField(p_y, NULL, "Slope", 0);
  emlrtAddField(p_y, NULL, "Bias", 0);
  emlrtAddField(o_y, p_y, "Out", 0);
  q_y = NULL;
  for (i10 = 0; i10 < 2; i10++) {
    iv22[i10] = 1 - i10;
  }

  emlrtAssign(&q_y, emlrtCreateStructArray(2, iv22, 0, NULL));
  emlrtAddField(q_y, NULL, "Index", 0);
  emlrtAddField(q_y, NULL, "DataType", 0);
  emlrtAddField(q_y, NULL, "IsSigned", 0);
  emlrtAddField(q_y, NULL, "MantBits", 0);
  emlrtAddField(q_y, NULL, "FixExp", 0);
  emlrtAddField(q_y, NULL, "Slope", 0);
  emlrtAddField(q_y, NULL, "Bias", 0);
  emlrtAddField(o_y, q_y, "DW", 0);
  r_y = NULL;
  for (i10 = 0; i10 < 2; i10++) {
    iv22[i10] = 1 - i10;
  }

  emlrtAssign(&r_y, emlrtCreateStructArray(2, iv22, 0, NULL));
  emlrtAddField(r_y, NULL, "Index", 0);
  emlrtAddField(r_y, NULL, "DataType", 0);
  emlrtAddField(r_y, NULL, "IsSigned", 0);
  emlrtAddField(r_y, NULL, "MantBits", 0);
  emlrtAddField(r_y, NULL, "FixExp", 0);
  emlrtAddField(r_y, NULL, "Slope", 0);
  emlrtAddField(r_y, NULL, "Bias", 0);
  emlrtAddField(o_y, r_y, "PersisDW", 0);
  emlrtAddField(c_y, o_y, "mapsInfo", 0);
  s_y = NULL;
  m9 = emlrtCreateDoubleScalar(1.0);
  emlrtAssign(&s_y, m9);
  emlrtAddField(c_y, s_y, "objDWorkTypeNameIndex", 0);
  b_u_sizes[0] = 1;
  b_u_sizes[1] = 6;
  t_y = NULL;
  m9 = emlrtCreateNumericArray(2, b_u_sizes, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m9);
  i10 = 0;
  for (i = 0; i < 6; i++) {
    pData[i10] = 0.0;
    i10++;
  }

  emlrtAssign(&t_y, m9);
  emlrtAddField(c_y, t_y, "inputDFFlagsIndexField", 0);
  emlrtAddField(b_y, c_y, "DispatcherInfo", 0);
  u_y = NULL;
  m9 = emlrtCreateNumericArray(2, iv25, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m9);
  for (i = 0; i < 4; i++) {
    pData[i] = (real_T)t1_cgxeChksum[i];
  }

  emlrtAssign(&u_y, m9);
  emlrtAddField(b_y, u_y, "cgxeChksum", 0);
  emlrtAddField(y, b_y, "RestoreInfo", 0);
  v_y = NULL;
  emlrtAssign(&v_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  for (i10 = 0; i10 < 4; i10++) {
    c_u[i10] = checksums[i10];
  }

  w_y = NULL;
  for (i10 = 0; i10 < 2; i10++) {
    iv22[i10] = 1 + 3 * i10;
  }

  emlrtAssign(&w_y, emlrtCreateStructArray(2, iv22, 0, NULL));
  for (i10 = 0; i10 < 4; i10++) {
    r0 = &c_u[i10];
    for (i11 = 0; i11 < 4; i11++) {
      b_u[i11] = r0->chksum[i11];
    }

    x_y = NULL;
    m9 = emlrtCreateNumericArray(2, iv26, mxDOUBLE_CLASS, mxREAL);
    pData = (real_T *)mxGetPr(m9);
    for (i = 0; i < 4; i++) {
      pData[i] = b_u[i];
    }

    emlrtAssign(&x_y, m9);
    emlrtAddField(w_y, x_y, "chksum", i10);
  }

  emlrtAddField(v_y, w_y, "checksums", 0);
  y_y = NULL;
  emlrtAssign(&y_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  ab_y = NULL;
  m9 = emlrtCreateNumericArray(2, iv27, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m9);
  for (i = 0; i < 4; i++) {
    pData[i] = (real_T)b_t5_chksum[i];
  }

  emlrtAssign(&ab_y, m9);
  emlrtAddField(y_y, ab_y, "codeGenChksum", 0);
  emlrtAddField(v_y, y_y, "codeGenOnlyInfo", 0);
  emlrtAddField(y, v_y, "VerificationInfo", 0);
  bb_y = NULL;
  m9 = emlrtCreateCharArray(2, iv28);
  emlrtInitCharArrayR2013a(emlrtRootTLSGlobal, 3, m9, u_slVer);
  emlrtAssign(&bb_y, m9);
  emlrtAddField(y, bb_y, "slVer", 0);
  emlrtAssign(&infoCache, y);
  return infoCache;
}

static const mxArray *c_emlrt_marshallOut(const PS3Controller_2 *u)
{
  const mxArray *y;
  const mxArray *b_y;
  const mxArray *m10;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *r_y;
  const mxArray *s_y;
  const mxArray *t_y;
  const mxArray *u_y;
  const mxArray *v_y;
  const mxArray *w_y;
  const mxArray *x_y;
  const mxArray *y_y;
  const mxArray *ab_y;
  const mxArray *bb_y;
  const mxArray *cb_y;
  const mxArray *db_y;
  const mxArray *eb_y;
  const mxArray *fb_y;
  const mxArray *gb_y;
  const mxArray *hb_y;
  const mxArray *ib_y;
  const mxArray *jb_y;
  const mxArray *kb_y;
  const mxArray *lb_y;
  const mxArray *mb_y;
  const mxArray *nb_y;
  const mxArray *ob_y;
  const mxArray *pb_y;
  const mxArray *qb_y;
  const mxArray *rb_y;
  const mxArray *sb_y;
  const mxArray *tb_y;
  const mxArray *ub_y;
  const mxArray *vb_y;
  const mxArray *wb_y;
  const mxArray *xb_y;
  const mxArray *yb_y;
  const mxArray *ac_y;
  const mxArray *bc_y;
  const mxArray *cc_y;
  const mxArray *dc_y;
  const mxArray *ec_y;
  const mxArray *fc_y;
  const mxArray *gc_y;
  const mxArray *hc_y;
  const mxArray *ic_y;
  const mxArray *jc_y;
  const mxArray *kc_y;
  const mxArray *lc_y;
  const mxArray *mc_y;
  const mxArray *nc_y;
  const mxArray *oc_y;
  const mxArray *pc_y;
  const mxArray *qc_y;
  const mxArray *rc_y;
  const mxArray *sc_y;
  const mxArray *tc_y;
  const mxArray *uc_y;
  const mxArray *vc_y;
  const mxArray *wc_y;
  const mxArray *xc_y;
  const mxArray *yc_y;
  const mxArray *ad_y;
  const mxArray *bd_y;
  const mxArray *cd_y;
  const mxArray *dd_y;
  const mxArray *ed_y;
  const mxArray *fd_y;
  const mxArray *gd_y;
  const mxArray *hd_y;
  const mxArray *id_y;
  const mxArray *jd_y;
  const mxArray *kd_y;
  const mxArray *ld_y;
  const mxArray *md_y;
  const mxArray *nd_y;
  const mxArray *od_y;
  const mxArray *pd_y;
  const mxArray *qd_y;
  const mxArray *rd_y;
  const mxArray *sd_y;
  const mxArray *td_y;
  const mxArray *ud_y;
  const mxArray *vd_y;
  const mxArray *wd_y;
  const mxArray *xd_y;
  const mxArray *yd_y;
  const mxArray *ae_y;
  const mxArray *be_y;
  const mxArray *ce_y;
  const mxArray *de_y;
  const mxArray *ee_y;
  const mxArray *fe_y;
  const mxArray *ge_y;
  const mxArray *he_y;
  const mxArray *ie_y;
  const mxArray *je_y;
  const mxArray *ke_y;
  const mxArray *le_y;
  const mxArray *me_y;
  const mxArray *ne_y;
  const mxArray *oe_y;
  const mxArray *pe_y;
  const mxArray *qe_y;
  const mxArray *re_y;
  const mxArray *se_y;
  const mxArray *te_y;
  const mxArray *ue_y;
  const mxArray *ve_y;
  const mxArray *we_y;
  const mxArray *xe_y;
  const mxArray *ye_y;
  const mxArray *af_y;
  const mxArray *bf_y;
  const mxArray *cf_y;
  const mxArray *df_y;
  const mxArray *ef_y;
  const mxArray *ff_y;
  const mxArray *gf_y;
  const mxArray *hf_y;
  const mxArray *if_y;
  const mxArray *jf_y;
  const mxArray *kf_y;
  const mxArray *lf_y;
  const mxArray *mf_y;
  const mxArray *nf_y;
  const mxArray *of_y;
  const mxArray *pf_y;
  const mxArray *qf_y;
  const mxArray *rf_y;
  const mxArray *sf_y;
  const mxArray *tf_y;
  const mxArray *uf_y;
  const mxArray *vf_y;
  const mxArray *wf_y;
  const mxArray *xf_y;
  const mxArray *yf_y;
  const mxArray *ag_y;
  const mxArray *bg_y;
  const mxArray *cg_y;
  const mxArray *dg_y;
  const mxArray *eg_y;
  const mxArray *fg_y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  b_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->leftStickY);
  emlrtAssign(&b_y, m10);
  emlrtAddField(y, b_y, "leftStickY", 0);
  c_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->rightStickX);
  emlrtAssign(&c_y, m10);
  emlrtAddField(y, c_y, "rightStickX", 0);
  d_y = NULL;
  emlrtAssign(&d_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  e_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->_select.value);
  emlrtAssign(&e_y, m10);
  emlrtAddField(d_y, e_y, "value", 0);
  f_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->_select.isPressed);
  emlrtAssign(&f_y, m10);
  emlrtAddField(d_y, f_y, "isPressed", 0);
  g_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->_select.clickDuration);
  emlrtAssign(&g_y, m10);
  emlrtAddField(d_y, g_y, "clickDuration", 0);
  h_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->_select.clickCount);
  emlrtAssign(&h_y, m10);
  emlrtAddField(d_y, h_y, "clickCount", 0);
  i_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->_select.time);
  emlrtAssign(&i_y, m10);
  emlrtAddField(d_y, i_y, "time", 0);
  j_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->_select.timePressed);
  emlrtAssign(&j_y, m10);
  emlrtAddField(d_y, j_y, "timePressed", 0);
  k_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->_select.sampleInterval);
  emlrtAssign(&k_y, m10);
  emlrtAddField(d_y, k_y, "sampleInterval", 0);
  l_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->_select.clickInterval);
  emlrtAssign(&l_y, m10);
  emlrtAddField(d_y, l_y, "clickInterval", 0);
  emlrtAddField(y, d_y, "select", 0);
  m_y = NULL;
  emlrtAssign(&m_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  n_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->l3.value);
  emlrtAssign(&n_y, m10);
  emlrtAddField(m_y, n_y, "value", 0);
  o_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->l3.isPressed);
  emlrtAssign(&o_y, m10);
  emlrtAddField(m_y, o_y, "isPressed", 0);
  p_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l3.clickDuration);
  emlrtAssign(&p_y, m10);
  emlrtAddField(m_y, p_y, "clickDuration", 0);
  q_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l3.clickCount);
  emlrtAssign(&q_y, m10);
  emlrtAddField(m_y, q_y, "clickCount", 0);
  r_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l3.time);
  emlrtAssign(&r_y, m10);
  emlrtAddField(m_y, r_y, "time", 0);
  s_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l3.timePressed);
  emlrtAssign(&s_y, m10);
  emlrtAddField(m_y, s_y, "timePressed", 0);
  t_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l3.sampleInterval);
  emlrtAssign(&t_y, m10);
  emlrtAddField(m_y, t_y, "sampleInterval", 0);
  u_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l3.clickInterval);
  emlrtAssign(&u_y, m10);
  emlrtAddField(m_y, u_y, "clickInterval", 0);
  emlrtAddField(y, m_y, "l3", 0);
  v_y = NULL;
  emlrtAssign(&v_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  w_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->r3.value);
  emlrtAssign(&w_y, m10);
  emlrtAddField(v_y, w_y, "value", 0);
  x_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->r3.isPressed);
  emlrtAssign(&x_y, m10);
  emlrtAddField(v_y, x_y, "isPressed", 0);
  y_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r3.clickDuration);
  emlrtAssign(&y_y, m10);
  emlrtAddField(v_y, y_y, "clickDuration", 0);
  ab_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r3.clickCount);
  emlrtAssign(&ab_y, m10);
  emlrtAddField(v_y, ab_y, "clickCount", 0);
  bb_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r3.time);
  emlrtAssign(&bb_y, m10);
  emlrtAddField(v_y, bb_y, "time", 0);
  cb_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r3.timePressed);
  emlrtAssign(&cb_y, m10);
  emlrtAddField(v_y, cb_y, "timePressed", 0);
  db_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r3.sampleInterval);
  emlrtAssign(&db_y, m10);
  emlrtAddField(v_y, db_y, "sampleInterval", 0);
  eb_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r3.clickInterval);
  emlrtAssign(&eb_y, m10);
  emlrtAddField(v_y, eb_y, "clickInterval", 0);
  emlrtAddField(y, v_y, "r3", 0);
  fb_y = NULL;
  emlrtAssign(&fb_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  gb_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->start.value);
  emlrtAssign(&gb_y, m10);
  emlrtAddField(fb_y, gb_y, "value", 0);
  hb_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->start.isPressed);
  emlrtAssign(&hb_y, m10);
  emlrtAddField(fb_y, hb_y, "isPressed", 0);
  ib_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->start.clickDuration);
  emlrtAssign(&ib_y, m10);
  emlrtAddField(fb_y, ib_y, "clickDuration", 0);
  jb_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->start.clickCount);
  emlrtAssign(&jb_y, m10);
  emlrtAddField(fb_y, jb_y, "clickCount", 0);
  kb_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->start.time);
  emlrtAssign(&kb_y, m10);
  emlrtAddField(fb_y, kb_y, "time", 0);
  lb_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->start.timePressed);
  emlrtAssign(&lb_y, m10);
  emlrtAddField(fb_y, lb_y, "timePressed", 0);
  mb_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->start.sampleInterval);
  emlrtAssign(&mb_y, m10);
  emlrtAddField(fb_y, mb_y, "sampleInterval", 0);
  nb_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->start.clickInterval);
  emlrtAssign(&nb_y, m10);
  emlrtAddField(fb_y, nb_y, "clickInterval", 0);
  emlrtAddField(y, fb_y, "start", 0);
  ob_y = NULL;
  emlrtAssign(&ob_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  pb_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->up.value);
  emlrtAssign(&pb_y, m10);
  emlrtAddField(ob_y, pb_y, "value", 0);
  qb_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->up.isPressed);
  emlrtAssign(&qb_y, m10);
  emlrtAddField(ob_y, qb_y, "isPressed", 0);
  rb_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->up.clickDuration);
  emlrtAssign(&rb_y, m10);
  emlrtAddField(ob_y, rb_y, "clickDuration", 0);
  sb_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->up.clickCount);
  emlrtAssign(&sb_y, m10);
  emlrtAddField(ob_y, sb_y, "clickCount", 0);
  tb_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->up.time);
  emlrtAssign(&tb_y, m10);
  emlrtAddField(ob_y, tb_y, "time", 0);
  ub_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->up.timePressed);
  emlrtAssign(&ub_y, m10);
  emlrtAddField(ob_y, ub_y, "timePressed", 0);
  vb_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->up.sampleInterval);
  emlrtAssign(&vb_y, m10);
  emlrtAddField(ob_y, vb_y, "sampleInterval", 0);
  wb_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->up.clickInterval);
  emlrtAssign(&wb_y, m10);
  emlrtAddField(ob_y, wb_y, "clickInterval", 0);
  emlrtAddField(y, ob_y, "up", 0);
  xb_y = NULL;
  emlrtAssign(&xb_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  yb_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->right.value);
  emlrtAssign(&yb_y, m10);
  emlrtAddField(xb_y, yb_y, "value", 0);
  ac_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->right.isPressed);
  emlrtAssign(&ac_y, m10);
  emlrtAddField(xb_y, ac_y, "isPressed", 0);
  bc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->right.clickDuration);
  emlrtAssign(&bc_y, m10);
  emlrtAddField(xb_y, bc_y, "clickDuration", 0);
  cc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->right.clickCount);
  emlrtAssign(&cc_y, m10);
  emlrtAddField(xb_y, cc_y, "clickCount", 0);
  dc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->right.time);
  emlrtAssign(&dc_y, m10);
  emlrtAddField(xb_y, dc_y, "time", 0);
  ec_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->right.timePressed);
  emlrtAssign(&ec_y, m10);
  emlrtAddField(xb_y, ec_y, "timePressed", 0);
  fc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->right.sampleInterval);
  emlrtAssign(&fc_y, m10);
  emlrtAddField(xb_y, fc_y, "sampleInterval", 0);
  gc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->right.clickInterval);
  emlrtAssign(&gc_y, m10);
  emlrtAddField(xb_y, gc_y, "clickInterval", 0);
  emlrtAddField(y, xb_y, "right", 0);
  hc_y = NULL;
  emlrtAssign(&hc_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  ic_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->down.value);
  emlrtAssign(&ic_y, m10);
  emlrtAddField(hc_y, ic_y, "value", 0);
  jc_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->down.isPressed);
  emlrtAssign(&jc_y, m10);
  emlrtAddField(hc_y, jc_y, "isPressed", 0);
  kc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->down.clickDuration);
  emlrtAssign(&kc_y, m10);
  emlrtAddField(hc_y, kc_y, "clickDuration", 0);
  lc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->down.clickCount);
  emlrtAssign(&lc_y, m10);
  emlrtAddField(hc_y, lc_y, "clickCount", 0);
  mc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->down.time);
  emlrtAssign(&mc_y, m10);
  emlrtAddField(hc_y, mc_y, "time", 0);
  nc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->down.timePressed);
  emlrtAssign(&nc_y, m10);
  emlrtAddField(hc_y, nc_y, "timePressed", 0);
  oc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->down.sampleInterval);
  emlrtAssign(&oc_y, m10);
  emlrtAddField(hc_y, oc_y, "sampleInterval", 0);
  pc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->down.clickInterval);
  emlrtAssign(&pc_y, m10);
  emlrtAddField(hc_y, pc_y, "clickInterval", 0);
  emlrtAddField(y, hc_y, "down", 0);
  qc_y = NULL;
  emlrtAssign(&qc_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  rc_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->left.value);
  emlrtAssign(&rc_y, m10);
  emlrtAddField(qc_y, rc_y, "value", 0);
  sc_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->left.isPressed);
  emlrtAssign(&sc_y, m10);
  emlrtAddField(qc_y, sc_y, "isPressed", 0);
  tc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->left.clickDuration);
  emlrtAssign(&tc_y, m10);
  emlrtAddField(qc_y, tc_y, "clickDuration", 0);
  uc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->left.clickCount);
  emlrtAssign(&uc_y, m10);
  emlrtAddField(qc_y, uc_y, "clickCount", 0);
  vc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->left.time);
  emlrtAssign(&vc_y, m10);
  emlrtAddField(qc_y, vc_y, "time", 0);
  wc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->left.timePressed);
  emlrtAssign(&wc_y, m10);
  emlrtAddField(qc_y, wc_y, "timePressed", 0);
  xc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->left.sampleInterval);
  emlrtAssign(&xc_y, m10);
  emlrtAddField(qc_y, xc_y, "sampleInterval", 0);
  yc_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->left.clickInterval);
  emlrtAssign(&yc_y, m10);
  emlrtAddField(qc_y, yc_y, "clickInterval", 0);
  emlrtAddField(y, qc_y, "left", 0);
  ad_y = NULL;
  emlrtAssign(&ad_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  bd_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->l2.value);
  emlrtAssign(&bd_y, m10);
  emlrtAddField(ad_y, bd_y, "value", 0);
  cd_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->l2.isPressed);
  emlrtAssign(&cd_y, m10);
  emlrtAddField(ad_y, cd_y, "isPressed", 0);
  dd_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l2.clickDuration);
  emlrtAssign(&dd_y, m10);
  emlrtAddField(ad_y, dd_y, "clickDuration", 0);
  ed_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l2.clickCount);
  emlrtAssign(&ed_y, m10);
  emlrtAddField(ad_y, ed_y, "clickCount", 0);
  fd_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l2.time);
  emlrtAssign(&fd_y, m10);
  emlrtAddField(ad_y, fd_y, "time", 0);
  gd_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l2.timePressed);
  emlrtAssign(&gd_y, m10);
  emlrtAddField(ad_y, gd_y, "timePressed", 0);
  hd_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l2.sampleInterval);
  emlrtAssign(&hd_y, m10);
  emlrtAddField(ad_y, hd_y, "sampleInterval", 0);
  id_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l2.clickInterval);
  emlrtAssign(&id_y, m10);
  emlrtAddField(ad_y, id_y, "clickInterval", 0);
  emlrtAddField(y, ad_y, "l2", 0);
  jd_y = NULL;
  emlrtAssign(&jd_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  kd_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->r2.value);
  emlrtAssign(&kd_y, m10);
  emlrtAddField(jd_y, kd_y, "value", 0);
  ld_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->r2.isPressed);
  emlrtAssign(&ld_y, m10);
  emlrtAddField(jd_y, ld_y, "isPressed", 0);
  md_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r2.clickDuration);
  emlrtAssign(&md_y, m10);
  emlrtAddField(jd_y, md_y, "clickDuration", 0);
  nd_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r2.clickCount);
  emlrtAssign(&nd_y, m10);
  emlrtAddField(jd_y, nd_y, "clickCount", 0);
  od_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r2.time);
  emlrtAssign(&od_y, m10);
  emlrtAddField(jd_y, od_y, "time", 0);
  pd_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r2.timePressed);
  emlrtAssign(&pd_y, m10);
  emlrtAddField(jd_y, pd_y, "timePressed", 0);
  qd_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r2.sampleInterval);
  emlrtAssign(&qd_y, m10);
  emlrtAddField(jd_y, qd_y, "sampleInterval", 0);
  rd_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r2.clickInterval);
  emlrtAssign(&rd_y, m10);
  emlrtAddField(jd_y, rd_y, "clickInterval", 0);
  emlrtAddField(y, jd_y, "r2", 0);
  sd_y = NULL;
  emlrtAssign(&sd_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  td_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->l1.value);
  emlrtAssign(&td_y, m10);
  emlrtAddField(sd_y, td_y, "value", 0);
  ud_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->l1.isPressed);
  emlrtAssign(&ud_y, m10);
  emlrtAddField(sd_y, ud_y, "isPressed", 0);
  vd_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l1.clickDuration);
  emlrtAssign(&vd_y, m10);
  emlrtAddField(sd_y, vd_y, "clickDuration", 0);
  wd_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l1.clickCount);
  emlrtAssign(&wd_y, m10);
  emlrtAddField(sd_y, wd_y, "clickCount", 0);
  xd_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l1.time);
  emlrtAssign(&xd_y, m10);
  emlrtAddField(sd_y, xd_y, "time", 0);
  yd_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l1.timePressed);
  emlrtAssign(&yd_y, m10);
  emlrtAddField(sd_y, yd_y, "timePressed", 0);
  ae_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l1.sampleInterval);
  emlrtAssign(&ae_y, m10);
  emlrtAddField(sd_y, ae_y, "sampleInterval", 0);
  be_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->l1.clickInterval);
  emlrtAssign(&be_y, m10);
  emlrtAddField(sd_y, be_y, "clickInterval", 0);
  emlrtAddField(y, sd_y, "l1", 0);
  ce_y = NULL;
  emlrtAssign(&ce_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  de_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->r1.value);
  emlrtAssign(&de_y, m10);
  emlrtAddField(ce_y, de_y, "value", 0);
  ee_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->r1.isPressed);
  emlrtAssign(&ee_y, m10);
  emlrtAddField(ce_y, ee_y, "isPressed", 0);
  fe_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r1.clickDuration);
  emlrtAssign(&fe_y, m10);
  emlrtAddField(ce_y, fe_y, "clickDuration", 0);
  ge_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r1.clickCount);
  emlrtAssign(&ge_y, m10);
  emlrtAddField(ce_y, ge_y, "clickCount", 0);
  he_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r1.time);
  emlrtAssign(&he_y, m10);
  emlrtAddField(ce_y, he_y, "time", 0);
  ie_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r1.timePressed);
  emlrtAssign(&ie_y, m10);
  emlrtAddField(ce_y, ie_y, "timePressed", 0);
  je_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r1.sampleInterval);
  emlrtAssign(&je_y, m10);
  emlrtAddField(ce_y, je_y, "sampleInterval", 0);
  ke_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->r1.clickInterval);
  emlrtAssign(&ke_y, m10);
  emlrtAddField(ce_y, ke_y, "clickInterval", 0);
  emlrtAddField(y, ce_y, "r1", 0);
  le_y = NULL;
  emlrtAssign(&le_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  me_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->triangle.value);
  emlrtAssign(&me_y, m10);
  emlrtAddField(le_y, me_y, "value", 0);
  ne_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->triangle.isPressed);
  emlrtAssign(&ne_y, m10);
  emlrtAddField(le_y, ne_y, "isPressed", 0);
  oe_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->triangle.clickDuration);
  emlrtAssign(&oe_y, m10);
  emlrtAddField(le_y, oe_y, "clickDuration", 0);
  pe_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->triangle.clickCount);
  emlrtAssign(&pe_y, m10);
  emlrtAddField(le_y, pe_y, "clickCount", 0);
  qe_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->triangle.time);
  emlrtAssign(&qe_y, m10);
  emlrtAddField(le_y, qe_y, "time", 0);
  re_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->triangle.timePressed);
  emlrtAssign(&re_y, m10);
  emlrtAddField(le_y, re_y, "timePressed", 0);
  se_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->triangle.sampleInterval);
  emlrtAssign(&se_y, m10);
  emlrtAddField(le_y, se_y, "sampleInterval", 0);
  te_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->triangle.clickInterval);
  emlrtAssign(&te_y, m10);
  emlrtAddField(le_y, te_y, "clickInterval", 0);
  emlrtAddField(y, le_y, "triangle", 0);
  ue_y = NULL;
  emlrtAssign(&ue_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  ve_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->circle.value);
  emlrtAssign(&ve_y, m10);
  emlrtAddField(ue_y, ve_y, "value", 0);
  we_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->circle.isPressed);
  emlrtAssign(&we_y, m10);
  emlrtAddField(ue_y, we_y, "isPressed", 0);
  xe_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->circle.clickDuration);
  emlrtAssign(&xe_y, m10);
  emlrtAddField(ue_y, xe_y, "clickDuration", 0);
  ye_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->circle.clickCount);
  emlrtAssign(&ye_y, m10);
  emlrtAddField(ue_y, ye_y, "clickCount", 0);
  af_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->circle.time);
  emlrtAssign(&af_y, m10);
  emlrtAddField(ue_y, af_y, "time", 0);
  bf_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->circle.timePressed);
  emlrtAssign(&bf_y, m10);
  emlrtAddField(ue_y, bf_y, "timePressed", 0);
  cf_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->circle.sampleInterval);
  emlrtAssign(&cf_y, m10);
  emlrtAddField(ue_y, cf_y, "sampleInterval", 0);
  df_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->circle.clickInterval);
  emlrtAssign(&df_y, m10);
  emlrtAddField(ue_y, df_y, "clickInterval", 0);
  emlrtAddField(y, ue_y, "circle", 0);
  ef_y = NULL;
  emlrtAssign(&ef_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  ff_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->cross.value);
  emlrtAssign(&ff_y, m10);
  emlrtAddField(ef_y, ff_y, "value", 0);
  gf_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->cross.isPressed);
  emlrtAssign(&gf_y, m10);
  emlrtAddField(ef_y, gf_y, "isPressed", 0);
  hf_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->cross.clickDuration);
  emlrtAssign(&hf_y, m10);
  emlrtAddField(ef_y, hf_y, "clickDuration", 0);
  if_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->cross.clickCount);
  emlrtAssign(&if_y, m10);
  emlrtAddField(ef_y, if_y, "clickCount", 0);
  jf_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->cross.time);
  emlrtAssign(&jf_y, m10);
  emlrtAddField(ef_y, jf_y, "time", 0);
  kf_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->cross.timePressed);
  emlrtAssign(&kf_y, m10);
  emlrtAddField(ef_y, kf_y, "timePressed", 0);
  lf_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->cross.sampleInterval);
  emlrtAssign(&lf_y, m10);
  emlrtAddField(ef_y, lf_y, "sampleInterval", 0);
  mf_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->cross.clickInterval);
  emlrtAssign(&mf_y, m10);
  emlrtAddField(ef_y, mf_y, "clickInterval", 0);
  emlrtAddField(y, ef_y, "cross", 0);
  nf_y = NULL;
  emlrtAssign(&nf_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  of_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->square.value);
  emlrtAssign(&of_y, m10);
  emlrtAddField(nf_y, of_y, "value", 0);
  pf_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->square.isPressed);
  emlrtAssign(&pf_y, m10);
  emlrtAddField(nf_y, pf_y, "isPressed", 0);
  qf_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->square.clickDuration);
  emlrtAssign(&qf_y, m10);
  emlrtAddField(nf_y, qf_y, "clickDuration", 0);
  rf_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->square.clickCount);
  emlrtAssign(&rf_y, m10);
  emlrtAddField(nf_y, rf_y, "clickCount", 0);
  sf_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->square.time);
  emlrtAssign(&sf_y, m10);
  emlrtAddField(nf_y, sf_y, "time", 0);
  tf_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->square.timePressed);
  emlrtAssign(&tf_y, m10);
  emlrtAddField(nf_y, tf_y, "timePressed", 0);
  uf_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->square.sampleInterval);
  emlrtAssign(&uf_y, m10);
  emlrtAddField(nf_y, uf_y, "sampleInterval", 0);
  vf_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->square.clickInterval);
  emlrtAssign(&vf_y, m10);
  emlrtAddField(nf_y, vf_y, "clickInterval", 0);
  emlrtAddField(y, nf_y, "square", 0);
  wf_y = NULL;
  emlrtAssign(&wf_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  xf_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->ps.value);
  emlrtAssign(&xf_y, m10);
  emlrtAddField(wf_y, xf_y, "value", 0);
  yf_y = NULL;
  m10 = emlrtCreateLogicalScalar(u->ps.isPressed);
  emlrtAssign(&yf_y, m10);
  emlrtAddField(wf_y, yf_y, "isPressed", 0);
  ag_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->ps.clickDuration);
  emlrtAssign(&ag_y, m10);
  emlrtAddField(wf_y, ag_y, "clickDuration", 0);
  bg_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->ps.clickCount);
  emlrtAssign(&bg_y, m10);
  emlrtAddField(wf_y, bg_y, "clickCount", 0);
  cg_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->ps.time);
  emlrtAssign(&cg_y, m10);
  emlrtAddField(wf_y, cg_y, "time", 0);
  dg_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->ps.timePressed);
  emlrtAssign(&dg_y, m10);
  emlrtAddField(wf_y, dg_y, "timePressed", 0);
  eg_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->ps.sampleInterval);
  emlrtAssign(&eg_y, m10);
  emlrtAddField(wf_y, eg_y, "sampleInterval", 0);
  fg_y = NULL;
  m10 = emlrtCreateDoubleScalar(u->ps.clickInterval);
  emlrtAssign(&fg_y, m10);
  emlrtAddField(wf_y, fg_y, "clickInterval", 0);
  emlrtAddField(y, wf_y, "ps", 0);
  return y;
}

static const mxArray *mw__internal__getSimState__fcn
  (InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance)
{
  const mxArray *st;
  const mxArray *y;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m11;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  static const int32_T iv29[2] = { 1, 4 };

  real_T *pData;
  int32_T i;
  const mxArray *h_y;
  static const int32_T iv30[2] = { 1, 17 };

  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *r_y;
  const mxArray *s_y;
  const mxArray *t_y;
  const mxArray *u_y;
  const mxArray *v_y;
  const mxArray *w_y;
  const mxArray *x_y;
  const mxArray *y_y;
  const mxArray *ab_y;
  const mxArray *bb_y;
  const mxArray *cb_y;
  const mxArray *db_y;
  const mxArray *eb_y;
  const mxArray *fb_y;
  const mxArray *gb_y;
  const mxArray *hb_y;
  const mxArray *ib_y;
  const mxArray *jb_y;
  const mxArray *kb_y;
  const mxArray *lb_y;
  const mxArray *mb_y;
  const mxArray *nb_y;
  const mxArray *ob_y;
  const mxArray *pb_y;
  const mxArray *qb_y;
  const mxArray *rb_y;
  const mxArray *sb_y;
  const mxArray *tb_y;
  const mxArray *ub_y;
  const mxArray *vb_y;
  const mxArray *wb_y;
  const mxArray *xb_y;
  const mxArray *yb_y;
  const mxArray *ac_y;
  const mxArray *bc_y;
  const mxArray *cc_y;
  const mxArray *dc_y;
  const mxArray *ec_y;
  const mxArray *fc_y;
  const mxArray *gc_y;
  const mxArray *hc_y;
  const mxArray *ic_y;
  const mxArray *jc_y;
  const mxArray *kc_y;
  const mxArray *lc_y;
  static const int32_T enumValues[4] = { 0, 1, 2, 3 };

  static const char * enumNames[4] = { "Cross", "Circle", "Triangle", "Square" };

  const mxArray *mc_y;
  const mxArray *m12 = NULL;
  const mxArray *nc_y;
  const mxArray *oc_y;
  const mxArray *pc_y;
  const mxArray *qc_y;
  const mxArray *rc_y;
  const mxArray *sc_y;
  const mxArray *tc_y;
  const mxArray *uc_y;
  const mxArray *vc_y;
  const mxArray *wc_y;
  const mxArray *xc_y;
  const mxArray *yc_y;
  const mxArray *ad_y;
  const mxArray *bd_y;
  const mxArray *cd_y;
  const mxArray *dd_y;
  const mxArray *ed_y;
  const mxArray *fd_y;
  const mxArray *gd_y;
  const mxArray *hd_y;
  const mxArray *id_y;
  const mxArray *jd_y;
  const mxArray *kd_y;
  const mxArray *ld_y;
  const mxArray *md_y;
  const mxArray *nd_y;
  const mxArray *od_y;
  const mxArray *pd_y;
  static const int32_T iv31[1] = { 4 };

  const mxArray *qd_y;
  st = NULL;
  y = NULL;
  emlrtAssign(&y, emlrtCreateCellMatrix(2, 1));
  b_y = NULL;
  emlrtAssign(&b_y, emlrtCreateStructMatrix(1, 1, 0, NULL));
  c_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isInitialized);
  emlrtAssign(&c_y, m11);
  emlrtAddField(b_y, c_y, "isInitialized", 0);
  d_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isReleased);
  emlrtAssign(&d_y, m11);
  emlrtAddField(b_y, d_y, "isReleased", 0);
  e_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.TunablePropsChanged);
  emlrtAssign(&e_y, m11);
  emlrtAddField(b_y, e_y, "TunablePropsChanged", 0);
  f_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isSim);
  emlrtAssign(&f_y, m11);
  emlrtAddField(b_y, f_y, "isSim", 0);
  g_y = NULL;
  m11 = emlrtCreateNumericArray(2, iv29, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m11);
  for (i = 0; i < 4; i++) {
    pData[i] = moduleInstance->sysobj.ps3Axes[i];
  }

  emlrtAssign(&g_y, m11);
  emlrtAddField(b_y, g_y, "ps3Axes", 0);
  h_y = NULL;
  m11 = emlrtCreateNumericArray(2, iv30, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m11);
  for (i = 0; i < 17; i++) {
    pData[i] = moduleInstance->sysobj.ps3Buttons[i];
  }

  emlrtAssign(&h_y, m11);
  emlrtAddField(b_y, h_y, "ps3Buttons", 0);
  i_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.u_lim);
  emlrtAssign(&i_y, m11);
  emlrtAddField(b_y, i_y, "u_lim", 0);
  emlrtAddField(b_y, c_emlrt_marshallOut(&moduleInstance->sysobj.ps3), "ps3", 0);
  j_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.runTime);
  emlrtAssign(&j_y, m11);
  emlrtAddField(b_y, j_y, "runTime", 0);
  k_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isRun);
  emlrtAssign(&k_y, m11);
  emlrtAddField(b_y, k_y, "isRun", 0);
  l_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.switch_phase_last);
  emlrtAssign(&l_y, m11);
  emlrtAddField(b_y, l_y, "switch_phase_last", 0);
  m_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.switch_phase);
  emlrtAssign(&m_y, m11);
  emlrtAddField(b_y, m_y, "switch_phase", 0);
  n_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.t0_step);
  emlrtAssign(&n_y, m11);
  emlrtAddField(b_y, n_y, "t0_step", 0);
  o_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.t_gain);
  emlrtAssign(&o_y, m11);
  emlrtAddField(b_y, o_y, "t_gain", 0);
  p_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.kp_st_leg);
  emlrtAssign(&p_y, m11);
  emlrtAddField(b_y, p_y, "kp_st_leg", 0);
  q_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.kd_st_leg);
  emlrtAssign(&q_y, m11);
  emlrtAddField(b_y, q_y, "kd_st_leg", 0);
  r_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.kp_sw_leg);
  emlrtAssign(&r_y, m11);
  emlrtAddField(b_y, r_y, "kp_sw_leg", 0);
  s_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.kd_sw_leg);
  emlrtAssign(&s_y, m11);
  emlrtAddField(b_y, s_y, "kd_sw_leg", 0);
  t_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.kp_hip);
  emlrtAssign(&t_y, m11);
  emlrtAddField(b_y, t_y, "kp_hip", 0);
  u_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.kd_hip);
  emlrtAssign(&u_y, m11);
  emlrtAddField(b_y, u_y, "kd_hip", 0);
  v_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.s_l_A);
  emlrtAssign(&v_y, m11);
  emlrtAddField(b_y, v_y, "s_l_A", 0);
  w_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.s_l_B);
  emlrtAssign(&w_y, m11);
  emlrtAddField(b_y, w_y, "s_l_B", 0);
  x_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.s_r_A);
  emlrtAssign(&x_y, m11);
  emlrtAddField(b_y, x_y, "s_r_A", 0);
  y_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.s_r_B);
  emlrtAssign(&y_y, m11);
  emlrtAddField(b_y, y_y, "s_r_B", 0);
  ab_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.thres_lo);
  emlrtAssign(&ab_y, m11);
  emlrtAddField(b_y, ab_y, "thres_lo", 0);
  bb_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.thres_hi);
  emlrtAssign(&bb_y, m11);
  emlrtAddField(b_y, bb_y, "thres_hi", 0);
  cb_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.tau);
  emlrtAssign(&cb_y, m11);
  emlrtAddField(b_y, cb_y, "tau", 0);
  db_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dx_gain);
  emlrtAssign(&db_y, m11);
  emlrtAddField(b_y, db_y, "dx_gain", 0);
  eb_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dx_err_p_gain);
  emlrtAssign(&eb_y, m11);
  emlrtAddField(b_y, eb_y, "dx_err_p_gain", 0);
  fb_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dx_err_d_gain);
  emlrtAssign(&fb_y, m11);
  emlrtAddField(b_y, fb_y, "dx_err_d_gain", 0);
  gb_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dy_gain);
  emlrtAssign(&gb_y, m11);
  emlrtAddField(b_y, gb_y, "dy_gain", 0);
  hb_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dy_err_p_gain);
  emlrtAssign(&hb_y, m11);
  emlrtAddField(b_y, hb_y, "dy_err_p_gain", 0);
  ib_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dy_err_d_gain);
  emlrtAssign(&ib_y, m11);
  emlrtAddField(b_y, ib_y, "dy_err_d_gain", 0);
  jb_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.y0_offset);
  emlrtAssign(&jb_y, m11);
  emlrtAddField(b_y, jb_y, "y0_offset", 0);
  kb_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.y0_gain);
  emlrtAssign(&kb_y, m11);
  emlrtAddField(b_y, kb_y, "y0_gain", 0);
  lb_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.l0_leg);
  emlrtAssign(&lb_y, m11);
  emlrtAddField(b_y, lb_y, "l0_leg", 0);
  mb_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.l_ret);
  emlrtAssign(&mb_y, m11);
  emlrtAddField(b_y, mb_y, "l_ret", 0);
  nb_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.l_ext_gain);
  emlrtAssign(&nb_y, m11);
  emlrtAddField(b_y, nb_y, "l_ext_gain", 0);
  ob_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.s_overlap);
  emlrtAssign(&ob_y, m11);
  emlrtAddField(b_y, ob_y, "s_overlap", 0);
  pb_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isTest1);
  emlrtAssign(&pb_y, m11);
  emlrtAddField(b_y, pb_y, "isTest1", 0);
  qb_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isTest2);
  emlrtAssign(&qb_y, m11);
  emlrtAddField(b_y, qb_y, "isTest2", 0);
  rb_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isTest3);
  emlrtAssign(&rb_y, m11);
  emlrtAddField(b_y, rb_y, "isTest3", 0);
  sb_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isTest4);
  emlrtAssign(&sb_y, m11);
  emlrtAddField(b_y, sb_y, "isTest4", 0);
  tb_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isTest5);
  emlrtAssign(&tb_y, m11);
  emlrtAddField(b_y, tb_y, "isTest5", 0);
  ub_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isTest6);
  emlrtAssign(&ub_y, m11);
  emlrtAddField(b_y, ub_y, "isTest6", 0);
  vb_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isTest7);
  emlrtAssign(&vb_y, m11);
  emlrtAddField(b_y, vb_y, "isTest7", 0);
  wb_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isTest8);
  emlrtAssign(&wb_y, m11);
  emlrtAddField(b_y, wb_y, "isTest8", 0);
  xb_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isTest9);
  emlrtAssign(&xb_y, m11);
  emlrtAddField(b_y, xb_y, "isTest9", 0);
  yb_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isTest10);
  emlrtAssign(&yb_y, m11);
  emlrtAddField(b_y, yb_y, "isTest10", 0);
  ac_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isTest11);
  emlrtAssign(&ac_y, m11);
  emlrtAddField(b_y, ac_y, "isTest11", 0);
  bc_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj.isTest12);
  emlrtAssign(&bc_y, m11);
  emlrtAddField(b_y, bc_y, "isTest12", 0);
  cc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.x_offset);
  emlrtAssign(&cc_y, m11);
  emlrtAddField(b_y, cc_y, "x_offset", 0);
  dc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.steering_offset);
  emlrtAssign(&dc_y, m11);
  emlrtAddField(b_y, dc_y, "steering_offset", 0);
  ec_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.q_yaw_tgt);
  emlrtAssign(&ec_y, m11);
  emlrtAddField(b_y, ec_y, "q_yaw_tgt", 0);
  fc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.y_offset);
  emlrtAssign(&fc_y, m11);
  emlrtAddField(b_y, fc_y, "y_offset", 0);
  gc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.EnableYawControl);
  emlrtAssign(&gc_y, m11);
  emlrtAddField(b_y, gc_y, "EnableYawControl", 0);
  hc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.uHipGravity);
  emlrtAssign(&hc_y, m11);
  emlrtAddField(b_y, hc_y, "uHipGravity", 0);
  ic_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.kp_rate);
  emlrtAssign(&ic_y, m11);
  emlrtAddField(b_y, ic_y, "kp_rate", 0);
  jc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.kd_rate);
  emlrtAssign(&jc_y, m11);
  emlrtAddField(b_y, jc_y, "kd_rate", 0);
  kc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.stanceLeg);
  emlrtAssign(&kc_y, m11);
  emlrtAddField(b_y, kc_y, "stanceLeg", 0);
  lc_y = NULL;
  emlrtCheckEnumR2012b(emlrtRootTLSGlobal, "GaitMode", 4, enumNames, enumValues);
  mc_y = NULL;
  m11 = emlrtCreateNumericMatrix(1, 1, mxINT8_CLASS, mxREAL);
  *(int8_T *)mxGetData(m11) = (int8_T)moduleInstance->sysobj.gaitMode;
  emlrtAssign(&mc_y, m11);
  emlrtAssign(&m12, mc_y);
  emlrtAssign(&lc_y, emlrtCreateEnumR2012b(emlrtRootTLSGlobal, "GaitMode", m12));
  emlrtDestroyArray(&m12);
  emlrtAddField(b_y, lc_y, "gaitMode", 0);
  nc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.t);
  emlrtAssign(&nc_y, m11);
  emlrtAddField(b_y, nc_y, "t", 0);
  oc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.q_yaw);
  emlrtAssign(&oc_y, m11);
  emlrtAddField(b_y, oc_y, "q_yaw", 0);
  pc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.z_offset);
  emlrtAssign(&pc_y, m11);
  emlrtAddField(b_y, pc_y, "z_offset", 0);
  qc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.x_est);
  emlrtAssign(&qc_y, m11);
  emlrtAddField(b_y, qc_y, "x_est", 0);
  rc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.y_est);
  emlrtAssign(&rc_y, m11);
  emlrtAddField(b_y, rc_y, "y_est", 0);
  sc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dx_est);
  emlrtAssign(&sc_y, m11);
  emlrtAddField(b_y, sc_y, "dx_est", 0);
  tc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dy_est);
  emlrtAssign(&tc_y, m11);
  emlrtAddField(b_y, tc_y, "dy_est", 0);
  uc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dy_est_avg);
  emlrtAssign(&uc_y, m11);
  emlrtAddField(b_y, uc_y, "dy_est_avg", 0);
  vc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dx_tgt);
  emlrtAssign(&vc_y, m11);
  emlrtAddField(b_y, vc_y, "dx_tgt", 0);
  wc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dy_tgt);
  emlrtAssign(&wc_y, m11);
  emlrtAddField(b_y, wc_y, "dy_tgt", 0);
  xc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dx_est_last);
  emlrtAssign(&xc_y, m11);
  emlrtAddField(b_y, xc_y, "dx_est_last", 0);
  yc_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dy_est_last);
  emlrtAssign(&yc_y, m11);
  emlrtAddField(b_y, yc_y, "dy_est_last", 0);
  ad_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.l_st_last);
  emlrtAssign(&ad_y, m11);
  emlrtAddField(b_y, ad_y, "l_st_last", 0);
  bd_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dl_st_last);
  emlrtAssign(&bd_y, m11);
  emlrtAddField(b_y, bd_y, "dl_st_last", 0);
  cd_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.l_sw_last);
  emlrtAssign(&cd_y, m11);
  emlrtAddField(b_y, cd_y, "l_sw_last", 0);
  dd_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dl_sw_last);
  emlrtAssign(&dd_y, m11);
  emlrtAddField(b_y, dd_y, "dl_sw_last", 0);
  ed_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.x_sw_last);
  emlrtAssign(&ed_y, m11);
  emlrtAddField(b_y, ed_y, "x_sw_last", 0);
  fd_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dx_sw_last);
  emlrtAssign(&fd_y, m11);
  emlrtAddField(b_y, fd_y, "dx_sw_last", 0);
  gd_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.y_sw_last);
  emlrtAssign(&gd_y, m11);
  emlrtAddField(b_y, gd_y, "y_sw_last", 0);
  hd_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dy_sw_last);
  emlrtAssign(&hd_y, m11);
  emlrtAddField(b_y, hd_y, "dy_sw_last", 0);
  id_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.sDDA);
  emlrtAssign(&id_y, m11);
  emlrtAddField(b_y, id_y, "sDDA", 0);
  jd_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Jz);
  emlrtAssign(&jd_y, m11);
  emlrtAddField(b_y, jd_y, "Jz", 0);
  kd_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.Jz_tgt);
  emlrtAssign(&kd_y, m11);
  emlrtAddField(b_y, kd_y, "Jz_tgt", 0);
  ld_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dx);
  emlrtAssign(&ld_y, m11);
  emlrtAddField(b_y, ld_y, "dx", 0);
  md_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.dy);
  emlrtAssign(&md_y, m11);
  emlrtAddField(b_y, md_y, "dy", 0);
  nd_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.theta);
  emlrtAssign(&nd_y, m11);
  emlrtAddField(b_y, nd_y, "theta", 0);
  od_y = NULL;
  m11 = emlrtCreateDoubleScalar(moduleInstance->sysobj.tauPhase);
  emlrtAssign(&od_y, m11);
  emlrtAddField(b_y, od_y, "tauPhase", 0);
  pd_y = NULL;
  m11 = emlrtCreateNumericArray(1, iv31, mxDOUBLE_CLASS, mxREAL);
  pData = (real_T *)mxGetPr(m11);
  for (i = 0; i < 4; i++) {
    pData[i] = moduleInstance->sysobj.hd_q[i];
  }

  emlrtAssign(&pd_y, m11);
  emlrtAddField(b_y, pd_y, "hd_q", 0);
  emlrtSetCell(y, 0, b_y);
  qd_y = NULL;
  m11 = emlrtCreateLogicalScalar(moduleInstance->sysobj_not_empty);
  emlrtAssign(&qd_y, m11);
  emlrtSetCell(y, 1, qd_y);
  emlrtAssign(&st, y);
  return st;
}

static void emlrt_marshallIn(const mxArray *b_sysobj, const char_T *identifier,
  MikhailController_MARLO_Steeringv2_2 *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  b_emlrt_marshallIn(emlrtAlias(b_sysobj), &thisId, y);
  emlrtDestroyArray(&b_sysobj);
}

static void b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, MikhailController_MARLO_Steeringv2_2 *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[89] = { "isInitialized", "isReleased",
    "TunablePropsChanged", "isSim", "ps3Axes", "ps3Buttons", "u_lim", "ps3",
    "runTime", "isRun", "switch_phase_last", "switch_phase", "t0_step", "t_gain",
    "kp_st_leg", "kd_st_leg", "kp_sw_leg", "kd_sw_leg", "kp_hip", "kd_hip",
    "s_l_A", "s_l_B", "s_r_A", "s_r_B", "thres_lo", "thres_hi", "tau", "dx_gain",
    "dx_err_p_gain", "dx_err_d_gain", "dy_gain", "dy_err_p_gain",
    "dy_err_d_gain", "y0_offset", "y0_gain", "l0_leg", "l_ret", "l_ext_gain",
    "s_overlap", "isTest1", "isTest2", "isTest3", "isTest4", "isTest5",
    "isTest6", "isTest7", "isTest8", "isTest9", "isTest10", "isTest11",
    "isTest12", "x_offset", "steering_offset", "q_yaw_tgt", "y_offset",
    "EnableYawControl", "uHipGravity", "kp_rate", "kd_rate", "stanceLeg",
    "gaitMode", "t", "q_yaw", "z_offset", "x_est", "y_est", "dx_est", "dy_est",
    "dy_est_avg", "dx_tgt", "dy_tgt", "dx_est_last", "dy_est_last", "l_st_last",
    "dl_st_last", "l_sw_last", "dl_sw_last", "x_sw_last", "dx_sw_last",
    "y_sw_last", "dy_sw_last", "sDDA", "Jz", "Jz_tgt", "dx", "dy", "theta",
    "tauPhase", "hd_q" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 89, fieldNames, 0U, 0);
  thisId.fIdentifier = "isInitialized";
  y->isInitialized = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isInitialized")), &thisId);
  thisId.fIdentifier = "isReleased";
  y->isReleased = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isReleased")), &thisId);
  thisId.fIdentifier = "TunablePropsChanged";
  y->TunablePropsChanged = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "TunablePropsChanged")), &thisId);
  thisId.fIdentifier = "isSim";
  y->isSim = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isSim")), &thisId);
  thisId.fIdentifier = "ps3Axes";
  d_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal, u, 0,
    "ps3Axes")), &thisId, y->ps3Axes);
  thisId.fIdentifier = "ps3Buttons";
  e_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal, u, 0,
    "ps3Buttons")), &thisId, y->ps3Buttons);
  thisId.fIdentifier = "u_lim";
  y->u_lim = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "u_lim")), &thisId);
  thisId.fIdentifier = "ps3";
  g_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal, u, 0,
    "ps3")), &thisId, &y->ps3);
  thisId.fIdentifier = "runTime";
  y->runTime = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "runTime")), &thisId);
  thisId.fIdentifier = "isRun";
  y->isRun = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isRun")), &thisId);
  thisId.fIdentifier = "switch_phase_last";
  y->switch_phase_last = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "switch_phase_last")), &thisId);
  thisId.fIdentifier = "switch_phase";
  y->switch_phase = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "switch_phase")), &thisId);
  thisId.fIdentifier = "t0_step";
  y->t0_step = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "t0_step")), &thisId);
  thisId.fIdentifier = "t_gain";
  y->t_gain = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "t_gain")), &thisId);
  thisId.fIdentifier = "kp_st_leg";
  y->kp_st_leg = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "kp_st_leg")), &thisId);
  thisId.fIdentifier = "kd_st_leg";
  y->kd_st_leg = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "kd_st_leg")), &thisId);
  thisId.fIdentifier = "kp_sw_leg";
  y->kp_sw_leg = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "kp_sw_leg")), &thisId);
  thisId.fIdentifier = "kd_sw_leg";
  y->kd_sw_leg = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "kd_sw_leg")), &thisId);
  thisId.fIdentifier = "kp_hip";
  y->kp_hip = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "kp_hip")), &thisId);
  thisId.fIdentifier = "kd_hip";
  y->kd_hip = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "kd_hip")), &thisId);
  thisId.fIdentifier = "s_l_A";
  y->s_l_A = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "s_l_A")), &thisId);
  thisId.fIdentifier = "s_l_B";
  y->s_l_B = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "s_l_B")), &thisId);
  thisId.fIdentifier = "s_r_A";
  y->s_r_A = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "s_r_A")), &thisId);
  thisId.fIdentifier = "s_r_B";
  y->s_r_B = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "s_r_B")), &thisId);
  thisId.fIdentifier = "thres_lo";
  y->thres_lo = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "thres_lo")), &thisId);
  thisId.fIdentifier = "thres_hi";
  y->thres_hi = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "thres_hi")), &thisId);
  thisId.fIdentifier = "tau";
  y->tau = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "tau")), &thisId);
  thisId.fIdentifier = "dx_gain";
  y->dx_gain = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dx_gain")), &thisId);
  thisId.fIdentifier = "dx_err_p_gain";
  y->dx_err_p_gain = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dx_err_p_gain")), &thisId);
  thisId.fIdentifier = "dx_err_d_gain";
  y->dx_err_d_gain = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dx_err_d_gain")), &thisId);
  thisId.fIdentifier = "dy_gain";
  y->dy_gain = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dy_gain")), &thisId);
  thisId.fIdentifier = "dy_err_p_gain";
  y->dy_err_p_gain = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dy_err_p_gain")), &thisId);
  thisId.fIdentifier = "dy_err_d_gain";
  y->dy_err_d_gain = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dy_err_d_gain")), &thisId);
  thisId.fIdentifier = "y0_offset";
  y->y0_offset = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "y0_offset")), &thisId);
  thisId.fIdentifier = "y0_gain";
  y->y0_gain = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "y0_gain")), &thisId);
  thisId.fIdentifier = "l0_leg";
  y->l0_leg = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "l0_leg")), &thisId);
  thisId.fIdentifier = "l_ret";
  y->l_ret = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "l_ret")), &thisId);
  thisId.fIdentifier = "l_ext_gain";
  y->l_ext_gain = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "l_ext_gain")), &thisId);
  thisId.fIdentifier = "s_overlap";
  y->s_overlap = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "s_overlap")), &thisId);
  thisId.fIdentifier = "isTest1";
  y->isTest1 = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isTest1")), &thisId);
  thisId.fIdentifier = "isTest2";
  y->isTest2 = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isTest2")), &thisId);
  thisId.fIdentifier = "isTest3";
  y->isTest3 = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isTest3")), &thisId);
  thisId.fIdentifier = "isTest4";
  y->isTest4 = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isTest4")), &thisId);
  thisId.fIdentifier = "isTest5";
  y->isTest5 = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isTest5")), &thisId);
  thisId.fIdentifier = "isTest6";
  y->isTest6 = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isTest6")), &thisId);
  thisId.fIdentifier = "isTest7";
  y->isTest7 = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isTest7")), &thisId);
  thisId.fIdentifier = "isTest8";
  y->isTest8 = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isTest8")), &thisId);
  thisId.fIdentifier = "isTest9";
  y->isTest9 = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isTest9")), &thisId);
  thisId.fIdentifier = "isTest10";
  y->isTest10 = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isTest10")), &thisId);
  thisId.fIdentifier = "isTest11";
  y->isTest11 = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isTest11")), &thisId);
  thisId.fIdentifier = "isTest12";
  y->isTest12 = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isTest12")), &thisId);
  thisId.fIdentifier = "x_offset";
  y->x_offset = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "x_offset")), &thisId);
  thisId.fIdentifier = "steering_offset";
  y->steering_offset = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "steering_offset")), &thisId);
  thisId.fIdentifier = "q_yaw_tgt";
  y->q_yaw_tgt = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "q_yaw_tgt")), &thisId);
  thisId.fIdentifier = "y_offset";
  y->y_offset = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "y_offset")), &thisId);
  thisId.fIdentifier = "EnableYawControl";
  y->EnableYawControl = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "EnableYawControl")), &thisId);
  thisId.fIdentifier = "uHipGravity";
  y->uHipGravity = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "uHipGravity")), &thisId);
  thisId.fIdentifier = "kp_rate";
  y->kp_rate = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "kp_rate")), &thisId);
  thisId.fIdentifier = "kd_rate";
  y->kd_rate = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "kd_rate")), &thisId);
  thisId.fIdentifier = "stanceLeg";
  y->stanceLeg = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "stanceLeg")), &thisId);
  thisId.fIdentifier = "gaitMode";
  y->gaitMode = i_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "gaitMode")), &thisId);
  thisId.fIdentifier = "t";
  y->t = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal, u,
    0, "t")), &thisId);
  thisId.fIdentifier = "q_yaw";
  y->q_yaw = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "q_yaw")), &thisId);
  thisId.fIdentifier = "z_offset";
  y->z_offset = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "z_offset")), &thisId);
  thisId.fIdentifier = "x_est";
  y->x_est = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "x_est")), &thisId);
  thisId.fIdentifier = "y_est";
  y->y_est = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "y_est")), &thisId);
  thisId.fIdentifier = "dx_est";
  y->dx_est = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dx_est")), &thisId);
  thisId.fIdentifier = "dy_est";
  y->dy_est = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dy_est")), &thisId);
  thisId.fIdentifier = "dy_est_avg";
  y->dy_est_avg = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dy_est_avg")), &thisId);
  thisId.fIdentifier = "dx_tgt";
  y->dx_tgt = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dx_tgt")), &thisId);
  thisId.fIdentifier = "dy_tgt";
  y->dy_tgt = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dy_tgt")), &thisId);
  thisId.fIdentifier = "dx_est_last";
  y->dx_est_last = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dx_est_last")), &thisId);
  thisId.fIdentifier = "dy_est_last";
  y->dy_est_last = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dy_est_last")), &thisId);
  thisId.fIdentifier = "l_st_last";
  y->l_st_last = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "l_st_last")), &thisId);
  thisId.fIdentifier = "dl_st_last";
  y->dl_st_last = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dl_st_last")), &thisId);
  thisId.fIdentifier = "l_sw_last";
  y->l_sw_last = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "l_sw_last")), &thisId);
  thisId.fIdentifier = "dl_sw_last";
  y->dl_sw_last = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dl_sw_last")), &thisId);
  thisId.fIdentifier = "x_sw_last";
  y->x_sw_last = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "x_sw_last")), &thisId);
  thisId.fIdentifier = "dx_sw_last";
  y->dx_sw_last = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dx_sw_last")), &thisId);
  thisId.fIdentifier = "y_sw_last";
  y->y_sw_last = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "y_sw_last")), &thisId);
  thisId.fIdentifier = "dy_sw_last";
  y->dy_sw_last = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "dy_sw_last")), &thisId);
  thisId.fIdentifier = "sDDA";
  y->sDDA = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "sDDA")), &thisId);
  thisId.fIdentifier = "Jz";
  y->Jz = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "Jz")), &thisId);
  thisId.fIdentifier = "Jz_tgt";
  y->Jz_tgt = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "Jz_tgt")), &thisId);
  thisId.fIdentifier = "dx";
  y->dx = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "dx")), &thisId);
  thisId.fIdentifier = "dy";
  y->dy = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "dy")), &thisId);
  thisId.fIdentifier = "theta";
  y->theta = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "theta")), &thisId);
  thisId.fIdentifier = "tauPhase";
  y->tauPhase = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "tauPhase")), &thisId);
  thisId.fIdentifier = "hd_q";
  j_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal, u, 0,
    "hd_q")), &thisId, y->hd_q);
  emlrtDestroyArray(&u);
}

static boolean_T c_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  boolean_T y;
  y = l_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[4])
{
  m_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void e_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[17])
{
  n_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static real_T f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = o_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static void g_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, PS3Controller_2 *y)
{
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[19] = { "leftStickY", "rightStickX", "select",
    "l3", "r3", "start", "up", "right", "down", "left", "l2", "r2", "l1", "r1",
    "triangle", "circle", "cross", "square", "ps" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 19, fieldNames, 0U, 0);
  thisId.fIdentifier = "leftStickY";
  y->leftStickY = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "leftStickY")), &thisId);
  thisId.fIdentifier = "rightStickX";
  y->rightStickX = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "rightStickX")), &thisId);
  thisId.fIdentifier = "select";
  y->_select = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "select")), &thisId);
  thisId.fIdentifier = "l3";
  y->l3 = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "l3")), &thisId);
  thisId.fIdentifier = "r3";
  y->r3 = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "r3")), &thisId);
  thisId.fIdentifier = "start";
  y->start = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "start")), &thisId);
  thisId.fIdentifier = "up";
  y->up = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "up")), &thisId);
  thisId.fIdentifier = "right";
  y->right = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "right")), &thisId);
  thisId.fIdentifier = "down";
  y->down = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "down")), &thisId);
  thisId.fIdentifier = "left";
  y->left = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "left")), &thisId);
  thisId.fIdentifier = "l2";
  y->l2 = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "l2")), &thisId);
  thisId.fIdentifier = "r2";
  y->r2 = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "r2")), &thisId);
  thisId.fIdentifier = "l1";
  y->l1 = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "l1")), &thisId);
  thisId.fIdentifier = "r1";
  y->r1 = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "r1")), &thisId);
  thisId.fIdentifier = "triangle";
  y->triangle = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "triangle")), &thisId);
  thisId.fIdentifier = "circle";
  y->circle = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "circle")), &thisId);
  thisId.fIdentifier = "cross";
  y->cross = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "cross")), &thisId);
  thisId.fIdentifier = "square";
  y->square = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "square")), &thisId);
  thisId.fIdentifier = "ps";
  y->ps = h_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "ps")), &thisId);
  emlrtDestroyArray(&u);
}

static PS3Button h_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  PS3Button y;
  emlrtMsgIdentifier thisId;
  static const char * fieldNames[8] = { "value", "isPressed", "clickDuration",
    "clickCount", "time", "timePressed", "sampleInterval", "clickInterval" };

  thisId.fParent = parentId;
  emlrtCheckStructR2012b(emlrtRootTLSGlobal, parentId, u, 8, fieldNames, 0U, 0);
  thisId.fIdentifier = "value";
  y.value = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "value")), &thisId);
  thisId.fIdentifier = "isPressed";
  y.isPressed = c_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "isPressed")), &thisId);
  thisId.fIdentifier = "clickDuration";
  y.clickDuration = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "clickDuration")), &thisId);
  thisId.fIdentifier = "clickCount";
  y.clickCount = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "clickCount")), &thisId);
  thisId.fIdentifier = "time";
  y.time = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a(emlrtRootTLSGlobal,
    u, 0, "time")), &thisId);
  thisId.fIdentifier = "timePressed";
  y.timePressed = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "timePressed")), &thisId);
  thisId.fIdentifier = "sampleInterval";
  y.sampleInterval = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "sampleInterval")), &thisId);
  thisId.fIdentifier = "clickInterval";
  y.clickInterval = f_emlrt_marshallIn(emlrtAlias(emlrtGetFieldR2013a
    (emlrtRootTLSGlobal, u, 0, "clickInterval")), &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static GaitMode i_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  GaitMode y;
  static const int32_T enumValues[4] = { 0, 1, 2, 3 };

  static const char * enumNames[4] = { "Cross", "Circle", "Triangle", "Square" };

  emlrtCheckEnumR2012b(emlrtRootTLSGlobal, "GaitMode", 4, enumNames, enumValues);
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, parentId, u, "GaitMode", false, 0U,
    0);
  y = (GaitMode)emlrtGetEnumElementR2009a(u, 0);
  emlrtDestroyArray(&u);
  return y;
}

static void j_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId, real_T y[4])
{
  p_emlrt_marshallIn(emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static boolean_T k_emlrt_marshallIn(const mxArray *b_sysobj_not_empty, const
  char_T *identifier)
{
  boolean_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = identifier;
  thisId.fParent = NULL;
  y = c_emlrt_marshallIn(emlrtAlias(b_sysobj_not_empty), &thisId);
  emlrtDestroyArray(&b_sysobj_not_empty);
  return y;
}

static void mw__internal__setSimState__fcn(InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF
  *moduleInstance, const mxArray *st)
{
  const mxArray *u;
  u = emlrtAlias(st);
  emlrt_marshallIn(emlrtAlias(emlrtGetCell(emlrtRootTLSGlobal, u, 0)), "sysobj",
                   &moduleInstance->sysobj);
  moduleInstance->sysobj_not_empty = k_emlrt_marshallIn(emlrtAlias(emlrtGetCell
    (emlrtRootTLSGlobal, u, 1)), "sysobj_not_empty");
  emlrtDestroyArray(&u);
  emlrtDestroyArray(&st);
}

static const mxArray *message(const mxArray *b, const mxArray *c, emlrtMCInfo
  *location)
{
  const mxArray *pArrays[2];
  const mxArray *m13;
  pArrays[0] = b;
  pArrays[1] = c;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m13, 2, pArrays,
    "message", true, location);
}

static void error(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "error", true,
                        location);
}

static const mxArray *b_message(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  const mxArray *m14;
  pArray = b;
  return emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 1, &m14, 1, &pArray,
    "message", true, location);
}

static void warning(const mxArray *b, emlrtMCInfo *location)
{
  const mxArray *pArray;
  pArray = b;
  emlrtCallMATLABR2012b(emlrtRootTLSGlobal, 0, NULL, 1, &pArray, "warning", true,
                        location);
}

static boolean_T l_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  boolean_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "logical", false, 0U,
    0);
  ret = *mxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void m_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[4])
{
  int32_T iv32[2];
  int32_T i12;
  for (i12 = 0; i12 < 2; i12++) {
    iv32[i12] = 1 + 3 * i12;
  }

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    iv32);
  for (i12 = 0; i12 < 4; i12++) {
    ret[i12] = (*(real_T (*)[4])mxGetData(src))[i12];
  }

  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[17])
{
  int32_T iv33[2];
  int32_T i13;
  for (i13 = 0; i13 < 2; i13++) {
    iv33[i13] = 1 + (i13 << 4);
  }

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    iv33);
  for (i13 = 0; i13 < 17; i13++) {
    ret[i13] = (*(real_T (*)[17])mxGetData(src))[i13];
  }

  emlrtDestroyArray(&src);
}

static real_T o_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  real_T ret;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 0U, 0);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static void p_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId, real_T ret[4])
{
  int32_T iv34[1];
  int32_T i14;
  iv34[0] = 4;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 1U,
    iv34);
  for (i14 = 0; i14 < 4; i14++) {
    ret[i14] = (*(real_T (*)[4])mxGetData(src))[i14];
  }

  emlrtDestroyArray(&src);
}

static void b_acos(creal_T *b_x)
{
  creal_T v;
  creal_T u;
  real_T yi;
  boolean_T xneg;
  real_T t;
  if (b_x->im == 0.0 && !(muDoubleScalarAbs(b_x->re) > 1.0)) {
    b_x->re = muDoubleScalarAcos(b_x->re);
    b_x->im = 0.0;
  } else {
    v.re = 1.0 + b_x->re;
    v.im = b_x->im;
    eml_scalar_sqrt(&v);
    if (b_x->im != 0.0) {
      u.re = 1.0 - b_x->re;
      u.im = -b_x->im;
      eml_scalar_sqrt(&u);
    } else {
      u.re = 1.0 - b_x->re;
      u.im = b_x->im;
      eml_scalar_sqrt(&u);
    }

    yi = u.im * v.re - u.re * v.im;
    xneg = yi < 0.0;
    if (xneg) {
      yi = -yi;
    }

    if (yi >= 2.68435456E+8) {
      yi = muDoubleScalarLog(yi) + 0.69314718055994529;
    } else if (yi > 2.0) {
      yi = muDoubleScalarLog(2.0 * yi + 1.0 / (muDoubleScalarSqrt(yi * yi + 1.0)
        + yi));
    } else {
      t = yi * yi;
      yi += t / (1.0 + muDoubleScalarSqrt(1.0 + t));
      t = muDoubleScalarAbs(yi);
      if (t > 4.503599627370496E+15 || !(!muDoubleScalarIsInf(yi) &&
           !muDoubleScalarIsNaN(yi))) {
        yi = muDoubleScalarLog(1.0 + yi);
      } else {
        if (!(t < 2.2204460492503131E-16)) {
          yi = muDoubleScalarLog(1.0 + yi) * (yi / (1.0 + yi - 1.0));
        }
      }
    }

    if (xneg) {
      yi = -yi;
    }

    if (b_x->re == 0.0) {
      t = 1.5707963267948966;
    } else {
      t = 2.0 * muDoubleScalarAtan2(muDoubleScalarAbs(u.re), muDoubleScalarAbs
        (v.re));
      if (u.re < 0.0 != v.re < 0.0) {
        t = -t;
      }
    }

    b_x->re = t;
    b_x->im = yi;
  }
}

static void eml_scalar_sqrt(creal_T *b_x)
{
  real_T absxi;
  real_T absxr;
  if (b_x->im == 0.0) {
    if (b_x->re < 0.0) {
      absxi = 0.0;
      absxr = muDoubleScalarSqrt(muDoubleScalarAbs(b_x->re));
    } else {
      absxi = muDoubleScalarSqrt(b_x->re);
      absxr = 0.0;
    }
  } else if (b_x->re == 0.0) {
    if (b_x->im < 0.0) {
      absxi = muDoubleScalarSqrt(-b_x->im / 2.0);
      absxr = -absxi;
    } else {
      absxi = muDoubleScalarSqrt(b_x->im / 2.0);
      absxr = absxi;
    }
  } else if (muDoubleScalarIsNaN(b_x->re) || muDoubleScalarIsNaN(b_x->im)) {
    absxi = rtNaN;
    absxr = rtNaN;
  } else if (muDoubleScalarIsInf(b_x->im)) {
    absxi = rtInf;
    absxr = b_x->im;
  } else if (muDoubleScalarIsInf(b_x->re)) {
    if (b_x->re < 0.0) {
      absxi = 0.0;
      absxr = rtInf;
    } else {
      absxi = rtInf;
      absxr = 0.0;
    }
  } else {
    absxr = muDoubleScalarAbs(b_x->re);
    absxi = muDoubleScalarAbs(b_x->im);
    if (absxr > 4.4942328371557893E+307 || absxi > 4.4942328371557893E+307) {
      absxr *= 0.5;
      absxi *= 0.5;
      absxi = muDoubleScalarHypot(absxr, absxi);
      if (absxi > absxr) {
        absxi = muDoubleScalarSqrt(absxi) * muDoubleScalarSqrt(1.0 + absxr /
          absxi);
      } else {
        absxi = muDoubleScalarSqrt(absxi) * 1.4142135623730951;
      }
    } else {
      absxi = muDoubleScalarSqrt((muDoubleScalarHypot(absxr, absxi) + absxr) *
        0.5);
    }

    if (b_x->re > 0.0) {
      absxr = 0.5 * (b_x->im / absxi);
    } else {
      if (b_x->im < 0.0) {
        absxr = -absxi;
      } else {
        absxr = absxi;
      }

      absxi = 0.5 * (b_x->im / absxr);
    }
  }

  b_x->re = absxi;
  b_x->im = absxr;
}

static void b_asin(real_T *b_x)
{
  if (*b_x < -1.0 || 1.0 < *b_x) {
    eml_error();
  }

  *b_x = muDoubleScalarAsin(*b_x);
}

static void mldivide(real_T B[24])
{
  int32_T xi;
  static int8_T iv35[4] = { 3, 3, 4, 4 };

  int32_T jBcol;
  int32_T k;
  real_T temp;
  int32_T kAcol;
  int32_T i;
  static real_T dv13[16] = { 1.0, 0.5, 0.0, 0.0, -1.0, 1.0, 0.0, 0.0, 0.0, 0.0,
    1.0, 0.5, 0.0, 0.0, -1.0, 1.0 };

  for (xi = 0; xi < 3; xi++) {
    if (iv35[xi] != xi + 1) {
      jBcol = iv35[xi] - 1;
      for (k = 0; k < 6; k++) {
        temp = B[xi + (k << 2)];
        B[xi + (k << 2)] = B[jBcol + (k << 2)];
        B[jBcol + (k << 2)] = temp;
      }
    }
  }

  for (xi = 0; xi < 6; xi++) {
    jBcol = xi << 2;
    for (k = 0; k < 4; k++) {
      kAcol = k << 2;
      if (B[k + jBcol] != 0.0) {
        for (i = k + 1; i + 1 < 5; i++) {
          B[i + jBcol] -= B[k + jBcol] * dv13[i + kAcol];
        }
      }
    }
  }

  for (xi = 0; xi < 6; xi++) {
    jBcol = xi << 2;
    for (k = 3; k > -1; k += -1) {
      kAcol = k << 2;
      if (B[k + jBcol] != 0.0) {
        B[k + jBcol] /= dv13[k + kAcol];
        for (i = 0; i + 1 <= k; i++) {
          B[i + jBcol] -= B[k + jBcol] * dv13[i + kAcol];
        }
      }
    }
  }
}

/* CGXE Glue Code */
static void mdlOutputs_KVvGQhP9zVmL5NQhzh0cxF(SimStruct *S, int_T tid)
{
  InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance;
  moduleInstance = (InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_outputs(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static void mdlInitialize_KVvGQhP9zVmL5NQhzh0cxF(SimStruct *S)
{
  InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance;
  moduleInstance = (InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_initialize(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static void mdlUpdate_KVvGQhP9zVmL5NQhzh0cxF(SimStruct *S, int_T tid)
{
  InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance;
  moduleInstance = (InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_update(moduleInstance);
  CGXERT_LEAVE_CHECK();
}

static mxArray* getSimState_KVvGQhP9zVmL5NQhzh0cxF(SimStruct *S)
{
  InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance;
  mxArray* mxSS;
  moduleInstance = (InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mxSS = (mxArray *) mw__internal__getSimState__fcn(moduleInstance);
  CGXERT_LEAVE_CHECK();
  return mxSS;
}

static void setSimState_KVvGQhP9zVmL5NQhzh0cxF(SimStruct *S, const mxArray *ss)
{
  InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance;
  moduleInstance = (InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  mw__internal__setSimState__fcn(moduleInstance, emlrtAlias(ss));
  CGXERT_LEAVE_CHECK();
}

static void mdlTerminate_KVvGQhP9zVmL5NQhzh0cxF(SimStruct *S)
{
  InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance;
  moduleInstance = (InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *)ssGetUserData(S);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_terminate(moduleInstance);
  CGXERT_LEAVE_CHECK();
  free((void *)moduleInstance);
  ssSetUserData(S, NULL);
}

static void mdlStart_KVvGQhP9zVmL5NQhzh0cxF(SimStruct *S)
{
  InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *moduleInstance;
  moduleInstance = (InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF *)calloc(1, sizeof
    (InstanceStruct_KVvGQhP9zVmL5NQhzh0cxF));
  moduleInstance->S = S;
  ssSetUserData(S, (void *)moduleInstance);
  CGXERT_ENTER_CHECK();
  cgxe_mdl_start(moduleInstance);
  CGXERT_LEAVE_CHECK();

  {
    uint_T options = ssGetOptions(S);
    options |= SS_OPTION_RUNTIME_EXCEPTION_FREE_CODE;
    ssSetOptions(S, options);
  }

  ssSetmdlOutputs(S, mdlOutputs_KVvGQhP9zVmL5NQhzh0cxF);
  ssSetmdlInitializeConditions(S, mdlInitialize_KVvGQhP9zVmL5NQhzh0cxF);
  ssSetmdlUpdate(S, mdlUpdate_KVvGQhP9zVmL5NQhzh0cxF);
  ssSetmdlTerminate(S, mdlTerminate_KVvGQhP9zVmL5NQhzh0cxF);
}

static void mdlProcessParameters_KVvGQhP9zVmL5NQhzh0cxF(SimStruct *S)
{
}

void method_dispatcher_KVvGQhP9zVmL5NQhzh0cxF(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_KVvGQhP9zVmL5NQhzh0cxF(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_KVvGQhP9zVmL5NQhzh0cxF(S);
    break;

   case SS_CALL_MDL_GET_SIM_STATE:
    *((mxArray**) data) = getSimState_KVvGQhP9zVmL5NQhzh0cxF(S);
    break;

   case SS_CALL_MDL_SET_SIM_STATE:
    setSimState_KVvGQhP9zVmL5NQhzh0cxF(S, (const mxArray *) data);
    break;

   default:
    /* Unhandled method */
    /*
       sf_mex_error_message("Stateflow Internal Error:\n"
       "Error calling method dispatcher for module: KVvGQhP9zVmL5NQhzh0cxF.\n"
       "Can't handle method %d.\n", method);
     */
    break;
  }
}

int autoInfer_dispatcher_KVvGQhP9zVmL5NQhzh0cxF(mxArray* plhs[], const char
  * commandName)
{
  if (strcmp(commandName, "NameResolution") == 0) {
    plhs[0] = (mxArray*) mw__internal__name__resolution__fcn();
    return 1;
  }

  if (strcmp(commandName, "AutoInfer") == 0) {
    plhs[0] = (mxArray*) mw__internal__autoInference__fcn();
    return 1;
  }

  return 0;
}

mxArray *cgxe_KVvGQhP9zVmL5NQhzh0cxF_BuildInfoUpdate(void)
{
  mxArray * mxBIArgs;
  mxArray * elem_1;
  mxArray * elem_2;
  mxArray * elem_3;
  mxArray * elem_4;
  mxArray * elem_5;
  mxArray * elem_6;
  mxArray * elem_7;
  mxArray * elem_8;
  mxArray * elem_9;
  mxBIArgs = mxCreateCellMatrix(1,3);
  elem_1 = mxCreateCellMatrix(1,6);
  elem_2 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,0,elem_2);
  elem_3 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,1,elem_3);
  elem_4 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,2,elem_4);
  elem_5 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,3,elem_5);
  elem_6 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,4,elem_6);
  elem_7 = mxCreateCellMatrix(0,0);
  mxSetCell(elem_1,5,elem_7);
  mxSetCell(mxBIArgs,0,elem_1);
  elem_8 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,1,elem_8);
  elem_9 = mxCreateCellMatrix(1,0);
  mxSetCell(mxBIArgs,2,elem_9);
  return mxBIArgs;
}
