#include<iostream>
#include<stack>

using namespace std;

class MyClass
{
    int num;
    public:
    MyClass(int num):num(num) {
    }
    ~MyClass()
    {
        std::cout<<"~MyClass()"<<std::endl;
    }
};

class Node {
    public:
        Node* next;
        int data;
    public:
        Node(int data)
        {
            this->data = data;
            next = NULL;
        }
};

class SLinkedList {
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
            while(curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = new Node(num);
        }
    }
    bool remove(int num) {
        Node* curr = head;
        Node* prev = NULL;

        bool exit = false;
        while(curr != NULL && !exit)
        {
            if(curr->data == num)
            {
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
    void show() {
        Node* curr = head;
        while(curr != NULL && curr != NULL) {
            std::cout<<curr->data<<std::endl;
            curr = curr->next;
        }
        std::cout<<"--------------------------"<<std::endl;
    }
    Node* getHead() {
        return head;
    }
    int size() {
        Node* curr = head;
        int count=0;
        while(curr != NULL)
        {
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
    Node* reverseLinkedList(){
        Node* curr = head;
        Node* prev = NULL;
        while(curr != NULL){
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
        while(curr != NULL)
        {
            if(newCurr == NULL) 
                newHead = newCurr = new Node(curr->data);
            else
            {
                newCurr->next = new Node(curr->data);
                newCurr = newCurr->next;
            }

            curr = curr->next;
        }
        return newHead;
    }
    ~SLinkedList() {
        Node* curr = head;
        while(curr != NULL)
        {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head = NULL;

        std::cout<<"Destructor: ~SLinkedList()"<<std::endl;
    }
};

void show(Node* head) {
    Node* curr = head;
    while(curr != NULL) {
        std::cout<<curr->data<<std::endl;
        curr = curr->next;
    }
}


void test1() {
    std::cout<<"test1()"<<std::endl;
    std::cout<<"Append node"<<std::endl;
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    mylist.show();
}

void test2() {
    std::cout<<"test2()"<<std::endl;
    std::cout<<"Remove/append node"<<std::endl;
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);

    mylist.remove(3);
    mylist.show();
}

void test3() {
    std::cout<<"test3()"<<std::endl;
    std::cout<<"Duplicated Linked List"<<std::endl;
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    mylist.show();
    Node* newList = mylist.duplicatedList();
    show(newList);
}

void test4() {
    std::cout<<"test4()"<<std::endl;
    std::cout<<"Reversed Linked List"<<std::endl;
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    mylist.show();

    Node* newList = mylist.reverse();
    show(newList);
}


void test5() {
    std::cout<<"test5()"<<std::endl;
    std::cout<<"reverseLinkedList()"<<std::endl;
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.show();

    Node* newList = mylist.reverseLinkedList();
    show(newList);
}

int main() {
    //test1();
    //test2();
    //test3();
    //test4();
    test5();
}

