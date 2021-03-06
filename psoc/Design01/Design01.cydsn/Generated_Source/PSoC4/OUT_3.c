/*******************************************************************************
* File Name: OUT_3.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "OUT_3.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        OUT_3_PC =   (OUT_3_PC & \
                                (uint32)(~(uint32)(OUT_3_DRIVE_MODE_IND_MASK << (OUT_3_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (OUT_3_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: OUT_3_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void OUT_3_Write(uint8 value) 
{
    uint8 drVal = (uint8)(OUT_3_DR & (uint8)(~OUT_3_MASK));
    drVal = (drVal | ((uint8)(value << OUT_3_SHIFT) & OUT_3_MASK));
    OUT_3_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: OUT_3_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  OUT_3_DM_STRONG     Strong Drive 
*  OUT_3_DM_OD_HI      Open Drain, Drives High 
*  OUT_3_DM_OD_LO      Open Drain, Drives Low 
*  OUT_3_DM_RES_UP     Resistive Pull Up 
*  OUT_3_DM_RES_DWN    Resistive Pull Down 
*  OUT_3_DM_RES_UPDWN  Resistive Pull Up/Down 
*  OUT_3_DM_DIG_HIZ    High Impedance Digital 
*  OUT_3_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void OUT_3_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(OUT_3__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: OUT_3_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro OUT_3_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 OUT_3_Read(void) 
{
    return (uint8)((OUT_3_PS & OUT_3_MASK) >> OUT_3_SHIFT);
}


/*******************************************************************************
* Function Name: OUT_3_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 OUT_3_ReadDataReg(void) 
{
    return (uint8)((OUT_3_DR & OUT_3_MASK) >> OUT_3_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(OUT_3_INTSTAT) 

    /*******************************************************************************
    * Function Name: OUT_3_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 OUT_3_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(OUT_3_INTSTAT & OUT_3_MASK);
		OUT_3_INTSTAT = maskedStatus;
        return maskedStatus >> OUT_3_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
