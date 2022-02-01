cmake_minimum_required(VERSION 3.19)
project(GeneralCPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(GeneralCPP main.cpp)
add_library(SOLID Chapter1/SOLID/RunSOLIDExamples.cpp Chapter1/SOLID/SingleResponsability.h)
target_link_libraries(GeneralCPP SOLID)
add_library(CPP_GuideLines CPP_GuideLines/Move.h CPP_GuideLines/RunCPPGuideLines.cpp)
target_link_libraries(GeneralCPP CPP_GuideLines)
add_library(DesignPatterns DesignPatterns/Creational/RunCreationalPatterns.cpp DesignPatterns/Creational/Singleton.h)
target_link_libraries(GeneralCPP DesignPatterns)
