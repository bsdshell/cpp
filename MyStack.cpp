#include<iostream>

using namespace std;
//[file=mystack.html title=""
class Stack{
    public:
        int maxLen;
        int count;
        char* array;
    public:
        Stack(int max){
            count = 0;
            maxLen = max;
            array = new char[maxLen];
        }
        void push(char ch){
            if(count < maxLen){
                array[count] = ch;
                count++;
            }
        }
        char pop(){
            char ch;
            if(count > 0){
                ch = array[count-1];
                count--;
            }
            return ch;
        }
        bool isEmpty(){
            return count == 0;
        }
        int size(){
            return count;
        }
        ~Stack(){
            if(array)
                delete[] array;
        }
};
//]

//[file=queuetwostacks.html title=""
class Queue{
    public:
        shared_ptr<Stack>  st1;
        shared_ptr<Stack>  st2;
        Queue(int n){
            shared_ptr<Stack> p1(new Stack(n)); 
            st1 = p1;
            shared_ptr<Stack> p2(new Stack(n)); 
            st2 = p2;
        }
    public:
        char dequeue(){
            char ch;
            if(st1->size() > 0){
                while(!st1->isEmpty()){
                    st2->push(st1->pop());
                }

                ch = st2->pop();
                while(!st2->isEmpty()){
                    st1->push(st2->pop());
                }
            }
            return ch;
        }
        void enqueue(int n){
            st1->push(n);
        }
        bool isEmpty(){
            return st1->isEmpty();
        }
};
//]

void test0(){
    printf("test0\n");
    Stack* st = new Stack(0);
    st->push('a');
    st->push('b');
    while(!st->isEmpty()){
        printf("[%c]", st->pop());
    }
    printf("-------test0\n");
}

void test1(){
    printf("test1\n");
    Stack* st = new Stack(10);
    st->push('a');
    st->push('b');
    while(!st->isEmpty()){
        printf("[%c]", st->pop());
    }
    char charStr[] = {'a', 'b', 'a'};
    printf("-------test1\n");
}

void test2(){
    printf("test2\n");
    Stack* st = new Stack(10);
    st->push('a');
    st->push('b');
    while(!st->isEmpty()){
        printf("[%c]", st->pop());
    }
    printf("-------test2\n");
}


void test3(){
    printf("test3\n");
    Stack* st = new Stack(10);
    st->push('a');
    st->push('b');
    while(!st->isEmpty()){
        printf("[%c]", st->pop());
    }
    printf("-------test3\n");
}


void test4(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    int len = 10;
    shared_ptr<Queue> q(new Queue(len));
    q->enqueue(1);
    while(!q->isEmpty()){
        printf("q=[%d]", q->dequeue());
    }
    printf("---------------------------------\n");
}
void test5(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    int len = 10;
    shared_ptr<Queue> q(new Queue(len));
    q->enqueue(1);
    q->dequeue();
    while(!q->isEmpty()){
        printf("q=[%d]\n", q->dequeue());
    }
    printf("---------------------------------\n");
}

void test6(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    int len = 10;
    shared_ptr<Queue> q(new Queue(len));
    q->enqueue(1);
    q->dequeue();
    q->dequeue();
    while(!q->isEmpty()){
        printf("q=[%d]\n", q->dequeue());
    }
    printf("---------------------------------\n");
} 


void test7(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    int len = 10;
    shared_ptr<Queue> q(new Queue(len));
    q->enqueue(1);
    q->enqueue(2);
    q->enqueue(3);
    q->dequeue();
    while(!q->isEmpty()){
        printf("q=[%d]\n", q->dequeue());
    }
    printf("---------------------------------\n");
} 
void test8(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    int len = 10;
    shared_ptr<Queue> q(new Queue(len));
    q->enqueue(1);
    while(!q->isEmpty()){
        printf("q=[%d]\n", q->dequeue());
    }
    printf("---------------------------------\n");
}


int main() {
    test3(); 
    test4(); 
    test5(); 
    test6(); 
    test7(); 
    test8(); 
}

