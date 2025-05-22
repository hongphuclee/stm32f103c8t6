# STM32F103C8T6 Custom Library

This is a self-written library for the **STM32F103C8T6** microcontroller, developed using **IAR Embedded Workbench**.
It simplifies programming and controlling basic peripherals.

## Supported Features
https://github.com/hongphuclee/stm32f103c8t6/tree/master
- **GPIO**: Configure and control input/output pins, toggle LEDs, read buttons, etc.
- **UART**: Send/receive data via UART for debugging or device communication.
- **I2C**: Basic I2C communication, supports sensors, LCDs, etc.
- **LCD I2C**: Display data on 16x2 LCD using I2C module.
- **Timer**: Configure Timer1 for delay generation, PWM, etc.
- **SysTick**: Millisecond delay using the SysTick timer.
- **NVIC**: Manage and configure interrupts.
- **DMA**: Automatic data transfer using DMA.
- **Clock (RCC)**: Configure system clock, switch between HSI/HSE sources.
- **ADC**: Read analog input signals.
- **Button**: Handle button input.
- **Common macros and definitions**: Easy register and bit-level manipulation.

---

## Note

This project is for **personal learning and experimentation only**.
It is not intended to be a replacement for the STM32 HAL/LL libraries,
nor is it optimized for performance or robustness. It is built mainly
for educational purposes and to better understand how STM32 peripherals
work at the register level.

---
