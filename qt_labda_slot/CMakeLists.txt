cmake_minimum_required(VERSION 3.14)

project(qt_labda_slot LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

set ( PUBLIC_HEADERS
    worker.h
)

set( PUBLIC_SOURCES
    worker.cpp
)
add_executable(qt_labda_slot
  ${PUBLIC_HEADERS}
  ${PUBLIC_SOURCES}
  main.cpp
)
target_link_libraries(qt_labda_slot Qt${QT_VERSION_MAJOR}::Core)

install(TARGETS qt_labda_slot
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
