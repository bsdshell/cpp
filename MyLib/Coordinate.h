#ifndef COORDINATE 
#define COORDINATE 

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include "Cylinder.h"

class Coordinate{
    Cylinder* col;
    Cylinder* co2;
    Cylinder* co3;
    public: 
    Coordinate(){
        int step = 20;
        double radius = 0.1
        col = new Cylinder(0.0, 0.0, 6.0, radius, steps);
        co2 = new Cylinder(0.0, 0.0, 6.0, radius, steps);
        co3 = new Cylinder(0.0, 0.0, 6.0, radius, steps);
    }
    void draw(){
        col->draw();
        glRotatef(90, 1.0, 0.0, 0.0);
        col->draw();
        glRotatef(90, 0.0, 1.0, 0.0);
        col->draw();
    }
    ~Coordinate(){
        delete col; 
        delete co2; 
        delete co3; 
    }
};

#endif
