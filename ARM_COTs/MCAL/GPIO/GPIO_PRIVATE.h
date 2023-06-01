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


#ifndef GPIO_PRIVATE_H
#define GPIO_PRIVATE_H

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"




/*
 #define RCC_BASE_ADD     0x4002 3800

#define  RRC_CR         		      *((volatile u32 *)RCC_BASE_ADD + 0X00)
#define  RRC_CR        		          *((volatile u32 *)RCC_BASE_ADD + 0X00)
#define  RRC_CR         		      *((volatile u32 *)RCC_BASE_ADD + 0X00)
*/

typedef struct 
{
   volatile u32  MODER ;
   volatile u32  OTYPER ;
   volatile u32  OSPEEDR ;
   volatile u32  PUPDR ;
   volatile u32  IDR ;
   volatile u32  ODR ;
   volatile u32  BSRR ;
   volatile u32  LCKR ;
   volatile u32  AFRL ;
   volatile u32  AFRH ;
     
}GPIO_t;

#define  GPIOC         		      ((volatile GPIO_t*)0x40020800)
#define  GPIOB         		      ((volatile GPIO_t*)0x40020400)
#define  GPIOA         		      ((volatile GPIO_t*)0x40020000)




/*
#define    RCC_AHB1ENR_GPIO_A_EN    0   
#define    RCC_AHB1ENR_GPIO_B_EN    1 
#define    RCC_AHB1ENR_GPIO_C_EN    2  
#define    RCC_AHB1ENR_GPIO_D_EN    3  
#define    RCC_AHB1ENR_GPIO_E_EN    4  
#define    RCC_AHB1ENR_GPIO_H_EN    7 
#define    RCC_AHB1ENR_CRCEN        12 
*/

  



#endif