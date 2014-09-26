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
- OpenCV (at least 1.2.14): http://opencv.org/
- OpenMP : http://openmp.org
- Eigen3 : http://eigen.tuxfamily.org

To compile Trackimg, use cmake to generate build files corresponding to your environment.

Here is an example for a build from Unix/Linux command line:
```sh
mkdir build && cd build
cmake ..
make
```

Once Trackimg is built, you will find the resulting binary under `bin/<BUILD_TYPE>` directory.

## Use Trackimg

TODO

### Command line

Run Trackimg with the following options:
TODO
