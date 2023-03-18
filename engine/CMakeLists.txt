cmake_minimum_required(VERSION 3.5)
project(engine)

set(CMAKE_CXX_STANDARD 11)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(${PROJECT_NAME}
    src/engine.cpp
    src/world.cpp
    src/camera.hpp
    src/model3d.cpp
    src/includes.h
    lib/tinyxml2/tinyxml2.h
    lib/tinyxml2/tinyxml2.cpp
    lib/glew/glew.c
    lib/glew/glew.h
)

target_include_directories(${PROJECT_NAME} PRIVATE src/tinyxml2)

find_package(OpenGL REQUIRED)
if(OPENGL_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${OpenGL_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${OPENGL_LIBRARIES})
else()
    message(FATAL_ERROR "OPENGL not found!")
endif()

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

find_package(GLUT REQUIRED)
if(GLUT_FOUND)
    target_include_directories(${PROJECT_NAME} PRIVATE ${GLUT_INCLUDE_DIRS})
    target_link_libraries(${PROJECT_NAME} PRIVATE ${GLUT_LIBRARIES})
else()
    message(FATAL_ERROR "GLUT not found!")
endif()

find_package(docopt COMPONENTS CXX REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${DOCOPT_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PRIVATE docopt)

if(WIN32)
    set(TOOLKITS_FOLDER "" CACHE PATH "Path to Toolkits folder")

    if(NOT EXISTS "${TOOLKITS_FOLDER}/glut/GL/glut.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glut/glut32.lib")
        message(FATAL_ERROR "GLUT not found")
    endif()
endif(WIN32)