#pragma once
#include <iostream>

template<typename T>
struct Node{
    Node(const T& = T(), Node<T>* = nullptr, Node<T>* = nullptr);

    T _data;
    Node<T>* _next;
    Node<T>* _back;
};

#include "../src/Node.cpp"