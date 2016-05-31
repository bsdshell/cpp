#include<iostream>
#include<memory>

using namespace std;

//[file=breakcycle.html title=""
class Class2;
class Class1{
    public:
    //shared_ptr<Class2> c2;
    weak_ptr<Class2> c2;
    public:
    ~Class1(){
        printf("Destroy Class1()\n");
    }
};

class Class2{
    public:
        shared_ptr<Class1> c1;
    public:
    ~Class2(){
        printf("Destroy Class2()\n");
    }
};

void cycle(){
    auto c1 = make_shared<Class1>();
    auto c2 = make_shared<Class2>();
    c1->c2 = c2;
    c2->c1 = c1;
}
//]

int main() {
    printf("bug\n"); 
    cycle();
    printf("finished!\n");
}

