cmake_minimum_required(VERSION 3.16)

project(my_project)

# Set the C++ standard to C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add your source files here
set(SOURCES 10_async_return.cpp)

# set(SOURCES image_slice_aysnc.cpp slice.cpp)

# Add an executable target for your program
add_executable(my_program ${SOURCES})


# Link against the threading library
find_package(Threads REQUIRED)
target_link_libraries(my_program PRIVATE Threads::Threads)
