#ifndef reflection_hpp
#define reflection_hpp
#include "Lighting.hpp"


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
    
    glBegin(GL_QUADS);
    glVertex3fv(floorVertices1[0]);
    glVertex3fv(floorVertices1[1]);
    glVertex3fv(floorVertices1[2]);
    glVertex3fv(floorVertices1[3]);
    glEnd();
    
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


void Dreflection(int renderReflection)
{
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
//        Ediffuselight();
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
//        Ediffuselight();
        //        glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
        //        glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
        //        if (stencilReflection) {
        glDisable(GL_STENCIL_TEST);
        //        }
    }
}
#endif
