/*********************************************
 * Author:          Asmaa Abd EL-kareim
 * Creation Data:   13 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                    Description
 * v1.0         13 MAY, 2023    Asmaa Abd EL-kareim          Initial Creation
*********************************************/



#include "../../ARM_COTs/LIB/BIT_MATH.h"
#include "../../ARM_COTs/LIB/STD_TYPES.h"
#include "../../ARM_COTs/MCAL/GPIO/GPIO_INTERFACE.h"
#include "../../ARM_COTs/MCAL/RCC/RCC_INTERFACE.h"
//#include "STD_TYPES.h"
//#include "BIT_MATH.h"
//#include "GPIO_INTERFACE.h"
//#include "RCC_INTERFACE.h"

#include "LED_MATRIX_INTERFACE.h"
#include "LED_MATRIX_PRIVATE.h"
#include "LED_MATRIX_CONFIG.h"


void HLedMatrix_voidInit (void)
{
	MGPIO_voidSetPinDirection (LED_MATRIX_ROW0_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_ROW1_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_ROW2_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_ROW3_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_ROW4_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_ROW5_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_ROW6_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_ROW7_PIN, OUTPUT );


    MGPIO_voidSetPinDirection (LED_MATRIX_COL0_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_COL1_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_COL2_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_COL3_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_COL4_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_COL5_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_COL6_PIN, OUTPUT );
    MGPIO_voidSetPinDirection (LED_MATRIX_COL7_PIN, OUTPUT );
	
	
    MGPIO_voidOutputMoade (LED_MATRIX_ROW0_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_ROW1_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_ROW2_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_ROW3_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_ROW4_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_ROW5_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_ROW6_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_ROW7_PIN, PUSH_PULL );


    MGPIO_voidOutputMoade (LED_MATRIX_COL0_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_COL1_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_COL2_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_COL3_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_COL4_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_COL5_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_COL6_PIN, PUSH_PULL );
    MGPIO_voidOutputMoade (LED_MATRIX_COL7_PIN, PUSH_PULL );

	



    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_ROW0_PIN, OUTPUT_SWITCH_SPEED_2M );
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_ROW1_PIN,OUTPUT_SWITCH_SPEED_2M );
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_ROW2_PIN, OUTPUT_SWITCH_SPEED_2M );
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_ROW3_PIN, OUTPUT_SWITCH_SPEED_2M);
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_ROW4_PIN, OUTPUT_SWITCH_SPEED_2M);
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_ROW5_PIN, OUTPUT_SWITCH_SPEED_2M );
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_ROW6_PIN, OUTPUT_SWITCH_SPEED_2M );
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_ROW7_PIN, OUTPUT_SWITCH_SPEED_2M );


    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_COL0_PIN, OUTPUT_SWITCH_SPEED_2M );
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_COL1_PIN, OUTPUT_SWITCH_SPEED_2M );
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_COL2_PIN, OUTPUT_SWITCH_SPEED_2M);
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_COL3_PIN, OUTPUT_SWITCH_SPEED_2M);
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_COL4_PIN, OUTPUT_SWITCH_SPEED_2M );
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_COL5_PIN, OUTPUT_SWITCH_SPEED_2M);
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_COL6_PIN, OUTPUT_SWITCH_SPEED_2M);
    MGPIO_voidOutPutSpeedRegister (LED_MATRIX_COL7_PIN, OUTPUT_SWITCH_SPEED_2M );

	
	
}

void HLedMatrix_voidDisplay (u8 Copy_u8Data , u8 Copy_u8ActivePortNumber , u8 Copy_u8ActivePinNumber)
{
   u8 Local_u8BitData ; 
    /*deactivate all cols*/
    
    MGPIO_voidSetPinValue (LED_MATRIX_COL0_PIN, HIGH);
    MGPIO_voidSetPinValue (LED_MATRIX_COL1_PIN, HIGH );
    MGPIO_voidSetPinValue (LED_MATRIX_COL2_PIN, HIGH);
    MGPIO_voidSetPinValue (LED_MATRIX_COL3_PIN, HIGH);
    MGPIO_voidSetPinValue (LED_MATRIX_COL4_PIN, HIGH);
    MGPIO_voidSetPinValue (LED_MATRIX_COL5_PIN, HIGH);
    MGPIO_voidSetPinValue (LED_MATRIX_COL6_PIN, HIGH);
    MGPIO_voidSetPinValue (LED_MATRIX_COL7_PIN, HIGH);
   
   
   /*write data on rows*/
   Local_u8BitData = GET_BIT(Copy_u8Data ,0);
   MGPIO_voidSetPinValue (LED_MATRIX_ROW0_PIN, Local_u8BitData);
   Local_u8BitData = GET_BIT(Copy_u8Data ,1);
   MGPIO_voidSetPinValue (LED_MATRIX_ROW1_PIN, Local_u8BitData);
   Local_u8BitData = GET_BIT(Copy_u8Data ,2);
   MGPIO_voidSetPinValue (LED_MATRIX_ROW2_PIN, Local_u8BitData);
   Local_u8BitData = GET_BIT(Copy_u8Data ,3);
   MGPIO_voidSetPinValue (LED_MATRIX_ROW3_PIN, Local_u8BitData);
   Local_u8BitData = GET_BIT(Copy_u8Data ,4);
   MGPIO_voidSetPinValue (LED_MATRIX_ROW4_PIN, Local_u8BitData);
   Local_u8BitData = GET_BIT(Copy_u8Data ,5);
   MGPIO_voidSetPinValue (LED_MATRIX_ROW5_PIN, Local_u8BitData);
   Local_u8BitData = GET_BIT(Copy_u8Data ,6);
   MGPIO_voidSetPinValue (LED_MATRIX_ROW6_PIN, Local_u8BitData);
   Local_u8BitData = GET_BIT(Copy_u8Data ,7);
   MGPIO_voidSetPinValue (LED_MATRIX_ROW7_PIN, Local_u8BitData);

   /*activate 1 col */
   MGPIO_voidSetPinValue (Copy_u8ActivePortNumber , Copy_u8ActivePinNumber , LOW);
   /*wait 2.5 milli sec*/
   MSystick_voidBuzyWait(2500);

}