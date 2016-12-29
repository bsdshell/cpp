#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
//#include "Node.h"

template <class Type> class SLL{
    public:
        Node<Type>* head;
        SLL(){head = NULL;};
    public:
    void append(Type data){
        if(head){
            Node<Type>* curr = head;
            while(curr->next){
                curr = curr->next;
            }
            curr->next = new Node<Type>(data); 
        }else{
            head = new Node<Type>(data);
        }
    }
    void append(Node<Type>* node){
        if(head){
            Node<Type>* curr = head;
            while(curr->next){
                curr = curr->next;
            }
            curr->next = node; 
        }else{
            head = node;
        }
    }
    void print(){
        Node<Type>* curr = head;
        while(curr){
            std::cout<<"["<<curr->data<<"]"<<std::endl;
            curr = curr->next;
        }
    }
    int count(){
        Node<Type>* curr = head;
        int count = 0;
        while(curr){
            count++;
            curr = curr->next;
        }
        return count;
    }

    void remove(Type item){
        Node<Type>* curr = head;
        Node<Type>* prev = NULL;
        while(curr){
            if(curr->data == item){
                if(prev == NULL){
                    head = curr->next;
                    curr->next = NULL;
                    delete curr;
                    curr = NULL;
                }else{
                    prev->next = curr->next;
                    curr->next = NULL;
                    delete curr;
                    curr = NULL;
                }
            }else{
                prev = curr;
                curr = curr->next;
            }
        }
    }

    void remove(Node<Type>* node){
        Node<Type>* curr = head;
        if(curr != NULL && node != NULL){
            Node<Type>* prev = NULL;
            Node<Type>* right = curr->next;
            while(curr){
                if(curr == node){
                    if(prev){
                        prev->next = right;
                        curr->next = NULL;
                    }else{
                        head = right;
                        curr->next = NULL;
                    }
                    delete curr;
                    curr = NULL;
                }else{
                    prev = curr;
                    curr = curr->next;
                    if(curr)
                        right = curr->next;
                }
            }
        }
    }
};

