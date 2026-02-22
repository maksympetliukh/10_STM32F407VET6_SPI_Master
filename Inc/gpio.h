/*
 * gpio.h
 *
 *  Created on: Feb 22, 2026
 *      Author: maksym
 */

#include "stm32f407xx.h"

#ifndef GPIO_H_
#define GPIO_H_

/*
 * GPIO pin configuration structure
 */
typedef struct {
	uint8_t pin_number;         /*!<Possible values from @GPIO_PIN_NUMBER>*/
	uint8_t pin_mode;           /*!<Possible values from @GPIO_PIN_MODES>*/
	uint8_t pin_speed;          /*!<Possible values from @GPIO_PIN_OSPEED>*/
	uint8_t pin_pu_pd_ctrl;     /*!<Possible values from @GPIO_PIN_PUPD>*/
	uint8_t pin_op_type;        /*!<Possible values from @GPIO_PIN_OPTYPE>*/
	uint8_t pin_alt_func_mode;  /*!<Possible values from @GPIO_PIN_AF>*/
}GPIO_PinConfig_t;

/*
 * GPIO handle structure
 */
typedef struct {
	GPIO_REG_t *pGPIOx; //This pointer holds the base address of the GPIO port to which the pin belongs
	GPIO_PinConfig_t GPIOx_CFG; //This structure includes GPIO pin configuration settings

}GPIO_Handle_t;

/*
 * GPIO APIs
 */
void GPIO_Init(GPIO_Handle_t *pGPIO_Handle);
void GPIO_DeInit(GPIO_REG_t *pGPIOx);
void GPIO_ClockControl(GPIO_REG_t *pGPIOx, uint8_t EnDiMode);
uint8_t GPIO_ReadPin(GPIO_REG_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadPort(GPIO_REG_t *pGPIOx);
void GPIO_WritePin(GPIO_REG_t *pGPIOx, uint8_t PinNumber, uint8_t value);
void GPIO_WritePort(GPIO_REG_t *pGPIOx, uint16_t value);
void GPIO_TogglePin(GPIO_REG_t *pGPIOx, uint8_t PinNumber);
void GPIO_IRQ_Interrupt_CFG(uint8_t IRQ_Number, uint8_t EnDiMode);
void GPIO_IRQ_Priority_CFG(uint8_t IRQ_Number, uint8_t IRQ_Priority);
void GPIO_IRQ_Handler(uint8_t PinNumber);

/*
 * @GPIO_PIN_NUMBER
 * GPIO pin possible numbers
 */
#define GPIO_PIN_0   0
#define GPIO_PIN_1   1
#define GPIO_PIN_2   2
#define GPIO_PIN_3   3
#define GPIO_PIN_4   4
#define GPIO_PIN_5   5
#define GPIO_PIN_6   6
#define GPIO_PIN_7   7
#define GPIO_PIN_8   8
#define GPIO_PIN_9   9
#define GPIO_PIN_10  10
#define GPIO_PIN_11  11
#define GPIO_PIN_12  12
#define GPIO_PIN_13  13
#define GPIO_PIN_14  14
#define GPIO_PIN_15  15
/*
 * @GPIO_PIN_MODES
 * GPIO modes
 */
#define GPIO_MODE_IN     0
#define GPIO_MODE_OUT    1
#define GPIO_MODE_ALT_FN 2
#define GPIO_MODE_ANALOG 3
#define GPIO_MODE_IT_FT  4
#define GPIO_MODE_IT_RT  5
#define GPIO_MODE_IT_RFT 6

/*
 * @GPIO_PIN_OPTYPE
 * GPIO pin output types
 */
#define GPIO_OUT_PP    0
#define GPIO_OUT_OPDRN   1

/*
 * GPIO_PIN_OSPEED
 * GPIO pin output speeds
 */
#define GPIO_OSPEED_LOW       0
#define GPIO_OSPEED_MEDIUM    1
#define GPIO_OSPEED_HIGH      2
#define GPIO_OSPEED_VERY_HIGH 2

/*
 * GPIO_PIN_PUPD
 * GPIO pin PUPD modes
 */
#define GPIO_NO_PUPD     0
#define GPIO_PIN_PU      1
#define GPIO_PIN_PD      2

#endif /* GPIO_H_ */
