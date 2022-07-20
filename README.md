# CPPND: Capstone Snake Game Example

This is a starter repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo was inspired by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) excellent StackOverflow post and set of responses.

<img src="snake_game.gif"/>

The Capstone Project gives you a chance to integrate what you've learned throughout this program. This project will become an important part of your portfolio to share with current and future colleagues and employers.

In this project, you can build your own C++ application or extend this Snake game, following the principles you have learned throughout this Nanodegree Program. This project will demonstrate that you can independently create applications using a wide range of C++ features.

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
2. Execute `./build.sh`

## New features:
* Different types of `Food` that spawn randomly:
  * Purple: increases speed and gives extra points
  * Pink: decreases speed 
  * Lime Green: swaps controls UP<->Down and Left<->Right
  * Blue: Shrinks the snake by 3 points
  * Red: game over

## Rubric points:
## Rubric Points

### Loops, Functions, I/O

| Criteria                                                                                       | Explanation                                                     |
|------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------|
| The project demonstrates an understanding of C++ functions and control structures.             | The new functionalities rely in the use of control structures and are organized in functions |
| The project reads data from a file and process the data, or the program writes data to a file. | ---------                                              |
| The project accepts user input and processes the input.                                        | ---------                                                                            |

### Object Oriented Programming

| Criteria                                                                         | Explanation and link(s)                                                                                                                                                                                                                           |
|----------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| The project uses Object Oriented Programming techniques.                         | The new class `Food` is used to create objects with the different types of new food and all the functionalities related to them are encapsulated in this new class |
| Classes use appropriate access specifiers for class members.                     | The class `Food` has several private members and methods that are only used inside the class and public functions for those functionalities that need to be executed from outside the class |
| Class constructors utilize member initialization lists.                          | All the possible parameters used in `Food`'s constructor are initialized using an initialization list |
| Classes abstract implementation details from their interfaces.                   | The name of the functions is self-explanatory or have comments to guide through more complex behaviors |
| Classes encapsulate behavior.                                                    | `Food` class has private members that are accessed using getters. The inner behavior of the food is encapsulated inside the class |
| Classes follow an appropriate inheritance hierarchy.                             | ---------  |
| Overloaded functions allow the same function to operate on different parameters. | `PlaceFood` works with 2 different sets of parameters|
| Derived class functions override virtual base class functions.                   | --------- |
| Templates generalize functions in the project.                                   | --------- |

### Memory Management

| Criteria                                                                                  | Explanation |
|-------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------|
| The project makes use of references in function declarations.                             | --------- |
| The project uses destructor(s) appropriately.                                             | --------- |
| The project uses scope / Resource Acquisition Is Initialization (RAII) where appropriate. | --------- |
| The project follows the Rule of 5.                                                        | --------- |
| The project uses move semantics to move data, instead of copying it, where possible.      | --------- |
| The project uses smart pointers instead of raw pointers.                                  | --------- |

### Concurrency

| Criteria                                     | Explanation |
|----------------------------------------------|-------------------------|
| The project uses multithreading.             | ---------                       |
| A promise and future is used in the project. | ---------                      |
| A mutex or lock is used in the project.      | ---------                       |
| A condition variable is used in the project. | ---------                       |



## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
