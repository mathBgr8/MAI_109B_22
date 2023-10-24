#include "../include/DataBase.hpp"

DataBase::DataBase(): DataBase("Base"){}

DataBase::DataBase(const std::string& fileName): name(fileName){
    if(std::filesystem::exists(fileName)){
        this->FromFile();
    }
    else{
        this->tables.emplace_back();
        this->ToFile();
    }
}

size_t DataBase::femalesGrants(size_t group) const{
    size_t ans = 0;
    for(size_t currentStudent = 0; currentStudent < this->tables[0].table.size(); ++currentStudent){
        if(std::stoi(this->tables[0].table[currentStudent][3]) != group || this->tables[0].table[currentStudent][2] != "f"){
            continue;
        }
        double sum = 0, counter = 0;
        for(size_t currentMark = 4; currentMark < this->tables[0].names.size(); ++currentMark){
            ++counter;
            sum += std::stoi(this->tables[0].table[currentStudent][currentMark]);
        }

        if(sum/counter >= 4.0f){
            ++ans;
        }
    }

    return ans;
}

void DataBase::FromFile(){
    std::ifstream fileReader(this->name);

    size_t DBSize;
    fileReader >> DBSize;

    for(size_t currentTable = 0; currentTable < DBSize; ++currentTable){
        size_t RowSize, CollunmSize;
        fileReader >> RowSize >> CollunmSize;

        Vector<std::string> names;
        for(size_t currentName = 0; currentName < CollunmSize; ++currentName){
            std::string str;
            fileReader >> str;
            names.push_back(str);
        }

        this->tables.emplace_back(names);
        for(size_t currentRow = 0; currentRow < RowSize; ++currentRow){
            this->tables.back().table.emplace_back(CollunmSize);
            for(size_t currentCollunm = 0; currentCollunm < CollunmSize; ++currentCollunm){
                fileReader >> this->tables.back().table[currentRow][currentCollunm];
            }
        }

    }

    fileReader.close();
}

void DataBase::ToFile() const{
    std::ofstream fileWritter(this->name);

    fileWritter << this->tables.size() << '\n';
    for(size_t currentTable = 0; currentTable < this->tables.size(); ++currentTable){
        fileWritter << this->tables[currentTable].table.size() << ' '
                    << this->tables[currentTable].names.size() << '\n';

        for(size_t currentName = 0; currentName < this->tables[currentTable].names.size(); ++currentName){
            fileWritter << this->tables[currentTable].names[currentName] << ' ';
        }
        fileWritter << '\n';

        for(size_t currentRow = 0; currentRow < this->tables[currentTable].table.size(); ++currentRow){
            for(size_t currentCollunm = 0; currentCollunm < this->tables[currentTable].names.size(); ++currentCollunm){
                fileWritter << this->tables[currentTable].table[currentRow][currentCollunm] << ' ';
            }
            fileWritter << '\n';
        }
    }

    fileWritter.close();
}

DataBase::~DataBase(){
    this->ToFile();
}

std::ostream& operator<<(std::ostream& stream, const DataBase& DB){
    for(size_t currentTable = 0; currentTable < DB.tables.size(); ++currentTable){
        stream << DB.tables[currentTable] << '\n';
    }
    return stream;
}