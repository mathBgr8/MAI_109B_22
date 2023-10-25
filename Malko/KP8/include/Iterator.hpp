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
    Iterator(const Iterator<T>&);

    Iterator<T>& operator++();
    T& operator*() const;
    Iterator<T> operator+(size_t);

    bool operator==(const Iterator<T>&) const;
    bool operator!=(const Iterator<T>&) const;

private:
    Node<T>* node;
};

#include "../src/Iterator.cpp"