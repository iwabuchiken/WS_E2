/*******************************************************************************
* File Name: IN_1.h  
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

#if !defined(CY_PINS_IN_1_H) /* Pins IN_1_H */
#define CY_PINS_IN_1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "IN_1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    IN_1_Write(uint8 value) ;
void    IN_1_SetDriveMode(uint8 mode) ;
uint8   IN_1_ReadDataReg(void) ;
uint8   IN_1_Read(void) ;
uint8   IN_1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define IN_1_DRIVE_MODE_BITS        (3)
#define IN_1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - IN_1_DRIVE_MODE_BITS))

#define IN_1_DM_ALG_HIZ         (0x00u)
#define IN_1_DM_DIG_HIZ         (0x01u)
#define IN_1_DM_RES_UP          (0x02u)
#define IN_1_DM_RES_DWN         (0x03u)
#define IN_1_DM_OD_LO           (0x04u)
#define IN_1_DM_OD_HI           (0x05u)
#define IN_1_DM_STRONG          (0x06u)
#define IN_1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define IN_1_MASK               IN_1__MASK
#define IN_1_SHIFT              IN_1__SHIFT
#define IN_1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IN_1_PS                     (* (reg32 *) IN_1__PS)
/* Port Configuration */
#define IN_1_PC                     (* (reg32 *) IN_1__PC)
/* Data Register */
#define IN_1_DR                     (* (reg32 *) IN_1__DR)
/* Input Buffer Disable Override */
#define IN_1_INP_DIS                (* (reg32 *) IN_1__PC2)


#if defined(IN_1__INTSTAT)  /* Interrupt Registers */

    #define IN_1_INTSTAT                (* (reg32 *) IN_1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define IN_1_DRIVE_MODE_SHIFT       (0x00u)
#define IN_1_DRIVE_MODE_MASK        (0x07u << IN_1_DRIVE_MODE_SHIFT)


#endif /* End Pins IN_1_H */


/* [] END OF FILE */
