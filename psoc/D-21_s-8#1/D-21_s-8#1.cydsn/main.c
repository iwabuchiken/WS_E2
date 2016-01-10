/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        
        
        OUT_1_Write( SW_1_Read() );
        
/*        OUT_1_Write( ! OUT_1_Read() );
        CyDelay( 100 );
  */      
/*        OUT_1_Write( 1 );
        CyDelay( 100 );

        OUT_1_Write( 0 );
        CyDelay( 500 );
*/

        
    }
}

/* [] END OF FILE */
