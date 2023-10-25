#pragma once
#include "Iterator.hpp"

template<typename T>
class List{
    friend class Iterator<T>;
    template<typename K>
    friend std::ostream& operator<<(std::ostream&, const List<K>&);

public:
    List();
    List(const size_t, const T& = T());
    List(const std::initializer_list<T>&);
    List(const List<T>&);

    void push_front(const T&);

    void pop_front();
    
    template<typename ...Args>
    void emplace_front(const Args&...);

    size_t size() const;
    void insert(const Iterator<T>&, const T&);
    void erase(const Iterator<T>&, const Iterator<T>&);
    void clear();
    bool empty() const;

    Iterator<T> begin() const;
    Iterator<T> end() const;

    void deleteK(size_t);

    ~List();
private:
    Node<T>* head;
    size_t sz;
};

#include "../src/List.cpp"