#include "Matrix.h"

int main(int argc, char* argv[]){

    Matrix<int> mat1 (3, 2);
    std::cout << mat1 << std::endl;
    Matrix<int> mat2 (3, 1);
    std::cout << mat2 << std::endl;
    Matrix<int> mat3 (3, 3);
    std::cout << mat3 << std::endl;
    std::cout << "LValue Addition" << std::endl;
    std::cout << mat1 + mat3 << std::endl;
    std::cout << "RValue Addition" << std::endl;
    const auto mat4 = mat2 + mat3;
    std::cout << mat4 << std::endl;

    std::cout << "Testin istream overloading" << std::endl;
    Matrix<int> mat5 (2);

    std::cin >> mat5;

    return 0;
}