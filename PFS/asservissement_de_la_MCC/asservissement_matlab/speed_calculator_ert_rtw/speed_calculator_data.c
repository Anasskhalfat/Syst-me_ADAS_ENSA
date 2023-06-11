/*
 * File: speed_calculator_data.c
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

/* Block parameters (default storage) */
P_speed_calculator_T speed_calculator_P = {
  /* Mask Parameter: DiscretePIDController_D
   * Referenced by: '<S27>/Derivative Gain'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_I
   * Referenced by: '<S30>/Integral Gain'
   */
  100.0,

  /* Mask Parameter: DiscretePIDController_InitialCo
   * Referenced by: '<S28>/Filter'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_Initial_h
   * Referenced by: '<S33>/Integrator'
   */
  0.0,

  /* Mask Parameter: DiscretePIDController_N
   * Referenced by: '<S36>/Filter Coefficient'
   */
  100.0,

  /* Mask Parameter: DiscretePIDController_P
   * Referenced by: '<S38>/Proportional Gain'
   */
  5.0,

  /* Expression: 1
   * Referenced by: '<Root>/direction'
   */
  1.0,

  /* Expression: 5
   * Referenced by: '<Root>/Step1'
   */
  5.0,

  /* Expression: 100
   * Referenced by: '<Root>/Step1'
   */
  100.0,

  /* Expression: 200
   * Referenced by: '<Root>/Step1'
   */
  200.0,

  /* Expression: 1
   * Referenced by: '<Root>/Step'
   */
  1.0,

  /* Expression: -100
   * Referenced by: '<Root>/Step'
   */
  -100.0,

  /* Expression: 0
   * Referenced by: '<Root>/Step'
   */
  0.0,

  /* Computed Parameter: Integrator_gainval
   * Referenced by: '<S33>/Integrator'
   */
  0.03,

  /* Computed Parameter: Filter_gainval
   * Referenced by: '<S28>/Filter'
   */
  0.03
};

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
