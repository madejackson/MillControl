# Using the arduino WebEditor
13.12.2021: Work in progress
- screenshots will be added later. There are availabel under Subpages -> pictures

In this section I will describe step by step how to get the arduino project from GitHub on to your arduino Nano. Using the arduino webeditor.
Note: the free Plan has only 200s of compilation time a day. During my experiments I ran out of time. In that case a local installation will be better.

## Mac (windows will be similar I guess)

1. download the project from the master
1. transform the "millControl" folder into a ZIP file
1. open the WebEditor on arduino.cc
1. go to sketchbook
1. click import
1. choose the "millControl.zip" file and upload it
    1. during the import it will tell you that some of the folder XYZ file do not contain something. You can accept it.
1. in case you are using an arduino nano you will need to change some configurations (see below)
1. depending on the display i2c or spi you need to adjust the settings (see below)
1. select "MillControll.ino" from the tab
2. click on verify and save
3. it should say "Success: ...."
   1. If you imported only the "MillControll.ino" file you will get a bunch of errors because of missing files
4. make sure that "MillControll.ino" is still selected from the tab
5. hit the upload and save button
6. after flash is complete you should see the first screen on the display of the arduino nano


## Config changes for the arduino nano
- MillControll.ino line 65: Rotator *UI::rotator = new RotatingEncoder(11, 10); 
- MillControll.ino line 77: ENCODER_BUTTON 9 
- in UI.h line 32: Mill_Button = 12
- in UI.h line 36: comment out

## Config changes for the display
- depening on i2c or SPI you need to change some values (lines 141 and further). The default values should still work. If not we proably need to update the U8GLib
- if you use i2c, verify if the lines 115 - 123 (SPI - BUS) are comented out.
- display pins do not need to be set, because they are standard. You can take them from the schematic view

