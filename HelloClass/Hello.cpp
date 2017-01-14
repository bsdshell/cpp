#include<iostream>
#include "AronLib.h"

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
        return a;
    }
    
};
int main(){
    printf("Hello World\n"); 
//    A* pt = new A();
//    pp(pt->num);
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

