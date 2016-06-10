#include<iostream>
#include<vector>
#include "Aron.h"

using namespace std;

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
    
};
//]

void test0(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    SLL* ssl = new SLL();
    ssl->print();
    printf("---------------------------------\n");
}
void test1(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    SLL* ssl = new SLL();
    ssl->append(1);
    ssl->print();
    printf("---------------------------------\n");
}
void test2(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    SLL* ssl = new SLL();
    ssl->append(1);
    ssl->append(2);
    ssl->append(3);
    ssl->print();
    printf("---------------------------------\n");
} 

int main(){
    test0();
    test1();
    test2();
}

