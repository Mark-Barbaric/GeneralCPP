#pragma once
#include <iostream>
#include <vector>

namespace CPPGuidelines{
    struct Object{
        int m_x {0}, m_y {0}, m_z{0};

        Object(int x, int y, int z):m_x(x), m_y(y), m_z(z){}

        Object(const Object& rhs){
            std::cout << "Copy Constructor Invoked.\n";
            m_x = rhs.m_x;
            m_y = rhs.m_y;
            m_z = rhs.m_z;
        }

    };

    inline void runVectorTest(){
        std::vector<Object> objects;
        objects.push_back(Object(1,2,3));
        objects.push_back(Object(4,5,6));
    }

    inline void runVectorOptimised(){
        std::vector<Object> objects;
        objects.reserve(2);
        objects.emplace_back(1,2,3);
        objects.emplace_back(4,5,6);
    }

    inline void runVectorBestPractices(){
        runVectorTest();
        runVectorOptimised();
    }
}