#include<iostream>
#include<vector>

using namespace std;

template <class Type> class MyNode{
    public:
        MyNode* next;
        MyNode* left;
        MyNode* right;
        MyNode* prev;
        Type data;
    public:
    MyNode(Type n){
        data = n;
        left = NULL;
        right = NULL;
        next = NULL;
        prev = NULL;
    }
};



//Node* cloneSLL(Node* root);
//void cloneDLL(Node* root, Node*& head, Node*& tail);
//void printVector(std::vector<int> vec);
//void printArray(int* arr, int len);
//void inorder(Node* root);
//void preorder(Node* root);
//void postorder(Node* root);
//void printLinkedList(Node* head);
//void printSLL(Node* head);
//void begin(const char* name);
//void cut(char* pt);
//void pp(const char *format, ...);
//string fun_parent();
//string fun_parent_parent();
//void fl();
//
