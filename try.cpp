#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int* process(string str)
{
    int len = str.length();
    int* intArr = new int[2*len-1];
    int c=0;
    for(int i=0; i<len; i++)
    {
        intArr[i+c] = str[i]-'0';
        std::cout<<"["<<i+c<<"]="<<intArr[i+c]<<std::endl;
        c++;
    }
    return intArr; 
}

class Interval
{
    public:
        int leftIndex;
        int rightIndex;
        int sum;
    public:
        Interval(int leftIndex, int rightIndex, int sum)
        {
            this->leftIndex = leftIndex;
            this->rightIndex= rightIndex;
            this->sum= sum;
        }
};
int evaluate(int* intArr, int len, int target)
{
    int count=0;
    int sum=0;
    bool first = false; 
    int leftIndex = -1;
    int rightIndex = -1;
    vector<Interval> vect;
    for(int i=len-1; i >=0; i--)
    {
        if(intArr[i] == '$')
        {
            int num = intArr[i+1];
            sum += num*pow(10, count);
            count++;
            first = true;
            if(leftIndex < 0)
                leftIndex = i+1;
        }       
        else if(first && (intArr[i] =='+' || intArr[i] == '*'))
        {
            int num = intArr[i+1];
            sum += num*pow(10, count);
            std::cout<<"sum="<<sum<<std::endl;

            if(rightIndex < 0)
                rightIndex = i+1;

            Interval inter(leftIndex, rightIndex, sum);
            vect.push_back(inter);
            first = false;
            count=0;
            sum = 0;
            leftIndex = -1;
            rightIndex= -1;
        }
        else if(first && i == 0)
        {
            int num = intArr[i];
            sum += num*pow(10, count);
            std::cout<<"sum="<<sum<<std::endl;

            if(rightIndex < 0)
                rightIndex = i;

            Interval inter(leftIndex, rightIndex, sum);
            vect.push_back(inter);

            first = false;
            count=0;
            sum = 0;
            leftIndex = -1;
            rightIndex= -1;
        }
        
                 
    } 
    for(int i=0; i<vect.size(); i++)
    {
        std::cout<<"leftIndex="<<vect.at(i).leftIndex<<std::endl;
        std::cout<<"rightIndex="<<vect.at(i).rightIndex<<std::endl;
    }

    vector<int> expVect;   

    int depth = 0;
    int index = len-1;
    while(index >= 0)
    {
        if(depth < vect.size() && index == vect.at(depth).leftIndex)    
        {
            expVect.push_back(vect.at(depth).sum);
            index = vect.at(depth).rightIndex;
            depth++;
        } 
        else
        {
            expVect.push_back(intArr[index]);
        }
        index--;
    }

    std::cout<<std::endl;
    std::reverse(expVect.begin(), expVect.end());
    for(int i=0; i<expVect.size(); i++)
    {
        if(i % 2 == 0)
            std::cout<<expVect.at(i)<<" ";
        else
            std::cout<<(char)expVect.at(i)<<" ";
    }
    std::cout<<std::endl;
    for(int i=0; i<expVect.size(); i++)
    {
        if(expVect[i] == '*')
        {
            expVect[i] = '+';
            expVect[i+1] = expVect[i-1]*expVect[i+1];
            expVect[i-1] = 0;
        }
    }

    std::cout<<std::endl;
    for(int i=0; i<expVect.size(); i++)
    {
        if(i % 2 == 0)
            std::cout<<expVect.at(i)<<" ";
        else
            std::cout<<(char)expVect.at(i)<<" ";
    }
    std::cout<<std::endl;
    int result = 0;
    for(int i=0; i<expVect.size(); i++)
    {
        if(i % 2 == 0)
            result += expVect[i];
    }
    std::cout<<"result="<<result<<std::endl;
    if(result == target)
    {
        string exp = "";
        for(int i=0; i<len; i++)
        {
            if( i % 2 == 0)
            {
                string strInt = std::to_string(intArr[i]); 
                exp += strInt;
                std::cout<<intArr[i]<<" ";
            }
            else
            {
                string str = string(1, (char)intArr[i]);
                exp += str;
                std::cout<<(char)intArr[i]<<" ";
            }
            
        }

        std::cout<<","<<target<<"->"<<exp<<std::endl;
    }
    std::cout<<std::endl;
    std::cout<<"-------------"<<std::endl;
    return result;
}

//d=1
void perm(int* intArr, int* ops, int len, int d, int target)
{
    if(d == len)
    {
        for(int i=0; i<len; i++)
        {
            if(i%2 == 1)
                if(intArr[i] == '$')
                    std::cout<<"";
                else
                    std::cout<<(char)intArr[i]<<" ";
            else
                std::cout<<intArr[i]<<" ";
        }
        std::cout<<std::endl;
        evaluate(intArr, len, target);
    }
    else
    {
        for(int i=0; i<3; i++)
        {
            intArr[d] = ops[i]; 
            perm(intArr, ops, len, d+2, target);
        }    
    }
}

void match(string str, int target)
{
    if(!str.empty())
    {
        if(str.length() == 1)
        {
            if(atoi(str.c_str()) == target)    
                std::cout<<str<<","<<target<<"->"<<str<<std::endl;
        }
        else if(str.length() > 1)
        {
            int len = 2*str.length()-1;
            int* intArr = process(str);
            int* ops = new int[3];
            ops[0] = '+';
            ops[1] = '*';
            ops[2] = '$';
            int d=1;
            perm(intArr, ops, len, d, target);
        }
    }
}

void test1()
{
    string str = "12345";
    int target = 5535;
    match(str, target);
}
int main()
{
    std::cout<<"Hello World"<<std::endl;
    test1();
}



