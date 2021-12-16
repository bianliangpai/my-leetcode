CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
project(Leetcode)

include_directories(
  ${CMAKE_SOURCE_DIR}
)

if (MSVC)
  set(CMAKE_CXX_FLAGS "/DEBUG")
else()
  set(CMAKE_CXX_FLAGS "-g -O0 -fno-omit-frame-pointer")
endif()

add_executable(
  Main
  main.cpp
)