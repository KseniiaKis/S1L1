cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME polynom)
project(${PROJECT_NAME})

# TODO(Korniakov): not sure if these lines are needed
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(Polynom_TESTS   "test_${PROJECT_NAME}")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)

# BUILD
add_subdirectory(src/MapLib)
add_subdirectory(src/SMapLib)
add_subdirectory(src/StackLib)
add_subdirectory(gtest)
add_subdirectory(test)
add_subdirectory(samples)

# REPORT
message( STATUS "")
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "======================================")
message( STATUS "")
message( STATUS "   Configuration: ${CMAKE_BUILD_TYPE}")
message( STATUS "")
