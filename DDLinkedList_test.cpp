#include<iostream>
#include "DDLinkedList.h"

void test0() {
    printf("test0");
    DDLinkedList<int>* ddl = new DDLinkedList<int>();
    ddl->append(new MyNode<int>(1));
}

void test1() {
    printf("[%s]--------\n", __PRETTY_FUNCTION__);

    DDLinkedList<int>* ddl = new DDLinkedList<int>();
    MyNode<int>* n1 = new MyNode<int>(1);
    ddl->append(n1);
    ddl->print();

    printf("---------------------------------\n");
}
////
//void test2() {
//    printf("[%s]--------\n", __PRETTY_FUNCTION__);
//
//    DDLinkedList<int>* ddl = new DDLinkedList<int>();
//    MyNode<int>* n1 = new MyNode<int>(1);
//
//    ddl->append(n1);
//    ddl->remove(n1);
//    ddl->print();
//    printf("---------------------------------\n");
//}
//
//void test3() {
//    printf("[%s]--------\n", __PRETTY_FUNCTION__);
//
//    DDLinkedList<int>* ddl = new DDLinkedList<int>();
//    MyNode<int>* n1 = new MyNode<int>(1);
//    MyNode<int>* n2 = new MyNode<int>(2);
//    MyNode<int>* n3 = new MyNode<int>(3);
//
//    ddl->append(n1);
//    ddl->append(n2);
//    ddl->append(n3);
//    ddl->remove(n1);
//    ddl->print();
//    printf("---------------------------------\n");
//}
//
//void test4() {
//    printf("[%s]--------\n", __PRETTY_FUNCTION__);
//
//    DDLinkedList<int>* ddl = new DDLinkedList<int>();
//    MyNode<int>* n1 = new MyNode<int>(1);
//    MyNode<int>* n2 = new MyNode<int>(2);
//    MyNode<int>* n3 = new MyNode<int>(3);
//
//    ddl->append(n1);
//    ddl->append(n2);
//    ddl->append(n3);
//    ddl->remove(n3);
//    ddl->remove(n1);
//    ddl->print();
//    printf("---------------------------------\n");
//}
//void test5() {
//    printf("test5\n");
//
//    DDLinkedList<int>* ddl = new DDLinkedList<int>();
//    MyNode<int>* n1 = new MyNode<int>(1);
//    MyNode<int>* n2 = new MyNode<int>(2);
//    MyNode<int>* n3 = new MyNode<int>(3);
//
//    ddl->append(n1);
//    ddl->append(n2);
//    ddl->append(n3);
//    ddl->remove(n3);
//    ddl->remove(n1);
//    ddl->remove(n2);
//    ddl->print();
//    printf("---------------------------------\n");
//}
//void test11() {
//    MyNode<int>* node;
//}
int main() {
    test0();
    test1();
//    test2();
//    test3();
//    test4();
//    test5();
//    test11();
}

