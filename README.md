# Automated Gate System
An Arduino-based automated gate system that uses ultrasonic sensors to detect objects and automatically opens/closes a gate using a servo motor.
## Features
- Automatic gate opening when objects are detected within 15cm
- Visual status indicators using LED lights
  - Red LED: Gate is closed
  - Blue LED: Gate is open
- Audible feedback using a piezo buzzer
- Automatic gate closing after 5 seconds
- Distance monitoring via Serial Monitor
## Hardware Requirements
- Arduino Board (Uno, Nano, or similar)
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- 2 LEDs (Red and Blue)
- Piezo Buzzer
- Jumper Wires
- Breadboard (optional)
## Pin Connections
| Component    | Arduino Pin |
|-------------|-------------|
| Ultrasonic Trigger | D2 |
| Ultrasonic Echo   | D3 |
| Red LED           | D4 |
| Blue LED          | D5 |
| Servo Motor       | D6 |
| Additional Ground | D7 |
| Additional Ground | D8 |
| Piezo Buzzer      | D12 |
## Installation
1. Connect the components according to the pin connections table
2. Upload the \utomated_gate.ino\ file to your Arduino board
3. Open the Serial Monitor (9600 baud) to view distance measurements
## Operation
- The gate automatically opens when an object is detected within 15cm
- The gate remains open for 5 seconds
- The buzzer provides audible feedback while the gate is open
- The gate automatically closes after 5 seconds
- LED indicators show the current gate status
## Customization
You can modify the following parameters in the code:
- Detection distance (currently 15cm)
- Gate open duration (currently 5000ms)
- Servo angles (currently 0° for closed, 80° for open)
- Buzzer intervals and patterns
## License
This project is open source and available under the MIT License.
## Author
 fredgisa
## Contributing
Feel free to submit issues and enhancement requests!
