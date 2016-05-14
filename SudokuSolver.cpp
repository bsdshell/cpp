#include<iostream>
#include<vector>
#include "mywatch.h"

//#include "boost/multi_array.hpp"
//#include <cassert>

using namespace std;

class SudokuSovler{
    int countZero;
    int countSolu;
    vector< vector<int> > vect;
    int board[9][9] = 
    {
        {0,0,0,2,0,0,0,0,0},
        {0,0,0,1,0,7,0,0,0},
        {0,0,6,0,3,0,5,0,0},
        {0,0,0,0,0,9,0,8,0},
        {0,0,0,0,2,0,0,0,4},
        {0,0,0,8,0,0,0,5,0},
        {0,0,9,0,4,0,3,0,1},
        {0,0,0,7,0,2,0,0,0},
        {0,0,0,0,0,8,0,0,6}

        //{3,0,0,2,0,0,0,0,0},
        //{0,0,0,1,0,7,0,0,0},
        //{7,0,6,0,3,0,5,0,0},
        //{0,7,0,0,0,9,0,8,0},
        //{9,0,0,0,2,0,0,0,4},
        //{0,1,0,8,0,0,0,5,0},
        //{0,0,9,0,4,0,3,0,1},
        //{0,0,0,7,0,2,0,0,0},
        //{0,0,0,0,0,8,0,0,6}
    };
    public:
    SudokuSovler(){
        countSolu = 0;
        for(int c=0; c<9; c++){    
            for(int r=0; r<9; r++){
                if(board[c][r] == 0){
                    vector<int> v;
                    v.push_back(c);
                    v.push_back(r);
                    vect.push_back(v);
                    countZero++;
                    }
                }
            std::cout<<std::endl;
        }
    }
    public:
    void printBoard(){
        for(auto& rows: board){    
            for(auto& elem: rows){
                std::cout<<"["<<elem<<"]";
            }
            std::cout<<std::endl;
        }
    }
    public: 
    bool checkColRow(int col, int row, int n) {
        for(int i=0; i<9; i++){
            if(board[col][i] == n || board[i][row] == n)
                return false;
        }
        return true;
    }
    public: 
    bool checkBlock(int col, int row, int n)
    {
        int cc = col/3;
        int rr = row/3;
        for(int c=0; c<3; c++){
            for(int r=0; r<3; r++) {
                if(board[c + cc*3][r + rr*3] == n)
                    return false;

            }
        }
        return true;
    }
    public:
    void solver(int k)
    {
        if(k == countZero) {
            //countSolu++;
            //std::cout<<"countSolu="<<countSolu<<std::endl;
            //printBoard();
            //std::cout<<std::endl;
        }
        else{
            for(int n=1; n<=9; n++)
            {
                int c = vect[k][0];
                int r = vect[k][1];

                if(checkColRow(c, r, n) && checkBlock(c, r, n)){
                    board[c][r] = n;
                    solver(k+1);
                    board[c][r] = 0;
                }
            }
        }
    }
    public:
        ~SudokuSovler()
        {
            std::cout<<"call ~SudokuSovler()"<<std::endl;
        }
};


int main()
{
    std::cout<<"C++ Sudoku Solver"<<std::endl;
    StopWatch* sw = new StopWatch();
    SudokuSovler* sudoku = new SudokuSovler();

    sudoku->printBoard();
    std::cout<<std::endl;
    int k=0;
    sw->start();
    sudoku->solver(k);
    sw->stop();
    std::cout<<"Duration="<<sw->duration()<<std::endl;

    if(sudoku)
        delete sudoku;
}

