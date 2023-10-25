#include "../include/List.hpp"
#include "benchmark.cpp"

int main(){
    benchmark();
    List<int> ls(5, 2);
    std::cout << ls << std::endl;
    ls.insert(ls.begin()+1, 3);
    std::cout << ls << std::endl;
    ls.erase(ls.begin(), ls.begin()+3);
    std::cout << ls << std::endl;

    List<int> ls2(ls);
    ls2.pop_front(); ls2.pop_front();
    std::cout << ls2 << std::endl;

    List<int> ls3{5, 10, 5, 6};
    std::cout << ls3 << std::endl;
    ls3.deleteK(2);
    std::cout << ls3 << std::endl;

    return 0;
}