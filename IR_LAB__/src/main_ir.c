#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"

#include "SYSTICK_INTERFACE.h"

#include "NVIC_INTERFACE.h"
#include "EXTI_INTERFACE.h"

#include "IR_INTERFACE.h"


void RGB_voidInit (void);


void main (void)

{
	RGB_voidInit ();
	IR_voidInit ();

	asm("NOP");
	while(1)
	{
		APP_voidPlay();
	}



}




void RGB_voidInit (void)
{
       /*3 pins in push/pull output mode to control RGB LED*/
		MGPIO_voidSetPinDirection (DIO_PORTA , PIN1, OUTPUT); // red
		MGPIO_voidSetPinDirection (DIO_PORTA , PIN2, OUTPUT); // green
		MGPIO_voidSetPinDirection (DIO_PORTA , PIN3, OUTPUT); // blue

		MGPIO_voidOutputMoade (DIO_PORTA , PIN1, PUSH_PULL);
		MGPIO_voidOutputMoade (DIO_PORTA , PIN2, PUSH_PULL);
		MGPIO_voidOutputMoade (DIO_PORTA , PIN3, PUSH_PULL);


}
