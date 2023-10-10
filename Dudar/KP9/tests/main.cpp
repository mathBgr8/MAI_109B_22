#include "../include/Table.hpp"
#include <chrono>
#include <vector>
#include <algorithm>

int main(){

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    Table<int> tb;
    tb.push_back(std::pair<std::string, int>("C", 5));
    tb.push_back(std::pair<std::string, int>("A", 4));
    tb.push_back(std::pair<std::string, int>("B", 5));
    tb.push_back(std::pair<std::string, int>("A", 5));
    tb.push_back(std::pair<std::string, int>("W", 5));
    tb.push_back(std::pair<std::string, int>("V", 5));
    tb.push_back(std::pair<std::string, int>("Agf", 5));
    tb.push_back(std::pair<std::string, int>("VGGD", 5));
    tb.push_back(std::pair<std::string, int>("MKL", 5));
    tb.push_back(std::pair<std::string, int>("F<KLSGM", 5));
    tb.push_back(std::pair<std::string, int>("fffklfmk", 5));
    tb.push_back(std::pair<std::string, int>("F<F<F<", 5));
    tb.push_back(std::pair<std::string, int>("DAPAF", 5));
    tb.push_back(std::pair<std::string, int>("V>:LE", 5));
    tb.sort();
    tb.print();

    Table<int> mytb;
    std::vector<std::pair<std::string, int>> stdtb;
    for(size_t i = 0; i < 10000; ++i){
        std::string str = "A";
        str[0] += ((i*13)/7)%5;
        mytb.push_back(std::pair<std::string, int>(str, 1));
        stdtb.push_back(std::pair<std::string, int>(str, 1));
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