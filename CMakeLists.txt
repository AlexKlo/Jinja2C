cmake_policy(SET CMP0025 NEW)
project(jinja2cppwrapper)

cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")

find_library(JINJA2CPP_LIBRARY jinja2cpp REQUIRED)
find_path(JINJA2CPP_INCLUDE_DIR jinja2cpp REQUIRED)

message(STATUS "Found jinja2cpp library: ${JINJA2CPP_LIBRARY}")
message(STATUS "Found jinja2cpp include dir: ${JINJA2CPP_INCLUDE_DIR}")

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${JINJA2CPP_INCLUDE_DIR})

add_library(jinja2cppwrapper SHARED)

file(GLOB_RECURSE SOURCES src/*.cpp)

target_sources(jinja2cppwrapper PRIVATE ${SOURCES})

target_link_libraries(jinja2cppwrapper PRIVATE ${JINJA2CPP_LIBRARY})

install(TARGETS jinja2cppwrapper LIBRARY DESTINATION lib)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/ DESTINATION include/jinja2cppwrapper)