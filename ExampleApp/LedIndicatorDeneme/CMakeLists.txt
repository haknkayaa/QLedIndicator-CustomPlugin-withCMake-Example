cmake_minimum_required(VERSION 3.0)

project(HelloWorld)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(WIN32)
    message("OS: ${CMAKE_SYSTEM_NAME}")
    set(QT_DIR "C:\\DevTools\\Qt\\5.15.2\\mingw81_64\\lib\\cmake\\Qt5")
    set(QT_QPA_PLATFORM_PLUGIN_PATH "C:\\DevTools\\Qt\\5.15.2\\mingw81_64\\plugins\\platforms")
    set(QT_PLUGIN_PATH "C:\\DevTools\\Qt\\5.15.2\\mingw81_64\\plugins")

    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
    set(BUILD_SHARED_LIBS TRUE)
else()
    message("OS: ${CMAKE_SYSTEM_NAME}")
    set(QT_DIR "/opt/Qt/5.15.2/gcc_64/lib/cmake/Qt5")
    set(QT_QPA_PLATFORM_PLUGIN_PATH "/opt/Qt/5.15.2/gcc_64/plugins/platforms")
    set(QT_PLUGIN_PATH "/opt/Qt/5.15.2/gcc_64/plugins")
endif()

set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} ${QT_DIR})

find_package(Qt5 COMPONENTS Core Widgets Gui REQUIRED)

add_executable(HelloWorld
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h
        src/mainwindow.ui
        )


include_directories(../../Plugin/QLedIndicator/src)


target_link_libraries(HelloWorld PRIVATE
        Qt5::Core
        Qt5::Widgets
        Qt5::Gui
        ${CMAKE_BINARY_DIR}/libQLedIndicator.dll
        )