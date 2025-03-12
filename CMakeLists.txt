cmake_minimum_required(VERSION 3.5)

project(cpu-monitoring)

set(CMAKE_PREFIX_PATH "C:/Qt/6.5.3/msvc2019_64")
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if(CMAKE_VERSION VERSION_LESS "3.7.0")
    set(CMAKE_INCLUDE_CURRENT_DIR ON)
endif()

find_package(Qt6 COMPONENTS Widgets REQUIRED)

add_executable(cpu-monitoring
    #src/mainwindow.ui
    src/monitor.cpp
    src/main.cpp
)

target_link_libraries(cpu-monitoring Qt6::Widgets)