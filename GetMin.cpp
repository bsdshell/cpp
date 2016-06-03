//
//  main.cpp
//  firstcpp
//
//  Created by cat on 6/1/16.
//  Copyright © 2016 myxcode. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;

//[ file=getmin.html title=""
template <class T>
class StackMin{
    public:
    stack<T> st;
    stack<T> minstack;
    StackMin(){
    }
    public:
    T getMin(){
        if(minstack.size() > 0)
            return minstack.top();
        return -1;
    }
    void push(T n){
        if(minstack.size() == 0)
            minstack.push(n);
        else{
            if(n < minstack.top()){
                minstack.push(n);
            }
        }

        st.push(n);
    }
    T pop(){
        if(st.size() > 0){
            if(minstack.top() == st.top()){
                minstack.pop();
                T n = st.top();
                st.pop();
                return n;
            }
            else{
                int n = st.top();
                st.pop();
                return n;
            }
        }
        return -1;
    }
    
};
//]

int main(int argc, const char * argv[]) {
    // insert code here...
    StackMin<int> st;
    st.push(3);
    st.push(8);
    st.push(1);
    st.push(2);
    int m = st.getMin();
    std::cout<<"m="<<m<<'\n';
    st.pop();
    st.pop();
    //st.pop();
    //st.pop();
    m = st.getMin();
    std::cout<<"m="<<m<<'\n';
    
    return 0;
}
