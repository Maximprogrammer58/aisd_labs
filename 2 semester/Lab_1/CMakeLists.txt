cmake_minimum_required(VERSION 3.11)

project(Set CXX)

set(CMAKE_CXX_STANDARD 23)

if(MSVC)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS true)

    if(CMAKE_CXX_FLAGS MATCHES "/W[0-4]")
        string(REGEX REPLACE "/W[0-4]" "/W4" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")   
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
    endif()
endif()

add_library(Set SHARED
    "include/Set.h"
    "src/Set.cc"
    "include/Random.h"
    "src/Random.cc"
    "include/TimeTest.h"
    "src/TimeTest.cc"
    "include/Task.h"
    "src/Task.cc"
)
target_include_directories(Set PUBLIC "include")

add_executable(main "main.cc")
target_link_libraries(main Set)