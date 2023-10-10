#include "../include/Node.hpp"

template<typename T>
Bin_Node<T>::Bin_Node(const T& data, Bin_Node<T>* left, Bin_Node<T>* right){
    this->data = data;
    this->left = left;
    this->right = right;
}