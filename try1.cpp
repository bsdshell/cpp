#include<iostream>
#include "Aron.h"

using namespace std;

template <class A_Type> class calc {
public:
    A_Type multiply(A_Type x, A_Type y);
    A_Type add(A_Type x, A_Type y);
};

template <class A_Type> A_Type calc<A_Type>::multiply(A_Type x,A_Type y) {
    return x*y;
}
template <class A_Type> A_Type calc<A_Type>::add(A_Type x, A_Type y) {
    return x+y;
}

int main() {
    std::cout<<"cool"<<std::endl;
    calc<double> cclass;
    double d = cclass.add(0.3, 0.4);
    cout<<d<<endl;
}

