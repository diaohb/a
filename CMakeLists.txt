#set(CMAKE_CXX_STANDARD 14)
###############################################
# Project hbuana
###############################################

#cmake minimum requirement
cmake_minimum_required(VERSION 3.17)
set(CMAKE_CXX_STANDARD 17)

#Project name and version
project (chess)

#CMake type
set(CMAKE_BUILD_TYPE Debug)

#External packages
find_package( ROOT COMPONENTS Matrix Hist RIO MathCore Physics)


#set run time output directory as bin
# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

#Add include directories
include_directories(src)
include_directories(include)

#message("hey ${YAML_CPP_INCLUDE_DIR}")
file(GLOB_RECURSE sources CONFIGURE_DEPENDS *.cxx *.h)
add_executable(chess ${sources})
# add_executable(ru_cube ru_cube.cxx src/Board.cxx src/Game.cxx src/Pixel.cxx)