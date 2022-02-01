#include "Move.h"

namespace CPPGuidelines{
    inline void runMove(){
        std::cout << "Running Move Example.\n";
        std::cout << "Initializing Entity using implicit conversion.\n";
        Entity entity ("Timothy");
        entity.printName();
        std::cout << "Initializing string2.\n";
        String string2 = "Hello";
        std::cout << "Initializing dest using std::move.\n";
        String dest = std::move(string2);
        dest = dest;
        Entity entity2 (dest);
        std::cout << "String Count: " << String::getCount() << std::endl;
    }

    inline void runCPPGuildelines(){
        std::cout << "Running CPP Guidelines.\n\n";
        runMove();
    }
}