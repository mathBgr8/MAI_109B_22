#include "../include/Matrix.hpp"

Matrix::Matrix(){
    this->LB.push_back(-1);
}

Matrix::Matrix(const std::string& filename){
    std::ifstream file;
    std::string str;
    file.open(filename);
    
    while(!file.eof()){
        ++this->n;
        getline(file, str);

        std::istringstream stream(str);
        
        if(this->m == 0){
            std::istringstream temp(str);
            double x;
            while(temp >> x){
                ++this->m;
            }
        }

        double num;
        size_t j = 0;
        while(stream >> num){
            ++j;
            if(num != 0){
                this->LB.push_back((n - 1) * m + j - 1);
                this->YE.push_back(num);
            }
        }

    }
    this->LB.push_back(-1);
    file.close();
}

void Matrix::print(){
    size_t place = 0;
    for(size_t currentPlace = 0; currentPlace < this->YE.size(); ++currentPlace){
        while(place < this->LB[currentPlace]){
            ++place;
            std::cout << 0 << ' ';
            if(place%this->m == 0){
                std::cout << std::endl;
            }
        }
        std::cout << this->YE[currentPlace] << ' ';
        if((place+1)%this->m == 0){
            std::cout << std::endl;
        }
        ++place;
    }
}

void Matrix::max(){
    int64_t max1 = -1;
    int64_t max2 = -1;
    if(this->YE.size() > 0){
        max2 = 0;
    }
    for(size_t currentNum = 1; currentNum < this->YE.size(); ++currentNum){
        if(this->YE[max2] < this->YE[currentNum]){
            max1 = -1;
            max2 = currentNum;
        }
        else if(this->YE[max2] == this->YE[currentNum]){
            max1 = max2;
            max2 = currentNum;
        }
    }
   
    int64_t maxPlace = max1;
    if(maxPlace < 0){
        maxPlace = max2;
    }
    double divider = this->YE[maxPlace];
    for(size_t currentNum = 0; currentNum < this->YE.size(); ++currentNum){
        if(this->LB[currentNum] % this->m == maxPlace % this->m){
            this->YE[currentNum] /= divider;
        }
    }
}