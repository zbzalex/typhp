cmake_minimum_required(VERSION 3.10)

project(typhp)

add_subdirectory(typhp)

add_executable(test
    test/test.cpp
)

target_include_directories(test
    PUBLIC
        typhp
)
