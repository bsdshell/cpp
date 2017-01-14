#ifndef __CAMERA__ 
#define __CAMERA__ 

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

using namespace Utility;

// A camera.  It moves horizontally in a circle centered at the origin of
// radius 10.  It moves vertically straight up and down.
class Camera {
    double theta;      // determines the x and z positions
    double alpha;     // increment in theta for swinging the camera around
    double dTheta;     // increment in theta for swinging the camera around
    double dAlpha;     // increment in theta for swinging the camera around
    double dy;         // increment in y for moving the camera up/down
    double r;
    double x;
    double y;
    double z;
public:
    Camera(): theta(0.0), dTheta(0.04), dy(0.2), r(6), alpha(0.0), dAlpha(0.04){}
    double getX() {
        return r * cos(theta)*cos(alpha);
    }
    void setTheta(double theta1){
        theta = theta1;
    }
    void setAlpha(double alpha1){
        alpha = alpha1;
    }
    double getRadius(){
        return r;
    }
    double getAlpha(){
        return alpha;
    }
    double getTheta(){
        return theta;
    }
    double getY() {
        return r*sin(alpha);
    }
    double getZ() {
        return r * sin(theta)*cos(alpha);
    }
    void moveRight() {
        theta += dTheta;
    }
    void moveLeft() {
        theta -= dTheta;
    }
    void moveUp() {
        alpha += dAlpha;
    }
    void moveDown() {
        alpha -= dAlpha;
    }
    void zoomIn() {
        r += -0.2;
    }
    void zoomOut() {
        r += 0.2;
    }
    void print(double posx, double posy){
        char buffer[200];
        sprintf(buffer, "[%f][%f][%f] alpha[%f] theta[%f] r[%f]", getX(), getY(), getZ(), getAlpha(), getTheta(), getRadius());
        printFormatNew(posx, posy, buffer); 
    }
};

#endif
