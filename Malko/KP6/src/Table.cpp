#include "../include/Table.hpp"

Table::Table(){
    this->names = Vector<std::string>{"surname", "initials", "sex", "group", "math", "informatics", "philosophy", "economics", "physics"};
}

Table::Table(const Vector<std::string>& names){
    this->names = names;
}

std::ostream& operator<<(std::ostream& stream, const Table& table){
    for(size_t currentName = 0; currentName < table.names.size(); ++currentName){
        stream << table.names[currentName] << ' ';
    }
    stream << '\n';

    for(size_t currentRow = 0; currentRow < table.table.size(); ++currentRow){
        for(size_t currentCollumn = 0; currentCollumn < table.table[currentRow].size(); ++currentCollumn){
            stream << table.table[currentRow][currentCollumn] << ' ';
        }
        stream << '\n';
    }

    return stream;
}