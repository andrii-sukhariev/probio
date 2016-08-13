cmake_minimum_required (VERSION 2.6)
project(probio)

SET(SFML_INCLUDE_PATH "" CACHE STRING "path to sfml includes")
SET(SFML_LIB_PATH "" CACHE STRING "path to sfml libs")

option(BUILD_MODEL "" ON)
option(BUILD_RENDER "" ON)
option(BUILD_DIALOG_SYSTEM "" ON)
option(BUILD_PROBIO_APP "" ON)

if(SFML_INCLUDE_PATH STREQUAL "" OR SFML_LIB_PATH STREQUAL "")
    message(ERROR " you have to specify valid sfml path")
else()
	SET(SFML_AVAILABLE 1)
endif()

SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
SET(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

if(NOT MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
endif()

if(SFML_AVAILABLE)
    include_directories(${SFML_INCLUDE_PATH})
	link_directories(${SFML_LIB_PATH})
	
	if(MSVC)
	    set(WORKING_LIBS_D model.lib render.lib dialog_system.lib sfml-graphics-d.lib sfml-system-d.lib sfml-window-d.lib)
		set(WORKING_LIBS model.lib render.lib dialog_system.lib sfml-graphics.lib sfml-system.lib sfml-window.lib)
		set(SFML_LIBS_D sfml-graphics-d.lib sfml-system-d.lib sfml-window-d.lib)
		set(SFML_LIBS sfml-graphics.lib sfml-system.lib sfml-window.lib)
	else()
	    set(WORKING_LIBS libmodel.so librender.so libdialog_system.so libsfml-graphics.so libsfml-system.so libsfml-window.so)
		set(SFML_LIBS libsfml-graphics.so libsfml-system.so libsfml-window.so)
    endif()
endif()

if(${BUILD_PROBIO_APP} MATCHES ON)
    include_directories(
	    ${CMAKE_CURRENT_SOURCE_DIR}/model/include
		${CMAKE_CURRENT_SOURCE_DIR}/render/include
		${CMAKE_CURRENT_SOURCE_DIR}/dialog_system/include
	)
	
	add_subdirectory(model)
	add_subdirectory(render)
	add_subdirectory(dialog_system)
	add_subdirectory(probio_app)
	
	add_dependencies(render model)
	
endif()

if (${BUILD_MODEL} MATCHES ON AND ${BUILD_PROBIO_APP} MATCHES OFF)
    add_subdirectory(model)
endif()

if (${BUILD_RENDER} MATCHES ON AND ${BUILD_PROBIO_APP} MATCHES OFF)
    add_subdirectory(render)
endif()

if (${BUILD_DIALOG_SYSTEM} MATCHES ON AND ${BUILD_PROBIO_APP} MATCHES OFF)
    add_subdirectory(dialog_system)
endif()