/*******************************************************************************
* File Name: OUT_1.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_OUT_1_H) /* Pins OUT_1_H */
#define CY_PINS_OUT_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "OUT_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    OUT_1_Write(uint8 value) ;
void    OUT_1_SetDriveMode(uint8 mode) ;
uint8   OUT_1_ReadDataReg(void) ;
uint8   OUT_1_Read(void) ;
uint8   OUT_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define OUT_1_DRIVE_MODE_BITS        (3)
#define OUT_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - OUT_1_DRIVE_MODE_BITS))

#define OUT_1_DM_ALG_HIZ         (0x00u)
#define OUT_1_DM_DIG_HIZ         (0x01u)
#define OUT_1_DM_RES_UP          (0x02u)
#define OUT_1_DM_RES_DWN         (0x03u)
#define OUT_1_DM_OD_LO           (0x04u)
#define OUT_1_DM_OD_HI           (0x05u)
#define OUT_1_DM_STRONG          (0x06u)
#define OUT_1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define OUT_1_MASK               OUT_1__MASK
#define OUT_1_SHIFT              OUT_1__SHIFT
#define OUT_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OUT_1_PS                     (* (reg32 *) OUT_1__PS)
/* Port Configuration */
#define OUT_1_PC                     (* (reg32 *) OUT_1__PC)
/* Data Register */
#define OUT_1_DR                     (* (reg32 *) OUT_1__DR)
/* Input Buffer Disable Override */
#define OUT_1_INP_DIS                (* (reg32 *) OUT_1__PC2)


#if defined(OUT_1__INTSTAT)  /* Interrupt Registers */

    #define OUT_1_INTSTAT                (* (reg32 *) OUT_1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define OUT_1_DRIVE_MODE_SHIFT       (0x00u)
#define OUT_1_DRIVE_MODE_MASK        (0x07u << OUT_1_DRIVE_MODE_SHIFT)


#endif /* End Pins OUT_1_H */


/* [] END OF FILE */
