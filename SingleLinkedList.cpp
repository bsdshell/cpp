#include<iostream>
#include<vector>
#include "Aron.h"

using namespace std;

void test0(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    SLL* ssl = new SLL();
    ssl->print();
    printf("---------------------------------\n");
}
void test1(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    SLL* ssl = new SLL();
    ssl->append(1);
    ssl->print();
    printf("---------------------------------\n");
}
void test2(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    SLL* ssl = new SLL();
    ssl->append(1);
    ssl->append(2);
    ssl->append(3);
    ssl->print();
    printf("---------------------------------\n");
} 

void test3(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    SLL* ssl = new SLL();
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    ssl->append(n1);
    ssl->append(n2);
    ssl->append(n3);
    ssl->print();
    printf("---------------------------------\n");
    ssl->remove(n1);
    ssl->print();

    printf("---------------------------------\n");
} 

void test4(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    SLL* ssl = new SLL();
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    ssl->append(n1);
    ssl->append(n2);
    ssl->append(n3);
    ssl->print();
    printf("---------------------------------\n");
    ssl->remove(n1);
    ssl->remove(n3);
    ssl->print();

    printf("---------------------------------\n");
} 

void test5(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    SLL* ssl = new SLL();
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    ssl->append(n1);
    ssl->append(n2);
    ssl->append(n3);
    ssl->print();
    printf("---------------------------------\n");
    ssl->remove(n1);
    ssl->remove(n3);
    ssl->remove(n2);
    ssl->print();

    printf("---------------------------------\n");
} 


void testCloneSLL0(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    SLL* ssl = new SLL();
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    ssl->append(n1);
    ssl->print();
    printf("---------------------------------\n");
    SLL* cll = new SLL();
    cll->head = cloneSLL(ssl->head);
    cll->print();
    printf("---------------------------------\n");
} 

void testCloneSLL1(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    SLL* ssl = new SLL();
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    ssl->append(n1);
    ssl->append(n2);
    ssl->append(n3);
    ssl->remove(n1);
    ssl->print();
    printf("---------------------------------\n");
    SLL* cll = new SLL();
    cll->head = cloneSLL(ssl->head);
    cll->print();

    printf("---------------------------------\n");
} 


void testCloneSLL2(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    SLL* ssl = new SLL();
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    ssl->append(n1);
    ssl->append(n2);
    ssl->append(n3);

    ssl->remove(n3);
    ssl->remove(n2);
    ssl->remove(n1);
    ssl->print();
    printf("---------------------------------\n");
    SLL* cll = new SLL();
    cll->head = cloneSLL(ssl->head);
    cll->print();

    printf("---------------------------------\n");
} 

int main(){
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    testCloneSLL0();
    testCloneSLL1();
    testCloneSLL2();
}

