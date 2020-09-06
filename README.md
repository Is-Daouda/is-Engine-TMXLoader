# is::Engine TMX Loader
This project shows you how to use the TMX Loader library with the game engine.
It incorporates the seven (7) examples that can be found on the official library [website](https://github.com/fallahn/sfml-tmxloader/tree/master/examples).
In this project you will also discover:
- The new object event management system
- How to use SDM with TMX Loader Objects

![Image](./images/demo_screen.png)

## Prerequisites
- [SFML Library (2.4 +)](https://www.sfml-dev.org/download.php)
- GCC Compiler (7.3 +)

---

## How to use is::Engine with the different development tools:
## CMake
**1. Prerequisites**
- CMake (3.1 +)

**2. Installation**
#### Windows
1. Compile SFML with CMake to have **static libraries** and put on **C:/ (C:/SFML)**.
2. Move the **is-Engine-TMXLoader** project to your **C:/ (C:/is-Engine-TMXLoader)**.
3. Execute this command :
```bash
cmake -S "C:/is-Engine-TMXLoader" -B "C:/build"
cd build
make
```

#### Linux
1. Install SFML 2.5.1 on your machine.
2. Move the **is-Engine-TMXLoader** project to **/home/user/ (/home/user/is-Engine-TMXLoader)**.
3. Execute this command :
```bash
sudo cmake -S "is-Engine-TMXLoader" -B "build"
cd build
sudo make
```

**3. After installation**
- You will have a **bin** folder in which the engine demo is located.

**5. Adding Source Files**
- In order for CMake to detect your source files (.cpp) you must include them in the **app_src.cmake** file which is located in the **is-Engine-TMXLoader/app/src/main/cmake** location.

---

## Visual Studio Code
This project uses the template of **andrew-r-king**. For more information on this template [click here](https://github.com/andrew-r-king/sfml-vscode-boilerplate).

**1. Prerequisites**
#### Windows
- [SFML 2.5.1 - GCC 7.3.0 MinGW (DW2) 32-bit](https://www.sfml-dev.org/files/SFML-2.5.1-windows-gcc-7.3.0-mingw-32-bit.zip)
- [GCC 7.3.0 MinGW (DW2) 32-bit](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z/download)
- [Git Bash](https://git-scm.com/downloads)

#### Linux
- Get SFML 2.5.1 from your distro if it has it, or compile from source.

**2. Installation**
#### Windows
1. Download & Extract SFML 2.5.1 to **C:/SFML/** where the bin/lib/include folders are contained within.
2. Download & Extract MinGW to **C:/mingw32/** where the bin/lib/include folders are contained within.

#### Linux
1. Ensure the GCC Toolchain is installed (**sudo apt install build-essential**).
2. Run **sudo apt install libsfml-dev**. The SFML version you got will vary depending on the distro. 2.5.1 is included in [Ubuntu 19.04 Disco Dingo](http://cdimage.ubuntu.com/daily-live/current/HEADER.html) for example.

**3. Opening the project with the IDE:**
#### Windows
1. Run the file **open_vscode.bat** in the main directory.

#### Linux
2. Execute this command in the main directory:
```bash
code -n "./app/src/main"
```

#### All
3. Or open the **is-Engine-TMXLoader/app/src/main** folder with **Solution Explorer**.

**4. Executable location**
- The compiler files can be found in **is-Engine-TMXLoader/app/src/main/bin-vscode**.

---

## Code::Blocks
**1. Prerequisites**

#### Windows
- [Code::Blocks 20.03 MinGW](https://sourceforge.net/projects/codeblocks/files/Binaries/20.03/Windows/codeblocks-20.03mingw-setup.exe/download)

#### Linux
- Code::Blocks 20.03

**2. Installation**
#### Windows
1. Compile SFML and put on **C:/ (C:/SFML_MinGW)**. The folder must have an **include** subfolder and a **lib** subfolder which contains the **static** (.a) and **Dynamic Link Library** (.dll) files.

#### Linux
1. Ensure the GCC Toolchain is installed (**sudo apt install build-essential**).
2. Run **sudo apt install libsfml-dev**. The SFML version you got will vary depending on the distro. 2.5.1 is included in [Ubuntu 19.04 Disco Dingo](http://cdimage.ubuntu.com/daily-live/current/HEADER.html) for example.

**3. Opening the project with the IDE:**

#### Windows
1. Run the file **open_codeblocks.bat** in the main directory.
2. Or open the file **is-Engine-windows.cbp** in the location **is-Engine-TMXLoader/app/src/main**

#### Linux
1. Execute this command in the main directory:
```bash
codeblocks "./app/src/main/is-Engine-linux.cbp"
```
2. Or open the file **is-Engine-linux.cbp** in the location **is-Engine-TMXLoader/app/src/main**.

**3. Executable location**
- The compiler files can be found in **is-Engine-TMXLoader/app/src/main/bin-codeblocks**.

---

## Change application icon:
#### Windows
- To change the icon of the application you must go to the location **is-Engine-TMXLoader/app/src/main/env/windows** replace all the images **(Attention CMake uses the same resources).**

#### Linux
- To change the icon of the application you must go to the location **is-Engine-TMXLoader/app/src/main/env/linux**.

---

## Description of the project structure:
![header](./images/is_Engine_structure.png)
----------------------------
- The source files of the project can be found in the **is-Engine-TMXLoader/app/src/main/cpp** location.

#### `main.cpp` file
Contains the entry point of the program, inside there are two instructions :
- `game.play()`: Launches the engine rendering loop which allows to manage the introduction screen, main menu, level and game over.
- `game.basicSFMLmain()` (disabled by default): Launches the display of a classic SFML window. The implementation is in the `basicSFMLmain.cpp` file. *Very useful if you already have a project under development and you want to associate it with the engine. You can also use it to implement your own components to the engine.*

----------------------------
#### `app_src` folder
Contains the source code of the game.
Description of these sub-directories:
- `activity` : Contains the `Activity` class which allows the interaction of the different scenes of the game.
- `config`   : Contains the `GameConfig.cpp` file which allows to define the general parameters of the game.
- `gamesystem_ext` : Contains a class derived from `GameSystem` which allows to manipulate game data (save, load, ...).
- `language` : Contains the `GameLanguage.cpp` file which allows to manage everything related to game languages.
- `levels`   : Contains game levels and the `Level.h` file which allows to integrate them into the game.
- `objects`  : Contains the objects that will be used in the different scenes.
- `scenes`   : Contains the different scenes of the game (Introduction, Main menu, ...).

----------------------------
#### `data` folder
Contains game resource files (music, sound sfx, image, ...)

----------------------------
#### `isEngine` folder
Contains the source code of the game engine

---

## How to contribute?
Here are some examples of how to contribute:
- You have developed a module and want it to be part of the engine, you are welcome.
- You have thought of a feature and you want it to be integrated into the engine, do not hesitate to submit it to us with your **name** of course.
- You want to participate in the development of the engine, well welcome to the team!
- You have developed a game or application with the engine, we gladly accept it to publish it!
- You noticed a bug, well done! Let us know Mr. Hacker.

## Contacts
  * For any help or other contribution please contact me on my [email address](mailto:isdaouda.n@gmail.com)
  * You can follow me on Twitter for more informations on my activities [@Is Daouda Games](https://twitter.com/IsDaouda_Games)