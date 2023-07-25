# xwhatsit/ibm/bigfoot_fxt_type_1/xwhatsit_rev4

![xwhatsit/ibm/bigfoot_fxt_type_1/xwhatsit_rev4](https://i.imgur.com/N7tnovWh.jpeg)

A short description of the keyboard/project

* Keyboard Maintainer: [Purdea Andrei](https://github.com/purdeaandrei)
* Hardware Supported: Supports the IBM Model F Bigfoot / FXT type 1 keyboards, using the original Xwhatsit beamspring controller PCB rev. 4.

  Design documentation for the original Xwhatsit boards can be found here: https://static.wongcornall.com/ibm-capsense-usb-web/ibm-capsense-usb.html
  Installation guides, open hardware source files, (and original firmware) are downloadable here: https://static.wongcornall.com/ibm-capsense-usb/

* Hardware Availability: Rare collector's item

These keyboards are supported by using an original Xwhatsit beamspring rev. 4 controller PCB,
and handwiring it into the original sense PCB which must be cut up to remove the original controller.
Wires are connected so that no two row/column wires cross.
Please be aware that one of pins between the beamspring pinout column pins is a not connected pin. This must be skipped.
Also please be aware that on the sense PCB two of the pads in the row of column pads don't actually go to any columns, these must also be skipped.
There are 23 columns in total, when cutting the PCB please make sure to allow access to the final 3 columns too. The pads for the final 3 columns are a little misaligned

Make example for this keyboard (after setting up your build environment):

    make xwhatsit/ibm/bigfoot_fxt_type_1/xwhatsit_rev4:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
