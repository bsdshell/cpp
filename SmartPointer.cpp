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

        // overload ostream 
        friend std::ostream& operator<<(std::ostream& out, shared_ptr<LinkedList> list){
           shared_ptr<Node> curr = list->head; 
           while(curr){
               out<<'['<<curr->data<<']'<<'\n';
               curr = curr->next;
           }
           return out;
        }

        void print(){
            shared_ptr<Node> curr = head;
            while(curr){
                printf("[%d]\n", curr->data);
                curr = curr->next;
            }
        }
        bool remove(shared_ptr<Node> node){
            bool ret = false;
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
                        ret = true;
                    }
                    curr = curr->next;
                }
            }
            return ret;
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
    //list->remove(p0);
    //list->remove(p2);
    list->print();
    printf("---------------------------------\n");
    cout<<list<<endl;
    printf("---------------------------------\n");
}

void testFriend(){
    printf("testFriend()---------------------------------\n");
    shared_ptr<LinkedList> list(new LinkedList());
    shared_ptr<Node> p0(new Node(1));
    shared_ptr<Node> p1(new Node(2));
    shared_ptr<Node> p2(new Node(3));

    list->append(p0);
    list->append(p1);
    list->append(p2);
    cout<<list<<endl;
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

//[file=smartcount.html title=""
void testRefCount(){
    shared_ptr<Node> pt0(new Node(1));
    shared_ptr<Node> pt1 = pt0;
    shared_ptr<Node> pt2 = pt0;
    printf("count=[%ld]\n", pt0.use_count()); // 3
    pt1.reset();
    printf("count=[%ld]\n", pt0.use_count()); // 2
    pt2.reset();
    printf("count=[%ld]\n", pt0.use_count()); // 1
    pt0.reset();
    printf("count=[%ld]\n", pt0.use_count()); // 0 
}
//]

void testCycle(){
    shared_ptr<Node> pt0(new Node(1));
    shared_ptr<Node> pt1(new Node(2));
    pt0->next = pt1;
    pt1->prev = pt0;

    printf("pt0 count=[%ld]\n", pt0.use_count()); // 0 
    printf("pt1 count=[%ld]\n", pt1.use_count()); // 0 

    pt1.reset();

    printf("pt0 count=[%ld]\n", pt0.use_count()); // 0 
    printf("pt1 count=[%ld]\n", pt1.use_count()); // 0 
}


void testCycle1(){
    shared_ptr<Node> pt0(new Node(1));
    shared_ptr<Node> pt1(new Node(2));
    shared_ptr<Node> pt2(new Node(3));

    pt0 = pt1;
    pt1 = pt2;
    pt2 = pt0;

    printf("pt0 count=[%ld]\n", pt0.use_count()); // 0 
    printf("pt1 count=[%ld]\n", pt1.use_count()); // 0 
    printf("pt2 count=[%ld]\n", pt2.use_count()); // 0 

    pt1.reset();

    printf("pt0 count=[%ld]\n", pt0.use_count()); // 0 
    printf("pt1 count=[%ld]\n", pt1.use_count()); // 0 
    printf("pt2 count=[%ld]\n", pt2.use_count()); // 0 

}

void testBadIdea(){
    shared_ptr<Node> pt(new Node(1));
    Node* npt = pt.get();
    printf("npt->data=[%d]\n", npt->data); // 0 
    printf("pt=[%ld]\n", pt.use_count()); // 0 
    //delete npt;
    //printf("pt=[%d]\n", pt.use_count()); // 0 
    pt.reset();
}

shared_ptr<Node> createNode(int n){
    shared_ptr<Node> pt(new Node(n));
    return pt;
}

//[file=smartreturn.html title=""
Node* bad_idea(){
    return new Node(1);
}

shared_ptr<Node> good_idea(){
    shared_ptr<Node> pt(new Node(1));
    return pt;
}
//]

//[file=unique.html title=""
void uniqueTransferOwnerShip(){
    unique_ptr<Node> upt(new Node(1)); 
    // error
    // unique_ptr<Node> upt1 = upt;
    // error
    // unique_ptr<Node> upt2(upt);
    unique_ptr<Node> upt3 = std::move(upt);
}
//]


//void testRawPointer(){
//    Node* nodept = new Node(1);
//    shared_ptr<Node> pt(new Node(2));
//    pt = nodept;
//}
int main() {
//    test0();
//    test1();
      test2();
//    test3();
//    test4();
    //testRefCount();
    //testCycle();
    //testCycle1();

//    shared_ptr<Node> pt0 = createNode(1);
//    shared_ptr<Node> pt1 = pt0;
//    printf("pt0 count=[%ld]\n", pt0.use_count()); 
//    printf("pt1 count=[%ld]\n", pt1.use_count()); 
//    pt1.reset();
//    printf("pt0 count=[%ld]\n", pt0.use_count()); 
//    printf("pt1 count=[%ld]\n", pt1.use_count()); 
//    printf("pt0->data=[%d]\n", pt0->data); 
//    testBadIdea();
      testFriend();
}

