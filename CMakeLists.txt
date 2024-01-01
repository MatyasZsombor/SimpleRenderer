cmake_minimum_required(VERSION 3.27)
project(Renderer)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)

add_executable(Renderer main.cpp
        header_files/standard_libraries.h
        header_files/implemented_headers.h
        helper_functions.cpp
        library.cpp
        RGB.cpp
        helper_functions.cpp
)
target_link_libraries(Renderer ${SDL2_LIBRARIES})
target_link_libraries(Renderer -lSDL2)
target_link_libraries(Renderer ${m})