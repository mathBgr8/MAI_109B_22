#include "../include/Stack.hpp"
#include "benchmark.cpp"

int main(){
    
    benchmark();

    Stack<int> st{5, 7, 13, 1, 4, 3, 9, 8, 11};
    st.print();
    st.sort();
    st.print();
    Stack<int> st1{5, 7, 13, 1, 4, 3, 9, 8, 11};
    Stack<int> st2{1, 2,90, 65, 4, 15};
    Stack<int> st3 = st1 + st2;
    st3.print();


    return 0;
}