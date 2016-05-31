#include<iostream>
#include<memory>

using namespace std;

//[file=smartpointer.html title=""]
class Node{
    public:
        int data;
        Node(int data){
            this->data = data;
        }
    public:
        shared_ptr<Node> prev;
        shared_ptr<Node> next;
};

class LinkedList{
    public:
        shared_ptr<Node> head;
        shared_ptr<Node> tail;
    public:
        LinkedList(){}

        void fun(){
            printf("fun()\n");
        }

        void append(shared_ptr<Node> node){
            if(!head){
                head = node;
                tail = head;
            }else{
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }

        void print(){
            shared_ptr<Node> curr = head;
            while(curr){
                printf("[%d]\n", curr->data);
                curr = curr->next;
            }
        }
        void remove(shared_ptr<Node> node){
            shared_ptr<Node> curr = head;
            if(node && curr){
                while(curr){
                    if(curr == node){
                        if(curr->prev == nullptr){
                            if(curr->next == nullptr){
                                // [curr] 
                                node.reset();
                                head.reset();
                                tail.reset();
                            }else{
                                // [curr]->[] 
                                shared_ptr<Node> next = curr->next;
                                curr->next.reset();
                                next->prev.reset();
                                head = next;
                            }
                        }else{
                            if(curr->next == nullptr){
                                // []->[curr] 
                                shared_ptr<Node> prev = curr->prev;
                                curr->prev.reset();
                                prev->next.reset();
                                tail = prev;
                            }else{
                                // []->[curr]->[]
                                shared_ptr<Node> next = curr->next;
                                shared_ptr<Node> prev = curr->prev;
                                next->prev = prev;
                                prev->next = next;
                            }
                        }
                    }
                    curr = curr->next;
                }
            }
        }
};
//]
void test0(){
    printf("test0()---------------------------------\n");
    shared_ptr<LinkedList> list(new LinkedList());
    shared_ptr<Node> p0(new Node(1));
    shared_ptr<Node> p1(new Node(2));
    shared_ptr<Node> p2(new Node(3));
    list->append(p0);
    list->append(p1);
    list->append(p2);
    list->print();
    printf("---------------------------------\n");
}

void test1(){
    printf("test1()---------------------------------\n");
    shared_ptr<LinkedList> list(new LinkedList());
    shared_ptr<Node> p0(new Node(1));
    shared_ptr<Node> p1(new Node(2));
    shared_ptr<Node> p2(new Node(3));
    list->append(p0);
    list->append(p1);
    list->append(p2);
    list->remove(p0);
    list->print();
    printf("---------------------------------\n");
}

void test2(){
    printf("test2()---------------------------------\n");
    shared_ptr<LinkedList> list(new LinkedList());
    shared_ptr<Node> p0(new Node(1));
    shared_ptr<Node> p1(new Node(2));
    shared_ptr<Node> p2(new Node(3));
    list->append(p0);
    list->append(p1);
    list->append(p2);
    list->remove(p0);
    list->remove(p2);
    list->print();
    printf("---------------------------------\n");
}

void test3(){
    printf("test3()---------------------------------\n");
    shared_ptr<LinkedList> list(new LinkedList());
    shared_ptr<Node> p0(new Node(1));
    shared_ptr<Node> p1(new Node(2));
    shared_ptr<Node> p2(new Node(3));
    list->append(p0);
    list->append(p1);
    list->append(p2);
    list->remove(p0);
    list->remove(p2);
    list->remove(p1);
    list->print();
    printf("---------------------------------\n");
}

void test4(){
    printf("test4()---------------------------------\n");
    shared_ptr<LinkedList> list(new LinkedList());
    shared_ptr<Node> p0(new Node(1));
    shared_ptr<Node> p1(new Node(2));
    shared_ptr<Node> p2(new Node(3));
    shared_ptr<Node> p3(new Node(4));
    shared_ptr<Node> p4(new Node(5));
    list->append(p0);
    list->append(p1);
    list->append(p2);
    list->remove(p0);
    list->remove(p2);
    list->remove(p1);
    list->append(p3);
    list->append(p4);

    list->print();
    printf("---------------------------------\n");
}
int main() {
    test0();
    test1();
    test2();
    test3();
    test4();
}

