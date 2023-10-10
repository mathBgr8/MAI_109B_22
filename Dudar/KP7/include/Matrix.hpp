#pragma once

#include "Vector.hpp"
#include <fstream>
#include <string>
#include <sstream>

class Matrix{
public:
   Matrix();
   Matrix(const std::string&);

   void print();
   void max();

private:
    Vector<int64_t> LB;
    Vector<double> YE;
    size_t n = 0;
    size_t m = 0;
};

#include "../src/Matrix.cpp"