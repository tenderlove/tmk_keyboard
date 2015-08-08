Atreus keyboard firmware
======================

The [Atreus](http://atreus.technomancy.us) is a 40% column-staggered
ergo keyboard.

This version is intended for use with the newer PCB-based designs that
use the A-Star Micro controller. If you have an older Teensy-based
one, try the `atreus-teensy2` tag.

The TMK firmware is more featureful than the default
[Atreus firmware](https://github.com/technomancy/atreus-firmware),
however it is much more complex, doesn't work with low-voltage
laptops, and makes specifying shifted key combos more difficult.

Run `make` to compile a .hex file that you can upload using `avrdude`.

The only layout currently supplied is "softdvorak" which sends
keycodes assuming the OS will perform QWERTY->Dvorak translation.
Patches welcome for additional layouts.
