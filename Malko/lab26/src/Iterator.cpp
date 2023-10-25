#include "../include/Iterator.hpp"

template<typename T>
Iterator<T>::Iterator(){
    this->node = nullptr;
}

template<typename T>
Iterator<T>::Iterator(const Node<T>* node){
    this->node = const_cast<Node<T>*>(node);
}

template<typename T>
Iterator<T>::Iterator(const Stack<T>& stack){
    this->node = const_cast<Node<T>*>(stack.begin().node);
}

template<typename T>
Iterator<T>& Iterator<T>::operator++(){
    this->node = this->node->next;
    return *this;
}

template<typename T>
T& Iterator<T>::operator*() const{
    return this->node->data;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& other) const{
    return this->node == other.node;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const{
    return !(*this == other);
}

template<typename T>
Iterator<T>& Iterator<T>::operator--(){
    this->node = this->node->back;
    return *this;
}