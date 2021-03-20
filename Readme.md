# Serial-to-Morse code for RP2040

This is a demo program, to explore the RP2040 (aka "the pico").
The program will make the RP2040 convert serial text input into morse code and send the morse code with its on-board LED.

The serial text will be read from USB. It is possible to adjust the [CMakeLists.txt](CMakeLists.txt) and have the serial text come from UART.

* Morse implementation based on https://github.com/raspberrypi/pico-examples/blob/master/picoboard/blinky/blinky.c
* RP2040 on board led blinking based on https://github.com/raspberrypi/pico-examples/blob/master/blink/blink.c
* USB serial input based on https://github.com/raspberrypi/pico-examples/blob/master/hello_world/usb/hello_usb.c

The how to's below are opinnionated to make them short and useful: There are alternatives available in the [RP2040 Getting started guide](https://datasheets.raspberrypi.org/pico/getting-started-with-pico.pdf).

# How to run

* Connect a RP2040 over USB to your computer while holding down the BOOTSEL button.
  A USB drive will appear to be connected to your computer.
* Drag and drop the [morse.uf2](https://github.com/berikv/pico-morse/releases/latest/download/morse.uf2) file onto the USB drive.
  The RP2040 will reboot and start running the morse program.
  Your system will tell you that you didn't properly disconnect the USB drive. Don't worry about that, the data was saved correctly.
  When the morse program is running, the RP2040 will show up as a serial modem over USB.
* Write data to the USB serial modem.
  On MacOS: `echo "Hello world in morse" > /dev/cu.usbmodem0000000000001`


# How to build

Instructions for MacOS:

* Install homebrew if you didn't yet
* Run `brew install arm-none-eabi-gcc`
* Download VSCode if you don't have it yet
* Enable the command line `code` command for launching VSCode
* Install the CMake Tools, C/C++ IntelliSense and optionally the cortex-debug extensions for VSCode.
This can be done in VSCode itself, or from the command line.

```
 code --install-extension marus25.cortex-debug
 code --install-extension ms-vscode.cmake-tools
 code --install-extension ms-vscode.cpptools
```
* Run `git clone -b master https://github.com/raspberrypi/pico-sdk.git`
* Open VSCode using the shell command `PICO_SDK_PATH=$(pwd)/pico-sdk code`
* Open the project directiory using VSCode
* Select "Configure project" when asked
* Select "GCC for arm-none-eabi" as the "active kit"
* Hit Build, this will generate the morse.uf2 file in the build folder
* Install the morse.uf2 using the instructions above
