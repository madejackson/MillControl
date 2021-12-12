Here are some more details regarding the hardware rquirements

## Hardware Requirements
 1. Runs on Arduino Pro Mini 5V 328 & compatible systems (should be most arduino machines having a ATmega328 or better CPU, needs 32k of storage space).
    1. if you use the mini you need an extra USB adapter
    2. for beginners it will be easier to use the [ardunino nano](#arduino-nano)
 1. Needs a rotary encoder with a switch and an optional second switch (mill switch) and a third switch (mill switch 2). If you only have one switch comment out the defines in UI.h
    1. instead of an encoder it could also have 3 buttons (up/ down / enter)
 1. Display SSD1306 128*64 i2c OLED Display or SSD1306 128*64 spi OLED. They support landscape and portrait mode. comment out the orientation define in UI.h. If you use a bigger display have a look at U8Glib line 132 and comment this out (hopefully there is a comment ;))
 1. Relais modul for arduino 
 1. 5 V power adapter (an old smartphone power supply)
 1. on/off switch so that there is no Standby electricity
 1. a 220v ralais, SSR or similar if you wanr ro use the [brew timer](#brew-timer) (optional)
    1. (SSR High Trigger 2 Channel: 2 channel Solid State Relais Modul 5V/230VAC High Level Trigger)
 1. HX711 modul and scale (optional)
 1. maybe a solution for the [radio interference](https://www.kaffee-netz.de/threads/millcontrol-arduino-muehlensteuerung-mit-timer-gewichtsautomatik-waagensteuerung-und-brew-timer.95553/page-4#post-1195423)
 1. a mill to tune up
 1. a breadboard and those conectors (f/f, m/f, m/m). This will be perfect for practise and setting up everything before putting it into a box or inside the mill.


### Arduino nano<br>
it can look like the following. It was an arduino nano v.3.0<br>
![image](https://user-images.githubusercontent.com/34890799/145284843-4fe529c0-1051-4825-8ec8-2eaacccb000e.png)

rotary encoder looks like this<br>
![image](https://user-images.githubusercontent.com/34890799/145285020-498416d5-eab7-4b3c-8e87-2cabbbdf29e4.png)

or something like a pressure switch instead of the encoder:<br>
![image](https://user-images.githubusercontent.com/34890799/145287013-621ce4fb-a4a5-44fa-b752-3f7820fefc97.png)


the display<br>
![image](https://user-images.githubusercontent.com/34890799/145285123-17f468ed-b236-4961-86a2-b8260090c0ed.png)

the relais modul looks like:<br>
????

smartphone power supply<br>
????

on/off switch<br>
????

220v ralais, SSR or similar <br>
![image](https://user-images.githubusercontent.com/34890799/145286482-62b83085-e631-4d04-8187-5f53d836ddfb.png)

HX711 modul <br>
![image](https://user-images.githubusercontent.com/34890799/145285397-f87eb607-7a3a-40e7-8ed2-06a6d25cd435.png)

scale <br>
![image](https://user-images.githubusercontent.com/34890799/145287171-584127cf-df0f-4c8c-8d08-97e830e750fc.png)

solution for the radio interference<br>
check it out here: <br>
https://www.kaffee-netz.de/threads/millcontrol-arduino-muehlensteuerung-mit-timer-gewichtsautomatik-waagensteuerung-und-brew-timer.95553/page-4#post-1195423
 
breadboard and wires <br>
![image](https://user-images.githubusercontent.com/34890799/145288024-ebd61c2b-5a6f-4d62-abfa-12cfbffb5df2.png)

