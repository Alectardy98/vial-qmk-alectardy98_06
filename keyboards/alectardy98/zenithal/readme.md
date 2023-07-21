# ZENITHal

A customizable Alps-compatible PCB for the Zenith Z150. To update the firmware connect the PCB to your computer and press Reset button.
![Zenithal](https://i.imgur.com/6N7EfMU.png)

Keyboard Maintainer: [Alectardy98](https://github.com/Alectardy98)  
Hardware Supported: Zenithal
Hardware Availability: [keebal](https://keebal.com)   

Make example for this keyboard (after setting up your build environment):

    make alectardy98/zenithal:default
    
See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

This drop in replacment PCB supports both a teensy 2.0 using THT or a ATMEGA32U4-AU. Currently, it is often vary expensive or impoosable to have a pcb produced with a SMD ATMEGA32U4-AU chip. For this reason, either or can be used in case is one is out of stock. The firmware for this pcb will be the same regardless of what chip is used.

You will notice that the pcb supports various other layouts, see the attached photo for more details. This can be done by modifing the keymap.c file. An important note is that the layout supports various diferent positions of the led modifiers. Currently the defult firmware layout is ment to mimic a Z150 XT. Please see the refrence photo to determin what leds are adressable and how they can be changed.


