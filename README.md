# CS480_Calculator
Simple expression based calculator created for CS480 using C++ and QT.

Built with QT Creator 4.7.2 and QT 5.11.2.
Tested and working on both Windows 10 and Ubuntu 16.04.

The easiest way to build this program is to install QT Creator and open the included *.pro file.T
While installing QT creator make sure to install the MinGW compiler (Windows) or the GCC compiler (Linux).

On my Ubuntu machine I also had to install another dependency to get it to build.
If you get a "cannot find -lGL" error, run the following command in a terminal:

sudo apt install libgl1-mesa-dev
