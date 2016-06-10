#include<iostream>
#include<vector>
#include "Aron.h"

using namespace std;

//[file=kdist.html title=""
void kdistance(Node* root, int k){
    if(root){
        if(k == 0){
            std::cout<<"["<<root->data<<"]"<<std::endl;
        }else if(k > 0){
            kdistance(root->left, k-1);
            kdistance(root->right, k-1);
        }
    }
}
//]

void kdistGraph(int** arr, int k, int h, int w){
    if(k == 0){
        std::cout<<"["<<h<<"]"<<std::endl;
    }else if(k > 0){
        for(int i=0; i<w; i++){
            if(h >= 0 && arr[h][w]){
                kdistGraph(arr, k-1, i, w);
            }
        }
    }
}

void test0(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    BST* b = new BST();
    b->insert(10);
    b->insert(5);
    b->insert(15);
    b->insert(7);
    int k=0;
    kdistance(b->root, k); 
    printf("---------------------------------\n");
}
void test1(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    BST* b = new BST();
    b->insert(10);
    b->insert(5);
    b->insert(15);
    b->insert(7);
    int k=1;
    kdistance(b->root, k); 
    printf("---------------------------------\n");
}

void test2(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    BST* b = new BST();
    b->insert(10);
    b->insert(5);
    b->insert(15);
    b->insert(7);
    int k=2;
    kdistance(b->root, k); 
    printf("---------------------------------\n");
} 

void test3(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    BST* b = new BST();
    b->insert(10);
    b->insert(5);
    b->insert(15);
    b->insert(7);
    int k=3;
    kdistance(b->root, k); 
    printf("---------------------------------\n");
} 

void test4(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    const int width = 5;
    int height= 5;
    int k = 2;
    
    int** arr = new int*[height];
    for(int i=0; i<height; i++){
        arr[i] = new int[width];
    }

    arr[0][1] = 1;
    arr[0][2] = 1;

    arr[1][2] = 1;
    arr[1][3] = 1;

    arr[2][3] = 1;
    arr[2][4] = 1;

    arr[3][4] = 1;

    int h = 0;
    kdistGraph(arr, k, h, width);


    for(int i=0; i<height; i++){
        delete[] arr[i]; 
    }
    delete[] arr;
    

    printf("---------------------------------\n");
} 

int main(){
    test0();
    test1();
    test2();
    test3();
    test4();
}

