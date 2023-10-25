#include "../include/Table.hpp"

template<typename T>
Table<T>::Table(): Table("table"){}

template<typename T>
Table<T>::Table(const std::string& fileName){
    std::ifstream fileReader(fileName);

    std::string str;
    while(getline(fileReader, str)){
        std::stringstream stream(str);
        T data;
        int64_t real, imag;
        stream >> real >> imag >> data;
        this->push_back(std::pair<complex, T>(complex(real, imag), data));
    }

    fileReader.close();
}

template<typename T>
void Table<T>::push_back(const std::pair<complex, T>& data){
    this->table.push_back(data);
}

template<typename T>
void Table<T>::sort(){

    for(size_t i = 0; i + 2 < this->table.size(); i += 2){
        for(size_t j = 0; j + 2 < this->table.size(); j += 2){
            if(this->table[j].first > this->table[j + 2].first){
                std::swap(this->table[j], this->table[j + 2]);
            }
        }
    }

    for(size_t i = 1; i + 2 < this->table.size(); i += 2){
        for(size_t j = 1; j + 2 < this->table.size(); j += 2){
            if(this->table[j].first > this->table[j + 2].first){
                std::swap(this->table[j], this->table[j + 2]);
            }
        }
    }

    for(size_t i = 0; i + 1 < this->table.size(); ++i){
        if(this->table[i].first > this->table[i + 1].first){
            std::swap(this->table[i], this->table[i + 1]);
        }
    }

}

bool complex::operator<(const complex& other) const{
    if(this->real < other.real) return true;
    return false;
}

bool complex::operator>(const complex& other) const{
    if(this->real > other.real) return true;
    return false;
}

template<typename K>
std::ostream& operator<<(std::ostream& stream, const Table<K>& table){
    for(size_t currentElem = 0; currentElem < table.table.size(); ++currentElem){
        stream << table.table[currentElem].first.real << ' '
               << table.table[currentElem].first.imag << ' '
               << table.table[currentElem].second << '\n';
    }

    return stream;
}