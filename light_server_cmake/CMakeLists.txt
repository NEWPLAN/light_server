cmake_minimum_required(VERSION 2.8)

project(http_serv_test)
set(CMAKE_VERBOSE_MAKEFILE on )

add_compile_options(-std=c++11 -Os)
message(STATUS "optional:-std=c++11")

add_definitions(-DNODEBUG)
message(STATUS "optional: no debug")

add_subdirectory(src)


include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/utils)

add_executable(http_server apps/HttpServer.cpp)

target_link_libraries(http_server lightserve pthread)