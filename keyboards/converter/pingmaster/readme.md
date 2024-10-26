# Converter IBM Pingmaster 4704

This is ported code from TMK, from the origional work done by Jun Wako

Keyboard Maintainer: [Alectardy98](https://github.com/Alectardy98)  
Hardware Supported: Ibm Pingmaster 4707
Hardware Availability: Vintage

Make example for this keyboard (after setting up your build environment):

    make converter/pingmaster:default
    
See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).


4704 Keyboard Protocol
======================
On powering up keyboard sends keyboard ID; A3h for 6019284(62-key), for example.
After that the keyboard enters FC command mode and waits for parameter data from host
so that it doesn't send any scancode until you send 'FF'(End of FC command mode).


    Keyboard                    ID
    -------------------------------
    Model 100 50-key            A2h
    Model 200 62-key            A3h
    Model 300 77-key            A4h
    Model 400 107-key           A5h
    Japanese/Chinese 102-key    A6h


Connector
---------
    Keyboard Plug from front

    DSUB-9
    -------------
    \ N 2 3 4 5 /
     \ N N N N /
      ---------
    2   GND
    3   VCC 5V
    4   DATA
    5   CLOCK
    N   No connection/No pin.


Keyboard to Host
----------------
Data bits are LSB first and Pairty is odd. Clock has around 60us high and 30us low part.

            ____       __   __   __   __   __   __   __   __   __   _______
    Clock       \_____/  \_/  \_/  \_/  \_/  \_/  \_/  \_/  \_/  \_/
                 ____ ____ ____ ____ ____ ____ ____ ____ ____ ____
    Data    ____/    X____X____X____X____X____X____X____X____X____X________
                Start   0    1    2    3    4    5    6    7    P  Stop

Start bit:  can be long as 300-350us.
Inhibit:    Pull Data line down to inhibit keyboard to send.
Timing:     Host reads bit while Clock is hi.(rising edge)
Stop bit:   Keyboard pulls down Data line to lo after 9th clock.



Host to Keyboard
----------------
Data bits are LSB first and Pairty is odd. Clock has around 60us high and 30us low part.

            ____        __   __   __   __   __   __   __   __   __   ________
    Clock       \______/  \_/  \_/  \_/  \_/  \_/  \_/  \_/  \_/  \_/
                ^   ____ ____ ____ ____ ____ ____ ____ ____ ____ ____ ___
    Data    ____|__/    X____X____X____X____X____X____X____X____X____X   \___
                |  Start   0    1    2    3    4    5    6    7    P   Stop
                Request by host

Start bit:  can be long as 300-350us during start up and upto 2500us while key scanning
Request:    Host pulls Clock line down to request to send a command.
Timing:     After Request keyboard pull up Data and down Clock line to low for start bit.
            After request host release Clock line once Data line becomes hi.
            Host wirtes a bit while Clock is hi and Keyboard reads while low.
Stop bit:   Host releases or pulls up Data line to hi after 9th clock and waits for keybaord pull down the line to lo.



Scancodes
---------
Keyboard doesn't send Break code for all keys except for Alt by default.

    6019284 62-key:
    ,-----------------------------------------------------------.
    |  `|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|**1|BS |
    |-----------------------------------------------------------|
    |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P| ￠|  \|  PD2|
    |-----------------------------------------------------------|
    |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| {}| PD3|
    |-----------------------------------------------------------|
    |Shif| <>|  Z|  X|  C|  V|  B|  N|  M|  ,|  ,|  /|**2|Shift |
    |-----------------------------------------------------------|
    |Reset|blk|Alt  |         Space             |Alt  |blk|Enter|
    `-----------------------------------------------------------'
    +----------+---------------------+----------+----------+
    |`       00|PD1     04|Caps    20|LShift  30|Reset   31|
    |1       18|q       05|a       21|<>      3E|Rblank  41|
    |2       19|w       06|s       22|z       32|Alt     3F|
    |3       1A|e       13|d       23|x       33|Space   40|
    |4       10|r       14|f       24|c       34|Alt     3F|
    |5       11|t       15|g       25|v       35|Lblank  42|
    |6       12|y       16|h       26|b       36|Enter   2F|
    |7       08|u       17|j       27|n       37|          |
    |8       09|i       01|k       28|m       38|          |
    |9       0A|o       02|l       29|,       39|          |
    |0       0F|p       03|;       2A|.       3A|          |
    |-       1F|￠      1B|'       2B|/       3B|          |
    |=       0D|\       1C|{}      2C|**2     3C|          |
    |**1     0C|PD2     1D|PD3     2D|RShift  3D|          |
    |BS      0E|          |          |          |          |
    +----------+---------------------+----------+----------+
    Bit7 is 'press flag' which set 1 on press and 0 on release when break code is enabled.

NOTE: When break code is enabled the key sends scancode with setting 7th bit on press
and without it on release. That is, '`' sends 80h on press and 00h on release.


Keyboard command
----------------
Keyboard accepts these commands from host.

        Description                             Entry point
    -----------------------------------------------------------
    FF  Soft Reset                              0008h
    FE  Resend                                  00e8h
    FD  Buzzer(emits a short beep)              00edh
    FC  Set Key Flag                            00f6h
    FB  Soft Reset                              0008h
    FA  Reset                                   0000h


Keyboard response
-----------------
Keyobard sends these bytes to host.

        Description                             Entry point
    -----------------------------------------------------------
    FE  Overflow(key event/receive data)        00c5h, 0346h
        Memory test error                       0224h
    FD  Command out of bound                    00d8h
        Key out of bound
    7E  Read/Parity error in receive from host  00bch
    80-FB? scan code(make)
    00-7B? scan code(break)
    note: Alps model spits scan code 7B(FB) at least.


Set Key Flag command(FC)
------------------------
After 'Power on Reset' firmware enters this command mode and waits for data from host,
so that you don't need to send 'FC' and it doesn't send any scancode until you send 'FF' to exit this mode.
With Alps models you need to send 'FC' command to enter this mode.

Data sent from host:

    bit: 7   6 ... 0
         en  |     |
         |   `-----`--- scan code
         `------------- enable bit(0: enable repeat, 1: enable break)

    00-7B   Enable repeat
    80-FB   Enable break
    FE      Resend(011ah) no need to use
    FF      End(0114h) exits FC command mode.

Response from keyboard:
    FD      Out of bound - Invalid scancode
    --      OK - No response means that command is accepted.

Examples:
    To enable break code of all keys you have to send following commands.

    FC 80 81 ... FB FF



4704 Hardware
=============
Power consumption
-----------------
This keyboard is very power greedy, it consumes around 170mA
and USB port may not be able to supply enough current.

    5.061V  -               No load. Power from Powered USB Hub.
    4.946V  133.6mA max     without Buzzer
    4.911V  171.0mA max     with Buzzer


Controller Board
----------------
NOTE: TWO BOLTS OF CONTROLLER BOARD IS CRITICAL.
Controller PCB and tab of bottom plate of key assembly with two hex bolts, these
connect between controller ground to the metal bottom plate of key switch assembly.
This connection is very critical to sense key state, keys will not be registered
unless they are tightened up with the bolts

    Controller: 8048 DIP40 with 1KB ROM and 64B RAM(8748H?)
    Clock:      ??MHz   Resonator? TODO: machine cycle: ??us
    Buffer:     7917 hex buffer
    Sensor:     IBM custom chip for capacitive sense


8048 Pin configuration
----------------------
Bus:
    bit: D7  D6  D5  D4  D3  D2  D1  D0
    use: BZ  CLK DAT ??? G   S2  S1  S0

    use dir     description
    ----------------------------------------------------------------------
    S0  out     Sensor select
    S1  out     Sensor select
    S2  out     Sensor select
    G   out     Sensor strobe?
    ???         Sensor state out(drive/charge? via 7917 buffer)
    DAT out     Data via buffer logic with 2K pull up resistor
    CLK out     Clock via buffer logic with 2K pull up resistor
    BZ  out     Drive Buzzer via 7917 buffer with 2KOhm pull up resistor(H:on/L:off)
T0:
    input of Sensor state(H:on/L:off)
T1:
    input of Clock line with 1KOhm pull up resistor
INT:
    input of Data line with 1KOhm pull down resistor
PORT1:
    P10-P17 matrix row0-7
PORT2:
    P20     matrix row8 or I(keyboard identity bits row)


Connections
-----------
    8048            Sensor
    -----------------------------
    D0-2 ====/===== S0-2(Sensor)
    D3   ---------- STR(Sensor)
           7917 buffer
    D4   --|>--+--- OUT(Sensor)
    T0   ------'

    8048            line
    -----------------------------
           Vcc  Vcc
            |    |
            R 1K R 2K
    T1   ---+-<|-+- CLK
    D6   ---|>---'
                Vcc
                 |
                 R 2K
    D6   ---|>---+- DAT
    T1   -+---<|-'
          R 1K
          |
         GND
                Vcc
                 |
                 R 2K
    D7   ---|>---+- BZ


Interruption
------------
I       disable at 0015h
TCNTI   disable at 0014h


IBM Capacitive sensor chip
--------------------------
Silver canned package

    Pin             Connection      Desciption
    ----------------------------------------------------------------
    Input(C0-7)     Matrix Col0-7   8 column line inputs
    Col select(S0-2)8048:D0-D2      Select column line to sense
    Strobe(STR)     8048:D3         Strobe
    Output(OUT)     848:T0          Read Key state(0:pressed/1:released)

    Pinout from bottom:
    +-----------++------+-------+-------+-------+
    | 1 2 3 4 5 ||1:LCL |6:LCC  |B:S0   |G:C5   |
    | 6 7   8 9 ||2:GND |7:LCM  |C:?    |H:C4   |
    | A       B ||3:Out |8:S2   |D:C6   |I:C3   |
    | C D   E F ||4:STR |9:S1   |E:C0   |J:C2   |
    | G H I J K ||5:VCC |A:C7   |F:?    |K:C1   |
    +-----------++------+-------+-------+-------+

    8048            Sensor
    D0-2 ====/===== S0-2
    D3   ---------- STR
           7917 buffer
    D4   --|>--+--- OUT
    T0   ------'

    Speculation: 8048:D4 is used to prepare to sense capacitance.(charge key capcitor?)

Procedure:
    at 030dh:
    D0-2=<column>   ; select column S0-2
    D4=1            ; Prepare sensor(Charge?)
    P1/P2=<row>     ; select row
    D0-4=<default>  ; 00010(bus=c2h)
    D3=1            ; Strobe
    P1/P2=0         ; unselect row
    read T0         ; see key state

    at 01afh:
    D0-2=<column>
    D4=1
    D0-2=2(010)     ; select col2
    P2=01h          ; select row
    D3=1            ; Strobe
    P2=00h          ; unselect row
    read T0


Keyswitch Matrix
----------------
6019284(62-key):
     |0       1       2       3       4       5       6       7
    -|--------------------------------------------------------------
    0|Enter   RShift  JIS_    PD3     PD2     \|      LofBS   BS
    1|RAlt    RBlank  /?      '"      {}      Cent!   -       =
    2|,       .       l       ;       o       p       9       0
    3|m       n       k       j       u       i       7       8
    4|Spc     b       g       h       t       y       5       6
    5|v       c       d       f       e       r       3       4
    6|LAlt    z       x       s       a       w       q       2
    7|Reset   LBlank  ISO\    LShift  CapLock PD1     `~      1
    8|_       x       _       _       x       x       _       _ (Identity bits: 32h)

    Two 15-line flat cables shown from bttom of PCB:

          Flatcable A    Flatcable B
        /             \/             \
        0123456789ABCDE0123456789ABCDE
        --8-----01234567----76543210--
          Id    row         col         -:GND


Keyboard Identity Bits
----------------------
4704 keyboards has its identity bit marks on PCB matrix and it is readable
from firmware so that it can select key layout depending on this.

PCB pictures:
    Model 100:
        http://kishy.dyndns.org/wp-content/uploads/2013/02/6019273_0011.jpg
    Model 200:
        http://kishy.dyndns.org/wp-content/uploads/2013/02/6019284_0020_capacitive-pcb-top.jpg
    Model 300:
        http://kbtalking.cool3c.com/article/23272
    Model 400:
        http://kishy.dyndns.org/wp-content/uploads/2011/09/6020218_distrib_0019.jpg



4704 Firmware
=============

Startup sequence
----------------
Power on Reset(0000h):
    Short Buzzer
        turns Buzzer(BZ=L) on at 0002h
        turns Buzzer(BZ=H) off at 01adh
    Initialize all memory(3fh-00h)
    Initialize other registers
    Read keyboard id and set default parameter at 01afh
        set break flag for Alt key by default
    Test and clear memory(3fh..00h) at 0202h
    Test program memory at 0214h
    r4=($21&07h)|50h at 0020h
    Send test result at 022dh
        sends [a0h | (keyboard id&f0h)>>4] on success
        6019284 seneds a3h on success
    Wait for data from host - it expects FC command data followed by ffh(end)
    Main loop

Soft Reset(0008h):
    Initialize all memory(20h-00h) It retains parameter memory.
    Initialize other registers
    r4=($21&07h)|50h at 0020h
    Main loop


Memory Map
----------
RAM(64 bytes):
$01-07  *Bank0* Registers r0-r7
        r0  temporary use
        r1  temporary use
        r2  temporary use
        r3  row mask of scan 024dh, 0257h
        r4  bus default value
            7 6 5 4 3 2 1 0
            | | | | | | | |
            | | | | | `-`-`------ Sensor column select
            | | | | `------------ Sensor strobe?
            | | | `-------------- Sensor column set?
            | | `---------------- Data
            | `------------------ Clock
            `-------------------- Buzzer control(L:on/H:off)023ch
            =$21&07h|50h: call 0020h at 001ch soft reset (52h=0101 0010)
            =$21&07h|50h: call 0020h at 0109h command FC (52h=0101 0010)
            =r4|80h: at 00f4h(FD command)
            =r4&7fh: at 023ch(Main)
            =r4&f0h: at 0200h
        r5  repeat dealy/interval
            used at 02d7h
            =07h at 02d9h
            =28h at 02ddh
            =28h at 02e1h
       *r6  0bh at 00edh(FD command)
            used at 0232h
        r7  received data from host
            temporary use at 01afh
            temporary use at 005dh
            =r4&c0h(current bus value?) 0247h
$08-17  8-level stack(2*8)
    $0E
    :       last key state(1:pressed/0:released)
    $15     (0E-15)=8*8=64 matrix(for 50-key and 62-key?)
    $16
    :       last key state(1:pressed/0:released)
    $1C     (16-1C)=7*8=56 (extension for 77-key?)

$18-1F  *Bank1* Registers 0-r7
    Outgoing buffer of data sent to host
    $1D     r5      outgoing buffer top
    $1E     r6      outgoing buffer
    $1F     r7      outgoing buffer bottom


$20     Resend buffer: code last sent used by 'Resend'(FE)

$21     Keyboard identity bits
        0011 0010  (6019284: 32h read from Row(I))
         ||| ||||
         ||| |```- Sensor chip control(bus value)??
         ||| `---- ???
         ```------ keyboard model id

        set at 01fah on Power on Reset:  32h from row8(I)(6019284)
        got at 0020h on Soft Reset:
        got at 034eh on translate into scan code:
        got at 0125h on command FC:
        set from scan 8(I) row at 01fdh

        Keyboard model id:
            Model 100 6019273 50-key (grid layout):     22h(from picture)
            Model 200 6019284 62-key Alpha(60% layout): 32h
            Model 300 6019303 77-key Expanded Alpha:    42h?(from dump list)
            Model 400 6020218 107-key Full key:         no identity
                Looks like this firmware does not support 107-key.

        IBM 4704 keyboards:
            It seems Model 100, 200 and 300 keyboards share one firmware code and
            have small square copper patterns on righ side of PCB to identify
            its layout. See following pictures. Model 400 may use another firmware.

$22-3F  30-byte Parameter RAM(Repeat and Break flags)
        Parameter byte is comprised of four flag pairs. Flags occupies two bits each a key.
        Parameter RAM can have flags for 120(4*30) keys.

        Parameter byte and flags:
            bit 7   6   5   4   3   2   1   0
                3r  3b  2r  2b  1r  1b  0r  0b
:
$3F     End of Memory(64 bytes)




Entry points
------------
0020    Soft Reset  r4=($21&07h)|50h = (32h&07h)|50h=52h
0029    r1=r1+(a), a=r0 (page 0)
002c    (F0=0: send or receive data with 'interpret command mode')
002d    Receive data or Send scan code
0035    Send scan code
        return: F1=1
0082    Receive data from host
        condition: F0==0   interpret command
                   F0==1   return receive data(a)
        return:    F1=1(ERROR) 00c7 (Receive ACK/Parity Error) 00b6,00ce
                   F1=0?
                   a=recieve data, (with F0=0 00dc) F0==0 means 'data received'
00bc    push 7f(error) into outgoing buffer
00be    push data/response into outgoing buffer(r5,r6,r7)
00d2    interpret keyboard command
00de    calculate parity

01a4    r1=r1+(a), a=r0 (page 1)
01a5    r1=r1+a, a=r0
01a9    Buzzer and Scan row8(*) and set param: call from Power on Reset 0018h
01af    Read keyboard identity bits from row8(I) and set param: - call from command FC 0107h
0202    Memory Test(Power on Reset)

0230    Main loop:  send, receive data and scan
        send/receive: call 002c
0263    **Scan matrix**(F1==0): F1=1, r1=15h, r2=3fh, r3=01h
0287    **Scan matrix**(F1==1): F1=0, r1=1ch, r2=77h, r3=02h
0325    get key configure flags(a=-----rb; where r:repeat enable, b:break enable)
0339    queue data at bottom of outgoing buffer
034e    translate into scan code
        scan code table1/table2


Keyboard command entry points
-----------------------------
FF: jump_table0   Soft Reset(008h)
FE: jump_table1   Resend(return content of $20)
FD: jump_table2   Short beep BZ
FC: jump_table3   parameter configuration(100h)
FB: jump_table4   Soft Reset(008h)
FA: jump_table5   Reset(000h)




;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
;  8048 Disassembly of IBM 6019284 ROM dump
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; label mnemonic                ; address   comment
;-------------------------------------------------------------------------------------
    org    000h
; jump_table:5  Hard Reset/Power on Reset
    mov    a,#07fh        ; 0000 - a=7f        Power on Reset
    outl    bus,a        ; 0002 - BZ=L(off), others=H
    mov    r0,#03fh    ; 0003 - r0=3fh
    clr    f1        ; 0005 - F1=0
    jmp    X000c        ; 0006 -
; jump_table:0,4 Soft Reset
    mov    r0,#020h    ; 0008 - r0=20h      $20=resend buffer
    clr    f1        ; 000a -
    cpl    f1        ; 000b - F1=1

;;;;;;;;;;;;;;;;;;
;   initialize memory
;       hard reset  clear 3f-00h    F1=0
;       soft reset  clear 20-00h    F1=1
X000c:    clr    f0        ; 000c - F0=0
    clr    a        ; 000d - a=0
X000e:    mov    @r0,a        ; 000e - @r0=0   r0=$3f(hard)/$20(soft)
    djnz    r0,X000e    ; 000f - clear RAM 3f/20h to $00
    mov    psw,a        ; 0011 - psw=0
    outl    p1,a        ; 0012 - p1=0
    outl    p2,a        ; 0013 - p2=0
    dis    tcnti        ; 0014 - disable timer overflow
    dis    i        ; 0015 - disable INT
    jf1    X001c        ; 0016 - jump if F1==1(Soft Reset?)

; F1==0 Power on Reset
    call    X01a9        ; 0018 - read keyboard id and set default parameter
    jmp    X0202        ; 001a - Memory Test and go to Main

; F1==1 Soft Reset
X001c:    call    X0020        ; 001c - ; r4=$21&07h|50h(52h?), a=r4
    jmp    X0230        ; 001e - ; go to Main

;;;;;;;;;;;;;;;;;;
; Set r4
: INPUT:    r4???
: RETURN:   a=r4(original)
;           r4=$21&07h|50h
;
X0020:    mov    r0,#021h    ; 0020 -  r0=21h(keyboad identity bits)
    mov    a,@r0        ; 0022 -  a=($21)
    anl    a,#007h        ; 0023 -  a=a&07h
    orl    a,#050h        ; 0025 -  a=a|50h
    xch    a,r4        ; 0027 -  swap a,r4
    ret            ; 0028 -

; read program memory @page0
; INPUT: a:address
; OUTPUT: a=(a)@page0
X0029:    movp    a,@a        ; 0029 -
    jmp    X01a5        ; 002a - r1=r1+a, a=r0



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Receive data or Send scan code
; INPUT:    F0=0:interpret command/1:retern data            used in Receive command/data
; OUTPUT:   F0=0(received)/1(not received)
; DONE: a=0, F1=1, buffer rotate
X002c:    clr    f0        ; 002c - F0=0
X002d:    jnt1    X0082        ; 002d - go to receive if T1(CLK)==L
    sel    rb1        ; 002f - switch to bank1
    mov    a,r5        ; 0030 - a=r5(bank1)            r5(bank1): scan code buffer
    sel    rb0        ; 0031 - switch to bank0
    jnz    X0035        ; 0032 - jump if r5(bank1)!=0
    retr            ; 0034 - return if r5(bank1)==0 buffer empty

;;;;;;;;;;;;;;;;;;
; Send scan code
; INPUT:    a=data
; OUTPUT:   F1=1:Sent,Rotate,Data ready/0:???
X0035:    dec    a        ; 0035 - a--
    clr    c        ; 0036 - c=0
    call    X00de        ; 0037 - c=parity calc
    jnt1    X0082        ; 0039 - go to receive if T1(CLK)=L
; Start bit
    anl    bus,#0bfh    ; 003b - [CLK=L]
    orl    bus,#020h    ; 003d - [DATA=H]        [[[Start bit]]]
    mov    r0,#010h    ; 003f - r0=10h


; check inhibited(DATA==L) - check DATA line released by host
X0041:    jni    X0047        ; 0041 - jump if DATA==L LOOP>
    jni    X0049        ; 0043 - jump if DATA==L
    jmp    X0054        ; 0045 - cont. if DATA==H
X0047:    jmp    X0049        ; 0047 -
X0049:    djnz    r0,X0041    ; 0049 - <LOOP  timeout?
; time out - end
    orl    bus,#040h    ; 004b - [CLK=H]
    anl    bus,#0dfh    ; 004d - [DATA=L]       [[[idle state]]]
    retr            ; 004f - return send end(give up with inhibited)


; check data==7eh   Keep data in 'Resend' buffer unless it is 7eh
X0050:    xrl    a,#07eh        ; 0050 - revert a
    jmp    X005d        ; 0052 -

X0054:    mov    r0,#020h    ; 0054 - r0=20h 'Resend' Buffer
    xrl    a,#07eh        ; 0056 - a=a^7eh(0111 1110)
    jz    X0050        ; 0058 - jump if a==7eh
; a!=7eh        retain data to $20(resend buffer) if data is not 7eh
    xrl    a,#07eh        ; 005a - revert a
    mov    @r0,a        ; 005c - $20=a  retain a to 'Resend' buffer


; Data bit0-7 and Parity(c)
; Pulse H:18/L:9??
X005d:    mov    r7,#009h    ; 005d - r7=9
X005f:    mov    r0,#009h    ; 005f - r0=9 LOOP>>
    jb0    X0069        ; 0061 - jump if a:bit0==1
; a:bit0==0
; send DATA=0
    anl    bus,#0dfh    ; 0063 - [DATA=L]
    orl    bus,#040h    ; 0065 - [CLK=H]
    jmp    X006f        ; 0067 -
; a:bit0==1
; send DATA=1
X0069:    orl    bus,#020h    ; 0069 - [DATA=H]
    orl    bus,#040h    ; 006b - [CLK=H]
    jmp    X006f        ; 006d -
; hold CLK=H
X006f:    djnz    r0,X006f    ; 006f - 9*2cycle delay (around 60us??)
    anl    bus,#0bfh    ; 0071 - [CLK=L]
    rrc    a        ; 0073 - a=a>>1, c=a:bit0
    djnz    r7,X005f    ; 0074 - <<LOOP
; Stop bit
; a=0, F1=1, buffer rotate
    anl    bus,#0dfh    ; 0076 - [DATA=L]           [Idle]  End
    clr    a        ; 0078 - a=0
    clr    f1        ; 0079 -
    cpl    f1        ; 007a - F1=1               [Sent?]
    orl    bus,#040h    ; 007b - [CLK=H]            [Idle]  End
; remove from outgoing buffer: r7=0, r6=r7, r5=r6
    sel    rb1        ; 007d - switch to bank1
    xch    a,r7        ; 007e -
    xch    a,r6        ; 007f -
    xch    a,r5        ; 0080 - 0->r7->r6->r5->a  [Bank1 Buffer rotate]
    retr            ; 0081 - retr reverts to bank0



;;;;;;;;;;;;;;;;;;
; Receive command/data from host
; INPUT:    F0=0:interpret command/1:return data(used by command)
; OUTPUT:   F0=0(received)/1(not received)
;           F1=1:Error/0:OK
; a: data
; c: parity
; F1: 0: Receive or Send 1: Receive
;
X0082:    jf1    X0086        ; 0082 -  jump if F1==1
; F1==0
    jmp    X002d        ; 0084 -  Can't recevie, do 'Receive or Send' again
; F1==1
X0086:    mov    r0,#006h    ; 0086 -  r0=6h
X0088:    djnz    r0,X0088    ; 0088 -  6*2cycle dealy
    jt1    X00cb        ; 008a -  return if T1(CLK)==H
    anl    bus,#0bfh    ; 008c -  [CLK=L]
    orl    bus,#020h    ; 008e -  [DATA=H]                  [Start bit]
    mov    r0,#011h    ; 0090 -
X0092:    djnz    r0,X0092    ; 0092 -  11*2cycle delay
    mov    r7,#009h    ; 0094 -  r7=9h
X0096:    orl    bus,#040h    ; 0096 -  LOOP>[CLK=H]              [Clock up for receive]
    mov    r0,#008h    ; 0098 -
X009a:    djnz    r0,X009a    ; 009a -  8*2cycle delay
    anl    bus,#0bfh    ; 009c -  [CLK=L]                   [Clock down]
    jni    X00a9        ; 009e -  jump if INT(DATA)==L      [Read bit] Read twice for debounce?
; DATA==H
    orl    a,#001h        ; 00a0 -  a:bit0=1
    jni    X00ad        ; 00a2 -  jump if INT(DATA)==L
; DATA==H
X00a4:    rrc    a        ; 00a4 -  a=a>>1 with carry         [Next bit]
    djnz    r7,X0096    ; 00a5 -  <LOOP
    jmp    X00b0        ; 00a7 -                            [go to Stop]
; DATA==L
X00a9:    anl    a,#0feh        ; 00a9 - a:bit0=0
    jni    X00a4        ; 00ab -  jump if INT(DATA)==L
; DATA==H
X00ad:    clr    f1        ; 00ad -  F1=0                      [Receive Error]
    jmp    X00a4        ; 00ae -


; wait for Stop/ACK (DATA=H)
; F0: 0=jump table, 1=return(with F0=0)
X00b0:    orl    bus,#040h    ; 00b0 - [CLK=H]                    [Idle] End
    mov    r0,#004h    ; 00b2 -
X00b4:    djnz    r0,X00b4    ; 00b4 - 4*2cycle? 8*0.2us=1.6us?
    jni    X00c7        ; 00b6 - jump if INT(DATA)==L       [Stop Error] *no error response?
; DATA==H
    anl    bus,#0dfh    ; 00b8 - [DATA=L]                   [Idle] End
    jf1    X00cc        ; 00ba - jump if F1==1
; F1==0                                                             [Receive Error]


; push 7eh into outgoing buffer (Receive Error at 00bah/Parity Error at 00ceh)
X00bc:    mov    a,#07eh        ; 00bc - 7eh: error response

; push data into top of outgoing buffer(Error response)
; a:data
; r5=a, r6=r5, r7=r6
X00be:    sel    rb1        ; 00be - switch to bank1
    inc    a        ; 00bf - a++
    xch    a,r5        ; 00c0 - a->r5->r6->r7->a
    xch    a,r6        ; 00c1 -
    xch    a,r7        ; 00c2 -
    jz    X00cb        ; 00c3 - jump if a==0
    mov    r7,#0ffh    ; 00c5 - r7=ffh overflow            [Over flow:FE]

X00c7:    anl    bus,#0dfh    ; 00c7 - [DATA=L]                   [Idle] End
    clr    f1        ; 00c9 -
    cpl    f1        ; 00ca - F1=1                       [Error flag]
X00cb:    retr            ; 00cb -



; check parity of recieve data
; F1==1
X00cc:    call    X00de        ; 00cc - call parity calc
    jc    X00bc        ; 00ce - jump if carryflag=1    (Parity ERROR)
; parity OK
    jf0    X00dc        ; 00d0 - jump if F0==1


;;;;;;;;;;;;;;;;;
; F0==0
; Interpret command
;
    cpl    a        ; 00d2 - compliment a       ffh-a(command)
    add    a,#jump_table    ; 00d3 - a=a+#jump_table
    jc    X00d8        ; 00d5 -
    jmpp    @a        ; 00d7 - jump table             [Keyboard command]
; Command Out bound Error
X00d8:    mov    a,#0fdh        ; 00d8 -    error response: FD
    jmp    X00be        ; 00da -

;;;;;;;;;;;;;;;;;
; F0==1
; Return data
X00dc:    cpl    f0        ; 00dc - F0=~F0(=0)
    ret            ; 00dd -
;
; recieve data/command
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;
; calculate parity: 'c' depends on number of '1' in 'a'
;   INPUT: a=data
;   OUTPUT: c(carry flag)
X00de:    mov    r0,#008h    ; 00de - b8 08    8.  r0=8h
X00e0:    rr    a        ; 00e0 - 77    w   a=a>>1
    jb0    X00e4        ; 00e1 - 12 e4    .d  jump if a:bit0==1
    cpl    c        ; 00e3 - a7    '   compliment carry flag
X00e4:    djnz    r0,X00e0    ; 00e4 - e8 e0    h`  jump if --r0!=0
    cpl    c        ; 00e6 - a7    '
    ret            ; 00e7 - 83    .



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Keyboard command  jump table
;
; jump_table:1 FE   Resend(return content of $20)
X00e8:    mov    r0,#020h    ; 00e8 -  $20
    mov    a,@r0        ; 00ea -  a=$20 get from resend buffer
    jmp    X00be        ; 00eb -  push into outogoing buffer

; jump_table:2 FD   r6=0bh, r4=r4|80h
    mov    r6,#00bh    ; 00ed -  r6=0bh  BZ duration(scan cycles)?
    orl    bus,#080h    ; 00ef -  BZ=H(on)
    mov    a,r4        ; 00f1 -
    orl    a,#080h        ; 00f2 -  BZ=H
    mov    r4,a        ; 00f4 -  r4=r4|80h BZ=H(on) bus-default
    retr            ; 00f5 -

; jump_table:3 FC
    mov    r1,#01eh    ; 00f6 -  r1=1eh
    jmp    X0100        ; 00f8 -

;
; keyboard commands:
;
; FF: jump_table0   Soft Reset(008h)
; FE: jump_table1   Resend(return content of $20)
; FD: jump_table2   BZ set BZ=H(on) to bus and r4(bus-default), duration to r6
; FC: jump_table3   Set key configuration
; FB: jump_table4   Soft Reset(008h)
; FA: jump_table5   Reset(000h)
;
jump_table:    db    008h,0e8h,0edh,0f6h,008h,000h        ; 00fa .hmv..
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; command FC    parameter configuration
;   clear $22-3f, then set data received from host
;
; r4:
;   set to $21&07h|50h
; r7: received data
;   r7=data|7fh
;       F0=0 if data:bit7=1
;       F0=1 if data:bit7=0
;
; data received(r7):
;   FF      End(0114h)
;   FE      Resend and receive again(011ah)
;   FF-80   F0=0    if bit7 of r7 is set
;   7F-00   F0=1    if bit7 of r7 is reset
;
;

;;;;;;;;;;;;;;;;;;
; clear parameter configuration RAM $3f..22
; INPUT: r1=1eh=30
;   called at 00f6h
X0100:    clr    a        ; 0100 - a=0
    mov    r0,#03fh    ; 0101 - r0=3f
X0103:    mov    @r0,a        ; 0103 - $3f=a
    dec    r0        ; 0104 - r0--
    djnz    r1,X0103    ; 0105 -
    call    X01af        ; 0107 - Read keyboar id and set parameter flags
    call    X0020        ; 0109 - r4=($21 & 07h | 50h) =52h

;;;;;;;;;;;;;;;;;;
; data receive from host
;
X010b:    clr    f0        ; 010b - LOOP>>
    cpl    f0        ; 010c - F0=1
X010d:    call    X002d        ; 010d - receive/send data with F0=1
    jf0    X010d        ; 010f - LOOP while F0==1


; received data from host(F0==0)
    mov    r7,a        ; 0111 - r7=data received
    cpl    c        ; 0112 - c=~c
    cpl    a        ; 0113 - a=~a

;;;;;;;;;;;;;;;;;
; a==FF *End*
    jz    X013b        ; 0114 - return if a==FF
    xrl    a,#001h        ; 0116 -
    jnz    X011e        ; 0118 - jump if a!=FE

;;;;;;;;;;;;;;;;;
; a==FE *Resend*
    call    X00e8        ; 011a - Resend         and continue...
    jmp    X010b        ; 011c - <<LOOP         Send/Receive loop again

;;;;;;;;;;;;;;;;;
; else  *Set flag*
;   data:bit7=1:enable break/0:enable repeat
X011e:    mov    a,r7        ; 011e - a=r7(data received)
    jb7    X0122        ; 011f - jump if a:bit7==1  (1xxx xxxx)
    cpl    f0        ; 0121 - F0=~F0=1   if a:bit7==0    [F0=1 means data:bit7==0]
X0122:    anl    a,#07fh        ; 0122 - a=a&7fh                    [data:bit6-0=scan code]
    mov    r7,a        ; 0124 - r7=a


; identify keybaord from $21=keyboar identity bits
    mov    r1,#021h    ; 0125 - r1=21h
    mov    a,@r1        ; 0127 - a=($21)
    anl    a,#0f0h        ; 0128 - a=a&f0h
    xrl    a,#020h        ; 012a - a=a^20h
    jz    X013c        ; 012c - jump if $21==0010 xxxx     6019273 50-key?
    xrl    a,#010h        ; 012e - a=a^10h
    jz    X0142        ; 0130 - jump if $21==0011 xxxx     *6019284 62-key*
    xrl    a,#070h        ; 0132 - a=a^70h
    jz    X0148        ; 0134 - jump if $21==0100 xxxx     6019303 77-key?

; Unknown keyboard
    mov    a,r7        ; 0136 - a=r7(received data)
    call    X015f        ; 0137 -                                [Set flag]
    jmp    X010b        ; 0139 - <<LOOP receive again

; End
X013b:    retr            ; 013b -



; Set 'index' and 'size' scan code table for each keyboard model
;   r1: end of scan code table(index)
;   r2: number of scan code table(size)
; 6019273 50-key?
X013c:    mov    r1,#0afh    ; 013c - r1=afh     address@page3   03afh(table1)
    mov    r2,#038h    ; 013e - r2=38h     0011 10(00)     56keys
    jmp    X014c        ; 0140 -

; *6019284 62-key*
X0142:    mov    r1,#0efh    ; 0142 - r1=efh     address@page3   03efh(table2)
    mov    r2,#040h    ; 0144 - r2=40h     0100 00(00)     64keys
    jmp    X014c        ; 0146 -

; 6019303 77-key?
X0148:    mov    r1,#0ffh    ; 0148 - r1=ffh     address@page3   03ffh(table2)
    mov    r2,#050h    ; 014a - r2=50h     0101 00(00)     80keys



; get scancode from table and test loop
LOOP>>
X014c:    mov    a,r1        ; 014c - a=r1
    movp3    a,@a        ; 014d - a=(r1)     read scan code table
    xrl    a,r7        ; 014e - a=a^r7     a==r7(received scan code)
    jnz    X0156        ; 014f -

; scan code(a) == received data(r7)
    dec    r2        ; 0151 - r2--
    mov    a,r2        ; 0152 - a=r2
    call    X015f        ; 0153 - call                           [Set flag]
    inc    r2        ; 0155 - r2++

; check next scan code
X0156:    dec    r1        ; 0156 - r1--               r1: address of table
    djnz    r2,X014c    ; 0157 - <<LOOP while --r2  r2: number of table

    jnc    X015d        ; 0159 - jump if r1>=0
    call    X00d8        ; 015b - Error: FD and cont.            [Out of bound Error: FD]
X015d:    jmp    X010b        ; 015d - <<LOOP Receive next data
;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Set flag routine
;
; INPUT: a=table index(number of table)
;        a: AAAA AAFF(AAAAAA:index of parameter RAM, FF: flag position(0-3))
;
X015f:    clr    c        ; 015f - c=0
                                ; calculate RAM address
    mov    r2,a        ; 0160 - r2=a       r2=data
    rr    a        ; 0161 - a=a>>1
    rr    a        ; 0162 - a=a>>1     a/4(four keys per a parameter byte)
    add    a,#022h        ; 0163 - a=a+22h    start of parameter bytes
    mov    r0,a        ; 0165 - r0=a       r0=parameter address

    mov    a,r2        ; 0166 - a=r2
    anl    a,#003h        ; 0167 - a=a&03h            [a=flag position]
    jz    X017e        ; 0169 - if FF==0b00
    dec    a        ; 016b - a--
    jz    X018a        ; 016c - if FF==0b01
    dec    a        ; 016e - a--
    jz    X0197        ; 016f - if FF==0b10

;
; Parameter byte and configure flags
;   bit 7   6   5   4   3   2   1   0
;       3r  3b  2r  2b  1r  1b  0r  0b

;;;;;;;;;;;;;;;;;;
; FF==11b:  3r/3b
    mov    a,@r0        ; 0171 - a=(r0)             r0=parameter address
    anl    a,#03fh        ; 0172 - a=a&0011 1111b     clear 3r/3b
    jf0    X017a        ; 0174 - jump if F0==1
; F0==0(received data:bit7==1)
; a=a|40h
    orl    a,#040h        ; 0176 - a=a|0100 0000b     3b: break enabled



;;;;;;;;;;;;;;;;;;
; store to RAM and return
X0178:    mov    @r0,a        ; 0178 - (r0)=a store parameter to RAM
    ret            ; 0179 - return a: command/received data
; End of Set flag
;;;;;;;;;;;;;;;;;;



; F0==1 (data:bit7==0)
; a=a|80h
X017a:    orl    a,#080h        ; 017a - a=a|1000 0000b     3r: repeat enabled
    jmp    X0178        ; 017c -
;;;


;;;;;;;;;;;;;;;;;;
; FF==00b:  0r/0b
X017e:    mov    a,@r0        ; 017e - a=(r0)
    anl    a,#0fch        ; 017f - a=a & 1111 1100b   clear 0r/0b
    jf0    X0186        ; 0181 - jump if F0==1
; F0==0(data:bit==1)
    inc    a        ; 0183 - a++                0b: break enabled
    jmp    X0178        ; 0184 -
; F0==1(data:bit==0)
X0186:    orl    a,#002h        ; 0186 -                    0r: repeat enabled
    jmp    X0178        ; 0188 -
;;;


;;;;;;;;;;;;;;;;;;
; FF==01b:  1r/1b
X018a:    mov    a,@r0        ; 018a -
    anl    a,#0f3h        ; 018b -                    clear 1r/1b
    jf0    X0193        ; 018d -
; F0==0(data:bit==1)
    orl    a,#004h        ; 018f -                    1b: break enabled
    jmp    X0178        ; 0191 -
; F0==1(data:bit==0)
X0193:    orl    a,#008h        ; 0193 -                    1r: repeat enabled
    jmp    X0178        ; 0195 -
;;;


;;;;;;;;
; FF==10b   parameter|10h / parameter|20h
X0197:    mov    a,@r0        ; 0197 -
    anl    a,#0cfh        ; 0198 -                    clear 2r/2b
    jf0    X01a0        ; 019a -
; F0==0(data:bit==1)
    orl    a,#010h        ; 019c -                    2b: break enabled
    jmp    X0178        ; 019e -
; F0==1(data:bit==0)
X01a0:    orl    a,#020h        ; 01a0 -                    2r: repeat enabled
    jmp    X0178        ; 01a2 -
;;;


;
; End of command FC
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;;;;;;;;;;;;;;;;;;
; read program memory @page1
;   INPUT: a=address of program memory
X01a4:    movp    a,@a        ; 01a4 - a=(a)@page1

;   OUTPUT: r1=r1+a, a=r0
; r1=r1+a,a=r0
X01a5:    add    a,r1        ; 01a5 -
    mov    r1,a        ; 01a6 - r1=a+r1
    mov    a,r0        ; 01a7 - a=r0
    ret            ; 01a8 -



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Scan row8(I) and set parameter flags(on Power on Reset)
;
; call from hard reset 0018h with a=0, r0=0, r1=0?
;   INPUT: r0, r1: for wait loop
;   OUTPUT: $21=keybaord identity bits, r4=$21&f0h
;

;;;;;;;;;;;;;;;;;;
; delay to make Buzzer audible when powering up??
X01a9:    djnz    r0,X01a9    ; 01a9 - r0*2cycle
    djnz    r1,X01a9    ; 01ab - r1*(r0*2cycle+2cycle) 256*(256*2+2)=131584(2us?/cycle) around 260ms??
    anl    bus,#0c0h    ; 01ad - BZ=_,CLK=_,DATA=L  line is idle


;;;;;;;;;;;;;;;;;;
;
; Read keyboard identity bits from row8(I) and set parameter flags(on command FC)
;   INPUT: a=0
;   OUTPUT: r4=a=scanned data of row8(I)=keyboard identity bits
;
;   F0: 1:read(frist)/0:read(second)&settle
;        It needs to read same value twice to settle.
;
;   Keyboar id bit pattern on PCB:
;       mark:       1
;       brank:      0
;   Sensor value meaning:
;       Sensor:     0           1
;       Kbd id:     1(mark)     0(blank)
;       Key:        1(pressed)  0(released)
;
; called from command FC 0107h
X01af:    mov    r7,#008h    ; 01af - r7=08h                 [column]
X01b1:    rl    a        ; 01b1 - a=a<<1 LOOP_0{         [next column]
X01b2:    mov    r4,a        ; 01b2 - LOOP{  r4=a            [data]
    cpl    f0        ; 01b3 - F0=~F0     toggle F0   [read twice to debounce]
    mov    a,r7        ; 01b4 - a=r7
    dec    a        ; 01b5 - a--
    orl    a,#0c0h        ; 01b6 - col(7-0)|c0h = c7-c0h  BZ=H:on [Beep during FC command]
    outl    bus,a        ; 01b8 -                        [Select column]
    orl    bus,#010h    ; 01b9 - D4=1                   [charge sensor out=H?]
    mov    a,#0d2h        ; 01bb - 1101 0010
    outl    bus,a        ; 01bd - bus=d2h   D4-0=10010   select column 2?

;
    orl    p2,#001h    ; 01be - P2:0=1                 [select row8(I)]
    mov    a,r4        ; 01c0 - a=r4(data)
    orl    bus,#008h    ; 01c1 - bus=d2h|08h=dah  D4=1  [Strobe?](1101 1010)
    anl    p2,#000h    ; 01c3 - P2:0=L                 [unselect row8(I)]

; check sensor out(T0)
    jt0    X01d5        ; 01c5 - jump if T0==H
    jf0    X01cd        ; 01c7 - jump if F0==1
    jb0    X01d9        ; 01c9 - jump if a:bit0==1      [Settle]
        ; TO(sensor)==0 && F0==0 && a:bit0==0
    jmp    X01b2        ; 01cb -  }LOOP

; record 1(a=a|01h) when key is on(T0=L) and F0==1
; T0(sensor)==L(off) && F0==1 (from 01c7)
X01cd:    orl    a,#001h        ; 01cd - a=a|1                  [Set a:bit0=H]
    jmp    X01b2        ; 01cf - LOOP

; record 0(a=a&feh) when key is off(T0=H) and F0==0
; T0(sensor)==H(on) && F0==0 && a:bit0==1(off) (from 01d7)
X01d1:    anl    a,#0feh        ; 01d1 - a=a&feh                [Set a:bit0=L]
    jmp    X01b2        ; 01d3 - LOOP

; scan LOOP again
; T0(sensor)==H(on) && F0==1 (from 01c5)
X01d5:    jf0    X01b2        ; 01d5 - LOOP while F0==1

; T0(sensor)==H(on) && F0==0
    jb0    X01d1        ; 01d7 - jump if a:bit0==1 [need to change r4(a) to 0]

; next column
; T0(sensor)==H && F0==0 && a:bit0==0 OR
; T0(sensor)==L && F0==0 && a:bit0==1   (from 01c9)
X01d9:    djnz    r7,X01b1    ; 01d9 - }LOOP_0 while --r7>0 [Next column]
    mov    r4,a        ; 01db - r4=a               a=r4=scanned data of Row8(I)


;;;;;;;;;;;;;;;;;;
;  Set parameters from scanned data of row 8(I)
;
;   INPUT:  a=r4=keyboard identity bits
;   OUTPUT: $21=keybaord identity bits, r4=$21&f0h
;
    anl    a,#0f0h        ; 01dc - a=a&f0h
    xrl    a,#020h        ; 01de - a=a^20h            (a==0010 xxxx)  6019273
    jz    X01ec        ; 01e0 - jump if a==0
    xrl    a,#010h        ; 01e2 - a=a^10h            (a==0011 xxxx) *6019284 when power on reset
    jz    X01f2        ; 01e4 - jump if a==0
    xrl    a,#070h        ; 01e6 - a=a^70h            (a==0100 xxxx)  6019303
    jz    X01f2        ; 01e8 - jump if a==0
    jmp    X01fa        ; 01ea -

; $21==(0010 xxxx)  for 6019273(50-key)
; set break enalbe flag for Reset(or on other layout?)
X01ec:    mov    r0,#022h    ; 01ec -
    mov    @r0,#001h    ; 01ee - $22=1      $22:bit0=break enable falg of ????
    jmp    X01fa        ; 01f0 -

; $21==(0011 0010 | 0100 xxxx)  for 6019284(62-key) or 6019303(77-key) layout
; set break enable flag for LAlt and RAlt *6019284
X01f2:    mov    r0,#02eh    ; 01f2 -
    mov    @r0,#001h    ; 01f4 - $2e=1      $2e:bit0=break enable flag of LAlt
    mov    r0,#024h    ; 01f6 -
    mov    @r0,#001h    ; 01f8 - $24=1      $24:bit0=break enable flag of RAlt

; set $21 to scanned data of row 8(I)   [keyboard identity bits]
X01fa:    mov    r0,#021h    ; 01fa -
    mov    a,r4        ; 01fc -
    mov    @r0,a        ; 01fd - ($21)=r4     $21: r4=identity bits(row 8(I))
    anl    a,#0f0h        ; 01fe -
    mov    r4,a        ; 0200 - r4=r4&f0h
    ret            ; 0201 -
;
; End of Scan row8(I)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Test and clear memory(3fh..00h) on Power on Reset
;
X0202:    mov    r0,#03fh    ; 0202 -  $3f
X0204:    mov    a,@r0        ; 0204 -  LOOP>>
    mov    r1,a        ; 0205 -  r1=(r0) r0=3f..00
    mov    a,#0ffh        ; 0206 -  a=ffh
    mov    @r0,a        ; 0208 -  (r0)=ffh
    xrl    a,@r0        ; 0209 -  a=a^ffh =0??
    jnz    X0224        ; 020a -  jump if a!=ffh    *always should be a=zero*
    mov    @r0,a        ; 020c -  (r0)=a    (=0)
    mov    a,@r0        ; 020d -  a=(r0)
    jnz    X0224        ; 020e -  jump if a!=ffh    *always should be a=zero*
    mov    a,r1        ; 0210 -  a=r1
    mov    @r0,a        ; 0211 -  (r0)=a (revert to origin value)
    djnz    r0,X0204    ; 0212 -  <<LOOP --r0

;
; Test program memory(0,255..1 @page0,1,2,3)
;
; INPUT: r0=0 r4=??
; OUTPUT: r4=$21&07h|50h, a=swapHL(r4(original)) or feh
X0214:    mov    a,r0        ; 0214 -  LOOP>>   a=r0=0
    call    X0029        ; 0215 -  r1=r1+(a), a=r0 (page0)
    call    X01a4        ; 0217 -  r1=r1+(a), a=r0 (page1)
    movp    a,@a        ; 0219 -
    call    X01a5        ; 021a -  r1=r1+(a), a=r0 (page2)
    movp3    a,@a        ; 021c -
    call    X01a5        ; 021d -  r1=r1+(a), a=r0 (page3)
    djnz    r0,X0214    ; 021f -  <<LOOP --r0
    mov    a,r1        ; 0221 -  a=r1  sum of program memory data
    jz    X0226        ; 0222 -  sum of program memory data != 0 if no error ???

; Send FE on error and r4 on success
X0224:    mov    r4,#0efh    ; 0224 -  r4=efh    Memory error
X0226:    call    X0020        ; 0226 -  r4=$21&07h|50h, a=r4(keyboard id or efh)
    swap    a        ; 0228 -  swap a:h<->a:l
    orl    a,#0a0h        ; 0229 -  a=a|a0h(1010 iiii)    i:keyboard id(hi-bits)
    call    X0339        ; 022b -  queue data(a) to buffer
    call    X010b        ; 022d -  send kbd ID and wait for data from host   [FC command]
    strt    t        ; 022f -  start timer
; Usually first data form keyboard at startup is A3h(sum of program memory?).
; FEh for memory error??
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Main??
;
; check scan code buffer to send
X0230:    call    X002c        ; 0230 - receive/send data
    mov    a,r6        ; 0232 - a=r6 set by command FD Short Beep(0bh at 00edh)
    jz    X023d        ; 0233 -
    djnz    r6,X023d    ; 0235 - r6--
; Buzzer off
    anl    bus,#07fh    ; 0237 - BZ=L(off)   when get to r6==0  [Short Beep ends]
    mov    a,r4        ; 0239 -
    anl    a,#07fh        ; 023a -
    mov    r4,a        ; 023c - r4=r4&7fh(BZ=L:off) r4=bus-default

; delay for scan    192*32cycle?
X023d:    mov    a,t        ; 023d - a=t(timer)
    add    a,#064h        ; 023e - a=a+64h
    jnc    X023d        ; 0240 - delay for scan
    clr    a        ; 0242 - a=0
    mov    t,a        ; 0243 - t=0    timer clear

; Start matrix scan
; r7=r4&c0h
X0244:    mov    a,r4        ; 0244 - a=r4
    anl    a,#0c0h        ; 0245 - a=a&c0h        BZ=_,CLK=_,DAT=L:
    mov    r7,a        ; 0247 - r7=r4&c0h      r7=bus-current
    jf1    X0253        ; 0248 - jump if F1==1 (p1/p2)

; F1==0
    cpl    f1        ; 024a - F1=1(=~F1)
    mov    r2,#03fh    ; 024b - r2=3fh         scan code seed
    mov    r3,#001h    ; 024d - r3=01h         row mask
    mov    r1,#015h    ; 024f - r1=15h         last key state
    jmp    X0263        ; 0251 - scan matrix p1 row

; F1==1
X0253:    clr    f0        ; 0253 - F0=0
    clr    f1        ; 0254 - F1=0
    mov    r2,#077h    ; 0255 - r2=77h         scan code seed
    mov    r3,#002h    ; 0257 - r3=02h
    mov    r1,#01ch    ; 0259 - r1=1ch         last key state
    jmp    X0287        ; 025b - Scan matrix p2 row
;
; INPUT:    F1=0
X025d:    cpl    f1        ; 025d - F1=~F1=1
    call    X002c        ; 025e - receive/send data
    clr    f1        ; 0260 - F1=0
    jmp    X0244        ; 0261 -

;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; scan matrix p1 row
; INPUT: F1=1, r1=15h, r2=3fh, r3=01h, r7=r4&c0h
;       (r1): last state
;
; r0:col, r7:bus-current, r3:row(drive H), r4=bus-default
;
; $15: bit7
;
; bus:  xxxS Gccc
;
X0263:    mov    a,#008h        ; 0263 - a=8 LOOP>>>
    mov    r0,a        ; 0265 - r0=08h =column
    orl    a,r7        ; 0266 - a=08h|r7
    mov    r7,a        ; 0267 - r7=a     =xxxx  1ccc(G:1 column:ccc) r7=P1 value
X0268:    dec    r7        ; 0268 - LOOP>> r7--
    mov    a,r7        ; 0269 - a=r7
    outl    bus,a        ; 026a -                        [select column]
    orl    bus,#010h    ; 026b - sensor out=H           [sensor clamp=H]???
    mov    a,r3        ; 026d - a=r3                   current row
    outl    p1,a        ; 026e - drive line with H      [select row]
    mov    a,r4        ; 026f - a=r4                   bus default value
    outl    bus,a        ; 0270 -                        [revert bus default]
    orl    bus,#008h    ; 0271 - D3:H sensor-G          [strobe]??? hold? clean Sensor?
    anl    p1,#000h    ; 0273 -                        [unselect row]

    jnt0    X02ab        ; 0275 - sensor out==0
; Sensor==1[key is on]
    mov    a,@r1        ; 0277 - a=$(r1); r1=15...  last key state
    jb7    X02e5        ; 0278 - jump if a:bit7==1(off) press
; a:bit7==0(last key state is on)  same as last
;On->On


; Go to next column
X027a:    rl    a        ; 027a - a=a<<1
    mov    @r1,a        ; 027b - (r1)=a; (r1)=(r1)<<1   next col of last key state
X027c:    dec    r2        ; 027c - r2--                   [key index of scan code table]
    djnz    r0,X0268    ; 027d - <<LOOP(8)              [next col]

    dec    r1        ; 027f - r1--   15,14,13,12,11,10,0F,0E? [last key state]
    mov    a,r3        ; 0280 -
    rl    a        ; 0281 -
    mov    r3,a        ; 0282 - r3=r3<<1 next row
    jb0    X0230        ; 0283 - jump if a:bit0==1  scan end(goto Main loop)
    jmp    X0263        ; 0285 - <<<LOOP                [next row]


;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Scan matrix p2 row(F1==1)
; INPUT: F0=0, F1=0, r1=1ch, r2=77h, r3=02h, r7=bus-current, r4=bus-default
;
; r0:col, r7:bus-current, r3:row(drive H), r4=bus-default
;   key index: 77h-
X0287:    mov    a,#008h        ; 0287 - a=8    LOOP>>
    mov    r0,a        ; 0289 - r0=8
    orl    a,r7        ; 028a - a=a|r7
    mov    r7,a        ; 028b - r7=a
X028c:    dec    r7        ; 028c - r7-- LOOP>>
    mov    a,r7        ; 028d - a=r7
    outl    bus,a        ; 028e -                        [select column]
    mov    a,r4        ; 0293 -                        bus default value
    outl    bus,a        ; 0294 -                        [revert bus default]
    orl    bus,#008h    ; 0295 -                        [strobe]
    anl    p2,#000h    ; 0297 - p2=00h                 [unselect row]
    jnt0    X02ab        ; 0299 - jump if sensor out==0(key is on)
; sensor==1(key is off)
    mov    a,@r1        ; 029b - a=(r1)                 [last key state]
    jb7    X02e5        ; 029c - jump if a:bit7==1(off)  press

; a:bit7==0(last key state is on)
X029e:    rl    a        ; 029e - a=a<<1
    mov    @r1,a        ; 029f - (r1)=a                 [next last key bit]
X02a0:    dec    r2        ; 02a0 - r2--(77h)
    djnz    r0,X028c    ; 02a1 - jump if r0--!=0 <<LOOP(8)
    dec    r1        ; 02a3 - r1--                   [next last key byte]
    mov    a,r3        ; 02a4 -
    rl    a        ; 02a5 -
    mov    r3,a        ; 02a6 - r3=r3<<1   [next row]??
    jb0    X025d        ; 02a7 -
    jmp    X0287        ; 02a9 - <<LOOP

;
; debouncing and change last key state
;
; sensor out==0(press; key is on)
;
; debouncing
X02ab:    call    X030d        ; 02ab - a=0(sensor out=1), ffh(sensor out=0)   [Sense key]
    jz    X02f8        ; 02ad - if a==0(key is off)
    call    X030d        ; 02af -                                        [Sense key]
    jz    X02f8        ; 02b1 - if a==0(key is off)

; Sensor==0(a=ffh; press)
    mov    a,@r1        ; 02b3 - a=(r1) last key state????
    jb7    X02ca        ; 02b4 -

;
; [release](off->on)
;
; last:bit7==0(off) && sensor=0(on)
    orl    a,#080h        ; 02b6 - 0:on   1:off
    rl    a        ; 02b8 -
    mov    @r1,a        ; 02b9 - (r1)=(r1)<<1   next column
    call    X0325        ; 02ba - key configure flag
                                ;        (a:bit1=repeat enable, a:bit0=break enable)
; if keyconf:bit0==1 then set release flag
    jb0    X02fd        ; 02bc - r2=r2|80h          [press flag]
; if keyconf:bit1==1 then set repeat
    jb1    X02e1        ; 02be - r5=repeat delay    [repeat]

; get scan code and queue it into buffer
X02c0:    call    translate034E    ; 02c0 - a=scancode
    call    X0339        ; 02c2 - queue data to buffer
    call    X0303        ; 02c4 -                    [r1=a=address of last key state]
X02c6:    jf1    X027c        ; 02c6 - next col(F1==1)
    jmp    X02a0        ; 02c8 - next col(F1==0)

;
; [hold key]
;
; last key is on and sensor==0(on)     (on->on)
X02ca:    rl    a        ; 02ca -
    mov    @r1,a        ; 02cb - (r1)=(r1)<<1
    call    X0325        ; 02cc - key configure flag
                                ;        (a:bit1=repeat enable, a:bit0=break enable)
; repeat:flag
    jb1    X02d4        ; 02ce -                    [repeat]

; if repeat:flag(bit1)==0  (no repeat)
X02d0:    call    X0303        ; 02d0 - r1=r2&0fh+0eh      address of last key state
    jmp    X02c6        ; 02d2 - goto next col

; if flag:bit1==1  (repeat)
X02d4:    jf0    X02dd        ; 02d4 -

; F0==0
    cpl    f0        ; 02d6 - F0=~F0=1
    djnz    r5,X02d0    ; 02d7 -
    mov    r5,#007h    ; 02d9 - r5=07h             repeat interval
    jmp    X02c0        ; 02db - send scan code

; F0==1
X02dd:    mov    r5,#028h    ; 02dd - r5=28h             repeat delay(for first repeat)
    jmp    X02d0        ; 02df -
;
X02e1:    mov    r5,#028h    ; 02e1 - r5=28h             repeat delay(for first repeat)
    jmp    X02c0        ; 02e3 - send scan code


;
; debouncing and change last key state: press
;
;   INPUT: (r1): last key status
;
; (r1):bit7==1(last key is on) &&  Sensor==1(key is off)  [release]
X02e5:    call    X030d        ; 02e5 - a=0(sensor out=1), ffh(sensor out=0)   [Sense key]
    jnz    X02f8        ; 02e7 -
    call    X030d        ; 02e9 -                                        [Sense key]
    jnz    X02f8        ; 02eb - \_debouncing
; Sensor==1(a=0)                                                                [Debounced]

;
; on->off [release]
;
    mov    a,@r1        ; 02ed - a=(r1) RAM
    anl    a,#07fh        ; 02ee - a=a&7fh        last state=0(0:on 1:off)
    rl    a        ; 02f0 - a=a<<1
    mov    @r1,a        ; 02f1 - (r1)=a
;
    call    X0325        ; 02f2 - key configure flag
                                ;        (a:bit1=repeat enable, a:bit0=break enable)
    jb0    X02c0        ; 02f4 - goto translate if a:bit0==1
    jmp    X02d0        ; 02f6 -

; go to next col scan   Sensor==1
X02f8:    mov    a,@r1        ; 02f8 -
    jf1    X027a        ; 02f9 - goto next col scan(p1) if F1==1        [Next column]
    jmp    X029e        ; 02fb - goto next col scan(p2) else            [Next column]

;
; add press flag(bit8)
; r2=key index
X02fd:    mov    a,r2        ; 02fd -                                        [key index]
    orl    a,#080h        ; 02fe -
    mov    r2,a        ; 0300 - r2=r2|80h  **press flag**
    jmp    X02c0        ; 0301 -

; Address of last key state
; INPUT: r2=key index
; OUTPUT: r1=(r2>>3)&0fh+0eh    = address of last key state
X0303:    mov    a,r2        ; 0303 - a=r2   key index
    rr    a        ; 0304 -
    rr    a        ; 0305 -
    rr    a        ; 0306 - a= a>>3
    anl    a,#00fh        ; 0307 - a= a & 0fh
    add    a,#00eh        ; 0309 - a= a + 0eh
    mov    r1,a        ; 030b - r1=a
    ret            ; 030c -

;;;;;;;;;;;;;;;;;;;;;;;
; Sense key
;   INPUT: r7: bus-current, F1:0(p2),1(p1) r4=bus-default, r3=row
;   RETURN: a=0xff(sensor out=0, press), 0(sensor out=1, release)
;
X030d:    mov    a,r7        ; 030d - r7: bus-current
    outl    bus,a        ; 030e -                            [Select column]
    orl    bus,#010h    ; 030f -                            [Charge: D4]
    mov    a,r3        ; 0311 - r3: row(drive) select      p1(F1=1)/p2(F1=0) setting
    jf1    X0317        ; 0312 -
; F1==0
    outl    p2,a        ; 0314 - set p2                     [Select row]
    jmp    X0318        ; 0315 -
; F1==1
X0317:    outl    p1,a        ; 0317 - set p1                     [Select row]

X0318:    mov    a,r4        ; 0318 - r4: bus-default
    outl    bus,a        ; 0319 - set bus
    clr    a        ; 031a - a=0
    orl    bus,#008h    ; 031b -                            [Strobe: D3]
    anl    p1,#000h    ; 031d - clear p1                   [Unselect row]
    anl    p2,#000h    ; 031f - clear p2                   [Unselect row]

    jt0    X0324        ; 0321 - sensor out==1
sensor out==0
    cpl    a        ; 0323 -  a=0xff                    [press(on)]
sensor out==1
X0324:    ret            ; 0324 -  a=0                       [release(off)]
;
; End of Main
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; key configure flags
;
; INPUT: r2=key index(p1:-3fh, p2:-77h)    (aaaaaaii)
: OUTPUT: a=Key configure 2-bit flags;  bit0 and 1 are only valid. (------rb)
;
:   Key configure flags are retained in RAM($22-3F) and
;   Key configure flags use 2bit per key so that a byte can has flags of four key like:
;       bit 7   6   5   4   3   2   1   0
;           3r  3b  2r  2b  1r  1b  0r  0b
;   where r=repeat enable, b=break code(release) eanble
;
X0325:    mov    a,r2        ; 0325 - a=r2           index
    rr    a        ; 0326 -
    rr    a        ; 0327 - a=a>>2         bit7-2 of index(aaaaaa)
    add    a,#022h        ; 0328 - a=a+22h        $22+aaaaaa
    mov    r1,a        ; 032a - r1=a
    mov    a,@r1        ; 032b - a=(r1)         $22-3F(ignored bit7,bit6)
    mov    r1,a        ; 032c - r1=a           r1=($22-3F) ????
    mov    a,r2        ; 032d - a=r2           index
    anl    a,#003h        ; 032e - a=a&03h        a=bit0,bit1 of index
    xch    a,r1        ; 0330 - a<->r1         r1=bit0,bit1 of index, a=($22-3F)
    inc    r1        ; 0331 - r1++           =1-4
X0332:    djnz    r1,X0335    ; 0332 - while --r1>0
    ret            ; 0334 -

; place flags of the key on bit0 and 1
X0335:    rr    a        ; 0335 -
    rr    a        ; 0336 - a=a>>2; a=$22-3F
    jmp    X0332        ; 0337 -

;
; Queue data to bottom of outgoing buffer(bank1:r5,r6,r7)
; INPUT: a=data, r2=???
; OUTPUT: r2=r2&07h
; a->r5->r6->r7
X0339:    sel    rb1        ; 0339 -   switch to bank1
    inc    a        ; 033a -   a++
    xch    a,r5        ; 033b -   a<->r5
    jz    X0348        ; 033c -
    xch    a,r5        ; 033e -
    xch    a,r6        ; 033f -
    jz    X0348        ; 0340 -
    xch    a,r6        ; 0342 -
    xch    a,r7        ; 0343 -
    jz    X0348        ; 0344 -
    mov    r7,#0ffh    ; 0346 -   buffer overflow
X0348:    sel    rb0        ; 0348 -   switch to bank0
    mov    a,r2        ; 0349 -   a=r2
    anl    a,#07fh        ; 034a -   a=a&7fh
    mov    r2,a        ; 034c -   r2=a
    ret            ; 034d -
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Translate key index into scancode
;
; INPUT: r2=keyindex [bit7:release flag(1:release/0:press), bit6-0:index]
; OUTPUT: a=scancode
translate034E:
    mov    r1,#021h    ; 034e -
    mov    a,@r1        ; 0350 - a=$21  $21:bit6,5,4 = traslate table
    anl    a,#0f0h        ; 0351 - a=a & f0h
    xrl    a,#020h        ; 0353 - a=a ^ 20h      $21:bit5(0010 0000) 0010 xxxx => table1
    jz    X0361        ; 0355 - if a==0        read table1     (6019273 50-key)
    xrl    a,#010h        ; 0357 - a=a ^ 10h      $21:bit4(0001 0000) 0011 xxxx => table2
    jz    X0370        ; 0359 -                read table2     (6019284 62-key)
    xrl    a,#070h        ; 035b - a=a & 70h      $21:bit6(0111 0000) 0100 xxxx => table2
    jz    X0370        ; 035d -                read table2     (6019303 77-key)
    mov    a,r2        ; 035f -                else use r2(keyindex) instead of scancode
    ret            ; 0360 -
; table1(8x7=56)
X0361:    mov    a,r2        ; 0361 - keyindex
    anl    a,#07fh        ; 0362 -
    add    a,#078h        ; 0364 - table1
; read table
X0366:    movp3    a,@a        ; 0366 - read scancode from table a=scan code
    xch    a,r2        ; 0367 - a=keyindex, r2=scancode
    jb7    X036c        ; 0368 - if keyindex:bit7==1 [relase event]
    xch    a,r2        ; 036a - a=scancode, r2=keyindex
    ret            ; 036b -
; release flag
X036c:    xch    a,r2        ; 036c -
    orl    a,#080h        ; 036d - [[[[[release flag(bit7)]]]]]
    ret            ; 036f - a: scan code
; table2(8X10=80)
X0370:    mov    a,r2        ; 0370 -
    anl    a,#07fh        ; 0371 -
    add    a,#0b0h        ; 0373 - table2
    jmp    X0366        ; 0375 - read table


; maybe 'salt' to make sum of program memory 'zero'(at 0222h)
    db    0b6h                    ; 0377 6


;;;;;;;;;;;;;;;;;;
;
; Scancode table
;

;;;;;;;;;;;;;;;;;;
; Used for 6019273                                        Add  Key              Parameter RAM
table1:    db    03fh,037h,03ah,036h,02ah,035h,022h,023h    ; 0378
    db    03bh,02bh,039h,031h,032h,029h,021h,0ffh    ; 0380
    db    033h,038h,0ffh,030h,028h,0ffh,020h,0ffh    ; 0388
    db    017h,01dh,01ch,015h,00ch,00dh,004h,005h    ; 0390
    db    00fh,01fh,01bh,013h,014h,00bh,003h,0ffh    ; 0398
    db    00eh,01ah,019h,012h,009h,00ah,001h,002h    ; 03a0
    db    016h,01eh,018h,010h,011h,008h,000h,0ffh    ; 03a8

;;;;;;;;;;;;;;;;;;
; Used for 6019284 and 6019303                            Add  Key              Parameter RAM
table2:    db    02fh,03dh,03ch,02dh,01dh,01ch,00ch,00eh    ; 03b0 Enter ... BS     $22, $23
    db    03fh,042h,03bh,02bh,02ch,01bh,01fh,00dh    ; 03b8 RAlt ...         $24, $25
    db    039h,03ah,029h,02ah,002h,003h,00ah,00fh    ; 03c0 ...              $26, $27
    db    038h,037h,028h,027h,017h,001h,008h,009h    ; 03c8 ...              $28, $29
    db    040h,036h,025h,026h,015h,016h,011h,012h    ; 03d0 ...              $2a, $2b
    db    035h,034h,023h,024h,013h,014h,01ah,010h    ; 03d8 ...              $2c, $2d
    db    03fh,032h,033h,022h,021h,006h,005h,019h    ; 03e0 LAlt ...         $2e, $2f
    db    031h,041h,03eh,030h,020h,004h,000h,018h    ; 03e8 Reset ... 1      $30, $31
    db    071h,076h,075h,066h,055h,056h,045h,046h    ; 03f0 Used for 77-key  $32, $33
    db    077h,067h,074h,064h,065h,054h,0ffh,044h    ; 03f8 Used for 77-key  $34, $35
;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



;
;    symbol equates
;
;  these are symbols from the control
;  file that are referenced in the code
;
jump_table    equ    0fah
;
    end
