#include "../include/Iterator.hpp"

template<typename T>
Iterator<T>::Iterator(){
    this->_node = nullptr;
}

template<typename T>
Iterator<T>::Iterator(Node<T>* node){
    this->_node = node;
}

template<typename T>
Iterator<T>::Iterator(const List<T>& list){
    this->_node = list._root;
}

template<typename T>
Iterator<T>& Iterator<T>::operator++(){
    this->_node = this->_node->_next;
    return *this;
}

template<typename T>
Iterator<T>& Iterator<T>::operator--(){
    this->_node = this->_node->_back;
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator+(size_t size){
    Iterator<T> returnIterator(*this);
    while(size != 0){
        ++returnIterator;
        --size;
    }
    return returnIterator;
}

template<typename T>
T& Iterator<T>::operator*() const{
    return this->_node->_data;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& other) const{
    return this->_node == other._node;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const{
    return this->_node != other._node;
}