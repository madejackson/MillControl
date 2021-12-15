## This describes how to set up the demo without the scale
Instead of the mill we will use the buildin LED from the arduino or a LED.

It will looke like this:

- (todo) fritzing picture
- (todo) real picture

1. the project must be inside an IDE (like described in the [WebEditor](./arduinoWebEditor.md))
2. set up the components on the breadboard
   1. Arduino
   2. Taster
   3. display
   4. rotary encoder
   5. the relais
   6. (todo) maybe the On/Off switch needs to be placed here as well
1. the following lines can be changed to mock the mill. Instead of the mill we will use our LED. So that if the millButton will be pushed, the LED will be turned on until the grind process is done.
   1. in UI.h the line 110
      1. from: static const unsigned char RELAY_PIN = 7; 
      2. to: static const unsigned char RELAY_PIN = LED_BUILTIN;
   3. in RUN.cpp line 39
      1. from: void Run::startMill() { digitalWrite(UI::RELAY_PIN, LOW); }
      2. to: void Run::startMill() { digitalWrite(UI::RELAY_PIN, HIGH); } 
   5. in RUN.cpp line 41
      1. from: void Run::stopMill() { digitalWrite(UI::RELAY_PIN, HIGH); }
      2. to: void Run::stopMill() { digitalWrite(UI::RELAY_PIN, LOW); } 
3. deploy everything on the arduino
4. now you can get some experience with the display and the buttons
5. the first running demo looks like this<br>
6. <img src="./pictures/IMG_7137.jpg" width="240"><br>
7. Next we will insert the relais into the breadbord. Therefore you will need to change some lines again:
   1. in UI.h replace the line 110
      1. from: static const unsigned char RELAY_PIN = LED_BUILTIN;
      2. to: 
         1. static const unsigned char RELAY_PIN = 8;
         1. static const unsigned char RELAY_PIN_LED = LED_BUILTIN;
   1. in RUN.cpp replace line 39 to 42 (todo needs to checked again)
   ```
   void Run::startMill() { 
   digitalWrite(UI::RELAY_PIN, LOW); 
   digitalWrite(UI::RELAY_PIN_LED, HIGH);
   }

   void Run::stopMill() { 
   digitalWrite(UI::RELAY_PIN, HIGH); 
   digitalWrite(UI::RELAY_PIN_LED, LOW);
   }
   ```
1. with the relais it looks like this<br>
<img src="./pictures/E524C827-B731-4221-AC48-F4BE631F5D13.jpeg" width="240"><br>
1. the last step would be to hock up something on the relais. E.g. a lamp or something with an external powersupply. So that we can test if the relais and the programm works as designed.
   1. I connected the kitchen lamp. Doesn't looks so save but works and it does the job

## Todo: add a demo with scale
