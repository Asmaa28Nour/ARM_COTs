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

#ifndef SYSTICK_PRIVATE_H
#define SYSTICK_PRIVATE_H



typedef struct 
{
   volatile u32 STK_CTRL ;
   volatile u32 STK_LOAD ;
   volatile u32 STK_VAL ;
   volatile u32 STK_CALIB ;
   
}SYSTICK_t;

#define  SYSTICK         		      ((volatile SYSTICK_t*)0xE000E010)

#define SYSTEM_CLK    0
#define SYSTEM_CLK_8  1

#define  ENABLE    1
#define  DISABLE  0

#define SINGLE_INTERVAL 0
#define PERIODIC_INTERVAL 1


#endif