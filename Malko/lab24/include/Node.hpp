#pragma once

template<typename T>
struct Bin_Node{
    Bin_Node(const T& = T(), Bin_Node<T>* = nullptr, Bin_Node<T>* = nullptr);

    Bin_Node<T>* left;
    Bin_Node<T>* right;
    T data;
};

#include "../src/Node.cpp"