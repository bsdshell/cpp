//
//  main.cpp
//  kdistGraph
//
//  Created by cat on 6/7/16.
//  Copyright © 2016 myxcode. All rights reserved.
//

#include <iostream>


void kdistGraph(int** arr, int k, int h, int w){
    if(k == 0){
        std::cout<<"["<<h<<"]"<<std::endl;
    }else if(k > 0){
        for(int i=0; i<w; i++){
            if(h >= 0 && arr[h][w]){
                kdistGraph(arr, k-1, i, w);
            }
        }
    }
}

void test4(){
    printf("[%s]--------\n", __PRETTY_FUNCTION__);
    const int width = 5;
    int height= 5;
    int k = 2;
    
    int** arr = new int*[height];
    for(int i=0; i<height; i++){
        arr[i] = new int[width];
    }
    arr[0][1] = 1;
    arr[0][2] = 1;
    
    arr[1][2] = 1;
    arr[1][3] = 1;
    
    arr[2][3] = 1;
    arr[2][4] = 1;
    
    arr[3][4] = 1;
    
    kdistGraph(arr, k, height, width);
    
    
    for(int i=0; i<height; i++){
        delete[] arr[i];
    }
    delete[] arr;
    
    
    printf("---------------------------------\n");
} 



int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    test4();
    
    return 0;
}
