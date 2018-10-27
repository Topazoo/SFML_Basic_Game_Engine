# SFML Game Development Tutorial
### Author: Peter Swanson

## Background
My first foray into game development in C++ using the Simple and Fast Multimedia Library.
The tutorial this game was based on can be found at https://www.gamefromscratch.com/page/Game-From-Scratch-CPP-Edition-The-Introduction.aspx

The tutorial itself appears outdated as SFML seems to be much more object-oriented than when this tutorial
was made. Thus, this project contains different data structures and design patterns than the tutorial itself.

## Minor Differences From Tutorial
- SFML object methods have different names and methods than the tutorial (e.g. the Rect class has no longer has a "bottom" or "right" attribute.
- Some SFML objects in the tutorial no longer exist and their functionality lies in other objects (e.g. the Image class has been replaced by the Texture class).
- Some important game state changes the tutorial omitted (e.g. game closed on splashscreen and changing to menu state on escape key press).

## Major Differences From Tutorial
- The Game class is implemented as a Singleton rather than a class with purely static methods.
- A much more abstract Menu class replaces the MainMenu class and supports dynamically adding buttons. It also supports rows of buttons instead of a single column and faster button lookup via a 2d hash table.

## Configuration
This project was built for Windows using Visual Studio 2017 and statically linked SFML libraries.
Here's a handy guide for configuring Visual Studio to use SFML's libraries: https://www.sfml-dev.org/tutorials/2.5/start-vc.php

## Requirements
- Visual Studio 2017: https://visualstudio.microsoft.com/vs/
- SFML Visual C++ 15 (2017) - 32-bit: https://www.sfml-dev.org/download/sfml/2.5.1/