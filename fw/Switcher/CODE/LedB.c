/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename  : LedB.C
**     Project   : Switcher
**     Processor : MC9S08SH8CPJ
**     Component : BitIO
**     Version   : Component 02.075, Driver 03.21, CPU db: 3.00.062
**     Compiler  : CodeWarrior HCS08 C Compiler
**     Date/Time : 1/6/2016, 3:28 AM
**     Abstract  :
**         This bean "BitIO" implements an one-bit input/output.
**         It uses one bit/pin of a port.
**         Methods of this bean are mostly implemented as a macros
**         (if supported by target language and compiler).
**     Settings  :
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       13            |  PTB3_PIB3_MOSI_ADP7
**             ----------------------------------------------------
**
**         Port name                   : PTB
**
**         Bit number (in port)        : 3
**         Bit mask of the port        : $0008
**
**         Initial direction           : Output (direction can be changed)
**         Safe mode                   : yes
**         Initial output value        : 0
**         Initial pull option         : off
**
**         Port data register          : PTBD      [$0002]
**         Port control register       : PTBDD     [$0003]
**
**         Optimization for            : speed
**     Contents  :
**         SetDir - void LedB_SetDir(bool Dir);
**         GetVal - bool LedB_GetVal(void);
**         PutVal - void LedB_PutVal(bool Val);
**         ClrVal - void LedB_ClrVal(void);
**         SetVal - void LedB_SetVal(void);
**
**     Copyright : 1997 - 2009 Freescale Semiconductor, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE LedB. */

#include "LedB.h"
  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  LedB_GetVal (component BitIO)
**
**     Description :
**         This method returns an input value.
**           a) direction = Input  : reads the input value from the
**                                   pin and returns it
**           b) direction = Output : returns the last written value
**     Parameters  : None
**     Returns     :
**         ---             - Input value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)

** ===================================================================
*/
/*
bool LedB_GetVal(void)

**  This method is implemented as a macro. See LedB.h file.  **
*/

/*
** ===================================================================
**     Method      :  LedB_PutVal (component BitIO)
**
**     Description :
**         This method writes the new output value.
**           a) direction = Input  : sets the new output value;
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes the value to the
**                                   appropriate pin
**     Parameters  :
**         NAME       - DESCRIPTION
**         Val             - Output value. Possible values:
**                           FALSE - logical "0" (Low level)
**                           TRUE - logical "1" (High level)
**     Returns     : Nothing
** ===================================================================
*/
void LedB_PutVal(bool Val)
{
  if (Val) {
    setReg8Bits(PTBD, 0x08);           /* PTBD3=0x01 */
    Shadow_PTB |= (byte)0x08;          /* Set-up shadow variable */
  } else { /* !Val */
    clrReg8Bits(PTBD, 0x08);           /* PTBD3=0x00 */
    Shadow_PTB &= (byte)~0x08;         /* Set-up shadow variable */
  } /* !Val */
}

/*
** ===================================================================
**     Method      :  LedB_ClrVal (component BitIO)
**
**     Description :
**         This method clears (sets to zero) the output value.
**           a) direction = Input  : sets the output value to "0";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "0" to the
**                                   appropriate pin
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LedB_ClrVal(void)

**  This method is implemented as a macro. See LedB.h file.  **
*/

/*
** ===================================================================
**     Method      :  LedB_SetVal (component BitIO)
**
**     Description :
**         This method sets (sets to one) the output value.
**           a) direction = Input  : sets the output value to "1";
**                                   this operation will be shown on
**                                   output after the direction has
**                                   been switched to output
**                                   (SetDir(TRUE);)
**           b) direction = Output : directly writes "1" to the
**                                   appropriate pin
**     Parameters  : None
**     Returns     : Nothing
** ===================================================================
*/
/*
void LedB_SetVal(void)

**  This method is implemented as a macro. See LedB.h file.  **
*/

/*
** ===================================================================
**     Method      :  LedB_SetDir (component BitIO)
**
**     Description :
**         This method sets direction of the bean.
**     Parameters  :
**         NAME       - DESCRIPTION
**         Dir        - Direction to set (FALSE or TRUE)
**                      FALSE = Input, TRUE = Output
**     Returns     : Nothing
** ===================================================================
*/
void LedB_SetDir(bool Dir)
{
  if (Dir) {
    setReg8(PTBD, (getReg8(PTBD) & (~0x08)) | (Shadow_PTB & 0x08)); /* PTBD3=Shadow_PTB[bit 3] */
    setReg8Bits(PTBDD, 0x08);          /* PTBDD3=0x01 */
  } else { /* !Dir */
    clrReg8Bits(PTBDD, 0x08);          /* PTBDD3=0x00 */
  } /* !Dir */
}


/* END LedB. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 3.07 [04.34]
**     for the Freescale HCS08 series of microcontrollers.
**
** ###################################################################
*/
