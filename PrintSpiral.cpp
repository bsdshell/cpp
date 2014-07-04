#include<iostream>

int main()
{
    /*
    int row = 4;
    int col = 6;
    int Array[4][6] = {
        { 1,   2,  3,  4,  5, 6},
        {16,  17, 18, 19, 20, 7},
        {15,  24, 23, 22, 21, 8},
        {14,  13, 12, 11, 10, 9}
    };
    */
    int row = 1;
    int col = 6;
    int Array[1][6] = {
        { 1,   2,  3,  4,  5, 6}
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

    if(col > row)
    {
        for(int i=0; i<row/2; i++)
        {
            for(int j=i; j<col-1-i; j++)
            {
                std::cout<<"["<<Array[i][j]<<"]";
            }
            std::cout<<std::endl;
            for(int j=i; j<row-1-i; j++)
            {
                std::cout<<"["<<Array[j][col-1-i]<<"]";
            }
            std::cout<<std::endl;

            for(int j=i; j<col-1-i; j++)
            {
                std::cout<<"["<<Array[row-1-i][col-1-j]<<"]";
            }
            std::cout<<std::endl;

            for(int j=i; j<row-1-i; j++)
            {
                std::cout<<"["<<Array[row-1-j][i]<<"]";
            }
            std::cout<<std::endl;
        }
    }
    std::cout<<"spiral"<<std::endl;
}
