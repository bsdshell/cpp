#include<iostream>
#include "AronLib.h"
#include <vector>

using namespace Utility;

class A{
    public:
    int num;
    public: 
    A(){
        pp("call A constructor\n");
    }
    A(int n){
        pp("call constructor\n");
        num = n;
    }
    A(A & other){
        num = other.num;
        pp("call copy constructor\n");
    }
    A& operator=(const A& rhs){
        pp("[A& operator=(const A& rhs)] call assighment operator\n");
        num = rhs.num;
        return *this;
    }
    A fun(){
        A a(100);
        return std::move(a);
    }
};

void test0(){
    begin();

    A a(3);
    A c = a;  // call copy constructor
    A b;
    A e;
    A d(5);
    A* pt = new A();
    e = b = d = *pt;
    pp(c.num);
    pp(d.num);
    pp(b.num);
    pp(e.num);
}

void test1(){
    begin();
    A a;
    A b = a.fun();
}

int main(){
    printf("Hello World\n"); 
    test0();
    test1();
}

