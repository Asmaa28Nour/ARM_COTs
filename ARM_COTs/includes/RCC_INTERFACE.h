
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

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H


#define     DIO_PORTA          RCC_AHB1ENR_GPIO_A_EN      
#define     DIO_PORTB          RCC_AHB1ENR_GPIO_B_EN     
#define     DIO_PORTC          RCC_AHB1ENR_GPIO_C_EN      
#define     DIO_PORTD          RCC_AHB1ENR_GPIO_D_EN      
#define     DIO_PORTE          RCC_AHB1ENR_GPIO_E_EN      
#define     DIO_PORTH          RCC_AHB1ENR_GPIO_H_EN  


void MRCC_voidInit(void);



void MRCC_voidEnablePeripheralClk (u8 Copy_u8PeripherBus , u8 Copy_u8PeripherID);




void MRCC_voidDisablePeripheralClk (u8 Copy_u8PeripherBus , u8 Copy_u8PeripherID);

#endif