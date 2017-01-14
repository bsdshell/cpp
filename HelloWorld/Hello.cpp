#include<iostream>
#include "AronLib.h"

using namespace std;
using namespace Utility;
using namespace SpaceVector4;
using namespace SpaceMatrix4;

void fun(float arr[16]){
    int n1 = sizeof(arr);
    int n2 = sizeof(float);
    int num = n1/n2;
    printf("n1=[%i] n2=[%i] num=[%i]", n1, n2, num);
}


void test0(){
    begin();
    Vector4 v0 = Vector4(0, 0, 0, 0); 
    v0.print();

    Vector4 v1 = Vector4(1, 0, 0, 0); 
    v1.print();
}

void test1(){
    begin();
    Vector4 v0; 

    Vector4 v1 = Vector4(1, 0, 0, 0); 
    v0 = v1;
    v0.print();
}

void test2(){
    begin();

    Vector4 v0 = Vector4(1, 2, 3, 4); 
    Vector4 v1 = Vector4(2, 3, 4, 5); 
    Vector4 v2 = v0 + v1; 
    v2.print();
}
void test3(){
    begin();

    Vector4 v0 = Vector4(1, 2, 3, 4); 
    Vector4 v1 = Vector4(2, 3, 4, 5); 
    Vector4 v2 = v0-v1; 
    v2.print();
}

void test4(){
    begin();

    Vector4 v0 = Vector4(1, 2, 3, 4); 
    int n = 2;
    Vector4 v1 = v0/n; 
    v1.print();
}

void test5(){
    begin();

    Vector4 v0 = Vector4(1, 2, 3, 4); 
    Vector4 v1 = Vector4(2, 3, 4, 5); 
    float f0 = v0.dot(v1); 
    pp(f0);
}

void test6(){
    begin();

    Vector4 v0 = Vector4(1, 2, 3); 
    Vector4 v1 = Vector4(2, 3, 4, 5); 
    float f0 = v0.dot(v1); 
    pp(f0);
}

void test7(){
    begin();

    Vector4 v0 = Vector4(2, 3, 4, 5); 
    pp(v0[0]);
    pp(v0[1]);
    pp(v0[2]);
    pp(v0[3]);

    fl();
}

void test8(){
    begin();
    Matrix4 m;
    m.print();
    
}

void test9(){
    begin();

    Matrix4 m;
    Vector4 c0 = Vector4(1, 2, 3, 4); 
    Vector4 c1 = Vector4(1, 1, 1, 1); 
    Vector4 c2 = Vector4(3, 4, 5, 6); 
    Vector4 c3 = Vector4(10, 20, 30, 40); 
    m[0] = c0;
    m[1] = c1;
    m[2] = c2;
    m[3] = c3;
    m.print();
}

void test10(){
    begin();

    Matrix4 m;
    Vector4 c0 = Vector4(1, 2, 3, 4); 
    Vector4 c1 = Vector4(1, 1, 1, 1); 
    Vector4 c2 = Vector4(3, 4, 5, 6); 
    Vector4 c3 = Vector4(10, 20, 30, 40); 
    m[0] = c0;
    m[1] = c1;
    m[2] = c2;
    m[3] = c3;
    m.print();
    fl();
    m[0].print();
    fl();
}
void test100(){
    begin();

    Matrix4 m;
    Vector4 c0 = Vector4(1, 2, 3, 4); 
    Vector4 c1 = Vector4(1, 1, 1, 1); 
    Vector4 c2 = Vector4(3, 4, 5, 6); 
    Vector4 c3 = Vector4(10, 20, 30, 40); 
    m[0] = c0;
    m[1] = c1;
    m[2] = c2;
    m[3] = c3;
    Vector4 vv = m[0];
    m[0] = Vector4(100, 100, 100, 100);
    vv.print();
}

void test11(){
    begin();

    Matrix4 m;
    Vector4 c0 = Vector4(1, 2, 3, 4); 
    Vector4 c1 = Vector4(1, 1, 1, 1); 
    Vector4 c2 = Vector4(3, 4, 5, 6); 
    Vector4 c3 = Vector4(10, 20, 30, 40); 
    m[0] = c0;
    m[1] = c1;
    m[2] = c2;
    m[3] = c3;

    Vector4 v = m*c0;
    fl();
    m.print();
    fl();
    c0.print();
    fl();
    v.print();
    fl();
}

void test12(){
    begin();
    Vector4 c0(1, 0, 0, 0);
    Vector4 c1(0, 1, 0, 0);
    Vector4 c2(0, 0, 1, 0);
    Vector4 c3(0, 0, 0, 1);
    Matrix4 m0;
    m0[0] = c0;
    m0[1] = c1;
    m0[2] = c2;
    m0[3] = c3;

    Vector4 cc0(1, 0, 0, 0);
    Vector4 cc1(0, 1, 0, 0);
    Vector4 cc2(0, 0, 1, 0);
    Vector4 cc3(0, 0, 0, 1);

    Matrix4 m1;
    m1[0] = cc0;
    m1[1] = cc1;
    m1[2] = cc2;
    m1[3] = cc3;

    Matrix4 mat = m0*m1;
    mat.print();
}

void test13(){
    begin();
    Vector4 c0(1, 0, 0, 0);
    Vector4 c1(0, 1, 0, 0);
    Vector4 c2(0, 0, 1, 0);
    Vector4 c3(0, 0, 0, 1);
    Matrix4 m0;
    m0[0] = c0;
    m0[1] = c1;
    m0[2] = c2;
    m0[3] = c3;

    Vector4 cc0(1, 2, 3, 4);
    Vector4 cc1(5, 6, 7, 8);
    Vector4 cc2(9, 10, 11, 12);
    Vector4 cc3(13, 14, 15, 16);

    Matrix4 m1;
    m1[0] = cc0;
    m1[1] = cc1;
    m1[2] = cc2;
    m1[3] = cc3;

    Matrix4 mat = m0*m1;
    mat.print();
}

void test0_normal(){
    begin();
    Vector4 v0(0, 0, 0, 0);
    Vector4 vn = v0.normal();
    vn.print();
}
void test1_normal(){
    begin();
    Vector4 v0(1, 0, 0, 0);
    Vector4 vn = v0.normal();
    vn.print();
}

void test2_normal(){
    begin();
    Vector4 v0(1, 1, 0, 0);
    Vector4 vn = v0.normal();
    vn.print();
}
void test3_normal(){
    begin();
    Vector4 v0(1, 1, 1, 0);
    Vector4 vn = v0.normal();
    vn.print();
}

void test4_normal(){
    begin();
    Vector4 v0(3, 4, 0, 0);
    Vector4 vn = v0.normal();
    vn.print();
}

void test_translate(){
    begin();
    Matrix4 mat;
    mat.translate(1, 2, 3);
    mat.print();
}
void test1_translate(){
    begin();
    Vector4 v(1, 1, 1, 1);
    Matrix4 mat;
    mat.translate(1, 2, 3);
    Vector4 v1 = mat*v;
    v.print();
    mat.print();
    v1.print();
}

int main(){
    printf("Hello World\n"); 
    test0();
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();
    test100();
    test11();
    test12();
    test13();
    test0_normal();
    test1_normal();
    test2_normal();
    test3_normal();
    test4_normal();
    test_translate();
    test1_translate();
}

