/*
 * 03_From_Master_to_Slave_Transmission.c
 *
 *  Created on: Feb 22, 2026
 *      Author: maksym
 */

#include "stm32f407xx.h"
#include "spi.h"
#include "gpio.h"

uint8_t tx = 0x01;
uint8_t rx = 0;
uint8_t dummy = 0xFF;

void Delay(void){
	for(volatile uint32_t i = 0; i < 100000; i++);
}

void SPI2_GPIO_Init(void){
	GPIO_Handle_t spi2_gpio;

	spi2_gpio.pGPIOx = GPIOB;

	GPIO_ClockControl(GPIOB, ENABLE);

	spi2_gpio.GPIOx_CFG.pin_mode = GPIO_MODE_ALT_FN;
	spi2_gpio.GPIOx_CFG.pin_alt_func_mode = 5;
	spi2_gpio.GPIOx_CFG.pin_op_type = GPIO_OUT_PP;
	spi2_gpio.GPIOx_CFG.pin_pu_pd_ctrl = GPIO_NO_PUPD;
	spi2_gpio.GPIOx_CFG.pin_speed = GPIO_OSPEED_HIGH;

	//SCLK
	spi2_gpio.GPIOx_CFG.pin_number = GPIO_PIN_13;
	GPIO_Init(&spi2_gpio);

	//MOSI
	spi2_gpio.GPIOx_CFG.pin_number = GPIO_PIN_15;
	GPIO_Init(&spi2_gpio);

	//MISO
	spi2_gpio.GPIOx_CFG.pin_number = GPIO_PIN_14;
	GPIO_Init(&spi2_gpio);

	//NSS
	spi2_gpio.GPIOx_CFG.pin_mode = GPIO_MODE_OUT;
	spi2_gpio.GPIOx_CFG.pin_number = GPIO_PIN_12;
	GPIO_Init(&spi2_gpio);
}

void SPI2_Init(void){
	SPI_Handle_t spi2;

	spi2.pSPIx = SPI2;
	SPI_ClockControl(SPI2, ENABLE);

	spi2.SPI_Configs.spi_bus_config = SPI_BUS_CFG_FD;
	spi2.SPI_Configs.spi_device_mode = SPI_DEVICE_MODE_MASTER;
	spi2.SPI_Configs.spi_clock_speed = SPI_SCLK_SPEED_DIV8;
	spi2.SPI_Configs.spi_dff = SPI_DFF_8B;
	spi2.SPI_Configs.spi_cpol = SPI_CPOL_LOW;
	spi2.SPI_Configs.spi_cpha = SPI_CPHA_LOW;
	spi2.SPI_Configs.spi_ssm = SPI_SSM_EN;
	spi2.SPI_Configs.spi_ssi = SPI_SSI_EN;

	SPI_Init(&spi2);
}

void Button_Init(void){
	GPIO_Handle_t btn;

	btn.pGPIOx = GPIOE;
	GPIO_ClockControl(GPIOE, ENABLE);

	btn.GPIOx_CFG.pin_number = GPIO_PIN_3;
	btn.GPIOx_CFG.pin_mode = GPIO_MODE_IN;
	btn.GPIOx_CFG.pin_speed = GPIO_OSPEED_HIGH;
	btn.GPIOx_CFG.pin_pu_pd_ctrl = GPIO_PIN_PU;

	GPIO_Init(&btn);
}

void LED_Init(void){
	GPIO_Handle_t led;

	led.pGPIOx = GPIOA;
	GPIO_ClockControl(GPIOA, ENABLE);

	led.GPIOx_CFG.pin_number = GPIO_PIN_7;
	led.GPIOx_CFG.pin_mode = GPIO_MODE_OUT;
	led.GPIOx_CFG.pin_op_type = GPIO_OUT_PP;
	led.GPIOx_CFG.pin_pu_pd_ctrl = GPIO_NO_PUPD;
	led.GPIOx_CFG.pin_speed = GPIO_OSPEED_HIGH;

	GPIO_Init(&led);
	GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
}

int main(void){
	SPI2_GPIO_Init();
	SPI2_Init();
	Button_Init();
	LED_Init();

	while(1){
		while(GPIO_ReadPin(GPIOE, GPIO_PIN_3) == 1);
		Delay();

		while(GPIO_ReadPin(GPIOE, GPIO_PIN_3) == 0);
		Delay();

		SPI_PeripheralControl(SPI2, ENABLE);

		GPIO_WritePin(GPIOB, GPIO_PIN_12, RESET);

		while(SPI_GetFlagStatus(SPI2, SPI_TXE_FLAG) == RESET);

		SPI_Data_Transmit(SPI2, &tx, 1);

		SPI_Data_Receive(SPI2, &rx, 1);

		SPI_Data_Transmit(SPI2,&dummy, 1);

		SPI_Data_Receive(SPI2, &rx, 1);

		while(SPI_GetFlagStatus(SPI2, SPI_BUSY_FLAG) == SET);

		GPIO_WritePin(GPIOB, GPIO_PIN_12, SET);

		SPI_PeripheralControl(SPI2, DISABLE);

		if(rx == 0x10){
			Delay();
			Delay();
			Delay();
			GPIO_WritePin(GPIOA, GPIO_PIN_7, 0);
			Delay();
			GPIO_WritePin(GPIOA, GPIO_PIN_7, 1);
		}
	}
}
