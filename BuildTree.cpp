#include<iostream>
#include<vector>
#include<cmath> 
#include "AronLib.h"

using namespace std;
//[ file=printbinary.html title=""
Node<int>* build(Node<int>* root, int level, int l){
    if(l < level && !root){
        root = new Node<int>(1);
        root->left = build(root->left, level, l + 1);
        root->right= build(root->right, level, l + 1);
    }
    return root;
}
void printBinary(Node<int>* root, std::string str){
    if(root){
        printBinary(root->left, str + "0");

        if(root->left == NULL && root->right == NULL)
            std::cout<<"["<<str<<"]"<<std::endl;
        
        printBinary(root->right, str + "1");
    }
}
//]

//[ file=printallbinary.html title=""
void printAllBinary(int n){
    for(int i=0; i<std::pow(2, n); i++){
        std:string str;
        int num = i;
        for(int j=0; j<n; j++){
            if(num % 2 == 0)
                str = "0" + str;
            else
                str = "1" + str;
            num = num/2;
        }
        std::cout<<"["<<str<<"]"<<std::endl;
    }
}
//]

void test0(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    int level = 1;
    int l = 0;
    Node<int>* node = NULL;
    Node<int>* root = build(node, level, l); 
    inorder(root);
    printf("---------------------------------\n");
}
void test1(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    int level = 2;
    int l = 0;
    Node<int>* node = NULL;
    Node<int>* root = build(node, level, l); 
    inorder(root);
    printf("---------------------------------\n");
}

void test2(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    int level = 3;
    int l = 0;
    Node<int>* node = NULL;
    Node<int>* root = build(node, level, l); 
    inorder(root);
    printf("---------------------------------\n");
} 
void test3(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    int level = 5;
    int l = 0;
    Node<int>* node = NULL;
    Node<int>* root = build(node, level, l); 
    inorder(root);

    printf("---------------------------------\n");
    std::string str;
    printBinary(root, str);
    printf("---------------------------------\n");
} 

void test4(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    printAllBinary(1);
    printf("---------------------------------\n");
} 

void test5(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    printAllBinary(2);
    printf("---------------------------------\n");
} 
void test6(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    printAllBinary(4);
    printf("---------------------------------\n");
} 

void test7(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    printAllBinary(0);
    printf("---------------------------------\n");
} 


int main(){
    test0(); 
    test1(); 
    test2(); 
    test3(); 
    test4(); 
    test5(); 
    test6(); 
    test7(); 
}

