#ifndef TORUS 
#define TORUS 

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

class Torus{
    GLfloat WHITE[3] = {1, 1, 1};
    GLfloat RED[3] = {1, 0, 0};
    GLfloat GREEN[3] = {0, 1, 0};
    GLfloat MAGENTA[3] = {1, 0, 1};
    int i, j, k;
    double s, t, x, y, z, twopi;
    int numc;
    int numt;
    double cx;
    double cy;
    double cz;
    double r = 0.3;
    double R = 1;

    public:
    Torus(int numc, int numt){
        twopi = 2 * (double)M_PI;
        this->numc = numc;
        this->numt = numt;
        cx = 0.0f;
        cy = 0.0f;
        cz = 0.0f;
    }
    Torus(int cx, int cy, int cz, int numc, int numt){
        twopi = 2 * (double)M_PI;
        this->numc = numc;
        this->numt = numt;
        this->cx = cx;
        this->cy = cy;
        this->cz = cz;
    }
    void draw(){
        GLfloat lightPosition[] = {4, 3, 7, 1};
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        glBegin(GL_QUAD_STRIP);

        glNormal3d(0, 1, 0);
        for (i = 0; i < numc; i++) {
            for (j = 0; j <= numt; j++) {
                for (k = 1; k >= 0; k--) {
                    s = (i + k) % numc + 0.5;
                    t = j % numt;
                    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,
                                 (i + j) % 2 == 0 ? GREEN : MAGENTA);

                    x = (R+r*cos(s*twopi/numc))*cos(t*twopi/numt) + cx;
                    y = (R+r*cos(s*twopi/numc))*sin(t*twopi/numt) + cy;
                    z = r * sin(s * twopi / numc) + cz;
                    glVertex3f(x, y, z);
                }
            }
        }
        glEnd();
    }
};

#endif

