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



MXTI_voidInit(void);
MXTI_voidEnableInterupt(u8 Copy_u8EXTILine);
MXTI_voidDisableInterupt(u8 Copy_u8EXTILine);
MXTI_voidChangeSenceMode(u8 Copy_u8EXTILine , u8 Copy_u8SenseSignal);
MXTI_voidChangeSenceMode(u8 Copy_u8EXTILine , void (*PNotifficationFnction)(void));

#define MEXTI_RISING_EDGE  0
#define MEXTI_FALLING_EDGE  1
#define MEXTI_ON_CHANGE_EDGE  2



#endif