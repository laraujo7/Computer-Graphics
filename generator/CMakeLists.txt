cmake_minimum_required(VERSION 3.5)

# Project Name
PROJECT(generator)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

add_executable(${PROJECT_NAME}
								src/generator.cpp
								src/generator.hpp
								src/models/box/box.cpp
								src/models/box/box.hpp
								src/models/cone/cone.cpp
								src/models/cone/cone.hpp
								src/models/sphere/sphere.cpp
								src/models/sphere/sphere.hpp
								src/models/plane/plane.cpp
								src/models/plane/plane.hpp
								src/models/patch/patch.cpp
								src/models/patch/patch.hpp
								src/classes/model/model.cpp
								src/classes/model/model.hpp
								src/classes/triangle_index/triangle_index.cpp
								src/classes/triangle_index/triangle_index.hpp
								../utils/point/point.cpp
    						../utils/point/point.hpp
								../utils/normal/normal.cpp
    						../utils/normal/normal.hpp
								../config/global.hpp
								../utils/file_helpers/file_helpers.cpp
								../utils/file_helpers/file_helpers.hpp
								../utils/string_helpers/string_helpers.cpp
								../utils/string_helpers/string_helpers.hpp
								../utils/generic_functions/generic_functions.hpp
							)

find_package(OpenGL REQUIRED)
include_directories(${OpenGL_INCLUDE_DIRS})
link_directories(${OpenGL_LIBRARY_DIRS})
add_definitions(${OpenGL_DEFINITIONS})

find_package(docopt COMPONENTS CXX REQUIRED)
include_directories(${DOCOPT_INCLUDE_DIRS})

if(NOT OPENGL_FOUND)
    message(ERROR " OPENGL not found!")
endif(NOT OPENGL_FOUND)

if  (WIN32)

	message(STATUS "Toolkits_DIR set to: " ${TOOLKITS_FOLDER})
	set(TOOLKITS_FOLDER "" CACHE PATH "Path to Toolkits folder")

	if (NOT EXISTS "${TOOLKITS_FOLDER}/glut/GL/glut.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glut/glut32.lib")
		message(ERROR ": GLUT not found")
	endif (NOT EXISTS "${TOOLKITS_FOLDER}/glut/GL/glut.h" OR NOT EXISTS "${TOOLKITS_FOLDER}/glut/glut32.lib")

	include_directories(${TOOLKITS_FOLDER}/glut )
	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES}
										  ${TOOLKITS_FOLDER}/glut/glut32.lib docopt)

	if (EXISTS "${TOOLKITS_FOLDER}/glut/glut32.dll" )
		file(COPY ${TOOLKITS_FOLDER}/glut/glut32.dll DESTINATION ${CMAKE_BINARY_DIR})
	endif(EXISTS "${TOOLKITS_FOLDER}/glut/glut32.dll" )

	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

else (WIN32) #Linux and Mac

	set( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} Wno-deprecated")
	find_package(GLUT REQUIRED)
	include_directories(${GLUT_INCLUDE_DIR})
	link_directories(${GLUT_LIBRARY_DIRS})
	add_definitions(${GLUT_DEFINITIONS})

	target_link_libraries(${PROJECT_NAME} ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} docopt)
	if(NOT GLUT_FOUND)
	   message(ERROR ": GLUT not found!")
	endif(NOT GLUT_FOUND)

endif(WIN32)








