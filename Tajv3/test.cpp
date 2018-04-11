#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <GLUT/GLUT.h>

#ifndef M_PI
#define M_PI 3.14159265
#endif
static int stencilReflection = 1, stencilShadow = 1, offsetShadow = 1;
static int renderShadow = 1, renderScene = 1, renderReflection = 1;
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

enum {
    MISSING, EXTENSION, ONE_DOT_ONE
};
int polygonOffsetVersion;

static GLfloat lightPosition[4];
static GLfloat lightColor[] = {0.8, 1.0, 0.8, 1.0};
static GLfloat skinColor[] = {0.1, 1.0, 0.1, 1.0}, eyeColor[] = {1.0, 0.2, 0.2, 1.0};

enum {
    X, Y, Z, W
};
enum {
    A, B, C, D
};

void shadowMatrix(GLfloat shadowMat[4][4], GLfloat groundplane[4], GLfloat lightpos[4]){
    GLfloat dot;
    
    dot = groundplane[X] * lightpos[X] +
    groundplane[Y] * lightpos[Y] +
    groundplane[Z] * lightpos[Z] +
    groundplane[W] * lightpos[W];
    
    shadowMat[0][0] = dot - lightpos[X] * groundplane[X];
    shadowMat[1][0] = 0.f - lightpos[X] * groundplane[Y];
    shadowMat[2][0] = 0.f - lightpos[X] * groundplane[Z];
    shadowMat[3][0] = 0.f - lightpos[X] * groundplane[W];
    
    shadowMat[X][1] = 0.f - lightpos[Y] * groundplane[X];
    shadowMat[1][1] = dot - lightpos[Y] * groundplane[Y];
    shadowMat[2][1] = 0.f - lightpos[Y] * groundplane[Z];
    shadowMat[3][1] = 0.f - lightpos[Y] * groundplane[W];
    
    shadowMat[X][2] = 0.f - lightpos[Z] * groundplane[X];
    shadowMat[1][2] = 0.f - lightpos[Z] * groundplane[Y];
    shadowMat[2][2] = dot - lightpos[Z] * groundplane[Z];
    shadowMat[3][2] = 0.f - lightpos[Z] * groundplane[W];
    
    shadowMat[X][3] = 0.f - lightpos[W] * groundplane[X];
    shadowMat[1][3] = 0.f - lightpos[W] * groundplane[Y];
    shadowMat[2][3] = 0.f - lightpos[W] * groundplane[Z];
    shadowMat[3][3] = dot - lightpos[W] * groundplane[W];
    
}

void findPlane(GLfloat plane[4], GLfloat v0[3], GLfloat v1[3], GLfloat v2[3])
{
    GLfloat vec0[3], vec1[3];
    
    vec0[X] = v1[X] - v0[X];
    vec0[Y] = v1[Y] - v0[Y];
    vec0[Z] = v1[Z] - v0[Z];
    
    vec1[X] = v2[X] - v0[X];
    vec1[Y] = v2[Y] - v0[Y];
    vec1[Z] = v2[Z] - v0[Z];
    
    plane[A] = vec0[Y] * vec1[Z] - vec0[Z] * vec1[Y];
    plane[B] = -(vec0[X] * vec1[Z] - vec0[Z] * vec1[X]);
    plane[C] = vec0[X] * vec1[Y] - vec0[Y] * vec1[X];
    
    plane[D] = -(plane[A] * v0[X] + plane[B] * v0[Y] + plane[C] * v0[Z]);
}

static void draw(void){
    glPushMatrix();
    glTranslatef(0.0, 10.0, 0.0);
    glutSolidCone(5.0, 20.0, 35, 35);
    glPopMatrix();
}

static GLfloat floorVertices[4][3] = {
    { -20.0, 0.0, 20.0 },
    { 20.0, 0.0, 20.0 },
    { 20.0, 0.0, -20.0 },
    { -20.0, 0.0, -20.0 },
};

static void drawFloor(void){
    glDisable(GL_LIGHTING);
    
    if (useTexture) {
        glEnable(GL_TEXTURE_2D);
    }
    
    glBegin(GL_QUADS);
    glVertex3fv(floorVertices[0]);
    glVertex3fv(floorVertices[1]);
    glVertex3fv(floorVertices[2]);
    glVertex3fv(floorVertices[3]);
    glEnd();
    
    if (useTexture) {
        glDisable(GL_TEXTURE_2D);
    }
    
    glEnable(GL_LIGHTING);
}

static GLfloat floorPlane[4];
static GLfloat floorShadow[4][4];

static void redraw(void)
{
    int start, end;
    
    if ((stencilReflection && renderReflection) || (stencilShadow && renderShadow)) {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    
    lightPosition[0] = 40*cos(lightAngle);
    lightPosition[1] = lightHeight;
    lightPosition[2] = 40*sin(lightAngle);
    lightPosition[3] = 0.0;
    
    
    shadowMatrix(floorShadow, floorPlane, lightPosition);
    
    glPushMatrix();
    glRotatef(angle2, 1.0, 0.0, 0.0);
    glRotatef(angle, 0.0, 1.0, 0.0);
    
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    
    if (renderReflection) {
        if (stencilReflection) {
            
            glDisable(GL_DEPTH_TEST);
            glColorMask(GL_FALSE, GL_FALSE, GL_FALSE, GL_FALSE);
            
            glEnable(GL_STENCIL_TEST);
            glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
            glStencilFunc(GL_ALWAYS, 1, 0xffffffff);
            
            drawFloor();
            
            glColorMask(GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE);
            glEnable(GL_DEPTH_TEST);
            
            glStencilFunc(GL_EQUAL, 1, 0xffffffff);
            glStencilOp(GL_KEEP, GL_KEEP, GL_KEEP);
        }
        
        glPushMatrix();
        glScalef(1.0, -1.0, 1.0);
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        glEnable(GL_NORMALIZE);
        glCullFace(GL_FRONT);
        draw();
        
        glDisable(GL_NORMALIZE);
        glCullFace(GL_BACK);
        glPopMatrix();
        
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
        
        if (stencilReflection) {
            glDisable(GL_STENCIL_TEST);
        }
    }
    
    glFrontFace(GL_CW);
//    glColor4f(0.0, 0.0, 0.0, 1.0);
    drawFloor();
    glFrontFace(GL_CCW);
    
    if (renderShadow) {
        if (stencilShadow) {
            glEnable(GL_STENCIL_TEST);
            glStencilFunc(GL_ALWAYS, 3, 0xffffffff);
            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
        }
    }
    
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//    glColor4f(0.7, 0.0, 0.0, 0.3);
    glColor4f(1.0, 1.0, 1.0, 0.3);
    drawFloor();
    glDisable(GL_BLEND);
    
    if (renderScene) {
        draw();
    }
    
    if (renderShadow) {
        
        if (stencilShadow) {
            glStencilFunc(GL_LESS, 2, 0xffffffff);
            glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
        }
        
        if (offsetShadow) {
            switch (polygonOffsetVersion) {
                case EXTENSION:
#ifdef GL_EXT_polygon_offset
                    glEnable(GL_POLYGON_OFFSET_EXT);
                    break;
#endif
#ifdef GL_VERSION_1_1
                case ONE_DOT_ONE:
                    glEnable(GL_POLYGON_OFFSET_FILL);
                    break;
#endif
                case MISSING:
                    break;
            }
        }
        
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glDisable(GL_LIGHTING);
        glColor4f(0.8, 0.0, 0.0, 0.5);
        
        glPushMatrix();
        glMultMatrixf((GLfloat *) floorShadow);
        draw();
        glPopMatrix();
        
        glDisable(GL_BLEND);
        glEnable(GL_LIGHTING);
        
        if (offsetShadow) {
            switch (polygonOffsetVersion) {
#ifdef GL_EXT_polygon_offset
                case EXTENSION:
                    glDisable(GL_POLYGON_OFFSET_EXT);
                    break;
#endif
#ifdef GL_VERSION_1_1
                case ONE_DOT_ONE:
                    glDisable(GL_POLYGON_OFFSET_FILL);
                    break;
#endif
                case MISSING:
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
    
    glDisable(GL_CULL_FACE);
    glTranslatef(lightPosition[0], lightPosition[1], lightPosition[2]);
   glRotatef(lightAngle * -180.0 / M_PI, 0, 1, 0);
    glRotatef(atan(lightHeight/12) * 180.0 / M_PI, 0, 0, 1);
    glColor3f(1.0, 1.0, 1.0);
    glEnable(GL_CULL_FACE);
    
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

static int supportsOneDotOne(void){
    const char *version;
    int major, minor;
    version = (char *) glGetString(GL_VERSION);
    if (sscanf(version, "%d.%d", &major, &minor) == 2)
        return major >= 1 && minor >= 1;
    return 0;
}

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
    
    
    polygonOffsetVersion = ONE_DOT_ONE;
    glPolygonOffset(-2.0, -1.0);
    
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    
    glMatrixMode(GL_PROJECTION);
    gluPerspective( 40.0, 1.0, 20.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(0.0, 8.0, 60.0,
              0.0, 8.0, 0.0,
              0.0, 1.0, 0.);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, 1);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.1);
    glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 0.05);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    
    findPlane(floorPlane, floorVertices[1], floorVertices[2], floorVertices[3]);
    
    glutMainLoop();
    return 0;
}
