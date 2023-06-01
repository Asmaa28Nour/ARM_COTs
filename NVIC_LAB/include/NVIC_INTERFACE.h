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

#ifndef NVIC_INTERRFACE_H
#define NVIC_INTEFACE_H


void MNVIC_voidINIT (void);

void MNVIC_voidEnablePeripheralINT (u8 Copy_u8PeriphralID);

void MNVIC_voidDisblePeripheralINT (u8 Copy_u8PeriphralID);

void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID);

void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority);


#define  MNVIC_EXTI0       6
#define  MNVIC_EXTI1       7





#endif