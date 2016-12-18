#include<iostream>
#include "DDLinkedList.h"
#include "Utility.h"

void test0() {
    begin();
    DDLinkedList<int>* ddl = new DDLinkedList<int>();
    ddl->append(new Node<int>(1));
    delete ddl;
}

void test1() {
    begin();

    DDLinkedList<int>* ddl = new DDLinkedList<int>();
    Node<int>* n1 = new Node<int>(1);
    ddl->append(n1);
    ddl->print();
    delete ddl;
}
void test2() {
    begin();

    DDLinkedList<int>* ddl = new DDLinkedList<int>();
    Node<int>* n1 = new Node<int>(1);
    ddl->append(n1);
    ddl->remove(n1);
    ddl->print();

    delete ddl;
}
void test3() {
    begin();

    DDLinkedList<int> ddl;
}
void test4() {
    begin();
    DDLinkedList<int>* ddl = new DDLinkedList<int>();
    Node<int>* n1 = new Node<int>(1);
    Node<int>* n2 = new Node<int>(2);
    Node<int>* n3 = new Node<int>(3);
    ddl->append(n1);
    ddl->append(n2);
    ddl->append(n3);
    ddl->print();
}

void test5() {
    begin();
    DDLinkedList<int>* ddl = new DDLinkedList<int>();
    Node<int>* n1 = new Node<int>(1);
    Node<int>* n2 = new Node<int>(2);
    Node<int>* n3 = new Node<int>(3);

    ddl->append(n1);
    ddl->append(n2);
    ddl->append(n3);
    ddl->remove(n2);
    ddl->print();
}

void test6() {
    begin();
    DDLinkedList<int>* ddl = new DDLinkedList<int>();
    ddl->append(1);
    ddl->append(2);
    ddl->append(3);
    ddl->print();
}

void test7() {
    begin();
    DDLinkedList<int>* ddl = new DDLinkedList<int>();
    ddl->append(1);
    ddl->append(2);
    ddl->append(3);
    ddl->print();
    ddl->remove(2);
    printf("---------------------------------\n");
    ddl->print();
    printf("---------------------------------\n");
    ddl->remove(1);
    ddl->print();
    printf("---------------------------------\n");
    ddl->remove(3);
    ddl->print();
}

void test8() {
    begin();
    DDLinkedList<int>* ddl = new DDLinkedList<int>();
    ddl->remove(3);
    ddl->print();
}

void test9() {
    begin();
    DDLinkedList<int>* ddl = new DDLinkedList<int>();
    ddl->append(3);
    ddl->remove(3);
    ddl->print();
}
void test10() {
    begin();
    DDLinkedList<int>* ddl = new DDLinkedList<int>();
    ddl->append(1);
    ddl->append(2);
    ddl->remove(3);
    ddl->print();
}

int main() {
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
}

