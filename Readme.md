# Serial-to-Morse code for RPi2040

This program takes text from the stdin, converts it to Morse code and blinks the on board LED of the RPi2040 based on the given text.

The stdin will be read its data from USB. It is possible to adjust the [CMakeLists.txt](CMakeLists.txt) and have the serial data come from UART.

* Morse implementation based on https://github.com/raspberrypi/pico-examples/blob/master/picoboard/blinky/blinky.c
* RPi2040 on board led blinking based on https://github.com/raspberrypi/pico-examples/blob/master/blink/blink.c
* USB serial input based on https://github.com/raspberrypi/pico-examples/blob/master/hello_world/usb/hello_usb.c

The how to's below are opinnionated to make them short and useful. There are countless alternatives, this gets you going the fastest.

# How to run

* Connect a RPi2040 over USB to your computer while holding down the BOOTSEL button.
  A USB drive will appear to be connected to your computer.
* Drag and drop the morse.uf2 file onto the USB drive.
  Get the morse.uf2 file from the [latest release](https://github.com/berikv/pico-morse/releases/latest/download)
  The RPi2040 will reboot and start running the morse program.
  Your system will tell you that you didn't properly disconnect the USB drive. Don't worry about that, the data was saved correctly.
  When the morse program is running, the RPi2040 will show up as a serial modem over USB.
* Write data to the USB serial modem.
  On MacOS `echo "Hello world in morse" > /dev/cu.usbmodem0000000000001`
  On Linux `echo "Hello wordl in morse" > /dev/ttyACM0`

# How to build

* Install homebrew if you didn't yet
* Run `brew install arm-none-eabi-gcc`
* Download VSCode if you don't have it yet
* Install the CMake Tools, C/C++ IntelliSense and optionally the cortex-debug extensions for VSCode.
This can be done in VSCode itself, or from the command line.

    code --install-extension marus25.cortex-debug
    code --install-extension ms-vscode.cmake-tools
    code --install-extension ms-vscode.cpptools

* Open the project directiory with VSCode
* Select "Configure project" when asked
* Select "GCC for arm-none-eabi" as the "active kit"
* Hit Build, this will generate the morse.uf2 file build in the build folder
