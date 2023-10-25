#pragma once
#include <iostream>
#include "./Node.hpp"
#include "./Iterator.hpp"

template<typename T>
class Stack{
template<typename K>
friend std::ostream& operator<<(std::ostream&, const Stack<K>&);
public:

    Stack();
    Stack(const size_t, const T& = T());
    Stack(const std::initializer_list<T>&);
    Stack(const Stack<T>&);
    Stack(Stack<T>&&);

    void push(const T&);
    void pop();

    T& top() const;
    size_t size() const;

    bool empty() const;
    void clear();

    Iterator<T> begin() const;
    Iterator<T> end() const;

    Stack<T>& operator=(const Stack<T>&);

    Stack<T> operator+(const Stack<T>&) const;
    void sort(const Iterator<T>& = Iterator<T>(), const Iterator<T>& = Iterator<T>());

    ~Stack();

private:
    Node<T>* head;
    size_t sz;
};

template<typename T>
std::ostream& operator<<(std::ostream&, const Stack<T>&);

#include "../src/Stack.cpp"