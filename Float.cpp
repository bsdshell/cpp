#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

int main()
{
    std::cout<<std::setprecision(100);

    double x = 1e-100;
    double y = 2e2;
    printf("x :=[%f]\n", x);
    printf("y :=[%d]\n", (int)y);

    double d = 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1;
    printf("d :=[%f]\n", d);

    double myd(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
    printf("myd :=[%f]\n", myd);
    std::cout<<"myd=:"<<myd<<std::endl;
}
