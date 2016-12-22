#include<iostream>
#include<unistd.h>


using namespace std;

int main() {
    for(int i=0; i<100; i++){
        usleep(1000000);
        cout<<"sleep"<<endl;
    }
}

