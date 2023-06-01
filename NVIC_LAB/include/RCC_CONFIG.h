
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



#ifndef RCC_CONGIG_H
#define RCC_CONGIG_H

/*
OPTIONS
HSI
HSE
HSE_BYP
PLL
*/
#define RCC_CPU_CLK_SOURCE    HSI



/*
OPTIONS
HSI
HSE
HSE_BYP
*/
#define PLL_CPU_CLK_SOURCE   HSI

#define RCC_AHB1 0
#define RCC_AHB2 1
#define RCC_APB1 2
#define RCC_APB2 3


/*options :

  SYSTEM_CLK
  SYSTEM_CLK_DIVIDED_2
  SYSTEM_CLK_DIVIDED_4
  SYSTEM_CLK_DIVIDED_8
  SYSTEM_CLK_DIVIDED_16
  SYSTEM_CLK_DIVIDED_64
  SYSTEM_CLK_DIVIDED_128
  SYSTEM_CLK_DIVIDED_256
  SYSTEM_CLK_DIVIDED_512

*/
#define AHB_PRESCALER    SYSTEM_CLK_DIVIDED_2


/*
options :

AHB_CLK
AHB_CLK_DIVIDED_BY_2
AHB_CLK_DIVIDED_BY_4
AHB_CLK_DIVIDED_BY_8
AHB_CLK_DIVIDED_BY_16

*/
#define APB1_PRESCALER    AHB_CLK_DIVIDED_BY_4


/*
options :

AHB_CLK
AHB_CLK_DIVIDED_BY_2
AHB_CLK_DIVIDED_BY_4
AHB_CLK_DIVIDED_BY_8
AHB_CLK_DIVIDED_BY_16

*/
#define APB2_PRESCALER    AHB_CLK_DIVIDED_BY_2





#endif