cmake_minimum_required (VERSION 2.6)

project (model)
set (BIN_NAME model)

file (GLOB_RECURSE SRCS
    src/*.cpp
	include/*.hpp
	include/*.h
)

include_directories (
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
	${SFML_INCLUDE_PATH}/
)

add_library (${BIN_NAME} STATIC ${SRCS})

if (MSVC)
    target_link_libraries(${BIN_NAME} optimized ${SFML_LIBS})
	target_link_libraries(${BIN_NAME} debug ${SFML_LIBS_D})
else ()
    target_link_libraries(${BIN_NAME} ${SFML_LIBS})
endif()