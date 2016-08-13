cmake_minimum_required (VERSION 2.6)

project (render)
set (BIN_NAME render)
set (MODEL_LIB model)

file (GLOB_RECURSE SRCS
    src/*.cpp
    include/*.hpp
    include/*.h
)

include_directories (
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
    ${CMAKE_CURRENT_SOURCE_DIR}/../model/include/
    ${SFML_INCLUDE_PATH}/
)

add_library (${BIN_NAME} STATIC ${SRCS})

if (MSVC)
    target_link_libraries(${BIN_NAME} optimized ${MODEL_LIB} ${SFML_LIBS})
    target_link_libraries(${BIN_NAME} debug ${MODEL_LIB} ${SFML_LIBS_D})
else ()
    target_link_libraries(${BIN_NAME} ${MODEL_LIB} ${SFML_LIBS})
endif()