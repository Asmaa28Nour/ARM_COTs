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

/*
MGPIO_voidSetPinDirection :
These bits are written by software to configure the I/O direction mode.
00: Input (reset state)
01: General purpose output mode
10: Alternate function mode
11: Analog mode
*/
void MGPIO_voidSetPinDirection (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8Mode )
{
    switch(Copy_u8PortNumber)
    {   
        /*port selection*/
        case DIO_PORTA :
             
             
            
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

/*
MGPIO_voidOutputMoade :
These bits are written by software to configure the output type of the I/O port.
0: Output push-pull (reset state)
1: Output open-drain

*/
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

/*
MGPIO_voidOutPutSpeedRegister :
These bits are written by software to configure the I/O output speed.
00: Low speed --- 2M
01: Medium speed ---- 10M
10: High speed ---- 50M
11: Very high speed ---- 200M
*/
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

/*
MGPIO_voidPullUP_PullDown :
These bits are written by software to configure the I/O pull-up or pull-down
00: No pull-up, pull-down
01: Pull-up
10: Pull-down
11: Reserved
*/

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
    case DIO_PORTA:
        switch (Copy_u8HighOrLow)
        {
        case HIGH:
            SET_BIT(GPIOA ->ODR,Copy_u8PinNumber);
            break;
        case LOW:
            CLR_BIT(GPIOA ->ODR,Copy_u8PinNumber);
            break;    
        
        default:
            break;
        }
        break;

    case DIO_PORTB:
        switch (Copy_u8HighOrLow)
        {
        case HIGH:
            SET_BIT(GPIOB ->ODR,Copy_u8PinNumber);
            break;
        case LOW:
            CLR_BIT(GPIOB ->ODR,Copy_u8PinNumber);
            break;    
        
        default:
            break;
        }
        break;

    case DIO_PORTC:
        switch (Copy_u8HighOrLow)
        {
        case HIGH:
            SET_BIT(GPIOC ->ODR,Copy_u8PinNumber);
            break;
        case LOW:
            CLR_BIT(GPIOC ->ODR,Copy_u8PinNumber);
            break;    
        
        default:
            break;
        }
        break;        
    
    default:
        break;
    }
}


void MGPIO_voidSetPortValue(u8 Copy_u8PortName , u32 Copy_u32PortValue)
{ 
    switch (Copy_u8PortName)
    {
    case DIO_PORTA:
         
         GPIOA ->ODR = Copy_u32PortValue;
        break;

    case DIO_PORTB:
        
         GPIOB ->ODR = Copy_u32PortValue;
        
        break;

    case DIO_PORTC:

        GPIOC ->ODR = Copy_u32PortValue;
        
        break;        
    
    default:
        break;
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

////////////////////////////////////////////////////////////

void MGPIO_voidConfigurationLockPin (u8 Copy_u8PortName,u8 Copy_u8PinNumber, u8 Copy_u8LockStatus)
{
    switch (Copy_u8LockStatus)
    {
    case LOCK:
        switch (Copy_u8PortName)
        {
        case DIO_PORTA :
             SET_BIT(GPIOA ->LCKR,Copy_u8PinNumber);
             
            break;
        case DIO_PORTB :
             SET_BIT(GPIOB ->LCKR,Copy_u8PinNumber);
             
            break;
        case DIO_PORTC :
             SET_BIT(GPIOC ->LCKR,Copy_u8PinNumber);
             
            break;        
        
        default:
            break;
        }
        
        break;

    case UNLOCK:
        switch (Copy_u8PortName)
        {
        case DIO_PORTA :
             CLR_BIT(GPIOA ->LCKR,Copy_u8PinNumber);
             
            break;
        case DIO_PORTB :
             CLR_BIT(GPIOB ->LCKR,Copy_u8PinNumber);
             
            break;
        case DIO_PORTC :
             CLR_BIT(GPIOC ->LCKR,Copy_u8PinNumber);
             
            break;        
        
        default:
            break;
        }
        
        break;    
    
    default:
        break;
    }
    
}

void MGPIO_voidConfigurationLockEnableDisable (u8 Copy_u8LockStatus , u8 Copy_u8PortName )
{
    switch (Copy_u8LockStatus)
    {
    case ENABLE:
        
        switch (Copy_u8PortName)
        {
        case DIO_PORTA :
            SET_BIT(GPIOA ->LCKR,16);
            break;

        case DIO_PORTB :
            SET_BIT(GPIOB ->LCKR,16);
            break;
        case DIO_PORTC :
            SET_BIT(GPIOC ->LCKR,16);
            break;        
        
        default:
            break;
        }
        break;

    case DISABLE:
        switch (Copy_u8PortName)
        {
        case DIO_PORTA :
            CLR_BIT(GPIOA ->LCKR,16);
            break;

        case DIO_PORTB :
            CLR_BIT(GPIOB ->LCKR,16);
            break;
        case DIO_PORTC :
            CLR_BIT(GPIOC ->LCKR,16);
            break;        
        
        default:
            break;
        }
        break;    
    
    default:
        break;
    }
    
}


/*
These bits are written by software to configure alternate function I/Os
AFRLy selection:
0000: AF0
0001: AF1
0010: AF2
0011: AF3
0100: AF4
0101: AF5
0110: AF6
0111: AF7
1000: AF8
1001: AF9
1010: AF10
1011: AF11
1100: AF12
1101: AF13
1110: AF14
1111: AF15
*/
void MGPIO_voidAlternate (u8 Copy_u8PortName,u8 Copy_u8PinNumber, u32 Copy_u32AFunctionSelection)
{
    switch (Copy_u8PinNumber)
    {
    case DIO_PORTA:
         if (Copy_u8PinNumber < 8)
         {
            GPIOA ->AFRL = (Copy_u32AFunctionSelection<<(Copy_u8PinNumber*4));
         }
         else if (Copy_u8PinNumber < 15)
         {
            GPIOA ->AFRH = (Copy_u32AFunctionSelection<<((Copy_u8PinNumber-8)*4));
         }

         else
         {
            //error


         }

         
        break;

    case DIO_PORTB:
         if (Copy_u8PinNumber < 8)
         {
            GPIOB ->AFRL = (Copy_u32AFunctionSelection<<(Copy_u8PinNumber*4));
         }
         else if (Copy_u8PinNumber < 15)
         {
            GPIOB ->AFRH = (Copy_u32AFunctionSelection<<((Copy_u8PinNumber-8)*4));
         }

         else
         {
            //error


         }

         
        break;


    case DIO_PORTC:
         if (Copy_u8PinNumber < 8)
         {
            GPIOC ->AFRL = (Copy_u32AFunctionSelection<<(Copy_u8PinNumber*4));
         }
         else if (Copy_u8PinNumber < 15)
         {
            GPIOC ->AFRH = (Copy_u32AFunctionSelection<<((Copy_u8PinNumber-8)*4));
         }

         else
         {
            //error


         }

         
        break;        
    
    default:
        break;
    }

}


