#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(const T& data, Node<T>* next){
    this->data = data;
    this->next = next;
}