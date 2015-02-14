#include<iostream>

using namespace std;
int main()
{
    std::cout<<"Hello World";
    const int len = 4;
    char array[len] = {'a', 'b', 'e', 'k'};
    string str1(1, 'a');
    string str2(1, 'b');

    string s;
    for(char ch:array)
        s += string(1, ch) + "#";
    string str = str1 + str2;
    std::cout<<"str="<<str<<endl;
    std::cout<<"s="<<s<<endl;

    s[s.length()-1] = '\0';
    std::cout<<"s="<<s<<endl;
}

