#ifndef __AronLib__ 
#define __AronLib__ 

#include <execinfo.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Vector3.h"
#include "DDLinkedList.h"

#define PAD "--------------------------------------------------------------------------------"

using namespace std;

namespace Utility{
    void fl();
    string fun_parent_parent();
    void cut(char* pt);
    void pp(const char* format, ...);

    void begin(){
        int sz = 80;
        std::string pretty_fun = fun_parent_parent();
        int len = pretty_fun.length();
        printf ("[%s%.*s]\n", pretty_fun.c_str(), sz < len ? 0 : (int)(sz - len), PAD);
    }

    void begin(const char* name){
        int sz = 80;
        printf ("[%s%.*s]\n", name, (sz < strlen(name)) ? 0 : (int)(sz - strlen(name)), PAD);
    }

    void end(){
        fl();
    }

    void fl(){
        printf("[%s]\n", PAD);
    }


    void cut(char* pt){
        int k = strlen(pt) - 1;
        while(k >= 0 && pt[k] != 'v') k--;

        k >= 0 ? pt[k] = 0 : printf("Error: invalid string format.");
    }

    // get the name of parent function, get the name of caller function
    string fun_parent(){
        void *array[10];
        size_t size;
        char **strings;

        size = backtrace (array, 10);
        strings = backtrace_symbols (array, size);

        cut(strings[1]);
        string str = std::string(strings[1] + 62);
        free(strings);
        return str; 
    }

    // get name of caller of caller function, get the name of parent of parent function
    string fun_parent_parent(){
        void *array[10];
        size_t size;
        char **strings;

        size = backtrace (array, 10);
        strings = backtrace_symbols (array, size);

        cut(strings[2]);
        string str = std::string(strings[2] + 62);
        free (strings);
        return str; 
    }

    void pp(const char* format, ...){
        printf(format);
    }

    void pp(int n){
        printf("[%d]", n);
    }

    void pp(float n){
        printf("[%f]", n);
    }

    void print(Vector3::Vector3 v){
        v.print();
    }

    void print(DDLinkedList<Vector3>* ddl){
        Node<Vector3>* curr = ddl->head;
        while(curr){
            curr->data.print();
            curr = curr->next;
        }
    }

    void printFormat(GLfloat x, GLfloat y, char *format,...) {
        va_list args;
        char buffer[200], *p;

        va_start(args, format);
        vsprintf(buffer, format, args);
        va_end(args);
        glPushMatrix();
        glTranslatef(x, y, 0);
        for (p = buffer; *p; p++)
            glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
        glPopMatrix();
    }

    void printFormat(GLfloat x, GLfloat y, GLfloat fl, GLfloat f2) {
        glPushMatrix();
        glTranslatef(x, y, 0);
        char buffer1[50];
        char buffer2[50];
        sprintf(buffer1, "%f", fl);
        for (char* p = buffer1; *p; p++)
            glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);

        glTranslatef(x + 30.0, 0.0, 0);
        sprintf(buffer2, "%f", f2);
        for (char* p = buffer2; *p; p++)
            glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
        glPopMatrix();
    }

    void printFormat(GLfloat x, GLfloat y, GLfloat fl) {
        glPushMatrix();
        glTranslatef(x, y, 0);
        char buffer[50];
        sprintf(buffer, "%f", fl);
        for (char* p = buffer; *p; p++)
            glutStrokeCharacter(GLUT_STROKE_ROMAN, *p);
        glPopMatrix();
    }
};



namespace SpaceVector4{
    class Vector4{
        float column[4];
        public:
        Vector4(){
            column[0] = column[1] = column[2] = 0.0f;
            column[3] = 0.0f;
        }
        Vector4(const Vector4& other){
            this->column[0] = other.column[0];
            this->column[1] = other.column[1];
            this->column[2] = other.column[2];
            this->column[3] = other.column[3];
        }
        Vector4(float x, float y, float z, float w = 1.0f){
            this->column[0] = x;
            this->column[1] = y;
            this->column[2] = z;
            this->column[3] = w;
        }
        Vector4(float arr[4]){
            this->column[0] = arr[0];
            this->column[1] = arr[1];
            this->column[2] = arr[2];
            this->column[3] = arr[3];
        }

        Vector4& operator=(const Vector4& rhs){
            this->column[0] = rhs.column[0];
            this->column[1] = rhs.column[1];
            this->column[2] = rhs.column[2];
            this->column[3] = rhs.column[3];
            return *this; 
        }

        Vector4 operator+(Vector4& rhs){
            Vector4 v; 
            v.column[0] = this->column[0] + rhs.column[0];
            v.column[1] = this->column[1] + rhs.column[1];
            v.column[2] = this->column[2] + rhs.column[2];
            v.column[3] = 0.0f;
            return v; 
        }

        Vector4 operator-(Vector4& rhs){
            Vector4 v; 
            v.column[0] = this->column[0] - rhs.column[0];
            v.column[1] = this->column[1] - rhs.column[1];
            v.column[2] = this->column[2] - rhs.column[2];
            v.column[3] = 0.0f;
            return v;
        }

        Vector4 operator/(float n){
            Vector4::Vector4 v; 
            v.column[0] = column[0]/n;
            v.column[1] = column[1]/n;
            v.column[2] = column[2]/n;
            return v;
        }

        float dot(Vector4::Vector4& rhs){
            Vector4::Vector4 v; 
            v.column[0] = column[0] * rhs.column[0];
            v.column[1] = column[1] * rhs.column[1];
            v.column[2] = column[2] * rhs.column[2];
            return v[0] + v[1] + v[2] + v[3];
        }

        float cross(Vector4::Vector4& rhs){
            return 0.0;
        }

        Vector4 normal(){
            Vector4::Vector4 v; 
            float norm = column[0]*column[0] + 
                         column[1]*column[1] +
                         column[2]*column[2];
            float n = sqrtf(norm); 
            return (*this)/n;
        }

        // [] can't modify member variables
        const float& operator[](int index) const{
            return column[index];
        } 

        // [] can modify member variables
        float& operator[](int index){
            return column[index];
        } 

        void print(){ 
            printf("x=[%f], y=[%f], z=[%f] w=[%f]\n", column[0], column[1], column[2], column[3]);
        }
    };
};

namespace SpaceMatrix4{
    using namespace SpaceVector4;

    class Matrix4{
        Vector4 mat[4];
        public:
        Matrix4(){
            mat[0] = mat[1] = mat[2] = mat[3] = Vector4();
        }

        // copy constructor
        Matrix4(const Matrix4& matrix){
            mat[0] = matrix[0];
            mat[1] = matrix[1];
            mat[2] = matrix[2];
            mat[3] = matrix[3];
        }
        Matrix4& operator=(const Matrix4& matrix){
            mat[0] = matrix[0];
            mat[1] = matrix[1];
            mat[2] = matrix[2];
            mat[3] = matrix[3];
            return *this;
        }

        // overload [] , const => member variables CAN NOT be modified 
        const Vector4& operator[](int index) const{
            return mat[index];
        }

        // overload [] , no const => member variables CAN be modified 
        Vector4& operator[](int index) {
            return mat[index];
        }
        Matrix4 operator+(Matrix4& rhs){
            Matrix4 m;
            m[0] = mat[0] + rhs[0];
            m[1] = mat[1] + rhs[1];
            m[2] = mat[2] + rhs[2];
            m[3] = mat[3] + rhs[3];
            return m;
        }
        Matrix4 operator-(Matrix4& rhs){
            Matrix4 m;
            m[0] = mat[0] - rhs[0];
            m[1] = mat[1] - rhs[1];
            m[2] = mat[2] - rhs[2];
            m[3] = mat[3] - rhs[3];
            return m;
        }

        // column vector
        Vector4 operator*(Vector4& vect4){
            Vector4 row0(mat[0][0], mat[1][0], mat[2][0], mat[3][0]);
            Vector4 row1(mat[0][1], mat[1][1], mat[2][1], mat[3][1]);
            Vector4 row2(mat[0][2], mat[1][2], mat[2][2], mat[3][2]);
            Vector4 row3(mat[0][3], mat[1][3], mat[2][3], mat[3][3]);
            Vector4 v(row0.dot(vect4), row1.dot(vect4), row2.dot(vect4), row3.dot(vect4));
            return v;
        }

        // column vector
        Matrix4 operator*(Matrix4& matrix){
            Matrix4 m;
            m[0] = (*this)*matrix[0];
            m[1] = (*this)*matrix[1];
            m[2] = (*this)*matrix[2];
            m[3] = (*this)*matrix[3];
            return m;
        }
        // [1, 2, 3, 0] => point at infinite 
        // [1, 2, 3, 1] => normal point
        Matrix4 translate(float x, float y, float z, float w = 0.0f){
            Matrix4 m;
            mat[0][0] = 1;
            mat[1][1] = 1;
            mat[2][2] = 1;

            mat[3][0] = x;
            mat[3][1] = y;
            mat[3][2] = z;
            mat[3][3] = w;
            return *this;
        }

        void print(){
            printf("[%f][%f][%f][%f]\n", mat[0][0], mat[1][0], mat[2][0], mat[3][0]);
            printf("[%f][%f][%f][%f]\n", mat[0][1], mat[1][1], mat[2][1], mat[3][1]);
            printf("[%f][%f][%f][%f]\n", mat[0][2], mat[1][2], mat[2][2], mat[3][2]);
            printf("[%f][%f][%f][%f]\n", mat[0][3], mat[1][3], mat[2][3], mat[3][3]);
        }
    };
};

#endif

