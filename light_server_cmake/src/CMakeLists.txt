cmake_minimum_required(VERSION 2.8)

include_directories(${CMAKE_SOURCE_DIR}/include)
include_directories(${CMAKE_SOURCE_DIR}/include/utils)

add_subdirectory(utils)

aux_source_directory(. DIR_SRC)

add_library(lightserve SHARED ${DIR_SRC})

target_link_libraries(lightserve lightutils)