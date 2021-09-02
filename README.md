# Pomodoro Timer
A small application that helps managing time :tomato:.

![main](https://i.imgur.com/OHQ38Nv.jpeg)

It also supports visual notifications:

![noti](https://i.imgur.com/YDNREI5.jpeg)

And some degree of control:

![settings](https://i.imgur.com/aN4XKO7.jpeg)

## Building

To keep things simple, you just need any C++ compiler and at least wxWidgets 3.1.5.

### Getting the wxWidgets Source Code

1. Create a directory to place the wxWidgets source code into. I will assume that this directory is C:\wxWidgets. The instructions in this post assume this location.
2. Download the source code for the latest stable or latest development release from the wxWidgets download page.
3. Open the downloaded file. Use the 7Zip utility to open the 7z file. Windows Explorer will open and expand the zip file.
4. Expand the files into the directory you created in step 1.

### Building wxWidgets

1. Start the CMake GUI.
2. Specify the wxWidgets root as your source folder.
3. Specify a path where the build files should be created. It's recommended to use a path outside the wxWidgets root folder.
4. Press the Configure button and you will be asked which IDE or build system you wish to use.
5. Optionally: Customize any of the options.
6. Press the Generate button.
7. Open the wxWidgets project with your preferred IDE and build it.

## Todo

Minimize to Tray

## Licence

MIT License. See ```LICENSE```.

Copyright (c) 2021 Igor Anikin.
