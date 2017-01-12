#ifndef CYLINDER 
#define CYLINDER 

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include <cstring>
#include <cstdio>

class Cylinder{
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
    double z;
    double radius;
    double beta = 0.0;

    // default color
    GLfloat color0[3]  = {1, 0, 0};
    GLfloat color1[3]  = {0, 1, 0};

    public: 
    Cylinder(double cx, double cy, double depth){
        twopi = 2 * (double)M_PI;
        this->cx = cx;
        this->cy = cy;
        numc = 10;
        radius = 2;
        beta = twopi/numc;
        z = depth;
    }
    Cylinder(double cx, double cy, double depth, double radius, int numc){
        twopi = 2 * (double)M_PI;
        this->cx = cx;
        this->cy = cy;
        this->numc = numc;
        this->radius = radius;
        this->beta = twopi/numc;
        z = depth;
    }
    Cylinder(double cx, double cy, double radius, int numc){
        twopi = 2 * (double)M_PI;
        this->numc = numc;
        this->cx = cx;
        this->cy = cy;
        numc = 10;
        this->radius = radius;
        beta = twopi/this->numc;
        z = 4;
    }
    void setColor(GLfloat c0[3], GLfloat c1[3]){
        memcpy(color0, c0, 3*sizeof(GLfloat));    
        memcpy(color1, c1, 3*sizeof(GLfloat));    
    }
    void lighting(){
        glEnable(GL_DEPTH_TEST);
        glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
        glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
        glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE);
        glMaterialf(GL_FRONT, GL_SHININESS, 30);
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
    }
    void draw(){
        lighting();
        GLfloat lightPosition[] = {4, 3, 7, 1};
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        glBegin(GL_QUAD_STRIP);
        glNormal3d(0, 1, 0);

        for (int i = 0; i <= numc; i++) {
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,
                         i % 2 == 0 ? color0 : color1);
            x = radius*cos(beta*i);   
            y = radius*sin(beta*i);   

            glVertex3f(x + cx, y + cy, -z);
            glVertex3f(x + cx, y + cy, z);
        }
        glEnd();
    }
};

#endif
