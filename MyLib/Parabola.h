#ifndef __PARABOLA__ 
#define __PARABOLA__ 

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include "Color.h" 

class Parabola{
    public:
    GLfloat WHITE[3]   = {1, 1, 1};
    GLfloat RED[3]     = {1, 0, 0};
    GLfloat GREEN[3]   = {0, 1, 0};
    GLfloat MAGENTA[3] = {1, 0, 1};

    GLfloat x0 = 0.0;
    GLfloat y0 = 0.0;
    GLfloat z0 = 0.0;

    GLfloat x1 = 0.0;
    GLfloat y1 = 0.0;
    GLfloat z1 = 0.0;

    GLfloat cx = 0.0;
    GLfloat cy = 0.0;
    GLfloat cz = 0.0;

    Parabola(){
        cx = 0.0;
        cy = 0.0;
        cz = 0.0;
    }
    Parabola(GLfloat cx, GLfloat cy, GLfloat cz){
        this->cx = cx;    
        this->cy = cy;
        this->cz = cz;
    }
    void init(){
        GLfloat lightPosition[] = {0, 2, 0, 1};
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        glNormal3d(0, 1, 0);
        glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
    }
    void draw(){
        init();

        int len = 20;
        GLfloat dr = (GLfloat)1/len;
        GLfloat delta = (GLfloat)2*M_PI/len;

        glBegin(GL_QUAD_STRIP); //starts drawing of points
        for(int j=0; j<len; j++){
            if(j % 2 == 0)
                glColor3f(1.0f,0.0f,0.0f); // point color
            else
                glColor3f(0.0f,1.0f,0.0f); // point color

            GLfloat rq = dr*j;
            GLfloat rq1 = dr*(j + 1);
            for(int i=0; i<=len; i++){
                x0 = rq*sin(delta*i) + cx;
                y0 = rq*rq + cy;
                z0 = rq*cos(delta*i) + cz; 

                x1 = rq1*sin(delta*i) + cx;
                y1 = rq1*rq1 + cy;
                z1 = rq1*cos(delta*i) + cz; 

                glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,
                             (i + j) % 2 == 0 ? GREEN : MAGENTA);
                glMaterialf(GL_FRONT, GL_SHININESS, 40);
                glVertex3f(x0, y0, z0);
                glVertex3f(x1, y1, z1);
            } 
        } 
        glEnd();
    }
};


#endif
