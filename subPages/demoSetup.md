## This describes how to set up the demo without the scale
Instead of the mill we will use use (LED or) the buildin LED

It will looke like this:

- (todo) fritzing picture
- (todo) real picture

1. the project must be inside a IDE (like described in the arduinoWebEditor.md (link needs to be added)
2. set up the components on the breadboard
   1. Arduino
   2. Taster
   3. display
   4. rotary encoder
   5. (todo) maybe the On/Off switch needs to be placed here as well
   6. (todo) place the relais somewhere
1. the following lines can be changed to mock the mill/relais to a LED. So that if the millButton will be pushed, the LED will be turned on until the grind process is done.
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
4. no you can get some experience with the display and the buttons
5. work in progress but the first running demo looks like this<br>
<img src="./pictures/IMG_7137.jpg" width="240"> 


## Todo: add a demo with scale
