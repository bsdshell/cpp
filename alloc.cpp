#include<iostream>
//#include "boost/multi_array.hpp"
//#include <cassert>

int main()
{
    std::cout<<"C++ allocate memory";
    int col = 4;
    int row = 3;

    // c style
    int* pt1 = (int*)malloc(sizeof(int)*col);
    for(int i=0; i<col; i++)
        pt1[i] = i;

    for(int i=0; i<col; i++){
        printf("[%d]", pt1[i]);
    }

    free(pt1);

    printf("c style 2D: pt2[col][row]\n");
    int** pt2 = (int**)malloc(col*sizeof(int*));
    for(int i=0; i<col; i++)
        pt2[i] = (int*)malloc(row*sizeof(int));

    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++){
            pt2[i][j] = (i*row + j); 
        }
    }

    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {
            printf("[%d]", pt2[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<col; i++) {
        free(pt2[i]);
    }
    free(pt2);


    printf("c style 1D array  simulates 2D array\n");
    int* pt3 = (int*)malloc(row*sizeof(int)*col);
    for(int i=0; i<col; i++){
        for(int j=0; j<row; j++){
            pt3[i*row+j] = i*row+j;
        }
    }

    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {
            printf("[%d]", pt3[i*row+j]);
        }
        printf("\n");
    }
    free(pt3);

    printf("c++ style 1D \n");
    int* pt = new int[col];
    for(int i=0; i<col; i++)
        pt[i] = i;

    for(int i=0; i<col; i++)
        printf("[%d]", pt[i]);

    printf("\n");
    delete[] pt;

    printf("c++ style \n");
    int** array = (int**)new int*[col];
    for(int c = 0; c < col; c++)
        array[c] = (int*) new int[row];

    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {
            array[i][j] = i*row+j;
        }
    }

    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {
            printf("[%d]", array[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<col; i++)
        delete[] array[i];

    delete[] array;
}

