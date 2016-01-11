/** ###################################################################
**     Filename  : Switcher.C
**     Project   : Switcher
**     Processor : MC9S08SH8CPJ
**     Version   : Driver 01.11
**     Compiler  : CodeWarrior HCS08 C Compiler
**     Date/Time : 1/5/2016, 2:21 PM
**     Abstract  :
**         Main module.
**         This module contains user's application code.
**     Settings  :
**     Contents  :
**         No public methods
**
** ###################################################################*/
/* MODULE Switcher */


/* Including needed modules to compile this module/procedure */
#include "Cpu.h"
#include "Events.h"
#include "CtrlInt.h"
#include "CtrlOut.h"
#include "LedR.h"
#include "LedG.h"
#include "LedB.h"
#include "timer.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

#define CONTROLADOR1 1
#define CONTROLADOR2 0
#define CtrlOut PTCD_PTCD1
#define CtrlInt PTCD_PTCD3
#define Led PTBD_PTBD3

long ReadSetTime(void);

byte AdcVal;
long ticks, actual;
byte stat;
byte blink;
byte band, band0;

static const long const vect[] = {1,1,42,56,71,85,99,113,127,141,155,169,184,198,212,226,240,254,268,282,296,311,325,
339,353,367,381,395,409,424,438,452,466,480,494,508,522,536,551,565,579,593,607,621,635,649,664,678,692,706,720,734,
748,762,776,791,805,819,833,847,861,875,889,904,918,932,946,960,974,988,1002,1016,1031,1045,1059,1073,1087,1101,1115,
1129,1144,1158,1172,1186,1200,1214,1228,1242,1256,1271,1285,1299,1313,1327,1341,1355,1369,1384,1398,1412,1426,1440,
1454,1468,1482,1496,1511,1525,1539,1553,1567,1581,1595,1609,1624,1638,1652,1666,1680,1694,1708,1722,1736,1751,1765,
1779,1793,1807,1821,1835,1849,1864,1878,1892,1906,1920,1934,1948,1962,1976,1991,2005,2019,2033,2047,2061,2075,2089,
2104,2118,2132,2146,2160,2174,2188,2202,2216,2231,2245,2259,2273,2287,2301,2315,2329,2344,2358,2372,2386,2400,2414,
2428,2442,2456,2471,2485,2499,2513,2527,2541,2555,2569,2584,2598,2612,2626,2640,2654,2668,2682,2696,2711,2725,2739,
2753,2767,2781,2795,2809,2824,2838,2852,2866,2880,2894,2908,2922,2936,2951,2965,2979,2993,3007,3021,3035,3049,3064,
3078,3092,3106,3120,3134,3148,3162,3176,3191,3205,3219,3233,3247,3261,3275,3289,3304,3318,3332,3346,3360,3374,3388,
3402,3416,3431,3445,3459,3473,3487,3501,3515,3529,3544,3558,3572,3586,3600,3600};




/* User includes (#include below this line is not maintained by Processor Expert) */

void main(void)
{
  /* Write your local variable definition here */

  /*** Processor Expert internal initialization. DON'T REMOVE THIS CODE!!! ***/
  PE_low_level_init();
  /*** End of Processor Expert internal initialization.                    ***/

  /* Write your code here */
  /* For example: for(;;) { } */

/*FALTA PRENDER LOS LEDS */
Led = 1;
CtrlOut = 0;
band = 0;
band0 = 0;

for(;;) {


    stat = PTCD_PTCD3;
    if(!stat && !band) { 
                ticks = 0;
                Led = blink;
                band0 = 1;
              }
              
    if(band0 && !band){ Led = blink;}
    
    actual = ReadSetTime();
    while(!stat && !band){
      stat = PTCD_PTCD3;
      Led = blink;
      if (ticks >= actual) {
      ticks = 0;
      CtrlOut = 1;
      Led = 0;
      band = 1;
      }

    }
}




/* Programa pruebas

for(;;) {
state = PTCD_PTCD3;

actual = ReadSetTime();
if (ticks >= actual) {

ticks = 0;
CtrlOut ^= 1;

}                  */


 
 
  /*** Don't write any code pass this line, or it will be deleted during code generation. ***/
  /*** Processor Expert end of main routine. DON'T MODIFY THIS CODE!!! ***/
  for(;;){}
  /*** Processor Expert end of main routine. DON'T WRITE CODE BELOW!!! ***/
  /*** End of main routine. DO NOT MODIFY THIS TEXT!!! ***/
}
/* END Switcher */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.07 [04.34]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/

long ReadSetTime(void){
ADCCFG = 0b00000000;
ADCSC1 = 0b00001010;

 while(ADCSC2_ADACT);
 while(!ADCSC1_COCO); 
         
  
 return vect[ADCRL]; 
}
