#include<iostream>
#include<stack>

using namespace std;

class MyClass
{
    int num;
    public:
    MyClass(int num):num(num)
    {
    }
    ~MyClass()
    {
        std::cout<<"~MyClass()"<<std::endl;
    }
};

class Node
{
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

class SLinkedList
{
    Node* head;
    public:
    SLinkedList()
    { 
        head = NULL;
    }
    public:
    void append(int num)
    {
        if(head == NULL)
            head = new Node(num);
        else
        {
            Node* curr = head;
            while(curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = new Node(num);
        }
    }
    bool remove(int num)
    {
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
    void show()
    {
        Node* curr = head;
        while(curr != NULL && curr != NULL)
        {
            std::cout<<curr->data<<std::endl;
            curr = curr->next;
        }
    }
    Node* getHead()
    {
        return head;
    }
    int size()
    {
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
    Node* reverse()
    {
        std::stack<Node*> stack;
        Node* curr = head;
        while(curr != NULL)
        {
            stack.push(curr);
            curr = curr->next;
        }
        Node* prev = NULL;
        Node* newHead = NULL;
        while(!stack.empty())
        {
            Node* curr = stack.top(); stack.pop();
            if(prev != NULL)
                prev->next = curr;    
            else
                newHead = curr;
            prev = curr;
            curr->next = NULL;
        }
        return newHead;
    }
    Node* duplicatedList()
    {
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
    ~SLinkedList()
    {
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

void show(Node* head)
{
    Node* curr = head;
    while(curr != NULL)
    {
        std::cout<<curr->data<<std::endl;
        curr = curr->next;
    }
}


void test1()
{
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    mylist.show();
}

void test2()
{
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);

    mylist.remove(3);
    mylist.show();
}

void test3()
{
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    mylist.show();
    std::cout<<"Duplicated Linked List"<<std::endl;
    Node* newList = mylist.duplicatedList();
    show(newList);
}

void test4()
{
    SLinkedList mylist;
    mylist.append(1);
    mylist.append(2);
    mylist.append(3);
    mylist.show();

    std::cout<<"Reversed Linked List"<<std::endl;
    Node* newList = mylist.reverse();
    show(newList);
}

int main()
{
    SLinkedList* sll = new SLinkedList();
    MyClass myclass(3);
    sll->show();
    std::cout<<"Single Linked List"<<std::endl;
    //test2();
    test4();
}

