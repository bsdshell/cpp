#include<iostream>
#include<vector>
using namespace std;

//[file=cpp-quick-sort.html title=""
void swap(int array[], int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int partition(int array[], int lo, int hi) {
    if(hi > lo) {
        int p = array[hi];
        int big = lo;
        for(int i=lo; i<=hi; i++) {
            if(array[i] <= p)     {
                swap(array, i, big);
                if(i < hi)
                    big++;
            }
        }
        return big;
    }
    return -1;
}

void quickSort(int array[], int lo, int hi) {
    if(hi > lo) {
        int pivot = partition(array, lo, hi); 
        quickSort(array, lo, pivot-1);
        quickSort(array, pivot+1, hi);
    }
}
//]

void test0() {
    printf("test0()---------------------------------\n");
    int array[] = {3};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;

    partition(array, lo, hi);
    for(int i=0; i<len; i++)
        std::cout<<"["<<i<<"]="<<array[i]<<std::endl;

    std::cout<<std::endl;
}

void test1() {
    printf("test1()---------------------------------\n");
    int array[] = {3, 2, 9, 0, 8};
    //int array[] = {3, 4};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;


    quickSort(array, lo, hi);
    for(int i=0; i<len; i++)
        std::cout<<"["<<i<<"]="<<array[i]<<std::endl;

    std::cout<<std::endl;
}

void test2() {
    printf("test3()---------------------------------\n");
    int array[] = {3, 4};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;

    
    quickSort(array, lo, hi);
    for(int i=0; i<len; i++)
        std::cout<<"["<<i<<"]="<<array[i]<<std::endl;

    std::cout<<std::endl;
} 

void test3() {
    printf("test4()---------------------------------\n");
    int array[] = {4, 3};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;

    
    quickSort(array, lo, hi);
    for(int i=0; i<len; i++)
        std::cout<<"["<<i<<"]="<<array[i]<<std::endl;

    std::cout<<std::endl;
} 

void test4() {
    printf("test5()---------------------------------\n");
    int array[] = {4, 9, 6, 1, 10, 20, 3};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;

    
    quickSort(array, lo, hi);
    for(int i=0; i<len; i++)
        std::cout<<"["<<i<<"]="<<array[i]<<std::endl;

    std::cout<<std::endl;
} 

int main() {
   test0(); 
   test1(); 
   test2(); 
   test3(); 
   test4(); 
}
