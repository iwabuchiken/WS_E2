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

void LED_OnOff_3LED(int, int, int, int);

int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        LED_OnOff_3LED(1, 0, 0, 100);
        LED_OnOff_3LED(0, 0, 0, 500);

        LED_OnOff_3LED(0, 1, 0, 100);
        LED_OnOff_3LED(0, 0, 0, 500);

        LED_OnOff_3LED(0, 0, 1, 1000);
        LED_OnOff_3LED(0, 0, 0, 500);

//        LED_OnOff_3LED(1, 1, 1, 250);
//        LED_OnOff_3LED(0, 0, 0, 500);

        /*LED_OnOff_3LED(1, 1, 1, 500);       
        LED_OnOff_3LED(0, 0, 0, 500);*/
        
        
/*        OUT_1_Write( 1 );
        OUT_2_Write( 0 );
        OUT_3_Write( 0 );
        
        CyDelay( 100 );
        
        OUT_1_Write( 0 );
        OUT_2_Write( 0 );
        
        CyDelay( 500 );
*/
        
    }
    
}//int main()

void LED_OnOff_3LED
(int LED_1, int LED_2, int LED_3, int len) {

        OUT_1_Write( LED_1 );
        OUT_2_Write( LED_2 );
        OUT_3_Write( LED_3 );
        
        CyDelay( len );

}//void LED_OnOff_3LED

/* [] END OF FILE */
