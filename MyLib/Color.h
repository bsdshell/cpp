#ifndef __COLOR__ 
#define __COLOR__ 

#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>

//struct Gizmo
//{
//  static const int count = 42;
//};

//struct COLOR{
//  static const int a = 76;
//  static const constexpr GLfloat arr[2] = {0.0, 1.0};
//};

typedef struct _COLOR{
    static const constexpr GLfloat WHITE[3]   = {1, 1, 1};
    static const constexpr GLfloat RED[3]     = {1, 0, 0};
    static const constexpr GLfloat GREEN[3]   = {0, 1, 0};
    static const constexpr GLfloat MAGENTA[3] = {1, 0, 1};
} COLOR;

#endif
