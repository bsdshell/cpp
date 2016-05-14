#include<iostream>
using namespace std;

class StopWatch{
    public:
    double duration_;
    std::clock_t start_;
    public:
    StopWatch() {
        duration_ = 0;
    }
    public:
    void start(){
        start_ = std::clock();
    }
    public:
    void stop(){
        duration_ = std::clock() - start_;
    }
    public:
    double duration(){
        return duration_; 
    }
};

int main()
{
    std::cout<<"C++ Sudoku Solver"<<std::endl;
    StopWatch* sw = new StopWatch();

    sw->start();
    for(int i=0; i<100000; i++)
        std::cout<<"Duration="<<std::endl;
    sw->stop();

    std::cout<<"Duration="<<sw->duration()<<std::endl;

    if(sw)
        delete sw;
}

