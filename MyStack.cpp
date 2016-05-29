#include<iostream>

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

int main() {
    test0(); 
    test1(); 
    test2(); 
    test3(); 
}

