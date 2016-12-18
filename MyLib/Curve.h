#ifndef CURVE 
#define CURVE 

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

#include "BezierCurve.h"
#include "Utility.h"

// simple beizer curve
class Curve{
    Vector3 p0;
    Vector3 p1;
    Vector3 p2;
    GLfloat WHITE[3] = {1, 1, 1}; // C++11
    GLfloat RED[3] = {1, 0, 0};
    DDLinkedList<Vector3>* ddl;
    public:
    Curve(){
        p0 = Vector3(-1, 1, 0);
        p1 = Vector3(0, 1, 0);
        p2 = Vector3(1, 1, 0);
        ddl = new DDLinkedList<Vector3>();
        int level = 3;
        beziercurve(p0, p1, p2, ddl, level);
    }
    void draw(){
        glBegin(GL_LINE_STRIP);
        glNormal3d(0, 1, 0);
        int c = 0;
        Node<Vector3>* curr = ddl->head;
        while(curr) {
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, c % 2 == 0 ? RED : WHITE);
            Vector3 v = curr->data;
            glVertex3d(v.v[0], v.v[1], v.v[2]);
            c++;
            curr = curr->next;
        }
        glEnd();
    }
};

#endif
