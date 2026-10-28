# Autonomous Thermal-Guided Flame Suppression Turret
Swiveling, heat-detecting mounted blower for putting out small nearby heat sources.

---

## Table of Contents
1. [Overview](#overview)
2. [Components](#components)
3. [Wiring](#wiring)
4. [Hardware Setup](#hardware-setup)
5. [Power Notes](#power-notes)
6. [Photos](#photos)

---

## Overview
A stationary pan/tilt turret controlled by an ESP32. When idle it sweeps back and forth looking for heat. A 32x24 thermal camera mounted next to the blower nozzle finds the hottest spot, the turret turns until that spot is centered, and a 12V blower fan puts the flame out. Once the temperature drops it goes back to sweeping.

- **Purpose:** learn ESP32 programming, thermal sensing, and servo control with a build that reacts to real heat.
- **V1:** prototype on the bench. No soldering and no PCB, everything is connected with jumper wires, servo extensions, and screw terminals. Built for small test flames like a candle.
- **V2:** compact version with a custom PCB.

---

## Components

| Part | Use |
|------|-----|
| AITRIP ESP32 DevKit (ESP-WROOM-32, 30 pin, USB-C, CP2102) | Main controller |
| MLX90640-D55 thermal camera (32x24, 55° FOV, I2C) | Finds the flame |
| 2x Miuzei 20kg metal gear servos (180°) | Pan and tilt |
| GDSTIME 7530 12V brushless blower fan | Blows the flame out |
| MOSFET switch module (dual MOS, 4-60V) | Lets the ESP32 turn the 12V fan on and off |
| 12V 5A power supply (5.5x2.1mm barrel plug) | Main power |
| HiLetgo XL4015 5A buck converter with voltmeter | Steps 12V down to 6V for the servos |
| Inline fuse holder + mini blade fuses | Protects the 12V line |
| 30cm servo extension cables | Servo wiring |
| M2-M5 screw kit | Mounting |
| Bambu Lab A1 mini + black PLA | Printed mounts |

---

## Wiring
- **12V supply** -> barrel jack screw terminal adapter -> XL4015 buck converter IN+ / IN-
- **Buck converter output** -> set to 6.0V (nothing connected yet)

---

## Hardware Setup
1. **Buck converter**
   - The servos can't take 12V, so the XL4015 steps the 12V supply down to 6V for them.
   - Connected the 12V supply to the XL4015 input through a barrel jack screw terminal adapter.
   - With nothing on the output, turned the adjustment screw until the display read 6.0V.
   - Checked the output with a multimeter: 6.04V.

---

## Power Notes
- Servos run off the 6V buck output, never off the ESP32.
- The two servos can pull 2A+ each when starting or stalled, which is why the buck converter is the 5A XL4015.
- The fan runs straight off 12V through the MOSFET module.
- The ESP32 is powered over USB for V1.

---

## Photos
- Buck converter set to 6V, multimeter reading 6.04V on the output
  <br><img src="assets/images/01_buck_6v.jpg" width="400">
<br><br>
