#include<iostream>
#include<list>

using namespace std;

int factorial(int n)
{
    if(n == 0)
        return 1;
    else
        return n*factorial(n-1);
}

int sumlist(list<int> l)
{
    int sum = 0;
    list<int>::iterator ite;
    for(ite = l.begin(); ite != l.end(); ite++)
        sum = *ite;
    return sum;
}

int* addvector(int v1[2], int v2[2])
{
    int* pt = new int[2]; 
    pt[0] = v1[0] + v2[0];
    pt[1] = v1[1] + v2[1];
    return pt;
}


int main(int argc, char** avgv)
{
    int n = factorial(5); 
    std::cout<<"factorial(5) = "<<n<<std::endl;

    list<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    n = sumlist(l);
    std::cout<<"sumlist(l) = "<<n<<std::endl;

    int v1[2] = {1, 2};
    int v2[2] = {2, 3};
    int* pt = addvector(v1, v2);
    std::cout<<"addvector(v1, v2) = ("<<pt[0]<<","<<pt[1]<<")"<<std::endl;
    delete[] pt;
}
 


