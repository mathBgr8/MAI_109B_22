#include "../include/Stack.hpp"

template<typename T>
Node<T>::Node(const T& data, Node<T>* next, Node<T>* back){
    this->data = data;
    this->next = next;
    this->back = back;
}

template<typename T>
Stack<T>::Stack(){
    this->root = nullptr;
    this->sz = 0;
}

template<typename T>
Stack<T>::Stack(const size_t size, const T& data): Stack(){
    for(size_t currentData = 0; currentData < size; ++currentData){
        this->push(data);
    }
}

template<typename T>
Stack<T>::Stack(const std::initializer_list<T>& list): Stack(){
    for(T data : list){
        this->push(data);
    }
}

template<typename T>
Stack<T>::Stack(const Stack<T>& other): Stack(){
    Iterator<T> it = other.end();
    while(it != other.begin()){
        this->push(*it);
        --it;
    }
    this->push(*it);
}

template<typename T>
void Stack<T>::push(const T& data){
    this->root = new Node<T>(data, this->root);
    if(this->root->next != nullptr){
        this->root->next->back = this->root;
    }
    ++this->sz;
}

template<typename T>
void Stack<T>::pop(){
    if(this->root == nullptr){
        return;
    }
    Node<T>* delNode = this->root;
    this->root = this->root->next;
    if(this->root != nullptr){
        this->root->back = nullptr;
    }
    --this->sz;
    delete delNode;
}

template<typename T>
T& Stack<T>::top() const{
    return this->root->data;
}

template<typename T>
size_t Stack<T>::size() const{
    return this->sz;
}

template<typename T>
bool Stack<T>::empty() const{
    return (this->sz == 0);
}

template<typename T>
void Stack<T>::clear(){
    while(this->sz > 0){
        this->pop();
    }
}

template<typename T>
Iterator<T> Stack<T>::begin() const{
    return Iterator<T>(this->root);
}

template<typename T>
Iterator<T> Stack<T>::end() const{
    Iterator<T> returnIt(this->root);
    while(returnIt.node->next != nullptr){
        ++returnIt;
    }
    return returnIt;
}

template<typename T>
Stack<T> Stack<T>::operator+(const Stack<T>& other) const{
    Stack<T> returnStack;
    Iterator<T> first(*this);
    Iterator<T> second(other);
    for(size_t currentData = 0; currentData < other.size(); ++currentData){
        returnStack.push(*second);
        ++second;
    }
    for(size_t currentData = 0; currentData < this->size(); ++currentData){
        returnStack.push(*first);
        ++first;
    }

    returnStack.sort();

    return returnStack;
}

template<typename T>
void Stack<T>::sort(const Iterator<T>& start, const Iterator<T>& end){
    if(start.node == nullptr && end.node == nullptr){
        this->sort(this->begin(), this->end());
    }
    if(start.node == nullptr || end.node == nullptr){
        return;
    }
    if(end.node->next == start.node){
        return;
    }
    if(start == end){
        return;
    }

    if(start.node->next == end.node){
        if(*start > *end){
            std::swap(*start, *end);
            return;
        }
        return;
    }
    
    Iterator<T> comp = start;
    Iterator<T> pivot = end;
    bool switched = false;
    while(comp != pivot){
        if(!switched){
            if(*comp >= *pivot){
                std::swap(*comp, *pivot);
                switched = true;
                continue;
            }
            ++comp;
        }
        else{
            if(*pivot < *comp){
                std::swap(*comp, *pivot);
                switched = false;
                continue;
            }
            --pivot;
        }
    }
    Iterator<T> temp = pivot;
    this->sort(start, --pivot);
    this->sort(++temp, end);

}

template<typename T>
void Stack<T>::print() const{
    Iterator<T> temp = this->begin();
    while(temp != this->end()){
        std::cout << *temp << ' ';
        ++temp;
    }
    std::cout << *temp << std::endl;
}

template<typename T>
Stack<T>::~Stack(){
    this->clear();
}

template<typename T>
Iterator<T>::Iterator(){
    this->node = nullptr;
}

template<typename T>
Iterator<T>::Iterator(const Node<T>* node){
    this->node = const_cast<Node<T>*>(node);
}

template<typename T>
Iterator<T>::Iterator(const Stack<T>& stack){
    this->node = const_cast<Node<T>*>(stack.begin().node);
}

template<typename T>
Iterator<T>& Iterator<T>::operator++(){
    this->node = this->node->next;
    return *this;
}

template<typename T>
T& Iterator<T>::operator*() const{
    return this->node->data;
}

template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& other) const{
    return this->node == other.node;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& other) const{
    return !(*this == other);
}

template<typename T>
Iterator<T>& Iterator<T>::operator--(){
    this->node = this->node->back;
    return *this;
}