#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(int* array, int len, int* pbuff)
{
    int c=0; 
    int plen=-1;
    bool isPalin = true;
    while(c < len && isPalin)
    {
        int moveLeft=0;
        isPalin = true;
        for(int i=c; i<len && isPalin; i++)
        {
            if(array[i] != array[len-i-moveLeft])
                isPalin = false;

            moveLeft++;
        }
        if(isPalin)
        {
            int index=0;
            for(int i=c; i<len; i++)
            {
                pbuff[index] = array[i];
                index++;
            }
            plen = len-c;
        }
        c++;
    }
    return plen; 
}

void maxPalindrome(int* array, int len, int* pbuff)
{
    int* maxbuff = new int[len];
    int index=0;
    int maxLen = 0;
    for(int i=0; i<len; i++)
    {
        if(maxLen < (len = isPalindrome(array, i+1, pbuff)))        
        {
            maxLen = len;
            for(int i=0; i<maxLen; i++)
            {
                maxbuff[i] = pbuff[i];
            }
        }
    }
}

string longestPalindrome(string str)
{
    string newStr = "";
    for(char ch:str)
        newStr += string(1, ch) + "#"; 

    //Trim the last character
    newStr[newStr.length()-1] = '\0';

    int maxOffset = 0;
    int leftIndex = 0;
    int rightIndex= 0;
    for(int i=0; i<newStr.length(); i++)
    {
        int offset = 0;
        int tmpLeft = i - (offset + 1);
        int tmpRight= i + (offset + 1);
        while(tmpLeft >=0 && tmpRight < newStr.length())
        {
            if(newStr[tmpLeft] == newStr[tmpRight])
                offset++;
            else
                break;

            tmpLeft = i - (offset + 1);
            tmpRight= i + (offset + 1);
        }

        if(offset > maxOffset)
        {
            leftIndex = tmpLeft;
            rightIndex = tmpRight;
            maxOffset = offset;
        }
    } 

    string palindrome = "";
    for(int i=leftIndex; i<=rightIndex; i++)
    {
        if(newStr[i] != '#')
            palindrome += string(1, newStr[i]);
    }

    return palindrome;
}

bool isPalindrome(string str)
{
    string originalStr = str;
    int len = str.length();
    for(int i=0; i<len/2; i++)
    {
        char tmpch = str[i];    
        str[i] = str[len-1-i];
        str[len-1-i] = tmpch;
    }
    return originalStr.compare(str);
}
string longestPalindrome2(string str)
{
    int offset=0;
    int maxLen=0;
    string maxStr="";
    while(offset < str.length())
    {
        for(int i=0; i<str.length(); i++)
        {
            if(offset + (i+1) <= str.length())
            {
                string substr = str.substr(offset, i+1);
                std::cout<<"substr="<<substr<<std::endl;
                int slen = substr.length();
                if(isPalindrome(substr) == 0)
                {
                    if(slen > maxLen)
                    {
                        maxStr = substr;
                        maxLen = slen;
                    }
                }
            }
        }
        offset++;
    }
    return maxStr;
}

void test1()
{
    std::cout<<"test1()"<<std::endl;
    string str = "abb";
    string palindrome = longestPalindrome(str);
    std::cout<<"str       ="<<str<<std::endl;
    std::cout<<"palindrome="<<palindrome<<std::endl<<std::endl;
}

void test2()
{
    std::cout<<"test2()"<<std::endl;
    const int len=1;
    string str = "a";
    
    string palindrome = longestPalindrome(str);
    std::cout<<"str       ="<<str<<std::endl;
    std::cout<<"palindrome="<<palindrome<<std::endl<<std::endl;
}

void test3()
{
    std::cout<<"test3()"<<std::endl;
    string str = "aabbeebb";
    string palindrome = longestPalindrome(str);
    std::cout<<"str       ="<<str<<std::endl;
    std::cout<<"palindrome="<<palindrome<<std::endl<<std::endl;
}

void test4()
{
    std::cout<<"test4()"<<std::endl;
    string str = "kakbaea";
    string palindrome = longestPalindrome(str);
    std::cout<<"str       ="<<str<<std::endl;
    std::cout<<"palindrome="<<palindrome<<std::endl<<std::endl;
}

void test5()
{
    std::cout<<"test5()"<<std::endl;
    string str = "kakbjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjasdfkasdljfalsjdfkkkkkkkkkkkkkkkkkk:lsdfdfkfksdfkaskjefaiwfjiafaea";
    string maxStr = longestPalindrome2(str);
    std::cout<<"maxStr="<<maxStr<<std::endl;
}


int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
}

