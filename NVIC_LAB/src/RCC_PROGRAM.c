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

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_INTERFACE.h"
#include "RCC_PRIVATE.h"
#include "RCC_CONFIG.h"




void MRCC_voidInit(void)
{
    /*select cpu clk source*/

    #if RCC_CPU_CLK_SOURCE == HSI  //SELECT INTERNAL SOURCE 16 MHZ
         //enable hsi
         SET_BIT(RCC->CR , 18);

         //SELECT SYSTEM CLK SOURCE
         CLR_BIT(RCC -> CFGR, 0);
         CLR_BIT(RCC -> CFGR, 1);


         
    #elif RCC_CPU_CLK_SOURCE == HSE  //SELECT EXTERNAL SOURCE mechanical sourece
          //enable hse
          SET_BIT(RCC->CR , 16);

          //SELECT SYSTEM CLK SOURCE
         SET_BIT(RCC -> CFGR, 0);
         CLR_BIT(RCC -> CFGR, 1);
        
    #elif RCC_CPU_CLK_SOURCE == HSE_BYP  //SELECT EXTERNAL SOURCE electrical source 
          // enable hse by pass system
          SET_BIT(RCC->CR , 18);    

          //SELECT SYSTEM CLK SOURCE
          SET_BIT(RCC -> CFGR, 0);
          CLR_BIT(RCC -> CFGR, 1);  
        
    #elif RCC_CPU_CLK_SOURCE == PLL  //SELECT PLL SOURCE
           //enable pll
            SET_BIT(RCC->CR , 24); 

            

           #if PLL_CPU_CLK_SOURCE == HSI  //SELECT INTERNAL SOURCE
              //enable hsi
               SET_BIT(RCC->CR , 18);


               //SELECT SYSTEM CLK SOURCE
               CLR_BIT(RCC -> CFGR, 0);
               SET_BIT(RCC -> CFGR, 1);

              
           #elif PLL_CPU_CLK_SOURCE == HSE  //SELECT EXTERNAL SOURCE mechanical sourece
              //enable hse
              SET_BIT(RCC->CR , 16);

              //SELECT SYSTEM CLK SOURCE
              CLR_BIT(RCC -> CFGR, 0);
              SET_BIT(RCC -> CFGR, 1);
              #else
              #error"PLL config error"

               #endif

    #else
    #error"RCC config error"

    #endif

/*AHB prescaler factor , AHB CLK = system CLK / divison factor*/
#if RCC_AHB_PRESCALER > 15
    #error "RCC_AHB_PRESCALER Configuration Error"
#else 
    RCC -> CFGR &= 0xFFFFFF0F;
    RCC->CFGR |= (AHB_PRESCALER<<4);
#endif    

/*APB1 prescaler factor , APB1 CLK = AHB CLK / divison factor*/ //"Low spead"
/*The software has to set these bits correctly not to exceed 42 MHz on this domain */
#if RCC_AHB_PRESCALER > 7
    #error "RCC_APB1_PRESCALER Configuration Error"
#else 
    RCC -> CFGR &= 0xFFFFE3FF;
    RCC->CFGR |= (APB1_PRESCALER<<10);
#endif 
  

/*APB2 prescaler factor , APB2 CLK = AHB CLK / divison factor*/ //"High spead"
/*The software has to set these bits correctly not to exceed 84 MHz on this domain*/
  
  #if RCC_AHB_PRESCALER > 7
    #error "RCC_APB2_PRESCALER Configuration Error"
#else 
    RCC -> CFGR &= 0xFFFF1FFF;
    RCC->CFGR |= (APB2_PRESCALER<<13);
#endif 


}







void MRCC_voidEnablePeripheralClk (u8 Copy_u8PeripherBus , u8 Copy_u8PeripherID)
{

  switch(Copy_u8PeripherBus)
    {
        case RCC_AHB1:
            SET_BIT(RCC->AHB1ENR, Copy_u8PeripherID);
        break;
        case RCC_AHB2:
            SET_BIT(RCC->AHB2ENR, Copy_u8PeripherID);
        break;
        case RCC_APB1:
            SET_BIT(RCC->APB1ENR, Copy_u8PeripherID);
        break;
        case RCC_APB2:
            SET_BIT(RCC->APB2ENR, Copy_u8PeripherID);
        break;
        default:
            
        break;
    }

}

void MRCC_voidDisablePeripheralClk (u8 Copy_u8PeripherBus , u8 Copy_u8PeripherID)
{
    switch(Copy_u8PeripherBus)
    {
        case RCC_AHB1:
            CLR_BIT(RCC->AHB1ENR, Copy_u8PeripherID);
        break;
        case RCC_AHB2:
            CLR_BIT(RCC->AHB2ENR, Copy_u8PeripherID);
        break;
        case RCC_APB1:
            CLR_BIT(RCC->APB1ENR, Copy_u8PeripherID);
        break;
        case RCC_APB2:
            CLR_BIT(RCC->APB2ENR, Copy_u8PeripherID);
        break;
        default:
            
        break;
    }
    
}
