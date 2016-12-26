#ifndef __CAMERA__KEYBOARD__
#define __CAMERA__KEYBOARD__

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include "Camera.h" 

Camera camera;
int g_filling = 1;

void keyboard(int key, int, int) {
    switch (key) {
    case GLUT_KEY_LEFT:
        camera.moveLeft();
        break;
    case GLUT_KEY_RIGHT:
        camera.moveRight();
        break;
    case GLUT_KEY_UP:
        camera.moveUp();
        break;
    case GLUT_KEY_DOWN:
        camera.moveDown();
        break;
    case 'o':
        camera.zoomIn();
        break;
    case 'O':
        camera.zoomOut();
        break;
    case 'w':
        if (g_filling==0) {
            // Polygon rasterization mode (polygon filled)
            glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
            g_filling=1;
        } else {
            // Polygon rasterization mode (polygon outlined)
            glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
            g_filling=0;
        }
        break;
    }
    glutPostRedisplay();
}

#endif
