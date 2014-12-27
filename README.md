FlightControls
==============

Basic hardware flight controller for Elite Dangerous (for Arduino)

 This MUST be used with an Arduino compatible with the 
 USB HID library (Leonardo, or any 32u4 chipset.. possibly others)

 See: http://i.imgur.com/ilhbTcL.jpg

 Left to Right; the Switches 1 to 4 are toggle type, and
 the two buttons are marked red and black.

 Wiring:
 Toggle 1 (Lights) - Digital 7
 Toggle 2 (Cargo Scoop) - Digital 6
 Toggle 3 (Landing Gear) - Digital 5
 Toggle 4 (Throttle 100% when up, 75% when down) - Digital 4
 Red Button (Full Stop / 0% Throttle) - Digital 3
 Black Button (Jump / Cruise) - Digital 2
 
 Wire switches so they are active when switched to GND
 
 Key Bindings Required:
 Lights - 'B'
 Cargo Scoop - 'HOME' (Default)
 Landing Gear - 'L' (Default)
 Throttle 100% - 'I'
 Throttle 75% - 'K'
 Full Stop - 'X' (Default)
 Jump - 'J' (Default)