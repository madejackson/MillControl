# Using the arduino WebEditor
In this section I will describe step by step how to get the arduino project from GitHub on to your Arduino Nano. Using the arduino webeditor.
Note: the free plan has only 200s of compilation time a day. During my experiments I ran out of compilation time sometimes. In that case a local installation will be better or just wait a day ;)

## Mac (windows will be similar I guess)

1. download the project from the master
   1. <img src="./pictures/Bildschirmfoto 2021-12-13 um 14.42.34.png" width="480">
3. transform the "millControl" folder into a ZIP file
   1. <img src="./pictures/Bildschirmfoto 2021-12-13 um 14.43.00.png" width="240">
4. open the WebEditor on arduino.cc
5. connect the arduino
6. choose your arduino and the coorect bootloader (I did it by try and error)
7. go to sketchbook
8. click import
9. choose the "millControl.zip" file and upload it
   1. during the import it will tell you that some of the folder's XYZ files do not contain something. You can accept it.
10. for the arduino nano you will need to change some configurations (see below [Config changes for the arduino nano](#config-changes-for-the-arduino-nano))
11. depending on the display i2c or spi you need to adjust the settings (see below [Config changes for the display](#config-changes-for-the-display))
12. select "MillControll.ino" from the tab in the WebEditor on arduino.cc
13. click on verify and save
14. it should say "Success: ...."
    1. If you imported only the "MillControll.ino" file, you will get a bunch of errors during "verify and save" because of missing files
15. connect the arduino
16. make sure that "MillControll.ino" is still selected from the tab
17. hit the upload and save button
18. after flash is complete you should see the first screen on the display of the arduino nano


## Config changes for the arduino nano
The values for the PINs can be found here [demoSetup.md](./demoSetup.md)
```
- MillControll.ino line 65: Rotator *UI::rotator = new RotatingEncoder(<CLK Pin>, <DT PIN>); 
- MillControll.ino line 77: ENCODER_BUTTON <SW PIN> 
- in UI.h line 32: Mill_Button = <Taster Signal PIN>
- in UI.h line 36: comment out
- in UI.h line 109: Relais Pin = <Relais Signal PIN>
```

## Config changes for the display
The values for the PINs can be found here [demoSetup.md](./demoSetup.md)
- depending on i2c or SPI you need to change some values (lines 141 and further). The default values should still work. If not we proably need to update the U8GLib
- if you use i2c, verify if the lines 115 - 123 (SPI - BUS) are comented out.
- display pins do not need to be set, because they are standard. You can take them from the schematic view or the [demoSetup.md](./demoSetup.md)

