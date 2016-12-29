#include <stdlib.h>
#include <stdio.h>


void fun1(int x, int y, int z){
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            for(int k=-1; k<=1; k++){
                printf("[%i][%i][%i]\n", x + i, y + j, z + k);
            }
            printf("\n");
        }
        printf("\n");
    }
}

void fun2(){
    int w = 4;
    int h = 4;
    int d = 4;
    for(int i=1; i<w-1; i++){
        for(int j=1; j<h-1; j++){
            for(int k=1; k<d-1; k++){
                fun1(i, j, k);
            }
        }
    }
}

int main(){
    fun2();
}

