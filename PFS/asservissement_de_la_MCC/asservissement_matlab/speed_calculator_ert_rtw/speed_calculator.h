/*
 * File: speed_calculator.h
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

#ifndef RTW_HEADER_speed_calculator_h_
#define RTW_HEADER_speed_calculator_h_
#include <math.h>
#include <stddef.h>
#ifndef speed_calculator_COMMON_INCLUDES_
#define speed_calculator_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_PWM.h"
#endif                                 /* speed_calculator_COMMON_INCLUDES_ */

#include "speed_calculator_types.h"
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T SFunctionBuilder_o1;          /* '<Root>/S-Function Builder' */
  real_T SFunctionBuilder_o2;          /* '<Root>/S-Function Builder' */
} B_speed_calculator_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  dsp_LowpassFilter_speed_calcu_T obj; /* '<Root>/Lowpass Filter' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Output' */
  codertarget_arduinobase_inter_T obj_l;/* '<Root>/PWM' */
  real_T SFunctionBuilder_DSTATE;      /* '<Root>/S-Function Builder' */
  real_T Integrator_DSTATE;            /* '<S33>/Integrator' */
  real_T Filter_DSTATE;                /* '<S28>/Filter' */
  boolean_T isInitialized;             /* '<Root>/Lowpass Filter' */
} DW_speed_calculator_T;

/* Parameters (default storage) */
struct P_speed_calculator_T_ {
  real_T DiscretePIDController_D;     /* Mask Parameter: DiscretePIDController_D
                                       * Referenced by: '<S27>/Derivative Gain'
                                       */
  real_T DiscretePIDController_I;     /* Mask Parameter: DiscretePIDController_I
                                       * Referenced by: '<S30>/Integral Gain'
                                       */
  real_T DiscretePIDController_InitialCo;
                              /* Mask Parameter: DiscretePIDController_InitialCo
                               * Referenced by: '<S28>/Filter'
                               */
  real_T DiscretePIDController_Initial_h;
                              /* Mask Parameter: DiscretePIDController_Initial_h
                               * Referenced by: '<S33>/Integrator'
                               */
  real_T DiscretePIDController_N;     /* Mask Parameter: DiscretePIDController_N
                                       * Referenced by: '<S36>/Filter Coefficient'
                                       */
  real_T DiscretePIDController_P;     /* Mask Parameter: DiscretePIDController_P
                                       * Referenced by: '<S38>/Proportional Gain'
                                       */
  real_T direction_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/direction'
                                        */
  real_T Step1_Time;                   /* Expression: 5
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 100
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 200
                                        * Referenced by: '<Root>/Step1'
                                        */
  real_T Step_Time;                    /* Expression: 1
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: -100
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 0
                                        * Referenced by: '<Root>/Step'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S33>/Integrator'
                                        */
  real_T Filter_gainval;               /* Computed Parameter: Filter_gainval
                                        * Referenced by: '<S28>/Filter'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_speed_calculator_T {
  const char_T *errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
  } Timing;
};

/* Block parameters (default storage) */
extern P_speed_calculator_T speed_calculator_P;

/* Block signals (default storage) */
extern B_speed_calculator_T speed_calculator_B;

/* Block states (default storage) */
extern DW_speed_calculator_T speed_calculator_DW;

/* Model entry point functions */
extern void speed_calculator_initialize(void);
extern void speed_calculator_step(void);
extern void speed_calculator_terminate(void);

/* Real-time Model object */
extern RT_MODEL_speed_calculator_T *const speed_calculator_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Display1' : Unused code path elimination
 * Block '<Root>/Display2' : Unused code path elimination
 * Block '<Root>/Scope' : Unused code path elimination
 */

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
 * '<Root>' : 'speed_calculator'
 * '<S1>'   : 'speed_calculator/Discrete PID Controller'
 * '<S2>'   : 'speed_calculator/Discrete PID Controller/Anti-windup'
 * '<S3>'   : 'speed_calculator/Discrete PID Controller/D Gain'
 * '<S4>'   : 'speed_calculator/Discrete PID Controller/Filter'
 * '<S5>'   : 'speed_calculator/Discrete PID Controller/Filter ICs'
 * '<S6>'   : 'speed_calculator/Discrete PID Controller/I Gain'
 * '<S7>'   : 'speed_calculator/Discrete PID Controller/Ideal P Gain'
 * '<S8>'   : 'speed_calculator/Discrete PID Controller/Ideal P Gain Fdbk'
 * '<S9>'   : 'speed_calculator/Discrete PID Controller/Integrator'
 * '<S10>'  : 'speed_calculator/Discrete PID Controller/Integrator ICs'
 * '<S11>'  : 'speed_calculator/Discrete PID Controller/N Copy'
 * '<S12>'  : 'speed_calculator/Discrete PID Controller/N Gain'
 * '<S13>'  : 'speed_calculator/Discrete PID Controller/P Copy'
 * '<S14>'  : 'speed_calculator/Discrete PID Controller/Parallel P Gain'
 * '<S15>'  : 'speed_calculator/Discrete PID Controller/Reset Signal'
 * '<S16>'  : 'speed_calculator/Discrete PID Controller/Saturation'
 * '<S17>'  : 'speed_calculator/Discrete PID Controller/Saturation Fdbk'
 * '<S18>'  : 'speed_calculator/Discrete PID Controller/Sum'
 * '<S19>'  : 'speed_calculator/Discrete PID Controller/Sum Fdbk'
 * '<S20>'  : 'speed_calculator/Discrete PID Controller/Tracking Mode'
 * '<S21>'  : 'speed_calculator/Discrete PID Controller/Tracking Mode Sum'
 * '<S22>'  : 'speed_calculator/Discrete PID Controller/Tsamp - Integral'
 * '<S23>'  : 'speed_calculator/Discrete PID Controller/Tsamp - Ngain'
 * '<S24>'  : 'speed_calculator/Discrete PID Controller/postSat Signal'
 * '<S25>'  : 'speed_calculator/Discrete PID Controller/preSat Signal'
 * '<S26>'  : 'speed_calculator/Discrete PID Controller/Anti-windup/Passthrough'
 * '<S27>'  : 'speed_calculator/Discrete PID Controller/D Gain/Internal Parameters'
 * '<S28>'  : 'speed_calculator/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S29>'  : 'speed_calculator/Discrete PID Controller/Filter ICs/Internal IC - Filter'
 * '<S30>'  : 'speed_calculator/Discrete PID Controller/I Gain/Internal Parameters'
 * '<S31>'  : 'speed_calculator/Discrete PID Controller/Ideal P Gain/Passthrough'
 * '<S32>'  : 'speed_calculator/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S33>'  : 'speed_calculator/Discrete PID Controller/Integrator/Discrete'
 * '<S34>'  : 'speed_calculator/Discrete PID Controller/Integrator ICs/Internal IC'
 * '<S35>'  : 'speed_calculator/Discrete PID Controller/N Copy/Disabled'
 * '<S36>'  : 'speed_calculator/Discrete PID Controller/N Gain/Internal Parameters'
 * '<S37>'  : 'speed_calculator/Discrete PID Controller/P Copy/Disabled'
 * '<S38>'  : 'speed_calculator/Discrete PID Controller/Parallel P Gain/Internal Parameters'
 * '<S39>'  : 'speed_calculator/Discrete PID Controller/Reset Signal/Disabled'
 * '<S40>'  : 'speed_calculator/Discrete PID Controller/Saturation/Passthrough'
 * '<S41>'  : 'speed_calculator/Discrete PID Controller/Saturation Fdbk/Disabled'
 * '<S42>'  : 'speed_calculator/Discrete PID Controller/Sum/Sum_PID'
 * '<S43>'  : 'speed_calculator/Discrete PID Controller/Sum Fdbk/Disabled'
 * '<S44>'  : 'speed_calculator/Discrete PID Controller/Tracking Mode/Disabled'
 * '<S45>'  : 'speed_calculator/Discrete PID Controller/Tracking Mode Sum/Passthrough'
 * '<S46>'  : 'speed_calculator/Discrete PID Controller/Tsamp - Integral/Passthrough'
 * '<S47>'  : 'speed_calculator/Discrete PID Controller/Tsamp - Ngain/Passthrough'
 * '<S48>'  : 'speed_calculator/Discrete PID Controller/postSat Signal/Forward_Path'
 * '<S49>'  : 'speed_calculator/Discrete PID Controller/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_speed_calculator_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
