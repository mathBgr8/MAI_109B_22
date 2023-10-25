#include "../include/Tree.hpp"

int main(){

    Tree<int> tr{5, 4, 6, 7, 8, 1, 2, 3, 9};
    std::cout << tr << std::endl;
    std::cout << *tr.findNode(7) << std::endl;

    Tree<int> tr3(tr);
    std::cout << tr3 << std::endl;

    Tree<int> tr2{1, 2, 3, 4};
    tr2.newNode(5, tr2.findNode(2));
    tr2.newNode(6, tr2.findNode(2));
    tr2.newNode(7, tr2.findNode(4));
    tr2.newNode(8, tr2.findNode(5));
    tr2.newNode(9, tr2.findNode(6));
    std::cout << tr2 << std::endl;

    std::cout << "Width is : " << tr2.countWidth() << std::endl;

    return 0;
}
