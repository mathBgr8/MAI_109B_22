#include "../include/Stack.hpp"

template<typename T>
std::ostream& operator<<(std::ostream& stream, const Stack<T>& stack){
    Iterator<T> temp = stack.begin();
    Iterator<T> tempEnd = stack.end();
    while(temp != tempEnd){
        stream << *temp << ' ';
        ++temp;
    }
    stream << *temp;
    return stream;
}

template<typename T>
Stack<T>::Stack(): head(nullptr), sz(0){}

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
    Iterator<T> temp = other.end();
    while(temp != other.begin()){
        this->push(*temp);
        --temp;
    }
    this->push(*temp);
}

template<typename T>
Stack<T>::Stack(Stack<T>&& temp){
    this->sz = temp.sz;
    this->head = temp.head;
    temp.head = nullptr;
}

template<typename T>
void Stack<T>::push(const T& data){
    this->head = new Node<T>(data, this->head);
    if(this->head->next != nullptr){
        this->head->next->back = this->head;
    }
    ++this->sz;
}

template<typename T>
void Stack<T>::pop(){

    if(this->head == nullptr){
        throw std::logic_error("Cannot pop an empty stack.");
    }

    Node<T>* delNode = this->head;
    this->head = this->head->next;
    if(this->head != nullptr){
        this->head->back = nullptr;
    }
    --this->sz;
    delete delNode;
}

template<typename T>
T& Stack<T>::top() const{
    return this->head->data;
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
    return Iterator<T>(this->head);
}

template<typename T>
Iterator<T> Stack<T>::end() const{
    Iterator<T> returnIt(this->head);
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
Stack<T>& Stack<T>::operator=(const Stack<T>& other){
    this->clear();

    Iterator<T> temp = other.end();
    --temp;

    while(temp != other.begin()){
        this->push(*temp);
        --temp;
    }
    this->push(*temp);

    return *this;
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
Stack<T>::~Stack(){
    this->clear();
}