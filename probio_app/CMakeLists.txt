cmake_minimum_required (VERSION 2.6)

project (probio_app)
set (BIN_NAME probio_app)
set (MODEL_LIB model)
set (RENDER_LIB render)
set (DIALOG_SYSTEM_LIB dialog_system)

file (GLOB_RECURSE SRCS
    src/*.cpp
	include/*.hpp
	include/*.h
)

include_directories (
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
	${CMAKE_CURRENT_SOURCE_DIR}/../model/include/
	${CMAKE_CURRENT_SOURCE_DIR}/../render/include/
	${CMAKE_CURRENT_SOURCE_DIR}/../dialog_system/include/
	${SFML_INCLUDE_PATH}/
)

add_executable (${BIN_NAME} src/probio.cpp)

if (MSVC)
    target_link_libraries(${BIN_NAME} optimized ${MODEL_LIB} ${RENDER_LIB} ${DIALOG_SYSTEM_LIB} ${SFML_LIBS})
	target_link_libraries(${BIN_NAME} debug ${MODEL_LIB} ${RENDER_LIB} ${DIALOG_SYSTEM_LIB} ${SFML_LIBS_D})
else ()
    target_link_libraries(${BIN_NAME} ${MODEL_LIB} ${RENDER_LIB} ${DIALOG_SYSTEM_LIB} ${SFML_LIBS})
endif()