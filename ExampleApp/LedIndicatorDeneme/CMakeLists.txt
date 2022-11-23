cmake_minimum_required(VERSION 3.0)

project(HelloWorld)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

add_executable(HelloWorld
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
        )


include_directories(../../Plugin/QLedIndicator/src)
add_library(QLedIndicator SHARED IMPORTED)
set_property(TARGET QLedIndicator PROPERTY IMPORTED_LOCATION "${PROJECT_SOURCE_DIR}/libQLedIndicator.dll")
set_property(TARGET QLedIndicator PROPERTY IMPORTED_IMPLIB "${PROJECT_SOURCE_DIR}/libQLedIndicator.dll.a")

target_link_libraries(HelloWorld PRIVATE
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        QLedIndicator
        )