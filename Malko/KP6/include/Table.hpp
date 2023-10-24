#pragma once
#include <string>
#include "../../KP7/include/Vector.hpp"

class DataBase;

class Table{
friend class DataBase;
friend std::ostream& operator<<(std::ostream&, const Table&);
public:
    Table();
    Table(const Vector<std::string>&);
private:
    Vector<std::string> names;
    Vector<Vector<std::string>> table;
};

std::ostream& operator<<(std::ostream&, const Table&);

#include "../src/Table.cpp"