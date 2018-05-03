/*
 Name:    macro-keyboard.ino
 Created: 5/18/2016 1:20:33 PM
 Author:  jjaeggli
*/

#include <Keypad.h>
#include <HID-Project.h>

const byte ROWS = 5; 
const byte COLS = 2;

const char MACRO_1 = '1';
const char MACRO_2 = '2';
const char MACRO_3 = '3';
const char MACRO_4 = '4';
const char MACRO_5 = '5';
const char MACRO_6 = '6';
const char MACRO_7 = '7';
const char MACRO_8 = '8';
const char MACRO_9 = '9';
const char ALT_FN = '0';

char keys[ROWS][COLS] = {
  { MACRO_1, MACRO_2},
  { MACRO_3, MACRO_4},
  { MACRO_5, MACRO_6},
  { MACRO_7, MACRO_8},
  { MACRO_9, ALT_FN}
};

byte rowPins[ROWS] = { 3, 4, 5, 6, 7 }; // Connect to the row pinouts of the keypad.
byte colPins[COLS] = { 8, 9 }; // Connect to the column pinouts of the keypad.

// Current alt-key state.
bool altKeyPressed = false;

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {
  // Fills kpd.key[ ] array with up-to 10 active keys.
  // Returns true if there are ANY active keys.
  if (keypad.getKeys())
  {
    for (int i=0; i < LIST_MAX; i++)  // Scan the whole key list.
    {
      if (keypad.key[i].stateChanged)  // Only find keys that have changed state.
      {
        String msg;
        char kchar = keypad.key[i].kchar;
        switch (keypad.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
          case PRESSED:
            handleKeyPress(kchar);
            msg = " PRESSED.";
            break;
          case HOLD:
            msg = " HOLD.";
            break;
          case RELEASED:
            handleKeyRelease(kchar);
            msg = " RELEASED.";
            break;
          case IDLE:
            msg = " IDLE.";
          }
          Serial.print("Key ");
          Serial.print(kchar);
          Serial.println(msg);
      }
    }
  }
}

/// Handles a key press.
void handleKeyPress(char key) {
  switch (key) {
    case MACRO_1:
      pressLockScreen();
      delay(10);
      Keyboard.releaseAll();
      break;
    case MACRO_5:
      pressBlenderTopBottom();
      delay(10);
      Keyboard.releaseAll();
      break;
    case MACRO_6:  
      pressBlenderPerspectiveOrtho();
      delay(10);
      Keyboard.releaseAll();
      break;
    case MACRO_7:
      pressBlenderLeftRight();
      delay(10);
      Keyboard.releaseAll();
      break;
    case MACRO_8:
      pressBlenderFrontBack();
      delay(10);
      Keyboard.releaseAll();
      break;
    case ALT_FN:
      altKeyPressed = true;
      break;
    default:  
      Keyboard.write(key);
      delay(10);
      Keyboard.releaseAll();
  }
}

/// Handles a key release.
void handleKeyRelease(char key) {
  if (key == ALT_FN)
  {
    altKeyPressed = false;  
  }  
}

// Lock screen macro
void pressLockScreen() {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press('l');
}

// TODO(jjaeggli): For single keyboard keypress functions, use a matrix for keyboard mapping.

// Blender top / bottom viewport macro
void pressBlenderTopBottom() {
  // Blender top / bottom
  if (altKeyPressed) {
    Keyboard.press(KEY_LEFT_CTRL);
  }
  Keyboard.press(KEYPAD_7);
}

// Blender left / right viewport macro
void pressBlenderLeftRight() {
  // Blender right / left view
  if (altKeyPressed) {
    Keyboard.press(KEY_LEFT_CTRL);
  }
  Keyboard.press(KEYPAD_3);
}

// Blender front / back viewport macro
void pressBlenderFrontBack() {
  // Blender front view
  if (altKeyPressed) {
    Keyboard.press(KEY_LEFT_CTRL);
  }
  Keyboard.press(KEYPAD_1);
}

// Blender perspective / ortho viewport macro
void pressBlenderPerspectiveOrtho() {
  // Blender perspective / ortho
  Keyboard.press(KEYPAD_5);
}

// Volume down keypress
void pressVolumeDown() {
  Keyboard.press(KEY_VOLUME_DOWN);
}

// Volume up keypress
void pressVolumeUp() {
  Keyboard.press(KEY_VOLUME_UP);
}

