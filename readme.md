# Bluetooth Controlled Electric Skateboard

Welcome to the Bluetooth Controlled Electric Skateboard project! This project aims to provide a safe and user-friendly way for beginners to learn skating. By incorporating Arduino, Bluetooth technology, and a mobile application, you can control the speed of the electric skateboard and receive obstacle notifications through a smartphone.

## Features

- **Mobile Application:** The remote controller for the electric skateboard is a mobile application developed using Flutter. This allows for a seamless and intuitive control experience.

- **Speed Control:** The speed of the electric skateboard is initially set to 0. Using the up button in the mobile application, you can increase the speed of the skateboard. Conversely, by pressing the down button, you can decrease the speed.

- **Force Stop:** To ensure safety, a force stop button is included in the mobile application. When pressed, the skateboard gradually decelerates and comes to a complete stop within 5 seconds.

- **Obstacle Detection:** A sonar sensor is integrated into the skateboard to detect obstacles in front of it. If an obstacle is detected, a buzzer alerts the rider by producing a sound, preventing potential collisions.

- **LED Lights:** The skateboard features LED lights, including green and red colors, enhancing its visual appeal while providing additional safety during low-light conditions.

## Getting Started

To get started with the Bluetooth Controlled Electric Skateboard, follow these steps:

### Prerequisites

- Arduino board (compatible with the Arduino IDE)
- Motor driver module (BTS7960)
- Bluetooth module (HC05)
- Sonar sensor
- Buzzer
- LEDs (green and red)
- Remote Control (Contact for the mobile application)

### Hardware Setup

Follow the circuit diagram.

### Software Setup

1. Install the Arduino IDE on your computer, if not already installed.

2. Open the Arduino IDE and create a new sketch.

3. Copy the Arduino code provided in this repository.

4. Connect your computer to the Arduino board and upload the sketch.

5.  Pair the mobile applicaion with the Bluetooth module connected to the Arduino board.

6.  Enjoy controlling the electric skateboard through the mobile application!

## Contributing

We welcome contributions to the Bluetooth Controlled Electric Skateboard project. If you have any suggestions, bug reports, or feature requests, please submit them via the issue tracker in the project repository. You can also fork the project, make improvements, and submit a pull request for review.

## License

The Bluetooth Controlled Electric Skateboard project is licensed under the [MIT License](https://opensource.org/licenses/MIT). Feel free to use, modify, and distribute the project code for personal or commercial purposes.

## Acknowledgments

We would like to acknowledge the following individuals and projects for their contributions and inspirations:

- [Flutter](https://flutter.dev/) - The open-source UI framework used for developing the mobile application.
- [Arduino](https://www.arduino.cc/) - The open-source electronics platform used for controlling the electric skateboard.

## Contact

If you have any questions or need further assistance, please don't hesitate to contact the project maintainer at [biswasbijoy414@gmail.com] We would be happy to assist you!

Happy skating!
