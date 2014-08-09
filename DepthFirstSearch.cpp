#include<iostream>
#include<stack>
using namespace std;

void PrintLocation(int down, int right)
{
    string str = std::to_string(down) + " " + std::to_string(right);
    std::cout<<"["<<str<<"]"<<std::endl;
}

void PrintMaze(int array[][6], int width, int height)
{
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<6; j++)
        {
            if(down == i && j == right)
                std::cout<<"["<<"x"<<"]";
            else
                std::cout<<"["<<array[i][j]<<"]";
        }
        std::cout<<std::endl;
    }
}
bool DepthFirstSearch(int array[][6], int down, int right)
{
    if(down < 5 && right < 6) 
    {
        if(array[down][right] == 0 || array[down][right] == 2)
        {
            for(int i=0; i<5; i++)
            {
                for(int j=0; j<6; j++)
                {
                    if(down == i && j == right)
                        std::cout<<"["<<"x"<<"]";
                    else
                        std::cout<<"["<<array[i][j]<<"]";
                }
                std::cout<<std::endl;
            }
            std::cout<<std::endl;

            if(DepthFirstSearch(array, down+1, right)) 
            {
                PrintLocation(down, right); 
                return true;
            }

            if(array[down][right] == 2)
            {
                std::cout<<"Done"<<std::endl;
                PrintLocation(down, right); 
                return true;
            }

            if(DepthFirstSearch(array, down, right+1))     
            {
                PrintLocation(down, right); 
                return true;
            }
        }
    }
    return false;
}


int main(int argc, char *argv[])
{
    const int row = 5;
    const int col = 6;
    int Array[row][col] = {
        {0, 1, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 1, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 2}
    };

    int right = 0;
    int down = 0;
    DepthFirstSearch(Array, down, right);
    std::cout<<std::endl;
    std::cout<<"spiral"<<std::endl;
}
