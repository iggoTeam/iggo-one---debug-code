# iggo-one-arduino---debug-code
debug code for testing GPIO and BUS

# tp51 ±0.1°C Digital Temperature Sensor
**Note:**
  - I2C Interface with the fixed **0x40** I2C address
  - High Accuracy Temperature Sensor Si7051: ± 0.1 ºC (max)
  - Wide operating voltage (1.9 to 3.6 V)
  - Operating Range -40 to +125 ºC
  - Factory calibrated

| CommandDescription  | Command | Code |
| ------------- | ------------- | ------------- |
| Measure Temperature, Hold Master Mode | --- | 0xE3 |
| Measure Temperature, No Hold Master Mode | --- | 0xF3 |
| Reset | --- | 0xFE |
| Write User Register | --- | 0xE6 |
| Write User Register | --- | 0xE6 |
| Read User Register | --- | 0xE7 |
| Read Electronic ID 1st Byte | --- | 0xFA 0x0F |
| Read Electronic ID 2nd Byte | --- | 0xFC 0xC9 |
| Read Firmware Revision | --- | 0x84 0xB8 |

| Accuracy Max  | range |
| -------------------------- | ------------- |
| ±0.1 °C  | +35.8 °C to 41 °C |
| ±0.13 °C  | 20.0 °C to 70.0 °C |
| ±0.25 | –40 °C to +125 °C |


±0.1 °C: +35.8 °C to 41 °C
±0.13 °C: 20.0 °C to 70.0 °C
±0.25 °C: –40 °C to +125 °C
