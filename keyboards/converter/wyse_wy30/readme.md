# Wyse WY-30

A converter for the Wyse WY-30 using a 4P4C connector.

Origional work, Wyse 4p4c: [MMcM](https://github.com/MMcM)  
Keyboard Maintainer: [ALectardy98](https://github.com/Alectardy98)  
Hardware Supported: Wyse Wy-30 / Pro Micro

Make example for this keyboard (after setting up your build environment):

    make converter/wyse_wy30:default
    make converter/wyse_wy30:vial

## Hardware

The connector is a 4P4C RJ modular jack. This wiring is the same as for Soarer's WYSEverter.

| Pin | Color  | Signal | AVR |
|-----|--------|--------|-----|
|   1 | Black  | Data   | D1  |
|   2 | Red    | Vcc    | +5V |
|   3 | Green  | Clock  | D0  |
|   4 | Yellow | Ground | GND |


This information was taken from the MMcM Wyse 4p4c project, but I found it a bit confusing. 
This might be more helpful, (from PCB TOP DOWN)
This view is when you flip the pcb over, and you can see the the THT pins for the 4p4c connector

      Top of PCB
|                    |
|       2    4       |
|                    |
|     1     3        |
|                    |
    Bottom of PCB
