# xwhatsit/ibm/3178/universal

![xwhatsit/ibm/3178/universal](https://i.imgur.com/VvDPHQQh.jpeg)

A short description of the keyboard/project

* Keyboard Maintainer: [Purdea Andrei](https://github.com/purdeaandrei)
* Hardware Supported: Supports the IBM Model F 3178 "Blue Switch" keyboards, using one of the xwhatsit controller PCBs supported by the 'universal' driver: the TH_XWhatsIt controller, or one of the SMD Model F controllers.

  The open hardware controllers supported by this firmware are published here:
    https://github.com/listofoptions/TH-XWhatsIt
    https://github.com/purdeaandrei/SMDModelFController
    https://github.com/purdeaandrei/SMD4704KishsaverClassModelFController
    https://github.com/purdeaandrei/SMDModelFController/tree/extra_columns
  And they have been discussed in the following threads:
    TH: https://deskthority.net/viewtopic.php?f=7&t=23406
    SMD Model F: https://deskthority.net/viewtopic.php?f=7&t=24597

* Hardware Availability: Rare collector's item

WARNING: the 3178 "blue switch" keyboard has an unusual pinout with many pins shifted, so you will need to:
 * If you're using an original Xwhatsit Model F controller, you will also need the thin adaptor board designed for 3178 keyboards, or you will need to connect it with individual wires, keeping in mind those shifted pins.
 * If you're using and SMD Model F controller, or a TH controller with daughterboard, then simply choose the alternate row of pins that are marked to be used with 3178 keyboards.
 * If you're using a wcass controller, or just the motherboard of the TH controller, then you will need to keep in mind the shifted pins when connecting the keyboard using individual wires.

Make example for this keyboard (after setting up your build environment):

    make xwhatsit/ibm/3178/universal:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
