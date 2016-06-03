#include<iostream>
#include<array>

using namespace std;

//[ file=stdarray.html title=""
template<typename T, int n>
class MyArray{
    private:
        T* arr;
    public:
        MyArray(){
            arr = new int[n];
        }
        ~MyArray(){
            delete[] arr;
        }
        T& operator[](int index) {
            return *(arr + index);
        }
};

void test0(){
    const int len = 3;
    std::array<int, len> arr = {1, 2, 3};
    for(int i=0; i<arr.size(); i++){
        std::cout<<"["<<arr[i]<<"]"<<'\n';
    } 
}
//]

void test1(){
    const int len1 = 4;
    MyArray<int, len1> myarr;
    for(int i=0; i<len1; i++){
        std::cout<<"["<<myarr[i]<<"]"<<'\n';
    } 
}

int main(){
    //test0();
    test1();
}

