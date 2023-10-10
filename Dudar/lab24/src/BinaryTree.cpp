#include "../include/BinaryTree.hpp"

bool isOperator(const char simbol){
    return (simbol == '-' || simbol == '+' || simbol == '*' || simbol == '/' || simbol == '^');
}

size_t getPriority(const char oper){
    switch(oper){
        case('+'):
            return 1;
        case('-'):
            return 1;
        case('*'):
            return 2;
        case('/'):
            return 2;
        case('^'):
            return 3;
        case('~'):
            return 4;
    }
    return 0;
}

BinaryTree::BinaryTree(const std::string& str){
    this->infStr = str;
    this->root = this->makeTree();
}

BinaryTree::BinaryTree(const BinaryTree& other){
    this->infStr = other.infStr;
    this->root = this->makeTree();
}

BinaryTree::BinaryTree(BinaryTree&& temp){
    this->root = temp.root;
    this->infStr = temp.infStr;
    temp.root = nullptr;
}

BinaryTree BinaryTree::operator=(const BinaryTree& other){
    this->clear();
    this->infStr = other.infStr;
    this->root = this->makeTree();
    return *this;
}

BinaryTree BinaryTree::copy() const{
    return BinaryTree(*this);
}

void BinaryTree::print(Bin_Node<std::string>* node, size_t depth) const{

    if(node == nullptr){
        node = this->root;
    }
    if(node->right != nullptr) print(node->right, depth + 1);
    for(size_t curerntTab = 0; curerntTab < depth; ++curerntTab){
        std::cout << '\t';
    }
    if(node->left != nullptr){
        std::cout << static_cast<char>(std::stoi(node->data)) << std::endl;
    }
    else{
        std::cout << node->data << std::endl;
    }
    if(node->left != nullptr) print(node->left, depth + 1);
}

Bin_Node<std::string>* BinaryTree::makeTree() const{
    Stack<Bin_Node<std::string>*> nodes;
    Stack<char> operators;
    std::string number;

    for(size_t currentChar = 0; currentChar < this->infStr.size(); ++currentChar){
        char ch = this->infStr[currentChar];
        if(!isOperator(ch) && ch != ')' && ch != '('){
            number += ch;
            if(currentChar == this->infStr.size() - 1){
                nodes.push(new Bin_Node<std::string>(number));
                number.clear();
            }
        }
        else if(ch == '('){
            operators.push(ch);
        }
        else if(ch == ')'){
            if(number != ""){
                nodes.push(new Bin_Node<std::string>(number));
                number.clear();
            }
            while(operators.top() != '('){
                char oper = operators.top();
                if(oper == '~'){
                    nodes.top()->left = new Bin_Node<std::string>(nodes.top()->data);
                    nodes.top()->data = oper;
                }
                else{
                    Bin_Node<std::string>* nw = new Bin_Node<std::string>(std::to_string(oper));
                    nw->right = nodes.top();
                    nodes.pop();
                    nw->left = nodes.top();
                    nodes.pop();
                    nodes.push(nw);
                }
                operators.pop();
            }
            operators.pop();
        }
        else{
            if(ch == '-' && operators.top() == '('){
                ch = '~';
            }
            else if(this->infStr[currentChar - 1] != ')'){
                nodes.push(new Bin_Node<std::string>(number));
                number.clear();
            }
            
            while(operators.size() != 0 && getPriority(ch) <= getPriority(operators.top())){
                
                char oper = operators.top();
                if(oper == '~'){
                    nodes.top()->left = new Bin_Node<std::string>(nodes.top()->data);
                    nodes.top()->data = oper;
                }
                else{
                    Bin_Node<std::string>* nw = new Bin_Node<std::string>(std::to_string(oper));
                    nw->right = nodes.top();
                    nodes.pop();
                    nw->left = nodes.top();
                    nodes.pop();
                    nodes.push(nw);
                }
                operators.pop();
            }
            operators.push(ch);
        }
    }
    while(operators.size() != 0){
        char oper = operators.top();
        if(oper == '~'){
            nodes.top()->left = new Bin_Node<std::string>(nodes.top()->data);
            nodes.top()->data = oper;
        }
        else{
            Bin_Node<std::string>* nw = new Bin_Node<std::string>(std::to_string(oper));
            nw->right = nodes.top();
            nodes.pop();
            nw->left = nodes.top();
            nodes.pop();
            nodes.push(nw);
        }
        operators.pop();
    }
    
    return nodes.top();
}

void BinaryTree::clear(){
    Stack<Bin_Node<std::string>*> stack;
    stack.push(this->root);
    while(stack.size() != 0){
        Bin_Node<std::string>* delBin_Node = stack.top();
        stack.pop();
        if(delBin_Node->left != nullptr){
            stack.push(delBin_Node->left);
        }
        if(delBin_Node->right != nullptr){
            stack.push(delBin_Node->right);
        }
        delete delBin_Node;
    }
}

BinaryTree::~BinaryTree(){
    this->clear();
}