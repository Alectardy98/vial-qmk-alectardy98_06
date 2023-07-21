# Set 2, PS/2 122

A converter for the a PS/2 (DIN-5) keyboard (scan code set 2) with a Serial (DE-9) mouse (Microsoft protocol).

Keyboard Maintainer: [MMcM](https://github.com/MMcM) 
Code baised on MMcm PS2 Serial Mouse Converter 
Hardware Supported: PS2 Keyboards 

Make example for this keyboard (after setting up your build environment):

    make converter/set2

The DIN-5 keyboard connector has Data on D0 and Clock on D1.

The serial port needs an RS-232 level shifter like a MAX232 and is then connected to RXD1 (D2) and TXD1 (D3).

RTS and DTR also need to be set, since that is how the mouse gets power. RTS can be wired to Vs+ from the MAX232 and DTS to the second transmit line, controlled by GPIO C6.
