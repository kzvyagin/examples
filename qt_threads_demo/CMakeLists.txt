cmake_minimum_required(VERSION 3.14)

project(qt_threads_demo LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

set( PUBLIC_HEADERS
     with_event_loop/runnableworker.h
     with_event_loop/taskworker.h
     with_event_loop/taskservice.h
     with_event_loop/stablethread.h
     with_event_loop/stabletaskservice.h
     with_event_loop/periodicworker.h
     simple_threads/simplethread.h
     simple_threads/simplerun.h
)

set( PUBLIC_SOURCES
     with_event_loop/runnableworker.cpp
     with_event_loop/taskworker.cpp
     with_event_loop/taskservice.cpp
     with_event_loop/stabletaskservice.cpp
     with_event_loop/periodicworker.cpp
     simple_threads/simplethread.cpp
     simple_threads/simplerun.cpp
)

add_executable(qt_threads_demo
    ${PUBLIC_HEADERS}
    ${PUBLIC_SOURCES}
    main.cpp
)

target_link_libraries(qt_threads_demo Qt${QT_VERSION_MAJOR}::Core)

target_include_directories(qt_threads_demo PUBLIC with_event_loop)
target_include_directories(qt_threads_demo PUBLIC simple_threads)


install(TARGETS qt_threads_demo
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
