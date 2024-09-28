cmake_minimum_required(VERSION 3.11)
project(poly-flip)

find_package(raylib 3.0 QUIET)

if (NOT raylib_FOUND)
  include(FetchContent)

  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/master.tar.gz
  )

  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
  endif()
endif()

include_directories(src/)
add_executable(${PROJECT_NAME} src/main.cpp src/Polygon.cpp)
target_link_libraries(${PROJECT_NAME} raylib)