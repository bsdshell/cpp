#include<iostream>
#include<vector>

using namespace std;

vector<int> MultiArray(vector<int> array)
{
    int len = array.size();
    int* v1 = new int[len];
    int* v2 = new int[len];
    for(int i=0; i<len; i++)
    {
        int tail = len-1-i;
        if(i==0)
        {
            v1[i] = 1;
            v2[tail] = 1;
        }
        else
        {
            v1[i] = v1[i-1]*array[i-1];
            v2[tail] = v2[tail+1]*array[tail+1];
        }
    }
    vector<int> v;
    for(int i=0; i<len; i++)
    {
         v.push_back(v1[i]*v2[i]);
    }
    return v;
}


int main()
{
    std::cout<<"Hello World";
    vector<int> array;
    array.push_back(2);
    array.push_back(3);
    array.push_back(4);
    array.push_back(5);
    array.push_back(6);

    int len = array.size();
    vector<int> v = MultiArray(array);

    std::cout<<endl;;
    for(int i=0; i<v.size(); i++)
    {
        std::cout<<"["<<v[i]<<"]"<<endl;;
    }
}
