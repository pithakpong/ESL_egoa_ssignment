# Project Name

Brief project description or a catchy project slogan.

## Table of Contents
- [Project Description](#project-description)
- [Project Components](#project-components)
- [How to Use the Project](#how-to-use-the-project)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [License](#license)

## Project Description

Provide a more detailed description of your project, including its purpose and goals.

## Project Components

List the major components of your project.

- **Database Files:**
  - Description of the database files and their purpose.

- **Scripts.py:**
  - Description of the scripts file and what it does.

- **Microcontroller Directory:**
  - Description of the microcontroller code and its role in the project.

- **Node-RED Directory:**
  - Description of the Node-RED flow and its significance.

## How to Use the Project

Explain how to set up and use the project. Provide clear and step-by-step instructions.

1. **Import the Node-RED Flow:**
   1. Import the `flows.json` file into your Node-RED instance.
   2. Modify the file paths in the Node-RED flow to match your project's file structure.

2. **Modify Scripts:**
   - Edit the `scripts.py` file and update the port name and baud rate to match your ESP32's serial communication settings.

3. **MQTT Configuration:**
   - Ensure that the MQTT settings in the Node-RED flow match your MQTT server's name and topic configuration.

4. **ESP32 Configuration:**
   - In the "microcontroller" directory, locate the `microcontroller.ino` file.
     - Replace `ssid` and `password` with your Wi-Fi network credentials.
     - Configure MQTT settings to match your MQTT broker.

5. **Database Configuration:**
   - Ensure you have the SQLite database files (`testDB.db` and `testDB2.db`) in your project directory.

6. **Deploy and Run:**
   - Deploy the Node-RED flow.
   - Upload the modified `microcontroller.ino` to your ESP32.
   - Start both Node-RED and the ESP32.

7. **Interact:**
   - View sensor data, including average temperature and humidity, on the Node-RED dashboard.
   - Utilize the LED controller widget to manage the LED's state.

## Troubleshooting

Provide guidance on what to do if users encounter issues or errors while setting up or using the project.

- Monitor the Node-RED debug console for any errors.
- Check the ESP32 serial output for debugging information.
- Ensure your MQTT broker is running and configured correctly.

## Contributing

Explain how others can contribute to your project if you're open to contributions. This could include guidelines for submitting bug reports, feature requests, or pull requests.

## License

Specify the license under which your project is distributed.
![Image 1](https://github.com/pithakpong/ESL_egoa_ssignment/blob/main/ui.png)
*show humility and temperature*

![Image 2](https://github.com/pithakpong/ESL_egoa_ssignment/blob/main/esp.jpg)
*esp control led on / led off*

![Image 3]([images/image3.png](https://github.com/pithakpong/ESL_egoa_ssignment/blob/main/mqtt.png))
*mqtt server*

![Image 4](https://github.com/pithakpong/ESL_egoa_ssignment/blob/main/ledcontrol.png)
*button control led dashboard*
