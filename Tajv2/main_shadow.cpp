#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GLUT/GLUT.h>
//#include "draw_compo.hpp"
#include "main_draw.hpp"
#include "Keyboard_mouse_handle.hpp"
#include "Lighting.hpp"
#ifndef M_PI
#define M_PI 3.14159265
#endif
static int stencilReflection = 1, stencilShadow = 1, offsetShadow = 1;
static int renderShadow = 1, renderScene = 1, renderReflection = 1;
static int linearFiltering = 0, useMipmaps = 0, useTexture = 1;
static int reportSpeed = 0;
//static int animation = 1;
//static GLboolean lightSwitch = GL_TRUE;
//static int forceExtension = 0;
int x1=0;
int y2=8;
//void draw2(void){
//    glPushMatrix();
//    glTranslatef(0.0, 10.0, 0.0);
//    glutSolidSphere(2.0, 20, 16);
//    glPopMatrix();
//}

static float lightAngle = 0.0, lightHeight = 20;
GLfloat angle = -150;
GLfloat angle2 = 30;

int moving, startx, starty;
int lightMoving = 0, lightStartX, lightStartY;
GLfloat lightColor0[] = {0.8, 1.0, 0.8, 1.0}; //Color (0.5, 0.5, 0.5)
//GLfloat lightPos0[] = {30.0f, 20.0f, 10.0f, 1.0f}; //Positioned at (300, 0, 100)
int polygonOffsetVersion;

//GLfloat lightColor1[] = {0.5f, 0.5f, 0.5f, 1.0f}; //Color (0.5, 0.5, 0.5)
//GLfloat lightPos1[] = {-5.0f, 0.0f, 8.0f, 1.0f}; //Positioned at (300, 0, 100)
//static GLfloat skinColor[] = {0.1, 1.0, 0.1, 1.0}, eyeColor[] = {1.0, 0.2, 0.2, 1.0};

void CshaMatrix(GLfloat shaMat[4][4], GLfloat groundpl[4], GLfloat lightpos[4]){
    GLfloat dot;
    
    dot = groundpl[0] * lightpos[0] +
    groundpl[1] * lightpos[1] +
    groundpl[2] * lightpos[2] +
    groundpl[3] * lightpos[3];
    
    shaMat[0][0] = dot - lightpos[0] * groundpl[0];
    shaMat[1][0] = 0.f - lightpos[0] * groundpl[1];
    shaMat[2][0] = 0.f - lightpos[0] * groundpl[2];
    shaMat[3][0] = 0.f - lightpos[0] * groundpl[3];
    
    shaMat[0][1] = 0.f - lightpos[1] * groundpl[0];
    shaMat[1][1] = dot - lightpos[1] * groundpl[1];
    shaMat[2][1] = 0.f - lightpos[1] * groundpl[2];
    shaMat[3][1] = 0.f - lightpos[1] * groundpl[3];
    
    shaMat[0][2] = 0.f - lightpos[2] * groundpl[0];
    shaMat[1][2] = 0.f - lightpos[2] * groundpl[1];
    shaMat[2][2] = dot - lightpos[2] * groundpl[2];
    shaMat[3][2] = 0.0f - lightpos[2] * groundpl[3];
    
    shaMat[0][3] = 0.f - lightpos[3] * groundpl[0];
    shaMat[1][3] = 0.f - lightpos[3] * groundpl[1];
    shaMat[2][3] = 0.f - lightpos[3] * groundpl[2];
    shaMat[3][3] = dot - lightpos[3] * groundpl[3];
}

void findPlane(GLfloat pl[4], GLfloat v0[3], GLfloat v1[3], GLfloat v2[3])
{
    GLfloat prvec[3], vec1[3];
    
    prvec[0] = v1[0] - v0[0];
    prvec[1] = v1[1] - v0[1];
    prvec[2] = v1[2] - v0[2];
    
    vec1[0] = v2[0] - v0[0];
    vec1[1] = v2[1] - v0[1];
    vec1[2] = v2[2] - v0[2];
    
    pl[0] = prvec[1] * vec1[2] - prvec[2] * vec1[1];
    pl[1] = -(prvec[0] * vec1[2] - prvec[2] * vec1[0]);
    pl[2] = prvec[0] * vec1[1] - prvec[1] * vec1[0];
    
    pl[3] = -(pl[0] * v0[0] + pl[1] * v0[1] + pl[2] * v0[2]);
}

//static void draw(void){
//    glPushMatrix();
//    glTranslatef(0.0, 10.0, 0.0);
//    glutSolidSphere(5.0, 20, 16);
//    glPopMatrix();
//}

static GLfloat floorVertices[4][3] = {
    { -20.0, 0.0, 20.0 },
    { 20.0, 0.0, 20.0 },
    { 20.0, 0.0, -20.0 },
    { -20.0, 0.0, -20.0 },
};

static GLfloat floorVertices1[4][3] = {
    { -4.0, 0.0, 10.0 },
    { 4.0, 0.0, 10.0 },
    { 4.0, 0.0, -20.0 },
    { -4.0, 0.0, -20.0 },
};


static void drawFloor1(void)
{
    glDisable(GL_LIGHTING);
    //    glPushMatrix();
    //    glTranslatef(0, 10, 0);
    //    if (useTexture) {
    //        glEnable(GL_TEXTURE_2D);
    //    }
    glPushMatrix();
    glBegin(GL_QUADS);
//   glColor4f(0.1, 0.1, 0.2,0.3);
    glVertex3fv(floorVertices1[0]);
    glVertex3fv(floorVertices1[1]);
    glVertex3fv(floorVertices1[2]);
    glVertex3fv(floorVertices1[3]);
    glEnd();
    glPopMatrix();
    
    //    if (useTexture) {
    //        glDisable(GL_TEXTURE_2D);
    //    }
    //    glPopMatrix();
    glEnable(GL_LIGHTING);
}


static void drawFloor(void){
    glDisable(GL_LIGHTING);
    //    glPushMatrix();
    //    glTranslatef(0, 10, 0);
//    if (useTexture) {
//        glEnable(GL_TEXTURE_2D);
//    }
    
    glBegin(GL_QUADS);
    glVertex3fv(floorVertices[0]);
    glVertex3fv(floorVertices[1]);
    glVertex3fv(floorVertices[2]);
    glVertex3fv(floorVertices[3]);
    glEnd();
    
//    if (useTexture) {
//        glDisable(GL_TEXTURE_2D);
//    }
    //    glPopMatrix();
    glEnable(GL_LIGHTING);
}

static GLfloat floorPlane[4];
static GLfloat floorShadow[4][4];

static void redraw(void)
{
    int start, end;

//    if ((stencilReflection && renderReflection) || (stencilShadow && renderShadow)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
//    }
//    else {
//        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    }
//    
    lightPosition[0] = 12*cos(lightAngle);
    lightPosition[1] = lightHeight;
    lightPosition[2] = 12*sin(lightAngle);
    lightPosition[3] = 0.0;
    
    
    CshaMatrix(floorShadow, floorPlane, lightPosition);
    
    glPushMatrix();
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
        draw();
        glEnable(GL_CULL_FACE);
        glDisable(GL_NORMALIZE);
//        glCullFace(GL_BACK);
        Ediffuselight();
        Especularlight();
        glPopMatrix();
        
//        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
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
        glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
        glEnable(GL_NORMALIZE);
        glDisable(GL_CULL_FACE);
//        glTranslatef(0, -1.0, 0.0);
            draw();
        glEnable(GL_CULL_FACE);
        glLightfv(GL_LIGHT1, GL_POSITION, lightPosition);
        glDisable(GL_NORMALIZE);
        glPopMatrix();
    }
    
    if (renderShadow) {
        
//        if (stencilShadow) {
            glStencilFunc(GL_LESS, 2, 0xffffffff);
            glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
//        }
        
        if (offsetShadow) {
            switch (polygonOffsetVersion) {
                case 1:
#ifdef GL_EXT_polygon_offset
                    glEnable(GL_POLYGON_OFFSET_EXT);
                    break;
#endif
#ifdef GL_VERSION_1_1
                case 2:
                    glEnable(GL_POLYGON_OFFSET_FILL);
                    break;
#endif
                case 0:
                    break;
            }
        }
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_LIGHTING);
        glColor4f(0.0, 0.0, 0.0, 0.5);
        
        glPushMatrix();
        glMultMatrixf((GLfloat *) floorShadow);
        glScalef(10, 10, 10);
        glColor3f(0.0, 0, 0);
        glDisable(GL_CULL_FACE);
        draw();
        glEnable(GL_CULL_FACE);
        glPopMatrix();
        
        glDisable(GL_BLEND);
        glEnable(GL_LIGHTING);
        
        if (offsetShadow) {
            switch (polygonOffsetVersion) {
#ifdef GL_EXT_polygon_offset
                case 1:
                    glDisable(GL_POLYGON_OFFSET_EXT);
                    break;
#endif
#ifdef GL_VERSION_1_1
                case 2:
                    glDisable(GL_POLYGON_OFFSET_FILL);
                    break;
#endif
                case 0:
                    break;
            }
        }
        if (stencilShadow) {
            glDisable(GL_STENCIL_TEST);
        }
    }
    
    glPushMatrix();
    glDisable(GL_LIGHTING);
    glColor3f(1.0, 1.0, 0.0);
    
//    glDisable(GL_CULL_FACE);
//    glTranslatef(lightPosition[0], lightPosition[1], lightPosition[2]);
//    glRotatef(lightAngle * -180.0 / M_PI, 0, 1, 0);
//    glRotatef(atan(lightHeight/12) * 180.0 / M_PI, 0, 0, 1);
    glColor3f(1.0, 1.0, 1.0);
//    glEnable(GL_CULL_FACE);
    
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
        lightAngle += 0.02;
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

void specialkeyboard1(int key, int xx, int yy)
{
    switch(key){
        case(GLUT_KEY_LEFT):
            x1++;
            break;
            
        case(GLUT_KEY_RIGHT):
            x1--;
            break;
            
        case(GLUT_KEY_UP):
            y2++;
            break;
            
        case(GLUT_KEY_DOWN):
            y2--;
            break;
            
        default: break;
    }
    glutPostRedisplay();
}
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
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutIdleFunc(idle);
//    glutKeyboardFunc(normalKeyboard);
    glutSpecialFunc(specialkeyboard);
    
    polygonOffsetVersion = 2;
    glPolygonOffset(-2.0, -1.0);
    
//    glEnable(GL_DEPTH_TEST);
//   glEnable(GL_TEXTURE_2D);
//    glEnable(GL_COLOR_MATERIAL);
    //    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
    Lighting();
    gluLookAt(0.0, 8.0, 60.0,
              x1, y2, 0.0,
              0.0, 1.0, 0);
    findPlane(floorPlane, floorVertices[1], floorVertices[2], floorVertices[3]);
    
    glutMainLoop();
    return 0;
}
