#include "../include/BinaryTree.hpp"

int main(){

    BinaryTree bt("((5+4)*3+(16/4)*6)+17");
    std::cout << bt << std::endl;
    std::cout << bt.count() << std::endl;
    return 0;
}