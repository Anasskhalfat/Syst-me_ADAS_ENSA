/*
 * File: speed_calculator.c
 *
 * Code generated for Simulink model 'speed_calculator'.
 *
 * Model version                  : 1.29
 * Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
 * C/C++ source code generated on : Tue May 23 12:30:53 2023
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Atmel->AVR
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "speed_calculator.h"
#include "speed_calculator_private.h"

/* Block signals (default storage) */
B_speed_calculator_T speed_calculator_B;

/* Block states (default storage) */
DW_speed_calculator_T speed_calculator_DW;

/* Real-time model */
static RT_MODEL_speed_calculator_T speed_calculator_M_;
RT_MODEL_speed_calculator_T *const speed_calculator_M = &speed_calculator_M_;
real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void speed_calculator_step(void)
{
  b_dsp_FIRFilter_0_speed_calcu_T *obj_1;
  b_dspcodegen_FIRFilter_speed__T *obj_0;
  codertarget_arduinobase_inter_T *obj;
  real_T rtb_FilterCoefficient;
  real_T rtb_Sum_c;
  real_T u0;
  real_T zCurr;
  int16_T n;
  uint8_T tmp;

  /* MATLABSystem: '<Root>/Digital Output' incorporates:
   *  Constant: '<Root>/direction'
   */
  rtb_Sum_c = rt_roundd_snf(speed_calculator_P.direction_Value);
  if (rtb_Sum_c < 256.0) {
    if (rtb_Sum_c >= 0.0) {
      tmp = (uint8_T)rtb_Sum_c;
    } else {
      tmp = 0U;
    }
  } else {
    tmp = MAX_uint8_T;
  }

  writeDigitalPin(4, tmp);

  /* End of MATLABSystem: '<Root>/Digital Output' */

  /* S-Function (codeurMoteur): '<Root>/S-Function Builder' */
  codeurMoteur_Outputs_wrapper(&speed_calculator_B.SFunctionBuilder_o1,
    &speed_calculator_B.SFunctionBuilder_o2,
    &speed_calculator_DW.SFunctionBuilder_DSTATE);

  /* Step: '<Root>/Step1' incorporates:
   *  Step: '<Root>/Step'
   */
  rtb_Sum_c = ((speed_calculator_M->Timing.clockTick0) * 0.03);
  if (rtb_Sum_c < speed_calculator_P.Step1_Time) {
    rtb_FilterCoefficient = speed_calculator_P.Step1_Y0;
  } else {
    rtb_FilterCoefficient = speed_calculator_P.Step1_YFinal;
  }

  /* End of Step: '<Root>/Step1' */

  /* Step: '<Root>/Step' */
  if (rtb_Sum_c < speed_calculator_P.Step_Time) {
    rtb_Sum_c = speed_calculator_P.Step_Y0;
  } else {
    rtb_Sum_c = speed_calculator_P.Step_YFinal;
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  rtb_Sum_c = (rtb_FilterCoefficient + rtb_Sum_c) -
    speed_calculator_B.SFunctionBuilder_o2;

  /* Gain: '<S36>/Filter Coefficient' incorporates:
   *  DiscreteIntegrator: '<S28>/Filter'
   *  Gain: '<S27>/Derivative Gain'
   *  Sum: '<S28>/SumD'
   */
  rtb_FilterCoefficient = (speed_calculator_P.DiscretePIDController_D *
    rtb_Sum_c - speed_calculator_DW.Filter_DSTATE) *
    speed_calculator_P.DiscretePIDController_N;

  /* MATLABSystem: '<Root>/PWM' */
  obj = &speed_calculator_DW.obj_l;
  obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);

  /* Sum: '<S42>/Sum' incorporates:
   *  DiscreteIntegrator: '<S33>/Integrator'
   *  Gain: '<S38>/Proportional Gain'
   */
  u0 = (speed_calculator_P.DiscretePIDController_P * rtb_Sum_c +
        speed_calculator_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  /* MATLABSystem: '<Root>/PWM' */
  if (!(u0 < 255.0)) {
    u0 = 255.0;
  }

  if (!(u0 > 0.0)) {
    u0 = 0.0;
  }

  MW_PWM_SetDutyCycle(speed_calculator_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE, u0);

  /* MATLABSystem: '<Root>/Lowpass Filter' */
  obj_0 = speed_calculator_DW.obj.FilterObj;
  if (obj_0->isInitialized != 1L) {
    obj_0->isSetupComplete = false;
    obj_0->isInitialized = 1L;
    obj_0->isSetupComplete = true;

    /* System object Initialization function: dsp.FIRFilter */
    for (n = 0; n < 50; n++) {
      obj_0->cSFunObject.W0_states[n] = obj_0->cSFunObject.P0_InitialStates;
    }
  }

  obj_1 = &obj_0->cSFunObject;

  /* System object Outputs function: dsp.FIRFilter */
  /* load input sample */
  u0 = speed_calculator_B.SFunctionBuilder_o2;
  for (n = 0; n < 50; n++) {
    /* shift state */
    zCurr = u0;
    u0 = obj_1->W0_states[(int32_T)n];
    obj_1->W0_states[(int32_T)n] = zCurr;

    /* compute one tap */
  }

  /* End of MATLABSystem: '<Root>/Lowpass Filter' */

  /* Update for S-Function (codeurMoteur): '<Root>/S-Function Builder' */
  /* compute last tap */
  /* store output sample */

  /* S-Function "codeurMoteur_wrapper" Block: <Root>/S-Function Builder */
  codeurMoteur_Update_wrapper(&speed_calculator_B.SFunctionBuilder_o1,
    &speed_calculator_B.SFunctionBuilder_o2,
    &speed_calculator_DW.SFunctionBuilder_DSTATE);

  /* Update for DiscreteIntegrator: '<S33>/Integrator' incorporates:
   *  Gain: '<S30>/Integral Gain'
   */
  speed_calculator_DW.Integrator_DSTATE +=
    speed_calculator_P.DiscretePIDController_I * rtb_Sum_c *
    speed_calculator_P.Integrator_gainval;

  /* Update for DiscreteIntegrator: '<S28>/Filter' */
  speed_calculator_DW.Filter_DSTATE += speed_calculator_P.Filter_gainval *
    rtb_FilterCoefficient;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.03, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  speed_calculator_M->Timing.clockTick0++;
}

/* Model initialize function */
void speed_calculator_initialize(void)
{
  {
    b_dspcodegen_FIRFilter_speed__T *iobj_0;
    codertarget_arduinobase_inter_T *obj;
    int16_T i;
    static const real_T tmp[51] = { 0.00013233693783970053,
      0.00025266413608115263, 0.00047939152109463204, 0.00082357156933653543,
      0.0013185308784448779, 0.001999609214080004, 0.0029023333245447704,
      0.0040601989986275185, 0.0055021695834974078, 0.0072500386563707645,
      0.0093158357706008537, 0.011699473418889068, 0.014386837631941346,
      0.017348512187691491, 0.020539296901458431, 0.023898635120609947,
      0.027352007123658595, 0.030813278762371665, 0.034187923582642596,
      0.037376967632494228, 0.040281445134898404, 0.042807105647114124,
      0.04486908375716743, 0.046396233875745971, 0.047334846619989927,
      0.0476514990967333, 0.047334846619989927, 0.046396233875745971,
      0.04486908375716743, 0.042807105647114124, 0.040281445134898404,
      0.037376967632494228, 0.034187923582642596, 0.030813278762371665,
      0.027352007123658595, 0.023898635120609947, 0.020539296901458431,
      0.017348512187691491, 0.014386837631941346, 0.011699473418889068,
      0.0093158357706008537, 0.0072500386563707645, 0.0055021695834974078,
      0.0040601989986275185, 0.0029023333245447704, 0.001999609214080004,
      0.0013185308784448779, 0.00082357156933653543, 0.00047939152109463204,
      0.00025266413608115263, 0.00013233693783970053 };

    /* Start for S-Function (codeurMoteur): '<Root>/S-Function Builder' */

    /* S-Function Block: <Root>/S-Function Builder */
    codeurMoteur_Start_wrapper(&speed_calculator_DW.SFunctionBuilder_DSTATE);

    /* InitializeConditions for S-Function (codeurMoteur): '<Root>/S-Function Builder' */

    /* S-Function Block: <Root>/S-Function Builder */
    {
      real_T initVector[1] = { 0 };

      {
        int_T i1;
        for (i1=0; i1 < 1; i1++) {
          speed_calculator_DW.SFunctionBuilder_DSTATE = initVector[0];
        }
      }
    }

    /* InitializeConditions for DiscreteIntegrator: '<S33>/Integrator' */
    speed_calculator_DW.Integrator_DSTATE =
      speed_calculator_P.DiscretePIDController_Initial_h;

    /* InitializeConditions for DiscreteIntegrator: '<S28>/Filter' */
    speed_calculator_DW.Filter_DSTATE =
      speed_calculator_P.DiscretePIDController_InitialCo;

    /* Start for MATLABSystem: '<Root>/Digital Output' */
    speed_calculator_DW.obj_h.matlabCodegenIsDeleted = false;
    speed_calculator_DW.obj_h.isInitialized = 1L;
    digitalIOSetup(4, 1);
    speed_calculator_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    speed_calculator_DW.obj_l.matlabCodegenIsDeleted = true;
    speed_calculator_DW.obj_l.isInitialized = 0L;
    speed_calculator_DW.obj_l.matlabCodegenIsDeleted = false;
    obj = &speed_calculator_DW.obj_l;
    speed_calculator_DW.obj_l.isSetupComplete = false;
    speed_calculator_DW.obj_l.isInitialized = 1L;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(6UL, 0.0, 0.0);
    speed_calculator_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Lowpass Filter' */
    speed_calculator_DW.obj._pobj0.matlabCodegenIsDeleted = true;
    speed_calculator_DW.obj.matlabCodegenIsDeleted = true;
    speed_calculator_DW.obj.isInitialized = 0L;
    speed_calculator_DW.obj.NumChannels = -1L;
    speed_calculator_DW.obj.matlabCodegenIsDeleted = false;
    speed_calculator_DW.obj.isSetupComplete = false;
    speed_calculator_DW.obj.isInitialized = 1L;
    iobj_0 = &speed_calculator_DW.obj._pobj0;
    iobj_0->isInitialized = 0L;

    /* System object Constructor function: dsp.FIRFilter */
    iobj_0->cSFunObject.P0_InitialStates = 0.0;
    for (i = 0; i < 51; i++) {
      iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
    }

    iobj_0->matlabCodegenIsDeleted = false;
    speed_calculator_DW.obj.FilterObj = iobj_0;
    speed_calculator_DW.obj.NumChannels = 1L;
    speed_calculator_DW.obj.isSetupComplete = true;

    /* End of Start for MATLABSystem: '<Root>/Lowpass Filter' */

    /* InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */
    iobj_0 = speed_calculator_DW.obj.FilterObj;
    if (iobj_0->isInitialized == 1L) {
      /* System object Initialization function: dsp.FIRFilter */
      for (i = 0; i < 50; i++) {
        iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
      }
    }

    /* End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter' */
  }
}

/* Model terminate function */
void speed_calculator_terminate(void)
{
  b_dspcodegen_FIRFilter_speed__T *obj_0;
  codertarget_arduinobase_inter_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Digital Output' */
  if (!speed_calculator_DW.obj_h.matlabCodegenIsDeleted) {
    speed_calculator_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output' */

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj = &speed_calculator_DW.obj_l;
  if (!speed_calculator_DW.obj_l.matlabCodegenIsDeleted) {
    speed_calculator_DW.obj_l.matlabCodegenIsDeleted = true;
    if ((speed_calculator_DW.obj_l.isInitialized == 1L) &&
        speed_calculator_DW.obj_l.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_SetDutyCycle(speed_calculator_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(6UL);
      MW_PWM_Close(speed_calculator_DW.obj_l.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for MATLABSystem: '<Root>/Lowpass Filter' */
  if (!speed_calculator_DW.obj.matlabCodegenIsDeleted) {
    speed_calculator_DW.obj.matlabCodegenIsDeleted = true;
    if ((speed_calculator_DW.obj.isInitialized == 1L) &&
        speed_calculator_DW.obj.isSetupComplete) {
      obj_0 = speed_calculator_DW.obj.FilterObj;
      if (obj_0->isInitialized == 1L) {
        obj_0->isInitialized = 2L;
      }

      speed_calculator_DW.obj.NumChannels = -1L;
    }
  }

  obj_0 = &speed_calculator_DW.obj._pobj0;
  if (!obj_0->matlabCodegenIsDeleted) {
    obj_0->matlabCodegenIsDeleted = true;
    if (obj_0->isInitialized == 1L) {
      obj_0->isInitialized = 2L;
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Lowpass Filter' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
