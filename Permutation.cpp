#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;


class MyClass
{
    public:
    void permutate(int* array, int size, int k)
    {
        if(k == size)
        {
            for(int i=0; i<size; i++)
                std::cout<<"["<<array[i]<<"] ";
            std::cout<<std::endl;
        }
        else
        {
            for(int i=k; i<size; i++)
            {
                swap(array, i, k);

                for(int j=0; j<k; j++)
                    std::cout<<"[--]";
                std::cout<<"(i="<<i<<",k="<<k<<")"<<std::endl;
                permutate(array, size, i+1);
                swap(array, i, k);
            }
        }
    }
    void combination(char array[], char buf[], int size, int k)
    {
        for(int i=k; i<size; i++)
        {
            buf[strlen(buf)] = array[i];
            buf[strlen(buf)+1] = '\0';
            for(int j=0; j<strlen(buf); j++)
            {
                std::cout<<"["<<buf[j]<<"]";
            }
            std::cout<<std::endl;
            combination(array, buf, size, i+1);
            buf[strlen(buf)-1] = '\0'; 
        }
    }
    void swap(int* array, int i, int j)
    {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
};

int main()
{
    MyClass* c = new MyClass();
    const int size = 3;
    int k = 0;
    int* arrayPt = (int*)malloc(sizeof(int)*size); 
    c->permutate(arrayPt, size, k);

    std::cout<<"===================="<<std::endl;
    
    char array[size] = {'a', 'b', 'c'};
    char* buf = (char*)malloc(sizeof(char)*size);
    c->combination(array, buf, size, k);
    free(buf);
}
