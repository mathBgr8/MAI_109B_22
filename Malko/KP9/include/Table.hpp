#pragma once
#include "../../KP7/include/Vector.hpp"
#include <fstream>
#include <sstream>

struct complex{
    complex(int64_t x = int64_t(), int64_t y = int64_t()): real(x), imag(y){}
    int64_t real;
    int64_t imag;
    bool operator>(const complex&) const;
    bool operator<(const complex&) const;
};

template<typename T>
class Table{
template<typename K>
friend std::ostream& operator<<(std::ostream&, const Table<K>&);
public:
    Table();
    Table(const std::string&);

    void push_back(const std::pair<complex, T>&);
    void sort();

    ~Table() = default;

private:
    Vector<std::pair<complex, T>> table;
};

template<typename K>
std::ostream& operator<<(std::ostream&, const Table<K>&);

#include "../src/Table.cpp"