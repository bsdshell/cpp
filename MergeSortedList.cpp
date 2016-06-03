#include<iostream>
#include<vector>
#include "Aron.h"

using namespace std;

//[file=mergesortedlist.html title=""
// Merge two sorted arrays
vector<int> merge(vector<int> vec1, vector<int> vec2){
    int len1 = vec1.size();
    int len2 = vec2.size();
    vector<int> vec;
    int i = 0, j=0;

    while(i < len1 || j < len2){
        if(i >= len1){
            vec.push_back(vec2[j]);
            j++;
        }
        else if(j >= len2){
            vec.push_back(vec1[i]);
            i++;
        }
        else{
            if(vec1[i] < vec2[j]){
                vec.push_back(vec1[i]);
                i++;
            }
            else if(vec1[i] == vec2[j]){
                vec.push_back(vec1[i]);
                vec.push_back(vec2[j]);
                i++; j++;
            }else{
                vec.push_back(vec2[j]);
                j++;
            }
        }
    }
    return vec;
}
//]

void test0(){
    printf("---------------------------------\n");
    vector<int> vec1;
    vector<int> vec2 = {2, 10, 23};
    vector<int> vec = merge(vec1, vec2);
    printVector(vec);
}

void test1(){
    printf("---------------------------------\n");
    vector<int> vec1 = {1, 4, 9};
    vector<int> vec2 = {2, 10, 23};
    vector<int> vec = merge(vec1, vec2);
    printVector(vec);
}

void test2(){
    printf("---------------------------------\n");
    vector<int> vec1 = {1, 4, 4, 9};
    vector<int> vec2 = {2, 4, 23};
    vector<int> vec = merge(vec1, vec2);
    printVector(vec);
}
void test3(){
    printf("---------------------------------\n");
    vector<int> vec1 = {9};
    vector<int> vec2 = {9};
    vector<int> vec = merge(vec1, vec2);
    printVector(vec);
}

int main(){
    test0();
    test1();
    test2();
    test3();
}

