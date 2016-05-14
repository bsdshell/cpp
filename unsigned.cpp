#include<iostream>
#include<vector>

using namespace std;
int main() {
    unsigned num = 10;
    int negative = -10;
    if(negative < num)
        cout<<"Ok"<<endl;
    else
        cout<<"Bug"<<endl;

    
    unsigned n = 0;
    cout<<"n-1="<<n-1<<endl;

    if(n - 1 < 0){
        cout<<"Ok"<<endl;
    }else{
        cout<<"Bug"<<endl;
    }

    // C++11 only
    // Compile g++ -std=c++11 
    std::vector<int> v = {1, 2, 4};
    for(int i=0; i<v.size()-1; i++){
        cout<<"v["<<i<<"]="<<v[i]<<endl;
    }

    std::vector<int> v1 = {};
    for(unsigned i=0; i < v1.size()-1; i++){
        cout<<"v1["<<i<<"]="<<v1[i]<<endl;
    }

}

