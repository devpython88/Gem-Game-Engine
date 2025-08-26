cmake_minimum_required(VERSION 3.10)
project(Gem)

set(LIBS raylib)
set(TEST_TARGET test)
set(LIB_TARGET Gem)

file(GLOB SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/Gem/*.cpp")

add_library(${LIB_TARGET} STATIC ${SOURCES})
target_link_libraries(${LIB_TARGET} PUBLIC ${LIBS})

option(TEST "Build test" ON)
if (TEST)
    add_executable(${TEST_TARGET} ${CMAKE_SOURCE_DIR}/src/main.cpp)
    target_link_libraries(${TEST_TARGET} PRIVATE ${LIB_TARGET})
endif()