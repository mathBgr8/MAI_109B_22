#pragma once
#include "Node.hpp"

template<typename T>
class List;

template<typename T>
class Iterator{
    friend class List<T>;
public:
    Iterator();
    Iterator(const List<T>&);
    Iterator(Node<T>*);

    Iterator& operator++();
    Iterator& operator--();
    T& operator*() const;
    Iterator operator+(size_t);

    bool operator==(const Iterator<T>&) const;
    bool operator!=(const Iterator<T>&) const;

private:
    Node<T>* _node;
};

#include "../src/Iterator.cpp"