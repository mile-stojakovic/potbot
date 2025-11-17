# PotBot
The source code for The Scrabblers' ENGR 130 Project 3, PotBot.

## Setup
### Prerequisites
PlatformIO, Git, Python

### Installation
Clone the repository from GitHub:
```bash
git clone https://github.com/mile-stojakovic/potbot.git
```
If you have the PlatformIO plugin for VSCode, you should just be able to click the compile and run buttons. If you are using the CLI version of PlatformIO, Navigate into the folder and run the following command:
```bash
pio run -t upload
```
### Web Server
To start the web server, you must have flask installed with Python. To install it, run the following command:
```bash
pip install flask
```
You must also ensure that both the ESP32 and your computer are connected to a network whose subnet mask allows the devices to connect. To be safe, you can connect both of them to the same network.
The WiFi credentials are stored in a PlatformIO library. To provide them, add the following text to `lib/WiFiCredentials/WiFiCredentials.h`:
```c
char* WIFI_SSID = "your network's name";
const char* WIFI_PASS = "your network's password";
const char* SERVER_IP = "your network's IP address, in https://0.0.0.0:5000 format";
```
Then to start the server, run:
```bash
python python/main.py
```
