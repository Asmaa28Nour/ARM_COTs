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
#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


void MSystick_voidInit (void);



void MSystick_voidBuzyWait(u32 Copy_u32TimeInMicro); //no must be written in 24 bit or less



void MSystick_VoidSetSingleEnterval(void ((*NotificatiomFunction)(void)), u32 Copy_u32TimeInMicro );



void MSystick_VoidSetPeriodicEnterval(void (*NotificatiomFunction)(void), u32 Copy_u32TimeInMicro );


void SysTick_Handler(void);


void MSystick_voidSetPreLoadValue(u32 Copy_u8LoadValue);


void MSystick_voidResetSysTick(void);



u32 MSTK_u32GetElapsedTime(void);



u32 MSTK_u32GetRemainingTime(void);


#endif
