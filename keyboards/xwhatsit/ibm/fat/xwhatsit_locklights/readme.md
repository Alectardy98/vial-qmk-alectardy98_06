# xwhatsit/ibm/fat/xwhatsit_locklights

![xwhatsit/ibm/fat/xwhatsit_locklights](https://i.imgur.com/5YjgiXWh.jpeg)

A short description of the keyboard/project

* Keyboard Maintainer: [Purdea Andrei](https://github.com/purdeaandrei)
* Hardware Supported: Supports the IBM Model F AT keyboards, using the original Xwhatsit model F rev. 1 or rev. 2 controller PCB.

  Design documentation for the original Xwhatsit boards can be found here: https://static.wongcornall.com/ibm-capsense-usb-web/ibm-capsense-usb.html
  Installation guides, open hardware source files, (and original firmware) are downloadable here: https://static.wongcornall.com/ibm-capsense-usb/

  Note that this version of the firmware is configured primarly for locklights operation (limited solenoid support), where the lock lights are expected to be connected to the expansion
  header using the classic xwhatsit pinout. Some solenoid support is kept, by outputting the slenoid trigger and enable signals on other GPIOs, which the user may choose to manually solder to.

* Hardware Availability: Rare collector's item

Make example for this keyboard (after setting up your build environment):

    make xwhatsit/ibm/fat/xwhatsit_locklights:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
