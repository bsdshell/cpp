#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Node.h"

template <class Type> class SLL{
    public:
        Node<Type>* head;
        SLL(){head = NULL;};
    public:
    void append(Type data){
        if(head){
            Node<Type>* curr = head;
            while(curr->right){
                curr = curr->right;
            }
            curr->right = new Node<Type>(data); 
        }else{
            head = new Node<Type>(data);
        }
    }
    void append(Node<Type>* node){
        if(head){
            Node<Type>* curr = head;
            while(curr->right){
                curr = curr->right;
            }
            curr->right = node; 
        }else{
            head = node;
        }
    }
    void print(){
        Node<Type>* curr = head;
        while(curr){
            std::cout<<"["<<curr->data<<"]"<<std::endl;
            curr = curr->right;
        }
    }
    int count(){
        Node<Type>* curr = head;
        int count = 0;
        while(curr){
            count++;
            curr = curr->right;
        }
        return count;
    }
    void remove(Node<Type>* node){
        Node<Type>* curr = head;
        if(curr != NULL && node != NULL){
            Node<Type>* prev = NULL;
            Node<Type>* right = curr->right;
            while(curr){
                if(curr == node){
                    if(prev){
                        prev->right = right;
                        curr->right = NULL;
                    }else{
                        head = right;
                        curr->right = NULL;
                    }
                    delete curr;
                    curr = NULL;
                }else{
                    prev = curr;
                    curr = curr->right;
                    if(curr)
                        right = curr->right;
                }
            }
        }
    }
};

