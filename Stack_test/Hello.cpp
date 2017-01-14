#include<iostream>
#include "AronLib.h"
#include "SLL.h"
#include "Stack.h"

using namespace Utility; 

void test0(){
    begin();
    SLL<int>* sll = new SLL<int>();
    sll->append(3);
    sll->print();

    delete sll;
}
void test1(){
    begin();
    SLL<int>* sll = new SLL<int>();
    sll->append(3);
    sll->remove(3);
    sll->print();

    delete sll;
}

void test2(){
    begin();
    SLL<int>* sll = new SLL<int>();
    sll->append(1);
    sll->append(2);
    sll->append(3);
    sll->remove(1);
    sll->print();

    delete sll;
}

void test3(){
    begin();
    SLL<int>* sll = new SLL<int>();
    sll->append(1);
    sll->append(2);
    sll->append(3);
    sll->remove(2);
    sll->print();

    delete sll;
}
void test4(){
    begin();
    SLL<int>* sll = new SLL<int>();
    sll->append(1);
    sll->append(2);
    sll->append(3);
    sll->remove(3);
    sll->print();

    delete sll;
}

void test5(){
    begin();
    Stack<int>* s = new Stack<int>();
    s->push(3);
    while(!s->empty()){
        pp(s->pop());
    }
}

void test6(){
    begin();
    Stack<int>* s = new Stack<int>();
    s->push(1);
    s->push(2);
    s->push(3);
    while(!s->empty()){
        pp(s->pop());
    }
}

void test7(){
    begin();
    Stack<int>* s = new Stack<int>();
    s->push(1);
    s->push(2);
    s->push(3);
    s->pop();
    s->pop();
    s->pop();
    while(!s->empty()){
        pp(s->pop());
    }
}
int main(){
    printf("Hello World\n"); 
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
}

