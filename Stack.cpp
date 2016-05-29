#include<iostream>
# include <iostream>
# include <type_traits>

template <class T>
inline bool isPrimitiveType(const T& data) {
    return std::is_fundamental<T>::value;
}

struct Foo {
    int x;
    char y;
    unsigned long long z;
};

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

bool isPalindrome(const char* str){
    if(str != NULL){
        int len = strlen(str);
        Stack* st1 = new Stack(len);
        Stack* st2 = new Stack(len);
        for(int i=0; i<len; i++){
            st1->push(str[i]);
        }
        int count = 0;
        while(count < len/2){
            st2->push(st1->pop());
            count++;
        }
        if(len % 2 != 0)
            st1->pop();

        while(!st1->isEmpty()){
            if(st1->pop() != st2->pop())
                return false;
        }
        
        return st1->isEmpty();
    }
    return true;
}

int* allocate(int size){
    return new int[size];
}
void deallocate(int* pt){
    delete[] pt;
}

void SortArray(int* pArray, int Count){
    if(pArray != NULL && Count > 1){
        for(int i=0; i<Count-1; i++)
            for(int j=0; j<Count-1 - i; j++){
                if(pArray[j] > pArray[j+1]){
                    int tmp = pArray[j];
                    pArray[j] = pArray[j+1];
                    pArray[j+1] = tmp;
                }
            }
    }
}

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

    Foo data;

    std::cout << "isPrimitiveType(Foo): " << std::boolalpha
        << isPrimitiveType(data) << std::endl;
    std::cout << "isPrimitiveType(int): " << std::boolalpha
        << isPrimitiveType(data.x) << std::endl;
    std::cout << "isPrimitiveType(char): " << std::boolalpha
        << isPrimitiveType(data.y) << std::endl;
    std::cout << "isPrimitiveType(unsigned long long): " << std::boolalpha
        << isPrimitiveType(data.z) << std::endl;
}

