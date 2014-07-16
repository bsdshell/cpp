#include<iostream>
#include<list>
#include<vector>

using namespace std;

class MyFunctor 
{
    const size_t length;
    public: 
    MyFunctor(size_t maxLength): length(maxLength){}
    
    bool operator()(const string& str) const
    {
        return str.length() < length;
    }
}; 

int main(int argc, char** avgv)
{
    vector<string> vec;
    vec.push_back("dog");
    vec.push_back("cow");
    vec.push_back("cake");
    vec.push_back("pop");
    vec.push_back("programming");

    MyFunctor fun(5);
    int count = count_if(vec.begin(), vec.end(), fun);
    cout<<"length(str) < 5="<<count<<endl;
}


