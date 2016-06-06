#include<iostream>
#include<vector>

using namespace std;

//[ file=reversebyte.html title=""
int reverseBit(int b){
    b = (b & 0xF0) >> 4 | (b & 0x0F) << 4;
    printf("b=[%x]\n", b);
    b = (b & 0xCC) >> 2 | (b & 0x33) << 2;
    printf("b=[%x]\n", b);
    b = (b & 0xAA) >> 1 | (b & 0x55) << 1;
    printf("b=[%x]\n", b);
    return b;
} 
//]


int main(){
    unsigned int n = 4;
    unsigned int b = reverseBit(n);
    printf("b=[%x]\n", b);
}

