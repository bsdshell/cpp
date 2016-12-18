#ifndef DDLINKEDLIST 
#define DDLINKEDLIST 

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Node.h"

template<class Type> class DDLinkedList {
public:
    Node<Type>* head;
    Node<Type>* tail;
public:
    DDLinkedList() {
        head = tail = NULL;
    }
    ~DDLinkedList() {
        printf("call ~DDLinkedList()\n");
        Node<Type>* curr = head;
        while(curr){
            Node<Type>* prev = curr;
            curr = curr->next;
            printf("delete [%d]\n", prev->data);
            delete prev;
        }
    }
    int count() {
        Node<Type>* curr = head;
        int count = 0;
        while(curr){
            count++;
            curr = curr->next;
        }
        return count;
    }
    void append(Type data) {
        Node<Type>* node = new Node<Type>(data);
        if(head == NULL) {
            head = tail = node; 
        } else {
            tail->next = node; 
            node->prev = tail;
            tail = node;
        }
    }
    void append(Node<Type>* node) {
        if(head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

    }
    void remove(Type data) {
        Node<Type>* curr = head;
        Node<Type>* prev = NULL;
        while(curr){
            Node<Type>* next = curr->next;
            if(curr->data == data){
                if(prev){
                    // [prev]->[curr]->[next]
                    if(next){
                        prev->next = next;
                        next->prev = prev;
                        curr->next = NULL;
                        curr->prev = NULL;
                        if(curr)
                            delete curr;
                        curr = NULL;
                    }else{
                        // [prev]->[curr]->[null]
                        prev->next = NULL;
                        curr->prev = NULL;
                        if(curr)
                            delete curr;
                        curr = NULL;
                        tail = prev;
                    }

                }else{
                    // [null]->[curr]->[next]
                    if(next){
                        Node<Type>* tmpHead = curr;
                        head = curr->next;
                        tmpHead->next = NULL;
                        tmpHead->prev = NULL;
                        if(curr)
                            delete curr;
                        tmpHead = curr = NULL;
                    }else{
                        // [null]->[curr]->[null]
                        curr->next = NULL;
                        curr->prev = NULL;
                        if(curr)
                            delete curr;
                        curr = NULL;
                        head = tail = NULL;
                    }
                }
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
    }
    void remove(Node<Type>* remove) {
        Node<Type>* curr = head;
        while(remove && curr) {
            if(curr == remove) {
                if(curr->prev == NULL) {
                    // first Node
                    Node<Type>* next = curr->next;
                    if(next == NULL) {
                        // [curr]
                        head = tail = NULL;
                    } else {
                        // [curr]->[]
                        curr->next = NULL;
                        next->prev = NULL;
                        head = next;
                    }
                    delete remove;
                    remove = NULL;

                } else if(curr->next == NULL) {
                    // last Node
                    Node<Type>* prev = curr->prev;
                    if(prev != NULL) {
                        // []->[curr]
                        prev->next = NULL;
                        curr->prev = NULL;
                        tail = prev;
                    }
                    delete remove;
                    remove = NULL;
                } else {
                    // []->[curr]->[]
                    Node<Type>* next = curr->next;
                    Node<Type>* prev = curr->prev;
                    next->prev = prev;
                    prev->next = next;
                    delete remove;
                    remove = NULL;
                }
            }
            curr = curr->next;
        }
    }
};

#endif 
