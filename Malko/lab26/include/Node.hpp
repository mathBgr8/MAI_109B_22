#pragma once

template<typename T>
struct Node{

    Node(const T& = T(), Node<T>* = nullptr, Node<T>* = nullptr);

    Node<T>* next;
    Node<T>* back;
    T data;
};

#include "../src/Node.cpp"