cmake_minimum_required(VERSION 3.13.0)

project(2Dengine VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(2Dengine
                src/main.cpp
                src/engine.cpp
                src/entity.cpp
                src/world.cpp
                src/tile.cpp

                src/render/renderer.cpp
                src/render/shader_manager.cpp
                src/render/vertex_buffer.cpp
                src/render/vertex_array.cpp
                src/render/index_buffer.cpp
                src/render/sprite_manager.cpp
                src/render/stb_image.cpp

                src/math/vector4.cpp

                src/callback_function.cpp
                src/glad.c) 

target_compile_definitions(2Dengine PUBLIC DEBUG=1)

if(UNIX AND NOT APPLE)
  target_link_libraries(2Dengine OpenGL::GL glfw)
elseif(WIN32)
  target_link_libraries(2Dengine ${CMAKE_SOURCE_DIR}/lib/glfw3dll.lib ${OPENGL_LIBRARIES})
endif()
