cmake_minimum_required(VERSION 3.27)
project(Renderer)

set(CMAKE_CXX_STANDARD 17)

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
)
target_link_libraries(Renderer ${OPENGL_LIBRARIES})
target_link_libraries(Renderer ${GLUT_LIBRARIES})
target_link_libraries(Renderer -lGL -lGLU -lglut)
target_link_libraries(Renderer ${m})