#ifndef test_hpp
#define testdraw_hpp
#include "Keyboard_mouse_handle.hpp"

//float z=0.0;
float sx=1.0f,sy=1.0f,sz=1.0f;

float xRot, yRot, zRot;















void checkthat(int xx,int zz , int x01,int z01, int x02, int z02)
{
    glBegin(GL_LINES);
    
    for(float i=0;i<=0.12f;i+=0.0001f)
    {
        glVertex3f( xx* x01,i,zz*z01 );
        glVertex3f( xx* x02  ,i,zz*z02   );
        
        
    }
    glEnd();
    
    
    float xc=0,yc=0;
    float R=.025f;
    for(int i=0;i<=90;i++)
    {
        xc=R*Cos(i);
        yc=R*Sin(i);
        float centerx=(x01+x02)/2;
        //float center
        //  drawpoints(,centery,xc,yc,zz,xx,cons);
        glColor3f(0,0,0);
        glBegin(GL_LINES);
        glVertex3f(centerx+xc,0.12f+yc,5*r-(centerx+xc));
        glVertex3f(centerx-xc,0.12f+yc,5*r-(centerx-xc));
        glEnd();
    }
    
    
}









#endif /* draw_compo_hpp */
