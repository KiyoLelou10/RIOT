@defgroup    boards_nucleo-f031k6 STM32 Nucleo-F031K6
@ingroup     boards_common_nucleo32
@brief       Support for the STM32 Nucleo-F031K6

## Overview

The Nucleo-F031K6 is a board from ST's Nucleo family supporting ARM Cortex-M0
STM32F031K6 microcontroller with 4KiB of RAM and 32KiB of Flash.

## Pinout

@image html pinouts/nucleo-f031k6-and-more.svg "Pinout for the Nucleo-F031K6 (from ST User Manual, UM1956, https://www.st.com/resource/en/user_manual/um1956-stm32-nucleo32-boards-mb1180-stmicroelectronics.pdf, page 31)" width=25%

### MCU

| MCU        |    STM32F031K6      |
|:---------- |:------------------- |
| Family     | ARM Cortex-M0       |
| Vendor     | ST Microelectronics |
| RAM        | 4KiB                |
| Flash      | 32KiB               |
| Frequency  | up to 48MHz         |
| FPU        | no                  |
| Timers     | 8 (5x 16-bit, 1x 32, 1x Systick, 1x Watchdog) |
| ADC        | 1x 12-bit (13 channels) |
| UARTs      | 1 (one USART)       |
| SPIs       | 1                   |
| CANs       | 0                   |
| RTC        | 1                   |
| I2Cs       | 1                   |
| Vcc        | 2.0V - 3.6V         |
| Datasheet  | [Datasheet](https://www.st.com/resource/en/datasheet/stm32f031k6.pdf) |
| Reference Manual | [Reference Manual](https://www.st.com/resource/en/reference_manual/rm0091-stm32f0x1stm32f0x2stm32f0x8-advanced-armbased-32bit-mcus-stmicroelectronics.pdf) |
| Programming Manual | [Programming Manual](https://www.st.com/resource/en/programming_manual/pm0215-stm32f0-series-cortexm0-programming-manual-stmicroelectronics.pdf) |
| Board Manual | [Board Manual](https://www.st.com/resource/en/user_manual/um1956-stm32-nucleo32-boards-mb1180-stmicroelectronics.pdf) |

## Flashing the Board Using ST-LINK Removable Media

On-board ST-LINK programmer provides via composite USB device removable media.
Copying the HEX file causes reprogramming of the board. This task
could be performed manually; however, the cpy2remed (copy to removable
media) PROGRAMMER script does this automatically. To program board in
this manner, use the command:
```
make BOARD=nucleo-f031k6 PROGRAMMER=cpy2remed flash
```
@note This PROGRAMMER was tested using ST-LINK firmware 2.37.26. Firmware updates
      can be found on [this STM webpage](https://www.st.com/en/development-tools/stsw-link007.html).
