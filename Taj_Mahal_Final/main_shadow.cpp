#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GLUT/GLUT.h>
//#include "draw_compo.hpp"
#include "Keyboard_mouse_handle.hpp"
#include "Lighting.hpp"
#include "shadow.hpp"
#ifndef M_PI
#define M_PI 3.14159265
#endif
static int stencilReflection = 1;
static int renderShadow = 1, renderScene = 1, renderReflection = 1;
static int linearFiltering = 0, useMipmaps = 0;



GLfloat lightColor0[] = {0.8, 1.0, 0.8, 1.0}; //Color (0.5, 0.5, 0.5)

static GLfloat floorVertices[4][3] = {
    { -20.0, 0.0, 20.0 },
    { 20.0, 0.0, 20.0 },
    { 20.0, 0.0, -20.0 },
    { -20.0, 0.0, -20.0 },
};

static GLfloat floorVertices1[4][3] = {
    { -4.0, 0.01, 5.0 },
    { 4.0, 0.01, 5.0 },
    { 4.0, 0.01, -20.0 },
    { -4.0, 0.01, -20.0 },
};


static void drawFloor1(void)
{
    glDisable(GL_LIGHTING);
    
    glPushMatrix();
    glBegin(GL_QUADS);
    glVertex3fv(floorVertices1[0]);
    glVertex3fv(floorVertices1[1]);
    glVertex3fv(floorVertices1[2]);
    glVertex3fv(floorVertices1[3]);
    glEnd();
    glPopMatrix();
    
    
    glEnable(GL_LIGHTING);
}


static void drawFloor(void){
    glDisable(GL_LIGHTING);
    
    
    glBegin(GL_QUADS);
    glVertex3fv(floorVertices[0]);
    glVertex3fv(floorVertices[1]);
    glVertex3fv(floorVertices[2]);
    glVertex3fv(floorVertices[3]);
    glEnd();
    
    glEnable(GL_LIGHTING);
}

static GLfloat floorPlane[4];

static void redraw(void)
{
    int start, end;

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    lightPosition[0] = 12*cos(lightAngle);
    lightPosition[1] = lightHeight;
    lightPosition[2] = 12*sin(lightAngle);
    lightPosition[3] = 0.0;
    
    
    CshaMatrix(floorShadow, floorPlane, lightPosition);
//     CshaMatrix(floorShadow1, floorPlane1, lightPosition);
    
    glPushMatrix();
    if(angle2<-10)
        angle2=30;
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    
    if (renderReflection) {
//        if (stencilReflection) {
        
            glDisable(GL_DEPTH_TEST);
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
            
            glEnable(GL_STENCIL_TEST);
            glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 1, 0xffffffff);
            drawFloor1();
            
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
            glEnable(GL_DEPTH_TEST);
            
            glStencilFunc(GL_EQUAL, 1, 0xffffffff);
            glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
//        }
        
        glPushMatrix();
        glTranslatef(0, -0.01f, -5.0f);
        glScalef(6.0, -8.0, 6.0);
        
//        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
//        glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
//        glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
        Ediffuselight();
        Especularlight();
        glEnable(GL_NORMALIZE);
//        glCullFace(GL_FRONT);
        glDisable(GL_CULL_FACE);
        flags=1;
        draw();
        glEnable(GL_CULL_FACE);
        glDisable(GL_NORMALIZE);
//        glCullFace(GL_BACK);
        Ediffuselight();
        Especularlight();
        glPopMatrix();
        
//        glLightfv(GL_LIGHT0, GL_POSITION, lightPwosition);
//        glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
//        glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
//        if (stencilReflection) {
            glDisable(GL_STENCIL_TEST);
//        }
    }
    
    glFrontFace(GL_CW);
    glColor4f(0.1, 0.1, 0.7, 1.0);
    drawFloor();
    glFrontFace(GL_CCW);
    
    if (renderShadow) {
//        if (stencilShadow) {
            glEnable(GL_STENCIL_TEST);
            glStencilFunc(GL_ALWAYS, 3, 0xffffffff);
            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
//        }
    }
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glColor4f(0.7, 0.0, 0.0, 0.3);
    glColor4f(0.5, 1.0, 0.5, 0.3);
    drawFloor();
    glColor4f(0.196078, 0.6, 0.8,0.3);
    drawFloor1();
    glDisable(GL_BLEND);
    
    if (renderScene) {
        glPushMatrix();
        //        glColor3f(0.0f, 1.0f, 1.0f);
//        glTranslatef(0, 1.5f, 0);
        glColor3f(1.0, 1, 1);
        glScalef(10,10, 10);
        glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
        glEnable(GL_NORMALIZE);
        glDisable(GL_CULL_FACE);
//        glTranslatef(0, -1.0, 0.0);
          flags=1;
            draw();
        glEnable(GL_CULL_FACE);
        glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
        glDisable(GL_NORMALIZE);
        glPopMatrix();
    }
    

    shadow(1);
    
    
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 1.0, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_LIGHTING);
    glPopMatrix();
    
    glPopMatrix();
    
    glutSwapBuffers();
}



void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_CULL_FACE);
    glMatrixMode(GL_PROJECTION);
    gluPerspective( 45.0, 2.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
    int i;
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL | GLUT_MULTISAMPLE);
    glutInitWindowSize(400, 400 );
    glutCreateWindow("CGV-Reflection + Shadow");
    initRendering();

    glutDisplayFunc(redraw);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutIdleFunc(idle);
    glutKeyboardFunc(normalKeyboard);
//    glutSpecialFunc(specialkeyboard);
    
    polygonOffsetVersion = 2;
    glPolygonOffset(-2.0, -1.0);
    
    Lighting();
    gluLookAt(0.0, 8.0, 40.0,
              0, 8, 0.0,
              0.0, 1.0, 0);
    findPlane(floorPlane, floorVertices[1], floorVertices[2], floorVertices[3]);
    
    glutMainLoop();
    return 0;
}
