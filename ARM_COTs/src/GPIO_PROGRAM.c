/*********************************************
 * Author:          Asmaa Abd EL-kareim
 * Creation Data:   30 MAR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                    Description
 * v1.0        09 APR, 2023    Asmaa Abd EL-kareim          Initial Creation
*********************************************/



#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
//#include "RCC_INTERFACE.h"
#include "GPIO_INTERFACE.h"
#include "GPIO_PRIVATE.h"
#include "GPIO_CONFIG.h"


void MGPIO_voidInit(void)
{

}

void MGPIO_voidSetPinDirection (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8Mode )
{
    switch(Copy_u8PortNumber)
    {   
        /*port selection*/
        case DIO_PORTA :
             
             /*enable PORTA CLK */
            
            /*Mode selection*/
             switch (Copy_u8Mode )
             {
             case INPUT:
                CLR_BIT(GPIOA ->MODER,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOA ->MODER,((Copy_u8PinNumber*2)+1));
            break;

            case OUTPUT:
                SET_BIT(GPIOA ->MODER,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOA ->MODER,((Copy_u8PinNumber*2)+1));
            break;


            case ALTERNATE:
                CLR_BIT(GPIOA ->MODER,(Copy_u8PinNumber*2));
                SET_BIT(GPIOA ->MODER,((Copy_u8PinNumber*2)+1));
            break;


            case ANALOG:
                SET_BIT(GPIOA ->MODER,(Copy_u8PinNumber*2));
                SET_BIT(GPIOA ->MODER,((Copy_u8PinNumber*2)+1));
            break;
 
             default:
                break;
             }

            break ; 

    case DIO_PORTB :
             
             /*enable PORTB CLK */
            
            /*Mode selection*/
             switch (Copy_u8Mode )
             {
             case INPUT:
                CLR_BIT(GPIOB ->MODER,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOB ->MODER,((Copy_u8PinNumber*2)+1));
            break;

            case OUTPUT:
                SET_BIT(GPIOB ->MODER,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOB ->MODER,((Copy_u8PinNumber*2)+1));
            break;


            case ALTERNATE:
                CLR_BIT(GPIOB ->MODER,(Copy_u8PinNumber*2));
                SET_BIT(GPIOB ->MODER,((Copy_u8PinNumber*2)+1));
            break;


            case ANALOG:
                SET_BIT(GPIOB ->MODER,(Copy_u8PinNumber*2));
                SET_BIT(GPIOB ->MODER,((Copy_u8PinNumber*2)+1));
            break;
 
             default:
                break;
             }

            break ; 


    case DIO_PORTC :
             
             /*enable PORTC CLK */
            
            /*Mode selection*/
             switch (Copy_u8Mode )
             {
             case INPUT:
                CLR_BIT(GPIOC ->MODER,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOC ->MODER,((Copy_u8PinNumber*2)+1));
            break;

            case OUTPUT:
                SET_BIT(GPIOC ->MODER,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOC ->MODER,((Copy_u8PinNumber*2)+1));
            break;


            case ALTERNATE:
                CLR_BIT(GPIOC ->MODER,(Copy_u8PinNumber*2));
                SET_BIT(GPIOC ->MODER,((Copy_u8PinNumber*2)+1));
            break;


            case ANALOG:
                SET_BIT(GPIOC ->MODER,(Copy_u8PinNumber*2));
                SET_BIT(GPIOC ->MODER,((Copy_u8PinNumber*2)+1));
            break;
 
             default:
                break;
             }

            break ; 

    default:
      break;
    }
   
}

void MGPIO_voidOutputMoade (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8OutputMode )
{

    switch (Copy_u8OutputMode)
    {
    case PUSH_PULL :
        switch (Copy_u8PortNumber)
        {
        case DIO_PORTA :
             
             CLR_BIT(GPIOA ->OTYPER,Copy_u8PinNumber);
             

            break;

        case DIO_PORTB :
             
             CLR_BIT(GPIOB ->OTYPER,Copy_u8PinNumber);
             

            break;

        case DIO_PORTC :
             
             CLR_BIT(GPIOC ->OTYPER,Copy_u8PinNumber);
             

            break;        
        
        default:
            break;
        }
		break;

    case OPEN_DRAIN :
        switch (Copy_u8PortNumber)
        {
        case DIO_PORTA :
             
             SET_BIT(GPIOA ->OTYPER,Copy_u8PinNumber);
             

            break;

        case DIO_PORTB :
             
             SET_BIT(GPIOB ->OTYPER,Copy_u8PinNumber);
             

            break;

        case DIO_PORTC :
             
             SET_BIT(GPIOC ->OTYPER,Copy_u8PinNumber);
             

            break;        
        
        default:
            break;
        }     
        
        break;
    
    default:
        break;
    }
    
}

void MGPIO_voidOutPutSpeedRegister (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8OutPutSpeed)
{
    switch(Copy_u8PortNumber)
    {   
        /*port selection*/
        case DIO_PORTA :     
            
              /*Speed selection*/
             switch (Copy_u8OutPutSpeed)
             {
             case OUTPUT_SWITCH_SPEED_2M:
                CLR_BIT(GPIOA ->OSPEEDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOA ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;

            case OUTPUT_SWITCH_SPEED_10M:
                SET_BIT(GPIOA ->OSPEEDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOA ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;


            case OUTPUT_SWITCH_SPEED_50M:
                CLR_BIT(GPIOA ->OSPEEDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOA ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;


            case OUTPUT_SWITCH_SPEED_200M:
                SET_BIT(GPIOA ->OSPEEDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOA ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;
 
             default:
                break;
             }

            break ; 

    case DIO_PORTB :
             
             
            
           /*Speed selection*/
             switch (Copy_u8OutPutSpeed)
             {
             case OUTPUT_SWITCH_SPEED_2M:
                CLR_BIT(GPIOB ->OSPEEDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOB ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;

            case OUTPUT_SWITCH_SPEED_10M:
                SET_BIT(GPIOB ->OSPEEDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOB ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;


            case OUTPUT_SWITCH_SPEED_50M:
                CLR_BIT(GPIOB ->OSPEEDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOB ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;


            case OUTPUT_SWITCH_SPEED_200M:
                SET_BIT(GPIOB ->OSPEEDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOB ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;
 
             default:
                break;
             }
            break ; 


    case DIO_PORTC :
             
             
          /*Speed selection*/
             switch (Copy_u8OutPutSpeed)
             {
             case OUTPUT_SWITCH_SPEED_2M:
                CLR_BIT(GPIOC ->OSPEEDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOC ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;

            case OUTPUT_SWITCH_SPEED_10M:
                SET_BIT(GPIOC ->OSPEEDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOC ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;


            case OUTPUT_SWITCH_SPEED_50M:
                CLR_BIT(GPIOC ->OSPEEDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOC ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;


            case OUTPUT_SWITCH_SPEED_200M:
                SET_BIT(GPIOC ->OSPEEDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOC ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;
 
             default:
                break;
             }
            break ; 

    default:
      break;
    }
   
}



void MGPIO_voidPullUP_PullDown (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8PullUpPullDown)
{
    switch(Copy_u8PortNumber)
    {   
        /*port selection*/
        case DIO_PORTA :     
            
              /*PULL UP / PULL DOWN / NO PULL SELECTION selection*/
             switch (Copy_u8PullUpPullDown)
             {
             case NO_PULL:
                CLR_BIT(GPIOA ->PUPDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOA ->PUPDR,((Copy_u8PinNumber*2)+1));
            break;

            case PULL_UP:
                SET_BIT(GPIOA ->PUPDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOA ->PUPDR,((Copy_u8PinNumber*2)+1));
            break;


            case PULL_DOWN:
                CLR_BIT(GPIOA ->PUPDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOA ->PUPDR,((Copy_u8PinNumber*2)+1));
            break;
             default:
                break;
             }

            break ;

    /*port selection*/
        case DIO_PORTB :     
            
              /*PULL UP / PULL DOWN / NO PULL SELECTION selection*/
             switch (Copy_u8PullUpPullDown)
             {
             case NO_PULL:
                CLR_BIT(GPIOB ->PUPDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOB ->PUPDR,((Copy_u8PinNumber*2)+1));
            break;

            case PULL_UP:
                SET_BIT(GPIOB ->PUPDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOB ->PUPDR,((Copy_u8PinNumber*2)+1));
            break;


            case PULL_DOWN:
                CLR_BIT(GPIOB ->PUPDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOB ->PUPDR,((Copy_u8PinNumber*2)+1));
            break;
             default:
                break;
             }

            break ;



    /*port selection*/
        case DIO_PORTC :     
            
              /*PULL UP / PULL DOWN / NO PULL SELECTION selection*/
             switch (Copy_u8PullUpPullDown)
             {
             case NO_PULL:
                CLR_BIT(GPIOC ->PUPDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOC ->PUPDR,((Copy_u8PinNumber*2)+1));
            break;

            case PULL_UP:
                SET_BIT(GPIOC ->PUPDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOC ->PUPDR,((Copy_u8PinNumber*2)+1));
            break;


            case PULL_DOWN:
                CLR_BIT(GPIOC ->PUPDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOC ->PUPDR,((Copy_u8PinNumber*2)+1));
            break;
             default:
                break;
             }

            break ;                 

    
    default:
      break;
    }
   
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8PortNumber , u8 Copy_u8PinNumber)
{
	u8 Local_u8ReturnedValue;

switch(Copy_u8PortNumber)
    {   
        /*port selection*/
        case DIO_PORTA :     
            
        	Local_u8ReturnedValue = GET_BIT(GPIOA ->IDR,Copy_u8PinNumber);

            break ; 
        case DIO_PORTB :     
            
        	Local_u8ReturnedValue = GET_BIT(GPIOB->IDR,Copy_u8PinNumber);

            break ; 
        case DIO_PORTC :     
            
        	Local_u8ReturnedValue = GET_BIT(GPIOC ->IDR,Copy_u8PinNumber);

            break ;         

    
    default:
      break;
    }
   return Local_u8ReturnedValue ;
}


void MGPIO_voidSetPinValue(u8 Copy_u8PortName , u8 Copy_u8PinNumber , u8 Copy_u8HighOrLow)
{ 
	


	switch (Copy_u8PortName)
	{
	case DIO_PORTA :
		switch(Copy_u8HighOrLow)
		{
		/*OUTPUT SELECTION "high or low" */
		case HIGH :

			SET_BIT(GPIOA ->ODR,Copy_u8PinNumber);

			break ;
		case LOW :

			CLR_BIT(GPIOA->ODR,Copy_u8PinNumber);

			break ;

		case DIO_PORTB :
			switch(Copy_u8HighOrLow)
			{
			/*OUTPUT SELECTION "high or low" */
			case HIGH :

				SET_BIT(GPIOB ->ODR,Copy_u8PinNumber);

				break ;
			case LOW :

				CLR_BIT(GPIOB->ODR,Copy_u8PinNumber);

				break ;

			case DIO_PORTC :
				switch(Copy_u8HighOrLow)
				{
				/*OUTPUT SELECTION "high or low" */
				case HIGH :

					SET_BIT(GPIOC ->ODR,Copy_u8PinNumber);

					break ;
				case LOW :

					CLR_BIT(GPIOC->ODR,Copy_u8PinNumber);

					break ;



				default:
					break;
				}
			}

		}
	}
}



/*
void MGPIO_voidSetResetValue(GPIO_t* Copy_GPIO_tPORT , u8 Copy_u8Value )
{
    
      Copy_GPIO_tPORT->BSRR = Copy_u8Value;

}
*/


/*
void MGPIO_voidGetPinValue_LinkerTime(GPIO_t* Copy_GPIO_tPORT , u8 Copy_u8PinNumber)
{
    switch(Copy_u8PortNumber)
    {   
        
        case DIO_PORTA :     
            
              
             switch (Copy_u8OutPutSpeed)
             {
             case OUTPUT_SWITCH_SPEED_2M:
                CLR_BIT(GPIOA ->OSPEEDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOA ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;

            case OUTPUT_SWITCH_SPEED_10M:
                SET_BIT(GPIOA ->OSPEEDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOA ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;


            case OUTPUT_SWITCH_SPEED_50M:
                CLR_BIT(GPIOA ->OSPEEDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOA ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;


            case OUTPUT_SWITCH_SPEED_200M:
                SET_BIT(GPIOA ->OSPEEDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOA ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;
 
             default:
                break;
             }

            break ; 

    case DIO_PORTB :
             
             
            
           
             switch (Copy_u8OutPutSpeed)
             {
             case OUTPUT_SWITCH_SPEED_2M:
                CLR_BIT(GPIOB ->OSPEEDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOB ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;

            case OUTPUT_SWITCH_SPEED_10M:
                SET_BIT(GPIOB ->OSPEEDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOB ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;


            case OUTPUT_SWITCH_SPEED_50M:
                CLR_BIT(GPIOB ->OSPEEDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOB ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;


            case OUTPUT_SWITCH_SPEED_200M:
                SET_BIT(GPIOB ->OSPEEDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOB ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;
 
             default:
                break;
             }
            break ; 


    case DIO_PORTC :
             
           
             switch (Copy_u8OutPutSpeed)
             {
             case OUTPUT_SWITCH_SPEED_2M:
                CLR_BIT(GPIOC ->OSPEEDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOC ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;

            case OUTPUT_SWITCH_SPEED_10M:
                SET_BIT(GPIOC ->OSPEEDR,(Copy_u8PinNumber*2));
                CLR_BIT(GPIOC ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;


            case OUTPUT_SWITCH_SPEED_50M:
                CLR_BIT(GPIOC ->OSPEEDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOC ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;


            case OUTPUT_SWITCH_SPEED_200M:
                SET_BIT(GPIOC ->OSPEEDR,(Copy_u8PinNumber*2));
                SET_BIT(GPIOC ->OSPEEDR,((Copy_u8PinNumber*2)+1));
            break;
 
             default:
                break;
             }
            break ; 

    default:
      break;
    }
   
}
*/


void MGPIO_voidAtomicSetPinValue(u8 Copy_u8PortName,u32 Copy_32PinNumber,u8 Copy_u8PinValue)
{
	switch(Copy_u8PortName)
	{
		case DIO_PORTA :
			if (Copy_u8PinValue == LOW)
			{
				Copy_32PinNumber = Copy_32PinNumber<<16;
        
				GPIOA-> BSRR = Copy_32PinNumber;
			}
			else if (Copy_u8PinValue == HIGH)
			{
				GPIOA-> BSRR = Copy_32PinNumber;
			}
			else
			{
				// Error
			}
		break;
		case DIO_PORTB :
			if (Copy_u8PinValue == LOW)
			{
				Copy_32PinNumber = Copy_32PinNumber<<16;
        
				GPIOB-> BSRR = Copy_32PinNumber;
			}
			else if (Copy_u8PinValue == HIGH)
			{
				GPIOB-> BSRR = Copy_32PinNumber;
			}
			else
			{
				// Error
			}
		break;
        case DIO_PORTC :
			if (Copy_u8PinValue == LOW)
			{
				Copy_32PinNumber = Copy_32PinNumber<<16;
        
				GPIOC-> BSRR = Copy_32PinNumber;
			}
			else if (Copy_u8PinValue == HIGH)
			{
				GPIOC-> BSRR = Copy_32PinNumber;
			}
			else
			{
				// Error
			}
		break;

        default:
        break;
}
}
