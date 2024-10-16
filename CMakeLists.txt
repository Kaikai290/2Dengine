cmake_minimum_required(VERSION 3.5.0)

project(2Dengine VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(2Dengine
                src/main.cpp) 

if(UNIX AND NOT APPLE)
  target_link_libraries(2Dengine OpenGL::GL glfw)
elseif(WIN32)
  target_link_libraries(2Dengine ${CMAKE_SOURCE_DIR}/lib/glfw3dll.lib OpenGL::GL glfw)
endif()
