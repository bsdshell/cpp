#include<iostream>
#include "Aron.h"
using namespace std;

void printVector(std::vector<int> vec){
    for(int i=0; i<vec.size(); i++){
        std::cout<<"["<<vec[i]<<"]"<<std::endl;
    } 
}

void printArray(int* arr, int len){
    for(int i=0; i<len; i++){
        std::cout<<"["<<arr[i]<<"]"<<std::endl;
    } 
}


 
