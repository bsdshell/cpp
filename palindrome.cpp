#include<iostream>
#include<vector>

/*
 * abbkkbe
 *
 * a
 * ab
 * abb
 * abbk
 * abbkk
 * abbkkb
 *  bbkkb
 *   bkkb
 *    kkb
 * abbkkbe
 */ 

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

int longestPalindrome(string str)
{
    int len = str.length();
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
        int left = 0;
        int right = 0;
        while(i - (offset + 1)>=0 && i + (offset + 1) < newStr.length())
        {
            int tmpLeft = i - (offset + 1);
            int tmpRight= i + (offset + 1);
            if(newStr[tmpLeft] == newStr[tmpRight])
            {
                left = tmpLeft;
                right = tmpRight;
                offset++;
            }
            else
                break;
        }
        if(offset > maxOffset)
        {
            leftIndex = left;
            rightIndex = right;
            maxOffset = offset;
        }
    } 

    string palindrome = "";
    for(int i=leftIndex; i<=rightIndex; i++)
    {
        if(newStr[i] != '#')
            palindrome += string(1, newStr[i]);
    }

    std::cout<<"palindrome="<<palindrome<<endl;

    return maxOffset;
}

void test1()
{
    std::cout<<"test1()"<<std::endl;
    string str = "abb";
    int maxOffset = longestPalindrome(str);
    std::cout<<"maxOffset="<<maxOffset<<std::endl;
}

void test2()
{
    std::cout<<"test2()"<<std::endl;
    const int len=1;
    string str = "a";
    int maxOffset = longestPalindrome(str);
    std::cout<<"maxOffset="<<maxOffset<<std::endl;
}

void test3()
{
    std::cout<<"test3()"<<std::endl;
    string str = "aabbeebb";
    int maxOffset = longestPalindrome(str);
    std::cout<<"maxOffset="<<maxOffset<<std::endl;
}

void test4()
{
    std::cout<<"test4()"<<std::endl;
    string str = "abba";
    int maxOffset = longestPalindrome(str);
    std::cout<<"maxOffset="<<maxOffset<<std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
}

