# xwhatsit/brand_new_model_f/f62/universal

![xwhatsit/brand_new_model_f/f62/universal](https://i.imgur.com/uwqPTyth.jpeg)

A short description of the keyboard/project

* Keyboard Maintainer: [Purdea Andrei](https://github.com/purdeaandrei)
* Hardware Supported: Supports the F62 reproduction by Model F Labs keyboards, using one of the xwhatsit controller PCBs supported by the 'universal' driver: the TH_XWhatsIt controller, or one of the SMD Model F controllers.

  The open hardware controllers supported by this firmware are published here:
    https://github.com/listofoptions/TH-XWhatsIt
    https://github.com/purdeaandrei/SMDModelFController
    https://github.com/purdeaandrei/SMD4704KishsaverClassModelFController
    https://github.com/purdeaandrei/SMDModelFController/tree/extra_columns
  And they have been discussed in the following threads:
    TH: https://deskthority.net/viewtopic.php?f=7&t=23406
    SMD Model F: https://deskthority.net/viewtopic.php?f=7&t=24597

* Hardware Availability: Rare collector's item

WARNING: None of the keyboards that ship from modelfkeyboards.com come with a controller compatible with this firmware!
This firmware is only useful if you decide to modify your keyboard, and replace the controller PCB with a non-default one.
Otherwise please consult which controller you have in your keyboard and choose the correct one. Early keyboards shipped with the "wcass" controller,
and there are plans that in the future keyboards will be shipped with the "leyden_jar" controller.

Make example for this keyboard (after setting up your build environment):

    make xwhatsit/brand_new_model_f/f62/universal:default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).
