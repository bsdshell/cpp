#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;
int main(int argc, char** argv)
{
    string str = "The cat is black";
    int len = str.length();
    char* array = new char[len+1];
    strncpy(array, str.c_str(), len);
    array[len+1] = '0';

    std::cout<<array<<std::endl;
    for(int i=0; i<len/2; i++)
    {
        int tmp = array[len-1-i];
        array[len-1-i] = array[i];
        array[i] = tmp;
    }
    std::cout<<array<<std::endl;

    delete array;
}

