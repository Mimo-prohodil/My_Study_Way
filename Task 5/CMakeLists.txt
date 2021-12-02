cmake_minimum_required(VERSION 3.5)

project(Task_5 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Task_5
    main.cpp    
    )

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/sampleText DESTINATION
    ${CMAKE_CURRENT_BINARY_DIR})
