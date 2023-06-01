


void RGB_voidInit (void);


void main (void)

{
        MRCC_voidInit();
		MRCC_voidEnablePeripheralClk(RCC_AHB1,RCC_AHB1ENR_GPIO_A_EN);

		/*IR Sensor Pin as pull up input*/
		MGPIO_voidSetPinDirection (DIO_PORTA , PIN0, INPUT);
		MGPIO_voidPullUP_PullDown (DIO_PORTA , PIN0 ,PULL_UP);



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