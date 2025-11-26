# Arduino Sensor Monitor 🏠

This project is a simple **Arduino-based sensor monitor** that reads data from basic sensors and applies a small piece of automation logic.

It uses:

- A **light sensor (LDR)** to detect ambient light
- A **temperature sensor** (e.g. LM35) to estimate room temperature
- A **PIR motion sensor** to detect movement
- An **LED** (or relay) to react to the environment

The logic is straightforward:

> If it is dark **and** motion is detected, turn the LED ON.  
> Otherwise, keep it OFF.

All sensor readings are also printed to the **Serial Monitor** so we can see what is happening in real time.

---

## 🎯 Goals of the Project

- Practice basic embedded systems concepts as an Electrical & Electronics Engineer  
- Work with analog and digital inputs on Arduino  
- Apply simple decision logic based on sensor data  
- Document the components and wiring so that someone else could reproduce the setup

This is a **beginner-level project**, not a final product.  
Its purpose is to show understanding of hardware + code interaction.

---

## 🧰 Hardware Used

- Arduino Uno (or compatible board)  
- LDR (photoresistor) + fixed resistor (e.g. 10 kΩ)  
- LM35 (or similar analog temperature sensor)  
- PIR motion sensor  
- LED + 220 Ω resistor  
- Breadboard & jumper wires

More details are in `docs/components.md`.

---

## 📂 Project Structure

```text
arduino-sensor-monitor/
├─ README.md
├─ src/
│   └─ sensor_monitor.ino
└─ docs/
    ├─ components.md
    └─ wiring-notes.md
