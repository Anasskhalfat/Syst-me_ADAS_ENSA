
/*
 * Include Files
 *
 */
#if defined(MATLAB_MEX_FILE)
#include "tmwtypes.h"
#include "simstruc_types.h"
#else
#include "rtwtypes.h"
#endif



/* %%%-SFUNWIZ_wrapper_includes_Changes_BEGIN --- EDIT HERE TO _END */
# ifndef MATLAB_MEX_FILE
# include <Arduino.h>
#define encodeurY1A 2
#define encodeurY1B 3

volatile double cpt1 = 0;
volatile double cpt = 0;

void doEncodeur1() 
{  
  if (digitalRead(encodeurY1A) == digitalRead(encodeurY1B)) 
  {
    cpt1++;
     cpt++;
    
  } 
  else 
  {
    cpt1--;
    cpt--;
  }
}


# endif
/* %%%-SFUNWIZ_wrapper_includes_Changes_END --- EDIT HERE TO _BEGIN */
#define y_width 1

/*
 * Create external references here.  
 *
 */
/* %%%-SFUNWIZ_wrapper_externs_Changes_BEGIN --- EDIT HERE TO _END */
/* extern double func(double a); */
/* %%%-SFUNWIZ_wrapper_externs_Changes_END --- EDIT HERE TO _BEGIN */

/*
 * Start function
 *
 */
void codeurMoteur_Start_wrapper(real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Start_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Custom Start code goes here.
 */
volatile double  dt = 0.03;
volatile double omega[0], compteur[0];
if (xD[0]==1) 
{
    # ifndef MATLAB_MEX_FILE
        compteur[0]=cpt1;
        omega[0] = (60.0*cpt1)/(50*64*dt); // en tours/min           
    # endif
}
/* %%%-SFUNWIZ_wrapper_Start_Changes_END --- EDIT HERE TO _BEGIN */
}
/*
 * Output function
 *
 */
void codeurMoteur_Outputs_wrapper(real_T *compteur,
			real_T *omega,
			const real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
/* This sample sets the output equal to the input
      y0[0] = u0[0]; 
 For complex signals use: y0[0].re = u0[0].re; 
      y0[0].im = u0[0].im;
      y1[0].re = u1[0].re;
      y1[0].im = u1[0].im;
 */
volatile double  dt = 0.03;
if (xD[0]==1) 
{
    # ifndef MATLAB_MEX_FILE
        compteur[0]=cpt;
        omega[0] = (60.0*cpt1)/(50*64*dt); // en tours/min
        cpt1=0;
    # endif
}
/* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
}

/*
 * Updates function
 *
 */
void codeurMoteur_Update_wrapper(real_T *compteur,
			real_T *omega,
			real_T *xD)
{
/* %%%-SFUNWIZ_wrapper_Update_Changes_BEGIN --- EDIT HERE TO _END */
/*
 * Code example
 *   xD[0] = u0[0];
 */
if (xD[0]!=1) 
{
    # ifndef MATLAB_MEX_FILE
       pinMode(2,INPUT);
       pinMode(3,INPUT);
       digitalWrite(2, HIGH); 
       digitalWrite(3, HIGH); 
       pinMode(4,INPUT);
       pinMode(6,INPUT);
       digitalWrite(4, HIGH); 
       digitalWrite(6, HIGH); 
       attachInterrupt(digitalPinToInterrupt(2), doEncodeur1, CHANGE);
    # endif
       xD[0] = 1;
}
/* %%%-SFUNWIZ_wrapper_Update_Changes_END --- EDIT HERE TO _BEGIN */
}

