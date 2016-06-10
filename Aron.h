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

class BST{
public:
    Node* root;
public:
    BST(){root=NULL;}

    void insert(int n){
        Node* curr = root;
        if(root == NULL){
            root = new Node(n);
        }else{
            while(curr){
                if(n < curr->data){
                    if(curr->left == NULL){
                        curr->left = new Node(n);
                        break;
                    }
                    curr = curr->left;
                }else{
                    if(curr->right == NULL){
                        curr->right = new Node(n);
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

    void destroyTree(Node* r){
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

void printVector(std::vector<int> vec);
void printArray(int* arr, int len);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);


