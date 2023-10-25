#include "../include/Node.hpp"

template<typename T>
Node<T>::Node(const T& data, Node<T>* next, Node<T>* back){
    this->data = data;
    this->next = next;
    this->back = back;
}