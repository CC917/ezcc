cmake_minimum_required(VERSION 3.18)

set(EZCC_BUILD_DEBUG "off" CACHE STRING "enable cmake verbose or debug opt")

# Set cmake module file search path.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

include(ezcc_com)

project(ezcc VERSION 0.0.1 LANGUAGES CXX)

add_subdirectory(core)
