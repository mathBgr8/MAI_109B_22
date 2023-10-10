#pragma once
#include "Iterator.hpp"

template<typename T>
class List{
    friend class Iterator<T>;
public:
    List();
    List(const size_t, const T& = T());
    List(const std::initializer_list<T>&);
    List(const List<T>&);

    void push_back(const T&);
    void push_front(const T&);

    void pop_back();
    void pop_front();
    
    template<typename ...Args>
    void emplace_back(const Args&...);
    template<typename ...Args>
    void emplace_front(const Args&...);

    void insert(const Iterator<T>&, const T&);
    void erase(const Iterator<T>&, const Iterator<T>&);

    Iterator<T> begin() const;
    Iterator<T> end() const;

    void deleteK(const T&);
    template<typename K>
    friend std::ostream& operator<<(std::ostream&, const List<K>&);
    ~List();
private:
    Node<T>* _root;
};

#include "../src/List.cpp"