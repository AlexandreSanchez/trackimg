# Trackimg

## About
Mono camera and mono object tracking in video sequences using LARS/LASSO algorithm.

## Project structure

The Trackimg project is structured as follow :
- **src**: source files of the project
- **cmake**: cmake finders files for needed libraries

## Compile

To compile, Trackimg depends on:
- CMake (at least 2.8): http://www.cmake.org
- OpenCV : http://opencv.org/

To compile Trackimg, use cmake to generate build files corresponding to your environment.

Here is an example for a build from Unix/Linux command line:
```sh
mkdir build && cd build
cmake ..
make
```

Once Trackimg is built, you will find the resulting binary under `bin/<BUILD_TYPE>` directory.

## Use Trackimg

### Command line
Run Trackimg with the following options:
```sh
Usage: trackimg [options] -d directory

Description:
Mono camera and mono object tracking in video sequences
using LARS/LASSO algorithm.

Required parameters:
-d <directory>     The root directory of the targeted video dataset.

Optional parameters:
-n <nbproc>        Number of processor core. {Default : 1}
-v <level>         Verbosity level
   The possible values are: {Default : 1}
       1 : summary and results
       2 : debug informations
-h                 Print this message.
```

