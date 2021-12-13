13.12.2021: Work in progress
- screenshots will be added later

In this section I will describe step by step how to get the arduino project from GitHub to you arduino.

Mac (windows will be similar I guess)

1. Download the project from the master
1. transform the "millControl" folder into a ZIP file
1. open the WebEditor on arduino.cc
1. go to sketchbook
1. click import
   1. during the import it will tell you that some of the filder of no XYZ file. You can accept it.
1. choose the "millControl.zip" File and upload it
1. click on verify and save
1. it should say "Success: ...."
   1. If you import only the "MillControll.ino" file you will get a bunch of errors because of missing files
1. in case you are using a arduino nano you will need to change some configurations (see below)


## Config changes for the arduino nano
- MillControll.ino line 65: Rotator *UI::rotator = new RotatingEncoder(11, 10); 
- MillControll.ino line 77: ENCODER_BUTTON 9 
- in UI.h line 32: Mill_Button = 12
- in UI.h line 36: comment out

Display pins müssen noch gesetzt werden
