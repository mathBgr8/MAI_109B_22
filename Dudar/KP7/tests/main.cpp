#include "../include/Matrix.hpp"
#include "benchmark.cpp"

int main(){

    benchmark();
    Matrix mat("Matrix");
    mat.print();
    std::cout << std::endl;
    mat.max();
    mat.print();

    return 0;
}