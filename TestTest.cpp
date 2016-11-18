#include<iostream>
#include<vector>
#include "Aron.h"
#include "Test.h"

using namespace std;

void test0(){
    begin();
    Test::t(3, 4);
    Test::t(4, 4);
    end();
}

void test1(){
    begin();
    //char str[100] = "essential";
    char str[10];
    pp("strlen(str)=%d\n", strlen(str));
    pp("sizeof str=%d\n", sizeof(str));
    pp("sizeof(*str)=%d\n", sizeof(*str));
    pp("(sizeof str) / sizeof(*str)=%d\n", (sizeof str) / sizeof(*str));
    fl();

    int arr[10];
    pp("sizeof arr=%d\n", sizeof arr);
    pp("sizeof *arr=%d\n", sizeof *arr);
    pp("(sizeof arr)/(sizeof *arr)=%d\n", (sizeof arr)/(sizeof *arr));
}

int main(){
    printf("Hello World\n"); 
    test0();
    test1();
}


