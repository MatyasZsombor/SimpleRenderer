cmake_minimum_required(VERSION 3.27)
project(Renderer)

set(CMAKE_CXX_STANDARD 17)
find_package(SDL2 REQUIRED)

add_executable(Renderer main.cpp
        library.cpp
        header_files/helper_functions.h
        header_files/vector.h
        helper_functions.cpp
        header_files/player.h
        header_files/all_headers.h
        header_files/constants.h
        header_files/RGB.h
        RGB.cpp
        header_files/all_headers.h
        header_files/library.h
        header_files/state.h
        header_files/standard_libraries.h
)
target_link_libraries(Renderer ${SDL2_LIBRARIES})
target_link_libraries(Renderer -lSDL2)
target_link_libraries(Renderer ${m})