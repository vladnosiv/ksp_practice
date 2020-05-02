cmake_minimum_required(VERSION 3.5)

project(ticTacToe)

include_directories("headers/")

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(ticTacToe
    headers/ticTacToe.hpp
    src/ticTacToe.cpp
    src/main.cpp
    src/widget.cpp
    headers/widget.hpp
    src/widget.ui
)

target_link_libraries(ticTacToe PRIVATE Qt5::Widgets)
