#include<iostream>

bool BinarySearch(int* array, int lo, int hi, int key)
{
    if(array != NULL && lo <= hi)
    {
        int mid = (lo+hi)/2;
        if(key < array[mid])
            return BinarySearch(array, lo, mid-1, key);
        else if(key > array[mid])
            return BinarySearch(array, mid+1, hi, key);
        else
            return true;
    }
    return false;
}

void test2()
{
    int array[1] = {1};
    int lo = 0;
    int hi = sizeof(array)/sizeof(int) -1;
    int key = 7;

    bool foundkey = BinarySearch(array, lo, hi, key);
    std::cout<<"key="<<key<<" foundKey="<<foundkey<<std::endl;

    key = 1;
    foundkey = BinarySearch(array, lo, hi, key);
    std::cout<<"key="<<key<<" foundKey="<<foundkey<<std::endl;

}

void test1()
{
    int array[5] = {1, 2, 3, 4, 5};
    int lo = 0;
    int hi = sizeof(array)/sizeof(int) -1;
    int key = 7;
    bool foundkey = BinarySearch(array, lo, hi, key);
    std::cout<<"key="<<key<<" foundKey="<<foundkey<<std::endl;
}

int main()
{
    std::cout<<"Binary Search"<<std::endl;
    test1();
}

