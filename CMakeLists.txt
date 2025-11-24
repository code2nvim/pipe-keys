cmake_minimum_required(VERSION 4.1)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD
  # This specific value changes as experimental support evolves. See
  # `Help/dev/experimental.rst` in the CMake source corresponding to
  # your CMake build for the exact value to use.
  "d0edc3af-4c50-42ea-a356-e2862fe7a444")
project(pipe-keys LANGUAGES CXX)

# set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(COMPILE_WARNING_AS_ERROR ON)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(pipe-keys src/main.cpp)

add_library(input STATIC)
target_link_libraries(pipe-keys PRIVATE input)

find_package(Libinput REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(libevdev REQUIRED IMPORTED_TARGET libevdev)
pkg_check_modules(libudev REQUIRED IMPORTED_TARGET libudev)

target_link_libraries(input PRIVATE Libinput::Libinput PkgConfig::libevdev PkgConfig::libudev)
target_sources(input
  PUBLIC
    FILE_SET CXX_MODULES FILES
      src/input.cpp
      src/input/data.cpp
      src/input/event.cpp
      src/input/external.cpp
      src/input/resource.cpp)
