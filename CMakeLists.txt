cmake_minimum_required(VERSION 3.0)

set(PROJECT_NAME polynom)
project(${PROJECT_NAME})

set(LIBRARY "${PROJECT_NAME}")
set(TESTS  "test_${PROJECT_NAME}")

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

# Include
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/gtest)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)

# BUILD
add_subdirectory(src/MapLib)
add_subdirectory(src/SMapLib)
add_subdirectory(src/StackLib)
add_subdirectory(src/TItemLib)
add_subdirectory(src/TTreeLib)
add_subdirectory(src/HMapLib)
add_subdirectory(gtest)
add_subdirectory(test)
add_subdirectory(samples)


# REPORT
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "======================================")
