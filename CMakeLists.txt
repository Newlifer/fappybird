cmake_minimum_required(VERSION 3.2.2)

project(fappybird)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -O2 -Wall -Wextra -pedantic -std=c++14")

set(SOURCES
    )

set(HEADERS
    )

include_directories("3rdparty/pugixml/src/")
add_subdirectory("3rdparty/pugixml/")

add_executable(fappybird "src/main.cpp" ${SOURCES} ${HEADERS})
target_link_libraries(fappybird pugixml)
