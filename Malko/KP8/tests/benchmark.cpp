#include "../include/List.hpp"
#include <chrono>
#include <forward_list>

void benchmark(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cout << "Big size initialize" << std::endl;

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::forward_list<int> stdList1(1000000);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    List<int> myList1(1000000);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "Copy initialize" << std::endl;

    begin = std::chrono::steady_clock::now();
    std::forward_list<int> stdList2(stdList1);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;  

    begin = std::chrono::steady_clock::now();
    List<int> myList2(myList1);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;  

    
    std::forward_list<int> stdList3;
    List<int> myList3;
    
    std::cout << "push_front() X 100" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100; ++i){
        stdList3.push_front(1);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100; ++i){
        myList3.push_front(1);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl; 

    std::cout << "push_front() X 10000" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        stdList3.push_front(1);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        myList3.push_front(1);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl; 

    std::cout << "push_front() X 1000000" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        stdList3.push_front(1);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        myList3.push_front(1);
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl; 

    std::cout << "pop_front() X 100" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100; ++i){
        stdList3.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 100; ++i){
        myList3.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl; 

    std::cout << "pop_front() X 10000" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        stdList3.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 10000; ++i){
        myList3.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl; 
    std::cout << "pop_front() X 1000000" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        stdList3.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    for(size_t i = 0; i < 1000000; ++i){
        myList3.pop_front();
    }
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl; 

    std::cout << "Insert " << std::endl;

    begin = std::chrono::steady_clock::now();
    myList1.insert(myList1.begin(), 5);
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "Erase: " << std::endl;

    begin = std::chrono::steady_clock::now();
    myList1.erase(myList1.begin()+myList1.size()/2, myList1.end());
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    std::cout << "Clear: " << std::endl;
    std::forward_list<int> stdList4;
    List<int> myList4;
    for(size_t i = 0; i < 100000; ++i){
        stdList4.push_front(25); myList4.push_front(25);
    }

    begin = std::chrono::steady_clock::now();
    stdList4.clear();
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    myList4.clear();
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
}