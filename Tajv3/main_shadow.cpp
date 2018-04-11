#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GLUT/GLUT.h>
#include "draw_compo.hpp"
#include "Lighting.hpp"
#include "shadow.hpp"
#include "reflection.hpp"
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
//GLfloat lightColor0[] = {0.8, 1.0, 0.8, 1.0}; //Color (0.5, 0.5, 0.5)
//GLfloat lightPos0[] = {30.0f, 20.0f, 10.0f, 1.0f}; //Positioned at (300, 0, 100)



//GLfloat lightColor1[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
//GLfloat lightPos1[] = {-5.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (300, 0, 100)
//static GLfloat skinColor[] = {0.1, 1.0, 0.1, 1.0}, eyeColor[] = {1.0, 0.2, 0.2, 1.0};


//static void draw(void){
//    glPushMatrix();
//    glTranslatef(0.0, 10.0, 0.0);
//    glutSolidSphere(5.0, 20, 16);
//    glPopMatrix();
//}

//static GLfloat floorVertices[4][3] = {
//    { -20.0, 0.0, 20.0 },
//    { 20.0, 0.0, 20.0 },
//    { 20.0, 0.0, -20.0 },
//    { -20.0, 0.0, -20.0 },
//};
//
//static void drawFloor(void){
//    glDisable(GL_LIGHTING);
//    //    glPushMatrix();
//    //    glTranslatef(0, 10, 0);
////    if (useTexture) {
////        glEnable(GL_TEXTURE_2D);
////    }
//    
//    glBegin(GL_QUADS);
//    glVertex3fv(floorVertices[0]);
//    glVertex3fv(floorVertices[1]);
//    glVertex3fv(floorVertices[2]);
//    glVertex3fv(floorVertices[3]);
//    glEnd();
//    
////    if (useTexture) {
////        glDisable(GL_TEXTURE_2D);
////    }
//    //    glPopMatrix();
//    glEnable(GL_LIGHTING);
//}

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
    Ediffuselight();
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
        glTranslatef(0, 1.5f, 0);
        glColor3f(1.0, 1, 1);
        glScalef(10,10, 10);
        Especularlight();
        glEnable(GL_NORMALIZE);
        glDisable(GL_CULL_FACE);
            draw();
        glEnable(GL_CULL_FACE);
        glDisable(GL_NORMALIZE);
        Especularlight();
        glPopMatrix();
    }
    
    shadow(1);
    
    glPushMatrix();
//    glDisable(GL_LIGHTING);
//    glColor3f(1.0, 1.0, 0.0);
    
//    glDisable(GL_CULL_FACE);
//    glTranslatef(lightPosition[0], lightPosition[1], lightPosition[2]);
//    glRotatef(lightAngle * -180.0 / M_PI, 0, 1, 0);
//    glRotatef(atan(lightHeight/12) * 180.0 / M_PI, 0, 0, 1);
    glColor3f(1.0, 1.0, 1.0);
//    glEnable(GL_CULL_FACE);
    
//    glEnable(GL_LIGHTING);
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

int main(int argc, char **argv){
    int i;
    glutInit(&argc, argv);
    
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_STENCIL | GLUT_MULTISAMPLE);
    glutCreateWindow("CGV-Reflection + Shadow");
    glutDisplayFunc(redraw);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutIdleFunc(idle);
    glutKeyboardFunc(normalKeyboard);
    glutSpecialFunc(specialkeyboard);
    
    polygonOffsetVersion = ONE_DOT_ONE;
    glPolygonOffset(-2.0, -1.0);
    
        glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
//   glEnable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
    glMatrixMode(GL_PROJECTION);
    gluPerspective( 40.0, 2.0, 20.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0, 8.0, 60.0,
              0.0, 8.0, 0.0,
              0.0, 1.0, 0.);
    Lighting();
//    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
    
//    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.1);
//    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05);
    
//    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor0);
//    glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
//
//    
//    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightColor1);
//    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
//    
//    GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0 };
//    GLfloat mat_shininess[] = { 50.0 };
//    GLfloat light_position[] = { 30.0, 20.0, 10.0, 1.0 };
//    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
//    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    
    
    findPlane(floorPlane, floorVertices[1], floorVertices[2], floorVertices[3]);
    
    glutMainLoop();
    return 0;
}
