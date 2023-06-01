
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "SYSTICK_INTERFACE.h"
#include "NVIC_INTERFACE.h"
#include "LED_MATRIX_INTERFACE.h"

void main(void)
{


	MRCC_voidInit();
	MSystick_voidInit ();
	MRCC_voidEnablePeripheralClk(RCC_AHB1,RCC_AHB1ENR_GPIO_A_EN);
	MRCC_voidEnablePeripheralClk(RCC_AHB1,RCC_AHB1ENR_GPIO_B_EN);
	HLedMatrix_voidInit ();
	while(1)
	{
		HLedMatrix_voidDisplayOneCol (0,LED_MATRIX_COL0_PIN);
		HLedMatrix_voidDisplayOneCol (124,LED_MATRIX_COL1_PIN);
		HLedMatrix_voidDisplayOneCol (18,LED_MATRIX_COL2_PIN);
		HLedMatrix_voidDisplayOneCol (18,LED_MATRIX_COL3_PIN);
		HLedMatrix_voidDisplayOneCol (18,LED_MATRIX_COL4_PIN);
		HLedMatrix_voidDisplayOneCol (18,LED_MATRIX_COL5_PIN);
		HLedMatrix_voidDisplayOneCol(124,LED_MATRIX_COL6_PIN);
		HLedMatrix_voidDisplayOneCol (0,LED_MATRIX_COL7_PIN);





}


}















/*
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
*/
