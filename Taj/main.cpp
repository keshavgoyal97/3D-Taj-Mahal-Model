#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

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


#include <cmath>
#include <queue>
#include <utility>
#include <iostream>
#include "draw_compo.hpp"
#include "main_draw.hpp"
#include "Lighting.hpp"
#define PI 3.1415926535898
#define Cos(th) cos(PI/180*(th))
#define Sin(th) sin(PI/180*(th))
#define DEF_D 5

//float z=0.0;
//float r =(100.0f/600.0f);
//float rx=(70.0f/600.0f);
//float sx=1.0f,sy=1.0f,sz=1.0f;
//float lx0 = 0.0, lz0 = -1.0;
//float xRot, yRot, zRot;
using namespace std;




void draw_window_z(int zz)
{
    
    
    
    
    
}











void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glColor4f(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(0,0,-8.0f);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
//    glEnable(GL_LIGHT3);
    Lighting();
    gluLookAt( x, 0.0, z,
              x + lx0, 0.0, z + lz0,
              0.0, 1.0, 0.0);
	   //  gluLookAt(0.0f, 0.0f,5.0f , 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    //  glRotatef(_angle,0.0f,1.0f,0.0f);
    //  drawBase();
    
    glPushMatrix();
    //  glTranslatef(0,0.2f,0);
    //    glColor3f(1.0,0.0,0.0);
    //   draw_cylinder();
    //   draw_gon();
    //    draw_cyl()
    //;
    glColor3f(0, 0, 0);
    draw();
    // draw_hemisphere();
    glPopMatrix();
    
    glBegin(GL_LINES);
    glColor3d(1, 0, 0);
    glVertex3f(0.0f, 0.0f,0.0f);
    glVertex3f(4.0f, 0.0f, 0.0f);
    glColor3d(0, 1.0 , 0.0);
    glVertex3f(0.0f, 0.0f,0.0f);
    glVertex3f(0.0f, 4.0f, 0.0f);
    glColor3d(0, 0, 1);
    glVertex3f(0.0f, 0.0f,0.0f);
    glVertex3f(0.0f, 0.0f, 4.0f);
    glEnd();
    
//    glFlush();
    glutSwapBuffers();
    
    
}


void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
//    glEnable(GL_CULL_FACE);
//    glClearColor(0.0f, 0.0, 0.0, 1.0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_SMOOTH);
}




int main(int argc, char** argv)
{
    
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(600,600);
    glutCreateWindow("Taj Mahal");
    initRendering();
    glutDisplayFunc(display);
    glutReshapeFunc(handleResize);
    
    glutSpecialFunc(specialkeyboard);
    glutCreateMenu(windowMenu);
    glutAddMenuEntry("Increase angle ",GLUT_KEY_LEFT);
    glutAddMenuEntry("Decrease angle ",GLUT_KEY_RIGHT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    
    glutMainLoop();
    return 0;
}

