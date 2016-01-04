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

    // capsense
    CapSense_Start();
    
    CapSense_InitializeAllBaselines();
    
    // pwm
    PWM_1_Start();
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        // capsense
        CapSense_ScanEnabledWidgets();
        
        // busy?
        if( ! CapSense_IsBusy() )
        {
            
            //uint16 value = CapSense_GetCentroidPos( CapSense_LINEAR_SLIDERS_POS_FILTERS_MASK );
            uint16 value = CapSense_GetCentroidPos( CapSense_LINEARSLIDER0__LS );

            if( value != 0xFFF )
            {
                //PWM_1_WriteCompare( value );
                PWM_1_WriteCompare( value / 2 );
            }
            /*else
            {
                //PWM_1_WriteCompare( 20 );
                //PWM_1_WritePeriod();
            }*/
            
            CapSense_UpdateEnabledBaselines();
            
        }//if( ! CapSense_IsBusy() )
        
    }//for(;;)
}

/* [] END OF FILE */
