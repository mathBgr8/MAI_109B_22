#pragma once
#include "Node.hpp"
#include "../../lab26/include/Stack.hpp"
#include <iostream>
#include <string>

class BinaryTree{
friend std::ostream& operator<<(std::ostream&, const BinaryTree&);
public:
    BinaryTree() = delete;
    BinaryTree(const std::string&);
    BinaryTree(const BinaryTree&);
    BinaryTree(BinaryTree&&);

    BinaryTree operator=(const BinaryTree&);
    Bin_Node<std::string>* createTree() const;
    size_t count(Bin_Node<std::string>* = nullptr, size_t = 0) const;

    ~BinaryTree();

private:
    Bin_Node<std::string>* head;
    std::string infStr;
};

std::ostream& operator<<(std::ostream&, const BinaryTree&);
void printNodes(std::ostream&, Bin_Node<std::string>*, size_t = 0);
bool isOperator(const char);
size_t getPriority(const char);

#include "../src/BinaryTree.cpp"