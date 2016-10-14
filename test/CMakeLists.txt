cmake_minimum_required(VERSION 3.2.2)

project(fappybird)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -pedantic -std=c++1y")

set(SOURCES
        "main.cpp"
    )

set(HEADERS
        "../include/fixed_string.hpp"
        "../include/chars_utils.hpp"
        "../include/tokenaizer.hpp"
    )

#include_directories("../3rdparty/pugixml/src/")
include_directories("../3rdparty/Catch/single_include/")
#add_subdirectory("../3rdparty/pugixml/")

add_executable(fappybird ${SOURCES} ${HEADERS})
#target_link_libraries(fappybird pugixml)
