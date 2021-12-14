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
   5. the relais
   6. (todo) maybe the On/Off switch needs to be placed here as well
1. the following lines can be changed to mock the mill to a LED. So that if the millButton will be pushed, the LED will be turned on until the grind process is done.
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
<img src="./pictures/E524C827-B731-4221-AC48-F4BE631F5D13.jpeg" width="240"><br>
<video src="./pictures/IMG_7143.MP4" controls="controls" style="max-width: 730px;">
</video>

To test the Relais LED you can also play a little and insert those lines:
in UI.H underneath line 110:
- static const unsigned char RELAY_PIN_LED = LED_BUILTIN;

in RUN.cpp begining from line 39:
void Run::startMill() { 
  digitalWrite(UI::RELAY_PIN, LOW); 
  digitalWrite(UI::RELAY_PIN_LED, HIGH);
}


void Run::stopMill() { 
  digitalWrite(UI::RELAY_PIN, HIGH); 
  digitalWrite(UI::RELAY_PIN_LED, LOW);
}

## Todo: add a demo with scale
