# The Omnikey Ultra "Ultra Mod"

This is a firmware for Modified Omnikey Ultra's after following my guied on www.keebal.com DO NOT use this firmware on a normal Omnikey Ultra As it will not work. The details on how to get your keyboard ready for the mod is on my webiste
Credit : Alectardy98
Thank You to lilwebsite
Thank you to MMcM


Hardware Supported: atmega32u4 

Make example for this keyboard (after setting up your build environment):

    "for arduino"
    make alectardy98/omnikey_ultra/32u4:default 
    
    or
    
    "for Pi Pico"
    make alectardy98/omnikey_ultra/rp2040:default 


The DIN-5 keyboard connector has Data on D0 and Clock on D1. "arduino"
The DIN-5 keyboard connector has Data on GP0 and Clock on GP1. "pi pico"
