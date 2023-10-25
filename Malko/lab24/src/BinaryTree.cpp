#include "../include/BinaryTree.hpp"


BinaryTree::BinaryTree(const std::string& str){
    this->infStr = str;
    this->head = this->createTree();
}

BinaryTree::BinaryTree(const BinaryTree& other){
    this->infStr = other.infStr;
    this->head = this->createTree();
}

BinaryTree::BinaryTree(BinaryTree&& temp){
    this->head = temp.head;
    this->infStr = temp.infStr;
    temp.head = nullptr;
}

BinaryTree BinaryTree::operator=(const BinaryTree& other){
    
    this->infStr = other.infStr;
    this->head = this->createTree();
    return *this;
}

Bin_Node<std::string>* BinaryTree::createTree() const{
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

size_t BinaryTree::count(Bin_Node<std::string>* node, size_t counter) const{
    if(node == nullptr && counter == 0){
        node = this->head;
    }
    if(node == nullptr){
        return 0;
    }
    if(node->left != nullptr){
        ++counter;
        counter += this->count(node->left);
    }
    if(node->right != nullptr){
        counter += this->count(node->right);
    }
    return counter;
}

BinaryTree::~BinaryTree(){

    Stack<Bin_Node<std::string>*> stack;
    stack.push(this->head);

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

std::ostream& operator<<(std::ostream& stream, const BinaryTree& tree){
    
    printNodes(stream, tree.head);

    return stream;
}

void printNodes(std::ostream& stream, Bin_Node<std::string>* node, size_t level){
    if(node == nullptr){
        return;
    }
    printNodes(stream, node->left, level+1);
    for(size_t currentTab = 0; currentTab < level; ++currentTab){
        stream << '\t';
    }
    if(node->left != nullptr){
        stream << static_cast<char>(std::stoi(node->data)) << '\n';
    }
    else{
        stream << node->data << '\n';
    }
    printNodes(stream, node->right, level+1);
}