#pragma once
#include <iostream>

template<typename T>
struct Node{
    Node(const T& = T(), Node<T>* = nullptr);

    T data;
    Node<T>* next;

};

#include "../src/Node.cpp"