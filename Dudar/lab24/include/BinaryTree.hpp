#pragma once
#include "Node.hpp"
#include "../../lab26/include/Stack.hpp"
#include <iostream>
#include <string>

bool isOperator(const char);
size_t getPriority(const char);

class BinaryTree{
public:
    BinaryTree() = delete;
    BinaryTree(const std::string&);
    BinaryTree(const BinaryTree&);
    BinaryTree(BinaryTree&&);

    BinaryTree operator=(const BinaryTree&);

    Bin_Node<std::string>* makeTree() const;

    BinaryTree copy() const;

    void print(Bin_Node<std::string>* = nullptr, size_t = 0) const;

    void clear();

    ~BinaryTree();

private:
    Bin_Node<std::string>* root;
    std::string infStr;
};

#include "../src/BinaryTree.cpp"