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

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#include "SYSTICK_INTERFACE.h"
#include "SYSTICK_PRIVATE.h"
#include "SYSTICK_CONFIG.h"

static void (*CallBackFunction)(void) = NULL;
static u8 u8IntervalFlag = SINGLE_INTERVAL;

void MSystick_voidInit (void)
{
    #if SYSTICK_CLK_COURCE == SYSTEM_CLK
     SET_BIT(SYSTICK->STK_CTRL , 2);

    #elif SYSTICK_CLK_COURCE == SYSTEM_CLK_8
     CLR_BIT(SYSTICK->STK_CTRL , 2);

    #else
    #error"systick config error"

    #endif

    #if SYSTICK_CLK_ENABLE == ENABLE
     SET_BIT(SYSTICK->STK_CTRL , 0);

    #elif SYSTICK_CLK_ENABLE == DISABLE
     CLR_BIT(SYSTICK->STK_CTRL , 0);

    #else
    #error"systick config error"

    #endif


    #if SYSTICK_INIT_ENABLE == ENABLE
     SET_BIT(SYSTICK->STK_CTRL , 1);

    #elif SYSTICK_INIT_ENABLE == DISABLE
     CLR_BIT(SYSTICK->STK_CTRL , 1);

    #else
    #error"systick config error"

    #endif
}



void MSystick_voidBuzyWait(u32 Copy_u32TimeInMicro) //no must be written in 24 bit or less
{
   SYSTICK->STK_LOAD = Copy_u32TimeInMicro; 
   while (GET_BIT(SYSTICK->STK_CTRL , 16) == 0);
   SYSTICK->STK_VAL = 0; 


}

void MSystick_VoidSetSingleEnterval(void ((*NotificatiomFunction)(void)), u32 Copy_u32TimeInMicro )
{
   SYSTICK->STK_LOAD = Copy_u32TimeInMicro;
  CallBackFunction = NotificatiomFunction ; 

   /*enable ENT*/
   SET_BIT(SYSTICK->STK_CTRL , 1);
   /*enable SYSTIC*/
   SET_BIT(SYSTICK->STK_CTRL , 0);
   
   u8IntervalFlag = SINGLE_INTERVAL;



}

void MSystick_VoidSetPeriodicEnterval(void (*NotificatiomFunction)(void), u32 Copy_u32TimeInMicro )
{
   SYSTICK->STK_LOAD = Copy_u32TimeInMicro;
   CallBackFunction = NotificatiomFunction ; 

   /*enable ENT*/
   SET_BIT(SYSTICK->STK_CTRL , 1);
   /*enable SYSTIC*/
   SET_BIT(SYSTICK->STK_CTRL , 0);

   u8IntervalFlag = PERIODIC_INTERVAL ;
   


}

void SysTick_Handler(void)
{
	u32 Local_u32TempVar;
	if(u8IntervalFlag == SINGLE_INTERVAL)
	{
		SYSTICK->STK_LOAD = 0;
		SYSTICK->STK_VAL = 0;
        /*DISABLE SYSTICK*/
		CLR_BIT(SYSTICK->STK_CTRL, 0);
	}
    else
    {

    }
    
	if(CallBackFunction != NULL)
	{
		CallBackFunction();
	}
	else
    {
        
    }
}

void MSystick_voidSetPreLoadValue(u32 Copy_u8LoadValue)
{
	SYSTICK-> STK_LOAD = Copy_u8LoadValue;
}

void MSystick_voidResetSysTick(void)
{
	SYSTICK-> STK_VAL = 0;
}

u32 MSTK_u32GetElapsedTime(void)
{
    u32 Local_u32RemainingTime;
	Local_u32RemainingTime = SYSTICK-> STK_VAL;
	return Local_u32RemainingTime;
	
}

u32 MSTK_u32GetRemainingTime(void)
{
    u32 Local_u32ElapsedTime;
	Local_u32ElapsedTime = SYSTICK-> STK_LOAD - SYSTICK-> STK_VAL;
	return Local_u32ElapsedTime;
	
}