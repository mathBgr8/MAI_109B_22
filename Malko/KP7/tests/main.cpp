#include "../include/Matrix.hpp"
#include "benchmark.cpp"

int main(){

    benchmark();
    Matrix mat("Matrix");
    std::cout << mat;
    Vector<int64_t> vec = mat * Vector<int64_t>{1, 2, 3};
    for(size_t currentElem = 0; currentElem < vec.size(); ++currentElem){
        std::cout << vec[currentElem] << ' ';
    }

    return 0;
}