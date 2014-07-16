#include<iostream>
#include<list>
#include<vector>

using namespace std;

bool isEven(int value)
{
    return value % 2 == 0;
}

int main(int argc, char** avgv)
{
    vector<int> vec;
    for(int i=0; i<10; i++)
        vec.push_back(i);

    for(vector<int>::iterator it=vec.begin(); it != vec.end(); it++)
    {
        cout<<"["<<*it<<"]";
    }
    cout<<endl;
    int numEven = count_if(vec.begin(), vec.end(), isEven);
    cout<<"All even number="<<numEven<<endl;
}


