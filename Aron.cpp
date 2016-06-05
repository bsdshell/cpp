#include<iostream>
#include "Aron.h"
using namespace std;

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

 
