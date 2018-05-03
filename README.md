# macro-keyboard

## Purpose

This is intended as the firmware for a USB macro or shortcut keyboard. Actual
usage may vary based on your specific use case. The mapping could be extended to
a game pad, half, or full keyboard. The current functionality is limited to my
specific use case.

## Features

  * NKRO support when used with a compatible keyboard wiring.
  * Uses HID-Project for an exhaustive collection of keycodes.
  * A small example of using chords for alternate keycodes.

## Firmware

The provided source supports a 2 x 5 keyboard configuration with my current
mapping for use with [Blender](http://www.blender.org), which is an incomplete
use of the available keys.

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
