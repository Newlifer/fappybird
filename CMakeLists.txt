cmake_minimum_required(VERSION 3.2.2)

project(fappybird)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -pedantic -std=c++1y")

set(SOURCES
        "src/main.cpp"
    )

set(HEADERS
        "include/fixed_string.hpp"
    )

include_directories("3rdparty/pugixml/src/")
add_subdirectory("3rdparty/pugixml/")

add_executable(fappybird ${SOURCES} ${HEADERS})
target_link_libraries(fappybird pugixml)
