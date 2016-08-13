cmake_minimum_required (VERSION 2.6)

project (dialog_system)
set (BIN_NAME dialog_system)

file (GLOB_RECURSE SRCS
    src/*.cpp
    include/*.hpp
    include/*.h
)

include_directories (
    ${CMAKE_CURRENT_SOURCE_DIR}/include/
)

add_library (${BIN_NAME} STATIC ${SRCS})