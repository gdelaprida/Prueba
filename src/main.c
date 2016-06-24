/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "stm32f4_discovery.h"

#define BIT26 0x4000000;  //Naranja(13)
#define BIT24 0x1000000;  //Verde (12)
#define BIT28 0x10000000; //Rojo (14)
#define BIT30 0x40000000; //Azul (15)

#define BIT13 0x2000;
#define BIT14 0x4000;
#define BIT12 0x1000;
#define BIT15 0x8000;

void main(void) {
	//Configuracion

	//Habilito el clk del bus GPIOD
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= BIT26;
	GPIOD->MODER |= BIT24;
	GPIOD->MODER |= BIT28;
	GPIOD->MODER |= BIT30;

	while(1) {
	//Aplicacion
	delay (5000);
	GPIOD->ODR ^= BIT13;
	delay (5000);
	GPIOD->ODR ^= BIT13;
	GPIOD->ODR ^= BIT14;
	delay (5000);
	GPIOD->ODR ^= BIT14;
	GPIOD->ODR ^= BIT15;
	delay (5000);
	GPIOD->ODR ^= BIT15;
	GPIOD->ODR ^= BIT12;
	delay (5000);
	GPIOD->ODR ^= BIT12;
	GPIOD->ODR ^= BIT13;
	}
}

void delay (uint16_t delay){
	uint8_t i;
	while (delay --> 0){
		for (i = 100; i>0; i--)
			asm ("nop");
	}
}
