#include "../include/Matrix.hpp"

Matrix::Matrix(){
    this->LB.push_back(-1);
}

Matrix::Matrix(const std::string& fileName){
    std::ifstream fileReader(fileName);

    std::string str;
    while(getline(fileReader, str)){
        ++this->n;

        std::stringstream sstream(str);
        size_t current = 0;
        int64_t num;

        while(sstream >> num){
            ++current;
            if(num != 0){
                this->LB.push_back((this->n - 1) * this->m + current - 1);
                this->YE.push_back(num);
            }
        }

        if(this->m == 0){
            this->m = current;
        }
    }

    this->LB.push_back(-1);
    fileReader.close();
}

Vector<int64_t> Matrix::operator*(const Vector<int64_t>& vec) const{
    if(vec.size() != this->n){
        throw std::logic_error("Uncorrect vector.");
    }
    Vector<int64_t> returnVector;
    size_t zeroCounter = 0;
    for(size_t currentCollumn = 0; currentCollumn < this->m; ++currentCollumn){
        int64_t sum = 0;

        for(size_t currentElem = 0; currentElem < vec.size(); ++currentElem){
            int64_t num = 0;
            int64_t pointer = this->m * currentElem + currentCollumn;
            for(size_t currentIndex = 0; currentIndex < this->LB.size(); ++currentIndex){
                if(this->LB[currentIndex] > pointer){
                    break;
                }
                if(this->LB[currentIndex] == pointer){
                    num = this->YE[currentIndex];
                    break;
                }
            }
            sum += num * vec[currentElem];
        }

        if(sum == 0){
            ++zeroCounter;
        }
        returnVector.push_back(sum);
    }

    std::cout << "Amount of zeros is : " << zeroCounter << std::endl;
    return returnVector;
}

std::ostream& operator<<(std::ostream& stream, const Matrix mat){
    size_t pointer = 0;

    for(size_t currentElem = 0; currentElem < mat.n * mat.m; ++currentElem){
        if(currentElem % mat.m == 0 && currentElem > 0){
            stream << '\n';
        }
        if(mat.LB[pointer] == currentElem){
            stream << mat.YE[pointer] << ' ';
            ++pointer;
        }
        else{
            stream << "0 ";
        }
    }
    stream << '\n';

    return stream;
}