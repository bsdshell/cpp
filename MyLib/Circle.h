#ifndef CIRCLE 
#define CIRCLE 

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

class Circle{
    GLfloat WHITE[3] = {1, 1, 1};
    GLfloat RED[3] = {1, 0, 0};
    GLfloat GREEN[3] = {0, 1, 0};
    GLfloat MAGENTA[3] = {1, 0, 1};
    int numc;
    double twopi;
    double cx;
    double cy;
    double x;
    double y;
    double radius;
    double beta = 0.0;
    public: 
    Circle(double cx, double cy){
        twopi = 2 * (double)M_PI;
        this->cx = cx;
        this->cy = cy;
        numc = 10;
        radius = 2;
        beta = twopi/numc;
    }

    Circle(double cx, double cy, int numc){
        twopi = 2 * (double)M_PI;
        this->numc = numc;
        this->cx = cx;
        this->cy = cy;
        numc = 10;
        radius = 2;
        beta = twopi/this->numc;
    }

    Circle(double cx, double cy, double radius, int numc){
        twopi = 2 * (double)M_PI;
        this->numc = numc;
        this->cx = cx;
        this->cy = cy;
        numc = 10;
        this->radius = radius;
        beta = twopi/this->numc;
    }
    void draw(){
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

#endif
