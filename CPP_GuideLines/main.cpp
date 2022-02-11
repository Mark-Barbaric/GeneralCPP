#include "Move.h"
#include "VectorBestPractice.h"

void runMove();
void runCPPGuidelines();

void runMove(){
    std::cout << "Running Move Example.\n";
    std::cout << "Initializing Entity using implicit conversion.\n";
    CPPGuidelines::Entity entity ("Timothy");
    entity.printName();
    std::cout << "Initializing string2.\n";
    CPPGuidelines::String string2 = "Hello";
    std::cout << "Initializing dest using std::move.\n";
    CPPGuidelines::String dest = std::move(string2);
    dest = dest;
    CPPGuidelines::Entity entity2 (dest);
    std::cout << "String Count: " << CPPGuidelines::String::getCount() << std::endl;
}

void runCPPGuidelines(){
    std::cout << "Running CPP Guidelines.\n\n";
    runMove();
    CPPGuidelines::runVectorBestPractices();
}

int main(int argc, char* argv[]){
    runCPPGuidelines();
    return 0;
}