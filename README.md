# Mask-Detector
A mask detector built as a final project for AP Computer Science A.

## Compilation
### Dependencies 
This project requires that both [CMake](https://cmake.org/download/) and [OpenCV](https://opencv.org/) are installed on your system.

### On Linux 
Run "install.sh" in the project's root directory.
Then, you can run the executable in the build directory

### On Windows
You will need to use the CMake application to compile.


## Project Requirements
- use variables
- use methods
- at least three classes 
- need to access each class/method within a class
- needs to run

## Notes
The structure of this project is kinda weird becuase it needs to meet the above requirements.

Each file in the include directory is a class. The main file is in the src directory.

## How it works

Using Haar Cascades, it detects faces, and then looks for mouths within the areas it detects a face. If there is no mouth, we can assume something (probably a mask) is covering it. If there is a mouth, then the person is definitely not wearing a mask (unless they are wearing some kind of clear mask).

Another way to do this would be to train a mask classifier using OpenCV, but honestly that sounded like a lot of work and I had other final projects to work on.
