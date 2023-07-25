# PS/2 keyboard 

A converter for the a PS/2 (DIN-5) keyboard (scan code set 2) with a Serial (DE-9) mouse (Microsoft protocol).

Keyboard Maintainer: [Alectardy98](https://github.com/alectardy98)  

Make example for this keyboard (after setting up your build environment):

    make converter/set2/32u4:default

The DIN-5 keyboard connector has Data on D0 and Clock on D1.

The serial port needs an RS-232 level shifter like a MAX232 and is then connected to RXD1 (D2) and TXD1 (D3).

RTS and DTR also need to be set, since that is how the mouse gets power. RTS can be wired to Vs+ from the MAX232 and DTR to the second transmit line, controlled by GPIO C6.

