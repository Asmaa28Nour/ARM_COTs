
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


#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H




#define  OUTPUT        1
#define  ANALOG        3
#define  ALTERNATE     2
#define  INPUT         0

#define PUSH_PULL      0
#define OPEN_DRAIN     1

#define PULL_UP         0
#define PULL_DOWN       1
#define NO_PULL         2


#define OUTPUT_SWITCH_SPEED_2M    0
#define OUTPUT_SWITCH_SPEED_10M   1
#define OUTPUT_SWITCH_SPEED_50M   2
#define OUTPUT_SWITCH_SPEED_200M  3

#define PIN0    0
#define PIN1    1
#define PIN2    2
#define PIN3    3
#define PIN4    4
#define PIN5    5
#define PIN6    6
#define PIN7    7
#define PIN8    8
#define PIN9    9
#define PIN10    10
#define PIN11    11
#define PIN12    12
#define PIN13    13
#define PIN14    14
#define PIN15    15



#define     DIO_PORTA       0    
#define     DIO_PORTB       1 
#define     DIO_PORTC       2


#define HIGH  1
#define LOW   0

#define SET     1
#define RESET   0

#define ENABLE  1
#define DISABLE 0

#define LOCK   1
#define UNLOCK 0



#define   AF0        0000
#define   AF1        0001
#define   AF2        0010
#define   AF3        0011
#define   AF4        0100
#define   AF5        0101
#define   AF6        0110
#define   AF7        0111
#define   AF8        1000
#define   AF9        1001
#define   AF10       1010
#define   AF11       1011
#define   AF12       1100
#define   AF13       1101
#define   AF14       1110
#define   AF15       1111



#define     PORTA          RCC_AHB1ENR_GPIO_A_EN      
#define     PORTB          RCC_AHB1ENR_GPIO_B_EN     
#define     PORTC          RCC_AHB1ENR_GPIO_C_EN      
#define     PORTD          RCC_AHB1ENR_GPIO_D_EN      
#define     PORTE          RCC_AHB1ENR_GPIO_E_EN      
#define     PORTH          RCC_AHB1ENR_GPIO_H_EN  


#define GPIO_BSRR_PIN0				0b00000000000000000000000000000001    ///  0b 0000 0000 0000 0000
#define GPIO_BSRR_PIN1				0b00000000000000000000000000000010    /// 0000000000000000
#define GPIO_BSRR_PIN2				0b00000000000000000000000000000100
#define GPIO_BSRR_PIN3				0b00000000000000000000000000001000
#define GPIO_BSRR_PIN4				0b00000000000000000000000000010000
#define GPIO_BSRR_PIN5				0b00000000000000000000000000100000
#define GPIO_BSRR_PIN6				0b00000000000000000000000001000000
#define GPIO_BSRR_PIN7				0b00000000000000000000000010000000
#define GPIO_BSRR_PIN8				0b00000000000000000000000100000000
#define GPIO_BSRR_PIN9				0b00000000000000000000001000000000
#define GPIO_BSRR_PIN10				0b00000000000000000000010000000000
#define GPIO_BSRR_PIN11				0b00000000000000000000100000000000
#define GPIO_BSRR_PIN12				0b00000000000000000001000000000000
#define GPIO_BSRR_PIN13				0b00000000000000000010000000000000
#define GPIO_BSRR_PIN14				0b00000000000000000100000000000000
#define GPIO_BSRR_PIN15  			0b00000000000000001000000000000000

void MGPIO_voidInit(void);
void MGPIO_voidSetPinDirection (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8Mode );
void MGPIO_voidOutputMoade (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8OutputMode );
void MGPIO_voidOutPutSpeedRegister (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8OutPutSpeed);
void MGPIO_voidPullUP_PullDown (u8 Copy_u8PortNumber , u8 Copy_u8PinNumber , u8 Copy_u8PullUpPullDown);
u8 MGPIO_u8GetPinValue(u8 Copy_u8PortNumber , u8 Copy_u8PinNumber);
void MGPIO_voidSetPinValue(u8 Copy_u8PortName , u8 Copy_u8PinNumber , u8 Copy_u8HighOrLow);
void MGPIO_voidSetPortValue(u8 Copy_u8PortName , u32 Copy_u32PortValue);
void MGPIO_voidAtomicSetPinValue(u8 Copy_u8PortName,u32 Copy_32PinNumber,u8 Copy_u8PinValue);
void MGPIO_voidConfigurationLockPin (u8 Copy_u8PortName,u8 Copy_u8PinNumber, u8 Copy_u8LockStatus);
void MGPIO_voidConfigurationLockEnableDisable (u8 Copy_u8LockStatus , u8 Copy_u8PortName );


#endif
