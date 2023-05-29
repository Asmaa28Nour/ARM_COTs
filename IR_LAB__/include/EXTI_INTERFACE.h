/*********************************************
 * Author:          Asmaa Abd EL-kareim
 * Creation Data:   22 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                    Description
 * v1.0        22 MAY, 2023    Asmaa Abd EL-kareim            Initial Creation
*********************************************/

#ifndef EXTI_INTERRFACE_H
#define EXTI_INTEFACE_H



void MXTI_voidInit(void);
void MXTI_voidEnableInterupt(u8 Copy_u8EXTILine);
void MXTI_voidDisableInterupt(u8 Copy_u8EXTILine);
void MXTI_voidChangeSenceMode(u8 Copy_u8EXTILine , u8 Copy_u8SenseSignal);
void MXTI_voidSetCallBack(u8 Copy_u8EXTILine , void (*PNotifficationFnction)(void));
#define MEXTI_RISING_EDGE  0
#define MEXTI_FALLING_EDGE  1
#define MEXTI_ON_CHANGE_EDGE  2

#define MEXTI_LINE_0  0


#endif
