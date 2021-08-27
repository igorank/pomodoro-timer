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

### Setting up wxWidgets Using Visual Studio 2019

1. The documentation on the wxWidgets website suggests that you start by creating a Visual C++ Win32 project or by copying one of the Samples projects and modifying that. I prefer to start with an empty project: On the Start Page tab under New project, click on Empty Project Visual C++, or select the File->New->Project… menu item to open the New Project dialog; select Empty Project Visual C++. Change the project name near the bottom of the dialog. For the sake of this post, assume you have named the project MyProject. Select the Create directory for solution and Create new Git repository checkboxes as appropriate. Click the OK button to create the project. You now have a project with no source files.
2. Right-click on the project name in the Solution Explorer. Select the Add->New Item… menu item to open the Add New Item dialog. Select the Header File (.h) item and enter the name of the header file for the application class (MyProjectApp.h). Click the Add button.
3. Right-click on the project name in the Solution Explorer. Select the Add->New Item… menu item to open the Add New Item dialog. Select the C++ File (.cpp) item and enter the name of source file for the application class (MyProjectApp.cpp). Click the Add button.
4. Perform the following steps to set up project specific settings:
  * In Solution Explorer, open the context menu for the project that you just created (MyProject, or whatever you named it). Select the Properties menu item. This opens the project’s Property Pages: 

![set](https://computingonplains.files.wordpress.com/2019/01/projectpropertypages.png)

  * Select Configuration Properties→Advanced→Character Set. Click on the dropdown button dropdownbutton. Select Use Unicode Character Set. Click the Apply button.
  * Select Configuration→C/C++→Preprocessor→Preprocessor Definitions and open its editor. Enter WXUSINGDLL, press Enter, and click on the OK button to close the editor.

5. In the Property Pages dialog, click the Apply button and then the OK button.
6. Build the program, and run it.

## Todo

Minimize to Tray

## Licence

MIT License. See ```LICENSE```.

Copyright (c) 2021 Igor Anikin.
