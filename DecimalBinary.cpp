#include<iostream>
#include<vector>
#include "Aron.h"

using namespace std;

//[file=decimal-to-binary.html title=""
vector<int> decimalBinary(int n){
    vector<int> vec;
    if(n == 0)
        vec.push_back(0);
    else if(n > 0){
        while(n){
            int r = n % 2;
            n = n/2;
            vec.push_back(r);
        }
    }
    return vec;
}
//]

void test0(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    vector<int> v = decimalBinary(0);
    printVector(v);
    printf("---------------------------------\n");
}
void test1(){
    printf("---------------------------------\n");
    vector<int> v = decimalBinary(1);
    printVector(v);
    printf("---------------------------------\n");
}
void test2(){
    printf("---------------------------------\n");
    vector<int> v = decimalBinary(4);
    printVector(v);
    printf("---------------------------------\n");
} 

void test3(){
    printf("---------------------------------\n");
    vector<int> v = decimalBinary(10);
    printVector(v);
    printf("---------------------------------\n");
} 

void test4(){
    printf("---------------------------------\n");
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    printVector(v);
    printf("---------------------------------\n");
} 


int main(){
    test0();
    test1();
    test2();
    test3();
}

