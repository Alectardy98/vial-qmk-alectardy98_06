# HP Vectra

A converter for the eponymous keyboard.

Keyboard Maintainer: [Alectardy98](https://github.com/Alectardy98)  
Hardware Supported: HP 46010A, Teensy 2.0  

Make example for this keyboard (after setting up your build environment):

    make converter/hp_vectra:default
    
See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

This firmware should work for both early and late revisons of the HP Vectra PCB, The early revisions have extra positions free in the matrix, and can be used, if a latter PCB is being used, then just leave keys marked as KC_NO alone.

to build the actual converter, you will need a teensy 2.0 or something with enough pins, a standerd pro micro does not have enough free pins

On the left side of the pcb, there is a ribbon cable, here are the pins and positions of each part of the cable

----- (LED CATHODE) VCC
----- (LED KANA)    E6
----- (LED CAPS)    F1
----- (LED NUM)     F4
----- (LED SCRL)    F0
----- (Row 0)       B0
----- (Row 1)       B1
----- (Row 2)       B2
----- (Row 3)       B3
----- (Row 4)       B7
----- (Row 5)       D0
----- (Row 6)       D1
----- (Row 7)       D2
----- (Row 8)       D3
----- (Row 9)       C6
----- (Row 10)      C7
----- (Row 11)      D5
----- (Row 12)      D4
----- (Col 0)       D6
----- (Col 1)       D7
----- (Col 2)       B4
----- (Col 3)       B5
----- (Col 4)       B6
----- (Col 5)       F7
----- (Col 6)       F6
----- (Col 7)       F5

