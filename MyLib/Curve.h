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
#include "Vector3.h"
#include "Const.h"

// three or four bezier curve 
class Curve{
    Vector3 p0;
    Vector3 p1;
    Vector3 p2;
    Vector3 p3;
    Vector3 arr[4];
    int level;
    DDLinkedList<Vector3>* ddl = new DDLinkedList<Vector3>();

    private: int numPoints = 3;
    public: Curve(){
        numPoints = 3;
        p0 = Vector3(-1, 1, 0);
        p1 = Vector3(0, 1, 0);
        p2 = Vector3(1, 1, 0);
        arr[0] = p0;
        arr[1] = p1;
        arr[2] = p2;
        toArray(p0, p1, p2);
        this->level = 3;
        beziercurve(arr[0], arr[1], arr[2], ddl, this->level);
    }
    Curve(Vector3 p0, Vector3 p1, Vector3 p2, int level=3){
        numPoints = 3;
        toArray(p0, p1, p2);
        this->level = level;
        beziercurve(arr[0], arr[1], arr[2], ddl, level);
    }
    Curve(Vector3 p0, Vector3 p1, Vector3 p2, Vector3 p3, int level=3) {
        numPoints = 4;
        toArray(p0, p1, p2, p3);
        this->level = level;
        beziercurve4(arr[0], arr[1], arr[2], arr[3], ddl, this->level);
    }
    void draw(){
        init();
        drawControlPoints();
        drawCurve();
    }

    private:
    void toArray(Vector3 p0, Vector3 p1, Vector3 p2, Vector3 p3 = Vector3(0.0, 0.0, 0.0)){
        arr[0] = p0;
        arr[1] = p1;
        arr[2] = p2;
        arr[3] = p3;
    }
    private:
    void init(){
        glNormal3d(0, 1, 0);
    }
    private:
    void drawCurve(){
        int c = 0;
        glBegin(GL_LINE_STRIP);
        Node<Vector3>* curr = ddl->head;
        while(curr) {
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, c % 2 == 0 ? RED : MAGENTA);
            Vector3 v = curr->data;
            glVertex3d(v.v[0], v.v[1], v.v[2]);
            c++;
            curr = curr->next;
        }
        glEnd();
    }
    private:
    void drawControlPoints(){
        glBegin(GL_LINE_STRIP);
            glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, WHITE);
            for(int i=0; i<numPoints; i++){
                glVertex3d(arr[i].v[0], arr[i].v[1], arr[i].v[2]);
            } 
        glEnd();
    }
};

#endif
