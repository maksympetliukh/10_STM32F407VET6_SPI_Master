/*
 * stm32f407xx.h
 *
 *  Created on: Feb 22, 2026
 *      Author: maksym
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STM32F407XX_H_
#define STM32F407XX_H_

/*
 * Base addresses of FLASH and SRAM memories
 */
#define FLASH_BASE 0x08000000UL /*512 KB read-only memory*/
#define SRAM1_BASE 0x20000000UL /*112 KB SRAM1*/
#define SRAM2_BASE 0x2001C000UL /*16  KB SRAM2*/
#define ROM_BASE   FLASH_BASE   /*Alias*/
#define SRAM_BASE  SRAM1_BASE   /*General SRAM*/

/*
 * ARM Cortex-M4 processor NVIC ISERx register addresses
 */
#define NVIC_ISER0 ((volatile uint32_t*)0xE000E100)
#define NVIC_ISER1 ((volatile uint32_t*)0xE000E104)
#define NVIC_ISER2 ((volatile uint32_t*)0xE000E108)
#define NVIC_ISER3 ((volatile uint32_t*)0xE000E10C)   /*Interrupt Set Enable Registers 0-7*/
#define NVIC_ISER4 ((volatile uint32_t*)0xE000E110)
#define NVIC_ISER5 ((volatile uint32_t*)0xE000E114)
#define NVIC_ISER6 ((volatile uint32_t*)0xE000E118)
#define NVIC_ISER7 ((volatile uint32_t*)0xE000E11C)

/*
 * ARM Cortex-M4 processor NVIC ICERx register addresses
 */
#define NVIC_ICER0 ((volatile uint32_t*)0xE000E180)
#define NVIC_ICER1 ((volatile uint32_t*)0xE000E184)
#define NVIC_ICER2 ((volatile uint32_t*)0xE000E188)
#define NVIC_ICER3 ((volatile uint32_t*)0xE000E18C)   /*Interrupt Clear Enable Registers 0-7*/
#define NVIC_ICER4 ((volatile uint32_t*)0xE000E190)
#define NVIC_ICER5 ((volatile uint32_t*)0xE000E194)
#define NVIC_ICER6 ((volatile uint32_t*)0xE000E198)
#define NVIC_ICER7 ((volatile uint32_t*)0xE000E19C)

/*
 * ARM Cortex-M4 processor NVIC ISPR register addresses
 */
#define NVIC_ISPR0 ((volatile uint32_t*)0xE000E200)
#define NVIC_ISPR1 ((volatile uint32_t*)0xE000E204)
#define NVIC_ISPR2 ((volatile uint32_t*)0xE000E208)
#define NVIC_ISPR3 ((volatile uint32_t*)0xE000E20C)  /*Interrupt set pending registers*/
#define NVIC_ISPR4 ((volatile uint32_t*)0xE000E210)
#define NVIC_ISPR5 ((volatile uint32_t*)0xE000E214)
#define NVIC_ISPR6 ((volatile uint32_t*)0xE000E218)
#define NVIC_ISPR7 ((volatile uint32_t*)0xE000E21C)

/*
 * ARM Cortex-M4 processor NVIC ICPR register addresses
 */
#define NVIC_ICPR0 ((volatile uint32_t*)0xE000E280)
#define NVIC_ICPR1 ((volatile uint32_t*)0xE000E284)
#define NVIC_ICPR2 ((volatile uint32_t*)0xE000E288)
#define NVIC_ICPR3 ((volatile uint32_t*)0xE000E28C)  /*Interrupt clear pending registers 0-7*/
#define NVIC_ICPR4 ((volatile uint32_t*)0xE000E290)
#define NVIC_ICPR5 ((volatile uint32_t*)0xE000E294)
#define NVIC_ICPR6 ((volatile uint32_t*)0xE000E298)
#define NVIC_ICPR7 ((volatile uint32_t*)0xE000E29C)

/*
 * ARM Cortex-M4 processor NVIC IABR register addresses
 */
#define NVIC_IABR0 ((volatile uint32_t*)0xE000E300
#define NVIC_IABR1 ((volatile uint32_t*)0xE000E304)
#define NVIC_IABR2 ((volatile uint32_t*)0xE000E308)
#define NVIC_IABR3 ((volatile uint32_t*)0xE000E30C)    /*Interrupt Active Bit registers 0-7*/
#define NVIC_IABR4 ((volatile uint32_t*)0xE000E310)
#define NVIC_IABR5 ((volatile uint32_t*)0xE000E314)
#define NVIC_IABR6 ((volatile uint32_t*)0xE000E318)
#define NVIC_IABR7 ((volatile uint32_t*)0xE000E31C)

/*
 * ARM Cortex-M4 processor NVIC IPR register addresses
 */
#define NVIC_IPR0   ((volatile uint32_t*)0xE000E400) /*Interrupt Priority Registers 0-58*/
#define NVIC_IPR1   ((volatile uint32_t*)0xE000E404)
#define NVIC_IPR2   ((volatile uint32_t*)0xE000E408)
#define NVIC_IPR3   ((volatile uint32_t*)0xE000E40C)
#define NVIC_IPR4   ((volatile uint32_t*)0xE000E410)
#define NVIC_IPR5   ((volatile uint32_t*)0xE000E414)
#define NVIC_IPR6   ((volatile uint32_t*)0xE000E418)
#define NVIC_IPR7   ((volatile uint32_t*)0xE000E41C)
#define NVIC_IPR8   ((volatile uint32_t*)0xE000E420)
#define NVIC_IPR9   ((volatile uint32_t*)0xE000E424)
#define NVIC_IPR10  ((volatile uint32_t*)0xE000E428)
#define NVIC_IPR11  ((volatile uint32_t*)0xE000E42C)
#define NVIC_IPR12  ((volatile uint32_t*)0xE000E430)
#define NVIC_IPR13  ((volatile uint32_t*)0xE000E434)
#define NVIC_IPR14  ((volatile uint32_t*)0xE000E438)
#define NVIC_IPR15  ((volatile uint32_t*)0xE000E43C)
#define NVIC_IPR16  ((volatile uint32_t*)0xE000E440)
#define NVIC_IPR17  ((volatile uint32_t*)0xE000E444)
#define NVIC_IPR18  ((volatile uint32_t*)0xE000E448)
#define NVIC_IPR19  ((volatile uint32_t*)0xE000E44C)
#define NVIC_IPR20  ((volatile uint32_t*)0xE000E450)
#define NVIC_IPR21  ((volatile uint32_t*)0xE000E454)
#define NVIC_IPR22  ((volatile uint32_t*)0xE000E458)
#define NVIC_IPR23  ((volatile uint32_t*)0xE000E45C)
#define NVIC_IPR24  ((volatile uint32_t*)0xE000E460)
#define NVIC_IPR25  ((volatile uint32_t*)0xE000E464)
#define NVIC_IPR26  ((volatile uint32_t*)0xE000E468)
#define NVIC_IPR27  ((volatile uint32_t*)0xE000E46C)
#define NVIC_IPR28  ((volatile uint32_t*)0xE000E470)
#define NVIC_IPR29  ((volatile uint32_t*)0xE000E474)
#define NVIC_IPR30  ((volatile uint32_t*)0xE000E478)
#define NVIC_IPR31  ((volatile uint32_t*)0xE000E47C)
#define NVIC_IPR32  ((volatile uint32_t*)0xE000E480)
#define NVIC_IPR33  ((volatile uint32_t*)0xE000E484)
#define NVIC_IPR34  ((volatile uint32_t*)0xE000E488)
#define NVIC_IPR35  ((volatile uint32_t*)0xE000E48C)
#define NVIC_IPR36  ((volatile uint32_t*)0xE000E490)
#define NVIC_IPR37  ((volatile uint32_t*)0xE000E494)
#define NVIC_IPR38  ((volatile uint32_t*)0xE000E498)
#define NVIC_IPR39  ((volatile uint32_t*)0xE000E49C)
#define NVIC_IPR40  ((volatile uint32_t*)0xE000E4A0)
#define NVIC_IPR41  ((volatile uint32_t*)0xE000E4A4)
#define NVIC_IPR42  ((volatile uint32_t*)0xE000E4A8)
#define NVIC_IPR43  ((volatile uint32_t*)0xE000E4AC)
#define NVIC_IPR44  ((volatile uint32_t*)0xE000E4B0)
#define NVIC_IPR45  ((volatile uint32_t*)0xE000E4B4)
#define NVIC_IPR46  ((volatile uint32_t*)0xE000E4B8)
#define NVIC_IPR47  ((volatile uint32_t*)0xE000E4BC)
#define NVIC_IPR48  ((volatile uint32_t*)0xE000E4C0)
#define NVIC_IPR49  ((volatile uint32_t*)0xE000E4C4)
#define NVIC_IPR50  ((volatile uint32_t*)0xE000E4C8)
#define NVIC_IPR51  ((volatile uint32_t*)0xE000E4CC)
#define NVIC_IPR52  ((volatile uint32_t*)0xE000E4D0)
#define NVIC_IPR53  ((volatile uint32_t*)0xE000E4D4)
#define NVIC_IPR54  ((volatile uint32_t*)0xE000E4D8)
#define NVIC_IPR55  ((volatile uint32_t*)0xE000E4DC)
#define NVIC_IPR56  ((volatile uint32_t*)0xE000E4E0)
#define NVIC_IPR57  ((volatile uint32_t*)0xE000E4E4)
#define NVIC_IPR58  ((volatile uint32_t*)0xE000E4E8)
#define NVIC_IPR59  ((volatile uint32_t*)0xE000E4EC)

/*
 * ARM Cortex-M4 processor STIR register address
 */
#define NVIC_STIR   ((volatile uint32_t*)0xE000EF00) /*Software Trigger Interrupt Register*/

/*
 * ARM Cortex-M4 number of implemented priority bits
 */
#define PRIOR_BITS_IMPLEMENTED 4
/*
 * AHBx and APBx bus peripheral base addresses
 */
#define PERIPH_BASE     0x40000000UL
#define APB1PERIPH_BASE PERIPH_BASE  /*APB1*/
#define APB2PERIPH_BASE 0x40010000UL /*APB2*/
#define AHB1PERIPH_BASE 0x40020000UL /*AHB1*/
#define AHB2PERIPH_BASE 0x50000000UL /*AHB2*/
#define RCC_BASE        0x40023800UL /*RCC*/

/*
 * AHB1 peripherals
 */
#define GPIOA_BASE 0x40020000UL /*GPIOA port base address*/
#define GPIOB_BASE 0x40020400UL /*GPIOB port base address*/
#define GPIOC_BASE 0x40020800UL /*GPIOC port base address*/
#define GPIOD_BASE 0x40020C00UL /*GPIOD port base address*/
#define GPIOE_BASE 0x40021000UL /*GPIOE port base address*/
#define GPIOF_BASE 0x40021400UL /*GPIOF port base address*/
#define GPIOG_BASE 0x40021800UL /*GPIOG port base address*/
#define GPIOH_BASE 0x40021C00UL /*GPIOH port base address*/
#define GPIOI_BASE 0x40022000UL /*GPIOI port base address*/

/*
 * APB1 peripherals
 */
#define I2C1_BASE   0x40005400UL /*I2C1*/
#define I2C2_BASE   0x40005800UL /*I2C2*/
#define I2C3_BASE   0x40005C00UL /*I2C3*/
#define SPI2_BASE   0x40003800UL /*SPI2/I2S2*/
#define SPI3_BASE   0x40003C00UL /*SPI3/I2S3*/
#define SPI4_BASE   0x40013400UL /*SPI4*/
#define USART2_BASE 0x40004400UL /*USART2*/
#define USART3_BASE 0x40004800UL /*USART3*/
#define UART4_BASE  0x40004C00UL /*UART4*/
#define UART5_BASE  0x40005000UL /*UART5*/

/*
 * APB2 peripherals
 */
#define SPI1_BASE    0x40013000UL /*SPI1*/
#define USART1_BASE  0x40011000UL /*USART1*/
#define USART6_BASE  0x40011400UL /*USART6*/
#define EXTI_BASE    0x40013C00UL /*EXTI*/
#define SYSCFG_BASE 0x40013800UL  /*SYSCFG*/

/*
 * Peripheral register structure for GPIO
 */
typedef struct{
	uint32_t volatile MODER;   /*GPIO port mode register                        offset: 0x00*/
	uint32_t volatile OTYPER;  /*GPIO port output type register                 offset: 0x04*/
	uint32_t volatile OSPEEDR; /*GPIO port output speed register                offset: 0x08*/
	uint32_t volatile PUPDR;   /*GPIO port pull-up/pull-down register           offset: 0x0C*/
	uint32_t volatile IDR;     /*GPIO port input data register                  offset: 0x10*/
	uint32_t volatile ODR;     /*GPIO port output data register         		offset: 0x14*/
	uint32_t volatile BSRR;    /*GPIO port bit set/reset register               offset: 0x18*/
	uint32_t volatile LCKR;    /*GPIO port configuration lock register          offset: 0x1C*/
	uint32_t volatile AFRL;    /*GPIO port alternative function low register    offset: 0x20*/
	uint32_t volatile AFRH;    /*GPIO port alternative function high register   offset: 0x24*/
}GPIO_REG_t;

/*
 * Peripheral definitions for GPIO
 */
#define GPIOA ((GPIO_REG_t*)GPIOA_BASE)
#define GPIOB ((GPIO_REG_t*)GPIOB_BASE)
#define GPIOC ((GPIO_REG_t*)GPIOC_BASE)
#define GPIOD ((GPIO_REG_t*)GPIOD_BASE)
#define GPIOE ((GPIO_REG_t*)GPIOE_BASE)
#define GPIOF ((GPIO_REG_t*)GPIOF_BASE)
#define GPIOG ((GPIO_REG_t*)GPIOG_BASE)
#define GPIOH ((GPIO_REG_t*)GPIOH_BASE)
#define GPIOI ((GPIO_REG_t*)GPIOI_BASE)

/*
 * RCC register structure
 */
typedef struct{
	uint32_t volatile CR;            /*Clock control register                                     offset:0x00*/
	uint32_t volatile PLLCFGR;       /*PLL configuration register                                 offset:0x04*/
	uint32_t volatile CFGR;          /*Clock configuration register                               offset:0x08*/
	uint32_t volatile CIR;           /*Clock interrupt register                                   offset:0x0C*/
	uint32_t volatile AHB1RSTR;      /*AHB1 peripheral register                                   offset:0x10*/
	uint32_t volatile AHB2RSTR;      /*AHB2 peripheral register                                   offset:0x14*/
	uint32_t volatile AHB3RSTR;      /*AHB3 peripheral register                                   offset:0x18*/
	uint32_t RESERVED0;              /*Reserved register                                          offset:0x1C*/
	uint32_t volatile APB1RSTR;      /*APB1 peripheral register                                   offset:0x20*/
	uint32_t volatile APB2RSTR;      /*APB2 peripheral register                                   offset:0x24*/
	uint32_t RESERVED1;              /*Reserved register                                          offset:0x28*/
	uint32_t RESERVED2;              /*Reserved register                                          offset:0x2C*/
	uint32_t volatile AHB1ENR;       /*AHB1 peripheral clock enable register                      offset:0x30*/
	uint32_t volatile AHB2ENR;       /*AHB2 peripheral clock enable register                      offset:0x34*/
	uint32_t volatile AHB3ENR;       /*AHB3 peripheral clock enable register                      offset:0x38*/
	uint32_t RESERVED3;              /*Reserved register                                          offset:0x3C*/
	uint32_t volatile APB1ENR;       /*APB1 peripheral clock enable register                      offset:0x40*/
	uint32_t volatile APB2ENR;       /*APB2 peripheral clock enable register                      offset:0x44*/
	uint32_t RESERVED4;              /*Reserved register                                          offset:0x48*/
	uint32_t RESERVED5;              /*Reserved Register                                          offset:0x4C*/
	uint32_t volatile AHB1LPENR;     /*AHB1 peripheral clock enable in low-power mode register    offset:0x50*/
	uint32_t volatile AHB2LPENR;     /*AHB2 peripheral clock enable in low-power mode register    offset:0x54*/
	uint32_t volatile AHB3LPENR;     /*AHB3 peripheral clock enable in low-power mode register    offset:0x58*/
	uint32_t RESERVED6;              /*Reserved register                                          offset:0x5C*/
	uint32_t volatile APB1LPENR;     /*APB1 peripheral clock enable in low-power mode register    offset:0x60*/
	uint32_t volatile APB2LPENR;     /*APB2 peripheral clock enable in low-power mode register    offset:0x64*/
	uint32_t RESERVED7;              /*Reserved register                                          offset:0x68*/
	uint32_t RESERVED8;              /*Reserved register                                          offset:0x6C*/
	uint32_t volatile BDCR;          /*Backup domain register                                     offset:0x70*/
	uint32_t volatile CSR;           /*Clock control & status register                            offset:0x74*/
	uint32_t RESERVED9;              /*Reserved register                                          offset:0x78*/
	uint32_t RESERVED10;             /*Reserved register                                          offset:0x7C*/
	uint32_t volatile SSCGR;         /*Spread spectrum clock generation register                  offset:0x80*/
	uint32_t volatile PLLI2SCFGR;    /*PLLI2S configuration register                              offset:0x84*/
}RCC_REG_t;

/*
 * Peripheral definitions for RCC
 */
#define RCC ((RCC_REG_t*)RCC_BASE)

/*
 * Macros to reset GPIOx peripherals
 */
#define GPIOA_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 0)); (RCC->AHB1RSTR &= ~(1 << 0));}while(0)
#define GPIOB_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 1)); (RCC->AHB1RSTR &= ~(1 << 1));}while(0)
#define GPIOC_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 2)); (RCC->AHB1RSTR &= ~(1 << 2));}while(0)
#define GPIOD_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 3)); (RCC->AHB1RSTR &= ~(1 << 3));}while(0)
#define GPIOE_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 4)); (RCC->AHB1RSTR &= ~(1 << 4));}while(0)
#define GPIOF_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 5)); (RCC->AHB1RSTR &= ~(1 << 5));}while(0)
#define GPIOG_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 6)); (RCC->AHB1RSTR &= ~(1 << 6));}while(0)
#define GPIOH_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 7)); (RCC->AHB1RSTR &= ~(1 << 7));}while(0)
#define GPIOI_REG_RESET() do{(RCC->AHB1RSTR |= (1 << 8)); (RCC->AHB1RSTR &= ~(1 << 8));}while(0)

/*
 * This macro returns GPIO port code for given GPIO pin address
 */
#define GPIO_BASE_TO_CODE(x) ((x) == GPIOA) ? 0 :\
		                     ((x) == GPIOB) ? 1 :\
		                     ((x) == GPIOC) ? 2 :\
		                     ((x) == GPIOD) ? 3 :\
		                     ((x) == GPIOE) ? 4 :\
		                     ((x) == GPIOF) ? 5 :\
		                     ((x) == GPIOG) ? 6 :\
		                     ((x) == GPIOH) ? 7 :\
		                     ((x) == GPIOI) ? 8 :\
		                     0 \

/*
 * Clock enable macro for GPIOx peripherals
 */
#define RCC_GPIOA_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 0))
#define RCC_GPIOB_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 1))
#define RCC_GPIOC_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 2))
#define RCC_GPIOD_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 3))
#define RCC_GPIOE_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 4))
#define RCC_GPIOF_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 5))
#define RCC_GPIOG_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 6))
#define RCC_GPIOH_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 7))
#define RCC_GPIOI_CLK_ENABLE()   ((RCC->AHB1ENR) |= (1 << 8))

/*
 * Clock disable macro for GPIOx peripherals
 */
#define RCC_GPIOA_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 0))
#define RCC_GPIOB_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 1))
#define RCC_GPIOC_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 2))
#define RCC_GPIOD_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 3))
#define RCC_GPIOE_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 4))
#define RCC_GPIOF_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 5))
#define RCC_GPIOG_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 6))
#define RCC_GPIOH_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 7))
#define RCC_GPIOI_CLK_DISABLE()   ((RCC->AHB1ENR) &= ~(1 << 8))

/*
 * Clock enable macro for I2Cx peripherals
 */
#define RCC_I2C1_CLK_ENABLE()    ((RCC->APB1ENR) |= (1 << 21))
#define RCC_I2C2_CLK_ENABLE()    ((RCC->APB1ENR) |= (1 << 22))
#define RCC_I2C3_CLK_ENABLE()    ((RCC->APB1ENR) |= (1 << 23))

/*
 *Clock disable macro for I2Cx peripherals
 */
#define RCC_I2C1_CLK_DISABLE()    ((RCC->APB1ENR) &= ~(1 << 21))
#define RCC_I2C2_CLK_DISABLE()    ((RCC->APB1ENR) &= ~(1 << 22))
#define RCC_I2C3_CLK_DISABLE()    ((RCC->APB1ENR) &= ~(1 << 23))

/*
 * Clock enable macro for SPIx peripherals
 */
#define RCC_SPI1_CLK_ENABLE()      ((RCC->APB2ENR) |= (1 << 12))
#define RCC_SPI2_CLK_ENABLE()      ((RCC->APB1ENR) |= (1 << 14))
#define RCC_SPI3_CLK_ENABLE()      ((RCC->APB1ENR) |= (1 << 15))
#define RCC_SPI4_CLK_ENABLE()      ((RCC->APB2ENR) |= (1 << 13))

/*
 * Clock disable macro for SPIx peripherals
 */
#define RCC_SPI1_CLK_DISABLE()      ((RCC->APB2ENR) &= ~(1 << 12))
#define RCC_SPI2_CLK_DISABLE()      ((RCC->APB1ENR) &= ~(1 << 14))
#define RCC_SPI3_CLK_DISABLE()      ((RCC->APB1ENR) &= ~(1 << 15))
#define RCC_SPI4_CLK_DISABLE()      ((RCC->APB2ENR) &= ~(1 << 13))

/*
 * Clock enable macro for UART/USARTx peripherals
 */
#define RCC_USART1_CLK_ENABLE()  ((RCC->APB2ENR) |= (1 << 4))
#define RCC_USART2_CLK_ENABLE()  ((RCC->APB1ENR) |= (1 << 17))
#define RCC_USART3_CLK_ENABLE()  ((RCC->APB1ENR) |= (1 << 18))
#define RCC_UART4_CLK_ENABLE()   ((RCC->APB1ENR) |= (1 << 19))
#define RCC_UART5_CLK_ENABLE()   ((RCC->APB1ENR) |= (1 << 20))
#define RCC_USART6_CLK_ENABLE()  ((RCC->APB2ENR) |= (1 << 5))

/*
 * Clock disable macro for UART/USARTx peripherals
 */
#define RCC_USART1_CLK_DISABLE()  ((RCC->APB2ENR) &= ~(1 << 4))
#define RCC_USART2_CLK_DISABLE()  ((RCC->APB1ENR) &= ~(1 << 17))
#define RCC_USART3_CLK_DISABLE()  ((RCC->APB1ENR) &= ~(1 << 18))
#define RCC_UART4_CLK_DISABLE()   ((RCC->APB1ENR) &= ~(1 << 19))
#define RCC_UART5_CLK_DISABLE()   ((RCC->APB1ENR) &= ~(1 << 20))
#define RCC_USART6_CLK_DISABLE()  ((RCC->APB2ENR) &= ~(1 << 5))

/*
 * Clock enable macro for SYSCFG peripheral
 */
#define RCC_SYSCFG_CLK_ENABLE()  ((RCC->APB2ENR) |= (1 << 14))

/*
 * Clock disable macro for SYSCFG peripheral
 */
#define RCC_SYSCFG_CLK_DISABLE()  ((RCC->APB2ENR) &= ~(1 << 14))

/*
 * SYSCFG peripheral register structure
 */
typedef struct{
	uint32_t volatile MEMRMP;  /*Memory remap register                           offset: 0x00*/
	uint32_t volatile PMC;     /*Peripheral mode configuration register          offset: 0x04*/
	uint32_t volatile EXTICR[4]; /*External interrupt configuration register 1     offset: 0x08-0x14*/
	uint32_t RESERVED1;        /*Reserved register                               offset: 0x18*/
	uint32_t RESERVED2;        /*Reserved register                               offset: 0x1C*/
	uint32_t volatile CMPCR;   /*Compensation cell control register              offset: 0x20*/
	uint32_t RESERVED3;        /*Reserved register                               offset: 0x24*/
	uint32_t RESERVED4;        /*Reserved register                               offset: 0x28*/
	uint32_t volatile CFGR;    /*Configuration register                          offset: 0x2C*/
}SYSCFG_REG_t;

#define SYSCFG  ((SYSCFG_REG_t*)SYSCFG_BASE)

/*
 * EXTI peripheral registers structure
 */
typedef struct{
	uint32_t volatile IMR;   /*Interrupt mask register                    offset: 0x00*/
	uint32_t volatile EMR;   /*Event mask register                        offset: 0x04*/
	uint32_t volatile RTSR;  /*Rising trigger selection register          offset: 0x08*/
	uint32_t volatile FTSR;  /*Falling trigger selection register         offset: 0x0C*/
	uint32_t volatile SWIER; /*Software interrupt event register          offset: 0x10*/
	uint32_t volatile PR;    /*Pending register                           offset: 0x14*/
}EXTI_REG_t;

#define EXTI ((EXTI_REG_t*)EXTI_BASE)

/*
 * Interrupt Request (IRQ) numbers of STM32F407xx MCU
 */
#define IRQ_EXTI0       6
#define IRQ_EXTI1       7
#define IRQ_EXTI2       8
#define IRQ_EXTI3       9
#define IRQ_EXTI4       10
#define IRQ_EXTI5_9     23
#define IRQ_EXTI10_15   40

/*
 * ARM Cortex-M4 CPU Priority Register base address
 */
#define NVIC_IRQ_PRIOR_BASE ((volatile uint32_t*)0xE000E400)

/*
 * SPI peripheral register structure
 */
typedef struct{
	uint32_t volatile CR1;          /*SPI Control Register 1                   offset: 0x00*/
	uint32_t volatile CR2;          /*SPI Control Register 2                   offset: 0x04*/
	uint32_t volatile SR;           /*SPI Status Register                      offset: 0x08*/
	uint32_t volatile DR;           /*SPI Data Register                        offset: 0x0C*/
	uint32_t volatile CRCPR;        /*CPI CRC polynomial Register              offset: 0x10*/
	uint32_t volatile RXCRCR;       /*SPI RX CRC Register                      offset: 0x14*/
	uint32_t volatile TXCRCR;       /*SPI TX CRC Register                      offset: 0x18*/
	uint32_t volatile I2SCFGR;      /*SPI I2C Configuration Register           offset: 0x1C*/
	uint32_t volatile I2SPR;        /*SPI I2S Prescaler Register               offset: 0x20*/
}SPI_REG_t;

/*
 * SPI Peripheral Definitions
 */
#define SPI1 ((SPI_REG_t*)SPI1_BASE)
#define SPI2 ((SPI_REG_t*)SPI2_BASE)
#define SPI3 ((SPI_REG_t*)SPI3_BASE)
#define SPI4 ((SPI_REG_t*)SPI4_BASE)

/*
 * Macros to reset SPIx peripherals
 */
#define SPI1_REG_RESET() do{(RCC->APB2RSTR |= (1 << 12)); (RCC->APB2RSTR &= ~(1 << 12));}while(0)
#define SPI2_REG_RESET() do{(RCC->APB1RSTR |= (1 << 14)); (RCC->APB2RSTR &= ~(1 << 14));}while(0)
#define SPI3_REG_RESET() do{(RCC->APB1RSTR |= (1 << 15)); (RCC->APB2RSTR &= ~(1 << 15));}while(0)
#define SPI4_REG_RESET() do{(RCC->APB2RSTR |= (1 << 13)); (RCC->APB2RSTR &= ~(1 << 13));}while(0)

/*
 * SPI CR1 peripheral bit position definition macros
 */
#define SPI_CR1_CPHA      0
#define SPI_CR1_CPOL      1
#define SPI_CR1_MSTR      2
#define SPI_CR1_BR        3
#define SPI_CR1_SPE       6
#define SPI_CR1_LSBF      7
#define SPI_CR1_SSI       8
#define SPI_CR1_SSM       9
#define SPI_CR1_RXONLY    10
#define SPI_CR1_DFF       11
#define SPI_CR1_CRCNEXT   12
#define SPI_CR1_CRCEN     13
#define SPI_CR1_BIDIOE    14
#define SPI_CR1_BIDIMODE  15

/*
 * SPI CR2 peripheral bit position definition macros
 */
#define SPI_CR2_RXDMAEN    0
#define SPI_CR2_TXDMAEN    1
#define SPI_CR2_SSOE       2
#define SPI_CR2_RESERVED   3
#define SPI_CR2_FRF        4
#define SPI_CR2_ERRIE      5
#define SPI_CR2_RXNEIE     6
#define SPI_CR2_TXEIE      7


/*
 * SPI SR peripheral bit position definition macros
 */
#define SPI_SR_RXNE      0
#define SPI_SR_TXE       1
#define SPI_SR_CHSIDE    2
#define SPI_SR_UDR       3
#define SPI_SR_CRCERR    4
#define SPI_SR_MODF      5
#define SPI_SR_OVR       6
#define SPI_SR_BSY       7
#define SPI_SR_FRE       8

/*
 * Generic macros
 */
#define HIGH            1
#define LOW             0
#define ENABLE          1
#define DISABLE         0
#define SET             1
#define RESET           0
#define PRESSED         0
#define RELEASED        1
#define FLAG_RESET      RESET
#define FLAG_SET        SET


#endif /* STM32F407XX_H_ */
