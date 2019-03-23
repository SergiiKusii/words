cmake_minimum_required(VERSION 2.8)

set (PROJECT words)
project(${PROJECT})

set(CMAKE_CXX_STANDARD 14)

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build, options are: Debug Release" FORCE)
endif ()

set(ROOT_DIR "${CMAKE_SOURCE_DIR}")
set(BINARY_DIR  ${ROOT_DIR}/bin/${CMAKE_BUILD_TYPE})
set(LIB_DIR "${ROOT_DIR}/lib/${CMAKE_BUILD_TYPE}")
set(TEST_DIR ${BINARY_DIR})
set(SOURCE_DIR ${ROOT_DIR}/src)

set(CMAKE_INCLUDE_PATH ${SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${LIB_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${LIB_DIR}")
# set (CMAKE_LIBRARY_PATH ${${PROJECT}_LIB_DIR})
set (EXECUTABLE_OUTPUT_PATH ${BINARY_DIR})
set (CMAKE_VERBOSE_MAKEFILE ON)

enable_testing()

add_subdirectory(src)
