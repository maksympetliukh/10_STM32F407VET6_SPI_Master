/*
 * spi.c
 *
 *  Created on: Feb 22, 2026
 *      Author: maksym
 */


#include "spi.h"

/*****************************************************
 * @fn            - spi_get_status_flag
 *
 * @brief         - This function returns SPI status flag.
 *
 * @param[in]     - pointer to the structure which contains SPI peripheral register base addresses.
 * @param[in]     - Flag variable.
 *
 * @return        - T or F
 *
 * * @note        - none
 */
uint8_t SPI_GetFlagStatus(SPI_REG_t *pSPIx, uint32_t flag){
	if(pSPIx->SR & flag){
		return FLAG_SET;
	}
	return FLAG_RESET;
}

/*****************************************************
 * @fn            - SPI_Init
 *
 * @brief         - This function initializes the SPI port and pin according to the specified settings in the handle structure.
 *
 * @param[in]     - pointer to the SPI handle structure which contains base address and configuration settings.
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_Init(SPI_Handle_t *pSPI_Handle){

	//Enable the peripheral clock
	SPI_ClockControl(pSPI_Handle->pSPIx, ENABLE);
	//Configure the CR1 register
	uint32_t tmp = 0;

	//device mode
	tmp |= pSPI_Handle->SPI_Configs.spi_device_mode << SPI_CR1_MSTR;

	//bus configurations
	if(pSPI_Handle->SPI_Configs.spi_bus_config == SPI_BUS_CFG_FD){
		//BIDI mode should be cleared
		tmp &= ~(1 << SPI_CR1_BIDIMODE);
	}else if(pSPI_Handle->SPI_Configs.spi_bus_config == SPI_BUS_CFG_HD){
		//Enable the BIDI mode
		tmp |= (1 << SPI_CR1_BIDIMODE);
	}else if(pSPI_Handle->SPI_Configs.spi_bus_config == SPI_BUS_CFG_SIMPLEX_RXONLY){
		//BIDI mode should be cleared and RXONLY must be set
		tmp &= ~(1 << SPI_CR1_BIDIMODE);
		tmp |= (1 << SPI_CR1_RXONLY);
	}

	//SPI Serial Clock Speed
	tmp |= pSPI_Handle->SPI_Configs.spi_clock_speed << SPI_CR1_BR;

	//DFF
	tmp |= pSPI_Handle->SPI_Configs.spi_dff << SPI_CR1_DFF;

	//CPOL
	tmp |= pSPI_Handle->SPI_Configs.spi_cpol << SPI_CR1_CPOL;

	//CPHA
	tmp |= pSPI_Handle->SPI_Configs.spi_cpha << SPI_CR1_CPHA;

	//SSM
	tmp |= pSPI_Handle->SPI_Configs.spi_ssm << SPI_CR1_SSM;

	if(pSPI_Handle->SPI_Configs.spi_ssm == SPI_SSM_EN){
		tmp |= (1 << SPI_CR1_SSI);
	}

	pSPI_Handle->pSPIx->CR1 = tmp;
}

/*****************************************************
 * @fn            - SPI_DeInit
 *
 * @brief         - This function allows us to reset the SPI port
 *
 * @param[in]     - Pointer to the structure that contains the base addresses  of the SPI port registers.
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_DeInit(SPI_REG_t *pSPIx){
	if(pSPIx == NULL){return;}

	if(pSPIx == SPI1){
		SPI1_REG_RESET();
	}else if(pSPIx == SPI2){
		SPI2_REG_RESET();
	}else if(pSPIx == SPI3){
		SPI3_REG_RESET();
	}else if(pSPIx == SPI4){
		SPI4_REG_RESET();
	}
}

/*****************************************************
 * @fn            - SPI_ClockControl
 *
 * @brief         - This function allows us to enable/disable a Peripheral Clock
 *
 * @param[in]     - Pointer to the structure that contains the base addresses of the SPI port registers.
 * @param[in]     - Enable/Disable mode variable
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_ClockControl(SPI_REG_t *pSPIx, uint8_t en_di_mode){
	if(en_di_mode == ENABLE){
		if(pSPIx == SPI1){
			RCC_SPI1_CLK_ENABLE();
		}else if(pSPIx == SPI2){
			RCC_SPI2_CLK_ENABLE();
		}else if(pSPIx == SPI3){
			RCC_SPI3_CLK_ENABLE();
		}else if(pSPIx == SPI4){
			RCC_SPI4_CLK_ENABLE();
		}
	}else if(en_di_mode == DISABLE){
		if(pSPIx == SPI1){
			RCC_SPI1_CLK_DISABLE();
		}else if(pSPIx == SPI2){
			RCC_SPI2_CLK_DISABLE();
		}else if(pSPIx == SPI3){
			RCC_SPI3_CLK_DISABLE();
		}else if(pSPIx == SPI4){
			RCC_SPI4_CLK_DISABLE();
		}
	}
}

/*****************************************************
 * @fn            - SPI_PeripheralControl
 *
 * @brief         - This function allows us to enable/disable the SPI Peripheral
 *
 * @param[in]     - Pointer to the structure that contains the base addresses of the SPI port registers.
 * @param[in]     - Enable/Disable mode variable
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_PeripheralControl(SPI_REG_t *pSPIx, uint8_t en_di_mode){
	if(en_di_mode == ENABLE){
		pSPIx->CR1 |= (1 << SPI_CR1_SPE);
	}else{
		pSPIx->CR1 &= ~(1 << SPI_CR1_SPE);
	}
}

/*****************************************************
 * @fn            - SPI_SSOE_CFG
 *
 * @brief         - This function sets the SSOE bit
 *
 * @param[in]     - Pointer to the structure that contains the base addresses of the SPI port registers.
 * @param[in]     - Enable/Disable mode variable
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_SSOE_CFG(SPI_REG_t *pSPIx, uint8_t en_di_mode){
	if(en_di_mode == ENABLE){
		pSPIx->CR2 |= (1 << SPI_CR2_SSOE);
	}else{
		pSPIx->CR2 &= ~(1 << SPI_CR2_SSOE);
	}
}

/*****************************************************
 * @fn            - SPI_SSI_CFG
 *
 * @brief         - This function enables the SSI
 *
 * @param[in]     - Pointer to the structure that contains the base addresses of the SPI port registers.
 * @param[in]     - Enable/Disable mode variable
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_SSI_CFG(SPI_REG_t *pSPIx, uint8_t en_di_mode){
	if(en_di_mode == ENABLE){
		pSPIx->CR1 |= (1 << SPI_CR1_SSI);
	}else{
		pSPIx->CR1 &= ~(1 << SPI_CR1_SSI);
	}
}
/*****************************************************
 * @fn            - SPI_Data_Transmit
 *
 * @brief         - This function sends data into the Data Register
 *
 * @param[in]     - Pointer to the base addresses of the SPI's port registers.
 * @param[in]     - Pointer to the data which we want to send.
 * @param[in]     - Length of the data that we want to send.
 * @return        - none
 *
 * * @note        - This is a blocking call
 */
void SPI_Data_Transmit(SPI_REG_t *pSPIx, uint8_t *pTX_buffer, uint32_t len){
	while(len > 0){
		//Wait until TXE is set
		while(SPI_GetFlagStatus(pSPIx, SPI_TXE_FLAG) == FLAG_RESET);

		//Check the DFF bit in CR1
		if(pSPIx->CR1 & (1 << SPI_CR1_DFF)){
			//16 bit DFF

			//Load the data into the DR
			pSPIx->DR = *((uint16_t*)pTX_buffer);

			//2 times because we took 2 bites (16 bits) of data
			len -= 2;


			//Increment the data pointer
			pTX_buffer += 2;

		}else{
			//8 bit DFF

			//Load the data into the DR
			pSPIx->DR = *pTX_buffer;

			len --;

			pTX_buffer++;
		}

	}
}

/*****************************************************
 * @fn            - GPIO_Init
 *
 * @brief         - This function initializes the GPIO port and pin according to the specified settings in the handle structure.
 *
 * @param[in]     - pointer to the GPIO handle structure which contains base address and configuration settings.
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_Data_Receive(SPI_REG_t *pSPIx, uint8_t *pRX_buffer, uint32_t len){
	while(len > 0){

		        while(SPI_GetFlagStatus(pSPIx, SPI_RXNE_FLAG) == FLAG_RESET);

		        if(pSPIx->CR1 & (1 << SPI_CR1_DFF)){
		            *((uint16_t*)pRX_buffer) = pSPIx->DR;

		            pRX_buffer += 2;
		            len -= 2;
		        }else{
		            *pRX_buffer = pSPIx->DR;

		            pRX_buffer++;
		            len--;
		        }
		    }
}

/*****************************************************
 * @fn            - GPIO_Init
 *
 * @brief         - This function initializes the GPIO port and pin according to the specified settings in the handle structure.
 *
 * @param[in]     - pointer to the GPIO handle structure which contains base address and configuration settings.
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_IRQ_Interrupt_CFG(uint8_t IRQ_Number, uint8_t en_di_mode){

}

/*****************************************************
 * @fn            - GPIO_Init
 *
 * @brief         - This function initializes the GPIO port and pin according to the specified settings in the handle structure.
 *
 * @param[in]     - pointer to the GPIO handle structure which contains base address and configuration settings.
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_IRQ_Priority_CFG(uint8_t IRQ_Number, uint8_t IRQ_Priority){

}

/*****************************************************
 * @fn            - GPIO_Init
 *
 * @brief         - This function initializes the GPIO port and pin according to the specified settings in the handle structure.
 *
 * @param[in]     - pointer to the GPIO handle structure which contains base address and configuration settings.
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_IRQ_Handler(SPI_Handle_t *pHandle){

}
