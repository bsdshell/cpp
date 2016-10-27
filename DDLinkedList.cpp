#include<iostream>
#include "Aron.h"

//[file=ddlinkedlist.html title=""
class DDLinkedList{
    public:
        Node* head;
        Node* tail;
    public:
        DDLinkedList(){
            head = tail = NULL;
        }
        void append(Node* node){
            if(head == NULL){
                head = tail = node;
            }else{
                tail->next = node;
                node->prev = tail;
                tail = node;
            }
        }
        void remove(Node* remove){
            Node* curr = head;
            while(remove && curr){
                if(curr == remove){
                    if(curr->prev == NULL){
                        // first node
                        Node* next = curr->next;
                        if(next == NULL){
                            // [curr] 
                            head = tail = NULL;
                        }else{
                            // [curr]->[] 
                            curr->next = NULL; 
                            next->prev = NULL;
                            head = next;
                        }
                        delete remove;
                        remove = NULL;

                    }else if(curr->next == NULL){
                        // last node
                        Node* prev = curr->prev;
                        if(prev != NULL){
                            // []->[curr]
                            prev->next = NULL;
                            curr->prev = NULL;
                            tail = prev;
                        }
                        delete remove;
                        remove = NULL;
                    }else{
                        // []->[curr]->[]
                        Node* next = curr->next;
                        Node* prev = curr->prev;
                        next->prev = prev;
                        prev->next = next;
                        delete remove;
                        remove = NULL;
                    }
                }
                curr = curr->next;
            }
        }
        void print(){
            Node* curr = head;
            while(curr){
                printf("[%d]\n", curr->data);
                curr = curr->next;
            }
        }
     
};
//]

void test0(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);

    DDLinkedList* ddl = new DDLinkedList();
    ddl->append(new Node(1));
    ddl->print();
}


void test1(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);

    DDLinkedList* ddl = new DDLinkedList();
    ddl->append(new Node(1));
    ddl->append(new Node(2));
    ddl->append(new Node(3));
    ddl->print();

    printf("---------------------------------\n");
}

void test2(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);

    DDLinkedList* ddl = new DDLinkedList();
    Node* n1 = new Node(1);

    ddl->append(n1);
    ddl->remove(n1);
    ddl->print();
    printf("---------------------------------\n");
}

void test3(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);

    DDLinkedList* ddl = new DDLinkedList();
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    ddl->append(n1);
    ddl->append(n2);
    ddl->append(n3);
    ddl->remove(n1);
    ddl->print();
    printf("---------------------------------\n");
}

void test4(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);

    DDLinkedList* ddl = new DDLinkedList();
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    ddl->append(n1);
    ddl->append(n2);
    ddl->append(n3);
    ddl->remove(n3);
    ddl->remove(n1);
    ddl->print();
    printf("---------------------------------\n");
}
void test5(){
    printf("test5\n");

    DDLinkedList* ddl = new DDLinkedList();
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    ddl->append(n1);
    ddl->append(n2);
    ddl->append(n3);
    ddl->remove(n3);
    ddl->remove(n1);
    ddl->remove(n2);
    ddl->print();
    printf("---------------------------------\n");
}


void testCloneDLL0(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);

    DDLinkedList* ddl = new DDLinkedList();
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    ddl->append(n1);
    ddl->append(n2);
    ddl->append(n3);
    ddl->print();
    printf("---------------------------------\n");
    Node* head = NULL;
    Node* tail = NULL;
    cloneDLL(ddl->head, head, tail);
    std::cout<<"["<<tail->data<<"]"<<std::endl;
    printf("---------------------------------\n");
}

void testCloneDLL1(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    DDLinkedList* ddl = new DDLinkedList();
    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);

    ddl->append(n1);
    ddl->print();
    printf("---------------------------------\n");
    Node* head = NULL;
    Node* tail = NULL;
    cloneDLL(ddl->head, head, tail);
    printLinkedList(head);
    printf("---------------------------------\n");
    std::cout<<"tail=["<<tail->data<<"]"<<std::endl;
    printf("---------------------------------\n");
}

int main() {
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
    testCloneDLL0();
    testCloneDLL1();
}

