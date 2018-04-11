#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GLUT/GLUT.h>
#include "Lighting.hpp"
#include "shadow.hpp"
#include "reflection.hpp"
#include "Keyboard_mouse_handle.hpp"
//#include "Lighting.hpp"
#ifndef M_PI
#define M_PI 3.14159265
#endif
static int stencilReflection = 1;
static int renderScene = 1;
static int linearFiltering = 0, useMipmaps = 0, useTexture = 1;
static int reportSpeed = 0;
static int animation = 1;
static GLboolean lightSwitch = GL_TRUE;
static int forceExtension = 0;

static float jump = 0.0;
static float lightAngle = 0.0, lightHeight = 20;
GLfloat angle = -150;
GLfloat angle2 = 30;

int moving, startx, starty;
int lightMoving = 0, lightStartX, lightStartY;
static GLfloat floorPlane[4];

static void redraw(void)
{
    int start, end;
    
//    if ((stencilReflection && renderReflection) || (stencilShadow && renderShadow)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//    }
//    else {
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    }
    
    lightPosition[0] = 12*cos(lightAngle);
    lightPosition[1] = lightHeight;
    lightPosition[2] = 12*sin(lightAngle);
    lightPosition[3] = 0.0;
    
    
    shadowMatrix(floorShadow, floorPlane, lightPosition);
    
    glPushMatrix();
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    
//    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    Dreflection(1);
    
    
    glFrontFace(GL_CW);
    glColor4f(0.1, 0.1, 0.7, 1.0);
    drawFloor();
    glFrontFace(GL_CCW);
    
    update_stencilB(1);
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(0.7, 0.0, 0.0, 0.3);
    glColor4f(1.0, 1.0, 1.0, 0.3);
    drawFloor();
    glDisable(GL_BLEND);
    
    if (renderScene) {
        glPushMatrix();
        //        glColor3f(0.0f, 1.0f, 1.0f);
//        glTranslatef(0, 1.5f, 0);
        glColor3f(1.0, 1, 1);
        glScalef(10,10, 10);
        Ediffuselight();
        Especularlight();
        glEnable(GL_NORMALIZE);
        glDisable(GL_CULL_FACE);
            draw();
        glEnable(GL_CULL_FACE);
        glDisable(GL_NORMALIZE);
        Especularlight();
        Ediffuselight();
        glPopMatrix();
    }
    
    shadow(1);
    
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 1.0, 0.0);
    
    glDisable(GL_CULL_FACE);
//    glTranslatef(lightPosition[0], lightPosition[1], lightPosition[2]);
//    glRotatef(lightAngle * -180.0 / M_PI, 0, 1, 0);
//    glRotatef(atan(lightHeight/12) * 180.0 / M_PI, 0, 0, 1);
    glColor3f(1.0, 1.0, 1.0);
//    glEnable(GL_CULL_FACE);
//    
    glEnable(GL_LIGHTING);
    glPopMatrix();
    
    glPopMatrix();
    
    glutSwapBuffers();
}

static void mouse(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            moving = 1;
            startx = x;
            starty = y;
        }
        if (state == GLUT_UP) {
            moving =0.0;
        }
    }
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            lightMoving = 1;
            lightStartX = x;
            lightStartY = y;
        }
        if (state == GLUT_UP) {
            lightMoving = 0.0;
        }
    }
}

static void motion(int x, int y)
{
    if (moving) {
        angle = angle + (x - startx);
        angle2 = angle2 + (y - starty);
        startx = x;
        starty = y;
        glutPostRedisplay();
    }
    if (lightMoving) {
        lightAngle += (x - lightStartX)/40.0;
        lightHeight += (lightStartY - y)/20.0;
        lightStartX = x;
        lightStartY = y;
        glutPostRedisplay();
    }
}

static void idle(void)
{
    if (!lightMoving) {
        lightAngle += 0.05;
    }
    glutPostRedisplay();
}

static void normalKeyboard(unsigned char c, int x, int y){
    if (c == 27) {
        exit(0);
    }
    glutPostRedisplay();
}

//static int supportsOneDotOne(void){
//    const char *version;
//    int major, minor;
//    version = (char *) glGetString(GL_VERSION);
//    if (sscanf(version, "%d.%d", &major, &minor) == 2)
//        return major >= 1 && minor >= 1;
//    return 0;
//}
void initRendering() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_CULL_FACE);
    glMatrixMode(GL_PROJECTION);
    gluPerspective( 45.0, 1.33, 2.0, 100.0);
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
    //    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutIdleFunc(idle);
    //    glutKeyboardFunc(normalKeyboard);
    //    glutSpecialFunc(specialkeyboard);
    
    polygonOffsetVersion = 2;
    glPolygonOffset(-2.0, -1.0);
    
    //    glEnable(GL_DEPTH_TEST);
    //   glEnable(GL_TEXTURE_2D);
    //    glEnable(GL_COLOR_MATERIAL);
    //    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
    Lighting();
    gluLookAt(0.0, 8.0, 60.0,
              0, 8, 0.0,
              0.0, 1.0, 0);
    findPlane(floorPlane, floorVertices[1], floorVertices[2], floorVertices[3]);
    
    glutMainLoop();
    return 0;
    return 0;
}
