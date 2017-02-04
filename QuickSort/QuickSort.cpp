#include<iostream>
#include<vector>
#include "AronLib.h"

using namespace std;
using namespace Utility;
using namespace SpaceTest;
using namespace SpaceSort;

void test0() {
    begin();
    Test<int> t;

    int array[] = {3};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;

    partition(array, lo, hi);
    t.f(array[0] == 3);
}

void test1() {
    begin();
    Test<int> t;

    int array[] = {3, 2, 9, 0, 8};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;

    quickSort(array, lo, hi);

    t.f(array[0] == 0);
    t.f(array[1] == 2);
    t.f(array[2] == 3);
    t.f(array[3] == 8);
    t.f(array[4] == 9);
}

void test2() {
    begin();
    Test<int> t;

    int array[] = {3, 4};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;

    quickSort(array, lo, hi);
    t.f(array[0] == 3);
    t.f(array[1] == 4);
} 

void test3() {
    begin();

    Test<int> t;

    int array[] = {4, 3};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;
    
    quickSort(array, lo, hi);
    t.f(array[0] == 3);
    t.f(array[1] == 4);
} 

int main() {
   test0(); 
   test1(); 
   test2(); 
   test3(); 
}
