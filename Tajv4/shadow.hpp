#ifndef shadow_hpp
#define shadow_hpp
#include "main_draw.hpp"
static int stencilShadow = 1, offsetShadow = 1, polygonOffsetVersion;;
enum {
    MISSING, EXTENSION, ONE_DOT_ONE
};
enum {
    X, Y, Z, W
};
enum {
    A, B, C, D
};

static GLfloat floorShadow[4][4];
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
    shadowMat[3][2] = 0.0f - lightpos[Z] * groundplane[W];
    
    shadowMat[X][3] = 0.f - lightpos[W] * groundplane[X];
    shadowMat[1][3] = 0.f - lightpos[W] * groundplane[Y];
    shadowMat[2][3] = 0.f - lightpos[W] * groundplane[Z];
    shadowMat[3][3] = dot - lightpos[W] * groundplane[W];
    
}

void update_stencilB(int renderShadow)
{
    if (renderShadow) {
        if (stencilShadow) {
            glEnable(GL_STENCIL_TEST);
            glStencilFunc(GL_ALWAYS, 3, 0xffffffff);
            glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
        }
    }
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


void shadow(int renderShadow)
{
    
    
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
}
#endif
