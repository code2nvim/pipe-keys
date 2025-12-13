cmake_minimum_required(VERSION 4.1)
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD
  # This specific value changes as experimental support evolves. See
  # `Help/dev/experimental.rst` in the CMake source corresponding to
  # your CMake build for the exact value to use.
  "d0edc3af-4c50-42ea-a356-e2862fe7a444")
project(pipe-keys LANGUAGES CXX)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_MODULE_STD ON)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(COMPILE_WARNING_AS_ERROR ON)

add_compile_options(-Wall -Wextra -Wpedantic)
add_custom_target(run_install ALL
  COMMAND bash ${CMAKE_SOURCE_DIR}/install.sh
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

add_compile_options(-pthread)
find_package(Libinput REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(gtkmm REQUIRED IMPORTED_TARGET gtkmm-4.0)
pkg_check_modules(jsoncpp REQUIRED IMPORTED_TARGET jsoncpp)
pkg_check_modules(libevdev REQUIRED IMPORTED_TARGET libevdev)
pkg_check_modules(libudev REQUIRED IMPORTED_TARGET libudev)
pkg_check_modules(webkitgtk REQUIRED IMPORTED_TARGET webkitgtk-6.0)

add_executable(pipe-keys src/main.cpp)
add_library(data)
add_library(input)
add_library(window)

target_link_libraries(data
  PRIVATE
    PkgConfig::jsoncpp)

target_link_libraries(input
  PRIVATE
    Libinput::Libinput
    PkgConfig::libevdev
    PkgConfig::libudev
    data)

target_link_libraries(window
  PRIVATE
    PkgConfig::gtkmm
    PkgConfig::webkitgtk
    data
    input)

target_link_libraries(pipe-keys
  PRIVATE
    PkgConfig::gtkmm
    window)

target_sources(data
  PUBLIC
    FILE_SET CXX_MODULES FILES
      src/data/code.cpp
      src/data.cpp)

target_sources(input
  PUBLIC
    FILE_SET CXX_MODULES FILES
      src/input/event.cpp
      src/input/external.cpp
      src/input/resource.cpp
      src/input.cpp)

target_sources(window
  PUBLIC
    FILE_SET CXX_MODULES FILES
      src/window/external.cpp
      src/window.cpp)
