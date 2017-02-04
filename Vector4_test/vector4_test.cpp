#include<iostream>
#include "AronLib.h"

using namespace std;
using namespace Utility;
using namespace SpaceVector4;
using namespace SpaceMatrix4;
using namespace SpaceTest;

void test0_equal(){
    begin();
    Test<Vector4> t;
    Vector4 v1;
    Vector4 v2;
    t.t(v1, v2);

    Vector4 v11(0, 1, 0, 0);
    Vector4 v22(0, 2, 0, 0);
    t.f(v11, v22);
}

void test0_assignment(){
    begin();
    Test<Vector4> t;

    Vector4 v1(0, 1, 0, 0);
    Vector4 v2 = v1;
    t.t(v1, v2);
}

void test0_e(){
    Test<Vector4> t;
    Vector4 e1(1, 0, 0, 0);
    Vector4 v;
    Vector4 v1 = v.e1;
    t.t(e1, v.e1);
}

void test0_addition(){
    begin();
    Test<Vector4> t;

    Vector4 v1(0, 1, 0, 0);
    Vector4 v2(1, 0, 0, 0);
    Vector4 v4(1, 1, 0, 0);
    Vector4 v3 = v1 + v2;
    t.t(v3, v4);
}

void test0_subtraction(){
    begin();
    Test<Vector4> t;

    Vector4 v1(1, 2, 3, 0);
    Vector4 v2(2, 3, 4, 0);
    Vector4 v4(-1, -1, -1, 0);
    Vector4 v3 = v1 - v2;
    t.t(v3, v4);
}

void test0_div(){
    begin();
    Test<Vector4> t;

    Vector4 v1(4, 6, 4, 0);
    Vector4 v2(2, 3, 2, 0);
    Vector4 v3 = v1/2;
    t.t(v2, v3);
}

void test0_dot(){
    begin();
    Test<float> t;

    Vector4 v1(4, 1, 4, 0);
    Vector4 v2(2, 3, 1, 0);
    float dot = v1.dot(v2);
    t.t(dot, 15);
}

int main(){
    test0_equal();
    test0_e();
    test0_assignment();
    test0_addition();
    test0_subtraction();
    test0_div();
    test0_dot();
}

