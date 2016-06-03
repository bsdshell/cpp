#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

bool power2(int n){
    if(n == 0 || n == 1 )
        return true;
    else{ 
        if(n % 2 != 0) 
            return false;
        else
            return power2(n/2);
    }
}

bool fastPower2(int n){
    return (n & (n-1)) == 0;
}

vector<int> decimalToBinary(int n){
    vector<int> vec;
    if(n > 0){
        while(n > 0){
            int r = n % 2;
            vec.push_back(r);
            n = n/2;        
        }
    }else{
        vec.push_back(n);
    }
    std::reverse(vec.begin(), vec.end());
    return vec;
}

int stringToDecimal(string str){
    int len = str.size();
    int s = 0;
    for(int i=0; i<len; i++){
        int n = str[len-1-i] - '0';
        s += n*pow(10, i); 
    }
    return s;
}


void test5(){
    string str = "100";
    std::cout<<"100="<<stringToDecimal(str)<<std::endl;
}
void test4(){
    string str = "0";
    std::cout<<"0="<<stringToDecimal(str)<<std::endl;
}
void test3(){
    string str = "123";
    std::cout<<"123="<<stringToDecimal(str)<<std::endl;
}

void test2(){
    printf("fastPower2---------------------------------\n");
    std::cout<<"0="<<fastPower2(0)<<std::endl;
    std::cout<<"1="<<fastPower2(1)<<std::endl;
    std::cout<<"2="<<fastPower2(2)<<std::endl;
    std::cout<<"8="<<fastPower2(8)<<std::endl;
    std::cout<<"10="<<fastPower2(10)<<std::endl;
    std::cout<<"16="<<fastPower2(16)<<std::endl;
    std::cout<<"256="<<fastPower2(256)<<std::endl;
    printf("---------------------------------\n");
}
void test1(){
    printf("test1()---------------------------------\n");
    vector<int> vec = decimalToBinary(10);
    for(int i=0; i<vec.size(); i++){
        std::cout<<vec[i]<<std::endl;
    }
    printf("---------------------------------\n");
}
void test0(){
    std::cout<<"0="<<power2(0)<<std::endl;
    std::cout<<"1="<<power2(1)<<std::endl;
    std::cout<<"2="<<power2(2)<<std::endl;
    std::cout<<"8="<<power2(8)<<std::endl;
    std::cout<<"10="<<power2(10)<<std::endl;
    std::cout<<"16="<<power2(16)<<std::endl;
    std::cout<<"256="<<power2(256)<<std::endl;
}

int main() {
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
}

