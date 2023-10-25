#pragma once
#include "../include/Node.hpp"

template<typename T>
class Stack;

template<typename T>
struct Iterator{
    Iterator();
    Iterator(const Node<T>*);
    Iterator(const Stack<T>&);

    Iterator& operator++();
    Iterator& operator--();
    T& operator*() const;
    bool operator==(const Iterator<T>&) const;
    bool operator!=(const Iterator<T>&) const;

    Node<T>* node;
};

#include "../src/Iterator.cpp"