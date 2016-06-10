#include<iostream>
#include "Aron.h"
using namespace std;

Node* invert(Node* root){
    if(root){
        Node* right = invert(root->left);
        Node* left  = invert(root->right);
        root->left = left ;
        root->right = right;
        return root;
    }
    return NULL;
}

Node* invert_top_down(Node* root){
    if(root){
        Node* left = root->left;
        root->left = root->right;
        root->right = left;
        invert_top_down(root->left);
        invert_top_down(root->right);
        return root;
    }
    return NULL;
}

void printVector(std::vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        std::cout<<"["<<vec[i]<<"]"<<std::endl;
    } 
}

void printArray(int* arr, int len){
    for(int i=0; i<len; i++){
        std::cout<<"["<<arr[i]<<"]"<<std::endl;
    } 
}

void preorder(Node* root){
    if(root){
        std::cout<<"["<<root->data<<"]"<<std::endl;
        inorder(root->left);
        inorder(root->right);
    }
}
void inorder(Node* root){
    if(root){
        inorder(root->left);
        std::cout<<"["<<root->data<<"]"<<std::endl;
        inorder(root->right);
    }
}
void postorder(Node* root){
    if(root){
        inorder(root->left);
        inorder(root->right);
        std::cout<<"["<<root->data<<"]"<<std::endl;
    }
}



 
