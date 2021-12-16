For Arduino beginners I would recommend the following to get started with all of this.

## Get to know the arduino
1. Read through the full project. If you are settisfied with the project, go ahead and buy all the required hardware components (see list [here](HardwareRequirements.md))
   - the breadbord and the LEDs will be really good to start with. Those are easy componets which will help you to lern a bit more about the arduino and get first hands on the project.
2. learn how the breadboard works. You will need a basic understanding.
   - google for: breadboard arduino function
   - you will find some youtube videos and articles which explain everything quite good
   - if you want to know how to power your breadboard with the arduino search for: power breadboard with arduino nano
3. get familiar with your arduino by checking out this page: https://www.arduino.cc
   - you can do some experiments there as well.
   - e.g. make the ordered LED blink
4. If you are familiar with your arduino and you know how you can power up the breadboard, how to bring code to your arduino and how the wireing works. I would say you can go on with this "mill project".

## Bring the display to live

setting up the display<br>
<img width="817" alt="Bildschirmfoto 2021-12-12 um 21 25 43" src="https://user-images.githubusercontent.com/34890799/145728445-7ffa7f8d-387d-4550-94be-1ed47498e444.png"><br>
- 3v3 -> VCC
- A4 -> SDA
- A5 -> SCL
- GND -> GND
Pictrues is available under assets - pictures - beginners<br>
https://www.youtube.com/watch?v=PfGUz6wkbeI

Hello world with U8GLib and the following object, worked
- U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE|U8G_I2C_OPT_DEV_0);	// I2C / TWI 

## Bring other components to live

If you are a little lost with the taster, with the rotary encoder, etc. I would advice to search on google for the name of the component and "setup arduino nano":
- e.g.: for the roatry encoder: ky 040 setup arduino nano
- e.g.: for the taster: ky 004 setup arduino nano
