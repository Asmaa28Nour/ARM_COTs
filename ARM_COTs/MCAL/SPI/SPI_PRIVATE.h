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

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H



typedef struct {

	volatile u32 CR1;
	volatile u32 CR2;
	volatile u32 SR;
	volatile u32 DR ;
	volatile u32 CRCPR;
	volatile u32 RXCRCR;
	volatile u32 TXCRCR;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR;

}SPI_t;



#define  SPI_1         		          ((volatile SPI_t*)0x40013000)
#define  SPI_2         		          ((volatile SPI_t*)0x40013400)
#define  SPI_3         		          ((volatile SPI_t*)0x40003C00)
#define  SPI_4         		          ((volatile SPI_t*)0x40003800)





#endif