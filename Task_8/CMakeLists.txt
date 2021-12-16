cmake_minimum_required(VERSION 3.10)

project(HW_07 LANGUAGES CXX)
set(PROJECT_LABEL hw-07)

#*******************************************************************************
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

#*******************************************************************************
if(NOT (CMAKE_BUILD_TYPE))
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Тип сборки" FORCE)
  message(STATUS "Build type: ${CMAKE_BUILD_TYPE} (default)")
else()
  message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
endif(NOT (CMAKE_BUILD_TYPE))

#*******************************************************************************
find_package(Git REQUIRED)
#find_package(Threads REQUIRED)

#*******************************************************************************
find_path(PROTOBUF_PATH ".git"
  PATHS "${CMAKE_SOURCE_DIR}/protobuf"
  DOC "PROTOBUF_PATH: Библиотека сериализации/десериализации данных"
  NO_DEFAULT_PATH
)
if(${PROTOBUF_PATH} STREQUAL "PROTOBUF_PATH-NOTFOUND")
  set(PROTOBUF_PATH "${CMAKE_CURRENT_SOURCE_DIR}/protobuf")
  set(PROTOBUF_GIT "https://github.com/protocolbuffers/protobuf.git")
  execute_process(
    COMMAND ${GIT_EXECUTABLE} clone --recurse-submodules --depth=1 ${PROTOBUF_GIT} ${PROTOBUF_PATH}
    RESULT_VARIABLE GIT_RESULT
    OUTPUT_VARIABLE GIT_OUTPUT)
  if(NOT (GIT_RESULT EQUAL "0") )
    message(FATAL_ERROR "Error downloading protobuf")
  endif()
endif()

list(APPEND CMAKE_MODULE_PATH "${PROTOBUF_PATH}/cmake")

option(protobuf_BUILD_TESTS "Build tests" OFF)
add_subdirectory(protobuf/cmake)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_BINARY_DIR}/protobuf/cmake/lib/cmake/protobuf")

#*******************************************************************************
find_package(Protobuf)
set(PROTO_FILES
  College.proto
)

protobuf_generate_cpp(PROTO_SOURCES PROTO_HEADERS ${PROTO_FILES})

#*******************************************************************************
add_executable(${PROJECT_LABEL}
  main.cpp
  ${PROTO_FILES}
  ${PROTO_SOURCES}
  ${PROTO_HEADERS}
)
target_link_libraries(${PROJECT_LABEL} PRIVATE
  libprotobuf
)

target_include_directories(${PROJECT_LABEL} PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}
)
