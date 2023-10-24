#pragma once
#include "Vector.hpp"
#include <fstream>
#include <string>
#include <sstream>

class Matrix{
friend std::ostream& operator<<(std::ostream&, const Matrix);
public:

    Matrix();
    Matrix(const std::string&);

    Vector<int64_t> operator*(const Vector<int64_t>&) const;

private:
    size_t n = 0, m = 0;
    Vector<int64_t> LB;
    Vector<double> YE;
};

std::ostream& operator<<(std::ostream&, const Matrix);

#include "../src/Matrix.cpp"