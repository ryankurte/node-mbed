# Node-MBed

MBed OS Based Sensor/Actuator Node Application

## Getting started

### Requirements

Can be installed with your favourite package manager (brew/apt/yum etc.)

- [arm-none-eabi-gcc](https://developer.arm.com/open-source/gnu-toolchain/gnu-rm/downloads)
- [cmake](https://cmake.org/)
- [python](https://cmake.org/)
- [virtualenv](https://virtualenv.pypa.io/en/stable/)
  - [mbed-cli](https://github.com/ARMmbed/mbed-cli)

This project uses virtualenv to mitigate janky af python packaging of mbed-cli, this is checked into the repository and contains the mbed-cli and all python dependencies.

To launch the local virtual environment run `. ./venv/bin/activate`, to exit run `deactivate`.

### Building

Check out the [makefile](makefile) for helper commands.

The WSTK boards do not appear to have support for the mbed IDE, so for now programming is via a set of jlink scripts exposed via the makefile.

### Resources

- https://github.com/ARMmbed/mbed-os-example-client


