# CS480_Calculator


### Description


Simple expression based calculator created for CS480 using C++ and QT.


---
### Build Instructions


Built with QT Creator 4.7.2 and QT 5.11.2.
Tested and working on both Windows 10 and Ubuntu 16.04.

The easiest way to build this program is to install QT Creator and open the included \*.pro file. While installing QT Creator make sure to install the MinGW compiler (Windows) or the GCC compiler (Linux). They can be selected in the QT Creator install wizard.

On my Ubuntu machine I also had to install another dependency to get it to build.
If you get a "cannot find -lGL" error, run the following command in a terminal:

```
sudo apt install libgl1-mesa-dev
```


---
### Usage Instructions


* Click the buttons displayed in the window or press the appropriate keys on your keyboard to input an expression.
* Click the '=' button or press the 'Enter' key on your keyboard to solve the expression.
* Click the 'C' button or press the 'Delete' key on your keyboard to clear the current expression.
* Press the 'Backspace' key on your keyboard to delete part of the expression from the right-hand side.
