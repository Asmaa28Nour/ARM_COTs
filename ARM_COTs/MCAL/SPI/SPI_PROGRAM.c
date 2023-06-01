/*********************************************
 * Author:          Asmaa Abd EL-kareim
 * Creation Data:   30 MAY, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                    Description
 * v1.0        30 MAY, 2023    Asmaa Abd EL-kareim            Initial Creation
*********************************************/

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

//#include "STD_TYPES.h"
//#include "BIT_MATH.h"

#include "SPI_INTERFACE.h"
#include "SPI_PRIVATE.h"
#include "SPI_CONFIG.h"

void MSPI1_voidInit (void);

u8 MSPI1_u8Tranceive (u8 Copy_u8Data)
{

    SPI_1 ->DR = Copy_u8Data;

    /*wait untill SPI1 not buzy*/
    while (GET_BIT(SPI_1->SR , 7) == 1);
    
    return(SPI_1->DR)
    
}

