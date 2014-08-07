#include<iostream>
#include<stack>
using namespace std;

bool DepthFirstSearch(int array[][6], int down, int right)
{
    if(down < 5 && right < 6) 
    {
        if(DepthFirstSearch(array, down+1, right)) 
        {
            string str = std::to_string(down) + " " + std::to_string(right);
            std::cout<<"["<<str<<"]"<<std::endl;
            return true;
        }
        else if(array[down][right] == 0)
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

            if(!DepthFirstSearch(array, down+1, right)) 
                return false;
            if(!DepthFirstSearch(array, down, right+1))     
                return false;
            return false;
        }
        else if(array[down][right] == 2)
        {
            std::cout<<"Done"<<std::endl;
            string str = std::to_string(down) + " " + std::to_string(right);
            std::cout<<str<<std::endl;
            return true;
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
