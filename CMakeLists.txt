cmake_minimum_required(VERSION 3.10)

project(DynamicArray VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -pedantic)
endif()

# Add the executable
add_executable(dynamic_array main.cpp)

# Make the header available
target_include_directories(dynamic_array PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Installation rules
install(TARGETS dynamic_array DESTINATION bin)
install(FILES dynamic_array.h DESTINATION include)
