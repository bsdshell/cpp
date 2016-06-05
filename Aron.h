#include<iostream>
#include<vector>

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    public:
    Node(int n){
        data = n;
        left = NULL;
        right = NULL;
    }
};

void printVector(std::vector<int> vec);
void printArray(int* arr, int len);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);


