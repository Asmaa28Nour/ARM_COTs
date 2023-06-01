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

#include "NVIC_INTERFACE.h"
#include "NVIC_PRIVATE.h"
#include "NVIC_CONFIG.h"




void MNVIC_voidINIT (void)
{
    /*set the group and sub perriorities distribution*/
    SCB_AIRCR |= (AIRCR_PRIVATE_KEY <<16) | (MNVIC_GRP_SUB_DISTRIBUTION <<8);



}




void MNVIC_voidEnablePeripheralINT (u8 Copy_u8PeriphralID)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PeriphralID /32;


    MNVIC ->ISER[Local_u8ISERIndex] = ((1<<Copy_u8PeriphralID % 32));


    
}


void MNVIC_voidDisblePeripheralINT (u8 Copy_u8PeriphralID)
{

    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PeriphralID /32;


    MNVIC ->ICER[Local_u8ISERIndex] = ((1<<Copy_u8PeriphralID % 32));

    
}



void MNVIC_voidSetPendingFlag(u8 Copy_u8PeripheralID)
{
    u8 Local_u8ISERIndex;
    Local_u8ISERIndex = Copy_u8PeripheralID / 32;
    MNVIC -> ISPR[Local_u8ISERIndex] = (1 << (Copy_u8PeripheralID%32));
}


void MNVIC_voidSetPeripheralPriority(u8 Copy_u8PeripheralID, u8 Copy_u8Priority)
{
    
    MNVIC -> IPR[Copy_u8PeripheralID] = (Copy_u8Priority << 4);
}


