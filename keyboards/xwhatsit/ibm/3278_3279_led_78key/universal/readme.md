# xwhatsit/ibm/3278_3279_led_78key/universal

![xwhatsit/ibm/3278_3279_led_78key/universal](https://i.imgur.com/xqc1oBAh.jpg)

A short description of the keyboard/project

* Keyboard Maintainer: [Purdea Andrei](https://github.com/purdeaandrei)
* Hardware Supported: Supports the IBM Beamspring 3278/3279 (78-key) keyboards, using one of the xwhatsit controller PCBs supported by the 'universal' driver: the TH_XWhatsIt controller, or the Compact Beamspring controller.

  The open hardware controllers supported by this firmware are published here:
    https://github.com/listofoptions/TH-XWhatsIt
    https://github.com/purdeaandrei/CompactBeamSpring
    https://github.com/purdeaandrei/CompactBeamSpringAdditionalExpansion
  And they have been discussed in the following threads:
    https://deskthority.net/viewtopic.php?f=7&t=23406
    https://deskthority.net/viewtopic.php?f=50&t=24512

* Hardware Availability: Rare collector's item

It is recommended to use the Compact Beamspring with Addition Expansion controller:
https://github.com/purdeaandrei/CompactBeamSpringAdditionalExpansion
Please read this document for details on how to perform the necessary connections:
https://github.com/purdeaandrei/CompactBeamSpringAdditionalExpansion/blob/master/top_panel_modifications.md

Alternatively, in the absence of a Compact Beamspring with Addition Expansion controller,
it may also be possible to solder the connections directly to the pro micro of a TH controller or a normal Compact Beamspring
controller, however this is not recommended.

Make example for this keyboard (after setting up your build environment):

    make xwhatsit/ibm/3278_3279_led_78key/universal:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
