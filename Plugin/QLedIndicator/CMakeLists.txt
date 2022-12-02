cmake_minimum_required(VERSION 3.0)
set(PLUGIN QLedIndicator)
project(${PLUGIN})

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set( CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/export/bin )
set( CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/export/lib )
set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/export/lib )

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

set(SOURCES
        src/QLedIndicator.cpp
        plugin/QLedIndicatorDesignerPlugin.cpp
        )

set(HEADERS
        src/QLedIndicator.h
        plugin/QLedIndicatorDesignerPlugin.h
        )

set(RESOURCES
        resources/icons.qrc
        )


find_package(Qt5 REQUIRED Core Gui Designer)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
add_definitions(-DQT_PLUGIN)
add_definitions(-DQT_NO_DEBUG)
add_definitions(-DQT_SHARED)
add_definitions(-DQDESIGNER_EXPORT_WIDGETS)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_library(${PLUGIN} SHARED
        ${SOURCES}
        ${HEADERS}
        ${RESOURCES}
        )

target_link_libraries(${PLUGIN}
        ${QT_LIBRARIES}
        Qt5::Core
        Qt5::Gui
        Qt5::Designer
        )


