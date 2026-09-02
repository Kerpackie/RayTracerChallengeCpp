cmake_minimum_required(VERSION 4.3)
project(RayTracerChallenge)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Magically download GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

# 2. Your core Ray Tracer code (Everything EXCEPT main.cpp)
add_library(RayTracerLib
        tuple.cpp
        tuple.h
        Colour.cpp
        Colour.h
)

# 3. Your Main Application
add_executable(RayTracerChallenge main.cpp)
target_link_libraries(RayTracerChallenge PRIVATE RayTracerLib)

# 4. Your Test Runner
add_executable(RayTracerChallenge_tests
        tuple_test.cpp
        ColourTest.cpp)
target_link_libraries(RayTracerChallenge_tests PRIVATE GTest::gtest_main RayTracerLib)

# Enable CLion's visual test runner
include(GoogleTest)
gtest_discover_tests(RayTracerChallenge_tests)