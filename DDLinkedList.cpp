#include<iostream>
#include "DDLinkedList.h"

//template <class Type> DDLinkedList<Type>::DDLinkedList() {
//    head = tail = NULL;
//}

//template <class Type> void DDLinkedList<Type>::append(MyNode<Type>* node) {
//    if(head == NULL) {
//        head = tail = node;
//    } else {
//        tail->next = node;
//        node->prev = tail;
//        tail = node;
//    }
//}
//
//template <class Type> void DDLinkedList<Type>::remove(MyNode<Type>* remove) {
//    MyNode<Type>* curr = head;
//    while(remove && curr) {
//        if(curr == remove) {
//            if(curr->prev == NULL) {
//                // first MyNode
//                MyNode<Type>* next = curr->next;
//                if(next == NULL) {
//                    // [curr]
//                    head = tail = NULL;
//                } else {
//                    // [curr]->[]
//                    curr->next = NULL;
//                    next->prev = NULL;
//                    head = next;
//                }
//                delete remove;
//                remove = NULL;
//
//            } else if(curr->next == NULL) {
//                // last MyNode
//                MyNode<Type>* prev = curr->prev;
//                if(prev != NULL) {
//                    // []->[curr]
//                    prev->next = NULL;
//                    curr->prev = NULL;
//                    tail = prev;
//                }
//                delete remove;
//                remove = NULL;
//            } else {
//                // []->[curr]->[]
//                MyNode<Type>* next = curr->next;
//                MyNode<Type>* prev = curr->prev;
//                next->prev = prev;
//                prev->next = next;
//                delete remove;
//                remove = NULL;
//            }
//        }
//        curr = curr->next;
//    }
//}
//
//template <class Type> void DDLinkedList<Type>::DDLinkedList<Type>::print() {
//    MyNode<int>* curr = head;
//    while(curr) {
//        printf("[%d]\n", curr->data);
//        curr = curr->next;
//    }
//}
//
