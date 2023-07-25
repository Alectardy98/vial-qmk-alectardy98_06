# xwhatsit/ibm/fxt_type_2/wcass

![xwhatsit/ibm/fxt_type_2/wcass](https://i.imgur.com/AD8fc8Th.jpeg)

A short description of the keyboard/project

* Keyboard Maintainer: [Purdea Andrei](https://github.com/purdeaandrei)
* Hardware Supported: Supports the IBM Model F XT Type 2 keyboards, using the wcass controller PCB.

  The "wcass" controller design has been developed and published here: https://deskthority.net/viewtopic.php?f=7&t=13479

* Hardware Availability: Rare collector's item

Most Model F XT keyboards are type 2, See the Types section of this wiki: https://deskthority.net/wiki/IBM_Personal_Computer_keyboard#Types

This firmware is designed for a keyboard that has been converted in a similar way to the following post: https://deskthority.net/viewtopic.php?t=19522
The post shows an original xwhatsit controller, however please keep the same general intent with any other controllers too:
namely wires are connected so that no two row/column wires cross, and the column wires in use are those 12 that are closest to the row-side of the controller.
This applies if using one of the SMD Model F controller types, if using the TH controller with a daughtercard, or if using the 'wcass' controller.
If wiring in the TH controller directly, make sure that you skip the 7 columns coming off of the third (optional) shift register, like the daughterboard would do.

Make example for this keyboard (after setting up your build environment):

    make xwhatsit/ibm/fxt_type_2/wcass:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
