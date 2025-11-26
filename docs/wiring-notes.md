# Wiring Notes

Below is a simple description of how the components are wired.

## LDR (Light Sensor)

- One leg of the LDR → **5V**
- Other leg of the LDR → **A0** and → a fixed resistor (e.g. 10 kΩ) to **GND**

This forms a voltage divider.  
The analog value is read from **A0**.

## Temperature Sensor (LM35 example)

- **VCC** → 5V  
- **GND** → GND  
- **OUT** → **A1**

The analog reading from A1 is converted to °C in code.

## PIR Motion Sensor

- **VCC** → 5V  
- **GND** → GND  
- **OUT** → Digital pin **2**

When motion is detected, the output goes HIGH.

## LED

- Anode (long leg) → Digital pin **8** through a **220 Ω** resistor  
- Cathode (short leg) → GND
