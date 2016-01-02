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

void OUT_ON(int);

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        while( IN_1_Read() )
        {
         
            OUT_ON( 100 );
            
        }
        
        OUT_ON( 500 );
        
        /* Place your application code here. */
        //OUT_1_Write( IN_1_Read() );
        
    }
    
}//int main()

void OUT_ON(int len)
{
    
    OUT_1_Write( ! OUT_1_Read() );
    
    CyDelay( len );
    
}//void OUT_ON(int)

/* [] END OF FILE */
