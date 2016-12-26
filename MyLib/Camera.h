#ifndef __CAMERA__ 
#define __CAMERA__ 

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>


// A camera.  It moves horizontally in a circle centered at the origin of
// radius 10.  It moves vertically straight up and down.
class Camera {
    double theta;      // determines the x and z positions
    double y;          // the current y position
    double dTheta;     // increment in theta for swinging the camera around
    double dy;         // increment in y for moving the camera up/down
    double r;
public:
    Camera(): theta(-1.2), y(3), dTheta(0.04), dy(0.2), r(6){}
    double getX() {
        return r * cos(theta);
    }
    double getY() {
        return y;
    }
    double getZ() {
        return r * sin(theta);
    }
    void moveRight() {
        theta += dTheta;
    }
    void moveLeft() {
        theta -= dTheta;
    }
    void moveUp() {
        y += dy;
    }
    void moveDown() {
        //if (y > dy) y -= dy;
        y -= dy;
    }
    void zoomIn() {
        //if (y > dy) y -= dy;
        r += -0.2;
    }
    void zoomOut() {
        //if (y > dy) y -= dy;
        r += 0.2;
    }
};

#endif
