#ifndef DRAWQUAD 
#define DRAWQUAD 

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

class DrawQuad{
    GLfloat WHITE[3] = {1, 1, 1};
    GLfloat RED[3] = {1, 0, 0};
    GLfloat GREEN[3] = {0, 1, 0};
    GLfloat MAGENTA[3] = {1, 0, 1};
    double beta = 0.0;
    public: 
    DrawQuad(){
    }
    void draw(){
        GLfloat lightPosition[] = {4, 3, 7, 1};
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        glBegin(GL_QUAD_STRIP);
        glNormal3d(0, 1, 0);

        glVertex3f(0, 0, 0);
        glVertex3f(0, 1, 0);
        glVertex3f(1, 0, 0);
        glVertex3f(1, 1, 0);
        glEnd();
    }
};

#endif
