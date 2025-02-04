# Snake Game
*Snake Game*, this is a traditional snake game with obstacle which implemented based on project capstone for Udacity's C++ Nanodegree Program.

## How to play
* You have to move the snake to eat the yellow food as much as you can. If you crash the orange obstacles, the game will finish
* Each time, the snake eats a yellow food, the score increases
* Each time, there will be an additional obstacle with different shapes

## Demo
![](snake_game.gif)

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.


## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg

## Rubic points

1. The project demonstrates an understanding of C++ functions and control structures.
  * obstacle.cpp: line 23 - 30
  * game.cpp: line 77 - 81
  * renderer.cpp: line 48 - 53, line 65 - 69, line 96 - 99
2. The project uses Object Oriented Programming techniques.
  * Check new classes created: food.cpp, obstacle.cpp, color.cpp
3. Classes use appropriate access specifiers for class members.
  * food.h: line 13 - 24
  * obstacle.h: line 19 - 26
  * color.h: line 10 - 22
4. Class constructors utilize member initialization lists.
  * food.cpp: line 8
  * obstacle.cpp: line 18
  * color.cpp: line 8
5. Classes encapsulate behavior.
  * food.cpp: line 13 - 35
  * color.cpp: line 10 - 24
  * obstacle.cpp: line 23 - 31
