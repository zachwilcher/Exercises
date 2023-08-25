cmake_minimum_required(VERSION 3.18)

project(cpplua LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(TARGET_EXE interpreter CACHE INTERNAL "name of the executable")

add_executable(${TARGET_EXE})

find_package(Lua REQUIRED)
target_include_directories(${TARGET_EXE} PRIVATE ${LUA_INCLUDE_DIR})
target_link_libraries(${TARGET_EXE} PRIVATE ${LUA_LIBRARIES})

target_sources(${TARGET_EXE} PRIVATE main.cpp)