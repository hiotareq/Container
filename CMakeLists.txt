cmake_minimum_required(VERSION 3.16)
project(Container)

set(CMAKE_CXX_STANDARD 14)

add_executable(Container
        main.cpp List.h List.cpp Container.h ListIterator.cpp ListIterator.h list_element.h)
