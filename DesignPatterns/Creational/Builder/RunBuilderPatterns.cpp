#include "HTML.h"
#include <iostream>

inline void runHTMLBuilderExample(){
    std::cout << "Running HTML Builder Example.\n";
    auto builder = HTMLElement::build("ul");
    builder->addChild("li", "hello")->addChild("li", "world");
    std::cout << builder->str() << std::endl;
}

inline void runBuilderPatternExamples(){
    std::cout << "Running Builder Pattern Examples.\n\n";
    runHTMLBuilderExample();
}
