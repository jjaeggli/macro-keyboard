# macro-keyboard / x-plane-pad

## Purpose

This is intended as the firmware for a USB macro or shortcut keyboard, or for a
gamepad input device. Actual usage may vary based on your specific use case. At
the core of the design is a keypad matrix supporting full simultaneous key
presses using only n x m pins. The mapping could be extended to a half or full
keyboard. The current functionality is limited to my specific use cases.

## Features

  * NKRO support when used with a compatible keyboard wiring.
  * Uses HID-Project for an exhaustive collection of keycodes.
  * A small example of using chords for alternate keycodes.

## Firmware

### macro-keyboard

The provided source supports a 2 x 5 keyboard configuration with my current
mapping for use with [Blender](http://www.blender.org), which is an incomplete
use of the available keys.

### x-plane-pad

The same 2 x 5 matrix support but instead controls gamepad buttons 1 through 10
as a HID gamepad, supporting full simultaneous press, hold, and release of all
buttons independently. Works with keyboard switches, but should also work with
any momentary or toggle switch.

## Hardware

The source is intended for use with an Arduino device which supports USB-HID.
Commonly the [Sparkfun Pro Micro](https://www.sparkfun.com/products/12640)
is used. Other cheaper devices are available which can be used in place of the
Pro Micro and should work with this source. I've used one such device, but have
found the serial port assignment on reset to be unreliable, and instead resort
to unpluging the USB connection when updating the firmware. Be sure to configure
the board type according to your device when compiling and uploading.

## References

* [Matrix Keyboard Wiring Guide](http://blog.komar.be/how-to-make-a-keyboard-the-matrix/)
* [Macro Keyboard Case (my design)](https://www.thingiverse.com/thing:2509293)
