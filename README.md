# A sample mruby/c project for Raspberry Pi Pico


### Getting started

- Setup Raspberry Pi Pico C/C++ SDK
  - Install mrbc by `rbenv install mruby-3.3.0`

  - Follow the instructions on [https://github.com/raspberrypi/pico-sdk#quick-start-your-own-project](https://github.com/raspberrypi/pico-sdk#quick-start-your-own-project)
    - Make sure you have `PICO_SDK_PATH` environment variable

  - Be knowledgeable how to install a UF2 file into Raspi Pico on [https://www.raspberrypi.org/documentation/rp2040/getting-started/#getting-started-with-c](https://www.raspberrypi.org/documentation/rp2040/getting-started/#getting-started-with-c)

  - [https://learn.sparkfun.com/tutorials/pro-micro-rp2040-hookup-guide](https://learn.sparkfun.com/tutorials/pro-micro-rp2040-hookup-guide) will also help you if you use Sparkfun Pro Micro RP2040

- Clone this repository

    ```
    git clone --recursive https://github.com/hasumikin/mrubyc-pico.git # Don't forget --recursive
    cd mrubyc-pico
    ```

- Build with `cmake` and `make`

    ```
    cd build
    cmake ..
    # cmake -DCMAKE_BUILD_TYPE=Debug .. # You can debug with picoprobe
    make
    ```

    Now you should have `l-chika.uf2` file in `build/` directory.

### "l-chika" ?

It means "LED blinking" in Japanese.

### Acknowledgement

This project is a successor of [aikawaYO/mrubyc-pico](https://github.com/aikawaYO/mrubyc-pico) which used mruby/c version 2.x.

### Contributing

Fork, clone, patch and send a pull request.

### License

MIT License.
