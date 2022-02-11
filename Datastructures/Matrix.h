#include <iostream>
#include <vector>

//https://medium.com/@furkanicus/how-to-create-a-matrix-class-using-c-3641f37809c7

template<typename T>
class Matrix{

    const size_t m_size;
    int m_value {0};
    std::vector<std::vector<T>> m_matrix;

public:

    explicit Matrix(const size_t size):m_size(size),
    m_matrix(m_size, std::vector<T>(m_size, static_cast<T>(0))){}
    Matrix(const size_t size, const int value):m_size(size), m_value(value),m_matrix(m_size, std::vector<T>(m_size, m_value)){}

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mt){

        for(auto& r : mt.m_matrix){
            for(auto& c : r){
                os << c <<  ",";
            }
            os << "\n";
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, const Matrix& mt){
        for(auto& r : mt.m_matrix){
            for(auto& c : r){
//                is >> *c;
            }
        }
        return is;
    }

    void set(int r, int c, int value){
        m_matrix[r][c] = value;
    }

    Matrix operator+(const Matrix& rhs){

        Matrix newMatrix(this->m_size, this->m_value + rhs.m_value);
        return newMatrix;
    }

    Matrix operator*(const Matrix& rhs){
        Matrix newMatrix(this->m_size);
        for(int i = 0; i < this->m_size; ++i){
            for(int j = 0; j < this->m_size; ++j){
                const auto newSum = this->m_matrix[i][j] + rhs.m_matrix[j][i];
                newMatrix.set(i, j, newSum);
            }
        }
    }
};