#include "../include/List.hpp"

template<typename T>
List<T>::List(){
    this->_root = new Node<T>();
    this->_root->_next = this->_root;
    this->_root->_back = this->_root;
}

template<typename T>
List<T>::List(const size_t size, const T& data){
    this->_root = new Node<T>();
    Node<T>* current = this->_root;
    for(size_t currentNode = 0; currentNode < size; ++currentNode){
        current->_next = new Node<T>(data, this->_root, current);
        current = current->_next;
        this->_root->_back = current;
    }
    this->_root = this->_root->_next;
}

template<typename T>
List<T>::List(const std::initializer_list<T>& list): List(){
    Node<T>* current = this->_root;
    for(T data : list){
        current->_next = new Node<T>(data, this->_root, current);
        current = current->_next;
        this->_root->_back = current;
    }
    this->_root = this->_root->_next;
}

template<typename T>
List<T>::List(const List<T>& other): List(){
    Iterator<T> current = other.begin();
    while(current != other.end()){
        this->push_back(*current);
        ++current;
    }
}

template<typename T>
void List<T>::push_back(const T& data){
    Node<T>* end = this->_root->_back;
    end->_data = data;
    end->_next = new Node<T>(T(), this->_root, end);
    this->_root->_back = end->_next;
}

template<typename T>
void List<T>::push_front(const T& data){
    Node<T>* end = this->_root->_back;
    end->_next = new Node<T>(data, this->_root, end);
    this->_root->_back = end->_next;
    this->_root = end->_next;
}

template<typename T>
void List<T>::pop_back(){
    if(this->_root->_back == this->_root){
        return;
    }
    Node<T>* delNode = this->_root->_back->_back;
    if(this->_root == delNode){
        this->_root = this->_root->_back;
    }
    delNode->_back->_next = delNode->_next;
    delNode->_next->_back = delNode->_back;
    delete delNode;
}

template<typename T>
void List<T>::pop_front(){
    if(this->_root->_back == this->_root){
        return;
    }
    Node<T>* delNode = this->_root;
    delNode->_back->_next = delNode->_next;
    delNode->_next->_back = delNode->_back;
    this->_root = delNode->_next;
    delete delNode;
}

template<typename T>
template<typename ...Args>
void List<T>::emplace_back(const Args&... args){
    this->push_back(T(args...));
}

template<typename T>
template<typename ...Args>
void List<T>::emplace_front(const Args&... args){
    this->push_front(T(args...));
}

template<typename T>
void List<T>::insert(const Iterator<T>& iter, const T& data){
    iter._node->_next = new Node<T>(data, iter._node->_next, iter._node);
    iter._node->_next->_next->_back = iter._node->_next;
}

template<typename T>
void List<T>::erase(const Iterator<T>& start, const Iterator<T>& end){
    
    Iterator<T> current = start;
    ++current;
    start._node->_next = end._node;
    end._node->_back = start._node;

    while(current != end){
        if(current == this->begin()){
            this->_root = end._node;
        }
        Node<T>* delNode = current._node;
        ++current;
        delete delNode;
    }
}

template<typename T>
Iterator<T> List<T>::begin() const{
    return Iterator<T>(this->_root);
}

template<typename T>
Iterator<T> List<T>::end() const{
    return Iterator<T>(this->_root->_back);
}

template<typename T>
void List<T>::deleteK(const T& k){
    Iterator<T> iter = this->begin();
    while(iter != this->end()){
        if(*iter == k){
            if(iter._node == this->_root){
                this->_root = iter._node->_next;
            }
            iter._node->_back->_next = iter._node->_next;
            iter._node->_next->_back = iter._node->_back;
            Node<T>* delNode = iter._node;
            ++iter;
            delete delNode;
            continue;
        }
        ++iter;
    }
}

template<typename T>
List<T>::~List(){
    Node<T>* current = this->_root;
    while(current->_next != this->_root){
        Node<T>* delNode = current;
        current = current->_next;
        delete delNode;
    }
    delete current;
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const List<T>& list){
    Iterator<T> iter = list.begin();
    while(iter != list.end()){
        stream << *iter << ' ';
        ++iter;
    }
    return stream;
}