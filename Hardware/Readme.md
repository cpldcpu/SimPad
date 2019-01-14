# Hardware

The experimental programmer hardware is based on an Arduino Nano with a ATMega168PA. 

The lines of the programming interface of the MCU are directly connected to GPIOs as shown below. Also VDD is controlled by a GPIO. Maximum load on VDD is 20mA according to the PMS150C datasheet, which can be easily sourced from the ATMega. Vpp is generated with a simple boost converter.

This is a minimal implementation and is not representative of a production worthy programmer.

	     6-wire    5-wire
	PWM = VPP     = ICVPP
	PB0 = VDD     = VDD  
	PB1 = MISO    = ICPDA      (data output of MCU or bidirectional)
	PB2 = MOSI    = Not used   (data input of MCU)
	PB3 = SCLK    = ICPCK 
	
	PA6 = ADC6 = voltage monitor input (5k1/10k divider)
 
## Boost converter to control Vpp

The programming voltage Vpp is generated with a simple boost converter that is controlled directly via the periphery of the ATMega. See below for circuit and LTspice simulator. This concept was previously used in the Openprog PIC programmer. See [here](http://openprog.altervista.org/OP_eng.html#Regulator) for more details.

Timer TC0 is used in fast PWM mode to generate a 62.5 kHz square wave on the input of the switching transistor. The voltage across the load is divided with R1 and R3 and fed back into the ADC of the ATMega. Right now the voltage in the programmer is not controlled in a closed loop, therefore changes of the load lead to a deviation of Vpp. To reduce the effect of load changes, a constant loading resistor was added.
A 1N4148 silicon diode with ~0.7 V voltage drop is used intentionally to reduce the standby voltage of the switching converter to below 5.0 V. 

## Open issues

 - To properly implement the programming sequence, including corner case verification, it is also necessary to control the voltage of VDD. This requires additional hardware.
<<<<<<< HEAD
 - Control of VPP is somewhat instable and has a slow step response. This could be improved with a closed loop converter or a dedicated boost converter IC.

### Circuit
![Circuit](booster%20circuit.gif)
### Simulation 
![Simulation](booster_transient.gif)
### Breadboard
![Breadboard](../hardware.jpg)
=======
 - Control of VPP is somewhat instable. This could be improved with a closed loop converter or a dedicated boost converter IC.

![Circuit](https://github.com/cpldcpu/SimPad/blob/master/Hardware/booster%20circuit.gif)
![Simulation](https://github.com/cpldcpu/SimPad/blob/master/Hardware/booster_transient.gif)
![Breadboard](https://github.com/cpldcpu/SimPad/blob/master/hardware.jpg)
>>>>>>> 6cad29db2b2d72b1e790ba1df813056a30018b4f
