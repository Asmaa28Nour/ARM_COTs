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

#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H



typedef struct 
{
volatile u32 IMR ;
volatile u32 EMR ;
volatile u32 RSTR ;
volatile u32 FSTR ;
volatile u32 SWIER ;
volatile u32 PR ;



   
}EXTI_t;

#define  MEXTI         		          ((volatile EXTI_t*)0x40013C00)

#define    SYSCFG_ CR1                *((volatile u32 *)0x40013808)


#define GRP_4_SUB_0_BITS    0b000
#define GRP_3_SUB_1_BITS    0b100
#define GRP_2_SUB_2_BITS    0b101
#define GRP_1_SUB_3_BITS    0b110
#define GRP_0_SUB_4_BITS    0b111



#define AIRCR_PRIVATE_KEY 0x05FA

#endif