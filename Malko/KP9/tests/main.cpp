#include "../include/Table.hpp"
#include <chrono>
#include <vector>
#include <algorithm>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Table<int> tb;
    std::cout << tb << std::endl;
    tb.sort();
    std::cout << tb << std::endl;

    Table<int> mytb;
    std::vector<std::pair<complex, int>> stdtb;
    for(size_t i = 0; i < 10000; ++i){
        int64_t num = ((i*13)/7)%5;
        mytb.push_back(std::pair<complex, int>(complex(num, 0), 1));
        stdtb.push_back(std::pair<complex, int>(complex(num, 0), 1));
    }

    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    mytb.sort();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    begin = std::chrono::steady_clock::now();
    std::sort(stdtb.begin(), stdtb.end());
    end = std::chrono::steady_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    return 0;
}