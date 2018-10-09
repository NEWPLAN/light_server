cmake_minimum_required(VERSION 2.8)

include_directories(${CMAKE_SOURCE_DIR}/include/utils)

add_compile_options(-lpthread)

aux_source_directory(. UTIL_SRC)
add_library(lightutils SHARED ${UTIL_SRC})