#include<iostream>
#include"Aron.h"

using namespace aron;

void swap(int* array, int i, int j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}
int partition(int* array, int lo, int hi)
{
    int pivot = array[hi];
    int big = lo;
    for(int i=lo; i<=hi; i++)
    {
        if(array[i] < pivot)
        {
            swap(array, i, big);
            big++;
        }   
    }
    swap(array, big, hi);
    return big;
    
}
void QuickSort(int* array, int lo, int hi)
{
    if(array != NULL && lo <= hi)
    {
        int pivot = partition(array, lo, hi);
        QuickSort(array, lo, pivot-1);
        QuickSort(array, pivot+1, hi);
    }
}

void test1()
{
    int array[5] = {1, 2, 3, 4, 5};
}
int main()
{
    std::cout<<"Hello World";
    myclass my;
}

