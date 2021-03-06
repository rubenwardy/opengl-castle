cmake_minimum_required(VERSION 3.15)
project(castle)

#################
# CONFIGURATION #
#################

# Enable debug symbols by default
if(CMAKE_BUILD_TYPE STREQUAL "")
	set(CMAKE_BUILD_TYPE Debug)
endif()
if(CMAKE_BUILD_TYPE STREQUAL Debug)
	message("-- Debug Build")
endif()

################
# DEPENDENCIES #
################

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_library(GLM REQUIRED)

find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
include_directories(${GLFW_INCLUDE_DIRS})


set(SOURCE_LIST
	src/main.cpp
	src/engine/Window.cpp
	src/engine/Shader.cpp
	src/engine/Shader.hpp
	src/graph/Node.cpp
	src/graph/Component.cpp
	src/game/MeshDrawComponent.cpp
	src/tests/tests.cpp
	src/libs/stb_image.c
	src/engine/Image.cpp
	src/engine/Texture.cpp
	src/engine/RenderDevice.cpp)

file(MAKE_DIRECTORY "bin")
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/bin")
set(EXECUTABLE_NAME "castle")

include_directories(${CMAKE_SOURCE_DIR}/src//libs/ ${GLEW_INCLUDE_DIR} ${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIR} ${GLM_INCLUDE_DIR})
add_executable(${EXECUTABLE_NAME} ${SOURCE_LIST})
target_link_libraries(${EXECUTABLE_NAME} ${STANDARD_TARGETS} ${OPENGL_LIBRARIES} ${GLEW_LIBRARIES} ${GLFW_LIBRARIES} ${GLM_LIBRARY})
