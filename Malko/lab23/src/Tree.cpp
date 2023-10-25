#include "../include/Tree.hpp"

template<typename T>
Tree<T>::Tree(): root(nullptr){}

template<typename T>
Tree<T>::Tree(const T& data): Tree(){
    this->root = new NodeTree<T>(data);
}

template<typename T>
Tree<T>::Tree(const std::initializer_list<T>& list): Tree(){
    for(T data : list){
        this->newNode(data);
    }
}

template<typename T>
Tree<T>::Tree(const Tree<T>& other): Tree(){
    this->root = new NodeTree<T>(other.root->data);
    this->build(other.root, this->root);
}

template<typename T>
void Tree<T>::build(const NodeTree<T>* other, NodeTree<T>* node){
    for(size_t currentChild = 0; currentChild < other->childs.size(); ++currentChild){
        node->childs.push_back(new NodeTree<T>(other->childs[currentChild]->data));
        this->build(other->childs[currentChild], node->childs.back());
    }
}

template<typename T>
void Tree<T>::newNode(const T& data, NodeTree<T>* node){
    if(node != nullptr){
        node->childs.push_back(new NodeTree<T>(data));
    }
    else if(this->root == nullptr){
        this->root = new NodeTree<T>(data);
    }
    else{
        this->root->childs.push_back(new NodeTree<T>(data));
    }
}

template<typename T>
NodeTree<T>* Tree<T>::findNode(const T& data) const{
    Stack<NodeTree<T>*> st1;
    Stack<NodeTree<T>*> st2;
    st1.push(this->root);
    while(!st1.empty()){
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
            }
        if(st2.top()->data == data){
            return st2.top();
        }
        NodeTree<T>* addNode = st2.top();
        st2.pop();
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        for(size_t currentChild = 0; currentChild < addNode->childs.size(); ++currentChild){
            st1.push(addNode->childs[currentChild]);
        }
    }
    return nullptr;
}

template<typename T>
void Tree<T>::delNode(const NodeTree<T>* node){
    for(size_t curerntChild = 0; curerntChild < node->childs.size(); ++curerntChild){
        this->delNode(node->childs[curerntChild]);
    }
    delete node;
}

template<typename T>
void Tree<T>::print(std::ostream& stream, const NodeTree<T>* node, size_t depth) const{
    if(node == nullptr){
        node = this->root;
        if(node == nullptr){
            return;
        }
    }
    for(int64_t currentChild = node->childs.size() - 1; currentChild >= 0; --currentChild){
        print(stream, node->childs[currentChild], depth + 1);
    }
    for(size_t currentTab = 0; currentTab < depth; ++currentTab){
        stream << '\t';
    }
    stream << *node << '\n';
}

template<typename T>
size_t Tree<T>::countWidth(const NodeTree<T>* node, Vector<int>* width, size_t depth){
    if(node == nullptr){
        node = this->root;
        if(node == nullptr){
            return 0;
        }
    }

    if(depth + 1> width->size()){
        width->push_back(0);
    }
    ++((*width)[depth]);
    for(size_t currentChild = 0; currentChild < node->childs.size(); ++currentChild){
        countWidth(node->childs[currentChild], width, depth + 1);
    }

    if(node == this->root){
        size_t max = 1;
        for(size_t currentWidth = 0; currentWidth < width->size(); ++currentWidth){
            max = max < (*width)[currentWidth] ? (*width)[currentWidth] : max;
        }
        delete width;
        return max;
    }
    return 0;
}

template<typename T>
Tree<T>::~Tree(){
    this->delNode(this->root);
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const Tree<T>& tree){
    tree.print(stream);
    return stream;
}