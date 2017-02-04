#include<iostream>
#include "AronLib.h"
#include <vector>

using namespace Utility;
using namespace std;

class MyClass{
    public:
    int num;
    MyClass(){
        pp("Empty Const.\n");
    }
    MyClass(int n){
        num = n;
    }
    MyClass(const MyClass& other){
        num = other.num;
        pp("Copy Const.\n");
    }

    MyClass(const MyClass&& other){
        num = other.num;
        pp("RValue Copy Const.\n");
    }

    MyClass& operator=(MyClass rhs){
        num = rhs.num;
        pp("Assignment operator\n");
        return *this;
    }

    void fun(){
        pp("class fun()");
    }
};


MyClass fun(){
    MyClass c;
//    MyClass b = std::move(c);
    return c;
}

void fun4(MyClass a, MyClass b){
    MyClass tmp = std::move(a);
    a = b;
    b = tmp;
    cout<<"a.num="<<a.num<<endl;
    cout<<"b.num="<<b.num<<endl;
}

void fun5(MyClass a, MyClass b){
    MyClass tmp = a;
    a = b;
    b = tmp;
    cout<<"a.num="<<a.num<<endl;
    cout<<"b.num="<<b.num<<endl;
}

void fun6(){
    MyClass n(10);
    MyClass tmp = std::move(n);
    cout<<"tmp.num="<<tmp.num<<endl;
    cout<<"n.num="<<n.num<<endl;
}

void uniquePt(){
    MyClass c(100);
    unique_ptr<MyClass> upt1(new MyClass(1));
    unique_ptr<MyClass> upt2(new MyClass(2));
    unique_ptr<MyClass> upt3 = std::move(upt1); 

    if(upt1 != nullptr)
        cout<<"upt1->num="<<upt1->num<<endl;
    else
        pp("upt1 is nullptr\n");

    cout<<"upt3->num="<<upt3->num<<endl;
}

void test4(){
    begin();
    uniquePt();
} 
void test2(){
    begin();
    MyClass a(1);
    MyClass b(2);
    fun4(a, b);
    fun5(a, b);
} 
void test3(){
    begin();
    fun6();
} 

void fun2(MyClass& c){
    pp("c is lvalue");
}

void fun2(MyClass&& c){
    pp("c is rvalue");
}

void test1(){
    begin();
    fun2(MyClass());
}

void test0(){
    begin();
    end();
}

int main(){
    printf("Hello World\n"); 
    test1();
    test2();
    test3();
    test4();
}

