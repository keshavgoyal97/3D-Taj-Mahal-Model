#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <cmath>
#include <queue>
#include <utility>


#ifdef USEGLEW
#include <GL/glew.h>
#endif

#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGl/glu.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#endif

#define PI 3.1415926535898
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))
#define DEF_D 5



#endif
