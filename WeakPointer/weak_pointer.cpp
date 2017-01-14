#include <stdlib.h>
#include <stdio.h>
#include <iostream>

// weak pointer in c++11, how to use weak pointer
// what is danging pointer in c++
// gx http://stackoverflow.com/questions/12030650/when-is-stdweak-ptr-useful
// 
using namespace std;
int main(){
    int* pt = new int(10);
    int* pt2 = pt;
    cout<<"*pt="<<*pt<<endl;

    delete pt;

    // pt2 is danging pointer now
    if(pt2 != NULL)
        cout<<"pt2 is danging pointer"<<endl;
    else
        cout<<"pt2 is not danging pointer"<<endl;
    
    // how to use weak pointer to avoid danging pointer
    // empty shared pointer 
    shared_ptr<int> spt;
    spt.reset(new int);
    *spt = 100;

    // assign spt to a weak pointer
    weak_ptr<int> weak1 = spt;

    spt.reset(new int(666));

    weak_ptr<int> weak2 = spt;

    if(auto tmp = weak1.lock())
        cout<<*tmp<<endl;
    else 
        cout<<"weak1 is expired"<<endl;

    if(auto tmp1 = weak2.lock())
        cout<<"*tmp1="<<*tmp1<<endl;
    else
        cout<<"weak2 is expired"<<endl;
}

