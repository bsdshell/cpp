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

void test1(){
    Stack* st = new Stack(10);
    st->push('a');
    st->push('b');
    while(!st->isEmpty()){
        printf("[%c]", st->pop());
    }
    char charStr[] = {'a', 'b', 'a'};
    printf("[%s][%d]\n", charStr, isPalindrome(charStr));
}


void test2(){
    Stack* st = new Stack(10);
    st->push('a');
    st->push('b');
    while(!st->isEmpty()){
        printf("[%c]", st->pop());
    }
    char charStr[] = {'a'};
    printf("[%s][%d]\n", charStr, isPalindrome(charStr));
}


void test3(){
    Stack* st = new Stack(10);
    st->push('a');
    st->push('b');
    while(!st->isEmpty()){
        printf("[%c]", st->pop());
    }
    char charStr[] = {'a', 'b'};
    printf("[%s][%d]\n", charStr, isPalindrome(charStr));
}

int main() {
    test1(); 
    test2(); 
    test3(); 
}

