# Using the arduino IDE
In this section I will describe step by step how to get the arduino project from GitHub on to your Arduino Nano. Using the arduino IDE.

## Should work with Linux, Windows and Mac (confirmed with Linux + Windows)

1. download and install Arduino IDE
   1. I recommend V2: [Installation Guide](https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing)
2. clone the project from github
   1. I recommend using Github Desktop, which conveniently shows you the changes you made.
3. open the File Millcontrol/Millcontrol.ino in the created Folder with Arduino IDE (should be default if installed correctly)
4. Install Libraries
   1. Select Sketch->Include Library->Manage Libraries
   2. select and install U8glib
   3. Download encoder library + TimerOne library (see Dependencies) (recommended way: Download the ZIP's from Github)
   4. Select Sketch->Include Library->add .ZIP-Library
   5. select and install both downloaded zip files / libraries.
5. connect the arduino
6. choose your arduino and the coorect bootloader (For me it was Arduino nano with Processor ... Old bootloader)
   1. Depending on the Arduino and on the OS you may need to install CH341-Drivers. On Linux, I had to uninstall BRLTTY as well for successfull connection.
7. depending on the relais (high or low trigger) you need to adjust the settings (see below [Config changes for the relais](#config-changes-for-the-relais))
8. for the arduino nano you will need to change some configurations (see below [Config changes for the arduino nano](#config-changes-for-the-arduino-nano))
9. depending on the display i2c or spi you need to adjust the settings (see below [Config changes for the display](#config-changes-for-the-display))
10. click on verify and then upload
   1. Verify should spit out some white text info about used memory and ram.
11. after flash is complete you should see the first screen on the display of the arduino nano


## Config changes for the arduino nano
The values for the PINs can be found here [demoSetup.md](./demoSetup.md)
```
- MillControll.ino line 65: Rotator *UI::rotator = new RotatingEncoder(<CLK Pin>, <DT PIN>); 
- MillControll.ino line 77: ENCODER_BUTTON <SW PIN> 
- in UI.h line 32: Mill_Button = <Taster Signal PIN>
- in UI.h line 36: comment out
- in UI.h line 109: Relais Pin = <Relais Signal PIN>
```

## Config changes for the relais
Depending on the used relay you may need to change following lines. My Relais triggers on High signal so I had to change:
```
- Run.cpp line 7: digitalWrite(UI::RELAY_PIN, **HIGH**); to digitalWrite(UI::RELAY_PIN, **LOW**);
- Run.cpp line 39: void Run::startMill() { digitalWrite(UI::RELAY_PIN, **LOW**); } to void Run::startMill() { digitalWrite(UI::RELAY_PIN, **HIGH**); }
- Run.cpp line 41: void Run::stopMill() { digitalWrite(UI::RELAY_PIN, **HIGH**); } to void Run::stopMill() { digitalWrite(UI::RELAY_PIN, **LOW**); }
```

## Config changes for the display
The values for the PINs can be found here [demoSetup.md](./demoSetup.md)
- depending on i2c or SPI you need to change some values (lines 141 and further). The default values should still work. If not we proably need to update the U8GLib
- if you use i2c, verify if the lines 115 - 123 (SPI - BUS) are comented out.
- display pins do not need to be set, because they are standard. You can take them from the schematic view or the [demoSetup.md](./demoSetup.md)