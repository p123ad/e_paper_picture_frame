# Battery Operated E-Paper Picture Frame

## Table of Contents

- [About](#about)
- [Getting Started](#getting_started)
- [BOM](#bom)
- [Printed Parts](#printed_parts)
- [Mechanical Build](#mechanics)
- [Electrical Build](#electronics)
- [Preparing the pictures](#pictures)
- [Code](#code)
- [Ressources](#ressources)

## About <a name = "about"></a>

This is a project in progress creating a battery operated digital picture frame. I hated the hassel with commercial digital picture frames which are only showing pictures while connectd to mains. So it was down for most of the time showing a black screen.
My goal was to design a concept for a digital picture frame with very low power consumption. So the choice fell towards a esp32 board with a very low deep sleep current, together with a low power E-paper display, which only consumes power during picture change.

## Getting Started <a name = "getting_started"></a>

The Firebeetle ESP32 has a deep sleep current of only 0.053mA according to great research of [The guy with the swiss accent](https://docs.google.com/spreadsheets/d/1Mu-bNwpnkiNUiM7f2dx8-gPnIAFMibsC2hMlWhIHbPQ/edit#gid=0)

## BOM <a name = "bom"></a>

| Count | Part  | Cost  |
|---|---|---|
| 1 | [E-Paper Display](https://www.waveshare.com/7.5inch-hd-e-paper-hat.htm)  | 60.99$  |
| 1 | [Picture Frame](https://www.nanu-nana.de/bilderrahmen-classic-15-x-20-cm-eiche-2002262014571/)  |  4.95€ |
| 1 |  [LiPo 3.7V](https://www.welectron.com/LiPo-Flachakku-503562-37V-1200mAh)  | 5.50€  |
| 1 | [Firebeetle ESP32](https://www.dfrobot.com/product-1590.html) | 6.90$ |
| 1 | Brass Screw | ~ 1€ |
| 4 | M2x4mm Screws |  |
| 4 | M2x8mm Screws |  |
| 8 | [M2 Threaded Inserts](https://www.amazon.de/gp/product/B08K1BVGN9/ref=ppx_yo_dt_b_asin_title_o04_s00?ie=UTF8&th=1) |  |

## Printed Parts <a name = "printed_parts"></a>

I printed the parts in wooden PLA filament on my Prusa Mini.

| Count | Part |
| --- | --- |
| 1 | Back |
| 1 | Passepartout |
| 2 | Stand |
| 1 | Lid |

## Mechanical Build <a name = "mechanics"></a>

First solder a wire together with the brass screw. This can be very tricky because of the high temperature needed.
If you struggle, an idea is to drill a 1.5-2.0mm hole into the screw. Add solder to the hole and heat it up so you can put the wire into the hole with the hot solder.
Drill a hole with a 4.5mm drill bit into the frame where you want to place the button-screw.

## Electrical Build <a name = "electronics"></a>

Connect the ESP board according to the wiring sketch 

## Preparing the Pictures <a name = "pictures"></a>

Since the E-paper Display only allows Pictures with a resolution of 880x528px with only black and white pixels you have to edit your pictures according these constraints. You find a reference from waveshare [here](https://www.waveshare.com/wiki/E-Paper_Floyd-Steinberg)
I will give a short step-by-step instruction of the process, which worked for me.

1. Install [GIMP](https://www.gimp.org/)
2. Open GIMP
3. Drag and Drop a Picture (.jpg) into the GIMP Workspace
4. Layer -> Scale layer... → set to 880px
5. Layer -> Scale Height.. -> set to 528px
6. Image → Crop to content
7. Colors → Desaturate → Desaturate ...
8. Colors → Posterize → 16 levels (optional)
9. Image → Mode → Indexed ... → Use black/white palette (1-bit)
10. Dithering → Color dithering: Floyd-Steinberg (normal) → Convert
11. File → Export to ... → Append .bmp extension → Export
12. Use [this tool](https://javl.github.io/image2cpp/) to convert your .bmp files to cpp byte code. Set the code output mode to Arduino Code
13. Copy the byte code to your Arduino project

## Code <a name = "code"></a>

Open the main.ino file with your Arduino IDE. There should be a few tabs. Each picture has to prepared according to the example picture in a `.c` and a `.h` file. Then the include path has to be added to `Picutes.h`.
Please also look through the `main.ino` file and change the code according to the names and numers of your pictures.

## Ressources <a name = "ressources"></a>

There are many ohter cool e-paper based picture frame projects out there which have many other special features. My work was also inspired by them. But my focus was to build a very low power consuming project to have it battery operated.

1. [E-Paper Picture that changes for my Mother](https://www.youtube.com/watch?v=YawP9RjPcJA)
2. [E-Ink Photo Frame using Raspberry Pi](https://www.youtube.com/watch?v=K_ueApCixTA)
3. [ESP32 E-Paper Frame](https://github.com/dani3lwinter/ESP32_ePaper_Frame)