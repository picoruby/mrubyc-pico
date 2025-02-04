# A sample mruby/c project for Raspberry Pi Pico


## Getting started

- Setup Raspberry Pi Pico C/C++ SDK

  - Follow the instructions on [https://github.com/raspberrypi/pico-sdk#quick-start-your-own-project](https://github.com/raspberrypi/pico-sdk#quick-start-your-own-project)
    - Make sure you have `PICO_SDK_PATH` environment variable

  - [https://learn.sparkfun.com/tutorials/pro-micro-rp2040-hookup-guide](https://learn.sparkfun.com/tutorials/pro-micro-rp2040-hookup-guide) will also help you if you use Sparkfun Pro Micro RP2040

- Install mrbc (mruby compiler)

    ```console
    rbenv install mruby-3.3.0
    ```

- Clone this repository

    ```console
    git clone --recursive https://github.com/picoruby/mrubyc-pico.git # Don't forget --recursive
    cd mrubyc-pico
    ```

- Build with `cmake` and `make`

    ```console
    cd build
    cmake ..
    # cmake -DCMAKE_BUILD_TYPE=Debug .. # You can debug with picoprobe
    make
    ```

    Now you should have `l-chika.uf2` file in `build` directory.

- Install

    - Connect a USB cable to Raspi Pico while pressing BOOTSEL button
    - You'll find `RPI-RP2` drive mounted in your PC's filer
    - Drag and drop `l-chika.uf2` into the drive
    - The LED on the Pico will start blinking. If not, you missed something

## "l-chika" ?

It means "LED blinking" in Japanese.

## Acknowledgement

This project is a successor of [aikawaYO/mrubyc-pico](https://github.com/aikawaYO/mrubyc-pico) which used mruby/c version 2.x.

## Contributing

Fork, clone, patch and send a pull request.

## License

MIT License.
