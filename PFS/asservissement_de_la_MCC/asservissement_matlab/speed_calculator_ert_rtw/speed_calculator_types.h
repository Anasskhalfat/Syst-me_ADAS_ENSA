/*
 * File: speed_calculator_types.h
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

#ifndef RTW_HEADER_speed_calculator_types_h_
#define RTW_HEADER_speed_calculator_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef struct_tag_04b6x6tDldj9IrIH2gmbjG
#define struct_tag_04b6x6tDldj9IrIH2gmbjG

struct tag_04b6x6tDldj9IrIH2gmbjG
{
  int16_T __dummy;
};

#endif                                 /* struct_tag_04b6x6tDldj9IrIH2gmbjG */

#ifndef typedef_b_arduinodriver_ArduinoDigita_T
#define typedef_b_arduinodriver_ArduinoDigita_T

typedef struct tag_04b6x6tDldj9IrIH2gmbjG b_arduinodriver_ArduinoDigita_T;

#endif                             /* typedef_b_arduinodriver_ArduinoDigita_T */

#ifndef struct_tag_AYWgtFscQm3mLUJYb3A20C
#define struct_tag_AYWgtFscQm3mLUJYb3A20C

struct tag_AYWgtFscQm3mLUJYb3A20C
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_arduinodriver_ArduinoDigita_T DigitalIODriverObj;
};

#endif                                 /* struct_tag_AYWgtFscQm3mLUJYb3A20C */

#ifndef typedef_codertarget_arduinobase_block_T
#define typedef_codertarget_arduinobase_block_T

typedef struct tag_AYWgtFscQm3mLUJYb3A20C codertarget_arduinobase_block_T;

#endif                             /* typedef_codertarget_arduinobase_block_T */

#ifndef struct_tag_PNTFOAmbgvzVAf4BHoOgDE
#define struct_tag_PNTFOAmbgvzVAf4BHoOgDE

struct tag_PNTFOAmbgvzVAf4BHoOgDE
{
  int16_T S0_isInitialized;
  real_T W0_states[50];
  real_T P0_InitialStates;
  real_T P1_Coefficients[51];
};

#endif                                 /* struct_tag_PNTFOAmbgvzVAf4BHoOgDE */

#ifndef typedef_b_dsp_FIRFilter_0_speed_calcu_T
#define typedef_b_dsp_FIRFilter_0_speed_calcu_T

typedef struct tag_PNTFOAmbgvzVAf4BHoOgDE b_dsp_FIRFilter_0_speed_calcu_T;

#endif                             /* typedef_b_dsp_FIRFilter_0_speed_calcu_T */

#ifndef struct_tag_cIE0BxVi6cdz59PXKF91XB
#define struct_tag_cIE0BxVi6cdz59PXKF91XB

struct tag_cIE0BxVi6cdz59PXKF91XB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_speed_calcu_T cSFunObject;
};

#endif                                 /* struct_tag_cIE0BxVi6cdz59PXKF91XB */

#ifndef typedef_b_dspcodegen_FIRFilter_speed__T
#define typedef_b_dspcodegen_FIRFilter_speed__T

typedef struct tag_cIE0BxVi6cdz59PXKF91XB b_dspcodegen_FIRFilter_speed__T;

#endif                             /* typedef_b_dspcodegen_FIRFilter_speed__T */

/* Custom Type definition for MATLABSystem: '<Root>/PWM' */
#include "MW_SVD.h"
#ifndef struct_tag_g1WX34VPn8QzVKQriB4HN
#define struct_tag_g1WX34VPn8QzVKQriB4HN

struct tag_g1WX34VPn8QzVKQriB4HN
{
  MW_Handle_Type MW_PWM_HANDLE;
};

#endif                                 /* struct_tag_g1WX34VPn8QzVKQriB4HN */

#ifndef typedef_g_matlabshared_ioclient_perip_T
#define typedef_g_matlabshared_ioclient_perip_T

typedef struct tag_g1WX34VPn8QzVKQriB4HN g_matlabshared_ioclient_perip_T;

#endif                             /* typedef_g_matlabshared_ioclient_perip_T */

#ifndef struct_tag_4eDVzK5FiryyCjvjjvrZGB
#define struct_tag_4eDVzK5FiryyCjvjjvrZGB

struct tag_4eDVzK5FiryyCjvjjvrZGB
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  g_matlabshared_ioclient_perip_T PWMDriverObj;
};

#endif                                 /* struct_tag_4eDVzK5FiryyCjvjjvrZGB */

#ifndef typedef_codertarget_arduinobase_inter_T
#define typedef_codertarget_arduinobase_inter_T

typedef struct tag_4eDVzK5FiryyCjvjjvrZGB codertarget_arduinobase_inter_T;

#endif                             /* typedef_codertarget_arduinobase_inter_T */

#ifndef struct_tag_BlgwLpgj2bjudmbmVKWwDE
#define struct_tag_BlgwLpgj2bjudmbmVKWwDE

struct tag_BlgwLpgj2bjudmbmVKWwDE
{
  uint32_T f1[8];
};

#endif                                 /* struct_tag_BlgwLpgj2bjudmbmVKWwDE */

#ifndef typedef_cell_wrap_speed_calculator_T
#define typedef_cell_wrap_speed_calculator_T

typedef struct tag_BlgwLpgj2bjudmbmVKWwDE cell_wrap_speed_calculator_T;

#endif                                /* typedef_cell_wrap_speed_calculator_T */

#ifndef struct_tag_0OmCeGuw1I0WffyIFWp1XC
#define struct_tag_0OmCeGuw1I0WffyIFWp1XC

struct tag_0OmCeGuw1I0WffyIFWp1XC
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_speed_calculator_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_speed__T *FilterObj;
  b_dspcodegen_FIRFilter_speed__T _pobj0;
};

#endif                                 /* struct_tag_0OmCeGuw1I0WffyIFWp1XC */

#ifndef typedef_dsp_LowpassFilter_speed_calcu_T
#define typedef_dsp_LowpassFilter_speed_calcu_T

typedef struct tag_0OmCeGuw1I0WffyIFWp1XC dsp_LowpassFilter_speed_calcu_T;

#endif                             /* typedef_dsp_LowpassFilter_speed_calcu_T */

/* Parameters (default storage) */
typedef struct P_speed_calculator_T_ P_speed_calculator_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_speed_calculator_T RT_MODEL_speed_calculator_T;

#endif                                /* RTW_HEADER_speed_calculator_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
