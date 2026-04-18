# SPI Master on STM32F407VET6

### What this project is
This project was created to learn basic principles, logic and how SPI protocol works.
Learn how to design and develop SPI driver and custom HAL-like library. This project aims to study the master device.
This project is developed accordingly to online course [(MCU1) Learn bare-metal driver development using Embedded C:
Writing drivers for STM32 GPIO, I2C, SPI, USART from scratch.](https://www.udemy.com/course/mastering-microcontroller-with-peripheral-driver-development/)

### Goals
- learn the SPI protocol general principles, architecture and registers
- learn how to design and develop SPI driver and library
- learn how to build master-device logic for SPI
- learn both blocking and non-blocking (with interrupts) communication
- learn how to check SPI communication with logic analyzer

### What actually program does
- configure all required peripherals for button, LED, SPI
- configure the SPI port parameters and behavior
- configure interruption setups
- design event callback API
- send data from master
- get a response from the slave-device accordingly to the AppEvCallback logic

### How to check I2C communication with Sealae Logic Analyzer
- connect master-device, slave device and logic analyzer together (I've used breadboard for convenience)
- configure PulseView measure parameters (I've used 24 MHz and 20 MS/s)
- check the transmitted and received signals

### Used devices
- MCU: **STM32F407VET6**
- MCU: **STM32F401CCU6**
- CPU: **ARM Cortex-M4**
- Logic Analyzer: **Sealae Logic Analyzer**
- Debugger: **ST-LINK V2.2**

### Used software and documentation
- Programming language: **C**
- Implementation: **bare-metal**
- IDE: **STM32CubeIDE**
- Debug tool: **STM32CubeProgrammer**
- Analysis tool: **PulseView**
- Reference manual: **RM0090**
- Reference manual: **RM00368**
- User manual: **ARM Cortex-M4**