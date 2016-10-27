#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Aron.h"

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

// clone single linked list clone linked list
//[file=clonesll.html title=""
Node* cloneSLL(Node* root){
    Node* curr = root;
    Node* ncurr = NULL;
    Node* head = NULL;
    while(curr){
        if(head == NULL){
            head = ncurr = new Node(curr->data); 
            curr = curr->next;
        }
        else{
            ncurr->next = new Node(curr->data);    
            ncurr = ncurr->next;
            curr = curr->next; 
        }
    }
    return head; 
}
//]

// clone double linked list
//[ file=clonedll.html title=""
void cloneDLL(Node* root, Node*& head, Node*& tail){
    Node* curr = root;
    Node* ncurr = NULL;
    while(curr){
        if(head == NULL){
            tail = head = ncurr = new Node(curr->data);
            curr = curr->next;
        }else{
            tail = ncurr->next = new Node(curr->data);
            ncurr->next->prev = ncurr;
            ncurr = ncurr->next;
            curr = curr->next;
        }
    }
}
//]


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

void printLinkedList(Node* head){
    Node* curr = head;
    while(curr){
        std::cout<<"["<<curr->data<<"]"<<std::endl;
        curr = curr->next;
    }
}


void printSLL(Node* head){
    Node* curr = head;
    while(curr){
        std::cout<<"["<<curr->data<<"]"<<std::endl;
        curr = curr->next;
    }
}



void begin(){
    int sz = 80;
    string pretty_fun = fun_parent_parent();
    int len = pretty_fun.length();
    printf ("[%s%.*s]\n", pretty_fun.c_str(), sz < len ? 0 : (int)(sz - len), PAD);
}

void begin(const char* name){
    int sz = 80;
    printf ("[%s%.*s]\n", name, (sz < strlen(name)) ? 0 : (int)(sz - strlen(name)), PAD);
}

void end(){
    printf("[%s]\n", PAD);
}


// gf https://www.gnu.org/software/libc/manual/html_node/Backtraces.html
// get name of caller function name

void cut(char* pt){
    int k = strlen(pt) - 1;
    while(k >= 0 && pt[k] != 'v') k--;

    k >= 0 ? pt[k] = 0 : printf("Error: invalid string format.");
}

// get the name of parent function, get the name of caller function
string fun_parent(){
    void *array[10];
    size_t size;
    char **strings;

    size = backtrace (array, 10);
    strings = backtrace_symbols (array, size);

    cut(strings[1]);
    string str = std::string(strings[1] + 63);
    free (strings);
    return str; 
}

// get name of caller of caller function, get the name of parent of parent function
string fun_parent_parent(){
    void *array[10];
    size_t size;
    char **strings;

    size = backtrace (array, 10);
    strings = backtrace_symbols (array, size);

    cut(strings[2]);
    string str = std::string(strings[2] + 63);
    free (strings);
    return str; 
}



 
