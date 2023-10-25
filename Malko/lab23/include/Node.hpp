#pragma once
#include <iostream>
#include "../../KP7/include/Vector.hpp"

template<typename T>
struct NodeTree{

    NodeTree(const T& = T(), Vector<NodeTree<T>*> = Vector<NodeTree<T>*>());

    T data;
    Vector<NodeTree<T>*> childs;
};

template<typename T>
std::ostream& operator<<(std::ostream&, const NodeTree<T>&);

#include "../src/Node.cpp"