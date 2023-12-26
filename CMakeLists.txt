cmake_minimum_required(VERSION 3.27)
project(Renderer)

set(CMAKE_CXX_STANDARD 17)

add_executable(Renderer main.cpp)
target_link_libraries(Renderer ${OPENGL_LIBRARIES})
target_link_libraries(Renderer ${GLUT_LIBRARIES})
target_link_libraries(Renderer -lGL -lGLU -lglut)