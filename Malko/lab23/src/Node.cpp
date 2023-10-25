#include "../include/Node.hpp"

template<typename T>
NodeTree<T>::NodeTree(const T& _data, Vector<NodeTree<T>*> vec): data(_data), childs(vec){}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const NodeTree<T>& node){
    return stream << node.data;
}