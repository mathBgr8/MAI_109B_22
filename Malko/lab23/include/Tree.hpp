#pragma once
#include "./Node.hpp"
#include "../../lab26/include/Stack.hpp"

template<typename T>
class Tree{
public:
    Tree();
    Tree(const T&);
    Tree(const std::initializer_list<T>&);
    Tree(const Tree<T>&);

    void newNode(const T& = T(), NodeTree<T>* = nullptr);
    void delNode(const NodeTree<T>*);
    NodeTree<T>* findNode(const T&) const;

    size_t countWidth(const NodeTree<T>* = nullptr, Vector<int>* = new Vector<int>(1), size_t = 0);
    void print(std::ostream&, const NodeTree<T>* = nullptr, size_t = 0) const;

    ~Tree();
private:
    void build(const NodeTree<T>*, NodeTree<T>*);
    NodeTree<T>* root;
};

template<typename T>
std::ostream& operator<<(std::ostream&, const Tree<T>&);

#include "../src/Tree.cpp"