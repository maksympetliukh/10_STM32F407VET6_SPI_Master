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

			len--;

			pTX_buffer++;
		}
	}
}

/*****************************************************
 * @fn            - SPI_Data_Receive
 *
 * @brief         - This function receives data from the Data Register
 *
 * @param[in]     - Pointer to the base addresses of the SPI's port registers.
 * @param[in]     - Pointer to the buffer where received data will be stored.
 * @param[in]     - Length of the data that we want to receive.
 *
 * @return        - none
 *
 * * @note        - This is a blocking call
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
 * @fn            - SPI_IRQ_Interrupt_CFG
 *
 * @brief         - This function configures the IRQ interrupt
 *
 * @param[in]     - IRQ number
 * @param[in]     - Enable/Disable mode variable
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_IRQ_Interrupt_CFG(uint8_t IRQ_Number, uint8_t en_di_mode){
	if(en_di_mode == ENABLE){
		if(IRQ_Number <= 31){
			*NVIC_ISER0 |= (1 << IRQ_Number);
		}else if(IRQ_Number > 31 && IRQ_Number < 64){
			*NVIC_ISER1 |= (1 << (IRQ_Number % 32));
		}else if(IRQ_Number > 64 && IRQ_Number < 96){
			*NVIC_ISER2 |= (1 << (IRQ_Number % 64));
		}
	}else{
		if(IRQ_Number <= 31){
			*NVIC_ICER0 |= (1 << IRQ_Number);
		}else if(IRQ_Number > 31 && IRQ_Number < 64){
			*NVIC_ICER1 |= (1 << (IRQ_Number % 32));
		}else if(IRQ_Number > 64 && IRQ_Number < 96){
			*NVIC_ICER2 |= (1 << (IRQ_Number % 64));
		}
	}
}

/*****************************************************
 * @fn            - SPI_IRQ_Priority_CFG
 *
 * @brief         - This function configures the IRQ priority
 *
 * @param[in]     - IRQ number
 * @param[in]     - IRQ priority
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_IRQ_Priority_CFG(uint8_t IRQ_Number, uint8_t IRQ_Priority){
	if(IRQ_Priority > 15) IRQ_Priority = 15;

	uint8_t reg_index = IRQ_Number / 4;
	uint8_t offset = IRQ_Number % 4;
	uint8_t shift_amount = (8 * offset) + (8 - PRIOR_BITS_IMPLEMENTED);

	*(NVIC_IRQ_PRIOR_BASE + (reg_index * 4)) &= ~(0xFFUL + (offset * 8));
	*(NVIC_IRQ_PRIOR_BASE + (reg_index * 4)) |= (IRQ_Priority << shift_amount);
}

//Some helper functions for SPI IRQ Handler
__weak void  SPI_ApplicationEventCallback(SPI_Handle_t *pHandle, uint8_t event_flag){

}

void SPI_CloseTransmission(SPI_Handle_t *pHandle){
	pHandle->pSPIx->CR2 &= ~(1 << SPI_CR2_TXEIE);
	pHandle->pTxBuffer = NULL;
	pHandle->TxLen = 0;
	pHandle->TxState = SPI_READY;
}

void SPI_CloseReception(SPI_Handle_t *pHandle){
	pHandle->pSPIx->CR2 &= ~(1 << SPI_CR2_RXNEIE);
	pHandle->pRxBuffer = NULL;
	pHandle->RxLen = 0;
	pHandle->RxState = SPI_READY;
}

void SPI_ClearOVRFlag(SPI_REG_t *pSPIx){
	uint8_t tmp;

	tmp = pSPIx->DR;
	tmp = pSPIx->SR;

	(void)tmp;
}


void spi_txe_interrupt_handle(SPI_Handle_t *pHandle){
	if(pHandle->pSPIx->CR1 & (1 << SPI_CR1_DFF)){
		//16 bit DFF
		pHandle->pSPIx->DR = *((uint16_t*)pHandle->pTxBuffer);
		pHandle->TxLen -= 2;
		pHandle->pTxBuffer += 2;
	}else{
		//8 bit DFF
		pHandle->pSPIx->DR = *pHandle->pTxBuffer;
		pHandle->TxLen--;
		pHandle->pTxBuffer++;
	}

	if(!pHandle->TxLen){
		SPI_CloseTransmission(pHandle);
		SPI_ApplicationEventCallback(pHandle, SPI_EVENT_TX_CMPLT);
	}
}

void spi_rxne_interrupt_handle(SPI_Handle_t *pHandle){
	if(pHandle->pSPIx->CR1 & (1 << SPI_CR1_DFF)){
		*((uint16_t*)pHandle->pRxBuffer) = pHandle->pSPIx->DR;
		pHandle->pRxBuffer += 2;
		pHandle->RxLen -= 2;
	}else{
		*pHandle->pRxBuffer = pHandle->pSPIx->DR;
		pHandle->pRxBuffer++;
		pHandle->RxLen--;
	}

	if(!pHandle->RxLen){
		SPI_CloseReception(pHandle);
		SPI_ApplicationEventCallback(pHandle, SPI_EVENT_RX_CMPLT);
	}
}

void spi_ovr_interrupt_handle(SPI_Handle_t *pHandle){
	SPI_ClearOVRFlag(pHandle->pSPIx);
	SPI_ApplicationEventCallback(pHandle, SPI_EVENT_OVR_ERR);
}


/*****************************************************
 * @fn            - SPI_IRQ_Handler
 *
 * @brief         - This function handles the SPI IRQ
 *
 * @param[in]     - pointer to the SPI handle structure
 *
 * @return        - none
 *
 * * @note        - none
 */
void SPI_IRQ_Handler(SPI_Handle_t *pHandle){
	uint8_t tmp1, tmp2;

	//Check for TXE
	tmp1 = pHandle->pSPIx->SR & (1 << SPI_SR_TXE);
	tmp2 = pHandle->pSPIx->CR2 & (1 << SPI_CR2_TXEIE);

	if(tmp1 && tmp2){
		spi_txe_interrupt_handle(pHandle);
	}

	//Check for RXNE
	tmp1 = pHandle->pSPIx->SR & (1 << SPI_SR_RXNE);
	tmp2 = pHandle->pSPIx->CR2 & (1 << SPI_CR2_RXNEIE);

	if(tmp1 && tmp2){
		spi_rxne_interrupt_handle(pHandle);
	}

	//Check for OVR
	tmp1 = pHandle->pSPIx->SR & (1 << SPI_SR_OVR);
	tmp2 = pHandle->pSPIx->CR2 & (1 << SPI_CR2_ERRIE);

	if(tmp1 && tmp2){
		spi_ovr_interrupt_handle(pHandle);
	}
}

uint8_t SPI_Transmit_IT(SPI_Handle_t *pSPI_Handle, uint8_t *pTxBuffer, uint32_t len){

	uint8_t state = pSPI_Handle->TxState;

	if(state != SPI_BUSY_IN_TX){
		pSPI_Handle->pTxBuffer = pTxBuffer;
		pSPI_Handle->TxLen = len;
		pSPI_Handle->TxState = SPI_BUSY_IN_TX;
		pSPI_Handle->pSPIx->CR2 |= (1 << SPI_CR2_TXEIE);
	}

	return state;
}

uint8_t SPI_Receive_IT(SPI_Handle_t *pSPI_Handle, uint8_t *pRxBuffer, uint32_t len){

	uint8_t state = pSPI_Handle->RxState;

	if(state != SPI_BUSY_IN_RX){
		pSPI_Handle->pRxBuffer = pRxBuffer;
		pSPI_Handle->RxLen = len;
		pSPI_Handle->RxState = SPI_BUSY_IN_RX;
		pSPI_Handle->pSPIx->CR2 |= (1 << SPI_CR2_RXNEIE);
	}

	return state;
}
