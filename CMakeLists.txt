cmake_minimum_required(VERSION 3.8)
project(ConwayCPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_CXX_FLAGS_DEBUG "-Wall -g")


set(SOURCE_FILES src/main.cpp src/Conway.cpp src/Conway.hpp src/SDL_Handler.cpp src/SDL_Handler.hpp)


# Appends the cmake/modules path inside the MAKE_MODULE_PATH variable which stores the
# directories of additional CMake modules (ie. MacroOutOfSourceBuild.cmake):
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")


# Find SDL2 libraries using the custom made module in
# the cmake/ path
find_package(SDL2 REQUIRED)
find_package(SDL2_IMAGE REQUIRED)

# Add SDL2 include directory to search path
include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMG_INCLUDE_DIR})

add_executable(ConwayCPP ${SOURCE_FILES})
target_link_libraries(ConwayCPP ${SDL2_LIBRARY})
target_link_libraries(ConwayCPP m)