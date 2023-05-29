/*********************************************
 * Author:          Asmaa Abd EL-kareim
 * Creation Data:   27 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                    Description
 * v1.0         27 MAY, 2023    Asmaa Abd EL-kareim          Initial Creation
*********************************************/



#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"

#include "SYSTICK_INTERFACE.h"

#include "NVIC_INTERFACE.h"
#include "EXTI_INTERFACE.h"

#include "IR_INTERFACE.h"
#include "IR_PRIVATE.h"
#include "IR_CONFIG.h"

static void APP_TakeAction(void);
static void APP_GetFrame (void);

volatile u8  APP_u8StartEdgeFlag = 0;
volatile u32 APP_u32ReceivedFrame[50] = {0};
volatile u8  APP_u8EdgeCounter = 0;
volatile u8 App_u8ButtonData = 0;


void IR_voidInit (void)
{
        MRCC_voidInit();
		MRCC_voidEnablePeripheralClk(RCC_AHB1,RCC_AHB1ENR_GPIO_A_EN);

		/*IR Sensor Pin as pull up input*/
		MGPIO_voidSetPinDirection (IR_PORT , IR_PIN , INPUT);
		MGPIO_voidPullUP_PullDown (IR_PORT , IR_PIN  ,PULL_UP);

        /*NVIC intialization*/
	    MNVIC_voidINIT();
	    /*NVIC enable*/
	    MNVIC_voidEnablePeripheralINT (IR_INT_PIN );
	    /*enable systick*/
	    MSystick_voidInit ();

	    MXTI_voidChangeSenceMode(IR_INT_LINE, MEXTI_FALLING_EDGE);


	    MXTI_voidSetCallBack(IR_INT_LINE , &APP_GetFrame); //when INIT is fired getFrame func will be executed
	    MXTI_voidEnableInterupt(IR_INT_LINE);


}



static void APP_GetFrame (void)
{
    /*this func is called after every falling edge*/
    if(APP_u8StartEdgeFlag == 0)
		{
		   /*wait time around 67.5 msec(67500 usec) to take the frame and after this time take action func*/
           /*will be executed*/
		    MSystick_VoidSetSingleEnterval(&APP_TakeAction, 80000);

		   /*raise the flag as an indication that frame data is taken*/
			APP_u8StartEdgeFlag = 1;
		}
		else // already we have the start frame edge and timer is conting in backgrond to indicate if this bit is 0 or 1
		{
			/*save every counted time in frame array*/
			APP_u32ReceivedFrame[APP_u8EdgeCounter] = MSTK_u32GetElapsedTime();
			/*Reset The Timer, Set PreLoad Value*/
			MSystick_VoidSetSingleEnterval(&APP_TakeAction, 80000);
			/*Increment Edge Counter*/
			APP_u8EdgeCounter++;
		}


}
static void APP_TakeAction(void)
{
    u8 Local_u8LoopCounter = 0;
	for(Local_u8LoopCounter = 0; Local_u8LoopCounter < 8; Local_u8LoopCounter++)
	{
        /*start from first array element that store data*/
		if((APP_u32ReceivedFrame[17+Local_u8LoopCounter] >= 1000) &&
		   (APP_u32ReceivedFrame[17+Local_u8LoopCounter] <= 1600))
		{
			CLR_BIT(App_u8ButtonData, Local_u8LoopCounter);
		}
		else
		{
			SET_BIT(App_u8ButtonData, Local_u8LoopCounter);
		}
        /*at the end of this func we will have u8 variable store the sent number from IR */
	}
	APP_u8StartEdgeFlag = 0; // reset the start flag to start  a new frame again
	APP_u8EdgeCounter = 0; // reset edge array counter
    //APP_u32ReceivedFrame[] = {0};
}




void APP_voidPlay(void)
{

	    switch( App_u8ButtonData )
	    {
	        case 12:
	        	MGPIO_voidSetPinValue(DIO_PORTA , PIN1 , HIGH); // RED

	            break;
	        case 24:
	        	MGPIO_voidSetPinValue(DIO_PORTA , PIN3 , HIGH); // red

	            break;
	        case 94:
	        	MGPIO_voidSetPinValue(DIO_PORTA , PIN3 , HIGH); // blue

	            break;
	        case 8:

	            break;
	        case 28:

	            break;
	        case 90:

	            break;
	        case 66:

	            break;
	        case 82:

	            break;
	        case 74:

	            break;
	        case 22:

	            break;
	    }
	}


