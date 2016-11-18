#include<iostream>
#include<stack>
#include "Aron.h"

using namespace std;

class SLinkedList {
public:
    Node* head;
public:
    SLinkedList() {
        head = NULL;
    }
public:
    void append(int num) {
        if(head == NULL)
            head = new Node(num);
        else {
            Node* curr = head;
            while(curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = new Node(num);
        }
    }
    bool remove(int num) {
        Node* curr = head;
        Node* prev = NULL;

        bool exit = false;
        while(curr != NULL && !exit) {
            if(curr->data == num) {
                if(prev == NULL)
                    head = curr->next;
                else
                    prev->next = curr->next;

                exit = true;
                delete curr;
            }
            prev = curr;
            curr = curr->next;
        }
        return true;
    }

    Node* getHead() {
        return head;
    }

    int size() {
        Node* curr = head;
        int count=0;
        while(curr != NULL) {
            curr = curr->next;
            count++;
        }
        return count;
    }

    //Return new reversed linked list
    Node* reverse() {
        std::stack<Node*> stack;
        Node* curr = head;
        while(curr != NULL) {
            stack.push(curr);
            curr = curr->next;
        }
        Node* prev = NULL;
        Node* newHead = NULL;
        while(!stack.empty()) {
            Node* curr = stack.top();
            stack.pop();
            if(prev != NULL)
                prev->next = curr;
            else
                newHead = curr;
            prev = curr;
            curr->next = NULL;
        }
        return newHead;
    }
    Node* reverseLinkedList() {
        Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL) {
            Node* tmpCurr = curr;
            curr->next = prev;
            prev = tmpCurr;
            curr = tmpCurr->next;
        }
        return prev;
    }

    Node* duplicatedList() {
        Node* curr = head;
        Node* newCurr = NULL;
        Node* newHead = NULL;
        while(curr != NULL) {
            if(newCurr == NULL)
                newHead = newCurr = new Node(curr->data);
            else {
                newCurr->next = new Node(curr->data);
                newCurr = newCurr->next;
            }

            curr = curr->next;
        }
        return newHead;
    }
    ~SLinkedList() {
        Node* curr = head;
        while(curr != NULL) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head = NULL;
    }
};

void test1() {
    begin();
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    printSLL(mylist.head);
}

void test0_remove() {
    begin();
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);

    mylist.remove(3);
    printSLL(mylist.head);
}

void test1_remove() {
    begin();
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);

    mylist.remove(1);
    mylist.remove(2);
    mylist.remove(3);
    printSLL(mylist.head);
}

void test3() {
    begin();
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    printSLL(mylist.head);
    Node* newList = mylist.duplicatedList();
    printSLL(newList);
}

void test4() {
    begin();
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    printSLL(mylist.head);

    Node* newList = mylist.reverse();
    printSLL(newList);
}

void test5() {
    begin();
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    printSLL(mylist.head);

    Node* newList = mylist.reverseLinkedList();
    printSLL(newList);
}

int main() {
    test1();
    test3(); test4();
    test5();
    test0_remove();
    test1_remove();
}

