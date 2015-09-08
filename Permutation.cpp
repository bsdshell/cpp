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
            for(int j=0; j<k; j++)
                std::cout<<"[--]";
            std::cout<<"(i="<<i<<",k="<<k<<")"<<std::endl;

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
    void nchoosek(char array[], char buf[], int n, int r, int k)
    {
        if( k > n || k < 0)
            return;
        if(k == 0 || n == 0)
        {
            for(int i=1; i<=r; i++)
            {
                std::cout<<"["<<buf[i]<<"]";
            }
            std::cout<<std::endl;
        }
        else{
            buf[k] = array[n];
            nchoosek(array, buf, n-1, r, k-1);
            nchoosek(array, buf, n-1, r, k);
        }
    }
    void swap(int* array, int i, int j)
    {
        int tmp = array[i];
        array[i] = array[j];
        array[j] = tmp;
    }
    void test0()
    {
        std::cout<<"====================test0()"<<std::endl;
        MyClass* c = new MyClass();
        const int size = 4;
        
        char array[size] = {'e', 'a', 'b', 'c'};
        char* buf = (char*)malloc(sizeof(char)*size);

        int n = size-1;
        int r = 2;
        int k = 2;
        c->nchoosek(array, buf, n, r, k);
        free(buf);
    } 
    void test1()
    {
        std::cout<<"====================test1()"<<std::endl;
        MyClass* c = new MyClass();
        const int size = 4;
        
        char array[size] = {'e', 'a', 'b', 'c'};
        char* buf = (char*)malloc(sizeof(char)*size);

        int n = size-1;
        int r = 3;
        int k = 3;
        c->nchoosek(array, buf, n, r, k);
        free(buf);
    } 

    void test2()
    {
        std::cout<<"====================test2()"<<std::endl;
        MyClass* c = new MyClass();
        const int size = 3;
        
        char array[size] = {'e', 'a', 'b'};
        char* buf = (char*)malloc(sizeof(char)*size);

        int n = size-1;
        int r = 1;
        int k = 1;
        c->nchoosek(array, buf, n, r, k);
        free(buf);
    } 

    void test3()
    {
        std::cout<<"====================test3()"<<std::endl;
        MyClass* c = new MyClass();
        const int size = 2;
        
        char array[size] = {'e', 'a'};
        char* buf = (char*)malloc(sizeof(char)*size);

        int n = size-1;
        int r = 1;
        int k = 1;
        c->nchoosek(array, buf, n, r, k);
        free(buf);
    } 
    void test4()
    {
        std::cout<<"====================test4()"<<std::endl;
        int k = 0;
        const int size = 4;
        MyClass* c = new MyClass();
        char array[size] = {'e', 'a', 'b', 'c'};
        char* buf = (char*)malloc(sizeof(char)*size);
        c->combination(array, buf, size, k);
        free(buf);
    } 
};

int main()
{
    MyClass* c = new MyClass();
    const int size = 4;
    int k = 0;
    int* arrayPt = (int*)malloc(sizeof(int)*size); 
    //c->permutate(arrayPt, size, k);

    std::cout<<"===================="<<std::endl;
    
    char array[size] = {'e', 'a', 'b', 'c'};
    char* buf = (char*)malloc(sizeof(char)*size);
    //c->combination(array, buf, size, k);

    
    c->test0();
    c->test1();
    c->test2();
    c->test3();
    c->test4();

}
