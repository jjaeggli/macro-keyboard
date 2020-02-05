/*
 Name:    x-plane-pad.ino
 Created: 2/4/2020
 Author:  jjaeggli
*/

#include <Keypad.h>
#include <HID-Project.h>

const byte ROWS = 5;
const byte COLS = 2;

const char ALT_FN = 0;

char keys[ROWS][COLS] = {
  { 0, 5},
  { 1, 6},
  { 2, 7},
  { 3, 8},
  { 4, 9}
};

// By default, not mapped to any controls in X-Plane 11.
KeyboardKeycode mapping[] = {
  KEYPAD_1,
  KEYPAD_3,
  KEYPAD_5,
  KEYPAD_7,
  KEYPAD_9
};

byte rowPins[ROWS] = { 3, 4, 5, 6, 7 }; // Connect to the row pinouts of the keypad.
byte colPins[COLS] = { 8, 9 }; // Connect to the column pinouts of the keypad.

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
    // Scan the whole key list.
    for (int i=0; i < LIST_MAX; i++)
    {
      // Only find keys that have changed state.
      if (keypad.key[i].stateChanged)
      {
        String msg;
        KeyboardKeycode kchar = keypad.key[i].kchar;
        // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
        switch (keypad.key[i].kstate) {
          case PRESSED:
            handleKeyPress(kchar);
            msg = " PRESSED.";
            break;
          case HOLD:
            msg = " HOLD.";
            break;
          case RELEASED:
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

// Handles a key press. Produces either a mapped KeyboardKeycode keypress or
// KEY_LEFT_SHIFT + mapped key keypresses.
void handleKeyPress(char key) {
  KeyboardKeycode keyCode = mapping[key];
  if (key > 4) {
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.press(mapping[key - 5]);
  } else {
    Keyboard.press(mapping[key]);
  }
  delay(10);
  Keyboard.releaseAll();
}
