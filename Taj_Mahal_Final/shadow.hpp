#ifndef shadow_hpp
#define shadow_hpp
#include "main_draw.hpp"
#include "draw_compo.hpp"
static int offsetShadow = 1, polygonOffsetVersion;;
enum {
    MISSING, EXTENSION, ONE_DOT_ONE
};

static GLfloat floorShadow[4][4];
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


void update_stencilB(int renderShadow)
{
    if (renderShadow) {
//        if (stencilShadow) {
            glEnable(GL_STENCIL_TEST);
            glStencilFunc(GL_ALWAYS, 3, 0xffffffff);
            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
//        }
    }
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

void shadow(int renderShadow)
{
    
    
    if (renderShadow) {
        
//        if (stencilShadow) {
            glStencilFunc(GL_LESS, 2, 0xffffffff);
            glStencilOp(GL_REPLACE, GL_REPLACE, GL_REPLACE);
//        }
        
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
        glColor4f(0.0, 0.0, 0.0, 0.5);
        
        glPushMatrix();
        glMultMatrixf((GLfloat *) floorShadow);
        glScalef(10, 10, 10);
        glColor4f(0.0, 0, 0,0.5);
        glDisable(GL_CULL_FACE);
        flags=0;
        flags2=0;
        draw();
        glEnable(GL_CULL_FACE);
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
//        if (stencilShadow) {
            glDisable(GL_STENCIL_TEST);
//        }
    }
}
#endif
