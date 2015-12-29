#include "MillControl.h"

bool Editor::start() {
    timeMode = &MillControl::TIME_MODE_SELECTOR.getMode();
    timeModes = &MillControl::TIME_MODE_SELECTOR.getTimeModes();

    firstChar = TimeMode::DATA_PER_MODE + (timeMode->weightMode ? 1 : 0);

    const int size = MillControl::TIME_MODE_SELECTOR.size();

    back = firstChar++;

    if (!deleteMode)
        gram = firstChar++;
    else
        gram = 0;

    if (size < TimeModeList::MAX_MODES && !deleteMode)
        add = firstChar++;
    else
        add = 0;

    if (size > 1)
        del = firstChar++;
    else
        del = 0;


    if (size > 2 && !deleteMode) {
        left = firstChar++;
        right = firstChar++;
    } else {
        left = 0;
        right = 0;
    }

    if (deleteMode)
        setEncoderMode(2, 0);
    else
        setEncoderMode(firstChar + TimeMode::MAX_CHARS, position);

    //if there is not mill button i need a multi click button in the gram editor
#ifndef MILL_BUTTON
    if(timeMode->weightMode)
        UI::encoderButton.setMultiClickButton();
    else
        UI::encoderButton.setSingleClickButton();
#endif
    return true;
}

void Editor::stop() {
}

int *Editor::getTime() {
    if (timeMode->weightMode) if (position == 0)
        return &timeMode->centiSecondsPerGram;
    else
        return &timeMode->data[position - 1];
    else
        return &timeMode->data[position];
}

char *Editor::getChar() {
    return &timeMode->name[position - firstChar];
}


void Editor::encoderClick() {
    if (position < back) {
        MillControl::open(MillControl::TIME_EDITOR);
        return;
    } else if (position == back) {
        if (deleteMode) {
            deleteMode = false;
        } else {
            timeModes->eepromWrite();
            close();
            return;
        }
        position = 0;
    } else if (position == gram) {
        timeMode->setWeightMode(!timeMode->weightMode);
        position = 0;
    } else if (position == add) {
        MillControl::TIME_MODE_SELECTOR.setMode(&timeModes->insertAfer(*timeMode));
        position = 0;
    } else if (position == left) {
        MillControl::TIME_MODE_SELECTOR.setMode(&timeModes->moveLeft(*timeMode));
        position = back;
    } else if (position == right) {
        MillControl::TIME_MODE_SELECTOR.setMode(&timeModes->moveRight(*timeMode));
        position = back;
    } else if (position == del) {
        if (deleteMode) {
            MillControl::TIME_MODE_SELECTOR.setMode(&timeModes->del(*timeMode));
            position = 0;
            deleteMode = false;
            close();
            return;
        } else {
            deleteMode = true;
        }
    } else if (position >= firstChar) {
        MillControl::open(MillControl::CHAR_EDITOR);
        return;
    }
    start();
    redraw();
}

//In Weight Mode encoder click starts the calibration mode
void Editor::millClick(unsigned char i) {
    if(timeMode->weightMode)
        MillControl::open(MillControl::WEIGHT_CALIBRATOR);
#ifndef MILL_BUTTON
    else
        encoderClick();
#endif
}


void Editor::encoderChanged(int encoderPos) {
    position = (deleteMode ? back : 0) + encoderPos;
    redraw();
}


void Editor::draw() {
    draw(false);
}

void Editor::drawEditor() {
    draw(true);
}

void Editor::draw(bool editor) {
    State::draw();
    unsigned char weightMode = timeMode->weightMode ? 1 : 0;
    for (char t = -weightMode; t < TimeMode::DATA_PER_MODE; t++) {

        const char pos = t + weightMode;
        
#ifdef PORTRAIT_DISPLAY
        unsigned char x = 0;
#ifdef MILL_BUTTON
        const bool small = false;
        unsigned char y = weightMode ? (UI::LINE_HEIGHT + UI::SMALL_LINE_HEIGHT + ((UI::DISPLAY_HEIGHT - UI::LINE_HEIGHT - (UI::SMALL_LINE_HEIGHT * 5)) * 2 / 10) + (((UI::DISPLAY_HEIGHT - UI::LINE_HEIGHT - (UI::SMALL_LINE_HEIGHT * 5)) * 2 / 10) + UI::SMALL_LINE_HEIGHT) * pos)
                                     : (UI::LINE_HEIGHT * 2  + ((UI::DISPLAY_HEIGHT - UI::SMALL_LINE_HEIGHT - (UI::LINE_HEIGHT * 5)) * 3 / 8) + (((UI::DISPLAY_HEIGHT - (UI::LINE_HEIGHT * 5)) * 2 / 8) + UI::LINE_HEIGHT) * pos );   //52 + line*32#endif
#else
        const bool small = false;
        unsigned char y = UI::LINE_HEIGHT *2  + ((UI::DISPLAY_HEIGHT - (UI::LINE_HEIGHT * 5)) * 3 / 8) + (((UI::DISPLAY_HEIGHT - (UI::LINE_HEIGHT * 5)) * 2 / 8) + UI::LINE_HEIGHT) * pos;   //52 + line*32#endif
#endif
#else
        unsigned char x = UI::LINE_HEIGHT*2;
#ifdef MILL_BUTTON
        const bool small = weightMode;
        const unsigned char y = weightMode ? (((UI::DISPLAY_HEIGHT- (UI::SMALL_LINE_HEIGHT * 4)) / 8) + UI::SMALL_LINE_HEIGHT  + (((UI::DISPLAY_HEIGHT- (UI::SMALL_LINE_HEIGHT  *4)) / 4) + UI::SMALL_LINE_HEIGHT  ) * pos) :
                                             (((UI::DISPLAY_HEIGHT- (UI::LINE_HEIGHT * 3)) / 6) + UI::LINE_HEIGHT + (((UI::DISPLAY_HEIGHT- (UI::LINE_HEIGHT *3)) / 3) + UI::LINE_HEIGHT ) * pos); //small ? (13 + pos * 16) : (16 + t * 22);
#else
        const bool small = false;
        const unsigned char y = weightMode ? (((UI::DISPLAY_HEIGHT - (UI::LINE_HEIGHT * 3)) / 6) + UI::LINE_HEIGHT + (((UI::DISPLAY_HEIGHT- (UI::LINE_HEIGHT *3)) / 3) + UI::LINE_HEIGHT ) * pos) :
                                             (((UI::DISPLAY_HEIGHT - (UI::LINE_HEIGHT * 2)) / 4) + UI::LINE_HEIGHT + (((UI::DISPLAY_HEIGHT- (UI::LINE_HEIGHT *2)) / 2) + UI::LINE_HEIGHT ) * pos); // y = weightMode ? (15 + pos * 22) : (23 + pos * 32);
#endif
#endif
        const int data = (t == -1) ? timeMode->centiSecondsPerGram : timeMode->data[t];

        UI::drawTimeLine(t, data, y, x, weightMode, small, position == pos, editor);
    }

    UI::u8g.setFont(UI::FONT_SMALL);
    
    drawEditPoint(0, back, 0);

    if (gram)
        drawEditPoint(1, gram, weightMode ? "s" : "g");

    if (add)
        drawEditPoint(2, add, UI::ADD_STRING);

    if (del)
        drawEditPoint(3, del, UI::DEL_STRING);

    if (left)
        drawEditPoint(4, left, UI::MOVE_LEFT_STRING);

    if (right)
        drawEditPoint(5, right, UI::MOVE_RIGHT_STRING);

    if (position >= firstChar) {
        UI::u8g.setFont(UI::FONT_REGULAR);
        char charBuf[TimeMode::MAX_CHARS + 1];

        const int i = position - firstChar;
        memcpy(charBuf, &timeMode->name, i + 1);
        charBuf[i + 1] = 0;

        unsigned char w = UI::u8g.getStrWidth(&charBuf[i]);

        charBuf[i] = 0;
        unsigned char x = UI::u8g.getStrWidth(charBuf);

#ifdef PORTRAIT_DISPLAY
        UI::u8g.drawHLine(x, UI::LINE_HEIGHT + UI::BORDER_WIDTH, w);
        if (editor)
            UI::u8g.drawHLine(x, UI::LINE_HEIGHT + UI::BORDER_WIDTH + 2, w);
#else
        UI::u8g.drawVLine(UI::LINE_HEIGHT + UI::BORDER_WIDTH, UI::DISPLAY_HEIGHT - x - w, w);
        if (editor)
            UI::u8g.drawVLine(UI::LINE_HEIGHT + UI::BORDER_WIDTH + 2, UI::DISPLAY_HEIGHT - x - w, w);
#endif
    }
}

void Editor::drawEditPoint(const unsigned char p, const unsigned char pos, const char *symbol) const {
    UI::drawEditPoint(p, pos == position, symbol);
};


