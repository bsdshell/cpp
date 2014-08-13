#include<iostream>
#include<vector>
using namespace std;

void prime(int n)
{
    bool* prime = new bool[n];
    for(int i=0; i<n; i++)
        prime[i] = true;

    for(int i=2; i<n; i++)
    {
        for(int j=2; j<i && prime[i]; j++)
        {
            if(prime[j] && (i % j) == 0)
                prime[i] = false;
        }
    }
    
    for(int i=2; i<n; i++)
    {
        std::cout<<"["<<i<<"]="<<prime[i]<<endl;
    }
    delete prime;
}

int main()
{
    clock_t startTime = clock();
    prime(100000);
    clock_t endTime = clock();

    clock_t diff = endTime - startTime;
    std::cout<<"diff="<<(float)diff/CLOCKS_PER_SEC<<endl;
}
