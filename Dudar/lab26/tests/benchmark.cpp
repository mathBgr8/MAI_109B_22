#include "../include/Stack.hpp"
#include <chrono>
#include <stack>

void benchmark(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cout << "Big size initialize" << std::endl;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    Stack<int> myStack1(1000000);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "Copy initialize" << std::endl;

    std::stack<int> stdStack1;
    for(size_t i = 0; i < 1000000; ++i){
        stdStack1.push(1);
    }

    begin = std::chrono::steady_clock::now();
    std::stack<int> stdSrack2(stdStack1);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;  

    begin = std::chrono::steady_clock::now();
    Stack<int> myStack2(myStack1);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl; 

    std::cout << "push() X 100" << std::endl;

    begin = std::chrono::steady_clock::now();
    std::stack<int> stdStack3;
    for(size_t i = 0; i < 100; ++i){
        stdStack3.push(1);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    Stack<int> myStack3;
    for(size_t i = 0; i < 100; ++i){
        myStack3.push(1);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;  

    std::cout << "push() X 10000" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        stdStack3.push(1);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        myStack3.push(1);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;  

    std::cout << "push() X 1000000" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        stdStack3.push(1);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        myStack3.push(1);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;  

    std::cout << "pop() X 100" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100; ++i){
        stdStack3.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100; ++i){
        myStack3.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl; 

    std::cout << "pop() X 10000" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        stdStack3.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        myStack3.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl; 

    std::cout << "pop() X 1000000" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        stdStack3.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        myStack3.pop();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;  

    std::cout << "sort(100000)" << std::endl;

    Stack<int> stack;
    for(size_t i = 0; i < 100000; ++i){
        stack.push(((i*13)/7)%17);
    }

    begin = std::chrono::steady_clock::now();
    stack.sort();
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl; 

}