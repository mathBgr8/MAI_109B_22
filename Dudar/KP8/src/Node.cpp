#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(const T& data, Node<T>* next, Node<T>* back){
    this->_data = data;
    this->_back = back;
    this->_next = next;
}