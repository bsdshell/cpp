#include<iostream>

int main()
{
    int row = 4;
    int col = 4;
    int Array[4][4] = {
        { 1,  2,  3, 4},
        {12, 13, 14, 5},
        {11, 16, 15, 6},
        {10,  9,  8, 7}
    };

    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            std::cout<<"["<<Array[i][j]<<"]";
        }
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    for(int i=0; i<row/2; i++)
    {
        for(int j=i; j<col-1-i; j++)
        {
            std::cout<<"["<<Array[i][j]<<"]";
        }
        std::cout<<std::endl;
        for(int j=i; j<col-1-i; j++)
        {
            std::cout<<"["<<Array[j][col-1-i]<<"]";
        }
        std::cout<<std::endl;
        for(int j=i; j<col-1-i; j++)
        {
            std::cout<<"["<<Array[row-1-i][col-1-j]<<"]";
        }
        std::cout<<std::endl;
        for(int j=i; j<col-1-i; j++)
        {
            std::cout<<"["<<Array[row-1-j][i]<<"]";
        }
        std::cout<<std::endl;
    }

    std::cout<<"spiral"<<std::endl;
}
