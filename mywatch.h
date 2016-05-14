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
        duration_ = (std::clock() - start_)/(double)CLOCKS_PER_SEC;
    }
    public:
    double duration(){
        return duration_; 
    }
};


