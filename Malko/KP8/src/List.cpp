#include "../include/List.hpp"

template<typename T>
List<T>::List(): head(nullptr), sz(0){}

template<typename T>
List<T>::List(const size_t size, const T& data): List(){
    for(size_t currentPush = 0; currentPush < size; ++currentPush){
        this->push_front(data);
    }
    this->sz = size;
}

template<typename T>
List<T>::List(const std::initializer_list<T>& list){
    T* temp = new T[list.size()];
    size_t index = 0;
    for(T data : list){
        temp[index] = data;
        ++index;
    }

    for(int64_t currentElem = list.size() - 1; currentElem >= 0; --currentElem){
        this->push_front(temp[currentElem]);
    }

    delete[] temp;
    this->sz = list.size();
}

template<typename T>
List<T>::List(const List& other){
    T* temp = new T[other.sz];
    Iterator<T> pointer = other.begin();
    Iterator<T> end = other.end();
    size_t index = 0;
    while(pointer != end){
        temp[index] = *pointer;
        ++pointer;
        ++index;
    }
    temp[other.size() - 1] = *end;

    for(int64_t currentElem = other.size() - 1; currentElem >= 0; --currentElem){
        this->push_front(temp[currentElem]);
    }

    delete[] temp;
    this->sz = other.sz;
}

template<typename T>
void List<T>::push_front(const T& data){
    this->head = new Node<T>(data, this->head);
    ++this->sz;
}

template<typename T>
void List<T>::pop_front(){
    if(this->head == nullptr){
        throw std::logic_error("Cannot pop empty list.");
    }
    Node<T>* nextNode = this->head->next;
    delete this->head;
    this->head = nextNode;
    --this->sz;
}

template<typename T>
template<typename ...Args>
void List<T>::emplace_front(const Args&... args){
    this->push_front(T(args...));
}

template<typename T>
Iterator<T> List<T>::begin() const{
    return Iterator<T>(this->head);
}

template<typename T>
Iterator<T> List<T>::end() const{
    Node<T>* currentNode = this->head;
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    return Iterator<T>(currentNode);
}

template<typename T>
void List<T>::insert(const Iterator<T>& nd, const T& data){
    Iterator<T> pointer = this->begin();
    while(pointer != nd){
        ++pointer;
    }
    pointer.node->next = new Node<T>(data, pointer.node->next);
    ++this->sz;
}

template<typename T>
void List<T>::erase(const Iterator<T>& first, const Iterator<T>& second){
    Iterator<T> pointer = first;
    ++pointer;
    while(pointer != second){
        Node<T>* deleteNode = pointer.node;
        ++pointer;
        delete deleteNode;
        --this->sz;
    }
    first.node->next = second.node;
}

template<typename T>
size_t List<T>::size() const{
    return this->sz;
}

template<typename T>
bool List<T>::empty() const{
    return !(this->head == nullptr);
}

template<typename T>
void List<T>::clear(){
    while(this->sz != 0){
        this->pop_front();
    }
}

template<typename T>
List<T>::~List(){
    this->clear();
}

template<typename T>
void List<T>::deleteK(size_t k){
    size_t midle = this->size() / 2;
    --k;
    size_t left = midle + k / 2;
    size_t right = midle - k / 2 - k % 2;
    this->erase(this->begin()+(right-1), this->begin()+(left+1));
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const List<T>& list){
    Iterator<T> pointer = list.begin();
    for(size_t currentElem = 0; currentElem < list.size(); ++currentElem){
        stream << *pointer << ' ';
        ++pointer;
    }
    return stream;
}