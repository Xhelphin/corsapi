# CorsaPi
A dynamic in-car lighting solution.  

## What is CorsaPi?
CorsaPi is a dynamic in-car lighting solution designed to provide fancy lighting to your car. It runs on an Arduino (preferably an Arduino Uno) which controls the light strip (Pimoroni Blinkt!) and a Raspberry Pi which runs a web application to allow you to control the device.  

CorsaPi works like this:  
1. The Blinkt! LED strip is connected to the Arduino via GPIO pins.  
2. The Arduino connects to the Raspberry Pi through Serial over USB.  
3. The Raspberry Pi connects to a WiFi network and runs a web application.  
4. When you press on a button in the web application, the Raspberry Pi tells the Arduino over the serial connection. The Arduino will start to run in the new mode.  

## What you need to run CorsaPi
To run CorsaPi, you will need the hardware mentioned above. Follow the list below to make sure you have all of the hardware you will need:  
- [Pimoroni Blinkt!](https://shop.pimoroni.com/products/blinkt?variant=22408658695)  
- Any Arduino with a USB connection and at least 2 digital GPIO pins, 1 5V pin and 1 GND pin.  
- Any Raspberry Pi that can connect to WiFi (Some models, such as the Raspberry Pi 4, will startup faster than others).  
- 4 GPIO jumper cables  
- A USB cable to connect the Arduino to the Raspberry Pi.  

## How to install CorsaPi
### Arduino
1. Download the [arduino.ino](arduino/arduino.ino) file.  
2. Make sure to edit the `DATAPIN` and `CLOCKPIN` lines in the code to refelect the pins you are using on your Arduino.  
3. Flash the file to the Arduino using the Arduino IDE.  

### Raspberry Pi
1. Clone this repository using `cd ~ && git clone https://github.com/xhelphin/corsapi`  
2. Navigate to the installer folder using `cd ~/corsapi/installer`  
3. Make the installer executable using `chmod +x install.sh`  
4. Run the installer using `sudo ./install.sh`  
5. Shut down the Pi using `sudo shutdown now -h`  

### Hardware
Use [this page](https://pinout.xyz/pinout/blinkt) while following these steps to find the right pions on the Blinkt!  
1. Disconnect all devices (Blinkt!, Arduino, Raspberry Pi) from power.
2. Connect the 5V pin on the Blinkt to the 5V pin on the Arduino.  
3. Connect the GND pin on the Blinkt to the GND pin on the Arduino.  
4. Connect the data pin to the data pin set in the Arduino code.  
5. Connect the clock pin to the clock pin set in the Arduino code.  
6. Connect the Arduino to the Raspberry Pi over USB.  
7. Connetct the Raspberry Pi to power.  

## How to uninstall CorsaPi
1. Navigate to the installer folder using `cd ~/corsapi/installer`  
2. Make the uninstaller executable using `chmod +x uninstall.sh`  
3. Run the uninstaller using `sudo ./uninstall.sh`  
4. Shut down the Pi using `sudo shutdown now -h`  
5. Unplug the Pi from power, the Arduino from the Raspberry Pi, and the Blinkt! from the Arduino.  

## Why is it called CorsaPi?
It was originally called CorsaPi as it was developed on a Raspberry Pi to be used in my Corsa. The name hasn't changed.

## Functions
### Static
- Static Red  
    - This function sets the Blinkt! to a static red. This does not have an animation.  
- Static Green  
    - This function sets the Blinkt! to a static green. This does not have an animation.  
- Static Blue  
    - This function sets the Blinkt! to a static blue. This does not have an animation.  
- Static White  
    - This function sets the Blinkt! to a static white. This does not have an animation.  
- Static Magenta  
    - This function sets the Blinkt! to a static magenta. This does not have an animation.  
- Static Yellow  
    - This function sets the Blinkt! to a static yellow. This does not have an animation.  
- Static Cyan  
    - This function sets the Blinkt! to a static cyan. This does not have an animation.  
- Static Orange  
    - This function sets the Blinkt! to a static orange. This does not have an animation.  
- Static Pink  
    - This function sets the Blinkt! to a static pink. This does not have an animation.  
- Static Purple  
    - This function sets the Blinkt! to a static purple. This does not have an animation.  
- Static White (50% Brightness)  
    - This function sets the Blinkt! to a static white at 50% brightness. This does not have an animation.  

### Strobe
- Strobe White  
    - This function flashes the Blinkt! between white and off. This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  
- Strobe Colours  
    - This function flashes the Blinkt! between white, red, green, blue and off. This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  
- Strobe Red  
    - This function flashes the Blinkt! between red and off. This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  
- Strobe Green  
    - This function flashes the Blinkt! between green and off. This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  
- Strobe Blue  
    - This function flashes the Blinkt! between blue and off. This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  
- Strobe Magenta  
    - This function flashes the Blinkt! between magenta and off. This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  
- Strobe Yellow  
    - This function flashes the Blinkt! between yellow and off. This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  
- Strobe Cyan  
    - This function flashes the Blinkt! between cyan and off. This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  
- Strobe Orange  
    - This function flashes the Blinkt! between orange and off. This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  
- Strobe Pink  
    - This function flashes the Blinkt! between pink and off. This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  
- Strobe Purple  
    - This function flashes the Blinkt! between purple and off. This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  
- Strobe White (50% Brightness)  
    - This function flashes the Blinkt! between white at 50% brightness and off. This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  

### Flash
- Hazard 
    - This function flashes the Blinkt! between orange and off. This function emulates hazard lights. This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  
- Emergency  
    - This function flashes the Blinkt! between blue and off. This function emulates emergency lights. **Be aware: This function may be illegal to use in your jurisdiction. Please make sure to check the laws in your area before using this function. I do not take responsibility for any consequences of using this function!** This function is animated. **This function could cause seizures for people with photosensitive epilepsy.**  

### Pulse
- Pulse Colours  
    - This function pulses the Blinkt! between white, red, green, blue and off. This function is animated.  
- Pulse White  
    - This function pulses the Blinkt! between white and off. This function is animated.  
- Pulse Red  
    - This function pulses the Blinkt! between red and off. This function is animated.  
- Pulse Green  
    - This function pulses the Blinkt! between green and off. This function is animated.  
- Pulse Blue  
    - This function pulses the Blinkt! between blue and off. This function is animated.  
- Pulse Magenta  
    - This function pulses the Blinkt! between magenta and off. This function is animated.  
- Pulse Yellow  
    - This function pulses the Blinkt! between yellow and off. This function is animated.  
- Pulse Cyan  
    - This function pulses the Blinkt! between cyan and off. This function is animated.  
- Pulse Orange  
    - This function pulses the Blinkt! between orange and off. This function is animated.  
- Pulse Pink  
    - This function pulses the Blinkt! between pink and off. This function is animated.  
- Pulse Purple  
    - This function pulses the Blinkt! between purple and off. This function is animated.  
- Pulse White (50% Brightness)  
    - This function pulses the Blinkt! between white at 50% brightness and off. This function is animated.  

### Fade
- Fade Colours  
    - This function fades the Blinkt! between white, red, green, blue and off. This function is animated.  
- Fade White  
    - This function fades the Blinkt! between white and off. This function is animated.  
- Fade Red  
    - This function fades the Blinkt! between red and off. This function is animated.  
- Fade Green  
    - This function fades the Blinkt! between green and off. This function is animated.  
- Fade Blue  
    - This function fades the Blinkt! between blue and off. This function is animated.  
- Fade Magenta  
    - This function fades the Blinkt! between magenta and off. This function is animated.  
- Fade Yellow  
    - This function fades the Blinkt! between yellow and off. This function is animated.  
- Fade Cyan  
    - This function fades the Blinkt! between cyan and off. This function is animated.  
- Fade Orange  
    - This function fades the Blinkt! between orange and off. This function is animated.  
- Fade Pink  
    - This function fades the Blinkt! between pink and off. This function is animated.  
- Fade Purple  
    - This function fades the Blinkt! between purple and off. This function is animated.  
- Fade White (50% Brightness)  
    - This function fades the Blinkt! between white at 50% brightness and off. This function is animated.  

### Run
- Run Colours  
    - This function runs the LEDs on the Blinkt! between white, red, green and blue. This function is animated.  
- Run White  
    - This function runs the LEDs on the Blinkt! between white and off. This function is animated.  
- Run Red  
    - This function runs the LEDs on the Blinkt! between red and off. This function is animated. 
- Run Green  
    - This function runs the LEDs on the Blinkt! between green and off. This function is animated. 
- Run Blue  
    - This function runs the LEDs on the Blinkt! between blue and off. This function is animated. 
- Run Magenta 
    - This function runs the LEDs on the Blinkt! between magenta and off. This function is animated.  
- Run Yellow  
    - This function runs the LEDs on the Blinkt! between yellow and off. This function is animated. 
- Run Cyan  
    - This function runs the LEDs on the Blinkt! between cyan and off. This function is animated. 
- Run Orange  
    - This function runs the LEDs on the Blinkt! between orange and off. This function is animated. 
- Run Pink  
    - This function runs the LEDs on the Blinkt! between pink and off. This function is animated. 
- Run Purple  
    - This function runs the LEDs on the Blinkt! between purple and off. This function is animated. 
- Run White (50% Brightness)  
    - This function runs the LEDs on the Blinkt! between white at 50% brightness and off. This function is animated. 

### Misc
- Flash Colours  
    - This function slowly flashes the Blinkt! between red, green, blue and white. This function is animated.  
- Rainbow Gradient  
    - This function runs the Blinkt! through the entire colour spectrum. This function is animated. This function will only look right when the LEDs are shining at a surface.  
- Scroll Colours  
    - This function runs the Blinkt! through the entire colour spectrum including white. This function is animated. This function will only look right when the LEDs are shining at a surface.  
- Off  
    - This function turns all of the LEDs on the Blinkt! off.  

## Planned features
- [ ] Add a true random colour flash mode
- [ ] Add a true random colour scroll mode
- [ ] Add a safe shutdown button to the web app