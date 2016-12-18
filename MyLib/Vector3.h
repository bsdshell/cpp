#ifndef VECTOR3 
#define VECTOR3 

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GLUT/glut.h>  /* Header File For The GLut Library*/

class Vector3{
    public:
    GLdouble v[3];
    public:
    Vector3(){ }
    public:

    Vector3(const Vector3& other){
        this->v[0] = other.v[0];
        this->v[1] = other.v[1];
        this->v[2] = other.v[2];
    }

    Vector3(GLdouble x, GLdouble y, GLdouble z){ 
        v[0] = x;
        v[1] = y;
        v[2] = z;
    }

    Vector3(GLdouble arr[3]){ 
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

    Vector3 operator/(GLdouble n){
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
