#include <iostream>

void runExceptions();
[[noreturn]] void throwCustomException();

class CustomException : public std::exception{

    std::string m_exceptionMessage;
public:

    explicit CustomException(std::string message):m_exceptionMessage(std::move(message)){}

    [[nodiscard]] const char* what() const noexcept override {
        return m_exceptionMessage.c_str();
    }
};

[[noreturn]] void throwCustomException(){
    throw CustomException("This is a custom exception");
}

void runExceptions(){
    try{
        throwCustomException();
    } catch(const std::exception e){
        std::cout << "Bad Alloc exception by value: " << e.what() << std::endl;
    }
}