cmake_minimum_required(VERSION 2.8)

project ( trackimg )

# Configure ouput folder for generated binary
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/)

ADD_DEFINITIONS(
    -std=c++11
)

find_package(OpenCV REQUIRED)
if(OPENCV_FOUND)
    message(STATUS "Found OpenCV")
else()
    message(STATUS "Cannot find OpenCV")
endif()

find_package(OpenMP QUIET)
if(OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    message(STATUS "Found OpenMP: " ${OpenMP_C_FLAGS})
else()
    message(STATUS "Cannot find OpenMP")
endif()

find_package(Eigen3 QUIET)
if(EIGEN3_FOUND)
    include_directories(${EIGEN3_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIR}/unsupported/)
    message(STATUS "Found Eigen3: ${EIGEN3_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIR}/unsupported/")
else()
    message(STATUS "Cannot find Eigen3")
endif()

#find_package(CImg QUIET)
#if(CIMG_FOUND)
#    include_directories(CIMG_INCLUDE_DIRS)
#    message(STATUS "Find CImg: ${CIMG_INCLUDE_DIRS}")
#else()
#    message(STATUS "Cannot find CImg")
#endif()

# Compile application
add_subdirectory(src)
