Here are some more details regarding the hardware rquirements

## Hardware Requirements
 1. Runs on Arduino Pro Mini 5V 328 & compatible systems (should be most arduino machines having a ATmega328 or better CPU, needs 32k of storage space).
    1. if you use the mini you need an extra USB adapter
    2. for beginners it will be easier to use the [ardunino nano](#arduino-nano)
 1. [Rotary Encoder](#rotary-encoder) (e.g. ky 040) with a switch 
    1. instead of an encoder it could also have 3 buttons (up/ down / enter). With 3 buttons you will need more space and more wires to connect
 1. [Display](#display): SSD1306 128x64 i2c OLED or SSD1306 128x64 spi OLED.
    1. They support landscape and portrait mode. Comment out the orientation define in UI.h. If you use a bigger display have a look at U8Glib line 132 and comment this out (hopefully there is a comment ;))
 4. 5 V power adapter (an old smartphone power supply). To power up the arduino. Right now I am not sure how to connect the arduino directly to the power supply, because the power seems to be to much for the arduino.
 6. [Relais modul](#the-relais-modul-looks-like-this) for arduino (Relais 5V KY-019 Modul High-Level-Trigger)
 9. maybe a solution for the [radio interference](https://www.kaffee-netz.de/threads/millcontrol-arduino-muehlensteuerung-mit-timer-gewichtsautomatik-waagensteuerung-und-brew-timer.95553/page-4#post-1195423)
 10. a mill to tune up
 11. a [breadboard and those conectors](#breadboard-and-wires) (f/f, m/f, m/m). This will be perfect for practising and setting up everything before putting it into a box or inside the mill.
 12. a LED will be good for beginners to do some testing
     1. recomanding a RGB LED which gives you more options when it comes to the rotary encoder
     2. RGB Led KY-016
 1. (optional) an optional second switch (mill switch) and a third switch (mill switch 2). If you only have one switch comment out the defines in UI.h
 2. (optional) on/off switch so that there is no standby electricity
 3. (optional) a 220v ralais, SSR or similar if you want to use the [brew timer](#brew-timer) 
    1. (SSR High Trigger 2 Channel: 2 channel Solid State Relais Modul 5V/230VAC High Level Trigger)
 8. (optional) HX711 modul and scale 


### Arduino nano<br>
it can look like the following. It was an arduino nano v.3.0<br>
![image](https://user-images.githubusercontent.com/34890799/145284843-4fe529c0-1051-4825-8ec8-2eaacccb000e.png)

### rotary encoder<br>
![image](https://user-images.githubusercontent.com/34890799/145285020-498416d5-eab7-4b3c-8e87-2cabbbdf29e4.png)

or something like a pressure switch instead of the encoder:<br>
![image](https://user-images.githubusercontent.com/34890799/145287013-621ce4fb-a4a5-44fa-b752-3f7820fefc97.png)


### display<br>
![image](https://user-images.githubusercontent.com/34890799/145285123-17f468ed-b236-4961-86a2-b8260090c0ed.png)

### the relais modul looks like this:<br>
Relais modul for arduino (Relais 5V KY-019 Modul High-Level-Trigger)<br>
<img width="123" alt="Bildschirmfoto 2021-12-15 um 23 38 03" src="https://user-images.githubusercontent.com/34890799/146275751-73394dca-9f47-4d88-9a0c-60f720c1cf25.png">

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
 
### breadboard and wires<br>
![image](https://user-images.githubusercontent.com/34890799/145288024-ebd61c2b-5a6f-4d62-abfa-12cfbffb5df2.png)

