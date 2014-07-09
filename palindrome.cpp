#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

bool isPalindrome(char* str)
{
    bool isValid = true;
    if(str != NULL)
    {
        int len = strlen(str);
        for(int i=0; i<len/2 && isValid; i++)
        {
            if( (str[i]) != str[len-1-i])        
                isValid = false;
        }
    }
    return isValid;
}


bool isPalindromeRecursive(char* str, int i)
{
    int len = strlen(str);
    if(len <= 1)
        return true;
    else
    {
       char* pt = new char[len-2];
       strncpy(pt, str+1, len-2);
       return str[i] == str[len-1-i] && isPalindromeRecursive(pt, i+1); 
    }
}

int main(int argc, char** argv)
{
    char* str = "aaabaaa";
    int i=0;
    std::cout<<isPalindromeRecursive(str, i)<<std::endl;

    str = "";
    i=0;
    std::cout<<"str=["<<str<<"]="<<isPalindromeRecursive(str, i)<<std::endl;

    str = "a";
    i=0;
    std::cout<<"str=["<<str<<"]"<<isPalindromeRecursive(str, i)<<std::endl;

    str = "ab";
    i=0;
    std::cout<<"str=["<<str<<"]"<<isPalindromeRecursive(str, i)<<std::endl;

    str = "aa";
    i=0;
    std::cout<<"str=["<<str<<"]"<<isPalindromeRecursive(str, i)<<std::endl;

    str = "aab";
    i=0;
    std::cout<<"str=["<<str<<"]"<<isPalindromeRecursive(str, i)<<std::endl;

    str = "aabb";
    i=0;
    std::cout<<"str=["<<str<<"]"<<isPalindromeRecursive(str, i)<<std::endl;

    str = "abba";
    i=0;
    std::cout<<"str=["<<str<<"]"<<isPalindromeRecursive(str, i)<<std::endl;

}
