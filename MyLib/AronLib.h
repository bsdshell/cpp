#ifndef __AronLib__
#define __AronLib__

#include <execinfo.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <cmath>
#include "Vector3.h"
#include "DDLinkedList.h"
#include "Const.h"

#define PAD "--------------------------------------------------------------------------------"
using namespace std;

const string S_RED = "\033[1;31m";
const string S_END = "\033[0m";


//cout << "\033[1;31mbold red text\033[0m\n";

namespace SpaceTest {
template<class T> class Test {
public:
    Test() { }
    bool t(T a, T b) {
        color(a == b);
    }
    bool t(double a, double b){
        double epsilon = 0.00001;
        return fabs(a - b) < epsilon;
    }
    Test(const Test& other) {}
    bool f(T a, T b) {
        color(!(a == b));
    }
    bool f(bool b) {
        color(b);
    }
    void color(bool b) {
        if(b)
            cout<<"["<<"true"<<"]"<<endl;
        else
            cout<<S_RED + "["<<"false"<<"]" + S_END<<endl;
    }
};
};

// quick sort
namespace SpaceSort {
void swap(int array[], int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

// quick sort partition
int partition(int array[], int lo, int hi) {
    if(hi > lo) {
        int p = array[hi];
        int big = lo;
        for(int i=lo; i<=hi; i++) {
            if(array[i] <= p)     {
                swap(array, i, big);
                if(i < hi)
                    big++;
            }
        }
        return big;
    }
    return -1;
}

void quickSort(int array[], int lo, int hi) {
    if(hi > lo) {
        int pivot = partition(array, lo, hi);
        quickSort(array, lo, pivot-1);
        quickSort(array, pivot+1, hi);
    }
  }
}

namespace Utility {
void fl();
string fun_parent_parent();
void cut(char* pt);
void pp(const char* format, ...);

void begin() {
    int sz = 80;
    std::string pretty_fun = fun_parent_parent();
    int len = pretty_fun.length();
    printf ("[%s%.*s]\n", pretty_fun.c_str(), sz < len ? 0 : (int)(sz - len), PAD);
}

void begin(const char* name) {
    int sz = 80;
    printf ("[%s%.*s]\n", name, (sz < strlen(name)) ? 0 : (int)(sz - strlen(name)), PAD);
}

void end() {
    fl();
}

void fl() {
    printf("[%s]\n", PAD);
}


void cut(char* pt) {
    int k = strlen(pt) - 1;
    while(k >= 0 && pt[k] != 'v') k--;

    k >= 0 ? pt[k] = 0 : printf("Error: invalid string format.");
}

// get the name of parent function, get the name of caller function
string fun_parent() {
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
string fun_parent_parent() {
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

void pp(const char* format, ...) {
    printf(format);
}

void pp(int n) {
    printf("[%d]", n);
}

void pp(float n) {
    printf("[%f]", n);
}

void print(Vector3::Vector3 v) {
    v.print();
}

void print(DDLinkedList<Vector3>* ddl) {
    Node<Vector3>* curr = ddl->head;
    while(curr) {
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

void printFormatNew(GLfloat x, GLfloat y, char* buffer) {
    glMatrixMode( GL_PROJECTION );
    glPushMatrix();
    glLoadIdentity();

    // l          r
    // ------------ up
    // |          |
    // |          |
    // ------------ bottom
    //
    // left, right, bottom, up
    gluOrtho2D( 0, 1280, 0, 1024 );

    glMatrixMode( GL_MODELVIEW );
    glPushMatrix();
    glLoadIdentity();
    glRasterPos2i(x, y);

    for ( int i = 0; i < strlen(buffer); i++) {
        //glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, buffer[i]);
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, buffer[i]);
    }

    glPopMatrix();
    glMatrixMode( GL_PROJECTION );
    glPopMatrix();
    glMatrixMode( GL_MODELVIEW );
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
void getModelViewMatrix(float matrix[16]) {
    glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
    fprintf(stderr, "[%s]\n", "Algebra Matrix Form");
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            // OpenGL use column-major instead of row-major
            fprintf(stderr, "[%f]", matrix[4*j+i]);
        }
        fprintf(stderr, "%s", "\n");
    }
    fprintf(stderr, "%s", "\n");
}
};


namespace SpaceDraw {
class Cube {
public:
    float x = 1.0f;
    float y;
    float z;
    float r;

    GLfloat vertices[108] = { 1, 1, 1,  -1, 1, 1,  -1,-1, 1,      // v0-v1-v2 (front)
                              -1,-1, 1,   1,-1, 1,   1, 1, 1,      // v2-v3-v0

                              1, 1, 1,   1,-1, 1,   1,-1,-1,      // v0-v3-v4 (right)
                              1,-1,-1,   1, 1,-1,   1, 1, 1,      // v4-v5-v0

                              1, 1, 1,   1, 1,-1,  -1, 1,-1,      // v0-v5-v6 (top)
                              -1, 1,-1,  -1, 1, 1,   1, 1, 1,      // v6-v1-v0

                              -1, 1, 1,  -1, 1,-1,  -1,-1,-1,      // v1-v6-v7 (left)
                              -1,-1,-1,  -1,-1, 1,  -1, 1, 1,      // v7-v2-v1

                              -1,-1,-1,   1,-1,-1,   1,-1, 1,      // v7-v4-v3 (bottom)
                              1,-1, 1,  -1,-1, 1,  -1,-1,-1,      // v3-v2-v7

                              1,-1,-1,  -1,-1,-1,  -1, 1,-1,      // v4-v7-v6 (back)
                              -1, 1,-1,   1, 1,-1,   1,-1,-1
                            };    // v6-v5-v4

    Cube() {
    }
    Cube(float x1, float y1, float z1, float r1=1.0) {
        x = x1;
        y = y1;
        z = z1;
        r = r1;
    }

    void draw() {
        glEnable(GL_DEPTH_TEST);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
        glLightfv(GL_LIGHT0, GL_SPECULAR, RED);
        glMaterialfv(GL_FRONT, GL_SPECULAR, MAGENTA);
        glMaterialf(GL_FRONT, GL_SHININESS, 10);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);

        GLfloat lightPosition[] = {4, 3, 7, 1};
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        glNormal3d(0, 1, 0);
        // enble and specify pointers to vertex arrays
        glEnableClientState(GL_VERTEX_ARRAY);
        glVertexPointer(3, GL_FLOAT, 0, vertices);
        glPushMatrix();
        glDrawArrays(GL_TRIANGLES, 0, 36);

        glPopMatrix();
        glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
    }
};  // end class Clube

class SimpleCoordinate {
public:
    SimpleCoordinate() {
    }
public:
    void draw(float width = 1.0, int num=10) {
        glBegin(GL_LINES);
        float delta = width/num;
        glColor3f(0.0f, width, 0.0f);
        for(int i=-num; i<=num; i++) {
            glVertex3f(-width, 0.0f, delta*i);
            glVertex3f(width, 0.0f,  delta*i);
        }

        glColor3f(0.3f,0.7f,0.0f);
        for(int i=-num; i<=num; i++) {
            glVertex3f(-width, delta*i,  0.0f);
            glVertex3f(width,  delta*i,  0.0f);
        }

        glColor3f(width, 0.0f,0.0f);
        for(int i=-num; i<=num; i++) {
            glVertex3f(0.0f, -width, delta*i);
            glVertex3f(0.0f, width,  delta*i);
        }

        glColor3f(0.4f, 0.4f,0.1f);
        for(int i=-num; i<=num; i++) {
            glVertex3f(delta*i, -width, 0.0f);
            glVertex3f(delta*i, width,  0.0f);
        }

        glColor3f(0.0f, 0.0f, width);
        for(int i=-num; i<=num; i++) {
            glVertex3f(delta*i, 0.0f, -width);
            glVertex3f(delta*i, 0.0f, width);
        }

        glColor3f(0.0f, 0.5f, 0.5f);
        for(int i=-num; i<=num; i++) {
            glVertex3f(0.0f, delta*i, -width);
            glVertex3f(0.0f, delta*i, width);
        }
        glEnd();
    }

}; // end class SimpleCoordinate

class Plane {
public:
    float x;
    float y;
    Plane(int x_ = 1.0f, int y_ = 1.0f) {
        x = x_;
        y = y_;
    }
    // draw x-y plane
    void draw() {
        float alpha = 0.5;
        glBegin(GL_QUADS);
        glColor4f(x, 0.0, 0.0, alpha);
        glVertex3f(-x, +y, 0.0); // top left

        glColor4f(0.0, y, 0.0, alpha);
        glVertex3f(-x, -y, 0.0); // bottom left

        glColor4f(0.0, 0.0, 1.0, alpha);
        glVertex3f(+x, -y, 0.0); // bottom right

        glColor4f(0.0, y, 1.0, alpha);
        glVertex3f(+x, +y, 0.0); // top right
        glEnd();
    }
}; // end class Plane

class Circle {
    int numc;
    double twopi;
    double cx;
    double cy;
    double x;
    double y;
    double radius;
    double beta = 0.0;
public:
    Circle(double cx, double cy) {
        twopi = 2 * (double)M_PI;
        this->cx = cx;
        this->cy = cy;
        numc = 10;
        radius = 2;
        beta = twopi/numc;
    }

    Circle(double cx, double cy, int numc) {
        twopi = 2 * (double)M_PI;
        this->numc = numc;
        this->cx = cx;
        this->cy = cy;
        numc = 10;
        radius = 2;
        beta = twopi/this->numc;
    }

    Circle(double cx, double cy, double radius, int numc) {
        twopi = 2 * (double)M_PI;
        this->numc = numc;
        this->cx = cx;
        this->cy = cy;
        numc = 10;
        this->radius = radius;
        beta = twopi/this->numc;
    }
    void move(double mx, double my, double mz) {
        cx = mx;
        cy = my;
    }
    void draw() {
        GLfloat lightPosition[] = {4, 3, 7, 1};
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        glBegin(GL_LINE_STRIP);
        glNormal3d(0, 1, 0);

        for (int i = 0; i <= numc; i++) {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,
                         i % 2 == 0 ? GREEN : MAGENTA);
            x = radius*cos(beta*i);
            y = radius*sin(beta*i);
            glVertex3f(x + cx, y + cy, 0);
        }
        glEnd();
    }
};
}; // end namespace PlaneSpaceDraw


namespace SpaceLog {
class Logging {
public:
    ofstream log;
public:
    Logging() {
        log.open ("/Users/cat/myfile/github/cpp/text/file1.txt");
    }
    void close() {
        log.close();
    }
    ~Logging() {
        log.close();
    }
};
};

namespace SpaceComplex{
    class Complex{
    public:
        double x;
        double y;

            Complex(){
                x = 0.0;
                y = 0.0;
            }
            Complex(double x_, double y_){
                x = x_;
                y = y_;
            }
            Complex operator+(Complex& c){
                Complex co;
                co.x = x + c.x;
                co.y = y + c.y;
                return co;
            }
            Complex operator-(Complex& c){
                Complex co;
                co.x = x - c.x;
                co.y = y - c.y;
                return co;
            }
            void print() {
                printf("[%1.2f][%1.2f]\n", x, y);
            }
    };
};


namespace SpaceVector4 {
class Vector4 {
    float column[4];
public:
    const float e1[4] = {1.0f, 0.0f, 0.0f, 0.0f};
    const float e2[4] = {0.0f, 1.0f, 0.0f, 0.0f};
    const float e3[4] = {0.0f, 0.0f, 1.0f, 0.0f};
    const float e4[4] = {0.0f, 0.0f, 0.0f, 1.0f};
public:
    Vector4() {
        column[0] = column[1] = column[2] = column[3] = 0.0f;
    }
    Vector4(const Vector4& other) {
        this->column[0] = other.column[0];
        this->column[1] = other.column[1];
        this->column[2] = other.column[2];
        this->column[3] = other.column[3];
    }

    Vector4(float x, float y, float z, float w = 1.0f) {
        this->column[0] = x;
        this->column[1] = y;
        this->column[2] = z;
        this->column[3] = w;
    }
    Vector4(const float arr[4]) {
        this->column[0] = arr[0];
        this->column[1] = arr[1];
        this->column[2] = arr[2];
        this->column[3] = arr[3];
    }
    Vector4(float arr[4]) {
        this->column[0] = arr[0];
        this->column[1] = arr[1];
        this->column[2] = arr[2];
        this->column[3] = arr[3];
    }
    bool operator==(const Vector4& rhs) {
        bool b0 = column[0] == rhs.column[0];
        bool b1 = column[1] == rhs.column[1];
        bool b2 = column[2] == rhs.column[2];
        bool b3 = column[3] == rhs.column[3];
        return (b0 && b1 && b2 && b3);
    }
    Vector4& operator=(const Vector4& rhs) {
        this->column[0] = rhs.column[0];
        this->column[1] = rhs.column[1];
        this->column[2] = rhs.column[2];
        this->column[3] = rhs.column[3];
        return *this;
    }

    Vector4 operator+(Vector4& rhs) {
        Vector4 v;
        v.column[0] = this->column[0] + rhs.column[0];
        v.column[1] = this->column[1] + rhs.column[1];
        v.column[2] = this->column[2] + rhs.column[2];
        v.column[3] = 0.0f;
        return v;
    }

    Vector4 operator-(Vector4& rhs) {
        Vector4 v;
        v.column[0] = this->column[0] - rhs.column[0];
        v.column[1] = this->column[1] - rhs.column[1];
        v.column[2] = this->column[2] - rhs.column[2];
        v.column[3] = 0.0f;
        return v;
    }

    Vector4 operator/(float n) {
        Vector4 v;
        v.column[0] = column[0]/n;
        v.column[1] = column[1]/n;
        v.column[2] = column[2]/n;
        return v;
    }

    float dot(Vector4& rhs) {
        Vector4 v;
        v.column[0] = column[0] * rhs.column[0];
        v.column[1] = column[1] * rhs.column[1];
        v.column[2] = column[2] * rhs.column[2];
        v.column[3] = column[3] * rhs.column[3];
        return v[0] + v[1] + v[2] + v[3];
    }

    float cross(Vector4::Vector4& rhs) {
        return 0.0;
    }

    Vector4 normal() {
        Vector4::Vector4 v;
        float norm = column[0]*column[0] +
                     column[1]*column[1] +
                     column[2]*column[2];
        float n = sqrtf(norm);
        return (*this)/n;
    }

    // [] can't modify member variables
    const float& operator[](int index) const {
        return column[index];
    }

    // [] can modify member variables
    float& operator[](int index) {
        return column[index];
    }

    void pp() {
        print();
    }
    void print() {
        printf("x=[%1.2f]\ny=[%1.2f]\nz=[%1.2f]\nw=[%1.2f]\n\n", column[0], column[1], column[2], column[3]);
    }
};
};

namespace SpaceMatrix4 {
using namespace SpaceVector4;
using namespace Utility;

class Matrix4 {
    Vector4 mat[4];
public:
    Matrix4() {
        mat[0] = mat[1] = mat[2] = mat[3] = Vector4();
    }

    // copy constructor
    Matrix4(const Matrix4& matrix) {
        mat[0] = matrix[0];
        mat[1] = matrix[1];
        mat[2] = matrix[2];
        mat[3] = matrix[3];
    }

    Matrix4(Vector4 v0, Vector4 v1, Vector4 v2, Vector4 v3) {
        mat[0] = v0;
        mat[1] = v1;
        mat[2] = v2;
        mat[3] = v3;
    }
    Matrix4(float m[16]) {
        Vector4 v1({ m[0],   m[1],   m[2],   m[3]});
        Vector4 v2({ m[4],   m[5],   m[6],   m[7]});
        Vector4 v3({ m[8],   m[9],   m[10],  m[11]});
        Vector4 v4({ m[12],  m[13],  m[14],  m[15]});
        mat[0] = v1;
        mat[1] = v2;
        mat[2] = v3;
        mat[3] = v4;
    }
    Matrix4& operator=(const Matrix4& matrix) {
        mat[0] = matrix[0];
        mat[1] = matrix[1];
        mat[2] = matrix[2];
        mat[3] = matrix[3];
        return *this;
    }

    bool operator==(const Matrix4& matrix) {
        bool b0 = mat[0] == matrix[0];
        bool b1 = mat[1] == matrix[1];
        bool b2 = mat[2] == matrix[2];
        bool b3 = mat[3] == matrix[3];
        return (b0 && b1 && b2 && b3);
    }
    // overload [] , const => member variables CAN NOT be modified
    const Vector4& operator[](int index) const {
        return mat[index];
    }

    // overload [] , no const => member variables CAN be modified
    Vector4& operator[](int index) {
        return mat[index];
    }
    Matrix4 operator+(Matrix4& rhs) {
        Matrix4 m;
        m[0] = mat[0] + rhs[0];
        m[1] = mat[1] + rhs[1];
        m[2] = mat[2] + rhs[2];
        m[3] = mat[3] + rhs[3];
        return m;
    }
    Matrix4 operator-(Matrix4& rhs) {
        Matrix4 m;
        m[0] = mat[0] - rhs[0];
        m[1] = mat[1] - rhs[1];
        m[2] = mat[2] - rhs[2];
        m[3] = mat[3] - rhs[3];
        return m;
    }

    // column vector
    Vector4 operator*(Vector4& vect4) {
        Vector4 row0(mat[0][0], mat[1][0], mat[2][0], mat[3][0]);
        Vector4 row1(mat[0][1], mat[1][1], mat[2][1], mat[3][1]);
        Vector4 row2(mat[0][2], mat[1][2], mat[2][2], mat[3][2]);
        Vector4 row3(mat[0][3], mat[1][3], mat[2][3], mat[3][3]);

        row0.print();
        row1.print();
        row2.print();
        row3.print();

        vect4.print();
        cout<<"["<<row0.dot(vect4)<<"]"<<endl;
        cout<<"["<<row1.dot(vect4)<<"]"<<endl;
        cout<<"["<<row2.dot(vect4)<<"]"<<endl;
        cout<<"["<<row3.dot(vect4)<<"]"<<endl;

        Vector4 v(row0.dot(vect4), row1.dot(vect4), row2.dot(vect4), row3.dot(vect4));
        v.print();
        return v;
    }

    // column vector
    Matrix4 operator*(Matrix4& matrix) {
        Matrix4 m;
        m[0] = (*this)*matrix[0];
        m[1] = (*this)*matrix[1];
        m[2] = (*this)*matrix[2];
        m[3] = (*this)*matrix[3];
        return m;
    }
    // [1, 2, 3, 0] => point at infinite
    // [1, 2, 3, 1] => normal point
    Matrix4 translate(float x, float y, float z) {
        Matrix4 m;
        mat[0][0] = 1;
        mat[1][1] = 1;
        mat[2][2] = 1;
        mat[3][3] = 1;

        mat[3][0] = x;
        mat[3][1] = y;
        mat[3][2] = z;
        mat[3][3] = 1;
        return *this;
    }
    Matrix4 identity() {
        mat[0][0] = 1;
        mat[1][1] = 1;
        mat[2][2] = 1;
        mat[3][3] = 1;
        return *this;
    }

    void pp() {
        print();
    }
    void print() {
        printf("[%1.2f][%1.2f][%1.2f][%1.2f]\n", mat[0][0], mat[1][0], mat[2][0], mat[3][0]);
        printf("[%1.2f][%1.2f][%1.2f][%1.2f]\n", mat[0][1], mat[1][1], mat[2][1], mat[3][1]);
        printf("[%1.2f][%1.2f][%1.2f][%1.2f]\n", mat[0][2], mat[1][2], mat[2][2], mat[3][2]);
        printf("[%1.2f][%1.2f][%1.2f][%1.2f]\n", mat[0][3], mat[1][3], mat[2][3], mat[3][3]);
        fl();
    }
};
};


#endif

