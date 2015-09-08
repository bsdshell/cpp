#include<iostream>
#include<vector>
using namespace std;

void swap(int array[], int i, int j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int partition(int array[], int lo, int hi)
{
    if(hi > lo)
    {
        int p = array[lo];
        int big = lo;
        for(int i=lo; i<hi+1; i++)
        {
            if(array[i] <= p)     
            {
                swap(array, i, big);
                big++;
            }
        }
        swap(array, lo, big-1);
        return big-1;
    }
    return -1;
}

void quickSort(int array[], int lo, int hi)
{
    if(hi > lo)
    {
        int pivot = partition(array, lo, hi); 
        quickSort(array, lo, pivot-1);
        quickSort(array, pivot+1, hi);
    }
}

void test1()
{
    int array[] = {3, 2, 9, 0, 8};
    //int array[] = {3, 4};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;

    
    partition(array, lo, hi);

    for(int i=0; i<len; i++)
        std::cout<<"["<<i<<"]="<<array[i]<<std::endl;

    std::cout<<std::endl;
}

void test2()
{
    int array[] = {3, 4};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;

    
    partition(array, lo, hi);

    for(int i=0; i<len; i++)
        std::cout<<"["<<i<<"]="<<array[i]<<std::endl;

    std::cout<<std::endl;
} 

void test3()
{
    int array[] = {3, 4};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;

    
    quickSort(array, lo, hi);
    for(int i=0; i<len; i++)
        std::cout<<"["<<i<<"]="<<array[i]<<std::endl;

    std::cout<<std::endl;
} 

void test4()
{
    int array[] = {4, 3};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;

    
    quickSort(array, lo, hi);
    for(int i=0; i<len; i++)
        std::cout<<"["<<i<<"]="<<array[i]<<std::endl;

    std::cout<<std::endl;
} 

void test5()
{
    int array[] = {4, 9, 6, 1, 10, 20, 3};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;

    
    quickSort(array, lo, hi);
    for(int i=0; i<len; i++)
        std::cout<<"["<<i<<"]="<<array[i]<<std::endl;

    std::cout<<std::endl;
} 

void test6()
{
    int array[] = {4};
    int lo = 0;
    int len = sizeof(array)/sizeof(int);
    int hi = len-1;

    
    quickSort(array, lo, hi);
    for(int i=0; i<len; i++)
        std::cout<<"["<<i<<"]="<<array[i]<<std::endl;

    std::cout<<std::endl;
} 

int main()
{
   test1(); 
   test2(); 
   test3(); 
   test4(); 
   test5(); 
   test6(); 
}
