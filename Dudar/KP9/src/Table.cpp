#include "../include/Table.hpp"

template<typename T>
void Table<T>::push_back(const std::pair<std::string, T>& data){
    this->table.push_back(data);
}

template<typename T>
void Table<T>::print() const{
    for(size_t currentPair = 0; currentPair < this->table.size(); ++currentPair){
        std::cout << this->table[currentPair].first << ' ' << this->table[currentPair].second << std::endl;
    }
}

template<typename T>
void Table<T>::sort(){
    for(size_t i = 0; i < this->table.size(); ++i){
        for(size_t j = 0; j < this->table.size() - 1; ++j){
            if(this->table[j] > this->table[j+1]){
                std::swap(this->table[j], this->table[j+1]);
            }
        }
    }
}