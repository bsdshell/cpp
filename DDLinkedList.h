#include "Aron.h"

template<class Type> class DDLinkedList {
public:
    MyNode<Type>* head;
    MyNode<Type>* tail;
public:
    DDLinkedList() {
        head = tail = NULL;
    }
    void append(MyNode<Type>* node) {
        if(head == NULL) {
            head = tail = node;
        } else {
            tail->next = node;
            node->prev = tail;
            tail = node;
        }

    }
    void remove(MyNode<Type>* remove) {
        MyNode<Type>* curr = head;
        while(remove && curr) {
            if(curr == remove) {
                if(curr->prev == NULL) {
                    // first MyNode
                    MyNode<Type>* next = curr->next;
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
                    // last MyNode
                    MyNode<Type>* prev = curr->prev;
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
                    MyNode<Type>* next = curr->next;
                    MyNode<Type>* prev = curr->prev;
                    next->prev = prev;
                    prev->next = next;
                    delete remove;
                    remove = NULL;
                }
            }
            curr = curr->next;
        }
    }

    void print() {
        MyNode<Type>* curr = head;
        while(curr) {
            printf("[%d]\n", curr->data);
            curr = curr->next;
        }
    }
};

