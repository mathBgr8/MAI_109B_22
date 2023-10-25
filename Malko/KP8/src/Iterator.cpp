#include "../include/Iterator.hpp"


template<typename T>
Iterator<T>::Iterator(): node(nullptr){}

template<typename T>
Iterator<T>::Iterator(const List<T>& list): Iterator(list.begin()){}

template<typename T>
Iterator<T>::Iterator(Node<T>* newNode): node(newNode){}

template<typename T>
Iterator<T>::Iterator(const Iterator<T>& other): node(other.node){}

template<typename T>
T& Iterator<T>::operator*() const{
    return this->node->data;
}

template<typename T>
Iterator<T>& Iterator<T>::operator++(){
    this->node = this->node->next;
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator+(size_t num){
    Iterator<T> returnIt(*this);
    for(size_t currentElem = 0; currentElem < num; ++currentElem){
        ++returnIt;
    }
    return returnIt;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& other) const{
    return (this->node == other.node);
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const{
    return (this->node != other.node);
}