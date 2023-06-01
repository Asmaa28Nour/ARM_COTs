
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

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H



#define    RCC_AHB1ENR_GPIO_A_EN    0   
#define    RCC_AHB1ENR_GPIO_B_EN    1 
#define    RCC_AHB1ENR_GPIO_C_EN    2  
#define    RCC_AHB1ENR_GPIO_D_EN    3  
#define    RCC_AHB1ENR_GPIO_E_EN    4  
#define    RCC_AHB1ENR_GPIO_H_EN    7 
#define    RCC_AHB1ENR_CRCEN        12 


#define RCC_AHB1     0
#define RCC_AHB2     1
#define RCC_APB1     2
#define RCC_APB2     3


void MRCC_voidInit(void);
void MRCC_voidEnablePeripheralClk (u8 Copy_u8PeripherBus , u8 Copy_u8PeripherID);
void MRCC_voidDisablePeripheralClk (u8 Copy_u8PeripherBus , u8 Copy_u8PeripherID);

#endif