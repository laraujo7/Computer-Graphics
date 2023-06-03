cmake_minimum_required(VERSION 3.5)

# Project Name
PROJECT(engine)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(${PROJECT_NAME}
    src/engine.cpp
    src/engine.hpp
    src/classes/camera/camera.cpp
    src/classes/camera/camera.hpp
    src/classes/spline/spline.cpp
    src/classes/spline/spline.hpp
    src/classes/group/group.cpp
    src/classes/group/group.hpp
    src/classes/model3d/model3d.cpp
    src/classes/model3d/model3d.hpp
    src/classes/modelConfig/modelConfig.cpp
    src/classes/modelConfig/modelConfig.hpp
    src/classes/transformation/transformation.cpp
    src/classes/transformation/transformation.hpp
    src/classes/world/world.cpp
    src/classes/world/world.hpp
    utils/colors_helpers/colors_helpers.cpp
    utils/colors_helpers/colors_helpers.hpp
    utils/xml_parser_helpers/xml_parser_helpers.hpp
    utils/xml_parser_helpers/xml_parser_helpers.cpp
    utils/xml_parser_helpers/xml_parser_helpers.hpp
    utils/direction_helpers/direction_helpers.cpp
    utils/direction_helpers/direction_helpers.hpp
    lib/tinyxml2/tinyxml2.h
    lib/tinyxml2/tinyxml2.cpp
    lib/glew/glew.c
    lib/glew/glew.h
    ../config/global.hpp
    ../utils/point/point.cpp
    ../utils/point/point.hpp
    ../utils/vector/vector.cpp
    ../utils/vector/vector.hpp
    ../utils/file_helpers/file_helpers.hpp
    ../utils/file_helpers/file_helpers.cpp
    ../utils/generic_functions/generic_functions.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE)

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