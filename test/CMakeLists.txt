cmake_minimum_required(VERSION 3.5)

project(DragonTest LANGUAGES CXX VERSION 0.0.1)

add_subdirectory(lib/Catch2)

add_executable(DragonTest DragonTest.cpp)
target_link_libraries(DragonTest PRIVATE DragonLib Catch2::Catch2WithMain)

include(Catch)

catch_discover_tests(DragonTest)
