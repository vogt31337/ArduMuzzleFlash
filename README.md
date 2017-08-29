# ArduMuzzleFlash
Arduino / attiny85 based muzzleflash for AirSoft using Neopixel

# ATTiny85 and Arduino
As this project is using an attiny85, for it's small size and price, a library is needed for Arduino.
It uses FastLED, which in turn uses yield().
Yield() isn't compatible with nearly all attiny85 libs out there except for this one:
https://raw.githubusercontent.com/damellis/attiny/ide-1.6.x-boards-manager/package_damellis_attiny_index.json

# Schematic
Soon to be released, when I figured out fritzing...
Use a digispark (or compatible) and attach the LEDs to P0.
For triggering the muzzleflash use a high level on P1 (for example through a light barrier).

# Update
Will soon enable to use the other pins to activate the muzzleflash as a flashlight.
