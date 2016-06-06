#include<iostream>
#include<vector>
#include "Aron.h"

using namespace std;

//[ file=leastop.html title=""
int leastOperation(int n){
    int count = 0;
    while(n > 0){
        if(n % 2 == 0){
            n /=2;
        }
        else{
            n--;
        }
        count++;
    }
    return count;
}
//]

void test0(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    std::cout<<"0=["<<leastOperation(0)<<"]"<<std::endl;
    printf("---------------------------------\n");
}

void test1(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    std::cout<<"1=["<<leastOperation(1)<<"]"<<std::endl;
    printf("---------------------------------\n");
}

void test2(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    std::cout<<"2=["<<leastOperation(2)<<"]"<<std::endl;
    printf("---------------------------------\n");
}
void test3(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    std::cout<<"8=["<<leastOperation(8)<<"]"<<std::endl;
    printf("---------------------------------\n");
} 

void test4(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    std::cout<<"16=["<<leastOperation(16)<<"]"<<std::endl;
    printf("---------------------------------\n");
} 

int main(){
    test0();
    test1();
    test2();
    test3();
    test4();
}

