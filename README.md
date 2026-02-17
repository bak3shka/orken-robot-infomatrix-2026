# ORKEN ROBOT — Precision Farming MVP (Infomatrix Asia 2026)

ORKEN ROBOT is an affordable precision-farming robot designed to automate **seeding** and **smart irrigation** for small-scale agriculture and school-level robotics demonstrations.

## Problem

Many small farms and educational labs still rely on manual planting and watering. This leads to:
- inconsistent watering decisions,
- extra labor,
- low repeatability in practical experiments.

## Solution

ORKEN ROBOT combines mobility, planting alignment, and soil-moisture-based irrigation in one Arduino-controlled platform:
- moves between planting points,
- lowers planting mechanism,
- aligns using photo sensor + laser,
- waters only when soil is dry (threshold-based).

## Key Features

- **Autonomous movement control** (forward/stop + extendable turn logic)
- **Lift mechanism** with upper/lower limit switches
- **Planting alignment module** (laser + photoresistor)
- **Smart irrigation** using soil moisture sensor
- **Real-time serial monitoring** for moisture values and robot actions

## System Workflow

1. Move forward to next point  
2. Stop and read soil moisture  
3. If dry: activate pump  
4. Lower planting tube/mechanism  
5. Align planting position with photo sensor + laser  
6. Water for defined duration  
7. Raise mechanism  
8. Move to next point and repeat

## Hardware (MVP)

- Arduino-compatible controller (**likely Arduino Mega 2560 class**, based on pin usage)
- 2x drive motors (left/right via motor driver)
- 1x spin motor module
- 1x lift motor module
- 1x water pump module
- 2x limit switches (upper/lower)
- 1x photoresistor (A0)
- 1x soil moisture sensor (A1)
- 1x laser module
- Motor driver + external power supply

## Pin Mapping (from current firmware)

| Module | Pins |
|---|---|
| Lower limit switch (`b_niz`) | 27 |
| Upper limit switch (`b_verh`) | 34 |
| Left drive motor | 4, 5 |
| Right drive motor | 2, 3 |
| Spin motor | 6, 7 |
| Lift motor | 9, 8 |
| Pump (`nasos`) | 10, 11 |
| Laser | 42 |
| Photo sensor | A0 |
| Soil moisture sensor | A1 |

## Firmware

Main firmware file: **`orken_robot.ino`**

Core control functions:
- `forward()`, `back()`, `turnLeft()`, `turnRight()`, `stopp()`
- `tpyba_niz()` / `tpyba_verh()` for lift limits
- `plant()` for laser/photo alignment
- `nasos()` for irrigation

## Build & Upload

1. Install **Arduino IDE 2.x**
2. Open `orken_robot.ino`
3. Select board:
   - `Arduino Mega 2560` (or your exact compatible board)
4. Select correct COM port
5. Upload firmware
6. Open Serial Monitor at **9600 baud** to view moisture logs

## Repository Structure

```text
.
├── README.md
└── orken_robot.ino
```
## Submission Links (Infomatrix Asia 2026)

- **Product Demo Video:** [YouTube](https://youtu.be/JLYbQbTHHys)
- **Startup Pitch Deck:** [Google Slides](https://docs.google.com/presentation/d/1T90bJU_dUtlaM3bAGNIbP5MnqOs_f7LU/edit?usp=sharing)
