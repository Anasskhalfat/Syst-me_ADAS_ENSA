/*
 * File: speed_calculator_private.h
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

#ifndef RTW_HEADER_speed_calculator_private_h_
#define RTW_HEADER_speed_calculator_private_h_
#include "rtwtypes.h"
#ifdef __cplusplus

extern "C" {

#endif

  extern void codeurMoteur_Start_wrapper(real_T *xD);
  extern void codeurMoteur_Outputs_wrapper(real_T *compteur,
    real_T *omega,
    const real_T *xD);
  extern void codeurMoteur_Update_wrapper(real_T *compteur,
    real_T *omega,
    real_T *xD);
  extern void codeurMoteur_Terminate_wrapper(real_T *xD);

#ifdef __cplusplus

}
#endif

extern real_T rt_roundd_snf(real_T u);

#endif                              /* RTW_HEADER_speed_calculator_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
