# Solenoid Lock using PWM Signals

This example shows how to operate solenoid lock using PWM signals which is generally used in EV cars where gun need to be locked while communication processes are ongoing. It's a basic setup that you can build upon STM32 Developement Board. 

## How to use example

### Hardware Required

The example can be run on STM32 (STM32L073VBT) based development board. You will need a USB cable to connect the
development board to a computer.

### Setup the Hardware

Here is the circuit of solenoid lock. 
[Solenoid_Lock_Circuit.png](https://github.com/Nirav0401/Solenoid_Lock/blob/main/Solenoid_Lock_Circuit.png)

lock_cntrl_1 -> Pin No 56 -> GPIO9 - PD9,
cont_cntrl_1 -> Pin No 55 -> GPIO8 - PD8,
fb1 -> Pin No 81 -> TIM21_CH1 -> PD0 for PWM generation,

You need to connect solenoid device to 5V Input and other two connections (V1 and V2) for making the device lock and unlock using pwm.

## Example Output

````
void solenoid_lock (void);
- This function activates the solenoid to lock. It sets the lock_cntrl_1 pin to high to power the solenoid coil. The cont_cntrl_1 pin remains low which activates V1 pin, and a PWM signal is generated on the fb1 pin.

void solenoid_release (void);
- This function deactivates the solenoid and as a result releasing its lock. It sets the lock_cntrl_1 pin to high to power the solenoid coil, cont_cntrl_1 pin to high to trigger the Q9 mosfet which further activates V2 pin and a PWM signal is generated on the fb1 pin.

````
