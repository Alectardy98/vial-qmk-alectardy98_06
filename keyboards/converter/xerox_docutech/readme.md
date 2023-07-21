# Keyboard converter for Xerox Docutech

This is a modification to the port of TMK's sony news code, using the sony news code now renamed and modified to workin in qmk  tmk_core/protocol in TMK to the keyboard directory in 
this version.

you will notice that the caps lock key actually has two matrix postions, in order to get full functionality, both matrix postion 5,13 and 6,13 should be set to the same key. It is stock to be used as caps lock, as labeled on the keyboard. 




## Build

```
git clone https://github.com/marfrit/qmk_firmware.git
cd qmk_firmware
make converter/xerox_docutech:vial
```

## Resource

- Soarer's Converter: http://geekhack.org/index.php?topic=17458.0
- 102keys(1392595): http://geekhack.org/index.php?topic=10737.0
- 122keys(1390876): http://www.seasip.info/VintagePC/ibm_1390876.html
- KbdBabel: http://www.kbdbabel.org/
- RJ45 Connector: http://www.kbdbabel.org/conn/kbd_connector_ibmterm.png
- DIN Connector: http://www.kbdbabel.org/conn/kbd_connector_ibm3179_318x_319x.png
- WinAVR: http://winavr.sourceforge.net/

