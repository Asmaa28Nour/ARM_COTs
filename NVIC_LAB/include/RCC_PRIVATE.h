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
//#include "../../LIB/STD_TYPES.h"
//#include "../../LIB/BIT_MATH.h"

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H






/*
 #define RCC_BASE_ADD     0x4002 3800

#define  RRC_CR         		      *((volatile u32 *)RCC_BASE_ADD + 0X00)
#define  RRC_CR        		          *((volatile u32 *)RCC_BASE_ADD + 0X00)
#define  RRC_CR         		      *((volatile u32 *)RCC_BASE_ADD + 0X00)
*/

typedef struct
{
    volatile u32 CR;
    volatile u32 PLLCFGR;
    volatile u32 CFGR;
    volatile u32 CIR;
    volatile u32 AHB1RSTR;
    volatile u32 AHB2RSTR;
    volatile u32 Reserved1[2];
    volatile u32 APB1RSTR;
    volatile u32 APB2RSTR;
    volatile u32 Reserved2[2];
    volatile u32 AHB1ENR;
    volatile u32 AHB2ENR;
    volatile u32 Reserved3[2];
    volatile u32 APB1ENR;
    volatile u32 APB2ENR;
    volatile u32 Reserved4[2];
    volatile u32 AHB1LPENR;
    volatile u32 AHB2LPENR;
    volatile u32 Reserved5[2];
    volatile u32 APB1LPENR;
    volatile u32 APB2LPENR;
    volatile u32 Reserved6[2];
    volatile u32 BDCR;
    volatile u32 CSR;
    volatile u32 Reserved7[2];
    volatile u32 SSCGR;
    volatile u32 PLLI2SCFGR;
    volatile u32 Reserved8;
    volatile u32 DCKCFGR;
}RCC_t;


#define  RCC         		      ((volatile RCC_t*)0x40023800)




#define HSI     0
#define HSE     1
#define HSE_BYP 2
#define PLL     3


/*
#define    RCC_AHB1ENR_GPIO_A_EN    0   
#define    RCC_AHB1ENR_GPIO_B_EN    1 
#define    RCC_AHB1ENR_GPIO_C_EN    2  
#define    RCC_AHB1ENR_GPIO_D_EN    3  
#define    RCC_AHB1ENR_GPIO_E_EN    4  
#define    RCC_AHB1ENR_GPIO_H_EN    7 
#define    RCC_AHB1ENR_CRCEN        12 
*/

#define SYSTEM_CLK                0000
#define SYSTEM_CLK_DIVIDED_2      1000
#define SYSTEM_CLK_DIVIDED_4      1001
#define SYSTEM_CLK_DIVIDED_8      1010
#define SYSTEM_CLK_DIVIDED_16     1011
#define SYSTEM_CLK_DIVIDED_64     1100
#define SYSTEM_CLK_DIVIDED_128    1101
#define SYSTEM_CLK_DIVIDED_256    1110
#define SYSTEM_CLK_DIVIDED_512    1111


#define AHB_CLK                  000
#define AHB_CLK_DIVIDED_BY_2     100
#define AHB_CLK_DIVIDED_BY_4     101
#define AHB_CLK_DIVIDED_BY_8     110
#define AHB_CLK_DIVIDED_BY_16    111


#endif