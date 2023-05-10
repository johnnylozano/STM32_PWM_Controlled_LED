# STM32 ADC-PWM Demo

This project demonstrates register level programming on an STM32 microcontroller, using an ADC to read the voltage from a potentiometer and generating a PWM signal to control the brightness of an LED.

---

## Project Structure

The project is divided into three source files:

- main.c: The main program, which initializes the ADC and PWM, then continuously reads the ADC value and sets the PWM duty cycle based on the potentiometer value.
- adc.c: Implements ADC initialization and functions to start continuous conversions and read ADC values.
- tim.c: Implements the initialization of a Timer and PWM configuration.

## Requirements

- STM32F4 microcontroller (tested on STM32F401RE)
- Potentiometer
- LED
- 220 Ohm resistor
- Suitable power supply and connections for the microcontroller, LED, and potentiometer

## How to Build and Run

1. Compile the project with your preferred toolchain (such as GCC ARM or IAR Embedded Workbench) for the STM32F4 series.
2. Upload the compiled binary to your STM32F4 microcontroller using a programming tool (such as ST-Link Utility or OpenOCD).
3. Connect the potentiometer to PA1 on the STM32F4, which is configured for ADC input.
4. Connect the LED to PA5 on the STM32F4, which is configured for PWM output.
5. Power on the microcontroller and rotate the potentiometer. The brightness of the LED should change according to the potentiometer position.

## How it Works

1. The ADC is configured in continuos conversion mode to read the voltage from the potentiometer connected to PA1.
2. The Timer is configured to generate a PWM signal on PA5.
3. The main program loop continuously reads the ADC value (potentiometer position) and updates the PWM duty cycle to control the brightness of the LED.

## Video Demo

<video width="640" height="480" controls muted>
  <source src="demo/demo.MOV" type="video/quicktime">
  Your browser does not support the video tag.
</video>

## License

This project is released under the MIT License. See the LICENSE file for more details.
