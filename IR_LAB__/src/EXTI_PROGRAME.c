/*********************************************
 * Author:          Asmaa Abd EL-kareim
 * Creation Data:   15 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                    Description
 * v1.0        15 MAY, 2023    Asmaa Abd EL-kareim            Initial Creation
*********************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_INTERFACE.h"
#include "EXTI_PRIVATE.h"
#include "EXTI_CONFIG.h"

void (*PVCallBack[16])(void) = {{NULL}};

void MXTI_voidInit(void)
{

}
void MXTI_voidEnableInterupt(u8 Copy_u8EXTILine)
{
    if (Copy_u8EXTILine < 16)
    {
   SET_BIT (MEXTI ->IMR , Copy_u8EXTILine);
    }
    else
    {
        return;
    }
}

void MXTI_voidDisableInterupt(u8 Copy_u8EXTILine)
{
    

}

void MXTI_voidChangeSenceMode(u8 Copy_u8EXTILine , u8 Copy_u8SenseSignal)
{
    switch (Copy_u8SenseSignal)
    {
    case MEXTI_RISING_EDGE:
         CLR_BIT (MEXTI->FSTR ,Copy_u8EXTILine );  //CLR RAISINGG EDGE SENSE MODE  
         SET_BIT (MEXTI->RSTR ,Copy_u8EXTILine );   //SET FALLING EDGE SENSE MODE
       
        break;
    case MEXTI_FALLING_EDGE:
         
         CLR_BIT (MEXTI->RSTR ,Copy_u8EXTILine );
         SET_BIT (MEXTI->FSTR ,Copy_u8EXTILine );
         
       
        break;
    case MEXTI_ON_CHANGE_EDGE:
         
         SET_BIT (MEXTI->RSTR ,Copy_u8EXTILine );
         SET_BIT (MEXTI->FSTR ,Copy_u8EXTILine );
       
        break;        
    
    default:
        break;
    }

}
void MXTI_voidSetCallBack(u8 Copy_u8EXTILine , void (*PNotifficationFnction)(void))
{
    if (Copy_u8EXTILine < 16)
    {
   PVCallBack[Copy_u8EXTILine] = PNotifficationFnction; 
    }
    else
    {

    }
}

void EXTI0_IRQHandler(void)
{
    if (PVCallBack [0]!= NULL)    //3mlna el if 3lshan myd5olsh f el defalt handller ""
    {
    PVCallBack[0]();
    SET_BIT(MEXTI ->PR , 0);

    }
    else
    {
        // Do nothing
    }
}


