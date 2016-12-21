#ifndef CHECKERBOARD 
#define CHECKERBOARD 

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include "Color.h" 

// A checkerboard class.  A checkerboard has alternating red and white
// squares.  The number of squares is set in the constructor.  Each square
// is 1 x 1.  One corner of the board is (0, 0) and the board stretches out
// along positive x and positive z.  It rests on the xz plane.  I put a
// spotlight at (4, 3, 7).
class CheckerBoard {
    int displayListId;
    int width;
    int depth;
    GLfloat WHITE[3]   = {1, 1, 1};
    GLfloat RED[3]     = {1, 0, 0};
    GLfloat GREEN[3]   = {0, 1, 0};
    GLfloat MAGENTA[3] = {1, 0, 1};
    GLfloat color0[3]  = {1, 0, 0};
    GLfloat color1[3]  = {0, 1, 0};
public:
    CheckerBoard(int width, int depth): width(width), depth(depth) {}
    double centerx() {
        return width / 2;
    }
    double centerz() {
        return depth / 2;
    }
    void setColor(GLfloat c0[3], GLfloat c1[3]){
        memcpy(color0, c0, 3*sizeof(GLfloat));    
        memcpy(color1, c1, 3*sizeof(GLfloat));    
    }
    void create() {
        displayListId = glGenLists(1);
        glNewList(displayListId, GL_COMPILE);
        GLfloat lightPosition[] = {4, 3, 7, 1};
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        glBegin(GL_QUADS);
        glNormal3d(0, 1, 0);
        for (int x = -width; x < width - 1; x++) {
            for (int z = -z; z < depth - 1; z++) {
                glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE,
                             (x + z) % 2 == 0 ? color0: color1);
                glVertex3d(x, 0, z);
                glVertex3d(x+1, 0, z);
                glVertex3d(x+1, 0, z+1);
                glVertex3d(x, 0, z+1);
            }
        }
        glEnd();
        glEndList();
    }
    void draw() {
        glCallList(displayListId);
    }
};

#endif

