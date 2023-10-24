#pragma once
#include "Table.hpp"
#include <string>
#include <fstream>
#include <filesystem>

class DataBase{
friend std::ostream& operator<<(std::ostream&, const DataBase&);
public:
    DataBase();
    DataBase(const std::string&);

    size_t femalesGrants(size_t) const;

    ~DataBase();

private:

    void ToFile() const;
    void FromFile();

    std::string name;
    Vector<Table> tables;
};

std::ostream& operator<<(std::ostream&, const DataBase&);

#include "../src/DataBase.cpp"