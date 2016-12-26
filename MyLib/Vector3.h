#ifndef __VECTOR3__
#define __VECTOR3__ 

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GLUT/glut.h>  /* Header File For The GLut Library*/

//class Vector4{
//    float value[4];
//    public:
//    Vector4(){
//        value[0] = value[1] = value[2] = value[3] = 0.0f;
//    }
//    Vector4(const Vector4& other){
//        this->value[0] = other.value[0];
//        this->value[1] = other.value[1];
//        this->value[2] = other.value[2];
//        this->value[3] = other.value[3];
//    }
//    Vector4(float x, float y, float z, float w = 0.0f){
//        this->value[0] = x;
//        this->value[1] = y;
//        this->value[2] = z;
//        this->value[3] = w;
//    }
//    Vector4(float arr[4]){
//        this->value[0] = arr[0];
//        this->value[1] = arr[1];
//        this->value[2] = arr[2];
//        this->value[3] = arr[3];
//    }
//
//    Vector4& operator=(const Vector4& rhs){
//        this->value[0] = rhs.value[0];
//        this->value[1] = rhs.value[1];
//        this->value[2] = rhs.value[2];
//        this->value[3] = rhs.value[3];
//        return *this; 
//    }
//
//    Vector4 operator+(Vector4& rhs){
//        Vector4 v; 
//        v.value[0] = this->value[0] + rhs.value[0];
//        v.value[1] = this->value[1] + rhs.value[1];
//        v.value[2] = this->value[2] + rhs.value[2];
//        v.value[3] = this->value[3] + rhs.value[3];
//        return v; 
//    }
//
//    Vector4 operator-(Vector4& rhs){
//        Vector4 v; 
//        v.value[0] = this->value[0] - rhs.value[0];
//        v.value[1] = this->value[1] - rhs.value[1];
//        v.value[2] = this->value[2] - rhs.value[2];
//        v.value[3] = this->value[3] - rhs.value[3];
//        return v;
//    }
//};
//
//
class Vector3{
    public:
    GLfloat v[3];
    public:
    Vector3(){ }
    public:

    Vector3(const Vector3& other){
        this->v[0] = other.v[0];
        this->v[1] = other.v[1];
        this->v[2] = other.v[2];
    }

    Vector3(GLfloat x, GLfloat y, GLfloat z){ 
        v[0] = x;
        v[1] = y;
        v[2] = z;
    }

    Vector3(GLfloat arr[3]){ 
        v[0] = arr[0];
        v[1] = arr[1];
        v[2] = arr[2];
    }

    Vector3& operator=(const Vector3& rhs){
        this->v[0] = rhs.v[0];
        this->v[1] = rhs.v[1];
        this->v[2] = rhs.v[2];
        return *this; 
    }

    Vector3 operator+(Vector3::Vector3& rhs){
        Vector3::Vector3 v; 
        v.v[0] = this->v[0] + rhs.v[0];
        v.v[1] = this->v[1] + rhs.v[1];
        v.v[2] = this->v[2] + rhs.v[2];
        return v; 
    }

    Vector3 operator-(Vector3::Vector3& rhs){
        Vector3::Vector3 v; 
        v.v[0] = this->v[0] - rhs.v[0];
        v.v[1] = this->v[1] - rhs.v[1];
        v.v[2] = this->v[2] - rhs.v[2];
        return v;
    }

    Vector3 operator/(GLfloat n){
        //Vector3* v = new Vector3(); 
        Vector3::Vector3 v; 
        v.v[0] = this->v[0]/n;
        v.v[1] = this->v[1]/n;
        v.v[2] = this->v[2]/n;
        return v;
    }

    Vector3 dot(Vector3::Vector3& rhs){
        Vector3::Vector3 v; 
        v.v[0] = this->v[0] * rhs.v[0];
        v.v[1] = this->v[1] * rhs.v[1];
        v.v[2] = this->v[2] * rhs.v[2];
        return v;
    }
    void print(){ 
        printf("x=[%f], y=[%f], z=[%f]\n", v[0], v[1], v[2]);
    }
};

#endif
