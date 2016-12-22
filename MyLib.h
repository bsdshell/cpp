#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GLUT/glut.h>  /* Header File For The GLut Library*/

class Vector3{
    public:
    GLdouble v[3];
    public:
    Vector3();
    public:
    Vector3(const Vector3& other);
    Vector3(GLdouble x, GLdouble y, GLdouble z);
    Vector3(GLdouble arr[3]); 
    Vector3& operator=(const Vector3& rhs);
    Vector3 operator+(Vector3& rhs);
    Vector3 operator-(Vector3& rhs);
    Vector3 operator/(GLdouble n);
    Vector3 dot(Vector3& rhs);
    void print();
};

