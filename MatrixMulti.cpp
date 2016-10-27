#include<iostream>

void matrixMultiply(double** mat1, double** mat2, int height, int width) {
    double** mat = new double*[height];
    for(int i=0; i<height; i++) {
        mat[i] = new double[width];
    }

    for(int k=0; k<width; k++) {
        for(int i=0; i<height; i++) {
            for(int j=0; j<width; j++) {
                mat[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            std::cout<<"["<<mat[i][j]<<"]";
        }
        std::cout<<std::endl;
    }
}

int main(int argc, char** avgv) {
    std::cout<<"Matrix Multiplication"<<std::endl;
    const int row = 4;
    const int col = 4;
    int Mat1[row][col] = {
        { 1,   2,  3,  4},
        {16,  17, 18, 19},
        {15,  24, 23, 22},
        {14,  13, 12, 11}
    };

    int Mat2[row][col] = {
        { 1,   2,  3,  4},
        {16,  17, 18, 19},
        {15,  24, 23, 22},
        {14,  13, 12, 11}
    };

    for(int i=0; i<row; i++) {
        for(int j=0; j<row; j++) {
            std::cout<<"["<<Mat1[i][j]<<"]";
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<row; j++) {
            std::cout<<"["<<Mat2[i][j]<<"]";
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;


    int Mat3[row][col];
    for(int k=0; k<row; k++) {
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                Mat3[i][j] += Mat1[i][k]*Mat2[k][j];
            }
        }
    }

    for(int i=0; i<row; i++) {
        for(int j=0; j<row; j++) {
            std::cout<<"["<<Mat3[i][j]<<"]";
        }
        std::cout<<std::endl;
    }
}

