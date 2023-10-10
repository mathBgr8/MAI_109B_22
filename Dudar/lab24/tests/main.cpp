#include "../include/BinaryTree.hpp"

int main(){

    BinaryTree bn("((5+15)*6)/15+((67/15)*(45+53)+9283)/167");
    bn.print();
    BinaryTree bn2(bn);
    bn2.print();
    BinaryTree bn3("5");
    bn3 = bn2;
    bn3.print();
    BinaryTree bn4(bn.copy());
    bn4.print();

    return 0;
}