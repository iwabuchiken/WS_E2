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

/*
OUT_OnOff

@param
int => pin number
int => duration

*/
void OUT_OnOff(int, int);

int main()
{
    //CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_1_Start();


    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
/*        if( IN_1_Read() == 1 ) {
           
            OUT_OnOff(1, 200);
            OUT_2_Write( 0 );
            
        } else if( IN_2_Read() == 1 ) {
            
            OUT_OnOff(2, 200);
            OUT_1_Write( 0 );
            
        } else {
            
            OUT_1_Write( 0 );
            OUT_2_Write( 0 );
            
        }
*/
    }//for(;;)
    
}//main()

void OUT_OnOff(int pin, int len)
{
    
    switch(pin) {
        
        case 1:
        
        OUT_1_Write( ! OUT_1_Read() );
        CyDelay( len );

        break;
        
        case 2:
        
        OUT_2_Write( ! OUT_2_Read() );
        CyDelay( len );
        
        break;
        
        default:
        
        break;
        
    }//switch(pin)
    
}//void OUT_OnOff(int, int)

/* [] END OF FILE */
