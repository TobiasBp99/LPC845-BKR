# LPC845 BRK

_The main goal is provide some basic examples with LPC845-BRK devolopment board. Maybe in a future using the most important files is possible to get a library._

## Contents:
---
- [Structure](#structure)
- [Testing](#testing)
- [Resources](#resources)
- [Autor](#autor)
- [Acknowledgment](#acknowledgment)


## Structure
Every project has a **source** and **inc** directory, **source** contains only files **.c** whilw **inc** contains only files **.h**.
Both type of files are divided between _<Module_Name__**FW**.c>_ or _<Module_Name__**SW**.h>_ That's beacause of the abstraction layers.
### Layers
To get an exportable code for any other embebbed is usefull working with abstraction layers.
![alt text](https://github.com/TobiasBp99/LPC845-BRK/blob/master/00-ImportantDocumentation/Layers.jpg)
_Example of set functions_
```
uint8_t GPIO_GetPIN(uint8_t port, uint8_t pin, uint8_t state); // Touch the (HW)
void GPIO_DebounceUserKEY(void);                               // Modify the buffer (SW)
uint8_t GetUserKEY(void);                                      // Read the buffer. (APP)
```


## Testing 🚀
_Steps for running an example._
### Prerequisites 📋
[MCUXpressoIDE](https://www.nxp.com/design/software/development-software/mcuxpresso-software-and-tools-/mcuxpresso-integrated-development-environment-ide:MCUXpresso-IDE)

[Doxygen](https://www.doxygen.nl/index.html)

[LPC845-BRK](https://www.nxp.com/products/processors-and-microcontrollers/arm-microcontrollers/general-purpose-mcus/lpc800-cortex-m0-plus-/low-cost-microcontrollers-mcus-based-on-arm-cortex-m0-plus-cores:LPC84X)

### Let's do it
_These steps are for Ubuntu. Open a new terminal._
```
git clone git@github.com:TobiasBp99/LPC845-BRK.git
```
_Open MCUXpressoIDE._
_Choose your workspace._
```
Import project(s) from file system...
Project archive (zip) Browse
```
_Choose the zip._
```
03-Semaphore.zip
Finisih
```
_Click project's name and push clean project._
_Now you're able to build and debug your code._

### Documentation
_Located in /LPC-BRK/03-Semaphore._
```
doxygen doxyfile
cd ./doc/latex
make
```
_Now the documentation is available in **doc/html/index.html** as a webpage._
_Now the documentation is available in **doc/latex/refman.pdf** as a PDF._

## Resources 🖇️
_There's a list of videos explaining how the project works._
[Youtube videos](https://www.youtube.com/playlist?list=PLcklOXEh1OBuFzwsaS9bkhSAK5Y9Cgrxb)


## Autor ✒️
* **Tobias Bavasso Piizzi** - *Trabajo Inicial* - [TobiasBp99](https://github.com/TobiasBp99)


## Acknowledgment 🎁
* Embebbed systems are a passion for me, I hope this information be useful for you

