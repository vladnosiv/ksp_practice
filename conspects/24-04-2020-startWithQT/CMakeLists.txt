cmake_minimum_required(VERSION 3.15)

project(testProject)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(testProject
    src/main.cpp
    src/widget.cpp
    include/widget.hpp
    src/widget.ui
  )

target_link_libraries(testProject PRIVATE Qt5::Widgets)
