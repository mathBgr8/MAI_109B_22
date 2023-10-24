#include "../include/DataBase.hpp"

int main(){

    DataBase database;
    std::cout << database;

    std::cout << database.femalesGrants(109) << std::endl;

    return 0;
}