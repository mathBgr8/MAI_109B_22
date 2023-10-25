#include "../include/Stack.hpp"
#include "benchmark.cpp"

int main(){
    
    benchmark();

    Stack<int> stack({1, 34, 67, 4, 35, 56, 102, 96, 8});
    Stack<int> stack2(6, 2);

    std::cout << stack << std::endl << '+' << std::endl << stack2 << std::endl << '=' << std::endl;

    Stack<int> stack3;
    stack3 = stack + stack2;
    std::cout << stack3 << std::endl;

    return 0;
}