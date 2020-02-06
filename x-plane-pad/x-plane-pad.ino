/*
 Name:    x-plane-pad.ino
 Created: 2/4/2020
 Author:  jjaeggli
*/

#include <Keypad.h>
#include <HID-Project.h>

const byte ROWS = 5;
const byte COLS = 2;

uint8_t keys[ROWS][COLS] = {
  { 1, 6},
  { 2, 7},
  { 3, 8},
  { 4, 9},
  { 5, 10}
};

byte rowPins[ROWS] = { 3, 4, 5, 6, 7 }; // Connect to the row pinouts of the keypad.
byte colPins[COLS] = { 8, 9 }; // Connect to the column pinouts of the keypad.

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  Gamepad.begin();
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
        uint8_t button = keypad.key[i].kchar;
        // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
        switch (keypad.key[i].kstate) {
          case PRESSED:
            Gamepad.press(button);
            msg = " PRESSED.";
            break;
          case HOLD:
            msg = " HOLD.";
            break;
          case RELEASED:
            Gamepad.release(button);
            msg = " RELEASED.";
            break;
          case IDLE:
            msg = " IDLE.";
        }
        Serial.print("Key ");
        Serial.print(button);
        Serial.println(msg);
        Gamepad.write();
      }
    }
  }
}
