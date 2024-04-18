# Solenoid Lock using PWM Signals

This example shows how to operate solenoid lock using PWM signals which is generally used in EV cars where gun need to be locked while communication processes are ongoing. It's a basic setup that you can build upon STM32 Developement Board. 

## How to use example

### Hardware Required

The example can be run on any commonly available STM32 based development board. You will need a USB cable to connect the
development board to a computer.

### Setup the Hardware

ADC Interface -> sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
              -> sConfig.SamplingTime = ADC_SAMPLETIME_112CYCLES;
              -> hadc1.Init.Resolution = ADC_RESOLUTION_12B;

## Example Output

````
HAL_ADC_Start_DMA(&hadc1, &ADC_VAL, 1);
- This function starts an ADC conversion in DMA mode.

&hadc1 -> This is a pointer to the ADC handle (hadc1 in this case), which is a structure containing ADC configuration and state information.
&ADC_VAL -> This is a pointer to the memory location where the ADC conversion result will be stored.
1 -> This specifies the number of ADC conversions to perform.

printf("Temp value is %0.2f\n", Temp);
You will receive the logs of temperature reading on the console.

````
