
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"
#include "NVIC_INTERFACE.h"



void main(void)
{

    MRCC_voidInit();

	MRCC_voidEnablePeripheralClk(RCC_AHB1,RCC_AHB1ENR_GPIO_A_EN);
	MGPIO_voidSetPinDirection (DIO_PORTA , PIN0, OUTPUT );
	MGPIO_voidSetPinDirection (DIO_PORTA , PIN1, OUTPUT );


    MNVIC_voidINIT();
    MNVIC_voidEnablePeripheralINT (MNVIC_EXTI0);
    MNVIC_voidEnablePeripheralINT (MNVIC_EXTI1); //has higher software periority

    MNVIC_voidSetPeripheralPriority(MNVIC_EXTI0, 0b1101);
    MNVIC_voidSetPeripheralPriority(MNVIC_EXTI1, 0b1100);
    MNVIC_voidSetPendingFlag(6);

    void EXTI0_Handler(void){

    	MGPIO_voidSetPinValue(DIO_PORTA , PIN0 , HIGH);
    	 MNVIC_voidSetPendingFlag(7);

    }

    void EXTI1_Handler(void){

    	MGPIO_voidSetPinValue(DIO_PORTA , PIN1 , HIGH);

    }

	while(1)
	{

	}



}
