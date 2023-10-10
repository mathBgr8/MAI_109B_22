#pragma once
#include "../../KP7/include/Vector.hpp"

template<typename T>
class Table{
public:
    Table() = default;
    ~Table() = default;

    void push_back(const std::pair<std::string, T>&);
    void print() const;
    void sort();

private:
    Vector<std::pair<std::string, T>> table;
};

#include "../src/Table.cpp"