#include<iostream>

void swap(int* array, int i, int j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}
void shuffle(int* array, int len)
{
    for(int i=0; i<len; i++)
    {
        int r = rand() % (len- i); 
        swap(array, r, (len-i-1));
    }
}


int main()
{
    std::cout<<"Shuffle desk of card or array"<<std::endl;
    int array[5] = {1, 2, 3, 4, 5};
    int len = sizeof(array)/sizeof(int);
    shuffle(array, len);
    for(int i=0; i<len; i++)
    {
        std::cout<<"["<<i<<"]="<<array[i]<<std::endl;;
    }
}

