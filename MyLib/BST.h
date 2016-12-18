#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Aron.h"
#include "Node.h"

template<class Type> class BST{
public:
    Node<Type>* root;
public:
    BST(){root=NULL;}

    void insert(int n){
        Node<Type>* curr = root;
        if(root == NULL){
            root = new Node<Type>(n);
        }else{
            while(curr){
                if(n < curr->data){
                    if(curr->left == NULL){
                        curr->left = new Node<Type>(n);
                        break;
                    }
                    curr = curr->left;
                }else{
                    if(curr->right == NULL){
                        curr->right = new Node<Type>(n);
                        break;
                    }
                    curr = curr->right;
                }
            }
        }
    }        
    ~BST(){
        destroyTree(root); 
    }

    void destroyTree(Node<Type>* r){
        if(root){
            destroyTree(r->left);
            destroyTree(r->right);
            if(r){
                delete r;
                r = NULL;
            }
        }
    }
};


