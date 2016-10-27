#include<iostream>
#include<vector>
#include "Aron.h"

using namespace std;

int fibonacci(int num){
    if(num == 1 || num == 2)
        return 1;
    else
        return fibonacci(num - 1) + fibonacci(num - 2);
}

void fun1(){
    printf("fun1");
}
void fun2(){
    printf("fun2");
    fun1();
}



// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55
// 1, 2, 3, 4, 5, 6, 7,  8,  9,  10
int main(){
    fun2();
    printf("Hello World\n"); 
    int ret = 0;
    int nkkk = 0;
    ret = fibonacci(3);
    printf("ret=[%d]\n", ret);
    printf("---------------------------------\n");

    nkkk++;
    ret = fibonacci(4);
    printf("ret=[%d]\n", ret);
    printf("---------------------------------\n");

    nkkk++;
    nkkk++;
    ret = fibonacci(10);
    printf("ret=[%d]\n", ret);
    printf("---------------------------------\n");

}

