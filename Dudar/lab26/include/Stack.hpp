#pragma once
#include <iostream>

template<typename T>
class Iterator;

template<typename T>
struct Node{

    Node(const T& = T(), Node<T>* = nullptr, Node<T>* = nullptr);

    Node<T>* next;
    Node<T>* back;
    T data;
};

template<typename T>
class Stack{
public:
    Stack();
    Stack(const size_t, const T& = T());
    Stack(const std::initializer_list<T>&);
    Stack(const Stack<T>&);

    void push(const T&);
    void pop();
    T& top() const;
    size_t size() const;
    bool empty() const;
    void clear();

    Iterator<T> begin() const;
    Iterator<T> end() const;

    void sort(const Iterator<T>& = Iterator<T>(), const Iterator<T>& = Iterator<T>());
    void print() const;

    Stack<T> operator+(const Stack<T>&) const;

    ~Stack();

private:
    Node<T>* root;
    size_t sz;
};

template<typename T>
struct Iterator{
    Iterator();
    Iterator(const Node<T>*);
    Iterator(const Stack<T>&);

    Iterator& operator++();
    Iterator& operator--();
    T& operator*() const;
    bool operator==(const Iterator<T>&) const;
    bool operator!=(const Iterator<T>&) const;

    Node<T>* node;
};

#include "../src/Stack.cpp"