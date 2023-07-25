# xwhatsit/ibm/fssk_v1_0b/universal

![xwhatsit/ibm/fssk_v1_0b/universal](https://deskthority.net/download/file.php?id=29306)

NOTE: The above image is not accurate (it's of the v1.0 version)

A short description of the keyboard/project

* Keyboard Maintainer: [Purdea Andrei](https://github.com/purdeaandrei)
* Hardware Supported: Supports the FSSK v1.0b keyboards, using one of the xwhatsit controller PCBs supported by the 'universal' driver: the TH_XWhatsIt controller, or one of the SMD Model F controllers.

  The open hardware controllers supported by this firmware are published here:
    https://github.com/listofoptions/TH-XWhatsIt
    https://github.com/purdeaandrei/SMDModelFController
    https://github.com/purdeaandrei/SMD4704KishsaverClassModelFController
    https://github.com/purdeaandrei/SMDModelFController/tree/extra_columns
  And they have been discussed in the following threads:
    TH: https://deskthority.net/viewtopic.php?f=7&t=23406
    SMD Model F: https://deskthority.net/viewtopic.php?f=7&t=24597

* Hardware Availability: Rare collector's item

These are IBM Model M SSK keyboards modified with an "FSSK" sense pcb, and Model F flippers.
The FSSK project has been developed here: https://deskthority.net/viewtopic.php?t=10744

Note: FSSK v1.0b was never officially released by i$, however the FEXT 1.0b board has been designed such that
if chopping it shorter no additional path cables would be required. This firmware supports such chopped boards.
Also tamsin has released a nicely modified FSSK v1.0b diptrace file too, which can be found over here:
https://deskthority.net/viewtopic.php?p=512949#p512949

Make example for this keyboard (after setting up your build environment):

    make xwhatsit/ibm/fssk_v1_0b/universal:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
