cmake_minimum_required(VERSION 3.19)
project(GeneralCPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(GeneralCPP main.cpp)
add_library(SOLID Chapter1/SOLID/RunSOLIDExamples.cpp Chapter1/SOLID/SingleResponsability.h)
target_link_libraries(GeneralCPP SOLID)
add_library(DesignPatterns DesignPatterns/RunDesignPatterns.cpp DesignPatterns/Creational/Singleton.h
        DesignPatterns/Creational/Builder/RunBuilderPatterns.cpp DesignPatterns/Creational/Builder/HTML.h)
target_link_libraries(GeneralCPP DesignPatterns)

add_subdirectory(Datastructures)
add_subdirectory(CPP_GuideLines)
add_subdirectory(Concurrency)