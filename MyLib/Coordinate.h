#ifndef COORDINATE 
#define COORDINATE 

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include "Cylinder.h"
#include "Color.h"

class Coordinate{
    GLfloat WHITE[3] = {1, 1, 1};
    GLfloat RED[3] = {1, 0, 0};
    GLfloat GREEN[3] = {0, 1, 0};
    GLfloat MAGENTA[3] = {1, 0, 1};

    Cylinder* col;
    Cylinder* co2;
    Cylinder* co3;
    double width;
    double radius;
    int nstep;
    public: 
    Coordinate(){
        nstep = 20;
        double radius = 0.1;
        width = 6.0;
        col = new Cylinder(0.0, 0.0, width, radius, nstep);
        co2 = new Cylinder(0.0, 0.0, width, radius, nstep);
        co3 = new Cylinder(0.0, 0.0, width, radius, nstep);
    }
    Coordinate(double width){
        nstep = 20;
        double radius = 0.1;
        this->width = width;
        col = new Cylinder(0.0, 0.0, this->width, radius, nstep);
        co2 = new Cylinder(0.0, 0.0, this->width, radius, nstep);
        co3 = new Cylinder(0.0, 0.0, this->width, radius, nstep);
    }
    Coordinate(double width, double radius){
        nstep = 20;
        this->radius = radius;
        this->width = width;
        col = new Cylinder(0.0, 0.0, this->width, this->radius, nstep);
        co2 = new Cylinder(0.0, 0.0, this->width, this->radius, nstep);
        co3 = new Cylinder(0.0, 0.0, this->width, this->radius, nstep);
    }
    Coordinate(double width, double radius, int nstep){
        this->nstep = nstep;
        this->radius = radius;
        this->width = width;
        col = new Cylinder(0.0, 0.0, this->width, this->radius, this->nstep);
        co2 = new Cylinder(0.0, 0.0, this->width, this->radius, this->nstep);
        co3 = new Cylinder(0.0, 0.0, this->width, this->radius, this->nstep);
    }
    void draw(){
        col->setColor(GREEN, WHITE); 
        col->draw();
        glRotatef(90, 1.0, 0.0, 0.0);
        co2->setColor(RED, WHITE); 
        co2->draw();
        glRotatef(90, 0.0, 1.0, 0.0);
        co3->setColor(MAGENTA, WHITE); 
        co3->draw();
    }
    ~Coordinate(){
        delete col; 
        delete co2; 
        delete co3; 
    }
};

#endif
