#include<iostream>
#include<vector>

#define PAD "--------------------------------------------------------------------------------"

using namespace std;

class Node{
    public:
        Node* next;
        Node* left;
        Node* right;
        Node* prev;
        int data;
    public:
    Node(int n){
        data = n;
        left = NULL;
        right = NULL;
        next = NULL;
        prev = NULL;
    }
};

//[file=singlelinkedlist.html title=""
class SLL{
    public:
        Node* head;
        SLL(){head = NULL;};
    public:
    void append(int data){
        if(head){
            Node* curr = head;
            while(curr->right){
                curr = curr->right;
            }
            curr->right = new Node(data); 
        }else{
            head = new Node(data);
        }
    }
    void append(Node* node){
        if(head){
            Node* curr = head;
            while(curr->right){
                curr = curr->right;
            }
            curr->right = node; 
        }else{
            head = node;
        }
    }
    void print(){
        Node* curr = head;
        while(curr){
            std::cout<<"["<<curr->data<<"]"<<std::endl;
            curr = curr->right;
        }
    }
    int count(){
        Node* curr = head;
        int count = 0;
        while(curr){
            count++;
            curr = curr->right;
        }
        return count;
    }
    void remove(Node* node){
        Node* curr = head;
        if(curr != NULL && node != NULL){
            Node* prev = NULL;
            Node* right = curr->right;
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
//]

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

Node* cloneSLL(Node* root);
void cloneDLL(Node* root, Node*& head, Node*& tail);
void printVector(std::vector<int> vec);
void printArray(int* arr, int len);
void inorder(Node* root);
void preorder(Node* root);
void postorder(Node* root);
void printLinkedList(Node* head);
void printSLL(Node* head);
void begin(const char* name);
void begin();
void end();
void cut(char* pt);
string fun_parent();
string fun_parent_parent();


